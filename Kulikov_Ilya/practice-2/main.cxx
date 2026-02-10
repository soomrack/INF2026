#include <stdio.h>

unsigned int months_passed = 0;

using Rubles = double;
using Percent = double;

Rubles goods_price = 750;
Rubles monthly_expenses_delta = 0;
const double difficulty_coefficient = 1e-5;

struct BankRecord {
  Rubles account = 0;
  Rubles deposit = 0;
  Percent interest = 0;
};

BankRecord new_bank_record(Rubles account, Rubles deposit, Percent interest) {
  BankRecord ret;

  ret.account = account;
  ret.deposit = deposit;
  ret.interest = interest;

  return ret;
}

BankRecord update_deposit(BankRecord br) {
  if (months_passed % 12 != 0)
    return br;

  br.account += br.deposit * br.interest / 100.0;
  monthly_expenses_delta += br.account;

  return br;
}

BankRecord from_deposit_to_account(BankRecord br, Rubles amount) {
  if (amount < 0)
    return br;

  if (br.deposit > amount) {
    br.deposit -= amount;
    br.account += amount;
  } else {
    br.account += br.deposit;
    br.deposit = 0;
  }

  return br;
}

BankRecord from_account_to_deposit(BankRecord br, Rubles amount) {
  if (amount < 0)
    return br;

  if (br.account > amount) {
    br.account -= amount;
    br.deposit += amount;
  } else {
    br.deposit += br.account;
    br.account = 0;
  }

  return br;
}

struct Person {
  BankRecord record;
  Rubles salary = 0;
  unsigned int goods = 0;
  Percent tax_rate = 0;
};

Person new_person(BankRecord record, Rubles salary, Percent tax_rate) {
  Person ret;

  ret.record = record;
  ret.salary = salary;
  ret.tax_rate = tax_rate;

  return ret;
}

Person pay_salary(Person p) {
  p.record.account += p.salary;

  return p;
}

Rubles taxes_for_person(Person p) {
  return (p.record.account + p.record.deposit) * p.tax_rate / 100.0;
}

Person pay_taxes(Person p) {
  Rubles taxes = taxes_for_person(p);

  if (p.record.account > taxes) {
    p.record.account -= taxes;
    return p;
  }

  if (p.record.account + p.record.deposit > taxes) {
    Rubles delta = taxes - p.record.account;
    p.record.account = 0;
    p.record.deposit -= delta;
    return p;
  }

  p.record.account = 0;
  p.record.deposit = 0;
  return p;
}

Person buy_goods(Person p, unsigned int amount) {
  unsigned int possible_amount = (int)(p.record.account / goods_price);
  amount = (possible_amount < amount) ? possible_amount : amount;

  p.record.account -= amount * goods_price;
  p.goods += amount;

  monthly_expenses_delta -= amount * goods_price;

  return p;
}

void print_person_info(Person p) {
  puts("'s personal info:");
  printf("Account:    %.2f\n", p.record.account);
  printf("Deposit:    %.2f\n", p.record.deposit);
  printf("Interest:   %.2f%%\n", p.record.interest);
  printf("Salary:     %.2f\n", p.salary);
  printf("Goods:      %d\n", p.goods);
  printf("Tax rate:   %.2f%%\n", p.tax_rate);
  printf("Taxes:      %.2f\n", taxes_for_person(p));
}

Person Alice, Bob, Eve;

void next_month() {
  Alice = pay_salary(Alice);
  Alice.record = update_deposit(Alice.record);
  Alice = pay_taxes(Alice);
  printf("    Alice");
  print_person_info(Alice);

  Bob = pay_salary(Bob);
  Bob.record = update_deposit(Bob.record);
  Bob = pay_taxes(Bob);
  printf("    Bob");
  print_person_info(Bob);

  Eve = pay_salary(Eve);
  Eve.record = update_deposit(Eve.record);
  Eve = pay_taxes(Eve);
  printf("    Eve");
  print_person_info(Eve);

  goods_price += monthly_expenses_delta * difficulty_coefficient;

  printf("-----~----- Another month passed. "
         "Goods price: %.2f -----~-----\n",
         goods_price);
  monthly_expenses_delta = 0;
  months_passed++;
}

int main() {
  Alice = new_person(new_bank_record(2'000'000, 500'000, 2.75), 157'000, 14.6);
  Bob = new_person(new_bank_record(50'000, 5'000, 13.42), 2'910, 12);
  Eve = new_person(new_bank_record(0, 0, 0), 27'093, 17.21);
  next_month();

  Alice = buy_goods(Alice, 10);
  Bob = buy_goods(Bob, 7);
  next_month();

  next_month();

  Alice.record = from_deposit_to_account(Alice.record, 25'000);
  Bob.record = from_account_to_deposit(Bob.record, 1'000'000);
  Eve.record = from_account_to_deposit(Eve.record, 1'000'000);
  next_month();

  next_month();

  for (int i = 0; i < 12 * 6; i++) {
    Alice.record = from_deposit_to_account(Alice.record, 1'000);
    Bob.record = from_account_to_deposit(Bob.record, 1'000);
    Eve = buy_goods(Eve, 2);

    next_month();
  }

  return 0;
}
