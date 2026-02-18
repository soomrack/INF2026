#include <stdio.h>


using RUB = long long int;
using USD = long long int;

using Percent = float;


struct Bank {
    RUB account;
    RUB deposite;
    USD account_usd;
    float rate_usd_rub;

    Percent deposite_interest;
    Percent credit_interest;

    RUB credit;
    RUB credit_limit;
    RUB payment;

    RUB total_spent;
    RUB total_earned;
};


struct Car {
    RUB gas;
    RUB value;
};


struct Person {
    Bank tbank;
    Car car;
    RUB salary;
    RUB food;
};
struct Person rick;
//struct Person cliff;


void rick_init()
{
    rick.tbank.account = 0;
    rick.salary = 150'000;
    rick.tbank.account_usd = 0;

    rick.tbank.rate_usd_rub = 80.0;
    rick.tbank.deposite = 100'000;
    rick.tbank.deposite_interest = 8.0;
    rick.tbank.credit = 3'000'000;
    rick.tbank.credit_limit = 5'000'000;
    rick.tbank.credit_interest = 21.0;

    rick.tbank.total_spent = 0;
    rick.tbank.total_earned = 0;

    rick.food = 30'000;

    rick.car.value = 2'400'000;
    rick.car.gas = 30'000;
}


void rick_salary(const int month, const int year)
{
    if (month == 12) {
        rick.tbank.account += rick.salary;
    }

    if (month == 1 and year == 2027) {
        rick.salary *= 1.5;
    }

    rick.tbank.account += rick.salary;
}


void rick_food()
{
    rick.tbank.account -= rick.food;
}


void rick_car()
{
    rick.tbank.account -= rick.car.gas;
}

void rick_credit(const int month, const int year)
{
    if (rick.tbank.credit > 0) {
        if (year == 2026) rick.tbank.credit_interest = 21.0;
        if (year == 2027) rick.tbank.credit_interest = 20.5;
        if (year == 2028) rick.tbank.credit_interest = 19.5;
        if (year == 2029) rick.tbank.credit_interest = 18.5;
        if (year == 2030) rick.tbank.credit_interest = 18.0;
        if (year == 2031) rick.tbank.credit_interest = 17.5;
        if (year == 2032) rick.tbank.credit_interest = 17.0;
        if (year == 2033) rick.tbank.credit_interest = 16.5;
        if (year == 2034) rick.tbank.credit_interest = 16.0;
        if (year == 2035) rick.tbank.credit_interest = 15.5;
        if (year == 2036) rick.tbank.credit_interest = 15.0;
        if (year == 2037) rick.tbank.credit_interest = 14.5;
        if (year == 2038) rick.tbank.credit_interest = 14.0;
        if (year == 2039) rick.tbank.credit_interest = 13.5;
        if (year == 2040) rick.tbank.credit_interest = 13.0;
        if (year == 2041) rick.tbank.credit_interest = 12.5;
        if (year == 2042) rick.tbank.credit_interest = 12.0;
        if (year == 2043) rick.tbank.credit_interest = 11.5;
        if (year == 2044) rick.tbank.credit_interest = 11.0;
        if (year == 2045) rick.tbank.credit_interest = 10.5;
        if (year == 2046) rick.tbank.credit_interest = 10.0;
        if (year == 2047) rick.tbank.credit_interest = 9.5;
        if (year == 2048) rick.tbank.credit_interest = 9.0;
        if (year == 2049) rick.tbank.credit_interest = 8.5;
        if (year == 2050) rick.tbank.credit_interest = 8.0;

        rick.tbank.credit += rick.tbank.credit * (rick.tbank.credit_interest / 12.0 / 100.0);

        rick.tbank.payment = rick.tbank.credit * 0.05;
        if (rick.tbank.account >= rick.tbank.payment) {
            rick.tbank.account -= rick.tbank.payment;
            rick.tbank.credit -= rick.tbank.payment;
            rick.tbank.total_spent += rick.tbank.payment;
        }
        else {
            rick.tbank.account -= 1000;
            rick.tbank.total_spent += 1000;
        }
    }
}

void rick_deposite(const int month, const int year)
{
    if (year == 2026) rick.tbank.deposite_interest = 8.0;
    if (year == 2027) rick.tbank.deposite_interest = 7.8;
    if (year == 2028) rick.tbank.deposite_interest = 7.5;
    if (year == 2029) rick.tbank.deposite_interest = 7.2;
    if (year == 2030) rick.tbank.deposite_interest = 7.0;
    if (year == 2031) rick.tbank.deposite_interest = 6.8;
    if (year == 2032) rick.tbank.deposite_interest = 6.5;
    if (year == 2033) rick.tbank.deposite_interest = 6.2;
    if (year == 2034) rick.tbank.deposite_interest = 6.0;
    if (year == 2035) rick.tbank.deposite_interest = 5.8;
    if (year == 2036) rick.tbank.deposite_interest = 5.5;
    if (year == 2037) rick.tbank.deposite_interest = 5.2;
    if (year == 2038) rick.tbank.deposite_interest = 5.0;
    if (year == 2039) rick.tbank.deposite_interest = 4.8;
    if (year == 2040) rick.tbank.deposite_interest = 4.5;
    if (year == 2041) rick.tbank.deposite_interest = 4.2;
    if (year == 2042) rick.tbank.deposite_interest = 4.0;
    if (year == 2043) rick.tbank.deposite_interest = 3.8;
    if (year == 2044) rick.tbank.deposite_interest = 3.5;
    if (year == 2045) rick.tbank.deposite_interest = 3.2;
    if (year == 2046) rick.tbank.deposite_interest = 3.0;
    if (year == 2047) rick.tbank.deposite_interest = 2.8;
    if (year == 2048) rick.tbank.deposite_interest = 2.5;
    if (year == 2049) rick.tbank.deposite_interest = 2.2;
    if (year == 2050) rick.tbank.deposite_interest = 2.0;

    rick.tbank.deposite += rick.tbank.deposite * (rick.tbank.deposite_interest / 12.0 / 100.0);

    rick.tbank.deposite += rick.tbank.account;
    rick.tbank.account = 0;
}

void rick_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        rick.tbank.account_usd += 3'000;
    }
}


void print_results()
{
    printf("Salary = %lld\n", rick.salary);

    RUB capital = 0;
    capital += rick.tbank.account;
    capital += rick.car.value;
    capital += rick.tbank.deposite;
    capital += rick.tbank.account_usd * rick.tbank.rate_usd_rub;
    printf("Capital = %lld", capital);
}


void simulation()
{
    int month = 2;
    int year = 2026;

    while (not (month == 3 and year == 2050)) {
        rick_salary(month, year);
        rick_freelance(month, year);
        rick_credit(month, year);
        rick_food();
        rick_car();
        // my_cat();
        // my_medine();
        // my_home();
        rick_deposite(month, year);

        rick.tbank.total_earned += rick.salary;
        rick.tbank.total_spent += rick.food + rick.car.gas;

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    rick_init();

    simulation();

    print_results();
}