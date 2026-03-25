#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

using Percent = float;
using RUB = long long int;
using USD = long long int;

struct Car {
    RUB value;
    RUB gas;
    RUB insurance;
    RUB maintenance;
    RUB winter_tires;
    RUB summer_tires;
    RUB tire_change;
    RUB car_wash;
    RUB parking;
    RUB fines;
    RUB diagnostics;
    RUB oil_change;
    RUB tax;
};

struct Subscriptions {
    RUB netflix;
    RUB spotify;
    RUB youtube_premium;
    RUB icloud;
    RUB dropbox;
    RUB adobe_cloud;
    RUB chatgpt_plus;
    RUB online_cinema;
    RUB fitness_app;
    RUB password_manager;
    RUB vpn_service;
    RUB alarm_clock_app;
    RUB forgotten_subscriptions;
    bool has_subscriptions;
};

struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
    RUB credit_card_debt;
    RUB credit_card_limit;
    RUB deposit_rub;
    RUB deposit_usd;
    float deposit_rate;
    RUB investment_bonds;
    RUB investment_stocks;
    RUB bank_commissions;
    RUB sms_banking_fee;
    RUB currency_exchange_loss;
    RUB atm_withdrawal_fee;
    RUB transfer_fees;
};

struct TransactionCosts {
    RUB delivery_returns;
    RUB online_shopping;
    RUB return_shipping;
    RUB failed_purchases;
    RUB late_fees;
    RUB fines_and_penalties;
    RUB forgotten_payments;
    RUB tax_penalties;
};

struct EmotionalShopping {
    RUB stress_purchases;
    RUB boredom_shopping;
    RUB mood_boosters;
    RUB unneeded_items;
    RUB impulse_buys;
    RUB comfort_shopping;
    RUB retail_therapy;
    RUB unused_items;
};

struct ConvenienceFees {
    RUB corner_store_markup;
    RUB food_delivery;
    RUB ready_meals;
    RUB premium_products;
    RUB lazy_tax;
    RUB express_delivery;
    RUB convenience_products;
    RUB time_savers;
};

struct ProxySpending {
    RUB children_toys_adult;
    RUB pet_luxury;
    RUB spouse_gifts_self;
    RUB hobby_for_child;
    RUB gadgets_for_family;
    RUB expensive_pet_items;
    RUB child_dreams;
    RUB pet_humanization;
};

struct SleepHealth {
    RUB orthopedic_mattress;
    RUB expensive_pillows;
    RUB bedding_sets;
    RUB weighted_blanket;
    RUB sleep_trackers;
    RUB blackout_curtains;
    RUB white_noise;
    RUB sleep_aids;
    RUB sad_lamps;
    RUB vitamin_d;
    RUB winter_sun_trips;
};

struct SocialCapital {
    RUB colleague_gifts;
    RUB teacher_gifts;
    RUB relative_gifts;
    RUB work_contributions;
    RUB friend_dinners;
    RUB social_obligations;
    RUB networking_events;
    RUB status_symbols;
};

struct IntangibleServices {
    RUB psychologist;
    RUB life_coach;
    RUB career_consultant;
    RUB astrologer;
    RUB tarot_reader;
    RUB personal_trainer;
    RUB nutritionist;
    RUB image_consultant;
};

struct SituationalPurchases {
    RUB corporate_outfit;
    RUB wedding_outfit;
    RUB special_equipment;
    RUB one_time_items;
    RUB event_clothing;
    RUB theme_party_gear;
    RUB team_building_gear;
};

struct PaidApps {
    RUB planner_app;
    RUB password_manager_app;
    RUB vpn_app;
    RUB sleep_app;
    RUB meditation_app;
    RUB fitness_app_paid;
    RUB language_learning;
    RUB productivity_tools;
};

struct LegalMistakes {
    RUB tax_unclaimed;
    RUB contract_violations;
    RUB late_tax_payment;
    RUB legal_ignorance;
    RUB document_errors;
    RUB missed_deadlines;
    RUB unnecessary_fees;
};

struct FriendSupport {
    RUB paying_for_friends;
    RUB group_taxi;
    RUB shared_housing;
    RUB friend_loans;
    RUB entertainment_for_all;
    RUB generous_treats;
    RUB unconscious_spending;
};

struct Flat {
    RUB housing_and_communal_servisec;
    RUB current_repairs;
    RUB household_chemicals;
    RUB general_household_needs;
    RUB checking_counters;
    RUB repair_of_large_household_appliances;
    RUB internet;
    RUB tv;
    RUB phone;
    RUB furniture_renewal;
    RUB curtains;
    RUB dishes;
    RUB cleaning_equipment;
    RUB air_conditioner_service;
    RUB water_filter;
    RUB insects_control;
    RUB new_lamps;
    RUB emergency_fund;
};

struct Storage {
    RUB seasonal_tires_storage;
    RUB bike_storage;
    RUB self_storage_rent;
    RUB old_items_storage;
    RUB warehouse_rent;
    bool has_storage;
};

struct Mortgage {
    RUB loan_amount;
    RUB monthly_payment;
    RUB down_payment;
    float interest_rate;
    RUB property_insurance;
    RUB life_insurance;
    RUB appraisal;
    RUB notary;
    RUB state_fee;
    RUB bank_commission;
    RUB early_repayment;
    RUB penalty;
    RUB renovation;
    RUB furniture;
};

struct Wedding {
    RUB restaurant;
    RUB dress_and_suit;
    RUB rings;
    RUB photographer;
    RUB videographer;
    RUB makeup_artist;
    RUB hairdresser;
    RUB bouquet;
    RUB boutonniere;
    RUB transport;
    RUB venue_decor;
    RUB invitations;
    RUB wedding_cake;
    RUB alcohol;
    RUB music;
    RUB host;
    RUB honeymoon;
    RUB other_expenses;
    bool happened;
};

struct Child {
    RUB initial_expenses;
    RUB monthly_food;
    RUB diapers;
    RUB clothes;
    RUB medicine;
    RUB toys;
    RUB kindergarten;
    RUB doctor_visits;
    RUB vitamins;
    RUB dentist;
    RUB child_birthday;
    RUB babysitter;
    RUB development;
    RUB stroller;
    RUB car_seat;
    RUB high_chair;
    RUB playpen;
    RUB baby_monitor;
    RUB breastfeeding;
    RUB hygiene;
    RUB swimming;
    RUB massage;
    bool born;
    int age_months;
};

struct Pet {
    RUB food;
    RUB treats;
    RUB veterinary;
    RUB vaccinations;
    RUB grooming;
    RUB toys_for_pet;
    RUB bedding;
    RUB bowl;
    RUB leash_and_collar;
    RUB carrier;
    RUB toilet_trainer;
    RUB filler;
    RUB claws_care;
    RUB pet_insurance;
    RUB pet_sitting;
    RUB training;
    RUB chip;
    RUB sterilization;
    bool have_pet;
};

struct Divorce {
    RUB lawyer_services;
    RUB court_fee;
    RUB property_division;
    RUB alimony;
    RUB appraiser_services;
    RUB notary_for_divorce;
    RUB moving_expenses;
    RUB separate_living;
    RUB new_furniture;
    RUB emotional_damage;
    RUB psychotherapy;
    RUB documents_reissue;
    RUB bank_accounts_division;
    RUB car_division;
    RUB debt_division;
    bool happened;
};

struct Job {
    RUB salary;
    RUB bonus;
    RUB thirteenth_salary;
    RUB sick_leave;
    RUB vacation_pay;
    RUB business_trip;
    RUB transportation;
    RUB lunch;
    RUB work_clothes;
    RUB training_courses;
    RUB professional_certificate;
    RUB literature;
    RUB software;
    RUB equipment;
    RUB internet_for_work;
    RUB phone_for_work;
    RUB workplace_rent;
    RUB taxes;
    RUB pension_contributions;
    RUB health_insurance;
    bool employed;
    bool looking_for_job;
};

struct FoodExpenses {
    RUB groceries;
    RUB meat;
    RUB vegetables;
    RUB dairy;
    RUB bread;
    RUB sweets;
    RUB beverages;
    RUB cafe;
    RUB fastfood;
    RUB coffee;
    RUB business_lunch;
    RUB delivery_food;
    RUB delivery_groceries;
    RUB guests;
    RUB holiday_extra;
};

struct HealthAddiction {
    RUB gym_membership;
    RUB personal_trainer;
    RUB group_classes;
    RUB swimming_pool;
    RUB massage_therapist;
    RUB osteopath;
    RUB sportswear;
    RUB sneakers;
    RUB fitness_tracker;
    RUB heart_rate_monitor;
    RUB yoga_mat;
    RUB gym_equipment_home;
    RUB protein;
    RUB bcaa;
    RUB creatine;
    RUB pre_workout;
    RUB vitamins_sports;
    RUB omega3;
    RUB collagen;
    RUB glutamine;
    RUB organic_vegetables;
    RUB organic_meat;
    RUB organic_chicken;
    RUB organic_eggs;
    RUB organic_fish;
    RUB organic_dairy;
    RUB superfoods;
    RUB healthy_snacks;
    RUB detox_water;
    RUB gluten_free;
    RUB lactose_free;
    RUB cryotherapy;
    RUB salt_cave;
    RUB hyperbaric_chamber;
    RUB iv_therapy;
    RUB detox_programs;
    RUB fasting;
    RUB food_scale;
    RUB blenders;
    RUB juicers;
    RUB food_containers;
    RUB meal_prep_services;
    RUB nutritionist;
    RUB food_analyzer;
    int addiction_level;
    bool orthorexia;
    bool gym_addict;
    bool body_dysmorphia;
    bool counting_calories;
    bool weighing_food;
    bool avoiding_social;
    bool problem_addict;
    RUB total_spent;
    RUB monthly_average;
    int years_pursuing;
    bool food_adjusted;
    bool eating_out_adjusted;
    bool social_adjusted;
};

struct Inheritance {
    RUB amount;
    int year_received;
    int month_received;
    bool received;
    bool from_grandmother;
    bool from_distant_relative;
    bool from_unexpected;
    RUB cash;
    RUB apartment_value;
    RUB car_value;
    RUB jewelry;
    RUB antiques;
    RUB tax_on_inheritance;
    RUB notary_costs;
    RUB lawyer_costs;
    RUB appraisal_costs;
    RUB debt_of_relative;
    bool was_expected;
    bool was_shock;
    bool caused_family_drama;
};

struct Person {
    Bank vtb;
    Subscriptions subs;
    TransactionCosts transactions;
    EmotionalShopping emotions;
    ConvenienceFees convenience;
    ProxySpending proxy;
    SleepHealth sleep;
    SocialCapital social;
    IntangibleServices intangible;
    SituationalPurchases situational;
    PaidApps paid_apps;
    LegalMistakes legal;
    FriendSupport friends;
    Storage storage;

    FoodExpenses alice_food;
    FoodExpenses husband_food;

    RUB salary;
    RUB husband_salary;

    Car car_alice;
    Car car_husband;

    Flat flat_1;
    Mortgage flat_2;

    Wedding wedding;
    Child child;

    Pet cat;
    Pet hamster;
    Pet dog;

    Divorce divorce;

    Job alice_job;
    Job husband_job;

    bool on_maternity_leave;
    bool married;
    RUB husband_alimony;
    RUB random_income;
    RUB random_expenses;
    RUB inflation_protection;
    RUB emergency_fund_personal;

    HealthAddiction health;
    Inheritance inheritance;
};

struct Person alice;

void alice_init()
{
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 500'000;
    alice.vtb.account_usd = 1'000;
    alice.vtb.credit_card_debt = 0;
    alice.vtb.credit_card_limit = 300'000;
    alice.vtb.deposit_rub = 200'000;
    alice.vtb.deposit_usd = 500;
    alice.vtb.deposit_rate = 8.5;
    alice.vtb.investment_bonds = 100'000;
    alice.vtb.investment_stocks = 50'000;
    alice.vtb.bank_commissions = 300;
    alice.vtb.sms_banking_fee = 99;
    alice.vtb.currency_exchange_loss = 200;
    alice.vtb.atm_withdrawal_fee = 150;
    alice.vtb.transfer_fees = 100;

    alice.health.gym_membership = 5'000;
    alice.health.personal_trainer = 8'000;
    alice.health.group_classes = 3'000;
    alice.health.swimming_pool = 2'500;
    alice.health.massage_therapist = 3'500;
    alice.health.osteopath = 4'000;
    alice.health.sportswear = 5'000;
    alice.health.sneakers = 8'000;
    alice.health.fitness_tracker = 25'000;
    alice.health.heart_rate_monitor = 5'000;
    alice.health.yoga_mat = 3'000;
    alice.health.gym_equipment_home = 10'000;
    alice.health.protein = 3'000;
    alice.health.bcaa = 1'500;
    alice.health.creatine = 1'000;
    alice.health.pre_workout = 1'500;
    alice.health.vitamins_sports = 2'000;
    alice.health.omega3 = 1'500;
    alice.health.collagen = 2'000;
    alice.health.glutamine = 1'000;
    alice.health.organic_vegetables = 4'000;
    alice.health.organic_meat = 5'000;
    alice.health.organic_chicken = 3'000;
    alice.health.organic_eggs = 1'000;
    alice.health.organic_fish = 4'000;
    alice.health.organic_dairy = 2'000;
    alice.health.superfoods = 2'500;
    alice.health.healthy_snacks = 1'500;
    alice.health.detox_water = 1'000;
    alice.health.gluten_free = 1'500;
    alice.health.lactose_free = 1'000;
    alice.health.cryotherapy = 2'500;
    alice.health.salt_cave = 1'000;
    alice.health.hyperbaric_chamber = 5'000;
    alice.health.iv_therapy = 7'000;
    alice.health.detox_programs = 15'000;
    alice.health.fasting = 10'000;
    alice.health.addiction_level = 0;
    alice.health.orthorexia = false;
    alice.health.gym_addict = false;
    alice.health.body_dysmorphia = false;
    alice.health.counting_calories = false;
    alice.health.weighing_food = false;
    alice.health.avoiding_social = false;
    alice.health.total_spent = 0;
    alice.health.monthly_average = 0;
    alice.health.years_pursuing = 0;
    alice.health.problem_addict = false;
    alice.health.food_scale = 3'000;
    alice.health.blenders = 20'000;
    alice.health.juicers = 15'000;
    alice.health.food_containers = 2'000;
    alice.health.meal_prep_services = 10'000;
    alice.health.nutritionist = 4'000;
    alice.health.food_analyzer = 8'000;
    alice.health.food_adjusted = false;
    alice.health.eating_out_adjusted = false;
    alice.health.social_adjusted = false;

    alice.subs.netflix = 999;
    alice.subs.spotify = 299;
    alice.subs.youtube_premium = 399;
    alice.subs.icloud = 149;
    alice.subs.dropbox = 699;
    alice.subs.adobe_cloud = 1'899;
    alice.subs.chatgpt_plus = 999;
    alice.subs.online_cinema = 599;
    alice.subs.fitness_app = 499;
    alice.subs.password_manager = 299;
    alice.subs.vpn_service = 399;
    alice.subs.alarm_clock_app = 99;
    alice.subs.forgotten_subscriptions = 500;
    alice.subs.has_subscriptions = true;

    alice.transactions.delivery_returns = 500;
    alice.transactions.online_shopping = 2'000;
    alice.transactions.return_shipping = 300;
    alice.transactions.failed_purchases = 1'000;
    alice.transactions.late_fees = 300;
    alice.transactions.fines_and_penalties = 500;
    alice.transactions.forgotten_payments = 400;
    alice.transactions.tax_penalties = 1'000;

    alice.emotions.stress_purchases = 2'000;
    alice.emotions.boredom_shopping = 1'500;
    alice.emotions.mood_boosters = 1'000;
    alice.emotions.unneeded_items = 1'200;
    alice.emotions.impulse_buys = 1'800;
    alice.emotions.comfort_shopping = 1'300;
    alice.emotions.retail_therapy = 1'600;
    alice.emotions.unused_items = 900;

    alice.convenience.corner_store_markup = 1'000;
    alice.convenience.food_delivery = 2'000;
    alice.convenience.ready_meals = 3'000;
    alice.convenience.premium_products = 1'500;
    alice.convenience.lazy_tax = 1'200;
    alice.convenience.express_delivery = 500;
    alice.convenience.convenience_products = 800;
    alice.convenience.time_savers = 600;

    alice.proxy.children_toys_adult = 2'000;
    alice.proxy.pet_luxury = 1'500;
    alice.proxy.spouse_gifts_self = 3'000;
    alice.proxy.hobby_for_child = 2'500;
    alice.proxy.gadgets_for_family = 4'000;
    alice.proxy.expensive_pet_items = 1'200;
    alice.proxy.child_dreams = 1'800;
    alice.proxy.pet_humanization = 900;

    alice.sleep.orthopedic_mattress = 15'000;
    alice.sleep.expensive_pillows = 3'000;
    alice.sleep.bedding_sets = 2'000;
    alice.sleep.weighted_blanket = 4'000;
    alice.sleep.sleep_trackers = 2'500;
    alice.sleep.blackout_curtains = 3'000;
    alice.sleep.white_noise = 1'500;
    alice.sleep.sleep_aids = 1'000;
    alice.sleep.sad_lamps = 5'000;
    alice.sleep.vitamin_d = 800;
    alice.sleep.winter_sun_trips = 30'000;

    alice.social.colleague_gifts = 1'000;
    alice.social.teacher_gifts = 1'500;
    alice.social.relative_gifts = 2'000;
    alice.social.work_contributions = 800;
    alice.social.friend_dinners = 2'500;
    alice.social.social_obligations = 1'200;
    alice.social.networking_events = 3'000;
    alice.social.status_symbols = 5'000;

    alice.intangible.psychologist = 4'000;
    alice.intangible.life_coach = 5'000;
    alice.intangible.career_consultant = 3'500;
    alice.intangible.astrologer = 2'000;
    alice.intangible.tarot_reader = 1'800;
    alice.intangible.personal_trainer = 3'000;
    alice.intangible.nutritionist = 2'500;
    alice.intangible.image_consultant = 4'000;

    alice.situational.corporate_outfit = 5'000;
    alice.situational.wedding_outfit = 8'000;
    alice.situational.special_equipment = 3'000;
    alice.situational.one_time_items = 2'000;
    alice.situational.event_clothing = 4'000;
    alice.situational.theme_party_gear = 2'500;
    alice.situational.team_building_gear = 1'500;

    alice.paid_apps.planner_app = 500;
    alice.paid_apps.password_manager_app = 300;
    alice.paid_apps.vpn_app = 400;
    alice.paid_apps.sleep_app = 250;
    alice.paid_apps.meditation_app = 350;
    alice.paid_apps.fitness_app_paid = 450;
    alice.paid_apps.language_learning = 600;
    alice.paid_apps.productivity_tools = 550;

    alice.legal.tax_unclaimed = 5'000;
    alice.legal.contract_violations = 2'000;
    alice.legal.late_tax_payment = 1'000;
    alice.legal.legal_ignorance = 3'000;
    alice.legal.document_errors = 1'500;
    alice.legal.missed_deadlines = 800;
    alice.legal.unnecessary_fees = 600;

    alice.friends.paying_for_friends = 2'000;
    alice.friends.group_taxi = 800;
    alice.friends.shared_housing = 5'000;
    alice.friends.friend_loans = 1'000;
    alice.friends.entertainment_for_all = 2'500;
    alice.friends.generous_treats = 1'500;
    alice.friends.unconscious_spending = 1'200;

    alice.storage.seasonal_tires_storage = 3'000;
    alice.storage.bike_storage = 1'500;
    alice.storage.self_storage_rent = 5'000;
    alice.storage.old_items_storage = 2'000;
    alice.storage.warehouse_rent = 2'500;
    alice.storage.has_storage = false;

    alice.salary = 500'000;
    alice.husband_salary = 300'000;

    alice.alice_food.groceries = 3'000;
    alice.alice_food.meat = 4'000;
    alice.alice_food.vegetables = 3'000;
    alice.alice_food.dairy = 2'000;
    alice.alice_food.bread = 500;
    alice.alice_food.sweets = 1'000;
    alice.alice_food.beverages = 1'000;
    alice.alice_food.cafe = 2'000;
    alice.alice_food.fastfood = 1'000;
    alice.alice_food.coffee = 500;
    alice.alice_food.business_lunch = 1'500;
    alice.alice_food.delivery_food = 2'000;
    alice.alice_food.delivery_groceries = 500;
    alice.alice_food.guests = 1'000;
    alice.alice_food.holiday_extra = 3'000;

    alice.husband_food.groceries = 1'500;
    alice.husband_food.meat = 5'000;
    alice.husband_food.vegetables = 2'000;
    alice.husband_food.dairy = 1'500;
    alice.husband_food.bread = 500;
    alice.husband_food.sweets = 1'500;
    alice.husband_food.beverages = 1'000;
    alice.husband_food.cafe = 3'000;
    alice.husband_food.fastfood = 1'500;
    alice.husband_food.coffee = 800;
    alice.husband_food.business_lunch = 2'000;
    alice.husband_food.delivery_food = 1'500;
    alice.husband_food.delivery_groceries = 300;
    alice.husband_food.guests = 1'000;
    alice.husband_food.holiday_extra = 2'000;

    alice.car_alice.value = 800'000;
    alice.car_alice.gas = 5'000;
    alice.car_alice.insurance = 40'000;
    alice.car_alice.maintenance = 5'000;
    alice.car_alice.winter_tires = 20'000;
    alice.car_alice.summer_tires = 20'000;
    alice.car_alice.tire_change = 3'000;
    alice.car_alice.car_wash = 1'500;
    alice.car_alice.parking = 2'000;
    alice.car_alice.fines = 500;
    alice.car_alice.diagnostics = 3'000;
    alice.car_alice.oil_change = 3'000;
    alice.car_alice.tax = 5'000;

    alice.car_husband.value = 1'200'000;
    alice.car_husband.gas = 7'000;
    alice.car_husband.insurance = 50'000;
    alice.car_husband.maintenance = 6'000;
    alice.car_husband.winter_tires = 25'000;
    alice.car_husband.summer_tires = 25'000;
    alice.car_husband.tire_change = 3'000;
    alice.car_husband.car_wash = 1'500;
    alice.car_husband.parking = 3'000;
    alice.car_husband.fines = 500;
    alice.car_husband.diagnostics = 3'500;
    alice.car_husband.oil_change = 3'500;
    alice.car_husband.tax = 7'000;

    alice.flat_1.housing_and_communal_servisec = 6'000;
    alice.flat_1.current_repairs = 1'000;
    alice.flat_1.household_chemicals = 1'000;
    alice.flat_1.general_household_needs = 1'500;
    alice.flat_1.checking_counters = 700;
    alice.flat_1.repair_of_large_household_appliances = 3'000;
    alice.flat_1.internet = 600;
    alice.flat_1.tv = 0;
    alice.flat_1.phone = 300;
    alice.flat_1.furniture_renewal = 2'000;
    alice.flat_1.curtains = 500;
    alice.flat_1.dishes = 500;
    alice.flat_1.cleaning_equipment = 500;
    alice.flat_1.air_conditioner_service = 0;
    alice.flat_1.water_filter = 500;
    alice.flat_1.insects_control = 300;
    alice.flat_1.new_lamps = 200;
    alice.flat_1.emergency_fund = 1'000;

    alice.flat_2.loan_amount = 3'000'000;
    alice.flat_2.monthly_payment = 35'000;
    alice.flat_2.down_payment = 600'000;
    alice.flat_2.interest_rate = 9.5;
    alice.flat_2.property_insurance = 10'000;
    alice.flat_2.life_insurance = 3'000;
    alice.flat_2.appraisal = 5'000;
    alice.flat_2.notary = 7'000;
    alice.flat_2.state_fee = 2'000;
    alice.flat_2.bank_commission = 15'000;
    alice.flat_2.early_repayment = 0;
    alice.flat_2.penalty = 0;
    alice.flat_2.renovation = 200'000;
    alice.flat_2.furniture = 300'000;

    alice.wedding.restaurant = 150'000;
    alice.wedding.dress_and_suit = 80'000;
    alice.wedding.rings = 50'000;
    alice.wedding.photographer = 40'000;
    alice.wedding.videographer = 30'000;
    alice.wedding.makeup_artist = 8'000;
    alice.wedding.hairdresser = 5'000;
    alice.wedding.bouquet = 5'000;
    alice.wedding.boutonniere = 1'000;
    alice.wedding.transport = 15'000;
    alice.wedding.venue_decor = 25'000;
    alice.wedding.invitations = 5'000;
    alice.wedding.wedding_cake = 8'000;
    alice.wedding.alcohol = 20'000;
    alice.wedding.music = 15'000;
    alice.wedding.host = 20'000;
    alice.wedding.honeymoon = 100'000;
    alice.wedding.other_expenses = 30'000;
    alice.wedding.happened = false;

    alice.child.initial_expenses = 100'000;
    alice.child.monthly_food = 3'000;
    alice.child.diapers = 2'500;
    alice.child.clothes = 3'000;
    alice.child.medicine = 1'000;
    alice.child.toys = 1'500;
    alice.child.kindergarten = 15'000;
    alice.child.doctor_visits = 2'000;
    alice.child.vitamins = 800;
    alice.child.dentist = 1'500;
    alice.child.child_birthday = 5'000;
    alice.child.babysitter = 10'000;
    alice.child.development = 2'000;
    alice.child.stroller = 15'000;
    alice.child.car_seat = 8'000;
    alice.child.high_chair = 3'000;
    alice.child.playpen = 4'000;
    alice.child.baby_monitor = 3'000;
    alice.child.breastfeeding = 3'000;
    alice.child.hygiene = 1'500;
    alice.child.swimming = 2'000;
    alice.child.massage = 2'000;
    alice.child.born = false;
    alice.child.age_months = 0;

    alice.cat.food = 1'500;
    alice.cat.treats = 300;
    alice.cat.veterinary = 500;
    alice.cat.vaccinations = 1'500;
    alice.cat.grooming = 0;
    alice.cat.toys_for_pet = 300;
    alice.cat.bedding = 500;
    alice.cat.bowl = 200;
    alice.cat.carrier = 1'000;
    alice.cat.toilet_trainer = 500;
    alice.cat.filler = 800;
    alice.cat.claws_care = 300;
    alice.cat.pet_insurance = 0;
    alice.cat.pet_sitting = 300;
    alice.cat.training = 0;
    alice.cat.chip = 1'000;
    alice.cat.sterilization = 4'000;
    alice.cat.have_pet = false;

    alice.hamster.food = 200;
    alice.hamster.treats = 50;
    alice.hamster.veterinary = 200;
    alice.hamster.vaccinations = 0;
    alice.hamster.grooming = 0;
    alice.hamster.toys_for_pet = 100;
    alice.hamster.bedding = 200;
    alice.hamster.bowl = 100;
    alice.hamster.carrier = 300;
    alice.hamster.toilet_trainer = 200;
    alice.hamster.filler = 200;
    alice.hamster.pet_insurance = 0;
    alice.hamster.pet_sitting = 50;
    alice.hamster.training = 0;
    alice.hamster.chip = 0;
    alice.hamster.sterilization = 0;
    alice.hamster.have_pet = false;

    alice.dog.food = 2'500;
    alice.dog.treats = 500;
    alice.dog.veterinary = 700;
    alice.dog.vaccinations = 2'000;
    alice.dog.grooming = 1'000;
    alice.dog.toys_for_pet = 500;
    alice.dog.bedding = 700;
    alice.dog.bowl = 300;
    alice.dog.leash_and_collar = 500;
    alice.dog.carrier = 1'500;
    alice.dog.toilet_trainer = 300;
    alice.dog.filler = 0;
    alice.dog.claws_care = 300;
    alice.dog.pet_insurance = 0;
    alice.dog.pet_sitting = 500;
    alice.dog.training = 1'500;
    alice.dog.chip = 1'000;
    alice.dog.sterilization = 5'000;
    alice.dog.have_pet = false;

    alice.divorce.lawyer_services = 50'000;
    alice.divorce.court_fee = 30'000;
    alice.divorce.property_division = 500'000;
    alice.divorce.alimony = 20'000;
    alice.divorce.appraiser_services = 20'000;
    alice.divorce.notary_for_divorce = 10'000;
    alice.divorce.moving_expenses = 50'000;
    alice.divorce.separate_living = 30'000;
    alice.divorce.new_furniture = 100'000;
    alice.divorce.emotional_damage = 30'000;
    alice.divorce.psychotherapy = 5'000;
    alice.divorce.documents_reissue = 10'000;
    alice.divorce.bank_accounts_division = 5'000;
    alice.divorce.car_division = 300'000;
    alice.divorce.debt_division = 200'000;
    alice.divorce.happened = false;

    alice.alice_job.salary = 70'000;
    alice.alice_job.bonus = 10'000;
    alice.alice_job.thirteenth_salary = 70'000;
    alice.alice_job.sick_leave = 5'000;
    alice.alice_job.vacation_pay = 7'000;
    alice.alice_job.business_trip = 10'000;
    alice.alice_job.transportation = 1'000;
    alice.alice_job.lunch = 2'000;
    alice.alice_job.work_clothes = 2'000;
    alice.alice_job.training_courses = 5'000;
    alice.alice_job.professional_certificate = 3'000;
    alice.alice_job.literature = 1'000;
    alice.alice_job.software = 1'000;
    alice.alice_job.equipment = 10'000;
    alice.alice_job.internet_for_work = 500;
    alice.alice_job.phone_for_work = 500;
    alice.alice_job.workplace_rent = 0;
    alice.alice_job.taxes = 9'100;
    alice.alice_job.pension_contributions = 15'400;
    alice.alice_job.health_insurance = 3'000;
    alice.alice_job.employed = true;
    alice.alice_job.looking_for_job = false;

    alice.husband_job.salary = 90'000;
    alice.husband_job.bonus = 15'000;
    alice.husband_job.thirteenth_salary = 90'000;
    alice.husband_job.sick_leave = 6'000;
    alice.husband_job.vacation_pay = 9'000;
    alice.husband_job.business_trip = 15'000;
    alice.husband_job.transportation = 1'500;
    alice.husband_job.lunch = 3'000;
    alice.husband_job.work_clothes = 3'000;
    alice.husband_job.training_courses = 7'000;
    alice.husband_job.professional_certificate = 4'000;
    alice.husband_job.literature = 1'500;
    alice.husband_job.software = 1'500;
    alice.husband_job.equipment = 15'000;
    alice.husband_job.internet_for_work = 500;
    alice.husband_job.phone_for_work = 500;
    alice.husband_job.workplace_rent = 0;
    alice.husband_job.taxes = 11'700;
    alice.husband_job.pension_contributions = 19'800;
    alice.husband_job.health_insurance = 4'000;
    alice.husband_job.employed = true;
    alice.husband_job.looking_for_job = false;

    alice.on_maternity_leave = false;
    alice.married = false;
    alice.husband_alimony = 0;
    alice.random_income = 0;
    alice.random_expenses = 0;
    alice.inflation_protection = 0;
    alice.emergency_fund_personal = 30'000;

    alice.inheritance.amount = 0;
    alice.inheritance.year_received = 0;
    alice.inheritance.month_received = 0;
    alice.inheritance.received = false;
    alice.inheritance.from_grandmother = false;
    alice.inheritance.from_distant_relative = false;
    alice.inheritance.from_unexpected = false;
    alice.inheritance.cash = 0;
    alice.inheritance.apartment_value = 0;
    alice.inheritance.car_value = 0;
    alice.inheritance.jewelry = 0;
    alice.inheritance.antiques = 0;
    alice.inheritance.tax_on_inheritance = 0;
    alice.inheritance.notary_costs = 0;
    alice.inheritance.lawyer_costs = 0;
    alice.inheritance.appraisal_costs = 0;
    alice.inheritance.debt_of_relative = 0;
    alice.inheritance.was_expected = false;
    alice.inheritance.was_shock = false;
    alice.inheritance.caused_family_drama = false;
}

float get_inflation_rate(int year, const char* category)
{
    switch (year)
    {
    case 2026: return 12.5;
    case 2027: return 14.0;
    case 2028: return 13.0;
    case 2029: return 11.5;
    default: return 10.0;
    }
}

void alice_food(const int month, const int year)
{
    if (month == 12) {
        alice.alice_food.holiday_extra = alice.alice_food.holiday_extra + 3'000;
        alice.husband_food.holiday_extra = alice.husband_food.holiday_extra + 2'000;
        alice.vtb.account_rub = alice.vtb.account_rub - 5'000;
    }

    float inflation = get_inflation_rate(year, "food");
    float monthly_inflation = inflation / 100 / 12;

    RUB alice_fields[15] = {
        alice.alice_food.groceries,
        alice.alice_food.meat,
        alice.alice_food.vegetables,
        alice.alice_food.dairy,
        alice.alice_food.bread,
        alice.alice_food.sweets,
        alice.alice_food.beverages,
        alice.alice_food.cafe,
        alice.alice_food.fastfood,
        alice.alice_food.coffee,
        alice.alice_food.business_lunch,
        alice.alice_food.delivery_food,
        alice.alice_food.delivery_groceries,
        alice.alice_food.guests,
        alice.alice_food.holiday_extra
    };

    for (int i = 0; i < 15; i++) {
        alice_fields[i] = alice_fields[i] + static_cast<RUB>(alice_fields[i] * monthly_inflation);
    }

    RUB total = 0;
    for (int i = 0; i < 15; i++) {
        total = total + alice_fields[i];
    }

    alice.alice_food.groceries = alice_fields[0];
    alice.alice_food.meat = alice_fields[1];
    alice.alice_food.vegetables = alice_fields[2];
    alice.alice_food.dairy = alice_fields[3];
    alice.alice_food.bread = alice_fields[4];
    alice.alice_food.sweets = alice_fields[5];
    alice.alice_food.beverages = alice_fields[6];
    alice.alice_food.cafe = alice_fields[7];
    alice.alice_food.fastfood = alice_fields[8];
    alice.alice_food.coffee = alice_fields[9];
    alice.alice_food.business_lunch = alice_fields[10];
    alice.alice_food.delivery_food = alice_fields[11];
    alice.alice_food.delivery_groceries = alice_fields[12];
    alice.alice_food.guests = alice_fields[13];
    alice.alice_food.holiday_extra = alice_fields[14];

    if (alice.married == true) {
        RUB husband_fields[15] = {
            alice.husband_food.groceries,
            alice.husband_food.meat,
            alice.husband_food.vegetables,
            alice.husband_food.dairy,
            alice.husband_food.bread,
            alice.husband_food.sweets,
            alice.husband_food.beverages,
            alice.husband_food.cafe,
            alice.husband_food.fastfood,
            alice.husband_food.coffee,
            alice.husband_food.business_lunch,
            alice.husband_food.delivery_food,
            alice.husband_food.delivery_groceries,
            alice.husband_food.guests,
            alice.husband_food.holiday_extra
        };

        for (int i = 0; i < 15; i++) {
            husband_fields[i] = husband_fields[i] + static_cast<RUB>(husband_fields[i] * monthly_inflation);
            total = total + husband_fields[i];
        }

        alice.husband_food.groceries = husband_fields[0];
        alice.husband_food.meat = husband_fields[1];
        alice.husband_food.vegetables = husband_fields[2];
        alice.husband_food.dairy = husband_fields[3];
        alice.husband_food.bread = husband_fields[4];
        alice.husband_food.sweets = husband_fields[5];
        alice.husband_food.beverages = husband_fields[6];
        alice.husband_food.cafe = husband_fields[7];
        alice.husband_food.fastfood = husband_fields[8];
        alice.husband_food.coffee = husband_fields[9];
        alice.husband_food.business_lunch = husband_fields[10];
        alice.husband_food.delivery_food = husband_fields[11];
        alice.husband_food.delivery_groceries = husband_fields[12];
        alice.husband_food.guests = husband_fields[13];
        alice.husband_food.holiday_extra = husband_fields[14];
    }

    if (alice.vtb.account_rub >= total) {
        alice.vtb.account_rub = alice.vtb.account_rub - total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_flat_1(const int month, const int year)
{
    float inflation = get_inflation_rate(year, "housing");
    alice.flat_1.housing_and_communal_servisec = alice.flat_1.housing_and_communal_servisec + static_cast<RUB>(alice.flat_1.housing_and_communal_servisec * (inflation / 100 / 12));

    RUB total = alice.flat_1.housing_and_communal_servisec + alice.flat_1.current_repairs +
        alice.flat_1.household_chemicals + alice.flat_1.general_household_needs +
        alice.flat_1.internet + alice.flat_1.phone + alice.flat_1.cleaning_equipment +
        alice.flat_1.emergency_fund;

    if ((year % 2) == 0) {
        total = total + alice.flat_1.checking_counters;
        alice.flat_1.general_household_needs = alice.flat_1.general_household_needs + 500;
    }
    else {
        alice.flat_1.general_household_needs = alice.flat_1.general_household_needs + 300;
    }

    if ((month % 5) == 0) {
        total = total + alice.flat_1.repair_of_large_household_appliances;
    }

    if ((month % 3) == 0) {
        total = total + alice.flat_1.water_filter;
    }

    if (alice.vtb.account_rub >= total) {
        alice.vtb.account_rub = alice.vtb.account_rub - total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_salary(const int month, const int year)
{
    if (month == 1 && year > 2026) {
        if (alice.alice_job.employed == true) {
            alice.salary = static_cast<RUB>(alice.salary * 1.07);
            alice.alice_job.salary = alice.salary;
        }

        if (alice.husband_job.employed == true && alice.married == true) {
            alice.husband_salary = static_cast<RUB>(alice.husband_salary * 1.08);
            alice.husband_job.salary = alice.husband_salary;
        }
    }

    if (year == 2028 && month == 3) {
        alice.on_maternity_leave = true;
    }
    if (year == 2029 && month == 3) {
        alice.on_maternity_leave = false;
    }

    RUB current_salary = 0;

    if (alice.alice_job.employed == true) {
        current_salary = alice.salary;
        if (alice.on_maternity_leave == true) {
            current_salary = static_cast<RUB>(current_salary * 0.4);
        }
        if (month == 12) {
            current_salary = current_salary + alice.alice_job.bonus;
        }
        if (month == 1) {
            current_salary = current_salary + alice.alice_job.thirteenth_salary;
        }
    }

    alice.vtb.account_rub = alice.vtb.account_rub + current_salary;

    if (alice.married == true && alice.husband_job.employed == true) {
        RUB husband_current = alice.husband_salary;
        if (month == 12) {
            husband_current = husband_current + alice.husband_job.bonus;
        }
        if (month == 1) {
            husband_current = husband_current + alice.husband_job.thirteenth_salary;
        }
        alice.vtb.account_rub = alice.vtb.account_rub + husband_current;
    }

    if (alice.divorce.happened == true && alice.child.born == true) {
        alice.vtb.account_rub = alice.vtb.account_rub + alice.divorce.alimony;
    }
}

void alice_car(Car& car, const int month, const int year)
{
    RUB total = car.gas + car.car_wash + car.parking;

    if (month == 10) {
        total = total + car.winter_tires + car.tire_change;
    }
    if (month == 4) {
        total = total + car.summer_tires + car.tire_change;
    }

    if (month == 1) {
        total = total + car.insurance + car.tax;
    }

    if ((month % 3) == 0) {
        total = total + car.maintenance + car.oil_change;
    }

    if ((month % 6) == 0) {
        total = total + car.diagnostics;
    }

    if (alice.vtb.account_rub >= total) {
        alice.vtb.account_rub = alice.vtb.account_rub - total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_bank_fees(const int month, const int year)
{
    RUB total = alice.vtb.sms_banking_fee;

    if ((rand() % 100) < 30) {
        total = total + alice.vtb.transfer_fees;
    }

    if (alice.vtb.account_usd > 0 && (month % 3) == 0) {
        alice.vtb.currency_exchange_loss = static_cast<RUB>(alice.vtb.account_usd * 0.01 * alice.vtb.rate_usd_rub);
        total = total + alice.vtb.currency_exchange_loss;
    }

    if ((rand() % 100) < 20) {
        total = total + alice.vtb.atm_withdrawal_fee;
    }

    if (alice.vtb.account_rub >= total) {
        alice.vtb.account_rub = alice.vtb.account_rub - total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_subscriptions(const int month, const int year)
{
    if (alice.subs.has_subscriptions == false) {
        return;
    }

    RUB total_subs = alice.subs.netflix + alice.subs.spotify + alice.subs.youtube_premium +
        alice.subs.icloud + alice.subs.dropbox + alice.subs.adobe_cloud +
        alice.subs.chatgpt_plus + alice.subs.online_cinema + alice.subs.fitness_app +
        alice.subs.password_manager + alice.subs.vpn_service + alice.subs.alarm_clock_app;

    if ((month % 3) == 0) {
        total_subs = total_subs + alice.subs.forgotten_subscriptions;
    }

    if (alice.vtb.account_rub >= total_subs) {
        alice.vtb.account_rub = alice.vtb.account_rub - total_subs;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_bank(const int month, const int year)
{
    if (month == 1) {
        RUB deposit_interest_rub = static_cast<RUB>(alice.vtb.deposit_rub * (alice.vtb.deposit_rate / 100.0));
        alice.vtb.deposit_rub = alice.vtb.deposit_rub + deposit_interest_rub;

        RUB deposit_interest_usd = static_cast<RUB>(alice.vtb.deposit_usd * 3.0 / 100.0);
        alice.vtb.deposit_usd = alice.vtb.deposit_usd + deposit_interest_usd;
    }

    if (month == 12) {
        RUB dividends = static_cast<RUB>(alice.vtb.investment_stocks * 0.05);
        alice.vtb.account_rub = alice.vtb.account_rub + dividends;
    }

    if (month == 6 || month == 12) {
        RUB coupons = static_cast<RUB>(alice.vtb.investment_bonds * 0.04);
        alice.vtb.account_rub = alice.vtb.account_rub + coupons;
    }

    if (alice.vtb.account_rub > 200'000) {
        RUB transfer = (alice.vtb.account_rub - 100'000) / 2;
        alice.vtb.deposit_rub = alice.vtb.deposit_rub + transfer;
        alice.vtb.account_rub = alice.vtb.account_rub - transfer;
    }
}

void alice_mortgage(const int month, const int year)
{
    static bool mortgage_taken = false;

    if (mortgage_taken == false && alice.married == true && year == 2027 && month == 7) {
        RUB total = alice.flat_2.down_payment + alice.flat_2.appraisal +
            alice.flat_2.notary + alice.flat_2.state_fee + alice.flat_2.bank_commission;

        if (alice.vtb.account_rub >= total) {
            alice.vtb.account_rub = alice.vtb.account_rub - total;
            mortgage_taken = true;
        }
    }

    if (mortgage_taken == true) {
        RUB interest = static_cast<RUB>(alice.flat_2.loan_amount * (alice.flat_2.interest_rate / 100.0 / 12.0));
        RUB principal_payment = alice.flat_2.monthly_payment - interest;

        if (principal_payment > alice.flat_2.loan_amount) {
            principal_payment = alice.flat_2.loan_amount;
        }

        RUB total_payment = alice.flat_2.monthly_payment;

        if (alice.flat_2.loan_amount > 0) {
            alice.flat_2.loan_amount = alice.flat_2.loan_amount - principal_payment;
            if (alice.flat_2.loan_amount < 0) {
                alice.flat_2.loan_amount = 0;
            }

            if (alice.vtb.account_rub >= total_payment) {
                alice.vtb.account_rub = alice.vtb.account_rub - total_payment;
            }
            else {
                alice.vtb.account_rub = 0;
            }
        }

        if (month == 7) {
            RUB insurance_total = alice.flat_2.property_insurance + alice.flat_2.life_insurance;
            if (alice.vtb.account_rub >= insurance_total) {
                alice.vtb.account_rub = alice.vtb.account_rub - insurance_total;
            }
            else {
                alice.vtb.account_rub = 0;
            }
        }

        int renovation_months[] = { 8, 9, 10, 11, 12 };
        for (int i = 0; i < 5; i++) {
            if (year == 2027 && month == renovation_months[i]) {
                RUB renovation_payment = alice.flat_2.renovation / 6;
                if (alice.vtb.account_rub >= renovation_payment) {
                    alice.vtb.account_rub = alice.vtb.account_rub - renovation_payment;
                }
                else {
                    alice.vtb.account_rub = 0;
                }
            }
        }
        if (year == 2028 && month == 1) {
            RUB renovation_payment = alice.flat_2.renovation / 6;
            if (alice.vtb.account_rub >= renovation_payment) {
                alice.vtb.account_rub = alice.vtb.account_rub - renovation_payment;
            }
            else {
                alice.vtb.account_rub = 0;
            }
        }

        if ((year == 2027 && month == 12) || (year == 2028 && month == 1)) {
            RUB furniture_payment = alice.flat_2.furniture / 2;
            if (alice.vtb.account_rub >= furniture_payment) {
                alice.vtb.account_rub = alice.vtb.account_rub - furniture_payment;
            }
            else {
                alice.vtb.account_rub = 0;
            }
        }
    }
}

void alice_wedding(const int month, const int year)
{
    if (alice.wedding.happened == false && year == 2026 && month == 8) {
        RUB total = alice.wedding.restaurant + alice.wedding.venue_decor + alice.wedding.wedding_cake +
            alice.wedding.alcohol + alice.wedding.dress_and_suit + alice.wedding.makeup_artist +
            alice.wedding.hairdresser + alice.wedding.bouquet + alice.wedding.boutonniere +
            alice.wedding.rings + alice.wedding.invitations + alice.wedding.photographer +
            alice.wedding.videographer + alice.wedding.music + alice.wedding.host +
            alice.wedding.transport + alice.wedding.honeymoon + alice.wedding.other_expenses;

        if (alice.vtb.account_rub >= total) {
            alice.vtb.account_rub = alice.vtb.account_rub - total;
            alice.wedding.happened = true;
            alice.married = true;
        }
    }
}

void alice_child(const int month, const int year)
{
    if (alice.child.born == false && alice.married == true && year == 2027 && month == 5) {
        if (alice.vtb.account_rub >= alice.child.initial_expenses) {
            alice.vtb.account_rub = alice.vtb.account_rub - alice.child.initial_expenses;
            alice.child.born = true;
            alice.child.age_months = 0;
        }
    }

    if (alice.child.born == true) {
        alice.child.age_months = alice.child.age_months + 1;

        float inflation = get_inflation_rate(year, "child");

        if ((month % 6) == 0) {
            alice.child.monthly_food = alice.child.monthly_food + static_cast<RUB>(alice.child.monthly_food * (inflation / 100.0 / 2));
            alice.child.diapers = alice.child.diapers + static_cast<RUB>(alice.child.diapers * (inflation / 100.0 / 2));
            alice.child.clothes = alice.child.clothes + static_cast<RUB>(alice.child.clothes * (inflation / 100.0 / 2));
            alice.child.medicine = alice.child.medicine + static_cast<RUB>(alice.child.medicine * (inflation / 100.0 / 2));
            alice.child.toys = alice.child.toys + static_cast<RUB>(alice.child.toys * (inflation / 100.0 / 2));
        }

        RUB total = alice.child.monthly_food + alice.child.diapers + alice.child.clothes +
            alice.child.medicine + alice.child.toys + alice.child.hygiene;

        if (alice.child.age_months <= 12) {
            if ((month % 3) == 0) {
                total = total + alice.child.swimming + alice.child.massage;
            }
            total = total + (alice.child.breastfeeding / 3);
        }

        if (alice.child.age_months >= 12) {
            total = total + alice.child.development + (alice.child.car_seat / 12);
        }

        if (alice.child.age_months >= 18) {
            total = total + alice.child.kindergarten;
        }

        if (alice.child.age_months >= 24) {
            if ((month % 6) == 0) {
                total = total + alice.child.dentist;
            }
        }

        if ((month % 2) == 0) {
            total = total + alice.child.doctor_visits + alice.child.vitamins;
        }

        if (month == 5) {
            total = total + alice.child.child_birthday;
        }

        if (alice.vtb.account_rub > 200'000 && (rand() % 10) == 0) {
            total = total + alice.child.babysitter;
        }

        if (alice.child.age_months == 12) {
            total = total + alice.child.high_chair;
        }
        if (alice.child.age_months == 18) {
            total = total + alice.child.playpen;
        }

        if (alice.child.age_months >= 6 && alice.child.age_months < 12) {
            alice.child.monthly_food = 4'000;
        }

        if (alice.vtb.account_rub >= total) {
            alice.vtb.account_rub = alice.vtb.account_rub - total;
        }
        else {
            alice.vtb.account_rub = 0;
        }
    }
}

void alice_divorce(const int month, const int year)
{
    if (alice.divorce.happened == false && alice.married == true && alice.child.born == true && year == 2029 && month == 3 && alice.vtb.account_rub < 100'000) {
        RUB total_divorce = alice.divorce.lawyer_services + alice.divorce.court_fee +
            alice.divorce.appraiser_services + alice.divorce.notary_for_divorce;

        if (alice.vtb.account_rub >= total_divorce) {
            alice.vtb.account_rub = alice.vtb.account_rub - total_divorce;
        }
        else {
            alice.vtb.account_rub = 0;
        }

        alice.divorce.property_division = alice.vtb.account_rub / 2;
        alice.vtb.account_rub = alice.vtb.account_rub - alice.divorce.property_division;

        alice.divorce.happened = true;
        alice.married = false;
        alice.husband_alimony = alice.divorce.alimony;
    }
}

void alice_job_change(const int month, const int year)
{
    if (alice.alice_job.employed == true && year == 2028 && month == 10 && (rand() % 100) < 20) {
        alice.alice_job.employed = false;
        alice.alice_job.looking_for_job = true;
        alice.salary = 0;
    }

    if (alice.alice_job.employed == false && alice.alice_job.looking_for_job == true) {
        alice.salary = 0;

        if ((month % 3) == 0) {
            RUB training_cost = alice.alice_job.training_courses / 3;
            if (alice.vtb.account_rub >= training_cost) {
                alice.vtb.account_rub = alice.vtb.account_rub - training_cost;
            }
            else {
                alice.vtb.account_rub = 0;
            }
        }

        int chance = 10 + (2029 - year) * 5;
        if ((rand() % 100) < chance) {
            alice.alice_job.employed = true;
            alice.alice_job.looking_for_job = false;

            RUB new_salary = alice.alice_job.salary * (1.0 + (rand() % 20) / 100.0);
            alice.salary = new_salary;
        }
    }
}

void alice_health_addiction(const int month, const int year)
{
    if (alice.health.problem_addict == false && alice.health.addiction_level == 0) {
        int start_chance = 10;
        if (year >= 2028)
        {
            start_chance = 20;
        }

        if ((rand() % 100) < start_chance) {
            alice.health.addiction_level = 15;
            alice.health.years_pursuing = 1;
        }
        else {
            return;
        }
    }

    if (alice.health.addiction_level > 0) {
        if ((rand() % 100) < 20) {
            alice.health.addiction_level = alice.health.addiction_level + 3;
            if (alice.health.addiction_level > 100) {
                alice.health.addiction_level = 100;
            }
        }

        if (alice.health.addiction_level >= 30 && alice.health.counting_calories == false) {
            alice.health.counting_calories = true;
        }

        if (alice.health.addiction_level >= 40 && alice.health.weighing_food == false) {
            alice.health.weighing_food = true;
            if (alice.vtb.account_rub >= alice.health.food_scale) {
                alice.vtb.account_rub = alice.vtb.account_rub - alice.health.food_scale;
            }
            else {
                alice.vtb.account_rub = 0;
            }
        }

        if (alice.health.addiction_level >= 50 && alice.health.gym_addict == false) {
            alice.health.gym_addict = true;
        }

        if (alice.health.addiction_level >= 60 && alice.health.orthorexia == false) {
            alice.health.orthorexia = true;
            alice.health.problem_addict = true;
        }

        if (alice.health.addiction_level >= 70 && alice.health.body_dysmorphia == false) {
            alice.health.body_dysmorphia = true;
        }

        if (alice.health.addiction_level >= 80 && alice.health.avoiding_social == false) {
            alice.health.avoiding_social = true;
        }
    }

    if (alice.health.addiction_level > 20 && alice.health.food_adjusted == false) {
        alice.alice_food.sweets = alice.alice_food.sweets * 0.3;
        alice.alice_food.fastfood = alice.alice_food.fastfood * 0.2;
        alice.alice_food.coffee = alice.alice_food.coffee * 0.5;
        alice.alice_food.beverages = alice.alice_food.beverages * 0.6;

        alice.alice_food.meat = alice.alice_food.meat * 1.2;
        alice.alice_food.vegetables = alice.alice_food.vegetables * 1.5;
        alice.alice_food.dairy = alice.alice_food.dairy * 1.1;

        if (alice.married == true) {
            alice.husband_food.sweets = alice.husband_food.sweets * 0.3;
            alice.husband_food.fastfood = alice.husband_food.fastfood * 0.2;
            alice.husband_food.coffee = alice.husband_food.coffee * 0.5;
            alice.husband_food.beverages = alice.husband_food.beverages * 0.6;

            alice.husband_food.meat = alice.husband_food.meat * 1.2;
            alice.husband_food.vegetables = alice.husband_food.vegetables * 1.5;
            alice.husband_food.dairy = alice.husband_food.dairy * 1.1;
        }

        alice.health.food_adjusted = true;
    }

    if (alice.health.orthorexia == true && alice.health.eating_out_adjusted == false) {
        alice.alice_food.bread = alice.alice_food.bread * 0.2;
        alice.alice_food.groceries = alice.alice_food.groceries * 0.5;
        alice.alice_food.cafe = alice.alice_food.cafe * 0.1;
        alice.alice_food.business_lunch = alice.alice_food.business_lunch * 0.1;
        alice.alice_food.delivery_food = alice.alice_food.delivery_food * 0.1;

        alice.alice_food.meat = alice.alice_food.meat * 1.3;
        alice.alice_food.vegetables = alice.alice_food.vegetables * 1.3;

        if (alice.married == true) {
            alice.husband_food.bread = alice.husband_food.bread * 0.2;
            alice.husband_food.groceries = alice.husband_food.groceries * 0.5;
            alice.husband_food.cafe = alice.husband_food.cafe * 0.1;
            alice.husband_food.business_lunch = alice.husband_food.business_lunch * 0.1;
            alice.husband_food.delivery_food = alice.husband_food.delivery_food * 0.1;

            alice.husband_food.meat = alice.husband_food.meat * 1.3;
            alice.husband_food.vegetables = alice.husband_food.vegetables * 1.3;
        }

        alice.health.eating_out_adjusted = true;
    }

    if (alice.health.avoiding_social == true && alice.health.social_adjusted == false) {
        alice.alice_food.cafe = 0;
        alice.alice_food.business_lunch = 0;
        alice.alice_food.delivery_food = 0;

        if (alice.married == true) {
            alice.husband_food.cafe = 0;
            alice.husband_food.business_lunch = 0;
            alice.husband_food.delivery_food = 0;
        }

        alice.health.social_adjusted = true;
    }

    RUB monthly_sport = 0;
    float addiction_multiplier = 1.0 + (alice.health.addiction_level / 100.0);

    monthly_sport = monthly_sport + static_cast<RUB>(alice.health.gym_membership * addiction_multiplier);

    if (alice.health.gym_addict == true) {
        monthly_sport = monthly_sport + static_cast<RUB>(alice.health.personal_trainer * 2);
        monthly_sport = monthly_sport + static_cast<RUB>(alice.health.group_classes);
    }

    if (alice.health.addiction_level > 40) {
        monthly_sport = monthly_sport + alice.health.swimming_pool;
    }

    RUB monthly_supplements = alice.health.protein + alice.health.bcaa + alice.health.creatine +
        alice.health.pre_workout + alice.health.vitamins_sports;

    if (alice.health.addiction_level > 50) {
        monthly_supplements = monthly_supplements + alice.health.omega3 + alice.health.collagen + alice.health.glutamine;
    }

    RUB organic_food = alice.health.organic_vegetables + alice.health.organic_meat + alice.health.organic_chicken +
        alice.health.organic_eggs + alice.health.organic_fish + alice.health.organic_dairy;

    if (alice.health.orthorexia == true) {
        organic_food = organic_food + alice.health.superfoods + alice.health.gluten_free +
            alice.health.lactose_free + alice.health.healthy_snacks + alice.health.detox_water;
    }

    RUB treatments = 0;
    if (alice.health.addiction_level > 50 && (rand() % 100) < 20) {
        treatments = treatments + alice.health.cryotherapy;
    }
    if (alice.health.addiction_level > 60 && (rand() % 100) < 15) {
        treatments = treatments + alice.health.salt_cave;
    }
    if (alice.health.addiction_level > 70 && (rand() % 100) < 10) {
        treatments = treatments + alice.health.hyperbaric_chamber;
    }
    if (alice.health.addiction_level > 80 && (rand() % 100) < 5) {
        treatments = treatments + alice.health.iv_therapy;
    }
    if (alice.health.problem_addict == true && (rand() % 100) < 8) {
        treatments = treatments + alice.health.detox_programs;
    }

    if (alice.health.addiction_level > 40 && month == 1 && (year % 2) == 0) {
        if (alice.vtb.account_rub >= alice.health.fitness_tracker) {
            alice.vtb.account_rub = alice.vtb.account_rub - alice.health.fitness_tracker;
        }
        else {
            alice.vtb.account_rub = 0;
        }
    }

    if (alice.health.addiction_level > 60 && month == 6 && (rand() % 100) < 30) {
        if (alice.vtb.account_rub >= alice.health.blenders) {
            alice.vtb.account_rub = alice.vtb.account_rub - alice.health.blenders;
        }
        else {
            alice.vtb.account_rub = 0;
        }
    }

    RUB health_total = monthly_sport + monthly_supplements + organic_food + treatments;
    if (alice.vtb.account_rub >= health_total) {
        alice.vtb.account_rub = alice.vtb.account_rub - health_total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
    alice.health.total_spent = alice.health.total_spent + health_total;

    if (alice.health.addiction_level > 30 && (month % 3) == 0) {
        if (alice.vtb.account_rub >= alice.health.nutritionist) {
            alice.vtb.account_rub = alice.vtb.account_rub - alice.health.nutritionist;
        }
        else {
            alice.vtb.account_rub = 0;
        }
    }

    alice.health.monthly_average = (alice.health.monthly_average * 11 + health_total) / 12;
}

void alice_inheritance(const int month, const int year)
{
    if (alice.inheritance.received == true) {
        return;
    }

    int chance = 0;
    if (year == 2027) {
        chance = 15;
    }
    else if (year == 2028) {
        chance = 10;
    }
    else if (year == 2029) {
        chance = 5;
    }
    else {
        return;
    }

    if (alice.vtb.account_rub < 50'000) {
        chance = chance * 2;
    }
    if ((rand() % 100) >= chance) {
        return;
    }

    int type = rand() % 100;
    RUB total_amount = 0;
    RUB expenses = 0;

    if (type < 50) {
        alice.inheritance.from_grandmother = true;
        if ((rand() % 100) < 70) {
            alice.inheritance.was_expected = true;
        }
        else {
            alice.inheritance.was_expected = false;
        }

        RUB apartment_price = 0;
        if ((rand() % 100) < 30) {
            apartment_price = 8'000'000 + (rand() % 5'000'000);
        }
        else if ((rand() % 100) < 50) {
            apartment_price = 4'000'000 + (rand() % 3'000'000);
        }
        else {
            apartment_price = 1'500'000 + (rand() % 1'500'000);
        }

        alice.inheritance.apartment_value = apartment_price;
        total_amount = total_amount + apartment_price;

        alice.inheritance.notary_costs = 15'000 + (rand() % 20'000);
        alice.inheritance.appraisal_costs = 5'000 + (rand() % 5'000);

        expenses = expenses + alice.inheritance.notary_costs;
        expenses = expenses + alice.inheritance.appraisal_costs;
    }
    else if (type < 80) {
        alice.inheritance.from_distant_relative = true;
        alice.inheritance.was_shock = true;

        RUB cash_amount = 300'000 + (rand() % 700'000);
        alice.inheritance.cash = cash_amount;
        total_amount = total_amount + cash_amount;

        alice.inheritance.tax_on_inheritance = static_cast<RUB>(cash_amount * 0.13);
        expenses = expenses + alice.inheritance.tax_on_inheritance;

        alice.inheritance.lawyer_costs = 30'000 + (rand() % 30'000);
        expenses = expenses + alice.inheritance.lawyer_costs;
    }
    else
    {
        alice.inheritance.from_unexpected = true;
        alice.inheritance.was_shock = true;

        int sub_type = rand() % 3;

        if (sub_type == 0) {
            alice.inheritance.jewelry = 200'000 + (rand() % 300'000);
            alice.inheritance.antiques = 100'000 + (rand() % 200'000);
            total_amount = total_amount + alice.inheritance.jewelry + alice.inheritance.antiques;
        }
        else if (sub_type == 1) {
            alice.inheritance.car_value = 400'000 + (rand() % 400'000);
            total_amount = total_amount + alice.inheritance.car_value;
        }
        else {
            alice.inheritance.cash = 100'000 + (rand() % 200'000);
            total_amount = total_amount + alice.inheritance.cash;
        }

        if ((rand() % 100) < 30) {
            alice.inheritance.debt_of_relative = static_cast<RUB>(total_amount * 0.2);
            expenses = expenses + alice.inheritance.debt_of_relative;
        }
    }

    if ((rand() % 100) < 25 && total_amount > 1'000'000) {
        alice.inheritance.caused_family_drama = true;
        RUB legal_costs = static_cast<RUB>(total_amount * 0.1);
        expenses = expenses + legal_costs;
    }

    RUB net_amount = total_amount - expenses;
    if (net_amount < 0) {
        net_amount = 0;
    }

    alice.inheritance.amount = net_amount;
    alice.inheritance.year_received = year;
    alice.inheritance.month_received = month;
    alice.inheritance.received = true;

    alice.vtb.account_rub = alice.vtb.account_rub + net_amount;
}

void alice_sleep_health(const int month, const int year)
{
    RUB total = 0;

    if (month == 11 && year == 2027) {
        total = total + alice.sleep.orthopedic_mattress + alice.sleep.expensive_pillows;
    }
    if (month == 10 && year == 2028) {
        total = total + alice.sleep.weighted_blanket + alice.sleep.blackout_curtains;
    }
    if (month >= 10 || month <= 3) {
        total = total + alice.sleep.vitamin_d;
    }
    if (month == 1 && alice.married == true && year >= 2027) {
        total = total + alice.sleep.winter_sun_trips;
    }

    if (alice.vtb.account_rub >= total) {
        alice.vtb.account_rub = alice.vtb.account_rub - total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_social_capital(const int month, const int year)
{
    RUB social_total = 0;
    if ((rand() % 100) < 30) {
        social_total = social_total + alice.social.colleague_gifts;
    }
    if ((rand() % 100) < 40) {
        social_total = social_total + alice.social.work_contributions;
    }
    if (month == 12) {
        social_total = social_total + (alice.social.relative_gifts * 3);
    }
    if (month == 2) {
        social_total = social_total + alice.social.relative_gifts;
    }
    if (month == 3) {
        social_total = social_total + alice.social.relative_gifts;
    }

    if (alice.vtb.account_rub >= social_total) {
        alice.vtb.account_rub = alice.vtb.account_rub - social_total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_intangible_services(const int month, const int year)
{
    RUB intangible_total = 0;
    if (alice.divorce.happened == true || alice.vtb.account_rub < 50'000) {
        intangible_total = intangible_total + alice.intangible.psychologist;
    }
    if (alice.alice_job.looking_for_job == true) {
        intangible_total = intangible_total + alice.intangible.career_consultant;
    }
    if (alice.vtb.account_rub < 30'000 && (rand() % 100) < 20) {
        intangible_total = intangible_total + alice.intangible.astrologer;
        intangible_total = intangible_total + alice.intangible.tarot_reader;
    }

    if (alice.vtb.account_rub >= intangible_total) {
        alice.vtb.account_rub = alice.vtb.account_rub - intangible_total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_situational_purchases(const int month, const int year)
{
    RUB situational_total = 0;
    if (month == 11 && year == 2027 && alice.alice_job.employed == true) {
        situational_total = situational_total + alice.situational.corporate_outfit;
    }
    if (month == 6 && year == 2028 && alice.married == true) {
        situational_total = situational_total + alice.situational.wedding_outfit;
    }
    if (month == 5 && year == 2027 && alice.alice_job.employed == true) {
        situational_total = situational_total + alice.situational.team_building_gear;
    }

    if (alice.vtb.account_rub >= situational_total) {
        alice.vtb.account_rub = alice.vtb.account_rub - situational_total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_paid_apps(const int month, const int year)
{
    RUB apps_total = alice.paid_apps.planner_app + alice.paid_apps.password_manager_app +
        alice.paid_apps.vpn_app + alice.paid_apps.sleep_app + alice.paid_apps.meditation_app +
        alice.paid_apps.fitness_app_paid + alice.paid_apps.language_learning +
        alice.paid_apps.productivity_tools;

    if (alice.vtb.account_rub >= apps_total) {
        alice.vtb.account_rub = alice.vtb.account_rub - apps_total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_legal_mistakes(const int month, const int year)
{
    RUB legal_total = 0;
    if (month == 4 && year == 2028) {
        legal_total = legal_total + alice.legal.tax_unclaimed;
    }
    if ((rand() % 100) < 5) {
        legal_total = legal_total + alice.legal.contract_violations;
    }
    if ((rand() % 100) < 8) {
        legal_total = legal_total + alice.legal.document_errors;
    }

    if (alice.vtb.account_rub >= legal_total) {
        alice.vtb.account_rub = alice.vtb.account_rub - legal_total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_friend_support(const int month, const int year)
{
    RUB friend_total = 0;
    if ((rand() % 100) < 25 && alice.alice_food.cafe > 0) {
        friend_total = friend_total + alice.friends.paying_for_friends;
    }
    if ((rand() % 100) < 30 && alice.alice_food.cafe > 0) {
        friend_total = friend_total + alice.friends.group_taxi;
    }
    if (alice.married == true && alice.alice_food.cafe > 0) {
        friend_total = friend_total + alice.friends.unconscious_spending;
    }

    if (alice.vtb.account_rub >= friend_total) {
        alice.vtb.account_rub = alice.vtb.account_rub - friend_total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_storage(const int month, const int year)
{
    if (alice.storage.has_storage == false) {
        return;
    }
    RUB storage_total = alice.storage.self_storage_rent;
    if (month == 4 || month == 10) {
        storage_total = storage_total + alice.storage.seasonal_tires_storage;
    }

    if (alice.vtb.account_rub >= storage_total) {
        alice.vtb.account_rub = alice.vtb.account_rub - storage_total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_transaction_costs(const int month, const int year)
{
    RUB total_costs = 0;
    if ((rand() % 100) < 40) {
        total_costs = total_costs + alice.transactions.return_shipping;
        total_costs = total_costs + (alice.transactions.delivery_returns / 2);
    }
    if ((rand() % 100) < 10) {
        total_costs = total_costs + alice.transactions.late_fees;
    }
    if (month == 4 && year > 2026) {
        total_costs = total_costs + alice.transactions.tax_penalties;
    }

    if (alice.vtb.account_rub >= total_costs) {
        alice.vtb.account_rub = alice.vtb.account_rub - total_costs;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_emotional_spending(const int month, const int year)
{
    RUB emotional_total = 0;
    if (alice.vtb.account_rub < 100'000) {
        emotional_total = emotional_total + alice.emotions.stress_purchases;
    }
    if ((rand() % 100) < 30) {
        emotional_total = emotional_total + (alice.emotions.impulse_buys / 2);
    }
    if ((rand() % 100) < 25) {
        emotional_total = emotional_total + alice.emotions.retail_therapy;
    }

    if (alice.vtb.account_rub >= emotional_total) {
        alice.vtb.account_rub = alice.vtb.account_rub - emotional_total;
    }
    else {
        alice.vtb.account_rub = 0;
    }

    if (emotional_total > 0) {
        alice.emotions.unused_items = alice.emotions.unused_items + static_cast<RUB>(emotional_total * 0.3);
    }
}

void alice_convenience_spending(const int month, const int year)
{
    RUB convenience_total = 0;
    if ((rand() % 100) < 60) {
        convenience_total = convenience_total + alice.convenience.corner_store_markup;
    }
    if (alice.on_maternity_leave == true) {
        convenience_total = convenience_total + (alice.convenience.food_delivery * 2);
        convenience_total = convenience_total + alice.convenience.ready_meals;
    }
    if ((rand() % 100) < 15) {
        convenience_total = convenience_total + alice.convenience.express_delivery;
    }

    if (alice.vtb.account_rub >= convenience_total) {
        alice.vtb.account_rub = alice.vtb.account_rub - convenience_total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_proxy_spending(const int month, const int year)
{
    RUB proxy_total = 0;
    if (alice.child.born == true) {
        if ((rand() % 100) < 20) {
            proxy_total = proxy_total + alice.proxy.children_toys_adult;
        }
        if (alice.child.age_months > 12 && (rand() % 100) < 15) {
            proxy_total = proxy_total + alice.proxy.hobby_for_child;
        }
    }
    if (alice.cat.have_pet == true || alice.dog.have_pet == true) {
        if ((rand() % 100) < 10) {
            proxy_total = proxy_total + alice.proxy.pet_luxury;
            proxy_total = proxy_total + alice.proxy.expensive_pet_items;
        }
    }

    if (alice.vtb.account_rub >= proxy_total) {
        alice.vtb.account_rub = alice.vtb.account_rub - proxy_total;
    }
    else {
        alice.vtb.account_rub = 0;
    }
}

void alice_handle_pets(const int month, const int year)
{
    if (alice.married == true && year >= 2027) {
        if (alice.cat.have_pet == false && month == 9) {
            alice.cat.have_pet = true;
            if (alice.vtb.account_rub >= 10'000) {
                alice.vtb.account_rub = alice.vtb.account_rub - 10'000;
            }
            else {
                alice.vtb.account_rub = 0;
            }
        }
        if (alice.dog.have_pet == false && alice.child.born == true && month == 10) {
            alice.dog.have_pet = true;
            if (alice.vtb.account_rub >= 15'000) {
                alice.vtb.account_rub = alice.vtb.account_rub - 15'000;
            }
            else {
                alice.vtb.account_rub = 0;
            }
        }
        if (alice.hamster.have_pet == false && alice.child.born == true && month == 11) {
            alice.hamster.have_pet = true;
            if (alice.vtb.account_rub >= 2'000) {
                alice.vtb.account_rub = alice.vtb.account_rub - 2'000;
            }
            else {
                alice.vtb.account_rub = 0;
            }
        }
    }

    if (alice.cat.have_pet == true) {
        RUB cat_total = alice.cat.food + alice.cat.treats + alice.cat.filler + (alice.cat.toys_for_pet / 3);

        if ((month % 3) == 0) {
            cat_total = cat_total + alice.cat.veterinary + alice.cat.grooming;
        }

        if ((month % 6) == 0) {
            cat_total = cat_total + alice.cat.vaccinations + alice.cat.claws_care;
        }

        if (month == 1) {
            cat_total = cat_total + alice.cat.bedding + (alice.cat.carrier / 2);
        }

        if (alice.vtb.account_rub >= cat_total) {
            alice.vtb.account_rub = alice.vtb.account_rub - cat_total;
        }
        else {
            alice.vtb.account_rub = 0;
        }
    }

    if (alice.hamster.have_pet == true) {
        RUB hamster_total = alice.hamster.food + alice.hamster.treats + alice.hamster.filler + (alice.hamster.toys_for_pet / 3);

        if ((month % 3) == 0) {
            hamster_total = hamster_total + alice.hamster.veterinary + alice.hamster.grooming;
        }

        if ((month % 6) == 0) {
            hamster_total = hamster_total + alice.hamster.vaccinations + alice.hamster.claws_care;
        }

        if (month == 1) {
            hamster_total = hamster_total + alice.hamster.bedding + (alice.hamster.carrier / 2);
        }

        if (alice.vtb.account_rub >= hamster_total) {
            alice.vtb.account_rub = alice.vtb.account_rub - hamster_total;
        }
        else {
            alice.vtb.account_rub = 0;
        }
    }

    if (alice.dog.have_pet == true) {
        RUB dog_total = alice.dog.food + alice.dog.treats + alice.dog.filler + (alice.dog.toys_for_pet / 3);

        if ((month % 3) == 0) {
            dog_total = dog_total + alice.dog.veterinary + alice.dog.grooming;
        }

        if ((month % 6) == 0) {
            dog_total = dog_total + alice.dog.vaccinations + alice.dog.claws_care;
        }

        if (month == 1) {
            dog_total = dog_total + alice.dog.bedding + (alice.dog.carrier / 2);
        }

        if (alice.vtb.account_rub >= dog_total) {
            alice.vtb.account_rub = alice.vtb.account_rub - dog_total;
        }
        else {
            alice.vtb.account_rub = 0;
        }
    }
}

void alice_update_emergency_fund()
{
    if (alice.vtb.account_rub > (alice.emergency_fund_personal * 12)) {
        RUB transfer = alice.vtb.account_rub / 10;
        alice.emergency_fund_personal = alice.emergency_fund_personal + transfer;
        if (alice.vtb.account_rub >= transfer) {
            alice.vtb.account_rub = alice.vtb.account_rub - transfer;
        }
        else {
            alice.vtb.account_rub = 0;
        }
    }
}

void print_results()
{
    RUB capital = 0;
    capital = capital + alice.vtb.account_rub;
    capital = capital + static_cast<RUB>(alice.vtb.account_usd * alice.vtb.rate_usd_rub);
    capital = capital + alice.vtb.deposit_rub;
    capital = capital + static_cast<RUB>(alice.vtb.deposit_usd * alice.vtb.rate_usd_rub);
    capital = capital + alice.vtb.investment_bonds;
    capital = capital + alice.vtb.investment_stocks;
    capital = capital + 5'000'000;

    printf("\nкапитал:\n");
    printf("наличные/счета: %I64d руб.\n", alice.vtb.account_rub);
    printf("депозиты: %I64d руб.\n", alice.vtb.deposit_rub);
    printf("инвестиции: %I64d руб.\n", alice.vtb.investment_bonds + alice.vtb.investment_stocks);
    printf("недвижимость: 5,000,000 руб.\n");
    printf("конечный капитал: %I64d руб.\n", capital);

    printf("\nДиНаМиКа:\n");
    printf("начальный капитал: 500,000 руб.\n");
    printf("конечный капитал: %I64d руб.\n", capital);
    printf("изменение: %+I64d руб. (%+.1f%%)\n", capital - 500000, (capital - 500000) * 100.0 / 500000);
}

void simulation()
{
    int year = 2026;
    int month = 1;

    while ((year == 2030 && month == 1) == false)
    {
        alice_salary(month, year);
        alice_bank(month, year);
        alice_inheritance(month, year);

        alice_mortgage(month, year);
        alice_flat_1(month, year);

        alice_car(alice.car_alice, month, year);
        alice_car(alice.car_husband, month, year);

        alice_food(month, year);

        alice_subscriptions(month, year);
        alice_paid_apps(month, year);

        alice_health_addiction(month, year);
        alice_sleep_health(month, year);

        alice_social_capital(month, year);
        alice_friend_support(month, year);
        alice_intangible_services(month, year);

        alice_transaction_costs(month, year);
        alice_emotional_spending(month, year);
        alice_convenience_spending(month, year);
        alice_proxy_spending(month, year);
        alice_situational_purchases(month, year);

        alice_legal_mistakes(month, year);
        alice_bank_fees(month, year);
        alice_storage(month, year);

        alice_wedding(month, year);
        alice_child(month, year);
        alice_divorce(month, year);
        alice_job_change(month, year);

        alice_handle_pets(month, year);

        alice_update_emergency_fund();

        month = month + 1;
        if (month == 13)
        {
            year = year + 1;
            month = 1;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    alice_init();
    simulation();
    print_results();

    return 0;
}