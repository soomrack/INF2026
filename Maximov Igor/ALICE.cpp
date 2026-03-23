#include <stdio.h>

using RUB = long long int; 

struct Bank 
{
    RUB account;         
    RUB deposit;         
    double interest_rate;
};


struct Car {
    RUB value; 
    RUB gas;   
};


struct Apartment {
    RUB internet;  
    RUB tv;         
    RUB mobile;     
    RUB utilities;  
};


struct Bar {
    int is_open;           
    RUB food_supplies;     
    RUB furniture_repair;  
};


struct Insurance {
    RUB car_insurance;   
    RUB health_insurance; 
    RUB home_insurance;   
};


struct Loan {
    RUB principal;       
    RUB remaining;       
    double interest_rate; 
    int active;          
};


struct Mortgage {
    RUB principal;        
    RUB remaining;        
    double interest_rate; 
    int active;           
    int months_left;      
};


struct Person
{
    RUB salary;         
    RUB second_salary;  
    RUB food;           
    RUB hamster;        
    RUB rent;          
    RUB clothing;       
    RUB entertainment;  
    RUB education;      
    RUB health;        
    struct Car car;    
    struct Bank bank;   
    struct Bank salary_bank;   
    struct Bank business_bank; 

   
    struct Insurance insurance;   
    struct Loan loan;             
                   
};


struct PersonPeter
{
    RUB salary;         
    RUB freelance1;     
    RUB freelance2;     
    RUB food;          
    RUB dog;            
    RUB clothing;       
    RUB entertainment;  
    RUB education;      
    RUB health;        
    struct Car car;     
    struct Bank bank;   
    struct Apartment apt; 
    struct Insurance insurance; 
    struct Mortgage mortgage;   
};


struct FamilyBudget {
    RUB account;        
    RUB deposit;        
    double interest_rate; 
};


struct Person Alice;
struct Apartment Alice_apt;
struct Bar Alice_bar;         
struct PersonPeter Peter;      
struct FamilyBudget Family;   
int married = 0;              


void alice_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) {
        Alice.salary *= 1.5;   
    }
    Alice.salary_bank.account += Alice.salary;
}


void alice_second_salary(const int month, const int year) {
    if (!Alice_bar.is_open) {
        Alice.salary_bank.account += Alice.second_salary;
    }
}


void print_result(){
    printf("\n=== Счета Alice ===\n");
    printf("Personal account = %lld\n", Alice.bank.account);
    printf("Personal deposit = %lld\n", Alice.bank.deposit);
    printf("Salary account = %lld\n", Alice.salary_bank.account);
    printf("Salary deposit = %lld\n", Alice.salary_bank.deposit);
    printf("Business account = %lld\n", Alice.business_bank.account);
    printf("Business deposit = %lld\n", Alice.business_bank.deposit);
    printf("Car value = %lld\n", Alice.car.value);
    if (Alice.loan.active) {
        printf("Loan remaining = %lld (interest %.2f%%)\n", Alice.loan.remaining, Alice.loan.interest_rate);
    } else {
        printf("Loan: none\n");
    }
    printf("Total capital = %lld\n", 
           Alice.bank.account + Alice.bank.deposit + 
           Alice.salary_bank.account + Alice.salary_bank.deposit +
           Alice.business_bank.account + Alice.business_bank.deposit +
           Alice.car.value);
}


void print_result_peter() {
    printf("\n=== Peter's Accounts ===\n");
    printf("Bank account = %lld\n", Peter.bank.account);
    printf("Bank deposit = %lld\n", Peter.bank.deposit);
    printf("Car value = %lld\n", Peter.car.value);
    if (Peter.mortgage.active) {
        printf("Mortgage remaining = %lld (interest %.2f%%, months left %d)\n",
               Peter.mortgage.remaining, Peter.mortgage.interest_rate, Peter.mortgage.months_left);
    } else {
        printf("Mortgage: none\n");
    }
    printf("Total capital = %lld\n", 
           Peter.bank.account + Peter.bank.deposit + Peter.car.value);
}




void family_interest() {
    RUB interest = Family.deposit * (Family.interest_rate / 12.0 / 100.0);
    Family.account += interest;
}


void family_contributions() {
    
    RUB alice_contrib = 100000;
    RUB peter_contrib = 100000;

    
    if (Alice.salary_bank.account >= alice_contrib) {
        Alice.salary_bank.account -= alice_contrib;
    } else {
        
        if (Alice.bank.account >= alice_contrib) {
            Alice.bank.account -= alice_contrib;
        } else {
            RUB from_deposit = alice_contrib - Alice.bank.account;
            if (Alice.bank.deposit >= from_deposit) {
                Alice.bank.deposit -= from_deposit;
                Alice.bank.account = 0;
            } else {
                printf("Warning: Not enough money for Alice's contribution to family budget (need %lld)\n", alice_contrib);
                alice_contrib = Alice.bank.account + Alice.bank.deposit;
                Alice.bank.account = 0;
                Alice.bank.deposit = 0;
            }
        }
    }
    Family.account += alice_contrib;

    
    if (Peter.bank.account >= peter_contrib) {
        Peter.bank.account -= peter_contrib;
    } else {
        RUB from_deposit = peter_contrib - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for Peter's contribution to family budget (need %lld)\n", peter_contrib);
            peter_contrib = Peter.bank.account + Peter.bank.deposit;
            Peter.bank.account = 0;
            Peter.bank.deposit = 0;
        }
    }
    Family.account += peter_contrib;
}


void family_mortgage_payment() {
    if (!Peter.mortgage.active) return;

    int months_left = Peter.mortgage.months_left;
    RUB remaining = Peter.mortgage.remaining;
    double rate = Peter.mortgage.interest_rate;

    RUB monthly_payment = (RUB)(remaining * (rate / 12.0 / 100.0) + remaining / months_left);
    if (monthly_payment > remaining) monthly_payment = remaining;

    RUB need = monthly_payment;
    if (Family.account >= need) {
        Family.account -= need;
        Peter.mortgage.remaining -= need;
        Peter.mortgage.months_left--;
    } else {
        RUB from_deposit = need - Family.account;
        if (Family.deposit >= from_deposit) {
            Family.deposit -= from_deposit;
            Family.account = 0;
            Peter.mortgage.remaining -= need;
            Peter.mortgage.months_left--;
        } else {
            printf("Warning: Нет денег в семейном бюджете для оплаты ипотеки (нужно %lld)\n", need);
            RUB paid = Family.account + Family.deposit;
            Peter.mortgage.remaining -= paid;
            Family.account = 0;
            Family.deposit = 0;
            Peter.mortgage.months_left = 0;
        }
    }

    if (Peter.mortgage.remaining <= 0) {
        Peter.mortgage.active = 0;
        Peter.mortgage.remaining = 0;
        printf("Ипотека полностью выплачена!\n");
    } else {
        printf("Ипотека оплачена из семейного бюджета: %lld, осталось выплатить: %lld, осталось месяцев: %d\n", need, Peter.mortgage.remaining, Peter.mortgage.months_left);
    }
}


void family_loan_payment() {
    if (!Alice.loan.active) return;

   
    RUB monthly_payment = (RUB)(Alice.loan.remaining * (Alice.loan.interest_rate / 12.0 / 100.0 + 1.0 / 60.0));
    if (monthly_payment > Alice.loan.remaining) monthly_payment = Alice.loan.remaining;
    RUB need = monthly_payment;

    if (Family.account >= need) {
        Family.account -= need;
        Alice.loan.remaining -= need;
    } else {
        RUB from_deposit = need - Family.account;
        if (Family.deposit >= from_deposit) {
            Family.deposit -= from_deposit;
            Family.account = 0;
            Alice.loan.remaining -= need;
        } else {
            printf("Warning: Нет денег в семейном бюджете для оплаты кредите (нужно %lld)\n", need);
            RUB paid = Family.account + Family.deposit;
            Alice.loan.remaining -= paid;
            Family.account = 0;
            Family.deposit = 0;
        }
    }

    if (Alice.loan.remaining <= 0) {
        Alice.loan.active = 0;
        Alice.loan.remaining = 0;
        printf("Кредит полностью погашен из семейного бюджета!\n");
    } else {
        printf("Кредит оплачен из семейного бюджета: %lld, осталось: %lld\n", need, Alice.loan.remaining);
    }
}


void family_transfer_to_deposit() {
    Family.deposit += Family.account;
    Family.account = 0;
}


void alice_salary_bank_interest(){
    RUB interest = Alice.salary_bank.deposit * (Alice.salary_bank.interest_rate / 12.0 / 100.0);
    Alice.salary_bank.account += interest;
}


void alice_business_bank_interest(){
    RUB interest = Alice.business_bank.deposit * (Alice.business_bank.interest_rate / 12.0 / 100.0);
    Alice.business_bank.account += interest;
}


void alice_fund_personal() {
    RUB total_expenses = Alice.food + Alice.car.gas + Alice.hamster + Alice.rent +
                         Alice.clothing + Alice.entertainment + Alice.education + Alice.health +
                         (Alice_apt.internet + Alice_apt.tv + Alice_apt.mobile + Alice_apt.utilities);
    if (Alice.salary_bank.account >= total_expenses) {
        Alice.salary_bank.account -= total_expenses;
        Alice.bank.account += total_expenses;
    } else {
        printf("Warning: Not enough money in salary account to fund personal expenses (need %lld, have %lld)\n",
               total_expenses, Alice.salary_bank.account);
        Alice.bank.account += Alice.salary_bank.account;
        Alice.salary_bank.account = 0;
    }
}


void alice_food(){
    RUB need = Alice.food;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for food (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
}


void alice_car(){
    RUB need = Alice.car.gas;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for car gas (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
}


void alice_hamster(){
    RUB need = Alice.hamster;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for hamster (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
}


void alice_rent(){
    RUB need = Alice.rent;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for rent (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
}


void alice_repair(){
    RUB repair_cost = 1'000'000;
    if (Alice.bank.deposit >= repair_cost) {
        Alice.bank.deposit -= repair_cost;
        printf("Ремонт выполнен, потрачено: %lld\n", repair_cost);
    } else {
        printf("Warning: Not enough money for repair (need %lld, have %lld on deposit)\n",
               repair_cost, Alice.bank.deposit);
        
        Alice.bank.deposit = 0;
    }
}


void alice_clothing() {
    RUB need = Alice.clothing;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for clothing (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
}


void alice_entertainment() {
    RUB need = Alice.entertainment;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for entertainment (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
}


void alice_education() {
    RUB need = Alice.education;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for education (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
}


void alice_health() {
    RUB need = Alice.health;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for health (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
}


void alice_apartment_expenses() {
    RUB need = Alice_apt.internet + Alice_apt.tv + Alice_apt.mobile + Alice_apt.utilities;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for apartment expenses (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
}


void alice_salary_transfer_to_deposit(){
    Alice.salary_bank.deposit += Alice.salary_bank.account;
    Alice.salary_bank.account = 0;
}


void alice_business_transfer_to_deposit(){
    Alice.business_bank.deposit += Alice.business_bank.account;
    Alice.business_bank.account = 0;
}




void alice_bar_monthly() {
    if (!Alice_bar.is_open) return;

    RUB revenue = 280 * 2000;
    RUB expenses = 3 * 100'000 + 50'000 + Alice_bar.food_supplies;
    RUB net = revenue - expenses;
    if (net >= 0) {
        Alice.business_bank.account += net;
    } else {
        
        RUB loss = -net;
        if (Alice.business_bank.account >= loss) {
            Alice.business_bank.account -= loss;
        } else {
            RUB from_deposit = loss - Alice.business_bank.account;
            if (Alice.business_bank.deposit >= from_deposit) {
                Alice.business_bank.deposit -= from_deposit;
                Alice.business_bank.account = 0;
            } else {
                printf("Warning: Not enough money in business bank to cover loss (need %lld, have %lld on account, %lld on deposit)\n",
                       loss, Alice.business_bank.account, Alice.business_bank.deposit);
                Alice.business_bank.deposit = 0;
                Alice.business_bank.account = 0;
            }
        }
    }
}


void alice_bar_furniture_repair() {
    if (!Alice_bar.is_open) return;
    RUB need = Alice_bar.furniture_repair;
    if (Alice.business_bank.account >= need) {
        Alice.business_bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.business_bank.account;
        if (Alice.business_bank.deposit >= from_deposit) {
            Alice.business_bank.deposit -= from_deposit;
            Alice.business_bank.account = 0;
        } else {
            printf("Warning: Not enough money for furniture repair (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.business_bank.account, Alice.business_bank.deposit);
            Alice.business_bank.deposit = 0;
            Alice.business_bank.account = 0;
        }
    }
}


void alice_open_bar() {
    RUB needed = 5'000'000;
    if (Alice.bank.deposit >= needed) {
        Alice.bank.deposit -= needed;
        Alice.business_bank.account = needed;
        
        RUB opening_cost = 3'500'000;
        if (Alice.business_bank.account >= opening_cost) {
            Alice.business_bank.account -= opening_cost;
        } else {
            
            RUB from_deposit = opening_cost - Alice.business_bank.account;
            if (Alice.business_bank.deposit >= from_deposit) {
                Alice.business_bank.deposit -= from_deposit;
                Alice.business_bank.account = 0;
            } else {
                printf("Critical: Not enough money to cover opening costs after transfer!\n");
                Alice.business_bank.deposit = 0;
                Alice.business_bank.account = 0;
            }
        }
        Alice_bar.food_supplies = 200'000;   
        Alice_bar.furniture_repair = 500'000; 
        Alice_bar.is_open = 1;
        printf("\n=== Bar opened! ===\n");
        printf("Transferred 5,000,000 from personal deposit.\n");
        printf("Spent 3,500,000 on opening. Business account left: %lld\n", Alice.business_bank.account);
        printf("Set monthly food supplies: %lld, yearly furniture repair: %lld\n",
               Alice_bar.food_supplies, Alice_bar.furniture_repair);
    } else {
        printf("Warning: Not enough money on personal deposit to open bar in 2034 (need 5,000,000, have %lld)\n", 
               Alice.bank.deposit);
    }
}



void alice_insurance() {
    RUB need = Alice.insurance.car_insurance + 
               Alice.insurance.health_insurance + 
               Alice.insurance.home_insurance;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for insurance (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
    printf("Insurance paid: %lld\n", need);
}


void alice_vacation() {
    RUB need = 150000; 
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for vacation (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
    printf("Vacation spent: %lld\n", need);
}


void alice_christmas_bonus() {
    RUB bonus = Alice.salary * 0.5; 
    Alice.salary_bank.account += bonus;
    printf("Christmas bonus: %lld\n", bonus);
}

void alice_new_car() {
    
    RUB old_value = Alice.car.value;
    Alice.bank.deposit += old_value;
    printf("Old car sold for %lld\n", old_value);
    
    RUB new_car_cost = 3'500'000;
    if (Alice.bank.deposit >= new_car_cost) {
        Alice.bank.deposit -= new_car_cost;
        Alice.car.value = new_car_cost;
        printf("New car bought for %lld\n", new_car_cost);
    } else {
        printf("Warning: Not enough deposit to buy new car (need %lld, have %lld)\n",
               new_car_cost, Alice.bank.deposit);
        
        Alice.car.value = Alice.bank.deposit;
        Alice.bank.deposit = 0;
        printf("Bought a cheaper car for %lld\n", Alice.car.value);
    }
}


void alice_take_loan() {
    if (!Alice.loan.active) {
        RUB loan_amount = 2'000'000;
        Alice.loan.principal = loan_amount;
        Alice.loan.remaining = loan_amount;
        Alice.loan.interest_rate = 10.0;
        Alice.loan.active = 1;
        
        Alice.bank.deposit += loan_amount;
        printf("Loan taken: %lld at %.2f%% yearly\n", loan_amount, Alice.loan.interest_rate);
    } else {
        printf("Loan already active, cannot take another.\n");
    }
}


void alice_repay_loan() {
    if (!Alice.loan.active) return;
    
    RUB monthly_payment = (RUB)(Alice.loan.remaining * (Alice.loan.interest_rate / 12.0 / 100.0 + 1.0 / 60.0));
    if (monthly_payment > Alice.loan.remaining) monthly_payment = Alice.loan.remaining;
    RUB need = monthly_payment;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
        Alice.loan.remaining -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
            Alice.loan.remaining -= need;
        } else {
            printf("Warning: Not enough money for loan payment (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            
            RUB paid = Alice.bank.account + Alice.bank.deposit;
            Alice.loan.remaining -= paid;
            Alice.bank.account = 0;
            Alice.bank.deposit = 0;
        }
    }
    if (Alice.loan.remaining <= 0) {
        Alice.loan.active = 0;
        Alice.loan.remaining = 0;
        printf("Loan fully repaid!\n");
    } else {
        printf("Loan payment: %lld, remaining: %lld\n", need, Alice.loan.remaining);
    }
}


void alice_property_tax() {
    RUB total_assets = Alice.car.value + Alice.bank.deposit + Alice.salary_bank.deposit + Alice.business_bank.deposit;
    RUB tax = (RUB)(total_assets * 0.005); 
    if (tax < 0) tax = 0;
    RUB need = tax;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for property tax (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
    printf("Property tax paid: %lld\n", tax);
}


void alice_charity() {
    RUB need = 20000;
    if (Alice.bank.account >= need) {
        Alice.bank.account -= need;
    } else {
        RUB from_deposit = need - Alice.bank.account;
        if (Alice.bank.deposit >= from_deposit) {
            Alice.bank.deposit -= from_deposit;
            Alice.bank.account = 0;
        } else {
            printf("Warning: Not enough money for charity (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Alice.bank.account, Alice.bank.deposit);
            Alice.bank.deposit = 0;
            Alice.bank.account = 0;
        }
    }
    printf("Charity donation: %lld\n", need);
}


void alice_inheritance() {
    RUB inheritance = 500'000;
    Alice.bank.deposit += inheritance;
    printf("Inheritance received: %lld\n", inheritance);
}

void alice_birthday() {
    RUB gift = 10 * 10000;
    RUB withdraw = 100000;
    Alice.bank.account += gift;
    if (Alice.bank.deposit >= withdraw) {
        Alice.bank.deposit -= withdraw;
    } else {
        printf("Warning: Not enough money on personal deposit for birthday (need 100000, have %lld)\n",
               Alice.bank.deposit);
        Alice.bank.deposit = 0;
    }
}

// --- Функции Питера ---

void peter_salary(const int month, const int year) {
    if ((month == 8) && (year == 2026)) {
        Peter.salary *= 1.5;   
    }
    Peter.bank.account += Peter.salary;
}


void peter_freelance() {
    Peter.bank.account += Peter.freelance1 + Peter.freelance2;
}




void peter_food(){
    RUB need = Peter.food;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for food (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
}


void peter_car(){
    RUB need = Peter.car.gas;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for car gas (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
}


void peter_dog(){
    RUB need = Peter.dog;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for dog (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
}


void peter_clothing() {
    RUB need = Peter.clothing;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for clothing (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
}


void peter_entertainment() {
    RUB need = Peter.entertainment;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for entertainment (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
}

void peter_education() {
    RUB need = Peter.education;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for education (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
}


void peter_health() {
    RUB need = Peter.health;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for health (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
}


void peter_apartment_expenses() {
    RUB need = Peter.apt.internet + Peter.apt.tv + Peter.apt.mobile + Peter.apt.utilities;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for apartment expenses (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
}


void peter_mortgage_payment() {
    if (!Peter.mortgage.active) return;

    int months_left = Peter.mortgage.months_left;
    if (months_left <= 0) {
        Peter.mortgage.active = 0;
        return;
    }

    RUB remaining = Peter.mortgage.remaining;
    double rate = Peter.mortgage.interest_rate;

    RUB monthly_payment = (RUB)(remaining * (rate / 12.0 / 100.0) + remaining / months_left);
    if (monthly_payment > remaining) monthly_payment = remaining;

    RUB need = monthly_payment;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
        Peter.mortgage.remaining -= need;
        Peter.mortgage.months_left--;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
            Peter.mortgage.remaining -= need;
            Peter.mortgage.months_left--;
        } else {
            printf("Warning: Not enough money for mortgage payment (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            RUB paid = Peter.bank.account + Peter.bank.deposit;
            Peter.mortgage.remaining -= paid;
            Peter.bank.account = 0;
            Peter.bank.deposit = 0;
            Peter.mortgage.months_left = 0;
        }
    }

    if (Peter.mortgage.remaining <= 0) {
        Peter.mortgage.active = 0;
        Peter.mortgage.remaining = 0;
        printf("Mortgage fully repaid!\n");
    } else {
        printf("Mortgage payment: %lld, remaining: %lld, months left: %d\n", need, Peter.mortgage.remaining, Peter.mortgage.months_left);
    }
}


void peter_insurance() {
    RUB need = Peter.insurance.car_insurance + 
               Peter.insurance.health_insurance + 
               Peter.insurance.home_insurance;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for insurance (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
    printf("Peter's insurance paid: %lld\n", need);
}


void peter_vacation() {
    RUB need = 150000; 
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for vacation (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
    printf("Peter's vacation spent: %lld\n", need);
}


void peter_christmas_bonus() {
    RUB bonus = Peter.salary * 0.5;
    Peter.bank.account += bonus;
    printf("Peter's Christmas bonus: %lld\n", bonus);
}


void peter_charity() {
    RUB need = 20000;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for charity (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
    printf("Peter's charity donation: %lld\n", need);
}


void peter_inheritance() {
    RUB inheritance = 500'000;
    Peter.bank.deposit += inheritance;
    printf("Peter's inheritance received: %lld\n", inheritance);
}


void peter_property_tax() {
    RUB total_assets = Peter.car.value + Peter.bank.deposit;
    RUB tax = (RUB)(total_assets * 0.005);
    if (tax < 0) tax = 0;
    RUB need = tax;
    if (Peter.bank.account >= need) {
        Peter.bank.account -= need;
    } else {
        RUB from_deposit = need - Peter.bank.account;
        if (Peter.bank.deposit >= from_deposit) {
            Peter.bank.deposit -= from_deposit;
            Peter.bank.account = 0;
        } else {
            printf("Warning: Not enough money for property tax (need %lld, have %lld on account, %lld on deposit)\n",
                   need, Peter.bank.account, Peter.bank.deposit);
            Peter.bank.deposit = 0;
            Peter.bank.account = 0;
        }
    }
    printf("Peter's property tax paid: %lld\n", tax);
}


void peter_birthday() {
    RUB gift = 10 * 10000;
    RUB withdraw = 100000;
    Peter.bank.account += gift;
    if (Peter.bank.deposit >= withdraw) {
        Peter.bank.deposit -= withdraw;
    } else {
        printf("Warning: Not enough money on personal deposit for birthday (need 100000, have %lld)\n",
               Peter.bank.deposit);
        Peter.bank.deposit = 0;
    }
}


void peter_new_car() {
    RUB old_value = Peter.car.value;
    Peter.bank.deposit += old_value;
    printf("Peter's old car sold for %lld\n", old_value);
    RUB new_car_cost = 3'500'000;
    if (Peter.bank.deposit >= new_car_cost) {
        Peter.bank.deposit -= new_car_cost;
        Peter.car.value = new_car_cost;
        printf("Peter's new car bought for %lld\n", new_car_cost);
    } else {
        printf("Warning: Not enough deposit to buy new car (need %lld, have %lld)\n",
               new_car_cost, Peter.bank.deposit);
        Peter.car.value = Peter.bank.deposit;
        Peter.bank.deposit = 0;
        printf("Bought a cheaper car for %lld\n", Peter.car.value);
    }
}

// --- Инициализация

void apply_inflation(){
    Alice.salary = Alice.salary * 106 / 100;
    Alice.second_salary = Alice.second_salary * 106 / 100;
    Alice.food = Alice.food * 106 / 100;
    Alice.car.gas = Alice.car.gas * 106 / 100;
    Alice.car.value = Alice.car.value * 106 / 100;
    Alice.hamster = Alice.hamster * 106 / 100;
    Alice.rent = Alice.rent * 106 / 100;
    Alice.clothing = Alice.clothing * 106 / 100;
    Alice.entertainment = Alice.entertainment * 106 / 100;
    Alice.education = Alice.education * 106 / 100;
    Alice.health = Alice.health * 106 / 100;
    Alice_apt.internet = Alice_apt.internet * 106 / 100;
    Alice_apt.tv = Alice_apt.tv * 106 / 100;
    Alice_apt.mobile = Alice_apt.mobile * 106 / 100;
    Alice_apt.utilities = Alice_apt.utilities * 106 / 100;
    Alice.insurance.car_insurance = Alice.insurance.car_insurance * 106 / 100;
    Alice.insurance.health_insurance = Alice.insurance.health_insurance * 106 / 100;
    Alice.insurance.home_insurance = Alice.insurance.home_insurance * 106 / 100;
}


void apply_inflation_peter(){
    Peter.salary = Peter.salary * 106 / 100;
    Peter.freelance1 = Peter.freelance1 * 106 / 100;
    Peter.freelance2 = Peter.freelance2 * 106 / 100;
    Peter.food = Peter.food * 106 / 100;
    Peter.car.gas = Peter.car.gas * 106 / 100;
    Peter.car.value = Peter.car.value * 106 / 100;
    Peter.dog = Peter.dog * 106 / 100;
    Peter.clothing = Peter.clothing * 106 / 100;
    Peter.entertainment = Peter.entertainment * 106 / 100;
    Peter.education = Peter.education * 106 / 100;
    Peter.health = Peter.health * 106 / 100;
    Peter.apt.internet = Peter.apt.internet * 106 / 100;
    Peter.apt.tv = Peter.apt.tv * 106 / 100;
    Peter.apt.mobile = Peter.apt.mobile * 106 / 100;
    Peter.apt.utilities = Peter.apt.utilities * 106 / 100;
    Peter.insurance.car_insurance = Peter.insurance.car_insurance * 106 / 100;
    Peter.insurance.health_insurance = Peter.insurance.health_insurance * 106 / 100;
    Peter.insurance.home_insurance = Peter.insurance.home_insurance * 106 / 100;
}


void Alice_init() {
    Alice.bank.account = 0;
    Alice.bank.deposit = 0;
    Alice.bank.interest_rate = 14.5; 

    Alice.salary_bank.account = 0;
    Alice.salary_bank.deposit = 0;
    Alice.salary_bank.interest_rate = 12.5;

    Alice.business_bank.account = 0;
    Alice.business_bank.deposit = 0;
    Alice.business_bank.interest_rate = 16.5;

    Alice.salary = 100'000;
    Alice.second_salary = 150'000;
    Alice.food = 20'000;
    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;
    Alice.hamster = 5'000;
    Alice.rent = 50'000;
    Alice.clothing = 10'000;
    Alice.entertainment = 8'000;
    Alice.education = 5'000;
    Alice.health = 6'000;

    Alice_apt.internet = 1'500;
    Alice_apt.tv = 1'000;
    Alice_apt.mobile = 1'200;
    Alice_apt.utilities = 7'000;

    Alice_bar.is_open = 0;
    Alice_bar.food_supplies = 0;
    Alice_bar.furniture_repair = 0;

    Alice.insurance.car_insurance = 30'000;  
    Alice.insurance.health_insurance = 40'000;
    Alice.insurance.home_insurance = 20'000;
    Alice.loan.active = 0;
    Alice.loan.principal = 0;
    Alice.loan.remaining = 0;
    Alice.loan.interest_rate = 0.0;
}  


void Peter_init() {
  
    Peter.bank.account = 0;
    Peter.bank.deposit = 0;
    Peter.bank.interest_rate = 12.0; 

  
    Peter.salary = 120'000;       
    Peter.freelance1 = 30'000;    
    Peter.freelance2 = 40'000;    

    
    Peter.food = 25'000;
    Peter.dog = 8'000;
    Peter.clothing = 12'000;
    Peter.entertainment = 10'000;
    Peter.education = 6'000;
    Peter.health = 7'000;

    
    Peter.car.value = 2'200'000;
    Peter.car.gas = 18'000;

    
    Peter.apt.internet = 1'500;
    Peter.apt.tv = 1'000;
    Peter.apt.mobile = 1'200;
    Peter.apt.utilities = 8'000;

    
    Peter.insurance.car_insurance = 35'000;
    Peter.insurance.health_insurance = 45'000;
    Peter.insurance.home_insurance = 25'000;

    
    Peter.mortgage.principal = 5'000'000;
    Peter.mortgage.remaining = 5'000'000;
    Peter.mortgage.interest_rate = 14.0;
    Peter.mortgage.active = 1;
    Peter.mortgage.months_left = 240; 
}


void Family_init() {
    Family.account = 0;
    Family.deposit = 0;
    Family.interest_rate = 20.0; 
}


void simulation(){
    int month = 2;
    int year = 2026; 
    int bar_opened = 0;
    int total_months = 0;   

    
    Family_init();

    while (!((month == 3) && (year == 2037))) {
        // ---- Свадьба в январе 2032 ----
        if (!married && year == 2032 && month == 1) {
            married = 1;
            printf("\n=== MARRIAGE! Alice and Peter get married. ===\n");
            printf("Family budget created. They will live in Peter's house, pay mortgage together.\n");
            printf("Alice stops paying rent. Both contribute 100,000 per month to family budget.\n");
        }

        // --- Операции Элис ---
        alice_salary_bank_interest();
        alice_business_bank_interest();
        alice_salary(month, year);
        alice_second_salary(month, year);
        alice_fund_personal();

        if (month == 5) alice_birthday();

        
        alice_food();  
        alice_car();
        alice_hamster();
        if (!married) alice_rent();          
        alice_clothing();
        alice_entertainment();
        alice_education();
        alice_health();
        alice_apartment_expenses();

        if (month == 2 && year == 2027) alice_repair();

        if (!bar_opened && year == 2034 && month == 1) {
            alice_open_bar();
            bar_opened = 1;
        }

        if (Alice_bar.is_open) {
            alice_bar_monthly();
            if (month == 1) alice_bar_furniture_repair();
        }

         
        if (!married) {
            alice_repay_loan();
        }

       
        if (month == 1) {
            alice_insurance();
            alice_property_tax();
        }
        if (month == 8) alice_vacation();
        if (month == 12) alice_christmas_bonus();
        if (month == 3) alice_charity();

       
        if (year == 2030 && month == 1 && !Alice.loan.active) alice_take_loan();
        if (year == 2031 && month == 1) alice_new_car();
        if (year == 2035 && month == 1) alice_inheritance();

        // --- Операции Питера ---
    
        RUB interest = Peter.bank.deposit * (Peter.bank.interest_rate / 12.0 / 100.0);
        Peter.bank.account += interest;

       
        peter_salary(month, year);
        peter_freelance();

        peter_food();
        peter_car();
        peter_dog();
        peter_clothing();
        peter_entertainment();
        peter_education();
        peter_health();
        peter_apartment_expenses();

        
        if (!married) {
            peter_mortgage_payment();
        }

       
        if (month == 1) {
            peter_insurance();
            peter_property_tax();
        }
        if (month == 5) peter_birthday();
        if (month == 8) peter_vacation();
        if (month == 12) peter_christmas_bonus();
        if (month == 3) peter_charity();

        
        if (year == 2032 && month == 1) peter_new_car();

        if (year == 2036 && month == 1) peter_inheritance();

        // --- Семейный бюджет  ---
        if (married) {
            
            family_interest();

            family_contributions();

            family_mortgage_payment();

            family_loan_payment();

            family_transfer_to_deposit();
        }

        alice_salary_transfer_to_deposit();

        alice_business_transfer_to_deposit();

       
        total_months++;
        if (total_months % 2 == 0) {
            RUB transfer = Alice.salary_bank.deposit;
            if (transfer > 0) {
                Alice.bank.deposit += transfer;
                Alice.salary_bank.deposit = 0;
            }
        }

        
        ++month;
        if (month == 13) {
            month = 1;
            ++year;
            apply_inflation();        
            apply_inflation_peter();  
        }
    }
}

int main()
{
    Alice_init();
    Peter_init();

    simulation();

    print_result();       
    print_result_peter(); 

    
    return 0;
}