#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using RUB = long long int;
using Percent = float;

struct Bank {
    RUB account;
    RUB deposite;
    Percent interest;
    RUB credit_card;
};

struct Construction {
    RUB beton;
    RUB armatura;
    RUB workers_salary;
    RUB equipment_rent;
    RUB fine;
    RUB bribe;
};

struct Style {
    RUB cosmetics;
    RUB beauty_salon;
    RUB clothes;
    RUB psychology;
    RUB instagram_ads;
};

struct Asset {
    char name[40];
    RUB value;
    RUB repair;
    int type;
};
struct Pet {
    char breed[40];
    RUB food_premium;
    RUB grooming;
    RUB trainer;
    RUB vitamins;
    RUB exhibition_fee;
};

struct Hobby {
    char name[40];
    RUB monthly_subscription;
    RUB equipment_upgrade;
    RUB professional_coach;
};

struct Person {
    Bank vtb;
    Style style;
    Construction business;
    Hobby hobby; 
    RUB salary;
    RUB food;
    RUB total_lost;
    RUB total_won;
};

struct Person gena;
struct Person masha;
Asset gena_assets[10];
int asset_count = 0;
Pet family_dog;

void init() {
    gena.vtb.account = 1000000;
    gena.vtb.deposite = 10000000;
    gena.vtb.interest = 16.0;
    gena.salary = 500000;
    gena.food = 30000;
    gena.business.beton = 100000;
    gena.business.armatura = 150000;
    gena.business.workers_salary = 200000;
    gena.business.bribe = 0;
    masha.vtb.account = 50000;
    masha.vtb.credit_card = 500000;
    masha.salary = 50000;
    masha.food = 150000;
    masha.style.clothes = 200000;
    masha.style.beauty_salon = 50000;
    masha.style.psychology = 0;
    asset_count = 3;
    strcpy(gena_assets[0].name, "hata_center");
    gena_assets[0].value = 35000000;
    gena_assets[0].repair = 15000;
    gena_assets[0].type = 1;
    strcpy(gena_assets[1].name, "dacha_elite");
    gena_assets[1].value = 50000000;
    gena_assets[1].repair = 40000;
    gena_assets[1].type = 1;
    strcpy(gena_assets[2].name, "vnedorozhnik");
    gena_assets[2].value = 15000000;
    gena_assets[2].repair = 60000;
    gena_assets[2].type = 2;
    strcpy(gena.hobby.name, "Weapon Collection & Shooting");
    gena.hobby.monthly_subscription = 50000;
    gena.hobby.equipment_upgrade = 200000;
    gena.hobby.professional_coach = 30000;

    strcpy(masha.hobby.name, "Extreme Boxing");
    masha.hobby.monthly_subscription = 25000;
    masha.hobby.equipment_upgrade = 15000;
    masha.hobby.professional_coach = 40000;

    strcpy(family_dog.breed, "Tibetan Mastiff");
    family_dog.food_premium = 35000;
    family_dog.grooming = 15000;
    family_dog.trainer = 20000;
    family_dog.vitamins = 10000;
    family_dog.exhibition_fee = 50000;

}

void gena_salary_get(int m) {
    gena.vtb.account += gena.salary;
    if (m == 12) {
        printf("gena poluchil premiyu v konce goda\n");
        gena.vtb.account += gena.salary;
    }
}

void masha_salary_get() {
    masha.vtb.account += masha.salary;
}

void food_costs() {
    gena.vtb.account -= gena.food;
    masha.vtb.account -= masha.food;
}

void masha_beauty_detalizacia() {
    RUB manikyur = 5000;
    RUB pedikyur = 7000;
    RUB resnicy = 4000;
    RUB solariy = 3000;
    masha.vtb.account -= (manikyur + pedikyur + resnicy + solariy);
}

void masha_lifestyle_monthly() {
    RUB internet = 2000;
    RUB mobile = 3500;
    RUB gifts = 10000;
    RUB taxi = 40000;
    masha.vtb.account -= (internet + mobile + gifts + taxi);
}

void masha_shopping_spree() {
    int r = rand() % 12;
    if (r == 1) {
        printf("masha kupila sumku za 500k\n");
        masha.vtb.account -= 500000;
    }
    if (r == 5) {
        printf("masha obnovila garderob k sezonu\n");
        masha.vtb.account -= 300000;
    }
}

void masha_health() {
    RUB gym = 15000;
    RUB kosmetika = 30000;
    RUB vitamini = 5000;
    masha.vtb.account -= (gym + kosmetika + vitamini);
}

void gena_car_costs() {
    RUB benzin = 25000;
    RUB moyka = 5000;
    RUB parking = 15000;
    gena.vtb.account -= (benzin + moyka + parking);
    int r = rand() % 40;
    if (r == 5) {
        printf("gena poluchil shtraf za prevyshenie\n");
        gena.vtb.account -= 5000;
    }
}

void gena_assets_maintenance() {
    for (int i = 0; i < asset_count; i++) {
        gena.vtb.account -= gena_assets[i].repair;
    }
}

void gena_stroyka_details() {
    int r = rand() % 20;
    if (r == 1) {
        printf("slomalsya kran nuzhen srochniy remont\n");
        gena.vtb.account -= 250000;
    }
    if (r == 2) {
        printf("podnyali nalog na zemlyu pod dachey\n");
        gena_assets[1].repair += 5000;
    }
    if (r == 3) {
        printf("betonozameshalka vdpreehala ne tuda ubytok\n");
        gena.vtb.account -= 100000;
    }
    if (r == 10) {
        printf("premiya ot zakazchika za krasiviy fasad\n");
        gena.vtb.account += 400000;
    }
}

void gena_business_events() {
    int r = rand() % 30;
    if (r == 1) {
        printf("posredniki snizili cenu na 30 proc economiya\n");
        gena.vtb.account += 1500000;
    }
    if (r == 2) {
        printf("tender ot adminki goroda vzyali\n");
        gena.vtb.account += 3000000;
    }
    if (r == 3) {
        printf("sdali obekt bez kosyakov ranishe sroka\n");
        gena.vtb.account += 1000000;
    }
    if (r == 4) {
        printf("sud s subpodryadchikom bolshie rashody\n");
        gena.vtb.account -= 800000;
    }
    if (r == 5) {
        printf("zabastovka rabochih nuzhny dengi na uregulirovanie\n");
        gena.vtb.account -= 500000;
    }
    if (r == 6) {
        printf("proverka vyyavila narusheniya dal vzatku\n");
        gena.vtb.account -= 1200000;
    }
}

void masha_social_life() {
    int r = rand() % 20;
    if (r == 1) {
        printf("vystavka hudozhnika znakomstvo s direktorom\n");
        printf("gena poluchil kontrakt\n");
        gena.salary += 50000;
    }
    if (r == 2) {
        printf("torgestvo plate u 3 devushek odinakovo\n");
        masha.vtb.account -= 400000;
        masha.style.psychology += 100000;
        masha.vtb.account -= 100000;
    }
    if (r == 3) {
        printf("blagotvoritelnost znakomstvo s prokurorom\n");
        printf("prokuror pomog v sudah dengi vernulis\n");
        gena.vtb.account += 1000000;
    }
}

void masha_startups() {
    if (rand() % 10 == 1) {
        RUB invest = 300000;
        masha.vtb.account -= invest;
        if (rand() % 10 == 1) {
            printf("startup labubu strelnul uspeh\n");
            masha.vtb.account += (invest * 3);
            masha.total_won += (invest * 3);
        }
        else {
            printf("startup provalilsya minus bablo\n");
            masha.total_lost += invest;
        }
    }
}

void family_events(int month) {
    if (month == 6) {
        printf("yubiley svadby 20 let bolshie traty\n");
        gena.vtb.account -= 2000000;
    }
    if (month == 8) {
        printf("otpusk v italii all inclusive\n");
        gena.vtb.account -= 1500000;
    }
    int r = rand() % 50;
    if (r == 15) {
        printf("dtp remont vnedorozhnika dorogo\n");
        gena.vtb.account -= 2000000;
    }
}

void vtb_deposite_calc(int year) {
    if (year == 2026) gena.vtb.interest = 16.0;
    if (year == 2027) gena.vtb.interest = 15.0;
    RUB monthly_profit = gena.vtb.deposite * (gena.vtb.interest / 12.0 / 100.0);
    gena.vtb.deposite += monthly_profit;
}

void check_deposite_growth(int m) {
    if (m % 3 == 0) {
        RUB bonus = gena.vtb.deposite * 0.01;
        gena.vtb.deposite += bonus;
    }
}

void apply_inflation(int year) {
    float f = 1.08;

    gena.food *= f;
    masha.food *= f;

    gena.business.beton *= f;
    gena.business.armatura *= f;
    gena.business.workers_salary *= f;
    gena.business.equipment_rent *= f;
    gena.business.fine *= f;
    gena.business.bribe *= f;

    masha.style.cosmetics *= f;
    masha.style.beauty_salon *= f;
    masha.style.clothes *= f;
    masha.style.psychology *= f;
    masha.style.instagram_ads *= f;

    gena.hobby.monthly_subscription *= f;
    gena.hobby.equipment_upgrade *= f;
    gena.hobby.professional_coach *= f;

    masha.hobby.monthly_subscription *= f;
    masha.hobby.equipment_upgrade *= f;
    masha.hobby.professional_coach *= f;

    family_dog.food_premium *= f;
    family_dog.grooming *= f;
    family_dog.trainer *= f;
    family_dog.vitamins *= f;
    family_dog.exhibition_fee *= f;

    RUB benzin = 25000;
    RUB moyka = 5000;
    RUB parking = 15000;
    benzin *= f;
    moyka *= f;
    parking *= f;

    RUB gym = 15000;
    RUB kosmetika_extra = 30000;
    RUB vitamini_masha = 5000;
    gym *= f;
    kosmetika_extra *= f;
    vitamini_masha *= f;

    for (int i = 0; i < asset_count; i++) {
        gena_assets[i].repair *= f;
        if (gena_assets[i].type == 1) {
            gena_assets[i].value *= 1.10;
        }
        else {
            gena_assets[i].value *= 0.85;
        }
    }

    if (year == 2030) {
        float crisis = 1.25;
        gena.business.beton *= crisis;
        gena.business.armatura *= crisis;
        family_dog.food_premium *= crisis;
        gena.food *= crisis;
        masha.food *= crisis;
        printf("vnimanie: v %d godu proizoshel krizis cen\n", year);
    }

    printf("noviy god %d: globalnaya inflyaciya na vse kategorii\n", year);
    printf("dorozhaet benzin, moyka, kosmetika i produkty\n");
}

void masha_support() {
    if (masha.vtb.account < 0) {
        RUB diff = -masha.vtb.account + 100000;
        gena.vtb.account -= diff;
        masha.vtb.account += diff;
        printf("gena perekinul deneg mashe na nuzhdy\n");
    }
}

void print_month_status(int m, int y) {
    RUB cap = gena.vtb.account + gena.vtb.deposite + masha.vtb.account;
    for (int i = 0; i < asset_count; i++) cap += gena_assets[i].value;
    printf("[%02d.%d] capital: %lld | g_acc: %lld | m_acc: %lld\n", m, y, cap, gena.vtb.account, masha.vtb.account);
}

void print_final_report() {
    printf("\n--- FINAL FINANCIAL AUDIT (10 YEARS) ---\n");
    printf("GENA ITOGI:\n");
    printf(" - schet v banke: %lld RUB\n", gena.vtb.account);
    printf(" - vklad vtb: %lld RUB\n", gena.vtb.deposite);
    printf(" - zarplata v konce: %lld RUB\n", gena.salary);
    printf("\nMASHA ITOGI:\n");
    printf(" - schet v banke: %lld RUB\n", masha.vtb.account);
    printf(" - startupy vyigrysh: %lld RUB\n", masha.total_won);
    printf(" - startupy ubytok: %lld RUB\n", masha.total_lost);
    RUB assets_value = 0;
    for (int i = 0; i < asset_count; i++) {
        assets_value += gena_assets[i].value;
    }
    RUB total_cash = gena.vtb.account + gena.vtb.deposite + masha.vtb.account;
    printf("\nAKTIVY SEMI:\n");
    printf(" - nedvizhimost i avto: %lld RUB\n", assets_value);
    printf(" - nalichnie i vklady: %lld RUB\n", total_cash);
    RUB final_sum = assets_value + total_cash;
    printf("------------------------------------------\n");
    printf("OBSHEE SOSTOYANIE SEMI: %lld RUB\n", final_sum);
    printf("------------------------------------------\n");
}
void family_dog_lifecycle() {
    gena.vtb.account -= family_dog.food_premium;
    masha.vtb.account -= family_dog.vitamins;

    if (rand() % 4 == 1) {
        printf("sobaka poehala na gruming\n");
        masha.vtb.account -= family_dog.grooming;
    }
    if (rand() % 6 == 1) {
        printf("zanyatie s kinologom dlya sobaki\n");
        gena.vtb.account -= family_dog.trainer;
    }
    if (rand() % 12 == 1) {
        printf("vystavka sobak: mastif vzyal medal\n");
        gena.vtb.account -= family_dog.exhibition_fee;
    }
}

void gena_hobby_weaponry() {
    gena.vtb.account -= gena.hobby.monthly_subscription;
    gena.vtb.account -= gena.hobby.professional_coach;
    RUB ammo_box = 15000;
    RUB range_rent = 10000;
    RUB targets_set = 5000;
    RUB cleaning_kit = 3000;
    gena.vtb.account -= (ammo_box + range_rent + targets_set + cleaning_kit);
    if (rand() % 10 == 1) {
        printf("gena kupil noviy redkiy stvol v kollekciyu\n");
        gena.vtb.account -= gena.hobby.equipment_upgrade;
    }
    if (rand() % 5 == 1) {
        printf("trenirovka po strelbe: tochnost povyshena\n");
        RUB extra_instructor = 7000;
        gena.vtb.account -= extra_instructor;
    }
    if (rand() % 20 == 7) {
        printf("gena prodlil licenziyu na oruzhie\n");
        gena.vtb.account -= 25000;
    }
}

void masha_hobby_boxing() {
    masha.vtb.account -= masha.hobby.monthly_subscription;
    masha.vtb.account -= masha.hobby.professional_coach;
    RUB bandages = 2000;
    RUB gym_fee = 5000;
    RUB mouthguard = 3000;
    RUB protein_shake = 4500;
    masha.vtb.account -= (bandages + gym_fee + mouthguard + protein_shake);
    if (rand() % 15 == 1) {
        printf("masha kupila professionalnie perchatki i ekipirovku\n");
        masha.vtb.account -= masha.hobby.equipment_upgrade;
    }
    if (rand() % 8 == 1) {
        printf("masha uchastvuet v gorodskom turnire po boksu\n");
        RUB entry_fee = 15000;
        RUB insurance = 5000;
        masha.vtb.account -= (entry_fee + insurance);
        if (rand() % 2 == 1) {
            printf("masha pobedila v boyu: moral podnyata\n");
            masha.total_won += 10000;
        }
        else {
            printf("masha proigrala no poluchila opyt\n");
        }
    }
}

void simulation_full() {
    int month = 3;
    int year = 2026;
    for (int i = 0; i < 120; i++) {
        vtb_deposite_calc(year);
        check_deposite_growth(month);
        food_costs();
        family_events(month);
        family_dog_lifecycle();
        masha_support();
        gena_salary_get(month);
        gena_assets_maintenance();
        gena_stroyka_details();
        gena_car_costs();
        gena_business_events();
        gena_hobby_weaponry();
        masha_salary_get();
        masha_beauty_detalizacia();
        masha_lifestyle_monthly();
        masha_shopping_spree();
        masha_health();
        masha_social_life();
        masha_startups();
        masha_hobby_boxing(); 

        if (i % 12 == 0) print_month_status(month, year);
        month++;
        if (month == 13) {
            month = 1;
            year++;
            apply_inflation(year);
        }
    }
}

int main() {
    srand(time(NULL));
    init();
    simulation_full();
    print_final_report();
    return 0;
}