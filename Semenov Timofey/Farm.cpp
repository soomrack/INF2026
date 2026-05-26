#include <DHT.h>

// ===== ПИНЫ И НАСТРОЙКИ =====
#define PIN_LAMP          6
#define PIN_PUMP          5
#define PIN_HEATER        4
#define PIN_FAN           7

#define PIN_LIGHT_SENS    A3
#define PIN_SOIL_SENS     A1
#define PIN_DHT_DATA      3

#define DHTTYPE DHT11
DHT dhtModule(PIN_DHT_DATA, DHTTYPE);

// ===== СТРУКТУРА КЛИМАТА =====
struct ClimateProfile {
  int lightThreshold;
  int soilDryThreshold;
  float tempMin;
  float tempMax;
  float humMax;
};

const ClimateProfile tomatoPreset = {400, 500, 20.0, 28.0, 70.0};
ClimateProfile currentProfile = tomatoPreset;

struct CustomSensor {
  String label;
  int pin;
  virtual int readAnalog() { return analogRead(pin); }
  virtual float readFloat() { return 0.0; }
};

struct AirSensorDHT : public CustomSensor {
  float readFloat() override { 
    if (label == "Temperature") return dhtModule.readTemperature();
    if (label == "Humidity") return dhtModule.readHumidity();
    return 0.0;
  }
};

struct SmartActuator {
  String label;
  int pin;
  void start() { digitalWrite(pin, HIGH); }
  void stop()  { digitalWrite(pin, LOW); }
};

// ===== ГЛОБАЛЬНЫЕ ОБЪЕКТЫ =====
CustomSensor photoSensor = {"Light", PIN_LIGHT_SENS};
CustomSensor groundSensor = {"Soil", PIN_SOIL_SENS};
AirSensorDHT tempSensor = {"Temperature", PIN_DHT_DATA};
AirSensorDHT humSensor  = {"Humidity", PIN_DHT_DATA};

SmartActuator growLamp   = {"Lamp", PIN_LAMP};
SmartActuator waterPump  = {"Pump", PIN_PUMP};
SmartActuator airHeater  = {"Heater", PIN_HEATER};
SmartActuator airFan     = {"Fan", PIN_FAN};

// ===== СИМУЛЯЦИЯ ВРЕМЕНИ СУТОК =====
int currentHour = 12; 
int currentMinute = 0;
unsigned long clockTimer = 0;

void updateClock() {
  if (millis() - clockTimer >= 1000) { 
    clockTimer = millis();
    currentMinute++;
    if (currentMinute >= 60) {
      currentMinute = 0;
      currentHour++;
      if (currentHour >= 24) currentHour = 0;
    }
  }
}

// ===== АЛГОРИТМЫ УПРАВЛЕНИЯ ТЕПЛИЦЕЙ =====

void regulateLighting() {
  bool isNightTime = (currentHour >= 22 || currentHour < 6);
  if (photoSensor.readAnalog() < currentProfile.lightThreshold && !isNightTime) {
    growLamp.start(); 
  } else {
    growLamp.stop();
  }
}

unsigned long pumpStartMillis = 0;
bool isWateringNow = false;

void regulateSoilMoisture() {
  if (isWateringNow) {
    if (millis() - pumpStartMillis >= 3000) { 
      waterPump.stop();
      isWateringNow = false;
    }
  } else {
    if (groundSensor.readAnalog() < currentProfile.soilDryThreshold) {
      waterPump.start();
      pumpStartMillis = millis();
      isWateringNow = true;
    }
  }
}

void regulateAirClimate() {
  float currentTemp = tempSensor.readFloat();
  float currentHum  = humSensor.readFloat();
  
  if (isnan(currentTemp) || isnan(currentHum)) return;

  bool turnOnHeater = false;
  bool turnOnFan = false;

  if (currentTemp > currentProfile.tempMax) {
    turnOnFan = true;
  }

  if (currentTemp < currentProfile.tempMin) {
    turnOnHeater = true;
    turnOnFan = true;
  }

  if (currentHum > currentProfile.humMax) {
    turnOnFan = true;
    turnOnHeater = true; 
  }

  bool isNightTime = (currentHour >= 22 || currentHour < 6);
  if (!isNightTime && currentMinute < 5) {
    turnOnFan = true;
  }

  if (turnOnHeater) airHeater.start(); else airHeater.stop();
  if (turnOnFan) airFan.start(); else airFan.stop();
}


void setup() {
  Serial.begin(9600);
  dhtModule.begin();

  pinMode(growLamp.pin, OUTPUT);
  pinMode(waterPump.pin, OUTPUT);
  pinMode(airHeater.pin, OUTPUT);
  pinMode(airFan.pin, OUTPUT);

  growLamp.stop();
  waterPump.stop();
  airHeater.stop();
  airFan.stop();

  pinMode(photoSensor.pin, INPUT);
  pinMode(groundSensor.pin, INPUT);
}

// ===== ГЛАВНЫЙ ИСПОЛНИТЕЛЬНЫЙ ЦИКЛ =====
void loop() {
  updateClock();         
  
  regulateLighting();  
  regulateSoilMoisture(); 
  regulateAirClimate();  

  delay(50);
}
