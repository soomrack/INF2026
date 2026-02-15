#include <stdio.h>


//ТИПЫ ДАННЫХ

using RUB = long long int;      //тип данных для операций в рублях
using USD = long long int;      //тип данных для операций в долларах

using Percent = float;          //тип данных для процентов (1-100%)


//СТРУКТУРЫ

/*struct Rate {                   //структура ставок по годам (2026-2030гг)
    Percent rate2026 = 14.5;
    Percent rate2027 = 12.5;
    Percent rate2028 = 10.5;
    Percent rate2029 = 7;
    Percent rate2030 = 4;
    Percent rate2031 = 4.5;
};*/


struct Bank {                   //структура банка
    RUB account;
    RUB deposite;
    USD account_usd;
    float rate_usd_rub;

    Percent interest;
    Rate rate;
   
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
    judy.salary = 180'000;

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








void judy_deposite(const int month, const int year)         //функция депозита Джуди в банке
{
    if (year == 2026) judy.zoobank.interest = 14.5;
    if (year == 2027) judy.zoobank.interest = 13.5;
    if (year == 2028) judy.zoobank.interest = 12.5;
    if (year == 2029) judy.zoobank.interest = 11.5;
    if (year == 2030) judy.zoobank.interest = 11.5;
    if (year == 2031) judy.zoobank.interest = 11.5;

    judy.zoobank.deposite += judy.zoobank.deposite * (judy.zoobank.interest / 12.0 / 100.0);

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

    RUB capital = 0;
    capital += judy.zoobank.account;
    capital += judy.car.value;
    capital += judy.zoobank.deposite;
    capital += judy.zoobank.account_usd * judy.zoobank.rate_usd_rub;
    printf("Capital = %lld\n", capital);
}


void simulation()                               //функция всей симуляции
{
    int month = 2;
    int year = 2026;

    while (not (month == 3 and year == 2030)) {
        judy_salary(month, year);
        judy_freelance(month, year);
        judy_food();
        judy_car();
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