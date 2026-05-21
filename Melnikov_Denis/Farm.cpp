#include <Wire.h>
#include <RTClib.h>
using Clock_Module_type = RTC_DS1307;

//============================
//    Климат
//============================
//  Имя             t_min  t_max  rh_air_min  rh_air_max  rh_soil_min  rh_soil_max  lux
#define CLIMATES \
    X(JUNGLE,         22,  35,  75,  95,  70,  90,  30) \
    X(DESERT,         20,  45,  10,  30,  10,  25,  80) \
    X(SAVANNA,        18,  40,  25,  50,  15,  35,  70) \
    X(STEPPE,         15,  35,  30,  55,  20,  40,  60) \
    X(MEDITERRANEAN,  10,  30,  40,  65,  30,  55,  55) \
    X(TEMPERATE,       5,  25,  60,  80,  50,  70,  40) \
    X(TAIGA,           0,  20,  70,  90,  60,  80,  20) \
    X(TUNDRA,        -10,  10,  70,  85,  50,  70,  15) \
    X(ARCTIC,        -30,   0,  80,  95,  70,  85,  10)

#define X(name, ...) name,
enum Climate { CLIMATES CLIMATE_COUNT };
#undef X

#define X(name, t_min, t_max, rh_air_min, rh_air_max, rh_soil_min, rh_soil_max, lux) \
    { t_min, t_max, rh_air_min, rh_air_max, rh_soil_min, rh_soil_max, lux },
const int climates[CLIMATE_COUNT][7] = { CLIMATES };
#undef X

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
    int last_time = 0;
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
    Thermometer(int pin) : pin(pin), min_temperature(20), max_temperature(26) // TODO: arduino code
    {
        pinMode(pin, INPUT);
    }

public:
    void temperature_range(int min_temperature, int max_temperature);
    void get_temperature();
    void print_temperature();
    int min_temp() const;
    int max_temp() const;
};

void Thermometer::temperature_range(int min_temperature, int max_temperature) {
    this->min_temperature = min_temperature;
    this->max_temperature = max_temperature;
}

void Thermometer::get_temperature()  // TODO: arduino code
{
    int raw = analogRead(pin);
    temperature = (raw / 1023.0) * 100.0 - 50;  // переводим в -50 - 50°C
}

void Thermometer::print_temperature()
{
    Serial.println(temperature);
}

int Thermometer::min_temp() const {
    return min_temperature;
}

int Thermometer::max_temp() const {
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
    Hygrometer(int pin) : pin(pin), min_RH(40), max_RH(60)
    {
        pinMode(pin, INPUT);
    }

public:
    void humidity_range(int min_RH, int max_RH);
    void get_RH();
    void print_RH();
    int min_humidity() const;
    int max_humidity() const;
};

void Hygrometer::humidity_range(int min_RH, int max_RH)
{
    this->min_RH = min_RH;
    this->max_RH = max_RH;
}

void Hygrometer::get_RH()
{
    int d = analogRead(pin);
    RH = (d / 1023.0) * 100; //%
}

void Hygrometer::print_RH()
{
    Serial.println(RH);
}

int Hygrometer::min_humidity() const {
    return min_RH;
}

int Hygrometer::max_humidity() const {
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
    Light(int pin) : pin(pin), light(30) // TODO: arduino code
    {
        pinMode(pin, INPUT);
    }

public:
    void light_range(int min_light);
    void get_light();
    void print_light();
    int min_lights() const;
};

void Light::light_range(int min_light)
{
    this->min_light = min_light;
}

void Light::get_light()  // TODO: arduino code
{
    light = round((analogRead(pin) * 100) / 1024);
}

void Light::print_light()
{
    Serial.println(light);
}

int Light::min_lights() const {
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
    bool on_fan_ventilation;
    bool on_fan_temperature;
public:
    Fan(int pin) : pin(pin) { pinMode(pin, OUTPUT); }
public:
    void power();
};


void Fan::power()  // TODO: arduino
{
    if (on_fan_ventilation || on_fan_temperature) { digitalWrite(pin, HIGH); }
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
void select_climate(Climate c, Thermometer& t, Hygrometer& ha, Hygrometer& hs, Light& l) {
    if (c >= CLIMATE_COUNT) return;
    t.temperature_range(climates[c][0], climates[c][1]);
    ha.humidity_range  (climates[c][2], climates[c][3]);
    hs.humidity_range  (climates[c][4], climates[c][5]);
    l.light_range      (climates[c][6]);
}

const int VENTILATION_EVERY_MINUTE    = 60;
const int VENTILATION_DURATION_MINUTE = 10;
const int DAY_START_HOUR              = 6;
const int DAY_END_HOUR                = 22;

void control_ventilation(Clock<Clock_Module_type>& clock, Fan& fan)
{
    if (!clock.is_daytime(DAY_START_HOUR, DAY_END_HOUR)) {
        fan.on_fan_ventilation = false;
        clock.last_time = clock.hour * 60 + clock.minute;
        return;
    }

    int now     = clock.hour * 60 + clock.minute;
    int elapsed = now - clock.last_time;
    if (elapsed < 0) elapsed += 24 * 60;  // защита от перехода через полночь

    if (elapsed >= VENTILATION_EVERY_MINUTE) {
        // Пора проветривать — запускаем и сбрасываем таймер
        fan.on_fan_ventilation = true;
        clock.last_time = now;
    }
    else if (fan.on_fan_ventilation && elapsed >= VENTILATION_DURATION_MINUTE) {
        // Проветривание закончилось
        fan.on_fan_ventilation = false;
    }
}

void control_temperature(const Thermometer& thermometer, Heater& heater, Fan& fan)
{
    if (thermometer.temperature <= thermometer.min_temp()) {
        heater.on_heater = true;
        fan.on_fan_temperature = true;
    }
    else if (thermometer.temperature >= thermometer.max_temp()) {
        heater.on_heater = false;
        fan.on_fan_temperature = true;
    }
    else {
        heater.on_heater = false;
        fan.on_fan_temperature = false;
    }
}


void control_humidity_air(const Hygrometer& hygrometer, Pump& pump)
{
    if (hygrometer.RH <= hygrometer.min_humidity()) {
        pump.on_pump = true;
    }
    else if (hygrometer.RH >= hygrometer.max_humidity()) {
        pump.on_pump = false;
    }
    else {
        pump.on_pump = false;
    }
}

void control_humidity_soil(const Hygrometer& hygrometer, Pump& pump)
{
    if (hygrometer.RH <= hygrometer.min_humidity()) {
        pump.on_pump = true;
    }
    else if (hygrometer.RH >= hygrometer.max_humidity() - 5) {
        pump.on_pump = false;
    }
    else {
        pump.on_pump = false;
    }
}

void control_light(Light& light, Lamp& lamp)
{
    if (light.light <= light.min_lights()) {
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
Clock<Clock_Module_type> farm_clock;
Thermometer thermometer(A1);
Hygrometer hygrometer_air(A2);
Hygrometer hygrometer_soil(A4);
Light light(A3);

// Актуаторы
Lamp lamp(6);
Heater heater(4);
Fan fan(7);
Pump pump_air(8);
Pump pump_soil(5);

void setup()
{
    Serial.begin(9600);
    farm_clock.begin();
    select_climate(JUNGLE,  thermometer, hygrometer_air, hygrometer_soil, light);
}

void loop()
{
    // Cчитываение данныех с датчиков
    farm_clock.get_time();
    thermometer.get_temperature();
    hygrometer_air.get_RH();
    hygrometer_soil.get_RH();
    light.get_light();

    //Вывод результатов считывания 
    farm_clock.print_time();
    thermometer.print_temperature();
    hygrometer_air.print_RH();
    hygrometer_soil.print_RH();
    light.print_light();

    // Регулировка
    control_temperature(thermometer, heater, fan);
    control_humidity_air(hygrometer_air, pump_air);
    control_humidity_soil(hygrometer_soil, pump_soil);
    control_light(light, lamp);
    control_ventilation(farm_clock, fan);

    lamp.power();
    heater.power();
    pump_air.power();
    pump_soil.power();
    fan.power();
}
