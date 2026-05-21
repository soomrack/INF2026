#include <DHT.h>

// --- НАСТРОЙКИ ---
#define LIGHT_PIN A0    // Свет
#define DHTPIN 2        // ДХТ 
#define DHTTYPE DHT11

// --- ПИНЫ СВЕТОДИОДОВ ---
#define LED_LIGHT 3     // Лампа 1: Свет
#define LED_FAN 7       // Лампа 2: Вентилятор
#define LED_HEAT 9      // Лампа 3: Обогрев
#define LED_HUMID 4    // Лампа 4: Увлажнитель

// --- ПОРОГИ ---
#define TEMP_HIGH 28.0  // Выше этой t — вентилятор
#define TEMP_LOW 22.0   // Ниже этой t — обогрев
#define HUM_LOW 40.0    // Ниже этой влажности — увлажнитель

DHT dht(DHTPIN, DHTTYPE);
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LED_LIGHT, OUTPUT);
  pinMode(LED_FAN, OUTPUT);
  pinMode(LED_HEAT, OUTPUT);
  pinMode(LED_HUMID, OUTPUT);

  digitalWrite(LED_LIGHT, LOW);
  digitalWrite(LED_FAN, LOW);
  digitalWrite(LED_HEAT, LOW);
  digitalWrite(LED_HUMID, LOW);
}

void loop() {
  // 1. ЛОГИКА СВЕТА
  int lightLevel = analogRead(LIGHT_PIN);

  if (lightLevel > 500) {
    digitalWrite(LED_LIGHT, HIGH);
  } else {
    digitalWrite(LED_LIGHT, LOW);
  }

  // 2. ЛОГИКА КЛИМАТА (раз в 2 секунды)
  if (millis() - previousMillis >= 2000) {
    previousMillis = millis();

    float t = dht.readTemperature();
    float h = dht.readHumidity();

    Serial.print("Свет: ");
    Serial.print(lightLevel);
    Serial.print(" | Температура: ");

    if (isnan(t) || isnan(h)) {
      Serial.println("ОШИБКА белого датчика!");
    } else {
      Serial.print(t);
      Serial.print(" *C, Влажность: ");
      Serial.print(h);
      Serial.println(" %");

      // Вентилятор
      digitalWrite(LED_FAN, (t > TEMP_HIGH) ? HIGH : LOW);

      // Обогрев
      digitalWrite(LED_HEAT, (t < TEMP_LOW) ? HIGH : LOW);

      // Увлажнитель
      digitalWrite(LED_HUMID, (h < HUM_LOW) ? HIGH : LOW);
    }
  }
}