#include <stdio.h>

//typedef int RUB;  // C
using RUB = long long int;  // C++
using Percent = float;


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
};


struct Bank{
    RUB salary_account;
    RUB Deposit;
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
    RUB salary;
    struct Bank Tbank;
    RUB food;
    RUB hobby;

    int happiness; //suicide(<=0) -> depression(1-40) -> normal(41-100) -> happy(>=100)
    bool alive;
    float happiness_multiplier;
    int year_of_death;


    struct Car car;
    struct Home home;

    //holiday expences
    struct Holidays holidays;

    void check_happiness(int const year){
        if(happiness>=100){
            happiness_multiplier=0.3;
            if (happiness>200) happiness=200;
        }
        else if(happiness<=0){
            alive=false;
            year_of_death=year;
        }
        else if(1<=happiness && happiness<=40){
            happiness_multiplier=0.7;
        }
        else{
            happiness_multiplier=1.0;
        }
    }

    void change_happiness(const int count){
        if (count<0){
            happiness+=count/happiness_multiplier/10;
        }
        else{
            happiness+=count*happiness_multiplier/10;
        }
    }
};
struct Person Alice;

struct Person Bob;

struct Country Russia;


void print_results()
{
    printf("Alice year of death: %d \nSalary = %lld\n", Alice.year_of_death,Alice.salary);
    printf("Capital = %lld\n", Alice.Tbank.salary_account+Alice.Tbank.Deposit+Alice.car.value+Alice.home.value);
    printf("Happiness = %d\n", Alice.happiness);
    printf("--------------------------\n");
    printf("Bob year of death: %d \nSalary = %lld\n", Bob.year_of_death, Bob.salary);
    printf("Capital = %lld\n", Bob.Tbank.salary_account+Bob.Tbank.Deposit+Bob.car.value+Bob.home.value);
    printf("Happiness = %d\n", Bob.happiness);
}


void alice_salary(const int month, const int year) {
    switch (year) 
    {
        case 2026: // Promotion
            switch (month)
            {
            case 8:
                Alice.salary *= 1.5;
                Alice.happiness_multiplier=1.3;
                break;
            case 9:
                Alice.happiness_multiplier=1.2;
                break;
            case 10:
                Alice.happiness_multiplier=1.1;
                break;
            default:
                break;
            break;
        }
    }
    if (month==12) Alice.salary+=Alice.salary*(Russia.indecsation / 100.0);
    Alice.Tbank.salary_account += Alice.salary;

    Alice.change_happiness(-1);
}

void alice_spending(const RUB spend){
    if ((Alice.Tbank.salary_account < spend)&&(Alice.Tbank.Deposit < spend)){
        Bob.change_happiness(-spend/10000*Bob.happiness_multiplier);
        return;
    }

    if (Alice.Tbank.salary_account < spend){
        Alice.Tbank.Deposit-=spend;
    }
    else{
        Alice.Tbank.salary_account-=spend;
    }
    Alice.change_happiness(spend/10000*Alice.happiness_multiplier);
}


void alice_bank_interest()
{
    Alice.Tbank.Deposit += Alice.Tbank.Deposit * (Alice.Tbank.interest / 12.0 / 100.0);  // Bank interest
    Bob.change_happiness(1);
}


void alice_holiday_expenses(const int month)
{
    switch(month)
    {
        case 1:
            alice_spending(Alice.holidays.Christmas);
        break;
        case 2:
            alice_spending(Alice.holidays.Valentines_day);
            alice_spending(Alice.holidays.Febrary_23);
        break;
        case 3:
            alice_spending(Alice.holidays.March_8);
        break;
        case 5:
            alice_spending(Alice.holidays.Labor_day);
        break;
        case 12:
            alice_spending(Alice.holidays.New_year);
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


void alice_food()
{
    alice_spending(Alice.food);
    Alice.food += Alice.food * (Russia.inflation_Food / 12.0 / 100.0);
}


void alice_car()
{
    alice_spending(Alice.car.gas);
    Alice.car.gas += Alice.car.gas * (Russia.inflation_Car / 12.0 / 100.0);
}


void alice_home()
{
    alice_spending(Alice.home.expenses);
    Alice.home.expenses += Alice.home.expenses * (Russia.inflation_Home / 12.0 / 100.0);
}


void alice_hobby()
{
    alice_spending(Alice.hobby);
    Alice.hobby += Alice.hobby * (Russia.inflation_Hobby / 12.0 / 100.0);
}


void alice_translate_to_savings()
{
    Alice.Tbank.Deposit+=Alice.Tbank.salary_account;
    Alice.Tbank.salary_account=0;
}


void alice_init()
{
    Alice.alive=true;
    Alice.happiness=90;
    Alice.happiness_multiplier=1.0;
    Alice.year_of_death=2127;

    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;

    Alice.salary = 180'000;
    Alice.food = 20'000;
    Alice.hobby = 30'000;

    Alice.home.value=0; //rent an appartment
    Alice.home.expenses=50'000;
    
    Alice.Tbank.salary_account = 0;
    Alice.Tbank.Deposit = 0;
    Alice.Tbank.interest = 14.5;
    Alice.Tbank.mortage_loan = Alice.home.value;
    Alice.Tbank.mortage_rate = 0; 
    Alice.Tbank.mortage_term = 0;

    //holiday expences
    Alice.holidays.Christmas=10'000;
    Alice.holidays.Valentines_day=2'000;
    Alice.holidays.Febrary_23=10'000;
    Alice.holidays.March_8=5'000;
    Alice.holidays.Labor_day=10'000;
    Alice.holidays.New_year=20'000;
}

void bob_init()
{
    Bob.alive=true;
    Bob.happiness=80;
    Bob.happiness_multiplier=1.0;
    Bob.year_of_death=2127;

    Bob.car.value = 2'400'000;
    Bob.car.gas = 15'000;

    Bob.salary = 180'000;
    Bob.food = 20'000;
    Bob.hobby = 30'000;

    Bob.home.value=10'000'000;
    Bob.home.expenses=30'000;
    
    Bob.Tbank.salary_account = 600'000;
    Bob.Tbank.Deposit = 0;
    Bob.Tbank.interest = 14.5; 
    //mortage
    Bob.Tbank.mortage_loan=Bob.home.value;
    Bob.Tbank.mortage_rate=20.5; 
    Bob.Tbank.mortage_term=331;

    //holiday expences
    Bob.holidays.Christmas=20'000;
    Bob.holidays.Valentines_day=10'000;
    Bob.holidays.Febrary_23=5'000;
    Bob.holidays.March_8=5'000;
    Bob.holidays.Labor_day=20'000;
    Bob.holidays.New_year=30'000;
}


void bob_salary(const int month, const int year) {
    switch (year) 
    {
        case 2026: // Promotion
            switch (month)
            {
            case 8:
                Bob.salary *= 1.5;
                Bob.happiness_multiplier=2;
                break;
            case 9:
                Bob.happiness_multiplier=1.5;
                break;
            case 10:
                Bob.happiness_multiplier=1.1;
                break;
            default:
                break;
            break;
        }
    }
    if (month==12) Bob.salary+=Bob.salary*(Russia.indecsation / 100.0);
    Bob.Tbank.salary_account += Bob.salary;
    
    Alice.change_happiness(-1);
}

bool bob_spending(const RUB spend){
    if ((Bob.Tbank.salary_account < spend)&&(Bob.Tbank.Deposit < spend)){
        Bob.change_happiness(-spend/10000);
        return false;
    }
    
    if (Bob.Tbank.salary_account < spend){
        Bob.Tbank.Deposit-=spend;
    }
    else{
        Bob.Tbank.salary_account-=spend;
    }
    Bob.change_happiness(spend/10000);
    return true;
}


void bob_bank_interest()
{
    Bob.Tbank.Deposit += Bob.Tbank.Deposit * (Bob.Tbank.interest / 12.0 / 100.0);  // Bank interest
    Bob.change_happiness(1);
}


void bob_holiday_expenses(const int month)
{
    switch(month)
    {
        case 1:
            if (bob_spending(Bob.holidays.Christmas)) Bob.change_happiness(10);
        break;
        case 2:
            if (bob_spending(Bob.holidays.Valentines_day)) Bob.change_happiness(10);
            if (bob_spending(Bob.holidays.Febrary_23)) Bob.change_happiness(14);
        break;
        case 3:
            if (bob_spending(Bob.holidays.March_8)) Bob.change_happiness(10);
        break;
        case 5:
            if (bob_spending(Bob.holidays.Labor_day)) Bob.change_happiness(10);
        break;
        case 12:
            if (bob_spending(Bob.holidays.New_year)) Bob.change_happiness(15);
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


void bob_food()
{
    bob_spending(Bob.food);
    Bob.food += Bob.food * (Russia.inflation_Food / 12.0 / 100.0);
}


void bob_car()
{
    bob_spending(Bob.car.gas);
    Bob.car.gas += Bob.car.gas * (Russia.inflation_Car / 12.0 / 100.0);
}


void bob_home()
{
    bob_spending(Bob.home.expenses);
    Bob.home.expenses += Bob.home.expenses * (Russia.inflation_Home / 12.0 / 100.0);
}


void bob_hobby()
{
    bob_spending(Bob.hobby);
    Bob.hobby += Bob.hobby * (Russia.inflation_Hobby / 12.0 / 100.0);
}


void bob_mortage_payment(const int year){
    if (Bob.Tbank.mortage_loan<=0) return;

    static const RUB S = Bob.home.value/Bob.Tbank.mortage_term;
    RUB rates = Bob.Tbank.mortage_loan*Bob.Tbank.mortage_rate/100/12;

    Bob.Tbank.mortage_loan += rates;
    if (Bob.Tbank.mortage_loan>=S){
        if (bob_spending(S + rates)){
            Bob.Tbank.mortage_loan-=S + rates;
        }
        else{
            Bob.Tbank.mortage_loan+=500;
        }
    }
    else{
        if (bob_spending(Bob.Tbank.mortage_loan)){
            Bob.Tbank.mortage_loan-=Bob.Tbank.mortage_loan;
            Bob.change_happiness(50);
        }
        else{
            Bob.Tbank.mortage_loan+=500;
        }
    }

}


void bob_translate_to_savings()
{
    Bob.Tbank.Deposit+=Bob.Tbank.salary_account;
    Bob.Tbank.salary_account=0;
}


void russia_init(){
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
    int year = 2026;
    
    while ( !((month == 3) && (year == 2127)) ) {
        if (Alice.alive){
            alice_bank_interest();
            alice_salary(month, year);
            alice_food();
            alice_home();
            alice_car();
            alice_hobby();
            alice_holiday_expenses(month);
            alice_translate_to_savings();
            Alice.check_happiness(year);
        }
        

        if (Bob.alive){
            bob_bank_interest();
            bob_salary(month, year);
            bob_mortage_payment(year);
            bob_food();
            bob_home();
            bob_car();
            bob_hobby();
            bob_translate_to_savings();
            Bob.check_happiness(year);
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
    russia_init();

    alice_init();

    bob_init();
    
    simulation();
    
    print_results();
}
