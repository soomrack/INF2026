#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


using RUB = long long int;
using USD = long long int;


struct Car {
	RUB value;
	RUB gas;
	RUB inshurance;
	RUB maintenance;
	RUB parking;
	RUB fine;
	RUB car_wash;
	RUB tires;
	RUB tax;
};


struct RealEstate {
	RUB apartment_value;
	RUB mortgage_payment;
	RUB utilities;
	RUB property_tax;
	RUB repair_fund;
	RUB inherited_apartment_value; // Унаследованная квартира
	RUB rental_income; // Доход от аренды
	RUB rental_tax; // Налог на доход от аренды
	RUB inherited_apartment_utilities; // Коммуналка наследуемой квартиры
	int is_rented; //Сдается ли квартира
};


struct Pets {
	RUB cat_food;
	RUB vet_visits;
	RUB toys;
	RUB insurance;
	RUB grooming;
	RUB cat_sitter;
	RUB litter; 
	RUB treats; 
};


struct Investments {
	RUB stocks;
	RUB crypto;
	RUB bonds;
	RUB gold; 
	RUB etf; 
	RUB startup; 
	float stocks_growth_rate;
	float crypto_volatility;
	float gold_growth_rate;
	float etf_growth_rate;
};


struct Bank {
	RUB account_rub;
	USD account_usd;
	float rate_usd_rub;
	float deposit_rate;
	RUB credit_card_debt;
	RUB credit_card_limit;
	RUB savings_account; 
	RUB tax_refund;
};


struct Education {
	RUB courses;
	RUB books;
	RUB certifications;
	RUB mentorship;
	RUB conference;
};


struct Health {
	RUB insurance;
	RUB dentist;
	RUB medications;
	RUB vitamins;
	RUB massage;
	RUB psychologist;
	RUB gym_membership;
	RUB sports_equipment;
};


struct Entertainment {
	RUB cinema;
	RUB concerts;
	RUB restaurants;
	RUB cafes;
	RUB museums;
	RUB hobbies;
	RUB board_games;
	RUB video_games;
};


struct Freelance {
	RUB monthly_income;
	RUB project_income;
	RUB taxes;
	int has_project;
	int project_month;
	int project_duration;
};


struct Charity {
	RUB animal_shelter;
	RUB environmental;
	RUB children_fund;
	RUB church;
	RUB monthly_donations;
};


struct Vacation {
	RUB travel_fund;
	RUB current_trip_cost;
	RUB souvenirs;
	RUB visa_fees;
	int is_traveling;
	int travel_month;
};


struct Family {
	RUB parents_aid;
	RUB grandparents_aid;
	RUB siblings_gifts;
	RUB family_events;
	RUB heritage_tax; 
};


struct Person {
	RUB pets_expenses;
	RUB lottery_tickets;
	Bank vtb;
	RUB food;
	RUB salary;
	Car car;
	RealEstate home;
	Pets animals;
	Investments portfolio;
	RUB subscriptions;
	RUB fitness;
	RUB clothes;
	RUB entertainment_total;
	Education education;
	Health health;
	Entertainment entertainment_detail;
	Freelance freelance;
	Charity charity;
	Vacation vacation;
	Family family;
	RUB transportation;
	RUB gifts;
	RUB emergency_fund;
	RUB beauty;
	RUB electronics; 
	RUB alcohol; 
};


struct Person alice;


void alice_init()
{
	alice.vtb.rate_usd_rub = 78.76;
	alice.vtb.deposit_rate = 0.10;
	alice.vtb.savings_account = 0;
	alice.vtb.tax_refund = 0;


	alice.portfolio.stocks_growth_rate = 0.12;
	alice.portfolio.crypto_volatility = 0.3;
	alice.portfolio.gold_growth_rate = 0.08;
	alice.portfolio.etf_growth_rate = 0.10;

	
	alice.vtb.account_rub = 500'000;
	alice.vtb.account_usd = 1'000;
	alice.vtb.credit_card_debt = 0;
	alice.vtb.credit_card_limit = 300'000;

	
	alice.food = 3'000;
	alice.salary = 70'000;
	alice.subscriptions = 2'500;
	alice.clothes = 8'000;
	alice.transportation = 3'000;
	alice.gifts = 5'000;
	alice.emergency_fund = 10'000;
	alice.beauty = 7'000;
	alice.electronics = 5'000;
	alice.alcohol = 2'000;

	
	alice.car.value = 2'400'000;
	alice.car.gas = 15'000;
	alice.car.inshurance = 20'000;
	alice.car.maintenance = 8'000;
	alice.car.parking = 5'000;
	alice.car.fine = 0;
	alice.car.car_wash = 2'000;
	alice.car.tires = 0; // Переобулась
	alice.car.tax = 4'500;

	
	alice.home.apartment_value = 8'500'000;
	alice.home.mortgage_payment = 45'000;
	alice.home.utilities = 7'000;
	alice.home.property_tax = 3'500;
	alice.home.repair_fund = 5'000;
	alice.home.inherited_apartment_value = 4'200'000; // Квартира от бабушки
	alice.home.rental_income = 35'000; // Арендная плата
	alice.home.rental_tax = 4'000;
	alice.home.inherited_apartment_utilities = 4'500;
	alice.home.is_rented = 1;

	
	alice.animals.cat_food = 2'500;
	alice.animals.vet_visits = 3'000;
	alice.animals.toys = 1'000;
	alice.animals.insurance = 1'500;
	alice.animals.grooming = 2'000;
	alice.animals.cat_sitter = 0;
	alice.animals.litter = 1'200;
	alice.animals.treats = 800;

	
	alice.portfolio.stocks = 200'000;
	alice.portfolio.crypto = 50'000;
	alice.portfolio.bonds = 100'000;
	alice.portfolio.gold = 75'000;
	alice.portfolio.etf = 150'000;
	alice.portfolio.startup = 0;

	
	alice.education.courses = 15'000;
	alice.education.books = 3'000;
	alice.education.certifications = 0;
	alice.education.mentorship = 0;
	alice.education.conference = 0;

	
	alice.health.insurance = 7'000;
	alice.health.dentist = 0;
	alice.health.medications = 1'500;
	alice.health.vitamins = 2'000;
	alice.health.massage = 3'000;
	alice.health.psychologist = 0;
	alice.health.gym_membership = 4'000;
	alice.health.sports_equipment = 0;

	
	alice.entertainment_detail.cinema = 2'000;
	alice.entertainment_detail.concerts = 0;
	alice.entertainment_detail.restaurants = 5'000;
	alice.entertainment_detail.cafes = 3'000;
	alice.entertainment_detail.museums = 1'000;
	alice.entertainment_detail.hobbies = 3'000;
	alice.entertainment_detail.board_games = 1'000;
	alice.entertainment_detail.video_games = 2'000;

	alice.entertainment_total = 0;

	
	alice.freelance.monthly_income = 0;
	alice.freelance.project_income = 0;
	alice.freelance.taxes = 0;
	alice.freelance.has_project = 0;
	alice.freelance.project_month = 0;
	alice.freelance.project_duration = 0;

	
	alice.charity.animal_shelter = 1'000;
	alice.charity.environmental = 500;
	alice.charity.children_fund = 1'000;
	alice.charity.church = 0;
	alice.charity.monthly_donations = 2'500;

	
	alice.vacation.travel_fund = 30'000;
	alice.vacation.current_trip_cost = 0;
	alice.vacation.souvenirs = 0;
	alice.vacation.visa_fees = 0;
	alice.vacation.is_traveling = 0;
	alice.vacation.travel_month = 0;

	
	alice.family.parents_aid = 5'000;
	alice.family.grandparents_aid = 3'000;
	alice.family.siblings_gifts = 2'000;
	alice.family.family_events = 0;
	alice.family.heritage_tax = 210'000;

	alice.lottery_tickets = 20'000;
}


void alice_rental_income()
{
	if (alice.home.is_rented) {
		alice.vtb.account_rub += alice.home.rental_income;

		
		alice.vtb.account_rub -= alice.home.rental_tax;

		
		alice.vtb.account_rub -= alice.home.inherited_apartment_utilities;

		
		if (rand() % 100 < 5) { 
			RUB repair_cost = (rand() % 20 + 5) * 1000;
			alice.vtb.account_rub -= repair_cost;
		}
	}
}


void alice_lottery()
{
	const RUB JACKPOT = 500'000'000;
	const int JACKPOT_CHANCE = 15000000;

	alice.vtb.account_rub -= alice.lottery_tickets;

	int random_number = rand() % JACKPOT_CHANCE + 1;

	if (random_number == 1) {
		alice.vtb.account_rub += JACKPOT;
		printf("\n*** УРРАА! ДЖЕКПОТ %lld РУБЛЕЙ! ***\n", JACKPOT);
	}
}


void alice_salary(const int month, const int year)
{
	alice.vtb.account_rub += alice.salary;

	if (month == 2 and year == 2026) {
		alice.vtb.account_rub += 5'000;  // Премия
	}

	if (month == 12 and year == 2026) {
		alice.vtb.account_rub += 30'000;  // Новогодняя премия
	}

	if (month == 6 and year == 2026) {
		alice.vtb.account_rub += 15'000;  // Летний бонус
	}

	if (month == 3 and year == 2026) {
		alice.salary = alice.salary * 1.5;
	}

	if (month == 1 and year > 2026) {
		float indexation = 1.10;
		alice.salary = alice.salary * indexation;
	}
}


void alice_freelance(const int month, const int year)
{
	
	if (!alice.freelance.has_project and month == 4 and year == 2026) {
		alice.freelance.has_project = 1;
		alice.freelance.project_month = month;
		alice.freelance.project_duration = 3;
		alice.freelance.project_income = 80'000;
	}

	if (!alice.freelance.has_project and month == 9 and year == 2026) {
		alice.freelance.has_project = 1;
		alice.freelance.project_month = month;
		alice.freelance.project_duration = 2;
		alice.freelance.project_income = 50'000;
	}

	if (alice.freelance.has_project) {
		int months_active = month - alice.freelance.project_month;
		if (months_active >= 0 and months_active < alice.freelance.project_duration) {
			RUB monthly_income = alice.freelance.project_income / alice.freelance.project_duration;
			alice.vtb.account_rub += monthly_income;

			
			RUB freelance_tax = monthly_income * 0.06; // Налог (Самозанятость)
			alice.vtb.account_rub -= freelance_tax;
			alice.freelance.taxes += freelance_tax;
		}
		else {
			alice.freelance.has_project = 0;
		}
	}
}


void alice_food(const int month, const int year)
{
	float inflation = 0.12;
	switch (year) {
	case 2026: inflation = 0.125; break;
	case 2027: inflation = 0.14; break;
	case 2028: inflation = 0.13; break;
	case 2029: inflation = 0.115; break;
	}

	alice.food += alice.food * (inflation / 12);
	alice.vtb.account_rub -= alice.food;

	if (month == 12) {
		alice.vtb.account_rub -= 10'000;  // Новогодний стол
	}

	if (month == 7 and year == 2026) {
		alice.vtb.account_rub -= 5'000;  // День рождения
	}

	if (month == 3 and year == 2026) {
		alice.vtb.account_rub -= 2'000;  // 8 марта
	}

	if (month == 11 and year == 2026) {
		alice.vtb.account_rub -= 20'000;  // Черная пятница
	}
}


void alice_car(const int month)
{
	alice.vtb.account_rub -= alice.car.gas;
	alice.vtb.account_rub -= alice.car.inshurance;
	alice.vtb.account_rub -= alice.car.maintenance;
	alice.vtb.account_rub -= alice.car.parking;
	alice.vtb.account_rub -= alice.car.car_wash;

	if (rand() % 100 < 33) {
		int fine_amount = (rand() % 5 + 1) * 500;
		alice.car.fine += fine_amount;
		alice.vtb.account_rub -= fine_amount;
	}

	
	if (month == 5 or month == 10) {
		alice.car.tires = 8'000;
		alice.vtb.account_rub -= alice.car.tires;
	}

	
	if (month == 11) { // Транспортный налог
		alice.vtb.account_rub -= alice.car.tax;
	}
}


void alice_real_estate(const int month, const int year)
{
	alice.vtb.account_rub -= alice.home.mortgage_payment;
	alice.vtb.account_rub -= alice.home.utilities;
	alice.vtb.account_rub -= alice.home.property_tax;
	alice.vtb.account_rub -= alice.home.repair_fund;

	
	if (month == 10) { // Налог на имущество
		RUB property_tax = alice.home.apartment_value * 0.001;
		alice.vtb.account_rub -= property_tax;
	}

	
	if (month == 1 and year > 2026) { // Индексация стоимости квартиры
		alice.home.apartment_value *= 1.15; // Рост 15% в год
		alice.home.inherited_apartment_value *= 1.15;
	}
}


void alice_pets(const int month)
{
	alice.vtb.account_rub -= alice.animals.cat_food;
	alice.vtb.account_rub -= alice.animals.vet_visits;
	alice.vtb.account_rub -= alice.animals.toys;
	alice.vtb.account_rub -= alice.animals.insurance;
	alice.vtb.account_rub -= alice.animals.grooming;
	alice.vtb.account_rub -= alice.animals.litter;
	alice.vtb.account_rub -= alice.animals.treats;

	if (rand() % 100 < 10) {
		int vet_emergency = (rand() % 10 + 5) * 1000;
		alice.vtb.account_rub -= vet_emergency;
	}

	
	if (alice.vacation.is_traveling and month == alice.vacation.travel_month) { // Сиделка для домашних животных
		alice.animals.cat_sitter = 6'000;
		alice.vtb.account_rub -= alice.animals.cat_sitter;
	}
}


void alice_investments(const int month, const int year)
{
	float stocks_return = 1.0 + (alice.portfolio.stocks_growth_rate / 12);
	alice.portfolio.stocks = alice.portfolio.stocks * stocks_return;

	
	float crypto_change = 1.0 + ((rand() % 200 - 100) / 100.0 * alice.portfolio.crypto_volatility / 12); // Волатильность крипты
	alice.portfolio.crypto = alice.portfolio.crypto * crypto_change;

	
	float bonds_return = 1.0 + (0.06 / 12); // Облигации (6% годовых)
	alice.portfolio.bonds = alice.portfolio.bonds * bonds_return;

	
	float gold_return = 1.0 + (alice.portfolio.gold_growth_rate / 12); // Золото (8% годовых)
	alice.portfolio.gold = alice.portfolio.gold * gold_return;

	
	float etf_return = 1.0 + (alice.portfolio.etf_growth_rate / 12); // ETF (10% годовых)
	alice.portfolio.etf = alice.portfolio.etf * etf_return;

	
	if (year == 2027 and month == 1 and alice.portfolio.startup > 0) { // Стартап (возможный доход при выходе)
		RUB exit_income = alice.portfolio.startup * 3; // Трехкратный выход
		alice.vtb.account_rub += exit_income;
		alice.portfolio.startup = 0;
	}

	
	if (alice.vtb.account_rub > 100'000) { // Автоматические инвестиции
		RUB investment_amount = alice.vtb.account_rub * 0.1;
		if (investment_amount > 50'000) investment_amount = 50'000;

		alice.vtb.account_rub -= investment_amount;

		
		alice.portfolio.stocks += investment_amount * 0.4;
		alice.portfolio.bonds += investment_amount * 0.2;
		alice.portfolio.etf += investment_amount * 0.2; // Диверсифицированный портфель
		alice.portfolio.gold += investment_amount * 0.15;
		alice.portfolio.crypto += investment_amount * 0.05;
	}
}


void alice_education_expenses(const int month, const int year)
{
	alice.vtb.account_rub -= alice.education.courses;
	alice.vtb.account_rub -= alice.education.books;
	alice.vtb.account_rub -= alice.education.certifications;

	if (alice.education.mentorship > 0) {
		alice.vtb.account_rub -= alice.education.mentorship;
	}

	if (month == 9 and year == 2026) {
		alice.education.certifications = 25'000; // Сертификация
		alice.vtb.account_rub -= alice.education.certifications;
	}

	if (month == 5 and year == 2027) {
		alice.education.conference = 40'000; // Профессиональная конференция
		alice.vtb.account_rub -= alice.education.conference;
	}
}


void alice_health_expenses(const int month)
{
	alice.vtb.account_rub -= alice.health.insurance;
	alice.vtb.account_rub -= alice.health.medications;
	alice.vtb.account_rub -= alice.health.vitamins;
	alice.vtb.account_rub -= alice.health.massage;
	alice.vtb.account_rub -= alice.health.gym_membership;


	if (alice.health.dentist > 0) {
		alice.vtb.account_rub -= alice.health.dentist;
		alice.health.dentist = 0;
	}


	if (alice.health.psychologist > 0) {
		alice.vtb.account_rub -= alice.health.psychologist;
	}


	if (alice.health.sports_equipment > 0) {
		alice.vtb.account_rub -= alice.health.sports_equipment;
		alice.health.sports_equipment = 0;
	}

	
	if (month == 6 or month == 12) {
		alice.health.dentist = (rand() % 10 + 5) * 1000;
		alice.vtb.account_rub -= alice.health.dentist;
	}
}


void alice_entertainment_expenses(const int month, const int year)
{
	alice.vtb.account_rub -= alice.entertainment_detail.cinema;
	alice.vtb.account_rub -= alice.entertainment_detail.restaurants;
	alice.vtb.account_rub -= alice.entertainment_detail.cafes;
	alice.vtb.account_rub -= alice.entertainment_detail.museums;
	alice.vtb.account_rub -= alice.entertainment_detail.hobbies;
	alice.vtb.account_rub -= alice.entertainment_detail.board_games;
	alice.vtb.account_rub -= alice.entertainment_detail.video_games;

	if (alice.entertainment_detail.concerts > 0) {
		alice.vtb.account_rub -= alice.entertainment_detail.concerts;
		alice.entertainment_detail.concerts = 0;
	}

	
	if (month == 7 and year == 2026) {
		alice.entertainment_detail.concerts = 8'000;
		alice.vtb.account_rub -= alice.entertainment_detail.concerts;
	}
}


void alice_charity_donations()
{
	alice.vtb.account_rub -= alice.charity.animal_shelter;
	alice.vtb.account_rub -= alice.charity.environmental;
	alice.vtb.account_rub -= alice.charity.children_fund;
	alice.vtb.account_rub -= alice.charity.monthly_donations;

	if (alice.charity.church > 0) {
		alice.vtb.account_rub -= alice.charity.church;
	}
}


void alice_vacation_expenses(const int month, const int year)
{
	alice.vtb.account_rub -= alice.vacation.travel_fund;

	
	if (month == 8 and year == 2026 and !alice.vacation.is_traveling) {
		alice.vacation.is_traveling = 1;
		alice.vacation.travel_month = 8;
		alice.vacation.current_trip_cost = 85'000;
		alice.vacation.visa_fees = 7'000;
		alice.vacation.souvenirs = 10'000;

		alice.vtb.account_rub -= alice.vacation.current_trip_cost;
		alice.vtb.account_rub -= alice.vacation.visa_fees;
		alice.vtb.account_rub -= alice.vacation.souvenirs;
	}


	if (alice.vacation.is_traveling and month == alice.vacation.travel_month) {
		alice.vacation.is_traveling = 0;
		alice.vacation.current_trip_cost = 0;
	}
}


void alice_family_expenses(const int month)
{
	alice.vtb.account_rub -= alice.family.parents_aid;
	alice.vtb.account_rub -= alice.family.grandparents_aid;
	alice.vtb.account_rub -= alice.family.siblings_gifts;


	if (alice.family.family_events > 0) {
		alice.vtb.account_rub -= alice.family.family_events;
		alice.family.family_events = 0;
	}

	
	if (month == 9) {
		alice.family.family_events = 15'000;
		alice.vtb.account_rub -= alice.family.family_events;
	}
}


void alice_monthly_others(const int month)
{
	alice.vtb.account_rub -= alice.subscriptions;
	alice.vtb.account_rub -= alice.clothes;
	alice.vtb.account_rub -= alice.transportation;
	alice.vtb.account_rub -= alice.gifts;
	alice.vtb.account_rub -= alice.emergency_fund;
	alice.vtb.account_rub -= alice.beauty;
	alice.vtb.account_rub -= alice.electronics;
	alice.vtb.account_rub -= alice.alcohol;

	
	if (month == 4 or month == 9) {
		RUB seasonal_clothes = 15'000;
		alice.vtb.account_rub -= seasonal_clothes;
	}

	
	if (month == 12) {
		RUB holiday_gifts = 25'000;
		alice.vtb.account_rub -= holiday_gifts;
	}
}


void alice_bank_operations(const int month, const int year)
{
	if (alice.vtb.account_rub > 0) {
		RUB deposit_interest = alice.vtb.account_rub * (alice.vtb.deposit_rate / 12);
		alice.vtb.account_rub += deposit_interest;
	}

	
	if (alice.vtb.savings_account > 0) {
		RUB savings_interest = alice.vtb.savings_account * (0.12 / 12);
		alice.vtb.savings_account += savings_interest;
	}

	
	if (alice.vtb.credit_card_debt > 0) {
		RUB min_payment = alice.vtb.credit_card_debt * 0.05;
		if (min_payment < 1000) min_payment = alice.vtb.credit_card_debt;

		alice.vtb.account_rub -= min_payment;
		alice.vtb.credit_card_debt -= min_payment;

		RUB credit_perc = alice.vtb.credit_card_debt * (0.24 / 12);
		alice.vtb.credit_card_debt += credit_perc;
	}

	
	if (month == 4) { // Возврат налогов (раз в год)
		alice.vtb.tax_refund = (rand() % 10 + 5) * 1000;
		alice.vtb.account_rub += alice.vtb.tax_refund;
	}
}


void alice_tax_optimization(const int month, const int year)
{
		if (year == 2026 and month == 12) { // ИИС
		RUB iis_investment = 200'000;


		if (alice.vtb.account_rub > iis_investment) {
			alice.vtb.account_rub -= iis_investment;
			alice.portfolio.stocks += iis_investment;
			

			RUB tax_deduction = iis_investment * 0.13; // Налоговый вычет 13%
			alice.vtb.account_rub += tax_deduction;
		}
	}
}


void simulation()
{
	int year = 2026;
	int month = 2;

	while (!(year == 2027 and month == 2)) {

		alice_salary(month, year);
		alice_rental_income(); // Доход от аренды унаследованной квартиры
		alice_freelance(month, year);
		alice_investments(month, year);

		alice_real_estate(month, year);
		alice_food(month, year);
		alice_pets(month);
		alice_car(month);
		alice_education_expenses(month, year);
		alice_health_expenses(month);
		alice_entertainment_expenses(month, year);
		alice_charity_donations();
		alice_vacation_expenses(month, year);
		alice_family_expenses(month);
		alice_monthly_others(month);

		alice_bank_operations(month, year);
		alice_tax_optimization(month, year);
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
	RUB capital = 0;
	capital += alice.car.value;
	capital += alice.home.apartment_value;
	capital += alice.home.inherited_apartment_value;
	capital += alice.vtb.account_rub;
	capital += alice.vtb.savings_account;
	capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
	capital += alice.portfolio.stocks;
	capital += alice.portfolio.crypto;
	capital += alice.portfolio.bonds;
	capital += alice.portfolio.gold;
	capital += alice.portfolio.etf;
	capital += alice.portfolio.startup;


	printf("Суммарный капитал: %lld руб\n", capital - alice.vtb.credit_card_debt);

	printf("Собственная квартира: %lld руб\n", alice.home.apartment_value);
	printf("Унаследованная квартира: %lld руб\n", alice.home.inherited_apartment_value);
	printf("Автомобиль: %lld руб\n", alice.car.value);
	printf("Инвестиционный портфель: %lld руб\n", alice.portfolio.stocks + alice.portfolio.crypto + alice.portfolio.bonds + alice.portfolio.gold +
		alice.portfolio.etf);
	printf("Средства: %lld руб\n",
		alice.vtb.account_rub + alice.vtb.savings_account);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	alice_init();
	simulation();
	print_results();

	return 0;
}
