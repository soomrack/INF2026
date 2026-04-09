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
    RUB fish;
    RUB sweets;
    RUB cereals;
    RUB frozen;
};

struct Transport {
    RUB metro;
    RUB bus;
    RUB taxi;
    RUB fuel;
};

struct Car {
    RUB insurance_osago;
    RUB insurance_kasko;
    RUB parking;
    RUB wash;
    RUB service;
    int has_car;
};

struct Healthcare {
    RUB insurance;
    RUB medicine;
    RUB dentist;
    RUB vitamins;
    RUB gym;
};

struct Entertainment {
    RUB cinema;
    RUB subscriptions;
    RUB hobbies;
    RUB restaurants;
    RUB bars;
    RUB concerts;
};

struct Clothing {
    RUB winter_clothes;
    RUB summer_clothes;
    RUB shoes;
    RUB accessories;
    RUB sportswear;
};

struct Education {
    RUB courses;
    RUB books;
    RUB software;
    RUB conferences;
};

struct Rent {
    RUB price;
    RUB light;
    RUB water;
    RUB electricity;
    RUB gas;
    RUB maintenance;
    RUB garbage;
    RUB intercom;
};

struct Gifts {
    RUB birthday;
    RUB new_year;
    RUB other;
};

struct Pet {
    RUB food;
    RUB vet;
    RUB grooming;
    RUB toys;
    int has_pet;
};

struct Appliances {
    RUB budget;
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

struct Taxes {
    float ndfl_rate;    // 13%
    RUB ndfl_paid;      // сколько уже заплатил за год
};

struct Person {
    char name[64];
    RUB salary;
    RUB salary_gross;   // до вычета НДФЛ
    RUB bonus;
    RUB internet;
    RUB phone;
    Food food;
    Transport transport;
    Car car;
    Rent rent;
    Healthcare health;
    Entertainment entertainment;
    Clothing clothing;
    Education education;
    Gifts gifts;
    Pet pet;
    Appliances appliances;
    Mortgage mortgage;
    Credit credit;
    Taxes taxes;
};


// ==================== ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ ====================

struct Bank Tinkoff;
struct Bank Sber;

struct Person Alice;
struct Person Bob;


// ==================== ИНИЦИАЛИЗАЦИЯ ALICE ====================

void Alice_init() {
    strcpy(Alice.name, "Alice");
    Alice.salary_gross = 91954; // чтобы после 13% НДФЛ было ~80000
    Alice.salary = (RUB)(Alice.salary_gross * (1.0f - 0.13f));
    Alice.bonus = 0;

    Alice.food.meat = 2000;
    Alice.food.sauces = 1000;
    Alice.food.bread = 300;
    Alice.food.vegetables = 500;
    Alice.food.dairy = 800;
    Alice.food.fruits = 600;
    Alice.food.drinks = 400;
    Alice.food.snacks = 300;
    Alice.food.fish = 700;
    Alice.food.sweets = 400;
    Alice.food.cereals = 350;
    Alice.food.frozen = 500;

    Alice.transport.metro = 3000;
    Alice.transport.bus = 0;
    Alice.transport.taxi = 1500;
    Alice.transport.fuel = 0;

    Alice.car.has_car = 0;
    Alice.car.insurance_osago = 0;
    Alice.car.insurance_kasko = 0;
    Alice.car.parking = 0;
    Alice.car.wash = 0;
    Alice.car.service = 0;

    Alice.rent.price = 25000;
    Alice.rent.light = 800;
    Alice.rent.water = 500;
    Alice.rent.electricity = 1200;
    Alice.rent.gas = 400;
    Alice.rent.maintenance = 600;
    Alice.rent.garbage = 150;
    Alice.rent.intercom = 100;

    Alice.health.insurance = 0;
    Alice.health.medicine = 500;
    Alice.health.dentist = 0;
    Alice.health.vitamins = 300;
    Alice.health.gym = 2500;

    Alice.entertainment.cinema = 1000;
    Alice.entertainment.subscriptions = 700;
    Alice.entertainment.hobbies = 1500;
    Alice.entertainment.restaurants = 2000;
    Alice.entertainment.bars = 1000;
    Alice.entertainment.concerts = 0;

    Alice.clothing.winter_clothes = 0;
    Alice.clothing.summer_clothes = 0;
    Alice.clothing.shoes = 0;
    Alice.clothing.accessories = 0;
    Alice.clothing.sportswear = 0;

    Alice.education.courses = 2000;
    Alice.education.books = 500;
    Alice.education.software = 300;
    Alice.education.conferences = 0;

    Alice.gifts.birthday = 0;
    Alice.gifts.new_year = 0;
    Alice.gifts.other = 0;

    Alice.pet.has_pet = 1; // кошка
    Alice.pet.food = 1500;
    Alice.pet.vet = 0;
    Alice.pet.grooming = 0;
    Alice.pet.toys = 200;

    Alice.appliances.budget = 0;

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

    Alice.taxes.ndfl_rate = 13.0;
    Alice.taxes.ndfl_paid = 0;

    Tinkoff.bank_account = 200000;
    Tinkoff.deposit = 500000;
    Tinkoff.percent = 14.0;
    Tinkoff.savings_account = 100000;
    Tinkoff.savings_percent = 10.0;
}


// ==================== ИНИЦИАЛИЗАЦИЯ BOB ====================

void Bob_init() {
    strcpy(Bob.name, "Bob");
    Bob.salary_gross = 137931;
    Bob.salary = (RUB)(Bob.salary_gross * (1.0f - 0.13f));
    Bob.bonus = 0;

    Bob.food.meat = 3000;
    Bob.food.sauces = 800;
    Bob.food.bread = 400;
    Bob.food.vegetables = 700;
    Bob.food.dairy = 600;
    Bob.food.fruits = 500;
    Bob.food.drinks = 800;
    Bob.food.snacks = 500;
    Bob.food.fish = 1200;
    Bob.food.sweets = 300;
    Bob.food.cereals = 400;
    Bob.food.frozen = 700;

    Bob.transport.metro = 0;
    Bob.transport.bus = 0;
    Bob.transport.taxi = 2000;
    Bob.transport.fuel = 5000;

    Bob.car.has_car = 1;
    Bob.car.insurance_osago = 800;   // ~10000/год, помесячно
    Bob.car.insurance_kasko = 4000;  // ~48000/год
    Bob.car.parking = 3000;
    Bob.car.wash = 1000;
    Bob.car.service = 0;             // ТО отдельно в life_events

    Bob.rent.price = 0; // своя квартира
    Bob.rent.light = 1000;
    Bob.rent.water = 600;
    Bob.rent.electricity = 1500;
    Bob.rent.gas = 500;
    Bob.rent.maintenance = 1200;
    Bob.rent.garbage = 200;
    Bob.rent.intercom = 150;

    Bob.health.insurance = 3000;
    Bob.health.medicine = 300;
    Bob.health.dentist = 0;
    Bob.health.vitamins = 0;
    Bob.health.gym = 4000;

    Bob.entertainment.cinema = 500;
    Bob.entertainment.subscriptions = 1200;
    Bob.entertainment.hobbies = 3000;
    Bob.entertainment.restaurants = 4000;
    Bob.entertainment.bars = 2000;
    Bob.entertainment.concerts = 0;

    Bob.clothing.winter_clothes = 0;
    Bob.clothing.summer_clothes = 0;
    Bob.clothing.shoes = 0;
    Bob.clothing.accessories = 0;
    Bob.clothing.sportswear = 0;

    Bob.education.courses = 5000;
    Bob.education.books = 1000;
    Bob.education.software = 800;
    Bob.education.conferences = 0;

    Bob.gifts.birthday = 0;
    Bob.gifts.new_year = 0;
    Bob.gifts.other = 0;

    Bob.pet.has_pet = 0;
    Bob.pet.food = 0;
    Bob.pet.vet = 0;
    Bob.pet.grooming = 0;
    Bob.pet.toys = 0;

    Bob.appliances.budget = 0;

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

    Bob.taxes.ndfl_rate = 13.0;
    Bob.taxes.ndfl_paid = 0;

    Sber.bank_account = 500000;
    Sber.deposit = 1000000;
    Sber.percent = 12.0;
    Sber.savings_account = 0;
    Sber.savings_percent = 8.0;
}


// ==================== ЗАРПЛАТА ====================

void Alice_salary(const int month, const int year) {
    if ((month == 4) && (year == 2027)) {
        Alice.salary_gross *= 1.4;
        Alice.salary = (RUB)(Alice.salary_gross * (1.0f - Alice.taxes.ndfl_rate / 100.0f));
    }
    if ((month == 1) && (year == 2029)) {
        Alice.salary_gross *= 1.2;
        Alice.salary = (RUB)(Alice.salary_gross * (1.0f - Alice.taxes.ndfl_rate / 100.0f));
    }
    if ((month == 7) && (year == 2030)) {
        Alice.salary_gross *= 1.15;
        Alice.salary = (RUB)(Alice.salary_gross * (1.0f - Alice.taxes.ndfl_rate / 100.0f));
    }

    // годовая премия в декабре (тоже с НДФЛ)
    if (month == 12) {
        Alice.bonus = (RUB)(Alice.salary_gross * (1.0f - Alice.taxes.ndfl_rate / 100.0f));
    } else {
        Alice.bonus = 0;
    }

    // НДФЛ учёт
    RUB ndfl_this_month = (RUB)(Alice.salary_gross * Alice.taxes.ndfl_rate / 100.0f);
    Alice.taxes.ndfl_paid += ndfl_this_month;
    if (month == 1) Alice.taxes.ndfl_paid = ndfl_this_month; // сброс в январе

    Tinkoff.bank_account += Alice.salary;
    Tinkoff.bank_account += Alice.bonus;
}


void Bob_salary(const int month, const int year) {
    if ((month == 3) && (year == 2027)) {
        Bob.salary_gross *= 1.3;
        Bob.salary = (RUB)(Bob.salary_gross * (1.0f - Bob.taxes.ndfl_rate / 100.0f));
    }
    if ((month == 6) && (year == 2028)) {
        Bob.salary_gross *= 1.25;
        Bob.salary = (RUB)(Bob.salary_gross * (1.0f - Bob.taxes.ndfl_rate / 100.0f));
    }
    if ((month == 1) && (year == 2030)) {
        Bob.salary_gross *= 1.1;
        Bob.salary = (RUB)(Bob.salary_gross * (1.0f - Bob.taxes.ndfl_rate / 100.0f));
    }

    // квартальная премия 30% (после НДФЛ)
    if (month == 3 || month == 6 || month == 9 || month == 12) {
        Bob.bonus = (RUB)(Bob.salary_gross * 0.3 * (1.0f - Bob.taxes.ndfl_rate / 100.0f));
    } else {
        Bob.bonus = 0;
    }

    RUB ndfl_this_month = (RUB)(Bob.salary_gross * Bob.taxes.ndfl_rate / 100.0f);
    Bob.taxes.ndfl_paid += ndfl_this_month;
    if (month == 1) Bob.taxes.ndfl_paid = ndfl_this_month;

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
    Tinkoff.bank_account -= Alice.food.fish;
    Tinkoff.bank_account -= Alice.food.sweets;
    Tinkoff.bank_account -= Alice.food.cereals;
    Tinkoff.bank_account -= Alice.food.frozen;

    float r = inflation / 100.0f / 12.0f; // месячная инфляция

    Alice.food.meat = (RUB)((float)Alice.food.meat * (1.0f + r));
    Alice.food.sauces = (RUB)((float)Alice.food.sauces * (1.0f + r));
    Alice.food.bread = (RUB)((float)Alice.food.bread * (1.0f + r));
    Alice.food.vegetables = (RUB)((float)Alice.food.vegetables * (1.0f + r));
    Alice.food.dairy = (RUB)((float)Alice.food.dairy * (1.0f + r));
    Alice.food.fruits = (RUB)((float)Alice.food.fruits * (1.0f + r));
    Alice.food.drinks = (RUB)((float)Alice.food.drinks * (1.0f + r));
    Alice.food.snacks = (RUB)((float)Alice.food.snacks * (1.0f + r));
    Alice.food.fish = (RUB)((float)Alice.food.fish * (1.0f + r));
    Alice.food.sweets = (RUB)((float)Alice.food.sweets * (1.0f + r));
    Alice.food.cereals = (RUB)((float)Alice.food.cereals * (1.0f + r));
    Alice.food.frozen = (RUB)((float)Alice.food.frozen * (1.0f + r));
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
    Sber.bank_account -= Bob.food.fish;
    Sber.bank_account -= Bob.food.sweets;
    Sber.bank_account -= Bob.food.cereals;
    Sber.bank_account -= Bob.food.frozen;

    float r = inflation / 100.0f / 12.0f;

    Bob.food.meat = (RUB)((float)Bob.food.meat * (1.0f + r));
    Bob.food.sauces = (RUB)((float)Bob.food.sauces * (1.0f + r));
    Bob.food.bread = (RUB)((float)Bob.food.bread * (1.0f + r));
    Bob.food.vegetables = (RUB)((float)Bob.food.vegetables * (1.0f + r));
    Bob.food.dairy = (RUB)((float)Bob.food.dairy * (1.0f + r));
    Bob.food.fruits = (RUB)((float)Bob.food.fruits * (1.0f + r));
    Bob.food.drinks = (RUB)((float)Bob.food.drinks * (1.0f + r));
    Bob.food.snacks = (RUB)((float)Bob.food.snacks * (1.0f + r));
    Bob.food.fish = (RUB)((float)Bob.food.fish * (1.0f + r));
    Bob.food.sweets = (RUB)((float)Bob.food.sweets * (1.0f + r));
    Bob.food.cereals = (RUB)((float)Bob.food.cereals * (1.0f + r));
    Bob.food.frozen = (RUB)((float)Bob.food.frozen * (1.0f + r));
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


void Bob_car(float inflation) {
    if (!Bob.car.has_car) return;

    Sber.bank_account -= Bob.car.insurance_osago;
    Sber.bank_account -= Bob.car.insurance_kasko;
    Sber.bank_account -= Bob.car.parking;
    Sber.bank_account -= Bob.car.wash;

    float r = inflation / 100.0f / 12.0f;

    Bob.car.insurance_osago = (RUB)((float)Bob.car.insurance_osago * (1.0f + r));
    Bob.car.insurance_kasko = (RUB)((float)Bob.car.insurance_kasko * (1.0f + r));
    Bob.car.parking = (RUB)((float)Bob.car.parking * (1.0f + r));
    Bob.car.wash = (RUB)((float)Bob.car.wash * (1.0f + r));
}


// ==================== АРЕНДА / КОММУНАЛКА ====================

void Alice_rent(float inflation) {
    Tinkoff.bank_account -= Alice.rent.price;
    Tinkoff.bank_account -= Alice.rent.light;
    Tinkoff.bank_account -= Alice.rent.water;
    Tinkoff.bank_account -= Alice.rent.electricity;
    Tinkoff.bank_account -= Alice.rent.gas;
    Tinkoff.bank_account -= Alice.rent.maintenance;
    Tinkoff.bank_account -= Alice.rent.garbage;
    Tinkoff.bank_account -= Alice.rent.intercom;

    float r = inflation / 100.0f / 12.0f;

    Alice.rent.price = (RUB)((float)Alice.rent.price * (1.0f + r));
    Alice.rent.light = (RUB)((float)Alice.rent.light * (1.0f + r));
    Alice.rent.water = (RUB)((float)Alice.rent.water * (1.0f + r));
    Alice.rent.electricity = (RUB)((float)Alice.rent.electricity * (1.0f + r));
    Alice.rent.gas = (RUB)((float)Alice.rent.gas * (1.0f + r));
    Alice.rent.maintenance = (RUB)((float)Alice.rent.maintenance * (1.0f + r));
    Alice.rent.garbage = (RUB)((float)Alice.rent.garbage * (1.0f + r));
    Alice.rent.intercom = (RUB)((float)Alice.rent.intercom * (1.0f + r));
}


void Bob_rent(float inflation) {
    Sber.bank_account -= Bob.rent.price;
    Sber.bank_account -= Bob.rent.light;
    Sber.bank_account -= Bob.rent.water;
    Sber.bank_account -= Bob.rent.electricity;
    Sber.bank_account -= Bob.rent.gas;
    Sber.bank_account -= Bob.rent.maintenance;
    Sber.bank_account -= Bob.rent.garbage;
    Sber.bank_account -= Bob.rent.intercom;

    float r = inflation / 100.0f / 12.0f;

    Bob.rent.light = (RUB)((float)Bob.rent.light * (1.0f + r));
    Bob.rent.water = (RUB)((float)Bob.rent.water * (1.0f + r));
    Bob.rent.electricity = (RUB)((float)Bob.rent.electricity * (1.0f + r));
    Bob.rent.gas = (RUB)((float)Bob.rent.gas * (1.0f + r));
    Bob.rent.maintenance = (RUB)((float)Bob.rent.maintenance * (1.0f + r));
    Bob.rent.garbage = (RUB)((float)Bob.rent.garbage * (1.0f + r));
    Bob.rent.intercom = (RUB)((float)Bob.rent.intercom * (1.0f + r));
}


// ==================== ЗДОРОВЬЕ ====================

void Alice_health(const int month, float inflation) {
    Tinkoff.bank_account -= Alice.health.insurance;
    Tinkoff.bank_account -= Alice.health.medicine;
    Tinkoff.bank_account -= Alice.health.vitamins;
    Tinkoff.bank_account -= Alice.health.gym;

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
    Alice.health.vitamins = (RUB)((float)Alice.health.vitamins * (1.0f + r));
    Alice.health.gym = (RUB)((float)Alice.health.gym * (1.0f + r));
}


void Bob_health(const int month, float inflation) {
    Sber.bank_account -= Bob.health.insurance;
    Sber.bank_account -= Bob.health.medicine;
    Sber.bank_account -= Bob.health.vitamins;
    Sber.bank_account -= Bob.health.gym;

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
    Bob.health.vitamins = (RUB)((float)Bob.health.vitamins * (1.0f + r));
    Bob.health.gym = (RUB)((float)Bob.health.gym * (1.0f + r));
}


// ==================== РАЗВЛЕЧЕНИЯ ====================

void Alice_entertainment(const int month, float inflation) {
    Tinkoff.bank_account -= Alice.entertainment.cinema;
    Tinkoff.bank_account -= Alice.entertainment.subscriptions;
    Tinkoff.bank_account -= Alice.entertainment.hobbies;
    Tinkoff.bank_account -= Alice.entertainment.restaurants;
    Tinkoff.bank_account -= Alice.entertainment.bars;

    // концерты пару раз в год
    if (month == 5 || month == 11) {
        Alice.entertainment.concerts = 4000;
        Tinkoff.bank_account -= Alice.entertainment.concerts;
    } else {
        Alice.entertainment.concerts = 0;
    }

    float r = inflation / 100.0f / 12.0f;

    Alice.entertainment.cinema = (RUB)((float)Alice.entertainment.cinema * (1.0f + r));
    Alice.entertainment.subscriptions = (RUB)((float)Alice.entertainment.subscriptions * (1.0f + r));
    Alice.entertainment.hobbies = (RUB)((float)Alice.entertainment.hobbies * (1.0f + r));
    Alice.entertainment.restaurants = (RUB)((float)Alice.entertainment.restaurants * (1.0f + r));
    Alice.entertainment.bars = (RUB)((float)Alice.entertainment.bars * (1.0f + r));
}


void Bob_entertainment(const int month, float inflation) {
    Sber.bank_account -= Bob.entertainment.cinema;
    Sber.bank_account -= Bob.entertainment.subscriptions;
    Sber.bank_account -= Bob.entertainment.hobbies;
    Sber.bank_account -= Bob.entertainment.restaurants;
    Sber.bank_account -= Bob.entertainment.bars;

    // концерты 3 раза в год
    if (month == 3 || month == 7 || month == 11) {
        Bob.entertainment.concerts = 6000;
        Sber.bank_account -= Bob.entertainment.concerts;
    } else {
        Bob.entertainment.concerts = 0;
    }

    float r = inflation / 100.0f / 12.0f;

    Bob.entertainment.cinema = (RUB)((float)Bob.entertainment.cinema * (1.0f + r));
    Bob.entertainment.subscriptions = (RUB)((float)Bob.entertainment.subscriptions * (1.0f + r));
    Bob.entertainment.hobbies = (RUB)((float)Bob.entertainment.hobbies * (1.0f + r));
    Bob.entertainment.restaurants = (RUB)((float)Bob.entertainment.restaurants * (1.0f + r));
    Bob.entertainment.bars = (RUB)((float)Bob.entertainment.bars * (1.0f + r));
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
    } else if (month == 2) {
        Alice.clothing.sportswear = 5000;
    } else {
        Alice.clothing.winter_clothes = 0;
        Alice.clothing.summer_clothes = 0;
        Alice.clothing.shoes = 0;
        Alice.clothing.accessories = 0;
        Alice.clothing.sportswear = 0;
    }

    Tinkoff.bank_account -= Alice.clothing.winter_clothes;
    Tinkoff.bank_account -= Alice.clothing.summer_clothes;
    Tinkoff.bank_account -= Alice.clothing.shoes;
    Tinkoff.bank_account -= Alice.clothing.accessories;
    Tinkoff.bank_account -= Alice.clothing.sportswear;
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
    } else if (month == 1) {
        Bob.clothing.sportswear = 8000;
    } else {
        Bob.clothing.winter_clothes = 0;
        Bob.clothing.summer_clothes = 0;
        Bob.clothing.shoes = 0;
        Bob.clothing.accessories = 0;
        Bob.clothing.sportswear = 0;
    }

    Sber.bank_account -= Bob.clothing.winter_clothes;
    Sber.bank_account -= Bob.clothing.summer_clothes;
    Sber.bank_account -= Bob.clothing.shoes;
    Sber.bank_account -= Bob.clothing.accessories;
    Sber.bank_account -= Bob.clothing.sportswear;
}


// ==================== ОБРАЗОВАНИЕ ====================

void Alice_education(const int month, float inflation) {
    Tinkoff.bank_account -= Alice.education.courses;
    Tinkoff.bank_account -= Alice.education.books;
    Tinkoff.bank_account -= Alice.education.software;

    // конференция раз в год
    if (month == 10) {
        Alice.education.conferences = 5000;
        Tinkoff.bank_account -= Alice.education.conferences;
    } else {
        Alice.education.conferences = 0;
    }

    float r = inflation / 100.0f / 12.0f;

    Alice.education.courses = (RUB)((float)Alice.education.courses * (1.0f + r));
    Alice.education.books = (RUB)((float)Alice.education.books * (1.0f + r));
    Alice.education.software = (RUB)((float)Alice.education.software * (1.0f + r));
}


void Bob_education(const int month, float inflation) {
    Sber.bank_account -= Bob.education.courses;
    Sber.bank_account -= Bob.education.books;
    Sber.bank_account -= Bob.education.software;

    // конференции 2 раза в год
    if (month == 4 || month == 9) {
        Bob.education.conferences = 15000;
        Sber.bank_account -= Bob.education.conferences;
    } else {
        Bob.education.conferences = 0;
    }

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


// ==================== ПОДАРКИ ====================

void Alice_gifts(const int month) {
    // ДР друзей/родственников
    if (month == 2) {
        Alice.gifts.birthday = 3000;
    } else if (month == 6) {
        Alice.gifts.birthday = 4000;
    } else if (month == 9) {
        Alice.gifts.birthday = 3500;
    } else {
        Alice.gifts.birthday = 0;
    }

    // НГ подарки
    if (month == 12) {
        Alice.gifts.new_year = 10000;
    } else {
        Alice.gifts.new_year = 0;
    }

    // 8 марта, 23 февраля
    if (month == 2 || month == 3) {
        Alice.gifts.other = 2000;
    } else {
        Alice.gifts.other = 0;
    }

    Tinkoff.bank_account -= Alice.gifts.birthday;
    Tinkoff.bank_account -= Alice.gifts.new_year;
    Tinkoff.bank_account -= Alice.gifts.other;
}


void Bob_gifts(const int month) {
    if (month == 3) {
        Bob.gifts.birthday = 5000;
    } else if (month == 7) {
        Bob.gifts.birthday = 6000;
    } else if (month == 11) {
        Bob.gifts.birthday = 4000;
    } else {
        Bob.gifts.birthday = 0;
    }

    if (month == 12) {
        Bob.gifts.new_year = 15000;
    } else {
        Bob.gifts.new_year = 0;
    }

    if (month == 2 || month == 3) {
        Bob.gifts.other = 3000;
    } else {
        Bob.gifts.other = 0;
    }

    Sber.bank_account -= Bob.gifts.birthday;
    Sber.bank_account -= Bob.gifts.new_year;
    Sber.bank_account -= Bob.gifts.other;
}


// ==================== ПИТОМЦЫ ====================

void Alice_pet(float inflation) {
    if (!Alice.pet.has_pet) return;

    Tinkoff.bank_account -= Alice.pet.food;
    Tinkoff.bank_account -= Alice.pet.toys;

    float r = inflation / 100.0f / 12.0f;
    Alice.pet.food = (RUB)((float)Alice.pet.food * (1.0f + r));
    Alice.pet.toys = (RUB)((float)Alice.pet.toys * (1.0f + r));
}

void Alice_pet_events(const int month) {
    if (!Alice.pet.has_pet) return;

    // ветеринар 2 раза в год (прививки, осмотр)
    if (month == 4 || month == 10) {
        Alice.pet.vet = 3000;
        Tinkoff.bank_account -= Alice.pet.vet;
    } else {
        Alice.pet.vet = 0;
    }

    // груминг раз в квартал
    if (month == 3 || month == 6 || month == 9 || month == 12) {
        Alice.pet.grooming = 1500;
        Tinkoff.bank_account -= Alice.pet.grooming;
    } else {
        Alice.pet.grooming = 0;
    }
}


// ==================== БЫТОВАЯ ТЕХНИКА ====================

void Alice_appliances(const int month, const int year) {
    Alice.appliances.budget = 0;

    if (month == 2 && year == 2027) Alice.appliances.budget = 15000; // пылесос
    if (month == 9 && year == 2028) Alice.appliances.budget = 25000; // микроволновка + блендер
    if (month == 4 && year == 2030) Alice.appliances.budget = 35000; // стиральная машина

    Tinkoff.bank_account -= Alice.appliances.budget;
}

void Bob_appliances(const int month, const int year) {
    Bob.appliances.budget = 0;

    if (month == 3 && year == 2027) Bob.appliances.budget = 40000;  // посудомойка
    if (month == 8 && year == 2028) Bob.appliances.budget = 20000;  // кофемашина
    if (month == 1 && year == 2029) Bob.appliances.budget = 60000;  // робот-пылесос + кондей
    if (month == 5 && year == 2030) Bob.appliances.budget = 30000;  // мультиварка + чайник

    Sber.bank_account -= Bob.appliances.budget;
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
    // ремонт / бытовые аварии
    if (month == 8 && year == 2027) Tinkoff.bank_account -= 45000;  // ремонт сантехники
    if (month == 2 && year == 2028) Tinkoff.bank_account -= 12000;  // ремонт обуви + химчистка
    if (month == 3 && year == 2030) Tinkoff.bank_account -= 18000;  // замена замка + ключи
    if (month == 11 && year == 2026) Tinkoff.bank_account -= 8000;  // сломался утюг + мелочи
    if (month == 6 && year == 2029) Tinkoff.bank_account -= 15000;  // починка мебели

    // отпуска
    if (month == 7 && year == 2026) Tinkoff.bank_account -= 40000;  // короткий отпуск на море
    if (month == 7 && year == 2027) Tinkoff.bank_account -= 55000;  // отпуск
    if (month == 7 && year == 2028) Tinkoff.bank_account -= 80000;  // отпуск подальше
    if (month == 7 && year == 2029) Tinkoff.bank_account -= 100000; // отпуск
    if (month == 7 && year == 2030) Tinkoff.bank_account -= 120000; // отпуск за границей
    if (month == 1 && year == 2027) Tinkoff.bank_account -= 20000;  // новогодние каникулы
    if (month == 1 && year == 2029) Tinkoff.bank_account -= 25000;  // НГ поездка

    // техника
    if (month == 3 && year == 2028) Tinkoff.bank_account -= 90000;  // новый ноутбук
    if (month == 11 && year == 2029) Tinkoff.bank_account -= 50000; // замена телефона
    if (month == 10 && year == 2026) Tinkoff.bank_account -= 15000; // наушники + аксессуары
    if (month == 6 && year == 2030) Tinkoff.bank_account -= 35000;  // планшет

    // покупка машины
    if (month == 5 && year == 2029) Tinkoff.bank_account -= 800000; // б/у авто

    // автомобильные расходы после покупки
    if (Alice.car.has_car) {
        if (month == 4 || month == 10) Tinkoff.bank_account -= 4000; // смена резины
        if (month == 9 && year == 2029) Tinkoff.bank_account -= 25000; // первое ТО
        if (month == 9 && year == 2030) Tinkoff.bank_account -= 30000; // ТО
    }

    // свадьбы/события друзей
    if (month == 6 && year == 2027) Tinkoff.bank_account -= 15000;  // подарок на свадьбу
    if (month == 8 && year == 2028) Tinkoff.bank_account -= 10000;  // ДР подруги
    if (month == 4 && year == 2029) Tinkoff.bank_account -= 12000;  // свадьба коллеги
    if (month == 10 && year == 2028) Tinkoff.bank_account -= 8000;  // фотосессия

    // мебель / обустройство
    if (month == 5 && year == 2029) Tinkoff.bank_account -= 20000;  // новый стол
    if (month == 11 && year == 2028) Tinkoff.bank_account -= 30000; // шкаф в новую квартиру
    if (month == 12 && year == 2028) Tinkoff.bank_account -= 15000; // шторы + декор

    // предновогодние траты
    if (month == 12 && year == 2026) Tinkoff.bank_account -= 10000;
    if (month == 12 && year == 2027) Tinkoff.bank_account -= 12000;
    if (month == 12 && year == 2028) Tinkoff.bank_account -= 15000;
    if (month == 12 && year == 2029) Tinkoff.bank_account -= 18000;
    if (month == 12 && year == 2030) Tinkoff.bank_account -= 25000;

    // налоговый вычет за лечение/образование
    if (month == 4 && year == 2027) Tinkoff.bank_account += 20000;
    if (month == 4 && year == 2028) Tinkoff.bank_account += 25000;
    if (month == 4 && year == 2029) Tinkoff.bank_account += 28000;
    if (month == 4 && year == 2030) Tinkoff.bank_account += 30000;
}

void Bob_life_events(const int month, const int year) {
    // ТО и ремонт авто
    if (month == 5 && year == 2027) Sber.bank_account -= 60000;  // ТО + мелкий ремонт
    if (month == 6 && year == 2028) Sber.bank_account -= 40000;  // аккумулятор + тормоза
    if (month == 5 && year == 2029) Sber.bank_account -= 65000;  // ТО + подвеска
    if (month == 5 && year == 2030) Sber.bank_account -= 70000;  // ТО + замена ремня ГРМ
    if (month == 9 && year == 2027) Sber.bank_account -= 35000;  // новые шины + диски
    if (month == 3 && year == 2029) Sber.bank_account -= 20000;  // лобовое стекло
    if (month == 11 && year == 2030) Sber.bank_account -= 40000; // кузовной ремонт (царапина)

    // отпуска
    if (month == 8 && year == 2026) Sber.bank_account -= 100000; // отпуск
    if (month == 8 && year == 2027) Sber.bank_account -= 150000; // отпуск
    if (month == 8 && year == 2028) Sber.bank_account -= 170000; // отпуск
    if (month == 8 && year == 2029) Sber.bank_account -= 200000; // отпуск за границей
    if (month == 8 && year == 2030) Sber.bank_account -= 220000; // отпуск
    if (month == 1 && year == 2028) Sber.bank_account -= 30000;  // НГ поездка
    if (month == 1 && year == 2030) Sber.bank_account -= 35000;  // НГ поездка

    // техника
    if (month == 11 && year == 2027) Sber.bank_account -= 70000;  // телевизор
    if (month == 2 && year == 2029) Sber.bank_account -= 80000;   // новый телефон
    if (month == 1 && year == 2030) Sber.bank_account -= 45000;   // новый комп
    if (month == 7 && year == 2028) Sber.bank_account -= 30000;   // игровая приставка
    if (month == 4 && year == 2030) Sber.bank_account -= 25000;   // умные часы + наушники

    // ремонт квартиры
    if (month == 10 && year == 2030) Sber.bank_account -= 55000;  // ванная
    if (month == 3 && year == 2028) Sber.bank_account -= 80000;   // кухня (частичный ремонт)
    if (month == 6 && year == 2026) Sber.bank_account -= 25000;   // покраска стен

    // события друзей
    if (month == 9 && year == 2028) Sber.bank_account -= 20000;   // свадьба друга
    if (month == 5 && year == 2027) Sber.bank_account -= 10000;   // ДР друга

    // предновогодние
    if (month == 12 && year == 2026) Sber.bank_account -= 15000;
    if (month == 12 && year == 2027) Sber.bank_account -= 18000;
    if (month == 12 && year == 2028) Sber.bank_account -= 20000;
    if (month == 12 && year == 2029) Sber.bank_account -= 30000;
    if (month == 12 && year == 2030) Sber.bank_account -= 35000;

    // фриланс
    if (month == 1 && year == 2028) Sber.bank_account += 50000;
    if (month == 11 && year == 2028) Sber.bank_account += 40000;
    if (month == 6 && year == 2029) Sber.bank_account += 75000;
    if (month == 3 && year == 2030) Sber.bank_account += 60000;
    if (month == 9 && year == 2030) Sber.bank_account += 45000;

    // смена резины 2 раза в год
    if (month == 4 || month == 10) Sber.bank_account -= 5000;
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
           Alice.food.drinks + Alice.food.snacks + Alice.food.fish +
           Alice.food.sweets + Alice.food.cereals + Alice.food.frozen;
}

RUB Bob_total_food() {
    return Bob.food.meat + Bob.food.bread + Bob.food.sauces +
           Bob.food.vegetables + Bob.food.dairy + Bob.food.fruits +
           Bob.food.drinks + Bob.food.snacks + Bob.food.fish +
           Bob.food.sweets + Bob.food.cereals + Bob.food.frozen;
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
           Alice.rent.electricity + Alice.rent.gas + Alice.rent.maintenance +
           Alice.rent.garbage + Alice.rent.intercom;
}

RUB Bob_total_rent() {
    return Bob.rent.price + Bob.rent.light + Bob.rent.water +
           Bob.rent.electricity + Bob.rent.gas + Bob.rent.maintenance +
           Bob.rent.garbage + Bob.rent.intercom;
}

RUB Alice_total_entertainment() {
    return Alice.entertainment.cinema + Alice.entertainment.subscriptions +
           Alice.entertainment.hobbies + Alice.entertainment.restaurants +
           Alice.entertainment.bars;
}

RUB Bob_total_entertainment() {
    return Bob.entertainment.cinema + Bob.entertainment.subscriptions +
           Bob.entertainment.hobbies + Bob.entertainment.restaurants +
           Bob.entertainment.bars;
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
    printf("  NDFL paid:   %lld\n", Alice.taxes.ndfl_paid);
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
    printf("  NDFL paid:   %lld\n", Bob.taxes.ndfl_paid);
    printf("  Net worth:   %lld\n", Bob_net_worth());
}


// ==================== СИМУЛЯЦИЯ ====================

void simulation() {
    int month = 1;
    int year = 2026;
    float inflation = 5.6;

    while (!(month == 1 && year == 2031)) {

        // --- Alice ---
        Alice_salary(month, year);
        Alice_food(inflation);
        Alice_transport(inflation);
        Alice_rent(inflation);
        Alice_health(month, inflation);
        Alice_entertainment(month, inflation);
        Alice_clothing(month);
        Alice_education(month, inflation);
        Alice_personal(inflation);
        Alice_gifts(month);
        Alice_pet(inflation);
        Alice_pet_events(month);
        Alice_appliances(month, year);
        Alice_credit(month, year);
        Alice_life_events(month, year);
        Alice_bank_deals();
        Alice_emergency_check();

        // --- Bob ---
        Bob_salary(month, year);
        Bob_food(inflation);
        Bob_transport(inflation);
        Bob_car(inflation);
        Bob_rent(inflation);
        Bob_health(month, inflation);
        Bob_entertainment(month, inflation);
        Bob_clothing(month);
        Bob_education(month, inflation);
        Bob_personal(inflation);
        Bob_gifts(month);
        Bob_appliances(month, year);
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
