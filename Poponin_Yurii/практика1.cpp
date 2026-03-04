#include <stdio.h>

using RUB = long long int;

//Структуры

struct Pet{
    RUB value;
    RUB food;
    RUB filler;
};

struct Car {
    RUB value;
    RUB gas;
};

struct Bank
{
    RUB bankcard;
    RUB salary;
    RUB deposit;
    RUB capital;
};


struct Person {
    RUB flat;
    RUB food;
    struct Bank vtb;
    struct Car car;
    struct Pet pet;
};

struct Person Alice;
struct Person Bob;


float pp = 14.5;

// Объявление функций
// Alice
void alice_salary(const int month, const int year);
void alice_deposit();
void alice_capital();
void alice_food();
void alice_car();
void inflation();
void alice_pet();
void alice_init();

// Bob
void bob_init();

// other
void simulation();





void alice_salary(const int month, const int year) 
{
    if ((month == 8) && (year == 2026)){
        Alice.vtb.salary *= 1.5;
    }

    Alice.vtb.bankcard += Alice.vtb.salary;
}

void alice_deposit()
{
    Alice.vtb.deposit += Alice.vtb.deposit * pp / 12 / 100;
    RUB money = Alice.vtb.salary / 10;
    Alice.vtb.deposit += money; 
    Alice.vtb.bankcard -= money;
}

void alice_capital()
{
    if (Alice.vtb.capital == 0){
        Alice.vtb.capital = Alice.flat + Alice.car.value + Alice.pet.value + Alice.vtb.bankcard;
    }
    Alice.vtb.capital += Alice.vtb.bankcard + Alice.vtb.deposit;
}

void alice_food()
{
    Alice.vtb.bankcard -= Alice.food;
}

void alice_car()
{
    Alice.vtb.bankcard -= Alice.car.gas;
}

void inflation()
{
    Alice.flat *= 0.09 / 12 / 100;
    Alice.food *= 1.04;
    Alice.car.gas *= 1.03;  //поделить на проценты
    Alice.car.value *= 1.03;
    Alice.pet.filler *= 1.01;
    Alice.pet.food *= 1.02;
}

void alice_pet()
{
    Alice.vtb.bankcard += Alice.pet.filler + Alice.pet.food;
}

void bob_init()
{
    Bob.flat = 0;
    Bob.vtb.bankcard = 0;
    Bob.vtb.deposit = 0;
    Bob.vtb.salary = 2910;
    Bob.food = 20'000;
    Bob.vtb.capital = 0;

    Bob.car.value = 2'400'000;
    Bob.car.gas = 15'000;

    Bob.pet.filler = 3000;
    Bob.pet.food = 5000;
}

void alice_init()
{
    Alice.flat = 8'000'000;
    Alice.vtb.bankcard = 0;
    Alice.vtb.deposit = 0;
    Alice.vtb.salary = 180'000;
    Alice.food = 20'000;
    Alice.vtb.capital = 0;

    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;

    Alice.pet.filler = 3000;
    Alice.pet.food = 5000;
}


void simulation()
{
    int month = 2;
    int year = 2026;

    while (!((month == 3) && (year == 2027))) {
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
    printf("bank acc = %lld\n", Alice.vtb.bankcard);
    printf("deposit = %lld\n", Alice.vtb.deposit);
    printf("capital = %lld", Alice.vtb.capital);
}

int main()
{
    alice_init();

    simulation();

    print_results();
}