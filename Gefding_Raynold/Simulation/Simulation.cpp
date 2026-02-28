#include <stdio.h>


using RUB = long long int;
using USD = long long int;

using Percent = float;


struct Bank {
    RUB account; // сумма на счету
    RUB deposite; // сумма на депозите
    Percent interest; // процент по депозиту

    USD account_usd; // сумма на долларовом счету
    float rate_usd_rub; // курс доллара к рублю
};


struct Car {
    RUB gas; // стоимость топлива
    RUB value; // стоимость машины
};


struct RentApartment {
    RUB rent; // стоимость аренды
    RUB housingservices; // стоимость жилищно-коммунальных услуг
};


struct OwnApartment {
    RUB flat; // стоимость квартиры 
    Percent mortgage; // процент по ипотеке
    RUB mortgageterm; // срок ипотеки в месяцах
    RUB housingservices; // стоимость жилищно-коммунальных услуг
};


struct Pet {
    RUB food; // стоимость топлива
    RUB health; // стоимость машины
    RUB toilet; // стоимость наполнителя
    RUB toys; // стоимость развлечений
};


struct Person {
    // Банки и накопления
    Bank vtb;

    // Недвижимость
    RentApartment rentflat;
    OwnApartment ownflat;

    // Транспорт
    Car car;
    RUB socialtransport;

    // Доходы
    RUB salary;

    // Расходы
    RUB food;
    RUB net;
    RUB healthinsurance;

    // Питомец
    Pet pet;

};

struct Person alice;

struct Person bob;

// Блок инициализации доходов и расходов alice - начало

void alice_init()
{
    alice.vtb.account = 0;
    alice.vtb.deposite = 1'000'000;
    alice.vtb.interest = 14.5;
    alice.salary = 180'000;

    alice.vtb.account_usd = 1'000;
    alice.vtb.rate_usd_rub = 78.5;

    alice.rentflat.rent = 30'000;
    alice.rentflat.housingservices = 10'000;

    alice.food = 20'000;
    alice.net = 1'000;
    alice.healthinsurance = 20'000;

    alice.car.value = 2'400'000;
    alice.car.gas = 15'000;

    alice.pet.food = 5'000;
    alice.pet.health= 5'000;
    alice.pet.toilet = 5'000;
    alice.pet.toys = 5'000;
}


void alice_salary(const int month, const int year)
{
    if (month == 12) {
        alice.vtb.account += alice.salary;  // 13th salary
    }

    if (month == 1 and year == 2027) {
        alice.salary *= 1.5;  // promotion
    }

    alice.vtb.account += alice.salary;
}


void alice_expences()
{
    alice.vtb.account -= alice.food;
    alice.vtb.account -= alice.net;
}

void alice_insurance()
{
    alice.vtb.account -= alice.healthinsurance;
}


void alice_pet()
{
    alice.vtb.account -= alice.pet.food;
    alice.vtb.account -= alice.pet.health;
    alice.vtb.account -= alice.pet.toilet;
    alice.vtb.account -= alice.pet.toys;
}


void alice_home()
{
    alice.vtb.account -= alice.rentflat.rent;
    alice.vtb.account -= alice.rentflat.housingservices;
}


void alice_car()
{
    alice.vtb.account -= alice.car.gas;
}


void alice_deposite(const int month, const int year)
{
    if (year == 2026) alice.vtb.interest = 14.5;
    if (year == 2027) alice.vtb.interest = 13.5;
    if (year == 2028) alice.vtb.interest = 12.5;
    if (year == 2029) alice.vtb.interest = 11.5;

    alice.vtb.deposite += alice.vtb.deposite * (alice.vtb.interest / 12.0 / 100.0);

    alice.vtb.deposite += alice.vtb.account;
    alice.vtb.account = 0;
}


void alice_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        alice.vtb.account_usd += 3'000;
    }
}

// Блок инициализации доходов и расходов alice - конец



// Блок инициализации доходов и расходов bob - начало

void bob_init()
{
    bob.vtb.account = 0;
    bob.vtb.deposite = 100'000;
    bob.vtb.interest = 14.5;
    bob.salary = 180'000;

    bob.vtb.account_usd = 1'000;
    bob.vtb.rate_usd_rub = 78.5;

    bob.rentflat.rent = 30'000;
    bob.rentflat.housingservices = 10'000;

    bob.food = 20'000;
    bob.net = 1'000;
    bob.healthinsurance = 20'000;

    bob.car.value = 2'400'000;
    bob.car.gas = 15'000;

    bob.pet.food = 5'000;
    bob.pet.health = 5'000;
    bob.pet.toilet = 5'000;
    bob.pet.toys = 5'000;
}


void bob_salary(const int month, const int year)
{
    if (month == 12) {
        bob.vtb.account += bob.salary;  // 13th salary
    }

    if (month == 1 and year == 2027) {
        bob.salary *= 1.5;  // promotion
    }

    bob.vtb.account += bob.salary;
}


void bob_expences()
{
    bob.vtb.account -= bob.food;
    bob.vtb.account -= bob.net;
}

void bob_insurance()
{
    bob.vtb.account -= bob.healthinsurance;
}


void bob_pet()
{
    bob.vtb.account -= bob.pet.food;
    bob.vtb.account -= bob.pet.health;
    bob.vtb.account -= bob.pet.toilet;
    bob.vtb.account -= bob.pet.toys;
}


void bob_home()
{
    bob.vtb.account -= bob.rentflat.rent;
    bob.vtb.account -= bob.rentflat.housingservices;
}


void bob_car()
{
    bob.vtb.account -= bob.car.gas;
}


void bob_deposite(const int month, const int year)
{
    if (year == 2026) bob.vtb.interest = 14.5;
    if (year == 2027) bob.vtb.interest = 13.5;
    if (year == 2028) bob.vtb.interest = 12.5;
    if (year == 2029) bob.vtb.interest = 11.5;

    bob.vtb.deposite += bob.vtb.deposite * (bob.vtb.interest / 12.0 / 100.0);

    bob.vtb.deposite += bob.vtb.account;
    bob.vtb.account = 0;
}


void bob_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        bob.vtb.account_usd += 3'000;
    }
}

// Блок инициализации доходов и расходов bob - конец


// Блок вывода - начало

void print_results()
{
    printf("Salary = %lld\n", alice.salary);

    RUB capital = 0;
    capital += alice.vtb.account;
    capital += alice.car.value;
    capital += alice.vtb.deposite;
    capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
    printf("Capital = %lld", capital);

    printf("\nSalary = %lld\n", bob.salary);

    capital = 0;
    capital += bob.vtb.account;
    capital += bob.car.value;
    capital += bob.vtb.deposite;
    capital += bob.vtb.account_usd * bob.vtb.rate_usd_rub;
    printf("Capital = %lld", capital);
}

// Блок вывода - конец


void simulation()
{
    int month = 2;
    int year = 2026;

    while (not (month == 3 and year == 2050)) {

        // Блок alice - начало
        alice_salary(month, year); // Начисление зарплаты
        alice_freelance(month, year); // Начисление фрилансов
        alice_expences(); // Мелкие расходы
        alice_car(); // Расходы на машину
        alice_pet(); // Расходы на питомца
        alice_insurance(); // Расходы на страховку
        alice_home(); // Расходы на дом
        alice_deposite(month, year); // Откладывание на депозит
        // Блок alice - конец


        // Блок bob - начало
        bob_salary(month, year); // Начисление зарплаты
        bob_freelance(month, year); // Начисление фрилансов
        bob_expences(); // Мелкие расходы
        bob_car(); // Расходы на машину
        bob_pet(); // Расходы на питомца
        bob_insurance(); // Расходы на страховку
        bob_home(); // Расходы на дом
        bob_deposite(month, year); // Откладывание на депозит
        // Блок bob - конец


        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    alice_init();
    bob_init();

    simulation();

    print_results();
}