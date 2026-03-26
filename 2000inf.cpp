#include <climits>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
typedef long long int RUB;

const RUB kBaseSalary = 70000;
const RUB kBaseSalaryKen = 62000;
const RUB kBaseSideIncome = 5000;
const RUB kBaseSideIncomeKen = 4200;
const RUB kTaxThreshold = 200000;
const int kTaxLowRate = 13;
const int kTaxHighRate = 20;
const RUB kEmergencyFundTarget = 300000;
const RUB kEmergencyFundTargetKen = 260000;
const double kDepositAprPp = 9.0;
const RUB kMonthlyCashToDeposit = 25000;
const int DIARY_VERBOSE_MAX_AGE = 28;
const RUB kCarPrice = 1200000;
const RUB kCarGasMonthly = 7000;
const RUB kCarServiceYearly = 15000;
const RUB kCarOsagoYearly = 9000;

struct car {
    RUB value;
    RUB gas;
    RUB oil;
    RUB wash;
    RUB fluid;
    RUB tires;
    RUB filter;
    RUB battery;
    RUB airfilter;
    RUB service;
    RUB parking;
    RUB kasko;
    RUB osago;
    RUB tax;
};

struct cat {
    RUB food;
    RUB toys;
    RUB medicine;
};

struct dog {
    RUB food;
    RUB toys;
    RUB medicine;
};

struct Bank {
    RUB account;
    RUB deposit;
};

struct hobby {
    RUB DDX_fitnes;
    RUB swimming_pool;
    RUB yoga;
    RUB language_courses;
    RUB painting;
    RUB pilates;
    RUB dancing;
    RUB tennis;
    RUB programming;
    RUB duolingo;
    RUB fishing;
};

struct weekend {
    RUB massage;
    RUB spa;
    RUB sauna;
    RUB bars;
    RUB night_clubs;
    RUB cinema;
    RUB theater;
    RUB jazz;
    RUB concerts;
    RUB museums;
    RUB art_galleries;
    RUB comedy_club;
    RUB cafe;
    RUB watter_park;
    RUB karaoke;
    RUB bowling;
    RUB billiards;
    RUB zoo;
};

struct shopping {
    RUB malls;
    RUB boutiques;
};

struct citytrip {
    RUB taxi;
    RUB scooter_rent;
    RUB bike_rent;
    RUB car_sharing;
    RUB public_transport;
};

struct domestic_travel {
    RUB train;
    RUB bus;
    RUB toll_roads;
    RUB car_sharing_long;
    RUB hotel;
    RUB fuel_intercity;
    RUB ferries;
};

struct international_trip {
    RUB flight;
    RUB international_passport;
    RUB visa;
    RUB currency_exchange;
    RUB luggage;
    RUB seat_selection;
    RUB travel_insurance;
    RUB hotel;
};

struct food {
    RUB milk;
    RUB kefir;
    RUB yogurt;
    RUB cheese;
    RUB cream;
    RUB nuts;
    RUB bread;
    RUB loaf;
    RUB rice;
    RUB meat;
    RUB fish;
    RUB buckwheat;
    RUB pasta;
    RUB oatmeal;
    RUB millet;
    RUB flour;
    RUB cereal;
    RUB sour_cream;
    RUB sugar;
    RUB salt;
    RUB spices;
    RUB mayonnaise;
    RUB ketchup;
};

struct food_fruits {
    RUB apples;
    RUB pears;
    RUB bananas;
    RUB oranges;
    RUB mandarins;
    RUB lemons;
    RUB grapes;
    RUB strawberries;
    RUB raspberries;
    RUB watermelon;
    RUB melon;
    RUB kiwi;
    RUB mango;
};

struct food_vegetables {
    RUB potatoes;
    RUB tomatoes;
    RUB cucumbers;
    RUB onions;
    RUB garlic;
    RUB carrots;
    RUB beets;
    RUB cabbage;
    RUB broccoli;
    RUB cauliflower;
    RUB peppers;
    RUB zucchini;
    RUB eggplants;
    RUB greens;
    RUB salad;
    RUB avocado;
};

struct junkfood {
    RUB chocolate;
    RUB candy;
    RUB cookies;
    RUB chips;
    RUB fast_food;
    RUB pizza;
    RUB ice_cream;
};

struct sportpit {
    RUB protein;
    RUB creatin;
    RUB geiner;
    RUB BCA;
};

struct Beverages {
    RUB water;
    RUB juice;
    RUB soda;
    RUB tea;
    RUB coffee;
    RUB cocoa;
};

struct Care {
    RUB cosmetics;
    RUB perfume;
    RUB haircut;
    RUB barber;
    RUB deodorant;
    RUB manicure;
    RUB razors;
    RUB creams;
    RUB shampoo;
    RUB soap;

};

struct health {
    RUB therapist;
    RUB dentist;
    RUB specialists;
    RUB tests;
    RUB diagnostics;
    RUB vitamins;
    RUB medicines;
};

struct education {
    RUB professional_courses;
    RUB language_courses;
    RUB it_courses;
    RUB online_courses;
    RUB books;
    RUB conferences;
    RUB workshops;
    RUB exams;
    RUB certificates;
    RUB educational_equipment;
    RUB software;
    RUB stationery;
};

struct home {
    RUB rent;
    RUB mortgage;
    RUB fire_alarm;
    RUB alarm_sistem;
    RUB cleaning;
    RUB electricity;
    RUB water;
    RUB heating;
    RUB gas;
    RUB garbage;
    RUB elevator;
    RUB intercom;
    RUB internet;
    RUB tv;
    RUB streaming;
};

struct cloth {
    RUB jeans;
    RUB trousers;
    RUB shorts;
    RUB shirts;
    RUB t_shirts;
    RUB sweaters;
    RUB hoodies;
    RUB sneakers;
    RUB gym_clothes;
    RUB yoga_clothes;
    RUB running_clothes;
    RUB bags;
    RUB socks;
    RUB slippers;
    RUB shoe_repair;
    RUB backpacks;
    RUB jewelry;
    RUB dry_cleaning;
    RUB watches;
};

struct electronics {
    RUB smartphone;
    RUB laptop;
    RUB tablet;
    RUB headphones;
    RUB smart_watch;
    RUB tv;
    RUB camera;
    RUB gaming_console;
    RUB computer_accessories;
    RUB software_subscriptions;
    RUB cloud_storage;
    RUB antivirus;
};

struct beauty {
    RUB haircut;
    RUB manicure;
    RUB pedicure;
    RUB cosmetics;
    RUB skincare;
    RUB perfume;
    RUB spa_treatments;
    RUB massage;
    RUB hair_products;
    RUB makeup;
};

struct sports {
    RUB gym_membership;
    RUB fitness_classes;
    RUB sports_equipment;
    RUB sportswear;
    RUB competitions;
    RUB coach;
    RUB supplements;
    RUB vitamins_sports;
    RUB recovery;
    RUB massage_sports;
};

struct charity {
    RUB donations;
    RUB volunteering_costs;
    RUB gifts;
    RUB holiday_gifts;
    RUB birthday_gifts;
    RUB wedding_gifts;
    RUB new_year_gifts;
};

struct travel {
    RUB domestic_flights;
    RUB international_flights;
    RUB hotels;
    RUB hostels;
    RUB airbnb;
    RUB rental_cars;
    RUB excursions;
    RUB travel_insurance;
    RUB visa_fees;
    RUB luggage;
    RUB airport_transfer;
    RUB travel_gear;
};

struct utilities {
    RUB electricity_extra;
    RUB water_extra;
    RUB heating_extra;
    RUB gas_extra;
    RUB internet_extra;
    RUB mobile_phone;
    RUB home_phone;
    RUB cable_tv;
    RUB streaming_services;
    RUB music_subscriptions;
    RUB cloud_services;
    RUB vpn;
};

struct pets {
    RUB dog_food;
    RUB cat_food;
    RUB vet_visits;
    RUB vaccinations;
    RUB pet_insurance;
    RUB grooming;
    RUB pet_toys;
    RUB pet_bedding;
    RUB pet_training;
    RUB pet_sitting;
};

struct insurance {
    RUB health_insurance;
    RUB life_insurance;
    RUB property_insurance;
    RUB car_insurance;
    RUB travel_insurance_annual;
    RUB liability_insurance;
    RUB pet_insurance_annual;
};

struct person {
    int age;
    char person_name[32];
    int health_points;
    int happiness_points;
    int energy_points;
    int discipline_points;
    int stress_points;

    RUB salary;
    int job_level;
    bool employed;
    int unemployment_months;
    RUB side_income;
    RUB monthly_expenses;
    RUB emergency_fund;
    RUB yearly_savings_goal;

    bool has_car;
    bool has_cat;
    bool has_dog;
    bool is_married;
    bool has_children;

    car my_car;
    cat my_cat;
    dog my_dog;
    Bank bank;
    hobby hobbies;
    weekend weekends;
    shopping shopping_activity;
    citytrip city_trip;
    domestic_travel domestic_trip;
    international_trip abroad_trip;
    food basic_food;
    food_fruits fruits;
    food_vegetables vegetables;
    junkfood fast_food;
    sportpit sport_nutrition;
    Beverages drinks;
    health medical;
    education learning;
    home housing;
    cloth wardrobe;

    electronics electronics_expenses;
    beauty beauty_expenses;
    sports sports_expenses;
    charity charity_expenses;
    travel travel_expenses;
    utilities utilities_expenses;
    pets pets_expenses;
    insurance insurance_expenses;

    int iq_level;
    int education_level;
    int career_satisfaction;
    int relationship_quality;
    int sleep_quality;
    int nutrition_quality;

    RUB mortgage_debt;
    RUB car_loan;
    RUB student_loan;
    RUB credit_card_debt;

    bool has_house;
    bool has_apartment;
    bool has_business;
    bool has_investments;
    bool has_stocks;
    bool has_bonds;
    bool has_crypto;

    int investment_risk_tolerance;
    int financial_literacy;
    int networking_skills;
    int leadership_skills;
    int technical_skills;
    int soft_skills;

    RUB monthly_investment;
    RUB monthly_savings_rate;
    RUB retirement_fund;
    RUB pension_contributions;

    int friends_count;
    int social_connections;
    int volunteer_hours;
    int hobby_diversity;

    RUB coffee_shops;
    RUB restaurants;
    RUB delivery_food;
    RUB meal_prep;
};

struct life_year_report {
    int age;
    RUB income;
    RUB expenses;
    RUB invested;
    RUB emergency_fund;
    RUB net_worth;
};

static int random_int(int l, int r) {
    if (l > r) swap(l, r);
    return l + rand() % (r - l + 1);
}

static RUB clamp_rub(RUB v, RUB lo, RUB hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static RUB min_rub(RUB a, RUB b) {
    return (a < b) ? a : b;
}

static double inflation_multiplier_rate(int year_index, double annual_rate_pp) {
    double r = annual_rate_pp / 100.0;
    double base = pow(1.0 + r, year_index);
    double wobble = (year_index % 4 == 0 ? 0.02 : -0.01);
    return base * (1.0 + wobble);
}

static RUB monthly_income_tax(RUB gross_monthly_income) {
    if (gross_monthly_income <= kTaxThreshold) {
        return gross_monthly_income * kTaxLowRate / 100;
    }
    RUB low = kTaxThreshold * kTaxLowRate / 100;
    RUB high = (gross_monthly_income - kTaxThreshold) * kTaxHighRate / 100;
    return low + high;
}

static void init_advanced_fields(person& p) {
    memset(&p.electronics_expenses, 0, sizeof(p.electronics_expenses));
    memset(&p.beauty_expenses, 0, sizeof(p.beauty_expenses));
    memset(&p.sports_expenses, 0, sizeof(p.sports_expenses));
    memset(&p.charity_expenses, 0, sizeof(p.charity_expenses));
    memset(&p.travel_expenses, 0, sizeof(p.travel_expenses));
    memset(&p.utilities_expenses, 0, sizeof(p.utilities_expenses));
    memset(&p.pets_expenses, 0, sizeof(p.pets_expenses));
    memset(&p.insurance_expenses, 0, sizeof(p.insurance_expenses));

    p.iq_level = random_int(85, 145);
    p.education_level = random_int(1, 5);
    p.career_satisfaction = random_int(40, 90);
    p.relationship_quality = random_int(30, 95);
    p.sleep_quality = random_int(40, 95);
    p.nutrition_quality = random_int(45, 90);

    p.mortgage_debt = 0;
    p.car_loan = 0;
    p.student_loan = 0;
    p.credit_card_debt = 0;

    p.has_house = false;
    p.has_apartment = false;
    p.has_business = false;
    p.has_investments = false;
    p.has_stocks = false;
    p.has_bonds = false;
    p.has_crypto = false;

    p.investment_risk_tolerance = random_int(1, 10);
    p.financial_literacy = random_int(30, 95);
    p.networking_skills = random_int(20, 90);
    p.leadership_skills = random_int(25, 85);
    p.technical_skills = random_int(30, 95);
    p.soft_skills = random_int(35, 90);

    p.monthly_investment = 5000;
    p.monthly_savings_rate = 10;
    p.retirement_fund = 0;
    p.pension_contributions = 5000;

    p.friends_count = random_int(3, 25);
    p.social_connections = random_int(10, 50);
    p.volunteer_hours = random_int(0, 10);
    p.hobby_diversity = random_int(1, 8);

    p.coffee_shops = 2000;
    p.restaurants = 5000;
    p.delivery_food = 3000;
    p.meal_prep = 8000;
}

static void init_person(person& p, const char* who) {
    // Ensure all fields are initialized (prevents accidental UB from later reads).
    memset(&p, 0, sizeof(p));
    p.age = 25;
    std::strncpy(p.person_name, who, sizeof(p.person_name) - 1);
    p.person_name[sizeof(p.person_name) - 1] = '\0';
    p.health_points = 85;
    p.happiness_points = 75;
    p.energy_points = 80;
    p.discipline_points = 65;
    p.stress_points = 25;

    p.salary = kBaseSalary;
    p.job_level = 2;
    p.employed = true;
    p.unemployment_months = 0;
    p.side_income = kBaseSideIncome;
    p.monthly_expenses = 55000;
    p.emergency_fund = 150000;
    p.yearly_savings_goal = kEmergencyFundTarget;

    if (who && who[0] == 'K') {
        p.salary = kBaseSalaryKen;
        p.job_level = 3;
        p.side_income = kBaseSideIncomeKen;
        p.monthly_expenses = 57000;
        p.emergency_fund = 140000;
        p.yearly_savings_goal = kEmergencyFundTargetKen;
        p.happiness_points = 71;
        p.stress_points = 29;
        p.discipline_points = 63;
    }

    p.has_car = true;
    p.has_cat = false;
    p.has_dog = false;
    p.is_married = false;
    p.has_children = false;

    p.bank.account = 200000;
    p.bank.deposit = 50000;

    memset(&p.my_car, 0, sizeof(p.my_car));
    p.my_car.value = kCarPrice;
    p.my_car.gas = kCarGasMonthly;
    p.my_car.service = kCarServiceYearly;
    p.my_car.osago = kCarOsagoYearly;
    p.my_car.oil = 6000;
    p.my_car.wash = 3000;
    p.my_car.fluid = 2000;
    p.my_car.tires = 20000;
    p.my_car.filter = 3000;
    p.my_car.battery = 5000;
    p.my_car.airfilter = 1500;
    p.my_car.parking = 12000;
    p.my_car.kasko = 30000;
    p.my_car.tax = 5000;

    memset(&p.my_dog, 0, sizeof(p.my_dog));
    memset(&p.hobbies, 0, sizeof(p.hobbies));
    memset(&p.shopping_activity, 0, sizeof(p.shopping_activity));
    memset(&p.city_trip, 0, sizeof(p.city_trip));
    memset(&p.domestic_trip, 0, sizeof(p.domestic_trip));
    memset(&p.abroad_trip, 0, sizeof(p.abroad_trip));
    memset(&p.sport_nutrition, 0, sizeof(p.sport_nutrition));

    p.housing.rent = 35000;
    p.housing.mortgage = 0;
    p.housing.internet = 1000;
    p.housing.electricity = 2500;
    p.housing.water = 1200;
    p.housing.heating = 2200;
    p.housing.gas = 900;
    p.housing.garbage = 500;
    p.housing.intercom = 300;
    p.housing.tv = 600;
    p.housing.streaming = 1200;
    p.housing.cleaning = 2500;
    p.housing.fire_alarm = 300;
    p.housing.alarm_sistem = 700;
    p.housing.elevator = 400;

    p.basic_food.meat = 5000;
    p.basic_food.fish = 3200;
    p.basic_food.rice = 900;
    p.basic_food.pasta = 1000;
    p.basic_food.bread = 900;
    p.basic_food.milk = 1200;
    p.basic_food.cheese = 1400;
    p.basic_food.kefir = 0;
    p.basic_food.yogurt = 0;
    p.basic_food.cream = 0;
    p.basic_food.nuts = 0;
    p.basic_food.loaf = 0;
    p.basic_food.buckwheat = 0;
    p.basic_food.oatmeal = 0;
    p.basic_food.millet = 0;
    p.basic_food.flour = 0;
    p.basic_food.cereal = 0;
    p.basic_food.sour_cream = 0;
    p.basic_food.sugar = 0;
    p.basic_food.salt = 0;
    p.basic_food.spices = 0;
    p.basic_food.mayonnaise = 0;
    p.basic_food.ketchup = 0;

    p.fruits.apples = 700;
    p.fruits.bananas = 600;
    p.fruits.oranges = 500;
    p.fruits.mandarins = 450;
    p.fruits.pears = 0;
    p.fruits.lemons = 0;
    p.fruits.grapes = 0;
    p.fruits.strawberries = 0;
    p.fruits.raspberries = 0;
    p.fruits.watermelon = 0;
    p.fruits.melon = 0;
    p.fruits.kiwi = 0;
    p.fruits.mango = 0;

    p.vegetables.potatoes = 800;
    p.vegetables.tomatoes = 900;
    p.vegetables.cucumbers = 700;
    p.vegetables.onions = 300;
    p.vegetables.garlic = 250;
    p.vegetables.carrots = 300;
    p.vegetables.cabbage = 400;
    p.vegetables.greens = 450;
    p.vegetables.beets = 0;
    p.vegetables.broccoli = 0;
    p.vegetables.cauliflower = 0;
    p.vegetables.peppers = 0;
    p.vegetables.zucchini = 0;
    p.vegetables.eggplants = 0;
    p.vegetables.salad = 0;
    p.vegetables.avocado = 0;

    p.drinks.water = 900;
    p.drinks.tea = 700;
    p.drinks.coffee = 1200;
    p.drinks.juice = 500;
    p.drinks.soda = 300;
    p.drinks.cocoa = 200;

    p.fast_food.pizza = 1200;
    p.fast_food.fast_food = 1800;
    p.fast_food.ice_cream = 500;
    p.fast_food.cookies = 600;
    p.fast_food.chips = 350;
    p.fast_food.chocolate = 450;
    p.fast_food.candy = 300;

    p.medical.therapist = 1200;
    p.medical.dentist = 1500;
    p.medical.tests = 1800;
    p.medical.vitamins = 1000;
    p.medical.medicines = 800;
    p.medical.specialists = 900;
    p.medical.diagnostics = 1100;

    p.learning.online_courses = 1500;
    p.learning.books = 1200;
    p.learning.it_courses = 2500;
    p.learning.language_courses = 2000;
    p.learning.professional_courses = 1800;
    p.learning.conferences = 800;
    p.learning.workshops = 700;
    p.learning.exams = 500;
    p.learning.certificates = 600;
    p.learning.educational_equipment = 1200;
    p.learning.software = 900;
    p.learning.stationery = 300;

    memset(&p.weekends, 0, sizeof(p.weekends));
    p.weekends.cinema = 800;
    p.weekends.cafe = 1500;
    p.weekends.museums = 500;

    init_advanced_fields(p);
}

static RUB estimate_monthly_income(const person& p, int month_index) {
    // "Bonus months" every 3rd month; keep it deterministic by month-of-year.
    RUB bonus = (month_index % 3 == 0) ? random_int(0, 12000) : 0;
    return p.salary + p.side_income + bonus;
}

static RUB estimate_monthly_income_after_tax(const person& p, int year_index, double employment_factor, int month_index) {
    RUB gross = estimate_monthly_income(p, month_index);

    if (p.age >= 60) {
        gross = gross / 2;
        RUB pension = (RUB)(28000 * (1.0 + 0.02 * (year_index > 0 ? year_index / 10 : 0)));
        gross += pension;
    }

    RUB tax = monthly_income_tax(gross);
    RUB net = gross - tax;
    if (employment_factor < 1.0) {
        net = (RUB)(net * employment_factor);
    }
    return net;
}

static RUB estimate_monthly_income_after_tax(const person& p, int year_index) {
    // Fallback overload (assumes month_index=0). Main simulation passes real month.
    return estimate_monthly_income_after_tax(p, year_index, 1.0, 0);
}

static RUB estimate_monthly_expenses(const person& p, int year_index) {
    RUB home_cost =
        p.housing.rent + p.housing.mortgage + p.housing.internet + p.housing.electricity +
        p.housing.water + p.housing.heating + p.housing.gas + p.housing.garbage +
        p.housing.intercom + p.housing.tv + p.housing.streaming + p.housing.cleaning +
        p.housing.fire_alarm + p.housing.alarm_sistem + p.housing.elevator;

    RUB food_cost =
        p.basic_food.meat + p.basic_food.fish + p.basic_food.rice + p.basic_food.pasta +
        p.basic_food.bread + p.basic_food.milk + p.basic_food.cheese +
        p.fruits.apples + p.fruits.bananas + p.fruits.oranges + p.fruits.mandarins +
        p.vegetables.potatoes + p.vegetables.tomatoes + p.vegetables.cucumbers +
        p.vegetables.onions + p.vegetables.garlic + p.vegetables.carrots +
        p.vegetables.cabbage + p.vegetables.greens;

    RUB health_and_growth =
        p.medical.therapist + p.medical.dentist + p.medical.tests + p.medical.vitamins +
        p.medical.medicines + p.medical.specialists + p.medical.diagnostics +
        p.learning.online_courses + p.learning.books + p.learning.it_courses +
        p.learning.language_courses + p.learning.professional_courses;

    RUB leisure =
        p.fast_food.pizza + p.fast_food.fast_food + p.fast_food.ice_cream +
        p.fast_food.cookies + p.fast_food.chips + p.fast_food.chocolate + p.fast_food.candy +
        p.weekends.cinema + p.weekends.cafe + p.weekends.museums;

    RUB transport_and_pets = 0;
    if (p.has_car) {
        transport_and_pets += p.my_car.gas;
        transport_and_pets += p.my_car.wash / 12;
        transport_and_pets += p.my_car.oil / 12;
        transport_and_pets += p.my_car.service / 12;
        transport_and_pets += p.my_car.parking / 12;
        transport_and_pets += p.my_car.kasko / 12;
        transport_and_pets += p.my_car.osago / 12;
        transport_and_pets += p.my_car.tax / 12;
        transport_and_pets += p.my_car.tires / 12;
    }
    if (p.has_cat) {
        transport_and_pets += p.my_cat.food + p.my_cat.toys + p.my_cat.medicine;
    }
    if (p.has_dog) {
        transport_and_pets += p.my_dog.food + p.my_dog.toys + p.my_dog.medicine;
    }

    if (p.age > 55) {
        double k = 1.0 + (p.age - 55) * 0.01;
        health_and_growth = (RUB)(health_and_growth * k);
    }

    RUB random_spike = random_int(0, 12000);

    double m_home = inflation_multiplier_rate(year_index, 3.0);
    double m_food = inflation_multiplier_rate(year_index, 4.0);
    double m_health = inflation_multiplier_rate(year_index, 5.0);
    double m_leisure = inflation_multiplier_rate(year_index, 4.5);
    double m_misc = inflation_multiplier_rate(year_index, 3.8);

    double stress_rel = 1.0 + ((p.stress_points - 50) / 200.0);
    if (stress_rel < 0.75) stress_rel = 0.75;
    if (stress_rel > 1.25) stress_rel = 1.25;

    RUB base =
        (RUB)(home_cost * m_home) +
        (RUB)(food_cost * m_food) +
        (RUB)(health_and_growth * m_health) +
        (RUB)((leisure + transport_and_pets) * m_leisure * stress_rel) +
        (RUB)((p.monthly_expenses / 10) * m_misc) +
        (RUB)(random_spike * m_misc);

    return base;
}

static void apply_advanced_life_events(person& p, int year_index) {
    if (p.age == 35 && !p.has_house) {
        p.has_house = true;
        p.housing.mortgage = 50000;
        p.housing.rent = 0;
        p.monthly_expenses += 20000;
        p.happiness_points += 20;
        p.stress_points += 10;
        cout << p.person_name << " bought a house at age " << p.age << "\n";
    }

    if (p.age == 40 && !p.has_children) {
        if (random_int(0, 2) == 0) {
            p.has_children = true;
            p.monthly_expenses += 35000;
            p.happiness_points += 25;
            p.stress_points += 15;
            p.energy_points -= 10;
            cout << p.person_name << " had a child at age " << p.age << "\n";
        }
    }

    if (p.age == 45 && p.has_house) {
        p.housing.mortgage = (RUB)(p.housing.mortgage * 0.7);
        p.happiness_points += 10;
        p.stress_points -= 5;
        cout << p.person_name << " paid off 30% of mortgage at age " << p.age << "\n";
    }

    if (p.age == 50) {
        p.salary += (RUB)(p.salary * 0.15);
        p.happiness_points += 8;
        p.retirement_fund += p.bank.deposit * 0.3;
        cout << p.person_name << " received career promotion at age " << p.age << "\n";
    }

    if (p.age == 55 && p.has_house) {
        p.housing.mortgage = 0;
        p.happiness_points += 15;
        p.stress_points -= 15;
        cout << p.person_name << " fully paid off mortgage at age " << p.age << "\n";
    }

    if (p.age == 60 && !p.has_children) {
        p.travel_expenses.international_flights = 100000;
        p.happiness_points += 12;
        cout << p.person_name << " started traveling internationally at age " << p.age << "\n";
    }

    if (p.age >= 65 && p.age % 5 == 0) {
        RUB inheritance = random_int(500000, 2000000);
        p.bank.account += inheritance;
        p.happiness_points += 5;
        cout << p.person_name << " received inheritance: " << inheritance << " RUB at age " << p.age << "\n";
    }

    if (p.age == 30 && random_int(0, 3) == 0) {
        p.has_dog = true;
        p.my_dog.food = 4000;
        p.my_dog.toys = 1000;
        p.my_dog.medicine = 1500;
        p.happiness_points += 12;
        p.monthly_expenses += 5000;
        cout << p.person_name << " got a dog at age " << p.age << "\n";
    }

    if (p.age == 28 && random_int(0, 2) == 0 && !p.has_cat) {
        p.has_cat = true;
        p.my_cat.food = 2500;
        p.my_cat.toys = 600;
        p.my_cat.medicine = 800;
        p.happiness_points += 8;
        p.monthly_expenses += 3000;
        cout << p.person_name << " got a cat at age " << p.age << "\n";
    }
}

static void apply_life_events(person& p, int year_index) {
    p.salary = (RUB)(p.salary * 1.045);
    p.side_income = (RUB)(p.side_income * 1.03);

    if (p.age == 27 && !p.has_cat) {
        p.has_cat = true;
        p.my_cat.food = 3000;
        p.my_cat.toys = 800;
        p.my_cat.medicine = 700;
        p.happiness_points += 5;
    }
    if (p.age == 30 && !p.is_married) {
        p.is_married = true;
        p.happiness_points += 15;
        p.monthly_expenses += 15000;
        p.relationship_quality = random_int(60, 95);
    }
    if (p.age == 33 && !p.has_children) {
        p.has_children = true;
        p.monthly_expenses += 30000;
        p.stress_points += 12;
        p.energy_points -= 8;
    }
    if (p.age == 45) {
        p.salary += 50000;
        p.side_income += 10000;
        p.happiness_points += 8;
    }
    if (p.age == 55) {
        p.salary += 30000;
        p.happiness_points += 5;
    }
    if (p.age == 65 && p.employed) {
        p.employed = false;
        p.happiness_points += 10;
        p.stress_points -= 15;
    }

    if (p.employed && p.age >= 22 && p.age <= 60 && year_index % 4 == 0) {
        if (random_int(0, 4) == 0) {
            p.job_level += 1;
            p.salary += (RUB)(18000 * p.job_level);
            p.side_income += (RUB)(5000 + 1500 * p.job_level);
            p.happiness_points += 3;
            p.stress_points += 1;
            p.career_satisfaction = min(100, p.career_satisfaction + random_int(5, 15));
        }
    }

    if (year_index % 5 == 0 && p.age < 65) {
        p.salary += random_int(4000, 12000);
        p.side_income += random_int(500, 3500);
    }

    apply_advanced_life_events(p, year_index);
}

static RUB calculate_pension_forecast(const person& p, int years_to_retirement) {
    RUB current_savings = p.bank.deposit + p.emergency_fund;
    RUB monthly_contribution = p.monthly_investment;
    double annual_return = kDepositAprPp / 100.0;

    RUB future_value = current_savings;
    for (int i = 0; i < years_to_retirement; ++i) {
        future_value = (RUB)(future_value * (1 + annual_return));
        future_value += monthly_contribution * 12;
    }
    return future_value;
}

static void print_detailed_health_report(const person& p) {
    cout << "\n=== Health Report for " << p.person_name << " ===\n";
    cout << "Physical Health: " << p.health_points << "/100\n";
    cout << "Mental Health: " << (100 - p.stress_points) << "/100\n";
    cout << "Energy Level: " << p.energy_points << "/100\n";
    cout << "Happiness Index: " << p.happiness_points << "/100\n";
    cout << "Discipline Score: " << p.discipline_points << "/100\n";
    cout << "Sleep Quality: " << p.sleep_quality << "/100\n";
    cout << "Nutrition Quality: " << p.nutrition_quality << "/100\n";
}

static void print_financial_analysis(const person& p) {
    RUB total_assets = p.bank.account + p.bank.deposit + p.emergency_fund;
    RUB monthly_net = (p.salary + p.side_income) - p.monthly_expenses;
    RUB total_debt = p.mortgage_debt + p.car_loan + p.student_loan + p.credit_card_debt;

    cout << "\n=== Financial Analysis for " << p.person_name << " ===\n";
    cout << "Total Assets: " << total_assets << " RUB\n";
    cout << "Total Debt: " << total_debt << " RUB\n";
    cout << "Net Worth: " << (total_assets - total_debt) << " RUB\n";
    cout << "Monthly Net Income: " << monthly_net << " RUB\n";
    cout << "Emergency Fund Coverage: " << (p.emergency_fund / max((RUB)1, p.monthly_expenses)) << " months\n";
    cout << "Savings Rate: " << (monthly_net * 100 / max((RUB)1, (p.salary + p.side_income))) << "%\n";
    cout << "Financial Literacy: " << p.financial_literacy << "/100\n";
    cout << "Investment Risk Tolerance: " << p.investment_risk_tolerance << "/10\n";
}

static void print_career_progress(const person& p) {
    cout << "\n=== Career Progress for " << p.person_name << " ===\n";
    cout << "Job Level: " << p.job_level << "\n";
    cout << "Current Salary: " << p.salary << " RUB\n";
    cout << "Side Income: " << p.side_income << " RUB\n";
    cout << "Employed: " << (p.employed ? "Yes" : "No") << "\n";
    cout << "Career Satisfaction: " << p.career_satisfaction << "/100\n";
    cout << "Leadership Skills: " << p.leadership_skills << "/100\n";
    cout << "Technical Skills: " << p.technical_skills << "/100\n";
    cout << "Soft Skills: " << p.soft_skills << "/100\n";
    cout << "Networking Skills: " << p.networking_skills << "/100\n";
    if (!p.employed) {
        cout << "Unemployment Duration: " << p.unemployment_months << " months\n";
    }
}

static void print_life_balance(const person& p) {
    cout << "\n=== Life Balance for " << p.person_name << " ===\n";
    int work_life_balance = (p.happiness_points + p.energy_points - p.stress_points) / 2;
    cout << "Work-Life Balance Score: " << work_life_balance << "/100\n";
    cout << "Married: " << (p.is_married ? "Yes" : "No") << "\n";
    cout << "Relationship Quality: " << p.relationship_quality << "/100\n";
    cout << "Children: " << (p.has_children ? "Yes" : "No") << "\n";
    cout << "Has Car: " << (p.has_car ? "Yes" : "No") << "\n";
    cout << "Has House: " << (p.has_house ? "Yes" : "No") << "\n";
    cout << "Has Pets: " << ((p.has_cat || p.has_dog) ? "Yes" : "No") << "\n";
    cout << "Friends Count: " << p.friends_count << "\n";
    cout << "Social Connections: " << p.social_connections << "\n";
    cout << "Hobby Diversity: " << p.hobby_diversity << "/8\n";
    cout << "Volunteer Hours/Week: " << p.volunteer_hours << "\n";
}

static void print_retirement_readiness(const person& p) {
    int years_to_retirement = max(0, 65 - p.age);
    RUB pension_forecast = calculate_pension_forecast(p, years_to_retirement);
    RUB annual_expenses = p.monthly_expenses * 12;
    RUB years_of_retirement = (annual_expenses > 0) ? (pension_forecast / annual_expenses) : 0;

    cout << "\n=== Retirement Readiness for " << p.person_name << " ===\n";
    cout << "Years until retirement: " << years_to_retirement << "\n";
    cout << "Projected retirement fund: " << pension_forecast << " RUB\n";
    cout << "Estimated retirement years coverage: " << years_of_retirement << " years\n";
    cout << "Retirement Fund: " << p.retirement_fund << " RUB\n";
    cout << "Pension Contributions: " << p.pension_contributions << " RUB/month\n";
    if (years_of_retirement >= 20) {
        cout << "Status: ON TRACK\n";
    } else if (years_of_retirement >= 10) {
        cout << "Status: MODERATE - Consider increasing savings\n";
    } else {
        cout << "Status: NEEDS IMPROVEMENT - Increase retirement contributions\n";
    }
}

static void compare_persons(const person& p1, const person& p2) {
    cout << "\n=== COMPARISON REPORT ===\n";

    RUB wealth1 = p1.bank.account + p1.bank.deposit + p1.emergency_fund;
    RUB wealth2 = p2.bank.account + p2.bank.deposit + p2.emergency_fund;

    cout << "Wealth: " << p1.person_name << "=" << wealth1
         << ", " << p2.person_name << "=" << wealth2 << "\n";
    cout << "Health: " << p1.person_name << "=" << p1.health_points
         << ", " << p2.person_name << "=" << p2.health_points << "\n";
    cout << "Happiness: " << p1.person_name << "=" << p1.happiness_points
         << ", " << p2.person_name << "=" << p2.happiness_points << "\n";
    cout << "Stress: " << p1.person_name << "=" << p1.stress_points
         << ", " << p2.person_name << "=" << p2.stress_points << "\n";
    cout << "Career Level: " << p1.person_name << "=" << p1.job_level
         << ", " << p2.person_name << "=" << p2.job_level << "\n";
    cout << "Financial Literacy: " << p1.person_name << "=" << p1.financial_literacy
         << ", " << p2.person_name << "=" << p2.financial_literacy << "\n";

    cout << "\nWinner: ";
    if (wealth1 > wealth2) cout << p1.person_name;
    else if (wealth2 > wealth1) cout << p2.person_name;
    else cout << "Tie";
    cout << " by wealth!\n";
}

static void save_report_to_file(const person& p, const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file: " << filename << "\n";
        return;
    }

    RUB total_assets = p.bank.account + p.bank.deposit + p.emergency_fund;
    RUB total_debt = p.mortgage_debt + p.car_loan + p.student_loan + p.credit_card_debt;

    file << "=== LIFE SIMULATION REPORT ===\n";
    file << "Name: " << p.person_name << "\n";
    file << "Age: " << p.age << "\n";
    file << "Final Net Worth: " << (total_assets - total_debt) << "\n";
    file << "Health: " << p.health_points << "\n";
    file << "Happiness: " << p.happiness_points << "\n";
    file << "Stress: " << p.stress_points << "\n";
    file << "=== FINANCIAL DETAILS ===\n";
    file << "Account: " << p.bank.account << "\n";
    file << "Deposit: " << p.bank.deposit << "\n";
    file << "Emergency Fund: " << p.emergency_fund << "\n";
    file << "Total Assets: " << total_assets << "\n";
    file << "Total Debt: " << total_debt << "\n";
    file << "=== FAMILY STATUS ===\n";
    file << "Married: " << (p.is_married ? "Yes" : "No") << "\n";
    file << "Children: " << (p.has_children ? "Yes" : "No") << "\n";
    file << "Has House: " << (p.has_house ? "Yes" : "No") << "\n";
    file << "Has Car: " << (p.has_car ? "Yes" : "No") << "\n";
    file << "=== CAREER ===\n";
    file << "Job Level: " << p.job_level << "\n";
    file << "Salary: " << p.salary << "\n";
    file << "Employed: " << (p.employed ? "Yes" : "No") << "\n";
    file << "Career Satisfaction: " << p.career_satisfaction << "\n";
    file.close();
    cout << "Report saved to " << filename << "\n";
}

static void print_annual_summary(const life_year_report& r, const person& p, int year) {
    RUB savings = r.income - r.expenses;
    cout << "\n┌─────────────────────────────────────────┐\n";
    cout << "│     YEAR " << year << " SUMMARY (" << p.person_name << ")         │\n";
    cout << "├─────────────────────────────────────────┤\n";
    cout << "│ Age: " << r.age << "                                     │\n";
    cout << "│ Income: " << r.income << " RUB                   │\n";
    cout << "│ Expenses: " << r.expenses << " RUB                  │\n";
    cout << "│ Savings: " << savings << " RUB                 │\n";
    cout << "│ Net Worth: " << r.net_worth << " RUB                │\n";
    cout << "├─────────────────────────────────────────┤\n";
    cout << "│ Health: " << p.health_points << "  │ Happiness: " << p.happiness_points << "  │\n";
    cout << "│ Energy: " << p.energy_points << "   │ Stress: " << p.stress_points << "     │\n";
    cout << "└─────────────────────────────────────────┘\n";
}

static void update_state_after_year(person& p, RUB year_income, RUB year_expenses) {
    RUB delta = year_income - year_expenses;
    p.bank.account += delta;

    if (delta > 0) {
        RUB emergency_target = p.yearly_savings_goal;
        if (p.emergency_fund < emergency_target) {
            RUB to_emergency = delta / 2;
            RUB gap = emergency_target - p.emergency_fund;
            if (to_emergency > gap) to_emergency = gap;
            p.emergency_fund += to_emergency;
            p.bank.account -= to_emergency;
            delta -= to_emergency;
        }

        RUB to_deposit = delta / 3;
        p.bank.account -= to_deposit;
        p.bank.deposit += to_deposit;

        p.monthly_investment = (RUB)(p.monthly_investment * 1.02);
        p.retirement_fund += to_deposit * 0.2;
    } else {
        p.stress_points += 4;
        p.happiness_points -= 3;
        p.monthly_investment = (RUB)(p.monthly_investment * 0.98);
    }

    if (p.bank.account < 0) {
        RUB deficit = -p.bank.account;
        RUB from_emergency = (p.emergency_fund >= deficit) ? deficit : p.emergency_fund;
        p.emergency_fund -= from_emergency;
        deficit -= from_emergency;
        p.bank.account = 0;

        if (deficit > 0) {
            RUB from_deposit = (p.bank.deposit >= deficit) ? deficit : p.bank.deposit;
            p.bank.deposit -= from_deposit;
            deficit -= from_deposit;
        }

        if (deficit > 0) {
            p.stress_points += 18;
            p.happiness_points -= 8;
        } else {
            p.stress_points += 10;
        }
    }

    p.health_points = (int)clamp_rub(p.health_points + random_int(-4, 3), 35, 100);
    p.happiness_points = (int)clamp_rub(p.happiness_points + random_int(-3, 4), 20, 100);
    p.energy_points = (int)clamp_rub(p.energy_points + random_int(-3, 3), 20, 100);
    p.discipline_points = (int)clamp_rub(p.discipline_points + random_int(-2, 2), 30, 100);
    p.stress_points = (int)clamp_rub(p.stress_points + random_int(-2, 3), 0, 100);

    p.sleep_quality = (int)clamp_rub(p.sleep_quality + random_int(-5, 5), 30, 100);
    p.nutrition_quality = (int)clamp_rub(p.nutrition_quality + random_int(-3, 4), 35, 100);
    p.career_satisfaction = (int)clamp_rub(p.career_satisfaction + random_int(-5, 8), 20, 100);
    p.relationship_quality = (int)clamp_rub(p.relationship_quality + random_int(-4, 6), 25, 100);
    p.financial_literacy = (int)clamp_rub(p.financial_literacy + random_int(-2, 5), 30, 100);
    p.networking_skills = (int)clamp_rub(p.networking_skills + random_int(-3, 4), 20, 100);
    p.leadership_skills = (int)clamp_rub(p.leadership_skills + random_int(-2, 5), 25, 100);
    p.technical_skills = (int)clamp_rub(p.technical_skills + random_int(-2, 6), 30, 100);
    p.soft_skills = (int)clamp_rub(p.soft_skills + random_int(-3, 5), 35, 100);

    p.friends_count = (int)clamp_rub(p.friends_count + random_int(-2, 3), 1, 30);
    p.social_connections = (int)clamp_rub(p.social_connections + random_int(-5, 8), 5, 80);
    p.hobby_diversity = (int)clamp_rub(p.hobby_diversity + random_int(-1, 2), 1, 8);
    p.volunteer_hours = (int)clamp_rub(p.volunteer_hours + random_int(-2, 3), 0, 20);
}

static void apply_deposit_yield(person& p) {
    if (p.bank.deposit > 0) {
        double monthly_factor = kDepositAprPp / 12.0 / 100.0;
        RUB interest = (RUB)(p.bank.deposit * monthly_factor);
        if (interest > 0) {
            p.bank.deposit += interest;
        }
    }
}

static void transfer_cash_to_deposit(person& p) {
    RUB moved = min_rub(kMonthlyCashToDeposit, p.bank.account);
    if (moved > 0) {
        p.bank.account -= moved;
        p.bank.deposit += moved;
    }
}

static void pay_expense_from_buffers(person& p, RUB due, RUB& paid, RUB& unpaid) {
    paid = 0;
    unpaid = 0;
    if (due <= 0) return;

    RUB remaining = due;

    if (p.bank.account >= remaining) {
        p.bank.account -= remaining;
        paid = remaining;
        return;
    }

    paid = p.bank.account;
    remaining -= p.bank.account;
    p.bank.account = 0;

    if (remaining > 0 && p.emergency_fund > 0) {
        RUB take_emergency = min_rub(p.emergency_fund, remaining);
        p.emergency_fund -= take_emergency;
        paid += take_emergency;
        remaining -= take_emergency;
    }

    if (remaining > 0 && p.bank.deposit > 0) {
        RUB take_dep = min_rub(p.bank.deposit, remaining);
        p.bank.deposit -= take_dep;
        paid += take_dep;
        remaining -= take_dep;
    }

    if (remaining > 0) {
        unpaid = remaining;
    }
}

static void refill_emergency_target(person& p) {
    if (p.emergency_fund >= p.yearly_savings_goal) return;

    RUB need = p.yearly_savings_goal - p.emergency_fund;

    RUB from_cash = min_rub(need, p.bank.account);
    p.bank.account -= from_cash;
    need -= from_cash;

    RUB from_dep = min_rub(need, p.bank.deposit);
    p.bank.deposit -= from_dep;
    need -= from_dep;

    p.emergency_fund += (from_cash + from_dep);
}

static void apply_stats_after_year(person& p, RUB net_savings, RUB unpaid_expenses) {
    int hp_delta = random_int(-5, 3);
    int happy_delta = 0;
    int stress_delta = 0;
    int energy_delta = random_int(-3, 2);
    int discipline_delta = random_int(-2, 3);

    if (unpaid_expenses > 0) {
        int penalty = (int)min_rub(unpaid_expenses / 50000, (RUB)25);
        if (penalty < 0) penalty = 0;
        stress_delta += 8 + penalty;
        happy_delta -= 5 + penalty;
        hp_delta -= 2 + penalty / 2;
    } else if (net_savings >= 0) {
        stress_delta += random_int(-2, 2);
        happy_delta += random_int(-1, 4);
        hp_delta += random_int(-1, 3);
    } else {
        stress_delta += random_int(4, 9);
        happy_delta -= random_int(1, 6);
        hp_delta -= random_int(1, 4);
    }

    p.stress_points = (int)clamp_rub(p.stress_points + stress_delta, 0, 100);
    p.happiness_points = (int)clamp_rub(p.happiness_points + happy_delta, 20, 100);
    p.health_points = (int)clamp_rub(p.health_points + hp_delta, 35, 100);
    p.energy_points = (int)clamp_rub(p.energy_points + energy_delta, 20, 100);
    p.discipline_points = (int)clamp_rub(p.discipline_points + discipline_delta, 30, 100);
}

enum DiaryAction : unsigned char {
    ACT_WORK = 0,
    ACT_FAMILY,
    ACT_STUDY,
    ACT_GYM,
    ACT_REST,
    ACT_TRAVEL,
    ACT_SICK,
    ACT_SHOPPING,
    ACT_CHARITY,
    ACT_SELF_CARE,
    ACT_PARTY,
    ACT_HOME_IMPROVEMENT,
    ACT_SLEEP_IN
};

const unsigned char DIARY_ACTIONS[] = {
    ACT_REST, ACT_REST,
    ACT_REST, ACT_REST,
    ACT_STUDY, ACT_REST,
    ACT_FAMILY, ACT_REST,
    ACT_REST, ACT_STUDY,
    ACT_GYM, ACT_REST,
    ACT_REST, ACT_FAMILY,
    ACT_STUDY, ACT_REST,
    ACT_REST, ACT_REST,
    ACT_REST, ACT_STUDY,
    ACT_FAMILY, ACT_GYM,
    ACT_REST, ACT_REST,
    ACT_STUDY, ACT_REST,
    ACT_REST, ACT_FAMILY,
    ACT_REST, ACT_STUDY,
    ACT_REST, ACT_REST,
    ACT_GYM, ACT_REST,
    ACT_FAMILY, ACT_REST,
    ACT_REST, ACT_REST,
    ACT_REST, ACT_STUDY,
    ACT_REST, ACT_FAMILY,
    ACT_REST, ACT_GYM,
    ACT_STUDY, ACT_REST,
    ACT_REST, ACT_REST,
    ACT_FAMILY, ACT_STUDY,
    ACT_REST, ACT_REST,
    ACT_TRAVEL, ACT_REST,
    ACT_GYM, ACT_FAMILY,
    ACT_REST, ACT_REST,
    ACT_REST, ACT_STUDY,
    ACT_REST, ACT_REST,
    ACT_FAMILY, ACT_REST,
    ACT_STUDY, ACT_GYM,
    ACT_REST, ACT_REST,
    ACT_REST, ACT_FAMILY,
    ACT_REST, ACT_REST,
    ACT_REST, ACT_REST,
    ACT_STUDY, ACT_REST,
    ACT_GYM, ACT_REST,
    ACT_REST, ACT_STUDY,
    ACT_REST, ACT_REST,
    ACT_REST, ACT_FAMILY,
    ACT_STUDY, ACT_REST,
    ACT_REST, ACT_GYM,
    ACT_REST, ACT_STUDY,
    ACT_FAMILY, ACT_REST,
    ACT_REST, ACT_REST,
    ACT_STUDY, ACT_REST,
    ACT_SICK, ACT_FAMILY,
    ACT_GYM, ACT_STUDY
};

const int DIARY_DAYS = sizeof(DIARY_ACTIONS) / sizeof(DIARY_ACTIONS[0]);

static double seasonal_cost_multiplier(int month, int year_index) {
    (void)year_index;  // seasonality is enough for month-level spending.
    // Winter -> heating/utility costs, Summer -> leisure/travel costs.
    if (month == 12 || month == 1 || month == 2) return 1.08;
    if (month == 3 || month == 4) return 1.03;
    if (month >= 6 && month <= 8) return 1.05;
    if (month == 5 || month == 9 || month == 10) return 1.01;
    if (month == 11) return 1.04;
    return 1.0;
}

static double seasonal_illness_multiplier(int month, int year_index) {
    (void)year_index;
    // Cold season raises probability of illnesses slightly.
    if (month == 12 || month == 1 || month == 2) return 1.25;
    if (month == 3) return 1.08;
    if (month == 11) return 1.15;
    return 1.0;
}

static int clamp_int(int v, int lo, int hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static life_year_report simulate_year(person& p, int year_index) {
    apply_life_events(p, year_index);

    RUB income_year = 0;
    RUB paid_expenses_year = 0;
    RUB unpaid_expenses_year = 0;

    for (int month = 1; month <= 12; ++month) {
        double employment_factor = 1.0;
        bool unemployment_active = false;
        int job_loss_extra_stress = 0;
        int job_loss_extra_happiness = 0;
        RUB job_loss_extra_due = 0;

        if (p.employed) {
            unemployment_active = false;

            if (p.age >= 22 && p.age <= 60) {
                double risk =
                    0.002 +
                    (p.stress_points / 100.0) * 0.014 +
                    (p.discipline_points < 50 ? (50 - p.discipline_points) : 0) / 100.0 * 0.004;
                if (risk < 0.001) risk = 0.001;
                if (risk > 0.05) risk = 0.05;

                if (random_int(0, 9999) < (int)(risk * 10000.0)) {
                    p.employed = false;
                    p.unemployment_months = random_int(2, 6);
                    employment_factor = 0.35;
                    unemployment_active = true;
                    job_loss_extra_stress = random_int(5, 14);
                    job_loss_extra_happiness = -random_int(2, 8);
                    job_loss_extra_due = (RUB)random_int(2000, 9000);
                }
            }
        } else {
            unemployment_active = true;
            employment_factor = 0.35;
            p.unemployment_months -= 1;
            if (p.unemployment_months <= 0) {
                p.employed = true;
                p.unemployment_months = 0;
                unemployment_active = false;
                employment_factor = 1.0;
            }
        }

        RUB month_income = estimate_monthly_income_after_tax(p, year_index, employment_factor, month);
        income_year += month_income;
        p.bank.account += month_income;

        apply_deposit_yield(p);

        int extra_stress = 0;
        int extra_happiness = 0;
        int extra_health = 0;
        int extra_energy = 0;

        RUB month_extra_due = 0;
        int cnt_work = 0;
        int cnt_family = 0;
        int cnt_study = 0;
        int cnt_gym = 0;
        int cnt_rest = 0;
        int cnt_travel = 0;
        int cnt_sick = 0;
        int cnt_shopping = 0;
        int cnt_charity = 0;
        int cnt_self_care = 0;
        int cnt_party = 0;
        int cnt_home = 0;
        int cnt_sleep_in = 0;

        if (job_loss_extra_stress != 0) {
            extra_stress += job_loss_extra_stress;
            extra_happiness += job_loss_extra_happiness;
            month_extra_due += job_loss_extra_due;
        }

        RUB month_due_base = estimate_monthly_expenses(p, year_index);
        double season_cost = seasonal_cost_multiplier(month, year_index);
        RUB month_due = (RUB)(month_due_base * season_cost);
        if (unemployment_active) {
            month_due = (RUB)(month_due * 0.85);
        }

        if (DIARY_DAYS > 0) {
            for (int day = 0; day < 30; ++day) {
                int day_index = year_index * 365 + (month - 1) * 30 + day;
                unsigned char act = DIARY_ACTIONS[day_index % DIARY_DAYS];

                // Month-level "impulses" that do not come from the static diary sequence.
                // They depend on the current emotional/physical state, so it is still real simulation.
                int roll = random_int(0, 9999);
                if (roll < p.stress_points) {
                    act = ACT_SELF_CARE;
                } else {
                    roll = random_int(0, 9999);
                    if (roll < max(0, 45 - p.energy_points) * 2) {
                        act = ACT_SLEEP_IN;
                    }
                }

                roll = random_int(0, 9999);
                if (act != ACT_SLEEP_IN && roll < max(0, 55 - p.financial_literacy) * 2) {
                    act = ACT_SHOPPING;
                }

                roll = random_int(0, 9999);
                if (act != ACT_SELF_CARE && p.relationship_quality > 60 && roll < 35) {
                    act = ACT_PARTY;
                }

                roll = random_int(0, 9999);
                if (act != ACT_PARTY && p.volunteer_hours < 10 && roll < 22) {
                    act = ACT_CHARITY;
                }

                roll = random_int(0, 9999);
                if (act != ACT_HOME_IMPROVEMENT && p.has_house && roll < 18 + month) {
                    act = ACT_HOME_IMPROVEMENT;
                }

                switch (act) {
                    case ACT_WORK:
                        cnt_work++;
                        extra_stress -= 1;
                        extra_happiness += 1;
                        break;
                    case ACT_FAMILY:
                        cnt_family++;
                        extra_stress -= 1;
                        extra_happiness += 2;
                        month_extra_due += 500;
                        break;
                    case ACT_STUDY:
                        cnt_study++;
                        extra_stress += 1;
                        extra_happiness += 1;
                        extra_energy -= 1;
                        month_extra_due += 400;
                        break;
                    case ACT_GYM:
                        cnt_gym++;
                        extra_stress -= 1;
                        extra_health += 1;
                        extra_energy += 1;
                        month_extra_due += 700;
                        break;
                    case ACT_REST:
                        cnt_rest++;
                        extra_stress -= 2;
                        extra_happiness += 2;
                        extra_energy += 2;
                        month_extra_due += 200;
                        break;
                    case ACT_TRAVEL:
                        cnt_travel++;
                        extra_stress += 1;
                        extra_happiness += 3;
                        extra_energy -= 1;
                        month_extra_due += 4000;
                        break;
                    case ACT_SICK:
                        cnt_sick++;
                        extra_stress += 3;
                        extra_happiness -= 2;
                        extra_health -= 4;
                        extra_energy -= 2;
                        month_extra_due += 2500;
                        break;
                    case ACT_SHOPPING:
                        cnt_shopping++;
                        extra_stress += 1;
                        extra_happiness += 2;
                        extra_energy -= 1;
                        month_extra_due += random_int(900, 4500);
                        break;
                    case ACT_CHARITY:
                        cnt_charity++;
                        extra_stress -= 1;
                        extra_happiness += 3;
                        extra_energy -= 0;
                        month_extra_due += random_int(200, 1200);
                        break;
                    case ACT_SELF_CARE:
                        cnt_self_care++;
                        extra_stress -= 2;
                        extra_happiness += 2;
                        extra_health += 1;
                        extra_energy += 1;
                        month_extra_due += random_int(700, 3200);
                        break;
                    case ACT_PARTY:
                        cnt_party++;
                        extra_stress += 2;
                        extra_happiness += 4;
                        extra_health -= 0;
                        extra_energy -= 2;
                        month_extra_due += random_int(1500, 7500);
                        break;
                    case ACT_HOME_IMPROVEMENT:
                        cnt_home++;
                        extra_stress -= 1;
                        extra_happiness += 2;
                        extra_health -= 0;
                        extra_energy -= 2;
                        month_extra_due += random_int(2500, 12000);
                        break;
                    case ACT_SLEEP_IN:
                        cnt_sleep_in++;
                        extra_stress -= 1;
                        extra_happiness += 1;
                        extra_health += 0;
                        extra_energy += 2;
                        month_extra_due += 0;
                        break;
                    default:
                        break;
                }
            }
        }

        if (p.age <= DIARY_VERBOSE_MAX_AGE) {
            cout << p.person_name
                 << " | Age " << p.age
                 << " | Month " << month
                 << " diary: work=" << cnt_work
                 << ", family=" << cnt_family
                 << ", study=" << cnt_study
                 << ", gym=" << cnt_gym
                 << ", rest=" << cnt_rest
                 << ", travel=" << cnt_travel
                 << ", sick=" << cnt_sick
                 << ", shopping=" << cnt_shopping
                 << ", charity=" << cnt_charity
                 << ", selfcare=" << cnt_self_care
                 << ", party=" << cnt_party
                 << ", home=" << cnt_home
                 << ", sleepin=" << cnt_sleep_in
                 << " | extraDue=" << month_extra_due
                 << "\n";
        }

        // Monthly trait progression driven by the diary mix.
        // This makes "life by months" more continuous: repeated behavior nudges long-term traits.
        {
            // Learning & career. More study sessions -> better technical skills and discipline.
            if (cnt_study >= 6) {
                p.technical_skills = clamp_int(p.technical_skills + random_int(2, 5), 0, 100);
                p.soft_skills = clamp_int(p.soft_skills + random_int(0, 2), 0, 100);
                p.discipline_points = clamp_int(p.discipline_points + random_int(1, 3), 0, 100);
                p.career_satisfaction = clamp_int(p.career_satisfaction + random_int(1, 3), 0, 100);
            } else if (cnt_study >= 3) {
                p.technical_skills = clamp_int(p.technical_skills + random_int(1, 3), 0, 100);
                p.discipline_points = clamp_int(p.discipline_points + random_int(0, 2), 0, 100);
            }

            // Training & body. Gym sessions improve discipline and sleep quality in small amounts.
            if (cnt_gym >= 5) {
                p.health_points = clamp_int(p.health_points + random_int(1, 4), 35, 100);
                p.discipline_points = clamp_int(p.discipline_points + random_int(1, 3), 0, 100);
                p.sleep_quality = clamp_int(p.sleep_quality + random_int(2, 5), 0, 100);
                p.nutrition_quality = clamp_int(p.nutrition_quality + random_int(0, 3), 0, 100);
            } else if (cnt_gym >= 3) {
                p.sleep_quality = clamp_int(p.sleep_quality + random_int(0, 2), 0, 100);
            }

            // Rest & recovery. Frequent rest makes energy stabilize and reduces stress slowly.
            if (cnt_rest >= 7) {
                p.energy_points = clamp_int(p.energy_points + random_int(1, 3), 20, 100);
                p.stress_points = clamp_int(p.stress_points - random_int(1, 4), 0, 100);
                p.happiness_points = clamp_int(p.happiness_points + random_int(1, 4), 20, 100);
            } else if (cnt_rest >= 4) {
                p.energy_points = clamp_int(p.energy_points + random_int(0, 2), 20, 100);
            }

            // Social life & relationships.
            if (cnt_family >= 3) {
                p.relationship_quality = clamp_int(p.relationship_quality + random_int(1, 3), 0, 100);
                p.social_connections = clamp_int(p.social_connections + random_int(0, 2), 0, 100);
            }
            if (cnt_travel >= 2 || cnt_party >= 2) {
                p.relationship_quality = clamp_int(p.relationship_quality + random_int(1, 3), 0, 100);
                p.friends_count = clamp_int(p.friends_count + random_int(0, 2), 0, 100);
            }

            // Charity & volunteering.
            if (cnt_charity >= 2) {
                p.volunteer_hours = clamp_int(p.volunteer_hours + random_int(1, 3), 0, 100);
                p.happiness_points = clamp_int(p.happiness_points + random_int(0, 2), 20, 100);
            }

            // Home improvement & finances.
            if (cnt_home >= 2) {
                p.financial_literacy = clamp_int(p.financial_literacy + random_int(1, 4), 0, 100);
                p.soft_skills = clamp_int(p.soft_skills + random_int(0, 2), 0, 100);
                p.stress_points = clamp_int(p.stress_points - random_int(0, 2), 0, 100);
            }

            // Sleep-in improves sleep quality but may slightly reduce discipline if it is frequent.
            if (cnt_sleep_in >= 4) {
                p.sleep_quality = clamp_int(p.sleep_quality + random_int(2, 5), 0, 100);
                p.discipline_points = clamp_int(p.discipline_points - random_int(0, 3), 0, 100);
            } else if (cnt_sleep_in >= 2) {
                p.sleep_quality = clamp_int(p.sleep_quality + random_int(0, 2), 0, 100);
            }

            // Illness episodes reduce short-term energy; long-term recovery is handled by stats after year.
            if (cnt_sick >= 1) {
                p.energy_points = clamp_int(p.energy_points - random_int(0, 3), 20, 100);
                p.nutrition_quality = clamp_int(p.nutrition_quality - random_int(0, 2), 0, 100);
            }
        }

        if (p.has_children) {
            double child_event_risk = 0.003 + (p.stress_points / 100.0) * 0.01;
            if (random_int(0, 9999) < (int)(child_event_risk * 10000.0)) {
                month_extra_due += random_int(1500, 12000);
                extra_stress += random_int(1, 4);
                extra_happiness -= random_int(0, 3);
                extra_energy -= random_int(0, 2);
            }
        }

        // Extra monthly events that depend on current lifestyle and season.
        {
            // Social catch-up: happens more often when social connections are low.
            if (p.social_connections < 45) {
                double social_risk = 0.004 + (45 - p.social_connections) / 100.0 * 0.03;
                if (random_int(0, 9999) < (int)(social_risk * 10000.0)) {
                    month_extra_due += random_int(800, 6500);
                    extra_happiness += random_int(2, 6);
                    extra_stress -= random_int(0, 2);
                    extra_energy -= random_int(0, 2);
                    p.social_connections += random_int(1, 3);
                    p.friends_count += random_int(0, 1);
                }
            }

            // Car incident / maintenance: depends on ownership and stress/energy.
            if (p.has_car) {
                int tiredness = max(0, 60 - p.energy_points);
                double car_risk = 0.002 + tiredness / 100.0 * 0.02 + (p.age > 50 ? 0.01 : 0.0);
                if (random_int(0, 9999) < (int)(car_risk * 10000.0)) {
                    month_extra_due += random_int(3000, 22000);
                    extra_stress += random_int(4, 12);
                    extra_happiness -= random_int(0, 4);
                    extra_energy -= random_int(1, 3);
                }
            }

            // Home maintenance: if you own a house/apartment, expect occasional repairs.
            if (p.has_house || p.has_apartment) {
                double home_risk = 0.0015 + (p.stress_points / 100.0) * 0.012;
                if (p.age > 45) home_risk += 0.01;
                if (random_int(0, 9999) < (int)(home_risk * 10000.0)) {
                    month_extra_due += random_int(2500, 18000);
                    extra_stress += random_int(1, 6);
                    extra_happiness -= random_int(0, 3);
                    extra_energy -= random_int(1, 3);
                }
            }

            // Burnout: when stress is high and energy is low, probability increases.
            if (p.stress_points > 70 && p.energy_points < 45) {
                double burnout_risk =
                    0.004 + (p.stress_points - 70) / 100.0 * 0.04 + (45 - p.energy_points) / 100.0 * 0.03;
                if (random_int(0, 9999) < (int)(burnout_risk * 10000.0)) {
                    month_extra_due += random_int(1500, 9000);
                    extra_stress += random_int(8, 18);
                    extra_happiness -= random_int(2, 7);
                    extra_health -= random_int(2, 6);
                    extra_energy -= random_int(3, 8);
                }
            }
        }

        {
            double illness_risk =
                0.002 +
                ((100.0 - p.health_points) / 100.0) * 0.02 +
                (p.stress_points / 100.0) * 0.012;
            if (illness_risk > 0.07) illness_risk = 0.07;
            illness_risk *= seasonal_illness_multiplier(month, year_index);
            if (illness_risk > 0.09) illness_risk = 0.09;
            if (random_int(0, 9999) < (int)(illness_risk * 10000.0)) {
                month_extra_due += random_int(4000, 25000);
                extra_stress += random_int(3, 10);
                extra_happiness -= random_int(0, 4);
                extra_health -= random_int(2, 10);
                extra_energy -= random_int(1, 4);
            }
        }

        month_due += month_extra_due;
        RUB cash_before = p.bank.account;
        RUB deposit_before = p.bank.deposit;
        RUB emergency_before = p.emergency_fund;
        RUB month_paid = 0;
        RUB month_unpaid = 0;
        pay_expense_from_buffers(p, month_due, month_paid, month_unpaid);
        RUB used_cash = cash_before - p.bank.account;
        RUB used_deposit = deposit_before - p.bank.deposit;
        RUB used_emergency = emergency_before - p.emergency_fund;

        paid_expenses_year += month_paid;
        unpaid_expenses_year += month_unpaid;

        p.stress_points = (int)clamp_rub(p.stress_points + extra_stress, 0, 100);
        p.happiness_points = (int)clamp_rub(p.happiness_points + extra_happiness, 20, 100);
        p.health_points = (int)clamp_rub(p.health_points + extra_health, 35, 100);
        p.energy_points = (int)clamp_rub(p.energy_points + extra_energy, 20, 100);

        // Micro-adjustment: sleep quality affects energy during the month.
        // This is intentionally small; the main yearly drift is handled in apply_stats_after_year().
        {
            int sleep_delta = 0;
            if (p.sleep_quality >= 80) sleep_delta = 1;
            else if (p.sleep_quality < 55) sleep_delta = -1;

            int nutrition_delta = 0;
            if (p.nutrition_quality >= 80) nutrition_delta = 1;
            else if (p.nutrition_quality < 55) nutrition_delta = -1;

            p.energy_points = clamp_int(p.energy_points + sleep_delta, 20, 100);
            p.health_points = clamp_int(p.health_points + nutrition_delta, 35, 100);
        }

        transfer_cash_to_deposit(p);

        if (p.age <= DIARY_VERBOSE_MAX_AGE) {
            cout << p.person_name
                 << " | Age " << (p.age + 0) // month belongs to current age
                 << " | Month " << month
                 << " finance: due=" << month_due
                 << ", paid=" << month_paid
                 << ", unpaid=" << month_unpaid
                 << " (cash=" << used_cash
                 << ", emergency=" << used_emergency
                 << ", deposit=" << used_deposit
                 << ") | stats: stress=" << p.stress_points
                 << ", happiness=" << p.happiness_points
                 << ", health=" << p.health_points
                 << ", energy=" << p.energy_points
                 << "\n";
        }
    }

    RUB net_savings = income_year - paid_expenses_year;
    refill_emergency_target(p);
    apply_stats_after_year(p, net_savings, unpaid_expenses_year);

    RUB invested = p.bank.deposit;
    RUB net_worth = p.bank.account + p.bank.deposit + p.emergency_fund;

    life_year_report report;
    report.age = p.age;
    report.income = income_year;
    report.expenses = paid_expenses_year;
    report.invested = invested;
    report.emergency_fund = p.emergency_fund;
    report.net_worth = net_worth;

    p.age++;
    return report;
}

static void print_report(const life_year_report& r, const char* who) {
    cout << who << " | Age: " << r.age
         << " | Income: " << r.income
         << " | Expenses: " << r.expenses
         << " | Deposit: " << r.invested
         << " | Emergency: " << r.emergency_fund
         << " | NetWorth: " << r.net_worth
         << "\n";
}

int main() {
    srand((unsigned)time(nullptr));

    person alice;
    person ken;
    init_person(alice, "Alice");
    init_person(ken, "Ken");

    vector<life_year_report> alice_history;
    vector<life_year_report> ken_history;

    cout << "==== Alice life simulation (C++) ====\n";
    cout << "Start age: " << alice.age << "\n";
    cout << "Start account: " << alice.bank.account << "\n\n";
    for (int y = 0; y < 95; ++y) {
        life_year_report rep = simulate_year(alice, y);
        alice_history.push_back(rep);
        print_report(rep, "Alice");
        if (y % 10 == 0 || y == 94) {
            print_annual_summary(rep, alice, y);
        }
    }

    cout << "\n==== Ken life simulation (C++) ====\n";
    cout << "Start age: " << ken.age << "\n";
    cout << "Start account: " << ken.bank.account << "\n\n";
    for (int y = 0; y < 95; ++y) {
        life_year_report rep = simulate_year(ken, y);
        ken_history.push_back(rep);
        print_report(rep, "Ken");
        if (y % 10 == 0 || y == 94) {
            print_annual_summary(rep, ken, y);
        }
    }

    cout << "\n==== Alice Final State ====\n";
    cout << "Person: " << alice.person_name << "\n";
    cout << "Age: " << alice.age << "\n";
    cout << "Account: " << alice.bank.account << "\n";
    cout << "Deposit: " << alice.bank.deposit << "\n";
    cout << "Emergency fund: " << alice.emergency_fund << "\n";
    cout << "Health: " << alice.health_points << "\n";
    cout << "Happiness: " << alice.happiness_points << "\n";
    cout << "Stress: " << alice.stress_points << "\n";
    cout << "Family: married=" << (alice.is_married ? "yes" : "no")
         << ", children=" << (alice.has_children ? "yes" : "no") << "\n";

    cout << "\n==== Ken Final State ====\n";
    cout << "Person: " << ken.person_name << "\n";
    cout << "Age: " << ken.age << "\n";
    cout << "Account: " << ken.bank.account << "\n";
    cout << "Deposit: " << ken.bank.deposit << "\n";
    cout << "Emergency fund: " << ken.emergency_fund << "\n";
    cout << "Health: " << ken.health_points << "\n";
    cout << "Happiness: " << ken.happiness_points << "\n";
    cout << "Stress: " << ken.stress_points << "\n";
    cout << "Family: married=" << (ken.is_married ? "yes" : "no")
         << ", children=" << (ken.has_children ? "yes" : "no") << "\n";

    print_detailed_health_report(alice);
    print_financial_analysis(alice);
    print_career_progress(alice);
    print_life_balance(alice);
    print_retirement_readiness(alice);

    print_detailed_health_report(ken);
    print_financial_analysis(ken);
    print_career_progress(ken);
    print_life_balance(ken);
    print_retirement_readiness(ken);

    compare_persons(alice, ken);

    save_report_to_file(alice, "alice_report.txt");
    save_report_to_file(ken, "ken_report.txt");

    return 0;
}
