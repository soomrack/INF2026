#include <Arduino.h>
#include <DHT.h>

const byte dht_model = DHT11;

const byte dht_pin = 2;
const byte soil_pin = A1;
const byte light_pin = A0;

const byte pump_pin = 5;
const byte fan_pin = 7;
const byte heater_pin = 4;
const byte lamp_pin = 6;

const unsigned long air_sensor_interval = 2000UL;
const unsigned long print_interval = 5000UL;

const unsigned long pump_work_time = 3000UL;
const unsigned long pump_pause_time = 10000UL;

const unsigned long minute_ms = 60000UL;
const unsigned long hour_ms = 3600000UL;
const unsigned long day_ms = 86400000UL;

const byte initial_hour = 12;

// Границы калибровки нужно определить под конкретную теплицу и конкретный датчик
const int soil_dry_raw = 0;
const int soil_wet_raw = 1023;

const int light_dark_raw = 1023;
const int light_bright_raw = 0;

using Celsius = float;
using Percent = int;
using Minutes = unsigned int;

struct ClimateSettings {
    const char* name;

    Celsius min_temp;
    Celsius max_temp;

    Percent max_air_humidity;
    Percent min_soil_humidity;
    Percent min_light;

    byte night_start;
    byte night_end;

    Minutes ventilation_period;
    Minutes ventilation_duration;
};

const ClimateSettings tomato = {
    .name = "Tomato",

    .min_temp = 22.0,
    .max_temp = 28.0,

    .max_air_humidity = 70,
    .min_soil_humidity = 35,
    .min_light = 50,

    .night_start = 22,
    .night_end = 6,

    .ventilation_period = 180,
    .ventilation_duration = 5
};

const ClimateSettings cucumber = {
    .name = "Cucumber",

    .min_temp = 23.0,
    .max_temp = 30.0,

    .max_air_humidity = 80,
    .min_soil_humidity = 45,
    .min_light = 45,

    .night_start = 22,
    .night_end = 6,

    .ventilation_period = 180,
    .ventilation_duration = 5
};

const ClimateSettings* current_climate = &tomato; // По умолчанию выращиваем помидоры, чтобы ошибки не было или других неожиданностей

void set_climate(const ClimateSettings& climate) {
    current_climate = &climate;
}

void set_climate(const ClimateSettings* climate) {
    current_climate = climate;
}

Percent convert_raw_to_percent(int raw, int zero_raw, int hundred_raw) {
    if (zero_raw == hundred_raw) {
        return 0;
    }

    // zero_raw и hundred_raw могут идти в обратном порядке
    long value = (long)(raw - zero_raw) * 100L;
    value = value / (hundred_raw - zero_raw);

    return (Percent)constrain(value, 0L, 100L);
}

// Время виртуальное, поэтому после перезагрузки снова стартует с initial_hour
byte get_hour() {
    byte passed_hours = (millis() % day_ms) / hour_ms;
    return (initial_hour + passed_hours) % 24;
}

Minutes get_minute_of_day() {
    unsigned long passed_minutes = (millis() % day_ms) / minute_ms;
    return (Minutes)((initial_hour * 60 + passed_minutes) % 1440);
}

bool is_night_now() {
    byte hour = get_hour();

    // Для ночи через полночь нужна отдельная проверка
    if (current_climate->night_start < current_climate->night_end) {
        return hour >= current_climate->night_start &&
               hour < current_climate->night_end;
    }

    return hour >= current_climate->night_start ||
           hour < current_climate->night_end;
}

bool ventilation_time_has_come() {
    Minutes period = current_climate->ventilation_period;
    Minutes duration = current_climate->ventilation_duration;

    if (period == 0 || duration == 0) {
        return false;
    }

    return get_minute_of_day() % period < duration;
}

class Sensor {
public:
    virtual void begin() = 0;
    virtual void update() = 0;
};

class AirSensor : public Sensor {
private:
    DHT dht;

    float temperature_value;
    float humidity_value;

    bool temperature_ready;
    bool humidity_ready;

    bool was_read;
    unsigned long last_read;

public:
    AirSensor(byte pin)
        : dht(pin, dht_model),
          temperature_value(0),
          humidity_value(0),
          temperature_ready(false),
          humidity_ready(false),
          was_read(false),
          last_read(0) {}

    void begin() override {
        dht.begin();
    }

    void update() override {
        unsigned long now = millis();

        if (was_read && now - last_read < air_sensor_interval) {
            return;
        }

        was_read = true;
        last_read = now;

        float humidity = dht.readHumidity();
        float temperature = dht.readTemperature();

        // При ошибке DHT возвращает NaN
        if (!isnan(humidity)) {
            humidity_value = humidity;
            humidity_ready = true;
        }

        if (!isnan(temperature)) {
            temperature_value = temperature;
            temperature_ready = true;
        }
    }

    bool has_temperature() const {
        return temperature_ready;
    }

    bool has_humidity() const {
        return humidity_ready;
    }

    float temperature() const {
        return temperature_value;
    }

    float humidity() const {
        return humidity_value;
    }
};

class AnalogSensor : public Sensor {
private:
    byte pin;
    int raw_value;
    Percent percent_value;

    int zero_raw;
    int hundred_raw;

public:
    AnalogSensor(byte sensor_pin, int zero_value, int hundred_value)
        : pin(sensor_pin),
          raw_value(0),
          percent_value(0),
          zero_raw(zero_value),
          hundred_raw(hundred_value) {}

    void begin() override {
        pinMode(pin, INPUT);
    }

    void update() override {
        raw_value = analogRead(pin);
        percent_value = convert_raw_to_percent(raw_value, zero_raw, hundred_raw);
    }

    Percent percent_reading() const {
        return percent_value;
    }

    int raw() const {
        return raw_value;
    }
};

class Actuator {
private:
    byte pin;
    bool active_high;
    bool turn_on_request;

public:
    Actuator(byte actuator_pin, bool is_active_high = true)
        : pin(actuator_pin),
          active_high(is_active_high),
          turn_on_request(false) {}

    void begin() {
        pinMode(pin, OUTPUT);
        off();
        apply();
    }

    void reset() {
        turn_on_request = false;
    }

    void on() {
        turn_on_request = true;
    }

    void off() {
        turn_on_request = false;
    }

    bool is_on() const {
        return turn_on_request;
    }

    void apply() {
        bool pin_is_high = active_high == turn_on_request;
        digitalWrite(pin, pin_is_high ? HIGH : LOW);
    }
};

AirSensor air(dht_pin);

AnalogSensor soil(soil_pin, soil_dry_raw, soil_wet_raw);
AnalogSensor light(light_pin, light_dark_raw, light_bright_raw);

Actuator pump(pump_pin);
Actuator fan(fan_pin);
Actuator heater(heater_pin);
Actuator lamp(lamp_pin);

Sensor* sensors[] = {
    &air,
    &soil,
    &light
};

Actuator* actuators[] = {
    &pump,
    &fan,
    &heater,
    &lamp
};

const byte sensor_count = sizeof(sensors) / sizeof(sensors[0]);
const byte actuator_count = sizeof(actuators) / sizeof(actuators[0]);

void begin_sensors() {
    for (byte i = 0; i < sensor_count; i++) {
        sensors[i]->begin();
    }
}

void begin_actuators() {
    for (byte i = 0; i < actuator_count; i++) {
        actuators[i]->begin();
    }
}

void update_sensors() {
    for (byte i = 0; i < sensor_count; i++) {
        sensors[i]->update();
    }
}

void reset_actuators() {
    // Регуляторы заново выставляют запросы каждый цикл
    for (byte i = 0; i < actuator_count; i++) {
        actuators[i]->reset();
    }
}

void apply_actuators() {
    for (byte i = 0; i < actuator_count; i++) {
        actuators[i]->apply();
    }
}

bool is_light_low() {
    return light.percent_reading() < current_climate->min_light;
}

bool is_soil_dry() {
    return soil.percent_reading() < current_climate->min_soil_humidity;
}

bool is_temperature_high() {
    return air.has_temperature() &&
           air.temperature() > current_climate->max_temp;
}

bool is_temperature_low() {
    return air.has_temperature() &&
           air.temperature() < current_climate->min_temp;
}

bool is_humidity_high() {
    return air.has_humidity() &&
           air.humidity() > current_climate->max_air_humidity;
}

bool can_ventilate_now() {
    return !is_night_now() &&
           !heater.is_on() &&
           !is_temperature_low();
}

void control_light() {
    if (!is_night_now() && is_light_low()) {
        lamp.on();
    }
}

void control_watering() {
    static bool watering = false;
    static bool waiting = false;

    static unsigned long watering_start = 0;
    static unsigned long pause_start = 0;

    unsigned long now = millis();

    if (!is_soil_dry()) {
        watering = false;
        waiting = false;
        return;
    }

    if (watering) {
        // Полив идет импульсами, чтобы вода успевала впитываться
        if (now - watering_start < pump_work_time) {
            pump.on();
        } else {
            watering = false;
            waiting = true;
            pause_start = now;
        }

        return;
    }

    if (waiting) {
        if (now - pause_start < pump_pause_time) {
            return;
        }

        waiting = false;
    }

    watering = true;
    watering_start = now;
    pump.on();
}

void control_temperature() {
    if (is_temperature_high()) {
        fan.on();
        return;
    }

    // При нагреве вентилятор помогает распределять теплый воздух
    if (is_temperature_low()) {
        heater.on();
        fan.on();
    }
}

void control_humidity() {
    if (is_humidity_high() && !heater.is_on()) {
        fan.on();
    }
}

void control_ventilation() {
    // Плановое проветривание не включается во время нагрева
    if (can_ventilate_now() && ventilation_time_has_come()) {
        fan.on();
    }
}

void print_climate_status(){
    Serial.print(F("Climate: "));
    Serial.println(current_climate->name);

    Serial.print(F("Hour: "));
    Serial.println(get_hour());

    Serial.print(F("Night: "));
    Serial.println(is_night_now() ? F("true") : F("false"));

    Serial.print(F("Temperature: "));
    if (air.has_temperature()) {
        Serial.print(air.temperature());
        Serial.println(F(" C"));
    } else {
        Serial.println(F("N/A"));
    }
}

void print_air_status(){
    Serial.print(F("Air humidity: "));
    if (air.has_humidity()) {
        Serial.print(air.humidity());
        Serial.println(F(" %"));
    } else {
        Serial.println(F("N/A"));
    }
}

void print_soil_status(){
    Serial.print(F("Soil humidity: "));
    Serial.print(soil.percent_reading());
    Serial.print(F(" %, raw = "));
    Serial.println(soil.raw());
}

void print_light_status(){
    Serial.print(F("Light: "));
    Serial.print(light.percent_reading());
    Serial.print(F(" %, raw = "));
    Serial.println(light.raw());
}

void print_actuators_status() {
    Serial.print(F("Pump: "));
    Serial.println(pump.is_on() ? F("ON") : F("OFF"));

    Serial.print(F("Fan: "));
    Serial.println(fan.is_on() ? F("ON") : F("OFF"));

    Serial.print(F("Heater: "));
    Serial.println(heater.is_on() ? F("ON") : F("OFF"));

    Serial.print(F("Lamp: "));
    Serial.println(lamp.is_on() ? F("ON") : F("OFF"));
}

void print_status() {
    static unsigned long last_print = 0;

    if (millis() - last_print < print_interval) {
        return;
    }

    last_print = millis();

    print_climate_status();
    print_air_status();
    print_soil_status();
    print_light_status();
    print_actuators_status();

    Serial.println();
}

void setup() {
    Serial.begin(9600);

    set_climate(&tomato);

    begin_sensors();
    begin_actuators();

    Serial.println(F("Greenhouse controller started"));
}

void loop() {
    update_sensors();

    reset_actuators();

    control_light();
    control_watering();
    control_temperature();
    control_humidity();
    control_ventilation();

    apply_actuators();

    print_status();

    delay(100);
}
