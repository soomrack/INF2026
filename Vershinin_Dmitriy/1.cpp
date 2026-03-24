#include <iostream>
#include <vector>
#include <map>
using namespace std;

using RUB = long long int;
using PERCENT = double;


struct Credit {
    RUB amount;
    RUB monthly_payment;
    PERCENT interest_rate;
    int months_left;
    bool active;
    string bank_name;
    int credit_score_impact;
    RUB total_paid;
    RUB interest_paid;
    vector<RUB> payment_history;
};

struct Deposit {
    RUB balance;
    PERCENT procent;
    string bank_name;
    int term_months;
    bool is_capitalized;
    RUB monthly_income;
    vector<RUB> deposit_history;
};

struct Bank {
    Credit credit;
    Deposit deposit;
    string name;
    RUB loyalty_points;
};

struct Stocks {
    int count;
    RUB cost;
    PERCENT growth;
    vector<string> tickers;
    map<string, int> portfolio;
    RUB total_invested;
    RUB total_dividends;
};

struct Bonds {
    int count;
    RUB cost;
    PERCENT growth;
    vector<string> bond_names;
    RUB total_invested;
    RUB total_interest;
};

struct RealEstate {
    RUB value;
    RUB rental_income;
    bool is_rented;
    string address;
    int square_meters;
    int rooms;
    int year_built;
    vector<RUB> renovation_history;
};

struct Business {
    bool has_business;
    RUB monthly_profit;
    RUB business_value;
    string business_type;
    int employees_count;
    RUB expenses;
    PERCENT growth_rate;
    vector<RUB> profit_history;
};

struct Investments {
    Stocks stocks;
    Bonds bonds;
    RealEstate real_estate;
    Business business;
    RUB crypto_balance;
    RUB gold_balance;
    vector<string> investment_history;
};

struct Insurance {
    RUB health_insurance;
    bool has_health_insurance;
    RUB car_insurance;
    bool has_car_insurance;
    RUB flat_insurance;
    bool has_flat_insurance;
    RUB life_insurance;
    bool has_life_insurance;
    RUB travel_insurance;
    bool has_travel_insurance;
};

struct Inflation {
    PERCENT salary;
    PERCENT food;
    PERCENT gas;
    PERCENT medicines;
    PERCENT entertainment;
    PERCENT car;
    PERCENT flat;
    PERCENT education;
    PERCENT healthcare;
    PERCENT utilities;
};

struct Taxes {
    PERCENT income_tax;
    PERCENT property_tax;
    PERCENT capital_gains_tax;
    PERCENT dividend_tax;
    PERCENT business_tax;
};

struct Car {
    RUB value;
    RUB gas;
    RUB maintenance_cost;
    string brand;
    string model;
    int year;
    int mileage;
    RUB insurance_cost;
    bool is_leased;
    RUB lease_payment;
};

struct Flat {
    RUB value;
    RUB utilities;
    int rooms;
    int floor;
    bool has_mortgage;
    RUB mortgage_payment;
    RUB mortgage_balance;
    PERCENT mortgage_rate;
};

struct Child {
    int age;
    int education_level;
    int intelligence;
    int happiness_child;
    RUB monthly_expenses;
    bool has_scholarship;
    vector<string> interests;
    RUB education_fund;
    string name;
    vector<int> grades;
    RUB allowance;
    bool has_part_time_job;
    RUB part_time_income;
};

struct Family {
    bool has_partner;
    RUB partner_salary;
    vector<Child> children;
    bool married;
    int years_married;
    RUB total_family_expenses;
    vector<RUB> family_income_history;
};

struct Education {
    bool has_higher_education;
    string degree;
    RUB tuition_paid;
    bool is_studying;
    vector<string> skills;
    RUB education_expenses;
};

struct HealthMetrics {
    int health_status;
    int mental_health;
    int fitness_level;
    RUB gym_membership;
    RUB therapy_cost;
    bool has_therapy;
    vector<string> medical_history;
    RUB total_medical_expenses;
};

struct Lifestyle {
    RUB travel_budget;
    vector<string> hobbies;
    RUB hobby_expenses;
    RUB charity_donations;
    bool has_pet;
    RUB pet_expenses;
    int social_events_per_month;
};

struct Person {
    string name;
    RUB salary;
    RUB capital;
    RUB food;
    RUB medicines;
    RUB entertainment;
    int health_status;
    int happiness;
    int age;
    bool is_employed;
    Family family;
    Car car;
    Flat flat;
    Bank bank;
    Insurance insurance;
    Investments investments;
    Education education;
    HealthMetrics health_metrics;
    Lifestyle lifestyle;
    RUB emergency_fund;
    RUB retirement_fund;
    vector<RUB> monthly_expense_history;
    vector<int> happiness_history;
    vector<int> health_history;
};


Person Alice;
Person Anton;
Inflation inflation;
Taxes taxes;
RUB global_economy_index = 100;
int global_crisis_counter = 0;
bool is_recession = false;


RUB calculate_child_expenses(int age) {
    RUB base_expenses = 10'000;
    
    if (age < 3) {
        return base_expenses + 10'000;
    } else if (age < 7) {
        return base_expenses + 5'000;
    } else if (age < 18) {
        return base_expenses + 10'000;
    } else {
        return base_expenses + 20'000;
    }
}


RUB calculate_education_cost(int education_level) {
    switch(education_level) {
        case 1: return 0;
        case 2: return 50'000;
        case 3: return 100'000;
        case 4: return 200'000;
        default: return 0;
    }
}


void handle_graduation(Child& child) {
    int choice = rand() % 2;
    
    switch(choice) {
        case 0:
            child.education_level = 2;
            break;
        case 1:
            child.education_level = 3;
            break;
    }
}


void apply_to_university(Child& child) {
    int admission_chance = child.intelligence;
    int economic_factor = global_economy_index > 80 ? 10 : -10;
    admission_chance = max(0, min(100, admission_chance + economic_factor));
    
    if (rand() % 100 < admission_chance) {
        child.has_scholarship = (child.intelligence > 85 && rand() % 2);
        child.education_level = 4;
    } else {
        child.education_level = 3;
    }
}


void update_academic_performance(Child& child) {
    float performance = (child.intelligence * 0.7 + child.happiness_child * 0.3) / 100;
    int grade = 60 + (performance * 40);
    child.grades.push_back(grade);
    
    if (performance > 0.9 && !child.has_scholarship) {
        child.has_scholarship = true;
    }
    else if (performance < 0.5 && child.has_scholarship) {
        child.has_scholarship = false;
    }
    
    if (performance > 0.8) {
        child.happiness_child = min(100, child.happiness_child + 5);
    } 
    else if (performance < 0.4) {
        child.happiness_child = max(0, child.happiness_child - 10);
    }
    
    if (child.age >= 16 && !child.has_part_time_job && performance > 0.7) {
        child.has_part_time_job = true;
    }
}

//===================Alice functoins==================

void alice_save_history() {
    Alice.monthly_expense_history.push_back(Alice.food + Alice.medicines + 
                                              Alice.entertainment + Alice.car.gas + 
                                              Alice.flat.utilities);
    Alice.happiness_history.push_back(Alice.happiness);
    Alice.health_history.push_back(Alice.health_status);
    
    if (Alice.monthly_expense_history.size() > 24) {
        Alice.monthly_expense_history.erase(Alice.monthly_expense_history.begin());
        Alice.happiness_history.erase(Alice.happiness_history.begin());
        Alice.health_history.erase(Alice.health_history.begin());
    }
}


void alice_have_child() {
    if (Alice.family.children.size() >= 5) {
        return;
    }
    
    Child new_child;
    new_child.age = 0;
    new_child.education_level = 0;
    new_child.intelligence = 50 + rand() % 51;
    new_child.happiness_child = 80;
    new_child.has_scholarship = false;
    new_child.education_fund = 0;
    new_child.name = "Child_" + to_string(Alice.family.children.size() + 1);
    new_child.allowance = 500;
    new_child.has_part_time_job = false;
    new_child.part_time_income = 0;
    
    new_child.monthly_expenses = calculate_child_expenses(new_child.age);
    
    Alice.family.children.push_back(new_child);
    
    Alice.food += 8000;
    Alice.entertainment += 5000;
    
    if (Alice.family.has_partner) {
        Alice.happiness = min(100, Alice.happiness + 20);
    } else {
        Alice.happiness = max(0, Alice.happiness - 15);
    }
}


void alice_update_children_expenses() {
    RUB total = 0;
    for (auto child : Alice.family.children) {
        child.monthly_expenses = calculate_child_expenses(child.age);
        total += child.monthly_expenses;
        
        if (child.has_part_time_job && child.age >= 16) {
            child.part_time_income = 5000 + rand() % 15000;
            total -= child.part_time_income;
        }
    }
}


void alice_children_expenses() {
    RUB total_children_expenses = 0;
    
    for (auto child : Alice.family.children) {
        total_children_expenses += child.monthly_expenses;
        
        if (child.education_level == 3 && child.has_scholarship) {
            total_children_expenses -= 5000;
        }
        
        if (child.age >= 18 && child.has_part_time_job) {
            total_children_expenses -= child.part_time_income;
        }
        
        child.allowance = 500 + (child.age * 50);
        total_children_expenses += child.allowance;
    }
    
    Alice.bank.deposit.balance -= total_children_expenses;
}


void alice_child_become_adult(int year) {
    for (auto it = Alice.family.children.begin(); it != Alice.family.children.end();) {
        if (it->age >= 22 && it->education_level >= 4) {
            Alice.food -= 8000;
            Alice.happiness = min(100, Alice.happiness + 15);
            
            if (it->has_part_time_job) {
                Alice.bank.deposit.balance -= 10000;
            }
            
            it = Alice.family.children.erase(it);
        } else {
            ++it;
        }
    }
}


void alice_children_growth(int year) {
    for (auto& child : Alice.family.children) {
        child.age++;
        
        if (child.age == 7 && child.education_level == 0) {
            child.education_level = 1;
        } 
        else if (child.age == 15 && child.education_level == 1) {
            handle_graduation(child);
        }
        else if (child.age == 17 && child.education_level == 3) {
            child.education_level = 4;
            apply_to_university(child);
        }
        else if (child.age == 8 && child.education_level == 2) {
            child.education_level = 3;
        }
        
        if (child.age % 5 == 0 && child.age > 0) {
            child.intelligence = min(100, child.intelligence + rand() % 10);
        }
    }
    alice_update_children_expenses();
}


void alice_buy_gifts_for_children(int month) {
    if (month == 12) {
        for (auto& child : Alice.family.children) {
            RUB gift_cost = 3000 + rand() % 7000;
            
            if (Alice.bank.deposit.balance >= gift_cost) {
                Alice.bank.deposit.balance -= gift_cost;
                child.happiness_child = min(100, child.happiness_child + 15);
            }
        }
    }
}


void alice_children(int month, int year) {
    alice_children_expenses();
    alice_buy_gifts_for_children(month);
    
    if (month == 1 || month == 6) {
        for (auto& child : Alice.family.children) {
            update_academic_performance(child);
        }
    }
    
    if (month == 1) {
        alice_children_growth(year);
        alice_child_become_adult(year);
    }
}



void alice_salary(const int month, const int year) {
    if (Alice.is_employed) {
        if (rand() % 1000 == 777) {
            Alice.salary *= 1.5;
        }
        
        if (month == 1 && year % 2 == 0) {
            Alice.salary *= 1 + inflation.salary / 100;
        }
        
        if (is_recession && Alice.salary > 50000) {
            Alice.salary *= 0.95;
        }

        Alice.bank.deposit.balance += Alice.salary;
        
        if (Alice.family.has_partner && Alice.family.married) {
            Alice.bank.deposit.balance += Alice.family.partner_salary;
        }
    }
    else {
        if(rand() % 10 == 4 && !is_recession) {
            Alice.is_employed = true;
            Alice.salary = 100'000 + rand() % 100'000;
        }
        else if (rand() % 20 == 1) {
            Alice.is_employed = true;
            Alice.salary = 50000 + rand() % 50000;
        }
    }
}


void alice_random_expenses() {
    RUB RandomExpenses = rand() % 50'000;
    Alice.bank.deposit.balance -= RandomExpenses;
}


void alice_random_positive_event(int month, int year) {
    int event = rand() % 500;
    
    if (event < 10) {
        RUB win = 50000 + rand() % 200000;
        Alice.bank.deposit.balance += win;
        Alice.happiness = min(100, Alice.happiness + 15);
    }
    else if (event < 30) {
        RUB gift = 5000 + rand() % 20000;
        Alice.bank.deposit.balance += gift;
        Alice.happiness = min(100, Alice.happiness + 5);
    }
    else if (event < 45 && Alice.health_status < 80) {
        Alice.health_status = min(100, Alice.health_status + 20);
    }
    else if (event < 60) {
        alice_have_child();
    }
    else if (event < 65 && Alice.investments.business.has_business) {
        RUB business_boost = Alice.investments.business.business_value * 0.1;
        Alice.investments.business.business_value += business_boost;
        Alice.bank.deposit.balance += business_boost;
    }
    else if (event < 68) {
        RUB inheritance = 100000 + rand() % 500000;
        Alice.bank.deposit.balance += inheritance;
    }
}


void alice_random_negative_event(int month, int year) {
    int event = rand() % 500;
    
    if (event < 15 && Alice.car.value > 0) {
        RUB repair_cost = Alice.car.value * (5 + rand() % 20) / 100;
        repair_cost = min(repair_cost, Alice.bank.deposit.balance / 2);
        Alice.bank.deposit.balance -= repair_cost;
        Alice.happiness = max(0, Alice.happiness - 10);
    }
    else if (event < 25) {
        RUB medical_cost = Alice.salary * (10 + rand() % 30) / 100;
        if (!Alice.insurance.has_health_insurance) {
            Alice.bank.deposit.balance -= medical_cost;
        } 
        else {
            RUB insurance_payout = medical_cost * 0.7;
            Alice.bank.deposit.balance -= (medical_cost - insurance_payout);
        }
        Alice.health_status = max(0, Alice.health_status - 15);
        Alice.happiness = max(0, Alice.happiness - 10);
    }
    else if (event < 30 && month == 12) {
        RUB theft = Alice.bank.deposit.balance * (2 + rand() % 8) / 100;
        Alice.bank.deposit.balance -= theft;
        Alice.happiness = max(0, Alice.happiness - 25);
    }
    else if (event < 32 && Alice.is_employed && is_recession) {
        Alice.is_employed = false;
        RUB severance = Alice.salary * 2;
        Alice.salary = 0;
        Alice.bank.deposit.balance += severance;
        Alice.happiness = max(0, Alice.happiness - 40);
    }
    else if (event < 35 && Alice.bank.credit.active) {
        RUB fine = Alice.bank.credit.monthly_payment * 0.5;
        Alice.bank.deposit.balance -= fine;
    }
    else if (event < 38 && Alice.investments.stocks.count > 0) {
        RUB stock_loss = Alice.investments.stocks.cost * 0.05;
        Alice.investments.stocks.cost -= stock_loss;
    }
}


void alice_take_credit(RUB amount, int months) {
    Alice.bank.credit.amount += amount;
    Alice.bank.credit.months_left = months;
    Alice.bank.credit.interest_rate = 15 + rand() % 10;
    Alice.bank.credit.monthly_payment = amount / months * (1 + Alice.bank.credit.interest_rate / 100);
    Alice.bank.credit.active = true;
    Alice.bank.credit.bank_name = "National Bank";
    Alice.bank.deposit.balance += amount;
}


void alice_credit_payment() {
    if (Alice.bank.credit.active) {
        Alice.bank.deposit.balance -= Alice.bank.credit.monthly_payment;
        Alice.bank.credit.total_paid += Alice.bank.credit.monthly_payment;
        Alice.bank.credit.payment_history.push_back(Alice.bank.credit.monthly_payment);
        Alice.bank.credit.months_left--;
        
        if (Alice.bank.credit.months_left <= 0) {
            Alice.bank.credit.active = false;
        }
    }
}


void alice_update_stocks() {
    if (Alice.investments.stocks.count > 0) {
        int market_volatility = is_recession ? -15 : (rand() % 40 - 10);
        Alice.investments.stocks.growth = market_volatility;
        Alice.investments.stocks.cost += Alice.investments.stocks.cost * Alice.investments.stocks.growth / 100;
    }
}


void alice_update_bonds() {
    if (Alice.investments.bonds.count > 0) {
        Alice.investments.bonds.growth = (rand() % 20 - 5);
        Alice.investments.bonds.cost += Alice.investments.bonds.cost * Alice.investments.bonds.growth / 100;
    }
}


void alice_dividends_stocks() {
    if (Alice.investments.stocks.count > 0) {
        RUB dividends = Alice.investments.stocks.cost * (5 + rand() % 5) / 100;
        Alice.bank.deposit.balance += dividends;
        Alice.investments.stocks.total_dividends += dividends;
    }
}


void alice_dividends_bonds() {
    if (Alice.investments.bonds.count > 0) {
        RUB interest = Alice.investments.bonds.cost * (3 + rand() % 3) / 100;
        Alice.bank.deposit.balance += interest;
        Alice.investments.bonds.total_interest += interest;
    }
}


void alice_crypto_investment() {
    if (Alice.investments.crypto_balance > 0) {
        PERCENT crypto_change = (rand() % 60 - 20);
        Alice.investments.crypto_balance *= 1 + crypto_change / 100;
    }
}


void alice_gold_investment() {
    if (Alice.investments.gold_balance > 0) {
        PERCENT gold_change = (rand() % 20 - 5);
        Alice.investments.gold_balance *= 1 + gold_change / 100;
    }
}


void alice_update_business() {
    if (Alice.investments.business.has_business) {
        PERCENT business_growth = (rand() % 30 - 10);
        Alice.investments.business.growth_rate = business_growth;
        Alice.investments.business.business_value *= 1 + business_growth / 100;
        Alice.investments.business.monthly_profit = Alice.investments.business.business_value * 0.02;
        
        if (is_recession) {
            Alice.investments.business.monthly_profit *= 0.7;
        }
        
        Alice.bank.deposit.balance += Alice.investments.business.monthly_profit;
        Alice.investments.business.profit_history.push_back(Alice.investments.business.monthly_profit);
    }
}


void alice_update_real_estate() {
    if (Alice.investments.real_estate.value > 0) {
        PERCENT real_estate_growth = (rand() % 20 - 2);
        Alice.investments.real_estate.value *= 1 + real_estate_growth / 100;
        
        if (Alice.investments.real_estate.is_rented) {
            RUB rental = Alice.investments.real_estate.rental_income;
            Alice.bank.deposit.balance += rental;
        }
    }
}


void alice_update_investments() {
    alice_update_stocks();
    alice_update_bonds();
    alice_dividends_stocks();
    alice_dividends_bonds();
    alice_crypto_investment();
    alice_gold_investment();
    alice_update_business();
    alice_update_real_estate();
}


RUB alice_count_insurance_pay() {
    RUB insurance_pay = 0;
    if (Alice.insurance.has_flat_insurance) {
        insurance_pay += Alice.insurance.flat_insurance;
    }
    if (Alice.insurance.has_car_insurance) {
        insurance_pay += Alice.insurance.car_insurance;
    }
    if (Alice.insurance.has_health_insurance) {
        insurance_pay += Alice.insurance.health_insurance;
    }
    if (Alice.insurance.has_life_insurance) {
        insurance_pay += Alice.insurance.life_insurance;
    }
    if (Alice.insurance.has_travel_insurance) {
        insurance_pay += Alice.insurance.travel_insurance;
    }
    return insurance_pay;
}


void alice_pay_insurance(int month) {
    if (month == 1) {
        RUB insurance_pay = alice_count_insurance_pay();
        
        if (Alice.bank.deposit.balance >= insurance_pay) {
            Alice.bank.deposit.balance -= insurance_pay;
        } else {
            vector<string> insurances = {"health", "car", "flat", "life", "travel"};
            int cancel_index = rand() % insurances.size();
            switch(cancel_index) {
                case 0: Alice.insurance.has_health_insurance = false; break;
                case 1: Alice.insurance.has_car_insurance = false; break;
                case 2: Alice.insurance.has_flat_insurance = false; break;
                case 3: Alice.insurance.has_life_insurance = false; break;
                case 4: Alice.insurance.has_travel_insurance = false; break;
            }
        }
    }
}


void alice_update_health() {
    if (Alice.food > 20000) {
        Alice.health_status = min(100, Alice.health_status + 2);
    } else if (Alice.food < 10000) {
        Alice.health_status = max(0, Alice.health_status - 5);
    }
    
    if (Alice.medicines > 5000) {
        Alice.health_status = min(100, Alice.health_status + 1);
    }
    
    if (Alice.age > 60) {
        Alice.health_status = max(0, Alice.health_status - 2);
    }
    
    if (Alice.health_metrics.gym_membership > 0) {
        Alice.health_metrics.fitness_level = min(100, Alice.health_metrics.fitness_level + 5);
        Alice.health_status = min(100, Alice.health_status + 3);
    }
    
    if (Alice.health_status < 30 && Alice.bank.deposit.balance > 50000) {
        RUB treatment = 30000;
        Alice.bank.deposit.balance -= treatment;
        Alice.health_status += 20;
    }
}


void alice_update_happiness() {
    if (Alice.is_employed) {
        Alice.happiness = max(0, Alice.happiness - 3);
    }
    
    if (Alice.entertainment > 15000) {
        Alice.happiness = min(100, Alice.happiness + 8);
    } else if (Alice.entertainment < 5000) {
        Alice.happiness = max(0, Alice.happiness - 5);
    }
    
    if (Alice.health_status < 50) {
        Alice.happiness = max(0, Alice.happiness - 10);
    }
    
    if (Alice.family.has_partner && Alice.family.married) {
        Alice.happiness = min(100, Alice.happiness + 3);
    }
    
    if (Alice.lifestyle.travel_budget > 0) {
        Alice.happiness = min(100, Alice.happiness + 5);
    }
    
    if (Alice.lifestyle.charity_donations > 0) {
        Alice.happiness = min(100, Alice.happiness + 2);
    }
}


void alice_deposit() {
    Alice.bank.deposit.balance *= 1 + Alice.bank.deposit.procent / 12.0 / 100.0;
    Alice.bank.deposit.deposit_history.push_back(Alice.bank.deposit.balance);
}


void alice_food(const int month) {
    if (month == 1) {
        Alice.food *= 1 + inflation.food / 100;
    }
    Alice.bank.deposit.balance -= Alice.food;
}


void alice_medicines(const int month) {
    if (month == 1) {
        Alice.medicines *= 1 + inflation.medicines / 100;
    }
    if (Alice.health_metrics.has_therapy) {
        Alice.bank.deposit.balance -= Alice.health_metrics.therapy_cost;
    }
    Alice.bank.deposit.balance -= Alice.medicines;
}


void alice_entertainment(const int month) {
    if (month == 1) {
        Alice.entertainment *= 1 + inflation.entertainment / 100;
    }
    Alice.bank.deposit.balance -= Alice.entertainment;
    
    if (Alice.lifestyle.hobby_expenses > 0) {
        Alice.bank.deposit.balance -= Alice.lifestyle.hobby_expenses;
    }
}


void alice_car(const int month) {
    if (month == 1) {
        Alice.car.gas *= 1 + inflation.gas / 100;
        Alice.car.value *= 1 + inflation.car / 100;
        if (Alice.car.is_leased) {
            Alice.bank.deposit.balance -= Alice.car.lease_payment;
        }
    }
    Alice.bank.deposit.balance -= Alice.car.gas;
}


void alice_car_maintenance(int month) {
    if (month == 6) {
        RUB maintenance = Alice.car.maintenance_cost + (Alice.car.mileage / 10000) * 5000;
        Alice.bank.deposit.balance -= maintenance;
    }
}


void alice_flat(const int month) {
    if (month == 1) {
        Alice.flat.value *= 1 + inflation.flat / 100;
        Alice.flat.utilities *= 1 + inflation.utilities / 100;
    }
    Alice.bank.deposit.balance -= Alice.flat.utilities;
    
    if (Alice.flat.has_mortgage) {
        Alice.bank.deposit.balance -= Alice.flat.mortgage_payment;
        Alice.flat.mortgage_balance -= Alice.flat.mortgage_payment;
        
        if (Alice.flat.mortgage_balance <= 0) {
            Alice.flat.has_mortgage = false;
        }
    }
}


void alice_pay_taxes(const int month) {
    if (month == 1) {
        RUB salarytax = Alice.salary * 12 * taxes.income_tax / 100;
        RUB cartax = Alice.car.value * taxes.property_tax / 100;
        RUB flattax = Alice.flat.value * taxes.property_tax / 100;
        RUB dividend_tax = (Alice.investments.stocks.total_dividends + 
                           Alice.investments.bonds.total_interest) * taxes.dividend_tax / 100;
        
        RUB total_tax = salarytax + cartax + flattax + dividend_tax;
        Alice.bank.deposit.balance -= total_tax;
    }
}


void alice_save_emergency_fund() {
    RUB target_emergency = Alice.monthly_expense_history.empty() ? 100000 : 
                           Alice.monthly_expense_history.back() * 6;
    
    if (Alice.emergency_fund < target_emergency && Alice.bank.deposit.balance > 50000) {
        RUB save = min(Alice.bank.deposit.balance / 20, target_emergency - Alice.emergency_fund);
        Alice.emergency_fund += save;
        Alice.bank.deposit.balance -= save;
    }
}


void alice_save_retirement() {
    if (Alice.age < 65 && Alice.is_employed) {
        RUB retirement_contribution = Alice.salary * 0.05;
        Alice.retirement_fund += retirement_contribution;
        Alice.bank.deposit.balance -= retirement_contribution;
    }
}


void update_economy(int year) {
    global_economy_index = 100 + (rand() % 30 - 15);
    
    if (year % 10 == 0 && year > 2020) {
        is_recession = true;
        global_crisis_counter = 24;
    }
    
    if (is_recession && global_crisis_counter > 0) {
        global_crisis_counter--;
        if (global_crisis_counter == 0) {
            is_recession = false;
        }
    }
}


RUB alice_capital() {
    RUB capital = Alice.bank.deposit.balance + Alice.car.value + Alice.flat.value + 
                  Alice.investments.stocks.cost + Alice.investments.bonds.cost +
                  Alice.investments.gold_balance + Alice.investments.crypto_balance +
                  Alice.investments.real_estate.value + Alice.investments.business.business_value +
                  Alice.emergency_fund + Alice.retirement_fund;
    return capital;
}

//=============================Anton functions=====================================

void anton_have_child() {
    RUB total_children_expenses = 0;
    for (auto child : Anton.family.children) {
        total_children_expenses += child.monthly_expenses;
    }
    
    if (!Anton.family.children.empty() && total_children_expenses > Anton.salary * 0.4) {
        return;
    }
    
    Child new_child;
    new_child.age = 0;
    new_child.education_level = 0;
    new_child.intelligence = 40 + rand() % 61;
    new_child.happiness_child = 90;
    new_child.has_scholarship = false;
    new_child.education_fund = 0;
    
    new_child.monthly_expenses = calculate_child_expenses(new_child.age);
    
    new_child.education_fund = 50'000;
    Anton.bank.deposit.balance -= 50'000;
    
    Anton.family.children.push_back(new_child);
    
    Anton.food += 5'000;
    Anton.entertainment -= 2'000;
    
    if (Anton.family.has_partner) {
        Anton.happiness = min(100, Anton.happiness + 25);
        Anton.family.partner_salary *= 1.05;
    } else {
        Anton.happiness = max(0, Anton.happiness - 5);
    }
}


void anton_update_children_expenses() {
    for (auto& child : Anton.family.children) {
        child.monthly_expenses = calculate_child_expenses(child.age);
        
        if (child.age >= 12 && child.age < 18) {
            RUB allowance = 500 + child.age * 50;
            child.monthly_expenses += allowance;
        }
        
        if (child.age >= 16 && child.age < 22 && !child.has_scholarship) {
            RUB part_time = 8'000 + rand() % 7'000;
            child.monthly_expenses -= part_time;
            child.has_scholarship = true;
        }
    }
}


void anton_children_expenses() {
    RUB total_children_expenses = 0;
    
    for (auto& child : Anton.family.children) {
        total_children_expenses += child.monthly_expenses;
        
        if (child.education_level >= 3 && child.intelligence > 70) {
            RUB reward = 2'000;
            total_children_expenses += reward;
            child.happiness_child = min(100, child.happiness_child + 5);
        }
        
        if (child.happiness_child < 30) {
            RUB penalty = 1'000;
            total_children_expenses -= penalty;
        }
    }
    
    Anton.bank.deposit.balance -= total_children_expenses;
}


void anton_child_become_adult(int year) {
    for (auto it = Anton.family.children.begin(); it != Anton.family.children.end();) {
        bool can_be_independent = false;
        
        if (it->age >= 21) {
            if (it->has_scholarship && it->education_level >= 3) {
                can_be_independent = true;
            }
            if (it->age >= 23) {
                can_be_independent = true;
            }
            if (it->education_level == 2 && it->age >= 19) {
                can_be_independent = true;
            }
        }
        
        if (can_be_independent) {
            Anton.food -= 5'000;
            Anton.happiness = min(100, Anton.happiness + 10);
            
            RUB start_capital = it->education_fund;
            Anton.bank.deposit.balance -= start_capital;
            
            it = Anton.family.children.erase(it);
        } else {
            ++it;
        }
    }
}


void anton_children_growth(int year) {
    for (auto& child : Anton.family.children) {
        child.age++;
        
        if (child.age == 6) {
            child.education_level = 1;
        } 
        else if (child.age == 15 && child.education_level == 1) {
            handle_graduation(child);
        }
        else if (child.age == 17 && child.education_level == 3) {
            child.education_level = 4;
            apply_to_university(child);
        }
        
        if (child.age % 3 == 0 && child.age > 0) {
            string new_interest;
            switch(rand() % 3) {
                case 0: new_interest = "sports"; break;
                case 1: new_interest = "music"; break;
                case 2: new_interest = "art"; break;
            }
            child.interests.push_back(new_interest);
        }
        
        anton_update_children_expenses();
    }
}


void anton_buy_gifts_for_children(int month) {
    bool is_birthday_month = false;
    for (auto& child : Anton.family.children) {
        if (month == (child.age % 12 + 1)) {
            is_birthday_month = true;
            break;
        }
    }
    
    if (month == 12 || is_birthday_month) {
        for (auto& child : Anton.family.children) {
            RUB gift_cost = 1'000;
            if (child.intelligence > 80) gift_cost = 5'000;
            else if (child.intelligence > 60) gift_cost = 3'000;
            
            if (Anton.bank.deposit.balance >= gift_cost) {
                Anton.bank.deposit.balance -= gift_cost;
                child.happiness_child = min(100, child.happiness_child + 20);
            }
        }
    }
}


void anton_children(int month, int year) {
    anton_children_expenses();
    anton_buy_gifts_for_children(month);
    
    for (auto& child : Anton.family.children) {
        update_academic_performance(child);
    }
    
    if (month == 1) {
        anton_children_growth(year);
        anton_child_become_adult(year);
    }
}


void anton_salary(const int month, const int year) {
    if (Anton.is_employed) {
        if (Anton.happiness > 80 && rand() % 200 == 0) {
            Anton.salary *= 1.1;
        }
        
        if (month == 1) {
            Anton.salary *= 1 + inflation.salary / 100;
        }
        
        if (month == 12) {
            RUB bonus = Anton.salary;
            Anton.bank.deposit.balance += bonus;
        }

        Anton.bank.deposit.balance += Anton.salary;
        
        if (Anton.family.has_partner && Anton.family.married) {
            Anton.bank.deposit.balance += Anton.family.partner_salary;
            if (month == 12) {
                Anton.bank.deposit.balance += Anton.family.partner_salary;
            }
        }
    }
    else {
        if(rand() % 6 == 0) {
            Anton.is_employed = true;
            Anton.salary = 70'000 + rand() % 60'000;
        }
    }
}


void anton_random_expenses() {
    if (rand() % 100 < 10) {
        RUB RandomExpenses = rand() % 20'000;
        Anton.bank.deposit.balance -= RandomExpenses;
    }
}


void anton_random_positive_event(int month, int year) {
    int event = rand() % 500;
    
    if (event < 5) {
        RUB win = 20'000 + rand() % 50'000;
        Anton.bank.deposit.balance += win;
        Anton.happiness = min(100, Anton.happiness + 20);
    }
    else if (event < 12) {
        RUB gift = 2'000 + rand() % 5'000;
        Anton.bank.deposit.balance += gift;
        Anton.happiness = min(100, Anton.happiness + 8);
    }
    else if (event < 18 && Anton.health_status < 90) {
        Anton.health_status = min(100, Anton.health_status + 25);
    }
    else if (event < 24) {
        anton_have_child();
    }
    else if (event < 28) {
        RUB bonus = Anton.salary * (Anton.age / 10);
        Anton.bank.deposit.balance += bonus;
    }
    else if (event < 32 && !Anton.bank.credit.active) {
        Anton.bank.credit.interest_rate = 8;
    }
}


void anton_random_negative_event(int month, int year) {
    int event = rand() % 500;
    
    if (event < 8 && Anton.car.value > 0) {
        RUB repair_cost = Anton.car.value * (2 + rand() % 10) / 100;
        if (Anton.bank.deposit.balance >= repair_cost) {
            Anton.bank.deposit.balance -= repair_cost;
        } 
        else {
            Anton.car.value *= 0.95;
        }
        Anton.happiness = max(0, Anton.happiness - 8);
    }
    else if (event < 15) {
        RUB medical_cost = Anton.salary * (5 + rand() % 15) / 100;
        if (!Anton.insurance.has_health_insurance) {
            if (Anton.bank.deposit.balance >= medical_cost) {
                Anton.bank.deposit.balance -= medical_cost;
            } 
            else {
                Anton.health_status = max(0, Anton.health_status - 30);
            }
        } 
        else {
            RUB insurance_payout = medical_cost * 0.9;
            Anton.bank.deposit.balance -= (medical_cost - insurance_payout);
        }
        Anton.health_status = max(0, Anton.health_status - 10);
        Anton.happiness = max(0, Anton.happiness - 8);
    }
    else if (event < 20 && month == 12) {
        RUB theft = Anton.bank.deposit.balance * (1 + rand() % 3) / 100;
        Anton.bank.deposit.balance -= theft;
        Anton.happiness = max(0, Anton.happiness - 20);
    }
    else if (event < 23 && Anton.is_employed && Anton.age > 55) {
        Anton.is_employed = false;
        Anton.salary = Anton.salary * 0.7;
        Anton.happiness = max(0, Anton.happiness - 15);
    }
    else if (event < 26 && Anton.bank.credit.active) {
        RUB fine = Anton.bank.credit.monthly_payment * 0.2;
        Anton.bank.deposit.balance -= fine;
        Anton.bank.credit.interest_rate += 1;
    }
    else if (event < 28) {
        taxes.income_tax = min(20.0, taxes.income_tax + 1);
        Anton.happiness = max(0, Anton.happiness - 5);
    }
}


void anton_take_credit(RUB amount, int months) {
    RUB best_rate = 20;
    if (Anton.bank.deposit.balance > 200'000) {
        best_rate = 12;
    }
    
    Anton.bank.credit.amount += amount;
    Anton.bank.credit.months_left = months;
    Anton.bank.credit.interest_rate = best_rate;
    Anton.bank.credit.monthly_payment = amount / months * (1 + best_rate / 100);
    Anton.bank.credit.active = true;
    Anton.bank.deposit.balance += amount;
}


void anton_credit_payment() {
    if (Anton.bank.credit.active) {
        RUB extra = 0;
        if (Anton.bank.deposit.balance > Anton.bank.credit.monthly_payment * 12) {
            extra = Anton.bank.credit.monthly_payment;
        }
        
        RUB payment = Anton.bank.credit.monthly_payment + extra;
        if (Anton.bank.deposit.balance >= payment) {
            Anton.bank.deposit.balance -= payment;
            Anton.bank.credit.amount -= extra;
            Anton.bank.credit.months_left--;
        } else {
            Anton.bank.credit.interest_rate += 2;
        }
        
        if (Anton.bank.credit.amount <= 0 || Anton.bank.credit.months_left <= 0) {
            Anton.bank.credit.active = false;
        }
    }
}


void anton_update_stocks() {
    if (Anton.investments.stocks.count > 0) {
        int market_trend = (rand() % 30 - 10);
        Anton.investments.stocks.growth = market_trend;
        Anton.investments.stocks.cost += Anton.investments.stocks.cost * market_trend / 100;
        
        if (market_trend < -10 && Anton.bank.deposit.balance > 50'000) {
            RUB maxbuy = 30'000;
            RUB buy = min(maxbuy, Anton.bank.deposit.balance / 10);
            Anton.investments.stocks.cost += buy;
            Anton.investments.stocks.count++;
            Anton.bank.deposit.balance -= buy;
        }
    }
}


void anton_update_bonds() {
    if (Anton.investments.bonds.count > 0) {
        Anton.investments.bonds.growth = (rand() % 15 - 2);
        Anton.investments.bonds.cost += Anton.investments.bonds.cost * Anton.investments.bonds.growth / 100;
    }
}


void anton_dividends_stocks() {
    if (Anton.investments.stocks.count > 0) {
        RUB dividends = Anton.investments.stocks.cost * (2 + rand() % 4) / 100;
        Anton.bank.deposit.balance += dividends;
        if (dividends > 5'000) {
            Anton.investments.stocks.cost += dividends * 0.5;
        }
    }
}


void anton_dividends_bonds() {
    if (Anton.investments.bonds.count > 0) {
        RUB interest = Anton.investments.bonds.cost * (4 + rand() % 3) / 100;
        Anton.bank.deposit.balance += interest;
    }
}


void anton_update_investments() {
    static int rebalance_month = 0;
    rebalance_month++;
    
    anton_update_stocks();
    anton_update_bonds();
    anton_dividends_stocks();
    anton_dividends_bonds();
    
    if (rebalance_month >= 12) {
        rebalance_month = 0;
        RUB total = Anton.investments.stocks.cost + Anton.investments.bonds.cost;
        if (total > 0) {
            RUB target_stocks = total * 0.6;
            if (Anton.investments.stocks.cost > target_stocks) {
                RUB sell = Anton.investments.stocks.cost - target_stocks;
                Anton.investments.stocks.cost -= sell;
                Anton.bank.deposit.balance += sell;
            } else if (Anton.investments.stocks.cost < target_stocks) {
                RUB buy = min(target_stocks - Anton.investments.stocks.cost, Anton.bank.deposit.balance / 5);
                Anton.investments.stocks.cost += buy;
                Anton.bank.deposit.balance -= buy;
            }
        }
    }
}


RUB anton_count_insurance_pay() {
    RUB insurance_pay = 0;
    if (Anton.insurance.has_flat_insurance) {
        insurance_pay += Anton.insurance.flat_insurance;
    } else {
        Anton.insurance.has_flat_insurance = true;
        insurance_pay += Anton.insurance.flat_insurance;
    }
    
    if (Anton.insurance.has_car_insurance) {
        insurance_pay += Anton.insurance.car_insurance;
    } else if (Anton.car.value > 0) {
        Anton.insurance.has_car_insurance = true;
        insurance_pay += Anton.insurance.car_insurance;
    }
    
    if (Anton.insurance.has_health_insurance) {
        insurance_pay += Anton.insurance.health_insurance;
    } else {
        Anton.insurance.has_health_insurance = true;
        insurance_pay += Anton.insurance.health_insurance;
    }
    
    return insurance_pay;
}


void anton_pay_insurance(int month) {
    if (month == 1) {
        RUB insurance_pay = anton_count_insurance_pay();
        
        if (Anton.bank.deposit.balance >= insurance_pay) {
            Anton.bank.deposit.balance -= insurance_pay;
        } else {
            anton_take_credit(insurance_pay, 12);
        }
    }
}


void anton_update_health() {
    if (Anton.food > 12'000 && Anton.food < 20'000) {
        Anton.health_status = min(100, Anton.health_status + 5);
    } else if (Anton.food > 25'000) {
        Anton.health_status = max(0, Anton.health_status - 5);
    } else if (Anton.food < 8'000) {
        Anton.health_status = max(0, Anton.health_status - 10);
    }
    
    static int checkup_counter = 0;
    checkup_counter++;
    if (checkup_counter >= 12) {
        checkup_counter = 0;
        RUB checkup_cost = 5'000;
        if (Anton.bank.deposit.balance >= checkup_cost) {
            Anton.bank.deposit.balance -= checkup_cost;
            Anton.health_status = min(100, Anton.health_status + 10);
        }
    }
    
    if (Anton.age > 60) {
        Anton.health_status = max(0, Anton.health_status - 1);
    }
}


void anton_update_happiness() {
    if (Anton.is_employed) {
        Anton.happiness = max(0, Anton.happiness - 2);
    }
    
    if (Anton.entertainment > 8'000 && Anton.entertainment < 15'000) {
        Anton.happiness = min(100, Anton.happiness + 10);
    } else if (Anton.entertainment < 3'000) {
        Anton.happiness = max(0, Anton.happiness - 8);
    }
    
    if (Anton.health_status < 60) {
        Anton.happiness = max(0, Anton.happiness - 15);
    }
    
    if (Anton.family.has_partner && Anton.family.married) {
        Anton.happiness = min(100, Anton.happiness + 4);
    }
    
    if (Anton.bank.deposit.balance > 2'000'000) {
        Anton.happiness = min(100, Anton.happiness + 2);
    } else if (Anton.bank.deposit.balance < 100'000) {
        Anton.happiness = max(0, Anton.happiness - 5);
    }
}


void anton_deposit() {
    RUB for_investment = Anton.bank.deposit.balance * 0.3;
    if (for_investment > 10'000) {
        Anton.investments.stocks.cost += for_investment / 2;
        Anton.investments.bonds.cost += for_investment / 2;
        Anton.bank.deposit.balance -= for_investment;
    }
    
    Anton.bank.deposit.balance *= 1 + Anton.bank.deposit.procent / 12.0 / 100.0;
}


void anton_food(const int month) {
    if (month == 1) {
        Anton.food *= 1 + inflation.food / 100;
    }
    
    if (Anton.food > Anton.salary * 0.2) {
        Anton.food = Anton.salary * 0.18;
    }
    
    Anton.bank.deposit.balance -= Anton.food;
}


void anton_medicines(const int month) {
    if (month == 1) {
        Anton.medicines *= 1 + inflation.medicines / 100;
    }
    
    if (Anton.health_status < 70) {
        Anton.bank.deposit.balance -= Anton.medicines;
    } else {
        Anton.bank.deposit.balance -= Anton.medicines / 2;
    }
}


void anton_entertainment(const int month) {
    if (month == 1) {
        Anton.entertainment *= 1 + inflation.entertainment / 100;
    }
    
    if (Anton.happiness > 80) {
        Anton.entertainment *= 0.8;
    } else if (Anton.happiness < 50) {
        Anton.entertainment *= 1.2;
    }
    
    Anton.bank.deposit.balance -= Anton.entertainment;
}


void anton_car(const int month) {
    if (month == 1) {
        Anton.car.gas *= 1 + inflation.gas / 100;
        Anton.car.value *= 1 + inflation.car / 100;
    }
    
    RUB gas_cost = Anton.car.gas;
    if (Anton.bank.deposit.balance < 100'000) {
        gas_cost *= 0.7;
    }
    
    Anton.bank.deposit.balance -= gas_cost;
}


void anton_car_maintenance(int month) {
    if (month == 6) {
        static RUB maintenance_fund = 0;
        maintenance_fund += Anton.car.maintenance_cost / 6;
        
        if (maintenance_fund >= Anton.car.maintenance_cost) {
            Anton.bank.deposit.balance -= Anton.car.maintenance_cost;
            maintenance_fund = 0;
        }
    }
}


void anton_flat(const int month) {
    if (month == 1) {
        Anton.flat.value *= 1 + inflation.flat / 100;
        Anton.flat.utilities *= 1 + inflation.flat / 100;
    }
    
    RUB utilities = Anton.flat.utilities;
    if (Anton.health_status > 80) {
        utilities *= 0.9;
    }
    
    Anton.bank.deposit.balance -= utilities;
}


void anton_pay_taxes(const int month) {
    if (month == 1) {
        RUB salarytax = Anton.salary * 12 * taxes.income_tax / 100;
        RUB cartax = Anton.car.value * taxes.property_tax / 100;
        RUB flattax = Anton.flat.value * taxes.property_tax / 100;
        
        RUB deductions = 0;
        if (Anton.family.children.size() > 0) {
            deductions += 1'400 * Anton.family.children.size() * 12;
        }
        if (Anton.insurance.has_health_insurance) {
            deductions += 15'000;
        }
        
        RUB total_tax = max(0LL, salarytax + cartax + flattax - deductions);
        Anton.bank.deposit.balance -= total_tax;
    }
}


RUB anton_capital() {
    RUB capital = Anton.bank.deposit.balance + Anton.car.value + Anton.flat.value + 
                  Anton.investments.stocks.cost + Anton.investments.bonds.cost;
    return capital;
}

//================================================================

void init_inflation() {
    inflation.salary = 10;
    inflation.food = 8;
    inflation.gas = 8;
    inflation.medicines = 7;
    inflation.entertainment = 7;
    inflation.car = 8;
    inflation.flat = 8;
    inflation.education = 10;
    inflation.healthcare = 12;
    inflation.utilities = 9;
}


void init_taxes() {
    taxes.income_tax = 13;
    taxes.property_tax = 0.1;
    taxes.capital_gains_tax = 13;
    taxes.dividend_tax = 9;
    taxes.business_tax = 15;
}


void init_alice() {
    Alice.name = "Alice";
    Alice.age = 25;
    Alice.salary = 120'000;
    Alice.food = 20'000;
    Alice.medicines = 10'000;
    Alice.entertainment = 15'000;
    Alice.health_status = 80;
    Alice.happiness = 70;
    Alice.is_employed = true;
    Alice.emergency_fund = 50'000;
    Alice.retirement_fund = 0;

    Alice.family.has_partner = true;
    Alice.family.married = true;
    Alice.family.partner_salary = 200'000;
    Alice.family.years_married = 3;
    
    Alice.bank.deposit.balance = 500'000;
    Alice.bank.deposit.procent = 16;
    Alice.bank.deposit.is_capitalized = true;
    Alice.bank.loyalty_points = 0;
    
    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;
    Alice.car.maintenance_cost = 30'000;
    Alice.car.brand = "Toyota";
    Alice.car.model = "Camry";
    Alice.car.year = 2020;
    Alice.car.mileage = 30000;
    Alice.car.is_leased = false;
    
    Alice.flat.value = 12'000'000;
    Alice.flat.utilities = 10'000;
    Alice.flat.rooms = 3;
    Alice.flat.floor = 5;
    Alice.flat.has_mortgage = false;
    
    Alice.insurance.has_health_insurance = true;
    Alice.insurance.health_insurance = 60'000;
    Alice.insurance.has_car_insurance = true;
    Alice.insurance.car_insurance = 50'000;
    Alice.insurance.has_flat_insurance = true;
    Alice.insurance.flat_insurance = 20'000;
    Alice.insurance.has_life_insurance = true;
    Alice.insurance.life_insurance = 30'000;
    Alice.insurance.has_travel_insurance = false;
    Alice.insurance.travel_insurance = 15'000;
    
    Alice.investments.stocks.count = 50;
    Alice.investments.stocks.cost = 500'000;
    Alice.investments.stocks.total_invested = 500'000;
    Alice.investments.bonds.count = 30;
    Alice.investments.bonds.cost = 300'000;
    Alice.investments.bonds.total_invested = 300'000;
    Alice.investments.crypto_balance = 50'000;
    Alice.investments.gold_balance = 100'000;
    Alice.investments.real_estate.value = 0;
    Alice.investments.real_estate.is_rented = false;
    Alice.investments.business.has_business = false;
    Alice.investments.business.business_value = 0;
    
    Alice.education.has_higher_education = true;
    Alice.education.degree = "Bachelor";
    Alice.education.is_studying = false;
    
    Alice.health_metrics.mental_health = 75;
    Alice.health_metrics.fitness_level = 60;
    Alice.health_metrics.gym_membership = 3000;
    Alice.health_metrics.has_therapy = false;
    Alice.health_metrics.therapy_cost = 0;
    
    Alice.lifestyle.travel_budget = 100'000;
    Alice.lifestyle.hobbies = {"reading", "sports"};
    Alice.lifestyle.hobby_expenses = 5'000;
    Alice.lifestyle.charity_donations = 2'000;
    Alice.lifestyle.has_pet = false;
    Alice.lifestyle.pet_expenses = 0;
    Alice.lifestyle.social_events_per_month = 2;
}


void init_anton() {
    Anton.age = 30;
    Anton.salary = 80'000;
    Anton.food = 12'000;
    Anton.medicines = 3'000;
    Anton.entertainment = 8'000;
    Anton.health_status = 90;
    Anton.happiness = 80;

    Anton.family.has_partner = true;
    Anton.family.married = true;
    Anton.family.partner_salary = 120'000;
    
    Anton.bank.deposit.balance = 500'000;
    Anton.bank.deposit.procent = 12;
    
    Anton.car.value = 1'200'000;
    Anton.car.gas = 8'000;
    Anton.car.maintenance_cost = 15'000;
    
    Anton.flat.value = 6'000'000;
    Anton.flat.utilities = 6'000;
    
    Anton.insurance.has_health_insurance = true;
    Anton.insurance.health_insurance = 30'000;
    Anton.insurance.has_car_insurance = true;
    Anton.insurance.car_insurance = 20'000;
    Anton.insurance.has_flat_insurance = true;
    Anton.insurance.flat_insurance = 10'000;
    
    Anton.investments.stocks.count = 100;
    Anton.investments.stocks.cost = 100'000;
    Anton.investments.bonds.count = 200;
    Anton.investments.bonds.cost = 200'000;
}


void print_results() {
    cout << "Alice:" << endl;
    cout << "Age: " << Alice.age << endl;
    cout << "Salary: " << Alice.salary << endl;
    cout << "Partner Salary: " << Alice.family.partner_salary << endl;
    cout << "Total Capital: " << alice_capital() << endl;
    cout << "Bank Deposit: " << Alice.bank.deposit.balance << endl;
    cout << "Stocks: " << Alice.investments.stocks.cost << endl;
    cout << "Bonds: " << Alice.investments.bonds.cost << endl;
    cout << "Crypto: " << Alice.investments.crypto_balance << endl;
    cout << "Gold: " << Alice.investments.gold_balance << endl;
    cout << "Car Value: " << Alice.car.value << endl;
    cout << "Flat Value: " << Alice.flat.value << endl;
    cout << "Emergency Fund: " << Alice.emergency_fund << endl;
    cout << "Retirement Fund: " << Alice.retirement_fund << endl;
    if (Alice.bank.credit.active) {
        cout << "Active Credit: " << Alice.bank.credit.amount << endl;
        cout << "Months Left: " << Alice.bank.credit.months_left << endl;
    } else {
        cout << "No active credits\n";
    }
    if (Alice.flat.has_mortgage) {
        cout << "Mortgage Balance: " << Alice.flat.mortgage_balance << endl;
    }
    cout << "Family:\n";
    cout << "Married: " << (Alice.family.married ? "Yes" : "No") << endl;
    cout << "Children: " << Alice.family.children.size() << endl;
    for (size_t i = 0; i < Alice.family.children.size(); i++) {
        cout << "    " << (i+1) << ". " << Alice.family.children[i].name 
             << " (Age: " << Alice.family.children[i].age 
             << ", Education Level: " << Alice.family.children[i].education_level << ")\n";
    }
    cout << "Health Status: " << Alice.health_status << "/100\n";
    cout << "Happiness: " << Alice.happiness << "/100\n";
    cout << "Mental Health: " << Alice.health_metrics.mental_health << "/100\n";
    cout << "Fitness Level: " << Alice.health_metrics.fitness_level << "/100\n";
    cout << "Monthly Expenses:\n";
    cout << "Food: " << Alice.food << endl;
    cout << "Medicines: " << Alice.medicines << endl;
    cout << "Entertainment: " << Alice.entertainment << endl;
    cout << "Gas: " << Alice.car.gas << endl;
    cout << "Utilities: " << Alice.flat.utilities << endl;
    cout << "Hobby Expenses: " << Alice.lifestyle.hobby_expenses << endl;
    cout << "Charity: " << Alice.lifestyle.charity_donations << endl;
    cout << "Investment Performance:\n";
    cout << "  - Total Stock Dividends: " << Alice.investments.stocks.total_dividends << endl;
    cout << "  - Total Bond Interest: " << Alice.investments.bonds.total_interest << endl;

    cout << endl << endl;

    cout << "Anton:" << endl;
    cout << "Age: " << Anton.age << endl;
    cout << "Salary: " << Anton.salary << endl;
    cout << "Partner Salary: " << Anton.family.partner_salary << endl;
    cout << "Total Capital: " << anton_capital() << endl;
    cout << "Bank Deposit: " << Anton.bank.deposit.balance << endl;
    cout << "Stocks: " << Anton.investments.stocks.cost << endl;
    cout << "Bonds: " << Anton.investments.bonds.cost << endl;
    cout << "Crypto: " << Anton.investments.crypto_balance << endl;
    cout << "Gold: " << Anton.investments.gold_balance << endl;
    cout << "Car Value: " << Anton.car.value << endl;
    cout << "Flat Value: " << Anton.flat.value << endl;
    cout << "Emergency Fund: " << Anton.emergency_fund << endl;
    cout << "Retirement Fund: " << Anton.retirement_fund << endl;
    if (Anton.bank.credit.active) {
        cout << "Active Credit: " << Anton.bank.credit.amount << endl;
        cout << "Months Left: " << Anton.bank.credit.months_left << endl;
    } else {
        cout << "No active credits\n";
    }
    if (Anton.flat.has_mortgage) {
        cout << "Mortgage Balance: " << Anton.flat.mortgage_balance << endl;
    }
    cout << "Family:\n";
    cout << "Married: " << (Anton.family.married ? "Yes" : "No") << endl;
    cout << "Children: " << Anton.family.children.size() << endl;
    for (size_t i = 0; i < Anton.family.children.size(); i++) {
        cout << "    " << (i+1) << ". " << Anton.family.children[i].name 
             << " (Age: " << Anton.family.children[i].age 
             << ", Education Level: " << Anton.family.children[i].education_level << ")\n";
    }
    cout << "Health Status: " << Anton.health_status << "/100\n";
    cout << "Happiness: " << Anton.happiness << "/100\n";
    cout << "Monthly Expenses:\n";
    cout << "Food: " << Anton.food << endl;
    cout << "Medicines: " << Anton.medicines << endl;
    cout << "Entertainment: " << Anton.entertainment << endl;
    cout << "Gas: " << Anton.car.gas << endl;
    cout << "Utilities: " << Anton.flat.utilities << endl;
    cout << "Hobby Expenses: " << Anton.lifestyle.hobby_expenses << endl;
    cout << "Charity: " << Anton.lifestyle.charity_donations << endl;
    
    cout << "\nSimulation completed\n";
}


void simulation() {
    srand(time(0));
    int month = 1;
    int year = 2026;
    
    while (!((month == 1) && (year == 2051))) {
        if (month == 1) {
            update_economy(year);
        }
        
        alice_salary(month, year);
        alice_deposit();
        alice_update_investments();
        alice_food(month);
        alice_car(month);
        alice_flat(month);
        alice_entertainment(month);
        alice_medicines(month);
        alice_car_maintenance(month);
        alice_pay_insurance(month);
        alice_pay_taxes(month);
        alice_children(month, year);
        alice_random_positive_event(month, year);
        alice_random_negative_event(month, year);
        alice_random_expenses();
        alice_update_health();
        alice_update_happiness();
        alice_credit_payment();
        alice_save_emergency_fund();
        alice_save_retirement();
        
        if (alice_capital() < 0) {
            alice_take_credit(-1 * alice_capital() + 50000, 24);
        }
        
        alice_save_history();


        anton_salary(month, year);
        anton_deposit();
        anton_food(month);
        anton_car(month);
        anton_flat(month);
        anton_pay_taxes(month);
        anton_pay_insurance(month);
        anton_car_maintenance(month);
        anton_entertainment(month);
        anton_medicines(month);
        anton_update_investments();
        anton_random_positive_event(month, year);
        anton_random_negative_event(month, year);
        anton_random_expenses();
        anton_update_health();
        anton_update_happiness();
        anton_children(month, year);
        anton_credit_payment();
        
        if (anton_capital() < 0) {
            anton_take_credit(-1 * anton_capital() + 100'000, 24);
        }
        

        month++;
        if (month == 13) {
            month = 1;
            year++;
            Alice.age++;
        }
    }
}


int main() {
    
    init_inflation();
    init_taxes();
    init_alice();
    init_anton();
    
    simulation();
    
    print_results();
    
    return 0;
}
