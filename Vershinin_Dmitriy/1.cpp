#include <iostream>

using RUB = long long int;  // C++

struct Bank {
	RUB balance;
	RUB deposit;
	RUB procent;
};


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
    struct Car AliceCar;
    struct Flat AliceFlat;
	struct Bank AliceBank;
};
struct Person Alice;


void alice_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) {
        Alice.salary *= 1.5;
    }

    Alice.AliceBank.balance += Alice.salary;    
}


void print_results() {
    printf("Salary = %lld\n", Alice.salary);
    printf("Capital = %lld", Alice.capital);

}


void random_expenses(){
    srand(time(0));
    RUB RandomExpenses = rand() % 100'000;
    Alice.AliceBank.balance -= RandomExpenses;
};


void alice_deposit() {
    Alice.AliceBank.deposit += Alice.AliceBank.deposit * (Alice.AliceBank.procent / 12.0 / 100.0);
}


void alice_food() {
    Alice.AliceBank.balance -= Alice.food;
}


void alice_medicines() {
    Alice.AliceBank.balance -= Alice.medicines;
}


void alice_entertainment() {
    Alice.AliceBank.balance -= Alice.entertainment;
}


void alice_car() {
    Alice.AliceBank.balance -= Alice.AliceCar.gas;
}

void alice_flat(){
    Alice.AliceBank.balance -= Alice.AliceFlat.mortgage + Alice.AliceFlat.utilities;
}

void alice_capital() {
	Alice.capital = Alice.AliceBank.balance + Alice.AliceBank.deposit + Alice.AliceCar.value + Alice.AliceFlat.value;
}


void alice_init() {
    Alice.salary = 180'000;
    Alice.food = 20'000;
    Alice.medicines = 10'000;
    Alice.entertainment = 15'000;
    
    Alice.AliceBank.balance = 0;
	Alice.AliceBank.deposit = 100'000;
	Alice.AliceBank.procent = 16;

    Alice.AliceCar.value = 2'400'000;
    Alice.AliceCar.gas = 15'000;

    Alice.AliceFlat.value = 12'000'000;
    Alice.AliceFlat.mortgage = 50'000;
    Alice.AliceFlat.utilities = 10'000;
}


void simulation() {
    int month = 2;
    int year = 2026;
    
    while ( !((month == 3) && (year == 2027)) ) {
        alice_salary(month, year);
        alice_deposit();
        alice_food();
        alice_car();
        alice_flat();
        random_expenses();
		alice_capital();
        
        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}


int main()
{
    alice_init();
    
    simulation();
    
    print_results();
}
