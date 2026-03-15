#include <stdio.h>

//typedef int RUB;  // C
using RUB = long long int;  // C++


struct Car {
    RUB value;
    RUB gas;
};


struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    struct Car car;
};
struct Person Alice;


float pp = 14.5;  // 115 -1 +


void alice_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) {  // Promotion
        Alice.salary *= 1.5;
    }

    Alice.capital += Alice.salary;    
}


void print_results()
{
    printf("Salary = %lld\n", Alice.salary);
    printf("Capital = %lld", Alice.capital);
}


void alice_bank_interest()
{
    Alice.capital += Alice.capital * (pp / 12.0 / 100.0);  // Bank interest
}


void alice_food()
{
    Alice.capital -= Alice.food;
}


void alice_car()
{
    Alice.capital -= Alice.car.gas;
}


void alice_init()
{
    Alice.capital = 0;
    Alice.salary = 180'000;
    Alice.food = 20'000;

    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;
}


void simulation()
{
    int month = 2;
    int year = 2026;
    
    while ( !((month == 3) && (year == 2027)) ) {
        // my_cat();
        // my_trip();
        alice_food();
        alice_car();
        alice_bank_interest();
        alice_salary(month, year);
        
        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}


int main()
{
    alice_init();
    
    simulation();
    
    print_results();
}
