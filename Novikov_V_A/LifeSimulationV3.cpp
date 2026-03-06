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
    int months_since_service;  // время с посл. ТО

    RUB tax;
};

struct Apartment {
    RUB rent;
    RUB utilities; // коммуналка
    RUB internet;
    RUB repairs;
    RUB furniture;
    RUB appliances;
    RUB total_spent;
};

struct Garage {
    RUB rent;
    RUB electricity;
    RUB repairs;
    RUB total_spent;
};

struct House {
    RUB value;
    RUB credit;
    RUB credit_payment;
    Percent credit_interest;
    RUB utilities;
    RUB heating;
    RUB internet;
    RUB repairs;
    RUB furniture;
    RUB appliances;
    RUB garden;
    RUB tax;
    RUB total_spent;
    int year_bought;
};

struct Person {
    Bank tbank;
    Car bmw_x3;
    Car bmw_x5;
    RUB salary;
    RUB food;
    RUB taxi_income_per_hour;
    int taxi_hours_per_week;
    RUB taxi_money;
    RUB taxi_tips;
    int taxi_clients;
    RUB taxi_expenses;
    RUB total_taxes_paid;
    RUB income_tax;
    Apartment apartment;
    Garage garage;
    House house; // купит в 2036
    bool has_house; // наличие дома
};

struct Person rick;
// struct Person cliff;


void rick_init()
{
    // BANK
    rick.tbank.account = 0;
    rick.salary = 300'000;
    rick.tbank.account_usd = 0;
    rick.tbank.rate_usd_rub = 80.0;
    rick.tbank.deposite = 100'000;
    rick.tbank.deposite_interest = 8.0;
    rick.tbank.credit = 1'000'000;
    rick.tbank.credit_limit = 5'000'000;
    rick.tbank.credit_interest = 21.0;
    rick.tbank.total_spent = 0;
    rick.tbank.total_earned = 0;
    rick.total_taxes_paid = 0;
    rick.income_tax = 0.13;

    // FOOD
    rick.food = 30'000;

    // TAXI JOB
    rick.taxi_income_per_hour = 500;
    rick.taxi_hours_per_week = 15;
    rick.taxi_money = 0;
    rick.taxi_tips = 0;
    rick.taxi_clients = 0;
    rick.taxi_expenses = 0;
    
    // APARTAMENT
    rick.apartment.rent = 35'000;
    rick.apartment.utilities = 7'000;
    rick.apartment.internet = 1'000;
    rick.apartment.repairs = 0;
    rick.apartment.furniture = 0;
    rick.apartment.appliances = 0;
    rick.apartment.total_spent = 0;

    // GARAGE
    rick.garage.rent = 5'000;
    rick.garage.electricity = 500;
    rick.garage.repairs = 0;
    rick.garage.total_spent = 0;

    // HOUSE
    rick.house.value = 0;
    rick.house.credit = 0;
    rick.house.credit_payment = 0;
    rick.house.credit_interest = 0;
    rick.house.utilities = 0;
    rick.house.heating = 0;
    rick.house.internet = 0;
    rick.house.repairs = 0;
    rick.house.furniture = 0;
    rick.house.appliances = 0;
    rick.house.garden = 0;
    rick.house.tax = 0;
    rick.house.total_spent = 0;
    rick.house.year_bought = 0;
    rick.has_house = false;

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


void rick_salary(const int month, const int year)
{
    if (month == 12) {
        rick.tbank.account += rick.salary; // 13th salary
    }

    if (month == 1 and year == 2027) {
        rick.salary *= 1.5; // promotion
    }

    if (month == 1 and year > 2027) {
        rick.salary = rick.salary * (1.0 + inflation_rate * 0.9); // индексация зп
    }

    rick.tbank.account += rick.salary;
    rick.tbank.total_earned += rick.salary;
}

void rick_taxi_work(const int month, const int year)
{
    int hours_this_month = rick.taxi_hours_per_week * 4;

    RUB base_income = rick.taxi_income_per_hour * hours_this_month;

    int tips_percent = 10 + (rand() % 21);  //случайные чаевые
    RUB tips = base_income * tips_percent / 100;

    int clients = hours_this_month * 2;

    RUB expenses = 3000 + (rand() % 3000);  //случайные расходы

    RUB total_income = base_income + tips;
    RUB clean_income = total_income - expenses;

    rick.taxi_money = rick.taxi_money + base_income;
    rick.taxi_tips = rick.taxi_tips + tips;
    rick.taxi_clients = rick.taxi_clients + clients;
    rick.taxi_expenses = rick.taxi_expenses + expenses;

    rick.tbank.account = rick.tbank.account + clean_income;
    rick.tbank.total_earned = rick.tbank.total_earned + clean_income;
}

void rick_taxi_events(int month, int year)
{
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


void rick_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        rick.tbank.account_usd += 3'000;
    }
}


void rick_pay_taxes(const int month, const int year)
{
    RUB total_tax = 0;

    // Подоходный налог
    RUB monthly_income_tax = rick.salary * rick.income_tax;
    if (rick.tbank.account >= monthly_income_tax) {
        rick.tbank.account -= monthly_income_tax;
        rick.total_taxes_paid += monthly_income_tax;
        rick.tbank.total_spent += monthly_income_tax;
        total_tax += monthly_income_tax;
    }
    else {
        rick.tbank.credit += monthly_income_tax;
        rick.total_taxes_paid += monthly_income_tax;
        rick.tbank.total_spent += monthly_income_tax;
    }

    // Транспортный налог
    if (month == 4) {
        RUB car_tax = rick.bmw_x3.tax + rick.bmw_x5.tax;
        if (rick.tbank.account >= car_tax) {
            rick.tbank.account -= car_tax;
            rick.total_taxes_paid += car_tax;
            rick.tbank.total_spent += car_tax;
            total_tax += car_tax;
        }
        else {
            rick.tbank.credit += car_tax;
            rick.total_taxes_paid += car_tax;
            rick.tbank.total_spent += car_tax;
        }
    }

    // Налог на такси
    if (month == 3 or month == 6 or month == 9 or month == 12) {
        RUB taxi_tax = rick.taxi_money * 0.06 / 4;
        if (rick.tbank.account >= taxi_tax) {
            rick.tbank.account -= taxi_tax;
            rick.total_taxes_paid += taxi_tax;
            rick.tbank.total_spent += taxi_tax;
            total_tax += taxi_tax;
        }
        else {
            rick.tbank.credit += taxi_tax;
            rick.total_taxes_paid += taxi_tax;
            rick.tbank.total_spent += taxi_tax;
        }
    }

    // Налог на дом
    if (month == 12 and rick.has_house == true) {
        RUB property_tax = rick.house.tax;
        if (rick.tbank.account >= property_tax) {
            rick.tbank.account -= property_tax;
            rick.total_taxes_paid += property_tax;
            rick.tbank.total_spent += property_tax;
            total_tax += property_tax;
        }
        else {
            rick.tbank.credit += property_tax;
            rick.total_taxes_paid += property_tax;
            rick.tbank.total_spent += property_tax;
        }
    }
}

void rick_food()
{
    if (rick.tbank.account >= rick.food) {
        rick.tbank.account -= rick.food;
        rick.tbank.total_spent += rick.food;
    }
    else {
        rick.tbank.credit += rick.food - rick.tbank.account;
        rick.tbank.total_spent += rick.food;
        rick.tbank.account = 0;
    }
}


void apply_inflation(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        rick.food = rick.food * (1.0 + inflation_rate);

        rick.bmw_x3.gas_price = rick.bmw_x3.gas_price * (1.0 + inflation_rate * 0.7);
        rick.bmw_x3.gas_month = rick.bmw_x3.gas_month * (1.0 + inflation_rate * 0.7);
        rick.bmw_x3.insurance = rick.bmw_x3.insurance * (1.0 + inflation_rate * 0.8);
        rick.bmw_x3.season_service = rick.bmw_x3.season_service * (1.0 + inflation_rate * 0.6);
        rick.bmw_x3.tire_change = rick.bmw_x3.tire_change * (1.0 + inflation_rate * 0.5);
        rick.bmw_x3.winter_tires = rick.bmw_x3.winter_tires * (1.0 + inflation_rate * 0.7);
        rick.bmw_x3.summer_tires = rick.bmw_x3.summer_tires * (1.0 + inflation_rate * 0.7);
        rick.bmw_x3.random_repair_min = rick.bmw_x3.random_repair_min * (1.0 + inflation_rate);
        rick.bmw_x3.random_repair_max = rick.bmw_x3.random_repair_max * (1.0 + inflation_rate);

        rick.bmw_x5.gas_price = rick.bmw_x5.gas_price * (1.0 + inflation_rate * 0.7);
        rick.bmw_x5.gas_month = rick.bmw_x5.gas_month * (1.0 + inflation_rate * 0.7);
        rick.bmw_x5.insurance = rick.bmw_x5.insurance * (1.0 + inflation_rate * 0.8);
        rick.bmw_x5.season_service = rick.bmw_x5.season_service * (1.0 + inflation_rate * 0.6);
        rick.bmw_x5.tire_change = rick.bmw_x5.tire_change * (1.0 + inflation_rate * 0.5);
        rick.bmw_x5.winter_tires = rick.bmw_x5.winter_tires * (1.0 + inflation_rate * 0.7);
        rick.bmw_x5.summer_tires = rick.bmw_x5.summer_tires * (1.0 + inflation_rate * 0.7);
        rick.bmw_x5.random_repair_min = rick.bmw_x5.random_repair_min * (1.0 + inflation_rate);
        rick.bmw_x5.random_repair_max = rick.bmw_x5.random_repair_max * (1.0 + inflation_rate);
    }
}


void bmw_x3_credit(const int month, const int year)
{
    if (rick.bmw_x3.credit > 0) {
        rick.bmw_x3.credit += rick.bmw_x3.credit * (rick.bmw_x3.credit_interest / 12.0 / 100.0);
        if (rick.tbank.account >= rick.bmw_x3.credit_payment) {
            rick.tbank.account -= rick.bmw_x3.credit_payment;
            rick.bmw_x3.credit -= rick.bmw_x3.credit_payment;
            rick.tbank.total_spent += rick.bmw_x3.credit_payment;
        }
        else {
            rick.tbank.account -= 10000;  // late payment
            rick.tbank.total_spent += 10000;
        }
    }
}

void bmw_x3_gas()
{
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

void bmw_x3_insurance(const int month)
{
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

void bmw_x3_tire_change(const int month)
{
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

void bmw_x3_new_tires(const int month, const int year)
{
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

void bmw_x3_service()
{
    rick.bmw_x3.months_since_service++;
    if (rick.bmw_x3.months_since_service >= 2) {
        RUB service_cost = rick.bmw_x3.season_service;
        if (rick.bmw_x3.age > 5) {  // после 5 лет
            service_cost = service_cost * 1.3;
        }
        if (rick.bmw_x3.age > 10) {  // после 10 лет
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

void bmw_x3_repair()
{
    int random_chance = rand() % 100;
    int repair_chance = rick.bmw_x3.age * 3;  // 3% за каждый год

    if (random_chance < repair_chance) {
        RUB repair_cost = rick.bmw_x3.random_repair_min + (rand() % (rick.bmw_x3.random_repair_max - rick.bmw_x3.random_repair_min));
        if (rick.tbank.account >= repair_cost) {
            rick.tbank.account -= repair_cost;
            rick.tbank.total_spent += repair_cost;
            rick.bmw_x3.accumulated_repair += repair_cost;
        }
        else {
            rick.tbank.credit += repair_cost - rick.tbank.account;  // если денег на ремонт нет, то кредит
            rick.bmw_x3.accumulated_repair += repair_cost;
            rick.tbank.total_spent += repair_cost;
            rick.tbank.account = 0;
        }
    }
}

void bmw_x3_aging(const int month)
{
    if (month == 12) {
        rick.bmw_x3.age++;
        rick.bmw_x3.value = rick.bmw_x3.value * 0.90;  // reduction in cost because old
        rick.bmw_x3.mileage_year += 2000;
    }
}

void rick_car_bmw_x3(const int month, const int year)
{
    bmw_x3_credit(month, year);
    bmw_x3_gas();
    bmw_x3_insurance(month);
    bmw_x3_tire_change(month);
    bmw_x3_new_tires(month, year);
    bmw_x3_service();
    bmw_x3_repair();
    bmw_x3_aging(month);
}

void bmw_x5_credit(const int month, const int year)
{
    if (rick.bmw_x5.credit > 0) {
        rick.bmw_x5.credit += rick.bmw_x5.credit * (rick.bmw_x5.credit_interest / 12.0 / 100.0);
        if (rick.tbank.account >= rick.bmw_x5.credit_payment) {
            rick.tbank.account -= rick.bmw_x5.credit_payment;
            if (rick.bmw_x5.credit >= rick.bmw_x5.credit_payment) {
                rick.bmw_x5.credit -= rick.bmw_x5.credit_payment;
            }
            else {
                RUB overpayment = rick.bmw_x5.credit_payment - rick.bmw_x5.credit;  // возврат при долг < платеж
                rick.bmw_x5.credit = 0;
                rick.tbank.account += overpayment;
            }
            rick.tbank.total_spent += rick.bmw_x5.credit_payment;
        }
        else {
            rick.tbank.account -= 10000;  // late payment
            rick.tbank.total_spent += 10000;
        }
    }
}

void bmw_x5_gas()
{
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

void bmw_x5_insurance(const int month)
{
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

void bmw_x5_tire_change(const int month)
{
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

void bmw_x5_new_tires(const int month, const int year)
{
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

void bmw_x5_service()
{
    rick.bmw_x5.months_since_service++;
    if (rick.bmw_x5.months_since_service >= 2) {
        RUB service_cost = rick.bmw_x5.season_service;
        if (rick.bmw_x5.age > 5) {  // после 5 лет
            service_cost = service_cost * 1.2;
        }
        if (rick.bmw_x5.age > 10) {  // после 10 лет
            service_cost = service_cost * 1.4;
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

void bmw_x5_repair()
{
    int random_chance = rand() % 100;
    int repair_chance = rick.bmw_x5.age * 2;  // 2% за каждый год

    if (random_chance < repair_chance) {
        RUB repair_cost = rick.bmw_x5.random_repair_min +
            (rand() % (rick.bmw_x5.random_repair_max - rick.bmw_x5.random_repair_min));
        if (rick.tbank.account >= repair_cost) {
            rick.tbank.account -= repair_cost;
            rick.tbank.total_spent += repair_cost;
            rick.bmw_x5.accumulated_repair += repair_cost;
        }
        else {
            rick.tbank.credit += repair_cost - rick.tbank.account;  // если денег на ремонт нет, то кредит
            rick.bmw_x5.accumulated_repair += repair_cost;
            rick.tbank.total_spent += repair_cost;
            rick.tbank.account = 0;
        }
    }
}

void bmw_x5_aging(const int month)
{
    if (month == 12) {
        rick.bmw_x5.age++;
        rick.bmw_x5.value = rick.bmw_x5.value * 0.95;  // потеря в цене каждый год
    }
}

void rick_car_bmw_x5(const int month, const int year)
{
    bmw_x5_credit(month, year);
    bmw_x5_gas();
    bmw_x5_insurance(month);
    bmw_x5_tire_change(month);
    bmw_x5_new_tires(month, year);
    bmw_x5_service();
    bmw_x5_repair();
    bmw_x5_aging(month);
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
            rick.tbank.account -= 1000;  // late payment
            rick.tbank.total_spent += 1000;
        }

        if (rick.tbank.credit > 0 && rick.tbank.credit < 5000) {  // проверка малости кредита
            if (rick.tbank.account >= rick.tbank.credit) {  // если хватает сразу
                rick.tbank.account -= rick.tbank.credit;
                rick.tbank.total_spent += rick.tbank.credit;
                rick.tbank.credit = 0;
            }
            else {
                rick.tbank.credit -= rick.tbank.account;  // хватает частично
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


void rick_apartment_life(const int month, const int year)
{
    if (rick.has_house == true) {
        return;  // если дом есть, квартиру не снимает
    }

    rick.tbank.account -= rick.apartment.rent;
    rick.apartment.total_spent += rick.apartment.rent;
    rick.tbank.total_spent += rick.apartment.rent;

    RUB utilities_cost = rick.apartment.utilities;
    if (month == 1 or month == 2 or month == 12) {
        utilities_cost = utilities_cost * 1.3;  // зимой +30%
    }
    rick.tbank.account -= utilities_cost;
    rick.apartment.total_spent += utilities_cost;
    rick.tbank.total_spent += utilities_cost;

    rick.tbank.account -= rick.apartment.internet;
    rick.apartment.total_spent += rick.apartment.internet;
    rick.tbank.total_spent += rick.apartment.internet;

    int event_chance = rand() % 100;
    if (event_chance < 10) {
        int apart_event = (month + year) % 6;

        switch (apart_event) {
        case 0:
            printf("[APARTMENT]: The faucet is broken. Call a plumber -3000 RUB\n");
            rick.tbank.account -= 3000;
            rick.apartment.repairs += 3000;
            rick.apartment.total_spent += 3000;
            rick.tbank.total_spent += 3000;
            break;
        case 1:
            printf("[APARTMENT]: Buying a new light fixture for the room -2500 RUB\n");
            rick.tbank.account -= 2500;
            rick.apartment.furniture += 2500;
            rick.apartment.total_spent += 2500;
            rick.tbank.total_spent += 2500;
            break;
        case 2:
            printf("[APARTMENT]: The kettle burned out. Buying a new one -2000 RUB\n");
            rick.tbank.account -= 2000;
            rick.apartment.appliances += 2000;
            rick.apartment.total_spent += 2000;
            rick.tbank.total_spent += 2000;
            break;
        case 3:
            printf("[APARTMENT]: Neighbors flooded. Ceiling repair -8000 RUB\n");
            rick.tbank.account -= 8000;
            rick.apartment.repairs += 8000;
            rick.apartment.total_spent += 8000;
            rick.tbank.total_spent += 8000;
            break;
        case 4:
            printf("[APARTMENT]: Buying a new mattress -7000 RUB\n");
            rick.tbank.account -= 7000;
            rick.apartment.furniture += 7000;
            rick.apartment.total_spent += 7000;
            rick.tbank.total_spent += 7000;
            break;
        case 5:
            printf("[APARTMENT]: The landlord raised the rent! Extra charge -5000 RUB\n");
            rick.tbank.account -= 5000;
            rick.apartment.rent += 5000;
            rick.apartment.total_spent += 5000;
            rick.tbank.total_spent += 5000;
            break;
        }
    }
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


void rick_buy_house(int month, int year)
{
    if (year == 2036 and month == 6 and rick.has_house == false) {
        printf("\n========== RICK BUYS A HOUSE! ==========\n");

        RUB house_price = 15'000'000;

        if (rick.tbank.deposite >= house_price) {
            rick.tbank.deposite -= house_price;
            rick.house.value = house_price;
            rick.house.year_bought = year;

            rick.house.utilities = 10'000;
            rick.house.heating = 5'000; // отопление
            rick.house.internet = 1'500;
            rick.house.garden = 3'000;
            rick.house.tax = house_price * 0.01 / 12;

            rick.has_house = true;

            printf("The house was purchased for %lld RUB!\n", house_price);
            printf("========================================\n\n");
        }
        else {
            printf("Not enough money for a house!\n");
        }
    }
}


void rick_house_life(const int month, const int year)
{
    if (rick.has_house == false) {
        return;
    }

    RUB utilities_cost = rick.house.utilities;
    rick.tbank.account -= utilities_cost;
    rick.house.total_spent += utilities_cost;
    rick.tbank.total_spent += utilities_cost;

    if (month == 1 or month == 2 or month == 3 or month == 10 or month == 11 or month == 12) {
        rick.tbank.account -= rick.house.heating;
        rick.house.total_spent += rick.house.heating;
        rick.tbank.total_spent += rick.house.heating;
    }

    rick.tbank.account -= rick.house.internet;
    rick.house.total_spent += rick.house.internet;
    rick.tbank.total_spent += rick.house.internet;

    if (month >= 4 and month <= 9) {
        rick.tbank.account -= rick.house.garden;
        rick.house.total_spent += rick.house.garden;
        rick.tbank.total_spent += rick.house.garden;
    }

    int event_chance = rand() % 100;
    if (event_chance < 15) {
        int house_event = (month + year * 2) % 12;

        switch (house_event) {
        case 0:
            printf("[HOUSE]: The roof is leaking.Repairs needed - 25000 RUB\n");
            rick.tbank.account -= 25000;
            rick.house.repairs += 25000;
            rick.house.total_spent += 25000;
            rick.tbank.total_spent += 25000;
            break;
        case 1:
            printf("[HOUSE]: Buying a new washing machine - 40000 RUB\n");
            rick.tbank.account -= 40000;
            rick.house.appliances += 40000;
            rick.house.total_spent += 40000;
            rick.tbank.total_spent += 40000;
            break;
        case 2:
            printf("[HOUSE]: Heating boiler replacement -60000 RUB\n");
            rick.tbank.account -= 60000;
            rick.house.repairs += 60000;
            rick.house.total_spent += 60000;
            rick.tbank.total_spent += 60000;
            break;
        case 3:
            printf("[HOUSE]: Buying new furniture for the living room -80000 RUB\n");
            rick.tbank.account -= 80000;
            rick.house.furniture += 80000;
            rick.house.total_spent += 80000;
            rick.tbank.total_spent += 80000;
            break;
        case 4:
            printf("[HOUSE]: A pipe burst. Urgent repairs needed -35000 RUB\n");
            rick.tbank.account -= 35000;
            rick.house.repairs += 35000;
            rick.house.total_spent += 35000;
            rick.tbank.total_spent += 35000;
            break;
        case 5:
            printf("[HOUSE]: Planted new trees in the garden -15000 RUB\n");
            rick.tbank.account -= 15000;
            rick.house.garden += 15000;
            rick.house.total_spent += 15000;
            rick.tbank.total_spent += 15000;
            break;
        case 6:
            printf("[HOUSE]: Replacing windows with plastic ones -90000 RUB\n");
            rick.tbank.account -= 90000;
            rick.house.repairs += 90000;
            rick.house.total_spent += 90000;
            rick.tbank.total_spent += 90000;
            break;
        case 7:
            printf("[HOUSE]: Buying a lawn mower -25000 RUB\n");
            rick.tbank.account -= 25000;
            rick.house.garden += 25000;
            rick.house.total_spent += 25000;
            rick.tbank.total_spent += 25000;
            break;
        case 8:
            printf("[HOUSE]: Buying a new refrigerator -55000 RUB\n");
            rick.tbank.account -= 55000;
            rick.house.appliances += 55000;
            rick.house.total_spent += 55000;
            rick.tbank.total_spent += 55000;
            break;
        }
    }
}


void print_mid_results(int year)
{
    printf("\n---------- %d YEAR REPORT ----------\n", year);

    RUB bank_capital = 0;
    bank_capital += rick.tbank.account;
    bank_capital += rick.tbank.deposite;
    bank_capital += rick.tbank.account_usd * rick.tbank.rate_usd_rub;

    RUB car_capital = 0;
    car_capital += rick.bmw_x3.value;
    car_capital += rick.bmw_x5.value;

    RUB total_capital = bank_capital + car_capital;
    if (rick.has_house == true) {
        total_capital += rick.house.value;
    }
    RUB total_debt = rick.tbank.credit + rick.bmw_x5.credit;
    RUB clean_capital = total_capital - total_debt;

    RUB net_taxi = rick.taxi_money + rick.taxi_tips - rick.taxi_expenses;

    printf("\n--- Assets ---\n");
    printf("Bank: %lld RUB.\n", bank_capital);
    printf("BMW X3: %lld RUB.\n", rick.bmw_x3.value);
    printf("BMW X5: %lld RUB.\n", rick.bmw_x5.value);
    if (rick.has_house == true) {
        printf("House: %lld RUB.\n", rick.house.value);
    }
    printf("\n--- Taxi stats ---\n");
    printf("Taxi earned: %lld RUB.\n", rick.taxi_money);
    printf("Taxi tips: %lld RUB.\n", rick.taxi_tips);
    printf("Taxi clients: %d\n", rick.taxi_clients);
    printf("Taxi expenses: %lld RUB.\n", rick.taxi_expenses);
    printf("Net taxi income: %lld RUB.\n", net_taxi);

    printf("\n--- Housing stats ---\n");
    if (rick.has_house == false) {
        printf("Apartment total spent: %lld RUB.\n", rick.apartment.total_spent);
        printf("Garage total spent: %lld RUB.\n", rick.garage.total_spent);
    }
    else {
        printf("House total spent: %lld RUB.\n", rick.house.total_spent);
        printf("  Repairs: %lld\n", rick.house.repairs);
        printf("  Furniture: %lld\n", rick.house.furniture);
        printf("  Appliances: %lld\n", rick.house.appliances);
        printf("  Garden: %lld\n", rick.house.garden);
    }

    printf("\n--- Debts ---\n");
    printf("Consumer credit: %lld RUB.\n", rick.tbank.credit);
    printf("Car credit: %lld RUB.\n", rick.bmw_x5.credit);
    if (rick.house.credit > 0) {
        printf("House credit: %lld RUB.\n", rick.house.credit);
    }

    printf("\n--- Result ---\n");
    printf("Total capital: %lld RUB.\n", total_capital);
    printf("Total debt: %lld RUB.\n", total_debt);
    printf("Clean capital: %lld RUB\n", clean_capital);
    printf("------------------------------------\n");
}


void print_results()
{
    printf("\n========== RICK'S LIFE FINANCIAL STATEMENT ==========\n");
    printf("Salary: %lld RUB.\n", rick.salary);

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
        printf("House: %lld RUB.\n", rick.house.value);
    }
    RUB total_capital = bank_capital + car_capital;

    printf("\n--- TAX ---\n");
    printf("Total taxes paid: %lld RUB.\n", rick.total_taxes_paid);
    printf("Average per year: %lld RUB.\n", rick.total_taxes_paid / 24);
    printf("Income tax: ~%lld RUB/year\n", (long long)(rick.salary * rick.income_tax * 12));
    printf("Car tax: %lld RUB/year (X3: %lld, X5: %lld)\n", rick.bmw_x3.tax + rick.bmw_x5.tax, rick.bmw_x3.tax, rick.bmw_x5.tax);
    if (rick.has_house == true) {
        printf("  - Property tax: %lld RUB/year\n", rick.house.tax * 12);
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
}


void simulation()
{
    int month = 2;
    int year = 2026;

    while (not (month == 3 and year == 2050)) {
        rick_salary(month, year);

        rick_taxi_work(month, year);
        int event_chance = rand() % 100;
        if (event_chance < 40) {
            rick_taxi_events(month, year);
        }
        rick_pay_taxes(month, year);
        rick_apartment_life(month, year);
        rick_garage_life(month, year);
        rick_buy_house(month, year);  
        rick_house_life(month, year);
        rick_freelance(month, year);
        apply_inflation(month, year);
        rick_car_bmw_x3(month, year);
        rick_car_bmw_x5(month, year);
        rick_credit(month, year);
        rick_food();
        rick_deposite(month, year);

        if (month == 12 and year % 5 == 0) {
            print_mid_results(year);
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

    rick_init();

    simulation();

    print_results();

    return 0;
}