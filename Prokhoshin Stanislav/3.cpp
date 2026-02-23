#include <stdio.h>

int year = 2026;
int month = 2;
double salary_up = 0.07;
int inflation = 7;
struct user
{
    int salary;
    int capital;
    double koeff; // иксы на вклад
    int trust_lvl;
};

user user_init(user x, int salary, int capital, double koeff, int trust_lvl)
{
    x.salary = salary;
    x.capital = capital;
    x.koeff = koeff;
    x.trust_lvl = trust_lvl;
    return x;
}

void data()
{
    ++month;
    if (month == 13)
    {
        ++year;
        month = 1;
    }
}
//void calc_inflation(){
//
//}
user calc_salary(user x)
{
    if (month == 1)
    {
        x.salary = (int)(x.salary * (1 + salary_up));
    }
    return x;
}

user calc_trust_lvl(user x)
{
    x.trust_lvl = (int)(x.capital / 1'000'000 + x.salary / 100'000);
    if (x.trust_lvl > 10)
    {
        x.trust_lvl = 10;
    }
    return x;
}

user calc_koef(user x)
{

    x.koeff = 1 + (double)x.trust_lvl / 50;
    return x;
}

int calc_loose(){
    int loose =int( 75'000*(100+inflation/100));
    return loose;
}

user calc_capital(user x)
{
    x.capital = x.capital + x.salary-calc_loose();
    if (month == 1)
    {
        x.capital = x.capital * x.koeff;
    }
    return x;
}

int main()
{
    user Ignat;
    Ignat = user_init(Ignat, 150'120, 1'000'000, 1, 2);
    while (year != 2035 || month != 6)
    {
        data();
        Ignat = calc_salary(Ignat);
        Ignat = calc_koef(Ignat);
        Ignat = calc_trust_lvl(Ignat);
        Ignat = calc_capital(Ignat);
    }
    printf("%d\n%lf\n%d\n%d\n", Ignat.salary, Ignat.koeff, Ignat.trust_lvl, Ignat.capital);
    return 0;
}
