#include <stdio.h>

class Thermometer {
private:
    int pin;
public:
    float temperature;
public:
    Thermometer(int pin) : pin(pin) { temperature = 20; }
    void get_temperature() { temperature = 20; }
};


class Heater {
public:
    bool on_temperature;
    void power();
};

void Heater::power() {
    if (on_temperature) {}
    else {}
}


class Fan {
public:
    bool on_temperature;
    void power();
};

void Fan::power() {
    if (on_temperature) {}
    else {}
}


class Hygrometer {
private:
    int pin;
public:
    float humidity;
public:
    Hygrometer(int pin) : pin(pin) { humidity = 50; }
    void get_humidity() { humidity = 50; }
};


class Pump {
public:
    bool on_humidity;
    void power();
};

void Pump::power() {
    if (on_humidity) {}
    else {}
}


class LightSensor {
private:
    int pin;
public:
    int light_level;
public:
    LightSensor(int pin) : pin(pin) { light_level = 300; }
    void get_light() { light_level = 300; }
};


class Lamp {
public:
    bool on_light;
    void power();
};

void Lamp::power() {
    if (on_light) {}
    else {}
}


void control_temperature(const Thermometer& thermometer, Heater& heater, Fan& fan)
{
    if (thermometer.temperature > 40) {
        heater.on_temperature = false;
        fan.on_temperature = true;
    }
    else if (thermometer.temperature < 20) {
        heater.on_temperature = true;
        fan.on_temperature = false;
    }
    else {
        heater.on_temperature = false;
        fan.on_temperature = false;
    }
}


void control_humidity(const Hygrometer& hygrometer, Pump& pump, Fan& fan)
{
    if (hygrometer.humidity > 70) {
        pump.on_humidity = false;
        fan.on_temperature = true;
    }
    else if (hygrometer.humidity < 30) {
        pump.on_humidity = true;
        fan.on_temperature = false;
    }
    else {
        pump.on_humidity = false;
        fan.on_temperature = false;
    }
}


void control_light(const LightSensor& light_sensor, Lamp& lamp)
{
    if (light_sensor.light_level > 500) {
        lamp.on_light = false;
    }
    else if (light_sensor.light_level < 100) {
        lamp.on_light = true;
    }
    else {
        lamp.on_light = false;
    }
}


int main()
{
    Thermometer thermometer(10);
    Heater heater;
    Fan fan;
    Hygrometer hygrometer(11);
    Pump pump;
    LightSensor light_sensor(12);
    Lamp lamp;

    for (int count = 10; count > 0; --count) {

        thermometer.get_temperature();
        hygrometer.get_humidity();
        light_sensor.get_light();

        control_temperature(thermometer, heater, fan);
        control_humidity(hygrometer, pump, fan);
        control_light(light_sensor, lamp);

        lamp.power();
        heater.power();
        pump.power();
        fan.power();
    }

    return 0;
}