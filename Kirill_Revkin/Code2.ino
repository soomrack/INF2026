#include <DHT.h>

const int PIN_DHT             = A2;   // температура + влажность воздуха
const int PIN_SOIL_SENSOR     = A3;   // влажность земли
const int PIN_LIGHT_SENSOR    = A0;   // освещение

const int PIN_PUMP            = 5;
const int PIN_FAN             = 7;
const int PIN_HEATER          = 4;
const int PIN_LAMP            = 6;

#define DHTTYPE DHT11

DHT dht(PIN_DHT, DHTTYPE);

struct ClimateConfig {
    float minTemperature;   // °C
    float maxTemperature;   // °C

    float minAirHumidity;   // %
    float maxAirHumidity;   // %

    int minSoilHumidity;    // %
    int maxSoilHumidity;    // %

    int minLight;           // 0..100
    int maxLight;           // 0..100
};

ClimateConfig config = {
    22.0, 28.0,   // температура
    45.0, 70.0,   // влажность воздуха
    35, 70,       // влажность земли
    35, 80        // освещенность
};

class Actuator {
protected:
    int pin;
    bool state;

public:
    Actuator(int p) : pin(p), state(false) {}

    void begin() {
        pinMode(pin, OUTPUT);
        apply();
    }

    void set(bool newState) {
        state = newState;
    }

    bool isOn() const {
        return state;
    }

    void apply() {
        digitalWrite(pin, state ? HIGH : LOW);
    }
};

class Lamp : public Actuator {
public:
    Lamp(int p) : Actuator(p) {}
};

class Heater : public Actuator {
public:
    Heater(int p) : Actuator(p) {}
};

class Fan : public Actuator {
public:
    Fan(int p) : Actuator(p) {}
};

class Pump : public Actuator {
public:
    Pump(int p) : Actuator(p) {}
};

class AirSensor {
public:
    float temperature; // °C
    float humidity;    // %

    AirSensor() : temperature(0), humidity(0) {}

    void begin() {
        dht.begin();
    }

    void read() {
        float h = dht.readHumidity();
        float t = dht.readTemperature();

        if (!isnan(h)) humidity = h;
        if (!isnan(t)) temperature = t;
    }
};

class SoilHumiditySensor {
private:
    int pin;

public:
    int humidity; // %

    SoilHumiditySensor(int p) : pin(p), humidity(0) {}

    void begin() {
        pinMode(pin, INPUT);
    }

    void read() {
        int raw = analogRead(pin);

        humidity = map(raw, 1023, 0, 0, 100);

        if (humidity < 0) humidity = 0;
        if (humidity > 100) humidity = 100;
    }
};

class LightSensor {
private:
    int pin;

public:
    int light; // 0..100

    LightSensor(int p) : pin(p), light(0) {}

    void begin() {
        pinMode(pin, INPUT);
    }

    void read() {
        int raw = analogRead(pin);
        light = map(raw, 0, 1023, 0, 100);

        if (light < 0) light = 0;
        if (light > 100) light = 100;
    }
};

class SmartFarm {
private:
    AirSensor& airSensor;
    SoilHumiditySensor& soilSensor;
    LightSensor& lightSensor;

    Lamp& lamp;
    Heater& heater;
    Fan& fan;
    Pump& pump;

    ClimateConfig& cfg;

    unsigned long lastPumpStart;
    unsigned long lastPumpStop;
    bool pumpCoolingDown;

    const unsigned long pumpWorkTimeMs = 3000;      // помпа работает 3 сек
    const unsigned long pumpPauseTimeMs = 10000;    // потом пауза 10 сек

public:
    SmartFarm(
        AirSensor& air,
        SoilHumiditySensor& soil,
        LightSensor& light,
        Lamp& lampRef,
        Heater& heaterRef,
        Fan& fanRef,
        Pump& pumpRef,
        ClimateConfig& configRef
    )
        : airSensor(air),
          soilSensor(soil),
          lightSensor(light),
          lamp(lampRef),
          heater(heaterRef),
          fan(fanRef),
          pump(pumpRef),
          cfg(configRef),
          lastPumpStart(0),
          lastPumpStop(0),
          pumpCoolingDown(false) {}

    void updateSensors() {
        airSensor.read();
        soilSensor.read();
        lightSensor.read();
    }

    void controlClimate() {
        bool needHeater = false;
        bool needFanByTemp = false;
        bool needFanByAirHumidity = false;

        if (airSensor.temperature < cfg.minTemperature) {
            needHeater = true;
        }
        else if (airSensor.temperature > cfg.maxTemperature) {
            needFanByTemp = true;
        }

        if (airSensor.humidity > cfg.maxAirHumidity) {
            needFanByAirHumidity = true;
        }

        heater.set(needHeater);
        fan.set(needFanByTemp || needFanByAirHumidity);

        if (lightSensor.light < cfg.minLight) {
            lamp.set(true);
        }
        else if (lightSensor.light > cfg.maxLight) {
            lamp.set(false);
        }

        controlPump();
    }

    void controlPump() {
        unsigned long now = millis();

        if (soilSensor.humidity >= cfg.minSoilHumidity) {
            pump.set(false);
            if (pump.isOn()) {
                lastPumpStop = now;
            }
            pumpCoolingDown = false;
            return;
        }

        if (pump.isOn()) {
            if (now - lastPumpStart >= pumpWorkTimeMs) {
                pump.set(false);
                lastPumpStop = now;
                pumpCoolingDown = true;
            }
            return;
        }

        if (pumpCoolingDown) {
            if (now - lastPumpStop >= pumpPauseTimeMs) {
                pumpCoolingDown = false;
            } else {
                return;
            }
        }

        pump.set(true);
        lastPumpStart = now;
    }

    void applyActuators() {
        lamp.apply();
        heater.apply();
        fan.apply();
        pump.apply();
    }

    void printStatus() {
        Serial.println(F("----- SMART FARM STATUS -----"));

        Serial.print(F("Air temperature: "));
        Serial.print(airSensor.temperature);
        Serial.println(F(" C"));

        Serial.print(F("Air humidity: "));
        Serial.print(airSensor.humidity);
        Serial.println(F(" %"));

        Serial.print(F("Soil humidity: "));
        Serial.print(soilSensor.humidity);
        Serial.println(F(" %"));

        Serial.print(F("Light: "));
        Serial.print(lightSensor.light);
        Serial.println(F(" /100"));

        Serial.print(F("Lamp: "));
        Serial.println(lamp.isOn() ? F("ON") : F("OFF"));

        Serial.print(F("Heater: "));
        Serial.println(heater.isOn() ? F("ON") : F("OFF"));

        Serial.print(F("Fan: "));
        Serial.println(fan.isOn() ? F("ON") : F("OFF"));

        Serial.print(F("Pump: "));
        Serial.println(pump.isOn() ? F("ON") : F("OFF"));

        Serial.println();
    }

    void runCycle() {
        updateSensors();
        controlClimate();
        applyActuators();
        printStatus();
    }
};

AirSensor airSensor;
SoilHumiditySensor soilSensor(PIN_SOIL_SENSOR);
LightSensor lightSensor(PIN_LIGHT_SENSOR);

Lamp lamp(PIN_LAMP);
Heater heater(PIN_HEATER);
Fan fan(PIN_FAN);
Pump pump(PIN_PUMP);

SmartFarm farm(
    airSensor,
    soilSensor,
    lightSensor,
    lamp,
    heater,
    fan,
    pump,
    config
);

void setup() {
    Serial.begin(9600);

    airSensor.begin();
    soilSensor.begin();
    lightSensor.begin();

    lamp.begin();
    heater.begin();
    fan.begin();
    pump.begin();

    Serial.println(F("Smart Farm started"));
}

void loop() {
    farm.runCycle();
    delay(5000);
}