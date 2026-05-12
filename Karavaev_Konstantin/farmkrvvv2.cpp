#include <DHT.h>

/**
 * КОНФИГУРАЦИЯ ПОРТОВ (PINS)
 */
const int PIN_DHT11        = 2;  // Датчик переехал во 2-й порт
const int PIN_HEATER       = 4;
const int PIN_PUMP         = 5;
const int PIN_LAMP         = 6;
const int PIN_FAN          = 7;
const int PIN_LIGHT_SENSOR = A0;
const int PIN_SOIL_SENSOR  = A1;

/**
 * ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
 */
bool isNight = false;
unsigned long lastVentTime = 0;
bool isVenting = false;

/**
 * СТРУКТУРА КЛИМАТИЧЕСКИХ ПРОФИЛЕЙ
 */
struct Profile {
    float tempHigh;        // Порог жары (вкл. вентилятор)
    float tempLow;         // Порог холода (вкл. обогрев)
    float humHigh;         // Порог влажности воздуха
    float humTempLimit;    // Температура, ниже которой включаем подогрев для осушения
    int soilLow;           // Порог полива (сухая почва)
    int soilHigh;          // Порог остановки полива
    int lightThreshold;    // Порог освещенности
    unsigned long ventInterval; // Время между проветриваниями
    unsigned long ventDuration; // Длительность проветривания
};

const Profile profiles[] = {
    {
        30.0, 22.0,        // Температура (Max/Min)
        75.0, 35.0,        // Влажность (Max/TempLimit)
        350, 700,          // Почва
        400,               // Свет
        1800000, 120000    // Проветривание: раз в 30 мин на 2 мин
    }
};

/**
 * БЛОК ДАТЧИКОВ (SENSORS)
 */

class DHTReader {
private:
    DHT dht;
public:
    float temperature;
    float humidity;

    DHTReader(int pin) : dht(pin, DHT11) {}

    void begin() {
        dht.begin();
        temperature = 22.0;
        humidity = 50.0;
    }

    void update() {
        float t = dht.readTemperature();
        float h = dht.readHumidity();
        if (!isnan(t)) temperature = t;
        if (!isnan(h)) humidity = h;
    }
};

class TemperatureSensor {
private:
    DHTReader& dhtReader;
public:
    float value;
    TemperatureSensor(DHTReader& readerRef) : dhtReader(readerRef), value(22.0) {}
    void read() { value = dhtReader.temperature; }
};

class HumiditySensor {
private:
    DHTReader& dhtReader;
public:
    float value;
    HumiditySensor(DHTReader& readerRef) : dhtReader(readerRef), value(50.0) {}
    void read() { value = dhtReader.humidity; }
};

class SoilMoistureSensor {
private:
    int pin;
public:
    int moisture;
    SoilMoistureSensor(int pin) : pin(pin), moisture(500) {}
    void read() { moisture = analogRead(pin); }
};

class LightSensor {
private:
    int pin;
public:
    int lightLevel;
    LightSensor(int pin) : pin(pin), lightLevel(500) {}
    void read() { lightLevel = analogRead(pin); }
};

/**
 * БЛОК АКТУАТОРОВ (ACTUATORS)
 */

class Fan {
private:
    int pin;
    bool currentState;
public:
    bool requestFanTemp;
    bool requestFanHum;
    bool requestFanVent;

    Fan(int pin) : pin(pin), currentState(false), requestFanTemp(false), 
                   requestFanHum(false), requestFanVent(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() {
        if (isNight) {
            digitalWrite(pin, LOW);
            currentState = false;
            return;
        }
        bool shouldFan = requestFanTemp || requestFanHum || requestFanVent;
        digitalWrite(pin, shouldFan ? HIGH : LOW); 
        currentState = shouldFan;
    }

    bool isOn() const { return currentState; }
};

class Heater {
private:
    int pin;
    Fan& fan;
public:
    bool requestHeatTemp;
    bool requestHeatHum;

    Heater(int pin, Fan& fanRef) : pin(pin), fan(fanRef), 
                                   requestHeatTemp(false), requestHeatHum(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void power() {
        // Обогрев работает только с вентилятором для конвекции
        bool shouldHeat = (requestHeatTemp || requestHeatHum) && fan.isOn();
        digitalWrite(pin, shouldHeat ? HIGH : LOW); 
    }
};

class Lamp {
private:
    int pin;
public:
    bool requestLight;
    Lamp(int pin) : pin(pin), requestLight(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
    void power() {
        digitalWrite(pin, requestLight ? HIGH : LOW); 
    }
};

class Pump {
private:
    int pin;
public:
    bool requestPump;
    Pump(int pin) : pin(pin), requestPump(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
    void power() {
        digitalWrite(pin, requestPump ? HIGH : LOW); 
    }
};

/**
 * ЛОГИКА УПРАВЛЕНИЯ (REGULATIONS)
 */

void control_temperature(const TemperatureSensor& ts, Heater& h, Fan& f, const Profile& p) {
    if (ts.value > p.tempHigh) {
        h.requestHeatTemp = false;
        f.requestFanTemp = true;
    } else if (ts.value < p.tempLow) {
        h.requestHeatTemp = true;
        f.requestFanTemp = true;
    } else {
        h.requestHeatTemp = false;
        f.requestFanTemp = false;
    }
}

void control_humidity(const HumiditySensor& hs, const TemperatureSensor& ts, Heater& h, Fan& f, const Profile& p) {
    if (hs.value > p.humHigh) {
        f.requestFanHum = true;
        h.requestHeatHum = (ts.value < p.humTempLimit);
    } else {
        f.requestFanHum = false;
        h.requestHeatHum = false;
    }
}

void control_soilmoisture(const SoilMoistureSensor& ss, Pump& pmp, const Profile& p) {
    if (ss.moisture > p.soilHigh) pmp.requestPump = true;
    else if (ss.moisture < p.soilLow) pmp.requestPump = false;
}

void control_light(const LightSensor& ls, Lamp& lmp, const Profile& p) {
    // Свет нужен когда темно (ниже порога), кроме ночи
    if (!isNight && ls.lightLevel < p.lightThreshold) {
        lmp.requestLight = true;
    } else {
        lmp.requestLight = false;
    }
}

void control_ventilation(Fan& f, const Profile& p) {
    if (isNight) {
        isVenting = false;
        f.requestFanVent = false;
        return;
    }
    unsigned long now = millis();
    if (!isVenting && (now - lastVentTime >= p.ventInterval)) {
        isVenting = true;
        lastVentTime = now;
        f.requestFanVent = true;
    }
    if (isVenting && (now - lastVentTime >= p.ventDuration)) {
        isVenting = false;
        f.requestFanVent = false;
    }
}

void checkNightTime() {
    // 10 секунд реального времени = 1 час в программе для теста
    unsigned long hours = (millis() / 10000) % 24;
    isNight = (hours >= 22 || hours < 6);
}

/**
 * ИНИЦИАЛИЗАЦИЯ
 */
DHTReader dhtReader(PIN_DHT11);
TemperatureSensor temperature(dhtReader);
HumiditySensor airHumidity(dhtReader);
SoilMoistureSensor soilSensor(PIN_SOIL_SENSOR);
LightSensor lightSensor(PIN_LIGHT_SENSOR);

Fan fan(PIN_FAN);
Heater heater(PIN_HEATER, fan);
Lamp lamp(PIN_LAMP);
Pump pump(PIN_PUMP);

void setup() {
    Serial.begin(9600);
    dhtReader.begin();
    Serial.println(F("--- Greenhouse System Ready ---"));
}

void loop() {
    const Profile& currentProfile = profiles[0];
    
    checkNightTime();
    dhtReader.update();

    temperature.read();
    airHumidity.read();
    soilSensor.read();
    lightSensor.read();

    control_temperature(temperature, heater, fan, currentProfile);
    control_humidity(airHumidity, temperature, heater, fan, currentProfile);
    control_soilmoisture(soilSensor, pump, currentProfile);
    control_light(lightSensor, lamp, currentProfile);
    control_ventilation(fan, currentProfile);

    fan.power();
    heater.power();
    lamp.power();
    pump.power();

    // Вывод в монитор порта для отладки
    Serial.print(F("Temp: ")); Serial.print(temperature.value);
    Serial.print(F(" | Light: ")); Serial.print(lightSensor.lightLevel);
    Serial.print(F(" | Night: ")); Serial.println(isNight);

    delay(2000);
}