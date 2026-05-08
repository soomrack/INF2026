// ОГУРЧИКИ
// оптимальная температура 22 - 28 
// оптимальная влажность воздуха 70% - 75%
// влажность почвы 350 - 700, где < 350 - слишком мокро, > 700 - сухо. 
// освещённость 12 часов. Контроль света активен с 08:00 по 20:00
// проветривание 5 мин в начале каждого часа с 08:00 по 20:00


#include <Wire.h>
#include <DHT.h>
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

const int DHT_PIN  = 2;
const int LDR_PIN  = A0;
const int SOIL_PIN = A1;

const int FAN_PIN    = 3;
const int HEATER_PIN = 4;
const int LAMP_PIN   = 5;
const int PUMP_PIN   = 6;

#define DHT_TYPE DHT11

// интерфесы
class ISensor {
public:
    virtual void update() = 0;
};

class IActuator {
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void apply() = 0;
};

class IRule {
public:
    virtual void execute() = 0;
};


// профиль климата
class ClimateProfile {
public:
    float minTemperature;
    float maxTemperature;
    float maxAirHumidity;

    int maxSoilMoisture;
    int maxLight;

    int dayStartHour;
    int dayEndHour;

    int ventilationMinutes;
};

class CucumberClimateProfile : public ClimateProfile {
public:
    CucumberClimateProfile() {
        minTemperature = 22.0;
        maxTemperature = 28.0;

        maxAirHumidity = 85.0;

        maxSoilMoisture = 700;
        maxLight = 800;

        dayStartHour = 8;
        dayEndHour = 20;

        ventilationMinutes = 5;
    }
};

// актуатор
class Actuator : public IActuator {
private:
    int pin;
    bool state;

public:
    Actuator(int pin) : pin(pin), state(false) {}

    void setup() {
        pinMode(pin, OUTPUT);
        off();
        apply();
    }

    void on() override {
        state = true;
    }

    void off() override {
        state = false;
    }

    void apply() override {
        digitalWrite(pin, state ? HIGH : LOW);
    }
};

// датчик DHT11
class DHT11Sensor : public ISensor {
private:
    DHT dht;

public:
    float temperature;
    float airHumidity;

    DHT11Sensor(int pin) : dht(pin, DHT_TYPE) {
        temperature = 0;
        airHumidity = 0;
    }

    void setup() {
        dht.begin();
    }

    void update() override {
        float t = dht.readTemperature();
        float h = dht.readHumidity();

        if (!isnan(t)) {
            temperature = t;
        }

        if (!isnan(h)) {
            airHumidity = h;
        }
    }
};

// аналоговый датчик
class AnalogSensor : public ISensor {
private:
    int pin;

public:
    int value;

    AnalogSensor(int pin) : pin(pin), value(0) {}

    void update() override {
        value = analogRead(pin);
    }
};

// часы DS1307
class ClockSensor : public ISensor {
private:
    RTC_DS1307 rtc;

public:
    DateTime currentTime;

    ClockSensor() : currentTime(DateTime()) {}

    void setup() {
        rtc.begin();
    }

    void update() override {
        currentTime = rtc.now();
    }

    bool isDayTime(ClimateProfile& profile) {
        int hour = currentTime.hour();

        return hour >= profile.dayStartHour &&
               hour < profile.dayEndHour;
    }

    bool isVentilationTime(ClimateProfile& profile) {
        return isDayTime(profile) &&
               currentTime.minute() < profile.ventilationMinutes;
    }
};

// дисплей времени
class TimeDisplay {
private:
    Adafruit_7segment display;

public:
    void setup() {
        display.begin(0x70);
        display.clear();
        display.writeDisplay();
    }

    void show(DateTime time) {
        int value = time.hour() * 100 + time.minute();

        display.print(value);
        display.drawColon(true);
        display.writeDisplay();
    }
};


// правила регулирования
class TemperatureRule : public IRule {
private:
    DHT11Sensor& dht;
    ClimateProfile& profile;
    IActuator& fan;
    IActuator& heater;

public:
    TemperatureRule(
        DHT11Sensor& dht,
        ClimateProfile& profile,
        IActuator& fan,
        IActuator& heater
    ) : dht(dht), profile(profile), fan(fan), heater(heater) {}

    void execute() override {
        if (dht.temperature > profile.maxTemperature) {
            fan.on();
            heater.off();
        }

        if (dht.temperature < profile.minTemperature) {
            heater.on();
            fan.on();
        }
    }
};

class AirHumidityRule : public IRule {
private:
    DHT11Sensor& dht;
    ClimateProfile& profile;
    IActuator& fan;

public:
    AirHumidityRule(
        DHT11Sensor& dht,
        ClimateProfile& profile,
        IActuator& fan
    ) : dht(dht), profile(profile), fan(fan) {}

    void execute() override {
        if (dht.airHumidity > profile.maxAirHumidity) {
            fan.on();
        }
    }
};

class SoilMoistureRule : public IRule {
private:
    AnalogSensor& soilSensor;
    ClimateProfile& profile;
    IActuator& pump;

public:
    SoilMoistureRule(
        AnalogSensor& soilSensor,
        ClimateProfile& profile,
        IActuator& pump
    ) : soilSensor(soilSensor), profile(profile), pump(pump) {}

    void execute() override {
        if (soilSensor.value > profile.maxSoilMoisture) {
            pump.on();
        }
    }
};

class LightRule : public IRule {
private:
    AnalogSensor& lightSensor;
    ClockSensor& clock;
    ClimateProfile& profile;
    IActuator& lamp;

public:
    LightRule(
        AnalogSensor& lightSensor,
        ClockSensor& clock,
        ClimateProfile& profile,
        IActuator& lamp
    ) : lightSensor(lightSensor), clock(clock), profile(profile), lamp(lamp) {}

    void execute() override {
        if (clock.isDayTime(profile)) {
            if (lightSensor.value > profile.maxLight) {
                lamp.on();
            }
        }
    }
};

class ScheduVentilationRule : public IRule {
private:
    ClockSensor& clock;
    ClimateProfile& profile;
    IActuator& fan;

public:
    ScheduVentilationRule(
        ClockSensor& clock,
        ClimateProfile& profile,
        IActuator& fan
    ) : clock(clock), profile(profile), fan(fan) {}

    void execute() override {
        if (clock.isVentilationTime(profile)) {
            fan.on();
        }
    }
};

// теплица
class Greenhouse {
private:
    ISensor** sensors;
    int sensorCount;

    IActuator** actuators;
    int actuatorCount;

    IRule** rules;
    int ruleCount;

public:
    Greenhouse(
        ISensor** sensors,
        int sensorCount,
        IActuator** actuators,
        int actuatorCount,
        IRule** rules,
        int ruleCount
    ) {
        this->sensors = sensors;
        this->sensorCount = sensorCount;
        this->actuators = actuators;
        this->actuatorCount = actuatorCount;
        this->rules = rules;
        this->ruleCount = ruleCount;
    }

    void updateSensors() {
        for (int i = 0; i < sensorCount; i++) {
            sensors[i]->update();
        }
    }

    void resetActuators() {
        for (int i = 0; i < actuatorCount; i++) {
            actuators[i]->off();
        }
    }

    void executeRules() {
        for (int i = 0; i < ruleCount; i++) {
            rules[i]->execute();
        }
    }

    void applyActuators() {
        for (int i = 0; i < actuatorCount; i++) {
            actuators[i]->apply();
        }
    }
};

// объекты
CucumberClimateProfile cucumberProfile;

DHT11Sensor dht11(DHT_PIN);
AnalogSensor soilSensor(SOIL_PIN);
AnalogSensor lightSensor(LDR_PIN);
ClockSensor clockSensor;

TimeDisplay timeDisplay;

Actuator fan(FAN_PIN);
Actuator heater(HEATER_PIN);
Actuator lamp(LAMP_PIN);
Actuator pump(PUMP_PIN);

// правила
TemperatureRule temperatureRule(dht11, cucumberProfile, fan, heater);
AirHumidityRule airHumidityRule(dht11, cucumberProfile, fan);
SoilMoistureRule soilMoistureRule(soilSensor, cucumberProfile, pump);
LightRule lightRule(lightSensor, clockSensor, cucumberProfile, lamp);
ScheduVentilationRule ventilationRule(clockSensor, cucumberProfile, fan);

// массивы архитектуры
ISensor* sensors[] = {
    &dht11,
    &soilSensor,
    &lightSensor,
    &clockSensor
};

IActuator* actuators[] = {
    &fan,
    &heater,
    &lamp,
    &pump
};

IRule* rules[] = {
    &temperatureRule,
    &airHumidityRule,
    &soilMoistureRule,
    &lightRule,
    &ventilationRule
};

Greenhouse greenhouse(
    sensors, 4,
    actuators, 4,
    rules, 5
);


void setup()
{
    Serial.begin(9600);

    dht11.setup();
    clockSensor.setup();
    timeDisplay.setup();

    fan.setup();
    heater.setup();
    lamp.setup();
    pump.setup();
}


void loop()
{
    greenhouse.updateSensors();

    greenhouse.resetActuators();
    greenhouse.executeRules();
    greenhouse.applyActuators();

    timeDisplay.show(clockSensor.currentTime);

    Serial.print("Time: ");
    Serial.print(clockSensor.currentTime.hour());
    Serial.print(":");
    Serial.print(clockSensor.currentTime.minute());

    Serial.print(" | Temperature: ");
    Serial.print(dht11.temperature);

    Serial.print(" | Air humidity: ");
    Serial.print(dht11.airHumidity);

    Serial.print(" | Soil: ");
    Serial.print(soilSensor.value);

    Serial.print(" | Light: ");
    Serial.print(lightSensor.value);

    Serial.print(" | Day: ");
    Serial.println(clockSensor.isDayTime(cucumberProfile) ? "YES" : "NO");

    delay(2000);
}
