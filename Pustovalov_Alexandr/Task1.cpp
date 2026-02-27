#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <array>

using namespace std;

using Percent = float;

using RUB = double;
using USD = double;
using BTC = double;

const std::array<double, 20> BTC_RATES = {
    65000.0, 58000.0, 45000.0, 30000.0, 35000.0, 50000.0, 69000.0, 80000.0,
    75000.0, 60000.0, 40000.0, 20000.0, 25000.0, 40000.0, 90000.0, 120000.0,
    100000.0, 85000.0, 70000.0, 150000.0
};

struct Economy {
    Percent inflation;
    double rate_usd_rub;
    int avg_salary;
    USD life_last_cost;

    bool crisis;
};

struct StockPortfolio {
    double russian_stocks;
    double us_stocks;
    double bonds;
    double index_fund;
};

struct StockMarket {
    double russian_index;
    double sp500;
    double bond_yield;
};

struct Car {
    RUB value;
    RUB gas;
    RUB yearly_tax;
};

struct Crypto {
    BTC balance;
    double exchange_rate_usd;
};

struct Loan {
    RUB body_debt;
    RUB monthly_payment;
    Percent interest_rate;
    bool is_active;
    int missed_payments;
};

struct Bank {
    RUB account_rub;
    USD account_usd;

    Loan mortgage;
    Loan consumer_credit;
    short credit_score;
};

struct Housing {
    RUB value;
    RUB rent;
    RUB monthly_utilities;
};

struct Health {
    RUB medicine_expenses;
    short happiness;
    short physical_health;
    short age;
    short max_age;
    short stress;
    bool is_alive;
};

struct Education {
    short degree_level;
    bool is_studying;
    RUB tuition_fee;
    int months_remaining;
    bool higher_education;
    short skill_level;
};

struct Family {
    bool has_partner;
    bool has_parents;
    short children_amount;
    RUB child_expences;
};

enum HobbyType {
    HOBBY_NONE = 0,
    HOBBY_GYM = 1,
    HOBBY_GAMING = 2,
    HOBBY_READING = 3,
    HOBBY_MUSIC = 4,
    HOBBY_PHOTOGRAPHY = 5,
    HOBBY_COOKING = 6,
    HOBBY_GARDENING = 7,
    HOBBY_SPORTS = 8,
    HOBBY_ART = 9,
    HOBBY_COLLECTING = 10
};

struct Hobby {
    HobbyType type;
    const char* name;
    RUB monthly_cost;
    RUB equipment_cost;
    short skill_level;
    short happiness_bonus;
    short stress_reduction;
    short health_bonus;
    bool is_active;
    int months_practiced;
};

struct Entertainment {
    bool has_streaming_subscription;
    RUB streaming_cost;

    bool has_gym_membership;
    RUB gym_membership_cost;

    bool plays_video_games;
    RUB gaming_monthly_cost;

    short theater_visits_per_year;
    short concert_visits_per_year;
    short museum_visits_per_year;
    RUB cultural_budget;

    short countries_visited;
    short trips_per_year;
    RUB travel_budget;
    bool prefers_luxury_travel;

    short restaurant_visits_per_month;
    short bar_visits_per_month;
    RUB social_entertainment_budget;

    short entertainment_satisfaction;
    RUB total_monthly_entertainment_cost;
};

struct HobbySystem {
    Hobby hobbies[3];
    short active_hobbies_count;
    Entertainment entertainment;
    short leisure_time_hours;
    short work_life_balance;
};

struct Person {
    Bank vtb;
    Crypto crypto_account;
    StockPortfolio portfolio;

    Car car;
    Housing home;

    RUB salary;
    RUB monthly_food_cost;
    RUB monthly_lifestyle_cost;

    Education education;
    HobbySystem hobbies;
    Health health;
    Family family;

};

struct Economy russia;
struct StockMarket market = { 3000.0, 4500.0, 8.0 };

struct Person alice;
struct Person bogdan;

int year = 2026;
int month = 2;
int simulation_month_counter = 0;

int current_event_type = 0;
int event_duration = 0;
int event_months_active = 0;
double event_severity = 0.0;
bool event_is_active = false;

const int MAX_CREDIT_SCORE = 850;
const int MIN_CREDIT_SCORE = 300;
const int MAX_MISSED_PAYMENTS_BEFORE_BANKRUPTCY = 3;


void init_entertainment(Entertainment& ent) {
    ent.has_streaming_subscription = false;
    ent.streaming_cost = 500;

    ent.has_gym_membership = false;
    ent.gym_membership_cost = 3000;

    ent.plays_video_games = false;
    ent.gaming_monthly_cost = 2000;

    ent.theater_visits_per_year = 0;
    ent.concert_visits_per_year = 0;
    ent.museum_visits_per_year = 0;
    ent.cultural_budget = 5000;

    ent.countries_visited = 1;
    ent.trips_per_year = 0;
    ent.travel_budget = 100000;
    ent.prefers_luxury_travel = false;

    ent.restaurant_visits_per_month = 0;
    ent.bar_visits_per_month = 0;
    ent.social_entertainment_budget = 10000;

    ent.entertainment_satisfaction = 50;
    ent.total_monthly_entertainment_cost = 0;
}


void init_hobby_system(HobbySystem& sys) {
    for (int i = 0; i < 3; i++) {
        sys.hobbies[i].type = HOBBY_NONE;
        sys.hobbies[i].is_active = false;
    }
    sys.active_hobbies_count = 0;
    sys.leisure_time_hours = 20;
    sys.work_life_balance = 50;

    init_entertainment(sys.entertainment);
}


Hobby create_hobby(HobbyType type) {
    Hobby hobby;
    hobby.type = type;
    hobby.is_active = true;
    hobby.skill_level = 0;
    hobby.months_practiced = 0;

    switch (type) {
    case HOBBY_GYM:
        hobby.name = "Gym";
        hobby.monthly_cost = 3000;
        hobby.equipment_cost = 15000;
        hobby.happiness_bonus = 8;
        hobby.stress_reduction = 15;
        hobby.health_bonus = 10;
        break;

    case HOBBY_GAMING:
        hobby.name = "Gaming";
        hobby.monthly_cost = 2000;
        hobby.equipment_cost = 80000;
        hobby.happiness_bonus = 12;
        hobby.stress_reduction = 10;
        hobby.health_bonus = -2;
        break;

    case HOBBY_READING:
        hobby.name = "Reading";
        hobby.monthly_cost = 1500;
        hobby.equipment_cost = 5000;
        hobby.happiness_bonus = 6;
        hobby.stress_reduction = 12;
        hobby.health_bonus = 0;
        break;

    case HOBBY_MUSIC:
        hobby.name = "Music";
        hobby.monthly_cost = 5000;
        hobby.equipment_cost = 50000;
        hobby.happiness_bonus = 15;
        hobby.stress_reduction = 20;
        hobby.health_bonus = 2;
        break;

    case HOBBY_PHOTOGRAPHY:
        hobby.name = "Photography";
        hobby.monthly_cost = 3000;
        hobby.equipment_cost = 100000;
        hobby.happiness_bonus = 10;
        hobby.stress_reduction = 8;
        hobby.health_bonus = 3;
        break;

    case HOBBY_COOKING:
        hobby.name = "Cooking";
        hobby.monthly_cost = 8000;
        hobby.equipment_cost = 30000;
        hobby.happiness_bonus = 10;
        hobby.stress_reduction = 12;
        hobby.health_bonus = 5;
        break;

    case HOBBY_GARDENING:
        hobby.name = "Gardening";
        hobby.monthly_cost = 2000;
        hobby.equipment_cost = 20000;
        hobby.happiness_bonus = 8;
        hobby.stress_reduction = 18;
        hobby.health_bonus = 5;
        break;

    case HOBBY_SPORTS:
        hobby.name = "Sports";
        hobby.monthly_cost = 5000;
        hobby.equipment_cost = 25000;
        hobby.happiness_bonus = 12;
        hobby.stress_reduction = 15;
        hobby.health_bonus = 15;
        break;

    case HOBBY_ART:
        hobby.name = "Art";
        hobby.monthly_cost = 4000;
        hobby.equipment_cost = 20000;
        hobby.happiness_bonus = 14;
        hobby.stress_reduction = 18;
        hobby.health_bonus = 0;
        break;

    case HOBBY_COLLECTING:
        hobby.name = "Collecting";
        hobby.monthly_cost = 10000;
        hobby.equipment_cost = 50000;
        hobby.happiness_bonus = 8;
        hobby.stress_reduction = 5;
        hobby.health_bonus = 0;
        break;

    default:
        hobby.name = "None";
        hobby.monthly_cost = 0;
        hobby.equipment_cost = 0;
        hobby.happiness_bonus = 0;
        hobby.stress_reduction = 0;
        hobby.health_bonus = 0;
        hobby.is_active = false;
    }

    return hobby;
}


RUB get_total_portfolio_value(Person& person) {
    return (RUB)(person.portfolio.russian_stocks +
        person.portfolio.us_stocks * russia.rate_usd_rub +
        person.portfolio.bonds +
        person.portfolio.index_fund);
}


RUB calculate_max_loan_amount(Person& person)
{
    if (person.vtb.credit_score < 400) return 0;

    double credit_multiplier = (double)(person.vtb.credit_score - 300) / 550.0;
    RUB max_loan = (RUB)(person.salary * 12 * credit_multiplier);

    if (person.vtb.consumer_credit.is_active) {
        max_loan -= person.vtb.consumer_credit.body_debt;
    }
    if (person.vtb.mortgage.is_active) {
        max_loan -= person.vtb.mortgage.body_debt / 5;
    }

    return fmax(0, max_loan);
}


Percent calculate_loan_interest_rate(Person& person)
{
    Percent base_rate = russia.crisis ? 25.0f : 15.0f;

    Percent credit_adjustment = (750.0f - person.vtb.credit_score) / 50.0f;

    return fmax(10.0f, fmin(40.0f, base_rate + credit_adjustment));
}


bool take_consumer_credit(Person& person, RUB amount)
{
    if (person.vtb.consumer_credit.is_active) {

        RUB total_debt = person.vtb.consumer_credit.body_debt + amount;
        RUB max_allowed = calculate_max_loan_amount(person) + person.vtb.consumer_credit.body_debt;

        if (total_debt > max_allowed) {
            return false;
        }

        person.vtb.consumer_credit.body_debt = total_debt;
        person.vtb.consumer_credit.interest_rate = calculate_loan_interest_rate(person);

        double monthly_rate = person.vtb.consumer_credit.interest_rate / 1200.0;
        double annuity_coef = (monthly_rate * pow(1 + monthly_rate, 36)) /
            (pow(1 + monthly_rate, 36) - 1);
        person.vtb.consumer_credit.monthly_payment = (RUB)(total_debt * annuity_coef);
    }
    else {
        RUB max_loan = calculate_max_loan_amount(person);

        if (amount > max_loan) {
            return false;
        }

        person.vtb.consumer_credit.is_active = true;
        person.vtb.consumer_credit.body_debt = amount;
        person.vtb.consumer_credit.interest_rate = calculate_loan_interest_rate(person);
        person.vtb.consumer_credit.missed_payments = 0;

        double monthly_rate = person.vtb.consumer_credit.interest_rate / 1200.0;
        double annuity_coef = (monthly_rate * pow(1 + monthly_rate, 36)) /
            (pow(1 + monthly_rate, 36) - 1);
        person.vtb.consumer_credit.monthly_payment = (RUB)(amount * annuity_coef);

    }

    person.vtb.account_rub += amount;
    person.vtb.credit_score -= 10;
    person.health.stress += 15;

    return true;
}


bool try_spend(Person& person, RUB amount)
{
    if (amount <= 0) return true;

    if (person.vtb.account_rub >= amount) {
        person.vtb.account_rub -= amount;
        return true;
    }

    RUB deficit = amount - person.vtb.account_rub;

    if (person.vtb.account_usd > 0) {
        USD usd_needed = (USD)ceil((double)deficit / russia.rate_usd_rub);
        USD usd_to_use = fmin(usd_needed, person.vtb.account_usd);

        person.vtb.account_rub += (RUB)(usd_to_use * russia.rate_usd_rub);
        person.vtb.account_usd -= usd_to_use;

        if (person.vtb.account_rub >= amount) {
            person.vtb.account_rub -= amount;
            return true;
        }
    }

    deficit = amount - person.vtb.account_rub;

    if (person.crypto_account.balance > 0.0001) {
        double crypto_rub_value = person.crypto_account.balance *
            person.crypto_account.exchange_rate_usd *
            russia.rate_usd_rub;

        if (crypto_rub_value >= deficit) {
            double btc_to_sell = deficit / (person.crypto_account.exchange_rate_usd *
                russia.rate_usd_rub);
            person.crypto_account.balance -= btc_to_sell;
            person.vtb.account_rub += deficit;
        }
        else {
            person.vtb.account_rub += (RUB)crypto_rub_value;
            person.crypto_account.balance = 0;
        }

        if (person.vtb.account_rub >= amount) {
            person.vtb.account_rub -= amount;
            return true;
        }
    }

    deficit = amount - person.vtb.account_rub;
    RUB portfolio_value = get_total_portfolio_value(person);

    if (portfolio_value > 0) {
        double sell_ratio = fmin(1.0, (double)deficit / portfolio_value);

        person.vtb.account_rub += (RUB)(person.portfolio.russian_stocks * sell_ratio);
        person.vtb.account_rub += (RUB)(person.portfolio.us_stocks * russia.rate_usd_rub * sell_ratio);
        person.vtb.account_rub += (RUB)(person.portfolio.bonds * sell_ratio);
        person.vtb.account_rub += (RUB)(person.portfolio.index_fund * sell_ratio);

        person.portfolio.russian_stocks *= (1.0 - sell_ratio);
        person.portfolio.us_stocks *= (1.0 - sell_ratio);
        person.portfolio.bonds *= (1.0 - sell_ratio);
        person.portfolio.index_fund *= (1.0 - sell_ratio);

        if (person.vtb.account_rub >= amount) {
            person.vtb.account_rub -= amount;
            return true;
        }
    }

    deficit = amount - person.vtb.account_rub;

    RUB credit_amount = (RUB)(deficit * 1.2);
    credit_amount = fmax(credit_amount, 50000);

    if (take_consumer_credit(person, credit_amount)) {
        if (person.vtb.account_rub >= amount) {
            person.vtb.account_rub -= amount;
            return true;
        }
    }

    person.vtb.account_rub = 0;
    person.health.stress += 40;

    return false;
}


bool start_new_hobby(Person& person, HobbyType type) {

    if (person.hobbies.active_hobbies_count >= 3) {
        return false;
    }

    for (int i = 0; i < 3; i++) {
        if (person.hobbies.hobbies[i].type == type &&
            person.hobbies.hobbies[i].is_active) {
            return false;
        }
    }

    Hobby new_hobby = create_hobby(type);

    if (!try_spend(person, new_hobby.equipment_cost)) {
        return false;
    }

    for (int i = 0; i < 3; i++) {
        if (!person.hobbies.hobbies[i].is_active) {
            person.hobbies.hobbies[i] = new_hobby;
            person.hobbies.active_hobbies_count++;
            person.health.happiness += 10;
            return true;
        }
    }

    return false;
}


void init()
{
    srand(time(NULL));
    // Global
    russia.rate_usd_rub = 76.75;
    russia.inflation = 5.59;
    russia.avg_salary = 96'772;
    russia.life_last_cost = 100'000.0;
    russia.crisis = false;

    current_event_type = 0;
    event_is_active = false;
    event_duration = 0;
    event_months_active = 0;
    event_severity = 0.0;

    // Alice
    alice.salary = 200'000;
    alice.vtb.account_rub = 150'000;
    alice.vtb.account_usd = 0;
    alice.vtb.consumer_credit.is_active = false;
    alice.vtb.consumer_credit.missed_payments = 0;
    alice.vtb.consumer_credit.body_debt = 0;
    alice.vtb.consumer_credit.monthly_payment = 0;
    alice.vtb.consumer_credit.interest_rate = 0;

    alice.vtb.mortgage.is_active = true;
    alice.vtb.mortgage.body_debt = 8'000'000;
    alice.vtb.mortgage.monthly_payment = 90'000;
    alice.vtb.mortgage.interest_rate = 8.0;
    alice.vtb.mortgage.missed_payments = 0;

    alice.vtb.credit_score = 700;

    alice.portfolio.russian_stocks = 0;
    alice.portfolio.us_stocks = 0;
    alice.portfolio.bonds = 0;
    alice.portfolio.index_fund = 0;

    alice.crypto_account.balance = 0.0;
    alice.crypto_account.exchange_rate_usd = BTC_RATES[0];

    alice.car.value = 2'500'000;
    alice.car.gas = 12'000;
    alice.car.yearly_tax = 4'000;

    init_hobby_system(alice.hobbies);
    alice.hobbies.entertainment.has_streaming_subscription = true;
    alice.hobbies.entertainment.restaurant_visits_per_month = 2;
    alice.hobbies.entertainment.trips_per_year = 1;
    alice.hobbies.entertainment.theater_visits_per_year = 2;
    alice.hobbies.leisure_time_hours = 15;

    start_new_hobby(alice, HOBBY_READING);

    alice.home.value = 15'000'000;
    alice.home.rent = 0;
    alice.home.monthly_utilities = 4'000;

    alice.monthly_food_cost = 25'000;
    alice.monthly_lifestyle_cost = 30'000;

    alice.education.degree_level = 1;
    alice.education.is_studying = true;
    alice.education.tuition_fee = 0;
    alice.education.months_remaining = 30;
    alice.education.skill_level = 10;
    alice.education.higher_education = true;

    alice.health.medicine_expenses = 20'000;
    alice.health.happiness = 85;
    alice.health.physical_health = 90;
    alice.health.age = 20;
    alice.health.max_age = 80;
    alice.health.stress = 10;
    alice.health.is_alive = true;
    alice.family = { false, true, 0, 30'000 };

    // Bogdan
    bogdan.salary = 300'000;
    bogdan.vtb.account_rub = 50'000;
    bogdan.vtb.account_usd = 10'000;
    bogdan.vtb.consumer_credit.is_active = false;
    bogdan.vtb.consumer_credit.missed_payments = 0;
    bogdan.vtb.consumer_credit.body_debt = 0;
    bogdan.vtb.consumer_credit.monthly_payment = 0;
    bogdan.vtb.consumer_credit.interest_rate = 0;

    bogdan.vtb.mortgage.is_active = false;

    bogdan.vtb.credit_score = 650;

    bogdan.portfolio.russian_stocks = 0;
    bogdan.portfolio.us_stocks = 0;
    bogdan.portfolio.bonds = 0;
    bogdan.portfolio.index_fund = 0;

    bogdan.crypto_account.balance = 1.5;
    bogdan.crypto_account.exchange_rate_usd = BTC_RATES[0];

    bogdan.car.value = 0;
    bogdan.car.gas = 0;
    bogdan.car.yearly_tax = 0;

    init_hobby_system(bogdan.hobbies);
    bogdan.hobbies.entertainment.has_gym_membership = true;
    bogdan.hobbies.entertainment.plays_video_games = true;
    bogdan.hobbies.entertainment.bar_visits_per_month = 2;
    bogdan.hobbies.entertainment.trips_per_year = 2;
    bogdan.hobbies.entertainment.prefers_luxury_travel = true;
    bogdan.hobbies.leisure_time_hours = 10;  // less time because of work

    start_new_hobby(bogdan, HOBBY_GAMING);
    start_new_hobby(bogdan, HOBBY_SPORTS);

    bogdan.home.value = 0;
    bogdan.home.rent = 50'000;
    bogdan.home.monthly_utilities = 5'000;

    bogdan.monthly_food_cost = 60'000; //healthy food
    bogdan.monthly_lifestyle_cost = 20'000;

    bogdan.education.degree_level = 1;
    bogdan.education.is_studying = true;
    bogdan.education.tuition_fee = 0;
    bogdan.education.months_remaining = 30;
    bogdan.education.skill_level = 20;
    bogdan.education.higher_education = true;

    bogdan.health.medicine_expenses = 30'000;
    bogdan.health.happiness = 70;
    bogdan.health.physical_health = 95;
    bogdan.health.age = 20;
    bogdan.health.max_age = 80;
    bogdan.health.stress = 20;
    bogdan.health.is_alive = true;
    bogdan.family = { false, true, 0, 40'000 };

}


double get_random(double min, double max)
{
    return min + (double)(rand()) / ((double)(RAND_MAX / (max - min)));
}


void crypto_rates_update()
{
    int index = simulation_month_counter % 20;
    double current_rate = BTC_RATES[index];
    double noise = get_random(-2000.0, 2000.0);

    alice.crypto_account.exchange_rate_usd = current_rate + noise;
    bogdan.crypto_account.exchange_rate_usd = current_rate + noise;
}


void stock_market_update() {
    double ru_change = get_random(-5.0, 5.0);
    double us_change = get_random(-3.0, 3.0);

    if (event_is_active) {
        if (current_event_type == 1 || current_event_type == 8 || current_event_type == 13) {
            // Crisis events
            ru_change -= 10.0 * event_severity;
            us_change -= 8.0 * event_severity;
        }
        else if (current_event_type == 4 || current_event_type == 17) {
            // Growth events
            ru_change += 5.0 * event_severity;
            us_change += 7.0 * event_severity;
        }
        else if (current_event_type == 11) {
            // Sanctions
            ru_change -= 15.0 * event_severity;
        }
    }

    market.russian_index *= (1.0 + ru_change / 100.0);
    market.sp500 *= (1.0 + us_change / 100.0);

    market.russian_index = fmax(500.0, fmin(10000.0, market.russian_index));
    market.sp500 = fmax(1000.0, fmin(15000.0, market.sp500));

    if (russia.crisis) {
        market.bond_yield = 15.0 + get_random(0, 5);
    }
    else {
        market.bond_yield = 7.0 + get_random(-1, 3);
    }
}


void quit_hobby(Person& person, int hobby_index) {
    if (hobby_index < 0 || hobby_index >= 3) return;
    if (!person.hobbies.hobbies[hobby_index].is_active) return;

    person.hobbies.hobbies[hobby_index].is_active = false;
    person.hobbies.hobbies[hobby_index].type = HOBBY_NONE;
    person.hobbies.active_hobbies_count--;

    person.health.happiness -= 3;
}


void practice_hobbies(Person& person) {
    for (int i = 0; i < 3; i++) {
        Hobby& hobby = person.hobbies.hobbies[i];

        if (!hobby.is_active) continue;

        if (!try_spend(person, hobby.monthly_cost)) {
            quit_hobby(person, i);
            continue;
        }

        hobby.months_practiced++;
        if (hobby.skill_level < 100) {
            hobby.skill_level += 1;
            if (hobby.skill_level > 100) hobby.skill_level = 100;
        }

        double skill_multiplier = 0.5 + (hobby.skill_level / 200.0);

        short happiness_gain = (short)(hobby.happiness_bonus * skill_multiplier);
        short stress_reduction = (short)(hobby.stress_reduction * skill_multiplier);
        short health_change = (short)(hobby.health_bonus * skill_multiplier);

        person.health.happiness += happiness_gain / 4;
        person.health.stress -= stress_reduction / 4;
        person.health.physical_health += health_change / 12;

        person.health.happiness = fmin(100, fmax(0, person.health.happiness));
        person.health.stress = fmin(100, fmax(0, person.health.stress));
        person.health.physical_health = fmin(100, fmax(0, person.health.physical_health));
    }
}


void hobby_random_events(Person& person) {
    for (int i = 0; i < 3; i++) {
        Hobby& hobby = person.hobbies.hobbies[i];
        if (!hobby.is_active) continue;

        double event_chance = get_random(0, 1000);

        if (event_chance < 5 && hobby.skill_level > 50) {
            person.health.happiness += 15;

            if (hobby.skill_level > 80) {
                RUB hobby_income = (RUB)(hobby.skill_level * 100);
                person.vtb.account_rub += hobby_income;
            }
        }

        if (event_chance > 998 &&
            (hobby.type == HOBBY_GYM || hobby.type == HOBBY_SPORTS)) {
            person.health.physical_health -= 15;
            person.health.medicine_expenses += 20000;
            hobby.is_active = false;
        }

        if (event_chance > 995 && event_chance <= 998) {
            if (hobby.months_practiced > 24 && get_random(0, 100) < 30) {
                quit_hobby(person, i);
            }
        }
    }
}


void consider_new_hobby(Person& person) {
    if (person.hobbies.active_hobbies_count >= 3) return;
    if (get_random(0, 100) > 2) return;

    HobbyType new_type = (HobbyType)((int)get_random(1, 10));

    Hobby potential = create_hobby(new_type);

    double total_wealth = person.vtb.account_rub +
        person.vtb.account_usd * russia.rate_usd_rub;

    if (total_wealth > potential.equipment_cost * 3) {
        if (start_new_hobby(person, new_type)) {
        }
    }
}


void manage_streaming(Person& person) {
    Entertainment& ent = person.hobbies.entertainment;

    if (ent.has_streaming_subscription) {
        if (try_spend(person, ent.streaming_cost)) {
            person.health.happiness += 1;
            person.health.stress -= 1;
        }
        else {
            ent.has_streaming_subscription = false;
        }
    }
    else {
        if (get_random(0, 100) < 5 && person.vtb.account_rub > 50000) {
            ent.has_streaming_subscription = true;
        }
    }
}


void manage_gym_membership(Person& person) {
    Entertainment& ent = person.hobbies.entertainment;

    if (ent.has_gym_membership) {
        if (try_spend(person, ent.gym_membership_cost)) {
            int visit_chance = 70 - person.health.stress;
            if (get_random(0, 100) < visit_chance) {
                person.health.physical_health += 2;
                person.health.stress -= 3;
                person.health.happiness += 2;
            }
        }
        else {
            ent.has_gym_membership = false;
        }
    }
    else {
        if (person.health.physical_health < 60 && get_random(0, 100) < 10) {
            if (person.vtb.account_rub > 30000) {
                ent.has_gym_membership = true;
                printf("Got gym membership!\n");
            }
        }
    }

    person.health.physical_health = fmin(100, person.health.physical_health);
    person.health.stress = fmax(0, person.health.stress);
}


void cultural_activities(Person& person, const int month) {
    Entertainment& ent = person.hobbies.entertainment;

    if (month == 3 || month == 6 || month == 9 || month == 12) {
        // Театр
        if (ent.theater_visits_per_year > 0 && get_random(0, 4) < 1) {
            RUB theater_cost = (RUB)get_random(2000, 8000);
            if (try_spend(person, theater_cost)) {
                person.health.happiness += 5;
                person.health.stress -= 3;
                ent.entertainment_satisfaction += 2;
            }
        }

        if (ent.concert_visits_per_year > 0 && get_random(0, 4) < 1) {
            RUB concert_cost = (RUB)get_random(3000, 15000);
            if (try_spend(person, concert_cost)) {
                person.health.happiness += 8;
                person.health.stress -= 5;
                ent.entertainment_satisfaction += 3;
            }
        }

        if (ent.museum_visits_per_year > 0 && get_random(0, 4) < 1) {
            RUB museum_cost = (RUB)get_random(500, 2000);
            if (try_spend(person, museum_cost)) {
                person.health.happiness += 3;
                ent.entertainment_satisfaction += 1;
            }
        }
    }
}


void social_entertainment(Person& person) {
    Entertainment& ent = person.hobbies.entertainment;

    if (ent.restaurant_visits_per_month > 0) {
        for (int i = 0; i < ent.restaurant_visits_per_month; i++) {
            RUB restaurant_cost = (RUB)get_random(2000, 5000);
            if (try_spend(person, restaurant_cost)) {
                person.health.happiness += 3;
                if (person.family.has_partner) {
                    person.health.happiness += 2;
                }
            }
        }
    }

    if (ent.bar_visits_per_month > 0 && person.health.age < 45) {
        for (int i = 0; i < ent.bar_visits_per_month; i++) {
            RUB bar_cost = (RUB)get_random(3000, 8000);
            if (try_spend(person, bar_cost)) {
                person.health.happiness += 4;
                person.health.stress -= 5;
                if (get_random(0, 100) < 20) {
                    person.health.physical_health -= 1;
                }
            }
        }
    }
}


void travel_vacation(Person& person) {
    Entertainment& ent = person.hobbies.entertainment;

    if (month == 7 || month == 8 || month == 1) {
        if (ent.trips_per_year > 0 && get_random(0, 3) < 1) {
            RUB travel_cost = ent.travel_budget;

            if (ent.prefers_luxury_travel) {
                travel_cost *= 2.5;
            }

            if (person.family.has_partner) {
                travel_cost *= 1.8;
            }
            travel_cost += person.family.children_amount * (ent.travel_budget * 0.5);

            if (try_spend(person, travel_cost)) {
                bool international = get_random(0, 100) < 40;

                if (international) {
                    ent.countries_visited++;
                    person.health.happiness += 20;
                    person.health.stress -= 25;
                }
                else {
                    person.health.happiness += 12;
                    person.health.stress -= 15;
                }

                person.health.physical_health += 5;
                person.health.physical_health = fmin(100, person.health.physical_health);

                ent.entertainment_satisfaction += 10;
            }
        }
    }
}


void update_entertainment_satisfaction(Person& person) {
    Entertainment& ent = person.hobbies.entertainment;

    ent.entertainment_satisfaction -= 1;

    if (ent.has_streaming_subscription) ent.entertainment_satisfaction += 1;
    if (ent.has_gym_membership) ent.entertainment_satisfaction += 2;
    if (person.hobbies.active_hobbies_count > 0) {
        ent.entertainment_satisfaction += person.hobbies.active_hobbies_count * 2;
    }

    ent.entertainment_satisfaction = fmin(100, fmax(0, ent.entertainment_satisfaction));

    if (ent.entertainment_satisfaction < 30) {
        person.health.happiness -= 2;
        person.health.stress += 2;
    }
    else if (ent.entertainment_satisfaction > 70) {
        person.health.happiness += 1;
    }
}


void calculate_entertainment_costs(Person& person) {
    Entertainment& ent = person.hobbies.entertainment;

    ent.total_monthly_entertainment_cost = 0;

    if (ent.has_streaming_subscription) {
        ent.total_monthly_entertainment_cost += ent.streaming_cost;
    }
    if (ent.has_gym_membership) {
        ent.total_monthly_entertainment_cost += ent.gym_membership_cost;
    }
    if (ent.plays_video_games) {
        ent.total_monthly_entertainment_cost += ent.gaming_monthly_cost;
    }

    for (int i = 0; i < 3; i++) {
        if (person.hobbies.hobbies[i].is_active) {
            ent.total_monthly_entertainment_cost +=
                person.hobbies.hobbies[i].monthly_cost;
        }
    }
}


void adjust_entertainment_for_age(Person& person) {
    Entertainment& ent = person.hobbies.entertainment;
    short age = person.health.age;

    if (age < 30) {
        ent.bar_visits_per_month = fmin(4, ent.bar_visits_per_month);
        ent.concert_visits_per_year = fmax(ent.concert_visits_per_year, 2);
    }

    if (age >= 35 && age < 55) {
        ent.theater_visits_per_year = fmax(ent.theater_visits_per_year, 2);
        ent.museum_visits_per_year = fmax(ent.museum_visits_per_year, 3);
        ent.bar_visits_per_month = fmin(1, ent.bar_visits_per_month);
    }

    if (age >= 55) {
        ent.bar_visits_per_month = 0;
        ent.prefers_luxury_travel = true;

        for (int i = 0; i < 3; i++) {
            if (person.hobbies.hobbies[i].type == HOBBY_SPORTS ||
                person.hobbies.hobbies[i].type == HOBBY_GYM) {
                if (get_random(0, 100) < 5) {
                    quit_hobby(person, i);
                }
            }
        }
    }
}


void process_hobbies_and_entertainment(Person& person, const int month) {
    // Hobby
    practice_hobbies(person);
    hobby_random_events(person);
    consider_new_hobby(person);

    // Joy
    manage_streaming(person);
    manage_gym_membership(person);
    cultural_activities(person, month);
    social_entertainment(person);
    travel_vacation(person);

    // Update
    update_entertainment_satisfaction(person);
    calculate_entertainment_costs(person);

    if (month == 1) {
        adjust_entertainment_for_age(person);
        person.hobbies.entertainment.streaming_cost *= (1.0 + russia.inflation / 100.0);
        person.hobbies.entertainment.gym_membership_cost *= (1.0 + russia.inflation / 100.0);
        person.hobbies.entertainment.travel_budget *= (1.0 + russia.inflation / 100.0);
    }
}


void invest_in_stocks(Person& person) {
    RUB monthly_investment = 0;

    if (person.vtb.account_rub > person.salary * 3) {
        monthly_investment = person.vtb.account_rub - person.salary * 2;
        monthly_investment = fmin(monthly_investment, person.salary * 0.3);
    }

    if (monthly_investment <= 0) return;

    person.vtb.account_rub -= monthly_investment;

    person.portfolio.russian_stocks += monthly_investment * 0.4;
    person.portfolio.us_stocks += (monthly_investment * 0.3) / russia.rate_usd_rub;
    person.portfolio.bonds += monthly_investment * 0.2;
    person.portfolio.index_fund += monthly_investment * 0.1;
}


void update_portfolio_value(Person& person) {
    double ru_return = (market.russian_index / 3000.0 - 1.0) * 0.1;
    double us_return = (market.sp500 / 4500.0 - 1.0) * 0.08;
    double bond_return = market.bond_yield / 100.0 / 12.0;

    person.portfolio.russian_stocks *= (1.0 + ru_return);
    person.portfolio.us_stocks *= (1.0 + us_return);
    person.portfolio.bonds *= (1.0 + bond_return);
    person.portfolio.index_fund *= (1.0 + (ru_return + us_return) / 2);
}


void process_credit_payment(Person& person)
{
    if (!person.vtb.consumer_credit.is_active) return;

    RUB payment = person.vtb.consumer_credit.monthly_payment;

    if (person.vtb.account_rub >= payment) {
        person.vtb.account_rub -= payment;

        double interest_part = person.vtb.consumer_credit.body_debt *
            (person.vtb.consumer_credit.interest_rate / 1200.0);
        double principal_part = payment - interest_part;

        person.vtb.consumer_credit.body_debt -= (RUB)principal_part;

        if (person.vtb.credit_score < MAX_CREDIT_SCORE) {
            person.vtb.credit_score += 1;
        }

        if (person.vtb.consumer_credit.missed_payments > 0) {
            person.vtb.consumer_credit.missed_payments = 0;
        }

        // The loan is repaid
        if (person.vtb.consumer_credit.body_debt <= 0) {
            person.vtb.consumer_credit.is_active = false;
            person.vtb.consumer_credit.body_debt = 0;
            person.vtb.consumer_credit.monthly_payment = 0;
            person.vtb.credit_score += 20;
            person.health.stress -= 10;
        }
    }
    else {
        person.vtb.consumer_credit.missed_payments++;
        person.vtb.credit_score -= 30;
        person.health.stress += 25;

        person.vtb.consumer_credit.body_debt = (RUB)(
            person.vtb.consumer_credit.body_debt * 1.02
            );

    }
}


bool check_bankruptcy(Person& person)
{
    if (person.vtb.consumer_credit.missed_payments >= MAX_MISSED_PAYMENTS_BEFORE_BANKRUPTCY ||
        person.vtb.mortgage.missed_payments >= MAX_MISSED_PAYMENTS_BEFORE_BANKRUPTCY) {

        person.home.value = 0;
        person.car.value = 0;
        person.car.gas = 0;
        person.vtb.account_rub = 0;
        person.vtb.account_usd = 0;
        person.crypto_account.balance = 0;
        person.portfolio = { 0, 0, 0, 0 };

        person.vtb.consumer_credit.is_active = false;
        person.vtb.mortgage.is_active = false;

        person.vtb.credit_score = MIN_CREDIT_SCORE;
        person.health.stress = 100;
        person.health.happiness = 0;

        if (person.health.physical_health < 30 || person.health.age > 60) {
            person.health.is_alive = false;
            return true;
        }

        person.home.rent = 30000;

        return true;
    }
    return false;
}


void alice_food_expences(const int month)
{
    try_spend(alice, alice.monthly_food_cost);
    if (month == 12) {
        alice.monthly_food_cost *= (1.0 + russia.inflation / 100.0);
    }
}


void alice_lifestyle_expences(const int month)
{
    try_spend(alice, alice.monthly_lifestyle_cost);
    if (month == 12) {
        alice.monthly_lifestyle_cost *= (1.0 + russia.inflation / 100.0);
    }
}


void alice_home_expences(const int month)
{
    try_spend(alice, alice.home.monthly_utilities);
    if (month == 12) {
        alice.home.monthly_utilities *= (1.0 + russia.inflation / 100.0);
    }
}


void alice_children_expences(const int month)
{
    RUB children_cost = alice.family.children_amount * alice.family.child_expences;

    try_spend(alice, children_cost);
    if (month == 12) {
        alice.family.child_expences *= (1.0 + russia.inflation / 100.0);
    }
}


void bogdan_food_expences(const int month)
{
    try_spend(bogdan, bogdan.monthly_food_cost);
    if (month == 12) {
        bogdan.monthly_food_cost += bogdan.monthly_food_cost * (russia.inflation / 100.);
    }
}


void bogdan_lifestyle_expences(const int month)
{
    try_spend(bogdan, bogdan.monthly_lifestyle_cost);
    if (month == 12) {
        bogdan.monthly_lifestyle_cost *= (1.0 + russia.inflation / 100.0);
    }
}


void bogdan_home_expences(const int month)
{
    try_spend(bogdan, bogdan.home.monthly_utilities);
    try_spend(bogdan, bogdan.home.rent);
    if (month == 12) {
        bogdan.home.monthly_utilities *= (1.0 + russia.inflation / 100.0);
        bogdan.home.rent *= (1.0 + russia.inflation / 100.0);
    }
}


void bogdan_children_expences(const int month)
{
    RUB children_cost = bogdan.family.children_amount * bogdan.family.child_expences;

    try_spend(bogdan, children_cost);
    if (month == 12) {
        bogdan.family.child_expences *= (1.0 + russia.inflation / 100.0);
    }
}


void do_russian_inflation()
{
    if (month == 1) {
        russia.avg_salary *= (russia.inflation / 100.) + 1;
    }
}


void alice_salary(const int month, const int year)
{
    if (month == 1) {
        alice.salary *= 1.05; //indexation
        alice.health.happiness += 5;
    }

    if (month == 2 && year == 2026) {
        alice.vtb.account_rub += 5000;  // bonus
        alice.health.happiness += 8;
    }

    alice.vtb.account_rub += alice.salary;
}


void bogdan_salary(const int month, const int year)
{
    if (get_random(0, 100) < 15) {
        // Job change
        double raise = get_random(1.10, 1.30);
        bogdan.salary = (RUB)(bogdan.salary * raise);

        // Job change stress
        bogdan.health.stress += (short)get_random(10, 25);
        if (bogdan.health.stress > 100) bogdan.health.stress = 100;
    }

    bogdan.vtb.account_rub += bogdan.salary;
    bogdan.health.happiness += 15;
}


void bogdan_life_prolongation(const int month)
{
    if (month == 1) {
        russia.life_last_cost *= (1.0 + russia.inflation / 100.0);
        RUB cost = (RUB)(russia.life_last_cost * russia.rate_usd_rub);

        if (bogdan.health.max_age >= 120) return;

        if (bogdan.health.max_age - bogdan.health.age > 3) return;

        double total_wealth = bogdan.vtb.account_rub +
            (bogdan.vtb.account_usd * russia.rate_usd_rub) +
            (bogdan.crypto_account.balance * bogdan.crypto_account.exchange_rate_usd * russia.rate_usd_rub);

        if (total_wealth >= cost) {
            if (try_spend(bogdan, cost)) {
                bogdan.health.max_age += 2;
                alice.health.happiness += 10;
            }
        }
    }
}


void apply_seasonal_events()
{
    if (month == 12) {
        alice.monthly_lifestyle_cost *= 1.5;
        bogdan.monthly_lifestyle_cost *= 1.5;
        alice.health.happiness += 5;
        bogdan.health.happiness += 5;
    }

    if (month == 1 && year > 2026) {
        alice.monthly_lifestyle_cost /= 1.5;
        bogdan.monthly_lifestyle_cost /= 1.5;
    }

    if (month >= 6 && month <= 8) {
        alice.health.stress = fmax(0, alice.health.stress - 2);
        bogdan.health.stress = fmax(0, bogdan.health.stress - 2);
    }

    if (month >= 9 && month <= 11) {
        if (get_random(0, 100) < 5) {
            alice.health.physical_health -= 5;
            alice.health.medicine_expenses += 5000;
        }
        if (get_random(0, 100) < 5) {
            bogdan.health.physical_health -= 5;
            bogdan.health.medicine_expenses += 5000;
        }
    }
}


void print_results()
{
    printf("\n\n############## FINAL RESULTS ##############\n\n");

    double capital_alice = alice.car.value +
        alice.crypto_account.balance * alice.crypto_account.exchange_rate_usd * russia.rate_usd_rub +
        alice.home.value + alice.vtb.account_rub + alice.vtb.account_usd * russia.rate_usd_rub +
        get_total_portfolio_value(alice);

    double capital_bogdan = bogdan.car.value +
        bogdan.crypto_account.balance * bogdan.crypto_account.exchange_rate_usd * russia.rate_usd_rub +
        bogdan.home.value + bogdan.vtb.account_rub + bogdan.vtb.account_usd * russia.rate_usd_rub +
        get_total_portfolio_value(bogdan);

    printf("Simulation ended in year %d\n", year);
    printf("Alice died at age %d | Bogdan died at age %d\n\n",
        alice.health.age, bogdan.health.age);

    printf("=== FINANCIAL ===\n");
    printf("Alice final capital: %.2f RUB\n", capital_alice);
    printf("Bogdan final capital: %.2f RUB\n", capital_bogdan);
    printf("Alice final salary: %.2f | Bogdan: %.2f\n\n", alice.salary, bogdan.salary);

    printf("=== FAMILY ===\n");
    printf("Alice had %d children\n", alice.family.children_amount);
    printf("Bogdan had %d children\n\n", bogdan.family.children_amount);

    printf("=== LIFE QUALITY ===\n");
    printf("Alice happiness: %d | Bogdan: %d\n", alice.health.happiness, bogdan.health.happiness);

    printf("\n=== HOBBIES & ENTERTAINMENT ===\n");
    printf("Alice hobbies: %d active | Countries visited: %d\n",
        alice.hobbies.active_hobbies_count,
        alice.hobbies.entertainment.countries_visited);
    printf("Bogdan hobbies: %d active | Countries visited: %d\n",
        bogdan.hobbies.active_hobbies_count,
        bogdan.hobbies.entertainment.countries_visited);
    printf("Alice entertainment satisfaction: %d\n",
        alice.hobbies.entertainment.entertainment_satisfaction);
    printf("Bogdan entertainment satisfaction: %d\n",
        bogdan.hobbies.entertainment.entertainment_satisfaction);

}


void alice_car(const int month)
{
    try_spend(alice, alice.car.gas);
    if (month == 2) try_spend(alice, alice.car.yearly_tax);
    if (month == 1) {
        alice.car.yearly_tax *= (1.0 + russia.inflation / 100.0);
        alice.car.gas *= (1.0 + russia.inflation / 100.0);
    }
}


void apply_economic_crisis()
{
    russia.inflation += 0.5 * event_severity;
    russia.rate_usd_rub += 2.0 * event_severity;
    russia.crisis = true;
}


void apply_pandemic(Person& person)
{
    person.health.physical_health -= (short)(3 * event_severity);
    person.health.medicine_expenses *= (1.0 + 0.3 * event_severity);
    person.monthly_lifestyle_cost *= 0.7;  // Lockdown
    person.car.gas *= 0.5;

    if (get_random(0, 100) < 5 * event_severity) {
        person.health.physical_health -= 20;
        person.health.stress += 30;
    }
}


void apply_war_conflict(Person& person)
{
    russia.inflation += 1.0 * event_severity;
    russia.rate_usd_rub += 5.0 * event_severity;
    russia.crisis = true;

    person.health.stress += (15 * event_severity);
    person.health.happiness -= (10 * event_severity);
    person.monthly_food_cost *= (1.0 + 0.1 * event_severity);
}


void apply_tech_boom(Person& person)
{
    if (person.education.skill_level > 15) {
        person.salary *= (1.0 + 0.03 * event_severity);
    }
    person.crypto_account.exchange_rate_usd *= (1.0 + 0.05 * event_severity);
    person.health.happiness += (3 * event_severity);
    russia.avg_salary *= (1.0 + 0.01 * event_severity);
}


void apply_oil_crisis(Person& person)
{
    russia.rate_usd_rub -= 2.0 * event_severity;
    person.car.gas *= (1.0 + 0.2 * event_severity);
    russia.avg_salary *= (1.0 + 0.005 * event_severity);
}


void apply_natural_disaster(Person& person)
{
    if (get_random(0, 100) < 5 * event_severity) {
        RUB damage = (RUB)(person.home.value * 0.1 * event_severity);
        person.home.value -= damage;
        person.vtb.account_rub -= damage;
        person.health.stress += 30;
    }
}


void apply_political_instability(Person& person)
{
    russia.rate_usd_rub += 3.0 * event_severity;
    person.health.stress += (10 * event_severity);

    if (get_random(0, 1000) < 5) {
        RUB frozen = person.vtb.account_rub * 0.1;
        person.vtb.account_rub -= frozen;
    }
}


void apply_global_recession(Person& person)
{
    russia.inflation -= 0.2 * event_severity;
    russia.avg_salary *= (1.0 - 0.01 * event_severity);
    person.home.value *= (1.0 - 0.005 * event_severity);
    person.health.stress += (5 * event_severity);
}


void apply_crypto_crash(Person& person)
{
    person.crypto_account.exchange_rate_usd *= (1.0 - 0.1 * event_severity);

    if (person.crypto_account.balance > 0.1) {
        person.health.stress += (20 * event_severity);
        person.health.happiness -= (15 * event_severity);
    }
}


void apply_crypto_boom(Person& person)
{
    person.crypto_account.exchange_rate_usd *= (1.0 + 0.15 * event_severity);

    if (person.crypto_account.balance > 0.1) {
        person.health.happiness += (15 * event_severity);
    }
}


void apply_sanctions(Person& person)
{
    russia.rate_usd_rub += 6.0 * event_severity;
    russia.inflation += 1.5 * event_severity;
    person.monthly_food_cost *= (1.0 + 0.1 * event_severity);
    person.health.stress += (10 * event_severity);

    if (person.vtb.account_usd > 1000 && get_random(0, 100) < 10) {
    }
}


void apply_real_estate_crash(Person& person)
{
    person.home.value *= (1.0 - 0.1 * event_severity);

    if (person.vtb.mortgage.is_active) {
        person.health.stress += (25 * event_severity);
    }
}


void apply_stock_crash(Person& person)
{
    russia.crisis = true;
    russia.avg_salary *= (1.0 - 0.02 * event_severity);
    person.health.stress += (8 * event_severity);
}


void apply_hyperinflation(Person& person)
{
    russia.inflation += 3.0 * event_severity;
    person.monthly_food_cost *= (1.0 + 0.15 * event_severity);
    person.vtb.account_rub *= (1.0 - 0.05 * event_severity);
    person.health.stress += (20 * event_severity);

}


void apply_currency_reform(Person& person)
{
    person.health.stress += (15 * event_severity);
}


void apply_mass_layoffs(Person& person, const char* name)
{
    if (get_random(0, 100) < 10 * event_severity) {
        if (person.salary > 0) {
            person.salary = 0;
            person.health.stress += 50;
            person.health.happiness -= 30;
        }
    }
    person.health.stress += (5 * event_severity);
}


void apply_economic_growth(Person& person)
{
    russia.avg_salary *= (1.0 + 0.02 * event_severity);
    person.salary *= (1.0 + 0.01 * event_severity);
    person.home.value *= (1.0 + 0.02 * event_severity);
    person.health.happiness += (5 * event_severity);
    person.health.stress -= (short)(3 * event_severity);

    if (russia.inflation > 4.0) {
        russia.inflation -= 0.3;
    }
}



void end_event()
{

    current_event_type = 0;
    event_is_active = false;
    russia.crisis = false;

    if (russia.inflation > 10.0) russia.inflation -= 2.0;
    if (russia.rate_usd_rub > 100.0) russia.rate_usd_rub -= 5.0;
}


void apply_event_to_person(Person& person, const char* name)
{
    if (!event_is_active) return;

    static int last_global_event_month = -1;
    bool apply_global = (last_global_event_month != simulation_month_counter);

    if (apply_global) {
        last_global_event_month = simulation_month_counter;
        switch (current_event_type) {
        case 1:  apply_economic_crisis(); break;
        case 2:  apply_pandemic(person); break;
        case 3:  apply_war_conflict(person); break;
        case 4:  apply_tech_boom(person); break;
        case 5:  apply_oil_crisis(person); break;
        case 6:  apply_natural_disaster(person); break;
        case 7:  apply_political_instability(person); break;
        case 8:  apply_global_recession(person); break;
        case 9:  apply_crypto_crash(person); break;
        case 10: apply_crypto_boom(person); break;
        case 11: apply_sanctions(person); break;
        case 12: apply_real_estate_crash(person); break;
        case 13: apply_stock_crash(person); break;
        case 14: apply_hyperinflation(person); break;
        case 15: apply_currency_reform(person); break;
        case 16: apply_mass_layoffs(person, name); break;
        case 17: apply_economic_growth(person); break;
        }
    }

    if (current_event_type != 4 && current_event_type != 10 && current_event_type != 17) {
        person.health.stress += (1 * event_severity);
    }
}


void start_random_event()
{
    if (event_is_active) return;

    if (get_random(0, 100) < 3) {
        current_event_type = (int)get_random(1, 17);
        event_severity = get_random(0.3, 1.0);
        event_duration = (int)get_random(6, 36);
        event_months_active = 0;
        event_is_active = true;

    }
}


void world_events()
{
    start_random_event();

    if (event_is_active) {
        event_months_active++;

        if (alice.health.is_alive) {
            apply_event_to_person(alice, "Alice");
        }
        if (bogdan.health.is_alive) {
            apply_event_to_person(bogdan, "Bogdan");
        }

        if (event_months_active >= event_duration) {
            end_event();
        }
    }

    apply_seasonal_events();
}


void random_events(Person& person)
{
    if (person.family.has_parents && get_random(0, 100) < 5) {
        RUB help_amount = 50'000;
        try_spend(person, help_amount);
    }

    if (get_random(0, 1000) < 1) {
        RUB inheritance = (RUB)get_random(1'000'000, 5'000'000);
        person.vtb.account_rub += inheritance;
        person.family.has_parents = false;
        person.health.stress += get_random(40, 60);
        person.health.happiness -= (short)get_random(20, 40);
    }
}


void alice_monthly_health_recovery()
{
    if (alice.health.age < 40) {
        alice.health.physical_health = fmin(100, alice.health.physical_health + 2);
    }
    else if (alice.health.age < 60) {
        alice.health.physical_health = fmin(100, alice.health.physical_health + 1);
    }

    if (alice.health.happiness > 70) {
        alice.health.physical_health = fmin(100, alice.health.physical_health + 1);
        alice.health.stress = fmax(0, alice.health.stress - 3);
    }
}


void bogdan_monthly_health_recovery()
{
    if (bogdan.health.age < 40) {
        bogdan.health.physical_health = fmin(100, bogdan.health.physical_health + 2);
    }
    else if (bogdan.health.age < 60) {
        bogdan.health.physical_health = fmin(100, bogdan.health.physical_health + 1);
    }

    if (bogdan.health.happiness > 70) {
        bogdan.health.physical_health = fmin(100, bogdan.health.physical_health + 1);
        bogdan.health.stress = fmax(0, bogdan.health.stress - 3);
    }
}


void alice_mortgage()
{
    if (alice.vtb.mortgage.is_active) {
        RUB payment = alice.vtb.mortgage.monthly_payment;

        if (alice.vtb.account_rub >= payment) {
            alice.vtb.account_rub -= payment;

            double interest_part = alice.vtb.mortgage.body_debt *
                (alice.vtb.mortgage.interest_rate / 1200.0);
            double principal_part = payment - interest_part;

            alice.vtb.mortgage.body_debt -= (RUB)principal_part;

            if (alice.vtb.mortgage.body_debt <= 0) {
                alice.vtb.mortgage.is_active = false;
                alice.vtb.mortgage.body_debt = 0;
                alice.health.stress -= 20;
                alice.health.happiness += 15;
            }
        }
        else {
            alice.vtb.mortgage.missed_payments++;
            alice.vtb.credit_score -= 15;
            alice.health.stress += 15;
        }
    }
}


void alice_try_find_partner(const short age, const int salary)
{
    if (!alice.family.has_partner and alice.health.stress < 50) {
        double p = (salary / russia.avg_salary - 1.0) * 10.0;
        short salary_bonus = (p < 0) ? 0 : (p > 6 ? 6 : p);
        short age_penalty = age - 20;
        alice.family.has_partner = get_random(1, 100) + salary_bonus - age_penalty > 95;
        if (alice.family.has_partner) printf("Alice found a partner at %d!\n", alice.health.age);
        alice.health.happiness += (short)get_random(10, 20);
    }
}


void bogdan_try_find_partner(const short age, const int salary)
{
    if (!bogdan.family.has_partner and bogdan.health.stress < 50) {
        double p = (salary / russia.avg_salary - 1.0) * 10.0;
        short salary_bonus = (p < 0) ? 0 : (p > 6 ? 6 : p);
        short age_penalty = age - 20;
        bogdan.family.has_partner = get_random(1, 100) + salary_bonus - age_penalty > 95;
        if (bogdan.family.has_partner) printf("Bogdan found a partner at %d!\n", bogdan.health.age);
        bogdan.health.happiness += (short)get_random(10, 20);
    }
}


void check_family_expansion(Person& person, int year)
{
    if (person.family.has_partner && person.health.age > 25 && person.health.age < 45) {
        int chance = 99;
        if (person.family.children_amount == 0) chance = 98;

        if (get_random(1, 100) > chance) {
            person.family.children_amount++;
            person.health.stress += get_random(10, 25);
        }
    }
}


void alice_age(const int month)
{
    if (month == 12) {
        if (alice.health.is_alive)  ++alice.health.age;

    }
    if (alice.health.age >= alice.health.max_age) alice.health.is_alive = false;
}


void bogdan_age(const int month)
{
    if (month == 12) {
        if (bogdan.health.is_alive)  ++bogdan.health.age;

    }
    if (bogdan.health.age >= bogdan.health.max_age) bogdan.health.is_alive = false;
}

void alice_medecine_expences(const int month)
{
    if (alice.health.physical_health < 50) {
        try_spend(alice, alice.health.medicine_expenses);
    }
    if (alice.health.physical_health <= 0) {
        alice.health.is_alive = false;
    }
    if (month == 1) {
        alice.health.medicine_expenses *= (1.0 + russia.inflation / 100.0);
    }
}


void alice_stress()
{
    if (alice.health.stress > 90) {
        alice.health.physical_health -= 5;
    }
    if (alice.health.stress > 20) {
        alice.health.stress -= 5;
    }

}


void alice_trip()
{
    if (simulation_month_counter % 24 == 0) {
        try_spend(alice, alice.salary * 0.6);
    }
}


void alice_study()
{
    if (alice.education.is_studying) {
        try_spend(alice, alice.education.tuition_fee);
        --alice.education.months_remaining;
        if (alice.education.months_remaining == 0) {
            if (alice.education.higher_education) {
                ++alice.education.degree_level;
            }
            else {
                alice.education.skill_level += 10;
            }
            alice.education.is_studying = false;
        }
    }
    else {
        if (get_random(1, 10) == 3) {
            alice.education.is_studying = true;
            if (alice.education.degree_level < 4) {
                if (get_random(1, 2) == 2) {
                    alice.education.higher_education = true;
                    alice.education.months_remaining = 24;
                    alice.education.tuition_fee = 0;
                }
                else {
                    alice.education.higher_education = false;
                    alice.education.months_remaining = 6;
                    alice.education.tuition_fee = 50'000;
                }
            }
            else
            {
                alice.education.higher_education = false;
            }
        }
    }
}


void bogdan_medecine_expences(const int month)
{
    if (bogdan.health.physical_health < 50) {
        try_spend(bogdan, bogdan.health.medicine_expenses);
    }
    if (bogdan.health.physical_health <= 0) {
        bogdan.health.is_alive = false;
    }
    if (month == 1) {
        bogdan.health.medicine_expenses *= (1.0 + russia.inflation / 100.0);
    }
}


void bogdan_stress()
{
    if (bogdan.health.stress > 90) {
        bogdan.health.physical_health -= 5;
    }
    if (bogdan.health.stress > 20) {
        bogdan.health.stress -= 5;
    }

}


void bogdan_trip()
{
    if (simulation_month_counter % 24 == 0) {
        try_spend(bogdan, bogdan.salary * 0.6);
    }
}


void bogdan_study()
{
    if (bogdan.education.is_studying) {
        try_spend(bogdan, bogdan.education.tuition_fee);
        --bogdan.education.months_remaining;
        if (bogdan.education.months_remaining == 0) {
            if (bogdan.education.higher_education) {
                ++bogdan.education.degree_level;
            }
            else {
                bogdan.education.skill_level += 10;
            }
            bogdan.education.is_studying = false;
        }
    }
    else {
        if (get_random(1, 6) == 3) {
            bogdan.education.is_studying = true;

            if (bogdan.education.degree_level < 4) {
                if (get_random(1, 2) == 2) {
                    bogdan.education.higher_education = true;
                    bogdan.education.months_remaining = 24;
                    bogdan.education.tuition_fee = 0;
                }
                else {
                    bogdan.education.higher_education = false;
                    bogdan.education.months_remaining = 6;
                    bogdan.education.tuition_fee = 50'000;
                }
            }
            else
            {
                bogdan.education.higher_education = false;
            }
        }
    }
}


void alice_happiness()
{
    if (alice.health.stress <= 10) {
        alice.health.happiness = fmin(100, alice.health.happiness + 10);
    }
    else if (alice.health.stress >= 80) {
        alice.health.happiness = fmax(0, alice.health.happiness - 10);
    }
}


void bogdan_happiness()
{
    if (bogdan.health.stress <= 10) {
        bogdan.health.happiness = fmin(100, bogdan.health.happiness + 10);
    }
    else if (bogdan.health.stress >= 80) {
        bogdan.health.happiness = fmax(0, bogdan.health.happiness - 10);
    }
}


void simulation()
{
    while (alice.health.is_alive || bogdan.health.is_alive) {
        // World
        world_events();
        crypto_rates_update();
        stock_market_update();
        do_russian_inflation();

        // Alice
        if (alice.health.is_alive) {
            alice_salary(month, year);
            update_portfolio_value(alice);
            random_events(alice);
            alice_car(month);
            alice_age(month);
            alice_medecine_expences(month);
            alice_stress();
            alice_trip();
            alice_study();
            alice_mortgage();
            alice_food_expences(month);
            alice_children_expences(month);
            alice_home_expences(month);
            alice_lifestyle_expences(month);
            process_credit_payment(alice);
            check_bankruptcy(alice);
            alice_try_find_partner(alice.health.age, alice.salary);
            check_family_expansion(alice, year);
            alice_happiness();
            alice_monthly_health_recovery();
            invest_in_stocks(alice);
            process_hobbies_and_entertainment(alice, month);
        }

        //Bogdan
        if (bogdan.health.is_alive) {
            bogdan_salary(month, year);
            update_portfolio_value(bogdan);
            random_events(bogdan);
            bogdan_food_expences(month);
            bogdan_children_expences(month);
            bogdan_home_expences(month);
            bogdan_lifestyle_expences(month);
            bogdan_age(month);
            bogdan_life_prolongation(month);
            bogdan_medecine_expences(month);
            bogdan_stress();
            bogdan_trip();
            bogdan_study();
            process_credit_payment(bogdan);
            check_bankruptcy(bogdan);
            bogdan_try_find_partner(bogdan.health.age, bogdan.salary);
            check_family_expansion(bogdan, year);
            invest_in_stocks(bogdan);
            bogdan_happiness();
            bogdan_monthly_health_recovery();
            process_hobbies_and_entertainment(bogdan, month);
        }

        ++simulation_month_counter;

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    init();
    simulation();
    print_results();
}