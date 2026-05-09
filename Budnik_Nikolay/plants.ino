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

// Границы калибровки нужно определить под конкретную теплицу и конкретный датчик
const int SOIL_DRY_RAW = 0;
const int SOIL_WET_RAW = 1023;

const int LIGHT_DARK_RAW = 1023;
const int LIGHT_BRIGHT_RAW = 0;

struct ClimateSettings {
    const char* name;

    float minTemp, maxTemp;
    float maxAirHumidity;

    int minSoilHumidity;
    int minLight;

    byte nightStart, nightEnd;

    // Время по смыслу должно быть неотрицательно
    unsigned int ventilationPeriod, ventilationDuration; // Провертирование каждые ventilationPeriod минут на ventilationDuration минут
};

const ClimateSettings tomato = {
    "Tomato",

    22.0, 28.0,
    70.0,

    35,
    50,

    22, 6,
    180, 5
};

const ClimateSettings cucumber = {
    "Cucumber",

    23.0, 30.0,
    80.0,

    45,
    45,

    22, 6,
    180, 5
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

// Время виртуальное, поэтому считаеться от millis(), после перезагрузки снова стартует с INITIAL_HOUR
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

    // Полив идёт импульсами, т.е. короткое включение насоса и пауза на впитывание
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
    TemperatureController(AirSensor& air, Device&
