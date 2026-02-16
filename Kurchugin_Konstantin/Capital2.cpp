#include <stdio.h>

//typedef int RUB; // Ключевое слово, зарезервировано под функции языка, используют в С
using RUB = long long int; // Используют в С++, можно из одного места поменять типы данных многих переменных

struct Car {
  RUB value;
  RUB gas;
};

struct Person { // создали свой тип данных
  RUB salary;
  RUB capital;
  RUB food;
  Car car;
};

struct Person Alice; // создали переменную типа данных Person

float pp = 14.5;

void alice_car() {
  Alice.capital -= Alice.car.gas;
}

void alice_salary(const int month, const int year) {
  if ((month == 8) && (year == 2026)) { // Promotion
    Alice.salary = Alice.salary * 1.5;
  }
  Alice.capital += Alice.salary;  
}

void print_results() {

  printf("Salary = %lld\n", Alice.salary);
  printf("Capital = %lld", Alice.capital);
}

void alice_food() {
  Alice.capital -= Alice.food;
}

void alice_bank_interest() {


}

void simulation()
{

  int month = 2;
  int year = 2026;

  //  for (int month = 1; month < 19; ++month) {
  while (!((month == 3) && (year == 2127))) {
    Alice.capital += Alice.capital * (pp / 12.0 / 100.0); // Bank interest



    // my_cat()
    // my_trip()
    alice_food();
    alice_car();
    alice_salary(month, year);

    ++month;
    if (month == 13) {
      month = 1;
      ++year;
    }
  }
}

void alice_init() // Присвоили значения характеристик, описывающих переменную данного типа
{
  Alice.capital = 0;
  Alice.salary = 180000;
  Alice.food = 20000;

  Alice.car.value = 2400000;
  Alice.car.gas = 15000;
}


int main()
{ 
  alice_init();

  simulation();
  
  print_results();

}


// long int - int хранит 4 байта, а не 2, в принте надо менять отдельно
