#include <stdio.h>
#include <stdlib.h>  
#include <time.h>   


int year = 2026;
int month = 2;


using Percent = float;
using RUB = long long int;
using USD = long long int;
using MonthCount = int;  // Количество месяцев для кредита


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
	MonthCount month;  // Количество месяцев для погашения кредита
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



// Прототипы функций для вывода
void print_header(const char* title);
void print_subheader(const char* title);
void print_separator();
void print_amount(const char* description, RUB amount, const char* currency);
void print_person_stats(const char* name, RUB account_rub, USD account_usd, RUB debt, RUB car_value, RUB food);
void print_operation(const char* person, const char* operation, RUB amount, const char* details);
void print_credit_payment(const char* person, RUB payment, RUB remaining_debt);
void print_early_payment(const char* person, RUB extra_payment, RUB remaining_account);
void print_investment_result(const char* person, const char* type, RUB amount, const char* result);
void print_car_transaction(const char* person, RUB old_value, RUB new_value, const char* status);
void print_utilities(RUB total, float percent_of_salary, RUB salary);
void print_family_total(RUB total);


// Прототипы функций праздников
void new_year_gifts(const int month, const int year);
void march_8_gifts(const int month, const int year);
void february_23_gifts(const int month, const int year);
void valentines_day_gifts(const int month, const int year);
void birthday_alice(const int month, const int year);
void birthday_john(const int month, const int year);
void anniversary_wedding(const int month, const int year);
void victory_day(const int month, const int year);
void halloween(const int month, const int year);
void process_all_holidays(const int month, const int year);


// Прототипы функций благотворительности
void alice_charity_donation(const int month, const int year);
void john_parents_help(const int month, const int year);
void family_joint_charity(const int month, const int year);
void alice_volunteering(const int month, const int year);
void john_volunteering(const int month, const int year);
void process_all_charity(const int month, const int year);


// Прототип функции медицины
void family_health_and_medicine(const int month, const int year);


// Прототип функции накоплений
void family_savings_goals(const int month, const int year);


// Прототип функции спорта
void family_sports(const int month, const int year);


// Функции для вывода
void print_header(const char* title) {
	printf("\n=== %s ===\n", title);
}


void print_subheader(const char* title) {
	printf("\n>>> %s <<<\n", title);
}


void print_separator() {
	printf("\n========== %d/%d ==========\n", month, year);
}


void print_amount(const char* description, RUB amount, const char* currency) {
	printf("  %s: %lld %s\n", description, amount, currency);
}


void print_person_stats(const char* name, RUB account_rub, USD account_usd, RUB debt, RUB car_value, RUB food) {
	printf("\n--- %s ---\n", name);
	printf("Account: %lld RUB, %lld USD\n", account_rub, account_usd);
	printf("Debt: %lld RUB\n", debt);
	printf("Car: %lld RUB\n", car_value);
	printf("Food budget: %lld RUB\n", food);
}


void print_operation(const char* person, const char* operation, RUB amount, const char* details) {
	printf("  %s: %s %lld RUB", person, operation, amount);
	if (details[0] != '\0') {
		printf(" %s", details);
	}
	printf("\n");
}


void print_credit_payment(const char* person, RUB payment, RUB remaining_debt) {
	printf("  %s's credit: payment %lld RUB, remaining debt: %lld RUB\n", person, payment, remaining_debt);
}


void print_early_payment(const char* person, RUB extra_payment, RUB remaining_account) {
	printf("  %s's EARLY PAYMENT: %lld RUB (remaining in account: %lld RUB)\n", 
		   person, extra_payment, remaining_account);
}


void print_investment_result(const char* person, const char* type, RUB amount, const char* result) {
	printf("    %s's %s: %s %lld RUB\n", person, type, result, amount);
}


void print_car_transaction(const char* person, RUB old_value, RUB new_value, const char* status) {
	printf("  %s's CAR: selling old car for %lld RUB\n", person, old_value);
	printf("    %s %s for %lld RUB\n", person, status, new_value);
}


void print_utilities(RUB total, float percent_of_salary, RUB salary) {
	printf("\n  Total utilities: %lld RUB\n", total);
	printf("  Paid by: JOHN\n");
	printf("  This is %.1f%% of John's monthly salary (%lld RUB)\n", percent_of_salary, salary);
}


void print_family_total(RUB total) {
	printf("\nFAMILY TOTAL MONEY: %lld RUB\n", total);
}


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
	
	print_amount("Alice's total money", total, "RUB");
	print_amount("  Rubles", alice.vtb.account_rub, "RUB");
	printf("  And dollars: %lld USD = %lld RUB\n", alice.vtb.account_usd, dollars_in_rub);
}


void john_total_money() { 
	RUB total_rub = john.vtb.account_rub;
	RUB dollars_in_rub = (RUB)(john.vtb.account_usd * john.vtb.rate_usd_rub);
	RUB total = total_rub + dollars_in_rub;
	
	print_amount("John's total money", total, "RUB");
	print_amount("  Rubles", john.vtb.account_rub, "RUB");
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
		print_operation("John", "New Year bonus", 30000, "");
	}
	if (month == 6) {
		john.vtb.account_rub += 20000;
		print_operation("John", "Summer bonus", 20000, "");
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
			print_operation("John", "summer road trip extra", 3000, "for gas");
		}
	}
}


void alice_credit(const int year, const int month) {
	if (alice.credit.debt > 0) {
		if (alice.vtb.account_rub >= alice.credit.payment) {
			alice.vtb.account_rub -= alice.credit.payment;
			alice.credit.debt -= alice.credit.payment;
			print_credit_payment("Alice", alice.credit.payment, alice.credit.debt);
		} else {
			RUB partial = alice.vtb.account_rub;
			alice.credit.debt -= partial;
			alice.vtb.account_rub = 0;
			print_credit_payment("Alice", partial, alice.credit.debt);
		}
	}
}


void john_credit(const int year, const int month) {
	if (john.credit.debt > 0) {
		if (john.vtb.account_rub >= john.credit.payment) {
			john.vtb.account_rub -= john.credit.payment;
			john.credit.debt -= john.credit.payment;
			print_credit_payment("John", john.credit.payment, john.credit.debt);
		} else {
			RUB partial = john.vtb.account_rub;
			john.credit.debt -= partial;
			john.vtb.account_rub = 0;
			print_credit_payment("John", partial, john.credit.debt);
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
			print_early_payment("Alice", extra_payment, alice.vtb.account_rub);
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
			print_early_payment("John", extra_payment, john.vtb.account_rub);
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
			print_operation("Alice's INVESTMENTS", "investing", invest_amount, "");
			alice.vtb.account_rub -= invest_amount;
			
			int invest_type = rand() % 2;
			
			if (invest_type == 0) {
				RUB profit = invest_amount * 0.05;
				alice.vtb.account_rub += invest_amount + profit;
				print_investment_result("Alice", "Deposit", profit, "+");
			} else {
				int risk = rand() % 100;
				if (risk < 70) {
					RUB profit = invest_amount * 0.20;
					alice.vtb.account_rub += invest_amount + profit;
					print_investment_result("Alice", "Stocks", profit, "SUCCESS! +");
				} else if (risk < 90) {
					RUB loss = invest_amount * 0.10;
					alice.vtb.account_rub += invest_amount - loss;
					print_investment_result("Alice", "Stocks", loss, "small losses -");
				} else {
					RUB loss = invest_amount * 0.30;
					alice.vtb.account_rub += invest_amount - loss;
					print_investment_result("Alice", "Stocks", loss, "losses -");
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
			print_operation("John's INVESTMENTS", "investing", invest_amount, "");
			john.vtb.account_rub -= invest_amount;
			
			int invest_type = rand() % 2;
			
			if (invest_type == 0) {
				RUB profit = invest_amount * 0.06;
				john.vtb.account_rub += invest_amount + profit;
				print_investment_result("John", "Deposit", profit, "+");
			} else {
				int risk = rand() % 100;
				if (risk < 60) {
					RUB profit = invest_amount * 0.25;
					john.vtb.account_rub += invest_amount + profit;
					print_investment_result("John", "Stocks", profit, "SUCCESS! +");
				} else if (risk < 80) {
					RUB loss = invest_amount * 0.10;
					john.vtb.account_rub += invest_amount - loss;
					print_investment_result("John", "Stocks", loss, "small losses -");
				} else {
					RUB loss = invest_amount * 0.30;
					john.vtb.account_rub += invest_amount - loss;
					print_investment_result("John", "Stocks", loss, "losses -");
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
			print_car_transaction("Alice", alice.car.value, new_car_price, "buying new car");
		} else {
			printf("    Alice not enough money, looking for options...\n");
			
			RUB budget_car = alice.car.value * 0.8;
			if (alice.vtb.account_rub >= budget_car + alice.car.gas) {
				alice.vtb.account_rub -= (budget_car + alice.car.gas);
				alice.car.value = budget_car;
				alice_car_purchase_month = current_month;
				alice_car_purchase_year = current_year;
				print_car_transaction("Alice", alice.car.value, budget_car, "buying budget car");
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
			print_car_transaction("John", john.car.value, new_car_price, "buying new car");
		} else {
			printf("    John saving more for a better car...\n");
		}
	}
}


void family_utilities(const int month, const int year) {
	print_subheader("FAMILY UTILITIES (John pays)");
	
	// Базовые коммунальные услуги
	RUB rent = 45000;           // Аренда
	RUB electricity = 3500;      // Электричество
	RUB water = 2000;            // Вода
	RUB gas = 1200;              // Газ
	RUB internet_tv = 1500;      // Интернет + ТВ
	RUB mobile_family = 2500;    // Мобильная связь на семью
	RUB cleaning = 2000;         // Уборка
	
	// Новые услуги
	RUB security = 3000;         // Охрана/домофон
	RUB garbage = 800;           // Вывоз мусора
	RUB elevator = 500;          // Обслуживание лифта
	RUB home_repair = 1000;      // Текущий ремонт дома
	RUB parking = 4000;          // Парковка
	RUB gym = 3500;              // Фитнес/спортзал
	RUB tv_subscription = 1000;  // Подписка на ТВ-каналы
	RUB music_subscription = 500; // Музыкальный стриминг
	RUB cinema_subscription = 800; // Кинотеатр онлайн
	
	// Сезонные корректировки
	switch (month) {
	case 12:
	case 1:
	case 2:
		rent += 4000;          // Зимой дороже отопление
		electricity += 1000;    // Больше света
		printf("  Winter months: heating +4000 RUB, electricity +1000 RUB\n");
		break;
		
	case 6:
	case 7:
	case 8:
		electricity += 3000;    // Кондиционер летом
		water += 1000;          // Больше воды летом
		printf("  Summer months: air conditioning +3000 RUB, water +1000 RUB\n");
		break;
		
	case 4:
	case 10:
		cleaning += 1500;       // Генеральная уборка
		printf("  Seasonal cleaning: +1500 RUB\n");
		break;
	}
	
	// Случайные непредвиденные расходы
	int unexpected = rand() % 100;
	if (unexpected < 15) {  
		RUB unexpected_cost = 0;
		const char* reason = "";
		
		switch (rand() % 8) {  
		case 0:
			unexpected_cost = 5000;
			reason = "broken washing machine";
			break;
		case 1:
			unexpected_cost = 3000;
			reason = "leaky faucet repair";
			break;
		case 2:
			unexpected_cost = 2000;
			reason = "light bulbs and small fixes";
			break;
		case 3:
			unexpected_cost = 4000;
			reason = "refrigerator repair";
			break;
		case 4:
			unexpected_cost = 2500;
			reason = "window cleaning";
			break;
		case 5:
			unexpected_cost = 3500;
			reason = "pest control";
			break;
		case 6:
			unexpected_cost = 6000;
			reason = "water heater repair";
			break;
		case 7:
			unexpected_cost = 1500;
			reason = "key replacement";
			break;
		}
		
		home_repair += unexpected_cost;
		printf("  Unexpected repair: %s - %lld RUB\n", reason, unexpected_cost);
	}
	
	// Инфляция коммунальных услуг по годам
	float utilities_inflation = 1.0;
	switch (year) {
		case 2027: utilities_inflation = 1.06; break;  // +6%
		case 2028: utilities_inflation = 1.08; break;  // +8%
		case 2029: utilities_inflation = 1.05; break;  // +5%
		default: utilities_inflation = 1.0;
	}
	
	if (year > 2026) {
		rent *= utilities_inflation;
		electricity *= utilities_inflation;
		water *= utilities_inflation;
		gas *= utilities_inflation;
		security *= utilities_inflation;
		garbage *= utilities_inflation;
		printf("  Utilities inflation: +%.0f%%\n", (utilities_inflation - 1) * 100);
	}
	
	//подсчет общей суммы
	RUB total_utilities = rent + electricity + water + gas + internet_tv + 
	mobile_family + cleaning + security + garbage + 
	elevator + home_repair + parking + gym + 
	tv_subscription + music_subscription + cinema_subscription;
	
	//вывод
	printf("\n  Total utilities: %lld RUB\n", total_utilities);
	printf("  Breakdown:\n");
	printf("    - Rent: %lld RUB\n", rent);
	printf("    - Electricity: %lld RUB\n", electricity);
	printf("    - Water: %lld RUB\n", water);
	printf("    - Gas: %lld RUB\n", gas);
	printf("    - Internet + TV: %lld RUB\n", internet_tv);
	printf("    - Mobile family: %lld RUB\n", mobile_family);
	printf("    - Cleaning: %lld RUB\n", cleaning);
	printf("    - Security: %lld RUB\n", security);
	printf("    - Garbage collection: %lld RUB\n", garbage);
	printf("    - Elevator: %lld RUB\n", elevator);
	printf("    - Home repair fund: %lld RUB\n", home_repair);
	printf("    - Parking: %lld RUB\n", parking);
	printf("    - Gym: %lld RUB\n", gym);
	printf("    - TV subscription: %lld RUB\n", tv_subscription);
	printf("    - Music streaming: %lld RUB\n", music_subscription);
	printf("    - Cinema subscription: %lld RUB\n", cinema_subscription);
	
	float percent_of_salary = (float)total_utilities / john.salary * 100;
	printf("  Paid by: JOHN\n");
	printf("  This is %.1f%% of John's monthly salary (%lld RUB)\n", percent_of_salary, john.salary);
	
	// Оплата коммунальных услуг
	if (total_utilities <= john.salary * 0.5) {  // Увеличили порог до 50%
		john.vtb.account_rub -= total_utilities;
		printf("  John paid: %lld RUB (remaining: %lld RUB)\n", total_utilities, john.vtb.account_rub);
	} else {
		printf("  Utilities are very high this month (over 50%% of salary)\n");
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
	
	// Статистика по годам
	static RUB yearly_utilities[4] = {0, 0, 0, 0};
	int year_index = year - 2026;
	if (year_index >= 0 && year_index < 4) {
		yearly_utilities[year_index] += total_utilities;
	}
	
	if (month == 12 && year_index >= 0 && year_index < 4) {
		printf("\n  === YEAR %d UTILITIES SUMMARY ===\n", year);
		printf("  Total for the year: %lld RUB\n", yearly_utilities[year_index]);
		printf("  Monthly average: %lld RUB\n", yearly_utilities[year_index] / 12);
		
		RUB john_yearly = john.salary * 12;
		float yearly_percent = (float)yearly_utilities[year_index] / john_yearly * 100;
		printf("  %.1f%% of John's annual salary\n", yearly_percent);
	}
}


// Функция для подарков на Новый год
void new_year_gifts(const int month, const int year) {
	if (month == 12) {
		printf("  NEW YEAR GIFTS:\n");
		
		// Покупают подарки друг другу
		if (john.vtb.account_rub >= 5000) {
			john.vtb.account_rub -= 5000;
			print_operation("John", "bought gift for Alice", 5000, "");
		} else {
			printf("    John can't afford gift for Alice :(\n");
		}
		
		if (alice.vtb.account_rub >= 5000) {
			alice.vtb.account_rub -= 5000;
			print_operation("Alice", "bought gift for John", 5000, "");
		} else {
			printf("    Alice can't afford gift for John :(\n");
		}
		
		// Общие подарки родственникам
		RUB family_gifts = 5000;
		RUB alice_part = family_gifts / 2;
		RUB john_part = family_gifts / 2;
		
		if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
			alice.vtb.account_rub -= alice_part;
			john.vtb.account_rub -= john_part;
			printf("    Gifts for family: %lld RUB (%lld each)\n", family_gifts, alice_part);
		} else {
			printf("    Not enough money for family gifts\n");
		}
		
		// Новогодний стол
		RUB new_year_food = 8000;
		RUB alice_food_part = new_year_food / 2;
		RUB john_food_part = new_year_food / 2;
		
		if (alice.vtb.account_rub >= alice_food_part && john.vtb.account_rub >= john_food_part) {
			alice.vtb.account_rub -= alice_food_part;
			john.vtb.account_rub -= john_food_part;
			printf("    New Year's Eve dinner: %lld RUB (%lld each)\n", new_year_food, alice_food_part);
		}
	}
}


// Функция для подарков на 8 марта
void march_8_gifts(const int month, const int year) {
	if (month == 3) {
		printf("  MARCH 8 (International Women's Day):\n");
		if (john.vtb.account_rub >= 5000) {
			john.vtb.account_rub -= 5000;
			print_operation("John", "gave Alice flowers and chocolates", 5000, "");
		} else if (john.vtb.account_rub >= 3000) {
			john.vtb.account_rub -= 3000;
			print_operation("John", "gave Alice flowers", 3000, "");
		} else {
			printf("    John forgot about March 8 :(\n");
		}
		
		// Подарки мамам
		RUB moms_gift = 4000;
		if (john.vtb.account_rub >= moms_gift) {
			john.vtb.account_rub -= moms_gift;
			printf("    Gift for John's mom: %lld RUB\n", moms_gift);
		}
		if (alice.vtb.account_rub >= moms_gift) {
			alice.vtb.account_rub -= moms_gift;
			printf("    Gift for Alice's mom: %lld RUB\n", moms_gift);
		}
	}
}


// Функция для подарков на 23 февраля
void february_23_gifts(const int month, const int year) {
	if (month == 2) {
		printf("  FEBRUARY 23 (Defender of the Fatherland Day):\n");
		if (alice.vtb.account_rub >= 5000) {
			alice.vtb.account_rub -= 5000;
			print_operation("Alice", "gave John a gift", 5000, "");
		} else if (alice.vtb.account_rub >= 3000) {
			alice.vtb.account_rub -= 3000;
			print_operation("Alice", "gave John a gift", 3000, "");
		} else {
			printf("    Alice forgot about February 23 :(\n");
		}
		
		// Подарки папам
		RUB dads_gift = 4000;
		if (alice.vtb.account_rub >= dads_gift) {
			alice.vtb.account_rub -= dads_gift;
			printf("    Gift for Alice's dad: %lld RUB\n", dads_gift);
		}
		if (john.vtb.account_rub >= dads_gift) {
			john.vtb.account_rub -= dads_gift;
			printf("    Gift for John's dad: %lld RUB\n", dads_gift);
		}
	}
}


// Функция для Дня Святого Валентина
void valentines_day_gifts(const int month, const int year) {
	if (month == 2) {
		printf("  VALENTINE'S DAY:\n");
		if (year == 2026) {
			// Первый год вместе - особенный
			if (john.vtb.account_rub >= 5000 && alice.vtb.account_rub >= 5000) {
				john.vtb.account_rub -= 5000;
				alice.vtb.account_rub -= 5000;
				printf("    Romantic weekend getaway: 10000 RUB (5000 each)\n");
			}
		} else {
			if (john.vtb.account_rub >= 3000 && alice.vtb.account_rub >= 3000) {
				john.vtb.account_rub -= 3000;
				alice.vtb.account_rub -= 3000;
				printf("    Romantic dinner: 6000 RUB (3000 each)\n");
			}
		}
	}
}


// Функция для Дня Рождения Алисы (предположим, что в мае)
void birthday_alice(const int month, const int year) {
	if (month == 5) {
		printf("  ALICE'S BIRTHDAY (May):\n");
		
		// Подарок от Джона
		RUB gift_from_john = 7000;
		if (john.vtb.account_rub >= gift_from_john) {
			john.vtb.account_rub -= gift_from_john;
			print_operation("John", "gave birthday gift to Alice", gift_from_john, "");
		}
		
		// Празднование
		RUB celebration = 10000;
		RUB alice_part = celebration / 2;
		RUB john_part = celebration / 2;
		
		if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
			alice.vtb.account_rub -= alice_part;
			john.vtb.account_rub -= john_part;
			printf("    Birthday celebration: %lld RUB (%lld each)\n", celebration, alice_part);
		}
		
		// Друзья приходят в гости
		printf("    Alice's friends came to visit!\n");
	}
}


// Функция для Дня Рождения Джона (предположим, что в сентябре)
void birthday_john(const int month, const int year) {
	if (month == 9) {
		printf("  JOHN'S BIRTHDAY (September):\n");
		
		// Подарок от Алисы
		RUB gift_from_alice = 8000;
		if (alice.vtb.account_rub >= gift_from_alice) {
			alice.vtb.account_rub -= gift_from_alice;
			print_operation("Alice", "gave birthday gift to John", gift_from_alice, "");
		}
		
		// Празднование
		RUB celebration = 12000;
		RUB alice_part = celebration / 2;
		RUB john_part = celebration / 2;
		
		if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
			alice.vtb.account_rub -= alice_part;
			john.vtb.account_rub -= john_part;
			printf("    Birthday celebration: %lld RUB (%lld each)\n", celebration, alice_part);
		}
		
		// Поход в ресторан
		if (alice.vtb.account_rub >= 5000 && john.vtb.account_rub >= 5000) {
			alice.vtb.account_rub -= 5000;
			john.vtb.account_rub -= 5000;
			printf("    Fancy dinner at restaurant: 10000 RUB (5000 each)\n");
		}
	}
}


// Функция для Годовщины свадьбы (предположим, что в августе)
void anniversary_wedding(const int month, const int year) {
	if (month == 8) {
		int years_married = year - 2026;
		if (years_married > 0) {
			printf("  WEDDING ANNIVERSARY (%d years):\n", years_married);
			
			RUB celebration = 8000 + (years_married * 2000); // Чем больше лет, тем дороже праздник
			RUB alice_part = celebration / 2;
			RUB john_part = celebration / 2;
			
			if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
				alice.vtb.account_rub -= alice_part;
				john.vtb.account_rub -= john_part;
				printf("    Anniversary celebration: %lld RUB (%lld each)\n", celebration, alice_part);
			}
			
			// Подарки друг другу
			RUB gift = 5000 + (years_married * 1000);
			if (john.vtb.account_rub >= gift) {
				john.vtb.account_rub -= gift;
				printf("    John gave Alice anniversary gift: %lld RUB\n", gift);
			}
			if (alice.vtb.account_rub >= gift) {
				alice.vtb.account_rub -= gift;
				printf("    Alice gave John anniversary gift: %lld RUB\n", gift);
			}
		}
	}
}


// Функция для Дня Победы (9 мая)
void victory_day(const int month, const int year) {
	if (month == 5) {
		printf("  VICTORY DAY (May 9):\n");
		
		// Поздравление ветеранов
		RUB veterans_gift = 2000;
		if (john.vtb.account_rub >= veterans_gift) {
			john.vtb.account_rub -= veterans_gift;
			printf("    Congratulations to veterans: %lld RUB\n", veterans_gift);
		}
		
		// Праздничный обед
		RUB festive_dinner = 3000;
		RUB alice_part = festive_dinner / 2;
		RUB john_part = festive_dinner / 2;
		
		if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
			alice.vtb.account_rub -= alice_part;
			john.vtb.account_rub -= john_part;
			printf("    Festive dinner: %lld RUB (%lld each)\n", festive_dinner, alice_part);
		}
	}
}


// Функция для Хэллоуина (31 октября)
void halloween(const int month, const int year) {
	if (month == 10) {
		printf("  HALLOWEEN (October 31):\n");
		
		// Украшение дома
		RUB decorations = 2000;
		RUB alice_part = decorations / 2;
		RUB john_part = decorations / 2;
		
		if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
			alice.vtb.account_rub -= alice_part;
			john.vtb.account_rub -= john_part;
			printf("    Halloween decorations: %lld RUB (%lld each)\n", decorations, alice_part);
		}
		
		// Угощения для детей
		RUB candy = 1500;
		if (john.vtb.account_rub >= candy) {
			john.vtb.account_rub -= candy;
			printf("    Candy for neighborhood children: %lld RUB\n", candy);
		}
		
		printf("    Alice dressed up as a witch, John as a vampire\n");
	}
}


// Основная функция, объединяющая все праздники
void process_all_holidays(const int month, const int year) {
	print_subheader("HOLIDAYS & CELEBRATIONS");
	
	new_year_gifts(month, year);
	valentines_day_gifts(month, year);
	february_23_gifts(month, year);
	march_8_gifts(month, year);
	victory_day(month, year);
	birthday_alice(month, year);
	anniversary_wedding(month, year);
	birthday_john(month, year);
	halloween(month, year);
}


// Функция для благотворительных пожертвований Алисы
void alice_charity_donation(const int month, const int year) {
	// Алиса жертвует на благотворительность в декабре
	if (month == 12 && alice.vtb.account_rub > 10000) {
		RUB donation = 5000;  
		alice.vtb.account_rub -= donation;
		print_operation("Alice", "charity donation", donation, "");
		printf("    Alice helps animal shelter\n");
	} else if (month == 12 && alice.vtb.account_rub > 5000) {
		RUB donation = 2000;
		alice.vtb.account_rub -= donation;
		print_operation("Alice", "small charity donation", donation, "");
	} else if (month == 12) {
		printf("  Alice wants to donate but doesn't have enough money\n");
	}
}


// Функция для помощи родителям от Джона
void john_parents_help(const int month, const int year) {
	// Джон помогает родителям раз в квартал
	if ((month == 2 || month == 5 || month == 8 || month == 11) && john.vtb.account_rub > 30000) {
		RUB help_parents = 15000;  // Увеличили сумму
		john.vtb.account_rub -= help_parents;
		print_operation("John", "helping parents", help_parents, "");
		printf("    Parents were very happy! Called to say thank you\n");
	} else if ((month == 2 || month == 5 || month == 8 || month == 11) && john.vtb.account_rub > 15000) {
		RUB help_parents = 8000;
		john.vtb.account_rub -= help_parents;
		print_operation("John", "helping parents", help_parents, "");
	} else if ((month == 2 || month == 5 || month == 8 || month == 11)) {
		printf("  John wants to help parents but doesn't have enough money\n");
	}
}


// Функция для совместной благотворительности семьи
void family_joint_charity(const int month, const int year) {
	// Совместная благотворительность на Новый год и в июне
	if ((month == 12 || month == 6) && year % 2 == 0) {
		RUB joint_charity = 7000;  // Увеличили сумму
		RUB alice_part = joint_charity / 2;
		RUB john_part = joint_charity / 2;
		
		if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
			alice.vtb.account_rub -= alice_part;
			john.vtb.account_rub -= john_part;
			printf("  Family donation to children's hospital: %lld RUB (%lld each)\n", 
				   joint_charity, alice_part);
			printf("    They bought toys and books for sick children\n");
		}
	}
}


// Функция для волонтерства Алисы
void alice_volunteering(const int month, const int year) {
	if (month == 4) {
		printf("  Alice volunteered at local library this month\n");
		printf("    She helped organize books and read to children\n");
	}
	if (month == 11) {
		printf("  Alice helped at the animal shelter this month\n");
		printf("    She walked dogs and played with cats\n");
	}
}


// Функция для волонтерства Джона
void john_volunteering(const int month, const int year) {
	if (month == 9) {
		printf("  John helped clean up the park this month\n");
		printf("    He planted trees and collected trash\n");
	}
	if (month == 3) {
		printf("  John helped elderly neighbors with snow removal\n");
	}
}


// Основная функция, объединяющая все благотворительные активности
void process_all_charity(const int month, const int year) {
	print_subheader("CHARITY & VOLUNTEERING");
	
	// Денежные пожертвования
	alice_charity_donation(month, year);
	john_parents_help(month, year);
	family_joint_charity(month, year);
	
	// Волонтерство 
	alice_volunteering(month, year);
	john_volunteering(month, year);
}


// Функция здоровья и медицины (игровая механика)
void family_health_and_medicine(const int month, const int year) {
	print_subheader("HEALTH AND MEDICINE");
	
	// Статические переменные для хранения состояния здоровья
	static int alice_health = 100;  // 100% - отличное здоровье
	static int john_health = 100;
	static RUB medicine_fund = 0;
	static int doctor_visits_alice = 0;
	static int doctor_visits_john = 0;
	
	// Ежемесячное ухудшение здоровья (стресс, погода и т.д.)
	int alice_decline = rand() % 5 + 1;  // 1-5%
	int john_decline = rand() % 7 + 2;   // 2-8% (Джон больше работает, сильнее устает)
	
	// Сезонные факторы
	switch (month) {
	case 12:
	case 1:
	case 2:
		// Зимой больше болеют
		alice_decline += 3;
		john_decline += 4;
		printf("  Winter season: higher risk of illness\n");
		break;
	case 3:
	case 4:
		// Весной авитаминоз
		alice_decline += 2;
		john_decline += 2;
		printf("  Spring vitamin deficiency: health declines faster\n");
		break;
	}
	
	alice_health -= alice_decline;
	john_health -= john_decline;
	
	// Здоровье не может быть меньше 0
	if (alice_health < 0) alice_health = 0;
	if (john_health < 0) john_health = 0;
	
	printf("\n  CURRENT HEALTH STATUS:\n");
	printf("    Alice: %d%%\n", alice_health);
	printf("    John: %d%%\n", john_health);
	
	// Профилактика здоровья (витамины, спорт)
	if (month == 10 || month == 4) {
		RUB vitamins_cost = 3000;
		RUB gym_membership = 5000;
		
		printf("\n  HEALTH PREVENTION:\n");
		
		if (alice.vtb.account_rub >= vitamins_cost) {
			alice.vtb.account_rub -= vitamins_cost;
			alice_health += 5;
			if (alice_health > 100) alice_health = 100;
			printf("    Alice bought vitamins: %lld RUB (health +5%%)\n", vitamins_cost);
		}
		
		if (john.vtb.account_rub >= gym_membership) {
			john.vtb.account_rub -= gym_membership;
			john_health += 7;
			if (john_health > 100) john_health = 100;
			printf("    John bought gym membership: %lld RUB (health +7%%)\n", gym_membership);
		}
	}
	
	// Посещение врачей (когда здоровье падает ниже 70%)
	if (alice_health < 70) {
		RUB doctor_cost = 2500;
		doctor_visits_alice++;
		
		if (alice.vtb.account_rub >= doctor_cost) {
			alice.vtb.account_rub -= doctor_cost;
			alice_health += 15;
			if (alice_health > 100) alice_health = 100;
			printf("\n  Alice visited doctor (visit #%d):\n", doctor_visits_alice);
			printf("    Cost: %lld RUB, health improved to %d%%\n", doctor_cost, alice_health);
			printf("    Doctor prescribed medicine and recommended more rest\n");
			
			// Лекарства по рецепту
			RUB medicine = 1800;
			if (alice.vtb.account_rub >= medicine) {
				alice.vtb.account_rub -= medicine;
				alice_health += 5;
				printf("    Bought medicine: %lld RUB (health +5%%)\n", medicine);
			}
		}
	}
	
	if (john_health < 65) {  // Джон терпит до более низкого уровня
		RUB doctor_cost = 3000;  // Дорогой врач для Джона
		doctor_visits_john++;
		
		if (john.vtb.account_rub >= doctor_cost) {
			john.vtb.account_rub -= doctor_cost;
			john_health += 12;
			if (john_health > 100) john_health = 100;
			printf("\n  John visited doctor (visit #%d):\n", doctor_visits_john);
			printf("    Cost: %lld RUB, health improved to %d%%\n", doctor_cost, john_health);
			printf("    Doctor said to work less and sleep more\n");
		}
	}
	
	// Экстренные случаи (здоровье упало слишком низко)
	if (alice_health < 30) {
		printf("\n  URGENT! Alice needs medical help!\n");
		RUB emergency_cost = 15000;
		
		if (alice.vtb.account_rub >= emergency_cost) {
			alice.vtb.account_rub -= emergency_cost;
			alice_health = 60;
			printf("    Emergency help: %lld RUB, health restored to 60%%\n", emergency_cost);
		} else if (john.vtb.account_rub >= emergency_cost) {
			john.vtb.account_rub -= emergency_cost;
			alice_health = 60;
			printf("    John paid for Alice's emergency help: %lld RUB\n", emergency_cost);
			printf("    Alice's health restored to 60%%\n");
		} else {
			printf("    NO MONEY FOR EMERGENCY HELP! This is very dangerous!\n");
		}
	}
	
	if (john_health < 25) {
		printf("\n  URGENT! John needs medical help!\n");
		RUB emergency_cost = 20000;
		
		if (john.vtb.account_rub >= emergency_cost) {
			john.vtb.account_rub -= emergency_cost;
			john_health = 55;
			printf("    Emergency help: %lld RUB, health restored to 55%%\n", emergency_cost);
		} else if (alice.vtb.account_rub >= emergency_cost) {
			alice.vtb.account_rub -= emergency_cost;
			john_health = 55;
			printf("    Alice paid for John's emergency help: %lld RUB\n", emergency_cost);
			printf("    John's health restored to 55%%\n");
		} else {
			printf("    NO MONEY FOR EMERGENCY HELP! This is very dangerous!\n");
		}
	}
	
	// Накопление на медицину
	RUB medicine_savings = 2000;
	if (month % 3 == 0) {  // Каждый третий месяц
		if (alice.vtb.account_rub >= medicine_savings/2 && 
			john.vtb.account_rub >= medicine_savings/2) {
			alice.vtb.account_rub -= medicine_savings/2;
			john.vtb.account_rub -= medicine_savings/2;
			medicine_fund += medicine_savings;
			printf("\n  Saved to medical fund: %lld RUB\n", medicine_savings);
			printf("    Current medical fund: %lld RUB\n", medicine_fund);
		}
	}
	
	// Статистика за год
	if (month == 12) {
		printf("\n  YEARLY HEALTH STATISTICS %d:\n", year);
		printf("    Doctor visits: Alice - %d, John - %d\n", 
			   doctor_visits_alice, doctor_visits_john);
		printf("    Spent on medicine (from fund): %lld RUB\n", medicine_fund);
		printf("    Average health: %.1f%%\n", (alice_health + john_health) / 2.0);
	}
}


// НОВАЯ ФУНКЦИЯ: Накопления и финансовые цели семьи
void family_savings_goals(const int month, const int year) {
	print_subheader("SAVINGS AND FINANCIAL GOALS");
	
	// Статические переменные для разных целей накопления
	static RUB vacation_fund = 0;        // На отпуск
	static RUB emergency_fund = 0;       // На черный день
	static RUB big_purchase_fund = 0;    // На крупную покупку (новая техника, мебель)
	static RUB education_fund = 0;        // На образование/курсы
	
	// Цели накопления
	static RUB vacation_goal = 200000;    // Цель на отпуск
	static RUB emergency_goal = 500000;   // Цель на черный день (3-6 месяцев расходов)
	static RUB big_purchase_goal = 150000; // На новую технику/мебель
	static RUB education_goal = 100000;    // На курсы/обучение
	
	// Прогресс по целям
	printf("\n  CURRENT SAVINGS:\n");
	printf("    Vacation fund: %lld RUB / %lld RUB (%.0f%%)\n", 
		   vacation_fund, vacation_goal, (float)vacation_fund / vacation_goal * 100);
	printf("    Emergency fund: %lld RUB / %lld RUB (%.0f%%)\n", 
		   emergency_fund, emergency_goal, (float)emergency_fund / emergency_goal * 100);
	printf("    Big purchases: %lld RUB / %lld RUB (%.0f%%)\n", 
		   big_purchase_fund, big_purchase_goal, (float)big_purchase_fund / big_purchase_goal * 100);
	printf("    Education: %lld RUB / %lld RUB (%.0f%%)\n", 
		   education_fund, education_goal, (float)education_fund / education_goal * 100);
	
	// Ежемесячные отчисления (фиксированный процент от дохода)
	RUB total_monthly_income = alice.salary + john.salary;
	RUB savings_per_month = total_monthly_income * 0.1;  // 10% от общего дохода
	
	// Распределение по разным фондам
	RUB to_vacation = savings_per_month * 0.3;      // 30% на отпуск
	RUB to_emergency = savings_per_month * 0.4;      // 40% в резервный фонд
	RUB to_big_purchase = savings_per_month * 0.2;   // 20% на крупные покупки
	RUB to_education = savings_per_month * 0.1;      // 10% на образование
	
	printf("\n  MONTHLY CONTRIBUTIONS (10%% of income):\n");
	printf("    Total savings: %lld RUB\n", savings_per_month);
	printf("    Distribution:\n");
	printf("      - Vacation (30%%): %lld RUB\n", to_vacation);
	printf("      - Emergency fund (40%%): %lld RUB\n", to_emergency);
	printf("      - Large purchases (20%%): %lld RUB\n", to_big_purchase);
	printf("      - Education (10%%): %lld RUB\n", to_education);
	
	// Проверяем, могут ли оба выделить эти деньги
	RUB alice_share = savings_per_month / 2;
	RUB john_share = savings_per_month / 2;
	
	if (alice.vtb.account_rub >= alice_share && john.vtb.account_rub >= john_share) {
		// Откладываем деньги
		alice.vtb.account_rub -= alice_share;
		john.vtb.account_rub -= john_share;
		
		vacation_fund += to_vacation;
		emergency_fund += to_emergency;
		big_purchase_fund += to_big_purchase;
		education_fund += to_education;
		
		printf("\n  Money successfully saved!\n");
	} else {
		printf("\n  Insufficient funds for contributions this month\n");
		printf("    Need: %lld RUB (Alice - %lld, John - %lld)\n", 
			   savings_per_month, alice_share, john_share);
	}
	
	// Достижение целей - тратим накопления
	if (month == 7 && vacation_fund >= vacation_goal) {  // Летом едем в отпуск
		printf("\n  >>> VACATION! <<<\n");
		printf("    Spent from vacation fund: %lld RUB\n", vacation_fund);
		printf("    Family went to the sea for 2 weeks\n");
		vacation_fund = 0;  // Обнуляем фонд после отпуска
	}
	
	if (month == 11 && big_purchase_fund >= big_purchase_goal) {  // Осенью крупные покупки
		printf("\n  >>> LARGE PURCHASE! <<<\n");
		printf("    Spent from purchase fund: %lld RUB\n", big_purchase_fund);
		printf("    Bought new refrigerator and washing machine\n");
		big_purchase_fund = 0;  // Обнуляем фонд
	}
	
	if (month == 9 && education_fund >= education_goal) {  // Осенью обучение
		printf("\n  >>> EDUCATION! <<<\n");
		printf("    Spent from education fund: %lld RUB\n", education_fund);
		printf("    Alice enrolled in English courses\n");
		printf("    John bought online programming courses\n");
		education_fund = 0;  // Обнуляем фонд
	}
	
	// Использование резервного фонда в экстренных ситуациях
	// Проверяем, хватает ли денег на счетах (имитация непредвиденных расходов)
	if (alice.vtb.account_rub < 10000 && emergency_fund > 0) {
		RUB needed = 20000 - alice.vtb.account_rub;
		if (needed > emergency_fund) needed = emergency_fund;
		
		printf("\n  >>> USING EMERGENCY FUND! <<<\n");
		printf("    Alice ran out of money, taking from emergency fund: %lld RUB\n", needed);
		emergency_fund -= needed;
		alice.vtb.account_rub += needed;
		printf("    Remaining in emergency fund: %lld RUB\n", emergency_fund);
	}
	
	if (john.vtb.account_rub < 10000 && emergency_fund > 0) {
		RUB needed = 20000 - john.vtb.account_rub;
		if (needed > emergency_fund) needed = emergency_fund;
		
		printf("\n  >>> USING EMERGENCY FUND! <<<\n");
		printf("    John ran out of money, taking from emergency fund: %lld RUB\n", needed);
		emergency_fund -= needed;
		john.vtb.account_rub += needed;
		printf("    Remaining in emergency fund: %lld RUB\n", emergency_fund);
	}
	
	// Годовой отчет
	if (month == 12) {
		printf("\n  === YEARLY SAVINGS REPORT %d ===\n", year);
		printf("    Saved during the year:\n");
		printf("      - Vacation fund: %lld RUB\n", vacation_fund);
		printf("      - Emergency fund: %lld RUB\n", emergency_fund);
		printf("      - Large purchases: %lld RUB\n", big_purchase_fund);
		printf("      - Education: %lld RUB\n", education_fund);
		printf("    TOTAL SAVED: %lld RUB\n", 
			   vacation_fund + emergency_fund + big_purchase_fund + education_fund);
	}
}


//Спорт и фитнес
void family_sports(const int month, const int year) {
	print_subheader("SPORTS AND FITNESS");
	
	// Статические переменные для отслеживания прогресса
	static int alice_workouts = 0;      // Всего тренировок Алисы
	static int john_workouts = 0;       // Всего тренировок Джона
	static RUB sports_spent = 0;         // Всего потрачено на спорт
	
	// 1. Абонементы в спортзал (покупают в январе и июне)
	if (month == 1 || month == 6) {
		RUB membership = 4000;  // в месяц
		RUB total_cost = membership * 6;  // на полгода
		RUB alice_part = total_cost / 2;
		RUB john_part = total_cost / 2;
		
		if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
			alice.vtb.account_rub -= alice_part;
			john.vtb.account_rub -= john_part;
			sports_spent += total_cost;
			printf("\n  Bought gym memberships for six months:\n");
			printf("    Cost: %lld RUB (Alice - %lld, John - %lld)\n", 
				   total_cost, alice_part, john_part);
		} else {
			printf("\n  Not enough money for gym memberships\n");
		}
	}
	
	// 2. Ежемесячные тренировки
	int alice_month = 8 + (rand() % 9);   // 8-16 тренировок в месяц
	int john_month = 10 + (rand() % 8);    // 10-18 тренировок в месяц
	
	alice_workouts += alice_month;
	john_workouts += john_month;
	
	printf("\n  WORKOUTS THIS MONTH:\n");
	printf("    Alice: %d workouts", alice_month);
	if (alice_month > 12) printf(" (active month!)");
	printf("\n");
	printf("    John: %d workouts", john_month);
	if (john_month > 15) printf(" (champion mode!)");
	printf("\n");
	
	// 3. Различные виды спорта (для разнообразия)
	const char* alice_sports[] = {"yoga", "swimming", "running", "dancing", "pilates", "tennis"};
	const char* john_sports[] = {"gym", "football", "basketball", "boxing", "cycling", "running"};
	
	int alice_fav = rand() % 6;
	int john_fav = rand() % 6;
	
	printf("    Alice's favorite sport: %s\n", alice_sports[alice_fav]);
	printf("    John's favorite sport: %s\n", john_sports[john_fav]);
	
	// 4. Спортивная экипировка (каждые 3 месяца)
	if (month % 3 == 0) {
		RUB equipment = 2000 + (rand() % 4000);  // 2000-6000 руб
		RUB alice_equip = equipment / 2;
		RUB john_equip = equipment - alice_equip;
		
		if (alice.vtb.account_rub >= alice_equip && john.vtb.account_rub >= john_equip) {
			alice.vtb.account_rub -= alice_equip;
			john.vtb.account_rub -= john_equip;
			sports_spent += equipment;
			
			printf("\n  BUYING SPORTS EQUIPMENT:\n");
			
			if (rand() % 2) {
				printf("    Alice bought: %s for %lld RUB\n", 
					   alice_fav == 0 ? "yoga mat" : 
					   alice_fav == 1 ? "swimsuit" : "running shoes", 
					   alice_equip);
			} else {
				printf("    John bought: %s for %lld RUB\n", 
					   john_fav == 0 ? "gym gloves" : 
					   john_fav == 1 ? "football boots" : "sports suit", 
					   john_equip);
			}
		}
	}
	
	// 5. Общая статистика
	printf("\n  TOTAL STATISTICS:\n");
	printf("    Total workouts: Alice - %d, John - %d\n", alice_workouts, john_workouts);
	printf("    Total spent on sports: %lld RUB\n", sports_spent);
	
	if (alice_workouts > 300) {
		printf("    Alice is in great athletic shape!\n");
	}
	if (john_workouts > 400) {
		printf("    John is a true athlete!\n");
	}
	
	// 6. Годовой отчёт
	static RUB yearly_sports[4] = {0};
	int year_index = year - 2026;
	if (year_index >= 0 && year_index < 4) {
		yearly_sports[year_index] += sports_spent;
	}
	
	if (month == 12) {
		printf("\n  === SPORTS RESULTS FOR %d ===\n", year);
		printf("    Workouts this year: %d\n", alice_workouts + john_workouts);
		printf("    Spent this year: %lld RUB\n", yearly_sports[year_index]);
	}
}


void show_monthly_stats(int m, int y) {
	print_separator();
	
	print_person_stats("ALICE", 
					   alice.vtb.account_rub, 
					   alice.vtb.account_usd, 
					   alice.credit.debt, 
					   alice.car.value, 
					   alice.food);
	
	
	printf("\n--- JOHN (salary: %lld RUB) ---\n", john.salary);
	printf("Account: %lld RUB, %lld USD\n", john.vtb.account_rub, john.vtb.account_usd);
	printf("Debt: %lld RUB\n", john.credit.debt);
	printf("Car: %lld RUB\n", john.car.value);
	printf("Food budget: %lld RUB\n", john.food);
	
	RUB family_total = alice.vtb.account_rub + john.vtb.account_rub + 
	(RUB)((alice.vtb.account_usd + john.vtb.account_usd) * alice.vtb.rate_usd_rub);
	print_family_total(family_total);
}


void print_results() {
	print_header("FINAL RESULTS");
	
	printf("\n--- ALICE ---\n");
	RUB alice_capital = alice.vtb.account_rub + 
	(RUB)(alice.vtb.account_usd * alice.vtb.rate_usd_rub) + 
	alice.car.value;
	print_amount("Total capital", alice_capital, "RUB");
	alice_total_money();
	print_amount("Credit debt", alice.credit.debt, "RUB");
	
	printf("\n--- JOHN ---\n");
	RUB john_capital = john.vtb.account_rub + 
	(RUB)(john.vtb.account_usd * john.vtb.rate_usd_rub) + 
	john.car.value;
	print_amount("Total capital", john_capital, "RUB");
	john_total_money();
	print_amount("Credit debt", john.credit.debt, "RUB");
	
	printf("\n=== FAMILY SUMMARY ===\n");
	print_amount("COMBINED CAPITAL", alice_capital + john_capital, "RUB");
	print_amount("Combined credit debt", alice.credit.debt + john.credit.debt, "RUB");
	
	if (alice_capital > john_capital) {
		printf("\n ALICE has more capital!\n");
	} else if (john_capital > alice_capital) {
		printf("\n JOHN has more capital!\n");
	} else {
		printf("\n They have equal capital!\n");
	}
}


void simulation() {
	year = 2026;
	month = 2;
	
	print_header("INITIAL DATA");
	printf("\n--- ALICE ---\n");
	print_amount("Annual salary", alice.salary * 12, "RUB");
	print_amount("Initial account", alice.vtb.account_rub, "RUB");
	printf("  USD: %lld USD\n", alice.vtb.account_usd);
	print_amount("Initial debt", alice.credit.debt, "RUB");
	
	printf("\n--- JOHN (breadwinner) ---\n");
	print_amount("Annual salary", john.salary * 12, "RUB");
	print_amount("Monthly salary", john.salary, "RUB");
	print_amount("Initial account", john.vtb.account_rub, "RUB");
	printf("  USD: %lld USD\n", john.vtb.account_usd);
	print_amount("Initial debt", john.credit.debt, "RUB");
	
	print_header("STARTING SIMULATION");
	show_monthly_stats(month, year);
	
	int months_passed = 0;
	
	while (!(year == 2029 && month == 2)) {
		printf("\n========== PROCESSING MONTH %d/%d ==========\n", month, year);
		
		family_utilities(month, year);
		
		process_all_holidays(month, year);
		process_all_charity(month, year);
		
		// Здоровье и медицина
		family_health_and_medicine(month, year);
		
		// Накопления и финансовые цели
		family_savings_goals(month, year);
		
		// Спорт и фитнес
		family_sports(month, year);
		
		print_subheader("ALICE'S OPERATIONS");
		alice_credit(year, month);
		alice_salary(month, year);
		alice_car();
		alice_food(month, year);
		alice_early_credit_payment();
		alice_invest();
		alice_car_transaction(month, year);
		
		print_subheader("JOHN'S OPERATIONS");
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
	
	print_header("SIMULATION COMPLETE");
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
