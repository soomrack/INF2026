#include <Arduino.h>
#include <DHT.h>

const byte dht_model = DHT11;

const byte dht_pin = 8;
const byte soil_pin = A1;
const byte light_pin = A3;

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

using Celsius = float;
using Percent = int;
using Minutes = unsigned int;

struct SensorCalibration {
    int zero_raw;
    int hundred_raw;
};

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

// по умолчанию выращиваем помидоры
const ClimateSettings* current_climate = &tomato;

void set_climate(const ClimateSettings& climate) {
    current_climate = &climate;
}

Percent convert_raw_to_percent(int raw, int zero_raw, int hundred_raw) {
    if (zero_raw == hundred_raw) {
        return 0;
    }

    // zero_raw и hundred_raw могут быть в любом порядке
    long value = (long)(raw - zero_raw) * 100L;
    value = value / (hundred_raw - zero_raw);

    return (Percent)constrain(value, 0L, 100L);
}

byte get_hour() {
    // время виртуальное, после перезагрузки снова стартует с initial_hour
    byte passed_hours = (millis() % day_ms) / hour_ms;
    return (initial_hour + passed_hours) % 24;
}

Minutes get_minute_of_day() {
    unsigned long passed_minutes = (millis() % day_ms) / minute_ms;
    return (Minutes)((initial_hour * 60 + passed_minutes) % 1440);
}

bool is_night_now(const ClimateSettings& climate) {
    byte hour = get_hour();

    if (climate.night_start < climate.night_end) {
        return hour >= climate.night_start &&
               hour < climate.night_end;
    }

    // если ночь проходит через полночь, проверяем через или
    return hour >= climate.night_start ||
           hour < climate.night_end;
}

bool ventilation_time_has_come(const ClimateSettings& climate) {
    if (climate.ventilation_period == 0 ||
        climate.ventilation_duration == 0) {
        return false;
    }

    return get_minute_of_day() % climate.ventilation_period <
           climate.ventilation_duration;
}

class AirSensor {
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

    void begin() {
        dht.begin();
    }

    void update() {
        unsigned long now = millis();

        if (was_read && now - last_read < air_sensor_interval) {
            return;
        }

        was_read = true;
        last_read = now;

        float humidity = dht.readHumidity();
        float temperature = dht.readTemperature();

        // при ошибке DHT возвращает NaN, поэтмоу оставляем прошлое нормальное значение
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

class AnalogSensor {
private:
    byte pin;
    int raw_value;
    Percent percent_value;
    SensorCalibration calibration;

public:
    AnalogSensor(byte sensor_pin, SensorCalibration sensor_calibration)
        : pin(sensor_pin),
          raw_value(0),
          percent_value(0),
          calibration(sensor_calibration) {}

    void begin() {
        pinMode(pin, INPUT);
    }

    void update() {
        raw_value = analogRead(pin);

        percent_value = convert_raw_to_percent(
            raw_value,
            calibration.zero_raw,
            calibration.hundred_raw
        );
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
    bool turns_on_with_high_signal;
    bool turn_on_request;

public:
    Actuator(byte actuator_pin, bool is_turned_on_by_high_signal = true)
        : pin(actuator_pin),
          turns_on_with_high_signal(is_turned_on_by_high_signal),
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
        // применяем после всех регуляторов, потому что один актуатор может быть нужен разным функциям
        bool pin_is_high = turns_on_with_high_signal == turn_on_request;
        digitalWrite(pin, pin_is_high ? HIGH : LOW);
    }
};

AirSensor air(dht_pin);

AnalogSensor soil(
    soil_pin,
    {
        .zero_raw = 0,
        .hundred_raw = 1023
    }
);

// у датчика света больше raw значит меньше света
AnalogSensor light(
    light_pin,
    {
        .zero_raw = 1023,
        .hundred_raw = 0
    }
);

Actuator pump(pump_pin);
Actuator fan(fan_pin);
Actuator heater(heater_pin);
Actuator lamp(lamp_pin);

void begin_sensors() {
    air.begin();
    soil.begin();
    light.begin();
}

void begin_actuators() {
    pump.begin();
    fan.begin();
    heater.begin();
    lamp.begin();
}

void read_sensors(AirSensor& air_sensor,
                  AnalogSensor& soil_sensor,
                  AnalogSensor& light_sensor) {
    air_sensor.update();
    soil_sensor.update();
    light_sensor.update();
}

void clear_actuator_requests(Actuator& pump_actuator,
                             Actuator& fan_actuator,
                             Actuator& heater_actuator,
                             Actuator& lamp_actuator) {
    // каждый регулятор заново просит включить нужные актуаторы
    pump_actuator.reset();
    fan_actuator.reset();
    heater_actuator.reset();
    lamp_actuator.reset();
}

bool is_light_low(const AnalogSensor& light_sensor,
                  const ClimateSettings& climate) {
    return light_sensor.percent_reading() < climate.min_light;
}

bool is_soil_dry(const AnalogSensor& soil_sensor,
                 const ClimateSettings& climate) {
    return soil_sensor.percent_reading() < climate.min_soil_humidity;
}

bool is_temperature_high(const AirSensor& air_sensor,
                         const ClimateSettings& climate) {
    return air_sensor.has_temperature() &&
           air_sensor.temperature() > climate.max_temp;
}

bool is_temperature_low(const AirSensor& air_sensor,
                        const ClimateSettings& climate) {
    return air_sensor.has_temperature() &&
           air_sensor.temperature() < climate.min_temp;
}

bool is_humidity_high(const AirSensor& air_sensor,
                      const ClimateSettings& climate) {
    return air_sensor.has_humidity() &&
           air_sensor.humidity() > climate.max_air_humidity;
}

void update_light_request(const AnalogSensor& light_sensor,
                          Actuator& lamp_actuator,
                          const ClimateSettings& climate) {
    if (!is_night_now(climate) &&
        is_light_low(light_sensor, climate)) {
        lamp_actuator.on();
    }
}

void update_watering_request(const AnalogSensor& soil_sensor,
                             Actuator& pump_actuator,
                             const ClimateSettings& climate) {
    static bool watering = false;
    static bool waiting = false;

    static unsigned long watering_start = 0;
    static unsigned long pause_start = 0;

    unsigned long now = millis();

    if (!is_soil_dry(soil_sensor, climate)) {
        watering = false;
        waiting = false;
        return;
    }

    if (watering) {
        // поливаем импульсами, чтобы вода успевала впитываться
        if (now - watering_start < pump_work_time) {
            pump_actuator.on();
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
    pump_actuator.on();
}

void update_temperature_request(const AirSensor& air_sensor,
                                Actuator& heater_actuator,
                                Actuator& fan_actuator,
                                const ClimateSettings& climate) {
    if (is_temperature_high(air_sensor, climate)) {
        fan_actuator.on();
        return;
    }

    if (is_temperature_low(air_sensor, climate)) {
        // вентилятор помогает распределять теплый воздух
        heater_actuator.on();
        fan_actuator.on();
    }
}

void update_ventilation_request(const AirSensor& air_sensor,
                                Actuator& fan_actuator,
                                const ClimateSettings& climate) {
    // вся вентиляция тут: по влажности и по расписание
    if (is_humidity_high(air_sensor, climate) ||
        (!is_night_now(climate) &&
         ventilation_time_has_come(climate))) {
        fan_actuator.on();
    }
}

void print_general_status() {
    Serial.print(F("Climate: "));
    Serial.println(current_climate->name);

    Serial.print(F("Hour: "));
    Serial.println(get_hour());

    Serial.print(F("Night: "));
    Serial.println(is_night_now(*current_climate) ? F("true") : F("false"));
}

void print_air_status() {
    Serial.print(F("Temperature: "));
    if (air.has_temperature()) {
        Serial.print(air.temperature());
        Serial.println(F(" C"));
    } else {
        Serial.println(F("N/A"));
    }

    Serial.print(F("Air humidity: "));
    if (air.has_humidity()) {
        Serial.print(air.humidity());
        Serial.println(F(" %"));
    } else {
        Serial.println(F("N/A"));
    }
}

void print_soil_status() {
    Serial.print(F("Soil humidity: "));
    Serial.print(soil.percent_reading());
    Serial.print(F(" %, raw = "));
    Serial.println(soil.raw());
}

void print_light_status() {
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

    print_general_status();
    print_air_status();
    print_soil_status();
    print_light_status();
    print_actuators_status();

    Serial.println();
}

void setup() {
    Serial.begin(9600);

    set_climate(tomato);

    begin_sensors();
    begin_actuators();

    Serial.println(F("Greenhouse controller started"));
}

void loop() {
    read_sensors(air, soil, light);
    clear_actuator_requests(pump, fan, heater, lamp);

    update_light_request(light, lamp, *current_climate);
    update_watering_request(soil, pump, *current_climate);
    update_temperature_request(air, heater, fan, *current_climate);
    update_ventilation_request(air, fan, *current_climate);

    pump.apply();
    fan.apply();
    heater.apply();
    lamp.apply();

    print_status();

    delay(100);
}
