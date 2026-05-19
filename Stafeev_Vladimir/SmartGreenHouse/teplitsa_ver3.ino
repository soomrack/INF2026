// ============================================================================
// Smart Greenhouse Controller
// Board : Arduino Uno
// ============================================================================
//
//Pinout:
// D4 - Relay: Fan
// D5 - Relay: Lamp
// D6 - Relay: Pump
// D7 - Relay: Heater
// D8 - DHT11 (temperature + air humidity)
// A0 - Light sensor (lower = brighter)
// A1 - Soil watering sensor (lower value = wetter)
//
//Climate flags:
// too_hot - temperature above profile threshold
// too_cold - temperature below profile threshold
// too_humid - air humidity above threshold -> ventilation
// too_dry_air - air humidity below threshold (reserved for future use)
// too_dark - light level below threshold -> lamp on (daytime only)
// soil_dry - soil needs watering
// soil_wet - soil is saturated
//
//Rules (each returns bool - is actuator needed):
// rule_fan_hot: too_hot  -> fan on
// rule_heater: too_cold -> heater on
// rule_fan_humidity: too_humid -> fan on
// rule_fan_scheduled: inside vent window + interval elapsed -> fan on
// rule_lamp: too_dark AND daytime -> lamp on
//
//Actuator control in loop():
// fan ON when: too_hot | too_humid | too_cold | scheduled ventilation
// heater ON when: too_cold AND fan is on
// lamp ON when: too_dark AND daytime
// pump driven by state machine reacting to soil_dry / soil_wet flags

#include <DHT.h>


namespace Clock {
    // Returns current hour (0-23).
    // Simulation: 1 real minute = 1 simulated hour (full day = 24 min)
    int get_hour();
    bool is_daytime(int day_start_h = 6, int day_end_h = 22);
}


int Clock::get_hour() {
    return (int)((millis() / 60000UL) % 24);
}


bool Clock::is_daytime(int day_start_h, int day_end_h) {
    int h = get_hour();
    return h >= day_start_h && h < day_end_h;
}


struct ClimateProfile {
    const char* name;

    float temp_too_hot;
    float temp_too_cold;

    float humidity_too_high;
    float humidity_too_low;

    int light_too_dark;
    int light_bright;

    int soil_dry_threshold;
    int soil_wet_threshold;

    // Scheduled ventilation (daytime only)
    int vent_start_h;
    int vent_end_h;
    unsigned long vent_check_interval_ms; //re-ventilation
};


namespace Profile {

    const ClimateProfile tomatoes = {
        /*name*/ "Tomatoes",
        /*temp_too_hot*/ 28.0f,
        /*temp_too_cold*/ 18.0f,
        /*humidity_too_high*/ 80.0f,
        /*humidity_too_low*/ 40.0f,
        /*light_too_dark*/ 700,
        /*light_bright*/ 500,
        /*soil_dry_threshold*/ 800,
        /*soil_wet_threshold*/ 300,
        /*vent_start_h*/ 10,
        /*vent_end_h*/ 14,
        /*vent_check_interval_ms*/ 1800000UL   // every 30 min
    };

    const ClimateProfile cucumbers = {
        /*name*/ "Cucumbers",
        /*temp_too_hot*/ 32.0f,
        /*temp_too_cold*/ 22.0f,
        /*humidity_too_high*/ 90.0f,
        /*humidity_too_low*/ 50.0f,
        /*light_too_dark*/ 650,
        /*light_bright*/ 450,
        /*soil_dry_threshold*/ 700,
        /*soil_wet_threshold*/ 250,
        /*vent_start_h*/ 11,
        /*vent_end_h*/ 15,
        /*vent_check_interval_ms*/ 1200000UL   // every 20 min
    };

    const ClimateProfile TESTERS = {
        /*name*/ "TESTERS",
        /*temp_too_hot*/ 29.0f,
        /*temp_too_cold*/ 28.0f,
        /*humidity_too_high*/ 90.0f,
        /*humidity_too_low*/ 30.0f,
        /*light_too_dark*/ 800,
        /*light_bright*/ 500,
        /*soil_dry_threshold*/ 700,
        /*soil_wet_threshold*/ 250,
        /*vent_start_h*/ 6,
        /*vent_end_h*/ 22,
        /*vent_check_interval_ms*/ 20000UL // every 20 s (for testing)
    };

}


const ClimateProfile* active_profile = &Profile::TESTERS;


struct ClimateFlags {
    bool too_hot;
    bool too_cold;
    bool too_humid;
    bool too_dry_air;
    bool too_dark;
    bool soil_dry;
    bool soil_wet;
};


ClimateFlags climate_flags = {};

constexpr int PIN_DHT = 8;
constexpr int PIN_RELAY_HEATER = 7;
constexpr int PIN_RELAY_PUMP = 6;
constexpr int PIN_RELAY_LAMP = 5;
constexpr int PIN_RELAY_FAN = 4;
constexpr int PIN_LIGHT_SENSOR = A0;
constexpr int PIN_SOIL_SENSOR = A1;


constexpr unsigned long PUMP_ON_TIME_MS = 1000UL; // pump runs for 1 s
constexpr unsigned long PUMP_WAIT_TIME_MS = 15000UL; // wait 15 s for absorption
constexpr int PUMP_MAX_CYCLES = 5; // max watering cycles

constexpr unsigned long LOOP_INTERVAL_MS = 2000UL;


namespace Relay {
    void init(int pin);
    void on(int pin);
    void off(int pin);
    bool isOn(int pin);
}


void Relay::init(int pin) { pinMode(pin, OUTPUT); digitalWrite(pin, LOW); }
void Relay::on(int pin) { digitalWrite(pin, HIGH); }
void Relay::off(int pin) { digitalWrite(pin, LOW); }
bool Relay::isOn(int pin) { return digitalRead(pin) == HIGH; }


class ISensor {
public:
    virtual void begin() = 0;
    virtual void update() = 0;
};


class DHTDriver {
private:
    DHT dht;
    unsigned long last_read_ms;
public:
    float temperature;
    float air_humidity;

    DHTDriver(int pin);
    void begin();
    void read();
};


DHTDriver::DHTDriver(int pin) : dht(pin, DHT11), last_read_ms(0) {
    temperature = 20.0f;
    air_humidity = 50.0f;
}


void DHTDriver::begin() {
    dht.begin();
}


void DHTDriver::read() {
    unsigned long now = millis();
    if (now - last_read_ms < LOOP_INTERVAL_MS) return;
    last_read_ms = now;
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    if (!isnan(t)) temperature  = t;
    if (!isnan(h)) air_humidity = h;
}


class TemperatureSensor : public ISensor {
private:
    DHTDriver& driver;
public:
    TemperatureSensor(DHTDriver& driver);
    void begin() override;
    void update() override;
    float value() const;
};


TemperatureSensor::TemperatureSensor(DHTDriver& d) : driver(d) {}
void TemperatureSensor::begin() {}
void TemperatureSensor::update() { driver.read(); }
float TemperatureSensor::value() const { return driver.temperature; }


class HumiditySensor : public ISensor {
private:
    DHTDriver& driver;
public:
    HumiditySensor(DHTDriver& driver);
    void begin() override;
    void update() override;
    float value() const;
};


HumiditySensor::HumiditySensor(DHTDriver& d) : driver(d) {}
void HumiditySensor::begin()  {}
void HumiditySensor::update() { driver.read(); }
float HumiditySensor::value() const { return driver.air_humidity; }


class LightSensor : public ISensor {
private:
    int pin;
public:
    int raw_value;

    LightSensor(int pin);
    void begin() override;
    void update() override;
};


LightSensor::LightSensor(int p) : pin(p), raw_value(0) {}
void LightSensor::begin() { pinMode(pin, INPUT); }
void LightSensor::update() { raw_value = analogRead(pin); }


class SoilSensor : public ISensor {
private:
    int pin;
public:
    int raw_value;

    SoilSensor(int pin);
    void begin() override;
    void update() override;
};


SoilSensor::SoilSensor(int p) : pin(p), raw_value(0) {}
void SoilSensor::begin() { pinMode(pin, INPUT); }
void SoilSensor::update() { raw_value = analogRead(pin); }


void update_climate_flags(const TemperatureSensor& temp,
                          const HumiditySensor& hum,
                          const LightSensor& light,
                          const SoilSensor& soil,
                          const ClimateProfile& p,
                          ClimateFlags& f)
{
    f.too_hot = temp.value() > p.temp_too_hot;
    f.too_cold = temp.value() < p.temp_too_cold;
    f.too_humid = hum.value() > p.humidity_too_high;
    f.too_dry_air= hum.value() < p.humidity_too_low;
    f.too_dark = light.raw_value > p.light_too_dark;
    f.soil_dry = soil.raw_value > p.soil_dry_threshold;
    f.soil_wet = soil.raw_value < p.soil_wet_threshold;

    // Debug output
    Serial.print(F("[Flags] hot:")); Serial.print(f.too_hot);
    Serial.print(F(" cold:")); Serial.print(f.too_cold);
    Serial.print(F(" humid:")); Serial.print(f.too_humid);
    Serial.print(F(" dry_air:")); Serial.print(f.too_dry_air);
    Serial.print(F(" dark:")); Serial.print(f.too_dark);
    Serial.print(F(" s.dry:")); Serial.print(f.soil_dry);
    Serial.print(F(" s.wet:")); Serial.println(f.soil_wet);
}


class IActuator {
public:
    virtual void begin() = 0;
    virtual void set(bool on) = 0;
};


class Fan : public IActuator {
private:
    int pin;
public:
    Fan(int pin);
    void begin() override;
    void set(bool on) override;
};


Fan::Fan(int p) : pin(p) {}
void Fan::begin() { Relay::init(pin); }
void Fan::set(bool on) {
    if (on) { Relay::on(pin); Serial.println(F("[Fan] ON")); }
    else { Relay::off(pin); Serial.println(F("[Fan] OFF")); }
}


class Heater : public IActuator {
private:
    int pin;
public:
    Heater(int pin);
    void begin() override;
    void set(bool on) override;
};


Heater::Heater(int p) : pin(p) {}
void Heater::begin() { Relay::init(pin); }
void Heater::set(bool on) {
    if (on) { Relay::on(pin); Serial.println(F("[Heater] ON")); }
    else { Relay::off(pin); Serial.println(F("[Heater] OFF")); }
}


class Lamp : public IActuator {
private:
    int pin;
public:
    Lamp(int pin);
    void begin() override;
    void set(bool on) override;
};


Lamp::Lamp(int p) : pin(p) {}
void Lamp::begin() { Relay::init(pin); }
void Lamp::set(bool on) {
    if (on) { Relay::on(pin); Serial.println(F("[Lamp] ON")); }
    else { Relay::off(pin); Serial.println(F("[Lamp] OFF")); }
}


class Pump : public IActuator {
public:
    enum class State { IDLE, WATERING, WAITING };

private:
    int pin;
    State state;
    unsigned long state_start_ms;
    int cycle_count;

public:
    Pump(int pin);
    void begin() override;
    void set(bool on) override;
    void update(const ClimateFlags& flags, SoilSensor& soil);
    State get_state() const;
};


Pump::Pump(int p) : pin(p), state(State::IDLE), state_start_ms(0), cycle_count(0) {}
void Pump::begin() { Relay::init(pin); }
void Pump::set(bool on) {}
Pump::State Pump::get_state() const { return state; }


void Pump::update(const ClimateFlags& flags, SoilSensor& soil) {
    unsigned long now = millis();
    switch (state) {
        case State::IDLE:
            if (flags.soil_dry && Clock::is_daytime()) {
                cycle_count = 0;
                state = State::WATERING;
                state_start_ms = now;
                Relay::on(pin);
                Serial.println(F("[Pump] Soil dry -> WATERING"));
            }
            break;

        case State::WATERING:
            if (now - state_start_ms >= PUMP_ON_TIME_MS) {
                Relay::off(pin);
                state = State::WAITING;
                state_start_ms = now;
                Serial.print(F("[Pump] Pump OFF -> WAITING (cycle "));
                Serial.print(cycle_count + 1);
                Serial.println(F(")"));
            }
            break;

        case State::WAITING:
            if (now - state_start_ms >= PUMP_WAIT_TIME_MS) {
                soil.update(); // fresh reading after absorption
                if (flags.soil_wet) {
                    state = State::IDLE;
                    cycle_count = 0;
                    Serial.println(F("[Pump] Soil wet -> IDLE"));
                } else if (cycle_count + 1 >= PUMP_MAX_CYCLES) {
                    state = State::IDLE;
                    cycle_count = 0;
                    Serial.println(F("[Pump] Max cycles -> IDLE (check sensor/water)"));
                } else {
                    cycle_count++;
                    state = State::WATERING;
                    state_start_ms = now;
                    Relay::on(pin);
                    Serial.print(F("[Pump] Still dry -> WATERING (cycle "));
                    Serial.print(cycle_count + 1);
                    Serial.println(F(")"));
                }
            }
            break;
    }
}


// too_hot -> fan
bool rule_fan_hot(const ClimateFlags& f) {
    return f.too_hot;
}

bool rule_fan_cold(const ClimateFlags& f) {
    return f.too_cold;
}

// too_cold -> heater needed (fan must also run)
bool rule_heater(const ClimateFlags& f) {
    return f.too_cold;
}

// too_humid -> ventilation
bool rule_fan_humidity(const ClimateFlags& f) {
    return f.too_humid;
}

// periodic ventilation
bool rule_fan_scheduled(const ClimateProfile& p) {
    static unsigned long last_vent_ms = 0;
    unsigned long now = millis();

    if (!Clock::is_daytime()) return false;

    int h = Clock::get_hour();
    if (h < p.vent_start_h || h >= p.vent_end_h) return false;

    if (now - last_vent_ms >= p.vent_check_interval_ms) {
        last_vent_ms = now;
        Serial.println(F("[Rule] Scheduled vent -> fan ON"));
        return true;
    }
    return false;
}

// too_dark AND daytime
bool rule_lamp(const ClimateFlags& f) {
    return f.too_dark && Clock::is_daytime();
}


DHTDriver dht_driver(PIN_DHT);
TemperatureSensor temp_sensor(dht_driver);
HumiditySensor hum_sensor(dht_driver);
LightSensor light_sensor(PIN_LIGHT_SENSOR);
SoilSensor soil_sensor(PIN_SOIL_SENSOR);

Fan fan(PIN_RELAY_FAN);
Heater heater(PIN_RELAY_HEATER);
Lamp lamp(PIN_RELAY_LAMP);
Pump pump(PIN_RELAY_PUMP);


void setup() {
    Serial.begin(9600);
    Serial.println(F("=== Smart Greenhouse booting ==="));
    Serial.print(F("=== Profile: "));
    Serial.print(active_profile->name);
    Serial.println(F(" ==="));

    dht_driver.begin();
    temp_sensor.begin();
    hum_sensor.begin();
    light_sensor.begin();
    soil_sensor.begin();

    fan.begin();
    heater.begin();
    lamp.begin();
    pump.begin();

    Serial.println(F("=== All devices initialised ==="));
}


void loop() {
    static unsigned long last_poll_ms = 0;
    unsigned long now = millis();

    if (now - last_poll_ms >= LOOP_INTERVAL_MS) {
        last_poll_ms = now;

        temp_sensor.update();
        hum_sensor.update();
        light_sensor.update();
        soil_sensor.update();

        Serial.print(F("[Sensors] Temp: "));
        Serial.print(temp_sensor.value());
        Serial.print(F(" C  AirHum: "));
        Serial.print(hum_sensor.value());
        Serial.print(F("%  Light: "));
        Serial.print(light_sensor.raw_value);
        Serial.print(F("  Soil: "));
        Serial.print(soil_sensor.raw_value);
        Serial.print(F("  Hour: "));
        Serial.print(Clock::get_hour());
        Serial.print(F("  Daytime: "));
        Serial.println(Clock::is_daytime() ? "yes" : "no");

        update_climate_flags(temp_sensor, hum_sensor, light_sensor,
                             soil_sensor, *active_profile, climate_flags);

        // Runs if temperature is too high, humidity is too high,
        // or the scheduled ventilation window is active.
        bool fan_on = Clock::is_daytime() && (
                      rule_fan_hot(climate_flags)
                   || rule_fan_humidity(climate_flags)
                   || rule_fan_scheduled(*active_profile)
                   || rule_fan_cold(climate_flags));
        if (fan_on && climate_flags.too_hot)  Serial.println(F("[Rule] Too hot -> fan ON"));
        if (fan_on && climate_flags.too_humid) Serial.println(F("[Rule] Too humid -> fan ON"));
        fan.set(fan_on);

        // Runs only when too_cold AND fan is already running.
        bool heater_on = rule_heater(climate_flags) && fan_on;
        if (climate_flags.too_cold && !fan_on)
            Serial.println(F("[Safety] Heater blocked - fan not running!"));
        if (heater_on) Serial.println(F("[Rule] Too cold -> heater ON"));
        heater.set(heater_on);

        // Runs only when it is dark AND it is daytime
        bool lamp_on = rule_lamp(climate_flags);
        if (lamp_on) Serial.println(F("[Rule]Darkness is coming -> lamp ON"));
        lamp.set(lamp_on);
    }

    pump.update(climate_flags, soil_sensor);
}
