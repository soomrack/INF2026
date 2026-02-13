#include <stdio.h>


// typedef int RUB;  // C
using RUB = long long int;  // C++


struct Car {
    RUB value;
    RUB gas;
};

struct Cat {
    RUB viskas;
};

struct tax_servise {
    RUB salary_tax;
};

struct House {
    RUB fixed_costs;
};

struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    RUB gambling;
    RUB savings;
    RUB salary_tax;
    Cat cat;
    Car car;
    RUB fixed_costs;
};
struct Person alice;


void alice_init()
{
    alice.capital = 500'000;
    alice.salary = 380'000;
    alice.food = 15'000;
    alice.gambling = 5'000;
    alice.savings = 0;
    alice.salary_tax = 68'400;
    alice.car.value = 2'400'000;
    alice.car.gas = 12'000;

    alice.cat.viskas = 60;
    alice.fixed_costs = 7'000;
}


float sberbank_interest(RUB sum)
{
    if (sum > 10'000 and sum < 3'000'000) {
        return 11.5;
    }

    if (sum >= 3'000'000) {
        return 12.5;  
    }

    return 0.1;
}


void alice_salary(const int year, const int month)
{
    if (month == 3 and year == 2026) {
        alice.salary *= 1.5;
    }
        
    alice.capital += alice.salary;
}

void alice_taxes(const int month)
{
     alice.salary -= alice.salary_tax;
}

void alice_fixed_costs(const int month) 
{
    alice.salary -= alice.fixed_costs;
}

void alice_food()
{
    alice.capital -= alice.food;
}


void print_results()
{
    printf("Salary = %lld\n", alice.salary);
    printf("Capital = %lld", alice.capital);
    printf("Savings = %lld" , alice.savings);
}

void alice_cat()
{
    alice.capital -= alice.cat.viskas;
}

void alice_car()
{
    alice.capital -= alice.car.gas;
}

void alice_gambling(const int month)
{
    alice.capital -= alice.gambling;
}

void alice_bank_interest()
{
    float pp;
    pp = sberbank_interest(alice.capital);
    alice.capital += alice.capital * (pp / 12.0 / 100.0);
}

void alice_savings(const int month)
{
    alice.savings += alice.salary * 0.1;
}

void alice_trip(const int year) {
    while(1) {
        alice.savings += 5000;
        if(alice.savings >= 200'000) alice.savings = 0;
    }
}

void alice_casino() { 
    int b=1000, x, y;
    while(1) {
        printf("balance: %d\n",b);
        printf("bet:"); scanf("5%d",&x);
        printf("number(1-10):"); scanf("%d",7&y);

        if(y==5) {
            b+=x*5;
            printf("Win +%dRUB\n",x*5);

        }
        else {
            b-=x;
            printf("Lose -%dRUB\n",x);
        }
    }
}


void alice_simulation()
{
    int year = 2026;
    int month = 2;
    
    while ( not (year == 2027 and month == 2) ) {

        alice_savings(month);
        alice_trip(year);
        alice_casino();
        alice_food();
        alice_car();
        alice_cat();
        alice_gambling(month);
        alice_taxes(month);
        alice_bank_interest();
        alice_salary(year, month);
        alice_fixed_costs(month);
        
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