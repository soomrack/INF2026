#include <stdio.h>

// typedef int RUB
using RUB = int;

struct Car {
    RUB value;
    RUB gas;
};

struct Person {
    RUB salary = 180'000;
    RUB capital = 0;
    RUB food;
}

RUB salary = 180'000;
RUB capital = 0;

void my_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) {
        salary = (salary * 1.5);
    }
    capital += salary;
}

void results() {
    printf("salary = %lld\n", salary);
    printf("capital = %lld", capital);
}

void simulation() {
    int month = 1;
    int year = 2026;
    
    float pp = 14.5;

    while ( !((month == 3) && (year == 2027)) ) {
        capital += capital * (pp / 12.0 / 100.0); // Bank interest
        
        my_salary(month, year);

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}

int main()
{
    simulation();
    
    results();
}
