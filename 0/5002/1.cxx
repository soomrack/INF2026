#include <stdio.h>
using Percent = float;
using RUB = long long int;
using USD = long long int;
using Time = int;

struct Car {
	RUB value;
	RUB gas;  
};


struct Bank {
	RUB account_rub;
	USD account_usd;
	float rate_usd_rub;
};
struct Credit {
	RUB debt;
	Time month;
	RUB payment;
	RUB remainder;
	Percent rate;

};

struct Person { // Зачем добовлять опять в struct ?
	Bank vtb;
	RUB salary;
	RUB food;
	Car car;
	Credit credit;
};

struct Person alice;

void alice_credit(const int month, const int year) {////
}

void alice_init() {
	alice.vtb.rate_usd_rub = 78, 76;
	alice.vtb.account_rub = 0;
	alice.vtb.account_usd = 1000;
	alice.salary = 180000;
	alice.food = 3000;
	alice.car.value = 24000;
	alice.car.gas = 15000;
	alice.credit.debt = 3'000'000;
	alice.credit.payment= 40'000;
	alice.credit.month = (alice.credit.debt/ alice.credit.payment);
}


void alice_food(const int month,const int year)
{
	if (month == 12) alice.vtb.account_rub -= 2000;  // christmas party
	Percent inflation = 12.0;
	switch (year) {
	case 2026:inflation = 12.5;break;
	case 2027:inflation = 14.0;break;
	case 2028:inflation = 13.0;break;
	case 2029:inflation = 11.5;break;
	}
	alice.food += alice.food * (inflation / 100 / 12);
	alice.vtb.account_rub -= alice.food;
}


void alice_salary(const int month, const int year) {
	if (month == 3) {
		alice.salary *= 1.5;
	}
		if (month == 2 && year == 2026) {
			alice.vtb.account_rub += 5000;  //bonus
		}
		alice.vtb.account_rub += alice.salary;
}


void print_results()
{
	printf("Salary = %lld\n", alice.salary);

	RUB capital = 0;
	capital += alice.vtb.account_rub;
	capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
	capital += alice.car.value;
	printf("Capital = %lld", capital);
}


void alice_car()  // const int month, const int year ?
{
	alice.vtb.account_rub -= alice.car.gas;
}
void simulation() {
	int year = 2026;
	int month = 2;
		while (!(year == 2029 && month == 2)) {
			alice_salary(month, year);
			alice_car();
			alice_food(month, year);
			++month;
			if (month == 13) {
				++year;
				month = 1;
			}

		}
}

int main() {
	alice_init();
	simulation();
	print_results();
}
