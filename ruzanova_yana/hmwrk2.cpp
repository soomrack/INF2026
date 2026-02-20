#include <stdio.h>


using Percent = float;

using RUB = long long int;
using USD = long long int;


struct Car {
    RUB value;
    RUB gas;
};


struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
};


struct Flat { //оплата собственной квартиры 
    RUB housing_and_communal_servisec; //ЖКХ
    RUB current_repairs; //текущий ремонт
    RUB household_chemicals; //бытовая химия 
    RUB general_household_needs; //общедомовые нужды
    RUB checking_counters;//проверка счётчиков
    RUB repair_of_large_household_appliances; //ремонт крупногабаритной техники
};

struct Mortgage { //ипотечная квартира
    RUB loan_amount; //сумма импотеки
    RUB monthly_payment; //ежемесячный платеж
};


struct Person {
    Bank vtb;
    RUB salary;
    RUB food;
    Car car;
    Flat flat_1;
    Mortgage flat_2;
};


struct Person alice; //алиса несчастная


void alice_init()
{
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 1'000;

    alice.salary = 700'000;
    alice.food = 3'000;

    alice.car.value = 2'400'000;
    alice.car.gas = 15'000;

    alice.flat_1.housing_and_communal_servisec = 17'000;
    alice.flat_1.current_repairs = 3'000;
    alice.flat_1.household_chemicals = 2'000;
    alice.flat_1.checking_counters=700;
    alice.flat_1.general_household_needs = 3'797;
    alice.flat_1.repair_of_large_household_appliances = 20'000;
}


void alice_food(const int month, const int year) //блок питания и тд
{
    if (month == 12) alice.vtb.account_rub -= 2000;  // christmas party

    Percent inflation_food = 12.0;
    switch (year) {
    case 2026: inflation_food = 12.5; break;
    case 2027: inflation_food = 14.0; break;
    case 2028: inflation_food = 13.0; break;
    case 2029: inflation_food = 11.5; break;
    }
    alice.food += alice.food * (inflation_food / 100. / 12.);

    alice.vtb.account_rub -= alice.food;
}


void alice_salary(const int month, const int year)// зпшечка
{
    if (month == 3) {
        alice.salary *= 1.5;
    }

    if (month == 2 && year == 2026) {
        alice.vtb.account_rub += 5000;  // bonus
    }

    alice.vtb.account_rub += alice.salary;
}


void print_results()
{
    printf("Salary = %lld\n", alice.salary);

    RUB capital = 0;
    capital += alice.vtb.account_rub;
    capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
    capital += alice.car.value;
    printf("Capital = %lld", capital);
}


void alice_car()//бибика
{
    alice.vtb.account_rub -= alice.car.gas;
}


void alice_flat_1(const int month, const int year) //квартирка
{
    Percent inflation_flat_1 = 12.0;
    switch (year) {
    case 2026: inflation_flat_1 = 13.5; break;
    case 2027: inflation_flat_1 = 17.0; break;
    case 2028: inflation_flat_1 = 15.0; break;
    case 2029: inflation_flat_1 = 19.5; break;
    }

    alice.flat_1.housing_and_communal_servisec += alice.flat_1.housing_and_communal_servisec * (inflation_flat_1 / 100. / 12.);

    if (year % 2 == 0) {
        alice.vtb.account_rub -= alice.flat_1.checking_counters;
        alice.flat_1.general_household_needs= alice.flat_1.general_household_needs+500;
    }
    else {
        alice.flat_1.general_household_needs = alice.flat_1.general_household_needs + 300;
    }
    if (month % 5 == 0) {
        alice.vtb.account_rub -= alice.flat_1.repair_of_large_household_appliances;
    }

    if (year)

    alice.vtb.account_rub -= alice.flat_1.housing_and_communal_servisec;
    alice.vtb.account_rub -= alice.flat_1.current_repairs;
    alice.vtb.account_rub -= alice.flat_1.household_chemicals;
    alice.vtb.account_rub -= alice.flat_1.general_household_needs;
}



void alice_flat_2()
{

}


void simulation()
{
    int year = 2026;
    int month = 2;

    while (!(year == 2027 && month == 2)) {
        alice_salary(month, year);
        alice_car();
        alice_flat_1(month, year);
        // my_trip();
        // my_rent();
        // my_mortgage();
        alice_food(month, year);

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
    simulation();
    print_results();
}