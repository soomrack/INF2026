#include <DHT.h>

<<<<<<< HEAD
bool isNight = false;

const int PIN_DHT = 2;
const int PIN_HEATER = 4;
const int PIN_PUMP = 5;
const int PIN_LAMP = 6;
const int PIN_FAN = 7;
const int PIN_LIGHT = A0;
const int PIN_SOIL = A1;

unsigned long lastVentTime = 0;
bool isVentingActive = false;


struct Profile {
    float tempHigh;
    float tempLow;

    float humHigh; 
    float humTempLimit;  // лимит температуры для нагрева при сырости
=======
bool isNightTime = false;

unsigned long ventilationStartTime = 0;
bool ventInProgress = false;

unsigned long pumpLastWorkTime = 0;
bool pumpDelayActive = false;

const int PIN_DHT = 3;
const int PIN_HEATER = 4;
const int PIN_PUMP = 5;
const int PIN_LAMP = 6;
const int PIN_VENT = 7;
const int PIN_LIGHT = A3;
const int PIN_SOIL = A1;


struct PlantProfile {
    float tempHigh;
    float tempLow;

    float humHigh;
    float humTempLimit;
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c

    int soilLow;
    int soilHigh;

    int lightThreshold;

    unsigned long ventInterval;
    unsigned long ventDuration;
<<<<<<< HEAD
};

const Profile profiles[] = {
    {
        // Профиль 1 (теплолюбивые)
        30.0, 20.0,       // tempHigh, tempLow
        80.0, 35.0,       // humHigh, humTempLimit
        300, 700,         // soilLow, soilHigh
        400,              // lightThreshold
        1800000, 120000   // ventInterval (30 мин), ventDuration (2 мин)
    },
    {
        // Профиль 2 (умеренные)
        28.0, 18.0,       // tempHigh, tempLow
        70.0, 30.0,       // humHigh, humTempLimit
        400, 600,         // soilLow, soilHigh
        300,              // lightThreshold
        3600000, 180000   // ventInterval (1 час), ventDuration (3 мин)
=======

    unsigned long pumpDuration;
    unsigned long pumpRest;
};

const PlantProfile profiles[] = {
    {
        32.0, 19.0,       // tempHigh, tempLow
        75.0, 34.0,       // humHigh, humTempLimit
        350, 650,         // soilLow, soilHigh
        17,               // lightThreshold
        1500000, 90000,   // ventInterval, ventDuration
        1000,             // pumpDuration
        200000            // pumpRest
    },
    {
        26.0, 16.0,       // tempHigh, tempLow
        65.0, 28.0,       // humHigh, humTempLimit
        450, 750,         // soilLow, soilHigh
        350,              // lightThreshold
        2700000, 150000,  // ventInterval, ventDuration
        5000,             // pumpDuration
        600000            // pumpRest
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
    }
};


<<<<<<< HEAD
class DHTReader {
private:
    DHT dht;
=======

class DHTReader {
private:
    DHT dhtDevice;
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
public:
    float temperature;
    float humidity;

<<<<<<< HEAD
    DHTReader(int pin) : dht(pin, DHT11) {
        dht.begin();
=======
    DHTReader(int pinNumber) : dhtDevice(pinNumber, DHT11) {
        dhtDevice.begin();
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
        temperature = 20.0;
        humidity = 50.0;
    }

    void update() {
<<<<<<< HEAD
        temperature = dht.readTemperature();
        humidity = dht.readHumidity();
        if (isnan(temperature)) temperature = 20.0;  // проверка датчика
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
=======
        temperature = dhtDevice.readTemperature();
        humidity = dhtDevice.readHumidity();

        if (isnan(temperature)) {
            Serial.println(F("! Ошибка чтения температуры DHT, использую 20.0"));
            temperature = 20.0;
        }
        if (isnan(humidity)) {
            Serial.println(F("! Ошибка чтения влажности DHT, использую 50.0"));
            humidity = 50.0;
        }
    }
};


class TemperatureSensor {
private:
    DHTReader* ptrReader;
public:
    float value;

    TemperatureSensor(DHTReader* dhtPtr) {
        ptrReader = dhtPtr;
        value = 20.0;
    }

    void read() {
        value = ptrReader->temperature;
    }
};


class HumiditySensor {
private:
    DHTReader* ptrReader;
public:
    float value;

    HumiditySensor(DHTReader* dhtPtr) {
        ptrReader = dhtPtr;
        value = 50.0;
    }

    void read() {
        value = ptrReader->humidity;
    }
};


class SoilMoistureSensor {
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
private:
    int pin;
public:
    int moisture;

<<<<<<< HEAD
    SoilSensor(int p) : pin(p) {
=======
    SoilMoistureSensor(int pinNum) {
        pin = pinNum;
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
        moisture = 500;
    }

    void read() {
        moisture = analogRead(pin);
    }
};

<<<<<<< HEAD
=======

>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
class LightSensor {
private:
    int pin;
public:
    int lightLevel;

<<<<<<< HEAD
    LightSensor(int p) : pin(p) {
=======
    LightSensor(int pinNum) {
        pin = pinNum;
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
        lightLevel = 500;
    }

    void read() {
        lightLevel = analogRead(pin);
    }
};

<<<<<<< HEAD
class Fan {
private:
    int pin;
    bool currentState;
public:
    bool requestTemp;
    bool requestHum;
    bool requestVent;

    Fan(int p) : pin(p), currentState(false), requestTemp(false), requestHum(false), requestVent(false) {
=======

class MultiVent {
private:
    int pin;
    bool activeState;
    int targetVentsCount;  // нужное кол во
    int maxVents;  // для расчета времени
    unsigned long cycleStartTime;
    unsigned long cycleDuration;

public:
    bool needVentByTemp;
    bool needVentByHum;
    bool needVentByTime;

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

>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

<<<<<<< HEAD
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
=======
    void setVentsCount(int count) {
        if (count < 0) count = 0;
        if (count > maxVents) count = maxVents;
        targetVentsCount = count;
    }

    void power() {
        unsigned long now = millis();

        if (cycleStartTime == 0) {  // обновление цикла работы
            cycleStartTime = now;
        }

        if (now - cycleStartTime >= cycleDuration) {
            cycleStartTime = now;
        }

        unsigned long elapsed = now - cycleStartTime;  // время с начала цикла
        unsigned long activeDuration = (cycleDuration * targetVentsCount) / maxVents;
        bool hasGlobalRequest = needVentByTemp || needVentByHum || needVentByTime;

        if (isNightTime || !hasGlobalRequest) {
            if (activeState == true) {
                digitalWrite(pin, LOW);
                activeState = false;
                Serial.print(F("Вентиляция: выключена"));
            }
            return;
        }

        bool newState = (elapsed < activeDuration);

        if (newState != activeState) {
            if (newState == true) {
                digitalWrite(pin, HIGH);
                Serial.print(F("Вентиляция: включена ("));
                Serial.print(targetVentsCount);
                Serial.print(F(" из "));
                Serial.print(maxVents);
                Serial.println(F(" вентиляторов)"));
            }
            else {
                digitalWrite(pin, LOW);
                Serial.print(F("Вентиляция: выключена"));
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
};


class Heater {
private:
    int pin;
    MultiVent* linkedVent;
    bool activeState;
public:
    bool needHeatByTemp;
    bool needHeatByHum;

    Heater(int pinNum, MultiVent* ventPtr) {
        pin = pinNum;
        linkedVent = ventPtr;
        activeState = false;
        needHeatByTemp = false;
        needHeatByHum = false;
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() {
<<<<<<< HEAD
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
=======
        bool prev = activeState;  // пред значение
        bool demandsFlag = needHeatByTemp || needHeatByHum;
        bool shouldHeat = demandsFlag && linkedVent->isOn();

        if (shouldHeat == true) {
            digitalWrite(pin, HIGH);
        }
        else {
            digitalWrite(pin, LOW);
        }

        activeState = shouldHeat;
        if (activeState != prev) {
            Serial.print(F("Обогреватель: "));
            if (activeState == true) {
                Serial.println(F("ВКЛ"));
            }
            else {
                Serial.println(F("ВЫКЛ"));
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
    bool activeState = false;
public:
    bool needLight = false;

    Lamp(int pinNum) {
        pin = pinNum;
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() {
<<<<<<< HEAD
        digitalWrite(pin, requestLight ? HIGH : LOW);
    }
};

class Pump {
private:
    int pin;
public:
    bool requestWater;

    Pump(int p) : pin(p), requestWater(false) {
=======
        bool prev = activeState;
        bool shouldLight = needLight;

        if (shouldLight == true) {
            digitalWrite(pin, HIGH);
        }
        else {
            digitalWrite(pin, LOW);
        }

        activeState = shouldLight;
        if (activeState != prev) {
            Serial.print(F("Лампа: "));
            if (activeState == true) {
                Serial.println(F("ВКЛ"));
            }
            else {
                Serial.println(F("ВЫКЛ"));
            }
        }
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

    Pump(int pinNum) : pin(pinNum), activeState(false), startTime(0), lastStopTime(0), isRunning(false), maxDuration(5000), restDuration(60000), needPump(false) {
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

<<<<<<< HEAD
    void power() {
        digitalWrite(pin, requestWater ? HIGH : LOW);
=======
    void setDuration(unsigned long duration) {
        maxDuration = duration;
    }

    void setRestDuration(unsigned long rest) {
        restDuration = rest;
    }

    void power() {
        unsigned long now = millis();

        if (isRunning && (now - startTime >= maxDuration)) {
            digitalWrite(pin, LOW);
            isRunning = false;
            lastStopTime = now;
            activeState = false;
        }

        if (!needPump && isRunning) {
            digitalWrite(pin, LOW);
            isRunning = false;
            lastStopTime = now;
            activeState = false;
        }

        if (needPump && !isRunning && (now - lastStopTime >= restDuration)) {
            digitalWrite(pin, HIGH);
            isRunning = true;
            startTime = now;
            activeState = true;
        }
    }

    bool isOn() const {
        return activeState;
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
    }
};


<<<<<<< HEAD
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
=======

int calculateVentsByTemperature(float temperature, const PlantProfile& activeProfile) {
    if (temperature > activeProfile.tempHigh + 3.0) {
        return 3;
    }
    else if (temperature > activeProfile.tempHigh) {
        return 2;
    }
    else if (temperature < activeProfile.tempLow) {
        return 1;
    }
    return 0;
}

int calculateVentsByHumidity(float humidity, const PlantProfile& activeProfile) {
    if (humidity > activeProfile.humHigh + 10.0) {
        return 3;
    }
    else if (humidity > activeProfile.humHigh) {
        return 2;
    }
    return 0;
}


void control_temperature(const TemperatureSensor& tempSens, Heater& heater, MultiVent& vent, const PlantProfile& activeProfile, int& requiredVents) {
    int ventsFromTemp = calculateVentsByTemperature(tempSens.value, activeProfile);

    if (ventsFromTemp > requiredVents) {
        requiredVents = ventsFromTemp;
    }

    if (tempSens.value > activeProfile.tempHigh) {
        heater.needHeatByTemp = false;
        vent.needVentByTemp = true;
        Serial.println(F("Регулятор температуры: жарко -> вентиляция ВКЛ, обогрев ВЫКЛ"));
    }
    else if (tempSens.value < activeProfile.tempLow) {
        heater.needHeatByTemp = true;
        vent.needVentByTemp = true;
        Serial.println(F("Регулятор температуры: холодно -> обогрев и вентиляция ВКЛ"));
    }
    else {
        if (heater.needHeatByTemp || vent.needVentByTemp) {
            Serial.println(F("Регулятор температуры: норма -> все выкл"));
        }
        heater.needHeatByTemp = false;
        vent.needVentByTemp = false;
    }
}


void control_humidity(const HumiditySensor& humSens, const TemperatureSensor& tempSens, Heater& heater, MultiVent& vent, const PlantProfile& activeProfile, int& requiredVents) {
    int ventsFromHum = calculateVentsByHumidity(humSens.value, activeProfile);

    if (ventsFromHum > requiredVents) {
        requiredVents = ventsFromHum;
    }

    if (humSens.value > activeProfile.humHigh) {
        vent.needVentByHum = true;
        Serial.print(F("Регулятор влажности: высокая влажность -> вентиляция ВКЛ"));
        if (tempSens.value < activeProfile.humTempLimit) {
            Serial.println(F(", обогрев ВКЛ (помощь в осушении)"));
            heater.needHeatByHum = true;
        }
        else {
            Serial.println(F(", обогрев не нужен"));
            heater.needHeatByHum = false;
        }
    }
    else {
        if (vent.needVentByHum || heater.needHeatByHum) {
            Serial.println(F("Регулятор влажности: влажность в норме -> все выкл"));
        }
        vent.needVentByHum = false;
        heater.needHeatByHum = false;
    }
}


void control_soilmoisture(const SoilMoistureSensor& soil, Pump& pump, const PlantProfile& activeProfile) {
    unsigned long now = millis();

    if (pumpDelayActive == true) {
        if (now - pumpLastWorkTime >= activeProfile.pumpRest) {
            pumpDelayActive = false;
            Serial.println(F("Регулятор почвы: пауза окончена, контроль полива возобновлен"));
        }
    }

    if (soil.moisture > activeProfile.soilHigh) {
        if (pumpDelayActive == false) {
            if (pump.needPump == false) {
                Serial.println(F("Регулятор почвы: сухо! -> старт полива"));
                pumpLastWorkTime = now;
                pump.needPump = true;
            }

            if (now - pumpLastWorkTime >= activeProfile.pumpDuration) {
                Serial.println(F("Регулятор почвы: лимит времени! -> принудительное выключение помпы"));
                pump.needPump = false;
                pumpDelayActive = true;
                pumpLastWorkTime = now;
            }
        }
    }
    else if (soil.moisture < activeProfile.soilLow) {
        if (pump.needPump == true) {
            Serial.println(F("Регулятор почвы: влажно -> помпа ВЫКЛ"));
        }
        pump.needPump = false;
    }
}


void control_light(const LightSensor& light, Lamp& lamp, const PlantProfile& activeProfile) {
    if (!isNightTime && light.lightLevel > activeProfile.lightThreshold) {
        if (!lamp.needLight) Serial.println(F("Регулятор света: темно -> лампа ВКЛ"));
        lamp.needLight = true;
    }
    else {
        if (lamp.needLight) {
            if (isNightTime) Serial.println(F("Регулятор света: ночь -> лампа ВЫКЛ"));
            else Serial.println(F("Регулятор света: достаточно светло -> лампа ВЫКЛ"));
        }
        lamp.needLight = false;
    }
}


void control_ventilation(MultiVent& vent, const PlantProfile& activeProfile) {
    if (isNightTime) {
        if (ventInProgress) {
            Serial.println(F("Проветривание: наступила ночь -> остановка"));
            ventInProgress = false;
            vent.needVentByTime = false;
        }
        return;
    }

    unsigned long currentTime = millis();

    if (!ventInProgress && (currentTime - ventilationStartTime >= activeProfile.ventInterval)) {
        Serial.println(F("Проветривание: запуск по расписанию"));
        ventInProgress = true;
        ventilationStartTime = currentTime;
        vent.needVentByTime = true;
    }

    if (ventInProgress && (currentTime - ventilationStartTime >= activeProfile.ventDuration)) {
        Serial.println(F("Проветривание: завершение по длительности"));
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
        Serial.print(F("=== Смена времени суток: "));
        if (isNightTime == true) {
            Serial.println(F("НОЧЬ"));
        }
        else {
            Serial.println(F("ДЕНЬ"));
        }
    }
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
}



<<<<<<< HEAD
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
    const Profile& currentProfile = profiles[1];

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
=======
DHTReader mainDht(PIN_DHT);
TemperatureSensor temperature(&mainDht);
HumiditySensor airHumidity(&mainDht);
SoilMoistureSensor soilSensor(PIN_SOIL);
LightSensor lightSensor(PIN_LIGHT);
MultiVent vent(PIN_VENT);
Heater heater(PIN_HEATER, &vent);
Lamp lamp(PIN_LAMP);
Pump pump(PIN_PUMP);


void setup() {
    Serial.begin(9600);
}

void loop() {
    static unsigned long cycleCount = 0;
    cycleCount++;
    Serial.print(F("\n--- Цикл "));
    Serial.print(cycleCount);
    Serial.println(F(" ---"));

    const PlantProfile& currentProfile = profiles[0];

    updateTimeStatus();
    mainDht.update();

    temperature.read();
    airHumidity.read();
    soilSensor.read();
    lightSensor.read();

    Serial.println(F("Датчики:"));
    Serial.print(F("  Температура: ")); Serial.print(temperature.value); Serial.println(F(" C"));
    Serial.print(F("  Влажность воздуха: ")); Serial.print(airHumidity.value); Serial.println(F(" %"));
    Serial.print(F("  Влажность почвы (0-1023): ")); Serial.println(soilSensor.moisture);
    Serial.print(F("  Освещённость (0-1023): ")); Serial.println(lightSensor.lightLevel);
    Serial.print(F("  Ночь: "));
    if (isNightTime == true) {
        Serial.println(F("да"));
    }
    else {
        Serial.println(F("нет"));
    }

    int requiredVentsCount = 0;

    control_temperature(temperature, heater, vent, currentProfile, requiredVentsCount);
    control_humidity(airHumidity, temperature, heater, vent, currentProfile, requiredVentsCount);
    control_soilmoisture(soilSensor, pump, currentProfile);
    control_light(lightSensor, lamp, currentProfile);
    control_ventilation(vent, currentProfile);

    if (vent.needVentByTime && requiredVentsCount < 1) {  // плановый продув
        requiredVentsCount = 1;
    }

    vent.setVentsCount(requiredVentsCount);

    Serial.print(F("Решение: включаем "));
    Serial.print(requiredVentsCount);
    Serial.println(F(" вентилятор(ов) из 3"));

    vent.power();
    heater.power();
    lamp.power();
    pump.power();

    Serial.print(F("Состояние актуаторов: вент="));
    if (vent.isOn() == true) {
        Serial.print(F("ВКЛ ("));
        Serial.print(vent.getCurrentVentsCount());
        Serial.print(F(" шт)"));
    }
    else {
        Serial.print(F("выкл"));
    }

    Serial.print(F(", нагрев="));
    if (heater.isOn() == true) { Serial.print(F("ВКЛ")); }
    else { Serial.print(F("выкл")); }

    Serial.print(F(", лампа="));
    if (lamp.needLight == true) { Serial.print(F("ВКЛ")); }
    else { Serial.print(F("выкл")); }

    Serial.print(F(", помпа="));
    if (pump.needPump == true) { Serial.println(F("ВКЛ")); }
    else { Serial.println(F("выкл")); }

    delay(2000);
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
}