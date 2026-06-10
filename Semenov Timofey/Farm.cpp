#include <DHT.h>

// ===== 1. ПИНЫ И НАСТРОЙКИ =====
#define PIN_LAMP          5
#define PIN_PUMP          6
#define PIN_HEATER        7
#define PIN_FAN           4

#define PIN_LIGHT_SENS    A1
#define PIN_SOIL_SENS     A2
#define PIN_DHT_DATA      3

#define DHTTYPE DHT11
DHT dhtModule(PIN_DHT_DATA, DHTTYPE);

// ===== 2. СТРУКТУРЫ И ОБЪЕКТНАЯ МОДЕЛЬ =====
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

const ClimateProfile tomatoPreset = {400, 1000, 20.0, 28.0, 70.0};
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
unsigned long pumpStopMillis = 0;
bool isWateringNow = false;

// ===== 5. ФУНКЦИИ И АЛГОРИТМЫ АВТОМАТИЗАЦИИ =====

// Системные часы
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
  bool isNightTime = (currentHour >= 22 || currentHour < 6); // Защищено от спойлеров мессенджеров :)
  if (lightSens.readAnalog() > profile.lightThreshold && !isNightTime) {
    lamp.start(); 
  } else {
    lamp.stop();
  }
}

// Алгоритм полива (с твоей 7-секундной паузой)
void regulateSoilMoisture(CustomSensor& soilSens, SmartActuator& pump, const ClimateProfile& profile) {
  if (isWateringNow) {
    if (millis() - pumpStartMillis >= 3000) { 
      pump.stop();
      isWateringNow = false;
      pumpStopMillis = millis();
    }
  } else {
    if ((soilSens.readAnalog() > profile.soilDryThreshold) && millis() - pumpStopMillis >= 7000) {
      pump.start();
      pumpStartMillis = millis();
      isWateringNow = true;
    }
  }
}

// ПОД-ФУНКЦИЯ 1: Контроль температуры воздуха
void controlTemperature(CustomSensor& tSens, bool& needHeater, bool& needFan, const ClimateProfile& profile) {
  float currentTemp = tSens.readFloat();
  if (isnan(currentTemp)) return;

  if (currentTemp > profile.tempMax) needFan = true;    // Жарко -> нужен вентилятор
  if (currentTemp < profile.tempMin) needHeater = true; // Холодно -> нужен обогрев
}

// ПОД-ФУНКЦИЯ 2: Контроль влажности воздуха
void controlHumidity(CustomSensor& hSens, bool& needHeater, bool& needFan, const ClimateProfile& profile) {
  float currentHum = hSens.readFloat();
  if (isnan(currentHum)) return;

  if (currentHum > profile.humMax) { 
    needFan = true;
    needHeater = true; // Слишком сыро -> включаем вытяжку и осушаем нагревом
  }
}

// ПОД-ФУНКЦИЯ 3: Проветривание по расписанию
void controlScheduledVentilation(bool& needFan) {
  bool isNightTime = (currentHour >= 22 || currentHour < 6);
  // Если день и первые 5 минут часа -> принудительно запрашиваем вентилятор
  if (!isNightTime && currentMinute < 5) {
    needFan = true;
  }
}

// ПОД-ФУНКЦИЯ 4: Применение команд с правилами безопасности
void applyAirClimate(SmartActuator& heater, SmartActuator& fan, bool needHeater, bool needFan) {
  // КРИТИЧЕСКОЕ ПРАВИЛО: Вентилятор обязан обдувать работающий нагреватель
  if (needHeater) needFan = true; 
  
  // Твоя защита от перегрузки: нагреватель работает только тогда, когда помпа ОТКЛЮЧЕНА
  if (needHeater && !isWateringNow) heater.start(); else heater.stop();
  
  // Физическое управление вентилятором
  if (needFan) fan.start(); else fan.stop();
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
  
  // 1. Управление светом и почвой
  regulateLighting(photoSensor, growLamp, activeProfile);    
  regulateSoilMoisture(groundSensor, waterPump, activeProfile); 

  // 2. Управление воздухом (Разнесено на прозрачные под-функции!)
  bool heaterRequested = false;
  bool fanRequested = false;

  controlTemperature(tempSensor, heaterRequested, fanRequested, activeProfile); // Контроль температуры
  controlHumidity(humSensor, heaterRequested, fanRequested, activeProfile);       // Контроль влажности
  controlScheduledVentilation(fanRequested);                                      // Проветривание по часам

  // 3. Безопасное физическое исполнение команд
  applyAirClimate(airHeater, airFan, heaterRequested, fanRequested); 

  // Мониторинг в Serial порт для отладки
  Serial.print("Light = "); Serial.print(photoSensor.readAnalog());
  Serial.print(" Soil = "); Serial.print(groundSensor.readAnalog());
  Serial.print(" IsWateringNow = "); Serial.print(isWateringNow);
  Serial.print(" Temp = "); Serial.print(tempSensor.readFloat());
  Serial.print(" Hum = "); Serial.print(humSensor.readFloat());
  Serial.print("\n");

  delay(50); 
}
