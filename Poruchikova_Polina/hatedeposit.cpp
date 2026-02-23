#include <stdio.h>
#include <ctime>
#include <cstdlib>


using RUB = long long int;


struct Car {
    RUB value;
    RUB gas;
};

struct Cat {
    RUB petfood;
    RUB vet;
    RUB filler;
};

struct Bank {
    RUB deposit;
    RUB account;
    
};

struct Random {
    RUB min;
    RUB max;
    RUB prize;
};

struct Gamble {
    RUB loss;
    RUB win;
    RUB casino;
};

struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    struct Bank Otkritie;
    struct Car kamaz; //создает переменную с данными которые в стракт машина (цена, бензин)
    struct Cat Barsik;
    struct Random lottery;
    struct Gamble addiction;
};


struct Person Alice; //создает переменную с данными которые в стракт персон (зп, еда и тд)

float pp = 14.5;


void alice_innit(){ //изначальные данные
    Alice.capital = 0;
    Alice.salary = 100'000;
    Alice.food = 20'000;
    Alice.kamaz.value = 2'400'000;
    Alice.kamaz.gas = 15'000;
    Alice.Barsik.vet = 5'000;
    Alice.Barsik.filler = 1'500;
    Alice.Barsik.petfood = 750;
    srand(time(NULL));
}

void alice_casino() {
    int loss = -1'000'000;
    int win = 1'000'000;
    int stepcas = 10'000;
    int casino = loss + (rand() % ((win - loss) / stepcas + 1)) * stepcas;
    Alice.capital += casino;
    Alice.addiction.casino = casino;
};

void alice_lottery(){
    int min = 0;
    int max = 100000;
    int step = 100;
    int prize = min + (rand() % ((max - min) / step + 1)) * step;
    Alice.capital += prize;
    Alice.lottery.prize = prize;
}

void alice_salary(const int month,const int year){
    if ( (month == 8) && (year == 2026)) { 
        Alice.salary *= 1.5; //повышение зп
    }
    Alice.capital += Alice.salary;
}

void alice_pet(){
    Alice.capital -= Alice.Barsik.filler;
    Alice.capital -= Alice.Barsik.petfood;
    Alice.capital -= Alice.Barsik.vet;
}


void alice_food(){
    Alice.capital -= Alice.food;
}

void alice_car_gas(){
    Alice.capital -= Alice.kamaz.gas; 
}

void alice_kamaz(){
    Alice.capital -= Alice.kamaz.value;
}

void alice_deposit()
{
    Alice.Otkritie.deposit += Alice.Otkritie.deposit * (pp / 12.0 / 100.0);
    Alice.Otkritie.deposit += Alice.Otkritie.account;
    Alice.Otkritie.account = 0;
}

void inflation(){
    Alice.food *= 1.06;
    Alice.Barsik.filler *= 1.06;
    Alice.Barsik.petfood *= 1.06;
    Alice.Barsik.vet *= 1.06;
    Alice.kamaz.gas*= 1.06;
}

void simulation(){ 
    int month = 2;
    int year = 2026;
    alice_kamaz();

    while ( !((month == 3) && (year == 2127)) ) { 
        alice_salary(month, year);
        alice_pet();
        alice_food();
        alice_car_gas();
        alice_lottery();
        alice_casino();
        alice_deposit();
        inflation();

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}

void print_results(){ //печает результаты но запускается через мейн
    printf("salary = %lld\n", Alice.salary);
    printf("capital = %lld\n", Alice.capital);
    printf("account = %lld\n", Alice.Otkritie.account);
    printf("deposit = %lld\n", Alice.Otkritie.deposit);
    printf("prize = %lld\n", Alice.lottery.prize);
    printf("casino = %lld\n", Alice.addiction.casino);
}


int main(){ //выполняет все
    alice_innit();

    simulation();

    print_results();
}


