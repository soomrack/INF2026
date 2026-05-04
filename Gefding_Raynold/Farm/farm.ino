#include <stdio.h>
#include <DHT.h>


class Thermometer {
private:
    int pin;
    DHT dht;
public:    
    float temperature;
    int humidity_air;
public:
    Thermometer(int pin) : pin(pin), dht(pin, DHT11) {
        temperature = 20;
        humidity_air = 50;
        dht.begin();
    }
public:
    void get_temperature() {
        temperature = dht.readTemperature();
        humidity_air = dht.readHumidity();
        if (isnan(temperature)) temperature = 20;
        if (isnan(humidity_air)) humidity_air = 50;
    }
};


class Gigrometer {
private:
    int pin;
public:
    int humidity_soil;
public:
    Gigrometer(int pin) : pin(pin) { humidity_soil = 500; }
public:
    void get_humidity() {
        humidity_soil = analogRead(pin);
    }
};


class LightSensor {
private:
    int pin;
public:
    int light_level;
public:
    LightSensor(int pin) : pin(pin) { light_level = 500; }
public:
    void get_light() {
        light_level = analogRead(pin);
    }
};


class Relay {
protected:
    int pin;
public:
    bool on_temperature;
    bool on_humidity_air;
    bool on_humidity_soil;
    bool on_light;
public:
    Relay(int pin) : pin(pin) {
        on_temperature = false;
        on_humidity_air = false;
        on_humidity_soil = false;
        on_light = false;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
    }
};


class Heater : public Relay {
public:
    Heater(int pin) : Relay(pin) {}
public:
    void power() {
        if (on_temperature || on_humidity_air) {
            digitalWrite(pin, LOW);
        } else {
            digitalWrite(pin, HIGH);
        }
    }
};


class Fan : public Relay {
public:
    Fan(int pin) : Relay(pin) {}
public:
    void power() {
        if (on_temperature || on_humidity_air) {
            digitalWrite(pin, LOW);
        } else {
            digitalWrite(pin, HIGH);
        }
    }
};


class Pump : public Relay {
public:
    Pump(int pin) : Relay(pin) {}
public:
    void power() {
        if (on_humidity_soil) {
            digitalWrite(pin, LOW);
        } else {
            digitalWrite(pin, HIGH);
        }
    }
};


class Lamp : public Relay {
public:
    Lamp(int pin) : Relay(pin) {}
public:
    void power() {
        if (on_light) {
            digitalWrite(pin, LOW);
        } else {
            digitalWrite(pin, HIGH);
        }
    }
};


void control_temperature(const Thermometer& thermometer, Heater& heater, Fan& fan) {
    if (thermometer.temperature > 30.0) {
        heater.on_temperature = false;
        fan.on_temperature = true;
    }
    else if (thermometer.temperature < 18.0) {
        heater.on_temperature = true;
        fan.on_temperature = true;
    }
    else {
        heater.on_temperature = false;
        fan.on_temperature = false;
    }
}

void control_humidity_air(const Thermometer& thermometer, Heater& heater, Fan& fan) {
    if (thermometer.humidity_air > 80) {
        heater.on_humidity_air = true;
        fan.on_humidity_air = true;
    }
    else if (thermometer.humidity_air < 40) {
        heater.on_humidity_air = false;
        fan.on_humidity_air = false;
    }
    else {
        heater.on_humidity_air = false;
        fan.on_humidity_air = false;
    }
}

void control_humidity_soil(const Gigrometer& gigrometer, Pump& pump) {
    if (gigrometer.humidity_soil < 300) {
        pump.on_humidity_soil = true;
    }
    else if (gigrometer.humidity_soil > 700) {
        pump.on_humidity_soil = false;
    }
}

void control_light(const LightSensor& light, Lamp& lamp) {
    if (light.light_level < 400) {
        lamp.on_light = true;
    }
    else if (light.light_level > 600) {
        lamp.on_light = false;
    }
}


int main() {
    Serial.begin(9600);
    
    Thermometer thermometer(12);   // DHT11 on D12
    Gigrometer gigrometer(A1);     // soil_humidity on A1
    LightSensor light(A0);         // lightsensor on A0
    
    Heater heater(4);    // heater D4
    Fan fan(7);          // fan on D7
    Pump pump(5);        // pump on D5
    Lamp lamp(6);        // lamp on D6

    while (true) {
        thermometer.get_temperature();
        gigrometer.get_humidity();
        light.get_light();

        control_temperature(thermometer, heater, fan);
        control_humidity_air(thermometer, heater, fan);
        control_humidity_soil(gigrometer, pump);
        control_light(light, lamp);

        heater.power();
        fan.power();
        pump.power();
        lamp.power();

        Serial.print("Temp: ");
        Serial.print(thermometer.temperature);
        Serial.print(" *C | Air humidity: ");
        Serial.print(thermometer.humidity_air);
        Serial.print(" % | Soil moisture: ");
        Serial.print(gigrometer.humidity_soil);
        Serial.print(" | Light: ");
        Serial.println(light.light_level);

        delay(10000);
    }

    return 0;
}
