#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>

using RUB = long long int;

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
    bool isBorn;
    int birth_month;
    int birth_year;
    int age_years;
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
    RUB school_supplies;
    RUB school_uniform;
    RUB tutoring;
    RUB music_school;
    RUB sports_section;
    RUB art_school;
    RUB summer_camp;
    RUB pocket_money;
    RUB birthday_party;
    RUB clothes_yearly;
    RUB shoes_yearly;
    RUB electronics;
    RUB mobile_phone;
    RUB internet_for_child;
    RUB psychologist;
    RUB speech_therapist;
    RUB dental_treatment;
    RUB glasses;
    RUB first_car;
    RUB university_tuition;
    RUB dormitory;
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
    char name[50];
    int age;
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
};

struct Family {
    Person husband;
    Person wife;
    bool isMarried;
    bool hasChildren;
    int child_age;

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


Family family;
int current_year = 2026;
int current_month = 1;
bool simulation_running = true;
RUB total_capital = 0;
ExpenseStats stats = { 0 };

RUB calculate_person_capital(Person* p) {
    return p->bank.account_rub + p->bank.deposit_rub + p->investments.total + p->car.value;
}

void init_wife(Person* p, const char* name, int age, RUB salary) {

    strcpy_s(p->name, name);
    p->age = age;
    p->salary = salary;
    p->bonus = 0;
    p->food = 20000;
    p->food_delivery = 5000;

    p->car.value = 3000000;
    p->car.gas = 15000;
    p->car.insurance = 5000;
    p->car.tires_winter = 20000;
    p->car.tires_summer = 20000;
    p->car.washing = 1000;
    p->car.parking_home = 5000;
    p->car.parking_work = 5000;
    p->car.fines = 0;
    p->car.toll_roads = 2000;
    p->car.repair = 5000;
    p->car.diagnostics = 3000;
    p->car.antifreeze = 1000;
    p->car.oil_change = 4000;

    p->transport.taxi = 3000;
    p->transport.carsharing = 2000;
    p->transport.pub = 2000;

    p->home.rent = 45000;
    p->home.farm = 2000;
    p->home.electricity = 4000;
    p->home.heating = 3000;
    p->home.water = 1500;
    p->home.gas = 500;
    p->home.garbage = 500;
    p->home.intercom = 300;
    p->home.furniture = 10000;
    p->home.cleaning = 1000;
    p->home.repair = 5000;

    p->cat.cvalue = 5000;
    p->cat.cfood = 3000;
    p->cat.toys = 2000;
    p->cat.tray = 1000;
    p->cat.house_bed = 1500;
    p->cat.scratching_post = 5000;
    p->cat.cvet = 2000;
    p->cat.vitamins = 2000;
    p->cat.treats = 500;
    p->cat.carrier = 2500;
    p->cat.dental_treats = 800;

    p->dog.dvalue = 30000;
    p->dog.dfood = 5000;
    p->dog.toys = 1500;
    p->dog.bed = 3000;
    p->dog.leash = 3500;
    p->dog.vet = 3000;
    p->dog.vaccines = 4000;
    p->dog.vitamins = 1000;
    p->dog.teeth_cleaning = 3000;
    p->dog.allergy_meds = 2000;

    p->wedding.dress = 50000;
    p->wedding.suit = 30000;
    p->wedding.venue = 100000;
    p->wedding.catering = 80000;
    p->wedding.photographer = 40000;
    p->wedding.music = 25000;
    p->wedding.flowers = 20000;
    p->wedding.cake = 10000;
    p->wedding.rings = 30000;
    p->wedding.honeymoon = 200000;
    p->wedding.transport = 15000;

    p->child.isBorn = false;
    p->child.birth_month = 0;
    p->child.birth_year = 0;
    p->child.age_years = 0;
    p->child.prenatal_vitamins = 5000;
    p->child.doctor_visits = 3000;
    p->child.ultrasound = 5500;
    p->child.maternity_clothes = 20000;
    p->child.childbirth = 80000;
    p->child.stroller = 40000;
    p->child.crib = 30000;
    p->child.mattress = 7000;
    p->child.bedding = 4000;
    p->child.changing_table = 8000;
    p->child.baby_bath = 2000;
    p->child.baby_monitor = 5000;
    p->child.diapers = 5000;
    p->child.baby_wipes = 1500;
    p->child.baby_clothes = 5000;
    p->child.baby_food = 6000;
    p->child.bottles = 3000;
    p->child.pacifiers = 1500;
    p->child.sterilizer = 4000;
    p->child.bottle_warmer = 2500;
    p->child.car_seat = 15000;
    p->child.high_chair = 8000;
    p->child.playpen = 6000;
    p->child.toys = 3000;
    p->child.books = 1500;
    p->child.vaccinations = 5000;
    p->child.pediatrician = 2500;
    p->child.medications = 5000;
    p->child.nanny = 30000;
    p->child.nursery = 25000;
    p->child.kindergarten = 20000;
    p->child.school_supplies = 10000;
    p->child.school_uniform = 8000;
    p->child.tutoring = 15000;
    p->child.music_school = 8000;
    p->child.sports_section = 7000;
    p->child.art_school = 5000;
    p->child.summer_camp = 30000;
    p->child.pocket_money = 2000;
    p->child.birthday_party = 15000;
    p->child.clothes_yearly = 20000;
    p->child.shoes_yearly = 10000;
    p->child.electronics = 50000;
    p->child.mobile_phone = 20000;
    p->child.internet_for_child = 1000;
    p->child.psychologist = 3000;
    p->child.speech_therapist = 4000;
    p->child.dental_treatment = 5000;
    p->child.glasses = 10000;
    p->child.first_car = 500000;
    p->child.university_tuition = 300000;
    p->child.dormitory = 50000;

    p->bank.account_rub = 0;
    p->bank.deposit_rub = 0;

    p->investments.stocks = 0;
    p->investments.bonds = 0;
    p->investments.etf = 0;
    p->investments.crypto = 0;
    p->investments.mutual_funds = 0;
    p->investments.gold = 0;
    p->investments.real_estate_fund = 0;
    p->investments.startup_investment = 0;
    p->investments.total = 0;


    p->education.professional_courses = 20000;
    p->education.language_courses = 15000;
    p->education.mba = 0;
    p->education.books = 5000;
    p->education.online_subscriptions = 3000;
    p->education.conferences = 10000;
    p->education.coaching = 8000;
    p->education.software_licenses = 5000;

    p->healthcare.medical_insurance = 15000;
    p->healthcare.fitness_club = 4000;
    p->healthcare.yoga = 3000;
    p->healthcare.massage = 4000;
    p->healthcare.psychologist = 5000;
    p->healthcare.vitamins_general = 2000;
    p->healthcare.regular_meds = 3000;

    p->entertainment.cinema = 2000;
    p->entertainment.theater = 4000;
    p->entertainment.concerts = 5000;
    p->entertainment.museums = 1000;
    p->entertainment.quests = 2000;
    p->entertainment.bowling = 1500;
    p->entertainment.restaurants = 8000;
    p->entertainment.bars = 5000;
    p->entertainment.hookah = 2000;
    p->entertainment.alcohol = 4000;
    p->entertainment.cigarettes = 0;
    p->entertainment.vape = 0;
    p->entertainment.gaming_subscriptions = 1000;
    p->entertainment.game_purchases = 2000;
    p->entertainment.board_games = 1500;

    p->utilities.internet = 800;
    p->utilities.mobile_family = 1500;
    p->utilities.tv_subscription = 500;
    p->utilities.streaming_video = 800;
    p->utilities.streaming_music = 300;
    p->utilities.cloud_storage = 200;
    p->utilities.vpn = 500;
    p->utilities.antivirus = 300;

    p->gifts.birthday_family = 5000;
    p->gifts.birthday_friends = 3000;
    p->gifts.birthday_colleagues = 2000;
    p->gifts.new_year = 10000;
    p->gifts.march_8 = 3000;
    p->gifts.february_23 = 3000;
    p->gifts.children_birthdays = 2000;
    p->gifts.donations = 1000;

    p->trip.flight = 85000;
    p->trip.hotel = 150000;
    p->trip.meals = 38000;
    p->trip.excursions = 30000;
    p->trip.transport = 30000;
    p->trip.insurance = 5000;
    p->trip.visa = 8000;
    p->trip.souvenirs = 20000;
    p->trip.entertainment = 45000;
    p->trip.shopping = 15000;
}

void init_husband(Person* p, const char* name, int age, RUB salary) {
    strcpy_s(p->name, name);
    p->age = age;
    p->salary = salary;        
    p->bonus = 0;
    p->food = 18000;          
    p->food_delivery = 7000;     

    p->car.value = 2500000;      
    p->car.gas = 10000;         
    p->car.insurance = 6000;
    p->car.tires_winter = 18000;
    p->car.tires_summer = 18000;
    p->car.washing = 1500;
    p->car.parking_home = 5000;
    p->car.parking_work = 5000;
    p->car.fines = 0;
    p->car.toll_roads = 1000;
    p->car.repair = 7000;
    p->car.diagnostics = 4000;
    p->car.antifreeze = 1200;
    p->car.oil_change = 5000;

    p->transport.taxi = 5000;   
    p->transport.carsharing = 1000;
    p->transport.pub = 3000;

    p->home.rent = 45000;
    p->home.farm = 2000;
    p->home.electricity = 4000;
    p->home.heating = 3000;
    p->home.water = 1500;
    p->home.gas = 500;
    p->home.garbage = 500;
    p->home.intercom = 300;
    p->home.furniture = 15000;  
    p->home.cleaning = 1500;
    p->home.repair = 5000;

    p->cat.cvalue = 8000;
    p->cat.cfood = 3500;
    p->cat.toys = 3000;
    p->cat.tray = 1200;
    p->cat.house_bed = 2000;
    p->cat.scratching_post = 6000;
    p->cat.cvet = 2500;
    p->cat.vitamins = 2500;
    p->cat.treats = 800;
    p->cat.carrier = 3000;
    p->cat.dental_treats = 1000;

    p->dog.dvalue = 25000;
    p->dog.dfood = 6000;
    p->dog.toys = 2000;
    p->dog.bed = 4000;
    p->dog.leash = 4000;
    p->dog.vet = 5000;
    p->dog.vaccines = 4500;
    p->dog.vitamins = 1500;
    p->dog.teeth_cleaning = 3500;
    p->dog.allergy_meds = 2500;

    p->wedding.dress = 80000;    
    p->wedding.suit = 25000;      
    p->wedding.venue = 100000;
    p->wedding.catering = 80000;
    p->wedding.photographer = 50000;
    p->wedding.music = 30000;
    p->wedding.flowers = 30000;
    p->wedding.cake = 15000;
    p->wedding.rings = 40000;
    p->wedding.honeymoon = 200000;
    p->wedding.transport = 20000;

    p->child.isBorn = false;
    p->child.birth_month = 0;
    p->child.birth_year = 0;
    p->child.age_years = 0;
    p->child.prenatal_vitamins = 7000;
    p->child.doctor_visits = 4000;
    p->child.ultrasound = 6000;
    p->child.maternity_clothes = 30000;
    p->child.childbirth = 100000;
    p->child.stroller = 50000;
    p->child.crib = 35000;
    p->child.mattress = 8000;
    p->child.bedding = 5000;
    p->child.changing_table = 10000;
    p->child.baby_bath = 3000;
    p->child.baby_monitor = 8000;
    p->child.diapers = 6000;
    p->child.baby_wipes = 2000;
    p->child.baby_clothes = 8000;
    p->child.baby_food = 7000;
    p->child.bottles = 4000;
    p->child.pacifiers = 2000;
    p->child.sterilizer = 5000;
    p->child.bottle_warmer = 3000;
    p->child.car_seat = 20000;
    p->child.high_chair = 10000;
    p->child.playpen = 8000;
    p->child.toys = 5000;
    p->child.books = 2500;
    p->child.vaccinations = 6000;
    p->child.pediatrician = 3500;
    p->child.medications = 6000;
    p->child.nanny = 35000;
    p->child.nursery = 30000;
    p->child.kindergarten = 25000;
    p->child.school_supplies = 12000;
    p->child.school_uniform = 10000;
    p->child.tutoring = 18000;
    p->child.music_school = 10000;
    p->child.sports_section = 8000;
    p->child.art_school = 7000;
    p->child.summer_camp = 35000;
    p->child.pocket_money = 2500;
    p->child.birthday_party = 20000;
    p->child.clothes_yearly = 30000;
    p->child.shoes_yearly = 15000;
    p->child.electronics = 60000;
    p->child.mobile_phone = 25000;
    p->child.internet_for_child = 1500;
    p->child.psychologist = 4000;
    p->child.speech_therapist = 5000;
    p->child.dental_treatment = 7000;
    p->child.glasses = 12000;
    p->child.first_car = 600000;
    p->child.university_tuition = 350000;
    p->child.dormitory = 60000;

    p->bank.account_rub = 0;
    p->bank.deposit_rub = 0;

    p->investments.stocks = 0;
    p->investments.bonds = 0;
    p->investments.etf = 0;
    p->investments.crypto = 0;
    p->investments.mutual_funds = 0;
    p->investments.gold = 0;
    p->investments.real_estate_fund = 0;
    p->investments.startup_investment = 0;
    p->investments.total = 0;

    p->education.professional_courses = 25000;
    p->education.language_courses = 20000;
    p->education.mba = 50000;
    p->education.books = 8000;
    p->education.online_subscriptions = 5000;
    p->education.conferences = 15000;
    p->education.coaching = 12000;
    p->education.software_licenses = 7000;

    p->healthcare.medical_insurance = 18000;
    p->healthcare.fitness_club = 6000;
    p->healthcare.yoga = 5000;
    p->healthcare.massage = 6000;
    p->healthcare.psychologist = 8000;
    p->healthcare.vitamins_general = 3000;
    p->healthcare.regular_meds = 4000;

    p->entertainment.cinema = 3000;
    p->entertainment.theater = 6000;
    p->entertainment.concerts = 7000;
    p->entertainment.museums = 2000;
    p->entertainment.quests = 3000;
    p->entertainment.bowling = 2000;
    p->entertainment.restaurants = 12000;
    p->entertainment.bars = 7000;
    p->entertainment.hookah = 1000;
    p->entertainment.alcohol = 3000;
    p->entertainment.cigarettes = 0;
    p->entertainment.vape = 0;
    p->entertainment.gaming_subscriptions = 500;
    p->entertainment.game_purchases = 1000;
    p->entertainment.board_games = 2000;

    p->utilities.internet = 800;
    p->utilities.mobile_family = 1500;
    p->utilities.tv_subscription = 500;
    p->utilities.streaming_video = 800;
    p->utilities.streaming_music = 300;
    p->utilities.cloud_storage = 200;
    p->utilities.vpn = 500;
    p->utilities.antivirus = 300;

    p->gifts.birthday_family = 7000;
    p->gifts.birthday_friends = 5000;
    p->gifts.birthday_colleagues = 3000;
    p->gifts.new_year = 15000;
    p->gifts.march_8 = 5000;
    p->gifts.february_23 = 2000;
    p->gifts.children_birthdays = 3000;
    p->gifts.donations = 2000;

    p->trip.flight = 100000;
    p->trip.hotel = 180000;
    p->trip.meals = 45000;
    p->trip.excursions = 40000;
    p->trip.transport = 35000;
    p->trip.insurance = 8000;
    p->trip.visa = 10000;
    p->trip.souvenirs = 30000;
    p->trip.entertainment = 60000;
    p->trip.shopping = 25000;
}

void init_family() {
    init_husband(&family.husband, "Alexander", 30, 200000);
    init_wife(&family.wife, "Alice", 26, 350000);
    family.isMarried = false;
    family.hasChildren = false;
    family.child_age = 0;

    family.husband.bank.account_rub = 500000;
    family.wife.bank.account_rub = 500000;
}

float get_inflation_rate(int year, const char* category) {
    float default_rate = 8.0f;

    if (strcmp(category, "food") == 0) {
        if (year == 2026) return 12.5f;
        if (year == 2027) return 14.0f;
        if (year == 2028) return 13.0f;
        return 10.0f;
    }

    if (strcmp(category, "car") == 0) {
        if (year == 2026) return 6.5f;
        if (year == 2027) return 7.0f;
        if (year == 2028) return 8.0f;
        return 7.0f;
    }

    if (strcmp(category, "home") == 0) {
        if (year == 2026) return 8.5f;
        if (year == 2027) return 9.0f;
        if (year == 2028) return 9.5f;
        return 8.5f;
    }

    if (strcmp(category, "utilities") == 0) {
        if (year == 2026) return 7.5f;
        if (year == 2027) return 8.0f;
        if (year == 2028) return 8.5f;
        return 7.5f;
    }

    if (strcmp(category, "pets") == 0) {
        if (year == 2026) return 10.0f;
        if (year == 2027) return 10.5f;
        if (year == 2028) return 11.0f;
        return 9.5f;
    }

    if (strcmp(category, "trip") == 0) {
        if (year == 2026) return 11.0f;
        if (year == 2027) return 12.0f;
        if (year == 2028) return 10.5f;
        return 10.0f;
    }

    if (strcmp(category, "entertainment") == 0) {
        if (year == 2026) return 9.0f;
        if (year == 2027) return 9.5f;
        if (year == 2028) return 10.0f;
        return 8.5f;
    }

    if (strcmp(category, "healthcare") == 0) {
        if (year == 2026) return 11.0f;
        if (year == 2027) return 11.5f;
        if (year == 2028) return 12.0f;
        return 10.0f;
    }

    if (strcmp(category, "education") == 0) {
        if (year == 2026) return 10.0f;
        if (year == 2027) return 10.5f;
        if (year == 2028) return 11.0f;
        return 9.5f;
    }

    if (strcmp(category, "gifts") == 0) {
        if (year == 2026) return 7.0f;
        if (year == 2027) return 7.5f;
        if (year == 2028) return 8.0f;
        return 7.0f;
    }

    if (strcmp(category, "child") == 0) {
        if (year == 2026) return 9.0f;
        if (year == 2027) return 9.5f;
        if (year == 2028) return 10.0f;
        return 9.0f;
    }

    if (strcmp(category, "transport") == 0) {
        if (year == 2026) return 9.0f;
        if (year == 2027) return 9.5f;
        if (year == 2028) return 10.0f;
        return 8.5f;
    }

    if (strcmp(category, "wedding") == 0) {
        if (year == 2026) return 10.0f;
        if (year == 2027) return 11.0f;
        if (year == 2028) return 12.0f;
        return 10.0f;
    }

    return default_rate;
}

void apply_inflation(Person* p, int year) {

    float food_inf = get_inflation_rate(year, "food");
    p->food = (RUB)(p->food * (1.0f + food_inf / 100.0f));
    p->food_delivery = (RUB)(p->food_delivery * (1.0f + food_inf / 100.0f));

    float car_inf = get_inflation_rate(year, "car");
    p->car.gas = (RUB)(p->car.gas * (1.0f + car_inf / 100.0f));
    p->car.toll_roads = (RUB)(p->car.toll_roads * (1.0f + car_inf / 100.0f));
    p->car.repair = (RUB)(p->car.repair * (1.0f + car_inf / 100.0f));
    p->car.oil_change = (RUB)(p->car.oil_change * (1.0f + car_inf / 100.0f));
    p->car.antifreeze = (RUB)(p->car.antifreeze * (1.0f + car_inf / 100.0f));
    p->car.tires_winter = (RUB)(p->car.tires_winter * (1.0f + car_inf / 100.0f));
    p->car.tires_summer = (RUB)(p->car.tires_summer * (1.0f + car_inf / 100.0f));
    p->car.diagnostics = (RUB)(p->car.diagnostics * (1.0f + car_inf / 100.0f));
    p->car.insurance = (RUB)(p->car.insurance * (1.0f + car_inf / 100.0f));
    p->car.washing = (RUB)(p->car.washing * (1.0f + car_inf / 100.0f));
    p->car.parking_home = (RUB)(p->car.parking_home * (1.0f + car_inf / 100.0f));
    p->car.parking_work = (RUB)(p->car.parking_work * (1.0f + car_inf / 100.0f));
    p->car.fines = (RUB)(p->car.fines * (1.0f + car_inf / 100.0f));

    float home_inf = get_inflation_rate(year, "home");
    p->home.rent = (RUB)(p->home.rent * (1.0f + home_inf / 100.0f));
    p->home.electricity = (RUB)(p->home.electricity * (1.0f + home_inf / 100.0f));
    p->home.heating = (RUB)(p->home.heating * (1.0f + home_inf / 100.0f));
    p->home.water = (RUB)(p->home.water * (1.0f + home_inf / 100.0f));
    p->home.gas = (RUB)(p->home.gas * (1.0f + home_inf / 100.0f));
    p->home.garbage = (RUB)(p->home.garbage * (1.0f + home_inf / 100.0f));
    p->home.intercom = (RUB)(p->home.intercom * (1.0f + home_inf / 100.0f));
    p->home.farm = (RUB)(p->home.farm * (1.0f + home_inf / 100.0f));
    p->home.cleaning = (RUB)(p->home.cleaning * (1.0f + home_inf / 100.0f));
    p->home.repair = (RUB)(p->home.repair * (1.0f + home_inf / 100.0f));
    p->home.furniture = (RUB)(p->home.furniture * (1.0f + home_inf / 100.0f));

    float pets_inf = get_inflation_rate(year, "pets");
    p->cat.cfood = (RUB)(p->cat.cfood * (1.0f + pets_inf / 100.0f));
    p->dog.dfood = (RUB)(p->dog.dfood * (1.0f + pets_inf / 100.0f));
    p->cat.cvet = (RUB)(p->cat.cvet * (1.0f + pets_inf / 100.0f));
    p->dog.vet = (RUB)(p->dog.vet * (1.0f + pets_inf / 100.0f));
    p->dog.vaccines = (RUB)(p->dog.vaccines * (1.0f + pets_inf / 100.0f));
    p->dog.teeth_cleaning = (RUB)(p->dog.teeth_cleaning * (1.0f + pets_inf / 100.0f));
    p->cat.toys = (RUB)(p->cat.toys * (1.0f + pets_inf / 100.0f));
    p->cat.tray = (RUB)(p->cat.tray * (1.0f + pets_inf / 100.0f));
    p->cat.house_bed = (RUB)(p->cat.house_bed * (1.0f + pets_inf / 100.0f));
    p->cat.scratching_post = (RUB)(p->cat.scratching_post * (1.0f + pets_inf / 100.0f));
    p->cat.vitamins = (RUB)(p->cat.vitamins * (1.0f + pets_inf / 100.0f));
    p->cat.treats = (RUB)(p->cat.treats * (1.0f + pets_inf / 100.0f));
    p->cat.carrier = (RUB)(p->cat.carrier * (1.0f + pets_inf / 100.0f));
    p->cat.dental_treats = (RUB)(p->cat.dental_treats * (1.0f + pets_inf / 100.0f));
    p->dog.toys = (RUB)(p->dog.toys * (1.0f + pets_inf / 100.0f));
    p->dog.bed = (RUB)(p->dog.bed * (1.0f + pets_inf / 100.0f));
    p->dog.leash = (RUB)(p->dog.leash * (1.0f + pets_inf / 100.0f));
    p->dog.vitamins = (RUB)(p->dog.vitamins * (1.0f + pets_inf / 100.0f));
    p->dog.allergy_meds = (RUB)(p->dog.allergy_meds * (1.0f + pets_inf / 100.0f));

    float trip_inf = get_inflation_rate(year, "trip");
    p->trip.flight = (RUB)(p->trip.flight * (1.0f + trip_inf / 100.0f));
    p->trip.hotel = (RUB)(p->trip.hotel * (1.0f + trip_inf / 100.0f));
    p->trip.meals = (RUB)(p->trip.meals * (1.0f + trip_inf / 100.0f));
    p->trip.excursions = (RUB)(p->trip.excursions * (1.0f + trip_inf / 100.0f));
    p->trip.transport = (RUB)(p->trip.transport * (1.0f + trip_inf / 100.0f));
    p->trip.insurance = (RUB)(p->trip.insurance * (1.0f + trip_inf / 100.0f));
    p->trip.visa = (RUB)(p->trip.visa * (1.0f + trip_inf / 100.0f));
    p->trip.souvenirs = (RUB)(p->trip.souvenirs * (1.0f + trip_inf / 100.0f));
    p->trip.entertainment = (RUB)(p->trip.entertainment * (1.0f + trip_inf / 100.0f));
    p->trip.shopping = (RUB)(p->trip.shopping * (1.0f + trip_inf / 100.0f));

    float ent_inf = get_inflation_rate(year, "entertainment");
    p->entertainment.cinema = (RUB)(p->entertainment.cinema * (1.0f + ent_inf / 100.0f));
    p->entertainment.theater = (RUB)(p->entertainment.theater * (1.0f + ent_inf / 100.0f));
    p->entertainment.concerts = (RUB)(p->entertainment.concerts * (1.0f + ent_inf / 100.0f));
    p->entertainment.museums = (RUB)(p->entertainment.museums * (1.0f + ent_inf / 100.0f));
    p->entertainment.quests = (RUB)(p->entertainment.quests * (1.0f + ent_inf / 100.0f));
    p->entertainment.bowling = (RUB)(p->entertainment.bowling * (1.0f + ent_inf / 100.0f));
    p->entertainment.restaurants = (RUB)(p->entertainment.restaurants * (1.0f + ent_inf / 100.0f));
    p->entertainment.bars = (RUB)(p->entertainment.bars * (1.0f + ent_inf / 100.0f));
    p->entertainment.hookah = (RUB)(p->entertainment.hookah * (1.0f + ent_inf / 100.0f));
    p->entertainment.alcohol = (RUB)(p->entertainment.alcohol * (1.0f + ent_inf / 100.0f));
    p->entertainment.cigarettes = (RUB)(p->entertainment.cigarettes * (1.0f + ent_inf / 100.0f));
    p->entertainment.vape = (RUB)(p->entertainment.vape * (1.0f + ent_inf / 100.0f));
    p->entertainment.gaming_subscriptions = (RUB)(p->entertainment.gaming_subscriptions * (1.0f + ent_inf / 100.0f));
    p->entertainment.game_purchases = (RUB)(p->entertainment.game_purchases * (1.0f + ent_inf / 100.0f));
    p->entertainment.board_games = (RUB)(p->entertainment.board_games * (1.0f + ent_inf / 100.0f));

    float health_inf = get_inflation_rate(year, "healthcare");
    p->healthcare.medical_insurance = (RUB)(p->healthcare.medical_insurance * (1.0f + health_inf / 100.0f));
    p->healthcare.fitness_club = (RUB)(p->healthcare.fitness_club * (1.0f + health_inf / 100.0f));
    p->healthcare.yoga = (RUB)(p->healthcare.yoga * (1.0f + health_inf / 100.0f));
    p->healthcare.massage = (RUB)(p->healthcare.massage * (1.0f + health_inf / 100.0f));
    p->healthcare.psychologist = (RUB)(p->healthcare.psychologist * (1.0f + health_inf / 100.0f));
    p->healthcare.vitamins_general = (RUB)(p->healthcare.vitamins_general * (1.0f + health_inf / 100.0f));
    p->healthcare.regular_meds = (RUB)(p->healthcare.regular_meds * (1.0f + health_inf / 100.0f));

    float edu_inf = get_inflation_rate(year, "education");
    p->education.professional_courses = (RUB)(p->education.professional_courses * (1.0f + edu_inf / 100.0f));
    p->education.language_courses = (RUB)(p->education.language_courses * (1.0f + edu_inf / 100.0f));
    p->education.mba = (RUB)(p->education.mba * (1.0f + edu_inf / 100.0f));
    p->education.books = (RUB)(p->education.books * (1.0f + edu_inf / 100.0f));
    p->education.online_subscriptions = (RUB)(p->education.online_subscriptions * (1.0f + edu_inf / 100.0f));
    p->education.conferences = (RUB)(p->education.conferences * (1.0f + edu_inf / 100.0f));
    p->education.coaching = (RUB)(p->education.coaching * (1.0f + edu_inf / 100.0f));
    p->education.software_licenses = (RUB)(p->education.software_licenses * (1.0f + edu_inf / 100.0f));

    float gifts_inf = get_inflation_rate(year, "gifts");
    p->gifts.birthday_family = (RUB)(p->gifts.birthday_family * (1.0f + gifts_inf / 100.0f));
    p->gifts.birthday_friends = (RUB)(p->gifts.birthday_friends * (1.0f + gifts_inf / 100.0f));
    p->gifts.birthday_colleagues = (RUB)(p->gifts.birthday_colleagues * (1.0f + gifts_inf / 100.0f));
    p->gifts.new_year = (RUB)(p->gifts.new_year * (1.0f + gifts_inf / 100.0f));
    p->gifts.march_8 = (RUB)(p->gifts.march_8 * (1.0f + gifts_inf / 100.0f));
    p->gifts.february_23 = (RUB)(p->gifts.february_23 * (1.0f + gifts_inf / 100.0f));
    p->gifts.children_birthdays = (RUB)(p->gifts.children_birthdays * (1.0f + gifts_inf / 100.0f));
    p->gifts.donations = (RUB)(p->gifts.donations * (1.0f + gifts_inf / 100.0f));

    float transport_inf = get_inflation_rate(year, "transport");
    p->transport.taxi = (RUB)(p->transport.taxi * (1.0f + transport_inf / 100.0f));
    p->transport.carsharing = (RUB)(p->transport.carsharing * (1.0f + transport_inf / 100.0f));
    p->transport.pub = (RUB)(p->transport.pub * (1.0f + transport_inf / 100.0f));

    float child_inf = get_inflation_rate(year, "child");
    p->child.prenatal_vitamins = (RUB)(p->child.prenatal_vitamins * (1.0f + child_inf / 100.0f));
    p->child.doctor_visits = (RUB)(p->child.doctor_visits * (1.0f + child_inf / 100.0f));
    p->child.ultrasound = (RUB)(p->child.ultrasound * (1.0f + child_inf / 100.0f));
    p->child.maternity_clothes = (RUB)(p->child.maternity_clothes * (1.0f + child_inf / 100.0f));
    p->child.childbirth = (RUB)(p->child.childbirth * (1.0f + child_inf / 100.0f));
    p->child.stroller = (RUB)(p->child.stroller * (1.0f + child_inf / 100.0f));
    p->child.crib = (RUB)(p->child.crib * (1.0f + child_inf / 100.0f));
    p->child.mattress = (RUB)(p->child.mattress * (1.0f + child_inf / 100.0f));
    p->child.bedding = (RUB)(p->child.bedding * (1.0f + child_inf / 100.0f));
    p->child.changing_table = (RUB)(p->child.changing_table * (1.0f + child_inf / 100.0f));
    p->child.baby_bath = (RUB)(p->child.baby_bath * (1.0f + child_inf / 100.0f));
    p->child.baby_monitor = (RUB)(p->child.baby_monitor * (1.0f + child_inf / 100.0f));
    p->child.diapers = (RUB)(p->child.diapers * (1.0f + child_inf / 100.0f));
    p->child.baby_wipes = (RUB)(p->child.baby_wipes * (1.0f + child_inf / 100.0f));
    p->child.baby_clothes = (RUB)(p->child.baby_clothes * (1.0f + child_inf / 100.0f));
    p->child.baby_food = (RUB)(p->child.baby_food * (1.0f + child_inf / 100.0f));
    p->child.bottles = (RUB)(p->child.bottles * (1.0f + child_inf / 100.0f));
    p->child.pacifiers = (RUB)(p->child.pacifiers * (1.0f + child_inf / 100.0f));
    p->child.sterilizer = (RUB)(p->child.sterilizer * (1.0f + child_inf / 100.0f));
    p->child.bottle_warmer = (RUB)(p->child.bottle_warmer * (1.0f + child_inf / 100.0f));
    p->child.car_seat = (RUB)(p->child.car_seat * (1.0f + child_inf / 100.0f));
    p->child.high_chair = (RUB)(p->child.high_chair * (1.0f + child_inf / 100.0f));
    p->child.playpen = (RUB)(p->child.playpen * (1.0f + child_inf / 100.0f));
    p->child.toys = (RUB)(p->child.toys * (1.0f + child_inf / 100.0f));
    p->child.books = (RUB)(p->child.books * (1.0f + child_inf / 100.0f));
    p->child.vaccinations = (RUB)(p->child.vaccinations * (1.0f + child_inf / 100.0f));
    p->child.pediatrician = (RUB)(p->child.pediatrician * (1.0f + child_inf / 100.0f));
    p->child.medications = (RUB)(p->child.medications * (1.0f + child_inf / 100.0f));
    p->child.nanny = (RUB)(p->child.nanny * (1.0f + child_inf / 100.0f));
    p->child.nursery = (RUB)(p->child.nursery * (1.0f + child_inf / 100.0f));
    p->child.kindergarten = (RUB)(p->child.kindergarten * (1.0f + child_inf / 100.0f));
    p->child.school_supplies = (RUB)(p->child.school_supplies * (1.0f + child_inf / 100.0f));
    p->child.school_uniform = (RUB)(p->child.school_uniform * (1.0f + child_inf / 100.0f));
    p->child.tutoring = (RUB)(p->child.tutoring * (1.0f + child_inf / 100.0f));
    p->child.music_school = (RUB)(p->child.music_school * (1.0f + child_inf / 100.0f));
    p->child.sports_section = (RUB)(p->child.sports_section * (1.0f + child_inf / 100.0f));
    p->child.art_school = (RUB)(p->child.art_school * (1.0f + child_inf / 100.0f));
    p->child.summer_camp = (RUB)(p->child.summer_camp * (1.0f + child_inf / 100.0f));
    p->child.pocket_money = (RUB)(p->child.pocket_money * (1.0f + child_inf / 100.0f));
    p->child.birthday_party = (RUB)(p->child.birthday_party * (1.0f + child_inf / 100.0f));
    p->child.clothes_yearly = (RUB)(p->child.clothes_yearly * (1.0f + child_inf / 100.0f));
    p->child.shoes_yearly = (RUB)(p->child.shoes_yearly * (1.0f + child_inf / 100.0f));
    p->child.electronics = (RUB)(p->child.electronics * (1.0f + child_inf / 100.0f));
    p->child.mobile_phone = (RUB)(p->child.mobile_phone * (1.0f + child_inf / 100.0f));
    p->child.internet_for_child = (RUB)(p->child.internet_for_child * (1.0f + child_inf / 100.0f));
    p->child.psychologist = (RUB)(p->child.psychologist * (1.0f + child_inf / 100.0f));
    p->child.speech_therapist = (RUB)(p->child.speech_therapist * (1.0f + child_inf / 100.0f));
    p->child.dental_treatment = (RUB)(p->child.dental_treatment * (1.0f + child_inf / 100.0f));
    p->child.glasses = (RUB)(p->child.glasses * (1.0f + child_inf / 100.0f));
    p->child.first_car = (RUB)(p->child.first_car * (1.0f + child_inf / 100.0f));
    p->child.university_tuition = (RUB)(p->child.university_tuition * (1.0f + child_inf / 100.0f));
    p->child.dormitory = (RUB)(p->child.dormitory * (1.0f + child_inf / 100.0f));

    float util_inf2 = get_inflation_rate(year, "utilities"); 
    p->utilities.internet = (RUB)(p->utilities.internet * (1.0f + util_inf2 / 100.0f));
    p->utilities.mobile_family = (RUB)(p->utilities.mobile_family * (1.0f + util_inf2 / 100.0f));
    p->utilities.tv_subscription = (RUB)(p->utilities.tv_subscription * (1.0f + util_inf2 / 100.0f));
    p->utilities.streaming_video = (RUB)(p->utilities.streaming_video * (1.0f + util_inf2 / 100.0f));
    p->utilities.streaming_music = (RUB)(p->utilities.streaming_music * (1.0f + util_inf2 / 100.0f));
    p->utilities.cloud_storage = (RUB)(p->utilities.cloud_storage * (1.0f + util_inf2 / 100.0f));
    p->utilities.vpn = (RUB)(p->utilities.vpn * (1.0f + util_inf2 / 100.0f));
    p->utilities.antivirus = (RUB)(p->utilities.antivirus * (1.0f + util_inf2 / 100.0f));

    float wedding_inf = get_inflation_rate(year, "wedding");
    p->wedding.dress = (RUB)(p->wedding.dress * (1.0f + wedding_inf / 100.0f));
    p->wedding.suit = (RUB)(p->wedding.suit * (1.0f + wedding_inf / 100.0f));
    p->wedding.venue = (RUB)(p->wedding.venue * (1.0f + wedding_inf / 100.0f));
    p->wedding.catering = (RUB)(p->wedding.catering * (1.0f + wedding_inf / 100.0f));
    p->wedding.cake = (RUB)(p->wedding.cake * (1.0f + wedding_inf / 100.0f));
    p->wedding.photographer = (RUB)(p->wedding.photographer * (1.0f + wedding_inf / 100.0f));
    p->wedding.music = (RUB)(p->wedding.music * (1.0f + wedding_inf / 100.0f));
    p->wedding.flowers = (RUB)(p->wedding.flowers * (1.0f + wedding_inf / 100.0f));
    p->wedding.rings = (RUB)(p->wedding.rings * (1.0f + wedding_inf / 100.0f));
    p->wedding.transport = (RUB)(p->wedding.transport * (1.0f + wedding_inf / 100.0f));
    p->wedding.honeymoon = (RUB)(p->wedding.honeymoon * (1.0f + wedding_inf / 100.0f));
}

void apply_salary(Person* p, int month, int year) {

    if (month == 3) {
        p->salary *=  1.2;
    }

    if (month == 12) {
        p->bonus = p->salary * 1.5;
        p->bank.account_rub += p->bonus;
        stats.total_income += p->bonus;
    }

    p->bank.account_rub += p->salary;
    stats.total_income += p->salary;

    RUB tax = p->salary * 0.13;
    p->bank.account_rub -= tax;
}

void apply_food_expenses(Person* p, int month) {
    p->bank.account_rub -= p->food;
    stats.food += p->food;
    stats.total_expenses += p->food;

    if (month % 2 == 0) {
        p->bank.account_rub -= p->food_delivery;
        stats.food += p->food_delivery;
        stats.total_expenses += p->food_delivery;
    }
}

void apply_housing_expenses(Person* p, int month) {
    p->bank.account_rub -= p->home.rent;
    p->bank.account_rub -= p->home.electricity;
    p->bank.account_rub -= p->home.heating;
    p->bank.account_rub -= p->home.water;
    p->bank.account_rub -= p->home.gas;
    p->bank.account_rub -= p->home.garbage;
    p->bank.account_rub -= p->home.intercom;
    stats.housing += p->home.rent + p->home.electricity + p->home.heating + p->home.water + p->home.gas + p->home.garbage + p->home.intercom;
    stats.total_expenses += p->home.rent + p->home.electricity + p->home.heating + p->home.water + p->home.gas + p->home.garbage + p->home.intercom;
    
    if (month % 3 == 0) {
        p->bank.account_rub -= p->home.farm;
        stats.housing += p->home.farm + p->home.cleaning;
        stats.total_expenses += p->home.farm + p->home.cleaning;
        p->bank.account_rub -= p->home.cleaning;
       
    }

    if (month == 6 || month == 12) {
        p->bank.account_rub -= p->home.repair;
        stats.housing += p->home.repair;
        stats.total_expenses += p->home.repair;
    }

    if (month == 5 || month == 11) {
        p->bank.account_rub -= p->home.furniture;
        stats.housing += p->home.furniture;
        stats.total_expenses += p->home.furniture;
    }
}

void apply_car_expenses(Person* p, int month, int year) {
    p->bank.account_rub -= p->car.gas;
    stats.car += p->car.gas;
    stats.total_expenses += p->car.gas;

    RUB toll = p->car.toll_roads;
    p->bank.account_rub -= toll;
    stats.car += toll;
    stats.total_expenses += toll;

    if (month % 2 == 0) {
        p->bank.account_rub -= p->car.washing;
        stats.car += p->car.washing;
        stats.total_expenses += p->car.washing;
    }

    p->bank.account_rub -= p->car.parking_home;
    p->bank.account_rub -= p->car.parking_work;
    stats.car += p->car.parking_work + p->car.parking_home;
    stats.total_expenses += p->car.parking_work + p->car.parking_home;

    if (month == 10) {
        p->bank.account_rub -= p->car.tires_winter;
        p->bank.account_rub -= p->car.diagnostics;
        stats.car += p->car.tires_winter + p->car.diagnostics;
        stats.total_expenses += p->car.tires_winter + p->car.diagnostics;
    }

    if (month == 4) {
        p->bank.account_rub -= p->car.tires_summer;
        p->bank.account_rub -= p->car.diagnostics;
        stats.car += p->car.tires_summer + p->car.diagnostics;
        stats.total_expenses += p->car.tires_summer + p->car.diagnostics;        
    }

    if (month == 6 || month == 12) {
        p->bank.account_rub -= p->car.oil_change;
        p->bank.account_rub -= p->car.antifreeze; 
        stats.car += p->car.oil_change + p->car.antifreeze;
        stats.total_expenses += p->car.oil_change + p->car.antifreeze;
    }

    if (month == 12) {
        p->bank.account_rub -= p->car.insurance;
        p->bank.account_rub -= p->car.repair;
        stats.car += p->car.insurance + p->car.repair;
        stats.total_expenses += p->car.insurance + p->car.repair;
       
    }

    if (rand() % 100 < 5) {
        RUB fine = 500 + rand() % 5000;
        p->car.fines += fine;
        p->bank.account_rub -= fine;
        stats.car += fine;
        stats.total_expenses += fine;
    }
}

void apply_transport_expenses(Person* p, int month) {
    p->bank.account_rub -= p->transport.pub;
    stats.transport += p->transport.pub;
    stats.total_expenses += p->transport.pub;

    if (month % 2 == 0) {
        p->bank.account_rub -= p->transport.taxi;
        stats.transport += p->transport.taxi;
        stats.total_expenses += p->transport.taxi;
    }

    if (month % 3 == 0) {
        p->bank.account_rub -= p->transport.carsharing;
        stats.transport += p->transport.carsharing;
        stats.total_expenses += p->transport.carsharing;
    }
}

void apply_trip_expenses(Person* p, int month) {
    RUB total = 0;
    total += p->trip.flight;
    total += p->trip.hotel;
    total += p->trip.meals;
    total += p->trip.excursions;
    total += p->trip.transport;
    total += p->trip.insurance;
    total += p->trip.visa;
    total += p->trip.souvenirs;
    total += p->trip.shopping;
    total += p->trip.entertainment;

    p->bank.account_rub -= total;
    stats.trips += total;
    stats.total_expenses += total;
}

void apply_child_expenses(Person* p, int month, int year, bool has_child, int child_age) {
    if (!has_child) return;


    RUB expense_this_month = 0;

    if (child_age < 1) {
        expense_this_month += p->child.diapers;
        expense_this_month += p->child.baby_wipes;
        expense_this_month += p->child.baby_clothes;
        expense_this_month += p->child.baby_food;
        expense_this_month += p->child.medications;
        expense_this_month += p->child.pediatrician;
        expense_this_month += p->child.toys;

        if (month == 3 || month == 6 || month == 9 || month == 12) {
            expense_this_month += p->child.vaccinations;
        }
    }
    else if (child_age >= 1 && child_age < 3) {
        expense_this_month += p->child.diapers;
        expense_this_month += p->child.baby_wipes;
        expense_this_month += p->child.baby_clothes;
        expense_this_month += p->child.baby_food;
        expense_this_month += p->child.toys;
        expense_this_month += p->child.books;
        expense_this_month += p->child.medications;
        expense_this_month += p->child.pediatrician;

        if (month == 12) {
            expense_this_month += p->child.vaccinations;
        }

        if (month == p->child.birth_month) {
            expense_this_month += p->child.birthday_party;
        }
    }
    else if (child_age >= 3 && child_age < 7) {
        expense_this_month += p->child.kindergarten;
        expense_this_month += p->child.clothes_yearly / 12;
        expense_this_month += p->child.shoes_yearly / 12;
        expense_this_month += p->child.toys;
        expense_this_month += p->child.books;
        expense_this_month += p->child.medications;

        if (month == 9) {
            expense_this_month += p->child.school_supplies;
        }

        if (month == p->child.birth_month) {
            expense_this_month += p->child.birthday_party;
        }

        if (month == 6) {
            expense_this_month += p->child.summer_camp / 2;
        }
    }
    else if (child_age >= 7 && child_age < 12) {
        expense_this_month += p->child.tutoring;
        expense_this_month += p->child.sports_section;
        expense_this_month += p->child.music_school;
        expense_this_month += p->child.clothes_yearly / 12;
        expense_this_month += p->child.shoes_yearly / 12;
        expense_this_month += p->child.pocket_money;
        expense_this_month += p->child.books;
        expense_this_month += p->child.medications;

        if (month == 8) {
            expense_this_month += p->child.school_supplies;
            expense_this_month += p->child.school_uniform;
        }

        if (month == 6) {
            expense_this_month += p->child.summer_camp;
        }

        if (month == p->child.birth_month) {
            expense_this_month += p->child.birthday_party;
        }

        if (month == 12) {
            expense_this_month += p->child.electronics / 4;
        }
    }
    else if (child_age >= 12 && child_age < 18) {
        expense_this_month += p->child.tutoring;
        expense_this_month += p->child.sports_section;
        expense_this_month += p->child.clothes_yearly / 12;
        expense_this_month += p->child.shoes_yearly / 12;
        expense_this_month += p->child.pocket_money;
        expense_this_month += p->child.mobile_phone / 12;
        expense_this_month += p->child.internet_for_child;

        if (month == 8) {
            expense_this_month += p->child.school_supplies;
        }

        if (month == 6) {
            expense_this_month += p->child.summer_camp;
        }

        if (month == p->child.birth_month) {
            expense_this_month += p->child.birthday_party;
        }

        if (month == 1 || month == 7) {
            expense_this_month += p->child.dental_treatment;
        }

        if (child_age >= 16 && month == 9) {
            expense_this_month += p->child.psychologist;
            expense_this_month += p->child.speech_therapist;
        }

        if (child_age == 18 && month == 1) {
            expense_this_month += p->child.first_car;
        }
    }
    else if (child_age >= 18) {
        expense_this_month += p->child.university_tuition / 12;
        expense_this_month += p->child.dormitory;
        expense_this_month += p->child.pocket_money;
        expense_this_month += p->child.clothes_yearly / 12;

        if (month == 8) {
            expense_this_month += p->child.school_supplies;
            expense_this_month += p->child.electronics / 2;
        }

        if (month == p->child.birth_month) {
            expense_this_month += p->child.birthday_party;
        }
    }

    p->bank.account_rub -= expense_this_month;
    stats.child += expense_this_month;
    stats.total_expenses += expense_this_month;
}

void apply_cat_expenses(Person* p, int month, bool has_cat) {
    if (!has_cat) return;

    p->bank.account_rub -= p->cat.cfood;
    stats.pets += p->cat.cfood;
    stats.total_expenses += p->cat.cfood;

    if (month % 2 == 0) {
        p->bank.account_rub -= p->cat.treats;
        stats.pets += p->cat.treats;
        stats.total_expenses += p->cat.treats;
    }

    if (month % 3 == 0) {
        p->bank.account_rub -= p->cat.toys;
        p->bank.account_rub -= p->cat.dental_treats;
        stats.pets += p->cat.toys + p->cat.dental_treats;
        stats.total_expenses += p->cat.toys + p->cat.dental_treats;
        
    }

    if (month % 4 == 0) {
        p->bank.account_rub -= p->cat.cvet;
        p->bank.account_rub -= p->cat.vitamins;
        stats.pets + p->cat.cvet + p->cat.vitamins;
        stats.total_expenses += p->cat.cvet + p->cat.vitamins;
    }
    
    if (month  == 1) {
        p->bank.account_rub -= p->cat.tray;
        p->bank.account_rub -= p->cat.house_bed;
        p->bank.account_rub -= p->cat.scratching_post;
        p->bank.account_rub -= p->cat.carrier;
        stats.pets += p->cat.tray+ p->cat.house_bed+ p->cat.scratching_post+ p->cat.carrier;
        stats.total_expenses += p->cat.tray + p->cat.house_bed + p->cat.scratching_post + p->cat.carrier;
    }
}

void apply_dog_expenses(Person* p, int month, bool has_dog) {
    if (!has_dog) return;

    p->bank.account_rub -= p->dog.dfood;
    stats.pets += p->dog.dfood;
    stats.total_expenses += p->dog.dfood;

    if (month % 2 == 0) {
        p->bank.account_rub -= p->dog.allergy_meds;
        stats.pets += p->dog.allergy_meds;
        stats.total_expenses += p->dog.allergy_meds;
    }

    if (month % 3 == 0) {
        p->bank.account_rub -= p->dog.toys;
        p->bank.account_rub -= p->dog.teeth_cleaning;
        stats.pets += p->dog.toys + p->dog.teeth_cleaning;
        stats.total_expenses += p->dog.toys + p->dog.teeth_cleaning;
    }

    if (month % 4 == 0) {
        p->bank.account_rub -= p->dog.vet;
        p->bank.account_rub -= p->dog.vitamins;
        stats.pets += p->dog.vet + p->dog.vitamins;
        stats.total_expenses += p->dog.vet + p->dog.vitamins;
    }

    if (month == 3) {
        p->bank.account_rub -= p->dog.vaccines;
        stats.pets += p->dog.vaccines;
        stats.total_expenses += p->dog.vaccines;
    }

    if (month == 1) {
        p->bank.account_rub -= p->dog.bed;
        p->bank.account_rub -= p->dog.leash;
        stats.pets += p->dog.bed + p->dog.leash;
        stats.total_expenses += p->dog.bed + p->dog.leash;
    }
}

void apply_entertainment_expenses(Person* p, int month) {
    RUB total = 0;
    if (month % 2 == 0) {
        total += p->entertainment.cinema;
        total += p->entertainment.bowling;
    }

    if (month % 3 == 0) {
        total += p->entertainment.theater;
        total += p->entertainment.concerts;
        total += p->entertainment.quests;
        total += p->entertainment.restaurants;
        total += p->entertainment.museums;
    }

    if (month % 4 == 0) {
        total += p->entertainment.bars;
        total += p->entertainment.hookah;
    }

    if (month % 5 == 0) {
        total += p->entertainment.board_games;
        total += p->entertainment.game_purchases;
    }

    total += p->entertainment.alcohol;
    total += p->entertainment.gaming_subscriptions;
    total += p->entertainment.cigarettes;
    total += p->entertainment.vape;

    p->bank.account_rub -= total;
    stats.entertainment += total;
    stats.total_expenses += total;
}

void apply_utilities_expenses(Person* p, int month) {
    RUB total = 0;
    total += p->utilities.internet;
    total += p->utilities.mobile_family;
    total += p->utilities.tv_subscription;
    total += p->utilities.streaming_video;
    total += p->utilities.streaming_music;
    total += p->utilities.cloud_storage;
    total += p->utilities.vpn;
    total += p->utilities.antivirus;

    p->bank.account_rub -= total;
    stats.utilities += total;
    stats.total_expenses += total;
}

void apply_gifts_expenses(Person* p, int month) {
    RUB total = 0;
    if (month == 1) total += p->gifts.new_year;
    if (month == 2) total += p->gifts.february_23;
    if (month == 3) total += p->gifts.march_8;
    if (month == 6 || month == 12) total += p->gifts.birthday_family;
    if (month == 9) total += p->gifts.children_birthdays;
    if (month == 7) total += p->gifts.birthday_friends;
    if (month == 4) total += p->gifts.birthday_colleagues;
    total += p->gifts.donations;

    p->bank.account_rub -= total;
    stats.gifts += total;
    stats.total_expenses += total;
}

void apply_healthcare_expenses(Person* p, int month) {
    RUB total = 0;
    if (month == 1) total += p->healthcare.medical_insurance;
    if (month == 6) total += p->healthcare.psychologist;
    total += p->healthcare.vitamins_general;
    total += p->healthcare.regular_meds;

    if (month % 2 == 0) total += p->healthcare.fitness_club;
    if (month % 3 == 0) {
        total += p->healthcare.massage;
        total += p->healthcare.yoga;
    }

    p->bank.account_rub -= total;
    stats.healthcare += total;
    stats.total_expenses += total;
}

void apply_education_expenses(Person* p, int month) {
    RUB total = 0;
    if (month == 1 || month == 8) {
        total += p->education.professional_courses;
        total += p->education.books;
    }
    if (month == 9) total += p->education.language_courses;
    if (month == 3) total += p->education.mba;
    if (month == 5) total += p->education.coaching;
    if (month == 7) total += p->education.conferences;
    total += p->education.online_subscriptions;
    total += p->education.software_licenses;

    p->bank.account_rub -= total;
    stats.education += total;
    stats.total_expenses += total;
}

void apply_investments(Person* p, int month) {

    RUB invest_amount = p->salary * 0.10;
    if (month == 1 || month>4 ) {
        p->investments.crypto += 0.5 * invest_amount;
        p->investments.gold += 0.5 * invest_amount;
    }

    if (month == 2) {
        p->investments.stocks += 0.5 * invest_amount;
        p->investments.bonds += 0.5 * invest_amount;
    }

    if (month == 3) {
        p->investments.etf += 0.5 * invest_amount;
        p->investments.mutual_funds += 0.5 * invest_amount;
    }

    if (month == 4) {
        p->investments.real_estate_fund= 0.5 * invest_amount;
        p->investments.startup_investment += 0.5 * invest_amount;
    }
    p->bank.account_rub -= invest_amount;
    stats.investments += invest_amount;
    stats.total_expenses += invest_amount;

    RUB stocks_return = p->investments.stocks * 0.01;
    p->investments.stocks += stocks_return;

    RUB bonds_return = p->investments.bonds * 0.008;
    p->investments.bonds += bonds_return;

    RUB crypto_return = p->investments.crypto * 0.1;
    p->investments.crypto += crypto_return;

    RUB gold_return = p->investments.gold * 0.05;
    p->investments.gold += gold_return;

    RUB etf_return = p->investments.etf * 0.0012;
    p->investments.etf += etf_return;

    RUB fund_return = p->investments.mutual_funds * 0.03;
    p->investments.mutual_funds += fund_return;

    RUB est_return = p->investments.real_estate_fund * 0.12;
    p->investments.real_estate_fund += est_return;

    RUB stup_return = p->investments.startup_investment * 0.2;
    p->investments.startup_investment += stup_return;

    p->investments.total = p->investments.gold + p->investments.crypto + p->investments.stocks + p->investments.startup_investment + p->investments.real_estate_fund + p->investments.mutual_funds + p->investments.etf + p->investments.bonds;

}

void apply_deposit_interest(Person* p, int month) {
    p->bank.deposit_rub += 0.05 * p->salary;
    p->bank.account_rub -= 0.05 * p->salary;
    if (p->bank.deposit_rub > 0) {
        RUB interest = p->bank.deposit_rub * 0.12 / 12;
        p->bank.deposit_rub += interest;
    }
}

void apply_wedding(Person* p, int month, int year, bool isMarried) {

    RUB total = 0;
    total += p->wedding.dress;
    total += p->wedding.suit;
    total += p->wedding.venue;
    total += p->wedding.catering;
    total += p->wedding.cake;
    total += p->wedding.photographer;
    total += p->wedding.music;
    total += p->wedding.flowers;
    total += p->wedding.rings;
    total += p->wedding.transport;
    total += p->wedding.honeymoon;

    p->bank.account_rub -= total;
    stats.wedding += total;
    stats.total_expenses += total;

}

void print_monthly_report(int month, int year, Person* p) {
    printf("\n           %d.%d   \n", month, year);
    printf("Salary: %lld RUB\n", p->salary);
    printf("Account RUB: %lld RUB\n", p->bank.account_rub);
    printf("Deposit: %lld RUB\n", p->bank.deposit_rub);
    printf("Investments: %lld RUB\n", p->investments.total);
}

void print_final_report(Person* p, int start_year, int start_month, int end_year, int end_month) {
    printf("Simulation period: %d.%d - %d.%d\n", start_month, start_year, end_month, end_year);
    printf("-----------------------------------\n");
    printf("Final salary: %lld RUB\n", p->salary);
    printf("Account RUB: %lld RUB\n", p->bank.account_rub);
    printf("Deposit: %lld RUB\n", p->bank.deposit_rub);
    printf("\n--- INVESTMENTS ---\n");
    printf("Total: %lld RUB\n", p->investments.total);
    printf("\n--- CAR ---\n");
    printf("Car value: %lld RUB\n", p->car.value);
    printf("\n--- TOTAL CAPITAL ---\n");

    RUB total = p->bank.account_rub + p->bank.deposit_rub + p->investments.total + p->car.value;
    printf("TOTAL: %lld RUB\n", total);
}

void print_detailed_report(int start_year, int start_month, int end_year, int end_month) {
    printf("\n\n");
    printf("========================================\n");
    printf("         ÄÅÒÀËÜÍÛÉ ÔÈÍÀÍÑÎÂÛÉ ÎÒ×¨Ò\n");
    printf("         Ïåðèîä: %d.%d - %d.%d\n", start_month, start_year, end_month, end_year);
    printf("========================================\n\n");

    RUB net = stats.total_income - stats.total_expenses;
    printf("ÎÁÙÈÉ ÄÎÕÎÄ:       %lld RUB\n", stats.total_income);
    printf("ÎÁÙÈÅ ÐÀÑÕÎÄÛ:     %lld RUB\n", stats.total_expenses);
    printf("×ÈÑÒÛÉ ÄÎÕÎÄ:      %lld RUB\n", net);
    printf("\n");

    printf("========================================\n");
    printf("ÐÀÑÕÎÄÛ ÏÎ ÊÀÒÅÃÎÐÈßÌ:\n");
    printf("========================================\n");
    printf("Ïðîäóêòû è äîñòàâêà:    %lld RUB\n", stats.food);
    printf("Æèëü¸ (àðåíäà, ÆÊÓ, ðåìîíò): %lld RUB\n", stats.housing);
    printf("Àâòîìîáèëü:             %lld RUB\n", stats.car);
    printf("Òðàíñïîðò (òàêñè è ïð.): %lld RUB\n", stats.transport);
    printf("Ïèòîìöû (êîøêà/ñîáàêà): %lld RUB\n", stats.pets);
    printf("Ïóòåøåñòâèÿ:            %lld RUB\n", stats.trips);
    printf("Ðàçâëå÷åíèÿ:            %lld RUB\n", stats.entertainment);
    printf("Óñëóãè (èíòåðíåò, ñâÿçü): %lld RUB\n", stats.utilities);
    printf("Ïîäàðêè è ïîæåðòâîâàíèÿ: %lld RUB\n", stats.gifts);
    printf("Çäîðîâüå (ñòðàõîâêà, ñïîðò): %lld RUB\n", stats.healthcare);
    printf("Îáðàçîâàíèå:            %lld RUB\n", stats.education);
    if (stats.wedding > 0)
        printf("Ñâàäüáà:                %lld RUB\n", stats.wedding);
    if (stats.child > 0)
        printf("Ðåá¸íîê:                %lld RUB\n", stats.child);
    printf("Èíâåñòèöèè:             %lld RUB\n", stats.investments);
    printf("\n");
}

void simulation(int start_year, int start_month, int end_year, int end_month) {
    int year = start_year;
    int month = start_month;

    bool has_cat = true;
    bool has_dog = true;
    bool is_married = family.isMarried;
    bool child = family.hasChildren;

    srand(time(NULL));

    while (!(year > end_year || (year == end_year && month > end_month))) {
        Person* p = &family.husband;
        Person* q = &family.wife;
        apply_salary(p, month, year);
        apply_salary(q, month, year);
        apply_investments(p, month);
        apply_investments(q, month);
        apply_deposit_interest(p, month);
        apply_deposit_interest(q, month);
        if (is_married == false) {
            int n = rand()%10;
            if (n == 7)
            {
                is_married = true;
                apply_wedding(p, month, year, is_married);
                child = true;
                family.isMarried = true;
                family.hasChildren = true;
                p->child.isBorn = true;
                q->child.isBorn = true;
                p->child.birth_month = month;
                q->child.birth_month = month;
                p->child.birth_year = year;
                q->child.birth_year = year;
            }
        }
        apply_food_expenses(p, month);
        apply_food_expenses(q, month);
        apply_housing_expenses(q, month);
        apply_child_expenses(p, month, year, child, family.child_age);
        apply_car_expenses(p, month, year);
        apply_car_expenses(q, month, year);
        apply_transport_expenses(q, month);
        if (has_cat) {
            apply_cat_expenses(p, month, has_cat);
        }

        if (has_dog) {
            apply_dog_expenses(p, month, has_dog);
        }

        if (month == 6) {
            apply_trip_expenses(p, month);
        }

        apply_entertainment_expenses(p, month);
        apply_utilities_expenses(q, month);
        apply_gifts_expenses(q, month);
        apply_healthcare_expenses(p, month);
        apply_healthcare_expenses(q, month);
        apply_education_expenses(p, month);
        
        if (month == 12) {
            apply_inflation(p, year);
            apply_inflation(q, year);
        }

        if (child && (month == p->child.birth_month))
            family.child_age +=1;

        if (month == 3 || month == 6 || month == 9 || month == 12) {
           //print_monthly_report(month, year, p);
        }
        month++;
        if (month == 13) {
            month = 1;
            year++;
        }
    }
    printf("\n-----HUSBAND-----\n");
    print_final_report(&family.husband, start_year, start_month, end_year, end_month);
    printf("\n-----WIFE-----\n");
    print_final_report(&family.wife, start_year, start_month, end_year, end_month);
    print_detailed_report(start_year, start_month, end_year, end_month);
}

int main() {
    setlocale(LC_ALL, "Russian");

    init_family();

    int start_year, start_month, end_year, end_month;

    start_year = 2026;
    end_year = 2028;
    start_month = 1;
    end_month = 12;
    printf("FINANCIAL SIMULATION \n");
 
    if (start_year < 2026 || end_year < start_year || start_year > 2028 ) {
        printf("Invalid period! Using default: 2026.1 - 2028.12\n");
        start_year = 2026;
        start_month = 1;
        end_year = 2028;
        end_month = 12;
    }
    
    simulation(start_year, start_month, end_year, end_month);
    return 0;
}