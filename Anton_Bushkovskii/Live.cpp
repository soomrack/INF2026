#include <stdio.h>


// typedef int RUB;  // C
using RUB = long long int;  // C++
using AGE = int;
using RUBS = long long int;
using DAY = int;
struct Car {
    RUB value;
    RUB gas;
};
struct Hams{
    RUB care;
    AGE age;
    RUB value;
};
struct Trip{
    RUB value;
    DAY days;
    int intrip;
};
struct Person {
    RUB bank;
    RUB salary;
    RUB capital;
    RUB food;
    Car car;
    Trip trip;
    Hams hams;
};
struct Person alice;


void alice_init()
{
    alice.bank=50'000;
    //допустим она молодец и держит все деньги на кате на вкладе с свободным добавлением и обналичиванием средств
    
    alice.capital = 0;
    alice.salary = 180'000;
    alice.hams.care = 5000;
    alice.hams.value= 2000;
    alice.hams.age = 2;
    alice.trip.value=165000;
    alice.trip.intrip=0;
    alice.food = 15'000;
    alice.trip.days=10;
    alice.car.value = 2'400'000;
    alice.car.gas = 12'000;
}


float sberbank_interest(RUB sum)
{
    if (sum > 10'000 and sum < 3'000'000) {
        return 11.5;
    }

    if (sum >= 3'000'000) {
        return 12.5;  //  125 -1 +
    }

    return 0.1;
}


void alice_salary(const int year, const int month)
{
    if (month == 3 and year == 2026) {
        alice.salary *= 1.5;
    };
    if (alice.trip.intrip==1){
        alice.bank+= (alice.salary*(2/3));
        alice.trip.intrip=0;
    };
    if (alice.trip.intrip==0){
        alice.bank+= alice.salary;
    };
}
void trip()
{
    if (alice.bank>=650000 and alice.trip.intrip==0){
        alice.bank-=alice.trip.value;
        alice.trip.intrip=1;
    }
}
void hams_dead()
{
    if (alice.hams.age>=3){
        alice.bank-= alice.hams.value;
        alice.hams.age=1;
    }

}
void alice_care()
{
    alice.bank -= alice.hams.care*(alice.hams.age/10+1);
}
void alice_food()
{
    alice.bank -= alice.food;
}


void print_results()
{
    alice.capital=alice.bank+alice.car.value+alice.hams.value;
    printf("Salary = %lld\n", alice.salary);
    printf("Capital = %lld\n", alice.capital);
    printf("Bank = %lld", alice.bank);
    printf("Бушковский лох");
}


void alice_car()
{
    alice.bank -= alice.car.gas;
}


void alice_bank_interest()
{
    float pp;
    pp = sberbank_interest(alice.bank);
    alice.bank += alice.bank * (pp / 12.0 / 100.0);
}


void alice_simulation()
{
    int year = 2026;
    int month = 2;
    
    while ( not (year == 2027 and month == 2) ) {
        alice_care();
        hams_dead();
        trip();
        alice_food();
        alice_car();
        alice_bank_interest();
        alice_salary(year, month);
        
        ++month;
        if (month == 13) {
            ++year;
            alice.hams.age+=1;
            month = 1;
        }
    }
}


int main()
{

    alice_init();
    
    alice_simulation();
    
    print_results();

}