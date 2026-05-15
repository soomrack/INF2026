#ifndef PENSION_HPP
#define PENSION_HPP

#include "bank.hpp"

struct Person;

struct PensionAccount {
    // Основные параметры
    RUB total_contributions;      // сколько всего отчислено (деньги сотрудника)
    RUB total_employer_match;     // сколько добавил работодатель
    RUB investment_gain;          // инвестиционный доход
    RUB current_balance;          // текущий баланс счёта

    // Параметры настройки
    float employee_rate;          // отчисления сотрудника (% от зарплаты)
    float employer_rate;          // отчисления работодателя (% от зарплаты)
    float investment_return;      // доходность инвестиций (% годовых)
};

void init_pension(PensionAccount& p);
void apply_pension_contributions(Person& person, PensionAccount& pension, int month, int year);
void apply_pension_investment_return(PensionAccount& pension);
void print_pension_stats(const PensionAccount& pension);

#endif