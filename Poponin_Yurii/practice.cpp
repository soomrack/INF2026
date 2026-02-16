#include <stdio.h>

using RUB = long long int;

struct Pet
{
    RUB value;
    RUB food;
    RUB filler;
};

struct Car 
{
    RUB value;
    RUB gas;
};


struct Person 
{
    RUB flat;
    RUB bankcard;
    RUB salary;
    RUB deposit;
    RUB food;
    RUB capital;
    struct Car car;
    struct Pet pet;
};
struct Person Alice;


float pp = 14.5;


void alice_salary(const int month, const int year) 
{
    if ((month == 8) && (year == 2026)) 
    {
        Alice.salary *= 1.5;
    }

    Alice.bankcard += Alice.salary;
}

void alice_deposit()
{
    Alice.deposit += Alice.deposit * pp / 12 / 100;
    Alice.deposit += Alice.salary / 10;
    Alice.bankcard = Alice.bankcard - Alice.salary / 10;
}

void alice_capital()
{
    if (Alice.capital == 0)
    {
        Alice.capital = Alice.flat + Alice.car.value + Alice.pet.value + Alice.bankcard;
    }
    Alice.capital += Alice.bankcard + Alice.deposit;
}


void alice_food()
{
    Alice.bankcard -= Alice.food;
}

void alice_car()
{
    Alice.bankcard -= Alice.car.gas;
}

void inflation()
{
    Alice.flat *= 1.04;
    Alice.food *= 1.04;
    Alice.car.gas *= 1.03;
    Alice.car.value *= 1.03;
    Alice.pet.filler *= 1.01;
    Alice.pet.food *= 1.02;
}

void alice_pet()
{
    Alice.bankcard = Alice.bankcard - Alice.pet.filler - Alice.pet.food;
}


void alice_init()
{
    Alice.flat = 8'000'000;
    Alice.bankcard = 0;
    Alice.deposit = 0;
    Alice.salary = 180'000;
    Alice.food = 20'000;
    Alice.capital = 0;

    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;

    Alice.pet.filler = 3000;
    Alice.pet.food = 5000;
}


void simulation()
{
    int month = 2;
    int year = 2026;

    while (!((month == 3) && (year == 2027))) 
    {
        alice_capital();
        alice_pet();
        alice_food();
        alice_car();
        alice_deposit();
        inflation();
        alice_salary(month, year);

        ++month;
        if (month == 13) 
        {
            month = 1;
            ++year;
        }
    }
}

void print_results()
{
    printf("bank acc = %lld\n", Alice.bankcard);
    printf("deposit = %lld\n", Alice.deposit);
    printf("capital = %lld", Alice.capital);
}

int main()
{
    alice_init();

    simulation();

    print_results();
}
