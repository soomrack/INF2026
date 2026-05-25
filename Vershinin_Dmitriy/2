#include <DHT.h>

// --- НАСТРОЙКА ВХОДА ---
#define LIGHT_PIN A0
#define DHTPIN 2
#define DHTTYPE DHT11
#define SOIL_SENSOR_PIN A1

// --- ПИНЫ СВЕТОДИОДОВ ---
#define LED_LIGHT 3
#define LED_FAN 7
#define LED_HEAT 9
#define LED_HUMID 4
#define PUMP_PIN 10

// --- ПОРОГИ КЛИМАТА ---
#define TEMP_HIGH 28.0
#define TEMP_LOW 24.0
#define HUM_LOW 40.0
#define HUM_HIGH 70.0

// --- НАСТРОЙКИ ПОЛИВА ---
#define SOIL_DRY_THRESHOLD 800
#define PUMP_DURATION 2000
#define PUMP_COOLDOWN 30000

// --- ВРЕМЯ НАСТРОЙКА ---
const int START_HOUR = 0;
const int START_MINUTE = 0;
unsigned long previousMillis = 0;

// --- ДАТЧИКИ ---
class LightSensor {
private:
    int pin;
public:
    int lightLevel;
public:
    LightSensor(int pin) : pin(pin) { lightLevel = 0; }
public:
    void measure() {
        lightLevel = analogRead(pin);
    }
};

class DHTSensor {
private:
    int pin;
    int type;
public:
    float temperature;
    float humidity;
    DHT dht;
public:
    DHTSensor(int pin, int type) : pin(pin), type(type), dht(pin, type) {
        temperature = 0;
        humidity = 0;
    }
public:
    void begin() { dht.begin(); }
    void measure() {
        temperature = dht.readTemperature();
        humidity = dht.readHumidity();
    }
    bool isValid() { return !isnan(temperature) && !isnan(humidity); }
};

class SoilSensor {
private:
    int pin;
public:
    int soilValue;
    int soilPercent;
public:
    SoilSensor(int pin) : pin(pin) { soilValue = 0; soilPercent = 0; }
public:
    void measure() {
        soilValue = analogRead(pin);
        soilPercent = map(soilValue, 0, 1023, 0, 100);
    }
};

// --- АКТУАТОРЫ ---
class Light {
public:
    bool lightOnDark;
    bool lightEnabled;
public:
    Light() { lightOnDark = false; lightEnabled = false; }
    void power() {
        digitalWrite(LED_LIGHT, lightEnabled ? HIGH : LOW);
    }
    void control(float lightLevel) {
        lightOnDark = (lightLevel > 500);
        lightEnabled = lightOnDark;
    }
};

class Heater {
public:
    bool heatOnLowTemp;
    bool heatEnabled;
public:
    Heater() { heatOnLowTemp = false; heatEnabled = false; }
    void power() {
        digitalWrite(LED_HEAT, heatEnabled ? HIGH : LOW);
    }
    void control(float temperature) {
        heatOnLowTemp = (temperature < TEMP_LOW);
        heatEnabled = heatOnLowTemp;
    }
};

class Fan {
public:
    bool fanOnTemp;
    bool fanOnHum;
    bool fanOnSchedule;
    bool fanEnabled;
public:
    Fan() { fanOnTemp = false; fanOnHum = false; fanOnSchedule = false; fanEnabled = false; }
    void power() {
        digitalWrite(LED_FAN, fanEnabled ? HIGH : LOW);
    }
    void control(float temperature, float humidity, int currentHour, int currentMinute) {
        fanOnTemp = (temperature > TEMP_HIGH);
        fanOnHum = (humidity > HUM_HIGH);
        if (currentHour >= 6 && currentHour < 23) {
            fanOnSchedule = (currentMinute < 10);
        } else {
            fanOnSchedule = false;
        }
        fanEnabled = fanOnTemp || fanOnHum || fanOnSchedule;
    }
};

class Humidifier {
public:
    bool humidOnLowHum;
    bool humidifierEnabled;
public:
    Humidifier() { humidOnLowHum = false; humidifierEnabled = false; }
    void power() {
        digitalWrite(LED_HUMID, humidifierEnabled ? HIGH : LOW);
    }
    void control(float humidity) {
        humidOnLowHum = (humidity < HUM_LOW);
        humidifierEnabled = humidOnLowHum;
    }
};

class Pump {
private:
    enum PumpState { PUMP_IDLE, PUMP_ACTIVE, PUMP_COOLDOWN_STATE };
    PumpState pumpState;
    unsigned long pumpTimer;
    int dryThreshold;
    unsigned long duration;
    unsigned long cooldown;
public:
    bool pumpEnabled;
public:
    Pump(int dryThreshold, unsigned long duration, unsigned long cooldown) 
        : dryThreshold(dryThreshold), duration(duration), cooldown(cooldown) {
        pumpState = PUMP_IDLE;
        pumpTimer = 0;
        pumpEnabled = false;
    }
    void power() {
        digitalWrite(PUMP_PIN, pumpEnabled ? HIGH : LOW);
    }
    void control(int soilValue) {
        switch (pumpState) {
            case PUMP_IDLE:
                if (soilValue > dryThreshold) {
                    pumpEnabled = true;
                    pumpTimer = millis();
                    pumpState = PUMP_ACTIVE;
                }
                break;
            case PUMP_ACTIVE:
                if (millis() - pumpTimer >= duration) {
                    pumpEnabled = false;
                    pumpTimer = millis();
                    pumpState = PUMP_COOLDOWN_STATE;
                }
                break;
            case PUMP_COOLDOWN_STATE:
                if (millis() - pumpTimer >= cooldown) {
                    pumpState = PUMP_IDLE;
                }
                break;
        }
    }
};

class TimeManager {
private:
    unsigned long startMillis;
    int startHour;
    int startMinute;
public:
    int currentHour;
    int currentMinute;
public:
    TimeManager(int startHour, int startMinute) : startHour(startHour), startMinute(startMinute) {
        startMillis = millis();
        currentHour = 0;
        currentMinute = 0;
    }
    void update() {
        unsigned long currentMillis = millis();
        unsigned long elapsedMinutes = (currentMillis - startMillis) / 60000UL;
        int totalMinutes = startHour * 60 + startMinute + elapsedMinutes;
        currentHour = (totalMinutes / 60) % 24;
        currentMinute = totalMinutes % 60;
    }
};

LightSensor lightSensor(LIGHT_PIN);
DHTSensor dhtSensor(DHTPIN, DHTTYPE);
SoilSensor soilSensor(SOIL_SENSOR_PIN);
Light light;
Heater heater;
Fan fan;
Humidifier humidifier;
Pump pump(SOIL_DRY_THRESHOLD, PUMP_DURATION, PUMP_COOLDOWN);
TimeManager timeManager(START_HOUR, START_MINUTE);

void setup() {
    Serial.begin(9600);
    dhtSensor.begin();
    
    pinMode(LED_LIGHT, OUTPUT);
    pinMode(LED_FAN, OUTPUT);
    pinMode(LED_HEAT, OUTPUT);
    pinMode(LED_HUMID, OUTPUT);
    pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  if (millis() - previousMillis >= 2000) {
    previousMillis = millis();

    timeManager.update();
    
    lightSensor.measure();
    dhtSensor.measure();
    soilSensor.measure();

    if (dhtSensor.isValid()) {
      light.control(lightSensor.lightLevel);
      fan.control(dhtSensor.temperature, dhtSensor.humidity, timeManager.currentHour, timeManager.currentMinute);
      heater.control(dhtSensor.temperature);
      humidifier.control(dhtSensor.humidity);
      pump.control(soilSensor.soilValue);

      light.power();
      fan.power();
      heater.power();
      humidifier.power();
      pump.power();

      Serial.print("Свет: ");
      Serial.print(lightSensor.lightLevel);
      Serial.print(" | Температура: ");
      Serial.print(dhtSensor.temperature);
      Serial.print("*C, Влажность воздуха: ");
      Serial.print(dhtSensor.humidity);
      Serial.print("% | Влажность почвы: ");
      Serial.print(soilSensor.soilPercent);
      Serial.println("%");
    }
  }
}
