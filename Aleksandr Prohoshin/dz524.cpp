#include <stdlib.h>
#include <time.h>
#include <initializer_list>
#include <stdio.h>

unsigned bounded_rand(unsigned range)
{
    for (unsigned x, r;;)
        if (x = rand(), r = x % range, x - r <= -range)
            return r;
}
using RUB = long long int;  // C++

struct Car {
    RUB value;
    RUB gas;
    int relese_of_car;
    RUB remont;
    int probeg;
};

struct ludo {
    RUB roulet;
    RUB black_jack;
    RUB pocker;
    int poker_skill;
    int black_Jack_skill;
};

struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    Car car;
    ludo ludo;
};

struct Person alice;


void alice_init()
{
    alice.capital = 5'000'000;
    alice.salary = 500'000;
    alice.food = 20'000;

    alice.car.value = 2'400'000;
    alice.car.gas = 12'000;
    alice.car.relese_of_car = 2024;
    alice.car.remont = 100'000;
    alice.car.probeg = 0;
    
    alice.ludo.pocker = 60'000;
    alice.ludo.roulet = 60'000;
    alice.ludo.black_jack = 60'000;
    alice.ludo.poker_skill = 0;
    alice.ludo.black_Jack_skill = 0;
}


float sberbank_interest(RUB sum)
{
    if (sum > 10'000 and sum < 3'000'000) {
        return 11.5;
    }

    if (sum >= 3'000'000) {
        return 12.5;  //  125 -1 +
    }

    return 0.1;
}


void alice_salary(const int year, const int month)
{
    if (month == 3 and year == 2026) {
        alice.salary *= 1.5;
    }

    alice.capital += alice.salary;
}


void alice_food()
{
    //ежедневная еда
    if (alice.capital < 5000000) {
        alice.capital -= alice.food;
    }

    if (alice.capital > 5000000 and alice.capital < 10000000) {
        alice.capital -= 2 * alice.food;
    }

    if (alice.capital > 10000000) {
        alice.capital -= 3 * alice.food;
    }
    // рестораны
    for (int i = 0; i < bounded_rand(3) + 1; i++) {
        int rest_price = bounded_rand(3'000) + 1'000;
        int food_quality = bounded_rand(2);
        int service = bounded_rand(2);
        int clean = bounded_rand(2);
        int location = bounded_rand(2);
        int tips = (food_quality + service + clean + location) * 150;
        int pay = rest_price + tips;
        alice.capital -= pay;
    }
}


void print_results()
{
    printf("Salary = %lld\n", alice.salary);
    printf("Capital = %lld", alice.capital);
}

void casino() 
{
    //рулетка
    alice.capital -= alice.ludo.roulet;
    int zahod = alice.ludo.roulet / 3;
    //на цвет
    for (int i = 0; i < 10; i++) {
        int random = bounded_rand(37);
        if (random < 17) {
            alice.capital += zahod / 5;
        }
    }
    //на тройку
    for (int i = 0; i < 10; i++) {
        int random = bounded_rand(37);
        if (random < 17) {
            alice.capital += zahod / 10 * 12;
        }
    }
    //на число
    for (int i = 0; i < 10; i++) {
        int random = bounded_rand(37);
        if (random == 25) {
            alice.capital += zahod / 10 * 36;
        }
    }
    //покеp
    alice.capital -= alice.ludo.pocker;
    int win = bounded_rand(12 - alice.ludo.poker_skill);
    int win_koef = bounded_rand(10);
    if (win == 1) {
        alice.capital += alice.ludo.pocker * win_koef;
    }

    int skill = bounded_rand(3);
    if (skill == 2 and alice.ludo.poker_skill < 10) {
        alice.ludo.poker_skill += 1;
    }
    // black Jack
    alice.capital -= alice.ludo.black_jack;
    int win = bounded_rand(12 - alice.ludo.black_Jack_skill);
    int win_koef = bounded_rand(5);
    if (win == 1) {
        alice.capital += alice.ludo.pocker * win_koef;
    }

    int skill = bounded_rand(2);
    if (skill == 1 and alice.ludo.black_Jack_skill < 10) {
        alice.ludo.black_Jack_skill += 1;
    }
}

void alice_car(const int month, const int year)
{
    alice.capital -= alice.car.gas;//бенз
    //пробег
    int probeg_mes = bounded_rand(400) + 300;
    alice.car.probeg += probeg_mes;
    //тех осмотр
    if (month == 5 or month == 11) {
        alice.capital -= alice.car.value * 0, 01;
    }
    //вероятная поломка
    int s = 1000 - probeg_mes;
    int random = bounded_rand(s);
    for (int i = 0; i < year - alice.car.relese_of_car; i++) {
        if (random == 1) {
            alice.capital = -alice.car.value / 20;
        }
    }
    //снижене стоимости за счет старения
    if (month == 3) {
        alice.car.value -= alice.car.value * 0, 02;
    }
    //дтп миимимими
    int random = bounded_rand(200);
    if (random == 67) {
        alice.capital = -alice.car.value / 10;
    }
    //дтп капитал
    int random = bounded_rand(1000);
    if (random == 52) {
        alice.capital = -alice.car.value / 10;
    }
    //взятки 
    alice.capital -= 5000;
    int random = bounded_rand(5000);
    if (random == 4444) {
        alice.capital -= 100.000;//приняли за взятки
    }
    //штрафы
    int count_fine = probeg_mes / 100;
    int fine = count_fine * 500;
    alice.capital -= fine;

}


void alice_bank_interest()
{
    float pp;
    pp = sberbank_interest(alice.capital);
    alice.capital += alice.capital * (pp / 12.0 / 100.0);
}


void alice_simulation()
{
    int year = 2026;
    int month = 2;

    while (not (year == 2027 and month == 2)) {
        // my_cat();
        // my_trip();
        alice_food();
        alice_car(month, year);
        alice_bank_interest();
        alice_salary(year, month);

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    srand(time({}));

    alice_init();

    alice_simulation();

    print_results();
}