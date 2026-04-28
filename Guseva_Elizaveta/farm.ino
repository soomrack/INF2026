// librarys
#include <DHT.h> 

// pins
#define FAN_PIN 7 
#define LED_PIN 6
#define PUMP_PIN 5
#define HEATER_PIN 4
#define TEMP_SENSOR_TYPE DHT11
const int LIGHT_SENSOR_PIN = A0;
const int HUMIDITY_SENSOR_PIN = A1;
#define TEMP_SENSOR_PIN 12

DHT dht(TEMP_SENSOR_PIN, TEMP_SENSOR_TYPE);

//humidity func init
int ticks_watering = 0;
bool use_humidity_func = true;

// loop init
float temperature;
int humidity;

// init
void setup() {
  pinMode(FAN_PIN, OUTPUT); 
  pinMode(LED_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(HEATER_PIN, OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
  pinMode(HUMIDITY_SENSOR_PIN, INPUT);
  pinMode(TEMP_SENSOR_PIN, INPUT);

  dht.begin();  
  Serial.begin(9600);
}

void control_temperature(float temperature){

  // control temp
  if (temperature >= 29){
  digitalWrite(FAN_PIN, HIGH);
  digitalWrite(HEATER_PIN, LOW);
  }

  else if (temperature <= 25){
  digitalWrite(FAN_PIN, HIGH);
  digitalWrite(HEATER_PIN, HIGH);
  }

  else { // room temperature
  digitalWrite(FAN_PIN, LOW); 
  digitalWrite(HEATER_PIN, LOW);
  }

  // telemetry
  Serial.print("Temperature: ");
  Serial.print(temperature);
}

void control_humidity(int humidity){

  // check humidity
  if(humidity >= 900){
    use_humidity_func = false;
  }
  else{
    use_humidity_func = true;
    ticks_watering++;
    digitalWrite(PUMP_PIN, LOW);
  }
  
  // control humidity
  if(use_humidity_func == false){
    ticks_watering++;
    if(ticks_watering <= 50){
      digitalWrite(PUMP_PIN, HIGH);
    }

    else if(50 <= ticks_watering && ticks_watering <= 100){
      digitalWrite(PUMP_PIN, LOW);
    }

    else{
      ticks_watering = 0;
      use_humidity_func = false;
    }
  }

  //telemetry
  Serial.print("Humidity: ");
  Serial.println(ticks_watering);
  Serial.println(humidity);
}

void loop() {
  int  lightness = analogRead(LIGHT_SENSOR_PIN);
  humidity = analogRead(HUMIDITY_SENSOR_PIN);
  temperature = dht.readTemperature();
  
  control_temperature(temperature);
  control_humidity(humidity);

  if(lightness >= 700){
    digitalWrite(LED_PIN, HIGH);
  }
  else{
    digitalWrite(LED_PIN, LOW);
  }

/*if(temperature >= 1050){
  digitalWrite(FAN_PIN, HIGH);
  digitalWrite(HEATER_PIN, HIGH);
  }

  else{
  digitalWrite(FAN_PIN, LOW);
  digitalWrite(HEATER_PIN, LOW);
  }*/
//digitalWrite(HEATER_PIN, HIGH);
 // Serial.println(lightness);
  //Serial.println(humidity);
  
  delay(100);
}
