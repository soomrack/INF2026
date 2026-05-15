#ifndef TRAVEL_HPP
#define TRAVEL_HPP

#include "bank.hpp"

struct Person;

struct Travel {
    bool is_active;          // в путешествии ли сейчас
    RUB total_cost;          // общая стоимость путешествия
    RUB ticket_cost;         // билеты туда-обратно
    RUB accommodation_cost;  // проживание
    RUB food_cost;           // еда в путешествии
    RUB entertainment_cost;  // развлечения

    int duration_days;       // продолжительность в днях
    RUB total_spent;         // сколько уже потрачено за все путешествия
    int travel_count;        // количество путешествий
};

void init_travel(Travel& t);
void plan_travel(Person& p, Travel& t, int month, int year);
void apply_travel_costs(Person& p, Travel& t);
void print_travel_stats(const Travel& t);

#endif