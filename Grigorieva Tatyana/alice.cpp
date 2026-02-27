#include <stdio.h>

using RUB = long long int;

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
    if (sum >= 3'000'000) return 12.5;
    if (sum > 10'000) return 11.5;
    return 0.1;
}

Bank sberbank = {
    "Сбербанк",
    11.5,
    0.01,
    10'000,
    sberbank_rate_calculator
};

struct Person {
    RUB salary;
    RUB cash;
    RUB food;
    Car car;
    Housing housing;
    BankPackage bank;
    Bank* main_bank;
};
struct Person alice;

const float INFLATION_RATE = 8.5;

struct MonthlyStats {
    RUB salary_received;
    RUB housing_paid;
    RUB food_paid;
    RUB gas_paid;
    RUB cashback_received;
    RUB interest_received;
    RUB savings_moved;
    RUB cash_spent;
    RUB card_spent;
    RUB cash_withdrawn;
} stats;

void init_stats() {
    stats.salary_received = 0;
    stats.housing_paid = 0;
    stats.food_paid = 0;
    stats.gas_paid = 0;
    stats.cashback_received = 0;
    stats.interest_received = 0;
    stats.savings_moved = 0;
    stats.cash_spent = 0;
    stats.card_spent = 0;
    stats.cash_withdrawn = 0;
}

void alice_init()
{
    alice.cash = 50'000;
    alice.salary = 180'000;
    alice.food = 15'000;

    alice.car.value = 2'400'000;
    alice.car.gas = 12'000;

    alice.housing.rent = 45'000;
    alice.housing.utilities = 7'000;
    alice.housing.internet = 1'000;
    alice.housing.mobile = 1'500;
    
    alice.bank.card = 20'000;
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
    
    if (alice.main_bank != nullptr) {
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
    
    if (alice.main_bank != nullptr) {
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
    
    if (alice.main_bank != nullptr) {
        RUB cashback = gas_card * alice.main_bank->card_cashback;
        alice.bank.card += cashback;
        stats.cashback_received += cashback;
        if (cashback > 0) printf("  Кэшбэк за бензин: %lld руб.\n", cashback);
    }
    
    printf("  Бензин: наличные %lld руб., карта %lld руб.\n", gas_cash, gas_card);
}

void alice_salary(const int year, const int month)
{
    RUB salary_to_pay = alice.salary;
    
    if (month == 3 && year == 2026) {
        RUB old_salary = alice.salary;
        alice.salary *= 1.5;
        salary_to_pay = old_salary;
        printf("  ПОВЫШЕНИЕ ЗАРПЛАТЫ! Теперь %lld руб./мес\n", alice.salary);
    }
    
    alice.bank.card += salary_to_pay;
    stats.salary_received += salary_to_pay;
    
    printf("  Зарплата получена на карту: %lld руб.\n", salary_to_pay);
}

void alice_bank_interest()
{
    if (alice.bank.savings <= 0) return;
    
    if (alice.main_bank != nullptr && alice.main_bank->calculate_rate != nullptr) {
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
    if (alice.bank.card > 100'000) {
        RUB transfer = (alice.bank.card - 50'000) * 0.7;
        if (transfer > 0 && alice.main_bank != nullptr && 
            transfer >= alice.main_bank->min_deposit) {
            alice.bank.savings += transfer;
            alice.bank.card -= transfer;
            stats.savings_moved += transfer;
            printf("  Переложено на сбережения: %lld руб.\n", transfer);
        }
    }
    
    // Если на карте меньше 20 тыс - снимаем со сбережений
    if (alice.bank.card < 20'000 && alice.bank.savings > 0) {
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
    if (alice.main_bank != nullptr && alice.main_bank->calculate_rate != nullptr) {
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
    
    
    printf("Стартовое состояние:\n");
    printf("  Наличные: %lld руб.\n", alice.cash);
    printf("  Карта: %lld руб.\n", alice.bank.card);
    printf("  Сбережения: %lld руб.\n\n", alice.bank.savings);
    
    while (!(year == 2027 && month == 2)) {
        printf("\n--- %d.%d ---\n", month, year);
        
        alice_housing_expenses();
        alice_food();
        alice_car();
        
        alice_bank_interest();
        alice_manage_savings(month);
        
        alice_salary(year, month);
        
        printf("  ИТОГ МЕСЯЦА: Наличные %lld, Карта %lld, Сбережения %lld\n", 
               alice.cash, alice.bank.card, alice.bank.savings);
        
        ++month;
        if (month == 13) {
            ++year;
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
    
    printf("ТЕКУЩЕЕ СОСТОЯНИЕ \n");
    printf("  Наличные:                 %lld руб.\n", alice.cash);
    printf("  Карта:                    %lld руб.\n", alice.bank.card);
    printf("  Сбережения:               %lld руб.\n", alice.bank.savings);
    printf("  Автомобиль:               %lld руб.\n", alice.car.value);
    printf("  Текущая зарплата:         %lld руб./мес\n", alice.salary);
    printf("  Процентная ставка:        %.2f%%\n", alice.bank.rate);
    printf("\n");
    
    printf(" КАПИТАЛ \n");
    printf("  Номинальный капитал:      %lld руб.\n", nominal_capital);
    printf("  Реальный капитал (с\n");
    printf("  инфляцией %.1f%%):        %lld руб.\n", 
           INFLATION_RATE, real_capital);
    printf("\n");
    
    printf("ДОХОДЫ (ЗА ГОД)\n");
    printf("  Получено зарплаты:        %lld руб.\n", stats.salary_received);
    printf("  Получено кэшбэка:         %lld руб.\n", stats.cashback_received);
    printf("  Получено процентов:       %lld руб.\n", stats.interest_received);
    printf("  ВСЕГО ДОХОДОВ:            %lld руб.\n", 
           stats.salary_received + stats.cashback_received + stats.interest_received);
    printf("\n");
    
    printf("РАСХОДЫ (ЗА ГОД)\n");
    printf("  Жилье:                    %lld руб.\n", stats.housing_paid);
    printf("  Еда:                      %lld руб.\n", stats.food_paid);
    printf("  Бензин:                   %lld руб.\n", stats.gas_paid);
    printf("  ВСЕГО РАСХОДОВ:           %lld руб.\n", 
           stats.housing_paid + stats.food_paid + stats.gas_paid);
    printf("\n");
    
    printf("ДВИЖЕНИЕ НАЛИЧНЫХ\n");
    printf("  Снято с карты:            %lld руб.\n", stats.cash_withdrawn);
    printf("  Потрачено наличными:      %lld руб.\n", stats.cash_spent);
    printf("\n");
    
    printf("СПОСОБЫ ОПЛАТЫ\n");
    RUB total_paid = stats.cash_spent + stats.card_spent;
    if (total_paid > 0) {
        printf("  Оплачено наличными:       %lld руб. (%.1f%%)\n", 
               stats.cash_spent, 
               (float)stats.cash_spent / total_paid * 100);
        printf("  Оплачено картой:          %lld руб. (%.1f%%)\n", 
               stats.card_spent,
               (float)stats.card_spent / total_paid * 100);
    }
    printf("\n");
    
    printf("ДВИЖЕНИЕ СБЕРЕЖЕНИЙ\n");
    if (stats.savings_moved >= 0) {
        printf("  Переложено в сбережения:  %lld руб.\n", stats.savings_moved);
    } else {
        printf("  Снято со сбережений:      %lld руб.\n", -stats.savings_moved);
    }
    printf("\n");
    
    printf("ЕЖЕМЕСЯЧНЫЕ РАСХОДЫ\n");
    printf("  Жилье:                    %lld руб./мес\n", monthly_housing);
    printf("  Еда:                      %lld руб./мес\n", alice.food);
    printf("  Бензин:                   %lld руб./мес\n", alice.car.gas);
    printf("  ВСЕГО:                    %lld руб./мес\n", monthly_total);
    if (monthly_total > 0) {
        printf("  Доля жилья:               %.1f%%\n", 
               (float)monthly_housing / monthly_total * 100);
    }
    printf("\n");
    
    printf("ИНФОРМАЦИЯ О БАНКЕ\n");
    printf("  Банк:                     %s\n", alice.main_bank->name);
    printf("  Кэшбэк по карте:          %.1f%%\n", 
           alice.main_bank->card_cashback * 100);
    printf("  Минимальная сумма депозита: %lld руб.\n", alice.main_bank->min_deposit);
    printf("\n");
    
    RUB total_income = stats.salary_received + stats.cashback_received + stats.interest_received;
    RUB total_expenses = stats.housing_paid + stats.food_paid + stats.gas_paid;
    RUB expected_change = total_income - total_expenses;
    RUB actual_change = (alice.cash + alice.bank.card + alice.bank.savings) - 
                        (50'000 + 20'000);
    
}

int main()
{
    alice_init();
    alice_simulation();
    print_results();
    return 0;
}