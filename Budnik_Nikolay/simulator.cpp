#include <cstdio>
#include <cstdint>

using RUB = long long;
using Percent = float;

struct Car {
    RUB market_value;
    RUB fuel_month;
};

struct Bank {
    RUB ch;
    RUB sv;
    RUB loan;
    RUB loan_pay_month;
    Percent loan_rate;
};

struct Infl {
    Percent food;
    Percent car_value;
    Percent fuel;
    Percent pet_food;
    Percent rent;
    Percent clothes;
    Percent health;
};

struct Pet {
    bool alive;
    RUB feed_month;
};

struct Health {
    int hp;
    RUB health_month;
};

struct Family {
    bool married;
    int kids;
    RUB kids_food_month;
    RUB kids_education_month;
};

struct Housing {
    bool owned;
    RUB rent_month;
    RUB house_value;
};

struct WorkTaxi {
    RUB orders_month;
    Percent service_fee;
    RUB expenses;
    RUB salary;
};

struct Person {
    const char* name;
    int age;
    RUB cap;

    RUB food_month;
    RUB leisure_month;
    RUB clothes_month;

    WorkTaxi work_taxi;
    Bank bank;
    Housing house;
    Car car;
    Family family;
    Pet pet;
    Health health;
    Infl infl;

    RUB investments;
    RUB last_unexpected;
};

Person Dilshot;
Person Azurbek;
Person Analbek;

Percent kSavingsAnnualRate = 14.5f;

RUB mon_percent(RUB base, Percent annual)
{
    double month_rate = static_cast<double>(annual) / 12.0 / 100.0;
    return static_cast<RUB>(static_cast<double>(base) * month_rate);
}

// Пересчёт капитала: активы минус долг
void recalc_cap(Person& p)
{
    RUB assets = 0;
    assets += p.bank.ch;
    assets += p.bank.sv;
    assets += p.car.market_value;
    assets += p.investments;

    if (p.house.owned) {
        assets += p.house.house_value;
    }

    p.cap = assets - p.bank.loan;
}

// Зарплата водителя Яндекс Такси:
// выручка - комиссия - сопутствующие расходы
void calc_salary_taxi(Person& p)
{
    RUB gross = p.work_taxi.orders_month;
    RUB fee = static_cast<RUB>(
        static_cast<double>(gross) * p.work_taxi.service_fee / 100.0
    );
    RUB costs = p.work_taxi.expenses;

    p.work_taxi.salary = gross - fee - costs;

    if (p.work_taxi.salary < 0) {
        p.work_taxi.salary = 0;
    }
}

void add_salary(Person& p)
{
    calc_salary_taxi(p);
    p.bank.ch += p.work_taxi.salary;
}

// Излишек с текущего счёта переводится в сбережения
void move_to_savings(Person& p)
{
    RUB reserve = 0;
    reserve += p.food_month;
    reserve += p.car.fuel_month;
    reserve += p.health.health_month;
    reserve += p.leisure_month;
    reserve += p.clothes_month;
    reserve += p.family.kids_food_month;
    reserve += p.family.kids_education_month;

    if (!p.house.owned) {
        reserve += p.house.rent_month;
    }

    if (p.pet.alive) {
        reserve += p.pet.feed_month;
    }

    RUB extra = p.bank.ch - reserve;

    if (extra > 0) {
        p.bank.ch -= extra;
        p.bank.sv += extra;
    }
}

void pay_loan(Person& p)
{
    if (p.bank.loan <= 0) {
        return;
    }

    RUB payment = p.bank.loan_pay_month;
    if (payment > p.bank.loan) {
        payment = p.bank.loan;
    }

    p.bank.loan -= payment;
    p.bank.ch -= payment;

    if (p.bank.loan > 0) {
        p.bank.loan += mon_percent(p.bank.loan, p.bank.loan_rate);
    }
}

void fix_negative_checking(Person& p)
{
    if (p.bank.ch >= 0) {
        return;
    }

    RUB need = -p.bank.ch;
    RUB take = (need <= p.bank.sv) ? need : p.bank.sv;

    p.bank.sv -= take;
    p.bank.ch += take;
}

void add_savings_income(Person& p)
{
    if (p.bank.sv <= 0) {
        return;
    }

    p.bank.sv += mon_percent(p.bank.sv, kSavingsAnnualRate);
}

void pay_food(Person& p)
{
    p.bank.ch -= p.food_month;

    if (p.family.kids > 0) {
        p.bank.ch -= p.family.kids_food_month;
        p.bank.ch -= p.family.kids_education_month;
    }
}

void pay_housing(Person& p)
{
    if (!p.house.owned) {
        p.bank.ch -= p.house.rent_month;
    }
}

void pay_car(Person& p)
{
    p.bank.ch -= p.car.fuel_month;
}

void pay_pet(Person& p)
{
    if (p.pet.alive) {
        p.bank.ch -= p.pet.feed_month;
    }
}

void pay_health(Person& p)
{
    p.bank.ch -= p.health.health_month;
}

void pay_leisure(Person& p)
{
    p.bank.ch -= p.leisure_month;
}

void pay_clothes(Person& p)
{
    p.bank.ch -= p.clothes_month;
}

// Небольшие разовые расходы по месяцам
void pay_unexpected(Person& p, int m, int y)
{
    RUB cost = 0;

    if (m == 5) {
        cost = 5000;
    }
    if (m == 11) {
        cost = 8000;
    }
    if (p.name == "Analbek" && m == 3 && y == 2026) {
        cost = 15000;
    }

    p.last_unexpected = cost;
    p.bank.ch -= cost;
}

// Ежемесячное повышение расходов и некоторых активов
void add_inflation(Person& p)
{
    p.food_month += mon_percent(p.food_month, p.infl.food);
    p.car.market_value += mon_percent(p.car.market_value, p.infl.car_value);
    p.car.fuel_month += mon_percent(p.car.fuel_month, p.infl.fuel);
    p.house.rent_month += mon_percent(p.house.rent_month, p.infl.rent);
    p.clothes_month += mon_percent(p.clothes_month, p.infl.clothes);
    p.health.health_month += mon_percent(p.health.health_month, p.infl.health);
    p.family.kids_food_month += mon_percent(p.family.kids_food_month, p.infl.food);
    p.family.kids_education_month += mon_percent(p.family.kids_education_month, p.infl.food);

    if (p.pet.alive) {
        p.pet.feed_month += mon_percent(p.pet.feed_month, p.infl.pet_food);
    }
}

void update_health(Person& p, int m)
{
    if (m == 2 || m == 3) {
        p.health.hp -= 1;
    }
    if (m == 6) {
        p.health.hp += 1;
    }
    if (m == 10) {
        p.health.hp -= 2;
    }

    if (p.health.hp < 0) {
        p.health.hp = 0;
    }
    if (p.health.hp > 100) {
        p.health.hp = 100;
    }
}

void update_age(Person& p, int m)
{
    if (m == 1) {
        p.age += 1;
    }
}

void init_dilshot(Person& p)
{
    p.name = "Dilshot";
    p.age = 32;

    p.work_taxi.orders_month = 220000;
    p.work_taxi.service_fee = 22.0f;
    p.work_taxi.expenses = 45000;
    calc_salary_taxi(p);

    p.bank.ch = 10000;
    p.bank.sv = 50000;
    p.bank.loan = 500000;
    p.bank.loan_pay_month = 20000;
    p.bank.loan_rate = 18.0f;

    p.house.owned = true;
    p.house.rent_month = 0;
    p.house.house_value = 3000000;

    p.car.market_value = 1200000;
    p.car.fuel_month = 12000;

    p.family.married = true;
    p.family.kids = 1;
    p.family.kids_food_month = 6000;
    p.family.kids_education_month = 4000;

    p.pet.alive = false;
    p.pet.feed_month = 0;

    p.health.hp = 80;
    p.health.health_month = 4000;

    p.infl.food = 9.0f;
    p.infl.car_value = 5.0f;
    p.infl.fuel = 11.0f;
    p.infl.pet_food = 0.0f;
    p.infl.rent = 8.0f;
    p.infl.clothes = 5.5f;
    p.infl.health = 7.0f;

    p.food_month = 18000;
    p.leisure_month = 8000;
    p.clothes_month = 4000;

    p.investments = 100000;
    p.last_unexpected = 0;
    p.cap = 0;

    recalc_cap(p);
}

void init_azurbek(Person& p)
{
    p.name = "Azurbek";
    p.age = 26;

    p.work_taxi.orders_month = 190000;
    p.work_taxi.service_fee = 25.0f;
    p.work_taxi.expenses = 50000;
    calc_salary_taxi(p);

    p.bank.ch = 5000;
    p.bank.sv = 0;
    p.bank.loan = 0;
    p.bank.loan_pay_month = 0;
    p.bank.loan_rate = 0.0f;

    p.house.owned = false;
    p.house.rent_month = 25000;
    p.house.house_value = 0;

    p.car.market_value = 600000;
    p.car.fuel_month = 10000;

    p.family.married = false;
    p.family.kids = 0;
    p.family.kids_food_month = 0;
    p.family.kids_education_month = 0;

    p.pet.alive = true;
    p.pet.feed_month = 1500;

    p.health.hp = 70;
    p.health.health_month = 5000;

    p.infl.food = 10.0f;
    p.infl.car_value = 4.0f;
    p.infl.fuel = 12.0f;
    p.infl.pet_food = 9.5f;
    p.infl.rent = 9.0f;
    p.infl.clothes = 6.0f;
    p.infl.health = 8.0f;

    p.food_month = 15000;
    p.leisure_month = 6000;
    p.clothes_month = 3000;

    p.investments = 0;
    p.last_unexpected = 0;
    p.cap = 0;

    recalc_cap(p);
}

void init_analbek(Person& p)
{
    p.name = "Analbek";
    p.age = 35;

    p.work_taxi.orders_month = 160000;
    p.work_taxi.service_fee = 28.0f;
    p.work_taxi.expenses = 55000;
    calc_salary_taxi(p);

    p.bank.ch = 2000;
    p.bank.sv = 0;
    p.bank.loan = 200000;
    p.bank.loan_pay_month = 15000;
    p.bank.loan_rate = 20.0f;

    p.house.owned = false;
    p.house.rent_month = 20000;
    p.house.house_value = 0;

    p.car.market_value = 0;
    p.car.fuel_month = 0;

    p.family.married = true;
    p.family.kids = 2;
    p.family.kids_food_month = 10000;
    p.family.kids_education_month = 6000;

    p.pet.alive = false;
    p.pet.feed_month = 0;

    p.health.hp = 60;
    p.health.health_month = 7000;

    p.infl.food = 11.0f;
    p.infl.car_value = 0.0f;
    p.infl.fuel = 0.0f;
    p.infl.pet_food = 0.0f;
    p.infl.rent = 10.0f;
    p.infl.clothes = 7.0f;
    p.infl.health = 9.0f;

    p.food_month = 14000;
    p.leisure_month = 3000;
    p.clothes_month = 2000;

    p.investments = 0;
    p.last_unexpected = 0;
    p.cap = 0;

    recalc_cap(p);
}

// Месячные события персонажей
void update_dilshot(int m, int y)
{
    (void)y;

    Dilshot.leisure_month = (m == 6) ? 20000 : 8000;

    if (m == 9) {
        Dilshot.family.kids_education_month += 10000;
    }
}

void update_azurbek(int m, int y)
{
    (void)y;

    if (m == 2) {
        Azurbek.work_taxi.orders_month = 100000;
        Azurbek.work_taxi.service_fee = 25.0f;
        Azurbek.work_taxi.expenses = 40000;
    }

    if (m == 5) {
        Azurbek.work_taxi.orders_month = 230000;
        Azurbek.work_taxi.service_fee = 23.0f;
        Azurbek.work_taxi.expenses = 50000;
    }

    Azurbek.leisure_month = (m == 7) ? 12000 : 6000;
}

void update_analbek(int m, int y)
{
    if (m == 1 && y == 2027) {
        Analbek.work_taxi.orders_month = 180000;
        Analbek.work_taxi.service_fee = 26.0f;
        Analbek.work_taxi.expenses = 50000;
    }

    Analbek.leisure_month = (m == 12) ? 5000 : 3000;
}

// Один месяц симуляции
void step_month(Person& p, int m, int y)
{
    add_inflation(p);
    add_salary(p);
    move_to_savings(p);

    pay_food(p);
    pay_housing(p);
    pay_car(p);
    pay_pet(p);
    pay_health(p);
    pay_leisure(p);
    pay_clothes(p);
    pay_unexpected(p, m, y);

    pay_loan(p);
    fix_negative_checking(p);
    add_savings_income(p);

    update_health(p, m);
    update_age(p, m);

    recalc_cap(p);
}

void run_simulation()
{
    int m = 2;
    int y = 2026;

    while (!(m == 3 && y == 2027)) {
        update_dilshot(m, y);
        update_azurbek(m, y);
        update_analbek(m, y);

        step_month(Dilshot, m, y);
        step_month(Azurbek, m, y);
        step_month(Analbek, m, y);

        m++;
        if (m == 13) {
            m = 1;
            y++;
        }
    }
}

void print_person(const Person& p)
{
    std::printf("Person: %s\n", p.name);
    std::printf("\tAge = %d\n", p.age);
    std::printf("\tSalary (RUB) = %lld\n", p.work_taxi.salary);
    std::printf("\tCap (RUB) = %lld\n", p.cap);

    std::printf("\tBank ch = %lld\n", p.bank.ch);
    std::printf("\tBank sv = %lld\n", p.bank.sv);
    std::printf("\tBank loan = %lld\n", p.bank.loan);

    std::printf("\tFood / month = %lld\n", p.food_month);
    std::printf("\tFuel / month = %lld\n", p.car.fuel_month);
    std::printf("\tRent / month = %lld\n", p.house.rent_month);

    if (p.pet.alive) {
        std::printf("\tPet food / month = %lld\n", p.pet.feed_month);
    } else {
        std::printf("\tNo pet\n");
    }

    std::printf("\tHealth HP = %d\n", p.health.hp);
    std::printf("\tHealthcare / month = %lld\n", p.health.health_month);
    std::printf("\tMarried = %d, kids = %d\n", static_cast<int>(p.family.married), p.family.kids);
    std::printf("\tKids food / month = %lld\n", p.family.kids_food_month);
    std::printf("\tKids education / month = %lld\n", p.family.kids_education_month);
    std::printf("\tLeisure / month = %lld\n", p.leisure_month);
    std::printf("\tClothes / month = %lld\n", p.clothes_month);
    std::printf("\tLast unexpected = %lld\n", p.last_unexpected);
    std::printf("\tInvestments = %lld\n", p.investments);
    std::printf("\n");
}

void print_summary(const Person& p)
{
    std::printf("-- %s summary --\n", p.name);
    std::printf("Cap: %lld RUB, Age: %d\n", p.cap, p.age);
    std::printf("Salary: %lld RUB, Loan: %lld RUB\n", p.work_taxi.salary, p.bank.loan);
    std::printf("\n");
}

void print_monthly_costs(const Person& p)
{
    std::printf("Monthly costs for %s:\n", p.name);
    std::printf("\tFood: %lld\n", p.food_month);
    std::printf("\tHousing: %lld\n", p.house.owned ? 0 : p.house.rent_month);
    std::printf("\tFuel: %lld\n", p.car.fuel_month);
    std::printf("\tHealth: %lld\n", p.health.health_month);
    std::printf("\tLeisure: %lld\n", p.leisure_month);
    std::printf("\tClothes: %lld\n", p.clothes_month);

    if (p.family.kids > 0) {
        std::printf("\tKids food: %lld\n", p.family.kids_food_month);
        std::printf("\tKids education: %lld\n", p.family.kids_education_month);
    }

    if (p.pet.alive) {
        std::printf("\tPet food: %lld\n", p.pet.feed_month);
    }

    std::printf("\n");
}

void print_taxi_stats(const Person& p)
{
    std::printf("Taxi stats for %s:\n", p.name);
    std::printf("\tOrders/month: %lld RUB\n", p.work_taxi.orders_month);
    std::printf("\tService fee: %.1f%%\n", p.work_taxi.service_fee);
    std::printf("\tExpenses: %lld RUB\n", p.work_taxi.expenses);
    std::printf("\tSalary: %lld RUB\n", p.work_taxi.salary);
    std::printf("\n");
}

void print_finances(const Person& p)
{
    std::printf("FINANCES (%s)\n", p.name);
    std::printf("Checking: %lld\n", p.bank.ch);
    std::printf("Savings: %lld\n", p.bank.sv);
    std::printf("Loan: %lld\n", p.bank.loan);
    std::printf("Capital: %lld\n", p.cap);
    std::printf("Investments: %lld\n", p.investments);
    std::printf("\n");
}

void print_consumption(const Person& p)
{
    std::printf("CONSUMPTION (%s)\n", p.name);
    std::printf("Food: %lld\n", p.food_month);
    std::printf("Housing: %lld\n", p.house.owned ? 0 : p.house.rent_month);
    std::printf("Fuel: %lld\n", p.car.fuel_month);
    std::printf("Leisure: %lld\n", p.leisure_month);
    std::printf("Clothes: %lld\n", p.clothes_month);
    std::printf("Health: %lld\n", p.health.health_month);

    if (p.family.kids > 0) {
        std::printf("Kids food: %lld\n", p.family.kids_food_month);
        std::printf("Kids education: %lld\n", p.family.kids_education_month);
    }

    if (p.pet.alive) {
        std::printf("Pet food: %lld\n", p.pet.feed_month);
    }

    std::printf("\n");
}

void print_inflation(const Person& p)
{
    std::printf("INFLATION RATES (%s)\n", p.name);
    std::printf("\tFood: %.2f%%\n", p.infl.food);
    std::printf("\tCar: %.2f%%\n", p.infl.car_value);
    std::printf("\tFuel: %.2f%%\n", p.infl.fuel);
    std::printf("\tRent: %.2f%%\n", p.infl.rent);
    std::printf("\tClothes: %.2f%%\n", p.infl.clothes);
    std::printf("\tHealth: %.2f%%\n", p.infl.health);

    if (p.pet.alive) {
        std::printf("\tPet food: %.2f%%\n", p.infl.pet_food);
    }

    std::printf("\n");
}

void print_full_report(const Person& p)
{
    std::printf("=== FULL REPORT: %s ===\n\n", p.name);

    print_summary(p);
    print_taxi_stats(p);
    print_finances(p);
    print_consumption(p);
    print_inflation(p);

    RUB total_cost = 0;
    total_cost += p.food_month;
    total_cost += p.house.owned ? 0 : p.house.rent_month;
    total_cost += p.car.fuel_month;
    total_cost += p.leisure_month;
    total_cost += p.clothes_month;
    total_cost += p.health.health_month;
    total_cost += p.family.kids_food_month;
    total_cost += p.family.kids_education_month;
    total_cost += p.pet.alive ? p.pet.feed_month : 0;

    std::printf("Total monthly cost (RUB): %lld\n", total_cost);
    std::printf("Salary (RUB): %lld\n", p.work_taxi.salary);

    if (p.work_taxi.salary > 0) {
        RUB margin = p.work_taxi.salary - total_cost;
        std::printf("Remaining (RUB): %lld\n", margin);
    } else {
        std::printf("No salary this month\n");
    }

    std::printf("\n");
}

void print_results()
{
    std::printf("=== Simulation ended ===\n\n");

    print_full_report(Dilshot);
    print_full_report(Azurbek);
    print_full_report(Analbek);
}

void init_all()
{
    init_dilshot(Dilshot);
    init_azurbek(Azurbek);
    init_analbek(Analbek);
}

void print_month_info(int m, int y)
{
    std::printf("Month: %d, Year: %d\n", m, y);
}

void print_monthly_cap(const Person& p, int m, int y)
{
    std::printf("  %s at %d.%d: cap = %lld, salary = %lld\n",
                p.name,
                m,
                y,
                p.cap,
                p.work_taxi.salary);
}

void run_simulation_with_monthly_print()
{
    int m = 2;
    int y = 2026;

    while (!(m == 3 && y == 2027)) {
        print_month_info(m, y);

        update_dilshot(m, y);
        update_azurbek(m, y);
        update_analbek(m, y);

        step_month(Dilshot, m, y);
        step_month(Azurbek, m, y);
        step_month(Analbek, m, y);

        print_monthly_cap(Dilshot, m, y);
        print_monthly_cap(Azurbek, m, y);
        print_monthly_cap(Analbek, m, y);

        m++;
        if (m == 13) {
            m = 1;
            y++;
        }
    }
}

int main()
{
    init_all();

    run_simulation();
    // run_simulation_with_monthly_print();

    print_results();

    std::printf("=== Example extra calls ===\n\n");

    print_summary(Dilshot);
    print_monthly_costs(Dilshot);
    print_taxi_stats(Dilshot);

    print_summary(Azurbek);
    print_monthly_costs(Azurbek);
    print_taxi_stats(Azurbek);

    print_summary(Analbek);
    print_monthly_costs(Analbek);
    print_taxi_stats(Analbek);

    return 0;
}
