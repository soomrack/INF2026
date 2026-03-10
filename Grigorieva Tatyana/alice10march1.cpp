#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef long long int RUB;

struct Car {
    RUB value;
    RUB gas;
};

struct Housing {
    RUB rent;
    RUB utilities;
    RUB internet;
    RUB mobile;
};

struct BankPackage {
    RUB card;
    RUB savings;
    float rate;
};

struct Bank {
    char name[50];
    float deposit_rate;
    float card_cashback;
    RUB min_deposit;
    float (*calculate_rate)(RUB sum);
};

float sberbank_rate_calculator(RUB sum)
{
    if (sum >= 3000000) return 12.5;
    if (sum > 10000) return 11.5;
    return 0.1;
}

struct Bank sberbank = {
    "Сбербанк",
    11.5,
    0.01,
    10000,
    sberbank_rate_calculator
};

struct Person {
    RUB salary;
    RUB cash;
    RUB food;
    RUB clothing;
    struct Car car;
    struct Housing housing;
    struct BankPackage bank;
    struct Bank* main_bank;
};
struct Person alice;


const float INFLATION_RATE = 8.5;


struct MonthlyStats {
    RUB salary_received;
    RUB housing_paid;
    RUB food_paid;
    RUB clothing_paid;
    RUB gas_paid;
    RUB cashback_received;
    RUB interest_received;
    RUB savings_moved;
    RUB cash_spent;
    RUB card_spent;
    RUB cash_withdrawn;
    RUB emergency_fund_used;
    RUB taxes_paid;
    RUB total_events_impact;
} stats;


// Структура для жизненных событий
struct LifeEvent {
    int year;
    int month;
    char description[100];
    RUB financial_impact;
    void (*effect)(struct Person* p, RUB amount);
    int probability;  //вероятность
    int triggered;
    int min_month;    // минимальный месяц для события
    int max_month;    // максимальный месяц для события
    int min_year;     // минимальный год
    int max_year;     // максимальный год
};


struct LifeEvent events[30];
int num_events = 0;


void alice_init();
void init_stats();
void withdraw_cash(RUB amount);
void alice_food();
void alice_housing_expenses();
void alice_car();
void alice_salary(int year, int month);
void alice_bank_interest();
void alice_manage_savings(int month);
void alice_simulation();
void print_results();


// Прототипы функций для событий
void car_breakdown(struct Person* p, RUB amount);
void medical_emergency(struct Person* p, RUB amount);
void salary_bonus(struct Person* p, RUB amount);
void vacation_expense(struct Person* p, RUB amount);
void home_repair(struct Person* p, RUB amount);
void laptop_breakdown(struct Person* p, RUB amount);
void dental_treatment(struct Person* p, RUB amount);
void car_insurance(struct Person* p, RUB amount);
void fitness_subscription(struct Person* p, RUB amount);
void courses_expense(struct Person* p, RUB amount);
void phone_break(struct Person* p, RUB amount);
void friend_wedding(struct Person* p, RUB amount);
void tax_refund(struct Person* p, RUB amount);
void inheritance_receive(struct Person* p, RUB amount);


void init_events_dynamic() {
    num_events = 0;
    
    struct LifeEvent e1;
    strcpy(e1.description, "Поломка автомобиля");
    e1.min_year = 2026;
    e1.max_year = 2027;
    e1.min_month = 1;
    e1.max_month = 12;
    e1.effect = car_breakdown;
    e1.probability = 25;
    e1.triggered = 0;
    e1.financial_impact = 0;
    events[num_events++] = e1;
    
    struct LifeEvent e2;
    strcpy(e2.description, "Медицинская проблема");
    e2.min_year = 2026;
    e2.max_year = 2027;
    e2.min_month = 1;
    e2.max_month = 12;
    e2.effect = medical_emergency;
    e2.probability = 15;
    e2.triggered = 0;
    e2.financial_impact = 0;
    events[num_events++] = e2;
    
    struct LifeEvent e3;
    strcpy(e3.description, "Годовая премия");
    e3.min_year = 2026;
    e3.max_year = 2027;
    e3.min_month = 12;
    e3.max_month = 1;  // декабрь-январь
    e3.effect = salary_bonus;
    e3.probability = 70;
    e3.triggered = 0;
    e3.financial_impact = 0;
    events[num_events++] = e3;
    
    struct LifeEvent e4;
    strcpy(e4.description, "Отпуск");
    e4.min_year = 2026;
    e4.max_year = 2027;
    e4.min_month = 6;
    e4.max_month = 8;  // летние месяцы
    e4.effect = vacation_expense;
    e4.probability = 90;
    e4.triggered = 0;
    e4.financial_impact = 0;
    events[num_events++] = e4;
    
    struct LifeEvent e5;
    strcpy(e5.description, "Свадьба друга");
    e5.min_year = 2026;
    e5.max_year = 2026;
    e5.min_month = 11;
    e5.max_month = 11;  // только ноябрь
    e5.effect = friend_wedding;
    e5.probability = 100;
    e5.triggered = 0;
    e5.financial_impact = 0;
    events[num_events++] = e5;
    
    struct LifeEvent e6;
    strcpy(e6.description, "Ремонт в квартире");
    e6.min_year = 2026;
    e6.max_year = 2027;
    e6.min_month = 4;
    e6.max_month = 8;  // весна-лето
    e6.effect = home_repair;
    e6.probability = 30;
    e6.triggered = 0;
    e6.financial_impact = 0;
    events[num_events++] = e6;
    
    struct LifeEvent e7;
    strcpy(e7.description, "Поломка ноутбука");
    e7.min_year = 2026;
    e7.max_year = 2027;
    e7.min_month = 1;
    e7.max_month = 12;
    e7.effect = laptop_breakdown;
    e7.probability = 20;
    e7.triggered = 0;
    e7.financial_impact = 0;
    events[num_events++] = e7;
    
    struct LifeEvent e8;
    strcpy(e8.description, "Лечение зубов");
    e8.min_year = 2026;
    e8.max_year = 2027;
    e8.min_month = 1;
    e8.max_month = 12;
    e8.effect = dental_treatment;
    e8.probability = 25;
    e8.triggered = 0;
    e8.financial_impact = 0;
    events[num_events++] = e8;
    
    struct LifeEvent e9;
    strcpy(e9.description, "Страховка автомобиля");
    e9.min_year = 2026;
    e9.max_year = 2026;
    e9.min_month = 3;
    e9.max_month = 3;  // только март
    e9.effect = car_insurance;
    e9.probability = 100;
    e9.triggered = 0;
    e9.financial_impact = 0;
    events[num_events++] = e9;
    
    struct LifeEvent e10;
    strcpy(e10.description, "Годовой абонемент в фитнес");
    e10.min_year = 2026;
    e10.max_year = 2027;
    e10.min_month = 1;
    e10.max_month = 1;  // только январь
    e10.effect = fitness_subscription;
    e10.probability = 60;
    e10.triggered = 0;
    e10.financial_impact = 0;
    events[num_events++] = e10;
    
    struct LifeEvent e11;
    strcpy(e11.description, "Профессиональные курсы");
    e11.min_year = 2026;
    e11.max_year = 2027;
    e11.min_month = 9;
    e11.max_month = 10;  // осень
    e11.effect = courses_expense;
    e11.probability = 40;
    e11.triggered = 0;
    e11.financial_impact = 0;
    events[num_events++] = e11;
    
    struct LifeEvent e12;
    strcpy(e12.description, "Разбил телефон");
    e12.min_year = 2026;
    e12.max_year = 2027;
    e12.min_month = 1;
    e12.max_month = 12;
    e12.effect = phone_break;
    e12.probability = 15;
    e12.triggered = 0;
    e12.financial_impact = 0;
    events[num_events++] = e12;
    
    struct LifeEvent e13;
    strcpy(e13.description, "Налоговый вычет");
    e13.min_year = 2027;
    e13.max_year = 2027;
    e13.min_month = 4;
    e13.max_month = 5;  // весна
    e13.effect = tax_refund;
    e13.probability = 50;
    e13.triggered = 0;
    e13.financial_impact = 0;
    events[num_events++] = e13;
    
    struct LifeEvent e14;
    strcpy(e14.description, "Получение наследства");
    e14.min_year = 2026;
    e14.max_year = 2027;
    e14.min_month = 1;
    e14.max_month = 12;
    e14.effect = inheritance_receive;
    e14.probability = 5;
    e14.triggered = 0;
    e14.financial_impact = 0;
    events[num_events++] = e14;
}

void schedule_events() {
    srand(time(NULL));
    
    printf("\n ПЛАНИРОВАНИЕ ЖИЗНЕННЫХ СОБЫТИЙ\n");
    
    for (int i = 0; i < num_events; i++) {
        // Выбираем случайный месяц в заданном диапазоне
        if (events[i].min_year == events[i].max_year) {
            // Событие в одном году
            events[i].year = events[i].min_year;
            
            if (events[i].min_month <= events[i].max_month) {
                // Обычный диапазон (например, июнь-сентябрь)
                events[i].month = events[i].min_month + 
                    (rand() % (events[i].max_month - events[i].min_month + 1));
            } else {
                // Диапазон через новый год (например, декабрь-январь)
                int range = (12 - events[i].min_month + 1) + events[i].max_month;
                int offset = rand() % range;
                
                if (offset < (12 - events[i].min_month + 1)) {
                    events[i].month = events[i].min_month + offset;
                    events[i].year = events[i].min_year;
                } else {
                    events[i].month = offset - (12 - events[i].min_month + 1) + 1;
                    events[i].year = events[i].min_year + 1;
                }
            }
        } else {
            // Событие может быть в разных годах
            int year_range = events[i].max_year - events[i].min_year;
            events[i].year = events[i].min_year + (rand() % (year_range + 1));
            
            if (events[i].year == events[i].min_year) {
                // В первый год - от min_month до декабря
                events[i].month = events[i].min_month + 
                                  rand() % (13 - events[i].min_month);
            } else if (events[i].year == events[i].max_year) {
                // В последний год - от января до max_month
                events[i].month = 1 + rand() % events[i].max_month;
            } else {
                // В промежуточные годы - любой месяц
                events[i].month = 1 + rand() % 12;
            }
        }
        
        // Генерируем случайную сумму для событий без эффекта
        if (events[i].effect == NULL) {
            events[i].financial_impact = 10000 + rand() % 190000;
        }
        
        printf("  Запланировано событие \"%s\" на %d.%d (вероятность %d%%)\n", 
               events[i].description, events[i].month, events[i].year, events[i].probability);
    }
}


void car_breakdown(struct Person* p, RUB amount) {
    RUB cost = 30000 + rand() % 120000;
    printf("\n ПОЛОМКА АВТОМОБИЛЯ\n");
    printf("Ремонт обошелся в %lld руб.\n", cost);
    
    if (p->bank.savings >= cost) {
        p->bank.savings -= cost;
        stats.emergency_fund_used += cost;
        printf("Оплачено из сбережений\n");
    } else {
        RUB remaining = cost - p->bank.savings;
        p->bank.savings = 0;
        p->bank.card -= remaining;
        stats.emergency_fund_used += cost;
        printf("Сбережений не хватило, пришлось снимать с карты: %lld руб.\n", remaining);
    }
    stats.total_events_impact += cost;
}


void medical_emergency(struct Person* p, RUB amount) {
    RUB cost = 20000 + rand() % 280000;
    printf("\n МЕДИЦИНСКАЯ ПРОБЛЕМА\n");
    printf("  Лечение обошлось в %lld руб.\n", cost);
    
    if (p->bank.savings >= cost) {
        p->bank.savings -= cost;
        stats.emergency_fund_used += cost;
        printf("Оплачено из сбережений\n");
    } else {
        RUB remaining = cost - p->bank.savings;
        p->bank.savings = 0;
        p->bank.card -= remaining;
        stats.emergency_fund_used += cost;
        printf("Сбережений не хватило, пришлось снимать с карты: %lld руб.\n", remaining);
    }
    stats.total_events_impact += cost;
}

void salary_bonus(struct Person* p, RUB amount) {
    RUB bonus = p->salary * (0.3 + (rand() % 70) / 100.0);
    printf("\n ГОДОВАЯ ПРЕМИЯ\n");
    printf("  Получено %lld руб.\n", bonus);
    p->bank.card += bonus;
    stats.salary_received += bonus;
    stats.total_events_impact -= bonus;
}

void vacation_expense(struct Person* p, RUB amount) {
    RUB cost = 50000 + rand() % 200000;
    printf("\n ОТПУСК\n");
    printf("  Потрачено на отпуск: %lld руб.\n", cost);
    p->bank.card -= cost;
    stats.total_events_impact += cost;
}

void home_repair(struct Person* p, RUB amount) {
    RUB cost = 20000 + rand() % 180000;
    printf("\n РЕМОНТ В КВАРТИРЕ\n");
    printf("  Потрачено на ремонт: %lld руб.\n", cost);
    p->bank.card -= cost;
    stats.total_events_impact += cost;
}

void laptop_breakdown(struct Person* p, RUB amount) {
    RUB cost = 30000 + rand() % 70000;
    printf("\n ПОЛОМКА НОУТБУКА\n");
    printf("  Ремонт/покупка нового: %lld руб.\n", cost);
    p->bank.card -= cost;
    stats.total_events_impact += cost;
}

void dental_treatment(struct Person* p, RUB amount) {
    RUB cost = 15000 + rand() % 135000;
    printf("\n ЛЕЧЕНИЕ ЗУБОВ\n");
    printf("  Потрачено на стоматолога: %lld руб.\n", cost);
    p->bank.card -= cost;
    stats.total_events_impact += cost;
}

void car_insurance(struct Person* p, RUB amount) {
    RUB cost = 25000 + rand() % 25000;
    printf("\n СТРАХОВКА АВТОМОБИЛЯ\n");
    printf("  Годовая страховка: %lld руб.\n", cost);
    p->bank.card -= cost;
    stats.total_events_impact += cost;
}

void fitness_subscription(struct Person* p, RUB amount) {
    RUB cost = 15000 + rand() % 35000;
    printf("\n ФИТНЕС АБОНЕМЕНТ\n");
    printf("  Годовой абонемент: %lld руб.\n", cost);
    p->bank.card -= cost;
    stats.total_events_impact += cost;
}

void courses_expense(struct Person* p, RUB amount) {
    RUB cost = 20000 + rand() % 80000;
    printf("\n ПРОФЕССИОНАЛЬНЫЕ КУРСЫ\n");
    printf("  Оплата курсов: %lld руб.\n", cost);
    p->bank.card -= cost;
    stats.total_events_impact += cost;
}

void phone_break(struct Person* p, RUB amount) {
    RUB cost = 10000 + rand() % 60000;
    printf("\n РАЗБИЛ ТЕЛЕФОН\n");
    printf("  Ремонт/покупка нового: %lld руб.\n", cost);
    p->bank.card -= cost;
    stats.total_events_impact += cost;
}

void friend_wedding(struct Person* p, RUB amount) {
    RUB cost = 10000 + rand() % 40000;
    printf("\n СВАДЬБА ДРУГА\n");
    printf("  Подарок и расходы: %lld руб.\n", cost);
    p->bank.card -= cost;
    stats.total_events_impact += cost;
}

void tax_refund(struct Person* p, RUB amount) {
    RUB refund = 13000 + rand() % 37000;
    printf("\n НАЛОГОВЫЙ ВЫЧЕТ\n");
    printf("  Возврат налога: %lld руб.\n", refund);
    p->bank.card += refund;
    stats.salary_received += refund;
    stats.total_events_impact -= refund;
}

void inheritance_receive(struct Person* p, RUB amount) {
    RUB inheritance = 100000 + rand() % 900000;
    printf("\n ПОЛУЧЕНИЕ НАСЛЕДСТВА\n");
    printf("  Получено: %lld руб.\n", inheritance);
    p->bank.savings += inheritance;
    stats.total_events_impact -= inheritance;
}


void check_events(int year, int month, struct Person* p) {
    for (int i = 0; i < num_events; i++) {
        if (events[i].year == year && events[i].month == month && !events[i].triggered) {
            int roll = rand() % 100;
            printf("\n--- ПРОВЕРКА СОБЫТИЯ: %s (roll=%d, need<%d) ---\n", 
                   events[i].description, roll, events[i].probability);
            
            if (roll < events[i].probability) {
                printf(" СОБЫТИЕ СРАБОТАЛО!\n");
                if (events[i].effect != NULL) {
                    events[i].effect(p, events[i].financial_impact);
                } else {
                    printf("\n СОБЫТИЕ: %s\n", events[i].description);
                    printf("  Финансовое влияние: %lld руб.\n", events[i].financial_impact);
                    p->bank.card -= events[i].financial_impact;
                    stats.total_events_impact += events[i].financial_impact;
                }
                events[i].triggered = 1;
            } else {
                printf(" СОБЫТИЕ НЕ СРАБОТАЛО (вероятность %d%%)\n", events[i].probability);
            }
        }
    }
}


void init_stats() {
    stats.salary_received = 0;
    stats.housing_paid = 0;
    stats.food_paid = 0;
    stats.clothing_paid = 0;
    stats.gas_paid = 0;
    stats.cashback_received = 0;
    stats.interest_received = 0;
    stats.savings_moved = 0;
    stats.cash_spent = 0;
    stats.card_spent = 0;
    stats.cash_withdrawn = 0;
    stats.emergency_fund_used = 0;
    stats.taxes_paid = 0;
    stats.total_events_impact = 0;
}


void alice_init()
{
    alice.cash = 50000;
    alice.salary = 180000;
    alice.food = 15000;
    alice.clothing = 8000;

    alice.car.value = 2400000;
    alice.car.gas = 12000;

    alice.housing.rent = 45000;
    alice.housing.utilities = 7000;
    alice.housing.internet = 1000;
    alice.housing.mobile = 1500;
    
    alice.bank.card = 20000;
    alice.bank.savings = 0;
    alice.bank.rate = 0;
    
    alice.main_bank = &sberbank;
    
    init_stats();
}


void withdraw_cash(RUB amount)
{
    if (amount <= alice.bank.card) {
        alice.bank.card -= amount;
        alice.cash += amount;
        stats.cash_withdrawn += amount;
        printf("  Снято с карты: %lld руб.\n", amount);
    }
}


void alice_food()
{
    RUB food_cash_needed = alice.food * 0.3;
    
    if (alice.cash < food_cash_needed) {
        RUB needed = food_cash_needed - alice.cash;
        withdraw_cash(needed);
    }
    
    RUB food_cash = food_cash_needed;
    RUB food_card = alice.food * 0.7;
    
    alice.cash -= food_cash;
    alice.bank.card -= food_card;
    
    stats.food_paid += alice.food;
    stats.cash_spent += food_cash;
    stats.card_spent += food_card;
    
    if (alice.main_bank != NULL) {
        RUB cashback = food_card * alice.main_bank->card_cashback;
        alice.bank.card += cashback;
        stats.cashback_received += cashback;
        if (cashback > 0) printf("  Кэшбэк за еду: %lld руб.\n", cashback);
    }
    
    printf("  Еда: наличные %lld руб., карта %lld руб.\n", food_cash, food_card);
}


void alice_housing_expenses()
{
    RUB total_housing = alice.housing.rent + 
                        alice.housing.utilities + 
                        alice.housing.internet + 
                        alice.housing.mobile;
    
    RUB housing_cash_needed = total_housing * 0.5;
    
    if (alice.cash < housing_cash_needed) {
        RUB needed = housing_cash_needed - alice.cash;
        withdraw_cash(needed);
    }
    
    RUB housing_cash = housing_cash_needed;
    RUB housing_card = total_housing * 0.5;
    
    alice.cash -= housing_cash;
    alice.bank.card -= housing_card;
    
    stats.housing_paid += total_housing;
    stats.cash_spent += housing_cash;
    stats.card_spent += housing_card;
    
    if (alice.main_bank != NULL) {
        RUB cashback = housing_card * alice.main_bank->card_cashback;
        alice.bank.card += cashback;
        stats.cashback_received += cashback;
        if (cashback > 0) printf("  Кэшбэк за жилье: %lld руб.\n", cashback);
    }
    
    printf("  Жилье: наличные %lld руб., карта %lld руб. (всего %lld руб.)\n", 
           housing_cash, housing_card, total_housing);
}


void alice_car()
{
    RUB gas_cash_needed = alice.car.gas * 0.5;
    
    if (alice.cash < gas_cash_needed) {
        RUB needed = gas_cash_needed - alice.cash;
        withdraw_cash(needed);
    }
    
    RUB gas_cash = gas_cash_needed;
    RUB gas_card = alice.car.gas * 0.5;
    
    alice.cash -= gas_cash;
    alice.bank.card -= gas_card;
    
    stats.gas_paid += alice.car.gas;
    stats.cash_spent += gas_cash;
    stats.card_spent += gas_card;
    
    if (alice.main_bank != NULL) {
        RUB cashback = gas_card * alice.main_bank->card_cashback;
        alice.bank.card += cashback;
        stats.cashback_received += cashback;
        if (cashback > 0) printf("  Кэшбэк за бензин: %lld руб.\n", cashback);
    }
    
    printf("  Бензин: наличные %lld руб., карта %lld руб.\n", gas_cash, gas_card);
}

void alice_clothing()
{
    RUB clothing_cash_needed = alice.clothing * 0.2;  // 20% наличными
    
    if (alice.cash < clothing_cash_needed) {
        RUB needed = clothing_cash_needed - alice.cash;
        withdraw_cash(needed);
    }
    
    RUB clothing_cash = clothing_cash_needed;
    RUB clothing_card = alice.clothing * 0.8;  // 80% картой
    
    alice.cash -= clothing_cash;
    alice.bank.card -= clothing_card;
    
    stats.clothing_paid += alice.clothing;
    stats.cash_spent += clothing_cash;
    stats.card_spent += clothing_card;
    
    if (alice.main_bank != NULL) {
        RUB cashback = clothing_card * alice.main_bank->card_cashback;
        alice.bank.card += cashback;
        stats.cashback_received += cashback;
        if (cashback > 0) printf("  Кэшбэк за одежду: %lld руб.\n", cashback);
    }
    
    printf("  Одежда: наличные %lld руб., карта %lld руб.\n", clothing_cash, clothing_card);
}

void alice_salary(const int year, const int month)
{
    RUB salary_to_pay = alice.salary;
    
    if (month == 3 && year == 2026) {
        RUB old_salary = alice.salary;
        alice.salary = alice.salary * 1.5;
        salary_to_pay = old_salary;
        printf("  ПОВЫШЕНИЕ ЗАРПЛАТЫ! Теперь %lld руб./мес\n", alice.salary);
    }
    
    RUB tax = salary_to_pay * 0.13;
    RUB after_tax = salary_to_pay - tax;
    
    alice.bank.card += after_tax;
    stats.salary_received += after_tax;
    stats.taxes_paid += tax;
    
    printf("  Зарплата: %lld руб., налог 13%%: %lld руб., на руки: %lld руб.\n", 
           salary_to_pay, tax, after_tax);
}


void alice_bank_interest()
{
    if (alice.bank.savings <= 0) return;
    
    if (alice.main_bank != NULL && alice.main_bank->calculate_rate != NULL) {
        alice.bank.rate = alice.main_bank->calculate_rate(alice.bank.savings);
    }
    
    RUB monthly_interest = alice.bank.savings * (alice.bank.rate / 12.0 / 100.0);
    alice.bank.savings += monthly_interest;
    
    stats.interest_received += monthly_interest;
    
    if (monthly_interest > 0) {
        printf("  Проценты по сбережениям: %lld руб. (ставка %.2f%%)\n", 
               monthly_interest, alice.bank.rate);
    }
}


void alice_manage_savings(const int month)
{
     // Если на карте больше 100 тыс - перекладываем излишек в сбережения
    if (alice.bank.card > 100000) {
        RUB transfer = (alice.bank.card - 50000) * 0.7;
        if (transfer > 0 && alice.main_bank != NULL && 
            transfer >= alice.main_bank->min_deposit) {
            alice.bank.savings += transfer;
            alice.bank.card -= transfer;
            stats.savings_moved += transfer;
            printf("  Переложено на сбережения: %lld руб.\n", transfer);
        }
    }
    
    // Если на карте меньше 20 тыс - снимаем со сбережений
    if (alice.bank.card < 20000 && alice.bank.savings > 0) {
        RUB withdraw = (alice.bank.savings * 0.2);
        if (withdraw > 0) {
            if (alice.bank.savings - withdraw < alice.main_bank->min_deposit) {
                withdraw = alice.bank.savings;
            }
            alice.bank.savings -= withdraw;
            alice.bank.card += withdraw;
            stats.savings_moved -= withdraw;
            printf("  Снято со сбережений: %lld руб.\n", withdraw);
        }
    }

    // Обновляем ставку (на случай, если сумма изменилась)
    if (alice.main_bank != NULL && alice.main_bank->calculate_rate != NULL) {
        float new_rate = alice.main_bank->calculate_rate(alice.bank.savings);
        if (new_rate != alice.bank.rate) {
            alice.bank.rate = new_rate;
            printf("  Ставка по сбережениям изменена на %.2f%%\n", alice.bank.rate);
        }
    }
}


void alice_simulation()
{
    int year = 2026;
    int month = 2;
    
    // Инициализируем и планируем события
    init_events_dynamic();
    schedule_events();
    
    printf("Стартовое состояние:\n");
    printf("  Наличные: %lld руб.\n", alice.cash);
    printf("  Карта: %lld руб.\n", alice.bank.card);
    printf("  Сбережения: %lld руб.\n\n", alice.bank.savings);
    
    while (!(year == 2027 && month == 2)) {
        printf("\n--- %d.%d ---\n", month, year);
        
        // Проверяем жизненные события
        check_events(year, month, &alice);
        
        alice_housing_expenses();
        alice_food();
        alice_clothing();
        alice_car();

        
        alice_bank_interest();
        alice_manage_savings(month);
        
        alice_salary(year, month);
        
        printf("  ИТОГ МЕСЯЦА: Наличные %lld, Карта %lld, Сбережения %lld\n", 
               alice.cash, alice.bank.card, alice.bank.savings);
        
        month++;
        if (month == 13) {
            year++;
            month = 1;
            printf("\n НОВЫЙ ГОД: %d \n", year);
        }
    }
}


void print_results()
{
    RUB nominal_capital = alice.cash + alice.car.value + 
                          alice.bank.card + alice.bank.savings;
    
    float inflation_factor = 1.0 + INFLATION_RATE / 100.0;
    RUB real_capital = nominal_capital / inflation_factor;

    RUB monthly_housing = alice.housing.rent + alice.housing.utilities + 
                          alice.housing.internet + alice.housing.mobile;
    RUB monthly_total = monthly_housing + alice.food + alice.car.gas;
    
    printf("         ФИНАНСОВЫЙ ОТЧЕТ АЛИСЫ           \n");
    printf("      Период: Февраль 2026 - Февраль 2027\n");

    printf("\nТЕКУЩЕЕ СОСТОЯНИЕ\n");
    printf("  Наличные:                 %10lld руб.\n", alice.cash);
    printf("  Карта:                    %10lld руб.\n", alice.bank.card);
    printf("  Сбережения:               %10lld руб.\n", alice.bank.savings);
    printf("  Автомобиль:               %10lld руб.\n", alice.car.value);
    printf("  Текущая зарплата:         %10lld руб./мес\n", alice.salary);
    printf("  Процентная ставка:        %10.2f%%\n", alice.bank.rate);
    
    printf("КАПИТАЛ\n");
    printf("  Номинальный капитал:      %10lld руб.\n", nominal_capital);
    printf("  Реальный капитал (с\n");
    printf("  инфляцией %.1f%%):        %10lld руб.\n", 
           INFLATION_RATE, real_capital);

    printf("ДОХОДЫ (ЗА ГОД)\n");
    printf("  Получено зарплаты:        %10lld руб.\n", stats.salary_received);
    printf("  Получено кэшбэка:         %10lld руб.\n", stats.cashback_received);
    printf("  Получено процентов:       %10lld руб.\n", stats.interest_received);
    printf("  ВСЕГО ДОХОДОВ:            %10lld руб.\n", 
           stats.salary_received + stats.cashback_received + stats.interest_received);

    printf("РАСХОДЫ (ЗА ГОД)\n");
    printf("  Жилье:                    %10lld руб.\n", stats.housing_paid);
    printf("  Еда:                      %10lld руб.\n", stats.food_paid);
    printf("  Одежда:                   %10lld руб.\n", stats.clothing_paid);
    printf("  Бензин:                   %10lld руб.\n", stats.gas_paid);
    printf("  Налоги:                   %10lld руб.\n", stats.taxes_paid);
    printf("  ВСЕГО РАСХОДОВ:           %10lld руб.\n", 
           stats.housing_paid + stats.food_paid + stats.gas_paid + stats.taxes_paid);
  
    printf("ЖИЗНЕННЫЕ СОБЫТИЯ\n");
    printf("  Использовано резервов:    %10lld руб.\n", stats.emergency_fund_used);
    printf("  Чистый эффект событий:    %10lld руб.\n", stats.total_events_impact);
  
    printf("ДВИЖЕНИЕ НАЛИЧНЫХ\n");
    printf("  Снято с карты:            %10lld руб.\n", stats.cash_withdrawn);
    printf("  Потрачено наличными:      %10lld руб.\n", stats.cash_spent);
 
    printf("СПОСОБЫ ОПЛАТЫ\n");
    RUB total_paid = stats.cash_spent + stats.card_spent;
    if (total_paid > 0) {
        printf("  Оплачено наличными:       %10lld руб. (%.1f%%)\n", 
               stats.cash_spent, 
               (float)stats.cash_spent / total_paid * 100);
        printf("  Оплачено картой:          %10lld руб. (%.1f%%)\n", 
               stats.card_spent,
               (float)stats.card_spent / total_paid * 100);
    }
  
    printf("ДВИЖЕНИЕ СБЕРЕЖЕНИЙ\n");
    if (stats.savings_moved >= 0) {
        printf("  Переложено в сбережения:  %10lld руб.\n", stats.savings_moved);
    } else {
        printf("  Снято со сбережений:      %10lld руб.\n", -stats.savings_moved);
    }
    
    printf("ЕЖЕМЕСЯЧНЫЕ РАСХОДЫ\n");
    printf("  Жилье:                    %10lld руб./мес\n", monthly_housing);
    printf("  Еда:                      %10lld руб./мес\n", alice.food);
    printf("  Бензин:                   %10lld руб./мес\n", alice.car.gas);
    printf("  ВСЕГО:                    %10lld руб./мес\n", monthly_total);
    
    printf("ИНФОРМАЦИЯ О БАНКЕ\n");
    printf("  Банк:                     %s\n", alice.main_bank->name);
    printf("  Кэшбэк по карте:          %.1f%%\n", 
           alice.main_bank->card_cashback * 100);
    printf("  Минимальная сумма депозита: %lld руб.\n", alice.main_bank->min_deposit);
    
    printf("ПРОИЗОШЕДШИЕ СОБЫТИЯ\n");
    int events_occurred = 0;
    for (int i = 0; i < num_events; i++) {
        if (events[i].triggered) {
            printf("  ✓ %d.%d: %s\n", events[i].month, events[i].year, events[i].description);
            events_occurred++;
        }
    }
    if (events_occurred == 0) {
        printf("  Не произошло ни одного события\n");
    }

}

int main()
{
    printf("ФИНАНСОВАЯ СИМУЛЯЦИЯ С ЖИЗНЕННЫМИ СОБЫТИЯМИ\n");
    
    alice_init();
    alice_simulation();
    print_results();
    
    return 0;
}