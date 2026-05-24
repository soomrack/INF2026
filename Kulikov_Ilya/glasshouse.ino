#include <Adafruit_Sensor.h>
#include <DHT_U.h>
#include <DHT.h>

typedef unsigned int Luxes;
typedef unsigned int DeciCelsius;
typedef double Percent;
typedef unsigned long Seconds;
typedef unsigned long Milliseconds;

enum Request {
    Disable = 0,
    Enable,
    Connect,
    
    UpdateLuminance,
    UpdateAirHumidity,
    UpdateSoilMoisture,
    UpdateTemperature,
    UpdateAbsoluteTime,
};

Luxes adc_level_to_luxes(int level)
{
   /* Assuming that at average luminance (~5000 luxes) photoresistor
      gives mean level 512, and that the relation is linear. */

   return level;
}

/* VVVVVVVVVVVVVVVVVVVVVVVV Target Measurements VVVVVVVVVVVVVVVVVVVVVVVV */

#define MIN_LUMINANCE      2700
#define MAX_LUMINANCE      8800
#define MIN_AIR_HUMIDITY   50.0
#define MAX_AIR_HUMIDITY   70.0
#define MIN_SOIL_MOISTURE  70.0
#define MAX_SOIL_MOISTURE  80.0
#define MIN_TEMPERATURE    180
#define MAX_TEMPERATURE    250
#define SUNRISE_TIME       21600 /* 06:00 */
#define SUNSET_TIME        64800 /* 18:00 */
#define START_CONDING_TIME 46800 /* 13:00 */
#define END_CONDING_TIME   48600 /* 13:30 */

/* VVVVVVVVVVVVVVVVVVVVVVVV Environment VVVVVVVVVVVVVVVVVVVVVVVV */

struct {
    Luxes luminance;
    Percent air_humidity;
    Percent soil_moisture;
    DeciCelsius temperature;
    Seconds absolute_time;
} env;

/* VVVVVVVVVVVVVVVVVVVVVVVV Pinout VVVVVVVVVVVVVVVVVVVVVVVV */

#define PHOTORESISTOR_PIN A0
#define DHT_PIN 2
#define FORK_PIN A1
#define LAMPS_RELAY_PIN 3
#define PUMP_RELAY_PIN 4
#define HEATER_RELAY_PIN 5
#define FAN_RELAY_PIN 6

/* VVVVVVVVVVVVVVVVVVVVVVVV Devices VVVVVVVVVVVVVVVVVVVVVVVV */

/* Connection: GND, 5V, analog pin */
void photoresistor(Request req)
{
    switch (req) {
//    case Connect:
//        return;
    case UpdateLuminance:
        env.luminance = adc_level_to_luxes(analogRead(PHOTORESISTOR_PIN));
        return;
    default:
        return;
    }
}


/* Connection: GND, 5V, digital pin */
void dht(Request req)
{
    static Percent air_humidity = 0;
    static DeciCelsius temperature = 0;
    static Milliseconds last_poll = 0;
    static int is_connected = 0;
    static DHT dht_device(DHT_PIN, DHT11);

    if (is_connected && (millis() - last_poll > 1000)) {
        air_humidity = dht_device.readHumidity();
        temperature = dht_device.readTemperature() * 10;
        last_poll = millis();
    }

    switch (req) {
    case Connect:
        dht_device.begin();
        is_connected = 1;
        return;
    case UpdateAirHumidity:
        env.air_humidity = air_humidity;
        return;
    case UpdateTemperature:
        env.temperature = temperature;
        return;
    default:
        return;
    }
}


/* Connection: GND, 5V, analog pin */
void fork(Request req)
{
    switch (req) {
//    case Connect:
//        return;
    case UpdateSoilMoisture:
        env.soil_moisture = analogRead(FORK_PIN) / 1024 * 100;
        return;
    default:
        return;
    }
}

 /* Unix Epoch Timestamp for MSK 2026-05-19:00-00-00 */
#define STARTUP_TIMESTAMP 1779138000
/* Connection: --- */ 
void absclock(Request req)
{
    switch (req) {
//    case Connect:
//        return;
    case UpdateAbsoluteTime:
        env.absolute_time = STARTUP_TIMESTAMP + millis() / 1000;
        return;
    default:
        return;
    }
}


/* Connection: GND, 5V, digital pin */
void lamps(Request req)
{
    static int state = Disable;

    switch (req) {
    case Connect:
        pinMode(LAMPS_RELAY_PIN, OUTPUT);
        digitalWrite(LAMPS_RELAY_PIN, HIGH);
        return;
    case Enable:
        if (!state) {
            digitalWrite(LAMPS_RELAY_PIN, LOW);
            state = Enable;
        }
        return;
    case Disable:
        if (state) {
            digitalWrite(LAMPS_RELAY_PIN, HIGH);
            state = Disable;
        }
        return;
    default:
        return;
    }
}


/* Connection: GND, 5V, digital pin */
void pump(Request req)
{
    static int state = Disable;
    
    switch (req) {
    case Connect:
        pinMode(PUMP_RELAY_PIN, OUTPUT);
        digitalWrite(PUMP_RELAY_PIN, HIGH);
        return;
    case Enable:
        if (!state) {
            digitalWrite(PUMP_RELAY_PIN, LOW);
            state = Enable;
        }
        return;
    case Disable:
        if (state) {
            digitalWrite(PUMP_RELAY_PIN, HIGH);
            state = Disable;
        }
        return;
    default:
        return;
    }
}


/* Connection: GND, 5V, digital pin */
void heater(Request req)
{
    static int state = Disable;
    
    switch (req) {
    case Connect:
        pinMode(HEATER_RELAY_PIN, OUTPUT);
        digitalWrite(HEATER_RELAY_PIN, HIGH);
        return;
    case Enable:
        if (!state) {
            digitalWrite(HEATER_RELAY_PIN, LOW);
            state = Enable;
        }
        return;
    case Disable:
        if (state) {
            digitalWrite(HEATER_RELAY_PIN, HIGH);
            state = Disable;
        }
        return;
    default:
        return;
    }
}


/* Connection: GND, 5V, digital pin */
void fan(Request req)
{
    static int state = Disable;
    
    switch (req) {
    case Connect:
        pinMode(FAN_RELAY_PIN, OUTPUT);
        digitalWrite(FAN_RELAY_PIN, HIGH);
        return;
    case Enable:
        if (!state) {
            digitalWrite(FAN_RELAY_PIN, LOW);
            state = Enable;
        }
        return;
    case Disable:
        if (state) {
            digitalWrite(FAN_RELAY_PIN, HIGH);
            state = Disable;
        }
        return;
    default:
        return;
    }
}

/* VVVVVVVVVVVVVVVVVVVVVVVV Biome Condition Predicates VVVVVVVVVVVVVVVVVVVVVVVV */

int its_dark()
{
    return env.luminance < MIN_LUMINANCE;
}


int its_nighttime()
{
    Seconds second_of_day = env.absolute_time % 86400;

    return (second_of_day < SUNRISE_TIME) ||
           (second_of_day > SUNSET_TIME);
}


int soil_is_dry()
{
    return env.soil_moisture < MIN_SOIL_MOISTURE;
}


int moistening_allowed()
{
    /*  Explanation:
     *  +
     *  Each day (86400 seconds) can be divided into 8640 intervals
     *  of 10 seconds each. Integer division allows us to get the
     *  number of this interval. We want there to be at least (an
     *  average) 10 seconds delay between moistenings for the water
     *  to reach the soil moisture sensor. We achieve this by
     *  alternating the time intervals when moistening is allowed
     *  and when it is forbidden, checking the interval number for
     *  parity.
     *  
     *  This way we ensure that the moistening will never last longer
     *  than 10 seconds, which compensates the "moistening impedance".
     */
    
    Seconds second_of_day = env.absolute_time % 86400;

    return (second_of_day / 8640) % 2 == 0;
}


int air_is_cold()
{
    return env.temperature < MIN_TEMPERATURE;
}


int air_is_warm()
{
    return env.temperature > MAX_TEMPERATURE;
}


int air_is_humid()
{
    return env.air_humidity > MAX_AIR_HUMIDITY;
}


int soil_is_moist()
{
    return env.soil_moisture > MAX_SOIL_MOISTURE;
}


int its_conditioning_time()
{
    Seconds second_of_day = env.absolute_time % 86400;

    return (second_of_day > START_CONDING_TIME) ||
           (second_of_day < END_CONDING_TIME);
}


/* VVVVVVVVVVVVVVVVVVVVVVVV Setup & Loop VVVVVVVVVVVVVVVVVVVVVVVV */

void clear_buffer(char *buffer, int len)
{
    for (int ith = 0; ith < len; ++ith)
        buffer[ith] = 0;
}


void printBiomeInfo()
{
#define BUFFER_LEN 64
    char print_buffer[BUFFER_LEN];
    clear_buffer(print_buffer, BUFFER_LEN);

    sprintf(print_buffer, "( (:luxs %08u) ", env.luminance);
    Serial.print(print_buffer);
    clear_buffer(print_buffer, BUFFER_LEN);

    sprintf(print_buffer, "(:air  %08.2f%%) ", env.air_humidity);
    Serial.print(print_buffer);
    clear_buffer(print_buffer, BUFFER_LEN);

    sprintf(print_buffer, "(:soil %08.2f%%) ", env.soil_moisture);
    Serial.print(print_buffer);
    clear_buffer(print_buffer, BUFFER_LEN);

    sprintf(print_buffer, "(:temp %08u.%u :celsius) ", env.temperature / 10, env.temperature % 10);
    Serial.print(print_buffer);
    clear_buffer(print_buffer, BUFFER_LEN);

    sprintf(print_buffer, "(:time %08lu) )", env.absolute_time);
    Serial.println(print_buffer);
}


void setup()
{
    Serial.begin(9600); /* and all-all-all */
    
    photoresistor(Connect);
    dht(Connect);
    fork(Connect);
    absclock(Connect);
}


void loop()
{
    photoresistor(UpdateLuminance);
    dht(UpdateAirHumidity);
    dht(UpdateTemperature);
    fork(UpdateSoilMoisture);
    absclock(UpdateAbsoluteTime);

    ( its_dark() && !its_nighttime() ) ?
        lamps(Enable) :
        lamps(Disable);

    ( soil_is_dry() && moistening_allowed() ) ?
        pump(Enable) :
        pump(Disable);

    ( air_is_cold() ) ?
        heater(Enable) :
        heater(Disable);

    ( !its_nighttime()
      && (air_is_warm()
      || air_is_cold()
      || air_is_humid()
      || soil_is_moist()
      || its_conditioning_time()) ) ?
        fan(Enable) :
        fan(Disable);

    printBiomeInfo();

    delay(10);
}
