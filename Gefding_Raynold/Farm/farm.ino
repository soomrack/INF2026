#include <DHT.h>

// pins

const int PIN_DHT11 = 2;
const int PIN_HEATER = 4;
const int PIN_PUMP = 5;
const int PIN_LAMP = 6;
const int PIN_FAN = 7;
const int PIN_LIGHT_SENSOR = A0;
const int PIN_SOIL_SENSOR = A1;

// classes

class Sensor {
public:
    virtual void read() = 0;
    virtual ~Sensor() {}
};

class Actuator {
public:
    virtual void power() = 0;
    virtual ~Actuator() {}
};

class RegulationAlgorithm {
public:
    virtual void control() = 0;
    virtual ~RegulationAlgorithm() {}
};

// sensors

class Thermometer : public Sensor {
private:
    DHT dht;
public:
    float temperature;
    float humidity;

    Thermometer(int pin) : dht(pin, DHT11) {
        dht.begin();
        temperature = 20.0;
        humidity = 50.0;
    }

    void read() override {
        temperature = dht.readTemperature();
        humidity = dht.readHumidity();
        if (isnan(temperature)) temperature = 20.0;
        if (isnan(humidity)) humidity = 50.0;
    }
};

class SoilMoistureSensor : public Sensor {
private:
    int pin;
public:
    int moisture;

    SoilMoistureSensor(int pin) : pin(pin) {
        moisture = 500;
    }

    void read() override {
        moisture = analogRead(pin);
    }
};

class LightSensor : public Sensor {
private:
    int pin;
public:
    int lightLevel;

    LightSensor(int pin) : pin(pin) {
        lightLevel = 500;
    }

    void read() override {
        lightLevel = analogRead(pin);
    }
};

// actuatorots

class Heater : public Actuator {
private:
    int pin;
public:
    bool on_temperature;

    Heater(int pin) : pin(pin), on_temperature(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() override {
        digitalWrite(pin, on_temperature ? LOW : HIGH);
    }
};

class Fan : public Actuator {
private:
    int pin;
public:
    bool on_temperature;

    Fan(int pin) : pin(pin), on_temperature(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() override {
        digitalWrite(pin, on_temperature ? LOW : HIGH);
    }
};

class Lamp : public Actuator {
private:
    int pin;
public:
    bool on_light;

    Lamp(int pin) : pin(pin), on_light(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() override {
        digitalWrite(pin, on_light ? LOW : HIGH);
    }
};

class Pump : public Actuator {
private:
    int pin;
public:
    bool on_moisture;

    Pump(int pin) : pin(pin), on_moisture(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() override {
        digitalWrite(pin, on_moisture ? LOW : HIGH);
    }
};

// regulations

class TemperatureRegulation : public RegulationAlgorithm {
private:
    Thermometer& thermometer;
    Heater& heater;
    Fan& fan;
public:
    TemperatureRegulation(Thermometer& t, Heater& h, Fan& f)
        : thermometer(t), heater(h), fan(f) {}

    void control() override {
        if (thermometer.temperature > 30.0) {
            heater.on_temperature = false;
            fan.on_temperature = true;
        }
        else if (thermometer.temperature < 20.0) {
            heater.on_temperature = true;
            fan.on_temperature = true;
        }
        else {
            heater.on_temperature = false;
            fan.on_temperature = false;
        }
    }
};

class HumidityRegulation : public RegulationAlgorithm {
private:
    Thermometer& thermometer;
    Fan& fan;
    Heater& heater;
public:
    HumidityRegulation(Thermometer& t, Fan& f, Heater& h)
        : thermometer(t), fan(f), heater(h) {}

    void control() override {
        if (thermometer.humidity > 80.0) {
            fan.on_temperature = true;
            if (thermometer.temperature < 35.0) {
                heater.on_temperature = true;
            }
        }
    }
};

class SoilMoistureRegulation : public RegulationAlgorithm {
private:
    SoilMoistureSensor& soilSensor;
    Pump& pump;
public:
    SoilMoistureRegulation(SoilMoistureSensor& s, Pump& p)
        : soilSensor(s), pump(p) {}

    void control() override {
        if (soilSensor.moisture < 300) {
            pump.on_moisture = true;
        } else if (soilSensor.moisture > 700) {
            pump.on_moisture = false;
        }
    }
};

class LightRegulation : public RegulationAlgorithm {
private:
    LightSensor& lightSensor;
    Lamp& lamp;
    bool isNightTime;
public:
    LightRegulation(LightSensor& l, Lamp& la)
        : lightSensor(l), lamp(la), isNightTime(false) {}

    void setNightTime(bool night) {
        isNightTime = night;
    }

    void control() override {
        if (!isNightTime && lightSensor.lightLevel < 400) {
            lamp.on_light = true;
        } else {
            lamp.on_light = false;
        }
    }
};

class ScheduledVentilation : public RegulationAlgorithm {
private:
    Fan& fan;
    unsigned long lastVentTime;
    const unsigned long ventInterval;
    const unsigned long ventDuration;
    bool isVenting;
    bool isNightTime;
public:
    ScheduledVentilation(Fan& f, unsigned long interval = 1800000, unsigned long duration = 120000)
        : fan(f), ventInterval(interval), ventDuration(duration),
          lastVentTime(0), isVenting(false), isNightTime(false) {}

    void setNightTime(bool night) {
        isNightTime = night;
    }

    void control() override {
        if (isNightTime) {
            if (isVenting) {
                isVenting = false;
                fan.on_temperature = false;
            }
            return;
        }

        unsigned long now = millis();

        if (!isVenting && (now - lastVentTime >= ventInterval)) {
            isVenting = true;
            lastVentTime = now;
            fan.on_temperature = true;
        }

        if (isVenting && (now - lastVentTime >= ventDuration)) {
            isVenting = false;
            fan.on_temperature = false;
        }
    }
};

// global objects

Thermometer thermometer(PIN_DHT11);
SoilMoistureSensor soilSensor(PIN_SOIL_SENSOR);
LightSensor lightSensor(PIN_LIGHT_SENSOR);

Heater heater(PIN_HEATER);
Fan fan(PIN_FAN);
Lamp lamp(PIN_LAMP);
Pump pump(PIN_PUMP);

TemperatureRegulation tempReg(thermometer, heater, fan);
HumidityRegulation humReg(thermometer, fan, heater);
SoilMoistureRegulation soilReg(soilSensor, pump);
LightRegulation lightReg(lightSensor, lamp);
ScheduledVentilation ventReg(fan);

bool isNight = false;
unsigned long lastNightCheck = 0;

void checkNightTime() {
    unsigned long now = millis();
    unsigned long hours = (now / 3600000UL) % 24;
    isNight = (hours >= 22 || hours < 6);
}

// setup and loop

void setup() {
    Serial.begin(9600);
}


void loop() {
    checkNightTime();
    lightReg.setNightTime(isNight);
    ventReg.setNightTime(isNight);

    thermometer.read();
    soilSensor.read();
    lightSensor.read();

    tempReg.control();
    humReg.control();
    soilReg.control();
    lightReg.control();
    ventReg.control();

    heater.power();
    fan.power();
    lamp.power();
    pump.power();

    delay(1000);
}
