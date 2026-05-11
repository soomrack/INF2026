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

class Fan {
private:
    int pin;
    bool currentState = false;
public:
    bool requestFanTemp = false;
    bool requestFanHum  = false;
    bool requestFanVent = false;

    Fan(int pin) : pin(pin) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() {
        if (isNight) {
            digitalWrite(pin, LOW);
            currentState = false;
            return;
        }
        bool shouldFan = requestFanTemp || requestFanHum || requestFanVent;
        digitalWrite(pin, shouldFan ? LOW : HIGH);
        currentState = shouldFan;
    }

    bool isOn() const { return currentState; }
};

class Heater {
private:
    int pin;
    Fan& fan;
public:
    bool requestHeatTemp = false;
    bool requestHeatHum  = false;

    Heater(int pin, Fan& fanRef) : pin(pin), fan(fanRef) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() {
        bool shouldHeat = (requestHeatTemp || requestHeatHum) && fan.isOn();
        digitalWrite(pin, shouldHeat ? LOW : HIGH);
    }
};

class Lamp {
private:
    int pin;
public:
    bool requestLight = false;

    Lamp(int pin) : pin(pin){
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power()  {
        digitalWrite(pin, requestLight ? LOW : HIGH);
    }
};

class Pump {
private:
    int pin;
public:
    bool requestPump = false; 

    Pump(int pin) : pin(pin){
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power()  {
        digitalWrite(pin, requestPump ? LOW : HIGH);
    }
};

// regulations

void control_temperature(const TemperatureSensor& temperatureSensor, Heater& heater, Fan& fan, const Profile& profile) {
    if (temperatureSensor.value > profile.tempHigh) {
        heater.requestHeatTemp = false;
        fan.requestFanTemp = true;
    }
    else if (temperatureSensor.value < profile.tempLow) {
        heater.requestHeatTemp = true;
        fan.requestFanTemp = true;
    }
    else {
        heater.requestHeatTemp = false;
        fan.requestFanTemp = false;
    }
}

void control_humidity(const HumiditySensor& humiditySensor, const TemperatureSensor& temperatureSensor, Heater& heater, Fan& fan, const Profile& profile) {
    if (humiditySensor.value > profile.humHigh) {
        fan.requestFanHum = true;
        if (temperatureSensor.value < profile.humTempLimit) {
            heater.requestHeatHum = true;
        } else {
            heater.requestHeatHum = false;
        }
    } else {
        fan.requestFanHum = false;
        heater.requestHeatHum = false;
    }
}

void control_soilmoisture(const SoilMoistureSensor& soilSensor, Pump& pump, const Profile& profile) {
    if (soilSensor.moisture < profile.soilLow) {
        pump.requestPump = true;
    } else if (soilSensor.moisture > profile.soilHigh) {
        pump.requestPump = false;
    }
}

void control_light(const LightSensor& lightSensor, Lamp& lamp, const Profile& profile) {
    if (!isNight && lightSensor.lightLevel < profile.lightThreshold) {
        lamp.requestLight = true;
    } else {
        lamp.requestLight = false;
    }
}

void control_ventilation(Fan& fan, const Profile& profile) {
    if (isNight) {
        isVenting = false;
        fan.requestFanVent = false;
        return;
    }

    unsigned long now = millis();

    if (!isVenting && (now - lastVentTime >= profile.ventInterval)) {
        isVenting = true;
        lastVentTime = now;
        fan.requestFanVent = true;
    }

    if (isVenting && (now - lastVentTime >= profile.ventDuration)) {
        isVenting = false;
        fan.requestFanVent = false;
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
Fan fan(PIN_FAN);
Heater heater(PIN_HEATER, fan);
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

    fan.power();
    heater.power();
    lamp.power();
    pump.power();

    delay(1000);
}
