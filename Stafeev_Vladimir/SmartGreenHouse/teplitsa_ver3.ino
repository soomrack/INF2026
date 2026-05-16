// ============================================================================
// Smart Greenhouse Controller
// Board : Arduino Uno
// ============================================================================
//
//  Pinout:
//    D4  — Relay: Fan
//    D5  — Relay: Lamp
//    D6  — Relay: Pump
//    D7  — Relay: Heater
//    D8  — DHT11 (temperature + air humidity)
//    A0  — Light sensor      (photoresistor, lower = brighter)
//    A1  — Soil moisture sensor (lower raw value = wetter)
//
//  Rules:
//    - Heater turns ON only together with Fan (never alone)
//    - Pump uses a state machine: water → wait for soil to absorb → re-check
//    - Lamp turns ON only during daytime (not at night)
//    - Fan runs on schedule during daytime
//    - Fan runs when humidity is too high
//
// ============================================================================

#include <DHT.h>

// ============================================================================
// SECTION 1: TIME HELPERS
// ============================================================================

namespace Clock {
    // Returns current hour (0–23).
    // Default: derives hours from millis() — each real minute = 1 sim hour.
    int get_hour() {
        // Simulation: 1 real minute = 1 simulated hour  (full day = 24 min)
        return (int)((millis() / 60000UL) % 24);
    }

    bool is_daytime(int day_start_h = 0, int day_end_h = 1) {
        int h = get_hour();
        return h >= day_start_h && h < day_end_h;
    }
}

// ============================================================================
// SECTION 2: CLIMATE PROFILES
// ============================================================================
//
//  To add a new profile — just add a new Profile::XXX block.
//  Control rules automatically pick up the active profile's thresholds.
//  Switch at runtime by changing: active_profile = &Profile::cucumbers;
//
// ============================================================================

struct ClimateProfile {
    const char* name;

    // Temperature thresholds (°C)
    float temp_too_hot;     // fan only above this
    float temp_too_cold;    // heater + fan below this

    // Air humidity thresholds (%)
    float humidity_too_high;  // ventilate above this

    // Light thresholds (raw ADC 0–1023, lower = brighter)
    int light_too_dark;     // lamp ON  above this value
    int light_bright;       // lamp OFF below this value

    // Soil moisture thresholds (raw ADC 0–1023, lower = wetter)
    int soil_dry;           // start watering above this
    int soil_wet;           // stop  watering below this

    // Scheduled ventilation
    int vent_start_h;       // hour to start scheduled ventilation (daytime only)
    int vent_end_h;         // hour to stop  scheduled ventilation
};

namespace Profile {

    const ClimateProfile tomatoes = {
        /* name             */ "Tomatoes",
        /* temp_too_hot     */ 28.0f,
        /* temp_too_cold    */ 18.0f,
        /* humidity_too_high*/ 80.0f,
        /* light_too_dark   */ 700,
        /* light_bright     */ 500,
        /* soil_dry         */ 800,
        /* soil_wet         */ 300,
        /* vent_start_h     */ 10,
        /* vent_end_h       */ 14
    };

    const ClimateProfile cucumbers = {
        /* name             */ "Cucumbers",
        /* temp_too_hot     */ 32.0f,
        /* temp_too_cold    */ 22.0f,
        /* humidity_too_high*/ 90.0f,
        /* light_too_dark   */ 650,
        /* light_bright     */ 450,
        /* soil_dry         */ 700,
        /* soil_wet         */ 250,
        /* vent_start_h     */ 11,
        /* vent_end_h       */ 15
    };

    const ClimateProfile TESTERS = {
        /* name             */ "TESTERS",
        /* temp_too_hot     */ 29.0f,
        /* temp_too_cold    */ 28.0f,
        /* humidity_too_high*/ 90.0f,
        /* light_too_dark   */ 800,
        /* light_bright     */ 500,
        /* soil_dry         */ 700,
        /* soil_wet         */ 250,
        /* vent_start_h     */ 11,
        /* vent_end_h       */ 15
    };
}   // namespace Profile

// Active profile pointer — change this one line to switch the entire climate
const ClimateProfile* active_profile = &Profile::TESTERS;

// ============================================================================
// SECTION 3: CONFIGURATION
// ============================================================================

// --- Pins ---
constexpr int PIN_DHT          = 8;
constexpr int PIN_RELAY_HEATER = 7;
constexpr int PIN_RELAY_PUMP   = 6;
constexpr int PIN_RELAY_LAMP   = 5;
constexpr int PIN_RELAY_FAN    = 4;
constexpr int PIN_LIGHT_SENSOR = A0;
constexpr int PIN_SOIL_SENSOR  = A1;

// --- Pump timing ---
constexpr unsigned long PUMP_ON_TIME_MS   =  1000UL;   // pump runs for 1 s
constexpr unsigned long PUMP_WAIT_TIME_MS = 15000UL;   // wait 15 s for water to absorb
constexpr int           PUMP_MAX_CYCLES   = 5;         // max consecutive watering cycles

// --- Main loop delay ---
constexpr unsigned long LOOP_INTERVAL_MS  =  2000UL;   // sensor poll interval

// ============================================================================
// SECTION 4: RELAY HELPERS  (active-HIGH logic)
// ============================================================================

namespace Relay {
    void init(int pin) { pinMode(pin, OUTPUT); digitalWrite(pin, LOW); }
    void on  (int pin) { digitalWrite(pin, HIGH); }
    void off (int pin) { digitalWrite(pin, LOW);  }
    bool isOn(int pin) { return digitalRead(pin) == HIGH; }
}

// ============================================================================
// SECTION 5: SENSOR INTERFACE
// ============================================================================

class ISensor {
public:
    virtual void begin()  = 0;
    virtual void update() = 0;
};

// ============================================================================
// SECTION 6: SENSORS
// ============================================================================

class DHTDriver {
private:
    DHT           dht;
    unsigned long last_read_ms;

public:
    float temperature;    // °C,  last valid reading
    float air_humidity;   // %,   last valid reading

    DHTDriver(int pin) : dht(pin, DHT11), last_read_ms(0) {
        temperature  = 20.0f;
        air_humidity = 50.0f;
    }

    void begin() { dht.begin(); }

    void read() {
        unsigned long now = millis();
        if (now - last_read_ms < LOOP_INTERVAL_MS) return;   // already fresh
        last_read_ms = now;

        float t = dht.readTemperature();
        float h = dht.readHumidity();
        if (!isnan(t)) temperature  = t;
        if (!isnan(h)) air_humidity = h;
    }
};


class TemperatureSensor : public ISensor {
private:
    DHTDriver& driver;
public:
    TemperatureSensor(DHTDriver& driver) : driver(driver) {}

    void begin()  override { /* DHTDriver::begin() handles hardware init */ }
    void update() override { driver.read(); }

    float value() const { return driver.temperature; }
};

// --- HumiditySensor: ISensor wrapper — exposes air humidity only ---
class HumiditySensor : public ISensor {
private:
    DHTDriver& driver;
public:
    HumiditySensor(DHTDriver& driver) : driver(driver) {}

    void begin()  override { /* DHTDriver::begin() handles hardware init */ }
    void update() override { driver.read(); }

    float value() const { return driver.air_humidity; }
};

// --- Photoresistor: ambient light ---
class LightSensor : public ISensor {
private:
    int pin;
public:
    int raw_value;    // 0–1023  (lower = brighter)

    LightSensor(int pin) : pin(pin), raw_value(0) {}

    void begin()  override { pinMode(pin, INPUT); }
    void update() override { raw_value = analogRead(pin); }

    bool is_dark  (const ClimateProfile& p) const { return raw_value >  p.light_too_dark; }
    bool is_bright(const ClimateProfile& p) const { return raw_value <  p.light_bright;   }
};

// --- Capacitive / resistive soil moisture ---
class SoilSensor : public ISensor {
private:
    int pin;
public:
    int raw_value;    // 0–1023  (lower = wetter)

    SoilSensor(int pin) : pin(pin), raw_value(0) {}

    void begin()  override { pinMode(pin, INPUT); }
    void update() override { raw_value = analogRead(pin); }

    bool is_dry(const ClimateProfile& p) const { return raw_value >  p.soil_dry; }
    bool is_wet(const ClimateProfile& p) const { return raw_value <  p.soil_wet; }
};

// ============================================================================
// SECTION 7: ACTUATOR INTERFACE  (Open-Closed: add actuators without changing rules)
// ============================================================================


class IActuator {
public:
    bool requested_on = false;
    virtual void begin() = 0;
    virtual void power() = 0;  
};

// ============================================================================
// SECTION 8: ACTUATORS
// ============================================================================

// --- Fan ---
class Fan : public IActuator {
private:
    int pin;
public:
    Fan(int pin) : pin(pin) {}
    void begin() override { Relay::init(pin); }
    void power() override {
        if (requested_on) { Relay::on(pin);  Serial.println(F("[Fan]    ON")); }
        else              { Relay::off(pin); Serial.println(F("[Fan]    OFF")); }
    }
};

// --- Heater ---
// NOTE: Heater must never run without the fan.
//       Apply fan.power() BEFORE heater.power() — see loop().
class Heater : public IActuator {
private:
    int pin;
public:
    Heater(int pin) : pin(pin) {}
    void begin() override { Relay::init(pin); }
    void power() override {
        if (requested_on) { Relay::on(pin);  Serial.println(F("[Heater] ON")); }
        else              { Relay::off(pin); Serial.println(F("[Heater] OFF")); }
    }
};

// --- Lamp ---
class Lamp : public IActuator {
private:
    int pin;
public:
    Lamp(int pin) : pin(pin) {}
    void begin() override { Relay::init(pin); }
    void power() override {
        if (requested_on) { Relay::on(pin);  Serial.println(F("[Lamp]   ON")); }
        else              { Relay::off(pin); Serial.println(F("[Lamp]   OFF")); }
    }
};


class Pump : public IActuator {
public:
    enum class State { IDLE, WATERING, WAITING };

private:
    int           pin;
    State         state;
    unsigned long state_start_ms;
    int           cycle_count;

public:
    Pump(int pin) : pin(pin), state(State::IDLE),
                    state_start_ms(0), cycle_count(0) {}

    void begin() override { Relay::init(pin); }


    void power() override {}

    // Call every loop iteration (before or after the timed block — doesn't matter).
    void update(SoilSensor& soil, const ClimateProfile& profile) {
        unsigned long now = millis();

        switch (state) {
            case State::IDLE:
                if (soil.is_dry(profile)) {
                    cycle_count    = 0;
                    state          = State::WATERING;
                    state_start_ms = now;
                    Relay::on(pin);
                    Serial.println(F("[Pump]   Soil dry  → WATERING"));
                }
                break;

            case State::WATERING:
                if (now - state_start_ms >= PUMP_ON_TIME_MS) {
                    Relay::off(pin);
                    state          = State::WAITING;
                    state_start_ms = now;
                    Serial.print  (F("[Pump]   Pump OFF  → WAITING (cycle "));
                    Serial.print  (cycle_count + 1);
                    Serial.println(F(")"));
                }
                break;

            case State::WAITING:
                if (now - state_start_ms >= PUMP_WAIT_TIME_MS) {
                    soil.update();   // fresh reading after absorption

                    if (soil.is_wet(profile)) {
                        state       = State::IDLE;
                        cycle_count = 0;
                        Serial.println(F("[Pump]   Soil wet  → IDLE"));
                    } else if (cycle_count + 1 >= PUMP_MAX_CYCLES) {
                        state       = State::IDLE;
                        cycle_count = 0;
                        Serial.println(F("[Pump]   Max cycles → IDLE (check sensor/water)"));
                    } else {
                        cycle_count++;
                        state          = State::WATERING;
                        state_start_ms = now;
                        Relay::on(pin);
                        Serial.print  (F("[Pump]   Still dry → WATERING (cycle "));
                        Serial.print  (cycle_count + 1);
                        Serial.println(F(")"));
                    }
                }
                break;
        }
    }

    State get_state() const { return state; }
};

// ============================================================================
// SECTION 9: CONTROL RULES  (Open-Closed: add rules without changing existing ones)
// ============================================================================

void rule_temperature(const TemperatureSensor& temp, Fan& fan, Heater& heater,
                      const ClimateProfile& p)
{
    if (temp.value() > p.temp_too_hot) {
        fan.requested_on    = true;
        heater.requested_on = false;
        return;
    }
    if (temp.value() < p.temp_too_cold) {
        fan.requested_on    = true;   // fan MUST accompany heater
        heater.requested_on = true;
        return;
    }
    // Comfortable range — leave fan/heater as-is (other rules may still need fan)
}

// --- Rule 2: Lighting (daytime only) ---
// Lamp ON only when it's dark AND daytime.
// Lamp OFF when bright OR nighttime.
void rule_lighting(const LightSensor& light, Lamp& lamp,
                   const ClimateProfile& p)
{
    if (!Clock::is_daytime()) {
        lamp.requested_on = false;
        return;
    }
    if (light.is_dark(p))        lamp.requested_on = true;
    else if (light.is_bright(p)) lamp.requested_on = false;
}

// --- Rule 3: Humidity ventilation ---
// High humidity → turn on fan
void rule_humidity(const HumiditySensor& hum, Fan& fan,
                   const ClimateProfile& p)
{
    if (hum.value() > p.humidity_too_high) {
        fan.requested_on = true;
        Serial.println(F("[Rule]   High humidity → ventilating"));
    }
}

// --- Rule 4: Scheduled ventilation (daytime only) ---
// Fan runs during the profile's scheduled window, but never at night.
void rule_scheduled_ventilation(Fan& fan, const ClimateProfile& p)
{
    if (!Clock::is_daytime()) return;   // no night ventilation

    int h = Clock::get_hour();
    if (h >= p.vent_start_h && h < p.vent_end_h) {
        fan.requested_on = true;
        Serial.println(F("[Rule]   Scheduled ventilation → fan ON"));
    }
}

// --- Aggregate: reset requested states, then apply all rules in order ---
// Add new rule calls here — nothing else in the program needs to change.
void apply_all_rules(const TemperatureSensor& temp, const HumiditySensor& hum,
                     const LightSensor& light,
                     Fan& fan, Heater& heater, Lamp& lamp,
                     const ClimateProfile& profile)
{
    // Reset all actuator requests before evaluating rules
    fan   .requested_on = false;
    heater.requested_on = false;
    lamp  .requested_on = false;

    // Apply rules (order matters: temperature sets base fan state first)
    rule_temperature          (temp, fan, heater, profile);
    rule_humidity             (hum,  fan,         profile);
    rule_scheduled_ventilation(      fan,         profile);
    rule_lighting             (light, lamp,       profile);

    // Safety check: heater must never run without fan
    if (heater.requested_on && !fan.requested_on) {
        heater.requested_on = false;
        Serial.println(F("[Safety] Heater blocked — fan not running!"));
    }
}

// ============================================================================
// SECTION 10: GLOBAL INSTANCES
// ============================================================================

// Shared low-level DHT driver (owned here, referenced by both DHT sensors)
DHTDriver dht_driver(PIN_DHT);

// --- Sensors ---
TemperatureSensor temp_sensor(dht_driver);   // reads temperature from DHT11
HumiditySensor    hum_sensor (dht_driver);   // reads air humidity from DHT11
LightSensor       light_sensor(PIN_LIGHT_SENSOR);
SoilSensor        soil_sensor (PIN_SOIL_SENSOR);

// --- Actuators ---
Fan    fan   (PIN_RELAY_FAN);
Heater heater(PIN_RELAY_HEATER);
Lamp   lamp  (PIN_RELAY_LAMP);
Pump   pump  (PIN_RELAY_PUMP);

// ============================================================================
// SECTION 11: SETUP
// ============================================================================

void setup()
{
    Serial.begin(9600);
    Serial.println(F("=== Smart Greenhouse booting ==="));
    Serial.print  (F("=== Profile: "));
    Serial.print  (active_profile->name);
    Serial.println(F(" ==="));

    // --- Sensors ---
    dht_driver  .begin();      // initialises the physical DHT11 chip
    temp_sensor .begin();      // no-op: driver handles hardware init
    hum_sensor  .begin();      // no-op: driver handles hardware init
    light_sensor.begin();
    soil_sensor .begin();

    // --- Actuators ---
    fan   .begin();
    heater.begin();
    lamp  .begin();
    pump  .begin();

    Serial.println(F("=== All devices initialised ==="));
}

// ============================================================================
// SECTION 12: MAIN LOOP
// ============================================================================


void loop()
{
    static unsigned long last_poll_ms = 0;
    unsigned long now = millis();

    if (now - last_poll_ms >= LOOP_INTERVAL_MS) {
        last_poll_ms = now;

        temp_sensor .update();    
        hum_sensor  .update();   
        light_sensor.update();
        soil_sensor .update();

        Serial.print  (F("[Sensors] Temp: "));     Serial.print(temp_sensor.value());
        Serial.print  (F(" C  AirHum: "));         Serial.print(hum_sensor.value());
        Serial.print  (F("%  Light: "));            Serial.print(light_sensor.raw_value);
        Serial.print  (F("  Soil: "));              Serial.print(soil_sensor.raw_value);
        Serial.print  (F("  Hour: "));              Serial.print(Clock::get_hour());
        Serial.print  (F("  Daytime: "));           Serial.println(Clock::is_daytime() ? "yes" : "no");

        apply_all_rules(temp_sensor, hum_sensor, light_sensor,
                        fan, heater, lamp,
                        *active_profile);


        fan   .power();
        heater.power();
        lamp  .power();
    }
    pump.update(soil_sensor, *active_profile);
}
