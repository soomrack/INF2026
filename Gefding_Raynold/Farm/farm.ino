#include <DHT.h>

// night

bool isNight = false;
unsigned long lastNightCheck = 0;

// pins

const int PIN_DHT11 = 2;
const int PIN_HEATER = 4;
const int PIN_PUMP = 5;
const int PIN_LAMP = 6;
const int PIN_FAN = 7;
const int PIN_LIGHT_SENSOR = A0;
const int PIN_SOIL_SENSOR = A1;

// ventilation parametrs - add to profile

unsigned long lastVentTime = 0;
const unsigned long ventInterval = 1800000;
const unsigned long ventDuration = 120000;
bool isVenting = false;

// sensors

class Thermometer {
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

    void read() {
        temperature = dht.readTemperature();
        humidity = dht.readHumidity();
        if (isnan(temperature)) temperature = 20.0;
        if (isnan(humidity)) humidity = 50.0;
    }
};

class SoilMoistureSensor {
private:
    int pin;
public:
    int moisture;

    SoilMoistureSensor(int pin) : pin(pin) {
        moisture = 500;
    }

    void read() {
        moisture = analogRead(pin);
    }
};

class LightSensor {
private:
    int pin;
public:
    int lightLevel;

    LightSensor(int pin) : pin(pin) {
        lightLevel = 500;
    }

    void read() {
        lightLevel = analogRead(pin);
    }
};

// actuators

class Heater {
private:
    int pin;
public:
    bool on_temperature;

    Heater(int pin) : pin(pin), on_temperature(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power()  {
        digitalWrite(pin, on_temperature ? LOW : HIGH);
    }
};

class Fan {
private:
    int pin;
public:
    bool on_temperature;

    Fan(int pin) : pin(pin), on_temperature(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power()  {
        digitalWrite(pin, on_temperature ? LOW : HIGH);
    }
};

class Lamp {
private:
    int pin;
public:
    bool on_light;

    Lamp(int pin) : pin(pin), on_light(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power()  {
        digitalWrite(pin, on_light ? LOW : HIGH);
    }
};

class Pump {
private:
    int pin;
public:
    bool on_moisture;

    Pump(int pin) : pin(pin), on_moisture(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power()  {
        digitalWrite(pin, on_moisture ? LOW : HIGH);
    }
};

// regulations

void control_temperature(const Thermometer& thermometer, Heater& heater, Fan& fan) {
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

void control_humidity(const Thermometer& thermometer, Heater& heater, Fan& fan) {
        if (thermometer.humidity > 80.0) {
            fan.on_temperature = true;
            if (thermometer.temperature < 35.0) {
                heater.on_temperature = true;
            }
        }
    }

void control_soilmoisture(const SoilMoistureSensor& soilSensor, Pump& pump) {
        if (soilSensor.moisture < 300) {
            pump.on_moisture = true;
        } else if (soilSensor.moisture > 700) {
            pump.on_moisture = false;
        }
    }

void control_light(const LightSensor& lightSensor, Lamp& lamp) {
        if (!isNight && lightSensor.lightLevel < 400) {
            lamp.on_light = true;
        } else {
            lamp.on_light = false;
        }
    }

void control_ventilation(Fan& fan) {
    if (isNight) {
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

void checkNightTime() {
    unsigned long now = millis();
    unsigned long hours = (now / 3600000UL) % 24;
    isNight = (hours >= 22 || hours < 6);
}

// setup and loop

Thermometer thermometer(PIN_DHT11);
SoilMoistureSensor soilSensor(PIN_SOIL_SENSOR);
LightSensor lightSensor(PIN_LIGHT_SENSOR);
Heater heater(PIN_HEATER);
Fan fan(PIN_FAN);
Lamp lamp(PIN_LAMP);
Pump pump(PIN_PUMP);

void setup() {
    Serial.begin(9600);
}

void loop() {
    
    checkNightTime();

    thermometer.read();
    soilSensor.read();
    lightSensor.read();

    control_temperature(thermometer, heater, fan);
    control_humidity(thermometer, heater, fan);
    control_soilmoisture(soilSensor, pump);
    control_light(lightSensor, lamp);
    control_ventilation(fan);

    heater.power();
    fan.power();
    lamp.power();
    pump.power();

    delay(1000);
}
