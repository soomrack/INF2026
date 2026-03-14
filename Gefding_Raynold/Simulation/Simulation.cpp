#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
#include <map>


using RUB = long long int;
using USD = long long int;

using Percent = float;


struct TaxRates {

    RUB ndfl_threshold_1 = 5'000'000;
    Percent ndfl_rate_1 = 13.0;
    Percent ndfl_rate_2 = 15.0;

    std::map<int, float> transport_base_rate;
    Percent transport_rate_per_hp = 2.5;

    Percent transport_age_coef_young = 1.0;
    Percent transport_age_coef_middle = 1.1;
    Percent transport_age_coef_old = 1.2;

    Percent property_tax_rate = 0.1;

    RUB deposit_tax_free_limit = 1'000'000;
    Percent deposit_tax_rate = 13.0;

    RUB social_threshold = 2'000'000;
    Percent social_rate = 30.0;
};

TaxRates global_tax_rates;


struct Bank {
    RUB account; 
    RUB deposite; 
    Percent interest; 

    USD account_usd; 
    float rate_usd_rub; 
};


struct Stock {
    std::string ticker;

    RUB quantity;
    RUB purchase_price;
    RUB current_price;
    Percent dividend_yield;
    int dividend_month;
};


struct Bond {
    std::string issuer;

    RUB face_value;
    RUB quantity;
    RUB purchase_price;
    RUB current_price;
    Percent coupon_rate;
    int coupon_months[12];
    RUB years_to_maturity;
};


struct ETF {
    std::string name;

    RUB quantity;
    RUB purchase_price;
    RUB current_price;
    Percent avg_dividend;
};

struct InvestmentPortfolio {
    std::vector<Stock> stocks;
    std::vector<Bond> bonds;
    std::vector<ETF> etfs;

    RUB management_fee;
    RUB brokerage_commission;

    RUB total_purchase_value;
    RUB total_current_value;
    RUB yearly_dividend_income;
};


struct Car {
    RUB gas; 
    RUB value;
    RUB horsepower;
    RUB manufacture_year;
};


struct Housing {
    RUB rent;
    RUB housingservices;
    RUB value;
    RUB cadastral_value;
};


struct Loan {
    RUB principal;
    RUB remaining;
    Percent rate;
    RUB months_left;
    RUB monthly_payment;
};


struct Pet {
    RUB food; 
    RUB health; 
    RUB toilet; 
    RUB toys;
};


struct RandomEvent {
    std::string name;
    std::string description;
    RUB min_impact;
    RUB max_impact;
    Percent probability;
    bool affects_all;
    std::string required_profession;
    RUB min_age;
    RUB max_age;
};


struct LifeEvent {
    std::string event_name;
    int month;
    int year;
    RUB financial_impact;
    std::string description;
};

struct EventHistory {
    std::vector<LifeEvent> events;
    RUB total_impact_from_events;
    RUB positive_events_count;
    RUB negative_events_count;
};


struct Person {
    std::string name;
    std::string region;

    int age;
    std::string profession;
    RUB work_experience;
    RUB health_status;
    RUB happiness;
    EventHistory event_history;
    bool is_alive;

    Bank vtb;

    InvestmentPortfolio investments;

    Housing home;

    Car car;
    RUB socialtransport;

    RUB salary;

    RUB food;
    RUB telecom;
    RUB healthinsurance;

    Pet pet;

    std::vector<Loan> loans;

    RUB yearly_income;
    RUB yearly_deposit_interest;
    int current_year;
};



struct Person alice;

struct Person bob;

void print_event_history(Person& p);


RUB calculate_income_tax(RUB monthly_income, Person& p, int month) {

    p.yearly_income += monthly_income;

    Percent rate = global_tax_rates.ndfl_rate_1;
    if (p.yearly_income > global_tax_rates.ndfl_threshold_1) {
        rate = global_tax_rates.ndfl_rate_2;
    }

    RUB tax = (RUB)(monthly_income * rate / 100.0);

    if (month == 12) {
        p.yearly_income = 0;
    }

    return tax;
}


void person_salary(Person &p, const int month, const int year)
{

    if (month == 12) {
        p.vtb.account += p.salary;  // 13rd salary
    }


    if (p.name == "Alice" && month == 1 && year == 2027) {
        p.salary *= 1.5;
    }
    if (p.name == "Bob" && month == 1 && year == 2028) { 
        p.salary *= 1.3;
    }

    
    RUB income_tax = calculate_income_tax(p.salary, p, month);
    p.vtb.account += p.salary - income_tax;
}


void person_expences(Person &p)
{
    p.vtb.account -= p.food;
    p.vtb.account -= p.telecom;
    p.vtb.account -= p.socialtransport;
}

void person_insurance(Person &p)
{
    p.vtb.account -= p.healthinsurance;
}


void person_pet(Person &p)
{
    p.vtb.account -= p.pet.food;
    p.vtb.account -= p.pet.health;
    p.vtb.account -= p.pet.toilet;
    p.vtb.account -= p.pet.toys;
}


RUB calculate_property_tax(const Housing& home, const Person& p, int current_year) {
    if (home.cadastral_value <= 0) return 0;

    Percent rate = global_tax_rates.property_tax_rate / 100.0;
    RUB annual_tax = (RUB)(home.cadastral_value * rate);
    return annual_tax / 12;
}


void person_home(Person &p, int current_year)
{
    p.vtb.account -= p.home.housingservices;
    if (p.home.rent > 0) {
        p.vtb.account -= p.home.rent;
    }

    RUB property_tax = calculate_property_tax(p.home, p, current_year);
    p.vtb.account -= property_tax;
}


int car_age(const Car& car, int current_year) {
    return current_year - car.manufacture_year;
}


float regional_coefficient(const std::string& region) {
    if (region == "Moscow") return 2.0;
    if (region == "SPb") return 1.8;
    return 1.0;
}


RUB calculate_transport_tax(const Car& car, const Person& p, int current_year) {
    if (car.horsepower <= 0) return 0;

    Percent base = global_tax_rates.transport_rate_per_hp;
    Percent regional = regional_coefficient(p.region);

    int age = car_age(car, current_year);
    float age_coef;
    if (age <= 3) age_coef = global_tax_rates.transport_age_coef_young;
    else if (age <= 10) age_coef = global_tax_rates.transport_age_coef_middle;
    else age_coef = global_tax_rates.transport_age_coef_old;


    RUB annual_tax = (RUB)(car.horsepower * base * regional * age_coef);

    return annual_tax / 12;
}


void person_car(Person &p, int current_year)
{
    p.vtb.account -= p.car.gas;

    RUB tax = calculate_transport_tax(p.car, p, current_year);
    p.vtb.account -= tax;
}

void person_freelance(Person &p, const int month, const int year)
{
    RUB freelance_income = 0;
    if (month == 3 and year == 2027) {
        p.vtb.account_usd += 3'000;
        freelance_income = 3'000 * p.vtb.rate_usd_rub;
    }
    if (p.name == "Bob" && month % 6 == 0) {
        p.vtb.account += 5'000;
        freelance_income = 5'000 * p.vtb.rate_usd_rub;
    }

    if (freelance_income > 0) {
        RUB tax = calculate_income_tax(freelance_income, p, month);
        p.vtb.account -= tax;
    }
}


RUB calculate_deposit_tax(RUB interest_earned, Person& p, int month) {

    p.yearly_deposit_interest += interest_earned;

    RUB tax = (RUB)(interest_earned * global_tax_rates.deposit_tax_rate / 100.0);

    if (month == 12) {
        p.yearly_deposit_interest = 0;
    }

    return tax;
}


void person_deposite(Person &p, const int month, const int year)
{
    if (year == 2026) p.vtb.interest = 14.5;
    if (year == 2027) p.vtb.interest = 13.5;
    if (year == 2028) p.vtb.interest = 12.5;
    if (year == 2029) p.vtb.interest = 11.5;

    RUB interest_earned = (RUB)(p.vtb.deposite * (p.vtb.interest / 12.0 / 100.0));
    p.vtb.deposite += interest_earned;

    RUB deposit_tax = calculate_deposit_tax(interest_earned, p, month);

    p.vtb.deposite -= deposit_tax;

    p.vtb.deposite += p.vtb.account;
    p.vtb.account = 0;
}


RUB calculate_annuity_payment(RUB principal, Percent rate_percent, RUB months)
{
    double monthly_rate = rate_percent / 100.0 / 12.0;

    double factor = monthly_rate * pow(1 + monthly_rate, months) / (pow(1 + monthly_rate, months) - 1);

    return (RUB)(principal * factor);
}


void person_loans(Person& p) {
    for (auto& loan : p.loans) {
        if (loan.months_left <= 0) continue;

        if (p.vtb.account >= loan.monthly_payment) {
            p.vtb.account -= loan.monthly_payment;
        }
        else {
            p.vtb.deposite -= loan.monthly_payment;
        }

        Percent monthly_rate = loan.rate / 100 / 12;
        RUB interest = (RUB)(loan.remaining * monthly_rate);
        RUB principal_part = loan.monthly_payment - interest;

        loan.remaining -= principal_part;
        if (loan.remaining < 0) loan.remaining = 0;

        loan.months_left--;
    }
}


void investment_init(Person& p) {
    if (p.name == "Alice") {
        Stock sber;
        sber.ticker = "SBER";
        sber.quantity = 100;
        sber.purchase_price = 250;
        sber.current_price = 250;
        sber.dividend_yield = 8.5;
        sber.dividend_month = 7;
        p.investments.stocks.push_back(sber);

        Stock gazp;
        gazp.ticker = "GAZP";
        gazp.quantity = 50;
        gazp.purchase_price = 350;
        gazp.current_price = 350;
        gazp.dividend_yield = 7.2;
        gazp.dividend_month = 10;
        p.investments.stocks.push_back(gazp);

        Bond ofz;
        ofz.issuer = "OFZ 26238";
        ofz.face_value = 1000;
        ofz.quantity = 200;
        ofz.purchase_price = 980;
        ofz.current_price = 980;
        ofz.coupon_rate = 7.5;

        ofz.coupon_months[0] = 3;
        ofz.coupon_months[1] = 9;
        ofz.years_to_maturity = 5;
        p.investments.bonds.push_back(ofz);

        p.investments.management_fee = 0;
        p.investments.brokerage_commission = 0.05;
    }

    if (p.name == "Bob") {
        ETF fxru;
        fxru.name = "FXRU";
        fxru.quantity = 500;
        fxru.purchase_price = 900;
        fxru.current_price = 900;
        fxru.avg_dividend = 4.5;
        p.investments.etfs.push_back(fxru);

        p.investments.management_fee = 0;
        p.investments.brokerage_commission = 0.05;
    }

    p.investments.total_purchase_value = 0;
    p.investments.total_current_value = 0;
    p.investments.yearly_dividend_income = 0;
}


// инициализация персон
void alice_init(Person &p)
{
    p.name = "Alice";
    p.region = "Moscow";

    p.age = 30;
    p.profession = "IT specialist";
    p.work_experience = 8 * 12;
    p.health_status = 90;
    p.happiness = 80;
    p.is_alive = true;
    p.event_history = EventHistory();

    p.vtb.account = 0;
    p.vtb.deposite = 1'000'000;
    p.vtb.interest = 14.5;
    p.salary = 180'000;

    p.vtb.account_usd = 1'000;
    p.vtb.rate_usd_rub = 78.5;

    p.home.value = 0;
    p.home.cadastral_value = 0;
    p.home.rent = 30'000;
    p.home.housingservices = 10'000;

    p.food = 20'000;
    p.telecom = 1'000;
    p.healthinsurance = 20'000;

    p.car.value = 2'400'000;
    p.car.gas = 15'000;
    p.car.horsepower = 150;
    p.car.manufacture_year = 2022;

    p.socialtransport = 0;

    p.pet.food = 5'000;
    p.pet.health = 5'000;
    p.pet.toilet = 5'000;
    p.pet.toys = 5'000;

    p.loans.clear();

    p.yearly_income = 0;
    p.yearly_deposit_interest = 0;

    investment_init(p);
}


void bob_init(Person &p)
{
    p.name = "Bob";
    p.region = "SPb";

    p.age = 28;
    p.profession = "Engineer";
    p.work_experience = 5 * 12;
    p.health_status = 85;
    p.happiness = 70;
    p.is_alive = true;
    p.event_history = EventHistory();

    p.vtb.account = 0;
    p.vtb.deposite = 100'000;
    p.vtb.interest = 14.5;
    p.salary = 120'000;

    p.vtb.account_usd = 5'000;
    p.vtb.rate_usd_rub = 78.5;

    p.home.value = 8'000'000;
    p.home.cadastral_value = 7'500'000;
    p.home.rent = 0;
    p.home.housingservices = 8'000;

    p.food = 25'000;
    p.telecom = 1'500;
    p.healthinsurance = 15'000;

    p.car.value = 0;
    p.car.gas = 0;
    p.car.horsepower = 0;
    p.car.manufacture_year = 0;

    p.socialtransport = 3'000;

    p.pet.food = 0;
    p.pet.health = 0;
    p.pet.toilet = 0;
    p.pet.toys = 0;

    Loan mortgage;
    mortgage.principal = 8'000'000;
    mortgage.remaining = 8'000'000;
    mortgage.rate = 9.5;
    mortgage.months_left = 240;
    mortgage.monthly_payment = calculate_annuity_payment(
        mortgage.principal, 
        mortgage.rate, 
        mortgage.months_left
    );

    p.loans.clear();
    p.loans.push_back(mortgage);
    
    p.yearly_income = 0;
    p.yearly_deposit_interest = 0;

    investment_init(p);
}


void update_investment_prices(Person& p, int year) {
    for (auto& stock : p.investments.stocks) {
        if (year % 2 == 0) {
            double change = (rand() % 40 - 20) / 100.0; // -20% .. +20%
            stock.current_price = (RUB)(stock.current_price * (1 + change));
            if (stock.current_price < 1) stock.current_price = 1;
        }
    }

    for (auto& bond : p.investments.bonds) {
        double change = (rand() % 20 - 10) / 100.0; // -10% .. +10%
        bond.current_price = (RUB)(bond.current_price * (1 + change));
        if (bond.current_price < bond.face_value * 0.5)
            bond.current_price = bond.face_value * 0.5;
    }

    for (auto& etf : p.investments.etfs) {
        double change = (rand() % 30 - 15) / 100.0; // -15% .. +15%
        etf.current_price = (RUB)(etf.current_price * (1 + change));
        if (etf.current_price < 1) etf.current_price = 1;
    }
}


void calculate_investment_value(Person& p) {
    p.investments.total_current_value = 0;
    p.investments.total_purchase_value = 0;

    for (const auto& stock : p.investments.stocks) {
        p.investments.total_current_value += stock.quantity * stock.current_price;
        p.investments.total_purchase_value += stock.quantity * stock.purchase_price;
    }

    for (const auto& bond : p.investments.bonds) {
        p.investments.total_current_value += bond.quantity * bond.current_price;
        p.investments.total_purchase_value += bond.quantity * bond.purchase_price;
    }

    for (const auto& etf : p.investments.etfs) {
        p.investments.total_current_value += etf.quantity * etf.current_price;
        p.investments.total_purchase_value += etf.quantity * etf.purchase_price;
    }
}


void process_dividends(Person& p, int month, int year) {
    RUB dividend_income = 0;

    // Дивиденды по акциям
    for (auto& stock : p.investments.stocks) {
        if (stock.dividend_month == month) {
            RUB dividend = (RUB)(stock.quantity * stock.current_price *
                stock.dividend_yield / 100.0);
            dividend_income += dividend;
            printf("  %s received dividends on %s: %lld RUB\n",
                p.name.c_str(), stock.ticker.c_str(), dividend);
        }
    }

    // Купоны по облигациям
    for (auto& bond : p.investments.bonds) {
        for (int i = 0; i < 12; i++) {
            if (bond.coupon_months[i] == month) {
                RUB coupon = (RUB)(bond.quantity * bond.face_value *
                    bond.coupon_rate / 100.0 / 12);
                dividend_income += coupon;
                printf("  %s received a coupon for %s: %lld RUB\n",
                    p.name.c_str(), bond.issuer.c_str(), coupon);
            }
        }
    }

    // Дивиденды по ETF
    for (auto& etf : p.investments.etfs) {
        if (month % 3 == 0) {
            RUB dividend = (RUB)(etf.quantity * etf.current_price *
                etf.avg_dividend / 100.0 / 4);
            dividend_income += dividend;
            printf("  %s received dividends on %s: %lld RUB\n",
                p.name.c_str(), etf.name.c_str(), dividend);
        }
    }

    if (dividend_income > 0) {
        p.vtb.account += dividend_income;
        p.investments.yearly_dividend_income += dividend_income;

        RUB dividend_tax = (RUB)(dividend_income * 13.0 / 100.0);
        p.vtb.account -= dividend_tax;
        printf("  Tax on dividends: %lld RUB\n", dividend_tax);
    }
}


void person_investments(Person& p, int month, int year) {
    if (month == 1) {
        update_investment_prices(p, year);
        calculate_investment_value(p);
    }

    process_dividends(p, month, year);

    if (p.name == "Alice" && month == 12) {
        RUB to_invest = p.investments.yearly_dividend_income / 2;
        if (to_invest > 10000) {
            for (auto& stock : p.investments.stocks) {
                if (stock.ticker == "SBER") {
                    RUB price = stock.current_price;
                    RUB commission = (RUB)(to_invest * p.investments.brokerage_commission / 100.0);
                    RUB net_invest = to_invest - commission;
                    RUB new_quantity = net_invest / price;
                    stock.quantity += new_quantity;
                    printf("  %s reinvested %lld RUB in %s, purchased %lld things.\n",
                        p.name.c_str(), net_invest, stock.ticker.c_str(), new_quantity);
                    break;
                }
            }
        }
        p.investments.yearly_dividend_income = 0;
    }
}



void print_person_results(Person &p)
{
    printf("\n========================================\n");
    printf("=== %s ===\n", p.name.c_str());
    printf("Age: %d лет\n", p.age);
    printf("Profession: %s\n", p.profession.c_str());
    printf("Work experience: %lld months\n", p.work_experience);
    printf("Health: %lld%%\n", p.health_status);
    printf("Happiness: %lld%%\n", p.happiness);
    printf("Status: %s\n", p.is_alive ? "Alive" : "Dead");

    calculate_investment_value(p);

    RUB capital = 0;
    capital += p.vtb.account;
    capital += p.car.value;
    capital += p.home.value;
    capital += p.vtb.deposite;
    capital += p.vtb.account_usd * p.vtb.rate_usd_rub;
    capital += p.investments.total_current_value;

    for (const auto& loan : p.loans){
        capital -= loan.remaining;
    }

    printf("Liquid assets (bank+deposits+investments): %lld RUB\n",
        p.vtb.account + p.vtb.deposite + p.investments.total_current_value);
    printf("Capital = %lld RUB\n", capital);

    if (!p.investments.stocks.empty() || !p.investments.bonds.empty() || !p.investments.etfs.empty()) {
        printf("\nInvestment Portfolio:\n");
        printf("  Stocks: %lld RUB (%lld items)\n",
            p.investments.total_current_value -
            (p.investments.bonds.size() > 0 ? p.investments.bonds[0].quantity * p.investments.bonds[0].current_price : 0) -
            (p.investments.etfs.size() > 0 ? p.investments.etfs[0].quantity * p.investments.etfs[0].current_price : 0),
            p.investments.stocks.size());
        printf("  Bonds: %lld RUB\n",
            p.investments.bonds.size() > 0 ? p.investments.bonds[0].quantity * p.investments.bonds[0].current_price : 0);
        printf("  ETFs: %lld RUB\n",
            p.investments.etfs.size() > 0 ? p.investments.etfs[0].quantity * p.investments.etfs[0].current_price : 0);
        printf("  Profit/Loss: %lld RUB\n",
            p.investments.total_current_value - p.investments.total_purchase_value);
    }

    print_event_history(p);
}



class EventManager {
private:
    std::vector<RandomEvent> possible_events;

public:
    EventManager() {
        // Medicine
        possible_events.push_back({
            "Illness",
            "Got sick and had to buy medicine",
            -50000, -5000, 0.08, false, "", 0, 100
            });
        possible_events.push_back({
            "Hospitalization",
            "Serious illness with hospitalization",
            -200000, -50000, 0.02, false, "", 0, 100
            });
        possible_events.push_back({
            "Dentist",
            "Dental problems",
            -30000, -10000, 0.05, false, "", 0, 100
            });

        // Career
        possible_events.push_back({
            "Bonus",
            "Received unexpected bonus at work",
            50000, 200000, 0.06, false, "", 0, 100
            });
        possible_events.push_back({
            "Promotion",
            "Got promoted",
            300000, 500000, 0.01, false, "", 25, 100
            });
        possible_events.push_back({
            "Layoff",
            "Lost job",
            -500000, 0, 0.03, false, "", 0, 100
            });
        possible_events.push_back({
            "New Project",
            "Participated in profitable project",
            100000, 300000, 0.04, false, "", 0, 100
            });

        // Family
        possible_events.push_back({
            "Wedding",
            "Got married (wedding expenses)",
            -500000, -200000, 0.005, false, "", 25, 100
            });
        possible_events.push_back({
            "Child",
            "Child birth",
            -100000, 0, 0.008, false, "", 25, 45
            });
        possible_events.push_back({
            "Divorce",
            "Divorce (lost half of property)",
            -2000000, -500000, 0.003, false, "", 30, 100
            });

        // Car
        possible_events.push_back({
            "Accident",
            "Car accident (need repairs)",
            -150000, -30000, 0.02, false, "", 0, 100
            });
        possible_events.push_back({
            "Fine",
            "Traffic fine",
            -5000, -500, 0.1, false, "", 0, 100
            });
        possible_events.push_back({
            "Car Breakdown",
            "Serious car breakdown",
            -80000, -20000, 0.04, false, "", 0, 100
            });

        // Housing
        possible_events.push_back({
            "Flood",
            "Flooded neighbors (repairs + compensation)",
            -100000, -20000, 0.01, false, "", 0, 100
            });
        possible_events.push_back({
            "Burglary",
            "Apartment burglary",
            -300000, -50000, 0.005, false, "", 0, 100
            });
        possible_events.push_back({
            "Lottery Win",
            "Unexpected lottery win",
            10000, 500000, 0.001, false, "", 0, 100
            });

        // Environment
        possible_events.push_back({
            "Hurricane",
            "Hurricane damaged property",
            -200000, -50000, 0.002, true, "", 0, 100
            });
        possible_events.push_back({
            "Flood",
            "Regional flood",
            -300000, -100000, 0.001, true, "", 0, 100
            });

        // Financial
        possible_events.push_back({
            "Bank Bankruptcy",
            "Bank went bankrupt (lost part of deposit)",
            -500000, -10000, 0.001, false, "", 0, 100
            });
        possible_events.push_back({
            "Crisis",
            "Economic crisis (job loss/income reduction)",
            -1000000, -200000, 0.02, true, "", 0, 100
            });
        possible_events.push_back({
            "Boom",
            "Economic boom (additional income)",
            200000, 800000, 0.02, true, "", 0, 100
            });

        // Presents
        possible_events.push_back({
            "Inheritance",
            "Received inheritance from distant relative",
            100000, 2000000, 0.001, false, "", 30, 100
            });
        possible_events.push_back({
            "Gift",
            "Expensive gift from relatives",
            10000, 100000, 0.03, false, "", 0, 100
            });
    }

    std::vector<RandomEvent> getPossibleEvents() const {
        return possible_events;
    }

    RUB calculateImpact(const RandomEvent& event) {
        return event.min_impact + (rand() % (event.max_impact - event.min_impact + 1));
    }
};



EventManager eventManager;


void process_random_event(Person& p, int month, int year) {
    if (!p.is_alive) return;

    double event_chance = (rand() % 10000) / 10000.0;

    auto events = eventManager.getPossibleEvents();

    for (const auto& event : events) {
        if (event_chance > event.probability) continue;

        if (p.age < event.min_age || p.age > event.max_age) continue;

        if (!event.required_profession.empty() &&
            event.required_profession != p.profession) continue;

        RUB impact = eventManager.calculateImpact(event);

        if (impact > 0) {
            p.vtb.account += impact;
            p.event_history.positive_events_count++;
        }
        else {
            RUB total_liquidity = p.vtb.account + p.vtb.deposite;
            if (total_liquidity < -impact) {
                printf("\nCRITICAL SITUATION for %s: %s\n",
                    p.name.c_str(), event.description.c_str());
                printf("   Need: %lld RUB, but have only %lld RUB\n",
                    -impact, total_liquidity);

                if (p.car.value > 0) {
                    printf("   Sell car for %lld RUB\n", p.car.value);
                    p.vtb.account += p.car.value;
                    p.car.value = 0;
                    p.car.gas = 0;
                }

                if (-impact > p.vtb.account) {
                    RUB needed = -impact - p.vtb.account;
                    if (p.vtb.deposite >= needed) {
                        p.vtb.deposite -= needed;
                        p.vtb.account += needed;
                    }
                    else {
                        if (-impact > total_liquidity * 10) {
                            printf("%s Died after random event!\n", p.name.c_str());
                            p.is_alive = false;
                            return;
                        }
                    }
                }
            }
            p.vtb.account += impact;
            p.event_history.negative_events_count++;
        }

        LifeEvent lifeEvent;
        lifeEvent.event_name = event.name;
        lifeEvent.month = month;
        lifeEvent.year = year;
        lifeEvent.financial_impact = impact;
        lifeEvent.description = event.description;
        p.event_history.events.push_back(lifeEvent);
        p.event_history.total_impact_from_events += impact;

        if (event.name == "Illness" || event.name == "Hospitalization") {
            p.health_status -= 10 + (rand() % 30);
            if (p.health_status < 0) p.health_status = 0;
        }
        if (event.name == "Wedding" || event.name == "Child") {
            p.happiness += 20;
            if (p.happiness > 100) p.happiness = 100;
        }
        if (event.name == "Divorce" || event.name == "Layoff") {
            p.happiness -= 30;
            if (p.happiness < 0) p.happiness = 0;
        }

        printf("\nEvent for %s (%d/%d): %s\n",
            p.name.c_str(), month, year, event.name.c_str());
        printf("   %s\n", event.description.c_str());
        printf("   Financial effect: %lld RUB\n", impact);
        if (p.health_status < 100)
            printf("   Health: %lld%%\n", p.health_status);
        if (p.happiness < 100)
            printf("   Happiness: %lld%%\n", p.happiness);

        break;
    }
}


void update_person_stats(Person& p, int month) {
    if (month == 1) {
        p.age++;
    }

    if (p.salary > 0) {
        p.work_experience++;
    }

    if (p.health_status < 100 && rand() % 100 < 30) {
        p.health_status += 1;
        if (p.health_status > 100) p.health_status = 100;
    }

    if (p.happiness < 50 && rand() % 100 < 20) {
        p.happiness += 1;
    }
    if (p.happiness > 50 && rand() % 100 < 20) {
        p.happiness -= 1;
    }
}


void person_healthcare(Person& p, int month) {
    RUB health_cost = 0;

    if (month == 6) {
        health_cost += 5000;
        printf("  %s get disparization: -5000 RUB\n", p.name.c_str());
    }

    if (p.health_status < 70) {
        health_cost += (100 - p.health_status) * 1000;
        p.vtb.account -= health_cost;
        printf("  %s healing: -%lld RUB (health %lld%%)\n",
            p.name.c_str(), health_cost, p.health_status);
    }
}


void calculate_pension(Person& p, int year) {
    if (p.age >= 65 && p.salary > 0) {
        printf("\n%s get pension in %d году\n", p.name.c_str(), year);
        RUB pension = p.work_experience * 1000;
        p.salary = pension;
    }
}

void print_event_history(Person& p) {
    printf("\nEvent chronos %s:\n", p.name.c_str());
    printf("   Event count: %lld\n", p.event_history.events.size());
    printf("   Positive: %lld\n", p.event_history.positive_events_count);
    printf("   Negative: %lld\n", p.event_history.negative_events_count);
    printf("   Full financial effect: %lld RUB\n", p.event_history.total_impact_from_events);

    if (!p.event_history.events.empty()) {
        printf("\n   Last 5 events:\n");
        int start = p.event_history.events.size() > 5 ?
            p.event_history.events.size() - 5 : 0;
        for (size_t i = start; i < p.event_history.events.size(); i++) {
            printf("   %d/%d: %-20s (%lld RUB)\n",
                p.event_history.events[i].month,
                p.event_history.events[i].year,
                p.event_history.events[i].event_name.c_str(),
                p.event_history.events[i].financial_impact);
        }
    }
}



void simulation(Person &p)
{
    int month = 2;
    int year = 2026;

    while (not (month == 3 and year == 2050)) {
        if (!p.is_alive) {
            printf("\n%s dead in %d/%d\n", p.name.c_str(), month, year);
            break;
        }


        person_salary(p, month, year);
        person_freelance(p, month, year);
        person_expences(p);
        person_car(p, year);
        person_pet(p);
        person_insurance(p);
        person_home(p, year);
        person_loans(p);
        person_investments(p, month, year);
        person_healthcare(p, month);
        process_random_event(p, month, year);
        update_person_stats(p, month);
        calculate_pension(p, year);
        person_deposite(p, month, year);


        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    alice_init(alice);
    bob_init(bob);

    simulation(alice);
    simulation(bob);

    print_person_results(alice);
    print_person_results(bob);
}