#include <stdio.h>

int salary = 180001;
int capital = 0;

void my_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) { // Promotion
        salary = salary * 1.5;
    }
    capital += salary;
}

static int rmain()
{
    float pp = 14.5;

    int month = 2;
    int year = 2026;

    //  for (int month = 1; month < 19; ++month) {
    while (!((month == 3) && (year == 2027))) {
        capital += capital * (pp / 12.0 / 100.0); // Bank interest

        my_salary(month, year);

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }

    printf("Salary = %d\n", salary);
    printf("Capital = %d", capital);
}
