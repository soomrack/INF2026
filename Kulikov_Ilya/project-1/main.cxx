#include <cstdlib>
#include <string>
#include <cmath>

using Integer = unsigned long long int;
using RUB_kopecks = Integer;
using Month = Integer;
using Kilometer = Integer;
using SquareMeters = double;
using Percent = double;
using InsuranceAmount = RUB_kopecks;
using LoanAmount = RUB_kopecks;
using AnimalCount = unsigned int;

struct Account {
    RUB_kopecks money;

    Account(RUB_kopecks initial_capital);

    void operator+=(RUB_kopecks amount);
    void operator-=(RUB_kopecks amount);
};


Account::Account(RUB_kopecks initial_capital) : money(initial_capital) {}


void Account::operator+=(RUB_kopecks amount)
{
    money += amount;
}

void Account::operator-=(RUB_kopecks amount)
{
    if (money < amount) exit(1);
    money -= amount;
}


struct Deposit : public Account
{
    Percent interest;

    Deposit(RUB_kopecks initial_capital, Percent interest);

    void accrue_interest();
};


Deposit::Deposit(RUB_kopecks initial_capital, Percent interest)
  : Account(initial_capital), interest(interest) {}


void Deposit::accrue_interest()
{
    money *= 1.0 + interest / 100.0;
}


enum Food {
    Apple,
    Steak,
    Cookie,
    Ramen,
    Potato,
    Salad,
    Spaghetti,
};


struct Car {
    Kilometer mileage;
    Percent wear;

    Car();

    void repair(Account &account);
    void drive(Kilometer route);
};


Car::Car() : mileage(0), wear(0.0) {}


void Car::repair(Account &account)
{
    double repair_coefficient = 0.0;
    if (wear <= 10.0)
        repair_coefficient = wear * wear / 10000.0;
    else if (wear <= 50.0)
        repair_coefficient = ((double)mileage / 500'000'00) * wear * wear * wear / 1000000.0;
    else if (wear <= 90.0)
        repair_coefficient = ((double)mileage / 500'000'00) * 20.0 * wear * wear * wear / 1000000.0;
    else
        repair_coefficient = wear;

    account -= ((double)mileage / 50'000) * repair_coefficient;
    wear = 0.0;
}


void Car::drive(Kilometer route)
{
    mileage += route;
    wear += route * wear / 100.0;
    if (wear >= 100.0) exit(1);
}


struct Flat {
    RUB_kopecks mortgage;
    Percent mortgage_rate;
    SquareMeters area;

    Flat(RUB_kopecks price, SquareMeters area, Percent mortgage_rate);

    void pay_mortgage(Account &account, RUB_kopecks payment);
};

Flat::Flat(RUB_kopecks price, SquareMeters area, Percent mortgage_rate)
    : mortgage(price), area(area), mortgage_rate(mortgage_rate) {}


void Flat::pay_mortgage(Account &account, RUB_kopecks payment)
{
    mortgage -= payment;
    mortgage *= (100.0 - mortgage_rate) / 100.0;
    account -= payment;
}


struct BankLoan {
    LoanAmount loan_amount;
    Percent interest_rate;
    Month repayment_period;

    BankLoan(LoanAmount amount, Percent interest, Month period);

    void repay(Account &account, LoanAmount amount);
    void accrue_interest();
};


BankLoan::BankLoan(LoanAmount amount, Percent interest, Month period)
    : loan_amount(amount), interest_rate(interest), repayment_period(period) {}


void BankLoan::repay(Account &account, LoanAmount amount)
{
    if (loan_amount < amount) exit(1);
    loan_amount -= amount;
    account -= amount;
}


void BankLoan::accrue_interest()
{
    loan_amount *= 1.0 + interest_rate / 100.0;
}


struct Animal {
    std::string species;
    Percent health_status;
    AnimalCount number;

    Animal(std::string species, Percent health_status, AnimalCount number);

    void feed(Percent health_bonus);
    void heal(Percent health_bonus);
};


Animal::Animal(std::string species, Percent health_status, AnimalCount number)
    : species(species), health_status(health_status), number(number) {}


void Animal::feed(Percent health_bonus)
{
    health_status += health_bonus;
    if (health_status > 100.0)
        health_status = 100.0;
    else if (health_status <= 0.0)
        exit(1);
}


void Animal::heal(Percent health_bonus)
{
    health_status += health_bonus;
    if (health_status > 100.0)
        health_status = 100.0;
    else if (health_status <= 0.0)
        exit(1);
}


struct Job {
    std::string title;
    RUB_kopecks salary;
    Percent satisfaction;

    Job(std::string title, RUB_kopecks salary, Percent satisfaction);

    void get_bonus(Account &account);
};


Job::Job(std::string title, RUB_kopecks salary, Percent satisfaction)
    : title(title), salary(salary), satisfaction(satisfaction) {}


void Job::get_bonus(Account &account)
{
    RUB_kopecks bonus = 0;
    if (satisfaction >= 80.0)
        bonus = salary * 0.1;
    else if (satisfaction >= 50.0)
        bonus = salary * 0.05;
    account += bonus;
}


struct Insurance {
    InsuranceAmount amount;
    Percent coverage_rate;

    Insurance(InsuranceAmount amount, Percent coverage_rate);

    void pay_for_insurance(Account &account);
};


Insurance::Insurance(InsuranceAmount amount, Percent coverage_rate)
    : amount(amount), coverage_rate(coverage_rate) {}


void Insurance::pay_for_insurance(Account &account)
{
    account -= amount;
    if (account.money < 0) exit(1);
}


struct House {
    RUB_kopecks price;
    RUB_kopecks maintenance_cost;
    Percent location_quality;

    House(RUB_kopecks price, RUB_kopecks maintenance_cost, Percent location_quality);

    void maintain(Account &account);
};


House::House(RUB_kopecks price, RUB_kopecks maintenance_cost, Percent location_quality)
    : price(price),
      maintenance_cost(maintenance_cost),
      location_quality(location_quality) {}


void House::maintain(Account &account)
{
    RUB_kopecks cost = maintenance_cost * (100.0 - location_quality) / 100.0;
    account -= cost;
    if (account.money < 0) exit(1);
}


struct Investment {
    RUB_kopecks initial_investment;
    Percent annual_return_rate;

    Investment(RUB_kopecks initial_investment, Percent annual_return_rate);

    void grow(Account &account);
};


Investment::Investment(RUB_kopecks initial_investment, Percent annual_return_rate)
    : initial_investment(initial_investment),
      annual_return_rate(annual_return_rate) {}


void Investment::grow(Account &account)
{
    initial_investment *= 1.0 + annual_return_rate / 100.0;
    account += initial_investment;
}


struct Travel {
    RUB_kopecks budget;
    Percent business_trip_bonus;

    Travel(RUB_kopecks budget, Percent business_trip_bonus);

    void plan_trip(Account &account);
    void go_on_trip(Account &account);
};


Travel::Travel(RUB_kopecks budget, Percent business_trip_bonus)
    : budget(budget), business_trip_bonus(business_trip_bonus) {}


void Travel::plan_trip(Account &account)
{
    account -= budget;
    if (account.money < 0) exit(1);
}


void Travel::go_on_trip(Account &account)
{
    RUB_kopecks bonus = budget * business_trip_bonus / 100.0;
    account += bonus;
}


struct MortgageLoan {
    RUB_kopecks mortgage_amount;
    Percent interest_rate;
    Month remaining_months;

    MortgageLoan(RUB_kopecks mortgage_amount, Percent interest_rate, Month remaining_months);

    void pay_mortgage(Account &account, RUB_kopecks payment);
    void accrue_interest();
};

MortgageLoan::MortgageLoan(RUB_kopecks mortgage_amount, Percent interest_rate, Month remaining_months)
    : mortgage_amount(mortgage_amount),
      interest_rate(interest_rate),
      remaining_months(remaining_months) {}


void MortgageLoan::pay_mortgage(Account &account, RUB_kopecks payment)
{
    if (mortgage_amount < payment) exit(1);
    mortgage_amount -= payment;
    account -= payment;
}


void MortgageLoan::accrue_interest()
{
    mortgage_amount *= 1.0 + interest_rate / 100.0;
}

struct Taxation {
    RUB_kopecks taxable_income;
    Percent tax_rate;

    Taxation(RUB_kopecks taxable_income, Percent tax_rate);

    RUB_kopecks calculate_tax();
};


Taxation::Taxation(RUB_kopecks taxable_income, Percent tax_rate)
    : taxable_income(taxable_income), tax_rate(tax_rate) {}


RUB_kopecks Taxation::calculate_tax()
{
    return taxable_income * tax_rate / 100.0;
}


struct Person {
    Account sberbank_account;
    Deposit sberbank_deposit;
    Month age;
    Percent health;
    Car car;
    Flat flat;
    BankLoan bank_loan;
    Animal pet;
    Job job;
    Insurance health_insurance;
    House house;
    Investment investment;
    Travel travel;
    MortgageLoan mortgage_loan;
    Taxation taxation;

    Person(Account sberbank_account,
           Deposit sberbank_deposit,
           Month age,
           Car car,
           Flat flat,
           BankLoan bank_loan,
           Animal pet,
           Job job,
           Insurance health_insurance,
           House house,
           Investment investment,
           Travel travel,
           MortgageLoan mortgage_loan,
           Taxation taxation);

    void get_monthly_salary(RUB_kopecks payment);
    void eat_food(Food food);
    void pay_for_flat(RUB_kopecks payment);
    void pay_for_loan(RUB_kopecks payment);
    void feed_pet(Percent health_bonus);
    void heal_pet(Percent health_bonus);
    void perform_job();
    void pay_for_insurance();
    void maintain_house();
    void grow_investment();
    void plan_trip();
    void go_on_trip();
    void pay_mortgage();
    void pay_tax();
};


Person::Person(Account sberbank_account,
               Deposit sberbank_deposit,
               Month age,
               Car car,
               Flat flat,
               BankLoan bank_loan,
               Animal pet,
               Job job,
               Insurance health_insurance,
               House house,
               Investment investment,
               Travel travel,
               MortgageLoan mortgage_loan,
               Taxation taxation)
  : sberbank_account(sberbank_account),
    sberbank_deposit(sberbank_deposit),
    age(age),
    car(car),
    flat(flat),
    bank_loan(bank_loan),
    pet(pet),
    job(job),
    health_insurance(health_insurance),
    house(house),
    investment(investment),
    travel(travel),
    mortgage_loan(mortgage_loan),
    taxation(taxation) {}


void Person::get_monthly_salary(RUB_kopecks payment)
{
    Percent tax_rate = 0.0;
    if (payment * 12 >= 50'000'000'00)
        tax_rate = 22.0;
    else if (payment * 12 >= 20'000'000'00)
        tax_rate = 20.0;
    else if (payment * 12 >= 5'000'000'00)
        tax_rate = 18.0;
    else if (payment * 12 >= 2'400'000'00)
        tax_rate = 15.0;
    else
        tax_rate = 13.0;

    RUB_kopecks tax = taxation.calculate_tax();
    sberbank_account += payment - tax;
}


void Person::eat_food(Food food)
{
    Percent health_bonus = 0.0;
    switch (food) {
        case Apple: health_bonus = 5.0; break;
        case Steak: health_bonus = 4.0; break;
        case Cookie: health_bonus = 0.5; break;
        case Ramen: health_bonus = -5.75; break;
        case Potato: health_bonus = 2.1; break;
        case Salad: health_bonus = 10.0; break;
        case Spaghetti: health_bonus = 1.25; break;
    }

    health += health_bonus;
    if (health <= 0.0) exit(1);
}


void Person::pay_for_flat(RUB_kopecks payment)
{
    flat.pay_mortgage(sberbank_account, payment);
}


void Person::pay_for_loan(RUB_kopecks payment)
{
    bank_loan.repay(sberbank_account, payment);
}


void Person::feed_pet(Percent health_bonus)
{
    pet.feed(health_bonus);
}


void Person::heal_pet(Percent health_bonus)
{
    pet.heal(health_bonus);
}


void Person::perform_job()
{
    job.get_bonus(sberbank_account);
}


void Person::pay_for_insurance()
{
    health_insurance.pay_for_insurance(sberbank_account);
}


void Person::maintain_house()
{
    house.maintain(sberbank_account);
}


void Person::grow_investment()
{
    investment.grow(sberbank_account);
}


void Person::plan_trip()
{
    travel.plan_trip(sberbank_account);
}


void Person::go_on_trip()
{
    travel.go_on_trip(sberbank_account);
}


void Person::pay_mortgage()
{
    mortgage_loan.pay_mortgage(sberbank_account, 10'000'00);
}


void Person::pay_tax()
{
    RUB_kopecks tax = taxation.calculate_tax();
    sberbank_account -= tax;
    if (sberbank_account.money < 0) exit(1);
}


int main() {
    Person alice {
        Account(100'000'00),
        Deposit(200'000'00, 20.12),
        27 * 12 + 3,
        Car(),
        Flat(3'500'000'00, 65.5, 12.78),
        BankLoan(500'000'00, 10.0, 240),
        Animal("Dog", 80.0, 1),
        Job("Software Engineer", 150'000'00, 90.0),
        Insurance(5'000'00, 50.0),
        House(2'000'000'00, 20'000'00, 80.0),
        Investment(100'000'00, 15.0),
        Travel(50'000'00, 15.0),
        MortgageLoan(1'500'000'00, 5.0, 240),
        Taxation(100'000'00, 20.0)
    };

    while (alice.age < 70 * 12) {
        alice.get_monthly_salary(40'000'00);
        alice.sberbank_deposit.accrue_interest();

        alice.eat_food(Steak);
        alice.eat_food(Apple);

        alice.car.drive(78 * alice.age / 50);

        alice.pay_for_flat(1'200'00 + 340'00 * (alice.age % 12));
        alice.flat.pay_mortgage(alice.sberbank_account, 18'900'00);

        alice.pay_for_loan(10'000'00);
        alice.feed_pet(5.0);
        alice.heal_pet(2.0);
        alice.perform_job();
        alice.pay_for_insurance();

        alice.maintain_house();
        alice.grow_investment();

        alice.plan_trip();
        alice.go_on_trip();

        alice.pay_mortgage();
        alice.pay_tax();

        ++alice.age;
    }

    return 0;
}
