#include <stdio.h>


using RUB = long long int;
using USD = long long int;

using Percent = float;


struct Bank {
    RUB account;
    RUB deposite;
    Percent interest;
    Percent inflation;
    
    USD account_usd;
    float rate_usd_rub;
};


struct Car {
    RUB gas;
    RUB value;
};


struct Person {
    Bank vtb;
    Car car;
    RUB salary;
    RUB food;
    RUB dog;
    RUB home;
    RUB medicine;
};
struct Person alice;
//struct Person bob;


void alice_init()
{
    alice.vtb.account = 0;
    alice.vtb.deposite = 1'000'000;
    alice.vtb.interest = 14.5;
    alice.salary = 180'000;
    alice.vtb.inflation = 6;

    alice.vtb.account_usd = 1'000;
    alice.vtb.rate_usd_rub = 78.5;
    
    alice.food = 20'000;
    alice.dog = 10'000;
    alice.home = 30'000;
    alice.medicine = 5'000;

    alice.car.value = 2'400'000;
    alice.car.gas = 15'000;
}


void alice_salary(const int month, const int year)
{
    if (month == 12) {
        alice.vtb.account += alice.salary;  // 13th salary
    }

    if ((month == 1) && (year == 2027)) {
        alice.salary *= 1.5;  // promotion
    }
        
    alice.vtb.account += alice.salary;
}


void alice_medicine()
{
    alice.vtb.account -= alice.medicine;
}


void alice_home()
{
    alice.vtb.account -= alice.home;
}


void alice_dog()
{
    alice.vtb.account -= alice.dog;
}


void alice_food()
{
    alice.vtb.account -= alice.food;
}


void alice_car()
{
    alice.vtb.account -= alice.car.gas;
}


void alice_deposite(const int month, const int year)
{
    if (year == 2026) alice.vtb.interest = 14.5;
    if (year == 2027) alice.vtb.interest = 13.5;
    if (year == 2028) alice.vtb.interest = 12.5;
    if (year == 2029) alice.vtb.interest = 11.5;
    
    alice.vtb.deposite += alice.vtb.deposite * (alice.vtb.interest  / 12.0 / 100.0);

    alice.vtb.deposite += alice.vtb.account;
    alice.vtb.account = 0;
}


void alice_freelance(const int month, const int year)
{
    if (month == 3 && year == 2027) {
        alice.vtb.account_usd += 3'000;
    }
}


void alice_inflation()
{
    alice.food *= 1 + (alice.vtb.inflation/12/100.0);
    alice.dog *= 1 + (alice.vtb.inflation/12/100.0);
    alice.medicine *= 1 + (alice.vtb.inflation/12/100.0);
    alice.home *= 1 + (alice.vtb.inflation/12/100.0);
    alice.car.gas *= 1 + (alice.vtb.inflation/12/100.0);
}


void print_results()
{
    printf("Salary = %lld\n", alice.salary);

    RUB capital = 0;
    capital += alice.vtb.account;
    capital += alice.car.value;
    capital += alice.vtb.deposite;
    capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
    printf("Capital = %lld", capital);
}


void simulation()
{
    int month = 2;
    int year = 2026;
    
    while ( !(month == 3 && year == 2028) ) {
        alice_salary(month, year);
        alice_freelance(month, year);
        alice_food();
        alice_car();
        alice_dog();
        alice_medicine();
        alice_home();
        alice_deposite(month, year);
        alice_inflation();
        
        
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    alice_init();
    
    simulation();
    
    print_results();
}