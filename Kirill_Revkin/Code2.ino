#include <Arduino.h>
#include <DHT.h>

const byte PIN_DHT          = 2;   // DHT11: температура + влажность воздуха
const byte PIN_SOIL_SENSOR  = A1;  // влажность почвы
const byte PIN_LIGHT_SENSOR = A0;  // датчик освещенности

const byte PIN_PUMP   = 5; // помпа
const byte PIN_FAN    = 7; // вентилятор
const byte PIN_HEATER = 4; // нагреватель
const byte PIN_LAMP   = 6; // лампа

#define DHTTYPE DHT11

const int SOIL_DRY_RAW = 0;
const int SOIL_WET_RAW = 1023;

const int LIGHT_DARK_RAW   = 1023;
const int LIGHT_BRIGHT_RAW = 0;

const byte START_HOUR = 12;

struct ClimateConfig {
    const char* name;

    float minTemperatureC;
    float maxTemperatureC;

    float maxAirHumidityPercent;

    int minSoilHumidityPercent;

    int minLightPercent;

    byte nightStartHour;
    byte nightEndHour;

    unsigned int ventilationPeriodMinutes;
    unsigned int ventilationDurationMinutes;
};

ClimateConfig tomatoClimate = {
    "Tomato",
    22.0, 28.0,   // температура воздуха
    70.0,         // максимальная влажность воздуха
    35,           // ниже этого значения почва считается сухой
    50,           // ниже этого значения мало света
    22, 6,        // ночь: 22:00 - 06:00
    180, 5        // проветривание 5 минут каждые 180 минут
};

ClimateConfig cucumberClimate = {
    "Cucumber",
    23.0, 30.0,
    80.0,
    45,
    45,
    22, 6,
    180, 5
};

ClimateConfig* currentClimate = &tomatoClimate;


int clampPercent(long value) {
    if (value < 0) return 0;
    if (value > 100) return 100;
    return (int)value;
}

int rawToPercent(int raw, int rawAtZeroPercent, int rawAtHundredPercent) {
    if (rawAtZeroPercent == rawAtHundredPercent) return 0;

    long value = (long)(raw - rawAtZeroPercent) * 100L;
    value = value / (rawAtHundredPercent - rawAtZeroPercent);
    return clampPercent(value);
}


class Sensor {
public:
    virtual void begin() = 0;
    virtual void update() = 0;
    virtual const char* name() const = 0;
};

class ControlAlgorithm {
public:
    virtual void control() = 0;
    virtual const char* name() const = 0;
};


class AirSensor : public Sensor {
private:
    DHT dht;
    float temperatureC;
    float humidityPercent;

public:
    AirSensor(byte pin) : dht(pin, DHTTYPE), temperatureC(0), humidityPercent(0) {}

    void begin() override {
        dht.begin();
    }

    void update() override {
        float newHumidity = dht.readHumidity();
        float newTemperature = dht.readTemperature();

        if (!isnan(newHumidity)) {
            humidityPercent = newHumidity;
        }

        if (!isnan(newTemperature)) {
            temperatureC = newTemperature;
        }
    }

    float temperature() const {
        return temperatureC;
    }

    float humidity() const {
        return humidityPercent;
    }

    const char* name() const override {
        return "air temperature and humidity";
    }
};


class SoilHumiditySensor : public Sensor {
private:
    byte pin;
    int humidityPercent;
    int rawValue;

public:
    SoilHumiditySensor(byte sensorPin) : pin(sensorPin), humidityPercent(0), rawValue(0) {}

    void begin() override {
        pinMode(pin, INPUT);
    }

    void update() override {
        rawValue = analogRead(pin);
        humidityPercent = rawToPercent(rawValue, SOIL_DRY_RAW, SOIL_WET_RAW);
    }

    int humidity() const {
        return humidityPercent;
    }

    int raw() const {
        return rawValue;
    }

    const char* name() const override {
        return "soil humidity";
    }
};


class LightSensor : public Sensor {
private:
    byte pin;
    int lightPercent;
    int rawValue;

public:
    LightSensor(byte sensorPin) : pin(sensorPin), lightPercent(0), rawValue(0) {}

    void begin() override {
        pinMode(pin, INPUT);
    }

    void update() override {
        rawValue = analogRead(pin);
        lightPercent = rawToPercent(rawValue, LIGHT_DARK_RAW, LIGHT_BRIGHT_RAW);
    }

    int light() const {
        return lightPercent;
    }

    int raw() const {
        return rawValue;
    }

    const char* name() const override {
        return "light";
    }
};


class Actuator {
private:
    byte pin;
    const char* actuatorName;
    bool activeHigh;
    bool requestedState;

public:
    Actuator(byte actuatorPin, const char* name, bool isActiveHigh = true)
        : pin(actuatorPin), actuatorName(name), activeHigh(isActiveHigh), requestedState(false) {}

    void begin() {
        pinMode(pin, OUTPUT);
        off();
        apply();
    }

    void resetRequest() {
        requestedState = false;
    }

    void on() {
        requestedState = true;
    }

    void off() {
        requestedState = false;
    }

    bool isOn() const {
        return requestedState;
    }

    void apply() {
        if (activeHigh) {
            digitalWrite(pin, requestedState ? HIGH : LOW);
        } else {
            digitalWrite(pin, requestedState ? LOW : HIGH);
        }
    }

    const char* name() const {
        return actuatorName;
    }
};


class GreenhouseClock {
private:
    const unsigned long minuteMs = 60000UL;
    const unsigned long hourMs = 3600000UL;
    const unsigned long dayMs = 86400000UL;

public:
    byte hour() const {
        byte passedHours = (millis() % dayMs) / hourMs;
        return (START_HOUR + passedHours) % 24;
    }

    unsigned int minuteOfDay() const {
        unsigned long passedMinutes = (millis() % dayMs) / minuteMs;
        return (START_HOUR * 60 + passedMinutes) % 1440;
    }

    bool isNight(const ClimateConfig& config) const {
        byte h = hour();

        if (config.nightStartHour < config.nightEndHour) {
            return h >= config.nightStartHour && h < config.nightEndHour;
        }

        return h >= config.nightStartHour || h < config.nightEndHour;
    }
};


class LightControl : public ControlAlgorithm {
private:
    LightSensor& lightSensor;
    Actuator& lamp;
    GreenhouseClock& clock;
    ClimateConfig*& config;

public:
    LightControl(LightSensor& light, Actuator& lampActuator,
                 GreenhouseClock& greenhouseClock, ClimateConfig*& climate)
        : lightSensor(light), lamp(lampActuator), clock(greenhouseClock), config(climate) {}

    void control() override {
        if (!clock.isNight(*config) && lightSensor.light() < config->minLightPercent) {
            lamp.on();
        }
    }

    const char* name() const override {
        return "light control";
    }
};


class SoilWateringControl : public ControlAlgorithm {
private:
    SoilHumiditySensor& soilSensor;
    Actuator& pump;
    ClimateConfig*& config;

    bool wateringNow;
    bool pauseNow;
    unsigned long wateringStartTime;
    unsigned long pauseStartTime;

    const unsigned long pumpWorkTimeMs = 3000UL;
    const unsigned long pumpPauseTimeMs = 10000UL;

public:
    SoilWateringControl(SoilHumiditySensor& soil, Actuator& pumpActuator, ClimateConfig*& climate)
        : soilSensor(soil), pump(pumpActuator), config(climate),
          wateringNow(false), pauseNow(false), wateringStartTime(0), pauseStartTime(0) {}

    void control() override {
        unsigned long now = millis();

        if (soilSensor.humidity() >= config->minSoilHumidityPercent) {
            wateringNow = false;
            pauseNow = false;
            return;
        }

        if (wateringNow) {
            if (now - wateringStartTime < pumpWorkTimeMs) {
                pump.on();
            } else {
                wateringNow = false;
                pauseNow = true;
                pauseStartTime = now;
            }
            return;
        }

        if (pauseNow) {
            if (now - pauseStartTime >= pumpPauseTimeMs) {
                pauseNow = false;
            } else {
                return;
            }
        }

        wateringNow = true;
        wateringStartTime = now;
        pump.on();
    }

    const char* name() const override {
        return "soil watering";
    }
};


class TemperatureControl : public ControlAlgorithm {
private:
    AirSensor& airSensor;
    Actuator& heater;
    Actuator& fan;
    ClimateConfig*& config;

public:
    TemperatureControl(AirSensor& air, Actuator& heaterActuator,
                       Actuator& fanActuator, ClimateConfig*& climate)
        : airSensor(air), heater(heaterActuator), fan(fanActuator), config(climate) {}

    void control() override {
        if (airSensor.temperature() > config->maxTemperatureC) {
            fan.on();
            return;
        }

        if (airSensor.temperature() < config->minTemperatureC) {
            heater.on();
            fan.on();
        }
    }

    const char* name() const override {
        return "temperature control";
    }
};


class AirHumidityControl : public ControlAlgorithm {
private:
    AirSensor& airSensor;
    Actuator& fan;
    ClimateConfig*& config;

public:
    AirHumidityControl(AirSensor& air, Actuator& fanActuator, ClimateConfig*& climate)
        : airSensor(air), fan(fanActuator), config(climate) {}

    void control() override {
        if (airSensor.humidity() > config->maxAirHumidityPercent) {
            fan.on();
        }
    }

    const char* name() const override {
        return "air humidity control";
    }
};


class ScheduleVentilationControl : public ControlAlgorithm {
private:
    Actuator& fan;
    GreenhouseClock& clock;
    ClimateConfig*& config;

public:
    ScheduleVentilationControl(Actuator& fanActuator, GreenhouseClock& greenhouseClock,
                               ClimateConfig*& climate)
        : fan(fanActuator), clock(greenhouseClock), config(climate) {}

    void control() override {
        if (clock.isNight(*config)) {
            return;
        }

        unsigned int minute = clock.minuteOfDay();
        unsigned int period = config->ventilationPeriodMinutes;
        unsigned int duration = config->ventilationDurationMinutes;

        if (period > 0 && duration > 0 && minute % period < duration) {
            fan.on();
        }
    }

    const char* name() const override {
        return "scheduled ventilation";
    }
};


AirSensor airSensor(PIN_DHT);
SoilHumiditySensor soilSensor(PIN_SOIL_SENSOR);
LightSensor lightSensor(PIN_LIGHT_SENSOR);


Actuator pump(PIN_PUMP, "pump");
Actuator fan(PIN_FAN, "fan");
Actuator heater(PIN_HEATER, "heater");
Actuator lamp(PIN_LAMP, "lamp");

GreenhouseClock greenhouseClock;


LightControl lightControl(lightSensor, lamp, greenhouseClock, currentClimate);
SoilWateringControl wateringControl(soilSensor, pump, currentClimate);
TemperatureControl temperatureControl(airSensor, heater, fan, currentClimate);
AirHumidityControl humidityControl(airSensor, fan, currentClimate);
ScheduleVentilationControl scheduleVentilation(fan, greenhouseClock, currentClimate);

Sensor* sensors[] = {
    &airSensor,
    &soilSensor,
    &lightSensor
};

Actuator* actuators[] = {
    &pump,
    &fan,
    &heater,
    &lamp
};

ControlAlgorithm* algorithms[] = {
    &lightControl,
    &wateringControl,
    &temperatureControl,
    &humidityControl,
    &scheduleVentilation
};

const byte SENSOR_COUNT = sizeof(sensors) / sizeof(sensors[0]);
const byte ACTUATOR_COUNT = sizeof(actuators) / sizeof(actuators[0]);
const byte ALGORITHM_COUNT = sizeof(algorithms) / sizeof(algorithms[0]);


void beginSensors() {
    for (byte i = 0; i < SENSOR_COUNT; ++i) {
        sensors[i]->begin();
    }
}

void beginActuators() {
    for (byte i = 0; i < ACTUATOR_COUNT; ++i) {
        actuators[i]->begin();
    }
}

void updateSensors() {
    for (byte i = 0; i < SENSOR_COUNT; ++i) {
        sensors[i]->update();
    }
}

void resetActuatorRequests() {
    for (byte i = 0; i < ACTUATOR_COUNT; ++i) {
        actuators[i]->resetRequest();
    }
}

void runControlAlgorithms() {
    for (byte i = 0; i < ALGORITHM_COUNT; ++i) {
        algorithms[i]->control();
    }
}

void applyActuators() {
    for (byte i = 0; i < ACTUATOR_COUNT; ++i) {
        actuators[i]->apply();
    }
}

void printStatus() {
    static unsigned long lastPrint = 0;
    const unsigned long printIntervalMs = 5000UL;

    if (millis() - lastPrint < printIntervalMs) {
        return;
    }

    lastPrint = millis();

    Serial.println(F("----- SMART FARM STATUS -----"));

    Serial.print(F("Climate: "));
    Serial.println(currentClimate->name);

    Serial.print(F("Time hour: "));
    Serial.println(greenhouseClock.hour());

    Serial.print(F("Night: "));
    Serial.println(greenhouseClock.isNight(*currentClimate) ? F("YES") : F("NO"));

    Serial.print(F("Air temperature: "));
    Serial.print(airSensor.temperature());
    Serial.println(F(" C"));

    Serial.print(F("Air humidity: "));
    Serial.print(airSensor.humidity());
    Serial.println(F(" %"));

    Serial.print(F("Soil humidity: "));
    Serial.print(soilSensor.humidity());
    Serial.print(F(" %, raw = "));
    Serial.println(soilSensor.raw());

    Serial.print(F("Light: "));
    Serial.print(lightSensor.light());
    Serial.print(F(" %, raw = "));
    Serial.println(lightSensor.raw());

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
    beginActuators();

    Serial.println(F("Smart Farm started"));
}

void loop() {
    updateSensors();             // 1. читаем датчики
    resetActuatorRequests();     // 2. очищаем прошлые команды
    runControlAlgorithms();      // 3. запускаем алгоритмы регулирования
    applyActuators();            // 4. применяем команды к актуаторам
    printStatus();               // 5. выводим состояние системы

    delay(5000);
}
