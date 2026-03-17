#include<iostream>
#include<cstdlib>
#include<ctime>

using Percent = float;

using RUB = long long;
using USD = long long;



struct World_Economy
{
    Percent inflation;
    Percent income_tax;

    float rate_usd_rub;

    Percent inflation_table[30];
};
struct World_Economy economy;



struct Freelance
{
    Percent chance_of_work;

    USD min_income;
    USD max_income;
};
struct Freelance freelance;



struct Car
{
    RUB value;

    RUB gas;
};



struct Deposit
{
    RUB capital;
    Percent rate;
};


struct Investments
{
    RUB capital;
};


struct Bank
{
    RUB account_rub;
    USD account_usd;

    Deposit deposit;
    Investments stocks;
};



struct Animals
{
    RUB humster;
    RUB cat;
    RUB dog;
    RUB man;
};


struct Electronics
{
    RUB phone_price;
    RUB laptop_price;

    int next_phone_year;
    int next_laptop_year;
};


struct Housing
{
    RUB rent;
};



struct Person
{
    RUB salary;
    RUB food;

    Bank vtb;

    Car car;

    Animals home_zoo;

    Electronics tech;

    Housing home;
};
struct Person alice;



void economy_init()
{
    economy.income_tax = 13;
    economy.rate_usd_rub = 78.76;

    economy.inflation_table[0] = 12;
    economy.inflation_table[1] = 11;
    economy.inflation_table[2] = 9;
    economy.inflation_table[3] = 8;
    economy.inflation_table[4] = 7;
    economy.inflation_table[5] = 7;
    economy.inflation_table[6] = 6;
    economy.inflation_table[7] = 6;
    economy.inflation_table[8] = 5;
    economy.inflation_table[9] = 5;

    for (int i = 10; i < 30; ++i)
        economy.inflation_table[i] = 5;
}



void switch_inflation(const int year)
{
    int index = year - 2026;

    if (index < 30)
        economy.inflation = economy.inflation_table[index];
}



void freelance_init()
{
    freelance.chance_of_work = 35;

    freelance.min_income = 200;
    freelance.max_income = 800;
}



void alice_init()
{
    alice.salary = 180000;

    alice.food = 3000;

    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 1000;

    alice.vtb.deposit.capital = 0;
    alice.vtb.deposit.rate = 8;

    alice.vtb.stocks.capital = 0;

    alice.car.value = 2400000;
    alice.car.gas = 15000;

    alice.home.rent = 30000;

    alice.home_zoo.cat = 3000;
    alice.home_zoo.humster = 700;
    alice.home_zoo.man = 200;

    alice.tech.phone_price = 50000;
    alice.tech.laptop_price = 80000;

    alice.tech.next_phone_year = 2028;
    alice.tech.next_laptop_year = 2031;
}



void switch_tax(const int year, Percent &tax)
{
    if (year >= 2028) tax = 14;
}



void alice_my_salary(const int month, const int year)
{
    if (month == 3)
        alice.salary *= 1.5;

    if (month == 2 && year == 2026)
        alice.vtb.account_rub += 5000;

    switch_tax(year, economy.income_tax);

    alice.vtb.account_rub += alice.salary * ((100 - economy.income_tax) / 100);
}



void alice_freelance()
{
    int roll = rand() % 100;

    if (roll < freelance.chance_of_work)
    {
        alice.vtb.account_usd += freelance.min_income +
            rand() % (freelance.max_income - freelance.min_income + 1);
    }
}



void alice_food_cost(const int year)
{
    switch_inflation(year);

    alice.food += alice.food * economy.inflation / 100 / 12;

    alice.vtb.account_rub -= alice.food;
}



void alice_animals_cost()
{
    alice.vtb.account_rub -= alice.home_zoo.cat;
    alice.vtb.account_rub -= alice.home_zoo.humster;
    alice.vtb.account_rub -= alice.home_zoo.man;
}



void alice_rent(const int year)
{
    switch_inflation(year);

    alice.home.rent += alice.home.rent * economy.inflation / 100 / 12;

    alice.vtb.account_rub -= alice.home.rent;
}



void alice_car_gas()
{
    alice.vtb.account_rub -= alice.car.gas;
}



void alice_car_service(const int month)
{
    if (month == 3 || month == 9)
        alice.vtb.account_rub -= 12000;

    if (month == 11)
        alice.vtb.account_rub -= 40000;

    if (month == 5)
        alice.vtb.account_rub -= 6000;
}



void sell_assets(RUB needed)
{
    if (alice.vtb.stocks.capital > 0)
    {
        RUB sell = std::min(alice.vtb.stocks.capital, needed);

        alice.vtb.stocks.capital -= sell;
        alice.vtb.account_rub += sell;

        needed -= sell;
    }

    if (needed > 0 && alice.vtb.deposit.capital > 0)
    {
        RUB sell = std::min(alice.vtb.deposit.capital, needed);

        alice.vtb.deposit.capital -= sell;
        alice.vtb.account_rub += sell;
    }
}



void alice_car_break()
{
    int roll = rand() % 100;

    if (roll < 6)
    {
        int damage = rand() % 100;

        RUB cost = 0;

        if (damage < 50) cost = 10000;
        else if (damage < 80) cost = 40000;
        else if (damage < 95) cost = 120000;
        else cost = alice.car.value;

        if (alice.vtb.account_rub < cost)
            sell_assets(cost - alice.vtb.account_rub);

        if (alice.vtb.account_rub >= cost)
            alice.vtb.account_rub -= cost;
    }
}



void alice_phone(const int year)
{
    if (year >= alice.tech.next_phone_year)
    {
        if (alice.vtb.account_rub > alice.tech.phone_price + 50000)
        {
            alice.vtb.account_rub -= alice.tech.phone_price;

            alice.tech.next_phone_year = year + 2 + rand() % 4;
        }
    }
}



void alice_laptop(const int year)
{
    if (year >= alice.tech.next_laptop_year)
    {
        if (alice.vtb.account_rub > alice.tech.laptop_price + 50000)
        {
            alice.vtb.account_rub -= alice.tech.laptop_price;

            alice.tech.next_laptop_year = year + 5 + rand() % 3;
        }
    }
}



void alice_deposit()
{
    RUB free_money = alice.vtb.account_rub - 100000;

    if (free_money > 0)
    {
        alice.vtb.account_rub -= free_money;
        alice.vtb.deposit.capital += free_money;
    }

    alice.vtb.deposit.capital +=
        alice.vtb.deposit.capital * alice.vtb.deposit.rate / 100 / 12;
}



void alice_investments()
{
    RUB invest = alice.vtb.account_rub * 0.2;

    alice.vtb.account_rub -= invest;

    alice.vtb.stocks.capital += invest;

    int roll = rand() % 100;

    if (roll < 45)
        alice.vtb.stocks.capital *= 1.01;
    else if (roll < 90)
        alice.vtb.stocks.capital *= 0.995;
    else
        alice.vtb.stocks.capital *= 1.03;
}



void simulation()
{
    int year = 2026;
    int month = 2;

    while (!(year == 2056 && month == 2))
    {
        alice_my_salary(month, year);
        alice_freelance();

        alice_food_cost(year);
        alice_animals_cost();

        alice_rent(year);

        alice_car_gas();
        alice_car_service(month);
        alice_car_break();

        alice_phone(year);
        alice_laptop(year);

        alice_deposit();
        alice_investments();

        ++month;

        if (month == 13)
        {
            ++year;
            month = 1;
        }
    }
}



void print_results()
{
    printf("Salary = %lld\n", alice.salary);

    RUB capital = 0;

    capital += alice.vtb.account_rub;
    capital += alice.vtb.account_usd * economy.rate_usd_rub;

    capital += alice.vtb.deposit.capital;
    capital += alice.vtb.stocks.capital;

    capital += alice.car.value;

    printf("Capital = %lld\n", capital);
}



int main()
{
    srand(time(0));

    economy_init();

    freelance_init();

    alice_init();

    simulation();

    print_results();
}
