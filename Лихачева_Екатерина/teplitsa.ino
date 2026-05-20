#include <DHT.h>

#define DHTPIN_TEMPERATURE 8
#define DHTPIN_AIR_HUMIDITY 3
#define DHTPIN_SOIL_HUMIDITY A1
#define LIGHT_SENSOR A3

DHT dht_temperature(DHTPIN_TEMPERATURE, DHT11);
DHT dht_air_humidity(DHTPIN_AIR_HUMIDITY, DHT11);
DHT dht_soil_humidity(DHTPIN_SOIL_HUMIDITY, DHT11);


// Определение классов до setup
class Thermometer {
public:
  int max_value = 22;
  int min_value = 9;
  int temperature;
  
  Thermometer() { temperature = 0; }
  
  void get_temperature() { 
    temperature = dht_temperature.readTemperature(); 
  }
};


class AirHumidity {
public:
  int max_value = 75;
  int air_humidity;
  
  AirHumidity() { air_humidity = 0; }
  
  void get_air_humidity() { 
    air_humidity = dht_air_humidity.readHumidity(); 
  }
};


class SoilHumidity {
public:
  int min_value = 70;
  int soil_humidity;
  
  SoilHumidity() { soil_humidity = 0; }
  
  void get_soil_humidity() { 
    soil_humidity = dht_soil_humidity.readHumidity(); 
  }
};


class Light {
public:
  int min_value = 10000;
  int light;
  
  Light() { light = 0; }
  
  void get_light() { 
    light = analogRead(LIGHT_SENSOR); 
  }
};


class Lamp {
private:
  int pin;
public:
  bool on_light;
  
  Lamp(int pin) : pin(pin) { on_light = false; }
  
  void power() {
    if (on_light) { digitalWrite(pin, HIGH); }
    else { digitalWrite(pin, LOW); }
  }
};


class Pump {
private:
  int pin;
public:
  bool in_use;
  unsigned long pumpStartTime;
  bool pumpRunning;
  
  Pump(int pin) : pin(pin) { 
    in_use = false; 
    pumpStartTime = 0;
    pumpRunning = false;
  }
  
  void power() {
    if (in_use && !pumpRunning) {
      digitalWrite(pin, HIGH);
      pumpStartTime = millis();
      pumpRunning = true;
    }
    
    if (pumpRunning && (millis() - pumpStartTime >= 180000)) {  // 3 минуты
      digitalWrite(pin, LOW);
      pumpRunning = false;
      in_use = false;
    }
    
    if (!in_use && pumpRunning) {
      digitalWrite(pin, LOW);
      pumpRunning = false;
    }
  }
};


class Fan {
private:
  int pin;
public:
  bool need_use_temperature = false;
  bool need_use_humidity = false;
  bool schedule_use = false;
  bool in_use;
  
  Fan(int pin) : pin(pin) { in_use = false; }
  
  void power() {
    if (in_use && (need_use_temperature || need_use_humidity || schedule_use)) { digitalWrite(pin, HIGH); }
    else { digitalWrite(pin, LOW); }
  }
};


class Heater {
private:
  int pin;
public:
  bool in_use;
  
  Heater(int pin) : pin(pin) { in_use = false; }
  
  void power() {
    if (in_use) { digitalWrite(pin, HIGH); }
    else { digitalWrite(pin, LOW); }
  }
};


// Глобальные объекты
Lamp lamp(6);
Pump pump(5);
Fan fan(7);
Heater heater(4);

Thermometer thermometer;
AirHumidity air_humidity;
SoilHumidity soil_humidity;
Light light;

// Переменная для времени
unsigned long last_second_check = 0;


// Получение текущего часа (0-23) 
int getCurrentHour() {
  return 12; // Заглушка
}


// Функция управления светом
void control_light(Light& light, Lamp& lamp) {
  int current_hour = getCurrentHour();
  
  if (current_hour >= 0 && current_hour <= 6) {
    lamp.on_light = false;
    return;
  }
  
  if (light.light > light.min_value) {
    lamp.on_light = false;
    return;
  }
  
  lamp.on_light = true;
}


// Функция управления влажностью почвы
void control_soil_humidity(SoilHumidity& soil_humidity, Pump& pump) {
  if (soil_humidity.soil_humidity < soil_humidity.min_value) {
    pump.in_use = true;
    return;
  }
  
  pump.in_use = false;
}


// Функция управления влажностью воздуха
void control_air_humidity(AirHumidity& air_humidity, Fan& fan) {
  if (air_humidity.air_humidity > air_humidity.max_value) {
    fan.in_use = true;
    fan.need_use_humidity = true;
    return;
  }

  fan.in_use = false;
}


// Функция управления температурой
void control_temperature(Thermometer& thermometer, Heater& heater, Fan& fan) {
  if (thermometer.temperature > thermometer.max_value) {
    heater.in_use = false;
    fan.in_use = true;
    fan.need_use_temperature = true;
    return;
  }
  
  if (thermometer.temperature < thermometer.min_value) {
    fan.in_use = false;
    heater.in_use = true;
    return;
  }
  
  heater.in_use = false;
  fan.in_use = false;
}


// Проветривание по расписанию (каждый час на 10 минут)
void airing_schedule(Fan& fan) {
  unsigned long current_millis = millis();
  unsigned long minutes = (current_millis / 60000) % 60;
  
  if (minutes < 10) {
    fan.in_use = true;
    fan.schedule_use = true;
  } else {
    if (!fan.in_use) {
      fan.in_use = false;
    }
  }
}


void setup() {
  Serial.begin(9600);
  
  dht_temperature.begin();
  dht_air_humidity.begin();
  dht_soil_humidity.begin();
  
  pinMode(6, OUTPUT);  // Lamp
  pinMode(5, OUTPUT);  // Pump
  pinMode(7, OUTPUT);  // Fan
  pinMode(4, OUTPUT);  // Heater
  
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  
  last_second_check = millis();
}


void loop() {
  unsigned long current_millis = millis();
  
  // Обновление показаний датчиков каждую секунду
  if (current_millis - last_second_check >= 1000) {
    last_second_check = current_millis;
    
    thermometer.get_temperature();
    air_humidity.get_air_humidity();
    soil_humidity.get_soil_humidity();
    light.get_light();
    
    Serial.print("Temp: ");  
    Serial.print(thermometer.temperature);
    Serial.print("°C, Air Humidity: ");
    Serial.print(air_humidity.air_humidity);
    Serial.print("%, Soil Humidity: ");
    Serial.print(soil_humidity.soil_humidity);
    Serial.print("%, Light: ");
    Serial.println(light.light);
  }
  
  control_temperature(thermometer, heater, fan);
  control_air_humidity(air_humidity, fan);
  control_soil_humidity(soil_humidity, pump);
  control_light(light, lamp);
  airing_schedule(fan);
  
  heater.power();
  fan.power();
  lamp.power();
  pump.power();
  
  delay(100); 
}
