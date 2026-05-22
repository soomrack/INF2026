#include <stdio.h>
#include <math.h>      
#include <stdlib.h>    
#include <time.h>  
#include <string>


using Percent = float;
using RUB = long long int;
using USD = long long int;



struct Cat {
	RUB food;         
	RUB vet;           
	RUB toys;          
};



struct Car {
	RUB value;         
	RUB gas;          
	RUB maintenance;   
	RUB insurance;    
	RUB repair;        
	int year;          
	int mileage;      
};



struct Bank {
	RUB account_rub;  
	USD account_usd;   
	float rate_usd_rub;
	
	
	RUB credit_amount; 
	RUB credit_monthly_payment; 
	RUB credit_total_paid; 
	Percent credit_rate; 
	int credit_months_remaining; 
};



struct Deposit {
	RUB amount;        
	Percent rate;      
	bool is_active;    
	int months_remaining; 
	RUB monthly_income; 
};



struct Apartment {
	RUB cost;          
	RUB monthly_maintenance; 
	bool is_owned;     
	bool is_mortgage;  
	RUB rent_income;   
	RUB rent_expense;  
	RUB square_meters; 
	int rooms;         
};



struct Insurance {
	RUB life_insurance;        
	RUB health_insurance;       
	RUB property_insurance;     
	RUB car_insurance;          
	bool has_life;              
	bool has_health;            
	bool has_property;          
	bool has_car;              
};



struct Investment {
	RUB stocks;                 
	RUB bonds;                  
	RUB etf;                    
	RUB crypto;                 
	Percent stocks_growth;      
	Percent bonds_growth;       
	Percent etf_growth;         
	Percent crypto_volatility;  
};



struct Education {
	RUB courses;                
	RUB books;                  
	RUB seminars;              
	bool is_studying;           
	int study_months_left;      
	RUB study_cost;             
};



struct Health {
	RUB gym;                    
	RUB medicines;              
	RUB doctor;                
	bool has_chronic;           
	RUB chronic_cost;           
};



struct Subscription {
	RUB streaming;              
	RUB music;                  
	RUB cloud;                  
	RUB software;               
	RUB other;                 
};



struct Travel {
	RUB vacation_budget;        
	RUB weekend_trips;          
	bool planned_vacation;      
	int vacation_month;        
};



struct Tax {
	RUB income_tax;             
	RUB property_tax;           
	RUB transport_tax;          
	bool pay_property_tax;      
	bool pay_transport_tax;     
};



struct Pension {
	RUB private_pension;        
	RUB state_pension;          
	bool has_private;           
};



struct Charity {
	RUB monthly;                
	RUB one_time;               
	bool active;                
};



struct OtherDebt {
	RUB amount;                 
	RUB monthly_payment;       
	Percent rate;              
	int months_left;           
};



struct Gifts {
	RUB birthday;               
	RUB holidays;              
	RUB other;                  
};



struct Pets {
	Cat cat;                   
	bool has_dog;              
	RUB dog_food;              
	RUB dog_vet;                
	RUB dog_toys;             
};



struct Person {
	Bank vtb;          
	Deposit deposit;   
	RUB salary;        
	RUB food;          
	RUB utilities;     
	RUB entertainment; 
	RUB clothes;       
	RUB health;        
	RUB education;     
	RUB transport;     
	RUB internet;      
	
	
	Cat cat;           
	Car car;           
	Apartment apartment; 
	
	
	RUB savings_goal;  
	RUB emergency_fund;
	
	
	bool has_credit_card; 
	RUB credit_card_limit; 
	RUB credit_card_debt; 
	
	
	int age;           
	int work_experience; 
	std::string name;     
	
	
	Insurance insurance;          
	Investment investment;       
	Education education_info;     
	Health health_info;           
	Subscription subscriptions;  
	Travel travel;                
	Tax tax;                      
	Pension pension;              
	Charity charity;              
	OtherDebt other_debt;         
	Gifts gifts;                  
	Pets pets;                  
};



struct Person alice;
struct Person bob;


RUB random_range(RUB min, RUB max) {
	return min + rand() % (max - min + 1);
}



void alice_update_exchange_rate() {
	
	float change = (rand() % 100 - 50) / 1000.0; 
	alice.vtb.rate_usd_rub *= (1.0 + change);    
	
	if (alice.vtb.rate_usd_rub < 50.0) alice.vtb.rate_usd_rub = 50.0;
	if (alice.vtb.rate_usd_rub > 150.0) alice.vtb.rate_usd_rub = 150.0;
}



void bob_update_exchange_rate() {
	
	float change = (rand() % 100 - 50) / 1000.0;
	bob.vtb.rate_usd_rub *= (1.0 + change);
	
	if (bob.vtb.rate_usd_rub < 50.0) bob.vtb.rate_usd_rub = 50.0;
	if (bob.vtb.rate_usd_rub > 150.0) bob.vtb.rate_usd_rub = 150.0;
}



void alice_init() {
	
	alice.name = "Alice";
	alice.age = 28;
	alice.work_experience = 5;
	
	
	alice.vtb.rate_usd_rub = 78.76;
	alice.vtb.account_rub = 50'000;  
	alice.vtb.account_usd = 1'000;
	
	
	alice.vtb.credit_amount = 5'000'000;  
	alice.vtb.credit_rate = 18.0;  
	alice.vtb.credit_months_remaining = 240;  
	alice.vtb.credit_total_paid = 0;
	
	
	
	alice.salary = 180'000;
	
	
	alice.food = 25'000;  
	alice.utilities = 8'000;  
	alice.entertainment = 10'000;  
	alice.clothes = 5'000;  
	alice.health = 3'000;  
	alice.education = 0; 
	alice.transport = 3'000;  
	alice.internet = 1'500;  
	
	
	alice.cat.food = 2'500;
	alice.cat.vet = 1'000;  
	alice.cat.toys = 500;
	
	
	
	alice.car.value = 2'400'000;
	alice.car.gas = 12'000;
	alice.car.maintenance = 3'000;  
	alice.car.insurance = 8'000;  
	alice.car.repair = 0;  
	alice.car.year = 2022;
	alice.car.mileage = 30'000;
	
	
	
	alice.apartment.cost = 8'000'000;  
	alice.apartment.monthly_maintenance = 5'000;  
	alice.apartment.is_owned = false;  
	alice.apartment.is_mortgage = true;
	alice.apartment.square_meters = 45;
	alice.apartment.rooms = 2;
	
	
	
	alice.savings_goal = 1'000'000;  
	alice.emergency_fund = 0;  
	
	
	alice.has_credit_card = true;
	alice.credit_card_limit = 300'000;
	alice.credit_card_debt = 0;
	
	
	alice.insurance.life_insurance = 3'000;      
	alice.insurance.health_insurance = 2'000;    
	alice.insurance.property_insurance = 1'500;  
	alice.insurance.car_insurance = 8'000;       
	alice.insurance.has_life = true;
	alice.insurance.has_health = true;
	alice.insurance.has_property = true;
	alice.insurance.has_car = true;
	
	
	alice.investment.stocks = 100'000;            
	alice.investment.bonds = 50'000;              
	alice.investment.etf = 30'000;               
	alice.investment.crypto = 10'000;             
	alice.investment.stocks_growth = 1.5;         
	alice.investment.bonds_growth = 0.8;          
	alice.investment.etf_growth = 1.2;           
	alice.investment.crypto_volatility = 10.0;    
	
	
	alice.education_info.courses = 2'000;         
	alice.education_info.books = 1'000;           
	alice.education_info.seminars = 0;            
	alice.education_info.is_studying = false;
	alice.education_info.study_months_left = 0;
	alice.education_info.study_cost = 0;
	
	
	alice.health_info.gym = 3'500;                 
	alice.health_info.medicines = 1'000;           
	alice.health_info.doctor = 500;                 
	alice.health_info.has_chronic = false;          
	alice.health_info.chronic_cost = 0;
	
	
	alice.subscriptions.streaming = 1'000;          
	alice.subscriptions.music = 500;                
	alice.subscriptions.cloud = 300;                
	alice.subscriptions.software = 0;                 
	alice.subscriptions.other = 200;                 
	
	
	alice.travel.vacation_budget = 100'000;          
	alice.travel.weekend_trips = 3'000;             
	alice.travel.planned_vacation = true;            
	alice.travel.vacation_month = 7;                  
	
	
	alice.tax.income_tax = 0;                         
	alice.tax.property_tax = 5'000;                   
	alice.tax.transport_tax = 3'000;                  
	alice.tax.pay_property_tax = true;
	alice.tax.pay_transport_tax = true;
	
	
	alice.pension.private_pension = 5'000;            
	alice.pension.state_pension = 0;                   
	alice.pension.has_private = true;
	
	
	alice.charity.monthly = 500;                       
	alice.charity.one_time = 0;                         
	alice.charity.active = true;
	
	
	alice.other_debt.amount = 0;
	alice.other_debt.monthly_payment = 0;
	alice.other_debt.rate = 0;
	alice.other_debt.months_left = 0;
	
	
	alice.gifts.birthday = 2'000;                      
	alice.gifts.holidays = 3'000;                     
	alice.gifts.other = 1'000;                         
	
	
	alice.pets.cat = alice.cat;                         
	alice.pets.has_dog = false;
	alice.pets.dog_food = 0;
	alice.pets.dog_vet = 0;
	alice.pets.dog_toys = 0;
}


void bob_init() {
	bob.name = "Bob";
	bob.age = 30;
	bob.work_experience = 7;
	
	
	bob.vtb.rate_usd_rub = 78.76;
	bob.vtb.account_rub = 300'000;  
	bob.vtb.account_usd = 2'000;
	
	
	
	bob.deposit.amount = 200'000;  
	bob.deposit.rate = 16.0;  
	bob.deposit.is_active = true;
	bob.deposit.months_remaining = 12;  
	bob.deposit.monthly_income = 0;  
	
	
	bob.salary = 220'000;  
	
	
	bob.food = 20'000;
	bob.utilities = 7'000;
	bob.entertainment = 15'000;  
	bob.clothes = 4'000;
	
	
	
	bob.health = 2'000;
	bob.education = 5'000;  
	bob.transport = 2'000;  
	bob.internet = 2'000;
	
	
	
	bob.cat.food = 0;
	bob.cat.vet = 0;
	bob.cat.toys = 0;
	
	
	
	bob.car.value = 0;
	bob.car.gas = 0;
	bob.car.maintenance = 0;
	bob.car.insurance = 0;
	bob.car.year = 0;
	bob.car.mileage = 0;
	
	
	
	bob.apartment.rent_expense = 30'000;  
	bob.apartment.monthly_maintenance = 0;  
	bob.apartment.is_owned = false;
	bob.apartment.is_mortgage = false;
	bob.apartment.square_meters = 40;
	bob.apartment.rooms = 1;
	
	
	
	bob.savings_goal = 2'000'000;  
	bob.emergency_fund = 100'000;  
	
	
	bob.has_credit_card = true;
	bob.credit_card_limit = 200'000;
	bob.credit_card_debt = 0;
	
	
	
	bob.insurance.life_insurance = 0;
	bob.insurance.health_insurance = 1'500;    
	bob.insurance.property_insurance = 0;
	bob.insurance.car_insurance = 0;
	bob.insurance.has_life = false;
	bob.insurance.has_health = true;
	bob.insurance.has_property = false;
	bob.insurance.has_car = false;
	
	
	
	bob.investment.stocks = 0;
	bob.investment.bonds = 100'000;
	bob.investment.etf = 0;
	bob.investment.crypto = 0;
	bob.investment.stocks_growth = 0;
	bob.investment.bonds_growth = 0.8;
	bob.investment.etf_growth = 0;
	bob.investment.crypto_volatility = 0;
	
	
	
	bob.education_info.courses = 5'000;         
	bob.education_info.books = 2'000;
	bob.education_info.seminars = 10'000;       
	bob.education_info.is_studying = true;
	bob.education_info.study_months_left = 6;   
	bob.education_info.study_cost = 15'000;      
	
	
	
	bob.health_info.gym = 0;
	bob.health_info.medicines = 500;
	bob.health_info.doctor = 200;
	bob.health_info.has_chronic = true;         
	bob.health_info.chronic_cost = 1'000;       
	
	
	
	bob.subscriptions.streaming = 0;
	bob.subscriptions.music = 300;
	bob.subscriptions.cloud = 0;
	bob.subscriptions.software = 0;
	bob.subscriptions.other = 0;
	
	
	
	bob.travel.vacation_budget = 0;
	bob.travel.weekend_trips = 0;
	bob.travel.planned_vacation = false;
	bob.travel.vacation_month = 0;
	
	
	
	bob.tax.income_tax = 0;
	bob.tax.property_tax = 0;
	bob.tax.transport_tax = 0;
	bob.tax.pay_property_tax = false;
	bob.tax.pay_transport_tax = false;
	
	
	
	bob.pension.private_pension = 0;
	bob.pension.state_pension = 0;
	bob.pension.has_private = false;
	
	
	bob.charity.monthly = 0;
	bob.charity.one_time = 0;
	bob.charity.active = false;
	
	
	bob.other_debt.amount = 50'000;
	bob.other_debt.monthly_payment = 5'000;
	bob.other_debt.rate = 12.0;
	bob.other_debt.months_left = 10;
	
	
	bob.gifts.birthday = 1'000;
	bob.gifts.holidays = 2'000;
	bob.gifts.other = 500;
	
	
	bob.pets.cat = bob.cat;   
	bob.pets.has_dog = false;
	bob.pets.dog_food = 0;
	bob.pets.dog_vet = 0;
	bob.pets.dog_toys = 0;
}



void alice_calculate_deposit_income() {
	
	if (!alice.deposit.is_active) return;
	
	alice.deposit.monthly_income = alice.deposit.amount * (alice.deposit.rate / 100.0 / 12.0);
	
	alice.deposit.amount += alice.deposit.monthly_income;
	
	alice.deposit.months_remaining--;
	
	if (alice.deposit.months_remaining <= 0) {
		alice.deposit.months_remaining = 12;  
		alice.deposit.rate = 15.0 + (rand() % 3); 
	}
}



void bob_calculate_deposit_income() {
	if (!bob.deposit.is_active) return;
	
	bob.deposit.monthly_income = bob.deposit.amount * (bob.deposit.rate / 100.0 / 12.0);
	bob.deposit.amount += bob.deposit.monthly_income;
	bob.deposit.months_remaining--;
	
	if (bob.deposit.months_remaining <= 0) {
		bob.deposit.months_remaining = 12;
		bob.deposit.rate = 15.0 + (rand() % 3);
	}
}



void alice_pay_mortgage() {
	
	if (alice.vtb.credit_months_remaining <= 0) return;  
	
	if (alice.vtb.account_rub >= alice.vtb.credit_monthly_payment) {
		// Списываем платеж
		alice.vtb.account_rub -= alice.vtb.credit_monthly_payment;
		alice.vtb.credit_total_paid += alice.vtb.credit_monthly_payment;
		alice.vtb.credit_months_remaining--;
		
		if (alice.vtb.credit_months_remaining == 0) {
			alice.apartment.is_owned = true;
			alice.apartment.is_mortgage = false;
			printf("    * Поздравляем, Алиса! Кредит на квартиру полностью выплачен! *\n");
		}
	} else {
		
		if (alice.has_credit_card && alice.credit_card_limit - alice.credit_card_debt >= alice.vtb.credit_monthly_payment) {
			alice.credit_card_debt += alice.vtb.credit_monthly_payment;
			alice.vtb.credit_total_paid += alice.vtb.credit_monthly_payment;
			alice.vtb.credit_months_remaining--;
			printf("    ВНИМАНИЕ, Алиса: Не хватает денег на ипотеку! Использована кредитная карта.\n");
		} else {
			
			printf("    * КРИТИЧНО, Алиса: ПРОСРОЧКА ПЛАТЕЖА ПО ИПОТЕКЕ! *\n");
			alice.vtb.credit_amount += alice.vtb.credit_amount * 0.01;  // Штраф 1%
			
			double monthly_rate = alice.vtb.credit_rate / 100.0 / 12.0;
			double power = pow(1.0 + monthly_rate, alice.vtb.credit_months_remaining);
			alice.vtb.credit_monthly_payment = alice.vtb.credit_amount * (monthly_rate * power) / (power - 1.0);
		}
	}
}



void bob_pay_mortgage() {
	return;
}



void alice_food(const int month, const int year) {
	
	if (month == 12) {
		alice.food += 5'000;  
		alice.vtb.account_rub -= 5'000;
	}
	if (month == 2) {  
		alice.food += 3'000;
		alice.vtb.account_rub -= 3'000;
	}
	
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
		case 2030: inflation = 10.0; break;
		case 2031: inflation = 9.5; break;
		default: inflation = 8.0; break;
	}
	alice.food += alice.food * (inflation / 100. / 12.);
	
	alice.vtb.account_rub -= alice.food;
}



void bob_food(const int month, const int year) {
	if (month == 12) {
		bob.food += 5'000;
		bob.vtb.account_rub -= 5'000;
	}
	if (month == 7) {  // День рождения Боба
		bob.food += 4'000;
		bob.vtb.account_rub -= 4'000;
	}
	
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
		case 2030: inflation = 10.0; break;
		case 2031: inflation = 9.5; break;
		default: inflation = 8.0; break;
	}
	bob.food += bob.food * (inflation / 100. / 12.);
	
	bob.vtb.account_rub -= bob.food;
}



void alice_cat(const int month, const int year) {
	
	if (alice.cat.food == 0 && alice.cat.vet == 0) return;
	
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 12.0; break;
		case 2029: inflation = 11.5; break;
		default: inflation = 10.0; break;
	}
	alice.cat.food += alice.cat.food * (inflation / 100. / 12.);
	
	if (month == 3 || month == 9) {
		alice.vtb.account_rub -= alice.cat.vet;
	}
	
	if (month == 12) {
		alice.vtb.account_rub -= alice.cat.toys * 2;
	}
	
	alice.vtb.account_rub -= alice.cat.food;
}



void bob_cat(const int month, const int year) {
	return;
}



void alice_car(const int month, const int year) {
	
	if (alice.car.value == 0) return;
	
	alice.vtb.account_rub -= alice.car.gas;
	
	if (month == 4 || month == 10) {
		alice.vtb.account_rub -= alice.car.maintenance;
	}
	
	if (month == 1) {
		alice.vtb.account_rub -= alice.car.insurance * 12;  // сразу за год
	}
	
	if (rand() % 100 < 5) { 
		RUB repair_cost = random_range(5'000, 50'000);
		alice.vtb.account_rub -= repair_cost;
		printf("    Алиса: неожиданный ремонт машины: %lld руб.\n", repair_cost);
	}
	
	alice.car.mileage += 1'500;  
	
	alice.car.value -= alice.car.value * 0.005;
}



void bob_car(const int month, const int year) {
	return;
}



void alice_salary(const int month, const int year) {
	
	if (month == 3) {
		alice.salary *= 1.5;
	}
	
	if (month == 1 && year > 2026) {
		Percent salary_increase = 8.0;  
		alice.salary += alice.salary * (salary_increase / 100.0);
	}
	
	if (month == 2 && year == 2026) {
		alice.vtb.account_rub += 5'000;
	}
	
	alice.vtb.account_rub += alice.salary;
}



void bob_salary(const int month, const int year) {
	
	if (month == 3) {
		bob.salary *= 1.5;
	}
	
	if (month == 1 && year > 2026) {
		Percent salary_increase = 8.0;
		bob.salary += bob.salary * (salary_increase / 100.0);
	}
	
	if (month == 11 && year == 2026) {
		bob.vtb.account_rub += 10'000; 
	}
	
	bob.vtb.account_rub += bob.salary;
}



void alice_apartment(const int month, const int year) {
	
	alice.vtb.account_rub -= alice.apartment.monthly_maintenance;
	
	if (!alice.apartment.is_owned && alice.apartment.rent_expense > 0) {
		alice.vtb.account_rub -= alice.apartment.rent_expense;
	}
	
	if (alice.apartment.is_owned && alice.apartment.rent_income > 0) {
		alice.vtb.account_rub += alice.apartment.rent_income;
	}
	
	if (rand() % 200 < 1) {  
		RUB repair_cost = random_range(10'000, 100'000);
		alice.vtb.account_rub -= repair_cost;
		printf("    Алиса: ремонт в квартире: %lld руб.\n", repair_cost);
	}
}



void bob_apartment(const int month, const int year) {
	
	bob.vtb.account_rub -= bob.apartment.monthly_maintenance; // обычно 0
	if (!bob.apartment.is_owned && bob.apartment.rent_expense > 0) {
		bob.vtb.account_rub -= bob.apartment.rent_expense;
	}
	
	if (rand() % 200 < 1) {
		RUB repair_cost = random_range(5'000, 30'000);
		bob.vtb.account_rub -= repair_cost;
		printf("    Боб: ремонт в арендованной квартире: %lld руб.\n", repair_cost);
	}
}



void alice_other_expenses(const int month, const int year) {
	
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
		case 2030: inflation = 10.0; break;
		case 2031: inflation = 9.5; break;
		default: inflation = 8.0; break;
	}
	
	// Развлечения
	alice.vtb.account_rub -= alice.entertainment * (inflation/100/12);
	
	// Одежда
	if (month == 4 || month == 9) {  
		alice.vtb.account_rub -= alice.clothes * 3 * (inflation/100/12);
	} else {
		alice.vtb.account_rub -= alice.clothes * (inflation/100/12);
	}
	
	// Здоровье
	alice.vtb.account_rub -= alice.health * (inflation/100/12);
	
	// Образование
	if (alice.education > 0) {
		if (month == 9) {  
			alice.vtb.account_rub -= alice.education * 12;
		}
	}
	
	// Транспорт
	alice.vtb.account_rub -= alice.transport * (inflation/100/12);
	
	// Интернет
	alice.vtb.account_rub -= alice.internet * (inflation/100/12);
	
	// Отпуск в июле
	if (month == 7) {
		RUB vacation_cost = random_range(50'000, 150'000);
		alice.vtb.account_rub -= vacation_cost;
		printf("    Алиса: отпуск: %lld руб.\n", vacation_cost);
	}
	
	// Подарки на Новый год
	if (month == 12) {
		RUB gifts_cost = random_range(10'000, 30'000);
		alice.vtb.account_rub -= gifts_cost * (inflation/100/12);
	}
}



void bob_other_expenses(const int month, const int year) {
	
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
		case 2030: inflation = 10.0; break;
		case 2031: inflation = 9.5; break;
		default: inflation = 8.0; break;
	}
	
	// Развлечения
	bob.vtb.account_rub -= bob.entertainment * (inflation/100/12);
	
	// Одежда
	if (month == 4 || month == 9) {
		bob.vtb.account_rub -= bob.clothes * 3 * (inflation/100/12);
	} else {
		bob.vtb.account_rub -= bob.clothes * (inflation/100/12);
	}
	
	// Здоровье
	bob.vtb.account_rub -= bob.health * (inflation/100/12);
	
	// Образование
	if (bob.education > 0) {
		if (month == 9) {
			bob.vtb.account_rub -= bob.education * 12;
		}
	}
	
	// Транспорт
	bob.vtb.account_rub -= bob.transport * (inflation/100/12);
	
	// Интернет
	bob.vtb.account_rub -= bob.internet * (inflation/100/12);
	
	// Отпуск в июне
	if (month == 6) {
		RUB vacation_cost = random_range(20'000, 80'000);
		bob.vtb.account_rub -= vacation_cost;
		printf("    Боб: отпуск: %lld руб.\n", vacation_cost);
	}
	
	// Подарки на Новый год
	if (month == 12) {
		RUB gifts_cost = random_range(5'000, 15'000);
		bob.vtb.account_rub -= gifts_cost * (inflation/100/12);
	}
}



void alice_random_financial_events(const int month, const int year) {
	
	int event = rand() % 1000;
	
	if (event < 10) {  // 1% - выигрыш в лотерею
		RUB win = random_range(1'000, 50'000);
		alice.vtb.account_rub += win;
		printf("    Алиса: удача! Выигрыш в лотерею: %lld руб.\n", win);
	}
	else if (event < 20) {  // 1% - штраф
		RUB fine = random_range(500, 5'000);
		alice.vtb.account_rub -= fine;
		printf("    Алиса: штраф: %lld руб.\n", fine);
	}
	else if (event < 30) {  // 1% - нашли деньги
		RUB found = random_range(100, 10'000);
		alice.vtb.account_rub += found;
		printf("    Алиса: нашли деньги: %lld руб.\n", found);
	}
	else if (event < 40) {  // 1% - потеряли деньги
		RUB lost = random_range(100, 5'000);
		alice.vtb.account_rub -= lost;
		printf("    Алиса: потеряли деньги: %lld руб.\n", lost);
	}
	else if (event < 45) {  // 0.5% - премия на работе
		RUB bonus = random_range(10'000, 100'000);
		alice.vtb.account_rub += bonus;
		printf("    Алиса: неожиданная премия на работе: %lld руб.\n", bonus);
	}
	else if (event < 48) {  // 0.3% - поломка техники
		RUB breakdown = random_range(10'000, 40'000);
		alice.vtb.account_rub -= breakdown;
		printf("    Алиса: поломка техники: %lld руб.\n", breakdown);
	}
}



void bob_random_financial_events(const int month, const int year) {
	
	int event = rand() % 1000;
	
	if (event < 10) { // 1% - выигрыш в лотерею
		RUB win = random_range(1'000, 50'000);
		bob.vtb.account_rub += win;
		printf("    Боб: выигрыш в лотерею: %lld руб.\n", win);
	}
	else if (event < 20) { // 1% - штраф
		RUB fine = random_range(500, 5'000);
		bob.vtb.account_rub -= fine;
		printf("    Боб: штраф: %lld руб.\n", fine);
	}
	else if (event < 30) {  // 1% - нашли деньги
		RUB found = random_range(100, 10'000);
		bob.vtb.account_rub += found;
		printf("    Боб: нашли деньги: %lld руб.\n", found);
	}
	else if (event < 40) {   // 1% - потеряли деньги
		RUB lost = random_range(100, 5'000);
		bob.vtb.account_rub -= lost;
		printf("    Боб: потеряли деньги: %lld руб.\n", lost);
	}
	else if (event < 45) {  // 0.5% - премия на работе
		RUB bonus = random_range(10'000, 100'000);
		bob.vtb.account_rub += bonus;
		printf("    Боб: неожиданная премия: %lld руб.\n", bonus);
	}
	else if (event < 48) {  // 0.3% - поломка техники
		RUB breakdown = random_range(10'000, 40'000);
		bob.vtb.account_rub -= breakdown;
		printf("    Боб: поломка техники: %lld руб.\n", breakdown);
	}
}



void alice_manage_emergency_fund() {
	
	RUB monthly_expenses = alice.food + alice.utilities + alice.entertainment + 
	alice.clothes + alice.health + alice.transport + 
	alice.internet + alice.cat.food + alice.car.gas;
	
	RUB target_emergency_fund = monthly_expenses * 6;
	
	if (alice.vtb.account_rub > target_emergency_fund + 100'000) {
		RUB excess = alice.vtb.account_rub - target_emergency_fund;
		RUB transfer = excess * 0.5;  // половину излишка
		alice.vtb.account_rub -= transfer;
		alice.emergency_fund += transfer;
	}
	
	
	if (alice.emergency_fund > target_emergency_fund * 1.2) {
		RUB excess = alice.emergency_fund - target_emergency_fund;
		alice.emergency_fund -= excess;
		alice.vtb.account_rub += excess;
	}
	
	
	if (alice.vtb.account_rub < monthly_expenses && alice.emergency_fund > 0) {
		RUB needed = monthly_expenses - alice.vtb.account_rub;
		RUB take = (needed < alice.emergency_fund) ? needed : alice.emergency_fund;
		alice.emergency_fund -= take;
		alice.vtb.account_rub += take;
		printf("    Алиса: использована подушка безопасности: %lld руб. Остаток: %lld\n", take, alice.emergency_fund);
	}
}



void bob_manage_emergency_fund() {
	
	RUB monthly_expenses = bob.food + bob.utilities + bob.entertainment + 
	bob.clothes + bob.health + bob.transport + 
	bob.internet + bob.cat.food + bob.car.gas;
	RUB target_emergency_fund = monthly_expenses * 6;
	
	if (bob.vtb.account_rub > target_emergency_fund + 100'000) {
		RUB excess = bob.vtb.account_rub - target_emergency_fund;
		RUB transfer = excess * 0.5;
		bob.vtb.account_rub -= transfer;
		bob.emergency_fund += transfer;
	}
	
	if (bob.emergency_fund > target_emergency_fund * 1.2) {
		RUB excess = bob.emergency_fund - target_emergency_fund;
		bob.emergency_fund -= excess;
		bob.vtb.account_rub += excess;
	}
	
	if (bob.vtb.account_rub < monthly_expenses && bob.emergency_fund > 0) {
		RUB needed = monthly_expenses - bob.vtb.account_rub;
		RUB take = (needed < bob.emergency_fund) ? needed : bob.emergency_fund;
		bob.emergency_fund -= take;
		bob.vtb.account_rub += take;
		printf("    Боб: использована подушка безопасности: %lld руб. Остаток: %lld\n", take, bob.emergency_fund);
	}
}



void alice_manage_credit_card() {
	if (!alice.has_credit_card) return;
	
	
	if (alice.credit_card_debt > 0) {
		
		RUB min_payment = alice.credit_card_debt * 0.05;
		if (min_payment < 1'000) min_payment = alice.credit_card_debt;
		
		if (alice.vtb.account_rub > min_payment + 10'000) {
			RUB payment = (alice.vtb.account_rub - 10'000 > alice.credit_card_debt) ? 
			alice.credit_card_debt : (alice.vtb.account_rub - 10'000);
			alice.vtb.account_rub -= payment;
			alice.credit_card_debt -= payment;
			printf("    Алиса: погашен долг по кредитной карте: %lld руб. Остаток долга: %lld\n", 
				   payment, alice.credit_card_debt);
		}
	}
}



void bob_manage_credit_card() {
	
	if (!bob.has_credit_card) return;
	
	if (bob.credit_card_debt > 0) {
		RUB min_payment = bob.credit_card_debt * 0.05;
		if (min_payment < 1'000) min_payment = bob.credit_card_debt;
		
		if (bob.vtb.account_rub > min_payment + 10'000) {
			RUB payment = (bob.vtb.account_rub - 10'000 > bob.credit_card_debt) ? 
			bob.credit_card_debt : (bob.vtb.account_rub - 10'000);
			bob.vtb.account_rub -= payment;
			bob.credit_card_debt -= payment;
			printf("    Боб: погашен долг по кредитной карте: %lld руб. Остаток долга: %lld\n", 
				   payment, bob.credit_card_debt);
		}
	}
}



void alice_invest_in_currency(const int month) {
	
	if (month % 3 == 0 && alice.vtb.account_rub > 100'000) {
		RUB to_invest = alice.vtb.account_rub * 0.2;  
		if (to_invest > 200'000) to_invest = 200'000;  
		
		USD dollars_to_buy = to_invest / alice.vtb.rate_usd_rub;
		alice.vtb.account_rub -= to_invest;
		alice.vtb.account_usd += dollars_to_buy;
		printf("    Алиса: инвестиция: куплено %lld долларов по курсу %.2f\n", 
			   dollars_to_buy, alice.vtb.rate_usd_rub);
	}
}



void bob_invest_in_currency(const int month) {
	
	if (month % 3 == 0 && bob.vtb.account_rub > 100'000) {
		RUB to_invest = bob.vtb.account_rub * 0.2;
		if (to_invest > 200'000) to_invest = 200'000;
		
		USD dollars_to_buy = to_invest / bob.vtb.rate_usd_rub;
		bob.vtb.account_rub -= to_invest;
		bob.vtb.account_usd += dollars_to_buy;
		printf("    Боб: инвестиция: куплено %lld долларов по курсу %.2f\n", 
			   dollars_to_buy, bob.vtb.rate_usd_rub);
	}
}



void handle_yearly_events(Person *alice, Person *bob, int year) {
	
	switch (year) {
	case 2030:
		printf("\n* 2030 год - кризис! Курс доллара скачет *\n");
		alice->vtb.rate_usd_rub *= 1.5;
		bob->vtb.rate_usd_rub *= 1.5;
		break;
		
	case 2035:
		printf("\n* 2035 год - Алиса получила повышение! *\n");
		alice->salary += 50'000;
		break;
		
	case 2040:
		printf("\n* 2040 год - Боб получил наследство! *\n");
		bob->vtb.account_rub += 500'000;
		break;
		
	default:
		break;
	}
}



void alice_handle_insurance(const int month) {
	
	if (alice.insurance.has_life) {
		alice.vtb.account_rub -= alice.insurance.life_insurance;
	}
	
	if (alice.insurance.has_health) {
		alice.vtb.account_rub -= alice.insurance.health_insurance;
	}
	
	if (alice.insurance.has_property) {
		alice.vtb.account_rub -= alice.insurance.property_insurance;
	}
	
	if (alice.insurance.has_car && month == 1) {
		
		alice.vtb.account_rub -= alice.insurance.car_insurance * 12;
	}
}



void bob_handle_insurance(const int month) {
	if (bob.insurance.has_life) {
		bob.vtb.account_rub -= bob.insurance.life_insurance;
	}
	if (bob.insurance.has_health) {
		bob.vtb.account_rub -= bob.insurance.health_insurance;
	}
	if (bob.insurance.has_property) {
		bob.vtb.account_rub -= bob.insurance.property_insurance;
	}
	if (bob.insurance.has_car && month == 1) {
		bob.vtb.account_rub -= bob.insurance.car_insurance * 12;
	}
}



void alice_handle_investments() {
	
	float stocks_change = (rand() % 200 - 100) / 100.0; // -1.0 .. 1.0
	alice.investment.stocks += alice.investment.stocks * (alice.investment.stocks_growth / 100.0 + stocks_change / 100.0);
	if (alice.investment.stocks < 0) alice.investment.stocks = 0;
	
	float bonds_change = (rand() % 100 - 50) / 100.0; // -0.5 .. 0.5
	alice.investment.bonds += alice.investment.bonds * (alice.investment.bonds_growth / 100.0 + bonds_change / 100.0);
	if (alice.investment.bonds < 0) alice.investment.bonds = 0;
	
	float etf_change = (rand() % 150 - 75) / 100.0; // -0.75 .. 0.75
	alice.investment.etf += alice.investment.etf * (alice.investment.etf_growth / 100.0 + etf_change / 100.0);
	if (alice.investment.etf < 0) alice.investment.etf = 0;
	
	float crypto_change = (rand() % 2000 - 1000) / 100.0; // -10.0 .. 10.0
	alice.investment.crypto += alice.investment.crypto * (crypto_change / 100.0);
	if (alice.investment.crypto < 0) alice.investment.crypto = 0;
}



void bob_handle_investments() {
	
	float bonds_change = (rand() % 100 - 50) / 100.0;
	bob.investment.bonds += bob.investment.bonds * (bob.investment.bonds_growth / 100.0 + bonds_change / 100.0);
	if (bob.investment.bonds < 0) bob.investment.bonds = 0;
}



void alice_handle_education(const int month) {
	
	alice.vtb.account_rub -= alice.education_info.courses;
	alice.vtb.account_rub -= alice.education_info.books;
	
	
	if (rand() % 12 == 0) { // примерно раз в год
		alice.vtb.account_rub -= alice.education_info.seminars;
		printf("    Алиса: оплата семинара: %lld руб.\n", alice.education_info.seminars);
	}
	
	
	if (alice.education_info.is_studying) {
		alice.vtb.account_rub -= alice.education_info.study_cost;
		alice.education_info.study_months_left--;
		if (alice.education_info.study_months_left <= 0) {
			alice.education_info.is_studying = false;
			printf("    Алиса: обучение завершено!\n");
		}
	}
}



void bob_handle_education(const int month) {
	
	bob.vtb.account_rub -= bob.education_info.courses;
	bob.vtb.account_rub -= bob.education_info.books;
	
	
	if (rand() % 12 == 0) { // примерно раз в год
		bob.vtb.account_rub -= bob.education_info.seminars;
		printf("    Боб: оплата семинара: %lld руб.\n", bob.education_info.seminars);
	}
	
	
	if (bob.education_info.is_studying) {
		bob.vtb.account_rub -= bob.education_info.study_cost;
		bob.education_info.study_months_left--;
		if (bob.education_info.study_months_left <= 0) {
			bob.education_info.is_studying = false;
			printf("    Боб: обучение завершено!\n");
		}
	}
}



void alice_handle_health(const int month, const int year) {
	
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
		case 2030: inflation = 10.0; break;
		case 2031: inflation = 9.5; break;
		default: inflation = 8.0; break;
	}
	
	// Спортзал
	alice.vtb.account_rub -= alice.health_info.gym * (inflation/100/12);
	
	// Лекарства
	alice.vtb.account_rub -= alice.health_info.medicines * (inflation/100/12);
	
	// Платные врачи
	alice.vtb.account_rub -= alice.health_info.doctor * (inflation/100/12);
	
	// Хронические болезни
	if (alice.health_info.has_chronic) {
		alice.vtb.account_rub -= alice.health_info.chronic_cost * (inflation/100/12);
	}
}



void bob_handle_health(const int month, const int year) {
	
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
		case 2030: inflation = 10.0; break;
		case 2031: inflation = 9.5; break;
		default: inflation = 8.0; break;
	}	
	
	// Спортзал
	bob.vtb.account_rub -= bob.health_info.gym * (inflation/100/12);
	
	// Лекарства
	bob.vtb.account_rub -= bob.health_info.medicines * (inflation/100/12);
	
	// Платные врачи
	bob.vtb.account_rub -= bob.health_info.doctor * (inflation/100/12);
	
	// Хронические болезни
	if (bob.health_info.has_chronic) {
		bob.vtb.account_rub -= bob.health_info.chronic_cost * (inflation/100/12);
	}
}



void alice_handle_subscriptions() {
	
	alice.vtb.account_rub -= alice.subscriptions.streaming;
	alice.vtb.account_rub -= alice.subscriptions.music;
	alice.vtb.account_rub -= alice.subscriptions.cloud;
	alice.vtb.account_rub -= alice.subscriptions.software;
	alice.vtb.account_rub -= alice.subscriptions.other;
}



void bob_handle_subscriptions() {
	
	bob.vtb.account_rub -= bob.subscriptions.streaming;
	bob.vtb.account_rub -= bob.subscriptions.music;
	bob.vtb.account_rub -= bob.subscriptions.cloud;
	bob.vtb.account_rub -= bob.subscriptions.software;
	bob.vtb.account_rub -= bob.subscriptions.other;
}



void alice_handle_travel(const int month) {
	
	alice.vtb.account_rub -= alice.travel.weekend_trips;
	
	if (alice.travel.planned_vacation && month == alice.travel.vacation_month) {
		alice.vtb.account_rub -= alice.travel.vacation_budget;
		printf("    Алиса: отпуск (бюджет) %lld руб.\n", alice.travel.vacation_budget);
	}
}



void bob_handle_travel(const int month) {
	
	bob.vtb.account_rub -= bob.travel.weekend_trips;
	
	if (bob.travel.planned_vacation && month == bob.travel.vacation_month) {
		bob.vtb.account_rub -= bob.travel.vacation_budget;
		printf("    Боб: отпуск %lld руб.\n", bob.travel.vacation_budget);
	}
}



void alice_handle_tax(const int month, const int year) {
	
	if (month == 11) { 
		if (alice.tax.pay_property_tax) {
			alice.vtb.account_rub -= alice.tax.property_tax;
			printf("    Алиса: уплачен налог на имущество: %lld руб.\n", alice.tax.property_tax);
		}
		if (alice.tax.pay_transport_tax) {
			alice.vtb.account_rub -= alice.tax.transport_tax;
			printf("    Алиса: уплачен транспортный налог: %lld руб.\n", alice.tax.transport_tax);
		}
	}
}



void bob_handle_tax(const int month, const int year) {
	
	if (month == 11) {
		if (bob.tax.pay_property_tax) {
			bob.vtb.account_rub -= bob.tax.property_tax;
		}
		if (bob.tax.pay_transport_tax) {
			bob.vtb.account_rub -= bob.tax.transport_tax;
		}
	}
}



void alice_handle_pension() {
	
	if (alice.pension.has_private) {
		alice.vtb.account_rub -= alice.pension.private_pension;
	}
}



void bob_handle_pension() {
	
	if (bob.pension.has_private) {
		bob.vtb.account_rub -= bob.pension.private_pension;
	}
}



void alice_handle_charity() {
	
	if (alice.charity.active) {
		alice.vtb.account_rub -= alice.charity.monthly;
	}
	
	if (rand() % 24 == 0) { // раз в 2 года
		alice.vtb.account_rub -= alice.charity.one_time;
		printf("    Алиса: разовое пожертвование: %lld руб.\n", alice.charity.one_time);
	}
}



void bob_handle_charity() {
	
	if (bob.charity.active) {
		bob.vtb.account_rub -= bob.charity.monthly;
	}
	if (rand() % 24 == 0) {
		bob.vtb.account_rub -= bob.charity.one_time;
	}
}



void alice_handle_other_debt() {
	
	if (alice.other_debt.amount > 0) {
		alice.vtb.account_rub -= alice.other_debt.monthly_payment;
		alice.other_debt.amount -= alice.other_debt.monthly_payment;
		alice.other_debt.months_left--;
		if (alice.other_debt.months_left <= 0) {
			alice.other_debt.amount = 0;
			printf("    Алиса: прочий долг полностью погашен!\n");
		}
	}
}



void bob_handle_other_debt() {
	
	if (bob.other_debt.amount > 0) {
		bob.vtb.account_rub -= bob.other_debt.monthly_payment;
		bob.other_debt.amount -= bob.other_debt.monthly_payment;
		bob.other_debt.months_left--;
		if (bob.other_debt.months_left <= 0) {
			bob.other_debt.amount = 0;
			printf("    Боб: потребительский кредит полностью погашен!\n");
		}
	}
}



void alice_handle_gifts(const int month) {
	
	alice.vtb.account_rub -= alice.gifts.birthday;
	
	alice.vtb.account_rub -= alice.gifts.holidays;
	
	alice.vtb.account_rub -= alice.gifts.other;
}



void bob_handle_gifts(const int month) {
	
	bob.vtb.account_rub -= bob.gifts.birthday;
	
	bob.vtb.account_rub -= bob.gifts.holidays;
	
	bob.vtb.account_rub -= bob.gifts.other;
}



void alice_handle_pets(const int month, const int year) {  
	
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
		case 2030: inflation = 10.0; break;
		case 2031: inflation = 9.5; break;
		default: inflation = 8.0; break;
	}	
	
	if (alice.pets.has_dog) {
		alice.vtb.account_rub -= alice.pets.dog_food * (inflation/100/12);
		alice.vtb.account_rub -= alice.pets.dog_vet * (inflation/100/12);
		alice.vtb.account_rub -= alice.pets.dog_toys * (inflation/100/12);
	}
	alice_cat(month, 2026); 
}



void bob_handle_pets(const int month, const int year) {
	
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
		case 2030: inflation = 10.0; break;
		case 2031: inflation = 9.5; break;
		default: inflation = 8.0; break;
	}	
	
	if (bob.pets.has_dog) {
		bob.vtb.account_rub -= bob.pets.dog_food * (inflation/100/12);
		bob.vtb.account_rub -= bob.pets.dog_vet * (inflation/100/12);
		bob.vtb.account_rub -= bob.pets.dog_toys * (inflation/100/12);
	}
	bob_cat(month, 2026);
}



void print_monthly_report(const int year, const int month, Person* p1, Person* p2) {
	
	printf("\n========================================\n");
	printf("ОТЧЕТ ЗА %d.%d\n", month, year);
	printf("========================================\n");
	
	
	// Отчет по Алисе
	printf("\n--- %s ---\n", p1->name.c_str());
	printf("  Счет (рубли): %'lld руб.\n", p1->vtb.account_rub);
	printf("  Счет (доллары): %'lld USD (%.2f руб.)\n", p1->vtb.account_usd, p1->vtb.rate_usd_rub);
	printf("  Доллар-счет в рублях: %'lld руб.\n", p1->vtb.account_usd * p1->vtb.rate_usd_rub);
	printf("  Подушка безопасности: %'lld руб.\n", p1->emergency_fund);
	printf("  Машина: %'lld руб.\n", p1->car.value);
	printf("  Квартира: %'lld руб.\n", p1->apartment.cost);
	printf("  Остаток по ипотеке: %'lld руб. (%d мес.)\n", 
		   p1->vtb.credit_amount - p1->vtb.credit_total_paid, p1->vtb.credit_months_remaining);
	printf("  Долг по кредитке: %'lld руб.\n", p1->credit_card_debt);
	
	
	RUB total_capital_p1 = p1->vtb.account_rub + 
	p1->vtb.account_usd * p1->vtb.rate_usd_rub + 
	p1->car.value + 
	p1->apartment.cost - 
	(p1->vtb.credit_amount - p1->vtb.credit_total_paid);
	printf("  ОБЩИЙ КАПИТАЛ: %'lld руб.\n", total_capital_p1);
	
	
	// Отчет по Бобу
	printf("\n--- %s ---\n", p2->name.c_str());
	printf("  Счет (рубли): %'lld руб.\n", p2->vtb.account_rub);
	printf("  Счет (доллары): %'lld USD (%.2f руб.)\n", p2->vtb.account_usd, p2->vtb.rate_usd_rub);
	printf("  Доллар-счет в рублях: %'lld руб.\n", p2->vtb.account_usd * p2->vtb.rate_usd_rub);
	printf("  Вклад: %'lld руб. (%.1f%%, осталось %d мес.)\n", 
		   p2->deposit.amount, p2->deposit.rate, p2->deposit.months_remaining);
	printf("  Подушка безопасности: %'lld руб.\n", p2->emergency_fund);
	printf("  Долг по кредитке: %'lld руб.\n", p2->credit_card_debt);
	printf("  Накоплено на квартиру: %'lld руб. (цель: %'lld)\n", 
		   p2->vtb.account_rub + p2->emergency_fund + p2->deposit.amount, 
		   p2->savings_goal);
	
	
	RUB total_capital_p2 = p2->vtb.account_rub + 
	p2->vtb.account_usd * p2->vtb.rate_usd_rub + 
	p2->deposit.amount;
	printf("  ОБЩИЙ КАПИТАЛ: %'lld руб.\n", total_capital_p2);
	
	
	printf("\n----------------------------------------\n");
}



void print_yearly_report(const int year, Person* p1, Person* p2) {
	
	printf("\n\n**** ГОДОВОЙ ОТЧЕТ %d ****\n", year);
	
	
	RUB capital_p1_start = 0;  
	RUB capital_p2_start = 0; 
	
	
	printf("\n--- %s ---\n", p1->name.c_str());
	printf("  Итоговый счет: %'lld руб.\n", p1->vtb.account_rub);
	printf("  Итоговая недвижимость: %'lld руб.\n", p1->apartment.cost);
	printf("  Остаток по ипотеке: %'lld руб.\n", p1->vtb.credit_amount - p1->vtb.credit_total_paid);
	
	
	printf("\n--- %s ---\n", p2->name.c_str());
	printf("  Итоговый счет: %'lld руб.\n", p2->vtb.account_rub);
	printf("  Итоговый вклад: %'lld руб.\n", p2->deposit.amount);
	printf("  Накоплено на квартиру: %'lld руб.\n", 
		   p2->vtb.account_rub + p2->emergency_fund + p2->deposit.amount);
	
	
	printf("************\n\n");
}



void simulation() {
	
	int year = 2026;
	int month = 2;
	
	
	printf("========== НАЧАЛО СИМУЛЯЦИИ ==========\n");
	printf("Алиса берет ипотеку, Боб копит на вклад\n\n");
	
	
	RUB alice_capital_last_year = 0;
	RUB bob_capital_last_year = 0;
	
	
	while (!(year == 2046 && month == 2)) { 
		
		alice_update_exchange_rate();
		alice_random_financial_events(month, year);
		alice_salary(month, year);
		alice_car(month, year);
		alice_cat(month, year); 
		alice_pay_mortgage();
		alice_apartment(month, year);
		alice_food(month, year);
		alice_other_expenses(month, year);
		alice_invest_in_currency(month);
		alice_handle_insurance(month);
		alice_handle_investments();
		alice_handle_education(month);
		alice_handle_health(month, year);
		alice_handle_subscriptions();
		alice_handle_travel(month);
		alice_handle_tax(month, year);
		alice_handle_pension();
		alice_handle_charity();
		alice_handle_other_debt();
		alice_handle_gifts(month);
		alice_manage_emergency_fund();
		alice_manage_credit_card();
		alice_handle_pets(month, year);
		
		
		bob_salary(month, year);
		bob_calculate_deposit_income();
		bob_apartment(month, year);
		bob_food(month, year);
		bob_other_expenses(month, year);
		bob_invest_in_currency(month);
		bob_handle_insurance(month);
		bob_handle_investments();
		bob_handle_education(month);
		bob_handle_health(month, year);
		bob_handle_subscriptions();
		bob_handle_travel(month);
		bob_handle_tax(month, year);
		bob_handle_pension();
		bob_handle_charity();
		bob_handle_other_debt();
		bob_handle_gifts(month);
		bob_manage_emergency_fund();
		bob_manage_credit_card();
		bob_handle_pets(month, year);
		bob_random_financial_events(month, year);
		bob_update_exchange_rate();
		
		
		handle_yearly_events(&alice, &bob, year);
		
		
		if (month % 6 == 0) {
			print_monthly_report(year, month, &alice, &bob);
		}
		
		
		if (month == 12) {
			print_yearly_report(year, &alice, &bob);
		}
		
		
		++month;
		if (month == 13) {
			++year;
			month = 1;
		}
	}
	
	
	printf("\n========== КОНЕЦ СИМУЛЯЦИИ ==========\n");
}



void print_results() {
	
	printf("\n\n");
	printf("========================================\n");
	printf("            ИТОГОВЫЕ РЕЗУЛЬТАТЫ         \n");
	printf("========================================\n\n");
	
	
	// Результаты Алисы
	printf("=== %s ===\n", alice.name.c_str());
	printf("Возраст: %d лет\n", alice.age + 20);  
	printf("Зарплата в конце периода: %'lld руб.\n", alice.salary);
	printf("\nАКТИВЫ:\n");
	printf("  Счет в рублях: %'lld руб.\n", alice.vtb.account_rub);
	printf("  Счет в долларах: %'lld USD (%.2f руб.)\n", alice.vtb.account_usd, alice.vtb.rate_usd_rub);
	printf("  Долларовый счет в рублях: %'lld руб.\n", alice.vtb.account_usd * alice.vtb.rate_usd_rub);
	printf("  Подушка безопасности: %'lld руб.\n", alice.emergency_fund);
	printf("  Машина: %'lld руб.\n", alice.car.value);
	printf("  Квартира: %'lld руб.\n", alice.apartment.cost);
	// Добавим новые активы
	printf("  Инвестиции (акции): %'lld руб.\n", alice.investment.stocks);
	printf("  Инвестиции (облигации): %'lld руб.\n", alice.investment.bonds);
	printf("  Инвестиции (ETF): %'lld руб.\n", alice.investment.etf);
	printf("  Инвестиции (крипто): %'lld руб.\n", alice.investment.crypto);
	
	
	printf("\nПАССИВЫ:\n");
	if (alice.vtb.credit_months_remaining > 0) {
		printf("  Остаток по ипотеке: %'lld руб. (%d мес.)\n", 
			   alice.vtb.credit_amount - alice.vtb.credit_total_paid, 
			   alice.vtb.credit_months_remaining);
	} else {
		printf("  Ипотека: ПОЛНОСТЬЮ ВЫПЛАЧЕНА!\n");
	}
	printf("  Долг по кредитной карте: %'lld руб.\n", alice.credit_card_debt);
	
	if (alice.other_debt.amount > 0) {
		printf("  Прочие долги: %'lld руб.\n", alice.other_debt.amount);
	}
	
	
	RUB alice_total_assets = alice.vtb.account_rub + 
	alice.vtb.account_usd * alice.vtb.rate_usd_rub + 
	alice.emergency_fund +
	alice.car.value + 
	alice.apartment.cost +
	alice.investment.stocks +
	alice.investment.bonds +
	alice.investment.etf +
	alice.investment.crypto;
	
	
	RUB alice_total_liabilities = (alice.vtb.credit_amount - alice.vtb.credit_total_paid) + 
	alice.credit_card_debt + alice.other_debt.amount;
	
	
	RUB alice_net_worth = alice_total_assets - alice_total_liabilities;
	
	
	printf("\nИТОГО:\n");
	printf("  Всего активов: %'lld руб.\n", alice_total_assets);
	printf("  Всего обязательств: %'lld руб.\n", alice_total_liabilities);
	printf("  ЧИСТЫЙ КАПИТАЛ: %'lld руб.\n", alice_net_worth);
	
	
	printf("\n----------------------------------------\n\n");
	
	
	// Результаты Боба
	printf("=== %s ===\n", bob.name.c_str());
	
	
	printf("Возраст: %d лет\n", bob.age + 20);
	printf("Зарплата в конце периода: %'lld руб.\n", bob.salary);
	printf("\nАКТИВЫ:\n");
	printf("  Счет в рублях: %'lld руб.\n", bob.vtb.account_rub);
	printf("  Счет в долларах: %'lld USD (%.2f руб.)\n", bob.vtb.account_usd, bob.vtb.rate_usd_rub);
	printf("  Долларовый счет в рублях: %'lld руб.\n", bob.vtb.account_usd * bob.vtb.rate_usd_rub);
	printf("  Вклад в банке: %'lld руб.\n", bob.deposit.amount);
	printf("  Подушка безопасности: %'lld руб.\n", bob.emergency_fund);
	printf("  Инвестиции (облигации): %'lld руб.\n", bob.investment.bonds);
	
	
	// Предположим, что Боб купил квартиру, если накопил достаточно
	bool bought_apartment = false;
	
	RUB bob_savings = bob.vtb.account_rub + bob.vtb.account_usd * bob.vtb.rate_usd_rub + 
	bob.deposit.amount + bob.emergency_fund + bob.investment.bonds;
	
	
	if (bob_savings >= bob.savings_goal && !bob.apartment.is_owned) {
		printf("\n* Боб накопил достаточно и КУПИЛ КВАРТИРУ! *\n");
		bob.apartment.is_owned = true;
		bob.apartment.cost = bob.savings_goal;
		bob.apartment.square_meters = 50;
		bob.apartment.rooms = 2;
		bought_apartment = true;
	}
	
	
	if (bob.apartment.is_owned) {
		
		printf("  Квартира: %'lld руб.\n", bob.apartment.cost);
	}
	
	
	printf("\nПАССИВЫ:\n");
	
	printf("  Долг по кредитной карте: %'lld руб.\n", bob.credit_card_debt);
	if (bob.other_debt.amount > 0) {
		printf("  Прочие долги (потребкредит): %'lld руб.\n", bob.other_debt.amount);
	}
	
	
	RUB bob_total_assets = bob.vtb.account_rub + 
	bob.vtb.account_usd * bob.vtb.rate_usd_rub + 
	bob.deposit.amount +
	bob.emergency_fund +
	bob.investment.bonds;
	
	
	if (bob.apartment.is_owned) {
		bob_total_assets += bob.apartment.cost;
	}
	
	
	RUB bob_total_liabilities = bob.credit_card_debt + bob.other_debt.amount;
	
	RUB bob_net_worth = bob_total_assets - bob_total_liabilities;
	
	
	printf("\nИТОГО:\n");
	printf("  Всего активов: %'lld руб.\n", bob_total_assets);
	printf("  Всего обязательств: %'lld руб.\n", bob_total_liabilities);
	printf("  ЧИСТЫЙ КАПИТАЛ: %'lld руб.\n", bob_net_worth);
	
	
	printf("\n========================================\n");
	
	
	printf("\n");
	printf("========================================\n");
	printf("         СРАВНЕНИЕ РЕЗУЛЬТАТОВ          \n");
	printf("========================================\n");
	printf("Алиса (ипотека): %'lld руб.\n", alice_net_worth);
	printf("Боб (вклад):     %'lld руб.\n", bob_net_worth);
	
	
	if (alice_net_worth > bob_net_worth) {
		printf("\nПОБЕДИТЕЛЬ: Алиса! Ипотека оказалась выгоднее накоплений.\n");
		printf("Разница: %'lld руб.\n", alice_net_worth - bob_net_worth);
	} else if (bob_net_worth > alice_net_worth) {
		printf("\nПОБЕДИТЕЛЬ: Боб! Накопления оказались выгоднее ипотеки.\n");
		printf("Разница: %'lld руб.\n", bob_net_worth - alice_net_worth);
	} else {
		printf("\nНИЧЬЯ! Оба достигли одинакового результата.\n");
	}
	
	printf("========================================\n");
}


void scenario_analysis() {
	
	printf("\n\n");
	printf("========================================\n");
	printf("       АНАЛИЗ РАЗЛИЧНЫХ СЦЕНАРИЕВ       \n");
	printf("========================================\n\n");
	
	
	printf("Сценарий 1: Высокая инфляция (15%%)\n");
	printf("Сценарий 2: Низкая инфляция (5%%)\n");
	printf("Сценарий 3: Экономический кризис\n");
	printf("Сценарий 4: Стабильная экономика\n\n");
	
	
	printf("Для более детального анализа запустите программу несколько раз\n");
	printf("с различными начальными параметрами (ставки, суммы и т.д.)\n");
}


int main() {
	
	
	srand(time(NULL));
	
	
	printf("========================================\n");
	printf("   СИМУЛЯЦИЯ ЖИЗНИ: АЛИСА vs БОБ      \n");
	printf("========================================\n\n");
	
	
	printf("Алиса берет ипотеку на квартиру\n");
	printf("Боб копит деньги на вкладе\n");
	printf("Сравнение результатов через 20 лет\n\n");
	
	
	alice_init();
	bob_init();
	
	
	printf("Начальные данные:\n");
	printf("  Алиса: зарплата %lld руб., ипотека %lld руб. на 20 лет\n", 
		   alice.salary, alice.vtb.credit_amount);
	printf("  Боб:   зарплата %lld руб., вклад %lld руб. под %.1f%%\n\n", 
		   bob.salary, bob.deposit.amount, bob.deposit.rate);
	
	
	simulation();
	
	
	print_results();
	
	
	scenario_analysis();
	
	
	printf("\nПрограмма завершена. Спасибо за использование!\n");
	
	
	return 0;
}
