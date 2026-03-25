#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using Percent = float;
using RUB = long long int;
using USD = long long int;

struct Car {
    RUB value;
    RUB gas;
    RUB STO;
    RUB OSAGO;
    RUB tires;
    RUB washing;
    RUB parking_space;
    RUB CASCO;
    RUB antifreeze;
    RUB brake_pads;
    RUB insurance;
    RUB fine;
    RUB wash_parking;
    RUB tax;
};

struct Trip {
    RUB flight_tickets;
    RUB hotel;
    RUB meals;
    RUB excursions;
    RUB transport;
    RUB insurance;
    RUB visa;
    RUB souvenirs;
    RUB luggage;
    RUB entertainment;
    RUB guide_services;
    RUB travel_agency;
    RUB visa_center;
    RUB taxi;
    RUB tips;
};

struct Dog {
    RUB purchase;
    RUB dog_food;
    RUB toys;
    RUB bowl;
    RUB bed;
    RUB collar_and_leash;
    RUB grooming;
    RUB veterinarian;
    RUB vaccines;
    RUB vitamins;
    RUB treats;
    RUB training;
    RUB kennel;
    RUB leash;
    RUB muzzle;
    RUB dog_sitter;
    RUB dog_clothes;
    RUB shampoo;
    RUB brush;
};

struct Flat {
    RUB rent;
    RUB household_supplies;
    RUB housing_and_communal_services;
    RUB furniture;
    RUB cleaning;
    RUB repair;
    RUB deposit;
    RUB realtors_commission;
    RUB electricity;
    RUB internet;
    RUB water;
    RUB gas;
    RUB security;
    RUB air_conditioner;
    RUB heating;
    RUB garbage;
    RUB renovation;
};

struct Cat {
    RUB purchase;
    RUB cat_food;
    RUB cat_litter;
    RUB toys;
    RUB tray;
    RUB little_house;
    RUB scratching_post;
    RUB grooming;
    RUB veterinarian;
    RUB vitamins;
    RUB treats;
    RUB carrier;
    RUB antiparasitic;
    RUB cat_tree;
    RUB nail_clipper;
    RUB brush;
    RUB collar;
};

struct Hamster {
    RUB purchase;
    RUB cage;
    RUB bedding;
    RUB food;
    RUB treats;
    RUB toys;
    RUB water_bottle;
    RUB bowl;
    RUB veterinarian;
    RUB vitamins;
    RUB exercise_ball;
    RUB sawdust;
    RUB hay;
    RUB transport_cage;
    RUB wheel;
    RUB house;
    RUB mineral_stone;
    RUB sand_bath;
    RUB tunnel;
};

struct Parrot {
    RUB purchase;
    RUB cage;
    RUB food;
    RUB treats;
    RUB toys;
    RUB perches;
    RUB veterinarian;
    RUB vitamins;
    RUB carrier;
    RUB cage_cleaner;
    RUB cuttlebone;
    RUB mirror;
    RUB swing;
    RUB ladder;
    RUB bell;
};

struct Fish {
    RUB purchase;
    RUB aquarium;
    RUB filter;
    RUB heater;
    RUB lighting;
    RUB decorations;
    RUB fish_food;
    RUB water_treatment;
    RUB veterinarian;
    RUB plants;
    RUB gravel;
    RUB air_pump;
    RUB net;
    RUB thermometer;
    RUB background;
};

struct Rabbit {
    RUB purchase;
    RUB cage;
    RUB food;
    RUB hay;
    RUB treats;
    RUB toys;
    RUB bedding;
    RUB water_bottle;
    RUB bowl;
    RUB veterinarian;
    RUB vitamins;
    RUB carrier;
    RUB brush;
    RUB nail_clipper;
};

struct Turtle {
    RUB purchase;
    RUB terrarium;
    RUB food;
    RUB vitamins;
    RUB heater;
    RUB lighting;
    RUB filter;
    RUB decorations;
    RUB veterinarian;
    RUB substrate;
    RUB water_conditioner;
};

struct Wedding {
    RUB dress;
    RUB suit;
    RUB venue;
    RUB catering;
    RUB photographer;
    RUB videographer;
    RUB music;
    RUB flowers;
    RUB invitations;
    RUB cake;
    RUB rings;
    RUB honeymoon;
    RUB registrar;
    RUB transport;
    RUB gifts_for_guests;
    RUB makeup_artist;
    RUB hair_stylist;
    RUB limousine;
    RUB fireworks;
    RUB rehearsal_dinner;
    RUB wedding_planner;
    RUB photo_album;
};

struct Child {
    bool isBorn;
    int birth_month;
    int birth_year;
    RUB prenatal_vitamins;
    RUB doctor_visits;
    RUB ultrasound;
    RUB maternity_clothes;
    RUB childbirth;
    RUB stroller;
    RUB crib;
    RUB mattress;
    RUB bedding;
    RUB changing_table;
    RUB baby_bath;
    RUB baby_monitor;
    RUB diapers;
    RUB baby_wipes;
    RUB baby_clothes;
    RUB baby_food;
    RUB bottles;
    RUB pacifiers;
    RUB sterilizer;
    RUB bottle_warmer;
    RUB car_seat;
    RUB high_chair;
    RUB playpen;
    RUB toys;
    RUB books;
    RUB vaccinations;
    RUB pediatrician;
    RUB medications;
    RUB nanny;
    RUB nursery;
    RUB kindergarten;
    RUB school;
    RUB education_fund;
    RUB sports_section;
    RUB music_school;
    RUB swimming_pool;
    RUB summer_camp;
    RUB tutor;
    RUB school_supplies;
    RUB uniform;
    RUB extracurricular;
};

struct Kredit {
    RUB amount;
    RUB monthly_payment;
    RUB interest_rate;
    int term_months;
    int start_year;
    int start_month;
    bool isActive;
    RUB remaining;
    RUB overpayment;
    RUB early_repayment_fee;
};

struct Mortgage {
    RUB amount;
    RUB down_payment;
    RUB monthly_payment;
    RUB interest_rate;
    int term_years;
    int start_year;
    int start_month;
    bool isActive;
    RUB remaining;
    RUB property_value;
    RUB insurance;
    RUB property_tax;
};

struct Health {
    RUB insurance;
    RUB dentist;
    RUB medications;
    RUB vitamins;
    RUB gym;
    RUB fitness_trainer;
    RUB psychologist;
    RUB massage;
    RUB sanatorium;
    RUB surgery;
    RUB ambulance;
    RUB hospital;
    RUB eye_doctor;
    RUB glasses;
    RUB physiotherapy;
};

struct Education {
    RUB courses;
    RUB books;
    RUB online_subscriptions;
    RUB mentor;
    RUB certificate;
    RUB university;
    RUB language_school;
    RUB webinars;
    RUB master_degree;
    RUB mba;
    RUB conference;
};

struct Entertainment {
    RUB cinema;
    RUB restaurants;
    RUB cafes;
    RUB bars;
    RUB concerts;
    RUB theater;
    RUB gaming;
    RUB streaming;
    RUB hobbies;
    RUB gifts;
    RUB bowling;
    RUB quest_rooms;
    RUB parties;
    RUB shopping;
    RUB cosmetics;
};

struct Charity {
    RUB donations;
    RUB volunteering;
    RUB gifts_for_friends;
    RUB help_parents;
    RUB animal_shelter;
    RUB orphanage;
    RUB environmental;
    RUB church;
    RUB scholarship_fund;
};

struct BlackJob {
    RUB income;
    bool isActive;
    int risk_level;
    RUB fine;
    bool caught;
    RUB bribe;
    int months_active;
};

struct Lottery {
    RUB ticket_cost;
    RUB winnings;
    int tickets_bought;
    int wins_count;
    RUB total_spent;
    RUB total_won;
    RUB biggest_win;
};

struct Inheritance {
    RUB amount;
    RUB property_value;
    int year;
    int month;
    bool isReceived;
    RUB tax;
    RUB notary_fees;
    RUB debt_from_inheritance;
};

struct Divorce {
    RUB lawyer_fees;
    RUB alimony;
    RUB property_division;
    RUB emotional_compensation;
    bool isHappened;
    int year;
    int month;
    RUB child_support;
    RUB moving_costs;
    RUB therapy_costs;
};

struct Dacha {
    RUB purchase;
    RUB maintenance;
    RUB utilities;
    RUB taxes;
    RUB repair;
    RUB security;
    RUB gardening;
    RUB furniture_dacha;
    RUB tools;
    RUB sauna;
    RUB barbecue;
    RUB pool;
};

struct Crypto {
    RUB btc_amount;
    RUB btc_price;
    RUB eth_amount;
    RUB eth_price;
    RUB sol_amount;
    RUB sol_price;
    RUB total_invested;
    RUB current_value;
    RUB profit_loss;
    RUB btc_buy_price;
    RUB eth_buy_price;
    RUB sol_buy_price;
};

struct Stock {
    RUB sber_amount;
    RUB sber_price;
    RUB gazprom_amount;
    RUB gazprom_price;
    RUB yandex_amount;
    RUB yandex_price;
    RUB total_invested;
    RUB current_value;
    RUB dividend_received;
};

struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
    RUB deposit;
    RUB deposit_interest;
    RUB credit_history;
    RUB investments;
    RUB metal_account;
    RUB gold_grams;
    RUB silver_grams;
};

struct Person {
    Bank vtb;
    RUB salary;
    RUB food;
    Car car;
    Flat flat;
    Cat cat;
    Dog dog;
    Hamster hamster;
    Parrot parrot;
    Fish fish;
    Rabbit rabbit;
    Turtle turtle;
    Trip trip;
    Wedding wedding;
    Child child;
    Kredit kredit;
    Mortgage mortgage;
    Health health;
    Education education;
    Entertainment entertainment;
    Charity charity;
    BlackJob black_job;
    Lottery lottery;
    Inheritance inheritance;
    Divorce divorce;
    Dacha dacha;
    Crypto crypto;
    Stock stock;
};
struct Person natalia;

struct Husband {
    RUB salary;
    RUB food;
    Car car;
    bool isPresent;
    RUB alimony;
    RUB child_support;
    RUB personal_expenses;
    RUB savings;
    RUB car_loan;
    RUB car_loan_payment;
};
struct Husband tolik;

struct Grandmother {
    RUB pension;
    RUB food;
    RUB medications;
    RUB utilities;
    RUB help_from_relatives;
    RUB gifts_for_grandchildren;
    bool isAlive;
    int age;
    RUB savings;
    RUB house_value;
    RUB dacha_value;
    RUB car_value;
    RUB jewelry;
};
struct Grandmother zinaida;

struct Grandfather {
    RUB pension;
    RUB savings;
    RUB house_value;
    bool isAlive;
    int death_year;
    int death_month;
    RUB inheritance_left;
};
struct Grandfather ivan;

struct Sister {
    RUB salary;
    RUB help_to_family;
    bool isPresent;
    RUB debt_to_natalia;
    RUB return_payment;
    bool paying_back;
};
struct Sister olga;

struct Friend {
    RUB help_amount;
    int help_month;
    int help_year;
    bool borrowed;
    RUB return_amount;
    bool returned;
};
struct Friend marina;

bool isCatAlive = true;
bool isDogAlive = true;
bool isHamsterAlive = true;
bool isParrotAlive = true;
bool isFishAlive = true;
bool isRabbitAlive = true;
bool isTurtleAlive = true;
bool isMarried = false;
bool isPregnant = false;
bool isChildAlive = false;
bool isDivorced = false;
bool hasDacha = false;
bool isMortgageActive = false;
bool isKreditActive = false;
bool isBlackJobActive = false;
bool isOlgaPaying = false;

void update_crypto_prices(int month, int year)
{
    srand(month * 1000 + year * 10000);
    float btc_change = (float)(rand() % 40 - 15) / 100.0;
    float eth_change = (float)(rand() % 45 - 18) / 100.0;
    float sol_change = (float)(rand() % 55 - 22) / 100.0;
    if (month == 1) btc_change += 0.08;
    if (month == 12) eth_change += 0.10;
    if (month == 6) sol_change -= 0.05;
    if (month == 3 && year == 2027) btc_change += 0.20;
    if (month == 9 && year == 2028) eth_change -= 0.15;
    natalia.crypto.btc_price = natalia.crypto.btc_price * (1.0 + btc_change);
    natalia.crypto.eth_price = natalia.crypto.eth_price * (1.0 + eth_change);
    natalia.crypto.sol_price = natalia.crypto.sol_price * (1.0 + sol_change);
    natalia.crypto.current_value = (natalia.crypto.btc_amount * natalia.crypto.btc_price) +
        (natalia.crypto.eth_amount * natalia.crypto.eth_price) +
        (natalia.crypto.sol_amount * natalia.crypto.sol_price);
    natalia.crypto.profit_loss = natalia.crypto.current_value - natalia.crypto.total_invested;
}

void update_stock_prices(int month, int year)
{
    srand(month * 2000 + year * 5000);
    float sber_change = (float)(rand() % 20 - 8) / 100.0;
    float gazprom_change = (float)(rand() % 25 - 10) / 100.0;
    float yandex_change = (float)(rand() % 30 - 12) / 100.0;
    if (month == 5 && year == 2027) sber_change += 0.15;
    if (month == 10 && year == 2028) gazprom_change -= 0.12;
    natalia.stock.sber_price = natalia.stock.sber_price * (1.0 + sber_change);
    natalia.stock.gazprom_price = natalia.stock.gazprom_price * (1.0 + gazprom_change);
    natalia.stock.yandex_price = natalia.stock.yandex_price * (1.0 + yandex_change);
    natalia.stock.current_value = (natalia.stock.sber_amount * natalia.stock.sber_price) +
        (natalia.stock.gazprom_amount * natalia.stock.gazprom_price) +
        (natalia.stock.yandex_amount * natalia.stock.yandex_price);
    if (month == 12)
    {
        natalia.stock.dividend_received += natalia.stock.sber_amount * 180;
        natalia.stock.dividend_received += natalia.stock.gazprom_amount * 120;
        natalia.stock.dividend_received += natalia.stock.yandex_amount * 50;
        natalia.vtb.account_rub += natalia.stock.dividend_received;
    }
}

void natalia_init()
{
    natalia.vtb.rate_usd_rub = 78.76;
    natalia.vtb.account_rub = 50000;
    natalia.vtb.account_usd = 1000;
    natalia.vtb.deposit = 0;
    natalia.vtb.deposit_interest = 7.0;
    natalia.vtb.credit_history = 700;
    natalia.vtb.investments = 0;
    natalia.vtb.metal_account = 0;
    natalia.vtb.gold_grams = 0;
    natalia.vtb.silver_grams = 0;
    natalia.salary = 180000;
    natalia.food = 3000;
    natalia.car.value = 2400000;
    natalia.car.gas = 15000;
    natalia.car.OSAGO = 5000;
    natalia.car.STO = 10000;
    natalia.car.tires = 15000;
    natalia.car.washing = 500;
    natalia.car.parking_space = 12000;
    natalia.car.CASCO = 40000;
    natalia.car.antifreeze = 1500;
    natalia.car.brake_pads = 8000;
    natalia.car.insurance = 5000;
    natalia.car.fine = 0;
    natalia.car.wash_parking = 2000;
    natalia.car.tax = 6000;
    natalia.flat.rent = 45000;
    natalia.flat.household_supplies = 2000;
    natalia.flat.housing_and_communal_services = 8000;
    natalia.flat.furniture = 10000;
    natalia.flat.cleaning = 15000;
    natalia.flat.repair = 5000;
    natalia.flat.deposit = 45000;
    natalia.flat.realtors_commission = 30000;
    natalia.flat.electricity = 3000;
    natalia.flat.internet = 800;
    natalia.flat.water = 1200;
    natalia.flat.gas = 500;
    natalia.flat.security = 1500;
    natalia.flat.air_conditioner = 30000;
    natalia.flat.heating = 4000;
    natalia.flat.garbage = 500;
    natalia.flat.renovation = 20000;
    natalia.cat.purchase = 5000;
    natalia.cat.cat_food = 3000;
    natalia.cat.cat_litter = 500;
    natalia.cat.toys = 2000;
    natalia.cat.tray = 1000;
    natalia.cat.little_house = 1500;
    natalia.cat.scratching_post = 5000;
    natalia.cat.grooming = 2000;
    natalia.cat.veterinarian = 2000;
    natalia.cat.vitamins = 2000;
    natalia.cat.treats = 500;
    natalia.cat.carrier = 2500;
    natalia.cat.antiparasitic = 1000;
    natalia.cat.cat_tree = 8000;
    natalia.cat.nail_clipper = 300;
    natalia.cat.brush = 400;
    natalia.cat.collar = 500;
    natalia.dog.purchase = 30000;
    natalia.dog.dog_food = 5000;
    natalia.dog.toys = 1500;
    natalia.dog.bowl = 1000;
    natalia.dog.bed = 3000;
    natalia.dog.collar_and_leash = 3500;
    natalia.dog.grooming = 5000;
    natalia.dog.veterinarian = 3000;
    natalia.dog.vaccines = 4000;
    natalia.dog.vitamins = 1000;
    natalia.dog.treats = 1500;
    natalia.dog.training = 5000;
    natalia.dog.kennel = 10000;
    natalia.dog.leash = 1500;
    natalia.dog.muzzle = 800;
    natalia.dog.dog_sitter = 3000;
    natalia.dog.dog_clothes = 2000;
    natalia.dog.shampoo = 600;
    natalia.dog.brush = 500;
    natalia.hamster.purchase = 1500;
    natalia.hamster.cage = 4000;
    natalia.hamster.bedding = 500;
    natalia.hamster.food = 500;
    natalia.hamster.treats = 300;
    natalia.hamster.toys = 500;
    natalia.hamster.water_bottle = 400;
    natalia.hamster.bowl = 200;
    natalia.hamster.veterinarian = 1500;
    natalia.hamster.vitamins = 300;
    natalia.hamster.exercise_ball = 600;
    natalia.hamster.sawdust = 400;
    natalia.hamster.hay = 300;
    natalia.hamster.transport_cage = 1000;
    natalia.hamster.wheel = 800;
    natalia.hamster.house = 1200;
    natalia.hamster.mineral_stone = 200;
    natalia.hamster.sand_bath = 300;
    natalia.hamster.tunnel = 400;
    natalia.parrot.purchase = 15000;
    natalia.parrot.cage = 8000;
    natalia.parrot.food = 1500;
    natalia.parrot.treats = 800;
    natalia.parrot.toys = 1000;
    natalia.parrot.perches = 1200;
    natalia.parrot.veterinarian = 2500;
    natalia.parrot.vitamins = 600;
    natalia.parrot.carrier = 1800;
    natalia.parrot.cage_cleaner = 400;
    natalia.parrot.cuttlebone = 300;
    natalia.parrot.mirror = 500;
    natalia.parrot.swing = 700;
    natalia.parrot.ladder = 400;
    natalia.parrot.bell = 300;
    natalia.fish.purchase = 3000;
    natalia.fish.aquarium = 12000;
    natalia.fish.filter = 3500;
    natalia.fish.heater = 2000;
    natalia.fish.lighting = 2500;
    natalia.fish.decorations = 4000;
    natalia.fish.fish_food = 500;
    natalia.fish.water_treatment = 600;
    natalia.fish.veterinarian = 1500;
    natalia.fish.plants = 2000;
    natalia.fish.gravel = 1200;
    natalia.fish.air_pump = 1800;
    natalia.fish.net = 300;
    natalia.fish.thermometer = 400;
    natalia.fish.background = 800;
    natalia.rabbit.purchase = 3000;
    natalia.rabbit.cage = 6000;
    natalia.rabbit.food = 800;
    natalia.rabbit.hay = 500;
    natalia.rabbit.treats = 400;
    natalia.rabbit.toys = 600;
    natalia.rabbit.bedding = 400;
    natalia.rabbit.water_bottle = 300;
    natalia.rabbit.bowl = 200;
    natalia.rabbit.veterinarian = 2000;
    natalia.rabbit.vitamins = 400;
    natalia.rabbit.carrier = 1200;
    natalia.rabbit.brush = 300;
    natalia.rabbit.nail_clipper = 250;
    natalia.turtle.purchase = 2500;
    natalia.turtle.terrarium = 8000;
    natalia.turtle.food = 400;
    natalia.turtle.vitamins = 300;
    natalia.turtle.heater = 2000;
    natalia.turtle.lighting = 1800;
    natalia.turtle.filter = 2500;
    natalia.turtle.decorations = 1500;
    natalia.turtle.veterinarian = 1800;
    natalia.turtle.substrate = 600;
    natalia.turtle.water_conditioner = 400;
    natalia.trip.flight_tickets = 85000;
    natalia.trip.hotel = 150000;
    natalia.trip.meals = 38000;
    natalia.trip.excursions = 30000;
    natalia.trip.transport = 30000;
    natalia.trip.insurance = 5000;
    natalia.trip.visa = 8000;
    natalia.trip.souvenirs = 20000;
    natalia.trip.luggage = 7000;
    natalia.trip.entertainment = 45000;
    natalia.trip.guide_services = 15000;
    natalia.trip.travel_agency = 5000;
    natalia.trip.visa_center = 3000;
    natalia.trip.taxi = 5000;
    natalia.trip.tips = 4000;
    natalia.wedding.dress = 80000;
    natalia.wedding.suit = 50000;
    natalia.wedding.venue = 150000;
    natalia.wedding.catering = 100000;
    natalia.wedding.photographer = 60000;
    natalia.wedding.videographer = 50000;
    natalia.wedding.music = 40000;
    natalia.wedding.flowers = 30000;
    natalia.wedding.invitations = 5000;
    natalia.wedding.cake = 15000;
    natalia.wedding.rings = 40000;
    natalia.wedding.honeymoon = 200000;
    natalia.wedding.registrar = 3000;
    natalia.wedding.transport = 20000;
    natalia.wedding.gifts_for_guests = 15000;
    natalia.wedding.makeup_artist = 10000;
    natalia.wedding.hair_stylist = 8000;
    natalia.wedding.limousine = 25000;
    natalia.wedding.fireworks = 20000;
    natalia.wedding.rehearsal_dinner = 30000;
    natalia.wedding.wedding_planner = 40000;
    natalia.wedding.photo_album = 8000;
    natalia.child.prenatal_vitamins = 5000;
    natalia.child.doctor_visits = 3000;
    natalia.child.ultrasound = 5500;
    natalia.child.maternity_clothes = 20000;
    natalia.child.childbirth = 80000;
    natalia.child.stroller = 40000;
    natalia.child.crib = 30000;
    natalia.child.mattress = 7000;
    natalia.child.bedding = 4000;
    natalia.child.changing_table = 8000;
    natalia.child.baby_bath = 2000;
    natalia.child.baby_monitor = 5000;
    natalia.child.diapers = 5000;
    natalia.child.baby_wipes = 1500;
    natalia.child.baby_clothes = 5000;
    natalia.child.baby_food = 6000;
    natalia.child.bottles = 3000;
    natalia.child.pacifiers = 1500;
    natalia.child.sterilizer = 4000;
    natalia.child.bottle_warmer = 2500;
    natalia.child.car_seat = 15000;
    natalia.child.high_chair = 8000;
    natalia.child.playpen = 6000;
    natalia.child.toys = 3000;
    natalia.child.books = 1500;
    natalia.child.vaccinations = 5000;
    natalia.child.pediatrician = 2500;
    natalia.child.medications = 5000;
    natalia.child.nanny = 30000;
    natalia.child.nursery = 25000;
    natalia.child.kindergarten = 35000;
    natalia.child.school = 50000;
    natalia.child.education_fund = 10000;
    natalia.child.sports_section = 8000;
    natalia.child.music_school = 7000;
    natalia.child.swimming_pool = 4000;
    natalia.child.summer_camp = 30000;
    natalia.child.tutor = 15000;
    natalia.child.school_supplies = 5000;
    natalia.child.uniform = 4000;
    natalia.child.extracurricular = 6000;
    natalia.kredit.amount = 300000;
    natalia.kredit.monthly_payment = 15000;
    natalia.kredit.interest_rate = 18.0;
    natalia.kredit.term_months = 24;
    natalia.kredit.start_year = 2026;
    natalia.kredit.start_month = 4;
    natalia.kredit.isActive = false;
    natalia.kredit.remaining = 0;
    natalia.kredit.overpayment = 0;
    natalia.kredit.early_repayment_fee = 5000;
    natalia.mortgage.amount = 6000000;
    natalia.mortgage.down_payment = 1200000;
    natalia.mortgage.monthly_payment = 45000;
    natalia.mortgage.interest_rate = 9.5;
    natalia.mortgage.term_years = 20;
    natalia.mortgage.start_year = 2026;
    natalia.mortgage.start_month = 6;
    natalia.mortgage.isActive = false;
    natalia.mortgage.remaining = 0;
    natalia.mortgage.property_value = 8000000;
    natalia.mortgage.insurance = 15000;
    natalia.mortgage.property_tax = 12000;
    natalia.health.insurance = 8000;
    natalia.health.dentist = 5000;
    natalia.health.medications = 3000;
    natalia.health.vitamins = 2000;
    natalia.health.gym = 4000;
    natalia.health.fitness_trainer = 8000;
    natalia.health.psychologist = 5000;
    natalia.health.massage = 3500;
    natalia.health.sanatorium = 50000;
    natalia.health.surgery = 150000;
    natalia.health.ambulance = 3000;
    natalia.health.hospital = 20000;
    natalia.health.eye_doctor = 3000;
    natalia.health.glasses = 8000;
    natalia.health.physiotherapy = 4000;
    natalia.education.courses = 20000;
    natalia.education.books = 5000;
    natalia.education.online_subscriptions = 3000;
    natalia.education.mentor = 15000;
    natalia.education.certificate = 10000;
    natalia.education.university = 300000;
    natalia.education.language_school = 25000;
    natalia.education.webinars = 5000;
    natalia.education.master_degree = 400000;
    natalia.education.mba = 800000;
    natalia.education.conference = 20000;
    natalia.entertainment.cinema = 1500;
    natalia.entertainment.restaurants = 5000;
    natalia.entertainment.cafes = 3000;
    natalia.entertainment.bars = 4000;
    natalia.entertainment.concerts = 7000;
    natalia.entertainment.theater = 4000;
    natalia.entertainment.gaming = 3000;
    natalia.entertainment.streaming = 1000;
    natalia.entertainment.hobbies = 5000;
    natalia.entertainment.gifts = 6000;
    natalia.entertainment.bowling = 2000;
    natalia.entertainment.quest_rooms = 3000;
    natalia.entertainment.parties = 8000;
    natalia.entertainment.shopping = 10000;
    natalia.entertainment.cosmetics = 4000;
    natalia.charity.donations = 2000;
    natalia.charity.volunteering = 1000;
    natalia.charity.gifts_for_friends = 5000;
    natalia.charity.help_parents = 10000;
    natalia.charity.animal_shelter = 1500;
    natalia.charity.orphanage = 3000;
    natalia.charity.environmental = 1000;
    natalia.charity.church = 500;
    natalia.charity.scholarship_fund = 5000;
    natalia.black_job.income = 30000;
    natalia.black_job.isActive = false;
    natalia.black_job.risk_level = 3;
    natalia.black_job.fine = 50000;
    natalia.black_job.caught = false;
    natalia.black_job.bribe = 20000;
    natalia.black_job.months_active = 0;
    natalia.lottery.ticket_cost = 200;
    natalia.lottery.winnings = 0;
    natalia.lottery.tickets_bought = 0;
    natalia.lottery.wins_count = 0;
    natalia.lottery.total_spent = 0;
    natalia.lottery.total_won = 0;
    natalia.lottery.biggest_win = 0;
    natalia.inheritance.amount = 500000;
    natalia.inheritance.property_value = 2000000;
    natalia.inheritance.year = 2027;
    natalia.inheritance.month = 3;
    natalia.inheritance.isReceived = false;
    natalia.inheritance.tax = 65000;
    natalia.inheritance.notary_fees = 15000;
    natalia.inheritance.debt_from_inheritance = 0;
    natalia.divorce.lawyer_fees = 100000;
    natalia.divorce.alimony = 30000;
    natalia.divorce.property_division = 500000;
    natalia.divorce.emotional_compensation = 200000;
    natalia.divorce.isHappened = false;
    natalia.divorce.year = 2028;
    natalia.divorce.month = 9;
    natalia.divorce.child_support = 20000;
    natalia.divorce.moving_costs = 50000;
    natalia.divorce.therapy_costs = 30000;
    natalia.dacha.purchase = 1500000;
    natalia.dacha.maintenance = 20000;
    natalia.dacha.utilities = 5000;
    natalia.dacha.taxes = 8000;
    natalia.dacha.repair = 30000;
    natalia.dacha.security = 4000;
    natalia.dacha.gardening = 3000;
    natalia.dacha.furniture_dacha = 50000;
    natalia.dacha.tools = 15000;
    natalia.dacha.sauna = 100000;
    natalia.dacha.barbecue = 15000;
    natalia.dacha.pool = 200000;
    natalia.crypto.btc_amount = 0.015;
    natalia.crypto.btc_price = 5000000;
    natalia.crypto.eth_amount = 0.5;
    natalia.crypto.eth_price = 250000;
    natalia.crypto.sol_amount = 15;
    natalia.crypto.sol_price = 8000;
    natalia.crypto.total_invested = (0.015 * 5000000) + (0.5 * 250000) + (15 * 8000);
    natalia.crypto.current_value = natalia.crypto.total_invested;
    natalia.crypto.profit_loss = 0;
    natalia.crypto.btc_buy_price = 5000000;
    natalia.crypto.eth_buy_price = 250000;
    natalia.crypto.sol_buy_price = 8000;
    natalia.stock.sber_amount = 100;
    natalia.stock.sber_price = 280;
    natalia.stock.gazprom_amount = 200;
    natalia.stock.gazprom_price = 160;
    natalia.stock.yandex_amount = 50;
    natalia.stock.yandex_price = 4000;
    natalia.stock.total_invested = (100 * 280) + (200 * 160) + (50 * 4000);
    natalia.stock.current_value = natalia.stock.total_invested;
    natalia.stock.dividend_received = 0;
    tolik.salary = 400000;
    tolik.food = 5000;
    tolik.car.value = 2800000;
    tolik.car.gas = 15000;
    tolik.car.OSAGO = 5000;
    tolik.car.STO = 10000;
    tolik.car.tires = 15000;
    tolik.car.washing = 500;
    tolik.car.parking_space = 12000;
    tolik.car.CASCO = 45000;
    tolik.car.antifreeze = 1500;
    tolik.car.brake_pads = 8000;
    tolik.car.insurance = 6000;
    tolik.car.fine = 0;
    tolik.car.wash_parking = 2000;
    tolik.car.tax = 7000;
    tolik.alimony = 0;
    tolik.child_support = 20000;
    tolik.personal_expenses = 15000;
    tolik.savings = 100000;
    tolik.car_loan = 0;
    tolik.car_loan_payment = 0;
    zinaida.pension = 25000;
    zinaida.food = 8000;
    zinaida.medications = 5000;
    zinaida.utilities = 4000;
    zinaida.help_from_relatives = 10000;
    zinaida.gifts_for_grandchildren = 3000;
    zinaida.isAlive = true;
    zinaida.age = 72;
    zinaida.savings = 300000;
    zinaida.house_value = 3500000;
    zinaida.dacha_value = 800000;
    zinaida.car_value = 400000;
    zinaida.jewelry = 150000;
    ivan.pension = 28000;
    ivan.savings = 200000;
    ivan.house_value = 2800000;
    ivan.isAlive = true;
    ivan.death_year = 2027;
    ivan.death_month = 5;
    ivan.inheritance_left = 2500000;
    olga.salary = 60000;
    olga.help_to_family = 5000;
    olga.isPresent = true;
    olga.debt_to_natalia = 50000;
    olga.return_payment = 5000;
    olga.paying_back = true;
    marina.help_amount = 30000;
    marina.help_month = 11;
    marina.help_year = 2026;
    marina.borrowed = false;
    marina.return_amount = 0;
    marina.returned = false;
}

void natalia_food(int month, int year)
{
    if (month == 12) natalia.vtb.account_rub -= 2000;
    Percent inflation = 12.0;
    if (year == 2026) inflation = 12.5;
    else if (year == 2027) inflation = 14.0;
    else if (year == 2028) inflation = 13.0;
    natalia.food += natalia.food * (inflation / 100.0 / 12.0);
    natalia.vtb.account_rub -= natalia.food;
}

void natalia_car_expenses(int month, int year)
{
    if (month == 10 && year == 2026) natalia.vtb.account_rub -= natalia.car.tires;
    natalia.vtb.account_rub -= natalia.car.gas;
    natalia.vtb.account_rub -= natalia.car.parking_space;
    if (month % 2 == 0) natalia.vtb.account_rub -= natalia.car.washing;
    if (month == 12 && year == 2026)
    {
        natalia.vtb.account_rub -= natalia.car.OSAGO;
        natalia.vtb.account_rub -= natalia.car.STO;
        natalia.vtb.account_rub -= natalia.car.CASCO;
        natalia.vtb.account_rub -= natalia.car.tax;
    }
    if (month == 6 && year == 2027) natalia.vtb.account_rub -= natalia.car.brake_pads;
    if (month == 3 && year == 2027) natalia.vtb.account_rub -= natalia.car.antifreeze;
    if (rand() % 100 < 8)
    {
        RUB fine_amount = 500 + rand() % 3000;
        natalia.vtb.account_rub -= fine_amount;
        natalia.car.fine += fine_amount;
    }
    Percent inflation_gas = 5.0;
    Percent inflation_service = 6.0;
    natalia.car.gas += natalia.car.gas * (inflation_gas / 100.0 / 5.0);
    natalia.car.STO += natalia.car.STO * (inflation_service / 100.0 / 6.0);
}

void natalia_flat_expenses(int month, int year)
{
    natalia.vtb.account_rub -= natalia.flat.rent;
    natalia.vtb.account_rub -= natalia.flat.housing_and_communal_services;
    natalia.vtb.account_rub -= natalia.flat.electricity;
    natalia.vtb.account_rub -= natalia.flat.internet;
    natalia.vtb.account_rub -= natalia.flat.water;
    natalia.vtb.account_rub -= natalia.flat.gas;
    natalia.vtb.account_rub -= natalia.flat.heating;
    natalia.vtb.account_rub -= natalia.flat.garbage;
    if (month % 6 == 0) natalia.vtb.account_rub -= natalia.flat.household_supplies;
    if (month == 12) natalia.vtb.account_rub -= natalia.flat.repair;
    if (month == 5 || month == 10) natalia.vtb.account_rub -= natalia.flat.cleaning;
    if (month == 1 && year == 2026)
    {
        natalia.vtb.account_rub -= natalia.flat.deposit;
        natalia.vtb.account_rub -= natalia.flat.realtors_commission;
    }
    if (month == 8 && year == 2027) natalia.vtb.account_rub -= natalia.flat.renovation;
    Percent inflation_rent = 8.0;
    Percent inflation_communal = 7.0;
    natalia.flat.rent += natalia.flat.rent * (inflation_rent / 100.0 / 8.0);
    natalia.flat.housing_and_communal_services += natalia.flat.housing_and_communal_services * (inflation_communal / 100.0 / 7.0);
}

void natalia_cat_expenses(int month, int year)
{
    if (isCatAlive)
    {
        if (month == 2 && year == 2026)
        {
            natalia.vtb.account_rub -= natalia.cat.purchase;
            natalia.vtb.account_rub -= natalia.cat.tray;
            natalia.vtb.account_rub -= natalia.cat.carrier;
            natalia.vtb.account_rub -= natalia.cat.cat_tree;
        }
        if (month % 2 == 0)
        {
            natalia.vtb.account_rub -= natalia.cat.cat_food;
            natalia.vtb.account_rub -= natalia.cat.cat_litter;
        }
        if (month % 4 == 0)
        {
            natalia.vtb.account_rub -= natalia.cat.grooming;
            natalia.vtb.account_rub -= natalia.cat.veterinarian;
            natalia.vtb.account_rub -= natalia.cat.antiparasitic;
        }
        if (month == 12 && year == 2026) natalia.vtb.account_rub -= natalia.cat.vitamins;
        if (month == 6 && year == 2027) natalia.vtb.account_rub -= natalia.cat.brush;
        Percent inflation_cat = 7.0;
        natalia.cat.cat_food += natalia.cat.cat_food * (inflation_cat / 100.0 / 7.0);
    }
}

void natalia_dog_expenses(int month, int year)
{
    if (isDogAlive)
    {
        if (month == 3 && year == 2026)
        {
            natalia.vtb.account_rub -= natalia.dog.purchase;
            natalia.vtb.account_rub -= natalia.dog.bed;
            natalia.vtb.account_rub -= natalia.dog.kennel;
            natalia.vtb.account_rub -= natalia.dog.leash;
        }
        if (month % 2 == 0) natalia.vtb.account_rub -= natalia.dog.dog_food;
        if (month % 4 == 0)
        {
            natalia.vtb.account_rub -= natalia.dog.vitamins;
            natalia.vtb.account_rub -= natalia.dog.veterinarian;
        }
        if (month == 5 || month == 11) natalia.vtb.account_rub -= natalia.dog.grooming;
        if (month == 8 && year == 2026) natalia.vtb.account_rub -= natalia.dog.training;
        if (month == 9 && year == 2027) natalia.vtb.account_rub -= natalia.dog.vaccines;
        if (month == 10 && year == 2027) natalia.vtb.account_rub -= natalia.dog.dog_clothes;
        Percent inflation_dog = 8.0;
        natalia.dog.dog_food += natalia.dog.dog_food * (inflation_dog / 100.0 / 8.0);
    }
}

void natalia_hamster_expenses(int month, int year)
{
    if (isHamsterAlive)
    {
        if (month == 4 && year == 2026)
        {
            natalia.vtb.account_rub -= natalia.hamster.purchase;
            natalia.vtb.account_rub -= natalia.hamster.cage;
            natalia.vtb.account_rub -= natalia.hamster.wheel;
            natalia.vtb.account_rub -= natalia.hamster.house;
        }
        natalia.vtb.account_rub -= natalia.hamster.sawdust;
        natalia.vtb.account_rub -= natalia.hamster.hay;
        if (month % 2 == 0)
        {
            natalia.vtb.account_rub -= natalia.hamster.food;
            natalia.vtb.account_rub -= natalia.hamster.treats;
        }
        if (month % 3 == 0) natalia.vtb.account_rub -= natalia.hamster.bedding;
        if (month == 4 && year == 2027) natalia.vtb.account_rub -= natalia.hamster.veterinarian;
        if (month == 8 && year == 2027) natalia.vtb.account_rub -= natalia.hamster.sand_bath;
        Percent inflation_hamster = 6.0;
        natalia.hamster.food += natalia.hamster.food * (inflation_hamster / 100.0 / 6.0);
    }
}

void natalia_parrot_expenses(int month, int year)
{
    if (isParrotAlive)
    {
        if (month == 5 && year == 2026)
        {
            natalia.vtb.account_rub -= natalia.parrot.purchase;
            natalia.vtb.account_rub -= natalia.parrot.cage;
            natalia.vtb.account_rub -= natalia.parrot.perches;
            natalia.vtb.account_rub -= natalia.parrot.swing;
        }
        if (month % 2 == 0) natalia.vtb.account_rub -= natalia.parrot.food;
        if (month % 3 == 0) natalia.vtb.account_rub -= natalia.parrot.treats;
        if (month == 6 || month == 12) natalia.vtb.account_rub -= natalia.parrot.veterinarian;
        if (month == 9 && year == 2026) natalia.vtb.account_rub -= natalia.parrot.vitamins;
        if (month == 3 && year == 2027) natalia.vtb.account_rub -= natalia.parrot.ladder;
        Percent inflation_parrot = 7.0;
        natalia.parrot.food += natalia.parrot.food * (inflation_parrot / 100.0 / 7.0);
    }
}

void natalia_fish_expenses(int month, int year)
{
    if (isFishAlive)
    {
        if (month == 6 && year == 2026)
        {
            natalia.vtb.account_rub -= natalia.fish.aquarium;
            natalia.vtb.account_rub -= natalia.fish.filter;
            natalia.vtb.account_rub -= natalia.fish.heater;
            natalia.vtb.account_rub -= natalia.fish.lighting;
            natalia.vtb.account_rub -= natalia.fish.purchase;
        }
        if (month % 2 == 0) natalia.vtb.account_rub -= natalia.fish.fish_food;
        if (month % 6 == 0) natalia.vtb.account_rub -= natalia.fish.water_treatment;
        if (month == 12 && year == 2026) natalia.vtb.account_rub -= natalia.fish.decorations;
        if (month == 9 && year == 2027) natalia.vtb.account_rub -= natalia.fish.air_pump;
        Percent inflation_fish = 5.0;
        natalia.fish.fish_food += natalia.fish.fish_food * (inflation_fish / 100.0 / 5.0);
    }
}

void natalia_rabbit_expenses(int month, int year)
{
    if (isRabbitAlive)
    {
        if (month == 7 && year == 2026)
        {
            natalia.vtb.account_rub -= natalia.rabbit.purchase;
            natalia.vtb.account_rub -= natalia.rabbit.cage;
            natalia.vtb.account_rub -= natalia.rabbit.water_bottle;
        }
        if (month % 2 == 0)
        {
            natalia.vtb.account_rub -= natalia.rabbit.food;
            natalia.vtb.account_rub -= natalia.rabbit.hay;
        }
        if (month % 3 == 0) natalia.vtb.account_rub -= natalia.rabbit.treats;
        if (month == 7 && year == 2027) natalia.vtb.account_rub -= natalia.rabbit.veterinarian;
        Percent inflation_rabbit = 6.0;
        natalia.rabbit.food += natalia.rabbit.food * (inflation_rabbit / 100.0 / 6.0);
    }
}

void natalia_turtle_expenses(int month, int year)
{
    if (isTurtleAlive)
    {
        if (month == 8 && year == 2026)
        {
            natalia.vtb.account_rub -= natalia.turtle.purchase;
            natalia.vtb.account_rub -= natalia.turtle.terrarium;
            natalia.vtb.account_rub -= natalia.turtle.heater;
        }
        if (month % 2 == 0) natalia.vtb.account_rub -= natalia.turtle.food;
        if (month % 4 == 0) natalia.vtb.account_rub -= natalia.turtle.vitamins;
        if (month == 8 && year == 2027) natalia.vtb.account_rub -= natalia.turtle.veterinarian;
        Percent inflation_turtle = 5.0;
        natalia.turtle.food += natalia.turtle.food * (inflation_turtle / 100.0 / 5.0);
    }
}

void natalia_trip_expenses(int month, int year)
{
    if (month == 5 && year == 2026)
    {
        natalia.vtb.account_rub -= natalia.trip.flight_tickets;
        natalia.vtb.account_rub -= natalia.trip.hotel;
        natalia.vtb.account_rub -= natalia.trip.meals;
        natalia.vtb.account_rub -= natalia.trip.excursions;
        natalia.vtb.account_rub -= natalia.trip.guide_services;
    }
    if (month == 1 && year == 2027)
    {
        natalia.vtb.account_rub -= natalia.trip.flight_tickets;
        natalia.vtb.account_rub -= natalia.trip.hotel;
        natalia.vtb.account_rub -= natalia.trip.souvenirs;
        natalia.vtb.account_rub -= natalia.trip.entertainment;
        natalia.vtb.account_rub -= natalia.trip.taxi;
    }
    if (month == 8 && year == 2027)
    {
        natalia.vtb.account_rub -= natalia.trip.flight_tickets * 0.6;
        natalia.vtb.account_rub -= natalia.trip.hotel * 0.7;
        natalia.vtb.account_rub -= natalia.trip.meals;
        natalia.vtb.account_rub -= natalia.trip.tips;
    }
    if (month == 2 && year == 2028)
    {
        natalia.vtb.account_rub -= natalia.trip.flight_tickets * 0.8;
        natalia.vtb.account_rub -= natalia.trip.visa;
        natalia.vtb.account_rub -= natalia.trip.visa_center;
    }
    Percent inflation_trip = 10.0;
    natalia.trip.flight_tickets += natalia.trip.flight_tickets * (inflation_trip / 100.0 / 10.0);
    natalia.trip.hotel += natalia.trip.hotel * (inflation_trip / 100.0 / 10.0);
    natalia.trip.meals += natalia.trip.meals * (inflation_trip / 100.0 / 10.0);
}

void natalia_salary(int month, int year)
{
    natalia.vtb.account_rub += natalia.salary;
    if (month == 3) natalia.salary = natalia.salary * 1.5;
    if (month == 2 && year == 2026) natalia.vtb.account_rub += 5000;
    if (month == 12 && year == 2026) natalia.vtb.account_rub += 15000;
    if (month == 12 && year == 2027) natalia.vtb.account_rub += 25000;
}

void natalia_wedding(int month, int year)
{
    if (month == 8 && year == 2026 && !isMarried)
    {
        isMarried = true;
        tolik.isPresent = true;
        RUB wedding_total = 0;
        wedding_total += natalia.wedding.dress;
        wedding_total += natalia.wedding.suit;
        wedding_total += natalia.wedding.venue;
        wedding_total += natalia.wedding.catering;
        wedding_total += natalia.wedding.photographer;
        wedding_total += natalia.wedding.music;
        wedding_total += natalia.wedding.flowers;
        wedding_total += natalia.wedding.cake;
        wedding_total += natalia.wedding.rings;
        wedding_total += natalia.wedding.limousine;
        wedding_total += natalia.wedding.fireworks;
        wedding_total += natalia.wedding.wedding_planner;
        RUB natalia_share = wedding_total / 2;
        natalia.vtb.account_rub -= natalia_share;
        natalia.vtb.account_rub -= natalia.wedding.honeymoon;
        natalia.vtb.account_rub -= natalia.wedding.makeup_artist;
        natalia.vtb.account_rub -= natalia.wedding.hair_stylist;
        natalia.vtb.account_rub -= natalia.wedding.rehearsal_dinner;
    }
}

void tolik_income_and_expenses(int month, int year)
{
    if (tolik.isPresent && !isDivorced)
    {
        natalia.vtb.account_rub += tolik.salary;
        natalia.vtb.account_rub -= tolik.food;
        natalia.vtb.account_rub -= tolik.car.gas;
        natalia.vtb.account_rub -= tolik.personal_expenses;
        if (month % 2 == 0) natalia.vtb.account_rub -= tolik.car.washing;
        if (month == 11 && year == 2026) natalia.vtb.account_rub -= tolik.car.tires;
        if (month == 12 && year == 2026)
        {
            natalia.vtb.account_rub -= tolik.car.OSAGO;
            natalia.vtb.account_rub -= tolik.car.STO;
            natalia.vtb.account_rub -= tolik.car.tax;
        }
        if (month == 3 && year == 2027) tolik.salary = tolik.salary * 1.1;
        if (month == 12 && year == 2027) natalia.vtb.account_rub += tolik.salary * 0.5;
    }
    if (isDivorced && tolik.isPresent)
    {
        natalia.vtb.account_rub += tolik.alimony;
        natalia.vtb.account_rub += tolik.child_support;
    }
}

void natalia_pregnancy(int month, int year)
{
    if (isMarried && !isPregnant && !isChildAlive)
    {
        if (month == 10 && year == 2026)
        {
            isPregnant = true;
            natalia.child.birth_month = 7;
            natalia.child.birth_year = 2027;
        }
    }
    if (isPregnant)
    {
        if (month == 10 && year == 2026) natalia.vtb.account_rub -= natalia.child.prenatal_vitamins;
        if (month == 11 && year == 2026)
        {
            natalia.vtb.account_rub -= natalia.child.doctor_visits;
            natalia.vtb.account_rub -= natalia.child.ultrasound;
        }
        if (month == 12 && year == 2026) natalia.vtb.account_rub -= natalia.child.maternity_clothes;
        if (month == 1 && year == 2027) natalia.vtb.account_rub -= natalia.child.doctor_visits;
        if (month == 2 && year == 2027) natalia.vtb.account_rub -= natalia.child.prenatal_vitamins;
        if (month == 3 && year == 2027) natalia.vtb.account_rub -= natalia.child.ultrasound;
        if (month == 4 && year == 2027) natalia.vtb.account_rub -= natalia.child.doctor_visits;
        if (month == 5 && year == 2027)
        {
            natalia.vtb.account_rub -= natalia.child.stroller;
            natalia.vtb.account_rub -= natalia.child.crib;
            natalia.vtb.account_rub -= natalia.child.car_seat;
            natalia.vtb.account_rub -= natalia.child.baby_monitor;
            natalia.vtb.account_rub -= natalia.child.changing_table;
        }
        if (month == 6 && year == 2027) natalia.vtb.account_rub -= natalia.child.doctor_visits;
    }
}

void natalia_childbirth(int month, int year)
{
    if (isPregnant && month == 7 && year == 2027)
    {
        isPregnant = false;
        isChildAlive = true;
        natalia.child.isBorn = true;
        natalia.vtb.account_rub -= natalia.child.childbirth;
        natalia.salary = natalia.salary * 0.4;
    }
}

void natalia_child_expenses(int month, int year)
{
    if (isChildAlive)
    {
        natalia.vtb.account_rub -= natalia.child.diapers;
        natalia.vtb.account_rub -= natalia.child.baby_wipes;
        natalia.vtb.account_rub -= natalia.child.baby_food;
        natalia.vtb.account_rub -= natalia.child.toys;
        if (month == 8 && year == 2027) natalia.vtb.account_rub -= natalia.child.vaccinations;
        if (month == 9 && year == 2027)
        {
            natalia.salary = 200000;
            natalia.vtb.account_rub -= natalia.child.nursery;
        }
        if (month >= 10 && year == 2027) natalia.vtb.account_rub -= natalia.child.nursery;
        if (year == 2028)
        {
            if (month == 1) natalia.vtb.account_rub -= natalia.child.kindergarten;
            if (month == 3) natalia.vtb.account_rub -= natalia.child.vaccinations;
            if (month == 9) natalia.vtb.account_rub -= natalia.child.sports_section;
            if (month == 12) natalia.vtb.account_rub -= natalia.child.school_supplies;
        }
        if (year == 2029 && month == 9)
        {
            natalia.vtb.account_rub -= natalia.child.school;
            natalia.vtb.account_rub -= natalia.child.education_fund;
            natalia.vtb.account_rub -= natalia.child.uniform;
        }
        if (year == 2028 && month == 6) natalia.vtb.account_rub -= natalia.child.swimming_pool;
        if (year == 2028 && month == 7) natalia.vtb.account_rub -= natalia.child.summer_camp;
    }
}

void natalia_kredit_expenses(int month, int year)
{
    if (natalia.kredit.isActive)
    {
        natalia.vtb.account_rub -= natalia.kredit.monthly_payment;
        natalia.kredit.remaining -= natalia.kredit.monthly_payment;
        natalia.kredit.overpayment += natalia.kredit.monthly_payment * (natalia.kredit.interest_rate / 100.0 / 12.0);
        if (natalia.kredit.remaining <= 0)
        {
            natalia.kredit.isActive = false;
            printf("Kredit paid off in %d/%d\n", month, year);
        }
    }
    if (month == 4 && year == 2026 && !natalia.kredit.isActive && !isMarried)
    {
        natalia.kredit.isActive = true;
        natalia.kredit.remaining = natalia.kredit.amount;
        printf("Kredit taken in %d/%d\n", month, year);
    }
    if (month == 4 && year == 2027 && natalia.kredit.isActive && natalia.vtb.account_rub > 200000)
    {
        RUB early = natalia.kredit.remaining;
        natalia.vtb.account_rub -= early;
        natalia.vtb.account_rub -= natalia.kredit.early_repayment_fee;
        natalia.kredit.remaining = 0;
        natalia.kredit.isActive = false;
        printf("Kredit early repayment in %d/%d\n", month, year);
    }
}

void natalia_mortgage_expenses(int month, int year)
{
    if (natalia.mortgage.isActive)
    {
        natalia.vtb.account_rub -= natalia.mortgage.monthly_payment;
        natalia.mortgage.remaining -= natalia.mortgage.monthly_payment;
        if (month == 12)
        {
            natalia.vtb.account_rub -= natalia.mortgage.insurance;
            natalia.vtb.account_rub -= natalia.mortgage.property_tax;
        }
        if (natalia.mortgage.remaining <= 0)
        {
            natalia.mortgage.isActive = false;
            printf("Mortgage paid off in %d/%d\n", month, year);
        }
    }
    if (month == 6 && year == 2026 && !natalia.mortgage.isActive && isMarried)
    {
        natalia.mortgage.isActive = true;
        natalia.mortgage.remaining = natalia.mortgage.amount - natalia.mortgage.down_payment;
        natalia.vtb.account_rub -= natalia.mortgage.down_payment;
        printf("Mortgage taken in %d/%d\n", month, year);
    }
}

void natalia_health_expenses(int month, int year)
{
    if (month % 3 == 0) natalia.vtb.account_rub -= natalia.health.vitamins;
    if (month == 6 || month == 12) natalia.vtb.account_rub -= natalia.health.dentist;
    if (month == 4 && year == 2027) natalia.vtb.account_rub -= natalia.health.sanatorium;
    if (month == 8 && year == 2026) natalia.vtb.account_rub -= natalia.health.gym;
    natalia.vtb.account_rub -= natalia.health.medications;
    if (month == 11 && year == 2027) natalia.vtb.account_rub -= natalia.health.insurance;
    if (month == 3 && year == 2028) natalia.vtb.account_rub -= natalia.health.eye_doctor;
    if (month == 5 && year == 2028) natalia.vtb.account_rub -= natalia.health.glasses;
}

void natalia_education_expenses(int month, int year)
{
    if (month == 9 && year == 2026)
    {
        natalia.vtb.account_rub -= natalia.education.courses;
        natalia.vtb.account_rub -= natalia.education.books;
    }
    if (month == 1 && year == 2027) natalia.vtb.account_rub -= natalia.education.language_school;
    if (month % 6 == 0) natalia.vtb.account_rub -= natalia.education.online_subscriptions;
    if (month == 9 && year == 2028) natalia.vtb.account_rub -= natalia.education.master_degree;
    if (month == 10 && year == 2028) natalia.vtb.account_rub -= natalia.education.conference;
}

void natalia_entertainment_expenses(int month, int year)
{
    if (month % 2 == 0) natalia.vtb.account_rub -= natalia.entertainment.cinema;
    if (month == 12)
    {
        natalia.vtb.account_rub -= natalia.entertainment.restaurants;
        natalia.vtb.account_rub -= natalia.entertainment.gifts;
        natalia.vtb.account_rub -= natalia.entertainment.parties;
    }
    if (month == 8) natalia.vtb.account_rub -= natalia.entertainment.concerts;
    if (month == 2 && year == 2027) natalia.vtb.account_rub -= natalia.entertainment.bowling;
    natalia.vtb.account_rub -= natalia.entertainment.streaming;
    if (month % 4 == 0) natalia.vtb.account_rub -= natalia.entertainment.cafes;
    if (month == 5 && year == 2027) natalia.vtb.account_rub -= natalia.entertainment.shopping;
    if (month == 11 && year == 2027) natalia.vtb.account_rub -= natalia.entertainment.cosmetics;
}

void natalia_charity_expenses(int month, int year)
{
    if (month == 12)
    {
        natalia.vtb.account_rub -= natalia.charity.donations;
        natalia.vtb.account_rub -= natalia.charity.orphanage;
        natalia.vtb.account_rub -= natalia.charity.scholarship_fund;
    }
    if (month % 6 == 0) natalia.vtb.account_rub -= natalia.charity.animal_shelter;
    natalia.vtb.account_rub -= natalia.charity.help_parents;
    if (month == 3 && year == 2027) natalia.vtb.account_rub -= natalia.charity.gifts_for_friends;
    if (month == 4 && year == 2028) natalia.vtb.account_rub -= natalia.charity.environmental;
}

void natalia_black_job(int month, int year)
{
    if (isBlackJobActive)
    {
        natalia.vtb.account_rub += natalia.black_job.income;
        natalia.black_job.months_active++;
        if (natalia.black_job.risk_level > (month % 5) || natalia.black_job.months_active > 12)
        {
            natalia.black_job.caught = true;
            natalia.vtb.account_rub -= natalia.black_job.fine;
            isBlackJobActive = false;
            printf("Black job caught in %d/%d, fine paid\n", month, year);
        }
        if (rand() % 100 < 15)
        {
            natalia.vtb.account_rub -= natalia.black_job.bribe;
            printf("Bribe paid for black job\n");
        }
    }
    if (month == 1 && year == 2027 && !isBlackJobActive && !isMarried && !isChildAlive)
    {
        isBlackJobActive = true;
        printf("Black job started\n");
    }
}

void natalia_lottery(int month, int year)
{
    if (month == 12 && year == 2026)
    {
        natalia.lottery.tickets_bought = 10;
        natalia.lottery.total_spent += natalia.lottery.ticket_cost * 10;
        natalia.vtb.account_rub -= natalia.lottery.ticket_cost * 10;
        if ((rand() % 100) < 15)
        {
            natalia.lottery.winnings = 50000;
            natalia.lottery.total_won += 50000;
            natalia.lottery.wins_count++;
            if (50000 > natalia.lottery.biggest_win) natalia.lottery.biggest_win = 50000;
            natalia.vtb.account_rub += natalia.lottery.winnings;
            printf("Lottery win in %d/%d: 50000 RUB\n", month, year);
        }
    }
    if (month == 12 && year == 2027)
    {
        natalia.lottery.tickets_bought = 5;
        natalia.lottery.total_spent += natalia.lottery.ticket_cost * 5;
        natalia.vtb.account_rub -= natalia.lottery.ticket_cost * 5;
        if ((rand() % 100) < 8)
        {
            natalia.lottery.winnings = 100000;
            natalia.lottery.total_won += 100000;
            natalia.lottery.wins_count++;
            if (100000 > natalia.lottery.biggest_win) natalia.lottery.biggest_win = 100000;
            natalia.vtb.account_rub += natalia.lottery.winnings;
            printf("Lottery win in %d/%d: 100000 RUB\n", month, year);
        }
    }
}

void natalia_inheritance(int month, int year)
{
    if (!natalia.inheritance.isReceived && year == natalia.inheritance.year && month == natalia.inheritance.month)
    {
        natalia.inheritance.isReceived = true;
        natalia.vtb.account_rub += natalia.inheritance.amount - natalia.inheritance.tax - natalia.inheritance.notary_fees;
        printf("Inheritance received in %d/%d\n", month, year);
    }
    if (ivan.isAlive && year == ivan.death_year && month == ivan.death_month)
    {
        ivan.isAlive = false;
        natalia.vtb.account_rub += ivan.inheritance_left;
        printf("Grandfather inheritance received\n");
    }
}

void natalia_dacha_expenses(int month, int year)
{
    if (hasDacha)
    {
        if (month == 5 || month == 9) natalia.vtb.account_rub -= natalia.dacha.maintenance;
        if (month == 6 || month == 7 || month == 8) natalia.vtb.account_rub -= natalia.dacha.utilities;
        if (month == 4) natalia.vtb.account_rub -= natalia.dacha.gardening;
        if (month == 10) natalia.vtb.account_rub -= natalia.dacha.taxes;
        if (month == 11 && year == 2027) natalia.vtb.account_rub -= natalia.dacha.repair;
        if (month == 6 && year == 2028) natalia.vtb.account_rub -= natalia.dacha.barbecue;
        if (month == 8 && year == 2028) natalia.vtb.account_rub -= natalia.dacha.sauna;
    }
    if (month == 5 && year == 2027 && !hasDacha && isMarried && isChildAlive)
    {
        hasDacha = true;
        natalia.vtb.account_rub -= natalia.dacha.purchase;
        natalia.vtb.account_rub -= natalia.dacha.furniture_dacha;
        natalia.vtb.account_rub -= natalia.dacha.tools;
        printf("Dacha purchased in %d/%d\n", month, year);
    }
}

void natalia_divorce(int month, int year)
{
    if (!natalia.divorce.isHappened && isMarried && isChildAlive && year == natalia.divorce.year && month == natalia.divorce.month)
    {
        natalia.divorce.isHappened = true;
        isDivorced = true;
        tolik.isPresent = false;
        natalia.vtb.account_rub -= natalia.divorce.lawyer_fees;
        natalia.vtb.account_rub -= natalia.divorce.property_division;
        natalia.vtb.account_rub -= natalia.divorce.moving_costs;
        tolik.alimony = natalia.divorce.alimony;
        tolik.child_support = natalia.divorce.child_support;
        printf("Divorce finalized in %d/%d\n", month, year);
    }
    if (isDivorced && month == 12 && year == 2028)
    {
        natalia.vtb.account_rub -= natalia.divorce.therapy_costs;
        printf("Therapy after divorce\n");
    }
}

void natalia_crypto_investment(int month, int year)
{
    if (month == 1 && year == 2026)
    {
        natalia.vtb.account_rub -= natalia.crypto.total_invested;
        natalia.vtb.investments += natalia.crypto.total_invested;
        printf("Crypto investment made\n");
    }
    update_crypto_prices(month, year);
    if (month == 12 && year == 2028)
    {
        natalia.vtb.account_rub += natalia.crypto.current_value;
        if (natalia.crypto.profit_loss > 0)
        {
            RUB tax = natalia.crypto.profit_loss * 13 / 100;
            natalia.vtb.account_rub += natalia.crypto.profit_loss - tax;
            printf("Crypto sold, profit: %lld, tax: %lld\n", natalia.crypto.profit_loss, tax);
        }
        else
        {
            printf("Crypto sold, loss: %lld\n", natalia.crypto.profit_loss);
        }
    }
}

void natalia_stock_investment(int month, int year)
{
    if (month == 2 && year == 2026)
    {
        natalia.vtb.account_rub -= natalia.stock.total_invested;
        natalia.vtb.investments += natalia.stock.total_invested;
        printf("Stock investment made\n");
    }
    update_stock_prices(month, year);
    if (month == 12 && year == 2028)
    {
        natalia.vtb.account_rub += natalia.stock.current_value;
        RUB profit = natalia.stock.current_value - natalia.stock.total_invested;
        if (profit > 0)
        {
            RUB tax = profit * 13 / 100;
            natalia.vtb.account_rub += profit - tax;
            printf("Stocks sold, profit: %lld\n", profit);
        }
        else
        {
            printf("Stocks sold, loss: %lld\n", profit);
        }
        printf("Total dividends received: %lld\n", natalia.stock.dividend_received);
    }
}

void natalia_sister_help(int month, int year)
{
    if (olga.isPresent && olga.paying_back)
    {
        natalia.vtb.account_rub += olga.return_payment;
        olga.debt_to_natalia -= olga.return_payment;
        if (olga.debt_to_natalia <= 0)
        {
            olga.paying_back = false;
            printf("Sister debt fully repaid in %d/%d\n", month, year);
        }
    }
    if (month == 3 && year == 2026 && olga.isPresent)
    {
        natalia.vtb.account_rub -= olga.help_to_family;
        printf("Help to sister\n");
    }
}

void natalia_friend_help(int month, int year)
{
    if (!marina.borrowed && month == marina.help_month && year == marina.help_year)
    {
        marina.borrowed = true;
        natalia.vtb.account_rub -= marina.help_amount;
        marina.return_amount = marina.help_amount * 1.1;
        printf("Money lent to friend\n");
    }
    if (marina.borrowed && !marina.returned && month == marina.help_month + 6 && year == marina.help_year + 1)
    {
        marina.returned = true;
        natalia.vtb.account_rub += marina.return_amount;
        printf("Friend returned money with interest\n");
    }
    if (marina.borrowed && !marina.returned && month == marina.help_month + 12)
    {
        marina.returned = true;
        printf("Friend never returned money\n");
    }
}

void natalia_grandmother_care(int month, int year)
{
    if (zinaida.isAlive)
    {
        natalia.vtb.account_rub += zinaida.pension;
        if (month == 1)
        {
            natalia.vtb.account_rub -= zinaida.food;
            natalia.vtb.account_rub -= zinaida.medications;
        }
        if (month == 3 && year == 2026) natalia.vtb.account_rub += zinaida.help_from_relatives;
        if (month == 12 && year == 2026) natalia.vtb.account_rub -= zinaida.gifts_for_grandchildren;
        if (month % 2 == 0) natalia.vtb.account_rub -= zinaida.utilities;
        if (month == 5 || month == 11) natalia.vtb.account_rub -= zinaida.medications;
        if (month == 9 && year == 2027)
        {
            zinaida.isAlive = false;
            natalia.vtb.account_rub += zinaida.savings;
            natalia.vtb.account_rub += zinaida.house_value;
            natalia.vtb.account_rub += zinaida.dacha_value;
            natalia.vtb.account_rub += zinaida.car_value;
            natalia.vtb.account_rub += zinaida.jewelry;
            printf("Grandmother passed away, inheritance received\n");
        }
    }
}

void natalia_random_events(int month, int year)
{
    int event = rand() % 100;
    if (event < 5 && natalia.vtb.account_rub > 50000)
    {
        RUB stolen = 5000 + rand() % 30000;
        natalia.vtb.account_rub -= stolen;
        printf("Theft: lost %lld RUB\n", stolen);
    }
    else if (event < 10)
    {
        RUB found = 1000 + rand() % 15000;
        natalia.vtb.account_rub += found;
        printf("Found money: +%lld RUB\n", found);
    }
    else if (event < 13)
    {
        RUB gift = 5000 + rand() % 25000;
        natalia.vtb.account_rub += gift;
        printf("Gift received: +%lld RUB\n", gift);
    }
    else if (event < 15 && !isMarried && !isDivorced)
    {
        isMarried = true;
        tolik.isPresent = true;
        printf("Unexpected marriage!\n");
    }
    else if (event < 17 && isMarried && !isDivorced)
    {
        isDivorced = true;
        tolik.isPresent = false;
        printf("Unexpected divorce!\n");
    }
}

void simulation()
{
    int year = 2026;
    int month = 2;
    while (!(year == 2029 && month == 1))
    {
        natalia_salary(month, year);
        natalia_flat_expenses(month, year);
        natalia_car_expenses(month, year);
        natalia_cat_expenses(month, year);
        natalia_dog_expenses(month, year);
        natalia_hamster_expenses(month, year);
        natalia_parrot_expenses(month, year);
        natalia_fish_expenses(month, year);
        natalia_rabbit_expenses(month, year);
        natalia_turtle_expenses(month, year);
        natalia_trip_expenses(month, year);
        natalia_food(month, year);
        natalia_wedding(month, year);
        tolik_income_and_expenses(month, year);
        natalia_pregnancy(month, year);
        natalia_childbirth(month, year);
        natalia_child_expenses(month, year);
        natalia_kredit_expenses(month, year);
        natalia_mortgage_expenses(month, year);
        natalia_health_expenses(month, year);
        natalia_education_expenses(month, year);
        natalia_entertainment_expenses(month, year);
        natalia_charity_expenses(month, year);
        natalia_black_job(month, year);
        natalia_lottery(month, year);
        natalia_inheritance(month, year);
        natalia_dacha_expenses(month, year);
        natalia_divorce(month, year);
        natalia_crypto_investment(month, year);
        natalia_stock_investment(month, year);
        natalia_sister_help(month, year);
        natalia_friend_help(month, year);
        natalia_grandmother_care(month, year);
        natalia_random_events(month, year);
        month++;
        if (month == 13)
        {
            year++;
            month = 1;
        }
    }
}

RUB calculate_total_capital()
{
    RUB total = 0;
    total += natalia.vtb.account_rub;
    total += natalia.vtb.account_usd * natalia.vtb.rate_usd_rub;
    total += natalia.car.value;
    total += natalia.crypto.current_value;
    total += natalia.stock.current_value;
    if (hasDacha) total += natalia.dacha.purchase;
    if (!zinaida.isAlive) total += zinaida.house_value;
    if (!ivan.isAlive) total += ivan.house_value;
    if (tolik.isPresent && !isDivorced) total += tolik.car.value;
    if (isMarried && !isDivorced && natalia.mortgage.isActive)
    {
        total -= natalia.mortgage.remaining;
    }
    if (natalia.kredit.isActive) total -= natalia.kredit.remaining;
    return total;
}

void print_results()
{
    printf("\n========== SIMULATION RESULTS ==========\n");
    printf("Year: 2026-2029\n");
    printf("\n--- NATALIA ---\n");
    printf("Salary: %lld RUB\n", natalia.salary);
    printf("Bank account RUB: %lld RUB\n", natalia.vtb.account_rub);
    printf("Bank account USD: %lld USD\n", natalia.vtb.account_usd);
    printf("Car value: %lld RUB\n", natalia.car.value);
    printf("\n--- FAMILY STATUS ---\n");
    printf("Married: %s\n", isMarried ? "Yes" : "No");
    printf("Divorced: %s\n", isDivorced ? "Yes" : "No");
    printf("Child: %s\n", isChildAlive ? "Yes" : "No");
    printf("\n--- PROPERTY ---\n");
    printf("Dacha owned: %s\n", hasDacha ? "Yes" : "No");
    printf("Mortgage active: %s\n", natalia.mortgage.isActive ? "Yes" : "No");
    if (natalia.mortgage.isActive) printf("Mortgage remaining: %lld RUB\n", natalia.mortgage.remaining);
    printf("Kredit active: %s\n", natalia.kredit.isActive ? "Yes" : "No");
    if (natalia.kredit.isActive) printf("Kredit remaining: %lld RUB\n", natalia.kredit.remaining);
    printf("\n--- INVESTMENTS ---\n");
    printf("Crypto current value: %lld RUB\n", natalia.crypto.current_value);
    printf("Crypto profit/loss: %lld RUB\n", natalia.crypto.profit_loss);
    printf("Stocks current value: %lld RUB\n", natalia.stock.current_value);
    printf("Stocks dividends received: %lld RUB\n", natalia.stock.dividend_received);
    printf("\n--- LOTTERY ---\n");
    printf("Total spent on lottery: %lld RUB\n", natalia.lottery.total_spent);
    printf("Total won: %lld RUB\n", natalia.lottery.total_won);
    printf("Wins count: %d\n", natalia.lottery.wins_count);
    printf("Biggest win: %lld RUB\n", natalia.lottery.biggest_win);
    printf("\n--- BLACK JOB ---\n");
    printf("Black job active: %s\n", isBlackJobActive ? "Yes" : "No");
    if (natalia.black_job.caught) printf("Was caught: Yes, fine paid\n");
    printf("\n--- INHERITANCE ---\n");
    printf("Grandmother inheritance received: %s\n", !zinaida.isAlive ? "Yes" : "No");
    printf("Grandfather inheritance received: %s\n", !ivan.isAlive ? "Yes" : "No");
    printf("\n--- TOTAL CAPITAL ---\n");
    printf("TOTAL CAPITAL: %lld RUB\n", calculate_total_capital());
    printf("==========================================\n");
}

int main()
{
    srand(time(NULL));
    natalia_init();
    simulation();
    print_results();
    return 0;
}