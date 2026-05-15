#ifndef BANK_HPP
#define BANK_HPP

using RUB = long long int;
using USD = long long int;
using Percent = float;

struct Bank {
    RUB account;
    RUB deposite;
    Percent interest;
    Percent inflation;
    USD account_usd;
    float rate_usd_rub;
};

// Прототипы функций
Percent get_interest_rate_for_year(int year);
void apply_bank_interest(Bank& bank, int year);
void transfer_to_deposit(Bank& bank);

#endif