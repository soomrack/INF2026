#include <stdio.h> // стандарт и/о

int main()
{
    int year = 2026;
    int month = 2;

    int salary = 100'001; // разделение разрядов
    int capital = 0;

    // for (int month = 1; month < 25; ++month)
    while (!(year == 2027 && month == 2))
    {
        if (month == 3)
        {
            salary = (salary * 1.5);
        }

        capital += salary;

        ++month; // прибавить 1 к переменной (month++; month = month+1)
        if (month == 13)
        {
            ++year;
            month = 1;
        }
    }

    printf("Salary = %d\n", salary); // %d чтоб десятичные вывести % - подставить сюда
    printf("Capital = %d", capital);
}