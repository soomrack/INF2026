#include <stdio.h>


using RUB = long long int;
using USD = long long int;

bool danil_dog = false;
bool eva_popugay = false;

float inflation = 8.7;

using Percent = float;


struct Bank
{
    RUB account;
    RUB deposite;
    Percent interest;

    USD account_usd;
    float rate_usd_rub;
};


struct Car
{
    RUB bmw_oil;
    RUB bmw_tires;
    RUB bmw_engine;
    RUB bmw_wheels;
    RUB bmw_piston;
    RUB bmw_valve;
    RUB bmw_spark_plug;
    RUB bmw_starter;
    RUB bmw_battery;
    RUB bmw_radiator;
    RUB bmw_fan;
    RUB bmw_muffler;
    RUB bmw_exhaust;
    RUB bmw_air_filter;
    RUB bmw_oil_filter;
    RUB bmw_timing_belt;
    RUB bmw_clutch;
    RUB bmw_transmission;
    RUB bmw_spring;
    RUB bmw_control_arm;
    RUB bmw_steering_rack;
    RUB bmw_brake_drum;
    RUB bmw_brake_pad;
    RUB bmw_brake_caliper;
    RUB bmw_antifreeze;
    RUB bmw_omyvaika;

    RUB mazda_air_filter;
    RUB mazda_oil_filter;
    RUB mazda_oil;
    RUB mazda_clutch;
    RUB battery;
    RUB mazda_antifreeze;
    RUB mazsa_omyvaika;
    RUB mazda_tires;

    RUB gas;
    RUB value;
    RUB repair;
};


struct Luxery
{
    RUB nogti;
    RUB haircut;
    RUB jewelry;
    RUB perfume;
    RUB eyebrows;
    RUB tan;
    RUB gucci_sumki;
    RUB prada_obuv;
    RUB lv_koshelek;
    RUB dior_ochki;
    RUB chanel_pomada;
    RUB hermes_braslet;
    RUB rolex_chasy;
    RUB versace_platye;
    RUB valentino_kabluki;
    RUB balenciaga_hudi;
    RUB fendi_remen;
    RUB bottega_klatch;
    RUB ysl_pudra;
    RUB tom_ford_duhi;
    RUB cartier_koltso;
    RUB dolce_gabbana_kupalnik;
    RUB burberry_plash;
    RUB armani_pidzhak;
    RUB ralph_lauren_rusbashka;
    RUB zegna_kostum;
    RUB brioni_galstuk;
    RUB roberto_cavalli_ochki;
    RUB maison_margiela_boots;
    RUB balmain_blazer;
    RUB offwhite_futbolka;
    RUB golden_goose_krossy;
    RUB acne_jeans;
    RUB moncler_curtka;
    RUB canada_goose_puhovik;
    RUB stone_island_hudi;

    RUB face_cleaning;
    RUB massage;
    RUB spa;
    RUB teeth_whitening;
    RUB eyebrows_correction;
    RUB perfume_exclusive;
    RUB cosmetologist;
};


struct E_solyariy
{
    RUB session_10_min;
    RUB session_15_min;
    RUB cream_bronzer;
    RUB cream_tan_accelerator;
    RUB cream_after_sun;
    RUB lip_balm_spf;
    RUB stickers_eyes;
    RUB cap;
    RUB sunglasses;
    RUB towel;
    RUB shoe_covers;
    RUB spray_cooling;
    RUB lotion_warm;
};


struct E_subscribe
{
    RUB youtube_premium;
    RUB spotify;
    RUB kinopoisk;
    RUB ivi;
    RUB vk_combo;
    RUB sber_prime;
    RUB yandex_plus;
    RUB apple_music;
    RUB telegram_premium;
    RUB chat_gpt;
    RUB midjourney;
    RUB photoshop;
    RUB stepik;
    RUB ps_plus;
    RUB game_pass;
    RUB nintendo_online;
    RUB icloud_plus;
    RUB google_drive;
    RUB yandex_disk;
    RUB dropbox;
    RUB tele2;
    RUB tinkoff_pro;
    RUB sber_pravda;
    RUB bank_commission;
    RUB domclick;
    RUB avito;
    RUB linkedin;
    RUB habr;
};


struct E_cat
{
    RUB napolnitel;
    RUB cats_food;
    //ниже непостоянные траты
    RUB osheinik;
    RUB toys;
};


struct Banya
{
    RUB entrance;
    RUB vip_room;
    RUB extra_hour;
    RUB broom_bereza;
    RUB broom_dub;
    RUB broom_eucalyptus;
    RUB sheet;
    RUB slippers;
    RUB cap_felt;
    RUB towel_big;
    RUB towel_small;
    RUB tea_herbal;
    RUB tea_black;
    RUB honey;
    RUB mint;
    RUB eucalyptus_oil;
    RUB salt;
    RUB scrub;
    RUB soap;
    RUB shampoo;
    RUB mask;
    RUB peels;
    RUB massage;
    RUB peeling_body;
    RUB washing_basin;
    RUB bucket_water;
    RUB kvass;
};


struct Pet_buy
{
    RUB dog;
    RUB popugay;
};


struct E_popugay
{
    RUB popugay_food;
    RUB popugay_toys;
    //ниже непостоянные траты
    RUB kletka;
};


struct D_dog
{
    RUB dogs_food;
    RUB grooming;
    RUB vet;
    RUB napolnitel;
    //ниже непостояные траты
    RUB osheinik;
};


struct E_travel
{
    RUB ticket;
    RUB car_rental;
    RUB transfer;
    RUB visa;
    RUB insurance;
    RUB excursion;
	RUB shopping;
	RUB souvenirs;
	RUB flashlight;
	RUB travel_clothes;
    RUB tent;
	RUB sleeping_bag;
	RUB backpack;
	RUB travel_food;
    RUB hotel;
    RUB food;
    RUB entertainment;
};


struct Hobby
{
    RUB golf;
    RUB chess;
    RUB swim;
    RUB code;
    RUB paint;
    RUB cook;
};

struct E_hobby
{
    RUB writing;
    RUB drawing;
    RUB painting;
    RUB photography;
    RUB singing;
    RUB dancing;
    RUB guitar;
    RUB piano;
    RUB drums;
};


struct Rent
{
    RUB rent;
};


struct E_food
{
    RUB eggs;
    RUB chicken_breast;
    RUB turkey;
    RUB salmon;
    RUB tuna;
    RUB oatmeal;
    RUB buckwheat;
    RUB quinoa;
    RUB rice;
    RUB avocado;
    RUB broccoli;
    RUB spinach;
    RUB cucumber;
    RUB tomatoes;
    RUB bell_pepper;
    RUB carrots;
    RUB cabbage;
    RUB greek_yogurt;
    RUB cottage_cheese;
    RUB milk;
    RUB nuts;
    RUB almonds;
    RUB walnuts;
    RUB berries;
    RUB blueberries;
    RUB strawberries;
    RUB banana;

};

struct D_food
{
    RUB eggs;
    RUB bread;
    RUB milk;
    RUB meat;
    RUB vegetables;
    RUB potatoes;
    RUB pasta;
    RUB rice;
    RUB chicken;
    RUB pork;
    RUB beef;
    RUB sausage;
    RUB cheese;
    RUB butter;
    RUB buckwheat;
    RUB bacon;
    RUB french_fries;
    RUB pizza;
    RUB burger;
    RUB instant_noodles;
    RUB chips;
    RUB beer;
    RUB soda;
    RUB mayonnaise;
    RUB ice_cream;
};


struct Gym
{
    RUB abonement;
    RUB personal_trainer;
    RUB sportswear;
    RUB towel;
    RUB locker_lock;
    RUB protein;
    RUB buds;
    RUB creatin;
    RUB desodorant;
};


struct Language
{
    RUB english;
    RUB spainish;
    RUB serbian;
    RUB italian;
};


struct Hoz_tovar
{
    RUB holodos;
    RUB tv;
    RUB washing_machine;
    RUB microwave;
    RUB oven;
    RUB kover;
    RUB dishes;
};


struct Person
{
    Luxery luxery;
    Bank vtb;
    Car car;
    RUB salary;
    Hobby hobby;
	E_hobby e_hobby;
    E_food e_food;
    D_food d_food;
    Gym gym;
    Hoz_tovar ht;
    E_cat cat;
    Rent kvartira_rent;
    Pet_buy pet_buy;
    D_dog dog;
    E_popugay popugay;
    E_travel e_travel;
    E_solyariy e_sloyariy;
    E_subscribe e_subscribe;
    Language language;
    Banya banya;
};


struct Person eva;
struct Person danil;


void eva_init()
{
    eva.vtb.account = 0;
    eva.vtb.deposite = 2'000'000;
    eva.vtb.interest = 14.5;
    eva.salary = 100'000;

    eva.vtb.account_usd = 1'000;
    eva.vtb.rate_usd_rub = 78.5;

    eva.kvartira_rent.rent = 25'000;

    eva.e_hobby.writing = 500;
	eva.e_hobby.drawing = 500;
	eva.e_hobby.painting = 1'000;
	eva.e_hobby.photography = 1'500;
	eva.e_hobby.singing = 1'000;
	eva.e_hobby.dancing = 1'000;
	eva.e_hobby.guitar = 2'000;
	eva.e_hobby.piano = 2'500;
	eva.e_hobby.drums = 1'500;

    eva.e_food.eggs = 50;
    eva.e_food.chicken_breast = 100;
    eva.e_food.turkey = 150;
    eva.e_food.salmon = 200;
    eva.e_food.tuna = 150;
    eva.e_food.oatmeal = 50;
    eva.e_food.buckwheat = 50;
    eva.e_food.quinoa = 100;
    eva.e_food.rice = 50;
    eva.e_food.avocado = 150;
    eva.e_food.broccoli = 50;
    eva.e_food.spinach = 50;
    eva.e_food.cucumber = 50;
    eva.e_food.tomatoes = 50;
    eva.e_food.bell_pepper = 50;
    eva.e_food.carrots = 50;
    eva.e_food.cabbage = 50;
    eva.e_food.greek_yogurt = 100;
    eva.e_food.cottage_cheese = 100;
    eva.e_food.milk = 50;
    eva.e_food.nuts = 100;
    eva.e_food.almonds = 50;
    eva.e_food.walnuts = 50;
    eva.e_food.berries = 100;
    eva.e_food.blueberries = 50;
    eva.e_food.strawberries = 50;
    eva.e_food.banana = 50;

    eva.ht.holodos = 50'000;
    eva.ht.tv = 100'000;
    eva.ht.washing_machine = 30'000;
    eva.ht.microwave = 15'000;
    eva.ht.oven = 20'000;
    eva.ht.kover = 10'000;
    eva.ht.dishes = 5'000;

    eva.car.repair = 1'000;
    eva.car.value = 2'400'000;
    eva.car.gas = 15'000;
    eva.car.mazda_air_filter = 500;
    eva.car.mazda_oil_filter = 700;
    eva.car.mazda_oil = 3'500;
    eva.car.mazda_clutch = 15'000;
    eva.car.battery = 7'000;
    eva.car.mazda_antifreeze = 7'500;
    eva.car.mazsa_omyvaika = 800;
    eva.car.mazda_tires = 3'000;

    eva.luxery.nogti = 3'000;
    eva.luxery.haircut = 1'000;
    eva.luxery.jewelry = 1'500;
    eva.luxery.perfume = 500;
    eva.luxery.eyebrows = 750;
    eva.luxery.tan = 1'000;
    eva.luxery.gucci_sumki = 234;
    eva.luxery.prada_obuv = 432;
    eva.luxery.lv_koshelek = 543;
    eva.luxery.dior_ochki = 643;
    eva.luxery.chanel_pomada =643 ;
    eva.luxery.hermes_braslet =234 ;
    eva.luxery.rolex_chasy = 745;
    eva.luxery.versace_platye = 765;
    eva.luxery.valentino_kabluki = 7543;
    eva.luxery.balenciaga_hudi = 643;
    eva.luxery.fendi_remen = 844;
    eva.luxery.bottega_klatch = 567;
    eva.luxery.ysl_pudra = 746;
    eva.luxery.tom_ford_duhi = 784;
    eva.luxery.cartier_koltso = 567;
    eva.luxery.dolce_gabbana_kupalnik = 835;
    eva.luxery.burberry_plash = 523;
    eva.luxery.armani_pidzhak = 333;
    eva.luxery.ralph_lauren_rusbashka = 523;
    eva.luxery.zegna_kostum = 512;
    eva.luxery.brioni_galstuk = 342;
    eva.luxery.roberto_cavalli_ochki = 754;
    eva.luxery.maison_margiela_boots = 999;
    eva.luxery.balmain_blazer = 675;
    eva.luxery.offwhite_futbolka = 765;
    eva.luxery.golden_goose_krossy = 552;
    eva.luxery.acne_jeans = 754;
    eva.luxery.moncler_curtka = 745;
    eva.luxery.canada_goose_puhovik = 464;
    eva.luxery.stone_island_hudi = 228;


    eva.language.english = 1500;
    eva.language.serbian = 1000;
    eva.language.italian = 2000;
    eva.language.spainish = 1000;

	eva.e_travel.ticket = 20'000;
	eva.e_travel.car_rental = 10'000;
	eva.e_travel.transfer = 5'000;
	eva.e_travel.visa = 3'000;
	eva.e_travel.insurance = 2'000;
	eva.e_travel.excursion = 5'000;
	eva.e_travel.shopping = 10'000;
	eva.e_travel.souvenirs = 5'000;
	eva.e_travel.flashlight = 1'000;
	eva.e_travel.travel_clothes = 5'000;
	eva.e_travel.tent = 10'000;
	eva.e_travel.sleeping_bag = 5'000;
	eva.e_travel.backpack = 5'000;
	eva.e_travel.travel_food = 5'000;
	eva.e_travel.hotel = 20'000;
	eva.e_travel.food = 10'000;
	eva.e_travel.entertainment = 10'000;

    eva.e_sloyariy.session_10_min = 1000;
    eva.e_sloyariy.session_15_min = 1400;
    eva.e_sloyariy.cream_bronzer = 100;
    eva.e_sloyariy.cream_tan_accelerator = 50;
    eva.e_sloyariy.lip_balm_spf = 60;
    eva.e_sloyariy.stickers_eyes = 15;
    eva.e_sloyariy.cap = 30;
    eva.e_sloyariy.sunglasses = 30;
    eva.e_sloyariy.towel = 100;
    eva.e_sloyariy.shoe_covers = 150;
    eva.e_sloyariy.spray_cooling = 15;
    eva.e_sloyariy.cream_after_sun = 20;
    eva.e_sloyariy.lotion_warm = 30;

    eva.e_subscribe.youtube_premium = 50;
    eva.e_subscribe.spotify = 60;
    eva.e_subscribe.kinopoisk = 30;
    eva.e_subscribe.ivi = 40;
    eva.e_subscribe.vk_combo = 50;
    eva.e_subscribe.sber_prime = 60;
    eva.e_subscribe.yandex_plus = 80;
    eva.e_subscribe.apple_music = 70;
    eva.e_subscribe.telegram_premium = 20;
    eva.e_subscribe.chat_gpt = 30;
    eva.e_subscribe.midjourney = 230;
    eva.e_subscribe.photoshop = 30;
    eva.e_subscribe.stepik = 70;
    eva.e_subscribe.ps_plus = 50;
    eva.e_subscribe.game_pass = 60;
    eva.e_subscribe.nintendo_online = 40;
    eva.e_subscribe.icloud_plus = 55;
    eva.e_subscribe.google_drive = 34;
    eva.e_subscribe.yandex_disk = 76;
    eva.e_subscribe.dropbox = 65;
    eva.e_subscribe.tele2 = 45;
    eva.e_subscribe.tinkoff_pro = 36;
    eva.e_subscribe.sber_pravda = 76;
    eva.e_subscribe.bank_commission = 45;
    eva.e_subscribe.domclick = 74;
    eva.e_subscribe.avito = 34;
    eva.e_subscribe.linkedin = 26;
    eva.e_subscribe.habr = 85;

    eva.cat.cats_food = 2500;
    eva.cat.napolnitel = 500;
    eva.cat.osheinik = 300;
    eva.cat.toys = 300;

    eva.pet_buy.popugay = 15'000;
    eva.popugay.popugay_food = 500;
    eva.popugay.popugay_toys = 300;
    eva.popugay.kletka = 2'000;
}

void danil_init()
{
    danil.vtb.account = 0;
    danil.vtb.deposite = 1'000'000;
    danil.vtb.interest = 14.5;
    danil.salary = 150'000;

    danil.vtb.account_usd = 1'000;
    danil.vtb.rate_usd_rub = 78.5;

    danil.d_food.eggs = 30;
    danil.d_food.bread = 15;
    danil.d_food.milk = 50;
    danil.d_food.meat = 200;
    danil.d_food.vegetables = 100;
    danil.d_food.potatoes = 50;
    danil.d_food.pasta = 50;
    danil.d_food.rice = 50;
    danil.d_food.chicken = 150;
    danil.d_food.pork = 150;
    danil.d_food.beef = 200;
    danil.d_food.sausage = 100;
    danil.d_food.cheese = 100;
    danil.d_food.butter = 50;
    danil.d_food.buckwheat = 50;
    danil.d_food.bacon = 100;
    danil.d_food.french_fries = 50;
    danil.d_food.pizza = 200;
    danil.d_food.burger = 150;
    danil.d_food.instant_noodles = 50;
    danil.d_food.chips = 50;
    danil.d_food.beer = 100;
    danil.d_food.soda = 50;
    danil.d_food.mayonnaise = 50;
    danil.d_food.ice_cream = 50;

    danil.kvartira_rent.rent = 15'000;

    danil.luxery.haircut = 1000;
    danil.luxery.perfume = 5000;
    danil.luxery.face_cleaning = 523;
    danil.luxery.massage = 655;
    danil.luxery.spa = 643;
    danil.luxery.teeth_whitening = 668;
    danil.luxery.eyebrows_correction = 976;
    danil.luxery.perfume_exclusive = 577;
    danil.luxery.cosmetologist = 900;

    danil.gym.abonement = 2'500;
    danil.gym.personal_trainer = 5'000;
    danil.gym.sportswear = 2'000;
    danil.gym.towel = 500;
    danil.gym.locker_lock = 100;
    danil.gym.protein = 1'500;
    danil.gym.buds = 2'000;
    danil.gym.creatin = 500;
    danil.gym.desodorant = 300;

    danil.language.english = 1500;
    danil.language.spainish = 1000;
    danil.language.serbian = 2000;
    danil.language.italian = 1000;

    danil.banya.entrance = 2000;
    danil.banya.vip_room = 300;
    danil.banya.extra_hour = 150;
    danil.banya.broom_bereza = 223;
    danil.banya.broom_dub = 230;
    danil.banya.broom_eucalyptus = 420;
    danil.banya.sheet = 230;
    danil.banya.slippers = 450;
    danil.banya.cap_felt = 275;
    danil.banya.towel_big = 650;
    danil.banya.towel_small = 650;
    danil.banya.tea_black = 260;
    danil.banya.tea_herbal = 840;
    danil.banya.honey = 643;
    danil.banya.mint = 754;
    danil.banya.eucalyptus_oil = 345;
    danil.banya.salt = 532;
    danil.banya.scrub = 234;
    danil.banya.soap = 346;
    danil.banya.shampoo = 634;
    danil.banya.mask = 754;
    danil.banya.peels = 234;
    danil.banya.massage = 523;
    danil.banya.peeling_body = 640;
    danil.banya.washing_basin = 643;
    danil.banya.bucket_water = 865;
    danil.banya.kvass = 644;

    danil.car.repair = 1000;
    danil.car.value = 500'000;
    danil.car.gas = 15'000;
    danil.car.bmw_air_filter = 1'500;
    danil.car.bmw_oil_filter = 2'000;
    danil.car.bmw_oil = 5'000;
    danil.car.bmw_clutch = 20'000;
    danil.car.bmw_battery = 7'000;
    danil.car.bmw_radiator = 10'000;
    danil.car.bmw_fan = 5'000;
    danil.car.bmw_muffler = 15'000;
    danil.car.bmw_exhaust = 20'000;
    danil.car.bmw_tires = 20'000;
    danil.car.bmw_wheels = 30'000;
    danil.car.bmw_engine = 100'000;
    danil.car.bmw_piston = 2'000;
    danil.car.bmw_valve = 1'500;
    danil.car.bmw_spark_plug = 3'000;
    danil.car.bmw_starter = 5'000;
    danil.car.bmw_transmission = 25'000;
    danil.car.bmw_brake_drum = 3'000;
    danil.car.bmw_brake_pad = 2'000;
    danil.car.bmw_brake_caliper = 5'000;
    danil.car.bmw_timing_belt = 7'000;
    danil.car.bmw_steering_rack = 15'000;
    danil.car.bmw_spring = 3'000;
    danil.car.bmw_antifreeze = 10'000;
    danil.car.bmw_omyvaika = 1'000;

    danil.hobby.golf = 2'000;
    danil.hobby.chess = 1'500;
    danil.hobby.swim = 1'000;
    danil.hobby.code = 0;
    danil.hobby.paint = 2'000;
    danil.hobby.cook = 500;

    danil.ht.holodos = 30'000;
    danil.ht.tv = 50'000;

    danil.pet_buy.dog = 20'000;

    danil.dog.dogs_food = 2'000;
    danil.dog.grooming = 1'000;
    danil.dog.vet = 5'000;
    danil.dog.napolnitel = 500;
    danil.dog.osheinik = 500;
}


void eva_salary(const int month, const int year)
{
    if (month == 12)
    {
        eva.vtb.account += eva.salary;  // 13th salary
    }

    if (month == 1 and year == 2027)
    {
        eva.salary *= 1.25;  // promotion
    }

    if (month == 1 and year == 2028)
    {
        eva.salary *= 1.5;  // promotion
    }

    if (month == 1 and year == 2029)
    {
        eva.salary *= 1.6;  // promotion
    }

    eva.vtb.account += eva.salary;
}


void danil_salary(const int month, const int year)
{
    if (year == 2026)
    {
        danil.vtb.account += 30'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2027)
    {
        danil.salary *= 1.25;  // promotion
    }

    if (year == 2027)
    {
        danil.vtb.account += 40'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2028)
    {
        danil.salary *= 1.25;  // promotion
    }

    if (year == 2028)
    {
        danil.vtb.account += 45'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2029)
    {
        danil.salary *= 1.25;  // promotion
    }

    if (year == 2029)
    {
        danil.vtb.account += 50'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2030)
    {
        danil.salary *= 1.4;  // promotion
    }

    if (year == 2030)
    {
        danil.vtb.account += 55'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2031)
    {
        danil.salary *= 1.25;  // promotion
    }

    if (year == 2031)
    {
        danil.vtb.account += 60'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2032)
    {
        danil.salary *= 1.3;  // promotion
    }

    if (year == 2032)
    {
        danil.vtb.account += 65'000;  // ежемесячная премия
    }
    
    if (month == 1 and year == 2033)
    {
        danil.salary *= 1.1;  // promotion
    }

    if (year == 2033)
    {
        danil.vtb.account += 70'000;  // ежемесячная премия
    }

    danil.vtb.account += danil.salary;
}


void eva_travel(const int month, const int year)
{
    if (month == 10 and year == 2030)
    {
        eva.vtb.account -= eva.e_travel.hotel;
        eva.vtb.account -= eva.e_travel.food;
        eva.vtb.account -= eva.e_travel.entertainment;
        eva.vtb.account -= eva.e_travel.ticket * 2;
        eva.vtb.account -= eva.e_travel.car_rental;
        eva.vtb.account -= eva.e_travel.transfer;
        eva.vtb.account -= eva.e_travel.visa;
        eva.vtb.account -= eva.e_travel.insurance;
        eva.vtb.account -= eva.e_travel.excursion;
        eva.vtb.account -= eva.e_travel.shopping;
        eva.vtb.account -= eva.e_travel.souvenirs;
        eva.vtb.account -= eva.e_travel.flashlight;
        eva.vtb.account -= eva.e_travel.travel_clothes;
        eva.vtb.account -= eva.e_travel.tent;
        eva.vtb.account -= eva.e_travel.sleeping_bag;
        eva.vtb.account -= eva.e_travel.backpack;
        eva.vtb.account -= eva.e_travel.travel_food;
    }

    eva.e_travel.hotel += eva.e_travel.hotel * inflation / 100.0 / 12;
    eva.e_travel.food += eva.e_travel.food * inflation / 100.0 / 12;
    eva.e_travel.entertainment += eva.e_travel.entertainment * inflation / 100.0 / 12;
    eva.e_travel.ticket += eva.e_travel.ticket * inflation / 100.0 / 12;
    eva.e_travel.car_rental += eva.e_travel.car_rental * inflation / 100.0 / 12;
    eva.e_travel.transfer += eva.e_travel.transfer * inflation / 100.0 / 12;
    eva.e_travel.visa += eva.e_travel.visa * inflation / 100.0 / 12;
    eva.e_travel.insurance += eva.e_travel.insurance * inflation / 100.0 / 12;
    eva.e_travel.excursion += eva.e_travel.excursion * inflation / 100.0 / 12;
    eva.e_travel.shopping += eva.e_travel.shopping * inflation / 100.0 / 12;
    eva.e_travel.souvenirs += eva.e_travel.souvenirs * inflation / 100.0 / 12;
    eva.e_travel.flashlight += eva.e_travel.flashlight * inflation / 100.0 / 12;
    eva.e_travel.travel_clothes += eva.e_travel.travel_clothes * inflation / 100.0 / 12;
    eva.e_travel.tent += eva.e_travel.tent * inflation / 100.0 / 12;
    eva.e_travel.sleeping_bag += eva.e_travel.sleeping_bag * inflation / 100.0 / 12;
    eva.e_travel.backpack += eva.e_travel.backpack * inflation / 100.0 / 12;
}


void eva_language(const int month, const int year)
{
    if (year == 2030)
    {
        eva.vtb.account -= eva.language.english;
    }

    if (year == 2031)
    {
        eva.vtb.account -= eva.language.serbian;
    }

    if (year == 2032)
    {
        eva.vtb.account -= eva.language.italian;
    }

    if (year == 2033)
    {
        eva.vtb.account -= eva.language.spainish;
    }

    eva.language.english += eva.language.english * inflation / 100.0 / 12;
    eva.language.serbian += eva.language.serbian * inflation / 100.0 / 12;
    eva.language.italian += eva.language.italian * inflation / 100.0 / 12;
    eva.language.spainish += eva.language.spainish * inflation / 100.0 / 12;
}


void danil_language(const int month, const int year)
{
    if (year == 2026)
    {
        danil.vtb.account -= danil.language.english;
    }

    if (year == 2027)
    {
        danil.vtb.account -= danil.language.serbian;
    }

    if (year == 2028)
    {
        danil.vtb.account -= danil.language.italian;
    }

    if (year == 2029)
    {
        danil.vtb.account -= danil.language.spainish;
    }

    danil.language.english += danil.language.english * inflation / 100.0 / 12;
    danil.language.serbian += danil.language.serbian * inflation / 100.0 / 12;
    danil.language.italian += danil.language.italian * inflation / 100.0 / 12;
    danil.language.spainish += danil.language.spainish * inflation / 100.0 / 12;
}


void eva_hobby()
{
    eva.vtb.account -= eva.e_hobby.writing;
    eva.e_hobby.writing += eva.e_hobby.writing * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_hobby.drawing;
    eva.e_hobby.drawing += eva.e_hobby.drawing * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_hobby.painting;
    eva.e_hobby.painting += eva.e_hobby.painting * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_hobby.photography;
    eva.e_hobby.photography += eva.e_hobby.photography * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_hobby.singing;
    eva.e_hobby.singing += eva.e_hobby.singing * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_hobby.dancing;
    eva.e_hobby.dancing += eva.e_hobby.dancing * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_hobby.guitar;
    eva.e_hobby.guitar += eva.e_hobby.guitar * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_hobby.piano;
    eva.e_hobby.piano += eva.e_hobby.piano * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_hobby.drums;
    eva.e_hobby.drums += eva.e_hobby.drums * inflation / 100.0 / 12;
}


void danil_hobby()
{
    danil.vtb.account -= danil.hobby.golf;
    danil.hobby.golf += danil.hobby.golf * inflation / 100.0 / 12;

    danil.vtb.account -= danil.hobby.chess;
    danil.hobby.chess += danil.hobby.chess * inflation / 100.0 / 12;

    danil.vtb.account -= danil.hobby.swim;
    danil.hobby.swim += danil.hobby.swim * inflation / 100.0 / 12;

    danil.vtb.account -= danil.hobby.code;
    danil.hobby.code += danil.hobby.code * inflation / 100.0 / 12;

    danil.vtb.account -= danil.hobby.paint;
    danil.hobby.paint += danil.hobby.paint * inflation / 100.0 / 12;

    danil.vtb.account -= danil.hobby.cook;
    danil.hobby.cook += danil.hobby.cook * inflation / 100.0 / 12;

}


void eva_kvartira()
{
    eva.vtb.account -= eva.kvartira_rent.rent;
    eva.kvartira_rent.rent += eva.kvartira_rent.rent * inflation / 100.0 / 12;
}


void danil_kvartira()
{
    danil.vtb.account -= danil.kvartira_rent.rent;
    danil.kvartira_rent.rent += danil.kvartira_rent.rent * inflation / 100.0 / 12;
}


void danil_banya(const int month, const int year)
{
    if (month == 10 and year == 2035)
    {
        danil.vtb.account -= danil.banya.entrance;
        danil.vtb.account -= danil.banya.vip_room;
        danil.vtb.account -= danil.banya.extra_hour;
        danil.vtb.account -= danil.banya.broom_bereza;
        danil.vtb.account -= danil.banya.broom_dub;
        danil.vtb.account -= danil.banya.broom_eucalyptus;
        danil.vtb.account -= danil.banya.sheet;
        danil.vtb.account -= danil.banya.slippers;
        danil.vtb.account -= danil.banya.cap_felt;
        danil.vtb.account -= danil.banya.towel_big;
        danil.vtb.account -= danil.banya.towel_small;
        danil.vtb.account -= danil.banya.tea_black;
        danil.vtb.account -= danil.banya.tea_herbal;
        danil.vtb.account -= danil.banya.honey;
        danil.vtb.account -= danil.banya.mint;
        danil.vtb.account -= danil.banya.eucalyptus_oil;
        danil.vtb.account -= danil.banya.scrub;
        danil.vtb.account -= danil.banya.soap;
        danil.vtb.account -= danil.banya.shampoo;
        danil.vtb.account -= danil.banya.peels;
        danil.vtb.account -= danil.banya.massage;
        danil.vtb.account -= danil.banya.peeling_body;
        danil.vtb.account -= danil.banya.washing_basin;
        danil.vtb.account -= danil.banya.bucket_water;
        danil.vtb.account -= danil.banya.kvass;
    }
    danil.banya.entrance += danil.banya.entrance * inflation / 100.0 / 12;
    danil.banya.vip_room += danil.banya.vip_room * inflation / 100.0 / 12;
    danil.banya.extra_hour += danil.banya.extra_hour * inflation / 100.0 / 12;
    danil.banya.broom_bereza += danil.banya.broom_bereza * inflation / 100.0 / 12;
    danil.banya.broom_dub += danil.banya.broom_dub * inflation / 100.0 / 12;
    danil.banya.broom_eucalyptus += danil.banya.broom_eucalyptus * inflation / 100.0 / 12;
    danil.banya.sheet += danil.banya.sheet * inflation / 100.0 / 12;
    danil.banya.cap_felt += danil.banya.cap_felt * inflation / 100.0 / 12;
    danil.banya.towel_big += danil.banya.towel_big * inflation / 100.0 / 12;
    danil.banya.towel_small += danil.banya.towel_small * inflation / 100.0 / 12;
    danil.banya.tea_black += danil.banya.tea_black * inflation / 100.0 / 12;
    danil.banya.tea_herbal += danil.banya.tea_herbal * inflation / 100.0 / 12;
    danil.banya.honey += danil.banya.honey * inflation / 100.0 / 12;
    danil.banya.eucalyptus_oil += danil.banya.eucalyptus_oil * inflation / 100.0 / 12;
    danil.banya.scrub += danil.banya.scrub * inflation / 100.0 / 12;
    danil.banya.soap += danil.banya.soap * inflation / 100.0 / 12;
    danil.banya.shampoo += danil.banya.shampoo * inflation / 100.0 / 12;
    danil.banya.peels += danil.banya.peels * inflation / 100.0 / 12;
    danil.banya.massage += danil.banya.massage * inflation / 100.0 / 12;
    danil.banya.peeling_body += danil.banya.peeling_body * inflation / 100.0 / 12;
    danil.banya.washing_basin += danil.banya.washing_basin * inflation / 100.0 / 12;
    danil.banya.bucket_water += danil.banya.bucket_water * inflation / 100.0 / 12;
    danil.banya.kvass += danil.banya.kvass * inflation / 100.0 / 12;
}


void eva_luxery(const int month, const int year)
{
    if (month == 1)
    {
        eva.vtb.account -= eva.luxery.nogti;
        eva.vtb.account -= eva.luxery.jewelry;
        eva.vtb.account -= eva.luxery.eyebrows;
    }

    if (month == 3)
    {
        eva.vtb.account -= eva.luxery.gucci_sumki;
        eva.vtb.account -= eva.luxery.prada_obuv;
        eva.vtb.account -= eva.luxery.lv_koshelek;
    }

    if (month == 5)
    {
        eva.vtb.account -= eva.luxery.dior_ochki;
        eva.vtb.account -= eva.luxery.chanel_pomada;
        eva.vtb.account -= eva.luxery.hermes_braslet;
    }

    if (month == 7)
    {
        eva.vtb.account -= eva.luxery.rolex_chasy;
        eva.vtb.account -= eva.luxery.versace_platye;
        eva.vtb.account -= eva.luxery.valentino_kabluki;
    }

    if (month == 9)
    {
        eva.vtb.account -= eva.luxery.balenciaga_hudi;
        eva.vtb.account -= eva.luxery.fendi_remen;
        eva.vtb.account -= eva.luxery.bottega_klatch;
    }

    if (month == 11)
    {
        eva.vtb.account -= eva.luxery.ysl_pudra;
        eva.vtb.account -= eva.luxery.tom_ford_duhi;
        eva.vtb.account -= eva.luxery.cartier_koltso;
    }

    if (month == 2)
    {
        eva.vtb.account -= eva.luxery.haircut;
        eva.vtb.account -= eva.luxery.perfume;
        eva.vtb.account -= eva.luxery.tan;
    }

    if (month == 4)
    {
        eva.vtb.account -= eva.luxery.dolce_gabbana_kupalnik;
        eva.vtb.account -= eva.luxery.burberry_plash;
        eva.vtb.account -= eva.luxery.armani_pidzhak;
    }

    if (month == 6)
    {
        eva.vtb.account -= eva.luxery.ralph_lauren_rusbashka;
        eva.vtb.account -= eva.luxery.zegna_kostum;
        eva.vtb.account -= eva.luxery.brioni_galstuk;
    }

    if (month == 8)
    {
        eva.vtb.account -= eva.luxery.roberto_cavalli_ochki;
        eva.vtb.account -= eva.luxery.maison_margiela_boots;
        eva.vtb.account -= eva.luxery.balmain_blazer;
    }

    if (month == 10)
    {
        eva.vtb.account -= eva.luxery.offwhite_futbolka;
        eva.vtb.account -= eva.luxery.golden_goose_krossy;
        eva.vtb.account -= eva.luxery.acne_jeans;
    }

    if (month == 12)
    {
        eva.vtb.account -= eva.luxery.moncler_curtka;
        eva.vtb.account -= eva.luxery.canada_goose_puhovik;
        eva.vtb.account -= eva.luxery.stone_island_hudi;
    }

    eva.luxery.nogti += eva.luxery.nogti * inflation / 100.0 / 12;
    eva.luxery.haircut += eva.luxery.haircut * inflation / 100.0 / 12;
    eva.luxery.jewelry += eva.luxery.jewelry * inflation / 100.0 / 12;
    eva.luxery.perfume += eva.luxery.perfume * inflation / 100.0 / 12;
    eva.luxery.eyebrows += eva.luxery.eyebrows * inflation / 100.0 / 12;
    eva.luxery.gucci_sumki += eva.luxery.gucci_sumki * inflation / 100.0 / 12;
    eva.luxery.prada_obuv += eva.luxery.prada_obuv * inflation / 100.0 / 12;
    eva.luxery.lv_koshelek += eva.luxery.lv_koshelek * inflation / 100.0 / 12;
    eva.luxery.dior_ochki += eva.luxery.dior_ochki * inflation / 100.0 / 12;
    eva.luxery.chanel_pomada += eva.luxery.chanel_pomada * inflation / 100.0 / 12;
    eva.luxery.hermes_braslet += eva.luxery.hermes_braslet * inflation / 100.0 / 12;
    eva.luxery.rolex_chasy += eva.luxery.rolex_chasy * inflation / 100.0 / 12;
    eva.luxery.versace_platye += eva.luxery.versace_platye * inflation / 100.0 / 12;
    eva.luxery.valentino_kabluki += eva.luxery.valentino_kabluki * inflation / 100.0 / 12;
    eva.luxery.balenciaga_hudi += eva.luxery.balenciaga_hudi * inflation / 100.0 / 12;
    eva.luxery.fendi_remen += eva.luxery.fendi_remen * inflation / 100.0 / 12;
    eva.luxery.bottega_klatch += eva.luxery.bottega_klatch * inflation / 100.0 / 12;
    eva.luxery.ysl_pudra += eva.luxery.ysl_pudra * inflation / 100.0 / 12;
    eva.luxery.tom_ford_duhi += eva.luxery.tom_ford_duhi * inflation / 100.0 / 12;
    eva.luxery.cartier_koltso += eva.luxery.cartier_koltso * inflation / 100.0 / 12;
    eva.luxery.dolce_gabbana_kupalnik += eva.luxery.dolce_gabbana_kupalnik * inflation / 100.0 / 12;
    eva.luxery.burberry_plash += eva.luxery.burberry_plash * inflation / 100.0 / 12;
    eva.luxery.armani_pidzhak += eva.luxery.armani_pidzhak * inflation / 100.0 / 12;
    eva.luxery.ralph_lauren_rusbashka += eva.luxery.ralph_lauren_rusbashka * inflation / 100.0 / 12;
    eva.luxery.zegna_kostum += eva.luxery.zegna_kostum * inflation / 100.0 / 12;
    eva.luxery.brioni_galstuk += eva.luxery.brioni_galstuk * inflation / 100.0 / 12;
    eva.luxery.roberto_cavalli_ochki += eva.luxery.roberto_cavalli_ochki * inflation / 100.0 / 12;
    eva.luxery.maison_margiela_boots += eva.luxery.maison_margiela_boots * inflation / 100.0 / 12;
    eva.luxery.balmain_blazer += eva.luxery.balmain_blazer * inflation / 100.0 / 12;
    eva.luxery.offwhite_futbolka += eva.luxery.offwhite_futbolka * inflation / 100.0 / 12;
    eva.luxery.golden_goose_krossy += eva.luxery.golden_goose_krossy * inflation / 100.0 / 12;
    eva.luxery.acne_jeans += eva.luxery.acne_jeans * inflation / 100.0 / 12;
    eva.luxery.moncler_curtka += eva.luxery.moncler_curtka * inflation / 100.0 / 12;
    eva.luxery.canada_goose_puhovik += eva.luxery.canada_goose_puhovik * inflation / 100.0 / 12;
    eva.luxery.stone_island_hudi += eva.luxery.stone_island_hudi * inflation / 100.0 / 12;
}


void danil_luxery(const int month, const int year)
{
    if (month == 1)
    {
        danil.vtb.account -= danil.luxery.haircut;
    }

    if (month == 3)
    {
        danil.vtb.account -= danil.luxery.face_cleaning;
    }

    if (month == 5)
    {
        danil.vtb.account -= danil.luxery.massage;
    }

    if (month == 7)
    {
        danil.vtb.account -= danil.luxery.spa;
    }

    if (month == 9)
    {
        danil.vtb.account -= danil.luxery.teeth_whitening;
    }

    if (month == 11)
    {
        danil.vtb.account -= danil.luxery.eyebrows_correction;
    }
    
    if (month == 4)
    {
        danil.vtb.account -= danil.luxery.perfume;
    }

    if (month == 8)
    {
        danil.vtb.account -= danil.luxery.perfume_exclusive;
    }

    if (month == 12)
    {
        danil.vtb.account -= danil.luxery.cosmetologist;
    }

    danil.luxery.haircut += danil.luxery.haircut * inflation / 100.0 / 12;
    danil.luxery.face_cleaning += danil.luxery.face_cleaning * inflation / 100.0 / 12;
    danil.luxery.massage += danil.luxery.massage * inflation / 100.0 / 12;
    danil.luxery.spa += danil.luxery.spa * inflation / 100.0 / 12;
    danil.luxery.teeth_whitening += danil.luxery.teeth_whitening * inflation / 100.0 / 12;
    danil.luxery.eyebrows_correction += danil.luxery.eyebrows_correction * inflation / 100.0 / 12;
    danil.luxery.perfume_exclusive += danil.luxery.perfume_exclusive * inflation / 100.0 / 12;
    danil.luxery.cosmetologist += danil.luxery.cosmetologist * inflation / 100.0 / 12;
    danil.luxery.perfume += danil.luxery.perfume * inflation / 100.0 / 12;
}


void danil_and_eva_pet_buy(const int month, const int year)
{
    if (month == 6 and year == 2026)
    {
        danil.vtb.deposite -= danil.pet_buy.dog;
        danil_dog = true;
    }
    danil.pet_buy.dog += danil.pet_buy.dog * inflation / 100.0 / 12;

    if (month == 7 and year == 2027)
    {
        eva.vtb.deposite -= eva.pet_buy.popugay;
        eva_popugay = true;
    }
    eva.pet_buy.popugay += eva.pet_buy.popugay * inflation / 100.0 / 12;
}


void eva_cat(const int month, const int year)
{
    eva.vtb.account -= eva.cat.cats_food;
    eva.cat.cats_food += eva.cat.cats_food * inflation / 100.0 / 12;

    eva.vtb.account -= eva.cat.napolnitel;
    eva.cat.napolnitel += eva.cat.napolnitel * inflation / 100.0 / 12;

    if (month == 5 and year == 2026)
    {
        eva.vtb.account -= eva.cat.osheinik;
    }

    eva.cat.osheinik += eva.cat.osheinik * inflation / 100.0 / 12;

    if (month == 8 and year == 2026)
    {
        eva.vtb.account -= eva.cat.toys;
    }

    eva.cat.toys += eva.cat.toys * inflation / 100.0 / 12;
}


void danils_dog(const int month, const int year)
{
    if (danil_dog == true)
    {
        danil.vtb.account -= danil.dog.dogs_food;
        danil.dog.dogs_food += danil.dog.dogs_food * inflation / 100.0 / 12;

        danil.vtb.account -= danil.dog.grooming;
        danil.dog.grooming += danil.dog.grooming * inflation / 100.0 / 12;

        danil.vtb.account -= danil.dog.vet;
        danil.dog.vet += danil.dog.vet * inflation / 100.0 / 12;

        danil.vtb.account -= danil.dog.napolnitel;
        danil.dog.napolnitel += danil.dog.napolnitel * inflation / 100.0 / 12;
    }

    if (month == 7 and year == 2026)
    {
        danil.vtb.account -= danil.dog.osheinik;
    }
    danil.dog.osheinik += danil.dog.osheinik * inflation / 100.0 / 12;
}


void evas_popugay(const int month, const int year)
{
    if (eva_popugay == true)
    {
        eva.vtb.account -= eva.popugay.popugay_food;
        eva.popugay.popugay_food += eva.popugay.popugay_food * inflation / 100.0 / 12;

        eva.vtb.account -= eva.popugay.popugay_toys;
        eva.popugay.popugay_toys += eva.popugay.popugay_toys * inflation / 100.0 / 12;
    }

    if (month == 8 and year == 2027)
    {
        eva.vtb.account -= eva.popugay.kletka;
    }
    eva.popugay.kletka += eva.popugay.kletka * inflation / 100.0 / 12;
}


void eva_food()
{
    eva.vtb.account -= eva.e_food.eggs * 8;
    eva.e_food.eggs += eva.e_food.eggs * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.chicken_breast * 20;
    eva.e_food.chicken_breast += eva.e_food.chicken_breast * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.turkey * 25;
    eva.e_food.turkey += eva.e_food.turkey * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.salmon * 50;
    eva.e_food.salmon += eva.e_food.salmon * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.tuna * 30;
    eva.e_food.tuna += eva.e_food.tuna * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.oatmeal * 10;
    eva.e_food.oatmeal += eva.e_food.oatmeal * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.buckwheat * 15;
    eva.e_food.buckwheat += eva.e_food.buckwheat * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.quinoa * 25;
    eva.e_food.quinoa += eva.e_food.quinoa * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.rice * 10;
    eva.e_food.rice += eva.e_food.rice * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.avocado * 30;
    eva.e_food.avocado += eva.e_food.avocado * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.broccoli * 10;
    eva.e_food.broccoli += eva.e_food.broccoli * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.spinach * 10;
    eva.e_food.spinach += eva.e_food.spinach * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.cucumber * 10;
    eva.e_food.cucumber += eva.e_food.cucumber * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.tomatoes * 10;
    eva.e_food.tomatoes += eva.e_food.tomatoes * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.bell_pepper * 10;
    eva.e_food.bell_pepper += eva.e_food.bell_pepper * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.carrots * 10;
    eva.e_food.carrots += eva.e_food.carrots * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.cabbage * 10;
    eva.e_food.cabbage += eva.e_food.cabbage * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.greek_yogurt * 20;
    eva.e_food.greek_yogurt += eva.e_food.greek_yogurt * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.cottage_cheese * 20;
    eva.e_food.cottage_cheese += eva.e_food.cottage_cheese * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.milk * 10;
    eva.e_food.milk += eva.e_food.milk * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.nuts * 20;
    eva.e_food.nuts += eva.e_food.nuts * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.almonds * 20;
    eva.e_food.almonds += eva.e_food.almonds * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.walnuts * 20;
    eva.e_food.walnuts += eva.e_food.walnuts * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.berries * 20;
    eva.e_food.berries += eva.e_food.berries * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.blueberries * 20;
    eva.e_food.blueberries += eva.e_food.blueberries * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.strawberries * 20;
    eva.e_food.strawberries += eva.e_food.strawberries * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.banana * 20;
    eva.e_food.banana += eva.e_food.banana * inflation / 100.0 / 12;
}


void danil_food()
{
    danil.vtb.account -= danil.d_food.eggs * 10;
    danil.d_food.eggs += danil.d_food.eggs * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.bread * 30;
    danil.d_food.bread += danil.d_food.bread * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.milk * 50;
    danil.d_food.milk += danil.d_food.milk * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.meat * 200;
    danil.d_food.meat += danil.d_food.meat * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.vegetables * 100;
    danil.d_food.vegetables += danil.d_food.vegetables * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.potatoes * 50;
    danil.d_food.potatoes += danil.d_food.potatoes * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.pasta * 50;
    danil.d_food.pasta += danil.d_food.pasta * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.rice * 50;
    danil.d_food.rice += danil.d_food.rice * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.chicken * 150;
    danil.d_food.chicken += danil.d_food.chicken * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.pork * 150;
    danil.d_food.pork += danil.d_food.pork * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.beef * 200;
    danil.d_food.beef += danil.d_food.beef * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.sausage * 100;
    danil.d_food.sausage += danil.d_food.sausage * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.cheese * 100;
    danil.d_food.cheese += danil.d_food.cheese * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.butter * 50;
    danil.d_food.butter += danil.d_food.butter * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.buckwheat * 50;
    danil.d_food.buckwheat += danil.d_food.buckwheat * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.bacon * 100;
    danil.d_food.bacon += danil.d_food.bacon * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.french_fries * 50;
    danil.d_food.french_fries += danil.d_food.french_fries * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.pizza * 200;
    danil.d_food.pizza += danil.d_food.pizza * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.burger * 150;
    danil.d_food.burger += danil.d_food.burger * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.instant_noodles * 50;
    danil.d_food.instant_noodles += danil.d_food.instant_noodles * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.chips * 50;
    danil.d_food.chips += danil.d_food.chips * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.beer * 100;
    danil.d_food.beer += danil.d_food.beer * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.soda * 50;
    danil.d_food.soda += danil.d_food.soda * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.mayonnaise * 50;
    danil.d_food.mayonnaise += danil.d_food.mayonnaise * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.ice_cream * 50;
    danil.d_food.ice_cream += danil.d_food.ice_cream * inflation / 100.0 / 12;
}


void eva_home_hoz(const int month, const int year)
{
    if (month == 5 and year == 2028)
    {
        eva.vtb.account -= eva.ht.holodos;
    }

    if (month == 6 and year == 2029)
    {
        eva.vtb.account -= eva.ht.tv;
    }

    if (month == 7 and year == 2030)
    {
        eva.vtb.account -= eva.ht.washing_machine;
    }

    if (month == 8 and year == 2031)
    {
        eva.vtb.account -= eva.ht.microwave;
    }

    if (month == 9 and year == 2032)
    {
        eva.vtb.account -= eva.ht.oven;
    }

    if (month == 10 and year == 2033)
    {
        eva.vtb.account -= eva.ht.kover;
    }

    if (month == 11 and year == 2034)
    {
        eva.vtb.account -= eva.ht.dishes;
    }

    eva.ht.tv += eva.ht.tv * inflation / 100.0 / 12;
    eva.ht.holodos += eva.ht.holodos * inflation / 100.0 / 12;
    eva.ht.washing_machine += eva.ht.washing_machine * inflation / 100.0 / 12;
    eva.ht.microwave += eva.ht.microwave * inflation / 100.0 / 12;
    eva.ht.oven += eva.ht.oven * inflation / 100.0 / 12;
    eva.ht.kover += eva.ht.kover * inflation / 100.0 / 12;
    eva.ht.dishes += eva.ht.dishes * inflation / 100.0 / 12;
}


void danil_home_hoz(const int month, const int year)
{
    if (month == 5 and year == 2027)
    {
        danil.vtb.account -= danil.ht.holodos;
    }

    danil.ht.holodos += danil.ht.holodos * inflation / 100.0 / 12;

    if (month == 6 and year == 2027)
    {
        danil.vtb.account -= danil.ht.tv;
    }

    danil.ht.tv += danil.ht.tv * inflation / 100.0 / 12;
}


void eva_solyariy(const int month, const int year)
{
    if (month == 2)
    {
        eva.vtb.account -= eva.e_sloyariy.session_10_min;
        eva.vtb.account -= eva.e_sloyariy.cream_bronzer;
        eva.vtb.account -= eva.e_sloyariy.cream_tan_accelerator;
        eva.vtb.account -= eva.e_sloyariy.cream_after_sun;
        eva.vtb.account -= eva.e_sloyariy.lip_balm_spf;
        eva.vtb.account -= eva.e_sloyariy.stickers_eyes;
        eva.vtb.account -= eva.e_sloyariy.cap;
        eva.vtb.account -= eva.e_sloyariy.sunglasses;
        eva.vtb.account -= eva.e_sloyariy.towel;
        eva.vtb.account -= eva.e_sloyariy.shoe_covers;
        eva.vtb.account -= eva.e_sloyariy.spray_cooling;
        eva.vtb.account -= eva.e_sloyariy.lotion_warm;
    }

    eva.e_sloyariy.session_10_min += eva.e_sloyariy.session_10_min * inflation / 100.0 / 12;
    eva.e_sloyariy.session_15_min += eva.e_sloyariy.session_15_min * inflation / 100.0 / 12;
    eva.e_sloyariy.cream_bronzer += eva.e_sloyariy.cream_bronzer * inflation / 100.0 / 12;
    eva.e_sloyariy.cream_tan_accelerator += eva.e_sloyariy.cream_tan_accelerator * inflation / 100.0 / 12;
    eva.e_sloyariy.cream_after_sun += eva.e_sloyariy.cream_after_sun * inflation / 100.0 / 12;
    eva.e_sloyariy.lip_balm_spf += eva.e_sloyariy.lip_balm_spf * inflation / 100.0 / 12;
    eva.e_sloyariy.stickers_eyes += eva.e_sloyariy.stickers_eyes * inflation / 100.0 / 12;
    eva.e_sloyariy.cap += eva.e_sloyariy.cap * inflation / 100.0 / 12;
    eva.e_sloyariy.sunglasses += eva.e_sloyariy.sunglasses * inflation / 100.0 / 12;
    eva.e_sloyariy.towel += eva.e_sloyariy.towel * inflation / 100.0 / 12;
    eva.e_sloyariy.shoe_covers += eva.e_sloyariy.shoe_covers * inflation / 100.0 / 12;
    eva.e_sloyariy.spray_cooling += eva.e_sloyariy.spray_cooling * inflation / 100.0 / 12;
    eva.e_sloyariy.lotion_warm += eva.e_sloyariy.lotion_warm * inflation / 100.0 / 12;
}


void eva_subscribe(const int month, const int year)
{
    if (year == 2026)
    {
        eva.vtb.account -= eva.e_subscribe.youtube_premium;
        eva.vtb.account -= eva.e_subscribe.spotify;
        eva.vtb.account -= eva.e_subscribe.kinopoisk;
        eva.vtb.account -= eva.e_subscribe.ivi;
        eva.vtb.account -= eva.e_subscribe.vk_combo;
    }

    if (year == 2027)
    {
        eva.vtb.account -= eva.e_subscribe.sber_prime;
        eva.vtb.account -= eva.e_subscribe.yandex_plus;
        eva.vtb.account -= eva.e_subscribe.apple_music;
        eva.vtb.account -= eva.e_subscribe.telegram_premium;
        eva.vtb.account -= eva.e_subscribe.chat_gpt;
    }

    if (year == 2028)
    {
        eva.vtb.account -= eva.e_subscribe.midjourney;
        eva.vtb.account -= eva.e_subscribe.photoshop;
        eva.vtb.account -= eva.e_subscribe.stepik;
        eva.vtb.account -= eva.e_subscribe.ps_plus;
        eva.vtb.account -= eva.e_subscribe.game_pass;
        eva.vtb.account -= eva.e_subscribe.youtube_premium;
        eva.vtb.account -= eva.e_subscribe.spotify;
    }

    if (year == 2029)
    {
        eva.vtb.account -= eva.e_subscribe.nintendo_online;
        eva.vtb.account -= eva.e_subscribe.icloud_plus;
        eva.vtb.account -= eva.e_subscribe.google_drive;
        eva.vtb.account -= eva.e_subscribe.yandex_disk;
        eva.vtb.account -= eva.e_subscribe.dropbox;
        eva.vtb.account -= eva.e_subscribe.sber_prime;
        eva.vtb.account -= eva.e_subscribe.yandex_plus;
    }

    if (year == 2030)
    {
        eva.vtb.account -= eva.e_subscribe.tele2;
        eva.vtb.account -= eva.e_subscribe.tinkoff_pro;
        eva.vtb.account -= eva.e_subscribe.sber_pravda;
        eva.vtb.account -= eva.e_subscribe.bank_commission;
        eva.vtb.account -= eva.e_subscribe.domclick;
        eva.vtb.account -= eva.e_subscribe.midjourney;
        eva.vtb.account -= eva.e_subscribe.photoshop;
    }

    if (year == 2031)
    {
        eva.vtb.account -= eva.e_subscribe.avito;
        eva.vtb.account -= eva.e_subscribe.linkedin;
        eva.vtb.account -= eva.e_subscribe.habr;
        eva.vtb.account -= eva.e_subscribe.nintendo_online;
        eva.vtb.account -= eva.e_subscribe.icloud_plus;
    }

    eva.e_subscribe.youtube_premium += eva.e_subscribe.youtube_premium * inflation / 100.0 / 12;
    eva.e_subscribe.spotify += eva.e_subscribe.spotify * inflation / 100.0 / 12;
    eva.e_subscribe.kinopoisk += eva.e_subscribe.kinopoisk * inflation / 100.0 / 12;
    eva.e_subscribe.ivi += eva.e_subscribe.ivi * inflation / 100.0 / 12;
    eva.e_subscribe.vk_combo += eva.e_subscribe.vk_combo * inflation / 100.0 / 12;
    eva.e_subscribe.sber_prime += eva.e_subscribe.sber_prime * inflation / 100.0 / 12;
    eva.e_subscribe.yandex_plus += eva.e_subscribe.yandex_plus * inflation / 100.0 / 12;
    eva.e_subscribe.apple_music += eva.e_subscribe.apple_music * inflation / 100.0 / 12;
    eva.e_subscribe.telegram_premium += eva.e_subscribe.telegram_premium * inflation / 100.0 / 12;
    eva.e_subscribe.chat_gpt += eva.e_subscribe.chat_gpt * inflation / 100.0 / 12;
    eva.e_subscribe.midjourney += eva.e_subscribe.midjourney * inflation / 100.0 / 12;
    eva.e_subscribe.photoshop += eva.e_subscribe.photoshop * inflation / 100.0 / 12;
    eva.e_subscribe.stepik += eva.e_subscribe.stepik * inflation / 100.0 / 12;
    eva.e_subscribe.ps_plus += eva.e_subscribe.ps_plus * inflation / 100.0 / 12;
    eva.e_subscribe.game_pass += eva.e_subscribe.game_pass * inflation / 100.0 / 12;
    eva.e_subscribe.nintendo_online += eva.e_subscribe.nintendo_online * inflation / 100.0 / 12;
    eva.e_subscribe.icloud_plus += eva.e_subscribe.icloud_plus * inflation / 100.0 / 12;
    eva.e_subscribe.google_drive += eva.e_subscribe.google_drive * inflation / 100.0 / 12;
    eva.e_subscribe.yandex_disk += eva.e_subscribe.yandex_disk * inflation / 100.0 / 12;
    eva.e_subscribe.dropbox += eva.e_subscribe.dropbox * inflation / 100.0 / 12;
    eva.e_subscribe.tele2 += eva.e_subscribe.tele2 * inflation / 100.0 / 12;
    eva.e_subscribe.tinkoff_pro += eva.e_subscribe.tinkoff_pro * inflation / 100.0 / 12;
    eva.e_subscribe.sber_pravda += eva.e_subscribe.sber_pravda * inflation / 100.0 / 12;
    eva.e_subscribe.bank_commission += eva.e_subscribe.bank_commission * inflation / 100.0 / 12;
    eva.e_subscribe.domclick += eva.e_subscribe.domclick * inflation / 100.0 / 12;
    eva.e_subscribe.avito += eva.e_subscribe.avito * inflation / 100.0 / 12;
    eva.e_subscribe.linkedin += eva.e_subscribe.linkedin * inflation / 100.0 / 12;
    eva.e_subscribe.habr += eva.e_subscribe.habr * inflation / 100.0 / 12;
}


void danil_gym(const int month, const int year)
{
    danil.vtb.account -= danil.gym.abonement;
    danil.gym.abonement += danil.gym.abonement * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.personal_trainer;
    danil.gym.personal_trainer += danil.gym.personal_trainer * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.sportswear;
    danil.gym.sportswear += danil.gym.sportswear * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.towel;
    danil.gym.towel += danil.gym.towel * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.locker_lock;
    danil.gym.locker_lock += danil.gym.locker_lock * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.protein;
    danil.gym.protein += danil.gym.protein * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.buds;
    danil.gym.buds += danil.gym.buds * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.creatin;
    danil.gym.creatin += danil.gym.creatin * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.desodorant;
    danil.gym.desodorant += danil.gym.desodorant * inflation / 100.0 / 12;
}


void eva_car(const int month)
{
    eva.vtb.account -= eva.car.mazsa_omyvaika;

    if (month == 6)
    {
        eva.vtb.account -= eva.car.mazda_antifreeze;
        eva.vtb.account -= eva.car.repair * 6;
    }

    if (month == 4)
    {
        eva.vtb.account -= eva.car.mazda_air_filter;
        eva.vtb.account -= eva.car.mazda_oil_filter;
        eva.vtb.account -= eva.car.mazda_oil;
        eva.vtb.account -= eva.car.mazda_clutch;
        eva.vtb.account -= eva.car.repair * 15;
    }

    if (month == 4)
    {
        eva.vtb.account -= eva.car.mazda_tires;
        eva.vtb.account -= eva.car.repair * 3;
    }

    if (month == 11)
    {
        eva.vtb.account -= eva.car.mazda_tires;
        eva.vtb.account -= eva.car.repair * 3;
    }

    eva.vtb.account -= eva.car.gas;

    eva.car.gas += eva.car.gas * inflation / 100.0 / 12;
    eva.car.repair += eva.car.repair * inflation / 100.0 / 12;
    eva.car.mazda_air_filter += eva.car.mazda_air_filter * inflation / 100.0 / 12;
    eva.car.mazda_oil_filter += eva.car.mazda_oil_filter * inflation / 100.0 / 12;
    eva.car.mazda_oil += eva.car.mazda_oil * inflation / 100.0 / 12;
    eva.car.mazda_clutch += eva.car.mazda_clutch * inflation / 100.0 / 12;
    eva.car.mazda_antifreeze += eva.car.mazda_antifreeze * inflation / 100.0 / 12;
    eva.car.mazsa_omyvaika += eva.car.mazsa_omyvaika * inflation / 100.0 / 12;
    eva.car.mazda_tires += eva.car.mazda_tires * inflation / 100.0 / 12;
}


void danil_car(const int month, const int year)
{
    if (month == 7)
    {
        danil.vtb.account -= danil.car.bmw_air_filter;
        danil.vtb.account -= danil.car.bmw_oil_filter;
        danil.vtb.account -= danil.car.bmw_oil;
        danil.vtb.account -= danil.car.bmw_clutch;
        danil.vtb.account -= danil.car.repair * 20;
    }
    
    danil.vtb.account -= danil.car.bmw_omyvaika;

    if (month == 6)
    {
        danil.vtb.account -= danil.car.bmw_antifreeze;
        danil.vtb.account -= danil.car.repair * 3.5;
    }

    if (month == 12)
    {
        danil.vtb.account -= danil.car.bmw_antifreeze;
        danil.vtb.account -= danil.car.repair * 3.5;
    }

    if (month == 4)
    {
        danil.vtb.account -= danil.car.bmw_tires * 4;
        danil.vtb.account -= danil.car.repair * 2.5;
    }

    if (month == 11)
    {
        danil.vtb.account -= danil.car.bmw_tires * 4;
        danil.vtb.account -= danil.car.repair * 2.5;
    }

    if (month == 10 and year == 2026)
    {
        danil.vtb.account -= danil.car.bmw_wheels * 4;
        danil.vtb.account -= danil.car.bmw_spring * 4;
        danil.vtb.account -= danil.car.bmw_control_arm * 4;
        danil.vtb.account -= danil.car.repair * 10;
    }

    if (month == 6 and year == 2027)
    {
        danil.vtb.account -= danil.car.bmw_starter;
        danil.vtb.account -= danil.car.bmw_muffler;
        danil.vtb.account -= danil.car.bmw_exhaust;
        danil.vtb.account -= danil.car.battery;
        danil.vtb.account -= danil.car.bmw_radiator;
        danil.vtb.account -= danil.car.bmw_fan;
        danil.vtb.account -= danil.car.repair * 30;
    }

    if (month == 10 and year == 2027)
    {
        danil.vtb.account -= danil.car.bmw_transmission;
        danil.vtb.account -= danil.car.repair * 10;
    }

    if (month == 4 and year == 2028)
    {
        danil.vtb.account -= danil.car.bmw_engine;
        danil.vtb.account -= danil.car.bmw_piston * 4;
        danil.vtb.account -= danil.car.bmw_valve * 16;
        danil.vtb.account -= danil.car.bmw_spark_plug * 6;
        danil.vtb.account -= danil.car.bmw_timing_belt;
        danil.vtb.account -= danil.car.bmw_steering_rack;
        danil.vtb.account -= danil.car.repair * 150;
    }

    if (month == 7 and year == 2032)
    {
        danil.vtb.account -= danil.car.bmw_brake_drum * 4;
        danil.vtb.account -= danil.car.bmw_brake_pad * 4;
        danil.vtb.account -= danil.car.bmw_brake_caliper * 4;
        danil.vtb.account -= danil.car.repair * 20;
    }

    danil.vtb.account -= danil.car.gas;

    danil.car.gas += danil.car.gas * inflation / 100.0 / 12;
    danil.car.repair += danil.car.repair * inflation / 100.0 / 12;
    danil.car.bmw_air_filter += danil.car.bmw_air_filter * inflation / 100.0 / 12;
    danil.car.bmw_oil_filter += danil.car.bmw_oil_filter * inflation / 100.0 / 12;
    danil.car.bmw_oil += danil.car.bmw_oil * inflation / 100.0 / 12;
    danil.car.bmw_clutch += danil.car.bmw_clutch * inflation / 100.0 / 12;
    danil.car.bmw_battery += danil.car.bmw_battery * inflation / 100.0 / 12;
    danil.car.bmw_radiator += danil.car.bmw_radiator * inflation / 100.0 / 12;
    danil.car.bmw_fan += danil.car.bmw_fan * inflation / 100.0 / 12;
    danil.car.bmw_muffler += danil.car.bmw_muffler * inflation / 100.0 / 12;
    danil.car.bmw_exhaust += danil.car.bmw_exhaust * inflation / 100.0 / 12;
    danil.car.bmw_tires += danil.car.bmw_tires * inflation / 100.0 / 12;
    danil.car.bmw_wheels += danil.car.bmw_wheels * inflation / 100.0 / 12;
    danil.car.bmw_engine += danil.car.bmw_engine * inflation / 100.0 / 12;
    danil.car.bmw_piston += danil.car.bmw_piston * inflation / 100.0 / 12;
    danil.car.bmw_valve += danil.car.bmw_valve * inflation / 100.0 / 12;
    danil.car.bmw_spark_plug += danil.car.bmw_spark_plug * inflation / 100.0 / 12;
    danil.car.bmw_starter += danil.car.bmw_starter * inflation / 100.0 / 12;
    danil.car.bmw_transmission += danil.car.bmw_transmission * inflation / 100.0 / 12;
    danil.car.bmw_brake_drum += danil.car.bmw_brake_drum * inflation / 100.0 / 12;
    danil.car.bmw_brake_pad += danil.car.bmw_brake_pad * inflation / 100.0 / 12;
    danil.car.bmw_brake_caliper += danil.car.bmw_brake_caliper * inflation / 100.0 / 12;
    danil.car.bmw_timing_belt += danil.car.bmw_timing_belt * inflation / 100.0 / 12;
    danil.car.bmw_steering_rack += danil.car.bmw_steering_rack * inflation / 100.0 / 12;
    danil.car.bmw_spring += danil.car.bmw_spring * inflation / 100.0 / 12;
    danil.car.bmw_tires += danil.car.bmw_tires * inflation / 100.0 / 12;
    danil.car.bmw_omyvaika += danil.car.bmw_omyvaika * inflation / 100.0 / 12;
    danil.car.bmw_antifreeze += danil.car.bmw_antifreeze * inflation / 100.0 / 12;
}


void eva_deposite(const int month, const int year)
{
    if (year == 2026) eva.vtb.interest = 14.5;
    if (year == 2027) eva.vtb.interest = 13.5;
    if (year == 2028) eva.vtb.interest = 12.5;
    if (year >= 2029) eva.vtb.interest = 11.5;

    eva.vtb.deposite += eva.vtb.deposite * (eva.vtb.interest / 12.0 / 100.0);

    eva.vtb.deposite += eva.vtb.account;
    eva.vtb.account = 0;
}


void danil_deposite(const int month, const int year)
{
    if (year == 2026) danil.vtb.interest = 15.0;
    if (year == 2027) danil.vtb.interest = 14.0;
    if (year == 2028) danil.vtb.interest = 13.0;
    if (year >= 2029) danil.vtb.interest = 11.5;

    danil.vtb.deposite += danil.vtb.deposite * (danil.vtb.interest / 12.0 / 100.0);

    danil.vtb.deposite += danil.vtb.account;
    danil.vtb.account = 0
}


void eva_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027)
    {
        eva.vtb.account += 3'000;
    };

    if (month == 4 and year == 2027)
    {
        eva.vtb.account += 10'000;
    };

    if (month == 6 and year == 2027)
    {
        eva.vtb.account += 12'000;
    };

    if (month == 7 and year == 2027)
    {
        eva.vtb.account += 20'000;
    };

    if (month == 8 and year == 2027)
    {
        eva.vtb.account += 15'000;
    };

    if (month == 9 and year == 2027)
    {
        eva.vtb.account += 12'000;
    };

    if (month == 10 and year == 2027)
    {
        eva.vtb.account += 6'000;
    };

    if (month == 11 and year == 2027)
    {
        eva.vtb.account += 12'000;
    };

    if (month == 12 and year == 2027)
    {
        eva.vtb.account += 100'000;
    };

    if (year == 2028)
    {
        eva.vtb.account += 30'000;
    }
}


void danil_freelance(const int month, const int year)
{
    if (year == 2026)
    {
        danil.vtb.account += 15'000;
    }

    if (year == 2027)
    {
        danil.vtb.account += 25'000;
    }

    if (year == 2028)
    {
        danil.vtb.account += 35'000;
    }

    if (year == 2029)
    {
        danil.vtb.account += 45'000;
    }

    if (year == 2030)
    {
        danil.vtb.account += 55'000;
    }

    if (year == 2031)
    {
        danil.vtb.account += 60'000;
    }

    if (year == 2032)
    {
        danil.vtb.account += 65'000;
    }
}


void print_results()
{
    printf("Eva\n");
    printf("Salary = %lld\n", eva.salary);

    RUB eva_capital = 0;
    eva_capital += eva.vtb.account;
    eva_capital += eva.car.value;
    eva_capital += eva.vtb.deposite;
    eva_capital += eva.vtb.account_usd * eva.vtb.rate_usd_rub;
    printf("Capital = %lld\n\n", eva_capital);

    printf("Danil\n");
    printf("Salary = %lld\n", danil.salary);

    RUB danil_capital = 1;
    danil_capital += danil.vtb.account;
    danil_capital += danil.car.value;
    danil_capital += danil.vtb.deposite;
    danil_capital += danil.vtb.account_usd * danil.vtb.rate_usd_rub;
    printf("Capital = %lld\n", danil_capital);
}





void simulation()
{
    int month = 2;
    int year = 2026;

    while (not (month == 3 and year == 2035))
    {
        eva_salary(month, year);
        eva_freelance(month, year);
        eva_car(month);
        eva_food();
        eva_luxery(month, year);
        eva_kvartira();
        eva_cat(month, year);
        eva_hobby();
        evas_popugay(month, year);
        eva_home_hoz(month, year);
		eva_travel(month, year);
        eva_solyariy(month, year);
        eva_subscribe(month, year);
        eva_language(month, year);

        danil_salary(month, year);
        danil_hobby();
        danil_kvartira();
        danil_luxery(month, year);
        danils_dog(month, year);
        danil_freelance(month, year);
        danil_car(month, year);
        danil_food();
        danil_home_hoz(month, year);
        danil_gym(month, year);
        danil_language(month, year);
        danil_banya(month, year);

        danil_and_eva_pet_buy(month, year);
        //чтобы деньги не минусовались
        eva_deposite(month, year);
        danil_deposite(month, year);
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    eva_init();

    danil_init();

    simulation();

    print_results();
}