#include <stdio.h>


using Percent = float;

using RUB = long long int;
using USD = long long int;
using KM = long long int;


struct Car {
    RUB value;
    RUB gas;
    RUB fine;
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
    RUB enterteinment;
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

void car_trip(const int month, const int year)
{
    alice.car.odometer += 2000;
}


void car_expenses()
{              //if (alice.car.odometer/7'500 = 1 && 2 && 3 && 4 && 5 && 6 && 7 && 8 && 9)
    if (alice.car.odometer == 7'500)
    {
        alice.vtb.account_rub -= 9000;
    }

}


void alice_trip(const int month, const int year)
{
    if (month == 8 && year == 2026)
    {
        alice.trip.hotel = 2500;
        alice.trip.tickets = 750;
        alice.trip.food = 500;
        alice.trip.museums = 700;
        alice.trip.enterteinment = 1000;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) +
            alice.trip.food +
            alice.trip.museums +
            alice.trip.enterteinment;
    }

    else  if (month == 7 && year == 2027)
    {
        alice.trip.hotel = 6550;
        alice.trip.tickets = 1300;
        alice.trip.food = 1200;
        alice.trip.museums = 1500;
        alice.trip.enterteinment = 2200;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) + alice.trip.food + alice.trip.museums + alice.trip.enterteinment;
    }
    
    else  if (month == 6 && year == 2028)
        {
            alice.trip.hotel = 10000;
            alice.trip.tickets = 3050;
            alice.trip.food = 4000;
            alice.trip.museums = 1700;
            alice.trip.enterteinment = 5000;

            alice.vtb.account_rub -= alice.trip.hotel +
                (2 * alice.trip.tickets) +
                alice.trip.food +
                alice.trip.museums +
                alice.trip.enterteinment;
        
        }

    else  if (month == 7 && year == 2029)
    {
        alice.trip.hotel = 120000;
        alice.trip.tickets = 6500;
        alice.trip.food = 500;
        alice.trip.museums = 700;
        alice.trip.enterteinment = 1000;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) +
            alice.trip.food +
            alice.trip.museums +
            alice.trip.enterteinment;
    }

    else  if (month == 7 && year == 2030)
    {
        alice.trip.hotel = 150000;
        alice.trip.tickets = 50000;
        alice.trip.food = 4300;
        alice.trip.museums = 7300;
        alice.trip.enterteinment = 10300;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) +
            alice.trip.food +
            alice.trip.museums +
            alice.trip.enterteinment;
    }

    else  if (month == 8 && year == 2031)
    {
        alice.trip.hotel = 20000;
        alice.trip.tickets = 3300;
        alice.trip.food = 5200;
        alice.trip.museums = 3500;
        alice.trip.enterteinment = 9000;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) +
            alice.trip.food +
            alice.trip.museums +
            alice.trip.enterteinment;
    }

    else  if (month == 6 && year == 2032)
    {
        alice.trip.hotel = 150000;
        alice.trip.tickets = 54000;
        alice.trip.food = 7000;
        alice.trip.museums = 4300;
        alice.trip.enterteinment = 11000;

        alice.vtb.account_rub -= alice.trip.hotel +
            (2 * alice.trip.tickets) +
            alice.trip.food +
            alice.trip.museums +
            alice.trip.enterteinment;
    }

}


void alice_credit(const int month, const int year)
{
    if (alice.vtb.credit_account == 0) return;
    
    alice.vtb.monthly_percent = alice.vtb.credit_account * alice.vtb.credit_per_in_month;
        alice.vtb.total_payment = alice.vtb.fix_pay + alice.vtb.monthly_percent;  // Общая сумма к оплате в этом месяце
        alice.vtb.credit_account += alice.vtb.monthly_percent;    //  долг на проценты
        alice.vtb.credit_account -= alice.vtb.fix_pay; 
        alice.vtb.account_rub -= alice.vtb.total_payment;
        alice.vtb.percent_pay +=  alice.vtb.monthly_percent; // Сумма упдлаченных процентов


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
    alice.rent += alice.rent * (inflation / 100. / 12.);

    alice.vtb.account_rub -= alice.rent;
}


void alice_food(const int month, const int year)
{
    if (month == 12) alice.vtb.account_rub -= 2000;  // christmas party

    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    }
    alice.food += alice.food * (inflation / 100. / 12.);

    alice.vtb.account_rub -= alice.food;
}


void alice_salary(const int month, const int year)
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

    printf("Car ODO = %lld\n", alice.car.odometer);

    RUB capital = 0;
    capital += alice.vtb.account_rub;
    capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
    capital += alice.car.value;
    printf("Capital = %lld", capital);

};


void alice_car()
{
    alice.vtb.account_rub -= alice.car.gas;
};


void simulation()
{
    int year = 2026;
    int month = 2;

    while (!(year == 2029 && month == 2)) {
        alice_salary(month, year);
        alice_car();
        alice_rent(month, year);
        //alice_rent(month, year);
// my_cat();
// my_trip();
// my_rent();
// my_mortgage();
        alice_food(month, year);
        alice_credit(month, year);
        alice_trip(month, year);
        car_trip(month, year);
        car_expenses();

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

