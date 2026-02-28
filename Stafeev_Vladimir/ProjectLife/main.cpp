#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// global economical factors
const float BANK_RATE = 15.5;
const float INFLATION = 7.5;
const float INFLATION_INCREASE = 1.0;
const float CAR_DEPRECIATION = 0.15;
const float USD_GROWTH = 0.05;
const float INCOME_TAX = 0.13;
const float BUSINESS_TAX = 0.06;
const float BUSINESS_TAX_PROFIT = 0.15;
const float PROPERTY_TAX_RATE = 0.002;
const float TRANSPORT_TAX_BASE = 50;
const float TECH_DEPRECIATION = 0.25;
const float PC_UPGRADE_COST = 0.3;

using RUB = long long int;
using USD = long long int;
using Percent = float;


enum Profession {
    PROFESSION_JUNIOR = 0,
    PROFESSION_SPECIALIST = 1,
    PROFESSION_SENIOR = 2,
    PROFESSION_TEAM_LEAD = 3,
    PROFESSION_MANAGER = 4,
    PROFESSION_DIRECTOR = 5,
    PROFESSION_ENTREPRENEUR = 6
};


enum BusinessType {
    BUSINESS_ONLINE = 0,
    BUSINESS_RETAIL = 1,
    BUSINESS_MANUFACTURING = 2,
    BUSINESS_CONSULTING = 3,
    BUSINESS_FREELANCE = 4,
    BUSINESS_IT = 5
};


enum InsuranceType {
    INSURANCE_NONE = 0,
    INSURANCE_BASIC = 1,
    INSURANCE_EXTENDED = 2,
    INSURANCE_PREMIUM = 3
};


struct Computer {
    bool is_personal;
    RUB purchase_price;
    RUB current_value;
    int purchase_year;
    int age;
    float performance;
    bool needs_upgrade;
    bool is_working;
    RUB upgrade_cost;


    int cpu_power;
    int ram;
    int storage;
    bool has_gpu;

    // for business
    int quantity;
    RUB total_value;
};


struct Skills {
    //(0-100)
    float technical;
    float managerial;
    float financial;
    float communication;
    float experience; //in years
    Profession current_profession;
    RUB education_cost;
    int certifications;
};


struct InsurancePolicy {
    InsuranceType type;
    RUB annual_premium;
    RUB deductible;
    RUB coverage_limit;
    float accident_coverage;
    float health_coverage;
    float property_coverage;
    float business_coverage;
    float tech_coverage;
    bool is_active;
    int years_active;
};


struct Business {
    bool is_active;
    BusinessType type;
    RUB initial_investment;
    RUB current_value;
    RUB monthly_revenue;
    RUB monthly_expenses;
    RUB monthly_profit;
    RUB account;
    RUB credit;
    RUB tax_debt;
    RUB tax_paid;
    float success_probability;
    float risk_factor;
    int years_active;

    int employees_count;
    RUB payroll;
    bool has_office;
    RUB office_rent;

    //for business
    Computer office_computers[50];
    int computer_count;
    RUB monthly_internet;
    RUB monthly_software;
    RUB monthly_cloud;

    InsurancePolicy business_insurance;
};

struct Bank {
    RUB account;
    RUB deposit;
    RUB credit;
    RUB credit_limit;
    Percent interest;
    Percent credit_rate;

    USD usd_account;
    float usd_rate;

    RUB tax_debt;
    RUB tax_paid;

    // invest
    RUB stocks;
    RUB bonds;
    RUB crypto;
};

struct Car {
    RUB monthly_fuel;
    RUB price;
    RUB maintenance;
    RUB insurance;
    RUB parking;
    RUB emergency_repair;
    int age;
    bool is_working;
    int engine_power;
    RUB tax_rate;

    InsurancePolicy casco;
};

struct Health {
    RUB monthly_sport;
    RUB annual_checkup;
    RUB emergency;
    RUB dental;
    RUB medicines;
    bool chronic_disease;

    InsurancePolicy health_insurance;
};

struct Home {
    RUB price;
    RUB monthly_utilities;
    RUB annual_insurance;
    RUB renovation;
    RUB emergency_repair;
    RUB appliances;
    RUB cadastral_value;

    InsurancePolicy property_insurance;
};

struct Female {
    Bank tbank;
    Car matiz;
    RUB salary;
    RUB net_salary;
    RUB monthly_food;
    RUB monthly_clothing;
    RUB monthly_entertainment;
    RUB monthly_health;
    RUB monthly_transport;
    RUB monthly_communications;
    RUB monthly_misc;
    RUB monthly_beauty;
    RUB monthly_gifts;
    Home flat;
    Health health;
    RUB emergency_fund;

    // personal
    Computer personal_pc;
    Computer laptop;
    Computer work_pc;

    Skills skills;
    Business business;
    InsurancePolicy life_insurance;
    RUB annual_income;

    Profession career_path[20];
    int career_stage;
    RUB total_education_cost;
    RUB total_tech_cost;
};


struct Male {
    Bank sber;
    Car volga;
    RUB salary;
    RUB net_salary;
    RUB monthly_food;
    RUB monthly_education;
    RUB monthly_clothing;
    RUB monthly_entertainment;
    RUB monthly_health;
    RUB monthly_sport;
    RUB monthly_communications;
    RUB monthly_gadgets;
    RUB monthly_hobbies;
    Home house;
    Health health;
    RUB dream_stash;
    RUB dream_car_price;
    RUB emergency_fund;

    // personal
    Computer gaming_pc;
    Computer work_laptop;
    Computer home_server;

    Skills skills;
    Business business;
    InsurancePolicy life_insurance;
    RUB annual_income;

    Profession career_path[20];
    int career_stage;
    RUB total_education_cost;
    RUB total_tech_cost;
};

Female Kate;
Male Henry;

// rand gen
bool random_event(float probability) {
    return (rand() / (float)RAND_MAX) < probability;
}


RUB calculate_insurance_premium(InsuranceType type, RUB insured_value, int age, bool has_history) {
    float base_rate = 0.0;
    switch (type) {
        case INSURANCE_BASIC: base_rate = 0.02; break;
        case INSURANCE_EXTENDED: base_rate = 0.05; break;
        case INSURANCE_PREMIUM: base_rate = 0.08; break;
        default: return 0;
    }

    float age_factor = 1.0 + (age / 100.0);
    float history_factor = has_history ? 0.9 : 1.2;

    return insured_value * base_rate * age_factor * history_factor;
}


void take_credit_if_needed(Bank& bank, RUB needed_amount) {
    if (needed_amount <= 0) return;

    if (bank.account >= needed_amount) {
        bank.account -= needed_amount;
    } else {
        RUB credit_needed = needed_amount - bank.account;
        if (credit_needed <= bank.credit_limit - bank.credit) {
            bank.credit += credit_needed;
            bank.account = 0;
            printf("Credit amount: %lld RUB under %.1f%%\n",
                   credit_needed, bank.credit_rate);
        } else {
            printf("DONT HAVE CREDIT LIMIT!!!\n");
        }
    }
}


RUB process_insurance_claim(InsurancePolicy& insurance, RUB damage, const char* event_type) {
    if (!insurance.is_active) return 0;

    RUB coverage = 0;

    if (strcmp(event_type, "accident") == 0 && insurance.accident_coverage > 0) {
        coverage = damage * insurance.accident_coverage;
    } else if (strcmp(event_type, "health") == 0 && insurance.health_coverage > 0) {
        coverage = damage * insurance.health_coverage;
    } else if (strcmp(event_type, "property") == 0 && insurance.property_coverage > 0) {
        coverage = damage * insurance.property_coverage;
    } else if (strcmp(event_type, "business") == 0 && insurance.business_coverage > 0) {
        coverage = damage * insurance.business_coverage;
    } else if (strcmp(event_type, "tech") == 0 && insurance.tech_coverage > 0) {
        coverage = damage * insurance.tech_coverage;
    }

    if (coverage > insurance.deductible) {
        coverage -= insurance.deductible;
    } else {
        coverage = 0;
    }

    if (coverage > insurance.coverage_limit) {
        coverage = insurance.coverage_limit;
    }

    if (coverage > 0) {
        printf("Insurance coverage: %lld RUB\n", coverage);
        insurance.years_active++;
    }

    return coverage;
}


void Kate_init_computers() {
    // personal PC
    Kate.personal_pc.is_personal = true;
    Kate.personal_pc.purchase_price = 80000;
    Kate.personal_pc.current_value = 80000;
    Kate.personal_pc.purchase_year = 2025;
    Kate.personal_pc.age = 1;
    Kate.personal_pc.performance = 75;
    Kate.personal_pc.needs_upgrade = false;
    Kate.personal_pc.is_working = true;
    Kate.personal_pc.upgrade_cost = 0;
    Kate.personal_pc.cpu_power = 70;
    Kate.personal_pc.ram = 16;
    Kate.personal_pc.storage = 512;
    Kate.personal_pc.has_gpu = false;

    // Laptop
    Kate.laptop.is_personal = true;
    Kate.laptop.purchase_price = 65000;
    Kate.laptop.current_value = 65000;
    Kate.laptop.purchase_year = 2026;
    Kate.laptop.age = 0;
    Kate.laptop.performance = 70;
    Kate.laptop.needs_upgrade = false;
    Kate.laptop.is_working = true;
    Kate.laptop.upgrade_cost = 0;
    Kate.laptop.cpu_power = 60;
    Kate.laptop.ram = 8;
    Kate.laptop.storage = 256;
    Kate.laptop.has_gpu = false;

    // Work PC (if working from home)
    Kate.work_pc.is_personal = true;
    Kate.work_pc.purchase_price = 0;  // not purchased yet
    Kate.work_pc.current_value = 0;
    Kate.work_pc.purchase_year = 0;
    Kate.work_pc.age = 0;
    Kate.work_pc.performance = 0;
    Kate.work_pc.needs_upgrade = false;
    Kate.work_pc.is_working = false;
    Kate.work_pc.upgrade_cost = 0;

    Kate.total_tech_cost = 145000; // personal_pc + laptop
}


void Henry_init_computers() {
    Henry.gaming_pc.is_personal = true;
    Henry.gaming_pc.purchase_price = 150000;
    Henry.gaming_pc.current_value = 150000;
    Henry.gaming_pc.purchase_year = 2025;
    Henry.gaming_pc.age = 1;
    Henry.gaming_pc.performance = 95;
    Henry.gaming_pc.needs_upgrade = false;
    Henry.gaming_pc.is_working = true;
    Henry.gaming_pc.upgrade_cost = 0;
    Henry.gaming_pc.cpu_power = 95;
    Henry.gaming_pc.ram = 32;
    Henry.gaming_pc.storage = 2000;
    Henry.gaming_pc.has_gpu = true;


    Henry.work_laptop.is_personal = true;
    Henry.work_laptop.purchase_price = 90000;
    Henry.work_laptop.current_value = 90000;
    Henry.work_laptop.purchase_year = 2026;
    Henry.work_laptop.age = 0;
    Henry.work_laptop.performance = 80;
    Henry.work_laptop.needs_upgrade = false;
    Henry.work_laptop.is_working = true;
    Henry.work_laptop.upgrade_cost = 0;
    Henry.work_laptop.cpu_power = 80;
    Henry.work_laptop.ram = 16;
    Henry.work_laptop.storage = 1000;
    Henry.work_laptop.has_gpu = true;


    Henry.home_server.is_personal = true;
    Henry.home_server.purchase_price = 45000;
    Henry.home_server.current_value = 45000;
    Henry.home_server.purchase_year = 2026;
    Henry.home_server.age = 0;
    Henry.home_server.performance = 50;
    Henry.home_server.needs_upgrade = false;
    Henry.home_server.is_working = true;
    Henry.home_server.upgrade_cost = 0;
    Henry.home_server.cpu_power = 40;
    Henry.home_server.ram = 8;
    Henry.home_server.storage = 4000;
    Henry.home_server.has_gpu = false;

    Henry.total_tech_cost = 285000;
}


void process_health_events_with_insurance(Female& person, int month, int year) {
    float sick_probability = 0.05;
    if (month >= 10 || month <= 3) sick_probability = 0.12;

    if (random_event(sick_probability)) {
        RUB sickness_cost = 5000 + rand() % 20000;
        printf("Kate is sick, she needs money: %lld RUB\n", sickness_cost);

        RUB insurance_coverage = process_insurance_claim(
            person.health.health_insurance, sickness_cost, "health");

        RUB remaining = sickness_cost - insurance_coverage;

        if (remaining > 0) {
            if (person.emergency_fund >= remaining) {
                person.emergency_fund -= remaining;
            } else {
                take_credit_if_needed(person.tbank, remaining - person.emergency_fund);
                person.emergency_fund = 0;
            }
        }
    }

    if (person.health.monthly_sport > 0 && random_event(0.02)) {
        RUB injury_cost = 10000 + rand() % 30000;
        printf("Kates sports injury, she needs money: %lld RUB\n", injury_cost);

        RUB insurance_coverage = process_insurance_claim(
            person.health.health_insurance, injury_cost, "health");

        RUB remaining = injury_cost - insurance_coverage;

        if (remaining > 0) {
            if (person.emergency_fund >= remaining) {
                person.emergency_fund -= remaining;
            } else {
                take_credit_if_needed(person.tbank, remaining - person.emergency_fund);
                person.emergency_fund = 0;
            }
        }
    }

    if (random_event(0.08)) {
        RUB dental_cost = person.health.dental * (0.5 + (rand() % 100) / 100.0);
        printf("Kates dantist: %lld RUB\n", dental_cost);

        if (person.emergency_fund >= dental_cost) {
            person.emergency_fund -= dental_cost;
        } else {
            person.tbank.account -= dental_cost;
        }
    }

    if (month == 5 && random_event(0.7)) {
        printf("Kates dispanserizatsiya: %lld RUB\n", person.health.annual_checkup);
        if (person.emergency_fund >= person.health.annual_checkup) {
            person.emergency_fund -= person.health.annual_checkup;
        } else {
            person.tbank.account -= person.health.annual_checkup;
        }
    }
}

void process_health_events_with_insurance(Male& person, int month, int year) {
    float sick_probability = 0.04;
    if (month >= 10 || month <= 3) sick_probability = 0.1;

    if (random_event(sick_probability)) {
        RUB sickness_cost = 3000 + rand() % 25000;
        printf("Henry is sick, he needs money: %lld RUB\n", sickness_cost);

        RUB insurance_coverage = process_insurance_claim(
            person.health.health_insurance, sickness_cost, "health");

        RUB remaining = sickness_cost - insurance_coverage;

        if (remaining > 0) {
            if (person.emergency_fund >= remaining) {
                person.emergency_fund -= remaining;
            } else {
                take_credit_if_needed(person.sber, remaining - person.emergency_fund);
                person.emergency_fund = 0;
            }
        }
    }

    if (person.monthly_sport > 0 && random_event(0.03)) {
        RUB injury_cost = 10000 + rand() % 40000;
        printf("Henrys sport injury, he needs money: %lld RUB\n", injury_cost);

        RUB insurance_coverage = process_insurance_claim(
            person.health.health_insurance, injury_cost, "health");

        RUB remaining = injury_cost - insurance_coverage;
        if (remaining > 0) {
            if (person.emergency_fund >= remaining) {
                person.emergency_fund -= remaining;
            } else {
                person.sber.account -= remaining;
            }
        }
    }
}


void process_car_events_with_insurance(Car& car, Bank& bank, RUB& emergency_fund,
                                       const char* owner, InsurancePolicy& life_insurance) {
    car.age++;

    float breakdown_prob = 0.01 + (car.age * 0.02);
    if (breakdown_prob > 0.3) breakdown_prob = 0.3;

    if (random_event(breakdown_prob)) {
        RUB repair_cost = 5000 + (rand() % 50000) * (1 + car.age / 5);
        printf("%s: car is broken, money for repair %lld RUB\n", owner, repair_cost);

        if (emergency_fund >= repair_cost) {
            emergency_fund -= repair_cost;
        } else {
            take_credit_if_needed(bank, repair_cost - emergency_fund);
            emergency_fund = 0;
        }

        if (random_event(0.3)) {
            car.is_working = false;
            printf("  %s: car is repairing\n", owner);
        }
    }

    if (random_event(0.005)) {
        RUB accident_cost = 20000 + rand() % 100000;
        printf("  %s: accident, cost %lld RUB\n", owner, accident_cost);

        RUB insurance_coverage = process_insurance_claim(
            car.casco, accident_cost, "accident");

        if (random_event(0.3)) {
            RUB health_damage = 10000 + rand() % 50000;
            printf("Health damage in car accident: %lld RUB\n", health_damage);

            RUB health_coverage = process_insurance_claim(
                life_insurance, health_damage, "health");

            RUB total_coverage = insurance_coverage + health_coverage;
            RUB remaining = accident_cost + health_damage - total_coverage;

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


void process_home_events_with_insurance(Home& home, Bank& bank, RUB& emergency_fund,
                                        const char* owner) {
    float emergency_prob = 0.005;

    if (random_event(emergency_prob)) {
        RUB repair_cost = 15000 + rand() % 100000;
        printf("  %s: home accident, cost %lld RUB\n", owner, repair_cost);

        RUB insurance_coverage = process_insurance_claim(
            home.property_insurance, repair_cost, "property");

        RUB remaining = repair_cost - insurance_coverage;

        if (remaining > 0) {
            if (emergency_fund >= remaining) {
                emergency_fund -= remaining;
            } else {
                take_credit_if_needed(bank, remaining - emergency_fund);
                emergency_fund = 0;
            }
        }
    }

    if (random_event(0.002)) {
        RUB theft_cost = 30000 + rand() % 200000;
        printf("  %s: theft cost %lld RUB\n", owner, theft_cost);

        RUB insurance_coverage = process_insurance_claim(
            home.property_insurance, theft_cost, "property");

        RUB remaining = theft_cost - insurance_coverage;
        if (remaining > 0) {
            if (emergency_fund >= remaining) {
                emergency_fund -= remaining;
            } else {
                bank.account -= remaining;
            }
        }
    }

    if (random_event(0.03)) {
        RUB appliance_cost = home.appliances * (0.5 + (rand() % 100) / 100.0);
        printf("  %s: home tech replacement/maintenance %lld RUB\n", owner, appliance_cost);

        if (emergency_fund >= appliance_cost) {
            emergency_fund -= appliance_cost;
        } else {
            bank.account -= appliance_cost;
        }
    }
}


void process_force_majeure(Female& person, int month, int year) {
    if (random_event(0.1)) {
        RUB impulse_buy = 3000 + rand() % 30000;
        printf("Kate: impulse buy %lld RUB\n", impulse_buy);
        person.tbank.account -= impulse_buy;
    }

    if (random_event(0.02)) {
        RUB help_amount = 10000 + rand() % 50000;
        printf("Kate: money help %lld RUB\n", help_amount);

        if (person.emergency_fund >= help_amount) {
            person.emergency_fund -= help_amount;
        } else {
            person.tbank.account -= help_amount;
        }
    }

    if (random_event(0.005)) {
        RUB loss_cost = 5000 + rand() % 40000;
        printf("  Kate: theft, loss %lld RUB\n", loss_cost);
        if (person.emergency_fund >= loss_cost) {
            person.emergency_fund -= loss_cost;
        } else {
            person.tbank.account -= loss_cost;
        }
    }

    if (random_event(0.03)) {
        RUB fine = 500 + rand() % 5000;
        printf("  Kate: fine %lld RUB\n", fine);
        person.tbank.account -= fine;
    }
}

void process_force_majeure(Male& person, int month, int year) {
    if (random_event(0.12)) {
        RUB impulse_buy = 5000 + rand() % 50000;
        printf("  Henry: impulse buy %lld RUB\n", impulse_buy);
        person.sber.account -= impulse_buy;
    }

    if (random_event(0.015)) {
        RUB help_amount = 15000 + rand() % 100000;
        printf("  Henry: money help %lld RUB\n", help_amount);

        if (person.emergency_fund >= help_amount) {
            person.emergency_fund -= help_amount;
        } else {
            person.sber.account -= help_amount;
        }
    }

    if (random_event(0.007)) {
        RUB loss_cost = 10000 + rand() % 100000;
        printf("  Henry: theft, loss %lld RUB\n", loss_cost);
        if (person.emergency_fund >= loss_cost) {
            person.emergency_fund -= loss_cost;
        } else {
            person.sber.account -= loss_cost;
        }
    }

    if (random_event(0.04)) {
        RUB fine = 1000 + rand() % 15000;
        printf("  Henry: fine %lld RUB\n", fine);
        person.sber.account -= fine;
    }
}


void Kate_monthly_processing(int month, int year) {
    Kate.tbank.account -= Kate.monthly_food;
    Kate.tbank.account -= Kate.monthly_clothing;
    Kate.tbank.account -= Kate.monthly_entertainment;
    Kate.tbank.account -= Kate.monthly_health;
    Kate.tbank.account -= Kate.monthly_transport;
    Kate.tbank.account -= Kate.monthly_communications;
    Kate.tbank.account -= Kate.monthly_misc;
    Kate.tbank.account -= Kate.monthly_beauty;
    Kate.tbank.account -= Kate.monthly_gifts;

    if (Kate.matiz.is_working) {
        Kate.tbank.account -= Kate.matiz.monthly_fuel;
        Kate.tbank.account -= Kate.matiz.parking;
    }

    Kate.tbank.account -= Kate.flat.monthly_utilities;

    if (Kate.health.chronic_disease) {
        Kate.tbank.account -= Kate.health.medicines;
    }

    Kate.tbank.account -= Kate.health.monthly_sport;
}


void Henry_monthly_processing(int month, int year) {
    Henry.sber.account -= Henry.monthly_food;
    Henry.sber.account -= Henry.monthly_clothing;
    Henry.sber.account -= Henry.monthly_entertainment;
    Henry.sber.account -= Henry.monthly_health;
    Henry.sber.account -= Henry.monthly_communications;
    Henry.sber.account -= Henry.monthly_gadgets;
    Henry.sber.account -= Henry.monthly_hobbies;

    if (Henry.volga.is_working) {
        Henry.sber.account -= Henry.volga.monthly_fuel;
        Henry.sber.account -= Henry.volga.parking;
    }

    Henry.sber.account -= Henry.house.monthly_utilities;

    if (Henry.health.chronic_disease) {
        Henry.sber.account -= Henry.health.medicines;
    }

    Henry.sber.account -= Henry.monthly_sport;
}


void Kate_deposit(int month, int year) {
    Kate.tbank.deposit += Kate.tbank.deposit * (Kate.tbank.interest / 12.0 / 100.0);

    RUB transfer = Kate.tbank.account * 0.8;
    Kate.tbank.deposit += transfer;
    Kate.tbank.account -= transfer;

    if (month == 12) {
        Kate.tbank.interest = BANK_RATE - 1.0;
    }
}

void Henry_deposit(int month, int year) {
    Henry.sber.deposit += Henry.sber.deposit * (Henry.sber.interest / 12.0 / 100.0);

    RUB transfer = Henry.sber.account * 0.85;
    Henry.sber.deposit += transfer;
    Henry.sber.account -= transfer;

    if (month == 12) {
        Henry.sber.interest = BANK_RATE - 0.5;
    }
}


void Henry_dream_savings(int month, int year) {
    if (Henry.sber.account > 150'000) {
        RUB saving = Henry.sber.account * 0.15;
        Henry.dream_stash += saving;
        Henry.sber.account -= saving;
    }

    if (Henry.dream_stash >= Henry.dream_car_price) {
        Henry.volga.price = Henry.dream_car_price;
        Henry.dream_stash -= Henry.dream_car_price;
        Henry.dream_car_price = Henry.dream_car_price * 1.5;
    }
}


void professional_development(Female& person, int year) {
    if (year % 3 == 0 && random_event(0.6)) {
        RUB education_cost = 50000 + rand() % 150000;
        printf("  Kate education cost %lld RUB\n", education_cost);

        if (person.emergency_fund >= education_cost) {
            person.emergency_fund -= education_cost;
        } else {
            person.tbank.account -= education_cost;
        }

        person.total_education_cost += education_cost;
        person.skills.education_cost += education_cost;

        person.skills.technical += 5 + rand() % 10;
        person.skills.managerial += 2 + rand() % 5;
        if (person.skills.technical > 100) person.skills.technical = 100;
        if (person.skills.managerial > 100) person.skills.managerial = 100;

        person.skills.certifications++;

        printf("Skills upgrades: tech %.1f, management %.1f\n",
               person.skills.technical, person.skills.managerial);
    }

    if (random_event(0.2)) {
        RUB cert_cost = 20000 + rand() % 60000;
        printf("  Kate gets certification, value %lld RUB\n", cert_cost);
        if (person.emergency_fund >= cert_cost) {
            person.emergency_fund -= cert_cost;
        } else {
            person.tbank.account -= cert_cost;
        }
        person.skills.certifications++;
        person.skills.technical += 3;
    }
}

void professional_development(Male& person, int year) {
    if (year % 2 == 0 && random_event(0.7)) {
        RUB education_cost = 70000 + rand() % 200000;
        printf("  Henry educates, value %lld RUB\n", education_cost);

        if (person.emergency_fund >= education_cost) {
            person.emergency_fund -= education_cost;
        } else {
            person.sber.account -= education_cost;
        }

        person.total_education_cost += education_cost;
        person.skills.education_cost += education_cost;

        person.skills.managerial += 8 + rand() % 12;
        person.skills.financial += 5 + rand() % 8;
        person.skills.communication += 3 + rand() % 5;

        if (person.skills.managerial > 100) person.skills.managerial = 100;
        if (person.skills.financial > 100) person.skills.financial = 100;
        if (person.skills.communication > 100) person.skills.communication = 100;

        person.skills.certifications++;

        printf("  Skills upgrades: management %.1f, financial %.1f\n",
               person.skills.managerial, person.skills.financial);
    }
}


void career_progression(Female& person, int year) {
    float promotion_chance = (person.skills.technical / 200.0) +
                             (person.skills.managerial / 200.0) +
                             (person.skills.certifications * 0.02);

    if (random_event(promotion_chance / 10)) {
        Profession old_prof = person.skills.current_profession;
        Profession new_prof = old_prof;

        switch (old_prof) {
            case PROFESSION_SPECIALIST:
                if (person.skills.technical > 70) new_prof = PROFESSION_SENIOR;
                break;
            case PROFESSION_SENIOR:
                if (person.skills.managerial > 50) new_prof = PROFESSION_TEAM_LEAD;
                break;
            case PROFESSION_TEAM_LEAD:
                if (person.skills.managerial > 70) new_prof = PROFESSION_MANAGER;
                break;
            case PROFESSION_MANAGER:
                if (person.skills.financial > 60) new_prof = PROFESSION_DIRECTOR;
                break;
            default:
                break;
        }

        if (new_prof != old_prof) {
            person.skills.current_profession = new_prof;
            person.career_path[person.career_stage++] = new_prof;

            float salary_multiplier = 1.0;
            switch (new_prof) {
                case PROFESSION_SENIOR: salary_multiplier = 1.3; break;
                case PROFESSION_TEAM_LEAD: salary_multiplier = 1.5; break;
                case PROFESSION_MANAGER: salary_multiplier = 1.8; break;
                case PROFESSION_DIRECTOR: salary_multiplier = 2.2; break;
                default: salary_multiplier = 1.2;
            }

            person.salary *= salary_multiplier;
            printf("  CONGRATS! Kate rises up to %d, salary %lld RUB\n",
                   new_prof, person.salary);
        }
    }

    if (random_event(0.15)) {
        RUB new_salary = person.salary * (1.1 + (rand() % 30) / 100.0);
        if (new_salary > person.salary * 1.2) {
            printf("  Kate gets offer with salary %lld RUB\n", new_salary);
            if (random_event(0.5)) {
                person.salary = new_salary;
                printf("  Kate changes work! New salary %lld RUB\n", person.salary);
            }
        }
    }
}

void career_progression(Male& person, int year) {
    float promotion_chance = (person.skills.managerial / 150.0) +
                             (person.skills.financial / 200.0) +
                             (person.skills.communication / 150.0) +
                             (person.skills.certifications * 0.03);

    if (random_event(promotion_chance / 8)) {
        Profession old_prof = person.skills.current_profession;
        Profession new_prof = old_prof;

        switch (old_prof) {
            case PROFESSION_SENIOR:
                if (person.skills.managerial > 60) new_prof = PROFESSION_TEAM_LEAD;
                break;
            case PROFESSION_TEAM_LEAD:
                if (person.skills.managerial > 75) new_prof = PROFESSION_MANAGER;
                break;
            case PROFESSION_MANAGER:
                if (person.skills.financial > 70) new_prof = PROFESSION_DIRECTOR;
                break;
            case PROFESSION_DIRECTOR:
                if (person.skills.financial > 80 && person.emergency_fund > 1000000)
                    new_prof = PROFESSION_ENTREPRENEUR;
                break;
            default:
                break;
        }

        if (new_prof != old_prof) {
            person.skills.current_profession = new_prof;
            person.career_path[person.career_stage++] = new_prof;

            float salary_multiplier = 1.0;
            switch (new_prof) {
                case PROFESSION_TEAM_LEAD: salary_multiplier = 1.4; break;
                case PROFESSION_MANAGER: salary_multiplier = 1.7; break;
                case PROFESSION_DIRECTOR: salary_multiplier = 2.0; break;
                case PROFESSION_ENTREPRENEUR: salary_multiplier = 2.5; break;
                default: salary_multiplier = 1.3;
            }

            person.salary *= salary_multiplier;
            printf("  CONGRATS! Henry rises up to %d level, new salary %lld RUB\n",
                   new_prof, person.salary);
        }
    }

    if (random_event(0.2)) {
        RUB new_salary = person.salary * (1.15 + (rand() % 40) / 100.0);
        if (new_salary > person.salary * 1.25) {
            printf("  Henry gets offer with salary %lld RUB\n", new_salary);
            if (random_event(0.6)) {
                person.salary = new_salary;
                printf("  Henry changes job! New salary %lld RUB\n", person.salary);
            }
        }
    }
}


void Kate_salary(int month, int year) {
    RUB gross_salary = Kate.salary;

    if (month == 12) {
        gross_salary += Kate.salary;
    }

    gross_salary += Kate.skills.certifications * 5000;

    RUB tax = gross_salary * INCOME_TAX;
    RUB net_salary = gross_salary - tax;

    Kate.tbank.account += net_salary;
    Kate.annual_income += gross_salary;
    Kate.tbank.tax_paid += tax;

    Kate.net_salary = net_salary;
}


void Henry_salary(int month, int year) {
    RUB gross_salary = Henry.salary;

    if (month == 12) {
        gross_salary += Henry.salary;
    }

    gross_salary += Henry.skills.certifications * 8000;
    gross_salary += Henry.skills.managerial * 500;

    RUB tax = gross_salary * INCOME_TAX;
    RUB net_salary = gross_salary - tax;

    Henry.sber.account += net_salary;
    Henry.annual_income += gross_salary;
    Henry.sber.tax_paid += tax;

    Henry.net_salary = net_salary;
}


void calculate_monthly_taxes(int month, int year) {
    if (month == 11) {
        RUB kate_property_tax = Kate.flat.cadastral_value * PROPERTY_TAX_RATE;
        RUB henry_property_tax = Henry.house.cadastral_value * PROPERTY_TAX_RATE;

        printf(" Property-tax: Kate %lld RUB, Henry %lld RUB\n",
               kate_property_tax, henry_property_tax);

        Kate.tbank.tax_debt += kate_property_tax;
        Henry.sber.tax_debt += henry_property_tax;
    }

    if (month == 10) {
        printf("Car-tax: Kate %lld RUB, Henry %lld RUB\n",
               Kate.matiz.tax_rate, Henry.volga.tax_rate);

        Kate.tbank.tax_debt += Kate.matiz.tax_rate;
        Henry.sber.tax_debt += Henry.volga.tax_rate;
    }
}

void pay_taxes(int month, int year) {
    if (month == 12) {
        if (Kate.tbank.tax_debt > 0) {
            printf("Taxes paiment Kate: %lld RUB\n", Kate.tbank.tax_debt);

            if (Kate.tbank.account >= Kate.tbank.tax_debt) {
                Kate.tbank.account -= Kate.tbank.tax_debt;
                Kate.tbank.tax_paid += Kate.tbank.tax_debt;
                Kate.tbank.tax_debt = 0;
            } else {
                RUB nedolm = Kate.tbank.tax_debt - Kate.tbank.account;
                RUB peni = nedolm * 0.1;
                printf("Taxes deficite! Peni rises %lld RUB\n", peni);
                Kate.tbank.tax_debt = nedolm + peni;
                Kate.tbank.account = 0;
            }
        }

        if (Henry.sber.tax_debt > 0) {
            printf("Taxes paiment Henry: %lld RUB\n", Henry.sber.tax_debt);

            if (Henry.sber.account >= Henry.sber.tax_debt) {
                Henry.sber.account -= Henry.sber.tax_debt;
                Henry.sber.tax_paid += Henry.sber.tax_debt;
                Henry.sber.tax_debt = 0;
            } else {
                RUB nedolm = Henry.sber.tax_debt - Henry.sber.account;
                RUB peni = nedolm * 0.1;
                printf(" Taxes deficite! Peni rises %lld RUB\n", peni);
                Henry.sber.tax_debt = nedolm + peni;
                Henry.sber.account = 0;
            }
        }
    }
}


void pay_insurance_premiums(int month, int year) {
    if (month == 1) {
        printf("  Isurance pays:\n");

        RUB kate_total = Kate.life_insurance.annual_premium +
                        Kate.matiz.casco.annual_premium +
                        Kate.flat.property_insurance.annual_premium +
                        Kate.health.health_insurance.annual_premium;

        if (Kate.business.is_active) {
            kate_total += Kate.business.business_insurance.annual_premium;
        }

        Kate.tbank.account -= kate_total;
        printf("    Kate: all %lld RUB\n", kate_total);

        RUB henry_total = Henry.life_insurance.annual_premium +
                         Henry.volga.casco.annual_premium +
                         Henry.house.property_insurance.annual_premium +
                         Henry.health.health_insurance.annual_premium;

        if (Henry.business.is_active) {
            henry_total += Henry.business.business_insurance.annual_premium;
        }

        Henry.sber.account -= henry_total;
        printf("    Henry: all %lld RUB\n", henry_total);
    }
}


void apply_inflation(int year) {
    if (year % 2 == 0) {
        float inflation_factor = 1.0 + (INFLATION / 100.0) * 2;
        Kate.salary = Kate.salary * inflation_factor;
        Henry.salary = Henry.salary * inflation_factor;
    }
}


void update_economic_params(int year) {
    if (year % 2 == 0) {
        float rate_change = 1.0 + USD_GROWTH * 2;
        Kate.tbank.usd_rate *= rate_change;
        Henry.sber.usd_rate *= rate_change;
    }
}


void update_insurance(int year) {
    if (year % 2 == 0) {
        Kate.life_insurance.annual_premium = calculate_insurance_premium(
            Kate.life_insurance.type, 2000000, year - 2026,
            Kate.life_insurance.years_active > 3);

        Kate.matiz.casco.annual_premium = calculate_insurance_premium(
            Kate.matiz.casco.type, Kate.matiz.price, Kate.matiz.age,
            Kate.matiz.casco.years_active > 3);

        Kate.flat.property_insurance.annual_premium = calculate_insurance_premium(
            Kate.flat.property_insurance.type, Kate.flat.price, 0,
            Kate.flat.property_insurance.years_active > 3);

        Henry.life_insurance.annual_premium = calculate_insurance_premium(
            Henry.life_insurance.type, 5000000, year - 2026,
            Henry.life_insurance.years_active > 3);

        Henry.volga.casco.annual_premium = calculate_insurance_premium(
            Henry.volga.casco.type, Henry.volga.price, Henry.volga.age,
            Henry.volga.casco.years_active > 3);

        Henry.house.property_insurance.annual_premium = calculate_insurance_premium(
            Henry.house.property_insurance.type, Henry.house.price, 0,
            Henry.house.property_insurance.years_active > 3);

        if (Kate.business.is_active) {
            Kate.business.business_insurance.annual_premium =
                Kate.business.current_value * 0.03;
        }

        if (Henry.business.is_active) {
            Henry.business.business_insurance.annual_premium =
                Henry.business.current_value * 0.05;
        }
    }
}


void process_tech_aging(Computer& pc, const char* owner, const char* device_name) {
    if (pc.purchase_price == 0) return;

    pc.age++;

    float performance_loss = 5 + (rand() % 10);
    pc.performance *= (1 - performance_loss / 100);
    if (pc.performance < 10) pc.performance = 10;

    pc.current_value = pc.current_value * (1 - TECH_DEPRECIATION);
    if (pc.current_value < pc.purchase_price * 0.1) {
        pc.current_value = pc.purchase_price * 0.1;
    }

    if (pc.age > 3 && pc.performance < 50 && !pc.needs_upgrade) {
        pc.needs_upgrade = true;
        pc.upgrade_cost = pc.purchase_price * PC_UPGRADE_COST;
        printf("  %s: %s needs upgrade (age %d years, perfomance %.0f%%). Upgrade cost %lld RUB\n",
               owner, device_name, pc.age, pc.performance, pc.upgrade_cost);
    }

    if (random_event(0.05 + pc.age * 0.02)) {
        pc.is_working = false;
        RUB repair_cost = pc.purchase_price * (0.1 + (rand() % 30) / 100.0);
        printf("  %s: %s broken! Repair cost %lld RUB\n",
               owner, device_name, repair_cost);
    }
}

void process_all_tech_aging() {
    process_tech_aging(Kate.personal_pc, "Kate", "personal PC");
    process_tech_aging(Kate.laptop, "Kate", "laptop");
    if (Kate.work_pc.purchase_price > 0) {
        process_tech_aging(Kate.work_pc, "Kate", "working PC");
    }

    process_tech_aging(Henry.gaming_pc, "Henry", "gaming PC");
    process_tech_aging(Henry.work_laptop, "Henry", "working laptop");
    process_tech_aging(Henry.home_server, "Henry", "home server");
}

// Покупка нового компьютера
void buy_new_computer(Female& person, const char* type, RUB budget) {
    RUB price = 0;
    Computer new_pc;
    new_pc.is_personal = true;
    new_pc.purchase_year = 2026 + person.skills.experience;
    new_pc.age = 0;
    new_pc.is_working = true;
    new_pc.needs_upgrade = false;

    if (strcmp(type, "work_pc") == 0) {
        price = 70000 + rand() % 50000;
        new_pc.purchase_price = price;
        new_pc.current_value = price;
        new_pc.performance = 70 + rand() % 20;
        new_pc.cpu_power = 70;
        new_pc.ram = 16;
        new_pc.storage = 512;
        new_pc.has_gpu = false;

        person.work_pc = new_pc;
        printf("  Kate new working PC cost %lld RUB\n", price);
    }
    else if (strcmp(type, "upgrade_personal") == 0) {
        price = person.personal_pc.upgrade_cost;
        if (price > 0) {
            person.personal_pc.performance += 30;
            if (person.personal_pc.performance > 100) person.personal_pc.performance = 100;
            person.personal_pc.current_value += price * 0.8;
            person.personal_pc.needs_upgrade = false;
            person.personal_pc.upgrade_cost = 0;
            person.personal_pc.age = 0;
            printf("  Kates personal PC upgrade cost %lld RUB\n", price);
        }
    }

    if (price > 0) {
        if (person.emergency_fund >= price) {
            person.emergency_fund -= price;
        } else {
            person.tbank.account -= price;
        }
        person.total_tech_cost += price;
    }
}

void buy_new_computer(Male& person, const char* type, RUB budget) {
    RUB price = 0;

    if (strcmp(type, "new_gaming") == 0) {
        price = 150000 + rand() % 150000;
        Computer new_pc;
        new_pc.is_personal = true;
        new_pc.purchase_price = price;
        new_pc.current_value = price;
        new_pc.purchase_year = 2026 + person.skills.experience;
        new_pc.age = 0;
        new_pc.performance = 90 + rand() % 10;
        new_pc.needs_upgrade = false;
        new_pc.is_working = true;
        new_pc.upgrade_cost = 0;
        new_pc.cpu_power = 95;
        new_pc.ram = 32;
        new_pc.storage = 2000;
        new_pc.has_gpu = true;

        person.gaming_pc = new_pc;
        printf("Henrys new gaming PC cost %lld RUB\n", price);
    }
    else if (strcmp(type, "upgrade_server") == 0) {
        price = 20000 + rand() % 40000;
        person.home_server.performance += 20;
        person.home_server.current_value += price * 0.7;
        person.home_server.storage += 2000;
        printf("  Henrys home server upgrade cost: %lld RUB\n", price);
    }

    if (price > 0) {
        if (person.emergency_fund >= price) {
            person.emergency_fund -= price;
        } else {
            person.sber.account -= price;
        }
        person.total_tech_cost += price;
    }
}


void handle_tech_breakdown(Female& person) {
    if (!person.personal_pc.is_working && person.personal_pc.purchase_price > 0) {
        RUB repair_cost = person.personal_pc.purchase_price * 0.2;
        printf("  Repair personal PC Kate: %lld RUB\n", repair_cost);

        RUB insurance_coverage = process_insurance_claim(
            person.life_insurance, repair_cost, "tech");

        RUB remaining = repair_cost - insurance_coverage;

        if (person.emergency_fund >= remaining) {
            person.emergency_fund -= remaining;
            person.personal_pc.is_working = true;
        } else if (person.tbank.account >= remaining) {
            person.tbank.account -= remaining;
            person.personal_pc.is_working = true;
        } else {
            printf("Not enough money! PC is not working\n");
        }
    }

    if (!person.laptop.is_working && person.laptop.purchase_price > 0) {
        RUB repair_cost = person.laptop.purchase_price * 0.15;
        printf("  Repair laptop Kate: %lld RUB\n", repair_cost);

        RUB insurance_coverage = process_insurance_claim(
            person.life_insurance, repair_cost, "tech");

        RUB remaining = repair_cost - insurance_coverage;

        if (person.emergency_fund >= remaining) {
            person.emergency_fund -= remaining;
            person.laptop.is_working = true;
        } else if (person.tbank.account >= remaining) {
            person.tbank.account -= remaining;
            person.laptop.is_working = true;
        }
    }
}


void handle_tech_breakdown(Male& person) {
    if (!person.gaming_pc.is_working && person.gaming_pc.purchase_price > 0) {
        RUB repair_cost = person.gaming_pc.purchase_price * 0.25;
        printf("  Repair gaming PC Henry: %lld RUB\n", repair_cost);

        RUB insurance_coverage = process_insurance_claim(
            person.life_insurance, repair_cost, "tech");

        RUB remaining = repair_cost - insurance_coverage;

        if (person.emergency_fund >= remaining) {
            person.emergency_fund -= remaining;
            person.gaming_pc.is_working = true;
        } else if (person.sber.account >= remaining) {
            person.sber.account -= remaining;
            person.gaming_pc.is_working = true;
        }
    }

    if (!person.work_laptop.is_working && person.work_laptop.purchase_price > 0) {
        RUB repair_cost = person.work_laptop.purchase_price * 0.2;
        printf("  Repair working laptop Henry: %lld RUB\n", repair_cost);

        RUB insurance_coverage = process_insurance_claim(
            person.life_insurance, repair_cost, "tech");

        RUB remaining = repair_cost - insurance_coverage;

        if (person.emergency_fund >= remaining) {
            person.emergency_fund -= remaining;
            person.work_laptop.is_working = true;
        } else if (person.sber.account >= remaining) {
            person.sber.account -= remaining;
            person.work_laptop.is_working = true;
        }
    }
}


void init_business_computers(Business& business, int count) {
    business.computer_count = count;
    business.monthly_internet = 5000;
    business.monthly_software = 3000 * count;
    business.monthly_cloud = 10000;

    for (int i = 0; i < count; i++) {
        business.office_computers[i].is_personal = false;
        business.office_computers[i].purchase_price = 50000 + rand() % 30000;
        business.office_computers[i].current_value = business.office_computers[i].purchase_price;
        business.office_computers[i].purchase_year = 2026;
        business.office_computers[i].age = 0;
        business.office_computers[i].performance = 70 + rand() % 20;
        business.office_computers[i].needs_upgrade = false;
        business.office_computers[i].is_working = true;
        business.office_computers[i].quantity = 1;

        business.office_computers[i].cpu_power = 60 + rand() % 30;
        business.office_computers[i].ram = 8 + (rand() % 3) * 8;
        business.office_computers[i].storage = 256 + (rand() % 3) * 256;
        business.office_computers[i].has_gpu = (rand() % 100) < 20;
    }

    RUB total = 0;
    for (int i = 0; i < count; i++) {
        total += business.office_computers[i].purchase_price;
    }
    printf("  Buying %d comps for office on %lld RUB\n", count, total);
}


void manage_business_computers(Business& business, int month, int year) {
    if (!business.is_active) return;
    if (business.computer_count == 0) return;

    business.monthly_expenses += business.monthly_internet;
    business.monthly_expenses += business.monthly_software;
    business.monthly_expenses += business.monthly_cloud;

    if (month == 1) {
        RUB software_update = business.monthly_software * 12 * 0.3;
        business.account -= software_update;
        printf("  business: software update for %lld RUB\n", software_update);
    }

    if (month == 12) {
        RUB total_depreciation = 0;
        int need_replacement = 0;

        for (int i = 0; i < business.computer_count; i++) {
            business.office_computers[i].age++;

            RUB old_value = business.office_computers[i].current_value;
            business.office_computers[i].current_value *= (1 - TECH_DEPRECIATION);
            total_depreciation += old_value - business.office_computers[i].current_value;

            if (business.office_computers[i].age > 3 &&
                business.office_computers[i].performance < 40) {
                need_replacement++;
            }

            if (random_event(0.1) && business.office_computers[i].is_working) {
                business.office_computers[i].is_working = false;
                RUB repair = business.office_computers[i].purchase_price * 0.1;
                business.account -= repair;
                printf("  business: comp repair %d for %lld RUB\n", i+1, repair);
            }
        }

        printf("  business: maintenance all computers %lld RUB\n", total_depreciation);

        if (need_replacement > 0 && business.account > 500000) {
            RUB replacement_cost = need_replacement * 60000;
            printf("  business: replacement %d overages comps for %lld RUB\n",
                   need_replacement, replacement_cost);

            if (business.account >= replacement_cost) {
                business.account -= replacement_cost;

                for (int i = 0; i < business.computer_count && need_replacement > 0; i++) {
                    if (business.office_computers[i].age > 3) {
                        business.office_computers[i].purchase_price = 60000;
                        business.office_computers[i].current_value = 60000;
                        business.office_computers[i].age = 0;
                        business.office_computers[i].performance = 80;
                        business.office_computers[i].is_working = true;
                        need_replacement--;
                    }
                }
            }
        }
    }
}


bool open_business(Female& person, int year) {
    if (person.business.is_active) return false;

    if (person.emergency_fund < 500000) return false;
    if (person.skills.financial < 40) return false;

    float business_chance = (person.skills.financial / 200.0) +
                           (person.skills.managerial / 200.0) +
                           (year - 2026) / 100.0;

    if (random_event(business_chance / 20)) {
        printf("\n=== Kate founds a company! ===\n");

        int business_type = rand() % 3;
        RUB investment = 300000 + rand() % 1000000;

        person.business.is_active = true;
        person.business.type = (BusinessType)business_type;
        person.business.initial_investment = investment;
        person.business.current_value = investment;
        person.business.success_probability = 0.5 + (person.skills.managerial / 200.0);
        person.business.risk_factor = 0.3;
        person.business.employees_count = 1 + rand() % 5;
        person.business.has_office = random_event(0.5);

        if (business_type == BUSINESS_IT || business_type == BUSINESS_ONLINE) {
            init_business_computers(person.business, person.business.employees_count + 1);
            person.business.monthly_cloud = 15000;
        } else {
            init_business_computers(person.business, person.business.employees_count / 2 + 1);
        }

        person.business.monthly_revenue = investment * 0.1;
        person.business.monthly_expenses = investment * 0.07;
        person.business.monthly_profit = person.business.monthly_revenue -
                                        person.business.monthly_expenses;

        if (person.emergency_fund >= investment) {
            person.emergency_fund -= investment;
            person.business.account = investment * 0.3;
        } else {
            RUB need_credit = investment - person.emergency_fund;
            person.business.credit = need_credit;
            person.business.account = person.emergency_fund + need_credit * 0.3;
            person.emergency_fund = 0;
        }

        printf("  business type: %d\n", business_type);
        printf("  Investments: %lld RUB\n", investment);
        printf("  Success probability: %.1f%%\n", person.business.success_probability * 100);
        printf("  emploees: %d\n", person.business.employees_count);
        printf("  Computers: %d\n", person.business.computer_count);

        person.business.business_insurance.type = INSURANCE_EXTENDED;
        person.business.business_insurance.annual_premium = investment * 0.03;
        person.business.business_insurance.deductible = 20000;
        person.business.business_insurance.coverage_limit = investment;
        person.business.business_insurance.business_coverage = 0.7;
        person.business.business_insurance.tech_coverage = 0.6;
        person.business.business_insurance.is_active = true;
        person.business.business_insurance.years_active = 0;

        return true;
    }
    return false;
}


bool open_business(Male& person, int year) {
    if (person.business.is_active) return false;

    if (person.emergency_fund < 800000) return false;
    if (person.skills.financial < 50) return false;

    float business_chance = (person.skills.financial / 150.0) +
                           (person.skills.managerial / 150.0) +
                           (year - 2026) / 80.0;

    if (random_event(business_chance / 15)) {
        printf("\n=== Henry founds business! ===\n");

        int business_type = 1 + rand() % 5;
        RUB investment = 500000 + rand() % 2000000;

        person.business.is_active = true;
        person.business.type = (BusinessType)business_type;
        person.business.initial_investment = investment;
        person.business.current_value = investment;
        person.business.success_probability = 0.6 + (person.skills.managerial / 150.0);
        person.business.risk_factor = 0.4;
        person.business.employees_count = 2 + rand() % 10;
        person.business.has_office = true;
        person.business.office_rent = 50000 + rand() % 150000;

        if (business_type == BUSINESS_IT) {
            init_business_computers(person.business, person.business.employees_count + 2);
            person.business.monthly_cloud = 20000;
        } else {
            init_business_computers(person.business, person.business.employees_count / 2 + 1);
        }

        person.business.monthly_revenue = investment * 0.15;
        person.business.monthly_expenses = investment * 0.1 + person.business.office_rent;
        person.business.monthly_profit = person.business.monthly_revenue -
                                        person.business.monthly_expenses;

        if (person.emergency_fund >= investment) {
            person.emergency_fund -= investment;
            person.business.account = investment * 0.4;
        } else {
            RUB need_credit = investment - person.emergency_fund;
            person.business.credit = need_credit;
            person.business.account = person.emergency_fund + need_credit * 0.4;
            person.emergency_fund = 0;
        }

        printf("  business type: %d\n", business_type);
        printf("  Investments: %lld RUB\n", investment);
        printf("  emploees: %d\n", person.business.employees_count);
        printf("  Computers: %d\n", person.business.computer_count);
        printf("  Office rent: %lld RUB/month\n", person.business.office_rent);

        person.business.business_insurance.type = INSURANCE_PREMIUM;
        person.business.business_insurance.annual_premium = investment * 0.05;
        person.business.business_insurance.deductible = 15000;
        person.business.business_insurance.coverage_limit = investment * 1.5;
        person.business.business_insurance.business_coverage = 0.85;
        person.business.business_insurance.tech_coverage = 0.8;
        person.business.business_insurance.is_active = true;
        person.business.business_insurance.years_active = 0;

        return true;
    }
    return false;
}


void manage_business(Female& person, int month, int year) {
    if (!person.business.is_active) return;

    person.business.years_active++;

    person.business.account += person.business.monthly_profit;

    manage_business_computers(person.business, month, year);

    RUB business_tax = person.business.monthly_profit * BUSINESS_TAX;
    if (business_tax < 0) business_tax = 0;

    person.business.tax_debt += business_tax;
    person.business.tax_paid += business_tax;
    person.business.account -= business_tax;

    if (random_event(0.02)) {
        RUB tech_loss = person.business.current_value * 0.05;
        printf("  business Kate: server failure, loss %lld RUB\n", tech_loss);

        RUB insurance_coverage = process_insurance_claim(
            person.business.business_insurance, tech_loss, "tech");

        tech_loss -= insurance_coverage;
        person.business.account -= tech_loss;
    }

    float risk_roll = random_event(person.business.risk_factor / 4);

    if (risk_roll) {
        int risk_type = rand() % 5;
        RUB loss = 0;

        switch (risk_type) {
            case 0:
                loss = person.business.monthly_revenue * 0.3;
                person.business.monthly_revenue *= 0.9;
                printf("  business Kate: best client loss, money loss %lld RUB\n", loss);
                break;
            case 1:
                loss = person.business.current_value * 0.1;
                printf("  business Kate: tech broken, loss %lld RUB\n", loss);
                break;
            case 2:
                loss = person.business.payroll * 0.5;
                printf("  business Kate: problems with emploees, loss %lld RUB\n", loss);
                break;
            case 3:
                loss = person.business.tax_debt * 0.2;
                printf("  business Kate: tax audit, fine %lld RUB\n", loss);
                break;
            case 4:
                loss = person.business.monthly_revenue * 0.2;
                person.business.monthly_profit *= 0.85;
                printf("  business Kate: economical risks, loss %lld RUB\n", loss);
                break;
        }

        RUB insurance_coverage = process_insurance_claim(
            person.business.business_insurance, loss, "business");

        loss -= insurance_coverage;
        person.business.account -= loss;

        if (person.business.account < -person.business.current_value * 0.5) {
            printf("Business Kate Banckrupted!\n");
        }
    }

    if (random_event(person.business.success_probability / 10)) {
        RUB growth = person.business.current_value * 0.1;
        person.business.current_value += growth;
        person.business.monthly_revenue *= 1.05;
        printf("Kates business rises! Value +%lld RUB\n", growth);
    }

    if (person.business.account > person.business.current_value * 0.3 &&
        person.business.years_active > 2 &&
        random_event(0.1)) {

        RUB expansion_cost = person.business.current_value * 0.5;
        printf("Kates business rises! Invest expansion %lld RUB\n", expansion_cost);

        if (person.business.account >= expansion_cost) {
            person.business.account -= expansion_cost;
            person.business.current_value += expansion_cost * 1.2;
            person.business.employees_count += 2;
            person.business.monthly_revenue *= 1.3;

            if (person.business.employees_count > person.business.computer_count) {
                person.business.computer_count = person.business.employees_count;
            }
        }
    }
}


void manage_business(Male& person, int month, int year) {
    if (!person.business.is_active) return;

    person.business.years_active++;

    person.business.account += person.business.monthly_profit;

    manage_business_computers(person.business, month, year);

    RUB business_tax = (person.business.monthly_revenue -
                        person.business.monthly_expenses) * BUSINESS_TAX_PROFIT;
    if (business_tax < 0) business_tax = 0;

    person.business.tax_debt += business_tax;
    person.business.tax_paid += business_tax;
    person.business.account -= business_tax;

    if (random_event(0.02)) {
        RUB tech_loss = person.business.current_value * 0.05;
        printf("  Henry's business: server failure, loss %lld RUB\n", tech_loss);

        RUB insurance_coverage = process_insurance_claim(
            person.business.business_insurance, tech_loss, "tech");

        tech_loss -= insurance_coverage;
        person.business.account -= tech_loss;
    }

    float risk_roll = random_event(person.business.risk_factor / 3);

    if (risk_roll) {
        int risk_type = rand() % 6;
        RUB loss = 0;

        switch (risk_type) {
            case 0:
                loss = person.business.current_value * 0.2;
                printf("  Henry's business: illegal action, loss %lld RUB\n", loss);
                break;
            case 1:
                loss = person.business.monthly_expenses * 2;
                printf("  Henry's business: supply failure, loss %lld RUB\n", loss);
                break;
            case 2:
                loss = person.business.account * 0.3;
                printf("  Henry's business: cyberatack, money loss %lld RUB\n", loss);
                break;
            case 3:
                loss = person.business.payroll * 3;
                printf("  Henry's business: best emploee loss, money loss %lld RUB\n", loss);
                break;
            case 4:
                loss = person.business.monthly_revenue * 0.4;
                person.business.monthly_revenue *= 0.8;
                printf("  Henry's business: concurention, loss %lld RUB\n", loss);
                break;
            case 5:
                loss = person.business.current_value * 0.15;
                person.business.monthly_profit *= 0.7;
                printf("  Henry's business: CRISIS, loss %lld RUB\n", loss);
                break;
        }

        RUB insurance_coverage = process_insurance_claim(
            person.business.business_insurance, loss, "business");

        loss -= insurance_coverage;
        person.business.account -= loss;
    }

    if (random_event(person.business.success_probability / 8)) {
        RUB growth = person.business.current_value * 0.15;
        person.business.current_value += growth;
        person.business.monthly_revenue *= 1.1;
        person.business.employees_count += 1;

        if (person.business.employees_count > person.business.computer_count) {
            int new_computers = person.business.employees_count - person.business.computer_count;
            printf("  Henry's business: buying %d new comps\n", new_computers);
            person.business.computer_count = person.business.employees_count;
        }

        printf("  Henry's business rises! Value +%lld RUB\n", growth);
    }

    if (person.business.account > person.business.current_value * 0.4 &&
        person.business.years_active > 3 &&
        random_event(0.15)) {

        RUB new_direction_cost = person.business.current_value * 0.4;
        printf("  Henry new direction explored! Investments %lld RUB\n",
               new_direction_cost);

        if (person.business.account >= new_direction_cost) {
            person.business.account -= new_direction_cost;
            person.business.current_value += new_direction_cost * 1.5;
            person.business.monthly_revenue *= 1.4;
            person.business.risk_factor *= 1.1;

            person.business.computer_count += person.business.employees_count / 2;
        }
    }
}

void maybe_sell_business(Female& person, int year) {
    if (!person.business.is_active) return;
    if (person.business.years_active < 3) return;

    if (person.business.current_value > person.business.initial_investment * 2 &&
        random_event(0.1)) {

        RUB sell_price = person.business.current_value * (0.8 + (rand() % 40) / 100.0);
        printf("\n=== Kate sells business for %lld RUB! ===\n", sell_price);

        person.emergency_fund += sell_price * 0.7;
        person.tbank.account += person.business.account;

        person.business.is_active = false;
        person.business.current_value = 0;

        person.skills.current_profession = PROFESSION_DIRECTOR;
        person.salary = 300000;
    }
}

void maybe_sell_business(Male& person, int year) {
    if (!person.business.is_active) return;
    if (person.business.years_active < 4) return;

    if (person.business.current_value > person.business.initial_investment * 3 &&
        random_event(0.15)) {

        RUB sell_price = person.business.current_value * (0.9 + (rand() % 30) / 100.0);
        printf("\n=== Henry sells business for %lld RUB! ===\n", sell_price);

        person.emergency_fund += sell_price * 0.65;
        person.sber.account += person.business.account;
        person.dream_car_price = sell_price * 0.5;

        person.business.is_active = false;
        person.business.current_value = 0;

        person.skills.current_profession = PROFESSION_ENTREPRENEUR;
    }
}


void simulation() {
    srand(time(NULL));

    int month = 2;
    int year = 2026;
    int years_passed = 0;

    while (years_passed < 40) {
        if (month == 1) {
            professional_development(Kate, year);
            professional_development(Henry, year);
            career_progression(Kate, year);
            career_progression(Henry, year);

            if (!Kate.business.is_active) open_business(Kate, year);
            if (!Henry.business.is_active) open_business(Henry, year);

            process_all_tech_aging();
        }

        Kate_salary(month, year);
        Henry_salary(month, year);

        if (Kate.business.is_active) {
            manage_business(Kate, month, year);
        }
        if (Henry.business.is_active) {
            manage_business(Henry, month, year);
        }

        if (month == 12) {
            maybe_sell_business(Kate, year);
            maybe_sell_business(Henry, year);
        }

        Kate_monthly_processing(month, year);
        Henry_monthly_processing(month, year);

        process_health_events_with_insurance(Kate, month, year);
        process_health_events_with_insurance(Henry, month, year);

        process_force_majeure(Kate, month, year);
        process_force_majeure(Henry, month, year);

        if (month == 1 || month == 6) {
            process_car_events_with_insurance(Kate.matiz, Kate.tbank, Kate.emergency_fund,
                                             "Kate", Kate.life_insurance);
            process_car_events_with_insurance(Henry.volga, Henry.sber, Henry.emergency_fund,
                                             "Henry", Henry.life_insurance);
        }

        if (random_event(0.3)) {
            process_home_events_with_insurance(Kate.flat, Kate.tbank, Kate.emergency_fund, "Kate");
            process_home_events_with_insurance(Henry.house, Henry.sber, Henry.emergency_fund, "Henry");
        }

        handle_tech_breakdown(Kate);
        handle_tech_breakdown(Henry);

        if (Kate.work_pc.purchase_price == 0 && Kate.skills.current_profession >= PROFESSION_SENIOR) {
            buy_new_computer(Kate, "work_pc", Kate.emergency_fund);
        }

        if (Kate.personal_pc.needs_upgrade && Kate.emergency_fund > Kate.personal_pc.upgrade_cost) {
            buy_new_computer(Kate, "upgrade_personal", Kate.emergency_fund);
        }

        if (Henry.gaming_pc.age > 4 && random_event(0.3) && Henry.emergency_fund > 150000) {
            buy_new_computer(Henry, "new_gaming", Henry.emergency_fund);
        }

        calculate_monthly_taxes(month, year);

        if (month == 1) {
            pay_insurance_premiums(month, year);
            Kate.tbank.account -= Kate.matiz.insurance;
            Henry.sber.account -= Henry.volga.insurance;
        }

        if (month == 3) {
            Kate.tbank.account -= Kate.flat.annual_insurance;
        }

        if (month == 6) {
            Henry.sber.account -= Henry.house.annual_insurance;
            Kate.tbank.account -= Kate.matiz.maintenance;
            Henry.sber.account -= Henry.volga.maintenance;
        }

        if (month == 8) {
            Kate.tbank.account -= Kate.flat.renovation;
            Henry.sber.account -= Henry.house.renovation;
        }

        if (month == 9) {
            Henry.sber.account -= Henry.monthly_education;
        }

        if (month != 9 && month != 12 && random_event(0.2)) {
            Henry.sber.account -= Henry.monthly_education * 0.3;
        }

        pay_taxes(month, year);

        Kate_deposit(month, year);
        Henry_deposit(month, year);
        Henry_dream_savings(month, year);

        if (Kate.tbank.account > 100000 && Kate.emergency_fund < 500000) {
            RUB transfer = Kate.tbank.account * 0.1;
            Kate.emergency_fund += transfer;
            Kate.tbank.account -= transfer;
        }

        if (Henry.sber.account > 150000 && Henry.emergency_fund < 700000) {
            RUB transfer = Henry.sber.account * 0.1;
            Henry.emergency_fund += transfer;
            Henry.sber.account -= transfer;
        }

        month++;
        if (month == 13) {
            month = 1;
            year++;
            years_passed++;

            Kate.skills.experience++;
            Henry.skills.experience++;

            apply_inflation(year);
            update_economic_params(year);
            update_insurance(year);

            Kate.annual_income = 0;
            Henry.annual_income = 0;

            Kate.matiz.is_working = true;
            Henry.volga.is_working = true;

            if (years_passed % 5 == 0) {
                printf("\n--- Progress: %d years simulation ---\n", years_passed);
                printf("tech Kate: PC %.0f%% (%d years), Laptop %.0f%% (%d years)\n",
                       Kate.personal_pc.performance, Kate.personal_pc.age,
                       Kate.laptop.performance, Kate.laptop.age);
                printf("tech Henry: Gaming %.0f%% (%d years), Laptop %.0f%% (%d years)\n",
                       Henry.gaming_pc.performance, Henry.gaming_pc.age,
                       Henry.work_laptop.performance, Henry.work_laptop.age);

                if (Kate.business.is_active) {
                    printf("Business Kate: value %lld RUB, comps %d\n",
                           Kate.business.current_value, Kate.business.computer_count);
                }
                if (Henry.business.is_active) {
                    printf("Henry's business: value %lld RUB, comps %d\n",
                           Henry.business.current_value, Henry.business.computer_count);
                }
            }
        }
    }
}

void print_results() {
    for (int i = 0; i < Kate.career_stage; i++) {
        printf("Stage %d: Level %d\n", i+1, Kate.career_path[i]);
    }
    printf("Education cost: %lld RUB\n", Kate.total_education_cost);
    printf("Tech cost: %lld RUB\n", Kate.total_tech_cost);
    printf("Certifications amount %d\n", Kate.skills.certifications);
    printf("Skills: Tech %.1f, Management %.1f, Financial %.1f\n\n",
           Kate.skills.technical, Kate.skills.managerial, Kate.skills.financial);

    printf("Kates tech:\n");
    printf("  personal PC: %lld RUB (age %d years, perfomance %.0f%%)\n",
           Kate.personal_pc.current_value, Kate.personal_pc.age, Kate.personal_pc.performance);
    printf("  Laptop: %lld RUB (age %d years, perfomance %.0f%%)\n",
           Kate.laptop.current_value, Kate.laptop.age, Kate.laptop.performance);
    if (Kate.work_pc.purchase_price > 0) {
        printf("  Work PC: %lld RUB (age %d years, perfomance %.0f%%)\n",
               Kate.work_pc.current_value, Kate.work_pc.age, Kate.work_pc.performance);
    }
    printf("\n");

    printf("Henrys career:\n");
    for (int i = 0; i < Henry.career_stage; i++) {
        printf("Stage %d: Level %d\n", i+1, Henry.career_path[i]);
    }
    printf("Education cost: %lld RUB\n", Henry.total_education_cost);
    printf("Tech cost: %lld RUB\n", Henry.total_tech_cost);
    printf("Certifications amount: %d\n", Henry.skills.certifications);
    printf("Skills: Tech %.1f, Management %.1f, Financial %.1f\n\n",
           Henry.skills.technical, Henry.skills.managerial, Henry.skills.financial);

    printf("Henrys techs:\n");
    printf("Gaming PC: %lld RUB (age %d years, perfomance %.0f%%)\n",
           Henry.gaming_pc.current_value, Henry.gaming_pc.age, Henry.gaming_pc.performance);
    printf("Working laptop: %lld RUB (age %d years, perfomance %.0f%%)\n",
           Henry.work_laptop.current_value, Henry.work_laptop.age, Henry.work_laptop.performance);
    printf("Home server: %lld RUB (age %d years, perfomance %.0f%%)\n",
           Henry.home_server.current_value, Henry.home_server.age, Henry.home_server.performance);
    printf("\n");

    if (Kate.business.is_active) {
        printf("Kate's business:\n");
        printf("Type: %d\n", Kate.business.type);
        printf("Years: %d\n", Kate.business.years_active);
        printf("Investments: %lld RUB\n", Kate.business.initial_investment);
        printf("Value: %lld RUB\n", Kate.business.current_value);
        printf("Profit: %lld RUB\n", Kate.business.monthly_profit);
        printf("Employers: %d\n", Kate.business.employees_count);
        printf("Amount of comps: %d\n", Kate.business.computer_count);
        printf("Taxes paid: %lld RUB\n", Kate.business.tax_paid);
        printf("Business capital: %lld RUB\n\n", Kate.business.account);
    }

    if (Henry.business.is_active) {
        printf("Henry's business:\n");
        printf("Type: %d\n", Henry.business.type);
        printf("Years: %d\n", Henry.business.years_active);
        printf("Investments: %lld RUB\n", Henry.business.initial_investment);
        printf("Value: %lld RUB\n", Henry.business.current_value);
        printf("Profit: %lld RUB\n", Henry.business.monthly_profit);
        printf("Employers: %d\n", Henry.business.employees_count);
        printf("Amount of comps: %d\n", Henry.business.computer_count);
        printf("Taxes paid: %lld RUB\n", Henry.business.tax_paid);
        printf("Business capital: %lld RUB\n\n", Henry.business.account);
    }

    printf("TAXES(personal):\n");
    printf("Kate: %lld RUB\n", Kate.tbank.tax_paid);
    printf("Henry: %lld RUB\n", Henry.sber.tax_paid);
    printf("NDFL: %lld RUB\n\n", Kate.tbank.tax_paid + Henry.sber.tax_paid);

    printf("ALL CAPITAL:\n");

    RUB kate_tech_value = Kate.personal_pc.current_value +
                          Kate.laptop.current_value +
                          Kate.work_pc.current_value;

    RUB kate_business_value = 0;
    if (Kate.business.is_active) {
        kate_business_value = Kate.business.current_value + Kate.business.account;

        for (int i = 0; i < Kate.business.computer_count; i++) {
            kate_business_value += Kate.business.office_computers[i].current_value;
        }
    }

    RUB kate_total = Kate.tbank.account + Kate.tbank.deposit +
                     Kate.flat.price + Kate.emergency_fund +
                     Kate.tbank.usd_account * Kate.tbank.usd_rate +
                     kate_tech_value + kate_business_value -
                     Kate.tbank.credit;

    RUB henry_tech_value = Henry.gaming_pc.current_value +
                           Henry.work_laptop.current_value +
                           Henry.home_server.current_value;

    RUB henry_business_value = 0;
    if (Henry.business.is_active) {
        henry_business_value = Henry.business.current_value + Henry.business.account;

        for (int i = 0; i < Henry.business.computer_count; i++) {
            henry_business_value += Henry.business.office_computers[i].current_value;
        }
    }

    RUB henry_total = Henry.sber.account + Henry.sber.deposit +
                      Henry.house.price + Henry.emergency_fund +
                      Henry.dream_stash +
                      Henry.sber.usd_account * Henry.sber.usd_rate +
                      henry_tech_value + henry_business_value -
                      Henry.sber.credit;

    printf("Kate: %lld RUB\n", kate_total);
    printf("tech: %lld RUB\n", kate_tech_value);
    printf("Henry: %lld RUB\n", henry_total);
    printf("tech: %lld RUB\n", henry_tech_value);
    printf("ALL: %lld RUB\n", kate_total + henry_total);
}


void Kate_init() {
    // bank
    Kate.tbank.account = 50'000;
    Kate.tbank.deposit = 850'000;
    Kate.tbank.interest = 14.5;
    Kate.tbank.credit = 0;
    Kate.tbank.credit_limit = 500'000;
    Kate.tbank.credit_rate = 21.0;
    Kate.tbank.tax_debt = 0;
    Kate.tbank.tax_paid = 0;
    Kate.tbank.stocks = 0;
    Kate.tbank.bonds = 0;
    Kate.tbank.crypto = 0;

    Kate.tbank.usd_account = 1500;
    Kate.tbank.usd_rate = 92.5;

    // incoming money
    Kate.salary = 145'000;
    Kate.net_salary = Kate.salary * (1 - INCOME_TAX);
    Kate.annual_income = 0;

    // per month
    Kate.monthly_food = 25'000;
    Kate.monthly_clothing = 8'000;
    Kate.monthly_entertainment = 12'000;
    Kate.monthly_health = 5'000;
    Kate.monthly_transport = 3'000;
    Kate.monthly_communications = 3'500;
    Kate.monthly_misc = 7'000;
    Kate.monthly_beauty = 6'000;
    Kate.monthly_gifts = 3'000;

    // car
    Kate.matiz.price = 280'000;
    Kate.matiz.monthly_fuel = 8'000;
    Kate.matiz.maintenance = 25'000;
    Kate.matiz.insurance = 18'000;
    Kate.matiz.parking = 5'000;
    Kate.matiz.emergency_repair = 0;
    Kate.matiz.age = 3;
    Kate.matiz.is_working = true;
    Kate.matiz.engine_power = 85;
    Kate.matiz.tax_rate = Kate.matiz.engine_power * TRANSPORT_TAX_BASE;

    // health
    Kate.health.monthly_sport = 4'000;
    Kate.health.annual_checkup = 15'000;
    Kate.health.emergency = 0;
    Kate.health.dental = 25'000;
    Kate.health.medicines = 2'000;
    Kate.health.chronic_disease = false;

    // home
    Kate.flat.price = 7'500'000;
    Kate.flat.cadastral_value = 8'200'000;
    Kate.flat.monthly_utilities = 6'500;
    Kate.flat.annual_insurance = 4'500;
    Kate.flat.renovation = 30'000;
    Kate.flat.emergency_repair = 0;
    Kate.flat.appliances = 20'000;

    // golden backup
    Kate.emergency_fund = 200'000;

    // comps
    Kate_init_computers();

    // skills
    Kate.skills.technical = 65;
    Kate.skills.managerial = 40;
    Kate.skills.financial = 50;
    Kate.skills.communication = 70;
    Kate.skills.experience = 3;
    Kate.skills.current_profession = PROFESSION_SPECIALIST;
    Kate.skills.certifications = 1;
    Kate.skills.education_cost = 0;
    Kate.career_stage = 0;
    Kate.career_path[Kate.career_stage++] = PROFESSION_SPECIALIST;
    Kate.total_education_cost = 0;

    // business
    Kate.business.is_active = false;
    Kate.business.computer_count = 0;

    // insurance
    Kate.life_insurance.type = INSURANCE_EXTENDED;
    Kate.life_insurance.annual_premium = 25000;
    Kate.life_insurance.deductible = 10000;
    Kate.life_insurance.coverage_limit = 2'000'000;
    Kate.life_insurance.accident_coverage = 0.9;
    Kate.life_insurance.health_coverage = 0.8;
    Kate.life_insurance.property_coverage = 0.0;
    Kate.life_insurance.business_coverage = 0.0;
    Kate.life_insurance.tech_coverage = 0.5;
    Kate.life_insurance.is_active = true;
    Kate.life_insurance.years_active = 0;

    Kate.matiz.casco.type = INSURANCE_EXTENDED;
    Kate.matiz.casco.annual_premium = calculate_insurance_premium(
        INSURANCE_EXTENDED, Kate.matiz.price, Kate.matiz.age, true);
    Kate.matiz.casco.deductible = 15000;
    Kate.matiz.casco.coverage_limit = Kate.matiz.price;
    Kate.matiz.casco.accident_coverage = 0.85;
    Kate.matiz.casco.health_coverage = 0.0;
    Kate.matiz.casco.property_coverage = 0.0;
    Kate.matiz.casco.business_coverage = 0.0;
    Kate.matiz.casco.tech_coverage = 0.0;
    Kate.matiz.casco.is_active = true;
    Kate.matiz.casco.years_active = 0;

    Kate.flat.property_insurance.type = INSURANCE_EXTENDED;
    Kate.flat.property_insurance.annual_premium = calculate_insurance_premium(
        INSURANCE_EXTENDED, Kate.flat.price, 0, true);
    Kate.flat.property_insurance.deductible = 20000;
    Kate.flat.property_insurance.coverage_limit = Kate.flat.price;
    Kate.flat.property_insurance.accident_coverage = 0.0;
    Kate.flat.property_insurance.health_coverage = 0.0;
    Kate.flat.property_insurance.property_coverage = 0.9;
    Kate.flat.property_insurance.business_coverage = 0.0;
    Kate.flat.property_insurance.tech_coverage = 0.0;
    Kate.flat.property_insurance.is_active = true;
    Kate.flat.property_insurance.years_active = 0;

    Kate.health.health_insurance.type = INSURANCE_PREMIUM;
    Kate.health.health_insurance.annual_premium = 45000;
    Kate.health.health_insurance.deductible = 0;
    Kate.health.health_insurance.coverage_limit = 1'000'000;
    Kate.health.health_insurance.accident_coverage = 0.0;
    Kate.health.health_insurance.health_coverage = 0.95;
    Kate.health.health_insurance.property_coverage = 0.0;
    Kate.health.health_insurance.business_coverage = 0.0;
    Kate.health.health_insurance.tech_coverage = 0.0;
    Kate.health.health_insurance.is_active = true;
    Kate.health.health_insurance.years_active = 0;
}


void Henry_init() {
    // bank
    Henry.sber.account = 75'000;
    Henry.sber.deposit = 1'800'000;
    Henry.sber.interest = 15.0;
    Henry.sber.credit = 0;
    Henry.sber.credit_limit = 800'000;
    Henry.sber.credit_rate = 20.0;
    Henry.sber.tax_debt = 0;
    Henry.sber.tax_paid = 0;
    Henry.sber.stocks = 0;
    Henry.sber.bonds = 0;
    Henry.sber.crypto = 0;

    Henry.sber.usd_account = 2500;
    Henry.sber.usd_rate = 92.5;

    // incoming money
    Henry.salary = 195'000;
    Henry.net_salary = Henry.salary * (1 - INCOME_TAX);
    Henry.annual_income = 0;

    // per month
    Henry.monthly_food = 30'000;
    Henry.monthly_education = 15'000;
    Henry.monthly_clothing = 6'000;
    Henry.monthly_entertainment = 10'000;
    Henry.monthly_health = 4'000;
    Henry.monthly_sport = 5'000;
    Henry.monthly_communications = 4'000;
    Henry.monthly_gadgets = 5'000;
    Henry.monthly_hobbies = 4'000;

    // Henry's car
    Henry.volga.price = 950'000;
    Henry.volga.monthly_fuel = 15'000;
    Henry.volga.maintenance = 45'000;
    Henry.volga.insurance = 45'000;
    Henry.volga.parking = 7'000;
    Henry.volga.emergency_repair = 0;
    Henry.volga.age = 2;
    Henry.volga.is_working = true;
    Henry.volga.engine_power = 150;
    Henry.volga.tax_rate = Henry.volga.engine_power * TRANSPORT_TAX_BASE;

    // health
    Henry.health.monthly_sport = 5'000;
    Henry.health.annual_checkup = 12'000;
    Henry.health.emergency = 0;
    Henry.health.dental = 20'000;
    Henry.health.medicines = 1'500;
    Henry.health.chronic_disease = false;

    // house
    Henry.house.price = 12'000'000;
    Henry.house.cadastral_value = 13'500'000;
    Henry.house.monthly_utilities = 12'000;
    Henry.house.annual_insurance = 10'000;
    Henry.house.renovation = 60'000;
    Henry.house.emergency_repair = 0;
    Henry.house.appliances = 30'000;

    // stash
    Henry.dream_stash = 0;
    Henry.dream_car_price = 4'500'000;
    Henry.emergency_fund = 300'000;

    // comps
    Henry_init_computers();

    // skills
    Henry.skills.technical = 45;
    Henry.skills.managerial = 75;
    Henry.skills.financial = 60;
    Henry.skills.communication = 80;
    Henry.skills.experience = 4;
    Henry.skills.current_profession = PROFESSION_SENIOR;
    Henry.skills.certifications = 2;
    Henry.skills.education_cost = 0;
    Henry.career_stage = 0;
    Henry.career_path[Henry.career_stage++] = PROFESSION_SENIOR;
    Henry.total_education_cost = 0;

    // business
    Henry.business.is_active = false;
    Henry.business.computer_count = 0;

    // insurance
    Henry.life_insurance.type = INSURANCE_PREMIUM;
    Henry.life_insurance.annual_premium = 40000;
    Henry.life_insurance.deductible = 5000;
    Henry.life_insurance.coverage_limit = 5'000'000;
    Henry.life_insurance.accident_coverage = 0.95;
    Henry.life_insurance.health_coverage = 0.9;
    Henry.life_insurance.property_coverage = 0.0;
    Henry.life_insurance.business_coverage = 0.0;
    Henry.life_insurance.tech_coverage = 0.6;
    Henry.life_insurance.is_active = true;
    Henry.life_insurance.years_active = 0;

    Henry.volga.casco.type = INSURANCE_PREMIUM;
    Henry.volga.casco.annual_premium = calculate_insurance_premium(
        INSURANCE_PREMIUM, Henry.volga.price, Henry.volga.age, true);
    Henry.volga.casco.deductible = 10000;
    Henry.volga.casco.coverage_limit = Henry.volga.price;
    Henry.volga.casco.accident_coverage = 0.95;
    Henry.volga.casco.health_coverage = 0.0;
    Henry.volga.casco.property_coverage = 0.0;
    Henry.volga.casco.business_coverage = 0.0;
    Henry.volga.casco.tech_coverage = 0.0;
    Henry.volga.casco.is_active = true;
    Henry.volga.casco.years_active = 0;

    Henry.house.property_insurance.type = INSURANCE_PREMIUM;
    Henry.house.property_insurance.annual_premium = calculate_insurance_premium(
        INSURANCE_PREMIUM, Henry.house.price, 0, true);
    Henry.house.property_insurance.deductible = 15000;
    Henry.house.property_insurance.coverage_limit = Henry.house.price;
    Henry.house.property_insurance.accident_coverage = 0.0;
    Henry.house.property_insurance.health_coverage = 0.0;
    Henry.house.property_insurance.property_coverage = 0.95;
    Henry.house.property_insurance.business_coverage = 0.0;
    Henry.house.property_insurance.tech_coverage = 0.0;
    Henry.house.property_insurance.is_active = true;
    Henry.house.property_insurance.years_active = 0;

    Henry.health.health_insurance.type = INSURANCE_EXTENDED;
    Henry.health.health_insurance.annual_premium = 35000;
    Henry.health.health_insurance.deductible = 5000;
    Henry.health.health_insurance.coverage_limit = 800'000;
    Henry.health.health_insurance.accident_coverage = 0.0;
    Henry.health.health_insurance.health_coverage = 0.85;
    Henry.health.health_insurance.property_coverage = 0.0;
    Henry.health.health_insurance.business_coverage = 0.0;
    Henry.health.health_insurance.tech_coverage = 0.0;
    Henry.health.health_insurance.is_active = true;
    Henry.health.health_insurance.years_active = 0;
}

int main() {
    freopen("output.txt", "w", stdout);
    Kate_init();
    Henry_init();

    simulation();

    print_results();

    return 0;
}
