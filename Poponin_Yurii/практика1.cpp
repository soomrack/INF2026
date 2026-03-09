#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // для русского
#define RESET   "\033[0m"
#define RED     "\033[31m"      // Цвет для плохих событий Боба
#define GREEN   "\033[32m"      // Цвет для хороших событий Алисы
#define YELLOW  "\033[33m"      // Цвет для общих новостей
#define BLUE    "\033[34m"      // Цвет для Боба
#define MAGENTA "\033[35m"      // Цвет для Алисы
#define CYAN    "\033[36m"      // Цвет для системных данных

using RUB = long long int;

//Структуры

struct Pet{
    RUB value;
    RUB food;
    RUB filler;
};

struct Car {
    RUB value;
    RUB gas;
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


struct Person {
    RUB flat;
    RUB food;
    struct Bank vtb;
    struct Car car;
    struct Pet pet;
};

struct Person Alice;
struct Person Bob;


float pp = 14.5; // пересмотреть
int month = 2;
int year = 2026;

// Объявление функций


// Alice
void alice_salary(const int month, const int year);
void alice_deposit();
void alice_capital();
void alice_food();
void alice_car();
void alice_inflation();
void alice_pet();
void alice_init();
void alice_lifestyle(int month, int year);

// Bob
void bob_salary(const int month, const int year);
void bob_deposit();
void bob_capital();
void bob_food();
void bob_car();
void bob_inflation();
void bob_pet();
void bob_init();
void bob_lifestyle(int month, int year);

// other
void simulation();



// Определение функций

// Alice

void alice_salary(const int month, const int year) 
{
    if ((month == 8) && (year == 2026)){
        Alice.vtb.salary *= 1.5;
    }

    Alice.vtb.bankcard += Alice.vtb.salary;
}

void alice_deposit()
{
    Alice.vtb.deposit += Alice.vtb.deposit * pp / 12 / 100;
    RUB money = Alice.vtb.salary / 10;
    Alice.vtb.deposit += money; 
    Alice.vtb.bankcard -= money;
}

void alice_capital()
{
    if ((month == 2) && (year == 2026)) {
        Alice.vtb.capital = Alice.flat + Alice.car.value + Alice.pet.value + Alice.vtb.bankcard;
    }
    Alice.vtb.capital += Alice.vtb.deposit;
}

void alice_food()
{
    Alice.vtb.bankcard -= Alice.food;
}

void alice_car()
{
    Alice.vtb.bankcard -= Alice.car.gas;
}

void alice_pet()
{
    Alice.vtb.bankcard -= Alice.pet.filler + Alice.pet.food;
}

void alice_init()
{
    Alice.flat = 8'000'000;
    Alice.vtb.bankcard = 0;
    Alice.vtb.deposit = 0;
    Alice.vtb.salary = 180'000;
    Alice.food = 20'000;
    Alice.vtb.capital = 0;

    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;

    Alice.pet.filler = 3000;
    Alice.pet.food = 5000;

    Alice.vtb.total_waste_money = 0;
    Alice.vtb.total_luck_money = 0;
}

void alice_inflation() {
    Alice.flat *= 0.09 / 12 / 100;
    Alice.food *= 1.04;
    Alice.car.gas *= 1.03;  //добавить рандом
    Alice.car.value *= 1.03;
    Alice.pet.filler *= 1.01;
    Alice.pet.food *= 1.02;
}

void alice_lifestyle(int month, int year) {
    if ((rand() % 100) > 30) return;
    int good_or_bad_event = rand() % 10;

    if (good_or_bad_event <= 7) {
        int good_event = rand() % 100;
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
            break;

        case 3:
            printf(GREEN "[%02d.%d] Кэшбэк за страховку квартиры. +3 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 3500;
            break;

        case 4:
            printf(GREEN "[%02d.%d] Алиса выиграла грант на обучение. Сэкономлено: +40 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 40000;
            break;

        case 5:
            printf(GREEN "[%02d.%d] Премия за «сотрудника месяца». +25 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 25000;
            Alice.vtb.total_luck_money += 25000;
            break;

        case 6:
            printf(GREEN "[%02d.%d] Подарок от друзей на праздник. +10 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 10000;
            break;

        case 7:
            printf(GREEN "[%02d.%d] Удачная подработка консультантом. +12 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 12000;
            break;

        case 8:
            printf(GREEN "[%02d.%d] Возврат переплаты по ЖКХ. +2 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 2000;
            break;

        case 9:
            printf(GREEN "[%02d.%d] Алиса нашла забытый подарочный сертификат. +3 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 3000;
            break;

        case 10:
            printf(GREEN "[%02d.%d] Алиса продала старые учебники на барахолке. +4 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 4000;
            break;

        case 11:
            printf(GREEN "[%02d.%d] Начисление процентов на остаток по карте. +1 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 1500;
            break;

        case 12:
            printf(GREEN "[%02d.%d] Алиса нашла промокод на скидку в 50%% на продукты. Сэкономлено: +5 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 5000;
            break;

        case 13:
            printf(GREEN "[%02d.%d] Удачная консультация по проекту в свободное время. +18 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 18000;
            break;

        case 14:
            printf(GREEN "[%02d.%d] Алиса получила кэшбэк за покупку авиабилетов. +6 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 6000;
            break;

        case 15:
            printf(GREEN "[%02d.%d] Друзья вернули давний долг, про который Алиса забыла. +10 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 10000;
            break;

        case 16:
            printf(GREEN "[%02d.%d] Алиса выиграла в корпоративной лотерее сертификат. +5 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 5000;
            break;

        case 17:
            printf(GREEN "[%02d.%d] Страховая компания выплатила компенсацию за задержку рейса. +3 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 3000;
            break;

        case 18:
            printf(GREEN "[%02d.%d] Алиса сдала ненужную одежду в ресейл-магазин. +2 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 2500;
            break;

        case 19:
            printf(GREEN "[%02d.%d] Алиса нашла 500 рублей в кармане старого пальто. +500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard += 500;
            break;
        default:

            break;
        }
    }
    else {
        int bad_event = rand() % 100;
        switch (bad_event) {
        case 0:
            printf(MAGENTA"[%02d.%d] Алиса потеряла зонт и купила новый. -2 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 2500;
            Alice.vtb.total_waste_money += 2500;
            break;

        case 1:
            printf(MAGENTA"[%02d.%d] Повышение стоимости интернета. Разовая доплата: -1 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 1000;
            break;

        case 2:
            printf(MAGENTA"[%02d.%d] Алиса случайно разбила любимую кружку. -800 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 800;
            break;

        case 3:
            printf(MAGENTA"[%02d.%d] Платный вебинар оказался бесполезным. -3 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 3000;
            Alice.vtb.total_waste_money += 3000;
            break;

        case 4:
            printf(MAGENTA"[%02d.%d] Комиссия за перевод в другой банк. -500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 500;
            break;

        case 5:
            printf(MAGENTA "[%02d.%d] Алиса случайно оставила включенным свет на месяц. Счет за свет: -2 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 2000;
            break;

        case 6:
            printf(MAGENTA "[%02d.%d] Потребовалась срочная чистка ноутбука от пыли. -3 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 3500;
            break;

        case 7:
            printf(MAGENTA "[%02d.%d] Алиса опоздала на поезд, пришлось брать новый билет. -4 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 4000;
            break;

        case 8:
            printf(MAGENTA "[%02d.%d] Пролила кофе на важные документы, перевыпуск: -1 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 1500;
            break;

        case 9:
            printf(MAGENTA "[%02d.%d] Траты на подарок коллеге, на который скидывались всем отделом. -2 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 2000;
            break;

        case 10:
            printf(MAGENTA "[%02d.%d] У Алисы закончилась память в облаке, оплата за год: -3 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 3000;
            break;

        case 11:
            printf(MAGENTA "[%02d.%d] Внезапный визит к платному врачу. -5 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 5000;
            break;

        case 12:
            printf(MAGENTA "[%02d.%d] Алиса купила книгу, которую уже читала. -1 200 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 1200;
            break;

        case 13:
            printf(MAGENTA "[%02d.%d] Порвались любимые кроссовки. Покупка новых: -8 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 8000;
            break;

        case 14:
            printf(MAGENTA "[%02d.%d] Алиса забыла отменить пробный период приложения. -900 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 900;
            break;

        case 15:
            printf(MAGENTA "[%02d.%d] Мелкий ремонт сантехники в ванной. -2 500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 2500;
            break;

        case 16:
            printf(MAGENTA "[%02d.%d] Штраф за неправильный переход дороги (пешеход). -500 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 500;
            break;

        case 17:
            printf(MAGENTA "[%02d.%d] Потерялась любимая помада, покупка новой: -2 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 2000;
            break;

        case 18:
            printf(MAGENTA "[%02d.%d] Алиса попала под ливень без зонта. Химчистка пальто: -3 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 3000;
            break;

        case 19:
            printf(MAGENTA "[%02d.%d] Сломались наушники. Покупка новых: -6 000 руб." RESET "\n", month, year);
            Alice.vtb.bankcard -= 6000;
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
        Bob.vtb.salary *= 1.5;
    }

    Bob.vtb.bankcard += Bob.vtb.salary;
}

void bob_deposit()
{
    Bob.vtb.deposit += Bob.vtb.deposit * pp / 12 / 100;
    RUB money = Bob.vtb.salary / 10;
    Bob.vtb.deposit += money;
    Bob.vtb.bankcard -= money;
}

void bob_capital()
{
    if ((month == 3) && (year == 2027)) {
        Bob.vtb.capital = Bob.flat + Bob.car.value + Bob.pet.value + Bob.vtb.bankcard;
    }
    Bob.vtb.capital += Bob.vtb.deposit;
}

void bob_food()
{
    Bob.vtb.bankcard -= Bob.food;
}

void bob_car()
{
    Bob.vtb.bankcard -= Bob.car.gas;
}

void bob_pet()
{
    Bob.vtb.bankcard -= Bob.pet.filler + Bob.pet.food;
}

//void bob_komunalka()

void bob_init()
{
    Bob.flat = 5'000'000;
    Bob.vtb.bankcard = 0;
    Bob.vtb.deposit = 0;
    Bob.vtb.salary = 120'000;
    Bob.food = 20'000;
    Bob.vtb.capital = 0;

    Bob.car.value = 2'400'000;
    Bob.car.gas = 15'000;

    Bob.pet.filler = 1000;
    Bob.pet.food = 3000;

    Bob.vtb.total_waste_money = 0;
    Bob.vtb.total_luck_money = 0;
}

void bob_lifestyle(int month, int year) {
    if ((rand() % 100) > 70) return;

    int good_or_bad_event = rand() % 10;

    if (good_or_bad_event >= 6)
    {
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
            break;
        }
        case 2:
            printf(RED"[%02d.%d] Боб купил последний айфон. Платёж: -80 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 80000;
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
            break;

        case 7: {
            RUB car_fine = 5000;
            printf(RED"[%02d.%d] Боб дрифтил на парковке: Штраф -%lld руб." RESET "\n", month, year, car_fine);
            Bob.vtb.bankcard -= car_fine;
            break;
        }

        case 8:
            printf(RED"[%02d.%d] Боб увидел рекламу и купил 'курс успешного успеха'. -30 000 руб." RESET "\n", month, year);
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
            break;

        case 13:
            printf(RED"[%02d.%d] Боб проспал работу 5 раз. Вычли из зарплаты: -10 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 10000;
            break;

        case 14: {
            RUB party = 25000;
            printf(RED"[%02d.%d] Боб устроил вечеринку для всех друзей. -%lld руб." RESET "\n", month, year, party);
            Bob.vtb.bankcard -= party;
            break;
        }

        case 15:
            printf(RED"[%02d.%d] Боб купил старый мотоцикл под восстановление. -120 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 120000;
            break;

        case 17:
            printf(RED"[%02d.%d] Боб забыл про подписку на 10 сервисов сразу. -6 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard -= 6000;
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
            break;
        }
        default:

            break;
        }
    }
    else {
        int good_event = rand() % 100;
        
        switch (good_event){
        case 0:
            printf(BLUE"[%02d.%d] Боб нашел на улице 5000 руб.!" RESET "\n", month, year);
            Bob.vtb.bankcard += 5000;
            break;

        case 1:
            printf(BLUE"[%02d.%d] Старый долг вернули Бобу. +10 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 10000;
            break;

        case 2:
            printf(BLUE"[%02d.%d] Боб выиграл бесплатный ужин. Экономия! +2 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 2000;
            break;

        case 4: {
            RUB win = 150000;
            printf(BLUE"[%02d.%d] Боб выиграл в казино! Выигрыш: +%lld руб." RESET "\n", month, year, win);
            Bob.vtb.bankcard += win;
            Bob.vtb.total_luck_money += win;
            break;
        }
        case 5: {
            printf(BLUE"[%02d.%d] Боб нашел подработку курьером на выходные. +15 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 15000;
            break;
        }
        case 6: {
            RUB win = 200000;
            printf(BLUE"[%02d.%d] Боб выиграл в онлайн-покер: +%lld руб." RESET "\n", month, year, win);
            Bob.vtb.bankcard += win;
            Bob.vtb.total_luck_money += win;
            break;
        }
        case 7: {
            RUB win = 100000;
            printf(BLUE"[%02d.%d] Боб выиграл в лотерею: +%lld руб." RESET "\n", month, year, win);
            Bob.vtb.bankcard += win;
            Bob.vtb.total_luck_money += win;
            break;
        }
        case 8: {
            RUB sell_item = 15000;
            printf(BLUE"[%02d.%d] Боб продал старый хлам с балкона на барахолке. +%lld руб." RESET "\n", month, year, sell_item);
            Bob.vtb.bankcard += sell_item;
            break;
        }

        case 9: {
            printf(BLUE"[%02d.%d] Боб нашел баг в приложении банка. Ему выплатили вознаграждение! +50 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 50000;
            break;
        }

        case 10: {
            RUB tax_return = 13000;
            printf(BLUE"[%02d.%d] Боб наконец-то подал на налоговый вычет. Пришли деньги: +%lld руб." RESET "\n", month, year, tax_return);
            Bob.vtb.bankcard += tax_return;
            break;
        }

        case 11: {
            printf(BLUE"[%02d.%d] Боб удачно зашел в крипту на «низах». Быстрая прибыль: +25 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 25000;
            break;
        }

        case 12: {
            printf(BLUE"[%02d.%d] Боб выиграл в конкурсе репостов новый смартфон и сразу его продал. +70 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 70000;
            break;
        }

        case 13: {
            RUB part_time = 12000;
            printf(BLUE"[%02d.%d] Боб подработал диджеем на вечеринке у друга. +%lld руб." RESET "\n", month, year, part_time);
            Bob.vtb.bankcard += part_time;
            break;
        }

        case 14: {
            printf(BLUE"[%02d.%d] Боб нашел забытую заначку в зимней куртке. Какая радость! +8 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 8000;
            break;
        }

        case 15: {
            printf(BLUE"[%02d.%d] Родственники прислали Бобу денег «на витамины». +10 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 10000;
            break;
        }

        case 16: {
            printf(BLUE"[%02d.%d] Боб сдал пустые бутылки из-под элитного газировки (шутка). Кешбэк от магазина: +1 500 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 1500;
            break;
        }

        case 17: {
            RUB stream_donations = 5000;
            printf(BLUE"[%02d.%d] Боб провел стрим, как он учит C. Накидали донатов: +%lld руб." RESET "\n", month, year, stream_donations);
            Bob.vtb.bankcard += stream_donations;
            break;
        }

        case 18: {
            printf(BLUE"[%02d.%d] Сосед попросил Боба починить компьютер. Оплата за сервис: +3 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 3000;
            break;
        }

        case 19: {
            printf(BLUE"[%02d.%d] Боб нашел редкую монету в сдачи. Продал нумизмату: +15 000 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 15000;
            break;
        }

        case 20: {
            printf(BLUE"[%02d.%d] Боб поучаствовал в платном опросе от крупной компании. +2 500 руб." RESET "\n", month, year);
            Bob.vtb.bankcard += 2500;
            break;
        }
        default:

            break;
        }
    }
}


// others
void simulation()
{


    while (!((month == 3) && (year == 2040))) {
        alice_capital();
        alice_pet();
        alice_food();
        alice_car();
        alice_deposit();
       // alice_inflation();
        alice_salary(month, year);
        alice_lifestyle(month, year);

        
        bob_capital();
        bob_pet();
        bob_food();
        bob_car();
        bob_deposit();
      //  bob_inflation(); not done 
        bob_salary(month, year);
        bob_lifestyle(month, year);

        ++month;
        if (month == 13) 
        {
            month = 1;
            ++year;
        }
    }
}

// Финальная часть

void print_results()
{
    printf("\nalice bank acc = %lld\n", Alice.vtb.bankcard);
    printf("alice deposit = %lld\n", Alice.vtb.deposit);
    printf("alice capital = %lld\n", Alice.vtb.capital);
    printf("bob bank acc = %lld\n", Bob.vtb.bankcard);
    printf("bob deposit = %lld\n", Bob.vtb.deposit);
    printf("bob capital = %lld", Bob.vtb.capital);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //для русского

    bob_init();

    alice_init();

    simulation();

    print_results();
}