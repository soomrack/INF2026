#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime>

using RUB = long long int;          // Тип для хранения денежных значений в рублях
const RUB CASH_LIMIT = 100'000;     // Лимит наличных денег
using percent = double;              // Тип для хранения процентов

// ================== СТРУКТУРЫ ==================

struct Car {
    RUB value;      // Текущая стоимость автомобиля
    RUB gas;        // Ежемесячные расходы на бензин
};

struct Job {
    RUB salary;                     // Зарплата
    percent fire_probability;        // Вероятность увольнения
    percent raise_probability;       // Вероятность внепланового повышения
    percent annual_raise_percent;    // Годовой процент повышения
    int raise_month;                // Месяц ежегодного повышения
};

struct World {
    percent inflation_rate;          // Годовая инфляция
    percent crisis_probability;      // Вероятность экономического кризиса
    percent crisis_impact_percent;   // Насколько сильно кризис влияет на активы
    percent apartment_growth_rate;   // Рост стоимости недвижимости
};

struct Deposit {
    RUB amount;         // Сумма депозита
    percent annual_rate; // Годовая ставка
    int months_left;    // Срок вклада в месяцах
    bool replenishable; // Можно ли пополнять вклад
};

struct Credit {
    RUB sumcredit;          // Остаток долга
    RUB monthly_payment;    // Ежемесячный платёж
    percent interest_rate;   // Процентная ставка
    int months_left;        // Остаток срока кредита
};

struct Investment {
    RUB amount;             // Сумма инвестиций
    percent expected_return; // Ожидаемая доходность
    percent risk;            // Уровень риска
};

struct YearlyReport {
    int year;                   // год отчёта
    RUB net_worth;              // чистый капитал
    RUB capital;                // наличные деньги
    RUB deposit;                
    RUB car_value;              
    RUB credit;                 // Остаток кредита
    RUB mortgage_debt;          // Остаток ипотеки
    RUB stock_value;            // стоимость инвестиций
    RUB rent_paid;              // сколько уплачено аренды
    RUB mortgage_paid;          // сколько уплачено по ипотеке
    RUB interest_paid;          // сколько уплачено процентов
    RUB property_tax_paid;      // налог на имущество
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

    int children_count;         
    RUB child_monthly_expense;  

    percent early_mortgage_payment_rate; // процент досрочного погашения
    RUB total_early_mortgage_paid;      // сколько досрочно погашено

    RUB stock_investment_amount; // инвестиции в акции
    percent stock_return_rate;    // доходность акций
    percent stock_volatility;     // волатильность
    RUB total_stock_profit;      // общая прибыль от акций

    bool is_unemployed;          // безработный ли человек
    int unemployed_months_left;  // сколько месяцев без работы

    RUB mortgage_debt;           // остаток ипотеки

    RUB apartment_value;         
    RUB total_mortgage_paid;     // сколько всего уплачено по ипотеке
    RUB total_interest_paid;     // сколько уплачено процентов
    RUB total_property_tax_paid; // налог на имущество
    RUB total_rent_paid;         // сколько уплачено аренды
    RUB total_repair_paid;       // сколько потрачено на ремонт
    RUB insurance_paid;          // страховка
    RUB stress_index;            // индекс стресса
    RUB liquidity_reserve;       // финансовая подушка
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
    alice.deposit.replenishable = true;  // можно пополнять

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

    alice.mortgage_debt = 12'000'000;     // Ипотека

    alice.stock_investment_amount = 0;
    alice.stock_return_rate = 0.10;
    alice.stock_volatility = 0.15;
    alice.total_stock_profit = 0;

    alice.is_unemployed = false;
    alice.unemployed_months_left = 0;

    alice.apartment_value = 12'000'000;   // Стоимость квартиры
    alice.total_mortgage_paid = 0;
    alice.total_interest_paid = 0;
    alice.total_property_tax_paid = 0;
    alice.total_rent_paid = 0;
    alice.total_repair_paid = 0;
    alice.insurance_paid = 0;
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
    bob.deposit.replenishable = true; // можно пополнять

    bob.job.salary = 180'000;        // зарплата по контракту
    bob.job.fire_probability = 2.0;  // вероятность увольнения
    bob.job.raise_probability = 5.0; // вероятность повышения
    bob.job.annual_raise_percent = 7.5; // годовой рост зарплаты
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

    bob.mortgage_debt = 0;          // ипотеки нет

    bob.apartment_value = 0;        // квартиры нет
    bob.total_mortgage_paid = 0;
    bob.total_interest_paid = 0;
    bob.total_property_tax_paid = 0;
    bob.total_rent_paid = 0;
    bob.total_repair_paid = 0;
    bob.insurance_paid = 0;
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


void alice_pay_food()
{
    alice.capital -= alice.food;         // списываем деньги на еду
    if (alice.capital < 0)               // стресс, если ушли в минус
        alice.stress_index += 2;
}


void alice_pay_car_expenses()
{
    alice.capital -= alice.car.gas;
    if (alice.capital < 0)
        alice.stress_index += 1;
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


void alice_pay_mortgage_month()
{
    if (alice.mortgage_debt <= 0) return; // если ипотека погашена

    percent monthly_rate = 9.0 / 12.0; // годовая ставка 9 процентов
    RUB interest = static_cast<RUB>(alice.mortgage_debt * (monthly_rate / 100.0)); // проценты за месяц

    RUB principal_payment = 67'000; // фиксированное тело кредита

    alice.capital -= (principal_payment + interest); // списываем деньги
    alice.mortgage_debt -= principal_payment;        // уменьшаем долг

    alice.total_mortgage_paid += principal_payment;  // учёт уплаченного тела
    alice.total_interest_paid += interest;           // учёт процентов

    if (alice.mortgage_debt < 0)
        alice.mortgage_debt = 0;

    if (alice.capital < 0)
        alice.stress_index += 5; // стресс если ушли в минус
}


void alice_early_repayment()
{
    if (alice.capital > 300'000 && alice.mortgage_debt > 0)
    {
        RUB extra = static_cast<RUB>(alice.capital * (alice.early_mortgage_payment_rate / 100.0));

        alice.capital -= extra;
        alice.mortgage_debt -= extra;
        alice.total_early_mortgage_paid += extra;

        if (alice.mortgage_debt < 0)
            alice.mortgage_debt = 0;
    }
}


void alice_apartment_growth(const World& world)
{
    percent growth = world.apartment_growth_rate;
    alice.apartment_value = static_cast<RUB>(
        alice.apartment_value * (1 + growth / 100.0)
        );
}


void alice_property_tax()
{
    percent tax_rate = 0.1; // 0.1 процента от стоимости
    RUB tax = static_cast<RUB>(alice.apartment_value * (tax_rate / 100.0));

    alice.capital -= tax;
    alice.total_property_tax_paid += tax;

    if (alice.capital < 0)
        alice.stress_index += 2;
}


void alice_pay_insurance()
{
    RUB insurance = 50'000; // ежегодная страховка

    alice.capital -= insurance;
    alice.insurance_paid += insurance;

    if (alice.capital < 0)
        alice.stress_index += 1;
}


void alice_random_repair()
{
    int chance = rand() % 100;

    if (chance < 10) // 10 процентов вероятность
    {
        RUB repair_cost = 200'000 + rand() % 300'000;

        alice.capital -= repair_cost;
        alice.total_repair_paid += repair_cost;
        alice.stress_index += 4;
    }
}


void alice_check_crisis(const World& world)
{
    int chance = rand() % 100;

    if (chance < world.crisis_probability)
    {
        percent drop = world.crisis_impact_percent;

        alice.apartment_value = static_cast<RUB>(
            alice.apartment_value * (1 - drop / 100.0)
            );

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

    if (alice.mortgage_debt > 5'000'000)
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


RUB alice_calculate_net_worth()
{
    RUB assets = 0;
    RUB liabilities = 0;

    // активы
    assets += alice.capital;                  // наличные
    assets += alice.deposit.amount;           // депозит
    assets += alice.car.value;                // машина
    assets += alice.stock_investment_amount; // акции
    assets += alice.apartment_value;          // недвижимость

    // обязательства
    liabilities += alice.credit.sumcredit;    // кредиты
    liabilities += alice.mortgage_debt;      // ипотека

    return assets - liabilities;              // net worth
}


void alice_make_year_report(int year)
{
    YearlyReport report;

    report.year = year;
    report.capital = alice.capital;
    report.deposit = alice.deposit.amount;
    report.car_value = alice.car.value;
    report.credit = alice.credit.sumcredit;
    report.mortgage_debt = alice.mortgage_debt;
    report.stock_value = alice.stock_investment_amount;
    report.rent_paid = alice.total_rent_paid;
    report.mortgage_paid = alice.total_mortgage_paid;
    report.interest_paid = alice.total_interest_paid;
    report.property_tax_paid = alice.total_property_tax_paid;
    report.stress_index = alice.stress_index;

    RUB assets = alice.capital +
        alice.deposit.amount +
        alice.car.value +
        alice.stock_investment_amount +
        alice.apartment_value;

    RUB liabilities = alice.credit.sumcredit + alice.mortgage_debt;

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


RUB bob_calculate_net_worth()
{
    RUB assets = 0;
    RUB liabilities = 0;

    // активы
    assets += bob.capital;                    // наличные
    assets += bob.deposit.amount;             // депозит
    assets += bob.car.value;                  // машина
    assets += bob.stock_investment_amount;   // акции
    assets += bob.apartment_value;            // недвижимость

    // обязательства
    liabilities += bob.credit.sumcredit;      // кредиты
    liabilities += bob.mortgage_debt;        // ипотека (у Боба 0, если нет ипотеки)

    return assets - liabilities;              // net worth
}


void bob_make_year_report(int year)
{
    YearlyReport report;

    report.year = year;
    report.capital = bob.capital;
    report.deposit = bob.deposit.amount;
    report.car_value = bob.car.value;
    report.credit = bob.credit.sumcredit;
    report.mortgage_debt = 0; // ипотеки нет у Боба
    report.stock_value = bob.stock_investment_amount;
    report.rent_paid = bob.total_rent_paid; // учитываем аренду
    report.mortgage_paid = 0; // ипотеки нет у Боба
    report.interest_paid = bob.total_interest_paid; // проценты по кредитам
    report.property_tax_paid = 0; // нет недвижимости
    report.stress_index = bob.stress_index;

    // расчёт net_worth: активы - обязательства
    RUB assets = bob.capital +
        bob.deposit.amount +
        bob.car.value +
        bob.stock_investment_amount;

    RUB liabilities = bob.credit.sumcredit; // ипотека отсутствует

    report.net_worth = assets - liabilities;

    // добавляем в глобальный отчёт
    report_bob.push_back(report);
}


    void simulate_alice(const World& world, int start_year, int simulation_years)
    {
        int year = start_year;
        int month = 1;

        while (year < start_year + simulation_years)
        {
            alice.capital += alice.salary;
            // работа
            alice_check_job_loss();
            alice_process_unemployment();
            alice_check_annual_raise(month);
            alice_random_bonus();
            alice_overtime_pay();
            alice_salary_shock(world);
            alice_change_job();
            alice_burnout();

            // расходы
            alice_pay_food();
            alice_pay_car_expenses();
            alice_depreciate_car();
            alice_pay_credit();

            // дети и семья
            alice_check_child_birth();
            alice_pay_children_expenses();
            alice_child_preschool();
            alice_child_school();
            alice_child_university();
            alice_maternity_leave();

            // инвестиции
            alice_invest_in_stocks();
            alice_apply_stock_return();
            alice_panic_sell();
            alice_rebalance_portfolio();

            // стресс
            alice_calculate_total_stress();

            // случайные события
            alice_random_large_expense();
            alice_random_bonus_or_inheritance();

            // если декабрь — делаем годовой отчёт
            if (month == 12)
            {
                alice_make_year_report(year);
                year++;
            }

            month++;
            if (month > 12) month = 1;
        }
    }


    void simulate_bob(const World& world, int start_year, int simulation_years)
    {
        int year = start_year;
        int month = 1;

        while (year < start_year + simulation_years)
        {
            bob.capital += bob.salary;
            // работа
            bob_check_job_loss();
            bob_process_unemployment();
            bob_check_annual_raise(month);
            bob_random_bonus();
            bob_overtime_pay();
            bob_salary_shock(world);
            bob_change_job();
            bob_burnout();

            // расходы
            bob_pay_food();
            bob_pay_car_expenses();
            bob_depreciate_car();
            bob_pay_rent();

            // дети и семья
            bob_check_child_birth();
            bob_pay_children_expenses();
            bob_child_preschool();
            bob_child_school();
            bob_child_university();
            bob_maternity_leave();

            // инвестиции
            bob_invest_in_stocks();
            bob_apply_stock_return();
            bob_panic_sell();
            bob_rebalance_portfolio();

            // стресс
            bob_calculate_total_stress();

            // случайные события
            bob_random_large_expense();
            bob_random_bonus_or_inheritance();

            // если декабрь — делаем годовой отчёт
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


    int main() {
    
        alice_init();
        bob_init();

        World world = world_init(); 

        simulate_alice(world, 2026, 30);
        simulate_bob(world, 2026, 30);

        print_alice_report();
        print_bob_report();
        compare_strategies();

        return 0;
    }
