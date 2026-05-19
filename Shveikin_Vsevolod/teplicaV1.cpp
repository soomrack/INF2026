#include <Arduino.h>
#include <Adafruit_Sensor.h> 
#include <DHT.h>

//          ИНТЕРФЕЙСЫ 

// Базовый интерфейс для всех датчиков
class ISensor {
public:
    virtual void read() = 0;
    virtual const char* getName() const = 0;
    virtual float getTemperature() const { return NAN; }
    virtual float getHumidity() const { return NAN; }
    virtual int getSoilMoisture() const { return -1; }
    virtual int getLightLevel() const { return -1; }
    virtual ~ISensor() {}
};

// Роли актуаторов 
enum ActuatorRole {
    ROLE_HEATER,   // нагреватель
    ROLE_FAN,      // вентилятор
    ROLE_PUMP,     // помпа
    ROLE_LAMP,     // лампа
    ROLE_UNKNOWN   // для всех остальных 
};

// Базовый интерфейс для всех исполнительных устройств
class IActuator {
public:
    virtual void update() = 0;
    virtual bool isActive() const = 0;
    virtual void setActive(bool state) = 0;
    virtual const char* getName() const = 0;
    virtual ActuatorRole getRole() const = 0; 
    virtual ~IActuator() {}
};

//          КЛИМАТИЧЕСКИЕ ПРОФИЛИ

struct ClimateProfile {
    const char* name;
    float tempMin;
    float tempMax;
    float humidityAirMin;
    float humidityAirMax;
    float heaterHumOn;
    float heaterHumOff;
    int soilDry;
    int soilWet;
    int lightDark;
    int lightBright;
    
    ClimateProfile(const char* n, float tMin, float tMax, 
                   float hMin, float hMax, float hOn, float hOff,
                   int sDry, int sWet, int lDark, int lBright)
        : name(n), tempMin(tMin), tempMax(tMax),
          humidityAirMin(hMin), humidityAirMax(hMax),
          heaterHumOn(hOn), heaterHumOff(hOff),
          soilDry(sDry), soilWet(sWet),
          lightDark(lDark), lightBright(lBright) {}
};

ClimateProfile testProfile("Test", 26.0f, 27.0f, 40.0f, 60.0f, 65.0f, 55.0f, 400, 500, 200, 500);

ClimateProfile tomatoProfile("Tomato", 18.0f, 30.0f, 40.0f, 80.0f, 90.0f, 70.0f, 300, 700, 400, 600);

ClimateProfile cucumberProfile("Cucumber", 22.0f, 28.0f, 70.0f, 90.0f, 85.0f, 75.0f, 400, 800, 300, 500);

ClimateProfile lettuceProfile("Lettuce", 16.0f, 22.0f, 60.0f, 80.0f, 80.0f, 70.0f, 350, 750, 350, 550); 

ClimateProfile* currentProfile = &testProfile; // Активный профиль (по умолчанию - тест)

// МЕНЕДЖЕРЫ ДАТЧИКОВ И АКТУРАТОРОВ 

class SensorManager {
private:
    static const int MAX_SENSORS = 10;
    ISensor* sensors[MAX_SENSORS];
    int sensorCount;
public:
    SensorManager() : sensorCount(0) {}
    
    void addSensor(ISensor* sensor) {
        if (sensorCount < MAX_SENSORS) {
            sensors[sensorCount++] = sensor;
        }
    }
    
    void readAll() {
        for (int i = 0; i < sensorCount; i++) {
            sensors[i]->read();
        }
    }
    
    // Поиск датчика  
    ISensor* findByName(const char* name) {
        for (int i = 0; i < sensorCount; i++) {
            if (strcmp(sensors[i]->getName(), name) == 0)
                return sensors[i];
        }
        return nullptr;
    }

    float getTemperature() {
        for (int i = 0; i < sensorCount; i++) {
            float t = sensors[i]->getTemperature();
            if (!isnan(t)) return t;
        }
        return 20.0f; 
    }
    float getAirHumidity() {
        for (int i = 0; i < sensorCount; i++) {
            float h = sensors[i]->getHumidity();
            if (!isnan(h)) return h;
        }
        return 50.0f;
    }
    int getSoilMoisture() {
        for (int i = 0; i < sensorCount; i++) {
            int m = sensors[i]->getSoilMoisture();
            if (m != -1) return m;
        }
        return 500;
    }
    int getLightLevel() {
        for (int i = 0; i < sensorCount; i++) {
            int l = sensors[i]->getLightLevel();
            if (l != -1) return l;
        }
        return 500;
    }
};

class ActuatorManager {
private:
    static const int MAX_ACTUATORS = 10;
    IActuator* actuators[MAX_ACTUATORS];
    int actuatorCount;

    // Быстрый доступ по ролям (индексы соответствуют ActuatorRole)
    IActuator* roleActuators[4];

public:
    ActuatorManager() : actuatorCount(0) {
        for (int i = 0; i < 4; i++) roleActuators[i] = nullptr;
    }

    void addActuator(IActuator* actuator) {
        if (actuatorCount < MAX_ACTUATORS) {
            actuators[actuatorCount++] = actuator;
            ActuatorRole role = actuator->getRole();
            if (role >= 0 && role < 4) {
                roleActuators[role] = actuator;
            }
        }
    }

    void updateAll() {
        for (int i = 0; i < actuatorCount; i++) {
            actuators[i]->update();
        }
    }

    IActuator* findByName(const char* name) {
        for (int i = 0; i < actuatorCount; i++) {
            if (strcmp(actuators[i]->getName(), name) == 0)
                return actuators[i];
        }
        return nullptr;
    }

    // Методы управления
    void setHeater(bool on) {
        if (roleActuators[ROLE_HEATER]) roleActuators[ROLE_HEATER]->setActive(on);
    }
    void setFan(bool on) {
        if (roleActuators[ROLE_FAN]) roleActuators[ROLE_FAN]->setActive(on);
    }
    void setPump(bool on) {
        if (roleActuators[ROLE_PUMP]) roleActuators[ROLE_PUMP]->setActive(on);
    }
    void setLamp(bool on) {
        if (roleActuators[ROLE_LAMP]) roleActuators[ROLE_LAMP]->setActive(on);
    }

    bool isPumpActive() {
        if (roleActuators[ROLE_PUMP]) return roleActuators[ROLE_PUMP]->isActive();
        return false;
    }
};

//          НАСТРОЙКИ

class TimeManager { // Таймер
private:
    unsigned long _startMillis;
    const unsigned long _MS_PER_HOUR = 3600000UL;
    const int _START_HOUR = 8;       // Утро - точка отсчёта
    const int _NIGHT_START = 22;      // Ночь: 22:00 - 06:00
    const int _NIGHT_END = 6; 
    const int _VENT_START = 10;       // Расписание проветривания: 10:00 - 14:00
    const int _VENT_END = 14; 

public:
    TimeManager() { _startMillis = millis(); }
    
    int getHour() {
        unsigned long elapsed = millis() - _startMillis;
        return (_START_HOUR + (elapsed / _MS_PER_HOUR)) % 24;
    }
    
    bool isNight() {
        int h = getHour();
        return (h >= _NIGHT_START || h < _NIGHT_END);
    }
    
    bool isVentilationTime() {
        int h = getHour();
        return (h >= _VENT_START && h < _VENT_END);
    }
};

//          КЛАССЫ ДАТЧИКОВ
class Thermometer : public ISensor {
private:
    int pin;
    DHT dht;
public:
    float temperature = 20.0f;
    float humidity_air = 50.0f;

    Thermometer(int pin) : pin(pin), dht(pin, DHT11) {
        dht.begin();
    }

    void read() override {
        temperature = dht.readTemperature();
        humidity_air = dht.readHumidity();
        if (isnan(temperature)) temperature = 20.0f;
        if (isnan(humidity_air)) humidity_air = 50.0f;
    }
    float getTemperature() const override { return temperature; }
    float getHumidity() const override { return humidity_air; }
    const char* getName() const override { return "Thermometer"; }
};

class Hygrometer : public ISensor {
private:
    int pin;
public:
    int humidity_soil = 500;

    Hygrometer(int pin) : pin(pin) {}

    void read() override {
        humidity_soil = analogRead(pin);
    }
    int getSoilMoisture() const override { return humidity_soil; }
    const char* getName() const override { return "Hygrometer"; }
};

class LightSensor : public ISensor {
private:
    int pin;
public:
    int light_level = 500;

    LightSensor(int pin) : pin(pin) {}

    void read() override {
        light_level = analogRead(pin);
    }
    int getLightLevel() const override { return 1023 - light_level; }  
    const char* getName() const override { return "LightSensor"; }
};

//          КЛАССЫ ИСПОЛНИТЕЛЬНЫХ УСТРОЙСТВ (Реле)

class Relay : public IActuator {
protected:
    int pin;
    bool active;
public:
    Relay(int pin) : pin(pin), active(false) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
    }

    void setActive(bool state) override { active = state; }
    bool isActive() const override { return active; }
    void update() override { digitalWrite(pin, active ? LOW : HIGH); }
    const char* getName() const override { return "Relay"; }
    ActuatorRole getRole() const override { return ROLE_UNKNOWN; }
};

class Heater : public Relay {
public:
    Heater(int pin) : Relay(pin) {}
    const char* getName() const override { return "Heater"; }
    ActuatorRole getRole() const override { return ROLE_HEATER; }
};

class Fan : public Relay {
public:
    Fan(int pin) : Relay(pin) {
        digitalWrite(pin, LOW);  
    }
    const char* getName() const override { return "Fan"; }
    ActuatorRole getRole() const override { return ROLE_FAN; }
    void update() override {
        digitalWrite(pin, active ? HIGH : LOW);  
    }
};

class Pump : public Relay {
public:
    Pump(int pin) : Relay(pin) {}
    const char* getName() const override { return "Pump"; }
    ActuatorRole getRole() const override { return ROLE_PUMP; }
};

class Lamp : public Relay {
public:
    Lamp(int pin) : Relay(pin) {}
    const char* getName() const override { return "Lamp"; }
    ActuatorRole getRole() const override { return ROLE_LAMP; }
};

//            УПРАВЛЕНИЕ  (логика теплицы)

class IControlStrategy {
public:
    virtual void regulate(SensorManager& sensors, 
                          ActuatorManager& actuators,
                          ClimateProfile* profile,
                          TimeManager& time,
                          unsigned long& pumpStartMs) = 0;
    virtual ~IControlStrategy() {}
};

// Исходная логика 
class DefaultControlStrategy : public IControlStrategy {
private:
    // Таймеры
    static const unsigned long FAN_INIT_MS = 5000;        // n секунд работа при вкл.
    static const unsigned long FAN_AFTER_HEATER_MS = 2000; // х секунд работа после выкл. нагревателя
    bool initialFanDone = false;
    unsigned long startMs = millis();
    bool heaterWasActive = false;
    unsigned long heaterOffMs = 0;
    bool fanHold = false;
public:
    void regulate(SensorManager& sensors, 
                  ActuatorManager& actuators,
                  ClimateProfile* profile,
                  TimeManager& time,
                  unsigned long& pumpStartMs) override {
        
        const ClimateProfile& P = *profile;
        
        float temperature = sensors.getTemperature();
        float airHumidity = sensors.getAirHumidity();
        int soilMoisture = sensors.getSoilMoisture();
        int lightLevel = sensors.getLightLevel();
        
// 1. Нагреватель 
if (temperature <= P.tempMin) {
    actuators.setHeater(true);
} else if (temperature >= P.tempMax) {
    actuators.setHeater(false);
}


// связка для нагревателя+вентилятора
bool heaterActive = false;
IActuator* heaterAct = actuators.findByName("Heater");
if (heaterAct) {
    heaterActive = heaterAct->isActive();
}

// 2. Вентилятор
bool fanNeeded = false;

// Принудительный старт на n секунд
if (!initialFanDone) {
    if (millis() - startMs < FAN_INIT_MS) {
        fanNeeded = true;
    } else {
        initialFanDone = true;
    }
}

if (temperature >= P.tempMax) fanNeeded = true;
if (airHumidity > P.humidityAirMax) fanNeeded = true;
if (!time.isNight() && time.isVentilationTime()) fanNeeded = true;  // Проветривание
if (heaterActive) fanNeeded = true;

// Работа x секунд после выключения нагревателя
if (heaterWasActive && !heaterActive) {
    fanHold = true;
    heaterOffMs = millis();
}
if (fanHold) {
    if (millis() - heaterOffMs < FAN_AFTER_HEATER_MS) {
        fanNeeded = true;
    } else {
        fanHold = false;
    }
}
heaterWasActive = heaterActive;

actuators.setFan(fanNeeded);
        
        // 3. Полив
        if (soilMoisture < P.soilDry) {
            if (!actuators.isPumpActive()) pumpStartMs = millis();
            actuators.setPump(true);
        } else if (soilMoisture > P.soilWet) {
            actuators.setPump(false);
        }
        
        // 4. Освещение
        if (time.isNight()) {
            actuators.setLamp(false);   
        } else {
            if (lightLevel > P.lightDark) actuators.setLamp(true);
            else if (lightLevel < P.lightBright) actuators.setLamp(false);
        }
    }
};

// Глобальные переменные
unsigned long pump_start_time = 0;
TimeManager timeKeeper;

// Менеджеры
SensorManager sensorManager;
ActuatorManager actuatorManager;

// Стратегия управления (по умолчанию)
DefaultControlStrategy defaultStrategy;
IControlStrategy* controlStrategy = &defaultStrategy;

// Тестовая стратегия: однократный последовательный запуск актуаторов по 3 секунды
class TestActuatorsStrategy : public IControlStrategy {
private:
    enum State { START, HEATER_ON, FAN_ON, PUMP_ON, LAMP_ON, DONE };
    State state = START;
    unsigned long stateStart = 0;
    const unsigned long ON_TIME = 3000;   // 3 секунды на каждый
    bool finished = false;
public:
    void regulate(SensorManager& sensors,
                  ActuatorManager& actuators,
                  ClimateProfile* profile,
                  TimeManager& time,
                  unsigned long& pumpStartMs) override {
        if (finished) return;

        unsigned long now = millis();
        switch (state) {
            case START:
                Serial.println("=== Actuator test start ===");
                stateStart = now;
                state = HEATER_ON;
                actuators.setHeater(true);
                Serial.println("Heater ON");
                break;
            case HEATER_ON:
                if (now - stateStart >= ON_TIME) {
                    actuators.setHeater(false);
                    Serial.println("Heater OFF");
                    actuators.setFan(true);
                    Serial.println("Fan ON");
                    stateStart = now;
                    state = FAN_ON;
                }
                break;
            case FAN_ON:
                if (now - stateStart >= ON_TIME) {
                    actuators.setFan(false);
                    Serial.println("Fan OFF");
                    actuators.setPump(true);
                    Serial.println("Pump ON");
                    stateStart = now;
                    state = PUMP_ON;
                }
                break;
            case PUMP_ON:
                if (now - stateStart >= ON_TIME) {
                    actuators.setPump(false);
                    Serial.println("Pump OFF");
                    actuators.setLamp(true);
                    Serial.println("Lamp ON");
                    stateStart = now;
                    state = LAMP_ON;
                }
                break;
            case LAMP_ON:
                if (now - stateStart >= ON_TIME) {
                    actuators.setLamp(false);
                    Serial.println("Lamp OFF");
                    Serial.println("=== Test finished, switching to normal mode ===");
                    finished = true;
                    state = DONE;
                    // Автоматический переход на обычную стратегию
                    controlStrategy = &defaultStrategy;
                }
                break;
            case DONE:
                break;
        }
    }
};

TestActuatorsStrategy testStrategy;

//          SETUP И LOOP 

// Объекты устройств
Thermometer thermometer(8);
Hygrometer hygrometer(A1);
LightSensor light_sensor(A0);

Heater heater(7);
Fan fan(4);
Pump pump(6);
Lamp lamp(5);

void setup() {
    Serial.begin(115200);
    
    // Регистрация датчиков
    sensorManager.addSensor(&thermometer);
    sensorManager.addSensor(&hygrometer);
    sensorManager.addSensor(&light_sensor);
    
    // Регистрация актуаторов
    actuatorManager.addActuator(&heater);
    actuatorManager.addActuator(&fan);
    actuatorManager.addActuator(&pump);
    actuatorManager.addActuator(&lamp);
    
    //Можно выбрать тестовую стратегию
    //controlStrategy = &testStrategy;
}

void loop() {
    Serial.print("Heater pin state: ");
    Serial.print(digitalRead(7));  // читаем пин нагревателя
    Serial.print(" | Heater active: ");
    Serial.print(heater.isActive());

    //Датчики
    sensorManager.readAll();

    //Логика регулирования (стратегия + профиль)
    controlStrategy->regulate(sensorManager, actuatorManager,
                              currentProfile, timeKeeper, pump_start_time);

    //Актуаторы
    actuatorManager.updateAll();

    //Отладка
    Serial.print("Temp: ");
    Serial.print(sensorManager.getTemperature());
    Serial.print(" *C | Air humidity: ");
    Serial.print(sensorManager.getAirHumidity());
    Serial.print(" % | Soil moisture: ");
    Serial.print(sensorManager.getSoilMoisture());
    Serial.print(" | Light: ");
    Serial.println(sensorManager.getLightLevel());

    delay(1000);
}