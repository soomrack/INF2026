#include "simulation.hpp"
#include "bank.hpp"
#include "expenses.hpp"
#include "inflation.hpp"

void simulation_step(Person& p, int month, int year) {
    // 1. Доходы
    person_salary(p, month, year);
    person_freelance(p, month, year);

    // 2. ПЕНСИОННЫЕ ОТЧИСЛЕНИЯ (после дохода, до расходов)
    apply_pension_contributions(p, p.pension, month, year);

    // 3. Курс валют
    update_exchange_rate(p, month, year);

    // 4. Расходы
    apply_all_expenses(p);
    apply_subscriptions(p);

    // 5. Путешествия
    plan_travel(p, p.travel, month, year);
    apply_travel_costs(p, p.travel);

    // 6. Случайные события
    apply_random_event(p, month, year);

    // 7. Ипотека
    apply_mortgage_payment_simple(p);

    // 8. ПЕНСИОННЫЙ ИНВЕСТИЦИОННЫЙ ДОХОД
    apply_pension_investment_return(p.pension);

    // 9. Инвестиции
    apply_investment_return(p);

    // 10. Банк
    apply_bank_interest(p.vtb, year);
    transfer_to_deposit(p.vtb);

    // 11. Инфляция
    apply_inflation_to_person(p);
}

void run_simulation(Person& p) {
    int month = 2;
    int year = 2026;

    while (!(month == 3 && year == 2028)) {
        simulation_step(p, month, year);

        if (month == 1 && year == 2027 && !p.has_mortgage && p.strategy == STRATEGY_CONSERVATIVE) {
            take_mortgage_simple(p);
        }

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}

RUB calculate_total_capital(const Person& p) {
    RUB capital = 0;
    capital += p.vtb.account;
    capital += p.car.value;
    capital += p.vtb.deposite;
    capital += static_cast<RUB>(p.vtb.account_usd * p.vtb.rate_usd_rub);
    capital += p.investment;
    if (p.has_mortgage) {
        capital += 8000000;
    }
    return capital;
}

float calculate_cumulative_inflation(const Person& p) {
    const RUB FOOD_START = 20000;
    if (FOOD_START <= 0) return 0.0f;
    return ((float)p.food / FOOD_START - 1.0f) * 100.0f;
}

RUB calculate_real_capital(const Person& p, float cumulative_inflation) {
    float inflation_multiplier = 1.0f + cumulative_inflation / 100.0f;
    return static_cast<RUB>(calculate_total_capital(p) / inflation_multiplier);
}

void print_results(const Person& p) {
    RUB capital = calculate_total_capital(p);
    float inflation = calculate_cumulative_inflation(p);
    RUB real_capital = calculate_real_capital(p, inflation);

    RUB income_before_tax = p.total_income + p.total_taxes_paid;

    printf("\n");
    printf("========================================\n");
    printf("  %s\n", p.name.c_str());
    printf("========================================\n");

    printf("\n--- CAPITAL ---\n");
    printf("  Final capital:               %lld RUB\n", capital);
    printf("  Real capital (2026 prices):  %lld RUB\n", real_capital);
    printf("  Purchasing power loss:       %lld RUB\n", capital - real_capital);

    printf("\n--- INCOME & TAXES ---\n");
    printf("  Income before tax:           %lld RUB\n", income_before_tax);
    printf("  Taxes paid (13%%):             %lld RUB\n", p.total_taxes_paid);
    printf("  Income after tax:            %lld RUB\n", p.total_income);

    printf("\n--- EXPENSES & SAVINGS ---\n");
    printf("  Total expenses:              %lld RUB\n", p.total_expenses);
    printf("  Savings:                     %lld RUB\n", p.total_income - p.total_expenses);
    if (p.total_income > 0) {
        float savings_rate = (1.0f - (float)p.total_expenses / p.total_income) * 100;
        printf("  Savings rate:                %.1f %%\n", savings_rate);
    }

    printf("\n--- INVESTMENTS ---\n");
    printf("  Invested (total):            %lld RUB\n", p.investment_total_in);
    printf("  Investment profit:           %lld RUB\n", p.investment_profit);
    printf("  Investment value:            %lld RUB\n", p.investment);
    if (p.investment_total_in > 0) {
        float profit_percent = (float)p.investment_profit / p.investment_total_in * 100;
        printf("  ROI:                         %.1f %%\n", profit_percent);
    }

    printf("\n--- MORTGAGE ---\n");
    if (p.has_mortgage) {
        RUB equity = 8000000 - p.mortgage_remaining;
        printf("  Remaining debt:              %lld RUB\n", p.mortgage_remaining);
        printf("  Monthly payment:             %lld RUB\n", p.mortgage_payment);
        printf("  Your equity:                 %lld RUB\n", equity);
    }
    else {
        printf("  No active mortgage\n");
    }

    print_pension_stats(p.pension);
}