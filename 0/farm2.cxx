#include <stdio.h>


class Thermometer {
private:
    int pin;
public:    
    float temperature;  // Celcius
public:
    Thermometer(int pin) : pin(pin) { temperature = 20; }  // TODO: arduino code
public:
    void get_temperature() { temperature = 20; }  // TODO: arduino code
};


class Heater {
public:
    bool on_temperature;
public:
    void power();
};

void Heater::power()  // TODO: arduino
{
    if (on_temperature) {}
    else {}
}


class Fan {
public:
    bool on_temperature;
public:
    void power();
};


void Fan::power()  // TODO: arduino
{
    if (on_temperature) {}  // arduino fan on
    else {}  // arduino fan off
}


void control_temperature(const Thermometer& thermometer, Heater& heater, Fan& fan)
{
    if (thermometer.temperature > 40) {
        heater.on_temperature = false;
        fan.on_temperature = true;
    }

    if (thermometer.temperature < 20) {
        heater.on_temperature = true;
        fan.on_temperature = true;
    }
}


int main()
{    
    Thermometer thermometer(10);
    Heater heater;
    Fan fan;

    for (int count = 10; count > 0; --count) {

        thermometer.get_temperature();
        // gigrometer.get_humidity();
        // light.get_light();

        control_temperature(thermometer, heater, fan);
        // control_humidity(gigrometer, pump, heater, fan);
        // control_light(light, lamp);

        // lamp.power();
        heater.power();
        // pump.power();
        fan.power();
    }
    
}
