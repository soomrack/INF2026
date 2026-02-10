#include <stdio.h>

int salary = 100'001;
int capital = 0;
int food = 15'000;


void my_salary(const int month)
{
    if (month == 3) {
        salary *= 1.5;
    }
        
    capital += salary;
}


void my_food()
{
    capital -= food;
}


int main()
{
    int year = 2026;
    int month = 2;
    
    while ( !(year == 2027 && month == 2) ) {
        // my_cat();
        // my_trip();
        my_food();
        // my_car();
        // my_bank_interest();
        my_salary(month);
        
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
    
    printf("Salary = %d\n", salary);
    printf("Capital = %d", capital);
}
