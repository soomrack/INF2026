#include <stdio.h>

using RUB = long long int;


struct Car {
    RUB value;
    RUB gas;
};

struct Hamster {
    RUB food;
};

struct Bank {
    RUB account;   // расчётный счёт
    RUB deposit;   // вклад
};

struct Person {
    RUB salary;
    Bank bank;
    RUB food;
    Car car;
    Hamster hamster;
};


struct Person Alice;

float bank_pp = 14.5;      // % по вкладу (годовых)
float inflation = 7.0;     // инфляция % годовых


void alice_salary(int month, int year) {
    if (month == 8 && year == 2026) {
        Alice.salary = Alice.salary * 1.5; // повышение
    }
    Alice.bank.account += Alice.salary;
}

void alice_food() {
    Alice.bank.account -= Alice.food;
}

void alice_car() {
    Alice.bank.account -= Alice.car.gas;
}

void alice_hamster() {
    Alice.bank.account -= Alice.hamster.food;
}

void alice_transfer_to_deposit(RUB amount) {
    if (Alice.bank.account >= amount) {
        Alice.bank.account -= amount;
        Alice.bank.deposit += amount;
    }
}

void bank_interest() {
    Alice.bank.deposit += Alice.bank.deposit * (bank_pp / 12.0 / 100.0);
}

void inflation_update() {
    float m = inflation / 12.0 / 100.0;

    Alice.food += Alice.food * m;
    Alice.car.gas += Alice.car.gas * m;
    Alice.car.value += Alice.car.value * m;
    Alice.hamster.food += Alice.hamster.food * m;
}

void simulation() {
    int month = 2;
    int year = 2026;

    while (!(month == 3 && year == 2127)) {

        // зарплата
        alice_salary(month, year);

        // часть денег — на вклад
        alice_transfer_to_deposit(Alice.salary / 3);

        // расходы
        alice_food();
        alice_car();
        alice_hamster();

        // проценты
        bank_interest();

        // инфляция
        inflation_update();

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}

void alice_init() {
    Alice.salary = 180000;

    Alice.bank.account = 0;
    Alice.bank.deposit = 0;

    Alice.food = 20000;

    Alice.car.value = 2400000;
    Alice.car.gas = 15000;

    Alice.hamster.food = 3000;
}

void print_results() {
    printf("Salary = %lld\n", Alice.salary);
    printf("Bank account = %lld\n", Alice.bank.account);
    printf("Deposit = %lld\n", Alice.bank.deposit);
    printf("Car value = %lld\n", Alice.car.value);
}

int main() {
    alice_init();
    simulation();
    print_results();
}




