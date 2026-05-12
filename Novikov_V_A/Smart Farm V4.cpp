#include <DHT.h>

bool isNight = false;

unsigned long lastVentTime = 0;
bool isVentingActive = false;

const int PIN_DHT = 2;
const int PIN_HEATER = 4;
const int PIN_PUMP = 5;
const int PIN_LAMP = 6;
const int PIN_FAN = 7;
const int PIN_LIGHT = A0;
const int PIN_SOIL = A1;


struct Profile {
    float tempHigh;
    float tempLow;

    float humHigh; 
    float humTempLimit;  // лимит температуры для нагрева при сырости

    int soilLow;
    int soilHigh;

    int lightThreshold;

    unsigned long ventInterval;
    unsigned long ventDuration;
};

const Profile profiles[] = {
    {
        // Профиль 0 (теплолюбивые)
        30.0, 20.0,       // tempHigh, tempLow
        80.0, 35.0,       // humHigh, humTempLimit
        300, 700,         // soilLow, soilHigh
        400,              // lightThreshold
        1800000, 120000   // ventInterval (30 мин), ventDuration (2 мин)
    },
    {
        // Профиль 1 (умеренные)
        28.0, 18.0,       // tempHigh, tempLow
        70.0, 30.0,       // humHigh, humTempLimit
        400, 600,         // soilLow, soilHigh
        300,              // lightThreshold
        3600000, 180000   // ventInterval (1 час), ventDuration (3 мин)
    }
};


class DHTReader {
private:
    DHT dht;
public:
    float temperature;
    float humidity;

    DHTReader(int pin) : dht(pin, DHT11) {
        dht.begin();
        temperature = 20.0;
        humidity = 50.0;
    }

    void update() {
        temperature = dht.readTemperature();
        humidity = dht.readHumidity();
        if (isnan(temperature)) temperature = 20.0;  // проверка исправности датчика
        if (isnan(humidity)) humidity = 50.0;
    }
};

class TemperatureSensor {
private:
    DHTReader& dhtRef;
public:
    float value;

    TemperatureSensor(DHTReader& ref) : dhtRef(ref), value(20.0) {}

    void read() {
        value = dhtRef.temperature;
    }
};

class HumiditySensor {
private:
    DHTReader& dhtRef;
public:
    float value;

    HumiditySensor(DHTReader& ref) : dhtRef(ref), value(50.0) {}

    void read() {
        value = dhtRef.humidity;
    }
};

class SoilSensor {
private:
    int pin;
public:
    int moisture;

    SoilSensor(int p) : pin(p) {
        moisture = 500;
    }

    void read() {
        moisture = analogRead(pin);
    }
};

class LightSensor {
private:
    int pin;
public:
    int lightLevel;

    LightSensor(int p) : pin(p) {
        lightLevel = 500;
    }

    void read() {
        lightLevel = analogRead(pin);
    }
};

class Fan {
private:
    int pin;
    bool currentState;
public:
    bool requestTemp;
    bool requestHum;
    bool requestVent;

    Fan(int p) : pin(p), currentState(false), requestTemp(false), requestHum(false), requestVent(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() {
        if (isNight) {
            digitalWrite(pin, LOW);
            currentState = false;
            return;
        }
        bool shouldRun = requestTemp || requestHum || requestVent;  // проверка запросов на вкл
        digitalWrite(pin, shouldRun ? HIGH : LOW);
        currentState = shouldRun;
    }

    bool isOn() const { 
        return currentState; 
    }
};

class Heater {
private:
    int pin;
    Fan& fanRef;  // право на опрос вента
public:
    bool requestTemp;
    bool requestHum;

    Heater(int p, Fan& fan) : pin(p), fanRef(fan), requestTemp(false), requestHum(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() {
        bool shouldHeat = (requestTemp || requestHum) && fanRef.isOn();
        digitalWrite(pin, shouldHeat ? HIGH : LOW);
    }
};

class Lamp {
private:
    int pin;
public:
    bool requestLight;

    Lamp(int p) : pin(p), requestLight(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() {
        digitalWrite(pin, requestLight ? HIGH : LOW);
    }
};

class Pump {
private:
    int pin;
public:
    bool requestWater;

    Pump(int p) : pin(p), requestWater(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() {
        digitalWrite(pin, requestWater ? HIGH : LOW);
    }
};


void control_temperature(const TemperatureSensor& tempSensor, Heater& heater, Fan& fan, const Profile& profile) {
    if (tempSensor.value > profile.tempHigh) {
        heater.requestTemp = false;
        fan.requestTemp = true;
    }
    else if (tempSensor.value < profile.tempLow) {
        heater.requestTemp = true;
        fan.requestTemp = true;
    }
    else {
        heater.requestTemp = false;
        fan.requestTemp = false;
    }
}

void control_humidity(const HumiditySensor& humSensor, const TemperatureSensor& tempSensor, Heater& heater, Fan& fan, const Profile& profile) {
    if (humSensor.value > profile.humHigh) {
        fan.requestHum = true;
        if (tempSensor.value < profile.humTempLimit) {
            heater.requestHum = true;
        }
        else {
            heater.requestHum = false;
        }
    }
    else {
        fan.requestHum = false;
        heater.requestHum = false;
    }
}

void control_soil(const SoilSensor& soilSensor, Pump& pump, const Profile& profile) {
    if (soilSensor.moisture > profile.soilHigh) {
        pump.requestWater = true;
    }
    else if (soilSensor.moisture < profile.soilLow) {
        pump.requestWater = false;
    }
}

void control_light(const LightSensor& lightSensor, Lamp& lamp, const Profile& profile) {
    if (!isNight && lightSensor.lightLevel > profile.lightThreshold) {
        lamp.requestLight = true;
    }
    else {
        lamp.requestLight = false;
    }
}

void control_ventilation(Fan& fan, const Profile& profile) {
    if (isNight) {
        isVentingActive = false;
        fan.requestVent = false;
        return;
    }

    unsigned long now = millis();

    if (!isVentingActive && (now - lastVentTime >= profile.ventInterval)) {
        isVentingActive = true;
        lastVentTime = now;
        fan.requestVent = true;
    }

    if (isVentingActive && (now - lastVentTime >= profile.ventDuration)) {
        isVentingActive = false;
        fan.requestVent = false;
    }
}

void checkNightTime() {
    unsigned long now = millis();
    unsigned long currentHour = (now / 3600000UL) % 24;
    isNight = (currentHour >= 22 || currentHour < 6);
}



DHTReader dhtSensor(PIN_DHT);
TemperatureSensor airTemp(dhtSensor);
HumiditySensor airHum(dhtSensor);
SoilSensor soilMoisture(PIN_SOIL);
LightSensor ambientLight(PIN_LIGHT);

Fan mainFan(PIN_FAN);
Heater mainHeater(PIN_HEATER, mainFan);
Lamp mainLamp(PIN_LAMP);
Pump mainPump(PIN_PUMP);


void setup() {  // первый запуск
    Serial.begin(9600);
    lastVentTime = millis();
}


void loop() {
    const Profile& currentProfile = profiles[0];

    checkNightTime();
    dhtSensor.update();

    airTemp.read();
    airHum.read();
    soilMoisture.read();
    ambientLight.read();

    control_temperature(airTemp, mainHeater, mainFan, currentProfile);
    control_humidity(airHum, airTemp, mainHeater, mainFan, currentProfile);
    control_soil(soilMoisture, mainPump, currentProfile);
    control_light(ambientLight, mainLamp, currentProfile);
    control_ventilation(mainFan, currentProfile);

    mainFan.power();
    mainHeater.power();
    mainLamp.power();
    mainPump.power();

    // отладка
    Serial.print("T:"); Serial.print(airTemp.value);
    Serial.print(" H:"); Serial.print(airHum.value);
    Serial.print(" L:"); Serial.print(ambientLight.lightLevel);
    Serial.print(" S:"); Serial.print(soilMoisture.moisture);
    Serial.print(" Night:"); Serial.println(isNight ? "1" : "0");

    delay(1000);
}