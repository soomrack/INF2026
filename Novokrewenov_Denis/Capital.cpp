#include <stdio.h>
#include <string>


using RUB = long int;
using KILOMETER = long int;


struct Car {
    RUB value;
    int power;
    RUB gas_value_per_liter;
    float fuel_consumption_per_liter;
    KILOMETER run;


    RUB oil_cost;
    int oil_change_rate;
    int oil_changed_km;
    RUB air_filter_cost;
    int air_filter_change_rate;
    int air_filter_changed_km;
    RUB brakes_cost;
    int brakes_change_rate;
    int brakes_changed_km;
    RUB glass_washer_cost;
    int glass_washer_change_rate;
    int glass_washer_changed_km;


    RUB wash_cost;
    int wash_frequency;


    RUB accident_cost;
    int accident_period;
    int accident_period_base;
    int till_last_accident;
};


struct Taxi {
    RUB kilometr_cost;
    RUB weather_multiplier;
};


struct Cat {
    RUB feed;
};


struct Medicine {
    RUB bondage_cost;
    int bondage;
    RUB citramon_cost;


    int citramon;
    RUB nurofen_cost;
    int nurofen;
    RUB ksarelto_cost;
    int ksarelto;
    RUB kagocel_cost;
    int kagocel;
};


struct Apartment {
    RUB value;
    RUB payment;
    RUB rent;
};


struct Wear {
    RUB autumn_new_wear_cost;
    RUB winter_new_wear_cost;
    RUB spring_new_wear_cost;
    RUB summer_new_wear_cost;


    int autumn_wear_state;
    int winter_wear_state;
    int spring_wear_state;
    int summer_wear_state;


    bool is_autumn_wear_repaired;
    bool is_winter_wear_repaired;
    bool is_spring_wear_repaired;
    bool is_summer_wear_repaired;


    RUB autumn_wear_wash_cost;
    RUB winter_wear_wash_cost;
    RUB spring_wear_wash_cost;
    RUB summer_wear_wash_cost;


    RUB autumn_wear_repair_cost;
    RUB winter_wear_repair_cost;
    RUB spring_wear_repair_cost;
    RUB summer_wear_repair_cost;
};


struct Credit {
    RUB summ;
    RUB min_credit;
    RUB max_credit;
    float interest_rate_per_month;
    int duration;
    int payment_per_month;
};


struct Bank {
    RUB account;
    float deposit_interest;
    Credit car_credit;
    Credit apartment_credit;
};


struct Person {
    std::string name;
    float tax_income;


    RUB salary;
    RUB capital;
    RUB food;
    Car car;
    Taxi taxi;
    Cat pet;
    Wear wear;


    Apartment apartment;


    Bank VTB;
    RUB poket_money_target;


    RUB feb23th_cost;
    RUB mar8th_cost;
    RUB newyear_cost;
    RUB dad_birthday_cost;
    RUB mom_birthday_cost;
    RUB sister_birthday_cost;
    RUB best_friend_birthday_cost;
    RUB partner_birthday_cost;


    int dad_birthday_month;
    int mom_birthday_month;
    int sister_birthday_month;
    int best_friend_birthday_month;
    int partner_birthday_month;
};


struct Person Alice;
struct Person Bob;
struct Person Kate;
struct Person Steve;


const float cash_interest_per_month = 1.0 + 15.0 / 12.0 / 100.0;
const float apartment_interest_per_month = 1.0 + 17.0 / 12.0 / 100.0;
const float salary_indexation = 1.07;
const float income_tax = 1 - 0.13;
RUB normal_car_TO = 7500;


void alice_pet() {
    Alice.pet.feed = Alice.pet.feed * cash_interest_per_month;
    Alice.VTB.account -= Alice.pet.feed;
}

void bob_pet() {
    Bob.pet.feed = Bob.pet.feed * cash_interest_per_month;
    Bob.VTB.account -= Bob.pet.feed;
}

void kate_pet() {
    Kate.pet.feed = Kate.pet.feed * cash_interest_per_month;
    Kate.VTB.account -= Kate.pet.feed;
}

void steve_pet() {
    Steve.pet.feed = Steve.pet.feed * cash_interest_per_month;
    Steve.VTB.account -= Steve.pet.feed;
}


RUB tax_by_power_per_month (const int power) {
    RUB power_multiplier;


    if (power <= 100) power_multiplier = 13;
    else if (power <= 125) power_multiplier = 28;
    else if (power <= 150) power_multiplier = 39;
    else if (power <= 175) power_multiplier = 50;
    else if (power <= 200) power_multiplier = 61;
    else if (power <= 225) power_multiplier = 72;
    else if (power <= 250) power_multiplier = 110;
    else power_multiplier = 150;


    return power * power_multiplier / 12;
}


void alice_buy_car (const int month, const int year) {
    if (Alice.VTB.account >= Alice.car.value && Alice.car.gas_value_per_liter == 0){
        Alice.VTB.account -= Alice.car.value;


        Alice.car.power = 140;
        Alice.car.gas_value_per_liter = 68;
        Alice.car.fuel_consumption_per_liter = 7/100;
        KILOMETER run;


        Alice.car.oil_cost = 1200;
        Alice.car.oil_change_rate = 8000;
        Alice.car.oil_changed_km = 0;
        Alice.car.air_filter_cost = 1500;
        Alice.car.air_filter_change_rate = 12000;
        Alice.car.air_filter_changed_km = 0;
        Alice.car.brakes_cost = 6000;
        Alice.car.brakes_change_rate = 40000;
        Alice.car.brakes_changed_km = 0;
        Alice.car.glass_washer_cost = 1500;
        Alice.car.glass_washer_change_rate = 10000;
        Alice.car.glass_washer_changed_km = 0;


        Alice.car.wash_cost = 1000;
        Alice.car.wash_frequency = 2;


        Alice.car.accident_cost = Alice.car.value * 0.15;
        Alice.car.accident_period_base = 6;
        Alice.car.accident_period = Alice.car.accident_period_base + (int)((Alice.car.brakes_cost + Alice.car.glass_washer_cost - normal_car_TO) / 3000);
        Alice.car.till_last_accident = 0;


        printf("%s bought a car in %d month of %d for %d RUB\n", Alice.name.c_str(), month, year, Alice.car.value);
    }
}

void bob_buy_car (const int month, const int year) {
    if (Bob.VTB.account >= Bob.car.value && Bob.car.gas_value_per_liter == 0){
        Bob.VTB.account -= Bob.car.value;


        Bob.car.power = 170;
        Bob.car.gas_value_per_liter = 75;
        Bob.car.fuel_consumption_per_liter = 7.0/100.0;
        KILOMETER run;


        Bob.car.oil_cost = 1600;
        Bob.car.oil_change_rate = 10000;
        Bob.car.oil_changed_km = 0;
        Bob.car.air_filter_cost = 2000;
        Bob.car.air_filter_change_rate = 12000;
        Bob.car.air_filter_changed_km = 0;
        Bob.car.brakes_cost = 8000;
        Bob.car.brakes_change_rate = 40000;
        Bob.car.brakes_changed_km = 0;
        Bob.car.glass_washer_cost = 6000;
        Bob.car.glass_washer_change_rate = 10000;
        Bob.car.glass_washer_changed_km = 0;


        Bob.car.wash_cost = 3000;
        Bob.car.wash_frequency = 2;


        Bob.car.accident_cost = Bob.car.value * 0.15;
        Bob.car.accident_period_base = 6;
        Bob.car.accident_period = Bob.car.accident_period_base + (int)((Bob.car.brakes_cost + Bob.car.glass_washer_cost - normal_car_TO) / 3000);
        Bob.car.till_last_accident = 0;


        printf("%s bought a car in %d month of %d for %d RUB\n", Bob.name.c_str(), month, year, Bob.car.value);
    }
}

void kate_buy_car (const int month, const int year) {
    if (Kate.VTB.account >= Kate.car.value && Kate.car.gas_value_per_liter == 0){
        Kate.VTB.account -= Kate.car.value;


        Kate.car.power = 95;
        Kate.car.gas_value_per_liter = 60;
        Kate.car.fuel_consumption_per_liter = 4.0/100.0;
        KILOMETER run;


        Kate.car.oil_cost = 1000;
        Kate.car.oil_change_rate = 8000;
        Kate.car.oil_changed_km = 0;
        Kate.car.air_filter_cost = 1000;
        Kate.car.air_filter_change_rate = 12000;
        Kate.car.air_filter_changed_km = 0;
        Kate.car.brakes_cost = 5000;
        Kate.car.brakes_change_rate = 40000;
        Kate.car.brakes_changed_km = 0;
        Kate.car.glass_washer_cost = 1200;
        Kate.car.glass_washer_change_rate = 10000;
        Kate.car.glass_washer_changed_km = 0;


        Kate.car.wash_cost = 1000;
        Kate.car.wash_frequency = 2;


        Kate.car.accident_cost = Kate.car.value * 0.15;
        Kate.car.accident_period_base = 6;
        Kate.car.accident_period = Kate.car.accident_period_base + (int)((Kate.car.brakes_cost + Kate.car.glass_washer_cost - normal_car_TO) / 3000);
        Kate.car.till_last_accident = 0;


        printf("%s bought a car in %d month of %d for %d RUB\n", Kate.name.c_str(), month, year, Kate.car.value);
    }
}

void steve_buy_car (const int month, const int year) {
    if (Steve.VTB.account >= Steve.car.value && Steve.car.gas_value_per_liter == 0){
        Steve.VTB.account -= Steve.car.value;


        Steve.car.power = 200;
        Steve.car.gas_value_per_liter = 80;
        Steve.car.fuel_consumption_per_liter = 10.0/100.0;
        KILOMETER run;


        Steve.car.oil_cost = 2000;
        Steve.car.oil_change_rate = 5000;
        Steve.car.oil_changed_km = 0;
        Steve.car.air_filter_cost = 3000;
        Steve.car.air_filter_change_rate = 10000;
        Steve.car.air_filter_changed_km = 0;
        Steve.car.brakes_cost = 9000;
        Steve.car.brakes_change_rate = 30000;
        Steve.car.brakes_changed_km = 0;
        Steve.car.glass_washer_cost = 3000;
        Steve.car.glass_washer_change_rate = 6000;
        Steve.car.glass_washer_changed_km = 0;


        Steve.car.wash_cost = 3000;
        Steve.car.wash_frequency = 4;


        Steve.car.accident_cost = Steve.car.value * 0.15;
        Steve.car.accident_period_base = 6;
        Steve.car.accident_period = Steve.car.accident_period_base + (int)((Steve.car.brakes_cost + Steve.car.glass_washer_cost - normal_car_TO) / 3000);
        Steve.car.till_last_accident = 0;


        printf("%s bought a car in %d month of %d for %d RUB\n", Steve.name.c_str(), month, year, Steve.car.value);
    }
}


void car_service(Person& person){
    if (person.car.run - person.car.oil_changed_km > person.car.oil_change_rate) {
        person.VTB.account -= person.car.oil_cost;
        person.car.oil_changed_km = person.car.run;
    }
    if (person.car.run - person.car.air_filter_changed_km > person.car.air_filter_change_rate) {
        person.VTB.account -= person.car.air_filter_cost;
        person.car.air_filter_changed_km = person.car.run;
    }
    if (person.car.run - person.car.brakes_changed_km > person.car.brakes_change_rate) {
        person.VTB.account -= person.car.brakes_cost;
        person.car.brakes_changed_km = person.car.run;
    }
    if (person.car.run - person.car.glass_washer_changed_km > person.car.glass_washer_change_rate) {
        person.VTB.account -= person.car.glass_washer_cost;
        person.car.glass_washer_changed_km = person.car.run;
    }
}


void alice_car(const int month, const int year, KILOMETER run_by_month) {
    
    normal_car_TO *= cash_interest_per_month;


    Alice.car.run += run_by_month;


    Alice.VTB.account -= run_by_month * Alice.car.fuel_consumption_per_liter * Alice.car.gas_value_per_liter;
    Alice.VTB.account -= tax_by_power_per_month(Alice.car.power);
    car_service(Alice);


    int extra_wash = 0;
    if (2 < month && month < 6 || 8 < month && month < 12) extra_wash = 1;
    Alice.VTB.account -= Alice.car.wash_cost * (Alice.car.wash_frequency + extra_wash);


    Alice.car.till_last_accident += 1;
    if (Alice.car.till_last_accident > Alice.car.accident_period) {
        Alice.car.till_last_accident = 0;
        Alice.VTB.account -= Alice.car.accident_cost;
        printf("%s take an accident in %d month of %d for %d RUB\n", Alice.name.c_str(), month, year, Alice.car.accident_cost);
    }
}

void bob_car(const int month, const int year, KILOMETER run_by_month) {
    
    normal_car_TO *= cash_interest_per_month;


    Bob.car.run += run_by_month;


    Bob.VTB.account -= run_by_month * Bob.car.fuel_consumption_per_liter * Bob.car.gas_value_per_liter;
    Bob.VTB.account -= tax_by_power_per_month(Bob.car.power);
    car_service(Bob);


    int extra_wash = 0;
    if (2 < month && month < 6 || 8 < month && month < 12) extra_wash = 1;
    Bob.VTB.account -= Bob.car.wash_cost * (Bob.car.wash_frequency + extra_wash);


    Bob.car.till_last_accident += 1;
    if (Bob.car.till_last_accident > Bob.car.accident_period) {
        Bob.car.till_last_accident = 0;
        Bob.VTB.account -= Bob.car.accident_cost;
        printf("%s take an accident in %d month of %d for %d RUB\n", Bob.name.c_str(), month, year, Bob.car.accident_cost);
    }
}

void kate_car(const int month, const int year, KILOMETER run_by_month) {
    
    normal_car_TO *= cash_interest_per_month;


    Kate.car.run += run_by_month;


    Kate.VTB.account -= run_by_month * Kate.car.fuel_consumption_per_liter * Kate.car.gas_value_per_liter;
    Kate.VTB.account -= tax_by_power_per_month(Kate.car.power);
    car_service(Kate);


    int extra_wash = 0;
    if (2 < month && month < 6 || 8 < month && month < 12) extra_wash = 1;
    Kate.VTB.account -= Kate.car.wash_cost * (Kate.car.wash_frequency + extra_wash);


    Kate.car.till_last_accident += 1;
    if (Kate.car.till_last_accident > Kate.car.accident_period) {
        Kate.car.till_last_accident = 0;
        Kate.VTB.account -= Kate.car.accident_cost;
        printf("%s take an accident in %d month of %d for %d RUB\n", Kate.name.c_str(), month, year, Kate.car.accident_cost);
    }
}

void steve_car(const int month, const int year, KILOMETER run_by_month) {
    
    normal_car_TO *= cash_interest_per_month;


    Steve.car.run += run_by_month;


    Steve.VTB.account -= run_by_month * Steve.car.fuel_consumption_per_liter * Steve.car.gas_value_per_liter;
    Steve.VTB.account -= tax_by_power_per_month(Steve.car.power);
    car_service(Steve);


    int extra_wash = 0;
    if (2 < month && month < 6 || 8 < month && month < 12) extra_wash = 1;
    Steve.VTB.account -= Steve.car.wash_cost * (Steve.car.wash_frequency + extra_wash);


    Steve.car.till_last_accident += 1;
    if (Steve.car.till_last_accident > Steve.car.accident_period) {
        Steve.car.till_last_accident = 0;
        Steve.VTB.account -= Steve.car.accident_cost;
        printf("%s take an accident in %d month of %d for %d RUB\n", Steve.name.c_str(), month, year, Steve.car.accident_cost);
    }
}


void alice_taxi(const int month, const int year, KILOMETER run_by_month) {
    


    if (12 == month || month < 3) {
        Alice.taxi.weather_multiplier = 1.7;
    }
    if (2 < month && month < 6) {
        Alice.taxi.weather_multiplier = 1.5;
    }
    if (5 < month && month < 9) {
        Alice.taxi.weather_multiplier = 1;
    }
    if (8 < month && month < 12) {
        Alice.taxi.weather_multiplier = 1.5;
    }


    Alice.VTB.account -= run_by_month * Alice.taxi.kilometr_cost;
}

void bob_taxi(const int month, const int year, KILOMETER run_by_month) {
    


    if (12 == month || month < 3) {
        Bob.taxi.weather_multiplier = 1.7;
    }
    if (2 < month && month < 6) {
        Bob.taxi.weather_multiplier = 1.5;
    }
    if (5 < month && month < 9) {
        Bob.taxi.weather_multiplier = 1;
    }
    if (8 < month && month < 12) {
        Bob.taxi.weather_multiplier = 1.5;
    }


    Bob.VTB.account -= run_by_month * Bob.taxi.kilometr_cost;
}

void kate_taxi(const int month, const int year, KILOMETER run_by_month) {
    


    if (12 == month || month < 3) {
        Kate.taxi.weather_multiplier = 1.7;
    }
    if (2 < month && month < 6) {
        Kate.taxi.weather_multiplier = 1.5;
    }
    if (5 < month && month < 9) {
        Kate.taxi.weather_multiplier = 1;
    }
    if (8 < month && month < 12) {
        Kate.taxi.weather_multiplier = 1.5;
    }


    Kate.VTB.account -= run_by_month * Kate.taxi.kilometr_cost;
}

void steve_taxi(const int month, const int year, KILOMETER run_by_month) {
    


    if (12 == month || month < 3) {
        Steve.taxi.weather_multiplier = 1.7;
    }
    if (2 < month && month < 6) {
        Steve.taxi.weather_multiplier = 1.5;
    }
    if (5 < month && month < 9) {
        Steve.taxi.weather_multiplier = 1;
    }
    if (8 < month && month < 12) {
        Steve.taxi.weather_multiplier = 1.5;
    }


    Steve.VTB.account -= run_by_month * Steve.taxi.kilometr_cost;
}


void alice_moving (const int month, const int year) {
    Alice.taxi.kilometr_cost *= cash_interest_per_month;
    Alice.car.value *= cash_interest_per_month;
    Alice.car.gas_value_per_liter *= cash_interest_per_month;
    Alice.car.oil_cost *= cash_interest_per_month;
    Alice.car.air_filter_cost *= cash_interest_per_month;
    Alice.car.brakes_cost *= cash_interest_per_month;
    Alice.car.glass_washer_cost *= cash_interest_per_month;
    Alice.car.wash_cost *= cash_interest_per_month;
    Alice.car.accident_cost *= cash_interest_per_month;



    KILOMETER run_by_month = 1200;
    if (Alice.car.gas_value_per_liter != 0) {
        alice_car(month, year, run_by_month);
    }
    else {
        alice_taxi(month, year, run_by_month);
    }
}

void bob_moving (const int month, const int year) {
    Bob.taxi.kilometr_cost *= cash_interest_per_month;
    Bob.car.value *= cash_interest_per_month;
    Bob.car.gas_value_per_liter *= cash_interest_per_month;
    Bob.car.oil_cost *= cash_interest_per_month;
    Bob.car.air_filter_cost *= cash_interest_per_month;
    Bob.car.brakes_cost *= cash_interest_per_month;
    Bob.car.glass_washer_cost *= cash_interest_per_month;
    Bob.car.wash_cost *= cash_interest_per_month;
    Bob.car.accident_cost *= cash_interest_per_month;



    KILOMETER run_by_month = 1200;
    if (Bob.car.gas_value_per_liter != 0) {
        bob_car(month, year, run_by_month);
    }
    else {
        bob_taxi(month, year, run_by_month);
    }
}

void kate_moving (const int month, const int year) {
    Kate.taxi.kilometr_cost *= cash_interest_per_month;
    Kate.car.value *= cash_interest_per_month;
    Kate.car.gas_value_per_liter *= cash_interest_per_month;
    Kate.car.oil_cost *= cash_interest_per_month;
    Kate.car.air_filter_cost *= cash_interest_per_month;
    Kate.car.brakes_cost *= cash_interest_per_month;
    Kate.car.glass_washer_cost *= cash_interest_per_month;
    Kate.car.wash_cost *= cash_interest_per_month;
    Kate.car.accident_cost *= cash_interest_per_month;



    KILOMETER run_by_month = 1200;
    if (Kate.car.gas_value_per_liter != 0) {
        kate_car(month, year, run_by_month);
    }
    else {
        kate_taxi(month, year, run_by_month);
    }
}

void steve_moving (const int month, const int year) {
    Steve.taxi.kilometr_cost *= cash_interest_per_month;
    Steve.car.value *= cash_interest_per_month;
    Steve.car.gas_value_per_liter *= cash_interest_per_month;
    Steve.car.oil_cost *= cash_interest_per_month;
    Steve.car.air_filter_cost *= cash_interest_per_month;
    Steve.car.brakes_cost *= cash_interest_per_month;
    Steve.car.glass_washer_cost *= cash_interest_per_month;
    Steve.car.wash_cost *= cash_interest_per_month;
    Steve.car.accident_cost *= cash_interest_per_month;



    KILOMETER run_by_month = 1200;
    if (Steve.car.gas_value_per_liter != 0) {
        steve_car(month, year, run_by_month);
    }
    else {
        steve_taxi(month, year, run_by_month);
    }
}


void alice_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) { // Promotion
        Alice.salary *= 1.5;
    }


    if (month == 10) {
        Alice.salary *= salary_indexation;
    }


    Alice.capital += Alice.salary * income_tax;
    RUB moved_sum = Alice.capital - Alice.poket_money_target;
    Alice.VTB.account += moved_sum;
    Alice.capital -= moved_sum;
}

void bob_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) { // Promotion
        Bob.salary *= 2.5;
    }


    if (month == 10) {
        Bob.salary *= salary_indexation;
    }


    Bob.capital += Bob.salary * income_tax;
    RUB moved_sum = Bob.capital - Bob.poket_money_target;
    Bob.VTB.account += moved_sum;
    Bob.capital -= moved_sum;
}

void kate_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) { // Promotion
        Kate.salary *= 1.5;
    }


    if (month == 10) {
        Kate.salary *= salary_indexation;
    }


    Kate.capital += Kate.salary * income_tax;
    RUB moved_sum = Kate.capital - Kate.poket_money_target;
    Kate.VTB.account += moved_sum;
    Kate.capital -= moved_sum;
}

void steve_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) { // Promotion
        Steve.salary *= 1.5;
    }


    if (month == 10) {
        Steve.salary *= salary_indexation;
    }


    Steve.capital += Steve.salary * income_tax;
    RUB moved_sum = Steve.capital - Steve.poket_money_target;
    Steve.VTB.account += moved_sum;
    Steve.capital -= moved_sum;
}


void alice_food() {
    Alice.food = Alice.food * cash_interest_per_month;
    Alice.VTB.account -= Alice.food;
}

void bob_food() {
    Bob.food = Bob.food * cash_interest_per_month;
    Bob.VTB.account -= Bob.food;
}

void kate_food() {
    Kate.food = Kate.food * cash_interest_per_month;
    Kate.VTB.account -= Kate.food;
}

void steve_food() {
    Steve.food = Steve.food * cash_interest_per_month;
    Steve.VTB.account -= Steve.food;
}


void alice_buy_apartment(const int month, const int year) {
    if (Alice.apartment.rent != 0 && Alice.VTB.account >= Alice.apartment.value){
        Alice.VTB.account -= Alice.apartment.value;
        Alice.apartment.rent = 0;
        Alice.apartment.payment += 10000;
        printf("%s bought an apartment in %d month of %d for %d RUB\n", Alice.name.c_str(), month, year, Alice.apartment.value);
    }
}

void bob_buy_apartment(const int month, const int year) {
    if (Bob.apartment.rent != 0 && Bob.VTB.account >= Bob.apartment.value){
        Bob.VTB.account -= Bob.apartment.value;
        Bob.apartment.rent = 0;
        Bob.apartment.payment += 10000;
        printf("%s bought an apartment in %d month of %d for %d RUB\n", Bob.name.c_str(), month, year, Bob.apartment.value);
    }
}

void kate_buy_apartment(const int month, const int year) {
    if (Kate.apartment.rent != 0 && Kate.VTB.account >= Kate.apartment.value){
        Kate.VTB.account -= Kate.apartment.value;
        Kate.apartment.rent = 0;
        Kate.apartment.payment += 10000;
        printf("%s bought an apartment in %d month of %d for %d RUB\n", Kate.name.c_str(), month, year, Kate.apartment.value);
    }
}

void steve_buy_apartment(const int month, const int year) {
    if (Steve.apartment.rent != 0 && Steve.VTB.account >= Steve.apartment.value){
        Steve.VTB.account -= Steve.apartment.value;
        Steve.apartment.rent = 0;
        Steve.apartment.payment += 10000;
        printf("%s bought an apartment in %d month of %d for %d RUB\n", Steve.name.c_str(), month, year, Steve.apartment.value);
    }
}


void alice_apartment(const int month, const int year) {
    Alice.apartment.payment *= apartment_interest_per_month;
    Alice.apartment.value *= cash_interest_per_month;
    Alice.apartment.rent *= apartment_interest_per_month;


    Alice.VTB.account -= Alice.apartment.payment;
    Alice.VTB.account -= Alice.apartment.rent;
}

void bob_apartment(const int month, const int year) {
    Bob.apartment.payment *= apartment_interest_per_month;
    Bob.apartment.value *= cash_interest_per_month;
    Bob.apartment.rent *= apartment_interest_per_month;


    Bob.VTB.account -= Bob.apartment.payment;
    Bob.VTB.account -= Bob.apartment.rent;
}

void kate_apartment(const int month, const int year) {
    Kate.apartment.payment *= apartment_interest_per_month;
    Kate.apartment.value *= cash_interest_per_month;
    Kate.apartment.rent *= apartment_interest_per_month;


    Kate.VTB.account -= Kate.apartment.payment;
    Kate.VTB.account -= Kate.apartment.rent;
}

void steve_apartment(const int month, const int year) {
    Steve.apartment.payment *= apartment_interest_per_month;
    Steve.apartment.value *= cash_interest_per_month;
    Steve.apartment.rent *= apartment_interest_per_month;


    Steve.VTB.account -= Steve.apartment.payment;
    Steve.VTB.account -= Steve.apartment.rent;
}


void alice_bank() {
    Alice.VTB.account += Alice.VTB.account * Alice.VTB.deposit_interest;

    if (Alice.VTB.car_credit.summ > 0){
        RUB payment = Alice.VTB.car_credit.payment_per_month;
        if (payment > Alice.VTB.car_credit.summ) {
            payment = Alice.VTB.car_credit.summ;  // в последний месяц платим ровно остаток
        }
        Alice.VTB.account -= payment;
        Alice.VTB.car_credit.summ -= payment;
        Alice.VTB.account -= Alice.VTB.car_credit.interest_rate_per_month * Alice.VTB.car_credit.summ;
    }

    if (Alice.VTB.apartment_credit.summ > 0){
        RUB payment = Alice.VTB.apartment_credit.payment_per_month;
        if (payment > Alice.VTB.apartment_credit.summ) {
            payment = Alice.VTB.apartment_credit.summ;
        }
        Alice.VTB.account -= payment;
        Alice.VTB.apartment_credit.summ -= payment;
        Alice.VTB.account -= Alice.VTB.apartment_credit.interest_rate_per_month * Alice.VTB.apartment_credit.summ;
    }
}

void bob_bank() {
    Bob.VTB.account += Bob.VTB.account * Bob.VTB.deposit_interest;

    if (Bob.VTB.car_credit.summ > 0){
        RUB payment = Bob.VTB.car_credit.payment_per_month;
        if (payment > Bob.VTB.car_credit.summ) {
            payment = Bob.VTB.car_credit.summ;
        }
        Bob.VTB.account -= payment;
        Bob.VTB.car_credit.summ -= payment;
        Bob.VTB.account -= Bob.VTB.car_credit.interest_rate_per_month * Bob.VTB.car_credit.summ;
    }

    if (Bob.VTB.apartment_credit.summ > 0){
        RUB payment = Bob.VTB.apartment_credit.payment_per_month;
        if (payment > Bob.VTB.apartment_credit.summ) {
            payment = Bob.VTB.apartment_credit.summ;
        }
        Bob.VTB.account -= payment;
        Bob.VTB.apartment_credit.summ -= payment;
        Bob.VTB.account -= Bob.VTB.apartment_credit.interest_rate_per_month * Bob.VTB.apartment_credit.summ;
    }
}

void kate_bank() {
    Kate.VTB.account += Kate.VTB.account * Kate.VTB.deposit_interest;

    if (Kate.VTB.car_credit.summ > 0){
        RUB payment = Kate.VTB.car_credit.payment_per_month;
        if (payment > Kate.VTB.car_credit.summ) {
            payment = Kate.VTB.car_credit.summ;
        }
        Kate.VTB.account -= payment;
        Kate.VTB.car_credit.summ -= payment;
        Kate.VTB.account -= Kate.VTB.car_credit.interest_rate_per_month * Kate.VTB.car_credit.summ;
    }

    if (Kate.VTB.apartment_credit.summ > 0){
        RUB payment = Kate.VTB.apartment_credit.payment_per_month;
        if (payment > Kate.VTB.apartment_credit.summ) {
            payment = Kate.VTB.apartment_credit.summ;
        }
        Kate.VTB.account -= payment;
        Kate.VTB.apartment_credit.summ -= payment;
        Kate.VTB.account -= Kate.VTB.apartment_credit.interest_rate_per_month * Kate.VTB.apartment_credit.summ;
    }
}

void steve_bank() {
    Steve.VTB.account += Steve.VTB.account * Steve.VTB.deposit_interest;

    if (Steve.VTB.car_credit.summ > 0){
        RUB payment = Steve.VTB.car_credit.payment_per_month;
        if (payment > Steve.VTB.car_credit.summ) {
            payment = Steve.VTB.car_credit.summ;
        }
        Steve.VTB.account -= payment;
        Steve.VTB.car_credit.summ -= payment;
        Steve.VTB.account -= Steve.VTB.car_credit.interest_rate_per_month * Steve.VTB.car_credit.summ;
    }

    if (Steve.VTB.apartment_credit.summ > 0){
        RUB payment = Steve.VTB.apartment_credit.payment_per_month;
        if (payment > Steve.VTB.apartment_credit.summ) {
            payment = Steve.VTB.apartment_credit.summ;
        }
        Steve.VTB.account -= payment;
        Steve.VTB.apartment_credit.summ -= payment;
        Steve.VTB.account -= Steve.VTB.apartment_credit.interest_rate_per_month * Steve.VTB.apartment_credit.summ;
    }
}

void alice_take_car_credit(const int month, const int year) {
    if (Alice.car.gas_value_per_liter == 0) {
        if (Alice.car.value - Alice.VTB.account < Alice.VTB.car_credit.max_credit) {
            Alice.VTB.car_credit.summ = Alice.car.value - Alice.VTB.account;
            Alice.VTB.car_credit.duration = 18;
            Alice.VTB.car_credit.payment_per_month = Alice.VTB.car_credit.summ / Alice.VTB.car_credit.duration;


            Alice.VTB.account += Alice.VTB.car_credit.summ;
            printf("%s took a car credit in %d month of %d for %d RUB\n", Alice.name.c_str(), month, year, Alice.VTB.car_credit.summ);
        }
    }
}

void bob_take_car_credit(const int month, const int year) {
    if (Bob.car.gas_value_per_liter == 0) {
        if (Bob.car.value - Bob.VTB.account < Bob.VTB.car_credit.max_credit) {
            Bob.VTB.car_credit.summ = Bob.car.value - Bob.VTB.account;
            Bob.VTB.car_credit.duration = 18;
            Bob.VTB.car_credit.payment_per_month = Bob.VTB.car_credit.summ / Bob.VTB.car_credit.duration;


            Bob.VTB.account += Bob.VTB.car_credit.summ;
            printf("%s took a car credit in %d month of %d for %d RUB\n", Bob.name.c_str(), month, year, Bob.VTB.car_credit.summ);
        }
    }
}

void kate_take_car_credit(const int month, const int year) {
    if (Kate.car.gas_value_per_liter == 0) {
        if (Kate.car.value - Kate.VTB.account < Kate.VTB.car_credit.max_credit) {
            Kate.VTB.car_credit.summ = Kate.car.value - Kate.VTB.account;
            Kate.VTB.car_credit.duration = 18;
            Kate.VTB.car_credit.payment_per_month = Kate.VTB.car_credit.summ / Kate.VTB.car_credit.duration;


            Kate.VTB.account += Kate.VTB.car_credit.summ;
            printf("%s took a car credit in %d month of %d for %d RUB\n", Kate.name.c_str(), month, year, Kate.VTB.car_credit.summ);
        }
    }
}

void steve_take_car_credit(const int month, const int year) {
    if (Steve.car.gas_value_per_liter == 0) {
        if (Steve.car.value - Steve.VTB.account < Steve.VTB.car_credit.max_credit) {
            Steve.VTB.car_credit.summ = Steve.car.value - Steve.VTB.account;
            Steve.VTB.car_credit.duration = 18;
            Steve.VTB.car_credit.payment_per_month = Steve.VTB.car_credit.summ / Steve.VTB.car_credit.duration;


            Steve.VTB.account += Steve.VTB.car_credit.summ;
            printf("%s took a car credit in %d month of %d for %d RUB\n", Steve.name.c_str(), month, year, Steve.VTB.car_credit.summ);
        }
    }
}


void alice_take_apartment_credit(const int month, const int year) {
    if (Alice.apartment.rent != 0) {
        if (Alice.apartment.value - Alice.VTB.account < Alice.VTB.apartment_credit.max_credit) {
            Alice.VTB.apartment_credit.summ = Alice.apartment.value - Alice.VTB.account;
            Alice.VTB.apartment_credit.duration = 120;
            Alice.VTB.apartment_credit.payment_per_month = Alice.VTB.apartment_credit.summ / Alice.VTB.apartment_credit.duration;


            Alice.VTB.account += Alice.VTB.apartment_credit.summ;
            printf("%s took an apartment credit in %d month of %d for %d RUB\n", Alice.name.c_str(), month, year, Alice.VTB.apartment_credit.summ);
        }
    }
}

void bob_take_apartment_credit(const int month, const int year) {
    if (Bob.apartment.rent != 0) {
        if (Bob.apartment.value - Bob.VTB.account < Bob.VTB.apartment_credit.max_credit) {
            Bob.VTB.apartment_credit.summ = Bob.apartment.value - Bob.VTB.account;
            Bob.VTB.apartment_credit.duration = 120;
            Bob.VTB.apartment_credit.payment_per_month = Bob.VTB.apartment_credit.summ / Bob.VTB.apartment_credit.duration;


            Bob.VTB.account += Bob.VTB.apartment_credit.summ;
            printf("%s took an apartment credit in %d month of %d for %d RUB\n", Bob.name.c_str(), month, year, Bob.VTB.apartment_credit.summ);
        }
    }
}

void kate_take_apartment_credit(const int month, const int year) {
    if (Kate.apartment.rent != 0) {
        if (Kate.apartment.value - Kate.VTB.account < Kate.VTB.apartment_credit.max_credit) {
            Kate.VTB.apartment_credit.summ = Kate.apartment.value - Kate.VTB.account;
            Kate.VTB.apartment_credit.duration = 120;
            Kate.VTB.apartment_credit.payment_per_month = Kate.VTB.apartment_credit.summ / Kate.VTB.apartment_credit.duration;


            Kate.VTB.account += Kate.VTB.apartment_credit.summ;
            printf("%s took an apartment credit in %d month of %d for %d RUB\n", Kate.name.c_str(), month, year, Kate.VTB.apartment_credit.summ);
        }
    }
}

void steve_take_apartment_credit(const int month, const int year) {
    if (Steve.apartment.rent != 0) {
        if (Steve.apartment.value - Steve.VTB.account < Steve.VTB.apartment_credit.max_credit) {
            Steve.VTB.apartment_credit.summ = Steve.apartment.value - Steve.VTB.account;
            Steve.VTB.apartment_credit.duration = 120;
            Steve.VTB.apartment_credit.payment_per_month = Steve.VTB.apartment_credit.summ / Steve.VTB.apartment_credit.duration;


            Steve.VTB.account += Steve.VTB.apartment_credit.summ;
            printf("%s took an apartment credit in %d month of %d for %d RUB\n", Steve.name.c_str(), month, year, Steve.VTB.apartment_credit.summ);
        }
    }
}


void alice_holidays(const int month) {
    if (month == 2) {
        Alice.VTB.account -= Alice.feb23th_cost;
    }
    if (month == 3) {
        Alice.VTB.account -= Alice.mar8th_cost;
    }
    if (month == Alice.dad_birthday_month) {
        Alice.VTB.account -= Alice.dad_birthday_cost;
    }
    if (month == Alice.mom_birthday_month) {
        Alice.VTB.account -= Alice.mom_birthday_cost;
    }
    if (month == Alice.sister_birthday_month) {
        Alice.VTB.account -= Alice.sister_birthday_cost;
    }
    if (month == Alice.best_friend_birthday_month) {
        Alice.VTB.account -= Alice.best_friend_birthday_cost;
    }
    if (month == 12) {
        Alice.VTB.account -= Alice.newyear_cost;
    }
}

void bob_holidays(const int month) {
    if (month == 2) {
        Bob.VTB.account -= Bob.feb23th_cost;
    }
    if (month == 3) {
        Bob.VTB.account -= Bob.mar8th_cost;
    }
    if (month == Bob.dad_birthday_month) {
        Bob.VTB.account -= Bob.dad_birthday_cost;
    }
    if (month == Bob.mom_birthday_month) {
        Bob.VTB.account -= Bob.mom_birthday_cost;
    }
    if (month == Bob.sister_birthday_month) {
        Bob.VTB.account -= Bob.sister_birthday_cost;
    }
    if (month == Bob.best_friend_birthday_month) {
        Bob.VTB.account -= Bob.best_friend_birthday_cost;
    }
    if (month == 12) {
        Bob.VTB.account -= Bob.newyear_cost;
    }
}

void kate_holidays(const int month) {
    if (month == 2) {
        Kate.VTB.account -= Kate.feb23th_cost;
    }
    if (month == 3) {
        Kate.VTB.account -= Kate.mar8th_cost;
    }
    if (month == Kate.dad_birthday_month) {
        Kate.VTB.account -= Kate.dad_birthday_cost;
    }
    if (month == Kate.mom_birthday_month) {
        Kate.VTB.account -= Kate.mom_birthday_cost;
    }
    if (month == Kate.sister_birthday_month) {
        Kate.VTB.account -= Kate.sister_birthday_cost;
    }
    if (month == Kate.best_friend_birthday_month) {
        Kate.VTB.account -= Kate.best_friend_birthday_cost;
    }
    if (month == 12) {
        Kate.VTB.account -= Kate.newyear_cost;
    }
}

void steve_holidays(const int month) {
    if (month == 2) {
        Steve.VTB.account -= Steve.feb23th_cost;
    }
    if (month == 3) {
        Steve.VTB.account -= Steve.mar8th_cost;
    }
    if (month == Steve.dad_birthday_month) {
        Steve.VTB.account -= Steve.dad_birthday_cost;
    }
    if (month == Steve.mom_birthday_month) {
        Steve.VTB.account -= Steve.mom_birthday_cost;
    }
    if (month == Steve.sister_birthday_month) {
        Steve.VTB.account -= Steve.sister_birthday_cost;
    }
    if (month == Steve.best_friend_birthday_month) {
        Steve.VTB.account -= Steve.best_friend_birthday_cost;
    }
    if (month == 12) {
        Steve.VTB.account -= Steve.newyear_cost;
    }
}


void alice_wear(const int month) {
    Alice.wear.winter_new_wear_cost *= cash_interest_per_month;
    Alice.wear.winter_wear_repair_cost *= cash_interest_per_month;
    Alice.wear.winter_wear_wash_cost *= cash_interest_per_month;


    Alice.wear.spring_new_wear_cost *= cash_interest_per_month;
    Alice.wear.spring_wear_repair_cost *= cash_interest_per_month;
    Alice.wear.spring_wear_wash_cost *= cash_interest_per_month;


    Alice.wear.summer_new_wear_cost *= cash_interest_per_month;
    Alice.wear.summer_wear_repair_cost *= cash_interest_per_month;
    Alice.wear.summer_wear_wash_cost *= cash_interest_per_month;


    Alice.wear.autumn_new_wear_cost *= cash_interest_per_month;
    Alice.wear.autumn_wear_repair_cost *= cash_interest_per_month;
    Alice.wear.autumn_wear_wash_cost *= cash_interest_per_month;



    if (12 == month || month < 3) {
        Alice.wear.winter_wear_state -= 20;
    }
    if (2 < month && month < 6) {
        Alice.wear.spring_wear_state -= 20;
    }
    if (5 < month && month < 9) {
        Alice.wear.summer_wear_state -= 15;
    }
    if (8 < month && month < 12) {
        Alice.wear.autumn_wear_state -= 20;
    }


    if (Alice.wear.winter_wear_state < 30) {
        if (!Alice.wear.is_winter_wear_repaired) {
            Alice.VTB.account -= Alice.wear.winter_wear_repair_cost;
            Alice.wear.winter_wear_state += 50;
            Alice.wear.is_winter_wear_repaired = true;
        }
        else {
            Alice.VTB.account -= Alice.wear.winter_new_wear_cost;
            Alice.wear.winter_wear_state = 100;
            Alice.wear.is_winter_wear_repaired = false;
        }
    }
    if (Alice.wear.spring_wear_state < 30) {
        if (!Alice.wear.is_spring_wear_repaired) {
            Alice.VTB.account -= Alice.wear.spring_wear_repair_cost;
            Alice.wear.spring_wear_state += 50;
            Alice.wear.is_spring_wear_repaired = true;
        }
        else {
            Alice.VTB.account -= Alice.wear.spring_new_wear_cost;
            Alice.wear.spring_wear_state = 100;
            Alice.wear.is_spring_wear_repaired = false;
        }
    }
    if (Alice.wear.summer_wear_state < 30) {
        if (!Alice.wear.is_summer_wear_repaired) {
            Alice.VTB.account -= Alice.wear.summer_wear_repair_cost;
            Alice.wear.summer_wear_state += 50;
            Alice.wear.is_summer_wear_repaired = true;
        }
        else {
            Alice.VTB.account -= Alice.wear.summer_new_wear_cost;
            Alice.wear.summer_wear_state = 100;
            Alice.wear.is_summer_wear_repaired = false;
        }
    }
    if (Alice.wear.autumn_wear_state < 30) {
        if (!Alice.wear.is_autumn_wear_repaired) {
            Alice.VTB.account -= Alice.wear.autumn_wear_repair_cost;
            Alice.wear.autumn_wear_state += 50;
            Alice.wear.is_autumn_wear_repaired = true;
        }
        else {
            Alice.VTB.account -= Alice.wear.autumn_new_wear_cost;
            Alice.wear.autumn_wear_state = 100;
            Alice.wear.is_autumn_wear_repaired = false;
        }
    }
}

void bob_wear(const int month) {
    Bob.wear.winter_new_wear_cost *= cash_interest_per_month;
    Bob.wear.winter_wear_repair_cost *= cash_interest_per_month;
    Bob.wear.winter_wear_wash_cost *= cash_interest_per_month;


    Bob.wear.spring_new_wear_cost *= cash_interest_per_month;
    Bob.wear.spring_wear_repair_cost *= cash_interest_per_month;
    Bob.wear.spring_wear_wash_cost *= cash_interest_per_month;


    Bob.wear.summer_new_wear_cost *= cash_interest_per_month;
    Bob.wear.summer_wear_repair_cost *= cash_interest_per_month;
    Bob.wear.summer_wear_wash_cost *= cash_interest_per_month;


    Bob.wear.autumn_new_wear_cost *= cash_interest_per_month;
    Bob.wear.autumn_wear_repair_cost *= cash_interest_per_month;
    Bob.wear.autumn_wear_wash_cost *= cash_interest_per_month;



    if (12 == month || month < 3) {
        Bob.wear.winter_wear_state -= 20;
    }
    if (2 < month && month < 6) {
        Bob.wear.spring_wear_state -= 20;
    }
    if (5 < month && month < 9) {
        Bob.wear.summer_wear_state -= 15;
    }
    if (8 < month && month < 12) {
        Bob.wear.autumn_wear_state -= 20;
    }


    if (Bob.wear.winter_wear_state < 30) {
        if (!Bob.wear.is_winter_wear_repaired) {
            Bob.VTB.account -= Bob.wear.winter_wear_repair_cost;
            Bob.wear.winter_wear_state += 50;
            Bob.wear.is_winter_wear_repaired = true;
        }
        else {
            Bob.VTB.account -= Bob.wear.winter_new_wear_cost;
            Bob.wear.winter_wear_state = 100;
            Bob.wear.is_winter_wear_repaired = false;
        }
    }
    if (Bob.wear.spring_wear_state < 30) {
        if (!Bob.wear.is_spring_wear_repaired) {
            Bob.VTB.account -= Bob.wear.spring_wear_repair_cost;
            Bob.wear.spring_wear_state += 50;
            Bob.wear.is_spring_wear_repaired = true;
        }
        else {
            Bob.VTB.account -= Bob.wear.spring_new_wear_cost;
            Bob.wear.spring_wear_state = 100;
            Bob.wear.is_spring_wear_repaired = false;
        }
    }
    if (Bob.wear.summer_wear_state < 30) {
        if (!Bob.wear.is_summer_wear_repaired) {
            Bob.VTB.account -= Bob.wear.summer_wear_repair_cost;
            Bob.wear.summer_wear_state += 50;
            Bob.wear.is_summer_wear_repaired = true;
        }
        else {
            Bob.VTB.account -= Bob.wear.summer_new_wear_cost;
            Bob.wear.summer_wear_state = 100;
            Bob.wear.is_summer_wear_repaired = false;
        }
    }
    if (Bob.wear.autumn_wear_state < 30) {
        if (!Bob.wear.is_autumn_wear_repaired) {
            Bob.VTB.account -= Bob.wear.autumn_wear_repair_cost;
            Bob.wear.autumn_wear_state += 50;
            Bob.wear.is_autumn_wear_repaired = true;
        }
        else {
            Bob.VTB.account -= Bob.wear.autumn_new_wear_cost;
            Bob.wear.autumn_wear_state = 100;
            Bob.wear.is_autumn_wear_repaired = false;
        }
    }
}

void kate_wear(const int month) {
    Kate.wear.winter_new_wear_cost *= cash_interest_per_month;
    Kate.wear.winter_wear_repair_cost *= cash_interest_per_month;
    Kate.wear.winter_wear_wash_cost *= cash_interest_per_month;


    Kate.wear.spring_new_wear_cost *= cash_interest_per_month;
    Kate.wear.spring_wear_repair_cost *= cash_interest_per_month;
    Kate.wear.spring_wear_wash_cost *= cash_interest_per_month;


    Kate.wear.summer_new_wear_cost *= cash_interest_per_month;
    Kate.wear.summer_wear_repair_cost *= cash_interest_per_month;
    Kate.wear.summer_wear_wash_cost *= cash_interest_per_month;


    Kate.wear.autumn_new_wear_cost *= cash_interest_per_month;
    Kate.wear.autumn_wear_repair_cost *= cash_interest_per_month;
    Kate.wear.autumn_wear_wash_cost *= cash_interest_per_month;



    if (12 == month || month < 3) {
        Kate.wear.winter_wear_state -= 20;
    }
    if (2 < month && month < 6) {
        Kate.wear.spring_wear_state -= 20;
    }
    if (5 < month && month < 9) {
        Kate.wear.summer_wear_state -= 15;
    }
    if (8 < month && month < 12) {
        Kate.wear.autumn_wear_state -= 20;
    }


    if (Kate.wear.winter_wear_state < 30) {
        if (!Kate.wear.is_winter_wear_repaired) {
            Kate.VTB.account -= Kate.wear.winter_wear_repair_cost;
            Kate.wear.winter_wear_state += 50;
            Kate.wear.is_winter_wear_repaired = true;
        }
        else {
            Kate.VTB.account -= Kate.wear.winter_new_wear_cost;
            Kate.wear.winter_wear_state = 100;
            Kate.wear.is_winter_wear_repaired = false;
        }
    }
    if (Kate.wear.spring_wear_state < 30) {
        if (!Kate.wear.is_spring_wear_repaired) {
            Kate.VTB.account -= Kate.wear.spring_wear_repair_cost;
            Kate.wear.spring_wear_state += 50;
            Kate.wear.is_spring_wear_repaired = true;
        }
        else {
            Kate.VTB.account -= Kate.wear.spring_new_wear_cost;
            Kate.wear.spring_wear_state = 100;
            Kate.wear.is_spring_wear_repaired = false;
        }
    }
    if (Kate.wear.summer_wear_state < 30) {
        if (!Kate.wear.is_summer_wear_repaired) {
            Kate.VTB.account -= Kate.wear.summer_wear_repair_cost;
            Kate.wear.summer_wear_state += 50;
            Kate.wear.is_summer_wear_repaired = true;
        }
        else {
            Kate.VTB.account -= Kate.wear.summer_new_wear_cost;
            Kate.wear.summer_wear_state = 100;
            Kate.wear.is_summer_wear_repaired = false;
        }
    }
    if (Kate.wear.autumn_wear_state < 30) {
        if (!Kate.wear.is_autumn_wear_repaired) {
            Kate.VTB.account -= Kate.wear.autumn_wear_repair_cost;
            Kate.wear.autumn_wear_state += 50;
            Kate.wear.is_autumn_wear_repaired = true;
        }
        else {
            Kate.VTB.account -= Kate.wear.autumn_new_wear_cost;
            Kate.wear.autumn_wear_state = 100;
            Kate.wear.is_autumn_wear_repaired = false;
        }
    }
}

void steve_wear(const int month) {
    Steve.wear.winter_new_wear_cost *= cash_interest_per_month;
    Steve.wear.winter_wear_repair_cost *= cash_interest_per_month;
    Steve.wear.winter_wear_wash_cost *= cash_interest_per_month;


    Steve.wear.spring_new_wear_cost *= cash_interest_per_month;
    Steve.wear.spring_wear_repair_cost *= cash_interest_per_month;
    Steve.wear.spring_wear_wash_cost *= cash_interest_per_month;


    Steve.wear.summer_new_wear_cost *= cash_interest_per_month;
    Steve.wear.summer_wear_repair_cost *= cash_interest_per_month;
    Steve.wear.summer_wear_wash_cost *= cash_interest_per_month;


    Steve.wear.autumn_new_wear_cost *= cash_interest_per_month;
    Steve.wear.autumn_wear_repair_cost *= cash_interest_per_month;
    Steve.wear.autumn_wear_wash_cost *= cash_interest_per_month;



    if (12 == month || month < 3) {
        Steve.wear.winter_wear_state -= 20;
    }
    if (2 < month && month < 6) {
        Steve.wear.spring_wear_state -= 20;
    }
    if (5 < month && month < 9) {
        Steve.wear.summer_wear_state -= 15;
    }
    if (8 < month && month < 12) {
        Steve.wear.autumn_wear_state -= 20;
    }


    if (Steve.wear.winter_wear_state < 30) {
        if (!Steve.wear.is_winter_wear_repaired) {
            Steve.VTB.account -= Steve.wear.winter_wear_repair_cost;
            Steve.wear.winter_wear_state += 50;
            Steve.wear.is_winter_wear_repaired = true;
        }
        else {
            Steve.VTB.account -= Steve.wear.winter_new_wear_cost;
            Steve.wear.winter_wear_state = 100;
            Steve.wear.is_winter_wear_repaired = false;
        }
    }
    if (Steve.wear.spring_wear_state < 30) {
        if (!Steve.wear.is_spring_wear_repaired) {
            Steve.VTB.account -= Steve.wear.spring_wear_repair_cost;
            Steve.wear.spring_wear_state += 50;
            Steve.wear.is_spring_wear_repaired = true;
        }
        else {
            Steve.VTB.account -= Steve.wear.spring_new_wear_cost;
            Steve.wear.spring_wear_state = 100;
            Steve.wear.is_spring_wear_repaired = false;
        }
    }
    if (Steve.wear.summer_wear_state < 30) {
        if (!Steve.wear.is_summer_wear_repaired) {
            Steve.VTB.account -= Steve.wear.summer_wear_repair_cost;
            Steve.wear.summer_wear_state += 50;
            Steve.wear.is_summer_wear_repaired = true;
        }
        else {
            Steve.VTB.account -= Steve.wear.summer_new_wear_cost;
            Steve.wear.summer_wear_state = 100;
            Steve.wear.is_summer_wear_repaired = false;
        }
    }
    if (Steve.wear.autumn_wear_state < 30) {
        if (!Steve.wear.is_autumn_wear_repaired) {
            Steve.VTB.account -= Steve.wear.autumn_wear_repair_cost;
            Steve.wear.autumn_wear_state += 50;
            Steve.wear.is_autumn_wear_repaired = true;
        }
        else {
            Steve.VTB.account -= Steve.wear.autumn_new_wear_cost;
            Steve.wear.autumn_wear_state = 100;
            Steve.wear.is_autumn_wear_repaired = false;
        }
    }
}


void alice_init() {
    Alice.name = "Alice";


    Alice.VTB.account = 100000;
    Alice.VTB.deposit_interest = 14.5 / 12.0 / 100.0;
    Alice.capital = 0;
    Alice.poket_money_target = 10000;
    Alice.salary = 180'000;
    Alice.food = 20000;


    Alice.VTB.car_credit.summ = 0;
    Alice.VTB.car_credit.min_credit = 10'000;
    Alice.VTB.car_credit.max_credit = 200'000;
    Alice.VTB.car_credit.interest_rate_per_month = 10.0 / 12.0 / 100.0;
    Alice.VTB.car_credit.duration = 0;
    Alice.VTB.car_credit.payment_per_month = 0;


    Alice.VTB.apartment_credit.summ = 0;
    Alice.VTB.apartment_credit.min_credit = 50'000;
    Alice.VTB.apartment_credit.max_credit = 500'000;
    Alice.VTB.apartment_credit.interest_rate_per_month = 18.0 / 12.0 / 100.0;
    Alice.VTB.apartment_credit.duration = 0;
    Alice.VTB.apartment_credit.payment_per_month = 0;


    Alice.apartment.value = 8000'000;
    Alice.apartment.payment = 30'000;
    Alice.apartment.rent = 70'000;


    Alice.car.value = 500'000;
    Alice.car.power = 0;
    Alice.taxi.kilometr_cost = 20;


    Alice.pet.feed = 2000;


    Alice.wear.autumn_new_wear_cost = 10000;
    Alice.wear.winter_new_wear_cost = 15000;
    Alice.wear.spring_new_wear_cost = 12000;
    Alice.wear.summer_new_wear_cost = 7000;


    Alice.wear.autumn_wear_state = 100;
    Alice.wear.winter_wear_state = 80;
    Alice.wear.spring_wear_state = 60;
    Alice.wear.summer_wear_state = 40;


    Alice.wear.is_autumn_wear_repaired = false;
    Alice.wear.is_winter_wear_repaired = false;
    Alice.wear.is_spring_wear_repaired = true;
    Alice.wear.is_summer_wear_repaired = false;


    Alice.wear.autumn_wear_wash_cost = 5000;
    Alice.wear.winter_wear_wash_cost = 5000;
    Alice.wear.spring_wear_wash_cost = 4000;
    Alice.wear.summer_wear_wash_cost = 2000;


    Alice.wear.autumn_wear_repair_cost = 5000;
    Alice.wear.winter_wear_repair_cost = 6000;
    Alice.wear.spring_wear_repair_cost = 4000;
    Alice.wear.summer_wear_repair_cost = 2000;


    Alice.feb23th_cost = 2000;
    Alice.mar8th_cost = 3000;
    Alice.newyear_cost = 7000;
    Alice.dad_birthday_cost = 5000;
    Alice.mom_birthday_cost = 4000;
    Alice.sister_birthday_cost = 3000;
    Alice.best_friend_birthday_cost = 2500;
    Alice.partner_birthday_cost = 4500;


    Alice.dad_birthday_month = 4;
    Alice.mom_birthday_month = 7;
    Alice.sister_birthday_month = 9;
    Alice.best_friend_birthday_month = 5;
    Alice.partner_birthday_month = 2;
}

void bob_init() {
    Bob.name = "Bob";


    Bob.VTB.account = 100000;
    Bob.VTB.deposit_interest = 14.5 / 12.0 / 100.0;
    Bob.capital = 0;
    Bob.poket_money_target = 20000;
    Bob.salary = 180'000;
    Bob.food = 30000;


    Bob.VTB.car_credit.summ = 0;
    Bob.VTB.car_credit.min_credit = 10'000;
    Bob.VTB.car_credit.max_credit = 300'000;
    Bob.VTB.car_credit.interest_rate_per_month = 10.0 / 12.0 / 100.0;
    Bob.VTB.car_credit.duration = 0;
    Bob.VTB.car_credit.payment_per_month = 0;


    Bob.VTB.apartment_credit.summ = 0;
    Bob.VTB.apartment_credit.min_credit = 50'000;
    Bob.VTB.apartment_credit.max_credit = 700'000;
    Bob.VTB.apartment_credit.interest_rate_per_month = 18.0 / 12.0 / 100.0;
    Bob.VTB.apartment_credit.duration = 0;
    Bob.VTB.apartment_credit.payment_per_month = 0;


    Bob.apartment.value = 8'000'000;
    Bob.apartment.payment = 45'000;
    Bob.apartment.rent = 100'000;


    Bob.car.value = 700'000;
    Bob.car.power = 0;
    Bob.taxi.kilometr_cost = 30;


    Bob.pet.feed = 6000;


    Bob.wear.autumn_new_wear_cost = 15000;
    Bob.wear.winter_new_wear_cost = 20000;
    Bob.wear.spring_new_wear_cost = 17000;
    Bob.wear.summer_new_wear_cost = 12000;


    Bob.wear.autumn_wear_state = 100;
    Bob.wear.winter_wear_state = 100;
    Bob.wear.spring_wear_state = 100;
    Bob.wear.summer_wear_state = 100;


    Bob.wear.is_autumn_wear_repaired = false;
    Bob.wear.is_winter_wear_repaired = false;
    Bob.wear.is_spring_wear_repaired = false;
    Bob.wear.is_summer_wear_repaired = false;


    Bob.wear.autumn_wear_wash_cost = 5000;
    Bob.wear.winter_wear_wash_cost = 5000;
    Bob.wear.spring_wear_wash_cost = 4000;
    Bob.wear.summer_wear_wash_cost = 3000;


    Bob.wear.autumn_wear_repair_cost = 8000;
    Bob.wear.winter_wear_repair_cost = 9000;
    Bob.wear.spring_wear_repair_cost = 7000;
    Bob.wear.summer_wear_repair_cost = 3000;


    Bob.feb23th_cost = 3000;
    Bob.mar8th_cost = 4000;
    Bob.newyear_cost = 8000;
    Bob.dad_birthday_cost = 6000;
    Bob.mom_birthday_cost = 6000;
    Bob.sister_birthday_cost = 5000;
    Bob.best_friend_birthday_cost = 3000;
    Bob.partner_birthday_cost = 7000;


    Bob.dad_birthday_month = 4;
    Bob.mom_birthday_month = 7;
    Bob.sister_birthday_month = 9;
    Bob.best_friend_birthday_month = 5;
    Bob.partner_birthday_month = 2;
}

void kate_init() {
    Kate.name = "Kate";


    Kate.VTB.account = 100000;
    Kate.VTB.deposit_interest = 14.5 / 12.0 / 100.0;
    Kate.capital = 0;
    Kate.poket_money_target = 10000;
    Kate.salary = 180'000;
    Kate.food = 15000;


    Kate.VTB.car_credit.summ = 0;
    Kate.VTB.car_credit.min_credit = 10'000;
    Kate.VTB.car_credit.max_credit = 150'000;
    Kate.VTB.car_credit.interest_rate_per_month = 10.0 / 12.0 / 100.0;
    Kate.VTB.car_credit.duration = 0;
    Kate.VTB.car_credit.payment_per_month = 0;


    Kate.VTB.apartment_credit.summ = 0;
    Kate.VTB.apartment_credit.min_credit = 50'000;
    Kate.VTB.apartment_credit.max_credit = 400'000;
    Kate.VTB.apartment_credit.interest_rate_per_month = 18.0 / 12.0 / 100.0;
    Kate.VTB.apartment_credit.duration = 0;
    Kate.VTB.apartment_credit.payment_per_month = 0;


    Kate.apartment.value = 3'000'000;
    Kate.apartment.payment = 25'000;
    Kate.apartment.rent = 60'000;


    Kate.car.value = 300'000;
    Kate.car.power = 0;
    Kate.taxi.kilometr_cost = 15;


    Kate.pet.feed = 0;


    Kate.wear.autumn_new_wear_cost = 7000;
    Kate.wear.winter_new_wear_cost = 10000;
    Kate.wear.spring_new_wear_cost = 10000;
    Kate.wear.summer_new_wear_cost = 5000;


    Kate.wear.autumn_wear_state = 60;
    Kate.wear.winter_wear_state = 60;
    Kate.wear.spring_wear_state = 60;
    Kate.wear.summer_wear_state = 40;


    Kate.wear.is_autumn_wear_repaired = false;
    Kate.wear.is_winter_wear_repaired = false;
    Kate.wear.is_spring_wear_repaired = true;
    Kate.wear.is_summer_wear_repaired = false;


    Kate.wear.autumn_wear_wash_cost = 4000;
    Kate.wear.winter_wear_wash_cost = 4000;
    Kate.wear.spring_wear_wash_cost = 3000;
    Kate.wear.summer_wear_wash_cost = 1000;


    Kate.wear.autumn_wear_repair_cost = 4000;
    Kate.wear.winter_wear_repair_cost = 5000;
    Kate.wear.spring_wear_repair_cost = 3000;
    Kate.wear.summer_wear_repair_cost = 1000;


    Kate.feb23th_cost = 1500;
    Kate.mar8th_cost = 2000;
    Kate.newyear_cost = 5000;
    Kate.dad_birthday_cost = 4000;
    Kate.mom_birthday_cost = 3000;
    Kate.sister_birthday_cost = 2000;
    Kate.best_friend_birthday_cost = 2000;
    Kate.partner_birthday_cost = 4000;


    Kate.dad_birthday_month = 4;
    Kate.mom_birthday_month = 7;
    Kate.sister_birthday_month = 9;
    Kate.best_friend_birthday_month = 5;
    Kate.partner_birthday_month = 2;
}

void steve_init() {
    Steve.name = "Steve";


    Steve.VTB.account = 100000;
    Steve.VTB.deposit_interest = 14.5 / 12.0 / 100.0;
    Steve.capital = 0;
    Steve.poket_money_target = 10000;
    Steve.salary = 180'000;
    Steve.food = 15000;


    Steve.VTB.car_credit.summ = 0;
    Steve.VTB.car_credit.min_credit = 10'000;
    Steve.VTB.car_credit.max_credit = 300'000;
    Steve.VTB.car_credit.interest_rate_per_month = 10.0 / 12.0 / 100.0;
    Steve.VTB.car_credit.duration = 0;
    Steve.VTB.car_credit.payment_per_month = 0;


    Steve.VTB.apartment_credit.summ = 0;
    Steve.VTB.apartment_credit.min_credit = 50'000;
    Steve.VTB.apartment_credit.max_credit = 700'000;
    Steve.VTB.apartment_credit.interest_rate_per_month = 18.0 / 12.0 / 100.0;
    Steve.VTB.apartment_credit.duration = 0;
    Steve.VTB.apartment_credit.payment_per_month = 0;


    Steve.apartment.value = 80000'000;
    Steve.apartment.payment = 20'000;
    Steve.apartment.rent = 50'000;


    Steve.car.value = 300'000;
    Steve.car.power = 0;
    Steve.taxi.kilometr_cost = 20;


    Steve.pet.feed = 2000;


    Steve.wear.autumn_new_wear_cost = 8000;
    Steve.wear.winter_new_wear_cost = 12000;
    Steve.wear.spring_new_wear_cost = 10000;
    Steve.wear.summer_new_wear_cost = 5000;


    Steve.wear.autumn_wear_state = 100;
    Steve.wear.winter_wear_state = 80;
    Steve.wear.spring_wear_state = 60;
    Steve.wear.summer_wear_state = 40;


    Steve.wear.is_autumn_wear_repaired = false;
    Steve.wear.is_winter_wear_repaired = false;
    Steve.wear.is_spring_wear_repaired = false;
    Steve.wear.is_summer_wear_repaired = false;


    Steve.wear.autumn_wear_wash_cost = 5000;
    Steve.wear.winter_wear_wash_cost = 5000;
    Steve.wear.spring_wear_wash_cost = 4000;
    Steve.wear.summer_wear_wash_cost = 2000;


    Steve.wear.autumn_wear_repair_cost = 5000;
    Steve.wear.winter_wear_repair_cost = 6000;
    Steve.wear.spring_wear_repair_cost = 4000;
    Steve.wear.summer_wear_repair_cost = 2000;


    Steve.feb23th_cost = 2000;
    Steve.mar8th_cost = 3000;
    Steve.newyear_cost = 7000;
    Steve.dad_birthday_cost = 5000;
    Steve.mom_birthday_cost = 4000;
    Steve.sister_birthday_cost = 3000;
    Steve.best_friend_birthday_cost = 2500;
    Steve.partner_birthday_cost = 4500;


    Steve.dad_birthday_month = 4;
    Steve.mom_birthday_month = 7;
    Steve.sister_birthday_month = 9;
    Steve.best_friend_birthday_month = 5;
    Steve.partner_birthday_month = 2;
}

void print_results() {
    printf("\n\n");
    printf("Global values :\n");
    printf("Cash interest:        %.1f%%\n", (cash_interest_per_month - 1) * 12 * 100);
    printf("Apartment interest:   %.1f%%\n", (apartment_interest_per_month - 1) * 12 * 100);

    printf("\n\n");
    printf("Person results :\n\n");

    printf("%s:\n", Alice.name.c_str());
    printf("  Has car:             %s\n", Alice.car.gas_value_per_liter != 0 ? "Yes" : "No");
    printf("  Has apartment:       %s\n", Alice.apartment.rent == 0 ? "Yes" : "No");
    printf("  Bank account:        %ld RUB\n", Alice.VTB.account);
    printf("  Salary:              %ld RUB\n", Alice.salary);
    printf("  Capital:             %ld RUB\n", Alice.capital);
    printf("  Pocket money target: %ld RUB\n", Alice.poket_money_target);
    printf("  Food:                %ld RUB\n", Alice.food);
    printf("  Pet feed:            %ld RUB\n", Alice.pet.feed);
    printf("  Car value:           %ld RUB\n", Alice.car.value);
    printf("  Car power:           %d HP\n", Alice.car.power);
    printf("  Car run:             %ld km\n", Alice.car.run);
    printf("  Gas price:           %ld RUB/liter\n", Alice.car.gas_value_per_liter);
    printf("  Fuel consumption:    %.2f L/100km\n", Alice.car.fuel_consumption_per_liter * 100);
    printf("  Taxi cost:           %ld RUB/km\n", Alice.taxi.kilometr_cost);
    printf("  Apartment value:     %ld RUB\n", Alice.apartment.value);
    printf("  Apartment payment:   %ld RUB/month\n", Alice.apartment.payment);
    printf("  Apartment rent:      %ld RUB/month\n", Alice.apartment.rent);
    printf("  Car credit:          %ld RUB\n", Alice.VTB.car_credit.summ);
    printf("  Apartment credit:    %ld RUB\n", Alice.VTB.apartment_credit.summ);
    printf("  Winter wear state:   %d%%\n", Alice.wear.winter_wear_state);
    printf("  Spring wear state:   %d%%\n", Alice.wear.spring_wear_state);
    printf("  Summer wear state:   %d%%\n", Alice.wear.summer_wear_state);
    printf("  Autumn wear state:   %d%%\n", Alice.wear.autumn_wear_state);
    printf("\n");


    printf("%s:\n", Bob.name.c_str());
    printf("  Has car:             %s\n", Bob.car.gas_value_per_liter != 0 ? "Yes" : "No");
    printf("  Has apartment:       %s\n", Bob.apartment.rent == 0 ? "Yes" : "No");
    printf("  Bank account:        %ld RUB\n", Bob.VTB.account);
    printf("  Salary:              %ld RUB\n", Bob.salary);
    printf("  Capital:             %ld RUB\n", Bob.capital);
    printf("  Pocket money target: %ld RUB\n", Bob.poket_money_target);
    printf("  Food:                %ld RUB\n", Bob.food);
    printf("  Pet feed:            %ld RUB\n", Bob.pet.feed);
    printf("  Car value:           %ld RUB\n", Bob.car.value);
    printf("  Car power:           %d HP\n", Bob.car.power);
    printf("  Car run:             %ld km\n", Bob.car.run);
    printf("  Gas price:           %ld RUB/liter\n", Bob.car.gas_value_per_liter);
    printf("  Fuel consumption:    %.2f L/100km\n", Bob.car.fuel_consumption_per_liter * 100);
    printf("  Taxi cost:           %ld RUB/km\n", Bob.taxi.kilometr_cost);
    printf("  Apartment value:     %ld RUB\n", Bob.apartment.value);
    printf("  Apartment payment:   %ld RUB/month\n", Bob.apartment.payment);
    printf("  Apartment rent:      %ld RUB/month\n", Bob.apartment.rent);
    printf("  Car credit:          %ld RUB\n", Bob.VTB.car_credit.summ);
    printf("  Apartment credit:    %ld RUB\n", Bob.VTB.apartment_credit.summ);
    printf("  Winter wear state:   %d%%\n", Bob.wear.winter_wear_state);
    printf("  Spring wear state:   %d%%\n", Bob.wear.spring_wear_state);
    printf("  Summer wear state:   %d%%\n", Bob.wear.summer_wear_state);
    printf("  Autumn wear state:   %d%%\n", Bob.wear.autumn_wear_state);
    printf("\n");

    printf("%s:\n", Kate.name.c_str());
    printf("  Has car:             %s\n", Kate.car.gas_value_per_liter != 0 ? "Yes" : "No");
    printf("  Has apartment:       %s\n", Kate.apartment.rent == 0 ? "Yes" : "No");
    printf("  Bank account:        %ld RUB\n", Kate.VTB.account);
    printf("  Salary:              %ld RUB\n", Kate.salary);
    printf("  Capital:             %ld RUB\n", Kate.capital);
    printf("  Pocket money target: %ld RUB\n", Kate.poket_money_target);
    printf("  Food:                %ld RUB\n", Kate.food);
    printf("  Pet feed:            %ld RUB\n", Kate.pet.feed);
    printf("  Car value:           %ld RUB\n", Kate.car.value);
    printf("  Car power:           %d HP\n", Kate.car.power);
    printf("  Car run:             %ld km\n", Kate.car.run);
    printf("  Gas price:           %ld RUB/liter\n", Kate.car.gas_value_per_liter);
    printf("  Fuel consumption:    %.2f L/100km\n", Kate.car.fuel_consumption_per_liter * 100);
    printf("  Taxi cost:           %ld RUB/km\n", Kate.taxi.kilometr_cost);
    printf("  Apartment value:     %ld RUB\n", Kate.apartment.value);
    printf("  Apartment payment:   %ld RUB/month\n", Kate.apartment.payment);
    printf("  Apartment rent:      %ld RUB/month\n", Kate.apartment.rent);
    printf("  Car credit:          %ld RUB\n", Kate.VTB.car_credit.summ);
    printf("  Apartment credit:    %ld RUB\n", Kate.VTB.apartment_credit.summ);
    printf("  Winter wear state:   %d%%\n", Kate.wear.winter_wear_state);
    printf("  Spring wear state:   %d%%\n", Kate.wear.spring_wear_state);
    printf("  Summer wear state:   %d%%\n", Kate.wear.summer_wear_state);
    printf("  Autumn wear state:   %d%%\n", Kate.wear.autumn_wear_state);
    printf("\n");

    printf("%s:\n", Steve.name.c_str());
    printf("  Has car:             %s\n", Steve.car.gas_value_per_liter != 0 ? "Yes" : "No");
    printf("  Has apartment:       %s\n", Steve.apartment.rent == 0 ? "Yes" : "No");
    printf("  Bank account:        %ld RUB\n", Steve.VTB.account);
    printf("  Salary:              %ld RUB\n", Steve.salary);
    printf("  Capital:             %ld RUB\n", Steve.capital);
    printf("  Pocket money target: %ld RUB\n", Steve.poket_money_target);
    printf("  Food:                %ld RUB\n", Steve.food);
    printf("  Pet feed:            %ld RUB\n", Steve.pet.feed);
    printf("  Car value:           %ld RUB\n", Steve.car.value);
    printf("  Car power:           %d HP\n", Steve.car.power);
    printf("  Car run:             %ld km\n", Steve.car.run);
    printf("  Gas price:           %ld RUB/liter\n", Steve.car.gas_value_per_liter);
    printf("  Fuel consumption:    %.2f L/100km\n", Steve.car.fuel_consumption_per_liter * 100);
    printf("  Taxi cost:           %ld RUB/km\n", Steve.taxi.kilometr_cost);
    printf("  Apartment value:     %ld RUB\n", Steve.apartment.value);
    printf("  Apartment payment:   %ld RUB/month\n", Steve.apartment.payment);
    printf("  Apartment rent:      %ld RUB/month\n", Steve.apartment.rent);
    printf("  Car credit:          %ld RUB\n", Steve.VTB.car_credit.summ);
    printf("  Apartment credit:    %ld RUB\n", Steve.VTB.apartment_credit.summ);
    printf("  Winter wear state:   %d%%\n", Steve.wear.winter_wear_state);
    printf("  Spring wear state:   %d%%\n", Steve.wear.spring_wear_state);
    printf("  Summer wear state:   %d%%\n", Steve.wear.summer_wear_state);
    printf("  Autumn wear state:   %d%%\n", Steve.wear.autumn_wear_state);
    printf("\n");
}

void simulation() {
    int month = 2;
    int year = 2026;

    while (!((month == 3) && (year == 2028))) {
        
        alice_pet();
        alice_food();
        alice_holidays(month);
        alice_moving(month, year);
        alice_take_car_credit(month, year);
        alice_buy_car(month, year);
        alice_take_apartment_credit(month, year);
        alice_buy_apartment(month, year);
        alice_apartment(month, year);
        alice_bank();
        alice_salary(month, year);
        alice_wear(month);

        bob_pet();
        bob_food();
        bob_holidays(month);
        bob_moving(month, year);
        bob_take_car_credit(month, year);
        bob_buy_car(month, year);
        bob_take_apartment_credit(month, year);
        bob_buy_apartment(month, year);
        bob_apartment(month, year);
        bob_bank();
        bob_salary(month, year);
        bob_wear(month);

        kate_pet();
        kate_food();
        kate_holidays(month);
        kate_moving(month, year);
        kate_take_car_credit(month, year);
        kate_buy_car(month, year);
        kate_take_apartment_credit(month, year);
        kate_buy_apartment(month, year);
        kate_apartment(month, year);
        kate_bank();
        kate_salary(month, year);
        kate_wear(month);

        steve_pet();
        steve_food();
        steve_holidays(month);
        steve_moving(month, year);
        steve_take_car_credit(month, year);
        steve_buy_car(month, year);
        steve_take_apartment_credit(month, year);
        steve_buy_apartment(month, year);
        steve_apartment(month, year);
        steve_bank();
        steve_salary(month, year);
        steve_wear(month);


        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}


int main() { 
    alice_init();
    bob_init();
    kate_init();
    steve_init();

    simulation();
 
    print_results();
}
