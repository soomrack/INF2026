#include <iostream>
using namespace std;

using RUB = long long int;  // C++
using PRCNT = double;

struct Bank {
	RUB balance;
	RUB deposit;
	RUB procent;
};


struct Inflation {
    PRCNT salary;
    PRCNT food;
    PRCNT gas;
    PRCNT medicines;
    PRCNT entertainment;
    PRCNT car;
    PRCNT flat;
};
Inflation inflation;


struct Taxes {
    PRCNT income_tax;
    PRCNT property_tax;
};
Taxes taxes;


struct Car {
    RUB value;
    RUB gas;
};


struct Flat {
    RUB value;
    RUB mortgage;
    RUB utilities;
};


struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    RUB medicines;
    RUB entertainment;
    Car car;
    Flat flat;
	Bank bank;
};
Person Alice;


void alice_salary() {
    if (rand() % 1000 == 777) {
        Alice.salary *= 1.5;
    }

    Alice.bank.balance += Alice.salary;    
}


void print_results() {
    printf("Salary = %lld\n", Alice.salary);
    printf("Capital = %lld", Alice.capital);

}


void random_expenses() {
    srand(time(0));
    RUB RandomExpenses = rand() % 100'000;
    Alice.bank.balance -= RandomExpenses;
};


void alice_deposit() {
    Alice.bank.deposit += Alice.bank.deposit * (Alice.bank.procent / 12.0 / 100.0);
}


void alice_food() {
    Alice.bank.balance -= Alice.food;
}


void alice_medicines() {
    Alice.bank.balance -= Alice.medicines;
}


void alice_entertainment() {
    Alice.bank.balance -= Alice.entertainment;
}


void alice_car() {
    Alice.bank.balance -= Alice.car.gas;
}

void alice_flat() {
    Alice.bank.balance -= Alice.flat.mortgage + Alice.flat.utilities;
}

void alice_capital() {
	Alice.capital = Alice.bank.balance + Alice.bank.deposit + Alice.car.value + Alice.flat.value;
}


void pay_taxes() {
    RUB salarytax = Alice.salary * 12 * taxes.income_tax / 100;
    RUB cartax = Alice.car.value * taxes.property_tax / 100;
    RUB flattax = Alice.flat.value * taxes.property_tax / 100;
    Alice.bank.balance -= salarytax + cartax + flattax;
}


void apply_inflation(const int year) {
    Alice.food *= (1 + inflation.food / 100);
    Alice.medicines *= (1 + inflation.medicines / 100);
    Alice.entertainment *= (1 + inflation.entertainment / 100);
    Alice.car.gas *= (1 + inflation.gas / 100);
    Alice.car.value *= (1 + inflation.car / 100);
    Alice.flat.value *= (1 + inflation.flat / 100);
    Alice.flat.mortgage *= (1 + inflation.flat / 100);
    
    if (year % 2 == 0) {
        Alice.salary *= (1 + inflation.salary / 100);
    }
}


void init_inflation() {
    inflation.salary = 10;
    inflation.food = 8;
    inflation.gas = 8;
    inflation.medicines = 7;
    inflation.entertainment = 7;
    inflation.car = 8;
    inflation.flat = 8;
}


void init_taxes() {
    taxes.income_tax = 13;
    taxes.property_tax = 0.1;
}


void init_alice() {
    Alice.salary = 120'000;
    Alice.food = 20'000;
    Alice.medicines = 10'000;
    Alice.entertainment = 15'000;
    
    Alice.bank.balance = 0;
	Alice.bank.deposit = 100'000;
	Alice.bank.procent = 16;

    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;

    Alice.flat.value = 12'000'000;
    Alice.flat.mortgage = 50'000;
    Alice.flat.utilities = 10'000;
}


void simulation() {
    int month = 1;
    int year = 2026;
    
    while ( !((month == 1) && (year == 2031)) ) {
        alice_salary();
        alice_deposit();
        alice_food();
        alice_car();
        alice_flat();
        random_expenses();
		alice_capital();
        
        ++month;
        if (month == 13) {
            pay_taxes();
            month = 1;
            ++year;
            apply_inflation(year);
        }
    }
}


int main()
{
    init_inflation();

    init_taxes();

    init_alice();
    
    simulation();
    
    print_results();
}
