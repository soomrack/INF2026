#ifndef PERSON_HPP
#define PERSON_HPP

#include "bank.hpp"
#include "car.hpp"
#include <string>

struct Person {
    std::string name;  // для идентификации
    Bank vtb;
    Car car;
    RUB salary;
    RUB food;
    RUB dog;
    RUB home;
    RUB medicine;
    RUB netflix_sub;
    RUB yandex_sub;
    RUB gamepass_sub;

    RUB total_expenses;
    RUB total_income;
    RUB total_sub_expenses;

    float tax_rate;
    RUB total_taxes_paid;
};

// Прототипы функций
void aplly_taxs(Person& p, RUB income_before_taxs);
void person_init(Person& p);
void person_salary(Person& p, int month, int year);
void person_freelance(Person& p, int month, int year);

#endif