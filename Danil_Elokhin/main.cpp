#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using RUB = long long int;
using percent = double;
using chance = double;

// ---------- Структуры данных ----------
struct Car 
{
    RUB value;
    RUB fuel_price;
    float fuel_consumption;
    RUB annual_car_tax;
    RUB insurance_osago;
    RUB insurance_kasko;
    RUB maintenance_cost_per_year;
    float depreciation_percent;
};


struct Home 
{
    RUB value;
    RUB monthly_rent;           
    double rent_indexation;      
    RUB security_deposit;        
    RUB utilities;               
    RUB parking_lot;            
};


struct Job 
{
    RUB salary;
    chance fire_probability;
    chance raise_probability;
    chance annual_raise_percent;
    int raise_month;
};


struct Deposit 
{
    RUB amount;
    percent annual_rate;
    int months_left;
};


struct Credit {
    RUB principal;          
    RUB monthly_payment;    
    percent interest_rate;   
    int months_left;
};

struct Investment 
{
    RUB amount;           
    percent expected_return; 
    percent volatility;     
    RUB total_dividends;   
};


struct Report 
{
    int year;
    RUB net_worth;
    RUB cash;
    RUB deposit;
    RUB car_value;
    RUB rent_paid;              
    RUB property_tax_paid;       
    RUB stress_index;
    RUB investment_value;        
    RUB credit_remaining;
};


struct Person 
{
    int age;
    int birthday_month;

    Job job;
    RUB cash;

    RUB food;
    percent food_indexation;

    RUB mobile_services;
    percent mobile_indexation;

    RUB healthcare;
    percent healthcare_indexation;

    RUB entertainment;
    percent entertainment_indexation;

    RUB clothing;
    percent clothing_indexation;

    RUB sport;
    percent sport_indexation;

    RUB pets;                     
    percent pets_indexation;

    RUB subscriptions;            
    percent subscriptions_indexation;

    RUB unexpected;              

    Car camry;
    Car land_cruiser;
    Deposit deposit;
    Credit credit;
    Investment stocks;
    Home flat_to_live;                   
    Home flat_to_rent;                   
    double avg_monthly_mileage;    

    bool is_unemployed;
    int unemployed_months_left;
    RUB stress_index;
    RUB total_rent_paid;           
    RUB total_property_tax_paid;    
    RUB total_rent_income;
    RUB total_credit_paid;          
    RUB total_interest_paid;
};

// ---------- Глобальные переменные ----------
std::vector<Report> report_alice;
std::vector<Report> report_bob;

Person alice;
Person bob;


struct World 
{
    percent inflation_rate;          
    percent crisis_probability;     
    percent crisis_impact_percent;   
    percent housing_price_growth;    
    percent stock_market_volatility; 
};


World world;

// ---------- Инициализация ----------
void world_init() 
{
    world.inflation_rate = 7.5;
    world.crisis_probability = 2.5;
    world.crisis_impact_percent = 20.0;
    world.housing_price_growth = 4.0;
    world.stock_market_volatility = 15.0;
}


void alice_init() 
{
    alice.job.salary = 180'000;
    alice.job.fire_probability = 1.5;
    alice.job.annual_raise_percent = 9.5;
    alice.job.raise_month = 7;

    alice.deposit.amount = 0;
    alice.deposit.annual_rate = 13.5;
    alice.deposit.months_left = 6;

    alice.credit.principal = 0;
    alice.credit.monthly_payment = 0;
    alice.credit.interest_rate = 12.0;
    alice.credit.months_left = 0;


    alice.stocks.amount = 0;
    alice.stocks.expected_return = 12.0;
    alice.stocks.volatility = world.stock_market_volatility;
    alice.stocks.total_dividends = 0;

    alice.age = 30;
    alice.birthday_month = 5;

    alice.cash = 500'000;  

    alice.food = 25'000;
    alice.food_indexation = 1.05;
    alice.mobile_services = 2'000;
    alice.mobile_indexation = 1.03;
    alice.healthcare = 5'000;
    alice.healthcare_indexation = 1.06;
    alice.entertainment = 15'000;
    alice.entertainment_indexation = 1.04;
    alice.clothing = 8'000;
    alice.clothing_indexation = 1.04;
    alice.unexpected = 10'000;
    alice.sport = 3'000;
    alice.sport_indexation = 1.03;
    alice.pets = 5000;  
    alice.pets_indexation = 1.05;
    alice.subscriptions = 1'500;
    alice.subscriptions_indexation = 1.02;

    alice.camry.value = 5'000'000;
    alice.camry.fuel_price = 65;
    alice.camry.fuel_consumption = 11.1;
    alice.camry.annual_car_tax = 18'600;
    alice.camry.insurance_osago = 10'500;
    alice.camry.insurance_kasko = 30'000;
    alice.camry.maintenance_cost_per_year = 15'000;
    alice.camry.depreciation_percent = 5;

    alice.flat_to_live.monthly_rent = 60'000;
    alice.flat_to_live.rent_indexation = 1.04;
    alice.flat_to_live.security_deposit = 60'000;
    alice.flat_to_live.utilities = 7'500;
    alice.flat_to_live.parking_lot = 5'000;

    alice.flat_to_rent.value = 8'000'000;
    alice.flat_to_rent.monthly_rent = 65'000;
    alice.flat_to_rent.rent_indexation = 1.04;
    alice.flat_to_rent.security_deposit = 65'000;
    alice.flat_to_rent.utilities = 8'500;
    alice.flat_to_rent.parking_lot = 6'000;

    alice.avg_monthly_mileage = 1200;  
    alice.is_unemployed = false;
    alice.unemployed_months_left = 0;
    alice.stress_index = 0;
    alice.total_rent_paid = 0;
    alice.total_property_tax_paid = 0;
    alice.total_rent_income = 0;
    alice.total_credit_paid = 0;
    alice.total_interest_paid = 0;
}

void bob_init()
{
    bob.job.salary = 200'000;
    bob.job.fire_probability = 1.5;
    bob.job.annual_raise_percent = 9.5;
    bob.job.raise_month = 6;

    bob.deposit.amount = 0;
    bob.deposit.annual_rate = 13.5;
    bob.deposit.months_left = 12;
    
    bob.credit.principal = 0;
    bob.credit.interest_rate = 12.0;
    bob.credit.months_left = 0;

    bob.stocks.amount = 0;
    bob.stocks.expected_return = 12.0;
    bob.stocks.volatility = world.stock_market_volatility;
    bob.stocks.total_dividends = 0;

    bob.age = 35;
    bob.birthday_month = 8;

    bob.cash = 600'000;

    bob.food = 35'000;
    bob.food_indexation = 1.05;
    bob.mobile_services = 2'000;
    bob.mobile_indexation = 1.03;
    bob.healthcare = 5'000;
    bob.healthcare_indexation = 1.06;
    bob.entertainment = 15'000;
    bob.entertainment_indexation = 1.04;
    bob.clothing = 10'000;
    bob.clothing_indexation = 1.04;
    bob.unexpected = 12'000;
    bob.sport = 5'000;
    bob.sport_indexation = 1.03;
    bob.pets = 7000;
    bob.pets_indexation = 1.05;
    bob.subscriptions = 1'500;
    bob.subscriptions_indexation = 1.02;

    bob.land_cruiser.value = 8'000'000;
    bob.land_cruiser.fuel_price = 65;
    bob.land_cruiser.fuel_consumption = 20.7;
    bob.land_cruiser.annual_car_tax = 40'000;
    bob.land_cruiser.insurance_osago = 17'500;
    bob.land_cruiser.insurance_kasko = 50'000;
    bob.land_cruiser.maintenance_cost_per_year = 15'000;
    bob.land_cruiser.depreciation_percent = 5;

    bob.flat_to_live.monthly_rent = 50'000;
    bob.flat_to_live.rent_indexation = 1.04;
    bob.flat_to_live.security_deposit = 50'000;
    bob.flat_to_live.utilities = 6'500;
    bob.flat_to_live.parking_lot = 7'000;

    bob.avg_monthly_mileage = 1500;
    bob.is_unemployed = false;
    bob.unemployed_months_left = 0;
    bob.stress_index = 0;
    bob.total_rent_paid = 0;
    bob.total_property_tax_paid = 0;
    bob.total_rent_income = 0;
    bob.total_credit_paid = 0;
    bob.total_interest_paid = 0;
}

// ---------- Работа и доходы ----------
void alice_check_job_loss() 
{
    if (alice.is_unemployed) return;

    double monthly_fire_prob = alice.job.fire_probability / 12.0;

    if ((rand() % 10000) / 100.0 < monthly_fire_prob) {
        alice.is_unemployed = true;
        alice.unemployed_months_left = 6;  
        alice.stress_index += 10;
    }
}


void alice_process_unemployment() 
{
    if (!alice.is_unemployed) return;

    alice.job.salary = 0;
    alice.unemployed_months_left--;

    if (alice.unemployed_months_left <= 0) {
        alice.is_unemployed = false;
        alice.job.salary = 150'000;  // находим новую работу с зарплатой ниже
        alice.stress_index -= 5;
    }
    else {
        alice.stress_index += 2;
    }
}


void alice_check_annual_raise(int month) 
{
    if (alice.is_unemployed) return;

    if (month == alice.job.raise_month) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * (1 + alice.job.annual_raise_percent / 100.0));
        alice.stress_index -= 5;
    }
}


void alice_random_bonus() 
{
    if (alice.is_unemployed) return;

    if ((rand() % 100) < 20) {  
        RUB bonus = 30'000 + rand() % 70'000;
        alice.cash += bonus;
        alice.stress_index -= 2;
    }
}


void alice_overtime_pay() 
{
    if (alice.is_unemployed) return;

    if ((rand() % 100) < 25) { 
        RUB overtime = 10'000 + rand() % 30'000;
        alice.cash += overtime;
        alice.stress_index += 1;  
    }
}


void alice_salary_shock() 
{
    if (alice.is_unemployed) return;

    double monthly_crisis_prob = world.crisis_probability / 12.0;
    if ((rand() % 10000) / 100.0 < monthly_crisis_prob) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.85); 
        alice.stress_index += 5;
    }
}


void alice_change_job() 
{
    if (alice.is_unemployed) return;

    if ((rand() % 1000) < 3) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.95);  
        alice.stress_index += 3;
    }
}


void alice_burnout() 
{
    if (alice.stress_index > 60) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.97);
        alice.stress_index += 1;
    }
}


void bob_check_job_loss()
{
    if (bob.is_unemployed) return;

    double monthly_fire_prob = bob.job.fire_probability / 12.0;

    if ((rand() % 10000) / 100.0 < monthly_fire_prob) {
        bob.is_unemployed = true;
        bob.unemployed_months_left = 6;
        bob.stress_index += 10;
    }
}


void bob_process_unemployment()
{
    if (!bob.is_unemployed) return;

    bob.job.salary = 0;
    bob.unemployed_months_left--;
     
    if (bob.unemployed_months_left <= 0) {
        bob.is_unemployed = false;
        bob.job.salary = 170'000;  
        bob.stress_index -= 5;
    }
    else {
        bob.stress_index += 2;
    }
}


void bob_check_annual_raise(int month)
{
    if (bob.is_unemployed) return;

    if (month == bob.job.raise_month) {
        bob.job.salary = static_cast<RUB>(bob.job.salary * (1 + bob.job.annual_raise_percent / 100.0));
        bob.stress_index -= 5;
    }
}


void bob_random_bonus()
{
    if (bob.is_unemployed) return;

    if ((rand() % 100) < 20) {
        RUB bonus = 30'000 + rand() % 70'000;
        bob.cash += bonus;
        bob.stress_index -= 2;
    }
}


void bob_overtime_pay()
{
    if (bob.is_unemployed) return;

    if ((rand() % 100) < 25) {
        RUB overtime = 10'000 + rand() % 30'000;
        bob.cash += overtime;
        bob.stress_index += 1;
    }
}


void bob_salary_shock()
{
    if (bob.is_unemployed) return;

    double monthly_crisis_prob = world.crisis_probability / 12.0;

    if ((rand() % 10000) / 100.0 < monthly_crisis_prob) {
        bob.job.salary = static_cast<RUB>(bob.job.salary * 0.85);
        bob.stress_index += 5;
    }
}


void bob_change_job()
{
    if (bob.is_unemployed) return;

    if ((rand() % 1000) < 3) {
        bob.job.salary = static_cast<RUB>(bob.job.salary * 0.95);
        bob.stress_index += 3;
    }
}


void bob_burnout()
{
    if (bob.stress_index > 60) {
        bob.job.salary = static_cast<RUB>(bob.job.salary * 0.97);
        bob.stress_index += 1;
    }
}


// ---------- Расходы (с инфляцией) ----------
void alice_pay_food() 
{
    RUB cost = static_cast<RUB>(alice.food * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.cash -= cost;

    if (alice.cash < 0) alice.stress_index += 2;
}


void alice_pay_mobile() 
{
    RUB cost = static_cast<RUB>(alice.mobile_services * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.cash -= cost;

    if (alice.cash < 0) alice.stress_index += 1;
}


void alice_pay_healthcare() 
{
    RUB cost = static_cast<RUB>(alice.healthcare * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.cash -= cost;

    if (alice.cash < 0) alice.stress_index += 2;
}


void alice_pay_entertainment()
{
    RUB cost = static_cast<RUB>(alice.entertainment * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.cash -= cost;

    if (alice.cash < 0) alice.stress_index += 1;
}


void alice_pay_clothing() 
{
    RUB cost = static_cast<RUB>(alice.clothing * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.cash -= cost;

    if (alice.cash < 0) alice.stress_index += 1;
}


void alice_pay_unexpected() 
{
    RUB cost = static_cast<RUB>(alice.unexpected * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.cash -= cost;

    if (alice.cash < 0) alice.stress_index += 2;
}


void alice_pay_sport() 
{
    RUB cost = static_cast<RUB>(alice.sport * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.cash -= cost;

    if (alice.cash < 0) alice.stress_index += 1;
}


void alice_pay_pets() 
{
    RUB cost = static_cast<RUB>(alice.pets * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.cash -= cost;

    if (alice.cash < 0) alice.stress_index += 2;
}


void alice_pay_subscriptions() 
{
    RUB cost = static_cast<RUB>(alice.subscriptions * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.cash -= cost;

    if (alice.cash < 0) alice.stress_index += 1;
}


void bob_pay_food()
{
    RUB cost = static_cast<RUB>(bob.food * (1 + world.inflation_rate / 100.0 / 12.0));
    bob.cash -= cost;

    if (bob.cash < 0) bob.stress_index += 2;
}


void bob_pay_mobile()
{
    RUB cost = static_cast<RUB>(bob.mobile_services * (1 + world.inflation_rate / 100.0 / 12.0));
    bob.cash -= cost;

    if (bob.cash < 0) bob.stress_index += 1;
}


void bob_pay_healthcare()
{
    RUB cost = static_cast<RUB>(bob.healthcare * (1 + world.inflation_rate / 100.0 / 12.0));
    bob.cash -= cost;

    if (bob.cash < 0) bob.stress_index += 2;
}


void bob_pay_entertainment()
{
    RUB cost = static_cast<RUB>(bob.entertainment * (1 + world.inflation_rate / 100.0 / 12.0));
    bob.cash -= cost;

    if (bob.cash < 0) bob.stress_index += 1;
}


void bob_pay_clothing()
{
    RUB cost = static_cast<RUB>(bob.clothing * (1 + world.inflation_rate / 100.0 / 12.0));
    bob.cash -= cost;

    if (bob.cash < 0) bob.stress_index += 1;
}


void bob_pay_unexpected()
{
    RUB cost = static_cast<RUB>(bob.unexpected * (1 + world.inflation_rate / 100.0 / 12.0));
    bob.cash -= cost;

    if (bob.cash < 0) bob.stress_index += 2;
}


void bob_pay_sport()
{
    RUB cost = static_cast<RUB>(bob.sport * (1 + world.inflation_rate / 100.0 / 12.0));
    bob.cash -= cost;

    if (bob.cash < 0) bob.stress_index += 1;
}


void bob_pay_pets()
{
    RUB cost = static_cast<RUB>(bob.pets * (1 + world.inflation_rate / 100.0 / 12.0));
    bob.cash -= cost;

    if (bob.cash < 0) bob.stress_index += 2;
}


void bob_pay_subscriptions()
{
    RUB cost = static_cast<RUB>(bob.subscriptions * (1 + world.inflation_rate / 100.0 / 12.0));
    bob.cash -= cost;

    if (bob.cash < 0) bob.stress_index += 1;
}


// ---------- Расходы на жильё (flat_to_live) ----------
void alice_pay_rent(int month) 
{
    RUB rent = alice.flat_to_live.monthly_rent;
    alice.cash -= rent;
    alice.total_rent_paid += rent;

    if (month == 12) {
        alice.flat_to_live.monthly_rent = 
            static_cast<RUB>(alice.flat_to_live.monthly_rent * (1 + world.inflation_rate / 100.0 / 12.0));
    }

    if (alice.cash < 0) alice.stress_index += 3;
}


void alice_pay_utilities(int month) 
{
    
    RUB utils = alice.flat_to_live.utilities;
    alice.cash -= utils;

    if (month == 12) {
        alice.flat_to_live.utilities =
            static_cast<RUB>(alice.flat_to_live.utilities * (1 + world.inflation_rate / 100.0));
    }

    if (alice.cash < 0) alice.stress_index += 2;
}


void alice_pay_parking(int(month)) 
{
    RUB parking = alice.flat_to_live.parking_lot;
    alice.cash -= parking;

    if (month == 12) {
        alice.flat_to_live.parking_lot =
            static_cast<RUB>(alice.flat_to_live.parking_lot * (1 + world.inflation_rate / 100.0));
    }

    if (alice.cash < 0) alice.stress_index += 1;
}


void bob_pay_rent(int month)
{
    RUB rent = bob.flat_to_live.monthly_rent;
    bob.cash -= rent;
    bob.total_rent_paid += rent;

    if (month == 12) {
        bob.flat_to_live.monthly_rent = 
            static_cast<RUB>(bob.flat_to_live.monthly_rent * (1 + world.inflation_rate / 100.0 / 12.0));
    }

    if (bob.cash < 0) bob.stress_index += 3;
}


void bob_pay_utilities(int month)
{
    RUB utils = bob.flat_to_live.utilities;
    bob.cash -= utils;

    if (month == 12) {
        bob.flat_to_live.utilities =
            static_cast<RUB>(bob.flat_to_live.utilities * (1 + world.inflation_rate / 100.0 / 12.0));
    }

    if (bob.cash < 0) bob.stress_index += 2;
}


void bob_pay_parking(int(month))
{
    RUB parking = bob.flat_to_live.parking_lot;
    bob.cash -= parking;

    if (month == 12) {
        bob.flat_to_live.parking_lot =
            static_cast<RUB>(bob.flat_to_live.parking_lot * (1 + world.inflation_rate / 100.0 / 12.0));
    }


    if (bob.cash < 0) bob.stress_index += 1;
}


// ---------- Доходы и расходы от сдаваемой квартиры (flat_to_rent) ----------
void alice_receive_rent(int month) 
{
    RUB rent_income = alice.flat_to_rent.monthly_rent;
    alice.cash += rent_income;
    alice.total_rent_income += rent_income;

    RUB utils = alice.flat_to_rent.utilities;
    RUB parking = alice.flat_to_rent.parking_lot;
    alice.cash -= utils;
    alice.cash -= parking;

    if (month == 12) {
        alice.flat_to_rent.monthly_rent = 
            static_cast<RUB>(alice.flat_to_rent.monthly_rent * (1 + world.inflation_rate / 100.0 / 12.0));
        alice.flat_to_rent.value =
            static_cast<RUB>(alice.flat_to_rent.value * (1 + world.inflation_rate / 100.0));
        alice.flat_to_rent.utilities =
            static_cast<RUB>(alice.flat_to_rent.utilities * (1 + world.inflation_rate / 100.0));
        alice.flat_to_rent.parking_lot =
            static_cast<RUB>(alice.flat_to_rent.parking_lot * (1 + world.inflation_rate / 100.0));
    }
    

    if (alice.cash < 0) alice.stress_index += 2;
}


void alice_pay_property_tax(int(month))
{
    RUB apartment_value = alice.flat_to_rent.value; 
    RUB tax = static_cast<RUB>(apartment_value * 0.003); 
    
    if (month == 12) {
        alice.cash -= tax ;  
        alice.total_property_tax_paid += tax ;
    }
    
    if (alice.cash < 0) alice.stress_index += 2;
}


// ---------- Расходы на автомобиль ----------
void alice_pay_fuel() 
{
    RUB fuel_cost = static_cast<RUB>((alice.avg_monthly_mileage / 100.0) *
        alice.camry.fuel_consumption *
        alice.camry.fuel_price *
        (1 + world.inflation_rate / 100.0 / 12.0));
    alice.cash -= fuel_cost;

    if (alice.cash < 0) alice.stress_index += 2;
}


void alice_pay_car_tax(int month) 
{
    RUB tax = alice.camry.annual_car_tax;

    if (month == 12) {
        alice.cash -= tax;
    }

    if (alice.cash < 0) alice.stress_index += 1;
}


void alice_pay_insurance_osago(int month) 
{
    RUB insurance = alice.camry.insurance_osago;
    
    if (month == 12) {
        alice.cash -= insurance;
        alice.camry.insurance_osago =
            static_cast<RUB>(alice.camry.insurance_osago * (1 + world.inflation_rate / 100.0));
    }

    if (alice.cash < 0) alice.stress_index += 1;
}


void alice_pay_insurance_kasko(int month) 
{
    RUB insurance = alice.camry.insurance_kasko ;
    
    if (month == 12) {
        alice.cash -= insurance;
        alice.camry.insurance_kasko =
            static_cast<RUB>(alice.camry.insurance_kasko * (1 + world.inflation_rate / 100.0));
    }

    if (alice.cash < 0) alice.stress_index += 2;
}


void alice_pay_maintenance() 
{
    RUB maintenance = static_cast<RUB>(alice.camry.maintenance_cost_per_year * (1 + world.inflation_rate / 100.0 ));
    alice.cash -= maintenance / 12;

    if (alice.cash < 0) alice.stress_index += 1;
}


void alice_depreciate_car(int month) 
{
    percent depreciate = alice.camry.depreciation_percent / 100.0;
    if (month == 12) {
        alice.camry.value = static_cast<RUB>(alice.camry.value * (1.0 - depreciate));

    }
}




void bob_pay_fuel()
{
    RUB fuel_cost = static_cast<RUB>((bob.avg_monthly_mileage / 100.0) *
        bob.land_cruiser.fuel_consumption *
        bob.land_cruiser.fuel_price *
        (1 + world.inflation_rate / 100.0 / 12.0));
    bob.cash -= fuel_cost;

    if (bob.cash < 0) bob.stress_index += 2;
}


void bob_pay_car_tax(int month)
{
    RUB tax = bob.land_cruiser.annual_car_tax;

    if (month == 12) {
        bob.cash -= tax;
    }

    if (bob.cash < 0) bob.stress_index += 1;
}


void bob_pay_insurance_osago(int month)
{
    RUB insurance = bob.land_cruiser.insurance_osago;

    if (month == 12) {
        bob.cash -= insurance;
        bob.land_cruiser.insurance_osago =
            static_cast<RUB>(bob.land_cruiser.insurance_osago * (1 + world.inflation_rate / 100.0));
    }

    if (bob.cash < 0) bob.stress_index += 1;
}


void bob_pay_insurance_kasko(int month)
{
    RUB insurance = bob.land_cruiser.insurance_kasko;

    if (month == 12) {
        bob.cash -= insurance;
        bob.land_cruiser.insurance_kasko =
            static_cast<RUB>(bob.land_cruiser.insurance_kasko * (1 + world.inflation_rate / 100.0));
    }

    if (bob.cash < 0) bob.stress_index += 2;
}


void bob_pay_maintenance()
{
    RUB maintenance = static_cast<RUB>(bob.land_cruiser.maintenance_cost_per_year * (1 + world.inflation_rate / 100.0));
    bob.cash -= maintenance / 12;

    if (bob.cash < 0) bob.stress_index += 1;
}


void bob_depreciate_car(int month)
{
    percent depreciate = bob.land_cruiser.depreciation_percent / 100.0;
    if (month == 12) {
        bob.land_cruiser.value = static_cast<RUB>(bob.land_cruiser.value * (1.0 - depreciate));

    }
}



// ---------- Депозит ----------
void alice_update_deposit() 
{
    if (alice.deposit.amount > 0) {

        RUB interest = static_cast<RUB>(alice.deposit.amount * (alice.deposit.annual_rate / 100.0 / 12.0));
        alice.deposit.amount += interest;
        alice.deposit.months_left--;

        if (alice.deposit.months_left <= 0) {
            alice.cash += alice.deposit.amount;
            alice.deposit.amount = 0;

        }
    }

    if (alice.cash > 200'000) {
        RUB to_deposit = std::min(alice.cash / 2, static_cast<RUB>( 500'000));
        alice.cash -= to_deposit;
        alice.deposit.amount += to_deposit;
        alice.deposit.months_left = 12; 
    }
}




void bob_update_deposit()
{
    if (bob.deposit.amount > 0) {

        RUB interest = static_cast<RUB>(bob.deposit.amount * (bob.deposit.annual_rate / 100.0 / 12.0));
        bob.deposit.amount += interest;
        bob.deposit.months_left--;

        if (bob.deposit.months_left <= 0) {
            bob.cash += bob.deposit.amount;
            bob.deposit.amount = 0;

        }
    }

    if (bob.cash > 200'000) {
        RUB to_deposit = std::min(bob.cash / 2, static_cast<RUB>(500'000));
        bob.cash -= to_deposit;
        bob.deposit.amount += to_deposit;
        bob.deposit.months_left = 12;
    }
}


// ---------- Кредит ----------
void alice_take_credit_if_needed() {
    
    if (alice.cash < -100'000 && alice.credit.principal == 0) {
        alice.credit.principal = -alice.cash + 50'000;
        alice.credit.months_left = 24;
        alice.credit.interest_rate = 15.0;
        // Рассчитаем аннуитетный платёж (упрощённо)
        double monthly_rate = alice.credit.interest_rate / 12.0 / 100.0;
        double ann = (monthly_rate * pow(1 + monthly_rate, alice.credit.months_left)) /
            (pow(1 + monthly_rate, alice.credit.months_left) - 1);
        alice.credit.monthly_payment = static_cast<RUB>(alice.credit.principal * ann);
        alice.cash += alice.credit.principal; 
        alice.stress_index += 8;
    }
}

void bob_take_credit_if_needed() {

    if (bob.cash < -100'000 && bob.credit.principal == 0) {
        bob.credit.principal = -bob.cash + 50'000;
        bob.credit.months_left = 24;
        bob.credit.interest_rate = 15.0;
        // Рассчитаем аннуитетный платёж (упрощённо)
        double monthly_rate = bob.credit.interest_rate / 12.0 / 100.0;
        double ann = (monthly_rate * pow(1 + monthly_rate, bob.credit.months_left)) /
            (pow(1 + monthly_rate, bob.credit.months_left) - 1);
        bob.credit.monthly_payment = static_cast<RUB>(bob.credit.principal * ann);
        bob.cash += bob.credit.principal;
        bob.stress_index += 8;
    }
}


void alice_pay_credit() 
{
    if (alice.credit.principal <= 0 || alice.credit.months_left <= 0) return;

    RUB payment = alice.credit.monthly_payment;
    RUB interest = static_cast<RUB>(alice.credit.principal * (alice.credit.interest_rate / 100.0 / 12.0));
    RUB principal_part = payment - interest;

    if (principal_part > alice.credit.principal) principal_part = alice.credit.principal;
    alice.cash -= payment;
    alice.credit.principal -= principal_part;
    alice.total_credit_paid += principal_part;
    alice.total_interest_paid += interest;
    alice.credit.months_left--;

    if (alice.cash < 0) alice.stress_index += 3;

    if (alice.credit.principal < 0) alice.credit.principal = 0;
}

void bob_pay_credit()
{
    if (bob.credit.principal <= 0 || bob.credit.months_left <= 0) return;
    RUB payment = bob.credit.monthly_payment;
    RUB interest = static_cast<RUB>(bob.credit.principal * (bob.credit.interest_rate / 100.0 / 12.0));
    RUB principal_part = payment - interest;

    if (principal_part > bob.credit.principal) principal_part = bob.credit.principal;
    bob.cash -= payment;
    bob.credit.principal -= principal_part;
    bob.total_credit_paid += principal_part;
    bob.total_interest_paid += interest;
    bob.credit.months_left--;

    if (bob.cash < 0) bob.stress_index += 3;

    if (bob.credit.principal < 0) bob.credit.principal = 0;
}

void alice_credit()
{
    alice_take_credit_if_needed();
    alice_pay_credit();
}

void bob_credit()
{
    bob_take_credit_if_needed();
    bob_pay_credit();
}


// ---------- Инвестиции в акции ----------
void alice_invest_in_stocks() 
{
    if (alice.cash > 100'000) {
        RUB invest = std::min(static_cast <RUB>(alice.cash / 3), static_cast <RUB>( 300'000));
        alice.cash -= invest;
        alice.stocks.amount += invest;
    }
}


void alice_apply_stock_return() 
{
    if (alice.stocks.amount <= 0) return;

    percent random_factor = ((rand() % 100) - 100) / 100.0; 
    percent monthly_return = alice.stocks.expected_return / 12.0 / 100.0;
    percent monthly_vol = alice.stocks.volatility / 12.0 / 100.0 * random_factor;
    percent total_return = monthly_return + monthly_vol;
    RUB change = static_cast<RUB>(alice.stocks.amount * total_return);
    alice.stocks.amount += change;

    if (change > 0) 
    {
        
        RUB dividends = static_cast<RUB>(change * 0.3); 
        alice.cash += dividends;
        alice.stocks.total_dividends += dividends;
    }
    else {
        alice.stress_index += 1; 
    }

}


void alice_panic_sell() 
{
    if (alice.stocks.amount > 0 && (rand() % 100) < 3) { 

        RUB loss = static_cast<RUB>(alice.stocks.amount * 0.1); 
        alice.stocks.amount -= loss;
        alice.cash += alice.stocks.amount; 
        alice.stocks.amount = 0;
        alice.stress_index += 5;
    }
}


void alice_rebalance_stocks() 
{
    if (alice.stocks.amount > 500'000) {
        RUB sell = alice.stocks.amount / 4;
        alice.cash += sell;
        alice.stocks.amount -= sell;
    }
}


void alice_investment()
{
    void alice_invest_in_stocks();
    void alice_apply_stock_return();
    void alice_panic_sell();
    void alice_rebalance_stocks();
}




void bob_invest_in_stocks()
{
    if (bob.cash > 100'000) {
        RUB invest = std::min(static_cast <RUB>(bob.cash / 3), static_cast <RUB>(300'000));
        bob.cash -= invest;
        bob.stocks.amount += invest;
    }
}


void bob_apply_stock_return()
{
    if (bob.stocks.amount <= 0) return;

    percent random_factor = ((rand() % 100) - 100) / 100.0;
    percent monthly_return = bob.stocks.expected_return / 12.0 / 100.0;
    percent monthly_vol = bob.stocks.volatility / 12.0 / 100.0 * random_factor;
    percent total_return = monthly_return + monthly_vol;
    RUB change = static_cast<RUB>(bob.stocks.amount * total_return);
    bob.stocks.amount += change;

    if (change > 0) {

        RUB dividends = static_cast<RUB>(change * 0.3);
        bob.cash += dividends;
        bob.stocks.total_dividends += dividends;
    }
    else {
        bob.stress_index += 1;
    }

}


void bob_panic_sell()
{
    if (bob.stocks.amount > 0 && (rand() % 100) < 3) {

        RUB loss = static_cast<RUB>(bob.stocks.amount * 0.1);
        bob.stocks.amount -= loss;
        bob.cash += bob.stocks.amount;
        bob.stocks.amount = 0;
        bob.stress_index += 5;
    }
}


void bob_rebalance_stocks()
{
    if (bob.stocks.amount > 500'000) {
        RUB sell = bob.stocks.amount / 4;
        bob.cash += sell;
        bob.stocks.amount -= sell;
    }
}


void bob_investment()
{
    void bob_invest_in_stocks();
    void bob_apply_stock_return();
    void bob_panic_sell();
    void bob_rebalance_stocks();
}


// ---------- Стресс ----------
void alice_calculate_stress() 
{
    if (alice.cash < 100'000) alice.stress_index += 5;

    if (alice.cash < 0) alice.stress_index += 15;

    if (alice.deposit.amount < 200'000) alice.stress_index += 2;

    if (alice.camry.value < 2'000'000) alice.stress_index += 2; 

    if (alice.stocks.amount < 0) alice.stress_index += 2;

    if (alice.stress_index > 100) alice.stress_index = 100;

    if (alice.stress_index < 0) alice.stress_index = 0;

    if (alice.stress_index > 70 && !alice.is_unemployed) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.98);
    }
    else if (alice.stress_index > 80 && !alice.is_unemployed) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.95);
    }
    else if (alice.stress_index > 90 && !alice.is_unemployed) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.93);
    }
   
}




void bob_calculate_stress()
{
    if (bob.cash < 100'000) bob.stress_index += 5;

    if (bob.cash < 0) bob.stress_index += 15;

    if (bob.deposit.amount < 200'000) bob.stress_index += 2;

    if (bob.land_cruiser.value < 2'000'000) bob.stress_index += 2;

    if (bob.stocks.amount < 0) bob.stress_index += 2;

    if (bob.stress_index > 100) bob.stress_index = 100;

    if (bob.stress_index < 0) bob.stress_index = 0;

    if (bob.stress_index > 70 && !bob.is_unemployed) {
        bob.job.salary = static_cast<RUB>(bob.job.salary * 0.98);
    }
    else if (bob.stress_index > 80 && !bob.is_unemployed) {
        bob.job.salary = static_cast<RUB>(bob.job.salary * 0.95);
    }
    else if (bob.stress_index > 90 && !bob.is_unemployed) {
        bob.job.salary = static_cast<RUB>(bob.job.salary * 0.93);
    }

}


// ---------- Случайные события ----------
void alice_random_medical_expense()
{
    if ((rand() % 100) < 5) { 
        RUB expense = 20'000 + rand() % 80'000;
        expense = static_cast<RUB>(expense * (1 + world.inflation_rate / 100.0));
        alice.cash -= expense;

        alice.stress_index += 3;
    }
}


void alice_random_car_repair() 
{
    if ((rand() % 100) < 4) { 
        RUB repair = 15'000 + rand() % 60'000;
        repair = static_cast<RUB>(repair * (1 + world.inflation_rate / 100.0));
        alice.cash -= repair;

        alice.stress_index += 4;
    }
}


void alice_random_vacation() 
{
    if ((rand() % 100) < 3) { 
        RUB cost = 50'000 + rand() % 150'000;
        cost = static_cast<RUB>(cost * (1 + world.inflation_rate / 100.0));
        alice.cash -= cost;

        alice.stress_index -= 5; 
    }
}


void alice_birthday(int month)
{
    if (month == alice.birthday_month) {
        RUB cost = 20000;
        RUB gifts = rand() % 50'000;
        alice.cash -= cost;
        alice.cash += gifts;
        alice.stress_index -= 7;
    }
}


void alice_random_gift() 
{
    if ((rand() % 100) < 8) { 
        RUB gift = 5'000 + rand() % 20'000;
        alice.cash -= gift;
        alice.stress_index -= 1;
    }
}


void alice_random_inheritance() 
{
    if ((rand() % 1000) < 2) { 
        RUB inheritance = 200'000 + rand() % 800'000;
        alice.cash += inheritance;
        alice.stress_index -= 10;
    }
}


void alice_random_fine() 
{
    if ((rand() % 100) < 2) { 
        RUB fine = 2'000 + rand() % 15'000;
        alice.cash -= fine;
        alice.stress_index += 2;
    }
}


void alice_random_phone_break() 
{
    if ((rand() % 100) < 3) { 
        RUB cost = 30'000 + rand() % 70'000;
        cost = static_cast<RUB>(cost * (1 + world.inflation_rate / 100.0));
        alice.cash -= cost;
        alice.stress_index += 2;
    }
}


void alice_random_household_break() 
{
    if ((rand() % 100) < 4) { 
        RUB cost = 10'000 + rand() % 40'000;
        cost = static_cast<RUB>(cost * (1 + world.inflation_rate / 100.0));
        alice.cash -= cost;
        alice.stress_index += 2;
    }
}


void alice_random_win_lottery() 
{
    if ((rand() % 10000) < 1) { 
        RUB win = 1'000'000 + rand() % 5'000'000;
        alice.cash += win;
        alice.stress_index -= 20;
    }
}


void alice_random_theft() 
{
    if ((rand() % 1000) < 1) {
        RUB loss = 50'000 + rand() % 200'000;
        alice.cash -= loss;
        alice.stress_index += 8;
    }
}




void bob_random_medical_expense()
{
    if ((rand() % 100) < 5) {
        RUB expense = 20'000 + rand() % 80'000;
        expense = static_cast<RUB>(expense * (1 + world.inflation_rate / 100.0));
        bob.cash -= expense;

        bob.stress_index += 3;
    }
}


void bob_random_car_repair()
{
    if ((rand() % 100) < 4) {
        RUB repair = 15'000 + rand() % 60'000;
        repair = static_cast<RUB>(repair * (1 + world.inflation_rate / 100.0));
        bob.cash -= repair;

        bob.stress_index += 4;
    }
}


void bob_random_vacation()
{
    if ((rand() % 100) < 3) {
        RUB cost = 50'000 + rand() % 150'000;
        cost = static_cast<RUB>(cost * (1 + world.inflation_rate / 100.0));
        bob.cash -= cost;

        bob.stress_index -= 5;
    }
}


void bob_birthday(int month)
{
    if (month == bob.birthday_month) {
        RUB cost = 20000;
        RUB gifts = rand() % 50'000;
        bob.cash -= cost;
        bob.cash += gifts;
        bob.stress_index -= 7;
    }
}


void bob_random_gift()
{
    if ((rand() % 100) < 8) {
        RUB gift = 5'000 + rand() % 20'000;
        bob.cash -= gift;
        bob.stress_index -= 1;
    }
}


void bob_random_inheritance()
{
    if ((rand() % 1000) < 2) {
        RUB inheritance = 200'000 + rand() % 800'000;
        bob.cash += inheritance;
        bob.stress_index -= 10;
    }
}


void bob_random_fine()
{
    if ((rand() % 100) < 2) {
        RUB fine = 2'000 + rand() % 15'000;
        bob.cash -= fine;
        bob.stress_index += 2;
    }
}


void bob_random_phone_break()
{
    if ((rand() % 100) < 3) {
        RUB cost = 30'000 + rand() % 70'000;
        cost = static_cast<RUB>(cost * (1 + world.inflation_rate / 100.0));
        bob.cash -= cost;
        bob.stress_index += 2;
    }
}


void bob_random_household_break()
{
    if ((rand() % 100) < 4) {
        RUB cost = 10'000 + rand() % 40'000;
        cost = static_cast<RUB>(cost * (1 + world.inflation_rate / 100.0));
        bob.cash -= cost;
        bob.stress_index += 2;
    }
}


void bob_random_win_lottery()
{
    if ((rand() % 10000) < 1) {
        RUB win = 1'000'000 + rand() % 5'000'000;
        bob.cash += win;
        bob.stress_index -= 20;
    }
}


void bob_random_theft()
{
    if ((rand() % 1000) < 1) {
        RUB loss = 50'000 + rand() % 200'000;
        bob.cash -= loss;
        bob.stress_index += 8;
    }
}



void alice_check_crisis() 
{

    if ((rand() % 100) < world.crisis_probability) {
        alice.flat_to_rent.monthly_rent = 
            static_cast<RUB>(alice.flat_to_rent.monthly_rent * (1 - world.crisis_impact_percent / 100.0));
        alice.flat_to_rent.value = 
            static_cast<RUB>(alice.flat_to_rent.value * (1 - world.crisis_impact_percent / 100.0));
        alice.camry.value = 
            static_cast<RUB>(alice.camry.value * (1 - world.crisis_impact_percent / 100.0));
        alice.stress_index += 15;
    }
}


void bob_check_crisis()
{

    if ((rand() % 100) < world.crisis_probability) {

        bob.flat_to_rent.monthly_rent = static_cast<RUB>(bob.flat_to_rent.monthly_rent * (1 - world.crisis_impact_percent / 100.0));
        bob.flat_to_rent.value = static_cast<RUB>(bob.flat_to_rent.value * (1 - world.crisis_impact_percent / 100.0));
        bob.land_cruiser.value = static_cast<RUB>(bob.land_cruiser.value * (1 - world.crisis_impact_percent / 100.0));
        bob.stress_index += 15;
    }
}

// ---------- Чистая стоимость и отчёт ----------
RUB alice_calculate_net_worth() 
{
    RUB assets = alice.cash + alice.deposit.amount + alice.camry.value + alice.flat_to_rent.value + alice.stocks.amount;
    RUB liabilities = alice.credit.principal;
    return assets - liabilities;
}


RUB bob_calculate_net_worth()
{
    RUB assets = bob.cash + bob.deposit.amount + bob.land_cruiser.value + bob.flat_to_rent.value + bob.stocks.amount;
    RUB liabilities = bob.credit.principal;
    return assets - liabilities;
}


void alice_make_report(int year, int month, const int end_year, const int end_month) 
{   
    if ((month == 12)||((year == end_year)&&(month == end_month))){
        Report report;
        report.year = year;
        report.net_worth = alice_calculate_net_worth();
        report.cash = alice.cash;
        report.deposit = alice.deposit.amount;
        report.car_value = alice.camry.value;
        report.rent_paid = alice.total_rent_paid;
        report.property_tax_paid = alice.total_property_tax_paid;
        report.stress_index = alice.stress_index;
        report.investment_value = alice.stocks.amount;
        report.credit_remaining = alice.credit.principal;

        alice.total_rent_paid = 0;
        alice.total_property_tax_paid = 0;

        report_alice.push_back(report);
    }
    

}


void bob_make_report(int year, int month, const int end_year, const int end_month)
{
    if ((month == 12) || ((year == end_year) && (month == end_month))) {
        Report report;
        report.year = year;
        report.net_worth = bob_calculate_net_worth();
        report.cash = bob.cash;
        report.deposit = bob.deposit.amount;
        report.car_value = bob.land_cruiser.value;
        report.rent_paid = bob.total_rent_paid;
        report.property_tax_paid = bob.total_property_tax_paid;
        report.stress_index = bob.stress_index;
        report.investment_value = alice.stocks.amount;
        report.credit_remaining = alice.credit.principal;

        bob.total_rent_paid = 0;
        bob.total_property_tax_paid = 0;

        report_bob.push_back(report);
    
    }
    
}


void alice_job() 
{
    if (!alice.is_unemployed) {
        alice.cash += alice.job.salary;
    }
    alice_check_job_loss();
    alice_process_unemployment();
    alice_random_bonus();
    alice_overtime_pay();
    alice_salary_shock();
    alice_change_job();
    alice_burnout();
}


void alice_flat_to_live(int month) 
{
    alice_pay_rent(month);
    alice_pay_utilities(month);
    alice_pay_parking(month);
}

void alice_flat_to_rent(int month) 
{
    alice_receive_rent(month);
    alice_pay_property_tax(month);
}


void alice_car_usage(int month) 
{
    alice_pay_fuel();
    alice_pay_insurance_osago(month);
    alice_pay_insurance_kasko(month);
    alice_pay_maintenance();
    alice_depreciate_car(month);
    alice_pay_car_tax(month);
}


void alice_events() 
{
    alice_random_theft();
    alice_random_win_lottery();
    alice_random_medical_expense();
    alice_random_car_repair();
    alice_random_vacation();
    alice_random_gift();
    alice_random_inheritance();
    alice_random_fine();
    alice_random_phone_break();
    alice_random_household_break();
}


void bob_job()
{
    if (!bob.is_unemployed) {
        bob.cash += bob.job.salary;
    }
    bob_check_job_loss();
    bob_process_unemployment();
    bob_random_bonus();
    bob_overtime_pay();
    bob_salary_shock();
    bob_change_job();
    bob_burnout();
}


void bob_flat_to_live(int month)
{
    bob_pay_rent(month);
    bob_pay_utilities(month);
    bob_pay_parking(month);
}



void bob_car_usage(int month)
{
    bob_pay_fuel();
    bob_pay_insurance_osago(month);
    bob_pay_insurance_kasko(month);
    bob_pay_maintenance();
    bob_depreciate_car(month);
    bob_pay_car_tax(month);
}


void bob_events()
{
    bob_random_theft();
    bob_random_win_lottery();
    bob_random_medical_expense();
    bob_random_car_repair();
    bob_random_vacation();
    bob_random_gift();
    bob_random_inheritance();
    bob_random_fine();
    bob_random_phone_break();
    bob_random_household_break();
}


// ---------- Основная симуляция ----------
void simulate_alice(const int start_year, const int start_month, const int end_year, const int end_month)
{
    int year = start_year;
    int month = start_month;

   
     
    while (!(year > end_year) && ((year < end_year) || (month <= end_month))){
        alice_job();
        alice_check_annual_raise(month);
        
        alice_pay_pets(); // вместо live_payments()
        alice_pay_subscriptions();
        alice_pay_food();
        alice_pay_mobile();
        alice_pay_healthcare();
        alice_pay_entertainment();
        alice_pay_clothing();
        alice_pay_unexpected();
        alice_pay_sport();

        alice_flat_to_live(month);
        alice_flat_to_rent(month);
        alice_car_usage(month);
        alice_update_deposit();
        alice_investment();
        alice_events();
        alice_birthday(month);
        alice_credit();
        alice_calculate_stress();
        alice_check_crisis();

        alice_make_report(year, month, end_year, end_month);
        
        if (month == 12){
            year++;
            month = 0;
        }

        month++;


    }
}


void simulate_bob(const int start_year, const int start_month,  const int end_year, const int end_month)
{
    int year = start_year;
    int month = start_month;


    while (!(year > end_year) && ((year < end_year) || (month <= end_month))){
        bob_job();
        bob_check_annual_raise(month);
       
        bob_pay_pets(); // вместо live_payments()
        bob_pay_subscriptions();
        bob_pay_food();
        bob_pay_mobile();
        bob_pay_healthcare();
        bob_pay_entertainment();
        bob_pay_clothing();
        bob_pay_unexpected();
        bob_pay_sport();

        bob_flat_to_live(month);
        bob_car_usage(month);
        bob_update_deposit(); 
        bob_investment();
        bob_events();
        bob_birthday(month);
        bob_credit();
        bob_calculate_stress();
        bob_check_crisis();

        bob_make_report(year,month, end_year, end_month);

        if (month == 12){
            year++;
            month = 0;
        }

        month++;


    }
}

// ---------- Вывод отчётов ----------
void alice_print_reports() 
{
    std::cout << "=== Alice year report ===\n";
    std::cout << "Year | Net Worth | cash | Deposit | Car Value | Rent Paid | Property Tax | Stress | Stocks | Credit\n";
    for (const auto& r : report_alice) {
        std::cout << r.year << " | "
            << r.net_worth << " | "
            << r.cash << " | "
            << r.deposit << " | "
            << r.car_value << " | "
            << r.rent_paid << " | "
            << r.property_tax_paid << " | "
            << r.stress_index << " | "
            << r.investment_value << " | "
            << r.credit_remaining << "\n";
    }
}


void bob_print_reports()
{
    std::cout << "=== Bob year report ===\n";
    std::cout << "Year | Net Worth | cash | Deposit | Car Value | Rent Paid | Property Tax | Stress | Stocks | Credit\n";
    for (const auto& r : report_bob) {
        std::cout << r.year << " | "
            << r.net_worth << " | "
            << r.cash << " | "
            << r.deposit << " | "
            << r.car_value << " | "
            << r.rent_paid << " | "
            << r.property_tax_paid << " | "
            << r.stress_index << " | "
            << r.investment_value << " | "
            << r.credit_remaining << "\n";
    }
}


int main() 
{
    srand(static_cast<unsigned>(time(nullptr))); // для случайности
    setlocale(LC_ALL, "");

    world_init();
    alice_init();
    bob_init();

    simulate_alice(2026, 5, 2040, 8);
    simulate_bob(2026, 5, 2040, 8);

    alice_print_reports();
    bob_print_reports();

    return 0;
}

