#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

using RUB = long long int;
using Percent = double;

const Percent INFLATION_FOOD = 5.0;
const Percent INFLATION_UTILITIES = 6.0;
const Percent INFLATION_GAS = 4.5;
const Percent INFLATION_OTHER = 4.0;

struct Cat {
	RUB food_per_month;
	RUB litter_per_month;		//наполнитель
	RUB vet_annual;			//раз в гож
	RUB toys_annual;
	RUB emergency_vet_min;
	RUB emergency_vet_max;
	RUB total_spent_food;
	RUB total_spent_vet;
	RUB total_spent_other;
	int age_months;
	bool is_alive;
	int emergency_vet_visits;		//счетчик - int
	int happy_events;		//интерестная идея :)
	RUB total_saved_from_lost;
};

struct Car {
	RUB current_value;		//ntc cnjbvjcnm
	RUB gas_per_month;
	RUB gas_price_per_liter;
	RUB insurance_per_year;
	RUB maintenance_per_year;
	RUB tire_change_per_season;
	RUB winter_tires_set;
	RUB summer_tires_set;
	int tires_age_years;
	RUB repair_min;
	RUB repair_max;
	RUB total_spent_gas;
	RUB total_spent_insurance;
	RUB total_spent_maintenance;			//TO
	RUB total_spent_tires;
	RUB total_spent_repairs;
	RUB total_spent_tax;
	RUB tax_per_year;
	int age_years;
	int months_since_service;
	RUB washing_per_year;
	RUB total_spent_washing;
	int total_repairs_count;
	int total_tire_sets_bought;
	int fines_count;		//Штраф
	RUB total_fines;
	int accidents_count;		//ДТП
	RUB total_accident_damage;
};

struct Mortgage {
	RUB total_amount;		//общая сумма
	RUB monthly_payment;
	Percent interest_rate;		//ставка год
	RUB remaining;		//S-P
	RUB total_paid;		//XP
	int months_left;	//n-nP
	bool is_paid_off;
	int paid_off_month;
	int paid_off_year;
	RUB early_repayment_total;
	int early_repayments_count;		//досрок
};

struct OzonPVZ {
	bool is_opened;
	int opened_month;
	int opened_year;
	RUB initial_investment;
	RUB rent_per_month;
	RUB utilities_per_month;
	RUB salary_per_employee;
	int employee_count;
	RUB supplies_per_month;
	RUB base_revenue_per_month;
	RUB bonus_per_register;
	int avg_new_clients_per_month;
	Percent growth_rate;	//рост клиентов
	int current_clients;		
	double season_multiplier[13];		//1-13
	Percent return_rate;
	RUB return_penalty_per_item;		//штраф за возрат
	int avg_items_per_client;
	RUB total_invested;
	RUB total_revenue;		//доходы
	RUB total_expenses;		//расходы
	RUB total_returns_penalty;
	RUB total_bonuses;
	int total_clients_served;
	int total_items_issued;
	int total_returns;
	int months_operated;
	int profitable_months;
	int unprofitable_months;
	RUB best_month_revenue;
	RUB worst_month_revenue;
	int best_month;
	int best_year;
	int worst_month;
	int worst_year;
	int employee_quits_count;
	int new_employees_hired;
	int positive_events;
	int negative_events;
	RUB max_single_expense;
	RUB max_single_revenue;		// разовый взлет
};

struct FamilyBudget {
	RUB account;		//нал
	RUB savings;
	Percent savings_interest;
	RUB total_earned;		//заработок
	RUB total_spent;
	RUB total_taxes_paid;
	RUB emergency_fund;
	RUB total_transferred_to_savings;
};

struct Housing {
	RUB utilities_per_month;
	RUB internet_per_month;
	RUB repairs_annual;
	RUB furniture_annual;
	RUB total_spent_utilities;
	RUB total_spent_internet;
	RUB total_spent_repairs;
	RUB total_spent_furniture;
	RUB household_chemicals_per_month;
	RUB total_spent_chemicals;
	int emergency_repairs_count;
	int renovations_count;
	RUB total_emergency_repairs;
};

struct John {
	RUB salary_per_month;
	RUB bonus_per_year;		//премия (grant)
	Percent income_tax_rate;
	Percent salary_growth;		//прирост зарплаы
	RUB total_earned_salary;
	RUB total_earned_bonus;
	RUB total_taxes_paid;
	int months_worked;
	int promotions_count;		//колво повышений
	RUB max_salary;
	int sick_days_this_year;		//болезнь
	RUB lost_income_from_sick;
};

struct Alice {
	RUB salary_per_month;
	Percent income_tax_rate;		//ндфл
	RUB total_earned_salary;
	RUB total_taxes_paid;
	bool quit_job;
	int quit_month;
	int quit_year;
	int months_worked_before_quit;
};

struct Entertainment {
	RUB restaurants_per_month;
	RUB cinema_per_month;
	RUB hobbies_per_month;
	RUB vacation_per_year;
	RUB total_spent_restaurants;
	RUB total_spent_movies;
	RUB total_spent_hobbies;
	RUB total_spent_vacation;
	int vacations_taken;		//отпуск
	int concerts_attended;
	RUB total_spent_concerts;
};

struct Health {
	RUB medicine_per_month;
	RUB dentist_per_year;
	RUB gym_per_month;
	RUB total_spent_medicine;
	RUB total_spent_dentist;
	RUB total_spent_gym;
};

struct Gifts {
	RUB birthday_gifts_per_year;
	RUB new_year_gifts_per_year;
	RUB other_holidays_per_year;
	RUB total_spent_gifts;
};

struct Subscriptions {
	RUB netflix_per_month;
	RUB spotify_per_month;
	RUB youtube_per_month;
	RUB cloud_storage_per_month;
	RUB total_spent_subscriptions;
};

struct Clothing {
	RUB clothes_per_season;
	RUB shoes_per_year;
	RUB total_spent_clothes;
	RUB total_spent_shoes;
};

struct Education {
	RUB courses_per_year;
	RUB books_per_month;
	RUB total_spent_courses;
	RUB total_spent_books;
};

struct Transport {
	RUB public_transport_per_month;
	RUB taxi_per_month;
	RUB total_spent_public;
	RUB total_spent_taxi;
};

struct Charity {
	RUB donations_per_year;
	RUB total_spent_charity;
};

struct Insurance {
	RUB life_insurance_per_year;
	RUB property_insurance_per_year;
	RUB total_spent_life;
	RUB total_spent_property;
};

//для удобства

Cat barsik;
Car lada;
Mortgage mortgage;
OzonPVZ pvz;
FamilyBudget family;
Housing housing;
John john;
Alice alice;
Entertainment fun;
Health health;
Gifts gifts;
Subscriptions subs;
Clothing clothes;
Education edu;
Transport transport;
Charity charity;
Insurance insurance;

//////////////////////////////////
//////////////////////////////////

int cur_month = 1;
int cur_year = 2026;

//////////////////////////////////
//////////////////////////////////

void print_date() {
	const char* months[] = {
		"", "Янв", "Фев", "Мар", "Апр", "Май", "Июн",
		"Июл", "Авг", "Сен", "Окт", "Ноя", "Дек"
	};
	printf("[%s %d] ", months[cur_month], cur_year);
}

void init_barsik() {
	barsik.food_per_month = 3'500;
	barsik.litter_per_month = 1'500;
	barsik.vet_annual = 8'000;
	barsik.toys_annual = 5'000;
	barsik.emergency_vet_min = 3'000;
	barsik.emergency_vet_max = 25'000;
	barsik.total_spent_food = 0;
	barsik.total_spent_vet = 0;
	barsik.total_spent_other = 0;
	barsik.age_months = 24;
	barsik.is_alive = true;
	barsik.emergency_vet_visits = 0;
	barsik.happy_events = 0;
	barsik.total_saved_from_lost = 0;
}

void init_lada() {
	lada.current_value = 2'800'000;
	lada.gas_per_month = 8'000;
	lada.gas_price_per_liter = 70;
	lada.insurance_per_year = 25'000;
	lada.maintenance_per_year = 55'000;
	lada.tire_change_per_season = 3'000;
	lada.winter_tires_set = 35'000;
	lada.summer_tires_set = 30'000;
	lada.tires_age_years = 2;
	lada.repair_min = 2'000;
	lada.repair_max = 250'000;
	lada.total_spent_gas = 0;
	lada.total_spent_insurance = 0;
	lada.total_spent_maintenance = 0;
	lada.total_spent_tires = 0;
	lada.total_spent_repairs = 0;
	lada.total_spent_tax = 0;
	lada.tax_per_year = 4'500;
	lada.age_years = 0;
	lada.months_since_service = 0;
	lada.washing_per_year = 12'000;
	lada.total_spent_washing = 0;
	lada.total_repairs_count = 0;
	lada.total_tire_sets_bought = 0;
	lada.fines_count = 0;
	lada.total_fines = 0;
	lada.accidents_count = 0;
	lada.total_accident_damage = 0;
}

void init_mortgage() {
	mortgage.total_amount = 16'000'000;
	mortgage.interest_rate = 10.5;
	mortgage.months_left = 180;
	mortgage.remaining = mortgage.total_amount;
	mortgage.total_paid = 0;
	mortgage.is_paid_off = false;
	mortgage.paid_off_month = 0;
	mortgage.paid_off_year = 0;
	mortgage.early_repayment_total = 0;
	mortgage.early_repayments_count = 0;
	
	double monthly_rate = mortgage.interest_rate / 100.0 / 12.0;
	double factor = pow(1.0 + monthly_rate, mortgage.months_left);
	mortgage.monthly_payment = static_cast<RUB>(
		mortgage.total_amount * (monthly_rate * factor) / (factor - 1.0)
												);
}

void init_pvz() {
	pvz.is_opened = false;
	pvz.opened_month = 0;
	pvz.opened_year = 0;
	pvz.initial_investment = 500'000;
	pvz.rent_per_month = 35'000;
	pvz.utilities_per_month = 5'000;
	pvz.salary_per_employee = 55'000;
	pvz.employee_count = 2;
	pvz.supplies_per_month = 3'000;
	pvz.base_revenue_per_month = 100'000;
	pvz.bonus_per_register = 200;
	pvz.avg_new_clients_per_month = 30;
	pvz.growth_rate = 2.0;
	pvz.current_clients = 0;
	
	pvz.season_multiplier[0] = 0.0;
	pvz.season_multiplier[1] = 0.3;
	pvz.season_multiplier[2] = 0.45;
	pvz.season_multiplier[3] = 0.9;
	pvz.season_multiplier[4] = 0.95;
	pvz.season_multiplier[5] = 1.0;
	pvz.season_multiplier[6] = 0.95;
	pvz.season_multiplier[7] = 0.9;
	pvz.season_multiplier[8] = 0.45;
	pvz.season_multiplier[9] = 1.5;
	pvz.season_multiplier[10] = 1.15;
	pvz.season_multiplier[11] = 1.5;
	pvz.season_multiplier[12] = 2.0;
	
	pvz.return_rate = 10.0;
	pvz.return_penalty_per_item = 150;
	pvz.avg_items_per_client = 3;
	
	pvz.total_invested = 0;
	pvz.total_revenue = 0;
	pvz.total_expenses = 0;
	pvz.total_returns_penalty = 0;
	pvz.total_bonuses = 0;
	pvz.total_clients_served = 0;
	pvz.total_items_issued = 0;
	pvz.total_returns = 0;
	pvz.months_operated = 0;
	pvz.profitable_months = 0;
	pvz.unprofitable_months = 0;
	pvz.best_month_revenue = 0;
	pvz.worst_month_revenue = 10000000000;
	pvz.best_month = 0;
	pvz.best_year = 0;
	pvz.worst_month = 0;
	pvz.worst_year = 0;
	pvz.employee_quits_count = 0;
	pvz.new_employees_hired = 0;
	pvz.positive_events = 0;
	pvz.negative_events = 0;
	pvz.max_single_expense = 0;
	pvz.max_single_revenue = 0;
}

void init_family_budget() {
	family.account = 500'000;
	family.savings = 750'000;
	family.savings_interest = 8.0;
	family.total_earned = 0;
	family.total_spent = 0;
	family.total_taxes_paid = 0;
	family.emergency_fund = 200'000;
	family.total_transferred_to_savings = 0;
}

void init_housing() {
	housing.utilities_per_month = 25'000;
	housing.internet_per_month = 1'000;
	housing.repairs_annual = 50'000;
	housing.furniture_annual = 60'000;
	housing.total_spent_utilities = 0;
	housing.total_spent_internet = 0;
	housing.total_spent_repairs = 0;
	housing.total_spent_furniture = 0;
	housing.household_chemicals_per_month = 2'000;
	housing.total_spent_chemicals = 0;
	housing.emergency_repairs_count = 0;
	housing.renovations_count = 0;
	housing.total_emergency_repairs = 0;
}

void init_john() {
	john.salary_per_month = 150'000;
	john.bonus_per_year = 200'000;
	john.income_tax_rate = 13.0;
	john.salary_growth = 7.0;
	john.total_earned_salary = 0;
	john.total_earned_bonus = 0;
	john.total_taxes_paid = 0;
	john.months_worked = 0;
	john.promotions_count = 0;
	john.max_salary = 150'000;
	john.sick_days_this_year = 0;
	john.lost_income_from_sick = 0;
}

void init_alice() {
	alice.salary_per_month = 90'000;
	alice.income_tax_rate = 13.0;
	alice.total_earned_salary = 0;
	alice.total_taxes_paid = 0;
	alice.quit_job = false;
	alice.quit_month = 0;
	alice.quit_year = 0;
	alice.months_worked_before_quit = 0;
}

void init_entertainment() {
	fun.restaurants_per_month = 4'000;
	fun.cinema_per_month = 2'000;
	fun.hobbies_per_month = 2'000;
	fun.vacation_per_year = 70'000;
	fun.total_spent_restaurants = 0;
	fun.total_spent_movies = 0;
	fun.total_spent_hobbies = 0;
	fun.total_spent_vacation = 0;
	fun.vacations_taken = 0;
	fun.concerts_attended = 0;
	fun.total_spent_concerts = 0;
}

void init_health() {
	health.medicine_per_month = 3'000;
	health.dentist_per_year = 15'000;
	health.gym_per_month = 4'000;
	health.total_spent_medicine = 0;
	health.total_spent_dentist = 0;
	health.total_spent_gym = 0;
}

void init_gifts() {
	gifts.birthday_gifts_per_year = 30'000;
	gifts.new_year_gifts_per_year = 25'000;
	gifts.other_holidays_per_year = 15'000;
	gifts.total_spent_gifts = 0;
}

void init_subs() {
	subs.netflix_per_month = 800;
	subs.spotify_per_month = 300;
	subs.youtube_per_month = 400;
	subs.cloud_storage_per_month = 200;
	subs.total_spent_subscriptions = 0;
}

void init_clothes() {
	clothes.clothes_per_season = 20'000;
	clothes.shoes_per_year = 15'000;
	clothes.total_spent_clothes = 0;
	clothes.total_spent_shoes = 0;
}

void init_edu() {
	edu.courses_per_year = 15'000;
	edu.books_per_month = 676;
	edu.total_spent_courses = 0;
	edu.total_spent_books = 0;
}

void init_transport() {
	transport.public_transport_per_month = 6'000;
	transport.taxi_per_month = 500;
	transport.total_spent_public = 0;
	transport.total_spent_taxi = 0;
}

void init_charity() {
	charity.donations_per_year = 5'000;
	charity.total_spent_charity = 0;
}

void init_insurance_new() {
	insurance.life_insurance_per_year = 30'000;
	insurance.property_insurance_per_year = 15'000;
	insurance.total_spent_life = 0;
	insurance.total_spent_property = 0;
}

void init_all() {
	init_barsik();
	init_lada();
	init_mortgage();
	init_pvz();
	init_family_budget();
	init_housing();
	init_john();
	init_alice();
	init_entertainment();
	init_health();
	init_gifts();
	init_subs();
	init_clothes();
	init_edu();
	init_transport();
	init_charity();
	init_insurance_new();
}

void john_salary() {
	if (cur_month == 1 && cur_year > 2026) {
		john.salary_per_month = static_cast<RUB>(
			 john.salary_per_month * (1.0 + john.salary_growth / 100.0)
			);
		if (john.salary_per_month > john.max_salary) {
			john.max_salary = john.salary_per_month;
		}
	}
	
	if (cur_month == 6 && cur_year == 2029) {
		john.salary_per_month = static_cast<RUB>(john.salary_per_month * 1.2);
		john.promotions_count = john.promotions_count + 1;
		printf("[ДЖОН] Повышение. Зарплата увеличена на 20%%\n");
	}
	
	if (cur_month == 6 && cur_year == 2034) {
		john.salary_per_month = static_cast<RUB>(john.salary_per_month * 1.25);
		john.promotions_count = john.promotions_count + 1;
		printf("[ДЖОН] Повышение еще +25%%\n");
	}
	
	john.sick_days_this_year = 0;
	int sick_chance = rand() % 100;
	if (sick_chance < 8) {
		int sick_days = 1 + (rand() % 5);
		john.sick_days_this_year = sick_days;
		RUB lost = static_cast<RUB>(john.salary_per_month / 22.0 * sick_days * 0.4);
		john.lost_income_from_sick = john.lost_income_from_sick + lost;
	}
	
	RUB gross = john.salary_per_month;
	gross = gross - static_cast<RUB>(john.salary_per_month / 22.0 * john.sick_days_this_year * 0.4);
	
	if (cur_month == 12) {
		gross = gross + john.bonus_per_year;
		john.total_earned_bonus = john.total_earned_bonus + john.bonus_per_year;
		if (cur_year > 2026) {
			john.bonus_per_year = static_cast<RUB>(
				 john.bonus_per_year * (1.0 + john.salary_growth / 100.0)
			);
		}
	}
	
	RUB tax = static_cast<RUB>(gross * john.income_tax_rate / 100.0);
	RUB net = gross - tax;
	
	family.account = family.account + net;
	family.total_earned = family.total_earned + net;
	family.total_taxes_paid = family.total_taxes_paid + tax;
	john.total_earned_salary = john.total_earned_salary + john.salary_per_month;
	john.total_taxes_paid = john.total_taxes_paid + tax;
	john.months_worked = john.months_worked + 1;
}

void alice_salary() {
	if (alice.quit_job) {
		return;
	}
	
	if (cur_month == 1 && cur_year > 2026) {
		alice.salary_per_month = static_cast<RUB>(
			 alice.salary_per_month * (1.0 + 3.0 / 100.0)
		  );
	}
	
	RUB gross = alice.salary_per_month;
	RUB tax = static_cast<RUB>(gross * alice.income_tax_rate / 100.0);
	RUB net = gross - tax;
	
	family.account = family.account + net;
	family.total_earned = family.total_earned + net;
	family.total_taxes_paid = family.total_taxes_paid + tax;
	alice.total_earned_salary = alice.total_earned_salary + gross;
	alice.total_taxes_paid = alice.total_taxes_paid + tax;
	alice.months_worked_before_quit = alice.months_worked_before_quit + 1;
}

void savings_interest() {
	if (family.savings > 0) {
		RUB interest = static_cast<RUB>(
			family.savings * (family.savings_interest / 100.0 / 12.0)
		);
		family.savings = family.savings + interest;
		family.total_earned = family.total_earned + interest;
	}
	
	if (cur_month == 1 && cur_year > 2026) {
		double delta = (rand() % 100 - 40) / 100.0;
		family.savings_interest = family.savings_interest + delta;
		if (family.savings_interest < 3.0) family.savings_interest = 3.0;
		if (family.savings_interest > 12.0) family.savings_interest = 12.0;
	}
	
	if (family.account > 100'000) {
		RUB transfer = family.account - 100'000;
		family.savings = family.savings + transfer;
		family.account = family.account - transfer;
		family.total_transferred_to_savings = family.total_transferred_to_savings + transfer;
	}
	
	if (family.account < 0 && family.savings > 0) {
		RUB needed = -family.account;
		if (family.savings >= needed) {
			family.savings = family.savings - needed;
			family.account = 0;
		}
	}
}

void pvz_open() {
	if (cur_year == 2027 && cur_month == 3 && pvz.is_opened == false) {
		if (family.savings >= pvz.initial_investment) {
			family.savings = family.savings - pvz.initial_investment;
			family.total_spent = family.total_spent + pvz.initial_investment;
			pvz.total_invested = pvz.total_invested + pvz.initial_investment;
			
			pvz.is_opened = true;
			pvz.opened_month = cur_month;
			pvz.opened_year = cur_year;
			pvz.current_clients = 50;
			
			alice.quit_job = true;
			alice.quit_month = cur_month;
			alice.quit_year = cur_year;
			
		
			printf("ОТКРЫТИЕ ПВЗ\n");
			printf("Дата: %d.%d\n", cur_month, cur_year);
			printf("Вложения: %lld руб.\n", pvz.initial_investment);
			printf("Алиса уволилась и управляет ПВЗ\n");
			printf("Начальная база клиентов: %d\n", pvz.current_clients);
		
		} else {
			printf("[ПВЗ] Не хватает средств Нужно: %lld, накоплено: %lld\n",
				   pvz.initial_investment, family.savings);
		}
	}
}

void pvz_revenue() {
	if (pvz.is_opened == false) {
		return;
	}
	
	int clients_this_month = pvz.current_clients;
	if (clients_this_month < 10) {
		clients_this_month = 10;
	}
	
	double season = pvz.season_multiplier[cur_month];
	
	RUB revenue = static_cast<RUB>(
	 pvz.base_revenue_per_month * season * (clients_this_month / 100.0)
	 );
	
	int new_clients = pvz.avg_new_clients_per_month;
	
	if (cur_month == 11 || cur_month == 12) {
		new_clients = static_cast<int>(new_clients * 1.5);
	}
	
	RUB bonus_revenue = new_clients * pvz.bonus_per_register;
	RUB total_revenue = revenue + bonus_revenue;
	
	int total_items = clients_this_month * pvz.avg_items_per_client;
	int returns_count = static_cast<int>(total_items * pvz.return_rate / 100.0);
	RUB returns_penalty = returns_count * pvz.return_penalty_per_item;
	
	RUB net_revenue = total_revenue - returns_penalty;
	
	family.account = family.account + net_revenue;
	family.total_earned = family.total_earned + net_revenue;
	
	pvz.total_revenue = pvz.total_revenue + total_revenue;
	pvz.total_returns_penalty = pvz.total_returns_penalty + returns_penalty;
	pvz.total_bonuses = pvz.total_bonuses + bonus_revenue;
	pvz.total_clients_served = pvz.total_clients_served + clients_this_month;
	pvz.total_items_issued = pvz.total_items_issued + total_items;
	pvz.total_returns = pvz.total_returns + returns_count;
	pvz.current_clients = pvz.current_clients + new_clients;
	pvz.months_operated = pvz.months_operated + 1;
	
	if (net_revenue > 0) {
		pvz.profitable_months = pvz.profitable_months + 1;
	} else {
		pvz.unprofitable_months = pvz.unprofitable_months + 1;
	}
	
	if (net_revenue > pvz.best_month_revenue) {
		pvz.best_month_revenue = net_revenue;
		pvz.best_month = cur_month;
		pvz.best_year = cur_year;
	}
	
	if (net_revenue < pvz.worst_month_revenue) {
		pvz.worst_month_revenue = net_revenue;
		pvz.worst_month = cur_month;
		pvz.worst_year = cur_year;
	}
	
	pvz.current_clients = static_cast<int>(
	  pvz.current_clients * (1.0 + pvz.growth_rate / 100.0)
	 );
}

void pvz_expenses() {
	if (pvz.is_opened == false) {
		return;
	}
	
	RUB total = 0;
	
	total = total + pvz.rent_per_month;
	total = total + pvz.utilities_per_month;
	total = total + pvz.salary_per_employee * pvz.employee_count;
	total = total + pvz.supplies_per_month;
	
	if (cur_month == 1 && cur_year > 2026) {
		pvz.rent_per_month = static_cast<RUB>(
			 pvz.rent_per_month * (1.0 + INFLATION_OTHER / 100.0)
		 );
		pvz.utilities_per_month = static_cast<RUB>(
			 pvz.utilities_per_month * (1.0 + INFLATION_UTILITIES / 100.0)
		 );
		pvz.salary_per_employee = static_cast<RUB>(
			 pvz.salary_per_employee * (1.0 + 4.0 / 100.0)
		  );
		pvz.supplies_per_month = static_cast<RUB>(
			 pvz.supplies_per_month * (1.0 + INFLATION_OTHER / 100.0)
		);
	}
	
	family.account = family.account - total;
	family.total_spent = family.total_spent + total;
	pvz.total_expenses = pvz.total_expenses + total;
}

void pvz_random_events() {
	if (pvz.is_opened == false) {
		return;
	}
	
	int chance = rand() % 100;
	if (chance >= 50) {
		return;
	}
	
	int event = rand() % 35;
	RUB amount = 0;
	const char* message = NULL;
	
	switch (event) {
	case 0:
		message = "[ПВЗ] Клиент устроил скандал, потеря товаров на 5000 руб.";
		amount = 5000;
		break;
	case 1:
		message = "[ПВЗ] Сломался сканер штрих-кодов. Ремонт: 8000 руб.";
		amount = 8000;
		break;
	case 2:
		message = "[ПВЗ] Ozon начислил премию за высокий рейтинг: +15,000 руб.";
		amount = -15000;
		break;
	case 3:
		message = "[ПВЗ] Потребовалась замена стеллажей: 25,000 руб.";
		amount = 25000;
		break;
	case 4:
		message = "[ПВЗ] Затопило помещение! Ущерб и ремонт: 40,000 руб.";
		amount = 40000;
		break;
	case 5:
		message = "[ПВЗ] Успешная акция привлекла новых клиентов! +10,000 руб.";
		amount = -10000;
		break;
	case 6:
		message = "[ПВЗ] Штраф за нарушение правил выдачи: 7,000 руб.";
		amount = 7000;
		break;
	case 7:
		message = "[ПВЗ] Клиент оставил чаевые за помощь: +2,000 руб.";
		amount = -2000;
		break;
	case 8:
		message = "[ПВЗ] Пришлось заказать новую оргтехнику: 35,000 руб.";
		amount = 35000;
		break;
	case 9:
		message = "[ПВЗ] Премия «Лучший ПВЗ месяца»: +20,000 руб.";
		amount = -20000;
		break;
	case 10:
		message = "[ПВЗ] Повышение арендной платы (разовый сбор): 12,000 руб.";
		amount = 12000;
		break;
	case 11:
		message = "[ПВЗ] Возврат крупной партии товаров. Потери: 18,000 руб.";
		amount = 18000;
		break;
	case 12:
		message = "[ПВЗ] Ozon компенсировал доставку бракованного товара: +8,000 руб.";
		amount = -8000;
		break;
	case 13:
		message = "[ПВЗ] Сотрудник заболел, доплата за подмену: 15,000 руб.";
		amount = 15000;
		break;
	case 14:
		message = "[ПВЗ] Установка системы видеонаблюдения: 30,000 руб.";
		amount = 30000;
		break;
	case 15:
		message = "[ПВЗ] Проверка Роспотребнадзора без штрафов. Повезло!";
		amount = 0;
		break;
	case 16:
		message = "[ПВЗ] Рекламная кампания принесла новых клиентов: +12,000 руб.";
		amount = -12000;
		break;
	case 17:
		message = "[ПВЗ] Поломка кондиционера. Ремонт: 22,000 руб.";
		amount = 22000;
		break;
	case 18:
		message = "[ПВЗ] Партнёрская программа Ozon: бонус +18,000 руб.";
		amount = -18000;
		break;
	case 19:
		message = "[ПВЗ] Кража товара из ПВЗ. Убыток: 10,000 руб.";
		amount = 10000;
		break;
	case 20:
		message = "[ПВЗ] Замена вывески Ozon (обязательное обновление): 20,000 руб.";
		amount = 20000;
		break;
	case 21:
		message = "[ПВЗ] Бонус за перевыполнение плана: +25,000 руб.";
		amount = -25000;
		break;
	case 22:
		message = "[ПВЗ] Обучение нового сотрудника: расходы 8,000 руб.";
		amount = 8000;
		break;
	case 23:
		message = "[ПВЗ] Подарочный сертификат от Ozon: +5,000 руб.";
		amount = -5000;
		break;
	case 24:
		message = "[ПВЗ] Замена упаковочного стола: 17,000 руб.";
		amount = 17000;
		break;
	case 25:
		message = "[ПВЗ] Сотрудник уволился, расходы на поиск нового: 10,000 руб.";
		amount = 10000;
		break;
	case 26:
		message = "[ПВЗ] Нашёлся идеальный сотрудник, премия за находку: +5,000 руб.";
		amount = -5000;
		break;
	case 27:
		message = "[ПВЗ] Сломалась кофемашина для клиентов. Ремонт: 6,000 руб.";
		amount = 6000;
		break;
	case 28:
		message = "[ПВЗ] Бесплатная раздача кофе привлекла клиентов: +8,000 руб.";
		amount = -8000;
		break;
	case 29:
		message = "[ПВЗ] Замена замков после попытки взлома: 14,000 руб.";
		amount = 14000;
		break;
	case 30:
		message = "[ПВЗ] Клиент оставил восторженный отзыв, Ozon дал бонус: +7,000 руб.";
		amount = -7000;
		break;
	case 31:
		message = "[ПВЗ] Срочный ремонт крыши после урагана: 45,000 руб.";
		amount = 45000;
		break;
	case 32:
		message = "[ПВЗ] Выиграли конкурс Ozon: сертификат на 30,000 руб. на оборудование";
		amount = -30000;
		break;
	case 33:
		message = "[ПВЗ] Сломалась система отопления зимой. Срочный ремонт: 28,000 руб.";
		amount = 28000;
		break;
	case 34:
		message = "[ПВЗ] Открыли вторую кассу, рост клиентов: +15,000 руб.";
		amount = -15000;
		break;
	default:
		message = "[ПВЗ] Обычный день, ничего ytg ghjbpjikj.";
		amount = 0;
		break;
	}
	
	if (amount > 0) {
		family.account = family.account - amount;
		family.total_spent = family.total_spent + amount;
		pvz.total_expenses = pvz.total_expenses + amount;
		pvz.negative_events = pvz.negative_events + 1;
		if (amount > pvz.max_single_expense) {
			pvz.max_single_expense = amount;
		}
	} else if (amount < 0) {
		RUB positive = -amount;
		family.account = family.account + positive;
		family.total_earned = family.total_earned + positive;
		pvz.total_revenue = pvz.total_revenue + positive;
		pvz.positive_events = pvz.positive_events + 1;
		if (positive > pvz.max_single_revenue) {
			pvz.max_single_revenue = positive;
		}
	}
	
	if (amount != 0) {
		print_date();
		printf("%s (Сумма: %lld руб.)\n", message, (amount > 0 ? amount : -amount));
	}
}

void family_food() {
	RUB food_budget = 40'000;
	
	if (cur_month == 1 && cur_year > 2026) {
		food_budget = static_cast<RUB>(
			food_budget * (1.0 + INFLATION_FOOD / 100.0)
		 );
	}
	
	if (cur_month == 12) {
		food_budget = static_cast<RUB>(food_budget * 1.3);
	}
	
	if (family.account >= food_budget) {
		family.account = family.account - food_budget;
		family.total_spent = family.total_spent + food_budget;
	} else {
		family.total_spent = family.total_spent + family.account;
		family.account = 0;
		print_date();
		printf("[ЕДА] Не хватило денег на еду!\n");
	}
}

void utilities() {
	RUB cost = housing.utilities_per_month;
	
	if (cur_month == 12 || cur_month == 1 || cur_month == 2) {
		cost = static_cast<RUB>(cost * 1.3);
	}
	
	if (cur_month == 1 && cur_year > 2026) {
		housing.utilities_per_month = static_cast<RUB>(
			 housing.utilities_per_month * (1.0 + INFLATION_UTILITIES / 100.0)
		 );
	}
	
	if (family.account >= cost) {
		family.account = family.account - cost;
		housing.total_spent_utilities = housing.total_spent_utilities + cost;
		family.total_spent = family.total_spent + cost;
	} else {
		housing.total_spent_utilities = housing.total_spent_utilities + family.account;
		family.total_spent = family.total_spent + family.account;
		family.account = 0;
	}
}

void internet() {
	RUB cost = housing.internet_per_month;
	
	if (cur_month == 1 && cur_year > 2026) {
		housing.internet_per_month = static_cast<RUB>(
			 housing.internet_per_month * (1.0 + 2.0 / 100.0)
		 );
	}
	
	if (family.account >= cost) {
		family.account = family.account - cost;
		housing.total_spent_internet = housing.total_spent_internet + cost;
		family.total_spent = family.total_spent + cost;
	} else {
		housing.total_spent_internet = housing.total_spent_internet + family.account;
		family.total_spent = family.total_spent + family.account;
		family.account = 0;
	}
}

void household_chemicals() {
	RUB cost = housing.household_chemicals_per_month;
	
	if (cur_month == 1 && cur_year > 2026) {
		housing.household_chemicals_per_month = static_cast<RUB>(
																 housing.household_chemicals_per_month * (1.0 + INFLATION_OTHER / 100.0)
																 );
	}
	
	if (family.account >= cost) {
		family.account = family.account - cost;
		housing.total_spent_chemicals = housing.total_spent_chemicals + cost;
		family.total_spent = family.total_spent + cost;
	} else {
		housing.total_spent_chemicals = housing.total_spent_chemicals + family.account;
		family.total_spent = family.total_spent + family.account;
		family.account = 0;
	}
}

void mortgage_payment() {
	if (mortgage.is_paid_off) {
		return;
	}
	
	if (cur_month == 1) {
		double delta = (rand() % 100 - 50) / 100.0;
		mortgage.interest_rate = mortgage.interest_rate + delta;
		if (mortgage.interest_rate < 5.0) mortgage.interest_rate = 5.0;
		if (mortgage.interest_rate > 18.0) mortgage.interest_rate = 18.0;
		
		double monthly_rate = mortgage.interest_rate / 100.0 / 12.0;
		if (mortgage.months_left > 0) {
			double factor = pow(1.0 + monthly_rate, mortgage.months_left);
			mortgage.monthly_payment = static_cast<RUB>(
														mortgage.remaining * (monthly_rate * factor) / (factor - 1.0)
														);
		}
	}
	
	RUB payment = mortgage.monthly_payment;
	
	if (cur_month == 12 && family.savings > 500'000) {
		RUB extra = family.savings - 300'000;
		if (extra > 200'000) extra = 200'000;
		family.savings = family.savings - extra;
		payment = payment + extra;
		mortgage.early_repayment_total = mortgage.early_repayment_total + extra;
		mortgage.early_repayments_count = mortgage.early_repayments_count + 1;
		print_date();
		printf("[ИПОТЕКА] Досрочное погашение: %lld руб.\n", extra);
	}
	
	if (family.account >= payment) {
		family.account = family.account - payment;
		family.total_spent = family.total_spent + payment;
		mortgage.total_paid = mortgage.total_paid + payment;
		mortgage.remaining = mortgage.remaining - payment;
		mortgage.months_left = mortgage.months_left - 1;
	} else {
		if (family.savings >= payment) {
			family.savings = family.savings - payment;
			mortgage.total_paid = mortgage.total_paid + payment;
			mortgage.remaining = mortgage.remaining - payment;
			mortgage.months_left = mortgage.months_left - 1;
			print_date();
			printf("[ИПОТЕКА] Платёж %lld руб. списан с накоплений!\n", payment);
		} else {
			print_date();
			printf("[ИПОТЕКА] ПРОСРОЧКА! Нет средств на платёж %lld руб.\n", payment);
		}
	}
	
	if (mortgage.remaining <= 0 || mortgage.months_left <= 0) {
		mortgage.is_paid_off = true;
		mortgage.paid_off_month = cur_month;
		mortgage.paid_off_year = cur_year;
		mortgage.remaining = 0;
		mortgage.months_left = 0;
		printf("\n========================================\n");
		printf("*** ИПОТЕКА ВЫПЛАЧЕНА! ***\n");
		printf("Дата: %d.%d\n", cur_month, cur_year);
		printf("Всего выплачено: %lld руб.\n", mortgage.total_paid);
		printf("Досрочных погашений: %d на сумму %lld руб.\n", 
			   mortgage.early_repayments_count, mortgage.early_repayment_total);
		printf("========================================\n\n");
	}
}

void barsik_life() {
	if (barsik.is_alive == false) {
		return;
	}
	
	RUB food = barsik.food_per_month;
	RUB litter = barsik.litter_per_month;
	RUB total = food + litter;
	
	if (cur_month == 1 && cur_year > 2026) {
		barsik.food_per_month = static_cast<RUB>(
												 barsik.food_per_month * (1.0 + INFLATION_FOOD / 100.0)
												 );
		barsik.litter_per_month = static_cast<RUB>(
												   barsik.litter_per_month * (1.0 + INFLATION_OTHER / 100.0)
												   );
	}
	
	if (barsik.age_months > 120) {
		food = static_cast<RUB>(food * 1.3);
		litter = static_cast<RUB>(litter * 1.2);
	}
	
	total = food + litter;
	
	if (family.account >= total) {
		family.account = family.account - total;
		family.total_spent = family.total_spent + total;
		barsik.total_spent_food = barsik.total_spent_food + total;
	} else {
		barsik.total_spent_food = barsik.total_spent_food + family.account;
		family.total_spent = family.total_spent + family.account;
		family.account = 0;
		print_date();
		printf("[БАРСИК] Не хватило денег на корм!\n");
	}
	
	if (cur_month == 3) {
		RUB vet = barsik.vet_annual;
		if (barsik.age_months > 96) {
			vet = static_cast<RUB>(vet * 1.5);
		}
		if (family.account >= vet) {
			family.account = family.account - vet;
			family.total_spent = family.total_spent + vet;
			barsik.total_spent_vet = barsik.total_spent_vet + vet;
		} else {
			RUB partial = family.account;
			barsik.total_spent_vet = barsik.total_spent_vet + partial;
			family.total_spent = family.total_spent + partial;
			family.account = 0;
			print_date();
			printf("[БАРСИК] Не хватило денег на полный осмотр у ветеринара!\n");
		}
		if (cur_year > 2026) {
			barsik.vet_annual = static_cast<RUB>(
												 barsik.vet_annual * (1.0 + INFLATION_OTHER / 100.0)
												 );
		}
	}
	
	if (cur_month == 9) {
		if (family.account >= barsik.toys_annual) {
			family.account = family.account - barsik.toys_annual;
			family.total_spent = family.total_spent + barsik.toys_annual;
			barsik.total_spent_other = barsik.total_spent_other + barsik.toys_annual;
		}
		if (cur_year > 2026) {
			barsik.toys_annual = static_cast<RUB>(
												  barsik.toys_annual * (1.0 + INFLATION_OTHER / 100.0)
												  );
		}
	}
	
	int chance1 = rand() % 100;
	if (chance1 < 5) {
		RUB emergency_cost = barsik.emergency_vet_min + 
		(rand() % (barsik.emergency_vet_max - barsik.emergency_vet_min + 1));
		
		barsik.emergency_vet_visits = barsik.emergency_vet_visits + 1;
		
		if (barsik.age_months > 100) {
			emergency_cost = static_cast<RUB>(emergency_cost * 1.4);
		}
		
		print_date();
		printf("[БАРСИК] Визит #%d к ветеринару! Стоимость: %lld руб.\n", 
			   barsik.emergency_vet_visits, emergency_cost);
		
		if (family.account >= emergency_cost) {
			family.account = family.account - emergency_cost;
			family.total_spent = family.total_spent + emergency_cost;
			barsik.total_spent_vet = barsik.total_spent_vet + emergency_cost;
		} else {
			RUB partial = family.account;
			family.total_spent = family.total_spent + partial;
			barsik.total_spent_vet = barsik.total_spent_vet + partial;
			family.account = 0;
			print_date();
			printf("[БАРСИК] Не хватило денег на лечение! Заплатили только %lld руб.\n", partial);
		}
	}
	
	int chance2 = rand() % 100;
	if (chance2 < 3) {
		barsik.happy_events = barsik.happy_events + 1;
		RUB found_money = 500 + (rand() % 5'000);
		family.account = family.account + found_money;
		family.total_earned = family.total_earned + found_money;
		barsik.total_saved_from_lost = barsik.total_saved_from_lost + found_money;
		print_date();
		printf("[БАРСИК] Барсик нашёл потерянные деньги! +%lld руб.\n", found_money);
	}
	
	int chance3 = rand() % 100;
	if (chance3 < 2 && barsik.age_months > 120) {
		barsik.is_alive = false;
		print_date();
		printf("[БАРСИК] Барсик ушёл на радугу... Прожил %d месяцев (%d лет)\n", 
			   barsik.age_months, barsik.age_months / 12);
		printf("[БАРСИК] За свою жизнь: %d экстренных визитов к вету, %d раз находил деньги (%lld руб.)\n",
			   barsik.emergency_vet_visits, barsik.happy_events, barsik.total_saved_from_lost);
	}
	
	barsik.age_months = barsik.age_months + 1;
}

void lada_life() {
	RUB gas_cost = lada.gas_per_month;
	
	if (cur_month == 1 && cur_year > 2026) {
		lada.gas_price_per_liter = static_cast<RUB>(
			lada.gas_price_per_liter * (1.0 + INFLATION_GAS / 100.0)
		);
		lada.gas_per_month = static_cast<RUB>(
			lada.gas_per_month * (1.0 + INFLATION_GAS / 100.0)
		  );
	}
	
	if (cur_month >= 6 && cur_month <= 8) {
		gas_cost = static_cast<RUB>(gas_cost * 1.2);
	}
	
	if (lada.age_years > 7) {
		gas_cost = static_cast<RUB>(gas_cost * 1.15);
	}
	
	if (family.account >= gas_cost) {
		family.account = family.account - gas_cost;
		lada.total_spent_gas = lada.total_spent_gas + gas_cost;
		family.total_spent = family.total_spent + gas_cost;
	} else {
		RUB partial = family.account;
		lada.total_spent_gas = lada.total_spent_gas + partial;
		family.total_spent = family.total_spent + partial;
		family.account = 0;
		print_date();
		printf("[МАШИНА] Не хватило денег на полный бак!\n");
	}
	
	if (cur_month == 2) {
		RUB insurance_cost = lada.insurance_per_year;
		if (lada.age_years > 5) {
			insurance_cost = static_cast<RUB>(insurance_cost * 0.9);
		}
		if (family.account >= insurance_cost) {
			family.account = family.account - insurance_cost;
			lada.total_spent_insurance = lada.total_spent_insurance + insurance_cost;
			family.total_spent = family.total_spent + insurance_cost;
		} else {
			RUB partial = family.account;
			lada.total_spent_insurance = lada.total_spent_insurance + partial;
			family.total_spent = family.total_spent + partial;
			family.account = 0;
		}
		if (cur_year > 2026) {
			lada.insurance_per_year = static_cast<RUB>(
													   lada.insurance_per_year * (1.0 + INFLATION_OTHER / 100.0)
													   );
		}
	}
	
	lada.months_since_service = lada.months_since_service + 1;
	if (lada.months_since_service >= 12) {
		RUB service_cost = lada.maintenance_per_year;
		if (lada.age_years > 5) {
			service_cost = static_cast<RUB>(service_cost * 1.3);
		}
		if (lada.age_years > 10) {
			service_cost = static_cast<RUB>(service_cost * 1.5);
		}
		
		if (family.account >= service_cost) {
			family.account = family.account - service_cost;
			lada.total_spent_maintenance = lada.total_spent_maintenance + service_cost;
			family.total_spent = family.total_spent + service_cost;
		} else {
			RUB partial = family.account;
			lada.total_spent_maintenance = lada.total_spent_maintenance + partial;
			family.total_spent = family.total_spent + partial;
			family.account = 0;
			print_date();
			printf("[МАШИНА] Не хватило денег на полное ТО!\n");
		}
		lada.months_since_service = 0;
		
		if (cur_year > 2026) {
			lada.maintenance_per_year = static_cast<RUB>(
				lada.maintenance_per_year * (1.0 + INFLATION_OTHER / 100.0)
			);
		}
	}
	
	if (cur_month == 4 || cur_month == 10) {
		if (family.account >= lada.tire_change_per_season) {
			family.account = family.account - lada.tire_change_per_season;
			lada.total_spent_tires = lada.total_spent_tires + lada.tire_change_per_season;
			family.total_spent = family.total_spent + lada.tire_change_per_season;
		} else {
			RUB partial = family.account;
			lada.total_spent_tires = lada.total_spent_tires + partial;
			family.total_spent = family.total_spent + partial;
			family.account = 0;
		}
		if (cur_year > 2026) {
			lada.tire_change_per_season = static_cast<RUB>(
				 lada.tire_change_per_season * (1.0 + INFLATION_OTHER / 100.0)
			 );
		}
	}
	
	lada.tires_age_years = lada.tires_age_years + 1;
	if (lada.tires_age_years >= 3) {
		if (cur_month == 10) {
			if (family.account >= lada.winter_tires_set) {
				family.account = family.account - lada.winter_tires_set;
				lada.total_spent_tires = lada.total_spent_tires + lada.winter_tires_set;
				family.total_spent = family.total_spent + lada.winter_tires_set;
				lada.total_tire_sets_bought = lada.total_tire_sets_bought + 1;
				print_date();
				printf("[МАШИНА] Куплена зимняя резина (комплект #%d): %lld руб.\n", 
					   lada.total_tire_sets_bought, lada.winter_tires_set);
			} else {
				print_date();
				printf("[МАШИНА] Нет денег на новую зимнюю резину! Ездим на старой.\n");
			}
		}
		if (cur_month == 4) {
			if (family.account >= lada.summer_tires_set) {
				family.account = family.account - lada.summer_tires_set;
				lada.total_spent_tires = lada.total_spent_tires + lada.summer_tires_set;
				family.total_spent = family.total_spent + lada.summer_tires_set;
				lada.total_tire_sets_bought = lada.total_tire_sets_bought + 1;
				print_date();
				printf("[МАШИНА] Куплена летняя резина (комплект #%d): %lld руб.\n", 
					   lada.total_tire_sets_bought, lada.summer_tires_set);
			}
		}
		lada.tires_age_years = 0;
		
		if (cur_year > 2026) {
			lada.winter_tires_set = static_cast<RUB>(
				lada.winter_tires_set * (1.0 + INFLATION_OTHER / 100.0)
			);
			lada.summer_tires_set = static_cast<RUB>(
				 lada.summer_tires_set * (1.0 + INFLATION_OTHER / 100.0)
			 );
		}
	}
	
	if (cur_month == 5 || cur_month == 11) {
		RUB wash_cost = lada.washing_per_year / 2;
		if (family.account >= wash_cost) {
			family.account = family.account - wash_cost;
			lada.total_spent_washing = lada.total_spent_washing + wash_cost;
			family.total_spent = family.total_spent + wash_cost;
		}
	}
	
	int repair_chance = lada.age_years * 4;
	if (repair_chance > 60) repair_chance = 60;
	
	if ((rand() % 100) < repair_chance) {
		RUB repair_cost = lada.repair_min + 
		(rand() % (lada.repair_max - lada.repair_min + 1));
		
		lada.total_repairs_count = lada.total_repairs_count + 1;
		
		print_date();
		printf("[МАШИНА] Ремонт #%d! Стоимость: %lld руб.\n", 
			   lada.total_repairs_count, repair_cost);
		
		if (family.account >= repair_cost) {
			family.account = family.account - repair_cost;
			family.total_spent = family.total_spent + repair_cost;
			lada.total_spent_repairs = lada.total_spent_repairs + repair_cost;
		} else {
			RUB partial = family.account;
			family.total_spent = family.total_spent + partial;
			lada.total_spent_repairs = lada.total_spent_repairs + partial;
			family.account = 0;
			print_date();
			printf("[МАШИНА] Не хватило денег на ремонт! Сделали частично.\n");
		}
	}
	
	int fine_chance = rand() % 100;
	if (fine_chance < 4) {
		RUB fine = 500 + (rand() % 5'000);
		lada.fines_count = lada.fines_count + 1;
		lada.total_fines = lada.total_fines + fine;
		
		print_date();
		printf("[МАШИНА] Штраф ГИБДД #%d: %lld руб.\n", lada.fines_count, fine);
		
		if (family.account >= fine) {
			family.account = family.account - fine;
			family.total_spent = family.total_spent + fine;
		} else {
			family.total_spent = family.total_spent + family.account;
			family.account = 0;
		}
	}
	
	int accident_chance = lada.age_years * 2;
	if (accident_chance > 30) accident_chance = 30;
	
	if ((rand() % 100) < accident_chance) {
		RUB damage = 10'000 + (rand() % 100'000);
		lada.accidents_count = lada.accidents_count + 1;
		lada.total_accident_damage = lada.total_accident_damage + damage;
		
		print_date();
		printf("[МАШИНА] ДТП #%d! Ущерб: %lld руб.\n", lada.accidents_count, damage);
		
		if (family.account >= damage) {
			family.account = family.account - damage;
			family.total_spent = family.total_spent + damage;
		} else {
			RUB partial = family.account;
			family.total_spent = family.total_spent + partial;
			family.account = 0;
			print_date();
			printf("[МАШИНА] Не хватило денег на ремонт после ДТП!\n");
		}
	}
	
	if (cur_month == 12) {
		if (family.account >= lada.tax_per_year) {
			family.account = family.account - lada.tax_per_year;
			lada.total_spent_tax = lada.total_spent_tax + lada.tax_per_year;
			family.total_spent = family.total_spent + lada.tax_per_year;
			family.total_taxes_paid = family.total_taxes_paid + lada.tax_per_year;
		} else {
			print_date();
			printf("[МАШИНА] Нет денег на транспортный налог!\n");
		}
	}
	
	if (cur_month == 12) {
		lada.age_years = lada.age_years + 1;
		lada.current_value = static_cast<RUB>(lada.current_value * 0.90);
		if (lada.age_years > 15) {
			lada.current_value = static_cast<RUB>(lada.current_value * 0.85);
		}
	}
}

void housing_repairs() {
	if (cur_month == 6) {
		if (family.account >= housing.repairs_annual) {
			family.account = family.account - housing.repairs_annual;
			housing.total_spent_repairs = housing.total_spent_repairs + housing.repairs_annual;
			family.total_spent = family.total_spent + housing.repairs_annual;
		}
		if (cur_year > 2026) {
			housing.repairs_annual = static_cast<RUB>(
													  housing.repairs_annual * (1.0 + INFLATION_OTHER / 100.0)
													  );
		}
	}
	
	if (cur_month == 8) {
		if (family.account >= housing.furniture_annual) {
			family.account = family.account - housing.furniture_annual;
			housing.total_spent_furniture = housing.total_spent_furniture + housing.furniture_annual;
			family.total_spent = family.total_spent + housing.furniture_annual;
		}
		if (cur_year > 2026) {
			housing.furniture_annual = static_cast<RUB>(
														housing.furniture_annual * (1.0 + INFLATION_OTHER / 100.0)
														);
		}
	}
	
	int chance = rand() % 100;
	if (chance < 8) {
		RUB emergency_repair = 5'000 + (rand() % 20'000);
		housing.emergency_repairs_count = housing.emergency_repairs_count + 1;
		housing.total_emergency_repairs = housing.total_emergency_repairs + emergency_repair;
		print_date();
		printf("[КВАРТИРА] Срочный ремонт #%d: %lld руб.\n", 
			   housing.emergency_repairs_count, emergency_repair);
		if (family.account >= emergency_repair) {
			family.account = family.account - emergency_repair;
			housing.total_spent_repairs = housing.total_spent_repairs + emergency_repair;
			family.total_spent = family.total_spent + emergency_repair;
		}
	}
}

void entertainment_life() {
	RUB rest = fun.restaurants_per_month;
	RUB movies = fun.cinema_per_month;
	RUB hobbies = fun.hobbies_per_month;
	
	if (cur_month == 1 && cur_year > 2026) {
		fun.restaurants_per_month = static_cast<RUB>(
													 fun.restaurants_per_month * (1.0 + INFLATION_OTHER / 100.0)
													 );
		fun.cinema_per_month = static_cast<RUB>(
												fun.cinema_per_month * (1.0 + INFLATION_OTHER / 100.0)
												);
		fun.hobbies_per_month = static_cast<RUB>(
												 fun.hobbies_per_month * (1.0 + INFLATION_OTHER / 100.0)
												 );
	}
	
	if (cur_month == 12) {
		rest = static_cast<RUB>(rest * 1.5);
	}
	
	RUB total = rest + movies + hobbies;
	
	if (family.account >= total) {
		family.account = family.account - total;
		fun.total_spent_restaurants = fun.total_spent_restaurants + rest;
		fun.total_spent_movies = fun.total_spent_movies + movies;
		fun.total_spent_hobbies = fun.total_spent_hobbies + hobbies;
		family.total_spent = family.total_spent + total;
	} else {
		family.total_spent = family.total_spent + family.account;
		family.account = 0;
	}
	
	if (cur_month == 7) {
		if (family.account >= fun.vacation_per_year) {
			family.account = family.account - fun.vacation_per_year;
			fun.total_spent_vacation = fun.total_spent_vacation + fun.vacation_per_year;
			family.total_spent = family.total_spent + fun.vacation_per_year;
			fun.vacations_taken = fun.vacations_taken + 1;
		}
		if (cur_year > 2026) {
			fun.vacation_per_year = static_cast<RUB>(
													 fun.vacation_per_year * (1.0 + INFLATION_OTHER / 100.0)
													 );
		}
	}
	
	int concert_chance = rand() % 100;
	if (concert_chance < 10) {
		RUB concert_cost = 3'000 + (rand() % 10'000);
		fun.concerts_attended = fun.concerts_attended + 1;
		fun.total_spent_concerts = fun.total_spent_concerts + concert_cost;
		if (family.account >= concert_cost) {
			family.account = family.account - concert_cost;
			family.total_spent = family.total_spent + concert_cost;
		}
	}
}

void health_life() {
	RUB med = health.medicine_per_month;
	RUB gym = health.gym_per_month;
	
	if (cur_month == 1 && cur_year > 2026) {
		health.medicine_per_month = static_cast<RUB>(
													 health.medicine_per_month * (1.0 + INFLATION_OTHER / 100.0)
													 );
		health.gym_per_month = static_cast<RUB>(
												health.gym_per_month * (1.0 + INFLATION_OTHER / 100.0)
												);
	}
	
	if (family.account >= med) {
		family.account = family.account - med;
		health.total_spent_medicine = health.total_spent_medicine + med;
		family.total_spent = family.total_spent + med;
	}
	
	if (family.account >= gym) {
		family.account = family.account - gym;
		health.total_spent_gym = health.total_spent_gym + gym;
		family.total_spent = family.total_spent + gym;
	}
	
	if (cur_month == 3) {
		if (family.account >= health.dentist_per_year) {
			family.account = family.account - health.dentist_per_year;
			health.total_spent_dentist = health.total_spent_dentist + health.dentist_per_year;
			family.total_spent = family.total_spent + health.dentist_per_year;
		}
		if (cur_year > 2026) {
			health.dentist_per_year = static_cast<RUB>(
													   health.dentist_per_year * (1.0 + INFLATION_OTHER / 100.0)
													   );
		}
	}
	
	int chance = rand() % 100;
	if (chance < 3) {
		RUB sick_cost = 2'000 + (rand() % 10'000);
		print_date();
		printf("[ЗДОРОВЬЕ] Болезнь, лекарства: %lld руб.\n", sick_cost);
		if (family.account >= sick_cost) {
			family.account = family.account - sick_cost;
			health.total_spent_medicine = health.total_spent_medicine + sick_cost;
			family.total_spent = family.total_spent + sick_cost;
		}
	}
}

void gifts_life() {
	if (cur_month == 1 && cur_year > 2026) {
		gifts.birthday_gifts_per_year = static_cast<RUB>(
			 gifts.birthday_gifts_per_year * (1.0 + INFLATION_OTHER / 100.0)
		 );
		gifts.new_year_gifts_per_year = static_cast<RUB>(
			 gifts.new_year_gifts_per_year * (1.0 + INFLATION_OTHER / 100.0)
			 );
		gifts.other_holidays_per_year = static_cast<RUB>(
				 gifts.other_holidays_per_year * (1.0 + INFLATION_OTHER / 100.0)
			 );
	}
	
	if (cur_month == 1) {
		if (family.account >= gifts.new_year_gifts_per_year) {
			family.account = family.account - gifts.new_year_gifts_per_year;
			gifts.total_spent_gifts = gifts.total_spent_gifts + gifts.new_year_gifts_per_year;
			family.total_spent = family.total_spent + gifts.new_year_gifts_per_year;
		}
	}
	
	if (cur_month == 4) {
		if (family.account >= gifts.birthday_gifts_per_year) {
			family.account = family.account - gifts.birthday_gifts_per_year;
			gifts.total_spent_gifts = gifts.total_spent_gifts + gifts.birthday_gifts_per_year;
			family.total_spent = family.total_spent + gifts.birthday_gifts_per_year;
		}
	}
	
	if (cur_month == 3 || cur_month == 5 || cur_month == 10) {
		RUB holiday_cost = gifts.other_holidays_per_year / 3;
		if (family.account >= holiday_cost) {
			family.account = family.account - holiday_cost;
			gifts.total_spent_gifts = gifts.total_spent_gifts + holiday_cost;
			family.total_spent = family.total_spent + holiday_cost;
		}
	}
}

void subscriptions_life() {
	RUB total = subs.netflix_per_month + subs.spotify_per_month + 
	subs.youtube_per_month + subs.cloud_storage_per_month;
	
	if (cur_month == 1 && cur_year > 2026) {
		subs.netflix_per_month = static_cast<RUB>(subs.netflix_per_month * (1.0 + INFLATION_OTHER / 100.0));
		subs.spotify_per_month = static_cast<RUB>(subs.spotify_per_month * (1.0 + INFLATION_OTHER / 100.0));
		subs.youtube_per_month = static_cast<RUB>(subs.youtube_per_month * (1.0 + INFLATION_OTHER / 100.0));
		subs.cloud_storage_per_month = static_cast<RUB>(subs.cloud_storage_per_month * (1.0 + INFLATION_OTHER / 100.0));
	}
	
	if (family.account >= total) {
		family.account = family.account - total;
		subs.total_spent_subscriptions = subs.total_spent_subscriptions + total;
		family.total_spent = family.total_spent + total;
	} else {
		subs.total_spent_subscriptions = subs.total_spent_subscriptions + family.account;
		family.total_spent = family.total_spent + family.account;
		family.account = 0;
	}
}

void clothes_life() {
	if (cur_month == 3 || cur_month == 6 || cur_month == 9 || cur_month == 12) {
		RUB cost = clothes.clothes_per_season;
		
		if (cur_month == 12) {
			cost = static_cast<RUB>(cost * 1.5);
		}
		
		if (family.account >= cost) {
			family.account = family.account - cost;
			clothes.total_spent_clothes = clothes.total_spent_clothes + cost;
			family.total_spent = family.total_spent + cost;
		} else {
			RUB partial = family.account;
			clothes.total_spent_clothes = clothes.total_spent_clothes + partial;
			family.total_spent = family.total_spent + partial;
			family.account = 0;
		}
		
		if (cur_year > 2026) {
			clothes.clothes_per_season = static_cast<RUB>(
														  clothes.clothes_per_season * (1.0 + INFLATION_OTHER / 100.0)
														  );
		}
	}
	
	if (cur_month == 4) {
		if (family.account >= clothes.shoes_per_year) {
			family.account = family.account - clothes.shoes_per_year;
			clothes.total_spent_shoes = clothes.total_spent_shoes + clothes.shoes_per_year;
			family.total_spent = family.total_spent + clothes.shoes_per_year;
		}
		if (cur_year > 2026) {
			clothes.shoes_per_year = static_cast<RUB>(
				 clothes.shoes_per_year * (1.0 + INFLATION_OTHER / 100.0)
			 );
		}
	}
}

void education_life() {
	RUB books = edu.books_per_month;
	
	if (cur_month == 1 && cur_year > 2026) {
		edu.books_per_month = static_cast<RUB>(
		  edu.books_per_month * (1.0 + INFLATION_OTHER / 100.0)
		  );
	}
	
	if (family.account >= books) {
		family.account = family.account - books;
		edu.total_spent_books = edu.total_spent_books + books;
		family.total_spent = family.total_spent + books;
	}
	
	if (cur_month == 9) {
		if (family.account >= edu.courses_per_year) {
			family.account = family.account - edu.courses_per_year;
			edu.total_spent_courses = edu.total_spent_courses + edu.courses_per_year;
			family.total_spent = family.total_spent + edu.courses_per_year;
		}
		if (cur_year > 2026) {
			edu.courses_per_year = static_cast<RUB>(
					edu.courses_per_year * (1.0 + INFLATION_OTHER / 100.0)
				);
		}
	}
}

void transport_life() {
	RUB pub = transport.public_transport_per_month;
	RUB taxi = transport.taxi_per_month;
	
	if (cur_month == 1 && cur_year > 2026) {
		transport.public_transport_per_month = static_cast<RUB>(
				transport.public_transport_per_month * (1.0 + INFLATION_OTHER / 100.0)
			);
		transport.taxi_per_month = static_cast<RUB>(
				transport.taxi_per_month * (1.0 + INFLATION_OTHER / 100.0)
			);
	}
	
	if (family.account >= pub) {
		family.account = family.account - pub;
		transport.total_spent_public = transport.total_spent_public + pub;
		family.total_spent = family.total_spent + pub;
	}
	
	if (family.account >= taxi) {
		family.account = family.account - taxi;
		transport.total_spent_taxi = transport.total_spent_taxi + taxi;
		family.total_spent = family.total_spent + taxi;
	}
}

void charity_life() {
	if (cur_month == 12) {
		if (family.account >= charity.donations_per_year) {
			family.account = family.account - charity.donations_per_year;
			charity.total_spent_charity = charity.total_spent_charity + charity.donations_per_year;
			family.total_spent = family.total_spent + charity.donations_per_year;
		}
		if (cur_year > 2026) {
			charity.donations_per_year = static_cast<RUB>(
				 charity.donations_per_year * (1.0 + INFLATION_OTHER / 100.0)
			  );
		}
	}
}

void insurance_life() {
	if (cur_month == 3) {
		if (family.account >= insurance.life_insurance_per_year) {
			family.account = family.account - insurance.life_insurance_per_year;
			insurance.total_spent_life = insurance.total_spent_life + insurance.life_insurance_per_year;
			family.total_spent = family.total_spent + insurance.life_insurance_per_year;
		}
		if (cur_year > 2026) {
			insurance.life_insurance_per_year = static_cast<RUB>(
					 insurance.life_insurance_per_year * (1.0 + INFLATION_OTHER / 100.0)
			 );
		}
	}
	
	if (cur_month == 6) {
		if (family.account >= insurance.property_insurance_per_year) {
			family.account = family.account - insurance.property_insurance_per_year;
			insurance.total_spent_property = insurance.total_spent_property + insurance.property_insurance_per_year;
			family.total_spent = family.total_spent + insurance.property_insurance_per_year;
		}
		if (cur_year > 2026) {
			insurance.property_insurance_per_year = static_cast<RUB>(
				 insurance.property_insurance_per_year * (1.0 + INFLATION_OTHER / 100.0)
				 );
		}
	}
}

void print_mid_results() {
	printf("\n");
	printf("==================== %d ГОД: ОТЧЁТ СЕМЬИ ====================\n", cur_year);
	
	RUB total_assets = family.account + family.savings + lada.current_value;
	RUB total_debt = mortgage.remaining;
	RUB net_worth = total_assets - total_debt;
	
	printf("--- Бюджет ---\n");
	printf("  Счёт: %lld руб.\n", family.account);
	printf("  Накопления: %lld руб.\n", family.savings);
	printf("  Ставка по депозиту: %.1f%%\n", family.savings_interest);
	printf("--- Зарплаты ---\n");
	printf("  Джон: %lld руб/мес\n", john.salary_per_month);
	if (!alice.quit_job) {
		printf("  Алиса: %lld руб/мес\n", alice.salary_per_month);
	} else {
		printf("  Алиса: управляет ПВЗ\n");
	}
	printf("--- Ипотека ---\n");
	printf("  Остаток: %lld руб.\n", mortgage.remaining);
	printf("  Платёж: %lld руб/мес\n", mortgage.monthly_payment);
	printf("  Осталось месяцев: %d\n", mortgage.months_left);
	printf("--- ПВЗ Ozon ---\n");
	if (pvz.is_opened) {
		RUB pvz_profit = pvz.total_revenue - pvz.total_expenses;
		printf("  Клиентов: %d\n", pvz.current_clients);
		printf("  Месяцев работы: %d\n", pvz.months_operated);
		printf("  Прибыльных месяцев: %d\n", pvz.profitable_months);
		printf("  Убыточных месяцев: %d\n", pvz.unprofitable_months);
		printf("  Выручка всего: %lld руб.\n", pvz.total_revenue);
		printf("  Расходы всего: %lld руб.\n", pvz.total_expenses);
		printf("  Прибыль: %lld руб.\n", pvz_profit);
	} else {
		printf("  Ещё не открыт.\n");
	}
	printf("--- Машина ---\n");
	printf("  Возраст: %d лет\n", lada.age_years);
	printf("  Стоимость: %lld руб.\n", lada.current_value);
	printf("  Ремонтов: %d\n", lada.total_repairs_count);
	printf("  Штрафов: %d\n", lada.fines_count);
	printf("  ДТП: %d\n", lada.accidents_count);
	printf("--- Итого ---\n");
	printf("  Активы: %lld руб.\n", total_assets);
	printf("  Долги: %lld руб.\n", total_debt);
	printf("  Чистый капитал: %lld руб.\n", net_worth);
}

void print_final_results() {
	printf("\n");
	printf("========== ИТОГОВЫЙ ФИНАНСОВЫЙ ОТЧЁТ=================\n");
	
	RUB total_assets = family.account + family.savings + lada.current_value;
	RUB total_debt = mortgage.remaining;
	RUB net_worth = total_assets - total_debt;
	
	printf("\n--- ДОХОДЫ ---\n");
	printf("  Зарплата Джона (всего): %lld руб.\n", john.total_earned_salary);
	printf("  Премии Джона (всего): %lld руб.\n", john.total_earned_bonus);
	printf("  Повышений Джона: %d\n", john.promotions_count);
	printf("  Максимальная зарплата Джона: %lld руб.\n", john.max_salary);
	printf("  Потеряно на больничных: %lld руб.\n", john.lost_income_from_sick);
	printf("  Зарплата Алисы до ПВЗ: %lld руб.\n", alice.total_earned_salary);
	printf("  Отработано Алисой до ПВЗ: %d мес.\n", alice.months_worked_before_quit);
	printf("  Доход ПВЗ: %lld руб.\n", pvz.total_revenue);
	printf("  ВСЕГО ДОХОДОВ: %lld руб.\n", family.total_earned);
	
	printf("\n--- РАСХОДЫ ---\n");
	printf("  Ипотека (выплачено): %lld руб.\n", mortgage.total_paid);
	printf("  Досрочные погашения: %d на сумму %lld руб.\n", 
		   mortgage.early_repayments_count, mortgage.early_repayment_total);
	printf("  Коммуналка: %lld руб.\n", housing.total_spent_utilities);
	printf("  Интернет: %lld руб.\n", housing.total_spent_internet);
	printf("  Бытовая химия: %lld руб.\n", housing.total_spent_chemicals);
	printf("  Ремонт квартиры: %lld руб.\n", housing.total_spent_repairs);
	printf("  Экстренных ремонтов: %d на %lld руб.\n", 
		   housing.emergency_repairs_count, housing.total_emergency_repairs);
	printf("  Мебель: %lld руб.\n", housing.total_spent_furniture);
	printf("  Кот Барсик (всего): %lld руб.\n", 
		   barsik.total_spent_food + barsik.total_spent_vet + barsik.total_spent_other);
	printf("    - Корм/наполнитель: %lld руб.\n", barsik.total_spent_food);
	printf("    - Ветеринар: %lld руб.\n", barsik.total_spent_vet);
	printf("    - Экстренных визитов: %d\n", barsik.emergency_vet_visits);
	printf("    - Нашёл денег: %lld руб.\n", barsik.total_saved_from_lost);
	printf("  Машина (всего): %lld руб.\n",
		   lada.total_spent_gas + lada.total_spent_insurance + lada.total_spent_maintenance
		   + lada.total_spent_tires + lada.total_spent_repairs + lada.total_spent_tax 
		   + lada.total_spent_washing + lada.total_fines + lada.total_accident_damage);
	printf("    - Бензин: %lld руб.\n", lada.total_spent_gas);
	printf("    - Страховка: %lld руб.\n", lada.total_spent_insurance);
	printf("    - ТО: %lld руб.\n", lada.total_spent_maintenance);
	printf("    - Резина/шиномонтаж: %lld руб.\n", lada.total_spent_tires);
	printf("    - Ремонты: %lld руб. (%d шт.)\n", lada.total_spent_repairs, lada.total_repairs_count);
	printf("    - Налог: %lld руб.\n", lada.total_spent_tax);
	printf("    - Мойка: %lld руб.\n", lada.total_spent_washing);
	printf("    - Штрафы: %lld руб. (%d шт.)\n", lada.total_fines, lada.fines_count);
	printf("    - ДТП: %lld руб. (%d шт.)\n", lada.total_accident_damage, lada.accidents_count);
	printf("  Развлечения (всего): %lld руб.\n",
		   fun.total_spent_restaurants + fun.total_spent_movies + fun.total_spent_hobbies 
		   + fun.total_spent_vacation + fun.total_spent_concerts);
	printf("    - Рестораны: %lld руб.\n", fun.total_spent_restaurants);
	printf("    - Кино: %lld руб.\n", fun.total_spent_movies);
	printf("    - Хобби: %lld руб.\n", fun.total_spent_hobbies);
	printf("    - Отпуск: %lld руб. (%d шт.)\n", fun.total_spent_vacation, fun.vacations_taken);
	printf("    - Концерты: %lld руб. (%d шт.)\n", fun.total_spent_concerts, fun.concerts_attended);
	printf("  Здоровье (всего): %lld руб.\n",
		   health.total_spent_medicine + health.total_spent_dentist + health.total_spent_gym);
	printf("  Подарки (всего): %lld руб.\n", gifts.total_spent_gifts);
	printf("  Подписки: %lld руб.\n", subs.total_spent_subscriptions);
	printf("  Одежда: %lld руб.\n", clothes.total_spent_clothes);
	printf("  Обувь: %lld руб.\n", clothes.total_spent_shoes);
	printf("  Книги: %lld руб.\n", edu.total_spent_books);
	printf("  Курсы: %lld руб.\n", edu.total_spent_courses);
	printf("  Общественный транспорт: %lld руб.\n", transport.total_spent_public);
	printf("  Такси: %lld руб.\n", transport.total_spent_taxi);
	printf("  Благотворительность: %lld руб.\n", charity.total_spent_charity);
	printf("  Страхование жизни: %lld руб.\n", insurance.total_spent_life);
	printf("  Страхование имущества: %lld руб.\n", insurance.total_spent_property);
	printf("  ПВЗ (расходы): %lld руб.\n", pvz.total_expenses);
	printf("  ВСЕГО РАСХОДОВ: %lld руб.\n", family.total_spent);
	
	printf("\n--- НАЛОГИ ---\n");
	printf("  НДФЛ Джон: %lld руб.\n", john.total_taxes_paid);
	printf("  НДФЛ Алиса: %lld руб.\n", alice.total_taxes_paid);
	printf("  Транспортный налог: %lld руб.\n", lada.total_spent_tax);
	printf("  ВСЕГО НАЛОГОВ: %lld руб.\n", family.total_taxes_paid);
	
	printf("\n--- ПВЗ OZON (ДЕТАЛЬНО) ---\n");
	if (pvz.is_opened) {
		printf("  Открыт: %d.%d\n", pvz.opened_month, pvz.opened_year);
		printf("  Вложения: %lld руб.\n", pvz.total_invested);
		printf("  Месяцев работы: %d\n", pvz.months_operated);
		printf("  Прибыльных месяцев: %d\n", pvz.profitable_months);
		printf("  Убыточных месяцев: %d\n", pvz.unprofitable_months);
		printf("  Положительных событий: %d\n", pvz.positive_events);
		printf("  Отрицательных событий: %d\n", pvz.negative_events);
		printf("  Максимальный разовый расход: %lld руб.\n", pvz.max_single_expense);
		printf("  Максимальный разовый доход: %lld руб.\n", pvz.max_single_revenue);
		printf("  Лучший месяц: %d.%d (+%lld руб.)\n", 
			   pvz.best_month, pvz.best_year, pvz.best_month_revenue);
		printf("  Худший месяц: %d.%d (%lld руб.)\n", 
			   pvz.worst_month, pvz.worst_year, pvz.worst_month_revenue);
		printf("  Всего клиентов обслужено: %d\n", pvz.total_clients_served);
		printf("  Всего выдано товаров: %d\n", pvz.total_items_issued);
		printf("  Всего возвратов: %d\n", pvz.total_returns);
		printf("  Штрафы за возвраты: %lld руб.\n", pvz.total_returns_penalty);
		printf("  Бонусы Ozon: %lld руб.\n", pvz.total_bonuses);
		RUB pvz_profit = pvz.total_revenue - pvz.total_expenses;
		printf("  ПРИБЫЛЬ ПВЗ: %lld руб.\n", pvz_profit);
	} else {
		printf("  ПВЗ не был открыт.\n");
	}
	
	printf("\n--- АКТИВЫ И ДОЛГИ ---\n");
	printf("  На счету: %lld руб.\n", family.account);
	printf("  Накопления: %lld руб.\n", family.savings);
	printf("  Переведено в накопления: %lld руб.\n", family.total_transferred_to_savings);
	printf("  Машина (остаточная стоимость): %lld руб.\n", lada.current_value);
	printf("  Возраст машины: %d лет\n", lada.age_years);
	if (mortgage.is_paid_off) {
		printf("  Ипотека ВЫПЛАЧЕНА в %d.%d\n", mortgage.paid_off_month, mortgage.paid_off_year);
	} else {
		printf("  Ипотека (остаток): %lld руб.\n", mortgage.remaining);
	}
	printf("  АКТИВЫ ВСЕГО: %lld руб.\n", total_assets);
	printf("  ДОЛГИ ВСЕГО: %lld руб.\n", total_debt);
	printf("  ЧИСТЫЙ КАПИТАЛ: %lld руб.\n", net_worth);
	
	printf("\n--- ВЫВОДЫ ---\n");
	if (net_worth > 10'000'000) {
		printf("Отличная финансовая модель! Семья хорошо обеспечена. \n");
	} else if (net_worth > 3'000'000) {
		printf("Хорошая финансовая модель. Всё стабильно.\n");
	} else if (net_worth > 0) {
		printf("Удовлетворительно. Есть куда расти.\n");
	} else {
		printf("Плохая финансовая модель. Расходы превышают доходы.\n");
	}
	
	if (pvz.is_opened && (pvz.total_revenue - pvz.total_expenses) > 0) {
		printf("ПВЗ Ozon оказался прибыльным бизнесом!\n");
		printf("    Рентабельность: %.1f%%\n", 
			   100.0 * (pvz.total_revenue - pvz.total_expenses) / pvz.total_revenue);
	} else if (pvz.is_opened) {
		printf("ПВЗ Ozon не принёс прибыли. Возможно, стоило не открывать.\n");
	}
	
	if (mortgage.is_paid_off) {
		printf("Ипотека успешно выплачена. Квартира полностью в собственности.\n");
	} else {
		printf("Ипотека ещё не выплачена. Осталось %d месяцев.\n", mortgage.months_left);
	}
	
	printf("========== СИМУЛЯЦИЯ ЗАВЕРШЕНА =============================\n");
}

void simulation() {
	while (!(cur_year == 2041 && cur_month == 1)) {
		
		john_salary();
		alice_salary();
		savings_interest();
		pvz_open();
		pvz_revenue();
		pvz_random_events();
		
		family_food();
		utilities();
		internet();
		household_chemicals();
		mortgage_payment();
		barsik_life();
		lada_life();
		pvz_expenses();
		housing_repairs();
		entertainment_life();
		health_life();
		gifts_life();
		subscriptions_life();
		clothes_life();
		education_life();
		transport_life();
		charity_life();
		insurance_life();
		
		if (cur_month == 12 && cur_year % 3 == 0) {
			print_mid_results();
		}
		
		cur_month = cur_month + 1;
		if (cur_month == 13) {
			cur_month = 1;
			cur_year = cur_year + 1;
		}
	}
}

int main() {
	std::system("chcp 65001 > nul");
	
	printf("============================================================\n");
	printf("=== СИМУЛЯЦИЯ ЖИЗНИ: АЛИСА И ДЖОН ==========================\n");
	printf("=== Период: 2026-2040 (15 лет) =============================\n");
	printf("============================================================\n");
	
	init_all();
	simulation();
	print_final_results();
	
	return 0;
}
