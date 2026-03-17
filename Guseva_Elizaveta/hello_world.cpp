#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

struct Person alice;

float random_float(float min, float max)
{
    return min + (max - min) * rand() / (RAND_MAX + 1.0);
}

int random_int(int min, int max)
{
    return min + rand() % (max - min + 1);
}

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

void alice_health(const int month, const int year)
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

    float market_return = random_float(-0.05, 0.12); // -5% to +12% monthly
    alice.vtb.investment_portfolio += alice.vtb.investment_portfolio * market_return;
    alice.stock_dividends += alice.vtb.investment_portfolio * 0.002; // 0.2% dividends
}

void alice_family_events(const int month, const int year)
{
    if (!alice.family.has_child && year == 2028 && month == 6 && alice.luck > 0.5)
    {
        alice.family.has_child = true; // baby born
        alice.family.child_age = 0;
        alice.vtb.account_rub -= 50000;        // baby expenses
        alice.luck += 0.3;                     // happiness
        alice.health_problem_threshold += 0.3; // stress of parenthood
    }

    if (alice.family.has_child)
    {
        alice.family.child_age++;

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

    if (month == 2 || month == 8) // vacation months
        entertainment_cost += 10000;

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

    if (month == 3 || month == 9) // seasonal clothes change
        clothes_cost = 10000;
    else if (month == 12) // New Year outfit
        clothes_cost = 8000;
    else
        clothes_cost = 2000; // occasional purchases

    alice.clothes += clothes_cost + (clothes_cost * (alice.inflation_rate / 100.0 / 12.0));
    alice.vtb.account_rub -= clothes_cost + (clothes_cost * (alice.inflation_rate / 100.0 / 12.0));
}

void alice_education(const int month, const int year)
{
    if (month == 9 && year % 2 == 0) // courses every 2 years
    {
        RUB course_cost = 30000;

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

    if (month == 3 && alice.family.has_child) // child birthday in March
        gift_cost = 5000;
    if (month == 12) // New Year gifts
        gift_cost = 10000;
    if (month == 2) // Valentine's day
        gift_cost = 3000;
    if (month == 8) // friends birthdays
        gift_cost = 2000;

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
void alice_use_airbag(){

    if (alice.vtb.account_rub < 0 && alice.vtb.savings > 0)
    {
        alice.vtb.account_rub += -alice.vtb.account_rub;
        alice.vtb.savings -= abs(alice.vtb.account_rub); // get some savings to cover negative RUB
    }

    if (alice.vtb.account_rub < 0 && alice.vtb.account_usd > 0)
    {
        alice.vtb.account_rub += (-alice.vtb.account_rub / alice.vtb.rate_usd_rub); // convert some USD to RUB to cover negative RUB
        alice.vtb.account_usd -= (-alice.vtb.account_rub / alice.vtb.rate_usd_rub);
    }
    
}
void print_results()
{
    printf("\nФИНАНСОВЫЙ ОТЧЕТ\n");
    printf("Счет в рублях: %lld руб.\n", alice.vtb.account_rub);
    printf("Счет в долларах: %lld USD\n", alice.vtb.account_usd);
    printf("Инвестиционный портфель: %lld USD\n", alice.vtb.investment_portfolio);
    printf("Депозит: %lld руб.\n", alice.vtb.deposit);
    printf("Накопления: %lld руб.\n", alice.vtb.savings);

    printf("\nРАСХОДЫ\n");
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

    printf("\nДОХОДЫ\n");
    printf("Зарплата (руб): %lld руб.\n", alice.salary_rub);
    printf("Зарплата (USD): %lld USD\n", alice.salary_usd);
    printf("Фриланс: %lld руб.\n", alice.freelance_income);
    printf("Пассивный доход: %lld руб.\n", alice.passive_income);
    printf("Дивиденды: %lld USD\n", alice.stock_dividends);
    printf("Бонусы: %lld руб.\n", alice.bonuses);
    printf("Неожиданные доходы: %lld руб.\n", alice.unexpected_income);

    if (alice.family.has_child)
    {
        printf("\nСЕМЬЯ\n");
        printf("Ребенок: есть (возраст %d лет)\n", alice.family.child_age);
        printf("Расходы на ребенка: %lld руб.\n", alice.family.child_expenses);
        printf("Накопления на образование: %lld руб.\n", alice.family.child_education);
    }

    if (alice.family.has_pet_cat || alice.family.has_pet_dog)
    {
        printf("Домашние питомцы: ");
        if (alice.family.has_pet_cat)
            printf("кот ");
        if (alice.family.has_pet_dog)
            printf("собака");
        printf("\nРасходы на питомцев: %lld руб.\n", alice.family.pet_expenses);
    }

    printf("Итоговый капитал (руб): %lld\n", alice.vtb.account_rub + alice.vtb.savings + alice.vtb.deposit);
    printf("Итоговый капитал (USD): %lld\n", alice.vtb.account_usd + alice.vtb.investment_portfolio);

    if (alice.health_problem_threshold > 1.0)
        printf("СТАТУС: Умер от проблем со здоровьем\n");
    else
        printf("СТАТУС: Жив и здоров\n");
}

void RIP()
{
    printf("\n💀💀💀 ПЕРСОНАЖ УМЕР ОТ ПРОБЛЕМ СО ЗДОРОВЬЕМ 💀💀💀\n");
    print_results();
}

void alice_init()
{
    // Bank
    alice.vtb.rate_usd_rub = random_float(70, 120); // initial exchange rate
    alice.vtb.account_rub = 50000; // начальный капитал
    alice.vtb.account_usd = 10000;
    alice.vtb.investment_portfolio = 2000;
    alice.vtb.deposit = 100000;
    alice.vtb.deposit_rate = 8.5;
    alice.vtb.savings = 0;

    // Person
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

    // Car
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

    // Home
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

    // Family
    alice.family.has_child = false;
    alice.family.child_age = 0;
    alice.family.child_expenses = 0;
    alice.family.child_education = 0;
    alice.family.has_pet_cat = false;
    alice.family.has_pet_dog = false;
    alice.family.pet_expenses = 0;

    srand(time(NULL));
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

        // Основные расходы
        alice_food_cost(month, year);
        alice_first_job(month, year);
        alice_second_job(month, year);
        alice_car();
        alice_pets(month, year);
        alice_rent(month, year);
        alice_health(month, year);

        // Дополнительные расходы
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

        // Доходы и события
        alice_freelance(month);
        alice_family_events(month, year);
        alice_trip();
        alice_investment_portfolio();
        alice_unexpected_events(); // car repairing, health problems, etc
        alice_use_airbag(); // financial airbag

        // Проверки
        alice_monthly_budget_check();
        alice_count_health_problem_threshold();

        if (alice.health_problem_threshold > 1.0)
        {
            RIP();
            return;
        }

        ++month;
        if (month == 13)
        {
            ++year;
            month = 1;
            printf("Год %d завершен. Текущий капитал: %lld руб.\n", year - 1, alice.vtb.account_rub);
        }

        months_survived++;
    }

    printf("\n✅ Симуляция успешно завершена! Прожито месяцев: %d\n", months_survived);
}

int main()
{
    printf("СИМУЛЯТОР ЖИЗНИ ЧЕЛОВЕКА\n");
    printf("Запуск симуляции Алисы...\n\n");

    alice_init();
    alice_simulation();
    print_results();

    return 0;
}
