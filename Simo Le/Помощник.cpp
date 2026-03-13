#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using Percent = float;
using RUB = long long int;
using USD = long long int;
using KM = long long int;


struct Car {
    RUB expenses;
    RUB value;
    RUB gas;
    RUB total_fines;
    KM odometer;
};


struct Bank {
    RUB total_payment;
    RUB monthly_percent;
    RUB percent_pay;
    RUB fix_pay = 84'000;
    Percent credit_per_in_month = 0.016275;
    RUB account;
    RUB credit_account;

    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
};

struct Trip {
    RUB hotel;
    RUB tickets;
    RUB food;
    RUB museums;
    RUB entertainment;
};


struct Person {
    Bank vtb;
    RUB salary;
    RUB food;
    RUB rent;
    Car car;
    Trip trip;
};


struct Person alice;


void car_expenses(const int month, const int year)
{
    {
        alice.vtb.account_rub -= alice.car.gas;
        alice.car.odometer += 2000;
    }

    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 10.3; break;
    case 2027: inflation = 12.4; break;
    case 2028: inflation = 11.9; break;
    case 2029: inflation = 13.5; break;

    }

    if (alice.car.odometer % 7'500 == 0)
    {
        alice.car.expenses += 9000;
    }
    else if (alice.car.odometer % 15'000 == 0)
    {
        alice.car.expenses += 9000;
    }

    int random_car_expenses_suspension = rand() % 100;
    if ((random_car_expenses_suspension) < 5 || (alice.car.odometer < 20'000)) 
    {
        alice.car.expenses += 20'000;
    }
    else if ((random_car_expenses_suspension) < 20 || (alice.car.odometer < 50'000))
    {
        alice.car.expenses += 25'000;
    }
    else if ((random_car_expenses_suspension) < 50 || (alice.car.odometer < 100'000))
    {
        alice.car.expenses += 40'000;
    }
    else if ((random_car_expenses_suspension) < 84 || (alice.car.odometer > 100'000))
    {
        alice.car.expenses += 50'000;
    }
    alice.vtb.account_rub -= alice.car.expenses * (inflation / 100 / 12);
}



void home_random_expenses(const int month, const int year)
{
    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 10.3; break;
    case 2027: inflation = 12.4; break;
    case 2028: inflation = 11.9; break;
    case 2029: inflation = 13.5; break;

    }
    int random_chanse_home = rand() % 100;

    if (random_chanse_home > 70 )
    {
        int type_incident = rand() % 4;
        RUB incident_cost = 0;

        switch (type_incident) {
        case 0:           // bulb
            incident_cost = 150;
            break;
        case 1:           // tap
            incident_cost = 200;
            break;
        case 2:           // dishes
            incident_cost = 550;
            break;
        case 3:           // 
            incident_cost = 150;
            break;
        }
        alice.vtb.account_rub -= incident_cost * (inflation / 100 / 12);
             
    }
}//else if ()


void car_random_fines(const int month, const int year)
{
    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 15.0; break;
    case 2027: inflation = 17.0; break;
    case 2028: inflation = 20.0; break;
    case 2029: inflation = 24.5; break;

    }

    int random_chance_fine = rand() % 100;

    if (random_chance_fine < 15)
    {
        int fine_type = rand() % 5;
        RUB fine_amount = 0;

        switch (fine_type) {
        case 0:
            fine_amount = 500;
            printf("Fine for speeding: 500 RUB\n");
            break;
        case 1:
            fine_amount = 1000;
            printf("Fine for illegal parking: 1000 RUB\n");
            break;
        case 2:
            fine_amount = 1500;
            printf("Fine for running red light: 1500 RUB\n");
            break;
        case 3:
            fine_amount = 800;
            printf("Fine for phone while driving: 800 RUB\n");
            break;
        case 4:
            fine_amount = 750;
            printf("Fine for crossing solid line: 750 RUB\n");
            break;
        }

        alice.car.total_fines += fine_amount;
        alice.vtb.account_rub -= fine_amount * (inflation / 100 / 12);
    }
}


void alice_trip(const int month, const int year)
{
    if (month == 8 && year == 2026)
    {
        alice.trip.hotel = 2'500;
        alice.trip.tickets = 750;
        alice.trip.food = 500;
        alice.trip.museums = 700;
        alice.trip.entertainment = 1'000;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) +
            alice.trip.food +
            alice.trip.museums +
            alice.trip.entertainment;
    }

    else if (month == 7 && year == 2027)
    {
        alice.trip.hotel = 6550;
        alice.trip.tickets = 1300;
        alice.trip.food = 1200;
        alice.trip.museums = 1500;
        alice.trip.entertainment = 2200;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) + alice.trip.food + alice.trip.museums + alice.trip.entertainment;
    }

    else  if (month == 6 && year == 2028)
    {
        alice.trip.hotel = 10000;
        alice.trip.tickets = 3050;
        alice.trip.food = 4000;
        alice.trip.museums = 1700;
        alice.trip.entertainment = 5000;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) +
            alice.trip.food +
            alice.trip.museums +
            alice.trip.entertainment;

    }

    else  if (month == 7 && year == 2029)
    {
        alice.trip.hotel = 120000;
        alice.trip.tickets = 6500;
        alice.trip.food = 500;
        alice.trip.museums = 700;
        alice.trip.entertainment = 1000;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) +
            alice.trip.food +
            alice.trip.museums +
            alice.trip.entertainment;
    }

    else  if (month == 7 && year == 2030)
    {
        alice.trip.hotel = 150000;
        alice.trip.tickets = 50000;
        alice.trip.food = 4300;
        alice.trip.museums = 7300;
        alice.trip.entertainment = 10300;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) +
            alice.trip.food +
            alice.trip.museums +
            alice.trip.entertainment;
    }

    else  if (month == 8 && year == 2031)
    {
        alice.trip.hotel = 20000;
        alice.trip.tickets = 3300;
        alice.trip.food = 5200;
        alice.trip.museums = 3500;
        alice.trip.entertainment = 9000;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) +
            alice.trip.food +
            alice.trip.museums +
            alice.trip.entertainment;
    }

    else  if (month == 6 && year == 2032)
    {
        alice.trip.hotel = 150000;
        alice.trip.tickets = 54000;
        alice.trip.food = 7000;
        alice.trip.museums = 4300;
        alice.trip.entertainment = 11000;
        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) +
            alice.trip.food +
            alice.trip.museums +
            alice.trip.entertainment;
    }

}


void alice_credit(const int month, const int year)
{
    if (alice.vtb.credit_account == 0) return;

    alice.vtb.monthly_percent = alice.vtb.credit_account * alice.vtb.credit_per_in_month;
    alice.vtb.total_payment = alice.vtb.fix_pay + alice.vtb.monthly_percent;
    alice.vtb.credit_account += alice.vtb.monthly_percent;
    alice.vtb.credit_account -= alice.vtb.fix_pay;
    alice.vtb.account_rub -= alice.vtb.total_payment;
    alice.vtb.percent_pay += alice.vtb.monthly_percent;
}


void alice_init()
{
    alice.vtb.credit_account = 3'024'000;
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 1'000;
    alice.vtb.percent_pay = 0;

    alice.salary = 180'000;
    alice.food = 3'000;
    alice.rent = 14'500;

    alice.car.value = 2'400'000;
    alice.car.gas = 15'000;
    alice.car.total_fines = 0;

   
}


void alice_rent(const int month, const int year)
{
    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.0; break;
    case 2027: inflation = 12.4; break;
    case 2028: inflation = 12.9; break;
    case 2029: inflation = 13.4; break;

    }
    alice.rent += alice.rent * (inflation / 100 / 12);

    alice.vtb.account_rub -= alice.rent;
}


void alice_food(const int month, const int year)
{
    if (month == 12) alice.vtb.account_rub -= 2000;

    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    }
    alice.food += alice.food * (inflation / 100 / 12);

    alice.vtb.account_rub -= alice.food;
}


void alice_salary(const int month, const int year)
{
    if (month == 3) {
        alice.salary *= 1.5;
    }

    if (month == 2 && year == 2026) {
        alice.vtb.account_rub += 5000;
    }

    alice.vtb.account_rub += alice.salary;
}


void print_results()
{
    printf("\n=== SIMULATION RESULTS ===\n");
    printf("Salary = %lld RUB\n", alice.salary);
    printf("Car mileage = %lld km\n", alice.car.odometer);
    printf("Total fines for period = %lld RUB\n", alice.car.total_fines);
    printf("RUB account = %lld RUB\n", alice.vtb.account_rub);
    printf("USD account = %lld USD\n", alice.vtb.account_usd);
};


void simulation()
{
    int year = 2026;
    int month = 2;

    while (!(year == 2029 && month == 2)) {
        alice_salary(month, year);
        alice_rent(month, year);
        alice_food(month, year);
        alice_credit(month, year);
        alice_trip(month, year);
        car_expenses(month, year);
        car_random_fines(month,year);
        home_random_expenses(month,year);

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
};


int main()
{
    alice_init();
    simulation();
    print_results();

    return 0;
}