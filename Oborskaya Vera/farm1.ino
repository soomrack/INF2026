#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>


#define PIN_DHT 2    
#define PIN_SOIL A0   
#define PIN_LIGHT A1   

#define PIN_FAN 7
#define PIN_HEATER 4
#define PIN_LAMP 6
#define PIN_PUMP 5

class Sensor {
public:
    virtual void update() = 0;
    virtual float getValue() const = 0;
};

class Actuator {
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void power() = 0;
    virtual bool isOn() const = 0;
};

class DHTSensor : public Sensor {
private:
    DHT dht;
    float temperature;
    float humidity;
public:
    DHTSensor(int pin) : dht(pin, DHT11), temperature(25.0), humidity(50.0) {
        dht.begin();
    }
    void update() override {
        float t = dht.readTemperature();
        float h = dht.readHumidity();
        if (!isnan(t)) temperature = t;
        if (!isnan(h)) humidity = h;
    }
    float getTemperature() const { return temperature; }
    float getHumidity() const { return humidity; }
    float getValue() const override { return temperature; }
};

class SoilSensor : public Sensor {
private:
    int pin;
    int moisture;
public:
    SoilSensor(int p) : pin(p), moisture(500) {}
    void update() override {
        moisture = analogRead(pin);
    }
    int getMoisture() const { return moisture; }
    float getValue() const override { return moisture; }
};

class LightSensor : public Sensor {
private:
    int pin;
    int lightLevel;
public:
    LightSensor(int p) : pin(p), lightLevel(500) {}
    void update() override {
        lightLevel = analogRead(pin);
    }
    int getLightLevel() const { return lightLevel; }
    float getValue() const override { return lightLevel; }
};

class Fan : public Actuator {
private:
    int pin;
    bool state;
    bool needFromTemp;
    bool needFromHum;
    bool needFromSched;
    bool needFromHeater;
    bool needFromStart;

public:
    Fan(int p) : pin(p), state(false), needFromTemp(false), needFromHum(false),
        needFromSched(false), needFromHeater(false) {
        pinMode(pin, OUTPUT);
        off();
    }

    void on() override {
        digitalWrite(pin, HIGH);
        state = true;
    }

    void off() override {
        digitalWrite(pin, LOW);
        state = false;
    }

    bool isOn() const override { return state; }

    void setNeedFromTemp(bool value) { needFromTemp = value; }
    void setNeedFromHum(bool value) { needFromHum = value; }
    void setNeedFromSched(bool value) { needFromSched = value; }
    void setNeedFromHeater(bool value) { needFromHeater = value; }
    void setNeedFromStart(bool value) { needFromStart = value; }

    bool getNeedFromTemp() const { return needFromTemp; }
    bool getNeedFromHum() const { return needFromHum; }
    bool getNeedFromSched() const { return needFromSched; }
    bool getNeedFromHeater() const { return needFromHeater; }
    bool getNeedFromStart() const { return needFromStart; }

    void power() override {
        if (needFromTemp || needFromHum || needFromSched || needFromHeater || needFromStart) {
            on();
        }
        else {
            off();
        }
    }

    void resetFlags() {
        needFromTemp = false;
        needFromHum = false;
        needFromSched = false;
        needFromHeater = false;
        needFromStart = false;
    }
};

class Heater : public Actuator {
private:
    int pin;
    bool state;
    bool needFromTemp;

public:
    Heater(int p) : pin(p), state(false), needFromTemp(false) {
        pinMode(pin, OUTPUT);
        off();
    }

    void on() override {
        digitalWrite(pin, HIGH);
        state = true;
    }

    void off() override {
        digitalWrite(pin, LOW);
        state = false;
    }

    bool isOn() const override { return state; }

    void setNeedFromTemp(bool value) { needFromTemp = value; }
    bool getNeedFromTemp() const { return needFromTemp; }

    void power() override {
        if (needFromTemp) {
            on();
        }
        else {
            off();
        }
    }

    void resetFlags() {
        needFromTemp = false;
    }
};

class Lamp : public Actuator {
private:
    int pin;
    bool state;
    bool needFromLight;

public:
    Lamp(int p) : pin(p), state(false), needFromLight(false) {
        pinMode(pin, OUTPUT);
        off();
    }

    void on() override {
        digitalWrite(pin, HIGH);
        state = true;
    }

    void off() override {
        digitalWrite(pin, LOW);
        state = false;
    }

    bool isOn() const override { return state; }

    void setNeedFromLight(bool value) { needFromLight = value; }

    void power() override {
        if (needFromLight) {
            on();
        }
        else {
            off();
        }
    }

    void resetFlags() {
        needFromLight = false;
    }
};

class Pump : public Actuator {
private:
    int pin;
    bool state;
    bool needFromSoil;

    unsigned long pumpStartTime;
    unsigned long pumpOffTime;
    bool isPumping;
    bool isWaiting;

    const unsigned long PUMP_DURATION = 2000;
    const unsigned long PUMP_COOLDOWN = 2000;

public:
    Pump(int p) : pin(p), state(false), needFromSoil(false),
        pumpStartTime(0), pumpOffTime(0), isPumping(false), isWaiting(false) {
        pinMode(pin, OUTPUT);
        off();
    }

    void on() override {
        digitalWrite(pin, HIGH);
        state = true;
    }

    void off() override {
        digitalWrite(pin, LOW);
        state = false;
    }

    bool isOn() const override { return state; }

    void setNeedFromSoil(bool value) {
        needFromSoil = value;
    }

    bool getNeedFromSoil() const { return needFromSoil; }

    void power() override {
        unsigned long currentTime = millis();

        if (isPumping) {
            if (currentTime - pumpStartTime >= PUMP_DURATION) {

                off();
                isPumping = false;
                isWaiting = true;
                pumpOffTime = currentTime;
                needFromSoil = false;
            }
        }

        else if (isWaiting) {
            if (currentTime - pumpOffTime >= PUMP_COOLDOWN) {
                isWaiting = false;
            }
        }
        else {
            if (needFromSoil) {
                pumpStartTime = currentTime;
                isPumping = true;
                on();
            }
            else {
                off();
            }
        }
    }

    void resetFlags() {
        if (!isPumping && !isWaiting) {
            needFromSoil = false;
        }
    }

    bool isPumpingNow() const { return isPumping; }
    bool isCoolingDown() const { return isWaiting; }
};

class Clock {
private:
    unsigned long lastMillis;
    unsigned long virtualTime;
    const unsigned long DAY_DURATION = 86400;
public:
    Clock() : lastMillis(0), virtualTime(43200) {}

    void update() {
        unsigned long now = millis();
        unsigned long delta = now - lastMillis;
        if (lastMillis == 0) {
            lastMillis = now;
            return;
        }
        const int ACCEL = 60;
        virtualTime += (delta / 1000) * ACCEL;
        virtualTime %= DAY_DURATION;
        lastMillis = now;
    }

    bool isNight(int nightStartHour, int nightEndHour) const {
        unsigned long seconds = virtualTime;
        unsigned long nightStartSec = (unsigned long)nightStartHour * 3600;
        unsigned long nightEndSec = (unsigned long)nightEndHour * 3600;
        if (nightStartSec < nightEndSec) {
            return (seconds >= nightStartSec && seconds < nightEndSec);
        }
        else {
            return (seconds >= nightStartSec || seconds < nightEndSec);
        }
    }

    int getHour() const { return virtualTime / 3600; }
};

struct Climate {
    float tempHigh;
    float tempLow;
    int soilDry;
    int soilWet;
    float humidityHigh;
    int lightLow;
    unsigned long ventilationInterval;
    unsigned long ventilationDuration;
    int nightStart;
    int nightEnd;
};

class ScheduledVentilation {
private:
    unsigned long lastStartTime;
    bool active;
public:
    ScheduledVentilation() : lastStartTime(0), active(false) {}

    void update(Fan& fan, const Climate& profile, Clock& clock) {
        unsigned long now = millis();

        if (clock.isNight(profile.nightStart, profile.nightEnd)) {
            if (active) {
                active = false;
            }
            return;
        }

        if (!active && (now - lastStartTime >= profile.ventilationInterval)) {
            active = true;
            lastStartTime = now;
        }

        if (active && (now - lastStartTime >= profile.ventilationDuration)) {
            active = false;
        }

        fan.setNeedFromSched(active);
    }

    bool isActive() const { return active; }
};

class StartupVentilation {
private:
    unsigned long endTime;   
    bool active;            

public:
    StartupVentilation() : endTime(0), active(false) {}
    void begin(unsigned long durationMs) {
        endTime = millis() + durationMs;
        active = true;
    }

    void update(Fan& fan) {
        if (!active) return;                   

        if (millis() < endTime) {
            fan.setNeedFromStart(true);        
        } else {
            active = false;                   
        }
    }

    bool isActive() const { return active; }
};

void controlLight(LightSensor& light, Lamp& lamp, Clock& clock, const Climate& profile) {
    bool isNight = clock.isNight(profile.nightStart, profile.nightEnd);

    lamp.setNeedFromLight(!isNight && (light.getLightLevel() < profile.lightLow));
}

void controlSoil(SoilSensor& soil, Pump& pump, const Climate& profile) {
    int moisture = soil.getMoisture();

    if (!pump.isCoolingDown() && !pump.isPumpingNow()) {
        pump.setNeedFromSoil(moisture < profile.soilDry);
    }
}

void controlTemperature(Fan& fan, DHTSensor& dht, Heater& heater, const Climate& profile) {
    float temp = dht.getTemperature();

    heater.setNeedFromTemp(temp < profile.tempLow);

    fan.setNeedFromHeater(heater.getNeedFromTemp());
    fan.setNeedFromTemp(temp > profile.tempHigh);
}

void controlHum(Fan& fan, DHTSensor& dht, const Climate& profile) {
    float hum = dht.getHumidity();

    fan.setNeedFromHum(hum > profile.humidityHigh);
}


Climate current_climate = {
    .tempHigh = 27.0,
    .tempLow = 21.0,
    .soilDry = 400,
    .soilWet = 700,
    .humidityHigh = 75.0,
    .lightLow = 400,
    .ventilationInterval = 1800000,   
    .ventilationDuration = 120000,    
    .nightStart = 22,
    .nightEnd = 6
};

DHTSensor dht(PIN_DHT);
SoilSensor soil(PIN_SOIL);
LightSensor light(PIN_LIGHT);

Fan fan(PIN_FAN);
Heater heater(PIN_HEATER);
Lamp lamp(PIN_LAMP);
Pump pump(PIN_PUMP);

Clock clock;
ScheduledVentilation scheduledVent;
StartupVentilation startupVent;

void print_status() {
    static unsigned long lastPrint = 0;
    if (millis() - lastPrint > 2000) {
        float temp = dht.getTemperature();
        float hum = dht.getHumidity();
        int moisture = soil.getMoisture();
        int lux = light.getLightLevel();
        Serial.print(F("T=")); Serial.print(temp); Serial.print(F("°C H=")); Serial.print(hum); Serial.print(F("% Soil="));
        Serial.print(moisture); Serial.print(F(" Light=")); Serial.print(lux);
        Serial.print(F(" | Heat:")); Serial.print(heater.isOn() ? "1" : "0");
        Serial.print(F(" Fan:")); Serial.print(fan.isOn() ? "1" : "0");
        Serial.print(F(" Lamp:")); Serial.print(lamp.isOn() ? "1" : "0");
        Serial.print(F(" Pump:")); Serial.print(pump.isOn() ? "1" : "0");
        Serial.print(F(" Night:")); Serial.print(clock.isNight(current_climate.nightStart, current_climate.nightEnd) ? "Y" : "N");
        Serial.println();
        lastPrint = millis();
    }
}

void setup() {
    Serial.begin(9600);
    Serial.println(F("Умная теплица запущена"));
    startupVent.begin(30000);
    delay(1000);
}

void loop() {

    lamp.resetFlags();
    pump.resetFlags();
    heater.resetFlags();
    fan.resetFlags();

    dht.update();
    soil.update();
    light.update();
    clock.update();
    scheduledVent.update(fan, current_climate, clock);
    startupVent.update(fan); 
    
    controlLight(light, lamp, clock, current_climate);
    controlSoil(soil, pump, current_climate);
    controlTemperature(fan, dht, heater, current_climate);
    controlHum(fan, dht, current_climate);

    lamp.power();
    pump.power();
    heater.power();
    fan.power();

    print_status();

    delay(500);
}
