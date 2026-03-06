#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>


using RUB = long long int;
using USD = long long int;

using Percent = float;


struct Bank {
    RUB account; 
    RUB deposite; 
    Percent interest; 

    USD account_usd; 
    float rate_usd_rub; 
};


struct Car {
    RUB gas; 
    RUB value; 
};


struct RentApartment {
    RUB rent; 
    RUB housingservices; 
};


struct OwnApartment {
    RUB flat; 
    Percent mortgage; 
    RUB mortgageterm; 
    RUB housingservices; 
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


struct Person {
    std::string name;

    // Банки и накопления
    Bank vtb;

    // Недвижимость
    RentApartment rentflat;
    OwnApartment ownflat;

    // Транспорт
    Car car;
    RUB socialtransport;

    // Доходы
    RUB salary;

    // Расходы
    RUB food;
    RUB telecom;
    RUB healthinsurance;

    // Питомец
    Pet pet;

    std::vector<Loan> loans;
};


struct Person alice;

struct Person bob;


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

    p.vtb.account += p.salary;
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


void person_home(Person &p)
{
    if (p.name == "Alice") {
        p.vtb.account -= p.rentflat.rent;
        p.vtb.account -= p.rentflat.housingservices;
    }
    if (p.name == "Bob") {
        p.vtb.account -= p.rentflat.housingservices;
    }
}


void person_car(Person &p)
{
    p.vtb.account -= p.car.gas;
}


void person_freelance(Person &p, const int month, const int year)
{
    if (month == 3 and year == 2027) {
        p.vtb.account_usd += 3'000;
    }
    if (p.name == "Bob" && month % 6 == 0) {
        p.vtb.account += 5'000;
    }
}


void person_deposite(Person &p, const int month, const int year)
{
    if (year == 2026) p.vtb.interest = 14.5;
    if (year == 2027) p.vtb.interest = 13.5;
    if (year == 2028) p.vtb.interest = 12.5;
    if (year == 2029) p.vtb.interest = 11.5;

    p.vtb.deposite += p.vtb.deposite * (p.vtb.interest / 12.0 / 100.0);

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


// инициализация персон
void alice_init(Person &p)
{
    p.name = "Alice";


    p.vtb.account = 0;
    p.vtb.deposite = 1'000'000;
    p.vtb.interest = 14.5;
    p.salary = 180'000;

    p.vtb.account_usd = 1'000;
    p.vtb.rate_usd_rub = 78.5;

    p.rentflat.rent = 30'000;
    p.rentflat.housingservices = 10'000;

    p.food = 20'000;
    p.telecom = 1'000;
    p.healthinsurance = 20'000;

    p.car.value = 2'400'000;
    p.car.gas = 15'000;

    p.socialtransport = 0;

    p.pet.food = 5'000;
    p.pet.health = 5'000;
    p.pet.toilet = 5'000;
    p.pet.toys = 5'000;

    p.loans.clear();
}


void bob_init(Person &p)
{
    p.name = "Bob";


    p.vtb.account = 0;
    p.vtb.deposite = 100'000;
    p.vtb.interest = 14.5;
    p.salary = 120'000;

    p.vtb.account_usd = 5'000;
    p.vtb.rate_usd_rub = 78.5;

    p.ownflat.flat = 8'000'000;
    p.ownflat.mortgage = 9.5;
    p.ownflat.mortgageterm = 240;
    p.ownflat.housingservices = 8'000;

    p.food = 25'000;
    p.telecom = 1'500;
    p.healthinsurance = 15'000;

    p.car.value = 0;
    p.car.gas = 0;
    p.socialtransport = 3'000;

    p.pet.food = 0;
    p.pet.health = 0;
    p.pet.toilet = 0;
    p.pet.toys = 0;

    Loan mortgage;
    mortgage.principal = p.ownflat.flat;
    mortgage.remaining = p.ownflat.flat;
    mortgage.rate = p.ownflat.mortgage;
    mortgage.months_left = p.ownflat.mortgageterm;
    mortgage.monthly_payment = calculate_annuity_payment(
        mortgage.principal, 
        mortgage.rate, 
        mortgage.months_left
    );

    p.loans.clear();
    p.loans.push_back(mortgage);
        
}


void print_person_results(Person &p)
{
    printf("\n=== %s ===\n", p.name.c_str());
    printf("Salary: %lld RUB\n", p.salary);

    RUB capital = 0;
    capital += p.vtb.account;
    capital += p.car.value;
    capital += p.vtb.deposite;
    capital += p.vtb.account_usd * p.vtb.rate_usd_rub;
    printf("Capital = %lld RUB\n", capital);

}


void simulation(Person &p)
{
    int month = 2;
    int year = 2026;

    while (not (month == 3 and year == 2050)) {


        person_salary(p, month, year);
        person_freelance(p, month, year);
        person_expences(p);
        person_car(p);
        person_pet(p);
        person_insurance(p);
        person_home(p);
        person_loans(p);
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