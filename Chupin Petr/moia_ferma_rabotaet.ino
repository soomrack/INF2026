#include <DHT.h>

const int PIN_DHT = 8;
const int PIN_HEATER = 4;
const int PIN_PUMP = 5;
const int PIN_LAMP = 6;
const int PIN_FAN = 7;
const int PIN_LIGHT = A1;
const int PIN_SOIL = A3;

float maxTemp = 32.0;
float minTemp = 19.0;
float maxHum = 75.0;
float humTempLimit = 34.0;
int soilDry = 350;
int soilWet = 650;
int lightThreshold = 400;

unsigned long ventInterval = 1500000;
unsigned long ventDuration = 90000;
unsigned long pumpDuration = 5000;
unsigned long pumpRest = 200000;

bool isNightTime = false;
unsigned long ventilationStartTime = 0;
bool ventInProgress = false;
unsigned long pumpLastWorkTime = 0;
bool pumpDelayActive = false;

bool heaterVentForced = false;
unsigned long heaterVentStartTime = 0;
bool heaterPrevState = false;

int cycleCounter = 0;

class ISensor {
public:
    virtual void update() = 0;
};

class IActuator {
public:
    virtual void power() = 0;
};

class DHTReader : public ISensor {
private:
    DHT dhtDevice;
public:
    float temperature = 0.0;
    float humidity = 0.0;
    
    DHTReader(int pinNumber) : dhtDevice(pinNumber, DHT11) {
        dhtDevice.begin();
    }
    
    void update() {
        temperature = dhtDevice.readTemperature();
        humidity = dhtDevice.readHumidity();
    }
};

class SoilSensor : public ISensor {
private:
    int pin;
public:
    int moisture = 500;
    
    SoilSensor(int pinNum) {
        pin = pinNum;
        pinMode(pin, INPUT);
    }
    
    void update() {
        moisture = analogRead(pin);
    }
};

class LightSensor : public ISensor {
private:
    int pin;
public:
    int lightLevel = 500;
    
    LightSensor(int pinNum) {
        pin = pinNum;
        pinMode(pin, INPUT);
    }
    
    void update() {
        lightLevel = analogRead(pin);
    }
};

class Device : public IActuator {
private:
    int pin;
public:
    bool state = false;
    
    Device(int pinNum) {
        pin = pinNum;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
    
    void power() {
        if (state == true) {
            digitalWrite(pin, HIGH);
        } else {
            digitalWrite(pin, LOW);
        }
    }
};

void updateTimeStatus() {
    cycleCounter = cycleCounter + 1;
    if (cycleCounter < 100) {
        isNightTime = false;
    } 
    else if (cycleCounter < 200) {
        isNightTime = true;
    } 
    else {
        cycleCounter = 0;
    }
}

void controlClimate(DHTReader &dht, Device &fan, Device &heater) {
    fan.state = false;
    heater.state = false;

    if (dht.temperature > maxTemp) {
        fan.state = true;
    } 
    else if (dht.temperature < minTemp) {
        heater.state = true;
        fan.state = true;
    }

    if (dht.humidity > maxHum) {
        fan.state = true;
        if (dht.temperature < humTempLimit) {
            heater.state = true;
        }
    }

    if (isNightTime == false) {
        unsigned long currentTime = millis();
        if (ventInProgress == false && (currentTime - ventilationStartTime >= ventInterval)) {
            ventInProgress = true;
            ventilationStartTime = currentTime;
        }
        if (ventInProgress == true && (currentTime - ventilationStartTime >= ventDuration)) {
            ventInProgress = false;
        }
        if (ventInProgress == true) {
            fan.state = true;
        }
    } else {
        ventInProgress = false;
    }

    unsigned long currentTime = millis();
    bool currentHeaterState = heater.state;
    if (currentHeaterState != heaterPrevState) {
        heaterVentForced = true;
        heaterVentStartTime = currentTime;
        heaterPrevState = currentHeaterState;
    }
    if (heaterVentForced == true) {
        if (currentTime - heaterVentStartTime >= 20000) {
            heaterVentForced = false;
        } else {
            fan.state = true;
        }
    }

    if (isNightTime == true) {
        fan.state = false;
    }
}

void controlWater(SoilSensor &soil, Device &pump) {
    unsigned long now = millis();
    
    if (pumpDelayActive == true) {
        if (now - pumpLastWorkTime >= pumpRest) {
            pumpDelayActive = false;
        }
    }

    if (soil.moisture < soilDry) { 
        if (pumpDelayActive == false) {
            if (pump.state == false) {
                pumpLastWorkTime = now;
                pump.state = true;
            }
            if (now - pumpLastWorkTime >= pumpDuration) {
                pump.state = false;
                pumpDelayActive = true;
                pumpLastWorkTime = now;
            }
        }
    } 
    else if (soil.moisture > soilWet) { 
        pump.state = false;
    }
}

void controlLight(LightSensor &light, Device &lamp) {
    if (isNightTime == false && light.lightLevel < lightThreshold) {
        lamp.state = true;
    } else {
        lamp.state = false;
    }
}

DHTReader mainDht(PIN_DHT);
SoilSensor soilSensor(PIN_SOIL);
LightSensor lightSensor(PIN_LIGHT);

Device fan(PIN_FAN);
Device heater(PIN_HEATER);
Device lamp(PIN_LAMP);
Device pump(PIN_PUMP);

void setup() {
    Serial.begin(9600);
    delay(2000); 
}

void loop() {
    updateTimeStatus();
    
    mainDht.update();
    soilSensor.update();
    lightSensor.update();

    controlClimate(mainDht, fan, heater);
    controlWater(soilSensor, pump);
    controlLight(lightSensor, lamp);

    if (pump.state == true) {
        heater.state = false; 
    }

    fan.power();
    heater.power();
    lamp.power();
    pump.power();

    delay(2000);
}
