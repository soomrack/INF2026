#include <DHT.h>

const int PIN_DHT = 8;
const int PIN_HEATER = 4;
const int PIN_PUMP = 5;
const int PIN_LAMP = 6;
const int PIN_FAN = 7;
const int PIN_LIGHT = A1;
const int PIN_SOIL = A3;

bool isNightTime = false;
unsigned long ventilationStartTime = 0;
bool ventInProgress = false;
unsigned long pumpLastWorkTime = 0;
bool pumpDelayActive = false;

// Флаги для отслеживания состояния датчиков
bool dhtSensorOK = true;
bool soilSensorOK = true;
bool lightSensorOK = true;
unsigned long sensorErrorTime = 0;
const unsigned long SENSOR_RETRY_INTERVAL = 5000;

// Флаги для принудительной вентиляции
bool heaterVentForced = false;
unsigned long heaterVentStartTime = 0;
const unsigned long HEATER_VENT_DURATION = 20000;
bool heaterPrevState = false;

struct PlantProfile {
    float tempHigh;
    float tempLow;
    float humHigh;
    float humTempLimit;
    int soilLow;
    int soilHigh;
    int lightThreshold;
    unsigned long ventInterval;
    unsigned long ventDuration;
    unsigned long pumpDuration;
    unsigned long pumpRest;
};

const PlantProfile profiles[] = {
    {
        32.0, 19.0,
        75.0, 34.0,
        350, 650,
        400,
        1500000, 90000,
        5000,
        200000
    },
    {
        28.0, 18.0,
        70.0, 30.0,
        400, 600,
        350,
        1800000, 120000,
        3000,
        300000
    }
};

class DHTReader {
private:
    DHT dhtDevice;
    unsigned long lastReadTime;
    const unsigned long READ_INTERVAL = 1000;
    int errorCount;
    const int MAX_ERRORS = 3;
    
public:
    float temperature;
    float humidity;
    float defaultTemp;
    float defaultHum;

    DHTReader(int pinNumber) : dhtDevice(pinNumber, DHT11) {
        dhtDevice.begin();
        temperature = 0.0;
        humidity = 0.0;
        lastReadTime = 0;
        errorCount = 0;
        defaultTemp = 24.0;
        defaultHum = 60.0;
    }

    void update() {
        unsigned long now = millis();
        
        if (now - lastReadTime >= READ_INTERVAL) {
            float t = dhtDevice.readTemperature();
            float h = dhtDevice.readHumidity();
            
            if (!isnan(t) && !isnan(h)) {
                temperature = t;
                humidity = h;
                errorCount = 0;
                dhtSensorOK = true;
            } else {
                errorCount++;
                if (errorCount >= MAX_ERRORS) {
                    dhtSensorOK = false;
                    Serial.println(F("WARNING: DHT sensor not responding - using default values"));
                }
            }
            lastReadTime = now;
        }
    }
    
    bool isDataValid() {
        return (!isnan(temperature) && !isnan(humidity) && dhtSensorOK);
    }
    
    float getTemperature() {
        if (isDataValid()) {
            return temperature;
        } else {
            Serial.println(F("Using default temperature"));
            return defaultTemp;
        }
    }
    
    float getHumidity() {
        if (isDataValid()) {
            return humidity;
        } else {
            Serial.println(F("Using default humidity"));
            return defaultHum;
        }
    }
};

class SoilMoistureSensor {
private:
    int pin;
    int errorCount;
    const int MAX_ERRORS = 3;
public:
    int moisture;
    int defaultValue;

    SoilMoistureSensor(int pinNum) {
        pin = pinNum;
        moisture = 500;
        errorCount = 0;
        defaultValue = 500;
        pinMode(pin, INPUT);
    }

    void read() {
        int raw = analogRead(pin);
        
        if (raw > 0 && raw < 1024) {
            moisture = raw;
            errorCount = 0;
            soilSensorOK = true;
        } else {
            errorCount++;
            if (errorCount >= MAX_ERRORS) {
                soilSensorOK = false;
                Serial.println(F("WARNING: Soil sensor not responding - using default value"));
            }
        }
    }
    
    int getMoisture() {
        if (soilSensorOK) {
            return moisture;
        } else {
            Serial.println(F("Using default soil moisture"));
            return defaultValue;
        }
    }
};

class LightSensor {
private:
    int pin;
    int errorCount;
    const int MAX_ERRORS = 3;
public:
    int lightLevel;
    int defaultValue;

    LightSensor(int pinNum) {
        pin = pinNum;
        lightLevel = 500;
        errorCount = 0;
        defaultValue = 500;
        pinMode(pin, INPUT);
    }

    void read() {
        int raw = analogRead(pin);
        
        if (raw > 0 && raw < 1024) {
            lightLevel = raw;
            errorCount = 0;
            lightSensorOK = true;
        } else {
            errorCount++;
            if (errorCount >= MAX_ERRORS) {
                lightSensorOK = false;
                Serial.println(F("WARNING: Light sensor not responding - using default value"));
            }
        }
    }
    
    int getLightLevel() {
        if (lightSensorOK) {
            return lightLevel;
        } else {
            Serial.println(F("Using default light level"));
            return defaultValue;
        }
    }
};

class MultiVent {
private:
    int pin;
    bool activeState;
    int targetVentsCount;
    int maxVents;
    unsigned long cycleStartTime;
    unsigned long cycleDuration;

public:
    bool needVentByTemp;
    bool needVentByHum;
    bool needVentByTime;
    bool needVentByHeater;

    MultiVent(int pinNum) {
        pin = pinNum;
        activeState = false;
        targetVentsCount = 0;
        maxVents = 3;
        cycleDuration = 60000;
        cycleStartTime = 0;
        needVentByTemp = false;
        needVentByHum = false;
        needVentByTime = false;
        needVentByHeater = false;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void setVentsCount(int count) {
        if (count < 0) count = 0;
        if (count > maxVents) count = maxVents;
        targetVentsCount = count;
    }

    void power() {
        unsigned long now = millis();

        if (cycleStartTime == 0) {
            cycleStartTime = now;
        }

        if (now - cycleStartTime >= cycleDuration) {
            cycleStartTime = now;
        }

        unsigned long elapsed = now - cycleStartTime;
        unsigned long activeDuration = (cycleDuration * targetVentsCount) / maxVents;
        bool hasGlobalRequest = needVentByTemp || needVentByHum || needVentByTime || needVentByHeater;

        if (isNightTime || !hasGlobalRequest) {
            if (activeState) {
                digitalWrite(pin, LOW);
                activeState = false;
                Serial.println(F("Vent: OFF"));
            }
            return;
        }

        bool newState = (elapsed < activeDuration);

        if (newState != activeState) {
            if (newState) {
                digitalWrite(pin, HIGH);
                Serial.print(F("Vent: ON ("));
                Serial.print(targetVentsCount);
                Serial.print(F("/"));
                Serial.print(maxVents);
                Serial.println(F(")"));
            } else {
                digitalWrite(pin, LOW);
                Serial.println(F("Vent: OFF"));
            }
            activeState = newState;
        }
    }

    bool isOn() const {
        return activeState;
    }

    int getCurrentVentsCount() const {
        if (!activeState) return 0;
        return targetVentsCount;
    }

    void forceVentilation(bool enable) {
        needVentByHeater = enable;
        if (enable) {
            Serial.println(F("Vent: FORCED ON by heater"));
        } else {
            Serial.println(F("Vent: FORCED OFF by heater"));
        }
    }
};


class Heater {
private:
    int pin;
    bool activeState;
public:
    bool needHeatByTemp;
    bool needHeatByHum;

    Heater(int pinNum) {
        pin = pinNum;
        activeState = false;
        needHeatByTemp = false;
        needHeatByHum = false;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    //forceOff + power
    void power(bool forcedOffState = false) {
        bool prev = activeState;
        bool demandsFlag = needHeatByTemp || needHeatByHum;
        
        
        bool shouldHeat = demandsFlag && !forcedOffState;

        if (shouldHeat) {
            digitalWrite(pin, HIGH);
        } else {
            digitalWrite(pin, LOW);
        }

        activeState = shouldHeat;
        if (activeState != prev) {
            if (forcedOffState) {
                Serial.println(F("Heater: OFF (forced by priority)"));
            } else {
                Serial.print(F("Heater:"));
                Serial.println(activeState ? F("ON") : F("OFF"));
            }
        }
    }

    bool isOn() const {
        return activeState;
    }
};


class Lamp {
private:
    int pin;
    bool activeState;
public:
    bool needLight;

    Lamp(int pinNum) {
        pin = pinNum;
        activeState = false;
        needLight = false;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() {
        bool prev = activeState;
        bool shouldLight = needLight && !isNightTime;

        if (shouldLight) {
            digitalWrite(pin, HIGH);
        } else {
            digitalWrite(pin, LOW);
        }

        activeState = shouldLight;
        if (activeState != prev) {
            Serial.print(F("Lamp: "));
            Serial.println(activeState ? F("ON") : F("OFF"));
        }
    }

    bool isOn() const {
        return activeState;
    }
};

class Pump {
private:
    int pin;
    bool activeState;
    unsigned long startTime;
    unsigned long lastStopTime;
    bool isRunning;
    unsigned long maxDuration;
    unsigned long restDuration;
public:
    bool needPump;

    Pump(int pinNum) {
        pin = pinNum;
        activeState = false;
        startTime = 0;
        lastStopTime = 0;
        isRunning = false;
        maxDuration = 5000;
        restDuration = 60000;
        needPump = false;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void setDuration(unsigned long duration) {
        maxDuration = duration;
    }

    void setRestDuration(unsigned long rest) {
        restDuration = rest;
    }

    void power() {
        unsigned long now = millis();
        bool prevState = isRunning;

        if (isRunning && (now - startTime >= maxDuration)) {
            digitalWrite(pin, LOW);
            isRunning = false;
            lastStopTime = now;
            activeState = false;
            if (prevState != isRunning) {
                Serial.println(F("Pump: OFF (time limit)"));
            }
        }

        if (!needPump && isRunning) {
            digitalWrite(pin, LOW);
            isRunning = false;
            lastStopTime = now;
            activeState = false;
            if (prevState != isRunning) {
                Serial.println(F("Pump: OFF (no need)"));
            }
        }

        if (needPump && !isRunning && (now - lastStopTime >= restDuration)) {
            digitalWrite(pin, HIGH);
            isRunning = true;
            startTime = now;
            activeState = true;
            if (prevState != isRunning) {
                Serial.println(F("Pump: ON"));
            }
        }
    }

    bool isOn() const {
        return activeState;
    }
};

// Управление принудительной вентиляцией при изменении состояния нагревателя
void control_heater_ventilation(Heater& heater, MultiVent& vent) {
    unsigned long currentTime = millis();
    bool currentHeaterState = heater.isOn();
    
    if (currentHeaterState != heaterPrevState) {
        heaterVentForced = true;
        heaterVentStartTime = currentTime;
        vent.forceVentilation(true);
        
        if (currentHeaterState) {
            Serial.println(F("Heater turned ON -> forced ventilation started"));
        } else {
            Serial.println(F("Heater turned OFF -> forced ventilation started"));
        }
        
        heaterPrevState = currentHeaterState;
    }
    
    if (heaterVentForced) {
        if (currentTime - heaterVentStartTime >= HEATER_VENT_DURATION) {
            heaterVentForced = false;
            vent.forceVentilation(false);
            Serial.println(F("Forced ventilation finished"));
        }
    }
}

int calculateVentsByTemperature(float temperature, const PlantProfile& activeProfile) {
    if (isnan(temperature)) return 0;
    if (temperature > activeProfile.tempHigh + 3.0) return 3;
    else if (temperature > activeProfile.tempHigh) return 2;
    else if (temperature < activeProfile.tempLow) return 1;
    return 0;
}

int calculateVentsByHumidity(float humidity, const PlantProfile& activeProfile) {
    if (isnan(humidity)) return 0;
    if (humidity > activeProfile.humHigh + 10.0) return 3;
    else if (humidity > activeProfile.humHigh) return 2;
    return 0;
}

void control_temperature(float temp, Heater& heater, MultiVent& vent, const PlantProfile& activeProfile, int& requiredVents) {
    if (isnan(temp)) {
        Serial.println(F("ERROR: No temperature data"));
        return;
    }
    
    int ventsFromTemp = calculateVentsByTemperature(temp, activeProfile);
    if (ventsFromTemp > requiredVents) requiredVents = ventsFromTemp;

    if (temp > activeProfile.tempHigh) {
        heater.needHeatByTemp = false;
        vent.needVentByTemp = true;
        Serial.println(F("Temp: high -> vent ON"));
    } else if (temp < activeProfile.tempLow) {
        heater.needHeatByTemp = true;
        vent.needVentByTemp = true;
        Serial.println(F("Temp: low -> heater ON"));
    } else {
        heater.needHeatByTemp = false;
        vent.needVentByTemp = false;
    }
}

void control_humidity(float hum, float temp, Heater& heater, MultiVent& vent, const PlantProfile& activeProfile, int& requiredVents) {
    if (isnan(hum) || isnan(temp)) {
        Serial.println(F("ERROR: No humidity data"));
        return;
    }
    
    int ventsFromHum = calculateVentsByHumidity(hum, activeProfile);
    if (ventsFromHum > requiredVents) requiredVents = ventsFromHum;

    if (hum > activeProfile.humHigh) {
        vent.needVentByHum = true;
        if (temp < activeProfile.humTempLimit) {
            heater.needHeatByHum = true;
            Serial.println(F("Hum: high and cold -> vent + heater ON"));
        } else {
            heater.needHeatByHum = false;
            Serial.println(F("Hum: high -> vent ON"));
        }
    } else {
        vent.needVentByHum = false;
        heater.needHeatByHum = false;
    }
}

void control_soilmoisture(int moisture, Pump& pump, const PlantProfile& activeProfile) {
    unsigned long now = millis();

    if (pumpDelayActive) {
        if (now - pumpLastWorkTime >= activeProfile.pumpRest) {
            pumpDelayActive = false;
            Serial.println(F("Soil: pause ended"));
        }
    }

    if (moisture < activeProfile.soilLow) {  
        if (!pumpDelayActive) {
            if (!pump.needPump) {
                Serial.println(F("Soil: dry -> pump ON"));
                pumpLastWorkTime = now;
                pump.needPump = true;
            }
            if (now - pumpLastWorkTime >= activeProfile.pumpDuration) {
                Serial.println(F("Soil: time limit -> pump OFF"));
                pump.needPump = false;
                pumpDelayActive = true;
                pumpLastWorkTime = now;
            }
        }
    } else if (moisture > activeProfile.soilHigh) {  
        if (pump.needPump) {
            Serial.println(F("Soil: wet -> pump OFF"));
        }
        pump.needPump = false;
    }
}

void control_light(int lightLevel, Lamp& lamp, const PlantProfile& activeProfile) {
    if (!isNightTime && lightLevel > activeProfile.lightThreshold) {
        if (!lamp.needLight) Serial.println(F("Light: dark -> lamp ON"));
        lamp.needLight = true;
    } else {
        if (lamp.needLight) {
            Serial.println(isNightTime ? F("Light: night -> lamp OFF") : F("Light: bright -> lamp OFF"));
        }
        lamp.needLight = false;
    }
}

void control_ventilation(MultiVent& vent, const PlantProfile& activeProfile) {
    if (isNightTime) {
        if (ventInProgress) {
            Serial.println(F("Ventilation: night -> stop"));
            ventInProgress = false;
            vent.needVentByTime = false;
        }
        return;
    }

    unsigned long currentTime = millis();

    if (!ventInProgress && (currentTime - ventilationStartTime >= activeProfile.ventInterval)) {
        Serial.println(F("Ventilation: scheduled start"));
        ventInProgress = true;
        ventilationStartTime = currentTime;
        vent.needVentByTime = true;
    }

    if (ventInProgress && (currentTime - ventilationStartTime >= activeProfile.ventDuration)) {
        Serial.println(F("Ventilation: finished"));
        ventInProgress = false;
        vent.needVentByTime = false;
    }
}

void updateTimeStatus() {
    unsigned long systemTime = millis();
    if (systemTime < 3600000UL) {
        isNightTime = false;
        return;
    }
    unsigned long currentHours = (systemTime / 3600000UL) % 24;
    bool newNight = (currentHours >= 22 || currentHours < 6);
    
    if (newNight != isNightTime) {
        isNightTime = newNight;
        Serial.print(F("Time change: "));
        Serial.println(isNightTime ? F("NIGHT") : F("DAY"));
    }
}

DHTReader mainDht(PIN_DHT);
SoilMoistureSensor soilSensor(PIN_SOIL);
LightSensor lightSensor(PIN_LIGHT);
MultiVent vent(PIN_FAN);
Pump pump(PIN_PUMP);
Heater heater(PIN_HEATER);
Lamp lamp(PIN_LAMP);

void setup() {
    Serial.begin(9600);
    Serial.println(F("System started"));
    
    pump.setDuration(profiles[0].pumpDuration);
    pump.setRestDuration(profiles[0].pumpRest);
    
    Serial.println(F("Checking sensors..."));
    delay(2000);
    mainDht.update();
    soilSensor.read();
    lightSensor.read();
    
    if (!dhtSensorOK) {
        Serial.println(F("WARNING: DHT sensor failed initial test - using defaults"));
    }
    if (!soilSensorOK) {
        Serial.println(F("WARNING: Soil sensor failed initial test - using defaults"));
    }
    if (!lightSensorOK) {
        Serial.println(F("WARNING: Light sensor failed initial test - using defaults"));
    }
    
    heaterPrevState = heater.isOn();
}

void loop() {
    static unsigned long cycleCount = 0;
    cycleCount++;
    
    Serial.print(F("\n--- Cycle "));
    Serial.print(cycleCount);
    Serial.println(F(" ---"));

    const PlantProfile& currentProfile = profiles[0];

    updateTimeStatus();
    
    mainDht.update();

    float temperature = mainDht.getTemperature();
    float humidity = mainDht.getHumidity();
    
    soilSensor.read();
    lightSensor.read();
    
    int soilMoisture = soilSensor.getMoisture();
    int lightLevel = lightSensor.getLightLevel();

    Serial.print(F("DHT: "));
    Serial.print(dhtSensorOK ? F("OK") : F("FAULT (using defaults)"));
    Serial.print(F("  Soil: "));
    Serial.print(soilSensorOK ? F("OK") : F("FAULT (using defaults)"));
    Serial.print(F("  Light: "));
    Serial.println(lightSensorOK ? F("OK") : F("FAULT (using defaults)"));

    Serial.print(F("Temperature: "));
    Serial.print(temperature);
    Serial.print(F(" C  Humidity: "));
    Serial.print(humidity);
    Serial.print(F(" %  Soil: "));
    Serial.print(soilMoisture);
    Serial.print(F("  Light: "));
    Serial.println(lightLevel);
    
    Serial.print(F("Night: "));
    Serial.println(isNightTime ? F("yes") : F("no"));

    if (!dhtSensorOK && millis() - sensorErrorTime > SENSOR_RETRY_INTERVAL) {
        mainDht.update();
        if (mainDht.isDataValid()) {
            dhtSensorOK = true;
            sensorErrorTime = 0;
            Serial.println(F("DHT sensor recovered!"));
        } else {
            sensorErrorTime = millis();
        }
    }

    int requiredVentsCount = 0;

    control_temperature(temperature, heater, vent, currentProfile, requiredVentsCount);
    control_humidity(humidity, temperature, heater, vent, currentProfile, requiredVentsCount);
    control_soilmoisture(soilMoisture, pump, currentProfile);
    control_light(lightLevel, lamp, currentProfile);
    control_ventilation(vent, currentProfile);
    
    //новая логика вентилятора
    control_heater_ventilation(heater, vent);

    if (vent.needVentByTime && requiredVentsCount < 1) {
        requiredVentsCount = 1;
    }
    
    if (vent.needVentByHeater) {
        requiredVentsCount = 3;
    }

    vent.setVentsCount(requiredVentsCount);
    
    
    pump.power();
    heater.power(pump.isOn());
    vent.power();
    lamp.power();

    Serial.print(F("Status: vent="));
    if (vent.isOn()) {
        Serial.print(F("ON ("));
        Serial.print(vent.getCurrentVentsCount());
        Serial.print(F(")"));
        if (vent.needVentByHeater) {
            Serial.print(F(" [FORCED]"));
        }
    } else {
        Serial.print(F("OFF"));
    }

    Serial.print(F(" heater="));
    Serial.print(heater.isOn() ? F("ON") : F("OFF"));

    Serial.print(F(" lamp="));
    Serial.print(lamp.isOn() ? F("ON") : F("OFF"));

    Serial.print(F(" pump="));
    Serial.println(pump.isOn() ? F("ON") : F("OFF"));

    delay(2000);
}