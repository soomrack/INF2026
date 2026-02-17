#include <stdio.h>

using RUB = long long int;

struct Cat {
    RUB value;
    RUB food;
};

struct Car {
    RUB value; 
	RUB gas;   
};

struct Bank {
	RUB salary;
	RUB card; 
	RUB deposit;  
	double deposit_apr; 
};


struct Person { 
    RUB food;   
	Car car;    
	Cat cat;    
	Bank Tbank;  
};

Person Alice;

const RUB emergency_fund = 250'000; // Сумма, которую Алиса считает достаточной для покрытия непредвиденных расходов

double inflation_month = (10 / 100.0 / 12.0); // Месячная инфляция
double deposit_month = (14.5 / 100.0 / 12.0); // Месячные проценты по вкладу

void alice_init() { // Инициализация данных Алисы
	Alice.Tbank.salary = 100'000; 

	Alice.food = 20'000; 

	Alice.car.value = 2'400'000; 
	Alice.car.gas = 15'000; 

	Alice.cat.value = 25'000; 
	Alice.cat.food = 5'000; 

	Alice.Tbank.card = 0;
	Alice.Tbank.deposit = 0;
}

void alice_inflation_tick() { // Инфляция повышает цены на все товары и услуги
	Alice.food *= (1.0 + inflation_month); 
	Alice.car.gas *= (1.0 + inflation_month); 
	Alice.car.value *= (1.0 + inflation_month); 

	Alice.cat.food *= (1.0 + inflation_month); 
	Alice.cat.value *= (1.0 + inflation_month); 
}

void alice_deposit_interest() { // Алиса получает проценты по вкладу
	Alice.Tbank.deposit += Alice.Tbank.deposit * deposit_month;
}

void alice_salary(const int month, const int year) { // Алиса получает зарплату
	if ((month == 8) && (year == 2026)) 
	{
		Alice.Tbank.salary *= 1.5;
	}

	Alice.Tbank.card += Alice.Tbank.salary;
}

void alice_pay_food() { // Алиса платит за еду
	if (Alice.Tbank.card >= Alice.food) {
		Alice.Tbank.card -= Alice.food;
	}

	else {
		printf("Alice cannot pay for food! Card balance: %lld, Food cost: %lld\n", Alice.Tbank.card, Alice.food);
	}
}

void alice_pay_gas() { // Алиса платит за бензин
	if (Alice.Tbank.card >= Alice.car.gas) {
		Alice.Tbank.card -= Alice.car.gas;
	}

	else {
		printf("Alice cannot pay for gas! Card balance: %lld, Gas cost: %lld\n", Alice.Tbank.card, Alice.car.gas);
	}
}

void alice_pay_cat_food() { // Алиса платит за еду для кота
	if (Alice.Tbank.card >= Alice.cat.food) {
		Alice.Tbank.card -= Alice.cat.food;
	}

	else {
		printf("Alice cannot pay for cat food! Card balance: %lld, Cat food cost: %lld\n", Alice.Tbank.card, Alice.cat.food);
	}
}

void alice_move_money_to_deposit() { // Алиса переводит деньги с карты на вклад, если на карте больше, чем emergency_fund
	if (Alice.Tbank.card > emergency_fund) {
		RUB amount = Alice.Tbank.card;
		Alice.Tbank.card -= amount;
		Alice.Tbank.deposit += amount;
	}	
}

void print_results() { // Вывод результатов после моделирования

	printf("Salary = %lld\n", Alice.Tbank.salary);
	printf("Deposit = %lld\n", Alice.Tbank.deposit);
	printf("Card = %lld\n", Alice.Tbank.card);
	printf("Total = %lld\n", Alice.Tbank.deposit + Alice.Tbank.card + Alice.car.value + Alice.cat.value);

	printf("Food = %lld\n", Alice.food); 
	printf("Gas = %lld\n", Alice.car.gas); 
	printf("Cat food = %lld\n", Alice.cat.food); 

	printf("Car value = %lld\n", Alice.car.value); 
	printf("Cat value = %lld\n", Alice.cat.value); 
}

void simulation() { // Моделирование финансовой жизни Алисы с февраля 2026 по март 2027
	int month = 2;
	int year = 2026;

	while (!((month == 3) && (year == 2027))) {
		alice_inflation_tick();
		alice_deposit_interest();
		alice_salary(month, year);
		alice_pay_food();
		alice_pay_gas();
		alice_pay_cat_food();
		alice_move_money_to_deposit();

		++month;
		if (month == 13) {
			month = 1;
			++year;
		}
	}
}

int main() {
	alice_init(); // Инициализация данных Алисы
	simulation(); // Моделирование финансовой жизни Алисы
	print_results(); // Вывод результатов после моделирования
}