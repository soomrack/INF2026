#include "pension.hpp"
#include "person.hpp"
#include <cstdio>

void init_pension(PensionAccount& p) {
    p.total_contributions = 0;
    p.total_employer_match = 0;
    p.investment_gain = 0;
    p.current_balance = 0;

    p.employee_rate = 6.0f;      // 6% от зарплаты отчисляет сотрудник
    p.employer_rate = 6.0f;      // 6% от зарплаты добавляет работодатель
    p.investment_return = 8.0f;  // 8% годовых доходность
}

void apply_pension_contributions(Person& person, PensionAccount& pension, int month, int year) {
    // Расчёт отчислений
    RUB employee_contrib = static_cast<RUB>(person.salary * (pension.employee_rate / 100.0f));
    RUB employer_contrib = static_cast<RUB>(person.salary * (pension.employer_rate / 100.0f));

    // Уменьшаем зарплату сотрудника на его отчисления
    person.vtb.account -= employee_contrib;
    person.total_expenses += employee_contrib;

    // Работодатель добавляет свою часть (не из зарплаты сотрудника)
    pension.total_contributions += employee_contrib;
    pension.total_employer_match += employer_contrib;
    pension.current_balance += employee_contrib + employer_contrib;

    
}

void apply_pension_investment_return(PensionAccount& pension) {
    if (pension.current_balance <= 0) return;

    // Начисляем доходность (8% годовых = ~0.67% в месяц)
    RUB monthly_gain = static_cast<RUB>(pension.current_balance * (pension.investment_return / 12.0f / 100.0f));

    if (monthly_gain > 0) {
        pension.current_balance += monthly_gain;
        pension.investment_gain += monthly_gain;
    }
}

void print_pension_stats(const PensionAccount& pension) {
    printf("\n--- PENSION (retirement savings) ---\n");
    printf("  My contributions:        %lld RUB\n", pension.total_contributions);
    printf("  Employer contributions:   %lld RUB\n", pension.total_employer_match);
    printf("  Investment gain:          %lld RUB\n", pension.investment_gain);
    printf("  Current balance:          %lld RUB\n", pension.current_balance);

    if (pension.total_contributions > 0) {
        float employer_match_percent = (float)pension.total_employer_match / pension.total_contributions * 100;
        float roi = (float)pension.investment_gain / pension.total_contributions * 100;
        printf("  Employer match:           %.1f%% of my contributions\n", employer_match_percent);
        printf("  Return on contributions:  %.1f%%\n", roi);
    }
}