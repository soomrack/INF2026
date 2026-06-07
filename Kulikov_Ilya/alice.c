#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int Months;
typedef unsigned int Rubles;
typedef double Percent;
typedef double Score;
typedef unsigned int Pcs;
typedef unsigned int Kilometers;

typedef enum {
    Fired = 0,
    Trainee,
    Associate,
    QualifiedSpecialist,
    Lead,
    GroupHead,
    DepartmentHead,
    Expert,
    CouncilMember,
    GeneralDirector,  
} Stage;

typedef enum {
    BachelorYear1 = 1,
    BachelorYear2,
    BachelorYear3,
    BachelorYear4,
    MasterYear1,
    MasterYear2,
    DoctorateYear1,
    DoctorateYear2,
    DoctorateYear3,
    DoctorateYear4,
} Grade;


typedef struct {
    Stage stage;
    Rubles salary;
    Percent work_quality;
    Percent colleagues_attitude; 
} Workplace;


typedef struct {    
    Grade grade;
    Score average_score;
    Rubles fellowship;
} Studyplace;


typedef struct {
    Pcs amount;
    Rubles price;
} Share;


typedef struct {
    Percent interest;
    Rubles amount;
} Deposit;


typedef struct {
#define RANDOM_VALUES_AMOUNT 16
    Rubles gains[RANDOM_VALUES_AMOUNT];
    Percent chances[RANDOM_VALUES_AMOUNT];
} RandomRubles;


typedef struct {
    Pcs amount;
    Rubles price;
} ForeignCurrency;


typedef struct {
    Rubles price;
    Score saturation_points;
    Percent healthyness;
    unsigned int portions;
} Food;


typedef struct {
    Rubles price;
    Score recreation_points;
    Percent tiredness;
} Activity;


struct {
    struct {
        Months birthdate;
        Rubles money;
        int hangs_on;
        
        struct {
            Workplace symbolics;
            Workplace csail;
        } job;

        struct {
            Studyplace mit;
        } education;

        struct {
            Share yandex;
            Share sberbank;
            Share nvidia;
        } securities;

        struct {
            Deposit at_sberbank;
            Deposit at_alphabank;
        } deposits;

        struct {
            RandomRubles lottery;
            RandomRubles finds;
            RandomRubles heritage;
        } occasional;

        struct {
            ForeignCurrency dollars;
            ForeignCurrency euros;
            ForeignCurrency yuans;
        } foreign_currencies;

        struct {
            Food proteins;
            Food fats;
            Food carbohydrates;
        } nutrition;

        struct {
            Activity walk;
            Activity amusement_park;
            Activity videogames;
            Activity reading;
            Activity friends_meeting;
            Activity art_gallery;
        } recreation;

        struct {
            struct {
                Percent headache;
                Percent hunger;
                Percent fatigue;
                Percent disease;
            } physical;

            struct {
                Percent loneliness;
                Percent life_monotony;
                Percent life_burden;
                Percent dementia;
                Percent brain_integrity;
                Percent intelligence_quotient;
            } mental;
        } sanity;

        struct {
            Rubles gas;
            Rubles warm_water;
            Rubles cold_water;
            Rubles electricity;
            Rubles renovation_fund;
        } monthly_utility;

        struct {
            Rubles for_church;
            Rubles for_orphans;
            Rubles for_cancer_patients;
            Rubles for_life_prolongation_researches;
        } monthly_charity;

        struct {
            int is_trade_union_member;
            Months workage;
            Rubles base_payment;  
        } trade_union;

        struct {
            Percent bank_interest;
            Rubles monthly_payment;
            Rubles debt;
        } mortgage;

        struct {
            Rubles monthly_payment;
        } warehouse_rent;

        struct {
            Percent bank_interest;
            Rubles monthly_payment;
            Rubles debt;
        } loan;

        struct {
            int is_alive;
            Percent hunger;
            Percent disease;
            Percent loneliness;
        } pet;

        struct {
            int is_exist;
            Percent wear;
            Kilometers mileage;
            Rubles base_repair_cost;
            Rubles fuel_efficiency;
        } car;

        struct {
            Rubles operator_salary;
            Rubles cleaner_salary;
            Rubles place_monthly_rent;
            Percent firm_interest;
            Percent orders_flaw_rate;
            Rubles average_order_cost;
            Rubles monthly_internet_payment;
        } odp;

    } alice;

    Months date;
} env;


void init_environment()
{
    env.date = 2026 * 12 + 6;

    env.alice.birthdate = 2001 * 12 + 7;
    env.alice.money = 50000;
    env.alice.hangs_on = 1;

    env.alice.job.symbolics.stage = Trainee;
    env.alice.job.symbolics.salary = 120000;
    env.alice.job.symbolics.work_quality = 65;
    env.alice.job.symbolics.colleagues_attitude = 50;

    env.alice.job.csail.stage = QualifiedSpecialist;
    env.alice.job.csail.salary = 198000;
    env.alice.job.csail.work_quality = 78;
    env.alice.job.csail.colleagues_attitude = 34;

    env.alice.education.mit.grade = BachelorYear2;
    env.alice.education.mit.average_score = 4.3;
    env.alice.education.mit.fellowship = 4000;

    env.alice.securities.yandex.amount = 35;
    env.alice.securities.yandex.price = 2500;

    env.alice.securities.sberbank.amount = 51;
    env.alice.securities.sberbank.price = 280;

    env.alice.securities.nvidia.amount = 3;
    env.alice.securities.nvidia.price = 45000;

    env.alice.deposits.at_sberbank.interest = 5.5;
    env.alice.deposits.at_sberbank.amount = 100000;

    env.alice.deposits.at_alphabank.interest = 6.2;
    env.alice.deposits.at_alphabank.amount = 50000;

    {
        Rubles gains[16] = { 0,        100,    500,     1000,
                             5000,     10000,  50000,   10000,
                             200000,   500000, 1000000, 5000000,
                             10000000, 0,      0,       0 };
                         
        Percent chances[16] = { 50,  20,  10,  7,
                                5,   3,   2,   1,
                                0.8, 0.5, 0.3, 0.2,
                                0.1, 0,   0,   0 };
                            
        for (int i = 0; i < 16; ++i) {
            env.alice.occasional.lottery.gains[i] = gains[i];
            env.alice.occasional.lottery.chances[i] = chances[i];
        }
    };

    {
        Rubles gains[16] = { 0,        100,    500,     1000,
                             5000,     10000,  50000,   10000,
                             200000,   500000, 1000000, 5000000,
                             10000000, 0,      0,       0 };
                         
        Percent chances[16] = { 50,  20,  10,  7,
                                5,   3,   2,   1,
                                0.8, 0.5, 0.3, 0.2,
                                0.1, 0,   0,   0 };
                            
        for (int i = 0; i < 16; ++i) {
            env.alice.occasional.finds.gains[i] = gains[i];
            env.alice.occasional.finds.chances[i] = chances[i];
        }
    };

    {
       Rubles gains[16] = { 0,        100,    500,     1000,
                             5000,     10000,  50000,   10000,
                             200000,   500000, 1000000, 5000000,
                             10000000, 0,      0,       0 };
                         
        Percent chances[16] = { 50,  20,  10,  7,
                                5,   3,   2,   1,
                                0.8, 0.5, 0.3, 0.2,
                                0.1, 0,   0,   0 };
                            
        for (int i = 0; i < 16; ++i) {
            env.alice.occasional.heritage.gains[i] = gains[i];
            env.alice.occasional.heritage.chances[i] = chances[i];
        }
    };

    env.alice.foreign_currencies.dollars.amount = 0;
    env.alice.foreign_currencies.dollars.price = 92;

    env.alice.foreign_currencies.euros.amount = 0;
    env.alice.foreign_currencies.euros.price = 100;

    env.alice.foreign_currencies.yuans.amount = 0;
    env.alice.foreign_currencies.yuans.price = 13;

    env.alice.nutrition.proteins.price = 170;
    env.alice.nutrition.proteins.saturation_points = 26.0;
    env.alice.nutrition.proteins.healthyness = 30;
    env.alice.nutrition.proteins.portions = 30 * 3 * 1;

    env.alice.nutrition.fats.price = 60;
    env.alice.nutrition.fats.saturation_points = 52.5;
    env.alice.nutrition.fats.healthyness = -10;
    env.alice.nutrition.fats.portions = 30 * 3 * 1;

    env.alice.nutrition.carbohydrates.price = 80;
    env.alice.nutrition.carbohydrates.saturation_points = 43.5;
    env.alice.nutrition.carbohydrates.healthyness = -5;
    env.alice.nutrition.carbohydrates.portions = 30 * 3 * 1;

    env.alice.recreation.walk.price = 0;
    env.alice.recreation.walk.recreation_points = 0.08;
    env.alice.recreation.walk.tiredness = -15;

    env.alice.recreation.amusement_park.price = 1500;
    env.alice.recreation.amusement_park.recreation_points = 0.35;
    env.alice.recreation.amusement_park.tiredness = -40;

    env.alice.recreation.videogames.price = 200;
    env.alice.recreation.videogames.recreation_points = 0.20;
    env.alice.recreation.videogames.tiredness = -10;

    env.alice.recreation.reading.price = 0;
    env.alice.recreation.reading.recreation_points = 0.15;
    env.alice.recreation.reading.tiredness = -5;

    env.alice.recreation.friends_meeting.price = 800;
    env.alice.recreation.friends_meeting.recreation_points = 0.30;
    env.alice.recreation.friends_meeting.tiredness = -30;

    env.alice.recreation.art_gallery.price = 600;
    env.alice.recreation.art_gallery.recreation_points = 0.25;
    env.alice.recreation.art_gallery.tiredness = -20;

    env.alice.sanity.physical.headache = 5;
    env.alice.sanity.physical.hunger = 12;
    env.alice.sanity.physical.fatigue = 15;
    env.alice.sanity.physical.disease = 2;

    env.alice.sanity.mental.loneliness = 10;
    env.alice.sanity.mental.life_monotony = 20;
    env.alice.sanity.mental.life_burden = 12;
    env.alice.sanity.mental.dementia = 1;
    env.alice.sanity.mental.brain_integrity = 100;
    env.alice.sanity.mental.intelligence_quotient = 95;

    env.alice.monthly_utility.gas = 500;
    env.alice.monthly_utility.warm_water = 1200;
    env.alice.monthly_utility.cold_water = 800;
    env.alice.monthly_utility.electricity = 2000;
    env.alice.monthly_utility.renovation_fund = 700;

    env.alice.monthly_charity.for_church = 500;
    env.alice.monthly_charity.for_orphans = 300;
    env.alice.monthly_charity.for_cancer_patients = 400;
    env.alice.monthly_charity.for_life_prolongation_researches = 1000;

    env.alice.trade_union.is_trade_union_member = 1;
    env.alice.trade_union.workage = 4 * 12;
    env.alice.trade_union.base_payment = 900;

    env.alice.mortgage.bank_interest = 4.5;
    env.alice.mortgage.monthly_payment = 35000;
    env.alice.mortgage.debt = 3500000;

    env.alice.warehouse_rent.monthly_payment = 12000;

    env.alice.loan.bank_interest = 10.2;
    env.alice.loan.monthly_payment = 8700;
    env.alice.loan.debt = 300000;

    env.alice.pet.is_alive = 1;
    env.alice.pet.hunger = 30;
    env.alice.pet.disease = 5;
    env.alice.pet.loneliness = 20;

    env.alice.car.is_exist = 1;
    env.alice.car.wear = 0.0;
    env.alice.car.mileage = 0;
    env.alice.car.base_repair_cost = 5000;
    env.alice.car.fuel_efficiency = 79; /* rubles per kilometer */

    env.alice.odp.operator_salary = 32000;
    env.alice.odp.cleaner_salary = 29000;
    env.alice.odp.place_monthly_rent = 30000;
    env.alice.odp.firm_interest = 10;
    env.alice.odp.orders_flaw_rate = 2;
    env.alice.odp.average_order_cost = 1200;
    env.alice.odp.monthly_internet_payment = 1500;
}


void consider_alice_symbolics_salary()
{    
    if (env.alice.job.symbolics.stage != Fired) {
        env.alice.money += env.alice.job.symbolics.salary;
        printf("[Month %u] [Alice] [Balance %u RUB] Received salary from Symbolics: %u RUB\n",
               env.date, env.alice.money, env.alice.job.symbolics.salary);
    }
}


void consider_alice_csail_salary()
{    
    if (env.alice.job.csail.stage != Fired) {
        env.alice.money += env.alice.job.csail.salary;
        printf("[Month %u] [Alice] [Balance %u RUB] Received salary from CSAIL: %u RUB\n",
               env.date, env.alice.money, env.alice.job.csail.salary);
    }
}


void consider_alice_mit_fellowship()
{
    if (env.alice.education.mit.grade <= DoctorateYear1) {
        env.alice.money += env.alice.education.mit.fellowship;
        printf("[Month %u] [Alice] [Balance %u RUB] Received fellowship from MIT: %u RUB\n",
               env.date, env.alice.money, env.alice.education.mit.fellowship);
    }
}


void consider_alice_symbolics_bonus()
{    
    Percent quality = env.alice.job.symbolics.work_quality;
    Percent attitude = env.alice.job.symbolics.colleagues_attitude;
    Percent bonus_chance = (quality + attitude) / 4;
    int bonus_trigger = rand() % 100;
    if (env.alice.job.symbolics.stage != Fired && bonus_trigger < (int)bonus_chance) {
        Rubles bonus = env.alice.job.symbolics.salary / 2; /* 50% bonus */
        env.alice.money += bonus;
        printf("[Month %u] [Alice] [Balance %u RUB] Received performance bonus from Symbolics: %u RUB\n",
               env.date, env.alice.money, bonus);
    }
}


void consider_alice_csail_bonus()
{
    Percent quality = env.alice.job.csail.work_quality;
    Percent attitude = env.alice.job.csail.colleagues_attitude;
    Percent bonus_chance = (quality + attitude) / 4;
    int bonus_trigger = rand() % 100;
    if (env.alice.job.csail.stage != Fired && bonus_trigger < (int)bonus_chance) {
        Rubles bonus = env.alice.job.csail.salary / 2; /* 50% bonus */
        env.alice.money += bonus;
        printf("[Month %u] [Alice] [Balance %u RUB] Received performance bonus from CSAIL: %u RUB\n",
               env.date, env.alice.money, bonus);
    }
}


void consider_alice_trade_union_bonus()
{
    if (env.alice.trade_union.is_trade_union_member) {
        ++env.alice.trade_union.workage;
        env.alice.money += env.alice.trade_union.base_payment;
        printf("[Month %u] [Alice] [Balance %u RUB] Received trade union payment: %u RUB\n",
               env.date, env.alice.money, env.alice.trade_union.base_payment);        
    }
}


void consider_alice_symbolics_promotion()
{    
    Percent quality = env.alice.job.symbolics.work_quality;
    Percent attitude = env.alice.job.symbolics.colleagues_attitude;
    int promotion_chance = (int) ((quality + attitude) / 16);
    int promotion_trigger = rand() % 100;

    if (env.alice.job.symbolics.stage != Fired &&
        env.alice.job.symbolics.stage < GeneralDirector &&
        promotion_trigger < promotion_chance) {
        ++env.alice.job.symbolics.stage;
        env.alice.job.symbolics.salary *= 1.95;
        printf("[Month %u] [Alice] [Balance %u RUB] Promoted at Symbolics to stage %u, salary now %u RUB\n",
               env.date, env.alice.money, env.alice.job.symbolics.stage,
               env.alice.job.symbolics.salary);
    }
}


void consider_alice_csail_promotion()
{
    Percent quality = env.alice.job.csail.work_quality;
    Percent attitude = env.alice.job.csail.colleagues_attitude;
    int promotion_chance = (int) ((quality + attitude) / 16);
    int promotion_trigger = rand() % 100;

    if (env.alice.job.csail.stage != Fired &&
        env.alice.job.csail.stage < GeneralDirector &&
        promotion_trigger < promotion_chance) {
        ++env.alice.job.csail.stage;
        env.alice.job.csail.salary *= 2.01;
        printf("[Month %u] [Alice] [Balance %u RUB] Promoted at CSAIL to stage %u, salary now %u RUB\n",
               env.date, env.alice.money, env.alice.job.csail.stage,
               env.alice.job.csail.salary);
    }
}


void consider_alice_symbolics_demotion()
{
    int fire_risk = rand() % 100;
    Percent quality = env.alice.job.symbolics.work_quality;
    if (env.alice.job.symbolics.stage != Fired && quality < 20 && fire_risk < 15) {
        env.alice.job.symbolics.stage = Fired;
        env.alice.job.symbolics.salary = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Fired from Symbolics due to low work quality\n",
               env.date, env.alice.money);
    }
}


void consider_alice_csail_demotion()
{
    int fire_risk = rand() % 100;
    Percent quality = env.alice.job.csail.work_quality;
    if (env.alice.job.csail.stage != Fired && quality < 20 && fire_risk < 15) {
        env.alice.job.csail.stage = Fired;
        env.alice.job.csail.salary = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Fired from CSAIL due to low work quality\n",
               env.date, env.alice.money);
    }
}


void consider_alice_symbolics_work_quality_flow()
{
    env.alice.job.symbolics.work_quality += (rand() % 9) - 4;
    if (env.alice.job.symbolics.work_quality > 100) env.alice.job.symbolics.work_quality = 100;
    if (env.alice.job.symbolics.work_quality < 0) env.alice.job.symbolics.work_quality = 0;
}


void consider_alice_csail_work_quality_flow()
{
    env.alice.job.csail.work_quality += (rand() % 5) - 2;
    if (env.alice.job.csail.work_quality > 100) env.alice.job.csail.work_quality = 100;
    if (env.alice.job.csail.work_quality < 0) env.alice.job.csail.work_quality = 0;
}


void consider_alice_mit_education()
{
    Score current_score = env.alice.education.mit.average_score;
    Score study_effect = (Score)(rand() % 10) / 100.0; /* random factor 0 to 0.09 */
    Score mental_factor = env.alice.sanity.mental.intelligence_quotient / 1000.0; /* IQ influence */
    Score change = study_effect + mental_factor - 0.02; /* base difficulty offset */
    
    env.alice.education.mit.average_score = current_score + change;
    
    if (env.alice.education.mit.average_score > 5.0)
        env.alice.education.mit.average_score = 5.0;
    if (env.alice.education.mit.average_score < 2.0)
        env.alice.education.mit.average_score = 2.0;

    printf("[Month %u] [Alice] [Balance %u RUB] MIT average score changed to %.2f\n",
           env.date, env.alice.money, env.alice.education.mit.average_score);

    env.alice.sanity.mental.intelligence_quotient += (rand() % 3) - 1;
    if (env.alice.sanity.mental.intelligence_quotient > 200)
        env.alice.sanity.mental.intelligence_quotient = 200;
    if (env.alice.sanity.mental.intelligence_quotient < 50)
        env.alice.sanity.mental.intelligence_quotient = 50;
    
    printf("[Month %u] [Alice] [Balance %u RUB] IQ changed to %.2f\n",
           env.date, env.alice.money, env.alice.sanity.mental.intelligence_quotient);
}


void consider_alice_mit_graduation()
{    
    Grade current_grade = env.alice.education.mit.grade;
    int graduation_trigger = rand() % 100;
    Score score = env.alice.education.mit.average_score;

    if (current_grade <= DoctorateYear4 && score >= 3.0 && graduation_trigger < 25) {
        ++env.alice.education.mit.grade;
        env.alice.education.mit.fellowship *= 1.78;
        printf("[Month %u] [Alice] [Balance %u RUB] Advanced to MIT grade %u, fellowship now %u RUB\n",
               env.date, env.alice.money, env.alice.education.mit.grade,
               env.alice.education.mit.fellowship);
    }

    
    if (env.alice.education.mit.grade > DoctorateYear4) {
        env.alice.education.mit.fellowship = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Graduated from MIT, no more fellowship\n",
               env.date, env.alice.money);
    }
}


void consider_alice_yandex_investment()
{
    int action = rand() % 100;
    if (action < 30 && env.alice.money >= env.alice.securities.yandex.price) {
        Pcs to_buy = (env.alice.money / 10) / env.alice.securities.yandex.price;
        if (to_buy > 0) {
            Rubles cost = to_buy * env.alice.securities.yandex.price;
            env.alice.money -= cost;
            env.alice.securities.yandex.amount += to_buy;
            printf("[Month %u] [Alice] [Balance %u RUB] Bought %u Yandex shares at %u RUB each, total %u RUB\n",
                   env.date, env.alice.money, to_buy, env.alice.securities.yandex.price, cost);
        }
    }
}


void consider_alice_sberbank_investment()
{
    int action = rand() % 100;
    if (action < 25 && env.alice.money >= env.alice.securities.sberbank.price) {
        Pcs to_buy = (env.alice.money / 12) / env.alice.securities.sberbank.price;
        if (to_buy > 0) {
            Rubles cost = to_buy * env.alice.securities.sberbank.price;
            env.alice.money -= cost;
            env.alice.securities.sberbank.amount += to_buy;
            printf("[Month %u] [Alice] [Balance %u RUB] Bought %u SberBank shares at %u RUB each, total %u RUB\n",
                   env.date, env.alice.money, to_buy, env.alice.securities.sberbank.price, cost);
        }
    }
}


void consider_alice_nvidia_investment()
{
    int action = rand() % 100;
    if (action < 20 && env.alice.money >= env.alice.securities.nvidia.price) {
        Pcs to_buy = (env.alice.money / 15) / env.alice.securities.nvidia.price;
        if (to_buy > 0) {
            Rubles cost = to_buy * env.alice.securities.nvidia.price;
            env.alice.money -= cost;
            env.alice.securities.nvidia.amount += to_buy;
            printf("[Month %u] [Alice] [Balance %u RUB] Bought %u NVidia shares at %u RUB each, total %u RUB\n",
                   env.date, env.alice.money, to_buy, env.alice.securities.nvidia.price, cost);
        }
    }
}


void consider_alice_sberbank_deposit_interest()
{
    Percent monthly_rate = env.alice.deposits.at_sberbank.interest / 12;
    Rubles interest = env.alice.deposits.at_sberbank.amount * (Rubles)monthly_rate / 100;
    env.alice.deposits.at_sberbank.amount += interest;
    printf("[Month %u] [Alice] [Balance %u RUB] Sberbank deposit interest accrued: %u RUB, total %u RUB\n",
           env.date, env.alice.money, interest, env.alice.deposits.at_sberbank.amount);   
}


void consider_alice_alphabank_deposit_interest()
{
    Percent monthly_rate = env.alice.deposits.at_alphabank.interest / 12;
    Rubles interest = env.alice.deposits.at_alphabank.amount * (Rubles)monthly_rate / 100;
    env.alice.deposits.at_alphabank.amount += interest;
    printf("[Month %u] [Alice] [Balance %u RUB] Alphabank deposit interest accrued: %u RUB, total %u RUB\n",
           env.date, env.alice.money, interest, env.alice.deposits.at_alphabank.amount);
    
}


void consider_alice_sberbank_deposit_topup()
{
    int topup_trigger = rand() % 100;
    if (topup_trigger < 35 && env.alice.money > 10000) {
        Rubles to_deposit = env.alice.money / 8;
        env.alice.money = env.alice.money - to_deposit;
        env.alice.deposits.at_sberbank.amount += to_deposit;
        printf("[Month %u] [Alice] [Balance %u RUB] Deposited %u RUB to Sberbank\n",
                   env.date, env.alice.money, to_deposit);
    }
}


void consider_alice_alphabank_deposit_topup()
{
    int topup_trigger = rand() % 100;
    if (topup_trigger < 20 && env.alice.money > 20000) {
        Rubles to_deposit = env.alice.money / 14;
        env.alice.money = env.alice.money - to_deposit;
        env.alice.deposits.at_alphabank.amount += to_deposit;
        printf("[Month %u] [Alice] [Balance %u RUB] Deposited %u RUB to Alphabank\n",
               env.date, env.alice.money, to_deposit);
    }
}


void consider_alice_lottery_income()
{
    Rubles win = 0;
    for (int i = 0; i < RANDOM_VALUES_AMOUNT; ++i) {
        int roll = rand() % 100;
        if (roll < env.alice.occasional.lottery.chances[i]) {
            win += env.alice.occasional.lottery.gains[i];
        }
    }

    if (win > 0) {
        printf("[Month %u] [Alice] [Balance %u RUB] Won lottery: %u RUB\n",
               env.date, env.alice.money, win);
    }
}


void consider_alice_finds_income()
{
    Rubles find = 0;
    for (int i = 0; i < RANDOM_VALUES_AMOUNT; ++i) {
        int roll = rand() % 100;
        if (roll < env.alice.occasional.finds.chances[i]) {
            find += env.alice.occasional.finds.gains[i];
        }
    }

    if (find > 0) {
        printf("[Month %u] [Alice] [Balance %u RUB] Find some money: %u RUB\n",
               env.date, env.alice.money, find);
    }
}


void consider_alice_heritage_income()
{
    Rubles heritage = 0;
    for (int i = 0; i < RANDOM_VALUES_AMOUNT; ++i) {
        int roll = rand() % 100;
        if (roll < env.alice.occasional.heritage.chances[i]) {
            heritage += env.alice.occasional.heritage.gains[i];
        }
    }

    if (heritage > 0) {
        printf("[Month %u] [Alice] [Balance %u RUB] Got heritage: %u RUB\n",
               env.date, env.alice.money, heritage);
    }
}


void consider_alice_dollars_buy()
{
    int buy_trigger = rand() % 100;
    if (buy_trigger < 25 && env.alice.money >= env.alice.foreign_currencies.dollars.price * 30) {        
        Pcs amount = 10 + rand() % 20;
        Rubles cost = amount * env.alice.foreign_currencies.dollars.price;
        env.alice.money -= cost;
        env.alice.foreign_currencies.dollars.amount += amount;
        printf("[Month %u] [Alice] [Balance %u RUB] Bought %u USD at %u RUB each, total %u RUB\n",
               env.date, env.alice.money, amount, env.alice.foreign_currencies.dollars.price, cost);
    }
}


void consider_alice_euros_buy()
{
    int buy_trigger = rand() % 100;
    if (buy_trigger < 14 && env.alice.money >= env.alice.foreign_currencies.euros.price * 18) {
        Pcs amount = 5 + rand() % 12;
        Rubles cost = amount * env.alice.foreign_currencies.euros.price;
        env.alice.money -= cost;
        env.alice.foreign_currencies.euros.amount += amount;
        printf("[Month %u] [Alice] [Balance %u RUB] Bought %u EUR at %u RUB each, total %u RUB\n",
               env.date, env.alice.money, amount, env.alice.foreign_currencies.euros.price, cost);
    }
}


void consider_alice_yuans_buy()
{
    int buy_trigger = rand() % 100;
    if (buy_trigger < 45 && env.alice.money >= env.alice.foreign_currencies.yuans.price * 57) {
        Pcs amount = 8 + rand() % 49;
        Rubles cost = amount * env.alice.foreign_currencies.yuans.price;
        env.alice.money -= cost;
        env.alice.foreign_currencies.yuans.amount += amount;
        printf("[Month %u] [Alice] [Balance %u RUB] Bought %u CNY at %u RUB each, total %u RUB\n",
               env.date, env.alice.money, amount, env.alice.foreign_currencies.yuans.price, cost);
    }
}


void consider_alice_dollars_sell()
{
    int sell_trigger = rand() % 100;
    if (sell_trigger < 20 && env.alice.foreign_currencies.dollars.amount > 15) {
        Pcs amount = 5 + rand() % 10;
        
        if (amount > env.alice.foreign_currencies.dollars.amount) {
            amount = env.alice.foreign_currencies.dollars.amount;
        }
        
        Rubles revenue = amount * env.alice.foreign_currencies.dollars.price;
        env.alice.money += revenue;
        env.alice.foreign_currencies.dollars.amount -= amount;
        printf("[Month %u] [Alice] [Balance %u RUB] Sold %u USD at %u RUB each, total %u RUB\n",
               env.date, env.alice.money, amount, env.alice.foreign_currencies.dollars.price, revenue);
    }
}


void consider_alice_euros_sell()
{
    int sell_trigger = rand() % 100;
    if (sell_trigger < 66 && env.alice.foreign_currencies.euros.amount > 33) {
        Pcs amount = 8 + rand() % 35;
        
        if (amount > env.alice.foreign_currencies.euros.amount) {
            amount = env.alice.foreign_currencies.euros.amount;
        }
        
        Rubles revenue = amount * env.alice.foreign_currencies.euros.price;
        env.alice.money += revenue;
        env.alice.foreign_currencies.euros.amount -= amount;
        printf("[Month %u] [Alice] [Balance %u RUB] Sold %u EUR at %u RUB each, total %u RUB\n",
               env.date, env.alice.money, amount, env.alice.foreign_currencies.dollars.price, revenue);
    }
}


void consider_alice_yuans_sell()
{
    int sell_trigger = rand() % 100;
    if (sell_trigger < 2 && env.alice.foreign_currencies.yuans.amount > 80) {
        Pcs amount = 5 + rand() % 75;
        
        if (amount > env.alice.foreign_currencies.yuans.amount) {
            amount = env.alice.foreign_currencies.yuans.amount;
        }
        
        Rubles revenue = amount * env.alice.foreign_currencies.yuans.price;
        env.alice.money += revenue;
        env.alice.foreign_currencies.yuans.amount -= amount;
        printf("[Month %u] [Alice] [Balance %u RUB] Sold %u CNY at %u RUB each, total %u RUB\n",
               env.date, env.alice.money, amount, env.alice.foreign_currencies.yuans.price, revenue);
    }
}


void consider_alice_mortgage_payment()
{
    if (env.alice.mortgage.debt > 0) {
        Rubles payment = env.alice.mortgage.monthly_payment;
        if (env.alice.money >= payment) {
            env.alice.money -= payment;
            if (payment >= env.alice.mortgage.debt) {
                payment = env.alice.mortgage.debt;
                env.alice.mortgage.debt = 0;
                printf("[Month %u] [Alice] [Balance %u RUB] Final mortgage payment: %u RUB, mortgage fully paid off\n",
                       env.date, env.alice.money, payment);
            } else {
                env.alice.mortgage.debt -= payment;
                printf("[Month %u] [Alice] [Balance %u RUB] Mortgage payment: %u RUB, remaining debt: %u RUB\n",
                       env.date, env.alice.money, payment, env.alice.mortgage.debt);
            }
        } else {
            Rubles partial = env.alice.money;
            env.alice.mortgage.debt -= partial;
            env.alice.money = 0;
            printf("[Month %u] [Alice] [Balance %u RUB] Partial mortgage payment: %u RUB, remaining debt: %u RUB\n",
                   env.date, env.alice.money, partial, env.alice.mortgage.debt);
        }
    }
}


void consider_alice_mortgage_extra_payment()
{
    int extra_trigger = rand() % 100;
    if (extra_trigger < 15
        && env.alice.mortgage.debt > 0
        && env.alice.money > env.alice.mortgage.monthly_payment * 2) {
        Rubles extra = env.alice.mortgage.monthly_payment;
        env.alice.money -= extra;
        if (extra >= env.alice.mortgage.debt) {
            extra = env.alice.mortgage.debt;
            env.alice.mortgage.debt = 0;
            printf("[Month %u] [Alice] [Balance %u RUB] Extra payment closed mortgage: %u RUB\n",
                   env.date, env.alice.money, extra);
        } else {
            env.alice.mortgage.debt -= extra;
            printf("[Month %u] [Alice] [Balance %u RUB] Extra mortgage payment: %u RUB, remaining debt: %u RUB\n",
                    env.date, env.alice.money, extra, env.alice.mortgage.debt);
        }
    }
}


void consider_alice_mortgage_occasional_rate_adjust()
{
    int rate_adjust = rand() % 100;
    if (rate_adjust < 3) {
        Percent change = (rand() % 3) - 1;
        env.alice.mortgage.bank_interest += change;
        if (env.alice.mortgage.bank_interest < 2.0)
            env.alice.mortgage.bank_interest = 2.0;
        if (env.alice.mortgage.bank_interest > 20.0)
            env.alice.mortgage.bank_interest = 20.0;
        printf("[Month %u] [Alice] [Balance %u RUB] Mortgage interest rate changed to %.1f%%\n",
               env.date, env.alice.money, env.alice.mortgage.bank_interest);
    }
}


void consider_alice_mortgage_mental_influence()
{
    if (env.alice.mortgage.debt > 0) {
        env.alice.sanity.mental.life_burden += 0.3; /* mortgage stress */
    } else {
        env.alice.sanity.mental.life_burden -= 1.0;
    }
    
    if (env.alice.sanity.mental.life_burden > 100)
        env.alice.sanity.mental.life_burden = 100;
    if (env.alice.sanity.mental.life_burden < 0)
        env.alice.sanity.mental.life_burden = 0;
    
    printf("[Month %u] [Alice] [Balance %u RUB] Life difficulty changed to %.1f%% due to mortgage (or its absence)\n",
           env.date, env.alice.money, env.alice.sanity.mental.life_burden);
}


void consider_alice_warehouse_rent()
{
    Rubles rent = env.alice.warehouse_rent.monthly_payment;
    if (env.alice.money >= rent) {
        env.alice.money -= rent;
        printf("[Month %u] [Alice] [Balance %u RUB] Paid warehouse rent: %u RUB\n",
               env.date, env.alice.money, rent);
    } else {
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot afford warehouse rent: %u RUB needed, %u RUB available\n",
               env.date, env.alice.money, rent, env.alice.money);
    }
}


void consider_alice_warehouse_rent_renegotiation()
{    
    int renegotiate = rand() % 100;
    if (renegotiate < 10) {
        int change = (rand() % 4001) - 2000;
        env.alice.warehouse_rent.monthly_payment += change;
        if (env.alice.warehouse_rent.monthly_payment < 5000) env.alice.warehouse_rent.monthly_payment = 5000;
        if (env.alice.warehouse_rent.monthly_payment > 50000) env.alice.warehouse_rent.monthly_payment = 50000;
        printf("[Month %u] [Alice] [Balance %u RUB] Warehouse rent changed to %u RUB/month\n",
               env.date, env.alice.money, env.alice.warehouse_rent.monthly_payment);
    }
}


void consider_alice_loan_payment()
{
    if (env.alice.loan.debt > 0) {
        Rubles payment = env.alice.loan.monthly_payment;
        if (env.alice.money >= payment) {
            env.alice.money -= payment;
            if (payment >= env.alice.loan.debt) {
                payment = env.alice.loan.debt;
                env.alice.loan.debt = 0;
                printf("[Month %u] [Alice] [Balance %u RUB] Final loan payment: %u RUB, loan fully paid off\n",
                       env.date, env.alice.money, payment);
            } else {
                env.alice.loan.debt = env.alice.loan.debt - payment;
                printf("[Month %u] [Alice] [Balance %u RUB] Loan payment: %u RUB, remaining debt: %u RUB\n",
                       env.date, env.alice.money, payment, env.alice.loan.debt);
            }
        } else {
            Rubles partial = env.alice.money;
            env.alice.loan.debt -= partial;
            env.alice.money = 0;
            env.alice.loan.debt += partial / 10; /* penalty for late payment */
            printf("[Month %u] [Alice] [Balance %u RUB] Partial loan payment: %u RUB, penalty applied, debt: %u RUB\n",
                   env.date, env.alice.money, partial, env.alice.loan.debt);
        }
    }    
}


void consider_alice_loan_extra_payment()
{
    int early_repay = rand() % 100;
    if (early_repay < 10
        && env.alice.loan.debt > 0
        && env.alice.money > env.alice.loan.monthly_payment * 3) {
        Rubles extra = env.alice.loan.monthly_payment * 2; /* double monthly payment extra */
        if (extra > env.alice.money) extra = env.alice.money;
        env.alice.money -= extra;
        if (extra >= env.alice.loan.debt) {
            extra = env.alice.loan.debt;
            env.alice.loan.debt = 0;
            printf("[Month %u] [Alice] [Balance %u RUB] Early repayment closed loan: %u RUB\n",
                   env.date, env.alice.money, extra);
        } else {
            env.alice.loan.debt -= extra;
            printf("[Month %u] [Alice] [Balance %u RUB] Early loan repayment: %u RUB, remaining debt: %u RUB\n",
                   env.date, env.alice.money, extra, env.alice.loan.debt);
        }
    }
}


void consider_alice_loan_occasional_rate_adjust()
{
    int rate_change = rand() % 100;
    if (rate_change < 6) {
        Percent change = (rand() % 2) - 0.5;
        env.alice.loan.bank_interest += change;
        if (env.alice.loan.bank_interest < 0.5) env.alice.loan.bank_interest = 0.5;
        if (env.alice.loan.bank_interest > 10.0) env.alice.loan.bank_interest = 10.0;
        printf("[Month %u] [Alice] [Balance %u RUB] Loan interest rate changed to %.1f%%\n",
               env.date, env.alice.money, env.alice.loan.bank_interest);
    }
}


void consider_alice_loan_mental_influence()
{
    if (env.alice.loan.debt > env.alice.loan.monthly_payment * 6) { /* high debt relative to payment */
        env.alice.sanity.mental.life_burden = env.alice.sanity.mental.life_burden + 0.5;
        if (env.alice.sanity.mental.life_burden > 100) env.alice.sanity.mental.life_burden = 100;
    }

    if (env.alice.loan.debt == 0 && env.alice.mortgage.debt == 0) {
        env.alice.sanity.mental.life_burden = env.alice.sanity.mental.life_burden - 2.0;
        if (env.alice.sanity.mental.life_burden < 0) env.alice.sanity.mental.life_burden = 0;
    }    
}


void consider_alice_proteins_needs()
{
    Rubles protein_cost = env.alice.nutrition.proteins.price * env.alice.nutrition.proteins.portions;
    if (env.alice.money >= protein_cost) {
        env.alice.money -= protein_cost;
        env.alice.sanity.physical.hunger -= env.alice.nutrition.proteins.saturation_points
                                            * env.alice.nutrition.proteins.portions;
        env.alice.sanity.physical.disease -= env.alice.nutrition.proteins.healthyness / 2;
        printf("[Month %u] [Alice] [Balance %u RUB] Bought proteins for %u RUB, hunger reduced\n",
               env.date, env.alice.money, protein_cost);
    } else {
        env.alice.sanity.physical.hunger = env.alice.sanity.physical.hunger + 5;
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot afford proteins (%u RUB), hunger increasing\n",
               env.date, env.alice.money, protein_cost);
    }
}


void consider_alice_fats_needs()
{
    Rubles fat_cost = env.alice.nutrition.fats.price * env.alice.nutrition.fats.portions;
    if (env.alice.money >= fat_cost) {
        env.alice.money -= fat_cost;
        env.alice.sanity.physical.hunger -= env.alice.nutrition.fats.saturation_points
                                            * env.alice.nutrition.fats.portions;
        env.alice.sanity.physical.disease -= env.alice.nutrition.fats.healthyness / 2;
        printf("[Month %u] [Alice] [Balance %u RUB] Bought fats for %u RUB, hunger reduced\n",
               env.date, env.alice.money, fat_cost);
    } else {
        env.alice.sanity.physical.hunger = env.alice.sanity.physical.hunger + 5;
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot afford fats (%u RUB), hunger increasing\n",
               env.date, env.alice.money, fat_cost);
    }
}


void consider_alice_carbohydrates_needs()
{
    Rubles carb_cost = env.alice.nutrition.carbohydrates.price * env.alice.nutrition.carbohydrates.portions;
    if (env.alice.money >= carb_cost) {
        env.alice.money -= carb_cost;
        env.alice.sanity.physical.hunger -= env.alice.nutrition.carbohydrates.saturation_points
                                            * env.alice.nutrition.carbohydrates.portions;
        env.alice.sanity.physical.disease -= env.alice.nutrition.carbohydrates.healthyness / 2;
        printf("[Month %u] [Alice] [Balance %u RUB] Bought carbohydrates for %u RUB, hunger reduced\n",
               env.date, env.alice.money, carb_cost);
    } else {
        env.alice.sanity.physical.hunger = env.alice.sanity.physical.hunger + 5;
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot afford carbohydrates (%u RUB), hunger increasing\n",
               env.date, env.alice.money, carb_cost);
    }
}


void consider_alice_recreation_walking()
{
    if (env.alice.money >= env.alice.recreation.walk.price) {
        env.alice.money -= env.alice.recreation.walk.price;
        env.alice.sanity.mental.loneliness += env.alice.recreation.walk.recreation_points * 100;
        env.alice.sanity.physical.fatigue += env.alice.recreation.walk.tiredness;
        printf("[Month %u] [Alice] [Balance %u RUB] Went for a walk; spent %u RUB\n",
               env.date, env.alice.money, env.alice.recreation.walk.price);
    }
}


void consider_alice_recreation_amusement_park()
{
    if (env.alice.money >= env.alice.recreation.amusement_park.price) {
        env.alice.money -= env.alice.recreation.amusement_park.price;
        env.alice.sanity.mental.loneliness -= env.alice.recreation.amusement_park.recreation_points * 100;
        env.alice.sanity.mental.life_monotony -= env.alice.recreation.amusement_park.recreation_points * 100;
        env.alice.sanity.physical.fatigue += env.alice.recreation.amusement_park.tiredness;
        printf("[Month %u] [Alice] [Balance %u RUB] Visited amusement park; spent %u RUB\n",
               env.date, env.alice.money, env.alice.recreation.amusement_park.price);
    }
}


void consider_alice_recreation_videogames()
{
    if (env.alice.money >= env.alice.recreation.videogames.price) {
        env.alice.money -= env.alice.recreation.videogames.price;
        env.alice.sanity.mental.life_monotony -= env.alice.recreation.videogames.recreation_points * 100;
        env.alice.sanity.mental.dementia -= env.alice.recreation.videogames.recreation_points * 50;
        env.alice.sanity.physical.fatigue += env.alice.recreation.videogames.tiredness;
        printf("[Month %u] [Alice] [Balance %u RUB] Played videogames; spent %u RUB\n",
               env.date, env.alice.money, env.alice.recreation.videogames.price);
    }
}


void consider_alice_recreation_reading()
{
    if (env.alice.money >= env.alice.recreation.reading.price) {
        env.alice.money -= env.alice.recreation.reading.price;
        env.alice.sanity.mental.brain_integrity += env.alice.recreation.reading.recreation_points * 100;
        env.alice.sanity.mental.intelligence_quotient += env.alice.recreation.reading.recreation_points * 10;
        env.alice.sanity.physical.fatigue += env.alice.recreation.reading.tiredness;
        printf("[Month %u] [Alice] [Balance %u RUB] Passed time reading; spent %u RUB\n",
               env.date, env.alice.money, env.alice.recreation.reading.price);
    }
}


void consider_alice_recreation_friends()
{
    if (env.alice.money >= env.alice.recreation.friends_meeting.price) {
        env.alice.money -= env.alice.recreation.friends_meeting.price;
        env.alice.sanity.mental.loneliness -= env.alice.recreation.friends_meeting.recreation_points * 100;
        env.alice.sanity.mental.life_monotony -= env.alice.recreation.friends_meeting.recreation_points * 50;
        env.alice.sanity.physical.fatigue += env.alice.recreation.friends_meeting.tiredness;
        printf("[Month %u] [Alice] [Balance %u RUB] Met friends for %u RUB\n",
               env.date, env.alice.money, env.alice.recreation.friends_meeting.price);
    }
}


void consider_alice_recreation_art_gallery_visit()
{
    if (env.alice.money >= env.alice.recreation.art_gallery.price) {
        env.alice.money -= env.alice.recreation.art_gallery.price;
        env.alice.sanity.mental.life_monotony -= env.alice.recreation.art_gallery.recreation_points * 100;
        env.alice.sanity.mental.intelligence_quotient += env.alice.recreation.art_gallery.recreation_points * 5;
        env.alice.sanity.physical.fatigue += env.alice.recreation.art_gallery.tiredness;
        printf("[Month %u] [Alice] [Balance %u RUB] Visited art gallery for %u RUB\n",
               env.date, env.alice.money, env.alice.recreation.art_gallery.price);
    }
}


void consider_alice_headache_change()
{
    env.alice.sanity.physical.headache += env.alice.sanity.physical.fatigue / 10.0
                                       +  env.alice.sanity.mental.life_burden / 20.0;
      
    if (env.alice.sanity.physical.headache > 100)
        env.alice.sanity.physical.headache = 100;
    if (env.alice.sanity.physical.headache < 0)
        env.alice.sanity.physical.headache = 0;    
}


void consider_alice_hunger_change()
{
    env.alice.sanity.physical.hunger += 8; /* base monthly hunger increase */
    
    if (env.alice.sanity.physical.hunger > 100)
        env.alice.sanity.physical.hunger = 100;
    if (env.alice.sanity.physical.hunger < 0)
        env.alice.sanity.physical.hunger = 0;    
}


void consider_alice_fatigue_change()
{
    env.alice.sanity.physical.fatigue += env.alice.sanity.mental.loneliness / 5.0; /* loneliness reduces rest quality */

    if (env.alice.sanity.physical.fatigue < 0)
        env.alice.sanity.physical.fatigue = 0;
    if (env.alice.sanity.physical.fatigue > 100)
        env.alice.sanity.physical.fatigue = 100;
}


void consider_alice_ill()
{
    Percent disease_risk = + env.alice.sanity.physical.hunger / 5.0
                           + env.alice.sanity.physical.fatigue / 10.0
                           + env.alice.sanity.mental.dementia / 15.0;
    
    int illness_check = rand() % 100;
    if (illness_check < (int) disease_risk) {
        env.alice.sanity.physical.disease = env.alice.sanity.physical.disease + 15;
        printf("[Month %u] [Alice] [Balance %u RUB] Got sick, disease increased to %.1f%%\n",
               env.date, env.alice.money, env.alice.sanity.physical.disease);
    }

    
    if (env.alice.sanity.physical.disease > 50) { /* serious illness */
        env.alice.sanity.mental.life_burden = env.alice.sanity.mental.life_burden + 2;
        env.alice.sanity.physical.fatigue = env.alice.sanity.physical.fatigue + 3;
    }
}


void consider_alice_immunity_action()
{
    env.alice.sanity.physical.disease -= 3; /* natural recovery */
    
    if (env.alice.sanity.physical.disease < 0)
        env.alice.sanity.physical.disease = 0;
    if (env.alice.sanity.physical.disease > 100)
        env.alice.sanity.physical.disease = 100;
}


void consider_alice_loneliness_flow()
{
    env.alice.sanity.mental.loneliness += 5; /* base monthly increase */
    
    if (env.alice.job.symbolics.stage == Fired && env.alice.job.csail.stage == Fired) {
        env.alice.sanity.mental.loneliness += 3; /* isolation from unemployment */
    }
    
    if (env.alice.sanity.mental.loneliness > 100)
        env.alice.sanity.mental.loneliness = 100;
    if (env.alice.sanity.mental.loneliness < 0)
        env.alice.sanity.mental.loneliness = 0;
}


void consider_alice_life_monotony_flow()
{
    env.alice.sanity.mental.life_monotony += 4;
    
    if (env.alice.education.mit.grade <= DoctorateYear4) {
        env.alice.sanity.mental.life_monotony -= 2; /* study brings variety */
    }
    
    if (env.alice.sanity.mental.life_monotony > 100)
        env.alice.sanity.mental.life_monotony = 100;
    if (env.alice.sanity.mental.life_monotony < 0)
        env.alice.sanity.mental.life_monotony = 0;
}


void consider_alice_dementia_flow()
{
    env.alice.sanity.mental.dementia += + env.alice.sanity.mental.life_monotony * 0.03
                                        + (100 - env.alice.sanity.mental.brain_integrity) * 0.09
                                        + (env.date - env.alice.birthdate) * 0.01;
    
    if (env.alice.sanity.mental.dementia > 100)
        env.alice.sanity.mental.dementia = 100;
    if (env.alice.sanity.mental.dementia < 0)
        env.alice.sanity.mental.dementia = 0;
}


void consider_alice_intelligence_flow()
{
    env.alice.sanity.mental.intelligence_quotient += + (100 - env.alice.sanity.mental.dementia) / 20.0
                                                     - env.alice.sanity.physical.fatigue / 15.0;
    
    if (env.alice.sanity.mental.intelligence_quotient > 200)
        env.alice.sanity.mental.intelligence_quotient = 200;
    if (env.alice.sanity.mental.intelligence_quotient < 30)
        env.alice.sanity.mental.intelligence_quotient = 30;
}


void consider_alice_gas_payment()
{
    Rubles gas_payment = env.alice.monthly_utility.gas;
    
    if (env.alice.money >= gas_payment) {
        env.alice.money -= gas_payment;
        printf("[Month %u] [Alice] [Balance %u RUB] Paid gas: %u RUB\n",
               env.date, env.alice.money, gas_payment);
    } else {
        env.alice.monthly_utility.gas *= 1.1; /* 10% late fee */
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot pay gas; debt increased to %u RUB\n",
               env.date, env.alice.money, env.alice.monthly_utility.gas);
    }
}


void consider_alice_warm_water_payment()
{
    Rubles warm_water_payment = env.alice.monthly_utility.warm_water;
    
    if (env.alice.money >= warm_water_payment) {
        env.alice.money -= warm_water_payment;
        printf("[Month %u] [Alice] [Balance %u RUB] Paid warm water: %u RUB\n",
               env.date, env.alice.money, warm_water_payment);
    } else {
        env.alice.monthly_utility.warm_water *= 1.1; /* 10% late fee */
        env.alice.sanity.physical.disease = env.alice.sanity.physical.disease + 2; /* no hot water */
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot pay warm water, debt increased to %u RUB\n",
               env.date, env.alice.money, env.alice.monthly_utility.warm_water);
    }
}


void consider_alice_cold_water_payment()
{
    Rubles cold_water_payment = env.alice.monthly_utility.cold_water;
    
    if (env.alice.money >= cold_water_payment) {
        env.alice.money -= cold_water_payment;
        printf("[Month %u] [Alice] [Balance %u RUB] Paid cold water: %u RUB\n",
               env.date, env.alice.money, cold_water_payment);
    } else {
        env.alice.monthly_utility.cold_water *= 1.1; /* 10% late fee */
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot pay cold water, debt increased to %u RUB\n",
               env.date, env.alice.money, env.alice.monthly_utility.cold_water);
    }
}


void consider_alice_electricity_payment()
{
    Rubles electricity_payment = env.alice.monthly_utility.electricity;
    
    if (env.alice.money >= electricity_payment) {
        env.alice.money -= electricity_payment;
        printf("[Month %u] [Alice] [Balance %u RUB] Paid electricity: %u RUB\n",
               env.date, env.alice.money, electricity_payment);
    } else {
        env.alice.monthly_utility.electricity *= 1.1; /* 10% late fee */
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot pay electricity, debt increased to %u RUB\n",
               env.date, env.alice.money, env.alice.monthly_utility.electricity);
    }
}


void consider_alice_church_donation()
{
    Rubles church_donation = env.alice.monthly_charity.for_church;
    
    if (env.alice.money >= church_donation) {
        env.alice.money -= church_donation;
        env.alice.sanity.mental.life_burden -= 2; /* spiritual relief */
        printf("[Month %u] [Alice] [Balance %u RUB] Donated to church: %u RUB\n",
               env.date, env.alice.money, church_donation);
    } else {
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot donate to church\n",
               env.date, env.alice.money);
    }
}


void consider_orphans_donation()
{
    Rubles orphans_donation = env.alice.monthly_charity.for_orphans;
    
    if (env.alice.money >= orphans_donation) {
        env.alice.money -= orphans_donation;
        env.alice.sanity.mental.loneliness -= 0.8; /* social connection */
        printf("[Month %u] [Alice] [Balance %u RUB] Donated to orphans: %u RUB\n",
               env.date, env.alice.money, orphans_donation);
    } else {
        env.alice.sanity.mental.life_burden += 0.3; /* conscience (?) guilt */
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot donate to orphans\n",
               env.date, env.alice.money);
    }
}


void consider_alice_cancer_patients_donation()
{
    Rubles cancer_donation = env.alice.monthly_charity.for_cancer_patients;
    
    if (env.alice.money >= cancer_donation) {
        env.alice.money -= cancer_donation;
        env.alice.sanity.mental.life_burden -= 2.3;
        printf("[Month %u] [Alice] [Balance %u RUB] Donated to cancer patients: %u RUB\n",
               env.date, env.alice.money, cancer_donation);
    } else {
        env.alice.sanity.mental.life_burden += 1.9; /* conscience (?) guilt */
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot donate to cancer patients\n",
               env.date, env.alice.money);
    }
}


void consider_alice_life_prolongation_research_donation()
{
    Rubles research_donation = env.alice.monthly_charity.for_life_prolongation_researches;
    if (env.alice.money >= research_donation) {
        env.alice.money -= research_donation;        
        env.alice.sanity.mental.life_monotony -= 5.3;
        printf("[Month %u] [Alice] [Balance %u RUB] Donated to life prolongation research: %u RUB\n",
               env.date, env.alice.money, research_donation);
    } else {        
        env.alice.sanity.mental.life_burden += 0.4;
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot donate to life prolongarion research\n",
               env.date, env.alice.money);
    }
}


void consider_alice_charity_flow()
{
    int adjust_charity = rand() % 100;

    if (adjust_charity < 15) {
        int change = (rand() % 201) - 100;
        
        env.alice.monthly_charity.for_church += change * 0.95;
        if (env.alice.monthly_charity.for_church < 100)
            env.alice.monthly_charity.for_church = 100;
        if (env.alice.monthly_charity.for_church > 5000)
            env.alice.monthly_charity.for_church = 5000;

        env.alice.monthly_charity.for_orphans += change * 1.4;
        if (env.alice.monthly_charity.for_orphans < 50)
            env.alice.monthly_charity.for_orphans = 50;
        if (env.alice.monthly_charity.for_orphans > 3000)
            env.alice.monthly_charity.for_orphans = 3000;
        
        env.alice.monthly_charity.for_cancer_patients += change * 2.4;
        if (env.alice.monthly_charity.for_cancer_patients < 200)
            env.alice.monthly_charity.for_cancer_patients = 200;
        if (env.alice.monthly_charity.for_cancer_patients > 4000)
            env.alice.monthly_charity.for_cancer_patients = 4000;

        env.alice.monthly_charity.for_life_prolongation_researches += change * 3.1;
        if (env.alice.monthly_charity.for_orphans < 25)
            env.alice.monthly_charity.for_orphans = 25;
        if (env.alice.monthly_charity.for_orphans > 6000)
            env.alice.monthly_charity.for_orphans = 6000;
    }
}


void consider_alice_odp_operator_payment()
{
    Rubles salary = env.alice.odp.operator_salary;
    
    if (env.alice.money >= salary) {
        env.alice.money -= salary;
        printf("[Month %u] [Alice] [Balance %u RUB] Paid ODP operator salary: %u RUB\n",
               env.date, env.alice.money, salary);
    } else {
        env.alice.odp.operator_salary *= 1.05; /* 5% penalty for late payment */
        env.alice.odp.orders_flaw_rate += 3; /* unmotivated staff */
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot pay operator salary, increased to %u RUB\n",
               env.date, env.alice.money, env.alice.odp.operator_salary);
    }
}


void consider_alice_odp_operator_performance_bonus()
{
    int performance_rating = 100 - (int) env.alice.odp.orders_flaw_rate;
    int raise_trigger = rand() % 100;
    
    if (raise_trigger < 20 && performance_rating > 80) {
        env.alice.odp.operator_salary *= 1.05; /* 5% raise */
        printf("[Month %u] [Alice] [Balance %u RUB] Operator got a raise to %u RUB\n",
               env.date, env.alice.money, env.alice.odp.operator_salary);
    }
}


void consieder_alice_odp_cleaner_payment()
{
    Rubles salary = env.alice.odp.cleaner_salary;
    
    if (env.alice.money >= salary) {
        env.alice.money -= salary;
        printf("[Month %u] [Alice] [Balance %u RUB] Paid ODP cleaner salary: %u RUB\n",
               env.date, env.alice.money, salary);
    } else {
        env.alice.odp.cleaner_salary *= 1.05; /* 5% penalty for late payment */
        env.alice.sanity.physical.disease = env.alice.sanity.physical.disease + 1; /* dirty workplace */
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot pay cleaner salary, increased to %u RUB\n",
               env.date, env.alice.money, env.alice.odp.cleaner_salary);
    }
}


void consider_alice_odb_cleaner_performance_bonus()
{
    int cleanliness_rating = 100 - (int) env.alice.odp.orders_flaw_rate;
    
    int raise_trigger = rand() % 100;
    if (raise_trigger < 18 && cleanliness_rating > 75) {
        env.alice.odp.cleaner_salary *= 1.05; /* 5% raise */
        printf("[Month %u] [Alice] [Balance %u RUB] Cleaner got a raise to %u RUB\n",
               env.date, env.alice.money, env.alice.odp.cleaner_salary);
    }
}


void consider_alice_odp_place_rent_payment()
{
    Rubles rent = env.alice.odp.place_monthly_rent;
    if (env.alice.money >= rent) {
        env.alice.money -= rent;
        printf("[Month %u] [Alice] [Balance %u RUB] Paid ODP place rent: %u RUB\n",
               env.date, env.alice.money, rent);
    } else {
        env.alice.odp.place_monthly_rent *= 1.1; /* 10% late fee */
        env.alice.odp.orders_flaw_rate += 2;
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot pay ODP rent, increased to %u RUB\n",
               env.date, env.alice.money, env.alice.odp.place_monthly_rent);
    }
}


void consider_alice_odp_place_rent_flow()
{
    int market_change = rand() % 100;
    if (market_change < 12) {
        int change = (rand() % 10001) - 3000;
        env.alice.odp.place_monthly_rent += change;
        if (env.alice.odp.place_monthly_rent < 15000)
            env.alice.odp.place_monthly_rent = 15000;
        if (env.alice.odp.place_monthly_rent > 80000)
            env.alice.odp.place_monthly_rent = 80000;
        printf("[Month %u] [Alice] [Balance %u RUB] ODP rent adjusted to %u RUB\n",
               env.date, env.alice.money, env.alice.odp.place_monthly_rent);
    }
}


void consider_alice_odp_firm_fee_payment()
{
    Percent firm_share = env.alice.odp.firm_interest / 100.0;
    Rubles monthly_revenue = env.alice.odp.average_order_cost * 50; /* estimate 50 orders per month */
    Rubles firm_payment = (Rubles)(monthly_revenue * firm_share);
    if (env.alice.money >= firm_payment) {
        env.alice.money -= firm_payment;
        printf("[Month %u] [Alice] [Balance %u RUB] Paid ODP firm fees: %u RUB\n",
               env.date, env.alice.money, firm_payment);
    } else {
        env.alice.money -= env.alice.money;
        env.alice.odp.firm_interest += 1.3; /* penalty rate increase */
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot pay firm fees, interest increased to %.1f%%\n",
               env.date, env.alice.money, env.alice.odp.firm_interest);
    }
}


void consider_alice_odp_firm_fee_renegotiation()
{
    int firm_negotiation = rand() % 100;
    if (firm_negotiation < 8) {
        Percent rate_change = (rand() % 5) - 2;
        env.alice.odp.firm_interest += rate_change;
        if (env.alice.odp.firm_interest < 3)
            env.alice.odp.firm_interest = 3;
        if (env.alice.odp.firm_interest > 30)
            env.alice.odp.firm_interest = 30;
        printf("[Month %u] [Alice] [Balance %u RUB] Firm interest rate changed to %.1f%%\n",
               env.date, env.alice.money, env.alice.odp.firm_interest);
    }
}


void consider_alice_odp_performance_bonus()
{
    
    Percent performance = 100.0 - env.alice.odp.orders_flaw_rate;
    if (performance > 90) { /* excellent performance bonus */
        Rubles bonus = env.alice.odp.average_order_cost * 3; /* bonus equal to 3 orders */
        env.alice.money = env.alice.money + bonus;
        printf("[Month %u] [Alice] [Balance %u RUB] Received ODP performance bonus: %u RUB\n",
               env.date, env.alice.money, bonus);
    }
}


void consider_alice_odp_audit()
{
    int audit_trigger = rand() % 100;
    if (audit_trigger < 5) { /* 5% chance of audit */
        if (env.alice.odp.orders_flaw_rate > 20) {
            Rubles audit_penalty = env.alice.odp.average_order_cost * 10; /* penalty for violations */
            env.alice.money -= audit_penalty;
            printf("[Month %u] [Alice] [Balance %u RUB] Audit found violations, fined %u RUB\n",
                   env.date, env.alice.money, audit_penalty);
        } else {
            printf("[Month %u] [Alice] [Balance %u RUB] Audit passed successfully\n",
                   env.date, env.alice.money);
        }
    }
}


void consider_alice_odp_mental_influence()
{
    if (env.alice.odp.firm_interest > 20) { /* high fees stress */
        env.alice.sanity.mental.life_burden += 0.5;
        if (env.alice.sanity.mental.life_burden > 100)
            env.alice.sanity.mental.life_burden = 100;
        else
            printf("[Month %u] [Alice] [Balance %u RUB] High firm interest made life burden change to %.1f%%\n",
                   env.date, env.alice.money,
                   env.alice.sanity.mental.life_burden);
    }
}


void consider_alice_odp_order_flaw_increase()
{
    int flaw_occurrence = rand() % 100;
    if (flaw_occurrence < (int) env.alice.odp.orders_flaw_rate) {
        env.alice.odp.orders_flaw_rate += 2;
        env.alice.odp.average_order_cost *= 0.95; /* 5% value loss */
        printf("[Month %u] [Alice] [Balance %u RUB] Order flaw occurred, rate now %.1f%%, cost reduced to %u RUB\n",
               env.date, env.alice.money, env.alice.odp.orders_flaw_rate, env.alice.odp.average_order_cost);
    }
}


void consider_alice_odp_order_flaw_mend()
{
    int operator_fix = rand() % 100;
    if (operator_fix < 40) { /* operator can fix up to 40% of flaws */
        env.alice.odp.orders_flaw_rate -= 1.5;
        printf("[Month %u] [Alice] [Balance %u RUB] Operator fixed some delivery & storing flaws, rate decreased to %.1f%%\n",
               env.date, env.alice.money, env.alice.odp.orders_flaw_rate);
    }
}


void consider_alice_odp_service_quality_investment()
{
    int quality_investment = rand() % 100;
    if (quality_investment < 10 && env.alice.money >= 5000) {
        env.alice.money -= 5000;
        env.alice.odp.orders_flaw_rate -= 3;
        printf("[Month %u] [Alice] [Balance %u RUB] Invested 5000 RUB in quality improvement\n",
               env.date, env.alice.money);
    }
}


void consider_alice_odp_ratings_loss()
{
    if (env.alice.odp.orders_flaw_rate > 50) {
        env.alice.odp.average_order_cost *= 0.90; /* reputational losses */
        env.alice.sanity.mental.life_burden += 3;
        printf("[Month %u] [Alice] [Balance %u RUB] High flaw level, ODP reputation damaged\n",
               env.date, env.alice.money);
    }
}


void consider_alice_odp_internet_payment()
{
    Rubles internet_payment = env.alice.odp.monthly_internet_payment;
    if (env.alice.money >= internet_payment) {
        env.alice.money -= internet_payment;
        printf("[Month %u] [Alice] [Balance %u RUB] Paid ODP internet: %u RUB\n",
               env.date, env.alice.money, internet_payment);
    } else {
        env.alice.odp.monthly_internet_payment *= 1.1; /* 10% late fee */
        env.alice.odp.orders_flaw_rate += 10; /* poor internet connectivity */
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot pay internet, flaw rate increased to %.1f%%\n",
               env.date, env.alice.money, env.alice.odp.orders_flaw_rate);
    }
}


void consider_alice_odp_internet_cost_change()
{
    int provider_change = rand() % 100;
    if (provider_change < 10) {
        int tariff_change = (rand() % 1001) - 300;
        env.alice.odp.monthly_internet_payment += tariff_change;
        if (env.alice.odp.monthly_internet_payment < 500)
            env.alice.odp.monthly_internet_payment = 500;
        if (env.alice.odp.monthly_internet_payment > 5000)
            env.alice.odp.monthly_internet_payment = 5000;
        printf("[Month %u] [Alice] [Balance %u RUB] Internet tariff changed to %u RUB\n",
               env.date, env.alice.money, env.alice.odp.monthly_internet_payment);
    }
}


void consider_alice_odp_internet_upgrade()
{
    int upgrade_trigger = rand() % 100;
    if (upgrade_trigger < 5 && env.alice.money >= env.alice.odp.monthly_internet_payment * 2) {
        env.alice.odp.monthly_internet_payment *= 1.25;
        env.alice.odp.average_order_cost *= 1.33;
        printf("[Month %u] [Alice] [Balance %u RUB] Upgraded internet speed, cost now %u RUB\n",
               env.date, env.alice.money, env.alice.odp.monthly_internet_payment);
    }
}


void consider_alice_odp_internet_unreliability()
{    
    if (env.alice.odp.monthly_internet_payment < 800) { /* cheap internet is unreliable */
        int outage_risk = rand() % 100;
        if (outage_risk < 15) {
            env.alice.odp.orders_flaw_rate += 3;
            printf("[Month %u] [Alice] [Balance %u RUB] Internet outage occurred, flaws increased\n",
                   env.date, env.alice.money);
        }
    }
}


void consider_alice_pet_nourish()
{
    Rubles food_cost = 1500; /* base pet food cost */
    if (env.alice.money >= food_cost) {
        env.alice.money -= food_cost;
        env.alice.pet.hunger -= 25;
        if (env.alice.pet.hunger < 0)
            env.alice.pet.hunger = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Fed pet for %u RUB, hunger now %.1f%%\n",
               env.date, env.alice.money, food_cost, env.alice.pet.hunger);
    } else {
        env.alice.pet.hunger += 15;
        printf("[Month %u] [Alice] [Balance %u RUB] Cannot afford pet food, hunger increased to %.1f%%\n",
               env.date, env.alice.money, env.alice.pet.hunger);
    }
}


void consider_alice_pet_treat()
{
    int treat_trigger = rand() % 100;
    if (treat_trigger < 20 && env.alice.money >= 800) {
        env.alice.money -= 800;
        env.alice.pet.loneliness -= 10;
        env.alice.pet.hunger -= 5;
        if (env.alice.pet.loneliness < 0)
            env.alice.pet.loneliness = 0;
        if (env.alice.pet.hunger < 0)
            env.alice.pet.hunger = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Bought pet treats for 800 RUB\n",
               env.date, env.alice.money);
    }
}


void consider_alice_pet_hunger_increase()
{
    env.alice.pet.hunger += 8; /* natural hunger increase */
    if (env.alice.pet.hunger > 100)
        env.alice.pet.hunger = 100;
}


void consider_alice_pet_hunger_mental_effect()
{
    if (env.alice.pet.hunger > 80) { /* severe hunger */
        env.alice.sanity.mental.life_burden += 2; /* guilt */
        if (env.alice.sanity.mental.life_burden > 100)
            env.alice.sanity.mental.life_burden = 100;
    }
}


void consider_alice_pet_play()
{
    int play_time = rand() % 100;
    if (play_time < 55) {
        env.alice.pet.loneliness -= 20;
        env.alice.sanity.mental.loneliness -= 3;
        env.alice.sanity.mental.life_monotony -= 2;
        if (env.alice.pet.loneliness < 0)
            env.alice.pet.loneliness = 0;
        if (env.alice.sanity.mental.loneliness < 0)
            env.alice.sanity.mental.loneliness = 0;
        if (env.alice.sanity.mental.life_monotony < 0)
            env.alice.sanity.mental.life_monotony = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Played with pet, loneliness decreased\n",
               env.date, env.alice.money);
    }
}


void consider_alice_pet_buy_toy()
{
    int toy_trigger = rand() % 100;
    if (toy_trigger < 15 && env.alice.money >= 1200) {
        env.alice.money -= 1200;
        env.alice.pet.loneliness -= 15;
        if (env.alice.pet.loneliness < 0)
            env.alice.pet.loneliness = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Bought pet toys for 1200 RUB\n",
               env.date, env.alice.money);
    }
}


void consider_alice_pet_walking()
{
    int walk_trigger = rand() % 100;
    if (walk_trigger < 35) {
        env.alice.pet.loneliness -= 10;
        env.alice.sanity.physical.fatigue -= 5;
        env.alice.sanity.mental.life_monotony -= 1;
        if (env.alice.pet.loneliness < 0)
            env.alice.pet.loneliness = 0;
        if (env.alice.sanity.physical.fatigue < 0)
            env.alice.sanity.physical.fatigue = 0;
        if (env.alice.sanity.mental.life_monotony < 0)
            env.alice.sanity.mental.life_monotony = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Walked with pet\n",
               env.date, env.alice.money);
    }
}


void consider_alice_pet_loneliness_flow()
{
    env.alice.pet.loneliness += 7; /* natural loneliness increase */
    if (env.alice.pet.loneliness > 100)
        env.alice.pet.loneliness = 100;
}


void consider_alice_pet_depression()
{
    if (env.alice.pet.loneliness > 70) { /* pet is very lonely */
        env.alice.pet.disease += 3; /* depression affects health */
        if (env.alice.pet.disease > 100)
            env.alice.pet.disease = 100;
    }
}


void consider_alice_pet_buy_medicine()
{
    int medicine_trigger = rand() % 100;
    if (medicine_trigger < 14
        && env.alice.pet.disease > 20
        && env.alice.money >= 2000) {
        
        env.alice.money -= 2000;
        env.alice.pet.disease -= 15;
        if (env.alice.pet.disease < 0)
            env.alice.pet.disease = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Bought pet medicine for 2000 RUB\n",
               env.date, env.alice.money);
    }
}


void consider_alice_pet_visit_vet()
{
    int vet_visit = rand() % 100;
    if (vet_visit < 6 && env.alice.money >= 5000) {
        env.alice.money -= 5000;
        env.alice.pet.disease -= 30;
        if (env.alice.pet.disease < 0)
            env.alice.pet.disease = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Vet visit cost 5000 RUB, pet health improved\n",
               env.date, env.alice.money);
    }
}


void consider_alice_pet_disease_flow()
{
    env.alice.pet.disease += + env.alice.pet.hunger * 0.10
                             + env.alice.pet.loneliness * 0.85;
    if (env.alice.pet.disease > 100)
        env.alice.pet.disease = 100;
}


void consider_alice_pet_fatality()
{
    int death_check = rand() % 100;
    Percent death_risk = + env.alice.pet.hunger * 0.50
                         + env.alice.pet.disease * 0.50;
    
    if (death_check < (int) death_risk) {
        env.alice.pet.is_alive = 0;
        env.alice.sanity.mental.loneliness += 20;
        env.alice.sanity.mental.life_burden += 15;
        printf("[Month %u] [Alice] [Balance %u RUB] Pet has died; mental health severely impacted\n",
               env.date, env.alice.money);
    }
}


void consider_alice_pet_natural_convalescence()
{
    env.alice.pet.disease -= 2;
    if (env.alice.pet.disease < 0)
        env.alice.pet.disease = 0;
}


void consider_alice_pet_disease_mental_effect()
{
    if (env.alice.pet.disease > 60) { /* pet is seriously ill */
        env.alice.sanity.mental.life_burden += 0.8;
        if (env.alice.sanity.mental.life_burden > 100)
            env.alice.sanity.mental.life_burden = 100;
    }
}


void consider_alice_car_commuting()
{
    Kilometers distance = 200 + rand() % 800; /* 200-999 km per month */
    Rubles fuel_cost = distance * env.alice.car.fuel_efficiency;
    if (env.alice.money >= fuel_cost) {
        env.alice.money -= fuel_cost;
        env.alice.car.mileage += distance;
        env.alice.car.wear += distance / 100.0;
        if (env.alice.car.wear > 100)
            env.alice.car.wear = 100;
        printf("[Month %u] [Alice] [Balance %u RUB] Car used %u km, fuel cost %u RUB, wear %.1f%%\n",
               env.date, env.alice.money, distance, fuel_cost, env.alice.car.wear);
    } else {
        env.alice.car.mileage += 50; /* critically minimal usage */
        env.alice.car.wear = env.alice.car.wear + 0.3;
        printf("[Month %u] [Alice] [Balance %u RUB] Low fuel, minimal car usage 50 km\n",
               env.date, env.alice.money);
    }
}


void consider_alice_car_wear_effect()
{
    if (env.alice.car.wear > 50) { /* high wear increases fuel consumption */
        env.alice.car.fuel_efficiency *= 0.82; /* 10% worse efficiency */
        if (env.alice.car.fuel_efficiency > 150)
            env.alice.car.fuel_efficiency = 150;
        printf("[Month %u] [Alice] [Balance %u RUB] Car wear effecting fuel efficiency, now %u RUB/km\n",
               env.date, env.alice.money, env.alice.car.fuel_efficiency);
    }
}


void consider_alice_car_accidence()
{
    if (env.alice.car.mileage < 50000) {
        int accident_risk = rand() % 100;
        if (accident_risk < 3) {
            env.alice.car.wear += 30;
            env.alice.sanity.mental.life_burden += 10;
            env.alice.sanity.mental.brain_integrity -= 10;
            printf("[Month %u] [Alice] [Balance %u RUB] Minor accident occurred, wear increased to %.1f%%\n",
                   env.date, env.alice.money, env.alice.car.wear);
        }
    } else {
        int serious_accident_risk = rand() % 100;
        if (serious_accident_risk < 2) {
            env.alice.car.is_exist = 0;
            env.alice.sanity.mental.life_burden += 30;
            env.alice.sanity.mental.brain_integrity -= 40;
            printf("[Month %u] [Alice] [Balance %u RUB] Major accident occurred, car destroyed\n",
                   env.date, env.alice.money);
        }
    }
}


void consider_alice_car_schedule_repair()
{
    if (env.alice.car.wear > 20) {
        Rubles repair_cost = env.alice.car.base_repair_cost * (1 + (Rubles) env.alice.car.wear / 50);
        int repair_trigger = rand() % 100;
        if (repair_trigger < 40 && env.alice.money >= repair_cost) {
            env.alice.money -= repair_cost;
            env.alice.car.wear -= 25;
            if (env.alice.car.wear < 0)
                env.alice.car.wear = 0;
            printf("[Month %u] [Alice] [Balance %u RUB] Car repaired for %u RUB, wear now %.1f%%\n",
                   env.date, env.alice.money, repair_cost, env.alice.car.wear);
        }
    }
}


void consider_alice_car_urgent_repair()
{
    if (env.alice.car.wear > 60) {
        Rubles urgent_cost = env.alice.car.base_repair_cost * 3;
        int urgent_trigger = rand() % 100;
        if (urgent_trigger < 70 && env.alice.money >= urgent_cost) {
            env.alice.money -= urgent_cost;
            env.alice.car.wear -= 40;
            if (env.alice.car.wear < 0)
                env.alice.car.wear = 0;
            printf("[Month %u] [Alice] [Balance %u RUB] Urgent car repair for %u RUB, wear now %.1f%%\n",
                   env.date, env.alice.money, urgent_cost, env.alice.car.wear);
        } else {
            env.alice.car.wear += 5; /* deterioration from neglect */
            printf("[Month %u] [Alice] [Balance %u RUB] Cannot afford urgent repair, wear increased to %.1f%%\n",
                   env.date, env.alice.money, env.alice.car.wear);
        }
    }
}


void consider_alice_car_engine_tuning()
{
    int engine_tune = rand() % 100;
    if (engine_tune < 8 && env.alice.money >= 15000) {
        env.alice.money -= 15000;
        env.alice.car.fuel_efficiency -= 5; /* better efficiency */
        if (env.alice.car.fuel_efficiency < 35)
            env.alice.car.fuel_efficiency = 35;
        printf("[Month %u] [Alice] [Balance %u RUB] Engine tuned for 15000 RUB, efficiency improved to %u RUB/km\n",
               env.date, env.alice.money, env.alice.car.fuel_efficiency);
    }
}


void consider_alice_car_suspension_tuning()
{
    int suspension_tune = rand() % 100;
    if (suspension_tune < 6 && env.alice.money >= 25000) {
        env.alice.money -= 25000;
        env.alice.car.base_repair_cost -= 500; /* less future repairs */
        if (env.alice.car.base_repair_cost < 2000)
            env.alice.car.base_repair_cost = 2000;
        env.alice.car.wear -= 5; /* improved durability */
        if (env.alice.car.wear < 0)
            env.alice.car.wear = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Suspension upgraded for 25000 RUB\n",
               env.date, env.alice.money);
    }
}


void consider_alice_car_interior_tuning()
{
    int interior_tune = rand() % 100;
    if (interior_tune < 10 && env.alice.money >= 4000) {
        env.alice.money -= 4000;
        env.alice.sanity.mental.life_monotony -= 3;
        if (env.alice.sanity.mental.life_monotony < 0)
            env.alice.sanity.mental.life_monotony = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Car comfort upgraded for 8000 RUB\n",
               env.date, env.alice.money);
    }
}


void consider_alice_car_paint()
{
    int paint_job = rand() % 100;
    if (paint_job < 4 && env.alice.money >= 15000) {
        env.alice.money -= 15000;
        env.alice.car.wear -= 8; /* protective cover */
        if (env.alice.car.wear < 0)
            env.alice.car.wear = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Car repainted for 35000 RUB, wear reduced\n",
               env.date, env.alice.money);
    }
}


void consider_food_inflation()
{
    int food_crisis = rand() % 100;
    if (food_crisis < 5) {
        env.alice.nutrition.proteins.price *= 1.30;
        env.alice.nutrition.fats.price *= 1.25;
        env.alice.nutrition.carbohydrates.price *= 1.20;
        printf("[Month %u] Food supply crisis, prices spiked\n",
               env.date);
    } else {
        Percent base_food_inflation = 1 + 0.03 + (rand() % 12) / 100.0;
        env.alice.nutrition.proteins.price *= base_food_inflation;
        env.alice.nutrition.fats.price *= base_food_inflation;
        env.alice.nutrition.carbohydrates.price *= base_food_inflation;
        printf("[Month %u] Food prices increased by %.2f%%; average %u RUB\n",
               env.date, base_food_inflation,
               ( env.alice.nutrition.carbohydrates.price
                 + env.alice.nutrition.fats.price
                 + env.alice.nutrition.proteins.price) / 3);
    }
}


void consider_gas_inflation()
{
    int energy_market_cycle = env.date % 12; /* seasonal pattern */
    
    Rubles gas_change;
    if (energy_market_cycle < 3) {
        gas_change = 30 + rand() % 41; /* winter: +30 to +70 RUB */
    } else if (energy_market_cycle < 6) {
        gas_change = -(20 + rand() % 31); /* spring: -20 to -50 RUB */
    } else if (energy_market_cycle < 9) {
        gas_change = 10 + rand() % 21; /* summer: +10 to +30 RUB */
    } else {
        gas_change = 40 + rand() % 61; /* autumn: +40 to +100 RUB */
    }
    
    env.alice.monthly_utility.gas += gas_change;
    if (env.alice.monthly_utility.gas < 200)
        env.alice.monthly_utility.gas = 200;

    printf("[Month %u] Gas prices changed: %u RUB now\n",
           env.date, env.alice.monthly_utility.gas);
}


void consider_water_inflation()
{
    int water_policy_change = rand() % 100;
    if (water_policy_change < 12) {
        env.alice.monthly_utility.warm_water += 1.08;
        env.alice.monthly_utility.cold_water *= 1.05;
        printf("[Month %u] Water tariff reform, prices increased: %u RUB average now\n",
               env.date, (env.alice.monthly_utility.warm_water
                          + env.alice.monthly_utility.cold_water) / 2);
    }
}


void consider_electicity_inflation()
{
    Percent electricity_inflation = 1 + (rand() % 3) / 100.0;
    env.alice.monthly_utility.electricity *= electricity_inflation;
        
    printf("[Month %u] Electicity prices changed: %u RUB now\n",
           env.date, env.alice.monthly_utility.electricity);
}


void consider_securities_market_inflation()
{
    int market_sentiment = (rand() % 21) - 10; /* -10 to +10 */
    if (market_sentiment > 5) {
        env.alice.securities.yandex.price *= 1 + (rand() % 8) / 100; /* 0-7% growth */
        env.alice.securities.nvidia.price *= 1 + (rand() % 12) / 100; /* 0-11% growth */
    } else if (market_sentiment < -5) {
        env.alice.securities.yandex.price *= 1 - (rand() % 6) / 100; /* 0-5% drop */
        env.alice.securities.nvidia.price *= 1 - (rand() % 9) / 100; /* 0-8% drop */
    } else { /* sideways market */
        env.alice.securities.sberbank.price *= 1 + ((rand() % 5) - 2) / 100; /* -2% to +2% */
    }
    
    if (env.alice.securities.yandex.price < 500)
        env.alice.securities.yandex.price = 500;
    if (env.alice.securities.sberbank.price < 100)
        env.alice.securities.sberbank.price = 100;
    if (env.alice.securities.nvidia.price < 10000)
        env.alice.securities.nvidia.price = 10000;
}


void process_alice_salary()
{
    consider_alice_symbolics_salary();
    consider_alice_symbolics_bonus();
    consider_alice_csail_salary();
    consider_alice_csail_bonus();
    consider_alice_mit_fellowship();
    consider_alice_trade_union_bonus();

    /* printf("Debug\n"); */
}


void process_alice_job_career()
{
    consider_alice_symbolics_promotion();
    consider_alice_csail_promotion();
    
    consider_alice_symbolics_demotion();
    consider_alice_csail_demotion();

    consider_alice_symbolics_work_quality_flow();
    consider_alice_csail_work_quality_flow();
}


void process_alice_scientific_career()
{
    consider_alice_mit_education();
    consider_alice_mit_graduation();
}


void process_alice_investment()
{
    consider_alice_yandex_investment();
    consider_alice_sberbank_investment();
    consider_alice_nvidia_investment();
}


void process_alice_interest()
{
    consider_alice_sberbank_deposit_interest();
    consider_alice_sberbank_deposit_topup();
    consider_alice_alphabank_deposit_interest();
    consider_alice_alphabank_deposit_topup();
}


void process_alice_occasional_income()
{
    consider_alice_lottery_income();
    consider_alice_finds_income();
    consider_alice_heritage_income();
}


void process_alice_currency_playing()
{
    consider_alice_dollars_sell();
    consider_alice_euros_sell();
    consider_alice_yuans_sell();

    consider_alice_dollars_buy();
    consider_alice_euros_buy();
    consider_alice_yuans_buy();
}


void process_alice_mortgage_payments()
{
    consider_alice_mortgage_payment();
    consider_alice_mortgage_extra_payment();
    consider_alice_mortgage_occasional_rate_adjust();
    consider_alice_mortgage_mental_influence();
}


void process_alice_warehouse_payments()
{
    consider_alice_warehouse_rent();
    consider_alice_warehouse_rent_renegotiation();
}


void process_alice_loan_payments()
{
    consider_alice_loan_payment();
    consider_alice_loan_extra_payment();
    consider_alice_loan_occasional_rate_adjust();
    consider_alice_loan_mental_influence();
}


void process_alice_nutrition()
{
    consider_alice_proteins_needs();
    consider_alice_fats_needs();
    consider_alice_carbohydrates_needs();
}


void process_alice_physical_sanity()
{
    consider_alice_headache_change();
    consider_alice_hunger_change();
    consider_alice_fatigue_change();
    consider_alice_ill();
    consider_alice_immunity_action();
}


void process_alice_recreation()
{
    int choice = rand() % 6;

    switch (choice) {
    case 0:
        consider_alice_recreation_walking();
        break;
    case 1:
        consider_alice_recreation_videogames();
        break;
    case 2:
        consider_alice_recreation_reading();
        break;
    case 3:
        consider_alice_recreation_friends();
        break;
    case 4:
        consider_alice_recreation_amusement_park();
        break;
    case 5:
        consider_alice_recreation_art_gallery_visit();
        break;
    }
}


void process_alice_mental_sanity()
{
    consider_alice_loneliness_flow();
    consider_alice_life_monotony_flow();
    consider_alice_dementia_flow();
    consider_alice_intelligence_flow();
    
    printf("[Month %u] [Alice] [Balance %u RUB] Mental state: "
           "loneliness %.1f, monotony %.1f, burden %.1f, dementia %.1f\n",
           env.date, env.alice.money,
           env.alice.sanity.mental.loneliness,
           env.alice.sanity.mental.life_monotony,
           env.alice.sanity.mental.life_burden,
           env.alice.sanity.mental.dementia);
}


void process_alice_utility_payments()
{
    consider_alice_gas_payment();
    consider_alice_warm_water_payment();
    consider_alice_cold_water_payment();
    consider_alice_electricity_payment();
}


void process_alice_charity_payments()
{
    consider_alice_church_donation();
    consider_orphans_donation();
    consider_alice_cancer_patients_donation();
    consider_alice_life_prolongation_research_donation();
    consider_alice_charity_flow();
}


void process_alice_odp_operator_salary()
{
    consider_alice_odp_operator_payment();
    consider_alice_odp_operator_performance_bonus();
}


void process_alice_odp_cleaner_salary()
{
    consieder_alice_odp_cleaner_payment();
    consider_alice_odb_cleaner_performance_bonus();
}


void process_alice_odp_place_rent()
{
    consider_alice_odp_place_rent_payment();
    consider_alice_odp_place_rent_flow();
}


void process_alice_odp_fees()
{
    consider_alice_odp_firm_fee_payment();
    consider_alice_odp_firm_fee_renegotiation();
    consider_alice_odp_performance_bonus();
    consider_alice_odp_audit();
    consider_alice_odp_mental_influence();
}


void process_alice_odp_order_flaw()
{
    consider_alice_odp_order_flaw_increase();
    consider_alice_odp_order_flaw_mend();
    consider_alice_odp_service_quality_investment();
    consider_alice_odp_ratings_loss();
}


void process_alice_odp_internet_payments()
{
    consider_alice_odp_internet_payment();
    consider_alice_odp_internet_cost_change();
    consider_alice_odp_internet_upgrade();
    consider_alice_odp_internet_unreliability();
}



void process_alice_pet_feeding()
{
    if (env.alice.pet.is_alive == 1) {
        consider_alice_pet_nourish();
        consider_alice_pet_treat();
        consider_alice_pet_hunger_increase();
        consider_alice_pet_hunger_mental_effect();
    }
}


void process_alice_pet_playing()
{
    if (env.alice.pet.is_alive == 1) {
        consider_alice_pet_play();
        consider_alice_pet_buy_toy();
        consider_alice_pet_walking();
        consider_alice_pet_loneliness_flow();
        consider_alice_pet_depression();
    }
}


void process_alice_pet_health()
{
    if (env.alice.pet.is_alive == 1) {
        consider_alice_pet_buy_medicine();
        consider_alice_pet_visit_vet();
        consider_alice_pet_disease_flow();
        consider_alice_pet_fatality();
        consider_alice_pet_natural_convalescence();
        consider_alice_pet_disease_mental_effect();
    }
}


void process_alice_car_usage()
{
    if (env.alice.car.is_exist == 1) {
        consider_alice_car_commuting();
        consider_alice_car_wear_effect();
        consider_alice_car_accidence();
    }
}


void process_alice_car_repairment()
{
    if (env.alice.car.is_exist == 1) {
        consider_alice_car_schedule_repair();
        consider_alice_car_urgent_repair();
    }
}


void process_alice_car_tuning()
{
    if (env.alice.car.is_exist == 1) {
        consider_alice_car_engine_tuning();
        consider_alice_car_suspension_tuning();
        consider_alice_car_interior_tuning();
        consider_alice_car_paint();
    }
}



void process_inflation()
{
    consider_food_inflation();
    consider_gas_inflation();
    consider_water_inflation();
    consider_electicity_inflation();
    consider_securities_market_inflation();
}



void (*monthly_simulation[])() = {
    process_alice_salary,
    process_alice_job_career,
    process_alice_scientific_career,

    process_alice_investment,
    process_alice_interest,
    process_alice_occasional_income,
    process_alice_currency_playing,

    process_alice_mortgage_payments,
    process_alice_warehouse_payments,
    process_alice_loan_payments,

    process_alice_nutrition,
    process_alice_recreation,
    process_alice_physical_sanity,
    process_alice_mental_sanity,

    process_alice_utility_payments,
    process_alice_charity_payments,

    /* ODP stands for 'Order Delivery Point' */
    process_alice_odp_operator_salary,
    process_alice_odp_cleaner_salary,
    process_alice_odp_place_rent,
    process_alice_odp_fees,
    process_alice_odp_order_flaw,
    process_alice_odp_internet_payments,

    process_alice_pet_feeding,
    process_alice_pet_playing,
    process_alice_pet_health,

    process_alice_car_usage,
    process_alice_car_repairment,
    process_alice_car_tuning,

    process_inflation,
    
    NULL
};


void print_end_statistics()
{
    Months age_months = env.date - env.alice.birthdate;
    unsigned int age_years = age_months / 12;
    unsigned int age_remaining_months = age_months % 12;

    printf("[END OF SIMULATION] End statistics:\n");

    printf("[Month %u] [Alice] [Balance %u RUB] Age: %u years %u months\n",
           env.date, env.alice.money, age_years, age_remaining_months);

    printf("[Month %u] [Alice] [Balance %u RUB] Job Symbolics: stage %u, salary %u RUB, quality %.1f%%, attitude %.1f%%\n",
           env.date, env.alice.money, env.alice.job.symbolics.stage, env.alice.job.symbolics.salary,
           env.alice.job.symbolics.work_quality, env.alice.job.symbolics.colleagues_attitude);

    printf("[Month %u] [Alice] [Balance %u RUB] Job CSAIL: stage %u, salary %u RUB, quality %.1f%%, attitude %.1f%%\n",
           env.date, env.alice.money, env.alice.job.csail.stage, env.alice.job.csail.salary,
           env.alice.job.csail.work_quality, env.alice.job.csail.colleagues_attitude);

    printf("[Month %u] [Alice] [Balance %u RUB] Education MIT: grade %u, score %.2f, fellowship %u RUB\n",
           env.date, env.alice.money, env.alice.education.mit.grade,
           env.alice.education.mit.average_score, env.alice.education.mit.fellowship);

    printf("[Month %u] [Alice] [Balance %u RUB] Securities: Yandex %u pcs at %u RUB, Sberbank %u pcs at %u RUB, Nvidia %u pcs at %u RUB\n",
           env.date, env.alice.money,
           env.alice.securities.yandex.amount, env.alice.securities.yandex.price,
           env.alice.securities.sberbank.amount, env.alice.securities.sberbank.price,
           env.alice.securities.nvidia.amount, env.alice.securities.nvidia.price);

    printf("[Month %u] [Alice] [Balance %u RUB] Deposits: Sberbank %.1f%% %u RUB, Alphabank %.1f%% %u RUB\n",
           env.date, env.alice.money,
           env.alice.deposits.at_sberbank.interest, env.alice.deposits.at_sberbank.amount,
           env.alice.deposits.at_alphabank.interest, env.alice.deposits.at_alphabank.amount);

    printf("[Month %u] [Alice] [Balance %u RUB] Foreign currencies: USD %u at %u RUB, EUR %u at %u RUB, CNY %u at %u RUB\n",
           env.date, env.alice.money,
           env.alice.foreign_currencies.dollars.amount, env.alice.foreign_currencies.dollars.price,
           env.alice.foreign_currencies.euros.amount, env.alice.foreign_currencies.euros.price,
           env.alice.foreign_currencies.yuans.amount, env.alice.foreign_currencies.yuans.price);

    printf("[Month %u] [Alice] [Balance %u RUB] Physical health: headache %.1f%%, hunger %.1f%%, fatigue %.1f%%, disease %.1f%%\n",
           env.date, env.alice.money,
           env.alice.sanity.physical.headache, env.alice.sanity.physical.hunger,
           env.alice.sanity.physical.fatigue, env.alice.sanity.physical.disease);

    printf("[Month %u] [Alice] [Balance %u RUB] Mental health: loneliness %.1f%%, monotony %.1f%%, burden %.1f%%, dementia %.1f%%, brain integrity %.1f%%, IQ %.1f%%\n",
           env.date, env.alice.money,
           env.alice.sanity.mental.loneliness, env.alice.sanity.mental.life_monotony,
           env.alice.sanity.mental.life_burden, env.alice.sanity.mental.dementia,
           env.alice.sanity.mental.brain_integrity, env.alice.sanity.mental.intelligence_quotient);

    printf("[Month %u] [Alice] [Balance %u RUB] Monthly utility: gas %u RUB, warm water %u RUB, cold water %u RUB, electricity %u RUB, renovation %u RUB\n",
           env.date, env.alice.money,
           env.alice.monthly_utility.gas, env.alice.monthly_utility.warm_water,
           env.alice.monthly_utility.cold_water, env.alice.monthly_utility.electricity,
           env.alice.monthly_utility.renovation_fund);

    printf("[Month %u] [Alice] [Balance %u RUB] Mortgage: debt %u RUB, interest %.1f%%, monthly payment %u RUB\n",
           env.date, env.alice.money,
           env.alice.mortgage.debt, env.alice.mortgage.bank_interest,
           env.alice.mortgage.monthly_payment);

    printf("[Month %u] [Alice] [Balance %u RUB] Loan: debt %u RUB, interest %.1f%%, monthly payment %u RUB\n",
           env.date, env.alice.money,
           env.alice.loan.debt, env.alice.loan.bank_interest,
           env.alice.loan.monthly_payment);

    printf("[Month %u] [Alice] [Balance %u RUB] Warehouse rent: %u RUB/month\n",
           env.date, env.alice.money, env.alice.warehouse_rent.monthly_payment);

    printf("[Month %u] [Alice] [Balance %u RUB] Pet: %s, hunger %.1f%%, disease %.1f%%, loneliness %.1f%%\n",
           env.date, env.alice.money,
           (env.alice.pet.is_alive ? "dead" : "alive"),
           env.alice.pet.hunger,
           env.alice.pet.disease, env.alice.pet.loneliness);

    printf("[Month %u] [Alice] [Balance %u RUB] Car: %s, wear %.1f%%, mileage %u km, repair cost %u RUB, fuel efficiency %u RUB/km\n",
           env.date, env.alice.money,
           (env.alice.car.is_exist ? "in property" : "crashed"),
           env.alice.car.wear, env.alice.car.mileage,
           env.alice.car.base_repair_cost, env.alice.car.fuel_efficiency);

    printf("[Month %u] [Alice] [Balance %u RUB] ODP: orders flaw rate %.1f%%, average order %u RUB, internet %u RUB/month\n",
           env.date, env.alice.money,
           env.alice.odp.orders_flaw_rate, env.alice.odp.average_order_cost,
           env.alice.odp.monthly_internet_payment);

    printf("[Month %u] [Alice] [Balance %u RUB] Trade union: member %d, workage %u months, base payment %u RUB\n",
           env.date, env.alice.money,
           env.alice.trade_union.is_trade_union_member,
           env.alice.trade_union.workage, env.alice.trade_union.base_payment);

    printf("[Month %u] [Alice] [Balance %u RUB] Monthly charity: church %u RUB, orphans %u RUB, cancer %u RUB, life research %u RUB\n",
           env.date, env.alice.money,
           env.alice.monthly_charity.for_church, env.alice.monthly_charity.for_orphans,
           env.alice.monthly_charity.for_cancer_patients, env.alice.monthly_charity.for_life_prolongation_researches);
}


void process_alice_end_conditions()
{
    if (env.alice.money <= 1000
        && env.alice.loan.debt > 0
        && env.alice.mortgage.debt > 0) {
        
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Bankrupt: no money with outstanding debts\n",
               env.date, env.alice.money);
        return;
    }

    if (env.alice.sanity.physical.hunger >= 90) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Died of starvation\n",
               env.date, env.alice.money);
        return;
    }

    if (env.alice.sanity.mental.dementia >= 90) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Lost mind completely: dementia at %.1f%%\n",
               env.date, env.alice.money, env.alice.sanity.mental.dementia);
        return;
    }

    if (env.alice.sanity.mental.brain_integrity <= 10) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Brain critically damaged\n",
               env.date, env.alice.money);
        return;
    }

    if (env.alice.sanity.physical.disease >= 90) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Died from severe disease\n",
               env.date, env.alice.money);
        return;
    }

    if (env.alice.sanity.mental.life_burden >= 90) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Psychological burden became unbearable, gave up on life\n",
               env.date, env.alice.money);
        return;
    }

    if (env.alice.loan.debt <= 100 && env.alice.mortgage.debt <= 100) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Financial freedom achieved: debts paid\n",
               env.date, env.alice.money);
        return;
    }

    if (env.alice.job.symbolics.stage == GeneralDirector
        && env.alice.job.csail.stage == GeneralDirector) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Reached top position at both companies simultaneously\n",
               env.date, env.alice.money);
        return;
    }

    if (env.alice.education.mit.grade > DoctorateYear4
        && env.alice.job.symbolics.stage == Fired
        && env.alice.job.csail.stage == Fired
        && env.alice.money < 1000) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Finished education but unemployable and broke\n",
               env.date, env.alice.money);
        return;
    }
    
    if (env.alice.pet.is_alive == 0
        && env.alice.sanity.mental.loneliness >= 90
        && env.alice.sanity.mental.life_monotony >= 100) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Lost pet and all social connections, complete isolation\n",
               env.date, env.alice.money);
        return;
    }

    if (env.alice.odp.orders_flaw_rate >= 90) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Franchise failed: service quality became terrible\n",
               env.date, env.alice.money);
        return;
    }

    if (env.alice.sanity.mental.intelligence_quotient <= 20) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Severe intellectual degradation, unable to live\n",
               env.date, env.alice.money);
        return;
    }

    if (env.alice.sanity.physical.fatigue >= 90
        && env.alice.sanity.physical.headache >= 90) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Complete physical exhaustion with chronic pain\n",
               env.date, env.alice.money);
        return;
    }
    
    Months age_months = env.date - env.alice.birthdate;
    unsigned int age_years = age_months / 12;
    unsigned int death_risk = (age_years * age_years) / (90 * 90);
    if (death_risk > rand() % 100) {
        env.alice.hangs_on = 0;
        printf("[Month %u] [Alice] [Balance %u RUB] Died at age %u\n",
               env.date, env.alice.money, age_years);
        return;
    }
}


int main()
{
    srand(time(NULL));

    init_environment();

    while (1) {
        int step = 0;
        while ( monthly_simulation[step] != NULL ) {
            ( *monthly_simulation[step] )();
            process_alice_end_conditions();   
            if (!env.alice.hangs_on) goto END;

            ++step;
        }
        
        ++env.date;
    }

    END:

    print_end_statistics();
       
    return 0;
}
