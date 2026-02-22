#include <stdio.h>    

using RUB = long long int;
using Percent = float;

struct Dog {

    struct OneTimeDog {
        RUB equipment;                  // амуниция (ошейник, поводок)
        RUB bowls;                      // миски 
        RUB carrier;                    // переноска 
        RUB cage;                       // клетка/вольер
        RUB vaccination;
    };
    OneTimeDog one_time;

    struct MonthDog {
        RUB feed;                       // корм
        RUB aibolit;
        RUB analyses;
    };
    MonthDog month;

    struct SpontaneousDog {
    RUB toys;
    RUB others;
    };
    SpontaneousDog spontaneous;
};
struct Dog Jack;

struct Car {

    struct OneTimeCar {
        RUB value;               
        RUB insurance;                  // страховка
    };
    OneTimeCar one_time;

    struct MonthCar {
        RUB washing;
        RUB vehicle_tax;                // транспортный налог
        RUB maintenance;                // техническое обслуживание
    };
    MonthCar month;

    struct WeekCar {
        RUB gas;
    };
    WeekCar week;
};
struct Car Subaru;

struct Bank {
    RUB bank_account;                    // текущий банковский счет
    RUB deposit;  
    Percent pp;  
};
struct Bank Rusbank; 

struct NewYearExpenses {
    RUB gifts;
    RUB food;
    RUB drinks;
    RUB entertainment;
    RUB decoration;  
};

struct Food {
    RUB dairy;
    RUB meat; 
    RUB poultry;
    RUB fish; 
    RUB seafood;
    RUB vegetables;
    RUB fruits;
    RUB berries;
    RUB beverages;
    RUB sweets;
    RUB eggs;
    RUB frozen;
    RUB sauces;
    RUB spices;
};

struct Person {
    RUB salary;
    Food food;
    Car car; 
    Dog dog; 
    RUB manicure;
    RUB internet;                    
    RUB wardrobe;                              // расходы на одежду/обувь/акссесуары
    NewYearExpenses new_year;                    
};
struct Person Alice;


void alice_salary (const int month, const int year) {
    if ((month == 8) && (year == 2026)) // 
    {
        Alice.salary *= 1.5;
    }
    Rusbank.bank_account += Alice.salary; 
}


void alice_food(float inflation) {
    Rusbank.bank_account -= Alice.food.dairy;
    Rusbank.bank_account -= Alice.food.meat;
    Rusbank.bank_account -= Alice.food.poultry;
    Rusbank.bank_account -= Alice.food.fish;
    Rusbank.bank_account -= Alice.food.seafood;
    Rusbank.bank_account -= Alice.food.vegetables;
    Rusbank.bank_account -= Alice.food.fruits;
    Rusbank.bank_account -= Alice.food.berries;
    Rusbank.bank_account -= Alice.food.beverages;
    Rusbank.bank_account -= Alice.food.sweets;
    Rusbank.bank_account -= Alice.food.eggs;
    Rusbank.bank_account -= Alice.food.frozen;
    Rusbank.bank_account -= Alice.food.sauces;
    Rusbank.bank_account -= Alice.food.spices; 
    Alice.food.dairy *= (1 + (inflation) / 100);
    Alice.food.meat *= (1 + (inflation) / 100);
    Alice.food.poultry *= (1 + (inflation) / 100);
    Alice.food.fish *= (1 + (inflation) / 100);
    Alice.food.seafood *= (1 + (inflation) / 100);
    Alice.food.vegetables *= (1 + (inflation) / 100);
    Alice.food.fruits *= (1 + (inflation) / 100);
    Alice.food.berries *= (1 + (inflation) / 100);
    Alice.food.beverages *= (1 + (inflation) / 100);
    Alice.food.sweets *= (1 + (inflation) / 100);
    Alice.food.eggs *= (1 + (inflation) / 100);
    Alice.food.frozen *= (1 + (inflation) / 100);
    Alice.food.sauces *= (1 + (inflation) / 100);
    Alice.food.spices *= (1 + (inflation) / 100);
}


void alice_personal(float inflation, int month) {
    Rusbank.bank_account -= Alice.internet;
    Rusbank.bank_account -= Alice.manicure;
    if (month == 12 || month == 3 || month == 6 || month == 9) {  
        Rusbank.bank_account -= Alice.wardrobe;
    }
    Alice.wardrobe *= (1 + inflation / 100);
    Alice.internet *= (1 + inflation / 100);
    Alice.manicure *= (1 + inflation / 100);
}


void alice_car(float inflation, int month, int year) {
    Rusbank.bank_account -= Subaru.month.maintenance;
    Rusbank.bank_account -= Subaru.month.washing;
    for (int week = 1; week <= 4; week++) {
        Rusbank.bank_account -= Subaru.week.gas;
    }
    if (month == 3) {                                                             // транспортный налог в марте
        Rusbank.bank_account -= Subaru.month.vehicle_tax * 12;                    // оплата сразу за год
    }
    if (month == 1) { 
        Rusbank.bank_account -= Subaru.one_time.insurance;
    }
    Subaru.one_time.value *= (1 + (inflation) / 100);
    Subaru.one_time.insurance *= (1 + inflation / 100);
    Subaru.month.washing *= (1 + (inflation) / 100);
    Subaru.month.maintenance *= (1 + (inflation) / 100);
    Subaru.month.vehicle_tax *= (1 + (inflation) / 100);
    Subaru.week.gas *= (1 + (inflation) / 100);
}


void alice_pet(float inflation, int month, int year) {
    Rusbank.bank_account -= Jack.month.feed;
    Rusbank.bank_account -= Jack.month.aibolit;
    Rusbank.bank_account -= Jack.month.analyses;
    if (month == 3) {  
        Rusbank.bank_account -= Jack.one_time.vaccination;
    }
    if (month == 9) { 
        Rusbank.bank_account -= Jack.one_time.equipment;
    }
    if (month == 5 && year % 2 == 0) {  
        Rusbank.bank_account -= Jack.one_time.bowls;
    }
    if (month == 7 && year % 3 == 0) {  
        Rusbank.bank_account -= Jack.one_time.carrier;
    }
    if (month == 11 && year % 3 == 0) {  
        Rusbank.bank_account -= Jack.one_time.cage;
    }
    if (month % 2 == 0) {
        Rusbank.bank_account -= Jack.spontaneous.toys;
        Rusbank.bank_account -= Jack.spontaneous.others;
    }
    Jack.one_time.equipment *= (1 + inflation / 100);
    Jack.one_time.bowls *= (1 + inflation / 100);
    Jack.one_time.carrier *= (1 + inflation / 100);
    Jack.one_time.cage *= (1 + inflation / 100);
    Jack.spontaneous.toys *= (1 + inflation / 100);
    Jack.spontaneous.others *= (1 + inflation / 100);
    Jack.one_time.vaccination *= (1 + inflation / 100);
    Jack.month.feed *= (1 + (inflation) / 100);
    Jack.month.aibolit *= (1 + (inflation) / 100);
    Jack.month.analyses *= (1 + (inflation) / 100);
}


void alice_bank_interest() {
    RUB interest = (RUB)((float)Rusbank.deposit * Rusbank.pp / 12.0f / 100.0f);
    Rusbank.deposit += interest;
}


void alice_new_year(int month, float inflation) {
    if (month == 12) { 
        Rusbank.bank_account -= Alice.new_year.decoration;  
        Rusbank.bank_account -= Alice.new_year.drinks;  
        Rusbank.bank_account -= Alice.new_year.gifts;
        Rusbank.bank_account -= Alice.new_year.food;
        Rusbank.bank_account -= Alice.new_year.entertainment;
        
        Alice.new_year.gifts *= (1 + inflation / 100);
        Alice.new_year.food *= (1 + inflation / 100);
        Alice.new_year.entertainment *= (1 + inflation / 100);
        Alice.new_year.decoration *= (1 + inflation / 100);  
        Alice.new_year.drinks *= (1 + inflation / 100);      
    }
}


void simulation() { 
    int month = 2;
    int year = 2026;

    float inflation = 5.6; 
    
    while (!(month == 2 && year == 2031)) {
        alice_salary(month, year); 
        alice_food(inflation);   
        alice_car(inflation, month, year);              
        alice_pet(inflation, month, year);    
        alice_personal(inflation, month);  
        alice_bank_interest();             
        alice_new_year(month, inflation); 
        
        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}


void alice_init()
{
    Alice.salary = 465'000;    
    Alice.internet = 550;      
    Alice.wardrobe = 25'000;
    Alice.manicure = 2'500;

    Alice.food.dairy = 1000;
    Alice.food.meat = 1000; 
    Alice.food.poultry = 500;
    Alice.food.fish = 2000; 
    Alice.food.seafood = 1000;
    Alice.food.vegetables = 500;
    Alice.food.fruits = 450;
    Alice.food.berries = 300;
    Alice.food.beverages = 300;
    Alice.food.sweets = 500;
    Alice.food.eggs = 150;
    Alice.food.frozen = 250;
    Alice.food.sauces = 150;
    Alice.food.spices = 250;

    Rusbank.bank_account = 1'000'000;   
    Rusbank.deposit = 3'000'000;  

    Subaru.one_time.value = 3'500'000;
    Subaru.one_time.insurance = 40'000; 
    Subaru.month.washing = 2'000;
    Subaru.month.vehicle_tax = 1'500;       
    Subaru.month.maintenance = 3'000;      
    Subaru.week.gas = 14'000;

    Jack.one_time.equipment = 2'000;          
    Jack.one_time.bowls = 1'000;              
    Jack.one_time.carrier = 2'000;           
    Jack.one_time.cage = 3'000;            
    Jack.one_time.vaccination = 3'000;         
    Jack.month.feed = 2'000;
    Jack.month.aibolit = 1'000;               
    Jack.month.analyses = 500;                 
    Jack.spontaneous.toys = 1'000;             
    Jack.spontaneous.others = 1'000;    

    Alice.new_year.gifts = 15'000;
    Alice.new_year.food = 10'000;
    Alice.new_year.entertainment = 6'500;
    Alice.new_year.decoration = 5'000;         
    Alice.new_year.drinks = 4'000;         

    Rusbank.pp = 14.5;
}
 

void print_results() { 
    if (Rusbank.bank_account < 0) {
        printf("Salary = %lld\n", Alice.salary);
        printf("Attention! You have a negative bank account!");
    }
    else
    {
    printf("Salary = %lld\n", Alice.salary);
    printf("Current bank account = %lld", Rusbank.bank_account); 
    }
}


int main()
{
    alice_init();
    simulation();
    print_results();
}










