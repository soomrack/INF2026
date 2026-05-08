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
const unsigned long DHT_READ_INTERVAL_MS = 2000UL;

// Границы калибровки нужно определить под конкретную теплицу и конкретный датчик
const int SOIL_MIN_RAW = 0;
const int SOIL_MAX_RAW = 1023;

const int LIGHT_DARK_RAW = 1023;
const int LIGHT_BRIGHT_RAW = 0;

const byte INITIAL_HOUR = 12;

struct PlantMode {
    const char* title;

    float tempLow;
    float tempHigh;

    float airHumidityLimit;
    int soilHumidityLimit;
    int lightLimit;

    byte nightFrom;
    byte nightTo;

    unsigned int fanPeriodMin;
    unsigned int fanWorkMin;
};

PlantMode tomatoMode = {
    "Tomato",
    22.0, 28.0,
    70.0,
    35,
    50,
    22, 6,
    180, 5
};

PlantMode cucumberMode = {
    "Cucumber",
    23.0, 30.0,
    80.0,
    45,
    45,
    22, 6,
    180, 5
};

PlantMode* activeMode = &tomatoMode;

int limitToPercent(long number) {
    if (number < 0) {
        return 0;
    }

    if (number > 100) {
        return 100;
    }

    return (int)number;
}

int convertRawToPercent(int raw, int rawZero, int rawFull) {
    if (rawZero == rawFull) {
        return 0;
    }

    // rawZero и rawFull могут идти в обратном порядке
    long percent = (long)(raw - rawZero) * 100L;
    percent = percent / (rawFull - rawZero);

    return limitToPercent(percent);
}

class BaseSensor {
public:
    virtual void init() = 0;
    virtual void read() = 0;
};

class BaseRegulator {
public:
    virtual void process() = 0;
};

class AirMonitor : public BaseSensor {
private:
    DHT dht;
    float tempValue;
    float humidityValue;
    unsigned long previousReadMs;
    bool hasRead;
    bool hasTemperature;
    bool hasHumidity;

public:
    AirMonitor(byte pin)
        : dht(pin, DHT_MODEL),
          tempValue(0),
          humidityValue(0),
          previousReadMs(0),
          hasRead(false),
          hasTemperature(false),
          hasHumidity(false) {}

    void init() override {
        dht.begin();
    }

    void read() override {
        unsigned long currentMs = millis();

        if (hasRead && currentMs - previousReadMs < DHT_READ_INTERVAL_MS) {
            return;
        }

        previousReadMs = currentMs;
        hasRead = true;

        float h = dht.readHumidity();
        float t = dht.readTemperature();

        // При ошибке DHT возвращает NaN, это защита
        if (!isnan(h)) {
            humidityValue = h;
            hasHumidity = true;
        }

        if (!isnan(t)) {
            tempValue = t;
            hasTemperature = true;
        }
    }

    bool temperatureReady() const {
        return hasTemperature;
    }

    bool humidityReady() const {
        return hasHumidity;
    }

    float getTemperature() const {
        return tempValue;
    }

    float getHumidity() const {
        return humidityValue;
    }

};

class SoilMonitor : public BaseSensor {
private:
    byte inputPin;
    int percentValue;
    int analogValue;

public:
    SoilMonitor(byte pin)
        : inputPin(pin), percentValue(0), analogValue(0) {}

    void init() override {
        pinMode(inputPin, INPUT);
    }

    void read() override {
        analogValue = analogRead(inputPin);
        percentValue = convertRawToPercent(
            analogValue,
            SOIL_MIN_RAW,
            SOIL_MAX_RAW
        );
    }

    int getPercent() const {
        return percentValue;
    }

    int getRaw() const {
        return analogValue;
    }

};

class LightMonitor : public BaseSensor {
private:
    byte inputPin;
    int percentValue;
    int analogValue;

public:
    LightMonitor(byte pin)
        : inputPin(pin), percentValue(0), analogValue(0) {}

    void init() override {
        pinMode(inputPin, INPUT);
    }

    void read() override {
        analogValue = analogRead(inputPin);
        percentValue = convertRawToPercent(
            analogValue,
            LIGHT_DARK_RAW,
            LIGHT_BRIGHT_RAW
        );
    }

    int getLightPercent() const {
        return percentValue;
    }

    int getRaw() const {
        return analogValue;
    }

};

class Device {
private:
    byte outputPin;
    bool activeLevelHigh;
    bool stateRequest;

public:
    Device(byte pin, bool highLevel = true)
        : outputPin(pin),
          activeLevelHigh(highLevel),
          stateRequest(false) {}

    void init() {
        pinMode(outputPin, OUTPUT);
        turnOff();
        writeState();
    }

    void clear() {
        stateRequest = false;
    }

    void turnOn() {
        stateRequest = true;
    }

    void turnOff() {
        stateRequest = false;
    }

    bool enabled() const {
        return stateRequest;
    }

    void writeState() {
        if (activeLevelHigh) {
            digitalWrite(outputPin, stateRequest ? HIGH : LOW);
        } else {
            digitalWrite(outputPin, stateRequest ? LOW : HIGH);
        }
    }
};

class FarmTimer {
private:
    // Время виртуальное, поэтому считаеться от millis(), после перезагрузки снова стартует с INITIAL_HOUR
    const unsigned long ONE_MINUTE = 60000UL;
    const unsigned long ONE_HOUR = 3600000UL;
    const unsigned long ONE_DAY = 86400000UL;

public:
    byte getHour() const {
        byte hoursAfterStart = (millis() % ONE_DAY) / ONE_HOUR;
        return (INITIAL_HOUR + hoursAfterStart) % 24;
    }

    unsigned int getMinuteOfDay() const {
        unsigned long minutesAfterStart = (millis() % ONE_DAY) / ONE_MINUTE;
        return (INITIAL_HOUR * 60 + minutesAfterStart) % 1440;
    }

    bool nightNow(const PlantMode& mode) const {
        byte h = getHour();

        // Для интервала ночи через полночь, например 22.00-06.00, нужна отдельная проверка
        if (mode.nightFrom < mode.nightTo) {
            return h >= mode.nightFrom && h < mode.nightTo;
        }

        return h >= mode.nightFrom || h < mode.nightTo;
    }
};

class LampRegulator : public BaseRegulator {
private:
    LightMonitor& light;
    Device& lamp;
    FarmTimer& timer;
    PlantMode*& mode;

public:
    LampRegulator(
        LightMonitor& lightSensor,
        Device& lampDevice,
        FarmTimer& farmTimer,
        PlantMode*& plantMode
    )
        : light(lightSensor),
          lamp(lampDevice),
          timer(farmTimer),
          mode(plantMode) {}

    void process() override {
        bool dayTime = !timer.nightNow(*mode);
        bool notEnoughLight = light.getLightPercent() < mode->lightLimit;

        if (dayTime && notEnoughLight) {
            lamp.turnOn();
        }
    }

};

class WateringRegulator : public BaseRegulator {
private:
    SoilMonitor& soil;
    Device& pump;
    PlantMode*& mode;

    bool pumpStage;
    bool waitingStage;

    unsigned long pumpStartMs;
    unsigned long waitStartMs;

    // Полив идёт импульсами, т.е. короткое включение насоса и пауза на впитывание
    const unsigned long PUMP_ON_TIME = 3000UL;
    const unsigned long WATER_PAUSE = 10000UL;

public:
    WateringRegulator(
        SoilMonitor& soilSensor,
        Device& pumpDevice,
        PlantMode*& plantMode
    )
        : soil(soilSensor),
          pump(pumpDevice),
          mode(plantMode),
          pumpStage(false),
          waitingStage(false),
          pumpStartMs(0),
          waitStartMs(0) {}

    void process() override {
        unsigned long currentMs = millis();

        if (soil.getPercent() >= mode->soilHumidityLimit) {
            pumpStage = false;
            waitingStage = false;
            return;
        }

        if (pumpStage) {
            if (currentMs - pumpStartMs < PUMP_ON_TIME) {
                pump.turnOn();
            } else {
                pumpStage = false;
                waitingStage = true;
                waitStartMs = currentMs;
            }

            return;
        }

        if (waitingStage) {
            if (currentMs - waitStartMs < WATER_PAUSE) {
                return;
            }

            waitingStage = false;
        }

        pumpStage = true;
        pumpStartMs = currentMs;
        pump.turnOn();
    }

};

class TemperatureRegulator : public BaseRegulator {
private:
    AirMonitor& air;
    Device& heater;
    Device& fan;
    PlantMode*& mode;

public:
    TemperatureRegulator(
        AirMonitor& airSensor,
        Device& heaterDevice,
        Device& fanDevice,
        PlantMode*& plantMode
    )
        : air(airSensor),
          heater(heaterDevice),
          fan(fanDevice),
          mode(plantMode) {}

    void process() override {
        if (!air.temperatureReady()) {
            return;
        }

        float temperature = air.getTemperature();

        if (temperature > mode->tempHigh) {
            fan.turnOn();
            return;
        }

        // Вентилятор помогает равномерно распределять воздух при нагреве
        if (temperature < mode->tempLow) {
            heater.turnOn();
            fan.turnOn();
        }
    }

};

class HumidityRegulator : public BaseRegulator {
private:
    AirMonitor& air;
    Device& fan;
    PlantMode*& mode;

public:
    HumidityRegulator(
        AirMonitor& airSensor,
        Device& fanDevice,
        PlantMode*& plantMode
    )
        : air(airSensor),
          fan(fanDevice),
          mode(plantMode) {}

    void process() override {
        if (!air.humidityReady()) {
            return;
        }

        if (air.getHumidity() > mode->airHumidityLimit) {
            fan.turnOn();
        }
    }

};

class VentilationRegulator : public BaseRegulator {
private:
    Device& fan;
    FarmTimer& timer;
    PlantMode*& mode;

public:
    VentilationRegulator(
        Device& fanDevice,
        FarmTimer& farmTimer,
        PlantMode*& plantMode
    )
        : fan(fanDevice),
          timer(farmTimer),
          mode(plantMode) {}

    void process() override {
        if (timer.nightNow(*mode)) {
            return;
        }

        unsigned int currentMinute = timer.getMinuteOfDay();
        unsigned int period = mode->fanPeriodMin;
        unsigned int duration = mode->fanWorkMin;

        if (period > 0 && duration > 0) {
            if (currentMinute % period < duration) {
                fan.turnOn();
            }
        }
    }

};

AirMonitor air(DHT_PIN);
SoilMonitor soil(SOIL_PIN);
LightMonitor light(LIGHT_PIN);

Device pump(PUMP_PIN);
Device fan(FAN_PIN);
Device heater(HEATER_PIN);
Device lamp(LAMP_PIN);

FarmTimer farmClock;

LampRegulator lampControl(light, lamp, farmClock, activeMode);
WateringRegulator wateringControl(soil, pump, activeMode);
TemperatureRegulator tempControl(air, heater, fan, activeMode);
HumidityRegulator humidityControl(air, fan, activeMode);
VentilationRegulator ventilationControl(fan, farmClock, activeMode);

BaseSensor* allSensors[] = {
    &air,
    &soil,
    &light
};

Device* allDevices[] = {
    &pump,
    &fan,
    &heater,
    &lamp
};

BaseRegulator* allRegulators[] = {
    &lampControl,
    &wateringControl,
    &tempControl,
    &humidityControl,
    &ventilationControl
};

const byte SENSORS_AMOUNT = sizeof(allSensors) / sizeof(allSensors[0]);
const byte DEVICES_AMOUNT = sizeof(allDevices) / sizeof(allDevices[0]);
const byte REGULATORS_AMOUNT = sizeof(allRegulators) / sizeof(allRegulators[0]);

void initSensors() {
    for (byte i = 0; i < SENSORS_AMOUNT; i++) {
        allSensors[i]->init();
    }
}

void initDevices() {
    for (byte i = 0; i < DEVICES_AMOUNT; i++) {
        allDevices[i]->init();
    }
}

void readAllSensors() {
    for (byte i = 0; i < SENSORS_AMOUNT; i++) {
        allSensors[i]->read();
    }
}

void clearDeviceStates() {
    // Регуляторы заново выставляют запросы каждый цикл, а запись в пины происходит в updateOutputs()
    for (byte i = 0; i < DEVICES_AMOUNT; i++) {
        allDevices[i]->clear();
    }
}

void calculateControlActions() {
    for (byte i = 0; i < REGULATORS_AMOUNT; i++) {
        allRegulators[i]->process();
    }
}

void updateOutputs() {
    for (byte i = 0; i < DEVICES_AMOUNT; i++) {
        allDevices[i]->writeState();
    }
}

void showSystemInfo() {
    static unsigned long previousPrint = 0;
    const unsigned long PRINT_DELAY = 5000UL;

    if (millis() - previousPrint < PRINT_DELAY) {
        return;
    }

    previousPrint = millis();

    Serial.println(F("- - - - - - GREENHOUSE INFO - - - - - -"));

    Serial.print(F("Selected mode: "));
    Serial.println(activeMode->title);

    Serial.print(F("Current hour: "));
    Serial.println(farmClock.getHour());

    Serial.print(F("Night mode: "));
    Serial.println(farmClock.nightNow(*activeMode) ? F("true") : F("false"));

    Serial.print(F("Temperature: "));
    if (air.temperatureReady()) {
        Serial.print(air.getTemperature());
        Serial.println(F(" C"));
    } else {
        Serial.println(F("N/A"));
    }

    Serial.print(F("Air humidity: "));
    if (air.humidityReady()) {
        Serial.print(air.getHumidity());
        Serial.println(F(" %"));
    } else {
        Serial.println(F("N/A"));
    }

    Serial.print(F("Soil moisture: "));
    Serial.print(soil.getPercent());
    Serial.print(F(" %, ADC = "));
    Serial.println(soil.getRaw());

    Serial.print(F("Light level: "));
    Serial.print(light.getLightPercent());
    Serial.print(F(" %, ADC = "));
    Serial.println(light.getRaw());

    Serial.print(F("Pump state: "));
    Serial.println(pump.enabled() ? F("ON") : F("OFF"));

    Serial.print(F("Fan state: "));
    Serial.println(fan.enabled() ? F("ON") : F("OFF"));

    Serial.print(F("Heater state: "));
    Serial.println(heater.enabled() ? F("ON") : F("OFF"));

    Serial.print(F("Lamp state: "));
    Serial.println(lamp.enabled() ? F("ON") : F("OFF"));

    Serial.println();
}

void setup() {
    Serial.begin(9600);

    initSensors();
    initDevices();

    Serial.println(F("Greenhouse controller is running"));
}

void loop() {
    readAllSensors();
    clearDeviceStates();
    calculateControlActions();
    updateOutputs();
    showSystemInfo();

    delay(100);
}
