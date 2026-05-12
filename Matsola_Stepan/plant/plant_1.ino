#include <DHT.h>

#define DHTTYPE DHT11

const int HUMID_TEMP_PIN = 2;
const int HUMID_SOIL_PIN = A1;
const int LIGHT_SENSOR_PIN = A0;

const int FAN_PIN = 7;
const int HEATER_PIN = 4;
const int LAMP_PIN = 6;
const int PUMP_PIN = 5;

DHT dht(HUMID_TEMP_PIN, DHTTYPE);

const float TEMP_MAX = 28.0;
const float TEMP_MIN = 18.0;
const float AIR_HUMIDITY_MAX = 70.0;
const int SOIL_MOISTURE_MIN = 50;
const int LIGHT_MIN = 400;

const unsigned long WATERING_DURATION = 3000;
const unsigned long WATERING_WAIT_DURATION = 20000;
const unsigned long VENTILATION_DURATION = 300000;
const unsigned long VENTILATION_INTERVAL = 3600000;
const unsigned long SENSOR_READ_DELAY = 2000;

float temperature = 0;
float airHumidity = 0;
int soilMoisture = 0;
int lightLevel = 0;

bool fanState = false;
bool heaterState = false;
bool lampState = false;
bool pumpState = false;

unsigned long lastVentTime = 0;
bool ventilationActive = false;
unsigned long ventilationStartTime = 0;

bool wateringActive = false;
unsigned long wateringStartTime = 0;
bool waitingAfterWatering = false;
unsigned long waitStartTime = 0;

void readSensors() {
  temperature = dht.readTemperature();
  airHumidity = dht.readHumidity();
  
  soilMoisture = analogRead(HUMID_SOIL_PIN);
  soilMoisture = map(soilMoisture, 0, 1023, 0, 100);
  
  lightLevel = analogRead(LIGHT_SENSOR_PIN);
  lightLevel = map(lightLevel, 0, 1023, 0, 1000);
}

bool isNightTime() {
  unsigned long hour = (millis() / 3600000) % 24;
  return (hour >= 22 || hour <= 6);
}

void controlLight() {
  if (!isNightTime() && lightLevel < LIGHT_MIN) {
    lampState = true;
  } else {
    lampState = false;
  }
}

void controlPump() {
  if (waitingAfterWatering) {
    if (millis() - waitStartTime >= WATERING_WAIT_DURATION) {
      waitingAfterWatering = false;
    }
    return;
  }
  
  if (wateringActive) {
    if (millis() - wateringStartTime >= WATERING_DURATION) {
      wateringActive = false;
      pumpState = false;
      waitingAfterWatering = true;
      waitStartTime = millis();
    }
    return;
  }
  
  if (!wateringActive && !waitingAfterWatering) {
    if (soilMoisture < SOIL_MOISTURE_MIN) {
      wateringActive = true;
      wateringStartTime = millis();
      pumpState = true;
    } else {
      pumpState = false;
    }
  }
}

void controlTemperature() {
  if (temperature > TEMP_MAX) {
    fanState = true;
    heaterState = false;
  } else if (temperature < TEMP_MIN) {
    heaterState = true;
    fanState = true;
  } else {
    heaterState = false;
    fanState = false;
  }
}

void controlHumidity() {
  if (airHumidity > AIR_HUMIDITY_MAX) {
    fanState = true;
  }
}

void scheduledVentilation() {
  if (!isNightTime() && !ventilationActive && millis() - lastVentTime > VENTILATION_INTERVAL) {
    ventilationActive = true;
    ventilationStartTime = millis();
    fanState = true;
    lastVentTime = millis();
  }
  
  if (ventilationActive && millis() - ventilationStartTime > VENTILATION_DURATION) {
    ventilationActive = false;
    fanState = false;
  }
}

void applyActuators() {
  digitalWrite(FAN_PIN, fanState ? HIGH : LOW);
  digitalWrite(HEATER_PIN, heaterState ? HIGH : LOW);
  digitalWrite(LAMP_PIN, lampState ? HIGH : LOW);
  digitalWrite(PUMP_PIN, pumpState ? HIGH : LOW);
}

void resetStates() {
  if (!ventilationActive) {
    fanState = false;
  }
  if (!wateringActive) {
    pumpState = false;
  }
  heaterState = false;
  lampState = false;
}

void setup() {
  pinMode(FAN_PIN, OUTPUT);
  pinMode(HEATER_PIN, OUTPUT);
  pinMode(LAMP_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  readSensors();
  
  resetStates();
  
  controlLight();
  controlPump();
  controlTemperature();
  controlHumidity();
  scheduledVentilation();
  
  applyActuators();
  
  delay(SENSOR_READ_DELAY);
}