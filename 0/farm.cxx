#include <stdio.h>


class Thermometer {
public:
    int temperature;  // Celcius
public:
    Thermometer() { temperature = 0; }
public:
    void get_temperature() { temperature = 30; }  // TODO: arduino
};


class Humidity {
public:
    int humidity;
public:
    Humidity() { humidity = 0; }
public:
    void get_humidity() { humidity = 30; }  // TODO: arduino
};


class Light {
public:
    int light;  // Candel
public:
    Light() { light = 0; }
public:
    void get_light() { light = 1000; }  // TODO: arduino
};


class Lamp {
private:
    int pin;
public:
    bool on_light;
public:
    Lamp(int pin) : pin(pin) { on_light = false; };  // TODO: arduino
public:
    void power();  // TODO: arduino
};


void Lamp::power()
{
    if (on_light) { /* arduino code */ }
    else { /* arduino code */ }
}


void control_light(const Light& light, Lamp& lamp)
{
    if ( light.light > 3000 ) {
        lamp.on_light = false;
        return;
    }
    
    lamp.on_light = true;
}



int main()
{
    Thermometer thermometer;
    Humidity humidity;
    Light light;
    
    Lamp lamp(10);

    for (int count = 10; count != 0; --count) {

        thermometer.get_temperature();
        humidity.get_humidity();
        light.get_light();

        // control_temperature(thermometer, heater, fan);
        // control_humidity(humidity, pump, fan);
        control_light(light, lamp);

        // heater.power();
        // fan.power();
        lamp.power();
        // pump.power();        
    }
}
