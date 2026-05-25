#include <stdio.h>

using RUB = long long int;


struct Bank {
    RUB debit;
    RUB business;
    RUB deposit;
    double rate;
};

struct Business {
    bool open;
    RUB income;
    RUB expenses;
    int bad_months;
};

struct Career {
    int level;
    RUB growth;
    int stagnation;
};

struct Mental {
    int stress;
    int burnout;
};

struct Assets {
    RUB investments;
    
};

struct Health {
    int level;        
    RUB expenses;
};

struct CarFleet {
    RUB car_value;
    RUB maintenance;
    int age;
};

struct Credits {
    RUB debt;
    RUB payment;
};

struct Insurance {
    bool active;
    RUB monthly_payment;
    RUB coverage;
};

struct Social {
    int connections;
    int reputation;
};

struct Passive {
    RUB income;
    int stability;
};

struct Education {
    int level;
    bool studying;
    int yearly_spent;
};

struct Decisions {
    bool frugal_mode;
    bool agressive_risk_mode;
};

struct Repair {
    int condition;
    bool need_repair;
};

struct Utilities {
    RUB base_cost;
    int penni_level;
};

struct RentalProperty {
    bool owned;
    RUB price;
    RUB rent_income;
    int tenants_happiness;
};


struct Leisure {
    int happiness;       
    int fatigue;         
    RUB budget;          
};


struct Travel {
    int trips_done;
    int experience;
    bool traveling;
};


struct Hobby {
    int level;
    RUB income;
    int interest;
};

struct Person {
    RUB salary;

    RUB food;
    RUB transport;
    RUB clothing;
    RUB entertainment;
    RUB healthy;
    RUB rent;
    RUB hamster;
    RUB dog;

    RUB mortgage;
    RUB mortgage_payment;
    bool has_mortgage;

    RUB house_price;
    RUB initial_payment;

    struct Bank bank;
    struct Business biz;
    struct Career career;
    struct Mental mental;
    struct Assets assets;
    struct Credits credits;
    struct Insurance insurance;       
    struct Social social;
    struct Passive passive;
    struct Decisions decisions;
    struct CarFleet car;
    struct Repair repair;
    struct Utilities utilities;
    struct RentalProperty rental;
    struct Health health;
    struct Education edu;
    struct Leisure leisure;
    struct Travel travel;
    struct Hobby hobby;
};

Person Alice;
Person Peter;


bool smart_spend(RUB &acc, RUB &dep, RUB need) {
    // проверка хватает ли денег вообще
    if (acc + dep < need) {
        return false; 
    }

    // сначала списываем с карты
    if (acc >= need) {
        acc -= need;
        return true;
    }

    // если не хватает на карте — добираем с депозита
    RUB from_dep = need - acc;
    acc = 0;
    dep -= from_dep;

    return true;
}



void Alice_init() {
    Alice.salary = 120000;

    Alice.food = 20000;
    Alice.transport = 10000;
    Alice.clothing = 8000;
    Alice.entertainment = 7000;
    Alice.healthy = 5000;
    Alice.health.level = 80;
    Alice.health.expenses = 0;
    Alice.rent = 50000;
    Alice.hamster = 4000;
    Alice.edu.level = 0;
    Alice.edu.studying = false;

    Alice.bank = {0,0,0,14.0};
    Alice.biz.open = 0;
    Alice.biz.income = 0;
    Alice.biz.expenses = 0;
    Alice.biz.bad_months = 0;

    Alice.career = {1,0};
    Alice.mental = {20};
    Alice.assets = {0};
    Alice.credits = {0};

    Alice.has_mortgage = 0;

    
    Alice.insurance.active = false;
    Alice.insurance.monthly_payment = 0;
    Alice.insurance.coverage = 0;

    Alice.social.connections = 5;
    Alice.social.reputation = 5;

    Alice.passive.income = 0;
    Alice.passive.stability = 0;

    Peter.repair.condition = 75;
    Peter.repair.need_repair = false;

    Peter.utilities.base_cost = 10000;
    Peter.utilities.penni_level = 0;

    Peter.rental.owned = false;
    Peter.rental.price = 0;
    Peter.rental.rent_income = 0;
    Peter.rental.tenants_happiness = 50;

    Alice.leisure.happiness = 10;
    Alice.leisure.fatigue = 0;
    Alice.leisure.budget = 7000;

    Alice.travel.trips_done = 0;
    Alice.travel.experience = 0;
    Alice.travel.traveling = false;

    Alice.hobby.level = 0;
    Alice.hobby.income = 0;
    Alice.hobby.interest = 5;
}

void Peter_init() {
    Peter.salary = 150000;

    Peter.food = 25000;
    Peter.transport = 12000;
    Peter.clothing = 9000;
    Peter.entertainment = 9000;
    Peter.healthy = 6000;
    Peter.health.level = 80;
    Peter.health.expenses = 0;
    Peter.dog = 6000;
    Peter.edu.level = 0;
    Peter.edu.studying = false;

    Peter.bank = {0,0,2000000,14.0};

    Peter.house_price = 8000000;
    Peter.initial_payment = 2000000;

    Peter.mortgage = Peter.house_price - Peter.initial_payment;
    Peter.mortgage_payment = 50000;
    Peter.has_mortgage = 1;

    Peter.career = {2,0};
    Peter.mental = {15};
    Peter.assets = {0};
    Peter.credits = {0};

    Peter.biz.open = 0;
    Peter.biz.income = 0;
    Peter.biz.expenses = 0;
    Peter.biz.bad_months = 0;

    Peter.insurance.active = false;
    Peter.insurance.monthly_payment = 0;
    Peter.insurance.coverage = 0;

    Peter.social.connections = 8;
    Peter.social.reputation = 7;

    Peter.passive.income = 0;
    Peter.passive.stability = 0;

    Peter.repair.condition = 85;
    Peter.repair.need_repair = false;

    Peter.utilities.base_cost = 7000;
    Peter.utilities.penni_level = 0;

    Peter.rental.owned = false;
    Peter.rental.price = 0;
    Peter.rental.rent_income = 0;
    Peter.rental.tenants_happiness = 70;

    Peter.leisure.happiness = 10;
    Peter.leisure.fatigue = 0;
    Peter.leisure.budget = 7000;

    Peter.travel.trips_done = 0;
    Peter.travel.experience = 0;
    Peter.travel.traveling = false;

    Peter.hobby.level = 0;
    Peter.hobby.income = 0;
    Peter.hobby.interest = 5;
}


void alice_salary(const int month) {
    if (month == 1)
        Alice.salary = Alice.salary * 105 / 100;

    
    if (Alice.bank.deposit > 500000) {
        Alice.bank.deposit += Alice.salary * 0.3;
        Alice.bank.debit += Alice.salary * 0.7;
    } else {
        Alice.bank.debit += Alice.salary;
    }
}

void peter_salary(const int month) {
    if (month == 1)
        Peter.salary = Peter.salary * 105 / 100;

    Peter.bank.debit += Peter.salary;
}


void global_crisis(const int year) {
    if (year == 12) {
        Alice.salary *= 0.8;
        Peter.salary *= 0.85;

        Alice.assets.investments *= 0.7;
        Peter.assets.investments *= 0.75;
    }
}


void hyperinflation(const int year) {
    if (year == 10) {
        Alice.food *= 1.5;
        Alice.transport *= 1,5;
        Alice.rent *= 1.3;
        Alice.clothing *= 2;
        Alice.healthy *= 1,4;
        Alice.hamster *= 1,3;

        Peter.food *= 1.5;
        Peter.transport *= 1,5;
        Peter.clothing *= 3;
        Peter.healthy *= 1,5;
        Peter.dog *= 2;
    }
}



void alice_food(const int month) {
    if (month == 1) Alice.food = Alice.food * 106 / 100;

    RUB need = Alice.food;

    if (Alice.bank.deposit < 100000)
        need *= 0.7; // экономия

    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, need);

    if (!ok) {
        Alice.mental.stress += 5; // не смогла купить еду
    }
}


void alice_transport(const int month) {
    if (month == 1) Alice.transport = Alice.transport * 106 / 100;

    RUB need = Alice.transport;

    if (Alice.bank.deposit < 50000)
        need *= 0.5; // отказ от машины

    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, need);

    if (!ok) {
        Alice.mental.stress += 5; 
    }
}

void alice_normal_healthy(const int month) {
    if (month == 1) Alice.healthy = Alice.healthy * 106 / 100;

    RUB need = Alice.healthy;

    if (month == 11)
        need *= 2; // заболела

    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, need);

    if (!ok) {
        Alice.mental.stress += 5; 
    }
}


void alice_mentalyty_health(const int month) {
    Alice.health.level -= Alice.mental.stress / 20;

    if (Alice.health.level < 50) {
        RUB cost = 20000;
            if(month == 1) cost = cost * 106 / 100;
        smart_spend(Alice.bank.debit, Alice.bank.deposit, cost);

        Alice.health.level += 10;
    }

    if (Alice.health.level < 30) {
        Alice.salary *= 0.9;
    }
}


void alice_major_health_event(const int month, const int year) {
    if (year % 13 == 0) {
        RUB cost = 300000;
            if(month == 1) cost = cost * 106 / 100;
        bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, cost);

        if (ok) {
            Alice.health.level += 20;
        } else {
            Alice.health.level -= 20;
            Alice.mental.stress += 10;
        }
    }
}


void alice_clothing(const int month, const int year) {
    if (month == 1) Alice.clothing = Alice.clothing * 106 / 100;

    RUB need = Alice.clothing; 

    if (year % 2 == 0 && month == 8 );
        need *= 3; // порвалась одежда

    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, need);

    if (!ok) {
        Alice.mental.stress += 5; 
    }
}


void alice_hamster(const int month, const int year) {
    if (month == 1) Alice.hamster = Alice.hamster * 106 / 100;

    RUB need = Alice.hamster;
    

    if (year == 2 && month == 2); 
        need *= 6; // хомяк заболел

    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, need);

    if (!ok) {
        Alice.mental.stress += 5; 
    }
}


void alice_school_education_start(const int year) {
    if (!Alice.edu.studying && year == 4) {
        Alice.edu.studying = true;
    }
}


void alice_school_education_process(const int month) {
    if (!Alice.edu.studying) return;

    RUB cost = 20000;
        if(month == 1) cost = cost * 106 / 100;
    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, cost);

    if (ok) {
        Alice.edu.level++;
    } else {
        Alice.mental.stress += 3;
    }

    if (Alice.edu.level > 10) {
        Alice.edu.studying = false;
        Alice.social.reputation++;
    }
}


void alice_job_loss(const int year, const int month) {
    if (year == 7 && month == 3) {
        Alice.salary = 0;
        Alice.mental.stress += 30;
        Alice.career.stagnation += 6;
    }
}

void alice_job_search(const int month) {
    if (Alice.salary == 0) {
        Alice.career.stagnation--;

        if (Alice.career.stagnation <= 0) {
            Alice.salary = 100000 + Alice.career.level * 20000;
            Alice.mental.stress -= 20;
        }
    }
}


void alice_career_growth(const int year) {
    if (year % 3 == 0 && Alice.salary > 0) {
        Alice.career.level++;
        Alice.salary += 15000;
    }
}

void alice_burnout() {
    if (Alice.mental.stress > 70) {
        Alice.salary *= 0.9;
        Alice.mental.burnout++;
    }
}


void alice_recovery(const int month) {
    if (month == 8) {
        Alice.mental.stress -= 25;
        if (Alice.mental.stress < 0) Alice.mental.stress = 0;
    }
}


void alice_job_recovery(const int year, const int month) {
    if (year == 7 && month == 7) {
        Alice.salary = 130000;
    }
}


void alice_buy_bmw(const int year) {
    if (Alice.car.car_value == 0 && Alice.bank.deposit > 700000) {

        RUB price = 1000000 + year * 20000;

        bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, price);

        if (ok) {
            Alice.car.car_value = price;
            Alice.car.maintenance = 10000;
            Alice.car.age = 0;
        } else {
            Alice.mental.stress += 10;
        }
    }
}


void alice_sell_bmw() {
    if (Alice.car.car_value == 0) return;

    if (Alice.car.age > 7 || Alice.bank.deposit < 50000) {

        RUB sell_price = Alice.car.car_value * 0.6;

        if (Alice.car.age > 10)
            sell_price *= 0.8;

        Alice.bank.deposit += sell_price;

        Alice.car.car_value = 0;
        Alice.car.age = 0;
    }
}


void alice_car_usage() {
    if (Alice.car.car_value == 0) return;

    Alice.car.age++;

    RUB cost = Alice.car.maintenance + Alice.car.age * 1000;

    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, cost);

    if (!ok) {
        Alice.mental.stress += 3;
        Alice.car.car_value *= 0.95; // ухудшение состояния
    } else {
        Alice.car.car_value *= 0.97; // амортизация
    }
}

void alice_car_breakdown(const int year) {
    if (year % 4 == 0 && Alice.car.car_value > 0) {
        smart_spend(Alice.bank.debit, Alice.bank.deposit, 20000);
        Alice.mental.stress += 20;
    }
}


void alice_risky_investment(const int year) {
    if (Alice.decisions.agressive_risk_mode = true) return;

        if (Alice.bank.deposit > 500000) {
            RUB invest = Alice.bank.deposit * 0.2;
            Alice.bank.deposit -= invest;

            if (year % 5 == 0)
                invest *= 0.7; 
            else
                invest *= 1.15;

            Alice.assets.investments += invest;
    }
}


void alice_activate_agressive_risk_mode() {
    if (Alice.bank.deposit > 4000000) {
        Alice.decisions.agressive_risk_mode = true;
    }
}


void alice_aggressive_invest(const int year) {
    if (!Alice.decisions.agressive_risk_mode) return;

    RUB invest = Alice.bank.deposit * 0.3;
    Alice.bank.deposit -= invest;

    if (year % 4 == 0)
        invest *= 0.6;
    else
        invest *= 1.25;

    Alice.assets.investments += invest;
    Alice.mental.stress += 5;
}


void alice_investment_income() {
    RUB income = Alice.assets.investments * 0.09;
    Alice.bank.business += income;
}


void alice_course_invest(const int year, const int month) {
    if (year == 5 && month == 9) {
        smart_spend(Alice.bank.debit, Alice.bank.deposit, 200000);
        Alice.salary += 20000;
    }
}


void alice_insurance_by_stress() {
    if (Alice.mental.stress > 50 && !Alice.insurance.active) {
        Alice.insurance.active = true;
        Alice.insurance.monthly_payment = 6000;
        Alice.insurance.coverage = 700000;
    }
}


void alice_insurance_event( const int year) {
    if (!Alice.insurance.active) return;

    if (year % 9 == 0 || Alice.mental.stress > 80) {
        RUB payout = Alice.insurance.coverage;

        if (Alice.mental.stress > 80)
            payout *= 0.8;

        Alice.bank.deposit += payout;
        Alice.mental.stress -= 25;
    }
}


void alice_activate_frugal_mode() {
    if (Alice.bank.deposit < 60000) {
        Alice.decisions.frugal_mode = true;
    } else {
        Alice.decisions.frugal_mode = false;
    }
}


void alice_frugal_effect() {
    if (!Alice.decisions.frugal_mode) return;

    RUB save_food = Alice.food * 0.15;
    RUB save_transport = Alice.transport * 0.2;

    Alice.food -= save_food;
    Alice.transport -= save_transport;

    Alice.mental.stress += 2;

    if (Alice.mental.stress > 70) {
        Alice.food *= 1.4; // срыв
    }
}


void alice_social_growth() {
    if (Alice.salary > 100000) {
        if (Alice.social.connections < 50)
            Alice.social.connections += 3;

        if (Alice.social.reputation < 20)
            Alice.social.reputation += 1;
    }
}


void alice_social_income_bonus() {
    RUB bonus = Alice.social.connections * 400;

    if (bonus > 20000)
        bonus = 20000;

    Alice.bank.business += bonus;
}


void alice_business_stability() {
    if (!Alice.biz.open) return;

    if (Alice.social.reputation > 15) {
        Alice.biz.bad_months -= 1;
        if (Alice.biz.bad_months < 0) Alice.biz.bad_months = 0;
    }
}


void alice_passive_income_start() {
    if (Alice.assets.investments > 600000 && Alice.passive.income == 0) {
        Alice.passive.stability++;

        if (Alice.passive.stability > 3) {
            Alice.passive.income = 10000;
        }
    }
}


void alice_passive_income_gain() {
    if (Alice.passive.income == 0) return;

    RUB income = Alice.passive.income;

    if (Alice.assets.investments > 1500000)
        income *= 1.2;

    Alice.bank.business += income;
}


void alice_passive_decay() {
    if (Alice.passive.income == 0) return;

    if (Alice.mental.stress > 70) {
        Alice.passive.income *= 0.95;
        Alice.passive.stability--;
    }
}


void alice_apt_repair(const int year) {
    Alice.repair.condition -= 4;

    if (Alice.repair.condition < 50)
        Alice.repair.need_repair = true;

    if (Alice.repair.need_repair && Alice.bank.deposit > 2000000) {

        RUB cost = 2000000 + (100 - Alice.repair.condition) * 2000;

        bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, cost);

        if (ok) {
            Alice.repair.condition = 90;
            Alice.repair.need_repair = false;
            Alice.mental.stress -= 5;
        } else {
            Alice.mental.stress += 7;
        }
    }
}


void alice_utilities_payment(const int month) {
    if (month == 1)
        Alice.utilities.base_cost *= 1.05;

    RUB cost = Alice.utilities.base_cost;

    if (Alice.car.car_value > 0)
        cost += 5000; // парковка 

    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, cost);

    if (!ok) {
        Alice.mental.stress += 4;
        Alice.utilities.penni_level++;
    }
}


void alice_buy_rental_property() {
    if (!Alice.rental.owned && Alice.bank.deposit > 2500000) {

        RUB price = 2500000;

        bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, price);

        if (ok) {
            Alice.rental.owned = true;
            Alice.rental.price = price;
            Alice.rental.rent_income = 25000;
            Alice.rental.tenants_happiness = 70;
        } else {
            Alice.mental.stress += 5;
        }
    }
}


void alice_rental_income() {
    if (!Alice.rental.owned) return;

    RUB income = Alice.rental.rent_income;

    if (Alice.rental.tenants_happiness < 40)
        income *= 0.7;

    Alice.bank.business += income;

    Alice.rental.tenants_happiness -= 2;
}


void alice_tenant_problems() {
    if (!Alice.rental.owned) return;

    if (Alice.rental.tenants_happiness < 30) {
        smart_spend(Alice.bank.debit, Alice.bank.deposit, 50000);
        Alice.rental.tenants_happiness += 20;
        Alice.mental.stress += 5;
    }
}


void alice_rent(const int month) {
    if (month == 1) Alice.rent = Alice.rent * 106 / 100;

    RUB need = Alice.rent;

    if (Alice.bank.deposit < 30000)
        need *= 0.6; // снимает хуже жильё

    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, need);

    if (!ok) {
        Alice.mental.stress += 5; 
    }
}


void alice_open_bar(const int year, const int month) {
if (year == 5 && month == 1) {
    if (!Alice.biz.open && Alice.bank.deposit > 1500000) {
        Alice.bank.deposit -= 1500000;
        Alice.biz.open = 1;
        Alice.biz.income = 140000;
        Alice.biz.expenses = 80000;
         }
    }
}

void alice_business(const int month) {
    if (!Alice.biz.open) return;

    if (month == 1) {
        Alice.biz.income *= 1.03;
        Alice.biz.expenses *= 1.05;
    }

    RUB profit = Alice.biz.income - Alice.biz.expenses;

    if (profit < 0) {
        Alice.biz.bad_months++;

        if (Alice.biz.bad_months > 6) {
            Alice.biz.open = 0;
            return;
        }
    } else {
        Alice.biz.bad_months = 0;
        Alice.bank.business += profit;
    }
}


void alice_cheap_fun(const int month) {
    RUB cost = 1000;
    if (month == 1) cost = cost * 106 / 100;
    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, cost);

    if (ok) {
        Alice.mental.stress -= 1;
        Alice.leisure.happiness += 1;
    }
}


void alice_travel_start(const int year) {
    if (!Alice.travel.traveling && Alice.bank.deposit > 300000 && year % 2 == 0) {
        Alice.travel.traveling = true;
    }
}


void alice_travel_process(const int month) {
    if (!Alice.travel.traveling) return;

    RUB cost = 100000;
    if (month == 1) cost = cost * 106 / 100;

    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, cost);

    if (ok) {
        Alice.travel.trips_done++;
        Alice.travel.experience += 10;
        Alice.mental.stress -= 10;
        Alice.social.connections += 2;
    } else {
        Alice.travel.traveling = false;
        Alice.mental.stress += 5;
    }

    if (Alice.travel.trips_done > 2) {
        Alice.travel.traveling = false;
    }
}


void alice_luxury_rest(const int month) {
    if (Alice.bank.deposit < 200000) return;

    RUB cost = 15000;
    if (month == 1) cost = cost * 106 / 100;

    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, cost);

    if (ok) {
        Alice.social.reputation += 2;
        Alice.mental.stress -= 5;
        Alice.leisure.happiness += 8;
    }
}


void alice_parties(const int month) {

    RUB cost = 8000;
    if (month == 1) cost = cost * 106 / 100;
    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, cost);

    if (ok) {
        Alice.social.connections += 3;
        Alice.mental.stress -= 4;
        Alice.leisure.fatigue += 5;
    } else {
        Alice.mental.stress += 2;
    }
}

void peter_food(int month) {
    if (month == 1) Peter.food = Peter.food * 106 / 100;

    RUB need = Peter.food;

    if (Peter.bank.deposit < 100000)
        need *= 0.8;

    bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, need);

    if (!ok) {
        Peter.mental.stress += 5; 
    }
}

void peter_transport(int month) {
    if (month == 1) Peter.transport = Peter.transport * 106 / 100;

    RUB need = Peter.transport;

    if (Peter.bank.deposit < 50000)
        need *= 0.6;

    bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, need);

    if (!ok) {
        Peter.mental.stress += 5; 
    }
}


void peter_normal_healthy(int month) {
    if (month == 1) Peter.healthy = Peter.healthy * 106 / 100;

    RUB need = Peter.healthy;

    if (month == 11)
        need *= 2; // Хантавирус

    bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, need);

    if (!ok) {
        Peter.mental.stress += 5; 
    }
}


void peter_mentalyty_health() {
    Peter.health.level -= Peter.mental.stress / 20;

    if (Peter.health.level < 50) {
        RUB cost = 20000;
        smart_spend(Peter.bank.debit, Peter.bank.deposit, cost);

        Peter.health.level += 10;
    }

    if (Peter.health.level < 30) {
        Peter.salary *= 0.9;
    }
}


void peter_major_health_event(int year) {
    if (year % 13 == 0) {
        RUB cost = 400000;

        bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, cost);

        if (ok) {
            Peter.health.level += 20;
        } else {
            Peter.health.level -= 20;
            Peter.mental.stress += 10;
        }
    }
}


void peter_clothing(int month, int year) {
    if (month == 1) Peter.clothing = Peter.clothing * 106 / 100;

    RUB need = Peter.clothing; 

    if (year % 2 == 0 && month == 8 );
        need *= 3; // питер следит за модой, появилась новая модная коллекция

    bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, need);

    if (!ok) {
        Peter.mental.stress += 5; 
    }
}


void peter_dog(int month, int year) {
    if (month == 1) Peter.dog = Peter.dog * 106 / 100;

    RUB need = Peter.dog;
    

    if (year == 2 && month == 2); 
        need *= 6; // собака беременная

    bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, need);

    if (!ok) {
        Peter.mental.stress += 2; 
    }
}


void peter_school_education_start(int year) {
    if (!Peter.edu.studying && year == 4) {
        Peter.edu.studying = true;
    }
}


void peter_school_education_process() {
    if (!Peter.edu.studying) return;

    RUB cost = 15000;

    bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, cost);

    if (ok) {
        Peter.edu.level++;
    } else {
        Peter.mental.stress += 3;
    }

    if (Peter.edu.level > 10) {
        Peter.edu.studying = false;
        Peter.social.reputation++;
    }
}

void peter_cheap_fun(const int month) {
    RUB cost = 1000;
    if (month == 1) cost = cost * 106 / 100;
    bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, cost);

    if (ok) {
        Peter.mental.stress -= 1;
        Peter.leisure.happiness += 1;
    }
}


void peter_travel_start(const int year) {
    if (!Peter.travel.traveling && Peter.bank.deposit > 300000 && year % 2 == 0) {
        Peter.travel.traveling = true;
    }
}


void peter_travel_process(const int month) {
    if (!Peter.travel.traveling) return;

    RUB cost = 100000;
    if (month == 1) cost = cost * 106 / 100;

    bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, cost);

    if (ok) {
        Peter.travel.trips_done++;
        Peter.travel.experience += 10;
        Peter.mental.stress -= 10;
        Peter.social.connections += 2;
    } else {
        Peter.travel.traveling = false;
        Peter.mental.stress += 5;
    }

    if (Peter.travel.trips_done > 2) {
        Peter.travel.traveling = false;
    }
}


void peter_luxury_rest(const int month) {
    if (Peter.bank.deposit < 200000) return;

    RUB cost = 15000;
    if (month == 1) cost = cost * 106 / 100;

    bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, cost);

    if (ok) {
        Peter.social.reputation += 2;
        Peter.mental.stress -= 5;
        Peter.leisure.happiness += 8;
    }
}


void peter_parties(const int month) {

    RUB cost = 8000;
    if (month == 1) cost = cost * 106 / 100;
    bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, cost);

    if (ok) {
        Peter.social.connections += 3;
        Peter.mental.stress -= 4;
        Peter.leisure.fatigue += 5;
    } else {
        Peter.mental.stress += 2;
    }
}


void peter_mortgage_pay() {
    if (!Peter.has_mortgage) return;

    RUB pay = Peter.mortgage_payment;

    // досрочное погашение
    if (Peter.bank.deposit > 30000000)
        pay *= 1.5;

    if (pay > Peter.mortgage)
        pay = Peter.mortgage;

    bool ok = smart_spend (Peter.bank.debit,Peter.bank.deposit,pay);
    if (ok) {
        Peter.mortgage -= pay;

        if (Peter.mortgage == 0) {
            Peter.has_mortgage = false;
        }
    } else {
        Peter.mental.stress += 10;
    }
}



void peter_mortgage_stress() {
    if (Peter.has_mortgage) {
        Peter.mental.stress += 1;

        if (Peter.bank.deposit < 100000)
            Peter.mental.stress += 2;
    }
}


void peter_house_growth(const int year, const int month) {
    if (month == 1) {
        // рост или кризис
        if (year == 12) {
            Peter.house_price *= 0.8; // кризис
        } else {
            Peter.house_price *= 1.04;
        }
    }
}


void peter_bonus(const int month) {
    if (month == 12) {
        Peter.bank.debit += Peter.salary * 0.5;
    }
}


void peter_buy_audi(const int year) {
    if (Peter.car.car_value == 0 && Peter.bank.deposit > 700000) {

        RUB price = 800000 + year * 20000;

        bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, price);

        if (ok) {
            Peter.car.car_value = price;
            Peter.car.maintenance = 10000;
            Peter.car.age = 0;
        } else {
            Peter.mental.stress += 5;
        }
    }
}


void peter_sell_audi() {
    if (Peter.car.car_value == 0) return;

    if (Peter.car.age > 7 || Peter.bank.deposit < 50000) {

        RUB sell_price = Peter.car.car_value * 0.6;

        if (Peter.car.age > 10)
            sell_price *= 0.8;

        Peter.bank.deposit += sell_price;

        Peter.car.car_value = 0;
        Peter.car.age = 0;
    }
}


void peter_car_usage() {
    if (Peter.car.car_value == 0) return;

    Peter.car.age++;

    RUB cost = Peter.car.maintenance + Peter.car.age * 1000;

    bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, cost);

    if (!ok) {
        Peter.mental.stress += 3;
        Peter.car.car_value *= 0.95; // ухудшение состояния
    } else {
        Peter.car.car_value *= 0.97; // амортизация
    }
}


void peter_car_breakdown(const int year) {
    if (year % 5 == 0 && Peter.car.car_value > 0) {
        smart_spend(Peter.bank.debit, Peter.bank.deposit, 40000);
        Peter.mental.stress += 15;
    }
}


void peter_risky_investment(const int year) {
    if (Peter.decisions.agressive_risk_mode = true) return;

        if (Peter.bank.deposit > 500000) {
            RUB invest = Peter.bank.deposit * 0.2;
             Peter.bank.deposit -= invest;

            if (year % 5 == 0)
                invest *= 0.7; 
            else
                invest *= 1.15;

            Alice.assets.investments += invest;
    }
}


void peter_activate_agressive_risk_mode() {
    if (Peter.bank.deposit > 3000000) {
        Peter.decisions.agressive_risk_mode = true;
    }
}


void peter_aggressive_invest(const int year) {
    if (!Peter.decisions.agressive_risk_mode) return;

    RUB invest = Peter.bank.deposit * 0.3;
    Peter.bank.deposit -= invest;

    if (year % 4 == 0)
        invest *= 0.6;
    else
        invest *= 1.25;

    Peter.assets.investments += invest;
    Peter.mental.stress += 5;
}


void peter_investment_income() {
    RUB income = Peter.assets.investments * 0.09;
    Peter.bank.business += income;
}


void peter_course_invest(const int year, const int month) {
    if (year == 5 && month == 9) {
        smart_spend(Peter.bank.debit, Peter.bank.deposit, 200000);
        Peter.salary += 20000;
    }
}


void peter_insurance_by_stress() {
    if (Peter.mental.stress > 70 && !Peter.insurance.active) {
        Peter.insurance.active = true;
        Peter.insurance.monthly_payment = 4000;
        Peter.insurance.coverage = 500000;
    }
}


void peter_insurance_event(const int year) {
    if (!Peter.insurance.active) return;

    if (year % 9 == 0 || Peter.mental.stress > 90) {
        RUB payout = Peter.insurance.coverage;

        if (Peter.mental.stress > 90)
            payout *= 0.8;

        Peter.bank.deposit += payout;
        Peter.mental.stress -= 15;
    }
}


void peter_activate_frugal_mode() {
    if (Peter.bank.deposit < 50000) {
        Peter.decisions.frugal_mode = true;
    } else {
        Peter.decisions.frugal_mode = false;
    }
}


void peter_frugal_effect() {
    if (!Peter.decisions.frugal_mode) return;

    RUB save_food = Peter.food * 0.15;
    RUB save_transport = Peter.transport * 0.2;

    Peter.food -= save_food;
    Peter.transport -= save_transport;

    Peter.mental.stress += 2;

    if (Peter.mental.stress > 90) {
        Peter.food *= 1.1; // срыв
    }
}


void peter_social_growth() {
    if (Peter.salary > 150000) {
        if (Peter.social.connections < 60)
            Peter.social.connections += 3;

        if (Peter.social.reputation < 40)
            Peter.social.reputation += 2;
    }
}


void peter_social_income_bonus() {
    RUB bonus = Peter.social.connections * 700;

    if (bonus > 30000)
        bonus = 30000;

    Peter.bank.business += bonus;
}


void peter_business_stability() {
    if (!Peter.biz.open) return;

    if (Peter.social.reputation > 15) {
        Peter.biz.bad_months -= 1;
        if (Peter.biz.bad_months < 0) Peter.biz.bad_months = 0;
    }
}


void peter_passive_income_start() {
    if (Peter.assets.investments > 800000 && Peter.passive.income == 0) {
        Peter.passive.stability++;

        if (Peter.passive.stability > 3) {
            Peter.passive.income = 20000;
        }
    }
}


void peter_passive_income_gain() {
    if (Peter.passive.income == 0) return;

    RUB income = Peter.passive.income;

    if (Peter.assets.investments > 1500000)
        income *= 1.2;

    Peter.bank.business += income;
}


void peter_passive_decay() {
    if (Peter.passive.income == 0) return;

    if (Peter.mental.stress > 90) {
        Peter.passive.income *= 0.9;
        Peter.passive.stability--;
    }
}


void peter_house_repair(const int year) {
    Peter.repair.condition -= 3;

    if (Peter.repair.condition < 50)
        Peter.repair.need_repair = true;

    if (Peter.repair.need_repair && Peter.bank.deposit > 2000000) {

        RUB cost = 2000000 + (100 - Peter.repair.condition) * 2000;

        bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, cost);

        if (ok) {
            Peter.repair.condition = 90;
            Peter.repair.need_repair = false;
            Peter.mental.stress -= 5;
        } else {
            Peter.mental.stress += 7;
        }
    }
}


void peter_utilities_payment(const int month) {
    if (month == 1)
        Peter.utilities.base_cost *= 1.05;

    RUB cost = Peter.utilities.base_cost;

    if (Peter.car.car_value > 0)
        cost += 2000; // парковка 

    bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, cost);

    if (!ok) {
        Peter.mental.stress += 4;
        Peter.utilities.penni_level++;
    }
}


void peter_open_vkusno_i_tochka(const int year, const int month) {
if (year == 10 && month == 8) {
    if (!Peter.biz.open && Peter.bank.deposit > 3000000) {
        Peter.bank.deposit -= 1500000;
        Peter.biz.open = 1;
        Peter.biz.income = 140000;
        Peter.biz.expenses = 80000;
         }
    }
}

void peter_business(const int month) {
    if (!Peter.biz.open) return;

    if (month == 1) {
        Peter.biz.income *= 1.03;
        Peter.biz.expenses *= 1.05;
    }

    RUB profit = Peter.biz.income - Peter.biz.expenses;

    if (profit < 0) {
        Peter.biz.bad_months++;

        if (Peter.biz.bad_months > 6) {
            Peter.biz.open = 0;
            return;
        }
    } else {
        Peter.biz.bad_months = 0;
        Peter.bank.business += profit;
    }
}


void peter_business_crisis(const int year) {
    if (year == 12 && Peter.biz.open) {
        Peter.biz.income *= 0.7;
        Peter.biz.expenses *= 1.2;
    }
}


void peter_buy_rental_property() {
    if (!Peter.rental.owned && Peter.bank.deposit > 2500000) {

        RUB price = 2500000;

        bool ok = smart_spend(Peter.bank.debit, Peter.bank.deposit, price);

        if (ok) {
            Peter.rental.owned = true;
            Peter.rental.price = price;
            Peter.rental.rent_income = 25000;
            Peter.rental.tenants_happiness = 70;
        } else {
            Peter.mental.stress += 5;
        }
    }
}


void peter_rental_income() {
    if (!Peter.rental.owned) return;

    RUB income = Peter.rental.rent_income;

    if (Peter.rental.tenants_happiness < 40)
        income *= 0.7;

    Peter.bank.business += income;

    Peter.rental.tenants_happiness -= 2;
}


void peter_tenant_problems() {
    if (!Peter.rental.owned) return;

    if (Peter.rental.tenants_happiness < 30) {
        smart_spend(Peter.bank.debit, Peter.bank.deposit, 50000);
        Peter.rental.tenants_happiness += 20;
        Peter.mental.stress += 5;
    }
}


void alice_deposit_interest() {
    RUB income = Alice.bank.deposit * (Alice.bank.rate / 12.0 / 100.0);

    if (Alice.bank.deposit > 1000000)
        income *= 0.9;

    Alice.bank.deposit += income;
}

void peter_deposit_interest() {
    RUB income = Peter.bank.deposit * (Peter.bank.rate / 12.0 / 100.0);

    if (Peter.bank.deposit > 2000000)
        income *= 0.85;

    Peter.bank.deposit += income;
}


void alice_transfer_money() {
    Alice.bank.deposit += Alice.bank.debit + Alice.bank.business;
    Alice.bank.debit = 0;
    Alice.bank.business = 0;
}

void peter_transfer_money() {
    Peter.bank.deposit += Peter.bank.debit + Peter.bank.business;
    Peter.bank.debit = 0;
    Peter.bank.business = 0;
}


void simulation() {
    for (int year = 0; year < 25; year++) {
        for (int month = 1; month <= 12; month++) {

            alice_salary(month);
            peter_salary(month);
            global_crisis(year);

            alice_food(month);
            alice_transport(month);
            alice_normal_healthy(month);
            alice_mentalyty_health(month);
            alice_major_health_event(month, year);
            alice_clothing(month, year);
            alice_hamster(month, year);
            alice_job_loss(month, year);
            alice_job_search(month);
            alice_career_growth(year);
            alice_burnout();
            alice_recovery(month);
            alice_job_recovery(month, year);
            alice_buy_bmw(month);
            alice_car_usage();
            alice_car_breakdown(year);
            alice_risky_investment(year);
            alice_activate_agressive_risk_mode();
            alice_aggressive_invest(year);
            alice_investment_income();
            alice_course_invest(year, month);
            alice_insurance_by_stress();
            alice_insurance_event(year);
            alice_activate_frugal_mode();
            alice_frugal_effect();
            alice_social_growth();
            alice_social_income_bonus();
            alice_business_stability();
            alice_passive_income_start();
            alice_passive_income_gain();
            alice_passive_decay();
            alice_buy_rental_property();
            alice_rental_income();
            alice_tenant_problems();
            alice_apt_repair(year);
            alice_rent(month);
            alice_utilities_payment(month);
            alice_cheap_fun(month);
            alice_travel_start(year);
            alice_travel_process(month);
            alice_luxury_rest(month);
            alice_parties(month);
        
            

            

            peter_food(month);
            peter_transport(month);
            peter_normal_healthy(month);
            peter_mentalyty_health();
            peter_major_health_event(year);
            peter_clothing(month, year);
            peter_dog(month, year);
            peter_cheap_fun(month);
            peter_travel_start(year);
            peter_travel_process(month);
            peter_luxury_rest(month);
            peter_parties(month);
            peter_mortgage_pay();
            peter_mortgage_stress();
            peter_house_growth(year, month);
            peter_bonus(month);
            peter_buy_audi(month);
            peter_car_usage();
            peter_car_breakdown(year);
            peter_risky_investment(year);
            peter_activate_agressive_risk_mode();
            peter_aggressive_invest(year);
            peter_investment_income();
            peter_course_invest(year, month);
            peter_insurance_by_stress();
            peter_insurance_event(year);
            peter_activate_frugal_mode();
            peter_frugal_effect();
            peter_social_growth();
            peter_social_income_bonus();
            peter_passive_income_start();
            peter_passive_income_gain();
            peter_passive_decay();
            peter_buy_rental_property();
            peter_rental_income();
            peter_tenant_problems();
            peter_house_repair(year);
            peter_utilities_payment(month);
            peter_business_crisis(year);

            alice_open_bar(year, month);
            alice_business(month);

            peter_open_vkusno_i_tochka(year, month);
            peter_business(month);

            alice_deposit_interest();
            peter_deposit_interest();


            alice_transfer_money();
            peter_transfer_money();
        }
    }
}


void result() {
    RUB alice_total = Alice.bank.deposit;

    RUB peter_total =
        Peter.bank.deposit +
        Peter.house_price -
        Peter.mortgage +
        Peter.assets.investments +
        Peter.car.car_value;

    printf("\n=== RESULT ===\n");

    printf("\n--- FINANCES ---\n");
    printf("Alice money: %lld\n", alice_total);
    printf("Peter money: %lld\n", peter_total);

    printf("\n--- STRESS ---\n");
    printf("Alice stress: %d\n", Alice.mental.stress);
    printf("Peter stress: %d\n", Peter.mental.stress);

    printf("\n--- SOCIAL ---\n");
    printf("Alice connections: %d\n", Alice.social.connections);
    printf("Alice reputation: %d\n", Alice.social.reputation);

    printf("Peter connections: %d\n", Peter.social.connections);
    printf("Peter reputation: %d\n", Peter.social.reputation);

    printf("\n--- ASSETS ---\n");
    printf("Peter house: %lld\n", Peter.house_price);
    printf("Mortgage left: %lld\n", Peter.mortgage);

    printf("Alice investments: %lld\n", Alice.assets.investments);
    printf("Peter investments: %lld\n", Peter.assets.investments);

    printf("\n--- STATUS ---\n");

    if (Alice.mental.stress > 80)
        printf("Alice is in burnout\n");
    else if (Alice.mental.stress < 30)
        printf("Alice is stable\n");

    if (Peter.mental.stress > 80)
        printf("Peter is in burnout\n");
    else if (Peter.mental.stress < 30)
        printf("Peter is stable\n");

    printf("\n--- DECISION ---\n");

    if (alice_total > peter_total)
        printf(">>> RENT BETTER\n");
    else
        printf(">>> MORTGAGE BETTER\n");
}


int main() {
    Alice_init();
    Peter_init();

    simulation();

    result();

    return 0;
}



ДОП ЗАДАНИЯ
/* 
void alice_englsih_education_start(const int month, const int year) {
    if (!Alice.edu.studying && month == 9 && year == 4) {
        Alice.edu.studying = true;
    }
}


void alice_school_education_process(const int month) {
    if (!Alice.edu.studying) return;

    RUB cost = 20000;

    if (month == 1)
        cost = cost * 106 / 100;

    bool ok = smart_spend(
        Alice.bank.debit,
        Alice.bank.deposit,
        cost
    );
    
    Alice.edu.yearly_spent += cost;

    if (month == 12 ) {
        RUB nalog = cost * 13 / 100;

        Alice.bank.debit += nalog;
        Alice.edu.yearly_spent = 0;
    }

    Alice.edu.level++;

    if (Alice.edu.level > 4) {
        if (Alice.edu.yearly_spent > 0) {
            RUB nalog = Alice.edu.yearly_spent * 13 / 100;
            Alice.bank.debit += nalog;
            Alice.edu.yearly_spent = 0;
        }
        Alice.edu.studying = false;
    }
}













void alice_renovation (const int month, const int year){
 RUB cost_oboi = 10000;
 RUB cost_potop = 100000;
 RUB cost_plita = 20000;
 if (month == 1) cost_oboi = cost_oboi * 106 / 100;
 if (month == 1) cost_potop = cost_potop * 106 / 100;
 if (month == 1) cost_plita * 106 / 100;
 
if (!year == 20) return;

    if(month == 2) {
        bool ok = smart_spend(Alice.bank.debit, Alice.bank.deposit, cost_oboi );
    }

    if (month == 3){
         bool ok = smart_spend(Alice.bank.debit,Alice.bank.deposit, cost_potop);
    }
    if (month == 4 )
        bool ok = smart_spend(Alice.bank.debit,Alice.bank.deposit, cost_potop);
    

}