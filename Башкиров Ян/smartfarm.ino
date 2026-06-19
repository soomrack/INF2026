#include <DHT.h>   // библиотека для датчика воздуха (температура + влажность)


// пины
#define FAN_PIN            7   // вентилятор
#define LED_PIN            6   // лампа
#define PUMP_PIN           5   // помпа (полив)
#define HEATER_PIN         4   // нагреватель

#define LIGHT_SENSOR_PIN   A3  // датчик освещённости
#define SOIL_SENSOR_PIN    A1  // датчик влажности почвы
#define DHT_PIN            3   // датчик температуры и влажности воздуха


// настройки климата
const float MIN_TEMP     = 20;   // ниже - холодно (включаем нагреватель)
const float MAX_TEMP     = 30;   // выше - жарко (включаем вентилятор)

const int   MAX_HUMIDITY = 70;   // влажность выше - вент

const int   DARK_LIGHT   = 300;  // свет ниже - темно
const int   DRY_SOIL     = 600;  // почва суше - полив

// "Ночь": принял, что ночь, если темно 15 секунд.
const unsigned long NIGHT_AFTER_MS = 15000;

// Вент каждую минуту по 10 секунд.
const unsigned long VENT_PERIOD   = 60000;
const unsigned long VENT_DURATION = 10000;  // сколько продувать


// датчик воздуха
DHT dht(DHT_PIN, DHT21);


// показания датчиков
float temperature = 0;   // температура, °C
float airHumidity = 0;   // влажность, %
int   light       = 0;   // освещённость, 0...1023 (темно-светло)
int   soil        = 0;   // влажность почвы, 0...1023 (влажно-сухо)


// что сейчас включено (true = вкл, false = выкл)
bool lampOn   = false;
bool fanOn    = false;
bool heaterOn = false;
bool pumpOn   = false;


// читаем датчики
void readSensors() {
    temperature = dht.readTemperature();
    airHumidity = dht.readHumidity();

    light = analogRead(LIGHT_SENSOR_PIN);
    soil  = analogRead(SOIL_SENSOR_PIN);
}


// ночь, если темно дольше NIGHT_AFTER_MS подряд
bool isNight() {
    static bool wasDark = false;          // было ли темно
    static unsigned long darkSince = 0;   // когда стало темно

    bool darkNow = (light <= DARK_LIGHT); // сейчас темно?

    if (!darkNow) {        // светло - значит день
        wasDark = false;
        return false;
    }

    if (!wasDark) {        // только что стемнело - запоминаем время
        wasDark = true;
        darkSince = millis();
    }

    return (millis() - darkSince >= NIGHT_AFTER_MS);   // темно достаточно долго -> ночь
}


// правила: сначала всё выключаем, потом включаем что нужно
void applyRules() {

    bool night = isNight();

    lampOn   = false;
    fanOn    = false;
    heaterOn = false;
    pumpOn   = false;

    // лампа: темно и не ночь -> включаем
    if (!night && light <= DARK_LIGHT) {
        lampOn = true;
    }

    // температура
    if (temperature < MIN_TEMP) {     // холодно -> греем и гоняем воздух
        heaterOn = true;
        fanOn    = true;
    }
    if (temperature > MAX_TEMP) {     // жарко -> проветриваем
        fanOn = true;
    }

    // влажность воздуха
    if (airHumidity >= MAX_HUMIDITY) {  // сыро -> проветриваем
        fanOn = true;
    }

    // полив: большое значение = сухо
    if (soil >= DRY_SOIL) {           // сухо -> поливаем
        pumpOn = true;
    }

    // проветривание по расписанию (но не ночью)
    if (!night && (millis() % VENT_PERIOD < VENT_DURATION)) {
        fanOn = true;
    }
}


// включаем/выключаем устройства на пинах (HIGH = вкл, LOW = выкл)
void applyDevices() {
    digitalWrite(LED_PIN,    lampOn   ? HIGH : LOW);
    digitalWrite(FAN_PIN,    fanOn    ? HIGH : LOW);
    digitalWrite(HEATER_PIN, heaterOn ? HIGH : LOW);
    digitalWrite(PUMP_PIN,   pumpOn   ? HIGH : LOW);
}


// печатаем отчёт раз в 2 секунды
void printReport() {
    static unsigned long lastTime = 0;
    if (millis() - lastTime < 2000) return;   // ещё не прошло 2 сек
    lastTime = millis();

    Serial.println("---------- Состояние теплицы ----------");

    Serial.print("Температура  : ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Влажн. возд. : ");
    Serial.print(airHumidity);
    Serial.println(" %");

    Serial.print("Освещённость : ");
    Serial.print(light);
    Serial.println(isNight() ? "  (НОЧЬ)" : "  (день)");

    Serial.print("Влажн. почвы : ");
    Serial.println(soil);

    Serial.print("Лампа: ");        Serial.print(lampOn   ? "ВКЛ" : "выкл");
    Serial.print("  Вентилятор: "); Serial.print(fanOn    ? "ВКЛ" : "выкл");
    Serial.print("  Нагрев: ");     Serial.print(heaterOn ? "ВКЛ" : "выкл");
    Serial.print("  Помпа: ");      Serial.println(pumpOn ? "ВКЛ" : "выкл");

    Serial.println();
}


// setup - один раз при включении
void setup() {
    Serial.begin(9600);   // монитор порта
    dht.begin();          // датчик воздуха

    pinMode(LED_PIN,    OUTPUT);
    pinMode(FAN_PIN,    OUTPUT);
    pinMode(HEATER_PIN, OUTPUT);
    pinMode(PUMP_PIN,   OUTPUT);

    Serial.println("=== Умная теплица запущена ===");
}


// loop - повторяется бесконечно
void loop() {
    readSensors();    // прочитать датчики
    applyRules();     // решить, что включить
    applyDevices();   // включить/выключить
    printReport();    // показать отчёт
}
