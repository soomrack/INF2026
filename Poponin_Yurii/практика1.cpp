#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 
#define RESET   "\033[0m" //знать что это
#define RED     "\033[31m"      
#define GREEN   "\033[32m"     
#define YELLOW  "\033[33m"      
#define BLUE    "\033[34m"     
#define MAGENTA "\033[35m"      
#define CYAN    "\033[36m"      

using RUB = long long int;
float USD_RUB_Rate = 95.5f;

// Структуры

// ==================== СИСТЕМА СРАВНЕНИЯ НАЧАЛЬНЫХ И КОНЕЧНЫХ ДАННЫХ ====================
struct Snapshot {
    // Alice
    RUB alice_start_salary;
    RUB alice_start_flat_value;
    RUB alice_start_bankcard;
    RUB alice_start_deposit;
    int alice_start_age;

    // Bob
    RUB bob_start_salary;
    RUB bob_start_flat_value;
    RUB bob_start_bankcard;
    RUB bob_start_deposit;
    int bob_start_age;

    // Economy
    float start_inflation;
    float start_stavka;
    float start_usd;
};

// Глобальная переменная для хранения снимка
struct Snapshot GameSnapshot;


struct Pet
{
    RUB value;
    RUB food;
    RUB filler;
    RUB vet_clinica;
};
struct Car 
{
    RUB value;
    RUB gas;
    RUB oil;
    RUB frostfree;
    RUB washingliquid;
    RUB TOcost;
    RUB toner;
    RUB penalty;
    RUB tires;
    RUB smena_rezini;
    RUB polirovka;
};

struct Army
{
    bool is_in_army;
    int month_left;
};

struct Bank
{
    RUB bankcard;
    RUB salary;
    RUB deposit;
    RUB capital;
    RUB total_waste_money;
    RUB total_luck_money;
};

struct Flat
{
	RUB value;
    RUB electricity;
    RUB water;
    RUB heating;
    RUB internet;
};

struct Mortgage 
{
    RUB total_loan;
    RUB monthly_pay;
    float rate;
    int duration;
    int months_left;
};
 
struct Business {
    char name[50];
    RUB monthly_profit;
    RUB initial_investment;
    int risk_level;
    bool is_active;
    int months_active;
};

struct Stock {
    std::string ticker;
    RUB price;
    int quantity;
    float volatility;
    RUB dividend_yield;
};

struct StockMarket {
    struct Stock sber;
    struct Stock gazprom;
    struct Stock yandex;
    float market_sentiment;
};


struct RealEstateMarket {
    float price_growth_rate;
    float rental_yield;
    int bubble_risk;
};

struct Person {
    int age;
    RUB food;
    RUB trip;
    struct Bank vtb;
	struct Flat flat;
    struct Business side_business;
    struct Car car;
    struct Pet pet;
    struct Mortgage house_loan;
    struct StockMarket portfolio;
    struct Army army;
    bool is_bankrupt;
};

struct WorldEconomy {
    float inflation_rate;
    float food_modifier;
    float car_modifier;
    float estate_modifier;
    float stavka;
    float monthly_base;
};

struct RealEstateMarket MoscowRealEstate;
struct WorldEconomy Russia2026;

struct Person Alice;
struct Person Bob;


// Объявление функций 

// Alice
void alice_salary(const int month, const int year);
void alice_deposit();
void alice_inflation(const int month, const int year);
void alice_init();
void alice_good_events(const int month, const int year);
void alice_bad_events(const int month, const int year);
void alice_food_expenses(const int month, const int year);
void alice_car_expenses(const int month, const int year);
void alice_pet_expenses(const int month, const int year);
void alice_start_business(const int month, const int year);
void alice_pay_mortgage(const int month, const int year);
void alice_init_mortgage();
void alice_housing_expenses(const int month, const int year);
void alice_extrawork(const int month, const int year);
void alice_check_bankruptcy(const int month, const int year);

// Bob
void bob_stats(const int month, const int year);
void bob_check_military(const int month, const int year);
void bob_salary(const int month, const int year);
void bob_deposit(const int month, const int year);
void bob_inflation(const int month, const int year);
void bob_init();
void bob_good_events(const int month, const int year);
void bob_bad_events(const int month, const int year);
void bob_food_expenses(const int month, const int year);
void bob_car_expenses(const int month, const int year);
void bob_fun_expenses(const int month, const int year);
void bob_pet_expenses(const int month, const int year);
void bob_extrawork(const int month, const int year);
void bob_init_mortgage();
void bob_start_business(const int month, const int year);
void bob_pay_mortgage(const int month, const int year);
void bob_check_bankruptcy(const int month, const int year);
void bob_military(const int month, const int year);

// other
void simulation();
void apply_global_inflation(const int month, const int year);
void update_business(const int month, const int year, struct Person& p);
void init_stock_market();
void update_stock_prices(const int month, const int year);
void alice_investment_strategy(const int month, const int year);
void bob_trading_strategy(const int month, const int year);
void apply_salary_indexation(const int month, const int year);
void take_initial_snapshot();
void print_final_comparison();
void print_personal_growth_report(const char* name, RUB start_capital, RUB end_capital, RUB start_salary, RUB end_salary, int age_passed);
void economy_init();
void global_economic_events(const int month, const int year);
void init_real_estate_market();
void update_real_estate_market(const int month, const int year);
void update_bank_rate(const int month, const int year);
void update_currency_rates(const int month, const int year);


// Определение функций

// Alice

void alice_salary(const int month, const int year) 
{
    if ((month == 8) && (year == 2026)) {
        Alice.vtb.salary *= 1.3;
    }

    Alice.vtb.bankcard += Alice.vtb.salary;
}


void alice_deposit()
{
    if (Alice.vtb.bankcard < 100'000) 
        return;
    Alice.vtb.deposit += Alice.vtb.deposit * Russia2026.stavka / 12 / 100;
    RUB money = Alice.vtb.salary / 10;
    Alice.vtb.deposit += money;
    Alice.vtb.bankcard -= money;
}

void alice_inflation(const int month, const int year) {
    Alice.flat.value += Alice.flat.value * (Russia2026.monthly_base * Russia2026.estate_modifier);
    Alice.food += Alice.food * (Russia2026.monthly_base * Russia2026.food_modifier);
    Alice.car.gas += Alice.car.gas * (Russia2026.monthly_base * Russia2026.car_modifier);
    Alice.pet.food += Alice.pet.food * (Russia2026.monthly_base * Russia2026.food_modifier);
}

void alice_food_expenses(const int month, const int year) { // vitamins 
    RUB grocery_bill = 25000;
    RUB cafe_bill = 8000;


    if (rand() % 100 < 20) {
        cafe_bill += 10000;
        printf("[%02d.%d] Алиса сходила в элитный ресторан. -10 000 руб.\n", month, year);
        Alice.vtb.total_waste_money += 10000;
    }

    Alice.vtb.bankcard -= (grocery_bill + cafe_bill);
}

void alice_car_expenses(const int month, const int year) {

    Alice.vtb.bankcard -= Alice.car.gas;
    Alice.vtb.bankcard -= Alice.car.oil;
    Alice.vtb.bankcard -= Alice.car.washingliquid;

    if (month == 4) {
        printf("[%02d.%d] Алиса прошла плановое ТО автомобиля. -%lld руб.\n", month, year, Alice.car.TOcost);
        Alice.vtb.bankcard -= Alice.car.TOcost;
    }

    if (month >= 11 && month <= 3) {
        Alice.vtb.bankcard -= Alice.car.frostfree;
		printf("[%02d.%d] Алиса залила антифриз в машину. -%lld руб.\n", month, year, Alice.car.frostfree);
    }

	if (month == 7 && year % 3 == 0) {
        printf("[%02d.%d] Алиса купила зимнюю и летнюю резину. -%lld руб.\n", month, year, Alice.car.tires);
        Alice.vtb.bankcard -= Alice.car.tires;
    }

	if (month == 10 || month == 4) {
        printf("[%02d.%d] Алиса сменила резину в шиномонтажке. -%lld руб.\n", month, year, Alice.car.smena_rezini);
        Alice.vtb.bankcard -= Alice.car.smena_rezini;
    }

    if (year % 4 == 0) {
        printf("[%02d.%d] Полировка фар. -%lld руб.\n", month, year, Alice.car.polirovka);
        Alice.vtb.bankcard -= Alice.car.polirovka;
    }
}

void alice_stats(const int month, const int year) {
    if (month == 10)
    {
        Alice.age++;
        printf("[%02d.%d] У Алисы День рождения в этом месяце! Ей исполнилось: %d. Поздравляем\n", month, year, Alice.age);
    }
}

void alice_pet_expenses(const int month, const int year) {
    RUB total_pet = Alice.pet.food + Alice.pet.filler;

    if (month == 5) {
        RUB vet_visit = 5000;
        printf("[%02d.%d] Кот Алисы получил ежегодные прививки. -%lld руб.\n", month, year, vet_visit);
        total_pet += vet_visit;
    }

    if (rand() % 100 < 10) {
        RUB damage = 10000;
        printf("[%02d.%d] Кот Алисы перевернул редкое и дорогое растение. Ущерб: -%lld руб.\n", month, year, damage);
        total_pet += damage;
        Alice.vtb.total_waste_money += damage;
	}

    Alice.vtb.bankcard -= total_pet;
}


void alice_pay_mortgage(const int month, const int year) {
    if (Alice.house_loan.months_left > 0) {
        Alice.vtb.bankcard -= Alice.house_loan.monthly_pay;
        Alice.house_loan.months_left--;

        if (month == 12) {
            printf("[%d год] Алисе осталось платить ипотеку %d месяцев.\n",
                year, Alice.house_loan.months_left);
        }

        if (Alice.house_loan.months_left == 0) {
            printf("!!! ПОЗДРАВЛЯЕМ! Алиса полностью выплатила ипотеку в %02d.%d !!!\n", month, year);
        }
    }
}


void alice_init_mortgage() {
    Alice.house_loan.total_loan = 4000000;
    Alice.house_loan.rate = 0.12;
    Alice.house_loan.duration = 160;
    Alice.house_loan.months_left = 160;

    float monthly_rate = Alice.house_loan.rate / 12.0;
    Alice.house_loan.monthly_pay = (Alice.house_loan.total_loan / Alice.house_loan.duration) + (Alice.house_loan.total_loan * monthly_rate);

    printf("--- ОФОРМЛЕНА ИПОТЕКА ДЛЯ АЛИСЫ ---\n");
    printf("Сумма: %lld руб. Платеж: %lld руб./мес.\n\n", Alice.house_loan.total_loan, Alice.house_loan.monthly_pay);
}


void alice_init()
{
    Alice.age = 20;

    Alice.vtb.bankcard = 0;
    Alice.vtb.deposit = 0;
    Alice.vtb.salary = 150'000;
    Alice.food = 20'000;
    Alice.vtb.capital = 0;
    Alice.is_bankrupt = false;
    Alice.side_business.is_active = false;

    Alice.flat.value = 8'000'000;
	Alice.flat.electricity = 3500;
	Alice.flat.water = 1200;
    Alice.flat.heating = 3500;
    Alice.flat.internet = 1800;

    Alice.car.value = 2'400'000;
    Alice.car.gas = 12'000;
    Alice.car.oil = 2000;
    Alice.car.frostfree = 1000;
    Alice.car.washingliquid = 1000;
    Alice.car.TOcost = 30000;
    Alice.car.tires = 60000;
	Alice.car.smena_rezini = 5000;

    Alice.pet.filler = 1000;
    Alice.pet.food = 4000;

    Alice.vtb.total_waste_money = 0;
    Alice.vtb.total_luck_money = 0;

    Alice.trip = 0;
}

void alice_housing_expenses(const int month, const int year) {

    if (month >= 11 || month <= 3) {
        Alice.flat.heating *= 1.5;
    }

    RUB total_utility = Alice.flat.electricity + Alice.flat.water + Alice.flat.heating + Alice.flat.internet;

    printf("[%02d.%d] Алиса оплатила ЖКХ: %lld руб.\n", month, year, total_utility);
    Alice.vtb.bankcard -= total_utility;

    if (month == 12) {
        RUB property_tax = Alice.flat.value * 0.001;
        printf("[%02d.%d] !!! Алиса оплатила годовой налог на имущество: %lld руб.\n", month, year, property_tax);
        Alice.vtb.bankcard -= property_tax;
    }
}

void alice_extrawork(const int month, const int year) {
    if (month >= 5 && month <= 9) {
        int flowers_seeds = 10000;
        Alice.vtb.bankcard -= flowers_seeds;
        int weather_is_good = rand() % 10;
        if (weather_is_good >= 4) {
            int profit = 30000;
            printf("[%02d.%d] Алиса вырастила и продала тюльпаны, погода была хорошая и она заработала: %d руб\n", month, year, profit);
			Alice.vtb.bankcard += profit;
        }
        else {
            int profit = 10000;
            printf("[%02d.%d] Алиса вырастила и продала тюльпаны, погода была плохая и она заработала: %d руб\n", month, year, profit);
            Alice.vtb.bankcard += profit;
        }
    }

    if (month >= 10 || month <= 3) {
        int testo_cost = 10000;
        Alice.vtb.bankcard -= testo_cost;
        int weather_is_good = rand() % 10;
        if (weather_is_good >= 4) {
            int profit = 30000;
            printf("[%02d.%d] Алиса продавала пряники, погода была хорошая и она заработала: %d руб\n", month, year, profit);
            Alice.vtb.bankcard += profit;
        }
        else {
            int profit = 10000;
            printf("[%02d.%d] Алиса продавала пряники, погода была плохая и она заработала: %d руб\n", month, year, profit);
            Alice.vtb.bankcard += profit;
		}
    }
}

void alice_check_bankruptcy(const int month, const int year) {
    if (Alice.is_bankrupt) return;

    if (Alice.vtb.bankcard < -500000) {
        Alice.is_bankrupt = 1;
        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!! ВНИМАНИЕ: Алиса ОБЪЯВЛЕНА БАНКРОТОМ В %02d.%d      !!!\n", month, year);
        printf("!!! Ее долги превысили 500 000 рублей.                 !!!\n");
        printf("!!! Симуляция жизни Алисы остановлена. GAME OVER       !!!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
    }
}

void alice_start_business(const int month, const int year) {
    if (Alice.side_business.is_active) return;
    if (Alice.is_bankrupt) return;
    if (Alice.vtb.bankcard < 200000) return;

    if (year >= 2028 && rand() % 100 < 5) {
        Alice.side_business.is_active = true;
        Alice.side_business.initial_investment = 150000;
        Alice.side_business.risk_level = 4;
        Alice.side_business.monthly_profit = 25000;
        Alice.side_business.months_active = 0;
        sprintf_s(Alice.side_business.name, "Кофейня Алисы");

        Alice.vtb.bankcard -= Alice.side_business.initial_investment;
        printf(GREEN "\n[%02d.%d] БИЗНЕС: Алиса открыла кофейню! Инвестировано %lld руб.\n" RESET, month, year, Alice.side_business.initial_investment);
    }
}

void alice_good_events(const int month, const int year) {
    int chance_of_good_event = rand() % 10;
    if (chance_of_good_event <= 8) {
        int good_event = rand() % 20;
        switch (good_event) {
        case 0:
            printf(GREEN "[%02d.%d] Алиса получила налоговый вычет за лечение. +15 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 15000;
            Alice.vtb.total_luck_money += 15000;
            break;

        case 1:
            printf(GREEN "[%02d.%d] Продажа старой мебели на сервисе объявлений. +7 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 7000;
            Alice.vtb.total_luck_money += 7000;
            break;

        case 2:
            printf(GREEN "[%02d.%d] Алиса нашла выгодный вклад с повышенным процентом! (Разовая премия) +5 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 5000;
            Alice.vtb.total_luck_money += 5000;
            break;

        case 3:
            printf(GREEN "[%02d.%d] Кэшбэк за страховку квартиры. +3 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 3500;
            Alice.vtb.total_luck_money += 3500;
            break;

        case 4:
            printf(GREEN "[%02d.%d] Алиса выиграла грант на обучение. Сэкономлено: +40 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 40000;
            Alice.vtb.total_luck_money += 40000;
            break;

        case 5:
            printf(GREEN "[%02d.%d] Премия за «сотрудника месяца». +25 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 25000;
            Alice.vtb.total_luck_money += 25000;
            break;

        case 6:
            printf(GREEN "[%02d.%d] Подарок от друзей на праздник. +10 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 10000;
            Alice.vtb.total_luck_money += 10000;
            break;

        case 7:
            printf(GREEN "[%02d.%d] Удачная подработка консультантом. +12 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 12000;
            Alice.vtb.total_luck_money += 12000;
            break;

        case 8:
            printf(GREEN "[%02d.%d] Возврат переплаты по ЖКХ. +2 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 2000;
            Alice.vtb.total_luck_money += 2000;
            break;

        case 9:
            printf(GREEN "[%02d.%d] Алиса нашла забытый подарочный сертификат. +3 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 3000;
            Alice.vtb.total_luck_money += 3000;
            break;

        case 10:
            printf(GREEN "[%02d.%d] Алиса продала старые учебники на барахолке. +4 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 4000;
            Alice.vtb.total_luck_money += 4000;
            break;

        case 11:
            printf(GREEN "[%02d.%d] Начисление процентов на остаток по карте. +1 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 1500;
            Alice.vtb.total_luck_money += 1500;
            break;

        case 12:
            printf(GREEN "[%02d.%d] Алиса нашла промокод на скидку в 50%% на продукты. Сэкономлено: +5 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 5000;
            Alice.vtb.total_luck_money += 5000;
            break;

        case 13:
            printf(GREEN "[%02d.%d] Удачная консультация по проекту в свободное время. +18 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 18000;
            Alice.vtb.total_luck_money += 18000;
            break;

        case 14:
            printf(GREEN "[%02d.%d] Алиса получила кэшбэк за покупку авиабилетов. +6 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 6000;
            Alice.vtb.total_luck_money += 6000;
            break;

        case 15:
            printf(GREEN "[%02d.%d] Друзья вернули давний долг, про который Алиса забыла. +10 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 10000;
            Alice.vtb.total_luck_money += 10000;
            break;

        case 16:
            printf(GREEN "[%02d.%d] Алиса выиграла в корпоративной лотерее сертификат. +5 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 5000;
            Alice.vtb.total_luck_money += 5000;
            break;

        case 17:
            printf(GREEN "[%02d.%d] Страховая компания выплатила компенсацию за задержку рейса. +3 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 3000;
            Alice.vtb.total_luck_money += 3000;
            break;

        case 18:
            printf(GREEN "[%02d.%d] Алиса сдала ненужную одежду в ресейл-магазин. +2 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 2500;
            Alice.vtb.total_luck_money += 2500;
            break;

        case 19:
            printf(GREEN "[%02d.%d] Алиса нашла 500 рублей в кармане старого пальто. +500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 500;
            Alice.vtb.total_luck_money += 500;
            break;
        default:

            break;
        }
    }
}

void alice_bad_events(const int month, const int year) {
    int chance_of_bad_event = rand() % 10;
    if (chance_of_bad_event >= 8) {
        int bad_event = rand() % 50;
        switch (bad_event) {
        case 0:
            printf(MAGENTA"[%02d.%d] Алиса потеряла зонт и купила новый. -2 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 2500;
            Alice.vtb.total_waste_money += 2500;
            break;

        case 1:
            printf(MAGENTA"[%02d.%d] Повышение стоимости интернета. Разовая доплата: -1 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 1000;
            Alice.vtb.total_waste_money += 1000;
            break;

        case 2:
            printf(MAGENTA"[%02d.%d] Алиса случайно разбила любимую кружку. -800 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 800;
            Alice.vtb.total_waste_money += 800;
            break;

        case 3:
            printf(MAGENTA"[%02d.%d] Платный вебинар оказался бесполезным. -3 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 3000;
            Alice.vtb.total_waste_money += 3000;
            break;

        case 4:
            printf(MAGENTA"[%02d.%d] Комиссия за перевод в другой банк. -500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 500;
            Alice.vtb.total_waste_money += 500;
            break;

        case 5:
            printf(MAGENTA "[%02d.%d] Алиса случайно оставила включенным свет на месяц. Счет за свет: -2 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 2000;
            Alice.vtb.total_waste_money += 2000;
            break;

        case 6:
            printf(MAGENTA "[%02d.%d] Потребовалась срочная чистка ноутбука от пыли. -3 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 3500;
            Alice.vtb.total_waste_money += 3500;
            break;

        case 7:
            printf(MAGENTA "[%02d.%d] Алиса опоздала на поезд, пришлось брать новый билет. -4 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 4000;
            Alice.vtb.total_waste_money += 4000;
            break;

        case 8:
            printf(MAGENTA "[%02d.%d] Пролила кофе на важные документы, перевыпуск: -1 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 1500;
            Alice.vtb.total_waste_money += 1500;
            break;

        case 9:
            printf(MAGENTA "[%02d.%d] Траты на подарок коллеге, на который скидывались всем отделом. -2 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 2000;
            Alice.vtb.total_waste_money += 2000;
            break;

        case 10:
            printf(MAGENTA "[%02d.%d] У Алисы закончилась память в облаке, оплата за год: -3 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 3000;
            Alice.vtb.total_waste_money += 3000;
            break;

        case 11:
            printf(MAGENTA "[%02d.%d] Внезапный визит к платному врачу. -5 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 5000;
            Alice.vtb.total_waste_money += 5000;
            break;

        case 12:
            printf(MAGENTA "[%02d.%d] Алиса купила книгу, которую уже читала. -1 200 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 1200;
            Alice.vtb.total_waste_money += 1200;
            break;

        case 13:
            printf(MAGENTA "[%02d.%d] Порвались любимые кроссовки. Покупка новых: -8 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 8000;
            Alice.vtb.total_waste_money += 8000;
            break;

        case 14:
            printf(MAGENTA "[%02d.%d] Алиса забыла отменить пробный период приложения. -900 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 900;
            Alice.vtb.total_waste_money += 900;
            break;

        case 15:
            printf(MAGENTA "[%02d.%d] Мелкий ремонт сантехники в ванной. -2 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 2500;
            Alice.vtb.total_waste_money += 2500;
            break;

        case 16:
            printf(MAGENTA "[%02d.%d] Штраф за запрещенную аватарку в максе. -1000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 500;
            Alice.vtb.total_waste_money += 500;
            break;

        case 17:
            printf(MAGENTA "[%02d.%d] Потерялась любимая помада, покупка новой: -2 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 2000;
            Alice.vtb.total_waste_money += 2000;
            break;

        case 18:
            printf(MAGENTA "[%02d.%d] Алиса попала под ливень без зонта. Химчистка пальто: -3 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 3000;
            Alice.vtb.total_waste_money += 3000;
            break;

        case 19:
            printf(MAGENTA "[%02d.%d] Сломались наушники. Покупка новых: -6 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 6000;
            Alice.vtb.total_waste_money += 6000;
            break;

        default:
            break;
        }
    }
}



// Bob

void bob_salary(const int month, const int year)
{
    if ((month == 8) && (year == 2026)) {
        Bob.vtb.salary *= 1.3;
    }

    Bob.vtb.bankcard += Bob.vtb.salary;
}


void bob_inflation(const int month, const int year) {
    Bob.flat.value += Bob.flat.value * (Russia2026.monthly_base * Russia2026.estate_modifier);
    Bob.food += Bob.food * (Russia2026.monthly_base * Russia2026.food_modifier);
    Bob.car.gas += Bob.car.gas * (Russia2026.monthly_base * Russia2026.car_modifier);
    Bob.pet.food += Bob.pet.food * (Russia2026.monthly_base * Russia2026.food_modifier);
}


void bob_deposit(const int month, const int year)
{
    if (Bob.vtb.bankcard > 0 && rand() % 10 > 5)
    {
         Bob.vtb.deposit += Bob.vtb.deposit * Russia2026.stavka / 12 / 100;
         RUB money = Bob.vtb.salary / 20;
         Bob.vtb.deposit += money;
         Bob.vtb.bankcard -= money;
    }

    if (rand() % 100 < 8) {
        RUB waste = Bob.vtb.deposit / 2;

        Bob.vtb.deposit -= waste;
        Bob.vtb.total_waste_money += waste;

        printf("[%02d.%d] Боб не сдержался и всрал половину вклада, потеряно: %lld руб\n", month, year, waste);
    }
}


void bob_food_expenses(const int month, const int year) {
    RUB fastfood = 25000; 
    RUB energy_drinks = 5000; 

    if (rand() % 100 < 40) {
        RUB party_pizza = 8000;
        printf("[%02d.%d] Боб заказал пиццу на всех друзей. -%lld руб.\n", month, year, party_pizza);
        fastfood += party_pizza;
        Bob.vtb.total_waste_money += party_pizza;
    }

    printf("[%02d.%d] Расходы Боба на еду и доставку: %lld руб.\n", month, year, fastfood + energy_drinks);
    Bob.vtb.bankcard -= (fastfood + energy_drinks);
}

void bob_car_expenses(const int month, const int year) {

    Bob.vtb.bankcard -= Bob.car.gas;
    Bob.vtb.bankcard -= Bob.car.oil;
    Bob.vtb.bankcard -= Bob.car.washingliquid;


    if (rand() % 100 < 20) { 
        RUB ticket = 2500;
        printf("[%02d.%d] ШТРАФ: Боб превысил скорость. -%lld руб.\n", month, year, ticket);
        Bob.vtb.bankcard -= ticket;
        Bob.vtb.total_waste_money += ticket;
    }

    if (month >= 11 && month <= 3) {
        Bob.vtb.bankcard -= Bob.car.frostfree;
        
    }

    if (rand() % 100 < 5) {
        RUB repair = 45000;
        printf("[%02d.%d] ПОЛОМКА: У Боба задымился капот! Ремонт: -%lld руб.\n", month, year, repair);
        Bob.vtb.bankcard -= repair;
        Bob.vtb.total_waste_money += repair;
    }

    if (rand() % 100 < 20) {
        printf("[%02d.%d] Боб прошел ТО. -%lld руб.\n", month, year, Bob.car.TOcost);
        Bob.vtb.bankcard -= Bob.car.TOcost;
    }

    if (rand() % 100 < 80) {
        printf("[%02d.%d] Бобу сняли тонировку: -%lld руб. Наклеил новую: -%lld руб\n", month, year, Bob.car.penalty, Bob.car.toner);
        Bob.vtb.bankcard -= Bob.car.penalty + Bob.car.toner;
    }
}

void bob_fun_expenses(const int month, const int year) {
    RUB subs = 4500;
    RUB bar_bill = 15000;


    if (rand() % 10 < 3) {
        RUB game_price = 8000;
        printf("[%02d.%d] Вышел новый ведьмак! Боб купил игру за %lld руб.\n", month, year, game_price);
        Bob.vtb.bankcard -= game_price;
        Bob.vtb.total_waste_money += game_price;
    }

    Bob.vtb.bankcard -= (subs + bar_bill);
}

void bob_pet_expenses(const int month, const int year) {

    if (rand() % 100 < 15) {
        RUB damage = 12000;
        printf("[%02d.%d] Пес Боба съел провода и порвал диван. Ущерб: -%lld руб.\n", month, year, damage);
        Bob.vtb.bankcard -= damage;
        Bob.vtb.total_waste_money += damage;
    }

    if (rand() % 100 < 10) {
        printf("[%02d.%d] Пес боба приболел, затраты на лечение обошлись в %lld руб\n", month, year, Bob.pet.vet_clinica);
        Bob.vtb.bankcard -= Bob.pet.vet_clinica;
    }

    Bob.vtb.bankcard -= Bob.pet.filler + Bob.pet.food;
}

void bob_extrawork(const int month, const int year) {
    if (month >= 5 && month <= 9) {
        int sab_rent = 10000;
        Bob.vtb.bankcard -= sab_rent;
        int weather_is_good = rand() % 10;
        if (weather_is_good >= 4) {
            int profit = 40000;
            printf("[%02d.%d] Боб подработал, сдавая сабы на пляже, погода была хорошая и он заработал: %d руб\n", month, year, profit);
            Bob.vtb.bankcard += profit;

        }
        else {
            int profit = 10000;
            printf("[%02d.%d] Боб подработал сдавая сабы на пляже, погода была плохая и он заработал: %d руб\n", month, year, profit);
            Bob.vtb.bankcard += profit;
        }
    }
    if (month >= 11 || month <= 2) {
        int bublik_rent = 10000;
        Bob.vtb.bankcard -= bublik_rent;
        int weather_is_good = rand() % 10;
        if (weather_is_good >= 4) {
            int profit = 40000;
            printf("[%02d.%d] Боб подработал, сдавая бублики на горке, погода была хорошая и он заработал: %d руб\n", month, year, profit);
			Bob.vtb.bankcard += profit;

        }
        else {
            int profit = 10000;
            printf("[%02d.%d] Боб подработал сдавая бублики на горке, погода была плохая и он заработал: %d руб\n", month, year, profit);
            Bob.vtb.bankcard += profit;
        }
    }
}


void bob_init_mortgage() {
    Bob.house_loan.total_loan = 2'500'000;
    Bob.house_loan.rate = 0.10;
    Bob.house_loan.duration = 100;
    Bob.house_loan.months_left = 100;

    float monthly_rate = Bob.house_loan.rate / 12.0;
    Bob.house_loan.monthly_pay = (Bob.house_loan.total_loan / Bob.house_loan.duration) + (Bob.house_loan.total_loan * monthly_rate);

    printf("--- ОФОРМЛЕНА ИПОТЕКА ДЛЯ БОБА ---\n");
    printf("Сумма: %lld руб. Платеж: %lld руб./мес.\n\n", Bob.house_loan.total_loan, Bob.house_loan.monthly_pay);
}

void bob_stats(const int month, const int year){
    if (month == 3)
    {
        Bob.age++;
        printf("[%02d.%d] У Боба День рождения в этом месяце! Ему исполнилось: %d. Поздравляем\n", month, year, Bob.age);
    }
}

void bob_check_military(const int month, const int year) {
    if (Bob.age == 22 && month == 3) {
        printf("[%02d.%d]!!! БОБ УЕХАЛ НА СРОЧНУЮ СЛУЖБУ. УВИДИМСЯ ЧЕРЕЗ ГОД, БОБ !!!\n");
        Bob.army.is_in_army = true;
    }
}

void bob_military(const int month, const int year) {
    if (Bob.army.is_in_army == true) {
        Bob.army.month_left--;
        switch (Bob.army.month_left) {
        case 0:
            Bob.army.is_in_army = false;
            printf("[%02d.%d]БОБ ДЕМБЕЛЬНУЛСЯ\n", month, year);
            break;
        case 1:
            printf("[%02d.%d] Бобу остался последний месяц до дембеля!!!\n", month, year);
            break;
        case 2:
            printf("[%02d.%d] Бобу осталось %d месяца до дембеля\n", month, year, Bob.army.month_left);
            break;
        case 3:
            printf("[%02d.%d] Бобу осталось %d месяца до дембеля\n", month, year, Bob.army.month_left);
            break;
        case 4:
            printf("[%02d.%d] Бобу осталось %d месяца до дембеля\n", month, year, Bob.army.month_left);
            break;
        case 5:
            printf("[%02d.%d] Бобу осталось %d месяцев до дембеля\n", month, year, Bob.army.month_left);
            break;
        case 6:
            printf("[%02d.%d] Бобу осталось %d месяцев до дембеля\n", month, year, Bob.army.month_left);
            break;
        case 7:
            printf("[%02d.%d] Бобу осталось %d месяцев до дембеля\n", month, year, Bob.army.month_left);
            break;
        case 8:
            printf("[%02d.%d] Бобу осталось %d месяцев до дембеля\n", month, year, Bob.army.month_left);
            break;
        case 9:
            printf("[%02d.%d] Бобу осталось %d месяцев до дембеля\n", month, year, Bob.army.month_left);
            break;
        case 10:
            printf("[%02d.%d] Бобу осталось %d месяцев до дембеля\n", month, year, Bob.army.month_left);
            break;
        case 11:
            printf("[%02d.%d] Бобу осталось %d месяцев до дембеля\n", month, year, Bob.army.month_left);
            break;
        case 12:
            printf("[%02d.%d] Бобу осталось %d месяцев до дембеля\n", month, year, Bob.army.month_left);
            break;
        }

    }
}

void bob_pay_mortgage(const int month, const int year) {
    if (Bob.house_loan.months_left > 0) {
        Bob.vtb.bankcard -= Bob.house_loan.monthly_pay;
        Bob.house_loan.months_left--;

        if (month == 12) {
            printf("[%d год] Бобу осталось платить ипотеку %d месяцев.\n",
                year, Bob.house_loan.months_left);
        }

        if (Bob.house_loan.months_left == 0) {
            printf("!!! ПОЗДРАВЛЯЕМ! Боб полностью выплатил ипотеку в %02d.%d !!!\n", month, year);
        }
    }
}

void bob_check_bankruptcy(const int month, const int year) {
    if (Bob.is_bankrupt == 1) return;


    if (Bob.vtb.bankcard < -500000) {
        Bob.is_bankrupt = 1;
        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!! ВНИМАНИЕ: БОБ ОБЪЯВЛЕН БАНКРОТОМ В %02d.%d         !!!\n", month, year);
        printf("!!! Его долги превысили 500 000 рублей.                !!!\n");
        printf("!!! Симуляция жизни Боба остановлена. GAME OVER        !!!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
    }
}


void bob_init()
{
    Bob.age = 20;
    Bob.flat.value = 5'000'000;
    Bob.vtb.bankcard = 0;
    Bob.vtb.deposit = 0;
    Bob.vtb.salary = 120'000;
    Bob.food = 20'000;
    Bob.vtb.capital = 0;

    Bob.car.value = 1'400'000;
    Bob.car.gas = 15'000;
    Bob.car.frostfree = 1000;
    Bob.car.oil = 1000;
    Bob.car.washingliquid = 1000;
    Bob.car.TOcost = 20000;
    Bob.car.penalty = 3000;
    Bob.car.toner = 4000;

    Bob.pet.filler = 1000;
    Bob.pet.food = 3000;
    Bob.pet.value = 15000;
    Bob.pet.vet_clinica = 3000;

    Bob.vtb.total_waste_money = 0;
    Bob.vtb.total_luck_money = 0;

    Bob.is_bankrupt = false; 
    Bob.side_business.is_active = false;

    Bob.army.month_left = 12;
    Bob.army.is_in_army = false;
}

void bob_start_business(const int month, const int year) {
    if (Bob.side_business.is_active) return;
    if (Bob.is_bankrupt || Bob.army.is_in_army) return;

    if (rand() % 100 < 8) {
        Bob.side_business.is_active = true;
        Bob.side_business.initial_investment = 50000 + (rand() % 100000);
        Bob.side_business.risk_level = 8;
        Bob.side_business.monthly_profit = 10000;
        Bob.side_business.months_active = 0;
        sprintf_s(Bob.side_business.name, "Стартап Боба v.%d", rand() % 10);

        Bob.vtb.bankcard -= Bob.side_business.initial_investment;
        printf(CYAN "\n[%02d.%d] БИЗНЕС: Боб вложился в '%s'! Инвестировано %lld руб.\n" RESET,
            month, year, Bob.side_business.name, Bob.side_business.initial_investment);
    }
}

void bob_good_events(const int month, const int year) {
    int chance_of_good_event = rand() % 50;
    if (chance_of_good_event <= 8) {
        int good_event = rand() % 20;

        switch (good_event) {
        case 0:
            printf(CYAN"[%02d.%d] Боб нашел на улице 5000 руб.!" RESET "\n", month, year);
            Bob.vtb.bankcard += 5000;
            Bob.vtb.total_luck_money += 5000;
            break;

        case 1:
            printf(CYAN"[%02d.%d] Старый долг вернули Бобу. +10 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 10000;
            Bob.vtb.total_luck_money += 10000;
            break;

        case 2:
            printf(CYAN"[%02d.%d] Боб выиграл бесплатный ужин. Экономия! +2 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 2000;
            Bob.vtb.total_luck_money += 2000;
            break;

        case 4: {
            RUB win = 150000;
            printf(CYAN"[%02d.%d] Боб выиграл в казино! Выигрыш: +%lld руб." RESET "\n", month, year, win);
            Bob.vtb.bankcard += win;
            Bob.vtb.total_luck_money += win;
            break;
        }
        case 5: {
            printf(CYAN"[%02d.%d] Боб нашел подработку курьером на выходные. +15 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 15000;
            Bob.vtb.total_luck_money += 15000;
            break;
        }
        case 6: {
            RUB win = 200000;
            printf(CYAN"[%02d.%d] Боб выиграл в онлайн-покер: +%lld руб." RESET "\n", month, year, win);
            Bob.vtb.bankcard += win;
            Bob.vtb.total_luck_money += win;
            break;
        }
        case 7: {
            RUB win = 100000;
            printf(CYAN"[%02d.%d] Боб выиграл в лотерею: +%lld руб." RESET "\n", month, year, win);
            Bob.vtb.bankcard += win;
            Bob.vtb.total_luck_money += win;
            break;
        }
        case 8: {
            RUB sell_item = 15000;
            printf(CYAN"[%02d.%d] Боб продал старый хлам с балкона на барахолке. +%lld руб." RESET "\n", month, year, sell_item);
            Bob.vtb.bankcard += sell_item;
            Bob.vtb.total_luck_money += sell_item;
            break;
        }

        case 9: {
            printf(CYAN"[%02d.%d] Боб нашел баг в приложении банка. Ему выплатили вознаграждение! +50 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 50000;
            Bob.vtb.total_luck_money += 50000;
            break;
        }

        case 10: {
            RUB tax_return = 13000;
            printf(CYAN"[%02d.%d] Боб наконец-то подал на налоговый вычет. Пришли деньги: +%lld руб." RESET "\n", month, year, tax_return);
            Bob.vtb.bankcard += tax_return;
            Bob.vtb.total_luck_money += tax_return;
            break;
        }

        case 11: {
            printf(CYAN"[%02d.%d] Боб удачно зашел в крипту на «низах». Быстрая прибыль: +25 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 25000;
            Bob.vtb.total_luck_money += 25000;
            break;
        }

        case 12: {
            printf(CYAN"[%02d.%d] Боб выиграл в конкурсе репостов новый смартфон и сразу его продал. +70 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 70000;
            Bob.vtb.total_luck_money += 70000;
            break;
        }

        case 13: {
            RUB part_time = 12000;
            printf(CYAN"[%02d.%d] Боб подработал диджеем на вечеринке у друга. +%lld руб." RESET "\n", month, year, part_time);
            Bob.vtb.bankcard += part_time;
            Bob.vtb.total_luck_money += part_time;
            break;
        }

        case 14: {
            printf(CYAN"[%02d.%d] Боб нашел забытую заначку в зимней куртке. Бобу по кайфу +8 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 8000;
            Bob.vtb.total_luck_money += 8000;
            break;
        }

        case 15: {
            printf(CYAN"[%02d.%d] Родственники прислали Бобу денег «на витамины». +10 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 10000;
            Bob.vtb.total_luck_money += 10000;
            break;
        }

        case 16: {
            printf(CYAN"[%02d.%d] Боб сдал пустые бутылки из-под элитного алкоголя. Кешбэк от магазина: +1 500 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 1500;
            Bob.vtb.total_luck_money += 1500;
            break;
        }

        case 17: {
            RUB stream_donations = 5000;
            printf(CYAN"[%02d.%d] Боб провел стрим, как он учит C. Накидали донатов: +%lld руб." RESET "\n", month, year, stream_donations);
            Bob.vtb.bankcard += stream_donations;
            Bob.vtb.total_luck_money += stream_donations;
            break;
        }

        case 18: {
            printf(CYAN"[%02d.%d] Сосед попросил Боба починить компьютер. Оплата за сервис: +3 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 3000;
            Bob.vtb.total_luck_money += 3000;
            break;
        }

        case 19: {
            printf(CYAN"[%02d.%d] Боб нашел редкую монету в сдаче. Продал нумизмату: +15 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 15000;
            Bob.vtb.total_luck_money += 15000;
            break;
        }

        case 20: {
            printf(CYAN"[%02d.%d] Боб поучаствовал в платном опросе от крупной компании. +2 500 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 2500;
            Bob.vtb.total_luck_money += 2500;
            break;
        }
        default:

            break;
        }
    }
}

void bob_bad_events(const int month, const int year) {
    int chance_of_bad_event = rand() % 10;
    if (chance_of_bad_event >= 1) {
        int bad_event = rand() % 100;

        switch (bad_event) {
        case 0: {
            RUB bet = 10000;
            printf(RED "[%02d.%d] Боб поставил на спорт: -%lld руб. (Проигрыш)" RESET "\n", month, year, bet);
            Bob.vtb.bankcard -= bet;
            Bob.vtb.total_waste_money += bet;
            break;
        }
        case 1: {
            printf(RED"[%02d.%d] Боб решил шикануть и снял президентский люкс на выходные. -80 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 80000;
            Bob.vtb.total_waste_money += 80000;
            break;
        }
        case 2:
            printf(RED"[%02d.%d] Боб купил последний айфон. Платёж: -80 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 120000;
            Bob.vtb.total_waste_money += 120000;
            break;

        case 3:
            printf(RED"[%02d.%d] Боб решил стать крипто-инвестором и купил мемкоин, который через неделю упал. -20 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 20000;
            Bob.vtb.total_waste_money += 20000;
            break;

        case 4: {
            printf(RED"[%02d.%d] Боб уволился с работы, надеясь на фриланс. Зарплата упала на 30%%!" RESET "\n", month, year);
            Bob.vtb.salary *= 0.7;
            break;
        }
        case 5: {
            printf(RED"[%02d.%d] Боб повелся на лохотрон в парке. -3000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 3000;
            Bob.vtb.total_waste_money += 3000;
            break;
        }
        case 6: {
            printf(RED"[%02d.%d] Боб решил стать музыкантом и купил гитару" RESET "\n", month, year);
            Bob.vtb.bankcard -= 15000;
            Bob.vtb.total_waste_money += 15000;
            break;

        case 7: {
            RUB car_fine = 5000;
            printf(RED"[%02d.%d] Боб дрифтил на парковке: Штраф -%lld руб." RESET "\n", month, year, car_fine);
            Bob.vtb.bankcard -= car_fine;
            Bob.vtb.total_waste_money += car_fine;
            break;
        }

        case 8:
            printf(RED"[%02d.%d] Боб купил 'курс успешного успеха'. -30 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 30000;
            Bob.vtb.total_waste_money += 30000;
            break;

        case 9: {
            RUB crypto_loss = Bob.vtb.bankcard * 0.2;
            printf(RED"[%02d.%d] Криптобиржа, где Боб хранил деньги, закрылась. Потеря: -%lld руб." RESET "\n", month, year, crypto_loss);
            Bob.vtb.bankcard -= crypto_loss;
            Bob.vtb.total_waste_money += crypto_loss;
            break;
        }

        case 10: {
            RUB bet = 10000;
            printf(RED"[%02d.%d] Боб поставил на спорт: -%lld руб. (Проигрыш)" RESET "\n", month, year, bet);
            Bob.vtb.bankcard -= bet;
            Bob.vtb.total_waste_money += bet;
            break;
        }
        case 12:
            printf(RED"[%02d.%d] Боб не поймал телефон на кондициях. Ремонт: -15 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 15000;
            Bob.vtb.total_waste_money += 15000;
            break;

        case 13:
            printf(RED"[%02d.%d] Боб проспал работу 5 раз. Вычли из зарплаты: -10 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 10000;
            Bob.vtb.total_waste_money += 10000;
            break;

        case 14: {
            RUB party = 25000;
            printf(RED"[%02d.%d] Боб устроил вечеринку для всех друзей. -%lld руб." RESET "\n", month, year, party);
            Bob.vtb.bankcard -= party;
            Bob.vtb.total_waste_money += party;
            break;
        }

        case 15:
            printf(RED"[%02d.%d] Боб купил старый мотоцикл под восстановление. -120 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 120000;
            Bob.vtb.total_waste_money += 120000;
            break;

        case 17:
            printf(RED"[%02d.%d] Боб забыл про подписку на 10 сервисов сразу. -6 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 6000;
            Bob.vtb.total_waste_money += 6000;
            break;

        case 18:
            printf(RED"[%02d.%d] Боб купил лотерейных билетов на всю сдачу. -2 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 2000;
            Bob.vtb.total_waste_money += 2000;
            break;

        case 19: {
            RUB debt_interest = 5000;
            printf(RED"[%02d.%d] Боб взял в долг у соседа, отдал с процентами. -%lld руб." RESET "\n", month, year, debt_interest);
            Bob.vtb.bankcard -= debt_interest;
            break;
        }

        case 20:
            printf(RED"[%02d.%d] Боб просто купил всем пиццу. -3 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 3000;
            Bob.vtb.total_waste_money += 3000;
            break;
        }
        default:

            break;
        }
    }
}


// others

void update_bank_rate(const int month, const int year) {
    if (month % 3 == 0) {
        int change = (rand() % 5) - 2;
        Russia2026.stavka += (float)change;

        if (Russia2026.stavka < 5.0) Russia2026.stavka = 5.0;
        if (Russia2026.stavka > 25.0) Russia2026.stavka = 25.0;

        printf("[%02d.%d]--- НОВОСТИ ЭКОНОМИКИ: Центробанк изменил ставку. Теперь она %.1f%% ---\n", month, year, Russia2026.stavka);
    }
}

void economy_init() {
    Russia2026.inflation_rate = 0.07;
    Russia2026.food_modifier = 1.2;
    Russia2026.car_modifier = 1.5;
    Russia2026.estate_modifier = 1.0;
    Russia2026.stavka = 14.5;
}

void apply_salary_indexation(const int month, const int year) {
    if (month != 1) return;

    printf("\n--- ЕЖЕГОДНАЯ ИНДЕКСАЦИЯ ЗАРПЛАТ (%d год) ---\n", year);

    // 1. Алиса
    if (not Alice.is_bankrupt) 
    {
        float alice_raise = (float)(rand() % 8) / 100.0;
        RUB old_salary_alice = Alice.vtb.salary;
        Alice.vtb.salary += Alice.vtb.salary * alice_raise;

        printf("Алиса: Зарплата выросла на %.1f%% (с %lld до %lld руб.)\n",
            alice_raise * 100, old_salary_alice, Alice.vtb.salary);
    }

    // 2. Боб
    if (not Bob.is_bankrupt) 
    {
        float bob_raise = (float)(rand() % 8) / 100.0;
        RUB old_salary_bob = Bob.vtb.salary;
        Bob.vtb.salary += Bob.vtb.salary * bob_raise;

        printf("Боб: Зарплата выросла на %.1f%% (с %lld до %lld руб.)\n",
            bob_raise * 100, old_salary_bob, Bob.vtb.salary);

        if (bob_raise < Russia2026.inflation_rate) {
            printf("(Внимание: Рост зарплаты Боба ниже уровня инфляции!)\n");
        }
    }
    printf("--------------------------------------------\n\n");
}

void update_business(const int month, const int year, struct Person& p) {
    if (!p.side_business.is_active) return;

    p.side_business.months_active++;

    int success_chance = 60 - (p.side_business.risk_level * 5);
    if (rand() % 100 < success_chance) {
        RUB profit = p.side_business.monthly_profit;
        p.vtb.bankcard += profit;
        if (p.side_business.months_active % 6 == 0) {
            p.side_business.monthly_profit = (RUB)(p.side_business.monthly_profit * 1.2);
            printf("[%02d.%d] Бизнес '%s' растёт! Прибыль: %lld руб.\n",
                month, year, p.side_business.name, p.side_business.monthly_profit);
        }
    }
    else {
        RUB loss = p.side_business.monthly_profit / 2;
        p.vtb.bankcard -= loss;
        printf(MAGENTA "[%02d.%d] Бизнес '%s' принёс убыток: %lld руб.\n" RESET,
            month, year, p.side_business.name, loss);
    }

    if (rand() % 100 < 5 || p.side_business.months_active > 36) {
        printf("[%02d.%d] Бизнес '%s' закрыт.\n", month, year, p.side_business.name);
        p.side_business.is_active = false;
    }
}

void apply_global_inflation(const int month, const int year) {
    Russia2026.monthly_base = Russia2026.inflation_rate / 12.0;
    if (month == 12) {
        float change = (float)((rand() % 40) - 20) / 1000.0;
        Russia2026.inflation_rate += change;

        if (Russia2026.inflation_rate < 0.04) 
        { 
            Russia2026.inflation_rate = 0.04; 
        }

        printf("\n>>> КОНЕЦ ГОДА %d: Инфляция на следующий год: %.1f%% <<<\n\n",
            year, Russia2026.inflation_rate * 100);
    }
}

void init_real_estate_market() {
    MoscowRealEstate.price_growth_rate = 0.06f;
    MoscowRealEstate.rental_yield = 0.05f;
    MoscowRealEstate.bubble_risk = 15;
}

void update_real_estate_market(const int month, const int year) {
    // Ежегодное обновление трендов
    if (month == 1) {
        MoscowRealEstate.price_growth_rate = 0.05f + ((rand() % 100) - 30) / 100.0f;
        MoscowRealEstate.bubble_risk += (rand() % 20) - 10;
        if (MoscowRealEstate.bubble_risk < 0) MoscowRealEstate.bubble_risk = 0;
        if (MoscowRealEstate.bubble_risk > 100) MoscowRealEstate.bubble_risk = 100;

        printf("\n--- НОВОСТИ НЕДВИЖИМОСТИ %d ---\n", year);
        printf("Рост цен: %.2f%% | Риск пузыря: %d%%\n",
            MoscowRealEstate.price_growth_rate * 100, MoscowRealEstate.bubble_risk);

        // Применение роста цен
        if (!Alice.is_bankrupt) {
            Alice.flat.value = (RUB)(Alice.flat.value * (1.0f + MoscowRealEstate.price_growth_rate));
        }
        if (!Bob.is_bankrupt) {
            Bob.flat.value = (RUB)(Bob.flat.value * (1.0f + MoscowRealEstate.price_growth_rate));
        }
    }

    // Схлопывание пузыря
    if (MoscowRealEstate.bubble_risk > 90 && rand() % 100 < 10) {
        float crash = 0.15f + (rand() % 20) / 100.0f;
        if (!Alice.is_bankrupt) Alice.flat.value = (RUB)(Alice.flat.value * (1.0f - crash));
        if (!Bob.is_bankrupt) Bob.flat.value = (RUB)(Bob.flat.value * (1.0f - crash));
        printf(RED "\n!!! КРИЗИС НА РЫНКЕ НЕДВИЖИМОСТИ !!! Цены упали на %.1f%%\n\n" RESET, crash * 100);
        MoscowRealEstate.bubble_risk = 20;
    }
}


void init_stock_market() {
    // Инициализация акций Сбера
    Alice.portfolio.sber.ticker = "SBER";
    Alice.portfolio.sber.price = 280;
    Alice.portfolio.sber.quantity = 0;
    Alice.portfolio.sber.volatility = 0.15f;
    Alice.portfolio.sber.dividend_yield = 15;

    // Газпром
    Alice.portfolio.gazprom.ticker = "GAZP";
    Alice.portfolio.gazprom.price = 170;
    Alice.portfolio.gazprom.quantity = 0;
    Alice.portfolio.gazprom.volatility = 0.20f;
    Alice.portfolio.gazprom.dividend_yield = 8;

    // Яндекс
    Alice.portfolio.yandex.ticker = "YNDX";
    Alice.portfolio.yandex.price = 2500;
    Alice.portfolio.yandex.quantity = 0;
    Alice.portfolio.yandex.volatility = 0.35f;
    Alice.portfolio.yandex.dividend_yield = 0;

    Alice.portfolio.market_sentiment = 0.1f;

    Bob.portfolio = Alice.portfolio;
}

void update_stock_prices(const int month, const int year) {

    float sentiment_change = ((rand() % 100) - 50) / 1000.0f;
    Alice.portfolio.market_sentiment += sentiment_change;
    if (Alice.portfolio.market_sentiment > 1.0f) Alice.portfolio.market_sentiment = 1.0f;
    if (Alice.portfolio.market_sentiment < -1.0f) Alice.portfolio.market_sentiment = -1.0f;
    Bob.portfolio.market_sentiment = Alice.portfolio.market_sentiment;


    auto updateStock = [&](Stock& s_alice, Stock& s_bob) {
        float random_factor = ((rand() % 100) - 50) / 100.0f;
        float change_percent = (random_factor * s_alice.volatility) + (Alice.portfolio.market_sentiment * 0.05f);

        if (rand() % 1000 < 5) {
            change_percent += (rand() % 2 == 0) ? 0.20f : -0.20f;
            printf(RED "[%02d.%d] ВНИМАНИЕ! Резкое движение по акциям %s!\n" RESET,
                month, year, s_alice.ticker.c_str());
        }

        s_alice.price = (RUB)(s_alice.price * (1.0f + change_percent));
        if (s_alice.price < 1) s_alice.price = 1;
        s_bob.price = s_alice.price;

        if (month % 3 == 0) {
            if (s_alice.quantity > 0) {
                RUB div_payment = s_alice.dividend_yield * s_alice.quantity;
                Alice.vtb.bankcard += div_payment;
                printf(GREEN "[%02d.%d] Дивиденды %s: +%lld руб.\n" RESET,
                    month, year, s_alice.ticker.c_str(), div_payment);
            }
            if (s_bob.quantity > 0) {
                RUB div_payment = s_bob.dividend_yield * s_bob.quantity;
                Bob.vtb.bankcard += div_payment;
                printf(CYAN "[%02d.%d] Дивиденды %s: +%lld руб.\n" RESET,
                    month, year, s_bob.ticker.c_str(), div_payment);
            }
        }
        };

    updateStock(Alice.portfolio.sber, Bob.portfolio.sber);
    updateStock(Alice.portfolio.gazprom, Bob.portfolio.gazprom);
    updateStock(Alice.portfolio.yandex, Bob.portfolio.yandex);
}

void alice_investment_strategy(const int month, const int year) {
    if (Alice.is_bankrupt) return;

    if ((month == 6 || month == 12) && Alice.vtb.bankcard > 50000) {
        int qty = 100;
        RUB cost = qty * Alice.portfolio.sber.price;
        if (cost <= Alice.vtb.bankcard) {
            Alice.portfolio.sber.quantity += qty;
            Alice.vtb.bankcard -= cost;
            printf("[%02d.%d] Алиса купила %d акций Сбера за %lld руб.\n",
                month, year, qty, cost);
        }
    }
}

void bob_trading_strategy(const int month, const int year) {
    if (Bob.is_bankrupt || Bob.army.is_in_army) return;

    if (rand() % 100 < 25 && Bob.vtb.bankcard > 10000) {
        int qty = 10;
        RUB cost = qty * Bob.portfolio.yandex.price;
        if (cost <= Bob.vtb.bankcard) {
            Bob.portfolio.yandex.quantity += qty;
            Bob.vtb.bankcard -= cost;
            printf("[%02d.%d] Боб купил %d акций Яндекса за %lld руб.\n",
                month, year, qty, cost);
        }
    }

    if (rand() % 100 < 15 && Bob.portfolio.yandex.quantity > 0) {
        RUB revenue = Bob.portfolio.yandex.quantity * Bob.portfolio.yandex.price;
        Bob.vtb.bankcard += revenue;
        printf("[%02d.%d] Боб продал акции Яндекса за %lld руб.\n", month, year, revenue);
        Bob.portfolio.yandex.quantity = 0;
    }
}
 
void global_economic_events(const int month, const int year) {
    int event_roll = rand() % 1000;

    // Санкции
    if (event_roll < 3) {
        printf(RED "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!! ГЛОБАЛЬНОЕ СОБЫТИЕ: ВВЕДЕНЫ НОВЫЕ САНКЦИИ !!!\n");
        printf("!!! Курс рубля резко упал, инфляция ускоряется. !!!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n" RESET);
        USD_RUB_Rate *= 1.25f;
        Russia2026.inflation_rate += 0.02f;
        Russia2026.stavka += 5.0f;
        printf("Новый курс USD/RUB: %.2f | Инфляция: %.1f%% | Ставка ЦБ: %.1f%%\n",
            USD_RUB_Rate, Russia2026.inflation_rate * 100, Russia2026.stavka);
    }

    // Неурожай
    if (event_roll > 900 && event_roll < 920) {
        printf(YELLOW "\n[%02d.%d] НОВОСТИ: Неурожай. Цены на продукты выросли!\n" RESET, month, year);
        Russia2026.food_modifier += 0.3f;
    }

    // Обвал нефти
    if (event_roll > 950) {
        printf(MAGENTA "\n[%02d.%d] НОВОСТИ: Обвал цен на нефть.\n" RESET, month, year);
        USD_RUB_Rate *= 1.15f;
        Russia2026.inflation_rate += 0.01f;
    }
}

void take_initial_snapshot() {
    // Alice
    GameSnapshot.alice_start_salary = Alice.vtb.salary;
    GameSnapshot.alice_start_flat_value = Alice.flat.value;
    GameSnapshot.alice_start_bankcard = Alice.vtb.bankcard;
    GameSnapshot.alice_start_deposit = Alice.vtb.deposit;
    GameSnapshot.alice_start_age = Alice.age;

    // Bob
    GameSnapshot.bob_start_salary = Bob.vtb.salary;
    GameSnapshot.bob_start_flat_value = Bob.flat.value;
    GameSnapshot.bob_start_bankcard = Bob.vtb.bankcard;
    GameSnapshot.bob_start_deposit = Bob.vtb.deposit;
    GameSnapshot.bob_start_age = Bob.age;

    // Economy
    GameSnapshot.start_inflation = Russia2026.inflation_rate;
    GameSnapshot.start_stavka = Russia2026.stavka;
    GameSnapshot.start_usd = USD_RUB_Rate;

    printf("\n=== НАЧАЛЬНЫЙ СНИМОК СОСТОЯНИЯ СДЕЛАН ===\n");
}

void update_currency_rates(const int month, const int year) {
    float usd_change = ((rand() % 200) - 50) / 100.0f;
    USD_RUB_Rate += usd_change;
    if (USD_RUB_Rate < 60.0f) USD_RUB_Rate = 60.0f;
    if (USD_RUB_Rate > 150.0f) USD_RUB_Rate = 150.0f;

    if (month == 12) {
        printf("\n=== КУРС USD/RUB НА КОНЕЦ %d ГОДА: %.2f ===\n", year, USD_RUB_Rate);
    }
}

void print_personal_growth_report(const char* name, RUB start_capital, RUB end_capital, RUB start_salary, RUB end_salary, int age_passed) {
    printf("\n--- АНАЛИЗ ИЗМЕНЕНИЙ ДЛЯ %s ---\n", name);
    printf("Возраст: +%d лет\n", age_passed);

    RUB capital_diff = end_capital - start_capital;
    float capital_growth_percent = (start_capital > 0) ? (float)capital_diff / start_capital * 100.0f : 0.0f;

    printf("Капитал: %lld руб. -> %lld руб. (Изменение: %+lld руб., %.2f%%)\n", start_capital, end_capital, capital_diff, capital_growth_percent);

    RUB salary_diff = end_salary - start_salary;
    float salary_growth_percent = (start_salary > 0) ? (float)salary_diff / start_salary * 100.0f : 0.0f;
    printf("Зарплата: %lld руб. -> %lld руб. (Изменение: %+lld руб., %.2f%%)\n",
        start_salary, end_salary, salary_diff, salary_growth_percent);
}

void print_final_comparison() {
    printf("\n\n");
    printf("============================================================\n");
    printf("               ИТОГОВЫЙ СРАВНИТЕЛЬНЫЙ АНАЛИЗ                 \n");
    printf("============================================================\n");

    RUB alice_end_capital = Alice.vtb.capital;
    RUB bob_end_capital = Bob.vtb.capital;
    RUB alice_start_capital_total = GameSnapshot.alice_start_flat_value + GameSnapshot.alice_start_bankcard + GameSnapshot.alice_start_deposit;
    RUB bob_start_capital_total = GameSnapshot.bob_start_flat_value + GameSnapshot.bob_start_bankcard + GameSnapshot.bob_start_deposit;

    print_personal_growth_report("АЛИСА", alice_start_capital_total, alice_end_capital,
        GameSnapshot.alice_start_salary, Alice.vtb.salary,
        Alice.age - GameSnapshot.alice_start_age);

    print_personal_growth_report("БОБ", bob_start_capital_total, bob_end_capital,
        GameSnapshot.bob_start_salary, Bob.vtb.salary,
        Bob.age - GameSnapshot.bob_start_age);

    printf("\n--- МАКРОЭКОНОМИЧЕСКИЕ ИЗМЕНЕНИЯ ---\n");
    printf("Инфляция: %.2f%% -> %.2f%%\n", GameSnapshot.start_inflation * 100, Russia2026.inflation_rate * 100);
    printf("Ключевая ставка ЦБ: %.2f%% -> %.2f%%\n", GameSnapshot.start_stavka, Russia2026.stavka);
    printf("Курс USD/RUB: %.2f -> %.2f (Рубль %s)\n", GameSnapshot.start_usd, USD_RUB_Rate,
        (USD_RUB_Rate > GameSnapshot.start_usd) ? "ослаб" : "укрепился");

    printf("\n--- СТАТИСТИКА УДАЧИ ---\n");
    printf("Алиса: Повезло на %lld руб. | Не повезло на %lld руб. (Баланс удачи: %+lld)\n",
        Alice.vtb.total_luck_money, Alice.vtb.total_waste_money,
        Alice.vtb.total_luck_money - Alice.vtb.total_waste_money);
    printf("Боб:   Повезло на %lld руб. | Не повезло на %lld руб. (Баланс удачи: %+lld)\n",
        Bob.vtb.total_luck_money, Bob.vtb.total_waste_money,
        Bob.vtb.total_luck_money - Bob.vtb.total_waste_money);

    printf("============================================================\n");
}


void simulation()
{
    int month = 2;
    int year = 2026;

    while (!((month == 3) && (year == 2030))) {
        
        apply_salary_indexation(month, year);

        apply_global_inflation(month, year);

        update_bank_rate(month, year);

        bob_military(month, year);

        global_economic_events(month, year);

        update_stock_prices(month, year);

        update_real_estate_market(month, year);

        update_currency_rates(month, year);

        if (not Alice.is_bankrupt) {
			alice_stats(month, year);
            alice_good_events(month, year);
            alice_bad_events(month, year);
            alice_inflation(month, year);
            alice_salary(month, year);
            alice_investment_strategy(month, year);
            alice_pay_mortgage(month, year);
            alice_housing_expenses(month, year);
            alice_food_expenses(month, year);
            alice_car_expenses(month, year);
            alice_pet_expenses(month, year);
            alice_extrawork(month, year);
            alice_start_business(month, year);
            update_business(month, year, Alice);
            alice_deposit();
            alice_check_bankruptcy(month, year);
        }

        if (not Bob.is_bankrupt && not Bob.army.is_in_army) {
            bob_stats(month, year);
            bob_bad_events(month, year);
            bob_good_events(month, year);
            bob_inflation(month, year);
            bob_food_expenses(month, year);
            bob_car_expenses(month, year);
            bob_fun_expenses(month, year);
            bob_pet_expenses(month, year);
            bob_extrawork(month, year);
            bob_deposit(month,year);
            bob_salary(month, year);
            bob_pay_mortgage(month, year);
            bob_trading_strategy(month, year);
            bob_start_business(month, year);
            update_business(month, year, Bob);
            bob_check_bankruptcy(month, year);
            bob_check_military(month, year);
        }

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}

// Финальная часть

void print_results()
{
    printf("\nБанковский счет Алисы = %lld\n", Alice.vtb.bankcard);
    printf("Вклад Алисы = %lld\n", Alice.vtb.deposit);
    printf("Имущество Алисы = %lld\n", Alice.vtb.capital = Alice.car.value + Alice.flat.value + Alice.pet.value + Alice.vtb.bankcard + Alice.vtb.deposit);
    printf("Алисе повезло = %lld\n", Alice.vtb.total_luck_money);
    printf("Алисе не повезло = %lld\n\n", Alice.vtb.total_waste_money);

    printf("Банковский счет Боба = %lld\n", Bob.vtb.bankcard);
    printf("Вклад Боба = %lld\n", Bob.vtb.deposit);
    printf("Имущество Боба = %lld\n", Bob.vtb.capital = Bob.car.value + Bob.flat.value + Bob.pet.value + Bob.vtb.bankcard + Bob.vtb.deposit);
    printf("Бобу фартануло = %lld\n", Bob.vtb.total_luck_money);
    printf("Бобу не фартануло = %lld\n\n", Bob.vtb.total_waste_money);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //для русского



    bob_init();
    alice_init();

    economy_init();
    bob_init_mortgage();
    alice_init_mortgage();
    init_stock_market();
    init_real_estate_market();

    // Снятие начальных данных до начала симуляции
    take_initial_snapshot();

    simulation();

    print_results();
    print_final_comparison();
}

// pensia
// mikozaim
// wedding
// baby
// po dnyam