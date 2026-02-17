#include <stdio.h>
#include <stdlib.h>

using RUB = long long int;
using USD = long long int;


struct Car {
	RUB value;
	RUB gas;
};


struct Bank {
	RUB account_rub;
	USD account_usd;
	float rate_usd_rub;
};


struct Person {
	RUB lottery;
	Bank vtb;
	RUB food;
	RUB salary;
	Car car;
};


struct Person alice;


void alice_init()
{
	alice.vtb.rate_usd_rub = 78.76;

	alice.vtb.account_rub = 0;
	alice.vtb.account_usd = 1'000;

	alice.food = 3'000;
	alice.salary = 180'000;

	alice.car.value = 2'400'000;
	alice.car.gas = 15'000;

	alice.lottery = 20'000;
}


void alice_lottery()
{
	int prizes[25] = {500'000, 100'000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // prizes list

	int prize_num = rand() % 25;
	
	int lottery_results = prizes[prize_num];

	alice.vtb.account_rub -= alice.lottery;
	alice.vtb.account_rub += lottery_results;
	//printf("Lottery = %lld\n", lottery_results); Проверял как работает rand
	//printf("Num = %lld\n", prize_num);
}


void alice_salary(const int month, const int year)
{
	if (month == 2 && year == 2026) {
		alice.vtb.account_rub += 5000; // bonus
	}

	if (month == 3) {
		alice.salary *= 1.5; // promotion
	}
	alice.vtb.account_rub += alice.salary;
}


void alice_food(const int month,const int year)
{
	if (month == 12) alice.vtb.account_rub -= 2000; // christmas party

	float inflation = 0.12;
	switch (year) {
	case 2026: inflation = 0.125; break;
	case 2027: inflation = 0.14; break;
	case 2028: inflation = 0.13; break;
	case 2029: inflation = 0.115; break;
	}
	alice.food += alice.food * (inflation / 12);

	alice.vtb.account_rub -= alice.food;
}


void alice_car()
{
	alice.vtb.account_rub -= alice.car.gas;
}


void simulation()
{
	int year = 2026;
	int month = 2;

	while (!(year == 2027 && month == 2)) {
		alice_salary(month, year);
		alice_car();
		alice_food(month, year);
		alice_lottery();

		++month;
		if (month == 13) {
			++year;
			month = 1;
		}
	}
}


void print_results()
{
	printf("Salary = %lld\n", alice.salary);

	RUB capital = 0;
	capital += alice.car.value;
	capital += alice.vtb.account_rub;
	capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
	printf("Capital = %lld", capital);
}


int main()
{
	alice_init();
	simulation();
	print_results();
}
