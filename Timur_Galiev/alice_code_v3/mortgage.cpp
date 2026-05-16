#include "mortgage.hpp"
#include "person.hpp"
#include <cstdio>
#include <cmath>

void init_mortgage(Mortgage& m) {
    m.total_loan = 0;
    m.remaining_loan = 0;
    m.monthly_payment = 0;
    m.annual_rate = 12.0f;
    m.months_total = 240;
    m.months_paid = 0;
    m.property_value = 8000000;
}

void take_mortgage(Person& p, Mortgage& m) {
    if (m.remaining_loan > 0) {
        printf("  Mortgage already active! Remaining debt: %lld RUB\n", m.remaining_loan);
        return;
    }

    RUB down_payment = 1500000;

    if (p.vtb.account < down_payment) {
        printf("  Not enough for down payment! Need %lld RUB, have %lld\n",
            down_payment, p.vtb.account);
        return;
    }

    p.vtb.account -= down_payment;
    p.total_expenses += down_payment;

    m.total_loan = m.property_value - down_payment;
    m.remaining_loan = m.total_loan;
    m.months_paid = 0;

    float monthly_rate = m.annual_rate / 12.0f / 100.0f;
    float annuity = (monthly_rate * pow(1 + monthly_rate, m.months_total)) /
        (pow(1 + monthly_rate, m.months_total) - 1);
    m.monthly_payment = static_cast<RUB>(m.total_loan * annuity + 0.5f);

    printf("\n  ===== MORTGAGE TAKEN! =====\n");
    printf("  Apartment price: %lld RUB\n", m.property_value);
    printf("  Down payment: %lld RUB\n", down_payment);
    printf("  Loan amount: %lld RUB\n", m.total_loan);
    printf("  Monthly payment: %lld RUB\n", m.monthly_payment);
    printf("  Interest rate: %.1f%%\n", m.annual_rate);
    printf("  Term: %d months (%d years)\n", m.months_total, m.months_total / 12);
}

void apply_mortgage_payment(Person& p, Mortgage& m) {
    if (m.remaining_loan <= 0) {
        if (m.months_paid > 0) {
            printf("  ===== MORTGAGE FULLY PAID OFF! =====\n");
        }
        return;
    }

    if (p.vtb.account < m.monthly_payment) {
        printf("  WARNING: Not enough money for mortgage payment!\n");
        printf("     Need %lld RUB, have %lld RUB\n", m.monthly_payment, p.vtb.account);
        RUB actual_payment = p.vtb.account;
        p.vtb.account = 0;
        m.remaining_loan -= actual_payment;
        p.total_expenses += actual_payment;
        return;
    }

    p.vtb.account -= m.monthly_payment;
    p.total_expenses += m.monthly_payment;

    float monthly_rate = m.annual_rate / 12.0f / 100.0f;
    RUB interest_payment = static_cast<RUB>(m.remaining_loan * monthly_rate);
    RUB principal_payment = m.monthly_payment - interest_payment;

    m.remaining_loan -= principal_payment;
    m.months_paid++;

    printf("  Mortgage: -%lld RUB (interest: %lld, principal: %lld)\n",
        m.monthly_payment, interest_payment, principal_payment);

    if (m.remaining_loan > 0) {
        printf("     Remaining: %lld RUB (%d months left)\n",
            m.remaining_loan, m.months_total - m.months_paid);
    }
}

void print_mortgage_info(const Mortgage& m) {
    printf("\n--- Mortgage ---\n");
    if (m.remaining_loan <= 0) {
        printf("Status: PAID OFF\n");
        if (m.months_paid > 0) {
            printf("Total paid: %lld RUB\n", m.monthly_payment * m.months_paid);
        }
    }
    else {
        printf("Status: ACTIVE\n");
        printf("Remaining debt: %lld RUB\n", m.remaining_loan);
        printf("Monthly payment: %lld RUB\n", m.monthly_payment);
        printf("Months paid: %d / %d\n", m.months_paid, m.months_total);
        printf("Progress: %.1f%%\n", (float)m.months_paid / m.months_total * 100);
    }
    printf("Apartment value: %lld RUB\n", m.property_value);

    if (m.remaining_loan > 0) {
        RUB equity = m.property_value - m.remaining_loan;
        printf("Your equity: %lld RUB (%.1f%% of apartment)\n",
            equity, (float)equity / m.property_value * 100);
    }
}