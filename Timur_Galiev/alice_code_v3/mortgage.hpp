#ifndef MORTGAGE_HPP
#define MORTGAGE_HPP

#include "bank.hpp"

struct Person;

struct Mortgage {
    RUB total_loan;
    RUB remaining_loan;
    RUB monthly_payment;
    float annual_rate;
    int months_total;
    int months_paid;
    RUB property_value;
};

void init_mortgage(Mortgage& m);
void take_mortgage(Person& p, Mortgage& m);
void apply_mortgage_payment(Person& p, Mortgage& m);
void print_mortgage_info(const Mortgage& m);

#endif