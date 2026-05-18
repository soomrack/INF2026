#include <stdio.h>
#include <DHT.h> 

unsigned long start_millis;
int start_seconds = 0;
int start_minutes = 0;
int start_hours = 0;
bool time_set = false;

// Настройки
int heat_sensor_temperature_on = 20;    // температура ниже которой включается обогреватель
int heat_sensor_temperature_off = 40;   // температура выше которой выключается обогреватель
int gigrometer_air_percent_off = 70;    // влажность воздуха выше которой выключается помпа
int gigrometer_soil_percent_off = 70;   // влажность почвы выше которой выключается помпа
int gigrometer_air_percent_on = 30;     // влажность воздуха ниже которой включается помпа
int gigrometer_soil_percent_on = 30;    // влажность почвы ниже которой включается помпа
int time_morning = 8;                   // начало дня (лампа и вентилятор работают)
int time_night = 20;                    // начало ночи
const long interval_aired = 15000;      // время проветривания
int aired_interval = 6;                 // интервал проветривания
const long interval_soil = 1000;        // интервал отключения помпы (чтобы не затопило)
int air_humidity_border = 80;           // влажность воздуха больше которой запускается вентилятор

class Thermometer {
private:
    int pin;
    float temperature;
    DHT dht;
public:    
    Thermometer(int pin) : pin(pin), temperature(0), dht(pin, DHT11) { 
      dht.begin();
    }  
    float get_temperature() { 
      temperature = dht.readTemperature(); 
      return temperature;
    }  
};

class GigrometerAir {
private:
    int pin;
    float humidity;
    DHT dht;
public:    
    GigrometerAir(int pin) : pin(pin), humidity(0), dht(pin, DHT11) { 
      dht.begin();
    } 
    float get_humidity() { 
      humidity = dht.readHumidity(); 
      return humidity;
    }  
};

class GigrometerSoil {
private:
    int pin;
    float humidity;
public:    
    GigrometerSoil(int pin) : pin(pin), humidity(0) {}
    float get_humidity() { 
      humidity = 100-(analogRead(pin)/ 1023.0) * 100; 
      return humidity;
    }  
};

class LightSensor {
private:
    int pin;
    int light;
public:    
    LightSensor(int pin) : pin(pin){} 
    float get_light() { 
      light = analogRead(pin); 
      return light;
    }  
};

class Heater {
private:
    int pin;
    bool is_on;
public:
    Heater(int pin) : pin(pin), is_on(0){}; 
    void set_on(bool condition){ is_on = condition; }
    bool get_heater_condition(){ return is_on; }
    void power(){ digitalWrite(pin, is_on ? HIGH : LOW); }
};

class Fan {
private:
    int pin;
    bool is_on;
    bool is_aired_flag;
    unsigned long previous_millis_aired;
public:
    Fan(int pin) : pin(pin), is_on(0), previous_millis_aired(0){}; 
    void set_on(bool condition){ is_on = condition; }
    bool get_fan_condition(){ return is_on; }
    void power(){ digitalWrite(pin, is_on ? HIGH : LOW); }
    void set_aired(bool condition){ is_aired_flag = condition; }
    bool is_aired(){ return is_aired_flag; }
    void set_previous_millis_aired(unsigned long previous_millis_aired){ this->previous_millis_aired = previous_millis_aired;}
    unsigned long get_previous_millis_aired(){ return previous_millis_aired;}
};

class Pump {
private:
    int pin;
    bool is_on;
    unsigned long previous_millis_soil;
public:
    Pump(int pin) : pin(pin), is_on(0), previous_millis_soil(0){}; 
    void set_on(bool condition){ is_on = condition; }
    bool get_pump_condition(){ return is_on; }
    void power(){ digitalWrite(pin, is_on ? HIGH : LOW); }
    void set_previous_millis_soil(unsigned long previous_millis_soil){ this->previous_millis_soil = previous_millis_soil;}
    unsigned long get_previous_millis_soil(){ return previous_millis_soil;}
};

class Lump {
private:
    int pin;
    bool is_on;
public:
    Lump(int pin) : pin(pin), is_on(0){}; 
    void set_on(bool condition){ is_on = condition; }
    bool get_lump_condition(){ return is_on; }
    void power(){ digitalWrite(pin, is_on ? HIGH : LOW); }
};

int humid_temp_pin = 2; 
int humid_soil_pin = A1;
int light_sensor_pin = A0;

int fan_pin = 7; 
int heater_pin = 4; 
int lump_pin = 6; 
int pump_pin = 5; 

void setup() {             
  Serial.begin(9600); 
  pinMode(light_sensor_pin, INPUT);
  pinMode(humid_soil_pin, INPUT);
  pinMode(fan_pin, OUTPUT);
  pinMode(heater_pin, OUTPUT);
  pinMode(lump_pin, OUTPUT);
  pinMode(pump_pin, OUTPUT);
}

Thermometer thermometer(humid_temp_pin);
GigrometerAir gigrometer_air(humid_temp_pin);
GigrometerSoil gigrometer_soil(humid_soil_pin);
LightSensor light_sensor(light_sensor_pin);

Fan fan(fan_pin);
Heater heater(heater_pin);
Pump pump(pump_pin);
Lump lump(lump_pin);

int get_current_hour() {
    if (!time_set) return 12; // если время не установлено, считаем что день
    
    unsigned long elapsed = millis() - start_millis;
    unsigned long total_seconds = elapsed / 1000;
    int current_hours = (start_hours + (start_minutes + (start_seconds + total_seconds) / 60) / 60) % 24;
    return current_hours;
}

void control_scheduled_air(GigrometerAir& gigrometer_air){
    int current_hour = get_current_hour();
    if ((current_hour-start_hours) % aired_interval == 0 && !fan.is_aired()){
        unsigned long current_millis_aired = millis();
        if (current_millis_aired - fan.get_previous_millis_aired() >= interval_aired) {
            fan.set_previous_millis_aired(current_millis_aired);
            fan.set_on(1);
        }
        else{
            fan.set_previous_millis_aired(0);
            fan.set_aired(1);
        }
    }
    else {
        fan.set_aired(0);
    }
}

void control_humidity_air(GigrometerAir& gigrometer_air){
    if (gigrometer_air.get_humidity()>air_humidity_border){
        fan.set_on(1);
    }
    else if (fan.is_aired()){
        fan.set_on(0);
    }
}
void control_temperature(Thermometer& thermometer)
{
    int current_hour = get_current_hour();
    bool is_daytime = (current_hour >= time_morning && current_hour < time_night);
    
    if (thermometer.get_temperature() > heat_sensor_temperature_off) {
        heater.set_on(0);
        if (is_daytime) {
            fan.set_on(1);
        }
    }

    if (thermometer.get_temperature() < heat_sensor_temperature_on) {
        heater.set_on(1);
        if (is_daytime) {
            fan.set_on(1);
        }
    }
    else if (fan.is_aired()){
        fan.set_on(0);
    }
}

void control_light(LightSensor& light_sensor)
{
    int current_hour = get_current_hour();
    
    if (light_sensor.get_light() < 500 && current_hour >= time_morning && current_hour < time_night) {
        lump.set_on(1);
    }
    else {
        lump.set_on(0);
    }
}

void control_humidity_soil(GigrometerSoil& gigrometer_soil)
{
    float humidity = gigrometer_soil.get_humidity();
    
    if (humidity > gigrometer_soil_percent_off) {
        pump.set_on(0);
    }

    if (humidity < gigrometer_soil_percent_on) {
        unsigned long current_millis_soil = millis();
        if (current_millis_soil - pump.get_previous_millis_soil() >= interval_soil) {
            pump.set_previous_millis_soil(0);
            pump.set_on(!pump.get_pump_condition());
        }
    }
}
unsigned long previous_millis_print = 0;
const long interval_print = 1000;
void print_data(){
    unsigned long current_millis_print = millis();
    if (previous_millis_print - previous_millis_print >= interval_print && time_set) {
        previous_millis_print = current_millis_print;
        Serial.print("Температура: ");
        Serial.print(thermometer.get_temperature());
        Serial.println(" °C");
        Serial.print("Влажность почвы: ");
        Serial.print(gigrometer_soil.get_humidity());
        Serial.println(" %");
        Serial.print("Влажность воздуха: ");
        Serial.print(gigrometer_air.get_humidity());
        Serial.println(" %");
        if (time_set){
            Serial.print("Текущее время: ");
            int current_hour = get_current_hour();
            Serial.println(current_hour);
        }
        Serial.println("---");
    }
}
void print_time() {
  if (start_hours < 10) Serial.print("0");
  Serial.print(start_hours);
  Serial.print(":");
  if (start_minutes < 10) Serial.print("0");
  Serial.print(start_minutes);
  Serial.print(":");
  if (start_seconds < 10) Serial.print("0");
  Serial.println(start_seconds);
}

void time_cycle(){
    if (!time_set) {
        if (Serial.available()) {
            String input = Serial.readStringUntil('\n');
            input.trim();

            int h = input.substring(0, 2).toInt();
            int m = input.substring(3, 5).toInt();
            int s = input.substring(6, 8).toInt();
            
            if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
                start_hours = h;
                start_minutes = m;
                start_seconds = s;
                start_millis = millis();
                time_set = true;
                Serial.print("Время установлено: ");
                print_time();
            } else {
                Serial.println("Неверный формат! Попробуйте ещё раз.");
            }
        }
    }
}

void loop()
{    
    time_cycle(); 

    control_temperature(thermometer);
    control_humidity_soil(gigrometer_soil);
    control_scheduled_air(gigrometer_air);
    control_light(light_sensor);
    control_humidity_air(gigrometer_air);
    
    lump.power();
    heater.power();
    pump.power();
    fan.power();

    print_data();
}