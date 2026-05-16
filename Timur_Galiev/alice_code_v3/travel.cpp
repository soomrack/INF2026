#include "travel.hpp"
#include "person.hpp"
#include <cstdio>
#include <cstdlib>

void init_travel(Travel& t) {
    t.is_active = false;
    t.total_cost = 0;
    t.ticket_cost = 0;
    t.accommodation_cost = 0;
    t.food_cost = 0;
    t.entertainment_cost = 0;
    t.duration_days = 0;
    t.total_spent = 0;
    t.travel_count = 0;
}

void plan_travel(Person& p, Travel& t, int month, int year) {
    // Путешествия в июле каждого года (кроме 2028, так как симуляция до марта)
    if (month != 7) return;
    if (year == 2028) return;
    if (t.is_active) return;

    // Случайный выбор направления (влияет на стоимость)
    int destination = rand() % 3;
    const char* destination_name = "";

    switch (destination) {
    case 0: // Турция
        destination_name = "Turkey";
        t.ticket_cost = 25000;           // билеты туда-обратно
        t.accommodation_cost = 35000;     // 7 дней в отеле
        t.food_cost = 15000;              // питание
        t.entertainment_cost = 10000;     // экскурсии
        t.duration_days = 7;
        break;
    case 1: // Европа
        destination_name = "Europe";
        t.ticket_cost = 45000;
        t.accommodation_cost = 50000;
        t.food_cost = 20000;
        t.entertainment_cost = 15000;
        t.duration_days = 7;
        break;
    case 2: // Россия (Сочи)
        destination_name = "Sochi";
        t.ticket_cost = 15000;
        t.accommodation_cost = 25000;
        t.food_cost = 12000;
        t.entertainment_cost = 8000;
        t.duration_days = 7;
        break;
    }

    t.total_cost = t.ticket_cost + t.accommodation_cost + t.food_cost + t.entertainment_cost;

    // Проверяем, хватает ли денег
    if (p.vtb.account < t.total_cost) {
        return;
    }

    // Списываем деньги
    p.vtb.account -= t.total_cost;
    p.total_expenses += t.total_cost;
    t.total_spent += t.total_cost;
    t.travel_count++;
    t.is_active = true;

    printf("\n  %s: TRAVEL to %s!\n", p.name.c_str(), destination_name);
    printf("     Duration: %d days\n", t.duration_days);
    printf("     Tickets: %lld RUB\n", t.ticket_cost);
    printf("     Accommodation: %lld RUB\n", t.accommodation_cost);
    printf("     Food: %lld RUB\n", t.food_cost);
    printf("     Entertainment: %lld RUB\n", t.entertainment_cost);
    printf("     Total: %lld RUB\n", t.total_cost);
}

void apply_travel_costs(Person& p, Travel& t) {
    if (!t.is_active) return;

    // Путешествие закончилось через 30 дней (просто снимаем флаг)
    // В реальности можно было бы списывать деньги постепенно, но у нас уже всё списано
    t.is_active = false;
}

void print_travel_stats(const Travel& t) {
    if (t.travel_count == 0) {
        printf("  No travels\n");
        return;
    }

    printf("  Number of travels:       %d\n", t.travel_count);
    printf("  Total spent on travels:  %lld RUB\n", t.total_spent);
    printf("  Average per travel:      %lld RUB\n", t.total_spent / t.travel_count);
}