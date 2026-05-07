#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define PIN_HEATER 4  //нагреватель
#define PIN_PUMP 5  //насо
#define PIN_LAMP 6  //лампа
#define PIN_VENT 7  //вентилятор
#define PIN_LIGHT A0  // д освещённости
#define PIN_SOIL A1  //д влажности почвы

DHT dht(DHTPIN, DHTTYPE);

//таймер полива
unsigned long pumpStartTime = 0;
bool isPumpRunning = false;
unsigned long lastWateringTime = 0;
const unsigned long MAX_PUMP_TIME = 10000;
const unsigned long REST_TIME = 60000;

//таймер проветривания
unsigned long lastVentTime = 0;
const unsigned long VENT_INTERVAL = 3600000; //раз в час
const unsigned long VENT_DURATION = 300000;  //5 минут работы
bool isScheduledVenting = false;
unsigned long ventStartTime = 0;


class Thermometer {
private:
    int pin;
public:
    float temperature;
    float humidity;
    
    Thermometer(int pin) : pin(pin) { 
        temperature = 20; 
        humidity = 50;
    }
    
    void get_temperature() {
        temperature = dht.readTemperature();
        humidity = dht.readHumidity();
        
        if (isnan(temperature)) temperature = 20;
        if (isnan(humidity)) humidity = 50;
    }
};



class Hygrometer {
private:
    int pin;
public:
    int moisture;  //0-1023, меньше тогда суше
    
    Hygrometer(int pin) : pin(pin) { 
        moisture = 500;
    }
    
    void get_humidity() {
        moisture = analogRead(pin);
    }
};


class LightSensor {
private:
    int pin;
public:
    int light_level;  //0-1023, меньше тогда темнее
    
    LightSensor(int pin) : pin(pin) { 
        light_level = 300;
    }
    
    void get_light() {
        light_level = analogRead(pin);
    }
    
    bool isNightTime() {  //проверка ночи
        return (light_level < 50);
    }
};


class Heater {
public:
    bool on_temperature;
    int pin;
    
    Heater(int p) : pin(p), on_temperature(false) {}
    
    void begin() {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
    
    void power() {
        if (on_temperature) {
            digitalWrite(pin, HIGH);
        } else {
            digitalWrite(pin, LOW);
        }
    }
};


class Fan {
public:
    bool on_temperature;
    int pin;
    
    Fan(int p) : pin(p), on_temperature(false) {}
    
    void begin() {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
    
    void power() {
        if (on_temperature) {
            digitalWrite(pin, HIGH);
        } else {
            digitalWrite(pin, LOW);
        }
    }
};


class Pump {
public:
    bool on_humidity;
    int pin;
    
    Pump(int p) : pin(p), on_humidity(false) {}
    
    void begin() {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
    
    void power() {
        if (on_humidity) {
            digitalWrite(pin, HIGH);
        } else {
            digitalWrite(pin, LOW);
        }
    }
};


class Lamp {
public:
    bool on_light;
    int pin;
    
    Lamp(int p) : pin(p), on_light(false) {}
    
    void begin() {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
    
    void power() {
        if (on_light) {
            digitalWrite(pin, HIGH);
        } else {
            digitalWrite(pin, LOW);
        }
    }
};



void control_temperature(const Thermometer& thermometer, Heater& heater, Fan& fan)  //темп и влаж возд
{
    if (thermometer.temperature < 22.0) {
        heater.on_temperature = true;
        fan.on_temperature = true;
    }
    else if (thermometer.temperature > 28.0) {
        heater.on_temperature = false;
        fan.on_temperature = true;
    }
    else if (thermometer.humidity > 70.0) {
        heater.on_temperature = false;
        fan.on_temperature = true;
    }
    else {
        heater.on_temperature = false;
        fan.on_temperature = false;
    }
}


void control_humidity(Hygrometer& hygrometer, Pump& pump, Fan& fan)  //влаж почвы
{
    unsigned long currentTime = millis();
    
    if (hygrometer.moisture > 700 && !isPumpRunning) {
        if (currentTime - lastWateringTime > REST_TIME) {
            pump.on_humidity = true;
            isPumpRunning = true;
            pumpStartTime = currentTime;
        }
    }
    
    if (isPumpRunning && hygrometer.moisture < 400) {
        pump.on_humidity = false;
        isPumpRunning = false;
        lastWateringTime = currentTime;
    }
    
    if (isPumpRunning && (currentTime - pumpStartTime > MAX_PUMP_TIME)) {  //защита от избытка
        pump.on_humidity = false;
        isPumpRunning = false;
        lastWateringTime = currentTime;
    }
}


void control_light(const LightSensor& light_sensor, Lamp& lamp)  //освещение
{
    if (light_sensor.isNightTime()) {
        lamp.on_light = false;
        return;
    }
    
    if (light_sensor.light_level < 300) {
        lamp.on_light = true;
    } else {
        lamp.on_light = false;
    }
}


void control_scheduled_ventilation(Fan& fan, const LightSensor& light_sensor)  //проветривание
{
    unsigned long currentTime = millis();
    
    if (light_sensor.isNightTime()) {
        if (isScheduledVenting) {
            fan.on_temperature = false;
            isScheduledVenting = false;
        }
        return;
    }
    
    if (!isScheduledVenting && (currentTime - lastVentTime >= VENT_INTERVAL)) {  //раз в час, по 5 мин
        isScheduledVenting = true;
        ventStartTime = currentTime;
        fan.on_temperature = true;
    }
    
    if (isScheduledVenting && (currentTime - ventStartTime >= VENT_DURATION)) {
        fan.on_temperature = false;
        isScheduledVenting = false;
        lastVentTime = currentTime;
    }
}



int main()
{
    Thermometer thermometer(DHTPIN);
    Hygrometer hygrometer(PIN_SOIL);
    LightSensor light_sensor(PIN_LIGHT);
    
    Heater heater(PIN_HEATER);
    Fan fan(PIN_VENT);
    Pump pump(PIN_PUMP);
    Lamp lamp(PIN_LAMP);
    
    Serial.begin(9600);
    dht.begin();
    
    heater.begin();
    fan.begin();
    pump.begin();
    lamp.begin();
    
    lastVentTime = millis();
    
    while (true) {
        thermometer.get_temperature();
        hygrometer.get_humidity();
        light_sensor.get_light();
        
        control_temperature(thermometer, heater, fan);
        control_humidity(hygrometer, pump, fan);
        control_light(light_sensor, lamp);
        control_scheduled_ventilation(fan, light_sensor);
        
        heater.power();
        fan.power();
        pump.power();
        lamp.power();
        
        delay(2000);  //каждые 2 секунды
    }
    
    return 0;
}