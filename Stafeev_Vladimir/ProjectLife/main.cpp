#include <stdio.h>

const float bank_rate = 15.5;  //central bank rate ~15.5
const float inflation = 6.4;  //inflation 6.4
const float inflation_increase = 1.3;  //inflation increase 1.3 per year
const float price_reduction = 0.17;  //car price reduction 17%

using RUB = long long int;
using USD = long long int;
using Percent = float;


struct Bank {
    RUB account;
    RUB deposite;
    RUB hypothec;
    RUB credit;
    Percent interest;

    USD account_usd;
    float rate_usd_rub;
};


struct Car {
    RUB gas;
    RUB price;
    RUB depreciation; //usage + maintenance
    RUB car_insurance;
};


struct Home {
    RUB price;
    RUB usage;
    RUB home_insurance;
};


struct Female {
    Bank tbank;
    Car matiz;
    RUB salary;
    RUB food;
    Home flat;
};

struct Male {
    Bank sber;
    Car volga;
    RUB salary;
    RUB food;
    RUB education;
    Home house;
    RUB stash;
    RUB dream_car;
};

Female Kate;
Male Henry;


void Kate_init()
{
    Kate.tbank.account = 0;
    Kate.tbank.deposite = 1'000'000;
    Kate.tbank.interest = 14.5;
    Kate.salary = 120'000;

    Kate.tbank.account_usd = 500;
    Kate.tbank.rate_usd_rub = 78.5;

    Kate.food = 15'000;

    Kate.matiz.price = 240'000;
    Kate.matiz.gas = 10'000;
    Kate.matiz.car_insurance = 5'000;
}

void Henry_init()
{
    Henry.sber.account = 0;
    Henry.sber.deposite = 2'000'000;  // start deposite
    Henry.sber.interest = 15.0;
    Henry.salary = 180'000;
    Henry.sber.account_usd = 1000;
    Henry.sber.rate_usd_rub = 78.5;

    Henry.food = 25'000;
    Henry.education = 30'000;

    Henry.volga.price = 850'000;
    Henry.volga.gas = 15'000;
    Henry.volga.car_insurance = 25'000;

    Henry.house.usage = 10'000;
    Henry.house.home_insurance = 8'000;

    Henry.stash = 0;
    Henry.dream_car = 3'500'000;
}


void Kate_salary(const int month, const int year)
{
    if (month == 12) {
        Kate.tbank.account += Kate.salary;  // 13th salary
    }

    if (month == 1 and year == 2027) {
        Kate.salary *= 1.5;  // promotion
    }

    Kate.tbank.account += Kate.salary;
}

void Henry_salary(const int month, const int year)
{
    if (month == 12) {
        Henry.sber.account += Henry.salary;  // 13th salary
    }

    if (month == 6 and year == 2027) {
        Henry.salary *= 1.3;  // promotion
    }

    Henry.sber.account += Henry.salary;
}


void Kate_food(const int month, const int year)
{
    Kate.tbank.account -= Kate.food;
    if (month == 12)
        Kate.tbank.account -= 10'000;  // new year
}

void Henry_food(const int month, const int year)
{
    Henry.sber.account -= Henry.food;

    if (month == 12)
        Henry.sber.account -= 30'000;  // new year
    if (month == 5)
        Henry.sber.account -= 20'000;  // mayskie
}

void Henry_education(const int month, const int year)
{
    if (month == 9) {
        Henry.sber.account -= Henry.education;
    }
}


void Kate_car(const int month, const int year)
{
    Kate.tbank.account -= Kate.matiz.gas;

    if (month == 12)
        Kate.matiz.price -= Kate.matiz.price * price_reduction;

    if (month == 1)
        Kate.tbank.account -= Kate.matiz.car_insurance;
}

void Henry_car(const int month, const int year)
{
    Henry.sber.account -= Henry.volga.gas;

    if (month == 12)
        Henry.volga.price -= Henry.volga.price * price_reduction;

    if (month == 2)  // insurance in february
        Henry.sber.account -= Henry.volga.car_insurance;
}


void Kate_home(const int month, const int year)
{
    Kate.tbank.account -= 7'000;  // flat usage
}

void Henry_home(const int month, const int year)
{
    Henry.sber.account -= Henry.house.usage;

    if (month == 6)  // house insurance
        Henry.sber.account -= Henry.house.home_insurance;
}


void Kate_deposite(const int month, const int year)
{
    if (month == 12)
        Kate.tbank.interest -= 0.1;

    Kate.tbank.deposite += Kate.tbank.deposite * (Kate.tbank.interest / 12.0 / 100.0);

    Kate.tbank.deposite += Kate.tbank.account;
    Kate.tbank.account = 0;
}

void Henry_deposite(const int month, const int year)
{
    if (month == 12)
        Henry.sber.interest -= 0.05;

    Henry.sber.deposite += Henry.sber.deposite * (Henry.sber.interest / 12.0 / 100.0);

    RUB transfer = Henry.sber.account * 0.9;
    Henry.sber.deposite += transfer;
    Henry.sber.account -= transfer;
}


void Kate_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        Kate.tbank.account_usd += 3'000;
    }
}

void Henry_investments(const int month, const int year)
{
    if (month == 6 and year == 2028) {
        Henry.sber.account_usd += 5'000;
    }
}

void Henry_dream_savings(const int month, const int year)
{
    if (Henry.sber.account > 100'000) {
        RUB saving = Henry.sber.account * 0.2;
        Henry.stash += saving;
        Henry.sber.account -= saving;
    }

    if (Henry.stash >= Henry.dream_car) {
        Henry.volga.price = Henry.dream_car;
        Henry.stash -= Henry.dream_car;
        Henry.dream_car = 5'000'000;
    }
}


void print_results()
{
    printf("Kate\n");
    printf("Salary = %lld RUB\n", Kate.salary);
    printf("Bank account = %lld RUB\n", Kate.tbank.account);
    printf("Deposit = %lld RUB\n", Kate.tbank.deposite);
    printf("Car price = %lld RUB\n", Kate.matiz.price);
    printf("USD account = %lld USD (%.1f RUB)\n",
           Kate.tbank.account_usd,
           (float)(Kate.tbank.account_usd * Kate.tbank.rate_usd_rub));

    RUB kate_capital = Kate.tbank.account + Kate.matiz.price +
                       Kate.tbank.deposite +
                       Kate.tbank.account_usd * Kate.tbank.rate_usd_rub;
    printf("Total capital = %lld RUB\n", kate_capital);

    printf("\nHenry\n");
    printf("Salary = %lld RUB\n", Henry.salary);
    printf("Bank account = %lld RUB\n", Henry.sber.account);
    printf("Deposit = %lld RUB\n", Henry.sber.deposite);
    printf("Car price = %lld RUB\n", Henry.volga.price);
    printf("USD account = %lld USD (%.1f RUB)\n",
           Henry.sber.account_usd,
           (float)(Henry.sber.account_usd * Henry.sber.rate_usd_rub));
    printf("Stash for dream = %lld RUB\n", Henry.stash);

    RUB henry_capital = Henry.sber.account + Henry.volga.price +
                        Henry.sber.deposite + Henry.stash +
                        Henry.sber.account_usd * Henry.sber.rate_usd_rub;
    printf("Total capital = %lld RUB\n", henry_capital);

    printf("\nCombined capital = %lld RUB\n", kate_capital + henry_capital);
}


void simulation()
{
    int month = 2;
    int year = 2026;

    while ( not (month == 3 and year == 2066) ) {
        Kate_salary(month, year);
        Kate_freelance(month, year);
        Kate_food(month, year);
        Kate_car(month, year);
        Kate_home(month, year);
        Kate_deposite(month, year);

        Henry_salary(month, year);
        Henry_investments(month, year);
        Henry_food(month, year);
        Henry_education(month, year);
        Henry_car(month, year);
        Henry_home(month, year);
        Henry_dream_savings(month, year);
        Henry_deposite(month, year);

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    Kate_init();
    Henry_init();

    simulation();

    print_results();
}
