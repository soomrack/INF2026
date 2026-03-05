#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using RUB = float;
using EUR = float;
using USD = float;
using Percent = float;

RUB inflation = 0.085;
int current_month = 1;
int current_year = 2024;
int simulation_months = 36;

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
};

struct RealEstate {
    RUB apartment_value;
    RUB house_value;
    RUB land_value;
    RUB rent_income;
    RUB mortgage_payment;
    RUB mortgage_debt;
    Percent mortgage_rate;
    int mortgage_term;
    RUB property_tax;
    RUB utilities;
    RUB repairs;
};

struct Vehicle {
    RUB car1_value;
    RUB car2_value;
    RUB motorcycle_value;
    RUB gas_monthly;
    RUB insurance;
    RUB tax;
    RUB maintenance;
    RUB parking;
    RUB fines;
    RUB loan_payment;
    RUB loan_debt;
};

struct Investments {
    RUB stocks;
    RUB bonds;
    RUB crypto;
    RUB gold;
    RUB business_share;
    RUB p2p_lending;
    RUB investment_fund;
    RUB dividends_monthly;
};

struct Education {
    RUB student_loan;
    RUB courses;
    RUB books;
    RUB seminars;
    RUB online_subscriptions;
    RUB children_education;
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
};

struct Clothing {
    RUB everyday;
    RUB work;
    RUB sport;
    RUB seasonal;
    RUB shoes;
    RUB accessories;
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
};

struct Person {
    std::string name;
    RUB salary;
    RUB passive_income;
    RUB bonus;
    RUB side_hustle;

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

    RUB total_assets;
    RUB total_debts;
    RUB net_worth;

    int age;
    bool has_child;
    int children_count;
    bool married;
    std::string partner_name;
};

Person david, lisa;

void init_david() {
    david.name = "David";
    david.salary = 300000;
    david.passive_income = 15000;
    david.bonus = 50000;
    david.side_hustle = 20000;

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

    david.realty.apartment_value = 8000000;
    david.realty.house_value = 0;
    david.realty.land_value = 0;
    david.realty.rent_income = 40000;
    david.realty.mortgage_payment = 0;
    david.realty.mortgage_debt = 0;
    david.realty.property_tax = 8000;
    david.realty.utilities = 12000;
    david.realty.repairs = 5000;

    david.transport.car1_value = 2500000;
    david.transport.car2_value = 0;
    david.transport.gas_monthly = 15000;
    david.transport.insurance = 8000;
    david.transport.tax = 3000;
    david.transport.maintenance = 5000;
    david.transport.parking = 3000;
    david.transport.fines = 0;

    david.invest.stocks = 300000;
    david.invest.bonds = 200000;
    david.invest.crypto = 50000;
    david.invest.gold = 100000;
    david.invest.business_share = 200000;
    david.invest.dividends_monthly = 15000;

    david.age = 32;
    david.has_child = false;
    david.married = true;
    david.partner_name = "Lisa";
}

void init_lisa() {
    lisa.name = "Lisa";
    lisa.salary = 100000;
    lisa.passive_income = 0;
    lisa.bonus = 10000;
    lisa.side_hustle = 5000;

    lisa.bank.checking = 25000;
    lisa.bank.savings = 50000;
    lisa.bank.deposite = 0;
    lisa.bank.interest = 12.0;
    lisa.bank.credit_card_debt = 150000;
    lisa.bank.credit_limit = 300000;
    lisa.bank.credit_used = 150000;
    lisa.bank.eur_account = 200;
    lisa.bank.eur_rate = 95.0;

    lisa.realty.apartment_value = 0;
    lisa.realty.rent_income = 0;
    lisa.realty.mortgage_payment = 45000;
    lisa.realty.mortgage_debt = 3500000;
    lisa.realty.mortgage_rate = 12.5;
    lisa.realty.mortgage_term = 240;
    lisa.realty.utilities = 8000;

    lisa.transport.car1_value = 800000;
    lisa.transport.gas_monthly = 8000;
    lisa.transport.insurance = 5000;
    lisa.transport.tax = 2000;
    lisa.transport.maintenance = 3000;
    lisa.transport.loan_payment = 15000;
    lisa.transport.loan_debt = 300000;

    lisa.invest.crypto = 10000;
    lisa.invest.gold = 15000;

    lisa.edu.student_loan = 400000;

    lisa.age = 28;
    lisa.has_child = false;
    lisa.married = true;
    lisa.partner_name = "David";
}

void apply_inflation() {
    david.salary *= (1 + inflation / 12);
    lisa.salary *= (1 + inflation / 12);
    david.realty.apartment_value *= (1 + inflation / 12 / 2);
    david.transport.gas_monthly *= (1 + inflation / 12);
    lisa.transport.gas_monthly *= (1 + inflation / 12);
    david.food.groceries *= (1 + inflation / 12);
    lisa.food.groceries *= (1 + inflation / 12);
}

void david_monthly_income() {
    david.bank.checking += david.salary;
    david.bank.checking += david.passive_income;
    david.bank.checking += david.side_hustle;
    david.bank.savings += david.bank.savings * (david.bank.interest / 100 / 12);
    david.bank.deposite += david.bank.deposite * (david.bank.interest / 100 / 12);
    david.bank.checking += david.invest.dividends_monthly;
    david.bank.checking += david.realty.rent_income;
}

void lisa_monthly_income() {
    lisa.bank.checking += lisa.salary;
    lisa.bank.checking += lisa.side_hustle;
    lisa.bank.savings += lisa.bank.savings * (lisa.bank.interest / 100 / 12);
}

void david_monthly_expenses() {
    david.bank.checking -= david.realty.property_tax / 12;
    david.bank.checking -= david.realty.utilities;
    david.bank.checking -= david.realty.repairs;
    david.bank.checking -= david.transport.gas_monthly;
    david.bank.checking -= david.transport.insurance;
    david.bank.checking -= david.transport.tax / 12;
    david.bank.checking -= david.transport.maintenance;
    david.bank.checking -= david.transport.parking;

    david.food.groceries = 40000;
    david.food.restaurant = 15000;
    david.food.coffee = 5000;
    david.bank.checking -= (david.food.groceries + david.food.restaurant + david.food.coffee);

    david.fun.travel = 30000;
    david.fun.hobbies = 10000;
    david.fun.streaming = 2000;
    david.fun.sports = 5000;
    david.bank.checking -= (david.fun.travel + david.fun.hobbies + david.fun.streaming + david.fun.sports);

    david.health.gym = 5000;
    david.health.vitamins = 3000;
    david.bank.checking -= (david.health.gym + david.health.vitamins);

    if (current_month % 3 == 0) {
        david.bank.checking -= 30000;
        david.clothes.everyday = 30000;
    }

    if (current_month == 12) {
        david.bank.checking -= 100000;
        david.fun.vacation = 100000;
    }
}

void lisa_monthly_expenses() {
    lisa.bank.checking -= lisa.realty.mortgage_payment;
    lisa.bank.checking -= lisa.realty.utilities;
    lisa.bank.checking -= lisa.transport.gas_monthly;
    lisa.bank.checking -= lisa.transport.insurance;
    lisa.bank.checking -= lisa.transport.loan_payment;

    lisa.bank.credit_card_debt += lisa.bank.credit_card_debt * 0.02;
    lisa.bank.credit_used = lisa.bank.credit_card_debt;

    lisa.food.groceries = 25000;
    lisa.food.restaurant = 20000;
    lisa.food.delivery = 8000;
    lisa.food.coffee = 4000;
    lisa.bank.checking -= (lisa.food.groceries + lisa.food.restaurant + lisa.food.delivery + lisa.food.coffee);

    lisa.fun.cinema = 3000;
    lisa.fun.concerts = 5000;
    lisa.fun.gaming = 2000;
    lisa.fun.streaming = 1500;
    lisa.bank.checking -= (lisa.fun.cinema + lisa.fun.concerts + lisa.fun.gaming + lisa.fun.streaming);

    lisa.health.doctors = 2000;
    lisa.health.dentistry = 3000;
    lisa.health.gym = 4000;
    lisa.bank.checking -= (lisa.health.doctors + lisa.health.dentistry + lisa.health.gym);

    if (current_month % 2 == 0) {
        lisa.bank.checking -= 15000;
        lisa.clothes.everyday = 15000;
    }

    if (lisa.bank.checking < 0) {
        lisa.bank.credit_card_debt += abs(lisa.bank.checking);
        lisa.bank.credit_used = lisa.bank.credit_card_debt;
        lisa.bank.checking = 0;
    }
}

void david_invest() {
    if (david.bank.checking > 200000) {
        RUB invest_amount = david.bank.checking * 0.3;
        david.invest.stocks += invest_amount * 0.5;
        david.invest.bonds += invest_amount * 0.3;
        david.invest.gold += invest_amount * 0.2;
        david.bank.checking -= invest_amount;
    }

    if (rand() % 100 < 30) {
        david.invest.crypto += david.invest.crypto * 0.05;
    }
    else {
        david.invest.crypto -= david.invest.crypto * 0.02;
    }

    david.invest.stocks += david.invest.stocks * 0.01;
    david.invest.bonds += david.invest.bonds * 0.005;
    david.invest.gold += david.invest.gold * 0.008;
}

void lisa_borrow() {
    if (lisa.bank.checking < 10000 && lisa.bank.credit_used < lisa.bank.credit_limit) {
        RUB borrow = 30000;
        if (lisa.bank.credit_used + borrow <= lisa.bank.credit_limit) {
            lisa.bank.credit_card_debt += borrow;
            lisa.bank.credit_used = lisa.bank.credit_card_debt;
            lisa.bank.checking += borrow;
        }
    }
}

void random_events(Person& p, bool is_david) {
    int event = rand() % 100;

    if (event < 5) {
        if (is_david) {
            p.bank.checking += 50000;
        }
        else {
            p.bank.checking += 15000;
        }
    }
    else if (event < 10) {
        if (is_david) {
            p.transport.fines = 3000;
            p.bank.checking -= 3000;
        }
        else {
            p.transport.fines = 1500;
            p.bank.checking -= 1500;
        }
    }
    else if (event < 15) {
        if (is_david) {
            p.health.emergency = 15000;
            p.bank.checking -= 15000;
        }
        else {
            p.health.emergency = 8000;
            p.bank.checking -= 8000;
        }
    }
    else if (event < 20) {
        if (is_david) {
            p.tech.smartphone = 80000;
            p.bank.checking -= 80000;
        }
        else {
            p.tech.smartphone = 40000;
            p.bank.checking -= 40000;
        }
    }
    else if (event < 23 && !p.has_child && p.married) {
        p.has_child = true;
        p.children_count = 1;
    }
}

void calculate_net_worth() {
    david.total_assets = david.bank.checking + david.bank.savings + david.bank.deposite +
        david.bank.eur_account * david.bank.eur_rate +
        david.bank.usd_account * david.bank.usd_rate +
        david.realty.apartment_value + david.transport.car1_value +
        david.invest.stocks + david.invest.bonds + david.invest.crypto +
        david.invest.gold + david.invest.business_share;

    david.total_debts = david.bank.credit_card_debt;
    david.net_worth = david.total_assets - david.total_debts;

    lisa.total_assets = lisa.bank.checking + lisa.bank.savings +
        lisa.bank.eur_account * lisa.bank.eur_rate +
        lisa.realty.apartment_value + lisa.transport.car1_value +
        lisa.invest.crypto + lisa.invest.gold;

    lisa.total_debts = lisa.bank.credit_card_debt + lisa.realty.mortgage_debt +
        lisa.transport.loan_debt + lisa.edu.student_loan;

    lisa.net_worth = lisa.total_assets - lisa.total_debts;
}

void print_header(int month, int year) {
    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << "МЕСЯЦ " << month << " | " << year << std::endl;
    std::cout << std::string(80, '=') << std::endl;
}

void print_david_status() {
    std::cout << "\n👨 ДЭВИД - Накопитель" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    std::cout << "💰 Текущий счет: " << std::fixed << std::setprecision(0) << david.bank.checking << " RUB" << std::endl;
    std::cout << "🏦 Сбережения: " << david.bank.savings << " RUB" << std::endl;
    std::cout << "📈 Депозит: " << david.bank.deposite << " RUB" << std::endl;
    std::cout << "💶 Евро: " << david.bank.eur_account << " EUR" << std::endl;
    std::cout << "💵 Доллары: " << david.bank.usd_account << " USD" << std::endl;
    std::cout << "🏠 Недвижимость: " << david.realty.apartment_value << " RUB" << std::endl;
    std::cout << "🚗 Авто: " << david.transport.car1_value << " RUB" << std::endl;
    std::cout << "📊 Акции: " << david.invest.stocks << " RUB" << std::endl;
    std::cout << "🪙 Крипта: " << david.invest.crypto << " RUB" << std::endl;
    std::cout << "💎 Золото: " << david.invest.gold << " RUB" << std::endl;
}

void print_lisa_status() {
    std::cout << "\n👩 ЛИЗА - Тратитель" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    std::cout << "💰 Текущий счет: " << std::fixed << std::setprecision(0) << lisa.bank.checking << " RUB" << std::endl;
    std::cout << "🏦 Сбережения: " << lisa.bank.savings << " RUB" << std::endl;
    std::cout << "💳 Кредитка: " << lisa.bank.credit_card_debt << " RUB (лимит " << lisa.bank.credit_limit << ")" << std::endl;
    std::cout << "🏠 Ипотека: " << lisa.realty.mortgage_debt << " RUB" << std::endl;
    std::cout << "🚗 Кредит на авто: " << lisa.transport.loan_debt << " RUB" << std::endl;
    std::cout << "🎓 Кредит за учебу: " << lisa.edu.student_loan << " RUB" << std::endl;
    std::cout << "🚗 Авто: " << lisa.transport.car1_value << " RUB" << std::endl;
}

void print_net_worth() {
    std::cout << "\n" << std::string(40, '=') << std::endl;
    std::cout << "💵 ЧИСТЫЙ КАПИТАЛ" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "Дэвид: " << david.net_worth << " RUB" << std::endl;
    std::cout << "Лиза:  " << lisa.net_worth << " RUB" << std::endl;
    std::cout << "Разница: " << (david.net_worth - lisa.net_worth) << " RUB" << std::endl;
}

void save_to_file() {
    std::ofstream file("simulation_results.txt", std::ios::app);
    file << current_month << "," << current_year << ","
        << david.net_worth << "," << lisa.net_worth << ","
        << david.bank.checking << "," << lisa.bank.checking << ","
        << david.invest.stocks << "," << lisa.bank.credit_card_debt << "\n";
    file.close();
}

void special_events() {
    if (current_month == 1 && current_year == 2025) {
        std::cout << "\n🎉 НОВЫЙ ГОД 2025!" << std::endl;
        david.bank.checking += 100000;
        lisa.bank.checking += 50000;
    }

    if (current_month == 3 && current_year == 2025) {
        std::cout << "\n💍 ГОДОВЩИНА СВАДЬБЫ!" << std::endl;
        david.bank.checking -= 50000;
        lisa.bank.checking += 50000;
    }

    if (current_month == 6 && current_year == 2025) {
        std::cout << "\n🏦 КРИЗИС НА РЫНКЕ!" << std::endl;
        david.invest.stocks *= 0.8;
        david.invest.crypto *= 0.5;
        inflation += 0.02;
    }

    if (current_month == 9 && current_year == 2025 && !david.has_child) {
        std::cout << "\n👶 У ДЭВИДА И ЛИЗЫ РОДИЛСЯ РЕБЕНОК!" << std::endl;
        david.has_child = true;
        lisa.has_child = true;
        david.children_count = 1;
        lisa.children_count = 1;
        david.bank.checking -= 200000;
    }
}

int main() {
    srand(time(0));

    init_david();
    init_lisa();

    std::cout << "СИМУЛЯЦИЯ ЖИЗНИ ДЭВИДА И ЛИЗЫ" << std::endl;
    std::cout << "Период: " << simulation_months << " месяцев" << std::endl;
    std::cout << "Инфляция: " << inflation * 100 << "% годовых" << std::endl;

    for (int i = 0; i < simulation_months; i++) {
        current_month = (i % 12) + 1;
        if (i > 0 && current_month == 1) current_year++;

        print_header(current_month, current_year);

        david_monthly_income();
        lisa_monthly_income();

        david_monthly_expenses();
        lisa_monthly_expenses();

        david_invest();
        lisa_borrow();

        random_events(david, true);
        random_events(lisa, false);

        special_events();

        apply_inflation();

        calculate_net_worth();

        print_david_status();
        print_lisa_status();
        print_net_worth();

        save_to_file();

        if (i % 6 == 0) {
            std::cout << "\n⏸ Нажмите Enter для продолжения...";
            std::cin.get();
        }
    }

    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << "ИТОГИ СИМУЛЯЦИИ" << std::endl;
    std::cout << std::string(80, '=') << std::endl;

    print_net_worth();

    std::cout << "\n📊 СТАТИСТИКА:" << std::endl;
    std::cout << "Дэвид накопил: " << david.net_worth << " RUB" << std::endl;
    std::cout << "Лиза в долгах: " << lisa.total_debts << " RUB" << std::endl;

    if (david.net_worth > lisa.net_worth) {
        std::cout << "\n🏆 Дэвид выиграл в накоплении капитала!" << std::endl;
    }
    else {
        std::cout << "\n🏆 Лиза тратила, но счастливее?" << std::endl;
    }

    std::cout << "\nРезультаты сохранены в simulation_results.txt" << std::endl;

    return 0;
}