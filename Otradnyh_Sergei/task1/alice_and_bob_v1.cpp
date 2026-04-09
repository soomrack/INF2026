#include <iostream>
#include <cmath>
#include <cstring>

using RUB = long long int;


// ==================== СТРУКТУРЫ ====================

struct Food {
    RUB meat;
    RUB bread;
    RUB sauces;
    RUB vegetables;
    RUB dairy;
    RUB fruits;
    RUB drinks;
    RUB snacks;
};

struct Transport {
    RUB metro;
    RUB bus;
    RUB taxi;
    RUB fuel;
};

struct Healthcare {
    RUB insurance;
    RUB medicine;
    RUB dentist;
};

struct Entertainment {
    RUB cinema;
    RUB subscriptions;
    RUB hobbies;
    RUB restaurants;
};

struct Clothing {
    RUB winter_clothes;
    RUB summer_clothes;
    RUB shoes;
    RUB accessories;
};

struct Education {
    RUB courses;
    RUB books;
    RUB software;
};

struct Rent {
    RUB price;
    RUB light;
    RUB water;
    RUB electricity;
    RUB gas;
    RUB maintenance;
};

struct Mortgage {
    RUB total_debt;
    RUB monthly_payment;
    float rate;
    int months_left;
};

struct Credit {
    RUB total_debt;
    RUB monthly_payment;
    float rate;
    int months_left;
};

struct Bank {
    RUB bank_account;
    RUB deposit;          // вклад (снять нельзя)
    float percent;
    RUB savings_account;  // накопительный (снять можно)
    float savings_percent;
};

struct Person {
    char name[64];
    RUB salary;
    RUB bonus;
    RUB internet;
    RUB phone;
    Food food;
    Transport transport;
    Rent rent;
    Healthcare health;
    Entertainment entertainment;
    Clothing clothing;
    Education education;
    Mortgage mortgage;
    Credit credit;
};


// ==================== ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ ====================

struct Bank Tinkoff;
struct Bank Sber;

struct Person Alice;
struct Person Bob;


// ==================== ИНИЦИАЛИЗАЦИЯ ALICE ====================

void Alice_init() {
    strcpy(Alice.name, "Alice");
    Alice.salary = 80000;
    Alice.bonus = 0;

    Alice.food.meat = 2000;
    Alice.food.sauces = 1000;
    Alice.food.bread = 300;
    Alice.food.vegetables = 500;
    Alice.food.dairy = 800;
    Alice.food.fruits = 600;
    Alice.food.drinks = 400;
    Alice.food.snacks = 300;

    Alice.transport.metro = 3000;
    Alice.transport.bus = 0;
    Alice.transport.taxi = 1500;
    Alice.transport.fuel = 0;

    Alice.rent.price = 25000;
    Alice.rent.light = 800;
    Alice.rent.water = 500;
    Alice.rent.electricity = 1200;
    Alice.rent.gas = 400;
    Alice.rent.maintenance = 600;

    Alice.health.insurance = 0;
    Alice.health.medicine = 500;
    Alice.health.dentist = 0;

    Alice.entertainment.cinema = 1000;
    Alice.entertainment.subscriptions = 700;
    Alice.entertainment.hobbies = 1500;
    Alice.entertainment.restaurants = 2000;

    Alice.clothing.winter_clothes = 0;
    Alice.clothing.summer_clothes = 0;
    Alice.clothing.shoes = 0;
    Alice.clothing.accessories = 0;

    Alice.education.courses = 2000;
    Alice.education.books = 500;
    Alice.education.software = 300;

    Alice.internet = 600;
    Alice.phone = 500;

    Alice.mortgage.total_debt = 0;
    Alice.mortgage.monthly_payment = 0;
    Alice.mortgage.rate = 0;
    Alice.mortgage.months_left = 0;

    Alice.credit.total_debt = 0;
    Alice.credit.monthly_payment = 0;
    Alice.credit.rate = 0;
    Alice.credit.months_left = 0;

    Tinkoff.bank_account = 200000;
    Tinkoff.deposit = 500000;
    Tinkoff.percent = 14.0;
    Tinkoff.savings_account = 100000;
    Tinkoff.savings_percent = 10.0;
}


// ==================== ИНИЦИАЛИЗАЦИЯ BOB ====================

void Bob_init() {
    strcpy(Bob.name, "Bob");
    Bob.salary = 120000;
    Bob.bonus = 0;

    Bob.food.meat = 3000;
    Bob.food.sauces = 800;
    Bob.food.bread = 400;
    Bob.food.vegetables = 700;
    Bob.food.dairy = 600;
    Bob.food.fruits = 500;
    Bob.food.drinks = 800;
    Bob.food.snacks = 500;

    Bob.transport.metro = 0;
    Bob.transport.bus = 0;
    Bob.transport.taxi = 2000;
    Bob.transport.fuel = 5000;

    Bob.rent.price = 0; // своя квартира, аренда не платится
    Bob.rent.light = 1000;
    Bob.rent.water = 600;
    Bob.rent.electricity = 1500;
    Bob.rent.gas = 500;
    Bob.rent.maintenance = 1200;

    Bob.health.insurance = 3000;
    Bob.health.medicine = 300;
    Bob.health.dentist = 0;

    Bob.entertainment.cinema = 500;
    Bob.entertainment.subscriptions = 1200;
    Bob.entertainment.hobbies = 3000;
    Bob.entertainment.restaurants = 4000;

    Bob.clothing.winter_clothes = 0;
    Bob.clothing.summer_clothes = 0;
    Bob.clothing.shoes = 0;
    Bob.clothing.accessories = 0;

    Bob.education.courses = 5000;
    Bob.education.books = 1000;
    Bob.education.software = 800;

    Bob.internet = 900;
    Bob.phone = 800;

    Bob.mortgage.total_debt = 3000000;
    Bob.mortgage.monthly_payment = 35000;
    Bob.mortgage.rate = 12.0;
    Bob.mortgage.months_left = 180;

    Bob.credit.total_debt = 0;
    Bob.credit.monthly_payment = 0;
    Bob.credit.rate = 0;
    Bob.credit.months_left = 0;

    Sber.bank_account = 500000;
    Sber.deposit = 1000000;
    Sber.percent = 12.0;
    Sber.savings_account = 0;
    Sber.savings_percent = 8.0;
}


// ==================== ЗАРПЛАТА ====================

void Alice_salary(const int month, const int year) {
    if ((month == 4) && (year == 2027)) {
        Alice.salary *= 1.4;
    }
    if ((month == 1) && (year == 2029)) {
        Alice.salary *= 1.2;
    }
    if ((month == 7) && (year == 2030)) {
        Alice.salary *= 1.15;
    }

    // годовая премия в декабре
    if (month == 12) {
        Alice.bonus = Alice.salary;
    } else {
        Alice.bonus = 0;
    }

    Tinkoff.bank_account += Alice.salary;
    Tinkoff.bank_account += Alice.bonus;
}


void Bob_salary(const int month, const int year) {
    if ((month == 3) && (year == 2027)) {
        Bob.salary *= 1.3;
    }
    if ((month == 6) && (year == 2028)) {
        Bob.salary *= 1.25;
    }
    if ((month == 1) && (year == 2030)) {
        Bob.salary *= 1.1;
    }

    // квартальная премия 30%
    if (month == 3 || month == 6 || month == 9 || month == 12) {
        Bob.bonus = (RUB)(Bob.salary * 0.3);
    } else {
        Bob.bonus = 0;
    }

    Sber.bank_account += Bob.salary;
    Sber.bank_account += Bob.bonus;
}


// ==================== ЕДА ====================

void Alice_food(float inflation) {
    Tinkoff.bank_account -= Alice.food.bread;
    Tinkoff.bank_account -= Alice.food.meat;
    Tinkoff.bank_account -= Alice.food.vegetables;
    Tinkoff.bank_account -= Alice.food.sauces;
    Tinkoff.bank_account -= Alice.food.dairy;
    Tinkoff.bank_account -= Alice.food.fruits;
    Tinkoff.bank_account -= Alice.food.drinks;
    Tinkoff.bank_account -= Alice.food.snacks;

    float r = inflation / 100.0f / 12.0f; // месячная инфляция

    Alice.food.meat = (RUB)((float)Alice.food.meat * (1.0f + r));
    Alice.food.sauces = (RUB)((float)Alice.food.sauces * (1.0f + r));
    Alice.food.bread = (RUB)((float)Alice.food.bread * (1.0f + r));
    Alice.food.vegetables = (RUB)((float)Alice.food.vegetables * (1.0f + r));
    Alice.food.dairy = (RUB)((float)Alice.food.dairy * (1.0f + r));
    Alice.food.fruits = (RUB)((float)Alice.food.fruits * (1.0f + r));
    Alice.food.drinks = (RUB)((float)Alice.food.drinks * (1.0f + r));
    Alice.food.snacks = (RUB)((float)Alice.food.snacks * (1.0f + r));
}


void Bob_food(float inflation) {
    Sber.bank_account -= Bob.food.bread;
    Sber.bank_account -= Bob.food.meat;
    Sber.bank_account -= Bob.food.vegetables;
    Sber.bank_account -= Bob.food.sauces;
    Sber.bank_account -= Bob.food.dairy;
    Sber.bank_account -= Bob.food.fruits;
    Sber.bank_account -= Bob.food.drinks;
    Sber.bank_account -= Bob.food.snacks;

    float r = inflation / 100.0f / 12.0f;

    Bob.food.meat = (RUB)((float)Bob.food.meat * (1.0f + r));
    Bob.food.sauces = (RUB)((float)Bob.food.sauces * (1.0f + r));
    Bob.food.bread = (RUB)((float)Bob.food.bread * (1.0f + r));
    Bob.food.vegetables = (RUB)((float)Bob.food.vegetables * (1.0f + r));
    Bob.food.dairy = (RUB)((float)Bob.food.dairy * (1.0f + r));
    Bob.food.fruits = (RUB)((float)Bob.food.fruits * (1.0f + r));
    Bob.food.drinks = (RUB)((float)Bob.food.drinks * (1.0f + r));
    Bob.food.snacks = (RUB)((float)Bob.food.snacks * (1.0f + r));
}


// ==================== ТРАНСПОРТ ====================

void Alice_transport(float inflation) {
    Tinkoff.bank_account -= Alice.transport.metro;
    Tinkoff.bank_account -= Alice.transport.bus;
    Tinkoff.bank_account -= Alice.transport.taxi;
    Tinkoff.bank_account -= Alice.transport.fuel;

    float r = inflation / 100.0f / 12.0f;

    Alice.transport.metro = (RUB)((float)Alice.transport.metro * (1.0f + r));
    Alice.transport.bus = (RUB)((float)Alice.transport.bus * (1.0f + r));
    Alice.transport.taxi = (RUB)((float)Alice.transport.taxi * (1.0f + r));
    Alice.transport.fuel = (RUB)((float)Alice.transport.fuel * (1.0f + r));
}


void Bob_transport(float inflation) {
    Sber.bank_account -= Bob.transport.metro;
    Sber.bank_account -= Bob.transport.bus;
    Sber.bank_account -= Bob.transport.taxi;
    Sber.bank_account -= Bob.transport.fuel;

    float r = inflation / 100.0f / 12.0f;

    Bob.transport.metro = (RUB)((float)Bob.transport.metro * (1.0f + r));
    Bob.transport.bus = (RUB)((float)Bob.transport.bus * (1.0f + r));
    Bob.transport.taxi = (RUB)((float)Bob.transport.taxi * (1.0f + r));
    Bob.transport.fuel = (RUB)((float)Bob.transport.fuel * (1.0f + r));
}


// ==================== АРЕНДА / КОММУНАЛКА ====================

void Alice_rent(float inflation) {
    Tinkoff.bank_account -= Alice.rent.price;
    Tinkoff.bank_account -= Alice.rent.light;
    Tinkoff.bank_account -= Alice.rent.water;
    Tinkoff.bank_account -= Alice.rent.electricity;
    Tinkoff.bank_account -= Alice.rent.gas;
    Tinkoff.bank_account -= Alice.rent.maintenance;

    float r = inflation / 100.0f / 12.0f;

    Alice.rent.price = (RUB)((float)Alice.rent.price * (1.0f + r));
    Alice.rent.light = (RUB)((float)Alice.rent.light * (1.0f + r));
    Alice.rent.water = (RUB)((float)Alice.rent.water * (1.0f + r));
    Alice.rent.electricity = (RUB)((float)Alice.rent.electricity * (1.0f + r));
    Alice.rent.gas = (RUB)((float)Alice.rent.gas * (1.0f + r));
    Alice.rent.maintenance = (RUB)((float)Alice.rent.maintenance * (1.0f + r));
}


void Bob_rent(float inflation) {
    Sber.bank_account -= Bob.rent.price;
    Sber.bank_account -= Bob.rent.light;
    Sber.bank_account -= Bob.rent.water;
    Sber.bank_account -= Bob.rent.electricity;
    Sber.bank_account -= Bob.rent.gas;
    Sber.bank_account -= Bob.rent.maintenance;

    float r = inflation / 100.0f / 12.0f;

    Bob.rent.light = (RUB)((float)Bob.rent.light * (1.0f + r));
    Bob.rent.water = (RUB)((float)Bob.rent.water * (1.0f + r));
    Bob.rent.electricity = (RUB)((float)Bob.rent.electricity * (1.0f + r));
    Bob.rent.gas = (RUB)((float)Bob.rent.gas * (1.0f + r));
    Bob.rent.maintenance = (RUB)((float)Bob.rent.maintenance * (1.0f + r));
}


// ==================== ЗДОРОВЬЕ ====================

void Alice_health(const int month, float inflation) {
    Tinkoff.bank_account -= Alice.health.insurance;
    Tinkoff.bank_account -= Alice.health.medicine;

    // стоматолог 2 раза в год
    if (month == 3 || month == 9) {
        Alice.health.dentist = 5000;
        Tinkoff.bank_account -= Alice.health.dentist;
    } else {
        Alice.health.dentist = 0;
    }

    float r = inflation / 100.0f / 12.0f;
    Alice.health.insurance = (RUB)((float)Alice.health.insurance * (1.0f + r));
    Alice.health.medicine = (RUB)((float)Alice.health.medicine * (1.0f + r));
}


void Bob_health(const int month, float inflation) {
    Sber.bank_account -= Bob.health.insurance;
    Sber.bank_account -= Bob.health.medicine;

    // стоматолог раз в год
    if (month == 6) {
        Bob.health.dentist = 8000;
        Sber.bank_account -= Bob.health.dentist;
    } else {
        Bob.health.dentist = 0;
    }

    float r = inflation / 100.0f / 12.0f;
    Bob.health.insurance = (RUB)((float)Bob.health.insurance * (1.0f + r));
    Bob.health.medicine = (RUB)((float)Bob.health.medicine * (1.0f + r));
}


// ==================== РАЗВЛЕЧЕНИЯ ====================

void Alice_entertainment(float inflation) {
    Tinkoff.bank_account -= Alice.entertainment.cinema;
    Tinkoff.bank_account -= Alice.entertainment.subscriptions;
    Tinkoff.bank_account -= Alice.entertainment.hobbies;
    Tinkoff.bank_account -= Alice.entertainment.restaurants;

    float r = inflation / 100.0f / 12.0f;

    Alice.entertainment.cinema = (RUB)((float)Alice.entertainment.cinema * (1.0f + r));
    Alice.entertainment.subscriptions = (RUB)((float)Alice.entertainment.subscriptions * (1.0f + r));
    Alice.entertainment.hobbies = (RUB)((float)Alice.entertainment.hobbies * (1.0f + r));
    Alice.entertainment.restaurants = (RUB)((float)Alice.entertainment.restaurants * (1.0f + r));
}


void Bob_entertainment(float inflation) {
    Sber.bank_account -= Bob.entertainment.cinema;
    Sber.bank_account -= Bob.entertainment.subscriptions;
    Sber.bank_account -= Bob.entertainment.hobbies;
    Sber.bank_account -= Bob.entertainment.restaurants;

    float r = inflation / 100.0f / 12.0f;

    Bob.entertainment.cinema = (RUB)((float)Bob.entertainment.cinema * (1.0f + r));
    Bob.entertainment.subscriptions = (RUB)((float)Bob.entertainment.subscriptions * (1.0f + r));
    Bob.entertainment.hobbies = (RUB)((float)Bob.entertainment.hobbies * (1.0f + r));
    Bob.entertainment.restaurants = (RUB)((float)Bob.entertainment.restaurants * (1.0f + r));
}


// ==================== ОДЕЖДА (сезонные покупки) ====================

void Alice_clothing(const int month) {
    if (month == 10) {
        Alice.clothing.winter_clothes = 15000;
        Alice.clothing.shoes = 8000;
        Alice.clothing.accessories = 3000;
    } else if (month == 4) {
        Alice.clothing.summer_clothes = 12000;
        Alice.clothing.shoes = 6000;
        Alice.clothing.accessories = 2000;
    } else {
        Alice.clothing.winter_clothes = 0;
        Alice.clothing.summer_clothes = 0;
        Alice.clothing.shoes = 0;
        Alice.clothing.accessories = 0;
    }

    Tinkoff.bank_account -= Alice.clothing.winter_clothes;
    Tinkoff.bank_account -= Alice.clothing.summer_clothes;
    Tinkoff.bank_account -= Alice.clothing.shoes;
    Tinkoff.bank_account -= Alice.clothing.accessories;
}


void Bob_clothing(const int month) {
    if (month == 11) {
        Bob.clothing.winter_clothes = 25000;
        Bob.clothing.shoes = 12000;
        Bob.clothing.accessories = 5000;
    } else if (month == 5) {
        Bob.clothing.summer_clothes = 18000;
        Bob.clothing.shoes = 10000;
        Bob.clothing.accessories = 3000;
    } else {
        Bob.clothing.winter_clothes = 0;
        Bob.clothing.summer_clothes = 0;
        Bob.clothing.shoes = 0;
        Bob.clothing.accessories = 0;
    }

    Sber.bank_account -= Bob.clothing.winter_clothes;
    Sber.bank_account -= Bob.clothing.summer_clothes;
    Sber.bank_account -= Bob.clothing.shoes;
    Sber.bank_account -= Bob.clothing.accessories;
}


// ==================== ОБРАЗОВАНИЕ ====================

void Alice_education(float inflation) {
    Tinkoff.bank_account -= Alice.education.courses;
    Tinkoff.bank_account -= Alice.education.books;
    Tinkoff.bank_account -= Alice.education.software;

    float r = inflation / 100.0f / 12.0f;

    Alice.education.courses = (RUB)((float)Alice.education.courses * (1.0f + r));
    Alice.education.books = (RUB)((float)Alice.education.books * (1.0f + r));
    Alice.education.software = (RUB)((float)Alice.education.software * (1.0f + r));
}


void Bob_education(float inflation) {
    Sber.bank_account -= Bob.education.courses;
    Sber.bank_account -= Bob.education.books;
    Sber.bank_account -= Bob.education.software;

    float r = inflation / 100.0f / 12.0f;

    Bob.education.courses = (RUB)((float)Bob.education.courses * (1.0f + r));
    Bob.education.books = (RUB)((float)Bob.education.books * (1.0f + r));
    Bob.education.software = (RUB)((float)Bob.education.software * (1.0f + r));
}


// ==================== ЛИЧНЫЕ РАСХОДЫ ====================

void Alice_personal(float inflation) {
    Tinkoff.bank_account -= Alice.internet;
    Tinkoff.bank_account -= Alice.phone;

    float r = inflation / 100.0f / 12.0f;
    Alice.internet = (RUB)((float)Alice.internet * (1.0f + r));
    Alice.phone = (RUB)((float)Alice.phone * (1.0f + r));
}


void Bob_personal(float inflation) {
    Sber.bank_account -= Bob.internet;
    Sber.bank_account -= Bob.phone;

    float r = inflation / 100.0f / 12.0f;
    Bob.internet = (RUB)((float)Bob.internet * (1.0f + r));
    Bob.phone = (RUB)((float)Bob.phone * (1.0f + r));
}


// ==================== БАНКОВСКИЕ ОПЕРАЦИИ ====================

void Alice_bank_deals() {
    RUB dep_interest = (RUB)((float)Tinkoff.deposit * Tinkoff.percent / 12.0f / 100.0f);
    Tinkoff.deposit += dep_interest;

    RUB sav_interest = (RUB)((float)Tinkoff.savings_account * Tinkoff.savings_percent / 12.0f / 100.0f);
    Tinkoff.savings_account += sav_interest;

    // излишки со счёта уходят на накопительный
    if (Tinkoff.bank_account > 50000) {
        RUB transfer = (Tinkoff.bank_account - 50000) / 2;
        Tinkoff.savings_account += transfer;
        Tinkoff.bank_account -= transfer;
    }
}


void Bob_bank_deals() {
    RUB dep_interest = (RUB)((float)Sber.deposit * Sber.percent / 12.0f / 100.0f);
    Sber.deposit += dep_interest;

    RUB sav_interest = (RUB)((float)Sber.savings_account * Sber.savings_percent / 12.0f / 100.0f);
    Sber.savings_account += sav_interest;

    if (Sber.bank_account > 100000) {
        RUB transfer = (Sber.bank_account - 100000) / 2;
        Sber.savings_account += transfer;
        Sber.bank_account -= transfer;
    }
}


// ==================== ИПОТЕКА И КРЕДИТ ====================

void Bob_mortgage() {
    if (Bob.mortgage.months_left > 0) {
        Sber.bank_account -= Bob.mortgage.monthly_payment;

        // процентная часть от остатка долга
        RUB interest_part = (RUB)((float)Bob.mortgage.total_debt * Bob.mortgage.rate / 12.0f / 100.0f);
        RUB principal_part = Bob.mortgage.monthly_payment - interest_part;
        if (principal_part < 0) principal_part = 0;

        Bob.mortgage.total_debt -= principal_part;
        if (Bob.mortgage.total_debt < 0) Bob.mortgage.total_debt = 0;

        Bob.mortgage.months_left--;
    }
}


void Alice_credit(const int month, const int year) {
    // берёт потребительский кредит в январе 2028
    if (month == 1 && year == 2028) {
        Alice.credit.total_debt = 200000;
        Alice.credit.monthly_payment = 10000;
        Alice.credit.rate = 18.0;
        Alice.credit.months_left = 24;
    }

    if (Alice.credit.months_left > 0) {
        Tinkoff.bank_account -= Alice.credit.monthly_payment;

        RUB interest_part = (RUB)((float)Alice.credit.total_debt * Alice.credit.rate / 12.0f / 100.0f);
        RUB principal_part = Alice.credit.monthly_payment - interest_part;
        if (principal_part < 0) principal_part = 0;

        Alice.credit.total_debt -= principal_part;
        if (Alice.credit.total_debt < 0) Alice.credit.total_debt = 0;

        Alice.credit.months_left--;
    }
}


// ==================== ЖИЗНЕННЫЕ СОБЫТИЯ ====================

void Alice_life_events(const int month, const int year) {
    if (month == 8 && year == 2027) Tinkoff.bank_account -= 45000;  // ремонт авто
    if (month == 7 && year == 2028) Tinkoff.bank_account -= 80000;  // отпуск
    if (month == 7 && year == 2029) Tinkoff.bank_account -= 100000; // отпуск
    if (month == 7 && year == 2030) Tinkoff.bank_account -= 120000; // отпуск за границей
    if (month == 3 && year == 2028) Tinkoff.bank_account -= 90000;  // новый ноутбук
    if (month == 11 && year == 2029) Tinkoff.bank_account -= 50000; // замена телефона
    if (month == 6 && year == 2027) Tinkoff.bank_account -= 15000;  // подарок на свадьбу

    if (month == 4 && year == 2027) Tinkoff.bank_account += 20000;  // налоговый вычет
    if (month == 4 && year == 2028) Tinkoff.bank_account += 25000;
}

void Bob_life_events(const int month, const int year) {
    if (month == 5 && year == 2027) Sber.bank_account -= 60000;  // ТО машины
    if (month == 8 && year == 2027) Sber.bank_account -= 150000; // отпуск
    if (month == 8 && year == 2029) Sber.bank_account -= 200000; // отпуск
    if (month == 8 && year == 2030) Sber.bank_account -= 220000; // отпуск
    if (month == 11 && year == 2027) Sber.bank_account -= 70000; // новый телевизор
    if (month == 2 && year == 2029) Sber.bank_account -= 80000;  // замена телефона

    if (month == 1 && year == 2028) Sber.bank_account += 50000;  // фриланс
    if (month == 6 && year == 2029) Sber.bank_account += 75000;  // фриланс

    if (month == 4 || month == 10) Sber.bank_account -= 5000; // смена резины
}


// ==================== ЭКСТРЕННОЕ ПОКРЫТИЕ ====================

void Alice_emergency_check() {
    // если ушёл в минус — снимаем с накопительного
    if (Tinkoff.bank_account < 0) {
        RUB deficit = -Tinkoff.bank_account;
        if (Tinkoff.savings_account >= deficit) {
            Tinkoff.savings_account -= deficit;
            Tinkoff.bank_account = 0;
        } else {
            Tinkoff.bank_account += Tinkoff.savings_account;
            Tinkoff.savings_account = 0;
        }
    }
    // если всё ещё минус — снимаем с вклада (крайний случай)
    if (Tinkoff.bank_account < 0) {
        RUB deficit = -Tinkoff.bank_account;
        if (Tinkoff.deposit >= deficit) {
            Tinkoff.deposit -= deficit;
            Tinkoff.bank_account = 0;
        } else {
            Tinkoff.bank_account += Tinkoff.deposit;
            Tinkoff.deposit = 0;
        }
    }
}

void Bob_emergency_check() {
    if (Sber.bank_account < 0) {
        RUB deficit = -Sber.bank_account;
        if (Sber.savings_account >= deficit) {
            Sber.savings_account -= deficit;
            Sber.bank_account = 0;
        } else {
            Sber.bank_account += Sber.savings_account;
            Sber.savings_account = 0;
        }
    }
    if (Sber.bank_account < 0) {
        RUB deficit = -Sber.bank_account;
        if (Sber.deposit >= deficit) {
            Sber.deposit -= deficit;
            Sber.bank_account = 0;
        } else {
            Sber.bank_account += Sber.deposit;
            Sber.deposit = 0;
        }
    }
}


// ==================== ПОДСЧЁТ ИТОГОВ ====================

RUB Alice_total_food() {
    return Alice.food.meat + Alice.food.bread + Alice.food.sauces +
           Alice.food.vegetables + Alice.food.dairy + Alice.food.fruits +
           Alice.food.drinks + Alice.food.snacks;
}

RUB Bob_total_food() {
    return Bob.food.meat + Bob.food.bread + Bob.food.sauces +
           Bob.food.vegetables + Bob.food.dairy + Bob.food.fruits +
           Bob.food.drinks + Bob.food.snacks;
}

RUB Alice_total_transport() {
    return Alice.transport.metro + Alice.transport.bus +
           Alice.transport.taxi + Alice.transport.fuel;
}

RUB Bob_total_transport() {
    return Bob.transport.metro + Bob.transport.bus +
           Bob.transport.taxi + Bob.transport.fuel;
}

RUB Alice_total_rent() {
    return Alice.rent.price + Alice.rent.light + Alice.rent.water +
           Alice.rent.electricity + Alice.rent.gas + Alice.rent.maintenance;
}

RUB Bob_total_rent() {
    return Bob.rent.price + Bob.rent.light + Bob.rent.water +
           Bob.rent.electricity + Bob.rent.gas + Bob.rent.maintenance;
}

RUB Alice_total_entertainment() {
    return Alice.entertainment.cinema + Alice.entertainment.subscriptions +
           Alice.entertainment.hobbies + Alice.entertainment.restaurants;
}

RUB Bob_total_entertainment() {
    return Bob.entertainment.cinema + Bob.entertainment.subscriptions +
           Bob.entertainment.hobbies + Bob.entertainment.restaurants;
}

RUB Alice_total_education() {
    return Alice.education.courses + Alice.education.books + Alice.education.software;
}

RUB Bob_total_education() {
    return Bob.education.courses + Bob.education.books + Bob.education.software;
}

RUB Alice_net_worth() {
    return Tinkoff.bank_account + Tinkoff.deposit + Tinkoff.savings_account;
}

RUB Bob_net_worth() {
    return Sber.bank_account + Sber.deposit + Sber.savings_account
           - Bob.mortgage.total_debt - Bob.credit.total_debt;
}


// ==================== ВЫВОД ====================

void print_yearly_report(const int year) {
    printf("\n========== %d ==========\n", year);

    printf("\nAlice:\n");
    printf("  Salary:      %lld\n", Alice.salary);
    printf("  Food:        %lld\n", Alice_total_food());
    printf("  Rent:        %lld\n", Alice_total_rent());
    printf("  Transport:   %lld\n", Alice_total_transport());
    printf("  Account:     %lld\n", Tinkoff.bank_account);
    printf("  Deposit:     %lld\n", Tinkoff.deposit);
    printf("  Savings:     %lld\n", Tinkoff.savings_account);
    printf("  Credit:      %lld\n", Alice.credit.total_debt);
    printf("  Net worth:   %lld\n", Alice_net_worth());

    printf("\nBob:\n");
    printf("  Salary:      %lld\n", Bob.salary);
    printf("  Food:        %lld\n", Bob_total_food());
    printf("  Rent:        %lld\n", Bob_total_rent());
    printf("  Transport:   %lld\n", Bob_total_transport());
    printf("  Account:     %lld\n", Sber.bank_account);
    printf("  Deposit:     %lld\n", Sber.deposit);
    printf("  Savings:     %lld\n", Sber.savings_account);
    printf("  Mortgage:    %lld\n", Bob.mortgage.total_debt);
    printf("  Net worth:   %lld\n", Bob_net_worth());
}


// ==================== СИМУЛЯЦИЯ ====================

void simulation() {
    int month = 1;
    int year = 2026;
    float inflation = 5.6;

    while (!(month == 1 && year == 2031)) {
        Alice_salary(month, year);
        Alice_food(inflation);
        Alice_transport(inflation);
        Alice_rent(inflation);
        Alice_health(month, inflation);
        Alice_entertainment(inflation);
        Alice_clothing(month);
        Alice_education(inflation);
        Alice_personal(inflation);
        Alice_credit(month, year);
        Alice_life_events(month, year);
        Alice_bank_deals();
        Alice_emergency_check();

        Bob_salary(month, year);
        Bob_food(inflation);
        Bob_transport(inflation);
        Bob_rent(inflation);
        Bob_health(month, inflation);
        Bob_entertainment(inflation);
        Bob_clothing(month);
        Bob_education(inflation);
        Bob_personal(inflation);
        Bob_mortgage();
        Bob_life_events(month, year);
        Bob_bank_deals();
        Bob_emergency_check();

        if (month == 12) {
            print_yearly_report(year);
        }

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}


// ==================== ФИНАЛЬНЫЙ ОТЧЁТ ====================

void print_final_results() {
    printf("\n\n====== ИТОГО (Январь 2031) ======\n");

    printf("\nAlice (Tinkoff):\n");
    printf("  Salary:      %lld\n", Alice.salary);
    printf("  Account:     %lld\n", Tinkoff.bank_account);
    printf("  Deposit:     %lld\n", Tinkoff.deposit);
    printf("  Savings:     %lld\n", Tinkoff.savings_account);
    printf("  Credit:      %lld\n", Alice.credit.total_debt);
    printf("  NET WORTH:   %lld\n", Alice_net_worth());

    printf("\nBob (Sber):\n");
    printf("  Salary:      %lld\n", Bob.salary);
    printf("  Account:     %lld\n", Sber.bank_account);
    printf("  Deposit:     %lld\n", Sber.deposit);
    printf("  Savings:     %lld\n", Sber.savings_account);
    printf("  Mortgage:    %lld\n", Bob.mortgage.total_debt);
    printf("  NET WORTH:   %lld\n", Bob_net_worth());

    RUB alice_nw = Alice_net_worth();
    RUB bob_nw = Bob_net_worth();

    if (alice_nw > bob_nw) {
        printf("\nAlice has %lld more than Bob.\n", alice_nw - bob_nw);
    } else if (bob_nw > alice_nw) {
        printf("\nBob has %lld more than Alice.\n", bob_nw - alice_nw);
    } else {
        printf("\nEqual net worth.\n");
    }
}


// ==================== MAIN ====================

int main() {
    Alice_init();
    Bob_init();

    simulation();
    print_final_results();

    return 0;
}
