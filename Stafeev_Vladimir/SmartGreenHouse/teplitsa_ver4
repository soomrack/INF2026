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
//Control rules (each sets actuator.on_condition):
// control_temperature : too_hot / too_cold -> fan, heater
//  control_humidity : too_humid -> fan
//  control_ventilation : scheduled window -> fan
//  control_light : too_dark + daytime -> lamp
//  control_soil : soil_dry / wet -> pump state machine
//
//Actuator power() in loop():
// fan.power() - on when on_condition is true
// heater.power() - on when on_condition is true (safety: fan must be on)
// lamp.power() - on when on_condition is true
// pump.power() - driven by internal state machine

#include <DHT.h>


constexpr int PIN_DHT          = 8;
constexpr int PIN_RELAY_HEATER = 7;
constexpr int PIN_RELAY_PUMP   = 6;
constexpr int PIN_RELAY_LAMP   = 5;
constexpr int PIN_RELAY_FAN    = 4;
constexpr int PIN_LIGHT_SENSOR = A0;
constexpr int PIN_SOIL_SENSOR  = A1;

constexpr unsigned long LOOP_INTERVAL_MS  = 2000UL;
constexpr unsigned long PUMP_ON_TIME_MS   = 1000UL;   // pump runs for 1 s
constexpr unsigned long PUMP_WAIT_TIME_MS = 15000UL;  // wait 15 s for absorption
constexpr int PUMP_MAX_CYCLES   = 5;        // max watering cycles per session


// Simulation: 1 real minute = 1 simulated hour (full day = 24 min)

namespace Clock {
    int  get_hour();
    bool is_daytime(int day_start_h = 0, int day_end_h = 22);
}

int Clock::get_hour() {
    return (int)((millis() / 60000UL) % 24);
}

bool Clock::is_daytime(int day_start_h, int day_end_h) {
    int h = get_hour();
    return (h >= day_start_h && h < day_end_h);
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

    int vent_start_h;           // scheduled ventilation window
    int vent_end_h;
    unsigned long vent_interval_ms;       // re-ventilation period
};


namespace Profile {

    const ClimateProfile tomatoes = {
        "Tomatoes",
        /*temp_too_hot*/ 28.0f,
        /*temp_too_cold*/ 18.0f,
        /*humidity_too_high*/ 80.0f,
        /*humidity_too_low*/ 40.0f,
        /*light_too_dark*/ 700,
        /*light_bright*/ 500,
        /*soil_dry*/ 800, /*soil_wet*/ 300,
        /*vent_start_h*/ 10, /*vent_end_h*/ 14,
        /*vent_interval_ms*/ 1800000UL   // every 30 min
    };

    const ClimateProfile cucumbers = {
        "Cucumbers",
        /*temp_too_hot*/ 32.0f,
        /*temp_too_cold*/ 22.0f,
        /*humidity_too_high*/ 90.0f,
        /*humidity_too_low*/ 50.0f,
        /*light_too_dark*/ 650,
        /*light_bright*/ 450,
        /*soil_dry*/ 700, /*soil_wet*/ 250,
        /*vent_start_h*/ 11, /*vent_end_h*/ 15,
        /*vent_interval_ms*/ 1200000UL   // every 20 min
    };

    const ClimateProfile TESTER = {
        "TESTER",
        /*temp_too_hot*/ 29.0f,
        /*temp_too_cold*/ 27.0f,
        /*humidity_too_high*/ 90.0f,
        /*humidity_too_low*/ 30.0f,
        /*light_too_dark*/ 900,
        /*light_bright*/ 100,
        /*soil_dry*/ 700, /*soil_wet*/ 250,
        /*vent_start_h*/ 6, /*vent_end_h*/ 22,
        /*vent_interval_ms*/ 20000UL     // every 20 s (testing)
    };

}


const ClimateProfile* active_profile = &Profile::TESTER;


struct ClimateFlags {
    bool too_hot;
    bool too_cold;
    bool too_humid;
    bool too_dry_air;   // reserved
    bool too_dark;
    bool soil_dry;
    bool soil_wet;
};

ClimateFlags climate_flags = {};


namespace Relay {
    void init(int pin) { pinMode(pin, OUTPUT); digitalWrite(pin, LOW); }
    void on (int pin) { digitalWrite(pin, HIGH); }
    void off (int pin) { digitalWrite(pin, LOW);  }
}


class DHTDriver {
private:
    DHT dht;
    unsigned long last_read_ms;
public:
    float temperature;
    float humidity;

    DHTDriver(int pin) : dht(pin, DHT11), last_read_ms(0),
                         temperature(20.0f), humidity(50.0f) {}

    void begin() { dht.begin(); }

    void read() {
        unsigned long now = millis();
        if (now - last_read_ms < LOOP_INTERVAL_MS) return;
        last_read_ms = now;
        float t = dht.readTemperature();
        float h = dht.readHumidity();
        if (!isnan(t)) temperature = t;
        if (!isnan(h)) humidity = h;
    }
};


class Thermometer {
private:
    DHTDriver& driver;
public:
    float temperature;

    Thermometer(DHTDriver& driver) : driver(driver), temperature(20.0f) {}
    void begin() {}
    void get_temperature() { driver.read(); temperature = driver.temperature; }
};


class Hygrometer {
private:
    DHTDriver& driver;
public:
    float humidity;

    Hygrometer(DHTDriver& driver) : driver(driver), humidity(50.0f) {}
    void begin() {}
    void get_humidity() { driver.read(); humidity = driver.humidity; }
};


class LightSensor {
private:
    int pin;
public:
    int raw_value;

    LightSensor(int pin) : pin(pin), raw_value(0) {}
    void begin() { pinMode(pin, INPUT); }
    void get_light() { raw_value = analogRead(pin); }
};


class SoilSensor {
private:
    int pin;
public:
    int raw_value;

    SoilSensor(int pin) : pin(pin), raw_value(0) {}
    void begin() { pinMode(pin, INPUT); }
    void get_moisture(){ raw_value = analogRead(pin); }
};


class Fan {
public:
    bool on_condition;
private:
    int pin;
public:
    Fan(int pin) : pin(pin), on_condition(false) {}
    void begin() { Relay::init(pin); }
    void power() {
        if (on_condition) { Relay::on(pin);  Serial.println(F("[Fan] ON"));  }
        else { Relay::off(pin); Serial.println(F("[Fan] OFF")); }
    }
};


class Heater {
public:
    bool on_condition;
private:
    int pin;
public:
    Heater(int pin) : pin(pin), on_condition(false) {}
    void begin() { Relay::init(pin); }
    void power() {
        if (on_condition) { Relay::on(pin);  Serial.println(F("[Heater] ON"));  }
        else { Relay::off(pin); Serial.println(F("[Heater] OFF")); }
    }
};


class Lamp {
public:
    bool on_condition;
private:
    int pin;
public:
    Lamp(int pin) : pin(pin), on_condition(false) {}
    void begin() { Relay::init(pin); }
    void power() {
        if (on_condition) { Relay::on(pin);  Serial.println(F("[Lamp] ON"));  }
        else { Relay::off(pin); Serial.println(F("[Lamp] OFF")); }
    }
};


class Pump {
public:
    enum class State { IDLE, WATERING, WAITING };
    bool on_condition;

private:
    int pin;
    State state;
    unsigned long state_start_ms;
    int cycle_count;

public:
    Pump(int pin) : pin(pin), on_condition(false),
                    state(State::IDLE), state_start_ms(0), cycle_count(0) {}

    void begin() { Relay::init(pin); }

    void power(const ClimateFlags& flags, SoilSensor& soil) {
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
                    Serial.print(F("[Pump] OFF -> WAITING (cycle "));
                    Serial.print(cycle_count + 1);
                    Serial.println(F(")"));
                }
                break;

            case State::WAITING:
                if (now - state_start_ms >= PUMP_WAIT_TIME_MS) {
                    soil.get_moisture();  // fresh reading after absorption
                    if (flags.soil_wet) {
                        state = State::IDLE;
                        cycle_count = 0;
                        Serial.println(F("[Pump] Soil wet -> IDLE"));
                    } else if (cycle_count + 1 >= PUMP_MAX_CYCLES) {
                        state = State::IDLE;
                        cycle_count = 0;
                        Serial.println(F("[Pump] Max cycles -> IDLE (check sensor/water)"));
                    } else {
                        ++cycle_count;
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
};


void control_temperature(const ClimateFlags& f, Fan& fan, Heater& heater)
{
    if (f.too_hot) {
        fan.on_condition = true;
        heater.on_condition = false;
        Serial.println(F("[Control] Too hot  -> fan ON, heater OFF"));
    }

    if (f.too_cold) {
        fan.on_condition = true;
        heater.on_condition = true;
        Serial.println(F("[Control] Too cold -> fan ON, heater ON"));
    }
}


void control_humidity(const ClimateFlags& f, Fan& fan)
{
    if (f.too_humid) {
        fan.on_condition = true;
        Serial.println(F("[Control] Too humid -> fan ON"));
    }
}


void control_ventilation(const ClimateProfile& p, Fan& fan)
{
    static unsigned long last_vent_ms = 0;
    unsigned long now = millis();

    if (!Clock::is_daytime()) return;

    int h = Clock::get_hour();
    if (h < p.vent_start_h || h >= p.vent_end_h) return;

    if (now - last_vent_ms >= p.vent_interval_ms) {
        last_vent_ms = now;
        fan.on_condition = true;
        Serial.println(F("[Control] Scheduled ventilation -> fan ON"));
    }
}


void control_light(const ClimateFlags& f, Lamp& lamp)
{
    if (f.too_dark && Clock::is_daytime()) {
        lamp.on_condition = true;
        Serial.println(F("[Control] Too dark + daytime -> lamp ON"));
    }
}


void log_sensors(const Thermometer& thermometer, const Hygrometer& hygrometer,
                 const LightSensor& light,       const SoilSensor& soil)
{
    Serial.print(F("[Sensors] Temp: ")); Serial.print(thermometer.temperature);
    Serial.print(F(" C  Hum: ")); Serial.print(hygrometer.humidity);
    Serial.print(F("%  Light: ")); Serial.print(light.raw_value);
    Serial.print(F("  Soil: ")); Serial.print(soil.raw_value);
    Serial.print(F("  Hour: ")); Serial.print(Clock::get_hour());
    Serial.print(F("  Daytime: ")); Serial.println(Clock::is_daytime() ? "yes" : "no");
}

void log_flags(const ClimateFlags& f)
{
    Serial.print(F("[Flags] hot:")); Serial.print(f.too_hot);
    Serial.print(F(" cold:")); Serial.print(f.too_cold);
    Serial.print(F(" humid:")); Serial.print(f.too_humid);
    Serial.print(F(" dry_air:")); Serial.print(f.too_dry_air);
    Serial.print(F(" dark:")); Serial.print(f.too_dark);
    Serial.print(F(" s.dry:")); Serial.print(f.soil_dry);
    Serial.print(F(" s.wet:")); Serial.println(f.soil_wet);
}


DHTDriver   dht_driver(PIN_DHT);
Thermometer thermometer(dht_driver);
Hygrometer  hygrometer(dht_driver);
LightSensor light_sensor(PIN_LIGHT_SENSOR);
SoilSensor  soil_sensor(PIN_SOIL_SENSOR);

Fan    fan(PIN_RELAY_FAN);
Heater heater(PIN_RELAY_HEATER);
Lamp   lamp(PIN_RELAY_LAMP);
Pump   pump(PIN_RELAY_PUMP);


void setup()
{
    Serial.begin(9600);
    Serial.println(F("=== Smart Greenhouse booting ==="));
    Serial.print(F("=== Profile: "));
    Serial.print(active_profile->name);
    Serial.println(F(" ==="));

    dht_driver.begin();
    thermometer.begin();
    hygrometer.begin();
    light_sensor.begin();
    soil_sensor.begin();

    fan.begin();
    heater.begin();
    lamp.begin();
    pump.begin();

    Serial.println(F("=== All devices initialised ==="));
}


void loop()
{
    static unsigned long last_poll_ms = 0;
    unsigned long now = millis();

    if (now - last_poll_ms >= LOOP_INTERVAL_MS) {
        last_poll_ms = now;

        thermometer.get_temperature();
        hygrometer.get_humidity();
        light_sensor.get_light();
        soil_sensor.get_moisture();
        log_sensors(thermometer, hygrometer, light_sensor, soil_sensor);


        climate_flags.too_hot = thermometer.temperature > active_profile->temp_too_hot;
        climate_flags.too_cold = thermometer.temperature < active_profile->temp_too_cold;
        climate_flags.too_humid = hygrometer.humidity > active_profile->humidity_too_high;
        climate_flags.too_dry_air = hygrometer.humidity < active_profile->humidity_too_low;
        climate_flags.too_dark = light_sensor.raw_value > active_profile->light_too_dark;
        climate_flags.soil_dry = soil_sensor.raw_value > active_profile->soil_dry_threshold;
        climate_flags.soil_wet = soil_sensor.raw_value < active_profile->soil_wet_threshold;
        log_flags(climate_flags);

        fan.on_condition    = false;
        heater.on_condition = false;
        lamp.on_condition   = false;

        control_temperature(climate_flags, fan, heater);
        control_humidity(climate_flags, fan);
        control_ventilation(*active_profile, fan);
        control_light(climate_flags, lamp);


        if (heater.on_condition && !fan.on_condition) {
            heater.on_condition = false;
            Serial.println(F("[Safety] Heater blocked - fan not running!"));
        }

        fan.power();
        heater.power();
        lamp.power();
    }

    pump.power(climate_flags, soil_sensor);
}
