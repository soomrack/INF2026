#include <stdio.h>

using RUB = long long int;

struct Car {
    RUB value;  
    RUB gas;   
};


struct Bank {
    RUB money;   
    RUB deposit;
    float pp = 14.5;    
};


struct Person {
    RUB salary;
    RUB capital;          
    RUB food;             
    struct Car car;
    struct Bank VTB;
    RUB hobby;
    RUB cat_food;         
    int has_car;    // Наличие машины (0 или 1)     
};
struct Person Alice;

                         
const float pr_inflation = 0.015;     


void alice_salary(const int month, const int year) {
    if ((month == 8) && (year >= 2026)) {  
        Alice.salary *= 1.5;
    }
    Alice.VTB.money += Alice.salary;    
}


void print_results() {
    printf("Зарплата = %lld\n", Alice.salary);
    printf("Деньги на банковском счету = %lld\n", Alice.VTB.money);
    printf("Депозит = %lld\n", Alice.VTB.deposit);
}


void alice_hobby() {
    Alice.VTB.money -= Alice.hobby;
    Alice.hobby += RUB (Alice.hobby * pr_inflation);
}


void alice_bank_interest() {
    if (Alice.VTB.money >= 0) {
        Alice.VTB.deposit += Alice.VTB.money;
        Alice.VTB.money -= Alice.VTB.money;
    }
    Alice.VTB.deposit += RUB (Alice.VTB.deposit * (Alice.VTB.pp / 12 / 100));
}


void alice_food() {
    Alice.VTB.money -= Alice.food;
    Alice.food += RUB (Alice.food * pr_inflation);
}


void alice_cat() {
    Alice.VTB.money -= Alice.cat_food;
    Alice.cat_food += RUB (Alice.cat_food * pr_inflation);
}


void alice_car() {
    Alice.VTB.money -= Alice.car.gas;
}


void alice_init() {
    Alice.salary = 180'000;
    Alice.food = 20'000;
    Alice.car.value = 2'000'000;
    Alice.car.gas = 15'000;
    Alice.cat_food = 5'000;
    Alice.hobby = 20000;

    Alice.VTB.money = 0;
    Alice.VTB.deposit = 0;
    Alice.has_car = 0;   
}


void simulation() {
    int month = 2;
    int year = 2026;
    
    while ( !((month == 3) && (year == 2028))) {         
             
        alice_salary(month, year);
        alice_food();
        alice_car();
        alice_cat();                
        alice_bank_interest();  
    

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}

int main() {
    alice_init();
    simulation();
    print_results();
    return 0;
}