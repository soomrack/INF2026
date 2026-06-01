#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using RUB = long long int;

struct Taxes {
    RUB income_tax;
    RUB property_tax;
    RUB capital_gains_tax;
    RUB total_taxes_paid;
    RUB tax_refund;
    int has_deduction;
    double tax_rate;
};

struct Mortgage {
    int has_mortgage;
    RUB total_loan;
    RUB monthly_payment;
    RUB remaining_balance;
    int months_paid;
    int total_months;
    double interest_rate;
};

struct Charity {
    RUB donations;
    int animals_shelter;
    int orphans_fund;
    int environment;
    double tax_deduction;
};

struct Achievements {
    int millionaire;
    int multimillionaire;
    int billionaire;
    
    int homeowner;
    int landlord;
    int second_home;
    
    int beginner_investor;
    int serious_investor;
    int pro_investor;
    int balanced_portfolio;
    
    int car_owner;
    int luxury_car;
    
    int happy_person;
    int very_happy;
    int survived_crisis;
    
    int taxpayer;
    int big_taxpayer;
    int philanthropist;
    int big_philanthropist;
    
    int educated;
    int salary_jump;
    
    int lucky;
    int very_lucky;
    int unlucky;
    
    int ten_years_survivor;

    int first_salary;
    int saver;
    int big_saver;
    int work_out;
    int movie_lover;
    int traveler;
    int hobbyist;
    int lucky_day;
    int gift_receiver;
    int fine_payer;
    int survivor;
};

struct Bank {
    double deposit_rate;
    RUB commission;
    double inflation_rate = 0.5;
};

struct InsuranceCompany
{
    RUB monthly_premium;
    int has_insurance;
    RUB coverage_amount;
    int years_paid;
    int last_payout_month;
    RUB total_paid;
};

struct RealEstate {
    RUB apartment_value;
    RUB apartment_tax;
    RUB rent_income;
    int apartment_condition;
    int apartment_rooms;
    int apartment_floor;
    int apartment_building_age;
    
    RUB cottage_value;
    RUB cottage_tax;
    RUB cottage_maintenance;
    int has_cottage;
    int cottage_condition;
    int cottage_area;
    
    RUB commercial_value;
    RUB commercial_income;
    int has_commercial;
    
    RUB second_apartment_value;
    RUB second_apartment_rent;
    int has_second_apartment;
    
    RUB repair_fund;
    int last_repair_year;
    int renovation_quality;
    
    RUB utilities_electricity;
    RUB utilities_water;
    RUB utilities_gas;
    RUB utilities_internet;
    
    RUB insurance_premium;
    int has_insurance;
    RUB insurance_payout;
};

struct Investments {
    RUB stocks;
    RUB bonds;
    double stocks_growth_rate;
};

struct Health {
    int happiness;
    RUB gym_membership;
    RUB medicine;
};

struct Entertainment {
    RUB cinema;
    RUB restaurants;
    RUB travel_budget;
    RUB hobbies;
};

struct Car {
    RUB value;
    RUB gas;
    RUB maintenance;
    RUB fine;
    int age_months;
};

struct Food {
    RUB home_cooking;
    RUB cafe;
    RUB delivery;
    RUB groceries;
    RUB work_lunch;
    int diet_type;
    int cooking_skill;
};

struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    RUB education;
    RUB random_income;
    RUB random_expense;
    struct Achievements achievements;
    struct Car car;
    struct Food food_detail;
    struct RealEstate realty;
    struct Investments invest;
    struct Health health;
    struct Entertainment fun;
    struct Mortgage mortgage;
    struct Charity charity;
    struct Taxes taxes;
};

struct Person Alice;

struct Bank sberbank;

struct InsuranceCompany health_insurance;

void alice_charity();
void check_and_award_achievements();
void print_all_achievements();
void alice_calculate_income_tax();
void alice_calculate_property_tax();
void alice_calculate_capital_gains_tax();
void alice_pay_taxes();
void alice_bank_interest();
void alice_insurance();
void alice_update_diet();
void alice_food();
void alice_health();
void alice_investments();
void alice_mortgage_payment();
void alice_real_estate();
void alice_utilities_payment();
void alice_property_insurance();
void alice_buy_cottage();
void alice_buy_commercial();
void alice_buy_second_apartment();
void alice_repair_property();
void alice_entertainment();
void alice_random_events();
void alice_car();
void alice_education();
void alice_salary(const int month, const int year);
void alice_boat(const int month, const int year);
void alice_init();
void print_results();
void alice_tax_report(const int year);
void add_happiness(const int delta);
void simulation();

void alice_charity() {
    if (Alice.capital > 500'000 && Alice.health.happiness > 70) {
        RUB donate = Alice.salary * 0.02;
        Alice.charity.donations += donate;
        Alice.capital -= donate;
        Alice.charity.tax_deduction = Alice.charity.donations * 0.13;
        add_happiness(3);
    }
}

void check_and_award_achievements() {
    static int achievements_shown = 0;
    
    if (Alice.capital > 1'000'000 && !Alice.achievements.millionaire) {
        printf("\nдостижение \"Миллионер\"\n");
        printf("   капитал превысил 1 000 000 RUB\n");
        printf("   награда: +10 к счастью\n");
        Alice.achievements.millionaire = 1;
        add_happiness(10);
    }
    
    if (Alice.capital > 10'000'000 && !Alice.achievements.multimillionaire) {
        printf("\nдостижение \"Мультимиллионер\"\n");
        printf("   капитал превысил 10 000 000 RUB\n");
        printf("   награда: +15 к счастью\n");
        Alice.achievements.multimillionaire = 1;
        add_happiness(15);
    }
    
    if (Alice.capital > 100'000'000 && !Alice.achievements.billionaire) {
        printf("\nдостижение \"Богатейшая женщина города\"\n");
        printf("   капитал превысил 100 000 000 RUB\n");
        printf("   награда: +30 к счастью\n");
        Alice.achievements.billionaire = 1;
        add_happiness(30);
    }
    
    if (!Alice.mortgage.has_mortgage && Alice.realty.apartment_value > 0 && !Alice.achievements.homeowner) {
        printf("\nдостижение \"Полноправный владелец\"\n");
        printf("   ипотека полностью погашена\n");
        printf("   награда: +15 к счастью\n");
        Alice.achievements.homeowner = 1;
        add_happiness(15);
    }
    
    if (Alice.realty.rent_income > 0 && !Alice.achievements.landlord) {
        printf("\nдостижение \"Арендодатель\"\n");
        printf("   квартира сдаётся и приносит доход\n");
        printf("   награда: +5 к счастью\n");
        Alice.achievements.landlord = 1;
        add_happiness(5);
    }

    if (Alice.realty.has_cottage && !Alice.achievements.second_home) {
        printf("\nдостижение \"Вторая недвижимость\"\n");
        printf("   Алиса купила себе коттедж\n");
        printf("   награда: +10 к счастью\n");
        Alice.achievements.second_home = 1;
        add_happiness(10);
    }
    
    RUB total_investments = Alice.invest.stocks + Alice.invest.bonds;
    
    if (total_investments > 100'000 && !Alice.achievements.beginner_investor) {
        printf("\nдостижение \"Начинающий инвестор\"\n");
        printf("   инвестиционный портфель превысил 100 000 RUB\n");
        Alice.achievements.beginner_investor = 1;
        add_happiness(5);
    }
    
    if (total_investments > 500'000 && !Alice.achievements.serious_investor) {
        printf("\nдостижение \"Серьёзный инвестор\"\n");
        printf("   инвестиционный портфель превысил 500 000 RUB\n");
        printf("   награда: +10 к счастью\n");
        Alice.achievements.serious_investor = 1;
        add_happiness(10);
    }
    
    if (total_investments > 1'000'000 && !Alice.achievements.pro_investor) {
        printf("\nдостижение \"Профессиональный инвестор\"\n");
        printf("   инвестиционный портфель превысил 1 000 000 RUB\n");
        printf("   награда: +20 к счастью\n");
        Alice.achievements.pro_investor = 1;
        add_happiness(20);
    }
    
    if (Alice.invest.stocks > 200'000 && Alice.invest.bonds > 200'000 && !Alice.achievements.balanced_portfolio) {
        printf("\nдостижение \"Сбалансированный портфель\"\n");
        printf("   акции и облигации превысили 200 000 RUB\n");
        printf("   награда: +8 к счастью\n");
        Alice.achievements.balanced_portfolio = 1;
        add_happiness(8);
    }
    
    if (Alice.car.value > 0 && !Alice.achievements.car_owner) {
        printf("\nдостижение \"Автовладелец\"\n");
        printf("   Алиса купила автомобиль\n");
        Alice.achievements.car_owner = 1;
        add_happiness(3);
    }
    
    if (Alice.car.value > 5'000'000 && !Alice.achievements.luxury_car) {
        printf("\nдостижение \"Роскошный автомобиль\"\n");
        printf("   стоимость машины превысила 5 000 000 RUB\n");
        printf("   награда: +10 к счастью\n");
        Alice.achievements.luxury_car = 1;
        add_happiness(10);
    }
    
    if (Alice.health.happiness >= 90 && !Alice.achievements.happy_person) {
        printf("\nдостижение \"Счастливая жизнь\"\n");
        printf("   уровень счастья превысил 90\n");
        printf("   награда: +5 к счастью\n");
        Alice.achievements.happy_person = 1;
        add_happiness(5);
    }
    
    if (Alice.health.happiness == 100 && !Alice.achievements.very_happy) {
        printf("\nдостижение \"Абсолютное счастье\"\n");
        printf("   уровень счастья достиг максимума\n");
        printf("   награда: +0 (счастье есть, больше не влезет)\n");
        Alice.achievements.very_happy = 1;
    }
    
    if (Alice.capital < 50'000 && Alice.capital > 0 && !Alice.achievements.survived_crisis) {
        printf("\nдостижение \"Антикризисный менеджмент\"\n");
        printf("   Алиса пережила финансовый кризис (капитал < 50,000)\n");
        printf("   награда: +5 к счастью\n");
        Alice.achievements.survived_crisis = 1;
        add_happiness(5);
    }
    
    if (Alice.taxes.total_taxes_paid > 500'000 && !Alice.achievements.taxpayer) {
        printf("\nдостижение \"Добросовестный налогоплательщик\"\n");
        printf("   уплачено налогов более 500 000 RUB\n");
        printf("   награда: +2 к счастью\n");
        Alice.achievements.taxpayer = 1;
        add_happiness(2);
    }
    
    if (Alice.taxes.total_taxes_paid > 2'000'000 && !Alice.achievements.big_taxpayer) {
        printf("\nдостижение \"Бюджетообразующий\"\n");
        printf("   уплачено налогов более 2 000 000 RUB\n");
        printf("   награда: +10 к счастью\n");
        Alice.achievements.big_taxpayer = 1;
        add_happiness(10);
    }
    
    if (Alice.charity.donations > 100'000 && !Alice.achievements.philanthropist) {
        printf("\nдостижение \"Филантроп\"\n");
        printf("   пожертвовано более 100 000 RUB\n");
        printf("   награда: +15 к счастью\n");
        Alice.achievements.philanthropist = 1;
        add_happiness(15);
    }
    
    if (Alice.charity.donations > 500'000 && !Alice.achievements.big_philanthropist) {
        printf("\nдостижение \"Великий филантроп\"\n");
        printf("   пожертвовано более 500 000 RUB\n");
        printf("   награда: +25 к счастью\n");
        Alice.achievements.big_philanthropist = 1;
        add_happiness(25);
    }
    
    static int salary_increased = 0;
    if (Alice.salary > 180'000 && !salary_increased) {
        salary_increased = 1;
        if (!Alice.achievements.salary_jump) {
            printf("\nдостижение \"Карьерный рост\"\n");
            printf("   зарплата увеличена благодаря образованию\n");
            printf("   награда: +10 к счастью\n");
            Alice.achievements.salary_jump = 1;
            add_happiness(10);
        }
    }
    
    static int courses_finished = 0;
    static RUB old_salary = 180'000;
    if (Alice.salary > old_salary + 10000 && !courses_finished) {
        courses_finished = 1;
        if (!Alice.achievements.educated) {
            printf("\nдостижение \"Образованная\"\n");
            printf("   Алиса закончила курсы повышения квалификации\n");
            printf("   награда: +5 к счастью\n");
            Alice.achievements.educated = 1;
            add_happiness(5);
        }
    }
    
    static RUB total_lottery_wins = 0;
    if (Alice.random_income > 0) {
        total_lottery_wins += Alice.random_income;
        if (total_lottery_wins > 100'000 && !Alice.achievements.lucky) {
            printf("\nдостижение \"Повезло\"\n");
            printf("   суммарный выигрыш превысил 100 000 RUB\n");
            printf("   награда: +8 к счастью\n");
            Alice.achievements.lucky = 1;
            add_happiness(8);
        }
        if (total_lottery_wins > 500'000 && !Alice.achievements.very_lucky) {
            printf("\nдостижение \"Любимица фортуны\"\n");
            printf("   суммарный выигрыш превысил 500 000 RUB\n");
            printf("   награда: +15 к счастью\n");
            Alice.achievements.very_lucky = 1;
            add_happiness(15);
        }
    }
    
    static RUB total_fines = 0;
    if (Alice.random_expense > 0) {
        total_fines += Alice.random_expense;
        if (total_fines > 50'000 && !Alice.achievements.unlucky) {
            printf("\nдостижение \"Не порядок\"\n");
            printf("   сумма штрафов превысила 50 000 RUB\n");
            printf("   Алиса расстроена (-5 к счастью)\n");
            Alice.achievements.unlucky = 1;
            add_happiness(-5);
        }
    }

    static int salary_received = 0;
    if (Alice.salary > 0 && !salary_received) {
        salary_received = 1;
        if (!Alice.achievements.first_salary) {
            printf("\nдостижение \"Первая зарплата\"\n");
            printf("   Алиса получила свою первую зарплату\n");
            printf("   награда: +5 к счастью\n");
            Alice.achievements.first_salary = 1;
            add_happiness(5);
        }
    }
    
    static RUB last_capital = 0;
    if (last_capital > 0) {
        RUB saved = Alice.capital - last_capital;
        if (saved > 50'000 && !Alice.achievements.saver) {
            printf("\nдостижение \"Копилка\"\n");
            printf("   Алиса сэкономила 50 000 RUB за месяц\n");
            printf("   награда: +8 к счастью\n");
            Alice.achievements.saver = 1;
            add_happiness(8);
        }
        if (saved > 200'000 && !Alice.achievements.big_saver) {
            printf("\nдостижение \"Настоящий сберегатель\"\n");
            printf("   Алиса сэкономила 200 000 RUB за месяц\n");
            printf("   награда: +15 к счастью\n");
            Alice.achievements.big_saver = 1;
            add_happiness(15);
        }
    }
    last_capital = Alice.capital;
    
    static int gym_months = 0;
    if (Alice.health.gym_membership > 0) {
        gym_months++;
        if (gym_months >= 12 && !Alice.achievements.work_out) {
            printf("\nдостижение \"Спортсменка\"\n");
            printf("   Алиса посещала спортзал целый год\n");
            printf("   награда: +10 к счастью\n");
            Alice.achievements.work_out = 1;
            add_happiness(10);
        }
    } else {
        gym_months = 0;
    }
    
    static int cinema_count = 0;
    if (Alice.fun.cinema > 0) {
        cinema_count++;
        if (cinema_count >= 10 && !Alice.achievements.movie_lover) {
            printf("\nдостижение \"Кинолюбительница\"\n");
            printf("   Алиса сходила в кино 10 раз\n");
            printf("   награда: +5 к счастью\n");
            Alice.achievements.movie_lover = 1;
            add_happiness(5);
        }
    }
    
    static RUB travel_total = 0;
    travel_total += Alice.fun.travel_budget;
    if (travel_total > 100'000 && !Alice.achievements.traveler) {
        printf("\nдостижение \"Путешественница\"\n");
        printf("   Алиса потратила на путешествия более 100 000 RUB\n");
        printf("   награда: +10 к счастью\n");
        Alice.achievements.traveler = 1;
        add_happiness(10);
    }
    
    static RUB hobby_total = 0;
    hobby_total += Alice.fun.hobbies;
    if (hobby_total > 50'000 && !Alice.achievements.hobbyist) {
        printf("\nдостижение \"Творческая личность\"\n");
        printf("   Алиса потратила на хобби более 50 000 RUB\n");
        printf("   награда: +5 к счастью\n");
        Alice.achievements.hobbyist = 1;
        add_happiness(5);
    }
    
    static int lottery_wins = 0;
    if (Alice.random_income > 0 && Alice.random_income >= 50'000) {
        lottery_wins++;
        if (!Alice.achievements.lucky_day) {
            printf("\nдостижение \"Везунчик\"\n");
            printf("   Алиса выиграла в лотерею\n");
            printf("   награда: +10 к счастью\n");
            Alice.achievements.lucky_day = 1;
            add_happiness(10);
        }
    }
    
    static int gift_count = 0;
    if (Alice.random_income > 0 && Alice.random_income < 50'000) {
        gift_count++;
        if (gift_count >= 5 && !Alice.achievements.gift_receiver) {
            printf("\nдостижение \"Любимица\"\n");
            printf("   Алисе подарили подарки 5 раз\n");
            printf("   награда: +5 к счастью\n");
            Alice.achievements.gift_receiver = 1;
            add_happiness(5);
        }
    }
    
    static RUB fines_total = 0;
    fines_total += Alice.car.fine;
    if (fines_total > 10'000 && !Alice.achievements.fine_payer) {
        printf("\nдостижение \"Нарушительница\" (не гордость, но факт)\n");
        printf("   Алиса заплатила штрафов более 10 000 RUB\n");
        printf("   Алиса расстроена (-2 к счастью)\n");
        Alice.achievements.fine_payer = 1;
        add_happiness(-2);
    }
    
    static int sickness_count = 0;
    if (Alice.health.medicine > 0) {
        sickness_count++;
        if (sickness_count >= 3 && !Alice.achievements.survivor) {
            printf("\nдостижение \"Здоровый дух\"\n");
            printf("   Алиса пережила 3 болезни\n");
            printf("   награда: +8 к счастью\n");
            Alice.achievements.survivor = 1;
            add_happiness(8);
        }
    }
}

void print_all_achievements() {
    printf("\nСписок достижений:\n\n");
    
    printf("Финансовые:\n");
    if (Alice.achievements.millionaire) {
        printf("- \"Миллионер\"\n");
    }
    if (Alice.achievements.multimillionaire) {
        printf("- \"Мультимиллионер\"\n");
    }
    if (Alice.achievements.billionaire) {
        printf("- \"Богатейшая женщина города\"\n");
    }

    printf("\nНедвижимость:\n");
    if (Alice.achievements.homeowner) {
        printf("- \"Полноправный владелец\"\n");
    }
    if (Alice.achievements.landlord) {
        printf("- \"Арендодатель\"\n");
    }
    
    printf("\nИнвестиции:\n");
    if (Alice.achievements.beginner_investor) {
        printf("- \"Начинающий инвестор\"\n");
    }
    if (Alice.achievements.serious_investor) {
        printf("- \"Серьёзный инвестор\"\n");
    }
    if (Alice.achievements.pro_investor) {
        printf("- \"Профессиональный инвестор\"\n");
    }
    if (Alice.achievements.balanced_portfolio) {
        printf("- \"Сбалансированный портфель\"\n");
    }
    
    printf("\nТранспорт:\n");
    if (Alice.achievements.car_owner) {
        printf("- \"Автовладелец\"\n");
    }
    if (Alice.achievements.luxury_car) {
        printf("- \"Роскошный автомобиль\"\n");
    }
    
    printf("\nКачество жизни:\n");
    if (Alice.achievements.happy_person) {
        printf("- \"Счастливая жизнь\"\n");
    }
    if (Alice.achievements.very_happy) {
        printf("- \"Абсолютное счастье\"\n");
    }
    if (Alice.achievements.survived_crisis) {
        printf("- \"Антикризисный менеджмент\"\n");
    }
    
    printf("\nСоциальные:\n");
    if (Alice.achievements.taxpayer) {
        printf("- \"Добросовестный налогоплательщик\"\n");
    }
    if (Alice.achievements.big_taxpayer) {
        printf("- \"Бюджетообразующий\"\n");
    }
    if (Alice.achievements.philanthropist) {
        printf("- \"Филантроп\"\n");
    }
    if (Alice.achievements.big_philanthropist) {
        printf("- \"Великий филантроп\"\n");
    }
    
    printf("\nОбразование:\n");
    if (Alice.achievements.educated) {
        printf("- \"Образованная\"\n");
    }
    if (Alice.achievements.salary_jump) {
        printf("- \"Карьерный рост\"\n");
    }
    
    printf("\nУдача:\n");
    if (Alice.achievements.lucky) {
        printf("- \"Повезло\"\n");
    }
    if (Alice.achievements.very_lucky) {
        printf("- \"Любимица фортуны\"\n");
    }
    if (Alice.achievements.unlucky) {
        printf("- \"Не порядок\"\n");
    }

    printf("\nПростые достижения:\n");
    if (Alice.achievements.first_salary) {
        printf("- \"Первая зарплата\"\n");
    }
    if (Alice.achievements.saver) {
        printf("- \"Копилка\"\n");
    }
    if (Alice.achievements.big_saver) {
        printf("- \"Настоящий сберегатель\"\n");
    }
    if (Alice.achievements.work_out) {
        printf("- \"Спортсменка\"\n");
    }
    if (Alice.achievements.movie_lover) {
        printf("- \"Кинолюбительница\"\n");
    }
    if (Alice.achievements.traveler) {
        printf("- \"Путешественница\"\n");
    }
    if (Alice.achievements.hobbyist) {
        printf("- \"Творческая личность\"\n");
    }
    if (Alice.achievements.lucky_day) {
        printf("- \"Везунчик\"\n");
    }
    if (Alice.achievements.gift_receiver) {
        printf("- \"Любимица\"\n");
    }
    if (Alice.achievements.fine_payer) {
        printf("- \"Нарушительница\"\n");
    }
    if (Alice.achievements.survivor) {
        printf("- \"Здоровый дух\"\n");
    }

    printf("\nСУПЕР достижения:\n");
    if (Alice.achievements.ten_years_survivor) {
        printf("- \"Побег из матрицы\"\n");
    }
    
    printf("\n");
}

void alice_calculate_income_tax() {
    RUB total_income = Alice.salary + Alice.random_income;
    
    static int education_deduction_used = 0;
    static int current_year = 2026;
    
    if (Alice.education > 0 && !education_deduction_used && Alice.taxes.has_deduction) {
        RUB deduction = Alice.education;
        if (deduction > 120'000) {
            deduction = 120'000;
        }
        Alice.taxes.tax_refund = deduction * 0.13;
        total_income -= deduction;
        education_deduction_used = 1;
        printf("налоговый вычет за обучение %lld RUB\n", Alice.taxes.tax_refund);
    }
    
    Alice.taxes.income_tax = total_income * Alice.taxes.tax_rate / 100.0;
    
    if (Alice.taxes.tax_refund > 0) {
        Alice.taxes.income_tax -= Alice.taxes.tax_refund;
        if (Alice.taxes.income_tax < 0) {
            Alice.taxes.income_tax = 0;
        }
    }
    
    printf("НДФЛ (13%%): %lld RUB\n", Alice.taxes.income_tax);
}

void alice_calculate_property_tax() {
    Alice.taxes.property_tax = Alice.realty.apartment_value * 0.1 / 100.0;
    
    RUB car_tax = Alice.car.value * 0.5 / 100.0;
    Alice.taxes.property_tax += car_tax;
    
    printf("налог на имущество %lld RUB (квартира + машина)\n", Alice.taxes.property_tax);
}

void alice_calculate_capital_gains_tax() {
    static RUB last_stocks = 0;
    static RUB last_bonds = 0;
    
    if (last_stocks == 0) {
        last_stocks = Alice.invest.stocks;
        last_bonds = Alice.invest.bonds;
        return;
    }
    
    RUB stocks_gain = Alice.invest.stocks - last_stocks;
    RUB bonds_gain = Alice.invest.bonds - last_bonds;
    
    if (stocks_gain > 0) {
        Alice.taxes.capital_gains_tax += stocks_gain * 0.13;
    }
    if (bonds_gain > 0) {
        Alice.taxes.capital_gains_tax += bonds_gain * 0.13;
    }
    
    last_stocks = Alice.invest.stocks;
    last_bonds = Alice.invest.bonds;
    
    if (Alice.taxes.capital_gains_tax > 0) {
        printf("налог на прирост капитала %lld RUB\n", Alice.taxes.capital_gains_tax);
    }
}

void alice_pay_taxes() {
    RUB monthly_tax = Alice.taxes.income_tax;
    
    static int months_counter = 0;
    months_counter++;
    
    if (months_counter == 12) {
        monthly_tax += Alice.taxes.property_tax;
        monthly_tax += Alice.taxes.capital_gains_tax;
        months_counter = 0;
        Alice.taxes.capital_gains_tax = 0;
    }
    
    Alice.capital -= monthly_tax;
    Alice.taxes.total_taxes_paid += monthly_tax;
    
    if (monthly_tax > 0) {
        printf("уплачено налогов %lld RUB\n", monthly_tax);
    }
}

void alice_bank_interest() {
    
    double annual_rate = sberbank.deposit_rate;
    double monthly_rate = annual_rate / 12.0 / 100.0;
    
    RUB base_capital = Alice.capital;
    RUB interest_earned = 0;
    RUB commission_amount = 0;
    RUB loyalty_bonus = 0;
    
    if (base_capital <= 0) {
        printf("на счету 0 RUB, проценты не начислены\n");
        return;
    }
    
    interest_earned = base_capital * monthly_rate;
    
    if (interest_earned > 1'000'000) {
        interest_earned = 1'000'000;
        printf("достигнут лимит начисления процентов (1 млн RUB в месяц)\n");
    }
    
    if (interest_earned > 0 && interest_earned < 1) {
        interest_earned = 1;
    }
    
    Alice.capital += interest_earned;
    
    if (interest_earned > 0) {
        printf("банковский процент: +%lld RUB (ставка %.1f%% годовых)\n", interest_earned, annual_rate);
    }
    
    commission_amount = sberbank.commission;
    
    if (Alice.capital > 5'000'000) {
        commission_amount = commission_amount * 0.5;
        printf("VIP-клиент: комиссия снижена на 50%%\n");
    }
    
    static int months_with_bank = 0;
    months_with_bank++;

    if (months_with_bank >= 12 && Alice.capital > 1'000'000) {
        commission_amount = commission_amount * 0.7;
        printf("постоянный клиент (более года): комиссия снижена на 30%%\n");
    }
    
    if (commission_amount > Alice.capital) {
        printf("недостаточно средств для списания комиссии (%lld RUB)\n", commission_amount);
        commission_amount = Alice.capital;
    }
    
    if (commission_amount > 0) {
        Alice.capital -= commission_amount;
        printf("комиссия за обслуживание: -%lld RUB\n", commission_amount);
    }
    
    if (Alice.mortgage.has_mortgage == 0 && Alice.random_expense == 0) {
        RUB loyalty_bonus = interest_earned * 0.1;
        if (loyalty_bonus > 0) {
            Alice.capital += loyalty_bonus;
            printf("бонус за отсутствие задолженностей: +%lld RUB\n", loyalty_bonus);
        }
    }
    
    if (Alice.capital < 0) {
        RUB overdraft_fee = -Alice.capital * 0.05;
        if (overdraft_fee > 10'000) {
            overdraft_fee = 10'000;
        }
        Alice.capital -= overdraft_fee;
        printf("штраф за овердрафт: -%lld RUB\n", overdraft_fee);
        add_happiness(-5);
    }
    
    RUB net_change = interest_earned + (commission_amount > 0 ? -commission_amount : 0);
    if (loyalty_bonus > 0) {
        net_change += loyalty_bonus;
    }
    
    printf("итоговое изменение счета: %+lld RUB\n", net_change);
    
    if (Alice.capital < 0) {
        printf("ПРЕДУПРЕЖДЕНИЕ: баланс отрицательный (%lld RUB)!\n", Alice.capital);
        add_happiness(-10);
    }
}

void alice_insurance() {
    if (health_insurance.has_insurance) {
        RUB health_premium = health_insurance.monthly_premium;
        
        static int health_insurance_years = 0;
        static int months_with_health = 0;
        months_with_health++;
        
        if (months_with_health >= 12) {
            months_with_health = 0;
            health_insurance_years++;
            
            if (health_insurance_years >= 3) {
                health_premium = health_premium * 0.85;
                printf("скидка на страховку здоровья за 3 года: 15%%\n");
            } else if (health_insurance_years >= 1) {
                health_premium = health_premium * 0.95;
                printf("скидка на страховку здоровья за 1 год: 5%%\n");
            }
        }
        
        Alice.capital -= health_premium;
        health_insurance.total_paid += health_premium;
        health_insurance.years_paid = health_insurance_years;
        
        printf("страховка здоровья: %lld RUB в месяц\n", health_premium);
        
        if (Alice.health.medicine > 0 && health_insurance.coverage_amount > 0) {
            RUB payout = Alice.health.medicine * 0.7;
            if (payout > health_insurance.coverage_amount) {
                payout = health_insurance.coverage_amount;
            }
            Alice.capital += payout;
            health_insurance.last_payout_month++;
            printf("страховка здоровья покрыла расходы на лекарства: +%lld RUB\n", payout);
            add_happiness(5);
        }
        
        if (health_insurance.years_paid % 12 == 0 && health_insurance.years_paid > 0) {
            printf("оплачен %d-й год страховки здоровья (всего %lld RUB)\n", health_insurance.years_paid, health_insurance.total_paid);
        }
    }
    
    if (Alice.realty.has_insurance) {
        RUB property_premium = Alice.realty.insurance_premium;
        
        static int property_insurance_years = 0;
        static int months_with_property = 0;
        months_with_property++;
        
        if (months_with_property >= 12) {
            months_with_property = 0;
            property_insurance_years++;
            
            if (property_insurance_years >= 3) {
                property_premium = property_premium * 0.8;
                printf("скидка на страховку недвижимости за 3 года: 20%%\n");
            } else if (property_insurance_years >= 1) {
                property_premium = property_premium * 0.95;
                printf("скидка на страховку недвижимости за 1 год: 5%%\n");
            }
        }
        
        Alice.capital -= property_premium;
        printf("страховка недвижимости: %lld RUB в месяц\n", property_premium);
        
        int accident = rand() % 100;
        if (accident < 2 && Alice.realty.apartment_condition < 5) {
            RUB damage = Alice.realty.apartment_value * 0.05;
            if (damage > 500000) {
                damage = 500000;
            }
            Alice.capital += damage;
            Alice.realty.insurance_payout = damage;
            printf("страховой случай по недвижимости: выплачено %lld RUB на ремонт\n", damage);
            add_happiness(-5);
        }
        
        if (Alice.realty.has_cottage && accident < 3) {
            RUB cottage_damage = Alice.realty.cottage_value * 0.03;
            if (cottage_damage > 100000) {
                cottage_damage = 100000;
            }
            Alice.capital += cottage_damage;
            printf("страховой случай на даче: выплачено %lld RUB\n", cottage_damage);
            add_happiness(-3);
        }
    }
    
    static int car_insurance_active = 0;
    static RUB car_insurance_premium = 0;
    
    if (Alice.car.value > 0 && !car_insurance_active) {
        car_insurance_active = 1;
        car_insurance_premium = Alice.car.value * 0.005;
        printf("оформлена автостраховка: %lld RUB в месяц\n", car_insurance_premium);
    }
    
    if (car_insurance_active && Alice.car.value > 0) {
        Alice.capital -= car_insurance_premium;
        printf("автостраховка: %lld RUB в месяц\n", car_insurance_premium);
        
        static int months_no_accident = 0;
        if (Alice.car.fine == 0 && Alice.car.maintenance == 0) {
            months_no_accident++;
            if (months_no_accident >= 12 && car_insurance_premium > 1000) {
                car_insurance_premium = car_insurance_premium * 0.9;
                printf("скидка на автостраховку за безаварийную езду: 10%%\n");
                months_no_accident = 0;
            }
        } else {
            months_no_accident = 0;
        }
        
        int car_accident = rand() % 100;
        if (car_accident < 1 && Alice.car.value > 0) {
            RUB car_damage = Alice.car.value * 0.15;
            if (car_damage > 200000) {
                car_damage = 200000;
            }
            Alice.capital += car_damage;
            printf("автостраховка покрыла ущерб после ДТП: +%lld RUB\n", car_damage);
            add_happiness(-8);
        }
    } else if (car_insurance_active && Alice.car.value == 0) {
        car_insurance_active = 0;
        printf("автостраховка отменена (нет автомобиля)\n");
    }
}

void alice_update_diet() {
    if (Alice.capital > 1'000'000 && Alice.health.happiness > 70) {
        if (Alice.food_detail.diet_type != 2) {
            Alice.food_detail.diet_type = 2;
            printf("Алиса перешла на здоровое питание (капитал > 1 млн)\n");
            add_happiness(3);
        }
    }

    else if (Alice.capital < 200'000) {
        if (Alice.food_detail.diet_type != 3) {
            Alice.food_detail.diet_type = 3;
            printf("Алиса перешла на экономное питание (капитал < 200k)\n");
            add_happiness(-2);
        }
    }

    else {
        if (Alice.food_detail.diet_type != 1) {
            Alice.food_detail.diet_type = 1;
            printf("Алиса вернулась к обычному питанию\n");
        }
    }
}

void alice_food() {
    static int food_months = 0;
    food_months++;
    if (food_months >= 12) {
        Alice.food += Alice.food * (sberbank.inflation_rate * 12 / 100.0);
        food_months = 0;
        printf("индексация расходов на питание: +%.1f%%\n", sberbank.inflation_rate * 12);
    }
    
    RUB base_food_cost = Alice.food;
    RUB actual_food_cost = base_food_cost;
    
    double cooking_saving = Alice.food_detail.cooking_skill * 0.005;
    if (cooking_saving > 0.2) {
        cooking_saving = 0.2;
    }
    
    switch(Alice.food_detail.diet_type) {
        case 1:
            actual_food_cost = base_food_cost * (1.0 - cooking_saving);
            break;
        case 2:
            actual_food_cost = base_food_cost * 1.3 * (1.0 - cooking_saving);
            add_happiness(2);
            break;
        case 3:
            actual_food_cost = base_food_cost * 0.8 * (1.0 - cooking_saving);
            add_happiness(-1);
            break;
    }
    
    Alice.food_detail.home_cooking = actual_food_cost * 0.4;
    Alice.food_detail.cafe = actual_food_cost * 0.2;
    Alice.food_detail.delivery = actual_food_cost * 0.15;
    Alice.food_detail.groceries = actual_food_cost * 0.25;
    
    if (Alice.salary > 0) {
        Alice.food_detail.work_lunch = actual_food_cost * 0.3;
        actual_food_cost += Alice.food_detail.work_lunch;
    }
    
    if (Alice.food_detail.home_cooking > 10'000 && Alice.food_detail.cooking_skill < 40) {
        Alice.food_detail.cooking_skill++;
        printf("навык готовки повышен до %d/40 (экономия %.1f%%)\n", Alice.food_detail.cooking_skill, cooking_saving * 100);
    }
    
    if ((rand() % 100) < 3 && Alice.food_detail.groceries > 5'000) {
        RUB waste = Alice.food_detail.groceries * 0.2;
        actual_food_cost += waste;
        printf("часть продуктов испортилась: потеряно %lld RUB\n", waste);
        add_happiness(-2);
    }
    
    if ((rand() % 100) < 8) {
        RUB discount = actual_food_cost * 0.1;
        actual_food_cost -= discount;
        printf("скидка на продукты: сохранено %lld RUB\n", discount);
        add_happiness(1);
    }
    
    Alice.capital -= actual_food_cost;
    
    printf("расходы на питание %lld RUB", actual_food_cost);

    if (Alice.food_detail.diet_type == 2) {
        printf(" (здоровое питание)");
    }

    if (Alice.food_detail.diet_type == 3) {
        printf(" (эконом режим)");
    }

    printf("\n");
}

void alice_health() {
    Alice.health.gym_membership += Alice.health.gym_membership * (sberbank.inflation_rate / 100.0);

    if (Alice.capital > 1'000'000) {
        add_happiness(2);
    }
    else if (Alice.capital < 100'000) {
        add_happiness(-3);
    }
    
    Alice.capital -= Alice.health.gym_membership;
    Alice.capital -= Alice.health.medicine;
    Alice.health.medicine = 0;
}

void alice_investments() {
    Alice.invest.stocks += Alice.invest.stocks * ((Alice.invest.stocks_growth_rate + sberbank.inflation_rate) / 100.0);
    
    Alice.invest.bonds += Alice.invest.bonds * (0.5 + sberbank.inflation_rate) / 100.0;
    
    Alice.capital += Alice.invest.stocks + Alice.invest.bonds;
}

void alice_mortgage_payment() {
    if (Alice.mortgage.has_mortgage && Alice.mortgage.remaining_balance > 0) {
        RUB payment = Alice.mortgage.monthly_payment;
        
        if (payment > Alice.mortgage.remaining_balance) {
            payment = Alice.mortgage.remaining_balance;
            Alice.mortgage.has_mortgage = 0;
            printf("ипотека полностью погашена\n");
        }
        
        Alice.capital -= payment;
        Alice.mortgage.remaining_balance -= payment;
        Alice.mortgage.months_paid++;
        
        printf("платёж по ипотеке %lld RUB\n", payment);
        printf("остаток %lld RUB\n", Alice.mortgage.remaining_balance);
    }
}

void alice_real_estate() {
    Alice.realty.utilities_electricity += Alice.realty.utilities_electricity * (sberbank.inflation_rate / 100.0);
    Alice.realty.utilities_water += Alice.realty.utilities_water * (sberbank.inflation_rate / 100.0);
    Alice.realty.utilities_gas += Alice.realty.utilities_gas * (sberbank.inflation_rate / 100.0);
    Alice.realty.utilities_internet += Alice.realty.utilities_internet * (sberbank.inflation_rate / 100.0);

    RUB apartment_tax_total = Alice.realty.apartment_tax;
    
    if (Alice.realty.has_cottage) {
        apartment_tax_total += Alice.realty.cottage_tax;
    }
    
    if (Alice.realty.has_commercial) {
        apartment_tax_total += Alice.realty.commercial_value * 0.002;
    }
    
    if (Alice.realty.has_second_apartment) {
        apartment_tax_total += Alice.realty.second_apartment_value * 0.001;
    }
    
    Alice.capital -= apartment_tax_total;
    printf("налог на недвижимость: %lld RUB\n", apartment_tax_total);
    
    if (Alice.realty.rent_income > 0) {
        Alice.capital -= Alice.realty.rent_income;
        printf("аренда жилья: %lld RUB\n", Alice.realty.rent_income);
    }
    
    if (Alice.realty.has_commercial && Alice.realty.commercial_income > 0) {
        Alice.capital += Alice.realty.commercial_income;
        printf("доход от аренды коммерческой недвижимости: %lld RUB\n", Alice.realty.commercial_income);
    }
    
    if (Alice.realty.has_second_apartment && Alice.realty.second_apartment_rent > 0) {
        Alice.capital += Alice.realty.second_apartment_rent;
        printf("доход от аренды второй квартиры: %lld RUB\n", Alice.realty.second_apartment_rent);
    }
    
    alice_utilities_payment();
    
    alice_mortgage_payment();
    
    static int months_since_repair = 0;
    months_since_repair++;
    
    if (months_since_repair > 120 && Alice.realty.apartment_condition > 1) {
        Alice.realty.apartment_condition--;
        months_since_repair = 0;
        printf("состояние квартиры ухудшилось до %d/10\n", Alice.realty.apartment_condition);
        add_happiness(-3);
    }
    
    double growth_rate = 0.3 + sberbank.inflation_rate;
    
    if (Alice.realty.apartment_condition >= 8) {
        growth_rate += 0.2;
    }
    
    if (Alice.realty.apartment_condition <= 3) {
        growth_rate -= 0.3;
    }
    
    Alice.realty.apartment_value += Alice.realty.apartment_value * (growth_rate / 100.0);
    
    if (Alice.realty.has_cottage) {
        Alice.realty.cottage_value += Alice.realty.cottage_value * ((0.2 + sberbank.inflation_rate) / 100.0);
        Alice.capital -= Alice.realty.cottage_maintenance;
        printf("расходы на содержание дачи: %lld RUB\n", Alice.realty.cottage_maintenance);
    }
    
    if (Alice.realty.has_commercial) {
        Alice.realty.commercial_value += Alice.realty.commercial_value * ((0.5 + sberbank.inflation_rate) / 100.0);
    }
    
    if (Alice.realty.has_second_apartment) {
        Alice.realty.second_apartment_value += Alice.realty.second_apartment_value * ((0.3 + sberbank.inflation_rate) / 100.0);
    }
    
    if (Alice.capital > 100000) {
        RUB repair_saving = 5000;
        Alice.realty.repair_fund += repair_saving;
        Alice.capital -= repair_saving;
        printf("отложено на ремонт: %lld RUB (всего %lld RUB)\n", repair_saving, Alice.realty.repair_fund);
    }
    
    if (Alice.realty.repair_fund >= 100000 && Alice.realty.apartment_condition < 10) {
        alice_repair_property();
    }
    
    if (!Alice.realty.has_cottage && Alice.capital > 3000000) {
        alice_buy_cottage();
    }
    
    if (!Alice.realty.has_commercial && Alice.capital > 5000000) {
        alice_buy_commercial();
    }
    
    if (!Alice.realty.has_second_apartment && Alice.capital > 4000000 && !Alice.mortgage.has_mortgage) {
        alice_buy_second_apartment();
    }
}

void alice_utilities_payment() {
    RUB total_utilities = Alice.realty.utilities_electricity;
    total_utilities += Alice.realty.utilities_water;
    total_utilities += Alice.realty.utilities_gas;
    total_utilities += Alice.realty.utilities_internet;
    
    static int month_counter = 0;
    month_counter++;
    if (month_counter == 12) month_counter = 0;
    
    if (month_counter == 1 || month_counter == 2) {
        total_utilities += 3000;
        printf("зимний сезон: отопление +3000 RUB\n");
    }
    
    if (Alice.realty.apartment_condition >= 8) {
        RUB saving = total_utilities * 0.1;
        total_utilities -= saving;
        printf("экономия на коммунальных (хорошее состояние): %lld RUB\n", saving);
    }
    
    Alice.capital -= total_utilities;
    printf("коммунальные платежи: %lld RUB\n", total_utilities);
    
    if (total_utilities > 10000) {
        printf("высокие коммунальные платежи, рекомендуется экономить\n");
        add_happiness(-2);
    }
}

void alice_property_insurance() {
    if (Alice.realty.has_insurance) {
        RUB total_premium = Alice.realty.insurance_premium;
        
        static int insurance_years = 0;
        insurance_years++;
        if (insurance_years >= 36) {
            total_premium = total_premium * 0.8;
            printf("скидка на страховку за 3 года: 20%%\n");
        }
        
        Alice.capital -= total_premium;
        printf("страховка недвижимости: %lld RUB\n", total_premium);

        int accident = rand() % 100;
        if (accident < 2 && Alice.realty.apartment_condition < 5) {
            RUB damage = Alice.realty.apartment_value * 0.05;
            Alice.capital -= damage;
            Alice.realty.insurance_payout = damage;
            printf("страховой случай: выплачено %lld RUB на ремонт\n", damage);
            add_happiness(-10);
        }
    }
}

void alice_buy_cottage() {
    if (Alice.capital > 3000000 && !Alice.realty.has_cottage) {
        Alice.realty.cottage_value = 2500000;
        Alice.realty.cottage_tax = 1500;
        Alice.realty.cottage_maintenance = 5000;
        Alice.realty.cottage_condition = 8;
        Alice.realty.cottage_area = 6;
        Alice.realty.has_cottage = 1;
        Alice.capital -= 2500000;
        
        printf("покупка дачи: 2 500 000 RUB\n");
        printf("площадь участка: 6 соток\n");
        printf("состояние дома: хорошее\n");
        add_happiness(15);
    }
}

void alice_buy_commercial() {
    if (Alice.capital > 5000000 && !Alice.realty.has_commercial) {
        Alice.realty.commercial_value = 4500000;
        Alice.realty.commercial_income = 25000;
        Alice.realty.has_commercial = 1;
        Alice.capital -= 4500000;
        
        printf("покупка коммерческой недвижимости: 4 500 000 RUB\n");
        printf("ежемесячный доход от аренды: 25 000 RUB\n");
        add_happiness(20);
    }
}

void alice_buy_second_apartment() {
    if (Alice.capital > 4000000 && !Alice.realty.has_second_apartment && !Alice.mortgage.has_mortgage) {
        RUB price = 3500000;
        Alice.realty.second_apartment_value = price;
        Alice.realty.second_apartment_rent = 20000;
        Alice.realty.has_second_apartment = 1;
        Alice.capital -= price;
        
        printf("покупка второй квартиры: 3 500 000 RUB\n");
        printf("ежемесячный доход от аренды: 20 000 RUB\n");
        add_happiness(20);
        
        if (!Alice.achievements.landlord) {
            printf("достижение Арендодатель\n");
            Alice.achievements.landlord = 1;
            add_happiness(5);
        }
    }
}

void alice_repair_property() {
    if (Alice.realty.repair_fund >= 100000 && Alice.realty.apartment_condition < 10) {
        RUB repair_cost = 100000;
        Alice.realty.repair_fund -= repair_cost;
        Alice.realty.apartment_condition++;
        Alice.realty.last_repair_year = 2026;
        
        printf("ремонт квартиры: потрачено %lld RUB\n", repair_cost);
        printf("состояние квартиры улучшилось до %d/10\n", Alice.realty.apartment_condition);
        add_happiness(10);
        
        RUB value_increase = Alice.realty.apartment_value * 0.03;
        Alice.realty.apartment_value += value_increase;
        printf("стоимость квартиры выросла на %lld RUB\n", value_increase);
    }
}

void alice_entertainment() {
    Alice.fun.cinema += Alice.fun.cinema * (sberbank.inflation_rate / 100.0);
    Alice.fun.restaurants += Alice.fun.restaurants * (sberbank.inflation_rate / 100.0);
    Alice.fun.travel_budget += Alice.fun.travel_budget * (sberbank.inflation_rate / 100.0);
    Alice.fun.hobbies += Alice.fun.hobbies * (sberbank.inflation_rate / 100.0);

    Alice.capital -= Alice.fun.cinema;
    Alice.capital -= Alice.fun.restaurants;
    Alice.capital -= Alice.fun.travel_budget;
    Alice.capital -= Alice.fun.hobbies;
    
    RUB total_fun = Alice.fun.cinema + Alice.fun.restaurants + Alice.fun.travel_budget + Alice.fun.hobbies;
    
    if (total_fun > 30'000) {
        add_happiness(15);
    }
    else if (total_fun > 10'000) {
        add_happiness(8);
    }
    else {
        add_happiness(-3);
    }
}

void alice_random_events() {
    Alice.capital -= 100;
    int lottery_prob = rand() % 100;
    
    if (lottery_prob < 5) {
        RUB win = 50'000 + (rand() % 200'000);
        Alice.random_income += win;
        printf("Алиса выиграла %lld RUB в лотерею\n", win);
        add_happiness(15);
    }

    int fine_prob = rand() % 100;
    if (fine_prob < 10) {
        RUB fine = 1'000 + (rand() % 10'000);
        Alice.random_expense += fine;
        printf("Алиса получила штраф %lld RUB\n", fine);
        add_happiness(-8);
    }

    int gift_prob = rand() % 100;
    if (gift_prob < 15) {
        RUB gift = 3'000 + (rand() % 20'000);
        Alice.random_income += gift;
        printf("Алисе подарили %lld RUB\n", gift);
        add_happiness(5);
    }
    
    int sickness_prob = rand() % 100;
    if (sickness_prob < 12) {
        RUB medicine_cost = 3'000 + (rand() % 15'000);
        Alice.health.medicine = medicine_cost;
        printf("Алиса заболела; траты на лекарства %lld RUB\n", medicine_cost);
        add_happiness(-12);
    }

    int bonus_prob = rand() % 100;
    if (bonus_prob < 8) {
        RUB bonus = Alice.salary * 0.5;
        Alice.random_income += bonus;
        printf("премия на работе +%lld RUB\n", bonus);
        add_happiness(10);
    }
    
    int device_prob = rand() % 100;
    if (device_prob < 6) {
        RUB repair_cost = 5'000 + (rand() % 30'000);
        Alice.random_expense += repair_cost;
        printf("сломалась техника, ремонт: %lld RUB\n", repair_cost);
        add_happiness(-5);
    }
    
    int found_prob = rand() % 100;
    if (found_prob < 7) {
        RUB found = 500 + (rand() % 5'000);
        Alice.random_income += found;
        printf("нашла %lld RUB на улице\n", found);
        add_happiness(3);
    }

    int discount_prob = rand() % 100;
    if (discount_prob < 10) {
        RUB saving = 2'000 + (rand() % 8'000);
        Alice.random_income += saving;
        printf("скидка в магазине; сэкономила %lld RUB\n", saving);
        add_happiness(4);
    }
    
    int utility_prob = rand() % 100;
    if (utility_prob < 15) {
        RUB utility_cost = 1'000 + (rand() % 7'000);
        Alice.random_expense += utility_cost;
        printf("повышение коммунальных платежей: +%lld RUB\n", utility_cost);
        add_happiness(-3);
    }
    
    static RUB friend_debt = 0;
    if (friend_debt == 0) {
        int lend_prob = rand() % 100;
        if (lend_prob < 8 && Alice.capital > 50'000) {
            friend_debt = 10'000 + (rand() % 20'000);
            Alice.capital -= friend_debt;
            printf("друг попросил в долг %lld RUB (обещал вернуть через месяц)\n", friend_debt);
            add_happiness(-2);
        }
    } else {
        int return_prob = rand() % 100;
        if (return_prob < 70) {
            Alice.random_income += friend_debt;
            printf("друг вернул долг %lld RUB\n", friend_debt);
            add_happiness(6);
            friend_debt = 0;
        } else {
            printf("друг не вернул долг в этом месяце :(\n");
            add_happiness(-4);
        }
    }
    
    int currency_prob = rand() % 100;
    if (currency_prob < 20) {
        double change = (rand() % 10) / 100.0;
        if (rand() % 2 == 0) {
            Alice.invest.stocks += Alice.invest.stocks * change;
            printf("курс акций вырос на %.1f%%\n", change * 100);
            add_happiness(3);
        } else {
            Alice.invest.stocks -= Alice.invest.stocks * change;
            printf("курс акций упал на %.1f%%\n", change * 100);
            add_happiness(-3);
        }
    }
    
    int neighbor_prob = rand() % 100;
    if (neighbor_prob < 5) {
        RUB help = 2'000 + (rand() % 8'000);
        Alice.random_income += help;
        printf("сосед помог с ремонтом, сэкономила %lld RUB\n", help);
        add_happiness(7);
    }
    
    int lost_prob = rand() % 100;
    if (lost_prob < 4) {
        RUB lost_value = 3'000 + (rand() % 15'000);
        Alice.random_expense += lost_value;
        printf("потеряла кошелёк с %lld RUB\n", lost_value);
        add_happiness(-10);
    }
    
    int contest_prob = rand() % 100;
    if (contest_prob < 3) {
        RUB prize = 5'000 + (rand() % 25'000);
        Alice.random_income += prize;
        printf("Алиса выиграла конкурс в соцсетях; приз: %lld RUB\n", prize);
        add_happiness(12);
    }
    
    int gym_prob = rand() % 100;
    if (gym_prob < 7 && Alice.health.gym_membership > 0) {
        RUB saved = Alice.health.gym_membership * 0.3;
        Alice.random_income += saved;
        printf("скидка на абонемент в спортзал; сэкономила %lld RUB\n", saved);
        add_happiness(3);
    }
    
    int education_prob = rand() % 100;
    if (education_prob < 5 && Alice.education > 0) {
        RUB scholarship = 5'000 + (rand() % 15'000);
        Alice.random_income += scholarship;
        printf("стипендия за успешную учёбу +%lld RUB\n", scholarship);
        add_happiness(8);
    }
    
    Alice.capital += Alice.random_income;
    Alice.capital -= Alice.random_expense;
    
    static RUB total_sickness = 0;
    if (Alice.health.medicine > 0) {
        total_sickness += Alice.health.medicine;
    }
    
    Alice.random_income = 0;
    Alice.random_expense = 0;
}

void alice_boat(const int month, const int year) {

    RUB fishing_equipment = 8000;
    RUB boat_cost = 20000;
    int boat_is_fine = 1;

    if ((month == 7) && (year == 2030)) {
        printf("Алиса поехала на рыбалку; стоимость лодки и снаряжения: %lld RUB\n", boat_cost + fishing_equipment);
        Alice.capital -= boat_cost + fishing_equipment;
    }

    if ((month == 8) && (year == 2030)) {
        printf("лодка сломалась; Алиса больше не рыбачит\n");
        boat_is_fine = 0;
    }
}

void alice_car() {
    Alice.car.gas += Alice.car.gas * (sberbank.inflation_rate / 100.0);

    Alice.capital -= Alice.car.gas;
    Alice.capital -= Alice.car.maintenance;
    Alice.capital -= Alice.car.fine;
    
    Alice.car.age_months++;
    double depreciation_rate = (Alice.car.age_months > 12) ? 2.0 : 1.0;
    Alice.car.value -= Alice.car.value * (depreciation_rate / 100.0);
    
    if (Alice.car.age_months % 6 == 0) {
        Alice.car.maintenance = 10'000 + (rand() % 20'000);
    }
    else {
        Alice.car.maintenance = 0;
    }
    
    if ((rand() % 100) < 1) {
        Alice.car.fine = 500 + (rand() % 5000);
        printf("штраф за парковку %lld RUB\n", Alice.car.fine);
    }
    else {
        Alice.car.fine = 0;
    }
}

void alice_education() {
    if (Alice.education > 0) {
        Alice.capital -= Alice.education;
        static int study_months = 0;
        study_months++;

        if (study_months == 12) {
            Alice.salary += Alice.salary * 0.1;
            printf("\nАлиса закончила курсы; зарплата повышена до %lld RUB\n", Alice.salary);
            study_months = 0;
            
            add_happiness(20);
        }
    }
}

void alice_salary(const int month, const int year) {
    static int salary_months = 0;
    salary_months++;
    if (salary_months >= 12) {
        RUB old_salary = Alice.salary;
        Alice.salary += Alice.salary * (sberbank.inflation_rate * 12 / 100.0);
        printf("индексация зарплаты: %lld RUB -> %lld RUB (+%.1f%%)\n", 
               old_salary, Alice.salary, sberbank.inflation_rate * 12);
        salary_months = 0;
    }

    if ((month == 8) && (year == 2026)) {
        Alice.salary *= 1.5;
        printf("\nповышение зарплаты: новая зарплата %lld RUB (+50%%)\n", Alice.salary);
        add_happiness(25);
    }
    
    if ((month == 8) && (year == 2028)) {
        Alice.salary *= 1.3;
        printf("\nповышение зарплаты: новая зарплата %lld RUB (+30%%)\n", Alice.salary);
        add_happiness(20);
    }
    
    if ((month == 8) && (year == 2031)) {
        Alice.salary *= 1.25;
        printf("\nповышение зарплаты: новая зарплата %lld RUB (+25%%)\n", Alice.salary);
        add_happiness(20);
    }
    
    if ((month == 8) && (year == 2034)) {
        Alice.salary *= 1.2;
        printf("\nповышение зарплаты: новая зарплата %lld RUB (+20%%)\n", Alice.salary);
        add_happiness(15);
    }
    
    Alice.capital += Alice.salary;
}

void alice_init() {
    Alice.capital = 500'000;
    Alice.salary = 180'000;
    Alice.education = 5'000;
    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;
    Alice.car.maintenance = 0;
    Alice.car.fine = 0;
    Alice.car.age_months = 0;
    Alice.realty.apartment_value = 8'000'000;
    Alice.realty.apartment_tax = 2'000;
    Alice.realty.rent_income = 0;
    Alice.realty.apartment_condition = 8;
    Alice.realty.apartment_rooms = 3;
    Alice.realty.apartment_floor = 5;
    Alice.realty.apartment_building_age = 10;
    
    Alice.realty.cottage_value = 0;
    Alice.realty.cottage_tax = 0;
    Alice.realty.cottage_maintenance = 0;
    Alice.realty.has_cottage = 0;
    Alice.realty.cottage_condition = 0;
    Alice.realty.cottage_area = 0;
    
    Alice.realty.commercial_value = 0;
    Alice.realty.commercial_income = 0;
    Alice.realty.has_commercial = 0;
    
    Alice.realty.second_apartment_value = 0;
    Alice.realty.second_apartment_rent = 0;
    Alice.realty.has_second_apartment = 0;
    
    Alice.realty.repair_fund = 0;
    Alice.realty.last_repair_year = 2026;
    Alice.realty.renovation_quality = 3;
    
    Alice.realty.utilities_electricity = 3000;
    Alice.realty.utilities_water = 1500;
    Alice.realty.utilities_gas = 2000;
    Alice.realty.utilities_internet = 800;
    
    Alice.realty.insurance_premium = 2000;
    Alice.realty.has_insurance = 1;
    Alice.realty.insurance_payout = 0;

    Alice.mortgage.has_mortgage = 0;
    Alice.mortgage.total_loan = 0;
    Alice.mortgage.monthly_payment = 0;
    Alice.mortgage.remaining_balance = 0;
    Alice.mortgage.months_paid = 0;
    Alice.mortgage.total_months = 240;
    Alice.mortgage.interest_rate = 10.0;

    Alice.invest.stocks = 100'000;
    Alice.invest.bonds = 200'000;
    Alice.invest.stocks_growth_rate = 2.5;

    Alice.health.happiness = 80;
    Alice.health.gym_membership = 5'000;
    Alice.health.medicine = 0;

    Alice.fun.cinema = 2'000;
    Alice.fun.restaurants = 8'000;
    Alice.fun.travel_budget = 10'000;
    Alice.fun.hobbies = 3'000;

    Alice.random_income = 0;
    Alice.random_expense = 0;

    sberbank.deposit_rate = 14.5;
    sberbank.commission = 300;

    health_insurance.monthly_premium = 2'500;
    health_insurance.has_insurance = 1;
    health_insurance.coverage_amount = 300'000;
    health_insurance.years_paid = 0;
    health_insurance.last_payout_month = 0;
    health_insurance.total_paid = 0;

    Alice.charity.donations = 0;
    Alice.charity.animals_shelter = 0;
    Alice.charity.orphans_fund = 0;
    Alice.charity.environment = 0;
    Alice.charity.tax_deduction = 0;

    Alice.taxes.income_tax = 0;
    Alice.taxes.property_tax = 0;
    Alice.taxes.capital_gains_tax = 0;
    Alice.taxes.total_taxes_paid = 0;
    Alice.taxes.tax_refund = 0;
    Alice.taxes.has_deduction = 1;
    Alice.taxes.tax_rate = 13.0;

    Alice.food = 20'000;
    Alice.food_detail.home_cooking = 0;
    Alice.food_detail.cafe = 0;
    Alice.food_detail.delivery = 0;
    Alice.food_detail.groceries = 0;
    Alice.food_detail.work_lunch = 0;
    Alice.food_detail.diet_type = 1;
    Alice.food_detail.cooking_skill = 10;
    
    Alice.achievements.millionaire = 0;
    Alice.achievements.multimillionaire = 0;
    Alice.achievements.billionaire = 0;
    Alice.achievements.homeowner = 0;
    Alice.achievements.landlord = 0;
    Alice.achievements.second_home = 0;
    Alice.achievements.beginner_investor = 0;
    Alice.achievements.serious_investor = 0;
    Alice.achievements.pro_investor = 0;
    Alice.achievements.balanced_portfolio = 0;
    Alice.achievements.car_owner = 0;
    Alice.achievements.luxury_car = 0;
    Alice.achievements.happy_person = 0;
    Alice.achievements.very_happy = 0;
    Alice.achievements.survived_crisis = 0;
    Alice.achievements.taxpayer = 0;
    Alice.achievements.big_taxpayer = 0;
    Alice.achievements.philanthropist = 0;
    Alice.achievements.big_philanthropist = 0;
    Alice.achievements.educated = 0;
    Alice.achievements.salary_jump = 0;
    Alice.achievements.lucky = 0;
    Alice.achievements.very_lucky = 0;
    Alice.achievements.unlucky = 0;
    Alice.achievements.ten_years_survivor = 0;
    Alice.achievements.first_salary = 0;
    Alice.achievements.saver = 0;
    Alice.achievements.work_out = 0;
    Alice.achievements.movie_lover = 0;
    Alice.achievements.traveler = 0;
    Alice.achievements.hobbyist = 0;
    Alice.achievements.lucky_day = 0;
    Alice.achievements.gift_receiver = 0;
    Alice.achievements.fine_payer = 0;
    Alice.achievements.survivor = 0;
    Alice.achievements.big_saver = 0;
}

void print_results() {
    printf("\n\n");
    printf("РЕЗУЛЬТАТЫ СИМУЛЯЦИИ\n");
    printf("\n");
    
    printf("ФИНАНСОВОЕ СОСТОЯНИЕ\n");
    printf("зарплата: %lld RUB в месяц\n", Alice.salary);
    printf("капитал: %lld RUB\n", Alice.capital);
    printf("\n");
    
    printf("АКТИВЫ\n");
    printf("стоимость машины: %lld RUB\n", Alice.car.value);
    printf("стоимость квартиры: %lld RUB\n", Alice.realty.apartment_value);
    printf("акции: %lld RUB\n", Alice.invest.stocks);
    printf("облигации: %lld RUB\n", Alice.invest.bonds);
    printf("стоимость всех активов: %lld RUB\n", Alice.capital + Alice.car.value + Alice.realty.apartment_value + Alice.invest.stocks + Alice.invest.bonds);
    printf("\n");
    
    printf("СОСТОЯНИЕ\n");
    printf("счастье: %d из 100\n", Alice.health.happiness);
    printf("возраст машины: %d месяцев\n", Alice.car.age_months);
    
    if (Alice.mortgage.has_mortgage) {
        printf("\nИПОТЕКА\n");
        printf("остаток долга: %lld RUB\n", Alice.mortgage.remaining_balance);
        printf("выплачено месяцев: %d из %d\n", Alice.mortgage.months_paid, Alice.mortgage.total_months);
    }
    
    printf("\n");
    
    printf("СТАТИСТИКА ЗА 10 ЛЕТ\n");
    printf("среднемесячный доход: %lld RUB\n", Alice.salary);
    printf("налогов уплачено всего: %lld RUB\n", Alice.taxes.total_taxes_paid);
    printf("пожертвовано на благотворительность: %lld RUB\n", Alice.charity.donations);
    printf("инвестиционный доход: %lld RUB\n", Alice.invest.stocks + Alice.invest.bonds - 300000);
    
    printf("\n");
    
    printf("ДОСТИЖЕНИЯ ИТОГО\n");
    int achievements_count = 0;
    if (Alice.achievements.millionaire) {
        achievements_count++;
    }
    if (Alice.achievements.multimillionaire) {
        achievements_count++;
    }
    if (Alice.achievements.billionaire) {
        achievements_count++;
    }
    if (Alice.achievements.homeowner) {
        achievements_count++;
    }
    if (Alice.achievements.landlord) {
        achievements_count++;
    }
    if (Alice.achievements.beginner_investor) {
        achievements_count++;
    }
    if (Alice.achievements.serious_investor) {
        achievements_count++;
    }
    if (Alice.achievements.pro_investor) {
        achievements_count++;
    }
    if (Alice.achievements.balanced_portfolio) {
        achievements_count++;
    }
    if (Alice.achievements.car_owner) {
        achievements_count++;
    }
    if (Alice.achievements.luxury_car) {
        achievements_count++;
    }
    if (Alice.achievements.happy_person) {
        achievements_count++;
    }
    if (Alice.achievements.very_happy) {
        achievements_count++;
    }
    if (Alice.achievements.survived_crisis) {
        achievements_count++;
    }
    if (Alice.achievements.taxpayer) {
        achievements_count++;
    }
    if (Alice.achievements.big_taxpayer) {
        achievements_count++;
    }
    if (Alice.achievements.philanthropist) {
        achievements_count++;
    }
    if (Alice.achievements.big_philanthropist) {
        achievements_count++;
    }
    if (Alice.achievements.educated) {
        achievements_count++;
    }
    if (Alice.achievements.salary_jump) {
        achievements_count++;
    }
    if (Alice.achievements.lucky) {
        achievements_count++;
    }
    if (Alice.achievements.very_lucky) {
        achievements_count++;
    }
    if (Alice.achievements.first_salary) {
        achievements_count++;
    }
    if (Alice.achievements.saver) {
        achievements_count++;
    }
    if (Alice.achievements.big_saver) {
        achievements_count++;
    }
    if (Alice.achievements.work_out) {
        achievements_count++;
    }
    if (Alice.achievements.movie_lover) {
        achievements_count++;
    }
    if (Alice.achievements.traveler) {
        achievements_count++;
    }
    if (Alice.achievements.hobbyist) {
        achievements_count++;
    }
    if (Alice.achievements.lucky_day) {
        achievements_count++;
    }
    if (Alice.achievements.gift_receiver) {
        achievements_count++;
    }
    if (Alice.achievements.fine_payer) {
        achievements_count++;
    }
    if (Alice.achievements.survivor) {
        achievements_count++;
    }
    if (Alice.achievements.ten_years_survivor) {
        achievements_count++;
    }
    
    printf("получено достижений: %d шт\n", achievements_count);
    if (Alice.achievements.ten_years_survivor) {
        printf("супер достижение: ПОБЕГ ИЗ МАТРИЦЫ\n");
    }

    printf("\n");
    printf("НЕДВИЖИМОСТЬ ПОДРОБНО\n");
    printf("состояние квартиры: %d из 10\n", Alice.realty.apartment_condition);
    printf("количество комнат: %d\n", Alice.realty.apartment_rooms);
    printf("этаж: %d\n", Alice.realty.apartment_floor);
    printf("возраст дома: %d лет\n", Alice.realty.apartment_building_age);
    
    if (Alice.realty.has_cottage) {
        printf("дача: стоимость %lld RUB\n", Alice.realty.cottage_value);
        printf("площадь участка: %d соток\n", Alice.realty.cottage_area);
    }
    
    if (Alice.realty.has_commercial) {
        printf("коммерческая недвижимость: %lld RUB\n", Alice.realty.commercial_value);
        printf("доход от аренды: %lld RUB в месяц\n", Alice.realty.commercial_income);
    }
    
    if (Alice.realty.has_second_apartment) {
        printf("вторая квартира: %lld RUB\n", Alice.realty.second_apartment_value);
        printf("доход от аренды: %lld RUB в месяц\n", Alice.realty.second_apartment_rent);
    }
    
    if (Alice.realty.repair_fund > 0) {
        printf("накоплено на ремонт: %lld RUB\n", Alice.realty.repair_fund);
    }
    
    printf("коммунальные платежи в месяц: %lld RUB\n", 
           Alice.realty.utilities_electricity + Alice.realty.utilities_water + 
           Alice.realty.utilities_gas + Alice.realty.utilities_internet);
    
    printf("\n");
}

void alice_yearly_report(const int year, const int years_total, const RUB last_year_capital, const RUB last_year_apartment, const RUB last_year_car, const int last_year_happiness) {
    
    printf("\n");
    printf("ГОДОВОЙ ОТЧЁТ %d\n", years_total);
    printf("\n");
    
    printf("СОСТОЯНИЕ НА КОНЕЦ ГОДА:\n");
    printf("  Капитал: %lld RUB\n", Alice.capital);
    printf("  Стоимость квартиры: %lld RUB\n", Alice.realty.apartment_value);
    printf("  Стоимость машины: %lld RUB\n", Alice.car.value);
    printf("  Уровень счастья: %d / 100\n", Alice.health.happiness);
    
    printf("\nДИНАМИКА ЗА ГОД:\n");
    
    RUB capital_growth = Alice.capital - last_year_capital;
    printf("  Рост капитала: %+lld RUB\n", capital_growth);
    
    RUB apartment_growth = Alice.realty.apartment_value - last_year_apartment;
    printf("  Рост стоимости квартиры: %+lld RUB\n", apartment_growth);
    
    RUB car_growth = Alice.car.value - last_year_car;
    printf("  Рост стоимости машины: %+lld RUB\n", car_growth);
    
    int happiness_change = Alice.health.happiness - last_year_happiness;
    printf("  Изменение счастья: %+d\n", happiness_change);
    
    printf("\nДОПОЛНИТЕЛЬНАЯ ИНФОРМАЦИЯ:\n");
    if (Alice.mortgage.has_mortgage) {
        printf("  Остаток по ипотеке: %lld RUB\n", Alice.mortgage.remaining_balance);
    } else {
        printf("  Ипотека: ПОГАШЕНА\n");
    }
    
    RUB total_assets = Alice.capital + Alice.realty.apartment_value + 
                       Alice.car.value + Alice.invest.stocks + Alice.invest.bonds;
    printf("  Всего активов: %lld RUB\n", total_assets);
    
    if (last_year_capital > 0 && capital_growth != 0) {
        double growth_percent = ((double)Alice.capital / last_year_capital - 1.0) * 100.0;
        printf("  Рост капитала (%%): %+.2f %%\n", growth_percent);
    }
    
    printf("\n");
}

void alice_tax_report(const int year) {
    printf("\n");
    printf("НАЛОГОВЫЙ ОТЧЕТ ЗА %d ГОД\n", year);
    printf("\n");
    
    printf("НАЛОГИ УПЛАЧЕННЫЕ\n");
    printf("налог на доходы физических лиц (НДФЛ): %lld RUB\n", Alice.taxes.income_tax);
    printf("налог на имущество: %lld RUB\n", Alice.taxes.property_tax);
    printf("налог на прирост капитала: %lld RUB\n", Alice.taxes.capital_gains_tax);
    printf("всего уплачено налогов за год: %lld RUB\n", Alice.taxes.total_taxes_paid);
    printf("\n");
    
    printf("НАЛОГОВЫЕ ВЫЧЕТЫ\n");
    printf("возврат налога за обучение: %lld RUB\n", Alice.taxes.tax_refund);
    printf("\n");
    
    printf("СРАВНЕНИЕ С ПРОШЛЫМ ГОДОМ\n");
    static RUB last_year_taxes = 0;
    RUB tax_change = Alice.taxes.total_taxes_paid - last_year_taxes;
    if (last_year_taxes > 0) {
        if (tax_change > 0) {
            printf("налоги увеличились на %lld RUB\n", tax_change);
        } else if (tax_change < 0) {
            printf("налоги уменьшились на %lld RUB\n", -tax_change);
        } else {
            printf("налоги остались на уровне прошлого года\n");
        }
    } else {
        printf("первый год отчётности\n");
    }
    last_year_taxes = Alice.taxes.total_taxes_paid;

    printf("\n");
}

void add_happiness(const int delta) {
    Alice.health.happiness += delta;
    
    if (Alice.health.happiness > 100) {
        Alice.health.happiness = 100;
    }
    if (Alice.health.happiness < 0) {
        Alice.health.happiness = 0;
    }
}

void simulation() {
    int month = 2;
    int year = 2026;
    int years_total = 0;

    RUB last_year_capital = Alice.capital;
    RUB last_year_apartment = Alice.realty.apartment_value;
    RUB last_year_car = Alice.car.value;
    int last_year_happiness = Alice.health.happiness;
    
    printf("\n");
    printf("\nНАЧАЛО СИМУЛЯЦИИ");
    printf("\nстартовый капитал %lld RUB", Alice.capital);
    printf("\nстартовая зарплата %lld RUB", Alice.salary);
    printf("\nинфляция %.1f%% в месяц (%.1f%% в год)", sberbank.inflation_rate, sberbank.inflation_rate * 12);
    printf("\nбанковская ставка %.1f%% годовых", sberbank.deposit_rate);
    printf("\n");
    
    while (years_total < 10) {
        printf("\n\n");
        printf("\nгод %d, месяц %d/%d", years_total + 1, month, year);
        printf("\n");
        
        alice_update_diet();
        alice_food();
        alice_health();
        alice_investments();
        alice_real_estate();
        alice_entertainment();
        alice_random_events();
        alice_car();
        alice_education();
        alice_salary(month, year);
        alice_boat(month, year);
        alice_mortgage_payment();
        alice_charity();
        alice_bank_interest();
        alice_calculate_income_tax();
        alice_calculate_property_tax();
        alice_calculate_capital_gains_tax();
        alice_pay_taxes();
        check_and_award_achievements();
        alice_insurance();
        
        printf("\nкапитал %lld RUB", Alice.capital);
        printf("\nсчастье %d/100", Alice.health.happiness);
        
        ++month;
        if (month == 13) {
            month = 1;
            ++year;
            years_total++;

            alice_yearly_report(year, years_total, last_year_capital, last_year_apartment, last_year_car, last_year_happiness);
            
            last_year_capital = Alice.capital;
            last_year_apartment = Alice.realty.apartment_value;
            last_year_car = Alice.car.value;
            last_year_happiness = Alice.health.happiness;
            
            alice_tax_report(year);
        }
    }

    if (!Alice.achievements.ten_years_survivor) {
        printf("\nСУПЕР достижение \"Побег из матрицы\"\n");
        printf("   Алиса успешно прошла 10 лет финансовой симуляции\n");
        printf("   награда: +50 к счастью (и золотая медаль)\n");
        Alice.achievements.ten_years_survivor = 1;
        add_happiness(50);
    }
    
    print_all_achievements();
}

int main() {
    srand(time(NULL));
    
    alice_init();
    simulation();
    print_results();
    
    return 0;
}
