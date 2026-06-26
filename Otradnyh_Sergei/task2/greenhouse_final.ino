#include <DHT.h>

class Thermometer {
private:
    DHT dht;
public:
    float temperature;  // Celsius
    float humidity;     // %
public:
    Thermometer(int pin) : dht(pin, DHT11) { temperature = 0; humidity = 0; }
public:
    void begin() { dht.begin(); }
public:
    void get_temperature() {
        float t = dht.readTemperature();
        float h = dht.readHumidity();
        if (!isnan(t)) { temperature = t; }
        if (!isnan(h)) { humidity = h; }
    }
};

class Light {
private:
    int pin;
public:
    int light;
public:
    Light(int pin) : pin(pin) { light = 0; }
public:
    void get_light() {
        light = analogRead(pin);
    }
};

class SoilMoisture {
private:
    int pin;
public:
    int moisture;
public:
    SoilMoisture(int pin) : pin(pin) { moisture = 0; }
public:
    void get_moisture() {
        moisture = analogRead(pin);
    }
};

class Heater {
private:
    int pin;
public:
    bool on_temperature;
public:
    Heater(int pin) : pin(pin) {
        on_temperature = false;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
public:
    void power() {
        if (on_temperature) { digitalWrite(pin, HIGH); }
        else { digitalWrite(pin, LOW); }
    }
};

class Fan {
private:
    int pin;
public:
    bool on_temperature;
public:
    Fan(int pin) : pin(pin) {
        on_temperature = false;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
public:
    void power() {
        if (on_temperature) { digitalWrite(pin, HIGH); }
        else { digitalWrite(pin, LOW); }
    }
};

class Lamp {
private:
    int pin;
public:
    bool on_light;
public:
    Lamp(int pin) : pin(pin) {
        on_light = false;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
public:
    void power() {
        if (on_light) { digitalWrite(pin, HIGH); }
        else { digitalWrite(pin, LOW); }
    }
};

class Pump {
private:
    int pin;
public:
    bool on_moisture;
public:
    Pump(int pin) : pin(pin) {
        on_moisture = false;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
public:
    void power() {
        if (on_moisture) { digitalWrite(pin, HIGH); }
        else { digitalWrite(pin, LOW); }
    }
};


void control_temperature(const Thermometer& thermometer, Heater& heater, Fan& fan)
{
    if (thermometer.temperature > 30) {
        heater.on_temperature = false;
        fan.on_temperature = true;
        return;
    }
    if (thermometer.temperature < 27) {
        heater.on_temperature = true;
        fan.on_temperature = true;
        return;
    }
    heater.on_temperature = false;
    fan.on_temperature = false;
}

void control_light(const Light& light, Lamp& lamp)
{
    if (light.light > 850) {
        lamp.on_light = true;
        return;
    }
    if (light.light < 750) {
        lamp.on_light = false;
        return;
    }
}

void control_moisture(const SoilMoisture& soil, Pump& pump)
{
    static unsigned long pumpTimer = 0;
    static int pumpState = 0;

    if (pumpState == 0) {
        if (soil.moisture < 400) {
            pump.on_moisture = true;
            pumpTimer = millis();
            pumpState = 1;
        } else if (soil.moisture > 700) {
            pump.on_moisture = false;
        }
    }
    else if (pumpState == 1) {
        if (millis() - pumpTimer >= 3000) {
            pump.on_moisture = false;
            pumpTimer = millis();
            pumpState = 2;
        }
    }
    else if (pumpState == 2) {
        if (millis() - pumpTimer >= 120000) {
            pumpState = 0;
        }
    }
}

// A0 — фоторезистор, A1 — влажность почвы, D12 — DHT11 (температура + влажность)
// D4 — обогреватель, D5 — насос, D6 — лампа, D7 — вентилятор

Thermometer thermometer(12);
Light light(A0);
SoilMoisture soil(A1);

Heater heater(4);
Pump pump(5);
Lamp lamp(6);
Fan fan(7);

void print_serial_data() {
    Serial.print("Temp: ");
    Serial.print(thermometer.temperature);
    Serial.print(" C | Hum: ");
    Serial.print(thermometer.humidity);
    Serial.print(" % | Light: ");
    Serial.print(light.light);
    Serial.print(" | Soil: ");
    Serial.print(soil.moisture);
    Serial.print(" | H:");
    Serial.print(heater.on_temperature);
    Serial.print(" F:");
    Serial.print(fan.on_temperature);
    Serial.print(" L:");
    Serial.print(lamp.on_light);
    Serial.print(" P:");
    Serial.println(pump.on_moisture);
}

void setup()
{
    analogReference(DEFAULT);
    Serial.begin(9600);
    thermometer.begin();
}

void loop()
{
    thermometer.get_temperature();
    light.get_light();
    soil.get_moisture();

    control_temperature(thermometer, heater, fan);
    control_light(light, lamp);
    control_moisture(soil, pump);

    heater.power();
    fan.power();
    lamp.power();
    pump.power();

    print_serial_data();

    delay(1500);
}