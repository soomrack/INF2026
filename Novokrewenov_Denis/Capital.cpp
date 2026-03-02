#include <stdio.h>
#include <string>

using RUB = long int;

struct Car {
    RUB value;
    RUB gas;
};

struct Cat {
    RUB feed;
};

struct Apartment {
    RUB value;
    RUB payment;
};

struct RentApartment {
    RUB rent;
};

struct Bank {
    RUB account;
    float deposit_interest;
};

struct Person {
    std::string name;
    RUB salary;
    RUB capital;
    RUB food;
    Car car;
    bool is_having_car;
    Cat pet;

    bool is_having_apartment;
    Apartment my_apartment;
    bool is_renting_apartment;
    RentApartment rent_apartment;

    Bank VTB;
    RUB poket_money_target;

    RUB feb23th_cost;
    RUB mar8th_cost;
    RUB newyear_cost;
    RUB dad_birthday_cost;
    RUB mom_birthday_cost;
    RUB sister_birthday_cost;
    RUB best_friend_birthday_cost;
    RUB partner_birthday_cost;

    int dad_birthday_month;
    int mom_birthday_month;
    int sister_birthday_month;
    int best_friend_birthday_month;
    int partner_birthday_month;
};



struct Person Alice;

const float pp = 14.5;
const float cash_interest_per_month = 1.0125; // 15%
const float apartment_interest_per_month = 1.0142; // 17%
const float salary_interest_per_month = 1.01; // 12%

void pet(Person& person) {
    person.pet.feed = person.pet.feed * cash_interest_per_month;
    person.VTB.account -= person.pet.feed;
}

void car(Person& person, int month, int year) {
    if (!person.is_having_car && person.VTB.account > person.car.value){
        person.VTB.account -= person.car.value;
        person.is_having_car = true;
        printf("%s bought a car in %d month of %d for %d RUB\n", person.name.c_str(), month, year, person.car.value);
    }
    person.car.value = person.car.value * cash_interest_per_month;

    person.car.gas = person.car.gas * cash_interest_per_month;
    if (person.is_having_car) person.VTB.account -= person.car.gas;
}

void salary(Person& person, const int month, const int year) {
    person.salary = person.salary * salary_interest_per_month;
    if ((month == 8) && (year == 2026)) { // Promotion
        person.salary = person.salary * 1.5;
    }
    person.capital += person.salary;

    person.VTB.account += person.capital - person.poket_money_target;
    person.capital = person.poket_money_target;
}

void food(Person& person) {
    person.food = person.food * cash_interest_per_month;
    person.VTB.account -= person.food;
}

void apartment(Person& person, int month, int year){
    if (person.is_having_apartment) {
        person.VTB.account -= person.my_apartment.payment;
    }
    else {
        if (person.VTB.account >= person.my_apartment.value){
            person.VTB.account -= person.my_apartment.value;
            person.is_having_apartment = true;
            person.is_renting_apartment = false;
            printf("%s bought an apartment in %d month of %d for %d RUB\n", person.name.c_str(), month, year, person.my_apartment.value);
        }
    }

    if (person.is_renting_apartment) {
        person.VTB.account -= person.rent_apartment.rent;
    }

    person.my_apartment.payment *= apartment_interest_per_month;
    person.my_apartment.value *= cash_interest_per_month;
    person.rent_apartment.rent *= apartment_interest_per_month;
}

void bank(Person& person) {
    person.VTB.account += person.VTB.account * (pp / 12.0 / 100.0);
}

void holidays(Person& person, const int month) {
    if (month == 2) person.VTB.account -= person.feb23th_cost;
    if (month == 3) person.VTB.account -= person.mar8th_cost;
    if (month == person.dad_birthday_month) person.VTB.account -= person.dad_birthday_cost;
    if (month == person.mom_birthday_month) person.VTB.account -= person.mom_birthday_cost;
    if (month == person.sister_birthday_month) person.VTB.account -= person.sister_birthday_cost;
    if (month == person.best_friend_birthday_month) person.VTB.account -= person.best_friend_birthday_cost;
    if (month == 12) person.VTB.account -= person.newyear_cost;
}

void alice_init() {
    Alice.name = "Alice";
    Alice.VTB.account = 100000;
    Alice.capital = 0;
    Alice.poket_money_target = 10000;
    Alice.salary = 180000;
    Alice.food = 20000;

    Alice.my_apartment.value = 800'000;
    Alice.my_apartment.payment = 30'000;
    Alice.is_having_apartment = false;
    Alice.rent_apartment.rent = 70'000;
    Alice.is_renting_apartment = true;

    Alice.is_having_car = false;
    Alice.car.value = 500000;
    Alice.car.gas = 15000;

    Alice.pet.feed = 2000;

    Alice.feb23th_cost = 2000;
    Alice.mar8th_cost = 3000;
    Alice.newyear_cost = 7000;
    Alice.dad_birthday_cost = 5000;
    Alice.mom_birthday_cost = 4000;
    Alice.sister_birthday_cost = 3000;
    Alice.best_friend_birthday_cost = 2500;
    Alice.partner_birthday_cost = 4500;

    Alice.dad_birthday_month = 4;
    Alice.mom_birthday_month = 7;
    Alice.sister_birthday_month = 9;
    Alice.best_friend_birthday_month = 5;
    Alice.partner_birthday_month = 2;
}

void print_results(Person& person) {
    printf("%s's account:\n", person.name.c_str());
    printf("  Bank account = %ld\n", person.VTB.account);
    printf("  Capital = %ld\n", person.capital);
    printf("  Salary = %ld\n", person.salary);
    printf("  Feed = %ld\n", person.pet.feed);
    printf("  Food = %ld\n", person.food);
    printf("  Car value = %ld\n", person.car.value);
    printf("  Car gas = %ld\n", person.car.gas);
}

void simulation(Person& person) {
    int month = 2;
    int year = 2026;


    while (!((month == 3) && (year == 2027))) {
        pet(Alice);
        food(Alice);
        car(Alice, month, year);
        apartment(Alice, month, year);
        holidays(Alice, month);
        bank(Alice);
        salary(Alice, month, year);

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}

int main() { 
    alice_init();

    simulation(Alice);
  
    print_results(Alice);
}
