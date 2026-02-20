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
    RUB salary_rub;
    USD salary_usd;
    Car car;
    RUB lunch_cost;
};
struct Person alice;

void alice_food_cost(const int month, const int year)
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

    alice.food += (alice.food + alice.lunch_cost * 247) * (inflation / 100. / 12.); // 247 - average number of working days in a month

    alice.vtb.account_rub -= alice.food;
}

void count_capital()
{
    RUB capital = 0;
    capital += alice.vtb.account_rub;
    capital += alice.car.value;
    capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
}

void print_results()
{
    printf("Capital_usd = %lld", alice.vtb.account_usd);
    printf("Capital_rub = %lld", alice.vtb.account_rub);
}

void alice_first_job(const int month, const int year)
{
    if (month == 2 && year == 2026)
        alice.vtb.account_rub += 5000; // bonus

    if (month == 3)
        alice.salary_rub *= 1.5; // promotion

    alice.vtb.account_rub += alice.salary_rub;
}

void alice_second_job(const int month, const int year)
{
    if (month == 5 && year == 2027)
        alice.vtb.account_usd += 3000; // bonus

    alice.vtb.account_usd += alice.salary_usd;
}

void alice_car()
{
    alice.vtb.account_rub -= alice.car.gas;
}

void alice_trip()
{
    if (alice.vtb.account_usd > 6000)
        alice.vtb.account_usd -= 6000; // trip to Maldives
}

void alice_cat(const int month, const int year)
{
    if (month == 12 && year == 2027)
        alice.vtb.account_usd -= 1000; // start-up costs

    if (month == 1)
        alice.vtb.account_rub -= 3000; // veterinary costs

    alice.vtb.account_rub -= 2000; // food
    alice.vtb.account_rub -= 500;  // litter
}

void simulation()
{
    int year = 2026;
    int month = 2;

    while (!(year == 2028 && month == 2))
    {
        if (month == 13)
        {
            ++year;
            month = 1;
        }

        alice_food_cost(month, year);
        alice_first_job(month, year);
        alice_second_job(month, year);
        alice_car();
        alice_cat(month, year);
        alice_trip();
        // alice_rent();
        // alice_mortgage();

        ++month;
    }
}

void alice_init()
{
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 10000;

    alice.food = 1800;
    alice.lunch_cost = 5;
    alice.salary_rub = 180000;
    alice.salary_usd = 1500;

    alice.car.value = 2400000;
    alice.car.gas = 15000;
}

int main()
{
    print_results();
    alice_init();
    simulation();
}
