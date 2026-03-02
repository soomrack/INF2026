#include <stdio.h>
#include <iostream>
#include <cmath>
//проверить на все ли существует инфляция(?), возмооожно заморочиться с налогами
using RUB = float;
using EUR = float;
using Percent = float;
bool newflat_own = false;
float inflation = 9.4f / 100.0f;
RUB newflat = 15'000'000;


struct Bank {

    RUB account;
    RUB deposite;
    Percent interest;

    EUR account_eur;
    float rate_eur_rub;

};


struct Car {

    RUB gas;
    RUB value;
	RUB wash;
	RUB penalty;
    RUB osago;
	RUB kasko;
    RUB washer_fluid;
    RUB antifreez;
    RUB tires;
	RUB tax_for_a_car;

};


struct Car_service {

    RUB service;
	RUB repair;

};


struct Girlfriend {

    RUB date;
    RUB flowers;

};


struct Flat {

    RUB rent;
    RUB HCS; // housing and communal services

};


struct Friends {
    
	//davis friends
    RUB beer;
	RUB fast_food;
	RUB cinema;
	RUB games;
	RUB bowling;
	RUB karaoke;
	RUB concerts;
	RUB billiard;

    //lisas girlfriends
	RUB coffe;
	RUB brunch;
	RUB cinema_lisa;
	RUB fotosession;
	RUB shopping;
	RUB spa;
	RUB massage;
	RUB restaurant;
	RUB taxi;
	RUB club;

};


struct Gym {

    RUB subscription;
    RUB protein;

};


struct Cat {

    RUB eat_for_cat;
    RUB toilet_for_cat;

};


struct Cosmetic {

    RUB pomade;
    RUB mascara;
    RUB foundation;
    RUB summ;

};


struct Gifts
{

    RUB gifts;

};


struct Hobbies 
{

	//davis hobbies

	RUB guitar;
    RUB hobbies;
	RUB golf;
	RUB skiing;
	RUB tennis;
	RUB fishing;
	RUB hiking;
	RUB books;
	RUB video_games;
	RUB machines;

	//lisa hobbies
    
	RUB dancing;
	RUB painting;
    RUB art;
	RUB fashion;
	RUB sewing;
	RUB jewelry;
	RUB cooking;
	RUB baking;
	RUB photography;
    RUB music;

};

struct Clothes {
    RUB shoes;
	RUB pants;
	RUB shirt;
    RUB jacket;
	RUB hat;
	RUB socks;
	RUB underwear;
	RUB accessories;
	RUB coat;
	RUB gloves;
	RUB scarf;
	RUB swimsuit;
	RUB dress;
	RUB t_shirt;
	RUB sweatshirt;
    RUB swimwear;
	RUB sportswear;
	RUB dresses;
	RUB skirts;
	RUB blouses;

};


struct Medicine {

    RUB visit_to_a_doctor;

    RUB ibuprofen_200mg;
	RUB paracetamol_500mg;
    RUB vitamin_c_effervescent;
    RUB multivitamin_daily;
    RUB vitamin_b12_sublingual;
    RUB iron_complex_vegan;
	RUB algae_omega3;
    RUB plant_protein_powder;
    RUB whey_protein_isolate;
    RUB creatine_monohydrate;
    RUB bcaa_powder;
    RUB joint_support_complex;
    RUB electrolyte_tabs;
    RUB caffeine_pills_200mg;
    RUB melatonin_3mg;
    RUB probiotic_capsules;
    RUB antacid_chewable;
    RUB cough_syrup_100ml;
    RUB bandage_elastic;
    RUB magnesium_glycinate;

};


struct Food {

    RUB ovsyanka;
    RUB eggs;
    RUB apples;
    RUB chiken;
    RUB buckwheat;
    RUB broccoli;
    RUB fish;
    RUB rice;
    RUB tomatoes;
    RUB cucumbers;
    RUB nuts;
    RUB tvorog;
    RUB bananas;
    RUB potato;
    RUB spinach;
    RUB yogurt;
    RUB olive_oil;
    RUB bread;
    RUB frozen_berries;

    RUB oatmeal;
    RUB almonds;
    RUB chia;
    RUB banana;
    RUB tofu;
    RUB quinoa;
    RUB lentils;
    RUB pepper;
    RUB chikpeas;
    RUB brown_rice;
    RUB avocados;
    RUB carrots;
    RUB orange;
    RUB hummus;
    RUB oat_milk;

    RUB dark_chocolate_75;
    RUB protein_bar;
    RUB honey;
    RUB marshmallow_sugar_free;
    RUB peanut_butter;
    RUB salmon_fillet;
    RUB beef_steak;
    RUB sweet_potato;
    RUB bell_pepper_red;
    RUB cauliflower;
    RUB chia_seeds;
    RUB coconut_oil;
    RUB green_tea_bags;
    RUB coffee_beans;

    RUB vegan_chocolate;
    RUB fruit_leather;
    RUB coconut_chips;
    RUB agave_syrup;
    RUB vegan_cookies;
    RUB tofu_smoked;
    RUB tempeh;
    RUB seitan;
    RUB edamame;
    RUB nutritional_yeast;
    RUB soy_sauce;
    RUB coconut_yogurt;
    RUB matcha_powder;
    RUB dates;
    RUB cacao_nibs;
};


struct Person {

    Bank tb;
    Car car;
    Gym gym;
    Flat flat;
    Girlfriend girlfriend;
    Friends friends;
    Car_service car_service;
    Cat cat;
    Cosmetic cosmetic;
    Gifts gifts;
    Food food;
	Medicine medicine;
	Hobbies hobbies;
	Clothes clothing;


    RUB boyfriend;
    RUB holiday;
    RUB salary;

};


struct Person davis;
struct Person lisa;


void davis_init()
{

    davis.tb.account = 0;
    davis.tb.deposite = 10'000;
    davis.tb.interest = 14.5;
    davis.salary = 300'000;

    davis.tb.account_eur = 5000;
    davis.tb.rate_eur_rub = 90.45;

    davis.food.ovsyanka = 20;
    davis.food.eggs = 12;
    davis.food.apples = 8;
    davis.food.chiken = 25;
    davis.food.buckwheat = 6;
    davis.food.broccoli = 15;
    davis.food.fish = 30;
    davis.food.rice = 7;
    davis.food.tomatoes = 12;
    davis.food.cucumbers = 10;
    davis.food.nuts = 80;
    davis.food.tvorog = 25;
    davis.food.bananas = 9;
    davis.food.avocados = 75;
    davis.food.potato = 3;
    davis.food.spinach = 20;
    davis.food.orange = 10;
    davis.food.yogurt = 15;
    davis.food.olive_oil = 66;
    davis.food.bread = 20;
    davis.food.frozen_berries = 30;

    davis.food.dark_chocolate_75 = 90;
    davis.food.protein_bar = 120;
    davis.food.honey = 40;
    davis.food.marshmallow_sugar_free = 35;
    davis.food.peanut_butter = 60;
    davis.food.salmon_fillet = 80;
    davis.food.beef_steak = 70;
    davis.food.sweet_potato = 8;
    davis.food.bell_pepper_red = 15;
    davis.food.cauliflower = 14;
    davis.food.chia_seeds = 100;
    davis.food.coconut_oil = 50;
    davis.food.green_tea_bags = 200;
    davis.food.coffee_beans = 150;
    
    davis.car.value = 1'800'000;
    davis.car.gas = 15'000;
	davis.car.wash = 500;
	davis.car.penalty = 5'000;
	davis.car.osago = 10'000;
	davis.car.kasko = 20'000;
	davis.car.washer_fluid = 300;
	davis.car.antifreez = 500;
	davis.car.tires = 20'000;
	davis.car.tax_for_a_car = 12'000;
    
    davis.car_service.service = 10'000;
	davis.car_service.repair = 20'000;

    davis.girlfriend.date = 10'000;

    davis.gym.subscription = 1'600;
    davis.gym.protein = 1'000;

    davis.flat.rent = 60'000;
    davis.flat.HCS = 5'000;
    
    davis.cat.eat_for_cat = 1'000;
    davis.cat.toilet_for_cat = 500;

    davis.friends.beer = 2'000;
	davis.friends.fast_food = 1'500;
	davis.friends.cinema = 1'000;
	davis.friends.games = 1'500;
	davis.friends.bowling = 1'000;
	davis.friends.karaoke = 1'000;
	davis.friends.concerts = 2'000;
	davis.friends.billiard = 1'000;

    davis.gifts.gifts = 15'000;
    
	davis.medicine.visit_to_a_doctor = 2'000;

    davis.holiday = lisa.holiday = 10'000;

    davis.medicine.whey_protein_isolate = 2800;
    davis.medicine.creatine_monohydrate = 1200;
    davis.medicine.bcaa_powder = 1500;
    davis.medicine.joint_support_complex = 1100;
    davis.medicine.electrolyte_tabs = 400;
    davis.medicine.caffeine_pills_200mg = 200;


    davis.medicine.ibuprofen_200mg = 85;
    davis.medicine.paracetamol_500mg = 40;
    davis.medicine.vitamin_c_effervescent = 250;
    davis.medicine.multivitamin_daily = 450;
    davis.medicine.magnesium_glycinate = 600;
    davis.medicine.melatonin_3mg = 550;
    davis.medicine.probiotic_capsules = 800;
    davis.medicine.antacid_chewable = 250;
    davis.medicine.cough_syrup_100ml = 380;
    davis.medicine.bandage_elastic = 150;

	davis.hobbies.guitar = 1'000;
	davis.hobbies.hobbies = 1'500;
	davis.hobbies.golf = 2'000;
	davis.hobbies.skiing = 3'000;
	davis.hobbies.tennis = 2'000;
	davis.hobbies.fishing = 1'500;
	davis.hobbies.hiking = 1'000;
	davis.hobbies.books = 1'500;
	davis.hobbies.video_games = 2'000;
	davis.hobbies.machines = 3'000;

}


void lisa_init()
{

    lisa.car.value = 0;
	lisa.car.gas = 10'000;
	lisa.car.wash = 500;
	lisa.car.penalty = 5'000;
	lisa.car.osago = 10'000;
	lisa.car.kasko = 20'000;
	lisa.car.washer_fluid = 300;
	lisa.car.antifreez = 500;
	lisa.car.tires = 20'000;
	lisa.car.tax_for_a_car = 12'000;
    
    lisa.food.oatmeal = 20;
    lisa.food.frozen_berries = 30;
    lisa.food.almonds = 80;
    lisa.food.chia = 100;
    lisa.food.bananas = 9;
    lisa.food.apples = 8;
    lisa.food.tofu = 40;
    lisa.food.quinoa = 70;
    lisa.food.lentils = 15;
    lisa.food.spinach = 20;
    lisa.food.tomatoes = 12;
    lisa.food.cucumbers = 10;
    lisa.food.pepper = 15;
    lisa.food.chikpeas = 20;
    lisa.food.brown_rice = 10;
    lisa.food.olive_oil = 66;
    lisa.food.avocados = 75;
    lisa.food.carrots = 5;
    lisa.food.broccoli = 15;
    lisa.food.orange = 10;
    lisa.food.hummus = 50;
    lisa.food.oat_milk = 15;

    lisa.food.vegan_chocolate = 85;
    lisa.food.fruit_leather = 40;
    lisa.food.coconut_chips = 70;
    lisa.food.agave_syrup = 50;
    lisa.food.vegan_cookies = 45;
    lisa.food.tofu_smoked = 45;
    lisa.food.tempeh = 60;
    lisa.food.seitan = 50;
    lisa.food.edamame = 35;
    lisa.food.nutritional_yeast = 120;
    lisa.food.soy_sauce = 15;
    lisa.food.coconut_yogurt = 25;
    lisa.food.matcha_powder = 300;
    lisa.food.dates = 30;
    lisa.food.cacao_nibs = 90;

    lisa.flat.rent = 10'000;


    lisa.tb.account = 0;
    lisa.tb.deposite = 5'000;
    lisa.tb.interest = 14.5;
    lisa.salary = 100'000;

    lisa.boyfriend = 15'000;

    lisa.tb.account_eur = 5000;
    lisa.tb.rate_eur_rub = 90.45;


    lisa.cosmetic.pomade = 3'000;
    lisa.cosmetic.mascara = 2'500;
    lisa.cosmetic.foundation = 4'000;
    lisa.cosmetic.summ = 0;

    lisa.gifts.gifts = 10'000;

    lisa.medicine.visit_to_a_doctor = 2'000;

    lisa.medicine.vitamin_b12_sublingual = 500;
    lisa.medicine.iron_complex_vegan = 700;
    lisa.medicine.algae_omega3 = 900;
    lisa.medicine.plant_protein_powder = 2500;

    lisa.medicine.ibuprofen_200mg = 85;
    lisa.medicine.paracetamol_500mg = 40;
    lisa.medicine.vitamin_c_effervescent = 250;
    lisa.medicine.multivitamin_daily = 450;
    lisa.medicine.magnesium_glycinate = 600;
    lisa.medicine.melatonin_3mg = 550;
    lisa.medicine.probiotic_capsules = 800;
    lisa.medicine.antacid_chewable = 250;
    lisa.medicine.cough_syrup_100ml = 380;
    lisa.medicine.bandage_elastic = 150;

	lisa.friends.coffe = 500;
	lisa.friends.brunch = 1'000;
	lisa.friends.cinema_lisa = 1'000;
	lisa.friends.fotosession = 2'000;
	lisa.friends.shopping = 5'000;
	lisa.friends.spa = 3'000;
	lisa.friends.massage = 2'000;
	lisa.friends.restaurant = 2'000;
	lisa.friends.taxi = 1'000;
	lisa.friends.club = 2'000;

	lisa.hobbies.dancing = 1'000;
    lisa.hobbies.painting = 1'500;
    lisa.hobbies.art = 2'000;
    lisa.hobbies.fashion = 3'000;
    lisa.hobbies.sewing = 1'500;
    lisa.hobbies.jewelry = 2'000;
    lisa.hobbies.cooking = 1'000;
    lisa.hobbies.baking = 1'500;
    lisa.hobbies.photography = 2'000;
	lisa.hobbies.music = 3'000;

}


void pair_init()
{
    davis_init();
	lisa_init();

}


void lisa_salary(const int month, const int year)
{

    if (month == 12) {

        lisa.tb.account += lisa.salary;

    }

    if (month == 1 and year == 2029) {

        lisa.salary *= 1.2;

    }

    if (month == 1 and year == 2032) {

        lisa.salary *= 1.25;

    }

    lisa.tb.account += lisa.salary;

    lisa.tb.account += lisa.boyfriend;

}


static void lisa_deposite(const int month, const int year)
{

    if (year == 2026) {

        lisa.tb.interest = 14.5;

    }

    if (year == 2027) {

        lisa.tb.interest = 13.5;

    }

    if (year == 2028) {

        lisa.tb.interest = 12.5;

    }

    if (year == 2029) {

        lisa.tb.interest = 11.5;

    }

    lisa.tb.deposite += lisa.tb.deposite * (lisa.tb.interest / 12.0 / 100.0);

    lisa.tb.deposite += lisa.tb.account;
    lisa.tb.account = 0;

}


void lisa_cosmetic(const int month, const int year)
{
    if (month == 4 or month == 9) {

        lisa.tb.account -= lisa.cosmetic.pomade;

    }


    if (month == 2 or month == 7) {

        lisa.tb.account -= lisa.cosmetic.mascara;

    }


    if (month == 3 or month == 8) {

        lisa.tb.account -= lisa.cosmetic.foundation;

    }


    lisa.cosmetic.pomade += lisa.cosmetic.pomade * inflation / 12;
    lisa.cosmetic.mascara += lisa.cosmetic.mascara * inflation / 12;
    lisa.cosmetic.foundation += lisa.cosmetic.foundation * inflation / 12;

}


void davis_salary(const int month, const int year)
{
    if (month == 12) {

        davis.tb.account += davis.salary;

    }


    if (month == 1 and year == 2028) {

        davis.salary *= 1.5;

    }


    if (month == 6 and year == 2030) {

        davis.salary *= 1.3;

    }


    if (month == 1 and year == 2033) {

        davis.salary *= 1.5;

    }


    davis.tb.account += davis.salary;

}


void davis_inflation(const int month, const int year)
{
    if (month == 1) {

        inflation += 0.5 / 100;

    }

}


void davis_friends(const int month, const int year)
{

	if (month == 2 or month == 5 or month == 9)
    {
        davis.tb.account -= davis.friends.beer;

    }

    davis.friends.beer += davis.friends.beer * inflation / 12;


    if (month == 3 or month == 6 or month == 10)
    {
        davis.tb.account -= davis.friends.fast_food;

	}

	davis.friends.fast_food += davis.friends.fast_food * inflation / 12;


    if (month == 4 or month == 7 or month == 11)
    {
        davis.tb.account -= davis.friends.cinema;

    }

	davis.friends.cinema += davis.friends.cinema * inflation / 12;


    if (month == 1 or month == 8 or month == 12)
    {
        davis.tb.account -= davis.friends.games;

	}

	davis.friends.games += davis.friends.games * inflation / 12;


    if (month == 2 or month == 4 or month == 6 or month == 8 or month == 10 or month == 12)
    {
        davis.tb.account -= davis.friends.bowling;

	}

	davis.friends.bowling += davis.friends.bowling * inflation / 12;


    if (month == 3 or month == 6 or month == 9 or month == 12)
    {
        davis.tb.account -= davis.friends.karaoke;

    }

	davis.friends.karaoke += davis.friends.karaoke * inflation / 12;


    if (month == 1 or month == 4 or month == 7 or month == 10)
    {
        davis.tb.account -= davis.friends.concerts;

    }

	davis.friends.concerts += davis.friends.concerts * inflation / 12;


    if (month == 2 or month == 5 or month == 8 or month == 11)
    {
        davis.tb.account -= davis.friends.billiard;

    }

	davis.friends.billiard += davis.friends.billiard * inflation / 12;

}


void lisa_friends(const int month, const int year)
{
    if (month == 1 or month == 4 or month == 7 or month == 10)
    {
        lisa.tb.account -= lisa.friends.coffe;
	}

	lisa.friends.coffe += lisa.friends.coffe * inflation / 12;


    if (month == 2 or month == 5 or month == 8 or month == 11)
    {
        lisa.tb.account -= lisa.friends.brunch;
	}

    lisa.friends.brunch += lisa.friends.brunch * inflation / 12;


    if (month == 3 or month == 6 or month == 9 or month == 12)
    {
        lisa.tb.account -= lisa.friends.cinema_lisa;
	}

    lisa.friends.cinema_lisa += lisa.friends.cinema_lisa * inflation / 12;


    if (month == 1 or month == 5 or month == 9)
    {
        lisa.tb.account -= lisa.friends.fotosession;
    }
    lisa.friends.fotosession += lisa.friends.fotosession * inflation / 12;


    if (month == 2 or month == 6 or month == 10)
    {
        lisa.tb.account -= lisa.friends.shopping;
    }

    lisa.friends.shopping += lisa.friends.shopping * inflation / 12;


    if (month == 3 or month == 7 or month == 11)
    {
        lisa.tb.account -= lisa.friends.spa;
    }

    lisa.friends.spa += lisa.friends.spa * inflation / 12;


    if (month == 4 or month == 8 or month == 12)
    {
        lisa.tb.account -= lisa.friends.massage;
    }

    lisa.friends.massage += lisa.friends.massage * inflation / 12;


    if (month == 1 or month == 5 or month == 9)
    {
        lisa.tb.account -= lisa.friends.restaurant;
    }

    lisa.friends.restaurant += lisa.friends.restaurant * inflation / 12;


    if (month == 2 or month == 6 or month == 10)
    {
        lisa.tb.account -= lisa.friends.taxi;
    }

    lisa.friends.taxi += lisa.friends.taxi * inflation / 12;


    if (month == 3 or month == 7 or month == 11)
    {
        lisa.tb.account -= lisa.friends.club;
    }

	lisa.friends.club += lisa.friends.club * inflation / 12;

}


void davis_hobbies(const int month, const int year)
{

    if (month == 1 or month == 4 or month == 7 or month == 10)
    {
        davis.tb.account -= davis.hobbies.guitar;

    }

	davis.hobbies.guitar += davis.hobbies.guitar * inflation / 12;


    if (month == 2 or month == 5 or month == 8 or month == 11)
    {
        davis.tb.account -= davis.hobbies.hobbies;

	}

    davis.hobbies.hobbies += davis.hobbies.hobbies * inflation / 12;


    if (month == 3 or month == 6 or month == 9 or month == 12)
    {
        davis.tb.account -= davis.hobbies.golf;

	}

	davis.hobbies.golf += davis.hobbies.golf * inflation / 12;


    if (month == 1 or month == 6 or month == 11)
    {
        davis.tb.account -= davis.hobbies.skiing;

	}

    davis.hobbies.skiing += davis.hobbies.skiing * inflation / 12;


    if (month == 2 or month == 7 or month == 12)
    {
        davis.tb.account -= davis.hobbies.tennis;

	}

    davis.hobbies.tennis += davis.hobbies.tennis * inflation / 12;


    if (month == 3 or month == 8 or month == 1)
    {
        davis.tb.account -= davis.hobbies.fishing;

    }

    davis.hobbies.fishing += davis.hobbies.fishing * inflation / 12;


    if (month == 4 or month == 9 or month == 2)
    {
        davis.tb.account -= davis.hobbies.hiking;

    }

    davis.hobbies.hiking += davis.hobbies.hiking * inflation / 12;


    if (month == 5 or month == 10 or month == 3)
    {
        davis.tb.account -= davis.hobbies.books;

    }

    davis.hobbies.books += davis.hobbies.books * inflation / 12;


    if (month == 6 or month == 11 or month == 4)
    {
        davis.tb.account -= davis.hobbies.video_games;

    }

    davis.hobbies.video_games += davis.hobbies.video_games * inflation / 12;


    if (month == 7 or month == 12 or month == 5)
    {
        davis.tb.account -= davis.hobbies.machines;

	}

	davis.hobbies.machines += davis.hobbies.machines * inflation / 12;


}


void lisa_hobbies(const int month, const int year)
{

    if (month == 1 or month == 4 or month == 7 or month == 10)
    {
        lisa.tb.account -= lisa.hobbies.dancing;

    }

	lisa.hobbies.dancing += lisa.hobbies.dancing * inflation / 12;


    if (month == 2 or month == 5 or month == 8 or month == 11)
    {
        lisa.tb.account -= lisa.hobbies.painting;

	}

    lisa.hobbies.painting += lisa.hobbies.painting * inflation / 12;


    if (month == 3 or month == 6 or month == 9 or month == 12)
    {
        lisa.tb.account -= lisa.hobbies.art;

	}

    lisa.hobbies.art += lisa.hobbies.art * inflation / 12;


    if (month == 1 or month == 5 or month == 9)
    {
        lisa.tb.account -= lisa.hobbies.fashion;

    }

    lisa.hobbies.fashion += lisa.hobbies.fashion * inflation / 12;


    if (month == 2 or month == 6 or month == 10)
    {
        lisa.tb.account -= lisa.hobbies.sewing;

    }

    lisa.hobbies.sewing += lisa.hobbies.sewing * inflation / 12;


    if (month == 3 or month == 7 or month == 11)
    {
        lisa.tb.account -= lisa.hobbies.jewelry;

    }

	lisa.hobbies.jewelry += lisa.hobbies.jewelry * inflation / 12;


    if (month == 4 or month == 8 or month == 12)
    {
        lisa.tb.account -= lisa.hobbies.cooking;

    }

    lisa.hobbies.cooking += lisa.hobbies.cooking * inflation / 12;


    if (month == 1 or month == 5 or month == 9)
    {
        lisa.tb.account -= lisa.hobbies.baking;

    }

    lisa.hobbies.baking += lisa.hobbies.baking * inflation / 12;


    if (month == 2 or month == 6 or month == 10)
    {
        lisa.tb.account -= lisa.hobbies.photography;

    }

    lisa.hobbies.photography += lisa.hobbies.photography * inflation / 12;


    if (month == 3 or month == 7 or month == 11)
    {
        lisa.tb.account -= lisa.hobbies.music;

	}

	lisa.hobbies.music += lisa.hobbies.music * inflation / 12;


}


void davis_cat()
{
    davis.tb.account -= davis.cat.eat_for_cat;
    davis.tb.account -= davis.cat.toilet_for_cat;

    davis.cat.eat_for_cat += davis.cat.eat_for_cat * inflation / 12;
    davis.cat.toilet_for_cat += davis.cat.toilet_for_cat * inflation / 12;

}


void davis_food()
{

    davis.tb.account -= davis.food.ovsyanka * 3.5;
    davis.tb.account -= davis.food.eggs * 7;
    davis.tb.account -= davis.food.apples * 10.5;
    davis.tb.account -= davis.food.chiken * 14;
    davis.tb.account -= davis.food.buckwheat * 6;
    davis.tb.account -= davis.food.broccoli * 10.5;
    davis.tb.account -= davis.food.fish * 10.5;
    davis.tb.account -= davis.food.rice * 5.6;
    davis.tb.account -= davis.food.tomatoes * 7;
    davis.tb.account -= davis.food.cucumbers * 7;
    davis.tb.account -= davis.food.nuts * 2.1;
    davis.tb.account -= davis.food.tvorog * 10.5;
    davis.tb.account -= davis.food.bananas * 8.4;
    davis.tb.account -= davis.food.avocados * 7;
    davis.tb.account -= davis.food.potato * 14;
    davis.tb.account -= davis.food.spinach * 3.5;
    davis.tb.account -= davis.food.orange * 10.5;
    davis.tb.account -= davis.food.yogurt * 10.5;
    davis.tb.account -= davis.food.olive_oil * 1.4;
    davis.tb.account -= davis.food.bread * 3.5;
    davis.tb.account -= davis.food.frozen_berries * 7;
        
    davis.tb.account -= davis.food.dark_chocolate_75 * 3;
    davis.tb.account -= davis.food.protein_bar * 6;
    davis.tb.account -= davis.food.honey * 5;
    davis.tb.account -= davis.food.marshmallow_sugar_free * 4;
    davis.tb.account -= davis.food.peanut_butter * 5;
    davis.tb.account -= davis.food.salmon_fillet * 15;
    davis.tb.account -= davis.food.beef_steak * 15;
    davis.tb.account -= davis.food.sweet_potato * 20;
    davis.tb.account -= davis.food.bell_pepper_red * 10;
    davis.tb.account -= davis.food.cauliflower * 10;
    davis.tb.account -= davis.food.chia_seeds * 3;
    davis.tb.account -= davis.food.coconut_oil * 4;
    davis.tb.account -= davis.food.green_tea_bags * 1.2;
    davis.tb.account -= davis.food.coffee_beans * 1.5;

}


void davis_food_inflation()
{
    davis.food.ovsyanka += davis.food.ovsyanka * inflation / 12;
    davis.food.eggs += davis.food.eggs * inflation / 12;
    davis.food.apples += davis.food.apples * inflation / 12;
    davis.food.chiken += davis.food.chiken * inflation / 12;
    davis.food.buckwheat += davis.food.buckwheat * inflation / 12;
    davis.food.broccoli += davis.food.broccoli * inflation / 12;
    davis.food.fish += davis.food.fish * inflation / 12;
    davis.food.rice += davis.food.rice * inflation / 12;
    davis.food.tomatoes += davis.food.tomatoes * inflation / 12;
    davis.food.cucumbers += davis.food.cucumbers * inflation / 12;
    davis.food.nuts += davis.food.nuts * inflation / 12;
    davis.food.tvorog += davis.food.tvorog * inflation / 12;
    davis.food.bananas += davis.food.bananas * inflation / 12;
    davis.food.avocados += davis.food.avocados * inflation / 12;
    davis.food.potato += davis.food.potato * inflation / 12;
    davis.food.spinach += davis.food.spinach * inflation / 12;
    davis.food.orange += davis.food.orange * inflation / 12;
    davis.food.yogurt += davis.food.yogurt * inflation / 12;
    davis.food.olive_oil += davis.food.olive_oil * inflation / 12;
    davis.food.bread += davis.food.bread * inflation / 12;
    davis.food.frozen_berries += davis.food.frozen_berries * inflation / 12;

	davis.food.dark_chocolate_75 += davis.food.dark_chocolate_75 * inflation / 12;
	davis.food.protein_bar += davis.food.protein_bar * inflation / 12;
	davis.food.honey += davis.food.honey * inflation / 12;
	davis.food.marshmallow_sugar_free += davis.food.marshmallow_sugar_free * inflation / 12;
	davis.food.peanut_butter += davis.food.peanut_butter * inflation / 12;
	davis.food.salmon_fillet += davis.food.salmon_fillet * inflation / 12;
	davis.food.beef_steak += davis.food.beef_steak * inflation / 12;
	davis.food.sweet_potato += davis.food.sweet_potato * inflation / 12;
	davis.food.bell_pepper_red += davis.food.bell_pepper_red * inflation / 12;
	davis.food.cauliflower += davis.food.cauliflower * inflation / 12;
	davis.food.chia_seeds += davis.food.chia_seeds * inflation / 12;
	davis.food.coconut_oil += davis.food.coconut_oil * inflation / 12;
	davis.food.green_tea_bags += davis.food.green_tea_bags * inflation / 12;
	davis.food.coffee_beans += davis.food.coffee_beans * inflation / 12;
}


void lisa_food()
{

    lisa.tb.account -= lisa.food.oatmeal * 3.5;
    lisa.tb.account -= lisa.food.frozen_berries * 7;
    lisa.tb.account -= lisa.food.almonds * 2.1;
    lisa.tb.account -= lisa.food.chia * 1.4;
    lisa.tb.account -= lisa.food.bananas * 8.4;
    lisa.tb.account -= lisa.food.apples * 10.5;
    lisa.tb.account -= lisa.food.tofu * 10.5;
    lisa.tb.account -= lisa.food.quinoa * 10.6;
    lisa.tb.account -= lisa.food.lentils * 5.6;
    lisa.tb.account -= lisa.food.spinach * 7;
    lisa.tb.account -= lisa.food.tomatoes * 7;
    lisa.tb.account -= lisa.food.cucumbers * 7;
    lisa.tb.account -= lisa.food.pepper * 7;
    lisa.tb.account -= lisa.food.chikpeas * 10.5;
    lisa.tb.account -= lisa.food.brown_rice * 5.6;
    lisa.tb.account -= lisa.food.olive_oil * 1.4;
    lisa.tb.account -= lisa.food.avocados * 7;
    lisa.tb.account -= lisa.food.carrots * 7;
    lisa.tb.account -= lisa.food.broccoli * 10.5;
    lisa.tb.account -= lisa.food.orange * 10.5;
    lisa.tb.account -= lisa.food.hummus * 3.5;
    lisa.tb.account -= lisa.food.oat_milk * 14;

	lisa.tb.account -= lisa.food.vegan_chocolate * 4;
	lisa.tb.account -= lisa.food.fruit_leather * 5;
	lisa.tb.account -= lisa.food.coconut_chips * 3;
	lisa.tb.account -= lisa.food.agave_syrup * 6;
	lisa.tb.account -= lisa.food.vegan_cookies * 10;
	lisa.tb.account -= lisa.food.tofu_smoked * 8;
	lisa.tb.account -= lisa.food.tempeh * 8;
	lisa.tb.account -= lisa.food.seitan * 8;
	lisa.tb.account -= lisa.food.edamame * 6;
	lisa.tb.account -= lisa.food.nutritional_yeast * 2;
	lisa.tb.account -= lisa.food.soy_sauce * 5;
	lisa.tb.account -= lisa.food.coconut_yogurt * 15;
	lisa.tb.account -= lisa.food.matcha_powder * 1;
	lisa.tb.account -= lisa.food.dates * 5;
	lisa.tb.account -= lisa.food.cacao_nibs * 2;


}


void lisa_food_inflation()
{
    lisa.food.oatmeal += lisa.food.oatmeal * inflation / 12;
    lisa.food.frozen_berries += lisa.food.frozen_berries * inflation / 12;
    lisa.food.almonds += lisa.food.almonds * inflation / 12;
    lisa.food.chia += lisa.food.chia * inflation / 12;
    lisa.food.bananas += lisa.food.bananas * inflation / 12;
    lisa.food.apples += lisa.food.apples * inflation / 12;
    lisa.food.tofu += lisa.food.tofu * inflation / 12;
    lisa.food.quinoa += lisa.food.quinoa * inflation / 12;
    lisa.food.lentils += lisa.food.lentils * inflation / 12;
    lisa.food.spinach += lisa.food.spinach * inflation / 12;
    lisa.food.tomatoes += lisa.food.tomatoes * inflation / 12;
    lisa.food.cucumbers += lisa.food.cucumbers * inflation / 12;
    lisa.food.pepper += lisa.food.pepper * inflation / 12;
    lisa.food.chikpeas += lisa.food.chikpeas * inflation / 12;
    lisa.food.brown_rice += lisa.food.brown_rice * inflation / 12;
    lisa.food.olive_oil += lisa.food.olive_oil * inflation / 12;
    lisa.food.avocados += lisa.food.avocados * inflation / 12;
    lisa.food.carrots += lisa.food.carrots * inflation / 12;
    lisa.food.broccoli += lisa.food.broccoli * inflation / 12;
    lisa.food.orange += lisa.food.orange * inflation / 12;
    lisa.food.hummus += lisa.food.hummus * inflation / 12;
    lisa.food.oat_milk += lisa.food.oat_milk * inflation / 12;

	lisa.food.vegan_chocolate += lisa.food.vegan_chocolate * inflation / 12;
	lisa.food.fruit_leather += lisa.food.fruit_leather * inflation / 12;
	lisa.food.coconut_chips += lisa.food.coconut_chips * inflation / 12;
	lisa.food.agave_syrup += lisa.food.agave_syrup * inflation / 12;
	lisa.food.vegan_cookies += lisa.food.vegan_cookies * inflation / 12;
	lisa.food.tofu_smoked += lisa.food.tofu_smoked * inflation / 12;
	lisa.food.tempeh += lisa.food.tempeh * inflation / 12;
	lisa.food.seitan += lisa.food.seitan * inflation / 12;
	lisa.food.edamame += lisa.food.edamame * inflation / 12;
	lisa.food.nutritional_yeast += lisa.food.nutritional_yeast * inflation / 12;
	lisa.food.soy_sauce += lisa.food.soy_sauce * inflation / 12;
	lisa.food.coconut_yogurt += lisa.food.coconut_yogurt * inflation / 12;
	lisa.food.matcha_powder += lisa.food.matcha_powder * inflation / 12;
	lisa.food.dates += lisa.food.dates * inflation / 12;
	lisa.food.cacao_nibs += lisa.food.cacao_nibs * inflation / 12;


}


void davis_car(const int month, const int year)
{
    davis.tb.account -= davis.car.gas;
    davis.car.gas += davis.car.gas * inflation / 12;

    davis.tb.account -= davis.car.wash;
	davis.car.wash += davis.car.wash * inflation / 12;

    davis.tb.account -= davis.car.penalty;
	davis.car.penalty += davis.car.penalty * inflation / 12;

	davis.tb.account -= davis.car.tax_for_a_car;
	davis.car.tax_for_a_car += davis.car.tax_for_a_car * inflation / 12;
     
    if (month == 2 or month == 4 or month == 8 or month == 10 or month == 12) 
    {

        davis.tb.account -= davis.car.washer_fluid;
        
	}

	davis.car.washer_fluid += davis.car.washer_fluid * inflation / 12;


    if (month == 2 or month == 10) 
    {

        davis.tb.account -= davis.car.antifreez;
        
    }

    davis.car.antifreez += davis.car.antifreez * inflation / 12;


    if (month == 3 or month == 11) 
    {

        davis.tb.account -= davis.car.tires;
        
    }

    davis.car.tires += davis.car.tires * inflation / 12;


	if (month == 1) 
    {

        davis.tb.account -= (davis.car.osago);
    }

    davis.car.osago += davis.car.osago * inflation / 12;


     if (month == 1) 
     {

        davis.tb.account -= (davis.car.kasko);

     }

	 davis.car.kasko += davis.car.kasko * inflation / 12;
    
}


void davis_girlfriend()
{
    davis.tb.account -= davis.girlfriend.date;
    davis.tb.account -= davis.girlfriend.flowers;

    davis.tb.account -= lisa.boyfriend;

    davis.girlfriend.date += davis.girlfriend.date * inflation / 12;
    davis.girlfriend.flowers += davis.girlfriend.flowers * inflation / 12;

}


void davis_gym()
{
    davis.tb.account -= davis.gym.protein;
    davis.tb.account -= davis.gym.subscription;

    lisa.tb.account -= davis.gym.subscription;

    davis.gym.subscription += davis.gym.subscription * inflation / 12;
    davis.gym.protein += davis.gym.protein * inflation / 12;

}

void davis_flat(const int month, const int year)
{
    if (newflat_own == false) {

        davis.tb.account -= davis.flat.rent;
        davis.tb.account -= davis.flat.HCS;

        davis.tb.account += lisa.flat.rent;
        lisa.tb.account -= lisa.flat.rent;

        davis.flat.HCS += davis.flat.HCS * inflation / 12;

    }


    if (newflat_own == false) {

        lisa.flat.rent += lisa.flat.rent * inflation / 12;
        davis.flat.rent += davis.flat.rent * inflation / 12;

    }

}


void davis_car_servise(const int month, const int year)
{
    if (month == 6) {

        davis.tb.account -= davis.car_service.service;

    }

    davis.car_service.service += davis.car_service.service * inflation / 12;


    if (month == 1 and year == 2030) {

        davis.tb.account -= davis.car_service.repair;

    }

	davis.car_service.repair += davis.car_service.repair * inflation / 12;

}


void lisa_car_servise(const int month, const int year)
{
    if (month == 6)
    {
        lisa.tb.account -= lisa.car_service.service;

    }

    lisa.car_service.service += lisa.car_service.service * inflation / 12;


    if (month == 1 and year == 2030)
    {
        lisa.tb.account -= lisa.car_service.repair;

    }

    lisa.car_service.repair += lisa.car_service.repair * inflation / 12;

}


void davis_clothing(const int month, const int year)
{
    if (month == 3 or month == 9) 
    {
        davis.tb.account -= davis.clothing.shoes;

    }

	davis.clothing.shoes += davis.clothing.shoes * inflation / 12;


    if (month == 4 or month == 10) 
    {
        davis.tb.account -= davis.clothing.jacket;

	}

    davis.clothing.jacket += davis.clothing.jacket * inflation / 12;


    if (month == 5 or month == 11) 
    {
        davis.tb.account -= davis.clothing.pants;

	}

    davis.clothing.pants += davis.clothing.pants * inflation / 12;


    if (month == 6 or month == 12) 
    {
        davis.tb.account -= davis.clothing.t_shirt;

    }

	davis.clothing.t_shirt += davis.clothing.t_shirt * inflation / 12;


    if (month == 7 or month == 1) 
    {
        davis.tb.account -= davis.clothing.sweatshirt;

    }

    davis.clothing.sweatshirt += davis.clothing.sweatshirt * inflation / 12;


    if (month == 8 or month == 2) 
    {
        davis.tb.account -= davis.clothing.underwear;

	}

	davis.clothing.underwear += davis.clothing.underwear * inflation / 12;


    if (month == 9 or month == 3) 
    {
        davis.tb.account -= davis.clothing.socks;

	}


	davis.clothing.socks += davis.clothing.socks * inflation / 12;
    if (month == 10 or month == 4) 
    {
        davis.tb.account -= davis.clothing.accessories;

	}

    davis.clothing.accessories += davis.clothing.accessories * inflation / 12;

    if (month == 11 or month == 5) 
    {
        davis.tb.account -= davis.clothing.swimwear;

	}

    davis.clothing.swimwear += davis.clothing.swimwear * inflation / 12;


    if (month == 12 or month == 6) 
    {
        davis.tb.account -= davis.clothing.sportswear;

	}

	davis.clothing.sportswear += davis.clothing.sportswear * inflation / 12;

}

void lisa_clothing(const int month, const int year)
{

    if (month == 3 or month == 9) 
    {
        lisa.tb.account -= lisa.clothing.dresses;

    }

	lisa.clothing.dresses += lisa.clothing.dresses * inflation / 12;


    if (month == 4 or month == 10) 
    {
        lisa.tb.account -= lisa.clothing.skirts;

	}

    lisa.clothing.skirts += lisa.clothing.skirts * inflation / 12;


    if (month == 5 or month == 11) 
    {
        lisa.tb.account -= lisa.clothing.blouses;

    }

    lisa.clothing.blouses += lisa.clothing.blouses * inflation / 12;


    if (month == 6 or month == 12) 
    {
        lisa.tb.account -= lisa.clothing.t_shirt;

	}

    lisa.clothing.t_shirt += lisa.clothing.t_shirt * inflation / 12;


    if (month == 7 or month == 1) 
    {
        lisa.tb.account -= lisa.clothing.sweatshirt;

    }

    lisa.clothing.sweatshirt += lisa.clothing.sweatshirt * inflation / 12;


    if (month == 8 or month == 2) 
    {
        lisa.tb.account -= lisa.clothing.underwear;

	}

    lisa.clothing.underwear += lisa.clothing.underwear * inflation / 12;


    if (month == 9 or month == 3) 
    {
        lisa.tb.account -= lisa.clothing.socks;

    }

    lisa.clothing.socks += lisa.clothing.socks * inflation / 12;


    if (month == 10 or month == 4) 
    {
        lisa.tb.account -= lisa.clothing.accessories;

    }

    lisa.clothing.accessories += lisa.clothing.accessories * inflation / 12;


    if (month == 11 or month == 5) 
    {
        lisa.tb.account -= lisa.clothing.swimwear;

    }

    lisa.clothing.swimwear += lisa.clothing.swimwear * inflation / 12;


    if (month == 12 or month == 6) 
    {
        lisa.tb.account -= lisa.clothing.sportswear;

    }

	lisa.clothing.sportswear += lisa.clothing.sportswear * inflation / 12;


}
 

void davis_deposite(const int month, const int year)
{
    if (year == 2026) 
    {
        
        davis.tb.interest = 14.5;

    }

    if (year == 2027) 
    {

        davis.tb.interest = 13.5;

    }

    if (year == 2028) 
    {

        davis.tb.interest = 12.5;

    }

    if (year == 2029) 
    {

        davis.tb.interest = 11.5;

    }

    if (year >= 2030) 
    {

        davis.tb.interest = 9.5;

    }

    davis.tb.deposite += davis.tb.deposite * (davis.tb.interest / 12.0 / 100.0);

    davis.tb.deposite += davis.tb.account;

    davis.tb.account = 0;

}

void davis_medicine(const int month, const int year)
{
    if (month == 2 or month == 11) {

        davis.tb.account -= davis.medicine.visit_to_a_doctor;

    }

	davis.medicine.visit_to_a_doctor += davis.medicine.visit_to_a_doctor * inflation / 12;


    davis.tb.account -= davis.medicine.whey_protein_isolate;
    davis.tb.account -= davis.medicine.creatine_monohydrate;
    davis.tb.account -= davis.medicine.bcaa_powder;
    davis.tb.account -= davis.medicine.joint_support_complex;
    davis.tb.account -= davis.medicine.electrolyte_tabs;
    davis.tb.account -= davis.medicine.caffeine_pills_200mg;

    davis.tb.account -= davis.medicine.ibuprofen_200mg;
    davis.tb.account -= davis.medicine.paracetamol_500mg;
    davis.tb.account -= davis.medicine.vitamin_c_effervescent;
    davis.tb.account -= davis.medicine.multivitamin_daily;
    davis.tb.account -= davis.medicine.magnesium_glycinate;
    davis.tb.account -= davis.medicine.melatonin_3mg;
    davis.tb.account -= davis.medicine.probiotic_capsules;
    davis.tb.account -= davis.medicine.antacid_chewable;
    davis.tb.account -= davis.medicine.cough_syrup_100ml;
    davis.tb.account -= davis.medicine.bandage_elastic;

	davis.medicine.whey_protein_isolate += davis.medicine.whey_protein_isolate * inflation / 12;
	davis.medicine.creatine_monohydrate += davis.medicine.creatine_monohydrate * inflation / 12;
	davis.medicine.bcaa_powder += davis.medicine.bcaa_powder * inflation / 12;
	davis.medicine.joint_support_complex += davis.medicine.joint_support_complex * inflation / 12;
	davis.medicine.electrolyte_tabs += davis.medicine.electrolyte_tabs * inflation / 12;
	davis.medicine.caffeine_pills_200mg += davis.medicine.caffeine_pills_200mg * inflation / 12;
    
    davis.medicine.ibuprofen_200mg += davis.medicine.ibuprofen_200mg * inflation / 12;
    davis.medicine.paracetamol_500mg += davis.medicine.paracetamol_500mg * inflation / 12;
    davis.medicine.vitamin_c_effervescent += davis.medicine.vitamin_c_effervescent * inflation / 12;
    davis.medicine.multivitamin_daily += davis.medicine.multivitamin_daily * inflation / 12;
    davis.medicine.magnesium_glycinate += davis.medicine.magnesium_glycinate * inflation / 12;
    davis.medicine.melatonin_3mg += davis.medicine.melatonin_3mg * inflation / 12;
    davis.medicine.probiotic_capsules += davis.medicine.probiotic_capsules * inflation / 12;
    davis.medicine.antacid_chewable += davis.medicine.antacid_chewable * inflation / 12;
    davis.medicine.cough_syrup_100ml += davis.medicine.cough_syrup_100ml * inflation / 12;
	davis.medicine.bandage_elastic += davis.medicine.bandage_elastic * inflation / 12;

}


void lisa_medicine(const int month, const int year)
{
    if (month == 3 or month == 10) {

        lisa.tb.account -= lisa.medicine.visit_to_a_doctor;

    }

	lisa.medicine.visit_to_a_doctor += lisa.medicine.visit_to_a_doctor * inflation / 12;


    lisa.tb.account -= lisa.medicine.vitamin_b12_sublingual;
    lisa.tb.account -= lisa.medicine.iron_complex_vegan;
    lisa.tb.account -= lisa.medicine.algae_omega3;
    lisa.tb.account -= lisa.medicine.plant_protein_powder;

    lisa.tb.account -= lisa.medicine.ibuprofen_200mg;
    lisa.tb.account -= lisa.medicine.paracetamol_500mg;
    lisa.tb.account -= lisa.medicine.vitamin_c_effervescent;
    lisa.tb.account -= lisa.medicine.multivitamin_daily;
    lisa.tb.account -= lisa.medicine.magnesium_glycinate;
    lisa.tb.account -= lisa.medicine.melatonin_3mg;
    lisa.tb.account -= lisa.medicine.probiotic_capsules;
    lisa.tb.account -= lisa.medicine.antacid_chewable;
    lisa.tb.account -= lisa.medicine.cough_syrup_100ml;
    lisa.tb.account -= lisa.medicine.bandage_elastic;

	lisa.medicine.vitamin_b12_sublingual += lisa.medicine.vitamin_b12_sublingual * inflation / 12;
	lisa.medicine.iron_complex_vegan += lisa.medicine.iron_complex_vegan * inflation / 12;
	lisa.medicine.algae_omega3 += lisa.medicine.algae_omega3 * inflation / 12;
    lisa.medicine.plant_protein_powder += lisa.medicine.plant_protein_powder * inflation / 12;

    lisa.medicine.ibuprofen_200mg += lisa.medicine.ibuprofen_200mg * inflation / 12;
    lisa.medicine.paracetamol_500mg += lisa.medicine.paracetamol_500mg * inflation / 12;
    lisa.medicine.vitamin_c_effervescent += lisa.medicine.vitamin_c_effervescent * inflation / 12;
    lisa.medicine.multivitamin_daily += lisa.medicine.multivitamin_daily * inflation / 12;
    lisa.medicine.magnesium_glycinate += lisa.medicine.magnesium_glycinate * inflation / 12;
    lisa.medicine.melatonin_3mg += lisa.medicine.melatonin_3mg * inflation / 12;
    lisa.medicine.probiotic_capsules += lisa.medicine.probiotic_capsules * inflation / 12;
    lisa.medicine.antacid_chewable += lisa.medicine.antacid_chewable * inflation / 12;
	lisa.medicine.cough_syrup_100ml += lisa.medicine.cough_syrup_100ml * inflation / 12;
}


void pair_gifts(const int month, const int year) //its gift for a celebration
{ 
    if (month == 1) {
		//new year and christmas
        davis.tb.account -= davis.gifts.gifts;
        lisa.tb.account -= lisa.gifts.gifts;

    }


    if (month == 2) {
		//day of all lovers
        davis.tb.account -= davis.gifts.gifts * 0.5;
        lisa.tb.account -= lisa.gifts.gifts * 0.5;

    }


    if (month == 10) {
		//gift for anniversary
        davis.tb.account -= davis.gifts.gifts;
        lisa.tb.account -= lisa.gifts.gifts;

    }


    if (month == 11) {
		//gift for davis's birthday 
        lisa.tb.account -= lisa.gifts.gifts * 1.5;

    }


    if (month == 12) {
		//gift for lisa's birthday
        davis.tb.account -= davis.gifts.gifts * 1.5;

    }

}


void pair_holiday(const int month, const int year)
{
    if (year > 2036) { 
        
        //after wedding

		if (month == 6) {

            davis.tb.account -= davis.holiday * 5;
            lisa.tb.account -= lisa.holiday * 2;

        }


		if (month == 1 and year == 2028) { 

            davis.tb.account -= davis.holiday * 3;
            lisa.tb.account -= lisa.holiday * 1.5;

        }

    }
}


void pair_marriage(const int month, const int year)
{
    if (month == 7 and year == 2035) { 

        davis.tb.account -= 1'500'000;
        lisa.tb.account -= 1'000'000;

    }


}


void mortgage()
{  
	// mortgage payment is calculated using annuity formula
    newflat += newflat * 0.22 / 12;
    float years = 15;
    float total_months = years * 12;
    float annual_rate = 20.7;
    float monthly_rate = (annual_rate / 100) / 12;
    float b = std::pow((1 - monthly_rate), (-1 * annual_rate));
    float a = (1 - b);
    float common_pow = std::pow(1 + monthly_rate, total_months);
    float annuity_payment = newflat * (monthly_rate * common_pow) / (common_pow - 1);

    davis.tb.account -= annuity_payment;
    newflat -= annuity_payment;

}


void pair_ownflat(const int month, const int year)
{
    if (month == 1 and year == 2032) {

		newflat -= 5'000'000; // first payment for the flat
        newflat_own = true;
        mortgage();
    }


    if (newflat_own == true) {

        if (newflat > 0) {
            mortgage();
        }

        else {
            davis.tb.account -= 0;
        }
    }

}


void pair_newcar(const int month, const int year)
{
    if (month == 12) {

        // every year car loses 15% of its value

        davis.car.value -= davis.car.value * 0.15;
        lisa.car.value -= lisa.car.value * 0.15;

    }


    if (davis.tb.deposite > 8'000'000) {

        // if he has a lot of money, he can buy a new car

        davis.tb.deposite -= 4'000'000;
        davis.car.value += 4'000'000;

    }


    if (year == 2039) {

        // its just a gift for his wife

        davis.tb.deposite -= 4'000'000;
        lisa.car.value += 4'000'000;

    }

}


void lisa_car(const int month, const int year)
{
    if (lisa.car.value > 0) 
    {

        lisa.tb.account -= lisa.car.gas;
        davis.car.gas += davis.car.gas * inflation / 12;

        lisa.tb.account -= lisa.car.wash;
        lisa.car.wash += lisa.car.wash * inflation / 12;

		lisa.tb.account -= lisa.car.penalty;
		lisa.car.penalty += lisa.car.penalty * inflation / 12;

		lisa.tb.account -= lisa.car.tax_for_a_car;
        lisa.car.tax_for_a_car += lisa.car.tax_for_a_car * inflation / 12;

        if (month == 2 or month == 4 or month == 8 or month == 10 or month == 12) 
        {

            lisa.tb.account -= lisa.car.washer_fluid;
        
        }

        lisa.car.washer_fluid += lisa.car.washer_fluid * inflation / 12;


        if (month == 2 or month == 10) 
        {

            lisa.tb.account -= lisa.car.antifreez;
        
        }

        lisa.car.antifreez += lisa.car.antifreez * inflation / 12;


        if (month == 3 or month == 11) 
        {

            lisa.tb.account -= lisa.car.tires;
        
        }

		lisa.car.tires += lisa.car.tires * inflation / 12;


        if (month == 1) 
        {

            lisa.tb.account -= lisa.car.osago;

		}

        lisa.car.osago += lisa.car.osago * inflation / 12;


        if (month == 1) 
        {

            lisa.tb.account -= lisa.car.kasko;

		}
		
		lisa.car.kasko += lisa.car.kasko * inflation / 12;

    }
}



void print_results()
{

    printf("Salary davis = %.2f\n", davis.salary);

    RUB capitaldavise = 0;

    capitaldavise += davis.car.value;
    capitaldavise += davis.tb.deposite;
    capitaldavise += davis.tb.account_eur * davis.tb.rate_eur_rub;

    printf("Capital davis = %.2f\n", capitaldavise);
    printf("Bank davis = %.2f\n", davis.tb.deposite);
    printf("Car davis = %.2f\n", davis.car.value);


    printf("Salary lisa = %.2f\n", lisa.salary);

    RUB capitallisa = 0;

    capitallisa += lisa.tb.account;
    capitallisa += lisa.tb.deposite;
    capitallisa += lisa.tb.account_eur * lisa.tb.rate_eur_rub;

    printf("Capital lisa = %.2f\n", capitallisa);
    printf("Bank lisa = %.2f\n", lisa.tb.deposite);
    printf("Car lisa = %.2f\n", lisa.car.value);

    RUB totalcapital = capitaldavise + capitallisa;
    printf("Total capital = %.2f\n", totalcapital);
}


void simulation()
{
    int month = 2;
    int year = 2026;

    while (not (month == 3 and year == 2040))
    {

        davis_salary(month, year);
        davis_car(month, year);
        davis_gym();
        davis_girlfriend();
        davis_flat(month, year);
        davis_car_servise(month, year);
        davis_inflation(month, year);
        davis_cat();
        davis_food();
        davis_food_inflation();
        davis_friends(month, year);
        davis_medicine(month, year);

        lisa_salary(month, year);
        lisa_cosmetic(month, year);
        lisa_food();
        lisa_food_inflation();
        lisa_medicine(month, year);
        lisa_car(month, year);
        
        pair_gifts(month, year);
        pair_holiday(month, year);
        pair_newcar(month, year);
        pair_marriage(month, year);
        pair_ownflat(month, year);

        davis_deposite(month, year);
        lisa_deposite(month, year);



        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }

    }
}



int main()
{

    pair_init();

    simulation();

    print_results();

}