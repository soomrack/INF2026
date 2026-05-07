#include <iostream>
#include <stdio.h>
#include <string>

//typedef int RUB;  // C
using RUB = long long int;  // C++
using Percent = float;

const int start_year = 2026;

struct Country{
    Percent inflation_Food;
    Percent inflation_Hobby;
    Percent inflation_Car;
    Percent inflation_Home;
    Percent inflation_Holiday;

    Percent indecsation;
};


struct Holidays{
    RUB Christmas;
    RUB Valentines_day;
    RUB Febrary_23;
    RUB March_8;
    RUB Labor_day;
    RUB New_year;
    RUB Birthday;
};


struct Bank{
    RUB salary_account;
    RUB deposit;
    Percent interest;

    //mortage
    Percent mortage_rate;
    RUB mortage_loan; 
    unsigned int mortage_term;
};


struct Home{
    RUB value;
    RUB expenses; 
};


struct Car {
    RUB value;
    RUB gas;
};


struct Person {
    std::string name;
    RUB salary;
    struct Bank Tbank;
    Percent probability_expenses;
    RUB food;
    RUB hobby;
    RUB taxes_paid;
    RUB insurance_health;
    RUB insurance_car;
    RUB investment_portfolio;
    Percent investment_risk; // 0.0 = депозит, 1.0 = акции/крипта
    bool has_health_insurance;
    bool has_car_insurance;
    int happiness; //suicide(<=0) -> depression(1-40) -> normal(41-100) -> happy(>=100)
    int health; //dead(<=0) -> bad health(1-40) -> normal(41-100) -> happy(>=100)
    float happiness_multiplier;
    bool alive;
    int year_of_death;
    struct Car car;
    struct Home home;
    struct Holidays holidays;

    void check_happiness(int const year);
    void check_health(int const year);
    void change_happiness(const int count);
    bool spending(const RUB spend);
    void change_health(const int year, const int count);
    void handle_taxes();
    void invest();
    void Person::attempt_marriage(int year);
    
    bool married;
    int marriage_year;
    RUB family_monthly_expenses;
};

struct Person Alice;

struct Person Bob;

struct Person Anton;

struct Person Eve;

struct Person Steve;

struct Person Leo;

struct Country Russia;

void Person::check_health(int const year){
    if(health >= 100) {
        if (happiness_multiplier < 2){
            happiness_multiplier += 0.1;
        }
        if (health>=300) health=300; 
    }
    else if(health <= 0) {
        alive = false;
        year_of_death = year;
    }
    else if(1 <= health && health <= 40){
        if (happiness_multiplier> 0.3){
            happiness_multiplier -= 0.3;
        }
    }
}

void Person::check_happiness(int const year){
    if(happiness >= 100) {
        happiness_multiplier = 0.3;
        if (happiness>=300) happiness=300; 
    }
    else if(happiness <= 0) {
        alive = false;
        year_of_death = year;
    }
    else if(1 <= happiness && happiness <= 40){
        happiness_multiplier = 0.7;
    }
    else{
        happiness_multiplier = 1.0;
    }
}

void Person::change_health(const int year, const int count)
{
    if (count < 0){
        health+=count*(year-start_year)/health;
    }
    else{
        happiness+=count/(year-start_year)*health;
    }
}

void Person::change_happiness(const int count)
{
    if (count < 0){
        happiness+=count/happiness_multiplier;
    }
    else{
        happiness+=count*happiness_multiplier;
    }
}

void Person::handle_taxes() 
{
    RUB annual_salary = salary * 12;
    RUB tax = calculate_income_tax(annual_salary) / 12;
    Tbank.salary_account -= tax;
    taxes_paid += tax;
}

void Person::invest() 
{
    if (investment_risk < 0.1) return; 

    Percent monthly_return = (investment_risk * 0.8 + 0.2) * (random(-3, 5) / 100.0);

    investment_portfolio += static_cast<RUB>(investment_portfolio * monthly_return);

    if (monthly_return > 0) change_happiness(2 * investment_risk);
    else if (monthly_return < -0.05) change_happiness(-5 * investment_risk);
}

void Person::attempt_marriage(int year)
{
    if (married) return;

    if (health <= 35 || happiness <= 30) return;

    float chance = 0.04f; // default chance
    if (happiness >= 70) chance += 0.03f;
    if (Tbank.salary_account + Tbank.deposit >= 300000) chance += 0.02f;
    if (probability_expenses > 30) chance -= 0.01f; 

    // limitations
    if (chance < 0.03f) chance = 0.03f;
    if (chance > 0.15f) chance = 0.15f;

    if (random(1, 100) <= chance * 100) {
        RUB wedding_cost = 150000 + random(0, 120000); 
        
        if (spending(wedding_cost)) {
            married = true;
            marriage_year = year;
            family_monthly_expenses = 40000; 
            holidays.Valentines_day+=salary*0.15;
            change_happiness(35);
            printf("[FAMILY] %s got married in %d. Cost: %lld RUB\n", name, year, wedding_cost);
        } else {
            change_happiness(-18);
            printf("[FAMILY] %s couldn't afford wedding in %d\n", name, year);
        }
    }
}

int random(const int begin, const int count);

RUB calculate_income_tax(const RUB salary);

bool Person::spending(const RUB spend)
{
    if ((Tbank.salary_account < spend)&&(Tbank.deposit < spend)){
        change_happiness(-spend / 10000 + random(-15,10));
        return false;
    }

    if (Tbank.salary_account < spend){
        Tbank.deposit -= spend;
    }
    else{
        Tbank.salary_account -= spend;
    }
    change_happiness(spend / 10000 + random(-5,10));
    return true;
}

void print_annual_report(const Person& p, const int year) {
    printf("=== %d | %s ===\n", year, p.name.c_str());
    printf("Health: %d | Happiness: %d\n", p.health, p.happiness);
    printf("Liquid Assets: %lld | Portfolio: %lld | Property: %lld\n",
           p.Tbank.salary_account + p.Tbank.deposit,
           p.investment_portfolio,
           p.car.value + p.home.value);
    printf("Mortgage: %lld | Insurance: %lld | Taxes: %lld\n",
           p.Tbank.mortage_loan,
           p.insurance_health + p.insurance_car,
           p.taxes_paid);
    printf("=====================\n\n");
}

void print_results()
{
    
    printf("--------------------------\n");
    printf("Alice year of death: %d \nSalary = %lld\n", Alice.year_of_death,Alice.salary);
    printf("Deposit = %lld\n", Alice.Tbank.deposit);
    printf("Salary account = %lld\n", Alice.Tbank.salary_account);
    printf("Property = %lld\n", Alice.car.value+Alice.home.value);
    printf("Total = %lld\n", Alice.Tbank.salary_account+Alice.Tbank.deposit+Alice.car.value+Alice.home.value);
    printf("Happiness = %d\n", Alice.happiness);
    printf("--------------------------\n");
    printf("Bob year of death: %d \nSalary = %lld\n", Bob.year_of_death, Bob.salary);
    printf("Deposit = %lld\n", Bob.Tbank.deposit);
    printf("Salary account = %lld\n", Bob.Tbank.salary_account);
    printf("Property = %lld\n", Bob.car.value+Bob.home.value);
    printf("Total = %lld\n", Bob.Tbank.salary_account+Bob.Tbank.deposit+Bob.car.value+Bob.home.value);
    printf("Happiness = %d\n", Bob.happiness);
    printf("--------------------------\n");
    printf("Anton year of death: %d \nSalary = %lld\n", Anton.year_of_death, Anton.salary);
    printf("Deposit = %lld\n", Anton.Tbank.deposit);
    printf("Salary account = %lld\n", Anton.Tbank.salary_account);
    printf("Property = %lld\n", Anton.car.value+Anton.home.value);
    printf("Total = %lld\n", Anton.Tbank.salary_account+Anton.Tbank.deposit+Anton.car.value+Anton.home.value);
    printf("Happiness = %d\n", Anton.happiness);
    printf("--------------------------\n\n");
    printf("Eve year of death: %d \nSalary = %lld\n", Eve.year_of_death, Eve.salary);
    printf("Deposit = %lld\n", Eve.Tbank.deposit);
    printf("Salary account = %lld\n", Eve.Tbank.salary_account);
    printf("Property = %lld\n", Eve.car.value+Eve.home.value);
    printf("Total = %lld\n", Eve.Tbank.salary_account+Eve.Tbank.deposit+Eve.car.value+Eve.home.value);
    printf("Happiness = %d\n", Eve.happiness);
    printf("--------------------------\n\n");
    printf("Steve year of death: %d \nSalary = %lld\n", Steve.year_of_death, Steve.salary);
    printf("Deposit = %lld\n", Steve.Tbank.deposit);
    printf("Salary account = %lld\n", Steve.Tbank.salary_account);
    printf("Property = %lld\n", Steve.car.value+Steve.home.value);
    printf("Total = %lld\n", Steve.Tbank.salary_account+Steve.Tbank.deposit+Steve.car.value+Steve.home.value);
    printf("Happiness = %d\n", Steve.happiness);
    printf("--------------------------\n\n");
    printf("Leo year of death: %d \nSalary = %lld\n", Leo.year_of_death, Leo.salary);
    printf("Deposit = %lld\n", Leo.Tbank.deposit);
    printf("Salary account = %lld\n", Leo.Tbank.salary_account);
    printf("Property = %lld\n", Leo.car.value+Leo.home.value);
    printf("Total = %lld\n", Leo.Tbank.salary_account+Leo.Tbank.deposit+Leo.car.value+Leo.home.value);
    printf("Happiness = %d\n", Leo.happiness);
    printf("--------------------------\n\n");

}

void alice_events(const int month, const int year)
{
    if (year == 2060 && month == 7){
        Alice.happiness = 35;
    }
    if (year == 2073 && month == 5){
        Anton.Tbank.salary_account+=140'000;
    }

}

void bob_events(const int month, const int year)
{
    if (year == 2052 && month == 3){
        Bob.happiness = 35;
    }
    if (year == 2072 && month == 7){
        Bob.Tbank.salary_account+=100'000;
    }
}

void anton_events(const int month, const int year)
{
    if (year == 2050 && month == 2){
        Anton.happiness = 35;
    }
    if (year == 2069 && month == 5){
        Anton.Tbank.salary_account+=120'000;
    }
}

void eve_events(const int month, const int year)
{
    if (year == 2056 && month == 5){
        Eve.happiness = 35;
    }
    if (year == 2072 && month == 4){
        Eve.Tbank.salary_account+=150'000;
    }
}

void steve_events(const int month, const int year)
{
    if (year == 2076 && month == 8){
        Steve.happiness = 100;
    }
    if (year == 2078 && month == 11){
        Steve.Tbank.salary_account+=100'000;
    }
}

void leo_events(const int month, const int year)
{
    if (year == 2050 && month == 8){
        Leo.happiness = 100;
    }
    if (year == 2080 && month == 11){
        Leo.Tbank.salary_account+=300'000;
    }
}

void alice_salary(const int month, const int year) 
{
    switch (year) 
    {
        case 2028: // Promotion
            switch (month)
            {
            case 8:
                Alice.salary *= 1.5;
                Alice.happiness_multiplier = 1.3;
                break;
            case 9:
                Alice.happiness_multiplier = 1.2;
                break;
            case 10:
                Alice.happiness_multiplier = 1.1;
                break;
            default:
                break;
            break;
        }
    }
    if (month==12) Alice.salary+=Alice.salary*(Russia.indecsation / 100.0);
    Alice.Tbank.salary_account += Alice.salary;

    Alice.change_happiness(-1); // because need to work
}

void bob_salary(const int month, const int year) 
{
    switch (year) 
    {
        case 2028: // Promotion
            switch (month)
            {
            case 8:
                Bob.salary *= 1.5;
                Bob.happiness_multiplier = 2;
                break;
            case 9:
                Bob.happiness_multiplier = 1.5;
                break;
            case 10:
                Bob.happiness_multiplier = 1.1;
                break;
            default:
                break;
            break;
        }
    }
    if (month == 12) Bob.salary += Bob.salary*(Russia.indecsation / 100.0);
    Bob.Tbank.salary_account += Bob.salary;
}

void anton_salary(const int month, const int year) 
{
    switch (year) 
    {
        case 2028: // Promotion
            switch (month)
            {
            case 8:
                Anton.salary *= 1.5;
                Anton.happiness_multiplier = 1.3;
                break;
            case 9:
                Anton.happiness_multiplier = 1.2;
                break;
            case 10:
                Anton.happiness_multiplier = 1.1;
                break;
            default:
                break;
            break;
        }
        case 2050:
            switch(month)
            {
                case 2:
                    Anton.salary *= 0.5;
                    Anton.happiness_multiplier = 0.7;
                    break;
                case 3:
                    Anton.happiness_multiplier = 0.8;
                    break;
                case 4:
                    Anton.happiness_multiplier = 0.9;
                    break;
                default:
                    break;
                break;
            }
    }
    if (month==12) Anton.salary+=Anton.salary*(Russia.indecsation / 100.0);
    Anton.Tbank.salary_account += Anton.salary;

    Anton.change_happiness(-1); // because need to work
}

void eve_salary(const int month, const int year) 
{
    switch (year) 
    {
        case 2028: // Promotion
            switch (month)
            {
            case 8:
                Eve.salary *= 1.5;
                Eve.happiness_multiplier = 1.3;
                break;
            case 9:
                Eve.happiness_multiplier = 1.2;
                break;
            case 10:
                Eve.happiness_multiplier = 1.1;
                break;
            default:
                break;
            break;
        }
        case 2050:
            switch(month)
            {
                case 2:
                    Eve.salary *= 1.1;
                    Eve.happiness_multiplier = 1.1;
                    break;
                case 3:
                    Eve.happiness_multiplier = 1.1;
                    break;
                case 4:
                    Eve.happiness_multiplier = 1.1;
                    break;
                default:
                    break;
                break;
            }
    }
    if (month==12) Eve.salary+=Eve.salary*(Russia.indecsation / 100.0);
    Eve.Tbank.salary_account += Eve.salary;

    Eve.change_happiness(-1); // because need to work
}

void steve_salary(const int month, const int year) 
{
    switch (year) 
    {
        case 2028: // Promotion
            switch (month)
            {
            case 8:
                Steve.salary *= 1.5;
                Steve.happiness_multiplier = 1.3;
                break;
            case 9:
                Steve.happiness_multiplier = 1.2;
                break;
            case 10:
                Steve.happiness_multiplier = 1.1;
                break;
            default:
                break;
            break;
        }
        case 2050:
            switch(month)
            {
                case 2:
                    Steve.salary *= 1.2;
                    Steve.happiness_multiplier = 1.3;
                break;
                case 3:
                    Steve.happiness_multiplier = 1.2;
                    break;
                case 4:
                    Steve.happiness_multiplier = 1.1;
                    break;
                default:
                    break;
                break;
            }
    }
    if (month==12) Steve.salary+=Steve.salary*(Russia.indecsation / 100.0);
    Steve.Tbank.salary_account += Steve.salary;

    Steve.change_happiness(-1); // because need to work
}

void leo_salary(const int month, const int year) 
{
    switch (year) 
    {
        case 2028: // Promotion
            switch (month)
            {
            case 8:
                Leo.salary *= 1.5;
                Leo.happiness_multiplier = 1.3;
                break;
            case 9:
                Leo.happiness_multiplier = 1.2;
                break;
            case 10:
                Leo.happiness_multiplier = 1.1;
                break;
            default:
                break;
            break;
        }
        case 2055:
            switch(month)
            {
                case 2:
                    Leo.salary *= 1.6;
                    Leo.happiness_multiplier = 1.4;
                break;
                case 3:
                    Leo.happiness_multiplier = 1.2;
                    break;
                case 4:
                    Leo.happiness_multiplier = 1.1;
                    break;
                default:
                    break;
                break;
            }
        case 2068:
            switch(month)
            {
                case 9:
                    Leo.salary *= 0.9;
                    Leo.happiness_multiplier = 0.7;
                break;
                case 10:
                    Leo.happiness_multiplier = 0.8;
                    break;
                case 11:
                    Leo.happiness_multiplier = 0.9;
                    break;
                default:
                    break;
                break;
            }
         case 2072:
            switch(month)
            {
                case 4:
                    Leo.salary *= 1.3;
                    Leo.happiness_multiplier = 1.3;
                break;
                case 5:
                    Leo.happiness_multiplier = 1.2;
                    break;
                case 6:
                    Leo.happiness_multiplier = 1.1;
                    break;
                default:
                    break;
                break;
            }
    }
    if (month==12) Leo.salary+=Leo.salary*(Russia.indecsation / 100.0);
    Leo.Tbank.salary_account += Leo.salary;

    Leo.change_happiness(-1); // because need to work
}

void alice_bank_interest()
{
    Alice.Tbank.deposit += Alice.Tbank.deposit * (Alice.Tbank.interest / 12.0 / 100.0);  // Bank interest
    Alice.change_happiness(1);
}

void bob_bank_interest()
{
    Bob.Tbank.deposit += Bob.Tbank.deposit * (Bob.Tbank.interest / 12.0 / 100.0);  // Bank interest
    Bob.change_happiness(1);
}

void anton_bank_interest()
{
    Anton.Tbank.deposit += Anton.Tbank.deposit * (Anton.Tbank.interest / 12.0 / 100.0);  // Bank interest
    Anton.change_happiness(1);
}

void eve_bank_interest()
{
    Eve.Tbank.deposit += Eve.Tbank.deposit * (Eve.Tbank.interest / 12.0 / 100.0);  // Bank interest
    Eve.change_happiness(1);
}

void steve_bank_interest()
{
    Steve.Tbank.deposit += Steve.Tbank.deposit * (Steve.Tbank.interest / 12.0 / 100.0);  // Bank interest
    Steve.change_happiness(1);
}

void leo_bank_interest()
{
    Steve.Tbank.deposit += Steve.Tbank.deposit * (Steve.Tbank.interest / 12.0 / 100.0);  // Bank interest
    Steve.change_happiness(2);
}

void alice_holiday_expenses(const int month)
{
    switch(month)
    {
        case 1:
            if (Alice.spending(Alice.holidays.Christmas)) Alice.change_happiness(10);
        break;
        case 2:
            if (Alice.spending(Alice.holidays.Febrary_23)) Alice.change_happiness(10);
            if (Alice.spending(Alice.holidays.Valentines_day)) Alice.change_happiness(10);
        break;
        case 4:
            if (Alice.spending(Alice.holidays.Birthday)) Alice.change_happiness(15);
        break;
        case 3:
            if (Alice.spending(Alice.holidays.March_8)) Alice.change_happiness(14);
        break;
        case 5:
            if (Alice.spending(Alice.holidays.Labor_day)) Alice.change_happiness(10);
        break;
        case 12:
            if (Alice.spending(Alice.holidays.New_year)) Alice.change_happiness(15);
            //inflation of expences
            Alice.holidays.Christmas += Alice.holidays.Christmas * (Russia.inflation_Holiday / 100.0);
            Alice.holidays.Valentines_day += Alice.holidays.Valentines_day * (Russia.inflation_Holiday / 100.0);
            Alice.holidays.Febrary_23 += Alice.holidays.Febrary_23 * (Russia.inflation_Holiday / 100.0);
            Alice.holidays.March_8 += Alice.holidays.March_8 * (Russia.inflation_Holiday / 100.0);
            Alice.holidays.Labor_day += Alice.holidays.Labor_day * (Russia.inflation_Holiday / 100.0);
            Alice.holidays.New_year += Alice.holidays.New_year * (Russia.inflation_Holiday / 100.0);
        break;
        default:
            return;
    }
}

void bob_holiday_expenses(const int month)
{
    switch(month)
    {
        case 1:
            if (Bob.spending(Bob.holidays.Christmas)) Bob.change_happiness(10);
        break;
        case 2:
            if (Bob.spending(Bob.holidays.Valentines_day)) Bob.change_happiness(10);
            if (Bob.spending(Bob.holidays.Febrary_23)) Bob.change_happiness(14);
        break;
        case 3:
            if (Bob.spending(Bob.holidays.March_8)) Bob.change_happiness(10);
        break;
        case 5:
            if (Bob.spending(Bob.holidays.Labor_day)) Bob.change_happiness(10);
        break;
        case 6:
            if (Bob.spending(Bob.holidays.Birthday)) Bob.change_happiness(15);
        break;
        case 12:
            if (Bob.spending(Bob.holidays.New_year)) Bob.change_happiness(15);
            //inflation of expences
            Bob.holidays.Christmas += Bob.holidays.Christmas * (Russia.inflation_Holiday / 100.0);
            Bob.holidays.Valentines_day += Bob.holidays.Valentines_day * (Russia.inflation_Holiday / 100.0);
            Bob.holidays.Febrary_23 += Bob.holidays.Febrary_23 * (Russia.inflation_Holiday / 100.0);
            Bob.holidays.March_8 += Bob.holidays.March_8 * (Russia.inflation_Holiday / 100.0);
            Bob.holidays.Labor_day += Bob.holidays.Labor_day * (Russia.inflation_Holiday / 100.0);
            Bob.holidays.New_year += Bob.holidays.New_year * (Russia.inflation_Holiday / 100.0);
        break;
        default:
            return;
    }
}

void anton_holiday_expenses(const int month)
{
    switch(month)
    {
        case 1:
            if (Anton.spending(Anton.holidays.Christmas)) Anton.change_happiness(10);
        break;
        case 2:
            if (Anton.spending(Anton.holidays.Valentines_day)) Anton.change_happiness(10);
            if (Anton.spending(Anton.holidays.Febrary_23)) Anton.change_happiness(14);
        break;
        case 3:
            if (Anton.spending(Anton.holidays.March_8)) Anton.change_happiness(10);
        break;
        case 5:
            if (Anton.spending(Anton.holidays.Labor_day)) Anton.change_happiness(10);
        break;
        case 6:
            if (Anton.spending(Anton.holidays.Birthday)) Anton.change_happiness(15);
        break;
        case 12:
            if (Anton.spending(Anton.holidays.New_year)) Anton.change_happiness(15);
            //inflation of expences
            Anton.holidays.Christmas += Anton.holidays.Christmas * (Russia.inflation_Holiday / 100.0);
            Anton.holidays.Valentines_day += Anton.holidays.Valentines_day * (Russia.inflation_Holiday / 100.0);
            Anton.holidays.Febrary_23 += Anton.holidays.Febrary_23 * (Russia.inflation_Holiday / 100.0);
            Anton.holidays.March_8 += Anton.holidays.March_8 * (Russia.inflation_Holiday / 100.0);
            Anton.holidays.Labor_day += Anton.holidays.Labor_day * (Russia.inflation_Holiday / 100.0);
            Anton.holidays.New_year += Anton.holidays.New_year * (Russia.inflation_Holiday / 100.0);
        break;
        default:
            return;
    }
}

void eve_holiday_expenses(const int month)
{
    switch(month)
    {
        case 1:
            if (Eve.spending(Eve.holidays.Christmas)) Eve.change_happiness(10);
        break;
        case 2:
            if (Eve.spending(Eve.holidays.Valentines_day)) Eve.change_happiness(10);
            if (Eve.spending(Eve.holidays.Febrary_23)) Eve.change_happiness(14);
        break;
        case 3:
            if (Eve.spending(Eve.holidays.March_8)) Eve.change_happiness(10);
        break;
        case 5:
            if (Eve.spending(Eve.holidays.Labor_day)) Eve.change_happiness(10);
        break;
        case 7:
            if (Eve.spending(Eve.holidays.Birthday)) Eve.change_happiness(15);
        break;
        case 12:
            if (Eve.spending(Eve.holidays.New_year)) Eve.change_happiness(15);
            //inflation of expences
            Eve.holidays.Christmas += Eve.holidays.Christmas * (Russia.inflation_Holiday / 100.0);
            Eve.holidays.Valentines_day += Eve.holidays.Valentines_day * (Russia.inflation_Holiday / 100.0);
            Eve.holidays.Febrary_23 += Eve.holidays.Febrary_23 * (Russia.inflation_Holiday / 100.0);
            Eve.holidays.March_8 += Eve.holidays.March_8 * (Russia.inflation_Holiday / 100.0);
            Eve.holidays.Labor_day += Eve.holidays.Labor_day * (Russia.inflation_Holiday / 100.0);
            Eve.holidays.New_year += Eve.holidays.New_year * (Russia.inflation_Holiday / 100.0);
        break;
        default:
            return;
    }
}

void steve_holiday_expenses(const int month)
{
    switch(month)
    {
        case 1:
            if (Steve.spending(Steve.holidays.Christmas)) Steve.change_happiness(10);
        break;
        case 2:
            if (Steve.spending(Steve.holidays.Valentines_day)) Steve.change_happiness(10);
            if (Steve.spending(Steve.holidays.Febrary_23)) Steve.change_happiness(14);
        break;
        case 3:
            if (Steve.spending(Steve.holidays.March_8)) Steve.change_happiness(10);
        break;
        case 5:
            if (Steve.spending(Steve.holidays.Labor_day)) Steve.change_happiness(10);
        break;
        case 10:
            if (Steve.spending(Steve.holidays.Birthday)) Steve.change_happiness(20);
        break;
        case 12:
            if (Steve.spending(Steve.holidays.New_year)) Steve.change_happiness(15);
            //inflation of expences
            Steve.holidays.Christmas += Steve.holidays.Christmas * (Russia.inflation_Holiday / 100.0);
            Steve.holidays.Valentines_day += Steve.holidays.Valentines_day * (Russia.inflation_Holiday / 100.0);
            Steve.holidays.Febrary_23 += Steve.holidays.Febrary_23 * (Russia.inflation_Holiday / 100.0);
            Steve.holidays.March_8 += Steve.holidays.March_8 * (Russia.inflation_Holiday / 100.0);
            Steve.holidays.Labor_day += Steve.holidays.Labor_day * (Russia.inflation_Holiday / 100.0);
            Steve.holidays.New_year += Steve.holidays.New_year * (Russia.inflation_Holiday / 100.0);
        break;
        default:
            return;
    }
}

void leo_holiday_expenses(const int month)
{
    switch(month)
    {
        case 1:
            if (Leo.spending(Leo.holidays.Christmas)) Leo.change_happiness(10);
        break;
        case 2:
            if (Leo.spending(Leo.holidays.Valentines_day)) Leo.change_happiness(10);
            if (Leo.spending(Leo.holidays.Febrary_23)) Leo.change_happiness(14);
        break;
        case 3:
            if (Leo.spending(Leo.holidays.March_8)) Leo.change_happiness(10);
        break;
        case 5:
            if (Leo.spending(Leo.holidays.Labor_day)) Leo.change_happiness(10);
        break;
        case 10:
            if (Leo.spending(Leo.holidays.Birthday)) Leo.change_happiness(20);
        break;
        case 12:
            if (Leo.spending(Leo.holidays.New_year)) Leo.change_happiness(15);
            //inflation of expences
            Leo.holidays.Christmas += Leo.holidays.Christmas * (Russia.inflation_Holiday / 100.0);
            Leo.holidays.Valentines_day += Leo.holidays.Valentines_day * (Russia.inflation_Holiday / 100.0);
            Leo.holidays.Febrary_23 += Leo.holidays.Febrary_23 * (Russia.inflation_Holiday / 100.0);
            Leo.holidays.March_8 += Leo.holidays.March_8 * (Russia.inflation_Holiday / 100.0);
            Leo.holidays.Labor_day += Leo.holidays.Labor_day * (Russia.inflation_Holiday / 100.0);
            Leo.holidays.New_year += Leo.holidays.New_year * (Russia.inflation_Holiday / 100.0);
        break;
        default:
            return;
    }
}

void alice_antidepression()
{
    if (Alice.happiness > 40){
        return;
    }
    else if (Alice.happiness <= 40 && Alice.happiness > 20){
        while (Alice.spending(1000)){
            Alice.change_happiness(10);
        }
    }   
    else if (Alice.happiness <= 20){
        while (Alice.spending(1500)) {
             Alice.change_happiness(12);
        }
    }
}

void bob_antidepression(){
    if (Bob.happiness > 40){
        return;
    }
    else if (Bob.happiness <= 40 && Bob.happiness > 20){
        while (Bob.spending(1000)){
            Bob.change_happiness(10);
        }
    }   
    else if (Bob.happiness <= 20){
        while (Bob.spending(1500)) {
             Bob.change_happiness(12);
        }
    }
}

void anton_antidepression()
{
    if (Anton.happiness > 40){
        return;
    }
    else if (Anton.happiness <= 40 && Anton.happiness > 20){
        while (Anton.spending(1000)){
            Anton.change_happiness(10);
        }
    }   
    else if (Anton.happiness <= 20){
        while (Anton.spending(1500)) {
             Anton.change_happiness(12);
        }
    }
}

void eve_antidepression()
{
    if (Eve.happiness > 45){
        return;
    }
    else if (Eve.happiness <= 45 && Eve.happiness > 21){
        while (Eve.spending(1000)){
            Eve.change_happiness(10);
        }
    }   
    else if (Eve.happiness <= 21){
        while (Eve.spending(1500)) {
             Eve.change_happiness(12);
        }
    }
}

void steve_antidepression()
{
    if (Steve.happiness > 25){
        return;
    }
    else if (Steve.happiness <= 25 && Steve.happiness > 15){
        while (Steve.spending(1000)){
            Steve.change_happiness(10);
        }
    }   
    else if (Steve.happiness <= 15){
        while (Steve.spending(1500)) {
             Steve.change_happiness(12);
        }
    }
}

void leo_antidepression()
{
    if (Leo.happiness > 50){
        return;
    }
    else if (Leo.happiness <= 50 && Leo.happiness > 35){
        while (Leo.spending(1000)){
            Leo.change_happiness(10);
        }
    }   
    else if (Leo.happiness <= 35){
        while (Leo.spending(1500)) {
             Leo.change_happiness(12);
        }
    }
}

void alice_medicine_expenses(const int year)
{
    if (Alice.health > 40){
        return;
    }
    else if (Alice.health <= 40 && Alice.health > 20){
        while (Alice.spending(1000)){
            Alice.change_health(year,8);
        }
    }   
    else if (Alice.health <= 20){
        while (Alice.spending(1500)) {
             Alice.change_health(year,8);
        }
    }

    if (Alice.has_health_insurance) {
        Alice.insurance_health = 5000 + (year - start_year) * 500;
        Alice.Tbank.salary_account -= Alice.insurance_health;
    }
}

void bob_medicine_expenses(const int year)
{
    if (Bob.health > 40){
        return;
    }
    else if (Bob.health <= 40 && Bob.health > 20){
        while (Bob.spending(1000)){
            Bob.change_health(year,8);
        }
    }   
    else if (Bob.health <= 20){
        while (Bob.spending(1500)) {
             Bob.change_health(year,8);
        }
    }

    if (Bob.has_health_insurance) {
        Bob.insurance_health = 5000 + (year - start_year) * 500;
        Bob.Tbank.salary_account -= Bob.insurance_health;
    }
}

void anton_medicine_expenses(const int year)
{
    if (Anton.health > 40){
        return;
    }
    else if (Anton.health <= 40 && Anton.health > 20){
        while (Anton.spending(1000)){
            Anton.change_health(year,8);
        }
    }   
    else if (Anton.health <= 20){
        while (Anton.spending(1500)) {
             Anton.change_health(year,8);
        }
    }

    if (Anton.has_health_insurance) {
        Anton.insurance_health = 5000 + (year - start_year) * 500;
        Anton.Tbank.salary_account -= Anton.insurance_health;
    }
}

void eve_medicine_expenses(const int year)
{
    if (Eve.health > 44){
        return;
    }
    else if (Eve.health <= 44 && Eve.health > 20){
        while (Eve.spending(1000)){
            Eve.change_health(year,8);
        }
    }   
    else if (Eve.health <= 20){
        while (Eve.spending(1500)) {
             Eve.change_health(year,8);
        }
    }

    if (Eve.has_health_insurance) {
        Eve.insurance_health = 5000 + (year - start_year) * 500;
        Eve.Tbank.salary_account -= Eve.insurance_health;
    }
}

void steve_medicine_expenses(const int year)
{
    if (Steve.health > 30){
        return;
    }
    else if (Steve.health <= 30 && Steve.health > 20){
        while (Steve.spending(1000)){
            Steve.change_health(year,8);
        }
    }   
    else if (Steve.health <= 20){
        while (Steve.spending(1500)) {
             Steve.change_health(year,8);
        }
    }

    if (Steve.has_health_insurance) {
        Steve.insurance_health = 5000 + (year - start_year) * 500;
        Steve.Tbank.salary_account -= Steve.insurance_health;
    }
}

void leo_medicine_expenses(const int year)
{
    if (Leo.health > 30){
        return;
    }
    else if (Leo.health <= 30 && Leo.health > 20){
        while (Leo.spending(1000)){
            Leo.change_health(year,8);
        }
    }   
    else if (Leo.health <= 20){
        while (Leo.spending(1500)) {
             Leo.change_health(year,8);
        }
    }

    if (Leo.has_health_insurance) {
        Leo.insurance_health = 5000 + (year - start_year) * 500;
        Leo.Tbank.salary_account -= Leo.insurance_health;
    }
}

void alice_food()
{
    Alice.spending(Alice.food);
    Alice.food += Alice.food * (Russia.inflation_Food / 12.0 / 100.0);
}

void bob_food()
{
    Bob.spending(Bob.food);
    Bob.food += Bob.food * (Russia.inflation_Food / 12.0 / 100.0);
}

void anton_food()
{
    Anton.spending(Anton.food);
    Anton.food += Anton.food * (Russia.inflation_Food / 12.0 / 100.0);
}

void eve_food()
{
    Eve.spending(Eve.food);
    Eve.food += Eve.food * (Russia.inflation_Food / 12.0 / 100.0);
}

void steve_food()
{
    Steve.spending(Steve.food);
    Steve.food += Steve.food * (Russia.inflation_Food / 12.0 / 100.0);
}

void leo_food()
{
    Leo.spending(Leo.food);
    Leo.food += Leo.food * (Russia.inflation_Food / 12.0 / 100.0);
}

void alice_family()
{
    Alice.spending(Alice.family_monthly_expenses);
    Alice.family_monthly_expenses += Alice.family_monthly_expenses * (Russia.inflation_Food / 12.0 / 100.0);
}

void bob_family()
{
    Bob.spending(Bob.family_monthly_expenses);
    Bob.family_monthly_expenses += Bob.family_monthly_expenses * (Russia.inflation_Food / 12.0 / 100.0);
}

void anton_family()
{
    Anton.spending(Anton.family_monthly_expenses);
    Anton.family_monthly_expenses += Anton.family_monthly_expenses * (Russia.inflation_Food / 12.0 / 100.0);
}

void eve_family()
{
    Eve.spending(Eve.family_monthly_expenses);
    Eve.family_monthly_expenses += Eve.family_monthly_expenses * (Russia.inflation_Food / 12.0 / 100.0);
}

void steve_family()
{
    Steve.spending(Steve.family_monthly_expenses);
    Steve.family_monthly_expenses += Steve.family_monthly_expenses * (Russia.inflation_Food / 12.0 / 100.0);
}

void leo_family()
{
    Leo.spending(Leo.family_monthly_expenses);
    Leo.family_monthly_expenses += Leo.family_monthly_expenses * (Russia.inflation_Food / 12.0 / 100.0);
}

void alice_car()
{
    Alice.spending(Alice.car.gas);
    Alice.car.gas += Alice.car.gas * (Russia.inflation_Car / 12.0 / 100.0);

    if (Alice.has_car_insurance) {
        Alice.insurance_car = Alice.car.value * 0.02;
        Alice.Tbank.salary_account -= Alice.insurance_car;
    }
}

void bob_car()
{
    Bob.spending(Bob.car.gas);
    Bob.car.gas += Bob.car.gas * (Russia.inflation_Car / 12.0 / 100.0);

    if (Bob.has_car_insurance) {
        Bob.insurance_car = Bob.car.value * 0.02;
        Bob.Tbank.salary_account -= Bob.insurance_car;
    }
}

void anton_car()
{
    Anton.spending(Anton.car.gas);
    Anton.car.gas += Anton.car.gas * (Russia.inflation_Car / 12.0 / 100.0);

    if (Anton.has_car_insurance) {
        Anton.insurance_car = Anton.car.value * 0.02;
        Anton.Tbank.salary_account -= Anton.insurance_car;
    }
}

void eve_car()
{
    Eve.spending(Eve.car.gas);
    Eve.car.gas += Eve.car.gas * (Russia.inflation_Car / 12.0 / 100.0);

    if (Eve.has_car_insurance) {
        Eve.insurance_car = Eve.car.value * 0.02;
        Eve.Tbank.salary_account -= Eve.insurance_car;
    }
}

void leo_car()
{
    Leo.spending(Leo.car.gas);
    Leo.car.gas += Leo.car.gas * (Russia.inflation_Car / 12.0 / 100.0);

    if (Leo.has_car_insurance) {
        Leo.insurance_car = Leo.car.value * 0.02;
        Leo.Tbank.salary_account -= Leo.insurance_car;
    }
}

void alice_home()
{
    Alice.spending(Alice.home.expenses);
    Alice.home.expenses += Alice.home.expenses * (Russia.inflation_Home / 12.0 / 100.0);
}

void bob_home()
{
    Bob.spending(Bob.home.expenses);
    Bob.home.expenses += Bob.home.expenses * (Russia.inflation_Home / 12.0 / 100.0);
}

void anton_home()
{
    Anton.spending(Anton.home.expenses);
    Anton.home.expenses += Anton.home.expenses * (Russia.inflation_Home / 12.0 / 100.0);
}

void eve_home()
{
    Eve.spending(Eve.home.expenses);
    Eve.home.expenses += Eve.home.expenses * (Russia.inflation_Home / 12.0 / 100.0);
}

void leo_home()
{
    Leo.spending(Leo.home.expenses);
    Leo.home.expenses += Leo.home.expenses * (Russia.inflation_Home / 12.0 / 100.0);
}

void alice_hobby()
{
    Alice.spending(Alice.hobby);
    Alice.hobby += Alice.hobby * (Russia.inflation_Hobby / 12.0 / 100.0);
}

void bob_hobby()
{
    Bob.spending(Bob.hobby);
    Bob.hobby += Bob.hobby * (Russia.inflation_Hobby / 12.0 / 100.0);
}

void anton_hobby()
{
    Anton.spending(Anton.hobby);
    Anton.hobby += Anton.hobby * (Russia.inflation_Hobby / 12.0 / 100.0);
}

void eve_hobby()
{
    Eve.spending(Eve.hobby);
    Eve.hobby += Eve.hobby * (Russia.inflation_Hobby / 12.0 / 100.0);
}

void steve_hobby()
{
    Steve.spending(Steve.hobby);
    Steve.hobby += Steve.hobby * (Russia.inflation_Hobby / 12.0 / 100.0);
}

void leo_hobby()
{
    Leo.spending(Leo.hobby);
    Leo.hobby += Leo.hobby * (Russia.inflation_Hobby / 12.0 / 100.0);
}

void alice_translate_to_savings()
{
    Alice.Tbank.deposit+=Alice.Tbank.salary_account;
    Alice.Tbank.salary_account=0;
}

void bob_translate_to_savings()
{
    Bob.Tbank.deposit+=Bob.Tbank.salary_account;
    Bob.Tbank.salary_account=0;
}

void anton_translate_to_savings()
{
    Anton.Tbank.deposit+=Anton.Tbank.salary_account;
    Anton.Tbank.salary_account=0;
}

void eve_translate_to_savings()
{
    Eve.Tbank.deposit+=Eve.Tbank.salary_account;
    Eve.Tbank.salary_account=0;
}

void steve_translate_to_savings()
{
    Steve.Tbank.deposit+=Steve.Tbank.salary_account;
    Steve.Tbank.salary_account=0;
}

void leo_translate_to_savings()
{
    Leo.Tbank.deposit+=Leo.Tbank.salary_account;
    Leo.Tbank.salary_account=0;
}

void bob_mortage_payment(const int year)
{
    if (Bob.Tbank.mortage_loan<=0) return;

    static const RUB S = Bob.home.value/Bob.Tbank.mortage_term;
    RUB rates = Bob.Tbank.mortage_loan*Bob.Tbank.mortage_rate/100/12;

    Bob.Tbank.mortage_loan += rates;
    if (Bob.Tbank.mortage_loan>=S){
        if (Bob.spending(S + rates)){
            Bob.Tbank.mortage_loan-=S + rates;
            Bob.change_happiness(-(S + rates) / 10000);
        }
        else{
            Bob.Tbank.mortage_loan+=500;
        }
    }
    else{
        if (Bob.spending(Bob.Tbank.mortage_loan)){
            Bob.Tbank.mortage_loan-=Bob.Tbank.mortage_loan;
            printf("Bob has paid off the mortage in %d year\n\n", year);
            Bob.change_happiness(50);
        }
        else{
            Bob.Tbank.mortage_loan+=500;
        }
    }
}

void anton_mortage_payment(const int year)
{
    if (Anton.Tbank.mortage_loan<=0) return;

    static const RUB S = Anton.home.value/Anton.Tbank.mortage_term;
    RUB rates = Anton.Tbank.mortage_loan*Anton.Tbank.mortage_rate/100/12;

    Anton.Tbank.mortage_loan += rates;
    if (Anton.Tbank.mortage_loan>=S){
        if (Anton.spending(S + rates)){
            Anton.Tbank.mortage_loan-=S + rates;
            Anton.change_happiness(-(S + rates) / 10000);
        }
        else{
            Anton.Tbank.mortage_loan+=500;
        }
    }
    else{
        if (Anton.spending(Anton.Tbank.mortage_loan)){
            Anton.Tbank.mortage_loan-=Anton.Tbank.mortage_loan;
            printf("Anton has paid off the mortage in %d year\n\n", year);
            Anton.change_happiness(50);
        }
        else{
            Anton.Tbank.mortage_loan+=500;
        }
    }
}

void eve_mortage_payment(const int year)
{
    if (Eve.Tbank.mortage_loan<=0) return;

    static const RUB S = Eve.home.value/Eve.Tbank.mortage_term;
    RUB rates = Eve.Tbank.mortage_loan*Eve.Tbank.mortage_rate/100/12;

    Eve.Tbank.mortage_loan += rates;
    if (Eve.Tbank.mortage_loan>=S){
        if (Eve.spending(S + rates)){
            Eve.Tbank.mortage_loan-=S + rates;
            Eve.change_happiness(-(S + rates) / 10000);
        }
        else{
            Eve.Tbank.mortage_loan+=500;
        }
    }
    else{
        if (Eve.spending(Eve.Tbank.mortage_loan)){
            Eve.Tbank.mortage_loan-=Eve.Tbank.mortage_loan;
            printf("Eve has paid off the mortage in %d year\n\n", year);
            Eve.change_happiness(50);
        }
        else{
            Eve.Tbank.mortage_loan+=500;
        }
    }
}

void steve_mortage_payment(const int year)
{
    if (Steve.Tbank.mortage_loan<=0) return;

    static const RUB S = Steve.home.value/Steve.Tbank.mortage_term;
    RUB rates = Steve.Tbank.mortage_loan*Steve.Tbank.mortage_rate/100/12;

    Steve.Tbank.mortage_loan += rates;
    if (Steve.Tbank.mortage_loan>=S){
        if (Steve.spending(S + rates)){
            Steve.Tbank.mortage_loan-=S + rates;
            Steve.change_happiness(-(S + rates) / 10000);
        }
        else{
            Steve.Tbank.mortage_loan+=500;
        }
    }
    else{
        if (Steve.spending(Steve.Tbank.mortage_loan)){
            Steve.Tbank.mortage_loan-=Steve.Tbank.mortage_loan;
            printf("Steve has paid off the mortage in %d year\n\n", year);
            Steve.change_happiness(50);
        }
        else{
            Steve.Tbank.mortage_loan+=500;
        }
    }
}

void alice_accidantly_expenses(const int month)
{
    if (month == 1 || month == 2 || month ==12)
    {
        if(random(1,100)<=Alice.probability_expenses+7){
            Alice.spending(random(1000,8000));
        }    
    }
    else{
        if(random(1,100)<=Alice.probability_expenses){
            Alice.spending(random(1000,10000));
        }
    }
}

void bob_accidantly_expenses(const int month)
{
    if(month == 3 || month == 4 || month == 5){
        if(random(1,100)<=Bob.probability_expenses+7){
            Bob.spending(random(1000,8000));
        }    
    }
    else{
        if(random(1,100)<=Bob.probability_expenses){
            Bob.spending(random(1000,10000));
        }
    }
}

void anton_accidantly_expenses(const int month)
{
    if (month == 1 || month == 2 || month ==12)
    {
        if(random(1,100)<=Anton.probability_expenses+7){
            Anton.spending(random(1000,8000));
        }    
    }
    else{
        if(random(1,100)<=Anton.probability_expenses){
            Anton.spending(random(1000,10000));
        }
    }
}

void eve_accidantly_expenses(const int month)
{
    if (month == 2 || month == 3 || month ==5)
    {
        if(random(1,100)<=Eve.probability_expenses+7){
            Eve.spending(random(1000,8000));
        }    
    }
    else{
        if(random(1,100)<=Eve.probability_expenses){
            Eve.spending(random(1000,10000));
        }
    }
}

void steve_accidantly_expenses(const int month)
{
    if (month == 6 || month == 7 || month == 8)
    {
        if(random(1,100)<=Steve.probability_expenses+7){
            Steve.spending(random(1000,8000));
        }    
    }
    else{
        if(random(1,100)<=Steve.probability_expenses){
            Steve.spending(random(1000,10000));
        }
    }
}

void leo_accidantly_expenses(const int month)
{
    if (month == 6 || month == 10 || month == 11)
    {
        if(random(1,100)<=Leo.probability_expenses+7){
            Leo.spending(random(1000,8000));
        }    
    }
    else{
        if(random(1,100)<=Leo.probability_expenses){
            Leo.spending(random(1000,10000));
        }
    }
}

void alice_init()
{
    Alice.name="Alice";
    Alice.alive = true;
    Alice.happiness = 100;
    Alice.happiness_multiplier = 1.0;
    Alice.year_of_death = 2127;

    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;

    Alice.salary = 180'000;
    Alice.food = 20'000;
    Alice.hobby = 30'000;
    Alice.probability_expenses = 37;

    Alice.home.value = 0; //rent an appartment
    Alice.home.expenses = 50'000;
    
    Alice.Tbank.salary_account = 200'000;
    Alice.Tbank.deposit = 100'000;
    Alice.Tbank.interest = 14.5;
    Alice.Tbank.mortage_loan = Alice.home.value;
    Alice.Tbank.mortage_rate = 0; 
    Alice.Tbank.mortage_term = 0;

    Alice.taxes_paid = calculate_income_tax(Alice.salary * 12) / 12;
    Alice.insurance_health = 0;
    Alice.insurance_car = 0;
    Alice.investment_portfolio = 0;
    Alice.investment_risk = 0.2;
    Alice.has_health_insurance = false;
    Alice.has_car_insurance = false;

    //holiday expences
    Alice.holidays.Christmas = 10'000;
    Alice.holidays.Valentines_day = 2'000;
    Alice.holidays.Febrary_23 = 10'000;
    Alice.holidays.March_8 = 5'000;
    Alice.holidays.Labor_day = 10'000;
    Alice.holidays.New_year = 20'000;
    Alice.holidays.Birthday = 20'000;

    Alice.married = false;
    Alice.marriage_year = 0;
    Alice.family_monthly_expenses = 0;
}

void bob_init()
{
    Bob.name="Bob";
    Bob.alive = true;
    Bob.happiness = 80;
    Bob.happiness_multiplier = 1.0;
    Bob.year_of_death = 2127;

    Bob.car.value = 2'400'000;
    Bob.car.gas = 15'000;

    Bob.salary = 180'000;
    Bob.food = 20'000;
    Bob.hobby = 30'000;
    Bob.probability_expenses = 15;

    Bob.home.value = 10'000'000;
    Bob.home.expenses = 30'000;
    
    Bob.Tbank.salary_account = 600'000;
    Bob.Tbank.deposit = 0;
    Bob.Tbank.interest = 14.5; 
    //mortage
    Bob.Tbank.mortage_loan = Bob.home.value;
    Bob.Tbank.mortage_rate = 20.5; 
    Bob.Tbank.mortage_term = 331;

    Bob.taxes_paid = calculate_income_tax(Bob.salary * 12) / 12;
    Bob.insurance_health = 0;
    Bob.insurance_car = 5'000;
    Bob.investment_portfolio = 50'000;
    Bob.investment_risk = 0.4;
    Bob.has_health_insurance = false;
    Bob.has_car_insurance = true;

    //holiday expences
    Bob.holidays.Christmas = 20'000;
    Bob.holidays.Valentines_day = 10'000;
    Bob.holidays.Febrary_23 = 5'000;
    Bob.holidays.March_8 = 5'000;
    Bob.holidays.Labor_day = 20'000;
    Bob.holidays.New_year = 30'000;
    Bob.holidays.Birthday = 10'000;

    Bob.married = false;
    Bob.marriage_year = 0;
    Bob.family_monthly_expenses = 0;
}

void anton_init()
{
    Anton.name="Anton";
    Anton.alive = true;
    Anton.happiness = 100;
    Anton.happiness_multiplier = 1.0;
    Anton.year_of_death = 2127;

    Anton.car.value = 2'400'000;
    Anton.car.gas = 15'000;

    Anton.salary = 180'000;
    Anton.food = 20'000;
    Anton.hobby = 30'000;
    Anton.probability_expenses = 30;

    Anton.home.value = 0; //rent an appartment
    Anton.home.expenses = 50'000;
    
    Anton.Tbank.salary_account = 600'000;
    Anton.Tbank.deposit = 100'000;
    Anton.Tbank.interest = 14.5;
    Anton.Tbank.mortage_loan = Anton.car.value;
    Anton.Tbank.mortage_rate = 48; 
    Anton.Tbank.mortage_term = 5.0;

    Anton.taxes_paid = calculate_income_tax(Anton.salary * 12) / 12;
    Anton.insurance_health = 8'000;
    Anton.insurance_car = 6'000;
    Anton.investment_portfolio = 100'000;
    Anton.investment_risk = 0.7;
    Anton.has_health_insurance = true;
    Anton.has_car_insurance = true;

    Anton.holidays.Christmas = 10'000;
    Anton.holidays.Valentines_day = 2'000;
    Anton.holidays.Febrary_23 = 10'000;
    Anton.holidays.March_8 = 5'000;
    Anton.holidays.Labor_day = 10'000;
    Anton.holidays.New_year = 20'000;
    Anton.holidays.Birthday = 20'000;

    Anton.married = false;
    Anton.marriage_year = 0;
    Anton.family_monthly_expenses = 0;
}

void eve_init()
{
    Eve.name="Eve";
    Eve.alive = true;
    Eve.happiness = 100;
    Eve.happiness_multiplier = 1.0;
    Eve.year_of_death = 2127;

    Eve.car.value = 5'400'000;
    Eve.car.gas = 25'000;

    Eve.salary = 200'000;
    Eve.food = 30'000;
    Eve.hobby = 50'000;
    Eve.probability_expenses = 60;

    Eve.home.value = 20'000'000;
    Eve.home.expenses = 50'000;
    
    Eve.Tbank.salary_account = 1'000'000;
    Eve.Tbank.deposit = 100'000;
    Eve.Tbank.interest = 14.5;
    Eve.Tbank.mortage_loan = 5'000'000;
    Eve.Tbank.mortage_rate = 48; 
    Eve.Tbank.mortage_term = 5.0;

    Eve.taxes_paid = calculate_income_tax(Eve.salary * 12) / 12;
    Eve.insurance_health = 20'000;
    Eve.insurance_car = 30'000;
    Eve.investment_portfolio = 100'000;
    Eve.investment_risk = 0.7;
    Eve.has_health_insurance = true;
    Eve.has_car_insurance = true;

    Eve.holidays.Christmas = 30'000;
    Eve.holidays.Valentines_day = 0;
    Eve.holidays.Febrary_23 = 10'000;
    Eve.holidays.March_8 = 5'000;
    Eve.holidays.Labor_day = 30'000;
    Eve.holidays.New_year = 60'000;
    Eve.holidays.Birthday = 100'000;

    Eve.married = false;
    Eve.marriage_year = 0;
    Eve.family_monthly_expenses = 0;
}

void steve_init()
{
    Steve.name="Steve";
    Steve.alive = true;
    Steve.happiness = 100;
    Steve.happiness_multiplier = 1.0;
    Steve.year_of_death = 2127;

    Steve.car.value = 0;
    Steve.car.gas = 0;

    Steve.salary = 50'000;
    Steve.food = 5'000;
    Steve.hobby = 15'000;
    Steve.probability_expenses = 20;

    Steve.home.value = 0; //with parents
    Steve.home.expenses = 0;
    
    Steve.Tbank.salary_account = 50'000;
    Steve.Tbank.deposit = 100'000;
    Steve.Tbank.interest = 14.5;
    Steve.Tbank.mortage_loan = 100'000;
    Steve.Tbank.mortage_rate = 12; 
    Steve.Tbank.mortage_term = 5.0;

    Steve.taxes_paid = calculate_income_tax(Steve.salary * 12) / 12;
    Steve.insurance_health = 0;
    Steve.insurance_car = 0;
    Steve.investment_portfolio = 100'000;
    Steve.investment_risk = 0.7;
    Steve.has_health_insurance = false;
    Steve.has_car_insurance = false;

    Steve.holidays.Christmas = 30'000;
    Steve.holidays.Valentines_day = 0;
    Steve.holidays.Febrary_23 = 10'000;
    Steve.holidays.March_8 = 5'000;
    Steve.holidays.Labor_day = 30'000;
    Steve.holidays.New_year = 60'000;
    Steve.holidays.Birthday = 100'000;

    Steve.married = false;
    Steve.marriage_year = 0;
    Steve.family_monthly_expenses = 0;
}

void leo_init()
{
    Leo.name="Leo";
    Leo.alive = true;
    Leo.happiness = 90;
    Leo.happiness_multiplier = 1.0;
    Leo.year_of_death = 2127;

    Leo.car.value = 5'400'000;
    Leo.car.gas = 25'000;

    Leo.salary = 50'000;
    Leo.food = 5'000;
    Leo.hobby = 15'000;
    Leo.probability_expenses = 30;

    Leo.home.value = 10'000'000; 
    Leo.home.expenses = 20'000;
    
    Leo.Tbank.salary_account = 200'000;
    Leo.Tbank.deposit = 100'000;
    Leo.Tbank.interest = 14.5;
    Leo.Tbank.mortage_loan = 0;
    Leo.Tbank.mortage_rate = 0; 
    Leo.Tbank.mortage_term = 0;

    Leo.taxes_paid = calculate_income_tax(Leo.salary * 12) / 12;
    Leo.insurance_health = 0;
    Leo.insurance_car = 30'000;
    Leo.investment_portfolio = 200'000;
    Leo.investment_risk = 0.5;
    Leo.has_health_insurance = false;
    Leo.has_car_insurance = true;

    Leo.holidays.Christmas = 30'000;
    Leo.holidays.Valentines_day = 20'000;
    Leo.holidays.Febrary_23 = 10'000;
    Leo.holidays.March_8 = 5'000;
    Leo.holidays.Labor_day = 30'000;
    Leo.holidays.New_year = 60'000;
    Leo.holidays.Birthday = 100'000;

    Leo.married = true;
    Leo.marriage_year = 2026;
    Leo.family_monthly_expenses = 40'000;
}


void russia_init()
{
    Russia.inflation_Car=18.5;
    Russia.inflation_Food=12.0;
    Russia.inflation_Hobby=14.5;
    Russia.inflation_Home=15.0;
    Russia.inflation_Holiday=16.0;

    Russia.indecsation=10.0;
};

void simulation()
{
    int month = 2;
    int year = start_year;
    
    while ( !((month == 3) && (year == 2127)) ) {
        if (Alice.alive){
            alice_bank_interest();
            alice_salary(month, year);
            Alice.handle_taxes();
            Alice.invest();
            alice_events(month, year);
            Alice.attempt_marriage(year); 
            alice_food();
            alice_family();
            alice_home();
            alice_car();
            alice_hobby();
            alice_accidantly_expenses(month);
            alice_holiday_expenses(month);
            alice_medicine_expenses(year);
            alice_antidepression();
            alice_translate_to_savings();
            Alice.change_health(year,-10);
            Alice.check_happiness(year);
            Alice.check_health(year);
        }
        

        if (Bob.alive){
            bob_bank_interest();
            bob_salary(month, year);
            Bob.handle_taxes();
            Bob.invest();
            bob_events(month, year);
            Bob.attempt_marriage(year);
            bob_mortage_payment(year);
            bob_food();
            bob_family();
            bob_home();
            bob_car();
            bob_hobby();
            bob_accidantly_expenses(month);
            bob_medicine_expenses(year);
            bob_antidepression();
            bob_translate_to_savings();
            Bob.change_health(year,-10);
            Bob.check_happiness(year);
            Bob.check_health(year);
        }


        if (Anton.alive){
            anton_bank_interest();
            anton_salary(month, year);
            Anton.handle_taxes();
            Anton.invest();
            anton_events(month, year);
            Anton.attempt_marriage(year);
            anton_mortage_payment(year);
            anton_food();
            anton_family();
            anton_home();
            anton_car();
            anton_hobby();
            anton_accidantly_expenses(month);
            anton_medicine_expenses(year);
            anton_antidepression();
            anton_translate_to_savings();
            Anton.change_health(year,-10);
            Anton.check_happiness(year);
            Anton.check_health(year);
        }


        if (Eve.alive){
            eve_bank_interest();
            eve_salary(month, year);
            Eve.handle_taxes();
            Eve.invest();
            eve_events(month, year);
            Eve.attempt_marriage(year); 
            eve_food();
            eve_family();
            eve_home();
            eve_car();
            eve_hobby();
            eve_accidantly_expenses(month);
            eve_holiday_expenses(month);
            eve_medicine_expenses(year);
            eve_antidepression();
            eve_translate_to_savings();
            Eve.change_health(year,-10);
            Eve.check_happiness(year);
            Eve.check_health(year);
        }


        if (Steve.alive){
            steve_bank_interest();
            steve_salary(month, year);
            Steve.handle_taxes();
            Steve.invest();
            steve_events(month, year);
            //Steve.attempt_marriage(year); 
            steve_food();
            steve_family();
            //without car and home paid
            steve_hobby();
            steve_accidantly_expenses(month);
            steve_holiday_expenses(month);
            steve_medicine_expenses(year);
            steve_antidepression();
            steve_translate_to_savings();
            Steve.change_health(year,-10);
            Steve.check_happiness(year);
            Steve.check_health(year);
        }


        if (Leo.alive){
            leo_bank_interest();
            leo_salary(month, year);
            Leo.handle_taxes();
            Leo.invest();
            leo_events(month, year);
            //Leo.attempt_marriage(year); // already have family
            leo_food();
            leo_family();
            leo_family();
            leo_home();
            leo_hobby();
            leo_accidantly_expenses(month);
            leo_holiday_expenses(month);
            leo_medicine_expenses(year);
            leo_antidepression();
            leo_translate_to_savings();
            Leo.change_health(year,-10);
            Leo.check_happiness(year);
            Leo.check_health(year);
        }


        if (month == 1) {
            print_annual_report(Alice, year);
            print_annual_report(Bob, year);
            print_annual_report(Anton, year);
            print_annual_report(Eve, year);
            print_annual_report(Steve, year);
            print_annual_report(Leo, year);
        }

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}

int random(const int begin, const int count)
{
    int num = (rand() % count) + begin;
    return num;
}

RUB calculate_income_tax(const RUB salary) {
    if (salary <= 5000000) return static_cast<RUB>(salary * 0.13);
    if (salary <= 20000000) return 650000 + static_cast<RUB>((salary - 5000000) * 0.15);
    return 2900000 + static_cast<RUB>((salary - 20000000) * 0.18);
}

int main()
{
    srand(time(NULL));

    russia_init();

    alice_init();

    bob_init();

    anton_init();

    eve_init();

    steve_init();

    leo_init();
    
    simulation();
    
    print_results();
}
