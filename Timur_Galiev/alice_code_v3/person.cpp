#include "person.hpp"
#include <cstdlib>

void person_init(Person& p, const std::string& name, Strategy strategy) {
    p.name = name;
    p.strategy = strategy;

    p.vtb.account = 0;
    p.vtb.deposite = 1000000;
    p.vtb.interest = 14.5f;
    p.salary = 180000;
    p.vtb.inflation = 6.0f;

    p.vtb.account_usd = 1000;
    p.vtb.rate_usd_rub = 78.5f;

    p.food = 20000;
    p.dog = 10000;
    p.home = 30000;
    p.medicine = 5000;

    p.car.value = 2400000;
    p.car.gas = 15000;

    p.total_expenses = 0;
    p.total_income = 0;

    p.tax_rate = 13.0f;
    p.total_taxes_paid = 0;

    p.investment = 0;
    p.investment_total_in = 0;
    p.investment_profit = 0;

    p.mortgage_remaining = 0;
    p.mortgage_payment = 0;
    p.has_mortgage = false;

    p.total_random_expenses = 0;
    p.total_random_income = 0;
    p.events_count = 0;

    init_travel(p.travel);

    init_pension(p.pension);

    if (strategy == STRATEGY_CONSERVATIVE) {
        p.netflix_sub = 750;
        p.yandex_plus_sub = 449;
        p.game_pass_sub = 550;
        p.monthly_investment = 20000;
        p.investment_return = 20.0f;
    }
    else {
        p.netflix_sub = 0;
        p.yandex_plus_sub = 449;
        p.game_pass_sub = 0;
        p.monthly_investment = 35000;
        p.investment_return = 25.0f;
    }
}

void person_salary(Person& p, int month, int year) {
    RUB monthly_income = p.salary;

    if (month == 12) {
        monthly_income += p.salary;
        monthly_income += p.salary / 2;
    }

    if ((month == 1) && (year == 2027)) {
        p.salary = static_cast<RUB>(p.salary * 1.5);
        monthly_income = p.salary;
    }

    apply_income_tax(p, monthly_income);
}

void person_freelance(Person& p, int month, int year) {
    if (month == 3 && year == 2027) {
        RUB freelance_usd = 3000;
        p.vtb.account_usd += freelance_usd;
        RUB freelance_rub = static_cast<RUB>(freelance_usd * p.vtb.rate_usd_rub);
        apply_income_tax(p, freelance_rub);
    }
}

void apply_income_tax(Person& p, RUB income_before_tax) {
    if (income_before_tax <= 0) return;

    RUB tax = static_cast<RUB>(income_before_tax * (p.tax_rate / 100.0f));
    RUB income_after_tax = income_before_tax - tax;

    p.vtb.account += income_after_tax;
    p.total_income += income_after_tax;
    p.total_taxes_paid += tax;
}

void apply_investment_return(Person& p) {
    if (p.monthly_investment == 0 && p.investment == 0) return;

    RUB to_invest = p.monthly_investment;

    if (p.vtb.account >= to_invest) {
        p.vtb.account -= to_invest;
        p.investment += to_invest;
        p.investment_total_in += to_invest;
    }
    else {
        to_invest = p.vtb.account;
        p.vtb.account = 0;
        p.investment += to_invest;
        p.investment_total_in += to_invest;
    }

    if (p.investment > 0) {
        RUB monthly_return = static_cast<RUB>(p.investment * (p.investment_return / 12.0f / 100.0f));
        if (monthly_return > 0) {
            p.investment += monthly_return;
            p.investment_profit += monthly_return;
        }
    }
}

void update_exchange_rate(Person& p, int month, int year) {
    if (month == 1 || month == 4 || month == 7 || month == 10) {
        float change = (rand() % 17 - 8) / 100.0f;
        p.vtb.rate_usd_rub *= (1.0f + change);
    }
}

void take_mortgage_simple(Person& p) {
    if (p.has_mortgage) return;
    if (p.strategy != STRATEGY_CONSERVATIVE) return;

    RUB down_payment = 1500000;
    if (p.vtb.account < down_payment) return;

    p.vtb.account -= down_payment;
    p.total_expenses += down_payment;

    p.mortgage_remaining = 6500000;
    p.mortgage_payment = 60000;
    p.has_mortgage = true;
}

void apply_mortgage_payment_simple(Person& p) {
    if (!p.has_mortgage) return;
    if (p.mortgage_remaining <= 0) {
        p.has_mortgage = false;
        return;
    }

    if (p.vtb.account < p.mortgage_payment) return;

    p.vtb.account -= p.mortgage_payment;
    p.total_expenses += p.mortgage_payment;
    p.mortgage_remaining -= p.mortgage_payment;
}

void apply_random_event(Person& p, int month, int year) {
    // 25% шанс события в месяц
    int chance = rand() % 100;
    if (chance >= 25) return;

    p.events_count++;

    // Выбираем тип события (0-5)
    int event_type = rand() % 6;
    RUB amount = 0;
    const char* event_name = "";

    switch (event_type) {
    case 0:  // Ремонт машины (5 000 - 30 000)
    case 1:
        amount = 5000 + (rand() % 25000);
        event_name = "Car repair";
        p.total_random_expenses += amount;
        p.vtb.account -= amount;
        p.total_expenses += amount;
        break;

    case 2:  // Повышение аренды/коммуналки (+5% до +15%)
    {
        float increase = 5.0f + (rand() % 11);
        RUB old_home = p.home;
        p.home = static_cast<RUB>(p.home * (1.0f + increase / 100.0f));
        amount = p.home - old_home;
        event_name = "Rent increase";
        p.total_random_expenses += amount;
    }
    return;  // не вычитаем из счёта, так как это изменение цены

    case 3:  // Штраф (1 000 - 10 000)
        amount = 1000 + (rand() % 9000);
        event_name = "Fine";
        p.total_random_expenses += amount;
        p.vtb.account -= amount;
        p.total_expenses += amount;
        break;

    case 4:  // Кража (5 000 - 50 000)
        amount = 5000 + (rand() % 45000);
        event_name = "Theft";
        p.total_random_expenses += amount;
        p.vtb.account -= amount;
        p.total_expenses += amount;
        break;

    case 5:  // Подарок (10 000 - 50 000)
        amount = 10000 + (rand() % 40000);
        event_name = "Gift";
        p.total_random_income += amount;
        p.vtb.account += amount;
        p.total_income += amount;
        break;
    }

   
}