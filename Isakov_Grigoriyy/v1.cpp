#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Типы данных 
using RUB = long long int;
using Percent = float;

//СТРУКТУРЫ (АНКЕТЫ

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
    int type; // 1 - hata, 2 - tachka
};

struct Person {
    Bank vtb;
    Style style;
    Construction business;
    RUB salary;
    RUB food;
    RUB total_lost;
    RUB total_won;
};

// Глобальные переменные 
struct Person gena;
struct Person masha;
Asset gena_assets[10];
int asset_count = 0;

//ИНИЦИАЛИЗАЦИЯ ДАННЫХ 

void init() {
    // Гена
    gena.vtb.account = 1000000;
    gena.vtb.deposite = 10000000;
    gena.vtb.interest = 16.0;
    gena.salary = 500000;
    gena.food = 30000;

    gena.business.beton = 100000;
    gena.business.armatura = 150000;
    gena.business.workers_salary = 200000;
    gena.business.bribe = 0;

    // Маша
    masha.vtb.account = 50000;
    masha.vtb.credit_card = 500000;
    masha.salary = 50000;
    masha.food = 150000;

    masha.style.clothes = 200000;
    masha.style.beauty_salon = 50000;
    masha.style.psychology = 0;

    // Имущество
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
}

//ФУНКЦИИ ДОХОДОВ

void gena_salary_get(int m) {
    gena.vtb.account += gena.salary;
    if (m == 12) { // 13-я зарплата 
        printf("gena poluchil premiyu v konce goda\n");
        gena.vtb.account += gena.salary;
    }
}

void masha_salary_get() {
    masha.vtb.account += masha.salary;
}

//ФУНКЦИИ БЫТОВЫХ РАСХОДОВ 

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

//ЛОГИКА БИЗНЕСА И СТРОЙКИ

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

//ЛОГИКА МАШИ

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

//СЕМЕЙНЫЕ СОБЫТИЯ

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

//ЭКОНОМИКА И БАНК

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
    for (int i = 0; i < asset_count; i++) {
        gena_assets[i].repair *= f;
        if (gena_assets[i].type == 1) gena_assets[i].value *= 1.10;
        else gena_assets[i].value *= 0.85;
    }
    printf("noviy god %d inflyaciya 8 proc\n", year);
}

void masha_support() {
    if (masha.vtb.account < 0) {
        RUB diff = -masha.vtb.account + 100000;
        gena.vtb.account -= diff;
        masha.vtb.account += diff;
        printf("gena perekinul deneg mashe na nuzhdy\n");
    }
}

//ВЫВОД СТАТУСА

void print_month_status(int m, int y) {
    RUB cap = gena.vtb.account + gena.vtb.deposite + masha.vtb.account;
    for (int i = 0; i < asset_count; i++) cap += gena_assets[i].value;
    printf("[%02d.%d] capital: %lld | g_acc: %lld | m_acc: %lld\n", m, y, cap, gena.vtb.account, masha.vtb.account);
}

//ГЛАВНЫЙ ЦИКЛ СИМУЛЯЦИИ

void simulation_full() {
    int month = 3;
    int year = 2026;
    for (int i = 0; i < 120; i++) {
        gena_salary_get(month);
        masha_salary_get();

        food_costs();
        gena_assets_maintenance();
        masha_beauty_detalizacia();
        masha_lifestyle_monthly();
        masha_shopping_spree();
        masha_health();

        gena_stroyka_details();
        gena_car_costs();
        gena_business_events();

        masha_social_life();
        masha_startups();

        family_events(month);

        vtb_deposite_calc(year);
        check_deposite_growth(month);
        masha_support();

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

    printf("\n rezultaty za 10 let\n");
    printf("masha poteryala: %lld\n", masha.total_lost);
    printf("masha podnyala: %lld\n", masha.total_won);

    RUB final_cap = gena.vtb.account + gena.vtb.deposite + masha.vtb.account;
    for (int i = 0; i < asset_count; i++) final_cap += gena_assets[i].value;
    printf("itogoviy capital semyi: %lld\n", final_cap);

    return 0;
}
