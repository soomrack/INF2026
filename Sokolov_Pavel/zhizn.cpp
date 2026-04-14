#include <stdio.h>
#include <iostream>

using RUB = float;
using Percent = float;
float inflation = 9.4f / 100.0f;

bool newcar_own = false;

bool shelly_pereezd_k_elprimo = false;

struct Bank 
{
    RUB account;
    RUB deposite;
    Percent interest;
};


struct Car
{
    RUB gas;
    RUB value;
    RUB wash;
    RUB osago;
    RUB kasko;
    RUB washer_fluid;
    RUB antifreez;
    RUB tires;
    RUB service;
};


struct Newcar
{
    RUB gas;
    RUB value;
    RUB wash;
    RUB osago;
    RUB kasko;
    RUB washer_fluid;
    RUB antifreez;
    RUB tires;
    RUB service;
};


struct Girlfriend
{
    RUB date;
    RUB flowers;
    RUB ring;
    RUB earrings;
    RUB necklace;
    RUB watch;
};


struct Home 
{
    RUB domnalogi;
    RUB value;
};


struct Flat
{
    RUB rent;
};


struct Friends
{
    //druzya elprimo
    RUB alcohol;
    RUB cinema;
    RUB games;
    RUB bowling;
    RUB concerts;
    RUB billiard;
    RUB shashlyki;

    //druzya shelly
    RUB coffee;
    RUB theatre;
    RUB fotosession;
    RUB shopping;
    RUB massage;
    RUB restaurant;
    RUB club;
};


struct Gym
{
    RUB ticket;
    RUB protein;
    RUB creatin;
    RUB bcaa;
};


struct Pet_buying
{
    RUB cat;
    RUB dog;
    RUB crocodile;
    RUB rabbit;
};


struct Cat
{
    RUB eda;
    RUB toys;
    RUB vet;
};

    
struct Dog
{
    RUB eda;
    RUB toys;
    RUB vet;
};
    

struct Crocodile
{
    RUB eda;
    RUB domik;
};


struct Rabbit
{
    RUB eda;
    RUB domik;
    RUB toys;
    RUB vet;
};


struct Public_transport
{
    RUB metro;
    RUB bus;
    RUB taxi;
};


struct Gifts
{
    RUB gifts;
};


struct Hobbies
{
    //ELPRIMO
    RUB boxingclub;;
    RUB snowboarding;
    RUB running;
    RUB fishing;
    RUB hiking;
    RUB books;
    RUB video_games;
    RUB swimming;

    //SHELLY    
    RUB dancing;
    RUB painting;
    RUB art;
    RUB cooking;
    RUB photography;
    RUB music;
};


struct Clothes
{
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
    RUB sportswear;
    RUB sport_shoes;
    RUB dresses;
    RUB skirts;
    RUB blouses;
};


struct Medicine
{
    RUB visit_to_a_doctor;
    RUB ibuprofen_200mg;
    RUB paracetamol_500mg;
    RUB vitamin_c_effervescent;
    RUB multivitamin_daily;
    RUB vitamin_b12_sublingual;
    RUB iron_complex_vegan;
    RUB algae_omega3;
    RUB caffeine_pills_200mg;
    RUB melatonin_3mg;
    RUB probiotic_capsules;
    RUB antacid_chewable;
    RUB cough_syrup_100ml;
    RUB bandage_elastic;
    RUB magnesium_glycinate;
};


struct Food
{
    RUB ovsyanka;
    RUB eggs;
    RUB apples;
    RUB chicken;
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
    RUB yogurt;
    RUB olive_oil;
    RUB bread;
    RUB frozen_berries;
    RUB almonds;
    RUB chia;
    RUB banana;
    RUB tofu;
    RUB pepper;
    RUB brown_rice;
    RUB avocados;
    RUB carrots;
    RUB orange;
    RUB hummus;
    RUB milk;
    RUB dark_chocolate;
    RUB protein_bar;
    RUB honey;
    RUB marshmallow_sugar_free;
    RUB peanut_butter;
    RUB salmon_fillet;
    RUB beef_steak;
    RUB sweet_potato;
    RUB bell_pepper_red;
    RUB chia_seeds;
    RUB coconut_oil;
    RUB green_tea_bags;
    RUB coffee_beans;
    RUB vegan_chocolate;
    RUB coconut_chips;
    RUB agave_syrup;
    RUB vegan_cookies;
    RUB soy_sauce;
    RUB coconut_yogurt;
};


struct Electrical_equipment
{
    RUB refrigirator;
    RUB washing_machine;
    RUB microwave;
    RUB oven;
    RUB dishwasher;
    RUB vacuum_cleaner;
    RUB air_conditioner;
    RUB tv;
    RUB computer;
    RUB headphones;
    RUB gaming_console;
    RUB blender;
    RUB coffee_maker;
    RUB toaster;
    RUB iron;
};

struct Furniture
{
    RUB sofa;
    RUB armchair;
    RUB coffetable;
    RUB bookcase;
    RUB cabinet;
    RUB bed;
    RUB mattress;
    RUB bench;
    RUB wardrobe;
    RUB table;
    RUB chairs;
    RUB sink;
    RUB toilet;
    RUB bath;
    RUB shower;
    RUB shelves;
    RUB desk;
    RUB bookshelf;
    RUB coatrack;
    RUB stool;
};


struct Person 
{
    Bank vtb;
    Pet_buying pet;
    Crocodile crocodile;
    Rabbit rabbit;
    Car car;
    Cat cat;
    Dog dog;
    RUB salary;
    Home home;
    Gym gym;
    Girlfriend girlfriend;
    Friends friends;
    Food food;
    Medicine medicine;
    Hobbies hobbies;
    Clothes clothing;
    Electrical_equipment electrical_equipment;
    Public_transport public_transport;
    Flat flat;
    Gifts gifts;
    Furniture furniture;
    Newcar newcar;
    RUB holiday;
};


struct Person elprimo;

struct Person shelly;

struct Person family; //shelly+elprimo


void elprimo_init()
{
    elprimo.vtb.account = 0;
    elprimo.vtb.deposite = 1'000'000;
    elprimo.vtb.interest = 14;
    elprimo.salary = 300'000;

    elprimo.food.ovsyanka = 20;
    elprimo.food.eggs = 12;
    elprimo.food.apples = 8;
    elprimo.food.chicken = 25;
    elprimo.food.buckwheat = 6;
    elprimo.food.broccoli = 15;
    elprimo.food.fish = 30;
    elprimo.food.rice = 7;
    elprimo.food.tomatoes = 12;
    elprimo.food.cucumbers = 10;
    elprimo.food.nuts = 80;
    elprimo.food.tvorog = 25;
    elprimo.food.bananas = 9;
    elprimo.food.orange = 35;
    elprimo.food.potato = 3;
    elprimo.food.orange = 10;
    elprimo.food.yogurt = 15;
    elprimo.food.olive_oil = 66;
    elprimo.food.bread = 20;
    elprimo.food.frozen_berries = 30;
    elprimo.food.dark_chocolate = 90;
    elprimo.food.protein_bar = 120;
    elprimo.food.honey = 40;
    elprimo.food.marshmallow_sugar_free = 35;
    elprimo.food.peanut_butter = 60;
    elprimo.food.salmon_fillet = 80;
    elprimo.food.beef_steak = 70;
    elprimo.food.sweet_potato = 8;
    elprimo.food.bell_pepper_red = 15;
    elprimo.food.chia_seeds = 100;
    elprimo.food.coconut_oil = 50;
    elprimo.food.green_tea_bags = 200;
    elprimo.food.coffee_beans = 150;

    elprimo.girlfriend.date = 10'000;
    elprimo.girlfriend.flowers = 2'000;
    elprimo.girlfriend.ring = 50'000;
    elprimo.girlfriend.earrings = 20'000;
    elprimo.girlfriend.necklace = 30'000;
    elprimo.girlfriend.watch = 40'000;

    elprimo.car.value = 4'000'000;
    elprimo.car.gas = 15'000;
    elprimo.car.wash = 500;
    elprimo.car.osago = 10'000;
    elprimo.car.kasko = 20'000;
    elprimo.car.washer_fluid = 300;
    elprimo.car.antifreez = 500;
    elprimo.car.tires = 20'000;
    elprimo.car.service = 10'000;

    elprimo.gym.ticket = 2'600;
    elprimo.gym.protein = 1'000;
    elprimo.gym.bcaa = 800;
    elprimo.gym.creatin = 1'000;

    elprimo.home.value = 12'000'000;
    elprimo.home.domnalogi = 40'000;

    elprimo.friends.alcohol = 4'000;
    elprimo.friends.cinema = 1'000;
    elprimo.friends.games = 1'500;
    elprimo.friends.bowling = 1'000;
    elprimo.friends.concerts = 2'000;
    elprimo.friends.billiard = 1'000;
    elprimo.friends.shashlyki = 2'000;

    elprimo.gifts.gifts = 40'000;

    elprimo.holiday = shelly.holiday = 25'000;

    elprimo.medicine.visit_to_a_doctor = 2'000;
    elprimo.medicine.caffeine_pills_200mg = 200;
    elprimo.medicine.ibuprofen_200mg = 85;
    elprimo.medicine.paracetamol_500mg = 40;
    elprimo.medicine.vitamin_c_effervescent = 250;
    elprimo.medicine.multivitamin_daily = 450;
    elprimo.medicine.magnesium_glycinate = 600;
    elprimo.medicine.melatonin_3mg = 550;
    elprimo.medicine.probiotic_capsules = 800;
    elprimo.medicine.antacid_chewable = 250;
    elprimo.medicine.cough_syrup_100ml = 380;
    elprimo.medicine.bandage_elastic = 150;
    elprimo.medicine.algae_omega3 = 500;

    elprimo.hobbies.swimming = 2'000;
    elprimo.hobbies.snowboarding = 3'000;
    elprimo.hobbies.running = 2'000;
    elprimo.hobbies.fishing = 1'500;
    elprimo.hobbies.hiking = 1'000;
    elprimo.hobbies.books = 1'500;
    elprimo.hobbies.video_games = 2'000;
    elprimo.hobbies.boxingclub = 5'000;

    elprimo.pet.dog = 10'000;
    elprimo.pet.crocodile = 50'000;

    elprimo.dog.eda = 1'000;
    elprimo.dog.toys = 1'000;
    elprimo.dog.vet = 5'000;

    elprimo.crocodile.eda = 10'000;
    elprimo.crocodile.domik = 40'000;

    elprimo.public_transport.metro = 70;
    elprimo.public_transport.bus = 60;
    elprimo.public_transport.taxi = 400;
}


void shelly_init()
{
    shelly.vtb.account = 0;
    shelly.vtb.deposite = 500'000;
    shelly.vtb.interest = 14;
    shelly.salary = 80'000;

    shelly.food.frozen_berries = 30;
    shelly.food.almonds = 80;
    shelly.food.chia = 100;
    shelly.food.bananas = 9;
    shelly.food.apples = 8;
    shelly.food.tofu = 40;
    shelly.food.tomatoes = 12;
    shelly.food.cucumbers = 10;
    shelly.food.pepper = 15;
    shelly.food.brown_rice = 10;
    shelly.food.olive_oil = 66;
    shelly.food.avocados = 75;
    shelly.food.carrots = 5;
    shelly.food.broccoli = 15;
    shelly.food.orange = 10;
    shelly.food.hummus = 50;
    shelly.food.vegan_chocolate = 85;
    shelly.food.coconut_chips = 70;
    shelly.food.agave_syrup = 50;
    shelly.food.vegan_cookies = 45;;
    shelly.food.soy_sauce = 15;
    shelly.food.coconut_yogurt = 25;

    shelly.flat.rent = 12'000;

    shelly.medicine.visit_to_a_doctor = 2'000;
    shelly.medicine.caffeine_pills_200mg = 200;
    shelly.medicine.ibuprofen_200mg = 85;
    shelly.medicine.paracetamol_500mg = 40;
    shelly.medicine.vitamin_c_effervescent = 250;
    shelly.medicine.multivitamin_daily = 450;
    shelly.medicine.magnesium_glycinate = 600;
    shelly.medicine.melatonin_3mg = 550;
    shelly.medicine.probiotic_capsules = 800;
    shelly.medicine.antacid_chewable = 250;
    shelly.medicine.cough_syrup_100ml = 380;
    shelly.medicine.bandage_elastic = 150;
    shelly.medicine.algae_omega3 = 500;

    shelly.friends.coffee = 500;
    shelly.friends.theatre = 1'000;
    shelly.friends.fotosession = 2'000;
    shelly.friends.shopping = 5'000;
    shelly.friends.massage = 2'000;
    shelly.friends.restaurant = 2'000;
    shelly.friends.club = 2'000;

    shelly.gifts.gifts = 10'000;

    shelly.car.value = 600'000;
    shelly.car.gas = 8'000;
    shelly.car.wash = 500;
    shelly.car.osago = 10'000;
    shelly.car.kasko = 20'000;
    shelly.car.washer_fluid = 300;
    shelly.car.antifreez = 500;
    shelly.car.tires = 20'000;

    shelly.newcar.value = 2'000'000;
    shelly.newcar.gas = 12'000;
    shelly.newcar.wash = 600;
    shelly.newcar.osago = 11'000;
    shelly.newcar.kasko = 19'000;
    shelly.newcar.washer_fluid = 400;
    shelly.newcar.antifreez = 450;
    shelly.newcar.tires = 25'000;

    shelly.hobbies.dancing = 1'000;
    shelly.hobbies.painting = 1'500;
    shelly.hobbies.art = 2'000;
    shelly.hobbies.cooking = 1'000;
    shelly.hobbies.photography = 2'000;
    shelly.hobbies.music = 3'000;

    shelly.pet.cat = 5'000;
    shelly.pet.rabbit = 10'000;

    shelly.cat.eda = 1'500;
    shelly.cat.toys = 1'000;
    shelly.cat.vet = 5'000;

    shelly.rabbit.eda = 1'000;
    shelly.rabbit.toys = 300;
    shelly.rabbit.vet = 2'500;
    shelly.rabbit.domik = 5'000;
}


void family_init()
{
    elprimo_init();
    shelly_init();

    family.electrical_equipment.air_conditioner = 25'000;
    family.electrical_equipment.computer = 50'000;
    family.electrical_equipment.headphones = 15'000;
    family.electrical_equipment.gaming_console = 30'000;
    family.electrical_equipment.blender = 10'000;
    family.electrical_equipment.coffee_maker = 5'000;
    family.electrical_equipment.toaster = 3'000;
    family.electrical_equipment.iron = 4'000;
    family.electrical_equipment.dishwasher = 40'000;
    family.electrical_equipment.oven = 35'000;
    family.electrical_equipment.refrigirator = 60'000;
    family.electrical_equipment.washing_machine = 45'000;
    family.electrical_equipment.microwave = 20'000;
    family.electrical_equipment.vacuum_cleaner = 15'000;
    family.electrical_equipment.tv = 40'000;

    family.furniture.armchair = 5'000;
    family.furniture.bath = 15'000;
    family.furniture.bed = 50'000;
    family.furniture.bench = 2'500;
    family.furniture.bookcase = 5'000;
    family.furniture.bookshelf = 7'000;
    family.furniture.cabinet = 5'000;
    family.furniture.chairs = 8'000;
    family.furniture.coatrack = 3'000;
    family.furniture.coffetable = 4'000;
    family.furniture.desk = 10'000;
    family.furniture.mattress = 30'000;
    family.furniture.shelves = 50'000;
    family.furniture.shower = 20'000;
    family.furniture.sink = 10'000;
    family.furniture.sofa = 35'000;
    family.furniture.stool = 4'000;
    family.furniture.table = 15'000;
    family.furniture.toilet = 10'000;
    family.furniture.wardrobe = 70'000;
}


void elprimo_salary(const int month, const int year)
{
    if (month == 12) {
        elprimo.vtb.account += elprimo.salary;
    }

    if (month == 1 and year == 2029){
        elprimo.salary *= 1.3;
    }

    if (month == 6 and year == 2034){
        elprimo.salary *= 1.2;
    }

    elprimo.vtb.account += elprimo.salary;
}


void elprimo_inflation(const int month, const int year)
{
    if (month == 1){
        inflation += 0.5 / 100;
    }
}


void elprimo_deposite(const int month, const int year)
{
    if (year == 2026) elprimo.vtb.interest = 14;
    if (year == 2028) elprimo.vtb.interest = 13;
    if (year == 2030) elprimo.vtb.interest = 12;
    if (year == 2032) elprimo.vtb.interest = 11;
    if (year == 2034) elprimo.vtb.interest = 10;

    elprimo.vtb.deposite += elprimo.vtb.deposite * (elprimo.vtb.interest / 12.0 / 100.0);

    elprimo.vtb.deposite += elprimo.vtb.account;
    elprimo.vtb.account = 0;
}



void elprimo_food()
{
    elprimo.vtb.account -= elprimo.food.ovsyanka * 3.5;
    elprimo.vtb.account -= elprimo.food.eggs * 7;
    elprimo.vtb.account -= elprimo.food.apples * 10.5;
    elprimo.vtb.account -= elprimo.food.buckwheat * 6;
    elprimo.vtb.account -= elprimo.food.broccoli * 10.5;
    elprimo.vtb.account -= elprimo.food.fish * 10.5;
    elprimo.vtb.account -= elprimo.food.rice * 5.6;
    elprimo.vtb.account -= elprimo.food.tomatoes * 7;
    elprimo.vtb.account -= elprimo.food.cucumbers * 7;
    elprimo.vtb.account -= elprimo.food.nuts * 2.1;
    elprimo.vtb.account -= elprimo.food.tvorog * 10.5;
    elprimo.vtb.account -= elprimo.food.bananas * 8.4;
    elprimo.vtb.account -= elprimo.food.avocados * 7;
    elprimo.vtb.account -= elprimo.food.potato * 14;
    elprimo.vtb.account -= elprimo.food.orange * 10.5;
    elprimo.vtb.account -= elprimo.food.yogurt * 10.5;
    elprimo.vtb.account -= elprimo.food.olive_oil * 1.4;
    elprimo.vtb.account -= elprimo.food.bread * 3.5;
    elprimo.vtb.account -= elprimo.food.frozen_berries * 7;
    elprimo.vtb.account -= elprimo.food.dark_chocolate * 3;
    elprimo.vtb.account -= elprimo.food.protein_bar * 6;
    elprimo.vtb.account -= elprimo.food.honey * 5;
    elprimo.vtb.account -= elprimo.food.marshmallow_sugar_free * 4;
    elprimo.vtb.account -= elprimo.food.peanut_butter * 5;
    elprimo.vtb.account -= elprimo.food.salmon_fillet * 15;
    elprimo.vtb.account -= elprimo.food.beef_steak * 15;
    elprimo.vtb.account -= elprimo.food.sweet_potato * 20;
    elprimo.vtb.account -= elprimo.food.bell_pepper_red * 10;
    elprimo.vtb.account -= elprimo.food.chia_seeds * 3;
    elprimo.vtb.account -= elprimo.food.coconut_oil * 4;
    elprimo.vtb.account -= elprimo.food.green_tea_bags * 1.2;
    elprimo.vtb.account -= elprimo.food.coffee_beans * 1.5;

    elprimo.food.ovsyanka += elprimo.food.ovsyanka * inflation / 12;
    elprimo.food.eggs += elprimo.food.eggs * inflation / 12;
    elprimo.food.apples += elprimo.food.apples * inflation / 12;
    elprimo.food.buckwheat += elprimo.food.buckwheat * inflation / 12;
    elprimo.food.broccoli += elprimo.food.broccoli * inflation / 12;
    elprimo.food.fish += elprimo.food.fish * inflation / 12;
    elprimo.food.rice += elprimo.food.rice * inflation / 12;
    elprimo.food.tomatoes += elprimo.food.tomatoes * inflation / 12;
    elprimo.food.cucumbers += elprimo.food.cucumbers * inflation / 12;
    elprimo.food.nuts += elprimo.food.nuts * inflation / 12;
    elprimo.food.tvorog += elprimo.food.tvorog * inflation / 12;
    elprimo.food.bananas += elprimo.food.bananas * inflation / 12;
    elprimo.food.avocados += elprimo.food.avocados * inflation / 12;
    elprimo.food.potato += elprimo.food.potato * inflation / 12;
    elprimo.food.orange += elprimo.food.orange * inflation / 12;
    elprimo.food.yogurt += elprimo.food.yogurt * inflation / 12;
    elprimo.food.olive_oil += elprimo.food.olive_oil * inflation / 12;
    elprimo.food.bread += elprimo.food.bread * inflation / 12;
    elprimo.food.frozen_berries += elprimo.food.frozen_berries * inflation / 12;
    elprimo.food.dark_chocolate += elprimo.food.dark_chocolate * inflation / 12;
    elprimo.food.protein_bar += elprimo.food.protein_bar * inflation / 12;
    elprimo.food.honey += elprimo.food.honey * inflation / 12;
    elprimo.food.marshmallow_sugar_free += elprimo.food.marshmallow_sugar_free * inflation / 12;
    elprimo.food.peanut_butter += elprimo.food.peanut_butter * inflation / 12;
    elprimo.food.salmon_fillet += elprimo.food.salmon_fillet * inflation / 12;
    elprimo.food.beef_steak += elprimo.food.beef_steak * inflation / 12;
    elprimo.food.sweet_potato += elprimo.food.sweet_potato * inflation / 12;
    elprimo.food.bell_pepper_red += elprimo.food.bell_pepper_red * inflation / 12;
    elprimo.food.chia_seeds += elprimo.food.chia_seeds * inflation / 12;
    elprimo.food.coconut_oil += elprimo.food.coconut_oil * inflation / 12;
    elprimo.food.green_tea_bags += elprimo.food.green_tea_bags * inflation / 12;
    elprimo.food.coffee_beans += elprimo.food.coffee_beans * inflation / 12;
}


void elprimo_car(const int month, const int year)
{
    elprimo.vtb.account -= elprimo.car.gas;
    elprimo.car.gas += elprimo.car.gas * inflation / 12;

    elprimo.vtb.account -= elprimo.car.wash;
    elprimo.car.wash += elprimo.car.wash * inflation / 12;

    if (month == 2 or month == 4 or month == 8 or month == 10 or month == 12){
        elprimo.vtb.account -= elprimo.car.washer_fluid;
    }
    elprimo.car.washer_fluid += elprimo.car.washer_fluid * inflation / 12;

    if (month == 2 or month == 10){
        elprimo.vtb.account -= elprimo.car.antifreez;
    }
    elprimo.car.antifreez += elprimo.car.antifreez * inflation / 12;

    if (month == 3 or month == 11){
        elprimo.vtb.account -= elprimo.car.tires;
    }
    elprimo.car.tires += elprimo.car.tires * inflation / 12;

    if (month == 1){
        elprimo.vtb.account -= (elprimo.car.osago);
    }
    elprimo.car.osago += elprimo.car.osago * inflation / 12;

    if (month == 1){
        elprimo.vtb.account -= (elprimo.car.kasko);
    }
    elprimo.car.kasko += elprimo.car.kasko * inflation / 12;
}


void elprimo_public_transport(const int month, const int year)
{
    elprimo.vtb.account -= elprimo.public_transport.metro;
    elprimo.public_transport.metro += elprimo.public_transport.metro * inflation / 12;

    elprimo.vtb.account -= elprimo.public_transport.bus;
    elprimo.public_transport.bus += elprimo.public_transport.bus * inflation / 12;

    elprimo.vtb.account -= elprimo.public_transport.taxi;
    elprimo.public_transport.taxi += elprimo.public_transport.taxi * inflation / 12;
}


void elprimo_girlfriend(const int month, const int year)
{
    elprimo.vtb.account -= elprimo.girlfriend.date;
    elprimo.vtb.account -= elprimo.girlfriend.flowers;

    if (month == 2 and year == 2027){
        elprimo.vtb.account -= elprimo.girlfriend.ring;
    }
    elprimo.girlfriend.ring += elprimo.girlfriend.ring * inflation / 12;

    if (month == 6 and year == 2028){
        elprimo.vtb.account -= elprimo.girlfriend.earrings;
    }
    elprimo.girlfriend.earrings += elprimo.girlfriend.earrings * inflation / 12;

    if (month == 9 and year == 2029){
        elprimo.vtb.account -= elprimo.girlfriend.necklace;
    }
    elprimo.girlfriend.necklace += elprimo.girlfriend.necklace * inflation / 12;

    if (month == 8 and year == 2031){
        elprimo.vtb.account -= elprimo.girlfriend.watch;
    }
    elprimo.girlfriend.watch += elprimo.girlfriend.watch * inflation / 12;

    elprimo.girlfriend.date += elprimo.girlfriend.date * inflation / 12;
    elprimo.girlfriend.flowers += elprimo.girlfriend.flowers * inflation / 12;
}


void elprimo_gym()
{
    elprimo.vtb.account -= elprimo.gym.protein;
    elprimo.vtb.account -= elprimo.gym.ticket;
    elprimo.vtb.account -= elprimo.gym.bcaa;
    elprimo.vtb.account -= elprimo.gym.creatin;

    elprimo.gym.ticket += elprimo.gym.ticket * inflation / 12;
    elprimo.gym.protein += elprimo.gym.protein * inflation / 12;
    elprimo.vtb.account += elprimo.gym.bcaa * inflation / 12;
    elprimo.vtb.account += elprimo.gym.creatin * inflation * 12;
}


void elprimo_home()
{
    elprimo.vtb.account -= elprimo.home.domnalogi;
    elprimo.home.domnalogi += elprimo.home.domnalogi * inflation / 12;
}


void elprimo_clothing(const int month, const int year)
{
    if (month == 3 or month == 9){
        elprimo.vtb.account -= elprimo.clothing.shoes;
    }
    elprimo.clothing.shoes += elprimo.clothing.shoes * inflation / 12;

    if (month == 4 or month == 10){
        elprimo.vtb.account -= elprimo.clothing.jacket;
    }
    elprimo.clothing.jacket += elprimo.clothing.jacket * inflation / 12;

    if (month == 5 or month == 11){
        elprimo.vtb.account -= elprimo.clothing.pants;
    }
    elprimo.clothing.pants += elprimo.clothing.pants * inflation / 12;

    if (month == 6 or month == 12){
        elprimo.vtb.account -= elprimo.clothing.t_shirt;
    }
    elprimo.clothing.t_shirt += elprimo.clothing.t_shirt * inflation / 12;

    if (month == 7 or month == 1){
        elprimo.vtb.account -= elprimo.clothing.sweatshirt;
    }
    elprimo.clothing.sweatshirt += elprimo.clothing.sweatshirt * inflation / 12;

    if (month == 8 or month == 2){
        elprimo.vtb.account -= elprimo.clothing.underwear;
    }
    elprimo.clothing.underwear += elprimo.clothing.underwear * inflation / 12;

    if (month == 9 or month == 3){
        elprimo.vtb.account -= elprimo.clothing.socks;
    }
    elprimo.clothing.socks += elprimo.clothing.socks * inflation / 12;

    if (month == 10 or month == 4){
        elprimo.vtb.account -= elprimo.clothing.accessories;
    }
    elprimo.clothing.accessories += elprimo.clothing.accessories * inflation / 12;

    if (month == 11 or month == 5){
        elprimo.vtb.account -= elprimo.clothing.sport_shoes;
    }
    elprimo.clothing.sport_shoes += elprimo.clothing.sport_shoes * inflation / 12;

    if (month == 12 or month == 6){
        elprimo.vtb.account -= elprimo.clothing.sportswear;
    }
    elprimo.clothing.sportswear += elprimo.clothing.sportswear * inflation / 12;
}


void elprimo_friends(const int month, const int year)
{
    if (month == 2 or month == 5 or month == 9){
        elprimo.vtb.account -= elprimo.friends.alcohol;
    }
    elprimo.friends.alcohol += elprimo.friends.alcohol * inflation / 12;

    if (month == 4 or month == 7 or month == 11){
        elprimo.vtb.account -= elprimo.friends.cinema;
    }
    elprimo.friends.cinema += elprimo.friends.cinema * inflation / 12;

    if (month == 1 or month == 8 or month == 12){
        elprimo.vtb.account -= elprimo.friends.games;
    }
    elprimo.friends.games += elprimo.friends.games * inflation / 12;

    if (month == 2 or month == 4 or month == 6 or month == 8 or month == 10 or month == 12){
        elprimo.vtb.account -= elprimo.friends.bowling;
    }
    elprimo.friends.bowling += elprimo.friends.bowling * inflation / 12;

    if (month == 3 or month == 6 or month == 9){
        elprimo.vtb.account -= elprimo.friends.shashlyki;
    }
    elprimo.vtb.account += elprimo.friends.shashlyki * inflation / 12;

    if (month == 1 or month == 4 or month == 7 or month == 10){
        elprimo.vtb.account -= elprimo.friends.concerts;
    }
    elprimo.friends.concerts += elprimo.friends.concerts * inflation / 12;

    if (month == 2 or month == 5 or month == 8 or month == 11){
        elprimo.vtb.account -= elprimo.friends.billiard;
    }
    elprimo.friends.billiard += elprimo.friends.billiard * inflation / 12;
}


void elprimo_hobbies(const int month, const int year)
{
    if (month == 1 or month == 4 or month == 7 or month == 10){
        elprimo.vtb.account -= elprimo.hobbies.boxingclub;
    }
    elprimo.hobbies.boxingclub += elprimo.hobbies.boxingclub * inflation / 12;

    if (month == 3 or month == 6 or month == 9 or month == 12){
        elprimo.vtb.account -= elprimo.hobbies.snowboarding;
    }
    elprimo.hobbies.snowboarding += elprimo.hobbies.snowboarding * inflation / 12;

    if (month == 1 or month == 6 or month == 11){
        elprimo.vtb.account -= elprimo.hobbies.swimming;
    }
    elprimo.hobbies.swimming += elprimo.hobbies.swimming * inflation / 12;

    if (month == 2 or month == 7 or month == 12){
        elprimo.vtb.account -= elprimo.hobbies.running;
    }
    elprimo.hobbies.running += elprimo.hobbies.running * inflation / 12;

    if (month == 3 or month == 8 or month == 1){
        elprimo.vtb.account -= elprimo.hobbies.fishing;
    }
    elprimo.hobbies.fishing += elprimo.hobbies.fishing * inflation / 12;

    if (month == 4 or month == 9 or month == 2){
        elprimo.vtb.account -= elprimo.hobbies.hiking;
    }
    elprimo.hobbies.hiking += elprimo.hobbies.hiking * inflation / 12;

    if (month == 5 or month == 10 or month == 3){
        elprimo.vtb.account -= elprimo.hobbies.books;
    }
    elprimo.hobbies.books += elprimo.hobbies.books * inflation / 12;

    if (month == 6 or month == 11 or month == 4){
        elprimo.vtb.account -= elprimo.hobbies.video_games;
    }
    elprimo.hobbies.video_games += elprimo.hobbies.video_games * inflation / 12;
}


void elprimo_boxbattles(const int month, const int year)
{

    if (month == 3 and year == 2027) {
        elprimo.vtb.account += 50'000; //победа 1
    }

    if (month == 5 and year == 2028) {
        elprimo.vtb.account += 45'000; //победа 2
    }

    if (month == 11 and year == 2028) {
        elprimo.vtb.account -= 100'000; //поражение 1
    }


    if (month == 2 and year == 2030) {
        elprimo.vtb.account += 150'000; //победа 3
    }

    if (month == 4 and year == 2031) {
        elprimo.vtb.account += 220'000; //победа 4
    }

    if (month == 7 and year == 2032) {
        elprimo.vtb.account -= 300'000; //поражение 2 и травма (медицинская операция и конец боксерской карьеры)
    }

}


void elprimo_medicine(const int month, const int year)
{
    if (month == 2 or month == 11) {
        elprimo.vtb.account -= elprimo.medicine.visit_to_a_doctor;
    }
    elprimo.medicine.visit_to_a_doctor += elprimo.medicine.visit_to_a_doctor * inflation / 12;

    elprimo.vtb.account -= elprimo.medicine.caffeine_pills_200mg;
    elprimo.vtb.account -= elprimo.medicine.ibuprofen_200mg;
    elprimo.vtb.account -= elprimo.medicine.paracetamol_500mg;
    elprimo.vtb.account -= elprimo.medicine.vitamin_c_effervescent;
    elprimo.vtb.account -= elprimo.medicine.multivitamin_daily;
    elprimo.vtb.account -= elprimo.medicine.magnesium_glycinate;
    elprimo.vtb.account -= elprimo.medicine.melatonin_3mg;
    elprimo.vtb.account -= elprimo.medicine.probiotic_capsules;
    elprimo.vtb.account -= elprimo.medicine.antacid_chewable;
    elprimo.vtb.account -= elprimo.medicine.cough_syrup_100ml;
    elprimo.vtb.account -= elprimo.medicine.bandage_elastic;

    elprimo.medicine.caffeine_pills_200mg += elprimo.medicine.caffeine_pills_200mg * inflation / 12;
    elprimo.medicine.ibuprofen_200mg += elprimo.medicine.ibuprofen_200mg * inflation / 12;
    elprimo.medicine.paracetamol_500mg += elprimo.medicine.paracetamol_500mg * inflation / 12;
    elprimo.medicine.vitamin_c_effervescent += elprimo.medicine.vitamin_c_effervescent * inflation / 12;
    elprimo.medicine.multivitamin_daily += elprimo.medicine.multivitamin_daily * inflation / 12;
    elprimo.medicine.magnesium_glycinate += elprimo.medicine.magnesium_glycinate * inflation / 12;
    elprimo.medicine.melatonin_3mg += elprimo.medicine.melatonin_3mg * inflation / 12;
    elprimo.medicine.probiotic_capsules += elprimo.medicine.probiotic_capsules * inflation / 12;
    elprimo.medicine.antacid_chewable += elprimo.medicine.antacid_chewable * inflation / 12;
    elprimo.medicine.cough_syrup_100ml += elprimo.medicine.cough_syrup_100ml * inflation / 12;
    elprimo.medicine.bandage_elastic += elprimo.medicine.bandage_elastic * inflation / 12;

    if (month == 7 and year == 2032) {
        elprimo.vtb.account -= 500'000; //операция после последнего проигранного боя
    }
}


void elprimo_and_shelly_buying_a_pet(const int month, const int year)
{
    if (month == 1 and year == 2027) {
        elprimo.vtb.account -= elprimo.pet.dog;;
    }
    elprimo.pet.dog += elprimo.pet.dog * inflation / 12;

    if (month == 1 and year == 2028) {
        shelly.vtb.account -= shelly.pet.cat;
    }
    shelly.pet.cat += shelly.pet.cat * inflation / 12;

    if (month == 1 and year == 2029) {
        shelly.vtb.account -= shelly.pet.rabbit;
    }
    shelly.pet.rabbit += shelly.pet.rabbit * inflation / 12;

    if (month == 1 and year == 2030) {
        elprimo.vtb.account -= elprimo.pet.crocodile;
    }
    elprimo.pet.crocodile += elprimo.pet.crocodile * inflation / 12;
}


void elprimo_dog(const int month, const int year)
{
    if (month >= 1 and year >= 2027){
        elprimo.vtb.account -= elprimo.dog.eda;

        elprimo.dog.eda += elprimo.dog.eda * inflation / 12;

        if (month == 6 or month == 9) {
            elprimo.vtb.account -= elprimo.dog.toys;
        }
        elprimo.dog.toys += elprimo.dog.toys * inflation / 12;

        if (month == 1 or month == 10) {
            elprimo.vtb.account -= elprimo.dog.vet;
        }
        elprimo.dog.vet += elprimo.dog.vet * inflation / 12;
    }
}


void elprimo_crocodile(const int month, const int year)
{
    if (month >= 1 and year >= 2030){
        elprimo.vtb.account -= elprimo.crocodile.eda;

        elprimo.crocodile.eda += elprimo.crocodile.eda * inflation / 12;

        if (month == 6) {
            elprimo.vtb.account -= elprimo.crocodile.domik;
        }
        elprimo.crocodile.domik += elprimo.crocodile.domik * inflation / 12;
    }
}


void shelly_cat(const int month, const int year)
{
    if (month >= 1 and year >= 2029){
        shelly.vtb.account -= shelly.cat.eda;

        shelly.cat.eda += shelly.cat.eda * inflation / 12;

        if (month == 6 or month == 9) {
            shelly.vtb.account -= shelly.cat.toys;
        }
        shelly.cat.toys += shelly.cat.toys * inflation / 12;

        if (month == 1 or month == 10) {
            shelly.vtb.account -= shelly.cat.vet;
        }
        shelly.cat.vet += shelly.cat.vet * inflation / 12;
    }
}


void shelly_rabbit(const int month, const int year)
{
    if (month >= 1 and year >= 2028){
        shelly.vtb.account -= shelly.rabbit.eda;

        shelly.rabbit.eda += shelly.rabbit.eda * inflation / 12;

        if (month == 6 or month == 9) {
            shelly.vtb.account -= shelly.rabbit.toys;
        }
        shelly.rabbit.toys += shelly.rabbit.toys * inflation / 12;

        if (month == 1 or month == 10) {
            shelly.vtb.account -= shelly.rabbit.vet;
        }
        shelly.rabbit.vet += shelly.rabbit.vet * inflation / 12;

        if (month == 6) {
            shelly.vtb.account -= shelly.rabbit.domik;
        }
        shelly.rabbit.domik += shelly.rabbit.domik * inflation / 12;
    } 
}



void shelly_salary(const int month, const int year)
{
    if (month == 12){
        shelly.vtb.account += shelly.salary;
    }

    if (month == 1 and year == 2029){
        shelly.salary *= 1.3;
    }

    if (month == 6 and year == 2034){
        shelly.salary *= 1.2;
    }

    shelly.vtb.account += shelly.salary;
}


void shelly_deposite(const int month, const int year)
{
    if (year == 2026) shelly.vtb.interest = 14;
    if (year == 2028) shelly.vtb.interest = 13;
    if (year == 2030) shelly.vtb.interest = 12;
    if (year == 2032) shelly.vtb.interest = 11;
    if (year == 2034) shelly.vtb.interest = 10;

    shelly.vtb.deposite += shelly.vtb.deposite * (shelly.vtb.interest / 12.0 / 100.0);

    shelly.vtb.deposite += shelly.vtb.account;
    shelly.vtb.account = 0;
}


void shelly_food()
{
    shelly.vtb.account -= shelly.food.frozen_berries * 7;
    shelly.vtb.account -= shelly.food.almonds * 2.1;
    shelly.vtb.account -= shelly.food.chia * 1.4;
    shelly.vtb.account -= shelly.food.bananas * 8.4;
    shelly.vtb.account -= shelly.food.apples * 10.5;
    shelly.vtb.account -= shelly.food.tofu * 10.5;
    shelly.vtb.account -= shelly.food.tomatoes * 7;
    shelly.vtb.account -= shelly.food.cucumbers * 7;
    shelly.vtb.account -= shelly.food.pepper * 7;
    shelly.vtb.account -= shelly.food.brown_rice * 5.6;
    shelly.vtb.account -= shelly.food.olive_oil * 1.4;
    shelly.vtb.account -= shelly.food.avocados * 7;
    shelly.vtb.account -= shelly.food.carrots * 7;
    shelly.vtb.account -= shelly.food.broccoli * 10.5;
    shelly.vtb.account -= shelly.food.orange * 10.5;
    shelly.vtb.account -= shelly.food.hummus * 3.5;
    shelly.vtb.account -= shelly.food.vegan_chocolate * 4;
    shelly.vtb.account -= shelly.food.coconut_chips * 3;
    shelly.vtb.account -= shelly.food.agave_syrup * 6;
    shelly.vtb.account -= shelly.food.vegan_cookies * 10;
    shelly.vtb.account -= shelly.food.soy_sauce * 5;
    shelly.vtb.account -= shelly.food.coconut_yogurt * 15;

    shelly.food.frozen_berries += shelly.food.frozen_berries * inflation / 12;
    shelly.food.almonds += shelly.food.almonds * inflation / 12;
    shelly.food.chia += shelly.food.chia * inflation / 12;
    shelly.food.bananas += shelly.food.bananas * inflation / 12;
    shelly.food.apples += shelly.food.apples * inflation / 12;
    shelly.food.tofu += shelly.food.tofu * inflation / 12;
    shelly.food.tomatoes += shelly.food.tomatoes * inflation / 12;
    shelly.food.cucumbers += shelly.food.cucumbers * inflation / 12;
    shelly.food.pepper += shelly.food.pepper * inflation / 12;
    shelly.food.brown_rice += shelly.food.brown_rice * inflation / 12;
    shelly.food.olive_oil += shelly.food.olive_oil * inflation / 12;
    shelly.food.avocados += shelly.food.avocados * inflation / 12;
    shelly.food.carrots += shelly.food.carrots * inflation / 12;
    shelly.food.broccoli += shelly.food.broccoli * inflation / 12;
    shelly.food.orange += shelly.food.orange * inflation / 12;
    shelly.food.hummus += shelly.food.hummus * inflation / 12;
    shelly.food.vegan_chocolate += shelly.food.vegan_chocolate * inflation / 12;;
    shelly.food.coconut_chips += shelly.food.coconut_chips * inflation / 12;
    shelly.food.agave_syrup += shelly.food.agave_syrup * inflation / 12;
    shelly.food.vegan_cookies += shelly.food.vegan_cookies * inflation / 12;
    shelly.food.soy_sauce += shelly.food.soy_sauce * inflation / 12;
    shelly.food.coconut_yogurt += shelly.food.coconut_yogurt * inflation / 12;
}


void shelly_flat(const int month, const int year)
{
    if (shelly_pereezd_k_elprimo == false){
        shelly.vtb.account -= shelly.flat.rent;  
    }
    else{
        shelly.flat.rent = 0;
    }

    shelly.flat.rent += shelly.flat.rent * inflation / 12;
}


void shelly_car(const int month, const int year)
{
    if (newcar_own == false){
        shelly.vtb.account -= shelly.car.gas;
        shelly.car.gas += shelly.car.gas * inflation / 12;

        shelly.vtb.account -= shelly.car.wash;
        shelly.car.wash += shelly.car.wash * inflation / 12;

        if (month == 2 or month == 4 or month == 8 or month == 10 or month == 12){
            shelly.vtb.account -= shelly.car.washer_fluid;
        }
        shelly.car.washer_fluid += shelly.car.washer_fluid * inflation / 12;

        if (month == 2 or month == 10){
            shelly.vtb.account -= shelly.car.antifreez;
        }
        shelly.car.antifreez += shelly.car.antifreez * inflation / 12;

        if (month == 3 or month == 11){
            shelly.vtb.account -= shelly.car.tires;
        }
        shelly.car.tires += shelly.car.tires * inflation / 12;

        if (month == 1){
            shelly.vtb.account -= (shelly.car.osago);
        }
        shelly.car.osago += shelly.car.osago * inflation / 12;

        if (month == 1){
            shelly.vtb.account -= (shelly.car.kasko);
        }
        shelly.car.kasko += shelly.car.kasko * inflation / 12;
    }

    else
    {
        shelly.vtb.account -= shelly.newcar.gas;
        shelly.newcar.gas += shelly.newcar.gas * inflation / 12;

        shelly.vtb.account -= shelly.newcar.wash;
        shelly.newcar.wash += shelly.newcar.wash * inflation / 12;

        if (month == 2 or month == 4 or month == 8 or month == 10 or month == 12){
            shelly.vtb.account -= shelly.newcar.washer_fluid;
        }
        shelly.newcar.washer_fluid += shelly.newcar.washer_fluid * inflation / 12;

        if (month == 2 or month == 10){
            shelly.vtb.account -= shelly.newcar.antifreez;
        }
        shelly.newcar.antifreez += shelly.newcar.antifreez * inflation / 12;

        if (month == 3 or month == 11){
            shelly.vtb.account -= shelly.newcar.tires;
        }
        shelly.newcar.tires += shelly.newcar.tires * inflation / 12;

        if (month == 1){
            shelly.vtb.account -= (shelly.newcar.osago);
        }
        shelly.newcar.osago += shelly.newcar.osago * inflation / 12;

        if (month == 1){
            shelly.vtb.account -= (shelly.newcar.kasko);
        }
        shelly.newcar.kasko += shelly.newcar.kasko * inflation / 12;
    }
}


void shelly_public_transport(const int month, const int year)
{
    shelly.vtb.account -= shelly.public_transport.metro;
    shelly.public_transport.metro += shelly.public_transport.metro * inflation / 12;

    shelly.vtb.account -= shelly.public_transport.bus;
    shelly.public_transport.bus += shelly.public_transport.bus * inflation / 12;

    shelly.vtb.account -= shelly.public_transport.taxi;
    shelly.public_transport.taxi += shelly.public_transport.taxi * inflation / 12;
}


void shelly_clothing(const int month, const int year)
{
    if (month == 3 or month == 9){
        shelly.vtb.account -= shelly.clothing.dresses;
    }
    shelly.clothing.dresses += shelly.clothing.dresses * inflation / 12;

    if (month == 4 or month == 10){
        shelly.vtb.account -= shelly.clothing.skirts;
    }
    shelly.clothing.skirts += shelly.clothing.skirts * inflation / 12;

    if (month == 5 or month == 11){
        shelly.vtb.account -= shelly.clothing.blouses;
    }
    shelly.clothing.blouses += shelly.clothing.blouses * inflation / 12;

    if (month == 6 or month == 12){
        shelly.vtb.account -= shelly.clothing.t_shirt;
    }
    shelly.clothing.t_shirt += shelly.clothing.t_shirt * inflation / 12;

    if (month == 7 or month == 1){
        shelly.vtb.account -= shelly.clothing.sweatshirt;
    }
    shelly.clothing.sweatshirt += shelly.clothing.sweatshirt * inflation / 12;

    if (month == 8 or month == 2){
        shelly.vtb.account -= shelly.clothing.underwear;
    }
    shelly.clothing.underwear += shelly.clothing.underwear * inflation / 12;

    if (month == 9 or month == 3){
        shelly.vtb.account -= shelly.clothing.socks;
    }
    shelly.clothing.socks += shelly.clothing.socks * inflation / 12;

    if (month == 10 or month == 4){
        shelly.vtb.account -= shelly.clothing.accessories;
    }
    shelly.clothing.accessories += shelly.clothing.accessories * inflation / 12;

    if (month == 12 or month == 6){
        shelly.vtb.account -= shelly.clothing.sportswear;
    }
    shelly.clothing.sportswear += shelly.clothing.sportswear * inflation / 12;
}


void shelly_friends(const int month, const int year)
{
    if (month == 1 or month == 4 or month == 7 or month == 10){
        shelly.vtb.account -= shelly.friends.coffee;
    }
    shelly.friends.coffee += shelly.friends.coffee * inflation / 12;

    if (month == 3 or month == 6 or month == 9 or month == 12){
        shelly.vtb.account -= shelly.friends.theatre;
    }
    shelly.friends.theatre += shelly.friends.theatre * inflation / 12;

    if (month == 1 or month == 5 or month == 9){
        shelly.vtb.account -= shelly.friends.fotosession;
    }
    shelly.friends.fotosession += shelly.friends.fotosession * inflation / 12;

    if (month == 2 or month == 6 or month == 10){
        shelly.vtb.account -= shelly.friends.shopping;
    }
    shelly.friends.shopping += shelly.friends.shopping * inflation / 12;

    if (month == 4 or month == 8 or month == 12){
        shelly.vtb.account -= shelly.friends.massage;
    }
    shelly.friends.massage += shelly.friends.massage * inflation / 12;

    if (month == 1 or month == 5 or month == 9){
        shelly.vtb.account -= shelly.friends.restaurant;
    }
    shelly.friends.restaurant += shelly.friends.restaurant * inflation / 12;

    if (month == 3 or month == 7 or month == 11){
        shelly.vtb.account -= shelly.friends.club;
    }
    shelly.friends.club += shelly.friends.club * inflation / 12;

}


void shelly_hobbies(const int month, const int year)
{
    if (month == 1 or month == 4 or month == 7 or month == 10){
        shelly.vtb.account -= shelly.hobbies.dancing;
    }
    shelly.hobbies.dancing += shelly.hobbies.dancing * inflation / 12;

    if (month == 2 or month == 5 or month == 8 or month == 11){
        shelly.vtb.account -= shelly.hobbies.painting;
    }
    shelly.hobbies.painting += shelly.hobbies.painting * inflation / 12;

    if (month == 3 or month == 6 or month == 9 or month == 12){
        shelly.vtb.account -= shelly.hobbies.art;
    }
    shelly.hobbies.art += shelly.hobbies.art * inflation / 12;

    if (month == 4 or month == 8 or month == 12){
        shelly.vtb.account -= shelly.hobbies.cooking;
    }
    shelly.hobbies.cooking += shelly.hobbies.cooking * inflation / 12;

    if (month == 2 or month == 6 or month == 10){
        shelly.vtb.account -= shelly.hobbies.photography;
    }
    shelly.hobbies.photography += shelly.hobbies.photography * inflation / 12;

    if (month == 3 or month == 7 or month == 11){
        shelly.vtb.account -= shelly.hobbies.music;
    }
    shelly.hobbies.music += shelly.hobbies.music * inflation / 12;
}


void shelly_medicine(const int month, const int year)
{
    if (month == 2 or month == 11){
        shelly.vtb.account -= shelly.medicine.visit_to_a_doctor;
    }
    shelly.medicine.visit_to_a_doctor += shelly.medicine.visit_to_a_doctor * inflation / 12;

    shelly.vtb.account -= shelly.medicine.caffeine_pills_200mg;
    shelly.vtb.account -= shelly.medicine.ibuprofen_200mg;
    shelly.vtb.account -= shelly.medicine.paracetamol_500mg;
    shelly.vtb.account -= shelly.medicine.vitamin_c_effervescent;
    shelly.vtb.account -= shelly.medicine.multivitamin_daily;
    shelly.vtb.account -= shelly.medicine.magnesium_glycinate;
    shelly.vtb.account -= shelly.medicine.melatonin_3mg;
    shelly.vtb.account -= shelly.medicine.probiotic_capsules;
    shelly.vtb.account -= shelly.medicine.antacid_chewable;
    shelly.vtb.account -= shelly.medicine.cough_syrup_100ml;
    shelly.vtb.account -= shelly.medicine.bandage_elastic;

    shelly.medicine.caffeine_pills_200mg += shelly.medicine.caffeine_pills_200mg * inflation / 12;
    shelly.medicine.ibuprofen_200mg += shelly.medicine.ibuprofen_200mg * inflation / 12;
    shelly.medicine.paracetamol_500mg += shelly.medicine.paracetamol_500mg * inflation / 12;
    shelly.medicine.vitamin_c_effervescent += shelly.medicine.vitamin_c_effervescent * inflation / 12;
    shelly.medicine.multivitamin_daily += shelly.medicine.multivitamin_daily * inflation / 12;
    shelly.medicine.magnesium_glycinate += shelly.medicine.magnesium_glycinate * inflation / 12;
    shelly.medicine.melatonin_3mg += shelly.medicine.melatonin_3mg * inflation / 12;
    shelly.medicine.probiotic_capsules += shelly.medicine.probiotic_capsules * inflation / 12;
    shelly.medicine.antacid_chewable += shelly.medicine.antacid_chewable * inflation / 12;
    shelly.medicine.cough_syrup_100ml += shelly.medicine.cough_syrup_100ml * inflation / 12;
    shelly.medicine.bandage_elastic += shelly.medicine.bandage_elastic * inflation / 12;
}

void shelly_and_elprimo_marriage(const int month, const int year)
{
    if (month == 7 and year == 2032) {
        elprimo.vtb.account -= 1'500'000;
        shelly_pereezd_k_elprimo = true;
    }
}

void shelly_newcar(const int month, const int year)
{
    if (month == 4 and year == 2034){
        newcar_own = true;
        elprimo.vtb.account -= 2'000'000;
    }
}


void shelly_and_elprimo_gifts(const int month, const int year)
{
    if (month == 1){
        //noviy god
        elprimo.vtb.account -= elprimo.gifts.gifts;
        shelly.vtb.account -= shelly.gifts.gifts;
    }

    if (month == 2){
        //14 fevralya
        elprimo.vtb.account -= elprimo.gifts.gifts * 0.5;
        shelly.vtb.account -= shelly.gifts.gifts * 0.5;
    }

    if (month == 7){
        //godovschina svadbi
        elprimo.vtb.account -= elprimo.gifts.gifts;
        shelly.vtb.account -= shelly.gifts.gifts;
    }

    if (month == 11){
        //elprimo dr
        shelly.vtb.account -= shelly.gifts.gifts * 1.5;
    }

    if (month == 12){
        //shelly dr
        elprimo.vtb.account -= elprimo.gifts.gifts * 1.5;
    }
}


void family_holiday(const int month, const int year)
{
    if (year > 2032)
    {
        if (month == 6){
            elprimo.vtb.account -= elprimo.holiday * 5;
            shelly.vtb.account -= shelly.holiday * 2;
        }

        if (month == 1 and year == 2035){
            elprimo.vtb.account -= elprimo.holiday * 3;
            shelly.vtb.account -= shelly.holiday * 1.5;
        }
    }
    elprimo.holiday += elprimo.holiday * inflation / 12;
    shelly.holiday += shelly.holiday * inflation / 12;
}


void family_electrical_equipment(const int month, const int year)
{
    // обновление электрооборудования в квартире (шелли захотела все новое)
    if (month == 1 and year == 2033){
        elprimo.vtb.account -= family.electrical_equipment.refrigirator * 0.5;
        shelly.vtb.account -= family.electrical_equipment.refrigirator * 0.5;
    }
    family.electrical_equipment.refrigirator += family.electrical_equipment.refrigirator * inflation / 12;

    if (month == 2 and year == 2033){
        elprimo.vtb.account -= family.electrical_equipment.washing_machine * 0.5;
        shelly.vtb.account -= family.electrical_equipment.washing_machine * 0.5;
    }
    family.electrical_equipment.washing_machine += family.electrical_equipment.washing_machine * inflation / 12;

    if (month == 3 and year == 2033){
        elprimo.vtb.account -= family.electrical_equipment.dishwasher * 0.5;
        shelly.vtb.account -= family.electrical_equipment.dishwasher * 0.5;
    }
    family.electrical_equipment.dishwasher += family.electrical_equipment.dishwasher * inflation / 12;

    if (month == 4 and year == 2033){
        elprimo.vtb.account -= family.electrical_equipment.microwave * 0.5;
        shelly.vtb.account -= family.electrical_equipment.microwave * 0.5;
    }
    family.electrical_equipment.microwave += family.electrical_equipment.microwave * inflation / 12;

    if (month == 5 and year == 2033){
        elprimo.vtb.account -= family.electrical_equipment.tv * 0.5;
        shelly.vtb.account -= family.electrical_equipment.tv * 0.5;
    }
    family.electrical_equipment.tv += family.electrical_equipment.tv * inflation / 12;

    if (month == 6 and year == 2033){
        elprimo.vtb.account -= family.electrical_equipment.vacuum_cleaner * 0.5;
        shelly.vtb.account -= family.electrical_equipment.vacuum_cleaner * 0.5;
    }
    family.electrical_equipment.vacuum_cleaner += family.electrical_equipment.vacuum_cleaner * inflation / 12;

    if (month == 7 and year == 2033){
        elprimo.vtb.account -= family.electrical_equipment.coffee_maker * 0.5;
        shelly.vtb.account -= family.electrical_equipment.coffee_maker * 0.5;
    }
    family.electrical_equipment.coffee_maker += family.electrical_equipment.coffee_maker * inflation / 12;

    if (month == 8 and year == 2033){
        elprimo.vtb.account -= family.electrical_equipment.air_conditioner * 0.5;
        shelly.vtb.account -= family.electrical_equipment.air_conditioner * 0.5;
    }
    family.electrical_equipment.air_conditioner += family.electrical_equipment.air_conditioner * inflation / 12;

    if (month == 9 and year == 2033){
        elprimo.vtb.account -= family.electrical_equipment.iron * 0.5;
        shelly.vtb.account -= family.electrical_equipment.iron * 0.5;
    }
    family.electrical_equipment.iron += family.electrical_equipment.iron * inflation / 12;

    if (month == 10 and year == 2033){
        elprimo.vtb.account -= family.electrical_equipment.computer * 0.5;
        shelly.vtb.account -= family.electrical_equipment.computer * 0.5;
    }
    family.electrical_equipment.computer += family.electrical_equipment.computer * inflation / 12;

    if (month == 12 and year == 2033){
        elprimo.vtb.account -= family.electrical_equipment.gaming_console * 0.5;
        shelly.vtb.account -= family.electrical_equipment.gaming_console * 0.5;
    }
    family.electrical_equipment.gaming_console += family.electrical_equipment.gaming_console * inflation / 12;

    if (month == 1 and year == 2034){
        elprimo.vtb.account -= family.electrical_equipment.toaster * 0.5;
        shelly.vtb.account -= family.electrical_equipment.toaster * 0.5;
    }
    family.electrical_equipment.toaster += family.electrical_equipment.toaster * inflation / 12;

    if (month == 2 and year == 2034){
        elprimo.vtb.account -= family.electrical_equipment.oven * 0.5;
        shelly.vtb.account -= family.electrical_equipment.oven * 0.5;
    }
    family.electrical_equipment.oven += family.electrical_equipment.oven * inflation / 12;

    if (month == 3 and year == 2034){
        elprimo.vtb.account -= family.electrical_equipment.blender * 0.5;
        shelly.vtb.account -= family.electrical_equipment.blender * 0.5;
    }
    family.electrical_equipment.blender += family.electrical_equipment.blender * inflation / 12;
}


void family_furniture(const int month, const int year)
{
    //новая мебель
    if (month == 1 and year == 2033){
        elprimo.vtb.account -= family.furniture.armchair * 0.5;
        shelly.vtb.account -= family.furniture.armchair * 0.5;
    }
    family.furniture.armchair += family.furniture.armchair * inflation / 12;

    if (month == 2 and year == 2033){
        elprimo.vtb.account -= family.furniture.bath * 0.5;
        shelly.vtb.account -= family.furniture.bath * 0.5;
    }
    family.furniture.bath += family.furniture.bath * inflation / 12;

    if (month == 3 and year == 2033){
        elprimo.vtb.account -= family.furniture.bed * 0.5;
        shelly.vtb.account -= family.furniture.bed * 0.5;
    }
    family.furniture.bed += family.furniture.bed * inflation / 12;

    if (month == 4 and year == 2033){
        elprimo.vtb.account -= family.furniture.bench * 0.5;
        shelly.vtb.account -= family.furniture.bench * 0.5;
    }
    family.furniture.bench += family.furniture.bench * inflation / 12;

    if (month == 5 and year == 2033){
        elprimo.vtb.account -= family.furniture.bookcase * 0.5;
        shelly.vtb.account -= family.furniture.bookcase * 0.5;
    }
    family.furniture.bookcase += family.furniture.bookcase * inflation / 12;

    if (month == 6 and year == 2033){
        elprimo.vtb.account -= family.furniture.bookshelf * 0.5;
        shelly.vtb.account -= family.furniture.bookshelf * 0.5;
    }
    family.furniture.bookshelf += family.furniture.bookshelf * inflation / 12;

    if (month == 7 and year == 2033){
        elprimo.vtb.account -= family.furniture.cabinet * 0.5;
        shelly.vtb.account -= family.furniture.cabinet * 0.5;
    }
    family.furniture.cabinet += family.furniture.cabinet * inflation / 12;

    if (month == 8 and year == 2033){
        elprimo.vtb.account -= family.furniture.chairs * 0.5;
        shelly.vtb.account -= family.furniture.chairs * 0.5;
    }
    family.furniture.chairs += family.furniture.chairs * inflation / 12;

    if (month == 9 and year == 2033){
        elprimo.vtb.account -= family.furniture.coatrack * 0.5;
        shelly.vtb.account -= family.furniture.coatrack * 0.5;
    }
    family.furniture.coatrack += family.furniture.coatrack * inflation / 12;

    if (month == 10 and year == 2033){
        elprimo.vtb.account -= family.furniture.coffetable * 0.5;
        shelly.vtb.account -= family.furniture.coffetable * 0.5;
    }
    family.furniture.coffetable += family.furniture.coffetable * inflation / 12;

    if (month == 11 and year == 2033){
        elprimo.vtb.account -= family.furniture.desk * 0.5;
        shelly.vtb.account -= family.furniture.desk * 0.5;
    }
    family.furniture.desk += family.furniture.desk * inflation / 12;

    if (month == 12 and year == 2033){
        elprimo.vtb.account -= family.furniture.mattress * 0.5;
        shelly.vtb.account -= family.furniture.mattress * 0.5;
    }
    family.furniture.mattress += family.furniture.mattress * inflation / 12;

    if (month == 1 and year == 2034){
        elprimo.vtb.account -= family.furniture.shelves * 0.5;
        shelly.vtb.account -= family.furniture.shelves * 0.5;
    }
    family.furniture.shelves += family.furniture.shelves * inflation / 12;

    if (month == 2 and year == 2034){
        elprimo.vtb.account -= family.furniture.shower * 0.5;
        shelly.vtb.account -= family.furniture.shower * 0.5;
    }
    family.furniture.shower += family.furniture.shower * inflation / 12;

    if (month == 3 and year == 2034){
        elprimo.vtb.account -= family.furniture.sink * 0.5;
        shelly.vtb.account -= family.furniture.sink * 0.5;
    }
    family.furniture.sink += family.furniture.sink * inflation / 12;

    if(month == 4 and year == 2034){
        elprimo.vtb.account -= family.furniture.sofa * 0.5;
        shelly.vtb.account -= family.furniture.sofa * 0.5;
    }
    family.furniture.sofa += family.furniture.sofa * inflation / 12;

    if (month == 5 and year == 2034){
        elprimo.vtb.account -= family.furniture.stool * 0.5;
        shelly.vtb.account -= family.furniture.stool * 0.5;
    }
    family.furniture.stool += family.furniture.stool * inflation / 12;

    if (month == 6 and year == 2034){
        elprimo.vtb.account -= family.furniture.table * 0.5;
        shelly.vtb.account -= family.furniture.table * 0.5;
    }
    family.furniture.table += family.furniture.table * inflation / 12;

    if (month == 7 and year == 2034){
        elprimo.vtb.account -= family.furniture.toilet * 0.5;
        shelly.vtb.account -= family.furniture.toilet * 0.5;
    }
    family.furniture.toilet += family.furniture.toilet * inflation / 12;

    if (month == 8 and year == 2034){
        elprimo.vtb.account -= family.furniture.wardrobe * 0.5;
        shelly.vtb.account -= family.furniture.wardrobe * 0.5;
    }
    family.furniture.wardrobe += family.furniture.wardrobe * inflation / 12;
}


void print_results()
{

    printf("Salary elprimo = %.2f\n", elprimo.salary);

    RUB capitalelprimo = 0;

    capitalelprimo += elprimo.car.value;
    capitalelprimo += elprimo.vtb.deposite;
    capitalelprimo += elprimo.vtb.account;

    printf("Capital elprimo = %.2f\n", capitalelprimo);

    printf("Salary shelly = %.2f\n", shelly.salary);

    RUB capitalshelly = 0;

    capitalshelly += shelly.newcar.value;
    capitalshelly += shelly.vtb.deposite;
    capitalshelly += shelly.vtb.account;

    printf("Capital shelly = %.2f\n", capitalshelly);

    RUB familycapital = capitalelprimo + capitalshelly;
    printf("Total capital = %.2f\n", familycapital);

}


void simulation()
{
    int month = 3;
    int year = 2026;

    while (not (month == 4 and year == 2036)){

        elprimo_salary(month, year);
        elprimo_car(month, year);
        elprimo_gym();
        elprimo_girlfriend(month, year);
        elprimo_home;
        elprimo_inflation(month, year);
        elprimo_dog(month, year);
        elprimo_crocodile(month, year);
        elprimo_boxbattles(month, year);
        elprimo_food();
        elprimo_friends(month, year);
        elprimo_medicine(month, year);
        elprimo_and_shelly_buying_a_pet(month, year);
        elprimo_clothing(month, year);
        elprimo_public_transport(month, year);

        shelly_salary(month, year);
        shelly_food();
        shelly_flat(month, year);
        shelly_medicine(month, year);
        shelly_car(month, year);
        shelly_cat(month, year);
        shelly_rabbit(month, year);
        shelly_clothing(month, year);
        shelly_public_transport(month, year);
        shelly_newcar(month, year);
        shelly_friends(month, year);

        elprimo_deposite(month, year);
        shelly_deposite(month, year);

        shelly_and_elprimo_marriage(month, year);
        shelly_and_elprimo_gifts(month, year);
        family_electrical_equipment(month, year);
        family_furniture(month, year);
        family_holiday(month, year);
        

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    family_init();

    simulation();

    print_results();
}