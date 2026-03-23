#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>

using RUB = long long int;          
const RUB CASH_LIMIT = 100'000;     
using percent = double;             


struct Car {
    RUB value;      
    RUB gas;        
};

struct Apartment {
    RUB value;               
    RUB mortgage_debt;       // остаток ипотеки
    RUB total_mortgage_paid; // сколько выплачено по ипотеке
    RUB total_interest_paid; // сколько выплачено процентов
    RUB property_tax_paid;   
    RUB total_repair_paid;   
    RUB insurance_paid;      // страховка
};

struct Job {
    RUB salary;                   
    percent fire_probability;       
    percent raise_probability;       
    percent annual_raise_percent;    
    int raise_month;                // Месяц ежегодного повышения
};

struct World {
    percent inflation_rate;          
    percent crisis_probability;      
    percent crisis_impact_percent;   // Насколько сильно кризис влияет на активы
    percent apartment_growth_rate;   
};

struct Deposit {
    RUB amount;         // Сумма депозита
    percent annual_rate; // Годовая ставка
    int months_left;    
    bool is_replenishable; // Можно ли пополнять вклад
};

struct Credit {
    RUB sumcredit;          // Остаток долга
    RUB monthly_payment;    
    percent interest_rate;   // Процентная ставка
    int months_left;        // Остаток срока кредита
};

struct Investment {
    RUB amount;             
    percent expected_return; // Ожидаемая доходность
    percent risk;            
};

struct YearlyReport {
    int year;                   
    RUB net_worth;              
    RUB capital;                
    RUB deposit;                
    RUB car_value;              
    RUB credit;                
    RUB mortgage_debt;          
    RUB stock_value;            
    RUB rent_paid;            
    RUB mortgage_paid;       
    RUB interest_paid;       
    RUB property_tax_paid;      
    RUB stress_index;
};


std::vector<YearlyReport> report_alice;   // массив отчётов Алисы
std::vector<YearlyReport> report_bob;     // массиы отчётов Боба


struct Person {
    RUB salary;                 
    RUB food;                  
    Car car;                    
    RUB capital;                
    Deposit deposit;            
    Job job;                   
    Credit credit;              
    Investment investment;      
    RUB rent;                   
    RUB total_rent_paid;

    int children_count;         
    RUB child_monthly_expense;  

    percent early_mortgage_payment_rate; 
    RUB total_early_mortgage_paid;     

    RUB stock_investment_amount; // инвестиции в акции
    percent stock_return_rate;    // доходность акций
    percent stock_volatility;     // волатильность
    RUB total_stock_profit;      // общая прибыль от акций

    bool is_unemployed;          // безработный ли человек
    int unemployed_months_left;  // сколько месяцев без работы

    RUB stress_index;            // индекс стресса
    RUB liquidity_reserve;       // финансовая подушка

    Apartment apartment;
};

Person alice;   // Объект Алисы
Person bob;     // Объект Боба


void alice_init()
{
    alice.capital = 0;                   
    alice.salary = 500'000;              
    alice.food = 20'000;                 

    alice.car.value = 2'400'000;         
    alice.car.gas = 10'000;              

    alice.deposit.amount = 0;            // депозит отсутствует
    alice.deposit.annual_rate = 11.5;    // процент по депозиту
    alice.deposit.months_left = 12;      // срок вклада
    alice.deposit.is_replenishable = true;  // можно пополнять

    alice.job.salary = 180'000;          // ЗП
    alice.job.fire_probability = 2.0;    // вероятность вылететь
    alice.job.raise_probability = 5.0;   // вероятность повышения
    alice.job.annual_raise_percent = 7.5;
    alice.job.raise_month = 3;           

    alice.credit.sumcredit = 2'400'000;  
    alice.credit.monthly_payment = 30'000;
    alice.credit.interest_rate = 12.0;
    alice.credit.months_left = 48;

    alice.investment.amount = 0;
    alice.investment.expected_return = 15.0;
    alice.investment.risk = 5.0;

    alice.children_count = 0;
    alice.child_monthly_expense = 15000;

    alice.early_mortgage_payment_rate = 0.20;
    alice.total_early_mortgage_paid = 0;


    alice.stock_investment_amount = 0;
    alice.stock_return_rate = 0.10;
    alice.stock_volatility = 0.15;
    alice.total_stock_profit = 0;

    alice.is_unemployed = false;
    alice.unemployed_months_left = 0;

    alice.apartment.value = 12'000'000;
    alice.apartment.mortgage_debt = 12'000'000;
    alice.apartment.total_mortgage_paid = 0;
    alice.apartment.total_interest_paid = 0;
    alice.apartment.property_tax_paid = 0;
    alice.apartment.total_repair_paid = 0;
    alice.apartment.insurance_paid = 0;
    alice.stress_index = 0;
    alice.liquidity_reserve = 0;
}


void bob_init()
{
    bob.capital = 0;               // стартовый капитал
    bob.salary = 500'000;          // начальная зарплата
    bob.food = 20'000;             // расходы на еду

    bob.car.value = 2'400'000;     // стоимость машины
    bob.car.gas = 10'000;          // расходы на бензин

    bob.deposit.amount = 0;        // депозит отсутствует
    bob.deposit.annual_rate = 11.5; // процент по депозиту
    bob.deposit.months_left = 12;   // срок вклада
    bob.deposit.is_replenishable = true; // можно пополнять

    bob.job.salary = 180'000;        // зарплата по контракту
    bob.job.fire_probability = 2.0;  // вероятность увольнения
    bob.job.raise_probability = 5.0; // вероятность повышения
    bob.job.annual_raise_percent = 7.5;  // годовой рост зарплаты
    bob.job.raise_month = 3;         // месяц повышения

    bob.credit.sumcredit = 2'400'000; // потребительский кредит
    bob.credit.monthly_payment = 30'000;
    bob.credit.interest_rate = 12.0;
    bob.credit.months_left = 48;

    bob.investment.amount = 0;
    bob.investment.expected_return = 15.0;
    bob.investment.risk = 5.0;

    bob.children_count = 0;
    bob.child_monthly_expense = 15000;

    bob.stock_investment_amount = 0;
    bob.stock_return_rate = 10.0;   // доходность 10 процентов
    bob.stock_volatility = 15.0;    // волатильность 15 процентов
    bob.total_stock_profit = 0;

    bob.is_unemployed = false;
    bob.unemployed_months_left = 0;

    bob.rent = 120'000;             // ежемесячная аренда
    bob.total_rent_paid = 0;

    bob.apartment.value = 0;
    bob.apartment.mortgage_debt = 0;
    bob.apartment.total_mortgage_paid = 0;
    bob.apartment.total_interest_paid = 0;
    bob.apartment.property_tax_paid = 0;
    bob.apartment.total_repair_paid = 0;
    bob.apartment.insurance_paid = 0;
    bob.stress_index = 0;
    bob.liquidity_reserve = 0;
}


World world_init()
{
    World world;

    world.inflation_rate = 8.0;         // инфляция 8 процентов
    world.crisis_probability = 3.0;     // вероятность кризиса 3 процента
    world.crisis_impact_percent = 25.0; // падение активов на 25 процентов
    world.apartment_growth_rate = 5.0;  // рост недвижимости 5 процентов

    return world;
}


void alice_pay_food(const World& world)
{
    RUB food_cost = static_cast<RUB>(
        alice.food *
        (1 + world.inflation_rate / 100.0)
        );

    alice.capital -= food_cost;

    if (alice.capital < 0)
        alice.stress_index += 2;
}


void alice_pay_car_expenses(const World& world)
{
    RUB gas_cost =
        static_cast<RUB>(
            alice.car.gas *
            (1 + world.inflation_rate / 100.0)
            );

    alice.capital -= gas_cost;

    if (alice.capital < 0)
        alice.stress_index += 2;
}


void alice_depreciate_car()
{
    alice.car.value = static_cast<RUB>(alice.car.value * 0.98); // 2% в месяц
}


void alice_pay_credit()
{
    if (alice.credit.months_left <= 0) return;

    percent monthly_rate = alice.credit.interest_rate / 12.0;
    RUB interest = static_cast<RUB>(alice.credit.sumcredit * (monthly_rate / 100.0));
    alice.capital -= alice.credit.monthly_payment;
    alice.credit.sumcredit -= (alice.credit.monthly_payment - interest);
    alice.credit.months_left--;

    if (alice.capital < 0)
        alice.stress_index += 3;
}


void alice_pay_mortgage_month(const World& world)
{
    if (alice.apartment.mortgage_debt <= 0)
        return;

    percent monthly_rate = 0.08 / 12.0;

    RUB interest = static_cast<RUB>(
        alice.apartment.mortgage_debt * monthly_rate
        );

    RUB principal_payment = 67'000;

    RUB total_payment = interest + principal_payment;

    double inflation_multiplier =
        1 + world.inflation_rate / 100.0 / 12.0;

    total_payment =
        static_cast<RUB>(total_payment * inflation_multiplier);

    alice.capital -= total_payment;

    alice.apartment.mortgage_debt -= principal_payment;

    alice.apartment.total_mortgage_paid += principal_payment;

    alice.apartment.total_interest_paid += interest;

    if (alice.capital < 0)
        alice.stress_index += 5;

    if (alice.apartment.mortgage_debt < 0)
        alice.apartment.mortgage_debt = 0;
}


void alice_early_repayment()
{
    if (alice.capital > 300'000 && alice.apartment.mortgage_debt > 0)
    {
        RUB extra = static_cast<RUB>(alice.capital * (alice.early_mortgage_payment_rate / 100.0));

        alice.capital -= extra;
        alice.apartment.mortgage_debt -= extra;
        alice.total_early_mortgage_paid += extra;

        if (alice.apartment.mortgage_debt < 0)
            alice.apartment.mortgage_debt = 0;
    }
}


void alice_apartment_growth(const World& world)
{
    percent growth = world.apartment_growth_rate;

    alice.apartment.value =
        static_cast<RUB>(alice.apartment.value * (1 + growth / 100.0));
}


void alice_property_tax(const World& world)
{
    percent tax_rate = 0.001;

    RUB tax =
        static_cast<RUB>(alice.apartment.value * tax_rate);

    double inflation_multiplier =
        1 + world.inflation_rate / 100.0;

    tax = static_cast<RUB>(tax * inflation_multiplier);

    alice.capital -= tax;

    alice.apartment.property_tax_paid += tax;

    if (alice.capital < 0)
        alice.stress_index += 1;
}


void alice_pay_insurance(const World& world)
{
    RUB insurance = 30'000;

    double inflation_multiplier =
        1 + world.inflation_rate / 100.0;

    insurance =
        static_cast<RUB>(insurance * inflation_multiplier);

    alice.capital -= insurance;

    alice.apartment.insurance_paid += insurance;

    if (alice.capital < 0)
        alice.stress_index += 1;
}


void alice_random_repair(const World& world)
{
    int random_value = rand() % 100;

    if (random_value < 10)
    {
        RUB repair_cost = 150'000;

        double inflation_multiplier =
            1 + world.inflation_rate / 100.0;

        repair_cost =
            static_cast<RUB>(repair_cost * inflation_multiplier);

        alice.capital -= repair_cost;

        alice.apartment.total_repair_paid += repair_cost;

        alice.stress_index += 3;
    }
}


void alice_check_crisis(const World& world)
{
    int chance = rand() % 100;

    if (chance < world.crisis_probability)
    {
        percent drop = world.crisis_impact_percent;

        alice.apartment.value =
            static_cast<RUB>(alice.apartment.value * (1 - drop / 100.0));

        alice.stress_index += 10;
    }
}


void alice_calculate_liquidity()
{
    alice.liquidity_reserve = alice.capital + alice.deposit.amount;

    if (alice.liquidity_reserve < 200'000)
        alice.stress_index += 3;
}


void alice_check_job_loss()
{
    if (!alice.is_unemployed && (rand() % 1000) < 5) // 0.5% шанс на увольнение
    {
        alice.is_unemployed = true;
        alice.unemployed_months_left = 6;
        alice.stress_index += 10; // стресс от увольнения
    }
}


void alice_process_unemployment()
{
    if (alice.is_unemployed)
    {
        alice.salary = 0;
        alice.unemployed_months_left--;

        // если месяцы без работы закончились
        if (alice.unemployed_months_left <= 0)
        {
            alice.is_unemployed = false;
            alice.salary = 150'000; // восстановление зарплаты
            alice.stress_index -= 5; // уменьшение стресса
        }
        else
        {
            alice.stress_index += 2; // стресс от продолжающейся безработицы
        }
    }
}


void alice_check_annual_raise(int month)
{
    if (alice.is_unemployed) return;

    if (month == alice.job.raise_month)
    {
        alice.salary = static_cast<RUB>(alice.salary * (1 + alice.job.annual_raise_percent / 100.0));
        alice.stress_index -= 1; // радость от повышения
    }
}


void alice_random_bonus()
{
    if (alice.is_unemployed) return;

    if ((rand() % 100) < 20) // 20% шанс бонуса
    {
        RUB bonus = 50'000 + rand() % 50'000; // случайный бонус
        alice.capital += bonus;
        alice.stress_index -= 1; // радость от бонуса
    }
}


void alice_overtime_pay()
{
    if (alice.is_unemployed) return;

    int chance = rand() % 100;
    if (chance < 30) // 30% шанс переработки
    {
        RUB overtime = 10'000 + rand() % 20'000;
        alice.capital += overtime;
        alice.stress_index += 1; // немного усталости
    }
}


void alice_salary_shock(const World& world)
{
    if (!alice.is_unemployed)
    {
        int chance = rand() % 100;
        if (chance < static_cast<int>(world.crisis_probability)) // кризис
        {
            alice.salary = static_cast<RUB>(alice.salary * 0.8); // падение зарплаты на 20%
            alice.stress_index += 5; // стресс от кризиса
        }
    }
}


void alice_change_job()
{
    if (!alice.is_unemployed && (rand() % 1000) < 3) // 0.3% шанс смены работы
    {
        RUB old_salary = alice.salary;
        alice.salary = static_cast<RUB>(alice.salary * 0.9); // новая работа ниже зарплата на 10%
        alice.stress_index += 5;
    }
}


void alice_burnout()
{
    if (alice.stress_index > 50) // если стресс высокий
    {
        alice.salary = static_cast<RUB>(alice.salary * 0.95); // снижение производительности
        alice.stress_index += 2; // стресс от выгорания
    }
}


void alice_invest_in_stocks()
{
    if (alice.capital > 50'000)
    {
        RUB invest = alice.capital / 2;
        alice.capital -= invest;
        alice.stock_investment_amount += invest;
    }
}


void alice_apply_stock_return()
{
    double random_factor = ((rand() % 200) - 100) / 100.0;
    percent monthly_return = alice.stock_return_rate / 12.0;
    percent volatility_effect = alice.stock_volatility * random_factor / 12.0;

    RUB profit = static_cast<RUB>(alice.stock_investment_amount * (monthly_return + volatility_effect));
    alice.stock_investment_amount += profit;
    alice.total_stock_profit += profit;

    // стресс если убытки
    if (profit < 0) alice.stress_index += 2;
}


void alice_panic_sell()
{
    if (alice.stock_investment_amount > 0 && rand() % 100 < 5) // 5% шанс панической продажи
    {
        RUB loss = alice.stock_investment_amount / 10; // теряем 10%
        alice.stock_investment_amount -= loss;
        alice.capital += alice.stock_investment_amount;
        alice.total_stock_profit -= loss;
        alice.stress_index += 5; // стресс от потерь
    }
}


void alice_rebalance_portfolio()
{
    if (alice.stock_investment_amount > 100'000)
    {
        RUB sell = alice.stock_investment_amount / 4; // продаём 25%
        alice.capital += sell;
        alice.stock_investment_amount -= sell;
    }
}


void alice_check_child_birth()
{
    int random_value = rand() % 1000;
    if (random_value < 3) // 0.3% шанс рождения ребёнка в месяц
    {
        alice.children_count++;
        alice.stress_index += 5; // стресс и радость одновременно
    }
}


void alice_pay_children_expenses()
{
    RUB total = alice.children_count * alice.child_monthly_expense;
    alice.capital -= total;

    // если нет денег, увеличиваем стресс
    if (alice.capital < 0)
        alice.stress_index += 5;
}


void alice_child_preschool()
{
    for (int i = 0; i < alice.children_count; ++i)
    {
        int chance = rand() % 100;
        if (chance < 70) // 70% дети ходят в сад
        {
            RUB cost = 10'000 + rand() % 5'000;
            alice.capital -= cost;

            if (alice.capital < 0)
                alice.stress_index += 2;
        }
    }
}


void alice_child_school()
{
    for (int i = 0; i < alice.children_count; ++i)
    {
        int chance = rand() % 100;
        if (chance < 100) // все дети идут в школу
        {
            RUB cost = 15'000 + rand() % 10'000;
            alice.capital -= cost;

            if (alice.capital < 0)
                alice.stress_index += 3;
        }
    }
}


void alice_child_university()
{
    for (int i = 0; i < alice.children_count; ++i)
    {
        int chance = rand() % 100;
        if (chance < 50) // 50% шанс, что ребёнок идёт в универ
        {
            RUB cost = 50'000 + rand() % 50'000;
            alice.capital -= cost;

            if (alice.capital < 0)
                alice.stress_index += 5;
        }
    }
}


void alice_maternity_leave()
{
    for (int i = 0; i < alice.children_count; ++i)
    {
        int chance = rand() % 100;
        if (chance < 5) // 5% шанс в месяце взять декрет
        {
            RUB lost_salary = static_cast<RUB>(alice.salary * 0.5); // теряем 50% дохода
            alice.capital -= lost_salary;
            alice.stress_index += 5;
        }
    }
}


void alice_stress_from_debt()
{
    if (alice.credit.sumcredit > 1'000'000)
        alice.stress_index += 5;

    if (alice.apartment.mortgage_debt > 5'000'000)
        alice.stress_index += 5;
}


void alice_stress_from_liquidity()
{
    if (alice.capital + alice.deposit.amount < 200'000)
        alice.stress_index += 3;
}

void alice_stress_from_rent()
{
    if (alice.rent > 50'000)
        alice.stress_index += 2;
}


void alice_stress_from_children()
{
    if (alice.children_count > 2)
        alice.stress_index += 3;
}


void alice_calculate_total_stress()
{
    alice_stress_from_debt();
    alice_stress_from_liquidity();
    alice_stress_from_rent();
    alice_stress_from_children();

    // если стресс больше 100, уменьшаем зарплату на 5%
    if (alice.stress_index > 100)
    {
        alice.salary = static_cast<RUB>(alice.salary * 0.95);
        alice.stress_index = 100; // лимитируем стресс
    }
}


void alice_random_large_expense()
{
    int chance = rand() % 100;
    if (chance < 5) // 5% шанс
    {
        RUB expense = 100'000 + rand() % 400'000;
        alice.capital -= expense;
        alice.stress_index += 5;
    }
}


void alice_random_bonus_or_inheritance()
{
    int chance = rand() % 100;
    if (chance < 5) // 5% шанс
    {
        RUB gain = 200'000 + rand() % 500'000;
        alice.capital += gain;
        alice.stress_index -= 3; // радость от денег
    }
}


void alice_buy_furniture(const World& world)
{
    int chance = rand() % 100;

    if (chance < 8)
    {
        RUB cost = 120'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(
            cost * (1 + inflation / 100.0)
            );

        alice.capital -= cost;

        alice.stress_index += 1;
    }
}


void alice_appliance_break(const World& world)
{
    int chance = rand() % 100;

    if (chance < 6)
    {
        RUB repair = 60'000;

        percent inflation = world.inflation_rate;

        repair = static_cast<RUB>(
            repair * (1 + inflation / 100.0)
            );

        alice.capital -= repair;

        alice.stress_index += 2;
    }
}


void alice_neighbor_flood(const World& world)
{
    int chance = rand() % 1000;

    if (chance < 5)
    {
        RUB repair = 250'000;

        percent inflation = world.inflation_rate;

        repair = static_cast<RUB>(
            repair * (1 + inflation / 100.0)
            );

        alice.capital -= repair;

        alice.stress_index += 6;
    }
}


void alice_lost_keys(const World& world)
{
    int chance = rand() % 100;

    if (chance < 3)
    {
        RUB locksmith = 15'000;

        percent inflation = world.inflation_rate;

        locksmith = static_cast<RUB>(
            locksmith * (1 + inflation / 100.0)
            );

        alice.capital -= locksmith;

        alice.stress_index += 1;
    }
}


void alice_install_security(const World& world)
{
    int chance = rand() % 100;

    if (chance < 2)
    {
        RUB cost = 80'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(
            cost * (1 + inflation / 100.0)
            );

        alice.capital -= cost;
    }
}


void alice_buy_home_decor(const World& world)
{
    int chance = rand() % 100;

    if (chance < 7)
    {
        RUB cost = 25'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        alice.capital -= cost;
    }
}


void alice_buy_phone(const World& world)
{
    int chance = rand() % 100;

    if (chance < 5)
    {
        RUB cost = 90'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        alice.capital -= cost;

        alice.stress_index += 1;
    }
}


void alice_family_gift()
{
    int chance = rand() % 100;

    if (chance < 10)
    {
        RUB gift = 15'000;

        alice.capital -= gift;
    }
}


void alice_lost_wallet()
{
    int chance = rand() % 100;

    if (chance < 3)
    {
        RUB loss = 12'000;

        alice.capital -= loss;

        alice.stress_index += 2;
    }
}


void alice_go_to_conference(const World& world)
{
    int chance = rand() % 100;

    if (chance < 4)
    {
        RUB cost = 40'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        alice.capital -= cost;
    }
}


void alice_medical_expense(const World& world)
{
    int chance = rand() % 100;

    if (chance < 6)
    {
        RUB cost = 35'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        alice.capital -= cost;

        alice.stress_index += 2;
    }
}


void alice_sell_old_items()
{
    int chance = rand() % 100;

    if (chance < 5)
    {
        RUB income = 10'000;

        alice.capital += income;
    }
}


void alice_take_vacation(const World& world)
{
    int chance = rand() % 100;

    if (chance < 5)
    {
        RUB cost = 150'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        alice.capital -= cost;
    }
}


void alice_take_courses(const World& world)
{
    int chance = rand() % 100;

    if (chance < 4)
    {
        RUB cost = 70'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        alice.capital -= cost;
    }
}


RUB alice_calculate_net_worth()
{
    RUB assets = 0;
    RUB liabilities = 0;

    assets += alice.capital;
    assets += alice.deposit.amount;
    assets += alice.car.value;
    assets += alice.stock_investment_amount;
    assets += alice.apartment.value;

    liabilities += alice.credit.sumcredit;
    liabilities += alice.apartment.mortgage_debt;

    return assets - liabilities;
}


void alice_make_year_report(int year)
{
    YearlyReport report;

    report.year = year;
    report.capital = alice.capital;
    report.deposit = alice.deposit.amount;
    report.car_value = alice.car.value;
    report.credit = alice.credit.sumcredit;
    report.mortgage_debt = alice.apartment.mortgage_debt;
    report.stock_value = alice.stock_investment_amount;
    report.rent_paid = 0;
    report.mortgage_paid = alice.apartment.total_mortgage_paid;
    report.interest_paid = alice.apartment.total_interest_paid;
    report.property_tax_paid = alice.apartment.property_tax_paid;
    report.stress_index = alice.stress_index;

    RUB assets =
        alice.capital +
        alice.deposit.amount +
        alice.car.value +
        alice.stock_investment_amount +
        alice.apartment.value;

    RUB liabilities =
        alice.credit.sumcredit +
        alice.apartment.mortgage_debt;

    report.net_worth = assets - liabilities;

    report_alice.push_back(report);
}


void bob_pay_food()
{
    bob.capital -= bob.food;
    if (bob.capital < 0)
        bob.stress_index += 2;
}


void bob_pay_car_expenses()
{
    bob.capital -= bob.car.gas;
    if (bob.capital < 0)
        bob.stress_index += 1;
}


void bob_depreciate_car()
{
    bob.car.value = static_cast<RUB>(bob.car.value * 0.98);
}


void bob_pay_rent()
{
    bob.capital -= bob.rent;
    bob.total_rent_paid += bob.rent;

    if (bob.capital < 0)
        bob.stress_index += 2;
}


void bob_check_job_loss()
{
    if (!bob.is_unemployed && (rand() % 1000) < 5) // 0.5% шанс на увольнение
    {
        bob.is_unemployed = true;
        bob.unemployed_months_left = 6;
        bob.stress_index += 10; // стресс от увольнения
    }
}


void bob_process_unemployment()
{
    if (bob.is_unemployed)
    {
        bob.salary = 0;
        bob.unemployed_months_left--;

        if (bob.unemployed_months_left <= 0)
        {
            bob.is_unemployed = false;
            bob.salary = 150'000;
            bob.stress_index -= 5;
        }
        else
        {
            bob.stress_index += 2;
        }
    }
}


void bob_check_annual_raise(int month)
{
    if (bob.is_unemployed) return;

    if (month == bob.job.raise_month)
    {
        bob.salary = static_cast<RUB>(bob.salary * (1 + bob.job.annual_raise_percent / 100.0));
        bob.stress_index -= 1;
    }
}


void bob_random_bonus()
{
    if (bob.is_unemployed) return;

    if ((rand() % 100) < 20)
    {
        RUB bonus = 50'000 + rand() % 50'000;
        bob.capital += bonus;
        bob.stress_index -= 1;
    }
}


void bob_overtime_pay()
{
    if (bob.is_unemployed) return;

    int chance = rand() % 100;
    if (chance < 30)
    {
        RUB overtime = 10'000 + rand() % 20'000;
        bob.capital += overtime;
        bob.stress_index += 1;
    }
}


void bob_salary_shock(const World& world)
{
    if (!bob.is_unemployed)
    {
        int chance = rand() % 100;
        if (chance < static_cast<int>(world.crisis_probability))
        {
            bob.salary = static_cast<RUB>(bob.salary * 0.8);
            bob.stress_index += 5;
        }
    }
}


void bob_change_job()
{
    if (!bob.is_unemployed && (rand() % 1000) < 3)
    {
        RUB old_salary = bob.salary;
        bob.salary = static_cast<RUB>(bob.salary * 0.9);
        bob.stress_index += 5;
    }
}


void bob_burnout()
{
    if (bob.stress_index > 50)
    {
        bob.salary = static_cast<RUB>(bob.salary * 0.95);
        bob.stress_index += 2;
    }
}


void bob_invest_in_stocks()
{
    if (bob.capital > 50'000)
    {
        RUB invest = bob.capital / 2;
        bob.capital -= invest;
        bob.stock_investment_amount += invest;
    }
}


void bob_apply_stock_return()
{
    double random_factor = ((rand() % 200) - 100) / 100.0;
    percent monthly_return = bob.stock_return_rate / 12.0;
    percent volatility_effect = bob.stock_volatility * random_factor / 12.0;

    RUB profit = static_cast<RUB>(bob.stock_investment_amount * (monthly_return + volatility_effect));
    bob.stock_investment_amount += profit;
    bob.total_stock_profit += profit;

    if (profit < 0) bob.stress_index += 2;
}


void bob_panic_sell()
{
    if (bob.stock_investment_amount > 0 && rand() % 100 < 5)
    {
        RUB loss = bob.stock_investment_amount / 10;
        bob.stock_investment_amount -= loss;
        bob.capital += bob.stock_investment_amount;
        bob.total_stock_profit -= loss;
        bob.stress_index += 5;
    }
}


void bob_rebalance_portfolio()
{
    if (bob.stock_investment_amount > 100'000)
    {
        RUB sell = bob.stock_investment_amount / 4;
        bob.capital += sell;
        bob.stock_investment_amount -= sell;
    }
}


void bob_check_child_birth()
{
    int random_value = rand() % 1000;
    if (random_value < 3)
    {
        bob.children_count++;
        bob.stress_index += 5;
    }
}


void bob_pay_children_expenses()
{
    RUB total = bob.children_count * bob.child_monthly_expense;
    bob.capital -= total;

    if (bob.capital < 0)
        bob.stress_index += 5;
}


void bob_child_preschool()
{
    for (int i = 0; i < bob.children_count; ++i)
    {
        int chance = rand() % 100;
        if (chance < 70)
        {
            RUB cost = 10'000 + rand() % 5'000;
            bob.capital -= cost;
            if (bob.capital < 0)
                bob.stress_index += 2;
        }
    }
}


void bob_child_school()
{
    for (int i = 0; i < bob.children_count; ++i)
    {
        int chance = rand() % 100;
        if (chance < 100)
        {
            RUB cost = 15'000 + rand() % 10'000;
            bob.capital -= cost;
            if (bob.capital < 0)
                bob.stress_index += 3;
        }
    }
}


void bob_child_university()
{
    for (int i = 0; i < bob.children_count; ++i)
    {
        int chance = rand() % 100;
        if (chance < 50)
        {
            RUB cost = 50'000 + rand() % 50'000;
            bob.capital -= cost;
            if (bob.capital < 0)
                bob.stress_index += 5;
        }
    }
}


void bob_maternity_leave()
{
    for (int i = 0; i < bob.children_count; ++i)
    {
        int chance = rand() % 100;
        if (chance < 5)
        {
            RUB lost_salary = static_cast<RUB>(bob.salary * 0.5);
            bob.capital -= lost_salary;
            bob.stress_index += 5;
        }
    }
}
    

void bob_stress_from_debt()
{
    if (bob.credit.sumcredit > 1'000'000)
        bob.stress_index += 5;
}


void bob_stress_from_liquidity()
{
    if (bob.capital + bob.deposit.amount < 200'000)
        bob.stress_index += 3;
}


void bob_stress_from_rent()
{
    if (bob.rent > 50'000)
        bob.stress_index += 2;
}


void bob_stress_from_children()
{
    if (bob.children_count > 2)
        bob.stress_index += 3;
}


void bob_calculate_total_stress()
{
    bob_stress_from_debt();
    bob_stress_from_liquidity();
    bob_stress_from_rent();
    bob_stress_from_children();

    if (bob.stress_index > 100)
    {
        bob.salary = static_cast<RUB>(bob.salary * 0.95);
        bob.stress_index = 100;
    }
}


void bob_random_large_expense()
{
    int chance = rand() % 100;
    if (chance < 5)
    {
        RUB expense = 100'000 + rand() % 400'000;
        bob.capital -= expense;
        bob.stress_index += 5;
    }
}


void bob_random_bonus_or_inheritance()
{
    int chance = rand() % 100;
    if (chance < 5)
    {
        RUB gain = 200'000 + rand() % 500'000;
        bob.capital += gain;
        bob.stress_index -= 3;
    }
}


void bob_rent_increase(const World& world)
{
    int chance = rand() % 100;

    if (chance < 10)
    {
        percent inflation = world.inflation_rate;

        bob.rent = static_cast<RUB>(
            bob.rent * (1 + inflation / 100.0)
            );

        bob.stress_index += 3;
    }
}


void bob_move_to_new_apartment(const World& world)
{
    int chance = rand() % 100;

    if (chance < 4)
    {
        RUB moving_cost = 90'000;

        percent inflation = world.inflation_rate;

        moving_cost = static_cast<RUB>(
            moving_cost * (1 + inflation / 100.0)
            );

        bob.capital -= moving_cost;

        bob.stress_index += 4;
    }
}


void bob_security_deposit_loss(const World& world)
{
    int chance = rand() % 100;

    if (chance < 2)
    {
        RUB loss = 50'000;

        percent inflation = world.inflation_rate;

        loss = static_cast<RUB>(
            loss * (1 + inflation / 100.0)
            );

        bob.capital -= loss;

        bob.stress_index += 2;
    }
}


void bob_buy_laptop(const World& world)
{
    int chance = rand() % 100;

    if (chance < 5)
    {
        RUB cost = 110'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        bob.capital -= cost;
    }
}


void bob_small_repair(const World& world)
{
    int chance = rand() % 100;

    if (chance < 6)
    {
        RUB cost = 20'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        bob.capital -= cost;
    }
}


void bob_visit_friends()
{
    int chance = rand() % 100;

    if (chance < 8)
    {
        RUB cost = 8'000;

        bob.capital -= cost;
    }
}


void bob_phone_break(const World& world)
{
    int chance = rand() % 100;

    if (chance < 4)
    {
        RUB cost = 60'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        bob.capital -= cost;

        bob.stress_index += 2;
    }
}


void bob_gift_parents()
{
    int chance = rand() % 100;

    if (chance < 7)
    {
        RUB gift = 12'000;

        bob.capital -= gift;

        bob.stress_index -= 2;
    }
}


void bob_medical_expense(const World& world)
{
    int chance = rand() % 100;

    if (chance < 5)
    {
        RUB cost = 30'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        bob.capital -= cost;

        bob.stress_index += 2;
    }
}


void bob_sell_old_items()
{
    int chance = rand() % 100;

    if (chance < 5)
    {
        RUB income = 9'000;

        bob.capital += income;
    }
}


void bob_take_vacation(const World& world)
{
    int chance = rand() % 100;

    if (chance < 5)
    {
        RUB cost = 120'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        bob.capital -= cost;
    }
}


void bob_take_courses(const World& world)
{
    int chance = rand() % 100;

    if (chance < 4)
    {
        RUB cost = 60'000;

        percent inflation = world.inflation_rate;

        cost = static_cast<RUB>(cost * (1 + inflation / 100.0));

        bob.capital -= cost;
    }
}


RUB bob_calculate_net_worth()
{
    RUB assets = 0;
    RUB liabilities = 0;

    assets += bob.capital;
    assets += bob.deposit.amount;
    assets += bob.car.value;
    assets += bob.stock_investment_amount;
    assets += bob.apartment.value;

    liabilities += bob.credit.sumcredit;
    liabilities += bob.apartment.mortgage_debt;

    return assets - liabilities;
}


void bob_make_year_report(int year)
{
    YearlyReport report;

    report.year = year;
    report.capital = bob.capital;
    report.deposit = bob.deposit.amount;
    report.car_value = bob.car.value;
    report.credit = bob.credit.sumcredit;
    report.mortgage_debt = 0;
    report.stock_value = bob.stock_investment_amount;
    report.rent_paid = bob.total_rent_paid;
    report.mortgage_paid = 0;
    report.interest_paid = 0;
    report.property_tax_paid = 0;
    report.stress_index = bob.stress_index;

    RUB assets =
        bob.capital +
        bob.deposit.amount +
        bob.car.value +
        bob.stock_investment_amount;

    RUB liabilities =
        bob.credit.sumcredit;

    report.net_worth = assets - liabilities;

    report_bob.push_back(report);
}


    void simulate_alice(const World& world, int start_year, int simulation_years)
    {
        int year = start_year;
        int month = 1;
        int end_year = start_year + simulation_years;

        while (!(year == end_year && month == 1))
        {
            alice.capital += alice.salary;
            alice_check_job_loss();
            alice_process_unemployment();
            alice_check_annual_raise(month);
            alice_random_bonus();
            alice_overtime_pay();
            alice_salary_shock(world);
            alice_change_job();
            alice_burnout();

            alice_pay_food(world);
            alice_pay_car_expenses(world);
            alice_depreciate_car();
            alice_pay_credit();

            alice_check_child_birth();
            alice_pay_children_expenses();
            alice_child_preschool();
            alice_child_school();
            alice_child_university();
            alice_maternity_leave();

            alice_invest_in_stocks();
            alice_apply_stock_return();
            alice_panic_sell();
            alice_rebalance_portfolio();

            alice_calculate_total_stress();

            alice_random_large_expense();
            alice_random_bonus_or_inheritance();

            alice_buy_furniture(world);
            alice_appliance_break(world);
            alice_neighbor_flood(world);
            alice_lost_keys(world);
            alice_install_security(world);


            alice_buy_home_decor(world);
            alice_buy_phone(world);
            alice_family_gift();
            alice_lost_wallet();
            alice_go_to_conference(world);
            alice_medical_expense(world);
            alice_sell_old_items();
            alice_take_vacation(world);
            alice_take_courses(world);

            if (month == 12)
            {
                bob_make_year_report(year);
                year++;
            }

            month++;
        }
    }


    void simulate_bob(const World& world, int start_year, int simulation_years)
    {
        int year = start_year;
        int month = 1;
        int end_year = start_year + simulation_years;

        while (!(year == end_year && month == 1))
        {
            bob.capital += bob.salary;
            
            bob_check_job_loss();
            bob_process_unemployment();
            bob_check_annual_raise(month);
            bob_random_bonus();
            bob_overtime_pay();
            bob_salary_shock(world);
            bob_change_job();
            bob_burnout();

            bob_pay_food();
            bob_pay_car_expenses();
            bob_depreciate_car();
            bob_pay_rent();

            bob_check_child_birth();
            bob_pay_children_expenses();
            bob_child_preschool();
            bob_child_school();
            bob_child_university();
            bob_maternity_leave();

            bob_invest_in_stocks();
            bob_apply_stock_return();
            bob_panic_sell();
            bob_rebalance_portfolio();
  
            bob_calculate_total_stress();

            bob_random_large_expense();
            bob_random_bonus_or_inheritance();

            bob_rent_increase(world);
            bob_move_to_new_apartment(world);
            bob_security_deposit_loss(world);

            bob_buy_laptop(world);
            bob_small_repair(world);
            bob_visit_friends();
            bob_phone_break(world);
            bob_gift_parents();
            bob_medical_expense(world);
            bob_sell_old_items();
            bob_take_vacation(world);
            bob_take_courses(world);

            if (month == 12)
            {
                bob_make_year_report(year);
                year++;
            }

            month++;
            if (month > 12) month = 1;
        }
    }


    void print_alice_report() {
        std::cout << "=== Yearly Report Alice ===\n";
        std::cout << "Year | Capital | Deposit | Car | Credit | Mortgage | Stocks | Rent Paid | Mortgage Paid | Interest Paid | Property Tax | Net Worth\n";

        for (const auto& report : report_alice) {
            std::cout
                << report.year << " | "
                << report.capital << " | "
                << report.deposit << " | "
                << report.car_value << " | "
                << report.credit << " | "
                << report.mortgage_debt << " | "
                << report.stock_value << " | "
                << report.rent_paid << " | "
                << report.mortgage_paid << " | "
                << report.interest_paid << " | "
                << report.property_tax_paid << " | "
                << report.net_worth
                << "\n";
        }
    }


    void print_bob_report() {
        std::cout << "=== Yearly Report Bob ===\n";
        std::cout << "Year | Capital | Deposit | Car | Credit | Mortgage | Stocks | Rent Paid | Mortgage Paid | Interest Paid | Property Tax | Net Worth\n";

        for (const auto& report : report_bob) {
            std::cout
                << report.year << " | "
                << report.capital << " | "
                << report.deposit << " | "
                << report.car_value << " | "
                << report.credit << " | "
                << report.mortgage_debt << " | "
                << report.stock_value << " | "
                << report.rent_paid << " | "
                << report.mortgage_paid << " | "
                << report.interest_paid << " | "
                << report.property_tax_paid << " | "
                << report.net_worth
                << "\n";
        }
    }

    void compare_strategies() {
        std::cout << "=== Comparison of Alice and Bob Strategies ===\n";
std::cout << "Year | Alice Capital | Bob Capital | Alice Deposit | Bob Deposit | Alice Car | Bob Car | Alice Credit | Bob Credit | Alice Mortgage | Alice Stocks | Bob Stocks | Alice Stress | Bob Stress | Alice Net Worth | Bob Net Worth\n";
        size_t years = std::min(report_alice.size(), report_bob.size());

        for (size_t i = 0; i < years; ++i) {
            const auto& alice_report = report_alice[i];
            const auto& bob_report = report_bob[i];

            std::cout
                << alice_report.year << " | "
                << alice_report.capital << " | "
                << bob_report.capital << " | "
                << alice_report.deposit << " | "
                << bob_report.deposit << " | "
                << alice_report.car_value << " | "
                << bob_report.car_value << " | "
                << alice_report.credit << " | "
                << bob_report.credit << " | "
                << alice_report.mortgage_debt << " | "
                << alice_report.stock_value << " | "
                << bob_report.stock_value << " | "
                << alice_report.stress_index << " | " 
                << bob_report.stress_index << " | " 
                << alice_report.net_worth << " | "
                << bob_report.net_worth
                << "\n";
        }
    }

    void analyze_alice_bob()
{
    size_t years = std::min(report_alice.size(), report_bob.size());

    int alice_richer_years = 0;
    int bob_richer_years = 0;
    int alice_less_stress_years = 0;
    int bob_less_stress_years = 0;

    std::cout << "=== Yearly Analysis: Alice vs Bob ===\n";
    std::cout << "Year | Richer | Less Stress\n";

    for (size_t i = 0; i < years; ++i)
    {
        const auto& alice_report = report_alice[i];
        const auto& bob_report = report_bob[i];

        std::string richer;
        std::string less_stress;

        if (alice_report.net_worth > bob_report.net_worth)
        {
            richer = "Alice";
            alice_richer_years++;
        }
        else if (bob_report.net_worth > alice_report.net_worth)
        {
            richer = "Bob";
            bob_richer_years++;
        }
        else
        {
            richer = "Equal";
        }

        if (alice_report.stress_index < bob_report.stress_index)
        {
            less_stress = "Alice";
            alice_less_stress_years++;
        }
        else if (bob_report.stress_index < alice_report.stress_index)
        {
            less_stress = "Bob";
            bob_less_stress_years++;
        }
        else
        {
            less_stress = "Equal";
        }

        std::cout
            << alice_report.year << " | "
            << richer << " | "
            << less_stress
            << "\n";
    }

    // Общий анализ
    std::cout << "\n=== Overall Analysis ===\n";
    std::cout << "Alice richer in " << alice_richer_years << " years, Bob in " << bob_richer_years << " years.\n";
    std::cout << "Alice less stressed in " << alice_less_stress_years << " years, Bob in " << bob_less_stress_years << " years.\n";

    if (alice_richer_years > bob_richer_years)
        std::cout << "Overall, Alice is richer.\n";
    else if (bob_richer_years > alice_richer_years)
        std::cout << "Overall, Bob is richer.\n";
    else
        std::cout << "Overall, wealth is equal.\n";

    if (alice_less_stress_years > bob_less_stress_years)
        std::cout << "Overall, Alice is less stressed.\n";
    else if (bob_less_stress_years > alice_less_stress_years)
        std::cout << "Overall, Bob is less stressed.\n";
    else
        std::cout << "Overall, stress levels are equal.\n";
}


    int main() {
    
        alice_init();
        bob_init();

        World world = world_init(); 

        simulate_alice(world, 2026, 30);
        simulate_bob(world, 2026, 30);

        print_alice_report();
        print_bob_report();
        compare_strategies();

        analyze_alice_bob();

        return 0;
    }
  
