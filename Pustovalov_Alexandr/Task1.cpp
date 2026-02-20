#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <vector>

using Percent = float;

using RUB = long long int;
using USD = long long int;
using BTC = double;

const std::vector<double> BTC_RATES = {
    65000.0, 58000.0, 45000.0, 30000.0, 35000.0, 50000.0, 69000.0, 80000.0,
    75000.0, 60000.0, 40000.0, 20000.0, 25000.0, 40000.0, 90000.0, 120000.0,
    100000.0, 85000.0, 70000.0, 150000.0
};

struct Economy {
    Percent inflation;
    double rate_usd_rub;
    int avg_salary;

    bool crisis;
};

struct Car {
    RUB value;
    RUB gas;
    RUB yearly_tax;
};

struct Crypto {
    BTC balance;
    double exchange_rate_usd;
};

struct Loan {
    RUB body_debt;
    RUB monthly_payment;
    Percent interest_rate;
    bool is_active;
};

struct Bank {
    RUB account_rub;
    USD account_usd;

    Loan mortgage;
    Loan consumer_credit;
};

struct Housing {
    RUB value;
    RUB rent;
    RUB monthly_utilities;
};

struct Health {
    short happines;
    short physical_health;
    short age;
    short max_age;
    short stress;
    bool is_alive;
};

struct Family
{
    bool has_partner;
    bool has_parents;
    short children_amount;
};

struct Person {
    Bank vtb;
    Crypto crypto_account;

    Car car;
    Housing home;

    RUB salary;
    RUB monthly_food_cost;
    RUB monthly_lifestyle_cost;

    Health health;
    Family family;

};

struct Economy russia;
struct Person alice;
struct Person bogdan;

int year = 2026;
int month = 2;
int simulation_month_counter = 0;

void init()
{
    srand(time(NULL));
    // Global
    russia.rate_usd_rub = 76.75;
    russia.inflation = 5.59;
    russia.avg_salary = 96'772;
    russia.crisis = false;

    // Alice
    alice.salary = 200'000;
    alice.vtb.account_rub = 150'000;
    alice.vtb.account_usd = 0;
    alice.vtb.consumer_credit.is_active = false;
    alice.vtb.mortgage.is_active = true;
    alice.vtb.mortgage.body_debt = 8'000'000;
    alice.vtb.mortgage.monthly_payment = 90'000;
    alice.vtb.mortgage.interest_rate = 0.08;

    alice.crypto_account.balance = 0.0;
    alice.crypto_account.exchange_rate_usd = BTC_RATES[0];

    alice.car.value = 2'500'000;
    alice.car.gas = 12'000;

    alice.home.value = 15'000'000;
    alice.home.rent = 0;
    alice.home.monthly_utilities = 4'000;

    alice.monthly_food_cost = 25'000;
    alice.monthly_lifestyle_cost = 30'000;

    alice.health = { 85, 90, 20, 80, 10, true };
    alice.family = { false, true, 0 };

    // Bogdan
    bogdan.salary = 300'000;
    bogdan.vtb.account_rub = 50'000;
    bogdan.vtb.account_usd = 10'000;
    bogdan.vtb.consumer_credit.is_active = false;
    bogdan.vtb.mortgage.is_active = true;

    bogdan.crypto_account.balance = 1.5;
    bogdan.crypto_account.exchange_rate_usd = BTC_RATES[0];

    bogdan.car.value = 0;
    bogdan.car.gas = 0;

    bogdan.home.value = 0;
    bogdan.home.rent = 50'000;
    bogdan.home.monthly_utilities = 5'000;

    bogdan.monthly_food_cost = 60'000; //healthy food
    bogdan.monthly_lifestyle_cost = 20'000;

    bogdan.health = { 60, 95, 20, 80, 20, true };
    bogdan.family = { false, true, 0 };
}

double get_random(double min, double max) {
    return min + (double)(rand()) / ((double)(RAND_MAX / (max - min)));
}

void update_crypto_rates() {
    int index = simulation_month_counter % BTC_RATES.size();
    double current_rate = BTC_RATES[index];
    double noise = get_random(-2000.0, 2000.0);

    alice.crypto_account.exchange_rate_usd = current_rate + noise;
    bogdan.crypto_account.exchange_rate_usd = current_rate + noise;
}

void alice_expenses(const int month, const int year, const Economy rus_economy)
{
    if (month == 12) alice.vtb.account_rub -= 2000;  // christmas party
    RUB children_cost = alice.family.children_amount * 30'000;
    alice.vtb.account_rub -= (alice.monthly_food_cost + alice.monthly_lifestyle_cost + alice.home.monthly_utilities + children_cost);
}

void do_inflation() {
    alice.monthly_food_cost += alice.monthly_food_cost * (russia.inflation / 100.);
    alice.monthly_lifestyle_cost *= (1.0 + russia.inflation / 100.0);
    alice.home.monthly_utilities *= (1.0 + russia.inflation / 100.0);

    bogdan.monthly_food_cost += bogdan.monthly_food_cost * (russia.inflation / 100.);
    bogdan.monthly_lifestyle_cost *= (1.0 + russia.inflation / 100.0);
    bogdan.home.monthly_utilities *= (1.0 + russia.inflation / 100.0);
}

void alice_salary(const int month, const int year)
{
    if (month == 3) {
        alice.salary *= 1.05; //indexation
    }

    if (month == 2 && year == 2026) {
        alice.vtb.account_rub += 5000;  // bonus
    }

    alice.vtb.account_rub += alice.salary;
}

void bogdan_salary(const int month, const int year)
{
    if (get_random(0, 100) < 15) {
        // Job change
        double raise = get_random(1.10, 1.30);
        bogdan.salary = (RUB)(bogdan.salary * raise);

        // Job change stress
        bogdan.health.stress += (short)get_random(10, 25);
        if (bogdan.health.stress > 100) bogdan.health.stress = 100;
    }

    bogdan.vtb.account_rub += bogdan.salary;
}

void bogdan_life_prolongation()
{
    bogdan.vtb.account_usd -= 100'000;
    bogdan.health.max_age += 3;
}

void bogdan_expenses(const int month, const int year)
{
    if (month == 12) bogdan.vtb.account_rub -= 2000;
    RUB children_cost = bogdan.family.children_amount * 40'000;
    bogdan.vtb.account_rub -= (bogdan.monthly_food_cost + bogdan.monthly_lifestyle_cost + bogdan.home.monthly_utilities + children_cost + bogdan.home.rent);

    if (bogdan.vtb.account_rub > 100'000) {
        double investment_rub = 50'000.0;
        bogdan.vtb.account_rub -= (RUB)investment_rub;
        double investment_usd = investment_rub / russia.rate_usd_rub;
        bogdan.crypto_account.balance += investment_usd / bogdan.crypto_account.exchange_rate_usd;
    }
}

void print_results()
{
    printf("Simulation ended in year %d. Alice died in age of %d. Bogdan died in age of %d\n", year, alice.health.max_age, bogdan.health.max_age);
    printf("Alice Salary at the end of her life was %lld\nMeanwile Bogdan salary was %lld\n", alice.salary, bogdan.salary);
    int capital_bogdan = bogdan.car.value + bogdan.crypto_account.balance * bogdan.crypto_account.exchange_rate_usd * russia.rate_usd_rub + bogdan.home.value +
        bogdan.vtb.account_rub + bogdan.vtb.account_usd * russia.rate_usd_rub;
    int capital_alice = alice.car.value + alice.crypto_account.balance * alice.crypto_account.exchange_rate_usd * russia.rate_usd_rub + alice.home.value +
        alice.vtb.account_rub + alice.vtb.account_usd * russia.rate_usd_rub;
    printf("Alice finished with great capital of %d\nAnd Bogdan's capital wasn't small too: %d\n", capital_alice, capital_bogdan);
    printf("Alice had %d children\nBogdan had %d children\n", alice.family.children_amount, bogdan.family.children_amount);
    printf("But who was really happy in the end of his life Alice: %d or Bogdan: %d?\n", alice.health.happines, bogdan.health.happines);
}


void alice_car(const int month)
{
    alice.vtb.account_rub -= alice.car.gas;
    if (month == 2) alice.vtb.account_rub -= alice.car.yearly_tax;
}

void world_events()
{
    russia.crisis = (get_random(1, 200) == 100);
    if (russia.crisis) {
        russia.inflation += 5.0;
        russia.rate_usd_rub += 20.0;
        printf("CRISIS HIT in %d!\n", year);
    }
    else {
        // Normalisation
        if (russia.inflation > 5.59) russia.inflation -= 0.1;
    }
}

void random_events(Person& p)
{
    if (p.family.has_parents && get_random(0, 100) < 5) {
        RUB help_amount = 50'000;
        p.vtb.account_rub -= help_amount;
    }
    if (get_random(0, 1000) < 1) {
        RUB inheritance = (RUB)get_random(1'000'000, 5'000'000);
        p.vtb.account_rub += inheritance;
        p.family.has_parents = false; //No parents :(
    }
}

void alice_mortgage() {
    double interest_part = alice.vtb.mortgage.body_debt * (alice.vtb.mortgage.interest_rate / 1200.0);
    double debt_part = alice.vtb.mortgage.monthly_payment - interest_part;
    alice.vtb.account_rub -= alice.vtb.mortgage.monthly_payment;
    alice.vtb.mortgage.body_debt -= debt_part;

    if (alice.vtb.mortgage.body_debt < 0) {
        alice.vtb.mortgage.body_debt = 0;
        alice.vtb.mortgage.is_active = false;
        printf("Alice paid off mortgage!\n");
    }
}

bool try_find_partner(const short age, const int salary) {
    double p = (salary / russia.avg_salary - 1.0) * 10.0;
    short salary_bonus = (p < 0) ? 0 : (p > 6 ? 6 : p);
    short age_penalty = age - 20;
    return get_random(1, 100) + salary_bonus - age_penalty > 95;
}

void check_family_expansion(Person& p, int year) {
    if (p.family.has_partner && p.health.age > 25 && p.health.age < 45) {
        int chance = 99;
        if (p.family.children_amount == 0) chance = 98;

        if (get_random(1, 100) > chance) {
            p.family.children_amount++;
            printf("New child born for someone at age %d!\n", p.health.age);
        }
    }
}

void simulation()
{
    while (alice.health.is_alive || bogdan.health.is_alive) {
        // World
        world_events();
        update_crypto_rates();

        // Alice
        if (alice.health.is_alive) {
            alice_salary(month, year);
            alice_car(month);
            if (alice.vtb.mortgage.is_active) alice_mortgage();
            alice_expenses(month, year, russia);
            random_events(alice);
            if (!alice.family.has_partner and alice.health.stress < 50) {
                alice.family.has_partner = try_find_partner(alice.health.age, alice.salary);
                if (alice.family.has_partner) printf("Alice found a partner at %d!\n", alice.health.age);
            }
            check_family_expansion(alice, year);
        }

        //Bogdan
        if (bogdan.health.is_alive) {
            bogdan_salary(month, year);
            bogdan_expenses(month, year);
            random_events(bogdan);
            if (!bogdan.family.has_partner and bogdan.health.stress < 50) {
                bogdan.family.has_partner = try_find_partner(bogdan.health.age, bogdan.salary);
                if (bogdan.family.has_partner) printf("Bogdan found a partner at %d!\n", bogdan.health.age);
            }
            check_family_expansion(bogdan, year);
        }

        ++month;
        ++simulation_month_counter;
        if (month == 13) {
            ++year;
            if (alice.health.is_alive)  ++alice.health.age;
            if (bogdan.health.is_alive) ++bogdan.health.age;
            bogdan_life_prolongation();
            do_inflation();
            russia.avg_salary *= (russia.inflation / 100.) + 1;
            month = 1;

            //       if (alice.family.has_partner && (25 < alice.health.age && alice.health.age  < 50)) alice.family.children_amount += (int)(get_random(1,100)>98);
            //       if (bogdan.family.has_partner && (25 < bogdan.health.age && bogdan.health.age < 50)) bogdan.family.children_amount += (int)(get_random(1, 100) > 98);

            if (alice.health.age == alice.health.max_age) alice.health.is_alive = false;
            if (bogdan.health.age == bogdan.health.max_age) bogdan.health.is_alive = false;
        }
    }
}


int main()
{
    init();
    simulation();
    print_results();
}