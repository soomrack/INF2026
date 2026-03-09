#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using RUB = long long int; // Используют в С++, можно из одного места поменять типы данных многих переменных

struct Car {
	RUB value;
	RUB gas;
	RUB maintenance;
};

struct Animal {
	RUB food;
	RUB vet;
};

struct Bank {
	RUB deposit;
	RUB account;
	float pp;
	float month_inf;
};

struct Investments {
	RUB stocks;           // Акции
	RUB bonds;            // Облигации
	RUB liquid_funds;     // Фонды ликвидности
};

struct Health {
	int age;
	RUB dentist;
	RUB med_chest; // Витамины, средства гигиены, лекарства от головной боли и так далее
	RUB desiase;
	RUB insuarance;
	RUB med_examination;
};

struct Flat {
	RUB renting;
	RUB appliance;
};

struct Regular {
	RUB food;
	RUB cloth;
	RUB gifts;
};

struct Person { // создали свой тип данных
	RUB salary;
	Car car;
	Animal animal;
	RUB travel;
	Flat flat;
	Health health;
	Bank bank;
	Regular payments;
	Investments invest;
};

struct Person Alice; // создали переменную типа данных Person

int month = 2;
int year = 2026;

void passing_of_time() { // функция для того, чтобы время менялось глобально во всей симуляции
	++month;
	if (month == 13) {
		month = 1;
		++year;
	}
}

void alice_car() {
	Alice.car.maintenance *= Alice.bank.month_inf;
	Alice.car.gas *= Alice.bank.month_inf;
	Alice.bank.account -= Alice.car.gas;
	if ((month == 4) || (month == 10)) { // Смена зимней и летней резины
		Alice.bank.account -= Alice.car.maintenance;
	}
}

void alice_turtle(){
	Alice.animal.vet *= Alice.bank.month_inf;
	Alice.animal.food *= Alice.bank.month_inf;
	Alice.bank.account -= Alice.animal.food;
	if (month % 6 == 0) {
		Alice.bank.account -= Alice.animal.vet;
	}
}

void alice_travel() {
	Alice.travel *= Alice.bank.month_inf;
	if (month == 8) {
		if (Alice.bank.deposit >= Alice.travel) {
			Alice.bank.deposit -= Alice.travel;
		}
	}
}

void alice_salary() {
	if ((month == 8) && ((year % 5) == 0)) { // Повышение зарплаты каждые 5 лет
		Alice.salary *= 1.3;
	}
	Alice.bank.account += Alice.salary;
}

void alice_regular_payments() {
	Alice.payments.food *= Alice.bank.month_inf;
	Alice.payments.cloth *= Alice.bank.month_inf;
	Alice.payments.gifts *= Alice.bank.month_inf;
	Alice.bank.account -= Alice.payments.food;
	Alice.bank.account -= Alice.payments.cloth;
	Alice.bank.account -= Alice.payments.gifts;
}

void alice_healt() {
	if (month == 2) {
		Alice.health.age += 1;
	}
	if (month == 9) {
		Alice.bank.account -= Alice.health.dentist;
	}
	if (month == 1) {
		Alice.bank.account -= Alice.health.insuarance;
	}
	Alice.bank.account -= Alice.health.med_chest;
	float age_factor = Alice.health.age / 25.0;
	Alice.bank.account -= (Alice.health.desiase * age_factor);
}

void alise_accommodation() { 
	Alice.flat.renting *= Alice.bank.month_inf;
	Alice.flat.appliance *= Alice.bank.month_inf;
	Alice.bank.account -= Alice.flat.renting;
	if (month == 4) {
		Alice.bank.deposit -= Alice.flat.appliance;
	}
}

void alice_bank_interest() {
	Alice.bank.deposit += Alice.bank.account;
	Alice.bank.account = 0;
	Alice.bank.deposit += Alice.bank.deposit * (Alice.bank.pp / 12.0 / 100.0); // Проценты по вкладу
}

void alice_monthly_invest() {
	RUB to_invest = Alice.salary * 0.1;

	if (Alice.bank.account > to_invest + 20000) {
		Alice.bank.account -= to_invest;

		Alice.invest.stocks += static_cast<RUB>(to_invest * 0.40);
		Alice.invest.bonds += static_cast<RUB>(to_invest * 0.35);
		Alice.invest.liquid_funds += static_cast<RUB>(to_invest * 0.25);
	}
}

void alice_investment_income() {
	float stock_market = 0.96 + (rand() % 9) / 100.0; 
	Alice.invest.stocks = static_cast<RUB>(Alice.invest.stocks * stock_market);

	Alice.invest.bonds = static_cast<RUB>(Alice.invest.bonds * 1.005); 

	Alice.invest.liquid_funds = static_cast<RUB>(Alice.invest.liquid_funds * 1.003); 
}


void print_status() {
	RUB total_invest = Alice.invest.stocks + Alice.invest.bonds + Alice.invest.liquid_funds;
	RUB total_capital = Alice.bank.account + Alice.bank.deposit + total_invest;

	printf("year %d:\n", year);
	printf("  age: %d\n", Alice.health.age);
	printf("  salary: %lld\n", Alice.salary);
	printf("  deposit: %lld\n", Alice.bank.deposit);
	printf("  investments: S=%lld B=%lld L=%lld Total=%lld\n",
		Alice.invest.stocks, Alice.invest.bonds, Alice.invest.liquid_funds, total_invest);
	printf("  TOTAL CAPITAL: %lld\n", total_capital);
}

void print_results() {
	printf("\nSalary = %lld\n", Alice.salary);
	printf("Deposit = %lld\n", Alice.bank.deposit);
	printf("Investments = %lld\n",
		Alice.invest.stocks + Alice.invest.bonds + Alice.invest.liquid_funds);
	printf("TOTAL CAPITAL = %lld\n",
		Alice.bank.deposit + Alice.bank.account +
		Alice.invest.stocks + Alice.invest.bonds + Alice.invest.liquid_funds);
}

void simulation() {
	while (!(year == 2057 && month == 3)) {

		alice_salary();
		alice_turtle();
		alice_travel();
		alice_healt();
		alice_regular_payments(); // еда, одежда, подарки
		alice_car();
		alise_accommodation();

		alice_monthly_invest();   
		alice_investment_income(); 

		alice_bank_interest();

		if (month == 1) {
			print_status();
		}

		passing_of_time();
	}	
}

void alice_init() // Присвоили значения характеристик, описывающих переменную данного типа
{
	Alice.bank.deposit = 0;
	Alice.bank.account = 0;
	Alice.bank.pp = 9.8;
	Alice.bank.month_inf = 1.0062;

	Alice.salary = 155000;

	Alice.payments.food = 20000;
	Alice.payments.cloth = 7000;
	Alice.payments.gifts = 2000;

	Alice.car.value = 2400000;
	Alice.car.gas = 15000;
	Alice.car.maintenance = 8000;

	Alice.animal.food = 1500;
	Alice.animal.vet = 3000;

	Alice.travel = 50000;

	Alice.flat.renting = 40000;
	Alice.flat.appliance = 10000;

	Alice.health.dentist = 4000;
	Alice.health.med_chest = 1500;
	Alice.health.desiase = 2000;
	Alice.health.insuarance = 15000;
	Alice.health.age = 25;

	Alice.invest.stocks = 0;
	Alice.invest.bonds = 0;
	Alice.invest.liquid_funds = 0;
}

int main() { 

	srand(time(NULL));
	alice_init();
	simulation();
	print_results();
}
