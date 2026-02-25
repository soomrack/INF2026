#include <stdio.h>
#include <iostream>

using RUB = long long int;
using USD = long long int;

// расходы на авто
struct Car { 
    RUB value;
    RUB gas;
    RUB wash;
};

// банковский счет
struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
};

// игровой аккаунт
struct Steam {
    RUB account_rub;
    RUB salary_steam;
    RUB expenses_steam;
};

// подписки на онлайн платформы
struct Sub {
    RUB yandex_music;
    RUB vpn;
    RUB boosty;
    USD spotify;
};

// все составляющие капитала человека
struct Person {
    Bank vtb;
    Steam steam;
    RUB capital;
    RUB salary_job;
    RUB food;
    RUB salary_freelance;
    Car car;
    Sub sub;
};
struct Person alice;

// иницилизация данных
void alice_init()
{
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 0;
    alice.steam.account_rub = 1000;

    alice.salary_job = 100'000;
    alice.food = 7'000;
    alice.salary_freelance = 0;

    alice.car.value = 2'400'000;
    alice.car.gas = 15'000;

    alice.sub.yandex_music = 450;
    alice.sub.vpn = 100;
    alice.sub.boosty = 150;
    alice.sub.spotify = 5.5;
}

// Steam
void alice_steam(const int month)
{
    // рандомный заработок берется от кейсов в кс которые раздают каждую неделю
    // цена кейсов может варироватся примерно от 5 до 1000 рублей
    int random_salary = rand()%100;

    if (random_salary % 9 == 0){
        random_salary *= 50;
    }
    
    // рандомные траты берутся от пакупки игр, зимой и летом скидки, 
    // + к этому добавляются праздники или отпуск поэтому траты больше
    int random_expenses = rand()%1000;
    
    if (month == 1 || month == 6){
        random_expenses *= 3;
    }

    alice.steam.salary_steam = random_salary;
    alice.steam.expenses_steam = random_expenses;
    alice.steam.account_rub += random_salary;

    // если не хватает денег на аккаунте то надо пополнить 
    if (alice.steam.account_rub < random_expenses){
        alice.vtb.account_rub -= random_expenses*1.1; // комиссия при пополнение
        alice.steam.account_rub += random_expenses;
    }
    alice.steam.account_rub -= random_expenses;
}

// траты на подписки
void alice_subs()
{
    alice.vtb.account_rub -= alice.sub.yandex_music;
    alice.vtb.account_rub -= alice.sub.vpn;
    alice.vtb.account_rub -= alice.sub.boosty;
    alice.vtb.account_usd -= alice.sub.spotify;
}

//траты на еду
void alice_food(const int month)
{
    if (month == 12) {
        alice.capital -= 2000;
    }
    alice.capital -= alice.food;
}

// траты на машину
void alice_car(const int month)
{
    alice.vtb.account_rub -= alice.car.gas;
    if (month % 2 == 0){
        alice.vtb.account_rub -= alice.car.wash;
    }
}

// начисление зп
void alice_salary(const int month, const int year)
{
    if (month == 3){
        alice.salary_job = (alice.salary_job * 1.5);
    }
    if (year == 2027 && month == 2){
        alice.vtb.account_rub += 5000;
    }
    alice.vtb.account_rub += alice.salary_job;
}

// заработок с фриланса
void alice_freelance(const int month)
{
    int time_freelance = 0;
    int bet_freelance = 0;

    time_freelance = rand() % 100;
    bet_freelance = rand() % 10;

    if (month == 12 || month == 1 || month == 5){
        time_freelance *= 2;
    }
    int salary_freelance = time_freelance * bet_freelance;
    alice.salary_freelance = salary_freelance * alice.vtb.rate_usd_rub;
    alice.vtb.account_usd += salary_freelance;
}

// симуляция нескольких лет
void simulation(const int delta_year, const int delta_month)
{
    int now_year = 2026;
    int now_month = 2;
    int year = now_year;
    int month = now_month;
    while ( !(year - now_year == delta_year  && month - now_month == delta_month)) {
        alice_salary(month, year);
        alice_food(month);
        alice_car(month);
        alice_subs();
        alice_freelance(month);
        alice_steam(month);
        ++month;
        if (month == 13){
            ++year;
            month = 1;
        }
    }  
}

//вывод результатов
void print_resullts()
{
    RUB capital = 0;
    
    printf("--------различные зп--------\n");
    printf("\tMain salary = %lld\n", alice.salary_job);
    printf("\tFreelance = %lld\n", alice.salary_freelance);
    printf("\tSteam salary = %lld\n", alice.steam.account_rub);

    printf("-----различные кошельки-----\n");
    printf("\tVTB RUB = %lld\n", alice.vtb.account_rub);
    printf("\tVTB USD = %lld\n", alice.vtb.account_usd);
    printf("\tSteam RUB = %lld\n", alice.steam.account_rub);
    
    capital += alice.vtb.account_rub;
    capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
    capital += alice.car.value;

    printf("----------капитал-----------\n");
    printf("\tCapital = %lld\n", capital);
}


int main(){
   alice_init();
   simulation(10, 5);
   print_resullts();
}
