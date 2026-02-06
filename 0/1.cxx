#include <stdio.h>


int capital = 0;
int food = 3000;


void food_cost(const int month)
{
    if (month == 12) {
        capital -= 2000;
    }
    
    capital -= food;
}


int main()
{
    int year = 2026;
    int month = 2;
    
    int salary = 10'001;

    while ( !(year == 2027 && month == 2) ) {
        if (month == 3) {
            salary *= 1.5;
        }

        if (month == 2 && year == 2026) {
            capital += 5000;  // bonus
        }
        
        capital += salary;  // capital = capital + salary

        food_cost(month);
        
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
    
    printf("Salary = %d\n", salary);
    printf("Capital = %d", capital);
}
