#include <stdio.h>
#include <stdlib.h> // Для генерации случайных чисел
#include <time.h>   // Для инициализации rand() по текущему времени
#include <clocale>  // Библиотека для работы с русским языком


using RUB = long long int;


struct BankAccount {
    RUB checking; // Текущий счет (карта)
    RUB deposit;  // Вклад
    RUB cashback; // Копилка кэшбэка
};


struct Loan {            // Кредитная система (на ремонт)
    RUB debt;            // Остаток долга
    RUB monthly_payment; // Сколько платить в месяц
};


struct Car {
    RUB value;               // Рыночная стоимость
    RUB gas;                 // Траты на бензин в месяц
    int horsepower;          // Лошадиные силы для налога
    int mileage;             // Текущий пробег (км)
    int age;                 // Возраст авто (лет)
    RUB insurance_cost;      // Ежегодная страховка ОСАГО
    RUB maintenance_cost;    // Стоимость ТО (замена масла, фильтров)
    RUB wash_cost;           // Траты на мойку в месяц
    bool has_winter_tires;   // Зимняя резина установлена?
    RUB tire_change_cost;    // Стоимость услуг шиномонтажа
    int km_to_next_maintenance; // Километров до следующего ТО
};


struct Flat {
    RUB value;
    RUB utilitybills;  // ЖКХ
};


struct Statistics {
    int medical_events;          // Сколько раз болела
    RUB medical_spent;           // Потрачено на аптеки
    int traffic_fines;           // Количество штрафов
    RUB fines_spent;             // Потрачено на штрафы
    int appliance_repairs;       // Поломки техники
    RUB repairs_spent;           // Потрачено на ремонт техники
    int shopping_events;         // Спонтанный шоппинг
    RUB shopping_spent;          // Потрачено на шоппинг
    int lottery_wins;            // Выигрыши в лотерею
    RUB lottery_income;          // Заработано на лотерее
    int car_breakdowns;          // Внезапные поломки авто
    RUB car_breakdown_spent;     // Потрачено на ремонт авто
    int maintenance_done;        // Сколько раз пройдено ТО
    int tire_changes;            // Сколько раз меняли резину
    int trips_taken;             // Сколько раз ездила в отпуск
    RUB trips_spent;             // Потрачено на отпуска
};


struct Person {
    RUB salary;
    RUB food;
    Car car;
    Flat flat;
    BankAccount bank;
    Loan renovation_loan;
    Statistics stats;                 // Статистика за время симуляции
    RUB accumulated_yearly_income;    // Накопленный доход за год (для НДФЛ)
    RUB accumulated_deposit_interest; // Накопленный процент по вкладам за год
};


struct Person alice;


RUB full_capital() {  // Функция подсчета полного капитала (Активы - Долги)
    RUB assets = alice.bank.checking + alice.bank.deposit + alice.car.value + alice.flat.value;
    RUB liabilities = alice.renovation_loan.debt;
    return assets - liabilities;
}


void alice_init()
{
    srand(time(NULL));  // Инициализация генератора случайных чисел

    alice.bank.checking = 0;
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
    alice.flat.utilitybills = 10'500;

    alice.renovation_loan.debt = 2'000'000;
    alice.renovation_loan.monthly_payment = 48'000;

    alice.accumulated_yearly_income = 0;
    alice.accumulated_deposit_interest = 0;

    alice.stats.medical_events = 0;  // Обнуление статистики
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
}


float sberbank_deposit_interest() {  // Ставка по вкладу
    return 14.5;
}


void pay_from_checking(RUB amount, bool is_cashback_category)  // Универсальная функция трат
{
    if (alice.bank.checking + alice.bank.deposit < amount) {  // Проверка на банкротство
        printf("КРИТИЧЕСКАЯ ОШИБКА: Алиса банкрот! Не хватает %lld руб.!\n", amount - (alice.bank.checking + alice.bank.deposit));
        alice.bank.checking = 0;
        alice.bank.deposit = 0;
        return;
    }

    if (alice.bank.checking < amount) {
        RUB diff = amount - alice.bank.checking;
        alice.bank.checking = 0;
        alice.bank.deposit -= diff;
    }
    
    else {
        alice.bank.checking -= amount;
    }

    if (is_cashback_category) {
        alice.bank.cashback += amount * 0.05;
    }
}


void calculate_and_pay_ndfl(RUB gross_income) {  // Удержание НДФЛ
    RUB tax = 0;
    if (alice.accumulated_yearly_income <= 2'400'000) {
        tax = gross_income * 0.13;
    }
    
    else if (alice.accumulated_yearly_income - gross_income < 2'400'000) {
        RUB chunk_13 = 2'400'000 - (alice.accumulated_yearly_income - gross_income);
        RUB chunk_15 = gross_income - chunk_13;
        tax = (chunk_13 * 0.13) + (chunk_15 * 0.15);
    }
    
    else {
        tax = gross_income * 0.15;
    }
    
    pay_from_checking(tax, false);
}


void pay_property_taxes(int month) {  // Имущественные налоги (Квартира и Машина)
    if (month == 11) { // Платится в ноябре
        RUB flat_tax = alice.flat.value * 0.001;
        pay_from_checking(flat_tax, false);

        int hp = alice.car.horsepower;
        int tax_rate = 0;
        if (hp <= 100) tax_rate = 24;
        else if (hp <= 150) tax_rate = 35;
        else if (hp <= 200) tax_rate = 50;
        else if (hp <= 250) tax_rate = 75;
        else tax_rate = 150;

        RUB car_tax = hp * tax_rate;
        pay_from_checking(car_tax, false);
    }
}


void pay_deposit_tax(int month) {  // Налог на вклады
    if (month == 12) { // Платится в декабре
        RUB tax_free_limit = 1'000'000 * 0.15;
        if (alice.accumulated_deposit_interest > tax_free_limit) {
            RUB taxable_base = alice.accumulated_deposit_interest - tax_free_limit;
            RUB deposit_tax = taxable_base * 0.13;
            pay_from_checking(deposit_tax, false);
        }
        
        alice.accumulated_yearly_income = 0;  // Обнуляются налоговые счетчики на следующий год
        alice.accumulated_deposit_interest = 0;
    }
}


void apply_random_events(int year, int month) {  // Генератор случайных событий
    int chance = rand() % 100 + 1; // Число от 1 до 100

    if (chance <= 5) { // 5% вероятность
        RUB medical_bill = 15'000 + (rand() % 10'000);
        alice.stats.medical_events++;
        alice.stats.medical_spent += medical_bill;
        pay_from_checking(medical_bill, false);
    }
    
    else if (chance > 5 && chance <= 12) { // 7% вероятность
        RUB traffic_fine = 1'500;
        alice.stats.traffic_fines++;
        alice.stats.fines_spent += traffic_fine;
        pay_from_checking(traffic_fine, false);
    }
    
    else if (chance > 12 && chance <= 15) { // 3% вероятность
        RUB repair_cost = 7'500 + (rand() % 35'000);
        alice.stats.appliance_repairs++;
        alice.stats.repairs_spent += repair_cost;
        pay_from_checking(repair_cost, false);
    }
    
    else if (chance > 15 && chance <= 18) { // 3% вероятность
        RUB shopping = 10'000 + (rand() % 20'000);
        alice.stats.shopping_events++;
        alice.stats.shopping_spent += shopping;
        pay_from_checking(shopping, true);
    }
    
    else if (chance == 100) { // 1% вероятность
        RUB bonus = 5'000 + (rand() % 10'000);
        alice.stats.lottery_wins++;
        alice.stats.lottery_income += bonus;
        alice.bank.checking += bonus;
    }
}


void alice_salary(const int year, const int month)
{
    if (month == 3 && year == 2026) alice.salary *= 1.1;
    RUB current_month_income = alice.salary;

    if (month == 1) current_month_income += 30'000 + (rand() % 30'000); // Январская премия

    alice.bank.checking += current_month_income;  // Начисление
    alice.accumulated_yearly_income += current_month_income;
    calculate_and_pay_ndfl(current_month_income);  // Сразу вычитание налогов
}


void alice_food(const int month)
{
    if (month == 1) alice.food *= 1.07;
    pay_from_checking(alice.food, true);
}


void alice_car(const int year, const int month)
{
    if (month == 1) {
        alice.car.gas *= 1.07;
        alice.car.wash_cost *= 1.05;
        alice.car.tire_change_cost *= 1.05;
    }

    pay_from_checking(alice.car.gas, true);
    pay_from_checking(alice.car.wash_cost, true);

    int monthly_mileage = 800 + (rand() % 700);
    alice.car.mileage += monthly_mileage;
    alice.car.km_to_next_maintenance -= monthly_mileage;

    if (alice.car.km_to_next_maintenance <= 0) {  // Плановое техобслуживание
        pay_from_checking(alice.car.maintenance_cost, false);
        alice.stats.maintenance_done++;
        alice.car.km_to_next_maintenance = 15'000;
    }

    if (month == 4 && alice.car.has_winter_tires) {      // Сезонный шиномонтаж
        alice.car.has_winter_tires = false;
        pay_from_checking(alice.car.tire_change_cost, false);
        alice.stats.tire_changes++;
    }
    
    else if (month == 11 && !alice.car.has_winter_tires) {
        alice.car.has_winter_tires = true;
        pay_from_checking(alice.car.tire_change_cost, false);
        alice.stats.tire_changes++;
    }

    if (month == 2) {  // Ежегодные события
        pay_from_checking(alice.car.insurance_cost, false);
        alice.car.age++;
        alice.car.value *= 0.90;
    }

    int breakdown_chance = rand() % 100 + 1;  // Случайная поломка
    if (breakdown_chance <= alice.car.age * 2) {
        RUB breakdown_cost = 5'000 + (rand() % 25'000);
        pay_from_checking(breakdown_cost, false);
        alice.stats.car_breakdowns++;
        alice.stats.car_breakdown_spent += breakdown_cost;
    }
}


void alice_flat(const int month)
{
    if (month == 1) {
        alice.flat.utilitybills *= 1.07;
        alice.flat.value *= 1.07;
    }
    
    pay_from_checking(alice.flat.utilitybills, false);
}


void alice_loan()
{
    if (alice.renovation_loan.debt > 0) {
        pay_from_checking(alice.renovation_loan.monthly_payment, false);
        alice.renovation_loan.debt -= alice.renovation_loan.monthly_payment;
        if (alice.renovation_loan.debt < 0) alice.renovation_loan.debt = 0;
    }
}


void alice_trip(int month) {
    if (month == 7) {
        RUB trip_cost = 150'000 + (rand() % 200'000);
        pay_from_checking(trip_cost, false);
        alice.stats.trips_taken++;
        alice.stats.trips_spent += trip_cost;
    }
}


void alice_bank_logic()
{
    alice.bank.checking += alice.bank.cashback;  // Выплата кэшбэка
    alice.bank.cashback = 0;

    if (alice.bank.checking > 0) {  // Перевод остатков на вклад
        alice.bank.deposit += alice.bank.checking;
        alice.bank.checking = 0;
    }

    if (alice.bank.deposit > 0) {  // Проценты по вкладу
        float rate = sberbank_deposit_interest();
        RUB monthly_interest = alice.bank.deposit * (rate / 12.0 / 100.0);
        alice.bank.deposit += monthly_interest;
        alice.accumulated_deposit_interest += monthly_interest;
    }
}


void print_results()
{
    printf("\n======================================================\n");
    printf("        ФИНАЛЬНЫЕ РЕЗУЛЬТАТЫ СИМУЛЯЦИИ (02.2028)        \n");
    printf("======================================================\n");

    printf("\n[ ФИНАНСЫ И АКТИВЫ ]\n");
    printf("ПОЛНЫЙ КАПИТАЛ (Net Worth):   %lld руб.\n", full_capital());
    printf("Зарплата на конец симуляции:  %lld руб.\n", alice.salary);
    printf("Баланс на вкладе:             %lld руб.\n", alice.bank.deposit);
    printf("Остаток по кредиту на ремонт: %lld руб.\n", alice.renovation_loan.debt);

    printf("\n[ ИМУЩЕСТВО ]\n");
    printf("Рыночная стоимость квартиры:  %lld руб.\n", alice.flat.value);
    printf("Рыночная стоимость машины:    %lld руб.\n", alice.car.value);
    printf("Возраст машины:               %d лет\n", alice.car.age);
    printf("Итоговый пробег:              %d км\n", alice.car.mileage);

    printf("\n[ СТАТИСТИКА ЖИЗНЕННЫХ СОБЫТИЙ ЗА ПЕРИОД ]\n");
    printf("Болезни (аптека/врачи):       %d раз(а) (потрачено: %lld руб.)\n", alice.stats.medical_events, alice.stats.medical_spent);
    printf("Штрафы за скорость:           %d раз(а) (потрачено: %lld руб.)\n", alice.stats.traffic_fines, alice.stats.fines_spent);
    printf("Поломки бытовой техники:      %d раз(а) (потрачено: %lld руб.)\n", alice.stats.appliance_repairs, alice.stats.repairs_spent);
    printf("Спонтанный шоппинг:           %d раз(а) (потрачено: %lld руб.)\n", alice.stats.shopping_events, alice.stats.shopping_spent);
    printf("Внезапные поломки авто:       %d раз(а) (потрачено: %lld руб.)\n", alice.stats.car_breakdowns, alice.stats.car_breakdown_spent);
    printf("Выигрыши в лотерею:           %d раз(а) (получено: %lld руб.)\n", alice.stats.lottery_wins, alice.stats.lottery_income);
    printf("Съездила в отпуск:            %d раз(а) (потрачено: %lld руб.)\n", alice.stats.trips_taken, alice.stats.trips_spent);

    printf("\n[ ОБСЛУЖИВАНИЕ АВТО ]\n");
    printf("Пройдено плановых ТО:         %d раз(а)\n", alice.stats.maintenance_done);
    printf("Сезонных замен резины:        %d раз(а)\n", alice.stats.tire_changes);
    printf("======================================================\n");
}


void alice_simulation()
{
    int year = 2026;
    int month = 2;

    while (!(year == 2028 && month == 2)) {
        alice_salary(year, month);
        alice_trip(month);
        alice_food(month);
        alice_car(year, month);
        alice_flat(month);
        pay_property_taxes(month);
        pay_deposit_tax(month);
        alice_loan();
        apply_random_events(year, month);
        alice_bank_logic();

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul");

    alice_init();
    alice_simulation();
    print_results();

    return 0;
}
