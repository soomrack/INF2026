#include <stdio.h>
#include <stdlib.h>  
#include <time.h>   
#include <string>
#include <vector>


using Percent = float;
using RUB = long long int;
using USD = long long int;
using MonthCount = int;


struct MonthData {
	int year;
	int month;
	
	// Данные Алисы
	RUB alice_account_rub;
	USD alice_account_usd;
	RUB alice_debt;
	RUB alice_car_value;
	RUB alice_food;
	RUB alice_credit_paid;
	RUB alice_early_payment;
	RUB alice_invest_amount;
	RUB alice_invest_result;
	std::string alice_invest_type;
	
	
	RUB john_account_rub;
	USD john_account_usd;
	RUB john_debt;
	RUB john_car_value;
	RUB john_food;
	RUB john_salary;
	RUB john_credit_paid;
	RUB john_early_payment;
	RUB john_invest_amount;
	RUB john_invest_result;
	std::string john_invest_type;
	
	// Ежемесячные события
	std::vector<std::string> events;
};


struct UtilitiesData {
	RUB total;
	RUB rent;
	RUB electricity;
	RUB water;
	RUB gas;
	RUB internet_tv;
	RUB mobile_family;
	RUB cleaning;
	RUB security;
	RUB garbage;
	RUB elevator;
	RUB home_repair;
	RUB parking;
	RUB gym;
	RUB tv_subscription;
	RUB music_subscription;
	RUB cinema_subscription;
	float percent_of_salary;
	bool used_usd;
};


struct HolidayData {
	std::string name;
	RUB amount;
	std::string description;
};


struct CharityData {
	std::string name;
	RUB amount;
	std::string description;
};


struct HealthData {
	int alice_health;
	int john_health;
	RUB medicine_fund;
	int alice_visits;
	int john_visits;
	RUB spent_on_medicine;
};


struct SavingsData {
	RUB vacation_fund;
	RUB emergency_fund;
	RUB big_purchase_fund;
	RUB education_fund;
	RUB vacation_goal;
	RUB emergency_goal;
	RUB big_purchase_goal;
	RUB education_goal;
};


struct SportsData {
	int alice_workouts;
	int john_workouts;
	RUB spent_on_sports;
};


struct RealEstateData {
	RUB apartment_value;
	RUB mortgage_debt;
	RUB mortgage_paid;
	int months_paid;
	bool bought;
};


struct EducationData {
	RUB education_fund;
	int alice_courses;
	int john_courses;
	RUB spent;
};


struct TravelData {
	RUB travel_fund;
	int trips_taken;
	RUB spent;
};


struct SimulationData {
	std::vector<MonthData> months;
	std::vector<UtilitiesData> utilities_history;
	std::vector<HolidayData> holidays;
	std::vector<CharityData> charities;
	std::vector<HealthData> health_history;
	std::vector<SavingsData> savings_history;
	std::vector<SportsData> sports_history;
	std::vector<RealEstateData> realestate_history;
	std::vector<EducationData> education_history;
	std::vector<TravelData> travel_history;
	
	RUB yearly_utilities[4] = {0};
	int yearly_doctor_visits_alice[4] = {0};
	int yearly_doctor_visits_john[4] = {0};
	RUB yearly_medicine_spent[4] = {0};
} sim_data;


int year = 2026;
int month = 2;


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
	MonthCount month;
	RUB payment;
	RUB remainder;
	Percent rate;
	RUB partial_payment;
};


struct RealEstate {
	RUB apartment_value;
	RUB mortgage_debt;
	RUB mortgage_payment;
	RUB rent_income;
	bool has_apartment;
	bool is_rented;
};


struct Person { 
	Bank vtb;
	RUB salary;
	RUB food;
	Car car;
	Credit credit;
	RealEstate realty;
	RUB debt_initial;  // Для отслеживания начального долга
};


struct Person alice;
struct Person john;


// Статические переменные для отслеживания состояния
static int alice_health = 100;
static int john_health = 100;
static RUB medicine_fund = 0;
static int doctor_visits_alice = 0;
static int doctor_visits_john = 0;


static RUB vacation_fund = 0;
static RUB emergency_fund = 0;
static RUB big_purchase_fund = 0;
static RUB education_fund_local = 0;


static int alice_workouts = 0;
static int john_workouts = 0;
static RUB sports_spent = 0;


static RUB apartment_value = 8000000;
static RUB mortgage_debt = 0;
static int months_paid = 0;
static bool bought_apartment = false;


static RUB education_fund_global = 0;
static int alice_courses = 0;
static int john_courses = 0;
static RUB spent_on_education = 0;


static RUB travel_fund = 0;
static int trips_taken = 0;
static RUB spent_on_travel = 0;


static RUB yearly_utilities[4] = {0};
static int last_inflation_year = 2026;


void  alice_init() {
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
	alice.debt_initial = alice.credit.debt;
	
	alice.realty.apartment_value = 0;
	alice.realty.mortgage_debt = 0;
	alice.realty.mortgage_payment = 0;
	alice.realty.rent_income = 0;
	alice.realty.has_apartment = false;
	alice.realty.is_rented = false;
}


void  john_init() {
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
	john.debt_initial = john.credit.debt;
	
	john.realty.apartment_value = 0;
	john.realty.mortgage_debt = 0;
	john.realty.mortgage_payment = 0;
	john.realty.rent_income = 0;
	john.realty.has_apartment = false;
	john.realty.is_rented = false;
}


void  alice_food(const int month, const int year) {
	if (month == 12) alice.vtb.account_rub -= 2000;
	
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
	}
	alice.food += (RUB)(alice.food * (inflation / 100 / 12));
	
	alice.vtb.account_rub -= alice.food;
}


void  john_food(const int month, const int year) {
	if (month == 12) john.vtb.account_rub -= 3000;
	Percent inflation = 12.0;
	switch (year) {
		case 2026: inflation = 12.5; break;
		case 2027: inflation = 14.0; break;
		case 2028: inflation = 13.0; break;
		case 2029: inflation = 11.5; break;
	}
	john.food += (RUB)(john.food * (inflation / 100 / 12));
	john.vtb.account_rub -= john.food;
}


void  alice_salary(const int month, const int year) {
	if (month == 3) {
		alice.salary = (RUB)(alice.salary * 1.5);
	}
	
	if (month == 2 && year == 2026) {
		alice.vtb.account_rub += 5000;
	}
	alice.vtb.account_rub += alice.salary;
}


void  john_salary(const int month, const int year) {
	if (month == 3) {
		john.salary = (RUB)(john.salary * 1.5);
	}
	
	if (month == 2 && year == 2026) {
		john.vtb.account_rub += 15000;
	}
	
	if (month == 12) {
		john.vtb.account_rub += 30000;
	}
	
	if (month == 6) {
		john.vtb.account_rub += 20000;
	}
	john.vtb.account_rub += john.salary;
}


void  alice_car() {
	if (alice.car.value > 0) {
		alice.vtb.account_rub -= alice.car.gas;
	}
}


void  john_car() {
	if (john.car.value > 0) {
		john.vtb.account_rub -= john.car.gas;
		if (month >= 6 && month <= 8) {
			john.vtb.account_rub -= 3000; 
		}
	}
}


void  alice_credit(const int year, const int month) {
	if (alice.credit.debt <= 0) return;
	
	if (alice.vtb.account_rub >= alice.credit.payment) {
		alice.vtb.account_rub -= alice.credit.payment;
		alice.credit.debt -= alice.credit.payment;
	} else {
		RUB partial = alice.vtb.account_rub;
		alice.credit.debt -= partial;
		alice.vtb.account_rub = 0;
	}
}


void  john_credit(const int year, const int month) {
	if (john.credit.debt <= 0) return;
	
	if (john.vtb.account_rub >= john.credit.payment) {
		john.vtb.account_rub -= john.credit.payment;
		john.credit.debt -= john.credit.payment;
	} else {
		RUB partial = john.vtb.account_rub;
		john.credit.debt -= partial;
		john.vtb.account_rub = 0;
	}
}


void  alice_early_credit_payment() {
	RUB threshold = 500000;
	
	if (alice.vtb.account_rub <= threshold || alice.credit.debt <= 0) return;
	
	RUB extra_payment = alice.vtb.account_rub - threshold;
	if (extra_payment > alice.credit.debt) {
		extra_payment = alice.credit.debt;
	}
	
	if (extra_payment <= 0) return;
	
	alice.vtb.account_rub -= extra_payment;
	alice.credit.debt -= extra_payment;
}


void  john_early_credit_payment() {
	RUB threshold = 400000;
	
	if (john.vtb.account_rub <= threshold || john.credit.debt <= 0) return;
	
	RUB extra_payment = john.vtb.account_rub - threshold;
	if (extra_payment > john.credit.debt) {
		extra_payment = john.credit.debt;
	}
	
	if (extra_payment <= 0) return;
	
	john.vtb.account_rub -= extra_payment;
	john.credit.debt -= extra_payment;
}


void  alice_invest() {
	RUB invest_threshold = 300000;
	RUB min_invest = 100000;
	
	if (alice.vtb.account_rub <= invest_threshold) return;
	
	RUB extra = alice.vtb.account_rub - invest_threshold;
	RUB invest_amount = (RUB)(extra * 0.3);
	invest_amount = (invest_amount / 1000) * 1000;
	
	if (invest_amount < min_invest) return;
	
	alice.vtb.account_rub -= invest_amount;
	
	int invest_type = rand() % 2;	
	
	if (invest_type == 0) {
		RUB profit = (RUB)(invest_amount * 0.05);
		alice.vtb.account_rub += invest_amount + profit;
	} else {
		int risk = rand() % 100;
		if (risk < 70) {
			RUB profit = (RUB)(invest_amount * 0.20);
			alice.vtb.account_rub += invest_amount + profit;
		} else if (risk < 90) {
			RUB loss = (RUB)(invest_amount * 0.10);
			alice.vtb.account_rub += invest_amount - loss;
		} else {
			RUB loss = (RUB)(invest_amount * 0.30);
			alice.vtb.account_rub += invest_amount - loss;
		}
	}
}


void  john_invest() {
	RUB invest_threshold = 400000;
	RUB min_invest = 150000;
	
	if (john.vtb.account_rub <= invest_threshold) return;
	
	RUB extra = john.vtb.account_rub - invest_threshold;
	RUB invest_amount = (RUB)(extra * 0.4);
	invest_amount = (invest_amount / 1000) * 1000;
	
	if (invest_amount < min_invest) return;
	
	john.vtb.account_rub -= invest_amount;
	
	int invest_type = rand() % 2;	
	
	if (invest_type == 0) {
		RUB profit = (RUB)(invest_amount * 0.06);
		john.vtb.account_rub += invest_amount + profit;
	} else {
		int risk = rand() % 100;
		if (risk < 60) {
			RUB profit = (RUB)(invest_amount * 0.25);
			john.vtb.account_rub += invest_amount + profit;
		} else if (risk < 80) {
			RUB loss = (RUB)(invest_amount * 0.10);
			john.vtb.account_rub += invest_amount - loss;
		} else {
			RUB loss = (RUB)(invest_amount * 0.30);
			john.vtb.account_rub += invest_amount - loss;
		}
	}
}


void  alice_car_transaction(int current_month, int current_year) {
	static int alice_car_purchase_month = 2;
	static int alice_car_purchase_year = 2026;
	
	int car_age_months = (current_year - alice_car_purchase_year) * 12 + (current_month - alice_car_purchase_month);
	
	if (car_age_months < 24 || alice.car.value <= 0) return;
	
	alice.vtb.account_rub += alice.car.value;
	
	RUB new_car_price = (RUB)(alice.car.value * 1.2);
	
	if (alice.vtb.account_rub >= new_car_price + alice.car.gas) {
		alice.vtb.account_rub -= (new_car_price + alice.car.gas);
		alice.car.value = new_car_price;
		alice_car_purchase_month = current_month;
		alice_car_purchase_year = current_year;
		return;
	}
	
	RUB budget_car = (RUB)(alice.car.value * 0.8);	
	
	if (alice.vtb.account_rub >= budget_car + alice.car.gas) {
		alice.vtb.account_rub -= (budget_car + alice.car.gas);
		alice.car.value = budget_car;
		alice_car_purchase_month = current_month;
		alice_car_purchase_year = current_year;
	} else {
		alice.car.value = 0;
		alice.car.gas = 0;
	}
}


void  john_car_transaction(int current_month, int current_year) {
	static int john_car_purchase_month = 2;
	static int john_car_purchase_year = 2026;
	
	int car_age_months = (current_year - john_car_purchase_year) * 12 + (current_month - john_car_purchase_month);
	
	if (car_age_months < 30 || john.car.value <= 0) return;
	
	john.vtb.account_rub += john.car.value;
	
	RUB new_car_price = (RUB)(john.car.value * 1.25);	
	
	if (john.vtb.account_rub >= new_car_price + john.car.gas) {
		john.vtb.account_rub -= (new_car_price + john.car.gas);
		john.car.value = new_car_price;
		john_car_purchase_month = current_month;
		john_car_purchase_year = current_year;
	}
}


void  family_utilities(const int month, const int year) {
	static RUB rent = 45000;
	static RUB electricity = 3500;
	static RUB water = 2000;
	static RUB gas = 1200;
	static RUB internet_tv = 1500;
	static RUB mobile_family = 2500;
	static RUB cleaning = 2000;
	static RUB security = 3000;
	static RUB garbage = 800;
	static RUB elevator = 500;
	static RUB home_repair = 1000;
	static RUB parking = 4000;
	static RUB gym = 3500;
	static RUB tv_subscription = 1000;
	static RUB music_subscription = 500;
	static RUB cinema_subscription = 800;
	
	
	if (month == 1 && year > last_inflation_year) {
		float utilities_inflation = 1.0;
		switch (year) {
			case 2027: utilities_inflation = 1.06; break;
			case 2028: utilities_inflation = 1.08; break;
			case 2029: utilities_inflation = 1.05; break;
			default: utilities_inflation = 1.0;
		}
		
		rent = (RUB)(rent * utilities_inflation);
		electricity = (RUB)(electricity * utilities_inflation);
		water = (RUB)(water * utilities_inflation);
		gas = (RUB)(gas * utilities_inflation);
		internet_tv = (RUB)(internet_tv * utilities_inflation);
		mobile_family = (RUB)(mobile_family * utilities_inflation);
		cleaning = (RUB)(cleaning * utilities_inflation);
		security = (RUB)(security * utilities_inflation);
		garbage = (RUB)(garbage * utilities_inflation);
		elevator = (RUB)(elevator * utilities_inflation);
		home_repair = (RUB)(home_repair * utilities_inflation);
		parking = (RUB)(parking * utilities_inflation);
		gym = (RUB)(gym * utilities_inflation);
		tv_subscription = (RUB)(tv_subscription * utilities_inflation);
		music_subscription = (RUB)(music_subscription * utilities_inflation);
		cinema_subscription = (RUB)(cinema_subscription * utilities_inflation);
		
		last_inflation_year = year;
	}
	
	
	RUB current_rent = rent;
	RUB current_electricity = electricity;
	RUB current_water = water;
	RUB current_gas = gas;
	RUB current_cleaning = cleaning;
	RUB current_home_repair = home_repair;
	
	
	switch (month) {
	case 12:
	case 1:
	case 2:
		current_rent += 4000;
		current_electricity += 1000;
		break;
		
	case 6:
	case 7:
	case 8:
		current_electricity += 3000;
		current_water += 1000;
		break;
		
	case 4:
	case 10:
		current_cleaning += 1500;
		break;
	}	
	
	
	// вероятность непредвиденных расходов до 25%
	int unexpected = rand() % 100;
	if (unexpected < 25) {  
		RUB unexpected_cost = 0;
		std::string incident_type;
		
		//список возможных инцидентов 
		switch (rand() % 15) {  
			case 0: 
			unexpected_cost = 5000; 
			incident_type = "Протечка крана";
			break;
			case 1: 
			unexpected_cost = 3000; 
			incident_type = "Замена лампочек в подъезде";
			break;
			case 2: 
			unexpected_cost = 2000; 
			incident_type = "Ремонт домофона";
			break;
			case 3: 
			unexpected_cost = 4000; 
			incident_type = "Замок в двери сломался";
			break;
			case 4: 
			unexpected_cost = 2500; 
			incident_type = "Прочистка канализации";
			break;
			case 5: 
			unexpected_cost = 3500; 
			incident_type = "Замена счетчика воды";
			break;
			case 6: 
			unexpected_cost = 6000; 
			incident_type = "Прорыв трубы отопления";
			break;
			case 7: 
			unexpected_cost = 1500; 
			incident_type = "Мелкий ремонт электропроводки";
			break;
			case 8: 
			unexpected_cost = 8000; 
			incident_type = "Поломка стиральной машины";
			break;
			case 9: 
			unexpected_cost = 4500; 
			incident_type = "Замена смесителя в ванной";
			break;
			case 10: 
			unexpected_cost = 5500; 
			incident_type = "Ремонт унитаза";
			break;
			case 11: 
			unexpected_cost = 3500; 
			incident_type = "Замена розеток и выключателей";
			break;
			case 12: 
			unexpected_cost = 7000; 
			incident_type = "Залив от соседей (доля расходов)";
			break;
			case 13: 
			unexpected_cost = 9000; 
			incident_type = "Аварийный вызов сантехника";
			break;
			case 14: 
			unexpected_cost = 10000; 
			incident_type = "Замена входной двери";
			break;
		}
		
		current_home_repair += unexpected_cost;
		home_repair += unexpected_cost;
		
		
		//событие в месячные данные для отслеживания
		if (!sim_data.months.empty()) {
			std::string event_desc = "Непредвиденный ремонт: " + incident_type + " - " + 
			std::to_string(unexpected_cost) + " RUB";
			sim_data.months.back().events.push_back(event_desc);
		}
	}
	
	
	//сезонные аварии (более вероятны зимой)
	if ((month == 12 || month == 1 || month == 2) && (rand() % 100) < 10) {
		RUB seasonal_cost = 0;
		std::string seasonal_issue;
		
		switch (rand() % 3) {
		case 0:
			seasonal_cost = 12000;
			seasonal_issue = "Прорыв трубы отопления из-за морозов";
			break;
		case 1:
			seasonal_cost = 8000;
			seasonal_issue = "Обледенение крыши - вызов бригады";
			break;
		case 2:
			seasonal_cost = 5000;
			seasonal_issue = "Замерзшие трубы - отогрев";
			break;
		}
		
		current_home_repair += seasonal_cost;
		home_repair += seasonal_cost;
		
		if (!sim_data.months.empty()) {
			std::string event_desc = "Сезонная авария: " + seasonal_issue + " - " + 
			std::to_string(seasonal_cost) + " RUB";
			sim_data.months.back().events.push_back(event_desc);
		}
	}
	
	
	//летние проблемы
	if ((month == 6 || month == 7 || month == 8) && (rand() % 100) < 8) {
		RUB summer_cost = 0;
		std::string summer_issue;
		
		switch (rand() % 3) {
		case 0:
			summer_cost = 10000;
			summer_issue = "Поломка кондиционера - ремонт";
			break;
		case 1:
			summer_cost = 6000;
			summer_issue = "Залив во время ливня (ремонт кровли)";
			break;
		case 2:
			summer_cost = 4000;
			summer_issue = "Нашествие муравьев/тараканов - дезинсекция";
			break;
		}
		
		current_home_repair += summer_cost;
		home_repair += summer_cost;
		
		if (!sim_data.months.empty()) {
			std::string event_desc = "Летняя проблема: " + summer_issue + " - " + 
			std::to_string(summer_cost) + " RUB";
			sim_data.months.back().events.push_back(event_desc);
		}
	}
	
	
	// крупные непредвиденные расходы (низкая вероятность, но большие суммы)
	if (rand() % 100 < 5) {
		RUB major_cost = 0;
		std::string major_issue;
		
		switch (rand() % 4) {
		case 0:
			major_cost = 25000;
			major_issue = "Замена водонагревателя";
			break;
		case 1:
			major_cost = 30000;
			major_issue = "Ремонт после протечки кровли";
			break;
		case 2:
			major_cost = 20000;
			major_issue = "Замена электропроводки в комнате";
			break;
		case 3:
			major_cost = 35000;
			major_issue = "Ремонт газового оборудования";
			break;
		}
		
		current_home_repair += major_cost;
		home_repair += major_cost;
		
		if (!sim_data.months.empty()) {
			std::string event_desc = "КРУПНЫЙ РЕМОНТ: " + major_issue + " - " + 
			std::to_string(major_cost) + " RUB";
			sim_data.months.back().events.push_back(event_desc);
		}
	}
	
	RUB total_utilities = current_rent + current_electricity + current_water + current_gas + 
	internet_tv + mobile_family + current_cleaning + security + garbage + 
	elevator + current_home_repair + parking + gym + 
	tv_subscription + music_subscription + cinema_subscription;
	
	bool used_usd = false;	
	
	if (total_utilities <= john.salary * 0.5) {
		john.vtb.account_rub -= total_utilities;
	} else {
		if (john.vtb.account_rub >= total_utilities) {
			john.vtb.account_rub -= total_utilities;
		} else {
			RUB from_usd = (RUB)(john.vtb.account_usd * john.vtb.rate_usd_rub);
			john.vtb.account_rub += from_usd;
			john.vtb.account_usd = 0;
			john.vtb.account_rub -= total_utilities;
			used_usd = true;
		}
	}
	
	
	// Сохранение данных
	UtilitiesData ud;
	ud.total = total_utilities;
	ud.rent = current_rent;
	ud.electricity = current_electricity;
	ud.water = current_water;
	ud.gas = current_gas;
	ud.internet_tv = internet_tv;
	ud.mobile_family = mobile_family;
	ud.cleaning = current_cleaning;
	ud.security = security;
	ud.garbage = garbage;
	ud.elevator = elevator;
	ud.home_repair = current_home_repair;
	ud.parking = parking;
	ud.gym = gym;
	ud.tv_subscription = tv_subscription;
	ud.music_subscription = music_subscription;
	ud.cinema_subscription = cinema_subscription;
	ud.percent_of_salary = (float)total_utilities / john.salary * 100;
	ud.used_usd = used_usd;
	
	sim_data.utilities_history.push_back(ud);
	
	int year_index = year - 2026;
	if (year_index >= 0 && year_index < 4) {
		yearly_utilities[year_index] += total_utilities;
		sim_data.yearly_utilities[year_index] = yearly_utilities[year_index];
	}
}


void  new_year_gifts(const int month, const int year) {
	if (month != 12) return;
	
	HolidayData hd;
	hd.name = "New Year";
	hd.amount = 0;
	
	if (john.vtb.account_rub >= 5000) {
		john.vtb.account_rub -= 5000;
		hd.amount += 5000;
	}
	
	if (alice.vtb.account_rub >= 5000) {
		alice.vtb.account_rub -= 5000;
		hd.amount += 5000;
	}
	
	RUB family_gifts = 5000;
	RUB alice_part = family_gifts / 2;
	RUB john_part = family_gifts / 2;
	
	if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
		alice.vtb.account_rub -= alice_part;
		john.vtb.account_rub -= john_part;
		hd.amount += family_gifts;
	}
	
	RUB new_year_food = 8000;
	alice_part = new_year_food / 2;
	john_part = new_year_food / 2;	
	
	if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
		alice.vtb.account_rub -= alice_part;
		john.vtb.account_rub -= john_part;
		hd.amount += new_year_food;
	}
	
	hd.description = "New Year celebration and gifts";
	sim_data.holidays.push_back(hd);
}


void  march_8_gifts(const int month, const int year) {
	if (month != 3) return;
	
	HolidayData hd;
	hd.name = "International Women's Day";
	hd.amount = 0;
	
	if (john.vtb.account_rub >= 5000) {
		john.vtb.account_rub -= 5000;
		hd.amount += 5000;
	} else if (john.vtb.account_rub >= 3000) {
		john.vtb.account_rub -= 3000;
		hd.amount += 3000;
	}
	
	RUB moms_gift = 4000;
	
	if (john.vtb.account_rub >= moms_gift) {
		john.vtb.account_rub -= moms_gift;
		hd.amount += moms_gift;
	}
	
	if (alice.vtb.account_rub >= moms_gift) {
		alice.vtb.account_rub -= moms_gift;
		hd.amount += moms_gift;
	}
	
	hd.description = "International Women's Day gifts";
	sim_data.holidays.push_back(hd);
}


void  february_23_gifts(const int month, const int year) {
	if (month != 2) return;
	
	HolidayData hd;
	hd.name = "Defender of the Fatherland Day";
	hd.amount = 0;
	
	if (alice.vtb.account_rub >= 5000) {
		alice.vtb.account_rub -= 5000;
		hd.amount += 5000;
	} else if (alice.vtb.account_rub >= 3000) {
		alice.vtb.account_rub -= 3000;
		hd.amount += 3000;
	}
	
	RUB dads_gift = 4000;
	
	if (alice.vtb.account_rub >= dads_gift) {
		alice.vtb.account_rub -= dads_gift;
		hd.amount += dads_gift;
	}
	
	if (john.vtb.account_rub >= dads_gift) {
		john.vtb.account_rub -= dads_gift;
		hd.amount += dads_gift;
	}
	
	hd.description = "Defender of the Fatherland Day gifts";
	sim_data.holidays.push_back(hd);
}


void  valentines_day_gifts(const int month, const int year) {
	if (month != 2) return;
	
	HolidayData hd;
	hd.name = "Valentine's Day";
	hd.amount = 0;
	
	if (year == 2026) {
		if (john.vtb.account_rub >= 5000 && alice.vtb.account_rub >= 5000) {
			john.vtb.account_rub -= 5000;
			alice.vtb.account_rub -= 5000;
			hd.amount = 10000;
		}
	} else {
		if (john.vtb.account_rub >= 3000 && alice.vtb.account_rub >= 3000) {
			john.vtb.account_rub -= 3000;
			alice.vtb.account_rub -= 3000;
			hd.amount = 6000;
		}
	}
	
	hd.description = "Romantic celebration";
	if (hd.amount > 0) sim_data.holidays.push_back(hd);
}


void  birthday_alice(const int month, const int year) {
	if (month != 5) return;
	
	HolidayData hd;
	hd.name = "Alice's Birthday";
	hd.amount = 0;
	
	RUB gift_from_john = 7000;
	
	if (john.vtb.account_rub >= gift_from_john) {
		john.vtb.account_rub -= gift_from_john;
		hd.amount += gift_from_john;
	}
	
	RUB celebration = 10000;
	RUB alice_part = celebration / 2;
	RUB john_part = celebration / 2;
	
	if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
		alice.vtb.account_rub -= alice_part;
		john.vtb.account_rub -= john_part;
		hd.amount += celebration;
	}
	
	hd.description = "Birthday celebration in May";
	sim_data.holidays.push_back(hd);
}


void  birthday_john(const int month, const int year) {
	if (month != 9) return;
	
	HolidayData hd;
	hd.name = "John's Birthday";
	hd.amount = 0;
	
	RUB gift_from_alice = 8000;
	
	if (alice.vtb.account_rub >= gift_from_alice) {
		alice.vtb.account_rub -= gift_from_alice;
		hd.amount += gift_from_alice;
	}
	
	RUB celebration = 12000;
	RUB alice_part = celebration / 2;
	RUB john_part = celebration / 2;
	
	if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
		alice.vtb.account_rub -= alice_part;
		john.vtb.account_rub -= john_part;
		hd.amount += celebration;
	}
	
	if (alice.vtb.account_rub >= 5000 && john.vtb.account_rub >= 5000) {
		alice.vtb.account_rub -= 5000;
		john.vtb.account_rub -= 5000;
		hd.amount += 10000;
	}
	
	hd.description = "Birthday celebration in September";
	sim_data.holidays.push_back(hd);
}


void  anniversary_wedding(const int month, const int year) {
	if (month != 8) return;
	
	int years_married = year - 2026;
	if (years_married <= 0) return;
	
	HolidayData hd;
	hd.name = "Wedding Anniversary";
	hd.amount = 0;
	
	RUB celebration = 8000 + (years_married * 2000);
	RUB alice_part = celebration / 2;
	RUB john_part = celebration / 2;
	
	if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
		alice.vtb.account_rub -= alice_part;
		john.vtb.account_rub -= john_part;
		hd.amount += celebration;
	}
	
	RUB gift = 5000 + (years_married * 1000);
	if (john.vtb.account_rub >= gift) {
		john.vtb.account_rub -= gift;
		hd.amount += gift;
	}
	if (alice.vtb.account_rub >= gift) {
		alice.vtb.account_rub -= gift;
		hd.amount += gift;
	}
	
	char desc[100];
	sprintf(desc, "%d years of marriage", years_married);
	hd.description = desc;
	sim_data.holidays.push_back(hd);
}


void  victory_day(const int month, const int year) {
	if (month != 5) return;
	
	HolidayData hd;
	hd.name = "Victory Day";
	hd.amount = 0;
	
	RUB veterans_gift = 2000;
	if (john.vtb.account_rub >= veterans_gift) {
		john.vtb.account_rub -= veterans_gift;
		hd.amount += veterans_gift;
	}
	
	RUB festive_dinner = 3000;
	RUB alice_part = festive_dinner / 2;
	RUB john_part = festive_dinner / 2;
	
	if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
		alice.vtb.account_rub -= alice_part;
		john.vtb.account_rub -= john_part;
		hd.amount += festive_dinner;
	}
	
	hd.description = "May 9 celebration";
	sim_data.holidays.push_back(hd);
}


void  halloween(const int month, const int year) {
	if (month != 10) return;
	
	HolidayData hd;
	hd.name = "Halloween";
	hd.amount = 0;
	
	RUB decorations = 2000;
	RUB alice_part = decorations / 2;
	RUB john_part = decorations / 2;
	
	if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
		alice.vtb.account_rub -= alice_part;
		john.vtb.account_rub -= john_part;
		hd.amount += decorations;
	}
	
	RUB candy = 1500;
	
	if (john.vtb.account_rub >= candy) {
		john.vtb.account_rub -= candy;
		hd.amount += candy;
	}
	
	hd.description = "Halloween celebration";
	sim_data.holidays.push_back(hd);
}


void  easter_celebration(const int month, const int year) {
	if (month != 4) return;
	
	HolidayData hd;
	hd.name = "Easter";
	hd.amount = 0;
	
	RUB easter_food = 0;
	RUB easter_gifts = 0;
	RUB easter_decorations = 0;
	
	if (year == 2026) {
		easter_food = 5000;
		easter_gifts = 3000;
		easter_decorations = 1500;
	} else if (year == 2027) {
		easter_food = 6000;
		easter_gifts = 4000;
		easter_decorations = 2000;
	} else if (year == 2028) {
		easter_food = 7000;
		easter_gifts = 5000;
		easter_decorations = 2500;
	} else {
		easter_food = 8000;
		easter_gifts = 6000;
		easter_decorations = 3000;
	}
	
	RUB total_cost = easter_food + easter_gifts + easter_decorations;
	RUB alice_part = total_cost / 2;
	RUB john_part = total_cost - alice_part;
	
	if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
		alice.vtb.account_rub -= alice_part;
		john.vtb.account_rub -= john_part;
		hd.amount = total_cost;
		
		char desc[200];
		sprintf(desc, "Easter celebration in April: food %lld RUB, gifts %lld RUB, decorations %lld RUB",
				easter_food, easter_gifts, easter_decorations);
		hd.description = desc;
		
		sim_data.holidays.push_back(hd);
		
		if (!sim_data.months.empty()) {
			std::string event_desc = "Пасха (апрель): " + std::to_string(total_cost) + 
			" RUB (куличи, яйца, подарки, украшения)";
			sim_data.months.back().events.push_back(event_desc);
		}
	} else {
		RUB modest_cost = 3000;
		RUB modest_alice = modest_cost / 2;
		RUB modest_john = modest_cost - modest_alice;
		
		if (alice.vtb.account_rub >= modest_alice && john.vtb.account_rub >= modest_john) {
			alice.vtb.account_rub -= modest_alice;
			john.vtb.account_rub -= modest_john;
			hd.amount = modest_cost;
			hd.description = "Modest Easter celebration in April";
			sim_data.holidays.push_back(hd);
			
			if (!sim_data.months.empty()) {
				std::string event_desc = "Пасха (апрель, скромно): " + std::to_string(modest_cost) + " RUB";
				sim_data.months.back().events.push_back(event_desc);
			}
		}
	}
}


void  process_all_holidays(const int month, const int year) {
	new_year_gifts(month, year);
	valentines_day_gifts(month, year);
	february_23_gifts(month, year);
	march_8_gifts(month, year);
	victory_day(month, year);
	birthday_alice(month, year);
	anniversary_wedding(month, year);
	birthday_john(month, year);
	halloween(month, year);
	easter_celebration(month, year);
}


void  alice_charity_donation(const int month, const int year) {
	if (month != 12) return;
	
	CharityData cd;
	cd.name = "Alice's Charity";
	cd.amount = 0;
	
	if (alice.vtb.account_rub > 10000) {
		RUB donation = 5000;
		alice.vtb.account_rub -= donation;
		cd.amount = donation;
		cd.description = "Animal shelter donation";
	} else if (alice.vtb.account_rub > 5000) {
		RUB donation = 2000;
		alice.vtb.account_rub -= donation;
		cd.amount = donation;
		cd.description = "Small charity donation";
	}
	
	if (cd.amount > 0) sim_data.charities.push_back(cd);
}


void  john_parents_help(const int month, const int year) {
	if (!(month == 2 || month == 5 || month == 8 || month == 11)) return;
	
	CharityData cd;
	cd.name = "John's Parents Help";
	cd.amount = 0;
	
	if (john.vtb.account_rub > 30000) {
		RUB help_parents = 15000;
		john.vtb.account_rub -= help_parents;
		cd.amount = help_parents;
		cd.description = "Quarterly help to parents";
	} else if (john.vtb.account_rub > 15000) {
		RUB help_parents = 8000;
		john.vtb.account_rub -= help_parents;
		cd.amount = help_parents;
		cd.description = "Small help to parents";
	}
	
	if (cd.amount > 0) sim_data.charities.push_back(cd);
}


void  family_joint_charity(const int month, const int year) {
	if (!((month == 12 || month == 6) && year % 2 == 0)) return;
	
	RUB joint_charity = 7000;
	RUB alice_part = joint_charity / 2;
	RUB john_part = joint_charity / 2;
	
	if (alice.vtb.account_rub < alice_part || john.vtb.account_rub < john_part) return;
	
	alice.vtb.account_rub -= alice_part;
	john.vtb.account_rub -= john_part;
	
	CharityData cd;
	cd.name = "Family Charity";
	cd.amount = joint_charity;
	cd.description = "Children's hospital donation";
	sim_data.charities.push_back(cd);
}


void  alice_volunteering(const int month, const int year) {
	if (month == 4 || month == 11) {
		CharityData cd;
		cd.name = "Alice's Volunteering";
		cd.amount = 0;
		cd.description = (month == 4) ? "Library volunteering" : "Animal shelter volunteering";
		sim_data.charities.push_back(cd);
	}
}

void  john_volunteering(const int month, const int year) {
	if (month == 9 || month == 3) {
		CharityData cd;
		cd.name = "John's Volunteering";
		cd.amount = 0;
		cd.description = (month == 9) ? "Park cleanup" : "Snow removal for elderly";
		sim_data.charities.push_back(cd);
	}
}


void  process_all_charity(const int month, const int year) {
	alice_charity_donation(month, year);
	john_parents_help(month, year);
	family_joint_charity(month, year);
	alice_volunteering(month, year);
	john_volunteering(month, year);
}


void  family_health_and_medicine(const int month, const int year) {
	int alice_decline = rand() % 5 + 1;
	int john_decline = rand() % 7 + 2;
	
	switch (month) {
	case 12:
	case 1:
	case 2:
		alice_decline += 3;
		john_decline += 4;
		break;
	case 3:
	case 4:
		alice_decline += 2;
		john_decline += 2;
		break;
	}
	
	alice_health -= alice_decline;
	john_health -= john_decline;
	
	if (alice_health < 0) alice_health = 0;
	if (john_health < 0) john_health = 0;
	
	if (month == 10 || month == 4) {
		RUB vitamins_cost = 3000;
		RUB gym_membership = 5000;
		
		if (alice.vtb.account_rub >= vitamins_cost) {
			alice.vtb.account_rub -= vitamins_cost;
			alice_health += 5;
			if (alice_health > 100) alice_health = 100;
		}
		
		if (john.vtb.account_rub >= gym_membership) {
			john.vtb.account_rub -= gym_membership;
			john_health += 7;
			if (john_health > 100) john_health = 100;
		}
	}
	
	if (alice_health < 70) {
		RUB doctor_cost = 2500;
		doctor_visits_alice++;
		
		if (alice.vtb.account_rub >= doctor_cost) {
			alice.vtb.account_rub -= doctor_cost;
			alice_health += 15;
			if (alice_health > 100) alice_health = 100;
			
			RUB medicine = 1800;
			if (alice.vtb.account_rub >= medicine) {
				alice.vtb.account_rub -= medicine;
				alice_health += 5;
			}
		}
	}
	
	if (john_health < 65) {
		RUB doctor_cost = 3000;
		doctor_visits_john++;
		
		if (john.vtb.account_rub >= doctor_cost) {
			john.vtb.account_rub -= doctor_cost;
			john_health += 12;
			if (john_health > 100) john_health = 100;
		}
	}
	
	if (alice_health < 30) {
		RUB emergency_cost = 15000;
		
		if (alice.vtb.account_rub >= emergency_cost) {
			alice.vtb.account_rub -= emergency_cost;
			alice_health = 60;
		} else if (john.vtb.account_rub >= emergency_cost) {
			john.vtb.account_rub -= emergency_cost;
			alice_health = 60;
		}
	}
	
	if (john_health < 25) {
		RUB emergency_cost = 20000;
		
		if (john.vtb.account_rub >= emergency_cost) {
			john.vtb.account_rub -= emergency_cost;
			john_health = 55;
		} else if (alice.vtb.account_rub >= emergency_cost) {
			alice.vtb.account_rub -= emergency_cost;
			john_health = 55;
		}
	}
	
	RUB medicine_savings = 2000;
	if (month % 3 == 0) {
		if (alice.vtb.account_rub >= medicine_savings/2 && 
			john.vtb.account_rub >= medicine_savings/2) {
			alice.vtb.account_rub -= medicine_savings/2;
			john.vtb.account_rub -= medicine_savings/2;
			medicine_fund += medicine_savings;
		}
	}	
	
	HealthData hd;
	hd.alice_health = alice_health;
	hd.john_health = john_health;
	hd.medicine_fund = medicine_fund;
	hd.alice_visits = doctor_visits_alice;
	hd.john_visits = doctor_visits_john;
	hd.spent_on_medicine = medicine_fund;
	
	sim_data.health_history.push_back(hd);
	
	int year_index = year - 2026;
	
	if (year_index >= 0 && year_index < 4) {
		sim_data.yearly_doctor_visits_alice[year_index] = doctor_visits_alice;
		sim_data.yearly_doctor_visits_john[year_index] = doctor_visits_john;
		sim_data.yearly_medicine_spent[year_index] = medicine_fund;
	}
}


void  family_savings_goals(const int month, const int year) {
	static RUB vacation_goal = 200000;
	static RUB emergency_goal = 500000;
	static RUB big_purchase_goal = 150000;
	static RUB education_goal = 100000;
	
	RUB total_monthly_income = alice.salary + john.salary;
	RUB savings_per_month = (RUB)(total_monthly_income * 0.1);
	
	RUB to_vacation = (RUB)(savings_per_month * 0.3);
	RUB to_emergency = (RUB)(savings_per_month * 0.4);
	RUB to_big_purchase = (RUB)(savings_per_month * 0.2);
	RUB to_education = (RUB)(savings_per_month * 0.1);
	
	RUB alice_share = savings_per_month / 2;
	RUB john_share = savings_per_month / 2;
	
	if (alice.vtb.account_rub < alice_share || john.vtb.account_rub < john_share) {
		return;
	}
	
	alice.vtb.account_rub -= alice_share;
	john.vtb.account_rub -= john_share;
	
	vacation_fund += to_vacation;
	emergency_fund += to_emergency;
	big_purchase_fund += to_big_purchase;
	education_fund_local += to_education;
	
	if (month == 7 && vacation_fund >= vacation_goal) {
		vacation_fund = 0;
	}
	
	if (month == 11 && big_purchase_fund >= big_purchase_goal) {
		big_purchase_fund = 0;
	}
	
	if (month == 9 && education_fund_local >= education_goal) {
		education_fund_local = 0;
	}
	
	if (alice.vtb.account_rub < 10000 && emergency_fund > 0) {
		RUB needed = 20000 - alice.vtb.account_rub;
		if (needed > emergency_fund) needed = emergency_fund;
		emergency_fund -= needed;
		alice.vtb.account_rub += needed;
	}	
	
	if (john.vtb.account_rub < 10000 && emergency_fund > 0) {
		RUB needed = 20000 - john.vtb.account_rub;
		if (needed > emergency_fund) needed = emergency_fund;
		emergency_fund -= needed;
		john.vtb.account_rub += needed;
	}
	
	SavingsData sd;
	sd.vacation_fund = vacation_fund;
	sd.emergency_fund = emergency_fund;
	sd.big_purchase_fund = big_purchase_fund;
	sd.education_fund = education_fund_local;
	sd.vacation_goal = vacation_goal;
	sd.emergency_goal = emergency_goal;
	sd.big_purchase_goal = big_purchase_goal;
	sd.education_goal = education_goal;
	
	sim_data.savings_history.push_back(sd);
}


void  family_sports(const int month, const int year) {
	if (month == 1 || month == 6) {
		RUB membership = 4000;
		RUB total_cost = membership * 6;
		RUB alice_part = total_cost / 2;
		RUB john_part = total_cost / 2;
		
		if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
			alice.vtb.account_rub -= alice_part;
			john.vtb.account_rub -= john_part;
			sports_spent += total_cost;
		}
	}
	
	int alice_month = 8 + (rand() % 9);
	int john_month = 10 + (rand() % 8);
	
	alice_workouts += alice_month;
	john_workouts += john_month;
	
	if (month % 3 == 0) {
		RUB equipment = 2000 + (rand() % 4000);
		RUB alice_equip = equipment / 2;
		RUB john_equip = equipment - alice_equip;
		
		if (alice.vtb.account_rub >= alice_equip && john.vtb.account_rub >= john_equip) {
			alice.vtb.account_rub -= alice_equip;
			john.vtb.account_rub -= john_equip;
			sports_spent += equipment;
		}
	}
	
	SportsData sd;
	sd.alice_workouts = alice_workouts;
	sd.john_workouts = john_workouts;
	sd.spent_on_sports = sports_spent;
	
	sim_data.sports_history.push_back(sd);
}


void  family_real_estate(const int month, const int year) {
	if (year == 2027 && month == 3 && !bought_apartment) {
		RUB down_payment = (RUB)(apartment_value * 0.3);
		RUB alice_part = down_payment / 2;
		RUB john_part = down_payment / 2;
		
		if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
			alice.vtb.account_rub -= alice_part;
			john.vtb.account_rub -= john_part;
			mortgage_debt = apartment_value - down_payment;
			bought_apartment = true;
		}
	}
	
	static RUB mortgage_payment = 70000;
	
	if (bought_apartment && mortgage_debt > 0) {
		if (john.vtb.account_rub >= mortgage_payment) {
			john.vtb.account_rub -= mortgage_payment;
			mortgage_debt -= mortgage_payment;
			months_paid++;
		} else {
			RUB penalty = (RUB)(mortgage_payment * 0.1);
			mortgage_debt += penalty;
		}
	}
	
	static int last_valuation_year = 2026;
	if (year > last_valuation_year && month == 1) {
		float appreciation = 1.08;
		apartment_value = (RUB)(apartment_value * appreciation);
		last_valuation_year = year;
	}
	
	RealEstateData red;
	red.apartment_value = apartment_value;
	red.mortgage_debt = mortgage_debt;
	red.mortgage_paid = months_paid * 70000;
	red.months_paid = months_paid;
	red.bought = bought_apartment;
	
	sim_data.realestate_history.push_back(red);
}


void  family_education(const int month, const int year) {
	RUB monthly_education = 5000;
	RUB alice_part = monthly_education / 2;
	RUB john_part = monthly_education / 2;
	
	if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
		alice.vtb.account_rub -= alice_part;
		john.vtb.account_rub -= john_part;
		education_fund_global += monthly_education;
	}
	
	if (month == 2 || month == 9) {
		RUB course_cost = 15000;
		if (education_fund_global >= course_cost) {
			education_fund_global -= course_cost;
			spent_on_education += course_cost;
			alice_courses++;
			
			if (rand() % 100 < 30) {
				alice.salary += 5000;
			}
		}
	}	
	
	if (month == 4 || month == 10) {
		RUB course_cost = 20000;
		if (education_fund_global >= course_cost) {
			education_fund_global -= course_cost;
			spent_on_education += course_cost;
			john_courses++;
			
			if (rand() % 100 < 40) {
				john.salary += 10000;
			}
		}
	}
	
	EducationData ed;
	ed.education_fund = education_fund_global;
	ed.alice_courses = alice_courses;
	ed.john_courses = john_courses;
	ed.spent = spent_on_education;
	
	sim_data.education_history.push_back(ed);
}


void  family_travel(const int month, const int year) {
	RUB monthly_income = alice.salary + john.salary;
	RUB travel_savings = (RUB)(monthly_income * 0.05);
	RUB alice_part = travel_savings / 2;
	RUB john_part = travel_savings / 2;	
	
	if (alice.vtb.account_rub >= alice_part && john.vtb.account_rub >= john_part) {
		alice.vtb.account_rub -= alice_part;
		john.vtb.account_rub -= john_part;
		travel_fund += travel_savings;
	}
	
	if (month == 7 && travel_fund >= 100000) {
		RUB trip_cost = 80000 + (rand() % 40000);
		if (travel_fund >= trip_cost) {
			travel_fund -= trip_cost;
			spent_on_travel += trip_cost;
			trips_taken++;
		}
	}
	
	if (month == 1 && travel_fund >= 70000) {
		RUB trip_cost = 60000 + (rand() % 30000);
		if (travel_fund >= trip_cost) {
			travel_fund -= trip_cost;
			spent_on_travel += trip_cost;
			trips_taken++;
		}
	}
	
	TravelData td;
	td.travel_fund = travel_fund;
	td.trips_taken = trips_taken;
	td.spent = spent_on_travel;
	
	sim_data.travel_history.push_back(td);
}


void  check_goals() {
	if (vacation_fund >= 200000) {
		printf("[GOAL ACHIEVED] Vacation fund target reached: %lld RUB\n", vacation_fund);
	}
	if (emergency_fund >= 500000) {
		printf("[GOAL ACHIEVED] Emergency fund target reached: %lld RUB\n", emergency_fund);
	}
	if (big_purchase_fund >= 150000) {
		printf("[GOAL ACHIEVED] Big purchase fund target reached: %lld RUB\n", big_purchase_fund);
	}
	if (education_fund_local >= 100000) {
		printf("[GOAL ACHIEVED] Education fund target reached: %lld RUB\n", education_fund_local);
	}
}


void check_milestones(int current_month, int current_year) {
	static RUB last_alice_milestone = 0;
	static RUB last_john_milestone = 0;
	
	RUB alice_total = alice.vtb.account_rub + alice.vtb.account_usd * 78.76;
	RUB john_total = john.vtb.account_rub + john.vtb.account_usd * 78.76;
	
	// Проверка достижения круглых сумм (каждые 100k RUB)
	if (alice_total / 100000 > last_alice_milestone / 100000) {
		printf("[MILESTONE] Alice reached %lld RUB!\n", alice_total);
		last_alice_milestone = alice_total;
	}
	
	if (john_total / 100000 > last_john_milestone / 100000) {
		printf("[MILESTONE] John reached %lld RUB!\n", john_total);
		last_john_milestone = john_total;
	}
	
	// Проверка погашения кредитов
	static bool alice_credit_notified = false;
	static bool john_credit_notified = false;
	
	if (!alice_credit_notified && alice.credit.debt == 0 && alice.debt_initial > 0) {
		printf("[MILESTONE] Alice fully paid off her credit!\n");
		alice_credit_notified = true;
	}
	
	if (!john_credit_notified && john.credit.debt == 0 && john.debt_initial > 0) {
		printf("[MILESTONE] John fully paid off his credit!\n");
		john_credit_notified = true;
	}
}


void  print_monthly_summary(int current_month, int current_year) {
	printf("\n========== %d/%d SUMMARY ==========\n", current_month, current_year);
	
	RUB alice_total = alice.vtb.account_rub + alice.vtb.account_usd * 78.76;
	RUB john_total = john.vtb.account_rub + john.vtb.account_usd * 78.76;
	RUB family_total = alice_total + john_total;
	
	printf("Alice: %lld RUB (%.1f%%)\n", alice_total, (float)alice_total / family_total * 100);
	printf("John: %lld RUB (%.1f%%)\n", john_total, (float)john_total / family_total * 100);
	printf("Family total: %lld RUB\n", family_total);
	
	if (alice.credit.debt > 0) {
		printf("Alice debt: %lld RUB\n", alice.credit.debt);
	}
	if (john.credit.debt > 0) {
		printf("John debt: %lld RUB\n", john.credit.debt);
	}
	if (mortgage_debt > 0) {
		printf("Mortgage debt: %lld RUB\n", mortgage_debt);
	}
	
	printf("Health: Alice %d%%, John %d%%\n", alice_health, john_health);
	printf("==================================\n");
}


void  record_month_data() {
	MonthData md;
	md.year = year;
	md.month = month;
	
	md.alice_account_rub = alice.vtb.account_rub;
	md.alice_account_usd = alice.vtb.account_usd;
	md.alice_debt = alice.credit.debt;
	md.alice_car_value = alice.car.value;
	md.alice_food = alice.food;
	md.alice_credit_paid = 0;
	md.alice_early_payment = 0;
	md.alice_invest_amount = 0;
	md.alice_invest_result = 0;
	
	md.john_account_rub = john.vtb.account_rub;
	md.john_account_usd = john.vtb.account_usd;
	md.john_debt = john.credit.debt;
	md.john_car_value = john.car.value;
	md.john_food = john.food;
	md.john_salary = john.salary;
	md.john_credit_paid = 0;
	md.john_early_payment = 0;
	md.john_invest_amount = 0;
	md.john_invest_result = 0;
	
	sim_data.months.push_back(md);
}


void  simulation() {
	year = 2026;
	month = 2;
	
	record_month_data();
	
	int months_passed = 0;
	
	while (!(year == 2029 && month == 2)) {
		family_utilities(month, year);
		
		process_all_holidays(month, year);
		process_all_charity(month, year);
		
		family_health_and_medicine(month, year);
		family_savings_goals(month, year);
		check_goals();
		
		family_sports(month, year);
		family_real_estate(month, year);
		family_education(month, year);
		family_travel(month, year);
		
		alice_credit(year, month);
		alice_salary(month, year);
		alice_car();
		alice_food(month, year);
		alice_early_credit_payment();
		alice_invest();
		alice_car_transaction(month, year);
		
		john_credit(year, month);
		john_salary(month, year);
		john_car();
		john_food(month, year);
		john_early_credit_payment();
		john_invest();
		john_car_transaction(month, year);
		
		record_month_data();
		check_milestones(month, year);
		
		// Вывод ежемесячного отчёта
		print_monthly_summary(month, year);
		
		months_passed++;
		
		++month;
		if (month == 13) {
			++year;
			month = 1;
		}    
	}
}


void  print_final_report() {
	printf("\n==================== FINAL REPORT ====================\n");
	printf("Simulation: 2026-2029\n\n");
	
	MonthData& last = sim_data.months.back();
	
	printf("========== FINAL STATUS ==========\n");
	printf("\n--- ALICE ---\n");
	printf("  Account: %lld RUB, %lld USD\n", last.alice_account_rub, last.alice_account_usd);
	printf("  Credit debt: %lld RUB\n", last.alice_debt);
	printf("  Car value: %lld RUB\n", last.alice_car_value);
	
	printf("\n--- JOHN ---\n");
	printf("  Account: %lld RUB, %lld USD\n", last.john_account_rub, last.john_account_usd);
	printf("  Credit debt: %lld RUB\n", last.john_debt);
	printf("  Car value: %lld RUB\n", last.john_car_value);
	printf("  Salary: %lld RUB\n", last.john_salary);
	
	RUB family_total = last.alice_account_rub + last.john_account_rub + 
	(RUB)((last.alice_account_usd + last.john_account_usd) * 78.76);
	printf("\n--- FAMILY ---\n");
	printf("  Total capital: %lld RUB\n", family_total);
	
	printf("\n========== YEARLY STATISTICS ==========\n");
	for (int y = 0; y < 4; y++) {
		if (sim_data.yearly_utilities[y] > 0) {
			printf("\n%d:\n", 2026 + y);
			printf("  Utilities: %lld RUB\n", sim_data.yearly_utilities[y]);
			printf("  Doctor visits: Alice - %d, John - %d\n", 
				   sim_data.yearly_doctor_visits_alice[y], 
				   sim_data.yearly_doctor_visits_john[y]);
			printf("  Spent on medicine: %lld RUB\n", sim_data.yearly_medicine_spent[y]);
		}
	}
	
	printf("\n========== HOLIDAYS ==========\n");
	RUB total_holidays = 0;
	
	for (const auto& h : sim_data.holidays) {
		printf("  %s: %lld RUB - %s\n", h.name.c_str(), h.amount, h.description.c_str());
		total_holidays += h.amount;
	}
	printf("  Total spent on holidays: %lld RUB\n", total_holidays);
	
	printf("\n========== CHARITY ==========\n");
	RUB total_charity = 0;
	for (const auto& c : sim_data.charities) {
		if (c.amount > 0) {
			printf("  %s: %lld RUB - %s\n", c.name.c_str(), c.amount, c.description.c_str());
			total_charity += c.amount;
		} else {
			printf("  %s: %s (no money)\n", c.name.c_str(), c.description.c_str());
		}
	}
	printf("  Total donated: %lld RUB\n", total_charity);
	
	if (!sim_data.health_history.empty()) {
		HealthData& last_h = sim_data.health_history.back();
		printf("\n========== HEALTH ==========\n");
		printf("  Alice: %d%%\n", last_h.alice_health);
		printf("  John: %d%%\n", last_h.john_health);
		printf("  Medicine fund: %lld RUB\n", last_h.medicine_fund);
	}
	
	if (!sim_data.savings_history.empty()) {
		SavingsData& last_s = sim_data.savings_history.back();
		printf("\n========== SAVINGS ==========\n");
		printf("  Vacation fund: %lld / %lld RUB\n", last_s.vacation_fund, last_s.vacation_goal);
		printf("  Emergency fund: %lld / %lld RUB\n", last_s.emergency_fund, last_s.emergency_goal);
		printf("  Big purchases: %lld / %lld RUB\n", last_s.big_purchase_fund, last_s.big_purchase_goal);
		printf("  Education: %lld / %lld RUB\n", last_s.education_fund, last_s.education_goal);
	}
	
	if (!sim_data.sports_history.empty()) {
		SportsData& last_sp = sim_data.sports_history.back();
		printf("\n========== SPORTS ==========\n");
		printf("  Total workouts: Alice - %d, John - %d\n", 
			   last_sp.alice_workouts, last_sp.john_workouts);
		printf("  Spent on sports: %lld RUB\n", last_sp.spent_on_sports);
	}
	
	if (!sim_data.realestate_history.empty()) {
		RealEstateData& last_re = sim_data.realestate_history.back();
		printf("\n========== REAL ESTATE ==========\n");
		if (last_re.bought) {
			printf("  Apartment purchased!\n");
			printf("  Apartment value: %lld RUB\n", last_re.apartment_value);
			printf("  Mortgage remaining: %lld RUB\n", last_re.mortgage_debt);
			printf("  Months paid: %d\n", last_re.months_paid);
		} else {
			printf("  Apartment not purchased\n");
		}
	}
	
	if (!sim_data.education_history.empty()) {
		EducationData& last_e = sim_data.education_history.back();
		printf("\n========== EDUCATION ==========\n");
		printf("  Courses completed: Alice - %d, John - %d\n", 
			   last_e.alice_courses, last_e.john_courses);
		printf("  Spent on education: %lld RUB\n", last_e.spent);
		printf("  Remaining in fund: %lld RUB\n", last_e.education_fund);
	}
	
	if (!sim_data.travel_history.empty()) {
		TravelData& last_t = sim_data.travel_history.back();
		printf("\n========== TRAVEL ==========\n");
		printf("  Total trips: %d\n", last_t.trips_taken);
		printf("  Spent on travel: %lld RUB\n", last_t.spent);
		printf("  Remaining in fund: %lld RUB\n", last_t.travel_fund);
	}
	
	
	printf("\n========== MONTHLY DYNAMICS ==========\n");
	int total_months = (int)sim_data.months.size();
	printf("\nFirst 3 months:\n");
	for (int i = 0; i < 3 && i < total_months; i++) {
		MonthData& m = sim_data.months[i];
		printf("  %d/%d: Family: %lld RUB (Alice: %lld, John: %lld)\n", 
			   m.month, m.year,
			   m.alice_account_rub + m.john_account_rub,
			   m.alice_account_rub, m.john_account_rub);
	}
	
	printf("\nLast 3 months:\n");
	for (int i = total_months - 3; i < total_months; i++) {
		if (i >= 0) {
			MonthData& m = sim_data.months[i];
			printf("  %d/%d: Family: %lld RUB (Alice: %lld, John: %lld)\n", 
				   m.month, m.year,
				   m.alice_account_rub + m.john_account_rub,
				   m.alice_account_rub, m.john_account_rub);
		}
	}
	
	printf("\n==================== END OF REPORT ====================\n");
}


int main() {
	srand((unsigned int)time(NULL));
	
	alice_init();
	john_init();
	
	printf("=== FAMILY FINANCIAL SIMULATOR ===\n");
	printf("Alice and John - John pays for utilities\n\n");
	printf("Simulating 2026-2029...\n");
	
	simulation();
	
	print_final_report();
	
	return 0;    
}
