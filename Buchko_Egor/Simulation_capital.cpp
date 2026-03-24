#include <stdio.h>
#include <iostream>

using PERCENT = float;

using RUB = long long int;
using USD = long long int;
using TIME = long long int;


// сберегательный счет
struct Savings_account {
    RUB account_rub;
    RUB min_account_rub;
    PERCENT bet;
    TIME time;
    TIME last_time;
};

// банковский счет
struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
    Savings_account alice_depozit_vacation;
    Savings_account alice_depozit_main;
};

// авто
struct Car { 
    RUB value;
    RUB gas;
    RUB wash;
    RUB sum_expenses;
    PERCENT inflation_gas;
};

// игровой аккаунт
struct Steam {
    RUB account_rub;
    RUB salary_steam;
    RUB expenses_steam;
    RUB sum_expenses;
};

// подписки на онлайн платформы
struct Sub {
    RUB yandex_music;
    RUB vpn;
    RUB boosty;
    USD spotify;
    USD netflix;
    RUB sum_expenses;
};

// еда
struct Food {
    RUB expenses;
    RUB sum_expenses_food;
    PERCENT inflation_food;
};

// все составляющие капитала человека
struct Person {
    Bank vtb;
    Steam steam;
    Food food;
    Car car;
    Sub sub;
    RUB capital;
    RUB salary_job;
    RUB salary_freelance;
};

struct Person alice;

// иницилизация данных
void alice_init()
{
    alice.vtb.rate_usd_rub = 78.76; // RUB
    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 0;
    alice.vtb.alice_depozit_main.account_rub = 100000; // RUB
    alice.vtb.alice_depozit_main.min_account_rub = 100000; // RUB
    alice.vtb.alice_depozit_main.bet = 1.08; // PERCENT
    alice.vtb.alice_depozit_main.time = 1; //month
    alice.vtb.alice_depozit_vacation.account_rub = 50000; // RUB
    alice.vtb.alice_depozit_vacation.min_account_rub = 50000; // RUB
    alice.vtb.alice_depozit_vacation.bet = 1.12; // PERCENT
    alice.vtb.alice_depozit_vacation.time = 12; //month
    alice.vtb.alice_depozit_vacation.last_time = 12; //month

    alice.salary_job = 100'000; // RUB
    alice.food.expenses = 7'000; // RUB
    alice.food.sum_expenses_food = 0;
    alice.food.inflation_food = 1.058;
    alice.salary_freelance = 0;

    alice.car.value = 2'400'000; //RUB
    alice.car.gas = 15'000; // RUB
    alice.car.inflation_gas = 1.09;

    alice.sub.yandex_music = 450; // RUB
    alice.sub.vpn = 100; // RUB
    alice.sub.boosty = 150; // RUB
    alice.sub.spotify = 5.5; // USD
    alice.sub.netflix = 11; // USD

    alice.steam.account_rub = 3000; // RUB
}

// выплаты по вкладу
void pay_saving_account(const int month){

    // вклад 1

    // если не хватает денег то они берутся со вклада
    if (alice.vtb.account_rub < 35000)
    {
        int sum_withdrawn = alice.vtb.alice_depozit_main.account_rub - alice.vtb.alice_depozit_main.min_account_rub;
        alice.vtb.account_rub += sum_withdrawn;
        alice.vtb.alice_depozit_main.account_rub -= sum_withdrawn;
    }

    // выплаты процента по вкладу
    float percent_month = (alice.vtb.alice_depozit_main.bet - 1) / 12 + 1;
    //std::cout << 1 - alice.vtb.alice_depozit_main.bet << "\n";
    alice.vtb.alice_depozit_main.account_rub *= percent_month;

    // вклад 2

    percent_month = (alice.vtb.alice_depozit_vacation.bet - 1) / 12 + 1;
    alice.vtb.alice_depozit_vacation.account_rub *= percent_month;

}

// изменение инфляции
void change_inflation()
{
    if (rand() % 2 == 0){
        alice.food.inflation_food += 0.01;
    }else{
        alice.food.inflation_food -= 0.005;
    }
}

// Steam
void alice_steam(const int month)
{
    // рандомный заработок берется от кейсов в кс которые раздают каждую неделю
    // цена кейсов может варироватся примерно от 5 до 1000 рублей
    int random_salary = rand()%100;

    if (random_salary % 9 == 0){
        random_salary *= 10;
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
    alice.steam.sum_expenses += random_expenses;
}

// траты на подписки
void alice_subs()
{
    alice.vtb.account_rub -= alice.sub.yandex_music;
    alice.vtb.account_rub -= alice.sub.vpn;
    alice.vtb.account_rub -= alice.sub.boosty;
    alice.vtb.account_usd -= alice.sub.spotify;
    alice.sub.sum_expenses += alice.sub.yandex_music;
    alice.sub.sum_expenses += alice.sub.vpn;
    alice.sub.sum_expenses += alice.sub.boosty;
    alice.sub.sum_expenses += alice.sub.spotify;
}

//траты на еду
void alice_food(const int month)
{
    if (month == 1) {
        alice.food.expenses *= alice.food.inflation_food;
    }
    if (month == 12) {
        alice.vtb.account_rub -= 2000;
        alice.food.sum_expenses_food += 2000;
    }

    alice.vtb.account_rub -= alice.food.expenses;
    alice.food.sum_expenses_food += alice.food.expenses;
}

// траты на машину
void alice_car(const int month)
{
    if (month == 1){
        alice.car.gas = alice.car.gas * alice.car.inflation_gas;
    }

    alice.vtb.account_rub -= alice.car.gas;
    alice.car.sum_expenses += alice.car.gas;
    
    if (month % 2 == 0){
        alice.vtb.account_rub -= alice.car.wash;
        alice.car.sum_expenses += alice.car.wash;
    }
}

// начисление зп
void alice_salary(const int month, const int year)
{
    if (month == 3){
        alice.salary_job = (alice.salary_job * 1.1);
    }
    if (month == 1){
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

//вывод результатов
void print_resullts()
{
    RUB capital = 0;
    
    printf("------------траты-----------\n");
    printf("\tFood = %lld\n", alice.food.sum_expenses_food);
    printf("\tCar = %lld\n", alice.car.sum_expenses);
    printf("\tSub = %lld\n", alice.sub.sum_expenses);
    printf("\tSteam = %lld\n", alice.steam.sum_expenses);

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

    printf("-----различные вклады-----\n");
    printf("\tVTB main = %lld\n", alice.vtb.alice_depozit_main.account_rub);
    printf("\tVTB vacation = %lld\n", alice.vtb.alice_depozit_vacation.account_rub);


    printf("----------капитал-----------\n");
    printf("\tCapital = %lld\n", capital);
}


// симуляция нескольких лет
void simulation(const int delta_year, const int delta_month)
{
    int now_year = 2026;
    int now_month = 2;
    int year = now_year;
    int month = now_month;
    while ( !(year - now_year == delta_year  && month - now_month == delta_month)) {
        change_inflation();
        alice_salary(month, year);
        alice_freelance(month);
        alice_food(month);
        alice_car(month);
        alice_subs();
        alice_steam(month);
        pay_saving_account(month);

        //printf("%lld\n", month);
        //print_resullts();
        ++month;
        if (month == 13){
            ++year;
            month = 1;
        }
    }  
}



int main(){
   alice_init();
   simulation(1, 5);
   print_resullts();
}
