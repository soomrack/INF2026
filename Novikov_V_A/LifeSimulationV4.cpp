#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using RUB = long long int;
using USD = long long int;

using KM = long int;
using Years = int;

using Percent = float;

const float inflation_rate = 0.04;


struct Bank {
    RUB account;
    RUB deposite;
    USD account_usd;
    float rate_usd_rub;

    Percent deposite_interest;
    Percent credit_interest;

    RUB credit;
    RUB credit_limit;
    RUB payment;

    RUB total_spent;
    RUB total_earned;
};

struct Car {
    RUB value;
    RUB credit;
    RUB credit_payment;
    Percent credit_interest;

    RUB gas_month;
    RUB gas_price;

    RUB winter_tires;
    RUB summer_tires;
    RUB tire_change;

    RUB season_service;
    RUB insurance;

    RUB random_repair_min;
    RUB random_repair_max;
    RUB accumulated_repair;

    Years age;
    KM mileage_year;
    int months_since_service;

    RUB tax;
};

struct Housing {
    RUB utilities;
    RUB internet;
    RUB repairs;
    RUB furniture;
    RUB appliances;
    RUB total_spent;

    RUB rent; // для квартиры

    RUB value;
    RUB heating;
    RUB garden;
    RUB tax;
    int year_bought;
};

struct Garage {
    RUB rent;
    RUB electricity;
    RUB repairs;
    RUB total_spent;
};

struct Person {
    RUB salary;
    RUB food;
    RUB total_taxes_paid;
    RUB income_tax;
    Housing housing;
};

struct RickOnly {
    Bank tbank;
    Car bmw_x3;
    Car bmw_x5;
    RUB taxi_income_per_hour;
    int taxi_hours_per_week;
    RUB taxi_money;
    RUB taxi_tips;
    int taxi_clients;
    RUB taxi_expenses;
    Garage garage;
    bool has_house;
};

struct CliffOnly {
    Bank vtb;
    RUB stunt_income_per_job;
    int stunt_jobs_per_month;
    RUB stunt_money;
    RUB stunt_bonuses;
    int stunt_injuries;
    RUB stunt_medical_expenses;
    RUB dog_food;
    RUB dog_vet;
    RUB dog_total_spent;
};

struct Person rick_main;
struct RickOnly rick;

struct Person cliff_main;
struct CliffOnly cliff;


void rick_init()
{
    // BANK
    rick.tbank.account = 0;
    rick_main.salary = 300'000;
    rick.tbank.account_usd = 0;
    rick.tbank.rate_usd_rub = 80.0;
    rick.tbank.deposite = 100'000;
    rick.tbank.deposite_interest = 8.0;
    rick.tbank.credit = 1'000'000;
    rick.tbank.credit_limit = 5'000'000;
    rick.tbank.credit_interest = 21.0;
    rick.tbank.total_spent = 0;
    rick.tbank.total_earned = 0;
    rick_main.total_taxes_paid = 0;
    rick_main.income_tax = 0.13;

    // FOOD
    rick_main.food = 30'000;

    // TAXI JOB
    rick.taxi_income_per_hour = 500;
    rick.taxi_hours_per_week = 15;
    rick.taxi_money = 0;
    rick.taxi_tips = 0;
    rick.taxi_clients = 0;
    rick.taxi_expenses = 0;
    
    // HOUSING
    rick_main.housing.rent = 35'000;
    rick_main.housing.utilities = 7'000;
    rick_main.housing.internet = 1'000;
    rick_main.housing.repairs = 0;
    rick_main.housing.furniture = 0;
    rick_main.housing.appliances = 0;
    rick_main.housing.total_spent = 0;

    rick_main.housing.value = 0;  // для дома
    rick_main.housing.heating = 0;
    rick_main.housing.garden = 0;
    rick_main.housing.tax = 0;
    rick_main.housing.year_bought = 0;

    rick.has_house = false;

    // GARAGE
    rick.garage.rent = 5'000;
    rick.garage.electricity = 500;
    rick.garage.repairs = 0;
    rick.garage.total_spent = 0;

    // CARS
    rick.bmw_x3.value = 4'500'000;
    rick.bmw_x3.credit = 0;
    rick.bmw_x3.credit_payment = 0;
    rick.bmw_x3.credit_interest = 0;

    rick.bmw_x3.gas_month = 18'000;
    rick.bmw_x3.gas_price = 55.0;

    rick.bmw_x3.winter_tires = 100'000;
    rick.bmw_x3.summer_tires = 90'000;
    rick.bmw_x3.tire_change = 5'000;

    rick.bmw_x3.season_service = 25'000;
    rick.bmw_x3.insurance = 90'000;

    rick.bmw_x3.random_repair_min = 5'000;
    rick.bmw_x3.random_repair_max = 60'000;
    rick.bmw_x3.accumulated_repair = 0;

    rick.bmw_x3.age = 4;
    rick.bmw_x3.mileage_year = 15'000;
    rick.bmw_x3.months_since_service = 0;

    rick.bmw_x3.tax = 7'500;


    rick.bmw_x5.value = 8'500'000;
    rick.bmw_x5.credit = 5'000'000;
    rick.bmw_x5.credit_payment = 95'000;
    rick.bmw_x5.credit_interest = 18.5;

    rick.bmw_x5.gas_month = 30'000;
    rick.bmw_x5.gas_price = 55.0;

    rick.bmw_x5.winter_tires = 200'000;
    rick.bmw_x5.summer_tires = 180'000;
    rick.bmw_x5.tire_change = 8'000;

    rick.bmw_x5.season_service = 50'000;
    rick.bmw_x5.insurance = 200'000;

    rick.bmw_x5.random_repair_min = 20'000;
    rick.bmw_x5.random_repair_max = 250'000;
    rick.bmw_x5.accumulated_repair = 0;

    rick.bmw_x5.age = 1;
    rick.bmw_x5.mileage_year = 25'000;
    rick.bmw_x5.months_since_service = 0;

    rick.bmw_x5.tax = 45'000;
}


void cliff_init()
{
    // BANK 
    cliff.vtb.account = 5'000;
    cliff_main.salary = 180'000;
    cliff.vtb.account_usd = 0;
    cliff.vtb.rate_usd_rub = 80.0;
    cliff.vtb.deposite = 20'000;
    cliff.vtb.deposite_interest = 8.0;
    cliff.vtb.credit = 300'000;
    cliff.vtb.credit_limit = 1'000'000;
    cliff.vtb.credit_interest = 19.0;
    cliff.vtb.total_spent = 0;
    cliff.vtb.total_earned = 0;
    cliff_main.total_taxes_paid = 0;
    cliff_main.income_tax = 0.13;

    // FOOD
    cliff_main.food = 35'000;

    // STUNT WORK
    cliff.stunt_income_per_job = 20'000;
    cliff.stunt_jobs_per_month = 5;
    cliff.stunt_money = 0;
    cliff.stunt_bonuses = 0;
    cliff.stunt_injuries = 0;
    cliff.stunt_medical_expenses = 0;

    // DOG
    cliff.dog_food = 6'000;
    cliff.dog_vet = 0;
    cliff.dog_total_spent = 0;

    // HOUSING
    cliff_main.housing.rent = 15'000;
    cliff_main.housing.utilities = 4'000;
    cliff_main.housing.internet = 800;
    cliff_main.housing.repairs = 0;
    cliff_main.housing.furniture = 0;
    cliff_main.housing.appliances = 0;
    cliff_main.housing.total_spent = 0;
}


// RICK'S LIFE
void rick_salary(const int month, const int year)
{
    if (month == 1 and year == 2027) {
        rick_main.salary *= 1.5;
    }
    if (month == 1 and year > 2027) {
        rick_main.salary = rick_main.salary * (1.0 + inflation_rate * 0.9);
    }

    RUB salary_without_tax = rick_main.salary;

    if (month == 12) {
        salary_without_tax += rick_main.salary;
    }

    RUB income_tax = salary_without_tax * 0.13;

    rick.tbank.account += salary_without_tax - income_tax;
    rick.tbank.total_earned += salary_without_tax;
    rick_main.total_taxes_paid += income_tax;
}


void rick_taxi_work(const int month, const int year)
{
    int hours_this_month = rick.taxi_hours_per_week * 4;

    RUB base_income = rick.taxi_income_per_hour * hours_this_month;

    int tips_percent = 10 + (rand() % 21);
    RUB tips = base_income * tips_percent / 100;

    int clients = hours_this_month * 2;

    RUB expenses = 3000 + (rand() % 3000);

    RUB total_income = base_income + tips;
    RUB clean_income = total_income - expenses;


    RUB taxi_tax = clean_income * 0.06;

    rick.taxi_money += base_income;
    rick.taxi_tips += tips;
    rick.taxi_clients += clients;
    rick.taxi_expenses += expenses;
    rick_main.total_taxes_paid += taxi_tax;

    rick.tbank.account += clean_income - taxi_tax;
    rick.tbank.total_earned += clean_income;


    int event_chance = rand() % 100;
    if (event_chance < 40) {
        int taxi_event = (month * 7 + year * 3) % 20;

        switch (taxi_event) {
        case 0:
            printf("[TAXI]: Flat tire in a pothole. Tire service -3,000 RUB\n");
            rick.tbank.account -= 3000;
            rick.taxi_expenses += 3000;
            rick.tbank.total_spent += 3000;
            break;

        case 1:
            printf("[TAXI]: A generous customer left a big tip! +5000 RUB\n");
            rick.tbank.account += 5000;
            rick.taxi_tips += 5000;
            rick.tbank.total_earned += 5000;
            break;

        case 2:
            printf("[TAXI]: The fine for illegal parking -2500 RUB\n");
            rick.tbank.account -= 2500;
            rick.taxi_expenses += 2500;
            rick.tbank.total_spent += 2500;
            break;

        case 3:
            printf("[TAXI]: A client forgot their phone. Return it and receive a reward +2000 RUB\n");
            rick.tbank.account += 2000;
            rick.taxi_tips += 2000;
            rick.tbank.total_earned += 2000;
            break;

        case 4:
            printf("[TAXI]: Washing a car after a dirty ride -1500 RUB\n");
            rick.tbank.account -= 1500;
            rick.taxi_expenses += 1500;
            rick.tbank.total_spent += 1500;
            break;

        case 5:
            printf("[TAXI]: Got into a minor accident. Bumper repair -15000 RUB\n");
            rick.tbank.account -= 15000;
            rick.taxi_expenses += 15000;
            rick.tbank.total_spent += 15000;
            break;

        case 6:
            printf("[TAXI]: A regular customer called a taxi. Bonus +3000 RUB\n");
            rick.tbank.account += 3000;
            rick.taxi_tips += 3000;
            rick.tbank.total_earned += 3000;
            break;

        case 7:
            printf("[TAXI]: Buying a new radio for communication -4000 RUB\n");
            rick.tbank.account -= 4000;
            rick.taxi_expenses += 4000;
            rick.tbank.total_spent += 4000;
            break;

        case 8:
            printf("[TAXI]: A passenger asked to go faster. A speeding ticket -2000 RUB\n");
            rick.tbank.account -= 2000;
            rick.taxi_expenses += 2000;
            rick.tbank.total_spent += 2000;
            break;

        case 9:
            printf("[TAXI]: Good day. Lots of orders! Bonus +6000 RUB\n");
            rick.tbank.account += 6000;
            rick.taxi_money += 6000;
            rick.tbank.total_earned += 6000;
            break;

        case 10:
            printf("[TAXI]: Oil change at a taxi company -5000 RUB\n");
            rick.tbank.account -= 5000;
            rick.taxi_expenses += 5000;
            rick.tbank.total_spent += 5000;
            break;

        case 11:
            printf("[TAXI]: Tourists paid generously for the ride to the hotel +4000 RUB\n");
            rick.tbank.account += 4000;
            rick.taxi_tips += 4000;
            rick.tbank.total_earned += 4000;
            break;

        case 12:
            printf("[TAXI]: The navigator is broken. Buying a new one -8000 RUB\n");
            rick.tbank.account -= 8000;
            rick.taxi_expenses += 8000;
            rick.tbank.total_spent += 8000;
            break;

        case 13:
            printf("[TAXI]: Free ride for a colleague. Lost -1000 RUB\n");
            rick.tbank.account -= 1000;
            rick.taxi_expenses += 1000;
            rick.tbank.total_spent += 1000;
            break;

        case 14:
            printf("[TAXI]: Won the 'Driver of the Month' competition +10000 RUB\n");
            rick.tbank.account += 10000;
            rick.taxi_money += 10000;
            rick.tbank.total_earned += 10000;
            break;

        case 15:
            printf("[TAXI]: Replacing windshield wipers before rain -2000 RUB\n");
            rick.tbank.account -= 2000;
            rick.taxi_expenses += 2000;
            rick.tbank.total_spent += 2000;
            break;

        case 16:
            printf("[TAXI]: The client paid in foreign currency. Exchange +2500 RUB\n");
            rick.tbank.account += 2500;
            rick.taxi_tips += 2500;
            rick.tbank.total_earned += 2500;
            break;

        case 17:
            printf("[TAXI]: Entering a toll road by mistake -1000 RUB\n");
            rick.tbank.account -= 1000;
            rick.taxi_expenses += 1000;
            rick.tbank.total_spent += 1000;
            break;

        case 18:
            printf("[TAXI]: Buying air fresheners and fragrances -1500 RUB\n");
            rick.tbank.account -= 1500;
            rick.taxi_expenses += 1500;
            rick.tbank.total_spent += 1500;
            break;

        case 19:
            printf("[TAXI]: Wedding procession. Good tips! +7000 RUB\n");
            rick.tbank.account += 7000;
            rick.taxi_tips += 7000;
            rick.tbank.total_earned += 7000;
            break;

        default:
            printf("[TAXI]: Nothing special. A typical workday.\n");
            break;
        }
    }
}


void rick_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        rick.tbank.account_usd += 3'000;
    }
}


void rick_food(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick_main.food = rick_main.food * (1.0 + inflation_rate);
    }

    if (rick.tbank.account >= rick_main.food) {
        rick.tbank.account -= rick_main.food;
        rick.tbank.total_spent += rick_main.food;
    }
    else {
        rick.tbank.credit += rick_main.food - rick.tbank.account;
        rick.tbank.total_spent += rick_main.food;
        rick.tbank.account = 0;
    }
}


void rick_bmw_x3_credit(const int month, const int year)
{
    if (rick.bmw_x3.credit > 0) {
        rick.bmw_x3.credit += rick.bmw_x3.credit * (rick.bmw_x3.credit_interest / 12.0 / 100.0);
        if (rick.tbank.account >= rick.bmw_x3.credit_payment) {
            rick.tbank.account -= rick.bmw_x3.credit_payment;
            rick.bmw_x3.credit -= rick.bmw_x3.credit_payment;
            rick.tbank.total_spent += rick.bmw_x3.credit_payment;
        }
        else {
            rick.tbank.account -= 10000;
            rick.tbank.total_spent += 10000;
        }
    }
}


void rick_bmw_x3_gas(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x3.gas_price = rick.bmw_x3.gas_price * (1.0 + inflation_rate * 0.7);
        rick.bmw_x3.gas_month = rick.bmw_x3.gas_month * (1.0 + inflation_rate * 0.7);
    }

    RUB gas_cost = rick.bmw_x3.gas_month;
    if (rick.tbank.account >= gas_cost) {
        rick.tbank.account -= gas_cost;
        rick.tbank.total_spent += gas_cost;
    }
    else {
        rick.tbank.credit += gas_cost - rick.tbank.account;
        rick.tbank.total_spent += gas_cost;
        rick.tbank.account = 0;
    }
}


void rick_bmw_x3_insurance(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x3.insurance = rick.bmw_x3.insurance * (1.0 + inflation_rate * 0.8);
    }

    if (month == 2) {
        if (rick.tbank.account >= rick.bmw_x3.insurance) {
            rick.tbank.account -= rick.bmw_x3.insurance;
            rick.tbank.total_spent += rick.bmw_x3.insurance;
        }
        else {
            rick.tbank.credit += rick.bmw_x3.insurance - rick.tbank.account;
            rick.tbank.total_spent += rick.bmw_x3.insurance;
            rick.tbank.account = 0;
        }
    }
}


void rick_bmw_x3_tire_change(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x3.tire_change = rick.bmw_x3.tire_change * (1.0 + inflation_rate * 0.5);
    }

    if (month == 10 or month == 4) {
        if (rick.tbank.account >= rick.bmw_x3.tire_change) {
            rick.tbank.account -= rick.bmw_x3.tire_change;
            rick.tbank.total_spent += rick.bmw_x3.tire_change;
        }
        else {
            rick.tbank.credit += rick.bmw_x3.tire_change - rick.tbank.account;
            rick.tbank.total_spent += rick.bmw_x3.tire_change;
            rick.tbank.account = 0;
        }
    }
}


void rick_bmw_x3_new_tires(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x3.winter_tires = rick.bmw_x3.winter_tires * (1.0 + inflation_rate * 0.7);
        rick.bmw_x3.summer_tires = rick.bmw_x3.summer_tires * (1.0 + inflation_rate * 0.7);
    }

    if (year % 3 == 0) {
        if (month == 10) {
            if (rick.tbank.account >= rick.bmw_x3.winter_tires) {
                rick.tbank.account -= rick.bmw_x3.winter_tires;
                rick.tbank.total_spent += rick.bmw_x3.winter_tires;
            }
            else {
                rick.tbank.credit += rick.bmw_x3.winter_tires - rick.tbank.account;
                rick.tbank.total_spent += rick.bmw_x3.winter_tires;
                rick.tbank.account = 0;
            }
        }
        if (month == 4) {
            if (rick.tbank.account >= rick.bmw_x3.summer_tires) {
                rick.tbank.account -= rick.bmw_x3.summer_tires;
                rick.tbank.total_spent += rick.bmw_x3.summer_tires;
            }
            else {
                rick.tbank.credit += rick.bmw_x3.summer_tires - rick.tbank.account;
                rick.tbank.total_spent += rick.bmw_x3.summer_tires;
                rick.tbank.account = 0;
            }
        }
    }
}


void rick_bmw_x3_service(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x3.season_service = rick.bmw_x3.season_service * (1.0 + inflation_rate * 0.6);
    }

    rick.bmw_x3.months_since_service++;
    if (rick.bmw_x3.months_since_service >= 2) {
        RUB service_cost = rick.bmw_x3.season_service;
        if (rick.bmw_x3.age > 5) {
            service_cost = service_cost * 1.3;
        }
        if (rick.bmw_x3.age > 10) {
            service_cost = service_cost * 1.5;
        }
        if (rick.tbank.account >= service_cost) {
            rick.tbank.account -= service_cost;
            rick.tbank.total_spent += service_cost;
        }
        else {
            rick.tbank.credit += service_cost - rick.tbank.account;
            rick.tbank.total_spent += service_cost;
            rick.tbank.account = 0;
        }
        rick.bmw_x3.months_since_service = 0;
    }
}


void rick_bmw_x3_repair(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x3.random_repair_min = rick.bmw_x3.random_repair_min * (1.0 + inflation_rate);
        rick.bmw_x3.random_repair_max = rick.bmw_x3.random_repair_max * (1.0 + inflation_rate);
    }

    int random_chance = rand() % 100;
    int repair_chance = rick.bmw_x3.age * 3;

    if (random_chance < repair_chance) {
        RUB repair_cost = rick.bmw_x3.random_repair_min + (rand() % (rick.bmw_x3.random_repair_max - rick.bmw_x3.random_repair_min));
        if (rick.tbank.account >= repair_cost) {
            rick.tbank.account -= repair_cost;
            rick.tbank.total_spent += repair_cost;
            rick.bmw_x3.accumulated_repair += repair_cost;
        }
        else {
            rick.tbank.credit += repair_cost - rick.tbank.account;
            rick.bmw_x3.accumulated_repair += repair_cost;
            rick.tbank.total_spent += repair_cost;
            rick.tbank.account = 0;
        }
    }
}


void rick_bmw_x3_aging(const int month, const int year)
{
    if (month == 12) {
        rick.bmw_x3.age++;
        rick.bmw_x3.value = rick.bmw_x3.value * 0.90;
        rick.bmw_x3.mileage_year += 2000;


        if (rick.tbank.account >= rick.bmw_x3.tax) {
            rick.tbank.account -= rick.bmw_x3.tax;
            rick_main.total_taxes_paid += rick.bmw_x3.tax;
            rick.tbank.total_spent += rick.bmw_x3.tax;
        }
        else {
            rick.tbank.credit += rick.bmw_x3.tax;
            rick_main.total_taxes_paid += rick.bmw_x3.tax;
            rick.tbank.total_spent += rick.bmw_x3.tax;
        }
    }
}


void rick_car_bmw_x3(const int month, const int year)
{
    rick_bmw_x3_credit(month, year);
    rick_bmw_x3_gas(month, year);
    rick_bmw_x3_insurance(month, year);
    rick_bmw_x3_tire_change(month, year);
    rick_bmw_x3_new_tires(month, year);
    rick_bmw_x3_service(month, year);
    rick_bmw_x3_repair(month, year);
    rick_bmw_x3_aging(month, year);
}


void rick_bmw_x5_credit(const int month, const int year)
{
    if (rick.bmw_x5.credit > 0) {
        rick.bmw_x5.credit += rick.bmw_x5.credit * (rick.bmw_x5.credit_interest / 12.0 / 100.0);
        if (rick.tbank.account >= rick.bmw_x5.credit_payment) {
            rick.tbank.account -= rick.bmw_x5.credit_payment;
            if (rick.bmw_x5.credit >= rick.bmw_x5.credit_payment) {
                rick.bmw_x5.credit -= rick.bmw_x5.credit_payment;
            }
            else {
                RUB overpayment = rick.bmw_x5.credit_payment - rick.bmw_x5.credit;
                rick.bmw_x5.credit = 0;
                rick.tbank.account += overpayment;
            }
            rick.tbank.total_spent += rick.bmw_x5.credit_payment;
        }
        else {
            rick.tbank.account -= 10000;
            rick.tbank.total_spent += 10000;
        }
    }
}


void rick_bmw_x5_gas(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x5.gas_price = rick.bmw_x5.gas_price * (1.0 + inflation_rate * 0.7);
        rick.bmw_x5.gas_month = rick.bmw_x5.gas_month * (1.0 + inflation_rate * 0.7);
    }

    RUB gas_cost = rick.bmw_x5.gas_month;
    if (rick.tbank.account >= gas_cost) {
        rick.tbank.account -= gas_cost;
        rick.tbank.total_spent += gas_cost;
    }
    else {
        rick.tbank.credit += gas_cost - rick.tbank.account;
        rick.tbank.total_spent += gas_cost;
        rick.tbank.account = 0;
    }
}


void rick_bmw_x5_insurance(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x5.insurance = rick.bmw_x5.insurance * (1.0 + inflation_rate * 0.8);
    }

    if (month == 2) {
        if (rick.tbank.account >= rick.bmw_x5.insurance) {
            rick.tbank.account -= rick.bmw_x5.insurance;
            rick.tbank.total_spent += rick.bmw_x5.insurance;
        }
        else {
            rick.tbank.credit += rick.bmw_x5.insurance - rick.tbank.account;
            rick.tbank.total_spent += rick.bmw_x5.insurance;
            rick.tbank.account = 0;
        }
    }
}


void rick_bmw_x5_tire_change(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x5.tire_change = rick.bmw_x5.tire_change * (1.0 + inflation_rate * 0.5);
    }

    if (month == 10 or month == 4) {
        if (rick.tbank.account >= rick.bmw_x5.tire_change) {
            rick.tbank.account -= rick.bmw_x5.tire_change;
            rick.tbank.total_spent += rick.bmw_x5.tire_change;
        }
        else {
            rick.tbank.credit += rick.bmw_x5.tire_change - rick.tbank.account;
            rick.tbank.total_spent += rick.bmw_x5.tire_change;
            rick.tbank.account = 0;
        }
    }
}


void rick_bmw_x5_new_tires(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x5.winter_tires = rick.bmw_x5.winter_tires * (1.0 + inflation_rate * 0.7);
        rick.bmw_x5.summer_tires = rick.bmw_x5.summer_tires * (1.0 + inflation_rate * 0.7);
    }

    if (year % 3 == 0) {
        if (month == 10) {
            if (rick.tbank.account >= rick.bmw_x5.winter_tires) {
                rick.tbank.account -= rick.bmw_x5.winter_tires;
                rick.tbank.total_spent += rick.bmw_x5.winter_tires;
            }
            else {
                rick.tbank.credit += rick.bmw_x5.winter_tires - rick.tbank.account;
                rick.tbank.total_spent += rick.bmw_x5.winter_tires;
                rick.tbank.account = 0;
            }
        }
        if (month == 4) {
            if (rick.tbank.account >= rick.bmw_x5.summer_tires) {
                rick.tbank.account -= rick.bmw_x5.summer_tires;
                rick.tbank.total_spent += rick.bmw_x5.summer_tires;
            }
            else {
                rick.tbank.credit += rick.bmw_x5.summer_tires - rick.tbank.account;
                rick.tbank.total_spent += rick.bmw_x5.summer_tires;
                rick.tbank.account = 0;
            }
        }
    }
}


void rick_bmw_x5_service(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x5.season_service = rick.bmw_x5.season_service * (1.0 + inflation_rate * 0.6);
    }

    rick.bmw_x5.months_since_service++;
    if (rick.bmw_x5.months_since_service >= 2) {
        RUB service_cost = rick.bmw_x5.season_service;
        if (rick.bmw_x5.age > 5) {
            service_cost = service_cost * 1.3;
        }
        if (rick.bmw_x5.age > 10) {
            service_cost = service_cost * 1.5;
        }
        if (rick.tbank.account >= service_cost) {
            rick.tbank.account -= service_cost;
            rick.tbank.total_spent += service_cost;
        }
        else {
            rick.tbank.credit += service_cost - rick.tbank.account;
            rick.tbank.total_spent += service_cost;
            rick.tbank.account = 0;
        }
        rick.bmw_x5.months_since_service = 0;
    }
}


void rick_bmw_x5_repair(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.bmw_x5.random_repair_min = rick.bmw_x5.random_repair_min * (1.0 + inflation_rate);
        rick.bmw_x5.random_repair_max = rick.bmw_x5.random_repair_max * (1.0 + inflation_rate);
    }

    int random_chance = rand() % 100;
    int repair_chance = rick.bmw_x5.age * 3;

    if (random_chance < repair_chance) {
        RUB repair_cost = rick.bmw_x5.random_repair_min + (rand() % (rick.bmw_x5.random_repair_max - rick.bmw_x5.random_repair_min));
        if (rick.tbank.account >= repair_cost) {
            rick.tbank.account -= repair_cost;
            rick.tbank.total_spent += repair_cost;
            rick.bmw_x5.accumulated_repair += repair_cost;
        }
        else {
            rick.tbank.credit += repair_cost - rick.tbank.account;
            rick.bmw_x5.accumulated_repair += repair_cost;
            rick.tbank.total_spent += repair_cost;
            rick.tbank.account = 0;
        }
    }
}


void rick_bmw_x5_aging(const int month, const int year)
{
    if (month == 12) {
        rick.bmw_x5.age++;
        rick.bmw_x5.value = rick.bmw_x5.value * 0.95;


        if (rick.tbank.account >= rick.bmw_x5.tax) {
            rick.tbank.account -= rick.bmw_x5.tax;
            rick_main.total_taxes_paid += rick.bmw_x5.tax;
            rick.tbank.total_spent += rick.bmw_x5.tax;
        }
        else {
            rick.tbank.credit += rick.bmw_x5.tax;
            rick_main.total_taxes_paid += rick.bmw_x5.tax;
            rick.tbank.total_spent += rick.bmw_x5.tax;
        }
    }
}


void rick_car_bmw_x5(const int month, const int year)
{
    rick_bmw_x5_credit(month, year);
    rick_bmw_x5_gas(month, year);
    rick_bmw_x5_insurance(month, year);
    rick_bmw_x5_tire_change(month, year);
    rick_bmw_x5_new_tires(month, year);
    rick_bmw_x5_service(month, year);
    rick_bmw_x5_repair(month, year);
    rick_bmw_x5_aging(month, year);
}


void rick_credit(const int month, const int year)
{
    if (rick.tbank.credit > 0) {
        if (year == 2026) rick.tbank.credit_interest = 21.0;
        if (year == 2027) rick.tbank.credit_interest = 20.5;
        if (year == 2028) rick.tbank.credit_interest = 19.5;
        if (year == 2029) rick.tbank.credit_interest = 18.5;
        if (year == 2030) rick.tbank.credit_interest = 18.0;
        if (year == 2031) rick.tbank.credit_interest = 17.5;
        if (year == 2032) rick.tbank.credit_interest = 17.0;
        if (year == 2033) rick.tbank.credit_interest = 16.5;
        if (year == 2034) rick.tbank.credit_interest = 16.0;
        if (year == 2035) rick.tbank.credit_interest = 15.5;
        if (year == 2036) rick.tbank.credit_interest = 15.0;
        if (year == 2037) rick.tbank.credit_interest = 14.5;
        if (year == 2038) rick.tbank.credit_interest = 14.0;
        if (year == 2039) rick.tbank.credit_interest = 13.5;
        if (year == 2040) rick.tbank.credit_interest = 13.0;
        if (year == 2041) rick.tbank.credit_interest = 12.5;
        if (year == 2042) rick.tbank.credit_interest = 12.0;
        if (year == 2043) rick.tbank.credit_interest = 11.5;
        if (year == 2044) rick.tbank.credit_interest = 11.0;
        if (year == 2045) rick.tbank.credit_interest = 10.5;
        if (year == 2046) rick.tbank.credit_interest = 10.0;
        if (year == 2047) rick.tbank.credit_interest = 9.5;
        if (year == 2048) rick.tbank.credit_interest = 9.0;
        if (year == 2049) rick.tbank.credit_interest = 8.5;
        if (year == 2050) rick.tbank.credit_interest = 8.0;

        rick.tbank.credit += rick.tbank.credit * (rick.tbank.credit_interest / 12.0 / 100.0);

        rick.tbank.payment = rick.tbank.credit * 0.05;
        if (rick.tbank.account >= rick.tbank.payment) {
            rick.tbank.account -= rick.tbank.payment;
            rick.tbank.credit -= rick.tbank.payment;
            rick.tbank.total_spent += rick.tbank.payment;
        }
        else {
            rick.tbank.account -= 1000;
            rick.tbank.total_spent += 1000;
        }

        if (rick.tbank.credit > 0 && rick.tbank.credit < 5000) {
            if (rick.tbank.account >= rick.tbank.credit) {
                rick.tbank.account -= rick.tbank.credit;
                rick.tbank.total_spent += rick.tbank.credit;
                rick.tbank.credit = 0;
            }
            else {
                rick.tbank.credit -= rick.tbank.account;
                rick.tbank.total_spent += rick.tbank.account;
                rick.tbank.account = 0;
            }
        } 
    }
}


void rick_deposite(const int month, const int year)
{
    if (year == 2026) rick.tbank.deposite_interest = 8.0;
    if (year == 2027) rick.tbank.deposite_interest = 7.8;
    if (year == 2028) rick.tbank.deposite_interest = 7.5;
    if (year == 2029) rick.tbank.deposite_interest = 7.2;
    if (year == 2030) rick.tbank.deposite_interest = 7.0;
    if (year == 2031) rick.tbank.deposite_interest = 6.8;
    if (year == 2032) rick.tbank.deposite_interest = 6.5;
    if (year == 2033) rick.tbank.deposite_interest = 6.2;
    if (year == 2034) rick.tbank.deposite_interest = 6.0;
    if (year == 2035) rick.tbank.deposite_interest = 5.8;
    if (year == 2036) rick.tbank.deposite_interest = 5.5;
    if (year == 2037) rick.tbank.deposite_interest = 5.2;
    if (year == 2038) rick.tbank.deposite_interest = 5.0;
    if (year == 2039) rick.tbank.deposite_interest = 4.8;
    if (year == 2040) rick.tbank.deposite_interest = 4.5;
    if (year == 2041) rick.tbank.deposite_interest = 4.2;
    if (year == 2042) rick.tbank.deposite_interest = 4.0;
    if (year == 2043) rick.tbank.deposite_interest = 3.8;
    if (year == 2044) rick.tbank.deposite_interest = 3.5;
    if (year == 2045) rick.tbank.deposite_interest = 3.2;
    if (year == 2046) rick.tbank.deposite_interest = 3.0;
    if (year == 2047) rick.tbank.deposite_interest = 2.8;
    if (year == 2048) rick.tbank.deposite_interest = 2.5;
    if (year == 2049) rick.tbank.deposite_interest = 2.2;
    if (year == 2050) rick.tbank.deposite_interest = 2.0;

    rick.tbank.deposite += rick.tbank.deposite * (rick.tbank.deposite_interest / 12.0 / 100.0);

    if (rick.tbank.account > 0) {
        rick.tbank.deposite += rick.tbank.account;
        rick.tbank.account = 0;
    }

    else if (rick.tbank.account < 0) {
        rick.tbank.credit += -rick.tbank.account;
        rick.tbank.account = 0;
    }
}


void rick_housing_buy_house(int month, int year)
{
    if (year == 2036 and month == 6 and rick.has_house == false) {
        printf("\n========== RICK BUYS A HOUSE! ==========\n");

        RUB house_price = 15'000'000;

        if (rick.tbank.deposite >= house_price) {
            rick.tbank.deposite -= house_price;
            rick_main.housing.value = house_price;
            rick_main.housing.year_bought = year;

            rick_main.housing.utilities = 10'000;
            rick_main.housing.heating = 5'000;
            rick_main.housing.internet = 1'500;
            rick_main.housing.garden = 3'000;
            rick_main.housing.tax = house_price * 0.01 / 12;

            rick.has_house = true;

            printf("The house was purchased for %lld RUB!\n", house_price);
            printf("========================================\n\n");
        }
        else {
            printf("Not enough money for a house!\n");
        }
    }
}


void rick_housing_rent(int month, int year)
{
    if (rick.has_house == false) {
        rick.tbank.account -= rick_main.housing.rent;
        rick_main.housing.total_spent += rick_main.housing.rent;
        rick.tbank.total_spent += rick_main.housing.rent;
    }
}


void rick_housing_utilities(int month, int year)
{
    if (month == 1 && year > 2026) {
        rick_main.housing.utilities = rick_main.housing.utilities * (1.0 + inflation_rate);
    }

    RUB utilities_cost = rick_main.housing.utilities;

    if (rick.has_house == false) {
        if (month == 1 or month == 2 or month == 12) {
            utilities_cost = utilities_cost * 1.3;
        }
    }

    rick.tbank.account -= utilities_cost;
    rick_main.housing.total_spent += utilities_cost;
    rick.tbank.total_spent += utilities_cost;
}


void rick_housing_internet(int month, int year)
{
    if (month == 1 && year > 2026) {
        rick_main.housing.internet = rick_main.housing.internet * (1.0 + inflation_rate * 0.8);
    }

    rick.tbank.account -= rick_main.housing.internet;
    rick_main.housing.total_spent += rick_main.housing.internet;
    rick.tbank.total_spent += rick_main.housing.internet;
}


void rick_housing_heating(int month, int year)
{
    if (rick.has_house == true) {
        if (month == 1 or month == 2 or month == 3 or month == 10 or month == 11 or month == 12) {
            rick.tbank.account -= rick_main.housing.heating;
            rick_main.housing.total_spent += rick_main.housing.heating;
            rick.tbank.total_spent += rick_main.housing.heating;
        }
    }
}


void rick_housing_garden(int month, int year)
{
    if (rick.has_house == true) {
        if (month >= 4 and month <= 9) {
            rick.tbank.account -= rick_main.housing.garden;
            rick_main.housing.total_spent += rick_main.housing.garden;
            rick.tbank.total_spent += rick_main.housing.garden;
        }
    }
}


void rick_housing_repairs(int month, int year)
{
    int event_chance = rand() % 100;
    int threshold = (rick.has_house ? 9 : 6);  // шансы для дома и кв

    if (event_chance < threshold) {
        int housing_event;
        RUB event_cost = 0;

        if (rick.has_house) {  // для дома
            housing_event = (month + year * 2) % 9;

            switch (housing_event) {
            case 0:
                printf("[HOUSE]: The roof is leaking. Repairs needed - 25000 RUB\n");
                event_cost = 25000;
                rick_main.housing.repairs += event_cost;
                break;
            case 1:
                printf("[HOUSE]: Buying a new washing machine - 40000 RUB\n");
                event_cost = 40000;
                rick_main.housing.appliances += event_cost;
                break;
            case 2:
                printf("[HOUSE]: Heating boiler replacement -60000 RUB\n");
                event_cost = 60000;
                rick_main.housing.repairs += event_cost;
                break;
            case 3:
                printf("[HOUSE]: Buying new furniture for the living room -80000 RUB\n");
                event_cost = 80000;
                rick_main.housing.furniture += event_cost;
                break;
            case 4:
                printf("[HOUSE]: A pipe burst. Urgent repairs needed -35000 RUB\n");
                event_cost = 35000;
                rick_main.housing.repairs += event_cost;
                break;
            case 5:
                printf("[HOUSE]: Planted new trees in the garden -15000 RUB\n");
                event_cost = 15000;
                rick_main.housing.garden += event_cost;
                break;
            case 6:
                printf("[HOUSE]: Replacing windows with plastic ones -90000 RUB\n");
                event_cost = 90000;
                rick_main.housing.repairs += event_cost;
                break;
            case 7:
                printf("[HOUSE]: Buying a lawn mower -25000 RUB\n");
                event_cost = 25000;
                rick_main.housing.garden += event_cost;
                break;
            case 8:
                printf("[HOUSE]: Buying a new refrigerator -55000 RUB\n");
                event_cost = 55000;
                rick_main.housing.appliances += event_cost;
                break;
            default: break;
            }
        }
        else {  // для квартиры
            housing_event = (month + year) % 6;

            switch (housing_event) {
            case 0:
                printf("[APARTMENT]: The faucet is broken. Call a plumber -3000 RUB\n");
                event_cost = 3000;
                rick_main.housing.repairs += event_cost;
                break;
            case 1:
                printf("[APARTMENT]: Buying a new light fixture for the room -2500 RUB\n");
                event_cost = 2500;
                rick_main.housing.furniture += event_cost;
                break;
            case 2:
                printf("[APARTMENT]: The kettle burned out. Buying a new one -2000 RUB\n");
                event_cost = 2000;
                rick_main.housing.appliances += event_cost;
                break;
            case 3:
                printf("[APARTMENT]: Neighbors flooded. Ceiling repair -8000 RUB\n");
                event_cost = 8000;
                rick_main.housing.repairs += event_cost;
                break;
            case 4:
                printf("[APARTMENT]: Buying a new mattress -7000 RUB\n");
                event_cost = 7000;
                rick_main.housing.furniture += event_cost;
                break;
            case 5:
                printf("[APARTMENT]: The landlord raised the rent! Extra charge -5000 RUB\n");
                event_cost = 5000;
                rick_main.housing.rent += 5000;
                break;
            default: break;
            }
        }

        if (event_cost > 0) {
            rick.tbank.account -= event_cost;
            rick_main.housing.total_spent += event_cost;
            rick.tbank.total_spent += event_cost;
        }
    }
}


void rick_housing_tax(int month, int year)
{
    if (month == 12 and rick.has_house == true) {
        if (rick.tbank.account >= rick_main.housing.tax) {
            rick.tbank.account -= rick_main.housing.tax;
            rick_main.total_taxes_paid += rick_main.housing.tax;
            rick.tbank.total_spent += rick_main.housing.tax;
        }
        else {
            rick.tbank.credit += rick_main.housing.tax;
            rick_main.total_taxes_paid += rick_main.housing.tax;
            rick.tbank.total_spent += rick_main.housing.tax;
        }
    }
}


void rick_housing_life(int month, int year)
{
    rick_housing_buy_house(month, year);
    rick_housing_rent(month, year);
    rick_housing_utilities(month, year);
    rick_housing_internet(month, year);
    rick_housing_heating(month, year);
    rick_housing_garden(month, year);
    rick_housing_repairs(month, year);
    rick_housing_tax(month, year);
}


void rick_garage_life(const int month, const int year)
{
    rick.tbank.account -= rick.garage.rent;
    rick.garage.total_spent += rick.garage.rent;
    rick.tbank.total_spent += rick.garage.rent;

    RUB electricity_cost = rick.garage.electricity;
    if (month == 1 or month == 2 or month == 12) {
        electricity_cost = electricity_cost * 1.5;
    }
    rick.tbank.account -= electricity_cost;
    rick.garage.total_spent += electricity_cost;
    rick.tbank.total_spent += electricity_cost;

    int event_chance = rand() % 100;
    if (event_chance < 5) {
        int garage_event = (month + year) % 4;

        switch (garage_event) {
        case 0:
            printf("[GARAGE]: The shelf collapsed. Buying a new one -2000 RUB\n");
            rick.tbank.account -= 2000;
            rick.garage.repairs += 2000;
            rick.garage.total_spent += 2000;
            rick.tbank.total_spent += 2000;
            break;
        case 1:
            printf("[GARAGE]: Changing the locks in the garage -1500 RUB\n");
            rick.tbank.account -= 1500;
            rick.garage.repairs += 1500;
            rick.garage.total_spent += 1500;
            rick.tbank.total_spent += 1500;
            break;
        case 2:
            printf("[GARAGE]: Buying a tool rack -3000 RUB\n");
            rick.tbank.account -= 3000;
            rick.garage.repairs += 3000;
            rick.garage.total_spent += 3000;
            rick.tbank.total_spent += 3000;
            break;
        case 3:
            printf("[GARAGE]: Conducted lighting -2500 RUB\n");
            rick.tbank.account -= 2500;
            rick.garage.repairs += 2500;
            rick.garage.total_spent += 2500;
            rick.tbank.total_spent += 2500;
            break;
        }
    }
}


// CLIFF'S LIFE
void cliff_salary(const int month, const int year)
{
    if (month == 1 and year == 2027) {
        cliff_main.salary *= 1.3;
    }
    if (month == 1 and year > 2027) {
        cliff_main.salary = cliff_main.salary * (1.0 + inflation_rate * 0.8);
    }

    RUB salary_without_tax = cliff_main.salary;

    if (month == 12) {
        salary_without_tax += cliff_main.salary;
    }

    RUB income_tax = salary_without_tax * 0.13;

    cliff.vtb.account += salary_without_tax - income_tax;
    cliff.vtb.total_earned += salary_without_tax;
    cliff_main.total_taxes_paid += income_tax;
}


void cliff_stunt_work(const int month, const int year)
{
    int jobs_this_month = cliff.stunt_jobs_per_month;
    RUB base_income = cliff.stunt_income_per_job * jobs_this_month;

    RUB stunt_tax = base_income * 0.06;

    cliff.stunt_money += base_income;
    cliff.vtb.account += base_income - stunt_tax;
    cliff.vtb.total_earned += base_income;
    cliff_main.total_taxes_paid += stunt_tax;

    int event_chance = rand() % 100;
    if (event_chance < 40) {
        int stunt_event = (month * 3 + year) % 15;

        switch (stunt_event) {
        case 0:
            printf("[STUNT]: Successful complex jump! Bonus +10,000 RUB\n");
            cliff.vtb.account += 10000;
            cliff.stunt_bonuses += 10000;
            cliff.vtb.total_earned += 10000;
            break;

        case 1:
            printf("[STUNT]: Minor injury. Medical expenses -5,000 RUB\n");
            cliff.vtb.account -= 5000;
            cliff.stunt_medical_expenses += 5000;
            cliff.vtb.total_spent += 5000;
            cliff.stunt_injuries++;
            break;

        case 2:
            printf("[STUNT]: Filming cancelled. Compensation +4,000 RUB\n");
            cliff.vtb.account += 4000;
            cliff.vtb.total_earned += 4000;
            break;

        case 3:
            printf("[STUNT]: Stunt coordinator gave a bonus! +8,000 RUB\n");
            cliff.vtb.account += 8000;
            cliff.stunt_bonuses += 8000;
            cliff.vtb.total_earned += 8000;
            break;

        case 4:
            printf("[STUNT]: Bruised ribs. Medical expenses -7,000 RUB\n");
            cliff.vtb.account -= 7000;
            cliff.stunt_medical_expenses += 7000;
            cliff.vtb.total_spent += 7000;
            cliff.stunt_injuries++;
            break;

        case 5:
            printf("[STUNT]: New stunt equipment needed -6,000 RUB\n");
            cliff.vtb.account -= 6000;
            cliff.vtb.total_spent += 6000;
            break;

        case 6:
            printf("[STUNT]: Featured in a movie trailer! Bonus +15,000 RUB\n");
            cliff.vtb.account += 15000;
            cliff.stunt_bonuses += 15000;
            cliff.vtb.total_earned += 15000;
            break;

        case 7:
            printf("[STUNT]: Pulled a muscle. Medical expenses -4,000 RUB\n");
            cliff.vtb.account -= 4000;
            cliff.stunt_medical_expenses += 4000;
            cliff.vtb.total_spent += 4000;
            cliff.stunt_injuries++;
            break;

        case 8:
            printf("[STUNT]: Dangerous car flip! Danger pay +12,000 RUB\n");
            cliff.vtb.account += 12000;
            cliff.stunt_bonuses += 12000;
            cliff.vtb.total_earned += 12000;
            break;

        case 9:
            printf("[STUNT]: Stunt school training -5,000 RUB\n");
            cliff.vtb.account -= 5000;
            cliff.vtb.total_spent += 5000;
            break;

        case 10:
            printf("[STUNT]: Worked as a stunt double for a star! +20,000 RUB\n");
            cliff.vtb.account += 20000;
            cliff.stunt_money += 20000;
            cliff.vtb.total_earned += 20000;
            break;

        case 11:
            printf("[STUNT]: Broken finger. Medical expenses -8,000 RUB\n");
            cliff.vtb.account -= 8000;
            cliff.stunt_medical_expenses += 8000;
            cliff.vtb.total_spent += 8000;
            cliff.stunt_injuries++;
            break;

        case 12:
            printf("[STUNT]: Stuntman of the month award! +10,000 RUB\n");
            cliff.vtb.account += 10000;
            cliff.stunt_bonuses += 10000;
            cliff.vtb.total_earned += 10000;
            break;

        case 13:
            printf("[STUNT]: Fire stunt practice -3,000 RUB\n");
            cliff.vtb.account -= 3000;
            cliff.vtb.total_spent += 3000;
            break;

        case 14:
            printf("[STUNT]: High fall stunt successfully performed! +18,000 RUB\n");
            cliff.vtb.account += 18000;
            cliff.stunt_bonuses += 18000;
            cliff.vtb.total_earned += 18000;
            break;

        default:
            break;
        }
    }
}

void cliff_food(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        cliff_main.food = cliff_main.food * (1.0 + inflation_rate);
    }

    if (cliff.vtb.account >= cliff_main.food) {
        cliff.vtb.account -= cliff_main.food;
        cliff.vtb.total_spent += cliff_main.food;
    }
    else {
        cliff.vtb.credit += cliff_main.food - cliff.vtb.account;
        cliff.vtb.total_spent += cliff_main.food;
        cliff.vtb.account = 0;
    }
}


void cliff_dog_life(const int month, const int year)
{
    if (cliff.vtb.account >= cliff.dog_food) {
        cliff.vtb.account -= cliff.dog_food;
        cliff.dog_total_spent += cliff.dog_food;
        cliff.vtb.total_spent += cliff.dog_food;
    }
    else {
        cliff.vtb.credit += cliff.dog_food - cliff.vtb.account;
        cliff.dog_total_spent += cliff.dog_food;
        cliff.vtb.total_spent += cliff.dog_food;
        cliff.vtb.account = 0;
    }

    int event_chance = rand() % 100;
    if (event_chance < 15) {
        int dog_event = (month + year) % 8;

        switch (dog_event) {
        case 0:
            printf("[BRANDY]: Brandy is sick. Vet visit -4,000 RUB\n");
            cliff.vtb.account -= 4000;
            cliff.dog_vet += 4000;
            cliff.dog_total_spent += 4000;
            cliff.vtb.total_spent += 4000;
            break;

        case 1:
            printf("[BRANDY]: Brandy chewed up the sofa! New one -5,000 RUB\n");
            cliff.vtb.account -= 5000;
            cliff.vtb.total_spent += 5000;
            break;

        case 2:
            printf("[BRANDY]: Brandy needs vaccination. Vet -3,000 RUB\n");
            cliff.vtb.account -= 3000;
            cliff.dog_vet += 3000;
            cliff.dog_total_spent += 3000;
            cliff.vtb.total_spent += 3000;
            break;

        case 3:
            printf("[BRANDY]: Buying new toys for Brandy -2,000 RUB\n");
            cliff.vtb.account -= 2000;
            cliff.dog_total_spent += 2000;
            cliff.vtb.total_spent += 2000;
            break;

        case 4:
            printf("[BRANDY]: Brandy found a lost wallet! Returned it. Reward +4,000 RUB\n");
            cliff.vtb.account += 4000;
            cliff.vtb.total_earned += 4000;
            break;

        case 5:
            printf("[BRANDY]: Brandy needs grooming. Pet salon -3,500 RUB\n");
            cliff.vtb.account -= 3500;
            cliff.dog_total_spent += 3500;
            cliff.vtb.total_spent += 3500;
            break;

        case 6:
            printf("[BRANDY]: Brandy won a local dog competition! Prize +5,000 RUB\n");
            cliff.vtb.account += 5000;
            cliff.vtb.total_earned += 5000;
            break;

        case 7:
            printf("[BRANDY]: Brandy ate something bad. Emergency vet -6,000 RUB\n");
            cliff.vtb.account -= 6000;
            cliff.dog_vet += 6000;
            cliff.dog_total_spent += 6000;
            cliff.vtb.total_spent += 6000;
            break;

        default:
            break;
        }
    }
}


void cliff_trailer_rent(int month, int year)
{
    cliff.vtb.account -= cliff_main.housing.rent;
    cliff_main.housing.total_spent += cliff_main.housing.rent;
    cliff.vtb.total_spent += cliff_main.housing.rent;
}


void cliff_trailer_utilities(int month, int year)
{
    if (month == 1 && year > 2026) {
        cliff_main.housing.utilities = cliff_main.housing.utilities * (1.0 + inflation_rate);
    }

    RUB utilities_cost = cliff_main.housing.utilities;
    if (month == 1 or month == 2 or month == 12) {
        utilities_cost = utilities_cost * 1.2;  // зимой +20%
    }

    cliff.vtb.account -= utilities_cost;
    cliff_main.housing.total_spent += utilities_cost;
    cliff.vtb.total_spent += utilities_cost;
}


void cliff_trailer_internet(int month, int year)
{
    if (month == 1 && year > 2026) {
        cliff_main.housing.internet = cliff_main.housing.internet * (1.0 + inflation_rate * 0.8);
    }

    cliff.vtb.account -= cliff_main.housing.internet;
    cliff_main.housing.total_spent += cliff_main.housing.internet;
    cliff.vtb.total_spent += cliff_main.housing.internet;
}


void cliff_trailer_repairs(int month, int year)
{
    int event_chance = rand() % 100;
    if (event_chance < 13) {
        int trailer_event = (month + year) % 10;
        RUB event_cost = 0;

        switch (trailer_event) {
        case 0:
            printf("[TRAILER]: Roof leaking. Repair -3,000 RUB\n");
            event_cost = 3000;
            cliff_main.housing.repairs += event_cost;
            break;

        case 1:
            printf("[TRAILER]: Bought a new camping chair -1,500 RUB\n");
            event_cost = 1500;
            cliff_main.housing.furniture += event_cost;
            break;

        case 2:
            printf("[TRAILER]: Portable heater broke. New one -3,000 RUB\n");
            event_cost = 3000;
            cliff_main.housing.appliances += event_cost;
            break;

        case 3:
            printf("[TRAILER]: Generator maintenance -2,000 RUB\n");
            event_cost = 2000;
            cliff_main.housing.repairs += event_cost;
            break;

        case 4:
            printf("[TRAILER]: New mattress for the trailer -4,000 RUB\n");
            event_cost = 4000;
            cliff_main.housing.furniture += event_cost;
            break;

        case 5:
            printf("[TRAILER]: Water tank replacement -5,000 RUB\n");
            event_cost = 5000;
            cliff_main.housing.repairs += event_cost;
            break;

        case 6:
            printf("[TRAILER]: Bought new curtains and rugs -2,500 RUB\n");
            event_cost = 2500;
            cliff_main.housing.furniture += event_cost;
            break;

        case 7:
            printf("[TRAILER]: Solar panel installation -8,000 RUB\n");
            event_cost = 8000;
            cliff_main.housing.appliances += event_cost;
            break;

        case 8:
            printf("[TRAILER]: Mouse infestation! Exterminator -3,500 RUB\n");
            event_cost = 3500;
            cliff.vtb.total_spent += event_cost;
            break;

        case 9:
            printf("[TRAILER]: Upgraded to a bigger trailer! Rent increase +5,000 RUB/month\n");
            cliff_main.housing.rent += 5000;
            event_cost = 0;
            break;

        default:
            break;
        }

        if (event_cost > 0) {
            cliff.vtb.account -= event_cost;
            cliff_main.housing.total_spent += event_cost;
            cliff.vtb.total_spent += event_cost;
        }
    }
}


void cliff_trailer_life(int month, int year)
{
    cliff_trailer_rent(month, year);
    cliff_trailer_utilities(month, year);
    cliff_trailer_internet(month, year);
    cliff_trailer_repairs(month, year);
}


void cliff_credit(const int month, const int year)
{
    if (cliff.vtb.credit > 0) {
        if (year == 2026) cliff.vtb.credit_interest = 19.0;
        if (year == 2027) cliff.vtb.credit_interest = 18.5;
        if (year == 2028) cliff.vtb.credit_interest = 18.5;
        if (year == 2029) cliff.vtb.credit_interest = 18.0;
        if (year == 2030) cliff.vtb.credit_interest = 18.2;
        if (year == 2031) cliff.vtb.credit_interest = 17.8;
        if (year == 2032) cliff.vtb.credit_interest = 17.5;
        if (year == 2033) cliff.vtb.credit_interest = 17.5;
        if (year == 2034) cliff.vtb.credit_interest = 16.9;
        if (year == 2035) cliff.vtb.credit_interest = 17.0;
        if (year == 2036) cliff.vtb.credit_interest = 17.1;
        if (year == 2037) cliff.vtb.credit_interest = 16.5;
        if (year == 2038) cliff.vtb.credit_interest = 16.5;
        if (year == 2039) cliff.vtb.credit_interest = 16.8;
        if (year == 2040) cliff.vtb.credit_interest = 17.0;
        if (year == 2041) cliff.vtb.credit_interest = 17.5;
        if (year == 2042) cliff.vtb.credit_interest = 17.6;
        if (year == 2043) cliff.vtb.credit_interest = 17.3;
        if (year == 2044) cliff.vtb.credit_interest = 16.5;
        if (year == 2045) cliff.vtb.credit_interest = 16.0;
        if (year == 2046) cliff.vtb.credit_interest = 17.0;
        if (year == 2047) cliff.vtb.credit_interest = 17.5;
        if (year == 2048) cliff.vtb.credit_interest = 16.5;
        if (year == 2049) cliff.vtb.credit_interest = 15.5;
        if (year == 2050) cliff.vtb.credit_interest = 15.0;

        cliff.vtb.credit += cliff.vtb.credit * (cliff.vtb.credit_interest / 12.0 / 100.0);

        cliff.vtb.payment = cliff.vtb.credit * 0.05;
        if (cliff.vtb.account >= cliff.vtb.payment) {
            cliff.vtb.account -= cliff.vtb.payment;
            cliff.vtb.credit -= cliff.vtb.payment;
            cliff.vtb.total_spent += cliff.vtb.payment;
        }
        else {
            cliff.vtb.account -= 1000;
            cliff.vtb.total_spent += 1000;
        }

        if (cliff.vtb.credit > 0 && cliff.vtb.credit < 5000) {
            if (cliff.vtb.account >= cliff.vtb.credit) {
                cliff.vtb.account -= cliff.vtb.credit;
                cliff.vtb.total_spent += cliff.vtb.credit;
                cliff.vtb.credit = 0;
            }
            else {
                cliff.vtb.credit -= cliff.vtb.account;
                cliff.vtb.total_spent += cliff.vtb.account;
                cliff.vtb.account = 0;
            }
        }
    }
}


void cliff_deposite(const int month, const int year)
{
    if (year == 2026) cliff.vtb.deposite_interest = 6.0;
    if (year == 2027) cliff.vtb.deposite_interest = 7.4;
    if (year == 2028) cliff.vtb.deposite_interest = 6.5;
    if (year == 2029) cliff.vtb.deposite_interest = 6.0;
    if (year == 2030) cliff.vtb.deposite_interest = 7.0;
    if (year == 2031) cliff.vtb.deposite_interest = 6.5;
    if (year == 2032) cliff.vtb.deposite_interest = 6.4;
    if (year == 2033) cliff.vtb.deposite_interest = 6.2;
    if (year == 2034) cliff.vtb.deposite_interest = 6.0;
    if (year == 2035) cliff.vtb.deposite_interest = 5.9;
    if (year == 2036) cliff.vtb.deposite_interest = 5.7;
    if (year == 2037) cliff.vtb.deposite_interest = 6.2;
    if (year == 2038) cliff.vtb.deposite_interest = 6.0;
    if (year == 2039) cliff.vtb.deposite_interest = 5.8;
    if (year == 2040) cliff.vtb.deposite_interest = 4.5;
    if (year == 2041) cliff.vtb.deposite_interest = 4.0;
    if (year == 2042) cliff.vtb.deposite_interest = 3.8;
    if (year == 2043) cliff.vtb.deposite_interest = 3.8;
    if (year == 2044) cliff.vtb.deposite_interest = 3.5;
    if (year == 2045) cliff.vtb.deposite_interest = 3.0;
    if (year == 2046) cliff.vtb.deposite_interest = 3.2;
    if (year == 2047) cliff.vtb.deposite_interest = 2.8;
    if (year == 2048) cliff.vtb.deposite_interest = 2.5;
    if (year == 2049) cliff.vtb.deposite_interest = 2.0;
    if (year == 2050) cliff.vtb.deposite_interest = 2.1;


    cliff.vtb.deposite += cliff.vtb.deposite * (cliff.vtb.deposite_interest / 12.0 / 100.0);

    if (cliff.vtb.account > 0) {
        cliff.vtb.deposite += cliff.vtb.account;
        cliff.vtb.account = 0;
    }
    else if (cliff.vtb.account < 0) {
        cliff.vtb.credit += -cliff.vtb.account;
        cliff.vtb.account = 0;
    }
}


// RESULTS RICK
void rick_print_mid_results(int year)
{
    printf("\n------------------------ %d RICK'S YEAR REPORT ------------------------\n", year);

    RUB bank_capital = 0;
    bank_capital += rick.tbank.account;
    bank_capital += rick.tbank.deposite;
    bank_capital += rick.tbank.account_usd * rick.tbank.rate_usd_rub;

    RUB car_capital = 0;
    car_capital += rick.bmw_x3.value;
    car_capital += rick.bmw_x5.value;

    RUB total_capital = bank_capital + car_capital;
    if (rick.has_house == true) {
        total_capital += rick_main.housing.value;
    }
    RUB total_debt = rick.tbank.credit + rick.bmw_x5.credit;
    RUB clean_capital = total_capital - total_debt;

    RUB net_taxi = rick.taxi_money + rick.taxi_tips - rick.taxi_expenses;

    printf("\n--- Assets ---\n");
    printf("Bank: %lld RUB.\n", bank_capital);
    printf("BMW X3: %lld RUB.\n", rick.bmw_x3.value);
    printf("BMW X5: %lld RUB.\n", rick.bmw_x5.value);
    if (rick.has_house == true) {
        printf("House: %lld RUB.\n", rick_main.housing.value);
    }
    printf("\n--- Taxi stats ---\n");
    printf("Taxi earned: %lld RUB.\n", rick.taxi_money);
    printf("Taxi tips: %lld RUB.\n", rick.taxi_tips);
    printf("Taxi clients: %d\n", rick.taxi_clients);
    printf("Taxi expenses: %lld RUB.\n", rick.taxi_expenses);
    printf("Net taxi income: %lld RUB.\n", net_taxi);

    printf("\n--- Housing stats ---\n");
    if (rick.has_house == false) {
        printf("Apartment total spent: %lld RUB.\n", rick_main.housing.total_spent);
        printf("Garage total spent: %lld RUB.\n", rick.garage.total_spent);
    }
    else {
        printf("House total spent: %lld RUB.\n", rick_main.housing.total_spent);
        printf("  Repairs: %lld\n", rick_main.housing.repairs);
        printf("  Furniture: %lld\n", rick_main.housing.furniture);
        printf("  Appliances: %lld\n", rick_main.housing.appliances);
        printf("  Garden: %lld\n", rick_main.housing.garden);
    }

    printf("\n--- Debts ---\n");
    printf("Consumer credit: %lld RUB.\n", rick.tbank.credit);
    printf("Car credit: %lld RUB.\n", rick.bmw_x5.credit);

    printf("\n--- Result ---\n");
    printf("Total capital: %lld RUB.\n", total_capital);
    printf("Total debt: %lld RUB.\n", total_debt);
    printf("Clean capital: %lld RUB\n", clean_capital);
    printf("--------------------------------------------------------------------------\n");
}


void rick_print_results()
{
    printf("\n--------------------- RICK'S LIFE FINANCIAL STATEMENT ---------------------\n");
    printf("Salary: %lld RUB.\n", rick_main.salary);

    RUB bank_capital = 0;
    bank_capital += rick.tbank.account;
    bank_capital += rick.tbank.deposite;
    bank_capital += rick.tbank.account_usd * rick.tbank.rate_usd_rub;
    RUB car_capital = 0;
    car_capital += rick.bmw_x3.value;
    car_capital += rick.bmw_x5.value;

    printf("\n--- ASSETS ---\n");
    printf("Bank: %lld RUB.\n", bank_capital);
    printf("BMW X3: %lld RUB.\n", rick.bmw_x3.value);
    printf("BMW X5: %lld RUB.\n", rick.bmw_x5.value);
    if (rick.has_house == true) {
        printf("House: %lld RUB.\n", rick_main.housing.value);
    }
    RUB total_capital = bank_capital + car_capital;

    printf("\n--- TAX ---\n");
    printf("Total taxes paid: %lld RUB.\n", rick_main.total_taxes_paid);
    printf("Average per year: %lld RUB.\n", rick_main.total_taxes_paid / 24);
    printf("Income tax: ~%lld RUB/year\n", (long long)(rick_main.salary * rick_main.income_tax * 12));
    printf("Car tax: %lld RUB/year (X3: %lld, X5: %lld)\n", rick.bmw_x3.tax + rick.bmw_x5.tax, rick.bmw_x3.tax, rick.bmw_x5.tax);
    if (rick.has_house == true) {
        printf("Property tax: %lld RUB/year\n", rick_main.housing.tax * 12);
    }

    printf("\n--- TAXI STATISTICS ---\n");
    printf("Total earned: %lld RUB.\n", rick.taxi_money);
    printf("Total tips: %lld RUB.\n", rick.taxi_tips);
    printf("Total clients: %d\n", rick.taxi_clients);
    printf("Total expenses: %lld RUB.\n", rick.taxi_expenses);
    RUB net_taxi = rick.taxi_money + rick.taxi_tips - rick.taxi_expenses;
    printf("Net taxi profit: %lld RUB.\n", net_taxi);
    printf("Average per year: %lld RUB.\n", net_taxi / 24);

    printf("\n--- DEBTS ---\n");
    printf("Consumer credit: %lld RUB.\n", rick.tbank.credit);
    printf("Car credit: %lld RUB.\n", rick.bmw_x5.credit);
    RUB total_debt = rick.tbank.credit + rick.bmw_x5.credit;

    printf("\n--- CAR STATISTICS ---\n");
    printf("BMW X3 - total number of repairs: %lld RUB.\n", rick.bmw_x3.accumulated_repair);
    printf("BMW X5 - total number of repairs: %lld RUB.\n", rick.bmw_x5.accumulated_repair);
    printf("Total Repair Costs: %lld RUB.\n", rick.bmw_x3.accumulated_repair + rick.bmw_x5.accumulated_repair);

    RUB clean_capital = total_capital - total_debt;
    printf("\n--- RESULT ---\n");
    printf("Total capital: %lld RUB.\n", total_capital);
    printf("Total debt: %lld RUB.\n", total_debt);
    printf("Clean capital: %lld RUB.\n", clean_capital);
    printf("--------------------------------------------------------------------------\n");
}


// RESULTS CLIFF
void cliff_print_mid_results(int year)
{
    printf("\n------------------------ %d CLIFF'S YEAR REPORT ------------------------\n", year);

    RUB bank_capital = cliff.vtb.account + cliff.vtb.deposite;
    RUB total_debt = cliff.vtb.credit;
    RUB clean_capital = bank_capital - total_debt;

    RUB net_stunt = cliff.stunt_money + cliff.stunt_bonuses - cliff.stunt_medical_expenses;

    printf("\n--- Assets ---\n");
    printf("Bank: %lld RUB.\n", bank_capital);
    printf("Trailer (rented, no value)\n");

    printf("\n--- Stunt stats ---\n");
    printf("Stunt income: %lld RUB.\n", cliff.stunt_money);
    printf("Bonuses: %lld RUB.\n", cliff.stunt_bonuses);
    printf("Injuries: %d\n", cliff.stunt_injuries);
    printf("Medical expenses: %lld RUB.\n", cliff.stunt_medical_expenses);
    printf("Net stunt profit: %lld RUB.\n", net_stunt);

    printf("\n--- Brandy stats ---\n");
    printf("Total spent on Brandy: %lld RUB.\n", cliff.dog_total_spent);

    printf("\n--- Trailer stats ---\n");
    printf("Total spent: %lld RUB.\n", cliff_main.housing.total_spent);

    printf("\n--- Debts ---\n");
    printf("Consumer credit: %lld RUB.\n", cliff.vtb.credit);

    printf("\n--- Result ---\n");
    printf("Clean capital: %lld RUB\n", clean_capital);
    printf("--------------------------------------------------------------------------\n");
}


void cliff_print_results()
{
    printf("\n-------------------- CLIFF'S LIFE FINANCIAL STATEMENT --------------------\n");
    printf("Salary: %lld RUB.\n", cliff_main.salary);

    RUB bank_capital = cliff.vtb.account + cliff.vtb.deposite;

    printf("\n--- ASSETS ---\n");
    printf("Bank: %lld RUB.\n", bank_capital);
    printf("Trailer (rented, no value)\n");

    printf("\n--- STUNT STATISTICS ---\n");
    printf("Total stunt income: %lld RUB.\n", cliff.stunt_money);
    printf("Total bonuses: %lld RUB.\n", cliff.stunt_bonuses);
    printf("Total injuries: %d\n", cliff.stunt_injuries);
    printf("Medical expenses: %lld RUB.\n", cliff.stunt_medical_expenses);
    RUB net_stunt = cliff.stunt_money + cliff.stunt_bonuses - cliff.stunt_medical_expenses;
    printf("Net stunt profit: %lld RUB.\n", net_stunt);

    printf("\n--- BRANDY STATISTICS ---\n");
    printf("Total spent on Brandy: %lld RUB.\n", cliff.dog_total_spent);
    printf("  - Food: %lld RUB/year\n", cliff.dog_food * 12);
    printf("  - Vet: %lld RUB\n", cliff.dog_vet);

    printf("\n--- TRAILER STATISTICS ---\n");
    printf("Total spent on trailer: %lld RUB.\n", cliff_main.housing.total_spent);
    printf("  - Rent: %lld RUB/year\n", cliff_main.housing.rent * 12);
    printf("  - Utilities: %lld RUB/year\n", cliff_main.housing.utilities * 12);
    printf("  - Repairs: %lld RUB\n", cliff_main.housing.repairs);

    printf("\n--- TAX ---\n");
    printf("Total taxes paid: %lld RUB.\n", cliff_main.total_taxes_paid);

    printf("\n--- DEBTS ---\n");
    printf("Consumer credit: %lld RUB.\n", cliff.vtb.credit);

    RUB clean_capital = bank_capital - cliff.vtb.credit;
    printf("\n--- RESULT ---\n");
    printf("Total capital: %lld RUB.\n", bank_capital);
    printf("Total debt: %lld RUB.\n", cliff.vtb.credit);
    printf("Clean capital: %lld RUB.\n", clean_capital);
    printf("--------------------------------------------------------------------------\n");
}


// SIMULATION RICK
void rick_simulation()
{
    int month = 2;
    int year = 2026;

    while (not (month == 3 and year == 2050)) {
        rick_salary(month, year);
        rick_taxi_work(month, year);
        rick_housing_life(month, year);
        rick_garage_life(month, year);
        rick_freelance(month, year);
        rick_car_bmw_x3(month, year);
        rick_car_bmw_x5(month, year);
        rick_credit(month, year);
        rick_food(month, year);
        rick_deposite(month, year);

        if (month == 12 and year % 5 == 0) {
            rick_print_mid_results(year);
        }

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


// SIMULATION CLIFF
void cliff_simulation()
{
    int month = 2;
    int year = 2026;

    while (not (month == 3 and year == 2050)) {
        cliff_salary(month, year);
        cliff_stunt_work(month, year);
        cliff_food(month, year);
        cliff_dog_life(month, year);
        cliff_trailer_life(month, year);
        cliff_credit(month, year);
        cliff_deposite(month, year);

        if (month == 12 and year % 5 == 0) {
            cliff_print_mid_results(year);
        }

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    srand(time(NULL));

    printf("\n=================================================== RICK'S LIFE ===================================================\n");
    rick_init();
    rick_simulation();
    rick_print_results();

    printf("\n================================================== CLIFF'S LIFE ==================================================\n");
    cliff_init();
    cliff_simulation();
    cliff_print_results();

    return 0;
}