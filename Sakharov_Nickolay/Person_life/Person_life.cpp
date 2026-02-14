#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

using RUB = long long int;
double inflation;
struct Cat
{
    string color;
    int age;
    RUB cat_food;
};

struct Car
{
    RUB value;
    RUB gas;
};
struct Work
{
    RUB salary;
    float raising;
};
struct Bank
{
    RUB balance;
    RUB deposit;
    float percent;
};

struct Person
{
    Work work;
    RUB food;
    Car car;
    Bank bank;
    RUB deposit_sum;
    Cat Pushok;
};

Person Alice;
void alice_cat()
{
    Alice.bank.balance -= Alice.Pushok.cat_food;
}
void alice_car()
{
    Alice.bank.balance -= Alice.car.gas;
}

void alice_salary(const int month, const int year)
{
    if ((month == 8) && (year == 2026))
    {
        Alice.work.salary = Alice.work.salary * Alice.work.raising;
    }
    Alice.bank.balance += Alice.work.salary;
}
void alice_food()
{
    Alice.bank.balance -= Alice.food;
}
void alice_bank_interest()
{
    Alice.bank.deposit += Alice.deposit_sum;
    Alice.bank.balance -= Alice.deposit_sum;
}
void alice_deposit_percent()
{
    Alice.bank.deposit += Alice.bank.deposit * (Alice.bank.percent / 12 / 100);
}
void print_results()
{

    printf("Salary = %lld\n", Alice.work.salary);
    printf("Capital = %lld\n", Alice.bank.balance);
    printf("Deposit = %lld", Alice.bank.deposit);
}
void simulation()
{

    int month = 2;
    int year = 2026;
    bool firstIteration = true;
    while (!((month == 3) && (year == 2030)))
    {
        alice_cat();
        alice_food();
        alice_car();
        alice_salary(month, year);

        if (!firstIteration)
        {
            alice_deposit_percent();
        }
        firstIteration = false;
        alice_bank_interest();
        ++month;
        if (month == 13)
        {
            double min = 5.5, max = 6.4;
            inflation = (double)rand() / RAND_MAX * (max - min) + min;
            Alice.food *= inflation / 100;
            Alice.car.gas *= inflation / 100;
            Alice.Pushok.cat_food *= inflation / 100;
            month = 1;
            ++year;
        }
    }
}
void alice_init()
{
    Alice.bank.balance = 0;
    Alice.bank.deposit = 0;
    Alice.work.salary = 180000;
    Alice.food = 30000;
    Alice.car.value = 2400000;
    Alice.work.raising = 1.2;
    Alice.deposit_sum = 40000;
    Alice.bank.percent = 14;
    Alice.Pushok.cat_food = 6000;
    Alice.Pushok.age = 3;
    Alice.Pushok.color = "white";
}
int main()
{
    alice_init();
    simulation();
    print_results();
}