#include <DHT.h>

struct Plant {
  int max_temperature = 30;
  int min_temperature = 20;
  int max_Ahumidity = 70;
  int min_Ahumidity = 50;
  int max_Shumidity = 800;
  int min_Shumidity = 600;
  int max_light = 200;
  int min_light = 100;
};

Plant tomato;


class AirSensor {
private:
  DHT dht;
public:
  float humidity = 0, temperature = 0;
  AirSensor(int pin) : dht(pin, DHT11) {}
  void begin() 
    { dht.begin(); }
  void update() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    if (!isnan(h) && !isnan(t)) 
      { humidity = h; temperature = t; }
  }
};

class HygrometerSoil {
public:
  int pin, humidity = 0;
  HygrometerSoil(int p) : pin(p) {}
  void get_humidity() 
    { humidity = analogRead(pin); }
};

class LightSensor {
public:
  int pin, value = 0;
  LightSensor(int p) : pin(p) {}
  void get_light() 
    { value = analogRead(pin); }
};

class Lamp {
public:
  int pin;
  bool on_lamp = false;
  Lamp(int p) : pin(p) { pinMode(pin, OUTPUT); }
  void power() 
    { digitalWrite(pin, on_lamp ? HIGH : LOW); }
};

class Fan {
private:
  int pin;
  unsigned long fan_start_time = 0;
public:
  bool on_fan = false;
  Fan(int p) : pin(p) { pinMode(pin, OUTPUT); }
  void power() 
    { digitalWrite(pin, on_fan ? HIGH : LOW); }
  void startTimer() 
    { fan_start_time = millis(); }
  void checkTimer() {
    if (fan_start_time > 0) {
      if (millis() - fan_start_time >= 20000) 
        fan_start_time = 0; // 20 сек обдув
      else 
        on_fan = true;
    }
  }
};

class Heater {
private:
  int pin;
public:
  bool on_heat = false;
  Heater(int p) : pin(p) { pinMode(pin, OUTPUT); }
  void power() 
    { digitalWrite(pin, on_heat ? HIGH : LOW); }
};

class Pump {
public:
  int pin;
  bool on_pump = false;
  Pump(int p) : pin(p) { pinMode(pin, OUTPUT); }
  void power()  
    { digitalWrite(pin, (on_pump && (millis() % 10000 <= 2000)) ? HIGH : LOW); }
};


AirSensor air(2);
HygrometerSoil soil(A1);
LightSensor light(A0);
Lamp lamp(3);
Fan fan(6);
Heater heater(5);
Pump pump(4);

unsigned long lastUpdate = 0;
unsigned long lastVentilation = 0;

void setup() {
  Serial.begin(9600);
  air.begin();}


//функции


void updateFan(unsigned long currentMillis) {

  if (currentMillis - lastVentilation >= 30000) {
    lastVentilation = currentMillis;
  }
  if (currentMillis - lastVentilation < 20000) {
    fan.on_fan = true;
  }
  
  // к обогреву
  if (heater.on_heat) {
    fan.on_fan = true;
  }
}

// Функция управления обогревом
void updateHeater() {
  if (pump.on_pump = true){
    heater.on_heat = false;
    return;
  }
  if (air.temperature > 0.1 && air.temperature < tomato.min_temperature) {
    heater.on_heat = true;
    fan.on_fan = true;
  } 
  if (air.temperature >= tomato.max_temperature) {
    fan.on_fan = true;
  }

}

// управлениe поливом
void updatePump(unsigned long currentMillis) {
  if (soil.humidity <= tomato.min_Shumidity) { 
    pump.on_pump = true;
    fan.on_fan = true;
  } else {
    pump.on_pump = false;
  }
}

//  управлениe светом
void updateLight() {
  if (light.value < tomato.min_light) { 
    lamp.on_lamp = true;  
  } 
  else if (light.value >= tomato.max_light) {
    lamp.on_lamp = false; 
  }
}


void loop() {
  unsigned long currentMillis = millis();


  fan.on_fan = false;
  lamp.on_lamp = false;

  updateHeater();      
  updateFan(currentMillis);
  updatePump(currentMillis);
  updateLight();


  fan.checkTimer();
  heater.power();
  fan.power();
  lamp.power();
  pump.power();

  if (currentMillis - lastUpdate >= 2000) {
    lastUpdate = currentMillis;
    air.update();
    soil.get_humidity();
    light.get_light();
    
    // Вывод показаний датчиков
    Serial.print("Температку: "); Serial.print(air.temperature);
    Serial.print("C; Влажность: "); Serial.print(air.humidity);
    Serial.print("%; Почва: "); Serial.print(soil.humidity);
    Serial.print("; Свет: "); Serial.print(light.value);
    

    Serial.print("; Вентилятор: "); Serial.print(fan.on_fan ? "ВКЛ" : "ВЫКЛ");
    Serial.print("; Обогрев: "); Serial.print(heater.on_heat ? "ВКЛ" : "ВЫКЛ");
    Serial.print("; Лампа: "); Serial.print(lamp.on_lamp ? "ВКЛ" : "ВЫКЛ");
    Serial.print("; Помпа: "); Serial.println(pump.on_pump ? "ВКЛ" : "ВЫКЛ");
  }
}
