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

  tomato.night_light = 100;
}

// датчики
class AirSensor {
private:
  int pin;
  DHT dht;

public:
  float humidity;
  float temperature;

  AirSensor(int pin) : pin(pin), dht(pin, DHT11) {
    humidity = 0;
    temperature = 0;
  }

  void begin() {
    dht.begin();
  }

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

  HygrometerSoil(int pin) : pin(pin) {
    humidity = 0;
  }

  void get_humidity() {
    humidity = analogRead(pin);
  }
};

class Light {
private:
  int pin;

public:
  int light;

  Light(int pin) : pin(pin) {
    light = 0;
  }

  void get_light() {
    light = analogRead(pin);
  }
};

// актуаторы
class Lamp {
private:
  int pin;

public:
  bool on_lamp;

  Lamp(int pin) : pin(pin) {
    on_lamp = false;
  }

  void begin() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  void power() {
    digitalWrite(pin, on_lamp ? HIGH : LOW);
  }
};

class Fan {
private:
  int pin;

public:
  bool on_fan;

  Fan(int pin) : pin(pin) {
    on_fan = false;
  }

  void begin() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  void power() {
    digitalWrite(pin, on_fan ? HIGH : LOW);
  }
};

class Heater {
private:
  int pin;

public:
  bool on_heat;

  Heater(int pin) : pin(pin) {
    on_heat = false;
  }

  void begin() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  void power() {
    digitalWrite(pin, on_heat ? HIGH : LOW);
  }
};

class Pump {
private:
  int pin;

public:
  bool on_pump;

  Pump(int pin) : pin(pin) {
    on_pump = false;
  }

  void begin() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  void power() {
    if (on_pump && millis() % 10000UL <= 2000UL) {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
  }
};

// функции управления
void control_temperature(AirSensor &air, Heater &heater, Plant &plant);
void control_soil_humidity(HygrometerSoil &soil, Pump &pump, Plant &plant);
void control_light(Light &light, Lamp &lamp, Plant &plant);

bool need_fan_temperature(AirSensor &air, Plant &plant);
bool need_fan_air_humidity(AirSensor &air, Plant &plant);
bool need_fan_soil_humidity(HygrometerSoil &soil, Plant &plant);
bool need_scheduled_ventilation();

void control_temperature(AirSensor &air, Heater &heater, Plant &plant) {
  if (air.temperature <= plant.min_temperature) {
    heater.on_heat = true;
  } else {
    heater.on_heat = false;
  }
}

void control_soil_humidity(HygrometerSoil &soil, Pump &pump, Plant &plant) {
  /*
    Для большинства аналоговых датчиков влажности почвы:
    большее значение = суше,
    меньшее значение = влажнее.

    800 — сухо, включаем насос.
    600 — уже достаточно влажно, выключаем насос.
  */

  if (soil.humidity >= plant.max_Shumidity) {
    pump.on_pump = true;
  } else if (soil.humidity <= plant.min_Shumidity) {
    pump.on_pump = false;
  }
}

void control_light(Light &light, Lamp &lamp, Plant &plant) {
  /*
    Лампа включается, если света мало.
    Выключается, если света уже достаточно много.
    Между min_light и max_light состояние не меняется,
    чтобы лампа не мигала около границы.
  */

  if (light.light <= plant.min_light) {
    lamp.on_lamp = true;
  } else if (light.light >= plant.max_light) {
    lamp.on_lamp = false;
  }
}

// управление вентилятором
bool need_fan_temperature(AirSensor &air, Plant &plant) {
  return air.temperature >= plant.max_temperature;
}

bool need_fan_air_humidity(AirSensor &air, Plant &plant) {
  return air.humidity >= plant.max_Ahumidity;
}

bool need_fan_soil_humidity(HygrometerSoil &soil, Plant &plant) {
  /*
    Если значение влажности почвы слишком маленькое,
    значит почва очень влажная — можно включить вентиляцию.
  */
  return soil.humidity <= plant.min_Shumidity;
}

bool need_scheduled_ventilation() {
  const unsigned long sixhours = 21600000UL;
  const unsigned long sixminutes = 360000UL;

  unsigned long phase = millis() % sixhours;

  return phase > 0 && phase <= sixminutes;
}

// объекты
Fan fan(7);
Lamp lamp(6);
Heater heater(4);
Pump pump(5);

AirSensor air(2);
HygrometerSoil soil(A1);
Light light(A0);

unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(9600);

  air.begin();

  fan.begin();
  lamp.begin();
  heater.begin();
  pump.begin();

  tomato_init();
}

void loop() {
  if (millis() - lastUpdate >= 2000UL) {
    air.update();
    lastUpdate = millis();

    Serial.print(" влажность почвы ");
    Serial.print(soil.humidity);

    Serial.print(" влажность воздуха ");
    Serial.print(air.humidity);

    Serial.print(" температура ");
    Serial.print(air.temperature);

    Serial.print(" освещенность ");
    Serial.println(light.light);
  }

  soil.get_humidity();
  light.get_light();

  control_temperature(air, heater, tomato);
  control_soil_humidity(soil, pump, tomato);
  control_light(light, lamp, tomato);

  fan.on_fan =
    need_fan_temperature(air, tomato) ||
    need_fan_air_humidity(air, tomato) ||
    need_fan_soil_humidity(soil, tomato) ||
    need_scheduled_ventilation();

  heater.power();
  fan.power();
  lamp.power();
  pump.power();
}