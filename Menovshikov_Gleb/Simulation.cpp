#include <stdio.h>
#include <iostream>
#include <array>
#include <list>
#include <random>

using std::cout;
using std::endl;
using std::array;
using std::list;
using std::string;

using Percent = float;
using RUB = long long int;
using USD = long long int;

std::random_device rd;
std::mt19937 gen(rd()); 
std::uniform_int_distribution<> distr(25, 30);


struct Calendar {
    const array<int, 12> normal_year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const array<int, 12> leap_year   = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    array<int, 12> year_days;
    int year;
    int month;
    int day;
    int weekday;

    int  get_days_in_month();
    void update_year_days();
    void start(int d, int m, int y, int wd);
    bool reached(int m, int y);
    void next_day();

    bool is_first_day();
    bool is_last_day();
    bool is_new_year();
    bool is_year_end();
    bool is_quarter_end();
    bool is_year(int y);
    bool is_weekend();
    bool is_weekday();

    bool is_january();
    bool is_february();
    bool is_march();
    bool is_april();
    bool is_may();
    bool is_june();
    bool is_july();
    bool is_august();
    bool is_september();
    bool is_october();
    bool is_november();
    bool is_december();

    bool is_winter();
    bool is_spring();
    bool is_summer();
    bool is_autumn();

    bool   is_heating_season();
    bool   is_electricity_peak();
    string month_name();
};

Calendar calendar;


struct Stress {
    int    stress_value;
    string stress_level;

    void  update_stress_level();
    void  increase(int amount);
    void  decrease(int amount);

    bool  is_cheerful();
    bool  is_normal();
    bool  is_exhausted();
    bool  is_frenzy();

    float productivity_factor();
    float spending_factor();

    const int* get_stress_pointer();
};


struct Home {
    RUB rent;
    RUB rental_income;
    RUB home_insurance;
    RUB repairs_monthly;
    RUB repairs_annual;
    RUB cleaning_supplies;
    RUB furniture_annual;

    RUB get_rent();
    RUB get_rental_income();
    RUB get_home_insurance();
    RUB get_repairs_monthly();
    RUB get_repairs_annual();
    RUB get_cleaning_supplies();
    RUB get_furniture_annual();
    RUB get_unexpected_repair();
    RUB get_total_annual_cost();
};


struct Job {
    RUB salary;
    RUB bonus;

    int current_workload;
    int daily_workload;
    int workday_stress;

    struct Overtime {
        int     workload_decrease;
        int     stress_increase;
        Percent extra_pay_multiplier;

    public:
        Overtime(const int workload, const Percent multiplier, const int stress_value);
    };

public:
    Overtime zero_overtime{0, 0, 0};
    Overtime small_overtime{0, 0, 0};
    Overtime meduim_overtime{0, 0, 0};
    Overtime large_overtime{0, 0, 0};

    void init_overtime() {
        small_overtime  = Overtime{daily_workload,   1.3f, (int)(workday_stress * 1.5f)};
        meduim_overtime = Overtime{daily_workload*2, 1.6f, (int)(workday_stress * 2.0f)};
        large_overtime  = Overtime{daily_workload*3, 2.0f, (int)(workday_stress * 2.5f)};
    }

    RUB      get_daily_pay();
    RUB      get_effective_daily_pay(int stress_value);
    RUB      get_bonus();
    RUB      get_annual_gross();
    RUB      get_annual_net(Percent tax_rate);
    void     promote();
    int      get_current_workload();
    void     increase_current_workload_by_days(const int days);
    Overtime what_overtime_needed();
    void     do_work(int &stress_value, RUB &account_rub);
    void     do_overtime(const Overtime overtime, int &stress_value, RUB &account_rub);
};


struct Car {
    RUB value;
    RUB gas;
    RUB tires_price;
    RUB oil_change;
    RUB car_wash;
    RUB parking_monthly;
    RUB insurance_osago;
    RUB insurance_kasko;
    RUB maintenance_annual;
    RUB fine_risk;

    RUB  get_tires_price();
    RUB  get_oil_change();
    RUB  get_car_wash();
    RUB  get_parking_monthly();
    RUB  get_insurance_osago();
    RUB  get_insurance_kasko();
    RUB  get_maintenance_annual();
    RUB  get_fine_risk();
    RUB  get_total_annual_cost();
    void check_random_fine(int stress_value, RUB &account_rub);
};


struct Bank {
    RUB     account_rub;
    USD     account_usd;
    float   rate_usd_rub;
    RUB     deposit_balance;
    Percent deposit_rate;
    RUB     monthly_deposit;
    RUB     bank_fee;

    RUB  get_bank_fee();
    RUB  get_deposit_balance();
    RUB  get_liquid_rub();
    void accrue_deposit_interest();
    void add_monthly_deposit();
};


struct Country {
    struct Economy {
        Percent inflation;

        Percent get_current_inflation();
        void    recalculate_inflation(const int year);
        void    recalculate_prices(list<RUB*> prices);
    };

public:
    Economy economy;
};


struct Health {
    RUB medicine_monthly;
    RUB doctor_visit;
    RUB dentist_annual;
    RUB gym_monthly;
    RUB vitamins_monthly;
    RUB emergency_medical;
    RUB optician_annual;
    RUB psychologist_monthly;

    RUB get_medicine_monthly(int stress_value);
    RUB get_doctor_visit();
    RUB get_dentist_annual();
    RUB get_gym_monthly();
    RUB get_vitamins_monthly();
    RUB get_emergency_medical();
    RUB get_optician_annual();
    RUB get_psychologist_monthly();
    RUB get_total_monthly(int stress_value);
    RUB get_total_annual_cost();
};


struct Phone {
    RUB monthly_plan;
    RUB replacement_cost;
    int replacement_cycle_years;

    RUB get_monthly_plan();
    RUB get_replacement_cost();
};


struct Utilities {
    RUB electricity_base;
    RUB electricity_winter_extra;
    RUB water_monthly;
    RUB heating_monthly;
    RUB internet_monthly;
    RUB tv_subscription;

    RUB get_electricity();
    RUB get_water_monthly();
    RUB get_heating();
    RUB get_internet_monthly();
    RUB get_tv_subscription();
    RUB get_total_monthly();
    RUB get_total_annual_cost();
};


struct Entertainment {
    RUB streaming_monthly;
    RUB cinema_monthly;
    RUB restaurant_monthly;
    RUB bar_monthly;
    RUB concert_quarterly;
    RUB hobbies_monthly;
    RUB games_monthly;
    RUB sports_events_annual;

    RUB get_streaming_monthly();
    RUB get_cinema_monthly();
    RUB get_restaurant_monthly(int stress_value);
    RUB get_bar_monthly(int stress_value);
    RUB get_concert_quarterly();
    RUB get_hobbies_monthly();
    RUB get_games_monthly();
    RUB get_sports_events_annual();
    RUB get_total_monthly(int stress_value);
    RUB get_total_annual_cost();
};


struct Clothing {
    RUB summer_wardrobe;
    RUB winter_wardrobe;
    RUB shoes_spring;
    RUB shoes_autumn;
    RUB accessories_annual;
    RUB sportswear_annual;
    RUB formal_wear_annual;

    RUB get_summer_wardrobe();
    RUB get_winter_wardrobe();
    RUB get_shoes_spring();
    RUB get_shoes_autumn();
    RUB get_accessories_annual();
    RUB get_sportswear_annual();
    RUB get_formal_wear_annual();
    RUB get_total_annual_cost();
};


struct PersonalCare {
    RUB haircut_monthly;
    RUB cosmetics_monthly;
    RUB pharmacy_monthly;
    RUB massage_monthly;
    RUB manicure_monthly;
    RUB perfume_biannual;
    RUB spa_quarterly;

    RUB get_haircut_monthly();
    RUB get_cosmetics_monthly();
    RUB get_pharmacy_monthly();
    RUB get_massage_monthly();
    RUB get_manicure_monthly();
    RUB get_perfume_biannual();
    RUB get_spa_quarterly();
    RUB get_total_monthly();
    RUB get_total_annual_cost();
};


struct Gifts {
    RUB birthday_own;
    RUB birthday_others_annual;
    RUB new_year_gifts;
    RUB valentines_day;
    RUB mothers_day;
    RUB fathers_day;
    RUB colleagues_gifts_annual;

    RUB get_birthday_own();
    RUB get_birthday_others_annual();
    RUB get_new_year_gifts();
    RUB get_valentines_day();
    RUB get_mothers_day();
    RUB get_fathers_day();
    RUB get_colleagues_gifts_annual();
    RUB get_total_annual_cost();
};


struct Transport {
    RUB metro_monthly;
    RUB taxi_monthly;
    RUB bus_monthly;
    RUB toll_roads_monthly;

    RUB get_metro_monthly();
    RUB get_taxi_monthly();
    RUB get_bus_monthly();
    RUB get_toll_roads_monthly();
    RUB get_total_monthly();
    RUB get_total_annual_cost();
};


struct Taxes {
    Percent income_tax_rate;
    Percent property_tax_rate;
    RUB     property_tax_annual;
    RUB     car_tax_annual;
    RUB     tax_deduction_return;

    RUB calculate_monthly_income_tax(const RUB monthly_income);
    RUB get_property_tax_annual();
    RUB get_car_tax_annual();
    RUB get_tax_deduction_return();
};


struct Electronics {
    RUB laptop_replacement;
    int laptop_cycle_years;
    RUB headphones_biannual;
    RUB smart_watch_biannual;
    RUB accessories_monthly;
    RUB repairs_annual;

    RUB get_laptop_replacement();
    RUB get_headphones_biannual();
    RUB get_smart_watch_biannual();
    RUB get_accessories_monthly();
    RUB get_repairs_annual();
    RUB get_total_annual_cost();
};


struct Subscriptions {
    RUB cloud_storage;
    RUB antivirus;
    RUB office_suite;
    RUB cloud_backup;
    RUB vpn;
    RUB professional_tools;
    RUB password_manager;
    RUB news_subscription;

    RUB get_cloud_storage();
    RUB get_antivirus();
    RUB get_office_suite();
    RUB get_cloud_backup();
    RUB get_vpn();
    RUB get_professional_tools();
    RUB get_password_manager();
    RUB get_news_subscription();
    RUB get_total_monthly();
    RUB get_total_annual_cost();
};


struct Person {
    Stress        mind;
    Home          home;
    Country       country;
    Bank          vtb;
    Job           job;
    RUB           food;
    RUB           cat;
    RUB           cat_vet;
    RUB           trip;
    Car           car;
    Health        health;
    Phone         phone;
    Utilities     utilities;
    Entertainment entertainment;
    Clothing      clothing;
    PersonalCare  personal_care;
    Gifts         gifts;
    Transport     transport;
    Taxes         taxes;
    Electronics   electronics;
    Subscriptions subscriptions;

    int day_off_stress_decrease;

    const list<RUB*> get_prices_pointers();
    RUB   get_total_monthly_income();
    RUB   get_total_monthly_expenses();
    RUB   get_monthly_surplus();
    float get_savings_rate();
    void  rest();
    void update_day_off_stress_decrease();
};

struct Person alice;


// Calendar

int Calendar::get_days_in_month() {
    return year_days[month-1];
}

void Calendar::update_year_days() {
    if (year % 4 != 0)
        year_days = normal_year;
    else
        year_days = leap_year;
}

void Calendar::start(int d, int m, int y, int wd) {
    day     = d;
    month   = m;
    year    = y;
    weekday = wd;
    update_year_days();
}

bool Calendar::reached(int m, int y) {
    return year == y && month == m;
}

void Calendar::next_day() {
    day++;
    weekday = (weekday + 1) % 7;

    if (day > year_days[month-1]) {
        ++month;
        day = 1;
    }

    if (month == 13) {
        ++year;
        update_year_days();
        month = 1;
    }
}

bool Calendar::is_first_day()    { return day == 1; }
bool Calendar::is_last_day()     { return day == year_days[month-1]; }
bool Calendar::is_new_year()     { return month == 1 && day == 1; }
bool Calendar::is_year_end()     { return month == 12 && day == 31; }
bool Calendar::is_quarter_end()  { return month == 3 || month == 6 || month == 9 || month == 12; }
bool Calendar::is_year(int y)    { return year == y; }
bool Calendar::is_weekend()      { return weekday == 5 || weekday == 6; }
bool Calendar::is_weekday()      { return weekday < 5; }

bool Calendar::is_january()      { return month == 1; }
bool Calendar::is_february()     { return month == 2; }
bool Calendar::is_march()        { return month == 3; }
bool Calendar::is_april()        { return month == 4; }
bool Calendar::is_may()          { return month == 5; }
bool Calendar::is_june()         { return month == 6; }
bool Calendar::is_july()         { return month == 7; }
bool Calendar::is_august()       { return month == 8; }
bool Calendar::is_september()    { return month == 9; }
bool Calendar::is_october()      { return month == 10; }
bool Calendar::is_november()     { return month == 11; }
bool Calendar::is_december()     { return month == 12; }

bool Calendar::is_winter()       { return month == 12 || month == 1 || month == 2; }
bool Calendar::is_spring()       { return month >= 3  && month <= 5; }
bool Calendar::is_summer()       { return month >= 6  && month <= 8; }
bool Calendar::is_autumn()       { return month >= 9  && month <= 11; }

bool Calendar::is_heating_season() {
    return month >= 10 || month <= 4;
}

bool Calendar::is_electricity_peak() {
    return month == 11 || month == 12 || month == 1 || month == 2 || month == 3;
}

string Calendar::month_name() {
    switch (month) {
        case 1:  return "January";
        case 2:  return "February";
        case 3:  return "March";
        case 4:  return "April";
        case 5:  return "May";
        case 6:  return "June";
        case 7:  return "July";
        case 8:  return "August";
        case 9:  return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Unknown";
    }
}


// Stress

void Stress::update_stress_level() {
    if (stress_value < 10)
        stress_level = "Cheerful";
    else if (stress_value < 20)
        stress_level = "Normal";
    else if (stress_value < 30)
        stress_level = "Exhausted";
    else
        stress_level = "Frenzy";
}

void Stress::increase(int amount) {
    stress_value += amount;
}

void Stress::decrease(int amount) {
    if (stress_value > amount){
        stress_value -= amount;
    } else{
        stress_value = 0;
    }
}

bool Stress::is_cheerful()  { return stress_value < 10; }
bool Stress::is_normal()    { return stress_value >= 10 && stress_value < 20; }
bool Stress::is_exhausted() { return stress_value >= 20 && stress_value < 30; }
bool Stress::is_frenzy()    { return stress_value >= 30; }

float Stress::productivity_factor() {
    if (is_frenzy())    return 0.6f;
    if (is_exhausted()) return 0.8f;
    if (is_normal())    return 0.95f;
    return 1.0f;
}

float Stress::spending_factor() {
    if (is_frenzy())    return 1.5f;
    if (is_exhausted()) return 1.2f;
    return 1.0f;
}

const int* Stress::get_stress_pointer() {
    return &stress_value;
}


// Home

RUB Home::get_rent() {
    return rent;
}
RUB Home::get_rental_income() {
    return rental_income;
}
RUB Home::get_home_insurance() {
    return home_insurance;
}
RUB Home::get_repairs_monthly() {
    return repairs_monthly;
}
RUB Home::get_repairs_annual() {
    return repairs_annual;
}
RUB Home::get_cleaning_supplies() {
    return cleaning_supplies;
}
RUB Home::get_furniture_annual() {
    return furniture_annual;
}
RUB Home::get_unexpected_repair() {
    if (rand() % 100 < 5)
        return repairs_monthly * 4;
    return 0;
}
RUB Home::get_total_annual_cost() {
    return rent * 12
         + home_insurance
         + repairs_monthly * 12
         + repairs_annual
         + cleaning_supplies * 12
         + furniture_annual;
}


// Job & Overtime

Job::Overtime::Overtime(const int workload, const Percent multiplier, const int stress_value) {
    workload_decrease    = workload;
    stress_increase      = stress_value;
    extra_pay_multiplier = multiplier;
}

RUB Job::get_daily_pay() {
    return (RUB)(salary * 7.0f / (calendar.get_days_in_month() * 5.0f));
}

RUB Job::get_effective_daily_pay(int stress_value) {
    float productivity = 1.0f;
    if (stress_value >= 30)      productivity = 0.6f;
    else if (stress_value >= 20) productivity = 0.8f;
    else if (stress_value >= 10) productivity = 0.95f;
    return (RUB)(get_daily_pay() * productivity);
}

RUB Job::get_bonus() {
    return bonus;
}
RUB Job::get_annual_gross() {
    return salary * 12 + bonus;
}
RUB Job::get_annual_net(Percent tax_rate) {
    return (RUB)(get_annual_gross() * (1.0f - tax_rate / 100.f));
}

void Job::promote() {
    salary *= 1.5;
}

int Job::get_current_workload() {
    return current_workload;
}

void Job::increase_current_workload_by_days(const int days) {
    current_workload += days * daily_workload;
}

Job::Overtime Job::what_overtime_needed() {
    if (current_workload <= daily_workload)
        return zero_overtime;
    else if (current_workload <= daily_workload * 2)
        return small_overtime;
    else if (current_workload <= daily_workload * 3)
        return meduim_overtime;
    else if (current_workload <= daily_workload * 4)
        return large_overtime;

    return zero_overtime;
}

void Job::do_work(int &stress_value, RUB &account_rub) {
    current_workload -= daily_workload;
    stress_value     += workday_stress;
    account_rub      += get_effective_daily_pay(stress_value);
}

void Job::do_overtime(const Overtime overtime, int &stress_value, RUB &account_rub) {
    current_workload -= overtime.workload_decrease;
    stress_value     += overtime.stress_increase;
    account_rub      += get_effective_daily_pay(stress_value) * overtime.extra_pay_multiplier;
}


// Car

RUB Car::get_tires_price() {
    return tires_price;
}
RUB Car::get_oil_change() {
    return oil_change;
}
RUB Car::get_car_wash() {
    return car_wash;
}
RUB Car::get_parking_monthly() {
    return parking_monthly;
}
RUB Car::get_insurance_osago() {
    return insurance_osago;
}
RUB Car::get_insurance_kasko() {
    return insurance_kasko;
}
RUB Car::get_maintenance_annual() {
    return maintenance_annual;
}
RUB Car::get_fine_risk() {
    return fine_risk;
}
RUB Car::get_total_annual_cost() {
    return gas * 12
         + tires_price * 2
         + oil_change * 2
         + car_wash * 12
         + parking_monthly * 12
         + insurance_osago
         + insurance_kasko
         + maintenance_annual
         + fine_risk * 12;
}

void Car::check_random_fine(int stress_value, RUB &account_rub) {
    int chance = 8;
    if (stress_value >= 30)      chance = 25;
    else if (stress_value >= 20) chance = 15;
    else if (stress_value >= 10) chance = 10;

    if (rand() % 100 < chance)
        account_rub -= fine_risk;
}


// Bank

RUB Bank::get_bank_fee() {
    return bank_fee;
}
RUB Bank::get_deposit_balance() {
    return deposit_balance;
}
RUB Bank::get_liquid_rub() {
    return account_rub + (RUB)(account_usd * rate_usd_rub);
}

void Bank::accrue_deposit_interest() {
    deposit_balance += deposit_balance * (deposit_rate / 100.f / 12.f);
}

void Bank::add_monthly_deposit() {
    deposit_balance += monthly_deposit;
    account_rub     -= monthly_deposit;
}


// Country & Economy

Percent Country::Economy::get_current_inflation() {
    return inflation;
}

void Country::Economy::recalculate_inflation(const int year) {
    switch (year) {
        case 2026: inflation = 12.5; break;
        case 2027: inflation = 14.0; break;
        case 2028: inflation = 13.0; break;
        case 2029: inflation = 11.5; break;
    }
}

void Country::Economy::recalculate_prices(list<RUB*> prices) {
    for (RUB* p : prices)
        *p += *p * (get_current_inflation() / 100.);
}


// Health

RUB Health::get_medicine_monthly(int stress_value) {
    if (stress_value >= 30) return medicine_monthly * 2;
    if (stress_value >= 20) return (RUB)(medicine_monthly * 1.5f);
    return medicine_monthly;
}
RUB Health::get_doctor_visit() {
    return doctor_visit;
}
RUB Health::get_dentist_annual() {
    return dentist_annual;
}
RUB Health::get_gym_monthly() {
    return gym_monthly;
}
RUB Health::get_vitamins_monthly() {
    return vitamins_monthly;
}
RUB Health::get_emergency_medical() {
    return emergency_medical;
}
RUB Health::get_optician_annual() {
    return optician_annual;
}
RUB Health::get_psychologist_monthly() {
    return psychologist_monthly;
}
RUB Health::get_total_monthly(int stress_value) {
    return get_medicine_monthly(stress_value)
         + gym_monthly
         + vitamins_monthly
         + psychologist_monthly;
}
RUB Health::get_total_annual_cost() {
    return medicine_monthly * 12
         + gym_monthly * 12
         + vitamins_monthly * 12
         + psychologist_monthly * 12
         + dentist_annual
         + optician_annual
         + doctor_visit * 4;
}


// Phone

RUB Phone::get_monthly_plan() {
    return monthly_plan;
}
RUB Phone::get_replacement_cost() {
    return replacement_cost;
}


// Utilities

RUB Utilities::get_electricity() {
    if (calendar.is_electricity_peak())
        return electricity_base + electricity_winter_extra;
    return electricity_base;
}

RUB Utilities::get_water_monthly() {
    return water_monthly;
}

RUB Utilities::get_heating() {
    if (calendar.is_heating_season())
        return heating_monthly;
    return 0;
}

RUB Utilities::get_internet_monthly() {
    return internet_monthly;
}
RUB Utilities::get_tv_subscription() {
    return tv_subscription;
}

RUB Utilities::get_total_monthly() {
    return get_electricity() + get_water_monthly()
         + get_heating() + get_internet_monthly()
         + get_tv_subscription();
}
RUB Utilities::get_total_annual_cost() {
    RUB electricity_peak_months = 5;
    RUB electricity_normal_months = 7;
    RUB heating_months = 7;

    return electricity_base * 12
         + electricity_winter_extra * electricity_peak_months
         + electricity_base * electricity_normal_months
         + water_monthly * 12
         + heating_monthly * heating_months
         + internet_monthly * 12
         + tv_subscription * 12;
}


// Entertainment

RUB Entertainment::get_streaming_monthly() {
    return streaming_monthly;
}
RUB Entertainment::get_cinema_monthly() {
    return cinema_monthly;
}

RUB Entertainment::get_restaurant_monthly(int stress_value) {
    if (stress_value >= 30) return (RUB)(restaurant_monthly * 0.6f);
    return restaurant_monthly;
}

RUB Entertainment::get_bar_monthly(int stress_value) {
    if (stress_value >= 30) return (RUB)(bar_monthly * 2.0f);
    if (stress_value >= 20) return (RUB)(bar_monthly * 1.4f);
    return bar_monthly;
}

RUB Entertainment::get_concert_quarterly() {
    return concert_quarterly;
}
RUB Entertainment::get_hobbies_monthly() {
    return hobbies_monthly;
}
RUB Entertainment::get_games_monthly() {
    return games_monthly;
}
RUB Entertainment::get_sports_events_annual() {
    return sports_events_annual;
}

RUB Entertainment::get_total_monthly(int stress_value) {
    return streaming_monthly
         + cinema_monthly
         + get_restaurant_monthly(stress_value)
         + get_bar_monthly(stress_value)
         + hobbies_monthly
         + games_monthly;
}
RUB Entertainment::get_total_annual_cost() {
    return streaming_monthly * 12
         + cinema_monthly * 12
         + restaurant_monthly * 12
         + bar_monthly * 12
         + hobbies_monthly * 12
         + games_monthly * 12
         + concert_quarterly * 4
         + sports_events_annual;
}


// Clothing

RUB Clothing::get_summer_wardrobe() {
    return summer_wardrobe;
}
RUB Clothing::get_winter_wardrobe() {
    return winter_wardrobe;
}
RUB Clothing::get_shoes_spring() {
    return shoes_spring;
}
RUB Clothing::get_shoes_autumn() {
    return shoes_autumn;
}
RUB Clothing::get_accessories_annual() {
    return accessories_annual;
}
RUB Clothing::get_sportswear_annual() {
    return sportswear_annual;
}
RUB Clothing::get_formal_wear_annual() {
    return formal_wear_annual;
}
RUB Clothing::get_total_annual_cost() {
    return summer_wardrobe
         + winter_wardrobe
         + shoes_spring
         + shoes_autumn
         + accessories_annual
         + sportswear_annual
         + formal_wear_annual;
}


// PersonalCare

RUB PersonalCare::get_haircut_monthly() {
    return haircut_monthly;
}
RUB PersonalCare::get_cosmetics_monthly() {
    return cosmetics_monthly;
}
RUB PersonalCare::get_pharmacy_monthly() {
    return pharmacy_monthly;
}
RUB PersonalCare::get_massage_monthly() {
    return massage_monthly;
}
RUB PersonalCare::get_manicure_monthly() {
    return manicure_monthly;
}
RUB PersonalCare::get_perfume_biannual() {
    return perfume_biannual;
}
RUB PersonalCare::get_spa_quarterly() {
    return spa_quarterly;
}

RUB PersonalCare::get_total_monthly() {
    return haircut_monthly + cosmetics_monthly + pharmacy_monthly
         + massage_monthly + manicure_monthly;
}
RUB PersonalCare::get_total_annual_cost() {
    return haircut_monthly * 12
         + cosmetics_monthly * 12
         + pharmacy_monthly * 12
         + massage_monthly * 12
         + manicure_monthly * 12
         + perfume_biannual * 2
         + spa_quarterly * 4;
}


// Gifts

RUB Gifts::get_birthday_own() {
    return birthday_own;
}
RUB Gifts::get_birthday_others_annual() {
    return birthday_others_annual;
}
RUB Gifts::get_new_year_gifts() {
    return new_year_gifts;
}
RUB Gifts::get_valentines_day() {
    return valentines_day;
}
RUB Gifts::get_mothers_day() {
    return mothers_day;
}
RUB Gifts::get_fathers_day() {
    return fathers_day;
}
RUB Gifts::get_colleagues_gifts_annual() {
    return colleagues_gifts_annual;
}
RUB Gifts::get_total_annual_cost() {
    return birthday_own
         + birthday_others_annual
         + new_year_gifts
         + valentines_day
         + mothers_day
         + fathers_day
         + colleagues_gifts_annual;
}


// Transport

RUB Transport::get_metro_monthly() {
    return metro_monthly;
}
RUB Transport::get_taxi_monthly() {
    return taxi_monthly;
}
RUB Transport::get_bus_monthly() {
    return bus_monthly;
}
RUB Transport::get_toll_roads_monthly() {
    return toll_roads_monthly;
}

RUB Transport::get_total_monthly() {
    return metro_monthly + taxi_monthly + bus_monthly + toll_roads_monthly;
}
RUB Transport::get_total_annual_cost() {
    return (metro_monthly + taxi_monthly + bus_monthly + toll_roads_monthly) * 12;
}


// Taxes

RUB Taxes::calculate_monthly_income_tax(const RUB monthly_income) {
    return (RUB)(monthly_income * (income_tax_rate / 100.f));
}
RUB Taxes::get_property_tax_annual() {
    return property_tax_annual;
}
RUB Taxes::get_car_tax_annual() {
    return car_tax_annual;
}
RUB Taxes::get_tax_deduction_return() {
    return tax_deduction_return;
}


// Electronics

RUB Electronics::get_laptop_replacement() {
    return laptop_replacement;
}
RUB Electronics::get_headphones_biannual() {
    return headphones_biannual;
}
RUB Electronics::get_smart_watch_biannual() {
    return smart_watch_biannual;
}
RUB Electronics::get_accessories_monthly() {
    return accessories_monthly;
}
RUB Electronics::get_repairs_annual() {
    return repairs_annual;
}
RUB Electronics::get_total_annual_cost() {
    return accessories_monthly * 12
         + repairs_annual
         + headphones_biannual
         + smart_watch_biannual;
}


// Subscriptions

RUB Subscriptions::get_cloud_storage() {
    return cloud_storage;
}
RUB Subscriptions::get_antivirus() {
    return antivirus;
}
RUB Subscriptions::get_office_suite() {
    return office_suite;
}
RUB Subscriptions::get_cloud_backup() {
    return cloud_backup;
}
RUB Subscriptions::get_vpn() {
    return vpn;
}
RUB Subscriptions::get_professional_tools() {
    return professional_tools;
}
RUB Subscriptions::get_password_manager() {
    return password_manager;
}
RUB Subscriptions::get_news_subscription() {
    return news_subscription;
}

RUB Subscriptions::get_total_monthly() {
    return cloud_storage + antivirus + office_suite + cloud_backup
         + vpn + professional_tools + password_manager + news_subscription;
}
RUB Subscriptions::get_total_annual_cost() {
    return get_total_monthly() * 12
         + antivirus
         + office_suite;
}


// Person

const list<RUB*> Person::get_prices_pointers() {
    return {
        &food, &cat, &cat_vet, &trip,
        &home.rent, &home.rental_income, &home.home_insurance,
        &home.repairs_monthly, &home.repairs_annual,
        &home.cleaning_supplies, &home.furniture_annual,
        &car.gas, &car.tires_price, &car.oil_change,
        &car.car_wash, &car.parking_monthly,
        &car.insurance_osago, &car.insurance_kasko,
        &car.maintenance_annual, &car.fine_risk,
        &vtb.monthly_deposit,
        &health.medicine_monthly, &health.doctor_visit, &health.dentist_annual,
        &health.gym_monthly, &health.vitamins_monthly, &health.emergency_medical,
        &health.optician_annual, &health.psychologist_monthly,
        &phone.monthly_plan, &phone.replacement_cost,
        &utilities.electricity_base, &utilities.electricity_winter_extra,
        &utilities.water_monthly, &utilities.heating_monthly,
        &utilities.internet_monthly, &utilities.tv_subscription,
        &entertainment.streaming_monthly, &entertainment.cinema_monthly,
        &entertainment.restaurant_monthly, &entertainment.bar_monthly,
        &entertainment.concert_quarterly, &entertainment.hobbies_monthly,
        &entertainment.games_monthly, &entertainment.sports_events_annual,
        &clothing.summer_wardrobe, &clothing.winter_wardrobe,
        &clothing.shoes_spring, &clothing.shoes_autumn,
        &clothing.accessories_annual, &clothing.sportswear_annual,
        &clothing.formal_wear_annual,
        &personal_care.haircut_monthly, &personal_care.cosmetics_monthly,
        &personal_care.pharmacy_monthly, &personal_care.massage_monthly,
        &personal_care.manicure_monthly, &personal_care.perfume_biannual,
        &personal_care.spa_quarterly,
        &gifts.birthday_own, &gifts.birthday_others_annual,
        &gifts.new_year_gifts, &gifts.valentines_day,
        &gifts.mothers_day, &gifts.fathers_day, &gifts.colleagues_gifts_annual,
        &transport.metro_monthly, &transport.taxi_monthly,
        &transport.bus_monthly, &transport.toll_roads_monthly,
        &electronics.accessories_monthly, &electronics.repairs_annual,
        &electronics.laptop_replacement, &electronics.headphones_biannual,
        &electronics.smart_watch_biannual,
        &subscriptions.cloud_storage, &subscriptions.antivirus,
        &subscriptions.office_suite, &subscriptions.cloud_backup,
        &subscriptions.vpn, &subscriptions.professional_tools,
        &subscriptions.password_manager, &subscriptions.news_subscription
    };
}

RUB Person::get_total_monthly_income() {
    return job.salary + home.rental_income;
}

RUB Person::get_total_monthly_expenses() {
    return home.get_rent()
         + home.get_repairs_monthly()
         + home.get_cleaning_supplies()
         + food
         + cat
         + utilities.get_total_monthly()
         + health.get_total_monthly(mind.stress_value)
         + entertainment.get_total_monthly(mind.stress_value)
         + personal_care.get_total_monthly()
         + transport.get_total_monthly()
         + subscriptions.get_total_monthly()
         + electronics.get_accessories_monthly()
         + phone.get_monthly_plan()
         + car.gas + car.get_car_wash() + car.get_parking_monthly()
         + taxes.calculate_monthly_income_tax(job.salary)
         + vtb.monthly_deposit
         + vtb.bank_fee;
}

RUB Person::get_monthly_surplus() {
    return get_total_monthly_income() - get_total_monthly_expenses();
}

float Person::get_savings_rate() {
    RUB income = get_total_monthly_income();
    if (income == 0) return 0.0f;
    return get_monthly_surplus() / income * 100.0f;
}

void Person::rest() {
    mind.decrease(day_off_stress_decrease);
}

void Person::update_day_off_stress_decrease(){
    day_off_stress_decrease = distr(gen);
}


// Initialization

void alice_init_mind() {
    alice.mind.stress_value       = 0;
    alice.mind.update_stress_level();
}

void alice_init_economy() {
    alice.country.economy.inflation = 12.5;
}

void alice_init_bank() {
    alice.vtb.rate_usd_rub    = 78.76;
    alice.vtb.account_rub     = 0;
    alice.vtb.account_usd     = 1'000;
    alice.vtb.deposit_balance = 0;
    alice.vtb.deposit_rate    = 16.0;
    alice.vtb.monthly_deposit = 10'000;
    alice.vtb.bank_fee        = 200;
}

void alice_init_job() {
    alice.job.salary           = 180'000;
    alice.job.bonus            = 0;
    alice.job.current_workload = 0;
    alice.job.daily_workload   = 100;
    alice.job.workday_stress   = 10;
    alice.job.init_overtime();
}

void alice_init_basics() {
    alice.food    = 3'000;
    alice.cat     = 2'000;
    alice.cat_vet = 5'000;
    alice.trip    = 60'000;
}

void alice_init_home() {
    alice.home.rent              = 30'000;
    alice.home.rental_income     = 25'000;
    alice.home.home_insurance    = 8'000;
    alice.home.repairs_monthly   = 2'000;
    alice.home.repairs_annual    = 20'000;
    alice.home.cleaning_supplies = 1'500;
    alice.home.furniture_annual  = 15'000;
}

void alice_init_car() {
    alice.car.value              = 2'400'000;
    alice.car.gas                = 15'000;
    alice.car.tires_price        = 3'000;
    alice.car.oil_change         = 5'000;
    alice.car.car_wash           = 500;
    alice.car.parking_monthly    = 5'000;
    alice.car.insurance_osago    = 8'000;
    alice.car.insurance_kasko    = 35'000;
    alice.car.maintenance_annual = 15'000;
    alice.car.fine_risk          = 1'500;
}

void alice_init_health() {
    alice.health.medicine_monthly     = 2'000;
    alice.health.doctor_visit         = 3'000;
    alice.health.dentist_annual       = 15'000;
    alice.health.gym_monthly          = 3'000;
    alice.health.vitamins_monthly     = 1'500;
    alice.health.emergency_medical    = 10'000;
    alice.health.optician_annual      = 8'000;
    alice.health.psychologist_monthly = 5'000;
}

void alice_init_phone() {
    alice.phone.monthly_plan            = 700;
    alice.phone.replacement_cost        = 80'000;
    alice.phone.replacement_cycle_years = 2;
}

void alice_init_utilities() {
    alice.utilities.electricity_base         = 2'000;
    alice.utilities.electricity_winter_extra = 800;
    alice.utilities.water_monthly            = 800;
    alice.utilities.heating_monthly          = 3'000;
    alice.utilities.internet_monthly         = 700;
    alice.utilities.tv_subscription          = 300;
}

void alice_init_entertainment() {
    alice.entertainment.streaming_monthly    = 800;
    alice.entertainment.cinema_monthly       = 1'500;
    alice.entertainment.restaurant_monthly   = 5'000;
    alice.entertainment.bar_monthly          = 2'000;
    alice.entertainment.concert_quarterly    = 4'000;
    alice.entertainment.hobbies_monthly      = 3'000;
    alice.entertainment.games_monthly        = 500;
    alice.entertainment.sports_events_annual = 5'000;
}

void alice_init_clothing() {
    alice.clothing.summer_wardrobe    = 15'000;
    alice.clothing.winter_wardrobe    = 20'000;
    alice.clothing.shoes_spring       = 8'000;
    alice.clothing.shoes_autumn       = 8'000;
    alice.clothing.accessories_annual = 10'000;
    alice.clothing.sportswear_annual  = 6'000;
    alice.clothing.formal_wear_annual = 15'000;
}

void alice_init_personal_care() {
    alice.personal_care.haircut_monthly   = 1'500;
    alice.personal_care.cosmetics_monthly = 3'000;
    alice.personal_care.pharmacy_monthly  = 1'000;
    alice.personal_care.massage_monthly   = 3'000;
    alice.personal_care.manicure_monthly  = 2'000;
    alice.personal_care.perfume_biannual  = 5'000;
    alice.personal_care.spa_quarterly     = 4'000;
}

void alice_init_gifts() {
    alice.gifts.birthday_own            = 15'000;
    alice.gifts.birthday_others_annual  = 20'000;
    alice.gifts.new_year_gifts          = 10'000;
    alice.gifts.valentines_day          = 3'000;
    alice.gifts.mothers_day             = 5'000;
    alice.gifts.fathers_day             = 3'000;
    alice.gifts.colleagues_gifts_annual = 8'000;
}

void alice_init_transport() {
    alice.transport.metro_monthly      = 2'500;
    alice.transport.taxi_monthly       = 3'000;
    alice.transport.bus_monthly        = 0;
    alice.transport.toll_roads_monthly = 1'000;
}

void alice_init_taxes() {
    alice.taxes.income_tax_rate      = 13.0;
    alice.taxes.property_tax_annual  = 8'000;
    alice.taxes.car_tax_annual       = 5'000;
    alice.taxes.tax_deduction_return = 0;
}

void alice_init_electronics() {
    alice.electronics.laptop_replacement   = 120'000;
    alice.electronics.laptop_cycle_years   = 3;
    alice.electronics.headphones_biannual  = 5'000;
    alice.electronics.smart_watch_biannual = 15'000;
    alice.electronics.accessories_monthly  = 500;
    alice.electronics.repairs_annual       = 5'000;
}

void alice_init_subscriptions() {
    alice.subscriptions.cloud_storage      = 300;
    alice.subscriptions.antivirus          = 400;
    alice.subscriptions.office_suite       = 500;
    alice.subscriptions.cloud_backup       = 250;
    alice.subscriptions.vpn                = 350;
    alice.subscriptions.professional_tools = 1'500;
    alice.subscriptions.password_manager   = 150;
    alice.subscriptions.news_subscription  = 200;
}

void alice_init() {
    alice_init_mind();
    alice_init_economy();
    alice_init_bank();
    alice_init_job();
    alice_init_basics();
    alice_init_home();
    alice_init_car();
    alice_init_health();
    alice_init_phone();
    alice_init_utilities();
    alice_init_entertainment();
    alice_init_clothing();
    alice_init_personal_care();
    alice_init_gifts();
    alice_init_transport();
    alice_init_taxes();
    alice_init_electronics();
    alice_init_subscriptions();
}


// Simulation functions

void alice_food() {
    if (!calendar.is_first_day()) return;

    RUB food_cost = (RUB)(alice.food * alice.mind.spending_factor());
    if (calendar.is_december()) food_cost += 2000;

    alice.vtb.account_rub -= food_cost;
}

void alice_home() {
    if (!calendar.is_first_day()) return;

    alice.vtb.account_rub -= alice.home.get_rent();
    alice.vtb.account_rub -= alice.home.get_repairs_monthly();
    alice.vtb.account_rub -= alice.home.get_cleaning_supplies();
    alice.vtb.account_rub -= alice.home.get_unexpected_repair();

    if (calendar.is_january())  alice.vtb.account_rub -= alice.home.get_home_insurance();
    if (calendar.is_march())    alice.vtb.account_rub -= alice.home.get_furniture_annual();
    if (calendar.is_june())     alice.vtb.account_rub -= alice.home.get_repairs_annual();
}

void alice_job() {
    if (calendar.is_first_day()) {
        if (calendar.is_march()) {
            alice.job.promote();
            alice.job.init_overtime();
        }
        if (calendar.is_february() && calendar.is_year(2026))
            alice.vtb.account_rub += alice.job.get_bonus();
    }

    if (calendar.is_weekday()) {
        alice.job.increase_current_workload_by_days(1);
        alice.job.do_overtime(alice.job.what_overtime_needed(), alice.mind.stress_value, alice.vtb.account_rub);
        alice.job.do_work(alice.mind.stress_value, alice.vtb.account_rub);
    }
}

void alice_car() {
    if (!calendar.is_first_day()) return;

    alice.vtb.account_rub -= alice.car.gas;
    alice.vtb.account_rub -= alice.car.get_car_wash();
    alice.vtb.account_rub -= alice.car.get_parking_monthly();
    alice.car.check_random_fine(alice.mind.stress_value, alice.vtb.account_rub);

    if (calendar.is_april() || calendar.is_october())   alice.vtb.account_rub -= alice.car.get_tires_price();
    if (calendar.is_march() || calendar.is_september()) alice.vtb.account_rub -= alice.car.get_oil_change();

    if (calendar.is_may()) {
        alice.vtb.account_rub -= alice.car.get_insurance_osago();
        alice.vtb.account_rub -= alice.car.get_insurance_kasko();
    }

    if (calendar.is_november()) alice.vtb.account_rub -= alice.car.get_maintenance_annual();
}

void alice_cat() {
    if (!calendar.is_first_day()) return;

    if (calendar.is_march() || calendar.is_september())
        alice.vtb.account_rub -= alice.cat_vet;

    alice.vtb.account_rub -= alice.cat;
}

void alice_trip() {
    if (calendar.is_first_day() && calendar.is_july())
        alice.vtb.account_rub -= alice.trip;
}

void alice_rent() {
    if (calendar.is_first_day())
        alice.vtb.account_rub += alice.home.get_rental_income();
}

void alice_mortgage() {
    if (calendar.is_first_day())
        alice.vtb.account_rub -= 45'000;
}

void alice_health() {
    if (!calendar.is_first_day()) return;

    alice.vtb.account_rub -= alice.health.get_medicine_monthly(alice.mind.stress_value);
    alice.vtb.account_rub -= alice.health.get_gym_monthly();
    alice.vtb.account_rub -= alice.health.get_vitamins_monthly();
    alice.vtb.account_rub -= alice.health.get_psychologist_monthly();

    if (calendar.is_quarter_end())  alice.vtb.account_rub -= alice.health.get_doctor_visit();
    if (calendar.is_april())        alice.vtb.account_rub -= alice.health.get_dentist_annual();
    if (calendar.is_july())         alice.vtb.account_rub -= alice.health.get_optician_annual();

    if (calendar.is_august() && calendar.is_year(2027))
        alice.vtb.account_rub -= alice.health.get_emergency_medical();
}

void alice_phone() {
    if (!calendar.is_first_day()) return;

    alice.vtb.account_rub -= alice.phone.get_monthly_plan();

    if (calendar.is_september() && calendar.is_year(2026))
        alice.vtb.account_rub -= alice.phone.get_replacement_cost();

    if (calendar.is_september() && calendar.is_year(2028))
        alice.vtb.account_rub -= alice.phone.get_replacement_cost();
}

void alice_utilities() {
    if (calendar.is_first_day())
        alice.vtb.account_rub -= alice.utilities.get_total_monthly();
}

void alice_entertainment() {
    if (!calendar.is_first_day()) return;

    alice.vtb.account_rub -= alice.entertainment.get_total_monthly(alice.mind.stress_value);

    if (calendar.is_quarter_end()) alice.vtb.account_rub -= alice.entertainment.get_concert_quarterly();
    if (calendar.is_august())      alice.vtb.account_rub -= alice.entertainment.get_sports_events_annual();
}

void alice_clothing() {
    if (!calendar.is_first_day()) return;

    if (calendar.is_april()) {
        alice.vtb.account_rub -= alice.clothing.get_summer_wardrobe();
        alice.vtb.account_rub -= alice.clothing.get_shoes_spring();
    }

    if (calendar.is_october()) {
        alice.vtb.account_rub -= alice.clothing.get_winter_wardrobe();
        alice.vtb.account_rub -= alice.clothing.get_shoes_autumn();
    }

    if (calendar.is_january()) {
        alice.vtb.account_rub -= alice.clothing.get_accessories_annual();
        alice.vtb.account_rub -= alice.clothing.get_formal_wear_annual();
    }

    if (calendar.is_may()) alice.vtb.account_rub -= alice.clothing.get_sportswear_annual();
}

void alice_personal_care() {
    if (!calendar.is_first_day()) return;

    alice.vtb.account_rub -= alice.personal_care.get_total_monthly();

    if (calendar.is_april() || calendar.is_october())
        alice.vtb.account_rub -= alice.personal_care.get_perfume_biannual();

    if (calendar.is_quarter_end())
        alice.vtb.account_rub -= alice.personal_care.get_spa_quarterly();
}

void alice_gifts() {
    if (!calendar.is_first_day()) return;

    if (calendar.is_february())  alice.vtb.account_rub -= alice.gifts.get_valentines_day();
    if (calendar.is_march())     alice.vtb.account_rub -= alice.gifts.get_mothers_day();
    if (calendar.is_may())       alice.vtb.account_rub -= alice.gifts.get_birthday_own();
    if (calendar.is_june())      alice.vtb.account_rub -= alice.gifts.get_fathers_day();
    if (calendar.is_october())   alice.vtb.account_rub -= alice.gifts.get_birthday_others_annual();
    if (calendar.is_november())  alice.vtb.account_rub -= alice.gifts.get_colleagues_gifts_annual();
    if (calendar.is_december())  alice.vtb.account_rub -= alice.gifts.get_new_year_gifts();
}

void alice_transport() {
    if (calendar.is_first_day())
        alice.vtb.account_rub -= alice.transport.get_total_monthly();
}

void alice_taxes() {
    if (!calendar.is_first_day()) return;

    alice.vtb.account_rub -= alice.taxes.calculate_monthly_income_tax(alice.job.salary);

    if (calendar.is_december()) {
        alice.vtb.account_rub -= alice.taxes.get_property_tax_annual();
        alice.vtb.account_rub -= alice.taxes.get_car_tax_annual();
    }

    if (calendar.is_april())
        alice.vtb.account_rub += alice.taxes.get_tax_deduction_return();
}

void alice_electronics() {
    if (!calendar.is_first_day()) return;

    alice.vtb.account_rub -= alice.electronics.get_accessories_monthly();

    if (calendar.is_june()      && calendar.is_year(2027))
        alice.vtb.account_rub -= alice.electronics.get_laptop_replacement();

    if (calendar.is_march()     && (calendar.is_year(2026) || calendar.is_year(2028)))
        alice.vtb.account_rub -= alice.electronics.get_headphones_biannual();

    if (calendar.is_september() && (calendar.is_year(2026) || calendar.is_year(2028)))
        alice.vtb.account_rub -= alice.electronics.get_smart_watch_biannual();

    if (calendar.is_january())
        alice.vtb.account_rub -= alice.electronics.get_repairs_annual();
}

void alice_subscriptions() {
    if (!calendar.is_first_day()) return;

    alice.vtb.account_rub -= alice.subscriptions.get_total_monthly();

    if (calendar.is_january()) alice.vtb.account_rub -= alice.subscriptions.get_antivirus();
    if (calendar.is_june())    alice.vtb.account_rub -= alice.subscriptions.get_office_suite();
}

void alice_bank() {
    if (!calendar.is_first_day()) return;

    alice.vtb.account_rub -= alice.vtb.get_bank_fee();
    alice.vtb.add_monthly_deposit();
    alice.vtb.accrue_deposit_interest();

    if (calendar.is_december())
        alice.vtb.account_rub += (RUB)(alice.vtb.account_usd * alice.vtb.rate_usd_rub * 0.01f);
}

void alice_economy() {
    alice.country.economy.recalculate_inflation(calendar.year);

    if (calendar.is_new_year())
        alice.country.economy.recalculate_prices(alice.get_prices_pointers());
}

void alice_rest() {
    if (calendar.is_weekend())
        alice.rest();
}

void alice_savings_review() {
    if (!calendar.is_first_day()) return;
    if (!calendar.is_quarter_end()) return;

    RUB surplus = alice.get_monthly_surplus();
    if (surplus > alice.vtb.monthly_deposit * 2)
        alice.vtb.monthly_deposit += 2'000;
}

void alice_year_end() {
    if (!calendar.is_year_end()) return;

    alice.mind.update_stress_level();

    RUB income      = alice.get_total_monthly_income();
    RUB expenses    = alice.get_total_monthly_expenses();
    RUB surplus     = alice.get_monthly_surplus();
    float save_rate = alice.get_savings_rate();

    RUB net_worth = alice.vtb.account_rub
                  + alice.vtb.account_usd * (USD)alice.vtb.rate_usd_rub
                  + alice.vtb.get_deposit_balance()
                  + alice.car.value;

    cout << endl;
    cout << "--- YEAR " << calendar.year << " SUMMARY ---" << endl;
    printf("  Cash balance          = %lld RUB\n",    alice.vtb.account_rub);
    printf("  Deposit balance       = %lld RUB\n",    alice.vtb.get_deposit_balance());
    printf("  Liquid (cash + USD)   = %lld RUB\n",    alice.vtb.get_liquid_rub());
    printf("  Net worth             = %lld RUB\n",    net_worth);
    printf("  Monthly income        = %lld RUB\n",    income);
    printf("  Monthly expenses      = %lld RUB\n",    expenses);
    printf("  Monthly surplus       = %lld RUB\n",    surplus);
    printf("  Savings rate          = %.1f%%\n",      save_rate);
    printf("  Annual gross income   = %lld RUB\n",    alice.job.get_annual_gross());
    printf("  Annual net income     = %lld RUB\n",    alice.job.get_annual_net(alice.taxes.income_tax_rate));
    printf("  Current salary        = %lld RUB/mo\n", alice.job.salary);
    printf("  Rental income         = %lld RUB/mo\n", alice.home.rental_income);
    printf("  Stress level          = %s (%d)\n",
           alice.mind.stress_level.c_str(), alice.mind.stress_value);
    printf("  Productivity          = %.0f%%\n",      alice.mind.productivity_factor() * 100);
    printf("  Inflation this year   = %.1f%%\n",
           alice.country.economy.get_current_inflation());
    cout << endl;
}

void print_results() {
    cout << endl;
    cout << "======================================" << endl;
    cout << "  SIMULATION RESULTS (Feb 2029)      " << endl;
    cout << "======================================" << endl;

    cout << endl;
    cout << "--- JOB ---" << endl;
    printf("  Salary         = %lld RUB\n", alice.job.salary);
    printf("  Bonus received = %lld RUB\n", alice.job.bonus);
    printf("  Workload left  = %d units\n",  alice.job.current_workload);

    cout << endl;
    cout << "--- BANK ---" << endl;
    printf("  Cash balance   = %lld RUB\n", alice.vtb.account_rub);
    printf("  USD account    = %lld USD\n", alice.vtb.account_usd);
    printf("  Deposit        = %lld RUB\n", alice.vtb.get_deposit_balance());
    printf("  Liquid total   = %lld RUB\n", alice.vtb.get_liquid_rub());

    RUB net_worth = alice.vtb.account_rub
                  + alice.vtb.account_usd * (USD)alice.vtb.rate_usd_rub
                  + alice.vtb.get_deposit_balance()
                  + alice.car.value;
    printf("  Net worth      = %lld RUB\n", net_worth);

    cout << endl;
    cout << "--- ECONOMY ---" << endl;
    cout << "  Inflation      = " << alice.country.economy.get_current_inflation() << "%" << endl;

    cout << endl;
    cout << "--- MONTHLY CASH FLOW ---" << endl;
    printf("  Income         = %lld RUB\n", alice.get_total_monthly_income());
    printf("  Expenses       = %lld RUB\n", alice.get_total_monthly_expenses());
    printf("  Surplus        = %lld RUB\n", alice.get_total_monthly_income() - alice.get_total_monthly_expenses());

    cout << endl;
    cout << "--- CURRENT MONTHLY PRICES (inflation-adjusted) ---" << endl;
    printf("  Food           = %lld RUB\n", alice.food);
    printf("  Rent           = %lld RUB\n", alice.home.rent);
    printf("  Gas            = %lld RUB\n", alice.car.gas);
    printf("  Cat (monthly)  = %lld RUB\n", alice.cat);
    printf("  Cat (vet)      = %lld RUB\n", alice.cat_vet);
    printf("  Trip (annual)  = %lld RUB\n", alice.trip);

    cout << endl;
    cout << "--- HEALTH (monthly base prices) ---" << endl;
    printf("  Medicine       = %lld RUB\n", alice.health.medicine_monthly);
    printf("  Gym            = %lld RUB\n", alice.health.gym_monthly);
    printf("  Vitamins       = %lld RUB\n", alice.health.vitamins_monthly);
    printf("  Psychologist   = %lld RUB\n", alice.health.psychologist_monthly);
    printf("  Doctor (visit) = %lld RUB\n", alice.health.doctor_visit);
    printf("  Dentist (ann.) = %lld RUB\n", alice.health.dentist_annual);
    printf("  Optician (ann.)= %lld RUB\n", alice.health.optician_annual);

    cout << endl;
    cout << "--- UTILITIES (monthly base prices) ---" << endl;
    printf("  Electricity    = %lld RUB\n", alice.utilities.electricity_base);
    printf("  Water          = %lld RUB\n", alice.utilities.water_monthly);
    printf("  Heating        = %lld RUB\n", alice.utilities.heating_monthly);
    printf("  Internet       = %lld RUB\n", alice.utilities.internet_monthly);
    printf("  TV             = %lld RUB\n", alice.utilities.tv_subscription);

    cout << endl;
    cout << "--- ENTERTAINMENT (monthly base prices) ---" << endl;
    printf("  Streaming      = %lld RUB\n", alice.entertainment.streaming_monthly);
    printf("  Cinema         = %lld RUB\n", alice.entertainment.cinema_monthly);
    printf("  Restaurants    = %lld RUB\n", alice.entertainment.restaurant_monthly);
    printf("  Bar            = %lld RUB\n", alice.entertainment.bar_monthly);
    printf("  Hobbies        = %lld RUB\n", alice.entertainment.hobbies_monthly);

    cout << endl;
    cout << "--- PERSONAL CARE (monthly base prices) ---" << endl;
    printf("  Haircut        = %lld RUB\n", alice.personal_care.haircut_monthly);
    printf("  Cosmetics      = %lld RUB\n", alice.personal_care.cosmetics_monthly);
    printf("  Massage        = %lld RUB\n", alice.personal_care.massage_monthly);
    printf("  Manicure       = %lld RUB\n", alice.personal_care.manicure_monthly);

    cout << endl;
    cout << "--- CAR (current prices) ---" << endl;
    printf("  Gas (monthly)  = %lld RUB\n", alice.car.gas);
    printf("  Tires          = %lld RUB\n", alice.car.tires_price);
    printf("  Oil change     = %lld RUB\n", alice.car.oil_change);
    printf("  Car wash       = %lld RUB\n", alice.car.car_wash);
    printf("  Parking        = %lld RUB\n", alice.car.parking_monthly);
    printf("  OSAGO (ann.)   = %lld RUB\n", alice.car.insurance_osago);
    printf("  KASKO (ann.)   = %lld RUB\n", alice.car.insurance_kasko);
    printf("  Maintenance    = %lld RUB\n", alice.car.maintenance_annual);
    printf("  Fine risk      = %lld RUB\n", alice.car.fine_risk);
    printf("  Total (ann.)   = %lld RUB\n", alice.car.get_total_annual_cost());

    cout << endl;
    cout << "--- TRANSPORT (current prices) ---" << endl;
    printf("  Metro          = %lld RUB\n", alice.transport.metro_monthly);
    printf("  Taxi           = %lld RUB\n", alice.transport.taxi_monthly);
    printf("  Toll roads     = %lld RUB\n", alice.transport.toll_roads_monthly);

    cout << endl;
    cout << "--- CLOTHING (current prices) ---" << endl;
    printf("  Summer clothes = %lld RUB\n", alice.clothing.summer_wardrobe);
    printf("  Winter clothes = %lld RUB\n", alice.clothing.winter_wardrobe);
    printf("  Shoes spring   = %lld RUB\n", alice.clothing.shoes_spring);
    printf("  Shoes autumn   = %lld RUB\n", alice.clothing.shoes_autumn);
    printf("  Accessories    = %lld RUB\n", alice.clothing.accessories_annual);
    printf("  Sportswear     = %lld RUB\n", alice.clothing.sportswear_annual);
    printf("  Formal wear    = %lld RUB\n", alice.clothing.formal_wear_annual);
    printf("  Total (ann.)   = %lld RUB\n", alice.clothing.get_total_annual_cost());

    cout << endl;
    cout << "--- GIFTS (current prices) ---" << endl;
    printf("  Own birthday   = %lld RUB\n", alice.gifts.birthday_own);
    printf("  Others b-days  = %lld RUB\n", alice.gifts.birthday_others_annual);
    printf("  New Year       = %lld RUB\n", alice.gifts.new_year_gifts);
    printf("  Valentine's    = %lld RUB\n", alice.gifts.valentines_day);
    printf("  Mother's Day   = %lld RUB\n", alice.gifts.mothers_day);
    printf("  Father's Day   = %lld RUB\n", alice.gifts.fathers_day);
    printf("  Colleagues     = %lld RUB\n", alice.gifts.colleagues_gifts_annual);
    printf("  Total (ann.)   = %lld RUB\n", alice.gifts.get_total_annual_cost());

    cout << endl;
    cout << "--- SUBSCRIPTIONS (current prices) ---" << endl;
    printf("  Cloud storage  = %lld RUB\n", alice.subscriptions.cloud_storage);
    printf("  Antivirus      = %lld RUB\n", alice.subscriptions.antivirus);
    printf("  Office suite   = %lld RUB\n", alice.subscriptions.office_suite);
    printf("  Cloud backup   = %lld RUB\n", alice.subscriptions.cloud_backup);
    printf("  VPN            = %lld RUB\n", alice.subscriptions.vpn);
    printf("  Pro tools      = %lld RUB\n", alice.subscriptions.professional_tools);
    printf("  Password mgr   = %lld RUB\n", alice.subscriptions.password_manager);
    printf("  News           = %lld RUB\n", alice.subscriptions.news_subscription);
    printf("  Total/month    = %lld RUB\n", alice.subscriptions.get_total_monthly());

    cout << endl;
    cout << "--- ELECTRONICS (current prices) ---" << endl;
    printf("  Laptop (once)  = %lld RUB\n", alice.electronics.laptop_replacement);
    printf("  Headphones     = %lld RUB\n", alice.electronics.headphones_biannual);
    printf("  Smart watch    = %lld RUB\n", alice.electronics.smart_watch_biannual);
    printf("  Accessories    = %lld RUB\n", alice.electronics.accessories_monthly);
    printf("  Repairs (ann.) = %lld RUB\n", alice.electronics.repairs_annual);

    cout << endl;
    cout << "--- HOME (current prices) ---" << endl;
    printf("  Home insurance = %lld RUB\n", alice.home.home_insurance);
    printf("  Repairs (mo.)  = %lld RUB\n", alice.home.repairs_monthly);
    printf("  Repairs (ann.) = %lld RUB\n", alice.home.repairs_annual);
    printf("  Cleaning       = %lld RUB\n", alice.home.cleaning_supplies);
    printf("  Furniture      = %lld RUB\n", alice.home.furniture_annual);
    printf("  Rental income  = %lld RUB\n", alice.home.rental_income);
    printf("  Total (ann.)   = %lld RUB\n", alice.home.get_total_annual_cost());

    cout << endl;
    cout << "--- TAXES ---" << endl;
    printf("  Income tax     = %.1f%%\n",   alice.taxes.income_tax_rate);
    printf("  Property tax   = %lld RUB\n", alice.taxes.property_tax_annual);
    printf("  Car tax        = %lld RUB\n", alice.taxes.car_tax_annual);

    cout << endl;
    cout << "--- STRESS ---" << endl;
    alice.mind.update_stress_level();
    cout << "  Stress value   = " << alice.mind.stress_value << endl;
    cout << "  Stress level   = " << alice.mind.stress_level << endl;
    printf("  Productivity   = %.0f%%\n", alice.mind.productivity_factor() * 100);

    cout << endl;
    cout << "--- ANNUAL INCOME ---" << endl;
    printf("  Gross income   = %lld RUB\n", alice.job.get_annual_gross());
    printf("  Net income     = %lld RUB\n", alice.job.get_annual_net(alice.taxes.income_tax_rate));
    printf("  Rental income  = %lld RUB\n", alice.home.rental_income * 12);
    printf("  Savings rate   = %.1f%%\n",   alice.get_savings_rate());
    printf("  Monthly surplus= %lld RUB\n", alice.get_monthly_surplus());

    cout << endl;
    cout << "--- ANNUAL BUDGET BREAKDOWN ---" << endl;
    printf("  Home           = %lld RUB\n", alice.home.get_total_annual_cost());
    printf("  Car            = %lld RUB\n", alice.car.get_total_annual_cost());
    printf("  Health         = %lld RUB\n", alice.health.get_total_annual_cost());
    printf("  Utilities      = %lld RUB\n", alice.utilities.get_total_annual_cost());
    printf("  Entertainment  = %lld RUB\n", alice.entertainment.get_total_annual_cost());
    printf("  Clothing       = %lld RUB\n", alice.clothing.get_total_annual_cost());
    printf("  Personal care  = %lld RUB\n", alice.personal_care.get_total_annual_cost());
    printf("  Gifts          = %lld RUB\n", alice.gifts.get_total_annual_cost());
    printf("  Transport      = %lld RUB\n", alice.transport.get_total_annual_cost());
    printf("  Electronics    = %lld RUB\n", alice.electronics.get_total_annual_cost());
    printf("  Subscriptions  = %lld RUB\n", alice.subscriptions.get_total_annual_cost());

    RUB annual_total = alice.home.get_total_annual_cost()
                     + alice.car.get_total_annual_cost()
                     + alice.health.get_total_annual_cost()
                     + alice.utilities.get_total_annual_cost()
                     + alice.entertainment.get_total_annual_cost()
                     + alice.clothing.get_total_annual_cost()
                     + alice.personal_care.get_total_annual_cost()
                     + alice.gifts.get_total_annual_cost()
                     + alice.transport.get_total_annual_cost()
                     + alice.electronics.get_total_annual_cost()
                     + alice.subscriptions.get_total_annual_cost();
    printf("  TOTAL          = %lld RUB\n", annual_total);

    cout << endl;
    cout << "======================================" << endl;
}

void simulation() {
    calendar.start(1, 2, 2026, 6);

    while (!calendar.reached(2, 2029)) {
        alice_food();
        alice_home();
        alice_car();
        alice_cat();
        alice_trip();
        alice_rent();
        alice_mortgage();
        alice_economy();
        alice_health();
        alice_phone();
        alice_utilities();
        alice_entertainment();
        alice_clothing();
        alice_personal_care();
        alice_gifts();
        alice_transport();
        alice_taxes();
        alice_electronics();
        alice_subscriptions();
        alice_bank();
        alice_job();
        alice_rest();
        alice_savings_review();
        alice_year_end();

        alice.update_day_off_stress_decrease();
        calendar.next_day();
        cout<<alice.day_off_stress_decrease<<" ";
    }
}


int main() {
    alice_init();
    simulation();
    print_results();
}
