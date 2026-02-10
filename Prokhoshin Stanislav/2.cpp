#include <stdio.h>

int salary = 180'001;
int capital = 0;

void my_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) {
            salary *= 1.5;
    }

    capital += salary;
}

int main() {
    float pp = 14.5;

    int month = 2;
    int year = 2026;

    while(!((month == 3) && (year == 2027))) {
        capital += capital*pp/100.0/12.0;

        my_salary(month, year);        

        if (month == 13){
            month = 1;
            ++year;
        }
        ++month;
    }
    printf("Salary = %d\n", salary);
    printf("Capital = %d", capital);
}
