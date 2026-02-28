#include <stdio.h>


using Percent = float;

using RUB = long long int;
using USD = long long int;


struct Car {
    RUB value;
    RUB gas;
};


struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
};


struct Person {
    Bank vtb;
    RUB salary;
    RUB food;
    RUB ipoteka;
    Car car;
};
struct Person Alice;


void Alice_init()
{
    Alice.vtb.rate_usd_rub = 78.76;
    Alice.vtb.account_rub = 0;
    Alice.vtb.account_usd = 1'000;
    
    Alice.salary = 180'000;
    Alice.food = 3'000;
    Alice.ipoteka = 20'000; 
    
    Alice.car.value = 2'400'0;
    Alice.car.gas = 15'000;
}


void Alice_food(const int month, const int year)
{
    if (month == 12) Alice.vtb.account_rub -= 2000;  // christmas party

    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    }
    Alice.food += Alice.food * (inflation / 100. / 12.);
        
    Alice.vtb.account_rub -= Alice.food;
}

void Alice_ipoteka(const int month, const int year)
{
    if (month == 2 && year == 2026) Alice.vtb.account_rub -= 50000;  // first pay

    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    }
    Alice.ipoteka += Alice.ipoteka * (inflation / 100. / 12.);
    Alice.vtb.account_rub -= Alice.ipoteka;
}

void Alice_salary(const int month, const int year)
{
    if (month == 3) {
        Alice.salary *= 1.5;
    }

    if (month == 2 && year == 2026) {
        Alice.vtb.account_rub += 5000;  // bonus
    }
        
    Alice.vtb.account_rub += Alice.salary;
}


void print_results()
{
    printf("Salary = %lld\n", Alice.salary);

    RUB capital = 0;
    capital += Alice.vtb.account_rub;
    capital += Alice.vtb.account_usd * Alice.vtb.rate_usd_rub;
    capital += Alice.car.value;
    printf("Capital = %lld\n", capital);
    printf("ipoteka = %lld\n", Alice.ipoteka);

}


void Alice_car()
{
    Alice.vtb.account_rub -= Alice.car.gas;
}


void simulation()
{
    int year = 2026;
    int month = 2;
    
    while ( !(year == 2027 && month == 2) ) {
        Alice_salary(month, year);
        Alice_car();
        // my_cat();
        // my_trip();
        // my_rent();
        // my_mortgage();
        Alice_food(month, year);
        Alice_ipoteka(month, year);
        
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    Alice_init();
    simulation();
    print_results();
}