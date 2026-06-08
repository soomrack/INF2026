#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <stdbool.h>

using RUB = long long int;

// инфляция
float get_monthly_rate(float annual_rate) {
	// годовая инфляция =>> месячная инфляция
	return powf(1 + annual_rate / 100, 1 / 12) - 1;
}

RUB apply_inflation(RUB value, float monthly_rate) {
	return static_cast<RUB>(value * (1 + monthly_rate));
}

// розовая машинка
struct Car {
	RUB value;
	RUB  gas;
	RUB maintenance;
	RUB coolant_flush;
	RUB washer_fluid;
	RUB osago;
	RUB casco;
	RUB green_card;
	float inf_rate; // 3 проц
};

// питомец
struct Animal {
	RUB food;
	RUB vet;
	RUB toys;
	RUB vitamins;
	RUB treats;
	RUB shampoo;
	RUB grooming;
	float inf_rate; // 5 проц
};

// банк + инфляция
struct Bank {
	RUB deposit;
	RUB account;
	RUB monthly_maintenance;
	RUB sms_notifications;
	RUB online_banking;
	RUB currency_exchange_commission;
	RUB card_insurance;

	float month_inf;
	float pp;
};

// инвестиции
struct Investments {
	RUB stocks;
	RUB bonds;
	RUB liquid_funds;
};

// медицинские расходы и возраст
struct Health {
	int age;
	RUB dentist;
	RUB med_chest;
	RUB disease;   // стоимость болезней (умножается на возрастной коэффициент)
	RUB insurance;
	RUB med_examination;
	float inf_rate;  // 8 проц
};

// аренда жилья и бытовая техника
struct Flat {
	RUB renting;
	RUB appliance;
	float inf_rate; // 4 проц
};

// повседневные расходы
struct Payments {
	RUB food;
	RUB cloth;
	RUB gifts;
	RUB subscription;
	float inf_rate;  // 3,5 проц
};

// образование
struct Education {
	RUB courses;
	RUB books;
	RUB hobby;
	float inf_rate;  // 6 проц
};

// благотворительность
struct Charity {
	RUB donations;
	RUB special;
	float inf_rate;  // 2 проц
};

// досуг
struct Leisure {
	RUB entertainment;
	RUB sport;
	RUB vacation;
	float inf_rate;  // 4,5 проц
};

// хеллоуин
struct Halloween {
	RUB pumking;
	RUB cosmetics;
	RUB costume;
	RUB party_food;
	float inf_rate; // 4 проц
};

// подвозит пассажиров на своей машине
struct Carguest {
	int monthly_rides;
	RUB price_one_ride;
	RUB monthly_income;
	RUB car_damage_cost;
	RUB total_damage;
	int rowdy_passengers;
	int rowdy_count;
	float inf_rate; // 3 проц
};

// бизнес ALICE'ONE - производство домиков для животных
struct Business {
	int employees;   // количество сотрудников (максимум 4)
	int team_builder;   // опыт команды (0-100, влияет на качество)
	bool is_active;   // бизнес работает или нет
	int monthly_sales_dogs;
	int monthly_sales_cats;
	int monthly_sales_reptiles;
	int monthly_sales_fish;
	RUB company_cash;
	RUB monthly_revenue;
	RUB production_cost;
	RUB marketing;
	RUB rent;
	RUB utilities;
	RUB raw_materials;
	RUB dog_house_price;
	RUB cat_house_price;
	RUB reptile_house_price;
	RUB fish_castle_price;
	float inf_rate;  // инфляция для бизнеса (3.2% в год)
};

// питание и РПП 
struct EatingDisorder {
	int relapse_count;
	int stress_level;   // уровень стресса (0-100), влияет на вероятность срыва
	bool is_healthy_mode;   // режим правильного питания (true - старается есть правильно)
	float relapse_probability;
	RUB healthy_food;
	RUB relapse_food; 
	float inf_rate; // 3,8 проц
};

// усталость от бизнеса / работы
struct Fatigue {
	int level;
	int burnout_rate;
	bool is_searching_job;
	int months_searching;
};

// работа
struct Job {
	int experience;   // опыт работы
	int vacation_days;
	int base_salary;
	int sick_leave_months;
	bool has_job;
	bool on_sick_leave;
	char position[50];


	RUB salary;
};

// травмы
struct Injury {
	char injury_name[100];
	int recovery_months;
	bool has_injury;
	bool needs_surgery;
	bool permanent_damage;

	RUB treatment_cost;
	RUB surgery_cost;
	float inf_rate;  // инфляция для лечения травм (7% в год)
};

// отношения
struct Relationship {
	bool has_boyfriend;
	bool boyfriend_pays;   // true - парень платит, false - Алиса

	int relationship_months;
	int relationship_quality;
	char last_gift_type[100];
	RUB restaurant_spent;
	RUB cosmetics_spent;
	RUB small_wants_spent;
	RUB handmade_gifts_spent;
	RUB clothes_increase;
	RUB shoes_increase;
	RUB jewelry_increase;
	RUB last_gift_amount;
	float inf_rate;  // 4,2 проц
};


struct Person {
    RUB salary;
    Car car;
	Animal animal;
	RUB travel;
	Flat flat;
	Health health;
	Bank bank;
	Payments payments;
	Investments invest;
	Education education;
	Charity charity;
	Leisure leisure;
	Halloween halloween;
	Carguest carguest;
	Business business;
	EatingDisorder eating;
	Fatigue fatigue;
	Job job;
	Injury injury;
	Relationship relationship;
};

struct Person Alice;

// глобальные переменные для отслеживания времени
int month = 2;
int year = 2026;

//переход к след месяцу
void passing_of_time() {
	++ month;
	if (month == 13) {
		month = 1;
		++year;
	}
}

// начальные значения
void alice_init() {

	Alice.bank.deposit = 0;
	Alice.bank.account = 0;
	Alice.bank.monthly_maintenance = 500;
	Alice.bank.sms_notifications = 60;
	Alice.bank.online_banking = 300;
	Alice.bank.currency_exchange_commission = 0;
	Alice.bank.card_insurance = 200;

	Alice.salary = 155'000;

	// регулярные платежи
	Alice.payments.food = 20'000;
	Alice.payments.cloth = 7'000;
	Alice.payments.gifts = 2'000;
	Alice.payments.subscription = 1'500;
	Alice.payments.inf_rate = 3.5;

	// автомобиль
	Alice.car.value = 2'400'000;
	Alice.car.gas = 15'000;
	Alice.car.maintenance = 8'000;
	Alice.car.coolant_flush = 2'000;
	Alice.car.washer_fluid = 3'000;
	Alice.car.osago = 10'000;
	Alice.car.casco = 50'000;
	Alice.car.green_card = 12'000;
	Alice.car.inf_rate = 3.0;

	// питомец
	Alice.animal.food = 1'500;
	Alice.animal.vet = 3'000;
	Alice.animal.toys = 2'000;
	Alice.animal.vitamins = 8'000;
	Alice.animal.treats = 1'000;
	Alice.animal.shampoo = 4'000;
	Alice.animal.grooming = 12'000;
	Alice.animal.inf_rate = 5.0;

	// путешествия
	Alice.travel = 50'000;

	// жилье
	Alice.flat.renting = 40'000;
	Alice.flat.appliance = 10'000;
	Alice.flat.inf_rate = 4.0;

	// здоровье
	Alice.health.dentist = 4'000;
	Alice.health.med_chest = 1'500;
	Alice.health.disease = 2'000;
	Alice.health.insurance = 15'000;
	Alice.health.med_examination = 3'000;
	Alice.health.age = 25;
	Alice.health.inf_rate = 8.0;

	// инвестиции
	Alice.invest.stocks = 0;
	Alice.invest.bonds = 0;
	Alice.invest.liquid_funds = 0;

	// образование
	Alice.education.courses = 5'000;
	Alice.education.books = 2'000;
	Alice.education.hobby = 3'000;
	Alice.education.inf_rate = 6.0;

	// благотворительность
	Alice.charity.donations = 1'000;
	Alice.charity.special = 5'000;
	Alice.charity.inf_rate = 2.0;

	// досуг
	Alice.leisure.entertainment = 5'000;
	Alice.leisure.sport = 2'500;
	Alice.leisure.vacation = 15'000;
	Alice.leisure.inf_rate = 4.5;

	// хеллоуин
	Alice.halloween.costume = 9'000;
	Alice.halloween.cosmetics = 20'000;
	Alice.halloween.party_food = 14'000;
	Alice.halloween.inf_rate = 4;

	// подвозим кого-то на машине
	Alice.carguest.monthly_rides = 0;
	Alice.carguest.price_one_ride = 500;
	Alice.carguest.monthly_income = 0;
	Alice.carguest.car_damage_cost = 0;
	Alice.carguest.rowdy_passengers = 0;
	Alice.carguest.total_damage = 0;
	Alice.carguest.rowdy_count = 0;
	Alice.carguest.inf_rate = 3.0;

	// бизнес ALICE'ONE
	Alice.business.company_cash = 500'000;
	Alice.business.monthly_revenue = 0;
	Alice.business.production_cost = 80'000;
	Alice.business.marketing = 20'000;
	Alice.business.rent = 30'000;
	Alice.business.utilities = 10'000;   // свет, вода, отопление
	Alice.business.raw_materials = 40'000;
	Alice.business.employees = 0;
	Alice.business.team_builder = 0;
	Alice.business.is_active = false;   // бизнес пока не активен

	// цены на продукцию (растут с качеством)
	Alice.business.dog_house_price = 12'000;
	Alice.business.cat_house_price = 8'000;
	Alice.business.reptile_house_price = 5'000;
	Alice.business.fish_castle_price = 3'000;

	// продажи
	Alice.business.monthly_sales_dogs = 0;
	Alice.business.monthly_sales_cats = 0;
	Alice.business.monthly_sales_reptiles = 0;
	Alice.business.monthly_sales_fish = 0;

	Alice.business.inf_rate = 3.2;

	// питание и РПП
	Alice.eating.healthy_food = 15'000;
	Alice.eating.relapse_food = 3'000;   // базовые траты на один срыв
	Alice.eating.relapse_count = 0;
	Alice.eating.stress_level = 20;
	Alice.eating.is_healthy_mode = true;   // Алиса старается питаться правильно
	Alice.eating.relapse_probability = 0.15;   // 15% вероятность срыва изначально
	Alice.eating.inf_rate = 3.8;

	// усталость
	Alice.fatigue.level = 0;
	Alice.fatigue.burnout_rate = 5;
	Alice.fatigue.is_searching_job = false;
	Alice.fatigue.months_searching = 0;

	// работа
	Alice.job.has_job = false;
	snprintf(Alice.job.position, sizeof(Alice.job.position), "%s", "None");
	Alice.job.salary = 0;
	Alice.job.experience = 0;
	Alice.job.vacation_days = 0;
	Alice.job.on_sick_leave = false;
	Alice.job.sick_leave_months = 0;

	// травмы
	Alice.injury.has_injury = false;
	snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "None");
	Alice.injury.treatment_cost = 0;
	Alice.injury.recovery_months = 0;
	Alice.injury.needs_surgery = false;
	Alice.injury.surgery_cost = 0;
	Alice.injury.inf_rate = 7.0;
	Alice.injury.permanent_damage = false;

	// отношения
	Alice.relationship.has_boyfriend = false;
	Alice.relationship.relationship_months = 0;
	Alice.relationship.relationship_quality = 0;
	Alice.relationship.restaurant_spent = 8000;
	Alice.relationship.cosmetics_spent = 5000;
	Alice.relationship.small_wants_spent = 3000;
	Alice.relationship.handmade_gifts_spent = 2000;
	Alice.relationship.clothes_increase = 5000;
	Alice.relationship.shoes_increase = 3000;
	Alice.relationship.jewelry_increase = 2000;
	Alice.relationship.boyfriend_pays = true;
	Alice.relationship.last_gift_amount = 0;
	Alice.relationship.inf_rate = 4.2;
}




// Д О Х О Д Ы   И   Р А С Х О Д Ы

// машинка
void alice_car() {
	float monthly_rate = get_monthly_rate(Alice.car.inf_rate);
	Alice.car.maintenance = apply_inflation(Alice.car.maintenance, monthly_rate);
	Alice.car.gas = apply_inflation(Alice.car.gas, monthly_rate);
	Alice.car.coolant_flush = apply_inflation(Alice.car.coolant_flush, monthly_rate);
	Alice.car.washer_fluid = apply_inflation(Alice.car.washer_fluid, monthly_rate);
	Alice.car.osago = apply_inflation(Alice.car.osago, monthly_rate);
	Alice.car.casco = apply_inflation(Alice.car.casco, monthly_rate);
	Alice.car.green_card = apply_inflation(Alice.car.green_card, monthly_rate);

	Alice.bank.account -= Alice.car.gas 
	+ Alice.car.maintenance 
	+ Alice.car.coolant_flush 
	+ Alice.car.osago
	+ Alice.car.casco
	+ Alice.car.green_card;
};

// питомец
void alice_humster() {
	float monthly_rate = get_monthly_rate(Alice.animal.inf_rate);
	Alice.animal.food = apply_inflation(Alice.animal.food, monthly_rate);
	Alice.animal.vet = apply_inflation(Alice.animal.vet, monthly_rate);
	Alice.animal.toys = apply_inflation(Alice.animal.toys, monthly_rate);
	Alice.animal.vitamins = apply_inflation(Alice.animal.vitamins, monthly_rate);
	Alice.animal.treats = apply_inflation(Alice.animal.treats, monthly_rate);
	Alice.animal.shampoo = apply_inflation(Alice.animal.shampoo, monthly_rate);
	Alice.animal.grooming = apply_inflation(Alice.animal.grooming, monthly_rate);

	Alice.bank.account -= Alice.animal.food
	+ Alice.animal.toys
	+ Alice.animal.vitamins
	+ Alice.animal.treats;
	
	if (month % 6 == 0) {
		Alice.bank.account -= Alice.animal.grooming
		+ Alice.animal.shampoo;
	}

	if (month == 8) {
		Alice.bank.account -= Alice.animal.vet;
	}
};

// путешествия
void alice_travel() {
	float monthly_rate = get_monthly_rate(Alice.payments.inf_rate);
	Alice.travel = apply_inflation(Alice.travel, monthly_rate);

	if (month == 7 and Alice.bank.deposit >= 90'000) {
		Alice.bank.deposit -= Alice.travel;
	}
};

// зп
void alice_salary() {
	if ((month == 4) and (year % 5) == 0) {
		Alice.salary *= 103/100;
	}

	Alice.bank.account += Alice.salary;
}

// регулярные траты
void alice_regular_payments() {
	float monthly_rate = get_monthly_rate(Alice.payments.inf_rate);
	Alice.payments.food = apply_inflation(Alice.payments.food, monthly_rate);
	Alice.payments.cloth = apply_inflation(Alice.payments.cloth, monthly_rate);
	Alice.payments.subscription = apply_inflation(Alice.payments.subscription, monthly_rate);
	Alice.payments.gifts = apply_inflation(Alice.payments.gifts, monthly_rate);

	Alice.bank.account -= Alice.payments.food
	+ Alice.payments.cloth
	+ Alice.payments.subscription
	+ Alice.payments.gifts;
}

// здоровая алиска
void alice_health() {
	float mounthly_rate = get_monthly_rate(Alice.health.inf_rate);
	Alice.health.dentist = apply_inflation(Alice.health.dentist, mounthly_rate);
	Alice.health.med_chest = apply_inflation(Alice.health.med_chest, mounthly_rate);
	Alice.health.disease = apply_inflation(Alice.health.disease, mounthly_rate);
	Alice.health.insurance = apply_inflation(Alice.health.insurance, mounthly_rate);
	Alice.health.med_examination = apply_inflation(Alice.health.med_examination, mounthly_rate);

	if (month == 1) {
		Alice.bank.account -= Alice.health.insurance;
	}

	if (month == 2) {
		Alice.health.age += 1;
	}

	if (month == 3) {
		Alice.bank.account -= Alice.health.med_examination;
	}

	if (month == 9) {
		Alice.bank.account -= Alice.health.dentist;
	}

Alice.bank.account -= Alice.health.med_chest;

// расходы на болезни зависят от возраста
float age_factor = Alice.health.age / 25.0;
Alice.bank.account -= (Alice.health.disease * age_factor);
}

// жилье
void alice_accomodation() {
float monthly_rate = get_monthly_rate(Alice.flat.inf_rate);
	Alice.flat.appliance = apply_inflation(Alice.flat.appliance, monthly_rate);
	Alice.flat.renting = apply_inflation(Alice.flat.renting, monthly_rate);
	
	Alice.bank.account -= Alice.flat.renting;

	if (month == 4) {
	Alice.bank.account -= Alice.flat.appliance;
	}
}

// образование
void alice_education() {
	float monthly_rate = get_monthly_rate(Alice.education.inf_rate);
	Alice.education.books = apply_inflation(Alice.education.books, monthly_rate);
	Alice.education.courses = apply_inflation(Alice.education.courses, monthly_rate);
	Alice.education.hobby = apply_inflation(Alice.education.hobby, monthly_rate);

	Alice.bank.account -= Alice.education.books;

	if (month == 6 || month == 7 || month == 8) {
		Alice.bank.account -= Alice.education.hobby;
	}

	if (month == 1 || month == 7) {
		Alice.bank.account -= Alice.education.courses;
	}
}

// благотворительностьь
void alice_charity() {
	float monthly_rate = get_monthly_rate(Alice.charity.inf_rate);
	Alice.charity.special = apply_inflation(Alice.charity.special, monthly_rate);
	Alice.charity.donations = apply_inflation(Alice.charity.special, monthly_rate);
	
	Alice.bank.account -= Alice.charity.donations;
	
	if (month == 12) {
		Alice.bank.account -= Alice.charity.special;
	}
}

// досуг
void alice_leisure() {
	float monthly_rate = get_monthly_rate(Alice.leisure.inf_rate);
	Alice.leisure.entertainment = apply_inflation(Alice.leisure.entertainment, monthly_rate);
	Alice.leisure.sport = apply_inflation(Alice.leisure.sport, monthly_rate);
	Alice.leisure.vacation = apply_inflation(Alice.leisure.vacation, monthly_rate);
	
	Alice.bank.account -= Alice.leisure.entertainment 
	+ Alice.leisure.sport;
	
	if (month == 6) {
		Alice.bank.account -= Alice.leisure.vacation;
	}
}

// найб ребяток для бизнеса
void alice_hire_team() {
	int chance = rand() % 100 + 1;

	printf("\n hiring team for ALICE'ONE\n");

	if (chance <= 3) {
		Alice.business.employees = 4;
		Alice.business.team_builder = 100;
		Alice.business.is_active = true;
		printf("[Alice found a brilliant team!\n");
		printf("all product prices increased by 50%% due to premium quality\n");

		Alice.business.dog_house_price *= 1.5;
		Alice.business.cat_house_price *= 1.5;
		Alice.business.reptile_house_price *= 1.5;
		Alice.business.fish_castle_price *= 1.5;
	}

	else if (chance <= 10) {
		Alice.business.employees = 4;
		Alice.business.team_builder = 80;
		Alice.business.is_active = true;
		printf("Alice hired an experienced team!\n");
		printf("product prices increased by 25%%\n");

		Alice.business.dog_house_price *= 1.25;
		Alice.business.cat_house_price *= 1.25;
		Alice.business.reptile_house_price *= 1.25;
		Alice.business.fish_castle_price *= 1.25;

	}

	else if (chance <= 20) {
		Alice.business.employees = 4;
		Alice.business.team_builder = 60;
		Alice.business.is_active = true;
		printf("Alice found a decent team!\n");
		printf("prices remain standard\n");
	}

	else if (chance <= 28) {
		Alice.business.employees = 4;
		Alice.business.team_builder = 40;
		Alice.business.is_active = true;
		printf("Alice hired beginners!\n");
		printf("prices reduced by 15%% to attract customers\n");

		Alice.business.dog_house_price *= 0.85;
		Alice.business.cat_house_price *= 0.85;
		Alice.business.reptile_house_price *= 0.85;
		Alice.business.fish_castle_price *= 0.85;
	}

	else if (chance <= 30) {
		Alice.business.employees = 2;
		Alice.business.team_builder = 30;
		Alice.business.is_active = true;
		printf("two employees constantly argue!\n");
		printf("prices reduced by 30%%\n");

		Alice.business.dog_house_price *= 0.7;
		Alice.business.cat_house_price *= 0.7;
		Alice.business.reptile_house_price *= 0.7;
		Alice.business.fish_castle_price *= 0.7;
	}

	else if (chance <= 33) {
		Alice.business.employees = 1;
		Alice.business.team_builder = 20;
		Alice.business.is_active = true;
		printf("production is extremely slow!\n");
		printf("prices reduced by 40%%\n");

		Alice.business.dog_house_price *= 0.6;
		Alice.business.cat_house_price *= 0.6;
		Alice.business.reptile_house_price *= 0.6;
		Alice.business.fish_castle_price *= 0.6;
	}

	else {
		if (Alice.business.employees == 0) {
			printf("no suitable team found this month\n");
			printf("Alice continues searching for employees...\n");
		}
		else {
			// команда уже есть, просто ничего не меняем
			printf("business continues as usual\n");
		}
	}

	if (Alice.business.is_active) {
		printf("\nTeam status:\n");
		printf(" %d employees\n", Alice.business.team_builder);
		printf("Prices: dogs=%lld cats=%lld reptilies=%lld fish=%lld",
		Alice.business.dog_house_price, Alice.business.cat_house_price,
		Alice.business.reptile_house_price, Alice.business.fish_castle_price);
	}
}

// работа бизнеса алиски
void alice_business_operations() {
	if (!Alice.business.is_active)  { // бизнес НЕ активен 
		if (year >= 2026 and month >= 3) {
			alice_hire_team();
	}
	return;
	}

	// инфляция для бизнеса
	float monthly_rate = get_monthly_rate(Alice.business.inf_rate);
	Alice.business.production_cost = apply_inflation(Alice.business.production_cost, monthly_rate);
	Alice.business.marketing = apply_inflation(Alice.business.marketing, monthly_rate);
	Alice.business.rent = apply_inflation(Alice.business.rent, monthly_rate);
	Alice.business.utilities = apply_inflation(Alice.business.utilities, monthly_rate);
	Alice.business.raw_materials = apply_inflation(Alice.business.raw_materials, monthly_rate);
	Alice.business.dog_house_price = apply_inflation(Alice.business.dog_house_price, monthly_rate);
	Alice.business.cat_house_price = apply_inflation(Alice.business.cat_house_price, monthly_rate);
	Alice.business.reptile_house_price = apply_inflation(Alice.business.reptile_house_price, monthly_rate);
	Alice.business.fish_castle_price = apply_inflation(Alice.business.fish_castle_price, monthly_rate);

	float productivity = Alice.business.team_builder / 100.0;
	int base_sales = Alice.business.employees * 10;
	float quality_factor = 0.5 + (productivity * 0.8);

	// колебания спроса от 70 до 130%
	int demand_variation = 70 + (rand() %60);

	// продажи за месяц
	Alice.business.monthly_sales_dogs = base_sales * quality_factor * (demand_variation / 100.0);
	Alice.business.monthly_sales_cats = base_sales * quality_factor * (demand_variation / 100.0);
	Alice.business.monthly_sales_reptiles = base_sales * quality_factor * (demand_variation / 100.0);
	Alice.business.monthly_sales_fish = base_sales * quality_factor * (demand_variation / 100.0);

	// выручка от продаж
	RUB revenue = (Alice.business.monthly_sales_dogs * Alice.business.dog_house_price) +
		(Alice.business.monthly_sales_cats * Alice.business.cat_house_price) +
		(Alice.business.monthly_sales_reptiles * Alice.business.reptile_house_price) +
		(Alice.business.monthly_sales_fish * Alice.business.fish_castle_price);

	Alice.business.monthly_revenue = revenue;

	// расходы бизнеса за месяц
	RUB total_expenses = Alice.business.production_cost +
		Alice.business.marketing +
		Alice.business.rent +
		Alice.business.utilities +
		Alice.business.raw_materials;

	// прибыль/убыток за месяц
	RUB monthly_profit = revenue - total_expenses;

	// обновляем деньги компании
	Alice.business.company_cash += monthly_profit;

	// отчет: что происходит с бизнесом
	if (month % 3 == 0) {
		printf("\n Sales in this month:\n");
		printf("  Dog houses sold: %d x %lld RUB = %lld RUB\n",
			Alice.business.monthly_sales_dogs, Alice.business.dog_house_price,
			Alice.business.monthly_sales_dogs * Alice.business.dog_house_price);
		printf("  Cat houses sold: %d x %lld RUB = %lld RUB\n",
			Alice.business.monthly_sales_cats, Alice.business.cat_house_price,
			Alice.business.monthly_sales_cats * Alice.business.cat_house_price);
		printf("  Reptile houses sold: %d x %lld RUB = %lld RUB\n",
			Alice.business.monthly_sales_reptiles, Alice.business.reptile_house_price,
			Alice.business.monthly_sales_reptiles * Alice.business.reptile_house_price);
		printf("  Fish castles sold: %d x %lld RUB = %lld RUB\n",
			Alice.business.monthly_sales_fish, Alice.business.fish_castle_price,
			Alice.business.monthly_sales_fish * Alice.business.fish_castle_price);
		printf("  Total revenue: %lld RUB\n", revenue);
		printf("  Total expenses: %lld RUB\n", total_expenses);
		printf("  Monthly profit: %lld RUB\n", monthly_profit);
		printf("  Company cash: %lld RUB\n", Alice.business.company_cash);
	}

	// алиса может забрать часть прибыли себе
	if (monthly_profit > 0 and month == 12) {
		RUB dividend = monthly_profit * 0.3;
		Alice.bank.deposit += dividend;
		Alice.business.company_cash -= dividend;
		printf("Alice took %lld RUB from business profit\n", dividend);
	}

	// если убыток компании составляет более 1'000'000, то она может закрыться
	if (Alice.business.company_cash < -1'000'000) {
		printf("Alice'one is bankrupt! Business closes.\n");
		Alice.business.is_active = false;
		Alice.business.employees = 0;
	}
}

// питание алиски
void alice_eating_disorder() {
	float monthly_rate = get_monthly_rate(Alice.eating.inf_rate);
	Alice.eating.healthy_food = apply_inflation(Alice.eating.healthy_food, monthly_rate);
	Alice.eating.relapse_food = apply_inflation(Alice.eating.relapse_food, monthly_rate);

	// базовые траты на питание, если алиска на пп

	if (Alice.eating.is_healthy_mode) {
		Alice.bank.account -= Alice.eating.healthy_food;
}

// расчет вероятности срыва в этом месяце
// чем выше уровень стресса, тем выше вероятность срыва
	int stress_from_age = Alice.health.age / 10;   // каждые 10 лет +1 к стрессу
	int stress_from_business = 0;
	if (Alice.business.is_active and Alice.business.company_cash < 0) {
		stress_from_business = 30;   // бизнес в убытке - сильный стресс
	}
	else if (Alice.business.is_active and Alice.business.company_cash < 1'000'000 and Alice.business.company_cash > 0) {
		stress_from_business = 15;
	}

	int stress_from_money = 0;
	RUB total_money = Alice.bank.account + Alice.bank.deposit;
	if (total_money < 50'000) {
		stress_from_money = 40;
	}
	else if (total_money < 100'000) {
		stress_from_money = 20;
	}
	else if (total_money < 200'000) {
		stress_from_money = 10;
	}

	// обновляем уровень стресса
	Alice.eating.stress_level = 20 
	+ stress_from_age 
	+ stress_from_business 
	+ stress_from_money;
	if (Alice.eating.stress_level > 100) Alice.eating.stress_level = 100;

	// вероятность срыва = базовый шанс 15% + уровень стресса / 4
	// максимальная вероятность 40% при стрессе 100
	Alice.eating.relapse_probability = 0.15 + (Alice.eating.stress_level / 4.0 / 100.0);
	if (Alice.eating.relapse_probability > 0.40) Alice.eating.relapse_probability = 0.40;

	int chance = rand() % 100 + 1;
	int probability_percent = Alice.eating.relapse_probability * 100;

	// сброс количества срывов в новом месяце
	Alice.eating.relapse_count = 0;

	printf("Stress level: %d/100\n", Alice.eating.stress_level);
	printf("Relapse probability: %.1f%%\n", Alice.eating.relapse_probability * 100);

	// определяем, будет ли срыв
	int relapse_severity;
	if (chance <= probability_percent) {
		// алиска сорвалась( теперь вычислим его тяжесть:
		relapse_severity = 1 + (rand() % 4);  // от 1 до 4 срывов в месяц

		// тяжесть срыва зависит от уровня стресса
		if (Alice.eating.stress_level > 70) {
			relapse_severity += 2;  // тяжелый стресс = больше срывов
		}
		else if (Alice.eating.stress_level > 50) {
			relapse_severity += 1;
		}

		if (relapse_severity > 7) 
			relapse_severity = 7;  // максимум 7 срывов

		Alice.eating.relapse_count = relapse_severity;

		// расходы на срывы
		RUB total_relapse_cost = Alice.eating.relapse_food * relapse_severity;
		Alice.bank.account -= total_relapse_cost;

		printf("\n Alice had a food relapse!\n");
		printf("Number of relapses this month: %d\n", relapse_severity);
		printf("Money spent on relapse foods: %lld RUB\n", total_relapse_cost);

		// типы срывов 
		for (int i = 0; i < relapse_severity; i++) {
			int relapse_type = rand() % 5;
			switch (relapse_type) {
			case 0:
				printf("Bought a large chocolate cake (3'000 RUB)\n");
				break;
			case 1:
				printf("Bought several chocolate bars (500 RUB each)\n");
				break;
			case 2:
				printf("Bought ice cream and cookies (800 RUB)\n");
				break;
			case 3:
				printf("Ordered fast food delivery (1'200 RUB)\n");
				break;
			case 4:
				printf("  - Bought candies and pastries (600 RUB)\n");
				break;
			}
		}
}

// доп расходы на лекарства из-за ухучщения здоровья
float health_penalty = relapse_severity * 0.02; 
RUB extra_health_cost = Alice.health.disease * health_penalty;
Alice.bank.account -= extra_health_cost;
printf("\n +%lld RUB for medications \n", extra_health_cost);

// срывов слишком много => алиска может заболеть
int illness_cost;
if (relapse_severity >= 5) {
	RUB ilnesss_cost = Alice.health.disease * 1.5;
	Alice.bank.account -= ilnesss_cost;
	printf(" Severe relapse caused illness! +%lld RUB\n", illness_cost);
}

else {
	// нет срыва в этом месяце
	printf("\nAlice maintained healthy eating!\n");

	// бонус к здоровью за правильное питание
	RUB health_bonus = Alice.health.med_chest * 0.3;  // экономия 30% на лекарствах
	Alice.bank.account += health_bonus;
	printf("Health bonus saved: +%lld RUB\n", health_bonus);

	// если долго нет срывов, стресс постепенно снижается
	static int months_without_relapse = 0;
	months_without_relapse++;
	if (months_without_relapse >= 3) {
		printf("3 months without relapse! Stress decreased!\n");
		Alice.eating.stress_level = Alice.eating.stress_level * 0.8;
		months_without_relapse = 0;
	}
}

// статистика за месяц
printf("\nMonthly eating summary\n");
printf("Healthy food budget spent: %lld RUB\n", Alice.eating.healthy_food);
printf("Stress level: %d/100\n", Alice.eating.stress_level);
}

// случайные травмы
void alice_random_injury() {
	// если уже есть травма/алиска на больничном => новые травмы не получает
	if(Alice.injury.has_injury || Alice.job.on_sick_leave) {
	return;
	}

	// базовый шанс получить травму
	int chance = rand() % 100 + 1;
	if (chance >8) return; // 92% что все окей

	printf("\n Injury \n");

	int injury_type;
	injury_type = rand() % 24 + 1;
	

	switch (injury_type) {

	case 1:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Ankle sprain");
		Alice.injury.treatment_cost = 15'000;
		Alice.injury.recovery_months = 2;
		Alice.injury.needs_surgery = false;
		printf("Alice had sprained her ankle while running...\n");
		break;

	case 2:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Wrist fracture");
		Alice.injury.treatment_cost = 45'000;
		Alice.injury.recovery_months = 3;
		Alice.injury.needs_surgery = false;
		printf("Alice had fell and fractured her wrist...\n");
		break;

	case 3:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Knee ligament tear");
		Alice.injury.treatment_cost = 120'000;
		Alice.injury.recovery_months = 6;
		Alice.injury.needs_surgery = true;
		Alice.injury.surgery_cost = 80'000;
		printf("Alice tore her knee ligament during training...\n");
		break;

	case 4:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Shoulder dislocation");
		Alice.injury.treatment_cost = 25'000;
		Alice.injury.recovery_months = 2;
		Alice.injury.needs_surgery = false;
		printf("Alice dislocated her shoulder while swimming...\n");
		break;

	case 5:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Back muscle strain");
		Alice.injury.treatment_cost = 8'000;
		Alice.injury.recovery_months = 1;
		Alice.injury.needs_surgery = false;
		printf("Alice strained her back muscles at the gym...\n");
		break;

	case 6:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Concussion");
		Alice.injury.treatment_cost = 60'000;
		Alice.injury.recovery_months = 3;
		Alice.injury.needs_surgery = false;
		printf("Alice hit her head and got a concussion...\n");
		break;

	case 7:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Achilles tendon rupture");
		Alice.injury.treatment_cost = 200'000;
		Alice.injury.recovery_months = 8;
		Alice.injury.needs_surgery = true;
		Alice.injury.surgery_cost = 150'000;
		printf("Alice ruptured her Achilles tendon...\n");
		break;

	case 8:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Rib fracture");
		Alice.injury.treatment_cost = 35'000;
		Alice.injury.recovery_months = 2;
		Alice.injury.needs_surgery = false;
		printf("Alice fractured a rib during workout...\n");
		break;

	case 9:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Tennis elbow");
		Alice.injury.treatment_cost = 12'000;
		Alice.injury.recovery_months = 3;
		Alice.injury.needs_surgery = false;
		printf("Alice developed tennis elbow...\n");
		break;

	case 10:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Hamstring pull");
		Alice.injury.treatment_cost = 10'000;
		Alice.injury.recovery_months = 1;
		Alice.injury.needs_surgery = false;
		printf("Alice pulled her hamstring while sprinting...\n");
		break;

	case 11:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "ACL tear");
		Alice.injury.treatment_cost = 250'000;
		Alice.injury.recovery_months = 12;
		Alice.injury.needs_surgery = true;
		Alice.injury.surgery_cost = 180'000;
		printf("Alice tore her ACL! Serious injury...\n");
		break;

	case 12:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Groin strain");
		Alice.injury.treatment_cost = 8'000;
		Alice.injury.recovery_months = 1;
		Alice.injury.needs_surgery = false;
		printf("Alice strained her groin during stretching...\n");
		break;

	case 13:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Stress fracture (foot)");
		Alice.injury.treatment_cost = 30'000;
		Alice.injury.recovery_months = 3;
		Alice.injury.needs_surgery = false;
		printf("Alice developed a stress fracture in her foot...\n");
		break;

	case 14:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Rotator cuff tear");
		Alice.injury.treatment_cost = 90'000;
		Alice.injury.recovery_months = 5;
		Alice.injury.needs_surgery = true;
		Alice.injury.surgery_cost = 70'000;
		printf("Alice tore her rotator cuff while swimming...\n");
		break;

	case 15:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Meniscus tear");
		Alice.injury.treatment_cost = 100'000;
		Alice.injury.recovery_months = 4;
		Alice.injury.needs_surgery = true;
		Alice.injury.surgery_cost = 90'000;
		printf("Alice tore her meniscus during squat...\n");
		break;

	case 16:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Cervical spine injury");
		Alice.injury.treatment_cost = 180'000;
		Alice.injury.recovery_months = 6;
		Alice.injury.needs_surgery = true;
		Alice.injury.surgery_cost = 200'000;
		printf("Alice injured her cervical spine...\n");
		break;

	case 17:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Broken collarbone");
		Alice.injury.treatment_cost = 50'000;
		Alice.injury.recovery_months = 2;
		Alice.injury.needs_surgery = false;
		printf("Alice broke her collarbone in a fall...\n");
		break;

	case 18:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Carpal tunnel syndrome");
		Alice.injury.treatment_cost = 20'000;
		Alice.injury.recovery_months = 3;
		Alice.injury.needs_surgery = true;
		Alice.injury.surgery_cost = 40'000;
		printf("Alice developed carpal tunnel syndrome...\n");
		break;

	case 19:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Hip labral tear");
		Alice.injury.treatment_cost = 130'000;
		Alice.injury.recovery_months = 5;
		Alice.injury.needs_surgery = true;
		Alice.injury.surgery_cost = 120'000;
		printf("Alice tore her hip labrum...\n");
		break;

	case 20:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Concussion with memory loss");
		Alice.injury.treatment_cost = 100'000;
		Alice.injury.recovery_months = 4;
		Alice.injury.needs_surgery = false;
		Alice.injury.permanent_damage = true;
		printf("Alice got a severe concussion with memory loss...\n");
		break;

	case 21:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Patellar dislocation");
		Alice.injury.treatment_cost = 40'000;
		Alice.injury.recovery_months = 2;
		Alice.injury.needs_surgery = false;
		printf("Alice's kneecap got dislocated...\n");
		break;

	case 22:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Lumbar disc herniation");
		Alice.injury.treatment_cost = 150'000;
		Alice.injury.recovery_months = 6;
		Alice.injury.needs_surgery = true;
		Alice.injury.surgery_cost = 160'000;
		printf("Alice herniated a disc in her lower back...\n");
		break;

	case 23:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Facial fracture");
		Alice.injury.treatment_cost = 80'000;
		Alice.injury.recovery_months = 2;
		Alice.injury.needs_surgery = true;
		Alice.injury.surgery_cost = 100'000;
		printf("Alice suffered a facial fracture...\n");
		break;

	case 24:
		snprintf(Alice.injury.injury_name, sizeof(Alice.injury.injury_name), "%s", "Multiple bruises and contusions");
		Alice.injury.treatment_cost = 5'000;
		Alice.injury.recovery_months = 1;
		Alice.injury.needs_surgery = false;
		printf("Alice has multiple bruises from a fall...\n");
		break;
}

	Alice.injury.has_injury = true;
	printf("Injury: %s\n", Alice.injury.injury_name);
	printf("Treatment cost: %lld RUB\n", Alice.injury.treatment_cost);
	printf("Recovery time: %d months\n", Alice.injury.recovery_months);

	if (Alice.injury.needs_surgery) {
		printf("Surgery! Cost: %lld RUB\n", Alice.injury.surgery_cost);

		// 70% шанс, что алиска согласится на операцию
		int surgery_chance = rand() % 100 + 1;

		if (surgery_chance <= 70 and (Alice.bank.deposit + Alice.bank.account) 
			>= Alice.injury.surgery_cost) {
			Alice.bank.deposit -= Alice.injury.surgery_cost;
			printf("Alice underwent surgery! %lld RUB paid\n", Alice.injury.surgery_cost);
		}

		else if (surgery_chance <= 70) {
			printf("Alice needs surgery but can't afford it! Taking a loan...\n");
			
			// берет кредит (отрицательный баланс)
			Alice.bank.deposit -= Alice.injury.surgery_cost;
		}

		else {
			printf("Alice refused surgery, recovery will take longer\n");
			Alice.injury.recovery_months += 3;
		}
	}

	// траты на лечение
	Alice.bank.account -= Alice.injury.treatment_cost;

	// уходит на больничный
	Alice.job.on_sick_leave = true;
	Alice.job.sick_leave_months = Alice.injury.recovery_months;
	Alice.job.vacation_days = 0;

	printf("Alice is now on sick leave for %d months\n", Alice.injury.recovery_months);
}

// ежемесячные расходы на уход (если есть потеря памяти)
void alice_permanent_care_cost() {
	if (Alice.injury.permanent_damage) {
		RUB care_cost = 5000;  // базовые расходы на уход
		apply_inflation(care_cost, get_monthly_rate(Alice.injury.inf_rate));
		Alice.bank.account -= care_cost;
		printf("[CARE] Permanent injury care cost: %lld RUB\n", care_cost);

		// дополнительные последствия: стресс не снижается ниже 50
		if (Alice.eating.stress_level < 50) {
			Alice.eating.stress_level = 50;
		}
	}
}

// начисление процентов по вкладу
// перекладывание текущего счета на депозит
void alice_bank_interest() {
	Alice.bank.deposit += Alice.bank.account;
	Alice.bank.account = 0;

	Alice.bank.deposit += Alice.bank.deposit * (Alice.bank.pp / 12.0 / 100.0);
	}

// усталось от бизнеса + поиск новой работы
void alice_business_fatigue() {
// если бизнес не активен или уже ищет работу, не накапливаем усталость
	if (!Alice.business.is_active || Alice.fatigue.is_searching_job) {
		return;
}

	// накопление усталости от бизнеса
	// факторы, увеличивающие усталость:
	int fatigue_increase = 0;

	// бизнес в убытке => сильная усталость
	if (Alice.business.company_cash < 0) {
		fatigue_increase += 15;
	}

	// маленькая прибыль => умеренная усталость
	else if (Alice.business.monthly_revenue 
	< Alice.business.production_cost * 1.2) {
		fatigue_increase += 8;
	}

	// команда маленькая => больше работы на Алису
	if (Alice.business.employees < 3) {
		fatigue_increase += 10;
	}

	// низкий опыт команды => нужно контролировать всё
	if (Alice.business.team_builder < 50) {
		fatigue_increase += 7;
	}

	// высокий уровень стресса от РПП увеличивает усталость
	fatigue_increase += (Alice.eating.stress_level / 10);

	// базовое накопление усталости
	Alice.fatigue.level += (5 + fatigue_increase);

	if (Alice.fatigue.level > 100) Alice.fatigue.level = 100;

	printf("Current fatigue level: %d/100\n", Alice.fatigue.level);
	printf("Fatigue increase this month: %d\n", 5 + fatigue_increase);

	// если усталость достигла 100, начинаем искать новую работу
	if (Alice.fatigue.level >= 100 && !Alice.fatigue.is_searching_job) {
		printf("\n[Burnout warning] Alice is exhausted from the business!\n");
		printf("She decided to close the business and find a new job as a coach!\n");

		// закрываем бизнес
		Alice.business.is_active = false;
		Alice.business.employees = 0;

		// начинаем поиск работы
		Alice.fatigue.is_searching_job = true;
		Alice.fatigue.months_searching = 0;

		// последняя прибыль от бизнеса (если есть)
		if (Alice.business.company_cash > 0) {
			Alice.bank.deposit += Alice.business.company_cash;
			printf("Company cash %lld RUB transferred to personal deposit\n", Alice.business.company_cash);
		}
	}
}

// поиск новой работы
void alice_search_new_job() {
	if (!Alice.fatigue.is_searching_job) return;

	Alice.fatigue.months_searching++;

	printf("\n JOB SEARCH \n");
	printf("Searching month #%d\n", Alice.fatigue.months_searching);

	// шанс найти работу зависит от опыта и месяца поиска
	int chance_to_find = 30 + (Alice.fatigue.months_searching * 10);
	if (chance_to_find > 85) chance_to_find = 85;

	int chance = rand() % 100 + 1;

	if (chance <= chance_to_find) {
		// Алиса нашла работу! определяем какую
		int job_type = rand() % 5 + 1;

		Alice.job.has_job = true;
		Alice.job.experience = 0;
		Alice.job.vacation_days = 28;
		Alice.job.on_sick_leave = false;
		Alice.job.sick_leave_months = 0;
		Alice.fatigue.is_searching_job = false;

		RUB base_salary = 0;

		switch (job_type) {

		case 1:
			snprintf(Alice.job.position, sizeof(Alice.job.position), "%s", "Swimming Coach");
			base_salary = 70'000;
			printf("Alice got a job as a SWIMMING COACH!\n");
			break;

		case 2:
			snprintf(Alice.job.position, sizeof(Alice.job.position), "%s", "Group Fitness Instructor");
			base_salary = 65'000;
			printf("Alice got a job as a GROUP FITNESS INSTRUCTOR!\n");
			break;

		case 3:
			snprintf(Alice.job.position, sizeof(Alice.job.position), "%s", "Personal Trainer");
			base_salary = 85'000;
			printf("Alice got a job as a PERSONAL TRAINER!\n");
			break;

		case 4:
			snprintf(Alice.job.position, sizeof(Alice.job.position), "%s", "Children's Coach");
			base_salary = 60'000;
			printf("Alice got a job as a CHILDREN'S COACH!\n");
			break;

		case 5:
			snprintf(Alice.job.position, sizeof(Alice.job.position), "%s", "Running Coach");
			base_salary = 75'000;
			printf("Alice got a job as a RUNNING COACH!\n");
			break;
		}

	// зп зависит от возраста и опыта
	int age_bonus = (Alice.health.age - 25) / 5 * 5'000;
	if (age_bonus < 0) age_bonus = 0;

	Alice.job.salary = Alice.salary + age_bonus;
	Alice.salary = Alice.job.salary;  // теперь у Алисы другая зп

	printf("Salary: %lld RUB/month\n", Alice.job.salary);
	printf("Vacation days per year: %d\n", Alice.job.vacation_days);
	printf("Experience starts at: %d/100\n", Alice.job.experience);

	// сброс усталости
	Alice.fatigue.level = 0;
	Alice.eating.stress_level = Alice.eating.stress_level * 0.5;
	printf("\n Fresh start! Fatigue reset to 0, stress decreased by 50%% \n");
	}

	// если ищет слишком долго (больше года), возможно, снижает требования
	if(Alice.fatigue.months_searching >= 12) {
		printf("Long job search! Alice is considering lower-paid positions\n");
		chance_to_find += 20;
	}
}

// травмы и больничный
void alice_injury_recovery() {
	if (!Alice.job.on_sick_leave) return;

	printf("Recovering from: %s\n", Alice.injury.injury_name);
	printf("Months remaining: %d\n", Alice.job.sick_leave_months);

	// на больничном начисляется только часть зп
	RUB sick_leave_pay = Alice.salary * 0.6;
	Alice.bank.account += sick_leave_pay;
	printf("Sick leave payment (60%% of salary): %lld RUB\n", sick_leave_pay);

	// ежемесячные расходы на реабилитацию
	RUB rehab_cost = Alice.injury.treatment_cost * 0.1;
	Alice.bank.account -= rehab_cost;
	printf("Rehabilitation costs this month: %lld RUB\n", rehab_cost);

	Alice.job.sick_leave_months--;

	if (Alice.job.sick_leave_months < 0) {
		Alice.job.sick_leave_months = 0;
	}

	if (Alice.job.sick_leave_months <= 0) {
		// aлиса восстановилась!
		Alice.job.on_sick_leave = false;
		Alice.injury.has_injury = false;
		printf("\n Alice has fully recovered and can return to work!\n");

		// Опыт работы увеличивается после травмы
		Alice.job.experience += 5;
		if (Alice.job.experience > 100) Alice.job.experience = 100;
		printf("Work experience increased to %d/100\n", Alice.job.experience);
	}
}

// накопление опыта на работе
void alice_work_experience() {
	if (!Alice.job.has_job || Alice.job.on_sick_leave) return;

	// каждый месяц работы увеличивает опыт
	Alice.job.experience += 2;
	if (Alice.job.experience > 100) Alice.job.experience = 100;

	// каждый год работы (в августе) - повышение зарплаты
	if (month == 8 and (year % 1 == 0)) {
		RUB raise = Alice.job.salary * 0.05;
		Alice.job.salary += raise;
		Alice.salary = Alice.job.salary;
		printf("\n Work anniversary! Salary increased by 5%% to %lld RUB\n", Alice.job.salary);
	}

	// если опыт достиг 100, можно получить премию
	if (Alice.job.experience >= 100) {
		static bool bonus_received = false;
		if (!bonus_received && month == 12) {
			RUB bonus = Alice.job.salary * 2;
			Alice.bank.account += bonus;
			printf("\n Year-end bonus: %lld RUB\n", bonus);
		bonus_received = true;
		}
	}
}

// поиск парня
void alice_find_boyfriend() {
	// если уже есть парень, не ищет
	if (Alice.relationship.has_boyfriend) return;

	// если на больничном или нет денег, меньше шансов
	int chance_modifier = 0;
	if (Alice.job.on_sick_leave) chance_modifier = -10;
	if ((Alice.bank.account + Alice.bank.deposit) < 50000) chance_modifier = -5;

	// базовый шанс найти парня 5% в месяц
	int chance = rand() % 100 + 1;
	if (chance > 8 + chance_modifier) return;  // 8% шанс

	printf("\n NEW RELATIONSHIP! \n");

	Alice.relationship.has_boyfriend = true;
	Alice.relationship.relationship_months = 0;
	Alice.relationship.relationship_quality = 50 + (rand() % 40);

	// типы парней с разными характеристиками
	int boyfriend_type = rand() % 5 + 1;
	switch (boyfriend_type) {
	case 1:
		printf("Alice met him at a coffee shop!\n");
		printf("He's a romantic and generous man!\n");
		Alice.relationship.boyfriend_pays = true;
		break;
	case 2:
		printf("Alice met him at the gym!\n");
		printf("He's an athlete and shares her passion for sports!\n");
		Alice.relationship.boyfriend_pays = (rand() % 2 == 0);
		break;
	case 3:
		printf("Alice met him at an art exhibition!\n");
		printf("He's creative and understanding!\n");
		Alice.relationship.boyfriend_pays = true;
		break;
	case 4:
		printf("Alice met him through work connections!\n");
		printf("He's ambitious and hardworking!\n");
		Alice.relationship.boyfriend_pays = (rand() % 3 != 0);
		break;
	case 5:
		printf("Alice met him at the dog park!\n");
		printf("He loves animals just like her!\n");
		Alice.relationship.boyfriend_pays = false;
		break;
	}

	printf("Relationship quality: %d/100\n", Alice.relationship.relationship_quality);
	if (Alice.relationship.boyfriend_pays) {
		printf("He usually pays for dates!\n");
	}
	else {
		printf("They split expenses equally or Alice pays more\n");
	}

	// снижение стресса от новых отношений
	int stress_reduction = 15 + (rand() % 15);
	Alice.eating.stress_level -= stress_reduction;
	if (Alice.eating.stress_level < 0) Alice.eating.stress_level = 0;
	printf("Stress decreased by % d points!\n", stress_reduction);
}

// инфляция хелоуин
void alice_halloween_inflation() {
	float monthly_rate = get_monthly_rate(Alice.halloween.inf_rate);

	Alice.halloween.pumking = apply_inflation(Alice.halloween.pumking, monthly_rate);
	Alice.halloween.cosmetics = apply_inflation(Alice.halloween.cosmetics, monthly_rate);
	Alice.halloween.costume = apply_inflation(Alice.halloween.costume, monthly_rate);
	Alice.halloween.party_food = apply_inflation(Alice.halloween.party_food, monthly_rate);
}

// хеллоуин
void alice_halloween_spending() {
	if (month != 10) return;

	RUB halloween_cost = Alice.halloween.pumking +
		Alice.halloween.cosmetics +
		Alice.halloween.costume +
		Alice.halloween.party_food;

	Alice.bank.account -= halloween_cost;
	printf("\nHalloween expenses %lld RUB\n", halloween_cost);
}



// траты на отношения
void alice_relationship_spending() {
	if (!Alice.relationship.has_boyfriend) return;

	// базовое увеличение трат
	RUB extra_clothes = Alice.payments.cloth * (0.3 + (rand() % 30) / 100.0);
	RUB extra_shoes = Alice.payments.cloth * 0.2;
	RUB extra_jewelry = 2000 + (rand() % 5000);

	Alice.bank.account -= extra_clothes;
	Alice.bank.account -= extra_shoes;
	Alice.bank.account -= extra_jewelry;

	printf("\n RELATIONSHIP EXPENSES \n");
	printf("Wants to look cooler: spent %lld RUB on new clothes\n", extra_clothes);
	printf("Spent %lld RUB on stylish shoes\n", extra_shoes);
	printf("Spent %lld RUB on accessories and jewelry\n", extra_jewelry);

	// траты на рестораны
	Alice.relationship.restaurant_spent *= Alice.bank.month_inf;
	RUB restaurant_cost = Alice.relationship.restaurant_spent;

	// траты на косметику
	Alice.relationship.cosmetics_spent *= Alice.bank.month_inf;
	RUB cosmetics_cost = Alice.relationship.cosmetics_spent;

	// маленькие хотелки (кофе, такси, мелочи)
	Alice.relationship.small_wants_spent *= Alice.bank.month_inf;
	RUB small_wants = Alice.relationship.small_wants_spent;

	// кто платит?
	if (Alice.relationship.boyfriend_pays) {
		// парень платит большую часть
		printf("He took Alice to a restaurant! He paid %lld RUB\n",
		restaurant_cost);
		printf("He also bought her cosmetics for %lld RUB\n", cosmetics_cost);
		printf("He covered small wants: %lld RUB\n", small_wants);
		// Алиса тратит только 20% от этого
		RUB alice_share = (restaurant_cost + cosmetics_cost + small_wants) * 0.2;
		Alice.bank.account -= alice_share;
		printf("Alice paid only her share: %lld RUB\n", alice_share);
	}
	else {
		// Алиса платит сама
		Alice.bank.account -= restaurant_cost;
		Alice.bank.account -= cosmetics_cost;
		Alice.bank.account -= small_wants;
		printf("Restaurant date cost : % lld RUB(Alice paid)\n", restaurant_cost);
		printf("Cosmetics shopping: %lld RUB\n", cosmetics_cost);
		printf("Small wants and treats: %lld RUB\n", small_wants);
	}

	// накопление усталости от отношений (если качество низкое)
	if (Alice.relationship.relationship_quality < 50) {
		Alice.fatigue.level += 2;
		printf("Low relationship quality increases fatigue!\n");
	}
}

// подарки парню своими руками
void alice_handmade_gifts() {
	if (!Alice.relationship.has_boyfriend) return;

	// шанс сделать подарок (30% в месяц)
	int chance = rand() % 100 + 1;
	if (chance > 35) return;

	Alice.relationship.handmade_gifts_spent *= Alice.bank.month_inf;
	RUB gift_cost = Alice.relationship.handmade_gifts_spent;

	printf("\n HANDMADE GIFT \n");

	int gift_type = rand() % 8 + 1;
	switch (gift_type) {
	case 1:
		printf("Alice made a beautiful scrapbook with memories!\n");
		printf("Materials: colored paper, stickers, glue, ribbons\n");
		break;
	case 2:
		printf("Alice painted a portrait of them together!\n");
		printf("Materials: canvas, acrylic paints, brushes, varnish\n");
		break;
	case 3:
		printf("Alice knitted a warm scarf!\n");
		printf("Materials: wool yarn, knitting needles, buttons\n");
		break;
	case 4:
		printf("Alice wrote a poem collection and handmade the book!\n");
		printf("Materials: paper, binding tools, cover design\n");
		break;
	case 5:
		printf("Alice baked personalized cookies and cake!\n");
		printf("Materials: ingredients, decorative icing, packaging\n");
		break;
	case 6:
		printf("Alice made scented candles in jars!\n");
		printf("Materials: wax, essential oils, wicks, glass jars\n");
		break;
	case 7:
		printf("Alice created a mixtape with meaningful songs!\n");
		printf("Materials: USB drive, custom case, handwritten notes\n");
		break;
	case 8:
		printf("Alice made a terrarium in a glass bottle!\n");
		printf("Materials: glass container, soil, moss, tiny decorations\n");
		break;
	}

	Alice.bank.account -= gift_cost;
	printf("Handmade gift cost: %lld RUB\n", gift_cost);

	// подарок улучшает отношения
	int quality_boost = 5 + (rand() % 10);
	Alice.relationship.relationship_quality += quality_boost;
	if (Alice.relationship.relationship_quality > 100) Alice.relationship.relationship_quality = 100;
	printf("Relationship quality improved by %d points!\n", quality_boost);

	// снижение стресса от творчества
	int stress_reduction = 5 + (rand() % 10);
	Alice.eating.stress_level -= stress_reduction;
	if (Alice.eating.stress_level < 0) Alice.eating.stress_level = 0;
	printf("Stress decreased by %d points!\n", stress_reduction);
}

// подарки Алисе от парня
void alice_receive_gifts() {
	if (!Alice.relationship.has_boyfriend) return;

	// шанс получить подарок
	int chance = rand() % 100 + 1;
	if (chance > 28) return;

	printf("\n GIFT FROM BOYFRIEND \n");

	int gift_type = rand() % 12 + 1;
	RUB gift_value = 0;

	switch (gift_type) {
	case 1:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "flowers");
		gift_value = 2000 + (rand() % 5000);
		printf("He gave Alice a beautiful bouquet of roses! (%lld RUB)\n", gift_value);
		break;
	case 2:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "jewelry");
		gift_value = 5000 + (rand() % 20000);
		printf("He surprised Alice with elegant earrings! (%lld RUB)\n", gift_value);
		break;
	case 3:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "money");
		gift_value = 10000 + (rand() % 40000);
		printf("He gave Alice money for her dreams! (%lld RUB)\n", gift_value);  // УБРАН boyfriend_name
		break;
	case 4:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "perfume");
		gift_value = 3000 + (rand() % 8000);
		printf("He bought Alice luxurious perfume! (%lld RUB)\n", gift_value);
		break;
	case 5:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "handbag");
		gift_value = 7000 + (rand() % 25000);
		printf("He gifted Alice a designer handbag! (%lld RUB)\n", gift_value);
		break;
	case 6:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "tech");
		gift_value = 15000 + (rand() % 50000);
		printf("He bought Alice new AirPods! (%lld RUB)\n", gift_value);
		break;
	case 7:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "spa");
		gift_value = 4000 + (rand() % 10000);
		printf("He gave Alice a spa certificate! (%lld RUB)\n", gift_value);
		break;
	case 8:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "dinner");
		gift_value = 5000 + (rand() % 15000);
		printf("He took Alice to a Michelin restaurant! (%lld RUB)\n", gift_value);  // УБРАН boyfriend_name
		break;
	case 9:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "experience");
		gift_value = 8000 + (rand() % 20000);
		printf("He bought tickets to a concert! (%lld RUB)\n", gift_value);
		break;
	case 10:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "self-care");
		gift_value = 3000 + (rand() % 7000);
		printf("He gave Alice luxury skincare set! (%lld RUB)\n", gift_value);
		break;
	case 11:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "surprise");
		gift_value = 1000 + (rand() % 3000);
		printf("He left sweet notes and chocolates! (%lld RUB)\n", gift_value);
		break;
	case 12:
		snprintf(Alice.relationship.last_gift_type, sizeof(Alice.relationship.last_gift_type), "%s", "sports");
		gift_value = 6000 + (rand() % 15000);
		printf("He bought new yoga mat and sportswear! (%lld RUB)\n", gift_value);
		break;
	}

	Alice.relationship.last_gift_amount = gift_value;

	// деньги идут на счет, остальное - подарки
	if (strcmp(Alice.relationship.last_gift_type, "money") == 0) {
		Alice.bank.account += gift_value;
		printf("Money added to account!\n");
	}
	else {
		printf("Alice received a wonderful gift! She saved %lld RUB\n", gift_value);
	}

	// подарки снижают стресс
	int stress_reduction = 10 + (rand() % 20);
	Alice.eating.stress_level -= stress_reduction;
	if (Alice.eating.stress_level < 0) Alice.eating.stress_level = 0;
	printf("Stress decreased by %d points!\n", stress_reduction);

	// качество отношений улучшается
	Alice.relationship.relationship_quality += 3;
	if (Alice.relationship.relationship_quality > 100) Alice.relationship.relationship_quality = 100;
	printf("Relationship quality +3 (now %d/100)\n", Alice.relationship.relationship_quality);
}

// расставание
void alice_breakup() {
	if (!Alice.relationship.has_boyfriend) return;

	int breakup_chance = 0;

	// Плохое качество отношений => высокий шанс
	if (Alice.relationship.relationship_quality < 30) {
		breakup_chance = 25;
	}
	else if (Alice.relationship.relationship_quality < 50) {
		breakup_chance = 15;
	}
	else if (Alice.relationship.relationship_quality < 70) {
		breakup_chance = 8;
	}
	else {
		breakup_chance = 3;
	}

	// дополнительные факторы
	if (Alice.fatigue.level > 80) breakup_chance += 10;  // усталость портит отношения
	if (Alice.eating.stress_level > 70) breakup_chance += 8;

	int chance = rand() % 100 + 1;
	if (chance > breakup_chance) return;

	printf("\n BREAK UP! \n");
	printf("Alice and him broke up!\n");

	// причина расставания
	int reason = rand() % 6 + 1;
	switch (reason) {
	case 1:
		printf("Reason: Different life goals and priorities\n");
		break;
	case 2:
		printf("Reason: Constant arguments and misunderstandings\n");
		break;
	case 3:
		printf("Reason: He moved to another city\n");
		break;
	case 4:
		printf("Reason: Lost feelings, grew apart over time\n");
		break;
	case 5:
		printf("Reason: Trust issues and jealousy\n");
		break;
	case 6:
		printf("Reason: Alice's career demanded all her attention\n");
		break;
	}

	// расставание повышает стресс
	int stress_increase = 20 + (rand() % 30);
	Alice.eating.stress_level += stress_increase;
	if (Alice.eating.stress_level > 100) Alice.eating.stress_level = 100;
	printf("Stress increased by %d points!\n", stress_increase);

	// усталость тоже растет
	Alice.fatigue.level += 10;
	if (Alice.fatigue.level > 100) Alice.fatigue.level = 100;

	// сбрасываем отношения
	Alice.relationship.has_boyfriend = false;
	Alice.relationship.relationship_months = 0;
	Alice.relationship.relationship_quality = 0;
}

void alice_update_relationship_quality() {
	if (!Alice.relationship.has_boyfriend) return;

	Alice.relationship.relationship_months++;

	int quality_change = 0;

	// позитивные факторы
	if (Alice.eating.stress_level < 30) quality_change += 2;
	if (Alice.business.is_active && Alice.business.company_cash > 100000) quality_change += 1;
	if (Alice.job.has_job && Alice.job.experience > 50) quality_change += 1;

	// негативные факторы
	if (Alice.eating.stress_level > 70) quality_change -= 3;
	if (Alice.fatigue.level > 70) quality_change -= 2;
	if (Alice.injury.has_injury) quality_change -= 4;

	quality_change += (rand() % 7) - 3;

	Alice.relationship.relationship_quality += quality_change;
	if (Alice.relationship.relationship_quality > 100) Alice.relationship.relationship_quality = 100;
	if (Alice.relationship.relationship_quality < 0) Alice.relationship.relationship_quality = 0;

	// раз в 3 месяца показываем статус отношений
	if (Alice.relationship.relationship_months % 3 == 0) {
		printf("\n RELATIONSHIP UPDATE \n");
		printf("Together for %d months with him\n",
			Alice.relationship.relationship_months);
		printf("Current relationship quality: %d/100\n", Alice.relationship.relationship_quality);

		if (Alice.relationship.relationship_quality >= 80) {
			printf("Amazing relationship! Very happy together!\n");
		}
		else if (Alice.relationship.relationship_quality >= 60) {
			printf("Good relationship, some small issues\n");
		}
		else if (Alice.relationship.relationship_quality >= 40) {
			printf("Average relationship, need to work on it\n");
		}
		else {
			printf("Struggling relationship, risk of breakup!\n");
		}
	}
}

// ежемесячное инвестирование: откладываем 10% от зарплаты, если хватает
void alice_monthly_invest() {
	RUB to_invest = Alice.salary * 0.1;
	// Проверяем, что на счету достаточно денег плюс остаток на жизнь (60000)
	if (Alice.bank.account > to_invest + 60000) {
		Alice.bank.account -= to_invest;   // снимаем деньги со счета

		// распределяем инвестиции: 40% в акции, 35% в облигации, 25% в ликвидные фонды
		Alice.invest.stocks += static_cast<RUB>(to_invest * 0.40);
		Alice.invest.bonds += static_cast<RUB>(to_invest * 0.35);
		Alice.invest.liquid_funds += static_cast<RUB>(to_invest * 0.25);
	}
}

// доходность от инвестиций
void alice_investment_income() {
	// акции: случайная доходность от -4% до +5% (0.96 + случайное число от 0 до 0.09)
	float stock_market = 0.96 + (rand() % 9) / 100.0;
	Alice.invest.stocks = static_cast<RUB>(Alice.invest.stocks * stock_market);

	// облигации: стабильный рост 0.5% в месяц
	Alice.invest.bonds = static_cast<RUB>(Alice.invest.bonds * 1.005);

	// ликвидные фонды: рост 3% в месяц
	Alice.invest.liquid_funds = static_cast<RUB>(Alice.invest.liquid_funds * 1.03);
}

// вывод текущего состояния (раз в год)
void print_status() {
	RUB total_invest = Alice.invest.stocks + Alice.invest.bonds + Alice.invest.liquid_funds;
	RUB total_capital = Alice.bank.account + Alice.bank.deposit + total_invest;

	printf("Year %d:\n", year);
	printf("  Age: %d\n", Alice.health.age);
	printf("  Salary: %lld RUB\n", Alice.salary);
	printf("  Deposit: %lld RUB\n", Alice.bank.deposit);
	printf("  Investments: Stocks=%lld Bonds=%lld Liquid=%lld Total=%lld RUB\n",
		Alice.invest.stocks, Alice.invest.bonds, Alice.invest.liquid_funds, total_invest);
	printf("  TOTAL CAPITAL: %lld RUB\n", total_capital);
	printf("  Additional breakdown \n");
	printf("  Regular expenses: Food=%lld Cloth=%lld Gifts=%lld Subscr=%lld\n",
		Alice.payments.food, Alice.payments.cloth, Alice.payments.gifts, Alice.payments.subscription);
	printf("  Education: Courses=%lld Books=%lld Hobby=%lld\n",
		Alice.education.courses, Alice.education.books, Alice.education.hobby);
	printf("  Charity: Donations=%lld Special=%lld\n",
		Alice.charity.donations, Alice.charity.special);
	printf("  Leisure: Entertain=%lld Sport=%lld Vacation=%lld\n",
		Alice.leisure.entertainment, Alice.leisure.sport, Alice.leisure.vacation);
	printf("  Halloween: Pumking=%lld Cosmetics=%lld Costume=%lld Party_food=%lld\n");
	printf("  Carguest: Monthly ride=%lld Price for one ride=%lld\n");
		printf("  --- Business Alice'one ---\n");
	if (Alice.business.is_active) {
		printf("  Business ACTIVE | Team: %d emp | Experience: %d/100\n",
			Alice.business.employees, Alice.business.team_builder);
		printf("  Company cash: %lld RUB\n", Alice.business.company_cash);
		RUB total_business_value = Alice.business.company_cash +
			(Alice.business.employees * 50000) +
			(Alice.business.team_builder * 1000);
		printf("  Business value: ~%lld RUB\n", total_business_value);
	}
	else {
		printf("  Business NOT ACTIVE (searching for team)\n");
	}
	printf("  Eating and Health \n");
	printf("  Healthy food budget: %lld RUB\n", Alice.eating.healthy_food);
	printf("  Stress level: %d/100\n", Alice.eating.stress_level);
	printf("  Relapse probability: %.1f%%\n", Alice.eating.relapse_probability * 100);
	if (Alice.eating.relapse_count > 0) {
		printf("  RELAPSES this month: %d\n", Alice.eating.relapse_count);
	}
	else {
		printf(" No relapses this month\n");
	}

	printf("  Fatigue and Work \n");
	printf("  Business fatigue: %d/100\n", Alice.fatigue.level);
	if (Alice.fatigue.is_searching_job) {
		printf(" Searching for new job (month %d)\n", Alice.fatigue.months_searching);
	}

	if (Alice.job.has_job) {
		printf("  Current job: %s\n", Alice.job.position);
		printf("  Job salary: %lld RUB\n", Alice.job.salary);
		printf("  Experience: %d/100\n", Alice.job.experience);
		if (Alice.job.on_sick_leave) {
			printf(" ON SICK LEAVE (%d months remaining)\n", Alice.job.sick_leave_months);
		}
	}
	else if (!Alice.business.is_active && !Alice.fatigue.is_searching_job) {
		printf(" No active job or business\n");
	}

	if (Alice.injury.has_injury) {
		printf(" Injury Status \n");
		printf(" Current injury: %s\n", Alice.injury.injury_name);
		printf("  Recovery: %d months remaining\n", Alice.job.sick_leave_months);
	}

	printf(" Relationship Status \n");
	if (Alice.relationship.has_boyfriend) {
		printf("In a relationship with him (%d months)\n",
			Alice.relationship.relationship_months);
		printf("  Relationship quality: %d/100\n", Alice.relationship.relationship_quality);
		if (Alice.relationship.relationship_quality >= 80) {
			printf("  Status: Amazing!\n");
		}
		else if (Alice.relationship.relationship_quality >= 60) {
			printf("  Status: Good\n");
		}
		else if (Alice.relationship.relationship_quality >= 40) {
			printf("  Status: Average\n");
		}
		else {
			printf("  Status: Struggling\n");
		}
		if (Alice.relationship.boyfriend_pays) {
			printf(" Boyfriend usually pays for dates\n");
		}
		else {
			printf(" Splitting expenses or Alice pays\n");
		}
		if (Alice.relationship.last_gift_amount > 0) {
			printf(" Last gift from boyfriend: %s (%lld RUB)\n",
				Alice.relationship.last_gift_type, Alice.relationship.last_gift_amount);
		}
	}
	else {
		printf(" Single (ready to mingle)\n");
	}
}

// вывод итоговых результатов после симуляции
void print_results() {
	RUB total_invest = Alice.invest.stocks + Alice.invest.bonds + Alice.invest.liquid_funds;
	RUB total_capital = Alice.bank.account + Alice.bank.deposit + total_invest;

	printf("\n FINAL RESULTS \n");
	printf("Final salary: %lld RUB\n", Alice.salary);
	printf("Final deposit: %lld RUB\n", Alice.bank.deposit);
	printf("Final investments: %lld RUB\n", total_invest);
	printf("TOTAL CAPITAL: %lld RUB\n", total_capital);
	printf("\n Busines ALICE'ONE final status \n");
	if (Alice.business.is_active) {
		printf("Business survived and ended with: %lld RUB company cash\n",
			Alice.business.company_cash);
		printf("Final team: %d employees with %d/100 experience\n",
			Alice.business.employees, Alice.business.team_builder);
	}
	else {
		printf("Business did not start or went bankrupt\n");
	}
	printf("\n EATING DISORDER STATISTICS \n");
	printf("Alice tried to maintain healthy eating throughout her life.\n");
	printf("However, due to high stress from work, business, and finances,\n");
	printf("she experienced periodic relapses.\n");
	printf("Final stress level: %d/100\n", Alice.eating.stress_level);
	printf("If stress was high → more relapses → more money spent on:\n");
	printf("  - Sweets, cakes, chocolate\n");
	printf("  - Fast carbohydrates and sugars\n");
	printf("  - Consequent health issues\n");

	printf("Final age: %d years\n", Alice.health.age);
	printf("Simulation completed from Feb 2026 to Mar 2057\n");

	printf("\n WORK and INJURY STATISTICS \n");
	if (Alice.job.has_job) {
		printf("Alice ended as: %s\n", Alice.job.position);
		printf("Final job salary: %lld RUB\n", Alice.job.salary);
		printf("Final work experience: %d/100\n", Alice.job.experience);
	}
	else if (Alice.business.is_active) {
		printf("Alice continued running ALICE'ONE business\n");
	}
	else {
		printf("Alice was between jobs at the end of simulation\n");
	}

	if (Alice.injury.has_injury) {
		printf("\n Alice had an active injury at simulation end: %s\n", Alice.injury.injury_name);
	}

	printf("\n RELATIONSHIP STATISTICS \n");
	if (Alice.relationship.has_boyfriend) {
		printf("Alice ended the simulation in a relationship with him\n");
		printf("They were together for %d months\n", Alice.relationship.relationship_months);
		printf("Final relationship quality: %d/100\n", Alice.relationship.relationship_quality);
	}
	else {
		printf("Alice was single at the end of the simulation\n");
	}
	printf("Throughout her life, Alice:\n");
	printf("  - Increased spending on clothes, shoes, and jewelry to look cooler\n");
	printf("  - Made handmade gifts (scrapbooks, paintings, baked goods, candles)\n");
	printf("  - Went on dates to restaurants and received gifts\n");
	printf("  - Her stress level was affected by relationship ups and downs\n");

	printf("Final age: %d years\n", Alice.health.age);
	printf("Simulation completed from Feb 2026 to Mar 2057\n");
	printf("\n Halloween statistics \n");
	printf("Costume costs % lld RUB\n", Alice.halloween.costume);
	printf("Pumking costs % lld RUB\n", Alice.halloween.pumking);
	printf("Cosmetics cost % lld RUB\n", Alice.halloween.cosmetics);
	printf("Food for Halloween party cost % lld RUB\n", Alice.halloween.party_food);
	
	printf("Final age: %d years\n", Alice.health.age);
	printf("Simulation completed from Feb 2026 to Mar 2057\n");
	}

// цикл по месяцам
void simulation() {
	while (!(year == 2057 && month == 3)) {

		alice_salary();

		alice_humster();
		alice_travel();
		alice_health();
		alice_regular_payments();
		alice_car();
		alice_education();
		alice_charity();
		alice_leisure();
		alice_halloween_spending();
		alice_halloween_inflation();
		alice_business_operations();
		alice_eating_disorder();

		alice_random_injury();
		alice_business_fatigue();
		alice_search_new_job();
		alice_injury_recovery();
		alice_permanent_care_cost();
		alice_work_experience();

		alice_find_boyfriend();
		alice_relationship_spending();
		alice_handmade_gifts();
		alice_receive_gifts();
		alice_breakup();
		alice_update_relationship_quality();

		alice_monthly_invest();
		alice_investment_income();

		alice_bank_interest();

		if (month == 1) {
			print_status();
		}

		passing_of_time();
	}
}
