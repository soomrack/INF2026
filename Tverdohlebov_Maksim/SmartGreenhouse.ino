#include <DHT.h>

#define DHT_PIN     2
#define DHT_TYPE    DHT22
#define SOIL_PIN    A0
#define LIGHT_PIN   A1
#define FAN_PIN     3
#define HEATER_PIN  4
#define LAMP_PIN    5
#define PUMP_PIN    6

DHT dht(DHT_PIN, DHT_TYPE);

class AirThermometer {
private:
    int pin;
public:
    float temperature;
    AirThermometer(int p) : pin(p) { temperature = 20; }
    void get_temperature() {
        float t = dht.readTemperature();
        if (!isnan(t)) temperature = t;
    }
};


class AirHygrometer {
private:
    int pin;
public:
    float humidity;
    AirHygrometer(int p) : pin(p) { humidity = 50; }
    void get_humidity() {
        float h = dht.readHumidity();
        if (!isnan(h)) humidity = h;
    }
};


class SoilMoistureSensor {
private:
    int pin;
public:
    int moisture;
    SoilMoistureSensor(int p) : pin(p) { moisture = 600; }
    void get_moisture() { moisture = analogRead(pin); }
};


class LightSensor {
private:
    int pin;
public:
    int light;
    LightSensor(int p) : pin(p) { light = 500; }
    void get_light() { light = analogRead(pin); }
};


class Heater {
public:
    bool on;
    Heater() { on = false; }
    void power() { digitalWrite(HEATER_PIN, on ? HIGH : LOW); }
};


class Fan {
public:
    bool on;
    Fan() { on = false; }
    void power() { digitalWrite(FAN_PIN, on ? HIGH : LOW); }
};


class Lamp {
public:
    bool on;
    Lamp() { on = false; }
    void power() { digitalWrite(LAMP_PIN, on ? HIGH : LOW); }
};


class Pump {
public:
    bool on;
    Pump() { on = false; }
    void power() { digitalWrite(PUMP_PIN, on ? HIGH : LOW); }
};


void control_temperature(AirThermometer& thermo, Heater& heater, Fan& fan) {
    if (thermo.temperature > 28) {
        heater.on = false;
        fan.on = true;
    } else if (thermo.temperature < 18) {
        heater.on = true;
        fan.on = true;
    } else {
        heater.on = false;
    }
}


void control_humidity(AirHygrometer& hygro, Fan& fan) {
    if (hygro.humidity > 75) {
        fan.on = true;
    }
}


void control_light(LightSensor& lightSensor, Lamp& lamp, bool isNight) {
    if (!isNight && lightSensor.light < 350) {
        lamp.on = true;
    } else {
        lamp.on = false;
    }
}


void control_soil(SoilMoistureSensor& soil, Pump& pump) {
    static unsigned long lastWaterTime = 0;
    unsigned long now = millis();
    if (soil.moisture > 650 && (now - lastWaterTime > 1800000UL)) {
        pump.on = true;
        lastWaterTime = now;
    } else {
        pump.on = false;
    }
}


void control_schedule(Fan& fan, bool isNight) {
    static unsigned long lastVentTime = 0;
    unsigned long now = millis();
    if (!isNight && (now - lastVentTime > 14400000UL)) {
        fan.on = true;
        lastVentTime = now;
    }
}


bool isNightTime() {
    unsigned long cycle = millis() % 86400000UL;   // 24 часа в миллисекундах
    return cycle >= 43200000UL;                    // после 12 часов — ночь
}


AirThermometer  thermometer(DHT_PIN);
AirHygrometer   hygrometer(DHT_PIN);
SoilMoistureSensor soil(SOIL_PIN);
LightSensor     light(LIGHT_PIN);

Heater heater;
Fan    fan;
Lamp   lamp;
Pump   pump;


void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(FAN_PIN, OUTPUT);
    pinMode(HEATER_PIN, OUTPUT);
    pinMode(LAMP_PIN, OUTPUT);
    pinMode(PUMP_PIN, OUTPUT);
}


void loop() {
    thermometer.get_temperature();
    hygrometer.get_humidity();
    soil.get_moisture();
    light.get_light();

    bool night = isNightTime();

    control_temperature(thermometer, heater, fan);
    control_humidity(hygrometer, fan);
    control_light(light, lamp, night);
    control_soil(soil, pump);
    control_schedule(fan, night);

    heater.power();
    fan.power();
    lamp.power();
    pump.power();

    delay(2000);
}
