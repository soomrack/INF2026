#include <stdio.h>
#include <cstdlib>
#include <time.h>

using RUB = long long int;
using Percent = float;


struct Car {
    bool exist;
    RUB value;
    RUB gas;
};

struct Bank {
    RUB money;
    RUB deposit;
    Percent interest = 14.5;
};

struct Pet {
    bool exist;
    RUB food;
    RUB vet;
};

struct Home {
    bool exist;
    RUB tax;
    RUB utilities;
    RUB rent;
    RUB price;
};

struct Food {
    RUB basic;
    RUB luxury;
};

struct Medical {
    RUB basic;
    RUB premium;
};

struct Child {
    bool exist;
    int age;
    int birth_month;
    RUB food;
    RUB clothes;
    RUB education;
    RUB toys;
    RUB medical;
    RUB teen_expenses;
    RUB older_expenses;
};

struct Family {
    bool has_partner;
    RUB partner_expenses;
    RUB family_events;
};

struct AdvancedHobby {
    RUB gym;
    RUB creative;
    RUB collecting;
    int level;
};

struct Mortgage {
    bool active;
    RUB principal;
    RUB monthly_payment;
    Percent rate;
    int months_left;
};

struct Person {
    bool alive;
    RUB salary;
    struct Food food;
    struct Car car;
    struct Bank VTB;
    struct Bank Sber;
    struct Pet cat;
    struct Pet humster;
    struct Home flat;
    struct Child child;
    struct Family family;
    struct AdvancedHobby advanced_hobby;
    RUB hobby;
    RUB car_tax;
    RUB rent;
    RUB utilities;
    float income_tax_rate;
    RUB taxes_paid;
    RUB subscriptions;
    RUB sport;
    RUB stocks;
    RUB life_insurance;
    int last_travel_month;
    struct Medical medical;
    RUB salary_bonus;
    struct Mortgage mortgage;
    int gambling_level;
    int appetite_level;
    int sociability;
    int ambition;
    int health_habits;
    int impulsiveness;
    int partner_type;
    RUB partner_monthly_effect;
    int leader_type;
    RUB political_tax;
    RUB new_political_expense;
    float death_multiplier;
    bool mobilization_active;
};

struct Person Alice;
struct Person Ben;

// ========== ФУНКЦИИ АЛИСЫ ==========

void alice_salary(const int month, const int year)
{
    if (!Alice.alive) {
        return;
    }

    RUB gross = Alice.salary;

    if ((month == 8) && (year >= 2026)) {
        Alice.salary *= 1.5;
    }

    if (Alice.salary_bonus > 0) {
        gross += Alice.salary_bonus;
    }

    RUB tax = RUB(gross * Alice.income_tax_rate);
    Alice.taxes_paid += tax;
    RUB net = gross - tax;
    Alice.VTB.money += net;
}


void alice_food()
{
    if (!Alice.alive) {
        return;
    }

    Alice.VTB.money -= Alice.food.basic;
    Alice.VTB.money -= Alice.food.luxury;

    Alice.food.basic += RUB(Alice.food.basic * 0.015);
    Alice.food.luxury += RUB(Alice.food.luxury * 0.015);
}


void alice_medical()
{
    if (!Alice.alive) {
        return;
    }

    Alice.VTB.money -= Alice.medical.basic;
    Alice.VTB.money -= Alice.medical.premium;

    Alice.medical.basic += RUB(Alice.medical.basic * 0.015);
    Alice.medical.premium += RUB(Alice.medical.premium * 0.015);
}


void alice_car()
{
    if (!Alice.alive) {
        return;
    }

    if (Alice.car.exist) {
        Alice.VTB.money -= Alice.car.gas;
    } else {
        if (Alice.VTB.deposit > Alice.car.value) {
            Alice.VTB.deposit -= Alice.car.value;
            Alice.car.exist = true;
        }
    }

    Alice.car.gas += RUB(Alice.car.gas * 0.015);
    Alice.car.value += RUB(Alice.car.value * 0.015);
}


void alice_cat(const int month)
{
    if (!Alice.alive) {
        return;
    }

    if (Alice.cat.exist) {
        Alice.VTB.money -= Alice.cat.food;
        if (month % 3 == 0) {
            Alice.VTB.money -= Alice.cat.vet;
        }
    }

    Alice.cat.food += RUB(Alice.cat.food * 0.015);
    Alice.cat.vet += RUB(Alice.cat.vet * 0.015);
}


void alice_hobby()
{
    if (!Alice.alive) {
        return;
    }

    Alice.VTB.money -= Alice.hobby;
    Alice.hobby += RUB(Alice.hobby * 0.015);
}


void alice_car_tax()
{
    if (!Alice.alive) {
        return;
    }

    if (Alice.car.exist) {
        Alice.VTB.money -= Alice.car_tax;
    }

    Alice.car_tax += RUB(Alice.car_tax * 0.015);
}


void alice_house()
{
    if (!Alice.alive) {
        return;
    }

    if (!Alice.flat.exist) {
        Alice.VTB.money -= Alice.rent;
        Alice.VTB.money -= Alice.utilities;
    } else {
        Alice.VTB.money -= Alice.flat.tax;
        Alice.VTB.money -= Alice.utilities;
    }

    Alice.rent += RUB(Alice.rent * 0.015);
    Alice.utilities += RUB(Alice.utilities * 0.015);
}


void alice_subscriptions()
{
    if (!Alice.alive) {
        return;
    }

    Alice.VTB.money -= Alice.subscriptions;
    Alice.subscriptions += RUB(Alice.subscriptions * 0.015);
}


void alice_sport()
{
    if (!Alice.alive) {
        return;
    }

    Alice.VTB.money -= Alice.sport;
    Alice.sport += RUB(Alice.sport * 0.015);
}


void alice_travel(int month, int year)
{
    if (!Alice.alive) {
        return;
    }

    if (month == 7 && Alice.last_travel_month != year) {
        RUB cost = 50000 + rand() % 50000;
        Alice.VTB.money -= cost;
        Alice.last_travel_month = year;
    }
}


void alice_tech_purchase()
{
    if (!Alice.alive) {
        return;
    }

    if (rand() % 100 < 5) {
        RUB cost = 10000 + rand() % 50000;
        Alice.VTB.money -= cost;
    }
}


void alice_stocks()
{
    if (!Alice.alive) {
        return;
    }

    if (Alice.stocks > 0) {
        float change = (rand() % 31 - 10) / 100.0f;
        RUB profit = RUB(Alice.stocks * change);
        Alice.stocks += profit;
    }

    if (Alice.VTB.money > 100000) {
        RUB buy = Alice.VTB.money * 0.1;
        Alice.VTB.money -= buy;
        Alice.stocks += buy;
    }
}


void alice_life_insurance()
{
    if (!Alice.alive) {
        return;
    }

    Alice.VTB.money -= Alice.life_insurance;
    Alice.life_insurance += RUB(Alice.life_insurance * 0.015);
}


void alice_bank_interest()
{
    if (!Alice.alive) {
        return;
    }

    Alice.VTB.deposit += RUB(Alice.VTB.deposit * (Alice.VTB.interest / 12 / 100));
}


void alice_deposit()
{
    if (!Alice.alive) {
        return;
    }

    if (Alice.VTB.money > 0) {
        Alice.VTB.deposit += Alice.VTB.money;
        Alice.VTB.money = 0;
    }
}


void alice_buy_car()
{
    if (!Alice.alive) {
        return;
    }

    if (!Alice.car.exist && Alice.VTB.deposit > Alice.car.value) {
        Alice.VTB.deposit -= Alice.car.value;
        Alice.car.exist = true;
    }
}


void alice_handle_apartment()
{
    if (!Alice.alive) {
        return;
    }
    if (Alice.flat.exist) {
        return;
    }
    if (!Alice.car.exist) {
        return;
    }

    if (Alice.VTB.deposit > Alice.flat.price) {
        Alice.VTB.deposit -= Alice.flat.price;
        Alice.flat.exist = true;
        printf("Алиса купила квартиру за наличные!\n");
    } else if (Alice.VTB.deposit > Alice.flat.price * 0.2) {
        RUB down_payment = Alice.flat.price * 0.2;
        RUB principal = Alice.flat.price - down_payment;
        Alice.VTB.deposit -= down_payment;
        Alice.flat.exist = true;

        Alice.mortgage.active = true;
        Alice.mortgage.principal = principal;
        Alice.mortgage.rate = 9.5;
        Alice.mortgage.months_left = 240;
        Alice.mortgage.monthly_payment = (principal * (1 + Alice.mortgage.rate / 100.0 / 12.0)) / Alice.mortgage.months_left;

        printf("Алиса оформила ипотеку на квартиру (первый взнос %lld руб.)\n", down_payment);
    }
}


void alice_negative_events()
{
    if (!Alice.alive) {
        return;
    }
    if (rand() % 100 >= 10) {
        return;
    }
    int event = rand() % 7;

    switch(event) {
        case 0: {
            RUB fine = 2000 + rand() % 10000;
            Alice.VTB.money -= fine;
            break;
        }
        case 1: {
            RUB repair = 5000 + rand() % 15000;
            Alice.VTB.money -= repair;
            break;
        }
        case 2: {
            RUB lost = 1000 + rand() % 5000;
            Alice.VTB.money -= lost;
            break;
        }
        case 3: {
            RUB medicine = 3000 + rand() % 12000;
            Alice.VTB.money -= medicine;
            break;
        }
        case 4: {
            RUB debt = 5000 + rand() % 10000;
            Alice.VTB.money -= debt;
            break;
        }
        case 5: {
            RUB phone = 5000 + rand() % 10000;
            Alice.VTB.money -= phone;
            break;
        }
        case 6: {
            RUB extra = 8000 + rand() % 20000;
            Alice.VTB.money -= extra;
            break;
        }
    }
}


void alice_positive_events()
{
    if (!Alice.alive) {
        return;
    }
    if (rand() % 100 >= 20) {
        return;
    }

    int event = rand() % 5;

    switch(event) {
        case 0: {
            RUB premia = Alice.salary * (0.1 + (rand() % 40) / 100.0);
            Alice.VTB.money += premia;
            break;
        }
        case 1: {
            RUB gift = Alice.hobby + rand() % 40000;
            Alice.VTB.money += gift;
            break;
        }
        case 2: {
            RUB kesbek = Alice.salary * 0.05 + rand() % 10000;
            Alice.VTB.money += kesbek;
            break;
        }
        case 3: {
            RUB inheritance = 100000 + rand() % 500000;
            Alice.VTB.money += inheritance;
            break;
        }
        case 4: {
            RUB bonus = Alice.salary * 0.15;
            Alice.VTB.money += bonus;
            break;
        }
    }
}


void alice_death_event(int month, int year)
{
    if (!Alice.alive) {
        return;
    }

    int death_chance = 6 - (Alice.health_habits / 2);
    if (death_chance < 1) death_chance = 1;
    if (rand() % 1000 < death_chance) {
        Alice.alive = false;
        printf("Алиса умер(ла) в %d.%d! (здоровье: %d/10)\n", month, year, Alice.health_habits);
    }
}


void alice_deneg_net()
{
    if (!Alice.alive) {
        return;
    }

    if (Alice.VTB.money < 0) {
        RUB needed = -Alice.VTB.money;
        if (Alice.VTB.deposit >= needed) {
            Alice.VTB.deposit -= needed;
            Alice.VTB.money = 0;
        } else {
            Alice.VTB.money = 0;
        }
    }
}


void alice_children(const int month)
{
    if (!Alice.alive) {
        return;
    }

    if (!Alice.child.exist) {
        return;
    }

    RUB total = Alice.child.food +
                Alice.child.clothes +
                Alice.child.education +
                Alice.child.toys +
                Alice.child.medical;

    if (Alice.child.age >= 16) {
        total += Alice.child.older_expenses;
    } else if (Alice.child.age >= 12) {
        total += Alice.child.teen_expenses;
    }

    Alice.VTB.money -= total;

    Alice.child.food += RUB(Alice.child.food * 0.015);
    Alice.child.clothes += RUB(Alice.child.clothes * 0.015);
    Alice.child.education += RUB(Alice.child.education * 0.015);
    Alice.child.toys += RUB(Alice.child.toys * 0.015);
    Alice.child.medical += RUB(Alice.child.medical * 0.015);
    Alice.child.teen_expenses += RUB(Alice.child.teen_expenses * 0.015);
    Alice.child.older_expenses += RUB(Alice.child.older_expenses * 0.015);

    if (month == Alice.child.birth_month) {
        Alice.child.age++;
    }
}


void alice_family(const int month)
{
    if (!Alice.alive) {
        return;
    }

    RUB total = 0;

    if (Alice.family.has_partner) {
        total += Alice.family.partner_expenses;
    }

    if (rand() % 20 == 0) {
        int event = rand() % 4;
        switch(event) {
            case 0: {
                total += 45000 + rand() % 30000;
                break;
            }
            case 1: {
                total += 8000 + rand() % 15000;
                break;
            }
            case 2: {
                total += 12000 + rand() % 18000;
                break;
            }
            case 3: {
                total += 7000 + rand() % 12000;
                break;
            }
        }
        Alice.family.family_events++;
    }

    Alice.VTB.money -= total;

    Alice.family.partner_expenses += RUB(Alice.family.partner_expenses * 0.015);
}


void alice_hobby_advanced()
{
    if (!Alice.alive) {
        return;
    }

    RUB total = Alice.advanced_hobby.gym +
                Alice.advanced_hobby.creative +
                Alice.advanced_hobby.collecting;

    Alice.VTB.money -= total;

    if (rand() % 8 == 0) {
        Alice.advanced_hobby.level++;
        if (Alice.advanced_hobby.level > 10) {
            Alice.advanced_hobby.level = 10;
        }
    }

    Alice.advanced_hobby.gym += RUB(Alice.advanced_hobby.gym * 0.015);
    Alice.advanced_hobby.creative += RUB(Alice.advanced_hobby.creative * 0.015);
    Alice.advanced_hobby.collecting += RUB(Alice.advanced_hobby.collecting * 0.015);

    if (Alice.advanced_hobby.level >= 7) {
        Alice.advanced_hobby.gym += 2000;
        Alice.advanced_hobby.creative += 1500;
    }
}


void alice_mortgage_payment()
{
    if (!Alice.alive || !Alice.mortgage.active) {
        return;
    }

    Alice.VTB.money -= Alice.mortgage.monthly_payment;
    Alice.mortgage.principal -= Alice.mortgage.monthly_payment * 0.7;
    Alice.mortgage.months_left--;

    if (Alice.mortgage.months_left <= 0) {
        Alice.mortgage.active = false;
        printf("Алиса полностью выплатила ипотеку!\n");
    }
}

// ========== ФУНКЦИИ БЕНА ==========

void ben_salary(const int month, const int year)
{
    if (!Ben.alive) {
        return;
    }

    RUB gross = Ben.salary;

    if (month == 12) {
        Ben.salary *= 1.35;
    }

    if (Ben.salary_bonus > 0) {
        gross += Ben.salary_bonus;
    }

    RUB tax = RUB(gross * Ben.income_tax_rate);
    Ben.taxes_paid += tax;
    RUB net = gross - tax;
    Ben.Sber.money += net;
}


void ben_food()
{
    if (!Ben.alive) {
        return;
    }

    Ben.Sber.money -= Ben.food.basic;
    Ben.Sber.money -= Ben.food.luxury;

    Ben.food.basic += RUB(Ben.food.basic * 0.015);
    Ben.food.luxury += RUB(Ben.food.luxury * 0.015);
}


void ben_medical()
{
    if (!Ben.alive) {
        return;
    }

    Ben.Sber.money -= Ben.medical.basic;
    Ben.Sber.money -= Ben.medical.premium;

    Ben.medical.basic += RUB(Ben.medical.basic * 0.015);
    Ben.medical.premium += RUB(Ben.medical.premium * 0.015);
}


void ben_car()
{
    if (!Ben.alive) {
        return;
    }

    if (Ben.car.exist) {
        Ben.Sber.money -= Ben.car.gas;
    }

    Ben.car.gas += RUB(Ben.car.gas * 0.015);
    Ben.car.value += RUB(Ben.car.value * 0.015);
}


void ben_cat(int month)
{
    if (!Ben.alive) {
        return;
    }

    if (Ben.humster.exist) {
        Ben.Sber.money -= Ben.humster.food;
        if (month % 3 == 0) {
            Ben.Sber.money -= Ben.humster.vet;
        }
    }

    Ben.humster.food += RUB(Ben.humster.food * 0.015);
    Ben.humster.vet += RUB(Ben.humster.vet * 0.015);
}


void ben_hobby()
{
    if (!Ben.alive) {
        return;
    }

    Ben.Sber.money -= Ben.hobby;
    Ben.hobby += RUB(Ben.hobby * 0.015);
}


void ben_car_tax()
{
    if (!Ben.alive) {
        return;
    }

    if (Ben.car.exist) {
        Ben.Sber.money -= Ben.car_tax;
    }

    Ben.car_tax += RUB(Ben.car_tax * 0.015);
}


void ben_house()
{
    if (!Ben.alive) {
        return;
    }

    Ben.Sber.money -= Ben.rent;
    Ben.Sber.money -= Ben.utilities;

    Ben.rent += RUB(Ben.rent * 0.015);
    Ben.utilities += RUB(Ben.utilities * 0.015);
}


void ben_subscriptions()
{
    if (!Ben.alive) {
        return;
    }

    Ben.Sber.money -= Ben.subscriptions;
    Ben.subscriptions += RUB(Ben.subscriptions * 0.015);
}


void ben_sport()
{
    if (!Ben.alive) {
        return;
    }

    Ben.Sber.money -= Ben.sport;
    Ben.sport += RUB(Ben.sport * 0.015);
}


void ben_travel(int month, int year)
{
    if (!Ben.alive) {
        return;
    }

    if (month == 7 && Ben.last_travel_month != year) {
        RUB cost = 50000 + rand() % 50000;
        Ben.Sber.money -= cost;
        Ben.last_travel_month = year;
    }
}


void ben_tech_purchase()
{
    if (!Ben.alive) {
        return;
    }

    if (rand() % 100 < 5) {
        RUB cost = 10000 + rand() % 50000;
        Ben.Sber.money -= cost;
    }
}


void ben_stocks()
{
    if (!Ben.alive) {
        return;
    }

    if (Ben.stocks > 0) {
        float change = (rand() % 31 - 10) / 100.0f;
        RUB profit = RUB(Ben.stocks * change);
        Ben.stocks += profit;
    }

    if (Ben.Sber.money > 100000) {
        RUB buy = Ben.Sber.money * 0.1;
        Ben.Sber.money -= buy;
        Ben.stocks += buy;
    }
}


void ben_life_insurance()
{
    if (!Ben.alive) {
        return;
    }

    Ben.Sber.money -= Ben.life_insurance;
    Ben.life_insurance += RUB(Ben.life_insurance * 0.015);
}


void ben_bank_interest()
{
    if (!Ben.alive) {
        return;
    }

    Ben.Sber.deposit += RUB(Ben.Sber.deposit * (Ben.Sber.interest / 12 / 100));
}


void ben_deposit()
{
    if (!Ben.alive) {
        return;
    }

    if (Ben.Sber.money > 0) {
        Ben.Sber.deposit += Ben.Sber.money;
        Ben.Sber.money = 0;
    }
}


void ben_buy_car()
{
    if (!Ben.alive) {
        return;
    }

    if (!Ben.car.exist && Ben.Sber.deposit > Ben.car.value) {
        Ben.Sber.deposit -= Ben.car.value;
        Ben.car.exist = true;
    }
}


void ben_handle_apartment()
{
    if (!Ben.alive) {
        return;
    }
    if (Ben.flat.exist) {
        return;
    }
    if (!Ben.car.exist) {
        return;
    }

    if (Ben.Sber.deposit > Ben.flat.price) {
        Ben.Sber.deposit -= Ben.flat.price;
        Ben.flat.exist = true;
        printf("Бен купил квартиру за наличные!\n");
    } else if (Ben.Sber.deposit > Ben.flat.price * 0.2) {
        RUB down_payment = Ben.flat.price * 0.2;
        RUB principal = Ben.flat.price - down_payment;
        Ben.Sber.deposit -= down_payment;
        Ben.flat.exist = true;

        Ben.mortgage.active = true;
        Ben.mortgage.principal = principal;
        Ben.mortgage.rate = 9.5;
        Ben.mortgage.months_left = 240;
        Ben.mortgage.monthly_payment = (principal * (1 + Ben.mortgage.rate / 100.0 / 12.0)) / Ben.mortgage.months_left;

        printf("Бен оформил ипотеку на квартиру (первый взнос %lld руб.)\n", down_payment);
    }
}


void ben_negative_events()
{
    if (!Ben.alive) {
        return;
    }
    if (rand() % 100 >= 10) {
        return;
    }

    int event = rand() % 7;

    switch(event) {
        case 0: {
            RUB fine = 2000 + rand() % 10000;
            Ben.Sber.money -= fine;
            break;
        }
        case 1: {
            RUB repair = 5000 + rand() % 15000;
            Ben.Sber.money -= repair;
            break;
        }
        case 2: {
            RUB lost = 1000 + rand() % 5000;
            Ben.Sber.money -= lost;
            break;
        }
        case 3: {
            RUB medicine = 3000 + rand() % 12000;
            Ben.Sber.money -= medicine;
            break;
        }
        case 4: {
            RUB debt = 5000 + rand() % 10000;
            Ben.Sber.money -= debt;
            break;
        }
        case 5: {
            RUB phone = 5000 + rand() % 10000;
            Ben.Sber.money -= phone;
            break;
        }
        case 6: {
            RUB extra = 8000 + rand() % 20000;
            Ben.Sber.money -= extra;
            break;
        }
    }
}


void ben_positive_events()
{
    if (!Ben.alive) {
        return;
    }
    if (rand() % 100 >= 20) {
        return;
    }

    int event = rand() % 5;

    switch(event) {
        case 0: {
            RUB premia = Ben.salary * (0.1 + (rand() % 40) / 100.0);
            Ben.Sber.money += premia;
            break;
        }
        case 1: {
            RUB gift = Ben.hobby + rand() % 40000;
            Ben.Sber.money += gift;
            break;
        }
        case 2: {
            RUB kesbek = Ben.salary * 0.05 + rand() % 10000;
            Ben.Sber.money += kesbek;
            break;
        }
        case 3: {
            RUB inheritance = 100000 + rand() % 500000;
            Ben.Sber.money += inheritance;
            break;
        }
        case 4: {
            RUB bonus = Ben.salary * 0.15;
            Ben.Sber.money += bonus;
            break;
        }
    }
}


void ben_death_event(int month, int year)
{
    if (!Ben.alive) {
        return;
    }

    int death_chance = 2 - (Ben.health_habits / 3);
    if (death_chance < 1) death_chance = 1;
    death_chance = (int)(death_chance * Ben.death_multiplier);
    if (death_chance > 50) death_chance = 50;
    if (rand() % 1000 < death_chance) {
        Ben.alive = false;
        if (Ben.mobilization_active) {
            printf("Бен умер в %d.%d! (здоровье: %d/10, мобилизация/жёсткий режим!)\n", month, year, Ben.health_habits);
        } else {
            printf("Бен умер в %d.%d! (здоровье: %d/10)\n", month, year, Ben.health_habits);
        }
    }
}


void ben_deneg_net()
{
    if (!Ben.alive) {
        return;
    }

    if (Ben.Sber.money < 0) {
        RUB needed = -Ben.Sber.money;
        if (Ben.Sber.deposit >= needed) {
            Ben.Sber.deposit -= needed;
            Ben.Sber.money = 0;
        } else {
            Ben.Sber.money = 0;
        }
    }
}


void ben_children(const int month)
{
    if (!Ben.alive) {
        return;
    }

    if (!Ben.child.exist) {
        return;
    }

    RUB total = Ben.child.food +
                Ben.child.clothes +
                Ben.child.education +
                Ben.child.toys +
                Ben.child.medical;

    if (Ben.child.age >= 16) {
        total += Ben.child.older_expenses;
    } else if (Ben.child.age >= 12) {
        total += Ben.child.teen_expenses;
    }

    Ben.Sber.money -= total;

    Ben.child.food += RUB(Ben.child.food * 0.015);
    Ben.child.clothes += RUB(Ben.child.clothes * 0.015);
    Ben.child.education += RUB(Ben.child.education * 0.015);
    Ben.child.toys += RUB(Ben.child.toys * 0.015);
    Ben.child.medical += RUB(Ben.child.medical * 0.015);
    Ben.child.teen_expenses += RUB(Ben.child.teen_expenses * 0.015);
    Ben.child.older_expenses += RUB(Ben.child.older_expenses * 0.015);

    if (month == Ben.child.birth_month) {
        Ben.child.age++;
    }
}


void ben_family(const int month)
{
    if (!Ben.alive) {
        return;
    }

    RUB total = 0;

    if (Ben.family.has_partner) {
        total += Ben.family.partner_expenses;
    }

    if (rand() % 20 == 0) {
        int event = rand() % 4;
        switch(event) {
            case 0: {
                total += 40000 + rand() % 25000;
                break;
            }
            case 1: {
                total += 7000 + rand() % 14000;
                break;
            }
            case 2: {
                total += 10000 + rand() % 16000;
                break;
            }
            case 3: {
                total += 6000 + rand() % 10000;
                break;
            }
        }
        Ben.family.family_events++;
    }

    Ben.Sber.money -= total;

    Ben.family.partner_expenses += RUB(Ben.family.partner_expenses * 0.015);
}


void ben_hobby_advanced()
{
    if (!Ben.alive) {
        return;
    }

    RUB total = Ben.advanced_hobby.gym +
                Ben.advanced_hobby.creative +
                Ben.advanced_hobby.collecting;

    Ben.Sber.money -= total;

    if (rand() % 8 == 0) {
        Ben.advanced_hobby.level++;
        if (Ben.advanced_hobby.level > 10) {
            Ben.advanced_hobby.level = 10;
        }
    }

    Ben.advanced_hobby.gym += RUB(Ben.advanced_hobby.gym * 0.015);
    Ben.advanced_hobby.creative += RUB(Ben.advanced_hobby.creative * 0.015);
    Ben.advanced_hobby.collecting += RUB(Ben.advanced_hobby.collecting * 0.015);

    if (Ben.advanced_hobby.level >= 7) {
        Ben.advanced_hobby.gym += 1800;
        Ben.advanced_hobby.creative += 1300;
    }
}


void ben_mortgage_payment()
{
    if (!Ben.alive || !Ben.mortgage.active) {
        return;
    }

    Ben.Sber.money -= Ben.mortgage.monthly_payment;
    Ben.mortgage.principal -= Ben.mortgage.monthly_payment * 0.7;
    Ben.mortgage.months_left--;

    if (Ben.mortgage.months_left <= 0) {
        Ben.mortgage.active = false;
        printf("Бен полностью выплатил ипотеку!\n");
    }
}

// ========== ИНИЦИАЛИЗАЦИЯ ==========

void alice_init()
{
    Alice.alive = true;
    Alice.salary = 180000;
    Alice.food.basic = 15000;
    Alice.food.luxury = 8000;
    Alice.medical.basic = 3000;
    Alice.medical.premium = 2000;
    Alice.hobby = 25000;
    Alice.sport = 5000;

    Alice.car.value = 2000000;
    Alice.car.gas = 15000;
    Alice.car.exist = false;

    Alice.cat.food = 5000;
    Alice.cat.vet = 12000;
    Alice.cat.exist = true;

    Alice.VTB.money = 0;
    Alice.VTB.deposit = 0;
    Alice.Sber.money = 0;
    Alice.Sber.deposit = 0;

    Alice.flat.exist = false;
    Alice.flat.price = 6000000;
    Alice.flat.rent = 30000;
    Alice.flat.tax = 6000;
    Alice.flat.utilities = 5000;

    Alice.car_tax = 3000;
    Alice.rent = 50000;
    Alice.utilities = 10000;
    Alice.income_tax_rate = 0.13;
    Alice.taxes_paid = 0;
    Alice.subscriptions = 3000;
    Alice.stocks = 0;
    Alice.life_insurance = 3000;
    Alice.last_travel_month = 0;
    Alice.salary_bonus = 0;

    Alice.child.exist = true;
    Alice.child.age = 5;
    Alice.child.birth_month = 8;
    Alice.child.food = 8000;
    Alice.child.clothes = 6000;
    Alice.child.education = 15000;
    Alice.child.toys = 4000;
    Alice.child.medical = 5000;
    Alice.child.teen_expenses = 25000;
    Alice.child.older_expenses = 13000;

    Alice.family.has_partner = false;
    Alice.family.partner_expenses = 0;
    Alice.family.family_events = 0;

    Alice.advanced_hobby.gym = 7000;
    Alice.advanced_hobby.creative = 4000;
    Alice.advanced_hobby.collecting = 3000;
    Alice.advanced_hobby.level = 3;

    Alice.mortgage.active = false;
    Alice.mortgage.principal = 0;
    Alice.mortgage.monthly_payment = 0;
    Alice.mortgage.rate = 0;
    Alice.mortgage.months_left = 0;

    Alice.gambling_level = 3 + rand() % 3;
    Alice.appetite_level = 4 + rand() % 3;
    Alice.sociability = 5 + rand() % 3;
    Alice.ambition = 4 + rand() % 4;
    Alice.health_habits = 3 + rand() % 5;
    Alice.impulsiveness = 3 + rand() % 4;
    Alice.partner_type = 0;
    Alice.partner_monthly_effect = 0;

    Alice.leader_type = 0;
    Alice.political_tax = 2000;
    Alice.new_political_expense = 4000;
    Alice.death_multiplier = 1.0f;
    Alice.mobilization_active = false;
}


void ben_init()
{
    Ben.alive = true;
    Ben.salary = 200000;
    Ben.food.basic = 18000;
    Ben.food.luxury = 7000;
    Ben.medical.basic = 2500;
    Ben.medical.premium = 1500;
    Ben.hobby = 15000;
    Ben.sport = 4000;

    Ben.car.value = 1500000;
    Ben.car.gas = 12000;
    Ben.car.exist = false;

    Ben.humster.food = 4000;
    Ben.humster.vet = 10000;
    Ben.humster.exist = true;

    Ben.Sber.money = 0;
    Ben.Sber.deposit = 0;

    Ben.car_tax = 2500;
    Ben.rent = 40000;
    Ben.utilities = 8000;
    Ben.income_tax_rate = 0.13;
    Ben.taxes_paid = 0;
    Ben.subscriptions = 4000;
    Ben.stocks = 0;
    Ben.life_insurance = 2500;
    Ben.last_travel_month = 0;
    Ben.salary_bonus = 0;

    Ben.flat.exist = false;
    Ben.flat.price = 5000000;
    Ben.flat.rent = 24000;
    Ben.flat.tax = 4000;
    Ben.flat.utilities = 3000;

    Ben.child.exist = true;
    Ben.child.age = 3;
    Ben.child.birth_month = 6;
    Ben.child.food = 7000;
    Ben.child.clothes = 5500;
    Ben.child.education = 12000;
    Ben.child.toys = 3500;
    Ben.child.medical = 4500;
    Ben.child.teen_expenses = 45000;
    Ben.child.older_expenses = 8000;

    Ben.family.has_partner = false;
    Ben.family.partner_expenses = 0;
    Ben.family.family_events = 0;

    Ben.advanced_hobby.gym = 6500;
    Ben.advanced_hobby.creative = 3500;
    Ben.advanced_hobby.collecting = 4500;
    Ben.advanced_hobby.level = 4;

    Ben.mortgage.active = false;
    Ben.mortgage.principal = 0;
    Ben.mortgage.monthly_payment = 0;
    Ben.mortgage.rate = 0;
    Ben.mortgage.months_left = 0;

    Ben.gambling_level = 2 + rand() % 4;
    Ben.appetite_level = 3 + rand() % 3;
    Ben.sociability = 4 + rand() % 3;
    Ben.ambition = 5 + rand() % 3;
    Ben.health_habits = 4 + rand() % 4;
    Ben.impulsiveness = 2 + rand() % 3;
    Ben.partner_type = 0;
    Ben.partner_monthly_effect = 0;

    Ben.leader_type = 0;
    Ben.political_tax = 2000;
    Ben.new_political_expense = 4000;
    Ben.death_multiplier = 1.0f;
    Ben.mobilization_active = false;
}


void alice_update_yearly_traits(int year)
{
    if (!Alice.alive) return;

    int old_gambling = Alice.gambling_level;
    int change = (rand() % 4) - 1;
    Alice.gambling_level = Alice.gambling_level + change;
    if (Alice.gambling_level < 0) Alice.gambling_level = 0;
    if (Alice.gambling_level > 10) Alice.gambling_level = 10;

    if (Alice.gambling_level > old_gambling) {
        printf("  Алиса стала более азартной! Уровень вырос с %d до %d.\n", old_gambling, Alice.gambling_level);
        printf("  Это привело к увеличению расходов на развлечения и хобби.\n");
        Alice.hobby += 3000 * Alice.gambling_level;
        Alice.advanced_hobby.gym += 500 * Alice.gambling_level;
        Alice.advanced_hobby.creative += 400 * Alice.gambling_level;
    } else if (Alice.gambling_level < old_gambling) {
        printf("  Алиса стала менее азартной. Уровень снизился с %d до %d.\n", old_gambling, Alice.gambling_level);
    }

    Alice.impulsiveness = (Alice.impulsiveness + Alice.gambling_level / 3);
    if (Alice.impulsiveness > 10) Alice.impulsiveness = 10;

    int old_appetite = Alice.appetite_level;
    change = (rand() % 3) - 1;
    Alice.appetite_level += change;
    if (Alice.appetite_level < 0) Alice.appetite_level = 0;
    if (Alice.appetite_level > 10) Alice.appetite_level = 10;

    if (Alice.appetite_level != old_appetite) {
        printf("  Уровень аппетита Алисы изменился с %d на %d.\n", old_appetite, Alice.appetite_level);
        printf("   Еда теперь обходится дороже (больше базовых продуктов и походов в рестораны).\n");
    }

    float appetite_factor = 1.0f + (Alice.appetite_level * 0.02f);
    Alice.food.basic = RUB(Alice.food.basic * appetite_factor * 1.015);
    Alice.food.luxury = RUB(Alice.food.luxury * appetite_factor * 1.015);
    printf("  Расходы на еду пересчитаны с учётом аппетита и инфляции.\n");

    int old_soci = Alice.sociability;
    Alice.sociability += (rand() % 3) - 1;
    if (Alice.sociability < 0) Alice.sociability = 0;
    if (Alice.sociability > 10) Alice.sociability = 10;

    if (Alice.sociability > old_soci) {
        printf("  Алиса стала более общительной! Теперь чаще ходит на встречи, вечеринки.\n");
        Alice.family.partner_expenses += 2000;
        Alice.advanced_hobby.collecting += 1500;
    }

    int old_amb = Alice.ambition;
    Alice.ambition += (rand() % 3) - 1;
    if (Alice.ambition < 0) Alice.ambition = 0;
    if (Alice.ambition > 10) Alice.ambition = 10;

    if (Alice.ambition > 7) {
        printf("  Алиса очень амбициозна! Это даёт бонус к зарплате, но увеличивает стресс.\n");
        Alice.salary = RUB(Alice.salary * 1.03);
        Alice.medical.basic += 1500;
    } else if (Alice.ambition < 3) {
        printf("  Амбициозность снизилась - меньше стресса, но и меньше зарплата.\n");
    }

    int old_health = Alice.health_habits;
    Alice.health_habits += (rand() % 3) - 1;
    if (Alice.health_habits < 0) Alice.health_habits = 0;
    if (Alice.health_habits > 10) Alice.health_habits = 10;

    if (Alice.health_habits > old_health) {
        printf("  Алиса стала вести более здоровый образ жизни! Мед. расходы снизились.\n");
        Alice.medical.basic = RUB(Alice.medical.basic * 0.9);
        Alice.life_insurance = RUB(Alice.life_insurance * 0.95);
    }

    int old_imp = Alice.impulsiveness;
    Alice.impulsiveness += (rand() % 3) - 1;
    if (Alice.impulsiveness < 0) Alice.impulsiveness = 0;
    if (Alice.impulsiveness > 10) Alice.impulsiveness = 10;

    if (Alice.impulsiveness > 6) {
        printf("  Алиса стала очень импульсивной! В этом году возможны неожиданные траты.\n");
    }

    printf("  Итог изменений личности Алисы за год: gambling=%d, appetite=%d, sociability=%d, ambition=%d, health=%d, impuls=%d\n",
           Alice.gambling_level, Alice.appetite_level, Alice.sociability, Alice.ambition, Alice.health_habits, Alice.impulsiveness);
}


void alice_check_wedding(int year)
{
    if (!Alice.alive || Alice.family.has_partner) return;

    int wedding_chance = 6 + (Alice.sociability / 2);
    if (rand() % 100 < wedding_chance) {
        Alice.family.has_partner = true;
        Alice.partner_type = rand() % 3;

        if (Alice.partner_type == 1) {
            Alice.partner_monthly_effect = 15000 + rand() % 25000;
            printf("\n [АЛИСА] В %d году Алиса вышла замуж! Партнёр — щедрый человек, который будет вносить %lld руб./мес. в семейный бюджет.\n", year, Alice.partner_monthly_effect * 2);
            printf("   Свадьба прошла весело, много гостей, подарки. Алиса счастлива!\n");
            Alice.family.family_events += 5;
            Alice.sociability += 1;
        } else if (Alice.partner_type == 2) {
            Alice.partner_monthly_effect = - (12000 + rand() % 18000);
            printf("\n [АЛИСА] В %d году Алиса вышла замуж! Но партнёр оказался расточительным — будет тратить %lld руб./мес. из её денег.\n", year, -Alice.partner_monthly_effect);
            printf("   Свадьба была пышной, теперь нужно быть осторожнее с финансами...\n");
            Alice.impulsiveness += 2;
        } else {
            Alice.partner_monthly_effect = 2000 + rand() % 5000;
            printf("\n [АЛИСА] В %d году Алиса вышла замуж! Партнёр обычный, вносит небольшой вклад %lld руб./мес.\n", year, Alice.partner_monthly_effect);
            printf("   Свадьба скромная, но милая. Желаем счастья!\n");
        }

        Alice.family.partner_expenses = 8000 + rand() % 12000;
        Alice.advanced_hobby.level += 1;
        if (Alice.partner_type == 1) Alice.ambition += 1;
    }
}


void ben_update_yearly_traits(int const year)
{
    if (!Ben.alive) return;

    printf("\n=== Бен. Ежегодное обновление личности (год %d) ===\n", year);

    int old_gambling = Ben.gambling_level;
    int change = (rand() % 4) - 1;
    Ben.gambling_level += change;
    if (Ben.gambling_level < 0) Ben.gambling_level = 0;
    if (Ben.gambling_level > 10) Ben.gambling_level = 10;

    if (Ben.gambling_level > old_gambling) {
        printf("  Бен стал более азартным! Уровень вырос с %d до %d.\n", old_gambling, Ben.gambling_level);
        printf("  → Увеличены расходы на хобби и развлечения.\n");
        Ben.hobby += 2500 * Ben.gambling_level;
        Ben.advanced_hobby.gym += 600 * Ben.gambling_level;
    }

    Ben.impulsiveness = (Ben.impulsiveness + Ben.gambling_level / 3);
    if (Ben.impulsiveness > 10) Ben.impulsiveness = 10;

    int old_appetite = Ben.appetite_level;
    change = (rand() % 3) - 1;
    Ben.appetite_level += change;
    if (Ben.appetite_level < 0) Ben.appetite_level = 0;
    if (Ben.appetite_level > 10) Ben.appetite_level = 10;

    if (Ben.appetite_level != old_appetite) {
        printf("  Уровень аппетита Бена изменился с %d на %d.\n", old_appetite, Ben.appetite_level);
    }
    float appetite_factor = 1.0f + (Ben.appetite_level * 0.02f);
    Ben.food.basic = RUB(Ben.food.basic * appetite_factor * 1.015);
    Ben.food.luxury = RUB(Ben.food.luxury * appetite_factor * 1.015);

    int old_soci = Ben.sociability;
    Ben.sociability += (rand() % 3) - 1;
    if (Ben.sociability < 0) Ben.sociability = 0;
    if (Ben.sociability > 10) Ben.sociability = 10;

    if (Ben.sociability > old_soci) {
        printf("  Бен стал более общительным.\n");
        Ben.family.partner_expenses += 1500;
    }

    int old_amb = Ben.ambition;
    Ben.ambition += (rand() % 3) - 1;
    if (Ben.ambition < 0) Ben.ambition = 0;
    if (Ben.ambition > 10) Ben.ambition = 10;

    if (Ben.ambition > 7) {
        printf("  Бен очень амбициозен! +3% к зарплате, но +стресс.\n");
        Ben.salary = RUB(Ben.salary * 1.03);
        Ben.medical.basic += 1200;
    }

    int old_health = Ben.health_habits;
    Ben.health_habits += (rand() % 3) - 1;
    if (Ben.health_habits < 0) Ben.health_habits = 0;
    if (Ben.health_habits > 10) Ben.health_habits = 10;

    if (Ben.health_habits > old_health) {
        printf("  Бен стал более здоровым! Мед. расходы ↓.\n");
        Ben.medical.basic = RUB(Ben.medical.basic * 0.92);
    }

    int old_imp = Ben.impulsiveness;
    Ben.impulsiveness += (rand() % 3) - 1;
    if (Ben.impulsiveness < 0) Ben.impulsiveness = 0;
    if (Ben.impulsiveness > 10) Ben.impulsiveness = 10;

    if (Ben.impulsiveness > 6) {
        printf("  Бен стал импульсивным - возможны неожиданные покупки.\n");
    }

    printf("  Итог Бена: gambling=%d, appetite=%d, sociability=%d, ambition=%d, health=%d, impuls=%d\n",
           Ben.gambling_level, Ben.appetite_level, Ben.sociability, Ben.ambition, Ben.health_habits, Ben.impulsiveness);
}

void ben_check_wedding(int year)
{
    if (!Ben.alive || Ben.family.has_partner) return;

    int wedding_chance = 5 + (Ben.sociability / 2);
    if (rand() % 100 < wedding_chance) {
        Ben.family.has_partner = true;
        Ben.partner_type = rand() % 3;

        if (Ben.partner_type == 1) {
            Ben.partner_monthly_effect = 18000 + rand() % 22000;
            printf("\n [БЕН] В %d году Бен женился! Партнёр щедрый, +%lld руб./мес. в бюджет.\n", year, Ben.partner_monthly_effect);
            printf("   Свадьба в хорошем ресторане, много друзей. Бен доволен!\n");
            Ben.family.family_events += 4;
            Ben.ambition += 1;
        } else if (Ben.partner_type == 2) {
            Ben.partner_monthly_effect = - (10000 + rand() % 15000);
            printf("\n [БЕН] В %d году Бен женился! Партнёр расточительный, -%lld руб./мес.\n", year, -Ben.partner_monthly_effect);
            printf("   Свадьба была дорогой, теперь финансы под контролем...\n");
            Ben.impulsiveness += 1;
        } else {
            Ben.partner_monthly_effect = 3000 + rand() % 4000;
            printf("\n [БЕН] В %d году Бен женился! Обычный партнёр, +%lld руб./мес.\n", year, Ben.partner_monthly_effect);
            printf("   Скромная свадьба, но тёплая. Поздравляем!\n");
        }

        Ben.family.partner_expenses = 6000 + rand() % 10000;
        Ben.advanced_hobby.level += 1;
    }
}


void update_politics(int year)
{
    if (rand() % 100 >= 18) {
        return; 
    }

    printf("\n=== [ПОЛИТИКА] %d год: ну что, выборы прошли, смена власти или реформы ===\n", year);
    printf("  Текущий лидер был тип: %d (0=нейтрал, 1=либерал, 2=консерватор, 3=авторитар)\n", Alice.leader_type);

    int old_leader = Alice.leader_type;
    int new_leader = rand() % 4;

    if (rand() % 10 < 2 && old_leader != 0) {
        new_leader = old_leader;
        printf("  Сохранился текущий курс (стабильность 20%% шанс).\n");
    } else {
        Alice.leader_type = new_leader;
        Ben.leader_type = new_leader;
        printf("  Новый лидер/режим: тип %d\n", new_leader);
    }

    Alice.mobilization_active = false;
    Ben.mobilization_active = false;
    Alice.death_multiplier = 1.0f;
    Ben.death_multiplier = 1.0f;
    switch (new_leader) {
        case 0: {
            printf("  К власти пришёл какой-то умеренный технократ, всё стабильно, без резких движений.\n");
            printf("  → Налоги чуть опустили для бизнеса, реформ почти нет, спокойно.\n");
            Alice.income_tax_rate = 0.12f;
            Ben.income_tax_rate = 0.12f;
            Alice.political_tax = RUB(Alice.political_tax * 0.8);
            Ben.political_tax = RUB(Ben.political_tax * 0.8);
            Alice.new_political_expense = 3500;
            Ben.new_political_expense = 3500;

            if (rand() % 2 == 0) {
                Alice.utilities = RUB(Alice.utilities * 0.95);
                Ben.utilities = RUB(Ben.utilities * 0.95);
            }
            printf("  Эффект: спокойный год, расходы на политику минимальны.\n");
            break;
        }
        case 1: {
            printf("  Либерал победил, ура! Налоги снизили, но теперь больше трат на соц.выплаты и больницы.\n");
            printf("  → Подоходный налог упал на пару процентов, зато пособия и медицина в плюсе.\n");
            Alice.income_tax_rate = (Alice.income_tax_rate - 0.035f < 0.07f ? 0.07f : Alice.income_tax_rate - 0.035f);
            Ben.income_tax_rate = (Ben.income_tax_rate - 0.035f < 0.07f ? 0.07f : Ben.income_tax_rate - 0.035f);
            Alice.political_tax = 0;
            Ben.political_tax = 0;
            Alice.new_political_expense = 12000 + rand() % 8000;
            Ben.new_political_expense = 11000 + rand() % 7000;
  
            Alice.death_multiplier = 0.85f;
            Ben.death_multiplier = 0.9f;
            printf("  Эффект: больше денег в кармане, но выше расходы на 'социалку'. Мобилизации нет.\n");
            break;
        }
        case 2: {
            printf("Выборы выиграл консерватор! Упор на традиции, семью, повышение налогов на 'роскошь'.\n");
            printf("  → Налоги ↑, добавлен сбор 'на поддержку семейных ценностей' и оборону.\n");
            Alice.income_tax_rate += 0.025f;
            Ben.income_tax_rate += 0.025f;
            if (Alice.income_tax_rate > 0.25f) Alice.income_tax_rate = 0.25f;
            if (Ben.income_tax_rate > 0.25f) Ben.income_tax_rate = 0.25f;
            Alice.political_tax = 5000 + rand() % 4000;
            Ben.political_tax = 4500 + rand() % 3500;
            Alice.new_political_expense = 6000 + rand() % 5000;
            Ben.new_political_expense = 7000 + rand() % 6000;
       
            Alice.sport += 2000;
            Ben.sport += 1500;
            printf("  Эффект: выше налоги, но стабильность. Нет мобилизации, но 'духовные' расходы.\n");
            break;
        }
        case 3: {
            printf("  Ой, жёсткий тип пришёл к власти, 'особый период' объявили, мобилизация и всё такое.\n");
            printf("  → Налоги резко вверх, сборы на оборону, патриотизм везде.\n");
            printf("  → Для Бена плохо: шанс смерти вырос, мобилизация, повестки, стресс — берегись!\n");
            Alice.income_tax_rate += 0.06f;
            Ben.income_tax_rate += 0.06f;
            if (Alice.income_tax_rate > 0.30f) Alice.income_tax_rate = 0.30f;
            if (Ben.income_tax_rate > 0.30f) Ben.income_tax_rate = 0.30f;
            Alice.political_tax = 15000 + rand() % 10000;
            Ben.political_tax = 18000 + rand() % 12000;
            Alice.new_political_expense = 25000 + rand() % 15000;
            Ben.new_political_expense = 30000 + rand() % 20000;
            Ben.death_multiplier = 2.2f + (rand() % 8) / 10.0f;
            Ben.mobilization_active = true;
            Alice.death_multiplier = 1.1f;

            if (rand() % 3 == 0) {
                Alice.hobby = RUB(Alice.hobby * 0.7);
                Ben.hobby = RUB(Ben.hobby * 0.7);
                printf("  (В жёстком режиме часть 'несерьёзных' расходов урезана)\n");
            }
            printf("  Эффект: деньги идут на войну/армию, Бен в зоне риска! Алиса тоже платит, но живёт.\n");
            break;
        }
    }

    printf("  Дополнительные корректировки расходов из-за полит. нестабильности:\n");
    float factor = 0.9f + (rand() % 30) / 100.0f;
    if (rand() % 2 == 0) {
        Alice.rent = RUB(Alice.rent * factor);
        Ben.rent = RUB(Ben.rent * factor);
        printf("    Аренда/ЖКХ изменена в %.2f раз\n", factor);
    }
    factor = 0.85f + (rand() % 25) / 100.0f;
    if (rand() % 3 == 0) {
        Alice.food.basic = RUB(Alice.food.basic * factor);
        Ben.food.basic = RUB(Ben.food.basic * factor);
        printf("    Цены на базовые продукты изменены (инфляция/дефицит от политики)\n");
    }
    if (new_leader == 3 && rand() % 2 == 0) {
        Alice.VTB.money -= 5000 + rand() % 15000;
        Ben.Sber.money -= 8000 + rand() % 20000;
        printf("    (В жёстком режиме возможны разовые 'штрафы' за 'неправильное' поведение)\n");
    }

    printf("  Итог: налоги новой партии Алиса=%lld, Бен=%lld | новые расходы Алиса=%lld, Бен=%lld | множ.смерти Бен=%.1f\n",
           Alice.political_tax, Ben.political_tax, Alice.new_political_expense, Ben.new_political_expense, Ben.death_multiplier);
    printf("  (Эти значения будут влиять на ежемесячные траты и риск смерти Бена)\n");
}

void apply_political_expenses()
{
    if (Alice.alive) {
        RUB total_pol = Alice.political_tax + Alice.new_political_expense;
        Alice.VTB.money -= total_pol;

        Alice.political_tax = RUB(Alice.political_tax * 1.015);
        Alice.new_political_expense = RUB(Alice.new_political_expense * 1.015);
        if (Alice.mobilization_active) {
            Alice.VTB.money -= 3000;
        }
    }
    if (Ben.alive) {
        RUB total_pol = Ben.political_tax + Ben.new_political_expense;
        Ben.Sber.money -= total_pol;
        Ben.political_tax = RUB(Ben.political_tax * 1.015);
        Ben.new_political_expense = RUB(Ben.new_political_expense * 1.015);
        if (Ben.mobilization_active) {
            Ben.Sber.money -= 5000;
     
            if (rand() % 20 == 0) {
                Ben.Sber.money -= 10000 + rand() % 30000;
                printf("  [МОБИЛИЗАЦИЯ] Бен понёс доп. расходы/штраф в этом месяце!\n");
            }
        }
    }
}


void simulation()
{
    int month = 2;
    int year = 2026;

    while (!((month == 3) && (year == 2031))) {
        alice_positive_events();
        alice_negative_events();
        alice_death_event(month, year);
        alice_tech_purchase();
        alice_travel(month, year);
        alice_stocks();
        alice_family(month);
        alice_hobby_advanced();

        alice_salary(month, year);
        alice_food();
        alice_children(month);
        alice_medical();
        alice_car();
        alice_cat(month);
        alice_hobby();
        alice_car_tax();
        alice_house();
        alice_subscriptions();
        alice_sport();
        alice_life_insurance();
        alice_bank_interest();
        alice_deposit();
        alice_buy_car();
        alice_handle_apartment();
        alice_deneg_net();

        ben_salary(month, year);
        ben_food();
        ben_medical();
        ben_car();
        ben_cat(month);
        ben_hobby();
        ben_children(month);
        ben_family(month);
        ben_hobby_advanced();
        ben_positive_events();
        ben_negative_events();
        ben_death_event(month, year);
        ben_tech_purchase();
        ben_travel(month, year);
        ben_stocks();
        ben_car_tax();
        ben_house();
        ben_subscriptions();
        ben_sport();
        ben_life_insurance();
        ben_bank_interest();
        ben_deposit();
        ben_buy_car();
        ben_handle_apartment();
        ben_deneg_net();

        alice_mortgage_payment();
        ben_mortgage_payment();

        if (Alice.family.has_partner) {
            Alice.VTB.money += Alice.partner_monthly_effect;
            if (Alice.partner_monthly_effect > 0) {
                Alice.family.partner_expenses = RUB(Alice.family.partner_expenses * 0.98);
            }
        }
        if (Ben.family.has_partner) {
            Ben.Sber.money += Ben.partner_monthly_effect;
        }

        apply_political_expenses();

        ++month;
        if (month == 13) {
            month = 1;
            ++year;

            alice_update_yearly_traits(year);
            ben_update_yearly_traits(year);
            alice_check_wedding(year);
            ben_check_wedding(year);
            update_politics(year);
        }
    }
}



void print_results()
{
    printf("\n================== ИТОГОВЫЙ ОТЧЁТ ==================\n");

    if (Alice.alive) {
        RUB total_assets = Alice.VTB.money + Alice.VTB.deposit + Alice.stocks +
                           (Alice.flat.exist ? Alice.flat.price : 0) +
                           (Alice.car.exist ? Alice.car.value : 0);

        printf("Алиса (жива):\n");
        printf(" Зарплата = %lld\n", Alice.salary);
        printf(" Деньги на счету = %lld\n", Alice.VTB.money);
        printf(" Депозит = %lld\n", Alice.VTB.deposit);
        printf(" Акции = %lld\n", Alice.stocks);
        printf(" Общее имущество = %lld\n", total_assets);
        printf(" Суммарный подоходный налог = %lld\n", Alice.taxes_paid);
        printf(" Расходы на еду = %lld\n", Alice.food.basic + Alice.food.luxury);
        printf(" Расходы на спорт = %lld\n", Alice.sport);
        printf(" Налог на машину = %lld\n", Alice.car_tax);
        printf(" Аренда = %lld\n", Alice.rent);
        printf(" ЖКХ = %lld\n", Alice.utilities);

        if (Alice.child.exist) {
            printf(" Ребёнок (%d лет):\n", Alice.child.age);
            printf("   Питание = %lld\n", Alice.child.food);
            printf("   Одежда = %lld\n", Alice.child.clothes);
            printf("   Образование = %lld\n", Alice.child.education);
            printf("   Игрушки = %lld\n", Alice.child.toys);
            printf("   Лекарства = %lld\n", Alice.child.medical);

            if (Alice.child.age >= 16) {
                printf("   Расходы старшего возраста (16+) = %lld\n", Alice.child.older_expenses);
            } else if (Alice.child.age >= 12) {
                printf("   Расходы подростка (12-15) = %lld\n", Alice.child.teen_expenses);
            }
        } else {
            printf(" Детей нет\n");
        }

        printf(" Продвинутые хобби:\n");
        printf("   Тренажёрный зал = %lld\n", Alice.advanced_hobby.gym);
        printf("   Творчество = %lld\n", Alice.advanced_hobby.creative);
        printf("   Коллекционирование = %lld\n", Alice.advanced_hobby.collecting);
        printf("   Желание тратиться на себя по 10-ти балльной шкале = %d\n", Alice.advanced_hobby.level);

        if (Alice.family.has_partner) {
            printf(" Муж: расходы = %lld\n", Alice.family.partner_expenses);
        } else {
            printf(" Мужа нет\n");
        }

        printf(" Есть ли квартира? %s\n", Alice.flat.exist ? "Да" : "Нет");
        printf(" Есть ли машина? %s\n", Alice.car.exist ? "Да" : "Нет");
        printf(" Есть ли кот? %s\n", Alice.cat.exist ? "Да" : "Нет");
    } else {
        printf("Алиса умерла.\n");
    }

    if (Ben.alive) {
        RUB total_assets = Ben.Sber.money + Ben.Sber.deposit + Ben.stocks +
                           (Ben.flat.exist ? Ben.flat.price : 0) +
                           (Ben.car.exist ? Ben.car.value : 0);

        printf("\nБен (жив):\n");
        printf(" Зарплата = %lld\n", Ben.salary);
        printf(" Деньги на счету = %lld\n", Ben.Sber.money);
        printf(" Депозит = %lld\n", Ben.Sber.deposit);
        printf(" Акции = %lld\n", Ben.stocks);
        printf(" Общее имущество = %lld\n", total_assets);
        printf(" Суммарный подоходный налог = %lld\n", Ben.taxes_paid);
        printf(" Расходы на еду = %lld\n", Ben.food.basic + Ben.food.luxury);
        printf(" Расходы на спорт = %lld\n", Ben.sport);
        printf(" Налог на машину = %lld\n", Ben.car_tax);
        printf(" Аренда = %lld\n", Ben.rent);
        printf(" ЖКХ = %lld\n", Ben.utilities);

        if (Ben.child.exist) {
            printf(" Ребёнок (%d лет):\n", Ben.child.age);
            printf("   Питание = %lld\n", Ben.child.food);
            printf("   Одежда = %lld\n", Ben.child.clothes);
            printf("   Образование = %lld\n", Ben.child.education);
            printf("   Игрушки = %lld\n", Ben.child.toys);
            printf("   Лекарства = %lld\n", Ben.child.medical);

            if (Ben.child.age >= 16) {
                printf("   Расходы старшего возраста (16+) = %lld\n", Ben.child.older_expenses);
            } else if (Ben.child.age >= 12) {
                printf("   Расходы подростка (12-15) = %lld\n", Ben.child.teen_expenses);
            }
        } else {
            printf(" Детей нет\n");
        }

        printf(" Продвинутые хобби:\n");
        printf("   Тренажёрный зал = %lld\n", Ben.advanced_hobby.gym);
        printf("   Творчество = %lld\n", Ben.advanced_hobby.creative);
        printf("   Коллекционирование = %lld\n", Ben.advanced_hobby.collecting);
        printf("   Желание тратиться на себя по 10-ти балльной шкале = %d\n", Ben.advanced_hobby.level);

        if (Ben.family.has_partner) {
            printf(" Жена: расходы = %lld\n", Ben.family.partner_expenses);
        } else {
            printf(" Жены нет\n");
        }

        printf(" Есть ли квартира? %s\n", Ben.flat.exist ? "Да" : "Нет");
        printf(" Есть ли машина? %s\n", Ben.car.exist ? "Да" : "Нет");
        printf(" Есть ли хомяк? %s\n", Ben.humster.exist ? "Да" : "Нет");
    } else {
        printf("Бен умер.\n");
    }

    printf("==================================================\n");


    printf("\n=== ЛИЧНОСТНЫЕ ХАРАКТЕРИСТИКИ ===\n");
    if (Alice.alive) {
        printf("Алиса:\n");
        printf("  Азартность (0-10): %d → влияет на хобби/развлечения (+%d руб.)\n", Alice.gambling_level, Alice.gambling_level * 300);
        printf("  Аппетит (0-10): %d → +%.1f%% к расходам на еду\n", Alice.appetite_level, Alice.appetite_level * 2.0);
        printf("  Общительность (0-10): %d → шанс свадьбы +%d%%\n", Alice.sociability, Alice.sociability / 2);
        printf("  Амбициозность (0-10): %d → бонус к зарплате\n", Alice.ambition);
        printf("  Здоровые привычки (0-10): %d → снижение мед. расходов\n", Alice.health_habits);
        printf("  Импульсивность (0-10): %d → риск случайных покупок\n", Alice.impulsiveness);
        if (Alice.family.has_partner) {
            printf("  Партнёр: %s (эффект %lld руб./мес.)\n",
                   Alice.partner_type == 1 ? "ЩЕДРЫЙ" : (Alice.partner_type == 2 ? "РАСТОЧИТЕЛЬНЫЙ" : "НЕЙТРАЛЬНЫЙ"),
                   Alice.partner_monthly_effect);
        } else {
            printf("  Партнёр: нет (ещё не женилась)\n");
        }
    } else {
        printf("Алиса умерла — характеристики не актуальны.\n");
    }

    if (Ben.alive) {
        printf("\nБен:\n");
        printf("  Азартность (0-10): %d → влияет на хобби/развлечения (+%d руб.)\n", Ben.gambling_level, Ben.gambling_level * 250);
        printf("  Аппетит (0-10): %d → +%.1f%% к расходам на еду\n", Ben.appetite_level, Ben.appetite_level * 2.0);
        printf("  Общительность (0-10): %d → шанс свадьбы +%d%%\n", Ben.sociability, Ben.sociability / 2);
        printf("  Амбициозность (0-10): %d → бонус к зарплате\n", Ben.ambition);
        printf("  Здоровые привычки (0-10): %d → снижение мед. расходов\n", Ben.health_habits);
        printf("  Импульсивность (0-10): %d → риск случайных покупок\n", Ben.impulsiveness);
        if (Ben.family.has_partner) {
            printf("  Партнёр: %s (эффект %lld руб./мес.)\n",
                   Ben.partner_type == 1 ? "ЩЕДРЫЙ" : (Ben.partner_type == 2 ? "РАСТОЧИТЕЛЬНЫЙ" : "НЕЙТРАЛЬНЫЙ"),
                   Ben.partner_monthly_effect);
        } else {
            printf("  Партнёр: нет (ещё не женился)\n");
        }
    } else {
        printf("\nБен умер — характеристики не актуальны.\n");
    }

    
    printf("\n=== ПОЛИТИЧЕСКАЯ СИТУАЦИЯ (режим, налоги, военное положение) ===\n");
    printf("Алиса:\n");
    printf("  Тип лидера: %d (0=нейтрал,1=либерал,2=консерватор,3=авторитар)\n", Alice.leader_type);
    printf("  Доп. полит. налог: %lld руб./мес.\n", Alice.political_tax);
    printf("  Новые полит. расходы: %lld руб./мес.\n", Alice.new_political_expense);
    printf("  Множитель риска смерти: %.1f\n", Alice.death_multiplier);
    if (Alice.mobilization_active) {
        printf("  Мобилизация активна (для Алисы — только доп. расходы)\n");
    }
    printf("Бен:\n");
    printf("  Тип лидера: %d\n", Ben.leader_type);
    printf("  Доп. полит. налог: %lld руб./мес.\n", Ben.political_tax);
    printf("  Новые полит. расходы: %lld руб./мес.\n", Ben.new_political_expense);
    printf("  Множитель риска смерти: %.1f\n", Ben.death_multiplier);
    if (Ben.mobilization_active) {
        printf("   МОБИЛИЗАЦИЯ АКТИВНА! (жёсткий режим — повышенный риск смерти и доп. траты)\n");
    } else {
        printf("  Мобилизация не активна\n");
    }
    printf("  (Политика влияет на все расходы, налоги и выживаемость Бена в течение всей симуляции)\n");

    RUB alice_net = Alice.VTB.money + Alice.VTB.deposit + Alice.stocks +
                    (Alice.flat.exist ? Alice.flat.price : 0) +
                    (Alice.car.exist ? Alice.car.value : 0);
    RUB ben_net = Ben.Sber.money + Ben.Sber.deposit + Ben.stocks +
                  (Ben.flat.exist ? Ben.flat.price : 0) +
                  (Ben.car.exist ? Ben.car.value : 0);

    printf("\n=== АНАЛИЗ И ВЫВОДЫ  ===\n");
    printf("Модель жизни Алисы: %s (финальное имущество %lld руб.)\n",
           Alice.alive ? (alice_net > 3000000 ? "ХОРОШАЯ" : "СРЕДНЯЯ/СЛАБАЯ") : "ПЛОХАЯ", alice_net);
    printf("Модель жизни Бена:   %s (финальное имущество %lld руб.)\n",
           Ben.alive ? (ben_net > 3000000 ? "ХОРОШАЯ" : "СРЕДНЯЯ/СЛАБАЯ") : "ПЛОХАЯ", ben_net);

    printf("\n Тестирование двух моделей жизни:\n");
    if (Alice.alive && Ben.alive) {
        printf("   Алиса vs Бен → разница в имуществе: %lld руб.\n", alice_net - ben_net);
    } else if (!Alice.alive && !Ben.alive) {
        printf("   Оба персонажа умерли — сравнение невозможно.\n");
    } else {
        printf("   Один из персонажей умер — сравнение частично.\n");
    }

    if (Alice.mortgage.active || Ben.mortgage.active) {
        printf("Ипотека vs копить: хотя бы один персонаж использует ипотеку — это позволило быстрее получить квартиру.\n");
    } else if (Alice.flat.exist || Ben.flat.exist) {
        printf("Ипотека vs копить: персонажи купили квартиру за наличные (без ипотеки).\n");
    } else {
        printf("Ипотека vs копить: пока никто не купил квартиру.\n");
    }

    printf("==================================================\n");
}


int main()
{
    srand(time(NULL));
    
    alice_init();
    ben_init();
    simulation();
    print_results();

    return 0;
}
