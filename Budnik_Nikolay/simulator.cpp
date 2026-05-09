#include <stdio.h>

using RUB = long long;


const int START_MONTH = 2;
const int START_YEAR = 2026;
const int END_MONTH = 3;
const int END_YEAR = 2036;

const int HISTORY_SIZE = 140;

const double DEPOSIT_RATE = 14.5;

const double FOOD_INFLATION = 1.007;
const double UTILITY_INFLATION = 1.006;
const double HOME_INFLATION = 1.006;
const double PET_INFLATION = 1.006;
const double CAR_INFLATION = 1.005;
const double HEALTH_INFLATION = 1.005;
const double OTHER_INFLATION = 1.004;

struct Food {
    RUB bread;
    RUB milk;
    RUB eggs;
    RUB beef;
    RUB chicken;
    RUB fish;
    RUB cheese;
    RUB yogurt;
    RUB rice;
    RUB pasta;
    RUB potatoes;
    RUB vegetables;
    RUB fruits;
    RUB tea;
    RUB coffee;
    RUB sweets;
    RUB oil;
    RUB salt;
    RUB sugar;
    RUB water;
};

struct Utility {
    RUB electricity;
    RUB cold_water;
    RUB hot_water;
    RUB heating;
    RUB gas;
    RUB internet;
    RUB mobile;
    RUB cleaning;
    RUB repair;
    RUB elevator;
    RUB security;
    RUB garbage;
};

struct Home {
    int owned;
    RUB rent;
    RUB house_value;
    RUB furniture;
    RUB appliances;
    RUB small_repair;
    RUB home_insurance;
};

struct Pet {
    int alive;
    int death_month;
    int death_year;
    RUB food;
    RUB vet;
    RUB medicine;
    RUB toys;
    RUB grooming;
    RUB accessories;
};

struct Car {
    int has_car;
    RUB value;
    RUB fuel;
    RUB insurance;
    RUB service;
    RUB repair;
    RUB parking;
    RUB tax;
    RUB washing;
    RUB tires;
    RUB fines;
};

struct Family {
    int married;
    int kids;
    RUB kids_food;
    RUB school;
    RUB kindergarten;
    RUB clothes;
    RUB medicine;
    RUB activities;
    RUB gifts;
};

struct Health {
    int hp;
    RUB doctor;
    RUB medicine;
    RUB sport;
    RUB dentist;
    RUB checkup;
    RUB emergency;
};

struct Other {
    RUB clothes;
    RUB leisure;
    RUB subscriptions;
    RUB hobbies;
    RUB gifts;
    RUB trips;
    RUB personal_care;
    RUB education;
};

struct Bank {
    RUB account;
    RUB deposit;
    RUB mortgage;
    RUB car_loan;
    RUB consumer_loan;
    RUB mortgage_payment;
    RUB car_loan_payment;
    RUB consumer_loan_payment;
    double mortgage_rate;
    double car_loan_rate;
    double consumer_loan_rate;
};

struct Work {
    RUB salary;
    RUB bonus;
    RUB taxi_orders;
    RUB taxi_expenses;
    int taxi_job;
};

struct MonthInfo {
    int month;
    int year;
    RUB account;
    RUB deposit;
    RUB debt;
    RUB capital;
    RUB income;
    RUB expenses;
    RUB credit_payment;
};

struct Person {
    const char* name;
    int age;
    Food food;
    Utility utility;
    Home home;
    Pet pet;
    Car car;
    Family family;
    Health health;
    Other other;
    Bank bank;
    Work work;
    MonthInfo history[HISTORY_SIZE];
    int history_count;
};

Person Dilshot = {
    "Dilshot",
    32,
    {
        1'200,
        900,
        1'400,
        4'500,
        3'800,
        2'500,
        1'600,
        900,
        800,
        900,
        700,
        2'500,
        2'200,
        500,
        700,
        1'000,
        600,
        100,
        200,
        400
    },
    {
        3'500,
        1'200,
        900,
        4'500,
        900,
        1'000,
        800,
        1'500,
        2'000,
        700,
        500,
        600
    },
    {
        1,
        0,
        4'200'000,
        2'000,
        1'500,
        1'500,
        1'000
    },
    {
        1,
        7,
        2033,
        3'500,
        1'200,
        700,
        500,
        800,
        400
    },
    {
        1,
        1'200'000,
        14'000,
        5'000,
        4'000,
        3'500,
        2'500,
        1'500,
        900,
        2'000,
        500
    },
    {
        1,
        1,
        8'000,
        7'000,
        0,
        3'000,
        1'000,
        4'000,
        2'000
    },
    {
        80,
        2'500,
        1'500,
        3'000,
        2'000,
        1'000,
        500
    },
    {
        5'000,
        9'000,
        1'200,
        3'500,
        2'500,
        6'000,
        2'000,
        2'000
    },
    {
        20'000,
        50'000,
        3'000'000,
        350'000,
        120'000,
        28'000,
        12'000,
        8'000,
        9.0,
        14.0,
        18.0
    },
    {
        0,
        30'000,
        230'000,
        50'000,
        1
    },
    {},
    0
};

Person Analbek = {
    "Analbek",
    35,
    {
        1'000,
        800,
        1'200,
        3'200,
        2'800,
        1'600,
        1'200,
        700,
        700,
        800,
        600,
        1'800,
        1'500,
        400,
        500,
        800,
        500,
        100,
        200,
        300
    },
    {
        2'800,
        900,
        700,
        3'500,
        700,
        800,
        700,
        1'000,
        1'500,
        500,
        300,
        500
    },
    {
        0,
        26'000,
        0,
        1'000,
        500,
        700,
        0
    },
    {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
    },
    {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
    },
    {
        1,
        2,
        12'000,
        10'000,
        8'000,
        4'500,
        1'500,
        5'000,
        3'000
    },
    {
        65,
        3'500,
        2'500,
        0,
        2'500,
        1'000,
        1'000
    },
    {
        3'000,
        5'000,
        900,
        2'000,
        2'000,
        3'000,
        1'500,
        1'000
    },
    {
        10'000,
        0,
        0,
        0,
        250'000,
        0,
        0,
        12'000,
        0.0,
        0.0,
        20.0
    },
    {
        135'000,
        15'000,
        0,
        0,
        0
    },
    {},
    0
};

RUB percent(RUB value, double percent_value) {
    return (RUB)((double)value * percent_value / 100.0);
}

RUB month_percent(RUB value, double year_percent) {
    return percent(value, year_percent / 12.0);
}

RUB total_food(const Food& f) {
    RUB total = 0;
    total += f.bread;
    total += f.milk;
    total += f.eggs;
    total += f.beef;
    total += f.chicken;
    total += f.fish;
    total += f.cheese;
    total += f.yogurt;
    total += f.rice;
    total += f.pasta;
    total += f.potatoes;
    total += f.vegetables;
    total += f.fruits;
    total += f.tea;
    total += f.coffee;
    total += f.sweets;
    total += f.oil;
    total += f.salt;
    total += f.sugar;
    total += f.water;
    return total;
}

RUB total_utility(const Utility& u) {
    RUB total = 0;
    total += u.electricity;
    total += u.cold_water;
    total += u.hot_water;
    total += u.heating;
    total += u.gas;
    total += u.internet;
    total += u.mobile;
    total += u.cleaning;
    total += u.repair;
    total += u.elevator;
    total += u.security;
    total += u.garbage;
    return total;
}

RUB total_home(const Home& h) {
    RUB total = 0;
    if (!h.owned) {
        total += h.rent;
    }
    total += h.furniture;
    total += h.appliances;
    total += h.small_repair;
    total += h.home_insurance;
    return total;
}

RUB total_pet(const Pet& p) {
    RUB total = 0;
    if (p.alive) {
        total += p.food;
        total += p.vet;
        total += p.medicine;
        total += p.toys;
        total += p.grooming;
        total += p.accessories;
    }
    return total;
}

RUB total_car(const Car& c) {
    RUB total = 0;
    if (c.has_car) {
        total += c.fuel;
        total += c.insurance;
        total += c.service;
        total += c.repair;
        total += c.parking;
        total += c.tax;
        total += c.washing;
        total += c.tires;
        total += c.fines;
    }
    return total;
}

RUB total_family(const Family& f) {
    RUB total = 0;
    total += f.kids_food;
    total += f.school;
    total += f.kindergarten;
    total += f.clothes;
    total += f.medicine;
    total += f.activities;
    total += f.gifts;
    return total;
}

RUB total_health(const Health& h) {
    RUB total = 0;
    total += h.doctor;
    total += h.medicine;
    total += h.sport;
    total += h.dentist;
    total += h.checkup;
    total += h.emergency;
    return total;
}

RUB total_other(const Other& o) {
    RUB total = 0;
    total += o.clothes;
    total += o.leisure;
    total += o.subscriptions;
    total += o.hobbies;
    total += o.gifts;
    total += o.trips;
    total += o.personal_care;
    total += o.education;
    return total;
}

RUB total_basic_expenses(const Person& p) {
    RUB total = 0;
    total += total_food(p.food);
    total += total_utility(p.utility);
    total += total_home(p.home);
    total += total_pet(p.pet);
    total += total_car(p.car);
    total += total_family(p.family);
    total += total_health(p.health);
    total += total_other(p.other);
    return total;
}

RUB total_debt(const Person& p) {
    RUB total = 0;
    total += p.bank.mortgage;
    total += p.bank.car_loan;
    total += p.bank.consumer_loan;
    return total;
}

RUB total_assets(const Person& p) {
    RUB total = 0;
    total += p.bank.account;
    total += p.bank.deposit;
    total += p.car.value;
    if (p.home.owned) {
        total += p.home.house_value;
    }
    return total;
}

RUB capital(const Person& p) {
    return total_assets(p) - total_debt(p);
}

RUB salary_for_month(const Person& p, int month, int year) {
    RUB salary = p.work.salary;
    if (p.work.taxi_job) {
        RUB fee = percent(p.work.taxi_orders, 22.0);
        salary = p.work.taxi_orders - fee - p.work.taxi_expenses;
    }
    if (salary < 0) {
        salary = 0;
    }
    if (month == 12) {
        salary += p.work.bonus;
    }
    if (p.name[0] == 'D' && year >= 2030) {
        salary += 15'000;
    }
    if (p.name[0] == 'A' && year >= 2031) {
        salary += 10'000;
    }
    return salary;
}

void receive_salary(Person& p, int month, int year) {
    p.bank.account += salary_for_month(p, month, year);
}

void pay_basic_expenses(Person& p) {
    p.bank.account -= total_food(p.food);
    p.bank.account -= total_utility(p.utility);
    p.bank.account -= total_home(p.home);
    p.bank.account -= total_pet(p.pet);
    p.bank.account -= total_car(p.car);
    p.bank.account -= total_family(p.family);
    p.bank.account -= total_health(p.health);
    p.bank.account -= total_other(p.other);
}

RUB credit_payment(RUB debt, RUB month_payment) {
    if (debt <= 0) {
        return 0;
    }
    if (debt < month_payment) {
        return debt;
    }
    return month_payment;
}

void add_credit_interest(RUB& debt, double rate) {
    if (debt > 0) {
        debt += month_percent(debt, rate);
    }
}

RUB pay_credit(RUB& debt, RUB month_payment, double rate, Bank& bank) {
    RUB payment = credit_payment(debt, month_payment);
    bank.account -= payment;
    debt -= payment;
    add_credit_interest(debt, rate);
    return payment;
}

RUB pay_credits(Person& p) {
    RUB total = 0;
    total += pay_credit(p.bank.mortgage, p.bank.mortgage_payment, p.bank.mortgage_rate, p.bank);
    total += pay_credit(p.bank.car_loan, p.bank.car_loan_payment, p.bank.car_loan_rate, p.bank);
    total += pay_credit(p.bank.consumer_loan, p.bank.consumer_loan_payment, p.bank.consumer_loan_rate, p.bank);
    return total;
}

void move_money(Person& p) {
    RUB reserve = total_basic_expenses(p);
    if (p.bank.account > reserve) {
        RUB move = p.bank.account - reserve;
        p.bank.account -= move;
        p.bank.deposit += move;
    }
    if (p.bank.account < 0) {
        RUB need = -p.bank.account;
        if (p.bank.deposit >= need) {
            p.bank.deposit -= need;
            p.bank.account = 0;
        } else {
            p.bank.account += p.bank.deposit;
            p.bank.deposit = 0;
        }
    }
}

void add_deposit_interest(Person& p) {
    if (p.bank.deposit > 0) {
        p.bank.deposit += month_percent(p.bank.deposit, DEPOSIT_RATE);
    }
}

void apply_inflation(Person& p) {
    p.food.bread = (RUB)(p.food.bread * FOOD_INFLATION);
    p.food.milk = (RUB)(p.food.milk * FOOD_INFLATION);
    p.food.eggs = (RUB)(p.food.eggs * FOOD_INFLATION);
    p.food.beef = (RUB)(p.food.beef * FOOD_INFLATION);
    p.food.chicken = (RUB)(p.food.chicken * FOOD_INFLATION);
    p.food.fish = (RUB)(p.food.fish * FOOD_INFLATION);
    p.food.cheese = (RUB)(p.food.cheese * FOOD_INFLATION);
    p.food.yogurt = (RUB)(p.food.yogurt * FOOD_INFLATION);
    p.food.rice = (RUB)(p.food.rice * FOOD_INFLATION);
    p.food.pasta = (RUB)(p.food.pasta * FOOD_INFLATION);
    p.food.potatoes = (RUB)(p.food.potatoes * FOOD_INFLATION);
    p.food.vegetables = (RUB)(p.food.vegetables * FOOD_INFLATION);
    p.food.fruits = (RUB)(p.food.fruits * FOOD_INFLATION);
    p.food.tea = (RUB)(p.food.tea * FOOD_INFLATION);
    p.food.coffee = (RUB)(p.food.coffee * FOOD_INFLATION);
    p.food.sweets = (RUB)(p.food.sweets * FOOD_INFLATION);
    p.food.oil = (RUB)(p.food.oil * FOOD_INFLATION);
    p.food.salt = (RUB)(p.food.salt * FOOD_INFLATION);
    p.food.sugar = (RUB)(p.food.sugar * FOOD_INFLATION);
    p.food.water = (RUB)(p.food.water * FOOD_INFLATION);
    p.family.kids_food = (RUB)(p.family.kids_food * FOOD_INFLATION);
    p.family.school = (RUB)(p.family.school * FOOD_INFLATION);
    p.family.kindergarten = (RUB)(p.family.kindergarten * FOOD_INFLATION);

    p.utility.electricity = (RUB)(p.utility.electricity * UTILITY_INFLATION);
    p.utility.cold_water = (RUB)(p.utility.cold_water * UTILITY_INFLATION);
    p.utility.hot_water = (RUB)(p.utility.hot_water * UTILITY_INFLATION);
    p.utility.heating = (RUB)(p.utility.heating * UTILITY_INFLATION);
    p.utility.gas = (RUB)(p.utility.gas * UTILITY_INFLATION);
    p.utility.internet = (RUB)(p.utility.internet * UTILITY_INFLATION);
    p.utility.mobile = (RUB)(p.utility.mobile * UTILITY_INFLATION);
    p.utility.cleaning = (RUB)(p.utility.cleaning * UTILITY_INFLATION);
    p.utility.repair = (RUB)(p.utility.repair * UTILITY_INFLATION);
    p.utility.elevator = (RUB)(p.utility.elevator * UTILITY_INFLATION);
    p.utility.security = (RUB)(p.utility.security * UTILITY_INFLATION);
    p.utility.garbage = (RUB)(p.utility.garbage * UTILITY_INFLATION);

    p.home.rent = (RUB)(p.home.rent * HOME_INFLATION);
    p.home.house_value = (RUB)(p.home.house_value * HOME_INFLATION);
    p.home.furniture = (RUB)(p.home.furniture * HOME_INFLATION);
    p.home.appliances = (RUB)(p.home.appliances * HOME_INFLATION);
    p.home.small_repair = (RUB)(p.home.small_repair * HOME_INFLATION);
    p.home.home_insurance = (RUB)(p.home.home_insurance * HOME_INFLATION);

    p.pet.food = (RUB)(p.pet.food * PET_INFLATION);
    p.pet.vet = (RUB)(p.pet.vet * PET_INFLATION);
    p.pet.medicine = (RUB)(p.pet.medicine * PET_INFLATION);
    p.pet.toys = (RUB)(p.pet.toys * PET_INFLATION);
    p.pet.grooming = (RUB)(p.pet.grooming * PET_INFLATION);
    p.pet.accessories = (RUB)(p.pet.accessories * PET_INFLATION);

    p.car.value = (RUB)(p.car.value * CAR_INFLATION);
    p.car.fuel = (RUB)(p.car.fuel * CAR_INFLATION);
    p.car.insurance = (RUB)(p.car.insurance * CAR_INFLATION);
    p.car.service = (RUB)(p.car.service * CAR_INFLATION);
    p.car.repair = (RUB)(p.car.repair * CAR_INFLATION);
    p.car.parking = (RUB)(p.car.parking * CAR_INFLATION);
    p.car.tax = (RUB)(p.car.tax * CAR_INFLATION);
    p.car.washing = (RUB)(p.car.washing * CAR_INFLATION);
    p.car.tires = (RUB)(p.car.tires * CAR_INFLATION);
    p.car.fines = (RUB)(p.car.fines * CAR_INFLATION);



    p.family.clothes = (RUB)(p.family.clothes * OTHER_INFLATION);
    p.family.activities = (RUB)(p.family.activities * OTHER_INFLATION);
    p.family.gifts = (RUB)(p.family.gifts * OTHER_INFLATION);
    p.other.clothes = (RUB)(p.other.clothes * OTHER_INFLATION);
    p.other.leisure = (RUB)(p.other.leisure * OTHER_INFLATION);
    p.other.subscriptions = (RUB)(p.other.subscriptions * OTHER_INFLATION);
    p.other.hobbies = (RUB)(p.other.hobbies * OTHER_INFLATION);
    p.other.gifts = (RUB)(p.other.gifts * OTHER_INFLATION);
    p.other.trips = (RUB)(p.other.trips * OTHER_INFLATION);
    p.other.personal_care = (RUB)(p.other.personal_care * OTHER_INFLATION);
    p.other.education = (RUB)(p.other.education * OTHER_INFLATION);

    p.family.medicine = (RUB)(p.family.medicine * HEALTH_INFLATION);
    p.health.doctor = (RUB)(p.health.doctor * HEALTH_INFLATION);
    p.health.medicine = (RUB)(p.health.medicine * HEALTH_INFLATION);
    p.health.sport = (RUB)(p.health.sport * HEALTH_INFLATION);
    p.health.dentist = (RUB)(p.health.dentist * HEALTH_INFLATION);
    p.health.checkup = (RUB)(p.health.checkup * HEALTH_INFLATION);
    p.health.emergency = (RUB)(p.health.emergency * HEALTH_INFLATION);
}

void update_pet(Person& p, int month, int year) {
    if (p.pet.alive && month == p.pet.death_month && year == p.pet.death_year) {
        p.pet.alive = 0;
        p.pet.food = 0;
        p.pet.vet = 0;
        p.pet.medicine = 0;
        p.pet.toys = 0;
        p.pet.grooming = 0;
        p.pet.accessories = 0;
    }
}

void update_health_and_age(Person& p, int month) {
    if (month == 2 || month == 3) {
        p.health.hp -= 1;
    }
    if (month == 6) {
        p.health.hp += 1;
    }
    if (p.bank.account < 0) {
        p.health.hp -= 1;
    }
    if (p.health.hp < 0) {
        p.health.hp = 0;
    }
    if (p.health.hp > 100) {
        p.health.hp = 100;
    }
    if (month == 1) {
        p.age += 1;
    }
}

RUB unexpected_expense(const Person& p, int month, int year) {
    if (p.name[0] == 'D' && month == 8 && year == 2028) {
        return 30'000;
    }
    if (p.name[0] == 'A' && month == 5 && year == 2029) {
        return 20'000;
    }
    if (month == 11) {
        return 8'000;
    }
    return 0;
}

void save_history(Person& p, int month, int year, RUB income, RUB expenses, RUB credit_payment) {
    if (p.history_count >= HISTORY_SIZE) {
        return;
    }
    MonthInfo& h = p.history[p.history_count];
    h.month = month;
    h.year = year;
    h.account = p.bank.account;
    h.deposit = p.bank.deposit;
    h.debt = total_debt(p);
    h.capital = capital(p);
    h.income = income;
    h.expenses = expenses;
    h.credit_payment = credit_payment;
    p.history_count += 1;
}

void simulate_month(Person& p, int month, int year) {
    update_pet(p, month, year);
    apply_inflation(p);
    RUB income = salary_for_month(p, month, year);
    receive_salary(p, month, year);
    RUB expenses = total_basic_expenses(p);
    pay_basic_expenses(p);
    p.bank.account -= unexpected_expense(p, month, year);
    RUB credit_payment = pay_credits(p);
    move_money(p);
    add_deposit_interest(p);
    update_health_and_age(p, month);
    save_history(p, month, year, income, expenses, credit_payment);
}

void next_month(int& month, int& year) {
    month += 1;
    if (month == 13) {
        month = 1;
        year += 1;
    }
}

void simulate(Person& a, Person& b) {
    int month = START_MONTH;
    int year = START_YEAR;
    while (!(month == END_MONTH && year == END_YEAR)) {
        simulate_month(a, month, year);
        simulate_month(b, month, year);
        next_month(month, year);
    }
}

RUB first_capital(const Person& p) {
    if (p.history_count == 0) {
        return 0;
    }
    return p.history[0].capital;
}

RUB last_capital(const Person& p) {
    if (p.history_count == 0) {
        return 0;
    }
    return p.history[p.history_count - 1].capital;
}

RUB capital_change(const Person& p) {
    return last_capital(p) - first_capital(p);
}

RUB total_income(const Person& p) {
    RUB total = 0;
    for (int i = 0; i < p.history_count; i++) {
        total += p.history[i].income;
    }
    return total;
}

RUB total_expenses(const Person& p) {
    RUB total = 0;
    for (int i = 0; i < p.history_count; i++) {
        total += p.history[i].expenses;
    }
    return total;
}

RUB total_credit_payments(const Person& p) {
    RUB total = 0;
    for (int i = 0; i < p.history_count; i++) {
        total += p.history[i].credit_payment;
    }
    return total;
}

int bad_months(const Person& p) {
    int count = 0;
    for (int i = 0; i < p.history_count; i++) {
        RUB free_money = p.history[i].income - p.history[i].expenses - p.history[i].credit_payment;
        if (free_money < 0) {
            count += 1;
        }
    }
    return count;
}

int score(const Person& p) {
    int result = 100;
    if (total_debt(p) > 0) {
        result -= 20;
    }
    if (p.bank.deposit < total_basic_expenses(p) * 3) {
        result -= 20;
    }
    if (p.health.hp < 60) {
        result -= 20;
    }
    if (bad_months(p) > 12) {
        result -= 20;
    }
    if (capital(p) < 0) {
        result -= 20;
    }
    if (result < 0) {
        result = 0;
    }
    return result;
}

const char* status(const Person& p) {
    if (score(p) >= 80) {
        return "good";
    }
    if (score(p) >= 50) {
        return "normal";
    }
    return "bad";
}

double rub_ratio(RUB part, RUB total) {
    if (total <= 0) {
        return 0.0;
    }
    return (double)part / (double)total;
}

double food_share(const Person& p) {
    return rub_ratio(total_food(p.food), total_basic_expenses(p));
}

double utility_share(const Person& p) {
    return rub_ratio(total_utility(p.utility), total_basic_expenses(p));
}

double home_share(const Person& p) {
    return rub_ratio(total_home(p.home), total_basic_expenses(p));
}

double pet_share(const Person& p) {
    return rub_ratio(total_pet(p.pet), total_basic_expenses(p));
}

double car_share(const Person& p) {
    return rub_ratio(total_car(p.car), total_basic_expenses(p));
}

double family_share(const Person& p) {
    return rub_ratio(total_family(p.family), total_basic_expenses(p));
}

double health_share(const Person& p) {
    return rub_ratio(total_health(p.health), total_basic_expenses(p));
}

double other_share(const Person& p) {
    return rub_ratio(total_other(p.other), total_basic_expenses(p));
}

double debt_to_assets(const Person& p) {
    return rub_ratio(total_debt(p), total_assets(p));
}

double deposit_to_expenses(const Person& p) {
    return rub_ratio(p.bank.deposit, total_basic_expenses(p));
}

double credit_payment_to_income(const Person& p) {
    RUB income = salary_for_month(p, END_MONTH, END_YEAR);
    RUB payment = p.bank.mortgage_payment + p.bank.car_loan_payment + p.bank.consumer_loan_payment;
    return rub_ratio(payment, income);
}

int mortgage_is_paid(const Person& p) {
    return p.bank.mortgage <= 0;
}

int car_loan_is_paid(const Person& p) {
    return p.bank.car_loan <= 0;
}

int consumer_loan_is_paid(const Person& p) {
    return p.bank.consumer_loan <= 0;
}

int all_debts_are_paid(const Person& p) {
    return total_debt(p) <= 0;
}

int has_required_history(const Person& p) {
    return p.history_count >= 120;
}

void print_expense_shares(const Person& p) {
    printf("expense shares\n");
    printf("food share: %.3f\n", food_share(p));
    printf("utility share: %.3f\n", utility_share(p));
    printf("home share: %.3f\n", home_share(p));
    printf("pet share: %.3f\n", pet_share(p));
    printf("car share: %.3f\n", car_share(p));
    printf("family share: %.3f\n", family_share(p));
    printf("health share: %.3f\n", health_share(p));
    printf("other share: %.3f\n", other_share(p));
}

void print_debt_analysis(const Person& p) {
    printf("debt analysis\n");
    printf("debt to assets: %.3f\n", debt_to_assets(p));
    printf("deposit to expenses: %.3f\n", deposit_to_expenses(p));
    printf("credit payment to income: %.3f\n", credit_payment_to_income(p));
    printf("mortgage paid: %d\n", mortgage_is_paid(p));
    printf("car loan paid: %d\n", car_loan_is_paid(p));
    printf("consumer loan paid: %d\n", consumer_loan_is_paid(p));
    printf("all debts paid: %d\n", all_debts_are_paid(p));
}

void print_history_check(const Person& p) {
    printf("history check\n");
    printf("required history: %d\n", has_required_history(p));
    printf("actual history months: %d\n", p.history_count);
}

RUB current_month_income(const Person& p) {
    return salary_for_month(p, END_MONTH, END_YEAR);
}

RUB current_credit_payment(const Person& p) {
    RUB total = 0;
    if (p.bank.mortgage > 0) {
        total += p.bank.mortgage_payment;
    }
    if (p.bank.car_loan > 0) {
        total += p.bank.car_loan_payment;
    }
    if (p.bank.consumer_loan > 0) {
        total += p.bank.consumer_loan_payment;
    }
    return total;
}

RUB current_free_money(const Person& p) {
    return current_month_income(p) - total_basic_expenses(p) - current_credit_payment(p);
}

int deposit_cover_months(const Person& p) {
    RUB expenses = total_basic_expenses(p);
    if (expenses <= 0) {
        return 0;
    }
    return (int)(p.bank.deposit / expenses);
}

int months_to_pay_credit(RUB debt, RUB payment) {
    int months = 0;
    if (payment <= 0) {
        return 0;
    }
    while (debt > 0 && months < 600) {
        if (debt <= payment) {
            debt = 0;
        } else {
            debt -= payment;
        }
        months += 1;
    }
    return months;
}

int months_to_pay_mortgage(const Person& p) {
    return months_to_pay_credit(p.bank.mortgage, p.bank.mortgage_payment);
}

int months_to_pay_car_loan(const Person& p) {
    return months_to_pay_credit(p.bank.car_loan, p.bank.car_loan_payment);
}

int months_to_pay_consumer_loan(const Person& p) {
    return months_to_pay_credit(p.bank.consumer_loan, p.bank.consumer_loan_payment);
}

int has_good_cash_reserve(const Person& p) {
    return deposit_cover_months(p) >= 3;
}

int has_big_debt(const Person& p) {
    return total_debt(p) > total_assets(p) / 2;
}

int has_expensive_life(const Person& p) {
    return total_basic_expenses(p) > current_month_income(p);
}

int has_negative_capital(const Person& p) {
    return capital(p) < 0;
}

int has_low_health(const Person& p) {
    return p.health.hp < 60;
}

void print_current_money_plan(const Person& p) {
    printf("current money plan\n");
    printf("income: %lld\n", current_month_income(p));
    printf("expenses: %lld\n", total_basic_expenses(p));
    printf("credit payment: %lld\n", current_credit_payment(p));
    printf("free money: %lld\n", current_free_money(p));
}

void print_credit_payoff_plan(const Person& p) {
    printf("credit payoff plan\n");
    printf("mortgage months: %d\n", months_to_pay_mortgage(p));
    printf("car loan months: %d\n", months_to_pay_car_loan(p));
    printf("consumer loan months: %d\n", months_to_pay_consumer_loan(p));
}

void print_simple_risks(const Person& p) {
    printf("simple risks\n");
    printf("good cash reserve: %d\n", has_good_cash_reserve(p));
    printf("big debt: %d\n", has_big_debt(p));
    printf("expensive life: %d\n", has_expensive_life(p));
    printf("negative capital: %d\n", has_negative_capital(p));
    printf("low health: %d\n", has_low_health(p));
}

void print_credit_explanation() {
    printf("credit explanation\n");
    printf("mortgage is the main long credit\n");
    printf("car loan is connected with transport\n");
    printf("consumer loan is an additional short debt\n");
    printf("each credit has payment and annual rate\n");
}

void print_model_explanation() {
    printf("model explanation\n");
    printf("salary is added every month\n");
    printf("expenses are removed every month\n");
    printf("deposit gets monthly interest\n");
    printf("prices grow because of inflation\n");
    printf("pet costs stop after pet death year\n");
}

RUB income_in_year(const Person& p, int year) {
    RUB total = 0;
    for (int i = 0; i < p.history_count; i++) {
        if (p.history[i].year == year) {
            total += p.history[i].income;
        }
    }
    return total;
}

RUB expenses_in_year(const Person& p, int year) {
    RUB total = 0;
    for (int i = 0; i < p.history_count; i++) {
        if (p.history[i].year == year) {
            total += p.history[i].expenses;
        }
    }
    return total;
}

RUB credit_payments_in_year(const Person& p, int year) {
    RUB total = 0;
    for (int i = 0; i < p.history_count; i++) {
        if (p.history[i].year == year) {
            total += p.history[i].credit_payment;
        }
    }
    return total;
}

void print_year_result(const Person& p, int year) {
    printf("year %d\n", year);
    printf("income: %lld\n", income_in_year(p, year));
    printf("expenses: %lld\n", expenses_in_year(p, year));
    printf("credit payments: %lld\n", credit_payments_in_year(p, year));
}

void print_selected_years(const Person& p) {
    printf("selected years\n");
    print_year_result(p, 2026);
    print_year_result(p, 2030);
    print_year_result(p, 2035);
}

void print_person_main(const Person& p) {
    printf("%s\n", p.name);
    printf("age: %d\n", p.age);
    printf("health: %d/100\n", p.health.hp);
    printf("account: %lld RUB\n", p.bank.account);
    printf("deposit: %lld RUB\n", p.bank.deposit);
    printf("debt: %lld RUB\n", total_debt(p));
    printf("capital: %lld RUB\n", capital(p));
    printf("score: %d/100\n", score(p));
    printf("status: %s\n", status(p));
}

void print_person_expenses(const Person& p) {
    printf("monthly expenses\n");
    printf("food: %lld\n", total_food(p.food));
    printf("utility: %lld\n", total_utility(p.utility));
    printf("home: %lld\n", total_home(p.home));
    printf("pet: %lld\n", total_pet(p.pet));
    printf("car: %lld\n", total_car(p.car));
    printf("family: %lld\n", total_family(p.family));
    printf("health: %lld\n", total_health(p.health));
    printf("other: %lld\n", total_other(p.other));
    printf("total: %lld\n", total_basic_expenses(p));
}

void print_person_credits(const Person& p) {
    printf("credits\n");
    printf("mortgage: %lld\n", p.bank.mortgage);
    printf("car loan: %lld\n", p.bank.car_loan);
    printf("consumer loan: %lld\n", p.bank.consumer_loan);
    printf("mortgage payment: %lld\n", p.bank.mortgage_payment);
    printf("car loan payment: %lld\n", p.bank.car_loan_payment);
    printf("consumer loan payment: %lld\n", p.bank.consumer_loan_payment);
}

void print_first_month_details(const Person& p) {
    if (p.history_count == 0) {
        return;
    }
    const MonthInfo& h = p.history[0];
    printf("first month details\n");
    printf("month: %d\n", h.month);
    printf("year: %d\n", h.year);
    printf("account: %lld\n", h.account);
    printf("deposit: %lld\n", h.deposit);
    printf("debt: %lld\n", h.debt);
    printf("capital: %lld\n", h.capital);
    printf("income: %lld\n", h.income);
    printf("expenses: %lld\n", h.expenses);
    printf("credit payment: %lld\n", h.credit_payment);
}

void print_last_month_details(const Person& p) {
    if (p.history_count == 0) {
        return;
    }
    const MonthInfo& h = p.history[p.history_count - 1];
    printf("last month details\n");
    printf("month: %d\n", h.month);
    printf("year: %d\n", h.year);
    printf("account: %lld\n", h.account);
    printf("deposit: %lld\n", h.deposit);
    printf("debt: %lld\n", h.debt);
    printf("capital: %lld\n", h.capital);
    printf("income: %lld\n", h.income);
    printf("expenses: %lld\n", h.expenses);
    printf("credit payment: %lld\n", h.credit_payment);
}

void print_month_line(const MonthInfo& h) {
    printf("%02d.%04d account=%lld deposit=%lld debt=%lld capital=%lld\n",
        h.month,
        h.year,
        h.account,
        h.deposit,
        h.debt,
        h.capital);
}

void print_first_three_months(const Person& p) {
    printf("first saved months\n");
    for (int i = 0; i < p.history_count && i < 3; i++) {
        print_month_line(p.history[i]);
    }
}

void print_last_three_months(const Person& p) {
    printf("last saved months\n");
    int start = p.history_count - 3;
    if (start < 0) {
        start = 0;
    }
    for (int i = start; i < p.history_count; i++) {
        print_month_line(p.history[i]);
    }
}

void print_person_history(const Person& p) {
    printf("history\n");
    printf("months: %d\n", p.history_count);
    printf("first capital: %lld\n", first_capital(p));
    printf("last capital: %lld\n", last_capital(p));
    printf("capital change: %lld\n", capital_change(p));
    printf("total income: %lld\n", total_income(p));
    printf("total expenses: %lld\n", total_expenses(p));
    printf("total credit payments: %lld\n", total_credit_payments(p));
    printf("bad months: %d\n", bad_months(p));
    print_first_month_details(p);
    print_last_month_details(p);
}

void print_food_bread(const Person& p) {
    printf("bread: %lld\n", (RUB)p.food.bread);
}

void print_food_milk(const Person& p) {
    printf("milk: %lld\n", (RUB)p.food.milk);
}

void print_food_eggs(const Person& p) {
    printf("eggs: %lld\n", (RUB)p.food.eggs);
}

void print_food_beef(const Person& p) {
    printf("beef: %lld\n", (RUB)p.food.beef);
}

void print_food_chicken(const Person& p) {
    printf("chicken: %lld\n", (RUB)p.food.chicken);
}

void print_food_fish(const Person& p) {
    printf("fish: %lld\n", (RUB)p.food.fish);
}

void print_food_cheese(const Person& p) {
    printf("cheese: %lld\n", (RUB)p.food.cheese);
}

void print_food_yogurt(const Person& p) {
    printf("yogurt: %lld\n", (RUB)p.food.yogurt);
}

void print_food_rice(const Person& p) {
    printf("rice: %lld\n", (RUB)p.food.rice);
}

void print_food_pasta(const Person& p) {
    printf("pasta: %lld\n", (RUB)p.food.pasta);
}

void print_food_potatoes(const Person& p) {
    printf("potatoes: %lld\n", (RUB)p.food.potatoes);
}

void print_food_vegetables(const Person& p) {
    printf("vegetables: %lld\n", (RUB)p.food.vegetables);
}

void print_food_fruits(const Person& p) {
    printf("fruits: %lld\n", (RUB)p.food.fruits);
}

void print_food_tea(const Person& p) {
    printf("tea: %lld\n", (RUB)p.food.tea);
}

void print_food_coffee(const Person& p) {
    printf("coffee: %lld\n", (RUB)p.food.coffee);
}

void print_food_sweets(const Person& p) {
    printf("sweets: %lld\n", (RUB)p.food.sweets);
}

void print_food_oil(const Person& p) {
    printf("oil: %lld\n", (RUB)p.food.oil);
}

void print_food_salt(const Person& p) {
    printf("salt: %lld\n", (RUB)p.food.salt);
}

void print_food_sugar(const Person& p) {
    printf("sugar: %lld\n", (RUB)p.food.sugar);
}

void print_food_water(const Person& p) {
    printf("water: %lld\n", (RUB)p.food.water);
}

void print_utility_electricity(const Person& p) {
    printf("electricity: %lld\n", (RUB)p.utility.electricity);
}

void print_utility_cold_water(const Person& p) {
    printf("cold water: %lld\n", (RUB)p.utility.cold_water);
}

void print_utility_hot_water(const Person& p) {
    printf("hot water: %lld\n", (RUB)p.utility.hot_water);
}

void print_utility_heating(const Person& p) {
    printf("heating: %lld\n", (RUB)p.utility.heating);
}

void print_utility_gas(const Person& p) {
    printf("gas: %lld\n", (RUB)p.utility.gas);
}

void print_utility_internet(const Person& p) {
    printf("internet: %lld\n", (RUB)p.utility.internet);
}

void print_utility_mobile(const Person& p) {
    printf("mobile: %lld\n", (RUB)p.utility.mobile);
}

void print_utility_cleaning(const Person& p) {
    printf("cleaning: %lld\n", (RUB)p.utility.cleaning);
}

void print_utility_repair(const Person& p) {
    printf("repair: %lld\n", (RUB)p.utility.repair);
}

void print_utility_elevator(const Person& p) {
    printf("elevator: %lld\n", (RUB)p.utility.elevator);
}

void print_utility_security(const Person& p) {
    printf("security: %lld\n", (RUB)p.utility.security);
}

void print_utility_garbage(const Person& p) {
    printf("garbage: %lld\n", (RUB)p.utility.garbage);
}

void print_home_owned(const Person& p) {
    printf("owned: %lld\n", (RUB)p.home.owned);
}

void print_home_rent(const Person& p) {
    printf("rent: %lld\n", (RUB)p.home.rent);
}

void print_home_house_value(const Person& p) {
    printf("house value: %lld\n", (RUB)p.home.house_value);
}

void print_home_furniture(const Person& p) {
    printf("furniture: %lld\n", (RUB)p.home.furniture);
}

void print_home_appliances(const Person& p) {
    printf("appliances: %lld\n", (RUB)p.home.appliances);
}

void print_home_small_repair(const Person& p) {
    printf("small repair: %lld\n", (RUB)p.home.small_repair);
}

void print_home_home_insurance(const Person& p) {
    printf("home insurance: %lld\n", (RUB)p.home.home_insurance);
}

void print_pet_alive(const Person& p) {
    printf("alive: %lld\n", (RUB)p.pet.alive);
}

void print_pet_death_month(const Person& p) {
    printf("death month: %lld\n", (RUB)p.pet.death_month);
}

void print_pet_death_year(const Person& p) {
    printf("death year: %lld\n", (RUB)p.pet.death_year);
}

void print_pet_food(const Person& p) {
    printf("food: %lld\n", (RUB)p.pet.food);
}

void print_pet_vet(const Person& p) {
    printf("vet: %lld\n", (RUB)p.pet.vet);
}

void print_pet_medicine(const Person& p) {
    printf("medicine: %lld\n", (RUB)p.pet.medicine);
}

void print_pet_toys(const Person& p) {
    printf("toys: %lld\n", (RUB)p.pet.toys);
}

void print_pet_grooming(const Person& p) {
    printf("grooming: %lld\n", (RUB)p.pet.grooming);
}

void print_pet_accessories(const Person& p) {
    printf("accessories: %lld\n", (RUB)p.pet.accessories);
}

void print_car_has_car(const Person& p) {
    printf("has car: %lld\n", (RUB)p.car.has_car);
}

void print_car_value(const Person& p) {
    printf("value: %lld\n", (RUB)p.car.value);
}

void print_car_fuel(const Person& p) {
    printf("fuel: %lld\n", (RUB)p.car.fuel);
}

void print_car_insurance(const Person& p) {
    printf("insurance: %lld\n", (RUB)p.car.insurance);
}

void print_car_service(const Person& p) {
    printf("service: %lld\n", (RUB)p.car.service);
}

void print_car_repair(const Person& p) {
    printf("repair: %lld\n", (RUB)p.car.repair);
}

void print_car_parking(const Person& p) {
    printf("parking: %lld\n", (RUB)p.car.parking);
}

void print_car_tax(const Person& p) {
    printf("tax: %lld\n", (RUB)p.car.tax);
}

void print_car_washing(const Person& p) {
    printf("washing: %lld\n", (RUB)p.car.washing);
}

void print_car_tires(const Person& p) {
    printf("tires: %lld\n", (RUB)p.car.tires);
}

void print_car_fines(const Person& p) {
    printf("fines: %lld\n", (RUB)p.car.fines);
}

void print_family_married(const Person& p) {
    printf("married: %lld\n", (RUB)p.family.married);
}

void print_family_kids(const Person& p) {
    printf("kids: %lld\n", (RUB)p.family.kids);
}

void print_family_kids_food(const Person& p) {
    printf("kids food: %lld\n", (RUB)p.family.kids_food);
}

void print_family_school(const Person& p) {
    printf("school: %lld\n", (RUB)p.family.school);
}

void print_family_kindergarten(const Person& p) {
    printf("kindergarten: %lld\n", (RUB)p.family.kindergarten);
}

void print_family_clothes(const Person& p) {
    printf("clothes: %lld\n", (RUB)p.family.clothes);
}

void print_family_medicine(const Person& p) {
    printf("medicine: %lld\n", (RUB)p.family.medicine);
}

void print_family_activities(const Person& p) {
    printf("activities: %lld\n", (RUB)p.family.activities);
}

void print_family_gifts(const Person& p) {
    printf("gifts: %lld\n", (RUB)p.family.gifts);
}

void print_health_hp(const Person& p) {
    printf("hp: %lld\n", (RUB)p.health.hp);
}

void print_health_doctor(const Person& p) {
    printf("doctor: %lld\n", (RUB)p.health.doctor);
}

void print_health_medicine(const Person& p) {
    printf("medicine: %lld\n", (RUB)p.health.medicine);
}

void print_health_sport(const Person& p) {
    printf("sport: %lld\n", (RUB)p.health.sport);
}

void print_health_dentist(const Person& p) {
    printf("dentist: %lld\n", (RUB)p.health.dentist);
}

void print_health_checkup(const Person& p) {
    printf("checkup: %lld\n", (RUB)p.health.checkup);
}

void print_health_emergency(const Person& p) {
    printf("emergency: %lld\n", (RUB)p.health.emergency);
}

void print_other_clothes(const Person& p) {
    printf("clothes: %lld\n", (RUB)p.other.clothes);
}

void print_other_leisure(const Person& p) {
    printf("leisure: %lld\n", (RUB)p.other.leisure);
}

void print_other_subscriptions(const Person& p) {
    printf("subscriptions: %lld\n", (RUB)p.other.subscriptions);
}

void print_other_hobbies(const Person& p) {
    printf("hobbies: %lld\n", (RUB)p.other.hobbies);
}

void print_other_gifts(const Person& p) {
    printf("gifts: %lld\n", (RUB)p.other.gifts);
}

void print_other_trips(const Person& p) {
    printf("trips: %lld\n", (RUB)p.other.trips);
}

void print_other_personal_care(const Person& p) {
    printf("personal care: %lld\n", (RUB)p.other.personal_care);
}

void print_other_education(const Person& p) {
    printf("education: %lld\n", (RUB)p.other.education);
}

void print_bank_account(const Person& p) {
    printf("account: %lld\n", (RUB)p.bank.account);
}

void print_bank_deposit(const Person& p) {
    printf("deposit: %lld\n", (RUB)p.bank.deposit);
}

void print_bank_mortgage(const Person& p) {
    printf("mortgage: %lld\n", (RUB)p.bank.mortgage);
}

void print_bank_car_loan(const Person& p) {
    printf("car loan: %lld\n", (RUB)p.bank.car_loan);
}

void print_bank_consumer_loan(const Person& p) {
    printf("consumer loan: %lld\n", (RUB)p.bank.consumer_loan);
}

void print_bank_mortgage_payment(const Person& p) {
    printf("mortgage payment: %lld\n", (RUB)p.bank.mortgage_payment);
}

void print_bank_car_loan_payment(const Person& p) {
    printf("car loan payment: %lld\n", (RUB)p.bank.car_loan_payment);
}

void print_bank_consumer_loan_payment(const Person& p) {
    printf("consumer loan payment: %lld\n", (RUB)p.bank.consumer_loan_payment);
}

void print_work_salary(const Person& p) {
    printf("salary: %lld\n", (RUB)p.work.salary);
}

void print_work_bonus(const Person& p) {
    printf("bonus: %lld\n", (RUB)p.work.bonus);
}

void print_work_taxi_orders(const Person& p) {
    printf("taxi orders: %lld\n", (RUB)p.work.taxi_orders);
}

void print_work_taxi_expenses(const Person& p) {
    printf("taxi expenses: %lld\n", (RUB)p.work.taxi_expenses);
}

void print_work_taxi_job(const Person& p) {
    printf("taxi job: %lld\n", (RUB)p.work.taxi_job);
}

void print_food_details(const Person& p) {
    printf("food details\n");
    print_food_bread(p);
    print_food_milk(p);
    print_food_eggs(p);
    print_food_beef(p);
    print_food_chicken(p);
    print_food_fish(p);
    print_food_cheese(p);
    print_food_yogurt(p);
    print_food_rice(p);
    print_food_pasta(p);
    print_food_potatoes(p);
    print_food_vegetables(p);
    print_food_fruits(p);
    print_food_tea(p);
    print_food_coffee(p);
    print_food_sweets(p);
    print_food_oil(p);
    print_food_salt(p);
    print_food_sugar(p);
    print_food_water(p);
}

void print_utility_details(const Person& p) {
    printf("utility details\n");
    print_utility_electricity(p);
    print_utility_cold_water(p);
    print_utility_hot_water(p);
    print_utility_heating(p);
    print_utility_gas(p);
    print_utility_internet(p);
    print_utility_mobile(p);
    print_utility_cleaning(p);
    print_utility_repair(p);
    print_utility_elevator(p);
    print_utility_security(p);
    print_utility_garbage(p);
}

void print_home_details(const Person& p) {
    printf("home details\n");
    print_home_owned(p);
    print_home_rent(p);
    print_home_house_value(p);
    print_home_furniture(p);
    print_home_appliances(p);
    print_home_small_repair(p);
    print_home_home_insurance(p);
}

void print_pet_details(const Person& p) {
    printf("pet details\n");
    print_pet_alive(p);
    print_pet_death_month(p);
    print_pet_death_year(p);
    print_pet_food(p);
    print_pet_vet(p);
    print_pet_medicine(p);
    print_pet_toys(p);
    print_pet_grooming(p);
    print_pet_accessories(p);
}

void print_car_details(const Person& p) {
    printf("car details\n");
    print_car_has_car(p);
    print_car_value(p);
    print_car_fuel(p);
    print_car_insurance(p);
    print_car_service(p);
    print_car_repair(p);
    print_car_parking(p);
    print_car_tax(p);
    print_car_washing(p);
    print_car_tires(p);
    print_car_fines(p);
}

void print_family_details(const Person& p) {
    printf("family details\n");
    print_family_married(p);
    print_family_kids(p);
    print_family_kids_food(p);
    print_family_school(p);
    print_family_kindergarten(p);
    print_family_clothes(p);
    print_family_medicine(p);
    print_family_activities(p);
    print_family_gifts(p);
}

void print_health_details(const Person& p) {
    printf("health details\n");
    print_health_hp(p);
    print_health_doctor(p);
    print_health_medicine(p);
    print_health_sport(p);
    print_health_dentist(p);
    print_health_checkup(p);
    print_health_emergency(p);
}

void print_other_details(const Person& p) {
    printf("other details\n");
    print_other_clothes(p);
    print_other_leisure(p);
    print_other_subscriptions(p);
    print_other_hobbies(p);
    print_other_gifts(p);
    print_other_trips(p);
    print_other_personal_care(p);
    print_other_education(p);
}


void print_bank_details(const Person& p) {
    printf("bank details\n");
    print_bank_account(p);
    print_bank_deposit(p);
    print_bank_mortgage(p);
    print_bank_car_loan(p);
    print_bank_consumer_loan(p);
    print_bank_mortgage_payment(p);
    print_bank_car_loan_payment(p);
    print_bank_consumer_loan_payment(p);
    printf("mortgage rate: %.2f\n", p.bank.mortgage_rate);
    printf("car loan rate: %.2f\n", p.bank.car_loan_rate);
    printf("consumer loan rate: %.2f\n", p.bank.consumer_loan_rate);
}


void print_work_details(const Person& p) {
    printf("work details\n");
    print_work_salary(p);
    print_work_bonus(p);
    print_work_taxi_orders(p);
    print_work_taxi_expenses(p);
    print_work_taxi_job(p);
}


void print_detailed_person(const Person& p) {
    print_food_details(p);
    print_utility_details(p);
    print_home_details(p);
    print_pet_details(p);
    print_car_details(p);
    print_family_details(p);
    print_health_details(p);
    print_other_details(p);
    print_bank_details(p);
    print_work_details(p);
    print_expense_shares(p);
    print_debt_analysis(p);
    print_current_money_plan(p);
    print_credit_payoff_plan(p);
    print_simple_risks(p);
}

void print_person(const Person& p) {
    printf("\n");
    print_person_main(p);
    print_person_expenses(p);
    print_person_credits(p);
    print_person_history(p);
    print_detailed_person(p);
}


void print_capital_difference(const Person& a, const Person& b) {
    printf("capital difference: %lld\n", capital(a) - capital(b));
}

void print_debt_difference(const Person& a, const Person& b) {
    printf("debt difference: %lld\n", total_debt(a) - total_debt(b));
}

void print_deposit_difference(const Person& a, const Person& b) {
    printf("deposit difference: %lld\n", a.bank.deposit - b.bank.deposit);
}

void print_health_difference(const Person& a, const Person& b) {
    printf("health difference: %d\n", a.health.hp - b.health.hp);
}

void print_score_difference(const Person& a, const Person& b) {
    printf("score difference: %d\n", score(a) - score(b));
}

void print_comparison_numbers(const Person& a, const Person& b) {
    print_capital_difference(a, b);
    print_debt_difference(a, b);
    print_deposit_difference(a, b);
    print_health_difference(a, b);
    print_score_difference(a, b);
}

void print_comparison(const Person& a, const Person& b) {
    printf("\ncomparison\n");
    if (capital(a) > capital(b)) {
        printf("better capital: %s\n", a.name);
    } else {
        printf("better capital: %s\n", b.name);
    }
    print_comparison_numbers(a, b);
    if (score(a) > score(b)) {
        printf("better score: %s\n", a.name);
    } else if (score(a) < score(b)) {
        printf("better score: %s\n", b.name);
    } else {
        printf("scores are equal\n");
    }
}


void print_income_requirement() {
    printf("income: salary and deposit interest\n");
}

void print_expense_requirement() {
    printf("expenses: food, utility, home, pet, car, family, health, other\n");
}

void print_time_requirement() {
    printf("time: about ten years, monthly step\n");
}

void print_credit_requirement() {
    printf("credit model: mortgage, car loan, consumer loan\n");
}

void print_output_requirement() {
    printf("output: final capital, debt, score and comparison\n");
}

void print_task_check(const Person& a, const Person& b) {
    printf("\ntask check\n");
    printf("simulation step: month\n");
    printf("period: 02.2026 - 03.2036\n");
    printf("detailed topic: several credits\n");
    print_credit_explanation();
    print_model_explanation();
    print_income_requirement();
    print_expense_requirement();
    print_time_requirement();
    print_credit_requirement();
    print_output_requirement();
    printf("food, utility, mortgage, rent, pet and car are included\n");
    printf("different inflation is used for different groups\n");
    printf("%s history months: %d\n", a.name, a.history_count);
    printf("%s history months: %d\n", b.name, b.history_count);
    printf("%s mortgage left: %lld\n", a.name, a.bank.mortgage);
    printf("%s mortgage left: %lld\n", b.name, b.bank.mortgage);
}

void print_model_constants() {
    printf("model constants\n");
    printf("deposit rate: %.2f\n", DEPOSIT_RATE);
    printf("food inflation: %.3f\n", FOOD_INFLATION);
    printf("utility inflation: %.3f\n", UTILITY_INFLATION);
    printf("home inflation: %.3f\n", HOME_INFLATION);
    printf("pet inflation: %.3f\n", PET_INFLATION);
    printf("car inflation: %.3f\n", CAR_INFLATION);
    printf("health inflation: %.3f\n", HEALTH_INFLATION);
    printf("other inflation: %.3f\n", OTHER_INFLATION);
}


void print_inflation_settings() {
    printf("inflation settings\n");
    printf("food inflation: %.3f\n", FOOD_INFLATION);
    printf("utility inflation: %.3f\n", UTILITY_INFLATION);
    printf("home inflation: %.3f\n", HOME_INFLATION);
    printf("pet inflation: %.3f\n", PET_INFLATION);
    printf("car inflation: %.3f\n", CAR_INFLATION);
    printf("health inflation: %.3f\n", HEALTH_INFLATION);
    printf("other inflation: %.3f\n", OTHER_INFLATION);
}

void print_simulation_settings() {
    printf("simulation settings\n");
    printf("start: %02d.%04d\n", START_MONTH, START_YEAR);
    printf("end: %02d.%04d\n", END_MONTH, END_YEAR);
    printf("history size: %d\n", HISTORY_SIZE);
    printf("deposit rate: %.2f\n", DEPOSIT_RATE);
    print_inflation_settings();
}


void print_all(const Person& a, const Person& b) {
    printf("financial life simulator\n");
    print_simulation_settings();
    print_model_constants();
    print_person(a);
    print_person(b);
    print_comparison(a, b);
    print_task_check(a, b);
}

int main() {
    simulate(Dilshot, Analbek);
    print_all(Dilshot, Analbek);
    return 0;
}
