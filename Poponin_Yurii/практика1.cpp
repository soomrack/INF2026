#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // для русского
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

// Bob
void bob_init();
void bob_inflation();

// other
void alice_lifestyle(int month, int year);
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
    if (Alice.vtb.capital == 0){//пересмотреть
        Alice.vtb.capital = Alice.flat + Alice.car.value + Alice.pet.value + Alice.vtb.bankcard;
    }
    Alice.vtb.capital += Alice.vtb.bankcard + Alice.vtb.deposit;
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
    Alice.vtb.bankcard += Alice.pet.filler + Alice.pet.food;
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
    if ((rand() % 100) > 40) return; // Происходит в 40% случаев

    int event_id = rand() % 20; // 20 вариантов событий

    switch (event_id) {
    case 0:
        printf("[%02d.%d] Стоматолог: Замена пломбы. -7 000 руб.\n", month, year);
        Alice.vtb.bankcard -= 7000;
        break;

    case 1: {
        RUB bonus = Alice.vtb.salary * 0.5;
        printf("[%02d.%d] Премия: Хороший отчет! +%lld руб.\n", month, year, bonus);
        Alice.vtb.bankcard += bonus;
        break;
    }

    case 2:
        printf("[%02d.%d] Авто: Прокол колеса и шиномонтаж. -4 500 руб.\n", month, year);
        Alice.vtb.bankcard -= 4500;
        break;

    case 3:
        printf("[%02d.%d] Кот: Визит к ветеринару. -3 500 руб.\n", month, year);
        Alice.vtb.bankcard -= 3500;
        break;

    case 4:
        printf("[%02d.%d] Родственники: Свадьба троюродного брата (подарок). -15 000 руб.\n", month, year);
        Alice.vtb.bankcard -= 15000;
        break;

    case 5:
        printf("[%02d.%d] Быт: Сломалась микроволновка. -12 000 руб.\n", month, year);
        Alice.vtb.bankcard -= 12000;
        break;

    case 6: {
        RUB win = 50000;
        printf("[%02d.%d] Лотерея: Малый выигрыш! +%lld руб.\n", month, year, win);
        Alice.vtb.bankcard += win;
        break;
    }

    case 7:
        printf("[%02d.%d] Штраф: Превышение скорости на трассе. -500 руб.\n", month, year);
        Alice.vtb.bankcard -= 500;
        break;

    case 8:
        printf("[%02d.%d] Отпуск: Горящий тур в Сочи. -60 000 руб.\n", month, year);
        Alice.vtb.bankcard -= 60000;
        break;

    case 9:
        printf("[%02d.%d] ЖКХ: Перерасчет за отопление. -4 000 руб.\n", month, year);
        Alice.vtb.bankcard -= 4000;
        break;

    case 10:
        printf("[%02d.%d] Обучение: Куплена книга по алгоритмам. -2 500 руб.\n", month, year);
        Alice.vtb.bankcard -= 2500;
        break;

    case 11:
        printf("[%02d.%d] Здоровье: Курс витаминов. -3 000 руб.\n", month, year);
        Alice.vtb.bankcard -= 3000;
        break;

    case 12: {
        RUB cashback = Alice.food * 0.05;
        printf("[%02d.%d] Банк: Выплачен кешбэк за продукты. +%lld руб.\n", month, year, cashback);
        Alice.vtb.bankcard += cashback;
        break;
    }

    case 13:
        printf("[%02d.%d] Удача: Нашла 1000 рублей на тротуаре. +1 000 руб.\n", month, year);
        Alice.vtb.bankcard += 1000;
        break;

    case 14:
        printf("[%02d.%d] Гаджеты: Разбила экран телефона. -18 000 руб.\n", month, year);
        Alice.vtb.bankcard -= 18000;
        break;

    case 15:
        printf("[%02d.%d] Налоги: Пришло уведомление за авто и квартиру. -25 000 руб.\n", month, year);
        Alice.vtb.bankcard -= 25000;
        break;

    case 16:
        printf("[%02d.%d] Праздник: Покупка подарков на Новый Год. -30 000 руб.\n", month, year);
        Alice.vtb.bankcard -= 30000;
        break;

    case 17: {
        printf("[%02d.%d] Карьера: Индексация зарплаты за выслугу лет! +5%%\n", month, year);
        Alice.vtb.salary *= 1.05;
        break;
    }

    case 18:
        printf("[%02d.%d] Подписки: Списали за музыку и кино. -1 200 руб.\n", month, year);
        Alice.vtb.bankcard -= 1200;
        break;

    case 19:
        printf("[%02d.%d] Спорт: Абонемент в фитнес-клуб. -20 000 руб.\n", month, year);
        Alice.vtb.bankcard -= 20000;
        break;

    default:
        break;
    }
}




// Bob

void bob_init()
{
    Bob.flat = 0;
    Bob.vtb.bankcard = 0;
    Bob.vtb.deposit = 0;
    Bob.vtb.salary = 2910;
    Bob.food = 20'000;
    Bob.vtb.capital = 0;

    Bob.car.value = 2'400'000;
    Bob.car.gas = 15'000;

    Bob.pet.filler = 3000;
    Bob.pet.food = 5000;
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
            printf("[%02d.%d] Боб поставил на спорт: -%lld руб. (Проигрыш)\n", month, year, bet);
            Bob.vtb.bankcard -= bet;
            Bob.vtb.total_waste_money += bet;
            break;
        }
        case 1: {
            printf("[%02d.%d] Боб решил шикануть и снял президентский люкс на выходные. -80 000 руб.\n", month, year);
            Bob.vtb.bankcard -= 80000;
            break;
        }
        case 2:
            printf("[%02d.%d] Боб купил последний айфон. Платёж: -80 000 руб.\n", month, year);
            Bob.vtb.bankcard -= 80000;
            break;
        case 3:
            printf("[%02d.%d] Боб решил стать крипто-инвестором и купил мемкоин, который через неделю упал. -20 000 руб.\n", month, year);
            Bob.vtb.bankcard -= 20000;
            break;
        case 4: {
            printf("[%02d.%d] Боб уволился с работы, надеясь на фриланс. Зарплата упала на 30%%!\n", month, year);
            Bob.vtb.salary *= 0.7;
            break;
        }
        case 5: {
            printf("[%02d.%d] Боб повелся на лохотрон в парке. -3000 руб.\n", month, year);
            Bob.vtb.bankcard -= 3000;
            break;
        }
        case 6: {
            printf("[%02d.%d] Боб решил стать музыкантом и купил гитару\n", month, year);
            Bob.vtb.bankcard -= 15000;
            break;
        case 7: {
            RUB car_fine = 5000;
            printf("[%02d.%d] Боб дрифтил на парковке: Штраф -%lld руб.\n", month, year, car_fine);
            Bob.vtb.bankcard -= car_fine;
            break;
        }

        case 8:
            printf("[%02d.%d] Боб увидел рекламу и купил 'курс успешного успеха'. -30 000 руб.\n", month, year);
            Bob.vtb.bankcard -= 30000;
            break;

        case 9: {
            RUB crypto_loss = Bob.vtb.bankcard * 0.2;
            printf("[%02d.%d] Криптобиржа, где Боб хранил деньги, закрылась. Потеря: -%lld руб.\n", month, year, crypto_loss);
            Bob.vtb.bankcard -= crypto_loss;
            break;
        }

        case 10: {
            RUB bet = 10000;
            printf("[%02d.%d] Боб поставил на спорт: -%lld руб. (Проигрыш)\n", month, year, bet);
            Bob.vtb.bankcard -= bet;
            Bob.vtb.total_waste_money += bet;
            break;
        }
        case 12:
            printf("[%02d.%d] Боб не поймал телефон на кондициях. Ремонт: -15 000 руб.\n", month, year);
            Bob.vtb.bankcard -= 15000;
            break;

        case 13:
            printf("[%02d.%d] Боб проспал работу 5 раз. Вычли из зарплаты: -10 000 руб.\n", month, year);
            Bob.vtb.bankcard -= 10000;
            break;

        case 14: {
            RUB party = 25000;
            printf("[%02d.%d] Боб устроил вечеринку для всех друзей. -%lld руб.\n", month, year, party);
            Bob.vtb.bankcard -= party;
            break;
        }

        case 15:
            printf("[%02d.%d] Боб купил старый мотоцикл под восстановление. -120 000 руб.\n", month, year);
            Bob.vtb.bankcard -= 120000;
            break;

        case 17:
            printf("[%02d.%d] Боб забыл про подписку на 10 сервисов сразу. -6 000 руб.\n", month, year);
            Bob.vtb.bankcard -= 6000;
            break;

        case 18:
            printf("[%02d.%d] Боб купил лотерейных билетов на всю сдачу. -2 000 руб.\n", month, year);
            Bob.vtb.bankcard -= 2000;
            break;

        case 19: {
            RUB debt_interest = 5000;
            printf("[%02d.%d] Боб взял в долг у соседа, отдал с процентами. -%lld руб.\n", month, year, debt_interest);
            Bob.vtb.bankcard -= debt_interest;
            break;
        }

        case 20:
            printf("[%02d.%d] Боб просто купил всем пиццу. -3 000 руб.\n", month, year);
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
            printf("[%02d.%d] Боб нашел на улице 5000 руб.!\n", month, year);
            Bob.vtb.bankcard += 5000;
            break;

        case 1:
            printf("[%02d.%d] Старый долг вернули Бобу. +10 000 руб.\n", month, year);
            Bob.vtb.bankcard += 10000;
            break;

        case 2:
            printf("[%02d.%d] Боб выиграл бесплатный ужин. Экономия! +2 000 руб.\n", month, year);
            Bob.vtb.bankcard += 2000;
            break;

        case 4: {
            RUB win = 150000;
            printf("[%02d.%d] Боб выиграл в казино! Выигрыш: +%lld руб.\n", month, year, win);
            Bob.vtb.bankcard += win;
            Bob.vtb.total_luck_money += win;
            break;
        }
        case 5: {
            printf("[%02d.%d] Боб нашел подработку курьером на выходные. +15 000 руб.\n", month, year);
            Bob.vtb.bankcard += 15000;
            break;
        }
        case 6: {
            RUB win = 200000;
            printf("[%02d.%d] Боб выиграл в онлайн-покер: +%lld руб.\n", month, year, win);
            Bob.vtb.bankcard += win;
            Bob.vtb.total_luck_money += win;
            break;
        }
        case 7: {
            RUB win = 100000;
            printf("[%02d.%d] Боб выиграл в лотерею: +%lld руб.\n", month, year, win);
            Bob.vtb.bankcard += win;
            Bob.vtb.total_luck_money += win;
            break;
        }
        case 8: {
            RUB sell_item = 15000;
            printf("[%02d.%d] Боб продал старый хлам с балкона на барахолке. +%lld руб.\n", month, year, sell_item);
            Bob.vtb.bankcard += sell_item;
            break;
        }

        case 9: {
            printf("[%02d.%d] Боб нашел баг в приложении банка. Ему выплатили вознаграждение! +50 000 руб.\n", month, year);
            Bob.vtb.bankcard += 50000;
            break;
        }

        case 10: {
            RUB tax_return = 13000;
            printf("[%02d.%d] Боб наконец-то подал на налоговый вычет. Пришли деньги: +%lld руб.\n", month, year, tax_return);
            Bob.vtb.bankcard += tax_return;
            break;
        }

        case 11: {
            printf("[%02d.%d] Боб удачно зашел в крипту на «низах». Быстрая прибыль: +25 000 руб.\n", month, year);
            Bob.vtb.bankcard += 25000;
            break;
        }

        case 12: {
            printf("[%02d.%d] Боб выиграл в конкурсе репостов новый смартфон и сразу его продал. +70 000 руб.\n", month, year);
            Bob.vtb.bankcard += 70000;
            break;
        }

        case 13: {
            RUB part_time = 12000;
            printf("[%02d.%d] Боб подработал диджеем на вечеринке у друга. +%lld руб.\n", month, year, part_time);
            Bob.vtb.bankcard += part_time;
            break;
        }

        case 14: {
            printf("[%02d.%d] Боб нашел забытую заначку в зимней куртке. Какая радость! +8 000 руб.\n", month, year);
            Bob.vtb.bankcard += 8000;
            break;
        }

        case 15: {
            printf("[%02d.%d] Родственники прислали Бобу денег «на витамины». +10 000 руб.\n", month, year);
            Bob.vtb.bankcard += 10000;
            break;
        }

        case 16: {
            printf("[%02d.%d] Боб сдал пустые бутылки из-под элитного газировки (шутка). Кешбэк от магазина: +1 500 руб.\n", month, year);
            Bob.vtb.bankcard += 1500;
            break;
        }

        case 17: {
            RUB stream_donations = 5000;
            printf("[%02d.%d] Боб провел стрим, как он учит C. Накидали донатов: +%lld руб.\n", month, year, stream_donations);
            Bob.vtb.bankcard += stream_donations;
            break;
        }

        case 18: {
            printf("[%02d.%d] Сосед попросил Боба починить компьютер. Оплата за сервис: +3 000 руб.\n", month, year);
            Bob.vtb.bankcard += 3000;
            break;
        }

        case 19: {
            printf("[%02d.%d] Боб нашел редкую монету в сдачи. Продал нумизмату: +15 000 руб.\n", month, year);
            Bob.vtb.bankcard += 15000;
            break;
        }

        case 20: {
            printf("[%02d.%d] Боб поучаствовал в платном опросе от крупной компании. +2 500 руб.\n", month, year);
            Bob.vtb.bankcard += 2500;
            break;
        }
        }
    }
}



// others
void simulation()
{
    int month = 2;
    int year = 2026;

    while (!((month == 3) && (year == 2027))) {
        alice_capital();
        alice_pet();
        alice_food();
        alice_car();
        alice_deposit();
        alice_inflation();
        alice_salary(month, year); //добавить боба
        alice_lifestyle(month, year);
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
    printf("bank acc = %lld\n", Alice.vtb.bankcard);
    printf("deposit = %lld\n", Alice.vtb.deposit);
    printf("capital = %lld", Alice.vtb.capital);
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