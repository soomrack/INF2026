#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using RUB = long long int;
using percent = double;
using chance = double;

// ---------- Структуры данных ----------
struct Car {
    RUB value;
    double fuel_price;
    float fuel_consumption;
    RUB annual_car_tax;
    RUB insurance_osago;
    RUB insurance_kasko;
    RUB maintenance_cost_per_year;
    float iznos_procent = 5;
};

struct Home {
    RUB value;
    RUB monthly_rent;           // арендная плата (если сдаётся – доход, если снимается – расход)
    double rent_indexation;      // ежегодная индексация аренды
    RUB security_deposit;        // депозит (залог)
    RUB utilities;               // коммунальные услуги за месяц
    RUB parking_lot;             // цена за парковку в месяц
};

struct Job {
    RUB salary;
    chance fire_probability;
    chance raise_probability;
    chance annual_raise_percent;
    int raise_month;
};

struct Deposit {
    RUB amount;
    percent annual_rate;
    int months_left;
};

struct Report {
    int year;
    RUB net_worth;
    RUB capital;
    RUB deposit;
    RUB car_value;
    RUB rent_paid;               // сколько уплачено аренды (за своё жильё)
    RUB property_tax_paid;       // налог на недвижимость (за сдаваемую квартиру)
    RUB stress_index;
};

struct Person {
    int age;
    int birthday_month;

    Job job;
    RUB capital;

    RUB food;
    double food_indexation;

    RUB mobile_services;
    double mobile_indexation;

    RUB healthcare;
    double healthcare_indexation;

    RUB entertainment;
    double entertainment_indexation;

    RUB clothing;
    double clothing_indexation;

    RUB unexpected;              

    Car camry;
    Deposit deposit;
    Home flat_1;                   // квартира, в которой живёт (арендует)
    Home flat_2;                   // квартира, которую сдаёт (инвестиционная)
    double avg_monthly_mileage;    

    bool is_unemployed;
    int unemployed_months_left;
    RUB stress_index;
    RUB total_rent_paid;           
    RUB total_property_tax_paid;    
    RUB total_rent_income;          
};

// ---------- Глобальные переменные ----------
std::vector<Report> report_alice;
Person alice;

struct World {
    percent inflation_rate;          // годовая инфляция (например, 8.0)
    percent crisis_probability;      // вероятность кризиса в год (процентов)
    percent crisis_impact_percent;   // падение стоимости активов при кризисе
    percent housing_price_growth;    // рост цен на жильё (для налога, если нужно)
    percent stock_market_volatility; // волатильность для инвестиций
};

World world;

// ---------- Инициализация ----------
void world_init() {
    world.inflation_rate = 7.5;
    world.crisis_probability = 2.5;
    world.crisis_impact_percent = 20.0;
    world.housing_price_growth = 4.0;
    world.stock_market_volatility = 15.0;
}

void alice_init() {
    alice.job.salary = 180'000;
    alice.job.fire_probability = 1.5;
    alice.job.annual_raise_percent = 9.5;
    alice.job.raise_month = 7;

    alice.deposit.amount = 0;
    alice.deposit.annual_rate = 13.5;
    alice.deposit.months_left = 6;

    alice.age = 30;
    alice.birthday_month = 5;

    alice.capital = 500'000;  // начальный капитал

    alice.food = 25'000;
    alice.food_indexation = 1.05;
    alice.mobile_services = 2'000;
    alice.mobile_indexation = 1.03;
    alice.healthcare = 5'000;
    alice.healthcare_indexation = 1.06;
    alice.entertainment = 15'000;
    alice.entertainment_indexation = 1.04;
    alice.clothing = 8'000;
    alice.clothing_indexation = 1.04;
    alice.unexpected = 10'000;

    alice.camry.value = 5'000'000;
    alice.camry.fuel_price = 64.7;
    alice.camry.fuel_consumption = 11.1;
    alice.camry.annual_car_tax = 18'600;
    alice.camry.insurance_osago = 10'500;
    alice.camry.insurance_kasko = 30'000;
    alice.camry.maintenance_cost_per_year = 15'000;
    alice.camry.iznos_procent = 5;

    alice.flat_1.monthly_rent = 60'000;
    alice.flat_1.rent_indexation = 1.04;
    alice.flat_1.security_deposit = 60'000;
    alice.flat_1.utilities = 7'500;
    alice.flat_1.parking_lot = 5'000;

    alice.flat_2.value = 8'000'000;
    alice.flat_2.monthly_rent = 65'000;
    alice.flat_2.rent_indexation = 1.04;
    alice.flat_2.security_deposit = 65'000;
    alice.flat_2.utilities = 8'500;
    alice.flat_2.parking_lot = 6'000;

    alice.avg_monthly_mileage = 1200;  
    alice.is_unemployed = false;
    alice.unemployed_months_left = 0;
    alice.stress_index = 0;
    alice.total_rent_paid = 0;
    alice.total_property_tax_paid = 0;
    alice.total_rent_income = 0;
}

// ---------- Работа и доходы ----------
void alice_check_job_loss() {
    if (alice.is_unemployed) return;
    double monthly_fire_prob = alice.job.fire_probability / 12.0;
    if ((rand() % 10000) / 100.0 < monthly_fire_prob) {
        alice.is_unemployed = true;
        alice.unemployed_months_left = 6;  
        alice.stress_index += 10;
    }
}

void alice_process_unemployment() {
    if (!alice.is_unemployed) return;
    alice.job.salary = 0;
    alice.unemployed_months_left--;
    if (alice.unemployed_months_left <= 0) {
        alice.is_unemployed = false;
        alice.job.salary = 150'000;  // находим новую работу с зарплатой ниже
        alice.stress_index -= 5;
    }
    else {
        alice.stress_index += 2;
    }
}

void alice_check_annual_raise(int month) {
    if (alice.is_unemployed) return;
    if (month == alice.job.raise_month) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * (1 + alice.job.annual_raise_percent / 100.0));
        alice.stress_index -= 5;
    }
}

void alice_random_bonus() {
    if (alice.is_unemployed) return;
    if ((rand() % 100) < 20) {  
        RUB bonus = 30'000 + rand() % 70'000;
        alice.capital += bonus;
        alice.stress_index -= 2;
    }
}

void alice_overtime_pay() {
    if (alice.is_unemployed) return;
    if ((rand() % 100) < 25) { 
        RUB overtime = 10'000 + rand() % 30'000;
        alice.capital += overtime;
        alice.stress_index += 1;  
    }
}

void alice_salary_shock() {
    if (alice.is_unemployed) return;
    double monthly_crisis_prob = world.crisis_probability / 12.0;
    if ((rand() % 10000) / 100.0 < monthly_crisis_prob) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.85); 
        alice.stress_index += 5;
    }
}

void alice_change_job() {
    if (alice.is_unemployed) return;
    if ((rand() % 1000) < 3) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.95);  
        alice.stress_index += 3;
    }
}

void alice_burnout() {
    if (alice.stress_index > 60) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.97);
        alice.stress_index += 1;
    }
}

// ---------- Расходы (с индексацией) ----------
void alice_pay_food() {
    RUB cost = static_cast<RUB>(alice.food * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital -= cost;
    if (alice.capital < 0) alice.stress_index += 2;
}

void alice_pay_mobile() {
    RUB cost = static_cast<RUB>(alice.mobile_services * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital -= cost;
    if (alice.capital < 0) alice.stress_index += 1;
}

void alice_pay_healthcare() {
    RUB cost = static_cast<RUB>(alice.healthcare * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital -= cost;
    if (alice.capital < 0) alice.stress_index += 2;
}

void alice_pay_entertainment() {
    RUB cost = static_cast<RUB>(alice.entertainment * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital -= cost;
    if (alice.capital < 0) alice.stress_index += 1;
}

void alice_pay_clothing() {
    RUB cost = static_cast<RUB>(alice.clothing * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital -= cost;
    if (alice.capital < 0) alice.stress_index += 1;
}

void alice_pay_unexpected() {
    RUB cost = static_cast<RUB>(alice.unexpected * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital -= cost;
    if (alice.capital < 0) alice.stress_index += 2;
}

// ---------- Расходы на жильё (flat_1) ----------
void alice_pay_rent() {
    RUB rent = static_cast<RUB>(alice.flat_1.monthly_rent * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital -= rent;
    alice.total_rent_paid += rent;
    if (alice.capital < 0) alice.stress_index += 3;
}

void alice_pay_utilities() {
    RUB utils = static_cast<RUB>(alice.flat_1.utilities * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital -= utils;
    if (alice.capital < 0) alice.stress_index += 2;
}

void alice_pay_parking() {
    RUB parking = static_cast<RUB>(alice.flat_1.parking_lot * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital -= parking;
    if (alice.capital < 0) alice.stress_index += 1;
}

// ---------- Доходы и расходы от сдаваемой квартиры (flat_2) ----------
void alice_receive_rent() {
   
    RUB rent_income = static_cast<RUB>(alice.flat_2.monthly_rent * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital += rent_income;
    alice.total_rent_income += rent_income;


    RUB utils = static_cast<RUB>(alice.flat_2.utilities * (1 + world.inflation_rate / 100.0 / 12.0));
    RUB parking = static_cast<RUB>(alice.flat_2.parking_lot * (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital -= utils;
    alice.capital -= parking;
    if (alice.capital < 0) alice.stress_index += 2;
}

void alice_pay_property_tax() {

    RUB apartment_value = 8'000'000; 
    RUB tax = static_cast<RUB>(apartment_value * 0.003); // 0.3% в год
    // индексация налога по инфляции
    tax = static_cast<RUB>(tax * (1 + world.inflation_rate / 100.0));
    alice.capital -= tax / 12;  
    alice.total_property_tax_paid += tax / 12;
    if (alice.capital < 0) alice.stress_index += 2;
}

// ---------- Расходы на автомобиль ----------
void alice_pay_fuel() {
    RUB fuel_cost = static_cast<RUB>((alice.avg_monthly_mileage / 100.0) *
        alice.camry.fuel_consumption *
        alice.camry.fuel_price *
        (1 + world.inflation_rate / 100.0 / 12.0));
    alice.capital -= fuel_cost;
    if (alice.capital < 0) alice.stress_index += 2;
}

void alice_pay_car_tax() {
    RUB tax = static_cast<RUB>(alice.camry.annual_car_tax * (1 + world.inflation_rate / 100.0));
    alice.capital -= tax / 12;
    if (alice.capital < 0) alice.stress_index += 1;
}

void alice_pay_insurance_osago() {
    RUB ins = static_cast<RUB>(alice.camry.insurance_osago * (1 + world.inflation_rate / 100.0));
    alice.capital -= ins / 12;
    if (alice.capital < 0) alice.stress_index += 1;
}

void alice_pay_insurance_kasko() {
    RUB ins = static_cast<RUB>(alice.camry.insurance_kasko * (1 + world.inflation_rate / 100.0));
    alice.capital -= ins / 12;
    if (alice.capital < 0) alice.stress_index += 2;
}

void alice_pay_maintenance() {
    RUB maint = static_cast<RUB>(alice.camry.maintenance_cost_per_year * (1 + world.inflation_rate / 100.0));
    alice.capital -= maint / 12;
    if (alice.capital < 0) alice.stress_index += 1;
}

void alice_depreciate_car() {

    double monthly_iznos = alice.camry.iznos_procent / 12.0 / 100.0;
    alice.camry.value = static_cast<RUB>(alice.camry.value * (1.0 - monthly_iznos));
}

// ---------- Депозит ----------
void alice_update_deposit() {
    if (alice.deposit.amount > 0) {

        RUB interest = static_cast<RUB>(alice.deposit.amount * (alice.deposit.annual_rate / 100.0 / 12.0));
        alice.deposit.amount += interest;
        alice.deposit.months_left--;
        if (alice.deposit.months_left <= 0) {
            alice.capital += alice.deposit.amount;
            alice.deposit.amount = 0;

        }
    }
    // если есть свободные деньги, можно пополнить депозит
    if (alice.capital > 200'000) {
        RUB to_deposit = std::min(alice.capital / 2, static_cast<RUB>( 500'000));
        alice.capital -= to_deposit;
        alice.deposit.amount += to_deposit;
        alice.deposit.months_left = 12; // новый вклад на 12 месяцев
    }
}

// ---------- Стресс ----------
void alice_calculate_stress() {


    if (alice.capital < 100'000) alice.stress_index += 5;
    if (alice.capital < 0) alice.stress_index += 15;

    if (alice.deposit.amount < 200'000) alice.stress_index += 2;

    if (alice.camry.value < 2'000'000) alice.stress_index += 2; 


    if (alice.stress_index > 100) alice.stress_index = 100;
    if (alice.stress_index < 0) alice.stress_index = 0;

    if (alice.stress_index > 70 && !alice.is_unemployed) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.98);
    }
    else if (alice.stress_index > 80 && !alice.is_unemployed) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.95);
    }
    else if (alice.stress_index > 90 && !alice.is_unemployed) {
        alice.job.salary = static_cast<RUB>(alice.job.salary * 0.93);
    }
   
}

// ---------- Случайные события ----------
void alice_random_medical_expense() {
    if ((rand() % 100) < 5) { 
        RUB expense = 20'000 + rand() % 80'000;
        expense = static_cast<RUB>(expense * (1 + world.inflation_rate / 100.0));
        alice.capital -= expense;
        alice.stress_index += 3;
    }
}

void alice_random_car_repair() {
    if ((rand() % 100) < 4) { 
        RUB repair = 15'000 + rand() % 60'000;
        repair = static_cast<RUB>(repair * (1 + world.inflation_rate / 100.0));
        alice.capital -= repair;
        alice.stress_index += 4;
    }
}

void alice_random_vacation() {
    if ((rand() % 100) < 3) { 
        RUB cost = 50'000 + rand() % 150'000;
        cost = static_cast<RUB>(cost * (1 + world.inflation_rate / 100.0));
        alice.capital -= cost;
        alice.stress_index -= 5; 
    }
}

void alice_random_gift() {
    if ((rand() % 100) < 8) { 
        RUB gift = 5'000 + rand() % 20'000;
        alice.capital -= gift;
        alice.stress_index -= 1;
    }
}

void alice_random_inheritance() {
    if ((rand() % 1000) < 2) { 
        RUB inheritance = 200'000 + rand() % 800'000;
        alice.capital += inheritance;
        alice.stress_index -= 10;
    }
}

void alice_random_fine() {
    if ((rand() % 100) < 2) { 
        RUB fine = 2'000 + rand() % 15'000;
        alice.capital -= fine;
        alice.stress_index += 2;
    }
}

void alice_random_phone_break() {
    if ((rand() % 100) < 3) { 
        RUB cost = 30'000 + rand() % 70'000;
        cost = static_cast<RUB>(cost * (1 + world.inflation_rate / 100.0));
        alice.capital -= cost;
        alice.stress_index += 2;
    }
}

void alice_random_household_break() {
    if ((rand() % 100) < 4) { 
        RUB cost = 10'000 + rand() % 40'000;
        cost = static_cast<RUB>(cost * (1 + world.inflation_rate / 100.0));
        alice.capital -= cost;
        alice.stress_index += 2;
    }
}

// ---------- Годовые события ----------(ПЕределать)
/*void alice_annual_indexation() {
    alice.flat_2.value = static_cast<RUB>(alice.flat_2.value * (1 + world.inflation_rate / 100.0));

    alice.food = static_cast<RUB>(alice.food * (1 + world.inflation_rate / 100.0));
    alice.mobile_services = static_cast<RUB>(alice.mobile_services * (1 + world.inflation_rate / 100.0));
    alice.healthcare = static_cast<RUB>(alice.healthcare * (1 + world.inflation_rate / 100.0));
    alice.entertainment = static_cast<RUB>(alice.entertainment * (1 + world.inflation_rate / 100.0));
    alice.clothing = static_cast<RUB>(alice.clothing * (1 + world.inflation_rate / 100.0));
    alice.unexpected = static_cast<RUB>(alice.unexpected * (1 + world.inflation_rate / 100.0));

  
    alice.flat_1.monthly_rent = static_cast<RUB>(alice.flat_1.monthly_rent * alice.flat_1.rent_indexation);
    alice.flat_2.monthly_rent = static_cast<RUB>(alice.flat_2.monthly_rent * alice.flat_2.rent_indexation);

    alice.flat_1.utilities = static_cast<RUB>(alice.flat_1.utilities * (1 + world.inflation_rate / 100.0));
    alice.flat_2.utilities = static_cast<RUB>(alice.flat_2.utilities * (1 + world.inflation_rate / 100.0));
    alice.flat_1.parking_lot = static_cast<RUB>(alice.flat_1.parking_lot * (1 + world.inflation_rate / 100.0));
    alice.flat_2.parking_lot = static_cast<RUB>(alice.flat_2.parking_lot * (1 + world.inflation_rate / 100.0));


    alice.camry.fuel_price = static_cast<RUB>(alice.camry.fuel_price * (1 + world.inflation_rate / 100.0));


    alice.camry.annual_car_tax = static_cast<RUB>(alice.camry.annual_car_tax * (1 + world.inflation_rate / 100.0));
    alice.camry.insurance_osago = static_cast<RUB>(alice.camry.insurance_osago * (1 + world.inflation_rate / 100.0));
    alice.camry.insurance_kasko = static_cast<RUB>(alice.camry.insurance_kasko * (1 + world.inflation_rate / 100.0));
    alice.camry.maintenance_cost_per_year = static_cast<RUB>(alice.camry.maintenance_cost_per_year * (1 + world.inflation_rate / 100.0));
}*/

void alice_check_crisis() {

    if ((rand() % 100) < world.crisis_probability) {

        alice.flat_2.monthly_rent = static_cast<RUB>(alice.flat_2.monthly_rent * (1 - world.crisis_impact_percent / 100.0));
        alice.flat_2.value = static_cast<RUB>(alice.flat_2.value * (1 - world.crisis_impact_percent / 100.0));
        alice.camry.value = static_cast<RUB>(alice.camry.value * (1 - world.crisis_impact_percent / 100.0));
        alice.stress_index += 15;
    }
}

// ---------- Чистая стоимость и отчёт ----------
RUB alice_calculate_net_worth() {
    RUB assets = alice.capital + alice.deposit.amount + alice.camry.value + alice.flat_2.value;
    RUB liabilities = 0; 
    return assets - liabilities;
}

void alice_make_report(int year) {
    Report r;
    r.year = year;
    r.net_worth = alice_calculate_net_worth();
    r.capital = alice.capital;
    r.deposit = alice.deposit.amount;
    r.car_value = alice.camry.value;
    r.rent_paid = alice.total_rent_paid;
    r.property_tax_paid = alice.total_property_tax_paid;
    r.stress_index = alice.stress_index;
    report_alice.push_back(r);
}

// ---------- Основная симуляция ----------
void simulate_alice(int start_year, int years) {
    int year = start_year;
    int month = 1;


    while (year < start_year + years) {
        // Начисление зарплаты
        if (!alice.is_unemployed) {
            alice.capital += alice.job.salary;
        }

        // Работа
        alice_check_job_loss();
        alice_process_unemployment();
        alice_check_annual_raise(month);
        alice_random_bonus();
        alice_overtime_pay();
        alice_salary_shock();
        alice_change_job();
        alice_burnout();

        // Расходы на жизнь
        alice_pay_food();
        alice_pay_mobile();
        alice_pay_healthcare();
        alice_pay_entertainment();
        alice_pay_clothing();
        alice_pay_unexpected();

        // Жильё (flat_1)
        alice_pay_rent();
        alice_pay_utilities();
        alice_pay_parking();

        // Доход от сдачи (flat_2)
        alice_receive_rent();
        alice_pay_property_tax();

        // Автомобиль
        alice_pay_fuel();
        alice_pay_car_tax();
        alice_pay_insurance_osago();
        alice_pay_insurance_kasko();
        alice_pay_maintenance();
        alice_depreciate_car();

        // Депозит
        alice_update_deposit();

        // Случайные события
        alice_random_medical_expense();
        alice_random_car_repair();
        alice_random_vacation();
        alice_random_gift();
        alice_random_inheritance();
        alice_random_fine();
        alice_random_phone_break();
        alice_random_household_break();

        // Пересчёт стресса
        alice_calculate_stress();

        // Если декабрь - годовой отчёт и годовые события
        if (month == 12) {
            //alice_annual_indexation();
            alice_check_crisis();
            alice_make_report(year);
            year++;
        }

        month++;
        if (month > 12) month = 1;


    }
}

// ---------- Вывод отчётов ----------
void print_reports() {
    std::cout << "=== Alice year report ===\n";
    std::cout << "Year | Net Worth | Capital | Deposit | Car Value | Rent Paid | Property Tax | Stress\n";
    for (const auto& r : report_alice) {
        std::cout << r.year << " | "
            << r.net_worth << " | "
            << r.capital << " | "
            << r.deposit << " | "
            << r.car_value << " | "
            << r.rent_paid << " | "
            << r.property_tax_paid << " | "
            << r.stress_index << "\n";
    }
}

// ---------- Главная функция ----------
int main() {
    srand(static_cast<unsigned>(time(nullptr))); // для случайности
    setlocale(LC_ALL, "");

    world_init();
    alice_init();

    simulate_alice(2026, 20);

    print_reports();

    return 0;
}
