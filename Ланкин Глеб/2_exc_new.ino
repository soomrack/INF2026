#include <Arduino.h>
#include <DHT.h>


const int FAN_PIN = 4;
const int LAMP_PIN = 5;
const int PUMP_PIN = 6;
const int HEATER_PIN = 3;

const int LIGHT_SENSOR_PIN = A1;
const int SOIL_MOISTURE_SENSOR_PIN = A2;

const int DHT_SENSOR_PIN = 2;
#define DHT_TYPE DHT11

DHT dht(DHT_SENSOR_PIN, DHT_TYPE);

struct ClimateProfile {
  const char* name;
  int minTemperature;
  int maxTemperature;
  int minSoilMoisture;
  int maxAirHumidity;
  int minLight;
  int dayStartHour;
  int nightStartHour;
};

// Климат для помидоров
ClimateProfile tomatoClimate = {
  "Tomato climate",

  20,   // minTemperature
  28,   // maxTemperature

  40,   // minSoilMoisture
  75,   // maxAirHumidity

  45,   // minLight

  7,    // dayStartHour
  22    // nightStartHour
};

// Климат для огурцов
ClimateProfile cucumberClimate = {
  "Cucumber climate",

  22,   // minTemperature
  30,   // maxTemperature

  55,   // minSoilMoisture
  85,   // maxAirHumidity

  50,   // minLight

  7,    // dayStartHour
  22    // nightStartHour
};

ClimateProfile* currentClimate = &tomatoClimate;

struct SensorData {
  int temperature;
  int soilMoisture;
  int airHumidity;
  int light;
  int hour;
};

// Базовый класс датчика
class Sensor {
public:
  virtual const char* getName() = 0;
  virtual int readValue() = 0;
};


class SoilMoistureSensor : public Sensor {
private:
  int pin;

public:
  SoilMoistureSensor(int sensorPin) {
    pin = sensorPin;
  }

  const char* getName() {
    return "Soil moisture sensor";
  }

  int readValue() {
    int rawValue = analogRead(pin);

    // Имитация влажности от 0 до 100%
    int moisture = map(rawValue, 0, 1023, 0, 100);

    return moisture;
  }
};


class LightSensor : public Sensor {
private:
  int pin;

public:
  LightSensor(int sensorPin) {
    pin = sensorPin;
  }

  const char* getName() {
    return "Light sensor";
  }

  int readValue() {
    int rawValue = analogRead(pin);

    // Имитация освещенности от 0 до 100%
    int light = map(rawValue, 0, 100, 100, 0);

    return light;
  }
};


class TimeSensor : public Sensor {
public:
  const char* getName() {
    return "Time sensor";
  }

  int readValue() {
    unsigned long seconds = millis() / 1000;

    // 1 час = 5 секунд
    int hour = (seconds / 5) % 24;

    return hour;
  }
};


class DHTTemperatureSensor : public Sensor {
private:
  DHT* dhtSensor;

public:
  DHTTemperatureSensor(DHT* sensor) {
    dhtSensor = sensor;
  }

  const char* getName() {
    return "DHT temperature sensor";
  }

  int readValue() {
    float temperature = dhtSensor->readTemperature();

    if (isnan(temperature)) {
      Serial.println("Error: failed to read temperature from DHT sensor");
      return -1;
}
    return (int)temperature;
  }
};

class DHTAirHumiditySensor : public Sensor {
private:
  DHT* dhtSensor;

public:
  DHTAirHumiditySensor(DHT* sensor) {
    dhtSensor = sensor;
  }

  const char* getName() {
    return "DHT air humidity sensor";
  }

  int readValue() {
    float humidity = dhtSensor->readHumidity();

    if (isnan(humidity)) {
      Serial.println("Error: failed to read humidity from DHT sensor");
      return -1;
}

    return (int)humidity;
  }
};


// Базовый класс актуатора
class Actuator {
private:
  int pin;
  const char* name;
  bool requestedState;
  bool currentState;

public:
  Actuator(const char* actuatorName, int actuatorPin) {
    name = actuatorName;
    pin = actuatorPin;
    requestedState = false;
    currentState = false;
  }

  void begin() {
    pinMode(pin, OUTPUT);
    off();
  }

  const char* getName() {
    return name;
  }

  void requestOn() {
    requestedState = true;
  }

  void requestOff() {
    requestedState = false;
  }

  void resetRequest() {
    requestedState = false;
  }

  void apply() {
    currentState = requestedState;

    if (currentState) {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
  }

  void on() {
    currentState = true;
    digitalWrite(pin, HIGH);
  }

  void off() {
    currentState = false;
    requestedState = false;
    digitalWrite(pin, LOW);
  }

  bool isOn() {
    return currentState;
  }

  void printState() {
    Serial.print(name);
    Serial.print(": ");

    if (currentState) {
      Serial.println("ON");
    } else {
      Serial.println("OFF");
    }
  }
};

// Набор актуаторов

struct GreenhouseActuators {
  Actuator* fan;
  Actuator* pump;
  Actuator* heater;
  Actuator* lamp;
};

// Правила

class ClimateRule {
public:
  virtual const char* getName() = 0;

  virtual void apply(
    SensorData data,
    ClimateProfile climate,
    GreenhouseActuators actuators
  ) = 0;
};


class TemperatureRule : public ClimateRule {
public:
  const char* getName() {
    return "Temperature control";
  }

  void apply(
    SensorData data,
    ClimateProfile climate,
    GreenhouseActuators actuators
  ) {
    if (data.temperature > climate.maxTemperature) {
      actuators.fan->requestOn();
    }

    if (data.temperature < climate.minTemperature) {
      actuators.heater->requestOn();
      actuators.fan->requestOn();

    }
  }
};


class SoilMoistureRule : public ClimateRule {
public:
  const char* getName() {
    return "Soil moisture control";
  }

  void apply(
    SensorData data,
    ClimateProfile climate,
    GreenhouseActuators actuators
  ) {
    if (data.soilMoisture < climate.minSoilMoisture) {
      actuators.pump->requestOn();

    }
  }
};


class LightRule : public ClimateRule {
public:
  const char* getName() {
    return "Light control";
  }

  void apply(
    SensorData data,
    ClimateProfile climate,
    GreenhouseActuators actuators
  ) {
    if (isNight(data.hour, climate)) {
      return;
    }

    if (data.light < climate.minLight) {
      actuators.lamp->requestOn();

    }
  }

private:
  bool isNight(int hour, ClimateProfile climate) {
    if (hour >= climate.nightStartHour || hour < climate.dayStartHour) {
      return true;
    }

    return false;
  }
};


class AirHumidityRule : public ClimateRule {
public:
  const char* getName() {
    return "Air humidity control";
  }

  void apply(
    SensorData data,
    ClimateProfile climate,
    GreenhouseActuators actuators
  ) {
    if (data.airHumidity > climate.maxAirHumidity) {
      actuators.fan->requestOn();

    }
  }
};


class ScheduledVentilationRule : public ClimateRule {
public:
  const char* getName() {
    return "Scheduled ventilation";
  }

  void apply(
    SensorData data,
    ClimateProfile climate,
    GreenhouseActuators actuators
  ) {
    if (isNight(data.hour, climate)) {
      return;
    }

    if (data.hour == 10 || data.hour == 15 || data.hour == 19) {
      actuators.fan->requestOn();
    }
  }

private:
  bool isNight(int hour, ClimateProfile climate) {
    if (hour >= climate.nightStartHour || hour < climate.dayStartHour) {
      return true;
    }

    return false;
  }
};

// датчики

DHTTemperatureSensor temperatureSensor(&dht);
DHTAirHumiditySensor airHumiditySensor(&dht);
SoilMoistureSensor soilMoistureSensor(SOIL_MOISTURE_SENSOR_PIN);
LightSensor lightSensor(LIGHT_SENSOR_PIN);
TimeSensor timeSensor;

// актуаторы
Actuator fan("Fan", FAN_PIN);
Actuator pump("Pump", PUMP_PIN);
Actuator heater("Heater", HEATER_PIN);
Actuator lamp("Lamp", LAMP_PIN);

GreenhouseActuators actuators = {
  &fan,
  &pump,
  &heater,
  &lamp
};


TemperatureRule temperatureRule;
SoilMoistureRule soilMoistureRule;
LightRule lightRule;
AirHumidityRule airHumidityRule;
ScheduledVentilationRule scheduledVentilationRule;


void setup() {
  Serial.begin(9600);

  dht.begin();
  fan.begin();
  pump.begin();
  heater.begin();
  lamp.begin();

  Serial.println("Smart greenhouse started");
  Serial.print("Current climate: ");
  Serial.println(currentClimate->name);

  printArchitectureInfo();
}


void loop() {
  SensorData data;
  data.temperature = temperatureSensor.readValue();
  data.soilMoisture = soilMoistureSensor.readValue();
  data.airHumidity = airHumiditySensor.readValue();
  data.light = lightSensor.readValue();
  data.hour = timeSensor.readValue();

  resetActuatorRequests();

  printSensorData(data);

  temperatureRule.apply(data, *currentClimate, actuators);
  soilMoistureRule.apply(data, *currentClimate, actuators);
  lightRule.apply(data, *currentClimate, actuators);
  airHumidityRule.apply(data, *currentClimate, actuators);
  scheduledVentilationRule.apply(data, *currentClimate, actuators);

  fan.apply();
  pump.apply();
  heater.apply();
  lamp.apply();

  printActuatorStates();

  Serial.println();
  delay(2000);
}


void resetActuatorRequests() {
  fan.resetRequest();
  pump.resetRequest();
  heater.resetRequest();
  lamp.resetRequest();
}


void printSensorData(SensorData data) {

  Serial.print("Climate: ");
  Serial.println(currentClimate->name);

  Serial.print("Hour: ");
  Serial.println(data.hour);

  Serial.print("Temperature: ");
  Serial.print(data.temperature);
  Serial.println(" C");

  Serial.print("Soil moisture: ");
  Serial.print(data.soilMoisture);
  Serial.println(" %");

  Serial.print("Air humidity: ");
  Serial.print(data.airHumidity);
  Serial.println(" %");

  Serial.print("Light: ");
  Serial.print(data.light);
  Serial.println(" %");
}


void printActuatorStates() {
  fan.printState();
  pump.printState();
  heater.printState();
  lamp.printState();

}


void printArchitectureInfo() {
  Serial.println("Sensors:");
  Serial.println(temperatureSensor.getName());
  Serial.println(soilMoistureSensor.getName());
  Serial.println(airHumiditySensor.getName());
  Serial.println(lightSensor.getName());
  Serial.println(timeSensor.getName());

  Serial.println("Actuators:");
  Serial.println(fan.getName());
  Serial.println(pump.getName());
  Serial.println(heater.getName());
  Serial.println(lamp.getName());
}
