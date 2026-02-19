#include <stdio.h>

using RUB = long long int;  // C++

struct Car {
    RUB value;
    RUB gas;
};

struct Housing {
    RUB rent;           // аренда квартиры
    RUB utilities;      // коммунальные платежи (свет, вода, газ)
    RUB internet;       // интернет
    RUB mobile;         // мобильная связь
};

// Структура для пакета услуг банка
struct BankPackage {
    RUB account;      // счет
    RUB deposit;      // депозит
    float interest;   // процент на депозит
};

struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    Car car;
    BankPackage bank;  // добавляем банковский пакет
    Housing housing;
};
struct Person alice;

// Годовая инфляция в процентах
const float INFLATION_RATE = 8.5;  // 8.5% годовых

void alice_init()
{
    alice.capital = 0;
    alice.salary = 180'000;
    alice.food = 15'000;

    alice.car.value = 2'400'000;
    alice.car.gas = 12'000;

      // Жилье и коммунальные услуги
    alice.housing.rent = 45'000;        // аренда квартиры
    alice.housing.utilities = 7'000;    // коммунальные платежи
    alice.housing.internet = 1'000;     // интернет
    alice.housing.mobile = 1'500;       // мобильная связь (тариф)
    
    // Инициализация банковского пакета
    alice.bank.account = 0;
    alice.bank.deposit = 0;
    alice.bank.interest = 0;
}

float sberbank_interest(RUB sum)
{
    if (sum > 10'000 && sum < 3'000'000) {
        return 11.5;
    }

    if (sum >= 3'000'000) {
        return 12.5;
    }

    return 0.1;
}

// Открыли депозит
void open_deposit(RUB amount)
{
    if (amount <= alice.bank.account) {
        alice.bank.deposit += amount;
        alice.bank.account -= amount;
        alice.bank.interest = sberbank_interest(alice.bank.deposit);
    }
}

// Закрыли депозит
void close_deposit(RUB amount)
{
    if (amount <= alice.bank.deposit) {
        alice.bank.deposit -= amount;
        alice.bank.account += amount;
        alice.bank.interest = sberbank_interest(alice.bank.deposit);
    }
}

void alice_salary(const int year, const int month)
{
    if (month == 3 && year == 2026) {
        alice.salary *= 1.5;
    }
    
    alice.capital += alice.salary;
    // Часть зарплаты кладем на счет в банке
    alice.bank.account += alice.salary * 0.3;  // 30% на счет
    alice.capital -= alice.salary * 0.3;
}

void alice_food()
{
    alice.capital -= alice.food;
    alice.bank.account -= alice.food * 0.7;  // 70% трат с банковского счета
}

void alice_housing_expenses()
{
    RUB total_housing = alice.housing.rent + 
                        alice.housing.utilities + 
                        alice.housing.internet + 
                        alice.housing.mobile;
    
    printf("  Housing costs: %lld \n", total_housing); //расходы на жилье в сумме
    
    // Платим за жилье (50% наличными, 50% с карты)
    alice.capital -= total_housing * 0.5;
    alice.bank.account -= total_housing * 0.5;
    
    if (alice.bank.account < 0) {
        alice.capital += alice.bank.account;
        alice.bank.account = 0;
    }
}

// Расчет ежемесячных расходов
    RUB monthly_housing = alice.housing.rent + alice.housing.utilities + 
                          alice.housing.internet + alice.housing.mobile;
    RUB monthly_total = monthly_housing + alice.food + alice.car.gas;
    
void print_results()
{
    // Расчет реального капитала с учетом инфляции
    RUB nominal_capital = alice.capital + alice.car.value + 
                          alice.bank.account + alice.bank.deposit;
    
    // Применяем инфляцию за период моделирования (1 год)
    float inflation_factor = 1.0 + INFLATION_RATE / 100.0;
    RUB real_capital = nominal_capital / inflation_factor;

    // Расчет ежемесячных расходов
    RUB monthly_housing = alice.housing.rent + alice.housing.utilities + 
                          alice.housing.internet + alice.housing.mobile;
    RUB monthly_total = monthly_housing + alice.food + alice.car.gas;
    
    
    
    printf("Salary %lld \n", alice.salary);
    printf("Capital = %lld \n", alice.capital);
    printf("Bank account = %lld \n", alice.bank.account);
    printf("Bank Deposit = %lld \n", alice.bank.deposit);
    printf("Bank interest = %.2f%%\n", alice.bank.interest);
    printf("Nominal capital = %lld \n", nominal_capital);
    printf("Inflation rate = %.1f%%\n", INFLATION_RATE);
    printf("Real capital = %lld  \n", real_capital);
    printf("Monthly housing costs: %lld \n", monthly_housing);
    printf("Monthly total costs: %lld \n", monthly_total);
    printf("Percentage of housing costs: %.1f%%\n", 
           (float)monthly_housing / monthly_total * 100);
}


   

void alice_car()
{
    alice.capital -= alice.car.gas;
    alice.bank.account -= alice.car.gas * 0.5;  // 50% трат на бензин со счета
}

void alice_bank_interest()
{
    // Начисление процентов на депозит
    if (alice.bank.deposit > 0) {
        RUB monthly_interest = alice.bank.deposit * (alice.bank.interest / 12.0 / 100.0);
        alice.bank.deposit += monthly_interest;
        alice.capital += monthly_interest;
    }
    
    // Начисление обычных процентов на счет (если ставка другая)
    float account_interest = 0.5;  // 0.5% на остаток по счету
    if (alice.bank.account > 0) {
        RUB account_monthly = alice.bank.account * (account_interest / 12.0 / 100.0);
        alice.bank.account += account_monthly;
        alice.capital += account_monthly;
    }
}

// Функция для стратегического управления депозитом
void alice_investment_strategy(const int month)
{
    // В начале каждого квартала открываем депозит, если есть свободные средства
    if (month % 3 == 1 && alice.bank.account > 100'000) {
        open_deposit(alice.bank.account * 0.5);  // 50% свободных средств на депозит
    }
    
    // В конце года снимаем часть депозита для крупных покупок
    if (month == 12 && alice.bank.deposit > 500'000) {
        close_deposit(alice.bank.deposit * 0.3);  // снимаем 30% депозита
    }
}

void alice_simulation()
{
    int year = 2026;
    int month = 2;
    
    while ( !(year == 2027 && month == 2)) {
        alice_housing_expenses();
        alice_food();
        alice_car();
        alice_bank_interest();
        alice_salary(year, month);
        alice_investment_strategy(month);
        
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}

int main()
{
    alice_init();
    
    alice_simulation();
    
    print_results();
    
    return 0;
}