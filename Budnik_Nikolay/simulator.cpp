#include <stdio.h>

using RUB = long long;
using Percent = double;
using MonthNumber = int;
using YearNumber = int;

const MonthNumber start_month = 2;
const YearNumber start_year = 2026;
const MonthNumber end_month = 3;
const YearNumber end_year = 2036;
const int history_capacity = 140;
const int dilshot_id = 1;
const int analbek_id = 2;

const Percent deposit_rate = 8.0;
const Percent food_inflation = 0.70;
const Percent utility_inflation = 0.60;
const Percent home_inflation = 0.50;
const Percent pet_inflation = 0.55;
const Percent car_inflation = 0.45;
const Percent family_inflation = 0.50;
const Percent health_inflation = 0.65;
const Percent other_inflation = 0.40;

struct Food {
  RUB bread;
  RUB milk;
  RUB eggs;
  const Percent food_inflation = 0.70;
  RUB meat;
  RUB fish;
  RUB vegetables;
  RUB fruits;
  RUB cereals;
  RUB drinks;
  RUB snacks;
};

struct Utility {
  RUB electricity;
  RUB water;
  RUB heating;
  RUB internet;
  RUB mobile;
  RUB cleaning;
};

struct Home {
  bool own;
  RUB rent;
  RUB value;
  RUB repair;
  RUB insurance;
  RUB furniture;
};

struct Pet {
  bool have;
  bool alive;
  MonthNumber death_month;
  YearNumber death_year;
  RUB feed;
  RUB vet;
  RUB medicine;
  RUB toys;
};

struct Car {
  bool have;
  RUB value;
  RUB fuel;
  RUB service;
  RUB insurance;
  RUB parking;
  RUB repair;
  RUB tax;
};

struct Family {
  bool married;
  int children;
  RUB food;
  RUB school;
  RUB clothes;
  RUB medicine;
  RUB hobby;
  RUB gifts;
};

struct Health {
  int hp;
  RUB doctor;
  RUB medicine;
  RUB sport;
  RUB dentist;
  RUB checkup;
};

struct Other {
  RUB clothes;
  RUB communication;
  RUB study;
  RUB entertainment;
  RUB travel;
  RUB gifts;
  RUB small_things;
};

struct Bank {
  RUB account;
  RUB deposit;
  RUB mortgage;
  RUB car_loan;
  RUB consumer_loan;
  RUB mortgage_payment;
  RUB car_loan_payment;
  RUB consumer_loan_payment;
  Percent mortgage_rate;
  Percent car_loan_rate;
  Percent consumer_loan_rate;
};

struct Work {
  bool taxi;
  RUB salary;
  RUB taxi_orders;
  RUB taxi_expenses;
  RUB bonus;
};

struct MonthSnapshot {
  MonthNumber month;
  YearNumber year;
  RUB account;
  RUB deposit;
  RUB debt;
  RUB capital;
  RUB income;
  RUB expenses;
  RUB credit_payment;
  RUB unexpected;
};

struct Person {
  const char *name;
  int id;
  int age;
  Food food;
  Utility utility;
  Home home;
  Pet pet;
  Car car;
  Family family;
  Health health;
  Other other;
  Bank bank;
  Work work;
  MonthSnapshot history[history_capacity];
  int history_count;
};

Person dilshot;
Person analbek;

void init_dilshot() {
  dilshot.name = "Dilshot";
  dilshot.id = dilshot_id;
  dilshot.age = 32;

  dilshot.food.bread = 1'200;
  dilshot.food.milk = 900;
  dilshot.food.eggs = 1'400;
  dilshot.food.meat = 6'500;
  dilshot.food.fish = 2'300;
  dilshot.food.vegetables = 3'800;
  dilshot.food.fruits = 3'100;
  dilshot.food.cereals = 1'700;
  dilshot.food.drinks = 1'400;
  dilshot.food.snacks = 1'600;

  dilshot.utility.electricity = 3'400;
  dilshot.utility.water = 1'100;
  dilshot.utility.heating = 4'800;
  dilshot.utility.internet = 900;
  dilshot.utility.mobile = 700;
  dilshot.utility.cleaning = 1'600;

  dilshot.home.own = true;
  dilshot.home.rent = 0;
  dilshot.home.value = 4'800'000;
  dilshot.home.repair = 2'000;
  dilshot.home.insurance = 1'200;
  dilshot.home.furniture = 1'500;

  dilshot.pet.have = true;
  dilshot.pet.alive = true;
  dilshot.pet.death_month = 7;
  dilshot.pet.death_year = 2033;
  dilshot.pet.feed = 3'500;
  dilshot.pet.vet = 1'200;
  dilshot.pet.medicine = 700;
  dilshot.pet.toys = 500;

  dilshot.car.have = true;
  dilshot.car.value = 1'000'000;
  dilshot.car.fuel = 14'000;
  dilshot.car.service = 4'500;
  dilshot.car.insurance = 5'000;
  dilshot.car.parking = 2'500;
  dilshot.car.repair = 3'500;
  dilshot.car.tax = 1'500;

  dilshot.family.married = true;
  dilshot.family.children = 1;
  dilshot.family.food = 8'000;
  dilshot.family.school = 7'000;
  dilshot.family.clothes = 3'500;
  dilshot.family.medicine = 1'500;
  dilshot.family.hobby = 4'000;
  dilshot.family.gifts = 2'500;

  dilshot.health.hp = 82;
  dilshot.health.doctor = 2'500;
  dilshot.health.medicine = 1'500;
  dilshot.health.sport = 3'000;
  dilshot.health.dentist = 2'000;
  dilshot.health.checkup = 1'000;

  dilshot.other.clothes = 4'500;
  dilshot.other.communication = 1'000;
  dilshot.other.study = 1'500;
  dilshot.other.entertainment = 5'000;
  dilshot.other.travel = 6'000;
  dilshot.other.gifts = 2'000;
  dilshot.other.small_things = 2'500;

  dilshot.bank.account = 20'000;
  dilshot.bank.deposit = 50'000;
  dilshot.bank.mortgage = 3'000'000;
  dilshot.bank.car_loan = 350'000;
  dilshot.bank.consumer_loan = 120'000;
  dilshot.bank.mortgage_payment = 40'000;
  dilshot.bank.car_loan_payment = 12'000;
  dilshot.bank.consumer_loan_payment = 8'000;
  dilshot.bank.mortgage_rate = 0.0;
  dilshot.bank.car_loan_rate = 5.0;
  dilshot.bank.consumer_loan_rate = 8.0;

  dilshot.work.taxi = true;
  dilshot.work.salary = 0;
  dilshot.work.taxi_orders = 230'000;
  dilshot.work.taxi_expenses = 50'000;
  dilshot.work.bonus = 30'000;

  dilshot.history_count = 0;
}

void init_analbek() {
  analbek.name = "Analbek";
  analbek.id = analbek_id;
  analbek.age = 35;

  analbek.food.bread = 1'100;
  analbek.food.milk = 800;
  analbek.food.eggs = 1'200;
  analbek.food.meat = 5'500;
  analbek.food.fish = 1'800;
  analbek.food.vegetables = 3'300;
  analbek.food.fruits = 2'800;
  analbek.food.cereals = 1'400;
  analbek.food.drinks = 1'000;
  analbek.food.snacks = 1'100;

  analbek.utility.electricity = 2'700;
  analbek.utility.water = 900;
  analbek.utility.heating = 3'500;
  analbek.utility.internet = 800;
  analbek.utility.mobile = 700;
  analbek.utility.cleaning = 1'200;

  analbek.home.own = false;
  analbek.home.rent = 38'000;
  analbek.home.value = 0;
  analbek.home.repair = 700;
  analbek.home.insurance = 0;
  analbek.home.furniture = 1'000;

  analbek.pet.have = false;
  analbek.pet.alive = false;
  analbek.pet.death_month = 0;
  analbek.pet.death_year = 0;
  analbek.pet.feed = 0;
  analbek.pet.vet = 0;
  analbek.pet.medicine = 0;
  analbek.pet.toys = 0;

  analbek.car.have = false;
  analbek.car.value = 0;
  analbek.car.fuel = 0;
  analbek.car.service = 0;
  analbek.car.insurance = 0;
  analbek.car.parking = 0;
  analbek.car.repair = 0;
  analbek.car.tax = 0;

  analbek.family.married = true;
  analbek.family.children = 2;
  analbek.family.food = 13'000;
  analbek.family.school = 11'000;
  analbek.family.clothes = 5'000;
  analbek.family.medicine = 2'000;
  analbek.family.hobby = 5'500;
  analbek.family.gifts = 3'000;

  analbek.health.hp = 70;
  analbek.health.doctor = 3'500;
  analbek.health.medicine = 2'500;
  analbek.health.sport = 0;
  analbek.health.dentist = 2'500;
  analbek.health.checkup = 1'000;

  analbek.other.clothes = 3'500;
  analbek.other.communication = 900;
  analbek.other.study = 1'000;
  analbek.other.entertainment = 3'000;
  analbek.other.travel = 3'000;
  analbek.other.gifts = 1'500;
  analbek.other.small_things = 2'000;

  analbek.bank.account = 10'000;
  analbek.bank.deposit = 0;
  analbek.bank.mortgage = 0;
  analbek.bank.car_loan = 0;
  analbek.bank.consumer_loan = 250'000;
  analbek.bank.mortgage_payment = 0;
  analbek.bank.car_loan_payment = 0;
  analbek.bank.consumer_loan_payment = 12'000;
  analbek.bank.mortgage_rate = 0.0;
  analbek.bank.car_loan_rate = 0.0;
  analbek.bank.consumer_loan_rate = 12.0;

  analbek.work.taxi = false;
  analbek.work.salary = 135'000;
  analbek.work.taxi_orders = 0;
  analbek.work.taxi_expenses = 0;
  analbek.work.bonus = 15'000;

  analbek.history_count = 0;
}

void init_people() {
  init_dilshot();
  init_analbek();
}

RUB total_food(const Food &food) {
  RUB total = 0;
  total += food.bread;
  total += food.milk;
  total += food.eggs;
  total += food.meat;
  total += food.fish;
  total += food.vegetables;
  total += food.fruits;
  total += food.cereals;
  total += food.drinks;
  total += food.snacks;
  return total;
}

RUB total_utility(const Utility &utility) {
  RUB total = 0;
  total += utility.electricity;
  total += utility.water;
  total += utility.heating;
  total += utility.internet;
  total += utility.mobile;
  total += utility.cleaning;
  return total;
}

RUB total_home(const Home &home) {
  RUB total = 0;
  if (!home.own) {
    total += home.rent;
  }
  total += home.repair;
  total += home.insurance;
  total += home.furniture;
  return total;
}

RUB total_pet(const Pet &pet) {
  RUB total = 0;
  if (pet.have && pet.alive) {
    total += pet.feed;
    total += pet.vet;
    total += pet.medicine;
    total += pet.toys;
  }
  return total;
}

RUB total_car(const Car &car) {
  RUB total = 0;
  if (car.have) {
    total += car.fuel;
    total += car.service;
    total += car.insurance;
    total += car.parking;
    total += car.repair;
    total += car.tax;
  }
  return total;
}

RUB total_family(const Family &family) {
  RUB total = 0;
  if (family.married) {
    total += family.food;
    total += family.school;
    total += family.clothes;
    total += family.medicine;
    total += family.hobby;
    total += family.gifts;
  }
  return total;
}

RUB total_health(const Health &health) {
  RUB total = 0;
  total += health.doctor;
  total += health.medicine;
  total += health.sport;
  total += health.dentist;
  total += health.checkup;
  return total;
}

RUB total_other(const Other &other) {
  RUB total = 0;
  total += other.clothes;
  total += other.communication;
  total += other.study;
  total += other.entertainment;
  total += other.travel;
  total += other.gifts;
  total += other.small_things;
  return total;
}

RUB total_basic_expenses(const Person &person) {
  RUB total = 0;
  total += total_food(person.food);
  total += total_utility(person.utility);
  total += total_home(person.home);
  total += total_pet(person.pet);
  total += total_car(person.car);
  total += total_family(person.family);
  total += total_health(person.health);
  total += total_other(person.other);
  return total;
}

RUB total_debt(const Person &person) {
  return person.bank.mortgage + person.bank.car_loan +
         person.bank.consumer_loan;
}

RUB total_assets(const Person &person) {
  RUB total = 0;
  total += person.bank.account;
  total += person.bank.deposit;
  if (person.home.own) {
    total += person.home.value;
  }
  if (person.car.have) {
    total += person.car.value;
  }
  return total;
}

RUB capital(const Person &person) {
  return total_assets(person) - total_debt(person);
}

RUB taxi_income(const Person &person) {
  RUB service_fee = (RUB)((double)person.work.taxi_orders * 22.0 / 100.0);
  RUB income = person.work.taxi_orders;
  income -= service_fee;
  income -= person.work.taxi_expenses;
  if (income < 0) {
    income = 0;
  }
  return income;
}

RUB base_income(const Person &person) {
  if (person.work.taxi) {
    return taxi_income(person);
  }
  return person.work.salary;
}

RUB bonus_income(const Person &person, MonthNumber month, YearNumber year) {
  (void)year;
  if (month == 12) {
    return person.work.bonus;
  }
  return 0;
}

RUB growth_income(const Person &person, YearNumber year) {
  if (person.id == dilshot_id && year >= 2030) {
    return 15'000;
  }
  if (person.id == analbek_id && year >= 2031) {
    return 12'000;
  }
  return 0;
}

RUB income_for_month(const Person &person, MonthNumber month, YearNumber year) {
  RUB income = 0;
  income += base_income(person);
  income += bonus_income(person, month, year);
  income += growth_income(person, year);
  return income;
}

RUB personal_unexpected_cost(const Person &person, MonthNumber month,
                             YearNumber year) {
  int code = person.id * 17 + month * 11 + year;
  if (code % 13 == 0) {
    return 9'000 + person.id * 1'000;
  }
  if (code % 17 == 0) {
    return 15'000;
  }
  return 0;
}

RUB common_unexpected_cost(MonthNumber month, YearNumber year) {
  if (month == 3 && year == 2028) {
    return 18'000;
  }
  if (month == 10 && year == 2032) {
    return 24'000;
  }
  if (month == 6 && year == 2035) {
    return 12'000;
  }
  return 0;
}

RUB unexpected_cost(const Person &person, MonthNumber month, YearNumber year) {
  RUB cost = 0;
  cost += personal_unexpected_cost(person, month, year);
  cost += common_unexpected_cost(month, year);
  return cost;
}

RUB credit_payment(RUB &debt, RUB payment) {
  if (debt <= 0) {
    return 0;
  }
  if (debt < payment) {
    RUB paid = debt;
    debt = 0;
    return paid;
  }
  debt -= payment;
  return payment;
}

void add_credit_interest(RUB &debt, Percent annual_rate) {
  if (debt > 0) {
    debt += (RUB)((double)debt * (annual_rate / 12.0) / 100.0);
  }
}

RUB pay_credit(RUB &debt, RUB payment, Percent annual_rate) {
  RUB paid = credit_payment(debt, payment);
  add_credit_interest(debt, annual_rate);
  return paid;
}

void update_pet(Person &person, MonthNumber month, YearNumber year) {
  if (person.pet.have && person.pet.alive) {
    bool pet_life_finished = false;

    if (year > person.pet.death_year) {
      pet_life_finished = true;
    }

    if (year == person.pet.death_year && month >= person.pet.death_month) {
      pet_life_finished = true;
    }

    if (pet_life_finished) {
      person.pet.alive = false;
      person.pet.feed = 0;
      person.pet.vet = 0;
      person.pet.medicine = 0;
      person.pet.toys = 0;
    }
  }
}

void update_health(Person &person, MonthNumber month) {
  if (month == 1 || month == 2) {
    person.health.hp -= 1;
  }
  if (person.bank.account < 0) {
    person.health.hp -= 2;
  }
  if (person.health.sport > 0) {
    person.health.hp += 1;
  }
  if (person.health.hp > 100) {
    person.health.hp = 100;
  }
  if (person.health.hp < 0) {
    person.health.hp = 0;
  }
}

void update_age(Person &person, MonthNumber month) {
  if (month == 1) {
    person.age++;
  }
}

void save_history(Person &person, MonthNumber month, YearNumber year,
                  RUB income, RUB expenses, RUB credit_payment,
                  RUB unexpected) {
  if (person.history_count >= history_capacity) {
    return;
  }
  int index = person.history_count;
  person.history[index].month = month;
  person.history[index].year = year;
  person.history[index].account = person.bank.account;
  person.history[index].deposit = person.bank.deposit;
  person.history[index].debt = total_debt(person);
  person.history[index].capital = capital(person);
  person.history[index].income = income;
  person.history[index].expenses = expenses;
  person.history[index].credit_payment = credit_payment;
  person.history[index].unexpected = unexpected;
  person.history_count++;
}

void receive_salary_or_taxi_income(Person &person, RUB &month_income) {
  RUB main_income = base_income(person);

  person.bank.account += main_income;
  month_income += main_income;
}

void receive_bonus_and_growth_income(Person &person, MonthNumber month,
                                     YearNumber year, RUB &month_income) {
  RUB extra_income = 0;

  extra_income += bonus_income(person, month, year);
  extra_income += growth_income(person, year);

  person.bank.account += extra_income;
  month_income += extra_income;
}

void pay_food_with_inflation(Person &person, RUB &month_expenses) {
  person.food.bread +=
      (RUB)((double)person.food.bread * food_inflation / 100.0);
  person.food.milk += (RUB)((double)person.food.milk * food_inflation / 100.0);
  person.food.eggs += (RUB)((double)person.food.eggs * food_inflation / 100.0);
  person.food.meat += (RUB)((double)person.food.meat * food_inflation / 100.0);
  person.food.fish += (RUB)((double)person.food.fish * food_inflation / 100.0);
  person.food.vegetables +=
      (RUB)((double)person.food.vegetables * food_inflation / 100.0);
  person.food.fruits +=
      (RUB)((double)person.food.fruits * food_inflation / 100.0);
  person.food.cereals +=
      (RUB)((double)person.food.cereals * food_inflation / 100.0);
  person.food.drinks +=
      (RUB)((double)person.food.drinks * food_inflation / 100.0);
  person.food.snacks +=
      (RUB)((double)person.food.snacks * food_inflation / 100.0);

  RUB food_cost = total_food(person.food);

  person.bank.account -= food_cost;
  month_expenses += food_cost;
}

void pay_utility_with_inflation(Person &person, RUB &month_expenses) {
  person.utility.electricity +=
      (RUB)((double)person.utility.electricity * utility_inflation / 100.0);
  person.utility.water +=
      (RUB)((double)person.utility.water * utility_inflation / 100.0);
  person.utility.heating +=
      (RUB)((double)person.utility.heating * utility_inflation / 100.0);
  person.utility.internet +=
      (RUB)((double)person.utility.internet * utility_inflation / 100.0);
  person.utility.mobile +=
      (RUB)((double)person.utility.mobile * utility_inflation / 100.0);
  person.utility.cleaning +=
      (RUB)((double)person.utility.cleaning * utility_inflation / 100.0);

  RUB utility_cost = total_utility(person.utility);

  person.bank.account -= utility_cost;
  month_expenses += utility_cost;
}

void pay_home_with_inflation(Person &person, RUB &month_expenses) {
  person.home.rent += (RUB)((double)person.home.rent * home_inflation / 100.0);
  person.home.repair +=
      (RUB)((double)person.home.repair * home_inflation / 100.0);
  person.home.insurance +=
      (RUB)((double)person.home.insurance * home_inflation / 100.0);
  person.home.value +=
      (RUB)((double)person.home.value * home_inflation / 100.0);

  RUB home_cost = total_home(person.home);

  person.bank.account -= home_cost;
  month_expenses += home_cost;
}

void pay_pet_with_inflation(Person &person, RUB &month_expenses) {
  person.pet.feed += (RUB)((double)person.pet.feed * pet_inflation / 100.0);
  person.pet.vet += (RUB)((double)person.pet.vet * pet_inflation / 100.0);
  person.pet.medicine +=
      (RUB)((double)person.pet.medicine * pet_inflation / 100.0);
  person.pet.toys += (RUB)((double)person.pet.toys * pet_inflation / 100.0);

  RUB pet_cost = total_pet(person.pet);

  person.bank.account -= pet_cost;
  month_expenses += pet_cost;
}

void pay_car_with_inflation(Person &person, RUB &month_expenses) {
  person.car.fuel += (RUB)((double)person.car.fuel * car_inflation / 100.0);
  person.car.service +=
      (RUB)((double)person.car.service * car_inflation / 100.0);
  person.car.insurance +=
      (RUB)((double)person.car.insurance * car_inflation / 100.0);
  person.car.repair += (RUB)((double)person.car.repair * car_inflation / 100.0);
  person.car.parking +=
      (RUB)((double)person.car.parking * car_inflation / 100.0);
  person.car.tax += (RUB)((double)person.car.tax * car_inflation / 100.0);
  person.car.value += (RUB)((double)person.car.value * car_inflation / 100.0);

  RUB car_cost = total_car(person.car);

  person.bank.account -= car_cost;
  month_expenses += car_cost;
}

void pay_family_with_inflation(Person &person, RUB &month_expenses) {
  person.family.food +=
      (RUB)((double)person.family.food * family_inflation / 100.0);
  person.family.school +=
      (RUB)((double)person.family.school * family_inflation / 100.0);
  person.family.clothes +=
      (RUB)((double)person.family.clothes * family_inflation / 100.0);
  person.family.medicine +=
      (RUB)((double)person.family.medicine * family_inflation / 100.0);
  person.family.hobby +=
      (RUB)((double)person.family.hobby * family_inflation / 100.0);
  person.family.gifts +=
      (RUB)((double)person.family.gifts * family_inflation / 100.0);

  RUB family_cost = total_family(person.family);

  person.bank.account -= family_cost;
  month_expenses += family_cost;
}

void pay_health_with_inflation(Person &person, RUB &month_expenses) {
  person.health.doctor +=
      (RUB)((double)person.health.doctor * health_inflation / 100.0);
  person.health.medicine +=
      (RUB)((double)person.health.medicine * health_inflation / 100.0);
  person.health.sport +=
      (RUB)((double)person.health.sport * health_inflation / 100.0);
  person.health.dentist +=
      (RUB)((double)person.health.dentist * health_inflation / 100.0);
  person.health.checkup +=
      (RUB)((double)person.health.checkup * health_inflation / 100.0);

  RUB health_cost = total_health(person.health);

  person.bank.account -= health_cost;
  month_expenses += health_cost;
}

void pay_other_with_inflation(Person &person, RUB &month_expenses) {
  person.other.clothes +=
      (RUB)((double)person.other.clothes * other_inflation / 100.0);
  person.other.communication +=
      (RUB)((double)person.other.communication * other_inflation / 100.0);
  person.other.study +=
      (RUB)((double)person.other.study * other_inflation / 100.0);
  person.other.entertainment +=
      (RUB)((double)person.other.entertainment * other_inflation / 100.0);
  person.other.travel +=
      (RUB)((double)person.other.travel * other_inflation / 100.0);
  person.other.gifts +=
      (RUB)((double)person.other.gifts * other_inflation / 100.0);
  person.other.small_things +=
      (RUB)((double)person.other.small_things * other_inflation / 100.0);

  RUB other_cost = total_other(person.other);

  person.bank.account -= other_cost;
  month_expenses += other_cost;
}

void pay_unexpected_expenses(Person &person, MonthNumber month, YearNumber year,
                             RUB &month_unexpected) {
  RUB unexpected = unexpected_cost(person, month, year);

  person.bank.account -= unexpected;
  month_unexpected += unexpected;
}

void pay_mortgage_with_interest(Person &person, RUB &month_credit_payment) {
  if (person.bank.mortgage > 0) {
    RUB payment = person.bank.mortgage_payment;

    if (person.bank.mortgage < payment) {
      payment = person.bank.mortgage;
    }

    person.bank.mortgage -= payment;
    person.bank.account -= payment;
    month_credit_payment += payment;

    if (person.bank.mortgage > 0) {
      RUB interest = (RUB)((double)person.bank.mortgage *
                           (person.bank.mortgage_rate / 12.0) / 100.0);
      person.bank.mortgage += interest;
    }
  }
}

void pay_car_loan_with_interest(Person &person, RUB &month_credit_payment) {
  if (person.bank.car_loan > 0) {
    RUB payment = person.bank.car_loan_payment;

    if (person.bank.car_loan < payment) {
      payment = person.bank.car_loan;
    }

    person.bank.car_loan -= payment;
    person.bank.account -= payment;
    month_credit_payment += payment;

    if (person.bank.car_loan > 0) {
      RUB interest = (RUB)((double)person.bank.car_loan *
                           (person.bank.car_loan_rate / 12.0) / 100.0);
      person.bank.car_loan += interest;
    }
  }
}

void pay_consumer_loan_with_interest(Person &person,
                                     RUB &month_credit_payment) {
  if (person.bank.consumer_loan > 0) {
    RUB payment = person.bank.consumer_loan_payment;

    if (person.bank.consumer_loan < payment) {
      payment = person.bank.consumer_loan;
    }

    person.bank.consumer_loan -= payment;
    person.bank.account -= payment;
    month_credit_payment += payment;

    if (person.bank.consumer_loan > 0) {
      RUB interest = (RUB)((double)person.bank.consumer_loan *
                           (person.bank.consumer_loan_rate / 12.0) / 100.0);
      person.bank.consumer_loan += interest;
    }
  }
}

void cover_negative_account(Person &person) {
  if (person.bank.account >= 0) {
    return;
  }

  RUB account_shortage = -person.bank.account;

  if (person.bank.deposit >= account_shortage) {
    person.bank.deposit -= account_shortage;
    person.bank.account = 0;
    return;
  }

  account_shortage -= person.bank.deposit;
  person.bank.deposit = 0;
  person.bank.account = 0;
  person.bank.consumer_loan += account_shortage;
}

void move_extra_money_to_deposit(Person &person) {
  RUB reserve = total_basic_expenses(person);

  if (person.bank.account > reserve) {
    RUB free_money = person.bank.account - reserve;

    person.bank.account -= free_money;
    person.bank.deposit += free_money;
  }
}

void update_account_after_payments(Person &person) {
  cover_negative_account(person);
  move_extra_money_to_deposit(person);
}

void receive_deposit_income(Person &person, RUB &month_income) {
  RUB deposit_interest =
      (RUB)((double)person.bank.deposit * (deposit_rate / 12.0) / 100.0);

  person.bank.deposit += deposit_interest;
  month_income += deposit_interest;
}

void simulate_month(Person &person, MonthNumber month, YearNumber year) {
  RUB month_income = 0;
  RUB month_expenses = 0;
  RUB month_unexpected = 0;
  RUB month_credit_payment = 0;

  update_pet(person, month, year);

  receive_deposit_income(person, month_income);
  receive_salary_or_taxi_income(person, month_income);
  receive_bonus_and_growth_income(person, month, year, month_income);

  pay_food_with_inflation(person, month_expenses);
  pay_utility_with_inflation(person, month_expenses);
  pay_home_with_inflation(person, month_expenses);
  pay_pet_with_inflation(person, month_expenses);
  pay_car_with_inflation(person, month_expenses);
  pay_family_with_inflation(person, month_expenses);
  pay_health_with_inflation(person, month_expenses);
  pay_other_with_inflation(person, month_expenses);

  pay_unexpected_expenses(person, month, year, month_unexpected);

  pay_mortgage_with_interest(person, month_credit_payment);
  pay_car_loan_with_interest(person, month_credit_payment);
  pay_consumer_loan_with_interest(person, month_credit_payment);

  update_account_after_payments(person);

  update_health(person, month);
  update_age(person, month);

  save_history(person, month, year, month_income, month_expenses,
               month_credit_payment, month_unexpected);
}

void simulate_year_for_people(Person &dilshot_person, Person &analbek_person,
                              YearNumber year) {
  MonthNumber first_month = 1;
  MonthNumber last_month = 12;

  if (year == start_year) {
    first_month = start_month;
  }

  if (year == end_year) {
    last_month = end_month - 1;
  }

  for (MonthNumber month = first_month; month <= last_month; month++) {
    simulate_month(dilshot_person, month, year);
    simulate_month(analbek_person, month, year);
  }
}

void simulate(Person &dilshot_person, Person &analbek_person) {
  for (YearNumber year = start_year; year <= end_year; year++) {
    simulate_year_for_people(dilshot_person, analbek_person, year);
  }
}

RUB history_income_for_year(const Person &person, YearNumber year) {
  RUB total = 0;
  int index = 0;
  while (index < person.history_count) {
    if (person.history[index].year == year) {
      total += person.history[index].income;
    }
    index++;
  }
  return total;
}

RUB history_expenses_for_year(const Person &person, YearNumber year) {
  RUB total = 0;
  int index = 0;
  while (index < person.history_count) {
    if (person.history[index].year == year) {
      total += person.history[index].expenses;
    }
    index++;
  }
  return total;
}

RUB history_credit_for_year(const Person &person, YearNumber year) {
  RUB total = 0;
  int index = 0;
  while (index < person.history_count) {
    if (person.history[index].year == year) {
      total += person.history[index].credit_payment;
    }
    index++;
  }
  return total;
}

RUB history_unexpected_for_year(const Person &person, YearNumber year) {
  RUB total = 0;
  int index = 0;
  while (index < person.history_count) {
    if (person.history[index].year == year) {
      total += person.history[index].unexpected;
    }
    index++;
  }
  return total;
}

int score(const Person &person) {
  int result = 50;
  RUB person_capital = capital(person);
  RUB debt = total_debt(person);
  if (person_capital > 5'000'000) {
    result += 25;
  } else if (person_capital > 2'000'000) {
    result += 15;
  } else if (person_capital > 0) {
    result += 5;
  } else {
    result -= 20;
  }
  if (debt == 0) {
    result += 15;
  } else if (debt < 500'000) {
    result += 5;
  } else {
    result -= 10;
  }
  if (person.bank.deposit > total_basic_expenses(person) * 3) {
    result += 10;
  }
  if (person.health.hp < 50) {
    result -= 10;
  }
  if (result < 0) {
    result = 0;
  }
  if (result > 100) {
    result = 100;
  }
  return result;
}

void print_money_line(const char *title, RUB value) {
  printf("%-28s %lld RUB\n", title, value);
}

void print_food(const Food &food) {
  printf("food\n");
  print_money_line("bread", food.bread);
  print_money_line("milk", food.milk);
  print_money_line("eggs", food.eggs);
  print_money_line("meat", food.meat);
  print_money_line("fish", food.fish);
  print_money_line("vegetables", food.vegetables);
  print_money_line("fruits", food.fruits);
  print_money_line("cereals", food.cereals);
  print_money_line("drinks", food.drinks);
  print_money_line("snacks", food.snacks);
  print_money_line("total food", total_food(food));
}

void print_utility(const Utility &utility) {
  printf("utility\n");
  print_money_line("electricity", utility.electricity);
  print_money_line("water", utility.water);
  print_money_line("heating", utility.heating);
  print_money_line("internet", utility.internet);
  print_money_line("mobile", utility.mobile);
  print_money_line("cleaning", utility.cleaning);
  print_money_line("total utility", total_utility(utility));
}

void print_home(const Home &home) {
  printf("home\n");
  printf("own: %s\n", home.own ? "yes" : "no");
  print_money_line("rent", home.rent);
  print_money_line("value", home.value);
  print_money_line("repair", home.repair);
  print_money_line("insurance", home.insurance);
  print_money_line("furniture", home.furniture);
  print_money_line("total home", total_home(home));
}

void print_pet(const Pet &pet) {
  printf("pet\n");
  printf("have: %s\n", pet.have ? "yes" : "no");
  printf("alive: %s\n", pet.alive ? "yes" : "no");
  print_money_line("feed", pet.feed);
  print_money_line("vet", pet.vet);
  print_money_line("medicine", pet.medicine);
  print_money_line("toys", pet.toys);
  print_money_line("total pet", total_pet(pet));
}

void print_car(const Car &car) {
  printf("car\n");
  printf("have: %s\n", car.have ? "yes" : "no");
  print_money_line("value", car.value);
  print_money_line("fuel", car.fuel);
  print_money_line("service", car.service);
  print_money_line("insurance", car.insurance);
  print_money_line("parking", car.parking);
  print_money_line("repair", car.repair);
  print_money_line("tax", car.tax);
  print_money_line("total car", total_car(car));
}

void print_family(const Family &family) {
  printf("family\n");
  printf("married: %s\n", family.married ? "yes" : "no");
  printf("children: %d\n", family.children);
  print_money_line("family food", family.food);
  print_money_line("school", family.school);
  print_money_line("clothes", family.clothes);
  print_money_line("medicine", family.medicine);
  print_money_line("hobby", family.hobby);
  print_money_line("gifts", family.gifts);
  print_money_line("total family", total_family(family));
}

void print_health(const Health &health) {
  printf("health\n");
  printf("hp: %d\n", health.hp);
  print_money_line("doctor", health.doctor);
  print_money_line("medicine", health.medicine);
  print_money_line("sport", health.sport);
  print_money_line("dentist", health.dentist);
  print_money_line("checkup", health.checkup);
  print_money_line("total health", total_health(health));
}

void print_other(const Other &other) {
  printf("other\n");
  print_money_line("clothes", other.clothes);
  print_money_line("communication", other.communication);
  print_money_line("study", other.study);
  print_money_line("entertainment", other.entertainment);
  print_money_line("travel", other.travel);
  print_money_line("gifts", other.gifts);
  print_money_line("small things", other.small_things);
  print_money_line("total other", total_other(other));
}

void print_bank(const Bank &bank) {
  printf("bank\n");
  print_money_line("account", bank.account);
  print_money_line("deposit", bank.deposit);
  print_money_line("mortgage", bank.mortgage);
  print_money_line("car loan", bank.car_loan);
  print_money_line("consumer loan", bank.consumer_loan);
  print_money_line("mortgage payment", bank.mortgage_payment);
  print_money_line("car loan payment", bank.car_loan_payment);
  print_money_line("consumer payment", bank.consumer_loan_payment);
  printf("mortgage rate: %.2f%%\n", bank.mortgage_rate);
  printf("car loan rate: %.2f%%\n", bank.car_loan_rate);
  printf("consumer loan rate: %.2f%%\n", bank.consumer_loan_rate);
}

void print_work(const Work &work) {
  printf("work\n");
  printf("taxi: %s\n", work.taxi ? "yes" : "no");
  print_money_line("salary", work.salary);
  print_money_line("taxi orders", work.taxi_orders);
  print_money_line("taxi expenses", work.taxi_expenses);
  print_money_line("bonus", work.bonus);
}

void print_main_info(const Person &person) {
  printf("\nmain info for %s\n", person.name);
  printf("id: %d\n", person.id);
  printf("age: %d\n", person.age);
  print_money_line("assets", total_assets(person));
  print_money_line("debt", total_debt(person));
  print_money_line("capital", capital(person));
  printf("score: %d\n", score(person));
}

void print_expenses_info(const Person &person) {
  RUB food = total_food(person.food);
  RUB utility = total_utility(person.utility);
  RUB home = total_home(person.home);
  RUB pet = total_pet(person.pet);
  RUB car = total_car(person.car);
  RUB family = total_family(person.family);
  RUB health = total_health(person.health);
  RUB other = total_other(person.other);
  RUB total = food + utility + home + pet + car + family + health + other;
  printf("expenses info for %s\n", person.name);
  print_money_line("food", food);
  print_money_line("utility", utility);
  print_money_line("home", home);
  print_money_line("pet", pet);
  print_money_line("car", car);
  print_money_line("family", family);
  print_money_line("health", health);
  print_money_line("other", other);
  print_money_line("total", total);
}

void print_history_line(const MonthSnapshot &snapshot) {
  printf("%02d.%04d account=%lld deposit=%lld debt=%lld capital=%lld "
         "income=%lld expenses=%lld credit=%lld unexpected=%lld\n",
         snapshot.month, snapshot.year, snapshot.account, snapshot.deposit,
         snapshot.debt, snapshot.capital, snapshot.income, snapshot.expenses,
         snapshot.credit_payment, snapshot.unexpected);
}

void print_first_months(const Person &person) {
  printf("first months for %s\n", person.name);
  int count = 0;
  while (count < 6 && count < person.history_count) {
    print_history_line(person.history[count]);
    count++;
  }
}

void print_last_months(const Person &person) {
  printf("last months for %s\n", person.name);
  int start = person.history_count - 6;
  if (start < 0) {
    start = 0;
  }
  int index = start;
  while (index < person.history_count) {
    print_history_line(person.history[index]);
    index++;
  }
}

void print_history_info(const Person &person) {
  printf("history info for %s\n", person.name);
  printf("history months: %d\n", person.history_count);
  print_first_months(person);
  print_last_months(person);
}

void print_year_info(const Person &person, YearNumber year) {
  printf(
      "year %d for %s: income=%lld expenses=%lld credit=%lld unexpected=%lld\n",
      year, person.name, history_income_for_year(person, year),
      history_expenses_for_year(person, year),
      history_credit_for_year(person, year),
      history_unexpected_for_year(person, year));
}

void print_selected_years(const Person &person) {
  print_year_info(person, 2026);
  print_year_info(person, 2027);
  print_year_info(person, 2028);
  print_year_info(person, 2030);
  print_year_info(person, 2032);
  print_year_info(person, 2034);
  print_year_info(person, 2036);
}

void print_credit_status(const Person &person) {
  printf("credit status for %s\n", person.name);
  print_money_line("mortgage left", person.bank.mortgage);
  print_money_line("car loan left", person.bank.car_loan);
  print_money_line("consumer loan left", person.bank.consumer_loan);
  print_money_line("total debt left", total_debt(person));
  if (total_debt(person) == 0) {
    printf("credit result: all credits are closed\n");
  } else {
    printf("credit result: there is still debt\n");
  }
}

void print_reserve_status(const Person &person) {
  RUB monthly = total_basic_expenses(person);
  RUB reserve = person.bank.account + person.bank.deposit;
  printf("reserve status for %s\n", person.name);
  print_money_line("monthly expenses", monthly);
  print_money_line("reserve", reserve);
  if (reserve >= monthly * 6) {
    printf("reserve result: strong reserve\n");
  } else if (reserve >= monthly * 3) {
    printf("reserve result: normal reserve\n");
  } else {
    printf("reserve result: weak reserve\n");
  }
}

void print_income_status(const Person &person) {
  RUB income = income_for_month(person, 12, end_year);
  RUB expenses = total_basic_expenses(person);
  printf("income status for %s\n", person.name);
  print_money_line("current income", income);
  print_money_line("current expenses", expenses);
  print_money_line("free money before credits", income - expenses);
}

void print_life_status(const Person &person) {
  printf("life status for %s\n", person.name);
  printf("age: %d\n", person.age);
  printf("health hp: %d\n", person.health.hp);
  printf("home: %s\n", person.home.own ? "own" : "rent");
  printf("car: %s\n", person.car.have ? "yes" : "no");
  printf("pet alive: %s\n", person.pet.alive ? "yes" : "no");
}

void print_expense_share_line(const char *title, RUB value, RUB total) {
  Percent share = 0.0;
  if (total > 0) {
    share = (double)value * 100.0 / (double)total;
  }
  printf("%-16s %lld RUB, %.2f%%\n", title, value, share);
}

void print_expense_shares(const Person &person) {
  RUB food = total_food(person.food);
  RUB utility = total_utility(person.utility);
  RUB home = total_home(person.home);
  RUB pet = total_pet(person.pet);
  RUB car = total_car(person.car);
  RUB family = total_family(person.family);
  RUB health = total_health(person.health);
  RUB other = total_other(person.other);
  RUB total = total_basic_expenses(person);
  printf("expense shares for %s\n", person.name);
  print_expense_share_line("food", food, total);
  print_expense_share_line("utility", utility, total);
  print_expense_share_line("home", home, total);
  print_expense_share_line("pet", pet, total);
  print_expense_share_line("car", car, total);
  print_expense_share_line("family", family, total);
  print_expense_share_line("health", health, total);
  print_expense_share_line("other", other, total);
}

void print_more_person_status(const Person &person) {
  printf("more status for %s\n", person.name);
  if (score(person) >= 80) {
    printf("model result: good financial model\n");
  } else if (score(person) >= 55) {
    printf("model result: average financial model\n");
  } else {
    printf("model result: risky financial model\n");
  }
  if (person.home.own) {
    printf("housing result: own home gives asset growth\n");
  } else {
    printf("housing result: rent gives flexibility but no home asset\n");
  }
}

void print_short_result(const Person &person) {
  printf("\nshort result for %s\n", person.name);
  printf("capital=%lld\n", capital(person));
  printf("debt=%lld\n", total_debt(person));
  printf("deposit=%lld\n", person.bank.deposit);
  printf("score=%d\n", score(person));
  printf("history months=%d\n", person.history_count);
}

void print_person(const Person &person) {
  print_main_info(person);
  print_food(person.food);
  print_utility(person.utility);
  print_home(person.home);
  print_pet(person.pet);
  print_car(person.car);
  print_family(person.family);
  print_health(person.health);
  print_other(person.other);
  print_bank(person.bank);
  print_work(person.work);
  print_expenses_info(person);
  print_history_info(person);
  print_selected_years(person);
  print_credit_status(person);
  print_reserve_status(person);
  print_income_status(person);
  print_life_status(person);
  print_expense_shares(person);
  print_more_person_status(person);
}

void print_comparison(const Person &dilshot_person,
                      const Person &analbek_person) {
  RUB dilshot_capital = capital(dilshot_person);
  RUB analbek_capital = capital(analbek_person);
  RUB dilshot_debt = total_debt(dilshot_person);
  RUB analbek_debt = total_debt(analbek_person);
  int dilshot_score = score(dilshot_person);
  int analbek_score = score(analbek_person);

  printf("\ncomparison\n");
  print_money_line("Dilshot capital", dilshot_capital);
  print_money_line("Analbek capital", analbek_capital);
  print_money_line("capital difference", dilshot_capital - analbek_capital);
  print_money_line("Dilshot debt", dilshot_debt);
  print_money_line("Analbek debt", analbek_debt);
  printf("Dilshot score: %d\n", dilshot_score);
  printf("Analbek score: %d\n", analbek_score);

  if (dilshot_capital > analbek_capital) {
    printf("financially stronger by capital: %s\n", dilshot_person.name);
  } else if (dilshot_capital < analbek_capital) {
    printf("financially stronger by capital: %s\n", analbek_person.name);
  } else {
    printf("capital is equal\n");
  }

  if (dilshot_score > analbek_score) {
    printf("financially stronger by score: %s\n", dilshot_person.name);
  } else if (dilshot_score < analbek_score) {
    printf("financially stronger by score: %s\n", analbek_person.name);
  } else {
    printf("score is equal\n");
  }
}

void print_settings() {
  printf("financial simulator settings\n");
  printf("period: %02d.%04d - %02d.%04d\n", start_month, start_year, end_month,
         end_year);
  printf("simulation step: month\n");
  printf("history capacity: %d\n", history_capacity);
  printf("deposit rate: %.2f%% per year\n", deposit_rate);
  printf("food inflation: %.2f%% per month\n", food_inflation);
  printf("utility inflation: %.2f%% per month\n", utility_inflation);
  printf("home inflation: %.2f%% per month\n", home_inflation);
  printf("pet inflation: %.2f%% per month\n", pet_inflation);
  printf("car inflation: %.2f%% per month\n", car_inflation);
  printf("family inflation: %.2f%% per month\n", family_inflation);
  printf("health inflation: %.2f%% per month\n", health_inflation);
  printf("other inflation: %.2f%% per month\n", other_inflation);
}

void print_year_report(const Person &person, YearNumber year) {
  RUB income = history_income_for_year(person, year);
  RUB expenses = history_expenses_for_year(person, year);
  RUB credit = history_credit_for_year(person, year);
  RUB unexpected = history_unexpected_for_year(person, year);
  RUB free_result = income - expenses - credit - unexpected;

  printf("%d report for %s\n", year, person.name);
  print_money_line("year income", income);
  print_money_line("year expenses", expenses);
  print_money_line("year credit", credit);
  print_money_line("year unexpected", unexpected);
  print_money_line("year free result", free_result);
}

RUB income_for_month_number(const Person &person, MonthNumber month_number) {
  RUB total = 0;

  for (int index = 0; index < person.history_count; index++) {
    if (person.history[index].month == month_number) {
      total += person.history[index].income;
    }
  }

  return total;
}

RUB expenses_for_month_number(const Person &person, MonthNumber month_number) {
  RUB total = 0;

  for (int index = 0; index < person.history_count; index++) {
    if (person.history[index].month == month_number) {
      total += person.history[index].expenses;
    }
  }

  return total;
}

void print_month_number_report(const Person &person, MonthNumber month_number) {
  printf("month %02d report for %s: income=%lld expenses=%lld\n", month_number,
         person.name, income_for_month_number(person, month_number),
         expenses_for_month_number(person, month_number));
}

void print_all_year_reports(const Person &person) {
  for (YearNumber year = start_year; year <= end_year; year++) {
    print_year_report(person, year);
  }
}

void print_all_month_number_reports(const Person &person) {
  for (MonthNumber month_number = 1; month_number <= 12; month_number++) {
    print_month_number_report(person, month_number);
  }
}

RUB month_free_result(const MonthSnapshot &snapshot) {
  RUB result = snapshot.income;
  result -= snapshot.expenses;
  result -= snapshot.credit_payment;
  result -= snapshot.unexpected;
  return result;
}

int first_month_with_positive_capital(const Person &person) {
  for (int index = 0; index < person.history_count; index++) {
    if (person.history[index].capital > 0) {
      return index;
    }
  }

  return -1;
}

int first_month_without_debt(const Person &person) {
  for (int index = 0; index < person.history_count; index++) {
    if (person.history[index].debt == 0) {
      return index;
    }
  }

  return -1;
}

int best_capital_month_index(const Person &person) {
  if (person.history_count == 0) {
    return -1;
  }

  int best_index = 0;

  for (int index = 1; index < person.history_count; index++) {
    if (person.history[index].capital > person.history[best_index].capital) {
      best_index = index;
    }
  }

  return best_index;
}

int worst_capital_month_index(const Person &person) {
  if (person.history_count == 0) {
    return -1;
  }

  int worst_index = 0;

  for (int index = 1; index < person.history_count; index++) {
    if (person.history[index].capital < person.history[worst_index].capital) {
      worst_index = index;
    }
  }

  return worst_index;
}

int best_free_result_month_index(const Person &person) {
  if (person.history_count == 0) {
    return -1;
  }

  int best_index = 0;

  for (int index = 1; index < person.history_count; index++) {
    if (month_free_result(person.history[index]) >
        month_free_result(person.history[best_index])) {
      best_index = index;
    }
  }

  return best_index;
}

int worst_free_result_month_index(const Person &person) {
  if (person.history_count == 0) {
    return -1;
  }

  int worst_index = 0;

  for (int index = 1; index < person.history_count; index++) {
    if (month_free_result(person.history[index]) <
        month_free_result(person.history[worst_index])) {
      worst_index = index;
    }
  }

  return worst_index;
}

RUB total_history_income(const Person &person) {
  RUB total = 0;

  for (int index = 0; index < person.history_count; index++) {
    total += person.history[index].income;
  }

  return total;
}

RUB total_history_expenses(const Person &person) {
  RUB total = 0;

  for (int index = 0; index < person.history_count; index++) {
    total += person.history[index].expenses;
  }

  return total;
}

RUB total_history_credit_payment(const Person &person) {
  RUB total = 0;

  for (int index = 0; index < person.history_count; index++) {
    total += person.history[index].credit_payment;
  }

  return total;
}

RUB total_history_unexpected(const Person &person) {
  RUB total = 0;

  for (int index = 0; index < person.history_count; index++) {
    total += person.history[index].unexpected;
  }

  return total;
}

RUB first_history_capital(const Person &person) {
  if (person.history_count == 0) {
    return 0;
  }

  return person.history[0].capital;
}

RUB last_history_capital(const Person &person) {
  if (person.history_count == 0) {
    return 0;
  }

  return person.history[person.history_count - 1].capital;
}

RUB average_history_income(const Person &person) {
  if (person.history_count == 0) {
    return 0;
  }

  return total_history_income(person) / person.history_count;
}

RUB average_history_expenses(const Person &person) {
  if (person.history_count == 0) {
    return 0;
  }

  return total_history_expenses(person) / person.history_count;
}

RUB average_history_credit_payment(const Person &person) {
  if (person.history_count == 0) {
    return 0;
  }

  return total_history_credit_payment(person) / person.history_count;
}

RUB average_history_unexpected(const Person &person) {
  if (person.history_count == 0) {
    return 0;
  }

  return total_history_unexpected(person) / person.history_count;
}

RUB average_history_free_result(const Person &person) {
  if (person.history_count == 0) {
    return 0;
  }

  RUB total = 0;

  for (int index = 0; index < person.history_count; index++) {
    total += month_free_result(person.history[index]);
  }

  return total / person.history_count;
}

int months_with_negative_free_result(const Person &person) {
  int count = 0;

  for (int index = 0; index < person.history_count; index++) {
    if (month_free_result(person.history[index]) < 0) {
      count++;
    }
  }

  return count;
}

int months_with_positive_free_result(const Person &person) {
  int count = 0;

  for (int index = 0; index < person.history_count; index++) {
    if (month_free_result(person.history[index]) >= 0) {
      count++;
    }
  }

  return count;
}

RUB biggest_debt_drop(const Person &person) {
  if (person.history_count < 2) {
    return 0;
  }

  RUB best_drop = 0;

  for (int index = 1; index < person.history_count; index++) {
    RUB previous_debt = person.history[index - 1].debt;
    RUB current_debt = person.history[index].debt;
    RUB drop = previous_debt - current_debt;

    if (drop > best_drop) {
      best_drop = drop;
    }
  }

  return best_drop;
}

RUB biggest_capital_growth(const Person &person) {
  if (person.history_count < 2) {
    return 0;
  }

  RUB best_growth = 0;

  for (int index = 1; index < person.history_count; index++) {
    RUB previous_capital = person.history[index - 1].capital;
    RUB current_capital = person.history[index].capital;
    RUB growth = current_capital - previous_capital;

    if (growth > best_growth) {
      best_growth = growth;
    }
  }

  return best_growth;
}

RUB biggest_capital_fall(const Person &person) {
  if (person.history_count < 2) {
    return 0;
  }

  RUB worst_fall = 0;

  for (int index = 1; index < person.history_count; index++) {
    RUB previous_capital = person.history[index - 1].capital;
    RUB current_capital = person.history[index].capital;
    RUB fall = previous_capital - current_capital;

    if (fall > worst_fall) {
      worst_fall = fall;
    }
  }

  return worst_fall;
}

void print_snapshot_line(const MonthSnapshot &snapshot) {
  printf("%02d.%04d account=%lld deposit=%lld debt=%lld capital=%lld "
         "income=%lld expenses=%lld credit=%lld unexpected=%lld free=%lld\n",
         snapshot.month, snapshot.year, snapshot.account, snapshot.deposit,
         snapshot.debt, snapshot.capital, snapshot.income, snapshot.expenses,
         snapshot.credit_payment, snapshot.unexpected,
         month_free_result(snapshot));
}

void print_snapshot_by_index(const Person &person, int index,
                             const char *title) {
  if (index < 0) {
    printf("%s for %s: no data\n", title, person.name);
    return;
  }

  printf("%s for %s\n", title, person.name);
  print_snapshot_line(person.history[index]);
}

void print_capital_extremes(const Person &person) {
  int best_index = best_capital_month_index(person);
  int worst_index = worst_capital_month_index(person);

  print_snapshot_by_index(person, best_index, "best capital month");
  print_snapshot_by_index(person, worst_index, "worst capital month");
}

void print_cash_flow_extremes(const Person &person) {
  int best_index = best_free_result_month_index(person);
  int worst_index = worst_free_result_month_index(person);

  print_snapshot_by_index(person, best_index, "best free money month");
  print_snapshot_by_index(person, worst_index, "worst free money month");
}

void print_average_history_values(const Person &person) {
  printf("average history values for %s\n", person.name);
  print_money_line("average income", average_history_income(person));
  print_money_line("average expenses", average_history_expenses(person));
  print_money_line("average credit payment",
                   average_history_credit_payment(person));
  print_money_line("average unexpected", average_history_unexpected(person));
  print_money_line("average free result", average_history_free_result(person));
}

void print_month_quality_counts(const Person &person) {
  printf("month quality counts for %s\n", person.name);
  printf("positive free result months: %d\n",
         months_with_positive_free_result(person));
  printf("negative free result months: %d\n",
         months_with_negative_free_result(person));
  printf("bad months by score logic: %d\n",
         months_with_negative_free_result(person));
}

void print_credit_progress_details(const Person &person) {
  printf("credit progress details for %s\n", person.name);
  print_money_line("biggest debt drop", biggest_debt_drop(person));
  print_money_line("current mortgage", person.bank.mortgage);
  print_money_line("current car loan", person.bank.car_loan);
  print_money_line("current consumer loan", person.bank.consumer_loan);
  print_money_line("current total debt", total_debt(person));

  int no_debt_index = first_month_without_debt(person);

  if (no_debt_index >= 0) {
    printf("first no debt month: %02d.%04d\n",
           person.history[no_debt_index].month,
           person.history[no_debt_index].year);
  } else {
    printf("first no debt month: not reached\n");
  }
}

void print_capital_progress_details(const Person &person) {
  printf("capital progress details for %s\n", person.name);
  print_money_line("first capital", first_history_capital(person));
  print_money_line("last capital", last_history_capital(person));
  print_money_line("capital growth", last_history_capital(person) -
                                         first_history_capital(person));
  print_money_line("biggest monthly capital growth",
                   biggest_capital_growth(person));
  print_money_line("biggest monthly capital fall",
                   biggest_capital_fall(person));

  int positive_index = first_month_with_positive_capital(person);

  if (positive_index >= 0) {
    printf("first positive capital month: %02d.%04d\n",
           person.history[positive_index].month,
           person.history[positive_index].year);
  } else {
    printf("first positive capital month: not reached\n");
  }
}

void print_score_details(const Person &person) {
  RUB monthly_expenses = total_basic_expenses(person);
  RUB three_month_reserve = monthly_expenses * 3;

  printf("score details for %s\n", person.name);
  printf("score: %d\n", score(person));
  printf("debt penalty active: %d\n", total_debt(person) > 0);
  printf("reserve penalty active: %d\n",
         person.bank.deposit < three_month_reserve);
  printf("health penalty active: %d\n", person.health.hp < 60);
  printf("bad months penalty active: %d\n",
         months_with_negative_free_result(person) > 12);
  printf("negative capital penalty active: %d\n", capital(person) < 0);
  print_money_line("monthly expenses", monthly_expenses);
  print_money_line("three month reserve target", three_month_reserve);
  print_money_line("current deposit", person.bank.deposit);
}

void print_compact_history_table(const Person &person) {
  printf("compact history table for %s\n", person.name);

  for (int index = 0; index < person.history_count; index += 12) {
    print_snapshot_line(person.history[index]);
  }

  if (person.history_count > 0) {
    int last_index = person.history_count - 1;

    if (last_index % 12 != 0) {
      print_snapshot_line(person.history[last_index]);
    }
  }
}

void print_clean_extra_analysis(const Person &person) {
  print_average_history_values(person);
  print_month_quality_counts(person);
  print_capital_extremes(person);
  print_cash_flow_extremes(person);
  print_credit_progress_details(person);
  print_capital_progress_details(person);
  print_score_details(person);
  print_compact_history_table(person);
}

void print_month_order_check() {
  printf("\nmonth order check\n");
  printf("1 pet life update\n");
  printf("2 deposit interest\n");
  printf("3 main income\n");
  printf("4 regular expenses with inflation\n");
  printf("5 unexpected expenses\n");
  printf("6 credit payments\n");
  printf("7 negative account cover\n");
  printf("8 free money to deposit\n");
  printf("9 health and age update\n");
  printf("10 month snapshot\n");
}

void print_editing_guide() {
  printf("\nediting guide\n");
  printf("new expense category needs struct fields\n");
  printf("new expense category needs init for Dilshot\n");
  printf("new expense category needs init for Analbek\n");
  printf("new expense category needs total function\n");
  printf("new expense category needs pay with inflation function\n");
  printf("new expense category needs print function\n");
  printf("new expense category needs one call in simulate_month\n");
}

void print_simulation_level_check() {
  printf("\nsimulation level check\n");
  printf("simulate controls whole period\n");
  printf("simulate_year_for_people controls months inside one year\n");
  printf("simulate_month controls all money actions inside one month\n");
}

void print_model_boundaries() {
  printf("\nmodel boundaries\n");
  printf("included income: salary, taxi, bonus, income growth, deposit "
         "interest\n");
  printf("included expenses: food, utility, home, pet, car, family, health, "
         "other\n");
  printf("included inflation: food, utility, home, pet, car, family, health, "
         "other\n");
  printf("included credits: mortgage, car loan, consumer loan\n");
  printf("included money: account, deposit, assets, debt, capital\n");
  printf("included life: pet life, health, age\n");
  printf("included history: monthly snapshots\n");
  printf("not included: taxes, currency exchange, stocks, job loss, "
         "refinancing, new property purchase\n");
}

void print_task_check(const Person &dilshot_person,
                      const Person &analbek_person) {
  printf("\ntask check\n");
  printf("simulation step: month\n");
  printf("period: 02.2026 - 03.2036\n");
  printf("detailed topic: several credits\n");
  printf("income: salary and deposit interest\n");
  printf("expenses: food, utility, home, pet, car, family, health, other\n");
  printf("credit model: mortgage, car loan, consumer loan\n");
  printf("output: final capital, debt, score and comparison\n");
  printf("%s history months: %d\n", dilshot_person.name,
         dilshot_person.history_count);
  printf("%s history months: %d\n", analbek_person.name,
         analbek_person.history_count);
  printf("%s mortgage left: %lld\n", dilshot_person.name,
         dilshot_person.bank.mortgage);
  printf("%s mortgage left: %lld\n", analbek_person.name,
         analbek_person.bank.mortgage);
}

int main() {
  init_people();
  simulate(dilshot, analbek);
  print_settings();
  print_short_result(dilshot);
  print_short_result(analbek);
  print_person(dilshot);
  print_all_year_reports(dilshot);
  print_all_month_number_reports(dilshot);
  print_clean_extra_analysis(dilshot);
  print_person(analbek);
  print_all_year_reports(analbek);
  print_all_month_number_reports(analbek);
  print_clean_extra_analysis(analbek);
  print_comparison(dilshot, analbek);
  print_month_order_check();
  print_editing_guide();
  print_simulation_level_check();
  print_model_boundaries();
  print_task_check(dilshot, analbek);
  return 0;
}
