#include "expenses.hpp"
#include <cstdio>

void spend_food(Person& p) {
    p.vtb.account -= p.food;
}

void spend_gas(Person& p) {
    p.vtb.account -= p.car.gas;
}

void spend_dog(Person& p) {
    p.vtb.account -= p.dog;
}

void spend_medicine(Person& p) {
    p.vtb.account -= p.medicine;
}

void spend_home(Person& p) {
    p.vtb.account -= p.home;
}

void apply_all_expenses(Person& p) {
    RUB monthly_expenses = 0;

    monthly_expenses += p.food;
    monthly_expenses += p.car.gas;
    monthly_expenses += p.dog;
    monthly_expenses += p.medicine;
    monthly_expenses += p.home;

    p.vtb.account -= monthly_expenses;
    p.total_expenses += monthly_expenses;
}

void apply_subscriptions(Person& p) {
    RUB monthly_subscriptions = 0;

    monthly_subscriptions += p.netflix_sub;
    monthly_subscriptions += p.yandex_plus_sub;
    monthly_subscriptions += p.game_pass_sub;

    p.vtb.account -= monthly_subscriptions;
    p.total_expenses += monthly_subscriptions;
}