<<<<<<< HEAD
#include <DHT.h>

// ===== ПИНЫ =====
#define light_pin 6
#define pump_pin 5
#define heat_pin 4
#define fan_pin 7

#define light_sensor_pin A3
#define ground_hum_pin A1
#define air_sensor_pin 3

// ===== DHT =====
#define DHTTYPE DHT11   
DHT dht(air_sensor_pin, DHTTYPE);

// ===== НАСТРОЙКИ =====
const bool RELAY_ACTIVE_LOW = false;

// Пороги
int lightLimit = 400;     // меньше = темно, включ лампу
int soilDryLimit = 500;   // меньше = сухо, включ помпу

float tempLow = 20.0;     // ниже - включ нагрев
float tempHigh = 28.0;    // выше - включ вентилятор

// ===== ФУНКЦИИ УПРАВЛЕНИЯ =====
void deviceOn(int pin) {
  digitalWrite(pin, RELAY_ACTIVE_LOW ? LOW : HIGH);
}

void deviceOff(int pin) {
  digitalWrite(pin, RELAY_ACTIVE_LOW ? HIGH : LOW);
}

void setup() {
  Serial.begin(9600);

  pinMode(light_pin, OUTPUT);
  pinMode(pump_pin, OUTPUT);
  pinMode(heat_pin, OUTPUT);
  pinMode(fan_pin, OUTPUT);

  pinMode(light_sensor_pin, INPUT);
  pinMode(ground_hum_pin, INPUT);

  dht.begin();

  deviceOff(light_pin);
  deviceOff(pump_pin);
  deviceOff(heat_pin);
  deviceOff(fan_pin);

  Serial.println("Smart Farm started");
}

void loop() {
  int lightValue = analogRead(light_sensor_pin);
  int soilValue = analogRead(ground_hum_pin);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.println("====== DATA ======");
  Serial.print("Light: ");
  Serial.println(lightValue);

  Serial.print("Soil humidity: ");
  Serial.println(soilValue);

  Serial.print("Air temp: ");
  Serial.println(temperature);

  Serial.print("Air humidity: ");
  Serial.println(humidity);

  // ===== СВЕТ =====
  if (lightValue < lightLimit) {
    deviceOn(light_pin);
    Serial.println("Light ON");
  } else {
    deviceOff(light_pin);
    Serial.println("Light OFF");
  }

  // ===== ПОМПА =====
  if (soilValue < soilDryLimit) {
    deviceOn(pump_pin);
    Serial.println("Pump ON");
    delay(3000);          // полив 3 секунды
    deviceOff(pump_pin);
    Serial.println("Pump OFF");
  } else {
    deviceOff(pump_pin);
    Serial.println("Pump OFF");
  }

  // ===== ТЕМПЕРАТУРА =====
  if (!isnan(temperature)) {
    if (temperature < tempLow) {
      deviceOn(heat_pin);
      deviceOff(fan_pin);
      Serial.println("Heat ON, Fan OFF");
    } 
    else if (temperature > tempHigh) {
      deviceOff(heat_pin);
      deviceOn(fan_pin);
      Serial.println("Heat OFF, Fan ON");
    } 
    else {
      deviceOff(heat_pin);
      deviceOff(fan_pin);
      Serial.println("Heat OFF, Fan OFF");
    }
  } else {
    Serial.println("DHT error");
    deviceOff(heat_pin);
    deviceOff(fan_pin);
  }

  delay(2000);
}
=======
#include <DHT.h>

// ===== ПИНЫ =====
#define light_pin 6
#define pump_pin 5
#define heat_pin 4
#define fan_pin 7

#define light_sensor_pin A3
#define ground_hum_pin A1
#define air_sensor_pin 3

// ===== DHT =====
#define DHTTYPE DHT11   
DHT dht(air_sensor_pin, DHTTYPE);

// ===== НАСТРОЙКИ =====
const bool RELAY_ACTIVE_LOW = false;

// Пороги
int lightLimit = 400;     // меньше = темно, включ лампу
int soilDryLimit = 500;   // меньше = сухо, включ помпу

float tempLow = 20.0;     // ниже - включ нагрев
float tempHigh = 28.0;    // выше - включ вентилятор

// ===== ФУНКЦИИ УПРАВЛЕНИЯ =====
void deviceOn(int pin) {
  digitalWrite(pin, RELAY_ACTIVE_LOW ? LOW : HIGH);
}

void deviceOff(int pin) {
  digitalWrite(pin, RELAY_ACTIVE_LOW ? HIGH : LOW);
}

void setup() {
  Serial.begin(9600);

  pinMode(light_pin, OUTPUT);
  pinMode(pump_pin, OUTPUT);
  pinMode(heat_pin, OUTPUT);
  pinMode(fan_pin, OUTPUT);

  pinMode(light_sensor_pin, INPUT);
  pinMode(ground_hum_pin, INPUT);

  dht.begin();

  deviceOff(light_pin);
  deviceOff(pump_pin);
  deviceOff(heat_pin);
  deviceOff(fan_pin);

  Serial.println("Smart Farm started");
}

void loop() {
  int lightValue = analogRead(light_sensor_pin);
  int soilValue = analogRead(ground_hum_pin);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.println("====== DATA ======");
  Serial.print("Light: ");
  Serial.println(lightValue);

  Serial.print("Soil humidity: ");
  Serial.println(soilValue);

  Serial.print("Air temp: ");
  Serial.println(temperature);

  Serial.print("Air humidity: ");
  Serial.println(humidity);

  // ===== СВЕТ =====
  if (lightValue < lightLimit) {
    deviceOn(light_pin);
    Serial.println("Light ON");
  } else {
    deviceOff(light_pin);
    Serial.println("Light OFF");
  }

  // ===== ПОМПА =====
  if (soilValue < soilDryLimit) {
    deviceOn(pump_pin);
    Serial.println("Pump ON");
    delay(3000);          // полив 3 секунды
    deviceOff(pump_pin);
    Serial.println("Pump OFF");
  } else {
    deviceOff(pump_pin);
    Serial.println("Pump OFF");
  }

  // ===== ТЕМПЕРАТУРА =====
  if (!isnan(temperature)) {
    if (temperature < tempLow) {
      deviceOn(heat_pin);
      deviceOff(fan_pin);
      Serial.println("Heat ON, Fan OFF");
    } 
    else if (temperature > tempHigh) {
      deviceOff(heat_pin);
      deviceOn(fan_pin);
      Serial.println("Heat OFF, Fan ON");
    } 
    else {
      deviceOff(heat_pin);
      deviceOff(fan_pin);
      Serial.println("Heat OFF, Fan OFF");
    }
  } else {
    Serial.println("DHT error");
    deviceOff(heat_pin);
    deviceOff(fan_pin);
  }

  delay(2000);
}
>>>>>>> 33a7e85d0f4b996146a03e28b6d2580bd8922e4c
