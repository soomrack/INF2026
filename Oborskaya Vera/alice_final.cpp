#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>

typedef long long int RUB;

struct Car {
    RUB value;
    RUB gas;
    RUB insurance;
    RUB tires_winter;
    RUB tires_summer;
    RUB washing;
    RUB parking_home;
    RUB parking_work;
    RUB fines;
    RUB toll_roads;
    RUB repair;
    RUB diagnostics;
    RUB antifreeze;
    RUB oil_change;
};

struct Transport {
    RUB taxi;
    RUB carsharing;
    RUB pub;
};

struct Trip {
    RUB flight;
    RUB hotel;
    RUB meals;
    RUB excursions;
    RUB transport;
    RUB insurance;
    RUB visa;
    RUB souvenirs;
    RUB entertainment;
    RUB shopping;
};

struct Home {
    RUB rent;
    RUB farm;
    RUB electricity;
    RUB heating;
    RUB water;
    RUB gas;
    RUB garbage;
    RUB intercom;
    RUB furniture;
    RUB cleaning;
    RUB repair;
};

struct Dog {
    RUB dvalue;
    RUB dfood;
    RUB toys;
    RUB bed;
    RUB leash;
    RUB vet;
    RUB vaccines;
    RUB vitamins;
    RUB teeth_cleaning;
    RUB allergy_meds;
};

struct Cat {
    RUB cvalue;
    RUB cfood;
    RUB toys;
    RUB tray;
    RUB house_bed;
    RUB scratching_post;
    RUB cvet;
    RUB vitamins;
    RUB treats;
    RUB carrier;
    RUB dental_treats;
};

struct Wedding {
    RUB dress;
    RUB suit;
    RUB venue;
    RUB catering;
    RUB cake;
    RUB photographer;
    RUB music;
    RUB flowers;
    RUB rings;
    RUB transport;
    RUB honeymoon;
};

struct Child {
    RUB medical;           
    RUB baby_supplies;    
    RUB baby_gear;        
    RUB clothes;          
    RUB food;             
    RUB education;        
    RUB entertainment;     
    RUB childcare;        
    RUB housing;           
    RUB transport;         
    RUB special_events;    
    RUB monthly_allowance; 
};

struct Bank {
    RUB account_rub;
    RUB deposit_rub;
};

struct Investments {
    RUB stocks;
    RUB bonds;
    RUB etf;
    RUB crypto;
    RUB mutual_funds;
    RUB gold;
    RUB real_estate_fund;
    RUB startup_investment;
    RUB total;
};

struct Education {
    RUB professional_courses;
    RUB language_courses;
    RUB mba;
    RUB books;
    RUB online_subscriptions;
    RUB conferences;
    RUB coaching;
    RUB software_licenses;
};

struct Healthcare {
    RUB medical_insurance;
    RUB fitness_club;
    RUB yoga;
    RUB massage;
    RUB psychologist;
    RUB vitamins_general;
    RUB regular_meds;
    RUB break_a_leg;
};

struct Entertainment {
    RUB cinema;
    RUB theater;
    RUB concerts;
    RUB museums;
    RUB quests;
    RUB bowling;
    RUB restaurants;
    RUB bars;
    RUB hookah;
    RUB alcohol;
    RUB cigarettes;
    RUB vape;
    RUB gaming_subscriptions;
    RUB game_purchases;
    RUB board_games;
};

struct Utilities {
    RUB internet;
    RUB mobile_family;
    RUB tv_subscription;
    RUB streaming_video;
    RUB streaming_music;
    RUB cloud_storage;
    RUB vpn;
    RUB antivirus;
};

struct Gifts {
    RUB birthday_family;
    RUB birthday_friends;
    RUB birthday_colleagues;
    RUB new_year;
    RUB march_8;
    RUB february_23;
    RUB children_birthdays;
    RUB donations;
};

struct Person {
    RUB salary;
    RUB bonus;
    RUB food;
    RUB food_delivery;
    Car car;
    Transport transport;
    Home home;
    Cat cat;
    Dog dog;
    Trip trip;
    Wedding wedding;
    Child child;
    Bank bank;
    Investments investments;
    Education education;
    Healthcare healthcare;
    Entertainment entertainment;
    Utilities utilities;
    Gifts gifts;
    bool hascat;
    bool hasdog;
    int age;
};

struct Family {
    bool isMarried;
    bool hasChildren;
    int child_age;
    int child_birth_month;
    int child_birth_year;
};

struct ExpenseStats {
    RUB total_income;
    RUB total_expenses;
    RUB food;
    RUB housing;
    RUB car;
    RUB transport;
    RUB pets;
    RUB trips;
    RUB entertainment;
    RUB utilities;
    RUB gifts;
    RUB healthcare;
    RUB education;
    RUB wedding;
    RUB child;
    RUB investments;
};

struct Person alice;
struct Person alex;
struct Family family = { 0 };
struct ExpenseStats alicestats = { 0 };
struct ExpenseStats alexstats = { 0 };

void init_alice() 
{
    alice.age = 25;

    alice.hascat = true;
    alice.hasdog = true;

    alice.salary = 250000;
    alice.bonus = 0;
    alice.food = 12000;
    alice.food_delivery = 3000;

    alice.car.value = 3000000;
    alice.car.gas = 4000;
    alice.car.insurance = 1500;
    alice.car.tires_winter = 2000;
    alice.car.tires_summer = 2000;
    alice.car.washing = 500;
    alice.car.parking_home = 2000;
    alice.car.parking_work = 2000;
    alice.car.fines = 1000;
    alice.car.toll_roads = 2000;
    alice.car.repair = 1000;
    alice.car.diagnostics = 1500;
    alice.car.antifreeze = 1000;
    alice.car.oil_change = 4000;

    alice.transport.taxi = 1000;
    alice.transport.carsharing = 300;
    alice.transport.pub = 100;

    alice.home.rent = 20000;
    alice.home.farm = 2000;
    alice.home.electricity = 2000;
    alice.home.heating = 1000;
    alice.home.water = 500;
    alice.home.gas = 500;
    alice.home.garbage = 500;
    alice.home.intercom = 300;
    alice.home.furniture = 4000;
    alice.home.cleaning = 1000;
    alice.home.repair = 500;

    alice.cat.cvalue = 500;
    alice.cat.cfood = 300;
    alice.cat.toys = 200;
    alice.cat.tray = 100;
    alice.cat.house_bed = 1500;
    alice.cat.scratching_post = 5000;
    alice.cat.cvet = 200;
    alice.cat.vitamins = 200;
    alice.cat.treats = 500;
    alice.cat.carrier = 2500;
    alice.cat.dental_treats = 800;

    alice.dog.dvalue = 30000;
    alice.dog.dfood = 5000;
    alice.dog.toys = 1500;
    alice.dog.bed = 3000;
    alice.dog.leash = 3500;
    alice.dog.vet = 3000;
    alice.dog.vaccines = 4000;
    alice.dog.vitamins = 1000;
    alice.dog.teeth_cleaning = 3000;
    alice.dog.allergy_meds = 2000;

    alice.wedding.dress = 50000;
    alice.wedding.suit = 30000;
    alice.wedding.venue = 100000;
    alice.wedding.catering = 80000;
    alice.wedding.photographer = 40000;
    alice.wedding.music = 25000;
    alice.wedding.flowers = 20000;
    alice.wedding.cake = 10000;
    alice.wedding.rings = 30000;
    alice.wedding.honeymoon = 200000;
    alice.wedding.transport = 15000;

    alice.child.medical = 48500/2;        
    alice.child.baby_supplies = 17500/2;   
    alice.child.baby_gear = 125000/2;      
    alice.child.clothes = 50000/2;         
    alice.child.food = 6000/2;             
    alice.child.education = 398000/2;      
    alice.child.entertainment = 105500/2;  
    alice.child.childcare = 30000/2;       
    alice.child.housing = 50000/2;         
    alice.child.transport = 500000/2;      
    alice.child.special_events = 95000/2;  
    alice.child.monthly_allowance = 2000/2;

    alice.bank.account_rub = 0;
    alice.bank.deposit_rub = 0;

    alice.investments.stocks = 0;
    alice.investments.bonds = 0;
    alice.investments.etf = 0;
    alice.investments.crypto = 0;
    alice.investments.mutual_funds = 0;
    alice.investments.gold = 0;
    alice.investments.real_estate_fund = 0;
    alice.investments.startup_investment = 0;
    alice.investments.total = 0;

    alice.education.professional_courses = 20000;
    alice.education.language_courses = 15000;
    alice.education.mba = 0;
    alice.education.books = 5000;
    alice.education.online_subscriptions = 3000;
    alice.education.conferences = 10000;
    alice.education.coaching = 8000;
    alice.education.software_licenses = 5000;

    alice.healthcare.medical_insurance = 15000;
    alice.healthcare.fitness_club = 4000;
    alice.healthcare.yoga = 3000;
    alice.healthcare.massage = 4000;
    alice.healthcare.psychologist = 5000;
    alice.healthcare.vitamins_general = 2000;
    alice.healthcare.regular_meds = 3000;
    alice.healthcare.break_a_leg = 15000;

    alice.entertainment.cinema = 200;
    alice.entertainment.theater = 400;
    alice.entertainment.concerts = 500;
    alice.entertainment.museums = 100;
    alice.entertainment.quests = 200;
    alice.entertainment.bowling = 1500;
    alice.entertainment.restaurants = 800;
    alice.entertainment.bars = 500;
    alice.entertainment.hookah = 2000;
    alice.entertainment.alcohol = 4000;
    alice.entertainment.cigarettes = 0;
    alice.entertainment.vape = 0;
    alice.entertainment.gaming_subscriptions = 100;
    alice.entertainment.game_purchases = 200;
    alice.entertainment.board_games = 1500;

    alice.utilities.internet = 800;
    alice.utilities.mobile_family = 1500;
    alice.utilities.tv_subscription = 500;
    alice.utilities.streaming_video = 800;
    alice.utilities.streaming_music = 300;
    alice.utilities.cloud_storage = 200;
    alice.utilities.vpn = 500;
    alice.utilities.antivirus = 300;

    alice.gifts.birthday_family = 500;
    alice.gifts.birthday_friends = 300;
    alice.gifts.birthday_colleagues = 200;
    alice.gifts.new_year = 1000;
    alice.gifts.march_8 = 300;
    alice.gifts.february_23 = 300;
    alice.gifts.children_birthdays = 200;
    alice.gifts.donations = 100;

    alice.trip.flight = 8500;
    alice.trip.hotel = 15000;
    alice.trip.meals = 3800;
    alice.trip.excursions = 3000;
    alice.trip.transport = 3000;
    alice.trip.insurance = 500;
    alice.trip.visa = 800;
    alice.trip.souvenirs = 2000;
    alice.trip.entertainment = 4500;
    alice.trip.shopping = 1500;
}

void init_alex() 
{
    alex.age = 30;

    alex.hascat = true;
    alex.hasdog = true;

    alex.salary = 300000;
    alex.bonus = 0;
    alex.food = 18000;          
    alex.food_delivery = 7000;     

    alex.car.value = 2500000;      
    alex.car.gas = 10000;         
    alex.car.insurance = 6000;
    alex.car.tires_winter = 18000;
    alex.car.tires_summer = 18000;
    alex.car.washing = 1500;
    alex.car.parking_home = 5000;
    alex.car.parking_work = 5000;
    alex.car.fines = 2000;
    alex.car.toll_roads = 1000;
    alex.car.repair = 7000;
    alex.car.diagnostics = 4000;
    alex.car.antifreeze = 1200;
    alex.car.oil_change = 5000;

    alex.transport.taxi = 5000;   
    alex.transport.carsharing = 1000;
    alex.transport.pub = 3000;

    alex.home.rent = 45000;
    alex.home.farm = 2000;
    alex.home.electricity = 4000;
    alex.home.heating = 3000;
    alex.home.water = 1500;
    alex.home.gas = 500;
    alex.home.garbage = 500;
    alex.home.intercom = 300;
    alex.home.furniture = 15000;  
    alex.home.cleaning = 1500;
    alex.home.repair = 5000;

    alex.cat.cvalue = 8000;
    alex.cat.cfood = 3500;
    alex.cat.toys = 3000;
    alex.cat.tray = 1200;
    alex.cat.house_bed = 2000;
    alex.cat.scratching_post = 6000;
    alex.cat.cvet = 2500;
    alex.cat.vitamins = 2500;
    alex.cat.treats = 800;
    alex.cat.carrier = 3000;
    alex.cat.dental_treats = 1000;

    alex.dog.dvalue = 25000;
    alex.dog.dfood = 6000;
    alex.dog.toys = 2000;
    alex.dog.bed = 4000;
    alex.dog.leash = 4000;
    alex.dog.vet = 5000;
    alex.dog.vaccines = 4500;
    alex.dog.vitamins = 1500;
    alex.dog.teeth_cleaning = 3500;
    alex.dog.allergy_meds = 2500;

    alex.wedding.dress = 80000;    
    alex.wedding.suit = 25000;      
    alex.wedding.venue = 100000;
    alex.wedding.catering = 80000;
    alex.wedding.photographer = 50000;
    alex.wedding.music = 30000;
    alex.wedding.flowers = 30000;
    alex.wedding.cake = 15000;
    alex.wedding.rings = 40000;
    alex.wedding.honeymoon = 200000;
    alex.wedding.transport = 20000;

    alex.child.medical = 48500 / 2;
    alex.child.baby_supplies = 17500 / 2;
    alex.child.baby_gear = 125000 / 2;
    alex.child.clothes = 50000 / 2;
    alex.child.food = 6000 / 2;
    alex.child.education = 398000 / 2;
    alex.child.entertainment = 105500 / 2;
    alex.child.childcare = 30000 / 2;
    alex.child.housing = 50000 / 2;
    alex.child.transport = 500000 / 2;
    alex.child.special_events = 95000 / 2;
    alex.child.monthly_allowance = 2000 / 2;

    alex.bank.account_rub = 0;
    alex.bank.deposit_rub = 0;

    alex.investments.stocks = 0;
    alex.investments.bonds = 0;
    alex.investments.etf = 0;
    alex.investments.crypto = 0;
    alex.investments.mutual_funds = 0;
    alex.investments.gold = 0;
    alex.investments.real_estate_fund = 0;
    alex.investments.startup_investment = 0;
    alex.investments.total = 0;

    alex.education.professional_courses = 25000;
    alex.education.language_courses = 20000;
    alex.education.mba = 50000;
    alex.education.books = 8000;
    alex.education.online_subscriptions = 5000;
    alex.education.conferences = 15000;
    alex.education.coaching = 12000;
    alex.education.software_licenses = 7000;

    alex.healthcare.medical_insurance = 18000;
    alex.healthcare.fitness_club = 6000;
    alex.healthcare.yoga = 5000;
    alex.healthcare.massage = 6000;
    alex.healthcare.psychologist = 8000;
    alex.healthcare.vitamins_general = 3000;
    alex.healthcare.regular_meds = 4000;

    alex.entertainment.cinema = 3000;
    alex.entertainment.theater = 6000;
    alex.entertainment.concerts = 7000;
    alex.entertainment.museums = 2000;
    alex.entertainment.quests = 3000;
    alex.entertainment.bowling = 2000;
    alex.entertainment.restaurants = 12000;
    alex.entertainment.bars = 7000;
    alex.entertainment.hookah = 1000;
    alex.entertainment.alcohol = 3000;
    alex.entertainment.cigarettes = 0;
    alex.entertainment.vape = 0;
    alex.entertainment.gaming_subscriptions = 500;
    alex.entertainment.game_purchases = 1000;
    alex.entertainment.board_games = 2000;

    alex.utilities.internet = 800;
    alex.utilities.mobile_family = 1500;
    alex.utilities.tv_subscription = 500;
    alex.utilities.streaming_video = 800;
    alex.utilities.streaming_music = 300;
    alex.utilities.cloud_storage = 200;
    alex.utilities.vpn = 500;
    alex.utilities.antivirus = 300;

    alex.gifts.birthday_family = 7000;
    alex.gifts.birthday_friends = 5000;
    alex.gifts.birthday_colleagues = 3000;
    alex.gifts.new_year = 15000;
    alex.gifts.march_8 = 5000;
    alex.gifts.february_23 = 2000;
    alex.gifts.children_birthdays = 3000;
    alex.gifts.donations = 2000;

    alex.trip.flight = 100000;
    alex.trip.hotel = 180000;
    alex.trip.meals = 45000;
    alex.trip.excursions = 40000;
    alex.trip.transport = 35000;
    alex.trip.insurance = 8000;
    alex.trip.visa = 10000;
    alex.trip.souvenirs = 30000;
    alex.trip.entertainment = 60000;
    alex.trip.shopping = 25000;
}

void alice_salary(int month) 
{
    alice.bank.account_rub += alice.salary;
    alicestats.total_income += alice.salary;

    RUB tax = alice.salary * 0.13;
    alice.bank.account_rub -= tax;

    if (month == 3) {
        alice.salary *=  1.2;
    }

    if (month == 12) {
        alice.bonus = alice.salary * 1.5;
        alice.bank.account_rub += alice.bonus;
        alicestats.total_income += alice.bonus;
    }
}

void alice_food_expenses(int month, int year) 
{
    alice.bank.account_rub -= alice.food;
    alicestats.food += alice.food;

    if (month % 2 == 0) {
        alice.bank.account_rub -= alice.food_delivery;
        alicestats.food += alice.food_delivery;
    }

    if (month==12) {
        float food_inf = year == 2026 ? 12.5f : (year == 2027 ? 14.0f : (year == 2028 ? 13.0f : 10.0f));
        alice.food = (RUB)(alice.food * (1.0f + food_inf / 100.0f));
        alice.food_delivery = (RUB)(alice.food_delivery * (1.0f + food_inf / 100.0f));
    }
}

void alice_housing_expenses(int month, int year) 
{
    alice.bank.account_rub -= alice.home.rent;
    alice.bank.account_rub -= alice.home.electricity;
    alice.bank.account_rub -= alice.home.heating;
    alice.bank.account_rub -= alice.home.water;
    alice.bank.account_rub -= alice.home.gas;
    alice.bank.account_rub -= alice.home.garbage;
    alice.bank.account_rub -= alice.home.intercom;

    alicestats.housing += alice.home.rent + alice.home.electricity + alice.home.heating + 
        alice.home.water + alice.home.gas + alice.home.garbage + alice.home.intercom;
    
    if (month % 3 == 0) {
        alice.bank.account_rub -= alice.home.farm;
        alicestats.housing += alice.home.farm + alice.home.cleaning;

        alice.bank.account_rub -= alice.home.cleaning;
    }

    if (month == 6 || month == 12) {
        alice.bank.account_rub -= alice.home.repair;

        alicestats.housing += alice.home.repair;
    }

    if (month == 5 || month == 11) {
        alice.bank.account_rub -= alice.home.furniture;

        alicestats.housing += alice.home.furniture;
    }

    if (month == 12) {
        float home_inf = year == 2026 ? 8.5f : year == 2027 ? 9.0f : year == 2028 ? 9.5f : 8.5f;
        alice.home.rent = (RUB)(alice.home.rent * (1.0f + home_inf / 100.0f));
        alice.home.electricity = (RUB)(alice.home.electricity * (1.0f + home_inf / 100.0f));
        alice.home.heating = (RUB)(alice.home.heating * (1.0f + home_inf / 100.0f));
        alice.home.water = (RUB)(alice.home.water * (1.0f + home_inf / 100.0f));
        alice.home.gas = (RUB)(alice.home.gas * (1.0f + home_inf / 100.0f));
        alice.home.garbage = (RUB)(alice.home.garbage * (1.0f + home_inf / 100.0f));
        alice.home.intercom = (RUB)(alice.home.intercom * (1.0f + home_inf / 100.0f));
        alice.home.farm = (RUB)(alice.home.farm * (1.0f + home_inf / 100.0f));
        alice.home.cleaning = (RUB)(alice.home.cleaning * (1.0f + home_inf / 100.0f));
        alice.home.repair = (RUB)(alice.home.repair * (1.0f + home_inf / 100.0f));
        alice.home.furniture = (RUB)(alice.home.furniture * (1.0f + home_inf / 100.0f));
    }
}

void alice_car_expenses( int month, int year) 
{
    RUB total = 0;
    total += alice.car.gas;
    total += alice.car.toll_roads;
    total += alice.car.parking_home;
    total += alice.car.parking_work;
    total += alice.car.fines;
    total += alice.car.fines;

    if (month % 2 == 0) {
        total += alice.car.washing;
    }
  
    if (month == 10) {
        total += alice.car.tires_winter;
        total += alice.car.diagnostics;
    }

    if (month == 4) {
        total += alice.car.tires_summer;
        total += alice.car.diagnostics;
    }

    if (month == 6 || month == 12) {
        total += alice.car.oil_change;
        total += alice.car.antifreeze;
    }

    if (month == 11) {
        total += alice.car.insurance;
        total += alice.car.repair;
    }

    alice.bank.account_rub -= total;
    alicestats.car += total;

    if (month == 12) {
        float car_inf = year == 2026 ? 6.5f : year == 2027 ? 7.0f : year == 2028 ? 8.0f : 7.0f;
        alice.car.gas = (RUB)(alice.car.gas * (1.0f + car_inf / 100.0f));
        alice.car.toll_roads = (RUB)(alice.car.toll_roads * (1.0f + car_inf / 100.0f));
        alice.car.repair = (RUB)(alice.car.repair * (1.0f + car_inf / 100.0f));
        alice.car.oil_change = (RUB)(alice.car.oil_change * (1.0f + car_inf / 100.0f));
        alice.car.antifreeze = (RUB)(alice.car.antifreeze * (1.0f + car_inf / 100.0f));
        alice.car.tires_winter = (RUB)(alice.car.tires_winter * (1.0f + car_inf / 100.0f));
        alice.car.tires_summer = (RUB)(alice.car.tires_summer * (1.0f + car_inf / 100.0f));
        alice.car.diagnostics = (RUB)(alice.car.diagnostics * (1.0f + car_inf / 100.0f));
        alice.car.insurance = (RUB)(alice.car.insurance * (1.0f + car_inf / 100.0f));
        alice.car.washing = (RUB)(alice.car.washing * (1.0f + car_inf / 100.0f));
        alice.car.parking_home = (RUB)(alice.car.parking_home * (1.0f + car_inf / 100.0f));
        alice.car.parking_work = (RUB)(alice.car.parking_work * (1.0f + car_inf / 100.0f));
        alice.car.fines = (RUB)(alice.car.fines * (1.0f + car_inf / 100.0f));
    }
 
}

void alice_transport_expenses( int month, int year) 
{
    alice.bank.account_rub -= alice.transport.pub;
    alicestats.transport += alice.transport.pub;

    if (month % 2 == 0) {
        alice.bank.account_rub -= alice.transport.taxi;
        alicestats.transport += alice.transport.taxi;
    }

    if (month % 3 == 0) {
        alice.bank.account_rub -= alice.transport.carsharing;
        alicestats.transport += alice.transport.carsharing;
    }

    if (month == 12) {
        float transport_inf = year == 2026 ? 9.0f : year == 2027 ? 9.5f : year == 2028 ? 10.0f : 8.5f;
        alice.transport.taxi = (RUB)(alice.transport.taxi * (1.0f + transport_inf / 100.0f));
        alice.transport.carsharing = (RUB)(alice.transport.carsharing * (1.0f + transport_inf / 100.0f));
        alice.transport.pub = (RUB)(alice.transport.pub * (1.0f + transport_inf / 100.0f));
    }
}

void alice_trip_expenses(int month, int year) 
{
    if (month != 6) return;

    RUB total = 0;
    total += alice.trip.flight;
    total += alice.trip.hotel;
    total += alice.trip.meals;
    total += alice.trip.excursions;
    total += alice.trip.transport;
    total += alice.trip.insurance;
    total += alice.trip.visa;
    total += alice.trip.souvenirs;
    total += alice.trip.shopping;
    total += alice.trip.entertainment;

    alice.bank.account_rub -= total;
    alicestats.trips += total;

    if (month == 12) {
        float trip_inf = year == 2026 ? 11.0f : year == 2027 ? 12.0f : year == 2028 ? 10.5f : 10.0f;
        alice.trip.flight = (RUB)(alice.trip.flight * (1.0f + trip_inf / 100.0f));
        alice.trip.hotel = (RUB)(alice.trip.hotel * (1.0f + trip_inf / 100.0f));
        alice.trip.meals = (RUB)(alice.trip.meals * (1.0f + trip_inf / 100.0f));
        alice.trip.excursions = (RUB)(alice.trip.excursions * (1.0f + trip_inf / 100.0f));
        alice.trip.transport = (RUB)(alice.trip.transport * (1.0f + trip_inf / 100.0f));
        alice.trip.insurance = (RUB)(alice.trip.insurance * (1.0f + trip_inf / 100.0f));
        alice.trip.visa = (RUB)(alice.trip.visa * (1.0f + trip_inf / 100.0f));
        alice.trip.souvenirs = (RUB)(alice.trip.souvenirs * (1.0f + trip_inf / 100.0f));
        alice.trip.entertainment = (RUB)(alice.trip.entertainment * (1.0f + trip_inf / 100.0f));
        alice.trip.shopping = (RUB)(alice.trip.shopping * (1.0f + trip_inf / 100.0f));

    }
}


void alice_child_expenses(int month, int year, bool has_child, int child_age) 
{
    if (!has_child) return;

    RUB total = 0;

    if (child_age < 1) {
        total += alice.child.medical / 12;
        total += alice.child.baby_supplies;
        total += alice.child.baby_gear / 12;
        total += alice.child.clothes / 12;
        total += alice.child.food;
        total += alice.child.entertainment / 12;

        if (month == family.child_birth_month) {
            total += alice.child.special_events;
        }
    }
    else if (child_age >= 1 && child_age < 3) {
        total += alice.child.medical / 6;
        total += alice.child.baby_supplies;
        total += alice.child.clothes / 12;
        total += alice.child.food;
        total += alice.child.entertainment / 6;

        if (month == family.child_birth_month) {
            total += alice.child.special_events;
        }
    }
    else if (child_age >= 3 && child_age < 7) {
        total += alice.child.education / 12;  
        total += alice.child.clothes / 12;
        total += alice.child.medical / 12;
        total += alice.child.entertainment / 6;
        total += alice.child.monthly_allowance;

        if (month == family.child_birth_month) {
            total += alice.child.special_events;
        }

        if (month == 6) {
            total += alice.child.entertainment / 4;  
        }
    }
    else if (child_age >= 7 && child_age < 12) {
        total += alice.child.education / 4;  
        total += alice.child.clothes / 12;
        total += alice.child.medical / 12;
        total += alice.child.entertainment / 6;
        total += alice.child.monthly_allowance;

        if (month == 8) {
            total += alice.child.education / 6;  
        }

        if (month == family.child_birth_month) {
            total += alice.child.special_events;
        }

        if (month == 6) {
            total += alice.child.entertainment / 3;  
        }
    }
    else if (child_age >= 12 && child_age < 18) {
        total += alice.child.education / 6;
        total += alice.child.clothes / 12;
        total += alice.child.medical / 6;
        total += alice.child.entertainment / 4;
        total += alice.child.monthly_allowance * 1.5f;
        total += alice.child.transport / 12;  

        if (month == 8) {
            total += alice.child.education / 8;
        }

        if (month == family.child_birth_month) {
            total += alice.child.special_events;
        }

        if (child_age == 18 && month == 1) {
            total += alice.child.transport;
        }
    }
    else if (child_age >= 18) {
        total += alice.child.education / 12;  
        total += alice.child.housing;
        total += alice.child.monthly_allowance;
        total += alice.child.clothes / 12;

        if (month == 8) {
            total += alice.child.education / 6;
            total += alice.child.entertainment / 4;
        }

        if (month == family.child_birth_month) {
            total += alice.child.special_events;
        }
    }

    alice.bank.account_rub -= total;
    alicestats.child += total;

    if (month == 12) {
        float child_inf = year == 2026 ? 9.0f : year == 2027 ? 9.5f : year == 2028 ? 10.0f : 9.0f;
        alice.child.medical = (RUB)(alice.child.medical * (1.0f + child_inf / 100.0f));
        alice.child.baby_supplies = (RUB)(alice.child.baby_supplies * (1.0f + child_inf / 100.0f));
        alice.child.baby_gear = (RUB)(alice.child.baby_gear * (1.0f + child_inf / 100.0f));
        alice.child.clothes = (RUB)(alice.child.clothes * (1.0f + child_inf / 100.0f));
        alice.child.food = (RUB)(alice.child.food * (1.0f + child_inf / 100.0f));
        alice.child.education = (RUB)(alice.child.education * (1.0f + child_inf / 100.0f));
        alice.child.entertainment = (RUB)(alice.child.entertainment * (1.0f + child_inf / 100.0f));
        alice.child.childcare = (RUB)(alice.child.childcare * (1.0f + child_inf / 100.0f));
        alice.child.housing = (RUB)(alice.child.housing * (1.0f + child_inf / 100.0f));
        alice.child.transport = (RUB)(alice.child.transport * (1.0f + child_inf / 100.0f));
        alice.child.special_events = (RUB)(alice.child.special_events * (1.0f + child_inf / 100.0f));
        alice.child.monthly_allowance = (RUB)(alice.child.monthly_allowance * (1.0f + child_inf / 100.0f));
    }
}

void alice_cat_expenses( int month, int year) 
{
    if (!alice.hascat) return;

    RUB total = 0;
    total += alice.cat.cfood;

    if (month % 2 == 0) {
        total += alice.cat.treats;         
    }

    if (month % 3 == 0) {
        total += alice.cat.toys;
        total += alice.cat.dental_treats;      
    }

    if (month % 4 == 0) {
        total += alice.cat.cvet;
        total += alice.cat.vitamins;       
    }
    
    if (month  == 1) {
        total += alice.cat.tray;
        total += alice.cat.house_bed;
        total += alice.cat.scratching_post;
        total += alice.cat.carrier;      
    }

    alice.bank.account_rub -= total;
    alicestats.pets += total;

    if (month == 12) {
        float pets_inf = year == 2026 ? 10.0f : year == 2027 ? 10.5f : year == 2028 ? 11.0f : 9.5f;
        alice.cat.cfood = (RUB)(alice.cat.cfood * (1.0f + pets_inf / 100.0f));
        alice.cat.cvet = (RUB)(alice.cat.cvet * (1.0f + pets_inf / 100.0f));
        alice.cat.toys = (RUB)(alice.cat.toys * (1.0f + pets_inf / 100.0f));
        alice.cat.tray = (RUB)(alice.cat.tray * (1.0f + pets_inf / 100.0f));
        alice.cat.house_bed = (RUB)(alice.cat.house_bed * (1.0f + pets_inf / 100.0f));
        alice.cat.scratching_post = (RUB)(alice.cat.scratching_post * (1.0f + pets_inf / 100.0f));
        alice.cat.vitamins = (RUB)(alice.cat.vitamins * (1.0f + pets_inf / 100.0f));
        alice.cat.treats = (RUB)(alice.cat.treats * (1.0f + pets_inf / 100.0f));
        alice.cat.carrier = (RUB)(alice.cat.carrier * (1.0f + pets_inf / 100.0f));
        alice.cat.dental_treats = (RUB)(alice.cat.dental_treats * (1.0f + pets_inf / 100.0f));
    }
}

void alice_dog_expenses(int month,int year) 
{
    if (!alice.hasdog) return;

    RUB total = 0;
    total += alice.dog.dfood;

    if (month % 2 == 0) {
        total += alice.dog.allergy_meds;
    }

    if (month % 3 == 0) {
        total += alice.dog.toys;
        total += alice.dog.teeth_cleaning;
    }

    if (month % 4 == 0) {
        total += alice.dog.vet;
        total += alice.dog.vitamins;
    }

    if (month == 3) {
        total += alice.dog.vaccines;
    }

    if (month == 1) {
        total += alice.dog.bed;
        total += alice.dog.leash;
    }
    
    alice.bank.account_rub -= total;
    alicestats.pets += total;

    if (month == 12) {
        float pets_inf = year == 2026 ? 10.0f : year == 2027 ? 10.5f : year == 2028 ? 11.0f : 9.5f;
        alice.dog.dfood = (RUB)(alice.dog.dfood * (1.0f + pets_inf / 100.0f));
        alice.dog.vet = (RUB)(alice.dog.vet * (1.0f + pets_inf / 100.0f));
        alice.dog.vaccines = (RUB)(alice.dog.vaccines * (1.0f + pets_inf / 100.0f));
        alice.dog.teeth_cleaning = (RUB)(alice.dog.teeth_cleaning * (1.0f + pets_inf / 100.0f));
        alice.dog.toys = (RUB)(alice.dog.toys * (1.0f + pets_inf / 100.0f));
        alice.dog.bed = (RUB)(alice.dog.bed * (1.0f + pets_inf / 100.0f));
        alice.dog.leash = (RUB)(alice.dog.leash * (1.0f + pets_inf / 100.0f));
        alice.dog.vitamins = (RUB)(alice.dog.vitamins * (1.0f + pets_inf / 100.0f));
        alice.dog.allergy_meds = (RUB)(alice.dog.allergy_meds * (1.0f + pets_inf / 100.0f));
    }
}

void alice_entertainment_expenses(int month, int year)
{
    RUB total = 0;

    if (month % 2 == 0) {
        total += alice.entertainment.cinema;
        total += alice.entertainment.bowling;
    }

    if (month % 3 == 0) {
        total += alice.entertainment.theater;
        total += alice.entertainment.concerts;
        total += alice.entertainment.quests;
        total += alice.entertainment.restaurants;
        total += alice.entertainment.museums;
    }

    if (month % 4 == 0) {
        total += alice.entertainment.bars;
        total += alice.entertainment.hookah;
    }

    if (month % 5 == 0) {
        total += alice.entertainment.board_games;
        total += alice.entertainment.game_purchases;
    }

    total += alice.entertainment.alcohol;
    total += alice.entertainment.gaming_subscriptions;
    total += alice.entertainment.cigarettes;
    total += alice.entertainment.vape;

    alice.bank.account_rub -= total;
    alicestats.entertainment += total;
    
    if (month == 12) {
        float ent_inf = year == 2026 ? 9.0f : year == 2027 ? 9.5f : year == 2028 ? 10.0f : 8.5f;
        alice.entertainment.cinema = (RUB)(alice.entertainment.cinema * (1.0f + ent_inf / 100.0f));
        alice.entertainment.theater = (RUB)(alice.entertainment.theater * (1.0f + ent_inf / 100.0f));
        alice.entertainment.concerts = (RUB)(alice.entertainment.concerts * (1.0f + ent_inf / 100.0f));
        alice.entertainment.museums = (RUB)(alice.entertainment.museums * (1.0f + ent_inf / 100.0f));
        alice.entertainment.quests = (RUB)(alice.entertainment.quests * (1.0f + ent_inf / 100.0f));
        alice.entertainment.bowling = (RUB)(alice.entertainment.bowling * (1.0f + ent_inf / 100.0f));
        alice.entertainment.restaurants = (RUB)(alice.entertainment.restaurants * (1.0f + ent_inf / 100.0f));
        alice.entertainment.bars = (RUB)(alice.entertainment.bars * (1.0f + ent_inf / 100.0f));
        alice.entertainment.hookah = (RUB)(alice.entertainment.hookah * (1.0f + ent_inf / 100.0f));
        alice.entertainment.alcohol = (RUB)(alice.entertainment.alcohol * (1.0f + ent_inf / 100.0f));
        alice.entertainment.cigarettes = (RUB)(alice.entertainment.cigarettes * (1.0f + ent_inf / 100.0f));
        alice.entertainment.vape = (RUB)(alice.entertainment.vape * (1.0f + ent_inf / 100.0f));
        alice.entertainment.gaming_subscriptions = (RUB)(alice.entertainment.gaming_subscriptions * (1.0f + ent_inf / 100.0f));
        alice.entertainment.game_purchases = (RUB)(alice.entertainment.game_purchases * (1.0f + ent_inf / 100.0f));
        alice.entertainment.board_games = (RUB)(alice.entertainment.board_games * (1.0f + ent_inf / 100.0f));
    }
}

void alice_utilities_expenses(int month, int year)
{
    RUB total = 0;
    total += alice.utilities.internet;
    total += alice.utilities.mobile_family;
    total += alice.utilities.tv_subscription;
    total += alice.utilities.streaming_video;
    total += alice.utilities.streaming_music;
    total += alice.utilities.cloud_storage;
    total += alice.utilities.vpn;
    total += alice.utilities.antivirus;

    alice.bank.account_rub -= total;
    alicestats.utilities += total;

    if (month == 12) {
        float util_inf = year == 2026 ? 7.5f : year == 2027 ? 8.0f : year == 2028 ? 8.5f : 7.5f;
        alice.utilities.internet = (RUB)(alice.utilities.internet * (1.0f + util_inf / 100.0f));
        alice.utilities.mobile_family = (RUB)(alice.utilities.mobile_family * (1.0f + util_inf / 100.0f));
        alice.utilities.tv_subscription = (RUB)(alice.utilities.tv_subscription * (1.0f + util_inf / 100.0f));
        alice.utilities.streaming_video = (RUB)(alice.utilities.streaming_video * (1.0f + util_inf / 100.0f));
        alice.utilities.streaming_music = (RUB)(alice.utilities.streaming_music * (1.0f + util_inf / 100.0f));
        alice.utilities.cloud_storage = (RUB)(alice.utilities.cloud_storage * (1.0f + util_inf / 100.0f));
        alice.utilities.vpn = (RUB)(alice.utilities.vpn * (1.0f + util_inf / 100.0f));
        alice.utilities.antivirus = (RUB)(alice.utilities.antivirus * (1.0f + util_inf / 100.0f));
    }
}

void alice_gifts_expenses(int month, int year)
{
    RUB total = 0;

    if (month == 1) total += alice.gifts.new_year;
    if (month == 2) total += alice.gifts.february_23;
    if (month == 3) total += alice.gifts.march_8;
    if (month == 6 || month == 12) total += alice.gifts.birthday_family;
    if (month == 9) total += alice.gifts.children_birthdays;
    if (month == 7) total += alice.gifts.birthday_friends;
    if (month == 4) total += alice.gifts.birthday_colleagues;
    total += alice.gifts.donations;

    alice.bank.account_rub -= total;
    alicestats.gifts += total;
    
    if (month == 12) {
        float gifts_inf = year == 2026 ? 7.0f : year == 2027 ? 7.5f : year == 2028 ? 8.0f : 7.0f;
        alice.gifts.birthday_family = (RUB)(alice.gifts.birthday_family * (1.0f + gifts_inf / 100.0f));
        alice.gifts.birthday_friends = (RUB)(alice.gifts.birthday_friends * (1.0f + gifts_inf / 100.0f));
        alice.gifts.birthday_colleagues = (RUB)(alice.gifts.birthday_colleagues * (1.0f + gifts_inf / 100.0f));
        alice.gifts.new_year = (RUB)(alice.gifts.new_year * (1.0f + gifts_inf / 100.0f));
        alice.gifts.march_8 = (RUB)(alice.gifts.march_8 * (1.0f + gifts_inf / 100.0f));
        alice.gifts.february_23 = (RUB)(alice.gifts.february_23 * (1.0f + gifts_inf / 100.0f));
        alice.gifts.children_birthdays = (RUB)(alice.gifts.children_birthdays * (1.0f + gifts_inf / 100.0f));
        alice.gifts.donations = (RUB)(alice.gifts.donations * (1.0f + gifts_inf / 100.0f));
    }
}

void alice_healthcare_expenses(int month, int year)
{
    RUB total = 0;

    total += alice.healthcare.vitamins_general;
    total += alice.healthcare.regular_meds;

    if (month == 1) total += alice.healthcare.medical_insurance;
    if (month == 6) total += alice.healthcare.psychologist;
    if (month == 8) total += alice.healthcare.break_a_leg;
    if (month % 2 == 0) total += alice.healthcare.fitness_club;
    if (month % 3 == 0) {
        total += alice.healthcare.massage;
        total += alice.healthcare.yoga;
    }

    alice.bank.account_rub -= total;
    alicestats.healthcare += total;
    
    if (month == 12) {
        float health_inf = year == 2026 ? 11.0f : year == 2027 ? 11.5f : year == 2028 ? 12.0f : 10.0f;
        alice.healthcare.medical_insurance = (RUB)(alice.healthcare.medical_insurance * (1.0f + health_inf / 100.0f));
        alice.healthcare.fitness_club = (RUB)(alice.healthcare.fitness_club * (1.0f + health_inf / 100.0f));
        alice.healthcare.yoga = (RUB)(alice.healthcare.yoga * (1.0f + health_inf / 100.0f));
        alice.healthcare.massage = (RUB)(alice.healthcare.massage * (1.0f + health_inf / 100.0f));
        alice.healthcare.psychologist = (RUB)(alice.healthcare.psychologist * (1.0f + health_inf / 100.0f));
        alice.healthcare.vitamins_general = (RUB)(alice.healthcare.vitamins_general * (1.0f + health_inf / 100.0f));
        alice.healthcare.regular_meds = (RUB)(alice.healthcare.regular_meds * (1.0f + health_inf / 100.0f));
        alice.healthcare.break_a_leg = (RUB)(alice.healthcare.break_a_leg * (1.0f + health_inf / 100.0f));
    }
}

void alice_education_expenses(int month, int year) 
{
    RUB total = 0;

    total += alice.education.online_subscriptions;
    total += alice.education.software_licenses;

    if (month == 1 || month == 8) {
        total += alice.education.professional_courses;
        total += alice.education.books;
    }
    if (month == 9) total += alice.education.language_courses;
    if (month == 3) total += alice.education.mba;
    if (month == 5) total += alice.education.coaching;
    if (month == 7) total += alice.education.conferences;
    
    alice.bank.account_rub -= total;
    alicestats.education += total;
    
    if (month == 12) {
        float edu_inf = year == 2026 ? 10.0f : year == 2027 ? 10.5f : year == 2028 ? 11.0f : 9.5f;
        alice.education.professional_courses = (RUB)(alice.education.professional_courses * (1.0f + edu_inf / 100.0f));
        alice.education.language_courses = (RUB)(alice.education.language_courses * (1.0f + edu_inf / 100.0f));
        alice.education.mba = (RUB)(alice.education.mba * (1.0f + edu_inf / 100.0f));
        alice.education.books = (RUB)(alice.education.books * (1.0f + edu_inf / 100.0f));
        alice.education.online_subscriptions = (RUB)(alice.education.online_subscriptions * (1.0f + edu_inf / 100.0f));
        alice.education.conferences = (RUB)(alice.education.conferences * (1.0f + edu_inf / 100.0f));
        alice.education.coaching = (RUB)(alice.education.coaching * (1.0f + edu_inf / 100.0f));
        alice.education.software_licenses = (RUB)(alice.education.software_licenses * (1.0f + edu_inf / 100.0f));
    }
}

void alice_wedding(int month, int year) 
{
    if (not family.isMarried) {
        srand(time(0) + clock());
        int n = rand() % 10;
        if (n == 7)
        {
            family.isMarried = true;
            family.hasChildren = true;
            family.child_birth_month = month;
            family.child_birth_year = year;
        }
        RUB total = 0;
        total += alice.wedding.dress;
        total += alice.wedding.suit;
        total += alice.wedding.venue;
        total += alice.wedding.catering;
        total += alice.wedding.cake;
        total += alice.wedding.photographer;
        total += alice.wedding.music;
        total += alice.wedding.flowers;
        total += alice.wedding.rings;
        total += alice.wedding.transport;
        total += alice.wedding.honeymoon;

        alice.bank.account_rub -= total;
        alicestats.wedding += total;
    }
    
    if (month == 12) {
        float wedding_inf = year == 2026 ? 10.0f : year == 2027 ? 11.0f : year == 2028 ? 12.0f : 10.0f;
        alice.wedding.dress = (RUB)(alice.wedding.dress * (1.0f + wedding_inf / 100.0f));
        alice.wedding.suit = (RUB)(alice.wedding.suit * (1.0f + wedding_inf / 100.0f));
        alice.wedding.venue = (RUB)(alice.wedding.venue * (1.0f + wedding_inf / 100.0f));
        alice.wedding.catering = (RUB)(alice.wedding.catering * (1.0f + wedding_inf / 100.0f));
        alice.wedding.cake = (RUB)(alice.wedding.cake * (1.0f + wedding_inf / 100.0f));
        alice.wedding.photographer = (RUB)(alice.wedding.photographer * (1.0f + wedding_inf / 100.0f));
        alice.wedding.music = (RUB)(alice.wedding.music * (1.0f + wedding_inf / 100.0f));
        alice.wedding.flowers = (RUB)(alice.wedding.flowers * (1.0f + wedding_inf / 100.0f));
        alice.wedding.rings = (RUB)(alice.wedding.rings * (1.0f + wedding_inf / 100.0f));
        alice.wedding.transport = (RUB)(alice.wedding.transport * (1.0f + wedding_inf / 100.0f));
        alice.wedding.honeymoon = (RUB)(alice.wedding.honeymoon * (1.0f + wedding_inf / 100.0f));
    }
}

void alice_investments(int month, int year) 
{
    RUB invest_amount = alice.salary * 0.10;
    if (month == 1 || month>4 ) {
        alice.investments.crypto += 0.5 * invest_amount;
        alice.investments.gold += 0.5 * invest_amount;
    }

    if (month == 2) {
        alice.investments.stocks += 0.5 * invest_amount;
        alice.investments.bonds += 0.5 * invest_amount;
    }

    if (month == 3) {
        alice.investments.etf += 0.5 * invest_amount;
        alice.investments.mutual_funds += 0.5 * invest_amount;
    }

    if (month == 4) {
        alice.investments.real_estate_fund= 0.5 * invest_amount;
        alice.investments.startup_investment += 0.5 * invest_amount;
    }
    alice.bank.account_rub -= invest_amount;
    alicestats.investments += invest_amount;

    RUB stocks_return = alice.investments.stocks * 0.01;
    alice.investments.stocks += stocks_return;

    RUB bonds_return = alice.investments.bonds * 0.008;
    alice.investments.bonds += bonds_return;

    RUB crypto_return = alice.investments.crypto * 0.1;
    alice.investments.crypto += crypto_return;

    RUB gold_return = alice.investments.gold * 0.05;
    alice.investments.gold += gold_return;

    RUB etf_return = alice.investments.etf * 0.0012;
    alice.investments.etf += etf_return;

    RUB fund_return = alice.investments.mutual_funds * 0.03;
    alice.investments.mutual_funds += fund_return;

    RUB est_return = alice.investments.real_estate_fund * 0.12;
    alice.investments.real_estate_fund += est_return;

    RUB stup_return = alice.investments.startup_investment * 0.2;
    alice.investments.startup_investment += stup_return;

    alice.investments.total = alice.investments.gold + alice.investments.crypto + alice.investments.stocks +
        alice.investments.startup_investment + alice.investments.real_estate_fund + alice.investments.mutual_funds + 
        alice.investments.etf + alice.investments.bonds;
}

void alice_deposit_interest() 
{
    alice.bank.deposit_rub += 0.05 * alice.salary;
    alice.bank.account_rub -= 0.05 * alice.salary;

    if (alice.bank.deposit_rub > 0) {
        RUB interest = alice.bank.deposit_rub * 0.12 / 12;
        alice.bank.deposit_rub += interest;
        alicestats.total_income += interest;
    }
}



void print_alicedetailed_report(int start_year, int start_month, int end_year, int end_month) 
{
    printf("\n\n");
    printf("========================================\n");
    printf("         ДЕТАЛЬНЫЙ ФИНАНСОВЫЙ ОТЧЁТ АЛИСЫ\n");
    printf("         Период: %d.%d - %d.%d\n", start_month, start_year, end_month, end_year);
    printf("========================================\n\n");

    alicestats.total_expenses = alicestats.food + alicestats.housing + alicestats.car + alicestats.transport +
        alicestats.pets + alicestats.trips +
        alicestats.entertainment + alicestats.utilities + alicestats.gifts + alicestats.healthcare + alicestats.education +
        alicestats.wedding + alicestats.child + alicestats.investments;
    alicestats.total_income += alice.investments.total;
    RUB net = alicestats.total_income - alicestats.total_expenses;

    printf("ОБЩИЙ ДОХОД:       %lld RUB\n", alicestats.total_income);
    printf("ОБЩИЕ РАСХОДЫ:     %lld RUB\n", alicestats.total_expenses);
    printf("ЧИСТЫЙ ДОХОД:      %lld RUB\n", net);
    printf("\n");

    printf("========================================\n");
    printf("РАСХОДЫ ПО КАТЕГОРИЯМ:\n");
    printf("========================================\n");
    printf("Продукты и доставка:    %lld RUB\n", alicestats.food);
    printf("Жильё (аренда, ЖКУ, ремонт): %lld RUB\n", alicestats.housing);
    printf("Автомобиль:             %lld RUB\n", alicestats.car);
    printf("Транспорт (такси и пр.): %lld RUB\n", alicestats.transport);
    printf("Питомцы (кошка/собака): %lld RUB\n", alicestats.pets);
    printf("Путешествия:            %lld RUB\n", alicestats.trips);
    printf("Развлечения:            %lld RUB\n", alicestats.entertainment);
    printf("Услуги (интернет, связь): %lld RUB\n", alicestats.utilities);
    printf("Подарки и пожертвования: %lld RUB\n", alicestats.gifts);
    printf("Здоровье (страховка, спорт): %lld RUB\n", alicestats.healthcare);
    printf("Образование:            %lld RUB\n", alicestats.education);

    if (alicestats.wedding > 0)
        printf("Свадьба:                %lld RUB\n", alicestats.wedding);

    if (alicestats.child > 0)
        printf("Ребёнок:                %lld RUB\n", alicestats.child);

    printf("Инвестиции:             %lld RUB\n", alicestats.investments);
    printf("\n");
}


void alex_salary(int month)
{
    alex.bank.account_rub += alex.salary;
    alexstats.total_income += alex.salary;

    RUB tax = alex.salary * 0.13;
    alex.bank.account_rub -= tax;

    if (month == 3) {
        alex.salary *= 1.2;
    }

    if (month == 12) {
        alex.bonus = alex.salary * 1.5;
        alex.bank.account_rub += alex.bonus;
        alexstats.total_income += alex.bonus;
    }
}

void alex_food_expenses(int month, int year)
{
    alex.bank.account_rub -= alex.food;
    alexstats.food += alex.food;

    if (month % 2 == 0) {
        alex.bank.account_rub -= alex.food_delivery;
        alexstats.food += alex.food_delivery;
    }

    if (month == 12) {
        float food_inf = year == 2026 ? 12.5f : (year == 2027 ? 14.0f : (year == 2028 ? 13.0f : 10.0f));
        alex.food = (RUB)(alex.food * (1.0f + food_inf / 100.0f));
        alex.food_delivery = (RUB)(alex.food_delivery * (1.0f + food_inf / 100.0f));
    }
}

void alex_housing_expenses(int month, int year)
{
    alex.bank.account_rub -= alex.home.rent;
    alex.bank.account_rub -= alex.home.electricity;
    alex.bank.account_rub -= alex.home.heating;
    alex.bank.account_rub -= alex.home.water;
    alex.bank.account_rub -= alex.home.gas;
    alex.bank.account_rub -= alex.home.garbage;
    alex.bank.account_rub -= alex.home.intercom;

    alexstats.housing += alex.home.rent + alex.home.electricity + alex.home.heating +
        alex.home.water + alex.home.gas + alex.home.garbage + alex.home.intercom;

    if (month % 3 == 0) {
        alex.bank.account_rub -= alex.home.farm;
        alexstats.housing += alex.home.farm + alex.home.cleaning;

        alex.bank.account_rub -= alex.home.cleaning;
    }

    if (month == 6 || month == 12) {
        alex.bank.account_rub -= alex.home.repair;

        alexstats.housing += alex.home.repair;
    }

    if (month == 5 || month == 11) {
        alex.bank.account_rub -= alex.home.furniture;

        alexstats.housing += alex.home.furniture;
    }

    if (month == 12) {
        float home_inf = year == 2026 ? 8.5f : year == 2027 ? 9.0f : year == 2028 ? 9.5f : 8.5f;
        alex.home.rent = (RUB)(alex.home.rent * (1.0f + home_inf / 100.0f));
        alex.home.electricity = (RUB)(alex.home.electricity * (1.0f + home_inf / 100.0f));
        alex.home.heating = (RUB)(alex.home.heating * (1.0f + home_inf / 100.0f));
        alex.home.water = (RUB)(alex.home.water * (1.0f + home_inf / 100.0f));
        alex.home.gas = (RUB)(alex.home.gas * (1.0f + home_inf / 100.0f));
        alex.home.garbage = (RUB)(alex.home.garbage * (1.0f + home_inf / 100.0f));
        alex.home.intercom = (RUB)(alex.home.intercom * (1.0f + home_inf / 100.0f));
        alex.home.farm = (RUB)(alex.home.farm * (1.0f + home_inf / 100.0f));
        alex.home.cleaning = (RUB)(alex.home.cleaning * (1.0f + home_inf / 100.0f));
        alex.home.repair = (RUB)(alex.home.repair * (1.0f + home_inf / 100.0f));
        alex.home.furniture = (RUB)(alex.home.furniture * (1.0f + home_inf / 100.0f));
    }
}

void alex_car_expenses(int month, int year)
{
    RUB total = 0;
    total += alex.car.gas;
    total += alex.car.toll_roads;
    total += alex.car.parking_home;
    total += alex.car.parking_work;
    total += alex.car.fines;
    total += alex.car.fines;

    if (month % 2 == 0) {
        total += alex.car.washing;
    }

    if (month == 10) {
        total += alex.car.tires_winter;
        total += alex.car.diagnostics;
    }

    if (month == 4) {
        total += alex.car.tires_summer;
        total += alex.car.diagnostics;
    }

    if (month == 6 || month == 12) {
        total += alex.car.oil_change;
        total += alex.car.antifreeze;
    }

    if (month == 11) {
        total += alex.car.insurance;
        total += alex.car.repair;
    }

    alex.bank.account_rub -= total;
    alexstats.car += total;

    if (month == 12) {
        float car_inf = year == 2026 ? 6.5f : year == 2027 ? 7.0f : year == 2028 ? 8.0f : 7.0f;
        alex.car.gas = (RUB)(alex.car.gas * (1.0f + car_inf / 100.0f));
        alex.car.toll_roads = (RUB)(alex.car.toll_roads * (1.0f + car_inf / 100.0f));
        alex.car.repair = (RUB)(alex.car.repair * (1.0f + car_inf / 100.0f));
        alex.car.oil_change = (RUB)(alex.car.oil_change * (1.0f + car_inf / 100.0f));
        alex.car.antifreeze = (RUB)(alex.car.antifreeze * (1.0f + car_inf / 100.0f));
        alex.car.tires_winter = (RUB)(alex.car.tires_winter * (1.0f + car_inf / 100.0f));
        alex.car.tires_summer = (RUB)(alex.car.tires_summer * (1.0f + car_inf / 100.0f));
        alex.car.diagnostics = (RUB)(alex.car.diagnostics * (1.0f + car_inf / 100.0f));
        alex.car.insurance = (RUB)(alex.car.insurance * (1.0f + car_inf / 100.0f));
        alex.car.washing = (RUB)(alex.car.washing * (1.0f + car_inf / 100.0f));
        alex.car.parking_home = (RUB)(alex.car.parking_home * (1.0f + car_inf / 100.0f));
        alex.car.parking_work = (RUB)(alex.car.parking_work * (1.0f + car_inf / 100.0f));
        alex.car.fines = (RUB)(alex.car.fines * (1.0f + car_inf / 100.0f));
    }

}

void alex_transport_expenses(int month, int year)
{
    alex.bank.account_rub -= alex.transport.pub;
    alexstats.transport += alex.transport.pub;

    if (month % 2 == 0) {
        alex.bank.account_rub -= alex.transport.taxi;
        alexstats.transport += alex.transport.taxi;
    }

    if (month % 3 == 0) {
        alex.bank.account_rub -= alex.transport.carsharing;
        alexstats.transport += alex.transport.carsharing;
    }

    if (month == 12) {
        float transport_inf = year == 2026 ? 9.0f : year == 2027 ? 9.5f : year == 2028 ? 10.0f : 8.5f;
        alex.transport.taxi = (RUB)(alex.transport.taxi * (1.0f + transport_inf / 100.0f));
        alex.transport.carsharing = (RUB)(alex.transport.carsharing * (1.0f + transport_inf / 100.0f));
        alex.transport.pub = (RUB)(alex.transport.pub * (1.0f + transport_inf / 100.0f));
    }
}

void alex_trip_expenses(int month, int year)
{
    if (month != 6) return;

    RUB total = 0;
    total += alex.trip.flight;
    total += alex.trip.hotel;
    total += alex.trip.meals;
    total += alex.trip.excursions;
    total += alex.trip.transport;
    total += alex.trip.insurance;
    total += alex.trip.visa;
    total += alex.trip.souvenirs;
    total += alex.trip.shopping;
    total += alex.trip.entertainment;

    alex.bank.account_rub -= total;
    alexstats.trips += total;

    if (month == 12) {
        float trip_inf = year == 2026 ? 11.0f : year == 2027 ? 12.0f : year == 2028 ? 10.5f : 10.0f;
        alex.trip.flight = (RUB)(alex.trip.flight * (1.0f + trip_inf / 100.0f));
        alex.trip.hotel = (RUB)(alex.trip.hotel * (1.0f + trip_inf / 100.0f));
        alex.trip.meals = (RUB)(alex.trip.meals * (1.0f + trip_inf / 100.0f));
        alex.trip.excursions = (RUB)(alex.trip.excursions * (1.0f + trip_inf / 100.0f));
        alex.trip.transport = (RUB)(alex.trip.transport * (1.0f + trip_inf / 100.0f));
        alex.trip.insurance = (RUB)(alex.trip.insurance * (1.0f + trip_inf / 100.0f));
        alex.trip.visa = (RUB)(alex.trip.visa * (1.0f + trip_inf / 100.0f));
        alex.trip.souvenirs = (RUB)(alex.trip.souvenirs * (1.0f + trip_inf / 100.0f));
        alex.trip.entertainment = (RUB)(alex.trip.entertainment * (1.0f + trip_inf / 100.0f));
        alex.trip.shopping = (RUB)(alex.trip.shopping * (1.0f + trip_inf / 100.0f));

    }
}


void alex_child_expenses(int month, int year, bool has_child, int child_age)
{
    if (!has_child) return;

    RUB total = 0;

    if (child_age < 1) {
        total += alex.child.medical / 12;
        total += alex.child.baby_supplies;
        total += alex.child.baby_gear / 12;
        total += alex.child.clothes / 12;
        total += alex.child.food;
        total += alex.child.entertainment / 12;

        if (month == family.child_birth_month) {
            total += alex.child.special_events;
        }
    }
    else if (child_age >= 1 && child_age < 3) {
        total += alex.child.medical / 6;
        total += alex.child.baby_supplies;
        total += alex.child.clothes / 12;
        total += alex.child.food;
        total += alex.child.entertainment / 6;

        if (month == family.child_birth_month) {
            total += alex.child.special_events;
        }
    }
    else if (child_age >= 3 && child_age < 7) {
        total += alex.child.education / 12;
        total += alex.child.clothes / 12;
        total += alex.child.medical / 12;
        total += alex.child.entertainment / 6;
        total += alex.child.monthly_allowance;

        if (month == family.child_birth_month) {
            total += alex.child.special_events;
        }

        if (month == 6) {
            total += alex.child.entertainment / 4;
        }
    }
    else if (child_age >= 7 && child_age < 12) {
        total += alex.child.education / 4;
        total += alex.child.clothes / 12;
        total += alex.child.medical / 12;
        total += alex.child.entertainment / 6;
        total += alex.child.monthly_allowance;

        if (month == 8) {
            total += alex.child.education / 6;
        }

        if (month == family.child_birth_month) {
            total += alex.child.special_events;
        }

        if (month == 6) {
            total += alex.child.entertainment / 3;
        }
    }
    else if (child_age >= 12 && child_age < 18) {
        total += alex.child.education / 6;
        total += alex.child.clothes / 12;
        total += alex.child.medical / 6;
        total += alex.child.entertainment / 4;
        total += alex.child.monthly_allowance * 1.5f;
        total += alex.child.transport / 12;

        if (month == 8) {
            total += alex.child.education / 8;
        }

        if (month == family.child_birth_month) {
            total += alex.child.special_events;
        }

        if (child_age == 18 && month == 1) {
            total += alex.child.transport;
        }
    }
    else if (child_age >= 18) {
        total += alex.child.education / 12;
        total += alex.child.housing;
        total += alex.child.monthly_allowance;
        total += alex.child.clothes / 12;

        if (month == 8) {
            total += alex.child.education / 6;
            total += alex.child.entertainment / 4;
        }

        if (month == family.child_birth_month) {
            total += alex.child.special_events;
        }
    }

    alex.bank.account_rub -= total;
    alexstats.child += total;

    if (month == 12) {
        float child_inf = year == 2026 ? 9.0f : year == 2027 ? 9.5f : year == 2028 ? 10.0f : 9.0f;
        alex.child.medical = (RUB)(alex.child.medical * (1.0f + child_inf / 100.0f));
        alex.child.baby_supplies = (RUB)(alex.child.baby_supplies * (1.0f + child_inf / 100.0f));
        alex.child.baby_gear = (RUB)(alex.child.baby_gear * (1.0f + child_inf / 100.0f));
        alex.child.clothes = (RUB)(alex.child.clothes * (1.0f + child_inf / 100.0f));
        alex.child.food = (RUB)(alex.child.food * (1.0f + child_inf / 100.0f));
        alex.child.education = (RUB)(alex.child.education * (1.0f + child_inf / 100.0f));
        alex.child.entertainment = (RUB)(alex.child.entertainment * (1.0f + child_inf / 100.0f));
        alex.child.childcare = (RUB)(alex.child.childcare * (1.0f + child_inf / 100.0f));
        alex.child.housing = (RUB)(alex.child.housing * (1.0f + child_inf / 100.0f));
        alex.child.transport = (RUB)(alex.child.transport * (1.0f + child_inf / 100.0f));
        alex.child.special_events = (RUB)(alex.child.special_events * (1.0f + child_inf / 100.0f));
        alex.child.monthly_allowance = (RUB)(alex.child.monthly_allowance * (1.0f + child_inf / 100.0f));
    }
}

void alex_cat_expenses(int month, int year)
{
    if (!alex.hascat) return;

    RUB total = 0;
    total += alex.cat.cfood;

    if (month % 2 == 0) {
        total += alex.cat.treats;
    }

    if (month % 3 == 0) {
        total += alex.cat.toys;
        total += alex.cat.dental_treats;
    }

    if (month % 4 == 0) {
        total += alex.cat.cvet;
        total += alex.cat.vitamins;
    }

    if (month == 1) {
        total += alex.cat.tray;
        total += alex.cat.house_bed;
        total += alex.cat.scratching_post;
        total += alex.cat.carrier;
    }

    alex.bank.account_rub -= total;
    alexstats.pets += total;

    if (month == 12) {
        float pets_inf = year == 2026 ? 10.0f : year == 2027 ? 10.5f : year == 2028 ? 11.0f : 9.5f;
        alex.cat.cfood = (RUB)(alex.cat.cfood * (1.0f + pets_inf / 100.0f));
        alex.cat.cvet = (RUB)(alex.cat.cvet * (1.0f + pets_inf / 100.0f));
        alex.cat.toys = (RUB)(alex.cat.toys * (1.0f + pets_inf / 100.0f));
        alex.cat.tray = (RUB)(alex.cat.tray * (1.0f + pets_inf / 100.0f));
        alex.cat.house_bed = (RUB)(alex.cat.house_bed * (1.0f + pets_inf / 100.0f));
        alex.cat.scratching_post = (RUB)(alex.cat.scratching_post * (1.0f + pets_inf / 100.0f));
        alex.cat.vitamins = (RUB)(alex.cat.vitamins * (1.0f + pets_inf / 100.0f));
        alex.cat.treats = (RUB)(alex.cat.treats * (1.0f + pets_inf / 100.0f));
        alex.cat.carrier = (RUB)(alex.cat.carrier * (1.0f + pets_inf / 100.0f));
        alex.cat.dental_treats = (RUB)(alex.cat.dental_treats * (1.0f + pets_inf / 100.0f));
    }
}

void alex_dog_expenses(int month, int year)
{
    if (!alex.hasdog) return;

    RUB total = 0;
    total += alex.dog.dfood;

    if (month % 2 == 0) {
        total += alex.dog.allergy_meds;
    }

    if (month % 3 == 0) {
        total += alex.dog.toys;
        total += alex.dog.teeth_cleaning;
    }

    if (month % 4 == 0) {
        total += alex.dog.vet;
        total += alex.dog.vitamins;
    }

    if (month == 3) {
        total += alex.dog.vaccines;
    }

    if (month == 1) {
        total += alex.dog.bed;
        total += alex.dog.leash;
    }

    alex.bank.account_rub -= total;
    alexstats.pets += total;

    if (month == 12) {
        float pets_inf = year == 2026 ? 10.0f : year == 2027 ? 10.5f : year == 2028 ? 11.0f : 9.5f;
        alex.dog.dfood = (RUB)(alex.dog.dfood * (1.0f + pets_inf / 100.0f));
        alex.dog.vet = (RUB)(alex.dog.vet * (1.0f + pets_inf / 100.0f));
        alex.dog.vaccines = (RUB)(alex.dog.vaccines * (1.0f + pets_inf / 100.0f));
        alex.dog.teeth_cleaning = (RUB)(alex.dog.teeth_cleaning * (1.0f + pets_inf / 100.0f));
        alex.dog.toys = (RUB)(alex.dog.toys * (1.0f + pets_inf / 100.0f));
        alex.dog.bed = (RUB)(alex.dog.bed * (1.0f + pets_inf / 100.0f));
        alex.dog.leash = (RUB)(alex.dog.leash * (1.0f + pets_inf / 100.0f));
        alex.dog.vitamins = (RUB)(alex.dog.vitamins * (1.0f + pets_inf / 100.0f));
        alex.dog.allergy_meds = (RUB)(alex.dog.allergy_meds * (1.0f + pets_inf / 100.0f));
    }
}

void alex_entertainment_expenses(int month, int year)
{
    RUB total = 0;

    if (month % 2 == 0) {
        total += alex.entertainment.cinema;
        total += alex.entertainment.bowling;
    }

    if (month % 3 == 0) {
        total += alex.entertainment.theater;
        total += alex.entertainment.concerts;
        total += alex.entertainment.quests;
        total += alex.entertainment.restaurants;
        total += alex.entertainment.museums;
    }

    if (month % 4 == 0) {
        total += alex.entertainment.bars;
        total += alex.entertainment.hookah;
    }

    if (month % 5 == 0) {
        total += alex.entertainment.board_games;
        total += alex.entertainment.game_purchases;
    }

    total += alex.entertainment.alcohol;
    total += alex.entertainment.gaming_subscriptions;
    total += alex.entertainment.cigarettes;
    total += alex.entertainment.vape;

    alex.bank.account_rub -= total;
    alexstats.entertainment += total;

    if (month == 12) {
        float ent_inf = year == 2026 ? 9.0f : year == 2027 ? 9.5f : year == 2028 ? 10.0f : 8.5f;
        alex.entertainment.cinema = (RUB)(alex.entertainment.cinema * (1.0f + ent_inf / 100.0f));
        alex.entertainment.theater = (RUB)(alex.entertainment.theater * (1.0f + ent_inf / 100.0f));
        alex.entertainment.concerts = (RUB)(alex.entertainment.concerts * (1.0f + ent_inf / 100.0f));
        alex.entertainment.museums = (RUB)(alex.entertainment.museums * (1.0f + ent_inf / 100.0f));
        alex.entertainment.quests = (RUB)(alex.entertainment.quests * (1.0f + ent_inf / 100.0f));
        alex.entertainment.bowling = (RUB)(alex.entertainment.bowling * (1.0f + ent_inf / 100.0f));
        alex.entertainment.restaurants = (RUB)(alex.entertainment.restaurants * (1.0f + ent_inf / 100.0f));
        alex.entertainment.bars = (RUB)(alex.entertainment.bars * (1.0f + ent_inf / 100.0f));
        alex.entertainment.hookah = (RUB)(alex.entertainment.hookah * (1.0f + ent_inf / 100.0f));
        alex.entertainment.alcohol = (RUB)(alex.entertainment.alcohol * (1.0f + ent_inf / 100.0f));
        alex.entertainment.cigarettes = (RUB)(alex.entertainment.cigarettes * (1.0f + ent_inf / 100.0f));
        alex.entertainment.vape = (RUB)(alex.entertainment.vape * (1.0f + ent_inf / 100.0f));
        alex.entertainment.gaming_subscriptions = (RUB)(alex.entertainment.gaming_subscriptions * (1.0f + ent_inf / 100.0f));
        alex.entertainment.game_purchases = (RUB)(alex.entertainment.game_purchases * (1.0f + ent_inf / 100.0f));
        alex.entertainment.board_games = (RUB)(alex.entertainment.board_games * (1.0f + ent_inf / 100.0f));
    }
}

void alex_utilities_expenses(int month, int year)
{
    RUB total = 0;
    total += alex.utilities.internet;
    total += alex.utilities.mobile_family;
    total += alex.utilities.tv_subscription;
    total += alex.utilities.streaming_video;
    total += alex.utilities.streaming_music;
    total += alex.utilities.cloud_storage;
    total += alex.utilities.vpn;
    total += alex.utilities.antivirus;

    alex.bank.account_rub -= total;
    alexstats.utilities += total;

    if (month == 12) {
        float util_inf = year == 2026 ? 7.5f : year == 2027 ? 8.0f : year == 2028 ? 8.5f : 7.5f;
        alex.utilities.internet = (RUB)(alex.utilities.internet * (1.0f + util_inf / 100.0f));
        alex.utilities.mobile_family = (RUB)(alex.utilities.mobile_family * (1.0f + util_inf / 100.0f));
        alex.utilities.tv_subscription = (RUB)(alex.utilities.tv_subscription * (1.0f + util_inf / 100.0f));
        alex.utilities.streaming_video = (RUB)(alex.utilities.streaming_video * (1.0f + util_inf / 100.0f));
        alex.utilities.streaming_music = (RUB)(alex.utilities.streaming_music * (1.0f + util_inf / 100.0f));
        alex.utilities.cloud_storage = (RUB)(alex.utilities.cloud_storage * (1.0f + util_inf / 100.0f));
        alex.utilities.vpn = (RUB)(alex.utilities.vpn * (1.0f + util_inf / 100.0f));
        alex.utilities.antivirus = (RUB)(alex.utilities.antivirus * (1.0f + util_inf / 100.0f));
    }
}

void alex_gifts_expenses(int month, int year)
{
    RUB total = 0;

    if (month == 1) total += alex.gifts.new_year;
    if (month == 2) total += alex.gifts.february_23;
    if (month == 3) total += alex.gifts.march_8;
    if (month == 6 || month == 12) total += alex.gifts.birthday_family;
    if (month == 9) total += alex.gifts.children_birthdays;
    if (month == 7) total += alex.gifts.birthday_friends;
    if (month == 4) total += alex.gifts.birthday_colleagues;
    total += alex.gifts.donations;

    alex.bank.account_rub -= total;
    alexstats.gifts += total;

    if (month == 12) {
        float gifts_inf = year == 2026 ? 7.0f : year == 2027 ? 7.5f : year == 2028 ? 8.0f : 7.0f;
        alex.gifts.birthday_family = (RUB)(alex.gifts.birthday_family * (1.0f + gifts_inf / 100.0f));
        alex.gifts.birthday_friends = (RUB)(alex.gifts.birthday_friends * (1.0f + gifts_inf / 100.0f));
        alex.gifts.birthday_colleagues = (RUB)(alex.gifts.birthday_colleagues * (1.0f + gifts_inf / 100.0f));
        alex.gifts.new_year = (RUB)(alex.gifts.new_year * (1.0f + gifts_inf / 100.0f));
        alex.gifts.march_8 = (RUB)(alex.gifts.march_8 * (1.0f + gifts_inf / 100.0f));
        alex.gifts.february_23 = (RUB)(alex.gifts.february_23 * (1.0f + gifts_inf / 100.0f));
        alex.gifts.children_birthdays = (RUB)(alex.gifts.children_birthdays * (1.0f + gifts_inf / 100.0f));
        alex.gifts.donations = (RUB)(alex.gifts.donations * (1.0f + gifts_inf / 100.0f));
    }
}

void alex_healthcare_expenses(int month, int year)
{
    RUB total = 0;

    total += alex.healthcare.vitamins_general;
    total += alex.healthcare.regular_meds;

    if (month == 1) total += alex.healthcare.medical_insurance;
    if (month == 6) total += alex.healthcare.psychologist;

    if (month % 2 == 0) total += alex.healthcare.fitness_club;
    if (month % 3 == 0) {
        total += alex.healthcare.massage;
        total += alex.healthcare.yoga;
    }

    alex.bank.account_rub -= total;
    alexstats.healthcare += total;

    if (month == 12) {
        float health_inf = year == 2026 ? 11.0f : year == 2027 ? 11.5f : year == 2028 ? 12.0f : 10.0f;
        alex.healthcare.medical_insurance = (RUB)(alex.healthcare.medical_insurance * (1.0f + health_inf / 100.0f));
        alex.healthcare.fitness_club = (RUB)(alex.healthcare.fitness_club * (1.0f + health_inf / 100.0f));
        alex.healthcare.yoga = (RUB)(alex.healthcare.yoga * (1.0f + health_inf / 100.0f));
        alex.healthcare.massage = (RUB)(alex.healthcare.massage * (1.0f + health_inf / 100.0f));
        alex.healthcare.psychologist = (RUB)(alex.healthcare.psychologist * (1.0f + health_inf / 100.0f));
        alex.healthcare.vitamins_general = (RUB)(alex.healthcare.vitamins_general * (1.0f + health_inf / 100.0f));
        alex.healthcare.regular_meds = (RUB)(alex.healthcare.regular_meds * (1.0f + health_inf / 100.0f));
    }
}

void alex_education_expenses(int month, int year)
{
    RUB total = 0;

    total += alex.education.online_subscriptions;
    total += alex.education.software_licenses;

    if (month == 1 || month == 8) {
        total += alex.education.professional_courses;
        total += alex.education.books;
    }
    if (month == 9) total += alex.education.language_courses;
    if (month == 3) total += alex.education.mba;
    if (month == 5) total += alex.education.coaching;
    if (month == 7) total += alex.education.conferences;

    alex.bank.account_rub -= total;
    alexstats.education += total;

    if (month == 12) {
        float edu_inf = year == 2026 ? 10.0f : year == 2027 ? 10.5f : year == 2028 ? 11.0f : 9.5f;
        alex.education.professional_courses = (RUB)(alex.education.professional_courses * (1.0f + edu_inf / 100.0f));
        alex.education.language_courses = (RUB)(alex.education.language_courses * (1.0f + edu_inf / 100.0f));
        alex.education.mba = (RUB)(alex.education.mba * (1.0f + edu_inf / 100.0f));
        alex.education.books = (RUB)(alex.education.books * (1.0f + edu_inf / 100.0f));
        alex.education.online_subscriptions = (RUB)(alex.education.online_subscriptions * (1.0f + edu_inf / 100.0f));
        alex.education.conferences = (RUB)(alex.education.conferences * (1.0f + edu_inf / 100.0f));
        alex.education.coaching = (RUB)(alex.education.coaching * (1.0f + edu_inf / 100.0f));
        alex.education.software_licenses = (RUB)(alex.education.software_licenses * (1.0f + edu_inf / 100.0f));
    }
}

void alex_wedding(int month, int year)
{
    if (family.isMarried == false) {
        srand(time(0) + clock());
        int n = rand() % 10;
        if (n == 7)
        {
            family.isMarried = true;
            family.hasChildren = true;
            family.child_birth_month = month;
            family.child_birth_year = year;
        }
        RUB total = 0;
        total += alex.wedding.dress;
        total += alex.wedding.suit;
        total += alex.wedding.venue;
        total += alex.wedding.catering;
        total += alex.wedding.cake;
        total += alex.wedding.photographer;
        total += alex.wedding.music;
        total += alex.wedding.flowers;
        total += alex.wedding.rings;
        total += alex.wedding.transport;
        total += alex.wedding.honeymoon;

        alex.bank.account_rub -= total;
        alexstats.wedding += total;
    }

    if (month == 12) {
        float wedding_inf = year == 2026 ? 10.0f : year == 2027 ? 11.0f : year == 2028 ? 12.0f : 10.0f;
        alex.wedding.dress = (RUB)(alex.wedding.dress * (1.0f + wedding_inf / 100.0f));
        alex.wedding.suit = (RUB)(alex.wedding.suit * (1.0f + wedding_inf / 100.0f));
        alex.wedding.venue = (RUB)(alex.wedding.venue * (1.0f + wedding_inf / 100.0f));
        alex.wedding.catering = (RUB)(alex.wedding.catering * (1.0f + wedding_inf / 100.0f));
        alex.wedding.cake = (RUB)(alex.wedding.cake * (1.0f + wedding_inf / 100.0f));
        alex.wedding.photographer = (RUB)(alex.wedding.photographer * (1.0f + wedding_inf / 100.0f));
        alex.wedding.music = (RUB)(alex.wedding.music * (1.0f + wedding_inf / 100.0f));
        alex.wedding.flowers = (RUB)(alex.wedding.flowers * (1.0f + wedding_inf / 100.0f));
        alex.wedding.rings = (RUB)(alex.wedding.rings * (1.0f + wedding_inf / 100.0f));
        alex.wedding.transport = (RUB)(alex.wedding.transport * (1.0f + wedding_inf / 100.0f));
        alex.wedding.honeymoon = (RUB)(alex.wedding.honeymoon * (1.0f + wedding_inf / 100.0f));
    }
}

void alex_investments(int month, int year)
{
    RUB invest_amount = alex.salary * 0.10;
    if (month == 1 || month > 4) {
        alex.investments.crypto += 0.5 * invest_amount;
        alex.investments.gold += 0.5 * invest_amount;
    }

    if (month == 2) {
        alex.investments.stocks += 0.5 * invest_amount;
        alex.investments.bonds += 0.5 * invest_amount;
    }

    if (month == 3) {
        alex.investments.etf += 0.5 * invest_amount;
        alex.investments.mutual_funds += 0.5 * invest_amount;
    }

    if (month == 4) {
        alex.investments.real_estate_fund = 0.5 * invest_amount;
        alex.investments.startup_investment += 0.5 * invest_amount;
    }
    alex.bank.account_rub -= invest_amount;
    alexstats.investments += invest_amount;

    RUB stocks_return = alex.investments.stocks * 0.01;
    alex.investments.stocks += stocks_return;

    RUB bonds_return = alex.investments.bonds * 0.008;
    alex.investments.bonds += bonds_return;

    RUB crypto_return = alex.investments.crypto * 0.1;
    alex.investments.crypto += crypto_return;

    RUB gold_return = alex.investments.gold * 0.05;
    alex.investments.gold += gold_return;

    RUB etf_return = alex.investments.etf * 0.0012;
    alex.investments.etf += etf_return;

    RUB fund_return = alex.investments.mutual_funds * 0.03;
    alex.investments.mutual_funds += fund_return;

    RUB est_return = alex.investments.real_estate_fund * 0.12;
    alex.investments.real_estate_fund += est_return;

    RUB stup_return = alex.investments.startup_investment * 0.2;
    alex.investments.startup_investment += stup_return;

    alex.investments.total = alex.investments.gold + alex.investments.crypto + alex.investments.stocks +
        alex.investments.startup_investment + alex.investments.real_estate_fund + alex.investments.mutual_funds +
        alex.investments.etf + alex.investments.bonds;
}

void alex_deposit_interest()
{
    alex.bank.deposit_rub += 0.05 * alex.salary;
    alex.bank.account_rub -= 0.05 * alex.salary;

    if (alex.bank.deposit_rub > 0) {
        RUB interest = alex.bank.deposit_rub * 0.12 / 12;
        alex.bank.deposit_rub += interest;
        alexstats.total_income += interest;
    }
}

void print_alexdetailed_report(int start_year, int start_month, int end_year, int end_month)
{
    printf("\n\n");
    printf("========================================\n");
    printf("         ДЕТАЛЬНЫЙ ФИНАНСОВЫЙ ОТЧЁТ АЛЕКСА\n");
    printf("         Период: %d.%d - %d.%d\n", start_month, start_year, end_month, end_year);
    printf("========================================\n\n");

    alexstats.total_expenses = alexstats.food + alexstats.housing + alexstats.car + alexstats.transport +
        alexstats.pets + alexstats.trips +
        alexstats.entertainment + alexstats.utilities + alexstats.gifts + alexstats.healthcare + alexstats.education +
        alexstats.wedding + alexstats.child + alexstats.investments;
    alexstats.total_income += alex.investments.total;

    RUB net = alexstats.total_income - alexstats.total_expenses;

    printf("ОБЩИЙ ДОХОД:       %lld RUB\n", alexstats.total_income);
    printf("ОБЩИЕ РАСХОДЫ:     %lld RUB\n", alexstats.total_expenses);
    printf("ЧИСТЫЙ ДОХОД:      %lld RUB\n", net);
    printf("\n");

    printf("========================================\n");
    printf("РАСХОДЫ ПО КАТЕГОРИЯМ:\n");
    printf("========================================\n");
    printf("Продукты и доставка:    %lld RUB\n", alexstats.food);
    printf("Жильё (аренда, ЖКУ, ремонт): %lld RUB\n", alexstats.housing);
    printf("Автомобиль:             %lld RUB\n", alexstats.car);
    printf("Транспорт (такси и пр.): %lld RUB\n", alexstats.transport);
    printf("Питомцы (кошка/собака): %lld RUB\n", alexstats.pets);
    printf("Путешествия:            %lld RUB\n", alexstats.trips);
    printf("Развлечения:            %lld RUB\n", alexstats.entertainment);
    printf("Услуги (интернет, связь): %lld RUB\n", alexstats.utilities);
    printf("Подарки и пожертвования: %lld RUB\n", alexstats.gifts);
    printf("Здоровье (страховка, спорт): %lld RUB\n", alexstats.healthcare);
    printf("Образование:            %lld RUB\n", alexstats.education);

    if (alexstats.wedding > 0)
        printf("Свадьба:                %lld RUB\n", alexstats.wedding);

    if (alexstats.child > 0)
        printf("Ребёнок:                %lld RUB\n", alexstats.child);

    printf("Инвестиции:             %lld RUB\n", alexstats.investments);
    printf("\n");
}

bool check_death(int month, int year) 
{
    srand(time(0) + clock());

    int death_chance = rand() %1000 ;
   
    if (death_chance < 2) { 
        int who = rand() % 2;

        printf("\n");
        printf("========================================\n");
        printf("          ВНЕЗАПНАЯ СМЕРТЬ!\n");
        printf("========================================\n");

        if (who == 0) {
            printf(" alex  внезапно умер в возрасте %d лет\n", alex.age);
            printf("   Месяц: %d, Год: %d\n", month, year);
        }
        else {
            printf(" alice  внезапно умерла в возрасте %d лет\n", alice.age);
            printf("   Месяц: %d, Год: %d\n", month, year);
        }

        printf("Симуляция остановлена.\n");
        printf("========================================\n");

        return true;
    }
    return false;

}

void simulation(int start_year, int start_month, int end_year, int end_month) {
    int year = start_year;
    int month = start_month;
 
    while (!(year > end_year || (year == end_year && month > end_month))) {
        if (check_death(month, year)) {
            return;
        }

        alice_salary(month);
        alice_investments(month,year);
        alice_deposit_interest();

        alex_salary(month);
        alex_investments(month, year);
        alex_deposit_interest();

        
        alice_food_expenses(month, year);
        alice_housing_expenses(month, year);
        alice_child_expenses(month, year, family.hasChildren, family.child_age);
        alice_car_expenses(month, year);
        alice_transport_expenses(month, year);
        alice_trip_expenses(month, year);
        alice_cat_expenses(month, year);
        alice_dog_expenses(month, year);
        alice_entertainment_expenses(month, year);
        alice_utilities_expenses(month, year);
        alice_gifts_expenses(month, year);
        alice_healthcare_expenses(month, year);
        alice_education_expenses(month, year);
        alice_wedding(month, year);

        alex_food_expenses(month, year);
        alex_housing_expenses(month, year);
        alex_child_expenses(month, year, family.hasChildren, family.child_age);
        alex_car_expenses(month, year);
        alex_transport_expenses(month, year);
        alex_trip_expenses(month, year);
        alex_cat_expenses(month, year);
        alex_dog_expenses(month, year);
        alex_entertainment_expenses(month, year);
        alex_utilities_expenses(month, year);
        alex_gifts_expenses(month, year);
        alex_healthcare_expenses(month, year);
        alex_education_expenses(month, year);
        alex_wedding(month, year);
        
        if (family.hasChildren && (month == family.child_birth_month))
            family.child_age +=1;

        month++;
        if (month == 13) {
            alice.age += 1;
            alex.age += 1;
            month = 1;
            year++;
        }
    }    
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int start_year, start_month, end_year, end_month;

    start_year = 2026;
    start_month = 1;
    end_year = 2036;
    end_month = 12; 
 
    if (start_year < 2026 || end_year < start_year || start_year > 2080 || ((end_year == start_year) && (end_month<=start_month))) {      
        printf("Недопустимый период! Использйуте период по умолчанию: 1.2026 - 12.2080\n");

        start_year = 2026;
        start_month = 1;
        end_year = 2028;
        end_month = 12;
    }

    init_alice();
    init_alex();

    printf("СТАРТ СИМУЛЯЦИИ \n");

    simulation(start_year, start_month, end_year, end_month);

    print_alicedetailed_report(start_year, start_month, end_year, end_month);
    print_alexdetailed_report(start_year, start_month, end_year, end_month);

    return 0;
}