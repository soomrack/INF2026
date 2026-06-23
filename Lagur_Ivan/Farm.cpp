#include <Adafruit_Sensor.h>
#include <DHT.h> 
#include <stdio.h>

#define FAN_PIN 4
#define LED_PIN 5
#define PUMP_PIN 6
#define HEATER_PIN 7
const int LIGHT_SENSOR_PIN_1 = A0;
const int HUMIDITY_SENSOR_PIN = A1;
#define TEMP_SENSOR_PIN 3
#define DHTTYPE DHT11



DHT dht(TEMP_SENSOR_PIN, DHTTYPE);

class Thermometer {
public:    
    float temperature;  // Celcius
    void get_temperature();
};

class Gigrometer_Air {
public:
    int humidity_air;
    void get_humidity();
};

class Heater {
public:
    bool on_temperature = false;
    bool on_humidity = false;
    void power();
};

class Fan {
public:
    bool on_temperature = false;
    bool on_humidity = false;
    void power();
};

class Light_sensor {
private:
    const int pin;
public:
    int illumination;
    Light_sensor(int p) : pin(p) { pinMode(pin, INPUT); }
    void get_illumination();
};

class Led {
public:
    bool on_illumination = false;
    void power();
};

class Gigrometer_Soil {
private:
    const int pin;
public:
    int humidity_soil;
    Gigrometer_Soil(const int p) : pin(p) { pinMode(pin, INPUT); }
    void get_humidity();
};

class Pump {
public:
    bool on_humidity = false;
    int time_ON = 0;
    int time_OFF = 0;
    bool last_value;
    void power();
};

Light_sensor light_sensor_1(LIGHT_SENSOR_PIN_1);
Thermometer thermometer;
Gigrometer_Air gigrometer_air;
Gigrometer_Soil gigrometer_soil(HUMIDITY_SENSOR_PIN);
Led led;
Pump pump;
Heater heater;
Fan fan;

void Thermometer::get_temperature() {
    temperature = dht.readTemperature();
}

void Gigrometer_Air::get_humidity() {
    humidity_air = dht.readHumidity();
}

void DHTread(Thermometer &term, Gigrometer_Air &gigr_air) {
    float t = dht.readTemperature();
    float hum = dht.readHumidity();
    if (!isnan(t)) term.temperature = t;   // иначе оставить предыдущее значение
    if (!isnan(hum)) gigr_air.humidity_air = hum;
}

void Heater::power() {
    if (on_temperature || on_humidity) {
        digitalWrite(HEATER_PIN, HIGH);
    } else {
        digitalWrite(HEATER_PIN, LOW);
    }
}

void Fan::power() {
    if (on_temperature || on_humidity) {
        digitalWrite(FAN_PIN, HIGH);
    } else {
        digitalWrite(FAN_PIN, LOW);
    }
}

void Light_sensor::get_illumination() {
    illumination = analogRead(pin);
}

void Led::power() {
    if (on_illumination) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
}

void Gigrometer_Soil::get_humidity() {
    humidity_soil = analogRead(pin);
}

void Pump::power() {
    if (on_humidity){
        digitalWrite(PUMP_PIN, HIGH);
    } else {
        digitalWrite(PUMP_PIN, LOW);
    }
}

unsigned long previousMillis = 0;
int currentHours = 0;
int currentMinutes = 0;

void control_time() {
    unsigned long now = millis();
    // Обновляем раз в 60 секунд
    if (now - previousMillis >= 60000) {
        previousMillis = now;
        currentMinutes++;
        if (currentMinutes >= 60) {
            currentMinutes = 0;
            currentHours++;
            if (currentHours > 23) {
                currentHours = 0;
            }
        }
    }
    // Для отладки выводим время
    Serial.print(currentHours);
    Serial.print(":");
    Serial.println(currentMinutes);
}

void control_temperature(const Thermometer& term, Heater& htr, Fan& fn) {
    if (term.temperature > 29) {
        htr.on_temperature = false; 
        fn.on_temperature = true;   
    } 
    else if (term.temperature < 28) {
        htr.on_temperature = true; 
        fn.on_temperature = false;
    } 
    else {
        htr.on_temperature = false;
        fn.on_temperature = false;
    }
}
void control_illumination(Light_sensor& ls1, Led& l, int currentHours) {
    if ((ls1.illumination < 500) &&(currentHours<22) && (currentHours>=10)) {
        l.on_illumination = true;
    } else {
        l.on_illumination = false;
    }
}

void control_humidity_air(const Gigrometer_Air& gigr, Heater& htr, Fan& fan) {
    if (gigr.humidity_air > 60) {
        htr.on_humidity = true;
        fan.on_humidity = true;
    } else {
        htr.on_humidity = false;
        fan.on_humidity = false;
    }
}

void control_humidity_soil(const Gigrometer_Soil& gigro, Pump& pmp, int currentHours) {
    static unsigned long last_switch_time = 0; 
    static bool is_watering_cycle = false;
    unsigned long current_time = millis();

    if ((gigro.humidity_soil <= 100) && ((currentHours>22) || (currentHours<=10))) { 
        pmp.on_humidity = false;
        is_watering_cycle = false; 
        return;
    }

    if (!is_watering_cycle) {
        pmp.on_humidity = true;
        is_watering_cycle = true;
        last_switch_time = current_time;
        Serial.println(F("Dry soil detected! Start watering..."));
    } 
    else {
        if (pmp.on_humidity) {
            if (current_time - last_switch_time >= 2000) {
                pmp.on_humidity = false;
                last_switch_time = current_time;
                Serial.println(F("Interval: Pump OFF (resting)"));
            }
        } else {
            if (current_time - last_switch_time >= 4000) {
                pmp.on_humidity = true;
                last_switch_time = current_time;
                Serial.println(F("Interval: Pump ON (watering)"));
            }
        }
    }
}

void control_ventilation(Fan& fn, int currentHours, int currentMinutes) {
    if ((currentHours == 12 || currentHours == 16 || currentHours == 20) && currentMinutes < 15) {
        fn.on_temperature = true;   // включаем на первые 15 минут часа
    } else {
        fn.on_temperature = false;
    }
}



void setup() {
  pinMode(FAN_PIN, OUTPUT); 
  pinMode(LED_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(HEATER_PIN, OUTPUT);
  dht.begin();
  delay(1000);

  Serial.begin(9600);
  thermometer.temperature = 25.0;
  gigrometer_air.humidity_air = 50;
}

void loop() {
    DHTread(thermometer, gigrometer_air);
    gigrometer_soil.get_humidity();
    light_sensor_1.get_illumination();

    control_time();
    control_ventilation(fan, currentHours, currentMinutes);
    control_temperature(thermometer, heater, fan);
    control_humidity_soil(gigrometer_soil, pump, currentHours);
    control_humidity_air(gigrometer_air, heater, fan);
    control_illumination(light_sensor_1, led, currentHours);


    led.power();
    heater.power();
    pump.power();
    fan.power();

    
    Serial.print(F(" Temperature: "));
    Serial.print(thermometer.temperature);
    Serial.print(F(" Humidity: "));
    Serial.print(gigrometer_soil.humidity_soil);
    Serial.print(F(" Illumination: "));
    Serial.print(light_sensor_1.illumination);
    Serial.print(F(" Humidity Air: "));
    Serial.println(gigrometer_air.humidity_air);




    delay(2000);
}
