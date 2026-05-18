#include <cmath>
#include <algorithm>

#include "finance/tax.hpp"

// Реализация расчётов НДФЛ и налоговых вычетов

void Tax_history::add_refund(int year, double amount, const std::string& reason)
{
    refunds.push_back({ year, amount, reason });
    total_refunds_received += amount;
}

// Вспомогательная функция: НДФЛ от накопленного дохода.
// Используется для расчёта нарастающим итогом с учётом ставки 15% сверх 5 млн.
static double tax_from_cumulative_income(double income)
{
    if (income <= ndfl_high_threshold)
        return income * ndfl_rate_base;

    return ndfl_high_threshold * ndfl_rate_base + (income - ndfl_high_threshold) * ndfl_rate_high;
}

double monthly_child_deduction(const Standard_deduction_state& s)
{
    if (s.income_ytd >= child_deduction_income_limit)
        return 0.0;

    double total = 0.0;
    for (int i = 1; i <= s.children_count; ++i)
    {
        if (i == 1) 
            total += child_deduction_first;
        else if (i == 2) 
            total += child_deduction_second;
        else
            total += child_deduction_third;
    }

    return total;
}

// Нарастающий расчёт: берём налог с дохода за весь год и вычитаем уже удержанное.
// Благодаря этому в декабрьском месяце корректно учитывается бонус.
double calculate_employer_ndfl(
    double gross_salary,
    double income_ytd,
    const Standard_deduction_state& std_ded)
{
    double child_ded = monthly_child_deduction(std_ded);
    double taxable = std::max(0.0, gross_salary - child_ded);

    double tax_now = tax_from_cumulative_income(income_ytd + taxable);
    double tax_prev = tax_from_cumulative_income(income_ytd);
    return tax_now - tax_prev;
}

double property_purchase_deduction_for_year(
    Property_deduction_state& prop,
    double annual_gross_income)
{
    if (!prop.eligible || prop.purchase_limit_remaining <= 0.0)
        return 0.0;

    double deduction = std::min(prop.purchase_limit_remaining, annual_gross_income);
    prop.purchase_limit_remaining -= deduction;
    return deduction;
}

// Вычет по процентам ограничен: фактически уплаченными процентами за год,
// лимитом в 3 млн и остатком дохода после вычета по покупке.
double property_interest_deduction_for_year(
    Property_deduction_state& prop,
    double annual_gross_income)
{
    if (!prop.eligible || prop.interest_limit_remaining <= 0.0)
        return 0.0;

    double claimable = std::min(prop.interest_paid_current_year, prop.interest_limit_remaining);
    claimable = std::min(claimable, annual_gross_income);

    prop.interest_limit_remaining -= claimable;
    prop.interest_paid_current_year= 0.0;  // сброс на новый год
    return claimable;
}

// Обычные расходы суммируются в общий лимит 120к.
// Дорогостоящее лечение — отдельно, без лимита (перечень Правительства РФ).
double social_deduction_for_year(const Social_deduction_state& s)
{
    double ordinary = s.medical_paid + s.education_self_paid;

    double children_edu = s.education_children_paid;
    if (s.children_in_education > 0)
    {
        double per_child_limit = education_child_limit * s.children_in_education;
        children_edu = std::min(children_edu, per_child_limit);
    }
    ordinary += children_edu;
    ordinary = std::min(ordinary, social_combined_limit);

    return ordinary + s.medical_expensive_paid;
}

// Декларация 3-НДФЛ: рассчитать возврат за год.
// Возврат = разница между налогом без вычетов и налогом с вычетами,
// но не больше фактически уплаченного за год.
double file_tax_return(
    Tax_year_state& state,
    double annual_gross_income,
    double tax_actually_paid)
{
    double ded_purchase = property_purchase_deduction_for_year(state.property, annual_gross_income);
    double ded_interest = property_interest_deduction_for_year(state.property, annual_gross_income - ded_purchase);
    double ded_social = social_deduction_for_year(state.social);
    state.social = {};  // социальные вычеты: остаток на следующий год НЕ переносится

    double total_deduction = ded_purchase + ded_interest + ded_social;
    if (total_deduction <= 0.0)
        return 0.0;

    double taxable_after = std::max(0.0, annual_gross_income - total_deduction);
    double overpaid = tax_from_cumulative_income(annual_gross_income)
                         - tax_from_cumulative_income(taxable_after);

    double refund = std::min(overpaid, tax_actually_paid);
    return std::max(0.0, refund);
    // Намеренно НЕ добавляем в pending — вызывающая сторона решает, когда зачислить.
}

void record_mortgage_interest_payment(Property_deduction_state& prop, double interest_amount)
{
    prop.interest_paid_current_year += interest_amount;
    prop.interest_paid_total += interest_amount;
}

void record_medical_expense(Social_deduction_state& social, double amount, bool is_expensive)
{
    if (is_expensive)
        social.medical_expensive_paid += amount;
    else
        social.medical_paid += amount;
}

void record_education_expense(Social_deduction_state& social, double amount, bool is_for_child)
{
    if (is_for_child)
        social.education_children_paid += amount;
    else
        social.education_self_paid += amount;
}

double remaining_property_refund_potential(const Property_deduction_state& prop)
{
    return (prop.purchase_limit_remaining + prop.interest_limit_remaining) * ndfl_rate_base;
}

Property_deduction_state make_property_deduction(double property_price, int purchase_year)
{
    double purchase_limit = std::min(property_price, property_purchase_deduction_limit);
    return 
    {
        .eligible = true,
        .purchase_limit_remaining = purchase_limit,
        .interest_limit_remaining = property_interest_deduction_limit,
        .interest_paid_current_year = 0.0,
        .interest_paid_total = 0.0,
        .purchase_year = purchase_year,
    };
}

void reset_for_new_tax_year(Tax_year_state& state, int new_year)
{
    state.year = new_year;
    state.gross_income_ytd = 0.0;
    state.tax_withheld_ytd = 0.0;
    state.social = {};
    state.standard.income_ytd = 0.0;
    // tax_refund_pending и лимиты имущественного вычета сохраняются
}

double effective_ndfl_rate(double gross_income, double total_ndfl_paid)
{
    if (gross_income <= 0.0) 
        return 0.0;
    return total_ndfl_paid / gross_income;
}
