
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// ============================================================================
// SECTION 1: GLOBAL CONSTANTS & CONFIGURATION
// ============================================================================

const float BANK_RATE            = 15.5f;
const float INFLATION            = 7.5f;
const float INFLATION_INCREASE   = 1.0f;
const float CAR_DEPRECIATION     = 0.15f;
const float USD_GROWTH           = 0.05f;
const float INCOME_TAX           = 0.13f;
const float BUSINESS_TAX         = 0.06f;
const float BUSINESS_TAX_PROFIT  = 0.15f;
const float PROPERTY_TAX_RATE   = 0.002f;
const float TRANSPORT_TAX_BASE   = 50.0f;
const float TECH_DEPRECIATION    = 0.25f;
const float PC_UPGRADE_COST      = 0.3f;

// ============================================================================
// SECTION 2: TYPE ALIASES & ENUMERATIONS
// ============================================================================

using RUB     = long long int;
using USD     = long long int;
using Percent = float;

enum Profession {
    PROFESSION_JUNIOR       = 0,
    PROFESSION_SPECIALIST   = 1,
    PROFESSION_SENIOR       = 2,
    PROFESSION_TEAM_LEAD    = 3,
    PROFESSION_MANAGER      = 4,
    PROFESSION_DIRECTOR     = 5,
    PROFESSION_ENTREPRENEUR = 6
};

enum BusinessType {
    BUSINESS_ONLINE        = 0,
    BUSINESS_RETAIL        = 1,
    BUSINESS_MANUFACTURING = 2,
    BUSINESS_CONSULTING    = 3,
    BUSINESS_FREELANCE     = 4,
    BUSINESS_IT            = 5
};

enum InsuranceType {
    INSURANCE_NONE     = 0,
    INSURANCE_BASIC    = 1,
    INSURANCE_EXTENDED = 2,
    INSURANCE_PREMIUM  = 3
};

// ============================================================================
// SECTION 3: DATA STRUCTURES
// ============================================================================

struct Computer {
    bool   is_personal;
    RUB    purchase_price;
    RUB    current_value;
    int    purchase_year;
    int    age;
    float  performance;
    bool   needs_upgrade;
    bool   is_working;
    RUB    upgrade_cost;
    int    cpu_power;
    int    ram;
    int    storage;
    bool   has_gpu;
    int    quantity;
    RUB    total_value;
};

struct Skills {
    float      technical;
    float      managerial;
    float      financial;
    float      communication;
    float      experience;
    Profession current_profession;
    RUB        education_cost;
    int        certifications;
};

struct InsurancePolicy {
    InsuranceType type;
    RUB           annual_premium;
    RUB           deductible;
    RUB           coverage_limit;
    float         accident_coverage;
    float         health_coverage;
    float         property_coverage;
    float         business_coverage;
    float         tech_coverage;
    bool          is_active;
    int           years_active;
};

struct Business {
    bool          is_active;
    BusinessType  type;
    RUB           initial_investment;
    RUB           current_value;
    RUB           monthly_revenue;
    RUB           monthly_expenses;
    RUB           monthly_profit;
    RUB           account;
    RUB           credit;
    RUB           tax_debt;
    RUB           tax_paid;
    float         success_probability;
    float         risk_factor;
    int           years_active;
    int           employees_count;
    RUB           payroll;
    bool          has_office;
    RUB           office_rent;
    Computer      office_computers[50];
    int           computer_count;
    RUB           monthly_internet;
    RUB           monthly_software;
    RUB           monthly_cloud;
    InsurancePolicy business_insurance;
};

struct Bank {
    RUB     account;
    RUB     deposit;
    RUB     credit;
    RUB     credit_limit;
    Percent interest;
    Percent credit_rate;
    USD     usd_account;
    float   usd_rate;
    RUB     tax_debt;
    RUB     tax_paid;
    RUB     stocks;
    RUB     bonds;
    RUB     crypto;
};

struct Car {
    RUB             monthly_fuel;
    RUB             price;
    RUB             maintenance;
    RUB             insurance;
    RUB             parking;
    RUB             emergency_repair;
    int             age;
    bool            is_working;
    int             engine_power;
    RUB             tax_rate;
    InsurancePolicy casco;
};

struct Health {
    RUB             monthly_sport;
    RUB             annual_checkup;
    RUB             emergency;
    RUB             dental;
    RUB             medicines;
    bool            chronic_disease;
    InsurancePolicy health_insurance;
};

struct Home {
    RUB             price;
    RUB             monthly_utilities;
    RUB             annual_insurance;
    RUB             renovation;
    RUB             emergency_repair;
    RUB             appliances;
    RUB             cadastral_value;
    InsurancePolicy property_insurance;
};

struct Female {
    Bank     tbank;
    Car      matiz;
    RUB      salary;
    RUB      net_salary;
    RUB      monthly_food;
    RUB      monthly_clothing;
    RUB      monthly_entertainment;
    RUB      monthly_health;
    RUB      monthly_transport;
    RUB      monthly_communications;
    RUB      monthly_misc;
    RUB      monthly_beauty;
    RUB      monthly_gifts;
    Home     flat;
    Health   health;
    RUB      emergency_fund;
    Computer personal_pc;
    Computer laptop;
    Computer work_pc;
    Skills   skills;
    Business business;
    InsurancePolicy life_insurance;
    RUB      annual_income;
    Profession career_path[20];
    int      career_stage;
    RUB      total_education_cost;
    RUB      total_tech_cost;
};

struct Male {
    Bank     sber;
    Car      volga;
    RUB      salary;
    RUB      net_salary;
    RUB      monthly_food;
    RUB      monthly_education;
    RUB      monthly_clothing;
    RUB      monthly_entertainment;
    RUB      monthly_health;
    RUB      monthly_sport;
    RUB      monthly_communications;
    RUB      monthly_gadgets;
    RUB      monthly_hobbies;
    Home     house;
    Health   health;
    RUB      dream_stash;
    RUB      dream_car_price;
    RUB      emergency_fund;
    Computer gaming_pc;
    Computer work_laptop;
    Computer home_server;
    Skills   skills;
    Business business;
    InsurancePolicy life_insurance;
    RUB      annual_income;
    Profession career_path[20];
    int      career_stage;
    RUB      total_education_cost;
    RUB      total_tech_cost;
};

// ============================================================================
// SECTION 4: GLOBAL INSTANCES
// ============================================================================

Female Kate;
Male   Henry;

// ============================================================================
// SECTION 5: LOW-LEVEL UTILITIES
// ============================================================================

bool random_event(float probability) {
    return (rand() / (float)RAND_MAX) < probability;
}

RUB calculate_insurance_premium(InsuranceType type, RUB insured_value,
                                int age, bool has_history)
{
    float base_rate = 0.0f;
    switch (type) {
        case INSURANCE_BASIC:    base_rate = 0.02f; break;
        case INSURANCE_EXTENDED: base_rate = 0.05f; break;
        case INSURANCE_PREMIUM:  base_rate = 0.08f; break;
        default: return 0;
    }

    float age_factor     = 1.0f + (age / 100.0f);
    float history_factor = has_history ? 0.9f : 1.2f;

    return (RUB)(insured_value * base_rate * age_factor * history_factor);
}

void take_credit_if_needed(Bank& bank, RUB needed_amount) {
    if (needed_amount <= 0) return;

    if (bank.account >= needed_amount) {
        bank.account -= needed_amount;
    } else {
        RUB credit_needed = needed_amount - bank.account;
        if (credit_needed <= bank.credit_limit - bank.credit) {
            bank.credit  += credit_needed;
            bank.account  = 0;
            printf("  Credit issued: %lld RUB at %.1f%%\n",
                   credit_needed, bank.credit_rate);
        } else {
            printf("  ERROR: credit limit exceeded!\n");
        }
    }
}

RUB process_insurance_claim(InsurancePolicy& policy, RUB damage,
                            const char* event_type)
{
    if (!policy.is_active) return 0;

    RUB coverage = 0;

    if      (strcmp(event_type, "accident") == 0 && policy.accident_coverage > 0)
        coverage = (RUB)(damage * policy.accident_coverage);
    else if (strcmp(event_type, "health")   == 0 && policy.health_coverage   > 0)
        coverage = (RUB)(damage * policy.health_coverage);
    else if (strcmp(event_type, "property") == 0 && policy.property_coverage > 0)
        coverage = (RUB)(damage * policy.property_coverage);
    else if (strcmp(event_type, "business") == 0 && policy.business_coverage > 0)
        coverage = (RUB)(damage * policy.business_coverage);
    else if (strcmp(event_type, "tech")     == 0 && policy.tech_coverage     > 0)
        coverage = (RUB)(damage * policy.tech_coverage);

    if (coverage > policy.deductible)
        coverage -= policy.deductible;
    else
        coverage = 0;

    if (coverage > policy.coverage_limit)
        coverage = policy.coverage_limit;

    if (coverage > 0) {
        printf("  Insurance payout: %lld RUB\n", coverage);
        policy.years_active++;
    }

    return coverage;
}

// ============================================================================
// SECTION 6: ASSET MANAGEMENT
// ============================================================================

// --- Computer Logic ---

void update_computer_state(Computer& pc, const char* owner, const char* device_name) {
    if (pc.purchase_price == 0) return;

    pc.age++;

    // Performance degradation
    float performance_loss = 5.0f + (rand() % 10);
    pc.performance *= (1.0f - performance_loss / 100.0f);
    if (pc.performance < 10.0f) pc.performance = 10.0f;

    // Value depreciation
    pc.current_value = (RUB)(pc.current_value * (1.0f - TECH_DEPRECIATION));
    if (pc.current_value < pc.purchase_price * 0.1f)
        pc.current_value = (RUB)(pc.purchase_price * 0.1f);

    // Check if upgrade is needed
    if (pc.age > 3 && pc.performance < 50.0f && !pc.needs_upgrade) {
        pc.needs_upgrade  = true;
        pc.upgrade_cost   = (RUB)(pc.purchase_price * PC_UPGRADE_COST);
        printf("  %s: %s needs upgrade (age %d yr, performance %.0f%%). Cost: %lld RUB\n",
               owner, device_name, pc.age, pc.performance, pc.upgrade_cost);
    }

    // Random breakdown
    if (random_event(0.05f + pc.age * 0.02f)) {
        pc.is_working      = false;
        RUB repair_cost    = (RUB)(pc.purchase_price * (0.1f + (rand() % 30) / 100.0f));
        printf("  %s: %s broke down! Repair cost: %lld RUB\n",
               owner, device_name, repair_cost);
    }
}

void handle_computer_repair(Female& person, Computer& pc, const char* device_name) {
    if (!pc.is_working && pc.purchase_price > 0) {
        RUB repair_cost        = (RUB)(pc.purchase_price * 0.2f);
        RUB insurance_coverage = process_insurance_claim(person.life_insurance, repair_cost, "tech");
        RUB remaining          = repair_cost - insurance_coverage;

        printf("  Kate: repairing %s — %lld RUB\n", device_name, repair_cost);

        if (person.emergency_fund >= remaining) {
            person.emergency_fund -= remaining;
            pc.is_working = true;
        } else if (person.tbank.account >= remaining) {
            person.tbank.account -= remaining;
            pc.is_working = true;
        } else {
            printf("  Kate: not enough funds — %s remains broken\n", device_name);
        }
    }
}

void handle_computer_repair(Male& person, Computer& pc, const char* device_name) {
    if (!pc.is_working && pc.purchase_price > 0) {
        RUB repair_cost        = (RUB)(pc.purchase_price * 0.25f);
        RUB insurance_coverage = process_insurance_claim(person.life_insurance, repair_cost, "tech");
        RUB remaining          = repair_cost - insurance_coverage;

        printf("  Henry: repairing %s — %lld RUB\n", device_name, repair_cost);

        if (person.emergency_fund >= remaining) {
            person.emergency_fund -= remaining;
            pc.is_working = true;
        } else if (person.sber.account >= remaining) {
            person.sber.account -= remaining;
            pc.is_working = true;
        } else {
            printf("  Henry: not enough funds — %s remains broken\n", device_name);
        }
    }
}

void buy_computer(Female& person, const char* type, RUB /*budget*/) {
    RUB price = 0;

    if (strcmp(type, "work_pc") == 0) {
        Computer new_pc;
        new_pc.is_personal   = true;
        new_pc.purchase_year = (int)(2026 + person.skills.experience);
        new_pc.age           = 0;
        new_pc.is_working    = true;
        new_pc.needs_upgrade = false;
        new_pc.upgrade_cost  = 0;

        price                = 70000 + rand() % 50000;
        new_pc.purchase_price = price;
        new_pc.current_value  = price;
        new_pc.performance    = 70.0f + rand() % 20;
        new_pc.cpu_power      = 70;
        new_pc.ram            = 16;
        new_pc.storage        = 512;
        new_pc.has_gpu        = false;
        person.work_pc        = new_pc;

        printf("  Kate: new work PC — %lld RUB\n", price);
    }
    else if (strcmp(type, "upgrade_personal") == 0) {
        price = person.personal_pc.upgrade_cost;
        if (price > 0) {
            person.personal_pc.performance  += 30.0f;
            if (person.personal_pc.performance > 100.0f)
                person.personal_pc.performance = 100.0f;

            person.personal_pc.current_value += (RUB)(price * 0.8f);
            person.personal_pc.needs_upgrade  = false;
            person.personal_pc.upgrade_cost   = 0;
            person.personal_pc.age            = 0;

            printf("  Kate: personal PC upgrade — %lld RUB\n", price);
        }
    }

    if (price > 0) {
        if (person.emergency_fund >= price)
            person.emergency_fund -= price;
        else
            person.tbank.account -= price;

        person.total_tech_cost += price;
    }
}

void buy_computer(Male& person, const char* type, RUB /*budget*/) {
    RUB price = 0;

    if (strcmp(type, "new_gaming") == 0) {
        Computer new_pc;
        new_pc.is_personal    = true;
        new_pc.purchase_year  = (int)(2026 + person.skills.experience);
        new_pc.age            = 0;
        new_pc.needs_upgrade  = false;
        new_pc.is_working     = true;
        new_pc.upgrade_cost   = 0;

        price                 = 150000 + rand() % 150000;
        new_pc.purchase_price = price;
        new_pc.current_value  = price;
        new_pc.performance    = 90.0f + rand() % 10;
        new_pc.cpu_power      = 95;
        new_pc.ram            = 32;
        new_pc.storage        = 2000;
        new_pc.has_gpu        = true;
        person.gaming_pc      = new_pc;

        printf("  Henry: new gaming PC — %lld RUB\n", price);
    }
    else if (strcmp(type, "upgrade_server") == 0) {
        price = 20000 + rand() % 40000;
        person.home_server.performance   += 20.0f;
        person.home_server.current_value += (RUB)(price * 0.7f);
        person.home_server.storage       += 2000;

        printf("  Henry: home server upgrade — %lld RUB\n", price);
    }

    if (price > 0) {
        if (person.emergency_fund >= price)
            person.emergency_fund -= price;
        else
            person.sber.account -= price;

        person.total_tech_cost += price;
    }
}

// --- Car & Home Logic ---

void process_car_events(Car& car, Bank& bank, RUB& emergency_fund,
                        const char* owner, InsurancePolicy& life_insurance)
{
    car.age++;

    // Random breakdown
    float breakdown_prob = 0.01f + (car.age * 0.02f);
    if (breakdown_prob > 0.3f) breakdown_prob = 0.3f;

    if (random_event(breakdown_prob)) {
        RUB repair_cost = (RUB)((5000 + (rand() % 50000)) * (1 + car.age / 5));
        printf("  %s: car broke down, repair cost: %lld RUB\n", owner, repair_cost);

        if (emergency_fund >= repair_cost) {
            emergency_fund -= repair_cost;
        } else {
            take_credit_if_needed(bank, repair_cost - emergency_fund);
            emergency_fund = 0;
        }

        if (random_event(0.3f)) {
            car.is_working = false;
            printf("  %s: car is under repair\n", owner);
        }
    }

    // Random accident
    if (random_event(0.005f)) {
        RUB accident_cost      = 20000 + rand() % 100000;
        RUB insurance_coverage = process_insurance_claim(car.casco, accident_cost, "accident");

        printf("  %s: accident, cost: %lld RUB\n", owner, accident_cost);

        if (random_event(0.3f)) {
            // Accident with health damage
            RUB health_damage   = 10000 + rand() % 50000;
            RUB health_coverage = process_insurance_claim(life_insurance, health_damage, "health");
            RUB total_coverage  = insurance_coverage + health_coverage;
            RUB remaining       = accident_cost + health_damage - total_coverage;

            printf("  %s: health damage in accident: %lld RUB\n", owner, health_damage);

            if (remaining > 0) {
                if (emergency_fund >= remaining) {
                    emergency_fund -= remaining;
                } else {
                    take_credit_if_needed(bank, remaining - emergency_fund);
                    emergency_fund = 0;
                }
            }
        } else {
            RUB remaining = accident_cost - insurance_coverage;
            if (remaining > 0) {
                if (emergency_fund >= remaining) {
                    emergency_fund -= remaining;
                } else {
                    take_credit_if_needed(bank, remaining - emergency_fund);
                    emergency_fund = 0;
                }
            }
        }
    }
}

void process_home_events(Home& home, Bank& bank, RUB& emergency_fund,
                         const char* owner)
{
    // Random emergency repair
    if (random_event(0.005f)) {
        RUB repair_cost        = 15000 + rand() % 100000;
        RUB insurance_coverage = process_insurance_claim(home.property_insurance, repair_cost, "property");
        RUB remaining          = repair_cost - insurance_coverage;

        printf("  %s: home emergency repair, cost: %lld RUB\n", owner, repair_cost);

        if (remaining > 0) {
            if (emergency_fund >= remaining) {
                emergency_fund -= remaining;
            } else {
                take_credit_if_needed(bank, remaining - emergency_fund);
                emergency_fund = 0;
            }
        }
    }

    // Random theft
    if (random_event(0.002f)) {
        RUB theft_cost         = 30000 + rand() % 200000;
        RUB insurance_coverage = process_insurance_claim(home.property_insurance, theft_cost, "property");
        RUB remaining          = theft_cost - insurance_coverage;

        printf("  %s: home theft, loss: %lld RUB\n", owner, theft_cost);

        if (remaining > 0) {
            if (emergency_fund >= remaining)
                emergency_fund -= remaining;
            else
                bank.account -= remaining;
        }
    }

    // Random appliance replacement
    if (random_event(0.03f)) {
        RUB appliance_cost = (RUB)(home.appliances * (0.5f + (rand() % 100) / 100.0f));
        printf("  %s: appliance replacement/maintenance: %lld RUB\n", owner, appliance_cost);

        if (emergency_fund >= appliance_cost)
            emergency_fund -= appliance_cost;
        else
            bank.account -= appliance_cost;
    }
}

// ============================================================================
// SECTION 7: FINANCE & CAREER
// ============================================================================

void process_health_events(Female& person, int month, int /*year*/) {
    // Seasonal illness
    float sick_probability = (month >= 10 || month <= 3) ? 0.12f : 0.05f;
    if (random_event(sick_probability)) {
        RUB sickness_cost      = 5000 + rand() % 20000;
        RUB insurance_coverage = process_insurance_claim(person.health.health_insurance, sickness_cost, "health");
        RUB remaining          = sickness_cost - insurance_coverage;

        printf("  Kate: sick, medical cost: %lld RUB\n", sickness_cost);

        if (remaining > 0) {
            if (person.emergency_fund >= remaining) {
                person.emergency_fund -= remaining;
            } else {
                take_credit_if_needed(person.tbank, remaining - person.emergency_fund);
                person.emergency_fund = 0;
            }
        }
    }

    // Sports injury
    if (person.health.monthly_sport > 0 && random_event(0.02f)) {
        RUB injury_cost        = 10000 + rand() % 30000;
        RUB insurance_coverage = process_insurance_claim(person.health.health_insurance, injury_cost, "health");
        RUB remaining          = injury_cost - insurance_coverage;

        printf("  Kate: sports injury, cost: %lld RUB\n", injury_cost);

        if (remaining > 0) {
            if (person.emergency_fund >= remaining) {
                person.emergency_fund -= remaining;
            } else {
                take_credit_if_needed(person.tbank, remaining - person.emergency_fund);
                person.emergency_fund = 0;
            }
        }
    }

    // Dentist visit
    if (random_event(0.08f)) {
        RUB dental_cost = (RUB)(person.health.dental * (0.5f + (rand() % 100) / 100.0f));
        printf("  Kate: dentist visit: %lld RUB\n", dental_cost);

        if (person.emergency_fund >= dental_cost)
            person.emergency_fund -= dental_cost;
        else
            person.tbank.account -= dental_cost;
    }

    // Annual medical checkup (May)
    if (month == 5 && random_event(0.7f)) {
        printf("  Kate: annual medical checkup: %lld RUB\n", person.health.annual_checkup);

        if (person.emergency_fund >= person.health.annual_checkup)
            person.emergency_fund -= person.health.annual_checkup;
        else
            person.tbank.account -= person.health.annual_checkup;
    }
}

void process_health_events(Male& person, int month, int /*year*/) {
    // Seasonal illness
    float sick_probability = (month >= 10 || month <= 3) ? 0.1f : 0.04f;
    if (random_event(sick_probability)) {
        RUB sickness_cost      = 3000 + rand() % 25000;
        RUB insurance_coverage = process_insurance_claim(person.health.health_insurance, sickness_cost, "health");
        RUB remaining          = sickness_cost - insurance_coverage;

        printf("  Henry: sick, medical cost: %lld RUB\n", sickness_cost);

        if (remaining > 0) {
            if (person.emergency_fund >= remaining) {
                person.emergency_fund -= remaining;
            } else {
                take_credit_if_needed(person.sber, remaining - person.emergency_fund);
                person.emergency_fund = 0;
            }
        }
    }

    // Sports injury
    if (person.monthly_sport > 0 && random_event(0.03f)) {
        RUB injury_cost        = 10000 + rand() % 40000;
        RUB insurance_coverage = process_insurance_claim(person.health.health_insurance, injury_cost, "health");
        RUB remaining          = injury_cost - insurance_coverage;

        printf("  Henry: sports injury, cost: %lld RUB\n", injury_cost);

        if (remaining > 0) {
            if (person.emergency_fund >= remaining)
                person.emergency_fund -= remaining;
            else
                person.sber.account -= remaining;
        }
    }
}

void process_force_majeure(Female& person, int /*month*/, int /*year*/) {
    // Impulse purchase
    if (random_event(0.1f)) {
        RUB impulse_buy = 3000 + rand() % 30000;
        printf("  Kate: impulse purchase — %lld RUB\n", impulse_buy);
        person.tbank.account -= impulse_buy;
    }

    // Financial help to someone
    if (random_event(0.02f)) {
        RUB help_amount = 10000 + rand() % 50000;
        printf("  Kate: financial help — %lld RUB\n", help_amount);

        if (person.emergency_fund >= help_amount)
            person.emergency_fund -= help_amount;
        else
            person.tbank.account -= help_amount;
    }

    // Theft
    if (random_event(0.005f)) {
        RUB loss_cost = 5000 + rand() % 40000;
        printf("  Kate: theft, loss: %lld RUB\n", loss_cost);

        if (person.emergency_fund >= loss_cost)
            person.emergency_fund -= loss_cost;
        else
            person.tbank.account -= loss_cost;
    }

    // Fine
    if (random_event(0.03f)) {
        RUB fine = 500 + rand() % 5000;
        printf("  Kate: fine — %lld RUB\n", fine);
        person.tbank.account -= fine;
    }
}

void process_force_majeure(Male& person, int /*month*/, int /*year*/) {
    // Impulse purchase
    if (random_event(0.12f)) {
        RUB impulse_buy = 5000 + rand() % 50000;
        printf("  Henry: impulse purchase — %lld RUB\n", impulse_buy);
        person.sber.account -= impulse_buy;
    }

    // Financial help to someone
    if (random_event(0.015f)) {
        RUB help_amount = 15000 + rand() % 100000;
        printf("  Henry: financial help — %lld RUB\n", help_amount);

        if (person.emergency_fund >= help_amount)
            person.emergency_fund -= help_amount;
        else
            person.sber.account -= help_amount;
    }

    // Theft
    if (random_event(0.007f)) {
        RUB loss_cost = 10000 + rand() % 100000;
        printf("  Henry: theft, loss: %lld RUB\n", loss_cost);

        if (person.emergency_fund >= loss_cost)
            person.emergency_fund -= loss_cost;
        else
            person.sber.account -= loss_cost;
    }

    // Fine
    if (random_event(0.04f)) {
        RUB fine = 1000 + rand() % 15000;
        printf("  Henry: fine — %lld RUB\n", fine);
        person.sber.account -= fine;
    }
}

void process_monthly_expenses(Female& person, int /*month*/, int /*year*/) {
    // Fixed living expenses
    person.tbank.account -= person.monthly_food;
    person.tbank.account -= person.monthly_clothing;
    person.tbank.account -= person.monthly_entertainment;
    person.tbank.account -= person.monthly_health;
    person.tbank.account -= person.monthly_transport;
    person.tbank.account -= person.monthly_communications;
    person.tbank.account -= person.monthly_misc;
    person.tbank.account -= person.monthly_beauty;
    person.tbank.account -= person.monthly_gifts;

    // Car expenses (if car is working)
    if (person.matiz.is_working) {
        person.tbank.account -= person.matiz.monthly_fuel;
        person.tbank.account -= person.matiz.parking;
    }

    // Utilities and health
    person.tbank.account -= person.flat.monthly_utilities;
    if (person.health.chronic_disease)
        person.tbank.account -= person.health.medicines;
    person.tbank.account -= person.health.monthly_sport;
}

void process_monthly_expenses(Male& person, int /*month*/, int /*year*/) {
    // Fixed living expenses
    person.sber.account -= person.monthly_food;
    person.sber.account -= person.monthly_clothing;
    person.sber.account -= person.monthly_entertainment;
    person.sber.account -= person.monthly_health;
    person.sber.account -= person.monthly_communications;
    person.sber.account -= person.monthly_gadgets;
    person.sber.account -= person.monthly_hobbies;

    // Car expenses (if car is working)
    if (person.volga.is_working) {
        person.sber.account -= person.volga.monthly_fuel;
        person.sber.account -= person.volga.parking;
    }

    // Utilities and health
    person.sber.account -= person.house.monthly_utilities;
    if (person.health.chronic_disease)
        person.sber.account -= person.health.medicines;
    person.sber.account -= person.monthly_sport;
}

void process_salary(Female& person, int month, int /*year*/) {
    RUB gross_salary = person.salary;
    if (month == 12) gross_salary += person.salary;              // Year-end bonus
    gross_salary += person.skills.certifications * 5000;         // Certification bonus

    RUB tax        = (RUB)(gross_salary * INCOME_TAX);
    RUB net_salary = gross_salary - tax;

    person.tbank.account  += net_salary;
    person.annual_income  += gross_salary;
    person.tbank.tax_paid += tax;
    person.net_salary      = net_salary;
}

void process_salary(Male& person, int month, int /*year*/) {
    RUB gross_salary = person.salary;
    if (month == 12) gross_salary += person.salary;              // Year-end bonus
    gross_salary += person.skills.certifications * 8000;         // Certification bonus
    gross_salary += (RUB)(person.skills.managerial * 500);       // Management bonus

    RUB tax        = (RUB)(gross_salary * INCOME_TAX);
    RUB net_salary = gross_salary - tax;

    person.sber.account  += net_salary;
    person.annual_income += gross_salary;
    person.sber.tax_paid += tax;
    person.net_salary     = net_salary;
}

void process_deposits(Female& person, int month, int /*year*/) {
    // Monthly deposit interest
    person.tbank.deposit += (RUB)(person.tbank.deposit * (person.tbank.interest / 12.0f / 100.0f));

    // Transfer 80% of account to deposit
    RUB transfer = (RUB)(person.tbank.account * 0.8f);
    person.tbank.deposit  += transfer;
    person.tbank.account  -= transfer;

    // Rate adjustment at year end
    if (month == 12)
        person.tbank.interest = BANK_RATE - 1.0f;
}

void process_deposits(Male& person, int month, int /*year*/) {
    // Monthly deposit interest
    person.sber.deposit += (RUB)(person.sber.deposit * (person.sber.interest / 12.0f / 100.0f));

    // Transfer 85% of account to deposit
    RUB transfer = (RUB)(person.sber.account * 0.85f);
    person.sber.deposit  += transfer;
    person.sber.account  -= transfer;

    // Rate adjustment at year end
    if (month == 12)
        person.sber.interest = BANK_RATE - 0.5f;
}

void process_career_growth(Female& person, int year) {
    // Periodic education
    if (year % 3 == 0 && random_event(0.6f)) {
        RUB education_cost = 50000 + rand() % 150000;
        printf("  Kate: education — %lld RUB\n", education_cost);

        if (person.emergency_fund >= education_cost)
            person.emergency_fund -= education_cost;
        else
            person.tbank.account -= education_cost;

        person.total_education_cost    += education_cost;
        person.skills.education_cost   += education_cost;
        person.skills.technical        += 5.0f + rand() % 10;
        person.skills.managerial       += 2.0f + rand() % 5;
        if (person.skills.technical  > 100.0f) person.skills.technical  = 100.0f;
        if (person.skills.managerial > 100.0f) person.skills.managerial = 100.0f;
        person.skills.certifications++;

        printf("  Skills updated — technical: %.1f, managerial: %.1f\n",
               person.skills.technical, person.skills.managerial);
    }

    // Random certification
    if (random_event(0.2f)) {
        RUB cert_cost = 20000 + rand() % 60000;
        printf("  Kate: new certification — %lld RUB\n", cert_cost);

        if (person.emergency_fund >= cert_cost)
            person.emergency_fund -= cert_cost;
        else
            person.tbank.account -= cert_cost;

        person.skills.certifications++;
        person.skills.technical += 3.0f;
    }
}

void process_career_growth(Male& person, int year) {
    // Periodic education
    if (year % 2 == 0 && random_event(0.7f)) {
        RUB education_cost = 70000 + rand() % 200000;
        printf("  Henry: education — %lld RUB\n", education_cost);

        if (person.emergency_fund >= education_cost)
            person.emergency_fund -= education_cost;
        else
            person.sber.account -= education_cost;

        person.total_education_cost    += education_cost;
        person.skills.education_cost   += education_cost;
        person.skills.managerial       += 8.0f + rand() % 12;
        person.skills.financial        += 5.0f + rand() % 8;
        person.skills.communication    += 3.0f + rand() % 5;
        if (person.skills.managerial    > 100.0f) person.skills.managerial    = 100.0f;
        if (person.skills.financial     > 100.0f) person.skills.financial     = 100.0f;
        if (person.skills.communication > 100.0f) person.skills.communication = 100.0f;
        person.skills.certifications++;

        printf("  Skills updated — managerial: %.1f, financial: %.1f\n",
               person.skills.managerial, person.skills.financial);
    }
}

void process_promotion(Female& person, int /*year*/) {
    float promotion_chance = (person.skills.technical  / 200.0f)
                           + (person.skills.managerial / 200.0f)
                           + (person.skills.certifications * 0.02f);

    if (random_event(promotion_chance / 10.0f)) {
        Profession old_prof = person.skills.current_profession;
        Profession new_prof = old_prof;

        switch (old_prof) {
            case PROFESSION_SPECIALIST:
                if (person.skills.technical  > 70.0f) new_prof = PROFESSION_SENIOR;
                break;
            case PROFESSION_SENIOR:
                if (person.skills.managerial > 50.0f) new_prof = PROFESSION_TEAM_LEAD;
                break;
            case PROFESSION_TEAM_LEAD:
                if (person.skills.managerial > 70.0f) new_prof = PROFESSION_MANAGER;
                break;
            case PROFESSION_MANAGER:
                if (person.skills.financial  > 60.0f) new_prof = PROFESSION_DIRECTOR;
                break;
            default: break;
        }

        if (new_prof != old_prof) {
            person.skills.current_profession      = new_prof;
            person.career_path[person.career_stage++] = new_prof;

            float salary_multiplier = 1.0f;
            switch (new_prof) {
                case PROFESSION_SENIOR:    salary_multiplier = 1.3f; break;
                case PROFESSION_TEAM_LEAD: salary_multiplier = 1.5f; break;
                case PROFESSION_MANAGER:   salary_multiplier = 1.8f; break;
                case PROFESSION_DIRECTOR:  salary_multiplier = 2.2f; break;
                default:                   salary_multiplier = 1.2f;
            }

            person.salary = (RUB)(person.salary * salary_multiplier);
            printf("  CONGRATS! Kate promoted to level %d, new salary: %lld RUB\n",
                   new_prof, person.salary);
        }
    }

    // Job offer
    if (random_event(0.15f)) {
        RUB new_salary = (RUB)(person.salary * (1.1f + (rand() % 30) / 100.0f));
        if (new_salary > (RUB)(person.salary * 1.2f)) {
            printf("  Kate: job offer with salary %lld RUB\n", new_salary);
            if (random_event(0.5f)) {
                person.salary = new_salary;
                printf("  Kate: accepted offer! New salary: %lld RUB\n", person.salary);
            }
        }
    }
}

void process_promotion(Male& person, int /*year*/) {
    float promotion_chance = (person.skills.managerial    / 150.0f)
                           + (person.skills.financial      / 200.0f)
                           + (person.skills.communication  / 150.0f)
                           + (person.skills.certifications * 0.03f);

    if (random_event(promotion_chance / 8.0f)) {
        Profession old_prof = person.skills.current_profession;
        Profession new_prof = old_prof;

        switch (old_prof) {
            case PROFESSION_SENIOR:
                if (person.skills.managerial > 60.0f) new_prof = PROFESSION_TEAM_LEAD;
                break;
            case PROFESSION_TEAM_LEAD:
                if (person.skills.managerial > 75.0f) new_prof = PROFESSION_MANAGER;
                break;
            case PROFESSION_MANAGER:
                if (person.skills.financial  > 70.0f) new_prof = PROFESSION_DIRECTOR;
                break;
            case PROFESSION_DIRECTOR:
                if (person.skills.financial  > 80.0f && person.emergency_fund > 1000000)
                    new_prof = PROFESSION_ENTREPRENEUR;
                break;
            default: break;
        }

        if (new_prof != old_prof) {
            person.skills.current_profession          = new_prof;
            person.career_path[person.career_stage++] = new_prof;

            float salary_multiplier = 1.0f;
            switch (new_prof) {
                case PROFESSION_TEAM_LEAD:    salary_multiplier = 1.4f; break;
                case PROFESSION_MANAGER:      salary_multiplier = 1.7f; break;
                case PROFESSION_DIRECTOR:     salary_multiplier = 2.0f; break;
                case PROFESSION_ENTREPRENEUR: salary_multiplier = 2.5f; break;
                default:                      salary_multiplier = 1.3f;
            }

            person.salary = (RUB)(person.salary * salary_multiplier);
            printf("  CONGRATS! Henry promoted to level %d, new salary: %lld RUB\n",
                   new_prof, person.salary);
        }
    }

    // Job offer
    if (random_event(0.2f)) {
        RUB new_salary = (RUB)(person.salary * (1.15f + (rand() % 40) / 100.0f));
        if (new_salary > (RUB)(person.salary * 1.25f)) {
            printf("  Henry: job offer with salary %lld RUB\n", new_salary);
            if (random_event(0.6f)) {
                person.salary = new_salary;
                printf("  Henry: accepted offer! New salary: %lld RUB\n", person.salary);
            }
        }
    }
}

// ============================================================================
// SECTION 8: BUSINESS LOGIC
// ============================================================================

void init_business_computers(Business& business, int count) {
    business.computer_count    = count;
    business.monthly_internet  = 5000;
    business.monthly_software  = 3000 * count;
    business.monthly_cloud     = 10000;

    for (int i = 0; i < count; i++) {
        business.office_computers[i] = {
            false,
            (RUB)(50000 + rand() % 30000),
            0,
            2026,
            0,
            (float)(70 + rand() % 20),
            false,
            true,
            0,
            60 + rand() % 30,
            8 + (rand() % 3) * 8,
            256 + (rand() % 3) * 256,
            (rand() % 100) < 20,
            1,
            0
        };
        business.office_computers[i].current_value = business.office_computers[i].purchase_price;
    }

    RUB total = 0;
    for (int i = 0; i < count; i++)
        total += business.office_computers[i].purchase_price;

    printf("  Purchased %d computers for office: %lld RUB\n", count, total);
}

void manage_business_computers(Business& business, int month, int /*year*/) {
    if (!business.is_active || business.computer_count == 0) return;

    // Monthly IT costs
    business.monthly_expenses += business.monthly_internet;
    business.monthly_expenses += business.monthly_software;
    business.monthly_expenses += business.monthly_cloud;

    // Annual software update (January)
    if (month == 1) {
        RUB software_update = (RUB)(business.monthly_software * 12 * 0.3f);
        business.account   -= software_update;
        printf("  Business: annual software update — %lld RUB\n", software_update);
    }

    // Annual hardware maintenance (December)
    if (month == 12) {
        RUB total_depreciation = 0;
        int need_replacement   = 0;

        for (int i = 0; i < business.computer_count; i++) {
            business.office_computers[i].age++;
            RUB old_value = business.office_computers[i].current_value;
            business.office_computers[i].current_value = (RUB)(
                business.office_computers[i].current_value * (1.0f - TECH_DEPRECIATION));
            total_depreciation += old_value - business.office_computers[i].current_value;

            if (business.office_computers[i].age > 3 &&
                business.office_computers[i].performance < 40.0f)
                need_replacement++;

            // Random breakdown
            if (random_event(0.1f) && business.office_computers[i].is_working) {
                business.office_computers[i].is_working = false;
                RUB repair = (RUB)(business.office_computers[i].purchase_price * 0.1f);
                business.account -= repair;
                printf("  Business: PC #%d repair — %lld RUB\n", i + 1, repair);
            }
        }

        printf("  Business: annual PC depreciation — %lld RUB\n", total_depreciation);

        // Replace outdated PCs if budget allows
        if (need_replacement > 0 && business.account > 500000) {
            RUB replacement_cost = (RUB)(need_replacement * 60000);
            printf("  Business: replacing %d outdated PC(s) — %lld RUB\n",
                   need_replacement, replacement_cost);

            if (business.account >= replacement_cost) {
                business.account -= replacement_cost;
                for (int i = 0; i < business.computer_count && need_replacement > 0; i++) {
                    if (business.office_computers[i].age > 3) {
                        business.office_computers[i].purchase_price = 60000;
                        business.office_computers[i].current_value  = 60000;
                        business.office_computers[i].age            = 0;
                        business.office_computers[i].performance    = 80.0f;
                        business.office_computers[i].is_working     = true;
                        need_replacement--;
                    }
                }
            }
        }
    }
}

void calculate_business_tax(Female& person) {
    RUB business_tax = (RUB)(person.business.monthly_profit * BUSINESS_TAX);
    if (business_tax < 0) business_tax = 0;

    person.business.tax_debt += business_tax;
    person.business.tax_paid += business_tax;
    person.business.account  -= business_tax;
}

void calculate_business_tax(Male& person) {
    RUB business_tax = (RUB)(
        (person.business.monthly_revenue - person.business.monthly_expenses) * BUSINESS_TAX_PROFIT);
    if (business_tax < 0) business_tax = 0;

    person.business.tax_debt += business_tax;
    person.business.tax_paid += business_tax;
    person.business.account  -= business_tax;
}

void handle_business_risks(Female& person) {
    // Server failure
    if (random_event(0.02f)) {
        RUB tech_loss          = (RUB)(person.business.current_value * 0.05f);
        RUB insurance_coverage = process_insurance_claim(person.business.business_insurance, tech_loss, "tech");
        tech_loss             -= insurance_coverage;

        printf("  Kate's business: server failure, loss: %lld RUB\n", tech_loss);
        person.business.account -= tech_loss;
    }

    // Random business risk
    if (random_event(person.business.risk_factor / 4.0f)) {
        int risk_type = rand() % 5;
        RUB loss      = 0;

        switch (risk_type) {
            case 0:
                loss = (RUB)(person.business.monthly_revenue * 0.3f);
                person.business.monthly_revenue = (RUB)(person.business.monthly_revenue * 0.9f);
                printf("  Kate's business: key client lost, loss: %lld RUB\n", loss);
                break;
            case 1:
                loss = (RUB)(person.business.current_value * 0.1f);
                printf("  Kate's business: equipment failure, loss: %lld RUB\n", loss);
                break;
            case 2:
                loss = (RUB)(person.business.payroll * 0.5f);
                printf("  Kate's business: employee issues, loss: %lld RUB\n", loss);
                break;
            case 3:
                loss = (RUB)(person.business.tax_debt * 0.2f);
                printf("  Kate's business: tax audit fine: %lld RUB\n", loss);
                break;
            case 4:
                loss = (RUB)(person.business.monthly_revenue * 0.2f);
                person.business.monthly_profit = (RUB)(person.business.monthly_profit * 0.85f);
                printf("  Kate's business: economic downturn, loss: %lld RUB\n", loss);
                break;
        }

        RUB insurance_coverage  = process_insurance_claim(person.business.business_insurance, loss, "business");
        loss                   -= insurance_coverage;
        person.business.account -= loss;

        if (person.business.account < -(RUB)(person.business.current_value * 0.5f))
            printf("  Kate's business: BANKRUPT!\n");
    }
}

void handle_business_risks(Male& person) {
    // Server failure
    if (random_event(0.02f)) {
        RUB tech_loss          = (RUB)(person.business.current_value * 0.05f);
        RUB insurance_coverage = process_insurance_claim(person.business.business_insurance, tech_loss, "tech");
        tech_loss             -= insurance_coverage;

        printf("  Henry's business: server failure, loss: %lld RUB\n", tech_loss);
        person.business.account -= tech_loss;
    }

    // Random business risk
    if (random_event(person.business.risk_factor / 3.0f)) {
        int risk_type = rand() % 6;
        RUB loss      = 0;

        switch (risk_type) {
            case 0:
                loss = (RUB)(person.business.current_value * 0.2f);
                printf("  Henry's business: legal issue, loss: %lld RUB\n", loss);
                break;
            case 1:
                loss = (RUB)(person.business.monthly_expenses * 2.0f);
                printf("  Henry's business: supply chain failure, loss: %lld RUB\n", loss);
                break;
            case 2:
                loss = (RUB)(person.business.account * 0.3f);
                printf("  Henry's business: cyberattack, loss: %lld RUB\n", loss);
                break;
            case 3:
                loss = (RUB)(person.business.payroll * 3.0f);
                printf("  Henry's business: key employee loss, cost: %lld RUB\n", loss);
                break;
            case 4:
                loss = (RUB)(person.business.monthly_revenue * 0.4f);
                person.business.monthly_revenue = (RUB)(person.business.monthly_revenue * 0.8f);
                printf("  Henry's business: competition pressure, loss: %lld RUB\n", loss);
                break;
            case 5:
                loss = (RUB)(person.business.current_value * 0.15f);
                person.business.monthly_profit = (RUB)(person.business.monthly_profit * 0.7f);
                printf("  Henry's business: CRISIS, loss: %lld RUB\n", loss);
                break;
        }

        RUB insurance_coverage   = process_insurance_claim(person.business.business_insurance, loss, "business");
        loss                    -= insurance_coverage;
        person.business.account -= loss;
    }
}

void handle_business_growth(Female& person) {
    // Organic growth
    if (random_event(person.business.success_probability / 10.0f)) {
        RUB growth = (RUB)(person.business.current_value * 0.1f);
        person.business.current_value  += growth;
        person.business.monthly_revenue = (RUB)(person.business.monthly_revenue * 1.05f);
        printf("  Kate's business grew! Value +%lld RUB\n", growth);
    }

    // Business expansion
    if (person.business.account   > (RUB)(person.business.current_value * 0.3f) &&
        person.business.years_active > 2 &&
        random_event(0.1f))
    {
        RUB expansion_cost = (RUB)(person.business.current_value * 0.5f);
        printf("  Kate's business: expansion investment — %lld RUB\n", expansion_cost);

        if (person.business.account >= expansion_cost) {
            person.business.account       -= expansion_cost;
            person.business.current_value += (RUB)(expansion_cost * 1.2f);
            person.business.employees_count += 2;
            person.business.monthly_revenue = (RUB)(person.business.monthly_revenue * 1.3f);

            if (person.business.employees_count > person.business.computer_count)
                person.business.computer_count = person.business.employees_count;
        }
    }
}

void handle_business_growth(Male& person) {
    // Organic growth
    if (random_event(person.business.success_probability / 8.0f)) {
        RUB growth = (RUB)(person.business.current_value * 0.15f);
        person.business.current_value  += growth;
        person.business.monthly_revenue = (RUB)(person.business.monthly_revenue * 1.1f);
        person.business.employees_count += 1;

        if (person.business.employees_count > person.business.computer_count) {
            int new_computers = person.business.employees_count - person.business.computer_count;
            printf("  Henry's business: buying %d new PC(s)\n", new_computers);
            person.business.computer_count = person.business.employees_count;
        }

        printf("  Henry's business grew! Value +%lld RUB\n", growth);
    }

    // New direction expansion
    if (person.business.account   > (RUB)(person.business.current_value * 0.4f) &&
        person.business.years_active > 3 &&
        random_event(0.15f))
    {
        RUB new_direction_cost = (RUB)(person.business.current_value * 0.4f);
        printf("  Henry's business: new direction — investment: %lld RUB\n", new_direction_cost);

        if (person.business.account >= new_direction_cost) {
            person.business.account        -= new_direction_cost;
            person.business.current_value  += (RUB)(new_direction_cost * 1.5f);
            person.business.monthly_revenue = (RUB)(person.business.monthly_revenue * 1.4f);
            person.business.risk_factor    *= 1.1f;
            person.business.computer_count += person.business.employees_count / 2;
        }
    }
}

// ============================================================================
// SECTION 9: BUSINESS ORCHESTRATION
// ============================================================================

bool try_open_business(Female& person, int year) {
    if (person.business.is_active)       return false;
    if (person.emergency_fund < 500000)  return false;
    if (person.skills.financial < 40.0f) return false;

    float business_chance = (person.skills.financial  / 200.0f)
                          + (person.skills.managerial  / 200.0f)
                          + (year - 2026)              / 100.0f;

    if (!random_event(business_chance / 20.0f)) return false;

    printf("\n=== Kate founds a company! ===\n");

    int business_type = rand() % 3;
    RUB investment    = 300000 + rand() % 1000000;

    person.business.is_active            = true;
    person.business.type                 = (BusinessType)business_type;
    person.business.initial_investment   = investment;
    person.business.current_value        = investment;
    person.business.success_probability  = 0.5f + (person.skills.managerial / 200.0f);
    person.business.risk_factor          = 0.3f;
    person.business.employees_count      = 1 + rand() % 5;
    person.business.has_office           = random_event(0.5f);

    if (business_type == BUSINESS_IT || business_type == BUSINESS_ONLINE) {
        init_business_computers(person.business, person.business.employees_count + 1);
        person.business.monthly_cloud = 15000;
    } else {
        init_business_computers(person.business, person.business.employees_count / 2 + 1);
    }

    person.business.monthly_revenue = (RUB)(investment * 0.1f);
    person.business.monthly_expenses = (RUB)(investment * 0.07f);
    person.business.monthly_profit  = person.business.monthly_revenue - person.business.monthly_expenses;

    if (person.emergency_fund >= investment) {
        person.emergency_fund    -= investment;
        person.business.account   = (RUB)(investment * 0.3f);
    } else {
        RUB need_credit           = investment - person.emergency_fund;
        person.business.credit    = need_credit;
        person.business.account   = (RUB)(person.emergency_fund + need_credit * 0.3f);
        person.emergency_fund     = 0;
    }

    person.business.business_insurance = {
        INSURANCE_EXTENDED,
        (RUB)(investment * 0.03f),
        20000,
        investment,
        0, 0, 0, 0.7f, 0.6f,
        true, 0
    };

    printf("  Business type:        %d\n",    business_type);
    printf("  Investment:           %lld RUB\n", investment);
    printf("  Success probability:  %.1f%%\n", person.business.success_probability * 100.0f);
    printf("  Employees:            %d\n",    person.business.employees_count);
    printf("  Computers:            %d\n",    person.business.computer_count);

    return true;
}

bool try_open_business(Male& person, int year) {
    if (person.business.is_active)       return false;
    if (person.emergency_fund < 800000)  return false;
    if (person.skills.financial < 50.0f) return false;

    float business_chance = (person.skills.financial  / 150.0f)
                          + (person.skills.managerial  / 150.0f)
                          + (year - 2026)              / 80.0f;

    if (!random_event(business_chance / 15.0f)) return false;

    printf("\n=== Henry founds a business! ===\n");

    int business_type = 1 + rand() % 5;
    RUB investment    = 500000 + rand() % 2000000;

    person.business.is_active            = true;
    person.business.type                 = (BusinessType)business_type;
    person.business.initial_investment   = investment;
    person.business.current_value        = investment;
    person.business.success_probability  = 0.6f + (person.skills.managerial / 150.0f);
    person.business.risk_factor          = 0.4f;
    person.business.employees_count      = 2 + rand() % 10;
    person.business.has_office           = true;
    person.business.office_rent          = 50000 + rand() % 150000;

    if (business_type == BUSINESS_IT) {
        init_business_computers(person.business, person.business.employees_count + 2);
        person.business.monthly_cloud = 20000;
    } else {
        init_business_computers(person.business, person.business.employees_count / 2 + 1);
    }

    person.business.monthly_revenue  = (RUB)(investment * 0.15f);
    person.business.monthly_expenses = (RUB)(investment * 0.1f + person.business.office_rent);
    person.business.monthly_profit   = person.business.monthly_revenue - person.business.monthly_expenses;

    if (person.emergency_fund >= investment) {
        person.emergency_fund    -= investment;
        person.business.account   = (RUB)(investment * 0.4f);
    } else {
        RUB need_credit           = investment - person.emergency_fund;
        person.business.credit    = need_credit;
        person.business.account   = (RUB)(person.emergency_fund + need_credit * 0.4f);
        person.emergency_fund     = 0;
    }

    person.business.business_insurance = {
        INSURANCE_PREMIUM,
        (RUB)(investment * 0.05f),
        15000,
        (RUB)(investment * 1.5f),
        0, 0, 0, 0.85f, 0.8f,
        true, 0
    };

    printf("  Business type:   %d\n",       business_type);
    printf("  Investment:      %lld RUB\n", investment);
    printf("  Employees:       %d\n",       person.business.employees_count);
    printf("  Computers:       %d\n",       person.business.computer_count);
    printf("  Office rent:     %lld RUB/month\n", person.business.office_rent);

    return true;
}

void manage_active_business(Female& person, int month, int year) {
    if (!person.business.is_active) return;

    person.business.years_active++;
    person.business.account += person.business.monthly_profit;

    manage_business_computers(person.business, month, year);
    calculate_business_tax(person);
    handle_business_risks(person);
    handle_business_growth(person);
}

void manage_active_business(Male& person, int month, int year) {
    if (!person.business.is_active) return;

    person.business.years_active++;
    person.business.account += person.business.monthly_profit;

    manage_business_computers(person.business, month, year);
    calculate_business_tax(person);
    handle_business_risks(person);
    handle_business_growth(person);
}

void try_sell_business(Female& person, int /*year*/) {
    if (!person.business.is_active)             return;
    if (person.business.years_active < 3)       return;
    if (person.business.current_value <= person.business.initial_investment * 2) return;
    if (!random_event(0.1f))                     return;

    RUB sell_price = (RUB)(person.business.current_value * (0.8f + (rand() % 40) / 100.0f));
    printf("\n=== Kate sold her business for %lld RUB! ===\n", sell_price);

    person.emergency_fund             += (RUB)(sell_price * 0.7f);
    person.tbank.account              += person.business.account;
    person.business.is_active          = false;
    person.business.current_value      = 0;
    person.skills.current_profession   = PROFESSION_DIRECTOR;
    person.salary                      = 300000;
}

void try_sell_business(Male& person, int /*year*/) {
    if (!person.business.is_active)             return;
    if (person.business.years_active < 4)       return;
    if (person.business.current_value <= person.business.initial_investment * 3) return;
    if (!random_event(0.15f))                    return;

    RUB sell_price = (RUB)(person.business.current_value * (0.9f + (rand() % 30) / 100.0f));
    printf("\n=== Henry sold his business for %lld RUB! ===\n", sell_price);

    person.emergency_fund             += (RUB)(sell_price * 0.65f);
    person.sber.account               += person.business.account;
    person.dream_car_price             = (RUB)(sell_price * 0.5f);
    person.business.is_active          = false;
    person.business.current_value      = 0;
    person.skills.current_profession   = PROFESSION_ENTREPRENEUR;
}

// ============================================================================
// SECTION 10: TAXES & GLOBAL ECONOMY
// ============================================================================

void calculate_monthly_taxes(int month, int /*year*/) {
    // Property tax (November)
    if (month == 11) {
        RUB kate_property_tax  = (RUB)(Kate.flat.cadastral_value  * PROPERTY_TAX_RATE);
        RUB henry_property_tax = (RUB)(Henry.house.cadastral_value * PROPERTY_TAX_RATE);

        printf("  Property tax: Kate %lld RUB, Henry %lld RUB\n",
               kate_property_tax, henry_property_tax);

        Kate.tbank.tax_debt  += kate_property_tax;
        Henry.sber.tax_debt  += henry_property_tax;
    }

    // Transport tax (October)
    if (month == 10) {
        printf("  Transport tax: Kate %lld RUB, Henry %lld RUB\n",
               Kate.matiz.tax_rate, Henry.volga.tax_rate);

        Kate.tbank.tax_debt  += Kate.matiz.tax_rate;
        Henry.sber.tax_debt  += Henry.volga.tax_rate;
    }
}

void pay_taxes(int month, int /*year*/) {
    if (month != 12) return;

    // Kate's tax payment
    if (Kate.tbank.tax_debt > 0) {
        printf("  Kate: tax payment — %lld RUB\n", Kate.tbank.tax_debt);

        if (Kate.tbank.account >= Kate.tbank.tax_debt) {
            Kate.tbank.account  -= Kate.tbank.tax_debt;
            Kate.tbank.tax_paid += Kate.tbank.tax_debt;
            Kate.tbank.tax_debt  = 0;
        } else {
            RUB tax_deficit      = Kate.tbank.tax_debt - Kate.tbank.account;
            RUB penalty          = (RUB)(tax_deficit * 0.1f);
            printf("  Kate: tax deficit! Penalty: %lld RUB\n", penalty);
            Kate.tbank.tax_debt  = tax_deficit + penalty;
            Kate.tbank.account   = 0;
        }
    }

    // Henry's tax payment
    if (Henry.sber.tax_debt > 0) {
        printf("  Henry: tax payment — %lld RUB\n", Henry.sber.tax_debt);

        if (Henry.sber.account >= Henry.sber.tax_debt) {
            Henry.sber.account  -= Henry.sber.tax_debt;
            Henry.sber.tax_paid += Henry.sber.tax_debt;
            Henry.sber.tax_debt  = 0;
        } else {
            RUB tax_deficit      = Henry.sber.tax_debt - Henry.sber.account;
            RUB penalty          = (RUB)(tax_deficit * 0.1f);
            printf("  Henry: tax deficit! Penalty: %lld RUB\n", penalty);
            Henry.sber.tax_debt  = tax_deficit + penalty;
            Henry.sber.account   = 0;
        }
    }
}

void pay_insurance_premiums(int month, int /*year*/) {
    if (month != 1) return;

    printf("  Annual insurance payments:\n");

    // Kate's total insurance
    RUB kate_total = Kate.life_insurance.annual_premium
                   + Kate.matiz.casco.annual_premium
                   + Kate.flat.property_insurance.annual_premium
                   + Kate.health.health_insurance.annual_premium;
    if (Kate.business.is_active)
        kate_total += Kate.business.business_insurance.annual_premium;

    Kate.tbank.account -= kate_total;
    printf("    Kate:  %lld RUB\n", kate_total);

    // Henry's total insurance
    RUB henry_total = Henry.life_insurance.annual_premium
                    + Henry.volga.casco.annual_premium
                    + Henry.house.property_insurance.annual_premium
                    + Henry.health.health_insurance.annual_premium;
    if (Henry.business.is_active)
        henry_total += Henry.business.business_insurance.annual_premium;

    Henry.sber.account -= henry_total;
    printf("    Henry: %lld RUB\n", henry_total);
}

void apply_inflation(int year) {
    if (year % 2 != 0) return;

    float inflation_factor = 1.0f + (INFLATION / 100.0f) * 2.0f;
    Kate.salary  = (RUB)(Kate.salary  * inflation_factor);
    Henry.salary = (RUB)(Henry.salary * inflation_factor);
}

void update_economic_params(int year) {
    if (year % 2 != 0) return;

    float rate_change        = 1.0f + USD_GROWTH * 2.0f;
    Kate.tbank.usd_rate     *= rate_change;
    Henry.sber.usd_rate     *= rate_change;
}

void update_insurance(int year) {
    if (year % 2 != 0) return;

    Kate.life_insurance.annual_premium =
        calculate_insurance_premium(Kate.life_insurance.type, 2000000,
                                    year - 2026, Kate.life_insurance.years_active > 3);

    Kate.matiz.casco.annual_premium =
        calculate_insurance_premium(Kate.matiz.casco.type, Kate.matiz.price,
                                    Kate.matiz.age, Kate.matiz.casco.years_active > 3);

    Kate.flat.property_insurance.annual_premium =
        calculate_insurance_premium(Kate.flat.property_insurance.type, Kate.flat.price,
                                    0, Kate.flat.property_insurance.years_active > 3);

    Henry.life_insurance.annual_premium =
        calculate_insurance_premium(Henry.life_insurance.type, 5000000,
                                    year - 2026, Henry.life_insurance.years_active > 3);

    Henry.volga.casco.annual_premium =
        calculate_insurance_premium(Henry.volga.casco.type, Henry.volga.price,
                                    Henry.volga.age, Henry.volga.casco.years_active > 3);

    Henry.house.property_insurance.annual_premium =
        calculate_insurance_premium(Henry.house.property_insurance.type, Henry.house.price,
                                    0, Henry.house.property_insurance.years_active > 3);

    if (Kate.business.is_active)
        Kate.business.business_insurance.annual_premium =
            (RUB)(Kate.business.current_value * 0.03f);

    if (Henry.business.is_active)
        Henry.business.business_insurance.annual_premium =
            (RUB)(Henry.business.current_value * 0.05f);
}

// ============================================================================
// SECTION 11: INITIALIZATION
// ============================================================================

void Kate_init_computers() {
    Kate.personal_pc = {true, 80000, 80000, 2025, 1, 75.0f, false, true, 0, 70, 16,  512,  false, 0, 0};
    Kate.laptop      = {true, 65000, 65000, 2026, 0, 70.0f, false, true, 0, 60,  8,  256,  false, 0, 0};
    Kate.work_pc     = {true,     0,     0,    0, 0,  0.0f, false, false, 0,  0,  0,    0, false, 0, 0};
    Kate.total_tech_cost = 145000;
}

void Henry_init_computers() {
    Henry.gaming_pc   = {true, 150000, 150000, 2025, 1, 95.0f, false, true, 0, 95, 32, 2000, true,  0, 0};
    Henry.work_laptop = {true,  90000,  90000, 2026, 0, 80.0f, false, true, 0, 80, 16, 1000, true,  0, 0};
    Henry.home_server = {true,  45000,  45000, 2026, 0, 50.0f, false, true, 0, 40,  8, 4000, false, 0, 0};
    Henry.total_tech_cost = 285000;
}

void init_character_kate() {
    // Bank
    Kate.tbank = {50000, 850000, 0, 500000, 14.5f, 21.0f, 1500, 92.5f, 0, 0, 0, 0, 0};

    // Income
    Kate.salary       = 145000;
    Kate.net_salary   = (RUB)(Kate.salary * (1.0f - INCOME_TAX));
    Kate.annual_income = 0;

    // Monthly expenses
    Kate.monthly_food           = 25000;
    Kate.monthly_clothing       = 8000;
    Kate.monthly_entertainment  = 12000;
    Kate.monthly_health         = 5000;
    Kate.monthly_transport      = 3000;
    Kate.monthly_communications = 3500;
    Kate.monthly_misc           = 7000;
    Kate.monthly_beauty         = 6000;
    Kate.monthly_gifts          = 3000;

    // Car
    Kate.matiz = {
        8000, 280000, 25000, 18000, 5000, 0, 3, true, 85,
        (RUB)(85 * TRANSPORT_TAX_BASE),
        {INSURANCE_EXTENDED, 0, 15000, 280000, 0.85f, 0, 0, 0, 0, true, 0}
    };
    Kate.matiz.casco.annual_premium =
        calculate_insurance_premium(INSURANCE_EXTENDED, Kate.matiz.price, Kate.matiz.age, true);

    // Health
    Kate.health = {
        4000, 15000, 0, 25000, 2000, false,
        {INSURANCE_PREMIUM, 45000, 0, 1000000, 0, 0.95f, 0, 0, 0, true, 0}
    };

    // Home (flat)
    Kate.flat = {
        7500000, 6500, 4500, 30000, 0, 20000, 8200000,
        {INSURANCE_EXTENDED, 0, 20000, 7500000, 0, 0, 0.9f, 0, 0, true, 0}
    };
    Kate.flat.property_insurance.annual_premium =
        calculate_insurance_premium(INSURANCE_EXTENDED, Kate.flat.price, 0, true);

    // Savings
    Kate.emergency_fund = 200000;

    // Tech
    Kate_init_computers();

    // Skills & career
    Kate.skills = {65.0f, 40.0f, 50.0f, 70.0f, 3.0f, PROFESSION_SPECIALIST, 0, 1};
    Kate.career_stage = 0;
    Kate.career_path[Kate.career_stage++] = PROFESSION_SPECIALIST;
    Kate.total_education_cost = 0;

    // Business
    Kate.business.is_active      = false;
    Kate.business.computer_count = 0;

    // Life insurance
    Kate.life_insurance = {INSURANCE_EXTENDED, 25000, 10000, 2000000, 0.9f, 0.8f, 0, 0, 0.5f, true, 0};
}

void init_character_henry() {
    // Bank
    Henry.sber = {75000, 1800000, 0, 800000, 15.0f, 20.0f, 2500, 92.5f, 0, 0, 0, 0, 0};

    // Income
    Henry.salary        = 195000;
    Henry.net_salary    = (RUB)(Henry.salary * (1.0f - INCOME_TAX));
    Henry.annual_income = 0;

    // Monthly expenses
    Henry.monthly_food           = 30000;
    Henry.monthly_education      = 15000;
    Henry.monthly_clothing       = 6000;
    Henry.monthly_entertainment  = 10000;
    Henry.monthly_health         = 4000;
    Henry.monthly_sport          = 5000;
    Henry.monthly_communications = 4000;
    Henry.monthly_gadgets        = 5000;
    Henry.monthly_hobbies        = 4000;

    // Car
    Henry.volga = {
        15000, 950000, 45000, 45000, 7000, 0, 2, true, 150,
        (RUB)(150 * TRANSPORT_TAX_BASE),
        {INSURANCE_PREMIUM, 0, 10000, 950000, 0.95f, 0, 0, 0, 0, true, 0}
    };
    Henry.volga.casco.annual_premium =
        calculate_insurance_premium(INSURANCE_PREMIUM, Henry.volga.price, Henry.volga.age, true);

    // Health
    Henry.health = {
        5000, 12000, 0, 20000, 1500, false,
        {INSURANCE_EXTENDED, 35000, 5000, 800000, 0, 0.85f, 0, 0, 0, true, 0}
    };

    // Home (house)
    Henry.house = {
        12000000, 12000, 10000, 60000, 0, 30000, 13500000,
        {INSURANCE_PREMIUM, 0, 15000, 12000000, 0, 0, 0.95f, 0, 0, true, 0}
    };
    Henry.house.property_insurance.annual_premium =
        calculate_insurance_premium(INSURANCE_PREMIUM, Henry.house.price, 0, true);

    // Savings & goals
    Henry.dream_stash     = 0;
    Henry.dream_car_price = 4500000;
    Henry.emergency_fund  = 300000;

    // Tech
    Henry_init_computers();

    // Skills & career
    Henry.skills = {45.0f, 75.0f, 60.0f, 80.0f, 4.0f, PROFESSION_SENIOR, 0, 2};
    Henry.career_stage = 0;
    Henry.career_path[Henry.career_stage++] = PROFESSION_SENIOR;
    Henry.total_education_cost = 0;

    // Business
    Henry.business.is_active      = false;
    Henry.business.computer_count = 0;

    // Life insurance
    Henry.life_insurance = {INSURANCE_PREMIUM, 40000, 5000, 5000000, 0.95f, 0.9f, 0, 0, 0.6f, true, 0};
}

void initialize_simulation() {
    srand((unsigned int)time(NULL));
    init_character_kate();
    init_character_henry();
}

// ============================================================================
// SECTION 12: SIMULATION LOOP
// ============================================================================

void process_month(int month, int year) {
    // --- Income ---
    process_salary(Kate,  month, year);
    process_salary(Henry, month, year);

    // --- Business management ---
    manage_active_business(Kate,  month, year);
    manage_active_business(Henry, month, year);

    // --- Living expenses ---
    process_monthly_expenses(Kate,  month, year);
    process_monthly_expenses(Henry, month, year);

    // --- Random events ---
    process_health_events(Kate,  month, year);
    process_health_events(Henry, month, year);
    process_force_majeure(Kate,  month, year);
    process_force_majeure(Henry, month, year);

    // --- Asset events (semi-annual) ---
    if (month == 1 || month == 6) {
        process_car_events(Kate.matiz, Kate.tbank,  Kate.emergency_fund,  "Kate",  Kate.life_insurance);
        process_car_events(Henry.volga, Henry.sber, Henry.emergency_fund, "Henry", Henry.life_insurance);
    }

    if (random_event(0.3f)) {
        process_home_events(Kate.flat,  Kate.tbank,  Kate.emergency_fund,  "Kate");
        process_home_events(Henry.house, Henry.sber, Henry.emergency_fund, "Henry");
    }

    // --- Tech repairs ---
    handle_computer_repair(Kate,  Kate.personal_pc,    "personal PC");
    handle_computer_repair(Kate,  Kate.laptop,         "laptop");
    handle_computer_repair(Henry, Henry.gaming_pc,     "gaming PC");
    handle_computer_repair(Henry, Henry.work_laptop,   "work laptop");

    // --- Tech upgrades ---
    if (Kate.work_pc.purchase_price == 0 &&
        Kate.skills.current_profession >= PROFESSION_SENIOR)
        buy_computer(Kate, "work_pc", Kate.emergency_fund);

    if (Kate.personal_pc.needs_upgrade &&
        Kate.emergency_fund > Kate.personal_pc.upgrade_cost)
        buy_computer(Kate, "upgrade_personal", Kate.emergency_fund);

    if (Henry.gaming_pc.age > 4 &&
        random_event(0.3f) &&
        Henry.emergency_fund > 150000)
        buy_computer(Henry, "new_gaming", Henry.emergency_fund);

    // --- Taxes ---
    calculate_monthly_taxes(month, year);

    // --- Annual payments (January) ---
    if (month == 1) {
        pay_insurance_premiums(month, year);
        Kate.tbank.account  -= Kate.matiz.insurance;
        Henry.sber.account  -= Henry.volga.insurance;
    }

    // --- Scheduled maintenance & annual costs ---
    if (month == 3) Kate.tbank.account  -= Kate.flat.annual_insurance;
    if (month == 6) {
        Henry.sber.account  -= Henry.house.annual_insurance;
        Kate.tbank.account  -= Kate.matiz.maintenance;
        Henry.sber.account  -= Henry.volga.maintenance;
    }
    if (month == 8) {
        Kate.tbank.account  -= Kate.flat.renovation;
        Henry.sber.account  -= Henry.house.renovation;
    }

    // --- Henry's education payments ---
    if (month == 9)
        Henry.sber.account -= Henry.monthly_education;
    else if (month != 12 && random_event(0.2f))
        Henry.sber.account -= (RUB)(Henry.monthly_education * 0.3f);

    // --- Tax settlement (December) ---
    pay_taxes(month, year);

    // --- Savings & deposits ---
    process_deposits(Kate,  month, year);
    process_deposits(Henry, month, year);

    // Henry's dream car savings
    if (Henry.sber.account > 150000) {
        RUB saving           = (RUB)(Henry.sber.account * 0.15f);
        Henry.dream_stash   += saving;
        Henry.sber.account  -= saving;
    }
    if (Henry.dream_stash >= Henry.dream_car_price) {
        Henry.volga.price     = Henry.dream_car_price;
        Henry.dream_stash    -= Henry.dream_car_price;
        Henry.dream_car_price = (RUB)(Henry.dream_car_price * 1.5f);
    }

    // --- Emergency fund top-up ---
    if (Kate.tbank.account > 100000 && Kate.emergency_fund < 500000) {
        RUB transfer          = (RUB)(Kate.tbank.account * 0.1f);
        Kate.emergency_fund  += transfer;
        Kate.tbank.account   -= transfer;
    }
    if (Henry.sber.account > 150000 && Henry.emergency_fund < 700000) {
        RUB transfer           = (RUB)(Henry.sber.account * 0.1f);
        Henry.emergency_fund  += transfer;
        Henry.sber.account    -= transfer;
    }
}

void process_year_end(int& month, int& year, int& years_passed) {
    // --- January: career & tech updates ---
    if (month == 1) {
        process_career_growth(Kate,  year);
        process_career_growth(Henry, year);
        process_promotion(Kate,  year);
        process_promotion(Henry, year);

        if (!Kate.business.is_active)  try_open_business(Kate,  year);
        if (!Henry.business.is_active) try_open_business(Henry, year);

        // Annual tech aging
        update_computer_state(Kate.personal_pc,   "Kate",  "personal PC");
        update_computer_state(Kate.laptop,         "Kate",  "laptop");
        if (Kate.work_pc.purchase_price > 0)
            update_computer_state(Kate.work_pc,    "Kate",  "work PC");

        update_computer_state(Henry.gaming_pc,     "Henry", "gaming PC");
        update_computer_state(Henry.work_laptop,   "Henry", "work laptop");
        update_computer_state(Henry.home_server,   "Henry", "home server");
    }

    // --- December: business sell attempts ---
    if (month == 12) {
        try_sell_business(Kate,  year);
        try_sell_business(Henry, year);
    }

    // --- Year rollover ---
    if (month == 13) {
        month = 1;
        year++;
        years_passed++;

        Kate.skills.experience++;
        Henry.skills.experience++;

        apply_inflation(year);
        update_economic_params(year);
        update_insurance(year);

        Kate.annual_income  = 0;
        Henry.annual_income = 0;

        // Reset car working state annually
        Kate.matiz.is_working  = true;
        Henry.volga.is_working = true;

        // Progress report every 5 years
        if (years_passed % 5 == 0) {
            printf("\n--- Simulation progress: %d years ---\n", years_passed);
            printf("  Kate  — PC: %.0f%% (%d yr), Laptop: %.0f%% (%d yr)\n",
                   Kate.personal_pc.performance, Kate.personal_pc.age,
                   Kate.laptop.performance,      Kate.laptop.age);
            printf("  Henry — Gaming PC: %.0f%% (%d yr), Laptop: %.0f%% (%d yr)\n",
                   Henry.gaming_pc.performance,   Henry.gaming_pc.age,
                   Henry.work_laptop.performance, Henry.work_laptop.age);

            if (Kate.business.is_active)
                printf("  Kate's business:  value %lld RUB, PCs: %d\n",
                       Kate.business.current_value, Kate.business.computer_count);

            if (Henry.business.is_active)
                printf("  Henry's business: value %lld RUB, PCs: %d\n",
                       Henry.business.current_value, Henry.business.computer_count);
        }
    }
}

void run_simulation() {
    int month        = 2;
    int year         = 2026;
    int years_passed = 0;

    while (years_passed < 40) {
        process_month(month, year);
        process_year_end(month, year, years_passed);
        month++;
    }
}

// ============================================================================
// SECTION 13: FINAL REPORT
// ============================================================================

void print_character_report_kate() {
    printf("\n╔══════════════════════════════╗\n");
    printf("║         KATE — RESULTS       ║\n");
    printf("╚══════════════════════════════╝\n");

    printf("\n  Career path:\n");
    for (int i = 0; i < Kate.career_stage; i++)
        printf("    Stage %d: level %d\n", i + 1, Kate.career_path[i]);

    printf("\n  Skills:\n");
    printf("    Technical:     %.1f\n", Kate.skills.technical);
    printf("    Managerial:    %.1f\n", Kate.skills.managerial);
    printf("    Financial:     %.1f\n", Kate.skills.financial);
    printf("    Certifications: %d\n",  Kate.skills.certifications);

    printf("\n  Education cost:  %lld RUB\n", Kate.total_education_cost);
    printf("  Tech cost:       %lld RUB\n",   Kate.total_tech_cost);

    printf("\n  Devices:\n");
    printf("    Personal PC: %lld RUB (age: %d yr, performance: %.0f%%)\n",
           Kate.personal_pc.current_value, Kate.personal_pc.age, Kate.personal_pc.performance);
    printf("    Laptop:      %lld RUB (age: %d yr, performance: %.0f%%)\n",
           Kate.laptop.current_value, Kate.laptop.age, Kate.laptop.performance);
    if (Kate.work_pc.purchase_price > 0)
        printf("    Work PC:     %lld RUB (age: %d yr, performance: %.0f%%)\n",
               Kate.work_pc.current_value, Kate.work_pc.age, Kate.work_pc.performance);

    if (Kate.business.is_active) {
        printf("\n  Business:\n");
        printf("    Type:           %d\n",       Kate.business.type);
        printf("    Years active:   %d\n",       Kate.business.years_active);
        printf("    Investment:     %lld RUB\n", Kate.business.initial_investment);
        printf("    Current value:  %lld RUB\n", Kate.business.current_value);
        printf("    Monthly profit: %lld RUB\n", Kate.business.monthly_profit);
        printf("    Employees:      %d\n",       Kate.business.employees_count);
        printf("    Computers:      %d\n",       Kate.business.computer_count);
        printf("    Taxes paid:     %lld RUB\n", Kate.business.tax_paid);
        printf("    Capital:        %lld RUB\n", Kate.business.account);
    }
}

void print_character_report_henry() {
    printf("\n╔══════════════════════════════╗\n");
    printf("║        HENRY — RESULTS       ║\n");
    printf("╚══════════════════════════════╝\n");

    printf("\n  Career path:\n");
    for (int i = 0; i < Henry.career_stage; i++)
        printf("    Stage %d: level %d\n", i + 1, Henry.career_path[i]);

    printf("\n  Skills:\n");
    printf("    Technical:     %.1f\n", Henry.skills.technical);
    printf("    Managerial:    %.1f\n", Henry.skills.managerial);
    printf("    Financial:     %.1f\n", Henry.skills.financial);
    printf("    Certifications: %d\n",  Henry.skills.certifications);

    printf("\n  Education cost:  %lld RUB\n", Henry.total_education_cost);
    printf("  Tech cost:       %lld RUB\n",   Henry.total_tech_cost);

    printf("\n  Devices:\n");
    printf("    Gaming PC:   %lld RUB (age: %d yr, performance: %.0f%%)\n",
           Henry.gaming_pc.current_value, Henry.gaming_pc.age, Henry.gaming_pc.performance);
    printf("    Work laptop: %lld RUB (age: %d yr, performance: %.0f%%)\n",
           Henry.work_laptop.current_value, Henry.work_laptop.age, Henry.work_laptop.performance);
    printf("    Home server: %lld RUB (age: %d yr, performance: %.0f%%)\n",
           Henry.home_server.current_value, Henry.home_server.age, Henry.home_server.performance);

    if (Henry.business.is_active) {
        printf("\n  Business:\n");
        printf("    Type:           %d\n",       Henry.business.type);
        printf("    Years active:   %d\n",       Henry.business.years_active);
        printf("    Investment:     %lld RUB\n", Henry.business.initial_investment);
        printf("    Current value:  %lld RUB\n", Henry.business.current_value);
        printf("    Monthly profit: %lld RUB\n", Henry.business.monthly_profit);
        printf("    Employees:      %d\n",       Henry.business.employees_count);
        printf("    Computers:      %d\n",       Henry.business.computer_count);
        printf("    Taxes paid:     %lld RUB\n", Henry.business.tax_paid);
        printf("    Capital:        %lld RUB\n", Henry.business.account);
    }
}

void print_final_report() {
    print_character_report_kate();
    print_character_report_henry();

    // --- Total capital ---
    RUB kate_tech_value = Kate.personal_pc.current_value
                        + Kate.laptop.current_value
                        + Kate.work_pc.current_value;

    RUB kate_business_value = 0;
    if (Kate.business.is_active) {
        kate_business_value = Kate.business.current_value + Kate.business.account;
        for (int i = 0; i < Kate.business.computer_count; i++)
            kate_business_value += Kate.business.office_computers[i].current_value;
    }

    RUB kate_total = Kate.tbank.account
                   + Kate.tbank.deposit
                   + Kate.flat.price
                   + Kate.emergency_fund
                   + (RUB)(Kate.tbank.usd_account * Kate.tbank.usd_rate)
                   + kate_tech_value
                   + kate_business_value
                   - Kate.tbank.credit;

    RUB henry_tech_value = Henry.gaming_pc.current_value
                         + Henry.work_laptop.current_value
                         + Henry.home_server.current_value;

    RUB henry_business_value = 0;
    if (Henry.business.is_active) {
        henry_business_value = Henry.business.current_value + Henry.business.account;
        for (int i = 0; i < Henry.business.computer_count; i++)
            henry_business_value += Henry.business.office_computers[i].current_value;
    }

    RUB henry_total = Henry.sber.account
                    + Henry.sber.deposit
                    + Henry.house.price
                    + Henry.emergency_fund
                    + Henry.dream_stash
                    + (RUB)(Henry.sber.usd_account * Henry.sber.usd_rate)
                    + henry_tech_value
                    + henry_business_value
                    - Henry.sber.credit;

    printf("\n╔══════════════════════════════╗\n");
    printf("║       TOTAL CAPITAL          ║\n");
    printf("╚══════════════════════════════╝\n");

    printf("\n  Personal income taxes paid:\n");
    printf("    Kate:  %lld RUB\n", Kate.tbank.tax_paid);
    printf("    Henry: %lld RUB\n", Henry.sber.tax_paid);
    printf("    Total: %lld RUB\n", Kate.tbank.tax_paid + Henry.sber.tax_paid);

    printf("\n  Net worth:\n");
    printf("    Kate:  %lld RUB  (tech: %lld RUB)\n", kate_total,  kate_tech_value);
    printf("    Henry: %lld RUB  (tech: %lld RUB)\n", henry_total, henry_tech_value);
    printf("    TOTAL: %lld RUB\n", kate_total + henry_total);
}

// ============================================================================
// SECTION 14: ENTRY POINT
// ============================================================================

int main() {
    freopen("output.txt", "w", stdout);

    initialize_simulation();
    run_simulation();
    print_final_report();

    return 0;
}
