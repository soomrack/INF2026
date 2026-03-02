#include <stdio.h>
#include <math.h>

using RUB = long long int;
using Percent = float;


struct Food {
    RUB bread, dairy, meat, chicken, fish;
    RUB vegetables, fruits, cereals, drinks, snacks;
    RUB eggs, oil, condiments, tea_coffee;
};

struct Hobby {
    RUB monthly_fee;
    RUB gear_yearly;
};

struct MarchExpenses {
    RUB gifts, flowers, restaurant;
};

struct SummerVacation {
    RUB tickets, hotel, excursions, souvenirs, food_extra;
};

struct Hamster {
    struct { RUB cage, wheel, drinker, vaccination; } one_time;
    struct { RUB feed, bedding, vet_checkup; } month;
    struct { RUB treats, accessories; } spontaneous;
};

struct Parrot {
    struct { RUB cage, perch, carrier, vet_initial; } one_time;
    struct { RUB feed, vitamins, vet; } month;
    struct { RUB toys, minerals; } spontaneous;
};

struct Bicycle {
    struct { RUB value, helmet, lock; } one_time;
    struct { RUB maintenance; } month;
    struct { RUB tire_change; } year_expense;
};

struct Scooter {
    struct { RUB value, insurance; } one_time;
    struct { RUB charging, maintenance; } month;
    struct { RUB electricity; } week;
};

struct Bank {
    RUB bank_account;
    RUB deposit;
    Percent rate;
};

struct StudentLoan {
    RUB monthly_payment;
    int months_left;
    RUB total_paid;
};

struct Person {
    RUB salary;
    Food food;
    RUB rent, communal, mobile, net;
    RUB clothes, public_transport, fitness, hairdo;
    RUB streaming, medicine;
    Hobby hobby;
    MarchExpenses march_holiday;
    SummerVacation vacation;
};


Person Diana, Oleg;
Hamster Barsik;
Parrot Kesha;
Bicycle Trek;
Scooter Xiaomi;
Bank DianaBank, OlegBank;
StudentLoan OlegLoan;


// утилиты для работы с однородными структурами из RUB

void spend(RUB &account, void *s, int n) {
    RUB *p = (RUB*)s;
    for (int i = 0; i < n; i++) account -= p[i];
}

void inflate(void *s, int n, float k) {
    RUB *p = (RUB*)s;
    for (int i = 0; i < n; i++) p[i] = (RUB)(p[i] * k);
}

#define SPEND(acc, s)    spend(acc, &(s), sizeof(s)/sizeof(RUB))
#define INFLATE(s, k)    inflate(&(s), sizeof(s)/sizeof(RUB), k)


void diana_salary(int month, int year) {
    if (month == 5  && year == 2027) Diana.salary = (RUB)(Diana.salary * 1.20);
    if (month == 11 && year == 2029) Diana.salary = (RUB)(Diana.salary * 1.15);
    DianaBank.bank_account += Diana.salary;
}

void diana_food(float k) {
    SPEND(DianaBank.bank_account, Diana.food);
    INFLATE(Diana.food, k);
}

void diana_living(float k, int month) {
    DianaBank.bank_account -= Diana.net + Diana.mobile + Diana.fitness +
        Diana.streaming + Diana.communal + Diana.hobby.monthly_fee + Diana.medicine;

    if (month == 3 || month == 6 || month == 9 || month == 12)
        DianaBank.bank_account -= Diana.clothes;
    if (month % 2 == 1)
        DianaBank.bank_account -= Diana.hairdo;
    if (month == 10)
        DianaBank.bank_account -= Diana.hobby.gear_yearly;

    Diana.clothes = (RUB)(Diana.clothes * k);
    Diana.net = (RUB)(Diana.net * k);
    Diana.mobile = (RUB)(Diana.mobile * k);
    Diana.fitness = (RUB)(Diana.fitness * k);
    Diana.hairdo = (RUB)(Diana.hairdo * k);
    Diana.communal = (RUB)(Diana.communal * k);
    Diana.streaming = (RUB)(Diana.streaming * k);
    Diana.medicine = (RUB)(Diana.medicine * k);
    INFLATE(Diana.hobby, k);
}

void diana_bicycle(float k, int month, int year) {
    if (month >= 4 && month <= 9)
        DianaBank.bank_account -= Trek.month.maintenance;
    if (month == 4)
        DianaBank.bank_account -= Trek.year_expense.tire_change;
    if (month == 5 && year == 2028)
        DianaBank.bank_account -= Trek.one_time.helmet;
    if (month == 6 && year % 4 == 0)
        DianaBank.bank_account -= Trek.one_time.lock;
    if (month < 4 || month > 9)
        DianaBank.bank_account -= Diana.public_transport;

    INFLATE(Trek.one_time, k);
    Trek.month.maintenance = (RUB)(Trek.month.maintenance * k);
    Trek.year_expense.tire_change = (RUB)(Trek.year_expense.tire_change * k);
    Diana.public_transport = (RUB)(Diana.public_transport * k);
}

void diana_pet(float k, int month, int year) {
    SPEND(DianaBank.bank_account, Barsik.month);

    if (month == 2)
        DianaBank.bank_account -= Barsik.one_time.vaccination;
    if (month == 7 && year % 2 == 0)
        DianaBank.bank_account -= Barsik.one_time.wheel;
    if (month == 4 && year % 3 == 0)
        DianaBank.bank_account -= Barsik.one_time.drinker;
    if (month == 10 && year % 3 == 0)
        DianaBank.bank_account -= Barsik.one_time.cage;
    if (month % 3 == 0)
        SPEND(DianaBank.bank_account, Barsik.spontaneous);

    INFLATE(Barsik.one_time, k);
    INFLATE(Barsik.month, k);
    INFLATE(Barsik.spontaneous, k);
}

void diana_deposit_interest() {
    DianaBank.deposit += (RUB)((float)DianaBank.deposit * DianaBank.rate / 1200.0f);
}

void diana_march_holiday(int month, float k) {
    if (month == 3) {
        SPEND(DianaBank.bank_account, Diana.march_holiday);
        INFLATE(Diana.march_holiday, k);
    }
}

void diana_vacation(int month, float k) {
    if (month == 7) {
        SPEND(DianaBank.bank_account, Diana.vacation);
        INFLATE(Diana.vacation, k);
    }
}


void oleg_salary(int month, int year) {
    if (month == 9 && year == 2027) Oleg.salary = (RUB)(Oleg.salary * 1.30);
    if (month == 2 && year == 2030) Oleg.salary = (RUB)(Oleg.salary * 1.10);
    OlegBank.bank_account += Oleg.salary;
}

void oleg_food(float k) {
    SPEND(OlegBank.bank_account, Oleg.food);
    INFLATE(Oleg.food, k);
}

void oleg_living(float k, int month) {
    OlegBank.bank_account -= Oleg.net + Oleg.mobile + Oleg.fitness +
        Oleg.streaming + Oleg.rent + Oleg.communal + Oleg.medicine +
        Oleg.hobby.monthly_fee;

    if (month == 2 || month == 5 || month == 8 || month == 11)
        OlegBank.bank_account -= Oleg.clothes;
    if (month % 2 == 0)
        OlegBank.bank_account -= Oleg.hairdo;
    if (month == 3)
        OlegBank.bank_account -= Oleg.hobby.gear_yearly;

    Oleg.clothes = (RUB)(Oleg.clothes * k);
    Oleg.net = (RUB)(Oleg.net * k);
    Oleg.mobile = (RUB)(Oleg.mobile * k);
    Oleg.fitness = (RUB)(Oleg.fitness * k);
    Oleg.hairdo = (RUB)(Oleg.hairdo * k);
    Oleg.rent = (RUB)(Oleg.rent * k);
    Oleg.communal = (RUB)(Oleg.communal * k);
    Oleg.streaming = (RUB)(Oleg.streaming * k);
    Oleg.medicine = (RUB)(Oleg.medicine * k);
    INFLATE(Oleg.hobby, k);
}

void oleg_scooter(float k, int month, int year) {
    if (month >= 5 && month <= 10) {
        OlegBank.bank_account -= Xiaomi.month.charging + Xiaomi.month.maintenance;
        OlegBank.bank_account -= 4 * Xiaomi.week.electricity;
    }
    if (month == 5)
        OlegBank.bank_account -= Xiaomi.one_time.insurance;
    if (month < 5 || month > 10)
        OlegBank.bank_account -= Oleg.public_transport;

    Xiaomi.one_time.insurance = (RUB)(Xiaomi.one_time.insurance * k);
    INFLATE(Xiaomi.month, k);
    Xiaomi.week.electricity = (RUB)(Xiaomi.week.electricity * k);
    Oleg.public_transport = (RUB)(Oleg.public_transport * k);
}

void oleg_pet(float k, int month, int year) {
    SPEND(OlegBank.bank_account, Kesha.month);

    if (month == 5)
        OlegBank.bank_account -= Kesha.one_time.vet_initial;
    if (month == 3 && year % 2 == 0)
        OlegBank.bank_account -= Kesha.one_time.perch;
    if (month == 9 && year % 3 == 0)
        OlegBank.bank_account -= Kesha.one_time.carrier;
    if (month == 1 && year % 4 == 0)
        OlegBank.bank_account -= Kesha.one_time.cage;
    if (month % 4 == 0)
        SPEND(OlegBank.bank_account, Kesha.spontaneous);

    INFLATE(Kesha.one_time, k);
    INFLATE(Kesha.month, k);
    INFLATE(Kesha.spontaneous, k);
}

void oleg_student_loan() {
    if (OlegLoan.months_left > 0) {
        OlegBank.bank_account -= OlegLoan.monthly_payment;
        OlegLoan.total_paid += OlegLoan.monthly_payment;
        OlegLoan.months_left--;
    }
}

void oleg_deposit_interest() {
    OlegBank.deposit += (RUB)((float)OlegBank.deposit * OlegBank.rate / 1200.0f);
}

void oleg_march_holiday(int month, float k) {
    if (month == 2) {
        SPEND(OlegBank.bank_account, Oleg.march_holiday);
        INFLATE(Oleg.march_holiday, k);
    }
}

void oleg_vacation(int month, float k) {
    if (month == 8) {
        SPEND(OlegBank.bank_account, Oleg.vacation);
        INFLATE(Oleg.vacation, k);
    }
}


void diana_init() {
    Diana.salary = 410000;
    Diana.net = 700;  Diana.mobile = 400;  Diana.clothes = 20000;
    Diana.hairdo = 2800;  Diana.fitness = 3500;  Diana.streaming = 900;
    Diana.rent = 0;  Diana.communal = 7500;
    Diana.public_transport = 3200;  Diana.medicine = 1500;
    Diana.hobby = {4000, 12000};

    Diana.food = {300, 900, 1200, 600, 1500, 700, 500, 200, 400, 350, 200, 150, 100, 400};

    DianaBank = {800000, 2500000, 15.0};

    Trek.one_time = {80000, 5000, 2000};
    Trek.month.maintenance = 1000;
    Trek.year_expense.tire_change = 3000;

    Barsik.one_time = {4000, 1500, 500, 2000};
    Barsik.month = {800, 400, 300};
    Barsik.spontaneous = {300, 400};

    Diana.march_holiday = {8000, 3000, 5000};
    Diana.vacation = {35000, 40000, 10000, 5000, 15000};
}

void oleg_init() {
    Oleg.salary = 350000;
    Oleg.net = 650;  Oleg.mobile = 500;  Oleg.clothes = 12000;
    Oleg.hairdo = 1200;  Oleg.fitness = 4500;  Oleg.streaming = 1100;
    Oleg.rent = 40000;  Oleg.communal = 5500;
    Oleg.public_transport = 2800;  Oleg.medicine = 1000;
    Oleg.hobby = {3500, 8000};

    Oleg.food = {250, 700, 1400, 700, 600, 500, 400, 300, 600, 500, 250, 100, 150, 500};

    OlegBank = {400000, 1200000, 12.5};
    OlegLoan = {25000, 36, 0};

    Xiaomi.one_time = {60000, 5000};
    Xiaomi.month = {500, 1000};
    Xiaomi.week.electricity = 200;

    Kesha.one_time = {8000, 1000, 2000, 3000};
    Kesha.month = {1500, 500, 600};
    Kesha.spontaneous = {400, 300};

    Oleg.march_holiday = {6000, 4000, 7000};
    Oleg.vacation = {25000, 30000, 8000, 3000, 12000};
}


void simulation() {
    int month = 3, year = 2026;
    float inf = 6.2f;

    while (!(month == 3 && year == 2031)) {
        float k = 1.0f + inf / 100.0f;

        diana_salary(month, year);
        diana_food(k);
        diana_bicycle(k, month, year);
        diana_pet(k, month, year);
        diana_living(k, month);
        diana_deposit_interest();
        diana_march_holiday(month, k);
        diana_vacation(month, k);

        oleg_salary(month, year);
        oleg_food(k);
        oleg_scooter(k, month, year);
        oleg_pet(k, month, year);
        oleg_living(k, month);
        oleg_student_loan();
        oleg_deposit_interest();
        oleg_march_holiday(month, k);
        oleg_vacation(month, k);

        if (++month == 13) { month = 1; year++; }
    }
}


void print_results() {
    RUB diana_total = DianaBank.bank_account + DianaBank.deposit;
    RUB oleg_total  = OlegBank.bank_account  + OlegBank.deposit;

    printf("========================================\n");
    printf("  ИТОГИ СИМУЛЯЦИИ (5 лет)\n");
    printf("========================================\n\n");

    printf("--- DIANA ---\n");
    printf("Зарплата:      %lld\nСчёт:          %lld\nВклад:         %lld\nИтого:         %lld\n",
           Diana.salary, DianaBank.bank_account, DianaBank.deposit, diana_total);
    if (DianaBank.bank_account < 0) printf(">>> Диана в минусе! <<<\n");

    printf("\n--- OLEG ---\n");
    printf("Зарплата:      %lld\nСчёт:          %lld\nВклад:         %lld\nИтого:         %lld\n",
           Oleg.salary, OlegBank.bank_account, OlegBank.deposit, oleg_total);
    printf("Кредит выплачено: %lld, осталось: %d мес.\n", OlegLoan.total_paid, OlegLoan.months_left);
    if (OlegBank.bank_account < 0) printf(">>> Олег в минусе! <<<\n");

    printf("\n========================================\n");
    if (diana_total > oleg_total)
        printf("Диана накопила больше на %lld\n", diana_total - oleg_total);
    else if (oleg_total > diana_total)
        printf("Олег накопил больше на %lld\n", oleg_total - diana_total);
    else
        printf("Накопили одинаково!\n");
    printf("========================================\n");
}


int main() {
    diana_init();
    oleg_init();
    simulation();
    print_results();
    return 0;
}