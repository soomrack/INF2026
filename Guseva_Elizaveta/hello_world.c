#include <stdio.h>

using Percent = float;

using RUB = long long int;
using USD = long long int;

struct Car
{
    RUB value;
    RUB gas;
};
struct Bank
{
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
};

struct Person
{
    Bank vtb;
    RUB food;
    RUB salary;
    Car car;
};
struct Person alice;

void food_cost(const int month, const int year)
{
    if (month == 12)
        alice.vtb.account_rub -= 2000; // party
    Percent inflation = 12.0;
    switch (year)
    {
    case 2026:
        inflation = 12.5;
        break;
    case 2027:
        inflation = 14.0;
        break;
    case 2028:
        inflation = 13.0;
        break;
    case 2029:
        inflation = 11.5;
        break;
    }

    alice.food += alice.food * (inflation / 100. / 12.);

    alice.vtb.account_rub -= alice.food;
}

void print_results()
{
    printf("Salary = %lld\n", alice.salary);
    RUB capital = 0;
    capital += alice.vtb.account_rub;
    capital += alice.car.value;
    capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
    printf("Capital = %lld", alice.vtb.account_rub);
}

void alice_salary(int month, int year)
{
    if (month == 2 && year == 2026)
    {
        alice.vtb.account_rub += 5000;
    }

    if (month == 3)
    {
        alice.salary *= 1.5;
    }

    alice.vtb.account_rub += alice.salary; // comment
}

void second_job(const int bonus, const int lunch_cost, const int bonus_month)
{
    alice.vtb.account_usd += 1000;
    if (bonus_month == 5)
    {
        alice.vtb.account_usd += bonus;
    }
    alice.vtb.account_rub -= lunch_cost * 30;
}

void alice_car()
{
    alice.vtb.account_rub -= alice.car.gas;
}

void simulation()
{
    int year = 2026;
    int month = 2;

    while (!(year == 2027 && month == 2))
    {
        food_cost(month, year);

        ++month;
        if (month == 13)
        {
            ++year;
            month = 1;
        }
        alice_salary(month, year);
        second_job(3000, 5, month);
        alice_car();
        // alice_cat();
        // alice_trip();
        // alice_rent();
        // alice_mortgage();
    }
    print_results();
}

void alice_init()
{
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 10000;

    alice.food = 1800;
    alice.salary = 180000;

    alice.car.value = 2400000;
    alice.car.gas = 15000;
}

int main()
{
    alice_init();
    simulation();
}
