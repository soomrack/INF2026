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
    RUB bank_acc_d;
    RUB bank_acc_с;
    RUB pet;
    struct Car car;
};
struct Person Alice;


float pp = 14.5;  // 115 -1 +
float inf = 0.05;

void alice_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) {  // Promotion
        Alice.salary *= 1.5;
    }

    Alice.bank_acc_d += Alice.salary;
}


void print_results()
{
    Alice.capital = Alice.bank_acc_c + Alice.car;
    printf("Salary = %lld\n", Alice.salary);
    printf("Capital = %lld" , Alice.capital)
}


void alice_bank_interest()
{
    Alice.bank_acc_с += Alice.bank_acc_d * (pp / 12.0 / 100.0);  // Bank interest
}


void alice_food()
{
    Alice.bank_acc_d -= Alice.food;
}


void alice_car()
{
    Alice.bank_acc_d -= Alice.car.gas;
}


void alice_init()
{
    Alice.bank_acc_d = 0;
    Alice.salary = 180'000;
    Alice.food = 20'000;
    Alice.capital = 0;

    Alice.pet = 5000;

    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;
}

void alice_inflation()
{
    Alice.car.value *= 1 + inf;
    Alice.car.gas *= 1 + inf;
    Alice.pet *= 1 + inf;
}

vaid alice_pet()
{
    Alice.bank_acc_d -= Alice.pet;
}

void simulation()
{
    int month = 2;
    int year = 2026;
    
    while ( !((month == 3) && (year == 2027)) ) {
        alice_pet();
        // my_trip();
        alice_food();
        alice_car();
        alice_salary(month, year);
        alice_bank_interest();
        alice_inflation();
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
