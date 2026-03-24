#include <stdio.h>


using RUB = long long int;
using USD = long long int;

using Percent = float;

Percent inflation = 8.7;


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


struct Solyariy
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


struct Subscribe
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


struct Pet
{
    bool danil_dog_is_alive = false;
    bool eva_popugay_is_alive = false;
    bool eva_cat_is_alive = false;
    RUB napolnitel;
    RUB food;
    RUB sale;
    RUB toys;
    RUB grooming;
    RUB vet;
    RUB osheinik;
    RUB kletka;
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


struct Travel
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


struct Food
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
    RUB bread;
    RUB meat;
    RUB vegetables;
    RUB potatoes;
    RUB pasta;
    RUB chicken;
    RUB pork;
    RUB beef;
    RUB sausage;
    RUB cheese;
    RUB butter;
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

    RUB vacuum_cleaner;
    RUB iron;
    RUB toaster;
    RUB kettle;
    RUB furniture;
    RUB curtains;
    RUB bedding;
    RUB towels;
    RUB kitchen_utensils;
    RUB fridge_freezer;
    RUB dishwasher;
    RUB coffee_machine;
    RUB blender;
    RUB mixer;
    RUB food_processor;
    RUB air_conditioner;
    RUB heater;
    RUB fan;
    RUB humidifier;
    RUB air_purifier;
    RUB lamp;
    RUB chandelier;
    RUB carpet;
    RUB rug;
    RUB mirror;
    RUB wardrobe;
    RUB chest_of_drawers;
    RUB shelf;
    RUB table;
};


struct Person
{
    Luxery luxery;
    Bank vtb;
    Car car;
    RUB salary;
    Hobby hobby;
    Food food;
    Gym gym;
    Hoz_tovar ht;
    Pet cat;
    Pet dog;
    Pet popugay;
    Rent kvartira_rent;
    Travel travel;
    Solyariy solyariy;
    Subscribe subscribe;
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

    eva.hobby.writing = 500;
    eva.hobby.drawing = 500;
    eva.hobby.painting = 1'000;
    eva.hobby.photography = 1'500;
    eva.hobby.singing = 1'000;
    eva.hobby.dancing = 1'000;
    eva.hobby.guitar = 2'000;
    eva.hobby.piano = 2'500;
    eva.hobby.drums = 1'500;

    eva.food.eggs = 50;
    eva.food.chicken_breast = 100;
    eva.food.turkey = 150;
    eva.food.salmon = 200;
    eva.food.tuna = 150;
    eva.food.oatmeal = 50;
    eva.food.buckwheat = 50;
    eva.food.quinoa = 100;
    eva.food.rice = 50;
    eva.food.avocado = 150;
    eva.food.broccoli = 50;
    eva.food.spinach = 50;
    eva.food.cucumber = 50;
    eva.food.tomatoes = 50;
    eva.food.bell_pepper = 50;
    eva.food.carrots = 50;
    eva.food.cabbage = 50;
    eva.food.greek_yogurt = 100;
    eva.food.cottage_cheese = 100;
    eva.food.milk = 50;
    eva.food.nuts = 100;
    eva.food.almonds = 50;
    eva.food.walnuts = 50;
    eva.food.berries = 100;
    eva.food.blueberries = 50;
    eva.food.strawberries = 50;
    eva.food.banana = 50;

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
    eva.luxery.chanel_pomada = 643;
    eva.luxery.hermes_braslet = 234;
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

    eva.travel.ticket = 20'000;
    eva.travel.car_rental = 10'000;
    eva.travel.transfer = 5'000;
    eva.travel.visa = 3'000;
    eva.travel.insurance = 2'000;
    eva.travel.excursion = 5'000;
    eva.travel.shopping = 10'000;
    eva.travel.souvenirs = 5'000;
    eva.travel.flashlight = 1'000;
    eva.travel.travel_clothes = 5'000;
    eva.travel.tent = 10'000;
    eva.travel.sleeping_bag = 5'000;
    eva.travel.backpack = 5'000;
    eva.travel.travel_food = 5'000;
    eva.travel.hotel = 20'000;
    eva.travel.food = 10'000;
    eva.travel.entertainment = 10'000;

    eva.solyariy.session_10_min = 1000;
    eva.solyariy.session_15_min = 1400;
    eva.solyariy.cream_bronzer = 100;
    eva.solyariy.cream_tan_accelerator = 50;
    eva.solyariy.lip_balm_spf = 60;
    eva.solyariy.stickers_eyes = 15;
    eva.solyariy.cap = 30;
    eva.solyariy.sunglasses = 30;
    eva.solyariy.towel = 100;
    eva.solyariy.shoe_covers = 150;
    eva.solyariy.spray_cooling = 15;
    eva.solyariy.cream_after_sun = 20;
    eva.solyariy.lotion_warm = 30;

    eva.subscribe.youtube_premium = 50;
    eva.subscribe.spotify = 60;
    eva.subscribe.kinopoisk = 30;
    eva.subscribe.ivi = 40;
    eva.subscribe.vk_combo = 50;
    eva.subscribe.sber_prime = 60;
    eva.subscribe.yandex_plus = 80;
    eva.subscribe.apple_music = 70;
    eva.subscribe.telegram_premium = 20;
    eva.subscribe.chat_gpt = 30;
    eva.subscribe.midjourney = 230;
    eva.subscribe.photoshop = 30;
    eva.subscribe.stepik = 70;
    eva.subscribe.ps_plus = 50;
    eva.subscribe.game_pass = 60;
    eva.subscribe.nintendo_online = 40;
    eva.subscribe.icloud_plus = 55;
    eva.subscribe.google_drive = 34;
    eva.subscribe.yandex_disk = 76;
    eva.subscribe.dropbox = 65;
    eva.subscribe.tele2 = 45;
    eva.subscribe.tinkoff_pro = 36;
    eva.subscribe.sber_pravda = 76;
    eva.subscribe.bank_commission = 45;
    eva.subscribe.domclick = 74;
    eva.subscribe.avito = 34;
    eva.subscribe.linkedin = 26;
    eva.subscribe.habr = 85;

    eva.cat.food = 2500;
    eva.cat.napolnitel = 500;
    eva.cat.osheinik = 300;
    eva.cat.toys = 300;
    eva.cat.sale = 20'000;

    eva.popugay.sale = 15'000;
    eva.popugay.food = 500;
    eva.popugay.toys = 300;
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

    danil.food.eggs = 30;
    danil.food.bread = 15;
    danil.food.milk = 50;
    danil.food.meat = 200;
    danil.food.vegetables = 100;
    danil.food.potatoes = 50;
    danil.food.pasta = 50;
    danil.food.rice = 50;
    danil.food.chicken = 150;
    danil.food.pork = 150;
    danil.food.beef = 200;
    danil.food.sausage = 100;
    danil.food.cheese = 100;
    danil.food.butter = 50;
    danil.food.buckwheat = 50;
    danil.food.bacon = 100;
    danil.food.french_fries = 50;
    danil.food.pizza = 200;
    danil.food.burger = 150;
    danil.food.instant_noodles = 50;
    danil.food.chips = 50;
    danil.food.beer = 100;
    danil.food.soda = 50;
    danil.food.mayonnaise = 50;
    danil.food.ice_cream = 50;

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
    danil.ht.vacuum_cleaner = 500;
    danil.ht.iron = 1000;
    danil.ht.toaster = 600;
    danil.ht.kettle = 700;
    danil.ht.furniture = 800;
    danil.ht.curtains = 900;
    danil.ht.bedding = 800;
    danil.ht.towels = 675;
    danil.ht.kitchen_utensils = 857;
    danil.ht.fridge_freezer = 7650;
    danil.ht.dishwasher = 564;
    danil.ht.coffee_machine = 5444;
    danil.ht.blender = 5643;
    danil.ht.mixer = 5543;
    danil.ht.food_processor = 600;
    danil.ht.air_conditioner = 644;
    danil.ht.heater = 122;
    danil.ht.humidifier = 324;
    danil.ht.air_purifier = 5324;
    danil.ht.lamp = 6433;
    danil.ht.chandelier = 643;
    danil.ht.carpet = 575;
    danil.ht.rug = 865;
    danil.ht.mirror = 234;
    danil.ht.wardrobe = 234;
    danil.ht.chest_of_drawers = 523;
    danil.ht.shelf = 734;
    danil.ht.table = 6337;


    danil.dog.sale = 20'000;
    danil.dog.food = 2'000;
    danil.dog.grooming = 1'000;
    danil.dog.vet = 5'000;
    danil.dog.napolnitel = 500;
    danil.dog.osheinik = 500;
}


void eva_salary(const int month, const int year)
{
    if (month == 12) {
        eva.vtb.account += eva.salary;
    }

    if (month == 1 and year == 2027) {
        eva.salary *= 1.25;
    }

    if (month == 1 and year == 2028) {
        eva.salary *= 1.5;
    }

    if (month == 1 and year == 2029) {
        eva.salary *= 1.6;
    }

    if (month == 5 and year == 2030) {
        eva.vtb.account += eva.salary / 2;
    }
    eva.vtb.account += eva.salary;
}


void danil_salary(const int month, const int year)
{
    if (year == 2026) {
        danil.vtb.account += 30'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2027) {
        danil.salary *= 1.25;  // promotion
    }

    if (year == 2027) {
        danil.vtb.account += 40'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2028) {
        danil.salary *= 1.25;  // promotion
    }

    if (year == 2028) {
        danil.vtb.account += 45'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2029) {
        danil.salary *= 1.25;  // promotion
    }

    if (year == 2029) {
        danil.vtb.account += 50'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2030) {
        danil.salary *= 1.4;  // promotion
    }

    if (year == 2030) {
        danil.vtb.account += 55'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2031) {
        danil.salary *= 1.25;  // promotion
    }

    if (year == 2031) {
        danil.vtb.account += 60'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2032) {
        danil.salary *= 1.3;  // promotion
    }

    if (year == 2032) {
        danil.vtb.account += 65'000;  // ежемесячная премия
    }

    if (month == 1 and year == 2033) {
        danil.salary *= 1.1;  // promotion
    }

    if (year == 2033) {
        danil.vtb.account += 70'000;  // ежемесячная премия
    }

    danil.vtb.account += danil.salary;
}


void eva_travel(const int month, const int year)
{
    if (month == 10 and year == 2030)
    {
        eva.vtb.account -= eva.travel.hotel;
        eva.vtb.account -= eva.travel.food;
        eva.vtb.account -= eva.travel.entertainment;
        eva.vtb.account -= eva.travel.ticket * 2;
        eva.vtb.account -= eva.travel.car_rental;
        eva.vtb.account -= eva.travel.transfer;
        eva.vtb.account -= eva.travel.visa;
        eva.vtb.account -= eva.travel.insurance;
        eva.vtb.account -= eva.travel.excursion;
        eva.vtb.account -= eva.travel.shopping;
        eva.vtb.account -= eva.travel.souvenirs;
        eva.vtb.account -= eva.travel.flashlight;
        eva.vtb.account -= eva.travel.travel_clothes;
        eva.vtb.account -= eva.travel.tent;
        eva.vtb.account -= eva.travel.sleeping_bag;
        eva.vtb.account -= eva.travel.backpack;
        eva.vtb.account -= eva.travel.travel_food;
    }

    eva.travel.hotel += eva.travel.hotel * inflation / 100.0 / 12;
    eva.travel.food += eva.travel.food * inflation / 100.0 / 12;
    eva.travel.entertainment += eva.travel.entertainment * inflation / 100.0 / 12;
    eva.travel.ticket += eva.travel.ticket * inflation / 100.0 / 12;
    eva.travel.car_rental += eva.travel.car_rental * inflation / 100.0 / 12;
    eva.travel.transfer += eva.travel.transfer * inflation / 100.0 / 12;
    eva.travel.visa += eva.travel.visa * inflation / 100.0 / 12;
    eva.travel.insurance += eva.travel.insurance * inflation / 100.0 / 12;
    eva.travel.excursion += eva.travel.excursion * inflation / 100.0 / 12;
    eva.travel.shopping += eva.travel.shopping * inflation / 100.0 / 12;
    eva.travel.souvenirs += eva.travel.souvenirs * inflation / 100.0 / 12;
    eva.travel.flashlight += eva.travel.flashlight * inflation / 100.0 / 12;
    eva.travel.travel_clothes += eva.travel.travel_clothes * inflation / 100.0 / 12;
    eva.travel.tent += eva.travel.tent * inflation / 100.0 / 12;
    eva.travel.sleeping_bag += eva.travel.sleeping_bag * inflation / 100.0 / 12;
    eva.travel.backpack += eva.travel.backpack * inflation / 100.0 / 12;
}


void eva_language(const int month, const int year)
{
    if (year == 2030) {
        eva.vtb.account -= eva.language.english;
    }

    if (year == 2031) {
        eva.vtb.account -= eva.language.serbian;
    }

    if (year == 2032) {
        eva.vtb.account -= eva.language.italian;
    }

    if (year == 2033) {
        eva.vtb.account -= eva.language.spainish;
    }

    eva.language.english += eva.language.english * inflation / 100.0 / 12;
    eva.language.serbian += eva.language.serbian * inflation / 100.0 / 12;
    eva.language.italian += eva.language.italian * inflation / 100.0 / 12;
    eva.language.spainish += eva.language.spainish * inflation / 100.0 / 12;
}


void danil_language(const int month, const int year)
{
    if (year == 2026) {
        danil.vtb.account -= danil.language.english;
    }

    if (year == 2027) {
        danil.vtb.account -= danil.language.serbian;
    }

    if (year == 2028) {
        danil.vtb.account -= danil.language.italian;
    }

    if (year == 2029) {
        danil.vtb.account -= danil.language.spainish;
    }

    danil.language.english += danil.language.english * inflation / 100.0 / 12;
    danil.language.serbian += danil.language.serbian * inflation / 100.0 / 12;
    danil.language.italian += danil.language.italian * inflation / 100.0 / 12;
    danil.language.spainish += danil.language.spainish * inflation / 100.0 / 12;
}


void eva_hobby()
{
    eva.vtb.account -= eva.hobby.writing;
    eva.hobby.writing += eva.hobby.writing * inflation / 100.0 / 12;

    eva.vtb.account -= eva.hobby.drawing;
    eva.hobby.drawing += eva.hobby.drawing * inflation / 100.0 / 12;

    eva.vtb.account -= eva.hobby.painting;
    eva.hobby.painting += eva.hobby.painting * inflation / 100.0 / 12;

    eva.vtb.account -= eva.hobby.photography;
    eva.hobby.photography += eva.hobby.photography * inflation / 100.0 / 12;

    eva.vtb.account -= eva.hobby.singing;
    eva.hobby.singing += eva.hobby.singing * inflation / 100.0 / 12;

    eva.vtb.account -= eva.hobby.dancing;
    eva.hobby.dancing += eva.hobby.dancing * inflation / 100.0 / 12;

    eva.vtb.account -= eva.hobby.guitar;
    eva.hobby.guitar += eva.hobby.guitar * inflation / 100.0 / 12;

    eva.vtb.account -= eva.hobby.piano;
    eva.hobby.piano += eva.hobby.piano * inflation / 100.0 / 12;

    eva.vtb.account -= eva.hobby.drums;
    eva.hobby.drums += eva.hobby.drums * inflation / 100.0 / 12;
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
    if (month == 10 and year == 2035) {
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
    if (month == 1) {
        eva.vtb.account -= eva.luxery.nogti;
        eva.vtb.account -= eva.luxery.jewelry;
        eva.vtb.account -= eva.luxery.eyebrows;
    }

    if (month == 3) {
        eva.vtb.account -= eva.luxery.gucci_sumki;
        eva.vtb.account -= eva.luxery.prada_obuv;
        eva.vtb.account -= eva.luxery.lv_koshelek;
    }

    if (month == 5) {
        eva.vtb.account -= eva.luxery.dior_ochki;
        eva.vtb.account -= eva.luxery.chanel_pomada;
        eva.vtb.account -= eva.luxery.hermes_braslet;
    }

    if (month == 7) {
        eva.vtb.account -= eva.luxery.rolex_chasy;
        eva.vtb.account -= eva.luxery.versace_platye;
        eva.vtb.account -= eva.luxery.valentino_kabluki;
    }

    if (month == 9) {
        eva.vtb.account -= eva.luxery.balenciaga_hudi;
        eva.vtb.account -= eva.luxery.fendi_remen;
        eva.vtb.account -= eva.luxery.bottega_klatch;
    }

    if (month == 11) {
        eva.vtb.account -= eva.luxery.ysl_pudra;
        eva.vtb.account -= eva.luxery.tom_ford_duhi;
        eva.vtb.account -= eva.luxery.cartier_koltso;
    }

    if (month == 2) {
        eva.vtb.account -= eva.luxery.haircut;
        eva.vtb.account -= eva.luxery.perfume;
        eva.vtb.account -= eva.luxery.tan;
    }

    if (month == 4) {
        eva.vtb.account -= eva.luxery.dolce_gabbana_kupalnik;
        eva.vtb.account -= eva.luxery.burberry_plash;
        eva.vtb.account -= eva.luxery.armani_pidzhak;
    }

    if (month == 6) {
        eva.vtb.account -= eva.luxery.ralph_lauren_rusbashka;
        eva.vtb.account -= eva.luxery.zegna_kostum;
        eva.vtb.account -= eva.luxery.brioni_galstuk;
    }

    if (month == 8) {
        eva.vtb.account -= eva.luxery.roberto_cavalli_ochki;
        eva.vtb.account -= eva.luxery.maison_margiela_boots;
        eva.vtb.account -= eva.luxery.balmain_blazer;
    }

    if (month == 10) {
        eva.vtb.account -= eva.luxery.offwhite_futbolka;
        eva.vtb.account -= eva.luxery.golden_goose_krossy;
        eva.vtb.account -= eva.luxery.acne_jeans;
    }

    if (month == 12) {
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
    if (month == 1) {
        danil.vtb.account -= danil.luxery.haircut;
    }

    if (month == 3) {
        danil.vtb.account -= danil.luxery.face_cleaning;
    }

    if (month == 5) {
        danil.vtb.account -= danil.luxery.massage;
    }

    if (month == 7) {
        danil.vtb.account -= danil.luxery.spa;
    }

    if (month == 9) {
        danil.vtb.account -= danil.luxery.teeth_whitening;
    }

    if (month == 11) {
        danil.vtb.account -= danil.luxery.eyebrows_correction;
    }

    if (month == 4) {
        danil.vtb.account -= danil.luxery.perfume;
    }

    if (month == 8) {
        danil.vtb.account -= danil.luxery.perfume_exclusive;
    }

    if (month == 12) {
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


void eva_cat(const int month, const int year)
{
    eva.cat.food += eva.cat.food * inflation / 100.0 / 12;
    eva.cat.napolnitel += eva.cat.napolnitel * inflation / 100.0 / 12;
    eva.cat.osheinik += eva.cat.osheinik * inflation / 100.0 / 12;
    eva.cat.toys += eva.cat.toys * inflation / 100.0 / 12;
    eva.cat.sale += eva.cat.sale * inflation / 100.0 / 12;

    if (month == 6 and year == 2027 and not eva.cat.eva_cat_is_alive) {
        eva.vtb.deposite -= eva.cat.sale;
        eva.cat.eva_cat_is_alive = true;
    }

    if (not eva.cat.eva_cat_is_alive) return;

    if (month == 5 and year == 2036) { //rip
        eva.cat.eva_cat_is_alive = false;
        return;
    }

    if (eva.cat.eva_cat_is_alive) {
        eva.vtb.account -= eva.cat.food;
        eva.vtb.account -= eva.cat.napolnitel;

        if (month == 7 and year == 2027) {
            eva.vtb.account -= eva.cat.osheinik;
        }

        if (month == 8 and year == 2027) {
            eva.vtb.account -= eva.cat.toys;
        }
    }
}


void danil_dog(const int month, const int year)
{
    danil.dog.food += danil.dog.food * inflation / 100.0 / 12;
    danil.dog.grooming += danil.dog.grooming * inflation / 100.0 / 12;
    danil.dog.sale += danil.dog.sale * inflation / 100.0 / 12;
    danil.dog.vet += danil.dog.vet * inflation / 100.0 / 12;
    danil.dog.napolnitel += danil.dog.napolnitel * inflation / 100.0 / 12;
    danil.dog.osheinik += danil.dog.osheinik * inflation / 100.0 / 12;

    if (month == 7 and year == 2026 and not danil.dog.danil_dog_is_alive) {
        danil.vtb.deposite -= danil.dog.sale;
        danil.dog.danil_dog_is_alive = true;
    }

    if (not danil.dog.danil_dog_is_alive) return;

    if (month == 3 and year == 2040) { //rip
        danil.dog.danil_dog_is_alive = false;
        return;
    }

    if (danil.dog.danil_dog_is_alive) {
        if (month == 8 and year == 2026) {
            danil.vtb.account -= danil.dog.osheinik;
        }

        danil.vtb.account -= danil.dog.food;
        danil.vtb.account -= danil.dog.grooming;
        danil.vtb.account -= danil.dog.vet;
        danil.vtb.account -= danil.dog.napolnitel;
    }
}


void evas_popugay(const int month, const int year)
{
    eva.popugay.sale += eva.popugay.sale * inflation / 100.0 / 12;
    eva.popugay.food += eva.popugay.food * inflation / 100.0 / 12;
    eva.popugay.toys += eva.popugay.toys * inflation / 100.0 / 12;
    eva.popugay.kletka += eva.popugay.kletka * inflation / 100.0 / 12;

    if (month == 7 and year == 2027 and not eva.popugay.eva_popugay_is_alive) {
        eva.vtb.deposite -= eva.popugay.sale;
        eva.popugay.eva_popugay_is_alive = true;
    }

    if (not eva.popugay.eva_popugay_is_alive) return;

    if (month == 4 and year == 2040) { //rip
        eva.popugay.eva_popugay_is_alive = false;
        return;
    }

    if (eva.popugay.eva_popugay_is_alive) {
        if (month == 8 and year == 2027) {
            eva.vtb.account -= eva.popugay.kletka;
        }

        eva.vtb.account -= eva.popugay.food;
        eva.vtb.account -= eva.popugay.toys;
    }
}


void eva_food()
{
    eva.vtb.account -= eva.food.eggs * 8;
    eva.food.eggs += eva.food.eggs * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.chicken_breast * 20;
    eva.food.chicken_breast += eva.food.chicken_breast * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.turkey * 25;
    eva.food.turkey += eva.food.turkey * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.salmon * 50;
    eva.food.salmon += eva.food.salmon * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.tuna * 30;
    eva.food.tuna += eva.food.tuna * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.oatmeal * 10;
    eva.food.oatmeal += eva.food.oatmeal * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.buckwheat * 15;
    eva.food.buckwheat += eva.food.buckwheat * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.quinoa * 25;
    eva.food.quinoa += eva.food.quinoa * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.rice * 10;
    eva.food.rice += eva.food.rice * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.avocado * 30;
    eva.food.avocado += eva.food.avocado * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.broccoli * 10;
    eva.food.broccoli += eva.food.broccoli * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.spinach * 10;
    eva.food.spinach += eva.food.spinach * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.cucumber * 10;
    eva.food.cucumber += eva.food.cucumber * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.tomatoes * 10;
    eva.food.tomatoes += eva.food.tomatoes * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.bell_pepper * 10;
    eva.food.bell_pepper += eva.food.bell_pepper * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.carrots * 10;
    eva.food.carrots += eva.food.carrots * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.cabbage * 10;
    eva.food.cabbage += eva.food.cabbage * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.greek_yogurt * 20;
    eva.food.greek_yogurt += eva.food.greek_yogurt * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.cottage_cheese * 20;
    eva.food.cottage_cheese += eva.food.cottage_cheese * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.milk * 10;
    eva.food.milk += eva.food.milk * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.nuts * 20;
    eva.food.nuts += eva.food.nuts * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.almonds * 20;
    eva.food.almonds += eva.food.almonds * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.walnuts * 20;
    eva.food.walnuts += eva.food.walnuts * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.berries * 20;
    eva.food.berries += eva.food.berries * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.blueberries * 20;
    eva.food.blueberries += eva.food.blueberries * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.strawberries * 20;
    eva.food.strawberries += eva.food.strawberries * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.banana * 20;
    eva.food.banana += eva.food.banana * inflation / 100.0 / 12;
}


void danil_food()
{
    danil.vtb.account -= danil.food.eggs * 10;
    danil.food.eggs += danil.food.eggs * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.bread * 30;
    danil.food.bread += danil.food.bread * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.milk * 50;
    danil.food.milk += danil.food.milk * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.meat * 200;
    danil.food.meat += danil.food.meat * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.vegetables * 100;
    danil.food.vegetables += danil.food.vegetables * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.potatoes * 50;
    danil.food.potatoes += danil.food.potatoes * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.pasta * 50;
    danil.food.pasta += danil.food.pasta * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.rice * 50;
    danil.food.rice += danil.food.rice * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.chicken * 150;
    danil.food.chicken += danil.food.chicken * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.pork * 150;
    danil.food.pork += danil.food.pork * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.beef * 200;
    danil.food.beef += danil.food.beef * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.sausage * 100;
    danil.food.sausage += danil.food.sausage * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.cheese * 100;
    danil.food.cheese += danil.food.cheese * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.butter * 50;
    danil.food.butter += danil.food.butter * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.buckwheat * 50;
    danil.food.buckwheat += danil.food.buckwheat * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.bacon * 100;
    danil.food.bacon += danil.food.bacon * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.french_fries * 50;
    danil.food.french_fries += danil.food.french_fries * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.pizza * 200;
    danil.food.pizza += danil.food.pizza * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.burger * 150;
    danil.food.burger += danil.food.burger * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.instant_noodles * 50;
    danil.food.instant_noodles += danil.food.instant_noodles * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.chips * 50;
    danil.food.chips += danil.food.chips * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.beer * 100;
    danil.food.beer += danil.food.beer * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.soda * 50;
    danil.food.soda += danil.food.soda * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.mayonnaise * 50;
    danil.food.mayonnaise += danil.food.mayonnaise * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.ice_cream * 50;
    danil.food.ice_cream += danil.food.ice_cream * inflation / 100.0 / 12;
}


void eva_home_hoz(const int month, const int year)
{
    if (month == 5 and year == 2028) {
        eva.vtb.account -= eva.ht.holodos;
    }

    if (month == 6 and year == 2029) {
        eva.vtb.account -= eva.ht.tv;
    }

    if (month == 7 and year == 2030) {
        eva.vtb.account -= eva.ht.washing_machine;
    }

    if (month == 8 and year == 2031) {
        eva.vtb.account -= eva.ht.microwave;
    }

    if (month == 9 and year == 2032) {
        eva.vtb.account -= eva.ht.oven;
    }

    if (month == 10 and year == 2033) {
        eva.vtb.account -= eva.ht.kover;
    }

    if (month == 11 and year == 2034) {
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
    if (month == 5 and year == 2027) {
        danil.vtb.account -= danil.ht.holodos;
    }

    danil.ht.holodos += danil.ht.holodos * inflation / 100.0 / 12;

    if (month == 6 and year == 2027) {
        danil.vtb.account -= danil.ht.tv;
        danil.vtb.account -= danil.ht.vacuum_cleaner;
        danil.vtb.account -= danil.ht.iron;
        danil.vtb.account -= danil.ht.toaster;
        danil.vtb.account -= danil.ht.kettle;
        danil.vtb.account -= danil.ht.furniture;
        danil.vtb.account -= danil.ht.curtains;
        danil.vtb.account -= danil.ht.bedding;
        danil.vtb.account -= danil.ht.towels;
        danil.vtb.account -= danil.ht.kitchen_utensils;
        danil.vtb.account -= danil.ht.fridge_freezer;
        danil.vtb.account -= danil.ht.dishwasher;
        danil.vtb.account -= danil.ht.coffee_machine;
        danil.vtb.account -= danil.ht.blender;
        danil.vtb.account -= danil.ht.mixer;
        danil.vtb.account -= danil.ht.food_processor;
        danil.vtb.account -= danil.ht.air_conditioner;
        danil.vtb.account -= danil.ht.heater;
        danil.vtb.account -= danil.ht.humidifier;
        danil.vtb.account -= danil.ht.air_purifier;
        danil.vtb.account -= danil.ht.lamp;
        danil.vtb.account -= danil.ht.chandelier;
        danil.vtb.account -= danil.ht.carpet;
        danil.vtb.account -= danil.ht.rug;
        danil.vtb.account -= danil.ht.mirror;
        danil.vtb.account -= danil.ht.wardrobe;
        danil.vtb.account -= danil.ht.chest_of_drawers;
        danil.vtb.account -= danil.ht.shelf;
        danil.vtb.account -= danil.ht.table;

    }

    danil.ht.tv += danil.ht.tv * inflation / 100.0 / 12;
    danil.ht.vacuum_cleaner += danil.ht.vacuum_cleaner * inflation / 100.0 / 12;
    danil.ht.iron += danil.ht.iron * inflation / 100.0 / 12;
    danil.ht.toaster += danil.ht.toaster * inflation / 100.0 / 12;
    danil.ht.kettle += danil.ht.kettle * inflation / 100.0 / 12;
    danil.ht.furniture += danil.ht.furniture * inflation / 100.0 / 12;
    danil.ht.curtains += danil.ht.curtains * inflation / 100.0 / 12;
    danil.ht.bedding += danil.ht.bedding * inflation / 100.0 / 12;
    danil.ht.towels += danil.ht.towels * inflation / 100.0 / 12;
    danil.ht.kitchen_utensils += danil.ht.kitchen_utensils * inflation / 100.0 / 12;
    danil.ht.fridge_freezer += danil.ht.fridge_freezer * inflation / 100.0 / 12;
    danil.ht.dishwasher += danil.ht.dishwasher * inflation / 100.0 / 12;
    danil.ht.coffee_machine += danil.ht.coffee_machine * inflation / 100.0 / 12;
    danil.ht.blender += danil.ht.blender * inflation / 100.0 / 12;
    danil.ht.mixer += danil.ht.mixer * inflation / 100.0 / 12;
    danil.ht.food_processor += danil.ht.food_processor * inflation / 100.0 / 12;
    danil.ht.air_conditioner += danil.ht.air_conditioner * inflation / 100.0 / 12;
    danil.ht.heater += danil.ht.heater * inflation / 100.0 / 12;
    danil.ht.humidifier += danil.ht.humidifier * inflation / 100.0 / 12;
    danil.ht.air_purifier += danil.ht.air_purifier * inflation / 100.0 / 12;
    danil.ht.lamp += danil.ht.lamp * inflation / 100.0 / 12;
    danil.ht.chandelier += danil.ht.chandelier * inflation / 100.0 / 12;
    danil.ht.carpet += danil.ht.carpet * inflation / 100.0 / 12;
    danil.ht.rug += danil.ht.rug * inflation / 100.0 / 12;
    danil.ht.mirror += danil.ht.mirror * inflation / 100.0 / 12;
    danil.ht.chest_of_drawers += danil.ht.chest_of_drawers * inflation / 100.0 / 12;
    danil.ht.shelf += danil.ht.shelf * inflation / 100.0 / 12;
    danil.ht.table += danil.ht.table * inflation / 100.0 / 12;
}


void eva_solyariy(const int month, const int year)
{
    if (month == 2) {
        eva.vtb.account -= eva.solyariy.session_10_min;
        eva.vtb.account -= eva.solyariy.cream_bronzer;
        eva.vtb.account -= eva.solyariy.cream_tan_accelerator;
        eva.vtb.account -= eva.solyariy.cream_after_sun;
        eva.vtb.account -= eva.solyariy.lip_balm_spf;
        eva.vtb.account -= eva.solyariy.stickers_eyes;
        eva.vtb.account -= eva.solyariy.cap;
        eva.vtb.account -= eva.solyariy.sunglasses;
        eva.vtb.account -= eva.solyariy.towel;
        eva.vtb.account -= eva.solyariy.shoe_covers;
        eva.vtb.account -= eva.solyariy.spray_cooling;
        eva.vtb.account -= eva.solyariy.lotion_warm;
    }

    eva.solyariy.session_10_min += eva.solyariy.session_10_min * inflation / 100.0 / 12;
    eva.solyariy.session_15_min += eva.solyariy.session_15_min * inflation / 100.0 / 12;
    eva.solyariy.cream_bronzer += eva.solyariy.cream_bronzer * inflation / 100.0 / 12;
    eva.solyariy.cream_tan_accelerator += eva.solyariy.cream_tan_accelerator * inflation / 100.0 / 12;
    eva.solyariy.cream_after_sun += eva.solyariy.cream_after_sun * inflation / 100.0 / 12;
    eva.solyariy.lip_balm_spf += eva.solyariy.lip_balm_spf * inflation / 100.0 / 12;
    eva.solyariy.stickers_eyes += eva.solyariy.stickers_eyes * inflation / 100.0 / 12;
    eva.solyariy.cap += eva.solyariy.cap * inflation / 100.0 / 12;
    eva.solyariy.sunglasses += eva.solyariy.sunglasses * inflation / 100.0 / 12;
    eva.solyariy.towel += eva.solyariy.towel * inflation / 100.0 / 12;
    eva.solyariy.shoe_covers += eva.solyariy.shoe_covers * inflation / 100.0 / 12;
    eva.solyariy.spray_cooling += eva.solyariy.spray_cooling * inflation / 100.0 / 12;
    eva.solyariy.lotion_warm += eva.solyariy.lotion_warm * inflation / 100.0 / 12;
}


void eva_subscribe(const int month, const int year)
{
    if (year == 2026) {
        eva.vtb.account -= eva.subscribe.youtube_premium;
        eva.vtb.account -= eva.subscribe.spotify;
        eva.vtb.account -= eva.subscribe.kinopoisk;
        eva.vtb.account -= eva.subscribe.ivi;
        eva.vtb.account -= eva.subscribe.vk_combo;
    }

    if (year == 2027) {
        eva.vtb.account -= eva.subscribe.sber_prime;
        eva.vtb.account -= eva.subscribe.yandex_plus;
        eva.vtb.account -= eva.subscribe.apple_music;
        eva.vtb.account -= eva.subscribe.telegram_premium;
        eva.vtb.account -= eva.subscribe.chat_gpt;
    }

    if (year == 2028) {
        eva.vtb.account -= eva.subscribe.midjourney;
        eva.vtb.account -= eva.subscribe.photoshop;
        eva.vtb.account -= eva.subscribe.stepik;
        eva.vtb.account -= eva.subscribe.ps_plus;
        eva.vtb.account -= eva.subscribe.game_pass;
        eva.vtb.account -= eva.subscribe.youtube_premium;
        eva.vtb.account -= eva.subscribe.spotify;
    }

    if (year == 2029) {
        eva.vtb.account -= eva.subscribe.nintendo_online;
        eva.vtb.account -= eva.subscribe.icloud_plus;
        eva.vtb.account -= eva.subscribe.google_drive;
        eva.vtb.account -= eva.subscribe.yandex_disk;
        eva.vtb.account -= eva.subscribe.dropbox;
        eva.vtb.account -= eva.subscribe.sber_prime;
        eva.vtb.account -= eva.subscribe.yandex_plus;
    }

    if (year == 2030) {
        eva.vtb.account -= eva.subscribe.tele2;
        eva.vtb.account -= eva.subscribe.tinkoff_pro;
        eva.vtb.account -= eva.subscribe.sber_pravda;
        eva.vtb.account -= eva.subscribe.bank_commission;
        eva.vtb.account -= eva.subscribe.domclick;
        eva.vtb.account -= eva.subscribe.midjourney;
        eva.vtb.account -= eva.subscribe.photoshop;
    }

    if (year == 2031) {
        eva.vtb.account -= eva.subscribe.avito;
        eva.vtb.account -= eva.subscribe.linkedin;
        eva.vtb.account -= eva.subscribe.habr;
        eva.vtb.account -= eva.subscribe.nintendo_online;
        eva.vtb.account -= eva.subscribe.icloud_plus;
    }

    eva.subscribe.youtube_premium += eva.subscribe.youtube_premium * inflation / 100.0 / 12;
    eva.subscribe.spotify += eva.subscribe.spotify * inflation / 100.0 / 12;
    eva.subscribe.kinopoisk += eva.subscribe.kinopoisk * inflation / 100.0 / 12;
    eva.subscribe.ivi += eva.subscribe.ivi * inflation / 100.0 / 12;
    eva.subscribe.vk_combo += eva.subscribe.vk_combo * inflation / 100.0 / 12;
    eva.subscribe.sber_prime += eva.subscribe.sber_prime * inflation / 100.0 / 12;
    eva.subscribe.yandex_plus += eva.subscribe.yandex_plus * inflation / 100.0 / 12;
    eva.subscribe.apple_music += eva.subscribe.apple_music * inflation / 100.0 / 12;
    eva.subscribe.telegram_premium += eva.subscribe.telegram_premium * inflation / 100.0 / 12;
    eva.subscribe.chat_gpt += eva.subscribe.chat_gpt * inflation / 100.0 / 12;
    eva.subscribe.midjourney += eva.subscribe.midjourney * inflation / 100.0 / 12;
    eva.subscribe.photoshop += eva.subscribe.photoshop * inflation / 100.0 / 12;
    eva.subscribe.stepik += eva.subscribe.stepik * inflation / 100.0 / 12;
    eva.subscribe.ps_plus += eva.subscribe.ps_plus * inflation / 100.0 / 12;
    eva.subscribe.game_pass += eva.subscribe.game_pass * inflation / 100.0 / 12;
    eva.subscribe.nintendo_online += eva.subscribe.nintendo_online * inflation / 100.0 / 12;
    eva.subscribe.icloud_plus += eva.subscribe.icloud_plus * inflation / 100.0 / 12;
    eva.subscribe.google_drive += eva.subscribe.google_drive * inflation / 100.0 / 12;
    eva.subscribe.yandex_disk += eva.subscribe.yandex_disk * inflation / 100.0 / 12;
    eva.subscribe.dropbox += eva.subscribe.dropbox * inflation / 100.0 / 12;
    eva.subscribe.tele2 += eva.subscribe.tele2 * inflation / 100.0 / 12;
    eva.subscribe.tinkoff_pro += eva.subscribe.tinkoff_pro * inflation / 100.0 / 12;
    eva.subscribe.sber_pravda += eva.subscribe.sber_pravda * inflation / 100.0 / 12;
    eva.subscribe.bank_commission += eva.subscribe.bank_commission * inflation / 100.0 / 12;
    eva.subscribe.domclick += eva.subscribe.domclick * inflation / 100.0 / 12;
    eva.subscribe.avito += eva.subscribe.avito * inflation / 100.0 / 12;
    eva.subscribe.linkedin += eva.subscribe.linkedin * inflation / 100.0 / 12;
    eva.subscribe.habr += eva.subscribe.habr * inflation / 100.0 / 12;
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

    if (month == 6) {
        eva.vtb.account -= eva.car.mazda_antifreeze;
        eva.vtb.account -= eva.car.repair * 6;
    }

    if (month == 4) {
        eva.vtb.account -= eva.car.mazda_air_filter;
        eva.vtb.account -= eva.car.mazda_oil_filter;
        eva.vtb.account -= eva.car.mazda_oil;
        eva.vtb.account -= eva.car.mazda_clutch;
        eva.vtb.account -= eva.car.repair * 15;
    }

    if (month == 4) {
        eva.vtb.account -= eva.car.mazda_tires;
        eva.vtb.account -= eva.car.repair * 3;
    }

    if (month == 11) {
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
    if (month == 7) {
        danil.vtb.account -= danil.car.bmw_air_filter;
        danil.vtb.account -= danil.car.bmw_oil_filter;
        danil.vtb.account -= danil.car.bmw_oil;
        danil.vtb.account -= danil.car.bmw_clutch;
        danil.vtb.account -= danil.car.repair * 20;
    }

    danil.vtb.account -= danil.car.bmw_omyvaika;

    if (month == 6) {
        danil.vtb.account -= danil.car.bmw_antifreeze;
        danil.vtb.account -= danil.car.repair * 3.5;
    }

    if (month == 12) {
        danil.vtb.account -= danil.car.bmw_antifreeze;
        danil.vtb.account -= danil.car.repair * 3.5;
    }

    if (month == 4) {
        danil.vtb.account -= danil.car.bmw_tires * 4;
        danil.vtb.account -= danil.car.repair * 2.5;
    }

    if (month == 11) {
        danil.vtb.account -= danil.car.bmw_tires * 4;
        danil.vtb.account -= danil.car.repair * 2.5;
    }

    if (month == 10 and year == 2026) {
        danil.vtb.account -= danil.car.bmw_wheels * 4;
        danil.vtb.account -= danil.car.bmw_spring * 4;
        danil.vtb.account -= danil.car.bmw_control_arm * 4;
        danil.vtb.account -= danil.car.repair * 10;
    }

    if (month == 6 and year == 2027) {
        danil.vtb.account -= danil.car.bmw_starter;
        danil.vtb.account -= danil.car.bmw_muffler;
        danil.vtb.account -= danil.car.bmw_exhaust;
        danil.vtb.account -= danil.car.battery;
        danil.vtb.account -= danil.car.bmw_radiator;
        danil.vtb.account -= danil.car.bmw_fan;
        danil.vtb.account -= danil.car.repair * 30;
    }

    if (month == 10 and year == 2027) {
        danil.vtb.account -= danil.car.bmw_transmission;
        danil.vtb.account -= danil.car.repair * 10;
    }

    if (month == 4 and year == 2028) {
        danil.vtb.account -= danil.car.bmw_engine;
        danil.vtb.account -= danil.car.bmw_piston * 4;
        danil.vtb.account -= danil.car.bmw_valve * 16;
        danil.vtb.account -= danil.car.bmw_spark_plug * 6;
        danil.vtb.account -= danil.car.bmw_timing_belt;
        danil.vtb.account -= danil.car.bmw_steering_rack;
        danil.vtb.account -= danil.car.repair * 150;
    }

    if (month == 7 and year == 2032) {
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
    danil.vtb.account = 0;
}


void eva_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        eva.vtb.account += 3'000;
    };

    if (month == 4 and year == 2027) {
        eva.vtb.account += 10'000;
    };

    if (month == 6 and year == 2027) {
        eva.vtb.account += 12'000;
    };

    if (month == 7 and year == 2027) {
        eva.vtb.account += 20'000;
    };

    if (month == 8 and year == 2027) {
        eva.vtb.account += 15'000;
    };

    if (month == 9 and year == 2027) {
        eva.vtb.account += 12'000;
    };

    if (month == 10 and year == 2027) {
        eva.vtb.account += 6'000;
    };

    if (month == 11 and year == 2027) {
        eva.vtb.account += 12'000;
    };

    if (month == 12 and year == 2027) {
        eva.vtb.account += 100'000;
    };

    if (year == 2028) {
        eva.vtb.account += 30'000;
    }
}


void danil_freelance(const int month, const int year)
{
    if (year == 2026) {
        danil.vtb.account += 15'000;
    }

    if (year == 2027) {
        danil.vtb.account += 25'000;
    }

    if (year == 2028) {
        danil.vtb.account += 35'000;
    }

    if (year == 2029) {
        danil.vtb.account += 45'000;
    }

    if (year == 2030) {
        danil.vtb.account += 55'000;
    }

    if (year == 2031) {
        danil.vtb.account += 60'000;
    }

    if (year == 2032) {
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
        eva_deposite(month, year);

        danil_salary(month, year);
        danil_hobby();
        danil_kvartira();
        danil_luxery(month, year);
        danil_dog(month, year);
        danil_freelance(month, year);
        danil_car(month, year);
        danil_food();
        danil_home_hoz(month, year);
        danil_gym(month, year);
        danil_language(month, year);
        danil_banya(month, year);
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