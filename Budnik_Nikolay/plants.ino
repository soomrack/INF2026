
#include <Arduino.h>
#include <DHT.h>

const byte DHT_PIN = 2;
const byte SOIL_PIN = A1;
const byte LIGHT_PIN = A0;

const byte PUMP_PIN = 5;
const byte FAN_PIN = 7;
const byte HEATER_PIN = 4;
const byte LAMP_PIN = 6;

#define DHT_MODEL DHT11

const unsigned long DHT_READ_INTERVAL = 2000UL;
const unsigned long PRINT_INTERVAL = 5000UL;

const unsigned long PUMP_WORK_TIME = 3000UL;
const unsigned long PUMP_PAUSE_TIME = 10000UL;

const unsigned long MINUTE_MS = 60000UL;
const unsigned long HOUR_MS = 3600000UL;
const unsigned long DAY_MS = 86400000UL;

const byte INITIAL_HOUR = 12;

// Границы калибровки нужно определить под конкретную теплицу и конкретный датчик
const int SOIL_DRY_RAW = 0;
const int SOIL_WET_RAW = 1023;

const int LIGHT_DARK_RAW = 1023;
const int LIGHT_BRIGHT_RAW = 0;

using Celsius = float;
using Percent = int;
using Minutes = unsigned int;

struct ClimateSettings {
    const char* name;

    Celsius minTemp, maxTemp;
    Percent maxAirHumidity;

    Percent minSoilHumidity;
    Percent minLight;

    byte nightStart, nightEnd;

    Minutes ventilationPeriod, ventilationDuration;
};

const ClimateSettings tomato = {
    "Tomato",

    22.0, 28.0,   // температура воздуха
    70.0,         // максимальная влажность воздуха

    35,           // минимальная влажность почвы
    50,           // минимальный уровень света

    22, 6,        // ночь: 22:00-06:00
    180, 5        // проветривание: каждые 180 минут на 5 минут
};

const ClimateSettings cucumber = {
    "Cucumber",

    23.0, 30.0,   // температура воздуха
    80.0,         // максимальная влажность воздуха

    45,           // минимальная влажность почвы
    45,           // минимальный уровень света

    22, 6,        // ночь: 22:00-06:00
    180, 5        // проветривание: каждые 180 минут на 5 минут
};

const ClimateSettings* climate = &tomato;

int clampPercent(long value) {
    if (value < 0) {
        return 0;
    }

    if (value > 100) {
        return 100;
    }

    return (int)value;
}

int rawToPercent(int raw, int rawAtZero, int rawAtHundred) {
    if (rawAtZero == rawAtHundred) {
        return 0;
    }

    // rawZero и rawFull могут идти в обратном порядке
    long percent = (long)(raw - rawAtZero) * 100L;
    percent = percent / (rawAtHundred - rawAtZero);

    return clampPercent(percent);
}

// Время виртуальное, поэтому считается от millis(), после перезагрузки снова стартует с INITIAL_HOUR
byte getHour() {
    byte passedHours = (millis() % DAY_MS) / HOUR_MS;
    return (INITIAL_HOUR + passedHours) % 24;
}

unsigned int getMinuteOfDay() {
    unsigned long passedMinutes = (millis() % DAY_MS) / MINUTE_MS;
    return (INITIAL_HOUR * 60 + passedMinutes) % 1440;
}

bool isNight() {
    byte hour = getHour();

    // Для интервала ночи через полночь, например 22.00-06.00, нужна отдельная проверка
    if (climate->nightStart < climate->nightEnd) {
        return hour >= climate->nightStart && hour < climate->nightEnd;
    }

    return hour >= climate->nightStart || hour < climate->nightEnd;
}

class Sensor {
public:
    virtual void begin() = 0;
    virtual void update() = 0;
};

class Controller {
public:
    virtual void update() = 0;
};

class AirSensor : public Sensor {
private:
    DHT dht;

    float temperatureValue;
    float humidityValue;

    bool temperatureIsReady;
    bool humidityIsReady;

    bool wasRead;
    unsigned long lastReadTime;

public:
    AirSensor(byte pin)
        : dht(pin, DHT_MODEL),
          temperatureValue(0),
          humidityValue(0),
          temperatureIsReady(false),
          humidityIsReady(false),
          wasRead(false),
          lastReadTime(0) {}

    void begin() override {
        dht.begin();
    }

    void update() override {
        unsigned long now = millis();

        if (wasRead && now - lastReadTime < DHT_READ_INTERVAL) {
            return;
        }

        wasRead = true;
        lastReadTime = now;

        float newHumidity = dht.readHumidity();
        float newTemperature = dht.readTemperature();

        // При ошибке DHT возвращает NaN, это защита
        if (!isnan(newHumidity)) {
            humidityValue = newHumidity;
            humidityIsReady = true;
        }

        if (!isnan(newTemperature)) {
            temperatureValue = newTemperature;
            temperatureIsReady = true;
        }
    }

    bool hasTemperature() const {
        return temperatureIsReady;
    }

    bool hasHumidity() const {
        return humidityIsReady;
    }

    float temperature() const {
        return temperatureValue;
    }

    float humidity() const {
        return humidityValue;
    }
};

class AnalogSensor : public Sensor {
private:
    byte pin;
    int rawValue;
    int percentValue;

    int rawAtZero;
    int rawAtHundred;

public:
    AnalogSensor(byte sensorPin, int zeroValue, int hundredValue)
        : pin(sensorPin),
          rawValue(0),
          percentValue(0),
          rawAtZero(zeroValue),
          rawAtHundred(hundredValue) {}

    void begin() override {
        pinMode(pin, INPUT);
    }

    void update() override {
        rawValue = analogRead(pin);
        percentValue = rawToPercent(rawValue, rawAtZero, rawAtHundred);
    }

    int percent() const {
        return percentValue;
    }

    int raw() const {
        return rawValue;
    }
};

class Device {
private:
    byte pin;
    bool activeHigh;
    bool needToTurnOn;

public:
    Device(byte devicePin, bool isActiveHigh = true)
        : pin(devicePin),
          activeHigh(isActiveHigh),
          needToTurnOn(false) {}

    void begin() {
        pinMode(pin, OUTPUT);
        off();
        apply();
    }

    void reset() {
        needToTurnOn = false;
    }

    void on() {
        needToTurnOn = true;
    }

    void off() {
        needToTurnOn = false;
    }

    bool isOn() const {
        return needToTurnOn;
    }

    void apply() {
        if (activeHigh) {
            digitalWrite(pin, needToTurnOn ? HIGH : LOW);
        } else {
            digitalWrite(pin, needToTurnOn ? LOW : HIGH);
        }
    }
};

class LightController : public Controller {
private:
    AnalogSensor& lightSensor;
    Device& lamp;

public:
    LightController(AnalogSensor& light, Device& lampDevice)
        : lightSensor(light),
          lamp(lampDevice) {}

    void update() override {
        if (!isNight() && lightSensor.percent() < climate->minLight) {
            lamp.on();
        }
    }
};

class WateringController : public Controller {
private:
    AnalogSensor& soilSensor;
    Device& pump;

    bool pumpIsWorking;
    bool pumpIsWaiting;

    unsigned long pumpStartTime;
    unsigned long pauseStartTime;

public:
    WateringController(AnalogSensor& soil, Device& pumpDevice)
        : soilSensor(soil),
          pump(pumpDevice),
          pumpIsWorking(false),
          pumpIsWaiting(false),
          pumpStartTime(0),
          pauseStartTime(0) {}

    void update() override {
        unsigned long now = millis();

        if (soilSensor.percent() >= climate->minSoilHumidity) {
            pumpIsWorking = false;
            pumpIsWaiting = false;
            return;
        }

        if (pumpIsWorking) {
            // Полив идёт импульсами, т.е. короткое включение насоса и пауза на впитывание
            if (now - pumpStartTime < PUMP_WORK_TIME) {
                pump.on();
            } else {
                pumpIsWorking = false;
                pumpIsWaiting = true;
                pauseStartTime = now;
            }

            return;
        }

        if (pumpIsWaiting) {
            if (now - pauseStartTime < PUMP_PAUSE_TIME) {
                return;
            }

            pumpIsWaiting = false;
        }

        pumpIsWorking = true;
        pumpStartTime = now;
        pump.on();
    }
};

class TemperatureController : public Controller {
private:
    AirSensor& airSensor;
    Device& heater;
    Device& fan;

public:
    TemperatureController(AirSensor& air, Device& heaterDevice, Device& fanDevice)
        : airSensor(air),
          heater(heaterDevice),
          fan(fanDevice) {}

    void update() override {
        if (!airSensor.hasTemperature()) {
            return;
        }

        float temp = airSensor.temperature();

        if (temp > climate->maxTemp) {
            fan.on();
            return;
        }

        // Вентилятор помогает равномерно распределять воздух при нагреве
        if (temp < climate->minTemp) {
            heater.on();
            fan.on();
        }
    }
};

class HumidityController : public Controller {
private:
    AirSensor& airSensor;
    Device& fan;

public:
    HumidityController(AirSensor& air, Device& fanDevice)
        : airSensor(air),
          fan(fanDevice) {}

    void update() override {
        if (!airSensor.hasHumidity()) {
            return;
        }

        if (airSensor.humidity() > climate->maxAirHumidity) {
            fan.on();
        }
    }
};

class VentilationController : public Controller {
private:
    Device& fan;

public:
    VentilationController(Device& fanDevice)
        : fan(fanDevice) {}

    void update() override {
        if (isNight()) {
            return;
        }

        unsigned int minute = getMinuteOfDay();
        unsigned int period = climate->ventilationPeriod;
        unsigned int duration = climate->ventilationDuration;

        if (period > 0 && duration > 0) {
            if (minute % period < duration) {
                fan.on();
            }
        }
    }
};

AirSensor air(DHT_PIN);

AnalogSensor soil(SOIL_PIN, SOIL_DRY_RAW, SOIL_WET_RAW);
AnalogSensor light(LIGHT_PIN, LIGHT_DARK_RAW, LIGHT_BRIGHT_RAW);

Device pump(PUMP_PIN);
Device fan(FAN_PIN);
Device heater(HEATER_PIN);
Device lamp(LAMP_PIN);

LightController lightController(light, lamp);
WateringController wateringController(soil, pump);
TemperatureController temperatureController(air, heater, fan);
HumidityController humidityController(air, fan);
VentilationController ventilationController(fan);

Sensor* sensors[] = {
    &air,
    &soil,
    &light
};

Device* devices[] = {
    &pump,
    &fan,
    &heater,
    &lamp
};

Controller* controllers[] = {
    &lightController,
    &wateringController,
    &temperatureController,
    &humidityController,
    &ventilationController
};

const byte SENSOR_COUNT = sizeof(sensors) / sizeof(sensors[0]);
const byte DEVICE_COUNT = sizeof(devices) / sizeof(devices[0]);
const byte CONTROLLER_COUNT = sizeof(controllers) / sizeof(controllers[0]);

void beginSensors() {
    for (byte i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->begin();
    }
}

void beginDevices() {
    for (byte i = 0; i < DEVICE_COUNT; i++) {
        devices[i]->begin();
    }
}

void updateSensors() {
    for (byte i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->update();
    }
}

void resetDevices() {
    // Регуляторы заново выставляют запросы каждый цикл, а запись в пины происходит в applyDevices()
    for (byte i = 0; i < DEVICE_COUNT; i++) {
        devices[i]->reset();
    }
}

void updateControllers() {
    for (byte i = 0; i < CONTROLLER_COUNT; i++) {
        controllers[i]->update();
    }
}

void applyDevices() {
    for (byte i = 0; i < DEVICE_COUNT; i++) {
        devices[i]->apply();
    }
}

void printStatus() {
    static unsigned long lastPrintTime = 0;

    if (millis() - lastPrintTime < PRINT_INTERVAL) {
        return;
    }

    lastPrintTime = millis();

    Serial.println(F("- - - - - - GREENHOUSE INFO - - - - - -"));

    Serial.print(F("Climate: "));
    Serial.println(climate->name);

    Serial.print(F("Hour: "));
    Serial.println(getHour());

    Serial.print(F("Night: "));
    Serial.println(isNight() ? F("true") : F("false"));

    Serial.print(F("Temperature: "));
    if (air.hasTemperature()) {
        Serial.print(air.temperature());
        Serial.println(F(" C"));
    } else {
        Serial.println(F("N/A"));
    }

    Serial.print(F("Air humidity: "));
    if (air.hasHumidity()) {
        Serial.print(air.humidity());
        Serial.println(F(" %"));
    } else {
        Serial.println(F("N/A"));
    }

    Serial.print(F("Soil humidity: "));
    Serial.print(soil.percent());
    Serial.print(F(" %, raw = "));
    Serial.println(soil.raw());

    Serial.print(F("Light: "));
    Serial.print(light.percent());
    Serial.print(F(" %, raw = "));
    Serial.println(light.raw());

    Serial.print(F("Pump: "));
    Serial.println(pump.isOn() ? F("ON") : F("OFF"));

    Serial.print(F("Fan: "));
    Serial.println(fan.isOn() ? F("ON") : F("OFF"));

    Serial.print(F("Heater: "));
    Serial.println(heater.isOn() ? F("ON") : F("OFF"));

    Serial.print(F("Lamp: "));
    Serial.println(lamp.isOn() ? F("ON") : F("OFF"));

    Serial.println();
}

void setup() {
    Serial.begin(9600);

    beginSensors();
    beginDevices();

    Serial.println(F("Greenhouse controller started"));
}

void loop() {
    updateSensors();

    resetDevices();
    updateControllers();
    applyDevices();

    printStatus();

    delay(100);
}
