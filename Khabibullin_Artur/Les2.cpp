#include <stdio.h>


int salary = 100'000;
int capital = 0;

void my_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) {
        salary = (salary * 1.5);
    }
    capital += salary;
}

int main()
{
    int month = 2;
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
printf("salary = %d\n", salary);
printf("capital = %d", capital);
}
