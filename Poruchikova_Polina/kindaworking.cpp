#include <stdio.h>
#include <ctime>
#include <cstdlib>


using RUB = long long int;

struct Plane {
    RUB value;
    RUB pilot;
    RUB fuel;
};

struct Yacht {
    RUB value;
    RUB captain;
    RUB fuel;
};

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
    float pp = 14.5;
};

struct Random {
    RUB min;
    RUB max;
    RUB prize;
};

struct Travel {
    RUB transport;
    RUB souvenir;
    RUB hotel;
    RUB excursion;
    RUB expensive;
    RUB cheap;
    RUB tripsum;
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
    RUB meds;
    RUB beauty;
    RUB gym;
    struct Travel trip;
    struct Bank Otkritie;
    struct Car kamaz;
    struct Car Smart_Fortwo; 
    struct Cat Barsik;
    struct Random lottery;
    struct Gamble addiction;
    float inflation;
};

struct Family {
    RUB capital;
    RUB cruise;
    struct Cat Musya;
    struct Cat Kittens;
    struct Plane Airbus;
    struct Yacht Beda;
    struct Travel Around_the_world;
};



struct Person Alice; 

struct Person Bob;

struct Family Together;



void bob_init(){ 
    Bob.capital = 0;

    Bob.salary = 100'000;

    Bob.meds = 10'000;
    Bob.gym = 15'000;
    Bob.food = 30'000;

    Bob.Smart_Fortwo.value = 500'000;
    Bob.Smart_Fortwo.gas = 10'000;

    Bob.inflation = 1.07;
}

void bob_salary(const int month,const int year){
    if ( (month == 5) && (year == 2036)) { 
        Bob.salary *= 2.5; 
    }
    Bob.capital += Bob.salary;
}

void bob_food(){
    Bob.capital -= Bob.food;
}

void bob_meds(){
    Bob.capital -= Bob.meds;
}

void bob_gym(){
        Bob.capital -= Bob.gym;
}

void bob_car_gas(){
    Bob.capital -= Bob.Smart_Fortwo.gas;
}

void bob_car(){
        Bob.capital -= Bob.Smart_Fortwo.value;
}



void alice_init(){ 
    Alice.capital = 0;

    Alice.salary = 200'000;
    
    Alice.meds = 10'000;
    Alice.beauty = 30'000;
    Alice.food = 20'000;

    Alice.kamaz.value = 7'000'000;
    Alice.kamaz.gas = 15'000;

    Alice.Barsik.vet = 5'000;
    Alice.Barsik.filler = 1'500;
    Alice.Barsik.petfood = 750;
    
    Alice.Otkritie.account = 0;
    Alice.Otkritie.deposit = 0;

    Alice.inflation = 1.06;
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

void alice_trip() {
    int cheap = 5000;
    int expensive = 500'000;
    int tripstep = 1000;

    int transport = cheap + (rand() % ((expensive / 5 - cheap) / tripstep + 1)) * tripstep * 10;
    int hotel = cheap + (rand() % ((expensive - cheap) / tripstep + 1)) * tripstep * 50;
    int souvenir = cheap + (rand() % ((expensive / 50 - cheap) / tripstep + 1)) * tripstep / 10;
    int excursion = cheap + (rand() % ((expensive / 10 - cheap) / tripstep + 1)) * tripstep;

    int trip_cost = transport + hotel + souvenir + excursion;

    Alice.capital -= transport + hotel + souvenir + excursion;
    Alice.trip.tripsum = transport + hotel + souvenir + excursion;
}

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
        Alice.salary *= 1.5; 
    }
    Alice.capital += Alice.salary;
    Alice.Otkritie.account += Alice.salary;
}

void alice_pet(){
    int cat_cost = Alice.Barsik.filler + Alice.Barsik.petfood + Alice.Barsik.vet;
    Alice.capital -= cat_cost;
}

void alice_food(){
        Alice.capital -= Alice.food;
}

void alice_meds(){
    Alice.capital -= Alice.meds;
}

void alice_beauty(){
        Alice.capital -= Alice.beauty;
}

void alice_car_gas(){
        Alice.capital -= Alice.kamaz.gas;
}

void alice_kamaz(){
    Alice.capital -= Alice.kamaz.value;
}

void alice_deposit(){
    Alice.Otkritie.deposit += Alice.Otkritie.deposit * (Alice.Otkritie.pp / 12.0 / 100.0);

    Alice.Otkritie.deposit += Alice.Otkritie.account;
    Alice.Otkritie.account = 0;
}



void together_init(){
    Together.capital = 0;

    Together.cruise = 300'000;

    Together.Musya.vet = 10'000;
    Together.Musya.filler = 1'500;
    Together.Musya.petfood = 850;

    Together.Kittens.filler = 1'500 * 3;
    Together.Kittens.vet = 5'000 * 3;
    Together.Kittens.petfood = 1'000 * 3;

    Together.Airbus.fuel = 50'000;
    Together.Airbus.pilot = 30'000;
    Together.Airbus.value = 35'269'240'000;

    Together.Beda.captain = 10'000;
    Together.Beda.fuel = 15'000;
    Together.Beda.value =209'813'000;
}

void family_budget(){
    Together.capital += Alice.capital + Bob.capital;
    Alice.capital = 0;
    Bob.capital = 0;
}

void family_food(){
    Together.capital -= (Alice.food + Bob.food) / 2;
}

void family_cats(){
    int Barsik_cost = Alice.Barsik.vet + Alice.Barsik.petfood + Alice.Barsik.filler;

    int Musya_cost = Together.Musya.vet + Together.Musya.petfood + Together.Musya.filler;

    int Kittens_cost = Together.Kittens.vet + Together.Kittens.petfood + Together.Kittens.filler;
    
    int all_cats = Barsik_cost + Musya_cost + Kittens_cost;

    Together.capital -= all_cats;
}

void family_cruise(){
    Together.capital -= Together.cruise;
}

void family_trip(){
    int cheap = 5000;
    int expensive = 500'000;
    int tripstep = 1000;

    int transport = Together.Airbus.fuel + Together.Airbus.pilot;
    int hotel = 2 * (cheap + (rand() % ((expensive - cheap) / tripstep + 1)) * tripstep * 50);
    int souvenir = 2 * (cheap + (rand() % ((expensive / 50 - cheap) / tripstep + 1)) * tripstep / 10);
    int excursion = 2 * (cheap + (rand() % ((expensive / 10 - cheap) / tripstep + 1)) * tripstep);

    int trip_cost = transport + hotel + souvenir + excursion;

    Together.capital -= trip_cost;
}

void family_funs(){
    
    Together.capital += Alice.lottery.prize;

    Together.capital -= Alice.beauty;
    Together.capital -= Bob.gym;
    Together.capital -= Together.Beda.captain;
    Together.capital -= Together.Beda.fuel;
};

void family_meds(){
        Together.capital -= Alice.meds;
        Together.capital -= Bob.meds;
}

void family_gas(){
    Together.capital -= Alice.kamaz.gas;
    Together.capital -= Bob.Smart_Fortwo.gas;
    Together.capital -= Together.Airbus.fuel;
    Together.capital -= Together.Beda.fuel;
}

void family_plane(){
       Together.capital -= Together.Airbus.value;
}

void family_yacht(){
        Together.capital -= Together.Beda.value;
}

void inflation (){
    Alice.meds *= Alice.inflation;
    Alice.food *= Alice.inflation;
    Alice.beauty *= Alice.inflation;
    Alice.kamaz.gas *= Alice.inflation;
    Alice.kamaz.value *= Alice.inflation;
    Alice.Barsik.filler *= Alice.inflation;
    Alice.Barsik.petfood *= Alice.inflation;
    Alice.Barsik.vet *= Alice.inflation;
    
    Bob.food = Bob.inflation;
    Bob.gym = Bob.inflation;
    Bob.meds = Bob.inflation;
    Bob.Smart_Fortwo.gas = Bob.inflation;
    Bob.Smart_Fortwo.value = Bob.inflation;
}

void simulation(){ 
    int month = 2;
    int year = 2026;
    bool family_mode = false;

    while ( !((month == 3) && (year == 2057)) ) { 
        if (!family_mode) {
            alice_salary(month, year);
            alice_pet();
            alice_beauty();
            alice_meds();
            alice_car_gas();
            alice_food();
            alice_lottery();
            alice_casino();
            alice_deposit();

            bob_salary(month, year);
            bob_car_gas();
            bob_food();
            bob_gym();
            bob_car();
            bob_meds();


            if (year % 10 == 0 && month == 11){
                alice_kamaz();
            }


            if (year % 5 == 0 && month == 1) {
                bob_car();
            }


            if ((year % 2 == 0) && month == 7) {
                alice_trip();
            }


            if (month == 1) {
                inflation();
            }
        }


        if (year == 2057 && month == 3 && !family_mode) {
            family_mode = true;
            family_budget();
        }

        if (family_mode && year <= 2067) {
            family_cats();
            family_food();
            family_funs();
            family_gas();
            family_meds();

            if (year % 5 == 0 && month == 6 && year > 2057) { 
                family_cruise();
            }

            if (year % 3 == 0 && month == 8 && year > 2057) { 
                family_trip();
            }

            if (year % 100 == 0 && month == 1 && year > 2057) {
                family_plane();
                family_yacht();
            }
        }

        ++month;
        if (month == 13) {
            month = 1;
            ++year;

        }
    }
}

void print_results(){ 
    printf("salary = %lld\n", Alice.salary);
    printf("capital = %lld\n", Alice.capital);
    printf("account = %lld\n", Alice.Otkritie.account);
    printf("deposit = %lld\n", Alice.Otkritie.deposit);
    printf("prize = %lld\n", Alice.lottery.prize);
    printf("casino = %lld\n", Alice.addiction.casino);
    printf("travel = %lld\n", Alice.trip.tripsum);
    printf("medicine = %lld\n", Alice.meds);

    printf("зарплата Boba = %lld\n", Bob.salary);
    printf("capital Boba = %lld\n", Bob.capital);
    
    printf("capital Family = %lld\n", Together.capital);
    printf("trip Family = %lld\n", Together.Around_the_world.tripsum);
}


int main(){ 
    alice_init();

    bob_init();

    together_init();

    simulation();

    print_results();
}

