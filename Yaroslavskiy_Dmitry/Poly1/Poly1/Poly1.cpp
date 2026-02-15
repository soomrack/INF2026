#include <stdio.h>


//ТИПЫ ДАННЫХ

using RUB = long long int;      //тип данных для операций в рублях
using USD = long long int;      //тип данных для операций в долларах

using Percent = float;          //тип данных для процентов (1-100%)


struct Bank {                   //структура банка
    RUB account;
    RUB deposite;
    USD account_usd;
    float rate_usd_rub;

    Percent interest;
   
};


struct Car {                    //структура автомобиля
    RUB gas;
    RUB value;
};


struct Person {                 //структура Персонажа (главная!!!)
    Bank zoobank;
    Car car;
    RUB salary;
    RUB food;
};
struct Person judy;             //Создание Персонажа Джуди;
struct Person nick;             //Создание Персонажа Ник;


//ФУНКЦИИ

void judy_init()                            //функция инициализации Джуди
{
    judy.zoobank.account = 0;
    judy.zoobank.deposite = 1'000'000;
    judy.zoobank.interest;
    //judy.salary = 180'000;

    judy.zoobank.account_usd = 1'000;
    judy.zoobank.rate_usd_rub = 78.5;

    judy.food = 20'000;

    judy.car.value = 2'400'000;
    judy.car.gas = 15'000;
}


void judy_salary(const int month, const int year)           //функция зарплаты Джуди
{
    if (month == 12) {
        judy.zoobank.account += judy.salary;  // 13th salary
    }

    if (month == 1) {
        judy.salary *= (judy.zoobank.interest + 100)/100;  //увеличение зарплаты на ставку (индексация)
    }

    judy.zoobank.account += judy.salary;
}


void judy_food()                            //функция еды Джуди
{
    judy.zoobank.account -= judy.food;
}


void judy_car()                             //функция машины Джуди
{
    judy.zoobank.account -= judy.car.gas;
}


float key_rate(const int month, const int year)              //функция ключевой ставки
{
    Percent percents_rate;
    if (year == 2026) percents_rate = 14.5;
    if (year == 2027) percents_rate = 12.5;
    if (year == 2028) percents_rate = 10;
    if (year == 2029) percents_rate = 7.5;
    if (year == 2030) percents_rate = 4;
    if (year == 2031) percents_rate = 4.5;
    return (percents_rate);
}

float delta(const int month, const int year)              //функция (ставка - % по депозиту или предложение по кредиту - ставка, 2026-2030гг)
{
    Percent percents_delta;
    if (year == 2026) percents_delta = 2.5;
    if (year == 2027) percents_delta = 2.5;
    if (year == 2028) percents_delta = 2;
    if (year == 2029) percents_delta = 1.5;
    if (year == 2030) percents_delta = 1;
    if (year == 2031) percents_delta = 1.5;
    return (percents_delta);
}


void judy_deposite(const int month, const int year)         //функция депозита Джуди в банке
{
    judy.zoobank.interest = key_rate(month, year) - delta(month, year);     //ключевая ставка - дельта ("комиссия" банка)

    judy.zoobank.deposite += judy.zoobank.deposite * (judy.zoobank.interest / 12.0 / 100.0);    //сложный процент

    printf("depos123 = %lld  ", judy.zoobank.deposite);
    judy.zoobank.deposite += judy.zoobank.account;
    judy.zoobank.account = 0;
}


void judy_freelance(const int month, const int year)            //функция подработки Джуди
{
    if (month == 3 and year == 2027) {
        judy.zoobank.account_usd += 3'000;
    }
}


void print_results()                            //функция вывода результатов
{
    printf("Salary = %lld  ", judy.salary);
    printf("depos = %lld  ", judy.zoobank.deposite);

    RUB capital = 0;
    capital += judy.zoobank.account;
    capital += judy.car.value;
    capital += judy.zoobank.deposite;
    capital += judy.zoobank.account_usd * judy.zoobank.rate_usd_rub;
    printf("Capital = %lld\n", capital);
}


void simulation()                               //функция всей симуляции
{
    int month = 1;
    int year = 2026;

    while (not (month == 3 and year == 2030)) {
        //judy_salary(month, year);
        //judy_freelance(month, year);
        //judy_food();
        //judy_car();
        //
        // my_cat();
        // my_medine();
        // my_home();
        judy_deposite(month, year);

        ++month;
        if (month == 13) {
            print_results();
            ++year;
            month = 1;
        }
    }
}


//ПРОГРАММА

int main()
{
    judy_init();

    simulation();

    print_results();
}