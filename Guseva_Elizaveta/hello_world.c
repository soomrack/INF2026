#include <stdio.h>

int capital = 0;
int food = 3000;

void  food_cost(const int month){
    if(month == 12){
        capital -= 2000;
    }
    capital -= food;
}

void second_job(const int bonus, const int lunch_cost, const int bonus_month){
    capital += 1000;
    if(bonus_month == 5){
        capital+=bonus;
    }
    capital -= lunch_cost*30;
}

int main()
{
    int year = 2026;
    int month = 2;

    int salary = 10001;
    

    while (!(year == 2027 && month == 2))
    {
        
        if (month == 2 && year == 2026){
            capital += 5000;
        }

        if (month == 3){
            salary *= 1.5;
        }

        capital += salary; // comment
        food_cost(month);

        ++month;
        if (month == 13){
            ++year;
            month = 1;
        }
        second_job(3000, 5, month);
    }
    

    printf("Salary = %d\n", salary);
    printf("Capital = %d", capital);
}
