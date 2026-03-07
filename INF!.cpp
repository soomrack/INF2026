#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <map>
#include <algorithm>

using RUB = float;
using EUR = float;
using USD = float;
using GBP = float;
using CNY = float;
using Percent = float;

RUB inflation = 0.085;
int current_month = 1;
int current_year = 2024;
int simulation_months = 60;
int global_happiness = 100;
int ecology_index = 75;
RUB oil_price = 4500;
RUB dollar_index = 88.5;

struct BankAccount {
    RUB checking;
    RUB savings;
    RUB deposite;
    Percent interest;
    RUB credit_card_debt;
    RUB credit_limit;
    RUB credit_used;
    EUR eur_account;
    RUB eur_rate;
    USD usd_account;
    RUB usd_rate;
    GBP gbp_account;
    RUB gbp_rate;
    CNY cny_account;
    RUB cny_rate;
    RUB debit_card;
    RUB virtual_card;
    RUB cash;
    RUB safe_deposit;
    std::map<std::string, RUB> crypto_wallet;
};

struct RealEstate {
    RUB apartment_value;
    RUB house_value;
    RUB cottage_value;
    RUB land_value;
    RUB commercial_value;
    RUB rent_income;
    RUB mortgage_payment;
    RUB mortgage_debt;
    Percent mortgage_rate;
    int mortgage_term;
    RUB property_tax;
    RUB utilities;
    RUB repairs;
    RUB renovation;
    RUB furniture;
    RUB appliances;
    RUB insurance;
    RUB management_fee;
    std::vector<RUB> rental_history;
};

struct Vehicle {
    RUB car1_value;
    RUB car2_value;
    RUB car3_value;
    RUB motorcycle_value;
    RUB scooter_value;
    RUB bicycle_value;
    RUB boat_value;
    RUB gas_monthly;
    RUB insurance;
    RUB tax;
    RUB maintenance;
    RUB parking;
    RUB fines;
    RUB loan_payment;
    RUB loan_debt;
    RUB washing;
    RUB detailing;
    RUB winter_tires;
    RUB summer_tires;
    RUB diagnostics;
    RUB oil_change;
    std::map<std::string, int> mileage;
};

struct Investments {
    RUB stocks;
    RUB bonds;
    RUB etf;
    RUB crypto;
    RUB gold;
    RUB silver;
    RUB platinum;
    RUB diamonds;
    RUB art;
    RUB antiques;
    RUB business_share;
    RUB p2p_lending;
    RUB investment_fund;
    RUB venture_capital;
    RUB startup_invest;
    RUB dividends_monthly;
    RUB crowdfunding;
    RUB nft;
    std::map<std::string, RUB> stock_portfolio;
    std::vector<RUB> investment_history;
};

struct Education {
    RUB student_loan;
    RUB courses;
    RUB books;
    RUB seminars;
    RUB webinars;
    RUB online_subscriptions;
    RUB children_education;
    RUB university;
    RUB masters_degree;
    RUB phd;
    RUB language_courses;
    RUB driving_license;
    RUB professional_cert;
    RUB workshops;
    RUB tutoring;
    std::vector<std::string> skills;
};

struct Food {
    RUB groceries;
    RUB restaurant;
    RUB fastfood;
    RUB delivery;
    RUB coffee;
    RUB work_lunch;
    RUB meat;
    RUB vegetables;
    RUB fruits;
    RUB dairy;
    RUB bakery;
    RUB alcohol;
    RUB sweets;
    RUB healthy_food;
    RUB organic;
    RUB gluten_free;
    RUB vegan;
    RUB seafood;
    RUB exotic;
    RUB spices;
    RUB sauces;
    RUB beverages;
    RUB snacks;
    RUB breakfast;
    RUB dinner;
    std::map<std::string, RUB> weekly_meal_plan;
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
    RUB travel;
    RUB vacation;
    RUB nightclub;
    RUB bar;
    RUB karaoke;
    RUB bowling;
    RUB paintball;
    RUB quest_rooms;
    RUB escape_rooms;
    RUB amusement_park;
    RUB zoo;
    RUB aquarium;
    RUB planetarium;
    std::vector<std::string> visited_places;
};

struct Health {
    RUB insurance;
    RUB doctors;
    RUB dentistry;
    RUB medications;
    RUB gym;
    RUB therapy;
    RUB vitamins;
    RUB emergency;
    RUB hospital;
    RUB surgery;
    RUB rehabilitation;
    RUB massage;
    RUB spa;
    RUB psycholog;
    RUB alternative_medicine;
    RUB fitness;
    RUB yoga;
    RUB meditation;
    RUB supplements;
    std::map<std::string, int> health_metrics;
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
    RUB sleepwear;
    RUB swimwear;
    RUB outerwear;
    RUB formal;
    RUB casual;
    RUB designer;
    RUB vintage;
    std::map<std::string, int> wardrobe;
};

struct Tech {
    RUB smartphone;
    RUB laptop;
    RUB tablet;
    RUB tv;
    RUB headphones;
    RUB gadgets;
    RUB subscriptions;
    RUB games;
    RUB smart_home;
    RUB camera;
    RUB drone;
    RUB vr_headset;
    RUB smart_watch;
    RUB fitness_tracker;
    RUB e_reader;
    RUB gaming_console;
    RUB monitor;
    RUB printer;
    RUB router;
    RUB cloud_storage;
    RUB software;
    std::vector<std::string> apps;
};

struct Pets {
    RUB dog_food;
    RUB cat_food;
    RUB bird_food;
    RUB fish_food;
    RUB vet;
    RUB grooming;
    RUB toys;
    RUB accessories;
    RUB training;
    RUB insurance;
    RUB boarding;
    int dogs_count;
    int cats_count;
    std::vector<std::string> pet_names;
};

struct Charity {
    RUB donations;
    RUB volunteering;
    RUB church;
    RUB homeless;
    RUB animal_shelter;
    RUB children_fund;
    RUB ecology;
    RUB education;
    RUB medicine;
    std::vector<std::string> charity_orgs;
};

struct Business {
    RUB own_business;
    RUB franchise;
    RUB online_store;
    RUB dropshipping;
    RUB mlm;
    RUB consulting;
    RUB freelancing;
    RUB youtube_channel;
    RUB blog;
    RUB instagram;
    RUB tiktok;
    RUB patreon;
    RUB onlyfans;
    RUB revenue;
    RUB expenses;
    RUB profit;
    RUB taxes;
    std::map<std::string, RUB> monthly_revenue;
};

struct Subscriptions {
    RUB netflix;
    RUB spotify;
    RUB youtube_premium;
    RUB apple_music;
    RUB disney_plus;
    RUB hbo;
    RUB amazon_prime;
    RUB patreon_subs;
    RUB twitch;
    RUB discord_nitro;
    RUB chatgpt;
    RUB midjourney;
    RUB photoshop;
    RUB office_365;
    RUB antivirus;
    RUB vpn;
    std::map<std::string, bool> active_subs;
};

struct Insurance {
    RUB life;
    RUB health;
    RUB car;
    RUB home;
    RUB travel;
    RUB pet;
    RUB business;
    RUB liability;
    RUB disability;
    std::map<std::string, RUB> coverage;
};

struct Taxes {
    RUB income_tax;
    RUB property_tax;
    RUB transport_tax;
    RUB land_tax;
    RUB dividend_tax;
    RUB crypto_tax;
    RUB inheritance_tax;
    RUB gift_tax;
    Percent tax_rate;
    std::vector<RUB> tax_history;
};

struct Debt {
    RUB mortgage;
    RUB car_loan;
    RUB student_loan;
    RUB personal_loan;
    RUB microfinance;
    RUB payday_loans;
    RUB family_debt;
    RUB friends_debt;
    RUB business_loan;
    RUB credit_line;
    RUB overdraft;
    RUB pawnshop;
    RUB bail;
    std::map<std::string, Percent> debt_rates;
    std::map<std::string, int> debt_terms;
};

struct Assets {
    RUB cash;
    RUB bank_deposits;
    RUB stocks;
    RUB bonds;
    RUB real_estate;
    RUB vehicles;
    RUB gold;
    RUB crypto;
    RUB business;
    RUB intellectual_property;
    RUB patents;
    RUB copyrights;
    RUB trademarks;
    std::vector<RUB> asset_history;
};

struct Goals {
    RUB buy_apartment;
    RUB buy_house;
    RUB buy_car;
    RUB travel_world;
    RUB retirement;
    RUB children_education;
    RUB start_business;
    RUB early_retirement;
    RUB financial_freedom;
    RUB passive_income_target;
    int target_age;
    std::map<std::string, RUB> goal_progress;
};

struct Statistics {
    RUB total_income;
    RUB total_expenses;
    RUB total_savings;
    RUB total_investments;
    RUB total_taxes;
    RUB avg_monthly_spend;
    RUB savings_rate;
    std::vector<RUB> income_history;
    std::vector<RUB> expense_history;
};

struct Person {
    std::string name;
    RUB salary;
    RUB passive_income;
    RUB bonus;
    RUB side_hustle;
    RUB pension;
    RUB social_benefits;
    RUB alimony;
    RUB inheritance;
    RUB lottery_wins;

    BankAccount bank;
    RealEstate realty;
    Vehicle transport;
    Investments invest;
    Education edu;
    Food food;
    Entertainment fun;
    Health health;
    Clothing clothes;
    Tech tech;
    Pets pets;
    Charity charity;
    Business business;
    Subscriptions subs;
    Insurance insurance;
    Taxes taxes;
    Debt debts;
    Assets assets;
    Goals goals;
    Statistics stats;

    RUB total_assets;
    RUB total_debts;
    RUB net_worth;
    RUB monthly_savings;
    RUB yearly_savings;

    int age;
    int health_score;
    int happiness;
    int stress_level;
    int work_life_balance;
    bool has_child;
    int children_count;
    bool married;
    std::string partner_name;
    std::string job_title;
    std::string education_level;
    std::vector<std::string> life_events;
    std::map<std::string, int> skills_level;
};

Person david, lisa;
std::vector<Person> family;
std::map<int, std::string> global_events;
std::vector<RUB> market_crashes;

void init_global_events() {
    global_events[2024] = "Олимпиада";
    global_events[2025] = "Экономический форум";
    global_events[2026] = "Чемпионат мира по футболу";
    global_events[2027] = "Технологическая выставка";
    global_events[2028] = "Крипто-бум";
    global_events[2029] = "Климатический саммит";
}

void init_david() {
    david.name = "David";
    david.salary = 300000;
    david.passive_income = 15000;
    david.bonus = 50000;
    david.side_hustle = 20000;
    david.pension = 0;
    david.social_benefits = 0;
    david.alimony = 0;
    david.inheritance = 500000;
    david.lottery_wins = 0;

    david.bank.checking = 150000;
    david.bank.savings = 500000;
    david.bank.deposite = 1000000;
    david.bank.interest = 15.0;
    david.bank.credit_card_debt = 0;
    david.bank.credit_limit = 500000;
    david.bank.credit_used = 0;
    david.bank.eur_account = 5000;
    david.bank.eur_rate = 95.0;
    david.bank.usd_account = 3000;
    david.bank.usd_rate = 88.0;
    david.bank.gbp_account = 1000;
    david.bank.gbp_rate = 112.0;
    david.bank.cny_account = 5000;
    david.bank.cny_rate = 12.5;
    david.bank.cash = 50000;
    david.bank.safe_deposit = 200000;
    david.bank.crypto_wallet["BTC"] = 0.1;
    david.bank.crypto_wallet["ETH"] = 1.5;

    david.realty.apartment_value = 8000000;
    david.realty.house_value = 0;
    d.realty.cottage_value = 0;
    david.realty.land_value = 0;
    david.realty.commercial_value = 0;
    david.realty.rent_income = 40000;
    david.realty.mortgage_payment = 0;
    david.realty.mortgage_debt = 0;
    david.realty.property_tax = 8000;
    david.realty.utilities = 12000;
    david.realty.repairs = 5000;
    david.realty.renovation = 0;
    david.realty.furniture = 300000;
    david.realty.appliances = 150000;
    david.realty.insurance = 10000;

    david.transport.car1_value = 2500000;
    david.transport.car2_value = 0;
    david.transport.bicycle_value = 30000;
    david.transport.gas_monthly = 15000;
    david.transport.insurance = 8000;
    david.transport.tax = 3000;
    david.transport.maintenance = 5000;
    david.transport.parking = 3000;
    david.transport.fines = 0;
    david.transport.washing = 2000;
    david.transport.detailing = 5000;
    david.transport.winter_tires = 30000;
    david.transport.mileage["car1"] = 45000;

    david.invest.stocks = 300000;
    david.invest.bonds = 200000;
    david.invest.etf = 150000;
    david.invest.crypto = 50000;
    david.invest.gold = 100000;
    david.invest.silver = 30000;
    david.invest.art = 50000;
    david.invest.business_share = 200000;
    david.invest.dividends_monthly = 15000;
    david.invest.stock_portfolio["SBER"] = 100000;
    david.invest.stock_portfolio["GAZP"] = 150000;
    david.invest.stock_portfolio["YNDX"] = 50000;

    david.age = 32;
    david.health_score = 90;
    david.happiness = 85;
    david.stress_level = 40;
    david.work_life_balance = 70;
    david.has_child = false;
    david.married = true;
    david.partner_name = "Lisa";
    david.job_title = "IT Director";
    david.education_level = "Master";

    david.subs.netflix = 1000;
    david.subs.spotify = 500;
    david.subs.youtube_premium = 400;
    david.subs.chatgpt = 800;
    david.subs.vpn = 300;

    david.stats.total_income = david.salary * 12;
    david.stats.savings_rate = 0.3;
}

void init_lisa() {
    lisa.name = "Lisa";
    lisa.salary = 100000;
    lisa.passive_income = 0;
    lisa.bonus = 10000;
    lisa.side_hustle = 5000;
    lisa.inheritance = 100000;

    lisa.bank.checking = 25000;
    lisa.bank.savings = 50000;
    lisa.bank.deposite = 0;
    lisa.bank.interest = 12.0;
    lisa.bank.credit_card_debt = 150000;
    lisa.bank.credit_limit = 300000;
    lisa.bank.credit_used = 150000;
    lisa.bank.eur_account = 200;
    lisa.bank.eur_rate = 95.0;
    lisa.bank.cash = 10000;
    lisa.bank.crypto_wallet["BTC"] = 0.01;

    lisa.realty.apartment_value = 0;
    lisa.realty.rent_income = 0;
    lisa.realty.mortgage_payment = 45000;
    lisa.realty.mortgage_debt = 3500000;
    lisa.realty.mortgage_rate = 12.5;
    lisa.realty.mortgage_term = 240;
    lisa.realty.utilities = 8000;
    lisa.realty.furniture = 200000;

    lisa.transport.car1_value = 800000;
    lisa.transport.gas_monthly = 8000;
    lisa.transport.insurance = 5000;
    lisa.transport.tax = 2000;
    lisa.transport.maintenance = 3000;
    lisa.transport.loan_payment = 15000;
    lisa.transport.loan_debt = 300000;
    lisa.transport.parking = 2000;
    lisa.transport.mileage["car1"] = 30000;

    lisa.invest.crypto = 10000;
    lisa.invest.gold = 15000;

    lisa.edu.student_loan = 400000;
    lisa.edu.language_courses = 30000;
    lisa.edu.skills = { "Design", "Photo", "SMM" };

    lisa.age = 28;
    lisa.health_score = 85;
    lisa.happiness = 90;
    lisa.stress_level = 60;
    lisa.has_child = false;
    lisa.married = true;
    lisa.partner_name = "David";
    lisa.job_title = "Designer";

    lisa.subs.spotify = 500;
    lisa.subs.disney_plus = 800;
    lisa.subs.instagram = 0;

    lisa.debts.mortgage = 3500000;
    lisa.debts.car_loan = 300000;
    lisa.debts.student_loan = 400000;
    lisa.debts.credit_line = 150000;
}

void market_simulation() {
    int market_event = rand() % 100;

    if (market_event < 10) {
        std::cout << "📉 Биржевой крах! Акции падают на 15%" << std::endl;
        david.invest.stocks *= 0.85;
        david.invest.etf *= 0.85;
        market_crashes.push_back(current_year * 100 + current_month);
    }
    else if (market_event < 20) {
        std::cout << "📈 Растущий рынок! Акции растут на 10%" << std::endl;
        david.invest.stocks *= 1.10;
        david.invest.etf *= 1.10;
    }

    if (rand() % 100 < 30) {
        RUB btc_change = 0.9 + (rand() % 30) / 100.0;
        david.bank.crypto_wallet["BTC"] *= btc_change;
        lisa.bank.crypto_wallet["BTC"] *= btc_change;
    }

    dollar_index = 85 + (rand() % 20);
    david.bank.usd_rate = dollar_index;
    lisa.bank.usd_rate = dollar_index;
}

void economic_crisis() {
    if (market_crashes.size() > 2) {
        std::cout << "⚠️ ЭКОНОМИЧЕСКИЙ КРИЗИС!" << std::endl;
        inflation += 0.15;
        david.salary *= 0.9;
        lisa.salary *= 0.85;
        david.realty.apartment_value *= 0.7;
        lisa.realty.apartment_value *= 0.7;
        david.invest.stocks *= 0.5;
        david.invest.bonds *= 0.8;
    }
}

void random_events(Person& p, bool is_david) {
    int event = rand() % 200;

    if (event < 5) {
        p.lottery_wins = 100000 + (rand() % 900000);
        p.bank.checking += p.lottery_wins;
        std::cout << "🍀 " << p.name << " выиграл в лотерею " << p.lottery_wins << " RUB!" << std::endl;
    }
    else if (event < 10) {
        p.inheritance += 500000;
        p.bank.checking += 500000;
        std::cout << "💝 " << p.name << " получил наследство!" << std::endl;
    }
    else if (event < 15) {
        p.bank.checking -= 50000;
        p.transport.fines = 5000;
        std::cout << "🚔 " << p.name << " получил штраф" << std::endl;
    }
    else if (event < 20) {
        p.health.emergency = 30000;
        p.bank.checking -= 30000;
        p.health_score -= 10;
        std::cout << "🏥 " << p.name << " попал в больницу" << std::endl;
    }
    else if (event < 25) {
        p.tech.smartphone = 80000;
        p.bank.checking -= 80000;
        std::cout << "📱 " << p.name << " купил новый телефон" << std::endl;
    }
    else if (event < 30) {
        p.fun.travel = 100000;
        p.bank.checking -= 100000;
        p.happiness += 15;
        std::cout << "✈️ " << p.name << " съездил в отпуск" << std::endl;
    }
    else if (event < 33 && !p.has_child && p.married) {
        p.has_child = true;
        p.children_count = 1;
        p.bank.checking -= 150000;
        std::cout << "👶 У " << p.name << " родился ребенок!" << std::endl;
    }
    else if (event < 36) {
        p.business.own_business += 200000;
        p.business.revenue = 50000;
        std::cout << "💼 " << p.name << " открыл свой бизнес!" << std::endl;
    }
    else if (event < 39) {
        p.salary *= 1.2;
        std::cout << "📈 " << p.name << " получил повышение!" << std::endl;
    }
    else if (event < 42) {
        p.salary *= 0.9;
        std::cout << "📉 " << p.name << " понизили в должности" << std::endl;
    }
}

void special_events() {
    if (current_month == 1 && current_year == 2025) {
        std::cout << "\n🎉 НОВЫЙ ГОД 2025!" << std::endl;
        david.bank.checking += 100000;
        lisa.bank.checking += 50000;
        david.happiness += 10;
        lisa.happiness += 10;
    }

    if (current_month == 2 && current_year == 2025) {
        std::cout << "\n💕 ДЕНЬ СВЯТОГО ВАЛЕНТИНА" << std::endl;
        david.bank.checking -= 30000;
        lisa.bank.checking += 30000;
        lisa.happiness += 15;
    }

    if (current_month == 3 && current_year == 2025) {
        std::cout << "\n💍 ГОДОВЩИНА СВАДЬБЫ!" << std::endl;
        david.bank.checking -= 50000;
        lisa.bank.checking += 50000;
        david.happiness += 20;
        lisa.happiness += 20;
    }

    if (current_month == 6 && current_year == 2025) {
        std::cout << "\n🏦 КРИЗИС НА РЫНКЕ!" << std::endl;
        david.invest.stocks *= 0.8;
        david.invest.crypto *= 0.5;
        lisa.invest.crypto *= 0.5;
        inflation += 0.02;
        market_crashes.push_back(202506);
    }

    if (current_month == 9 && current_year == 2025 && !david.has_child) {
        std::cout << "\n👶 У ДЭВИДА И ЛИЗЫ РОДИЛСЯ РЕБЕНОК!" << std::endl;
        david.has_child = true;
        lisa.has_child = true;
        david.children_count = 1;
        lisa.children_count = 1;
        david.bank.checking -= 200000;
        lisa.bank.checking -= 100000;
        david.happiness += 50;
        lisa.happiness += 50;
    }

    if (current_month == 12 && current_year == 2025) {
        std::cout << "\n🎄 НОВОГОДНИЕ ПРАЗДНИКИ" << std::endl;
        david.bank.checking -= 150000;
        lisa.bank.checking -= 100000;
        david.happiness += 25;
        lisa.happiness += 25;
    }
}

void calculate_net_worth() {
    david.total_assets = david.bank.checking + david.bank.savings + david.bank.deposite +
        david.bank.eur_account * david.bank.eur_rate +
        david.bank.usd_account * david.bank.usd_rate +
        david.bank.gbp_account * david.bank.gbp_rate +
        david.bank.cny_account * david.bank.cny_rate +
        david.bank.cash + david.bank.safe_deposit +
        david.realty.apartment_value + david.realty.house_value +
        david.realty.cottage_value + david.realty.land_value +
        david.realty.commercial_value + david.realty.furniture +
        david.realty.appliances +
        david.transport.car1_value + david.transport.car2_value +
        david.transport.motorcycle_value + david.transport.bicycle_value +
        david.transport.boat_value +
        david.invest.stocks + david.invest.bonds + david.invest.etf +
        david.invest.crypto + david.invest.gold + david.invest.silver +
        david.invest.art + david.invest.business_share +
        david.business.own_business;

    for (auto& crypto : david.bank.crypto_wallet) {
        if (crypto.first == "BTC") david.total_assets += crypto.second * 5000000;
        if (crypto.first == "ETH") david.total_assets += crypto.second * 300000;
    }

    david.total_debts = david.bank.credit_card_debt + david.debts.mortgage +
        david.debts.car_loan + david.debts.student_loan +
        david.debts.personal_loan + david.debts.business_loan;

    david.net_worth = david.total_assets - david.total_debts;
    david.monthly_savings = david.salary - (david.food.groceries + david.realty.utilities +
        david.transport.gas_monthly + david.fun.entertainment);

    lisa.total_assets = lisa.bank.checking + lisa.bank.savings +
        lisa.bank.eur_account * lisa.bank.eur_rate +
        lisa.bank.cash +
        lisa.realty.apartment_value + lisa.realty.furniture +
        lisa.transport.car1_value +
        lisa.invest.crypto + lisa.invest.gold;

    lisa.total_debts = lisa.bank.credit_card_debt + lisa.debts.mortgage +
        lisa.debts.car_loan + lisa.debts.student_loan +
        lisa.debts.credit_line;

    lisa.net_worth = lisa.total_assets - lisa.total_debts;
    lisa.monthly_savings = lisa.salary - (lisa.food.groceries + lisa.realty.utilities +
        lisa.transport.gas_monthly + lisa.fun.entertainment +
        lisa.debts.mortgage + lisa.debts.car_loan);
}

void print_detailed_status() {
    std::cout << "\n" << std::string(100, '=') << std::endl;
    std::cout << "📊 ДЕТАЛЬНЫЙ ОТЧЕТ | Месяц " << current_month << "/" << current_year << std::endl;
    std::cout << std::string(100, '=') << std::endl;

    std::cout << "\n👨 ДЭВИД - Инвестор-накопитель" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "💰 Текущий счет: " << std::fixed << std::setprecision(0) << david.bank.checking << " RUB" << std::endl;
    std::cout << "🏦 Сбережения: " << david.bank.savings << " RUB" << std::endl;
    std::cout << "📈 Депозит (" << david.bank.interest << "%): " << david.bank.deposite << " RUB" << std::endl;
    std::cout << "💶 Евро: " << david.bank.eur_account << " EUR (" << david.bank.eur_account * david.bank.eur_rate << " RUB)" << std::endl;
    std::cout << "💵 Доллары: " << david.bank.usd_account << " USD (" << david.bank.usd_account * david.bank.usd_rate << " RUB)" << std::endl;
    std::cout << "🏠 Недвижимость: " << david.realty.apartment_value << " RUB" << std::endl;
    std::cout << "🚗 Авто: " << david.transport.car1_value << " RUB (пробег " << david.transport.mileage["car1"] << " км)" << std::endl;
    std::cout << "📊 Акции: " << david.invest.stocks << " RUB" << std::endl;
    std::cout << "🪙 Крипта: " << david.invest.crypto << " RUB" << std::endl;
    std::cout << "💎 Золото: " << david.invest.gold << " RUB" << std::endl;
    std::cout << "💼 Бизнес: " << david.business.own_business << " RUB" << std::endl;
    std::cout << "😊 Счастье: " << david.happiness << "/100" << std::endl;
    std::cout << "💪 Здоровье: " << david.health_score << "/100" << std::endl;
    std::cout << "📈 Net Worth: " << david.net_worth << " RUB" << std::endl;

    std::cout << "\n👩 ЛИЗА - Гедонист-тратитель" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "💰 Текущий счет: " << lisa.bank.checking << " RUB" << std::endl;
    std::cout << "🏦 Сбережения: " << lisa.bank.savings << " RUB" << std::endl;
    std::cout << "💳 Кредитка: " << lisa.bank.credit_card_debt << " RUB (лимит " << lisa.bank.credit_limit << ")" << std::endl;
    std::cout << "🏠 Ипотека: " << lisa.debts.mortgage << " RUB (платеж " << lisa.realty.mortgage_payment << "/мес)" << std::endl;
    std::cout << "🚗 Кредит на авто: " << lisa.debts.car_loan << " RUB" << std::endl;
    std::cout << "🎓 Кредит за учебу: " << lisa.debts.student_loan << " RUB" << std::endl;
    std::cout << "💳 Кредитная линия: " << lisa.debts.credit_line << " RUB" << std::endl;
    std::cout << "🚗 Авто: " << lisa.transport.car1_value << " RUB" << std::endl;
    std::cout << "😊 Счастье: " << lisa.happiness << "/100" << std::endl;
    std::cout << "💪 Здоровье: " << lisa.health_score << "/100" << std::endl;
    std::cout << "📈 Net Worth: " << lisa.net_worth << " RUB" << std::endl;

    std::cout << "\n📊 МАКРОЭКОНОМИКА" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "📈 Инфляция: " << inflation * 100 << "% годовых" << std::endl;
    std::cout << "💵 Доллар: " << dollar_index << " RUB" << std::endl;
    std::cout << "🛢 Нефть: " << oil_price << " RUB/барр" << std::endl;
    std::cout << "🌍 Экология: " << ecology_index << "/100" << std::endl;
}

void print_comparison() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "⚖️ СРАВНЕНИЕ ПЕРСОНАЖЕЙ" << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    RUB david_monthly_income = david.salary + david.passive_income + david.business.revenue;
    RUB lisa_monthly_income = lisa.salary + lisa.side_hustle;

    RUB david_monthly_expenses = david.food.groceries + david.realty.utilities +
        david.transport.gas_monthly + david.fun.travel +
        david.subs.netflix + david.subs.spotify;

    RUB lisa_monthly_expenses = lisa.food.groceries + lisa.realty.utilities +
        lisa.transport.gas_monthly + lisa.fun.travel +
        lisa.realty.mortgage_payment + lisa.transport.loan_payment +
        lisa.subs.spotify + lisa.subs.disney_plus;

    std::cout << "Дэвид:" << std::endl;
    std::cout << "  Доходы: " << david_monthly_income << " RUB/мес" << std::endl;
    std::cout << "  Расходы: " << david_monthly_expenses << " RUB/мес" << std::endl;
    std::cout << "  Сбережения: " << david.monthly_savings << " RUB/мес" << std::endl;
    std::cout << "  Сбережения (%): " << (david.monthly_savings / david_monthly_income * 100) << "%" << std::endl;

    std::cout << "\nЛиза:" << std::endl;
    std::cout << "  Доходы: " << lisa_monthly_income << " RUB/мес" << std::endl;
    std::cout << "  Расходы: " << lisa_monthly_expenses << " RUB/мес" << std::endl;
    std::cout << "  Сбережения: " << lisa.monthly_savings << " RUB/мес" << std::endl;
    std::cout << "  Сбережения (%): " << (lisa.monthly_savings / lisa_monthly_income * 100) << "%" << std::endl;
}

void generate_report() {
    std::ofstream file("full_report.txt");
    file << "СИМУЛЯЦИЯ ЖИЗНИ ДЭВИДА И ЛИЗЫ\n";
    file << "Период: " << simulation_months << " месяцев\n";
    file << "Начало: Январь 2024\n\n";

    file << "ИТОГОВЫЙ КАПИТАЛ:\n";
    file << "Дэвид: " << david.net_worth << " RUB\n";
    file << "Лиза: " << lisa.net_worth << " RUB\n";
    file << "Разница: " << (david.net_worth - lisa.net_worth) << " RUB\n\n";

    file << "АКТИВЫ ДЭВИДА:\n";
    file << "Банк: " << david.bank.checking + david.bank.savings + david.bank.deposite << "\n";
    file << "Недвижимость: " << david.realty.apartment_value << "\n";
    file << "Инвестиции: " << david.invest.stocks + david.invest.bonds + david.invest.crypto + david.invest.gold << "\n";
    file << "Бизнес: " << david.business.own_business << "\n\n";

    file << "ДОЛГИ ЛИЗЫ:\n";
    file << "Ипотека: " << lisa.debts.mortgage << "\n";
    file << "Кредитка: " << lisa.debts.credit_line << "\n";
    file << "Автокредит: " << lisa.debts.car_loan << "\n";
    file << "Учеба: " << lisa.debts.student_loan << "\n";

    file.close();
}

int count_lines() {
    std::ifstream file(__FILE__);
    std::string line;
    int lines = 0;
    while (std::getline(file, line)) {
        lines++;
    }
    return lines;
}

int main() {
    srand(time(0));

    init_global_events();
    init_david();
    init_lisa();

    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║     СИМУЛЯЦИЯ ЖИЗНИ ДЭВИДА И ЛИЗЫ (НАКОПИТЕЛЬ VS ТРАТИТЕЛЬ)    ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n\n";

    std::cout << "Период: " << simulation_months << " месяцев" << std::endl;
    std::cout << "Инфляция: " << inflation * 100 << "% годовых" << std::endl;
    std::cout << "Код содержит: " << count_lines() << " строк\n" << std::endl;

    for (int i = 0; i < simulation_months; i++) {
        current_month = (i % 12) + 1;
        if (i > 0 && current_month == 1) current_year++;

        if (i % 12 == 0) {
            std::cout << "\n📅 НАЧАЛО " << current_year << " ГОДА" << std::endl;
        }

        david.bank.checking += david.salary;
        david.bank.checking += david.passive_income;
        david.bank.checking += david.business.revenue;
        david.bank.savings += david.bank.savings * (david.bank.interest / 100 / 12);
        david.bank.deposite += david.bank.deposite * (david.bank.interest / 100 / 12);

        lisa.bank.checking += lisa.salary;
        lisa.bank.checking += lisa.side_hustle;
        lisa.bank.savings += lisa.bank.savings * (lisa.bank.interest / 100 / 12);

        david.food.groceries = 30000 + (rand() % 10000);
        david.food.restaurant = 10000 + (rand() % 10000);
        david.food.coffee = 3000 + (rand() % 2000);
        david.bank.checking -= (david.food.groceries + david.food.restaurant + david.food.coffee);

        lisa.food.groceries = 20000 + (rand() % 10000);
        lisa.food.restaurant = 15000 + (rand() % 10000);
        lisa.food.coffee = 4000 + (rand() % 3000);
        lisa.bank.checking -= (lisa.food.groceries + lisa.food.restaurant + lisa.food.coffee);

        david.bank.checking -= david.realty.utilities;
        david.bank.checking -= david.realty.property_tax / 12;
        david.bank.checking -= david.transport.gas_monthly;
        david.bank.checking -= david.transport.insurance;
        david.bank.checking -= david.subs.netflix + david.subs.spotify + david.subs.chatgpt;

        lisa.bank.checking -= lisa.realty.utilities;
        lisa.bank.checking -= lisa.realty.mortgage_payment;
        lisa.bank.checking -= lisa.transport.gas_monthly;
        lisa.bank.checking -= lisa.transport.insurance;
        lisa.bank.checking -= lisa.transport.loan_payment;
        lisa.bank.checking -= lisa.subs.spotify + lisa.subs.disney_plus;

        lisa.bank.credit_card_debt += lisa.bank.credit_card_debt * 0.02;

        if (david.bank.checking > 200000) {
            RUB invest_amount = david.bank.checking * 0.3;
            david.invest.stocks += invest_amount * 0.4;
            david.invest.bonds += invest_amount * 0.3;
            david.invest.etf += invest_amount * 0.2;
            david.invest.gold += invest_amount * 0.1;
            david.bank.checking -= invest_amount;
        }

        market_simulation();
        economic_crisis();

        random_events(david, true);
        random_events(lisa, false);
        special_events();

        if (lisa.bank.checking < 0) {
            lisa.bank.credit_card_debt += abs(lisa.bank.checking);
            lisa.bank.checking = 0;
        }

        david.invest.stocks += david.invest.stocks * 0.01;
        david.invest.bonds += david.invest.bonds * 0.005;
        david.invest.gold += david.invest.gold * 0.008;

        david.happiness = std::min(100, david.happiness + (rand() % 5) - 2);
        lisa.happiness = std::min(100, lisa.happiness + (rand() % 10) - 3);

        david.health_score = std::min(100, david.health_score + (rand() % 3) - 1);
        lisa.health_score = std::min(100, lisa.health_score + (rand() % 4) - 2);

        david.transport.mileage["car1"] += 1000 + (rand() % 1000);
        lisa.transport.mileage["car1"] += 800 + (rand() % 800);

        calculate_net_worth();

        if (i % 3 == 0 || i == simulation_months - 1) {
            print_detailed_status();
            print_comparison();
        }

        if (i == simulation_months - 1) {
            std::cout << "\n" << std::string(100, '=') << std::endl;
            std::cout << "🏁 ФИНАЛЬНЫЙ РЕЗУЛЬТАТ ПОСЛЕ " << simulation_months << " МЕСЯЦЕВ" << std::endl;
            std::cout << std::string(100, '=') << std::endl;
            print_detailed_status();
            print_comparison();

            std::cout << "\n📊 ИТОГОВАЯ СТАТИСТИКА:" << std::endl;
            std::cout << "Дэвид накопил: " << david.net_worth << " RUB" << std::endl;
            std::cout << "Лиза в долгах: " << lisa.total_debts << " RUB" << std::endl;
            std::cout << "Разница в капитале: " << (david.net_worth - lisa.net_worth) << " RUB" << std::endl;

            if (david.net_worth > lisa.net_worth) {
                std::cout << "\n🏆 Дэвид - чемпион по накоплению капитала!" << std::endl;
                std::cout << "💡 Мораль: Инвестиции и сбережения побеждают гедонизм" << std::endl;
            }
            else {
                std::cout << "\n🏆 Лиза счастливее, хоть и в долгах!" << std::endl;
                std::cout << "💡 Мораль: Деньги - не главное в жизни" << std::endl;
            }
        }

        david.salary *= (1 + inflation / 12);
        lisa.salary *= (1 + inflation / 12);
        david.realty.apartment_value *= (1 + inflation / 12 / 2);
        david.transport.gas_monthly *= (1 + inflation / 12);
        lisa.transport.gas_monthly *= (1 + inflation / 12);
    }

    generate_report();

    std::cout << "\n📁 Полный отчет сохранен в full_report.txt" << std::endl;
    std::cout << "📊 Финальный код содержит " << count_lines() << " строк" << std::endl;

    return 0;
}