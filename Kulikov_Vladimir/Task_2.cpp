#include <stdio.h>

using RUB = long long;

struct Car {
	RUB value;
	RUB gas;
};

struct Bank {
	RUB account;
	RUB deposit;
};

struct Dog {
	RUB cost;  
};

struct Person {
	RUB salary;
	RUB food;
	Car car;
	Dog dog;
	Bank bank;
};

void person_init(Person& p) {
	p.salary = 100000;
	p.food = 30000;

	p.car.value = 0;
	p.car.gas = 3000;

	p.dog.cost = 5000;

	p.bank.account = 0;
	p.bank.deposit = 0;
}

void receive_salary(Person& p, int month, int year) {
	if (month == 12 && year == 2026) {
		p.salary = p.salary * 3 / 2;
	}
	p.bank.account += p.salary;
}

void pay_food(Person& p) {
	p.bank.account -= p.food;
}

void pay_gas(Person& p) {
	p.bank.account -= p.car.gas;
}

void pay_dog(Person& p) {
	p.bank.account -= p.dog.cost;
}

void transfer_to_deposit(Person& p, RUB amount) {
	p.bank.account -= amount;
	p.bank.deposit += amount;
}

void deposit_interest(Person& p, double pp) {
	p.bank.deposit += (RUB)(p.bank.deposit * (pp / 12.0 / 100.0));
}

void apply_inflation(Person& p, double inflation_pp) {
	double k = 1.0 + inflation_pp / 12.0 / 100.0;

	p.food = (RUB)(p.food * k);
	p.car.gas = (RUB)(p.car.gas * k);
	p.car.value = (RUB)(p.car.value * k);
	p.dog.cost = (RUB)(p.dog.cost * k);

}

void print_results(const Person& p) {
	printf("salary=%lld\n", p.salary);
	printf("account=%lld\n", p.bank.account);
	printf("deposit=%lld\n", p.bank.deposit);
	printf("food=%lld, gas=%lld, dog=%lld\n", p.food, p.car.gas, p.dog.cost);
	printf("car value=%lld\n", p.car.value);
}


void simulation(Person& p) {
	int month = 10;
	int year = 2026;

	while (!(month == 11 && year == 2027)) {
		apply_inflation(p, 2.0);
		deposit_interest(p, 14.5);
		pay_food(p);
		pay_gas(p);
		pay_dog(p);
		transfer_to_deposit(p, 50000);
		receive_salary(p, month, year);

		++month;
		if (month ==13) {
			month = 1;
			++year;
		}
	}
}

int main() {
	Person Epstein;
	person_init(Epstein);
	simulation(Epstein);
	print_results(Epstein);
	
}