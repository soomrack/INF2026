#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using RUB = long long int;
using USD = long long int;
using EUR = long long int;
using GBP = long long int;
using CNY = long long int;
using Percent = float;

struct Bank {
    RUB account;
    RUB deposite;
    Percent interest;

    USD account_usd;
    float rate_usd_rub;

    EUR account_eur;
    float rate_eur_rub;

    GBP account_gbp;
    float rate_gbp_rub;

    CNY account_cny;
    float rate_cny_rub;
};

struct Car {
    RUB gas;
    RUB value;
    RUB insurance;
    RUB tax;
    RUB parking;
    RUB repair;
    RUB washing;
    RUB winter_tires;
    RUB summer_tires;
    RUB oil_change;
    RUB diagnostics;
    RUB fines;
    RUB detailing;
    RUB car_wash_subscription;
    RUB new_radio;
    RUB new_seat_covers;
    RUB tire_storage;
};

struct RealEstate {
    RUB apartment_value;
    RUB house_value;
    RUB cottage_value;
    RUB land_value;
    RUB mortgage_payment;
    RUB mortgage_debt;
    RUB utilities;
    RUB property_tax;
    RUB repair;
    RUB furniture;
    RUB appliances;
    RUB renovation;
    RUB insurance;
    RUB internet;
    RUB tv_subscription;
    RUB cleaning_service;
    RUB gardening;
};

struct Cat {
    RUB food;
    RUB vet;
    RUB toys;
    RUB toilet_filler;
    RUB treats;
    RUB scratching_post;
    RUB bed;
    RUB carrier;
    RUB vaccinations;
};

struct Dog {
    RUB food;
    RUB vet;
    RUB toys;
    RUB toilet_filler;
    RUB treats;
    RUB leash;
    RUB collar;
    RUB bed;
    RUB vaccinations;
    RUB training;
    RUB walking_service;
    RUB grooming;
};

struct Medicine {
    RUB vitamins;
    RUB cold_medicine;
    RUB dentist;
    RUB doctor;
    RUB emergency;
    RUB surgery;
    RUB rehabilitation;
    RUB massage;
    RUB spa;
    RUB psychologist;
    RUB lab_tests;
    RUB mri;
    RUB ultrasound;
    RUB physiotherapy;
};

struct Freelance {
    RUB design;
    RUB consulting;
    RUB programming;
    RUB writing;
    RUB translation;
    RUB tutoring;
    RUB photography;
    RUB videography;
    RUB web_development;
    RUB mobile_development;
    RUB seo;
    RUB smm;
};

struct Education {
    RUB courses;
    RUB books;
    RUB seminars;
    RUB webinars;
    RUB conferences;
    RUB online_courses;
    RUB driving_license;
    RUB professional_cert;
    RUB language_courses;
    RUB music_school;
    RUB art_school;
    RUB coaching;
};

struct Entertainment {
    RUB cinema;
    RUB concerts;
    RUB theater;
    RUB museum;
    RUB gaming;
    RUB streaming;
    RUB hobbies;
    RUB sports;
    RUB bar;
    RUB nightclub;
    RUB karaoke;
    RUB bowling;
    RUB paintball;
    RUB quest_rooms;
    RUB amusement_park;
    RUB zoo;
    RUB aquarium;
};

struct Clothing {
    RUB everyday;
    RUB work;
    RUB sport;
    RUB seasonal;
    RUB shoes;
    RUB accessories;
    RUB bags;
    RUB watches;
    RUB jewelry;
    RUB underwear;
    RUB outerwear;
    RUB hats;
    RUB scarves;
    RUB gloves;
};

struct Health {
    RUB gym;
    RUB yoga;
    RUB pilates;
    RUB meditation;
    RUB vitamins;
    RUB supplements;
    RUB massage;
    RUB spa;
    RUB fitness_app;
    RUB sports_equipment;
    RUB sports_clothing;
};

struct Travel {
    RUB flights;
    RUB hotels;
    RUB excursions;
    RUB souvenirs;
    RUB travel_insurance;
    RUB visa;
    RUB taxi;
    RUB food_travel;
    RUB activities;
    RUB travel_gear;
    RUB luggage;
};

struct Gifts {
    RUB birthday;
    RUB new_year;
    RUB valentine;
    RUB anniversary;
    RUB wedding;
    RUB christmas;
    RUB graduation;
    RUB friends;
    RUB family;
    RUB colleagues;
};

struct Subscriptions {
    RUB netflix;
    RUB spotify;
    RUB youtube_premium;
    RUB disney_plus;
    RUB hbo;
    RUB ivi;
    RUB kinopoisk;
    RUB chatgpt;
    RUB office_365;
    RUB google_one;
    RUB icloud;
    RUB dropbox;
    RUB vpn;
    RUB fitness_app;
    RUB meditation_app;
    RUB news;
};

struct Charity {
    RUB church;
    RUB animal_shelter;
    RUB children_fund;
    RUB homeless;
    RUB ecology;
    RUB education;
    RUB medicine;
    RUB disaster_relief;
    RUB veterans;
};

struct Investments {
    RUB stocks;
    RUB bonds;
    RUB etf;
    RUB crypto;
    RUB gold;
    RUB silver;
    RUB business;
    RUB startup;
};

struct Taxes {
    RUB income_tax;
    RUB property_tax;
    RUB transport_tax;
    RUB land_tax;
    RUB dividend_tax;
    RUB tax_return;
};

struct Insurance {
    RUB life;
    RUB health;
    RUB car;
    RUB home;
    RUB travel;
    RUB pet;
};

struct Person {
    Bank vtb;
    Car car;
    RealEstate home;
    Cat cat;
    Dog dog;
    Medicine medicine;
    Freelance freelance;
    Education education;
    Entertainment entertainment;
    Clothing clothes;
    Health health;
    Travel travel;
    Gifts gifts;
    Subscriptions subs;
    Charity charity;
    Investments invest;
    Taxes taxes;
    Insurance insurance;
    RUB salary;
    RUB bonus;
    RUB food;
    RUB restaurant;
    RUB delivery;
    RUB coffee;
    RUB alcohol;
    RUB emergency_fund;
};

Person david;
Person lisa;

void david_init()
{
    david.vtb.account = 0;
    david.vtb.deposite = 1000000;
    david.vtb.interest = 14.5;
    david.salary = 300000;
    david.bonus = 50000;

    david.vtb.account_usd = 3000;
    david.vtb.rate_usd_rub = 88;
    david.vtb.account_eur = 2000;
    david.vtb.rate_eur_rub = 95;
    david.vtb.account_gbp = 1000;
    david.vtb.rate_gbp_rub = 112;
    david.vtb.account_cny = 5000;
    david.vtb.rate_cny_rub = 12.5;

    david.food = 25000;
    david.restaurant = 15000;
    david.delivery = 5000;
    david.coffee = 5000;
    david.alcohol = 5000;
    david.emergency_fund = 100000;

    david.car.value = 2500000;
    david.car.gas = 15000;
    david.car.insurance = 8000;
    david.car.tax = 3000;
    david.car.parking = 3000;
    david.car.repair = 5000;
    david.car.washing = 2000;
    david.car.winter_tires = 30000;
    david.car.summer_tires = 25000;
    david.car.oil_change = 3000;
    david.car.diagnostics = 2000;
    david.car.fines = 0;
    david.car.detailing = 5000;
    david.car.car_wash_subscription = 2000;
    david.car.new_radio = 0;
    david.car.new_seat_covers = 0;
    david.car.tire_storage = 5000;

    david.home.apartment_value = 8000000;
    david.home.house_value = 0;
    david.home.cottage_value = 0;
    david.home.land_value = 0;
    david.home.mortgage_payment = 0;
    david.home.mortgage_debt = 0;
    david.home.utilities = 12000;
    david.home.property_tax = 8000;
    david.home.repair = 5000;
    david.home.furniture = 300000;
    david.home.appliances = 150000;
    david.home.renovation = 0;
    david.home.insurance = 10000;
    david.home.internet = 1000;
    david.home.tv_subscription = 500;
    david.home.cleaning_service = 2000;
    david.home.gardening = 0;

    david.cat.food = 0;
    david.cat.vet = 0;
    david.cat.toys = 0;
    david.cat.toilet_filler = 0;
    david.cat.treats = 0;
    david.cat.scratching_post = 0;
    david.cat.bed = 0;
    david.cat.carrier = 0;
    david.cat.vaccinations = 0;

    david.dog.food = 3000;
    david.dog.vet = 2000;
    david.dog.toys = 500;
    david.dog.toilet_filler = 0;
    david.dog.treats = 1000;
    david.dog.leash = 500;
    david.dog.collar = 500;
    david.dog.bed = 2000;
    david.dog.vaccinations = 1500;
    david.dog.training = 5000;
    david.dog.walking_service = 0;
    david.dog.grooming = 1000;

    david.medicine.vitamins = 2000;
    david.medicine.cold_medicine = 1000;
    david.medicine.dentist = 3000;
    david.medicine.doctor = 2000;
    david.medicine.emergency = 0;
    david.medicine.surgery = 0;
    david.medicine.rehabilitation = 0;
    david.medicine.massage = 2000;
    david.medicine.spa = 2000;
    david.medicine.psychologist = 0;
    david.medicine.lab_tests = 1000;
    david.medicine.mri = 0;
    david.medicine.ultrasound = 0;
    david.medicine.physiotherapy = 0;

    david.freelance.design = 0;
    david.freelance.consulting = 20000;
    david.freelance.programming = 10000;
    david.freelance.writing = 0;
    david.freelance.translation = 0;
    david.freelance.tutoring = 0;
    david.freelance.photography = 0;
    david.freelance.videography = 0;
    david.freelance.web_development = 0;
    david.freelance.mobile_development = 0;
    david.freelance.seo = 0;
    david.freelance.smm = 0;

    david.education.courses = 0;
    david.education.books = 3000;
    david.education.seminars = 5000;
    david.education.webinars = 2000;
    david.education.conferences = 10000;
    david.education.online_courses = 5000;
    david.education.driving_license = 0;
    david.education.professional_cert = 0;
    david.education.language_courses = 0;
    david.education.music_school = 0;
    david.education.art_school = 0;
    david.education.coaching = 0;

    david.entertainment.cinema = 2000;
    david.entertainment.concerts = 3000;
    david.entertainment.theater = 2000;
    david.entertainment.museum = 1000;
    david.entertainment.gaming = 3000;
    david.entertainment.streaming = 1000;
    david.entertainment.hobbies = 5000;
    david.entertainment.sports = 5000;
    david.entertainment.bar = 3000;
    david.entertainment.nightclub = 0;
    david.entertainment.karaoke = 0;
    david.entertainment.bowling = 0;
    david.entertainment.paintball = 0;
    david.entertainment.quest_rooms = 0;
    david.entertainment.amusement_park = 0;
    david.entertainment.zoo = 0;
    david.entertainment.aquarium = 0;

    david.clothes.everyday = 10000;
    david.clothes.work = 15000;
    david.clothes.sport = 5000;
    david.clothes.seasonal = 10000;
    david.clothes.shoes = 8000;
    david.clothes.accessories = 3000;
    david.clothes.bags = 0;
    david.clothes.watches = 50000;
    david.clothes.jewelry = 0;
    david.clothes.underwear = 2000;
    david.clothes.outerwear = 15000;
    david.clothes.hats = 2000;
    david.clothes.scarves = 1000;
    david.clothes.gloves = 1000;

    david.health.gym = 5000;
    david.health.yoga = 2000;
    david.health.pilates = 0;
    david.health.meditation = 0;
    david.health.vitamins = 2000;
    david.health.supplements = 2000;
    david.health.massage = 3000;
    david.health.spa = 2000;
    david.health.fitness_app = 500;
    david.health.sports_equipment = 3000;
    david.health.sports_clothing = 5000;

    david.travel.flights = 50000;
    david.travel.hotels = 30000;
    david.travel.excursions = 10000;
    david.travel.souvenirs = 5000;
    david.travel.travel_insurance = 2000;
    david.travel.visa = 0;
    david.travel.taxi = 3000;
    david.travel.food_travel = 10000;
    david.travel.activities = 5000;
    david.travel.travel_gear = 5000;
    david.travel.luggage = 0;

    david.gifts.birthday = 10000;
    david.gifts.new_year = 20000;
    david.gifts.valentine = 5000;
    david.gifts.anniversary = 15000;
    david.gifts.wedding = 0;
    david.gifts.christmas = 0;
    david.gifts.graduation = 0;
    david.gifts.friends = 5000;
    david.gifts.family = 10000;
    david.gifts.colleagues = 3000;

    david.subs.netflix = 1000;
    david.subs.spotify = 500;
    david.subs.youtube_premium = 400;
    david.subs.disney_plus = 0;
    david.subs.hbo = 0;
    david.subs.ivi = 0;
    david.subs.kinopoisk = 0;
    david.subs.chatgpt = 800;
    david.subs.office_365 = 500;
    david.subs.google_one = 200;
    david.subs.icloud = 200;
    david.subs.dropbox = 0;
    david.subs.vpn = 300;
    david.subs.fitness_app = 500;
    david.subs.meditation_app = 0;
    david.subs.news = 300;

    david.charity.church = 1000;
    david.charity.animal_shelter = 1000;
    david.charity.children_fund = 1000;
    david.charity.homeless = 500;
    david.charity.ecology = 500;
    david.charity.education = 500;
    david.charity.medicine = 500;
    david.charity.disaster_relief = 0;
    david.charity.veterans = 0;

    david.invest.stocks = 300000;
    david.invest.bonds = 200000;
    david.invest.etf = 150000;
    david.invest.crypto = 50000;
    david.invest.gold = 100000;
    david.invest.silver = 30000;
    david.invest.business = 200000;
    david.invest.startup = 0;

    david.taxes.income_tax = 45000;
    david.taxes.property_tax = 8000;
    david.taxes.transport_tax = 3000;
    david.taxes.land_tax = 0;
    david.taxes.dividend_tax = 2000;
    david.taxes.tax_return = 0;

    david.insurance.life = 5000;
    david.insurance.health = 5000;
    david.insurance.car = 8000;
    david.insurance.home = 3000;
    david.insurance.travel = 1000;
    david.insurance.pet = 1000;
}

void lisa_init()
{
    lisa.vtb.account = 25000;
    lisa.vtb.deposite = 0;
    lisa.vtb.interest = 12.0;
    lisa.salary = 100000;
    lisa.bonus = 10000;

    lisa.vtb.account_usd = 100;
    lisa.vtb.rate_usd_rub = 88;
    lisa.vtb.account_eur = 200;
    lisa.vtb.rate_eur_rub = 95;
    lisa.vtb.account_gbp = 0;
    lisa.vtb.rate_gbp_rub = 112;
    lisa.vtb.account_cny = 0;
    lisa.vtb.rate_cny_rub = 12.5;

    lisa.food = 20000;
    lisa.restaurant = 20000;
    lisa.delivery = 8000;
    lisa.coffee = 4000;
    lisa.alcohol = 3000;
    lisa.emergency_fund = 0;

    lisa.car.value = 800000;
    lisa.car.gas = 8000;
    lisa.car.insurance = 5000;
    lisa.car.tax = 2000;
    lisa.car.parking = 2000;
    lisa.car.repair = 3000;
    lisa.car.washing = 1000;
    lisa.car.winter_tires = 20000;
    lisa.car.summer_tires = 15000;
    lisa.car.oil_change = 2000;
    lisa.car.diagnostics = 1000;
    lisa.car.fines = 0;
    lisa.car.detailing = 3000;
    lisa.car.car_wash_subscription = 1000;
    lisa.car.new_radio = 0;
    lisa.car.new_seat_covers = 0;
    lisa.car.tire_storage = 3000;

    lisa.home.apartment_value = 0;
    lisa.home.house_value = 0;
    lisa.home.cottage_value = 0;
    lisa.home.land_value = 0;
    lisa.home.mortgage_payment = 45000;
    lisa.home.mortgage_debt = 3500000;
    lisa.home.utilities = 8000;
    lisa.home.property_tax = 0;
    lisa.home.repair = 2000;
    lisa.home.furniture = 200000;
    lisa.home.appliances = 100000;
    lisa.home.renovation = 0;
    lisa.home.insurance = 0;
    lisa.home.internet = 1000;
    lisa.home.tv_subscription = 500;
    lisa.home.cleaning_service = 1000;
    lisa.home.gardening = 0;

    lisa.cat.food = 2000;
    lisa.cat.vet = 1000;
    lisa.cat.toys = 300;
    lisa.cat.toilet_filler = 500;
    lisa.cat.treats = 500;
    lisa.cat.scratching_post = 1000;
    lisa.cat.bed = 1500;
    lisa.cat.carrier = 1000;
    lisa.cat.vaccinations = 1000;

    lisa.dog.food = 0;
    lisa.dog.vet = 0;
    lisa.dog.toys = 0;
    lisa.dog.toilet_filler = 0;
    lisa.dog.treats = 0;
    lisa.dog.leash = 0;
    lisa.dog.collar = 0;
    lisa.dog.bed = 0;
    lisa.dog.vaccinations = 0;
    lisa.dog.training = 0;
    lisa.dog.walking_service = 0;
    lisa.dog.grooming = 0;

    lisa.medicine.vitamins = 1500;
    lisa.medicine.cold_medicine = 800;
    lisa.medicine.dentist = 5000;
    lisa.medicine.doctor = 2000;
    lisa.medicine.emergency = 0;
    lisa.medicine.surgery = 0;
    lisa.medicine.rehabilitation = 0;
    lisa.medicine.massage = 2000;
    lisa.medicine.spa = 3000;
    lisa.medicine.psychologist = 2000;
    lisa.medicine.lab_tests = 1000;
    lisa.medicine.mri = 0;
    lisa.medicine.ultrasound = 0;
    lisa.medicine.physiotherapy = 0;

    lisa.freelance.design = 5000;
    lisa.freelance.consulting = 0;
    lisa.freelance.programming = 0;
    lisa.freelance.writing = 0;
    lisa.freelance.translation = 0;
    lisa.freelance.tutoring = 0;
    lisa.freelance.photography = 2000;
    lisa.freelance.videography = 0;
    lisa.freelance.web_development = 0;
    lisa.freelance.mobile_development = 0;
    lisa.freelance.seo = 0;
    lisa.freelance.smm = 3000;

    lisa.education.courses = 5000;
    lisa.education.books = 2000;
    lisa.education.seminars = 3000;
    lisa.education.webinars = 1000;
    lisa.education.conferences = 0;
    lisa.education.online_courses = 3000;
    lisa.education.driving_license = 0;
    lisa.education.professional_cert = 5000;
    lisa.education.language_courses = 10000;
    lisa.education.music_school = 0;
    lisa.education.art_school = 5000;
    lisa.education.coaching = 3000;

    lisa.entertainment.cinema = 3000;
    lisa.entertainment.concerts = 5000;
    lisa.entertainment.theater = 2000;
    lisa.entertainment.museum = 1000;
    lisa.entertainment.gaming = 2000;
    lisa.entertainment.streaming = 1000;
    lisa.entertainment.hobbies = 5000;
    lisa.entertainment.sports = 2000;
    lisa.entertainment.bar = 3000;
    lisa.entertainment.nightclub = 3000;
    lisa.entertainment.karaoke = 2000;
    lisa.entertainment.bowling = 2000;
    lisa.entertainment.paintball = 0;
    lisa.entertainment.quest_rooms = 2000;
    lisa.entertainment.amusement_park = 3000;
    lisa.entertainment.zoo = 1000;
    lisa.entertainment.aquarium = 1000;

    lisa.clothes.everyday = 15000;
    lisa.clothes.work = 10000;
    lisa.clothes.sport = 5000;
    lisa.clothes.seasonal = 10000;
    lisa.clothes.shoes = 8000;
    lisa.clothes.accessories = 5000;
    lisa.clothes.bags = 10000;
    lisa.clothes.watches = 10000;
    lisa.clothes.jewelry = 5000;
    lisa.clothes.underwear = 3000;
    lisa.clothes.outerwear = 15000;
    lisa.clothes.hats = 2000;
    lisa.clothes.scarves = 1000;
    lisa.clothes.gloves = 1000;

    lisa.health.gym = 4000;
    lisa.health.yoga = 2000;
    lisa.health.pilates = 2000;
    lisa.health.meditation = 500;
    lisa.health.vitamins = 1500;
    lisa.health.supplements = 1000;
    lisa.health.massage = 3000;
    lisa.health.spa = 4000;
    lisa.health.fitness_app = 500;
    lisa.health.sports_equipment = 2000;
    lisa.health.sports_clothing = 5000;

    lisa.travel.flights = 30000;
    lisa.travel.hotels = 20000;
    lisa.travel.excursions = 5000;
    lisa.travel.souvenirs = 3000;
    lisa.travel.travel_insurance = 1000;
    lisa.travel.visa = 0;
    lisa.travel.taxi = 2000;
    lisa.travel.food_travel = 5000;
    lisa.travel.activities = 3000;
    lisa.travel.travel_gear = 3000;
    lisa.travel.luggage = 5000;

    lisa.gifts.birthday = 10000;
    lisa.gifts.new_year = 15000;
    lisa.gifts.valentine = 5000;
    lisa.gifts.anniversary = 10000;
    lisa.gifts.wedding = 5000;
    lisa.gifts.christmas = 0;
    lisa.gifts.graduation = 0;
    lisa.gifts.friends = 5000;
    lisa.gifts.family = 10000;
    lisa.gifts.colleagues = 2000;

    lisa.subs.netflix = 0;
    lisa.subs.spotify = 500;
    lisa.subs.youtube_premium = 400;
    lisa.subs.disney_plus = 800;
    lisa.subs.hbo = 0;
    lisa.subs.ivi = 500;
    lisa.subs.kinopoisk = 0;
    lisa.subs.chatgpt = 0;
    lisa.subs.office_365 = 0;
    lisa.subs.google_one = 0;
    lisa.subs.icloud = 200;
    lisa.subs.dropbox = 0;
    lisa.subs.vpn = 0;
    lisa.subs.fitness_app = 500;
    lisa.subs.meditation_app = 500;
    lisa.subs.news = 0;

    lisa.charity.church = 0;
    lisa.charity.animal_shelter = 500;
    lisa.charity.children_fund = 500;
    lisa.charity.homeless = 300;
    lisa.charity.ecology = 200;
    lisa.charity.education = 0;
    lisa.charity.medicine = 0;
    lisa.charity.disaster_relief = 0;
    lisa.charity.veterans = 0;

    lisa.invest.stocks = 20000;
    lisa.invest.bonds = 0;
    lisa.invest.etf = 0;
    lisa.invest.crypto = 10000;
    lisa.invest.gold = 15000;
    lisa.invest.silver = 0;
    lisa.invest.business = 0;
    lisa.invest.startup = 0;

    lisa.taxes.income_tax = 15000;
    lisa.taxes.property_tax = 0;
    lisa.taxes.transport_tax = 2000;
    lisa.taxes.land_tax = 0;
    lisa.taxes.dividend_tax = 0;
    lisa.taxes.tax_return = 0;

    lisa.insurance.life = 0;
    lisa.insurance.health = 3000;
    lisa.insurance.car = 5000;
    lisa.insurance.home = 0;
    lisa.insurance.travel = 0;
    lisa.insurance.pet = 0;
}

void david_salary(const int month, const int year)
{
    if (month == 12) {
        david.vtb.account += david.bonus;
    }

    if (month == 1 and year == 2027) {
        david.salary = 350000;
    }

    if (month == 1 and year == 2028) {
        david.salary = 400000;
    }

    david.vtb.account += david.salary;
}

void lisa_salary(const int month, const int year)
{
    if (month == 12) {
        lisa.vtb.account += lisa.bonus;
    }

    if (month == 1 and year == 2027) {
        lisa.salary = 120000;
    }

    if (month == 1 and year == 2028) {
        lisa.salary = 140000;
    }

    lisa.vtb.account += lisa.salary;
}

void david_freelance(const int month, const int year)
{
    if (month == 2 and year == 2026) {
        david.vtb.account += david.freelance.consulting;
    }
    if (month == 5 and year == 2026) {
        david.vtb.account += david.freelance.programming;
    }
    if (month == 8 and year == 2026) {
        david.vtb.account += david.freelance.consulting;
    }
    if (month == 11 and year == 2026) {
        david.vtb.account += david.freelance.programming;
    }
    if (month == 2 and year == 2027) {
        david.vtb.account += david.freelance.consulting * 2;
    }
    if (month == 6 and year == 2027) {
        david.vtb.account += david.freelance.programming * 2;
    }
    if (month == 10 and year == 2027) {
        david.vtb.account += david.freelance.consulting;
    }
    if (month == 3 and year == 2028) {
        david.vtb.account += david.freelance.programming * 2;
    }
    if (month == 7 and year == 2028) {
        david.vtb.account += david.freelance.consulting;
    }
}

void lisa_freelance(const int month, const int year)
{
    if (month == 3 and year == 2026) {
        lisa.vtb.account += lisa.freelance.design;
    }
    if (month == 6 and year == 2026) {
        lisa.vtb.account += lisa.freelance.design;
    }
    if (month == 9 and year == 2026) {
        lisa.vtb.account += lisa.freelance.design;
    }
    if (month == 12 and year == 2026) {
        lisa.vtb.account += lisa.freelance.design * 2;
    }
    if (month == 4 and year == 2027) {
        lisa.vtb.account += lisa.freelance.design * 2;
    }
    if (month == 8 and year == 2027) {
        lisa.vtb.account += lisa.freelance.design;
    }
    if (month == 12 and year == 2027) {
        lisa.vtb.account += lisa.freelance.design * 2;
    }
    if (month == 5 and year == 2028) {
        lisa.vtb.account += lisa.freelance.design;
    }
    if (month == 10 and year == 2028) {
        lisa.vtb.account += lisa.freelance.design * 2;
    }
    if (month == 2 and year == 2027) {
        lisa.vtb.account += lisa.freelance.photography;
    }
    if (month == 7 and year == 2027) {
        lisa.vtb.account += lisa.freelance.smm;
    }
    if (month == 11 and year == 2028) {
        lisa.vtb.account += lisa.freelance.photography * 2;
    }
}

void david_food(const int month, const int year)
{
    david.vtb.account -= david.food;
    david.vtb.account -= david.restaurant;
    david.vtb.account -= david.delivery;
    david.vtb.account -= david.coffee;
    david.vtb.account -= david.alcohol;
}

void lisa_food(const int month, const int year)
{
    lisa.vtb.account -= lisa.food;
    lisa.vtb.account -= lisa.restaurant;
    lisa.vtb.account -= lisa.delivery;
    lisa.vtb.account -= lisa.coffee;
    lisa.vtb.account -= lisa.alcohol;
}

void david_entertainment(const int month, const int year)
{
    if (month == 2) {
        david.vtb.account -= david.entertainment.cinema * 2;
        david.vtb.account -= david.entertainment.bar;
    }
    if (month == 4 or month == 8 or month == 10) {
        david.vtb.account -= david.entertainment.cinema;
        david.vtb.account -= david.entertainment.gaming;
        david.vtb.account -= david.entertainment.hobbies;
    }
    if (month == 6) {
        david.vtb.account -= david.entertainment.concerts;
        david.vtb.account -= david.entertainment.sports;
    }
    if (month == 12) {
        david.vtb.account -= david.entertainment.theater;
        david.vtb.account -= david.entertainment.museum;
        david.vtb.account -= 20000;
    }
    if (month == 7) {
        david.vtb.account -= david.entertainment.streaming * 12;
    }
}

void lisa_entertainment(const int month, const int year)
{
    if (month == 2) {
        lisa.vtb.account -= lisa.entertainment.cinema;
        lisa.vtb.account -= lisa.entertainment.bar;
        lisa.vtb.account -= lisa.entertainment.nightclub;
    }
    if (month == 3 or month == 6 or month == 9) {
        lisa.vtb.account -= lisa.entertainment.concerts;
        lisa.vtb.account -= lisa.entertainment.gaming;
        lisa.vtb.account -= lisa.entertainment.hobbies;
    }
    if (month == 5 or month == 11) {
        lisa.vtb.account -= lisa.entertainment.karaoke;
        lisa.vtb.account -= lisa.entertainment.bowling;
        lisa.vtb.account -= lisa.entertainment.quest_rooms;
    }
    if (month == 7) {
        lisa.vtb.account -= lisa.entertainment.amusement_park;
        lisa.vtb.account -= lisa.entertainment.zoo;
    }
    if (month == 12) {
        lisa.vtb.account -= lisa.entertainment.theater;
        lisa.vtb.account -= 30000;
    }
}

void david_clothes(const int month, const int year)
{
    if (month == 3 or month == 9) {
        david.vtb.account -= david.clothes.everyday;
        david.vtb.account -= david.clothes.work;
    }
    if (month == 5) {
        david.vtb.account -= david.clothes.sport;
        david.vtb.account -= david.clothes.shoes;
    }
    if (month == 11) {
        david.vtb.account -= david.clothes.seasonal;
        david.vtb.account -= david.clothes.outerwear;
        david.vtb.account -= david.clothes.hats;
        david.vtb.account -= david.clothes.gloves;
    }
    if (month == 4) {
        david.vtb.account -= david.clothes.accessories;
        david.vtb.account -= david.clothes.underwear;
    }
}

void lisa_clothes(const int month, const int year)
{
    if (month == 2 or month == 5 or month == 8 or month == 11) {
        lisa.vtb.account -= lisa.clothes.everyday;
        lisa.vtb.account -= lisa.clothes.work;
    }
    if (month == 3 or month == 9) {
        lisa.vtb.account -= lisa.clothes.sport;
        lisa.vtb.account -= lisa.clothes.shoes;
        lisa.vtb.account -= lisa.clothes.accessories;
    }
    if (month == 4 or month == 10) {
        lisa.vtb.account -= lisa.clothes.seasonal;
        lisa.vtb.account -= lisa.clothes.outerwear;
    }
    if (month == 6) {
        lisa.vtb.account -= lisa.clothes.bags;
        lisa.vtb.account -= lisa.clothes.jewelry;
    }
    if (month == 12) {
        lisa.vtb.account -= lisa.clothes.hats;
        lisa.vtb.account -= lisa.clothes.scarves;
        lisa.vtb.account -= lisa.clothes.gloves;
    }
}

void david_health(const int month, const int year)
{
    if (month == 1) {
        david.vtb.account -= david.health.gym * 12;
        david.vtb.account -= david.health.vitamins;
    }
    if (month == 6) {
        david.vtb.account -= david.health.massage;
        david.vtb.account -= david.health.spa;
    }
    if (month == 9) {
        david.vtb.account -= david.health.sports_equipment;
        david.vtb.account -= david.health.sports_clothing;
    }
    if (month == 4) {
        david.vtb.account -= david.health.yoga;
    }
}

void lisa_health(const int month, const int year)
{
    if (month == 1 or month == 7) {
        lisa.vtb.account -= lisa.health.gym * 12;
        lisa.vtb.account -= lisa.health.vitamins;
    }
    if (month == 3) {
        lisa.vtb.account -= lisa.health.yoga;
        lisa.vtb.account -= lisa.health.pilates;
    }
    if (month == 5) {
        lisa.vtb.account -= lisa.health.massage;
        lisa.vtb.account -= lisa.health.spa;
    }
    if (month == 9) {
        lisa.vtb.account -= lisa.health.sports_equipment;
        lisa.vtb.account -= lisa.health.sports_clothing;
    }
    if (month == 11) {
        lisa.vtb.account -= lisa.health.meditation;
    }
}

void david_charity(const int month, const int year)
{
    if (month == 12) {
        david.vtb.account -= david.charity.church;
        david.vtb.account -= david.charity.animal_shelter;
        david.vtb.account -= david.charity.children_fund;
        david.vtb.account -= david.charity.homeless;
        david.vtb.account -= david.charity.ecology;
    }
}

void lisa_charity(const int month, const int year)
{
    if (month == 12) {
        lisa.vtb.account -= lisa.charity.animal_shelter;
        lisa.vtb.account -= lisa.charity.children_fund;
        lisa.vtb.account -= lisa.charity.homeless;
    }
}

void david_subscriptions(const int month, const int year)
{
    david.vtb.account -= david.subs.netflix;
    david.vtb.account -= david.subs.spotify;
    david.vtb.account -= david.subs.youtube_premium;
    david.vtb.account -= david.subs.chatgpt;
    david.vtb.account -= david.subs.office_365;
    david.vtb.account -= david.subs.google_one;
    david.vtb.account -= david.subs.icloud;
    david.vtb.account -= david.subs.vpn;
    david.vtb.account -= david.subs.fitness_app;
    david.vtb.account -= david.subs.news;
}

void lisa_subscriptions(const int month, const int year)
{
    lisa.vtb.account -= lisa.subs.spotify;
    lisa.vtb.account -= lisa.subs.youtube_premium;
    lisa.vtb.account -= lisa.subs.disney_plus;
    lisa.vtb.account -= lisa.subs.ivi;
    lisa.vtb.account -= lisa.subs.icloud;
    lisa.vtb.account -= lisa.subs.fitness_app;
    lisa.vtb.account -= lisa.subs.meditation_app;
}

void david_travel(const int month, const int year)
{
    if (month == 7) {
        david.vtb.account -= david.travel.flights;
        david.vtb.account -= david.travel.hotels;
        david.vtb.account -= david.travel.excursions;
        david.vtb.account -= david.travel.souvenirs;
        david.vtb.account -= david.travel.travel_insurance;
        david.vtb.account -= david.travel.taxi;
        david.vtb.account -= david.travel.food_travel;
        david.vtb.account -= david.travel.activities;
    }
    if (month == 1 and year == 2027) {
        david.vtb.account -= 50000;
        david.vtb.account -= david.travel.travel_gear;
    }
}

void lisa_travel(const int month, const int year)
{
    if (month == 8) {
        lisa.vtb.account -= lisa.travel.flights;
        lisa.vtb.account -= lisa.travel.hotels;
        lisa.vtb.account -= lisa.travel.excursions;
        lisa.vtb.account -= lisa.travel.souvenirs;
        lisa.vtb.account -= lisa.travel.travel_insurance;
        lisa.vtb.account -= lisa.travel.taxi;
        lisa.vtb.account -= lisa.travel.food_travel;
        lisa.vtb.account -= lisa.travel.activities;
    }
    if (month == 2 and year == 2027) {
        lisa.vtb.account -= 30000;
        lisa.vtb.account -= lisa.travel.luggage;
    }
}

void david_gifts(const int month, const int year)
{
    if (month == 2) {
        david.vtb.account -= david.gifts.valentine;
    }
    if (month == 3) {
        david.vtb.account -= david.gifts.anniversary;
    }
    if (month == 5) {
        david.vtb.account -= david.gifts.birthday;
    }
    if (month == 12) {
        david.vtb.account -= david.gifts.new_year;
        david.vtb.account -= david.gifts.friends;
        david.vtb.account -= david.gifts.family;
        david.vtb.account -= david.gifts.colleagues;
    }
}

void lisa_gifts(const int month, const int year)
{
    if (month == 2) {
        lisa.vtb.account -= lisa.gifts.valentine;
    }
    if (month == 3) {
        lisa.vtb.account -= lisa.gifts.anniversary;
    }
    if (month == 6) {
        lisa.vtb.account -= lisa.gifts.wedding;
    }
    if (month == 8) {
        lisa.vtb.account -= lisa.gifts.birthday;
    }
    if (month == 12) {
        lisa.vtb.account -= lisa.gifts.new_year;
        lisa.vtb.account -= lisa.gifts.friends;
        lisa.vtb.account -= lisa.gifts.family;
    }
}

void david_education(const int month, const int year)
{
    if (month == 9) {
        david.vtb.account -= david.education.books;
        david.vtb.account -= david.education.seminars;
        david.vtb.account -= david.education.webinars;
        david.vtb.account -= david.education.online_courses;
    }
    if (month == 10 and year == 2027) {
        david.vtb.account -= david.education.conferences;
    }
}

void lisa_education(const int month, const int year)
{
    if (month == 9) {
        lisa.vtb.account -= lisa.education.courses;
        lisa.vtb.account -= lisa.education.books;
        lisa.vtb.account -= lisa.education.online_courses;
    }
    if (month == 1 and year == 2027) {
        lisa.vtb.account -= 20000;
        lisa.vtb.account -= lisa.education.language_courses;
    }
    if (month == 2 and year == 2028) {
        lisa.vtb.account -= lisa.education.professional_cert;
    }
    if (month == 4) {
        lisa.vtb.account -= lisa.education.art_school;
    }
}

void david_cat(const int month, const int year)
{
    david.vtb.account -= david.cat.food;
    david.vtb.account -= david.cat.toilet_filler;
    if (month == 3 or month == 9) {
        david.vtb.account -= david.cat.vet;
    }
    if (month == 6 or month == 12) {
        david.vtb.account -= david.cat.toys;
    }
}

void lisa_cat(const int month, const int year)
{
    lisa.vtb.account -= lisa.cat.food;
    lisa.vtb.account -= lisa.cat.toilet_filler;
    lisa.vtb.account -= lisa.cat.treats;
    if (month == 5 or month == 11) {
        lisa.vtb.account -= lisa.cat.vet;
        lisa.vtb.account -= lisa.cat.vaccinations;
    }
    if (month == 3 or month == 9) {
        lisa.vtb.account -= lisa.cat.toys;
        lisa.vtb.account -= lisa.cat.scratching_post;
    }
    if (month == 1 and year == 2027) {
        lisa.vtb.account -= lisa.cat.bed;
        lisa.vtb.account -= lisa.cat.carrier;
    }
}

void david_dog(const int month, const int year)
{
    david.vtb.account -= david.dog.food;
    david.vtb.account -= david.dog.treats;
    if (month == 4 or month == 10) {
        david.vtb.account -= david.dog.vet;
        david.vtb.account -= david.dog.vaccinations;
    }
    if (month == 6 or month == 12) {
        david.vtb.account -= david.dog.toys;
    }
    if (month == 8) {
        david.vtb.account -= david.dog.grooming;
    }
    if (month == 1 and year == 2027) {
        david.vtb.account -= david.dog.training;
    }
    if (month == 1 and year == 2028) {
        david.vtb.account -= david.dog.bed;
    }
}

void lisa_dog(const int month, const int year)
{
    lisa.vtb.account -= lisa.dog.food;
    lisa.vtb.account -= lisa.dog.treats;
    if (month == 4 or month == 10) {
        lisa.vtb.account -= lisa.dog.vet;
    }
    if (month == 6 or month == 12) {
        lisa.vtb.account -= lisa.dog.toys;
    }
}

void david_medicine(const int month, const int year)
{
    david.vtb.account -= david.medicine.vitamins;
    if (month == 2 or month == 11) {
        david.vtb.account -= david.medicine.cold_medicine;
    }
    if (month == 4) {
        david.vtb.account -= david.medicine.dentist;
    }
    if (month == 10) {
        david.vtb.account -= david.medicine.doctor;
        david.vtb.account -= david.medicine.lab_tests;
    }
    if (month == 6) {
        david.vtb.account -= david.medicine.massage;
    }
}

void lisa_medicine(const int month, const int year)
{
    lisa.vtb.account -= lisa.medicine.vitamins;
    if (month == 1 or month == 12) {
        lisa.vtb.account -= lisa.medicine.cold_medicine;
    }
    if (month == 5) {
        lisa.vtb.account -= lisa.medicine.dentist;
    }
    if (month == 9) {
        lisa.vtb.account -= lisa.medicine.doctor;
        lisa.vtb.account -= lisa.medicine.lab_tests;
    }
    if (month == 3) {
        lisa.vtb.account -= lisa.medicine.massage;
    }
    if (month == 7) {
        lisa.vtb.account -= lisa.medicine.spa;
    }
    if (month == 11) {
        lisa.vtb.account -= lisa.medicine.psychologist;
    }
}

void david_car(const int month, const int year)
{
    david.vtb.account -= david.car.gas;
    david.vtb.account -= david.car.insurance / 12;
    david.vtb.account -= david.car.tax / 12;
    david.vtb.account -= david.car.parking;
    david.vtb.account -= david.car.washing;
    david.vtb.account -= david.car.car_wash_subscription;

    if (month == 4) {
        david.vtb.account -= david.car.repair;
        david.vtb.account -= david.car.diagnostics;
        david.vtb.account -= david.car.oil_change;
    }
    if (month == 10) {
        david.vtb.account -= david.car.winter_tires;
        david.vtb.account -= david.car.tire_storage;
    }
    if (month == 4 and year == 2027) {
        david.vtb.account -= david.car.summer_tires;
    }
    if (month == 5 and year == 2027) {
        david.vtb.account -= david.car.detailing;
    }
    if (month == 8 and year == 2028) {
        david.vtb.account -= david.car.fines;
    }
}

void lisa_car(const int month, const int year)
{
    lisa.vtb.account -= lisa.car.gas;
    lisa.vtb.account -= lisa.car.insurance / 12;
    lisa.vtb.account -= lisa.car.tax / 12;
    lisa.vtb.account -= lisa.car.parking;
    lisa.vtb.account -= lisa.car.washing;
    lisa.vtb.account -= lisa.car.car_wash_subscription;

    if (month == 5) {
        lisa.vtb.account -= lisa.car.repair;
        lisa.vtb.account -= lisa.car.diagnostics;
        lisa.vtb.account -= lisa.car.oil_change;
    }
    if (month == 10) {
        lisa.vtb.account -= lisa.car.winter_tires;
        lisa.vtb.account -= lisa.car.tire_storage;
    }
    if (month == 4 and year == 2027) {
        lisa.vtb.account -= lisa.car.summer_tires;
    }
    if (month == 7 and year == 2027) {
        lisa.vtb.account -= lisa.car.detailing;
    }
}

void david_home(const int month, const int year)
{
    david.vtb.account -= david.home.utilities;
    david.vtb.account -= david.home.property_tax / 12;
    david.vtb.account -= david.home.internet;
    david.vtb.account -= david.home.tv_subscription;

    if (month == 6) {
        david.vtb.account -= david.home.repair;
    }
    if (month == 1 and year == 2027) {
        david.vtb.account -= david.home.furniture / 5;
    }
    if (month == 1 and year == 2028) {
        david.vtb.account -= david.home.appliances / 3;
    }
    if (month == 3) {
        david.vtb.account -= david.home.cleaning_service;
    }
    if (month == 5 and year == 2028) {
        david.vtb.account -= david.home.insurance;
    }
}

void lisa_home(const int month, const int year)
{
    lisa.vtb.account -= lisa.home.utilities;
    lisa.vtb.account -= lisa.home.mortgage_payment;
    lisa.vtb.account -= lisa.home.internet;
    lisa.vtb.account -= lisa.home.tv_subscription;

    if (month == 7) {
        lisa.vtb.account -= lisa.home.repair;
    }
    if (month == 3 and year == 2027) {
        lisa.vtb.account -= lisa.home.furniture / 4;
    }
    if (month == 9 and year == 2027) {
        lisa.vtb.account -= lisa.home.appliances / 2;
    }
    if (month == 11) {
        lisa.vtb.account -= lisa.home.cleaning_service;
    }
}

void david_tax_return(const int month, const int year)
{
    if (month == 4 and year == 2027) {
        david.taxes.tax_return = 30000;
        david.vtb.account += david.taxes.tax_return;
    }
    if (month == 4 and year == 2028) {
        david.taxes.tax_return = 35000;
        david.vtb.account += david.taxes.tax_return;
    }
}

void lisa_tax_return(const int month, const int year)
{
    if (month == 4 and year == 2027) {
        lisa.taxes.tax_return = 15000;
        lisa.vtb.account += lisa.taxes.tax_return;
    }
    if (month == 4 and year == 2028) {
        lisa.taxes.tax_return = 18000;
        lisa.vtb.account += lisa.taxes.tax_return;
    }
}

void david_emergency(const int month, const int year)
{
    if (month == 8 and year == 2027) {
        david.medicine.emergency = 50000;
        david.vtb.account -= david.medicine.emergency;
        david.emergency_fund -= david.medicine.emergency;
    }
    if (month == 2 and year == 2028) {
        david.car.repair = 30000;
        david.vtb.account -= david.car.repair;
    }
    if (month == 11 and year == 2026) {
        david.medicine.surgery = 80000;
        david.vtb.account -= david.medicine.surgery;
    }
    if (month == 7 and year == 2028) {
        david.home.repair = 40000;
        david.vtb.account -= david.home.repair;
    }
}

void lisa_emergency(const int month, const int year)
{
    if (month == 5 and year == 2026) {
        lisa.medicine.emergency = 20000;
        lisa.vtb.account -= lisa.medicine.emergency;
    }
    if (month == 9 and year == 2027) {
        lisa.car.repair = 25000;
        lisa.vtb.account -= lisa.car.repair;
    }
    if (month == 11 and year == 2028) {
        lisa.medicine.emergency = 15000;
        lisa.vtb.account -= lisa.medicine.emergency;
    }
    if (month == 3 and year == 2026) {
        lisa.medicine.mri = 12000;
        lisa.vtb.account -= lisa.medicine.mri;
    }
    if (month == 10 and year == 2027) {
        lisa.home.repair = 15000;
        lisa.vtb.account -= lisa.home.repair;
    }
}

void david_investments(const int month, const int year)
{
    if (david.vtb.account > 200000) {
        RUB invest = david.vtb.account * 0.3;
        david.invest.stocks += invest * 0.4;
        david.invest.bonds += invest * 0.2;
        david.invest.etf += invest * 0.15;
        david.invest.gold += invest * 0.1;
        david.invest.crypto += invest * 0.1;
        david.invest.business += invest * 0.05;
        david.vtb.account -= invest;
    }

    int market = (year - 2026) * 2 + (month / 4);
    david.invest.stocks += david.invest.stocks * (5 + market) / 1000;
    david.invest.bonds += david.invest.bonds * 3 / 1000;
    david.invest.etf += david.invest.etf * 4 / 1000;
    david.invest.gold += david.invest.gold * 2 / 1000;

    if (month == 12) {
        david.invest.crypto += david.invest.crypto * (rand() % 20 - 5) / 100;
    }
}

void lisa_investments(const int month, const int year)
{
    if (lisa.vtb.account > 50000) {
        RUB invest = lisa.vtb.account * 0.2;
        lisa.invest.stocks += invest * 0.5;
        lisa.invest.gold += invest * 0.3;
        lisa.invest.crypto += invest * 0.2;
        lisa.vtb.account -= invest;
    }

    lisa.invest.stocks += lisa.invest.stocks * 3 / 1000;
    lisa.invest.gold += lisa.invest.gold * 2 / 1000;

    if (month == 6) {
        lisa.invest.crypto += lisa.invest.crypto * (rand() % 30 - 10) / 100;
    }
}

void david_deposite(const int month, const int year)
{
    if (year == 2026) david.vtb.interest = 14.5;
    if (year == 2027) david.vtb.interest = 13.5;
    if (year == 2028) david.vtb.interest = 12.5;

    david.vtb.deposite += david.vtb.deposite * (david.vtb.interest / 12.0 / 100.0);

    if (david.vtb.account > 100000) {
        RUB transfer = david.vtb.account * 0.5;
        david.vtb.deposite += transfer;
        david.vtb.account -= transfer;
    }
}

void lisa_deposite(const int month, const int year)
{
    if (year == 2026) lisa.vtb.interest = 12.0;
    if (year == 2027) lisa.vtb.interest = 11.0;
    if (year == 2028) lisa.vtb.interest = 10.0;

    lisa.vtb.deposite += lisa.vtb.deposite * (lisa.vtb.interest / 12.0 / 100.0);

    if (lisa.vtb.account > 50000) {
        RUB transfer = lisa.vtb.account * 0.3;
        lisa.vtb.deposite += transfer;
        lisa.vtb.account -= transfer;
    }
}

void david_currency(const int month, const int year)
{
    if (year == 2026) {
        david.vtb.rate_usd_rub = 85;
        david.vtb.rate_eur_rub = 92;
        david.vtb.rate_gbp_rub = 108;
        david.vtb.rate_cny_rub = 12;
    }
    if (year == 2027) {
        david.vtb.rate_usd_rub = 90;
        david.vtb.rate_eur_rub = 98;
        david.vtb.rate_gbp_rub = 115;
        david.vtb.rate_cny_rub = 12.8;
    }
    if (year == 2028) {
        david.vtb.rate_usd_rub = 95;
        david.vtb.rate_eur_rub = 102;
        david.vtb.rate_gbp_rub = 120;
        david.vtb.rate_cny_rub = 13.5;
    }
}

void lisa_currency(const int month, const int year)
{
    if (year == 2026) {
        lisa.vtb.rate_usd_rub = 85;
        lisa.vtb.rate_eur_rub = 92;
    }
    if (year == 2027) {
        lisa.vtb.rate_usd_rub = 90;
        lisa.vtb.rate_eur_rub = 98;
    }
    if (year == 2028) {
        lisa.vtb.rate_usd_rub = 95;
        lisa.vtb.rate_eur_rub = 102;
    }
}

void david_loan(const int month, const int year)
{
    if (year == 2026 and david.vtb.account < 100000) {
        david.vtb.account += 500000;
    }
}

void lisa_loan(const int month, const int year)
{
    if (lisa.vtb.account < 0) {
        lisa.vtb.account += 100000;
        lisa.home.mortgage_debt += 100000;
    }
    if (year == 2027 and lisa.vtb.account < 50000) {
        lisa.vtb.account += 200000;
        lisa.home.mortgage_debt += 200000;
    }
}

void david_special_events(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        david.vtb.account += 100000;
    }
    if (month == 9 and year == 2027) {
        david.vtb.account -= 150000;
    }
    if (month == 12 and year == 2028) {
        david.vtb.account += david.emergency_fund;
    }
    if (month == 6 and year == 2026) {
        david.vtb.account += 50000;
    }
}

void lisa_special_events(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        lisa.vtb.account += 50000;
    }
    if (month == 9 and year == 2027) {
        lisa.vtb.account -= 50000;
    }
    if (month == 6 and year == 2028) {
        lisa.vtb.account -= 80000;
    }
    if (month == 12 and year == 2026) {
        lisa.vtb.account += 30000;
    }
    if (month == 1 and year == 2028) {
        lisa.vtb.account -= 40000;
    }
}

void david_insurance(const int month, const int year)
{
    if (month == 1) {
        david.vtb.account -= david.insurance.life;
        david.vtb.account -= david.insurance.health;
        david.vtb.account -= david.insurance.home;
    }
    if (month == 6) {
        david.vtb.account -= david.insurance.car;
    }
    if (month == 3) {
        david.vtb.account -= david.insurance.travel;
    }
    if (month == 9) {
        david.vtb.account -= david.insurance.pet;
    }
}

void lisa_insurance(const int month, const int year)
{
    if (month == 1) {
        lisa.vtb.account -= lisa.insurance.health;
    }
    if (month == 6) {
        lisa.vtb.account -= lisa.insurance.car;
    }
}

void david_beauty(const int month, const int year)
{
    if (month == 5) {
        david.vtb.account -= 3000;
    }
    if (month == 10) {
        david.vtb.account -= 2000;
    }
}

void lisa_beauty(const int month, const int year)
{
    if (month == 2 or month == 5 or month == 8 or month == 11) {
        lisa.vtb.account -= 5000;
    }
    if (month == 4 or month == 10) {
        lisa.vtb.account -= 3000;
    }
    if (month == 12) {
        lisa.vtb.account -= 8000;
    }
}

void david_sport(const int month, const int year)
{
    if (month == 1) {
        david.vtb.account -= 5000;
    }
    if (month == 6) {
        david.vtb.account -= 3000;
    }
    if (month == 9) {
        david.vtb.account -= 4000;
    }
}

void lisa_sport(const int month, const int year)
{
    if (month == 3) {
        lisa.vtb.account -= 3000;
    }
    if (month == 7) {
        lisa.vtb.account -= 2000;
    }
    if (month == 11) {
        lisa.vtb.account -= 4000;
    }
}

void david_tech_upgrade(const int month, const int year)
{
    if (month == 9 and year == 2026) {
        david.vtb.account -= 50000;
    }
    if (month == 9 and year == 2027) {
        david.vtb.account -= 60000;
    }
    if (month == 9 and year == 2028) {
        david.vtb.account -= 70000;
    }
}

void lisa_tech_upgrade(const int month, const int year)
{
    if (month == 11 and year == 2026) {
        lisa.vtb.account -= 30000;
    }
    if (month == 11 and year == 2027) {
        lisa.vtb.account -= 35000;
    }
    if (month == 11 and year == 2028) {
        lisa.vtb.account -= 40000;
    }
}

void david_holiday_bonus(const int month, const int year)
{
    if (month == 5 and year == 2027) {
        david.vtb.account += 20000;
    }
    if (month == 5 and year == 2028) {
        david.vtb.account += 25000;
    }
}

void lisa_holiday_bonus(const int month, const int year)
{
    if (month == 5 and year == 2027) {
        lisa.vtb.account += 10000;
    }
    if (month == 5 and year == 2028) {
        lisa.vtb.account += 12000;
    }
}

void david_sporting_goods(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        david.vtb.account -= 8000;
    }
    if (month == 8 and year == 2028) {
        david.vtb.account -= 10000;
    }
}

void lisa_sporting_goods(const int month, const int year)
{
    if (month == 4 and year == 2027) {
        lisa.vtb.account -= 5000;
    }
    if (month == 9 and year == 2028) {
        lisa.vtb.account -= 6000;
    }
}

void david_tire_change(const int month, const int year)
{
    if (month == 10) {
        david.vtb.account -= 3000;
    }
    if (month == 4) {
        david.vtb.account -= 3000;
    }
}

void lisa_tire_change(const int month, const int year)
{
    if (month == 10) {
        lisa.vtb.account -= 2000;
    }
    if (month == 4) {
        lisa.vtb.account -= 2000;
    }
}

void david_consulting_session(const int month, const int year)
{
    if (month == 2 and year == 2027) {
        david.vtb.account += 15000;
    }
    if (month == 8 and year == 2028) {
        david.vtb.account += 20000;
    }
}

void lisa_photo_session(const int month, const int year)
{
    if (month == 6 and year == 2027) {
        lisa.vtb.account += 8000;
    }
    if (month == 10 and year == 2028) {
        lisa.vtb.account += 10000;
    }
}

void david_yearly_goal(const int month, const int year)
{
    if (month == 12) {
        RUB total_income = david.salary * 12;
        RUB total_investments = david.invest.stocks + david.invest.bonds + david.invest.etf;
        RUB total_savings = david.vtb.deposite;
        printf("Дэвид: годовой доход %lld руб, инвестиции %lld руб, накопления %lld руб\n",
            total_income, total_investments, total_savings);
    }
}

void lisa_yearly_goal(const int month, const int year)
{
    if (month == 12) {
        RUB total_income = lisa.salary * 12;
        RUB total_debt = lisa.home.mortgage_debt;
        printf("Лиза: годовой доход %lld руб, долг по ипотеке %lld руб, осталось %lld мес\n",
            total_income, total_debt, total_debt / lisa.home.mortgage_payment);
    }
}

void print_david(const int month, const int year)
{
    printf("\n===== ДЭВИД | %d/%d =====\n", month, year);
    printf("Зарплата: %lld руб\n", david.salary);
    printf("Текущий счет: %lld руб\n", david.vtb.account);
    printf("Депозит: %lld руб\n", david.vtb.deposite);
    printf("Доллары: %lld USD (курс %.2f)\n", david.vtb.account_usd, david.vtb.rate_usd_rub);
    printf("Евро: %lld EUR (курс %.2f)\n", david.vtb.account_eur, david.vtb.rate_eur_rub);
    printf("Недвижимость: %lld руб\n", david.home.apartment_value);
    printf("Авто: %lld руб\n", david.car.value);
    printf("Акции: %lld руб\n", david.invest.stocks);
    printf("Золото: %lld руб\n", david.invest.gold);
    printf("Криптовалюта: %lld руб\n", david.invest.crypto);
}

void print_lisa(const int month, const int year)
{
    printf("\n===== ЛИЗА | %d/%d =====\n", month, year);
    printf("Зарплата: %lld руб\n", lisa.salary);
    printf("Текущий счет: %lld руб\n", lisa.vtb.account);
    printf("Депозит: %lld руб\n", lisa.vtb.deposite);
    printf("Доллары: %lld USD (курс %.2f)\n", lisa.vtb.account_usd, lisa.vtb.rate_usd_rub);
    printf("Ипотечный долг: %lld руб\n", lisa.home.mortgage_debt);
    printf("Авто: %lld руб\n", lisa.car.value);
    printf("Акции: %lld руб\n", lisa.invest.stocks);
    printf("Криптовалюта: %lld руб\n", lisa.invest.crypto);
}

void print_results(const int month, const int year)
{
    RUB david_rub = david.vtb.account + david.vtb.deposite;
    RUB david_usd_rub = david.vtb.account_usd * david.vtb.rate_usd_rub;
    RUB david_eur_rub = david.vtb.account_eur * david.vtb.rate_eur_rub;
    RUB david_gbp_rub = david.vtb.account_gbp * david.vtb.rate_gbp_rub;
    RUB david_cny_rub = david.vtb.account_cny * david.vtb.rate_cny_rub;
    RUB david_assets = david_rub + david_usd_rub + david_eur_rub + david_gbp_rub + david_cny_rub;
    david_assets += david.home.apartment_value + david.home.house_value + david.home.cottage_value;
    david_assets += david.car.value + david.invest.stocks + david.invest.bonds + david.invest.etf;
    david_assets += david.invest.crypto + david.invest.gold + david.invest.silver;
    david_assets += david.invest.business + david.invest.startup;
    david_assets += david.home.furniture + david.home.appliances;

    RUB lisa_rub = lisa.vtb.account + lisa.vtb.deposite;
    RUB lisa_usd_rub = lisa.vtb.account_usd * lisa.vtb.rate_usd_rub;
    RUB lisa_eur_rub = lisa.vtb.account_eur * lisa.vtb.rate_eur_rub;
    RUB lisa_assets = lisa_rub + lisa_usd_rub + lisa_eur_rub;
    lisa_assets += lisa.car.value + lisa.invest.stocks + lisa.invest.gold + lisa.invest.crypto;
    lisa_assets += lisa.home.furniture + lisa.home.appliances;
    RUB lisa_debts = lisa.home.mortgage_debt;
    RUB lisa_capital = lisa_assets - lisa_debts;

    RUB david_capital = david_assets;

    printf("\n========================================\n");
    printf("ИТОГОВЫЙ ОТЧЕТ | %d/%d\n", month, year);
    printf("========================================\n");

    printf("\nДЭВИД (Накопитель):\n");
    printf("  Общие активы: %lld руб\n", david_assets);
    printf("  Капитал: %lld руб\n", david_capital);
    printf("  Депозит: %lld руб\n", david.vtb.deposite);
    printf("  Инвестиции: %lld руб\n", david.invest.stocks + david.invest.bonds + david.invest.etf);
    printf("  Недвижимость: %lld руб\n", david.home.apartment_value);
    printf("  Валютные накопления: %lld руб\n", david_usd_rub + david_eur_rub);

    printf("\nЛИЗА (Тратитель):\n");
    printf("  Общие активы: %lld руб\n", lisa_assets);
    printf("  Общие долги: %lld руб\n", lisa_debts);
    printf("  Капитал: %lld руб\n", lisa_capital);
    printf("  Ипотечный долг: %lld руб\n", lisa.home.mortgage_debt);
    printf("  Ежемесячный платеж по ипотеке: %lld руб\n", lisa.home.mortgage_payment);

    printf("\nРАЗНИЦА:\n");
    printf("  Разница в капитале: %lld руб\n", david_capital - lisa_capital);

    if (david_capital > lisa_capital) {
        printf("\nДэвид накопил больше - инвестиции и сбережения побеждают!\n");
    }
    else {
        printf("\nЛиза счастливее в тратах!\n");
    }
}

void simulation()
{
    int month = 1;
    int year = 2026;

    while (not (month == 12 and year == 2028)) {
        david_salary(month, year);
        lisa_salary(month, year);

        david_freelance(month, year);
        lisa_freelance(month, year);

        david_food(month, year);
        lisa_food(month, year);

        david_entertainment(month, year);
        lisa_entertainment(month, year);

        david_clothes(month, year);
        lisa_clothes(month, year);

        david_health(month, year);
        lisa_health(month, year);

        david_charity(month, year);
        lisa_charity(month, year);

        david_subscriptions(month, year);
        lisa_subscriptions(month, year);

        david_travel(month, year);
        lisa_travel(month, year);

        david_gifts(month, year);
        lisa_gifts(month, year);

        david_education(month, year);
        lisa_education(month, year);

        david_cat(month, year);
        lisa_cat(month, year);

        david_dog(month, year);
        lisa_dog(month, year);

        david_medicine(month, year);
        lisa_medicine(month, year);

        david_car(month, year);
        lisa_car(month, year);

        david_home(month, year);
        lisa_home(month, year);

        david_tax_return(month, year);
        lisa_tax_return(month, year);

        david_emergency(month, year);
        lisa_emergency(month, year);

        david_investments(month, year);
        lisa_investments(month, year);

        david_currency(month, year);
        lisa_currency(month, year);

        david_loan(month, year);
        lisa_loan(month, year);

        david_special_events(month, year);
        lisa_special_events(month, year);

        david_insurance(month, year);
        lisa_insurance(month, year);

        david_beauty(month, year);
        lisa_beauty(month, year);

        david_sport(month, year);
        lisa_sport(month, year);

        david_tech_upgrade(month, year);
        lisa_tech_upgrade(month, year);

        david_holiday_bonus(month, year);
        lisa_holiday_bonus(month, year);

        david_sporting_goods(month, year);
        lisa_sporting_goods(month, year);

        david_tire_change(month, year);
        lisa_tire_change(month, year);

        david_consulting_session(month, year);
        lisa_photo_session(month, year);

        david_yearly_goal(month, year);
        lisa_yearly_goal(month, year);

        david_deposite(month, year);
        lisa_deposite(month, year);

        if (month == 6 or month == 12) {
            print_david(month, year);
            print_lisa(month, year);
        }

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}

int main()
{
    srand(time(0));
    david_init();
    lisa_init();

    simulation();
    print_results(12, 2028);

    return 0;
}