#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

using RUB = long long int;

struct Apartment {
	RUB value;
	RUB communal;
};

struct Clothes {
	RUB shoes;
	RUB socks;
	RUB pants;
	RUB sneakers;
	RUB jeans;
	RUB trousers;
	RUB tshirt;
	RUB dress;
	RUB brassiere;
	RUB hat;
	RUB swimsuit;
	RUB jacket;
	RUB caot;
	RUB bag;
};

struct Cat {
	RUB value;
	RUB food;
	RUB vetclinic;
	RUB ill;
};

struct TAX {
	double tax;
	RUB salaryyear;
	RUB sum;
};

struct Economictyges {
	float indexation;
	float inflation;
};

struct Bank {
	RUB depozit;
	float percent;
	RUB account;
};

struct Car {
	RUB value;
	RUB gas;
	RUB maintenance;
	RUB wintertires;
};

struct Money {
	RUB salary;
	double highprice;
};

struct Person {
	Cat cat;
	RUB capital;
	RUB food;
	Car car;
	Bank bank;
	Apartment apartment;
	RUB trip;
	TAX tax;
	Economictyges economic;
	Money money;
	RUB ill;
	Clothes clothes;
};

Person alice;

void alice_init() {
	alice.capital = 0;
	alice.bank.account = 0;
	alice.bank.depozit = 0;

	alice.money.salary = 130'000;
	alice.money.highprice = 0;

	alice.food = 32000;
	alice.ill = 1500;
	alice.trip = 300000;

	alice.apartment.value = 12'000'000;
	alice.apartment.communal = 18000;

	alice.car.value = 2'400'000;
	alice.car.gas = 12000;
	alice.car.maintenance = 6000;
	alice.car.wintertires = 10000;

	alice.cat.food = 6'000;
	alice.cat.value = 10000;
	alice.cat.ill = 25'000;
	alice.cat.vetclinic = 0;

	alice.economic.indexation = 10;
	alice.economic.inflation = 13;

	alice.tax.salaryyear = 0;
	alice.tax.sum = 0;
	alice.tax.tax = 0;

	alice.clothes.shoes = 7'000;
	alice.clothes.socks = 500;
	alice.clothes.pants = 4'000;
	alice.clothes.sneakers = 8'000;
	alice.clothes.jeans = 5'000;
	alice.clothes.trousers = 4500;
	alice.clothes.tshirt = 1'500;
	alice.clothes.dress = 6000;
	alice.clothes.brassiere = 2'000;
	alice.clothes.hat = 3'000;
	alice.clothes.swimsuit = 5'000;
	alice.clothes.jacket = 12'000;
	alice.clothes.caot = 10'000;
	alice.clothes.bag = 8'000;
}
double tax_rate(int year_income)
{
	if (alice.tax.salaryyear < 2400000)
	{
		return 13;
	}
	else if (alice.tax.salaryyear >= 2400000 and alice.tax.salaryyear < 5000000)
	{
		return 15;
	}
	else if (alice.tax.salaryyear >= 5000000 and alice.tax.salaryyear < 20000000)
	{
		return 18;
	}
	else if (alice.tax.salaryyear >= 20000000 and alice.tax.salaryyear < 50000000)
	{
		return 20;
	}
	else return 22;
}

void apply_inflation_to_clothes(const int month) {
	if (month == 1) {
		float inf = alice.economic.inflation / 100.0;
		alice.clothes.shoes += alice.clothes.shoes * inf;
		alice.clothes.socks += alice.clothes.socks * inf;
		alice.clothes.pants += alice.clothes.pants * inf;
		alice.clothes.sneakers += alice.clothes.sneakers * inf;
		alice.clothes.jeans += alice.clothes.jeans * inf;
		alice.clothes.trousers += alice.clothes.trousers * inf;
		alice.clothes.tshirt += alice.clothes.tshirt * inf;
		alice.clothes.dress += alice.clothes.dress * inf;
		alice.clothes.brassiere += alice.clothes.brassiere * inf;
		alice.clothes.hat += alice.clothes.hat * inf;
		alice.clothes.swimsuit += alice.clothes.swimsuit * inf;
		alice.clothes.jacket += alice.clothes.jacket * inf;
		alice.clothes.caot += alice.clothes.caot * inf;
		alice.clothes.bag += alice.clothes.bag * inf;
	}
}

void alice_clothes(const int month)
{
	static bool bought_winter_coat = false;
	static bool bought_winter_jacket = false;
	static bool bought_swimsuit = false;
	static bool bought_hat = false;

	if ((month == 9 || month == 10 || month == 11) && !bought_winter_coat)
	{
		if (rand() % 3 == 2) {
			alice.bank.account -= alice.clothes.caot;
			bought_winter_coat = true;
		}
	}

	if ((month == 12 || month == 1 || month == 2) && !bought_winter_jacket)
	{
		if (rand() % 3 == 2) {
			alice.bank.account -= alice.clothes.jacket;
		}
		alice.bank.account -= alice.clothes.shoes;
		bought_winter_jacket = true;
	}

	if ((month >= 5 && month <= 8) && !bought_swimsuit)
	{
		if (rand() % 3 == 2) {
			alice.bank.account -= alice.clothes.swimsuit;
			bought_swimsuit = true;
		}
	}
	if ((month >= 5 && month <= 8) && !bought_hat)
	{
		if (rand() % 3 == 1) {
			alice.bank.account -= alice.clothes.hat;
			bought_hat = true;
		}
	}
	if (rand() % 2 == 1)
	{
		alice.bank.account -= (alice.clothes.pants + alice.clothes.socks);
	}

	if (month == 3)
	{
		bought_winter_coat = false;
		bought_winter_jacket = false;
	}
	if (month == 8)
	{
		bought_swimsuit = false;
		bought_hat = false;
	}

	if (rand() % 100 < 5)
	{
		alice.bank.account -= alice.clothes.tshirt;
	}
	if (rand() % 100 < 3)
	{
		alice.bank.account -= alice.clothes.jeans;
	}
	if (rand() % 100 < 2)
	{
		alice.bank.account -= alice.clothes.bag;
	}
}

void alice_ill(const int month)
{
	short randomill = 1 + rand() % 80;
	short randomvalueill = 1 + rand() % 5;

	if (randomill <= 10)
	{
		alice.bank.account -= alice.ill * randomvalueill;
	}

	switch (month)
	{
	case 1:  alice.ill += alice.ill * alice.economic.inflation / 100; break;
	}

	if (randomill > 75)
	{
		alice.bank.depozit -= alice.ill * randomill;
		alice.tax.sum -= alice.ill * randomill * tax_rate(alice.tax.salaryyear);
		if (alice.tax.sum <= 0)
		{
			alice.tax.sum += alice.ill * randomill * tax_rate(alice.tax.salaryyear);
			alice.bank.depozit += alice.tax.sum;
			alice.tax.sum = 0;
		}
		else
		{
			alice.bank.depozit += alice.ill * randomill * tax_rate(alice.tax.salaryyear);
		}
	}
}

void alice_trip(const int month)
{
	if (alice.bank.depozit >= 500000 and month == 7) {
		short randomtrip = 1 + rand() % 50;
		short rm = 1 + rand() % 2;

		switch (rm)
		{
		case 1: alice.bank.depozit += alice.trip * randomtrip / 100; break;
		case 2: alice.bank.depozit -= alice.trip * randomtrip / 100; break;
		}

		alice.bank.depozit -= alice.trip;
	}
	if (month == 12) {
		alice.trip += alice.trip * alice.economic.inflation / 100;
	}

}

void alice_salaryyear(const int month)
{
	if (month == 1) alice.tax.salaryyear = 0;
	alice.tax.salaryyear += alice.money.salary;
}


void alice_capital()
{
	alice.capital = alice.car.value + alice.bank.depozit + alice.apartment.value;
}

void alice_depozit() {
	alice.bank.depozit += alice.bank.account;
	alice.bank.account = 0;
}

void alice_apartment(int month)
{
	if (month < 3 || month == 12)
	{
		alice.apartment.communal *= 1.5;
	}

	short randomcommunal = 1 + rand() % 5;
	short rc = 1 + rand() % 2;

	switch (rc)
	{
	case 1: alice.bank.account -= alice.apartment.communal * randomcommunal / 100; break;
	case 2: alice.bank.account += alice.apartment.communal * randomcommunal / 100; break;
	}

	alice.bank.account -= alice.apartment.communal;

	if (month == 1)
	{
		alice.apartment.communal += alice.apartment.communal * alice.economic.inflation / 100;
	}

	if (month < 3 || month == 12)
	{
		alice.apartment.communal /= 1.5;
	}
}

void alice_cat(const int month)
{
	if (month == 1)
	{
		alice.cat.food += alice.cat.food * alice.economic.inflation / 100;
	}

	alice.bank.account -= alice.cat.food;

	short randomcatill = 1 + rand() % 100;
	if (randomcatill < 10)
	{
		alice.cat.vetclinic = alice.cat.ill / randomcatill;
		alice.bank.account -= alice.cat.vetclinic;
	}
	switch (month) {
	case 1: alice.cat.ill += alice.cat.ill * alice.economic.inflation / 100; break;
	}

}

float depreciation()
{
	if (alice.car.value > 8000000)
	{
		return 2;
	}

	if (alice.car.value > 1000000 and alice.car.value < 8000000)
	{
		return 1;
	}
	if (alice.car.value < 1000000)
	{
		return 0.5;
	}
	return 0.2;

}

float sberbank_interest(RUB sum)
{

	if (sum > 10'000 and sum < 3'000'000) {
		return 11.5;
	}

	if (sum >= 3'000'000) {
		return 12.5;
	}

	return 0.1;
}

	void alice_salary(const int year, const int month)
	{
		srand(time(NULL));
		int random = 1 + rand() % 10;
		RUB gross = alice.money.salary;
		if (random == 5)
		{
			alice.money.highprice = alice.money.salary * 0.2;
			gross += alice.money.highprice;
			alice.tax.salaryyear += alice.money.highprice;
		}

		if (alice.bank.depozit >= 500000 and month == 7) {
			alice.bank.account -= alice.money.salary / 2;
		}
		if (month == 12)
		{
			alice.money.salary += alice.money.salary * alice.economic.indexation / 100;
		}
		if (month == 3 and year == 2026) {
			alice.money.salary *= 1.2;
		}

		alice.tax.salaryyear += gross;
		float tt = tax_rate(alice.tax.salaryyear);
		RUB tax = gross * tt / 100;
		alice.tax.sum += tax;
		RUB net = gross - tax;
		alice.bank.account += net;
}

void alice_food(int month)
{

	if (month < 3 || month == 12)
	{
		alice.food *= 1.1;
	}


	short randomfood = 1 + rand() % 15;
	short pm = 1 + rand() % 2;
	switch (pm)
	{
	case 1: alice.bank.account += alice.food * randomfood / 100; break;
	case 2:	alice.bank.account -= alice.food * randomfood / 100; break;
	}


	alice.bank.account -= alice.food;


	if (month < 3 || month == 12)
	{
		alice.food /= 1.1;

	}
	switch (month)
	{
	case 1: alice.food += alice.food * alice.economic.inflation / 100; break;
	}
}

void print_results()
{
	printf("Salary = %lld\n", alice.money.salary);
	printf("Capital = %lld\n", alice.capital);
	printf("Depozit = %lld\n", alice.bank.depozit);
	printf("CAR = %lld\n", alice.car.value);
}

void alice_car(const int month)

{
	if (month < 3 || month == 12)
	{
		alice.car.gas *= 1.5;
		alice.car.maintenance += alice.car.wintertires;
	}
	short randomgas = 1 + rand() % 15;
	short pm = 1 + rand() % 2;
	switch (pm)
	{
	case 1: alice.bank.account += alice.car.gas * randomgas / 100; break;
	case 2:	alice.bank.account -= alice.car.gas * randomgas / 100; break;
	}

	alice.bank.account -= alice.car.gas;
	alice.car.value -= alice.car.value * depreciation() / 100;
	alice.bank.account -= alice.car.maintenance;
	alice.car.gas += alice.car.gas * alice.economic.inflation / 12 / 100;

	switch (month)
	{
	case 1: alice.car.maintenance += alice.car.maintenance * alice.economic.inflation / 100; break;
	}


	if (month < 3 || month == 12)
	{
		alice.car.gas /= 1.5;
		alice.car.maintenance -= alice.car.wintertires;
	}
}
void alice_bank_interest()
{
	float pp;
	pp = sberbank_interest(alice.bank.depozit);
	alice.bank.depozit += alice.bank.depozit * (pp / 12.0 / 100.0);
}

void alice_simulation()
{
	int year = 2026;
	int month = 2;

	while (not (year == 2028 and month == 2)) {
		tax_rate(alice.tax.salaryyear);
		alice_salary(year, month);
		alice_trip(month);
		alice_food(month);
		alice_clothes(month);
		apply_inflation_to_clothes(month);
		alice_ill(month);
		alice_car(month);
		alice_apartment(month);
		alice_cat(month);
		alice_depozit();
		alice_bank_interest();
		alice_capital();
		alice_salaryyear(month);

		++month;
		if (month == 13) {
			++year;
			month = 1;
		}
	}
}


int main()
{
	srand(time(NULL));
	alice_init();
	alice_simulation();
	print_results();
}