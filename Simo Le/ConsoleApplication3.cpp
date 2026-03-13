#include <stdio.h>
using Percent = float;
using RUB = long long int;

struct Bank {
    RUB percent_pay = 0;
    RUB fix_pay = 84'000;  // ежемесячный платеж по кредиту
    Percent credit_per_in_month = 0.016275;  // 1.6275% в месяц
    RUB account;  // счет Алисы
    RUB credit_account;  // остаток по кредиту
};

struct Person {
    Bank MYFB;
    RUB salary;
};

struct Person alice;

void alice_init()
{
    alice.MYFB.account = 0;
    alice.MYFB.credit_account = 3'024'000;  // сумма кредита
    alice.salary = 150'000;
}

void alice_salary(const int month, const int year)
{
    alice.MYFB.account += alice.salary;
    printf("  + Salary: %lld RUB\n", alice.salary);
}

void alice_credit(const int month, const int year)
{
    if (alice.MYFB.credit_account <= 0) {
        printf("  Credit already paid off!\n");
        return;
    }

    // Расчет процентов на остаток кредита
    RUB month_percent = alice.MYFB.credit_account * alice.MYFB.credit_per_in_month;

    printf("  Credit before: %lld RUB, Percent: %lld RUB\n",
        alice.MYFB.credit_account, month_percent);

    // Проверяем, не последний ли платеж (чтобы не уйти в минус)
    if (alice.MYFB.fix_pay >= alice.MYFB.credit_account + month_percent) {
        // Последний платеж - гасим остаток полностью
        RUB total_payment = alice.MYFB.credit_account + month_percent;
        alice.MYFB.account -= total_payment;
        alice.MYFB.credit_account = 0;
        printf("  Last payment! Total: %lld RUB (Body: %lld + Percent: %lld)\n",
            total_payment, alice.MYFB.credit_account + month_percent - month_percent, month_percent);
    }
    else {
        // Обычный платеж
        RUB body_payment = alice.MYFB.fix_pay - month_percent;
        alice.MYFB.account -= alice.MYFB.fix_pay;
        alice.MYFB.credit_account -= body_payment;
        printf("  Regular payment: %lld RUB (Body: %lld + Percent: %lld)\n",
            alice.MYFB.fix_pay, body_payment, month_percent);
    }

    alice.MYFB.percent_pay += month_percent;
    printf("  Account after credit: %lld RUB\n", alice.MYFB.account);
}

void print_results()
{
    printf("\n====================================\n");
    printf("FINAL RESULTS\n");
    printf("====================================\n");
    printf("Monthly salary: %lld RUB\n", alice.salary);
    printf("Total money on account: %lld RUB\n", alice.MYFB.account);
    printf("Credit remaining: %lld RUB\n", alice.MYFB.credit_account);
    printf("Total percent paid: %lld RUB\n", alice.MYFB.percent_pay);

    RUB total_earned = alice.salary * 36;  // 3 года * 12 месяцев = 36 месяцев
    RUB total_paid = 3'024'000 + alice.MYFB.percent_pay;
    printf("Total earned for 3 years: %lld RUB\n", total_earned);
    printf("Total paid (credit + percent): %lld RUB\n", total_paid);
    printf("Remaining money: %lld RUB\n", alice.MYFB.account);
    printf("====================================\n");
}

void simulation()
{
    int year = 2026;
    int month = 2;
    int month_counter = 0;

    printf("=== START SIMULATION ===\n");
    printf("Initial state:\n");
    printf("Year: %d, Month: %d\n", year, month);
    printf("Initial credit: %lld RUB\n", alice.MYFB.credit_account);
    printf("Initial account: %lld RUB\n\n", alice.MYFB.account);

    while (!(year == 2029 && month == 3)) {  // включительно до февраля 2029
        month_counter++;
        printf("\n--- Month %d: %d-%02d ---\n", month_counter, year, month);
        printf("Account before operations: %lld RUB\n", alice.MYFB.account);

        alice_salary(month, year);
        alice_credit(month, year);

        printf("Account after all operations: %lld RUB\n", alice.MYFB.account);
        printf("Credit remaining: %lld RUB\n", alice.MYFB.credit_account);

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }

    printf("\n=== SIMULATION END ===\n");
}
int main()
{
    alice_init();
    simulation();
    print_results();

    return 0;
}