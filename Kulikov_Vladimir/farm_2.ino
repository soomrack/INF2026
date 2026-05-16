#include <DHT.h>

// ===== ПИНЫ =====
#define LIGHT_PIN 6
#define PUMP_PIN 5
#define HEAT_PIN 4
#define FAN_PIN 7

#define LIGHT_SENSOR_PIN A3
#define SOIL_SENSOR_PIN A1
#define AIR_SENSOR_PIN 3

#define DHTTYPE DHT11
DHT dht(AIR_SENSOR_PIN, DHTTYPE);

// ===== НАСТРОЙКИ =====
const bool RELAY_ACTIVE_LOW = false;

// Пороги
int lightLimit = 400;
int soilDryLimit = 500;
float tempLow = 20.0;
float tempHigh = 28.0;
float humHigh = 70.0; // для проветривания

// ===== СТРУКТУРЫ =====
struct Sensor {
  String name;
  int pin;
  int readAnalog() { return analogRead(pin); }
  float readFloat() { return 0.0; } // для DHT
};

// специализированный датчик DHT
struct DHTSensor : Sensor {
  float readFloat() { 
    if (name == "Temp") return dht.readTemperature();
    if (name == "Hum") return dht.readHumidity();
    return 0.0;
  }
};

struct Actuator {
  String name;
  int pin;
  void on()  { digitalWrite(pin, RELAY_ACTIVE_LOW ? LOW : HIGH); }
  void off() { digitalWrite(pin, RELAY_ACTIVE_LOW ? HIGH : LOW); }
};

// ===== ОБЪЕКТЫ =====
Sensor lightSensor = {"Light", LIGHT_SENSOR_PIN};
Sensor soilSensor  = {"Soil", SOIL_SENSOR_PIN};
DHTSensor tempSensor = {"Temp", AIR_SENSOR_PIN};
DHTSensor humSensor  = {"Hum", AIR_SENSOR_PIN};

Actuator lamp   = {"Lamp", LIGHT_PIN};
Actuator pump   = {"Pump", PUMP_PIN};
Actuator heater = {"Heater", HEAT_PIN};
Actuator fan    = {"Fan", FAN_PIN};

// ===== ФУНКЦИИ УПРАВЛЕНИЯ =====
void regulateLight() {
  if (lightSensor.readAnalog() < lightLimit) lamp.on(); 
  else lamp.off();
}

void regulateSoil() {
  if (soilSensor.readAnalog() < soilDryLimit) {
    pump.on();
    delay(3000); // полив
    pump.off();
  } else pump.off();
}

void regulateTempHum() {
  float temp = tempSensor.readFloat();
  float hum  = humSensor.readFloat();
  if (!isnan(temp) && !isnan(hum)) {
    // температура
    if (temp < tempLow) { heater.on(); fan.off(); }
    else if (temp > tempHigh) { heater.off(); fan.on(); }
    else { heater.off(); fan.off(); }

    // влажность
    if (hum > humHigh) fan.on(); // проветривание
  } else {
    heater.off(); fan.off();
  }
}

// ===== SETUP =====
void setup() {
  Serial.begin(9600);

  Actuator* actuators[] = {&lamp, &pump, &heater, &fan};
  for (auto a : actuators) {
    pinMode(a->pin, OUTPUT);
    a->off();
  }

  Sensor* sensors[] = {&lightSensor, &soilSensor};
  for (auto s : sensors) pinMode(s->pin, INPUT);

  dht.begin();
}

// ===== MAIN LOOP =====
void loop() {
  regulateLight();
  regulateSoil();
  regulateTempHum();

  delay(500); // минимальная задержка
}
