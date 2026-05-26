
#include <Arduino.h>
#include <DHT.h>
#define DHT_MODEL DHT11

const byte DHT_PIN = 2;
const byte TEMP_PIN = A4;
const byte HUM_PIN = A5;
const byte SOIL_PIN = A1;
const byte LIGHT_PIN = A0;

const byte PUMP_PIN = 5;
const byte FAN_PIN = 7;
const byte HEATER_PIN = 4;
const byte LAMP_PIN = 6;

const unsigned long AirSensor_READ_INTERVAL = 2000UL;
const unsigned long PRINT_INTERVAL = 5000UL;

const unsigned long PUMP_WORK_TIME = 3000UL;
const unsigned long PUMP_PAUSE_TIME = 10000UL;

const unsigned long MINUTE_MS = 60000UL;
const unsigned long HOUR_MS = 3600000UL;
const unsigned long DAY_MS = 86400000UL;

const byte START_HOUR = 12;

const int SOIL_DRY_RAW = 0;
const int SOIL_WET_RAW = 1023;

const int LIGHT_DARK_RAW = 1023;
const int LIGHT_BRIGHT_RAW = 0;

using Celsius = float;
using Percent = float;
using Minutes = unsigned int;

struct ClimateSettings {
  Celsius minTemp, maxTemp;

  Percent maxAirHumidity;
  Percent minSoilHumidity;

  Percent minLight;

  byte nightStart, nightEnd;

  Minutes ventilationPeriod, ventilationDuration;
};

const ClimateSettings climateSettings = {28.0, 34.0, 70.0, 35, 50, 22, 6, 180, 5};

int limitToPercentRange(long value) {
  if (value < 0) {
    return 0;
  }

  if (value > 100) {
    return 100;
  }

  return (int)value;
}

int rawToPercent(int raw, int rawAtZero, int rawAtHundred) {
  if (rawAtZero == rawAtHundred) {
    return 0;
  }

  long percent = (long)(raw - rawAtZero) * 100L;
  percent = percent / (rawAtHundred - rawAtZero);

  return limitToPercentRange(percent);
}

byte getHour() {
  byte passedHours = (millis() % DAY_MS) / HOUR_MS;
  return (START_HOUR + passedHours) % 24;
}

Minutes getMinuteOfDay() {
  unsigned long passedMinutes = (millis() % DAY_MS) / MINUTE_MS;
  return (Minutes)((START_HOUR * 60 + passedMinutes) % 1440);
}

bool isNight() {
  byte hour = getHour();

  if (climateSettings.nightStart < climateSettings.nightEnd) return hour >= climateSettings.nightStart && hour < climateSettings.nightEnd;
  return hour >= climateSettings.nightStart || hour < climateSettings.nightEnd;
}

class Sensor {
public:
  virtual void begin() = 0;
  virtual void update() = 0;
};

class Controller {
public:
  virtual void update() = 0;
};

class AirSensor : public Sensor {
private:
  DHT dht;

  float temperatureValue;
  float humidityValue;

  bool temperatureIsReady;
  bool humidityIsReady;

  bool wasRead;
  unsigned long lastReadTime;

public:
  AirSensor(byte pin) : dht(pin, DHT_MODEL), temperatureValue(0), humidityValue(0),
        temperatureIsReady(false), humidityIsReady(false), wasRead(false),
        lastReadTime(0) {}

  void begin() override {
    dht.begin();
    pinMode(TEMP_PIN, INPUT);
    pinMode(HUM_PIN, INPUT);
  }

  void update() override {
    unsigned long now = millis();

    if (wasRead && now - lastReadTime < AirSensor_READ_INTERVAL) {
      return;
    }

    wasRead = true;
    lastReadTime = now;

    float newHumidity = analogRead(HUM_PIN) / 10;
    float newTemperature = analogRead(TEMP_PIN) / 30;

    if (!isnan(newHumidity)) {
      humidityValue = newHumidity;
      humidityIsReady = true;
    }

    if (!isnan(newTemperature)) {
      temperatureValue = newTemperature;
      temperatureIsReady = true;
    }
  }

  bool hasTemperature() const {
    return temperatureIsReady;
  }

  bool hasHumidity() const {
    return humidityIsReady;
  }

  float getTemperature() const {
    return temperatureValue;
  }

  float getHumidity() const {
    return humidityValue;
  }
};

class AnalogSensor : public Sensor {
private:
  byte pin;
  int rawValue;
  int percentValue;

  int rawAtZero;
  int rawAtHundred;

public:
  AnalogSensor(byte sensorPin, int zeroValue, int hundredValue)
      : pin(sensorPin), rawValue(0), percentValue(0), rawAtZero(zeroValue),
        rawAtHundred(hundredValue) {}

  void begin() override {
    pinMode(pin, INPUT);
  }

  void update() override {
    rawValue = analogRead(pin);
    percentValue = rawToPercent(rawValue, rawAtZero, rawAtHundred);
  }

  int percent() const {
    return percentValue;
  }

  int raw() const {
    return rawValue;
  }
};

class Actuator {
private:
  byte pin;
  bool activeHigh;
  bool needToTurnOn;

public:
  Actuator(byte devicePin, bool isActiveHigh = true) : pin(devicePin), activeHigh(isActiveHigh), needToTurnOn(false) {}

  void begin() {
    pinMode(pin, OUTPUT);
    off();
    apply();
  }

  void reset() {
    needToTurnOn = false;
  }

  void on() {
    needToTurnOn = true;
  }

  void off() {
    needToTurnOn = false;
  }

  bool isOn() const {
    return needToTurnOn;
  }

  void apply() {
    if (activeHigh) {
      digitalWrite(pin, needToTurnOn ? HIGH : LOW);
    } else {
      digitalWrite(pin, needToTurnOn ? LOW : HIGH);
    }
  }
};

class LightController : public Controller {
private:
  AnalogSensor &lightSensor;
  Actuator &lamp;

public:
  LightController(AnalogSensor &light, Actuator &lampDevice) : lightSensor(light), lamp(lampDevice) {}

  void update() override {
    if (!isNight() && lightSensor.percent() < climateSettings.minLight) {
      lamp.on();
    }
  }
};

class WateringController : public Controller {
private:
  AnalogSensor &soilSensor;
  Actuator &pump;

  bool pumpIsWorking;
  bool pumpIsWaiting;

  unsigned long pumpStartTime;
  unsigned long pauseStartTime;

public:
  WateringController(AnalogSensor &soil, Actuator &pumpDevice)
      : soilSensor(soil), pump(pumpDevice), pumpIsWorking(false),
        pumpIsWaiting(false), pumpStartTime(0), pauseStartTime(0) {}

  void update() override {
    unsigned long now = millis();

    if (soilSensor.percent() >= climateSettings.minSoilHumidity) {
      pumpIsWorking = false;
      pumpIsWaiting = false;
      return;
    }

    if (pumpIsWorking) {
      if (now - pumpStartTime < PUMP_WORK_TIME) {
        pump.on();
      } else {
        pumpIsWorking = false;
        pumpIsWaiting = true;
        pauseStartTime = now;
      }

      return;
    }

    if (pumpIsWaiting) {
      if (now - pauseStartTime < PUMP_PAUSE_TIME) {
        return;
      }

      pumpIsWaiting = false;
    }

    pumpIsWorking = true;
    pumpStartTime = now;
    pump.on();
  }
};

class TemperatureController : public Controller {
private:
  AirSensor &airSensor;
  Actuator &heater;
  Actuator &fan;

public:
  TemperatureController(AirSensor &air, Actuator &heaterDevice, Actuator &fanDevice) : airSensor(air), heater(heaterDevice), fan(fanDevice) {}

  void update() override {
    if (!airSensor.hasTemperature()) {
      return;
    }

    float temp = airSensor.getTemperature();

    if (temp > climateSettings.maxTemp) {
      fan.on();
      return;
    }

    if (temp < climateSettings.minTemp) {
      heater.on();
      fan.on();
    }
  }
};

class HumidityController : public Controller {
private:
  AirSensor &airSensor;
  Actuator &fan;

public:
  HumidityController(AirSensor &air, Actuator &fanDevice)
      : airSensor(air), fan(fanDevice) {}

  void update() override {
    if (!airSensor.hasHumidity()) {
      return;
    }

    if (airSensor.getHumidity() > climateSettings.maxAirHumidity) {
      fan.on();
    }
  }
};

class VentilationController : public Controller {
private:
  Actuator &fan;

public:
  VentilationController(Actuator &fanDevice) : fan(fanDevice) {}

  void update() override {
    if (isNight()) {
      return;
    }

    unsigned int minute = getMinuteOfDay();
    unsigned int period = climateSettings.ventilationPeriod;
    unsigned int duration = climateSettings.ventilationDuration;

    if (period > 0 && duration > 0) {
      if (minute % period < duration) {
        fan.on();
      }
    }
  }
};

AirSensor air(DHT_PIN);

AnalogSensor soil(SOIL_PIN, SOIL_DRY_RAW, SOIL_WET_RAW);
AnalogSensor light(LIGHT_PIN, LIGHT_DARK_RAW, LIGHT_BRIGHT_RAW);

Actuator pump(PUMP_PIN);
Actuator fan(FAN_PIN);
Actuator heater(HEATER_PIN);
Actuator lamp(LAMP_PIN);

LightController lightController(light, lamp);
WateringController wateringController(soil, pump);
TemperatureController temperatureController(air, heater, fan);
HumidityController humidityController(air, fan);
VentilationController ventilationController(fan);

void printStatus() {
  static unsigned long lastPrintTime = 0;

  if (millis() - lastPrintTime < PRINT_INTERVAL) {
    return;
  }

  lastPrintTime = millis();

  Serial.print(("Hour: "));
  Serial.println(getHour());

  Serial.print(("Night: "));
  Serial.println(isNight() ? F("true") : F("false"));

  Serial.print(("Temperature: "));
  if (air.hasTemperature()) {
    Serial.print(air.getTemperature());
    Serial.println((" C"));
  } else {
    Serial.println(("N/A"));
  }

  Serial.print(("Air humidity: "));
  if (air.hasHumidity()) {
    Serial.print(air.getHumidity());
    Serial.println((" %"));
  } else {
    Serial.println(("N/A"));
  }

  Serial.print(("Soil humidity: "));
  Serial.print(soil.percent());
  Serial.print((" %, raw = "));
  Serial.println(soil.raw());

  Serial.print(("Light: "));
  Serial.print(light.percent());
  Serial.print((" %, raw = "));
  Serial.println(light.raw());

  Serial.print(("Pump: "));
  if (pump.isOn()) {
    Serial.println("ON");
  }
  else {
    Serial.println("OFF");
  }
  

  Serial.print(("Fan: "));
  if (fan.isOn()) {
    Serial.println("ON");
  }
  else {
    Serial.println("OFF");
  }

  Serial.print(("Heater: "));
  if (heater.isOn()) {
    Serial.println("ON");
  }
  else {
    Serial.println("OFF");
  }

  Serial.print(("Lamp: "));
  if (lamp.isOn()) {
    Serial.println("ON");
  }
  else {
    Serial.println("OFF");
  }

  Serial.println();
}

void setup() {
  Serial.begin(9600);

  air.begin();
  soil.begin();
  light.begin();
  
  pump.begin();
  fan.begin();
  heater.begin();
  lamp.begin();

  Serial.println(("Started"));
}

void loop() {
  air.update();
  soil.update();
  light.update();

  pump.reset();
  fan.reset();
  heater.reset();
  lamp.reset();

  lightController.update();
  wateringController.update();
  temperatureController.update();
  humidityController.update();
  ventilationController.update();

  pump.apply();
  fan.apply();
  heater.apply();
  lamp.apply();

  printStatus();

  delay(100);
}
