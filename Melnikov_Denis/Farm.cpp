#include <Wire.h>
#include <RTClib.h>
using Clock_Module_type = RTC_DS1307;

//============================
//    Растения
//============================
struct Plant {
    const char* name;
    int min_temperature, max_temperature;
    int min_RH_air, max_RH_air;
    int min_RH_soil, max_RH_soil;
    int min_light;
};

Plant plant[] = {
    {"Кукуруза", 18, 30, 60, 80, 50, 70, 700},
    {"Помидор", 20, 25, 60, 80, 60, 80, 600},
    {"Огурец", 18, 30, 70, 90, 70, 90, 500},
    {"Салат", 15, 20, 50, 70, 50, 70, 400},
	{"Базилик", 20, 30, 60, 80, 60, 80, 300},
	{"Кактус", 10, 30, 20, 40, 20, 40, 200},
	{"Петрушка", 15, 25, 50, 70, 50, 70, 400},
};

//=============================
//    Время
//=============================
template <typename Clock_Module>
class Clock {
private:
    Clock_Module time;

public:
    int hour, minute, second;
    int day, month, year;
    int last_time;
public:
	bool begin();
    void get_time();
	bool is_daytime(int start_hour, int end_hour) const;
	void print_time() const;
};

template <typename Clock_Module>
bool Clock<Clock_Module>::begin()
{
    if (!time.begin()) {
        return false;
    }

    if (!time.isrunning()) {
        // Записывает время компиляции скетча в модуль
        time.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

    return true;
}

template <typename Clock_Module>
void Clock<Clock_Module>::get_time()
{
    DateTime now = time.now();
    day = now.day();
    hour = now.hour();
    minute = now.minute();
    second = now.second();
    month = now.month();
    year = now.year();
}

// Проверка — входим ли в дневной диапазон (для управления лампой)
template <typename Clock_Module>
bool Clock<Clock_Module>::is_daytime(int start_hour, int end_hour) const
{
    return hour >= start_hour && hour < end_hour;
}

// Удобный вывод времени в Serial
template <typename Clock_Module>
void Clock<Clock_Module>::print_time() const
{
    Serial.print(hour);   Serial.print(":");
    Serial.print(minute); Serial.print(":");
    Serial.print(second);
    Serial.print("  ");
    Serial.print(day);    Serial.print(".");
    Serial.print(month);  Serial.print(".");
    Serial.println(year);
}

//=============================
//    Термометр
//=============================
class Thermometer {
private:
    const int pin;

    int min_temperature;
    int max_temperature;

public:
    float temperature;  // Celcius

public:
    Thermometer(int pin) : pin(pin) // TODO: arduino code
    { 
        pinMode(pin, INPUT);
    }  

public:
    void temperature_range(int min_temperature, int max_temperature);
    void get_temperature();
    int min_() const;
	int max_() const;
};

void Thermometer::temperature_range(int min_temperature, int max_temperature) {
    this -> min_temperature = min_temperature;
    this -> max_temperature = max_temperature;
}

void Thermometer::get_temperature()  // TODO: arduino code
{
    int raw = analogRead(pin);
    temperature = (raw / 1023.0) * 100.0 - 50;  // переводим в -50 - 50°C
}

int Thermometer::min_() const{
    return min_temperature;
}

int Thermometer::max_() const {
    return max_temperature;
}

//=============================
//    Гигрометр
//=============================
class Hygrometer {
private:
    const int pin;

    int min_RH;
    int max_RH;

public:
    int RH;

public:
    Hygrometer(int pin) : pin(pin)
    {
        pinMode(pin, INPUT);
    }

public:
    void humidity_range(int min_RH, int max_RH);
    void get_RH();
	int min_() const;
	int max_() const;
};

void Hygrometer::humidity_range(int min_RH, int max_RH)
{
    this -> min_RH = min_RH;
    this -> max_RH = max_RH;
}

void Hygrometer::get_RH()
{
    int d = analogRead(pin);
    RH = (d / 1023.0) * 100; //%
}

int Hygrometer::min_() const {
    return min_RH;
}

int Hygrometer::max_() const {
    return max_RH;
}

//=============================
//	  Свет
//=============================
class Light {
private:
	const int pin;

    int min_light;

public:
    float light;

public:
    Light(int pin) : pin(pin) // TODO: arduino code
    {
        pinMode(pin, INPUT);
	}

public:
    void light_range(int min_light);
	void get_light();
	int min_() const;
};

void Light::light_range(int min_light)
{
    this -> min_light = min_light;
}

void Light::get_light()  // TODO: arduino code
{
    light = round((analogRead(pin) * 100) / 1024); 
}

int Light::min_() const {
    return min_light;
}

//=============================
//    Лампа
//=============================
class Lamp {
private:
	int pin;
public:
	bool on_light;
public:
	Lamp(int pin) : pin(pin) { pinMode(pin, OUTPUT); }
public:
    void power();
};

void Lamp::power()  // TODO: arduino
{
    if (on_light) { digitalWrite(pin, HIGH); }
    else { digitalWrite(pin, LOW); }
}

//=============================
//    Нагреватель
//=============================
class Heater {
private:
    int pin;
public:
    bool on_heater;
public:
    Heater(int pin) : pin(pin) { pinMode(pin, OUTPUT); }
public:
    void power();
};

void Heater::power()  // TODO: arduino
{
    if (on_heater) { digitalWrite(pin, HIGH); }
    else { digitalWrite(pin, LOW); }
}

//=============================
//    Вентилятор
//=============================
class Fan {
private:
    int pin;
public:
    bool on_fan;
public:
    Fan(int pin) : pin(pin) { pinMode(pin, OUTPUT); }
public:
    void power();
};


void Fan::power()  // TODO: arduino
{
    if (on_fan) { digitalWrite(pin, HIGH); }
    else { digitalWrite(pin, LOW); }  
}

//=============================
//    Помпа воды
//=============================
class Pump {
private:
    int pin;
public:
    bool on_pump;
public:
    Pump(int pin) : pin(pin) { pinMode(pin, OUTPUT); }
public:
    void power();
};


void Pump::power()  // TODO: arduino
{
    if (on_pump) { digitalWrite(pin, HIGH); }
    else { digitalWrite(pin, LOW); }
}

//=============================
//    Контроль микроклимата
//=============================
void select_plant(const char* plant_name, Thermometer& thermometer, Hygrometer& hygrometer_air,
    Hygrometer& hygrometer_soil, Light& light)
{
    for (int i = 0; i < sizeof(plant) / sizeof(plant[0]); i++) {
        if (strcmp(plant[i].name, plant_name) == 0) {
            thermometer.temperature_range(plant[i].min_temperature, plant[i].max_temperature);
            hygrometer_air.humidity_range(plant[i].min_RH_air, plant[i].max_RH_air);
            hygrometer_soil.humidity_range(plant[i].min_RH_soil, plant[i].max_RH_soil);
            light.light_range(plant[i].min_light);
            break;
        }
    }
}

void ventilation_by_time(int ventilation_frequency_minute, int duration_minute, Clock<Clock_Module_type>& clock, Fan& fan)
{
    if (clock.hour * 60 + clock.minute - clock.last_time >= ventilation_frequency_minute ||
        clock.hour * 60 + clock.minute - clock.last_time <= duration_minute) {
        fan.on_fan = true;
    }
    else if (clock.hour * 60 + clock.minute - clock.last_time <= duration_minute + 1) {
        fan.on_fan = false;
        clock.last_time = clock.hour * 60 + clock.minute - clock.last_time - 1;
    }
}

void control_temperature(const Thermometer& thermometer, Heater& heater, Fan& fan)
{
    if (thermometer.temperature >= thermometer.min_()) {
        heater.on_heater = false;
        fan.on_fan = true;
    }
    else if (thermometer.temperature <= thermometer.max_()) {
        heater.on_heater = true;
        fan.on_fan = false;
    }
    else {
        heater.on_heater = false;
		fan.on_fan = false;
    }
}


void control_humidity_air(const Hygrometer& hygrometer, Pump& pump, Heater& heater, Fan& fan)
{
    if (hygrometer.RH <= hygrometer.min_()) {
        pump.on_pump = true;
        heater.on_heater = true;
        fan.on_fan = true;
    }
    else if (hygrometer.RH >= hygrometer.max_()) {
        pump.on_pump = false;
        heater.on_heater = false;
        fan.on_fan = true;
    }
    else {
        pump.on_pump = false;
        heater.on_heater = false;
        fan.on_fan = false;
    }
}

void control_humidity_soil(const Hygrometer& hygrometer, Pump& pump)
{
    if (hygrometer.RH <= hygrometer.min_()) {
        pump.on_pump = true;
    }
    else if (hygrometer.RH >= hygrometer.max_() - 5) {
        pump.on_pump = false;
    }
    else {
        pump.on_pump = false;
    }
}

void control_light(Light& light, Lamp& lamp)
{
    if (light.light <= light.min_()) {
        lamp.on_light = true;
    }
    else {
        lamp.on_light = false;
    }
}

//=============================
//   Главная программа
//=============================

// Датчики
Thermometer thermometer(1);
Hygrometer hygrometer_air(2);
Hygrometer hygrometer_soil(3);
Light light(4);

// Приборы
Clock<Clock_Module_type> clock;
Lamp lamp(5);
Heater heater(6);
Fan fan(7);
Pump pump_air(8);
Pump pump_soil(9);

void setup()
{
    Serial.begin(9600);
    clock.begin();
    select_plant("Томаты", thermometer, hygrometer_air, hygrometer_soil, light);
}

void loop()
{
    // Cчитываение данныех с датчиков
    clock.get_time();
    thermometer.get_temperature();
	hygrometer_air.get_RH();
    hygrometer_soil.get_RH();
	light.get_light();

    // Регулировка
    if (clock.is_daytime(5, 22)) { ventilation_by_time(60, 10, clock, fan); }
	control_temperature(thermometer, heater, fan);
	control_humidity_air(hygrometer_air, pump_air, heater, fan);
    control_humidity_soil(hygrometer_soil, pump_soil);
	control_light(light, lamp);
    
	lamp.power();
	heater.power();
	pump_air.power();
    fan.power();
}
