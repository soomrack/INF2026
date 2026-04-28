// ============================================================
// Life Simulation — Alice
//
// Models the financial life of a person named Alice over a
// three-year period (February 2026 – February 2029).
//
// Structs:
//   Calendar        — day / month / year tracking, leap-year handling
//   Stress          — numeric stress value + level string
//                     (Cheerful / Normal / Exhausted / Frenzy)
//                     Level influences food spending, medicine costs,
//                     entertainment, job productivity and fine probability
//   Home            — rent, rental income, insurance, repairs, cleaning,
//                     furniture; random unexpected repair events
//   Job             — salary, workload, overtime tiers
//     Job::Overtime — workload decrease, stress increase, pay multiplier
//                     Stress level reduces productivity and overtime output
//   Car             — fuel, tires, oil, wash, parking, OSAGO, KASKO,
//                     maintenance; random traffic fine events
//   Bank            — cash account (RUB), USD account, timed deposit
//                     with monthly interest accrual
//   Country::Economy— inflation rate per year; propagates to all prices
//                     on January 1st via pointer list
//   Health          — medicine, gym, vitamins, doctor, dentist, optician,
//                     psychologist, emergency; stress raises medicine cost
//   Phone           — monthly plan, periodic phone replacement
//   Utilities       — electricity (base + winter extra), water, heating
//                     (seasonal), internet, TV subscription
//   Entertainment   — streaming, cinema, restaurants, bar, concerts,
//                     hobbies, games, sports events; stress raises bar cost
//   Clothing        — seasonal wardrobe, shoes, accessories, sportswear,
//                     formal wear
//   PersonalCare    — haircut, cosmetics, pharmacy, massage, manicure,
//                     perfume, spa
//   Gifts           — own birthday, friends' birthdays, New Year,
//                     Valentine's Day, Mother's/Father's Day, colleagues
//   Transport       — metro, taxi, bus, toll roads
//   Taxes           — income tax 13%, property tax, car tax (annual)
//   Electronics     — laptop, headphones, smart watch, accessories, repairs
//   Subscriptions   — cloud storage, antivirus, office suite, cloud backup,
//                     VPN, professional tools, password manager, news
//   Person          — aggregates all structs; owns the inflation pointer list
//
// All variable prices are inflation-adjusted once per year on
// January 1st via Country::Economy::recalculate_prices().
// Mortgage payments and income taxes are fixed / percentage-based
// and therefore excluded from inflation recalculation.
// ============================================================

#include <stdio.h>
#include <iostream>
#include <list>
#include <array>
#include <cstdlib>
#include <ctime>


using std::cout;
using std::endl;

using std::list;
using std::array;

using std::string;


using Percent = float;

using RUB = long long int;
using USD = long long int;

using USint = unsigned short int;


// ============================================================
// STRUCT DECLARATIONS
// ============================================================

struct Calendar{
    const array<USint, 12> normal_year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const array<USint, 12> leap_year = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    array<USint, 12> year_days;
    USint year;
    USint month;
    USint day;
    USint weekday;

    USint get_days_in_month();
    void update_year_days();
    void advance();
};

Calendar calendar;

struct Stress {
    USint stress_value;
    string stress_level;

    void update_stress_level();
    const USint* get_stress_pointer();
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
};


struct Job {
    RUB salary;
    RUB bonus;

    USint current_workload;
    USint daily_workload;

    USint workday_stress;

    struct Overtime {
        USint workload_decrease;
        USint stress_increase;
        Percent extra_pay_multiplier;

    public:
        Overtime (const int workload, const Percent multiplier, const int stress_value);

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

    RUB get_daily_pay();
    RUB get_bonus();
    void promote();
    USint get_current_workload();
    void increase_current_workload_by_days(const USint days);
    Overtime what_overtime_needed();
    void do_work(USint &stress_value, RUB &account_rub);
    void do_overtime(const Overtime overtime, USint &stress_value, RUB &account_rub);
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

    RUB get_tires_price();
    RUB get_oil_change();
    RUB get_car_wash();
    RUB get_parking_monthly();
    RUB get_insurance_osago();
    RUB get_insurance_kasko();
    RUB get_maintenance_annual();
    RUB get_fine_risk();
};


struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
    RUB deposit_balance;
    Percent deposit_rate;
    RUB monthly_deposit;
    RUB bank_fee;

    RUB get_bank_fee();
    RUB get_deposit_balance();
    void accrue_deposit_interest();
    void add_monthly_deposit();
};


struct Country {

    struct Economy {
        Percent inflation;

        Percent get_current_inflation();
        void recalculate_inflation(const int year);
        void recalculate_prices(list<RUB*> prices);
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

    RUB get_medicine_monthly();
    RUB get_doctor_visit();
    RUB get_dentist_annual();
    RUB get_gym_monthly();
    RUB get_vitamins_monthly();
    RUB get_emergency_medical();
    RUB get_optician_annual();
    RUB get_psychologist_monthly();
};


struct Phone {
    RUB monthly_plan;
    RUB replacement_cost;
    USint replacement_cycle_years;

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

    RUB get_electricity(const USint month);
    RUB get_water_monthly();
    RUB get_heating(const USint month);
    RUB get_internet_monthly();
    RUB get_tv_subscription();
    RUB get_total_monthly(const USint month);
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
    RUB get_restaurant_monthly();
    RUB get_bar_monthly();
    RUB get_concert_quarterly();
    RUB get_hobbies_monthly();
    RUB get_games_monthly();
    RUB get_sports_events_annual();
    RUB get_total_monthly();
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
};


struct Taxes {
    Percent income_tax_rate;
    Percent property_tax_rate;
    RUB property_tax_annual;
    RUB car_tax_annual;
    RUB tax_deduction_return;

    RUB calculate_monthly_income_tax(const RUB monthly_income);
    RUB get_property_tax_annual();
    RUB get_car_tax_annual();
    RUB get_tax_deduction_return();
};


struct Electronics {
    RUB laptop_replacement;
    USint laptop_cycle_years;
    RUB headphones_biannual;
    RUB smart_watch_biannual;
    RUB accessories_monthly;
    RUB repairs_annual;

    RUB get_laptop_replacement();
    RUB get_headphones_biannual();
    RUB get_smart_watch_biannual();
    RUB get_accessories_monthly();
    RUB get_repairs_annual();
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
};


struct Person {
    Stress mind;
    Home home;
    Country country;
    Bank vtb;
    Job job;
    RUB food;
    RUB cat;
    RUB cat_vet;
    RUB trip;
    Car car;
    Health health;
    Phone phone;
    Utilities utilities;
    Entertainment entertainment;
    Clothing clothing;
    PersonalCare personal_care;
    Gifts gifts;
    Transport transport;
    Taxes taxes;
    Electronics electronics;
    Subscriptions subscriptions;

    USint day_off_stress_decrease;

    const list<RUB*> get_prices_pointers();
    void rest();
};


struct Person alice;


// ============================================================
// IMPLEMENTATIONS
// ============================================================

//Calendar
USint Calendar::get_days_in_month()
    {
        return year_days[month-1];
    }
void Calendar::update_year_days()
    {
        if (year%4 != 0){
            year_days = normal_year;
        }

        else if (year%4 == 0){
            year_days = leap_year;
        }
    }
void Calendar::advance()
    {
        day++;
        weekday++;

        if (weekday > 7){
            weekday = 1;
        }

        if (day>year_days[month-1]){
            ++month;
            day = 1;
        }

        if (month == 13) {
            ++year;
            update_year_days();
            month = 1;
        }
    }

//Stress
void Stress::update_stress_level()
    {
        if (stress_value < 30){
            stress_level = "Cheerful";
        }

        else if (stress_value < 60){
            stress_level = "Normal";
        }

        else if (stress_value < 90){
            stress_level = "Exhausted";
        }

        else {
            stress_level = "Frenzy";
        }
    }
const USint* Stress::get_stress_pointer()
    {
        USint* stress_pointer = &stress_value;

        return stress_pointer;
    }

//Home
RUB Home::get_rent()
    {
        return rent;
    }
RUB Home::get_rental_income()
    {
        return rental_income;
    }
RUB Home::get_home_insurance()
    {
        return home_insurance;
    }
RUB Home::get_repairs_monthly()
    {
        return repairs_monthly;
    }
RUB Home::get_repairs_annual()
    {
        return repairs_annual;
    }
RUB Home::get_cleaning_supplies()
    {
        return cleaning_supplies;
    }
RUB Home::get_furniture_annual()
    {
        return furniture_annual;
    }

//Job&Overtime
Job::Overtime::Overtime (const int workload, const Percent multiplier, const int stress_value)
    {
        workload_decrease = workload;
        stress_increase = stress_value;
        extra_pay_multiplier = multiplier;
    }
RUB Job::get_daily_pay()
    {
        return salary/calendar.get_days_in_month();
    }
RUB Job::get_bonus()
    {
        return bonus;
    }
void Job::promote()
    {
        salary *= 1.5;
    }
USint Job::get_current_workload()
    {
        return current_workload;
    }
void Job::increase_current_workload_by_days(const USint days)
    {
        current_workload += days * daily_workload;
    }
Job::Overtime Job::what_overtime_needed()
    {
        if (current_workload <= daily_workload)
        {
            return zero_overtime;
        }

        else if (current_workload > daily_workload && current_workload <= daily_workload*2)
        {
            return small_overtime;
        }

        else if (current_workload*2 > daily_workload && current_workload <= daily_workload*3)
        {
            return meduim_overtime;
        }

        else if (current_workload*3 > daily_workload && current_workload <= daily_workload*4)
        {
            return large_overtime;
        }

        return zero_overtime;
    }
void Job::do_work(USint &stress_value, RUB &account_rub)
    {
        current_workload -= daily_workload;
        stress_value += workday_stress;
        if (stress_value > 100){
            stress_value = 100;
        }
        account_rub += get_daily_pay();
    }
void Job::do_overtime(const Overtime overtime, USint &stress_value, RUB &account_rub)
    {
        current_workload -= overtime.workload_decrease;
        stress_value += overtime.stress_increase;
        if (stress_value > 100){
            stress_value = 100;
        }
        account_rub += get_daily_pay()*overtime.extra_pay_multiplier;
    }

//Car
RUB Car::get_tires_price()
    {
        return tires_price;
    }
RUB Car::get_oil_change()
    {
        return oil_change;
    }
RUB Car::get_car_wash()
    {
        return car_wash;
    }
RUB Car::get_parking_monthly()
    {
        return parking_monthly;
    }
RUB Car::get_insurance_osago()
    {
        return insurance_osago;
    }
RUB Car::get_insurance_kasko()
    {
        return insurance_kasko;
    }
RUB Car::get_maintenance_annual()
    {
        return maintenance_annual;
    }
RUB Car::get_fine_risk()
    {
        return fine_risk;
    }

//Bank
RUB Bank::get_bank_fee()
    {
        return bank_fee;
    }
RUB Bank::get_deposit_balance()
    {
        return deposit_balance;
    }
void Bank::accrue_deposit_interest()
    {
        deposit_balance += deposit_balance * (deposit_rate / 100.f / 12.f);
    }
void Bank::add_monthly_deposit()
    {
        deposit_balance += monthly_deposit;
        account_rub    -= monthly_deposit;
    }

//Country&Economy
Percent Country::Economy::get_current_inflation()
    {
        return inflation;
    }
void Country::Economy::recalculate_inflation(const int year)
    {
        switch (year)
        {
            case 2026: inflation = 12.5; break;
            case 2027: inflation = 14.0; break;
            case 2028: inflation = 13.0; break;
            case 2029: inflation = 11.5; break;
        }
    }
void Country::Economy::recalculate_prices(list<RUB*> prices)
    {
        for (RUB* i : prices){
        *i += *i*(get_current_inflation()/100.);
        }
    }

//Health
RUB Health::get_medicine_monthly()
    {
        return medicine_monthly;
    }
RUB Health::get_doctor_visit()
    {
        return doctor_visit;
    }
RUB Health::get_dentist_annual()
    {
        return dentist_annual;
    }
RUB Health::get_gym_monthly()
    {
        return gym_monthly;
    }
RUB Health::get_vitamins_monthly()
    {
        return vitamins_monthly;
    }
RUB Health::get_emergency_medical()
    {
        return emergency_medical;
    }
RUB Health::get_optician_annual()
    {
        return optician_annual;
    }
RUB Health::get_psychologist_monthly()
    {
        return psychologist_monthly;
    }

//Phone
RUB Phone::get_monthly_plan()
    {
        return monthly_plan;
    }
RUB Phone::get_replacement_cost()
    {
        return replacement_cost;
    }

//Utilities
RUB Utilities::get_electricity(const USint month)
    {
        if (month == 11 || month == 12 || month == 1 || month == 2 || month == 3)
        {
            return electricity_base + electricity_winter_extra;
        }

        return electricity_base;
    }
RUB Utilities::get_water_monthly()
    {
        return water_monthly;
    }
RUB Utilities::get_heating(const USint month)
    {
        if (month >= 10 || month <= 4)
        {
            return heating_monthly;
        }

        return 0;
    }
RUB Utilities::get_internet_monthly()
    {
        return internet_monthly;
    }
RUB Utilities::get_tv_subscription()
    {
        return tv_subscription;
    }
RUB Utilities::get_total_monthly(const USint month)
    {
        return get_electricity(month) + get_water_monthly()
             + get_heating(month) + get_internet_monthly()
             + get_tv_subscription();
    }

//Entertainment
RUB Entertainment::get_streaming_monthly()
    {
        return streaming_monthly;
    }
RUB Entertainment::get_cinema_monthly()
    {
        return cinema_monthly;
    }
RUB Entertainment::get_restaurant_monthly()
    {
        return restaurant_monthly;
    }
RUB Entertainment::get_bar_monthly()
    {
        return bar_monthly;
    }
RUB Entertainment::get_concert_quarterly()
    {
        return concert_quarterly;
    }
RUB Entertainment::get_hobbies_monthly()
    {
        return hobbies_monthly;
    }
RUB Entertainment::get_games_monthly()
    {
        return games_monthly;
    }
RUB Entertainment::get_sports_events_annual()
    {
        return sports_events_annual;
    }
RUB Entertainment::get_total_monthly()
    {
        return streaming_monthly + cinema_monthly + restaurant_monthly
             + bar_monthly + hobbies_monthly + games_monthly;
    }

//Clothing
RUB Clothing::get_summer_wardrobe()
    {
        return summer_wardrobe;
    }
RUB Clothing::get_winter_wardrobe()
    {
        return winter_wardrobe;
    }
RUB Clothing::get_shoes_spring()
    {
        return shoes_spring;
    }
RUB Clothing::get_shoes_autumn()
    {
        return shoes_autumn;
    }
RUB Clothing::get_accessories_annual()
    {
        return accessories_annual;
    }
RUB Clothing::get_sportswear_annual()
    {
        return sportswear_annual;
    }
RUB Clothing::get_formal_wear_annual()
    {
        return formal_wear_annual;
    }

//PersonalCare
RUB PersonalCare::get_haircut_monthly()
    {
        return haircut_monthly;
    }
RUB PersonalCare::get_cosmetics_monthly()
    {
        return cosmetics_monthly;
    }
RUB PersonalCare::get_pharmacy_monthly()
    {
        return pharmacy_monthly;
    }
RUB PersonalCare::get_massage_monthly()
    {
        return massage_monthly;
    }
RUB PersonalCare::get_manicure_monthly()
    {
        return manicure_monthly;
    }
RUB PersonalCare::get_perfume_biannual()
    {
        return perfume_biannual;
    }
RUB PersonalCare::get_spa_quarterly()
    {
        return spa_quarterly;
    }
RUB PersonalCare::get_total_monthly()
    {
        return haircut_monthly + cosmetics_monthly + pharmacy_monthly
             + massage_monthly + manicure_monthly;
    }

//Gifts
RUB Gifts::get_birthday_own()
    {
        return birthday_own;
    }
RUB Gifts::get_birthday_others_annual()
    {
        return birthday_others_annual;
    }
RUB Gifts::get_new_year_gifts()
    {
        return new_year_gifts;
    }
RUB Gifts::get_valentines_day()
    {
        return valentines_day;
    }
RUB Gifts::get_mothers_day()
    {
        return mothers_day;
    }
RUB Gifts::get_fathers_day()
    {
        return fathers_day;
    }
RUB Gifts::get_colleagues_gifts_annual()
    {
        return colleagues_gifts_annual;
    }

//Transport
RUB Transport::get_metro_monthly()
    {
        return metro_monthly;
    }
RUB Transport::get_taxi_monthly()
    {
        return taxi_monthly;
    }
RUB Transport::get_bus_monthly()
    {
        return bus_monthly;
    }
RUB Transport::get_toll_roads_monthly()
    {
        return toll_roads_monthly;
    }
RUB Transport::get_total_monthly()
    {
        return metro_monthly + taxi_monthly + bus_monthly + toll_roads_monthly;
    }

//Taxes
RUB Taxes::calculate_monthly_income_tax(const RUB monthly_income)
    {
        return (RUB)(monthly_income * (income_tax_rate / 100.f));
    }
RUB Taxes::get_property_tax_annual()
    {
        return property_tax_annual;
    }
RUB Taxes::get_car_tax_annual()
    {
        return car_tax_annual;
    }
RUB Taxes::get_tax_deduction_return()
    {
        return tax_deduction_return;
    }

//Electronics
RUB Electronics::get_laptop_replacement()
    {
        return laptop_replacement;
    }
RUB Electronics::get_headphones_biannual()
    {
        return headphones_biannual;
    }
RUB Electronics::get_smart_watch_biannual()
    {
        return smart_watch_biannual;
    }
RUB Electronics::get_accessories_monthly()
    {
        return accessories_monthly;
    }
RUB Electronics::get_repairs_annual()
    {
        return repairs_annual;
    }

//Subscriptions
RUB Subscriptions::get_cloud_storage()
    {
        return cloud_storage;
    }
RUB Subscriptions::get_antivirus()
    {
        return antivirus;
    }
RUB Subscriptions::get_office_suite()
    {
        return office_suite;
    }
RUB Subscriptions::get_cloud_backup()
    {
        return cloud_backup;
    }
RUB Subscriptions::get_vpn()
    {
        return vpn;
    }
RUB Subscriptions::get_professional_tools()
    {
        return professional_tools;
    }
RUB Subscriptions::get_password_manager()
    {
        return password_manager;
    }
RUB Subscriptions::get_news_subscription()
    {
        return news_subscription;
    }
RUB Subscriptions::get_total_monthly()
    {
        return cloud_storage + antivirus + office_suite + cloud_backup
             + vpn + professional_tools + password_manager + news_subscription;
    }

//Person
const list<RUB*> Person::get_prices_pointers()
    {
        RUB* food_pointer              = &food;
        RUB* cat_pointer               = &cat;
        RUB* cat_vet_pointer           = &cat_vet;
        RUB* trip_pointer              = &trip;

        RUB* rent_pointer              = &home.rent;
        RUB* rental_income_pointer     = &home.rental_income;
        RUB* home_insurance_pointer    = &home.home_insurance;
        RUB* repairs_monthly_pointer   = &home.repairs_monthly;
        RUB* repairs_annual_pointer    = &home.repairs_annual;
        RUB* cleaning_pointer          = &home.cleaning_supplies;
        RUB* furniture_pointer         = &home.furniture_annual;

        RUB* gas_pointer               = &car.gas;
        RUB* tires_price_pointer       = &car.tires_price;
        RUB* oil_change_pointer        = &car.oil_change;
        RUB* car_wash_pointer          = &car.car_wash;
        RUB* parking_pointer           = &car.parking_monthly;
        RUB* osago_pointer             = &car.insurance_osago;
        RUB* kasko_pointer             = &car.insurance_kasko;
        RUB* car_maint_pointer         = &car.maintenance_annual;
        RUB* car_fine_pointer          = &car.fine_risk;

        RUB* deposit_pointer           = &vtb.monthly_deposit;

        RUB* medicine_pointer          = &health.medicine_monthly;
        RUB* doctor_pointer            = &health.doctor_visit;
        RUB* dentist_pointer           = &health.dentist_annual;
        RUB* gym_pointer               = &health.gym_monthly;
        RUB* vitamins_pointer          = &health.vitamins_monthly;
        RUB* emergency_medical_pointer = &health.emergency_medical;
        RUB* optician_pointer          = &health.optician_annual;
        RUB* psychologist_pointer      = &health.psychologist_monthly;

        RUB* phone_plan_pointer        = &phone.monthly_plan;
        RUB* phone_replace_pointer     = &phone.replacement_cost;

        RUB* electricity_pointer       = &utilities.electricity_base;
        RUB* elec_winter_pointer       = &utilities.electricity_winter_extra;
        RUB* water_pointer             = &utilities.water_monthly;
        RUB* heating_pointer           = &utilities.heating_monthly;
        RUB* internet_pointer          = &utilities.internet_monthly;
        RUB* tv_pointer                = &utilities.tv_subscription;

        RUB* streaming_pointer         = &entertainment.streaming_monthly;
        RUB* cinema_pointer            = &entertainment.cinema_monthly;
        RUB* restaurant_pointer        = &entertainment.restaurant_monthly;
        RUB* bar_pointer               = &entertainment.bar_monthly;
        RUB* concert_pointer           = &entertainment.concert_quarterly;
        RUB* hobbies_pointer           = &entertainment.hobbies_monthly;
        RUB* games_pointer             = &entertainment.games_monthly;
        RUB* sports_events_pointer     = &entertainment.sports_events_annual;

        RUB* summer_clothes_pointer    = &clothing.summer_wardrobe;
        RUB* winter_clothes_pointer    = &clothing.winter_wardrobe;
        RUB* shoes_spring_pointer      = &clothing.shoes_spring;
        RUB* shoes_autumn_pointer      = &clothing.shoes_autumn;
        RUB* accessories_pointer       = &clothing.accessories_annual;
        RUB* sportswear_pointer        = &clothing.sportswear_annual;
        RUB* formal_wear_pointer       = &clothing.formal_wear_annual;

        RUB* haircut_pointer           = &personal_care.haircut_monthly;
        RUB* cosmetics_pointer         = &personal_care.cosmetics_monthly;
        RUB* pharmacy_pointer          = &personal_care.pharmacy_monthly;
        RUB* massage_pointer           = &personal_care.massage_monthly;
        RUB* manicure_pointer          = &personal_care.manicure_monthly;
        RUB* perfume_pointer           = &personal_care.perfume_biannual;
        RUB* spa_pointer               = &personal_care.spa_quarterly;

        RUB* bday_own_pointer          = &gifts.birthday_own;
        RUB* bday_others_pointer       = &gifts.birthday_others_annual;
        RUB* new_year_gifts_pointer    = &gifts.new_year_gifts;
        RUB* valentines_pointer        = &gifts.valentines_day;
        RUB* mothers_pointer           = &gifts.mothers_day;
        RUB* fathers_pointer           = &gifts.fathers_day;
        RUB* colleagues_pointer        = &gifts.colleagues_gifts_annual;

        RUB* metro_pointer             = &transport.metro_monthly;
        RUB* taxi_pointer              = &transport.taxi_monthly;
        RUB* bus_pointer               = &transport.bus_monthly;
        RUB* toll_pointer              = &transport.toll_roads_monthly;

        RUB* elec_accessories_pointer  = &electronics.accessories_monthly;
        RUB* elec_repairs_pointer      = &electronics.repairs_annual;
        RUB* laptop_pointer            = &electronics.laptop_replacement;
        RUB* headphones_pointer        = &electronics.headphones_biannual;
        RUB* smart_watch_pointer       = &electronics.smart_watch_biannual;

        RUB* cloud_storage_pointer     = &subscriptions.cloud_storage;
        RUB* antivirus_pointer         = &subscriptions.antivirus;
        RUB* office_suite_pointer      = &subscriptions.office_suite;
        RUB* cloud_backup_pointer      = &subscriptions.cloud_backup;
        RUB* vpn_pointer               = &subscriptions.vpn;
        RUB* pro_tools_pointer         = &subscriptions.professional_tools;
        RUB* pass_manager_pointer      = &subscriptions.password_manager;
        RUB* news_pointer              = &subscriptions.news_subscription;

        return {food_pointer, cat_pointer, cat_vet_pointer, trip_pointer,
                rent_pointer, rental_income_pointer,
                home_insurance_pointer, repairs_monthly_pointer, repairs_annual_pointer,
                cleaning_pointer, furniture_pointer,
                gas_pointer, tires_price_pointer, oil_change_pointer,
                car_wash_pointer, parking_pointer,
                osago_pointer, kasko_pointer, car_maint_pointer, car_fine_pointer,
                deposit_pointer,
                medicine_pointer, doctor_pointer, dentist_pointer,
                gym_pointer, vitamins_pointer, emergency_medical_pointer,
                optician_pointer, psychologist_pointer,
                phone_plan_pointer, phone_replace_pointer,
                electricity_pointer, elec_winter_pointer, water_pointer,
                heating_pointer, internet_pointer, tv_pointer,
                streaming_pointer, cinema_pointer, restaurant_pointer,
                bar_pointer, concert_pointer, hobbies_pointer,
                games_pointer, sports_events_pointer,
                summer_clothes_pointer, winter_clothes_pointer,
                shoes_spring_pointer, shoes_autumn_pointer,
                accessories_pointer, sportswear_pointer, formal_wear_pointer,
                haircut_pointer, cosmetics_pointer, pharmacy_pointer,
                massage_pointer, manicure_pointer, perfume_pointer, spa_pointer,
                bday_own_pointer, bday_others_pointer, new_year_gifts_pointer,
                valentines_pointer, mothers_pointer, fathers_pointer, colleagues_pointer,
                metro_pointer, taxi_pointer, bus_pointer, toll_pointer,
                elec_accessories_pointer, elec_repairs_pointer,
                laptop_pointer, headphones_pointer, smart_watch_pointer,
                cloud_storage_pointer, antivirus_pointer, office_suite_pointer,
                cloud_backup_pointer, vpn_pointer, pro_tools_pointer,
                pass_manager_pointer, news_pointer};
    }
void Person::rest()
    {
        if (mind.stress_value >= day_off_stress_decrease){
            mind.stress_value -= day_off_stress_decrease;
        }
        else {
            mind.stress_value = 0;
        }
    }


// ============================================================
// INITIALIZATION
// ============================================================

void alice_init()
{
    alice.mind.stress_value = 0;
    alice.mind.update_stress_level();

    alice.country.economy.inflation = 12.5;

    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 1'000;
    alice.vtb.deposit_balance = 0;
    alice.vtb.deposit_rate = 16.0;
    alice.vtb.monthly_deposit = 10'000;
    alice.vtb.bank_fee = 200;

    alice.job.salary = 180'000;
    alice.job.bonus = 0;
    alice.job.current_workload = 0;
    alice.job.daily_workload = 100;
    alice.job.workday_stress = 10;
    alice.job.init_overtime();

    alice.food = 3'000;
    alice.cat = 2'000;
    alice.cat_vet = 5'000;
    alice.trip = 60'000;

    alice.home.rent = 30'000;
    alice.home.rental_income = 25'000;
    alice.home.home_insurance = 8'000;
    alice.home.repairs_monthly = 2'000;
    alice.home.repairs_annual = 20'000;
    alice.home.cleaning_supplies = 1'500;
    alice.home.furniture_annual = 15'000;

    alice.car.value = 2'400'000;
    alice.car.gas = 15'000;
    alice.car.tires_price = 3'000;
    alice.car.oil_change = 5'000;
    alice.car.car_wash = 500;
    alice.car.parking_monthly = 5'000;
    alice.car.insurance_osago = 8'000;
    alice.car.insurance_kasko = 35'000;
    alice.car.maintenance_annual = 15'000;
    alice.car.fine_risk = 1'500;

    alice.health.medicine_monthly = 2'000;
    alice.health.doctor_visit = 3'000;
    alice.health.dentist_annual = 15'000;
    alice.health.gym_monthly = 3'000;
    alice.health.vitamins_monthly = 1'500;
    alice.health.emergency_medical = 10'000;
    alice.health.optician_annual = 8'000;
    alice.health.psychologist_monthly = 5'000;

    alice.phone.monthly_plan = 700;
    alice.phone.replacement_cost = 80'000;
    alice.phone.replacement_cycle_years = 2;

    alice.utilities.electricity_base = 2'000;
    alice.utilities.electricity_winter_extra = 800;
    alice.utilities.water_monthly = 800;
    alice.utilities.heating_monthly = 3'000;
    alice.utilities.internet_monthly = 700;
    alice.utilities.tv_subscription = 300;

    alice.entertainment.streaming_monthly = 800;
    alice.entertainment.cinema_monthly = 1'500;
    alice.entertainment.restaurant_monthly = 5'000;
    alice.entertainment.bar_monthly = 2'000;
    alice.entertainment.concert_quarterly = 4'000;
    alice.entertainment.hobbies_monthly = 3'000;
    alice.entertainment.games_monthly = 500;
    alice.entertainment.sports_events_annual = 5'000;

    alice.clothing.summer_wardrobe = 15'000;
    alice.clothing.winter_wardrobe = 20'000;
    alice.clothing.shoes_spring = 8'000;
    alice.clothing.shoes_autumn = 8'000;
    alice.clothing.accessories_annual = 10'000;
    alice.clothing.sportswear_annual = 6'000;
    alice.clothing.formal_wear_annual = 15'000;

    alice.personal_care.haircut_monthly = 1'500;
    alice.personal_care.cosmetics_monthly = 3'000;
    alice.personal_care.pharmacy_monthly = 1'000;
    alice.personal_care.massage_monthly = 3'000;
    alice.personal_care.manicure_monthly = 2'000;
    alice.personal_care.perfume_biannual = 5'000;
    alice.personal_care.spa_quarterly = 4'000;

    alice.gifts.birthday_own = 15'000;
    alice.gifts.birthday_others_annual = 20'000;
    alice.gifts.new_year_gifts = 10'000;
    alice.gifts.valentines_day = 3'000;
    alice.gifts.mothers_day = 5'000;
    alice.gifts.fathers_day = 3'000;
    alice.gifts.colleagues_gifts_annual = 8'000;

    alice.transport.metro_monthly = 2'500;
    alice.transport.taxi_monthly = 3'000;
    alice.transport.bus_monthly = 0;
    alice.transport.toll_roads_monthly = 1'000;

    alice.taxes.income_tax_rate = 13.0;
    alice.taxes.property_tax_annual = 8'000;
    alice.taxes.car_tax_annual = 5'000;
    alice.taxes.tax_deduction_return = 0;

    alice.electronics.laptop_replacement = 120'000;
    alice.electronics.laptop_cycle_years = 3;
    alice.electronics.headphones_biannual = 5'000;
    alice.electronics.smart_watch_biannual = 15'000;
    alice.electronics.accessories_monthly = 500;
    alice.electronics.repairs_annual = 5'000;

    alice.subscriptions.cloud_storage = 300;
    alice.subscriptions.antivirus = 400;
    alice.subscriptions.office_suite = 500;
    alice.subscriptions.cloud_backup = 250;
    alice.subscriptions.vpn = 350;
    alice.subscriptions.professional_tools = 1'500;
    alice.subscriptions.password_manager = 150;
    alice.subscriptions.news_subscription = 200;

    alice.day_off_stress_decrease = 25;
}


// ============================================================
// SIMULATION FUNCTIONS
// ============================================================

void alice_home(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.home.get_rent();

        alice.vtb.account_rub -= alice.home.get_repairs_monthly();

        alice.vtb.account_rub -= alice.home.get_cleaning_supplies();

        if (month == 1)
        {
            alice.vtb.account_rub -= alice.home.get_home_insurance();  // annual insurance renewal
        }

        if (month == 3)
        {
            alice.vtb.account_rub -= alice.home.get_furniture_annual();  // spring furniture shopping
        }

        if (month == 6)
        {
            alice.vtb.account_rub -= alice.home.get_repairs_annual();  // big summer renovation
        }
    }
}


void alice_food(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        if (month == 12) alice.vtb.account_rub -= 2000;  // christmas party

        alice.vtb.account_rub -= alice.food;
    }
}


void alice_job(const int day, const int month, const int year)
{
    if (day == 1)
    {
        if (month == 3)
        {
            alice.job.promote();
            alice.job.init_overtime();
        }

        if (month == 2 && year == 2026)
        {
            alice.vtb.account_rub += alice.job.get_bonus();
        }
    }

    alice.job.increase_current_workload_by_days(1);
    alice.job.do_overtime(alice.job.what_overtime_needed(), alice.mind.stress_value, alice.vtb.account_rub);
    alice.job.do_work(alice.mind.stress_value, alice.vtb.account_rub);
}


void alice_car(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.car.gas;

        alice.vtb.account_rub -= alice.car.get_car_wash();

        alice.vtb.account_rub -= alice.car.get_parking_monthly();

        alice.vtb.account_rub -= alice.car.get_fine_risk();

        if (month == 4 || month == 10)
        {
            alice.vtb.account_rub -= alice.car.get_tires_price();
        }

        if (month == 3 || month == 9)
        {
            alice.vtb.account_rub -= alice.car.get_oil_change();  // oil change every 6 months
        }

        if (month == 5)
        {
            alice.vtb.account_rub -= alice.car.get_insurance_osago();  // annual OSAGO renewal
            alice.vtb.account_rub -= alice.car.get_insurance_kasko();  // annual KASKO renewal
        }

        if (month == 11)
        {
            alice.vtb.account_rub -= alice.car.get_maintenance_annual();  // annual service
        }
    }
}


void alice_cat(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        if (month == 3 || month == 9) alice.vtb.account_rub -= alice.cat_vet;  // vet checkup twice a year

        alice.vtb.account_rub -= alice.cat;  // monthly cat food and care
    }
}


void alice_trip(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1 && month == 7)
    {
        alice.vtb.account_rub -= alice.trip;  // annual summer vacation
    }
}


void alice_rent(const int day)
{
    if (day == 1)
    {
        alice.vtb.account_rub += alice.home.get_rental_income();  // rental income from owned property
    }
}


void alice_mortgage(const int day)
{
    if (day == 1)
    {
        alice.vtb.account_rub -= 45'000;  // monthly mortgage payment
    }
}


void alice_health(const int day, const int month, const int year)
{
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.health.get_medicine_monthly();

        alice.vtb.account_rub -= alice.health.get_gym_monthly();

        alice.vtb.account_rub -= alice.health.get_vitamins_monthly();

        alice.vtb.account_rub -= alice.health.get_psychologist_monthly();

        if (month == 3 || month == 6 || month == 9 || month == 12)
        {
            alice.vtb.account_rub -= alice.health.get_doctor_visit();  // quarterly checkup
        }

        if (month == 4)
        {
            alice.vtb.account_rub -= alice.health.get_dentist_annual();  // annual dentist
        }

        if (month == 7)
        {
            alice.vtb.account_rub -= alice.health.get_optician_annual();  // annual optician
        }

        if (month == 8 && year == 2027)
        {
            alice.vtb.account_rub -= alice.health.get_emergency_medical();  // one-off emergency
        }
    }
}


void alice_phone(const int day, const int month, const int year)
{
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.phone.get_monthly_plan();

        if (month == 9 && year == 2026)
        {
            alice.vtb.account_rub -= alice.phone.get_replacement_cost();  // new phone every 2 years
        }

        if (month == 9 && year == 2028)
        {
            alice.vtb.account_rub -= alice.phone.get_replacement_cost();  // next replacement
        }
    }
}


void alice_utilities(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.utilities.get_total_monthly(month);
    }
}


void alice_entertainment(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.entertainment.get_total_monthly();

        if (month == 3 || month == 6 || month == 9 || month == 12)
        {
            alice.vtb.account_rub -= alice.entertainment.get_concert_quarterly();
        }

        if (month == 8)
        {
            alice.vtb.account_rub -= alice.entertainment.get_sports_events_annual();
        }
    }
}


void alice_clothing(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        if (month == 4)
        {
            alice.vtb.account_rub -= alice.clothing.get_summer_wardrobe();
            alice.vtb.account_rub -= alice.clothing.get_shoes_spring();
        }

        if (month == 10)
        {
            alice.vtb.account_rub -= alice.clothing.get_winter_wardrobe();
            alice.vtb.account_rub -= alice.clothing.get_shoes_autumn();
        }

        if (month == 1)
        {
            alice.vtb.account_rub -= alice.clothing.get_accessories_annual();
            alice.vtb.account_rub -= alice.clothing.get_formal_wear_annual();
        }

        if (month == 5)
        {
            alice.vtb.account_rub -= alice.clothing.get_sportswear_annual();
        }
    }
}


void alice_personal_care(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.personal_care.get_total_monthly();

        if (month == 4 || month == 10)
        {
            alice.vtb.account_rub -= alice.personal_care.get_perfume_biannual();
        }

        if (month == 3 || month == 6 || month == 9 || month == 12)
        {
            alice.vtb.account_rub -= alice.personal_care.get_spa_quarterly();
        }
    }
}


void alice_gifts(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        if (month == 2)
        {
            alice.vtb.account_rub -= alice.gifts.get_valentines_day();
        }

        if (month == 3)
        {
            alice.vtb.account_rub -= alice.gifts.get_mothers_day();  // March 8 in Russia
        }

        if (month == 5)
        {
            alice.vtb.account_rub -= alice.gifts.get_birthday_own();  // Alice's birthday
        }

        if (month == 6)
        {
            alice.vtb.account_rub -= alice.gifts.get_fathers_day();
        }

        if (month == 10)
        {
            alice.vtb.account_rub -= alice.gifts.get_birthday_others_annual();  // friends birthdays
        }

        if (month == 11)
        {
            alice.vtb.account_rub -= alice.gifts.get_colleagues_gifts_annual();
        }

        if (month == 12)
        {
            alice.vtb.account_rub -= alice.gifts.get_new_year_gifts();  // New Year presents
        }
    }
}


void alice_transport(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.transport.get_total_monthly();
    }
}


void alice_taxes(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        RUB monthly_income = alice.job.salary;
        alice.vtb.account_rub -= alice.taxes.calculate_monthly_income_tax(monthly_income);

        if (month == 12)
        {
            alice.vtb.account_rub -= alice.taxes.get_property_tax_annual();
            alice.vtb.account_rub -= alice.taxes.get_car_tax_annual();
        }

        if (month == 4)
        {
            alice.vtb.account_rub += alice.taxes.get_tax_deduction_return();  // annual tax refund
        }
    }
}


void alice_electronics(const int day, const int month, const int year)
{
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.electronics.get_accessories_monthly();

        if (month == 6 && year == 2027)
        {
            alice.vtb.account_rub -= alice.electronics.get_laptop_replacement();
        }

        if (month == 3 && (year == 2026 || year == 2028))
        {
            alice.vtb.account_rub -= alice.electronics.get_headphones_biannual();
        }

        if (month == 9 && (year == 2026 || year == 2028))
        {
            alice.vtb.account_rub -= alice.electronics.get_smart_watch_biannual();
        }

        if (month == 1)
        {
            alice.vtb.account_rub -= alice.electronics.get_repairs_annual();
        }
    }
}


void alice_subscriptions(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.subscriptions.get_total_monthly();

        if (month == 1)
        {
            alice.vtb.account_rub -= alice.subscriptions.get_antivirus();  // annual antivirus renewal
        }

        if (month == 6)
        {
            alice.vtb.account_rub -= alice.subscriptions.get_office_suite();  // annual office renewal
        }
    }
}


void alice_bank(const int day, const int month, const int year)
{
    (void)year;
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.vtb.get_bank_fee();

        alice.vtb.add_monthly_deposit();

        alice.vtb.accrue_deposit_interest();

        if (month == 12)
        {
            alice.vtb.account_rub += (RUB)(alice.vtb.account_usd * alice.vtb.rate_usd_rub * 0.01f);  // USD appreciation bonus
        }
    }
}


// ============================================================
// OUTPUT
// ============================================================

void print_yearly_summary(const int year)
{
    cout << endl;
    cout << "--- YEAR " << year << " SUMMARY ---" << endl;
    printf("  Cash balance          = %lld RUB\n",  alice.vtb.account_rub);
    printf("  Deposit balance       = %lld RUB\n",  alice.vtb.get_deposit_balance());
    printf("  Current salary        = %lld RUB/mo\n", alice.job.salary);
    printf("  Rental income         = %lld RUB/mo\n", alice.home.rental_income);
    printf("  Rent paid             = %lld RUB/mo\n", alice.home.rent);
    printf("  Food cost             = %lld RUB/mo\n", alice.food);
    printf("  Stress level          = %s (%d)\n",
           alice.mind.stress_level.c_str(), alice.mind.stress_value);
    printf("  Inflation this year   = %.1f%%\n",
           alice.country.economy.get_current_inflation());
    cout << endl;
}


void print_results()
{
    cout << endl;
    cout << "======================================" << endl;
    cout << "  SIMULATION RESULTS (Feb 2029)      " << endl;
    cout << "======================================" << endl;

    cout << endl;
    cout << "--- JOB ---" << endl;
    printf("  Salary         = %lld RUB\n",  alice.job.salary);
    printf("  Bonus received = %lld RUB\n",  alice.job.bonus);
    printf("  Workload left  = %d units\n",   alice.job.current_workload);

    cout << endl;
    cout << "--- BANK ---" << endl;
    printf("  Cash balance   = %lld RUB\n",  alice.vtb.account_rub);
    printf("  USD account    = %lld USD\n",  alice.vtb.account_usd);
    printf("  Deposit        = %lld RUB\n",  alice.vtb.get_deposit_balance());

    RUB net_worth = 0;
    net_worth += alice.vtb.account_rub;
    net_worth += alice.vtb.account_usd * (USD)alice.vtb.rate_usd_rub;
    net_worth += alice.vtb.get_deposit_balance();
    net_worth += alice.car.value;
    printf("  Net worth      = %lld RUB\n",  net_worth);

    cout << endl;
    cout << "--- ECONOMY ---" << endl;
    cout << "  Inflation      = " << alice.country.economy.get_current_inflation() << "%" << endl;

    cout << endl;
    cout << "--- CURRENT MONTHLY PRICES (inflation-adjusted) ---" << endl;
    printf("  Food           = %lld RUB\n",  alice.food);
    printf("  Rent           = %lld RUB\n",  alice.home.rent);
    printf("  Gas            = %lld RUB\n",  alice.car.gas);
    printf("  Cat (monthly)  = %lld RUB\n",  alice.cat);
    printf("  Cat (vet)      = %lld RUB\n",  alice.cat_vet);
    printf("  Trip (annual)  = %lld RUB\n",  alice.trip);

    cout << endl;
    cout << "--- HEALTH (monthly base prices) ---" << endl;
    printf("  Medicine       = %lld RUB\n",  alice.health.medicine_monthly);
    printf("  Gym            = %lld RUB\n",  alice.health.gym_monthly);
    printf("  Vitamins       = %lld RUB\n",  alice.health.vitamins_monthly);
    printf("  Psychologist   = %lld RUB\n",  alice.health.psychologist_monthly);
    printf("  Doctor (visit) = %lld RUB\n",  alice.health.doctor_visit);
    printf("  Dentist (ann.) = %lld RUB\n",  alice.health.dentist_annual);
    printf("  Optician (ann.)= %lld RUB\n",  alice.health.optician_annual);

    cout << endl;
    cout << "--- UTILITIES (monthly base prices) ---" << endl;
    printf("  Electricity    = %lld RUB\n",  alice.utilities.electricity_base);
    printf("  Water          = %lld RUB\n",  alice.utilities.water_monthly);
    printf("  Heating        = %lld RUB\n",  alice.utilities.heating_monthly);
    printf("  Internet       = %lld RUB\n",  alice.utilities.internet_monthly);
    printf("  TV             = %lld RUB\n",  alice.utilities.tv_subscription);

    cout << endl;
    cout << "--- ENTERTAINMENT (monthly base prices) ---" << endl;
    printf("  Streaming      = %lld RUB\n",  alice.entertainment.streaming_monthly);
    printf("  Cinema         = %lld RUB\n",  alice.entertainment.cinema_monthly);
    printf("  Restaurants    = %lld RUB\n",  alice.entertainment.restaurant_monthly);
    printf("  Bar            = %lld RUB\n",  alice.entertainment.bar_monthly);
    printf("  Hobbies        = %lld RUB\n",  alice.entertainment.hobbies_monthly);

    cout << endl;
    cout << "--- PERSONAL CARE (monthly base prices) ---" << endl;
    printf("  Haircut        = %lld RUB\n",  alice.personal_care.haircut_monthly);
    printf("  Cosmetics      = %lld RUB\n",  alice.personal_care.cosmetics_monthly);
    printf("  Massage        = %lld RUB\n",  alice.personal_care.massage_monthly);
    printf("  Manicure       = %lld RUB\n",  alice.personal_care.manicure_monthly);

    cout << endl;
    cout << "--- CAR (current prices) ---" << endl;
    printf("  Gas (monthly)  = %lld RUB\n",  alice.car.gas);
    printf("  Tires          = %lld RUB\n",  alice.car.tires_price);
    printf("  Oil change     = %lld RUB\n",  alice.car.oil_change);
    printf("  Car wash       = %lld RUB\n",  alice.car.car_wash);
    printf("  Parking        = %lld RUB\n",  alice.car.parking_monthly);
    printf("  OSAGO (ann.)   = %lld RUB\n",  alice.car.insurance_osago);
    printf("  KASKO (ann.)   = %lld RUB\n",  alice.car.insurance_kasko);
    printf("  Maintenance    = %lld RUB\n",  alice.car.maintenance_annual);
    printf("  Fine risk      = %lld RUB\n",  alice.car.fine_risk);

    cout << endl;
    cout << "--- TRANSPORT (current prices) ---" << endl;
    printf("  Metro          = %lld RUB\n",  alice.transport.metro_monthly);
    printf("  Taxi           = %lld RUB\n",  alice.transport.taxi_monthly);
    printf("  Toll roads     = %lld RUB\n",  alice.transport.toll_roads_monthly);

    cout << endl;
    cout << "--- CLOTHING (current prices) ---" << endl;
    printf("  Summer clothes = %lld RUB\n",  alice.clothing.summer_wardrobe);
    printf("  Winter clothes = %lld RUB\n",  alice.clothing.winter_wardrobe);
    printf("  Shoes spring   = %lld RUB\n",  alice.clothing.shoes_spring);
    printf("  Shoes autumn   = %lld RUB\n",  alice.clothing.shoes_autumn);
    printf("  Accessories    = %lld RUB\n",  alice.clothing.accessories_annual);
    printf("  Sportswear     = %lld RUB\n",  alice.clothing.sportswear_annual);
    printf("  Formal wear    = %lld RUB\n",  alice.clothing.formal_wear_annual);

    cout << endl;

    cout << "--- GIFTS (current prices) ---" << endl;
    printf("  Own birthday   = %lld RUB\n",  alice.gifts.birthday_own);
    printf("  Others b-days  = %lld RUB\n",  alice.gifts.birthday_others_annual);
    printf("  New Year       = %lld RUB\n",  alice.gifts.new_year_gifts);
    printf("  Valentine's    = %lld RUB\n",  alice.gifts.valentines_day);
    printf("  Mother's Day   = %lld RUB\n",  alice.gifts.mothers_day);
    printf("  Father's Day   = %lld RUB\n",  alice.gifts.fathers_day);
    printf("  Colleagues     = %lld RUB\n",  alice.gifts.colleagues_gifts_annual);

    cout << endl;
    cout << "--- SUBSCRIPTIONS (current prices) ---" << endl;
    printf("  Cloud storage  = %lld RUB\n",  alice.subscriptions.cloud_storage);
    printf("  Antivirus      = %lld RUB\n",  alice.subscriptions.antivirus);
    printf("  Office suite   = %lld RUB\n",  alice.subscriptions.office_suite);
    printf("  Cloud backup   = %lld RUB\n",  alice.subscriptions.cloud_backup);
    printf("  VPN            = %lld RUB\n",  alice.subscriptions.vpn);
    printf("  Pro tools      = %lld RUB\n",  alice.subscriptions.professional_tools);
    printf("  Password mgr   = %lld RUB\n",  alice.subscriptions.password_manager);
    printf("  News           = %lld RUB\n",  alice.subscriptions.news_subscription);
    printf("  Total/month    = %lld RUB\n",  alice.subscriptions.get_total_monthly());

    cout << endl;
    cout << "--- ELECTRONICS (current prices) ---" << endl;
    printf("  Laptop (once)  = %lld RUB\n",  alice.electronics.laptop_replacement);
    printf("  Headphones     = %lld RUB\n",  alice.electronics.headphones_biannual);
    printf("  Smart watch    = %lld RUB\n",  alice.electronics.smart_watch_biannual);
    printf("  Accessories    = %lld RUB\n",  alice.electronics.accessories_monthly);
    printf("  Repairs (ann.) = %lld RUB\n",  alice.electronics.repairs_annual);

    cout << endl;
    cout << "--- TAXES ---" << endl;
    printf("  Income tax     = %.1f%%\n",    alice.taxes.income_tax_rate);
    printf("  Property tax   = %lld RUB\n",  alice.taxes.property_tax_annual);
    printf("  Car tax        = %lld RUB\n",  alice.taxes.car_tax_annual);

    cout << endl;
    cout << "--- HOME (current prices) ---" << endl;
    printf("  Home insurance = %lld RUB\n",  alice.home.home_insurance);
    printf("  Repairs (mo.)  = %lld RUB\n",  alice.home.repairs_monthly);
    printf("  Repairs (ann.) = %lld RUB\n",  alice.home.repairs_annual);
    printf("  Cleaning       = %lld RUB\n",  alice.home.cleaning_supplies);
    printf("  Furniture      = %lld RUB\n",  alice.home.furniture_annual);
    printf("  Rental income  = %lld RUB\n",  alice.home.rental_income);

    cout << endl;
    cout << "--- STRESS ---" << endl;
    alice.mind.update_stress_level();
    cout << "  Stress value   = " << alice.mind.stress_value << endl;
    cout << "  Stress level   = " << alice.mind.stress_level << endl;

    cout << endl;
    cout << "======================================" << endl;
}


// ============================================================
// SIMULATION LOOP
// ============================================================

void simulation()
{
    calendar.day = 1;
    calendar.weekday = 1;
    calendar.month = 2;
    calendar.year = 2026;
    calendar.update_year_days();

    while ( !(calendar.year == 2029 && calendar.month == 2) )
    {
        alice_food(calendar.day, calendar.month, calendar.year);
        alice_home(calendar.day, calendar.month, calendar.year);
        alice_car(calendar.day, calendar.month, calendar.year);

        alice.country.economy.recalculate_inflation(calendar.year);

        if (calendar.month == 1 && calendar.day == 1){
            alice.country.economy.recalculate_prices(alice.get_prices_pointers());
        }

        alice_cat(calendar.day, calendar.month, calendar.year);
        alice_trip(calendar.day, calendar.month, calendar.year);
        alice_rent(calendar.day);
        alice_mortgage(calendar.day);

        alice_health(calendar.day, calendar.month, calendar.year);
        alice_phone(calendar.day, calendar.month, calendar.year);
        alice_utilities(calendar.day, calendar.month, calendar.year);
        alice_entertainment(calendar.day, calendar.month, calendar.year);
        alice_clothing(calendar.day, calendar.month, calendar.year);
        alice_personal_care(calendar.day, calendar.month, calendar.year);
        alice_gifts(calendar.day, calendar.month, calendar.year);
        alice_transport(calendar.day, calendar.month, calendar.year);
        alice_taxes(calendar.day, calendar.month, calendar.year);
        alice_electronics(calendar.day, calendar.month, calendar.year);
        alice_subscriptions(calendar.day, calendar.month, calendar.year);
        alice_bank(calendar.day, calendar.month, calendar.year);

        if (calendar.weekday < 6){
            alice_job(calendar.day, calendar.month, calendar.year);
        }

        else {
            alice.rest();
        }

        alice.mind.update_stress_level();


        if (calendar.day == 31 && calendar.month == 12)
        {
            print_yearly_summary(calendar.year);
        }

        calendar.advance();
    }
}


int main()
{
    alice_init();
    simulation();
    print_results();
}
