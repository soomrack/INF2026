#include <stdio.h>

using RUB = long long int;

// --- DATA STRUCTURES ---
struct Car {
    RUB value;
    RUB gas;
};

struct Bank {
    RUB account;
    RUB deposit;
};

struct Inflation {
    // годовая инфляция, %
    float food;
    float car_value;
    float gas;
    float pet_food;
};

struct Pet {
    bool enabled; // 0/1
    RUB feed;    // ежемесячные расходы
};

// --- PERSON ---
struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    struct Car car;

    struct Bank bank;
    struct Inflation infl;
    struct Pet dog;
};

struct Person Alice;

float pp = 14.5f; // годовая ставка, %

// --- HELPERS ---
static RUB rub_percent_month(RUB base, float annual_percent)
{
    // простая месячная ставка = annual/12/100
    double monthly_rate = (double)annual_percent / 12.0 / 100.0;
    return (RUB)((double)base * monthly_rate);
}

static void alice_sync_capital()
{
    Alice.capital = Alice.bank.account + Alice.bank.deposit;
}

// --- MAIN ACTIONS ---
void alice_salary(const int month, const int year)
{
    if ((month == 8) && (year == 2026)) {
        Alice.salary = (RUB)((double)Alice.salary * 1.5);
    }
    Alice.bank.account += Alice.salary; // зарплата на счет
}

void alice_bank_interest()
{
    // проценты начисляются на вклад
    Alice.bank.deposit += rub_percent_month(Alice.bank.deposit, pp);
}

void alice_food()
{
    Alice.bank.account -= Alice.food; // еда со счета
}

void alice_car()
{
    Alice.bank.account -= Alice.car.gas; // бензин со счета
}

// --- OTHER ACTIONS ---
static void alice_inflation()
{
    Alice.food     += rub_percent_month(Alice.food, Alice.infl.food);
    Alice.car.value+= rub_percent_month(Alice.car.value, Alice.infl.car_value);
    Alice.car.gas  += rub_percent_month(Alice.car.gas, Alice.infl.gas);

    if (Alice.dog.enabled) {
        Alice.dog.feed += rub_percent_month(Alice.dog.feed, Alice.infl.pet_food);
    }
}

static void alice_pet()
{
    if (Alice.dog.enabled) {
        Alice.bank.account -= Alice.dog.feed;
    }
}

static void alice_transfer_to_deposit()
{
    // оставляем на счете расходы этого месяца, остальное на вклад
    RUB reserve = Alice.food + Alice.car.gas + (Alice.dog.enabled ? Alice.dog.feed : 0);
    RUB extra = Alice.bank.account - reserve;

    if (extra > 0) {
        Alice.bank.account -= extra;
        Alice.bank.deposit += extra;
    }
}

// --- DEPOSIT ---
static void alice_cover_account_from_deposit()
{
    // если после расходов счет в минусе — закрываем минус со вклада
    if (Alice.bank.account >= 0) return;

    RUB need = -Alice.bank.account;
    RUB take = (need <= Alice.bank.deposit) ? need : Alice.bank.deposit;

    Alice.bank.deposit -= take;
    Alice.bank.account += take;
}

// --- INIT --- SIM --- PRINT
void alice_init()
{
    Alice.capital = 0;
    Alice.salary = 180'000;
    Alice.food = 20'000;

    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;

    // банк
    Alice.bank.account = 0;
    Alice.bank.deposit = 0;

    // собака
    Alice.dog.enabled = 1;
    Alice.dog.feed = 2'000;

    // инфляция
    Alice.infl.food = 8.0f;
    Alice.infl.car_value = 6.0f;
    Alice.infl.gas = 10.0f;
    Alice.infl.pet_food = 9.0f;

    alice_sync_capital();
}

void simulation()
{
    int month = 2;
    int year = 2026;

    while ( !((month == 3) && (year == 2027)) ) {

        // 1) цены выросли (инфляция отдельно на еду/машину/бензин/питомца)
        alice_inflation();

        // 2) зарплата на счет
        alice_salary(month, year);

        // 3) переводим лишнее на вклад
        alice_transfer_to_deposit();

        // 4) списываем расходы со счета
        alice_food();
        alice_car();
        alice_pet();

        // 5) если счет ушел в минус, берем со вклада
        alice_cover_account_from_deposit();

        // 6) проценты на вклад
        alice_bank_interest();

        // 7) обновляем итоговый капитал
        alice_sync_capital();

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}

void print_results()
{
    printf("Salary = %lld\n", Alice.salary);
    printf("Capital = %lld\n", Alice.capital);

    printf("Bank.account = %lld\n", Alice.bank.account);
    printf("Bank.deposit = %lld\n", Alice.bank.deposit);

    printf("Food = %lld\n", Alice.food);
    printf("Car value = %lld\n", Alice.car.value);
    printf("Car gas = %lld\n", Alice.car.gas);

    if (Alice.dog.enabled == 1){
       printf("Dog's feed = %lld\n", Alice.dog.feed);

    }
}

// --- MAIN FUNCTION ---
int main()
{
    alice_init();
    simulation();
    print_results();
}
