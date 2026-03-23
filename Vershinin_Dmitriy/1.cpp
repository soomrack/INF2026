#include <iostream>
#include <vector>
using namespace std;

using RUB = long long int;  // C++
using PERCENT = double;


struct Credit {
    RUB amount;
    RUB monthly_payment;
    PERCENT interest_rate;
    int months_left;
    bool active;
};


struct Deposit {
    RUB balance;
	PERCENT procent;
};


struct Bank {
    Credit credit;
    Deposit deposit;
};


struct Stocks{
    int count;
    RUB cost;
    PERCENT growth;
};


struct Bonds{
    int count;
    RUB cost;
    PERCENT growth;
};


struct Investments {
    Stocks stocks;
    Bonds bonds;
};


struct Insurance {
    RUB health_insurance;
    bool has_health_insurance;
    RUB car_insurance;
    bool has_car_insurance;
    RUB flat_insurance;
    bool has_flat_insurance;
};


struct Inflation {
    PERCENT salary;
    PERCENT food;
    PERCENT gas;
    PERCENT medicines;
    PERCENT entertainment;
    PERCENT car;
    PERCENT flat;
};
Inflation inflation;


struct Taxes {
    PERCENT income_tax;
    PERCENT property_tax;
};
Taxes taxes;


struct Car {
    RUB value;
    RUB gas;
    RUB maintenance_cost;
};


struct Flat {
    RUB value;
    RUB utilities;
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
};


struct Family {
    bool has_partner;
    RUB partner_salary;
    vector<Child> children;
    bool married;
};


struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    RUB medicines;
    RUB entertainment;
    int health_status;
    int happiness;
    int age;
    bool is_employed = true;
    Family family;
    Car car;
    Flat flat;
	Bank bank;
    Insurance insurance;
    Investments investments;
};
Person Alice;


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


void alice_have_child() {
    Child new_child;
    new_child.age = 0;
    new_child.education_level = 0;
    new_child.intelligence = 1 + rand() % 100;
    new_child.happiness_child = 80;
    new_child.has_scholarship = false;
    new_child.education_fund = 0;
    
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


void alice_update_children_expenses(Child child) {
    for (Child child : Alice.family.children) {
        child.monthly_expenses = calculate_child_expenses(child.age);
    }
}


void alice_children_expenses() {
    RUB total_children_expenses = 0;
    
    for (Child child : Alice.family.children) {
        total_children_expenses += child.monthly_expenses;
        
        if (child.education_level == 3 && child.has_scholarship) {
            total_children_expenses -= 5000;
        }
    }
    
    Alice.bank.deposit.balance -= total_children_expenses;
}


void alice_child_become_adult(int year) {
    for (auto it = Alice.family.children.begin(); it != Alice.family.children.end();) {
        if (it->age >= 22 && it->education_level >= 4) {
            Alice.food -= 8000;
            Alice.happiness = min(100, Alice.happiness + 15);
            
            it = Alice.family.children.erase(it);
        } else {
            ++it;
        }
    }
}


void handle_graduation(Child& child) {
    
    int choice = rand() % 3;
    
    switch(choice) {
        case 0:
            child.education_level = 2;
            break;
        case 1:
            child.education_level = 4;
            Alice.bank.deposit.balance += 30000;
            break;
    }
}


void apply_to_university(Child& child) {
    int admission_chance = child.intelligence;
    
    if (rand() % 100 < admission_chance) {
        child.has_scholarship = (child.intelligence > 85 && rand() % 2);
    } 
    else {
        child.education_level = 4;
    }
}


void update_academic_performance(Child& child) {
    float performance = (child.intelligence * 0.7 + child.happiness_child * 0.3) / 100;
    
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
}


void alice_children_growth(int year) {
    for (Child child : Alice.family.children) {
        child.age++;
        
        if (child.age == 7 && child.education_level == 0) {
            child.education_level = 1;
        } 
        else if (child.age == 17 && child.education_level == 1) {
            handle_graduation(child);
        }
        else if (child.age == 8 && child.education_level == 2) {
            child.education_level = 3;
            apply_to_university(child);
        }
        
        alice_update_children_expenses(child);
    }
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
        for (Child child : Alice.family.children) {
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
        if (month == 1 and year % 2 == 0){
            Alice.salary *= 1 + inflation.salary / 100;
        }

        Alice.bank.deposit.balance += Alice.salary;
    }
    else{
        if(rand() % 10 == 4) {
            Alice.is_employed = true;
            Alice.salary = 100'000 + rand() % 100'000;
        }
    }  
}


void alice_random_expenses() {
    RUB RandomExpenses = rand() % 100'000;
    Alice.bank.deposit.balance -= RandomExpenses;
};


void alice_random_positive_event(int month, int year) {
    int event = rand() % 300;
    
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
}

void alice_random_negative_event(int month, int year) {
    int event = rand() % 300;
    
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
    else if (event < 32 && Alice.is_employed) {
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
}


void alice_take_credit(RUB amount, int months) {
    Alice.bank.credit.amount += amount;
    Alice.bank.credit.months_left = months;
    Alice.bank.credit.monthly_payment = Alice.bank.credit.amount / months * (1 + Alice.bank.credit.interest_rate / 100);
    Alice.bank.credit.active = true;
    Alice.bank.deposit.balance += amount;
}


void alice_credit_payment() {
    if (Alice.bank.credit.active) {
        Alice.bank.deposit.balance -= Alice.bank.credit.monthly_payment;
        Alice.bank.credit.months_left--;
        if (Alice.bank.credit.months_left <= 0) {
            Alice.bank.credit.active = false;
        }
    }
}


void alice_update_stocks() {
    if (Alice.investments.stocks.count > 0) {
        Alice.investments.stocks.growth = (rand() % 40 - 20);
        Alice.investments.stocks.cost += Alice.investments.stocks.cost * Alice.investments.stocks.growth / 100;
    }
}


void alice_update_bonds() {
    if (Alice.investments.bonds.count > 0) {
        Alice.investments.bonds.growth = (rand() % 40 - 20);
        Alice.investments.bonds.cost += Alice.investments.bonds.cost * Alice.investments.bonds.growth / 100;
    }
}


void alice_dividends_stocks(){
    if (Alice.investments.stocks.count > 0) {
        RUB dividends = Alice.investments.stocks.cost * (5 + rand() % 5) / 100;
        Alice.bank.deposit.balance += dividends;
    }
}


void alice_dividends_bonds(){
    if (Alice.investments.bonds.count > 0) {
        RUB dividends = Alice.investments.bonds.cost * (3 + rand() % 3) / 100;
        Alice.bank.deposit.balance += dividends;
    }
}


void alice_update_investments() {
    alice_update_stocks();
    alice_update_bonds();
    alice_dividends_stocks();
    alice_dividends_bonds();
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
    return insurance_pay;
}


void alice_pay_insurance(int month) {
    if (month == 1) {
        RUB insurance_pay = alice_count_insurance_pay();
        
        if (Alice.bank.deposit.balance >= insurance_pay) {
            Alice.bank.deposit.balance -= insurance_pay;
        } else {
            if (rand() % 2) {
                Alice.insurance.has_health_insurance = false;
            }
        }
    }
}


void alice_update_health() {
    if (Alice.food > 20000) {
        Alice.health_status = min(100, Alice.health_status + 2);
    }
    
    if (Alice.age > 60) {
        Alice.health_status = max(0, Alice.health_status - 1);
    }
}


void alice_update_happiness() {
    if (Alice.is_employed) {
        Alice.happiness = max(0, Alice.happiness - 5);
    }
    
    if (Alice.entertainment > 15000) {
        Alice.happiness = min(100, Alice.happiness + 5);
    }
    
    if (Alice.health_status < 50) {
        Alice.happiness = max(0, Alice.happiness - 10);
    }
}


void alice_deposit() {
    Alice.bank.deposit.balance *= 1 + Alice.bank.deposit.procent / 12.0 / 100.0;
}


void alice_food(const int month) {
    if (month == 1){
        Alice.food *= 1 + inflation.food / 100;
    }
    Alice.bank.deposit.balance -= Alice.food;
}


void alice_medicines(const int month) {
    if (month == 1){
        Alice.medicines *= 1 + inflation.medicines / 100;
    }
    Alice.bank.deposit.balance -= Alice.medicines;
}


void alice_entertainment(const int month) {
    if (month == 1){
        Alice.entertainment *= 1 + inflation.entertainment / 100;
    }
    Alice.bank.deposit.balance -= Alice.entertainment;
}


void alice_car(const int month) {
    if (month == 1){
        Alice.car.gas *= 1 + inflation.gas / 100;
        Alice.car.value *= 1 + inflation.car / 100;
    }
    Alice.bank.deposit.balance -= Alice.car.gas;
}


void alice_car_maintenance(int month) {
    if (month == 6) {
        Alice.bank.deposit.balance -= Alice.car.maintenance_cost;
    }
}

void alice_flat(const int month) {
    if (month == 1){
        Alice.flat.value *= 1 + inflation.flat / 100;
        Alice.flat.utilities *= 1 + inflation.flat / 100;
    }
    Alice.bank.deposit.balance -= Alice.flat.utilities;
}


void alice_pay_taxes(const int month) {
    if (month == 1){
    RUB salarytax = Alice.salary * 12 * taxes.income_tax / 100;
    RUB cartax = Alice.car.value * taxes.property_tax / 100;
    RUB flattax = Alice.flat.value * taxes.property_tax / 100;
    Alice.bank.deposit.balance -= salarytax + cartax + flattax;
    }
}


RUB alice_capitaL() {
    RUB capital = Alice.bank.deposit.balance + Alice.car.value + Alice.flat.value + Alice.investments.stocks.cost + Alice.investments.bonds.cost;
    return capital;
}



void init_inflation() {
     inflation.salary = 10;
    inflation.food = 8;
    inflation.gas = 8;
    inflation.medicines = 7;
    inflation.entertainment = 7;
    inflation.car = 8;
    inflation.flat = 8;
}


void init_taxes() {
    taxes.income_tax = 13;
    taxes.property_tax = 0.1;
}


void init_alice() {
    Alice.age = 25;
    Alice.salary = 120'000;
    Alice.food = 20'000;
    Alice.medicines = 10'000;
    Alice.entertainment = 15'000;
    Alice.health_status = 80;
    Alice.happiness = 70;

    Alice.family.has_partner = true;
    Alice.family.married = true;
    Alice.family.partner_salary = 200'000;
    
    Alice.bank.deposit.balance = 50'000;
    Alice.bank.deposit.procent = 16;
    
    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;
    
    Alice.flat.value = 12'000'000;
    Alice.flat.utilities = 10'000;
    
    Alice.insurance.has_health_insurance = true;
    Alice.insurance.health_insurance = 60'000;
    Alice.insurance.has_car_insurance = true;
    Alice.insurance.car_insurance = 50'000;
    Alice.insurance.has_flat_insurance = true;
    Alice.insurance.flat_insurance = 20'000;
    
    Alice.investments.stocks.count = 50;
    Alice.investments.stocks.cost = 50'000;
    Alice.investments.bonds.count = 30;
    Alice.investments.bonds.cost = 30'000;
}


void print_results() {
    cout << "Salary = " << Alice.salary << endl;
    cout << "Capital = " << alice_capitaL() << endl;
    cout << "Credit = " << Alice.bank.credit.amount << endl;
    cout << "Children = " << Alice.family.children.size() << endl;
}


void simulation() {
    srand(time(0));
    int month = 1;
    int year = 2026;
    
    while ( !((month == 1) && (year == 2031)) ) {
        alice_salary(month, year);
        alice_deposit();
        alice_food(month);
        alice_car(month);
        alice_flat(month);
        alice_pay_taxes(month);
        alice_pay_insurance(month);
        alice_car_maintenance(month);
        alice_entertainment(month);
        alice_medicines(month);
        alice_update_investments();
        alice_random_positive_event(month, year);
        alice_random_negative_event(month, year);
        alice_random_expenses();
        alice_update_health();
        alice_update_happiness();
        alice_children(month, year);
        alice_credit_payment();
        if (alice_capitaL() < 0) {
            alice_take_credit(-1 * alice_capitaL(), 24);
        }
        
        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}


int main()
{
    init_inflation();

    init_taxes();

    init_alice();
    
    simulation();
    
    print_results();
}
