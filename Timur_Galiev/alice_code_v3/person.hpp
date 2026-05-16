#ifndef PERSON_HPP
#define PERSON_HPP

#include "travel.hpp"
#include "bank.hpp"
#include "car.hpp"
#include <string>
#include "pension.hpp"

enum Strategy {
    STRATEGY_CONSERVATIVE,   // Алиса
    STRATEGY_AGGRESSIVE      // Боб
};

struct Person {
    std::string name;
    Strategy strategy;

    Bank vtb;
    Car car;

    RUB salary;
    RUB food;
    RUB dog;
    RUB home;
    RUB medicine;

    RUB total_expenses;
    RUB total_income;

    RUB netflix_sub;
    RUB yandex_plus_sub;
    RUB game_pass_sub;

    float tax_rate;
    RUB total_taxes_paid;

    RUB investment;
    RUB investment_total_in;
    RUB investment_profit;
    RUB monthly_investment;
    float investment_return;

    Travel travel;

    PensionAccount pension;

    // Ипотека
    RUB mortgage_remaining;
    RUB mortgage_payment;
    bool has_mortgage;

    RUB total_random_expenses;   // всего потрачено на случайные события
    RUB total_random_income;     // всего получено от случайных событий
    int events_count;            // количество произошедших событий
};

void person_init(Person& p, const std::string& name, Strategy strategy);
void person_salary(Person& p, int month, int year);
void person_freelance(Person& p, int month, int year);
void apply_income_tax(Person& p, RUB income_before_tax);
void apply_investment_return(Person& p);
void update_exchange_rate(Person& p, int month, int year);
void take_mortgage_simple(Person& p);
void apply_mortgage_payment_simple(Person& p);
void compare_results(const Person& a, const Person& b);
void apply_random_event(Person& p, int month, int year);

#endif