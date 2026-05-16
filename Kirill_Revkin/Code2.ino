#include <DHT.h>


const int DHT_PIN = 8;
const int SOIL_PIN = A1;
const int LIGHT_PIN = A0;

const int FAN_PIN = 7;
const int HEATER_PIN = 4;
const int LAMP_PIN = 6;
const int PUMP_PIN = 5;


const int SOIL_RAW_DRY = 1023;  
const int SOIL_RAW_WET = 0;  

const int LIGHT_RAW_DARK = 1023;    
const int LIGHT_RAW_BRIGHT = 0;  


const unsigned long ONE_HOUR = 60UL * 60UL * 1000UL;
const unsigned long ONE_DAY = 24UL * ONE_HOUR;

const unsigned long VENT_PERIOD = 6UL * ONE_HOUR;   
const unsigned long VENT_DURATION = 6UL * 60UL * 1000UL;

const int DAY_START_HOUR = 6;
const int NIGHT_START_HOUR = 22;

const unsigned long DHT_READ_PERIOD = 2000UL;
const unsigned long PRINT_PERIOD = 2000UL;


struct Plant {
  int min_temperature;
  int max_temperature;

  int min_air_humidity;
  int max_air_humidity;

  int min_soil_humidity;
  int max_soil_humidity;

  int min_light;
  int max_light;
};

Plant tomato;

void tomato_init() {
  tomato.min_temperature = 20;
  tomato.max_temperature = 30;

  tomato.min_air_humidity = 50;
  tomato.max_air_humidity = 70;

  tomato.min_soil_humidity = 35;
  tomato.max_soil_humidity = 75;

  tomato.min_light = 45;
  tomato.max_light = 90;
}


int inverted_sensor_to_percent(int rawValue, int rawAtZeroPercent, int rawAtHundredPercent) {
  long percent = (long)(rawAtZeroPercent - rawValue) * 100L;
  percent = percent / (rawAtZeroPercent - rawAtHundredPercent);

  if (percent < 0) {
    percent = 0;
  }

  if (percent > 100) {
    percent = 100;
  }

  return (int)percent;
}

int get_hour() {
  unsigned long timeInDay = millis() % ONE_DAY;
  return timeInDay / ONE_HOUR;
}

bool is_night() {
  int hour = get_hour();

  if (hour >= NIGHT_START_HOUR || hour < DAY_START_HOUR) {
    return true;
  }

  return false;
}


class AirSensor {
private:
  DHT dht;
  unsigned long lastReadTime;

public:
  float temperature;
  float humidity;

  AirSensor(int pin) : dht(pin, DHT11) {
    temperature = 0;
    humidity = 0;
    lastReadTime = 0;
  }

  void begin() {
    dht.begin();
  }

  void update() {
    if (lastReadTime != 0 && millis() - lastReadTime < DHT_READ_PERIOD) {
      return;
    }

    lastReadTime = millis();

    float newHumidity = dht.readHumidity();
    float newTemperature = dht.readTemperature();

    if (newHumidity >= 0 && newHumidity <= 100) {
      humidity = newHumidity;
    }

    if (newTemperature > -40 && newTemperature < 80) {
      temperature = newTemperature;
    }
  }
};

class HygrometerSoil {
private:
  int pin;

public:
  int raw;  
  int humidity;

  HygrometerSoil(int sensorPin) {
    pin = sensorPin;
    raw = 0;
    humidity = 0;
  }

  void update() {
    raw = analogRead(pin);
    humidity = inverted_sensor_to_percent(raw, SOIL_RAW_DRY, SOIL_RAW_WET);
  }
};

class LightSensor {
private:
  int pin;

public:
  int raw;    
  int light;  

  LightSensor(int sensorPin) {
    pin = sensorPin;
    raw = 0;
    light = 0;
  }

  void update() {
    raw = analogRead(pin);
    light = inverted_sensor_to_percent(raw, LIGHT_RAW_DARK, LIGHT_RAW_BRIGHT);
  }
};


class Fan {
private:
  int pin;

public:
  bool on_fan;

  Fan(int devicePin) {
    pin = devicePin;
    on_fan = false;
  }

  void begin() {
    pinMode(pin, OUTPUT);
  }

  void power() {
    if (on_fan) {
      digitalWrite(pin, HIGH);
    }
    else {
      digitalWrite(pin, LOW);
    }
  }
};

class Heater {
private:
  int pin;

public:
  bool on_heat;

  Heater(int devicePin) {
    pin = devicePin;
    on_heat = false;
  }

  void begin() {
    pinMode(pin, OUTPUT);
  }

  void power() {
    if (on_heat) {
      digitalWrite(pin, HIGH);
    }
    else {
      digitalWrite(pin, LOW);
    }
  }
};

class Lamp {
private:
  int pin;

public:
  bool on_lamp;

  Lamp(int devicePin) {
    pin = devicePin;
    on_lamp = false;
  }

  void begin() {
    pinMode(pin, OUTPUT);
  }

  void power() {
    if (on_lamp) {
      digitalWrite(pin, HIGH);
    }
    else {
      digitalWrite(pin, LOW);
    }
  }
};

class Pump {
private:
  int pin;

public:
  bool on_pump;

  Pump(int devicePin) {
    pin = devicePin;
    on_pump = false;
  }

  void begin() {
    pinMode(pin, OUTPUT);
  }

  void power() {
    if (on_pump && millis() % 10000UL < 2000UL) {
      digitalWrite(pin, HIGH);
    }
    else {
      digitalWrite(pin, LOW);
    }
  }
};


AirSensor air(DHT_PIN);
HygrometerSoil soil(SOIL_PIN);
LightSensor lightSensor(LIGHT_PIN);

Fan fan(FAN_PIN);
Heater heater(HEATER_PIN);
Lamp lamp(LAMP_PIN);
Pump pump(PUMP_PIN);


void read_all_sensors() {
  air.update();
  soil.update();
  lightSensor.update();
}

void reset_actuators() {
  fan.on_fan = false;
  heater.on_heat = false;
  lamp.on_lamp = false;
  pump.on_pump = false;
}

void control_temperature() {
  if (air.temperature < tomato.min_temperature) {
    heater.on_heat = true;
    fan.on_fan = true;
  }

  if (air.temperature > tomato.max_temperature) {
    heater.on_heat = false;
    fan.on_fan = true;
  }
}

void control_air_humidity() {
  if (air.humidity > tomato.max_air_humidity) {
    fan.on_fan = true;
  }
}

void control_soil_humidity() {
  if (soil.humidity < tomato.min_soil_humidity) {
    pump.on_pump = true;
  }

  if (soil.humidity > tomato.max_soil_humidity) {
    fan.on_fan = true;
  }
}

void control_light() {
  if (lightSensor.light < tomato.min_light && !is_night()) {
    lamp.on_lamp = true;
  }
}

void scheduled_ventilation() {
  if (millis() % VENT_PERIOD < VENT_DURATION) {
    fan.on_fan = true;
  }
}

void apply_actuators() {
  heater.power();
  fan.power();
  lamp.power();
  pump.power();
}

void print_status() {
  static unsigned long lastPrintTime = 0;

  if (millis() - lastPrintTime < PRINT_PERIOD) {
    return;
  }

  lastPrintTime = millis();

  Serial.print("Hour from start: ");
  Serial.println(get_hour());

  Serial.print("Temperature: ");
  Serial.print(air.temperature);
  Serial.println(" C");

  Serial.print("Air humidity: ");
  Serial.print(air.humidity);
  Serial.println(" %");

  Serial.print("Soil raw: ");
  Serial.print(soil.raw);
  Serial.print("Soil humidity: ");
  Serial.print(soil.humidity);
  Serial.println(" %");

  Serial.print("Light raw: ");
  Serial.print(lightSensor.raw);
  Serial.print("Light: ");
  Serial.print(lightSensor.light);
  Serial.println(" %");

  Serial.print("Fan: ");
  Serial.println(fan.on_fan ? "ON" : "OFF");

  Serial.print("Heater: ");
  Serial.println(heater.on_heat ? "ON" : "OFF");

  Serial.print("Lamp: ");
  Serial.println(lamp.on_lamp ? "ON" : "OFF");

  Serial.print("Pump: ");
  Serial.println(pump.on_pump ? "ON" : "OFF");

  Serial.println();
}


void setup() {
  Serial.begin(9600);

  tomato_init();

  air.begin();
  fan.begin();
  heater.begin();
  lamp.begin();
  pump.begin();

  Serial.println("Smart Farm Started");
}

void loop() {
  read_all_sensors();

  reset_actuators();

  control_temperature();
  control_air_humidity();
  control_soil_humidity();
  control_light();
  scheduled_ventilation();

  apply_actuators();
  print_status();
}
