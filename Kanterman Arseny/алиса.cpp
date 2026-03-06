#include <stdio.h>
#include <stdlib.h>  
#include <time.h>   

int year = 2026;
int month = 2;

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
	RUB partial_payment;
};

struct Person { 
	Bank vtb;
	RUB salary;
	RUB food;
	Car car;
	Credit credit;
};

struct Person alice;
struct Person john;

void alice_init() {
	alice.vtb.rate_usd_rub = 78.76;
	alice.vtb.account_rub = 0;
	alice.vtb.account_usd = 1000;
	alice.salary = 180000;
	alice.food = 3000;
	alice.car.value = 24000;
	alice.car.gas = 15000;
	alice.credit.debt = 3000000;
	alice.credit.payment = 40000;
	alice.credit.month = (alice.credit.debt / alice.credit.payment);
}

void john_init() {
	john.vtb.rate_usd_rub = 78.76;
	john.vtb.account_rub = 150000;  
	john.vtb.account_usd = 2000;     
	john.salary = 350000;            
	john.food = 4000;
	john.car.value = 45000;           
	john.car.gas = 20000;
	john.credit.debt = 1000000;       
	john.credit.payment = 35000;
	john.credit.month = (john.credit.debt / john.credit.payment);
}

void alice_total_money() { 
	RUB total_rub = alice.vtb.account_rub;
	RUB dollars_in_rub = (RUB)(alice.vtb.account_usd * alice.vtb.rate_usd_rub);
	RUB total = total_rub + dollars_in_rub;
	
	printf("Alice's total money: %lld RUB\n", total);
	printf("  Rubles: %lld RUB\n", alice.vtb.account_rub);
	printf("  And dollars: %lld USD = %lld RUB\n", alice.vtb.account_usd, dollars_in_rub);
}

void john_total_money() { 
	RUB total_rub = john.vtb.account_rub;
	RUB dollars_in_rub = (RUB)(john.vtb.account_usd * john.vtb.rate_usd_rub);
	RUB total = total_rub + dollars_in_rub;
	
	printf("John's total money: %lld RUB\n", total);
	printf("  Rubles: %lld RUB\n", john.vtb.account_rub);
	printf("  And dollars: %lld USD = %lld RUB\n", john.vtb.account_usd, dollars_in_rub);
}

void alice_food(const int month, const int year) {
	if (month == 12) alice.vtb.account_rub -= 2000;
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
	}
	alice.food += alice.food * (inflation / 100 / 12);
	alice.vtb.account_rub -= alice.food;
}

void john_food(const int month, const int year) {
	if (month == 12) john.vtb.account_rub -= 3000;
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
	}
	john.food += john.food * (inflation / 100 / 12);
	john.vtb.account_rub -= john.food;
}

void alice_salary(const int month, const int year) {
	if (month == 3) {
		alice.salary *= 1.5;
	}
	if (month == 2 && year == 2026) {
		alice.vtb.account_rub += 5000;
	}
	alice.vtb.account_rub += alice.salary;
}

void john_salary(const int month, const int year) {
	if (month == 3) {
		john.salary *= 1.5;
	}
	if (month == 2 && year == 2026) {
		john.vtb.account_rub += 15000;
	}
	if (month == 12) {
		john.vtb.account_rub += 30000;
		printf("  John: New Year bonus +30000 RUB\n");
	}
	if (month == 6) {
		john.vtb.account_rub += 20000;
		printf("  John: Summer bonus +20000 RUB\n");
	}
	john.vtb.account_rub += john.salary;
}

void alice_car() {
	if (alice.car.value > 0) {
		alice.vtb.account_rub -= alice.car.gas;
	}
}

void john_car() {
	if (john.car.value > 0) {
		john.vtb.account_rub -= john.car.gas;
		if (month >= 6 && month <= 8) {
			john.vtb.account_rub -= 3000; 
			printf("  John: summer road trip extra +3000 RUB for gas\n");
		}
	}
}

void alice_credit(const int year, const int month) {
	if (alice.credit.debt > 0) {
		if (alice.vtb.account_rub >= alice.credit.payment) {
			alice.vtb.account_rub -= alice.credit.payment;
			alice.credit.debt -= alice.credit.payment;
			printf("  Alice's credit: payment %lld RUB, remaining debt: %lld RUB\n", alice.credit.payment, alice.credit.debt);
		} else {
			RUB partial = alice.vtb.account_rub;
			alice.credit.debt -= partial;
			alice.vtb.account_rub = 0;
			printf("  Alice's credit: partial payment %lld RUB, remaining debt: %lld RUB\n", partial, alice.credit.debt);
		}
	}
}

void john_credit(const int year, const int month) {
	if (john.credit.debt > 0) {
		if (john.vtb.account_rub >= john.credit.payment) {
			john.vtb.account_rub -= john.credit.payment;
			john.credit.debt -= john.credit.payment;
			printf("  John's credit: payment %lld RUB, remaining debt: %lld RUB\n", john.credit.payment, john.credit.debt);
		} else {
			RUB partial = john.vtb.account_rub;
			john.credit.debt -= partial;
			john.vtb.account_rub = 0;
			printf("  John's credit: partial payment %lld RUB, remaining debt: %lld RUB\n", partial, john.credit.debt);
		}
	}
}

void alice_early_credit_payment() {
	RUB threshold = 500000;
	
	if (alice.vtb.account_rub > threshold && alice.credit.debt > 0) {
		RUB extra_payment = alice.vtb.account_rub - threshold;
		if (extra_payment > alice.credit.debt) {
			extra_payment = alice.credit.debt;
		}
		
		if (extra_payment > 0) {
			alice.vtb.account_rub -= extra_payment;
			alice.credit.debt -= extra_payment;
			printf("  Alice's EARLY PAYMENT: %lld RUB (remaining in account: %lld RUB)\n", 
				   extra_payment, alice.vtb.account_rub);
		}
	}
}

void john_early_credit_payment() {
	RUB threshold = 400000;
	
	if (john.vtb.account_rub > threshold && john.credit.debt > 0) {
		RUB extra_payment = john.vtb.account_rub - threshold;
		if (extra_payment > john.credit.debt) {
			extra_payment = john.credit.debt;
		}
		
		if (extra_payment > 0) {
			john.vtb.account_rub -= extra_payment;
			john.credit.debt -= extra_payment;
			printf("  John's EARLY PAYMENT: %lld RUB (remaining in account: %lld RUB)\n", 
				   extra_payment, john.vtb.account_rub);
		}
	}
}

void alice_invest() {
	RUB invest_threshold = 300000;
	RUB min_invest = 100000;
	
	if (alice.vtb.account_rub > invest_threshold) {
		RUB extra = alice.vtb.account_rub - invest_threshold;
		RUB invest_amount = extra * 0.3;
		invest_amount = (invest_amount / 1000) * 1000;
		
		if (invest_amount >= min_invest) {
			printf("  Alice's INVESTMENTS: investing %lld RUB\n", invest_amount);
			alice.vtb.account_rub -= invest_amount;
			
			int invest_type = rand() % 2;
			
			if (invest_type == 0) {
				RUB profit = invest_amount * 0.05;
				alice.vtb.account_rub += invest_amount + profit;
				printf("    Alice's Deposit: +%lld RUB profit\n", profit);
			} else {
				int risk = rand() % 100;
				if (risk < 70) {
					RUB profit = invest_amount * 0.20;
					alice.vtb.account_rub += invest_amount + profit;
					printf("    Alice's Stocks: SUCCESS! +%lld RUB profit\n", profit);
				} else if (risk < 90) {
					RUB loss = invest_amount * 0.10;
					alice.vtb.account_rub += invest_amount - loss;
					printf("    Alice's Stocks: small losses -%lld RUB\n", loss);
				} else {
					RUB loss = invest_amount * 0.30;
					alice.vtb.account_rub += invest_amount - loss;
					printf("    Alice's Stocks: losses -%lld RUB\n", loss);
				}
			}
		}
	}
}

void john_invest() {
	RUB invest_threshold = 400000;
	RUB min_invest = 150000;
	
	if (john.vtb.account_rub > invest_threshold) {
		RUB extra = john.vtb.account_rub - invest_threshold;
		RUB invest_amount = extra * 0.4;
		invest_amount = (invest_amount / 1000) * 1000;
		
		if (invest_amount >= min_invest) {
			printf("  John's INVESTMENTS: investing %lld RUB\n", invest_amount);
			john.vtb.account_rub -= invest_amount;
			
			int invest_type = rand() % 2;
			
			if (invest_type == 0) {
				RUB profit = invest_amount * 0.06;
				john.vtb.account_rub += invest_amount + profit;
				printf("    John's Deposit: +%lld RUB profit\n", profit);
			} else {
				int risk = rand() % 100;
				if (risk < 60) {
					RUB profit = invest_amount * 0.25;
					john.vtb.account_rub += invest_amount + profit;
					printf("    John's Stocks: SUCCESS! +%lld RUB profit\n", profit);
				} else if (risk < 80) {
					RUB loss = invest_amount * 0.10;
					john.vtb.account_rub += invest_amount - loss;
					printf("    John's Stocks: small losses -%lld RUB\n", loss);
				} else {
					RUB loss = invest_amount * 0.30;
					john.vtb.account_rub += invest_amount - loss;
					printf("    John's Stocks: losses -%lld RUB\n", loss);
				}
			}
		}
	}
}

void alice_car_transaction(int current_month, int current_year) {
	static int alice_car_purchase_month = 2;
	static int alice_car_purchase_year = 2026;
	
	int car_age_months = (current_year - alice_car_purchase_year) * 12 + (current_month - alice_car_purchase_month);
	
	if (car_age_months >= 24 && alice.car.value > 0) {
		printf("  Alice's CAR: selling old car for %lld RUB\n", alice.car.value);
		alice.vtb.account_rub += alice.car.value;
		
		RUB new_car_price = alice.car.value * 1.2;
		
		if (alice.vtb.account_rub >= new_car_price + alice.car.gas) {
			alice.vtb.account_rub -= (new_car_price + alice.car.gas);
			alice.car.value = new_car_price;
			alice_car_purchase_month = current_month;
			alice_car_purchase_year = current_year;
			printf("    Alice buying new car for %lld RUB\n", new_car_price);
		} else {
			printf("    Alice not enough money, looking for options...\n");
			
			RUB budget_car = alice.car.value * 0.8;
			if (alice.vtb.account_rub >= budget_car + alice.car.gas) {
				alice.vtb.account_rub -= (budget_car + alice.car.gas);
				alice.car.value = budget_car;
				alice_car_purchase_month = current_month;
				alice_car_purchase_year = current_year;
				printf("    Alice buying budget car for %lld RUB\n", budget_car);
			} else {
				printf("    Alice staying without car :(\n");
				alice.car.value = 0;
				alice.car.gas = 0;
			}
		}
	}
}

void john_car_transaction(int current_month, int current_year) {
	static int john_car_purchase_month = 2;
	static int john_car_purchase_year = 2026;
	
	int car_age_months = (current_year - john_car_purchase_year) * 12 + (current_month - john_car_purchase_month);
	
	if (car_age_months >= 30 && john.car.value > 0) {
		printf("  John's CAR: selling old car for %lld RUB\n", john.car.value);
		john.vtb.account_rub += john.car.value;
		
		RUB new_car_price = john.car.value * 1.25;
		
		if (john.vtb.account_rub >= new_car_price + john.car.gas) {
			john.vtb.account_rub -= (new_car_price + john.car.gas);
			john.car.value = new_car_price;
			john_car_purchase_month = current_month;
			john_car_purchase_year = current_year;
			printf("    John buying new car for %lld RUB\n", new_car_price);
		} else {
			printf("    John saving more for a better car...\n");
		}
	}
}

void family_utilities(const int month, const int year) {
	printf("\n>>> FAMILY UTILITIES (John pays) <<<\n");
	
	RUB rent = 45000;  
	RUB electricity = 3500; 
	RUB water = 2000;  
	RUB gas = 1200;  
	RUB internet_tv = 1500;  
	RUB mobile_family = 2500;  
	RUB cleaning = 2000;  
	
	switch (month) {
	case 12:
	case 1:
	case 2:
		rent += 3000;  
		electricity += 800;  
		printf("  Winter months: heating +3000 RUB\n");
		break;
		
	case 3:
	case 4:
		electricity += 2000;  
		printf("  Summer months: air conditioning +2000 RUB\n");
		break;
		
	case 5:
		cleaning += 1000;  
		printf("  Spring cleaning: +1000 RUB\n");
		break;
		
	case 6:
		printf("  Preparing for winter\n");
		rent += 1000;  
		break;
	}
	
	int unexpected = rand() % 100;
	if (unexpected < 10) {  
		RUB unexpected_cost = 0;
		const char* reason = "";
		
		switch (rand() % 4) {  
		case 0:
			unexpected_cost = 3000;  
			reason = "small repair";
			break;
		case 1:
			unexpected_cost = 2000;  
			reason = "plumber";
			break;
		case 2:
			unexpected_cost = 1000;  
			reason = "light bulbs";
			break;
		case 3:
			unexpected_cost = 1500;  
			reason = "kitchen supplies";
			break;
		}
		
		rent += unexpected_cost;
		printf("  Unexpected: %s - %lld RUB\n", reason, unexpected_cost);
	}
	
	float utilities_inflation = 1.0;
	switch (year) {
		case 2027: utilities_inflation = 1.05; break;  
		case 2028: utilities_inflation = 1.07; break;  
		case 2029: utilities_inflation = 1.04; break; 
		default: utilities_inflation = 1.0;
	}
	
	if (year > 2026) {
		rent *= utilities_inflation;
		electricity *= utilities_inflation;
		water *= utilities_inflation;
		printf("  Utilities inflation: +%.0f%%\n", (utilities_inflation - 1) * 100);
	}
	
	RUB total_utilities = rent + electricity + water + gas + internet_tv + mobile_family + cleaning;
	
	printf("\n  Total utilities: %lld RUB\n", total_utilities);
	printf("  Paid by: JOHN\n");
	
	float percent_of_salary = (float)total_utilities / john.salary * 100;
	printf("  This is %.1f%% of John's monthly salary (%lld RUB)\n", 
		   percent_of_salary, john.salary);
	
	if (total_utilities <= john.salary * 0.4) {
		john.vtb.account_rub -= total_utilities;
		printf(" John paid: %lld RUB (remaining: %lld RUB)\n", 
			   total_utilities, john.vtb.account_rub);
	} else {
		printf("  Utilities are high this month\n");
		if (john.vtb.account_rub >= total_utilities) {
			john.vtb.account_rub -= total_utilities;
			printf("  John paid: %lld RUB\n", total_utilities);
		} else {
			RUB from_usd = john.vtb.account_usd * john.vtb.rate_usd_rub;
			john.vtb.account_rub += from_usd;
			john.vtb.account_usd = 0;
			john.vtb.account_rub -= total_utilities;
			printf("  John used USD to pay: %lld RUB\n", total_utilities);
		}
	}
	
	static RUB yearly_utilities[4] = {0, 0, 0, 0};
	int year_index = year - 2026;
	if (year_index >= 0 && year_index < 4) {
		yearly_utilities[year_index] += total_utilities;
	}
	
	if (month == 12 && year_index >= 0 && year_index < 4) {
		printf("\n  === YEAR %d UTILITIES ===\n", year);
		printf("  Total: %lld RUB\n", yearly_utilities[year_index]);
		printf("  Monthly avg: %lld RUB\n", yearly_utilities[year_index] / 12);
		
		RUB john_yearly = john.salary * 12;
		float yearly_percent = (float)yearly_utilities[year_index] / john_yearly * 100;
		printf("  %.1f%% of John's annual salary\n", yearly_percent);
	}
}

//Подарки на праздники
void holiday_gifts(const int month, const int year) {
	printf("\n>>> HOLIDAY GIFTS <<<\n");
	
	// Новый год
	if (month == 12) {
		printf("  NEW YEAR GIFTS:\n");
		
		// Покупают подарки друг другу
		if (john.vtb.account_rub >= 5000) {
			john.vtb.account_rub -= 5000;
			printf("  John bought gift for Alice: 5000 RUB\n");
		} else {
			printf("  John can't afford gift for Alice :(\n");
		}
		
		if (alice.vtb.account_rub >= 5000) {
			alice.vtb.account_rub -= 5000;
			printf("  Alice bought gift for John: 5000 RUB\n");
		} else {
			printf("  Alice can't afford gift for John :(\n");
		}
		
		// Общие подарки родственникам
		RUB family_gifts = 5000;
		RUB alice_part = family_gifts / 2;
		RUB john_part = family_gifts / 2;
		
		if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
			alice.vtb.account_rub -= alice_part;
			john.vtb.account_rub -= john_part;
			printf("  Gifts for family: %lld RUB (%lld each)\n", family_gifts, alice_part);
		} else {
			printf("  Not enough money for family gifts\n");
		}
	}
	
	// 8 марта
	if (month == 3) {
		printf("  MARCH 8:\n");
		if (john.vtb.account_rub >= 3000) {
			john.vtb.account_rub -= 3000;
			printf("  John gave Alice flowers and chocolates: 3000 RUB\n");
		} else {
			printf("  John forgot about March 8 :(\n");
		}
	}
	
	// 23 февраля
	if (month == 2) {
		printf("  FEBRUARY 23:\n");
		if (alice.vtb.account_rub >= 3000) {
			alice.vtb.account_rub -= 3000;
			printf("  Alice gave John a gift: 3000 RUB\n");
		} else {
			printf("  Alice forgot about February 23 :(\n");
		}
	}
	
	// День Святого Валентина
	if (month == 2 && year > 2026) {
		printf("  VALENTINE'S DAY:\n");
		if (john.vtb.account_rub >= 2000 && alice.vtb.account_rub >= 2000) {
			john.vtb.account_rub -= 2000;
			alice.vtb.account_rub -= 2000;
			printf("  Romantic dinner: 4000 RUB (2000 each)\n");
		}
	}
}

// Благотворительность
void charity(const int month, const int year) {
	printf("\n>>> CHARITY <<<\n");
	
	// Алиса жертвует на благотворительность в декабре
	if (month == 12 && alice.vtb.account_rub > 10000) {
		RUB donation = 3000;
		alice.vtb.account_rub -= donation;
		printf("  Alice: charity donation 3000 RUB\n");
		printf("  Alice helps animal shelter\n");
	} else if (month == 12) {
		printf("  Alice wants to donate but doesn't have enough money\n");
	}
	
	// Джон помогает родителям (раз в полгода)
	if ((month == 5 || month == 11) && john.vtb.account_rub > 20000) {
		RUB help_parents = 10000;
		john.vtb.account_rub -= help_parents;
		printf("  John: helping parents %lld RUB\n", help_parents);
		printf("  Parents were very happy!\n");
	} else if ((month == 5 || month == 11)) {
		printf("  John wants to help parents but doesn't have enough money\n");
	}
	
	// Совместная благотворительность на Новый год
	if (month == 12 && year % 2 == 0) {  // каждый четный год
		RUB joint_charity = 5000;
		RUB alice_part = joint_charity / 2;
		RUB john_part = joint_charity / 2;
		
		if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
			alice.vtb.account_rub -= alice_part;
			john.vtb.account_rub -= john_part;
			printf("  Family donation to children's hospital: %lld RUB\n", joint_charity);
		}
	}
	
	// Волонтерство 
	if (month == 4) {
		printf("  Alice volunteered at local library this month\n");
	}
	if (month == 9) {
		printf("  John helped clean up the park\n");
	}
}

void show_monthly_stats(int m, int y) {
	printf("\n========== %d/%d ==========\n", m, y);
	
	printf("\n--- ALICE ---\n");
	printf("Account: %lld RUB, %lld USD\n", alice.vtb.account_rub, alice.vtb.account_usd);
	printf("Debt: %lld RUB\n", alice.credit.debt);
	printf("Car: %lld RUB\n", alice.car.value);
	printf("Food budget: %lld RUB\n", alice.food);
	
	printf("\n--- JOHN (salary: %lld RUB) ---\n", john.salary);
	printf("Account: %lld RUB, %lld USD\n", john.vtb.account_rub, john.vtb.account_usd);
	printf("Debt: %lld RUB\n", john.credit.debt);
	printf("Car: %lld RUB\n", john.car.value);
	printf("Food budget: %lld RUB\n", john.food);
	
	RUB family_total = alice.vtb.account_rub + john.vtb.account_rub + 
	(RUB)((alice.vtb.account_usd + john.vtb.account_usd) * alice.vtb.rate_usd_rub);
	printf("\nFAMILY TOTAL MONEY: %lld RUB\n", family_total);
}

void print_results() {
	printf("\n=== FINAL RESULTS ===\n");
	
	printf("\n--- ALICE ---\n");
	RUB alice_capital = alice.vtb.account_rub + 
	(RUB)(alice.vtb.account_usd * alice.vtb.rate_usd_rub) + 
	alice.car.value;
	printf("Total capital: %lld RUB\n", alice_capital);
	alice_total_money();
	printf("Credit debt: %lld RUB\n", alice.credit.debt);
	
	printf("\n--- JOHN ---\n");
	RUB john_capital = john.vtb.account_rub + 
	(RUB)(john.vtb.account_usd * john.vtb.rate_usd_rub) + 
	john.car.value;
	printf("Total capital: %lld RUB\n", john_capital);
	john_total_money();
	printf("Credit debt: %lld RUB\n", john.credit.debt);
	
	printf("\n=== FAMILY SUMMARY ===\n");
	printf("COMBINED CAPITAL: %lld RUB\n", alice_capital + john_capital);
	printf("Combined credit debt: %lld RUB\n", alice.credit.debt + john.credit.debt);
	
	if (alice_capital > john_capital) {
		printf("\n ALICE has more capital!\n");
	} else {
		printf("\n JOHN has more capital!\n");
	}
}

void simulation() {
	year = 2026;
	month = 2;
	
	printf("\n=== INITIAL DATA ===\n");
	printf("\n--- ALICE ---\n");
	printf("Annual salary: %lld RUB\n", alice.salary * 12);
	printf("Initial account: %lld RUB, %lld USD\n", alice.vtb.account_rub, alice.vtb.account_usd);
	printf("Initial debt: %lld RUB\n", alice.credit.debt);
	
	printf("\n--- JOHN (breadwinner) ---\n");
	printf("Annual salary: %lld RUB\n", john.salary * 12);
	printf("Monthly salary: %lld RUB\n", john.salary);
	printf("Initial account: %lld RUB, %lld USD\n", john.vtb.account_rub, john.vtb.account_usd);
	printf("Initial debt: %lld RUB\n", john.credit.debt);
	
	printf("\n=== STARTING SIMULATION ===\n");
	show_monthly_stats(month, year);
	
	int months_passed = 0;
	
	while (!(year == 2029 && month == 2)) {
		printf("\n========== PROCESSING MONTH %d/%d ==========\n", month, year);
		
		family_utilities(month, year);
		
		holiday_gifts(month, year);
		charity(month, year);
		
		printf("\n>>> ALICE'S OPERATIONS <<<\n");
		alice_credit(year, month);
		alice_salary(month, year);
		alice_car();
		alice_food(month, year);
		alice_early_credit_payment();
		alice_invest();
		alice_car_transaction(month, year);
		
		printf("\n>>> JOHN'S OPERATIONS <<<\n");
		john_credit(year, month);
		john_salary(month, year);
		john_car();
		john_food(month, year);
		john_early_credit_payment();
		john_invest();
		john_car_transaction(month, year);
		
		show_monthly_stats(month, year);
		
		++month;
		if (month == 13) {
			++year;
			month = 1;
		}
		months_passed++;
	}
	
	printf("\n=== SIMULATION COMPLETE ===\n");
	printf("Months passed: %d\n", months_passed);
	printf("End date: %d/%d\n", month, year);
	print_results();
}

int main() {
	alice_init();
	john_init();
	srand(time(NULL));
	
	printf("=== FAMILY FINANCIAL SIMULATOR ===\n");
	printf("Alice and John - John pays all utilities\n\n");
	
	simulation();
	
	return 0;
}
