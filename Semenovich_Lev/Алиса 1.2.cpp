#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

using Percent = float;
using RUB = long long int;
using USD = long long int;
using EUR = long long int;
using Time = int;

struct Stock {
    RUB value;
    Percent growth_rate;
    Percent fall_rate;
    int months_since_change;
    RUB dividend;
    Percent dividend_yield;
    int rating;
    RUB market_cap;
    RUB pe_ratio;
    RUB eps;
    int shares_count;
    RUB volatility;
    bool is_dividend_paid;
};

struct TravelInfo {
    int month_start;
    int year_start;
    int destination_id;
    RUB total_cost;
    RUB hotel_cost_total;
    RUB flight_cost;
    RUB daily_expenses;
    RUB excursion_cost;
    RUB souvenir_cost;
    RUB food_cost_travel;
    RUB transport_cost;
    RUB visa_cost;
    RUB insurance_cost;
    int duration_days;
    RUB income_generated;
    int likes_count;
    int views_count;
    int comments_count;
    int shares_count;
    RUB sponsorship_deal;
    int rating;
    RUB unexpected_cost;
};

struct Travel {
    bool is_traveling;
    int days_in_travel;
    RUB daily_income_bonus;
    RUB hotel_cost_per_day;
    RUB flight_cost;
    int months_until_next;
    TravelInfo history[50];
    int trips_count;
    RUB total_travel_cost;
    RUB total_travel_income;
    RUB total_likes;
    RUB total_views;
    RUB total_comments;
    RUB best_trip_income;
    int longest_trip;
    RUB favorite_destination;
    int trips_by_type[10];
    RUB total_unexpected_costs;
};

struct ApartmentRent {
    RUB monthly_rent;
    RUB utilities;
    RUB internet;
    RUB deposit;
    bool is_rented;
    int contract_months;
    RUB total_paid;
    RUB penalties;
    RUB furniture_cost;
    RUB repair_cost;
    bool has_insurance;
    RUB insurance_cost;
    RUB cleaning_cost;
    RUB parking_cost;
    bool has_pets_allowed;
    int landlord_rating;
};

struct Apartment {
    RUB mortgage_debt;
    RUB monthly_payment;
    RUB renovation_cost;
    RUB renovation_spent;
    bool renovation_done;
    Percent renovation_progress;
    ApartmentRent rent;
    RUB square_meters;
    int rooms_count;
    int floor;
    int building_floors;
    bool has_balcony;
    bool has_parking;
    RUB property_tax;
    RUB insurance_home;
    RUB utility_debt;
};

struct Dog {
    RUB food_cost;
    RUB vet_cost;
    RUB toys_cost;
    RUB grooming_cost;
    RUB insurance_cost;
    RUB training_cost;
    RUB walking_cost;
    RUB medicine_cost;
    bool is_sick;
    bool is_vaccinated;
    bool is_alive;
    int age_months;
    int vet_visits;
    int sickness_count;
    RUB total_spent;
    RUB food_eaten;
    int walks_count;
    RUB weight;
    int happiness_level;
    int health_level;
    int training_level;
    bool is_trained;
    bool is_spayed;
    RUB chip_cost;
    RUB passport_cost;
};

struct Food {
    RUB groceries;
    RUB restaurants;
    RUB delivery;
    RUB coffee;
    RUB sweets;
    RUB alcohol;
    RUB healthy_food;
    RUB fast_food;
    RUB total;
    RUB organic_food;
    RUB exotic_food;
    RUB meal_prep;
    RUB catering;
};

struct Bank {
    RUB account_rub;
    USD account_usd;
    EUR account_eur;
    float rate_usd_rub;
    float rate_eur_rub;
    RUB credit_limit;
    RUB credit_debt;
    Percent credit_rate;
    RUB savings_account;
    RUB deposit_account;
    Percent deposit_rate;
    int credit_score;
    RUB monthly_interest;
    RUB total_interest_earned;
};

struct Credit {
    RUB debt;
    Time month;
    RUB payment;
    RUB remainder;
    Percent rate;
    int remaining_months;
    RUB overpayment;
    RUB monthly_payment_min;
    RUB early_repayment_penalty;
    bool is_early_repayment;
    int late_payments;
    RUB late_fee;
};

struct Career {
    RUB office_salary;
    RUB blogger_income;
    RUB filming_cost;
    bool is_office_working;
    int years_experience;
    RUB bonus_last_year;
    int subscribers_count;
    int videos_count;
    RUB sponsorship_income;
    RUB merch_income;
    RUB ad_income;
    int collaborations_count;
    RUB youtube_income;
    RUB tiktok_income;
    RUB instagram_income;
    bool has_agent;
    RUB agent_fee;
};

struct Car {
    RUB value;
    RUB gas;
    RUB insurance;
    RUB maintenance;
    RUB parking;
    RUB washing;
    RUB tires;
    RUB repairs;
    int mileage;
    RUB tax;
    RUB fine;
    int accidents_count;
    bool is_insured;
    RUB osago;
    RUB casco;
    RUB diagnostic_cost;
    int oil_changes;
    RUB spare_parts;
    RUB tuning_cost;
    int fuel_consumption;
};

struct Health {
    bool is_sick;
    int sick_days;
    RUB medicine_cost;
    RUB gym_cost;
    RUB vitamins_cost;
    RUB doctor_cost;
    int steps_per_day;
    int sleep_hours;
    RUB dental_cost;
    RUB optical_cost;
    RUB therapy_cost;
    RUB surgery_cost;
    bool has_medical_insurance;
    RUB medical_insurance_cost;
    int stress_level;
    int energy_level;
};

struct Investment {
    RUB crypto_value;
    RUB gold_value;
    RUB real_estate_value;
    RUB bonds_value;
    RUB total_invested;
    RUB total_value;
    RUB etf_value;
    RUB pension_fund;
    RUB nfs_value;
    RUB business_investment;
    RUB startup_investment;
    int investment_years;
    RUB profit_tax;
};

struct Subscriptions {
    RUB netflix;
    RUB spotify;
    RUB youtube_premium;
    RUB cloud_storage;
    RUB gym;
    RUB total;
    RUB disney_plus;
    RUB hbo;
    RUB amazon_prime;
    RUB patreon;
    RUB onlyfans;
    RUB news_subscription;
    RUB game_pass;
};

struct Clothing {
    RUB clothes;
    RUB shoes;
    RUB accessories;
    RUB total;
    RUB winter_clothes;
    RUB summer_clothes;
    RUB sport_clothes;
    RUB work_clothes;
    RUB luxury_items;
    RUB bags;
    RUB watches;
    RUB jewelry;
};

struct Education {
    RUB courses;
    RUB books;
    RUB total;
    RUB university_fee;
    RUB language_courses;
    RUB master_class;
    RUB webinar;
    RUB conference;
    RUB certificate_cost;
    RUB mentorship;
};

struct Charity {
    RUB donations;
    RUB total;
    RUB animal_shelter;
    RUB children_fund;
    RUB environmental;
    RUB medical_charity;
    RUB education_charity;
    int charity_events;
};

struct Hobby {
    RUB sports;
    RUB music;
    RUB art;
    RUB games;
    RUB total;
    RUB tennis;
    RUB skiing;
    RUB photography;
    RUB painting;
    RUB musical_instruments;
};

struct Utilities {
    RUB electricity;
    RUB water;
    RUB gas;
    RUB heating;
    RUB garbage;
    RUB total;
    RUB home_insurance;
};

struct Tax {
    RUB income_tax;
    RUB property_tax;
    RUB transport_tax;
    RUB total;
    RUB tax_refund;
    bool is_tax_declared;
};

struct YearTravel {
    int year;
    int trips_in_year;
    RUB total_cost_year;
    RUB total_income_year;
    RUB best_destination;
};

struct Person {
    Bank vtb;
    RUB salary;
    Food food;
    RUB savings_for_investments;
    Car car;
    Credit credit;
    Career career;
    Stock stocks[7];
    Travel travel;
    Apartment apartment;
    Dog dog;
    RUB total_invested;
    RUB total_stock_value;
    Investment investments;
    Subscriptions subscriptions;
    Clothing clothing;
    Education education;
    Charity charity;
    Health health;
    RUB emergency_fund;
    RUB pension_savings;
    Hobby hobby;
    Utilities utilities;
    Tax tax;
    YearTravel travel_history[5];
    RUB total_income_lifetime;
    RUB total_expenses_lifetime;
    int age;
    bool is_married;
    bool has_children;
    int children_count;
    RUB alimony;
    RUB child_support;
    int happiness_index;
    int stress_index;
};

struct Person alice;

Percent alice_inflation(const int year) {
    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    default: inflation = 12.0; break;
    }
    return inflation;
}

void alice_init() {
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.rate_eur_rub = 85.30;
    alice.vtb.account_rub = 50000;
    alice.vtb.account_usd = 500;
    alice.vtb.account_eur = 200;
    alice.vtb.credit_limit = 500000;
    alice.vtb.credit_debt = 0;
    alice.vtb.credit_rate = 18.5;
    alice.vtb.savings_account = 0;
    alice.vtb.deposit_account = 0;
    alice.vtb.deposit_rate = 8.5;
    alice.vtb.credit_score = 720;
    alice.vtb.monthly_interest = 0;
    alice.vtb.total_interest_earned = 0;

    alice.career.office_salary = 80000;
    alice.career.blogger_income = 0;
    alice.career.filming_cost = 15000;
    alice.career.is_office_working = true;
    alice.career.years_experience = 3;
    alice.career.bonus_last_year = 0;
    alice.career.subscribers_count = 50000;
    alice.career.videos_count = 120;
    alice.career.sponsorship_income = 0;
    alice.career.merch_income = 0;
    alice.career.ad_income = 0;
    alice.career.collaborations_count = 0;
    alice.career.youtube_income = 0;
    alice.career.tiktok_income = 0;
    alice.career.instagram_income = 0;
    alice.career.has_agent = false;
    alice.career.agent_fee = 0;

    alice.food.groceries = 12000;
    alice.food.restaurants = 5000;
    alice.food.delivery = 3000;
    alice.food.coffee = 2000;
    alice.food.sweets = 1000;
    alice.food.alcohol = 1500;
    alice.food.healthy_food = 2000;
    alice.food.fast_food = 1000;
    alice.food.organic_food = 3000;
    alice.food.exotic_food = 1000;
    alice.food.meal_prep = 2000;
    alice.food.catering = 0;
    alice.food.total = alice.food.groceries + alice.food.restaurants +
        alice.food.delivery + alice.food.coffee + alice.food.sweets +
        alice.food.alcohol + alice.food.healthy_food + alice.food.fast_food;

    alice.salary = 0;
    alice.savings_for_investments = 0;
    alice.emergency_fund = 0;
    alice.pension_savings = 0;

    alice.car.value = 1800000;
    alice.car.gas = 8000;
    alice.car.insurance = 6000;
    alice.car.maintenance = 3000;
    alice.car.parking = 2000;
    alice.car.washing = 1500;
    alice.car.tires = 0;
    alice.car.repairs = 0;
    alice.car.mileage = 45000;
    alice.car.tax = 4000;
    alice.car.fine = 0;
    alice.car.accidents_count = 0;
    alice.car.is_insured = true;
    alice.car.osago = 6000;
    alice.car.casco = 25000;
    alice.car.diagnostic_cost = 0;
    alice.car.oil_changes = 4;
    alice.car.spare_parts = 0;
    alice.car.tuning_cost = 0;
    alice.car.fuel_consumption = 10;

    alice.credit.debt = 0;
    alice.credit.payment = 0;
    alice.credit.month = 0;
    alice.credit.remainder = 0;
    alice.credit.rate = 0;
    alice.credit.remaining_months = 0;
    alice.credit.overpayment = 0;
    alice.credit.monthly_payment_min = 0;
    alice.credit.early_repayment_penalty = 0;
    alice.credit.is_early_repayment = false;
    alice.credit.late_payments = 0;
    alice.credit.late_fee = 0;

    alice.apartment.mortgage_debt = 0;
    alice.apartment.monthly_payment = 0;
    alice.apartment.renovation_cost = 0;
    alice.apartment.renovation_spent = 0;
    alice.apartment.renovation_done = false;
    alice.apartment.renovation_progress = 0;
    alice.apartment.square_meters = 65;
    alice.apartment.rooms_count = 2;
    alice.apartment.floor = 5;
    alice.apartment.building_floors = 9;
    alice.apartment.has_balcony = true;
    alice.apartment.has_parking = false;
    alice.apartment.property_tax = 0;
    alice.apartment.insurance_home = 0;
    alice.apartment.utility_debt = 0;

    alice.apartment.rent.monthly_rent = 35000;
    alice.apartment.rent.utilities = 5000;
    alice.apartment.rent.internet = 1000;
    alice.apartment.rent.deposit = 70000;
    alice.apartment.rent.is_rented = true;
    alice.apartment.rent.contract_months = 12;
    alice.apartment.rent.total_paid = 0;
    alice.apartment.rent.penalties = 0;
    alice.apartment.rent.furniture_cost = 0;
    alice.apartment.rent.repair_cost = 0;
    alice.apartment.rent.has_insurance = false;
    alice.apartment.rent.insurance_cost = 0;
    alice.apartment.rent.cleaning_cost = 2000;
    alice.apartment.rent.parking_cost = 3000;
    alice.apartment.rent.has_pets_allowed = true;
    alice.apartment.rent.landlord_rating = 8;

    alice.travel.is_traveling = false;
    alice.travel.days_in_travel = 0;
    alice.travel.daily_income_bonus = 0;
    alice.travel.hotel_cost_per_day = 5000;
    alice.travel.flight_cost = 30000;
    alice.travel.months_until_next = 0;
    alice.travel.trips_count = 0;
    alice.travel.total_travel_cost = 0;
    alice.travel.total_travel_income = 0;
    alice.travel.total_likes = 0;
    alice.travel.total_views = 0;
    alice.travel.total_comments = 0;
    alice.travel.best_trip_income = 0;
    alice.travel.longest_trip = 0;
    alice.travel.favorite_destination = 0;
    alice.travel.total_unexpected_costs = 0;
    for (int i = 0; i < 10; i++) alice.travel.trips_by_type[i] = 0;

    alice.dog.food_cost = 5000;
    alice.dog.vet_cost = 2000;
    alice.dog.toys_cost = 1000;
    alice.dog.grooming_cost = 1500;
    alice.dog.insurance_cost = 800;
    alice.dog.training_cost = 2000;
    alice.dog.walking_cost = 3000;
    alice.dog.medicine_cost = 0;
    alice.dog.is_sick = false;
    alice.dog.is_vaccinated = true;
    alice.dog.is_alive = true;
    alice.dog.age_months = 24;
    alice.dog.vet_visits = 0;
    alice.dog.sickness_count = 0;
    alice.dog.total_spent = 0;
    alice.dog.food_eaten = 0;
    alice.dog.walks_count = 0;
    alice.dog.weight = 15;
    alice.dog.happiness_level = 80;
    alice.dog.health_level = 90;
    alice.dog.training_level = 70;
    alice.dog.is_trained = true;
    alice.dog.is_spayed = false;
    alice.dog.chip_cost = 0;
    alice.dog.passport_cost = 0;

    alice.investments.crypto_value = 0;
    alice.investments.gold_value = 0;
    alice.investments.real_estate_value = 0;
    alice.investments.bonds_value = 0;
    alice.investments.total_invested = 0;
    alice.investments.total_value = 0;
    alice.investments.etf_value = 0;
    alice.investments.pension_fund = 0;
    alice.investments.nfs_value = 0;
    alice.investments.business_investment = 0;
    alice.investments.startup_investment = 0;
    alice.investments.investment_years = 0;
    alice.investments.profit_tax = 0;

    alice.subscriptions.netflix = 799;
    alice.subscriptions.spotify = 169;
    alice.subscriptions.youtube_premium = 299;
    alice.subscriptions.cloud_storage = 199;
    alice.subscriptions.gym = 2500;
    alice.subscriptions.disney_plus = 799;
    alice.subscriptions.hbo = 599;
    alice.subscriptions.amazon_prime = 399;
    alice.subscriptions.patreon = 500;
    alice.subscriptions.onlyfans = 0;
    alice.subscriptions.news_subscription = 299;
    alice.subscriptions.game_pass = 999;
    alice.subscriptions.total = alice.subscriptions.netflix + alice.subscriptions.spotify +
        alice.subscriptions.youtube_premium + alice.subscriptions.cloud_storage +
        alice.subscriptions.gym + alice.subscriptions.disney_plus +
        alice.subscriptions.hbo + alice.subscriptions.amazon_prime +
        alice.subscriptions.patreon + alice.subscriptions.news_subscription +
        alice.subscriptions.game_pass;

    alice.clothing.clothes = 5000;
    alice.clothing.shoes = 2000;
    alice.clothing.accessories = 1000;
    alice.clothing.winter_clothes = 0;
    alice.clothing.summer_clothes = 0;
    alice.clothing.sport_clothes = 0;
    alice.clothing.work_clothes = 0;
    alice.clothing.luxury_items = 0;
    alice.clothing.bags = 0;
    alice.clothing.watches = 0;
    alice.clothing.jewelry = 0;
    alice.clothing.total = alice.clothing.clothes + alice.clothing.shoes + alice.clothing.accessories;

    alice.education.courses = 0;
    alice.education.books = 1000;
    alice.education.university_fee = 0;
    alice.education.language_courses = 0;
    alice.education.master_class = 0;
    alice.education.webinar = 0;
    alice.education.conference = 0;
    alice.education.certificate_cost = 0;
    alice.education.mentorship = 0;
    alice.education.total = alice.education.books;

    alice.charity.donations = 0;
    alice.charity.animal_shelter = 0;
    alice.charity.children_fund = 0;
    alice.charity.environmental = 0;
    alice.charity.medical_charity = 0;
    alice.charity.education_charity = 0;
    alice.charity.charity_events = 0;
    alice.charity.total = 0;

    alice.health.is_sick = false;
    alice.health.sick_days = 0;
    alice.health.medicine_cost = 0;
    alice.health.gym_cost = 2500;
    alice.health.vitamins_cost = 1000;
    alice.health.doctor_cost = 0;
    alice.health.steps_per_day = 8000;
    alice.health.sleep_hours = 7;
    alice.health.dental_cost = 0;
    alice.health.optical_cost = 0;
    alice.health.therapy_cost = 0;
    alice.health.surgery_cost = 0;
    alice.health.has_medical_insurance = true;
    alice.health.medical_insurance_cost = 5000;
    alice.health.stress_level = 50;
    alice.health.energy_level = 70;

    alice.hobby.sports = 2000;
    alice.hobby.music = 1000;
    alice.hobby.art = 500;
    alice.hobby.games = 1500;
    alice.hobby.tennis = 0;
    alice.hobby.skiing = 0;
    alice.hobby.photography = 0;
    alice.hobby.painting = 0;
    alice.hobby.musical_instruments = 0;
    alice.hobby.total = alice.hobby.sports + alice.hobby.music + alice.hobby.art + alice.hobby.games;

    alice.utilities.electricity = 2000;
    alice.utilities.water = 1000;
    alice.utilities.gas = 500;
    alice.utilities.heating = 1500;
    alice.utilities.garbage = 300;
    alice.utilities.home_insurance = 0;
    alice.utilities.total = alice.utilities.electricity + alice.utilities.water +
        alice.utilities.gas + alice.utilities.heating + alice.utilities.garbage;

    alice.tax.income_tax = 0;
    alice.tax.property_tax = 0;
    alice.tax.transport_tax = 4000;
    alice.tax.tax_refund = 0;
    alice.tax.is_tax_declared = false;
    alice.tax.total = alice.tax.transport_tax;

    alice.stocks[0].value = 100000; alice.stocks[0].growth_rate = 15.0; alice.stocks[0].fall_rate = 8.0;
    alice.stocks[0].months_since_change = 0; alice.stocks[0].dividend_yield = 2.5;
    alice.stocks[0].rating = 8; alice.stocks[0].market_cap = 10000000; alice.stocks[0].pe_ratio = 15;
    alice.stocks[0].eps = 5000; alice.stocks[0].shares_count = 10; alice.stocks[0].volatility = 12.0;
    alice.stocks[0].is_dividend_paid = false;

    alice.stocks[1].value = 80000; alice.stocks[1].growth_rate = 10.0; alice.stocks[1].fall_rate = 5.0;
    alice.stocks[1].months_since_change = 0; alice.stocks[1].dividend_yield = 3.0;
    alice.stocks[1].rating = 7; alice.stocks[1].market_cap = 8000000; alice.stocks[1].pe_ratio = 12;
    alice.stocks[1].eps = 4000; alice.stocks[1].shares_count = 8; alice.stocks[1].volatility = 8.0;
    alice.stocks[1].is_dividend_paid = false;

    alice.stocks[2].value = 120000; alice.stocks[2].growth_rate = 20.0; alice.stocks[2].fall_rate = 12.0;
    alice.stocks[2].months_since_change = 0; alice.stocks[2].dividend_yield = 1.5;
    alice.stocks[2].rating = 9; alice.stocks[2].market_cap = 12000000; alice.stocks[2].pe_ratio = 20;
    alice.stocks[2].eps = 6000; alice.stocks[2].shares_count = 12; alice.stocks[2].volatility = 18.0;
    alice.stocks[2].is_dividend_paid = false;

    alice.stocks[3].value = 90000; alice.stocks[3].growth_rate = 12.0; alice.stocks[3].fall_rate = 7.0;
    alice.stocks[3].months_since_change = 0; alice.stocks[3].dividend_yield = 2.8;
    alice.stocks[3].rating = 8; alice.stocks[3].market_cap = 9000000; alice.stocks[3].pe_ratio = 14;
    alice.stocks[3].eps = 4500; alice.stocks[3].shares_count = 9; alice.stocks[3].volatility = 10.0;
    alice.stocks[3].is_dividend_paid = false;

    alice.stocks[4].value = 110000; alice.stocks[4].growth_rate = 18.0; alice.stocks[4].fall_rate = 9.0;
    alice.stocks[4].months_since_change = 0; alice.stocks[4].dividend_yield = 2.0;
    alice.stocks[4].rating = 8; alice.stocks[4].market_cap = 11000000; alice.stocks[4].pe_ratio = 18;
    alice.stocks[4].eps = 5500; alice.stocks[4].shares_count = 11; alice.stocks[4].volatility = 15.0;
    alice.stocks[4].is_dividend_paid = false;

    alice.stocks[5].value = 70000; alice.stocks[5].growth_rate = 8.0; alice.stocks[5].fall_rate = 4.0;
    alice.stocks[5].months_since_change = 0; alice.stocks[5].dividend_yield = 4.0;
    alice.stocks[5].rating = 6; alice.stocks[5].market_cap = 7000000; alice.stocks[5].pe_ratio = 10;
    alice.stocks[5].eps = 3500; alice.stocks[5].shares_count = 7; alice.stocks[5].volatility = 6.0;
    alice.stocks[5].is_dividend_paid = false;

    alice.stocks[6].value = 150000; alice.stocks[6].growth_rate = 25.0; alice.stocks[6].fall_rate = 15.0;
    alice.stocks[6].months_since_change = 0; alice.stocks[6].dividend_yield = 1.0;
    alice.stocks[6].rating = 10; alice.stocks[6].market_cap = 15000000; alice.stocks[6].pe_ratio = 25;
    alice.stocks[6].eps = 7500; alice.stocks[6].shares_count = 15; alice.stocks[6].volatility = 22.0;
    alice.stocks[6].is_dividend_paid = false;

    alice.total_invested = 0;
    alice.total_stock_value = 720000;

    alice.total_income_lifetime = 0;
    alice.total_expenses_lifetime = 0;
    alice.age = 28;
    alice.is_married = false;
    alice.has_children = false;
    alice.children_count = 0;
    alice.alimony = 0;
    alice.child_support = 0;
    alice.happiness_index = 70;
    alice.stress_index = 30;
}

void alice_savings_distribution() {
    RUB monthly_total = alice.salary + alice.career.blogger_income +
        alice.career.sponsorship_income + alice.career.merch_income +
        alice.career.ad_income + alice.career.youtube_income +
        alice.career.tiktok_income + alice.career.instagram_income;
    RUB keep_for_expenses = 100000;

    if (monthly_total > keep_for_expenses) {
        RUB to_invest = monthly_total - keep_for_expenses;
        RUB to_emergency = to_invest * 0.2;
        RUB to_investments = to_invest * 0.8;

        alice.savings_for_investments += to_investments;
        alice.emergency_fund += to_emergency;
        alice.vtb.account_rub += keep_for_expenses;
    }
    else {
        alice.vtb.account_rub += monthly_total;
    }

    alice.total_income_lifetime += monthly_total;
}

void alice_office_salary(const int month, const int year) {
    if (alice.career.is_office_working) {
        RUB salary_to_add = alice.career.office_salary;

        if (month == 12) {
            RUB bonus = alice.career.office_salary * 0.5;
            salary_to_add += bonus;
            alice.career.bonus_last_year = bonus;
        }
        if (month == 3 && year == 2026) {
            salary_to_add += 10000;
            printf("  Квартальная премия: +10000 руб\n");
        }
        if (month == 6 && year == 2027) {
            salary_to_add += 15000;
            printf("  Летняя премия: +15000 руб\n");
        }
        if (month == 9 && year == 2028) {
            salary_to_add += 20000;
            printf("  Осенняя премия: +20000 руб\n");
        }

        alice.salary = salary_to_add;

        RUB tax = alice.salary * 0.13;
        alice.vtb.account_rub += (alice.salary - tax);
        alice.tax.income_tax += tax;

        printf("  Офисная зарплата: %lld руб (налог %lld)\n", alice.salary, tax);
    }
    else {
        alice.salary = 0;
    }
}

void alice_blogger_income(const int month, const int year) {
    RUB base_blogger_income = 50000;

    if (alice.travel.is_traveling) {
        alice.travel.daily_income_bonus += 2000;
        RUB travel_bonus = alice.travel.daily_income_bonus;
        alice.career.blogger_income = base_blogger_income + travel_bonus;
        printf("  Блогерский доход (путешествие, бонус +%lld): %lld руб\n", travel_bonus, alice.career.blogger_income);
    }
    else {
        alice.career.blogger_income = base_blogger_income;
        printf("  Блогерский доход: %lld руб\n", alice.career.blogger_income);
    }

    if (alice.career.subscribers_count > 100000) {
        alice.career.sponsorship_income = alice.career.subscribers_count / 1000 * 100;
    }
    else {
        alice.career.sponsorship_income = alice.career.subscribers_count / 1000 * 50;
    }

    alice.career.ad_income = alice.career.videos_count * 5000;
    alice.career.youtube_income = alice.career.subscribers_count / 1000 * 50;
    alice.career.instagram_income = alice.career.subscribers_count / 1000 * 30;

    if (month % 3 == 0) {
        alice.career.merch_income = 15000 + (rand() % 20000);
        printf("  Доход от мерча: +%lld руб\n", alice.career.merch_income);
    }

    RUB total_blogger = alice.career.blogger_income + alice.career.sponsorship_income +
        alice.career.ad_income + alice.career.youtube_income +
        alice.career.instagram_income + alice.career.merch_income;

    RUB tax = total_blogger * 0.13;
    alice.vtb.account_rub += (total_blogger - tax);
    alice.tax.income_tax += tax;

    printf("  Итого блогерский доход: %lld руб (налог %lld)\n", total_blogger, tax);

    Percent inflation = alice_inflation(year);
    if (month == 1) {
        alice.career.blogger_income += alice.career.blogger_income * (inflation / 100);
        alice.career.subscribers_count += alice.career.subscribers_count * 0.1;
        alice.career.videos_count += 36;
        printf("  Индексация дохода: +%.1f%%, подписчиков: %d\n", inflation, alice.career.subscribers_count);
    }
}

void alice_food_cost(const int month, const int year) {
    RUB food_total = alice.food.groceries + alice.food.restaurants +
        alice.food.delivery + alice.food.coffee + alice.food.sweets +
        alice.food.alcohol + alice.food.healthy_food + alice.food.fast_food;

    Percent inflation = alice_inflation(year);

    if (month == 1) {
        alice.food.groceries += alice.food.groceries * (inflation / 100 / 12);
        alice.food.restaurants += alice.food.restaurants * (inflation / 100 / 12);
        alice.food.delivery += alice.food.delivery * (inflation / 100 / 12);
        alice.food.coffee += alice.food.coffee * (inflation / 100 / 12);
        alice.food.sweets += alice.food.sweets * (inflation / 100 / 12);
        alice.food.alcohol += alice.food.alcohol * (inflation / 100 / 12);
        alice.food.healthy_food += alice.food.healthy_food * (inflation / 100 / 12);
        alice.food.fast_food += alice.food.fast_food * (inflation / 100 / 12);
    }

    if (month == 12) {
        food_total += 8000;
    }
    if (month == 2) {
        food_total += 3000;
    }
    if (month == 3) {
        food_total += 4000;
    }
    if (month == 11 && year == 2028) {
        food_total += 5000;
    }

    alice.vtb.account_rub -= food_total;
    alice.total_expenses_lifetime += food_total;
}

void alice_dog_cost(const int month, const int year) {
    if (!alice.dog.is_alive) return;

    RUB dog_total = alice.dog.food_cost + alice.dog.vet_cost + alice.dog.toys_cost +
        alice.dog.grooming_cost + alice.dog.insurance_cost +
        alice.dog.training_cost + alice.dog.walking_cost + alice.dog.medicine_cost;

    if (rand() % 100 < 8 && !alice.dog.is_sick) {
        alice.dog.is_sick = true;
        RUB vet_treatment = 8000 + (rand() % 12000);
        alice.dog.medicine_cost = vet_treatment;
        dog_total += vet_treatment;
        alice.dog.sickness_count++;
        alice.dog.health_level -= 20;
        printf("  СОБАКА ЗАБОЛЕЛА! Лечение: %lld руб\n", vet_treatment);

        if (alice.dog.sickness_count >= 3 && alice.dog.age_months > 120) {
            alice.dog.is_alive = false;
            printf("  СОБАКА УМЕРЛА ОТ БОЛЕЗНИ...\n");
            return;
        }
    }
    else if (alice.dog.is_sick) {
        alice.dog.is_sick = false;
        alice.dog.medicine_cost = 0;
        alice.dog.vet_visits++;
        alice.dog.health_level += 10;
        printf("  Собака выздоровела\n");
    }

    if (month == 5 && year == 2027 && alice.dog.is_alive) {
        RUB vaccination = 3500;
        dog_total += vaccination;
        alice.dog.is_vaccinated = true;
    }

    if (month % 2 == 0) {
        RUB grooming = alice.dog.grooming_cost;
        dog_total += grooming;
    }

    if (month % 3 == 0) {
        RUB toys = alice.dog.toys_cost;
        dog_total += toys;
    }

    Percent inflation = alice_inflation(year);
    if (month == 1) {
        alice.dog.food_cost += alice.dog.food_cost * (inflation / 100 / 12);
        alice.dog.grooming_cost += alice.dog.grooming_cost * (inflation / 100 / 12);
        alice.dog.walking_cost += alice.dog.walking_cost * (inflation / 100 / 12);
    }

    alice.vtb.account_rub -= dog_total;
    alice.dog.total_spent += dog_total;
    alice.dog.food_eaten += alice.dog.food_cost;
    alice.dog.age_months++;

    if (alice.travel.is_traveling) {
        alice.dog.happiness_level -= 5;
        printf("  Собака грустит без хозяина: счастье -5\n");
    }
    else {
        alice.dog.happiness_level += 2;
        if (alice.dog.happiness_level > 100) alice.dog.happiness_level = 100;
    }

    printf("  Расходы на собаку: %lld руб (счастье %d, здоровье %d)\n",
        dog_total, alice.dog.happiness_level, alice.dog.health_level);
}

void alice_apartment_cost(const int month, const int year) {
    if (!alice.apartment.rent.is_rented) return;

    RUB rent_total = alice.apartment.rent.monthly_rent +
        alice.apartment.rent.utilities +
        alice.apartment.rent.internet +
        alice.apartment.rent.cleaning_cost;

    Percent inflation = alice_inflation(year);

    if (month == 1 && year > 2026) {
        alice.apartment.rent.monthly_rent += alice.apartment.rent.monthly_rent * (inflation / 100);
        alice.apartment.rent.utilities += alice.apartment.rent.utilities * (inflation / 100 / 12);
        printf("  Индексация аренды: +%.1f%%\n", inflation);
    }

    alice.apartment.rent.total_paid += rent_total;

    if (month == alice.apartment.rent.contract_months) {
        alice.vtb.account_rub += alice.apartment.rent.deposit;
        alice.apartment.rent.contract_months += 12;
    }

    alice.vtb.account_rub -= rent_total;
    alice.total_expenses_lifetime += rent_total;
}

void alice_subscriptions_cost(const int month) {
    RUB subs_total = alice.subscriptions.total;

    alice.vtb.account_rub -= subs_total;
    alice.total_expenses_lifetime += subs_total;

    printf("  Подписки: %lld руб\n", subs_total);
}

void alice_clothing_cost(const int month, const int year) {
    RUB clothing_total = alice.clothing.total;

    if (month == 9) {
        alice.clothing.winter_clothes = 8000;
        clothing_total += alice.clothing.winter_clothes;
        printf("  Зимняя одежда: +8000 руб\n");
    }
    if (month == 4) {
        alice.clothing.summer_clothes = 6000;
        clothing_total += alice.clothing.summer_clothes;
        printf("  Летняя одежда: +6000 руб\n");
    }

    if (month % 6 == 0) {
        alice.clothing.sport_clothes = 4000;
        clothing_total += alice.clothing.sport_clothes;
        printf("  Спортивная одежда: +4000 руб\n");
    }

    Percent inflation = alice_inflation(year);
    if (month == 1) {
        alice.clothing.clothes += alice.clothing.clothes * (inflation / 100 / 12);
        alice.clothing.shoes += alice.clothing.shoes * (inflation / 100 / 12);
    }

    alice.vtb.account_rub -= clothing_total;
    alice.total_expenses_lifetime += clothing_total;

    alice.clothing.winter_clothes = 0;
    alice.clothing.summer_clothes = 0;
    alice.clothing.sport_clothes = 0;
}

void alice_education_cost(const int month, const int year) {
    RUB edu_total = alice.education.total;

    if (month == 1 && year == 2027) {
        alice.education.courses = 25000;
        edu_total += alice.education.courses;
    }

    if (month == 9 && year == 2028) {
        alice.education.language_courses = 30000;
        edu_total += alice.education.language_courses;
    }

    if (month % 4 == 0) {
        alice.education.conference = 15000;
        edu_total += alice.education.conference;
    }

    if (month % 2 == 0) {
        alice.education.books = 2000;
        edu_total += alice.education.books;
    }

    alice.vtb.account_rub -= edu_total;
    alice.total_expenses_lifetime += edu_total;

    printf("  Расходы на образование: %lld руб\n", edu_total);

    alice.education.courses = 0;
    alice.education.language_courses = 0;
    alice.education.conference = 0;
    alice.education.books = 0;
}

void alice_health_cost(const int month, const int year) {
    RUB health_total = alice.health.gym_cost + alice.health.vitamins_cost +
        alice.health.medical_insurance_cost + alice.health.medicine_cost +
        alice.health.doctor_cost;

    if (month == 6) {
        alice.health.dental_cost = 8000;
        health_total += alice.health.dental_cost;
    }

    if (month == 11) {
        alice.health.doctor_cost = 5000;
        health_total += alice.health.doctor_cost;
    }

    if (rand() % 100 < 5 && !alice.health.is_sick) {
        alice.health.is_sick = true;
        alice.health.sick_days = 3 + (rand() % 7);
        RUB treatment = 3000 + (rand() % 7000);
        alice.health.medicine_cost = treatment;
        health_total += treatment;
    }
    else if (alice.health.is_sick) {
        alice.health.sick_days--;
        if (alice.health.sick_days <= 0) {
            alice.health.is_sick = false;
            alice.health.medicine_cost = 0;
        }
    }

    Percent inflation = alice_inflation(year);
    if (month == 1) {
        alice.health.gym_cost += alice.health.gym_cost * (inflation / 100 / 12);
        alice.health.vitamins_cost += alice.health.vitamins_cost * (inflation / 100 / 12);
    }

    alice.vtb.account_rub -= health_total;
    alice.total_expenses_lifetime += health_total;

    printf("  Расходы на здоровье: %lld руб (спортзал %lld, витамины %lld, страховка %lld)\n",
        health_total, alice.health.gym_cost, alice.health.vitamins_cost,
        alice.health.medical_insurance_cost);

    alice.health.dental_cost = 0;
    alice.health.doctor_cost = 0;
}

void alice_hobby_cost(const int month, const int year) {
    RUB hobby_total = alice.hobby.total;

    if (month == 5) {
        alice.hobby.tennis = 5000;
        hobby_total += alice.hobby.tennis;
    }

    if (month == 11) {
        alice.hobby.skiing = 10000;
        hobby_total += alice.hobby.skiing;
    }

    if (year == 2027 && month == 3) {
        alice.hobby.photography = 30000;
        hobby_total += alice.hobby.photography;
    }

    Percent inflation = alice_inflation(year);
    if (month == 1) {
        alice.hobby.sports += alice.hobby.sports * (inflation / 100 / 12);
        alice.hobby.music += alice.hobby.music * (inflation / 100 / 12);
        alice.hobby.games += alice.hobby.games * (inflation / 100 / 12);
    }

    alice.vtb.account_rub -= hobby_total;
    alice.total_expenses_lifetime += hobby_total;

    printf("  Расходы на хобби: %lld руб\n", hobby_total);

    alice.hobby.tennis = 0;
    alice.hobby.skiing = 0;
    alice.hobby.photography = 0;
}
