#include <stdio.h>


// typedef int RUB;  // C
using RUB = long long int;  // C++


struct Car {
    RUB value;
    RUB gas;
    RUB repair;
    float iznos_procent = 5;
};


struct Person {
    RUB salary;
    RUB bank_account;
    RUB food;
    RUB capital;
    Car car;
    float inflation_procent = 10;
};
struct Person alice;


void alice_init()
{
    alice.bank_account = 0;
    alice.salary = 180'000;
    alice.food = 15'000;
    
    alice.car.value = 2'400'000;
    alice.car.gas = 12'000;
    alice.car.repair = 7'000;
    alice.capital = alice.bank_account + alice.car.value;
}


float sberbank_interest(RUB sum)
{
    if (sum > 10'000 and sum < 3'000'000) {
        return 11.5;
    }

    if (sum >= 3'000'000) {
        return 12.5;  //  125 -1 +
    }

    return 0.1;
}

void alice_salary(const int year, const int month)
{
    if (month == 3 and year == 2026) {
        alice.salary *= 1.5;
    }

    alice.bank_account += alice.salary;
}

void alice_food()
{
    alice.bank_account -= alice.food;
}

void alice_car()
{
    alice.bank_account -= alice.car.gas;
    alice.bank_account -= alice.car.repair;
}

void alice_deposit()
{
    float pp;
    pp = sberbank_interest(alice.bank_account);
    alice.bank_account += alice.bank_account * (pp / 12.0 / 100.0);
}

void alice_real_capital() 
{
    alice.capital = alice.bank_account + alice.car.value;
}

void alice_year_inflation() 
{
    alice.food += alice.food *(alice.inflation_procent / 100);
    alice.car.value += alice.car.value * ((alice.inflation_procent - alice.car.iznos_procent) / 100);
    alice.car.gas += alice.car.gas * (alice.inflation_procent / 100);
    alice.car.repair += alice.car.repair * (alice.inflation_procent / 100);
}

void print_results()
{
    printf("Salary = %lld\n", alice.salary);
    printf("Capital = %lld", alice.bank_account);
}

void alice_simulation()
{
    int year = 2026;
    int month = 2;

    while (not (year == 2027 and month == 2)) {
        // my_cat();
        // my_trip();
        
        alice_salary(year, month);
        alice_food();
        alice_car();
        alice_deposit();
        alice_real_capital();
        
        
        if (year == 2026 and month == 12) 
        {
            alice_year_inflation();
        }

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

    alice_simulation();

    print_results();
}
