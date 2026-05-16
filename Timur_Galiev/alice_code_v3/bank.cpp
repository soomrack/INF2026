#include "bank.hpp"

Percent get_interest_rate_for_year(int year) {
    if (year == 2026) return 14.5f;
    if (year == 2027) return 13.5f;
    if (year == 2028) return 12.5f;
    if (year == 2029) return 11.5f;
    return 10.0f;
}

void apply_bank_interest(Bank& bank, int year) {
    Percent rate = get_interest_rate_for_year(year);
    bank.deposite += bank.deposite * (rate / 12.0f / 100.0f);
}

RUB calculate_interest_amount(const Bank& bank, int year) {
    Percent rate = get_interest_rate_for_year(year);
    RUB interest = static_cast<RUB>(bank.deposite * (rate / 12.0f / 100.0f));
    return interest;
}

void transfer_to_deposit(Bank& bank) {
    bank.deposite += bank.account;
    bank.account = 0;
}