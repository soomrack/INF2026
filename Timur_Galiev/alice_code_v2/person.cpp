#include "person.hpp"

void person_init(Person& p) {
    p.name = "Alice";
    p.vtb.account = 0;
    p.vtb.deposite = 1'000'000;
    p.vtb.interest = 14.5f;
    p.salary = 180'000;
    p.vtb.inflation = 6.0f;

    p.vtb.account_usd = 1'000;
    p.vtb.rate_usd_rub = 78.5f;

    p.netflix_sub = 750;
    p.yandex_sub = 449;
    p.gamepass_sub = 550;

    p.food = 20'000;
    p.dog = 10'000;
    p.home = 30'000;
    p.medicine = 5'000;

    p.car.value = 2'400'000;
    p.car.gas = 15'000;

    p.total_expenses = 0;
    p.total_income = 0;
    p.total_sub_expenses = 0;

    p.tax_rate = 13.0f;
    p.total_taxes_paid = 0;
}

void apply_income_taxes(Person& p, RUB income_before_taxes) {
    if (income_before_taxes <= 0) return;
    RUB tax = static_cast<RUB>(income_before_taxes * (p.tax_rate / 100.0f));
    RUB income_after_taxes = income_before_taxes - tax;
    p.vtb.account += income_after_taxes;
    p.total_income += income_after_taxes;
    p.total_taxes_paid += tax;
}

void person_salary(Person& p, int month, int year) {
    RUB monthly_income = p.salary;

    if (month == 12) {
        p.vtb.account += p.salary;  // 13th salary
    }

    if ((month == 1) && (year == 2027)) {
        p.salary = static_cast<RUB>(p.salary * 1.5);  // promotion
        monthly_income = p.salary;
    }

    apply_income_taxes(p, monthly_income);
}

void person_freelance(Person& p, int month, int year) {
    if (month == 3 && year == 2027) {
        USD freelance_usd = 3000;
        p.vtb.account_usd += freelance_usd;
        RUB freelance_rub = static_cast<RUB>(freelance_usd * p.vtb.rate_usd_rub);
        apply_income_taxes(p, freelance_rub);
    }
}