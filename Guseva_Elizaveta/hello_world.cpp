#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

using Percent = float;
using RUB = long long int;
using USD = long long int;

struct Car
{
    RUB value;
    RUB gas;
    RUB maintenance;
    RUB insurance;
    RUB tax;
    RUB credit;
    RUB credit_remaining;
    RUB credit_monthly;
    int credit_months_left;
    bool has_credit;
};

struct RealEstate
{
    RUB value;
    RUB mortgage;
    RUB mortgage_remaining;
    RUB mortgage_monthly;
    RUB utilities;
    RUB repair;
    RUB tax;
    int mortgage_months_left;
    bool has_mortgage;
    bool is_rental;
    RUB rental_income;
};

struct Bank
{
    RUB account_rub;
    USD account_usd;
    USD investment_portfolio;
    RUB deposit;
    float deposit_rate;
    RUB credit_card_debt;
    RUB credit_card_limit;
    RUB credit_card_interest;
    float rate_usd_rub;
    RUB savings;
};

struct Family
{
    bool has_child;
    int child_age;
    RUB child_expenses;
    RUB child_education;
    bool has_pet_cat;
    bool has_pet_dog;
    RUB pet_expenses;
};

struct Person
{
    Bank vtb;
    RUB food;
    RUB salary_rub;
    USD salary_usd;
    Car car;
    RealEstate home;
    RUB lunch_cost;
    float health_problem_threshold;
    RUB health;
    RUB health_insurance;
    float luck;
    RUB education;
    RUB education_cost;
    RUB entertainment;
    RUB sport;
    RUB clothes;
    RUB gadgets;
    RUB gifts;
    RUB charity;
    RUB travel;
    RUB travel_savings;
    RUB freelance_income;
    RUB passive_income;
    RUB stock_dividends;
    RUB business_income;
    RUB tax_rub;
    RUB unexpected_expense;
    RUB unexpected_income;
    RUB fines;
    RUB bonuses;
    RUB inflation_rate;
    Family family;
    RUB monthly_budget;
    RUB monthly_savings_goal;
    RUB subscription_services;
    RUB communication;
    RUB transport;
    RUB personal_care;
};

struct Statistics
{
    RUB total_income;
    RUB total_expenses;
    RUB total_savings;
    RUB total_investments;
    RUB total_taxes_paid;
    RUB total_fines_paid;
    RUB total_charity_donated;
    RUB total_travel_expenses;
    RUB total_education_expenses;
    RUB total_health_expenses;
    RUB total_entertainment_expenses;
    RUB total_clothing_expenses;
    RUB total_gadget_expenses;
    RUB total_gift_expenses;
    RUB total_pet_expenses;
    RUB total_child_expenses;
    RUB total_car_expenses;
    RUB total_home_expenses;
    RUB monthly_savings_rate;
    RUB financial_independence_score;
    int retirement_age_estimate;
};

struct Loan
{
    RUB amount;
    RUB monthly_payment;
    RUB interest_rate;
    int months_left;
    bool is_active;
    char purpose[50];
};

struct Investment
{
    RUB stocks;
    RUB bonds;
    RUB crypto;
    RUB real_estate_fund;
    RUB gold;
    RUB total_value;
    float daily_return;
};

struct HealthMetrics
{
    RUB stress_level;
    RUB sleep_quality;
    RUB exercise_frequency;
    RUB social_activity;
    RUB happiness_index;
};

struct Person alice;
struct Person bob;

struct Statistics alice_stats;
struct Statistics bob_stats;
struct Loan alice_loans[5];
struct Loan bob_loans[5];
struct Investment alice_invest;
struct Investment bob_invest;
struct HealthMetrics alice_health;
struct HealthMetrics bob_health;

float random_float(float min, float max)
{
    return min + (max - min) * rand() / (RAND_MAX + 1.0);
}

int random_int(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// alice

void alice_reset_health_problem_threshold()
{
    alice.health_problem_threshold = 0;
}

void alice_reset_luck()
{
    alice.luck = 0;
}

void alice_count_health_problem_threshold()
{
    if (alice.vtb.account_rub < 0)
        alice.health_problem_threshold += 0.2; // stress

    if (alice.vtb.account_rub > 50000 || alice.vtb.account_usd > 1000)
        alice.health_problem_threshold -= 0.2; // financial stability => recovery

    if (alice.luck > 0.3)
        alice.health_problem_threshold -= 0.1; // minimize risk of health problems

    if (alice.family.has_child)
        alice.health_problem_threshold += 0.1; // children are stressful

    if (alice.sport > 0)
        alice.health_problem_threshold -= 0.15; // sport is healthy
}

void alice_food_cost(const int month, const int year)
{
    RUB monthly_food = alice.food;

    if (month == 12)
        monthly_food += 5000; // New Year celebration

    if (month == 1 && alice.family.has_child)
        monthly_food += 3000; // child presents

    if (month == 3 && alice.family.has_child)
        monthly_food += 2000; // child birthday

    monthly_food += alice.lunch_cost * 21; // 21 working days in a month

    float inflation = alice.inflation_rate / 100.0 / 12.0;
    monthly_food += monthly_food * inflation;

    if (alice.family.has_child)
        monthly_food += 15000; // child food

    monthly_food += monthly_food * (alice.inflation_rate / 100.0 / 12.0); // inflation
    alice.food = monthly_food;
    alice.vtb.account_rub -= monthly_food;
}

void alice_first_job(const int month, const int year)
{
    RUB salary = alice.salary_rub;

    if (month == 2 && year == 2026 && alice.luck > 0.3)
        alice.bonuses += 5000; // bonus

    if (month == 3 && alice.luck > 0.3 && year == 2026)
    {
        salary = salary * 1.5;                 // promotion
        alice.health_problem_threshold += 0.1; // responsibility stress
    }

    // Tax calculation
    RUB tax = salary * 0.13; // 13% income tax
    alice.tax_rub += tax;
    salary -= tax;

    alice.vtb.account_rub += salary;
    alice.health_problem_threshold += 0.2; // work stress
    alice.salary_rub = salary;
}

void alice_second_job(const int month, const int year)
{
    USD salary = alice.salary_usd;

    if (month == 5 && year == 2027 && alice.luck > 0.2)
        alice.vtb.account_usd += 3000; // bonus

    alice.vtb.account_usd += salary;
    alice.health_problem_threshold += 0.2; // work stress
}

void alice_car()
{
    if (alice.car.has_credit && alice.car.credit_months_left > 0)
    {
        alice.vtb.account_rub -= alice.car.credit_monthly;
        alice.car.credit_remaining -= alice.car.credit_monthly;
        alice.car.credit_months_left--;
    }

    if (alice.car.credit_months_left == 0)
        alice.car.has_credit = false;

    float gas_inflation = 10.8 / 100.0 / 12.0;
    float maintenance_inflation = 9.3 / 100.0 / 12.0;
    float insurance_inflation = 7 / 100.0 / 12.0;

    alice.vtb.account_rub -= alice.car.gas + (alice.car.gas * gas_inflation);
    alice.vtb.account_rub -= alice.car.maintenance + (alice.car.maintenance * maintenance_inflation);
    alice.vtb.account_rub -= alice.car.insurance + (alice.car.insurance * insurance_inflation);
    alice.vtb.account_rub -= alice.car.tax;

    alice.health_problem_threshold += 0.1; // unactive lifestyle
}

void alice_trip()
{
    RUB trip_cost = 50000;
    trip_cost += trip_cost * (alice.inflation_rate / 100.0 / 12.0); // inflation

    if (alice.travel_savings > trip_cost)
    {
        alice.vtb.account_rub -= trip_cost;
        alice.travel_savings -= trip_cost;
        alice.health_problem_threshold -= 0.3; // relaxation
    }
    else
    {
        alice.travel_savings += alice.salary_rub * 0.1; // save 10% of salary for trip
        alice.vtb.account_rub -= alice.salary_rub * 0.1;
    }
}

void alice_pets(const int month, const int year)
{
    if (alice.family.has_pet_cat || alice.family.has_pet_dog)
    {
        RUB pet_expenses = 0;

        if (month == 12 && year == 2027 && !alice.family.has_pet_cat)
        {
            alice.family.has_pet_cat = true; // get a cat
            pet_expenses += 1000;            // initial costs
        }

        if (month == 5 && year == 2030 && !alice.family.has_pet_dog)
        {
            alice.family.has_pet_dog = true; // get a dog
            pet_expenses += 2000;            // initial costs
        }

        if (alice.family.has_pet_cat)
        {
            if (month == 1)
                pet_expenses += 3000; // vet check
            pet_expenses += 2000;     // food
            pet_expenses += 1000;     // litter/toys
        }

        if (alice.family.has_pet_dog)
        {
            if (month == 1)
                pet_expenses += 3000; // vet check
            pet_expenses += 3000;     // food
            pet_expenses += 500;      // toys
        }

        alice.vtb.account_rub -= pet_expenses + (pet_expenses * (alice.inflation_rate / 100.0 / 12.0));
        alice.health_problem_threshold -= 0.5; // pet therapy
        alice.luck += 0.1;                     // pet brings luck
    }
}

void alice_rent(const int month, const int year)
{
    RUB rent_payment = alice.home.mortgage_monthly;

    if (alice.home.has_mortgage)
    {
        if (alice.vtb.account_rub < rent_payment)
        {
            alice.fines += 5000;                   // penalty
            alice.health_problem_threshold += 0.1; // stress
            alice.luck -= 0.2;                     // karma
        }
        else
        {
            alice.vtb.account_rub -= rent_payment;
            alice.home.mortgage_remaining -= rent_payment;
            alice.home.mortgage_months_left--;
            alice.health_problem_threshold -= 0.1; // stability

            if (alice.home.mortgage_months_left == 0)
                alice.home.has_mortgage = false;
        }
    }

    RUB utilities = alice.home.utilities;

    if (month == 1 || month == 2 || month == 12)
        utilities += 2000; // heating in winter
    else if (month == 6 || month == 7 || month == 8)
        utilities += 1500; // cooling in summer

    utilities += utilities * (alice.inflation_rate / 100.0 / 12.0);
    alice.vtb.account_rub -= utilities;

    if (alice.home.is_rental && alice.home.rental_income > 0)
    {
        alice.passive_income += alice.home.rental_income + (alice.home.rental_income * (alice.inflation_rate / 100.0 / 12.0));
    }
}

void alice_health_cost(const int month, const int year)
{
    RUB health_cost = alice.health * alice.health_problem_threshold;

    if (month == 10)
    {
        health_cost += 10000; // annual check-up
        alice.health_problem_threshold -= 0.5;
        alice.luck += 0.1;
    }

    if (year > 2035)
        health_cost += alice.health * (year - 2035) / 2; // older = more health expenses

    if (alice.health_insurance > 0)
    {
        health_cost -= health_cost * 0.7; // insurance covers 70%
        alice.vtb.account_rub -= alice.health_insurance;
    }

    float health_inflation = 5.8 / 100.0 / 12.0;
    health_cost += health_cost * health_inflation;

    alice.health = health_cost;
    alice.vtb.account_rub -= health_cost;
}

void alice_investment_portfolio()
{
    if (alice.vtb.account_rub > 50000)
    {
        RUB investment = 10000;
        alice.vtb.savings += investment;
        alice.vtb.account_rub -= investment;
    }

    if (alice.vtb.account_usd > 2000)
    {
        USD investment = 500;
        alice.vtb.investment_portfolio += investment;
        alice.vtb.account_usd -= investment;
    }

    float market_return = random_float(-0.05, 0.12) * alice.luck; // -5% to +12% monthly
    alice.vtb.investment_portfolio += alice.vtb.investment_portfolio * market_return;
    alice.stock_dividends += alice.vtb.investment_portfolio * 0.002; // 0.2% dividends
}

void alice_family_events(const int month, const int year)
{
    if (!alice.family.has_child && year == 2028 && month == 3 && alice.luck > 0.5)
    {
        alice.family.has_child = true; // baby born
        alice.family.child_age = 0;
        alice.vtb.account_rub -= 50000;        // baby expenses
        alice.luck += 0.3;                     // happiness
        alice.health_problem_threshold += 0.3; // stress of parenthood
    }

    if (alice.family.has_child)
    {
        if (month == 3)
        {
            alice.family.child_age++; // child birthday
        }

        RUB child_cost = 10000;
        if (alice.family.child_age < 3)
            child_cost = 0; // isn't old enough for activities
        else if (alice.family.child_age < 7 && alice.family.child_age >= 3)
            child_cost = 12000; // kindergarten
        else if (alice.family.child_age < 18 && alice.family.child_age >= 7)
            child_cost = 20000; // school, activities

        alice.family.child_expenses += child_cost + (child_cost * (alice.inflation_rate / 100.0 / 12.0));
        alice.vtb.account_rub -= child_cost;

        if (month == 1 && alice.family.child_age > 6)
        {
            RUB education_saving = alice.salary_rub * 0.05; // save 5% of salary for education
            alice.family.child_education += education_saving;
            alice.vtb.account_rub -= education_saving;
        }
    }
}

void alice_entertainment(const int month)
{
    RUB entertainment_cost = 5000;

    if (month == 12)
        entertainment_cost += 10000; // New Year parties
    if (month == 1)
        entertainment_cost += 5000; // post-New Year
    if (month == 2 || month == 8)
        entertainment_cost += 10000; // vacation

    alice.entertainment += entertainment_cost + (entertainment_cost * (alice.inflation_rate / 100.0 / 12.0));
    alice.vtb.account_rub -= entertainment_cost + (entertainment_cost * (alice.inflation_rate / 100.0 / 12.0));
    alice.health_problem_threshold -= 0.2; // relaxation
}

void alice_personal_care()
{
    RUB care_cost = 3000;
    alice.personal_care += care_cost + (care_cost * (alice.inflation_rate / 100.0 / 12.0));
    alice.vtb.account_rub -= care_cost + (care_cost * (alice.inflation_rate / 100.0 / 12.0));
}

void alice_clothes(const int month)
{
    RUB clothes_cost = 0;

    if (month == 3 || month == 9)
        clothes_cost = 10000; // seasonal clothes change
    else if (month == 12)
        clothes_cost = 8000; // New Year outfit
    else
        clothes_cost = 2000; // occasional purchases

    alice.clothes += clothes_cost + (clothes_cost * (alice.inflation_rate / 100.0 / 12.0));
    alice.vtb.account_rub -= clothes_cost + (clothes_cost * (alice.inflation_rate / 100.0 / 12.0));
}

void alice_education(const int month, const int year)
{
    if (month == 9 && year % 2 == 0)
    {
        RUB course_cost = 30000;                                            // courses every 2 years
        course_cost += course_cost * (alice.inflation_rate / 100.0 / 12.0); // inflation
        alice.education_cost += course_cost;
        alice.vtb.account_rub -= course_cost;
        alice.salary_rub += 50000; // education leads to higher salary
        alice.luck += 0.1;
    }
}

void alice_unexpected_events()
{
    float event_probability = random_float(0, 1);

    if (event_probability < 0.1) // 10% chance each month
    {
        int event_type = random_int(1, 5);

        switch (event_type)
        {
        case 1:
        {
            RUB repair_cost = random_int(10000, 50000);
            alice.unexpected_expense += repair_cost;
            alice.vtb.account_rub -= repair_cost;
            alice.health_problem_threshold += 0.2; // stress
            break;
        }
        case 2:
        {
            RUB found = random_int(1000, 10000);
            alice.unexpected_income += found;
            alice.vtb.account_rub += found;
            alice.luck += 0.1;
            break;
        }
        case 3:
        {
            RUB fine = random_int(500, 5000);
            alice.fines += fine;
            alice.vtb.account_rub -= fine;
            alice.health_problem_threshold += 0.1; // stress
            break;
        }
        case 4:
        {
            RUB gift = random_int(5000, 20000);
            alice.unexpected_income += gift;
            alice.vtb.account_rub += gift;
            alice.luck += 0.2;
            break;
        }
        case 5:
        {
            RUB extra_bonus = random_int(5000, 15000);
            alice.bonuses += extra_bonus;
            alice.vtb.account_rub += extra_bonus;
            alice.luck += 0.1;
            break;
        }
        }
    }
}

void alice_subscriptions()
{
    RUB subscriptions = 2000; // internet, streaming, etc.
    alice.subscription_services += subscriptions + (subscriptions * (alice.inflation_rate / 100.0 / 12.0));
    alice.vtb.account_rub -= subscriptions + (subscriptions * (alice.inflation_rate / 100.0 / 12.0));
}

void alice_communication()
{
    RUB comm_cost = 1500; // phone, mobile internet
    alice.communication += comm_cost + (comm_cost * (alice.inflation_rate / 100.0 / 12.0));
    alice.vtb.account_rub -= comm_cost + (comm_cost * (alice.inflation_rate / 100.0 / 12.0));
}

void alice_transport()
{
    RUB transport_cost = 3000; // public transport, taxi
    alice.transport += transport_cost + (transport_cost * (alice.inflation_rate / 100.0 / 12.0));
    alice.vtb.account_rub -= transport_cost + (transport_cost * (alice.inflation_rate / 100.0 / 12.0));
}

void alice_charity(const int month)
{
    if (alice.vtb.account_rub > 50000 && month == 12)
    {
        RUB donation = 5000;
        alice.charity += donation;
        alice.vtb.account_rub -= donation;
        alice.luck += 0.1; // good karma
    }
}

void alice_sport()
{
    RUB sport_cost = 3000; // gym membership
    alice.sport += sport_cost + (sport_cost * (alice.inflation_rate / 100.0 / 12.0));
    alice.vtb.account_rub -= sport_cost + (sport_cost * (alice.inflation_rate / 100.0 / 12.0));
    alice.health_problem_threshold -= 0.3;
}

void alice_freelance(const int month)
{
    if (month % 3 == 0 && alice.luck > 0.2) // freelance gig every 3 months
    {
        RUB freelance_earning = random_int(10000, 30000);
        alice.freelance_income += freelance_earning;
        alice.vtb.account_rub += freelance_earning;
    }
}

void alice_gifts(const int month)
{
    RUB gift_cost = 0;

    if (month == 3 && alice.family.has_child)
        gift_cost = 5000; // child birthday
    if (month == 12)
        gift_cost = 10000; // New Year gifts
    if (month == 2)
        gift_cost = 3000; // Valentine's day
    if (month == 8)
        gift_cost = 2000; // friends birthdays

    if (gift_cost > 0)
    {
        alice.gifts += gift_cost + (gift_cost * (alice.inflation_rate / 100.0 / 12.0));
        alice.vtb.account_rub -= gift_cost + (gift_cost * (alice.inflation_rate / 100.0 / 12.0));
    }
}

void alice_gadgets(const int month, const int year)
{
    if (month == 11 && year % 3 == 0) // new phone every 3 years
    {
        RUB gadget_cost = random_int(15000, 300000);
        alice.gadgets += gadget_cost;
        alice.vtb.account_rub -= gadget_cost;
    }
}

void alice_monthly_budget_check()
{
    RUB total_expenses = alice.food + alice.home.mortgage_monthly + alice.home.utilities +
                         alice.entertainment + alice.clothes + alice.transport +
                         alice.communication + alice.subscription_services + alice.sport +
                         alice.personal_care + alice.car.gas + alice.car.maintenance;

    alice.monthly_budget = total_expenses;

    if (total_expenses > alice.salary_rub * 0.8)
    {
        alice.health_problem_threshold += 0.1; // stress of spending too much
    }

    if (alice.vtb.account_rub > alice.monthly_savings_goal * 12)
    {
        alice.luck += 0.2;
    }
}

void alice_use_airbag()
{
    if (alice.vtb.account_rub >= 0)
        return;

    if (alice.vtb.savings > 0)
    {
        alice.vtb.account_rub += -alice.vtb.account_rub;
        alice.vtb.savings -= llabs(alice.vtb.account_rub); // get some savings to cover negative RUB
    }

    if (alice.vtb.account_usd > 0)
    {
        alice.vtb.account_rub += (-alice.vtb.account_rub / alice.vtb.rate_usd_rub); // convert some USD to RUB to cover negative RUB
        alice.vtb.account_usd -= (-alice.vtb.account_rub / alice.vtb.rate_usd_rub);
    }
}

void alice_update_investments()
{
    alice_invest.stocks = alice.vtb.investment_portfolio * 0.5;
    alice_invest.bonds = alice.vtb.investment_portfolio * 0.3;
    alice_invest.crypto = alice.vtb.investment_portfolio * 0.1;
    alice_invest.real_estate_fund = alice.vtb.investment_portfolio * 0.05;
    alice_invest.gold = alice.vtb.investment_portfolio * 0.05;
    alice_invest.total_value = alice.vtb.investment_portfolio;
    alice_invest.daily_return = random_float(-0.03, 0.05);
}

void alice_update_health_metrics()
{
    alice_health.stress_level = alice.health_problem_threshold * 100;
    alice_health.sleep_quality = 70 - alice.health_problem_threshold * 20;
    alice_health.exercise_frequency = (alice.sport > 0) ? 3 : 0;
    alice_health.social_activity = 50 + alice.luck * 30;
    alice_health.happiness_index = 60 + alice.luck * 30 - alice.health_problem_threshold * 20;

    if (alice_health.happiness_index < 0)
        alice_health.happiness_index = 0;
    if (alice_health.happiness_index > 100)
        alice_health.happiness_index = 100;
}

void alice_tax_declaration(const int year)
{
    if (year % 3 == 0)
    {
        RUB expected_tax = alice.salary_rub * 0.13 * 12;
        RUB paid_tax = alice.tax_rub;

        if (paid_tax < expected_tax * 0.9)
        {
            RUB penalty = (expected_tax - paid_tax) * 0.2;
            alice.fines += penalty;
            alice.vtb.account_rub -= penalty;
            alice.health_problem_threshold += 0.3;
            printf("⚠️ Налоговая проверка Алисы: штраф %lld руб.\n", penalty);
        }
        else if (paid_tax > expected_tax * 1.1)
        {
            RUB refund = paid_tax - expected_tax;
            alice.vtb.account_rub += refund;
            alice.luck += 0.2;
            printf("🎉 Возврат налогов Алисе: %lld руб.\n", refund);
        }
    }
}

void alice_manage_loans()
{
    for (int i = 0; i < 5; i++)
    {
        if (alice_loans[i].is_active && alice_loans[i].months_left > 0)
        {
            alice.vtb.account_rub -= alice_loans[i].monthly_payment;
            alice_loans[i].amount -= alice_loans[i].monthly_payment;
            alice_loans[i].months_left--;

            if (alice_loans[i].months_left == 0 || alice_loans[i].amount <= 0)
            {
                alice_loans[i].is_active = false;
                alice.luck += 0.05;
                printf("🎉 Алиса погасила кредит!\n");
            }
        }
    }
}

void alice_init()
{
    // bank
    alice.vtb.rate_usd_rub = random_float(70, 120);
    alice.vtb.account_rub = 50000;
    alice.vtb.account_usd = 10000;
    alice.vtb.investment_portfolio = 2000;
    alice.vtb.deposit = 100000;
    alice.vtb.deposit_rate = 8.5;
    alice.vtb.savings = 0;

    // person
    alice.lunch_cost = 5;
    alice.salary_rub = 580000;
    alice.salary_usd = 1500;
    alice.food = 1000;
    alice.health = 5000;
    alice.health_insurance = 3000;
    alice.education = 0;
    alice.entertainment = 0;
    alice.sport = 0;
    alice.clothes = 0;
    alice.gadgets = 0;
    alice.gifts = 0;
    alice.charity = 0;
    alice.travel = 0;
    alice.travel_savings = 20000;
    alice.freelance_income = 0;
    alice.passive_income = 0;
    alice.stock_dividends = 0;
    alice.business_income = 0;
    alice.tax_rub = 0;
    alice.unexpected_expense = 0;
    alice.unexpected_income = 0;
    alice.fines = 0;
    alice.bonuses = 0;
    alice.inflation_rate = 8.5;
    alice.monthly_savings_goal = 20000;

    // car
    alice.car.value = 2400000;
    alice.car.gas = 15000;
    alice.car.maintenance = 5000;
    alice.car.insurance = 8000;
    alice.car.tax = 3000;
    alice.car.has_credit = true;
    alice.car.credit = 1200000;
    alice.car.credit_remaining = 1200000;
    alice.car.credit_monthly = 40000;
    alice.car.credit_months_left = 30;

    // home
    alice.home.value = 8000000;
    alice.home.has_mortgage = true;
    alice.home.mortgage = 6000000;
    alice.home.mortgage_remaining = 6000000;
    alice.home.mortgage_monthly = 70000;
    alice.home.mortgage_months_left = 120;
    alice.home.utilities = 10000;
    alice.home.repair = 0;
    alice.home.tax = 5000;
    alice.home.is_rental = false;
    alice.home.rental_income = 0;

    // family
    alice.family.has_child = false;
    alice.family.child_age = 0;
    alice.family.child_expenses = 0;
    alice.family.child_education = 0;
    alice.family.has_pet_cat = false;
    alice.family.has_pet_dog = false;
    alice.family.pet_expenses = 0;
}

void alice_simulation()
{
    int year = 2026;
    int month = 2;
    int months_survived = 0;

    while (!(year == 2036 && month == 2)) // 10 years simulation
    {
        alice_reset_health_problem_threshold();
        alice_reset_luck();

        // main finances
        alice_food_cost(month, year);
        alice_first_job(month, year);
        alice_second_job(month, year);
        alice_car();
        alice_pets(month, year);
        alice_rent(month, year);
        alice_health_cost(month, year);

        // additional finances
        alice_entertainment(month);
        alice_personal_care();
        alice_clothes(month);
        alice_education(month, year);
        alice_transport();
        alice_communication();
        alice_subscriptions();
        alice_sport();
        alice_gifts(month);
        alice_gadgets(month, year);
        alice_charity(month);

        // income and events
        alice_freelance(month);
        alice_family_events(month, year);
        alice_trip();
        alice_investment_portfolio();
        alice_unexpected_events();
        alice_use_airbag();

        // check
        alice_monthly_budget_check();
        alice_count_health_problem_threshold();

        if (alice.health_problem_threshold > 1.0)
        {
            printf("\n💀 АЛИСА УМЕРЛА В %d ГОДУ 💀\n", year);
            return;
        }

        ++month;
        if (month == 12)
        {
            ++year;
            month = 1;
        }

        months_survived++;
    }

    printf("\n✅ Алиса успешно завершила симуляцию! Прожито месяцев: %d\n", months_survived);
}

void print_results()
{
    printf("\nФИНАНСОВЫЙ ОТЧЕТ АЛИСЫ\n");
    printf("Счет в рублях: %lld руб.\n", alice.vtb.account_rub);
    printf("Счет в долларах: %lld USD\n", alice.vtb.account_usd);
    printf("Инвестиционный портфель: %lld USD\n", alice.vtb.investment_portfolio);
    printf("Депозит: %lld руб.\n", alice.vtb.deposit);
    printf("Накопления: %lld руб.\n", alice.vtb.savings);

    printf("\nРАСХОДЫ АЛИСЫ\n");
    printf("Питание: %lld руб.\n", alice.food);
    printf("Здоровье: %lld руб.\n", alice.health);
    printf("Развлечения: %lld руб.\n", alice.entertainment);
    printf("Одежда: %lld руб.\n", alice.clothes);
    printf("Образование: %lld руб.\n", alice.education_cost);
    printf("Спорт: %lld руб.\n", alice.sport);
    printf("Транспорт: %lld руб.\n", alice.transport);
    printf("Связь: %lld руб.\n", alice.communication);
    printf("Подписки: %lld руб.\n", alice.subscription_services);
    printf("Подарки: %lld руб.\n", alice.gifts);
    printf("Благотворительность: %lld руб.\n", alice.charity);
    printf("Непредвиденные расходы: %lld руб.\n", alice.unexpected_expense);
    printf("Штрафы: %lld руб.\n", alice.fines);

    printf("\nДОХОДЫ АЛИСЫ\n");
    printf("Зарплата (руб): %lld руб.\n", alice.salary_rub);
    printf("Зарплата (USD): %lld USD\n", alice.salary_usd);
    printf("Фриланс: %lld руб.\n", alice.freelance_income);
    printf("Пассивный доход: %lld руб.\n", alice.passive_income);
    printf("Дивиденды: %lld USD\n", alice.stock_dividends);
    printf("Бонусы: %lld руб.\n", alice.bonuses);
    printf("Неожиданные доходы: %lld руб.\n", alice.unexpected_income);

    if (alice.family.has_child)
    {
        printf("\nСЕМЬЯ АЛИСЫ\n");
        printf("Ребенок: есть (возраст %d лет)\n", alice.family.child_age);
        printf("Расходы на ребенка: %lld руб.\n", alice.family.child_expenses);
        printf("Накопления на образование: %lld руб.\n", alice.family.child_education);
    }

    if (alice.family.has_pet_cat || alice.family.has_pet_dog)
    {
        printf("Домашние питомцы Алисы: ");
        if (alice.family.has_pet_cat)
            printf("кот ");
        if (alice.family.has_pet_dog)
            printf("собака");
        printf("\nРасходы на питомцев: %lld руб.\n", alice.family.pet_expenses);
    }

    printf("\nИтоговый капитал Алисы (руб): %lld\n", alice.vtb.account_rub + alice.vtb.savings + alice.vtb.deposit);
    printf("Итоговый капитал Алисы (USD): %lld\n", alice.vtb.account_usd + alice.vtb.investment_portfolio);

    if (alice.health_problem_threshold > 1.0)
        printf("СТАТУС АЛИСЫ: Умерла от проблем со здоровьем\n");
    else
        printf("СТАТУС АЛИСЫ: Жива и здорова\n");
}

void alice_print_detailed_report()
{
    printf("\n📊 ДЕТАЛЬНЫЙ ОТЧЕТ АЛИСЫ\n");
    printf("   ОБЩИЕ ПОКАЗАТЕЛИ:\n");
    printf("   Всего доходов: %lld руб.\n", alice_stats.total_income);
    printf("   Всего расходов: %lld руб.\n", alice_stats.total_expenses);
    printf("   Норма сбережений: %lld%%\n", alice_stats.monthly_savings_rate);
    printf("   Индекс финансовой независимости: %lld%%\n", alice_stats.financial_independence_score);

    printf("\n   СТРУКТУРА РАСХОДОВ:\n");
    printf("   Жилье: %lld руб.\n", alice_stats.total_home_expenses);
    printf("   Автомобиль: %lld руб.\n", alice_stats.total_car_expenses);
    printf("   Здоровье: %lld руб.\n", alice_stats.total_health_expenses);
    printf("   Образование: %lld руб.\n", alice_stats.total_education_expenses);
    printf("   Развлечения: %lld руб.\n", alice_stats.total_entertainment_expenses);
    printf("   Одежда: %lld руб.\n", alice_stats.total_clothing_expenses);
    printf("   Подарки: %lld руб.\n", alice_stats.total_gift_expenses);
    printf("   Благотворительность: %lld руб.\n", alice_stats.total_charity_donated);
    printf("   Путешествия: %lld руб.\n", alice_stats.total_travel_expenses);

    printf("\n   ЗДОРОВЬЕ АЛИСЫ:\n");
    printf("   Уровень стресса: %.0f%%\n", alice_health.stress_level);
    printf("   Качество сна: %.0f%%\n", alice_health.sleep_quality);
    printf("   Индекс счастья: %.0f%%\n", alice_health.happiness_index);
}

// bob

void bob_reset_health_problem_threshold()
{
    bob.health_problem_threshold = 0;
}

void bob_reset_luck()
{
    bob.luck = 0;
}

void bob_count_health_problem_threshold()
{
    if (bob.vtb.account_rub < 0)
        bob.health_problem_threshold += 0.25; // bob is more sensitive, than alice

    if (bob.vtb.account_rub > 30000 || bob.vtb.account_usd > 500)
        bob.health_problem_threshold -= 0.15;

    if (bob.luck > 0.3)
        bob.health_problem_threshold -= 0.1;

    if (bob.family.has_pet_cat)
        bob.health_problem_threshold -= 0.3; // cat = relax

    if (bob.sport > 0)
        bob.health_problem_threshold -= 0.2;
}

void bob_food_cost(const int month, const int year)
{
    RUB monthly_food = bob.food;

    if (month == 12)
        monthly_food += 3000; // New year

    monthly_food += bob.lunch_cost * 21; // 21 work days in a month

    float inflation = bob.inflation_rate / 100.0 / 12.0;
    monthly_food += monthly_food * inflation;

    if (bob.family.has_pet_cat)
        monthly_food += 2000; // food

    bob.food = monthly_food;
    bob.vtb.account_rub -= monthly_food;
}

void bob_first_job(const int month, const int year)
{
    RUB salary = bob.salary_rub;

    if (month == 2 && year == 2026 && bob.luck > 0.2)
        bob.bonuses += 3000; // bonus

    if (month == 6 && bob.luck > 0.3 && year == 2027)
    {
        salary = salary * 1.3; // promote
        bob.health_problem_threshold += 0.15;
    }

    RUB tax = salary * 0.13;
    bob.tax_rub += tax;
    salary -= tax;

    bob.vtb.account_rub += salary;
    bob.health_problem_threshold += 0.2;
    bob.salary_rub = salary;
}

void bob_car()
{
    if (bob.car.has_credit && bob.car.credit_months_left > 0)
    {
        bob.vtb.account_rub -= bob.car.credit_monthly;
        bob.car.credit_remaining -= bob.car.credit_monthly;
        bob.car.credit_months_left--;
    }

    if (bob.car.credit_months_left == 0)
        bob.car.has_credit = false;

    float gas_inflation = 10.8 / 100.0 / 12.0;
    bob.vtb.account_rub -= bob.car.gas + (bob.car.gas * gas_inflation);
    bob.vtb.account_rub -= bob.car.maintenance;
    bob.vtb.account_rub -= bob.car.insurance;
    bob.vtb.account_rub -= bob.car.tax;

    bob.health_problem_threshold += 0.1;
}

void bob_pets(const int month, const int year)
{
    if (bob.family.has_pet_cat)
    {
        RUB pet_expenses = 0;

        if (month == 1)
            pet_expenses += 2000; // vet check

        pet_expenses += 1500; // food
        pet_expenses += 500;  // toys/litter

        bob.vtb.account_rub -= pet_expenses;
        bob.family.pet_expenses += pet_expenses;
        bob.health_problem_threshold -= 0.3;
        bob.luck += 0.1;
    }
}

void bob_rent(const int month, const int year)
{
    RUB rent_payment = bob.home.mortgage_monthly;

    if (bob.vtb.account_rub < rent_payment)
    {
        bob.fines += 3000;
        bob.health_problem_threshold += 0.2;
        bob.luck -= 0.1;
    }
    else
    {
        bob.vtb.account_rub -= rent_payment;
        bob.health_problem_threshold -= 0.1;
    }

    RUB utilities = bob.home.utilities;

    if (month == 1 || month == 2 || month == 12)
        utilities += 1500;
    else if (month == 6 || month == 7 || month == 8)
        utilities += 1000;

    utilities += utilities * (bob.inflation_rate / 100.0 / 12.0);
    bob.vtb.account_rub -= utilities;
}

void bob_health_cost(const int month, const int year)
{
    RUB health_cost = bob.health * bob.health_problem_threshold;

    if (month == 10)
    {
        health_cost += 5000;
        bob.health_problem_threshold -= 0.3;
        bob.luck += 0.05;
    }

    if (year > 2035)
        health_cost += bob.health * (year - 2035) / 3;

    if (bob.health_insurance > 0)
    {
        health_cost -= health_cost * 0.6; // insurance = 60%
        bob.vtb.account_rub -= bob.health_insurance;
    }

    float health_inflation = 5.8 / 100.0 / 12.0;
    health_cost += health_cost * health_inflation;

    bob.health = health_cost;
    bob.vtb.account_rub -= health_cost;
}

void bob_entertainment(const int month)
{
    RUB entertainment_cost = 3000;

    if (month == 12)
        entertainment_cost += 5000;
    if (month == 1)
        entertainment_cost += 2000;
    if (month == 7) // summer vacation
        entertainment_cost += 15000;

    bob.entertainment += entertainment_cost;
    bob.vtb.account_rub -= entertainment_cost;
    bob.health_problem_threshold -= 0.15;
}

void bob_sport()
{
    RUB sport_cost = 1500;
    bob.sport += sport_cost;
    bob.vtb.account_rub -= sport_cost;
    bob.health_problem_threshold -= 0.2;
}

void bob_freelance(const int month)
{
    if (month % 2 == 0 && bob.luck > 0.1) // bob has freelance gigs more often, than alice
    {
        RUB freelance_earning = random_int(5000, 15000);
        bob.freelance_income += freelance_earning;
        bob.vtb.account_rub += freelance_earning;
    }
}

void bob_save_money(const int month)
{
    RUB savings = bob.salary_rub * 0.05; // bob saves money to buy a new car
    bob.vtb.savings += savings;
    bob.vtb.account_rub -= savings;
}

void bob_unexpected_events()
{
    float event_probability = random_float(0, 1);

    if (event_probability < 0.08) // 8% chance
    {
        int event_type = random_int(1, 4);

        switch (event_type)
        {
        case 1:
        {
            RUB repair_cost = random_int(5000, 25000);
            bob.unexpected_expense += repair_cost;
            bob.vtb.account_rub -= repair_cost;
            bob.health_problem_threshold += 0.15;
            break;
        }
        case 2:
        {
            RUB found = random_int(500, 5000);
            bob.unexpected_income += found;
            bob.vtb.account_rub += found;
            bob.luck += 0.1;
            break;
        }
        case 3:
        {
            RUB gift_from_parents = random_int(3000, 10000);
            bob.unexpected_income += gift_from_parents;
            bob.vtb.account_rub += gift_from_parents;
            bob.luck += 0.1;
            break;
        }
        case 4:
        {
            RUB cat_vet = random_int(1000, 5000);
            bob.unexpected_expense += cat_vet;
            bob.vtb.account_rub -= cat_vet;
            bob.health_problem_threshold += 0.1;
            break;
        }
        }
    }
}


void bob_use_airbag()
{
    if (bob.vtb.account_rub >= 0)
        return;

    if (bob.vtb.savings > 0)
    {
        bob.vtb.account_rub += -bob.vtb.account_rub;
        bob.vtb.savings -= llabs(bob.vtb.account_rub);
    }

    if (bob.vtb.account_usd > 0)
    {
        RUB needed = -bob.vtb.account_rub;
        USD usd_needed = needed / bob.vtb.rate_usd_rub;
        if (usd_needed <= bob.vtb.account_usd)
        {
            bob.vtb.account_rub += needed;
            bob.vtb.account_usd -= usd_needed;
        }
    }
}

void bob_monthly_budget_check()
{
    RUB total_expenses = bob.food + bob.home.mortgage_monthly + bob.home.utilities +
                         bob.entertainment + bob.clothes + bob.sport +
                         bob.car.gas + bob.car.maintenance;

    bob.monthly_budget = total_expenses;

    if (total_expenses > bob.salary_rub * 0.7) // bob is more thrifty
        bob.health_problem_threshold += 0.15;

    if (bob.vtb.savings > bob.monthly_savings_goal * 6)
        bob.luck += 0.1;
}

void bob_update_investments()
{
    bob_invest.stocks = bob.vtb.investment_portfolio * 0.6;
    bob_invest.bonds = bob.vtb.investment_portfolio * 0.25;
    bob_invest.crypto = bob.vtb.investment_portfolio * 0.05;
    bob_invest.real_estate_fund = bob.vtb.investment_portfolio * 0.05;
    bob_invest.gold = bob.vtb.investment_portfolio * 0.05;
    bob_invest.total_value = bob.vtb.investment_portfolio;
    bob_invest.daily_return = random_float(-0.02, 0.04);
}

void bob_update_health_metrics()
{
    bob_health.stress_level = bob.health_problem_threshold * 100;
    bob_health.sleep_quality = 75 - bob.health_problem_threshold * 25;
    bob_health.exercise_frequency = (bob.sport > 0) ? 2 : 1;
    bob_health.social_activity = 40 + bob.luck * 40;
    bob_health.happiness_index = 55 + bob.luck * 35 - bob.health_problem_threshold * 15;

    if (bob_health.happiness_index < 0)
        bob_health.happiness_index = 0;
    if (bob_health.happiness_index > 100)
        bob_health.happiness_index = 100;
}

void bob_tax_declaration(const int year)
{
    if (year % 3 == 0)
    {
        RUB expected_tax = bob.salary_rub * 0.13 * 12;
        RUB paid_tax = bob.tax_rub;

        if (paid_tax < expected_tax * 0.85)
        {
            RUB penalty = (expected_tax - paid_tax) * 0.15;
            bob.fines += penalty;
            bob.vtb.account_rub -= penalty;
            bob.health_problem_threshold += 0.2;
            printf("⚠️ Налоговая проверка Боба: штраф %lld руб.\n", penalty);
        }
    }
}

void bob_manage_loans()
{
    for (int i = 0; i < 5; i++)
    {
        if (bob_loans[i].is_active && bob_loans[i].months_left > 0)
        {
            bob.vtb.account_rub -= bob_loans[i].monthly_payment;
            bob_loans[i].amount -= bob_loans[i].monthly_payment;
            bob_loans[i].months_left--;

            if (bob_loans[i].months_left == 0 || bob_loans[i].amount <= 0)
            {
                bob_loans[i].is_active = false;
                bob.luck += 0.05;
                printf("🎉 Боб погасил кредит!\n");
            }
        }
    }
}

void bob_init()
{
    // bank
    bob.vtb.rate_usd_rub = random_float(70, 120);
    bob.vtb.account_rub = 30000;
    bob.vtb.account_usd = 5000;
    bob.vtb.investment_portfolio = 1000;
    bob.vtb.deposit = 50000;
    bob.vtb.deposit_rate = 7.5;
    bob.vtb.savings = 0;

    // person
    bob.lunch_cost = 8;
    bob.salary_rub = 450000;
    bob.salary_usd = 1000;
    bob.food = 1500;
    bob.health = 3000;
    bob.health_insurance = 2000;
    bob.education = 0;
    bob.entertainment = 0;
    bob.sport = 0;
    bob.clothes = 0;
    bob.gadgets = 0;
    bob.gifts = 0;
    bob.charity = 0;
    bob.travel = 0;
    bob.travel_savings = 10000;
    bob.freelance_income = 0;
    bob.passive_income = 0;
    bob.stock_dividends = 0;
    bob.business_income = 0;
    bob.tax_rub = 0;
    bob.unexpected_expense = 0;
    bob.unexpected_income = 0;
    bob.fines = 0;
    bob.bonuses = 0;
    bob.inflation_rate = 8.5;
    bob.monthly_savings_goal = 15000;

    // car
    bob.car.value = 1200000;
    bob.car.gas = 12000;
    bob.car.maintenance = 4000;
    bob.car.insurance = 6000;
    bob.car.tax = 2000;
    bob.car.has_credit = true;
    bob.car.credit = 600000;
    bob.car.credit_remaining = 600000;
    bob.car.credit_monthly = 25000;
    bob.car.credit_months_left = 24;

    // home
    bob.home.value = 0;
    bob.home.has_mortgage = false;
    bob.home.mortgage = 0;
    bob.home.mortgage_remaining = 0;
    bob.home.mortgage_monthly = 35000;
    bob.home.mortgage_months_left = 0;
    bob.home.utilities = 8000;
    bob.home.repair = 0;
    bob.home.tax = 0;
    bob.home.is_rental = false;
    bob.home.rental_income = 0;

    // family
    bob.family.has_child = false;
    bob.family.child_age = 0;
    bob.family.child_expenses = 0;
    bob.family.child_education = 0;
    bob.family.has_pet_cat = true;
    bob.family.has_pet_dog = false;
    bob.family.pet_expenses = 0;
}

void bob_simulation()
{
    int year = 2026;
    int month = 2;

    while (!(year == 2036 && month == 2))
    {
        bob_reset_health_problem_threshold();
        bob_reset_luck();

        // main finances
        bob_food_cost(month, year);
        bob_first_job(month, year);
        bob_car();
        bob_pets(month, year);
        bob_rent(month, year);
        bob_health_cost(month, year);
        bob_entertainment(month);
        bob_sport();
        bob_freelance(month);
        bob_save_money(month);
        bob_unexpected_events();
        bob_use_airbag();

        // check
        bob_monthly_budget_check();
        bob_count_health_problem_threshold();

        if (bob.health_problem_threshold > 1.0)
        {
            printf("\n💀 БОБ УМЕР В %d ГОДУ 💀\n", year);
            return;
        }

        ++month;
        if (month == 12)
        {
            ++year;
            month = 1;
        }
    }

    printf("\n✅ Боб успешно завершил симуляцию!\n");
}

void bob_print_results()
{
    printf("\nФИНАНСОВЫЙ ОТЧЕТ БОБА\n");
    printf("Счет в рублях: %lld руб.\n", bob.vtb.account_rub);
    printf("Счет в долларах: %lld USD\n", bob.vtb.account_usd);
    printf("Инвестиционный портфель: %lld USD\n", bob.vtb.investment_portfolio);
    printf("Депозит: %lld руб.\n", bob.vtb.deposit);
    printf("Накопления: %lld руб.\n", bob.vtb.savings);

    printf("\nРАСХОДЫ БОБА\n");
    printf("Питание: %lld руб.\n", bob.food);
    printf("Здоровье: %lld руб.\n", bob.health);
    printf("Развлечения: %lld руб.\n", bob.entertainment);
    printf("Спорт: %lld руб.\n", bob.sport);
    printf("Одежда: %lld руб.\n", bob.clothes);
    printf("Расходы на питомцев: %lld руб.\n", bob.family.pet_expenses);

    printf("\nДОХОДЫ БОБА\n");
    printf("Зарплата (руб): %lld руб.\n", bob.salary_rub);
    printf("Зарплата (USD): %lld USD\n", bob.salary_usd);
    printf("Фриланс: %lld руб.\n", bob.freelance_income);
    printf("Бонусы: %lld руб.\n", bob.bonuses);
    printf("Неожиданные доходы: %lld руб.\n", bob.unexpected_income);

    printf("\nИтоговый капитал Боба (руб): %lld\n", bob.vtb.account_rub + bob.vtb.savings + bob.vtb.deposit);
    printf("Итоговый капитал Боба (USD): %lld\n", bob.vtb.account_usd + bob.vtb.investment_portfolio);

    if (bob.family.has_pet_cat)
        printf("У Боба есть кот!\n");

    if (bob.health_problem_threshold > 1.0)
        printf("СТАТУС БОБА: Умер от проблем со здоровьем\n");
    else
        printf("СТАТУС БОБА: Жив и здоров\n");
}

void bob_print_detailed_report()
{
    printf("\n📊 ДЕТАЛЬНЫЙ ОТЧЕТ БОБА\n");
    printf("   ОБЩИЕ ПОКАЗАТЕЛИ:\n");
    printf("   Всего доходов: %lld руб.\n", bob_stats.total_income);
    printf("   Всего расходов: %lld руб.\n", bob_stats.total_expenses);
    printf("   Норма сбережений: %lld%%\n", bob_stats.monthly_savings_rate);

    printf("\n   СТРУКТУРА РАСХОДОВ:\n");
    printf("   Жилье: %lld руб.\n", bob_stats.total_home_expenses);
    printf("   Автомобиль: %lld руб.\n", bob_stats.total_car_expenses);
    printf("   Здоровье: %lld руб.\n", bob_stats.total_health_expenses);
    printf("   Развлечения: %lld руб.\n", bob_stats.total_entertainment_expenses);
    printf("   Питомцы: %lld руб.\n", bob_stats.total_pet_expenses);

    printf("\n   ЗДОРОВЬЕ БОБА:\n");
    printf("   Уровень стресса: %.0f%%\n", bob_health.stress_level);
    printf("   Качество сна: %.0f%%\n", bob_health.sleep_quality);
    printf("   Индекс счастья: %.0f%%\n", bob_health.happiness_index);
}

// statistics

void alice_init_statistics()
{
    alice_stats.total_income = 0;
    alice_stats.total_expenses = 0;
    alice_stats.total_savings = 0;
    alice_stats.total_investments = 0;
    alice_stats.total_taxes_paid = 0;
    alice_stats.total_fines_paid = 0;
    alice_stats.total_charity_donated = 0;
    alice_stats.total_travel_expenses = 0;
    alice_stats.total_education_expenses = 0;
    alice_stats.total_health_expenses = 0;
    alice_stats.total_entertainment_expenses = 0;
    alice_stats.total_clothing_expenses = 0;
    alice_stats.total_gadget_expenses = 0;
    alice_stats.total_gift_expenses = 0;
    alice_stats.total_pet_expenses = 0;
    alice_stats.total_child_expenses = 0;
    alice_stats.total_car_expenses = 0;
    alice_stats.total_home_expenses = 0;
    alice_stats.monthly_savings_rate = 0;
    alice_stats.financial_independence_score = 0;
    alice_stats.retirement_age_estimate = 65;
}

void alice_collect_statistics()
{
    alice_stats.total_income += alice.salary_rub + (alice.salary_usd * alice.vtb.rate_usd_rub) +
                                alice.freelance_income + alice.bonuses + alice.unexpected_income;

    alice_stats.total_expenses += alice.food + alice.health + alice.entertainment +
                                  alice.clothes + alice.education_cost + alice.sport +
                                  alice.transport + alice.communication + alice.subscription_services +
                                  alice.gifts + alice.charity + alice.unexpected_expense + alice.fines;

    alice_stats.total_savings = alice.vtb.savings;
    alice_stats.total_investments = alice.vtb.investment_portfolio * alice.vtb.rate_usd_rub + alice.vtb.deposit;
    alice_stats.total_taxes_paid = alice.tax_rub;
    alice_stats.total_fines_paid = alice.fines;
    alice_stats.total_charity_donated = alice.charity;
    alice_stats.total_travel_expenses = alice.travel;
    alice_stats.total_education_expenses = alice.education_cost;
    alice_stats.total_health_expenses = alice.health;
    alice_stats.total_entertainment_expenses = alice.entertainment;
    alice_stats.total_clothing_expenses = alice.clothes;
    alice_stats.total_gadget_expenses = alice.gadgets;
    alice_stats.total_gift_expenses = alice.gifts;
    alice_stats.total_pet_expenses = alice.family.pet_expenses;
    alice_stats.total_child_expenses = alice.family.child_expenses;
    alice_stats.total_car_expenses = alice.car.gas + alice.car.maintenance + alice.car.insurance +
                                     alice.car.tax + alice.car.credit_monthly;
    alice_stats.total_home_expenses = alice.home.mortgage_monthly + alice.home.utilities + alice.home.repair;

    if (alice_stats.total_income > 0)
    {
        alice_stats.monthly_savings_rate = (alice_stats.total_savings * 100) / alice_stats.total_income;
    }

    RUB annual_expenses = (alice_stats.total_expenses > 0) ? alice_stats.total_expenses / 1 : 0;
    if (annual_expenses > 0 && alice_stats.total_investments > 0)
    {
        alice_stats.financial_independence_score = (alice_stats.total_investments * 0.04 * 100) / annual_expenses;
    }
}

void bob_init_statistics()
{
    bob_stats.total_income = 0;
    bob_stats.total_expenses = 0;
    bob_stats.total_savings = 0;
    bob_stats.total_investments = 0;
    bob_stats.total_taxes_paid = 0;
    bob_stats.total_fines_paid = 0;
    bob_stats.total_charity_donated = 0;
    bob_stats.total_travel_expenses = 0;
    bob_stats.total_education_expenses = 0;
    bob_stats.total_health_expenses = 0;
    bob_stats.total_entertainment_expenses = 0;
    bob_stats.total_clothing_expenses = 0;
    bob_stats.total_gadget_expenses = 0;
    bob_stats.total_gift_expenses = 0;
    bob_stats.total_pet_expenses = 0;
    bob_stats.total_child_expenses = 0;
    bob_stats.total_car_expenses = 0;
    bob_stats.total_home_expenses = 0;
    bob_stats.monthly_savings_rate = 0;
    bob_stats.financial_independence_score = 0;
    bob_stats.retirement_age_estimate = 65;
}

void bob_collect_statistics()
{
    bob_stats.total_income += bob.salary_rub + (bob.salary_usd * bob.vtb.rate_usd_rub) +
                              bob.freelance_income + bob.bonuses + bob.unexpected_income;

    bob_stats.total_expenses += bob.food + bob.health + bob.entertainment + bob.clothes +
                                bob.sport + bob.unexpected_expense + bob.fines;

    bob_stats.total_savings = bob.vtb.savings;
    bob_stats.total_investments = bob.vtb.investment_portfolio * bob.vtb.rate_usd_rub + bob.vtb.deposit;
    bob_stats.total_taxes_paid = bob.tax_rub;
    bob_stats.total_fines_paid = bob.fines;
    bob_stats.total_pet_expenses = bob.family.pet_expenses;
    bob_stats.total_car_expenses = bob.car.gas + bob.car.maintenance + bob.car.insurance +
                                   bob.car.tax + bob.car.credit_monthly;
    bob_stats.total_home_expenses = bob.home.mortgage_monthly + bob.home.utilities;

    if (bob_stats.total_income > 0)
    {
        bob_stats.monthly_savings_rate = (bob_stats.total_savings * 100) / bob_stats.total_income;
    }
}

void compare_detailed_statistics()
{
    printf("\n🔍 СРАВНИТЕЛЬНЫЙ АНАЛИЗ\n");
    printf("   ПОКАЗАТЕЛЬ        | АЛИСА      | БОБ\n");
    printf("   ------------------|------------|------------\n");
    printf("   Норма сбережений  | %8lld%% | %8lld%%\n", alice_stats.monthly_savings_rate, bob_stats.monthly_savings_rate);
    printf("   Инвестиции        | %10lld | %10lld\n", alice_stats.total_investments, bob_stats.total_investments);
    printf("   Накопления        | %10lld | %10lld\n", alice_stats.total_savings, bob_stats.total_savings);
    printf("   Уровень стресса   | %9.0f%% | %9.0f%%\n", alice_health.stress_level, bob_health.stress_level);
    printf("   Индекс счастья    | %9.0f%% | %9.0f%%\n", alice_health.happiness_index, bob_health.happiness_index);
}

void alice_and_bob_meet(const int month, const int year)
{
    // persons meet
    if (year == 2027 && month == 6 && alice.luck > 0.3 && bob.luck > 0.3)
    {
        printf("\n❤️ АЛИСА И БОБ ВСТРЕТИЛИСЬ! ❤️\n");

        // exchange experience
        if (alice.salary_rub > bob.salary_rub)
        {
            bob.salary_rub += 5000; // alice lessons helps bob
            alice.luck += 0.1;      // karma
        }
        else
        {
            alice.salary_rub += 5000; // bob lessons helps alice
            bob.luck += 0.1;          // karma
        }

        // joint travel
        RUB trip_cost = 30000;
        if (alice.travel_savings > trip_cost / 2 && bob.vtb.savings > trip_cost / 2)
        {
            alice.travel_savings -= trip_cost / 2;
            bob.vtb.savings -= trip_cost / 2;
            alice.health_problem_threshold -= 0.2;
            bob.health_problem_threshold -= 0.2;
            alice.luck += 0.2;
            bob.luck += 0.2;
            printf("🍷 Алиса и Боб сходили в ресторан и отдохнули!\n");
        }
    }

    // financial support
    if (year > 2027)
    {
        RUB loan = 20000;
        if (alice.vtb.account_rub > 100000 && bob.vtb.account_rub < 0)
        {
            alice.vtb.account_rub -= loan;
            bob.vtb.account_rub += loan;
            alice.luck += 0.1; // karma
            printf("💰 Алиса одолжила Бобу %lld руб.\n", loan);
        }
        else if (bob.vtb.account_rub > 100000 && alice.vtb.account_rub < 0)
        {
            bob.vtb.account_rub -= loan;
            alice.vtb.account_rub += loan;
            bob.luck += 0.1; // karma
            printf("💰 Боб одолжил Алисе %lld руб.\n", loan);
        }
    }

    // joint buisness
    if (year > 2028 && alice.business_income > 0 && bob.freelance_income > 0)
    {
        if (random_float(0, 1) < 0.05)
        {
            RUB business_profit = random_int(20000, 100000);
            alice.business_income += business_profit / 2;
            bob.freelance_income += business_profit / 2;
            alice.vtb.account_rub += business_profit / 2;
            bob.vtb.account_rub += business_profit / 2;
            printf("🤝 Совместный проект принес %lld руб.\n", business_profit);
        }
    }

    // Marriage
    if (year == 2030 && month == 6 && alice.luck > 0.5 && bob.luck > 0.5)
    {
        if (alice.family.has_child == false && bob.family.has_child == false)
        {
            printf("\n💍 АЛИСА И БОБ ПОЖЕНИЛИСЬ! 💍\n");
            // finances unification
            RUB total_rub = alice.vtb.account_rub + bob.vtb.account_rub;
            USD total_usd = alice.vtb.account_usd + bob.vtb.account_usd;
            alice.vtb.account_rub = total_rub / 2;
            bob.vtb.account_rub = total_rub / 2;
            alice.vtb.account_usd = total_usd / 2;
            bob.vtb.account_usd = total_usd / 2;
        }
    }
}

void compare_personalities(const int month, const int year)
{
    if (month == 12 && year % 3 == 0)
    {
        printf("\nСРАВНЕНИЕ ПЕРСОНАЖЕЙ: %d год\n", year);
        printf("Алиса - счет: %lld руб., здоровье: %.2f\n", alice.vtb.account_rub, alice.health_problem_threshold);
        printf("Боб    - счет: %lld руб., здоровье: %.2f\n", bob.vtb.account_rub, bob.health_problem_threshold);

        if (alice.vtb.account_rub > bob.vtb.account_rub)
            printf("Алиса богаче на %lld руб.\n", alice.vtb.account_rub - bob.vtb.account_rub);
        else
            printf("Боб богаче на %lld руб.\n", bob.vtb.account_rub - alice.vtb.account_rub);
    }
}

// ========== РАСШИРЕННАЯ ДВОЙНАЯ СИМУЛЯЦИЯ ==========

void dual_simulation_extended()
{
    printf("\n=== РАСШИРЕННАЯ ДВОЙНАЯ СИМУЛЯЦИЯ ===\n");

    alice_init();
    bob_init();
    alice_init_statistics();
    bob_init_statistics();

    for (int i = 0; i < 5; i++)
    {
        alice_loans[i].is_active = false;
        bob_loans[i].is_active = false;
    }

    alice_loans[0].amount = 500000;
    alice_loans[0].monthly_payment = 15000;
    alice_loans[0].interest_rate = 12;
    alice_loans[0].months_left = 36;
    alice_loans[0].is_active = true;
    strcpy(alice_loans[0].purpose, "Ремонт квартиры");

    int year = 2026;
    int month = 2;
    int months_survived = 0;

    while (!(year == 2036 && month == 2))
    {
        // reset
        alice_reset_health_problem_threshold();
        alice_reset_luck();
        bob_reset_health_problem_threshold();
        bob_reset_luck();

        // alice simulation
        alice_food_cost(month, year);
        alice_first_job(month, year);
        alice_second_job(month, year);
        alice_car();
        alice_pets(month, year);
        alice_rent(month, year);
        alice_health_cost(month, year);
        alice_entertainment(month);
        alice_personal_care();
        alice_clothes(month);
        alice_education(month, year);
        alice_transport();
        alice_communication();
        alice_subscriptions();
        alice_sport();
        alice_gifts(month);
        alice_gadgets(month, year);
        alice_charity(month);
        alice_freelance(month);
        alice_family_events(month, year);
        alice_trip();
        alice_investment_portfolio();
        alice_unexpected_events();
        alice_use_airbag();
        alice_monthly_budget_check();
        alice_count_health_problem_threshold();
        alice_manage_loans();
        alice_tax_declaration(year);
        alice_collect_statistics();
        alice_update_health_metrics();
        alice_update_investments();

        // bob simulation
        bob_food_cost(month, year);
        bob_first_job(month, year);
        bob_car();
        bob_pets(month, year);
        bob_rent(month, year);
        bob_health_cost(month, year);
        bob_entertainment(month);
        bob_sport();
        bob_freelance(month);
        bob_save_money(month);
        bob_unexpected_events();
        bob_use_airbag();
        bob_monthly_budget_check();
        bob_count_health_problem_threshold();
        bob_manage_loans();
        bob_tax_declaration(year);
        bob_collect_statistics();
        bob_update_health_metrics();
        bob_update_investments();

        // interactions
        alice_and_bob_meet(month, year);
        compare_personalities(month, year);

        if (alice.health_problem_threshold > 1.0)
        {
            printf("\n💔 АЛИСА УМЕРЛА В %d ГОДУ 💔\n", year);
            return;
        }

        if (bob.health_problem_threshold > 1.0)
        {
            printf("\n💔 БОБ УМЕР В %d ГОДУ 💔\n", year);
            return;
        }

        months_survived++;
        ++month;
        if (month == 12)
        {
            ++year;
            month = 1;
            if (year % 2 == 0)
            {
                printf("📅 Год %d завершен\n", year - 1);
            }
        }
    }

    printf("\n✅ РАСШИРЕННАЯ СИМУЛЯЦИЯ УСПЕШНО ЗАВЕРШЕНА!\n");
    printf("Прожито месяцев: %d\n", months_survived);

    print_results();
    bob_print_results();
    alice_print_detailed_report();
    bob_print_detailed_report();
    compare_detailed_statistics();

    RUB alice_total = alice.vtb.account_rub + alice.vtb.savings + alice.vtb.deposit;
    RUB bob_total = bob.vtb.account_rub + bob.vtb.savings;

    printf("\n🏆 ФИНАЛЬНЫЙ РЕЗУЛЬТАТ:\n");
    if (alice_total > bob_total)
        printf("   Алиса победила с отрывом в %lld руб.\n", alice_total - bob_total);
    else if (bob_total > alice_total)
        printf("   Боб победил с отрывом в %lld руб.\n", bob_total - alice_total);
    else
        printf("   Ничья! Оба накопили одинаково.\n");

    if (alice_health.happiness_index > bob_health.happiness_index)
        printf("   Алиса счастливее Боба!\n");
    else if (bob_health.happiness_index > alice_health.happiness_index)
        printf("   Боб счастливее Алисы!\n");
    else
        printf("   Одинаково счастливы.\n");
}

int main()
{
    printf("   СИМУЛЯТОР ЖИЗНИ ДВУХ ПЕРСОНАЖЕЙ\n");

    printf("Выберите режим:\n");
    printf("1 - Симуляция только Алисы\n");
    printf("2 - Симуляция только Боба\n");
    printf("3 - Двойная симуляция (Алиса и Боб)\n");
    printf("4 - Расширенная двойная симуляция (с аналитикой)\n");
    printf("Ваш выбор: ");

    int choice;
    scanf("%d", &choice);

    srand(time(NULL));

    switch (choice)
    {
    case 1:
        printf("\nЗапуск симуляции Алисы...\n\n");
        alice_init();
        alice_simulation();
        print_results();
        break;

    case 2:
        printf("\nЗапуск симуляции Боба...\n\n");
        bob_init();
        bob_simulation();
        bob_print_results();
        break;

    case 3:
        dual_simulation_extended();
        break;

    case 4:
        dual_simulation_extended();
        break;

    default:
        printf("\nНеверный выбор. Запуск расширенной симуляции...\n");
        dual_simulation_extended();
    }

    printf("СИМУЛЯЦИЯ ЗАВЕРШЕНА\n");

    return 0;
}
