#include <stdio.h>

// typedef int RUB // C

using RUB = long long int; // C++

struct Car {
    RUB value;
    RUB gas;
}
struct Person {
RUB salary;
RUB capital;
RUB food;
RUN car;
};
struct Persen Alice;


void print(){
    printf("Salary = %lld\n", salary);
    printf("Capital = %lld", capital);
}
void alice_init(){
    Alice.salary = 10000;
    Alice.capital = 50000;
    Alice.food = 2000;
}

void alice_salary(const int month, const int year) {
  if ((month == 8) && (year == 2026)) { // Promotion
      Alice.salary *= 1.5;
  }
Alice.capital += Alice.salary;
}

void alice_food(){
    Alice.capital -= Alice.food;
}

void simulation(){
    float pp = 14.5;

    int month = 2;
    int year = 2026;

  //  for (int month = 1; month < 19; ++month) {
    while (!((month == 3) && (year == 2027))) {
      capital += capital * (pp / 12.0 / 100.0); // Bank interest

      alice_food();
      alice_salary(month, year);

      ++month;
      if (month == 13) {
        month = 1;
        ++year;
      }
    }
}


int main()
{
    alice_init();

    simulation();
    print();
}
