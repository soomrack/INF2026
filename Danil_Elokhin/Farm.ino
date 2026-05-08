#include <DHT22.h>
#include <Arduino.h>
using Percent = double;
const unsigned long nightTime = 57600000UL;
const unsigned long morningTime = 86400000UL;
bool isNight = false;


// Пороги
const float Temp_Low = 20.0;   
const float Temp_High = 30.0;  
const Percent Hum_Low = 60.0;   
const Percent Hum_High = 80.0;   
const int LIGHT_THRESH = 450;   // Порог освещенности (0...1023)

const float HYST_TEMP = 1.0;
const float HYST_HUM = 2.0;
const int HYST_LIGHT = 20;

const int Pin_Hum = A3;
const int Pin_Light = A2;

const int Pin_Lamp = 6;
const int Pin_Pump = 5;
const int Pin_Heater = 4;
const int Pin_Fan = 7;
const int Pin_DHT = 1;


class AnalogSensor {
protected:
    int pin;
    virtual float rawToValue(int raw)
    {
        return raw; 
    }           
public:
    AnalogSensor(int p) {
        pin = p;
    }
    void begin() 
    { 
        pinMode(pin, INPUT); 
    }
    virtual float read() 
    { 
        return rawToValue(analogRead(pin)); 
    }
};

//(-50..+50)

//(0..100 %)
class Hygrometer : public AnalogSensor {
public:
    Hygrometer(int p) : AnalogSensor(p) {}
    float read() override {
        int raw = analogRead(pin);
        return (raw / 1023.0) * 100.0;
    }
};

// (0..1023)
class LightSensor : public AnalogSensor {
public:
    LightSensor(int p) : AnalogSensor(p) {
    } 
};

class Actuator {
private:
    int pin;
    bool state;
public:
    Actuator(int p) : pin(p), state(false) {}
    void begin() 
    {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
    void on() 
    { 
        digitalWrite(pin, HIGH); 
        state = true; 
    }
    void off() 
    { 
        digitalWrite(pin, LOW);
        state = false; 
    }
    void set(bool s) 
    { 
        s ? on() : off(); 
    }
    bool getState() const 
    { 
        return state; 
    }
};

class DHTSensor {
private:
    int pin;
    DHT22 dht;

public:
    DHTSensor(int p) : pin(p), dht(p) {}

    void begin()
    {
        pinMode(pin, INPUT);
    }

    float readTemperature()
    {
        int temperature = 0;

        float result = dht.getTemperature(temperature);

        return result;


    }

    Percent readHumAir()
    {
        float humidity = dht.getHumidity();
        
        return humidity;

    }
};


DHTSensor dhtSensor(Pin_DHT);
Hygrometer    humSensor(Pin_Hum);
LightSensor   lightSensor(Pin_Light);

Actuator lamp(Pin_Lamp);
Actuator pump(Pin_Pump);
Actuator heater(Pin_Heater);
Actuator fan(Pin_Fan);


float currentTemp = 0.0;
float currentHumAir = 0.0;
float currentHumGround = 0.0;
int   currentLight = 0;


// Вывод данных в Serial
void printData() {
    Serial.print("Temp: ");
    Serial.print(currentTemp);
    Serial.print(" C, HumAir: ");
    Serial.print(currentHumAir);
    Serial.print(" %, HumGround: ");
    Serial.print(currentHumGround);
    Serial.print(" %, Light: ");
    Serial.print(currentLight);
    Serial.print(" | Lamp: ");
    Serial.print(lamp.getState());
    Serial.print(" Pump: ");
    Serial.print(pump.getState());
    Serial.print(" Heater: ");
    Serial.print(heater.getState());
    Serial.print(" Fan: ");
    Serial.println(fan.getState());
}

// ------------------- ЛОГИКА УПРАВЛЕНИЯ ------------------------
void controlTemperature(float temp) {
    static bool heaterWasOn = false;
    static bool fanWasOn = false;

    if (temp < Temp_Low - (heaterWasOn ? HYST_TEMP : 0)) {
        heater.on();
        fan.off();
        heaterWasOn = true;
        fanWasOn = false;
    }
    else if (temp > Temp_High + (fanWasOn ? HYST_TEMP : 0)) {
        heater.off();
        fan.on();
        heaterWasOn = false;
        fanWasOn = true;
    }
    else if (temp >= Temp_Low +
    HYST_TEMP && temp <= Temp_High - HYST_TEMP) {
        heater.off();
        fan.off();
        heaterWasOn = false;
        fanWasOn = false;
    }
    // Если температура в промежуточной зоне, сохраняем предыдущее состояние
}

void controlHumidity(float hum) {
    static bool pumpWasOn = false;

    if (hum < Hum_Low - (pumpWasOn ? HYST_HUM : 0))
    {
        pump.on();
        pumpWasOn = true;
    }
    else if (hum > Hum_High + (pumpWasOn ? HYST_HUM : 0)) {
        pump.off();
        pumpWasOn = false;
    }
    // Иначе оставляем как есть
}

void controlLight(int light) {
    static bool lampWasOn = false;

    if (light < LIGHT_THRESH - (lampWasOn ? HYST_LIGHT : 0)) {
        lamp.on();
        lampWasOn = true;
    }
    else if (light > LIGHT_THRESH + HYST_LIGHT) {
        lamp.off();
        lampWasOn = false;
    }
    // Иначе без изменений
}


void setup() 
{
    Serial.begin(9600);
    Serial.println("Smart Farm starting...");
    
    humSensor.begin();
    lightSensor.begin();

    lamp.begin();
    pump.begin();
    heater.begin();
    fan.begin();

    delay(1000);
}


void loop() 
{
    if (millis() >= nightTime and millis() <= morningTime ) {
    isNight = true;}
    else {
    isNight = false;
    }
  
    if (isNight) {

      lamp.off();
      pump.off();
      heater.off();
      fan.off();

      return;
    }

    currentTemp  = dhtSensor.readTemperature();
    currentHumAir  = dhtSensor.readHumAir();
    currentHumGround   = humSensor.read();
    currentLight = lightSensor.read();

    controlTemperature(currentTemp);
    controlHumidity(currentHumGround);
    controlLight(currentLight);

    printData();
    
    delay(2000);  
}
