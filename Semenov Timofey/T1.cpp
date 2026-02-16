#include <stdio.h>

using RUB = long long;

struct Car {
    RUB value;
    RUB gas;
};

struct Cat {
    RUB cost;
};

struct Bank {
    RUB account;
    RUB deposit;
};

struct Person {
    RUB salary;
    RUB food;
    Car mycar;
    Cat mycat;
    Bank mybank;
};

void person_init(Person& p) {
    p.salary = 100000;
    p.food = 30000;

    p.mycar.value = 2000000;
    p.mycar.gas = 2500;

    p.mycat.cost = 5000;

    p.mybank.account = 0;
    p.mybank.deposit = 0;
}

void receive_salary(Person& p, int month, int year) {
    if (month == 12 && year == 2026) {
        p.salary = p.salary * 3 / 2;
    }
    p.mybank.account += p.salary;
}

void pay_food(Person& p) {
    p.mybank.account -= p.food;
}

void pay_car(Person& p) {
    p.mybank.account -= p.mycar.gas;
}

void pay_cat(Person& p) {
    p.mybank.account -= p.mycat.cost;
}

void transfer_to_deposit(Person& p, RUB amount) {
    p.mybank.account -= amount;
    p.mybank.deposit += amount;
}

void deposit_interest(Person& p, double pp) {
    p.mybank.deposit += (RUB)(p.mybank.deposit * (pp / 12.0 / 100.0));
}

void apply_inflation(Person& p, double inflation_pp) {
    double k = 1.0 + inflation_pp / 12.0 / 100.0;

    p.food = (RUB)(p.food * k);

    p.mycar.gas = (RUB)(p.mycar.gas * k);
    p.mycar.value = (RUB)(p.mycar.value * k);

    p.mycat.cost = (RUB)(p.mycat.cost * k);

}

void print_results(const Person& p) {
    printf("salary=%lld\n", p.salary);
    printf("account=%lld\n", p.mybank.account);
    printf("deposit=%lld\n", p.mybank.deposit);
    printf("food=%lld, gas=%lld, cat=%lld\n", p.food, p.mycar.gas, p.mycat.cost);
    printf("car value=%lld\n", p.mycar.value);
}


void simulation(Person& p) {
    int month = 10;
    int year = 2026;

    while (!(month == 11 && year == 2027)) {
        apply_inflation(p, 16.0);
        deposit_interest(p, 14.5);
        pay_food(p);
        pay_car(p);
        pay_cat(p);
        transfer_to_deposit(p, 50000);
        receive_salary(p, month, year);

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}

int main() {
    Person Buba;
    person_init(Buba);
    simulation(Buba);
    print_results(Buba);

}
