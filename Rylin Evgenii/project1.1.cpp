#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <clocale>  


using RUB = long long int;
using percent = float; 
using KM = int;
using Area = int;


struct BankAccount {
    RUB bank_account; 
    RUB deposit;      
    RUB cashback;     
};


struct Loan {            
    RUB debt;            
    RUB monthly_payment; 
};


struct Car {
    RUB value;               
    RUB gas;                 
    int horsepower;          
    KM mileage;             
    int age;                 
    RUB insurance_cost;      
    RUB maintenance_cost;    
    RUB wash_cost;           
    bool has_winter_tires;   
    RUB tire_change_cost;    
    KM km_to_next_maintenance; 
};


struct Flat {
    RUB value;                  
    Area square_meters;          
    RUB utility_bills;           
    RUB internet_tv_cost;       
    RUB major_repairs_fund;     
    RUB home_insurance_cost;    
    RUB cleaning_supplies_cost; 
    int renovation_condition;   
};


struct MentalHealth {
    int stress_level;           
    int burnout_months_left;    
    RUB therapy_cost_per_session; 
    bool is_in_therapy;         
};


struct Hobby {
    RUB video_games_monthly_budget; 
    RUB weekend_trip_cost;          
    int months_since_last_trip;     
};


struct Statistics {
    int medical_events;          
    RUB medical_spent;           
    int traffic_fines;           
    RUB fines_spent;             
    int appliance_repairs;      
    RUB repairs_spent;           
    int shopping_events;         
    RUB shopping_spent;         
    int lottery_wins;            
    RUB lottery_income;          
    int car_breakdowns;          
    RUB car_breakdown_spent;     
    int maintenance_done;        
    int tire_changes;            
    int trips_taken;             
    RUB trips_spent;             
    int flat_minor_repairs_done; 
    RUB flat_minor_repairs_spent;
    RUB flat_total_upkeep_spent; 
    int forgotten_subscriptions; 
    RUB subscriptions_spent;     
    int scam_calls;              
    RUB scam_losses;            
    int neighbor_floods;         
    RUB flood_spent;            
    int unexpected_gifts_count;  
    RUB unexpected_gifts_income; 
    int burnouts_experienced;    
    RUB lost_income_due_to_burnout; 
    int therapy_sessions_attended; 
    RUB therapy_spent;           
    int video_games_bought;     
    RUB video_games_spent;
    int weekend_trips_taken;
    RUB weekend_trips_spent;
};


struct Person {
    RUB salary;
    RUB food;
    Car car;
    Flat flat;
    BankAccount bank;
    Loan renovation_loan;
    MentalHealth mental;             
    Hobby hobby;                   
    Statistics stats;                 // Статистика за время симуляции
    RUB accumulated_yearly_income;    // Накопленный доход за год (для НДФЛ)
    RUB accumulated_deposit_interest; // Накопленный процент по вкладам за год
};


struct Person alice;


RUB full_capital() {  // Функция подсчета полного капитала (Активы - Долги)
    RUB assets = alice.bank.bank_account + alice.bank.deposit + alice.car.value + alice.flat.value;
    RUB liabilities = alice.renovation_loan.debt;
    return assets - liabilities;
}


void alice_init() {
    srand(time(NULL));  // Инициализация генератора случайных чисел
    alice.bank.bank_account = 0;
    alice.bank.deposit = 500'000;
    alice.bank.cashback = 0;

    alice.salary = 180'000;
    alice.food = 35'000;

    alice.car.value = 2'400'000;
    alice.car.gas = 12'000;
    alice.car.horsepower = 150;
    alice.car.mileage = 31'150;
    alice.car.age = 3;
    alice.car.insurance_cost = 18'000;
    alice.car.maintenance_cost = 25'000;
    alice.car.wash_cost = 2'000;
    alice.car.has_winter_tires = true;
    alice.car.tire_change_cost = 4'000;
    alice.car.km_to_next_maintenance = 10'000;

    alice.flat.value = 10'000'000;
    alice.flat.square_meters = 65;
    alice.flat.utility_bills = 10'500;
    alice.flat.internet_tv_cost = 1'200;
    alice.flat.major_repairs_fund = alice.flat.square_meters * 25;
    alice.flat.home_insurance_cost = 12'000;
    alice.flat.cleaning_supplies_cost = 3'000;
    alice.flat.renovation_condition = 100;

    alice.renovation_loan.debt = 2'000'000;
    alice.renovation_loan.monthly_payment = 48'000;

    alice.mental.stress_level = 10;
    alice.mental.burnout_months_left = 0;
    alice.mental.therapy_cost_per_session = 4'500;
    alice.mental.is_in_therapy = false;

    alice.hobby.video_games_monthly_budget = 3'000;
    alice.hobby.weekend_trip_cost = 15'000;
    alice.hobby.months_since_last_trip = 0;

    alice.accumulated_yearly_income = 0;
    alice.accumulated_deposit_interest = 0;

    alice.stats.medical_events = 0;
    alice.stats.medical_spent = 0;
    alice.stats.traffic_fines = 0;
    alice.stats.fines_spent = 0;
    alice.stats.appliance_repairs = 0;
    alice.stats.repairs_spent = 0;
    alice.stats.shopping_events = 0;
    alice.stats.shopping_spent = 0;
    alice.stats.lottery_wins = 0;
    alice.stats.lottery_income = 0;
    alice.stats.car_breakdowns = 0;
    alice.stats.car_breakdown_spent = 0;
    alice.stats.maintenance_done = 0;
    alice.stats.tire_changes = 0;
    alice.stats.trips_taken = 0;
    alice.stats.trips_spent = 0;
    alice.stats.flat_minor_repairs_done = 0;
    alice.stats.flat_minor_repairs_spent = 0;
    alice.stats.flat_total_upkeep_spent = 0;
    alice.stats.forgotten_subscriptions = 0;
    alice.stats.subscriptions_spent = 0;
    alice.stats.scam_calls = 0;
    alice.stats.scam_losses = 0;
    alice.stats.neighbor_floods = 0;
    alice.stats.flood_spent = 0;
    alice.stats.unexpected_gifts_count = 0;
    alice.stats.unexpected_gifts_income = 0;
    alice.stats.burnouts_experienced = 0;
    alice.stats.lost_income_due_to_burnout = 0;
    alice.stats.therapy_sessions_attended = 0;
    alice.stats.therapy_spent = 0;
    alice.stats.video_games_bought = 0;
    alice.stats.video_games_spent = 0;
    alice.stats.weekend_trips_taken = 0;
    alice.stats.weekend_trips_spent = 0;
}


percent sberbank_deposit_interest() {  // Ставка по вкладу
    return 14.5;
}


void alice_pay_from_bank_account(RUB amount, bool is_cashback_category) {  // Универсальная функция трат
    if (alice.bank.bank_account + alice.bank.deposit < amount) {  // Проверка на банкротство
        printf("КРИТИЧЕСКАЯ ОШИБКА: Алиса банкрот! Не хватает %lld руб.!\n", amount - (alice.bank.bank_account + alice.bank.deposit));
        alice.bank.bank_account = 0;
        alice.bank.deposit = 0;
        return;
    }
    
    if (alice.bank.bank_account < amount) {
        RUB diff = amount - alice.bank.bank_account;
        alice.bank.bank_account = 0;
        alice.bank.deposit -= diff;
    }
    else {
        alice.bank.bank_account -= amount;
    }
    
    if (is_cashback_category) {
        percent cashback_rate = 0.05;
        alice.bank.cashback += amount * cashback_rate;
    }
}


void alice_calculate_and_pay_ndfl(RUB gross_income) {  // Удержание НДФЛ
    RUB tax = 0;
    percent tax_rate_13 = 0.13;
    percent tax_rate_15 = 0.15;

    if (alice.accumulated_yearly_income <= 2'400'000) {
        tax = gross_income * tax_rate_13;
    }
    else if (alice.accumulated_yearly_income - gross_income < 2'400'000) {
        RUB chunk_13 = 2'400'000 - (alice.accumulated_yearly_income - gross_income);
        RUB chunk_15 = gross_income - chunk_13;
        tax = (chunk_13 * tax_rate_13) + (chunk_15 * tax_rate_15);
    }
    else {
        tax = gross_income * tax_rate_15;
    }
    
    alice_pay_from_bank_account(tax, false);
}


void alice_pay_flat_tax(int month) {  // Налог на квартиру
    if (month == 11) { 
        percent flat_tax_rate = 0.001; // Региональная ставка налога на имущество
        RUB flat_tax = alice.flat.value * flat_tax_rate;
        alice_pay_from_bank_account(flat_tax, false);
        alice.stats.flat_total_upkeep_spent += flat_tax;
    }
}


void alice_pay_deposit_tax(int month) {  // Налог на вклады
    if (month == 12) { // Платится в декабре
        percent tax_free_rate = 0.15;
        percent deposit_tax_rate = 0.13;
        RUB tax_free_limit = 1'000'000 * tax_free_rate;

        if (alice.accumulated_deposit_interest > tax_free_limit) {
            RUB taxable_base = alice.accumulated_deposit_interest - tax_free_limit;
            RUB deposit_tax = taxable_base * deposit_tax_rate;
            alice_pay_from_bank_account(deposit_tax, false);
        }
        
        alice.accumulated_yearly_income = 0;  // Обнуляются налоговые счетчики на следующий год
        alice.accumulated_deposit_interest = 0;
    }
}


void alice_mental_health_and_hobbies(int month) {
    alice.mental.stress_level += 7; 

    if (alice.renovation_loan.debt > 1'000'000) {
        alice.mental.stress_level += 4; 
    }

    alice.hobby.months_since_last_trip++;
    
    if (alice.hobby.months_since_last_trip > 6) {
        alice.mental.stress_level += 4; 
    }

    if (rand() % 100 < 15) { 
        alice.mental.stress_level += 15;
    }

    if (alice.mental.stress_level > 30 && alice.mental.stress_level < 80) {
        alice_pay_from_bank_account(alice.hobby.video_games_monthly_budget, true);
        alice.stats.video_games_bought++;
        alice.stats.video_games_spent += alice.hobby.video_games_monthly_budget;
        alice.mental.stress_level -= 8;
    }

    if (alice.mental.stress_level > 60 && alice.mental.stress_level < 80 && alice.hobby.months_since_last_trip > 2) {
        alice_pay_from_bank_account(alice.hobby.weekend_trip_cost, true);
        alice.stats.weekend_trips_taken++;
        alice.stats.weekend_trips_spent += alice.hobby.weekend_trip_cost;
        alice.mental.stress_level -= 25;
        alice.hobby.months_since_last_trip = 0; 
    }

    if (alice.mental.stress_level >= 80 && alice.mental.burnout_months_left == 0) {
        alice.mental.burnout_months_left = 2; 
        alice.stats.burnouts_experienced++;
        alice.mental.is_in_therapy = true;    
        alice.mental.stress_level = 40;       
    }

    if (alice.mental.is_in_therapy) {
        int sessions_per_month = 4; // Раз в неделю
        RUB monthly_therapy_cost = alice.mental.therapy_cost_per_session * sessions_per_month;
        alice_pay_from_bank_account(monthly_therapy_cost, false);

        alice.stats.therapy_sessions_attended += sessions_per_month;
        alice.stats.therapy_spent += monthly_therapy_cost;
        alice.mental.stress_level -= 15; 

        if (alice.mental.stress_level <= 20 && alice.mental.burnout_months_left == 0) {
            alice.mental.is_in_therapy = false;
        }
    }

    if (alice.mental.stress_level < 0) alice.mental.stress_level = 0;
}


void alice_apply_random_events(int year, int month) {  // Генератор случайных событий
    int chance = rand() % 100 + 1; 

    int burnout_penalty;
    if (alice.mental.burnout_months_left > 0) {
        burnout_penalty = 5;
    }
    else {
        burnout_penalty = 0;
    }

    if (chance <= 5) { 
        RUB medical_bill = 15'000 + (rand() % 10'000);
        alice.stats.medical_events++;
        alice.stats.medical_spent += medical_bill;
        alice_pay_from_bank_account(medical_bill, false);

    }
    
    if (chance > 5 && chance <= (12 + burnout_penalty)) { 
        RUB traffic_fine = 1'500;
        alice.stats.traffic_fines++;
        alice.stats.fines_spent += traffic_fine;
        alice_pay_from_bank_account(traffic_fine, false);

    }
    else if (chance > 12 && chance <= 15) { 
        RUB repair_cost = 7'500 + (rand() % 35'000);
        alice.stats.appliance_repairs++;
        alice.stats.repairs_spent += repair_cost;
        alice_pay_from_bank_account(repair_cost, false);
        alice.mental.stress_level += 5; 

    }
    else if (chance > 15 && chance <= 18) { 
        RUB shopping = 10'000 + (rand() % 20'000);
        alice.stats.shopping_events++;
        alice.stats.shopping_spent += shopping;
        alice_pay_from_bank_account(shopping, true);
        alice.mental.stress_level -= 5; 

    }
    
    if (chance > 18 && chance <= (21 + burnout_penalty)) { 
        RUB sub_cost = 500 + (rand() % 2000);
        alice.stats.forgotten_subscriptions++;
        alice.stats.subscriptions_spent += sub_cost;
        alice_pay_from_bank_account(sub_cost, false);

    }
    else if (chance == 22) { 
        alice.stats.scam_calls++;
        if (alice.bank.bank_account > 0) {
            RUB loss = alice.bank.bank_account / 2;
            alice.bank.bank_account -= loss;
            alice.stats.scam_losses += loss;
            alice.mental.stress_level += 25; 
        }

    }
    else if (chance == 23) { 
        alice.stats.neighbor_floods++;
        RUB total_damage = 100'000 + (rand() % 150'000);
        RUB alice_pays = total_damage * 0.10; 
        alice_pay_from_bank_account(alice_pays, false);
        alice.stats.flood_spent += alice_pays;
        alice.mental.stress_level += 30; 

    }
    else if (chance > 23 && chance <= 25) { 
        RUB gift = 2'000 + (rand() % 8'000);
        alice.stats.unexpected_gifts_count++;
        alice.stats.unexpected_gifts_income += gift;
        alice.bank.bank_account += gift;

    }
    
    if (chance == 100) { 
        RUB bonus = 5'000 + (rand() % 10'000);
        alice.stats.lottery_wins++;
        alice.stats.lottery_income += bonus;
        alice.bank.bank_account += bonus;
    }
}


void alice_salary(const int year, const int month) {
    if (month == 3 && year == 2026) {
        percent salary_increase = 1.1;
        alice.salary *= salary_increase;
    }

    RUB current_month_income = alice.salary;

    if (alice.mental.burnout_months_left > 0) {
        RUB sick_leave_pay = alice.salary * 0.4; 
        alice.stats.lost_income_due_to_burnout += (alice.salary - sick_leave_pay);
        current_month_income = sick_leave_pay;
        alice.mental.burnout_months_left--; 
    }

    if (month == 1 && alice.mental.burnout_months_left == 0) {
        current_month_income += 30'000 + (rand() % 30'000); 
    }

    alice.bank.bank_account += current_month_income;  
    alice.accumulated_yearly_income += current_month_income;
    alice_calculate_and_pay_ndfl(current_month_income);  
}


void alice_food(const int month) {
    if (month == 1) {
        percent inflation = 1.07;
        alice.food *= inflation;
    }
    
    alice_pay_from_bank_account(alice.food, true);
}


void alice_car(const int year, const int month) {
    if (month == 1) {
        percent inflation_gas = 1.07;
        percent inflation_services = 1.05;
        alice.car.gas *= inflation_gas;
        alice.car.wash_cost *= inflation_services;
        alice.car.tire_change_cost *= inflation_services;
    }
    alice_pay_from_bank_account(alice.car.gas, true);
    alice_pay_from_bank_account(alice.car.wash_cost, true);

    int monthly_mileage = 800 + (rand() % 700);
    alice.car.mileage += monthly_mileage;
    alice.car.km_to_next_maintenance -= monthly_mileage;

    if (alice.car.km_to_next_maintenance <= 0) {  // Плановое техобслуживание
        alice_pay_from_bank_account(alice.car.maintenance_cost, false);
        alice.stats.maintenance_done++;
        alice.car.km_to_next_maintenance = 15'000;
    }

    if (month == 4 && alice.car.has_winter_tires) {      // Сезонный шиномонтаж
        alice.car.has_winter_tires = false;
        alice_pay_from_bank_account(alice.car.tire_change_cost, false);
        alice.stats.tire_changes++;
    }
    else if (month == 11 && !alice.car.has_winter_tires) {
        alice.car.has_winter_tires = true;
        alice_pay_from_bank_account(alice.car.tire_change_cost, false);
        alice.stats.tire_changes++;
    }

    if (month == 2) {  
        percent depreciation = 0.90;
        alice_pay_from_bank_account(alice.car.insurance_cost, false);
        alice.car.age++;
        alice.car.value *= depreciation;
    }

    if (month == 11) { 
        int hp = alice.car.horsepower;
        int tax_rate = 0;
        if (hp <= 100) tax_rate = 24;
        else if (hp <= 150) tax_rate = 35;
        else if (hp <= 200) tax_rate = 50;
        else if (hp <= 250) tax_rate = 75;
        else tax_rate = 150;

        RUB car_tax = hp * tax_rate;
        alice_pay_from_bank_account(car_tax, false);
    }

    int breakdown_chance = rand() % 100 + 1;  
    if (breakdown_chance <= alice.car.age * 2) {
        RUB breakdown_cost = 5'000 + (rand() % 25'000);
        alice_pay_from_bank_account(breakdown_cost, false);
        alice.stats.car_breakdowns++;
        alice.stats.car_breakdown_spent += breakdown_cost;
        alice.mental.stress_level += 10; 
    }
}


void alice_flat(const int month) {
    if (month == 1) {
        percent inflation_housing = 1.07;
        percent inflation_services = 1.05;
        percent property_value_growth = 1.03;
        alice.flat.utility_bills *= inflation_housing;
        alice.flat.major_repairs_fund *= inflation_housing;
        alice.flat.internet_tv_cost *= inflation_services;
        alice.flat.cleaning_supplies_cost *= inflation_services;
        alice.flat.value *= property_value_growth;
    }

    alice_pay_from_bank_account(alice.flat.utility_bills, false);
    alice_pay_from_bank_account(alice.flat.internet_tv_cost, true);
    alice_pay_from_bank_account(alice.flat.major_repairs_fund, false);
    alice_pay_from_bank_account(alice.flat.cleaning_supplies_cost, true);

    alice.stats.flat_total_upkeep_spent += (alice.flat.utility_bills + alice.flat.internet_tv_cost + alice.flat.major_repairs_fund + alice.flat.cleaning_supplies_cost);

    if (month == 3) {
        alice_pay_from_bank_account(alice.flat.home_insurance_cost, false);
        alice.stats.flat_total_upkeep_spent += alice.flat.home_insurance_cost;
    }

    int wear_and_tear = rand() % 2;
    alice.flat.renovation_condition -= wear_and_tear;

    if (alice.flat.renovation_condition < 75) {
        RUB repair_cost = 25'000 + (rand() % 40'000);
        alice_pay_from_bank_account(repair_cost, false);
        alice.flat.renovation_condition = 100;
        alice.stats.flat_minor_repairs_done++;
        alice.stats.flat_minor_repairs_spent += repair_cost;
        alice.stats.flat_total_upkeep_spent += repair_cost;
        alice.mental.stress_level += 15;
    }
}


void alice_loan() {
    if (alice.renovation_loan.debt > 0) {
        alice_pay_from_bank_account(alice.renovation_loan.monthly_payment, false);
        alice.renovation_loan.debt -= alice.renovation_loan.monthly_payment;
        if (alice.renovation_loan.debt < 0) alice.renovation_loan.debt = 0;
    }
}


void alice_trip(int month) {
    if (month == 7) {
        RUB trip_cost = 150'000 + (rand() % 200'000);
        alice_pay_from_bank_account(trip_cost, false);
        alice.stats.trips_taken++;
        alice.stats.trips_spent += trip_cost;

        alice.mental.stress_level -= 40; 
        alice.hobby.months_since_last_trip = 0;
    }
}


void alice_sberbank() {
    if (alice.bank.deposit > 0) {
        percent rate = sberbank_deposit_interest();
        RUB monthly_interest = alice.bank.deposit * (rate / 12.0 / 100.0);
        alice.bank.deposit += monthly_interest;
        alice.accumulated_deposit_interest += monthly_interest;
    }
    
    alice.bank.bank_account += alice.bank.cashback;
    alice.bank.cashback = 0;

    if (alice.bank.bank_account > 0) {
        alice.bank.deposit += alice.bank.bank_account;
        alice.bank.bank_account = 0;
    }
}


void print_results() {
    printf("\n======================================================\n");
    printf("        ФИНАЛЬНЫЕ РЕЗУЛЬТАТЫ СИМУЛЯЦИИ (02.2028)        \n");
    printf("======================================================\n");

    printf("\n[ ФИНАНСЫ И АКТИВЫ ]\n");
    printf("ПОЛНЫЙ КАПИТАЛ (Net Worth):   %lld руб.\n", full_capital());
    printf("Зарплата на конец симуляции:  %lld руб.\n", alice.salary);
    printf("Баланс на вкладе:             %lld руб.\n", alice.bank.deposit);
    printf("Остаток по кредиту на ремонт: %lld руб.\n", alice.renovation_loan.debt);

    printf("\n[ МЕНТАЛЬНОЕ ЗДОРОВЬЕ И СТРЕСС ]\n");
    printf("Текущий уровень стресса:      %d / 100\n", alice.mental.stress_level);
    printf("Случаев выгорания:  %d раз(а)\n", alice.stats.burnouts_experienced);
    printf("Потеряно З/П из-за выгорания: %lld руб.\n", alice.stats.lost_income_due_to_burnout);
    printf("Сеансов у психолога:          %d раз(а) (потрачено: %lld руб.)\n", alice.stats.therapy_sessions_attended, alice.stats.therapy_spent);
    printf("Куплено видеоигр (антистресс):%d раз(а)\n", alice.stats.video_games_bought, alice.stats.video_games_spent);
    printf("Поездок за город (выходные):  %d раз(а) (потрачено: %lld руб.)\n", alice.stats.weekend_trips_taken, alice.stats.weekend_trips_spent);

    printf("\n[ ИМУЩЕСТВО: КВАРТИРА ]\n");
    printf("Рыночная стоимость квартиры:  %lld руб.\n", alice.flat.value);
    printf("Состояние ремонта:            %d%%\n", alice.flat.renovation_condition);
    printf("Проведено мелких ремонтов:    %d раз(а) (потрачено: %lld руб.)\n", alice.stats.flat_minor_repairs_done, alice.stats.flat_minor_repairs_spent);
    printf("Всего потрачено на жилье:     %lld руб. (ЖКХ, налоги, ремонты)\n", alice.stats.flat_total_upkeep_spent);

    printf("\n[ ИМУЩЕСТВО: АВТОМОБИЛЬ ]\n");
    printf("Рыночная стоимость машины:    %lld руб.\n", alice.car.value);
    printf("Возраст машины:               %d лет\n", alice.car.age);
    printf("Итоговый пробег:              %d км\n", alice.car.mileage);

    printf("\n[ СТАТИСТИКА ЖИЗНЕННЫХ СОБЫТИЙ ЗА ПЕРИОД ]\n");
    printf("Болезни (аптека/врачи):       %d раз(а) (потрачено: %lld руб.)\n", alice.stats.medical_events, alice.stats.medical_spent);
    printf("Штрафы за скорость:           %d раз(а) (потрачено: %lld руб.)\n", alice.stats.traffic_fines, alice.stats.fines_spent);
    printf("Поломки бытовой техники:      %d раз(а) (потрачено: %lld руб.)\n", alice.stats.appliance_repairs, alice.stats.repairs_spent);
    printf("Спонтанный шоппинг:           %d раз(а) (потрачено: %lld руб.)\n", alice.stats.shopping_events, alice.stats.shopping_spent);
    printf("Внезапные поломки авто:       %d раз(а) (потрачено: %lld руб.)\n", alice.stats.car_breakdowns, alice.stats.car_breakdown_spent);
    printf("Списания за забытые подписки: %d раз(а) (потеряно: %lld руб.)\n", alice.stats.forgotten_subscriptions, alice.stats.subscriptions_spent);
    printf("Попадания на мошенников:      %d раз(а) (потеряно: %lld руб.)\n", alice.stats.scam_calls, alice.stats.scam_losses);
    printf("Затопления соседей:           %d раз(а) (выплачено: %lld руб.)\n", alice.stats.neighbor_floods, alice.stats.flood_spent);
    printf("Неожиданные доходы/подарки:   %d раз(а) (получено: %lld руб.)\n", alice.stats.unexpected_gifts_count, alice.stats.unexpected_gifts_income);
    printf("Выигрыши в лотерею:           %d раз(а) (получено: %lld руб.)\n", alice.stats.lottery_wins, alice.stats.lottery_income);
    printf("Съездила в отпуск:            %d раз(а) (потрачено: %lld руб.)\n", alice.stats.trips_taken, alice.stats.trips_spent);

    printf("\n[ ОБСЛУЖИВАНИЕ АВТО ]\n");
    printf("Пройдено плановых ТО:         %d раз(а)\n", alice.stats.maintenance_done);
    printf("Сезонных замен резины:        %d раз(а)\n", alice.stats.tire_changes);
    printf("======================================================\n");
}


void alice_simulation() {
    int year = 2026;
    int month = 2;

    while (!(year == 2028 && month == 2)) {
        alice_mental_health_and_hobbies(month); // Сначала обрабатываем стресс
        alice_salary(year, month);
        alice_trip(month);
        alice_food(month);
        alice_car(year, month);
        alice_flat(month);
        alice_pay_flat_tax(month);
        alice_pay_deposit_tax(month);
        alice_loan();
        alice_apply_random_events(year, month);
        alice_sberbank();

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul");

    alice_init();
    alice_simulation();
    print_results();

    return 0;
}
