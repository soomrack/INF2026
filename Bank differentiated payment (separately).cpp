#include <stdio.h>
using Percent = float;

using RUB = long long int;

struct Bank {
    RUB percent_pay;
    RUB fix_pay = 84'000;
    Percent credit_per_in_month = 0.016275;
    RUB account;
    RUB credit_account;

};

struct Person {
    Bank MYFB;
    RUB salary;
};
struct Person alice;

                        //struct Bank_credit {
                        //   RUB fix_pay = 84'000;
                        //   Percent credit_per_in_month = 0.016275;
                        //Credit.fix_pay = 84'000;

void alice_init()
{
    alice.MYFB.account = 0;
    alice.MYFB.credit_account = 3'024'000;
    alice.salary = 150'000;
                                //alice.MYFB.cred_per_in_month = 0.016275;
};
                                //prinf("Fix_pay = %lld\n" Credit.fix_pay);


void alice_salary(const int month, const int year)
{
    alice.MYFB.account += alice.salary;
};

void alice_credit(const int month, const int year)
{
    if (alice.MYFB.credit_account > 0) {
        alice.MYFB.credit_account -= alice.MYFB.fix_pay;
        alice.MYFB.percent_pay += alice.MYFB.credit_account * alice.MYFB.credit_per_in_month;
        alice.MYFB.credit_account -= alice.MYFB.percent_pay;
        alice.MYFB.account -= alice.MYFB.fix_pay + alice.MYFB.percent_pay;
    };

    //alice.MYFB.accaunt += (alice.salary - alice.MYFB.fix_pay + alice.MYFB.credit_accaunt * alice.MYFB.fix_pay;

};




void print_results()
{
    printf("%lld\n", alice.MYFB.account);
};





void simulation()
{
    int year = 2026;
    int month = 2;

   // printf("Credit amount: %lld RUB\n\n", alice.MYFB.credit_account);
   
    while (!(year == 2029 && month == 2)) {  // включительно до февраля 2029
        alice_salary(month, year);
        alice_credit(month, year);

        //printf("Year: %d, Month: %02d, Account: %lld, Credit: %lld\n",
        
        //printf("Account after all operations: %lld RUB\n", alice.MYFB.account);
        

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
    alice_salary(month, year);
}

int main()
{
    alice_init();
    simulation();
    print_results();

    return 0;
}
        // 1'465'511'40 RUB

