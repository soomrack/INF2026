#include <iostream>
#include <vector>


using namespace std;

// ================= БАЗОВЫЕ КЛАССЫ =================

// Базовый класс датчика
class Sensor {
public:
    virtual void update() = 0;
    virtual void show() const = 0;
};

// Базовый класс актуатора
class Actuator {
protected:
    bool is_on;

public:
    Actuator() : is_on(false) {}

    virtual void on() {
        is_on = true;
    }

    virtual void off() {
        is_on = false;
    }

    virtual void power() const = 0;
};

// ================= ДАТЧИКИ =================

// Датчик температуры
class Thermometer : public Sensor {
private:
    int pin;
    float temperature;

public:
    Thermometer(int p) : pin(p), temperature(20) {}

    void update() override {
        temperature = 20;
    }

    float get_temperature() const {
        return temperature;
    }

    void show() const override {
        cout << "Temperature: "
            << temperature
            << " C" << endl;
    }
};

// Датчик влажности воздуха
class Hygrometer : public Sensor {
private:
    int pin;
    float humidity;

public:
    Hygrometer(int p) : pin(p), humidity(60) {}

    void update() override {
        humidity = 70;
    }

    float get_humidity() const {
        return humidity;
    }

    void show() const override {
        cout << "Air humidity: "
            << humidity
            << " %" << endl;
    }
};

// Датчик влажности почвы
class SoilHumiditySensor : public Sensor {
private:
    int pin;
    float soil_humidity;

public:
    SoilHumiditySensor(int p)
        : pin(p), soil_humidity(50) {
    }

    void update() override {
        soil_humidity = 50;
    }

    float get_soil_humidity() const {
        return soil_humidity;
    }

    void show() const override {
        cout << "Soil humidity: "
            << soil_humidity
            << " %" << endl;
    }
};

// Датчик освещения
class LightSensor : public Sensor {
private:
    int pin;
	float light_level; // уровень освещенности

public:
    LightSensor(int p)
        : pin(p), light_level(3000) {
    }

    void update() override {
        light_level = 1000;
    }

    float get_light_level() const {
        return light_level;
    }

    void show() const override {
        cout << "light_level: "
            << light_level
            << endl;
    }
};

// ================= АКТУАТОРЫ =================

class Heater : public Actuator {
public:
    void power() const override {
        if (is_on)
            cout << "Heater ON" << endl;
        else
            cout << "Heater OFF" << endl;
    }
};

class Fan : public Actuator {
public:
    void power() const override {
        if (is_on)
            cout << "Fan ON" << endl;
        else
            cout << "Fan OFF" << endl;
    }
};

class Lamp : public Actuator {
public:
    void power() const override {
        if (is_on)
            cout << "Lamp ON" << endl;
        else
            cout << "Lamp OFF" << endl;
    }
};

class Pump : public Actuator {
public:
    void power() const override {
        if (is_on)
            cout << "Pump ON" << endl;
        else
            cout << "Pump OFF" << endl;
    }
};

// ================= ЧАСЫ =================

class Clock {
private:
    int hour;

public:
    Clock() : hour(12) {}

    void update() {
        hour++;

        if (hour >= 24)
            hour = 0;
    }

    int get_hour() const {
        return hour;
    }

    bool is_night() const {
        return (hour >= 22 || hour < 6);
    }

    void show() const {
        cout << "Hour: "
            << hour
            << ":00" << endl;
    }
};

// ================= АЛГОРИТМЫ =================

// Контроль температуры
void control_temperature(
    const Thermometer& thermometer,
    Heater& heater,
    Fan& fan)
{
    float temp = thermometer.get_temperature();

    if (temp > 35) {
        heater.off();
        fan.on();
    }
    else if (temp < 20) {
        heater.on();
        fan.on();
    }
    else {
        heater.off();
        fan.off();
    }
}

// Контроль влажности почвы
void control_soil_humidity(
    const SoilHumiditySensor& soil,
    Pump& pump)
{
    float hum = soil.get_soil_humidity();

    if (hum < 70) {
        pump.on();
    }
    else {
        pump.off();
    }
}

// Контроль освещения
void control_light(
    const LightSensor& light,
    const Clock& clock,
    Lamp& lamp)
{
    if (clock.is_night()) {
        lamp.off();
        return;
    }

    float light_level =
        light.get_light_level();

    if (light_level < 3000) {
        lamp.on();
    }
    else {
        lamp.off();
    }
}

// ================= MAIN =================

int main()
{
    // Датчики
    Thermometer thermometer(1);
    Hygrometer hygrometer(2);
    SoilHumiditySensor soil_sensor(3);
    LightSensor light_sensor(4);

    // Актуаторы
    Heater heater;
    Fan fan;
    Lamp lamp;
    Pump pump;

    // Часы
    Clock clock;

    // Основной цикл
    for (int i = 0; i < 10; i++) {

        cout << "===================="
            << endl;

        // Обновление датчиков
        thermometer.update();
        hygrometer.update();
        soil_sensor.update();
        light_sensor.update();

        clock.update();

        // Вывод данных датчиков
        thermometer.show();
        hygrometer.show();
        soil_sensor.show();
        light_sensor.show();

        clock.show();

        cout << endl;

        // Алгоритмы управления
        control_temperature(
            thermometer,
            heater,
            fan);

        control_soil_humidity(
            soil_sensor,
            pump);

        control_light(
            light_sensor,
            clock,
            lamp);

        // Работа устройств
        heater.power();
        fan.power();
        pump.power();
        lamp.power();

        cout << endl;
    }

    return 0;
}
