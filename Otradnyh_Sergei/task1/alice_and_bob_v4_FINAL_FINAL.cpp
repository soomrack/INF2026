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

struct PersonalCare {
    RUB haircut;
    RUB cosmetics;
    RUB hygiene;
};

struct FoodDelivery {
    RUB monthly;
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
    PersonalCare care;
    FoodDelivery delivery;
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

    Alice.care.haircut = 2000;
    Alice.care.cosmetics = 1500;
    Alice.care.hygiene = 800;

    Alice.delivery.monthly = 2000;

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

    Bob.care.haircut = 1500;
    Bob.care.cosmetics = 500;
    Bob.care.hygiene = 600;

    Bob.delivery.monthly = 4000; // заказывает чаще

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


// ==================== АВТОМОБИЛЬ ====================

void Alice_car(const int month, const int year, float inflation) {
    // покупает машину в мае 2029
    if (month == 5 && year == 2029) {
        Alice.car.has_car = 1;
        Alice.car.insurance_osago = 700;
        Alice.car.insurance_kasko = 3500;
        Alice.car.parking = 2000;
        Alice.car.wash = 800;
        Alice.transport.fuel = 4000;
        Alice.transport.metro = 0;  // пересаживается на машину
        Alice.transport.bus = 0;
    }

    if (!Alice.car.has_car) return;

    Tinkoff.bank_account -= Alice.car.insurance_osago;
    Tinkoff.bank_account -= Alice.car.insurance_kasko;
    Tinkoff.bank_account -= Alice.car.parking;
    Tinkoff.bank_account -= Alice.car.wash;

    float r = inflation / 100.0f / 12.0f;

    Alice.car.insurance_osago = (RUB)((float)Alice.car.insurance_osago * (1.0f + r));
    Alice.car.insurance_kasko = (RUB)((float)Alice.car.insurance_kasko * (1.0f + r));
    Alice.car.parking = (RUB)((float)Alice.car.parking * (1.0f + r));
    Alice.car.wash = (RUB)((float)Alice.car.wash * (1.0f + r));
}


void Bob_car(const int month, float inflation) {
    if (!Bob.car.has_car) return;

    Sber.bank_account -= Bob.car.insurance_osago;
    Sber.bank_account -= Bob.car.insurance_kasko;
    Sber.bank_account -= Bob.car.parking;
    Sber.bank_account -= Bob.car.wash;

    // зимой мойка чаще
    if (month >= 11 || month <= 3) {
        Sber.bank_account -= Bob.car.wash; // доп. мойка
    }

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

void Alice_care(const int month, float inflation) {
    // стрижка раз в 2 месяца
    if (month % 2 == 0) {
        Tinkoff.bank_account -= Alice.care.haircut;
    }

    Tinkoff.bank_account -= Alice.care.cosmetics;
    Tinkoff.bank_account -= Alice.care.hygiene;

    float r = inflation / 100.0f / 12.0f;
    Alice.care.haircut = (RUB)((float)Alice.care.haircut * (1.0f + r));
    Alice.care.cosmetics = (RUB)((float)Alice.care.cosmetics * (1.0f + r));
    Alice.care.hygiene = (RUB)((float)Alice.care.hygiene * (1.0f + r));
}


void Bob_care(const int month, float inflation) {
    // стрижка каждый месяц
    Sber.bank_account -= Bob.care.haircut;
    Sber.bank_account -= Bob.care.cosmetics;
    Sber.bank_account -= Bob.care.hygiene;

    float r = inflation / 100.0f / 12.0f;
    Bob.care.haircut = (RUB)((float)Bob.care.haircut * (1.0f + r));
    Bob.care.cosmetics = (RUB)((float)Bob.care.cosmetics * (1.0f + r));
    Bob.care.hygiene = (RUB)((float)Bob.care.hygiene * (1.0f + r));
}


// ==================== ДОСТАВКА ЕДЫ ====================

void Alice_delivery(float inflation) {
    Tinkoff.bank_account -= Alice.delivery.monthly;

    float r = inflation / 100.0f / 12.0f;
    Alice.delivery.monthly = (RUB)((float)Alice.delivery.monthly * (1.0f + r));
}


void Bob_delivery(float inflation) {
    Sber.bank_account -= Bob.delivery.monthly;

    float r = inflation / 100.0f / 12.0f;
    Bob.delivery.monthly = (RUB)((float)Bob.delivery.monthly * (1.0f + r));
}


// ==================== СЕЗОННЫЕ КОММУНАЛЬНЫЕ ====================

void Alice_seasonal_utilities(const int month) {
    // зимой электричество дороже (обогреватель, свет раньше)
    if (month >= 11 || month <= 3) {
        Tinkoff.bank_account -= 800;
    }
    // летом кондиционер
    if (month >= 6 && month <= 8) {
        Tinkoff.bank_account -= 500;
    }
}


void Bob_seasonal_utilities(const int month) {
    if (month >= 11 || month <= 3) {
        Sber.bank_account -= 1200;
    }
    if (month >= 6 && month <= 8) {
        Sber.bank_account -= 800;
    }
}


// ==================== СЕЗОННЫЕ РАСХОДЫ НА ЕДУ ====================

void Alice_seasonal_food(const int month) {
    // зимой больше тратит на горячее, чай, мёд
    if (month >= 11 || month <= 2) {
        Tinkoff.bank_account -= 1000;
    }
    // летом больше фруктов, мороженое, напитки
    if (month >= 6 && month <= 8) {
        Tinkoff.bank_account -= 800;
    }
    // праздничный стол в декабре
    if (month == 12) {
        Tinkoff.bank_account -= 5000;
    }
    // масленица
    if (month == 3) {
        Tinkoff.bank_account -= 1000;
    }
}


void Bob_seasonal_food(const int month) {
    if (month >= 11 || month <= 2) {
        Sber.bank_account -= 1500;
    }
    if (month >= 6 && month <= 8) {
        Sber.bank_account -= 1200;
    }
    if (month == 12) {
        Sber.bank_account -= 8000;
    }
    // шашлыки на майские
    if (month == 5) {
        Sber.bank_account -= 3000;
    }
}


// ==================== ПОДПИСКИ (ИЗМЕНЕНИЯ) ====================

void Alice_subscriptions_update(const int month, const int year) {
    // добавляет подписку на музыку с 2027
    if (month == 1 && year == 2027) {
        Alice.entertainment.subscriptions += 200;
    }
    // добавляет онлайн-кинотеатр с 2028
    if (month == 6 && year == 2028) {
        Alice.entertainment.subscriptions += 400;
    }
    // отказывается от одной подписки в 2029 (оптимизирует)
    if (month == 3 && year == 2029) {
        Alice.entertainment.subscriptions -= 300;
        if (Alice.entertainment.subscriptions < 0) Alice.entertainment.subscriptions = 0;
    }
}


void Bob_subscriptions_update(const int month, const int year) {
    // подписка на VPN
    if (month == 1 && year == 2027) {
        Bob.entertainment.subscriptions += 300;
    }
    // облачное хранилище
    if (month == 4 && year == 2027) {
        Bob.entertainment.subscriptions += 200;
    }
    // добавляет подписку на образовательную платформу
    if (month == 9 && year == 2028) {
        Bob.education.courses += 1500;
    }
    // отменяет кинотеатр в 2030
    if (month == 2 && year == 2030) {
        Bob.entertainment.subscriptions -= 500;
        if (Bob.entertainment.subscriptions < 0) Bob.entertainment.subscriptions = 0;
    }
}


// ==================== ХОББИ-СОБЫТИЯ ====================

void Alice_hobby_events(const int month, const int year) {
    // покупка материалов для рукоделия
    if (month == 9 && year == 2026) Tinkoff.bank_account -= 3000;
    if (month == 1 && year == 2027) Tinkoff.bank_account -= 4000;
    if (month == 9 && year == 2027) Tinkoff.bank_account -= 3500;
    if (month == 1 && year == 2028) Tinkoff.bank_account -= 5000;

    // начинает ходить на йогу с 2028
    if (year >= 2028) {
        Tinkoff.bank_account -= 2000;
    }

    // мастер-классы
    if (month == 3 && year == 2027) Tinkoff.bank_account -= 3000;
    if (month == 10 && year == 2028) Tinkoff.bank_account -= 4000;
    if (month == 3 && year == 2029) Tinkoff.bank_account -= 4500;
    if (month == 10 && year == 2030) Tinkoff.bank_account -= 5000;

    // покупка фотоаппарата
    if (month == 6 && year == 2028) Tinkoff.bank_account -= 45000;
}


void Bob_hobby_events(const int month, const int year) {
    // обновление игрового оборудования
    if (month == 11 && year == 2026) Sber.bank_account -= 8000;  // геймпад
    if (month == 2 && year == 2028) Sber.bank_account -= 15000;  // клавиатура + мышь
    if (month == 11 && year == 2029) Sber.bank_account -= 20000; // монитор

    // начинает бегать с 2027, покупает кроссовки
    if (month == 4 && year == 2027) Sber.bank_account -= 12000;
    if (month == 4 && year == 2028) Sber.bank_account -= 13000;
    if (month == 4 && year == 2029) Sber.bank_account -= 14000;
    if (month == 4 && year == 2030) Sber.bank_account -= 15000;

    // участие в забегах
    if (month == 6 && year == 2027) Sber.bank_account -= 3000;
    if (month == 9 && year == 2028) Sber.bank_account -= 4000;
    if (month == 6 && year == 2029) Sber.bank_account -= 5000;
    if (month == 9 && year == 2030) Sber.bank_account -= 5000;

    // покупка велосипеда
    if (month == 5 && year == 2028) Sber.bank_account -= 35000;

    // ремонт велосипеда
    if (month == 4 && year == 2029) Sber.bank_account -= 5000;
    if (month == 4 && year == 2030) Sber.bank_account -= 6000;
}


// ==================== УБОРКА (BOB) ====================

void Bob_cleaning(const int month, const int year, float inflation) {
    // нанимает клининг с 2028 года, 2 раза в месяц
    if (year < 2028) return;

    RUB cleaning_cost = 4000;
    if (year == 2029) cleaning_cost = 4200;
    if (year == 2030) cleaning_cost = 4500;

    Sber.bank_account -= cleaning_cost;
}


// ==================== ШТРАФЫ И НЕПРЕДВИДЕННОЕ ====================

void Alice_fines(const int month, const int year) {
    if (!Alice.car.has_car) return;

    // штраф за парковку
    if (month == 7 && year == 2029) Tinkoff.bank_account -= 3000;
    if (month == 2 && year == 2030) Tinkoff.bank_account -= 2500;

    // штраф за превышение
    if (month == 11 && year == 2029) Tinkoff.bank_account -= 1500;
    if (month == 8 && year == 2030) Tinkoff.bank_account -= 3000;
}


void Bob_fines(const int month, const int year) {
    // штрафы ГИБДД
    if (month == 3 && year == 2026) Sber.bank_account -= 1500;
    if (month == 8 && year == 2027) Sber.bank_account -= 2500;
    if (month == 1 && year == 2028) Sber.bank_account -= 5000;
    if (month == 6 && year == 2029) Sber.bank_account -= 2000;
    if (month == 4 && year == 2030) Sber.bank_account -= 3000;
    if (month == 9 && year == 2030) Sber.bank_account -= 1500;

    // эвакуатор
    if (month == 10 && year == 2028) Sber.bank_account -= 7000;
}


// ==================== УДАЛЁНКА (BOB) ====================

void Bob_remote_work(const int month, const int year) {
    // с 2029 переходит на частичную удалёнку, экономит на бензине
    if (year >= 2029) {
        Sber.bank_account += 2000; // меньше ездит
    }

    // но тратит на домашний офис
    if (month == 1 && year == 2029) Sber.bank_account -= 25000; // кресло
    if (month == 2 && year == 2029) Sber.bank_account -= 15000; // стол
    if (month == 3 && year == 2029) Sber.bank_account -= 5000;  // лампа + органайзер
}


// ==================== БЫТОВЫЕ МЕЛОЧИ ====================

void Alice_household(const int month, const int year) {
    // бытовая химия и расходники каждый месяц
    Tinkoff.bank_account -= 1500;

    // сезонные закупки
    if (month == 9) {
        Tinkoff.bank_account -= 3000; // канцтовары, начало учебного сезона (привычка)
    }
    if (month == 3 && year == 2027) Tinkoff.bank_account -= 5000; // генеральная уборка, средства
    if (month == 3 && year == 2028) Tinkoff.bank_account -= 5500;
    if (month == 3 && year == 2029) Tinkoff.bank_account -= 6000;
    if (month == 3 && year == 2030) Tinkoff.bank_account -= 6500;

    // замена постельного белья/полотенец раз в год
    if (month == 8) {
        Tinkoff.bank_account -= 4000;
    }
}


void Bob_household(const int month, const int year) {
    Sber.bank_account -= 2000;

    // фильтры для воды каждые 3 месяца
    if (month == 1 || month == 4 || month == 7 || month == 10) {
        Sber.bank_account -= 1500;
    }

    // замена лампочек, батареек, мелочи
    if (month == 6) {
        Sber.bank_account -= 2000;
    }
    if (month == 12) {
        Sber.bank_account -= 2500;
    }

    // генеральная уборка перед НГ (дополнительно к клинингу)
    if (month == 12 && year >= 2028) {
        Sber.bank_account -= 3000;
    }
}


// ==================== БЛАГОТВОРИТЕЛЬНОСТЬ (BOB) ====================

void Bob_charity(const int month, const int year) {
    // начинает жертвовать с 2028, раз в квартал
    if (year < 2028) return;

    if (month == 3 || month == 6 || month == 9 || month == 12) {
        Sber.bank_account -= 3000;
    }
}


// ==================== КЭШБЭК ====================

void Alice_cashback(const int month) {
    // кэшбэк по карте ~1% от трат, примерно
    Tinkoff.bank_account += 500;

    // повышенный кэшбэк в категориях иногда
    if (month == 1 || month == 7) {
        Tinkoff.bank_account += 300;
    }
}


void Bob_cashback(const int month) {
    Sber.bank_account += 800;

    if (month == 3 || month == 9) {
        Sber.bank_account += 500;
    }
}


// ==================== СМЕНА ЗАЛА (ALICE) ====================

void Alice_gym_change(const int month, const int year) {
    // переходит в зал получше с 2029
    if (month == 1 && year == 2029) {
        Alice.health.gym = 4000;
    }
    // годовой абонемент со скидкой в январе
    if (month == 1 && year == 2030) {
        Tinkoff.bank_account -= 36000; // оплата за год вперёд
        Alice.health.gym = 0;          // помесячно не платит
    }
    // восстанавливает помесячную оплату через год
    if (month == 1 && year == 2031) {
        Alice.health.gym = 4500;
    }
}


// ==================== СТРАХОВАНИЕ ЖИЗНИ (BOB) ====================

void Bob_life_insurance(const int month, const int year) {
    // оформляет страхование жизни с 2028 (привязано к ипотеке)
    if (year < 2028) return;

    // платит раз в год в январе
    if (month == 1) {
        RUB premium = 15000;
        if (year == 2029) premium = 16000;
        if (year == 2030) premium = 17000;
        Sber.bank_account -= premium;
    }
}


// ==================== ДЕПОЗИТНЫЕ ОПЕРАЦИИ ====================

void Alice_deposit_topup(const int month, const int year) {
    // раз в год в июне пополняет вклад, если на накопительном больше 300к
    if (month == 6 && Tinkoff.savings_account > 300000) {
        RUB topup = 100000;
        Tinkoff.savings_account -= topup;
        Tinkoff.deposit += topup;
    }
}


void Bob_deposit_topup(const int month, const int year) {
    // раз в год в марте пополняет вклад
    if (month == 3 && Sber.savings_account > 500000) {
        RUB topup = 200000;
        Sber.savings_account -= topup;
        Sber.deposit += topup;
    }
}


// ==================== ЗДОРОВЬЕ (ЭКСТРЕННОЕ) ====================

void Alice_health_events(const int month, const int year) {
    // простуда зимой
    if (month == 1 && year == 2027) Tinkoff.bank_account -= 3000;
    if (month == 2 && year == 2029) Tinkoff.bank_account -= 4000;
    if (month == 12 && year == 2029) Tinkoff.bank_account -= 3500;

    // аллергия весной
    if (month == 5 && year == 2027) Tinkoff.bank_account -= 2000;
    if (month == 5 && year == 2028) Tinkoff.bank_account -= 2500;
    if (month == 5 && year == 2029) Tinkoff.bank_account -= 2500;
    if (month == 5 && year == 2030) Tinkoff.bank_account -= 3000;

    // линзы раз в 3 месяца
    if (month == 1 || month == 4 || month == 7 || month == 10) {
        Tinkoff.bank_account -= 3000;
    }

    // экстренный визит к врачу
    if (month == 9 && year == 2028) Tinkoff.bank_account -= 15000;

    // операция на зуб мудрости
    if (month == 2 && year == 2030) Tinkoff.bank_account -= 25000;
}


void Bob_health_events(const int month, const int year) {
    // простуда
    if (month == 12 && year == 2027) Sber.bank_account -= 3000;
    if (month == 1 && year == 2029) Sber.bank_account -= 4500;

    // спортивная травма
    if (month == 4 && year == 2028) Sber.bank_account -= 20000;  // МРТ + лечение
    if (month == 5 && year == 2028) Sber.bank_account -= 10000;  // физиотерапия

    // годовой чекап
    if (month == 3 && year == 2027) Sber.bank_account -= 15000;
    if (month == 3 && year == 2028) Sber.bank_account -= 16000;
    if (month == 3 && year == 2029) Sber.bank_account -= 17000;
    if (month == 3 && year == 2030) Sber.bank_account -= 18000;

    // очки новые раз в 2 года
    if (month == 6 && year == 2027) Sber.bank_account -= 12000;
    if (month == 6 && year == 2029) Sber.bank_account -= 14000;
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


// ==================== ПИТОМЦЫ BOB ====================

void Bob_pet(const int month, const int year, float inflation) {
    // заводит собаку в марте 2027
    if (month == 3 && year == 2027) {
        Bob.pet.has_pet = 1;
        Bob.pet.food = 3000;
        Bob.pet.toys = 500;
        Sber.bank_account -= 25000; // покупка щенка + первичные расходы
    }

    if (!Bob.pet.has_pet) return;

    Sber.bank_account -= Bob.pet.food;
    Sber.bank_account -= Bob.pet.toys;

    // ветеринар 3 раза в год (прививки, осмотр, глисты)
    if (month == 2 || month == 6 || month == 10) {
        Bob.pet.vet = 4000;
        Sber.bank_account -= Bob.pet.vet;
    } else {
        Bob.pet.vet = 0;
    }

    // груминг каждые 2 месяца
    if (month % 2 == 0) {
        Bob.pet.grooming = 2500;
        Sber.bank_account -= Bob.pet.grooming;
    } else {
        Bob.pet.grooming = 0;
    }

    float r = inflation / 100.0f / 12.0f;
    Bob.pet.food = (RUB)((float)Bob.pet.food * (1.0f + r));
    Bob.pet.toys = (RUB)((float)Bob.pet.toys * (1.0f + r));
}


// ==================== ПОБОЧНЫЙ ДОХОД ALICE ====================

void Alice_side_income(const int month, const int year) {
    // начинает подрабатывать репетитором с 2028 года
    if (year < 2028) return;

    // 2-3 ученика, нерегулярно
    if (month == 1 || month == 3 || month == 5 || month == 9 || month == 10 || month == 11) {
        Tinkoff.bank_account += 8000;
    }
    if (month == 2 || month == 4) {
        Tinkoff.bank_account += 12000; // больше учеников перед экзаменами
    }
    // летом каникулы, репетиторства нет
}


// ==================== ПЕРЕЕЗД ALICE ====================

void Alice_moving(const int month, const int year) {
    // переезжает в квартиру получше в октябре 2028
    if (month == 10 && year == 2028) {
        Tinkoff.bank_account -= 60000; // грузчики + залог

        Alice.rent.price = 32000;
        Alice.rent.light = 1000;
        Alice.rent.water = 600;
        Alice.rent.electricity = 1500;
        Alice.rent.gas = 500;
        Alice.rent.maintenance = 800;
        Alice.rent.garbage = 200;
        Alice.rent.intercom = 150;
    }
}


// ==================== ДОСРОЧНОЕ ГАШЕНИЕ ИПОТЕКИ BOB ====================

void Bob_mortgage_extra(const int month, const int year) {
    // досрочно гасит в конце каждого года если есть лишние деньги
    if (month == 12 && Bob.mortgage.months_left > 0) {
        if (Sber.bank_account > 200000) {
            RUB extra = 50000;
            Sber.bank_account -= extra;
            Bob.mortgage.total_debt -= extra;
            if (Bob.mortgage.total_debt < 0) Bob.mortgage.total_debt = 0;
        }
    }
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
        Alice_seasonal_food(month);
        Alice_transport(inflation);
        Alice_car(month, year, inflation);
        Alice_rent(inflation);
        Alice_seasonal_utilities(month);
        Alice_health(month, inflation);
        Alice_health_events(month, year);
        Alice_entertainment(month, inflation);
        Alice_subscriptions_update(month, year);
        Alice_clothing(month);
        Alice_education(month, inflation);
        Alice_personal(inflation);
        Alice_care(month, inflation);
        Alice_delivery(inflation);
        Alice_gifts(month);
        Alice_pet(inflation);
        Alice_pet_events(month);
        Alice_deposit_topup(month, year);
        Alice_credit(month, year);
        Alice_side_income(month, year);
        Alice_moving(month, year);
        Alice_life_events(month, year);
        Alice_bank_deals();
        Alice_emergency_check();

        // --- Bob ---
        Bob_salary(month, year);
        Bob_food(inflation);
        Bob_seasonal_food(month);
        Bob_transport(inflation);
        Bob_car(month, inflation);
        Bob_rent(inflation);
        Bob_seasonal_utilities(month);
        Bob_health(month, inflation);
        Bob_health_events(month, year);
        Bob_entertainment(month, inflation);
        Bob_subscriptions_update(month, year);
        Bob_clothing(month);
        Bob_education(month, inflation);
        Bob_personal(inflation);
        Bob_care(month, inflation);
        Bob_delivery(inflation);
        Bob_gifts(month);
        Bob_pet(month, year, inflation);
        Bob_hobby_events(month, year);
        Bob_cleaning(month, year, inflation);
        Bob_fines(month, year);
        Bob_remote_work(month, year);
        Bob_household(month, year);
        Bob_charity(month, year);
        Bob_cashback(month);
        Bob_life_insurance(month, year);
        Bob_deposit_topup(month, year);
        Bob_appliances(month, year);
        Bob_mortgage();
        Bob_mortgage_extra(month, year);
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