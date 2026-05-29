#include <DHT.h>

// ===== 1. ПИНЫ И НАСТРОЙКИ =====
#define PIN_LAMP          6
#define PIN_PUMP          5
#define PIN_HEATER        4
#define PIN_FAN           7

#define PIN_LIGHT_SENS    A3
#define PIN_SOIL_SENS     A1
#define PIN_DHT_DATA      3

#define DHTTYPE DHT11
DHT dhtModule(PIN_DHT_DATA, DHTTYPE);

// ===== 2. СТРУКТУРЫ И ОБЪЕКТНАЯ МОДЕЛЬ (ПЕРЕНЕСЕНО НАВЕРХ) =====
struct ClimateProfile {
  int lightThreshold;
  int soilDryThreshold;
  float tempMin;
  float tempMax;
  float humMax;
};

struct CustomSensor {
  String label;
  int pin;
  
  CustomSensor(String lbl, int p) : label(lbl), pin(p) {}

  virtual int readAnalog() { return analogRead(pin); }
  virtual float readFloat() { return 0.0; }
  virtual ~CustomSensor() {} 
};

// Наследник для цифрового датчика воздуха
struct AirSensorDHT : public CustomSensor {

  AirSensorDHT(String lbl, int p) : CustomSensor(lbl, p) {}

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

// ===== 3. ВНУТРЕННИЕ СИСТЕМНЫЕ ЧАСЫ И ПЕРЕМЕННЫЕ =====
int currentHour = 12; 
int currentMinute = 0;
unsigned long clockTimer = 0;

const ClimateProfile tomatoPreset = {400, 500, 20.0, 28.0, 70.0};
const ClimateProfile orchidPreset = {300, 600, 18.0, 25.0, 80.0};

ClimateProfile activeProfile = tomatoPreset;

// ===== 4. ИНИЦИАЛИЗАЦИЯ УСТРОЙСТВ =====
CustomSensor photoSensor  = {"Light", PIN_LIGHT_SENS};
CustomSensor groundSensor = {"Soil", PIN_SOIL_SENS};
AirSensorDHT tempSensor   = {"Temperature", PIN_DHT_DATA};
AirSensorDHT humSensor    = {"Humidity", PIN_DHT_DATA};

SmartActuator growLamp   = {"Lamp", PIN_LAMP};
SmartActuator waterPump  = {"Pump", PIN_PUMP};
SmartActuator airHeater  = {"Heater", PIN_HEATER};
SmartActuator airFan     = {"Fan", PIN_FAN};

unsigned long pumpStartMillis = 0;
bool isWateringNow = false;

// ===== 5. ФУНКЦИИ И АЛГОРИТМЫ АВТОМАТИЗАЦИИ =====
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

// Алгоритм освещения
void regulateLighting(CustomSensor& lightSens, SmartActuator& lamp, const ClimateProfile& profile) {
  bool isNightTime = (currentHour >= 22 || currentHour < 6);
  if (lightSens.readAnalog() < profile.lightThreshold && !isNightTime) {
    lamp.start(); 
  } else {
    lamp.stop();
  }
}

// Алгоритм полива
void regulateSoilMoisture(CustomSensor& soilSens, SmartActuator& pump, const ClimateProfile& profile) {
  if (isWateringNow) {
    if (millis() - pumpStartMillis >= 3000) { 
      pump.stop();
      isWateringNow = false;
    }
  } else {
    if (soilSens.readAnalog() < profile.soilDryThreshold) {
      pump.start();
      pumpStartMillis = millis();
      isWateringNow = true;
    }
  }
}

// Алгоритм управления воздушным климатом
void regulateAirClimate(CustomSensor& tSens, CustomSensor& hSens, SmartActuator& heater, SmartActuator& fan, const ClimateProfile& profile) {
  float currentTemp = tSens.readFloat();
  float currentHum  = hSens.readFloat();
  
  if (isnan(currentTemp) || isnan(currentHum)) return;

  bool turnOnHeater = false;
  bool turnOnFan = false;

  if (currentTemp > profile.tempMax) turnOnFan = true; 
  if (currentTemp < profile.tempMin) turnOnHeater = true; 

  if (currentHum > profile.humMax) { 
    turnOnFan = true;
    turnOnHeater = true; 
  }

  // Расписание проветривания
  bool isNightTime = (currentHour >= 22 || currentHour < 6);
  if (!isNightTime && currentMinute < 5) turnOnFan = true;

  if (turnOnHeater) turnOnFan = true; 

  if (turnOnHeater) heater.start(); else heater.stop();
  if (turnOnFan) fan.start(); else fan.stop();
}

// ===== 6. НАЧАЛЬНАЯ НАСТРОЙКА =====
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

// ===== 7. ГЛАВНЫЙ ИСПОЛНИТЕЛЬНЫЙ ЦИКЛ =====
void loop() {
  updateClock(); 
  
  // Вызов алгоритмов с явным указанием датчиков и исполнителей
  regulateLighting(photoSensor, growLamp, activeProfile);    
  regulateSoilMoisture(groundSensor, waterPump, activeProfile); 
  regulateAirClimate(tempSensor, humSensor, airHeater, airFan, activeProfile);  

  delay(50); 
}
