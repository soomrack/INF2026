#include <stdio.h>
#include <DHT.h>

struct Plant {
  int max_temperature;
  int min_temperature;
  int max_Ahumidity;
  int min_Ahumidity;
  int max_Shumidity;
  int min_Shumidity;
  int max_light;
  int min_light;
  int night_light;
};

Plant tomato;

void tomato_init() {
  tomato.max_temperature = 30;
  tomato.min_temperature = 20;
  tomato.max_Shumidity = 800;
  tomato.min_Shumidity = 600;
  tomato.max_Ahumidity = 70;
  tomato.min_Ahumidity = 50;
  tomato.max_light = 700;
  tomato.min_light = 500;
}

// датчики
class AirSensor {
private:
  int pin;
  DHT dht;
public:
  float humidity;
  float temperature;
  AirSensor(int pin) : dht(pin, DHT11), pin(pin) {
    humidity = 0;
    temperature = 0;
  }
  void begin() { dht.begin(); }
  void update() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    if (!isnan(h) && !isnan(t)) {
      humidity = h;
      temperature = t;
    }
  }
};

class HygrometerSoil {
private:
  int pin;
public:
  int humidity;
  HygrometerSoil(int pin) : pin(pin) { humidity = 0; }
  void get_humidity() { humidity = analogRead(pin); }
};

class Light {
private:
  int pin;
public:
  int light;
  Light(int pin) : pin(pin) { light = 0; }
  void get_light() { light = analogRead(pin); }
};

// актуаторы
class Lamp {
private:
  int pin;
public:
  bool on_lamp;
  Lamp(int pin) : pin(pin) {
    on_lamp = false;
    pinMode(pin, OUTPUT);
  }
  void power();
};

class Fan {
private:
  int pin;
public:
  bool on_fan;
  Fan(int pin) : pin(pin) {
    on_fan = false;
    pinMode(pin, OUTPUT);
  }
  void power();
};

class Heater {
private:
  int pin;
public:
  bool on_heat;
  Heater(int pin) : pin(pin) {
    on_heat = false;
    pinMode(pin, OUTPUT);
  }
  void power();
};

class Pump {
private:
  int pin;
public:
  bool on_pump;
  Pump(int pin) : pin(pin) {
    on_pump = false;
    pinMode(pin, OUTPUT);
  }
  void power();
};

void Heater::power() {
  if (on_heat) { digitalWrite(pin, HIGH); }
  else { digitalWrite(pin, LOW); }
}

void Pump::power() {
  if (on_pump && millis() % 10000 <= 2000) { digitalWrite(pin, HIGH); }
  else { digitalWrite(pin, LOW); }
}

void Lamp::power() {
  if (on_lamp) { digitalWrite(pin, HIGH); }
  else { digitalWrite(pin, LOW); }
}

void Fan::power() {
  if (on_fan) { digitalWrite(pin, HIGH); }
  else { digitalWrite(pin, LOW); }
}

void control_temperature(AirSensor &t, Heater &h, Fan &f, Plant &plant, Pump &p);
void control_air_humidity(AirSensor &hyg, Fan &f, Plant &plant);
void control_soil_humidity(HygrometerSoil &hyg, Pump &p, Fan &f, Plant &plant);
void control_light(Light &lig, Lamp &l, Plant &p);
void scheduled_ventilation(Fan &f, AirSensor &t, Plant &plant);


void control_temperature(AirSensor &t, Heater &h, Fan &f, Plant &plant, Pump &p) {
  if (p.on_pump == true) {
    h.on_heat = false;
    return;
  }
  if (t.temperature < plant.min_temperature) {
    h.on_heat = true; // включаем обогрев
    f.on_fan = true;  // включаем обдув вместе с обогревом
  }
  if (t.temperature > plant.max_temperature) {
    f.on_fan = true;  // Жарко - просто проветриваем
  }
}

void control_air_humidity(AirSensor &hyg, Fan &f, Plant &plant) {
  if (hyg.humidity > plant.min_Ahumidity && hyg.humidity < plant.max_Ahumidity) {
    f.on_fan = false;
  }
  else if (hyg.humidity <= plant.min_Ahumidity) {
    f.on_fan = false;
  }
  else if (hyg.humidity >= plant.max_Ahumidity) {
    f.on_fan = true;
  }
}

void control_soil_humidity(HygrometerSoil &hyg, Pump &p, Fan &f, Plant &plant) {
  if (hyg.humidity <= plant.min_Shumidity) {
    p.on_pump = true;
    f.on_fan = false;
  }
  else if (hyg.humidity >= plant.max_Shumidity) {
    p.on_pump = false;
    f.on_fan = true;
  }
   else  {
    p.on_pump = false;
    f.on_fan = false;
  }
}

void control_light(Light &lig, Lamp &l, Plant &p) {
  if (lig.light > p.min_light && lig.light < p.max_light) {
    l.on_lamp = true;
  }
  else {
    l.on_lamp = false;
  }
}

void scheduled_ventilation(Fan &f, AirSensor &t, Plant &plant) {
  const unsigned long int sixhours = 21600000;
  const unsigned long int sixminutes = 360000;
  if (t.temperature < plant.min_temperature) {
    return; // Выходим из функции прямо здесь, игнорируя таймер ниже
  }
  if (millis() % sixhours > 0 && millis() % sixhours <= sixminutes) {
    f.on_fan = true;
  }
}

Fan fan(7);
Lamp lamp(6);
Heater heater(4);
Pump pump(5);

AirSensor air(2);
HygrometerSoil soil(A1);
Light light(A0);

void setup() {
  Serial.begin(9600);
  air.begin();
  tomato_init();
}

unsigned long lastUpdate = 0;

void loop() {
  if (millis() - lastUpdate >= 2000) { // датчик не может быстрее
    air.update();
  }
  soil.get_humidity();
  light.get_light();

  control_temperature(air, heater, fan, tomato, pump);
  control_air_humidity(air, fan, tomato);
  control_soil_humidity(soil, pump, fan, tomato);
  control_light(light, lamp, tomato);
  scheduled_ventilation(fan, air, tomato);

  heater.power();
  fan.power();
  lamp.power();
  pump.power();

  if (millis() - lastUpdate >= 2000) {
    lastUpdate = millis();
    Serial.print(" влажность почвы "); Serial.print(soil.humidity);
    Serial.print(" влажность воздуха "); Serial.print(air.humidity);
    Serial.print(" температура "); Serial.print(air.temperature);
    Serial.print(" освещенность "); Serial.println(light.light);
  }
}
