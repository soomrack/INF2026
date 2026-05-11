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

// ventilation

unsigned long lastVentTime = 0;
bool isVenting = false;

// profiles

struct Profile {
    float tempHigh;
    float tempLow;

    float humHigh;
    float humTempLimit;

    int soilLow;
    int soilHigh;

    int lightThreshold;

    unsigned long ventInterval;
    unsigned long ventDuration;
};

const Profile profiles[] = {
    {
        // profile 1
        30.0, 20.0,       // tempHigh, tempLow
        80.0, 35.0,       // humHigh, humTempLimit
        300, 700,         // soilLow, soilHigh
        400,              // lightThreshold
        1800000, 120000   // ventInterval, ventDuration
    },
    {
        // profile 2
        28.0, 18.0,       // tempHigh, tempLow
        70.0, 30.0,       // humHigh, humTempLimit
        400, 600,         // soilLow, soilHigh
        300,              // lightThreshold
        3600000, 180000   // ventInterval, ventDuration
    }
};

// sensors

class DHTReader {
private:
    DHT dht;
public:
    float temperature;
    float humidity;

    DHTReader(int pin) : dht(pin, DHT11) {
        dht.begin();
        temperature = 20.0;
        humidity = 50.0;
    }

    void update() {
        temperature = dht.readTemperature();
        humidity = dht.readHumidity();
        if (isnan(temperature)) temperature = 20.0;
        if (isnan(humidity)) humidity = 50.0;
    }
};

class TemperatureSensor {
private:
    DHTReader& dhtReader;
public:
    float value;

    TemperatureSensor(DHTReader& readerRef) : dhtReader(readerRef), value(20.0) {}

    void read() {
        value = dhtReader.temperature;
    }
};

class HumiditySensor {
private:
    DHTReader& dhtReader;
public:
    float value;

    HumiditySensor(DHTReader& readerRef) : dhtReader(readerRef), value(50.0) {}

    void read() {
        value = dhtReader.humidity;
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

void control_temperature(const TemperatureSensor& temperatureSensor, Heater& heater, Fan& fan, const Profile& profile) {
    if (temperatureSensor.value > profile.tempHigh) {
        heater.on_temperature = false;
        fan.on_temperature = true;
    }
    else if (temperatureSensor.value < profile.tempLow) {
        heater.on_temperature = true;
        fan.on_temperature = true;
    }
    else {
        heater.on_temperature = false;
        fan.on_temperature = false;
    }
}

void control_humidity(const HumiditySensor& humiditySensor, const TemperatureSensor& temperatureSensor, Heater& heater, Fan& fan, const Profile& profile) {
        if (humiditySensor.value > profile.humHigh) {
            fan.on_temperature = true;
            if (temperatureSensor.value < profile.humTempLimit) {
                heater.on_temperature = true;
            }
        }
    }

void control_soilmoisture(const SoilMoistureSensor& soilSensor, Pump& pump, const Profile& profile) {
        if (soilSensor.moisture < profile.soilLow) {
            pump.on_moisture = true;
        } else if (soilSensor.moisture > profile.soilHigh) {
            pump.on_moisture = false;
        }
    }

void control_light(const LightSensor& lightSensor, Lamp& lamp, const Profile& profile) {
        if (!isNight && lightSensor.lightLevel < profile.lightThreshold) {
            lamp.on_light = true;
        } else {
            lamp.on_light = false;
        }
    }

void control_ventilation(Fan& fan, const Profile& profile) {
    if (isNight) {
            if (isVenting) {
                isVenting = false;
                fan.on_temperature = false;
            }
            return;
        }

        unsigned long now = millis();

        if (!isVenting && (now - lastVentTime >= profile.ventInterval)) {
            isVenting = true;
            lastVentTime = now;
            fan.on_temperature = true;
        }

        if (isVenting && (now - lastVentTime >= profile.ventDuration)) {
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

DHTReader dhtReader(PIN_DHT11);
TemperatureSensor temperature(dhtReader);
HumiditySensor airHumidity(dhtReader);
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
    const Profile& currentProfile = profiles[0];
    
    checkNightTime();
    dhtReader.update();

    temperature.read();
    airHumidity.read();
    soilSensor.read();
    lightSensor.read();

    control_temperature(temperature, heater, fan, currentProfile);
    control_humidity(airHumidity, temperature, heater, fan, currentProfile);
    control_soilmoisture(soilSensor, pump, currentProfile);
    control_light(lightSensor, lamp, currentProfile);
    control_ventilation(fan, currentProfile);

    heater.power();
    fan.power();
    lamp.power();
    pump.power();

    delay(1000);
}
