#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

using RUB = long long int;
using PERCENT = double;

const int MAX_EVENTS = 500;
const int MAX_EVENT_LENGTH = 200;

struct Car {
    RUB value;
    RUB gas;
    RUB insurance;
    RUB repair;
    int year;
    char brand[50];
};

struct Investment {
    char type[50];
    RUB amount;
    RUB current_value;
    PERCENT change_rate;
    int quantity;
    bool active;
    RUB purchase_price;
};

struct Career {
    int level;
    char position[100];
    RUB base_salary;
    int experience;
    int skill_points;
    bool can_work;
    RUB monthly_bonus;
};

struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    RUB rent;
    RUB utilities;
    RUB taxes;
    struct Car car;
    char name[50];
    int age;
    int health;
    int mental_health;
    int stress;
    bool is_alive;
    bool in_clinic;
    bool died_from_debt;
    RUB microloan_debt;
    int microloan_months;
    RUB shopping_spending;
    RUB clothing_expenses;
    RUB entertainment_expenses;
    RUB household_expenses;
    RUB transport_expenses;
    struct Career career;
    struct Investment investments[5];
    int investment_count;
};

struct Pet {
    char name[50];
    int health;
    int mental_health;
    RUB food_cost;
    RUB vet_cost;
    bool is_alive;
    bool is_ill;
    int illness_severity;
    bool is_stray;
};

struct Education {
    int exam_score;
    int education_level;
    bool exams_passed;
    bool enrolled;
    RUB education_cost;
    char institution[100];
    int years_remaining;
    char status[50];
    bool can_study_later;
};

struct EventLog {
    char description[MAX_EVENT_LENGTH];
    int month;
    int year;
    int type;
};

struct Family {
    struct Person husband;
    struct Person wife;
    struct Person daughter;
    struct Pet dog;
    struct Pet cat;
    struct Education daughter_edu;
    RUB family_budget;
    int family_stress;
    int daughter_good_behavior_points;
    bool daughter_stole;
    int months_without_stealing;
    RUB family_credit;
    int credit_months;
    bool made_major_purchase;
    char major_purchase_name[100];
    RUB base_expenses;
    bool gang_attacked;  
};

struct MonthStats {
    int month;
    int year;
    RUB income;
    RUB expenses;
    RUB bank_interest;
    RUB microloan_payments;
    RUB shopping_expenses;
    RUB education_expenses;
    RUB investment_income;
    RUB investment_loss;
    RUB career_bonus;
    RUB vacation_expenses;
    RUB sanatorium_expenses;
    RUB unexpected_expenses;
    RUB entertainment_expenses;
    RUB clothing_expenses;
    RUB medical_expenses;
    RUB credit_payments;
    RUB household_expenses;
    RUB transport_expenses;
    RUB food_expenses;
    RUB gang_attack_loss;  
};

struct SimulationConfig {
    PERCENT bank_rate;
    PERCENT inflation_rate;
    PERCENT microloan_rate;
    PERCENT credit_rate;
    PERCENT gangster_rate;  
    int start_month;
    int start_year;
    int end_month;
    int end_year;
};

struct InvestmentMarket {
    RUB stocks_price;
    RUB bonds_price;
    RUB crypto_price;
    RUB realty_price;
};

struct Family family;
struct MonthStats current_stats;
struct SimulationConfig config;
struct EventLog event_log[MAX_EVENTS];
struct InvestmentMarket market;
int event_count = 0;
int total_months = 0;
RUB total_income = 0;
RUB total_expenses = 0;
int bankruptcy_months = 0;
bool daughter_in_orphanage = false;
bool simulation_ended = false;
bool game_saved = false;
int deaths_count = 0;

const char* minor_events_positive[] = {
    "Ангелина весь месяц училась на пятёрки",
    "Денис получил благодарность от начальника",
    "Алиса нашла скидку в супермаркете",
    "Семья хорошо провела выходные вместе",
    "Ангелина победила в школьной олимпиаде",
    "Денис помог коллеге с проектом",
    "Алиса получила комплимент от клиентов",
    "Джина научилась новой команде",
    "Семья посетила музей",
    "Ангелина помогла соседке",
    "Денис получил небольшую премию",
    "Алиса испекла вкусный торт",
    "Ангелина сделала домашку без напоминаний"
};

const char* minor_events_negative[] = {
    "Денис получил устный выговор за опоздания",
    "Ангелина поссорилась с одноклассницей",
    "Алиса забыла выключить свет (доп. расходы)",
    "Денис забыл важный документ дома",
    "Ангелина получила замечание от учителя",
    "Алиса опоздала на встречу",
    "Денис заболел лёгкой простудой",
    "Ангелина потеряла сменку в школе",
    "Семья пропустила автобус",
    "Алиса купила ненужную вещь",
    "Ангелина получила двойку за контрольную",
    "Денис разбил чашку на работе",
    "Ангелина забыла сделать уроки"
};

const char* minor_events_neutral[] = {
    "Ангелина читала книгу весь вечер",
    "Денис смотрел футбол с друзьями",
    "Алиса вязала свитер",
    "Семья готовила пиццу вместе",
    "Джина спала весь день",
    "Ангелина гуляла в парке",
    "Денис чинил кран на кухне",
    "Алиса пересаживала цветы",
    "Семья играла в настольные игры",
    "Ангелина рисовала картину",
    "Денис слушал музыку в машине",
    "Алиса говорила по телефону с подругой"
};

void init_config() {
    config.bank_rate = 14.5;
    config.inflation_rate = 8.0;
    config.microloan_rate = 2.0;
    config.credit_rate = 1.5;
    config.gangster_rate = 15.0;  
    config.start_month = 2;
    config.start_year = 2026;
    config.end_month = 3;
    config.end_year = 2027;
}

void init_market() {
    market.stocks_price = 1000;
    market.bonds_price = 500;
    market.crypto_price = 5000;
    market.realty_price = 100000;
}

void update_market() {
    int change = rand() % 20 - 10;
    market.stocks_price = (RUB)(market.stocks_price * (1 + change / 100.0));
    if (market.stocks_price < 500) market.stocks_price = 500;
    change = rand() % 10 - 5;
    market.bonds_price = (RUB)(market.bonds_price * (1 + change / 100.0));
    if (market.bonds_price < 500) market.bonds_price = 500;
    change = rand() % 40 - 20;
    market.crypto_price = (RUB)(market.crypto_price * (1 + change / 100.0));
    if (market.crypto_price < 500) market.crypto_price = 500;
    change = rand() % 15 - 5;
    market.realty_price = (RUB)(market.realty_price * (1 + change / 100.0));
    if (market.realty_price < 5000) market.realty_price = 5000;
}

void init_car(struct Car* car, const char* brand, RUB value, RUB gas) {
    car->value = value;
    car->gas = gas;
    car->insurance = 10000;
    car->repair = 0;
    car->year = 2024;
    int i = 0;
    while (brand[i] != '\0' && i < 49) {
        car->brand[i] = brand[i];
        i++;
    }
    car->brand[i] = '\0';
}

void init_career(struct Career* career, int level, const char* position, RUB base_salary) {
    career->level = level;
    int i = 0;
    while (position[i] != '\0' && i < 99) {
        career->position[i] = position[i];
        i++;
    }
    career->position[i] = '\0';
    career->base_salary = base_salary;
    career->experience = 0;
    career->skill_points = 0;
    career->can_work = true;
    career->monthly_bonus = 0;
}

void init_investment(struct Investment* inv, const char* type, RUB amount, RUB price, int qty) {
    int i = 0;
    while (type[i] != '\0' && i < 49) {
        inv->type[i] = type[i];
        i++;
    }
    inv->type[i] = '\0';
    inv->amount = amount;
    inv->current_value = amount;
    inv->change_rate = 0;
    inv->quantity = qty;
    inv->active = true;
    inv->purchase_price = price;
}

void init_person(struct Person* person, const char* name, int age, RUB salary, RUB capital) {
    int i = 0;
    while (name[i] != '\0' && i < 49) {
        person->name[i] = name[i];
        i++;
    }
    person->name[i] = '\0';

    person->age = age;
    person->salary = salary;
    person->capital = capital;
    person->food = 10000;
    person->rent = 0;
    person->utilities = 2500;
    person->taxes = 0;
    person->health = 98 + (rand() % 3);
    person->mental_health = 90 + (rand() % 6);
    person->stress = 0;
    person->is_alive = true;
    person->in_clinic = false;
    person->died_from_debt = false;
    person->microloan_debt = 0;
    person->microloan_months = 0;
    person->shopping_spending = 4000;
    person->clothing_expenses = 4000;
    person->entertainment_expenses = 6000;
    person->household_expenses = 5000;
    person->transport_expenses = 3000;
    person->investment_count = 0;
}

void init_pet(struct Pet* pet, const char* name) {
    int i = 0;
    while (name[i] != '\0' && i < 49) {
        pet->name[i] = name[i];
        i++;
    }
    pet->name[i] = '\0';
    pet->health = 100;
    pet->mental_health = 100;
    pet->food_cost = 5000;
    pet->vet_cost = 10000;
    pet->is_alive = true;
    pet->is_ill = false;
    pet->illness_severity = 0;
    pet->is_stray = false;
}

void init_education() {
    family.daughter_edu.exam_score = 0;
    family.daughter_edu.education_level = 0;
    family.daughter_edu.exams_passed = false;
    family.daughter_edu.enrolled = false;
    family.daughter_edu.education_cost = 0;
    family.daughter_edu.years_remaining = 0;
    family.daughter_edu.can_study_later = false;
    char default_inst[] = "Не определено";
    int i = 0;
    while (default_inst[i] != '\0' && i < 99) {
        family.daughter_edu.institution[i] = default_inst[i];
        i++;
    }
    family.daughter_edu.institution[i] = '\0';
    char status[] = "Школьница";
    i = 0;
    while (status[i] != '\0' && i < 49) {
        family.daughter_edu.status[i] = status[i];
        i++;
    }
    family.daughter_edu.status[i] = '\0';
}

void init_family() {
    init_person(&family.husband, "Денис", 35, 95000, 60000);
    init_car(&family.husband.car, "BMW X5", 5500000, 20000);
    init_career(&family.husband.career, 3, "Старший специалист", 95000);

    init_person(&family.wife, "Алиса", 33, 75000, 0);
    init_car(&family.wife.car, "Toyota Camry", 2400000, 15000);
    init_career(&family.wife.career, 2, "Специалист", 75000);

    family.family_budget = family.husband.capital + family.wife.capital;
    family.husband.capital = 0;
    family.wife.capital = 0;

    init_person(&family.daughter, "Ангелина", 16, 0, 0);
    family.daughter.food = 8000;
    family.daughter.mental_health = 65 + (rand() % 10);
    family.daughter.shopping_spending = 4000;
    init_career(&family.daughter.career, 0, "Студент/Безработный", 0);
    family.daughter.career.can_work = false;

    init_pet(&family.dog, "Джина");
    init_pet(&family.cat, "Сэм");
    family.cat.is_alive = false;

    init_education();

    family.family_budget = 0;
    family.family_stress = 0;
    family.daughter_good_behavior_points = 0;
    family.daughter_stole = false;
    family.months_without_stealing = 0;
    family.family_credit = 0;
    family.credit_months = 0;
    family.made_major_purchase = false;
    family.base_expenses = 30000;
    family.gang_attacked = false;  
    char purchase[] = "Нет";
    int i = 0;
    while (purchase[i] != '\0' && i < 99) {
        family.major_purchase_name[i] = purchase[i];
        i++;
    }
    family.major_purchase_name[i] = '\0';
}

void init_stats() {
    current_stats.month = 0;
    current_stats.year = 0;
    current_stats.income = 0;
    current_stats.expenses = 0;
    current_stats.bank_interest = 0;
    current_stats.microloan_payments = 0;
    current_stats.shopping_expenses = 0;
    current_stats.education_expenses = 0;
    current_stats.investment_income = 0;
    current_stats.investment_loss = 0;
    current_stats.career_bonus = 0;
    current_stats.vacation_expenses = 0;
    current_stats.sanatorium_expenses = 0;
    current_stats.unexpected_expenses = 0;
    current_stats.entertainment_expenses = 0;
    current_stats.clothing_expenses = 0;
    current_stats.medical_expenses = 0;
    current_stats.credit_payments = 0;
    current_stats.household_expenses = 0;
    current_stats.transport_expenses = 0;
    current_stats.food_expenses = 0;
    current_stats.gang_attack_loss = 0;  
}

void add_event(const char* description, int type) {
    if (event_count < MAX_EVENTS) {
        int i = 0;
        while (description[i] != '\0' && i < MAX_EVENT_LENGTH - 1) {
            event_log[event_count].description[i] = description[i];
            i++;
        }
        event_log[event_count].description[i] = '\0';
        event_log[event_count].month = total_months + 1;
        event_log[event_count].year = current_stats.year;
        event_log[event_count].type = type;
        event_count++;
    }
}

void check_new_pet() {
    if (family.cat.is_alive) return;
    if (!family.husband.is_alive || !family.wife.is_alive) return;

    if (family.daughter_good_behavior_points >= 20 && family.months_without_stealing >= 3) {
        family.cat.is_alive = true;
        printf("\n[РАДОСТЬ] Семья завела кота Сэма!\n");
        add_event("Семья завела кота Сэма", 1);
        family.daughter.mental_health += 20;
        family.daughter_good_behavior_points = 0;
    }

    int stray_chance = rand() % 100;
    if (stray_chance < 5 && !family.cat.is_alive) {
        family.cat.is_alive = true;
        family.cat.is_stray = true;
        printf("\n[РАДОСТЬ] Семья подобрала бродячего кота!\n");
        add_event("Подобран бродячий кот", 1);
        family.daughter.mental_health += 15;
    }
}

void career_level_up(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    if (!person->career.can_work) return;

    person->career.experience += 5;

    int promotion_chance = 100 - (person->career.skill_points * 2);
    if (promotion_chance < 20) promotion_chance = 20;

    if (rand() % 100 >= promotion_chance) return;

    if (person->career.experience >= 20 && person->career.level == 1) {
        person->career.level = 2;
        person->salary = (RUB)(person->salary * 1.3);
        person->career.base_salary = person->salary;
        char pos[] = "Специалист";
        int i = 0;
        while (pos[i] != '\0' && i < 99) {
            person->career.position[i] = pos[i];
            i++;
        }
        person->career.position[i] = '\0';
        printf("[КАРЬЕРА] %s повышен до Специалиста! Зарплата: %lld\n", person->name, person->salary);
        char event_msg[200];
        sprintf(event_msg, "%s повышен до Специалиста", person->name);
        add_event(event_msg, 3);
    }
    else if (person->career.experience >= 50 && person->career.level == 2) {
        person->career.level = 3;
        person->salary = (RUB)(person->salary * 1.5);
        person->career.base_salary = person->salary;
        char pos[] = "Старший специалист";
        int i = 0;
        while (pos[i] != '\0' && i < 99) {
            person->career.position[i] = pos[i];
            i++;
        }
        person->career.position[i] = '\0';
        printf("[КАРЬЕРА] %s повышен до Старшего специалиста! Зарплата: %lld\n", person->name, person->salary);
        char event_msg[200];
        sprintf(event_msg, "%s повышен до Старшего специалиста", person->name);
        add_event(event_msg, 3);
    }
    else if (person->career.experience >= 100 && person->career.level == 3) {
        person->career.level = 4;
        person->salary = (RUB)(person->salary * 1.8);
        person->career.base_salary = person->salary;
        char pos[] = "Руководитель";
        int i = 0;
        while (pos[i] != '\0' && i < 99) {
            person->career.position[i] = pos[i];
            i++;
        }
        person->career.position[i] = '\0';
        printf("[КАРЬЕРА] %s повышен до Руководителя! Зарплата: %lld\n", person->name, person->salary);
        char event_msg[200];
        sprintf(event_msg, "%s повышен до Руководителя", person->name);
        add_event(event_msg, 3);
    }
    else if (person->career.experience >= 150 && person->career.level == 4) {
        person->career.level = 5;
        person->salary = (RUB)(person->salary * 2.0);
        person->career.base_salary = person->salary;
        char pos[] = "Директор";
        int i = 0;
        while (pos[i] != '\0' && i < 99) {
            person->career.position[i] = pos[i];
            i++;
        }
        person->career.position[i] = '\0';
        printf("[КАРЬЕРА] %s повышен до Директора! Зарплата: %lld\n", person->name, person->salary);
        char event_msg[200];
        sprintf(event_msg, "%s повышен до Директора", person->name);
        add_event(event_msg, 3);
    }
}

void career_skill_up(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    if (!person->career.can_work) return;

    RUB training_cost = 35000;
    if (family.family_budget >= training_cost) {
        family.family_budget -= training_cost;
        current_stats.expenses += training_cost;
        person->career.skill_points += 15;
        person->mental_health += 10;

        int skill_result = rand() % 100;
        if (skill_result < 20) {
            printf("[ОБУЧЕНИЕ] %s прошёл курсы, но навыки не улучшились...\n", person->name);
            char event_msg[200];
            sprintf(event_msg, "%s обучение без результата", person->name);
            add_event(event_msg, 4);
        }
        else if (skill_result < 80) {
            person->salary = (RUB)(person->salary * 1.05);
            printf("[ОБУЧЕНИЕ] %s прошёл курсы! Навыки +15, Зарплата +5%%\n", person->name);
            char event_msg[200];
            sprintf(event_msg, "%s прошёл обучение за %lld руб.", person->name, training_cost);
            add_event(event_msg, 3);
        }
        else {
            person->salary = (RUB)(person->salary * 1.12);
            printf("[ОБУЧЕНИЕ] %s блестяще прошёл курсы! Навыки +25, Зарплата +12%%\n", person->name);
            char event_msg[200];
            sprintf(event_msg, "%s отличное обучение +12%%", person->name);
            add_event(event_msg, 1);
        }
    }
}

void career_bonus(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    if (!person->career.can_work) return;

    int chance = rand() % 100;
    if (chance < 25) {
        RUB bonus = person->salary / 4;
        family.family_budget += bonus;
        current_stats.income += bonus;
        current_stats.career_bonus += bonus;
        person->career.monthly_bonus = bonus;
        printf("[ПРЕМИЯ] %s получил премию: %lld руб.\n", person->name, bonus);
        char event_msg[200];
        sprintf(event_msg, "%s получил премию %lld руб.", person->name, bonus);
        add_event(event_msg, 1);
    }
}

void buy_investment(struct Person* person, const char* type, RUB amount, RUB price, int qty) {
    if (!person->is_alive || person->in_clinic) return;
    if (person->investment_count >= 5) return;
    if (family.family_budget < amount) {
        printf("[ОШИБКА] Недостаточно средств! Нужно %lld руб., у вас %lld руб.\n", amount, family.family_budget);
        return;
    }

    family.family_budget -= amount;
    init_investment(&person->investments[person->investment_count], type, amount, price, qty);
    person->investment_count++;
    current_stats.expenses += amount;
    printf("[ИНВЕСТ] %s купил %s (%d шт.) на %lld руб.\n", person->name, type, qty, amount);
    char event_msg[200];
    sprintf(event_msg, "%s купил %s (%d шт.) на %lld руб.", person->name, type, qty, amount);
    add_event(event_msg, 2);
}

void auto_sell_investments() {
    if (family.family_budget > -200000) return;

    for (int p = 0; p < 3; p++) {
        struct Person* person = (p == 0) ? &family.husband : (p == 1) ? &family.wife : &family.daughter;
        for (int i = 0; i < person->investment_count; i++) {
            if (!person->investments[i].active) continue;

            family.family_budget += person->investments[i].current_value;
            person->investments[i].active = false;

            char event_msg[200];
            sprintf(event_msg, "Автоматическая продажа инвестиций: %lld руб.", person->investments[i].current_value);
            add_event(event_msg, 4);

            if (family.family_budget > -100000) return;
        }
    }
}

void update_investments(struct Person* person) {
    if (!person->is_alive) return;

    for (int i = 0; i < person->investment_count; i++) {
        if (!person->investments[i].active) continue;

        PERCENT change = 0;
        int rand_val = rand() % 100;

        if (strcmp(person->investments[i].type, "Акции") == 0) {
            if (rand_val < 35) change = -0.05;
            else if (rand_val < 80) change = 0.04;
            else change = 0.12;
        }
        else if (strcmp(person->investments[i].type, "Облигации") == 0) {
            change = 0.01;
        }
        else if (strcmp(person->investments[i].type, "Криптовалюта") == 0) {
            if (rand_val < 25) change = -0.20;
            else if (rand_val < 75) change = 0.06;
            else change = 0.35;
        }
        else if (strcmp(person->investments[i].type, "Недвижимость") == 0) {
            change = 0.005;
        }

        RUB old_value = person->investments[i].current_value;
        person->investments[i].current_value = (RUB)(person->investments[i].current_value * (1 + change));
        RUB diff = person->investments[i].current_value - old_value;

        if (diff > 0) {
            current_stats.investment_income += diff;
            char event_msg[200];
            sprintf(event_msg, "Инвестиции +%lld руб.", diff);
            add_event(event_msg, 1);
        }
        else if (diff < 0) {
            current_stats.investment_loss += (-diff);
            char event_msg[200];
            sprintf(event_msg, "Инвестиции -%lld руб.", -diff);
            add_event(event_msg, 4);
        }
    }
}

void sell_investment(struct Person* person, int index) {
    if (!person->is_alive) return;
    if (index < 0 || index >= person->investment_count) return;
    if (!person->investments[index].active) return;

    family.family_budget += person->investments[index].current_value;
    person->investments[index].active = false;
    printf("[ИНВЕСТ] %s продал инвестицию. Получено: %lld руб.\n",
        person->name, person->investments[index].current_value);
}

void take_microloan(RUB amount) {
    if (amount <= 0) return;

    family.husband.microloan_debt += amount;
    family.husband.microloan_months = 12;
    family.family_budget += amount;
    current_stats.income += amount;
    printf("[МИКРОЗАЙМ] Взят микрозайм: %lld руб.\n", amount);
    char event_msg[200];
    sprintf(event_msg, "Взят микрозайм %lld руб.", amount);
    add_event(event_msg, 4);
}

void pay_microloan() {
    if (family.husband.microloan_debt <= 0) return;

    if (family.family_budget >= family.husband.microloan_debt * 2) {
        RUB total = family.husband.microloan_debt;
        family.family_budget -= total;
        current_stats.expenses += total;
        current_stats.microloan_payments += total;
        printf("[МИКРОЗАЙМ] Автоматическое полное погашение! Списано: %lld руб.\n", total);
        add_event("Микрозайм погашен досрочно", 1);
        family.husband.microloan_debt = 0;
        family.husband.microloan_months = 0;
        return;
    }

    RUB monthly_payment = (RUB)(family.husband.microloan_debt * config.microloan_rate / 100.0);
    RUB principal = family.husband.microloan_debt / 8;
    RUB total = monthly_payment + principal;

    if (family.family_budget >= total) {
        family.family_budget -= total;
        family.husband.microloan_debt -= principal;
        current_stats.expenses += total;
        current_stats.microloan_payments += total;
        family.husband.microloan_months--;
        family.husband.stress += 5;
        printf("[МИКРОЗАЙМ] Автоматическое погашение: %lld руб. Остаток: %lld руб.\n", total, family.husband.microloan_debt);
        char event_msg[200];
        sprintf(event_msg, "Погашение микрозайма %lld руб.", total);
        add_event(event_msg, 2);

        if (family.husband.microloan_debt <= 0) {
            printf("[МИКРОЗАЙМ] Микрозайм полностью погашен!\n");
            add_event("Микрозайм погашен", 1);
        }
    }
    else {
        if (family.family_budget > monthly_payment) {
            RUB partial_payment = family.family_budget - monthly_payment;
            family.family_budget = 0;
            family.husband.microloan_debt -= partial_payment;
            current_stats.expenses += partial_payment + monthly_payment;
            current_stats.microloan_payments += partial_payment + monthly_payment;
            printf("[МИКРОЗАЙМ] Частичное погашение: %lld руб. Остаток: %lld руб.\n",
                partial_payment + monthly_payment, family.husband.microloan_debt);
        }
        else {
            family.husband.microloan_debt += monthly_payment;
            family.husband.stress += 10;
            printf("[МИКРОЗАЙМ] ПРОСРОЧКА! Добавлены проценты: %lld руб.\n", monthly_payment);
        }
    }

    if (family.husband.microloan_months <= 0) {
        family.husband.microloan_debt = 0;
    }
}

void take_credit(RUB amount, int months) {
    if (amount <= 0) return;

    family.family_credit += amount;
    family.credit_months = months;
    family.family_budget += amount;
    printf("[КРЕДИТ] Взят кредит: %lld руб. на %d мес.\n", amount, months);
    char event_msg[200];
    sprintf(event_msg, "Взят кредит %lld руб. на %d мес.", amount, months);
    add_event(event_msg, 4);
}

void pay_credit() {
    if (family.family_credit <= 0) return;

    RUB monthly_payment = (RUB)(family.family_credit * config.credit_rate / 100.0);
    RUB principal = family.family_credit / family.credit_months;
    RUB total = monthly_payment + principal;

    if (family.family_budget >= total) {
        family.family_budget -= total;
        family.family_credit -= principal;
        current_stats.expenses += total;
        current_stats.credit_payments += total;
        family.credit_months--;
        printf("[КРЕДИТ] Погашено: %lld руб. Остаток: %lld руб.\n", total, family.family_credit);

        if (family.family_credit <= 0) {
            printf("[КРЕДИТ] Кредит полностью погашен!\n");
            add_event("Кредит погашен", 1);
        }
    }
}

void check_microloan_need() {
    if (family.husband.microloan_debt > 0) return;

    if (family.family_budget < -10000) {
        RUB loan = 50000;
        take_microloan(loan);
        family.family_stress += 20;
    }
}


void take_gangster_loan() {
    if (family.family_credit > 0) return;
    if (family.family_budget > -100000) return;

    printf("\n[ВНИМАНИЕ] Семья в критическом финансовом положении!\n");
    printf("Доступен экстренный кредит под %d%% в месяц.\n", (int)config.gangster_rate);
    printf("Взять 100000 руб.? (1-Да, 0-Нет): ");
    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("[ОШИБКА] Введите число!\n");
        while (getchar() != '\n');
        return;
    }
    if (choice == 1) {
        RUB amount = 100000;
        family.family_credit += amount;
        family.credit_months = 24;
        family.family_budget += amount;
        printf("[КРЕДИТ] Взят экстренный кредит: %lld руб. под %d%%/мес\n", amount, (int)config.gangster_rate);
        char event_msg[200];
        sprintf(event_msg, "Взят экстренный кредит %lld руб. под %d%%", amount, (int)config.gangster_rate);
        add_event(event_msg, 4);
    }
}

void person_salary(struct Person* person, int month, int year) {
    if (!person->is_alive || person->in_clinic) return;
    if (person->salary <= 0) return;
    if (!person->career.can_work) return;

    if ((month == 8) && (year == 2026) && (person->salary > 50000)) {
        person->salary = (RUB)(person->salary * 1.5);
        printf("[ПОВЫШЕНИЕ] %s получил повышение! Зарплата: %lld\n", person->name, person->salary);
        char event_msg[200];
        sprintf(event_msg, "%s получил повышение зарплаты до %lld руб.", person->name, person->salary);
        add_event(event_msg, 1);
    }

    if ((month == 1) && (year > 2026)) {
        person->salary = (RUB)(person->salary * 1.1);
        printf("[ИНДЕКСАЦИЯ] %s зарплата проиндексирована: %lld\n", person->name, person->salary);
        char event_msg[200];
        sprintf(event_msg, "%s индексация зарплаты до %lld руб.", person->name, person->salary);
        add_event(event_msg, 1);
    }

    family.family_budget += person->salary;
    current_stats.income += person->salary;
}

void person_food(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;

    RUB salary_factor = (person->salary > 0) ? (person->salary / 10000) : 0;
    RUB actual_food = (RUB)((person->food + salary_factor * 500) * (1 + config.inflation_rate / 100.0 / 12.0));

    family.family_budget -= actual_food;
    current_stats.expenses += actual_food;
    current_stats.food_expenses += actual_food;
}

void person_clothing(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    RUB salary_factor = (person->salary > 0) ? (person->salary / 10000) : 0;
    RUB actual = (RUB)((person->clothing_expenses + salary_factor * 300) * (1 + config.inflation_rate / 100.0 / 12.0));
    family.family_budget -= actual;
    current_stats.expenses += actual;
    current_stats.clothing_expenses += actual;
}

void person_entertainment(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    RUB salary_factor = (person->salary > 0) ? (person->salary / 10000) : 0;
    RUB actual = (RUB)((person->entertainment_expenses + salary_factor * 400) * (1 + config.inflation_rate / 100.0 / 12.0));
    family.family_budget -= actual;
    current_stats.expenses += actual;
    current_stats.entertainment_expenses += actual;
}

void person_household(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    RUB salary_factor = (person->salary > 0) ? (person->salary / 10000) : 0;
    RUB actual = (RUB)((person->household_expenses + salary_factor * 200) * (1 + config.inflation_rate / 100.0 / 12.0));
    family.family_budget -= actual;
    current_stats.expenses += actual;
    current_stats.household_expenses += actual;
}

void person_transport(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    RUB salary_factor = (person->salary > 0) ? (person->salary / 10000) : 0;
    RUB actual = (RUB)((person->transport_expenses + salary_factor * 200) * (1 + config.inflation_rate / 100.0 / 12.0));
    family.family_budget -= actual;
    current_stats.expenses += actual;
    current_stats.transport_expenses += actual;
}

void person_car(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    if (person->car.value <= 0) return;

    family.family_budget -= person->car.gas;
    current_stats.expenses += person->car.gas;

    if (current_stats.month == 1) {
        family.family_budget -= person->car.insurance;
        current_stats.expenses += person->car.insurance;
        char event_msg[200];
        sprintf(event_msg, "Оплачена страховка: %lld руб.", person->car.insurance);
        add_event(event_msg, 2);
    }

    int repair_chance = rand() % 100;
    if (repair_chance < 5) {
        person->car.repair = 50000;
        family.family_budget -= person->car.repair;
        current_stats.unexpected_expenses += person->car.repair;
        person->stress += 10;
        printf("[РЕМОНТ] Ремонт авто: %lld руб.\n", person->car.repair);
        char event_msg[200];
        sprintf(event_msg, "Ремонт автомобиля %lld руб.", person->car.repair);
        add_event(event_msg, 4);
    }
}

void person_utilities(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    RUB actual = person->utilities;
    if ((current_stats.month >= 11) || (current_stats.month <= 3)) {
        actual = (RUB)(person->utilities * 1.3);
    }
    family.family_budget -= actual;
    current_stats.expenses += actual;
}

void person_taxes(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    if (person->salary <= 0) return;
    person->taxes = (RUB)(person->salary * 0.13);
    family.family_budget -= person->taxes;
    current_stats.expenses += person->taxes;
}

void daughter_shopping() {
    if (!family.daughter.is_alive || family.daughter.in_clinic) return;

    if (family.daughter.mental_health >= 50) return;

    int shopping_chance = rand() % 100;
    if (shopping_chance >= 40) return;

    RUB shopping = family.daughter.shopping_spending;
    if (shopping > 7500) shopping = 7500;

    if (family.family_budget >= shopping) {
        family.family_budget -= shopping;
        current_stats.expenses += shopping;
        current_stats.shopping_expenses += shopping;
        current_stats.clothing_expenses += shopping;

        family.daughter.mental_health += 20;
        family.daughter.stress -= 10;

        if (family.daughter.mental_health > 95) family.daughter.mental_health = 95;
        if (family.daughter.stress < 0) family.daughter.stress = 0;

        family.daughter_good_behavior_points += 1;
        char event_msg[200];
        sprintf(event_msg, "Ангелина шопинг: %lld руб.", shopping);
        add_event(event_msg, 2);
    }
}

void daughter_stealing_check() {
    if (!family.daughter.is_alive || family.daughter.in_clinic) return;

    int steal_chance = rand() % 100;
    if (family.daughter.capital < 0 && steal_chance < 10) {
        family.daughter_stole = true;
        family.months_without_stealing = 0;

        RUB stolen = 10000 + (rand() % 5000);
        if (stolen > 15000) stolen = 15000;

        family.family_budget -= stolen;
        family.daughter.capital += stolen;
        current_stats.expenses += stolen;

        family.daughter.mental_health -= 30;
        family.daughter.stress += 25;
        family.family_stress += 15;

        printf("\n[ТРАГЕДИЯ] Ангелина украла %lld руб. у родителей!\n", stolen);
        printf("[НАКАЗАНИЕ] Дочь наказана! Психика -30, Стресс +25\n");
        add_event("Ангелина украла деньги у родителей", 5);

        if (family.daughter.mental_health < 0) family.daughter.mental_health = 0;
    }
    else if (family.daughter.capital >= 0) {
        family.months_without_stealing++;
        if (family.months_without_stealing <= 12) {
            family.daughter_good_behavior_points += 1;
        }
    }
}

void person_mental_health(struct Person* person) {
    if (!person->is_alive) return;

    person->stress += 5;
    person->mental_health -= (person->stress / 10);
    person->mental_health -= 2;

    if (family.family_budget < 50000) {
        person->stress += 10;
        person->mental_health -= 5;
    }

    if (person->microloan_debt > 0 || family.family_credit > 0) {
        person->stress += 15;
        person->mental_health -= 8;
    }

    if (person->mental_health < 30) {
        person->stress += 15;
    }

    if (person->mental_health > 70) {
        person->stress -= 5;
    }

    if (person->stress < 0) person->stress = 0;
    if (person->mental_health < 0) person->mental_health = 0;
    if (person->mental_health > 95) person->mental_health = 95;

    person->mental_health += (rand() % 5) - 2;
    if (person->mental_health > 95) person->mental_health = 95;
    if (person->mental_health < 70) person->mental_health = 70;
}

void daughter_mental_health() {
    if (!family.daughter.is_alive || family.daughter.in_clinic) return;

    family.daughter.mental_health -= 20;
    family.daughter.stress += 18;

    if (family.family_budget < 100000) {
        family.daughter.mental_health -= 12;
        family.daughter.stress += 15;
    }

    if (family.husband.mental_health < 50 || family.wife.mental_health < 50) {
        family.daughter.mental_health -= 15;
    }

    if (family.cat.is_alive) {
        family.daughter.mental_health += 8;
        family.daughter.stress -= 5;
    }

    if (family.daughter.mental_health < 0) family.daughter.mental_health = 0;
    if (family.daughter.mental_health > 85) family.daughter.mental_health = 85;

    family.daughter.mental_health += (rand() % 8) - 4;
    if (family.daughter.mental_health > 85) family.daughter.mental_health = 85;
    if (family.daughter.mental_health < 50) family.daughter.mental_health = 50;
}

void person_health() {
    struct Person* persons[3] = { &family.husband, &family.wife, &family.daughter };

    for (int i = 0; i < 3; i++) {
        if (!persons[i]->is_alive) continue;

        persons[i]->health += (rand() % 5) - 2;
        if (persons[i]->health > 100) persons[i]->health = 100;
        if (persons[i]->health < 95) persons[i]->health = 95;
    }
}

void person_rest(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    person->mental_health += 10;
    person->stress -= 10;
    if (person->mental_health > 95) person->mental_health = 95;
    if (person->stress < 0) person->stress = 0;
}

void person_therapist(struct Person* person) {
    if (!person->is_alive || person->in_clinic) return;
    RUB cost = 15000;
    if (family.family_budget >= cost) {
        family.family_budget -= cost;
        current_stats.expenses += cost;
        current_stats.medical_expenses += cost;
        person->mental_health += 25;
        person->stress -= 20;
        if (person->mental_health > 95) person->mental_health = 95;
        if (person->stress < 0) person->stress = 0;
        printf("[ТЕРАПИЯ] %s посетил психотерапевта за %lld руб.\n", person->name, cost);
        char event_msg[200];
        sprintf(event_msg, "%s терапия за %lld руб.", person->name, cost);
        add_event(event_msg, 2);
    }
}

void person_clinic_check(struct Person* person) {
    if (!person->is_alive) return;
    if (person->mental_health <= 0 && !person->in_clinic) {
        person->in_clinic = true;
        person->stress = 0;
        printf("[КЛИНИКА] %s отправлен в клинику\n", person->name);
        char event_msg[200];
        sprintf(event_msg, "%s отправлен в психиатрическую клинику", person->name);
        add_event(event_msg, 5);
    }
    if (person->in_clinic && person->mental_health > 50) {
        person->in_clinic = false;
        printf("[ВЫПИСКА] %s выписан из клиники\n", person->name);
        char event_msg[200];
        sprintf(event_msg, "%s выписан из клиники", person->name);
        add_event(event_msg, 1);
    }
}

void pet_care() {
    if (!family.dog.is_alive) return;

    family.dog.health -= 2;

    RUB food = family.dog.food_cost;
    family.family_budget -= food;
    current_stats.expenses += food;

    int illness_chance = rand() % 100;
    if (illness_chance < 8 && !family.dog.is_ill) {
        family.dog.is_ill = true;
        family.dog.illness_severity = rand() % 3 + 1;
        printf("\n[БОЛЕЗНЬ] Джина заболела! Тяжесть: %d/3\n", family.dog.illness_severity);
        add_event("Джина заболела", 4);
    }

    if (family.dog.is_ill) {
        RUB vet = family.dog.vet_cost * family.dog.illness_severity;
        family.family_budget -= vet;
        current_stats.medical_expenses += vet;
        family.dog.health -= 10 * family.dog.illness_severity;

        int recovery = rand() % 100;
        if (recovery < 60) {
            family.dog.is_ill = false;
            family.dog.illness_severity = 0;
            printf("[ВЫЗДОРОВЛЕНИЕ] Джина выздоровела!\n");
            add_event("Джина выздоровела", 1);
        }
    }

    int death_chance = rand() % 1000;
    if (family.dog.health <= 0 || death_chance < 3) {
        family.dog.is_alive = false;
        printf("\n[ТРАГЕДИЯ] Джина умерла...\n");
        add_event("Джина умерла", 5);
        family.wife.mental_health -= 20;
        family.daughter.mental_health -= 25;
    }

    if (family.dog.health < 50 && !family.dog.is_ill) {
        RUB vet = family.dog.vet_cost;
        family.family_budget -= vet;
        current_stats.medical_expenses += vet;
        family.dog.health += 30;
        char event_msg[200];
        sprintf(event_msg, "Лечение Джины: %lld руб.", vet);
        add_event(event_msg, 2);
    }
}

void pet_cat_care() {
    if (!family.cat.is_alive) return;

    RUB food = 3000;
    family.family_budget -= food;
    current_stats.expenses += food;

    family.cat.health += 1;  
    if (family.cat.health > 100) family.cat.health = 100;

    int illness_chance = rand() % 100;
    if (illness_chance < 6 && !family.cat.is_ill) {
        family.cat.is_ill = true;
        family.cat.illness_severity = rand() % 3 + 1;
        printf("\n[БОЛЕЗНЬ] Сэм заболел! Тяжесть: %d/3\n", family.cat.illness_severity);
        add_event("Сэм заболел", 4);
    }

    if (family.cat.is_ill) {
        RUB vet = family.cat.vet_cost * family.cat.illness_severity;
        family.family_budget -= vet;
        current_stats.medical_expenses += vet;
        family.cat.health -= 8 * family.cat.illness_severity;

        int recovery = rand() % 100;
        if (recovery < 65) {
            family.cat.is_ill = false;
            family.cat.illness_severity = 0;
            printf("[ВЫЗДОРОВЛЕНИЕ] Сэм выздоровел!\n");
            add_event("Сэм выздоровел", 1);
        }
    }

    int death_chance = rand() % 1500;
    if (family.cat.health <= 0 || death_chance < 2) {
        family.cat.is_alive = false;
        printf("\n[ТРАГЕДИЯ] Сэм умер...\n");
        add_event("Сэм умер", 5);
        family.daughter.mental_health -= 30;
    }

    if (family.cat.health < 50 && !family.cat.is_ill) {
        RUB vet = family.cat.vet_cost;
        family.family_budget -= vet;
        current_stats.medical_expenses += vet;
        family.cat.health += 25;
        char event_msg[200];
        sprintf(event_msg, "Лечение Сэма: %lld руб.", vet);
        add_event(event_msg, 2);
    }

    family.cat.mental_health += 5;
    if (family.cat.mental_health > 100) family.cat.mental_health = 100;
}

void minor_events() {
    int event_type = rand() % 100;
    const char* event_msg = "";
    int type = 0;
    bool affects_daughter_mental = false;
    int mental_decrease = 0;

    if (event_type < 35) {
        int idx = rand() % 13;
        event_msg = minor_events_positive[idx];
        type = 1;
        family.daughter_good_behavior_points += 1;
        printf("[СОБЫТИЕ] %s\n", event_msg);
    }
    else if (event_type < 70) {
        int neg_index = rand() % 13;
        event_msg = minor_events_negative[neg_index];
        type = 4;
        family.family_stress += 2;

        if (neg_index == 1 || neg_index == 4 || neg_index == 10 || neg_index == 13) {
            affects_daughter_mental = true;
            mental_decrease = 8 + (rand() % 7);
        }
        printf("[СОБЫТИЕ] %s\n", event_msg);
    }
    else {
        int idx = rand() % 12;
        event_msg = minor_events_neutral[idx];
        type = 0;
        printf("[СОБЫТИЕ] %s\n", event_msg);
    }

    add_event(event_msg, type);

    if (affects_daughter_mental && family.daughter.is_alive) {
        family.daughter.mental_health -= mental_decrease;
        family.daughter.stress += 5;
        if (family.daughter.mental_health < 0) family.daughter.mental_health = 0;
    }
}

void daughter_exams() {
    if (!family.daughter.is_alive) return;
    if (family.daughter_edu.exams_passed) return;

    if (current_stats.month == 5 && current_stats.year == 2026) {
        printf("\n=== ЭКЗАМЕНЫ АНГЕЛИНЫ ===\n");

        int base_score = 50 + (family.daughter.mental_health / 5);

        if (family.husband.mental_health > 70 && family.wife.mental_health > 70) {
            base_score += 10;
        }

        if (family.family_budget > 200000) {
            base_score += 10;
        }

        if (!family.daughter_stole && family.months_without_stealing >= 3) {
            base_score += 15;
        }

        int random_factor = rand() % 30 - 15;
        family.daughter_edu.exam_score = base_score + random_factor;

        if (family.daughter_edu.exam_score < 0) family.daughter_edu.exam_score = 0;
        if (family.daughter_edu.exam_score > 100) family.daughter_edu.exam_score = 100;

        family.daughter_edu.exams_passed = true;

        printf("Результат экзаменов: %d/100\n", family.daughter_edu.exam_score);

        char event_msg[200];
        sprintf(event_msg, "Экзамены Ангелины: %d/100", family.daughter_edu.exam_score);
        add_event(event_msg, 3);

        if (family.daughter_edu.exam_score >= 80) {
            printf("Отличный результат!\n");
            family.daughter_good_behavior_points += 20;
        }
        else if (family.daughter_edu.exam_score >= 60) {
            printf("Хороший результат.\n");
            family.daughter_good_behavior_points += 10;
        }
        else if (family.daughter_edu.exam_score >= 40) {
            printf("Удовлетворительный результат.\n");
            family.daughter_good_behavior_points += 5;
        }
        else {
            printf("Плохой результат...\n");
        }
    }
}

void daughter_education_choice() {
    if (!family.daughter.is_alive) return;
    if (!family.daughter_edu.exams_passed) return;

    if (family.daughter_edu.enrolled) {
        if (family.daughter_edu.education_level == 1 &&
            family.daughter_edu.can_study_later &&
            family.daughter_edu.exam_score >= 40) {

            RUB base_cost = 0;
            RUB discount = 0;

            if (family.daughter_edu.exam_score >= 80) {
                base_cost = 250000;
                discount = (RUB)(base_cost * 0.20);
            }
            else if (family.daughter_edu.exam_score >= 60) {
                base_cost = 150000;
                discount = (RUB)(base_cost * 0.10);
            }
            else {
                base_cost = 50000;
                discount = 0;
            }

            RUB final_cost = base_cost - discount;

            if (family.family_budget >= final_cost) {
                printf("\n[ИНФО] Появились средства на образование для Ангелины!\n");
                printf("Отправить учиться? (1-Да, 0-Нет): ");
                int choice;
                if (scanf("%d", &choice) != 1) {
                    printf("[ОШИБКА] Введите число!\n");
                    while (getchar() != '\n');
                    return;
                }
                if (choice == 1) {
                    family.daughter_edu.enrolled = false;
                    family.daughter_edu.education_level = 0;
                    family.daughter.career.can_work = false;
                    family.daughter.salary = 0;
                    printf("Ангелина ушла с работы и поступила учиться!\n");
                    add_event("Ангелина начала учиться", 1);
                }
                else {
                    return;
                }
            }
        }
        return;
    }

    if (current_stats.month == 6 && current_stats.year == 2026) {
        printf("\n=== ВЫБОР ОБРАЗОВАНИЯ ===\n");
        printf("Результат экзаменов: %d/100\n", family.daughter_edu.exam_score);

        RUB base_cost = 0;
        RUB discount = 0;

        if (family.daughter_edu.exam_score >= 80) {
            base_cost = 250000;
            discount = (RUB)(base_cost * 0.20);
        }
        else if (family.daughter_edu.exam_score >= 60) {
            base_cost = 150000;
            discount = (RUB)(base_cost * 0.10);
        }
        else if (family.daughter_edu.exam_score >= 40) {
            base_cost = 50000;
            discount = 0;
        }

        RUB final_cost = base_cost - discount;

        if (family.daughter_edu.exam_score >= 80 && family.family_budget >= final_cost) {
            family.daughter_edu.education_level = 3;
            family.daughter_edu.education_cost = final_cost;
            family.daughter_edu.years_remaining = 4;
            char inst[] = "Престижный ВУЗ";
            int i = 0;
            while (inst[i] != '\0' && i < 99) {
                family.daughter_edu.institution[i] = inst[i];
                i++;
            }
            family.daughter_edu.institution[i] = '\0';
            char status[] = "Студентка";
            i = 0;
            while (status[i] != '\0' && i < 49) {
                family.daughter_edu.status[i] = status[i];
                i++;
            }
            family.daughter_edu.status[i] = '\0';
            printf("Ангелина поступила в Престижный ВУЗ! Стоимость: %lld руб. (скидка %lld руб.)\n", final_cost, discount);
            add_event("Ангелина поступила в Престижный ВУЗ", 1);
        }
        else if (family.daughter_edu.exam_score >= 60 && family.family_budget >= final_cost) {
            family.daughter_edu.education_level = 3;
            family.daughter_edu.education_cost = final_cost;
            family.daughter_edu.years_remaining = 4;
            char inst[] = "Обычный ВУЗ";
            int i = 0;
            while (inst[i] != '\0' && i < 99) {
                family.daughter_edu.institution[i] = inst[i];
                i++;
            }
            family.daughter_edu.institution[i] = '\0';
            char status[] = "Студентка";
            i = 0;
            while (status[i] != '\0' && i < 49) {
                family.daughter_edu.status[i] = status[i];
                i++;
            }
            family.daughter_edu.status[i] = '\0';
            printf("Ангелина поступила в ВУЗ! Стоимость: %lld руб. (скидка %lld руб.)\n", final_cost, discount);
            add_event("Ангелина поступила в ВУЗ", 1);
        }
        else if (family.daughter_edu.exam_score >= 40 && family.family_budget >= final_cost) {
            family.daughter_edu.education_level = 2;
            family.daughter_edu.education_cost = final_cost;
            family.daughter_edu.years_remaining = 2;
            char inst[] = "Колледж";
            int i = 0;
            while (inst[i] != '\0' && i < 99) {
                family.daughter_edu.institution[i] = inst[i];
                i++;
            }
            family.daughter_edu.institution[i] = '\0';
            char status[] = "Студентка";
            i = 0;
            while (status[i] != '\0' && i < 49) {
                family.daughter_edu.status[i] = status[i];
                i++;
            }
            family.daughter_edu.status[i] = '\0';
            printf("Ангелина поступила в Колледж! Стоимость: %lld руб.\n", final_cost);
            add_event("Ангелина поступила в Колледж", 1);
        }
        else {
            family.daughter_edu.education_level = 1;
            family.daughter_edu.education_cost = 0;
            family.daughter_edu.years_remaining = 0;
            char inst[] = "Низкоквалифицированная работа";
            int i = 0;
            while (inst[i] != '\0' && i < 99) {
                family.daughter_edu.institution[i] = inst[i];
                i++;
            }
            family.daughter_edu.institution[i] = '\0';
            printf("Ангелина вынуждена идти на низкоквалифицированную работу - нет денег на образование (у вас %lld руб.).\n", family.family_budget);
            printf("(Если появятся средства, она сможет поступить позже)\n");
            family.daughter_edu.can_study_later = true;
            add_event("Ангелина пошла на работу (нет денег)", 3);
        }

        if (family.daughter_edu.education_cost > 0) {
            if (family.family_budget >= family.daughter_edu.education_cost) {
                family.family_budget -= family.daughter_edu.education_cost;
                current_stats.expenses += family.daughter_edu.education_cost;
                current_stats.education_expenses += family.daughter_edu.education_cost;
            }
            else {
                printf("[ИНФО] Доступен кредит на образование. Взять? (1-Да, 0-Нет): ");
                int take_credit_choice;
                if (scanf("%d", &take_credit_choice) != 1) {
                    printf("[ОШИБКА] Введите число!\n");
                    while (getchar() != '\n');
                    return;
                }
                if (take_credit_choice == 1) {
                    take_credit(family.daughter_edu.education_cost, 36);
                    family.family_budget -= family.daughter_edu.education_cost;
                    current_stats.expenses += family.daughter_edu.education_cost;
                    current_stats.education_expenses += family.daughter_edu.education_cost;
                }
                else {
                    printf("[ОШИБКА] Недостаточно средств! Ангелина идёт на работу.\n");
                    family.daughter_edu.education_level = 1;
                    family.daughter_edu.years_remaining = 0;
                    family.daughter_edu.can_study_later = true;
                }
            }
        }

        family.daughter_edu.enrolled = true;

        if (family.daughter_edu.education_level >= 2) {
            family.daughter.career.can_work = false;
        }
        else {
            family.daughter.career.can_work = true;
            family.daughter.salary = 25000;
            init_career(&family.daughter.career, 1, "Низкоквалифицированный работник", 25000);
            printf("Ангелина устроилась на работу. Зарплата: %lld руб./мес\n", family.daughter.salary);
        }
    }
}

void daughter_education_progress() {
    if (!family.daughter.is_alive) return;
    if (!family.daughter_edu.enrolled) return;
    if (family.daughter_edu.years_remaining <= 0) return;

    if (current_stats.month == 6) {
        family.daughter_edu.years_remaining--;
        printf("[ОБРАЗОВАНИЕ] Год обучения завершён. Осталось: %d\n", family.daughter_edu.years_remaining);

        if (family.daughter_edu.years_remaining <= 0) {
            family.daughter_edu.enrolled = false;
            family.daughter.career.can_work = true;

            if (family.daughter_edu.education_level == 3) {
                family.daughter.salary = 150000;
                init_career(&family.daughter.career, 2, "Младший специалист", 150000);
                printf("[ВЫПУСК] Ангелина окончила ВУЗ! Зарплата: %lld\n", family.daughter.salary);
                add_event("Ангелина окончила ВУЗ", 1);
            }
            else if (family.daughter_edu.education_level == 2) {
                family.daughter.salary = 80000;
                init_career(&family.daughter.career, 1, "Специалист", 80000);
                printf("[ВЫПУСК] Ангелина окончила Колледж! Зарплата: %lld\n", family.daughter.salary);
                add_event("Ангелина окончила Колледж", 1);
            }
        }
    }
}

void major_purchase_check() {
    if (family.made_major_purchase) return;
    if (family.family_budget < 2000000) return;

    printf("\n[ИНФО] Семья накопила достаточно средств для крупной покупки!\n");
    printf("1. Купить новую квартиру (1500000 руб.) +20 к психике всех\n");
    printf("2. Купить дачу (1000000 руб.) +15 к психике всех\n");
    printf("3. Отложить деньги\n");
    printf("Выбор: ");

    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("[ОШИБКА] Введите число!\n");
        while (getchar() != '\n');
        return;
    }

    if (choice == 1) {
        family.family_budget -= 1500000;
        current_stats.expenses += 1500000;
        family.husband.mental_health += 20;
        family.wife.mental_health += 20;
        family.daughter.mental_health += 20;
        family.made_major_purchase = true;
        char purchase[] = "Квартира";
        int i = 0;
        while (purchase[i] != '\0' && i < 99) {
            family.major_purchase_name[i] = purchase[i];
            i++;
        }
        family.major_purchase_name[i] = '\0';
        if (family.husband.mental_health > 95) family.husband.mental_health = 95;
        if (family.wife.mental_health > 95) family.wife.mental_health = 95;
        if (family.daughter.mental_health > 85) family.daughter.mental_health = 85;
        printf("[ПОКУПКА] Семья купила новую квартиру!\n");
        add_event("Куплена квартира", 1);
    }
    else if (choice == 2) {
        family.family_budget -= 1000000;
        current_stats.expenses += 1000000;
        family.husband.mental_health += 15;
        family.wife.mental_health += 15;
        family.daughter.mental_health += 15;
        family.made_major_purchase = true;
        char purchase[] = "Дача";
        int i = 0;
        while (purchase[i] != '\0' && i < 99) {
            family.major_purchase_name[i] = purchase[i];
            i++;
        }
        family.major_purchase_name[i] = '\0';
        if (family.husband.mental_health > 95) family.husband.mental_health = 95;
        if (family.wife.mental_health > 95) family.wife.mental_health = 95;
        if (family.daughter.mental_health > 85) family.daughter.mental_health = 85;
        printf("[ПОКУПКА] Семья купила дачу!\n");
        add_event("Куплена дача", 1);
    }
}

void random_event(struct Person* person, const char* role) {
    if (!person->is_alive || person->in_clinic) return;

    int event = rand() % 1000;

    if (event < 2) {
        person->health -= 50;
        RUB hospital = 100000;
        family.family_budget -= hospital;
        current_stats.medical_expenses += hospital;
        printf("[СОБЫТИЕ] %s %s попал в больницу! Здоровье -50, расходы %lld руб.\n", role, person->name, hospital);
        char event_msg[200];
        sprintf(event_msg, "%s госпитализация %lld руб.", person->name, hospital);
        add_event(event_msg, 5);
    }
    else if (event < 5) {
        RUB loss = 50000;
        family.family_budget -= loss;
        current_stats.unexpected_expenses += loss;
        printf("[СОБЫТИЕ] %s %s потерял кошелёк! Потеря %lld руб.\n", role, person->name, loss);
        char event_msg[200];
        sprintf(event_msg, "%s потерял кошелёк %lld руб.", person->name, loss);
        add_event(event_msg, 4);
    }
    else if (event < 8) {
        person->health -= 20;
        RUB medicine = 30000;
        family.family_budget -= medicine;
        current_stats.medical_expenses += medicine;
        printf("[СОБЫТИЕ] %s %s заболел! Здоровье -20, лекарства %lld руб.\n", role, person->name, medicine);
        char event_msg[200];
        sprintf(event_msg, "%s болезнь лекарства %lld руб.", person->name, medicine);
        add_event(event_msg, 4);
    }
    else if (event < 10 && person->car.value > 0) {
        int accident = rand() % 100;
        if (accident < 30) {
            person->is_alive = false;
            deaths_count++;
            printf("[СОБЫТИЕ] %s %s погиб в ДТП!\n", role, person->name);
            char event_msg[200];
            sprintf(event_msg, "%s погиб в ДТП", person->name);
            add_event(event_msg, 5);
        }
        else {
            person->health -= 40;
            RUB repair = 200000;
            family.family_budget -= repair;
            current_stats.unexpected_expenses += repair;
            printf("[СОБЫТИЕ] %s %s попал в аварию! Здоровье -40, ремонт %lld руб.\n", role, person->name, repair);
            char event_msg[200];
            sprintf(event_msg, "%s авария ремонт %lld руб.", person->name, repair);
            add_event(event_msg, 5);
        }
    }
    else if (event < 13) {
        RUB fine = 10000;
        family.family_budget -= fine;
        current_stats.unexpected_expenses += fine;
        printf("[СОБЫТИЕ] %s %s получил штраф! %lld руб.\n", role, person->name, fine);
        char event_msg[200];
        sprintf(event_msg, "%s штраф %lld руб.", person->name, fine);
        add_event(event_msg, 4);
    }
    else if (event < 20) {
        RUB bonus = person->salary / 4;
        family.family_budget += bonus;
        current_stats.income += bonus;
        printf("[СОБЫТИЕ] %s %s нашёл деньги! +%lld руб.\n", role, person->name, bonus);
        char event_msg[200];
        sprintf(event_msg, "%s нашёл деньги %lld руб.", person->name, bonus);
        add_event(event_msg, 1);
    }
    else if (event < 28) {
        RUB inheritance = 200000;
        family.family_budget += inheritance;
        current_stats.income += inheritance;
        printf("[СОБЫТИЕ] %s %s получил наследство! +%lld руб.\n", role, person->name, inheritance);
        char event_msg[200];
        sprintf(event_msg, "%s наследство %lld руб.", person->name, inheritance);
        add_event(event_msg, 1);
    }
    else if (event < 32) {
        person->stress += 20;
        person->mental_health -= 15;
        printf("[СОБЫТИЕ] %s %s пережил сильный стресс! Психика -15\n", role, person->name);
        char event_msg[200];
        sprintf(event_msg, "%s сильный стресс", person->name);
        add_event(event_msg, 4);
    }
    else if (event < 40) {
        RUB lottery = 100000;
        family.family_budget += lottery;
        current_stats.income += lottery;
        printf("[СОБЫТИЕ] %s %s выиграл в лотерею! +%lld руб.\n", role, person->name, lottery);
        char event_msg[200];
        sprintf(event_msg, "%s выиграл в лотерею %lld руб.", person->name, lottery);
        add_event(event_msg, 1);
    }
}

void major_life_event() {
    int event = rand() % 100;

    if (event < 2) {
        printf("\n[КРИЗИС] Экономический кризис! Инфляция выросла до 25%%\n");
        config.inflation_rate = 25.0;
        family.husband.salary = (RUB)(family.husband.salary * 0.7);
        family.wife.salary = (RUB)(family.wife.salary * 0.7);
        add_event("Экономический кризис", 5);
    }
    else if (event < 8) {
        printf("\n[БУМ] Экономический рост! Зарплаты выросли на 30%%\n");
        family.husband.salary = (RUB)(family.husband.salary * 1.3);
        family.wife.salary = (RUB)(family.wife.salary * 1.3);
        config.bank_rate = 20.0;
        add_event("Экономический рост", 1);
    }
    else if (event < 10) {
        printf("\n[ПОЖАР] Пожар в квартире! Ущерб 500000 руб.\n");
        RUB damage = 500000;
        family.family_budget -= damage;
        current_stats.unexpected_expenses += damage;
        add_event("Пожар в квартире", 5);
    }
    else if (event < 12) {
        printf("\n[КРАЖА] Квартиру обокрали! Потеряно 150000 руб.\n");
        RUB theft = 150000;
        family.family_budget -= theft;
        current_stats.unexpected_expenses += theft;
        add_event("Квартиру обокрали", 5);
    }
}

void bank_interest() {
    PERCENT monthly_rate = config.bank_rate / 12.0 / 100.0;
    RUB interest = (RUB)(family.family_budget * monthly_rate);

    family.family_budget += interest;
    current_stats.bank_interest += interest;
    current_stats.income += interest;

    if (interest > 1000) {
        char event_msg[200];
        sprintf(event_msg, "Банковский процент: +%lld руб.", interest);
        add_event(event_msg, 1);
    }
}

void check_bankruptcy() {
    RUB total_debt = family.husband.microloan_debt + family.wife.microloan_debt + family.daughter.microloan_debt + family.family_credit;
    if (family.family_budget < 0 || total_debt > 500000) {
        if (family.family_budget >= -500000) {
            bankruptcy_months++;
            if (bankruptcy_months == 1) {
                add_event("Начало банкротства", 5);
            }
        }
    }
    else {
        bankruptcy_months = 0;
    }
}

void check_death(struct Person* person, const char* role) {
    if (!person->is_alive) return;

    if (person->health <= 0) {
        person->is_alive = false;
        deaths_count++;
        printf("\n[ТРАГЕДИЯ] %s %s погиб из-за проблем со здоровьем.\n", role, person->name);
        char event_msg[200];
        sprintf(event_msg, "%s погиб (здоровье)", person->name);
        add_event(event_msg, 5);
    }

    if (family.family_budget < -500000) {
        person->is_alive = false;
        person->died_from_debt = true;
        deaths_count++;
        printf("\n[ТРАГЕДИЯ] %s %s погиб.\n", role, person->name);
        char event_msg[200];
        sprintf(event_msg, "%s погиб (долги)", person->name);
        add_event(event_msg, 5);
    }
}

void check_poverty_death() {
    if (family.family_budget <= -500000) {
        bankruptcy_months++;
        if (bankruptcy_months >= 2) {
            printf("\n");
            printf("################################################################\n");
            printf("#                                                              #\n");
            printf("#             С  М  Е  Р  Т  Ь    В    Н  И  Щ  Е  Т  Е        #\n");
            printf("#                      П  А  С  Х  А  Л  К  А                  #\n");
            printf("#                                                              #\n");
            printf("################################################################\n");
            printf("#                                                              #\n");
            printf("#      Ваша семья погибла от непосильных долгов...             #\n");
            printf("#                                                              #\n");
            printf("#      Иногда жадность,  неправильные решения                  #\n");
            printf("#      и неудачи приводят к фатальному концу.                  #\n");
            printf("#                                                              #\n");
            printf("#      Попробуйте начать сначала и сделать другой выбор!       #\n");
            printf("#                                                              #\n");
            printf("################################################################\n");

            if (family.husband.is_alive) {
                family.husband.is_alive = false;
                family.husband.died_from_debt = true;
                deaths_count++;
                add_event("  (  )", 5);
            }
            if (family.wife.is_alive) {
                family.wife.is_alive = false;
                family.wife.died_from_debt = true;
                deaths_count++;
                add_event("  (  )", 5);
            }
            if (family.daughter.is_alive) {
                family.daughter.is_alive = false;
                family.daughter.died_from_debt = true;
                deaths_count++;
                add_event("  (  )", 5);
            }

            add_event("   -  ", 5);
            simulation_ended = true;
        }
    }
    else {
        bankruptcy_months = 0;
    }
}

void check_orphanage() {
    if (!family.husband.is_alive && !family.wife.is_alive && family.daughter.is_alive && !daughter_in_orphanage) {
        daughter_in_orphanage = true;
        family.daughter.is_alive = false;
        deaths_count++;
        printf("\n[ТРАГЕДИЯ] Оба родителя погибли. Ангелина забрана в приют.\n");
        printf("[КОНЕЦ] Симуляция завершена - дочь в приюте.\n");
        add_event("Ангелина забрана в приют", 5);
        simulation_ended = true;
    }
}

void check_gang_attack() {
    if (family.gang_attacked) return;
    if (family.husband.microloan_months <= 0) return;

    int months_overdue = 12 - family.husband.microloan_months;
    if (months_overdue > 4) {
        family.gang_attacked = true;
        family.husband.health -= 15;
        RUB loss = 5000;
        family.family_budget -= loss;
        current_stats.gang_attack_loss += loss;
        current_stats.unexpected_expenses += loss;

        printf("\n[НАПАДЕНИЕ] На Дениса напали неизвестные! Требуют вернуть микрозайм!\n");
        printf("Потери: Здоровье -15, Деньги -%lld руб.\n", loss);
        add_event("Нападение бандитов", 5);

        if (family.husband.health <= 0) {
            family.husband.is_alive = false;
            deaths_count++;
            printf("[ТРАГЕДИЯ] Денис погиб от полученных травм!\n");
        }
    }
}

void print_family_status() {
    printf("\n========================================\n");
    printf("СТАТУС СЕМЬИ (Месяц %d)\n", total_months + 1);
    printf("========================================\n");
    printf("Общий бюджет семьи: %lld руб.\n", family.family_budget);
    if (family.husband.microloan_debt > 0 || family.family_credit > 0) {
        printf("МИКРОЗАЙМЫ: %lld руб. | КРЕДИТ: %lld руб.\n",
            family.husband.microloan_debt, family.family_credit);
    }
    printf("Денис: Психика=%d, Здоровье=%d, Жив=%d\n",
        family.husband.mental_health, family.husband.health, family.husband.is_alive);
    printf("  Карьера: %s (Уровень %d)\n", family.husband.career.position, family.husband.career.level);
    printf("  Инвестиций: %d\n", family.husband.investment_count);
    printf("Алиса: Психика=%d, Здоровье=%d, Жив=%d\n",
        family.wife.mental_health, family.wife.health, family.wife.is_alive);
    printf("  Карьера: %s (Уровень %d)\n", family.wife.career.position, family.wife.career.level);
    printf("  Инвестиций: %d\n", family.wife.investment_count);
    printf("Ангелина: Психика=%d, Жив=%d, Статус: %s\n",
        family.daughter.mental_health, family.daughter.is_alive, family.daughter_edu.status);
    printf("  Образование: %s (Осталось лет: %d)\n", family.daughter_edu.institution, family.daughter_edu.years_remaining);
    printf("  Поведение: %d очков (Без краж: %d мес.)\n",
        family.daughter_good_behavior_points, family.months_without_stealing);
    printf("Джина (собака): Здоровье=%d, Жива=%d, Состояние: %s%s\n",
        family.dog.health, family.dog.is_alive,
        family.dog.is_ill ? "Болеет (тяжесть " : "Здоров",
        family.dog.is_ill ? "%d/3)" : "");
    if (family.dog.is_ill) {
        printf("                                     Тяжесть: %d/3\n", family.dog.illness_severity);
    }
    if (family.cat.is_alive) {
        printf("Сэм (кот): Здоровье=%d, Жив=%d%s, Состояние: %s",
            family.cat.health, family.cat.is_alive,
            family.cat.is_stray ? " (подобран)" : "",
            family.cat.is_ill ? "Болеет" : "Здоров");
        if (family.cat.is_ill) {
            printf(" (тяжесть %d/3)", family.cat.illness_severity);
        }
        printf("\n");
    }
    if (family.made_major_purchase) {
        printf("Крупная покупка: %s\n", family.major_purchase_name);
    }
    printf("Банкротство месяцев: %d\n", bankruptcy_months);
    printf("========================================\n");
}

void show_menu() {
    printf("\n========================================\n");
    printf("           ГЛАВНОЕ МЕНЮ (Месяц %d)      \n", total_months + 1);
    printf("========================================\n");
    printf("1. Продолжить симуляцию (следующий месяц)\n");
    printf("2. Показать статус семьи\n");
    printf("3. Купить инвестиции\n");
    printf("4. Пройти обучение (35000 руб) +1 месяц\n");
    printf("5. Поехать в отпуск (50000 руб) +1 месяц\n");
    printf("6. Санаторий (30000 руб) +1 месяц\n");
    printf("7. Сохранить игру\n");
    printf("8. Загрузить игру\n");
    printf("9. Выйти из игры\n");
    printf("========================================\n");
    printf("Ваш выбор: ");
}

void investment_menu() {
    printf("\n========================================\n");
    printf("           ИНВЕСТИЦИИ                  \n");
    printf("========================================\n");
    printf("1. Акции - %lld руб./шт. (риск: средний)\n", market.stocks_price);
    printf("2. Облигации - %lld руб./шт. (риск: низкий)\n", market.bonds_price);
    printf("3. Криптовалюта - %lld руб./шт. (риск: высокий)\n", market.crypto_price);
    printf("4. Недвижимость - %lld руб./шт. (риск: низкий)\n", market.realty_price);
    printf("5. Назад в главное меню\n");
    printf("----------------------------------------\n");
    printf("Общий бюджет семьи: %lld руб.\n", family.family_budget);
    printf("----------------------------------------\n");
    printf("ВАШИ ИНВЕСТИЦИИ:\n");

    struct Person* persons[3] = { &family.husband, &family.wife, &family.daughter };
    const char* names[3] = { "Денис", "Алиса", "Ангелина" };

    for (int p = 0; p < 3; p++) {
        for (int i = 0; i < persons[p]->investment_count; i++) {
            if (persons[p]->investments[i].active) {
                printf("  %s: %s (%d шт.) - %lld руб.\n",
                    names[p],
                    persons[p]->investments[i].type,
                    persons[p]->investments[i].quantity,
                    persons[p]->investments[i].current_value);
            }
        }
    }
    printf("========================================\n");
    printf("Ваш выбор: ");
}

void process_month_actions() {
    person_food(&family.husband);
    person_food(&family.wife);
    person_food(&family.daughter);

    person_clothing(&family.husband);
    person_clothing(&family.wife);
    person_clothing(&family.daughter);

    person_entertainment(&family.husband);
    person_entertainment(&family.wife);
    person_entertainment(&family.daughter);

    person_household(&family.husband);
    person_household(&family.wife);
    person_household(&family.daughter);

    person_transport(&family.husband);
    person_transport(&family.wife);
    person_transport(&family.daughter);

    person_car(&family.husband);
    person_car(&family.wife);

    person_utilities(&family.husband);
    person_utilities(&family.wife);

    person_taxes(&family.husband);
    person_taxes(&family.wife);

    pet_care();
    pet_cat_care();

    bank_interest();

    check_microloan_need();

    if (family.family_budget < -100000) {
        take_gangster_loan();
    }

    pay_microloan();
    pay_credit();

    update_investments(&family.husband);
    update_investments(&family.wife);

    auto_sell_investments();

    person_salary(&family.husband, current_stats.month, current_stats.year);
    person_salary(&family.wife, current_stats.month, current_stats.year);
    person_salary(&family.daughter, current_stats.month, current_stats.year);

    daughter_shopping();
    daughter_stealing_check();

    person_mental_health(&family.husband);
    person_mental_health(&family.wife);
    daughter_mental_health();

    person_health();

    if (family.husband.mental_health < 30) person_therapist(&family.husband);
    if (family.wife.mental_health < 30) person_therapist(&family.wife);
    if (family.daughter.mental_health < 30) person_therapist(&family.daughter);

    person_rest(&family.husband);
    person_rest(&family.wife);
    person_rest(&family.daughter);

    person_clinic_check(&family.husband);
    person_clinic_check(&family.wife);
    person_clinic_check(&family.daughter);

    career_level_up(&family.husband);
    career_level_up(&family.wife);
    career_bonus(&family.husband);
    career_bonus(&family.wife);

    daughter_exams();
    daughter_education_choice();
    daughter_education_progress();

    check_new_pet();

    minor_events();

    random_event(&family.husband, "Муж");
    random_event(&family.wife, "Жена");
    random_event(&family.daughter, "Дочь");

    major_life_event();

    major_purchase_check();

    check_bankruptcy();

    check_death(&family.husband, "Муж");
    check_death(&family.wife, "Жена");
    check_death(&family.daughter, "Дочь");

    check_poverty_death();
    check_orphanage();

    check_gang_attack();  
}

void vacation_trip() {
    RUB cost = 50000;

    if (family.family_budget < cost) {
        printf("[ОШИБКА] Недостаточно средств! Нужно %lld руб.\n", cost);
        return;
    }

    family.family_budget -= cost;
    current_stats.expenses += cost;
    current_stats.vacation_expenses += cost;
    current_stats.entertainment_expenses += cost;

    family.husband.mental_health += 20;
    family.wife.mental_health += 20;
    family.daughter.mental_health += 15;
    family.husband.stress -= 15;
    family.wife.stress -= 15;

    if (family.husband.mental_health > 95) family.husband.mental_health = 95;
    if (family.wife.mental_health > 95) family.wife.mental_health = 95;
    if (family.daughter.mental_health > 85) family.daughter.mental_health = 85;
    if (family.husband.stress < 0) family.husband.stress = 0;
    if (family.wife.stress < 0) family.wife.stress = 0;

    printf("[ОТПУСК] Семья отдохнула за %lld руб.! Психика +20\n", cost);
    add_event("Семейный отпуск", 1);
}

void sanatorium_trip() {
    RUB cost = 30000;

    if (family.family_budget < cost) {
        printf("[ОШИБКА] Недостаточно средств! Нужно %lld руб.\n", cost);
        return;
    }

    family.family_budget -= cost;
    current_stats.expenses += cost;
    current_stats.sanatorium_expenses += cost;
    current_stats.medical_expenses += cost;

    family.husband.health += 10;
    family.wife.health += 10;
    family.husband.mental_health += 15;
    family.wife.mental_health += 15;

    if (family.husband.health > 100) family.husband.health = 100;
    if (family.wife.health > 100) family.wife.health = 100;
    if (family.husband.mental_health > 95) family.husband.mental_health = 95;
    if (family.wife.mental_health > 95) family.wife.mental_health = 95;

    printf("[САНАТОРИЙ] Семья прошла оздоровление за %lld руб.! Здоровье +10\n", cost);
    add_event("Санаторий", 1);
}

void print_event_log() {
    printf("\n========================================\n");
    printf("         ЖУРНАЛ СОБЫТИЙ                \n");
    printf("========================================\n");
    printf("Всего событий: %d\n", event_count);
    printf("----------------------------------------\n");

    int positive_count = 0;
    int negative_count = 0;
    int neutral_count = 0;

    for (int i = 0; i < event_count; i++) {
        if (event_log[i].type == 1) positive_count++;
        else if (event_log[i].type == 4 || event_log[i].type == 5) negative_count++;
        else neutral_count++;
    }

    printf("Позитивные: %d | Нейтральные: %d | Негативные: %d\n", positive_count, neutral_count, negative_count);
    printf("----------------------------------------\n");

    for (int i = 0; i < event_count; i++) {
        const char* type_str = "";
        switch (event_log[i].type) {
        case 0: type_str = "[СИСТЕМА]"; break;
        case 1: type_str = "[ХОРОШО]"; break;
        case 2: type_str = "[ТРАТА]"; break;
        case 3: type_str = "[КАРЬЕРА]"; break;
        case 4: type_str = "[ПРОБЛЕМА]"; break;
        case 5: type_str = "[ТРАГЕДИЯ]"; break;
        }
        printf("%03d. %s Мес.%d: %s\n", i + 1, type_str, event_log[i].month, event_log[i].description);
    }
    printf("========================================\n");
}

void print_month_summary() {
    printf("\n========================================\n");
    printf("         ИТОГИ МЕСЯЦА %d               \n", total_months);
    printf("========================================\n");
    printf("ДОХОДЫ:\n");
    printf("  Зарплаты: %lld руб.\n", current_stats.income - current_stats.bank_interest - current_stats.investment_income - current_stats.career_bonus);
    printf("  Банковский процент: %lld руб.\n", current_stats.bank_interest);
    printf("  Доход от инвестиций: %lld руб.\n", current_stats.investment_income);
    printf("  Премии: %lld руб.\n", current_stats.career_bonus);
    printf("РАСХОДЫ:\n");
    printf("  Еда: %lld руб.\n", current_stats.food_expenses);
    printf("  Одежда: %lld руб.\n", current_stats.clothing_expenses);
    printf("  Развлечения: %lld руб.\n", current_stats.entertainment_expenses);
    printf("  Бытовые нужды: %lld руб.\n", current_stats.household_expenses);
    printf("  Транспорт: %lld руб.\n", current_stats.transport_expenses);
    printf("  Шопоголизм: %lld руб.\n", current_stats.shopping_expenses);
    printf("  Образование: %lld руб.\n", current_stats.education_expenses);
    printf("  Отпуск/Санаторий: %lld руб.\n", current_stats.vacation_expenses + current_stats.sanatorium_expenses);
    printf("  Медицина: %lld руб.\n", current_stats.medical_expenses);
    printf("  Микрозаймы: %lld руб.\n", current_stats.microloan_payments);
    printf("  Кредиты: %lld руб.\n", current_stats.credit_payments);
    printf("  Непредвиденные: %lld руб.\n", current_stats.unexpected_expenses);
    printf("  Потери от инвестиций: %lld руб.\n", current_stats.investment_loss);
    if (current_stats.gang_attack_loss > 0) {
        printf("  Нападение бандитов: %lld руб.\n", current_stats.gang_attack_loss);
    }
    printf("----------------------------------------\n");
    printf("БАЛАНС МЕСЯЦА: %lld руб.\n", current_stats.income - current_stats.expenses);
    printf("========================================\n");
}

void print_final_summary() {
    printf("\n");
    printf("??????????????????????????????????????????\n");
    printf("?         ИТОГИ СИМУЛЯЦИИ                ?\n");
    printf("??????????????????????????????????????????\n");
    printf("? ПРОЖИТО МЕСЯЦЕВ: %-21d ?\n", total_months);
    printf("??????????????????????????????????????????\n");
    printf("? ГЛАВНЫЕ ДОСТИЖЕНИЯ:                    ?\n");

    if (family.daughter_edu.education_level == 3) {
        printf("? ? Дочь окончила ВУЗ                    ?\n");
    }
    else if (family.daughter_edu.education_level == 2) {
        printf("? ? Дочь окончила Колледж                ?\n");
    }

    if (family.husband.career.level >= 4 || family.wife.career.level >= 4) {
        printf("? ? Кто-то из родителей стал руководителем ?\n");
    }

    if (family.cat.is_alive) {
        printf("? ? В семье появился кот Сэм             ?\n");
    }

    if (family.made_major_purchase) {
        printf("? ? Совершена крупная покупка            ?\n");
    }

    if (total_income > 5000000) {
        printf("? ? Заработано более 5 млн руб.          ?\n");
    }

    if (bankruptcy_months == 0) {
        printf("? ? Ни одного месяца банкротства         ?\n");
    }

    printf("??????????????????????????????????????????\n");
    printf("? НЕУДАЧИ:                               ?\n");

    bool has_failures = false;

    if (deaths_count > 0) {
        printf("? Погибло членов семьи: %-16d ?\n", deaths_count);
        has_failures = true;
    }

    if (bankruptcy_months > 0) {
        printf("? Месяцев банкротства: %-17d ?\n", bankruptcy_months);
        has_failures = true;
    }

    if (family.gang_attacked) {
        printf("? Было нападение бандитов              ?\n");
        has_failures = true;
    }

    if (!has_failures) {
        printf("? -                                      ?\n");
    }

    printf("??????????????????????????????????????????\n");
}

void print_results() {
    printf("\n");
    printf("========================================\n");
    printf("         ИТОГОВЫЕ РЕЗУЛЬТАТЫ            \n");
    printf("========================================\n");
    printf("Период: %d месяцев\n", total_months);
    printf("Денис: %s, Долг=%lld\n",
        family.husband.is_alive ? "Жив" : "Мёртв", family.husband.microloan_debt);
    printf("  Карьера: %s (Уровень %d)\n", family.husband.career.position, family.husband.career.level);
    printf("Алиса: %s, Долг=%lld\n",
        family.wife.is_alive ? "Жив" : "Мёртв", family.wife.microloan_debt);
    printf("  Карьера: %s (Уровень %d)\n", family.wife.career.position, family.wife.career.level);
    printf("Ангелина: %s\n",
        family.daughter.is_alive ? "Жива" : "Мертва");
    printf("  Статус: %s\n", family.daughter_edu.status);
    printf("  Образование: %s\n", family.daughter_edu.institution);
    printf("  Экзамены: %d/100\n", family.daughter_edu.exam_score);
    printf("  Поведение: %d очков\n", family.daughter_good_behavior_points);
    printf("Джина: %s\n", family.dog.is_alive ? "Жива" : "Мертва");
    if (family.cat.is_alive) {
        printf("Сэм (кот): %s%s\n", family.cat.is_alive ? "Жив" : "Мертв",
            family.cat.is_stray ? " (подобран)" : "");
    }
    if (family.made_major_purchase) {
        printf("Крупная покупка: %s\n", family.major_purchase_name);
    }
    printf("----------------------------------------\n");
    printf("ФИНАНСОВЫЙ ОТЧЁТ:\n");
    printf("----------------------------------------\n");
    printf("ОБЩИЙ БЮДЖЕТ: %lld руб.\n", family.family_budget);
    printf("КРЕДИТЫ: %lld руб.\n", family.family_credit);
    printf("ВСЕГО ЗАРАБОТАНО: %lld руб.\n", total_income);
    printf("ВСЕГО ПОТРАЧЕНО:  %lld руб.\n", total_expenses);
    printf("БАЛАНС:           %lld руб.\n", total_income - total_expenses);
    printf("----------------------------------------\n");
    printf("Детализация доходов:\n");
    printf("  Доход от инвестиций: %lld руб.\n", current_stats.investment_income);
    printf("  Премии по карьере:   %lld руб.\n", current_stats.career_bonus);
    printf("Детализация расходов:\n");
    printf("  Потери от инвестиций: %lld руб.\n", current_stats.investment_loss);
    printf("  Выплачено микрозаймов: %lld руб.\n", current_stats.microloan_payments);
    printf("  Выплачено кредитов:    %lld руб.\n", current_stats.credit_payments);
    printf("  Шопоголизм дочери:     %lld руб.\n", current_stats.shopping_expenses);
    printf("  Образование:           %lld руб.\n", current_stats.education_expenses);
    printf("  Отпуск:                %lld руб.\n", current_stats.vacation_expenses);
    printf("  Санаторий:             %lld руб.\n", current_stats.sanatorium_expenses);
    printf("  Непредвиденные:        %lld руб.\n", current_stats.unexpected_expenses);
    printf("  Медицина:              %lld руб.\n", current_stats.medical_expenses);
    if (current_stats.gang_attack_loss > 0) {
        printf("  Нападение бандитов:    %lld руб.\n", current_stats.gang_attack_loss);
    }
    printf("========================================\n");

    print_event_log();
    print_final_summary();
}

void save_to_file() {
    ofstream outfile;
    outfile.open("report.txt");

    if (outfile.is_open()) {
        outfile << "=== ОТЧЁТ СЕМЬИ ===" << endl;
        outfile << "Общий бюджет: " << family.family_budget << " руб." << endl;
        outfile << "Кредиты: " << family.family_credit << " руб." << endl;
        outfile << "Денис: " << (family.husband.is_alive ? "Жив" : "Мёртв") << endl;
        outfile << "Алиса: " << (family.wife.is_alive ? "Жив" : "Мёртв") << endl;
        outfile << "Ангелина: " << (family.daughter.is_alive ? "Жива" : "Мертва") << endl;
        outfile << "Статус: " << family.daughter_edu.status << endl;
        outfile << "Образование: " << family.daughter_edu.institution << endl;
        outfile << "Экзамены: " << family.daughter_edu.exam_score << "/100" << endl;
        outfile << "Период: " << total_months << " мес." << endl;
        outfile << "Всего заработано: " << total_income << " руб." << endl;
        outfile << "Всего потрачено: " << total_expenses << " руб." << endl;
        outfile << "Поведение дочери: " << family.daughter_good_behavior_points << " очков" << endl;
        outfile << "Джина: " << (family.dog.is_alive ? "Жива" : "Мертва") << endl;
        if (family.cat.is_alive) {
            outfile << "Сэм (кот): Жив" << (family.cat.is_stray ? " (подобран)" : "") << endl;
        }
        if (family.made_major_purchase) {
            outfile << "Крупная покупка: " << family.major_purchase_name << endl;
        }
        outfile << endl << "=== ЖУРНАЛ СОБЫТИЙ ===" << endl;
        for (int i = 0; i < event_count; i++) {
            const char* type_str = "";
            switch (event_log[i].type) {
            case 0: type_str = "[СИСТЕМА]"; break;
            case 1: type_str = "[ХОРОШО]"; break;
            case 2: type_str = "[ТРАТА]"; break;
            case 3: type_str = "[КАРЬЕРА]"; break;
            case 4: type_str = "[ПРОБЛЕМА]"; break;
            case 5: type_str = "[ТРАГЕДИЯ]"; break;
            }
            outfile << i + 1 << ". " << type_str << " Мес." << event_log[i].month
                << ": " << event_log[i].description << endl;
        }
        outfile.close();
    }
}

void process_month() {
    current_stats.month = total_months + 1;
    current_stats.year = config.start_year + (config.start_month + total_months) / 12;

    printf("\n--- Месяц %d (Осталось: %d) ---\n", current_stats.month,
        (config.end_year - config.start_year) * 12 + (config.end_month - config.start_month) - total_months);

    char month_event[200];
    sprintf(month_event, "Начало месяца %d", current_stats.month);
    add_event(month_event, 0);

    process_month_actions();

    total_months++;
    total_income += current_stats.income;
    total_expenses += current_stats.expenses;

    print_month_summary();
}

void process_action_month() {
    current_stats.month = total_months + 1;
    current_stats.year = config.start_year + (config.start_month + total_months) / 12;

    printf("\n--- Месяц %d (Осталось: %d) ---\n", current_stats.month,
        (config.end_year - config.start_year) * 12 + (config.end_month - config.start_month) - total_months);

    char month_event[200];
    sprintf(month_event, "Начало месяца %d", current_stats.month);
    add_event(month_event, 0);

    process_month_actions();

    total_months++;
    total_income += current_stats.income;
    total_expenses += current_stats.expenses;

    print_month_summary();
}

void save_game() {
    ofstream savefile;
    savefile.open("savegame.dat", ios::binary);

    if (savefile.is_open()) {
        savefile.write((char*)&family, sizeof(struct Family));
        savefile.write((char*)&config, sizeof(struct SimulationConfig));
        savefile.write((char*)&total_months, sizeof(int));
        savefile.write((char*)&total_income, sizeof(RUB));
        savefile.write((char*)&total_expenses, sizeof(RUB));
        savefile.write((char*)&bankruptcy_months, sizeof(int));
        savefile.write((char*)&daughter_in_orphanage, sizeof(bool));
        savefile.write((char*)&event_log, sizeof(struct EventLog) * event_count);
        savefile.write((char*)&event_count, sizeof(int));
        savefile.write((char*)&market, sizeof(struct InvestmentMarket));
        savefile.write((char*)&deaths_count, sizeof(int));

        savefile.close();
        printf("[СИСТЕМА] Игра сохранена успешно!\n");
        add_event("Игра сохранена", 0);
        game_saved = true;
    }
    else {
        printf("[ОШИБКА] Не удалось сохранить игру!\n");
    }
}

void load_game() {
    ifstream loadfile;
    loadfile.open("savegame.dat", ios::binary);

    if (loadfile.is_open()) {
        loadfile.read((char*)&family, sizeof(struct Family));
        loadfile.read((char*)&config, sizeof(struct SimulationConfig));
        loadfile.read((char*)&total_months, sizeof(int));
        loadfile.read((char*)&total_income, sizeof(RUB));
        loadfile.read((char*)&total_expenses, sizeof(RUB));
        loadfile.read((char*)&bankruptcy_months, sizeof(int));
        loadfile.read((char*)&daughter_in_orphanage, sizeof(bool));
        loadfile.read((char*)&event_log, sizeof(struct EventLog) * MAX_EVENTS);
        loadfile.read((char*)&event_count, sizeof(int));
        loadfile.read((char*)&market, sizeof(struct InvestmentMarket));
        loadfile.read((char*)&deaths_count, sizeof(int));

        loadfile.close();
        printf("[СИСТЕМА] Игра загружена успешно!\n");
        add_event("Игра загружена", 0);
        game_saved = true;
    }
    else {
        printf("[ОШИБКА] Файл сохранения не найден!\n");
    }
}

void simulation() {
    int menu_choice;

    printf("\n=== НАЧАЛО СИМУЛЯЦИИ ===\n");
    printf("Период: %d.%d - %d.%d\n\n", config.start_month, config.start_year, config.end_month, config.end_year);
    add_event("Симуляция началась", 0);

    while (!simulation_ended) {

        init_stats();

        show_menu();
        if (scanf("%d", &menu_choice) != 1) {
            printf("\n[ОШИБКА] Введите число!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (menu_choice) {
        case 1:
            process_month();

            if (total_months >= (config.end_year - config.start_year) * 12 + (config.end_month - config.start_month)) {
                printf("\n[КОНЕЦ] Достигнут конец симуляции.\n");
                add_event("Симуляция завершена (дата)", 0);
                simulation_ended = true;
            }

            if (!family.husband.is_alive && !family.wife.is_alive && !family.daughter.is_alive) {
                printf("\n[КОНЕЦ] Вся семья погибла. Симуляция завершена.\n");
                add_event("Симуляция завершена (смерть)", 5);
                simulation_ended = true;
            }
            break;

        case 2:
            print_family_status();
            break;

        case 3: {
            int inv_menu = 1;
            while (inv_menu) {
                update_market();
                investment_menu();
                int inv_choice;
                if (scanf("%d", &inv_choice) != 1) {
                    printf("\n[ОШИБКА] Введите число!\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (inv_choice >= 1 && inv_choice <= 4) {
                    printf("Количество штук (мин. 1): ");
                    int qty;
                    if (scanf("%d", &qty) != 1 || qty < 1) {
                        printf("[ОШИБКА] Неверное количество!\n");
                        continue;
                    }
                    RUB price = 0;
                    const char* type = "";
                    if (inv_choice == 1) { price = market.stocks_price; type = "Акции"; }
                    else if (inv_choice == 2) { price = market.bonds_price; type = "Облигации"; }
                    else if (inv_choice == 3) { price = market.crypto_price; type = "Криптовалюта"; }
                    else if (inv_choice == 4) { price = market.realty_price; type = "Недвижимость"; }

                    RUB amount = price * qty;
                    if (amount < 5000) {
                        printf("[ОШИБКА] Минимальная сумма инвестиции 5000 руб.!\n");
                        continue;
                    }
                    buy_investment(&family.husband, type, amount, price, qty);
                }
                else if (inv_choice == 5) {
                    inv_menu = 0;
                }
                else {
                    printf("\nНеверный выбор!\n");
                }
            }
            break;
        }

        case 4:
            printf("\n[ОБУЧЕНИЕ] Проводится обучение...\n");
            career_skill_up(&family.husband);
            career_skill_up(&family.wife);
            process_action_month();
            break;

        case 5:
            vacation_trip();
            process_action_month();
            break;

        case 6:
            sanatorium_trip();
            process_action_month();
            break;

        case 7:
            save_game();
            break;

        case 8:
            load_game();
            break;

        case 9:
            printf("\nВыход из игры...\n");
            add_event("Игрок вышел из игры", 0);
            simulation_ended = true;
            break;

        default:
            printf("\nНеверный выбор! Попробуйте снова.\n");
        }
    }

    printf("\n=== СИМУЛЯЦИЯ ЗАВЕРШЕНА ===\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    printf("========================================\n");
    printf("   СИМУЛЯТОР СЕМЕЙНЫХ ФИНАНСОВ v6.12  \n");
    printf("========================================\n\n");

    init_config();
    init_market();
    init_family();
    srand((unsigned int)time(NULL));

    simulation();
    print_family_status();
    print_results();
    save_to_file();

    printf("\nНажмите Enter для выхода...");
    while (getchar() != '\n');
    (void)getchar();

    return 0;
}