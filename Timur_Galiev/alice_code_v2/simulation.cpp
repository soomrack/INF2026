#include "simulation.hpp"
#include "bank.hpp"
#include "expenses.hpp"
#include "inflation.hpp"
#include <cstdio>

void simulation_step(Person& p, int month, int year) {
    // Получение доходов
    person_salary(p, month, year);
    person_freelance(p, month, year);

    // Расходы
    apply_all_expenses(p);
    apply_subscriptions(p);

    // Банковские операции
    apply_bank_interest(p.vtb, year);
    transfer_to_deposit(p.vtb);

    // Инфляция на следующий месяц
    apply_inflation_to_person(p);
}

void run_simulation(Person& p) {
    int month = 2;
    int year = 2026;

    while (!(month == 3 && year == 2028)) {
        simulation_step(p, month, year);

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}
RUB calculate_total_sub_expenses(const Person& p) {
    return p.total_sub_expenses;
}

RUB calculate_total_expenses(const Person& p) {
    return p.total_expenses;  // просто возвращаем накопленное значение
}

RUB calculate_total_capital(const Person& p) {
    RUB capital = 0;
    capital += p.vtb.account;
    capital += p.car.value;
    capital += p.vtb.deposite;
    capital += static_cast<RUB>(p.vtb.account_usd * p.vtb.rate_usd_rub);
    return capital;
}

void print_results(const Person& p) {
    printf("\n========== FINAL RESULTS ==========\n");
    printf("Person: %s\n", p.name.c_str());
    printf("Final salary:  %lld RUB\n", p.salary);

    RUB capital = calculate_total_capital(p);
    printf("Final capital: %lld RUB\n", capital);

    // НОВОЕ: вывод статистики за весь период
    printf("\n--- Summary for entire period ---\n");
    printf("Total income:             %lld RUB\n", p.total_income);
    printf("Total expenses:           %lld RUB\n", p.total_expenses);
    printf("Total taxes paid:         %lld RUB\n", p.total_taxes_paid);

    // Реальный доход ДО налогов (для статистики)
    RUB income_before_tax = p.total_income + p.total_taxes_paid;
    printf("Total income before tax:  %lld RUB\n", income_before_tax);

    printf("\n--- Final subscription prices ---\n");
    printf("Netflix:     %lld RUB/month\n", p.netflix_sub);
    printf("Yandex Plus: %lld RUB/month\n", p.yandex_sub);
    printf("Game Pass:   %lld RUB/month\n", p.gamepass_sub);
    printf("Total:       %lld RUB\n", p.total_sub_expenses);

    printf("=====================================\n");
}