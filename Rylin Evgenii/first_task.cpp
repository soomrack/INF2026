#include <stdio.h>


// typedef int RUB;  // C
using RUB = long long int;  // C++


struct Car {
    RUB value;
    RUB gas;
};


struct Flat {
    RUB value;
    RUB utilitybills; // коммунальные услуги за квартиру
};

struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    Car car;
    Flat flat;
    RUB full_capital() {
        return capital + car.value + flat.value;
    } // функция, которая находится внутри структуры Person и считает конечный капитал 
};
struct Person alice;


void alice_init()
{
    alice.capital = 0;
    alice.salary = 180'000;
    alice.food = 32'000;

    alice.car.value = 2'400'000;
    alice.car.gas = 12'000;
    
    alice.flat.value = 10'000'000;
    alice.flat.utilitybills = 10'000;
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
    }

    alice.capital += alice.salary;
}


void alice_food()
{
    alice.capital -= alice.food;
}


void print_results()
{
    printf("Salary = %lld\n", alice.salary);
    printf("Total capital = %lld", alice.full_capital());
}


void alice_car()
{
    alice.capital -= alice.car.gas;
}


void alice_bank_interest()
{
    float pp;
    pp = sberbank_interest(alice.capital);
    alice.capital += alice.capital * (pp / 12.0 / 100.0);
}

void alice_trip(int month) {
    if (month == 7) {
        alice.capital -= 175'000;
    }
}

void alice_simulation()
{
    int year = 2026;
    int month = 2;

    while (not (year == 2027 and month == 2)) {
        // my_cat();
        alice_trip(month);
        alice_food();
        alice_car();
        alice_bank_interest();
        alice_salary(year, month);

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
            alice.food *= 1.07; // ужегодное увеличение трат на покупку еды
            alice.car.gas *= 1.07; // ежегодное увеличение трат на бензин
            alice.flat.utilitybills *= 1.07; // ежегодное подорожание коммунальных услуг
            alice.car.value *= 0.92; // ежегодное уменьшение стоимости машины
            alice.flat.value *= 1.07; // ежегодное подорожание квартиры 
            alice.capital += 50'000; // ежегодная премия Алисы в размере 50'000 рублей
        }
    }
}


int main()
{
    alice_init();

    alice_simulation();

    print_results();
}
