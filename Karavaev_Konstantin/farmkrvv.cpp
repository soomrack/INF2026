#include <DHT.h>

#define DHTPIN 12
#define DHTTYPE DHT11
#define HEATER_PIN 4
#define PUMP_PIN 5
#define LAMP_PIN 6
#define FAN_PIN 7
#define LIGHT_SENSOR_PIN A0
#define SOIL_SENSOR_PIN A1

class Thermometer {
private:
    int pin;
    DHT dht;
public:
    float temperature;
    Thermometer(int pin) : pin(pin), dht(pin, DHTTYPE) { temperature = 20; }
    void begin() { dht.begin(); }
    void get_temperature() { temperature = dht.readTemperature(); }
};

class AirHumidity {
private:
    int pin;
    DHT dht;
public:
    float humidity;
    AirHumidity(int pin) : pin(pin), dht(pin, DHTTYPE) { humidity = 0; }
    void begin() { dht.begin(); }
    void get_humidity() { humidity = dht.readHumidity(); }
};

class SoilHumidity {
private:
    int pin;
public:
    int humidity;
    SoilHumidity(int pin) : pin(pin) { humidity = 0; }
    void get_humidity() { humidity = analogRead(pin); }
};

class Light {
private:
    int pin;
public:
    int light_level;
    Light(int pin) : pin(pin) { light_level = 0; }
    void get_light() { light_level = analogRead(pin); }
};

class Heater {
private:
    int pin;
public:
    bool on_temperature;
    Heater(int pin) : pin(pin), on_temperature(false) { pinMode(pin, OUTPUT); }
    void power() { digitalWrite(pin, on_temperature ? LOW : HIGH); }
};

class Fan {
private:
    int pin;
public:
    bool on_temperature;
    Fan(int pin) : pin(pin), on_temperature(false) { pinMode(pin, OUTPUT); }
    void power() { digitalWrite(pin, on_temperature ? LOW : HIGH); }
};

class Pump {
private:
    int pin;
public:
    bool on_humidity;
    Pump(int pin) : pin(pin), on_humidity(false) { pinMode(pin, OUTPUT); }
    void power() { digitalWrite(pin, on_humidity ? LOW : HIGH); }
};

class Lamp {
private:
    int pin;
public:
    bool on_light;
    Lamp(int pin) : pin(pin), on_light(false) { pinMode(pin, OUTPUT); }
    void power() { digitalWrite(pin, on_light ? LOW : HIGH); }
};

void control_temperature(const Thermometer& thermometer, Heater& heater, Fan& fan) {
    if (thermometer.temperature > 28.0) {
        heater.on_temperature = false;
        fan.on_temperature = true;
    } else if (thermometer.temperature < 22.0) {
        heater.on_temperature = true;
        fan.on_temperature = false;
    } else {
        heater.on_temperature = false;
        fan.on_temperature = false;
    }
}

void control_humidity(const SoilHumidity& soil, Pump& pump) {
    if (soil.humidity > 700) {
        pump.on_humidity = true;
    } else {
        pump.on_humidity = false;
    }
}

void control_light(const Light& light, Lamp& lamp) {
    if (light.light_level < 400) {
        lamp.on_light = true;
    } else {
        lamp.on_light = false;
    }
}

Thermometer thermometer(DHTPIN);
AirHumidity air_humidity(DHTPIN);
SoilHumidity soil(SOIL_SENSOR_PIN);
Light light_sensor(LIGHT_SENSOR_PIN);

Heater heater(HEATER_PIN);
Pump pump(PUMP_PIN);
Lamp lamp(LAMP_PIN);
Fan fan(FAN_PIN);

void setup() {
    Serial.begin(9600);
    thermometer.begin();
}

void loop() {
    thermometer.get_temperature();
    air_humidity.get_humidity();
    soil.get_humidity();
    light_sensor.get_light();

    control_temperature(thermometer, heater, fan);
    control_humidity(soil, pump);
    control_light(light_sensor, lamp);

    heater.power();
    fan.power();
    pump.power();
    lamp.power();

    Serial.print("T: "); Serial.print(thermometer.temperature);
    Serial.print(" | Soil: "); Serial.println(soil.humidity);

    delay(2000);
}