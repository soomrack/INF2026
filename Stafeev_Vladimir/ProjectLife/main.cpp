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


void Kate_food(const int month, const int year)
{
    if (month == 12)
        Kate.tbank.account -= 10'000;
    Kate.tbank.account -= Kate.food;
}

void Henry_food(const int month, const int year)
{
    if (month == 12)
        Henry.sber.account -= 30'000;
    if (month == 5)
        Henry.sber.account -= Henry.food;
    Henry.sber.account -= Henry.food;
}


void Kate_car(const int month, const int year)
{
    Kate.tbank.account -= Kate.matiz.gas;
    if (month == 12)
        Kate.matiz.price -= Kate.matiz.price * price_reduction;
    if (month == 1)
        Kate.tbank.account -= Kate.matiz.car_insurance;
}


void Kate_deposite(const int month, const int year)
{
    if (year == 2026) Kate.tbank.interest = 14.5;
    if (year == 2027) Kate.tbank.interest = 13.5;
    if (year == 2028) Kate.tbank.interest = 12.5;
    if (year == 2029) Kate.tbank.interest = 11.5;

    Kate.tbank.deposite += Kate.tbank.deposite * (Kate.tbank.interest  / 12.0 / 100.0);

    Kate.tbank.deposite += Kate.tbank.account;
    Kate.tbank.account = 0;
}


void Kate_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        Kate.tbank.account_usd += 3'000;
    }
}


void print_results()
{
    printf("Salary = %lld\n", Kate.salary);

    RUB capital = 0;
    capital += Kate.tbank.account;
    capital += Kate.matiz.price;
    capital += Kate.tbank.deposite;
    capital += Kate.tbank.account_usd * Kate.tbank.rate_usd_rub;
    printf("Capital = %lld", capital);
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
        // my_cat();
        // my_medine();
        // my_home();
        Kate_deposite(month, year);

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

    simulation();

    print_results();
}
