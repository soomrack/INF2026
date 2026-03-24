#include <cstdio>
#include <cstring>

using RUB = long long;
using Percent = float;

const int START_MONTH = 2;
const int START_YEAR  = 2026;

const int END_MONTH   = 3;
const int END_YEAR    = 2027;

// const int MONTHS_PER_YEAR = 12;

const Percent kSavingsAnnualRate = 14.5f;

const int HISTORY_CAPACITY = 24;

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

struct MonthlyStats {
    int month;
    int year;

    RUB checking;
    RUB savings;
    RUB loan;
    RUB capital;
    RUB salary;

    RUB total_basic_cost;
    RUB unexpected_cost;
};

struct AggregatedStats {
    RUB total_salary;
    RUB total_unexpected;
    RUB total_loan_paid;
    RUB total_food_paid;
    RUB total_housing_paid;
    RUB total_car_paid;
    RUB total_pet_paid;
    RUB total_health_paid;
    RUB total_leisure_paid;
    RUB total_clothes_paid;
    RUB total_kids_paid;

    RUB best_capital;
    RUB worst_capital;

    int best_month;
    int best_year;
    int worst_month;
    int worst_year;

    int months_simulated;
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

    MonthlyStats history[HISTORY_CAPACITY];
    int history_count;

    AggregatedStats stats;
};

Person Dilshot;
Person Analbek;

RUB mon_percent(RUB base, Percent annual) {
    double month_rate = static_cast<double>(annual) / 12.0 / 100.0;
    return static_cast<RUB>(static_cast<double>(base) * month_rate);
}

int is_same_date(int m1, int y1, int m2, int y2) {
    return (m1 == m2 && y1 == y2);
}

int is_finish_date(int month, int year) {
    return is_same_date(month, year, END_MONTH, END_YEAR);
}

void next_month(int& month, int& year) {
    month++;
    if (month == 13) {
        month = 1;
        year++;
    }
}

RUB max_rub(RUB a, RUB b) {
    return (a > b) ? a : b;
}

RUB min_rub(RUB a, RUB b) {
    return (a < b) ? a : b;
}

int clamp_hp(int hp) {
    if (hp < 0) return 0;
    if (hp > 100) return 100;
    return hp;
}

void reset_monthly_stats(MonthlyStats& s) {
    s.month = 0;
    s.year = 0;

    s.checking = 0;
    s.savings = 0;
    s.loan = 0;
    s.capital = 0;
    s.salary = 0;

    s.total_basic_cost = 0;
    s.unexpected_cost = 0;
}

void reset_aggregated_stats(AggregatedStats& s) {
    s.total_salary = 0;
    s.total_unexpected = 0;
    s.total_loan_paid = 0;
    s.total_food_paid = 0;
    s.total_housing_paid = 0;
    s.total_car_paid = 0;
    s.total_pet_paid = 0;
    s.total_health_paid = 0;
    s.total_leisure_paid = 0;
    s.total_clothes_paid = 0;
    s.total_kids_paid = 0;

    s.best_capital = 0;
    s.worst_capital = 0;

    s.best_month = 0;
    s.best_year = 0;
    s.worst_month = 0;
    s.worst_year = 0;

    s.months_simulated = 0;
}

void reset_person(Person& p) {
    p.name = "";
    p.age = 0;
    p.cap = 0;

    p.food_month = 0;
    p.leisure_month = 0;
    p.clothes_month = 0;

    p.work_taxi.orders_month = 0;
    p.work_taxi.service_fee = 0.0f;
    p.work_taxi.expenses = 0;
    p.work_taxi.salary = 0;

    p.bank.ch = 0;
    p.bank.sv = 0;
    p.bank.loan = 0;
    p.bank.loan_pay_month = 0;
    p.bank.loan_rate = 0.0f;

    p.house.owned = false;
    p.house.rent_month = 0;
    p.house.house_value = 0;

    p.car.market_value = 0;
    p.car.fuel_month = 0;

    p.family.married = false;
    p.family.kids = 0;
    p.family.kids_food_month = 0;
    p.family.kids_education_month = 0;

    p.pet.alive = false;
    p.pet.feed_month = 0;

    p.health.hp = 100;
    p.health.health_month = 0;

    p.infl.food = 0.0f;
    p.infl.car_value = 0.0f;
    p.infl.fuel = 0.0f;
    p.infl.pet_food = 0.0f;
    p.infl.rent = 0.0f;
    p.infl.clothes = 0.0f;
    p.infl.health = 0.0f;

    p.investments = 0;
    p.last_unexpected = 0;

    p.history_count = 0;

    for (int i = 0; i < HISTORY_CAPACITY; i++) {
        reset_monthly_stats(p.history[i]);
    }

    reset_aggregated_stats(p.stats);
}


// капитал считаем как ликвидные деньги + активы - остаток долга
void recalc_cap(Person& p) {
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

// зарплата таксиста хранится уже после комиссии сервиса и операционных расходов
void calc_salary_taxi(Person& p) {
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

// эта сумма используется как нижняя граница обязательных регулярных расходов без кредита
RUB calc_kids_month_cost(const Person& p) {
    return p.family.kids_food_month + p.family.kids_education_month;
}

// базовая нагрузка без кредита нужна для оценки обязательного минимума месяца
RUB calc_basic_month_cost_without_loan(const Person& p) {
    RUB total = 0;

    total += p.food_month;
    total += p.car.fuel_month;
    total += p.health.health_month;
    total += p.leisure_month;
    total += p.clothes_month;

    if (!p.house.owned) {
        total += p.house.rent_month;
    }

    if (p.pet.alive) {
        total += p.pet.feed_month;
    }

    total += calc_kids_month_cost(p);

    return total;
}

// резерв не равен всем деньгам на счёте, он задаёт нижнюю границу перед переводом в savings
RUB calc_reserve_target(const Person& p) {
    RUB reserve = 0;
    reserve += calc_basic_month_cost_without_loan(p);
    return reserve;
}

void push_history(Person& p, int month, int year, RUB basic_cost) {
    if (p.history_count >= HISTORY_CAPACITY) {
        return;
    }

    MonthlyStats& s = p.history[p.history_count];

    s.month = month;
    s.year = year;
    s.checking = p.bank.ch;
    s.savings = p.bank.sv;
    s.loan = p.bank.loan;
    s.capital = p.cap;
    s.salary = p.work_taxi.salary;
    s.total_basic_cost = basic_cost;
    s.unexpected_cost = p.last_unexpected;

    p.history_count++;
}

// первый зафиксированный месяц инициализирует обе границы сразу
void update_capital_extremes(Person& p, int month, int year) {
    if (p.stats.months_simulated == 0) {
        p.stats.best_capital = p.cap;
        p.stats.worst_capital = p.cap;

        p.stats.best_month = month;
        p.stats.best_year = year;
        p.stats.worst_month = month;
        p.stats.worst_year = year;

        return;
    }

    if (p.cap > p.stats.best_capital) {
        p.stats.best_capital = p.cap;
        p.stats.best_month = month;
        p.stats.best_year = year;
    }

    if (p.cap < p.stats.worst_capital) {
        p.stats.worst_capital = p.cap;
        p.stats.worst_month = month;
        p.stats.worst_year = year;
    }
}

void set_bank(
    Person& p,
    RUB ch,
    RUB sv,
    RUB loan,
    RUB loan_pay_month,
    Percent loan_rate
) {
    p.bank.ch = ch;
    p.bank.sv = sv;
    p.bank.loan = loan;
    p.bank.loan_pay_month = loan_pay_month;
    p.bank.loan_rate = loan_rate;
}

void set_housing(
    Person& p,
    bool owned,
    RUB rent_month,
    RUB house_value
) {
    p.house.owned = owned;
    p.house.rent_month = rent_month;
    p.house.house_value = house_value;
}

void set_car(
    Person& p,
    RUB market_value,
    RUB fuel_month
) {
    p.car.market_value = market_value;
    p.car.fuel_month = fuel_month;
}

void set_family(
    Person& p,
    bool married,
    int kids,
    RUB kids_food_month,
    RUB kids_education_month
) {
    p.family.married = married;
    p.family.kids = kids;
    p.family.kids_food_month = kids_food_month;
    p.family.kids_education_month = kids_education_month;
}

void set_pet(
    Person& p,
    bool alive,
    RUB feed_month
) {
    p.pet.alive = alive;
    p.pet.feed_month = feed_month;
}

void set_health(
    Person& p,
    int hp,
    RUB health_month
) {
    p.health.hp = hp;
    p.health.health_month = health_month;
}

void set_inflation(
    Person& p,
    Percent food,
    Percent car_value,
    Percent fuel,
    Percent pet_food,
    Percent rent,
    Percent clothes,
    Percent health
) {
    p.infl.food = food;
    p.infl.car_value = car_value;
    p.infl.fuel = fuel;
    p.infl.pet_food = pet_food;
    p.infl.rent = rent;
    p.infl.clothes = clothes;
    p.infl.health = health;
}

void set_lifestyle(
    Person& p,
    RUB food_month,
    RUB leisure_month,
    RUB clothes_month,
    RUB investments
) {
    p.food_month = food_month;
    p.leisure_month = leisure_month;
    p.clothes_month = clothes_month;
    p.investments = investments;
}

void init_dilshot(Person& p) {
    reset_person(p);

    p.name = "Dilshot";
    p.age = 32;

    p.work_taxi.orders_month = 220'000;
    p.work_taxi.service_fee = 22.0f;
    p.work_taxi.expenses = 45'000;
    calc_salary_taxi(p);

    set_bank(
        p,
        10'000,
        50'000,
        500'000,
        20'000,
        18.0f
    );

    set_housing(
        p,
        true,
        0,
        3'000'000
    );

    set_car(
        p,
        1'200'000,
        12'000
    );

    set_family(
        p,
        true,
        1,
        6'000,
        4'000
    );

    set_pet(
        p,
        false,
        0
    );

    set_health(
        p,
        80,
        4'000
    );

    set_inflation(
        p,
        9.0f,
        5.0f,
        11.0f,
        0.0f,
        8.0f,
        5.5f,
        7.0f
    );

    set_lifestyle(
        p,
        18'000,
        8'000,
        4'000,
        100'000
    );

    p.last_unexpected = 0;

    recalc_cap(p);
}

void init_analbek(Person& p) {
    reset_person(p);

    p.name = "Analbek";
    p.age = 35;

    p.work_taxi.orders_month = 160'000;
    p.work_taxi.service_fee = 28.0f;
    p.work_taxi.expenses = 55'000;
    calc_salary_taxi(p);

    set_bank(
        p,
        2'000,
        0,
        200'000,
        15'000,
        20.0f
    );

    set_housing(
        p,
        false,
        20'000,
        0
    );

    set_car(
        p,
        0,
        0
    );

    set_family(
        p,
        true,
        2,
        10'000,
        6'000
    );

    set_pet(
        p,
        false,
        0
    );

    set_health(
        p,
        60,
        7'000
    );

    set_inflation(
        p,
        11.0f,
        0.0f,
        0.0f,
        0.0f,
        10.0f,
        7.0f,
        9.0f
    );

    set_lifestyle(
        p,
        14'000,
        3'000,
        2'000,
        0
    );

    p.last_unexpected = 0;

    recalc_cap(p);
}

void init_all() {
    init_dilshot(Dilshot);
    init_analbek(Analbek);
}

int is_dilshot(const Person& p) {
    return std::strcmp(p.name, "Dilshot") == 0;
}

int is_analbek(const Person& p) {
    return std::strcmp(p.name, "Analbek") == 0;
}

RUB calc_total_assets(const Person& p) {
    RUB total = 0;

    total += p.bank.ch;
    total += p.bank.sv;
    total += p.car.market_value;
    total += p.investments;

    if (p.house.owned) {
        total += p.house.house_value;
    }

    return total;
}

RUB calc_total_liabilities(const Person& p) {
    RUB total = 0;
    total += p.bank.loan;
    return total;
}

RUB calc_net_income_before_personal_costs(const Person& p) {
    return p.work_taxi.salary;
}

RUB calc_total_family_cost(const Person& p) {
    return p.family.kids_food_month + p.family.kids_education_month;
}

RUB calc_total_recurring_cost(const Person& p) {
    RUB total = 0;

    total += p.food_month;
    total += p.leisure_month;
    total += p.clothes_month;
    total += p.health.health_month;
    total += p.car.fuel_month;
    total += calc_total_family_cost(p);

    if (!p.house.owned) {
        total += p.house.rent_month;
    }

    if (p.pet.alive) {
        total += p.pet.feed_month;
    }

    return total;
}

RUB calc_cash_total(const Person& p) {
    return p.bank.ch + p.bank.sv;
}

RUB calc_non_cash_assets(const Person& p) {
    RUB total = 0;
    total += p.car.market_value;
    total += p.investments;

    if (p.house.owned) {
        total += p.house.house_value;
    }

    return total;
}

// сигнализирует, что регулярная нагрузка и кредит уже съедают месячный доход
int has_credit_pressure(const Person& p) {
    if (p.bank.loan <= 0) {
        return 0;
    }

    RUB recurring = calc_total_recurring_cost(p);
    RUB after_costs = p.work_taxi.salary - recurring - p.bank.loan_pay_month;

    return (after_costs < 0);
}

// здесь сравниваем checking с резервом, а не со всеми расходами за весь горизонт
int has_liquidity_risk(const Person& p) {
    RUB reserve = calc_reserve_target(p);
    return p.bank.ch < reserve;
}

int has_health_risk(const Person& p) {
    return p.health.hp < 50;
}

void capture_initial_snapshot(Person& p) {
    recalc_cap(p);
    update_capital_extremes(p, START_MONTH, START_YEAR);
    push_history(p, START_MONTH, START_YEAR, calc_basic_month_cost_without_loan(p));
}

void capture_all_initial_snapshots() {
    capture_initial_snapshot(Dilshot);
    capture_initial_snapshot(Analbek);
}

void seed_initial_aggregates(Person& p) {
    p.stats.total_salary = 0;
    p.stats.total_unexpected = 0;
    p.stats.total_loan_paid = 0;
    p.stats.total_food_paid = 0;
    p.stats.total_housing_paid = 0;
    p.stats.total_car_paid = 0;
    p.stats.total_pet_paid = 0;
    p.stats.total_health_paid = 0;
    p.stats.total_leisure_paid = 0;
    p.stats.total_clothes_paid = 0;
    p.stats.total_kids_paid = 0;
    p.stats.months_simulated = 0;
}

void seed_all_aggregates() {
    seed_initial_aggregates(Dilshot);
    seed_initial_aggregates(Analbek);
}

void validate_person_basics(const Person& p) {
    if (p.name == 0) {
        std::printf("Warning: null name\n");
    }

    if (p.age < 0) {
        std::printf("Warning: negative age for %s\n", p.name);
    }

    if (p.health.hp < 0 || p.health.hp > 100) {
        std::printf("Warning: hp out of range for %s\n", p.name);
    }

    if (p.family.kids < 0) {
        std::printf("Warning: negative kids for %s\n", p.name);
    }

    if (p.bank.loan < 0) {
        std::printf("Warning: negative loan for %s\n", p.name);
    }
}

void validate_all() {
    validate_person_basics(Dilshot);
    validate_person_basics(Analbek);
}

int is_owner_household(const Person& p) {
    return p.house.owned ? 1 : 0;
}

int is_family_household(const Person& p) {
    return (p.family.married || p.family.kids > 0) ? 1 : 0;
}

int uses_car(const Person& p) {
    return p.car.market_value > 0 || p.car.fuel_month > 0;
}

int has_pet(const Person& p) {
    return p.pet.alive ? 1 : 0;
}

    void add_salary_to_checking(Person& p) {
        calc_salary_taxi(p);
        p.bank.ch += p.work_taxi.salary;
        p.stats.total_salary += p.work_taxi.salary;
    }

    void add_bonus_if_needed(Person& p, int month, int year) {
        RUB bonus = 0;

        if (is_dilshot(p)) {
            if (month == 12 && year == 2026) {
                bonus = 30'000;
            }
        }

        if (is_analbek(p)) {
            if (month == 1 && year == 2027) {
                bonus = 10'000;
            }
        }

        if (bonus > 0) {
            p.bank.ch += bonus;
            p.stats.total_salary += bonus;
        }
    }

    void process_income_stage(Person& p, int month, int year) {
        add_salary_to_checking(p);
        add_bonus_if_needed(p, month, year);
    }

    void pay_food(Person& p) {
        p.bank.ch -= p.food_month;
        p.stats.total_food_paid += p.food_month;
    }

    void pay_kids(Person& p) {
        RUB total = 0;

        total += p.family.kids_food_month;
        total += p.family.kids_education_month;

        p.bank.ch -= total;
        p.stats.total_kids_paid += total;
    }

    void pay_housing(Person& p) {
        if (!p.house.owned) {
            p.bank.ch -= p.house.rent_month;
            p.stats.total_housing_paid += p.house.rent_month;
        }
    }

    void pay_car(Person& p) {
        p.bank.ch -= p.car.fuel_month;
        p.stats.total_car_paid += p.car.fuel_month;
    }

    void pay_pet(Person& p) {
        if (p.pet.alive) {
            p.bank.ch -= p.pet.feed_month;
            p.stats.total_pet_paid += p.pet.feed_month;
        }
    }

    void pay_health(Person& p) {
        p.bank.ch -= p.health.health_month;
        p.stats.total_health_paid += p.health.health_month;
    }

void pay_leisure(Person& p) {
    p.bank.ch -= p.leisure_month;
    p.stats.total_leisure_paid += p.leisure_month;
}

void pay_clothes(Person& p) {
    p.bank.ch -= p.clothes_month;
    p.stats.total_clothes_paid += p.clothes_month;
}

RUB pay_all_basic_costs(Person& p) {
    RUB total = 0;

    pay_food(p);
    total += p.food_month;

    pay_kids(p);
    total += calc_kids_month_cost(p);

    pay_housing(p);
    if (!p.house.owned) {
        total += p.house.rent_month;
    }

    pay_car(p);
    total += p.car.fuel_month;

    pay_pet(p);
    if (p.pet.alive) {
        total += p.pet.feed_month;
    }

    pay_health(p);
    total += p.health.health_month;

    pay_leisure(p);
    total += p.leisure_month;

    pay_clothes(p);
    total += p.clothes_month;

    return total;
}

// здесь задаются не катастрофы, а мелкие и средние бытовые отклонения от плана
RUB calc_unexpected_cost(const Person& p, int month, int year) {
    RUB cost = 0;

    if (month == 5) {
        cost = 5000;
    }

    if (month == 11) {
        cost = 8000;
    }

    if (is_analbek(p) && month == 3 && year == 2026) {
        cost = 15000;
    }

    if (is_dilshot(p) && month == 8 && year == 2026) {
        cost = 12000;
    }

    return cost;
}

void pay_unexpected(Person& p, int month, int year) {
    RUB cost = calc_unexpected_cost(p, month, year);
    p.last_unexpected = cost;
    p.bank.ch -= cost;
    p.stats.total_unexpected += cost;
}

RUB calc_loan_payment_due(const Person& p) {
    if (p.bank.loan <= 0) {
        return 0;
    }

    RUB payment = p.bank.loan_pay_month;

    if (payment > p.bank.loan) {
        payment = p.bank.loan;
    }

    return payment;
}

// проценты начисляются на остаток после обязательного платежа за месяц
void apply_loan_interest(Person& p) {
    if (p.bank.loan > 0) {
        p.bank.loan += mon_percent(p.bank.loan, p.bank.loan_rate);
    }
}

void pay_loan(Person& p) {
    if (p.bank.loan <= 0) {
        return;
    }

    RUB payment = calc_loan_payment_due(p);

    p.bank.loan -= payment;
    p.bank.ch   -= payment;

    p.stats.total_loan_paid += payment;

    if (p.bank.loan > 0) {
        apply_loan_interest(p);
    }
}

int is_loan_heavy(const Person& p) {
    if (p.work_taxi.salary <= 0) {
        return 0;
    }

    RUB due = calc_loan_payment_due(p);
    return due > (p.work_taxi.salary / 3);
}


RUB calc_transfer_to_savings(const Person& p) {
    RUB reserve = calc_reserve_target(p);
    RUB extra = p.bank.ch - reserve;

    if (extra > 0) {
        return extra;
    }

    return 0;
}

// переводим только излишек относительно резерва, а не весь остаток счёта
void move_to_savings(Person& p) {
    RUB transfer = calc_transfer_to_savings(p);

    if (transfer > 0) {
        p.bank.ch -= transfer;
        p.bank.sv += transfer;
    }
}

void add_savings_income(Person& p) {
    if (p.bank.sv <= 0) {
        return;
    }

    p.bank.sv += mon_percent(p.bank.sv, kSavingsAnnualRate);
}

void fix_negative_checking(Person& p) {
    if (p.bank.ch >= 0) {
        return;
    }

    RUB need = -p.bank.ch;
    RUB take = (need <= p.bank.sv) ? need : p.bank.sv;

    p.bank.sv -= take;
    p.bank.ch += take;
}

void emergency_cover_from_savings(Person& p) {
    if (p.bank.ch >= 0) {
        return;
    }

    fix_negative_checking(p);
}

void process_savings_stage(Person& p) {
    move_to_savings(p);
    add_savings_income(p);
    emergency_cover_from_savings(p);
}


void inflate_food(Person& p) {
    p.food_month += mon_percent(p.food_month, p.infl.food);
}

void inflate_car(Person& p) {
    p.car.market_value += mon_percent(p.car.market_value, p.infl.car_value);
    p.car.fuel_month   += mon_percent(p.car.fuel_month,   p.infl.fuel);
}

void inflate_housing(Person& p) {
    p.house.rent_month += mon_percent(p.house.rent_month, p.infl.rent);
}

void inflate_health(Person& p) {
    p.health.health_month += mon_percent(p.health.health_month, p.infl.health);
}

void inflate_clothes(Person& p) {
    p.clothes_month += mon_percent(p.clothes_month, p.infl.clothes);
}

void inflate_kids(Person& p) {
    p.family.kids_food_month += mon_percent(p.family.kids_food_month, p.infl.food);
    p.family.kids_education_month += mon_percent(p.family.kids_education_month, p.infl.food);
}

void inflate_pet(Person& p) {
    if (p.pet.alive) {
        p.pet.feed_month += mon_percent(p.pet.feed_month, p.infl.pet_food);
    }
}

// порядок инфляции важен только тем, что он применяется до расходов месяца
void add_inflation(Person& p) {
    inflate_food(p);
    inflate_car(p);
    inflate_housing(p);
    inflate_health(p);
    inflate_clothes(p);
    inflate_kids(p);
    inflate_pet(p);
}


RUB process_expense_stage(Person& p, int month, int year) {
    RUB basic_cost = pay_all_basic_costs(p);
    pay_unexpected(p, month, year);
    return basic_cost;
}

void process_credit_stage(Person& p) {
    pay_loan(p);
    fix_negative_checking(p);
}

void process_money_flow(Person& p, int month, int year) {
    process_income_stage(p, month, year);
    move_to_savings(p);
    process_expense_stage(p, month, year);
    process_credit_stage(p);
    add_savings_income(p);
    fix_negative_checking(p);
}


RUB calc_free_cash_after_basic_costs(const Person& p) {
    return p.work_taxi.salary - calc_basic_month_cost_without_loan(p);
}

RUB calc_free_cash_after_all_costs(const Person& p) {
    return p.work_taxi.salary
            - calc_basic_month_cost_without_loan(p)
            - calc_loan_payment_due(p);
}

int is_month_negative_after_costs(const Person& p) {
    return calc_free_cash_after_all_costs(p) < 0;
}

int savings_cover_months(const Person& p) {
    RUB monthly = calc_basic_month_cost_without_loan(p);

    if (monthly <= 0) {
        return 0;
    }

    return static_cast<int>(p.bank.sv / monthly);
}


void update_month_counter(Person& p) {
    p.stats.months_simulated++;
}

void normalize_negative_values(Person& p) {
    if (p.bank.loan < 0) {
        p.bank.loan = 0;
    }

    if (p.bank.sv < 0) {
        p.bank.sv = 0;
    }
}


void update_health_seasonal(Person& p, int month) {
    if (month == 2 || month == 3) {
        p.health.hp -= 1;
    }

    if (month == 6) {
        p.health.hp += 1;
    }

    if (month == 10) {
        p.health.hp -= 2;
    }

    p.health.hp = clamp_hp(p.health.hp);
}

// здесь здоровье реагирует не на диагнозы, а на финансовый стресс модели
void update_health_by_stress(Person& p) {
    if (is_month_negative_after_costs(p)) {
        p.health.hp -= 1;
    }

    if (has_credit_pressure(p)) {
        p.health.hp -= 1;
    }

    p.health.hp = clamp_hp(p.health.hp);
}

// низкая ликвидность отдельно ухудшает состояние, даже если капитал формально положительный
void update_health_by_liquidity(Person& p) {
    if (has_liquidity_risk(p)) {
        p.health.hp -= 1;
    }

    p.health.hp = clamp_hp(p.health.hp);
}

void update_health(Person& p, int month) {
    update_health_seasonal(p, month);
    update_health_by_stress(p);
    update_health_by_liquidity(p);
    p.health.hp = clamp_hp(p.health.hp);
}


void update_age(Person& p, int month) {
    if (month == 1) {
        p.age += 1;
    }
}


void update_leisure_dilshot(int month, int year) {
    (void)year;

    if (month == 6) {
        Dilshot.leisure_month = 20000;
    } else if (month == 1) {
        Dilshot.leisure_month = 12000;
    } else {
        Dilshot.leisure_month = 8000;
    }
}

void update_leisure_analbek(int month, int year) {
    (void)year;

    if (month == 12) {
        Analbek.leisure_month = 5000;
    } else if (month == 1) {
        Analbek.leisure_month = 4000;
    } else {
        Analbek.leisure_month = 3000;
    }
}


void update_income_dilshot(int month, int year) {
    (void)month;

    if (year == 2026) {
        Dilshot.work_taxi.orders_month = 220000;
        Dilshot.work_taxi.service_fee  = 22.0f;
        Dilshot.work_taxi.expenses     = 45000;
    }

    if (month == 10 && year == 2026) {
        Dilshot.work_taxi.orders_month = 235000;
    }

    if (month == 1 && year == 2027) {
        Dilshot.work_taxi.orders_month = 240000;
        Dilshot.work_taxi.service_fee  = 21.5f;
        Dilshot.work_taxi.expenses     = 47000;
    }
}

void update_income_analbek(int month, int year) {
    if (month == 1 && year == 2027) {
        Analbek.work_taxi.orders_month = 180000;
        Analbek.work_taxi.service_fee  = 26.0f;
        Analbek.work_taxi.expenses     = 50000;
        return;
    }

    if (month == 7 && year == 2026) {
        Analbek.work_taxi.orders_month = 170000;
        Analbek.work_taxi.service_fee  = 27.0f;
        Analbek.work_taxi.expenses     = 52000;
        return;
    }

    Analbek.work_taxi.orders_month = 160000;
    Analbek.work_taxi.service_fee  = 28.0f;
    Analbek.work_taxi.expenses     = 55000;
}

// тут семейные расходы меняются ступенчато, чтобы в отчётах были заметны события года
void update_family_costs_dilshot(int month, int year) {
    (void)year;

    if (month == 9) {
        Dilshot.family.kids_education_month += 10000;
    }
}

void update_family_costs_analbek(int month, int year) {
    (void)year;

    if (month == 9) {
        Analbek.family.kids_education_month += 6000;
    }

    if (month == 12) {
        Analbek.family.kids_food_month += 2000;
    }
}

// ============================================================
//  ИЗМЕНЕНИЕ МЕДИЦИНСКИХ РАСХОДОВ
// ============================================================

void update_health_cost_dilshot(int month) {
    if (Dilshot.health.hp < 60) {
        Dilshot.health.health_month += 1000;
    }

    if (month == 10) {
        Dilshot.health.health_month += 500;
    }
}

void update_health_cost_analbek(int month) {
    if (Analbek.health.hp < 50) {
        Analbek.health.health_month += 1500;
    }

    if (month == 3 || month == 11) {
        Analbek.health.health_month += 1000;
    }
}

// специальные события меняют состояние напрямую до основного денежного шага
void apply_special_event_dilshot(int month, int year) {
    if (month == 4 && year == 2026) {
        Dilshot.bank.ch += 15000;
    }

    if (month == 8 && year == 2026) {
        Dilshot.bank.ch -= 5000;
    }
}

void apply_special_event_analbek(int month, int year) {
    if (month == 3 && year == 2026) {
        Analbek.bank.ch -= 5000;
    }

    if (month == 6 && year == 2026) {
        Analbek.bank.ch += 7000;
    }
}


void update_dilshot(int month, int year) {
    update_leisure_dilshot(month, year);
    update_income_dilshot(month, year);
    update_family_costs_dilshot(month, year);
    update_health_cost_dilshot(month);
    apply_special_event_dilshot(month, year);
}

void update_analbek(int month, int year) {
    update_leisure_analbek(month, year);
    update_income_analbek(month, year);
    update_family_costs_analbek(month, year);
    update_health_cost_analbek(month);
    apply_special_event_analbek(month, year);
}


int is_school_season(int month) {
    return (month == 9);
}

int is_new_year_period(int month) {
    return (month == 12 || month == 1);
}

int is_autumn(int month) {
    return (month == 9 || month == 10 || month == 11);
}

int is_summer(int month) {
    return (month == 6 || month == 7 || month == 8);
}

void apply_school_pressure(Person& p, int month) {
    if (is_school_season(month) && p.family.kids > 0) {
        p.family.kids_education_month += 2000;
    }
}

void apply_new_year_pressure(Person& p, int month) {
    if (is_new_year_period(month)) {
        p.leisure_month += 1000;
        p.clothes_month += 500;
    }
}

void apply_autumn_health_pressure(Person& p, int month) {
    if (is_autumn(month)) {
        p.health.health_month += 300;
    }
}

// летний эффект уменьшает только медицинскую статью, не восстанавливая прошлые значения автоматически
void apply_summer_relief(Person& p, int month) {
    if (is_summer(month) && p.health.hp > 70) {
        if (p.health.health_month >= 500) {
            p.health.health_month -= 500;
        }
    }
}

void apply_generic_month_events(Person& p, int month) {
    apply_school_pressure(p, month);
    apply_new_year_pressure(p, month);
    apply_autumn_health_pressure(p, month);
    apply_summer_relief(p, month);
}

// здесь режем только явно некорректные значения, чтобы модель не ломалась на длинной серии месяцев
void normalize_person_state(Person& p) {
    if (p.food_month < 0) p.food_month = 0;
    if (p.leisure_month < 0) p.leisure_month = 0;
    if (p.clothes_month < 0) p.clothes_month = 0;

    if (p.car.market_value < 0) p.car.market_value = 0;
    if (p.car.fuel_month < 0) p.car.fuel_month = 0;

    if (p.bank.ch < -1000000000LL) p.bank.ch = -1000000000LL;
    if (p.bank.sv < 0) p.bank.sv = 0;
    if (p.bank.loan < 0) p.bank.loan = 0;

    if (p.family.kids_food_month < 0) p.family.kids_food_month = 0;
    if (p.family.kids_education_month < 0) p.family.kids_education_month = 0;

    if (p.house.rent_month < 0) p.house.rent_month = 0;
    if (p.house.house_value < 0) p.house.house_value = 0;

    if (p.health.health_month < 0) p.health.health_month = 0;
    if (p.pet.feed_month < 0) p.pet.feed_month = 0;

    p.health.hp = clamp_hp(p.health.hp);
}


void update_pre_month_state(Person& p, int month, int year) {
    if (is_dilshot(p)) {
        update_dilshot(month, year);
    }

    if (is_analbek(p)) {
        update_analbek(month, year);
    }

    apply_generic_month_events(p, month);
    normalize_person_state(p);
}


void update_post_month_state(Person& p, int month) {
    update_health(p, month);
    update_age(p, month);
    normalize_person_state(p);
}


RUB calc_actual_month_load(const Person& p) {
    RUB total = 0;

    total += p.food_month;
    total += p.leisure_month;
    total += p.clothes_month;
    total += p.health.health_month;
    total += p.car.fuel_month;
    total += p.family.kids_food_month;
    total += p.family.kids_education_month;

    if (!p.house.owned) {
        total += p.house.rent_month;
    }

    if (p.pet.alive) {
        total += p.pet.feed_month;
    }

    total += calc_loan_payment_due(p);

    return total;
}

RUB calc_total_month_outflow_estimate(const Person& p) {
    return calc_actual_month_load(p) + p.last_unexpected;
}

RUB calc_month_margin_estimate(const Person& p) {
    return p.work_taxi.salary - calc_total_month_outflow_estimate(p);
}


int history_has_space(const Person& p) {
    return p.history_count < HISTORY_CAPACITY;
}

MonthlyStats* get_next_history_slot(Person& p) {
    if (!history_has_space(p)) {
        return 0;
    }
    return &p.history[p.history_count];
}

void fill_history_slot(
    MonthlyStats& s,
    const Person& p,
    int month,
    int year,
    RUB basic_cost
) {
    s.month = month;
    s.year = year;

    s.checking = p.bank.ch;
    s.savings = p.bank.sv;
    s.loan = p.bank.loan;
    s.capital = p.cap;
    s.salary = p.work_taxi.salary;

    s.total_basic_cost = basic_cost;
    s.unexpected_cost = p.last_unexpected;
}

void push_history_row(Person& p, int month, int year, RUB basic_cost) {
    MonthlyStats* slot = get_next_history_slot(p);

    if (slot == 0) {
        return;
    }

    fill_history_slot(*slot, p, month, year, basic_cost);
    p.history_count++;
}

// ============================================================
//  ОБНОВЛЕНИЕ ЭКСТРЕМУМОВ КАПИТАЛА
// ============================================================

void update_best_capital(Person& p, int month, int year) {
    if (p.stats.months_simulated == 0 || p.cap > p.stats.best_capital) {
        p.stats.best_capital = p.cap;
        p.stats.best_month = month;
        p.stats.best_year = year;
    }
}

void update_worst_capital(Person& p, int month, int year) {
    if (p.stats.months_simulated == 0 || p.cap < p.stats.worst_capital) {
        p.stats.worst_capital = p.cap;
        p.stats.worst_month = month;
        p.stats.worst_year = year;
    }
}

// void update_capital_extremes(Person& p, int month, int year) {
//     update_best_capital(p, month, year);
//     update_worst_capital(p, month, year);
// }

void finalize_month_counters(Person& p) {
    p.stats.months_simulated++;
}

// basic_cost передаём отдельно, чтобы в историю попала фактическая базовая нагрузка месяца
void finalize_person_after_month(
    Person& p,
    int month,
    int year,
    RUB basic_cost
) {
    recalc_cap(p);
    update_capital_extremes(p, month, year);
    push_history_row(p, month, year, basic_cost);
    finalize_month_counters(p);
}


RUB history_first_capital(const Person& p) {
    if (p.history_count <= 0) {
        return 0;
    }
    return p.history[0].capital;
}

RUB history_last_capital(const Person& p) {
    if (p.history_count <= 0) {
        return 0;
    }
    return p.history[p.history_count - 1].capital;
}

RUB history_first_savings(const Person& p) {
    if (p.history_count <= 0) {
        return 0;
    }
    return p.history[0].savings;
}

RUB history_last_savings(const Person& p) {
    if (p.history_count <= 0) {
        return 0;
    }
    return p.history[p.history_count - 1].savings;
}

RUB history_capital_delta(const Person& p) {
    if (p.history_count <= 1) {
        return 0;
    }
    return history_last_capital(p) - history_first_capital(p);
}

RUB history_savings_delta(const Person& p) {
    if (p.history_count <= 1) {
        return 0;
    }
    return history_last_savings(p) - history_first_savings(p);
}


RUB history_sum_salary(const Person& p) {
    RUB total = 0;

    for (int i = 0; i < p.history_count; i++) {
        total += p.history[i].salary;
    }

    return total;
}

RUB history_sum_basic_cost(const Person& p) {
    RUB total = 0;

    for (int i = 0; i < p.history_count; i++) {
        total += p.history[i].total_basic_cost;
    }

    return total;
}

RUB history_sum_unexpected(const Person& p) {
    RUB total = 0;

    for (int i = 0; i < p.history_count; i++) {
        total += p.history[i].unexpected_cost;
    }

    return total;
}

double history_avg_salary(const Person& p) {
    if (p.history_count <= 0) {
        return 0.0;
    }

    return static_cast<double>(history_sum_salary(p))
            / static_cast<double>(p.history_count);
}

double history_avg_basic_cost(const Person& p) {
    if (p.history_count <= 0) {
        return 0.0;
    }

    return static_cast<double>(history_sum_basic_cost(p))
            / static_cast<double>(p.history_count);
}

double history_avg_unexpected(const Person& p) {
    if (p.history_count <= 0) {
        return 0.0;
    }

    return static_cast<double>(history_sum_unexpected(p))
            / static_cast<double>(p.history_count);
}


int history_best_index(const Person& p) {
    if (p.history_count <= 0) {
        return -1;
    }

    int best = 0;

    for (int i = 1; i < p.history_count; i++) {
        if (p.history[i].capital > p.history[best].capital) {
            best = i;
        }
    }

    return best;
}

int history_worst_index(const Person& p) {
    if (p.history_count <= 0) {
        return -1;
    }

    int worst = 0;

    for (int i = 1; i < p.history_count; i++) {
        if (p.history[i].capital < p.history[worst].capital) {
            worst = i;
        }
    }

    return worst;
}

MonthlyStats* history_best_month(Person& p) {
    int idx = history_best_index(p);
    if (idx < 0) {
        return 0;
    }
    return &p.history[idx];
}

MonthlyStats* history_worst_month(Person& p) {
    int idx = history_worst_index(p);
    if (idx < 0) {
        return 0;
    }
    return &p.history[idx];
}

// маржа считается грубо по истории, потому что кредит в таблице хранится отдельно как баланс
int history_negative_margin_months(const Person& p) {
    int count = 0;

    for (int i = 0; i < p.history_count; i++) {
        RUB margin = p.history[i].salary
                    - p.history[i].total_basic_cost
                    - p.history[i].unexpected_cost;

        if (margin < 0) {
            count++;
        }
    }

    return count;
}

int history_low_savings_months(const Person& p) {
    int count = 0;

    for (int i = 0; i < p.history_count; i++) {
        if (p.history[i].savings < p.history[i].total_basic_cost) {
            count++;
        }
    }

    return count;
}

int history_high_loan_months(const Person& p) {
    int count = 0;

    for (int i = 0; i < p.history_count; i++) {
        if (p.history[i].loan > 0 && p.history[i].loan >= 300000) {
            count++;
        }
    }

    return count;
}


int compare_capital_last(const Person& a, const Person& b) {
    RUB ac = history_last_capital(a);
    RUB bc = history_last_capital(b);

    if (ac > bc) return 1;
    if (ac < bc) return -1;
    return 0;
}

int compare_savings_last(const Person& a, const Person& b) {
    RUB as = history_last_savings(a);
    RUB bs = history_last_savings(b);

    if (as > bs) return 1;
    if (as < bs) return -1;
    return 0;
}

int compare_unexpected_total(const Person& a, const Person& b) {
    RUB au = history_sum_unexpected(a);
    RUB bu = history_sum_unexpected(b);

    if (au < bu) return 1;
    if (au > bu) return -1;
    return 0;
}


int is_stable_month_snapshot(const MonthlyStats& s) {
    if (s.checking < 0) return 0;
    if (s.capital < 0) return 0;
    return 1;
}

int stable_month_count(const Person& p) {
    int count = 0;

    for (int i = 0; i < p.history_count; i++) {
        if (is_stable_month_snapshot(p.history[i])) {
            count++;
        }
    }

    return count;
}


double debt_to_assets_ratio(const Person& p) {
    RUB assets = calc_total_assets(p);

    if (assets <= 0) {
        return 0.0;
    }

    return static_cast<double>(p.bank.loan)
            / static_cast<double>(assets);
}

double savings_to_assets_ratio(const Person& p) {
    RUB assets = calc_total_assets(p);

    if (assets <= 0) {
        return 0.0;
    }

    return static_cast<double>(p.bank.sv)
            / static_cast<double>(assets);
}

double checking_to_assets_ratio(const Person& p) {
    RUB assets = calc_total_assets(p);

    if (assets <= 0) {
        return 0.0;
    }

    return static_cast<double>(p.bank.ch)
            / static_cast<double>(assets);
}

double investments_to_assets_ratio(const Person& p) {
    RUB assets = calc_total_assets(p);

    if (assets <= 0) {
        return 0.0;
    }

    return static_cast<double>(p.investments)
            / static_cast<double>(assets);
}

double housing_to_assets_ratio(const Person& p) {
    RUB assets = calc_total_assets(p);

    if (assets <= 0) {
        return 0.0;
    }

    if (!p.house.owned) {
        return 0.0;
    }

    return static_cast<double>(p.house.house_value)
            / static_cast<double>(assets);
}

double car_to_assets_ratio(const Person& p) {
    RUB assets = calc_total_assets(p);

    if (assets <= 0) {
        return 0.0;
    }

    return static_cast<double>(p.car.market_value)
            / static_cast<double>(assets);
}


// эти коэффициенты нужны для отчёта, а не для принятия решений внутри модели
double recurring_cost_to_salary_ratio(const Person& p) {
    if (p.work_taxi.salary <= 0) {
        return 0.0;
    }

    return static_cast<double>(calc_total_recurring_cost(p))
            / static_cast<double>(p.work_taxi.salary);
}

double loan_to_salary_ratio(const Person& p) {
    if (p.work_taxi.salary <= 0) {
        return 0.0;
    }

    return static_cast<double>(calc_loan_payment_due(p))
            / static_cast<double>(p.work_taxi.salary);
}

double unexpected_to_salary_ratio_history(const Person& p) {
    RUB total_salary = history_sum_salary(p);
    RUB total_unexpected = history_sum_unexpected(p);

    if (total_salary <= 0) {
        return 0.0;
    }

    return static_cast<double>(total_unexpected)
            / static_cast<double>(total_salary);
}

double average_margin_ratio_history(const Person& p) {
    double avg_salary = history_avg_salary(p);
    double avg_basic = history_avg_basic_cost(p);
    double avg_unexp = history_avg_unexpected(p);

    if (avg_salary <= 0.0) {
        return 0.0;
    }

    double avg_margin = avg_salary - avg_basic - avg_unexp;
    return avg_margin / avg_salary;
}


RUB emergency_fund_target_3m(const Person& p) {
    return calc_basic_month_cost_without_loan(p) * 3;
}

RUB emergency_fund_target_6m(const Person& p) {
    return calc_basic_month_cost_without_loan(p) * 6;
}

int emergency_fund_level_3m_ok(const Person& p) {
    return p.bank.sv >= emergency_fund_target_3m(p);
}

int emergency_fund_level_6m_ok(const Person& p) {
    return p.bank.sv >= emergency_fund_target_6m(p);
}

double emergency_fund_coverage_ratio(const Person& p) {
    RUB target = emergency_fund_target_6m(p);

    if (target <= 0) {
        return 0.0;
    }

    return static_cast<double>(p.bank.sv)
            / static_cast<double>(target);
}


double capital_growth_ratio(const Person& p) {
    RUB first = history_first_capital(p);
    RUB last  = history_last_capital(p);

    if (first == 0) {
        return 0.0;
    }

    return static_cast<double>(last - first)
            / static_cast<double>(first);
}

double savings_growth_ratio(const Person& p) {
    RUB first = history_first_savings(p);
    RUB last  = history_last_savings(p);

    if (first == 0) {
        return 0.0;
    }

    return static_cast<double>(last - first)
            / static_cast<double>(first);
}

double average_capital_history(const Person& p) {
    if (p.history_count <= 0) {
        return 0.0;
    }

    RUB total = 0;

    for (int i = 0; i < p.history_count; i++) {
        total += p.history[i].capital;
    }

    return static_cast<double>(total)
            / static_cast<double>(p.history_count);
}

// здесь используем простую прокси-метрику разброса без отдельной статистической библиотеки
double capital_volatility_proxy(const Person& p) {
    if (p.history_count <= 1) {
        return 0.0;
    }

    double avg = average_capital_history(p);
    double acc = 0.0;

    for (int i = 0; i < p.history_count; i++) {
        double d = static_cast<double>(p.history[i].capital) - avg;
        acc += d * d;
    }

    return acc / static_cast<double>(p.history_count);
}


int score_liquidity(const Person& p) {
    int score = 0;

    if (p.bank.ch >= 0) score += 20;
    if (p.bank.sv > 0) score += 20;
    if (emergency_fund_level_3m_ok(p)) score += 30;
    if (emergency_fund_level_6m_ok(p)) score += 30;

    return score;
}

int score_debt(const Person& p) {
    int score = 100;

    if (p.bank.loan <= 0) {
        return score;
    }

    double ratio = debt_to_assets_ratio(p);

    if (ratio > 0.80) score -= 70;
    else if (ratio > 0.60) score -= 50;
    else if (ratio > 0.40) score -= 30;
    else if (ratio > 0.20) score -= 15;

    if (loan_to_salary_ratio(p) > 0.50) score -= 20;
    else if (loan_to_salary_ratio(p) > 0.30) score -= 10;

    if (score < 0) score = 0;
    return score;
}

int score_stability(const Person& p) {
    int total_months = p.history_count;

    if (total_months <= 0) {
        return 0;
    }

    int stable = stable_month_count(p);

    return (stable * 100) / total_months;
}

int score_health(const Person& p) {
    int hp = p.health.hp;

    if (hp < 0) hp = 0;
    if (hp > 100) hp = 100;

    return hp;
}

// итоговый score специально грубый и объяснимый, чтобы его было легко читать в отчёте
int calc_financial_score(const Person& p) {
    int s1 = score_liquidity(p);
    int s2 = score_debt(p);
    int s3 = score_stability(p);
    int s4 = score_health(p);

    int score = (s1 + s2 + s3 + s4) / 4;

    if (score < 0) score = 0;
    if (score > 100) score = 100;

    return score;
}


const Person& richer_person_by_capital() {
    if (Dilshot.cap >= Analbek.cap) {
        return Dilshot;
    }
    return Analbek;
}

const Person& stronger_person_by_savings() {
    if (Dilshot.bank.sv >= Analbek.bank.sv) {
        return Dilshot;
    }
    return Analbek;
}

const Person& healthier_person() {
    if (Dilshot.health.hp >= Analbek.health.hp) {
        return Dilshot;
    }
    return Analbek;
}

const Person& safer_person_by_score() {
    if (calc_financial_score(Dilshot) >= calc_financial_score(Analbek)) {
        return Dilshot;
    }
    return Analbek;
}

RUB capital_gap() {
    return Dilshot.cap - Analbek.cap;
}

RUB savings_gap() {
    return Dilshot.bank.sv - Analbek.bank.sv;
}

RUB loan_gap() {
    return Dilshot.bank.loan - Analbek.bank.loan;
}


const char* debt_status(const Person& p) {
    if (p.bank.loan <= 0) {
        return "no-loan";
    }

    double ratio = debt_to_assets_ratio(p);

    if (ratio > 0.70) return "very-high";
    if (ratio > 0.45) return "high";
    if (ratio > 0.20) return "medium";
    return "low";
}

const char* liquidity_status(const Person& p) {
    if (p.bank.ch < 0) {
        return "critical";
    }

    if (emergency_fund_level_6m_ok(p)) {
        return "strong";
    }

    if (emergency_fund_level_3m_ok(p)) {
        return "normal";
    }

    if (p.bank.sv > 0) {
        return "weak";
    }

    return "critical";
}

const char* capital_trend_status(const Person& p) {
    RUB delta = history_capital_delta(p);

    if (delta > 200000) return "strong-up";
    if (delta > 0)      return "up";
    if (delta == 0)     return "flat";
    if (delta > -200000) return "down";
    return "strong-down";
}

const char* overall_status(const Person& p) {
    int score = calc_financial_score(p);

    if (score >= 80) return "excellent";
    if (score >= 65) return "good";
    if (score >= 50) return "acceptable";
    if (score >= 35) return "weak";
    return "critical";
}


int person_is_financially_positive(const Person& p) {
        return p.cap > 0;
    }

    int person_is_overleveraged(const Person& p) {
        return debt_to_assets_ratio(p) > 0.60;
    }

    int person_has_good_buffer(const Person& p) {
        return emergency_fund_level_3m_ok(p);
    }

    int person_has_strong_buffer(const Person& p) {
        return emergency_fund_level_6m_ok(p);
    }

    int person_is_improving(const Person& p) {
        return history_capital_delta(p) > 0;
    }

// функции вывода информации
void print_separator() {
    std::printf("------------------------------------------------------------\n");
}

void print_big_separator() {
    std::printf("============================================================\n");
}

void print_title(const char* title) {
    print_big_separator();
    std::printf("%s\n", title);
    print_big_separator();
}

void print_subtitle(const char* title) {
    print_separator();
    std::printf("%s\n", title);
    print_separator();
}

void print_identity(const Person& p) {
    std::printf("Name              : %s\n", p.name);
    std::printf("Age               : %d\n", p.age);
    std::printf("Health HP         : %d\n", p.health.hp);
}

void print_household(const Person& p) {
    std::printf("Married           : %d\n", static_cast<int>(p.family.married));
    std::printf("Kids              : %d\n", p.family.kids);
    std::printf("Has pet           : %d\n", static_cast<int>(p.pet.alive));
}

void print_assets_block(const Person& p) {
    std::printf("Checking          : %lld RUB\n", p.bank.ch);
    std::printf("Savings           : %lld RUB\n", p.bank.sv);
    std::printf("Investments       : %lld RUB\n", p.investments);
    std::printf("Car value         : %lld RUB\n", p.car.market_value);
    std::printf("House value       : %lld RUB\n", p.house.house_value);
    std::printf("Capital           : %lld RUB\n", p.cap);
}

void print_liabilities_block(const Person& p) {
    std::printf("Loan              : %lld RUB\n", p.bank.loan);
    std::printf("Loan payment      : %lld RUB/month\n", p.bank.loan_pay_month);
    std::printf("Loan rate         : %.2f%%\n", p.bank.loan_rate);
}

void print_income_block(const Person& p) {
    std::printf("Orders/month      : %lld RUB\n", p.work_taxi.orders_month);
    std::printf("Service fee       : %.2f%%\n", p.work_taxi.service_fee);
    std::printf("Taxi expenses     : %lld RUB\n", p.work_taxi.expenses);
    std::printf("Net salary        : %lld RUB\n", p.work_taxi.salary);
}

void print_costs_block(const Person& p) {
    std::printf("Food              : %lld RUB\n", p.food_month);
    std::printf("Leisure           : %lld RUB\n", p.leisure_month);
    std::printf("Clothes           : %lld RUB\n", p.clothes_month);
    std::printf("Health            : %lld RUB\n", p.health.health_month);
    std::printf("Car fuel          : %lld RUB\n", p.car.fuel_month);
    std::printf("Kids food         : %lld RUB\n", p.family.kids_food_month);
    std::printf("Kids education    : %lld RUB\n", p.family.kids_education_month);
    std::printf("Pet food          : %lld RUB\n", p.pet.feed_month);
    std::printf("Rent              : %lld RUB\n", p.house.owned ? 0LL : p.house.rent_month);
    std::printf("Unexpected last   : %lld RUB\n", p.last_unexpected);
}

void print_cost_summary(const Person& p) {
    std::printf("Recurring cost    : %lld RUB\n", calc_total_recurring_cost(p));
    std::printf("Reserve target    : %lld RUB\n", calc_reserve_target(p));
    std::printf("Month load est.   : %lld RUB\n", calc_total_month_outflow_estimate(p));
    std::printf("Free cash est.    : %lld RUB\n", calc_free_cash_after_all_costs(p));
}

void print_inflation_block(const Person& p) {
    std::printf("Infl food         : %.2f%%\n", p.infl.food);
    std::printf("Infl car value    : %.2f%%\n", p.infl.car_value);
    std::printf("Infl fuel         : %.2f%%\n", p.infl.fuel);
    std::printf("Infl pet food     : %.2f%%\n", p.infl.pet_food);
    std::printf("Infl rent         : %.2f%%\n", p.infl.rent);
    std::printf("Infl clothes      : %.2f%%\n", p.infl.clothes);
    std::printf("Infl health       : %.2f%%\n", p.infl.health);
}

void print_aggregated_stats(const Person& p) {
    std::printf("Months simulated  : %d\n", p.stats.months_simulated);
    std::printf("Total salary      : %lld RUB\n", p.stats.total_salary);
    std::printf("Total unexpected  : %lld RUB\n", p.stats.total_unexpected);
    std::printf("Total loan paid   : %lld RUB\n", p.stats.total_loan_paid);
    std::printf("Total food paid   : %lld RUB\n", p.stats.total_food_paid);
    std::printf("Total housing     : %lld RUB\n", p.stats.total_housing_paid);
    std::printf("Total car paid    : %lld RUB\n", p.stats.total_car_paid);
    std::printf("Total pet paid    : %lld RUB\n", p.stats.total_pet_paid);
    std::printf("Total health paid : %lld RUB\n", p.stats.total_health_paid);
    std::printf("Total leisure     : %lld RUB\n", p.stats.total_leisure_paid);
    std::printf("Total clothes     : %lld RUB\n", p.stats.total_clothes_paid);
    std::printf("Total kids paid   : %lld RUB\n", p.stats.total_kids_paid);
}

void print_history_header() {
    std::printf(
        "%-8s %-12s %-12s %-12s %-12s %-12s %-12s\n",
        "Date",
        "Checking",
        "Savings",
        "Loan",
        "Capital",
        "Salary",
        "BasicCost"
    );
}

void print_history_row(const MonthlyStats& s) {
    std::printf(
        "%02d.%04d %-12lld %-12lld %-12lld %-12lld %-12lld %-12lld\n",
        s.month,
        s.year,
        s.checking,
        s.savings,
        s.loan,
        s.capital,
        s.salary,
        s.total_basic_cost
    );
}

void print_history(const Person& p) {
    print_subtitle("History");
    print_history_header();

    for (int i = 0; i < p.history_count; i++) {
        print_history_row(p.history[i]);
    }
}

void print_history_extremes(Person& p) {
    MonthlyStats* best = history_best_month(p);
    MonthlyStats* worst = history_worst_month(p);

    print_subtitle("History extremes");

    if (best != 0) {
        std::printf(
            "Best month         : %02d.%04d, capital = %lld RUB\n",
            best->month,
            best->year,
            best->capital
        );
    }

    if (worst != 0) {
        std::printf(
            "Worst month        : %02d.%04d, capital = %lld RUB\n",
            worst->month,
            worst->year,
            worst->capital
        );
    }
}

void print_ratios(const Person& p) {
    print_subtitle("Ratios");

    std::printf("Debt/assets        : %.4f\n", debt_to_assets_ratio(p));
    std::printf("Savings/assets     : %.4f\n", savings_to_assets_ratio(p));
    std::printf("Checking/assets    : %.4f\n", checking_to_assets_ratio(p));
    std::printf("Invest/assets      : %.4f\n", investments_to_assets_ratio(p));
    std::printf("Housing/assets     : %.4f\n", housing_to_assets_ratio(p));
    std::printf("Car/assets         : %.4f\n", car_to_assets_ratio(p));
    std::printf("Recurring/salary   : %.4f\n", recurring_cost_to_salary_ratio(p));
    std::printf("Loan/salary        : %.4f\n", loan_to_salary_ratio(p));
}

void print_scores(const Person& p) {
    print_subtitle("Scores");

    std::printf("Liquidity score    : %d\n", score_liquidity(p));
    std::printf("Debt score         : %d\n", score_debt(p));
    std::printf("Stability score    : %d\n", score_stability(p));
    std::printf("Health score       : %d\n", score_health(p));
    std::printf("Financial score    : %d\n", calc_financial_score(p));
}

void print_statuses(const Person& p) {
    print_subtitle("Statuses");

    std::printf("Debt status        : %s\n", debt_status(p));
    std::printf("Liquidity status   : %s\n", liquidity_status(p));
    std::printf("Capital trend      : %s\n", capital_trend_status(p));
    std::printf("Overall status     : %s\n", overall_status(p));
}

void print_history_metrics(const Person& p) {
    print_subtitle("History metrics");

    std::printf("Capital first      : %lld RUB\n", history_first_capital(p));
    std::printf("Capital last       : %lld RUB\n", history_last_capital(p));
    std::printf("Capital delta      : %lld RUB\n", history_capital_delta(p));
    std::printf("Savings first      : %lld RUB\n", history_first_savings(p));
    std::printf("Savings last       : %lld RUB\n", history_last_savings(p));
    std::printf("Savings delta      : %lld RUB\n", history_savings_delta(p));
    std::printf("Avg salary         : %.2f RUB\n", history_avg_salary(p));
    std::printf("Avg basic cost     : %.2f RUB\n", history_avg_basic_cost(p));
    std::printf("Avg unexpected     : %.2f RUB\n", history_avg_unexpected(p));
    std::printf("Stable months      : %d\n", stable_month_count(p));
    std::printf("Negative margins   : %d\n", history_negative_margin_months(p));
}

void print_summary(const Person& p) {
    print_title(p.name);
    print_identity(p);
    print_household(p);
    print_income_block(p);
    print_assets_block(p);
    print_liabilities_block(p);
    print_cost_summary(p);
}

void print_full_report(Person& p) {
    print_title("FULL REPORT");

    print_summary(p);

    print_subtitle("Costs");
    print_costs_block(p);

    print_subtitle("Inflation");
    print_inflation_block(p);

    print_subtitle("Aggregated stats");
    print_aggregated_stats(p);

    print_ratios(p);
    print_scores(p);
    print_statuses(p);
    print_history_metrics(p);
    print_history_extremes(p);
    print_history(p);
}

void print_comparison_header() {
    print_title("COMPARISON");
}

void print_comparison_main() {
    std::printf("Richer by capital  : %s\n", richer_person_by_capital().name);
    std::printf("Stronger savings   : %s\n", stronger_person_by_savings().name);
    std::printf("Healthier          : %s\n", healthier_person().name);
    std::printf("Safer by score     : %s\n", safer_person_by_score().name);
    std::printf("Capital gap        : %lld RUB\n", capital_gap());
    std::printf("Savings gap        : %lld RUB\n", savings_gap());
    std::printf("Loan gap           : %lld RUB\n", loan_gap());
}

void print_comparison_statuses() {
    std::printf(
        "%s overall        : %s\n",
        Dilshot.name,
        overall_status(Dilshot)
    );
    std::printf(
        "%s overall        : %s\n",
        Analbek.name,
        overall_status(Analbek)
    );
}

void print_comparison_scores() {
    std::printf(
        "%s score          : %d\n",
        Dilshot.name,
        calc_financial_score(Dilshot)
    );
    std::printf(
        "%s score          : %d\n",
        Analbek.name,
        calc_financial_score(Analbek)
    );
}

void print_comparison_report() {
    print_comparison_header();
    print_comparison_main();
    print_comparison_statuses();
    print_comparison_scores();
}

void print_final_short_conclusion() {
    print_title("FINAL SHORT CONCLUSION");

    if (calc_financial_score(Dilshot) > calc_financial_score(Analbek)) {
        std::printf(
            "%s is financially stronger at the end of simulation.\n",
            Dilshot.name
        );
    } else if (calc_financial_score(Dilshot) < calc_financial_score(Analbek)) {
        std::printf(
            "%s is financially stronger at the end of simulation.\n",
            Analbek.name
        );
    } else {
        std::printf("Both persons have equal final financial score.\n");
    }

    std::printf(
        "%s capital trend: %s\n",
        Dilshot.name,
        capital_trend_status(Dilshot)
    );
    std::printf(
        "%s capital trend: %s\n",
        Analbek.name,
        capital_trend_status(Analbek)
    );
}
RUB run_basic_expense_stage(Person& p) {
    RUB basic_cost = 0;

    basic_cost = pay_all_basic_costs(p);

    return basic_cost;
}

void run_unexpected_stage(Person& p, int month, int year) {
    pay_unexpected(p, month, year);
}

void run_credit_stage(Person& p) {
    pay_loan(p);
    fix_negative_checking(p);
}

void run_savings_income_stage(Person& p) {
    add_savings_income(p);
    fix_negative_checking(p);
}

void run_postprocessing_stage(Person& p, int month) {
    update_post_month_state(p, month);
    normalize_negative_values(p);
    recalc_cap(p);
}

// шаг устроен так, чтобы сначала применить сценарий месяца, а потом уже списывать деньги
void step_month(Person& p, int month, int year) {
    RUB basic_cost = 0;

    update_pre_month_state(p, month, year);

    add_inflation(p);

    process_income_stage(p, month, year);

    move_to_savings(p);

    basic_cost = run_basic_expense_stage(p);

    run_unexpected_stage(p, month, year);

    run_credit_stage(p);

    run_savings_income_stage(p);

    run_postprocessing_stage(p, month);

    finalize_person_after_month(p, month, year, basic_cost);
}

void step_all_persons(int month, int year) {
    step_month(Dilshot, month, year);
    step_month(Analbek, month, year);
}

void print_month_info(int month, int year) {
    print_big_separator();
    std::printf("Month: %02d  Year: %d\n", month, year);
    print_big_separator();
}

void print_monthly_cap(const Person& p, int month, int year) {
    std::printf(
        "%s at %02d.%04d -> cap = %lld RUB, salary = %lld RUB, savings = %lld RUB\n",
        p.name,
        month,
        year,
        p.cap,
        p.work_taxi.salary,
        p.bank.sv
    );
}

void print_monthly_status_line(const Person& p) {
    std::printf(
        "  %-8s | checking=%10lld | loan=%10lld | status=%s\n",
        p.name,
        p.bank.ch,
        p.bank.loan,
        overall_status(p)
    );
}

void print_monthly_snapshot(int month, int year) {
    print_month_info(month, year);
    print_monthly_cap(Dilshot, month, year);
    print_monthly_cap(Analbek, month, year);
    print_monthly_status_line(Dilshot);
    print_monthly_status_line(Analbek);
    std::printf("\n");
}

void print_year_marker(int year) {
    print_title("YEAR MARKER");
    std::printf("Completed year boundary: %d\n", year);
}

void print_mid_simulation_report_if_needed(int month, int year) {
    if (month == 8 && year == 2026) {
        print_title("MID SIMULATION REPORT");
        print_summary(Dilshot);
        print_summary(Analbek);
        print_comparison_report();
    }
}

void print_year_end_report_if_needed(int month, int year) {
    if (month == 12) {
        print_year_marker(year);
        print_comparison_report();
    }
}

// конец периода не включён в цикл, поэтому симуляция идёт до 03.2027 не доходя до самого шага марта
void run_simulation() {
    int month = START_MONTH;
    int year  = START_YEAR;

    while (!is_finish_date(month, year)) {
        step_all_persons(month, year);

        print_mid_simulation_report_if_needed(month, year);
        print_year_end_report_if_needed(month, year);

        next_month(month, year);
    }
}

void run_simulation_with_monthly_print() {
    int month = START_MONTH;
    int year  = START_YEAR;

    while (!is_finish_date(month, year)) {
        step_all_persons(month, year);
        print_monthly_snapshot(month, year);
        print_mid_simulation_report_if_needed(month, year);
        print_year_end_report_if_needed(month, year);
        next_month(month, year);
    }
}

void print_results() {
    print_title("SIMULATION ENDED");

    print_full_report(Dilshot);
    print_full_report(Analbek);

    print_comparison_report();

    print_final_short_conclusion();
}

void print_compact_results() {
    print_title("COMPACT RESULTS");
    print_summary(Dilshot);
    print_summary(Analbek);
    print_comparison_report();
}

void print_debug_state() {
    print_title("DEBUG STATE");
    std::printf("Dilshot history rows : %d\n", Dilshot.history_count);
    std::printf("Analbek history rows : %d\n", Analbek.history_count);
    std::printf("Dilshot months       : %d\n", Dilshot.stats.months_simulated);
    std::printf("Analbek months       : %d\n", Analbek.stats.months_simulated);
}

void print_intro() {
    print_title("FINANCIAL LIFE SIMULATOR");
    std::printf("Characters : Dilshot, Analbek\n");
    std::printf("Period     : %02d.%04d - %02d.%04d (end exclusive)\n",
                START_MONTH,
                START_YEAR,
                END_MONTH,
                END_YEAR);
    std::printf("\n");
}

void print_initial_state() {
    print_title("INITIAL STATE");
    print_summary(Dilshot);
    print_summary(Analbek);
    print_comparison_report();
}

void prepare_simulation() {
    init_all();
    validate_all();
    seed_all_aggregates();
    capture_all_initial_snapshots();
}

void run_default_flow() {
    print_intro();
    prepare_simulation();
    print_initial_state();
    run_simulation();
    print_results();
}

int main() {
    run_default_flow();
    return 0;
}
