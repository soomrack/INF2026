#include <stdio.h>

using RUB = long long int;
using Percent = double;

struct Cat {
	RUB value;
	RUB food;
};

struct Car {
	RUB value;
	RUB gas;
	RUB insurance;
	RUB tax;
	RUB parking;
	RUB wash;
	RUB tires;
	RUB service;
	RUB repair;
};

struct Bank {
	RUB salary;
	RUB card;
	RUB deposit;
	Percent deposit_apr;
	RUB credit_debt;
	RUB credit_limit;
	RUB credit_penalty_fee;
	Percent credit_apr;
	Percent credit_min_payment_percent;
	RUB cashback_pending;
	Percent cashback_percent;
};

struct HomeBills {
	RUB home_insurance;
	RUB property_tax;
	RUB electricity;
	RUB heating;
	RUB water;
	RUB gas;
	RUB repairs_fund;
	RUB intercom;
	RUB trash;
	RUB internet;
	RUB tv;
	RUB mobile;
	RUB cleaning;
};

struct Home {
	RUB value;
	RUB furniture;
	RUB mortgage_debt;
	RUB mortgage_payment;
	Percent mortgage_rate;
	HomeBills bills;
};

struct Item {
	RUB value;
	Percent wear;
	Percent monthly_wear;
	RUB repair_cost;
	RUB replace_cost;
	RUB service_cost;
};

struct Inventory {
	Item phone;
	Item laptop;
	Item headphones;
	Item smartwatch;
	Item pc;
	Item monitor;
	Item keyboard;
	Item mouse;
	Item chair;
	Item console;
	Item tv;
	Item fridge;
	Item microwave;
	Item washing_machine;
	Item vacuum;
	Item coffee_machine;
	Item blender;
	Item bed;
	Item sofa;
	Item table;
	Item bike;
	Item skates;
	Item gym_membership;
	Item camera;
	Item toolbox;
	Item winter_clothes;
	Item summer_clothes;
	Item shoes_pack;
};

struct Person {
	RUB food;
	RUB clothes;
	RUB entertainment;
	RUB medicine;
	RUB education;
	RUB subscriptions;
	RUB transport;
	RUB gifts;
	RUB cafe;
	RUB hygiene;
	RUB cosmetics;
	RUB pets;
	RUB games;
	Car car;
	Cat cat;
	Inventory items;
	Bank Tbank;
	Bank Sberbank;
	Bank Alfabank;
	Bank VTB;
};

struct TattooSalon {
	RUB cash;
	RUB price_small;
	RUB price_medium;
	RUB price_large;
	RUB clients_small;
	RUB clients_medium;
	RUB clients_large;
	RUB tips;
	RUB rent;
	RUB utilities;
	RUB internet;
	RUB ink;
	RUB needles;
	RUB gloves;
	RUB antiseptic;
	RUB film;
	RUB paper;
	RUB cleaning;
	RUB marketing;
	RUB smm;
	RUB ads;
	RUB equipment_value;
	RUB equipment_wear;
	RUB equipment_monthly_wear;
	RUB equipment_repair_cost;
	RUB master_salary;
	RUB admin_salary;
	RUB staff_taxes;
	double tax_percent;
	RUB reputation;
	RUB reputation_growth;
	RUB reputation_drop;
	RUB month_income;
	RUB month_expenses;
	RUB month_profit;
};

struct FamilyGoals {
	RUB travel_fund;
	RUB repair_fund;
	RUB education_fund;
	RUB emergency_fund_target;
	RUB monthly_to_travel;
	RUB monthly_to_repair;
	RUB monthly_to_education;
	RUB last_event_cost;
};

class LifeSimulation {
private:
	FamilyGoals goals;
	Person Alice;
	Person David;
	Home shared_home;
	TattooSalon salon;
	void bank_init(Bank& bank) {
		bank.salary = 0;
		bank.card = 0;
		bank.deposit = 0;
		bank.deposit_apr = 0;
		bank.credit_debt = 0;
		bank.credit_apr = 0;
		bank.credit_limit = 0;
		bank.credit_min_payment_percent = 0;
		bank.credit_penalty_fee = 0;
		bank.cashback_pending = 0;
		bank.cashback_percent = 0;
	}

	void item_init(Item& it, const RUB value, const Percent wear, const Percent monthly_wear, const RUB repair_cost, const RUB replace_cost, const RUB service_cost) {
		it.value = value;
		it.wear = wear;
		it.monthly_wear = monthly_wear;
		it.repair_cost = repair_cost;
		it.replace_cost = replace_cost;
		it.service_cost = service_cost;
	}

	void home_bills_init() {
		shared_home.bills.electricity = 3'500;
		shared_home.bills.water = 2'500;
		shared_home.bills.gas = 1000;
		shared_home.bills.heating = 2'000;
		shared_home.bills.trash = 500;
		shared_home.bills.intercom = 250;
		shared_home.bills.internet = 1'000;
		shared_home.bills.tv = 500;
		shared_home.bills.mobile = 1'000;
		shared_home.bills.home_insurance = 2'500;
		shared_home.bills.property_tax = 1'500;
		shared_home.bills.repairs_fund = 3'000;
		shared_home.bills.cleaning = 1000;
	}

	void home_init() {
		shared_home.value = 12'000'000;
		shared_home.furniture = 750'000;
		shared_home.mortgage_debt = 10'000'000;
		shared_home.mortgage_rate = 12.0;
		shared_home.mortgage_payment = 110'000;
		home_bills_init();
	}

	void init_Alice_inventory() {
		item_init(Alice.items.phone, 90'000, 5, 3, 3'000, 90'000, 0);
		item_init(Alice.items.laptop, 160'000, 10, 2, 8'000, 160'000, 0);
		item_init(Alice.items.headphones, 15'000, 15, 4, 1'500, 15'000, 0);
		item_init(Alice.items.smartwatch, 25'000, 12, 3, 2'500, 25'000, 0);
		item_init(Alice.items.pc, 250'000, 10, 2, 7'000, 250'000, 0);
		item_init(Alice.items.monitor, 35'000, 8, 1, 2'000, 35'000, 0);
		item_init(Alice.items.keyboard, 8'000, 20, 4, 800, 8'000, 0);
		item_init(Alice.items.mouse, 5'000, 25, 5, 500, 5'000, 0);
		item_init(Alice.items.chair, 25'000, 15, 2, 1'500, 25'000, 0);
		item_init(Alice.items.console, 0, 0, 0, 0, 0, 0);
		item_init(Alice.items.tv, 60'000, 8, 1, 3'500, 60'000, 0);
		item_init(Alice.items.fridge, 55'000, 5, 1, 3'500, 55'000, 0);
		item_init(Alice.items.microwave, 10'000, 10, 2, 1'000, 10'000, 0);
		item_init(Alice.items.washing_machine, 45'000, 8, 1, 3'000, 45'000, 0);
		item_init(Alice.items.vacuum, 18'000, 10, 2, 1'500, 18'000, 0);
		item_init(Alice.items.coffee_machine, 5'000, 12, 2, 2'000, 5'000, 0);
		item_init(Alice.items.blender, 3'000, 15, 3, 700, 3'000, 0);
		item_init(Alice.items.bed, 25'000, 5, 1, 2'500, 25'000, 0);
		item_init(Alice.items.sofa, 40'000, 5, 1, 4'000, 40'000, 0);
		item_init(Alice.items.table, 20'000, 5, 1, 1'200, 20'000, 0);
		item_init(Alice.items.skates, 12'000, 10, 4, 900, 12'000, 0);
		item_init(Alice.items.gym_membership, 0, 0, 0, 0, 0, 2'500);
		item_init(Alice.items.bike, 0, 0, 0, 0, 0, 0);
		item_init(Alice.items.camera, 0, 0, 0, 0, 0, 0);
		item_init(Alice.items.toolbox, 8'000, 5, 1, 400, 8'000, 0);
		item_init(Alice.items.winter_clothes, 0, 0, 0, 0, 0, 0);
		item_init(Alice.items.summer_clothes, 0, 0, 0, 0, 0, 0);
		item_init(Alice.items.shoes_pack, 0, 0, 0, 0, 0, 0);
	}

	void init_David_inventory() {
		item_init(David.items.phone, 55'000, 10, 4, 2'000, 55'000, 0);
		item_init(David.items.laptop, 120'000, 15, 3, 6'000, 120'000, 0);
		item_init(David.items.headphones, 12'000, 20, 5, 1'000, 12'000, 0);
		item_init(David.items.smartwatch, 0, 0, 0, 0, 0, 0);
		item_init(David.items.pc, 0, 0, 0, 0, 0, 0);
		item_init(David.items.monitor, 0, 0, 0, 0, 0, 0);
		item_init(David.items.keyboard, 0, 0, 0, 0, 0, 0);
		item_init(David.items.mouse, 0, 0, 0, 0, 0, 0);
		item_init(David.items.chair, 0, 0, 0, 0, 0, 0);
		item_init(David.items.console, 35'000, 10, 2, 2'000, 35'000, 0);
		item_init(David.items.tv, 0, 0, 0, 0, 0, 0);
		item_init(David.items.fridge, 0, 0, 0, 0, 0, 0);
		item_init(David.items.microwave, 0, 0, 0, 0, 0, 0);
		item_init(David.items.washing_machine, 0, 0, 0, 0, 0, 0);
		item_init(David.items.vacuum, 0, 0, 0, 0, 0, 0);
		item_init(David.items.coffee_machine, 0, 0, 0, 0, 0, 0);
		item_init(David.items.blender, 0, 0, 0, 0, 0, 0);
		item_init(David.items.bed, 0, 0, 0, 0, 0, 0);
		item_init(David.items.sofa, 0, 0, 0, 0, 0, 0);
		item_init(David.items.table, 0, 0, 0, 0, 0, 0);
		item_init(David.items.skates, 0, 0, 0, 0, 0, 0);
		item_init(David.items.gym_membership, 0, 0, 0, 0, 0, 1'800);
		item_init(David.items.bike, 35'000, 5, 2, 5'000, 35'000, 0);
		item_init(David.items.camera, 0, 0, 0, 0, 0, 0);
		item_init(David.items.toolbox, 0, 0, 0, 0, 0, 0);
		item_init(David.items.winter_clothes, 0, 0, 0, 0, 0, 0);
		item_init(David.items.summer_clothes, 0, 0, 0, 0, 0, 0);
		item_init(David.items.shoes_pack, 0, 0, 0, 0, 0, 0);
	}

	void init_Alice_profile() {
		Alice.food = 30'000;
		Alice.clothes = 6'000;
		Alice.entertainment = 5'000;
		Alice.medicine = 1'500;
		Alice.education = 2'500;
		Alice.subscriptions = 800;
		Alice.transport = 2'000;
		Alice.gifts = 2'000;
		Alice.cafe = 3'000;
		Alice.hygiene = 1'200;
		Alice.cosmetics = 1'500;
		Alice.pets = 0;
		Alice.games = 1'500;
		Alice.car.value = 2'400'000;
		Alice.car.gas = 15'000;
		Alice.car.insurance = 6'000;
		Alice.car.tax = 2'000;
		Alice.car.repair = 4'000;
		Alice.car.parking = 4'000;
		Alice.car.wash = 1'200;
		Alice.car.tires = 1'500;
		Alice.car.service = 2'500;
		Alice.cat.value = 25'000;
		Alice.cat.food = 5'000;
		init_Alice_inventory();
		bank_init(Alice.Tbank);
		bank_init(Alice.Sberbank);
		bank_init(Alice.Alfabank);
		bank_init(Alice.VTB);
		Alice.Tbank.salary = 400'000;
		Alice.Tbank.deposit_apr = 14.5;
		Alice.Sberbank.deposit_apr = 12.0;
		Alice.Alfabank.deposit_apr = 13.0;
		Alice.VTB.deposit_apr = 11.5;
		Alice.Tbank.credit_apr = 24.0;
		Alice.Sberbank.credit_apr = 23.0;
		Alice.Alfabank.credit_apr = 25.0;
		Alice.VTB.credit_apr = 22.0;
		Alice.Tbank.credit_limit = 200'000;
		Alice.Sberbank.credit_limit = 150'000;
		Alice.Alfabank.credit_limit = 250'000;
		Alice.VTB.credit_limit = 120'000;
		Alice.Tbank.credit_min_payment_percent = 8.0;
		Alice.Sberbank.credit_min_payment_percent = 7.0;
		Alice.Alfabank.credit_min_payment_percent = 9.0;
		Alice.VTB.credit_min_payment_percent = 6.0;
		Alice.Tbank.credit_penalty_fee = 1'000;
		Alice.Sberbank.credit_penalty_fee = 800;
		Alice.Alfabank.credit_penalty_fee = 1'200;
		Alice.VTB.credit_penalty_fee = 700;
		Alice.Tbank.cashback_percent = 1.0;
		Alice.Sberbank.cashback_percent = 0.5;
		Alice.Alfabank.cashback_percent = 1.5;
		Alice.VTB.cashback_percent = 0.8;
	}

	void init_David_profile() {
		David.food = 15'000;
		David.clothes = 4'000;
		David.entertainment = 4'000;
		David.medicine = 1'000;
		David.education = 3'000;
		David.subscriptions = 600;
		David.transport = 2'500;
		David.gifts = 1'000;
		David.cafe = 2'500;
		David.hygiene = 900;
		David.cosmetics = 600;
		David.pets = 0;
		David.games = 2'000;
		David.car.value = 1'200'000;
		David.car.gas = 12'000;
		David.car.insurance = 4'500;
		David.car.tax = 1'500;
		David.car.repair = 3'000;
		David.car.parking = 2'000;
		David.car.wash = 900;
		David.car.tires = 1'200;
		David.car.service = 1'800;
		David.cat.value = 0;
		David.cat.food = 0;
		init_David_inventory();
		bank_init(David.Tbank);
		bank_init(David.Sberbank);
		bank_init(David.Alfabank);
		bank_init(David.VTB);
		David.Tbank.salary = 80'000;
		David.Tbank.deposit_apr = 14.0;
		David.Sberbank.deposit_apr = 11.5;
		David.Alfabank.deposit_apr = 12.5;
		David.VTB.deposit_apr = 11.0;
		David.Tbank.credit_apr = 26.0;
		David.Sberbank.credit_apr = 24.0;
		David.Alfabank.credit_apr = 27.0;
		David.VTB.credit_apr = 23.0;
		David.Tbank.credit_limit = 80'000;
		David.Sberbank.credit_limit = 60'000;
		David.Alfabank.credit_limit = 90'000;
		David.VTB.credit_limit = 50'000;
		David.Tbank.credit_min_payment_percent = 10.0;
		David.Sberbank.credit_min_payment_percent = 9.0;
		David.Alfabank.credit_min_payment_percent = 11.0;
		David.VTB.credit_min_payment_percent = 8.0;
		David.Tbank.credit_penalty_fee = 900;
		David.Sberbank.credit_penalty_fee = 700;
		David.Alfabank.credit_penalty_fee = 1'000;
		David.VTB.credit_penalty_fee = 600;
		David.Tbank.cashback_percent = 1.0;
		David.Sberbank.cashback_percent = 0.5;
		David.Alfabank.cashback_percent = 1.2;
		David.VTB.cashback_percent = 0.8;
	}

	RUB pay_from_bank_card(Bank& bank, const RUB amount) {
		if (amount <= 0) {
			return 0;
		}
		if (bank.card >= amount) {
			bank.card -= amount;
			return 0;
		}
		else {
			RUB rest = amount - bank.card;
			bank.card = 0;
			return rest;
		}
	}

	RUB person_total_card_money(const Person& person) {
		return person.Tbank.card + person.Sberbank.card + person.Alfabank.card + person.VTB.card;
	}

	void bank_transfer_cards(Bank& from, Bank& to, const RUB amount) {
		if (amount <= 0) {
			return;
		}
		if (from.card >= amount) {
			from.card -= amount;
			to.card += amount;
		}
		else {
			RUB moved = from.card;
			from.card = 0;
			to.card += moved;
		}
	}

	void person_transfer_to_people(Person& from, Person& to, const RUB amount) {
		if (amount <= 0) {
			return;
		}
		bank_transfer_cards(from.Tbank, to.Tbank, amount);
	}

	void pay_from_all_cards(Person& person, const RUB amount, const char* what, const char* who) {
		RUB rest = amount;
		rest = pay_from_bank_card(person.Tbank, rest);
		rest = pay_from_bank_card(person.Sberbank, rest);
		rest = pay_from_bank_card(person.Alfabank, rest);
		rest = pay_from_bank_card(person.VTB, rest);
		if (rest > 0) {
			printf("%s cannot pay for %s! Need: %lld, Unpaid: %lld\n", who, what, amount, rest);
		}
	}

	void add_cashback_for_spending(Bank& bank, const RUB amount) {
		if (amount <= 0) {
			return;
		}
		double part = (bank.cashback_percent / 100.0);
		RUB cashback = (RUB)(amount * part);
		if (cashback < 0) {
			cashback = 0;
		}
		bank.cashback_pending += cashback;
	}

	void person_cashback_tick(Person& person) {
		person.Tbank.card += person.Tbank.cashback_pending;
		person.Sberbank.card += person.Sberbank.cashback_pending;
		person.Alfabank.card += person.Alfabank.cashback_pending;
		person.VTB.card += person.VTB.cashback_pending;
		person.Tbank.cashback_pending = 0;
		person.Sberbank.cashback_pending = 0;
		person.Alfabank.cashback_pending = 0;
		person.VTB.cashback_pending = 0;
	}

	RUB bank_credit_available(const Bank& bank) {
		RUB avail = bank.credit_limit - bank.credit_debt;
		if (avail < 0) {
			avail = 0;
		}
		return avail;
	}

	RUB pay_from_credit(Bank& bank, const RUB amount) {
		if (amount <= 0) {
			return 0;
		}
		RUB avail = bank_credit_available(bank);
		if (avail <= 0) {
			return amount;
		}
		if (avail >= amount) {
			bank.credit_debt += amount;
			return 0;
		}
		else {
			bank.credit_debt += avail;
			return amount - avail;
		}
	}

	void pay_with_cards_and_credit(Person& person, Bank& prefer_card_bank, Bank& prefer_credit_bank, const RUB amount, const char* what, const char* who) {
		if (amount <= 0) {
			return;
		}
		RUB rest = amount;
		RUB before = prefer_card_bank.card;
		rest = pay_from_bank_card(prefer_card_bank, rest);
		RUB spent = before - prefer_card_bank.card;
		add_cashback_for_spending(prefer_card_bank, spent);
		if (&prefer_card_bank != &person.Tbank) {
			RUB b = person.Tbank.card;
			rest = pay_from_bank_card(person.Tbank, rest);
			add_cashback_for_spending(person.Tbank, b - person.Tbank.card);
		}
		if (&prefer_card_bank != &person.Sberbank) {
			RUB b = person.Sberbank.card;
			rest = pay_from_bank_card(person.Sberbank, rest);
			add_cashback_for_spending(person.Sberbank, b - person.Sberbank.card);
		}
		if (&prefer_card_bank != &person.Alfabank) {
			RUB b = person.Alfabank.card;
			rest = pay_from_bank_card(person.Alfabank, rest);
			add_cashback_for_spending(person.Alfabank, b - person.Alfabank.card);
		}
		if (&prefer_card_bank != &person.VTB) {
			RUB b = person.VTB.card;
			rest = pay_from_bank_card(person.VTB, rest);
			add_cashback_for_spending(person.VTB, b - person.VTB.card);
		}
		rest = pay_from_credit(prefer_credit_bank, rest);
		if (rest > 0) {
			printf("%s cannot pay for %s even with credit! Need: %lld, Unpaid: %lld\n", who, what, amount, rest);
		}
	}

	void deposit_interest_bank(Bank& bank) {
		double deposit_month = (bank.deposit_apr / 100.0 / 12.0);
		bank.deposit += bank.deposit * deposit_month;
	}

	void credit_interest_bank(Bank& bank) {
		if (bank.credit_debt <= 0) {
			return;
		}
		double credit_month = (bank.credit_apr / 100.0 / 12.0);
		bank.credit_debt += bank.credit_debt * credit_month;
	}

	RUB credit_min_payment(const Bank& bank) {
		if (bank.credit_debt <= 0) {
			return 0;
		}
		double part = (bank.credit_min_payment_percent / 100.0);
		RUB min_payment = (RUB)(bank.credit_debt * part);
		if (min_payment < 500) {
			min_payment = 500;
		}
		if (min_payment > bank.credit_debt) {
			min_payment = bank.credit_debt;
		}
		return min_payment;
	}

	void credit_pay_minimum(Bank& bank) {
		RUB mp = credit_min_payment(bank);
		if (mp <= 0) {
			return;
		}
		if (bank.card >= mp) {
			bank.card -= mp;
			bank.credit_debt -= mp;
		}
		else {
			RUB paid = bank.card;
			bank.card = 0;
			bank.credit_debt -= paid;
			if (bank.credit_debt < 0) {
				bank.credit_debt = 0;
			}
			bank.credit_debt += bank.credit_penalty_fee;
		}
	}

	void person_credit_month_tick(Person& person) {
		credit_interest_bank(person.Tbank);
		credit_interest_bank(person.Sberbank);
		credit_interest_bank(person.Alfabank);
		credit_interest_bank(person.VTB);
		credit_pay_minimum(person.Tbank);
		credit_pay_minimum(person.Sberbank);
		credit_pay_minimum(person.Alfabank);
		credit_pay_minimum(person.VTB);
	}

	void person_deposit_month_tick(Person& person) {
		deposit_interest_bank(person.Tbank);
		deposit_interest_bank(person.Sberbank);
		deposit_interest_bank(person.Alfabank);
		deposit_interest_bank(person.VTB);
	}

	void item_wear_tick(Item& it) {
		if (it.value <= 0) {
			return;
		}
		it.wear += it.monthly_wear;
		if (it.wear > 100) {
			it.wear = 100;
		}
	}

	void person_items_wear_tick(Person& person) {
		item_wear_tick(person.items.phone);
		item_wear_tick(person.items.laptop);
		item_wear_tick(person.items.headphones);
		item_wear_tick(person.items.smartwatch);
		item_wear_tick(person.items.pc);
		item_wear_tick(person.items.monitor);
		item_wear_tick(person.items.keyboard);
		item_wear_tick(person.items.mouse);
		item_wear_tick(person.items.chair);
		item_wear_tick(person.items.console);
		item_wear_tick(person.items.tv);
		item_wear_tick(person.items.fridge);
		item_wear_tick(person.items.microwave);
		item_wear_tick(person.items.washing_machine);
		item_wear_tick(person.items.vacuum);
		item_wear_tick(person.items.coffee_machine);
		item_wear_tick(person.items.blender);
		item_wear_tick(person.items.bed);
		item_wear_tick(person.items.sofa);
		item_wear_tick(person.items.table);
		item_wear_tick(person.items.skates);
		item_wear_tick(person.items.bike);
		item_wear_tick(person.items.camera);
		item_wear_tick(person.items.toolbox);
	}

	void try_repair_or_replace_item(Person& person, Item& it, const char* item_name, const char* who) {
		if (it.value <= 0) {
			return;
		}
		if (it.wear < 80) {
			return;
		}
		RUB repair = it.repair_cost;
		pay_from_all_cards(person, repair, item_name, who);
		if (it.wear >= 30) {
			it.wear -= 30;
		}
		else {
			it.wear = 0;
		}
		if (it.wear >= 90) {
			RUB repl = it.replace_cost;
			pay_from_all_cards(person, repl, item_name, who);
			it.value = repl;
			it.wear = 0;
		}
	}

	void person_items_service_pay(Person& person, const char* who) {
		pay_from_all_cards(person, person.items.phone.service_cost, "phone service", who);
		pay_from_all_cards(person, person.items.laptop.service_cost, "laptop service", who);
		pay_from_all_cards(person, person.items.headphones.service_cost, "headphones service", who);
		pay_from_all_cards(person, person.items.smartwatch.service_cost, "smartwatch service", who);
		pay_from_all_cards(person, person.items.gym_membership.service_cost, "gym membership", who);
	}

	void person_items_repair_or_replace(Person& person, const char* who) {
		try_repair_or_replace_item(person, person.items.phone, "phone", who);
		try_repair_or_replace_item(person, person.items.laptop, "laptop", who);
		try_repair_or_replace_item(person, person.items.headphones, "headphones", who);
		try_repair_or_replace_item(person, person.items.smartwatch, "smartwatch", who);
		try_repair_or_replace_item(person, person.items.tv, "tv", who);
		try_repair_or_replace_item(person, person.items.vacuum, "vacuum", who);
		try_repair_or_replace_item(person, person.items.washing_machine, "washing machine", who);
	}

	void Alice_salary(const int month, const int year) {
		if ((month == 8) && (year == 2026))
		{
			Alice.Tbank.salary = (RUB)(Alice.Tbank.salary * 1.5);
		}
		Alice.Tbank.card += Alice.Tbank.salary;
	}

	void David_salary(const int month, const int year) {
		if ((month == 1) && (year == 2027))
		{
			David.Tbank.salary = 0;
		}
		if ((month == 8) && (year == 2026))
		{
			David.Tbank.salary = (RUB)(David.Tbank.salary * 1.5);
		}
		David.Tbank.card += David.Tbank.salary;
	}

	void inflation_tick_person(Person& person) {
		double inflation_month = (10.0 / 100.0 / 12.0);
		person.food *= (1.0 + inflation_month);
		person.clothes *= (1.0 + inflation_month);
		person.entertainment *= (1.0 + inflation_month);
		person.medicine *= (1.0 + inflation_month);
		person.education *= (1.0 + inflation_month);
		person.subscriptions *= (1.0 + inflation_month);
		person.transport *= (1.0 + inflation_month);
		person.gifts *= (1.0 + inflation_month);
		person.cafe *= (1.0 + inflation_month);
		person.hygiene *= (1.0 + inflation_month);
		person.cosmetics *= (1.0 + inflation_month);
		person.pets *= (1.0 + inflation_month);
		person.games *= (1.0 + inflation_month);
		person.car.gas *= (1.0 + inflation_month);
		person.car.insurance *= (1.0 + inflation_month);
		person.car.tax *= (1.0 + inflation_month);
		person.car.repair *= (1.0 + inflation_month);
		person.car.parking *= (1.0 + inflation_month);
		person.car.wash *= (1.0 + inflation_month);
		person.car.tires *= (1.0 + inflation_month);
		person.car.service *= (1.0 + inflation_month);
		person.car.value *= (1.0 + inflation_month);
		person.cat.food *= (1.0 + inflation_month);
		person.cat.value *= (1.0 + inflation_month);
		person.items.phone.repair_cost *= (1.0 + inflation_month);
		person.items.laptop.repair_cost *= (1.0 + inflation_month);
		person.items.headphones.repair_cost *= (1.0 + inflation_month);
		person.items.smartwatch.repair_cost *= (1.0 + inflation_month);
		person.items.phone.replace_cost *= (1.0 + inflation_month);
		person.items.laptop.replace_cost *= (1.0 + inflation_month);
		person.items.headphones.replace_cost *= (1.0 + inflation_month);
		person.items.smartwatch.replace_cost *= (1.0 + inflation_month);
		person.items.gym_membership.service_cost *= (1.0 + inflation_month);
	}

	void inflation_tick_home() {
		double inflation_month = (10.0 / 100.0 / 12.0);
		shared_home.value *= (1.0 + inflation_month);
		shared_home.furniture *= (1.0 + inflation_month);
		shared_home.bills.electricity *= (1.0 + inflation_month);
		shared_home.bills.water *= (1.0 + inflation_month);
		shared_home.bills.gas *= (1.0 + inflation_month);
		shared_home.bills.heating *= (1.0 + inflation_month);
		shared_home.bills.trash *= (1.0 + inflation_month);
		shared_home.bills.intercom *= (1.0 + inflation_month);
		shared_home.bills.internet *= (1.0 + inflation_month);
		shared_home.bills.tv *= (1.0 + inflation_month);
		shared_home.bills.mobile *= (1.0 + inflation_month);
		shared_home.bills.home_insurance *= (1.0 + inflation_month);
		shared_home.bills.property_tax *= (1.0 + inflation_month);
		shared_home.bills.repairs_fund *= (1.0 + inflation_month);
		shared_home.bills.cleaning *= (1.0 + inflation_month);
	}

	void mortgage_interest_tick() {
		double mortgage_month = (shared_home.mortgage_rate / 100.0 / 12.0);
		shared_home.mortgage_debt += shared_home.mortgage_debt * mortgage_month;
	}

	RUB person_salary_now(const Person& person) {
		return person.Tbank.salary;
	}

	void couple_split_by_salary(const RUB total, RUB& main_part, RUB& second_part) {
		RUB sA = person_salary_now(Alice);
		RUB sD = person_salary_now(David);
		if (sA < 0) { sA = 0; }
		if (sD < 0) { sD = 0; }
		RUB sum = sA + sD;
		if (sum <= 0) {
			main_part = total / 2;
			second_part = total - main_part;
			return;
		}
		double shareA = (double)sA / (double)sum;
		main_part = (RUB)(total * shareA);
		second_part = total - main_part;
	}

	void couple_help_if_needed(Person& who_needs_help, Person& helper, RUB need_amount, const char* need_name) {
		if (need_amount <= 0) {
			return;
		}
		RUB helper_money = person_total_card_money(helper);
		if (helper_money <= 0) {
			printf("No helper money for %s!\n", need_name);
			return;
		}
		RUB move = need_amount;
		if (move > helper_money) {
			move = helper_money;
		}
		person_transfer_to_people(helper, who_needs_help, move);
	}

	void couple_pay_shared_bill_by_salary_with_help(const RUB total, const char* what) {
		RUB a = 0;
		RUB d = 0;
		couple_split_by_salary(total, a, d);
		RUB Alice_before = person_total_card_money(Alice);
		pay_from_all_cards(Alice, a, what, "Alice");
		RUB Alice_after = person_total_card_money(Alice);
		RUB Alice_paid = Alice_before - Alice_after;
		RUB Alice_unpaid = a - Alice_paid;
		if (Alice_unpaid < 0) { Alice_unpaid = 0; }
		RUB David_before = person_total_card_money(David);
		pay_from_all_cards(David, d, what, "David");
		RUB David_after = person_total_card_money(David);
		RUB David_paid = David_before - David_after;
		RUB David_unpaid = d - David_paid;
		if (David_unpaid < 0) { David_unpaid = 0; }
		if (Alice_unpaid > 0) {
			couple_help_if_needed(Alice, David, Alice_unpaid, what);
			pay_from_all_cards(Alice, Alice_unpaid, what, "Alice");
		}
		if (David_unpaid > 0) {
			couple_help_if_needed(David, Alice, David_unpaid, what);
			pay_from_all_cards(David, David_unpaid, what, "David");
		}
	}

	void couple_pay_electricity() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.electricity, "electricity (shared home)");
	}

	void couple_pay_water() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.water, "water (shared home)");
	}

	void couple_pay_gas_home() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.gas, "home gas (shared home)");
	}

	void couple_pay_heating() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.heating, "heating (shared home)");
	}

	void couple_pay_trash() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.trash, "trash (shared home)");
	}

	void couple_pay_intercom() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.intercom, "intercom (shared home)");
	}

	void couple_pay_internet() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.internet, "internet (shared home)");
	}

	void couple_pay_tv() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.tv, "tv (shared home)");
	}

	void couple_pay_mobile() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.mobile, "mobile (shared home)");
	}

	void couple_pay_home_insurance() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.home_insurance, "home insurance (shared home)");
	}

	void couple_pay_property_tax() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.property_tax, "property tax (shared home)");
	}

	void couple_pay_repairs_fund() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.repairs_fund, "repairs fund (shared home)");
	}

	void couple_pay_cleaning() {
		couple_pay_shared_bill_by_salary_with_help(shared_home.bills.cleaning, "cleaning (shared home)");
	}

	void couple_pay_mortgage() {
		if (shared_home.mortgage_debt <= 0) {
			return;
		}
		couple_pay_shared_bill_by_salary_with_help(shared_home.mortgage_payment, "mortgage (shared home)");
		if (shared_home.mortgage_debt >= shared_home.mortgage_payment) {
			shared_home.mortgage_debt -= shared_home.mortgage_payment;
		}
		else {
			shared_home.mortgage_debt = 0;
		}
	}

	void Alice_pay_food() {
		pay_with_cards_and_credit(Alice, Alice.Alfabank, Alice.Alfabank, Alice.food, "food", "Alice");
	}

	void David_pay_food() {
		pay_with_cards_and_credit(David, David.Alfabank, David.Alfabank, David.food, "food", "David");
	}

	void Alice_pay_gas() {
		pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.car.gas, "gas", "Alice");
	}

	void David_pay_gas() {
		pay_with_cards_and_credit(David, David.Tbank, David.Tbank, David.car.gas, "gas", "David");
	}

	void Alice_pay_cat_food() {
		pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.cat.food, "cat food", "Alice");
	}

	void Alice_pay_clothes() {
		pay_with_cards_and_credit(Alice, Alice.Sberbank, Alice.Sberbank, Alice.clothes, "clothes", "Alice");
	}

	void David_pay_clothes() {
		pay_with_cards_and_credit(David, David.Sberbank, David.Sberbank, David.clothes, "clothes", "David");
	}

	void Alice_pay_entertainment() {
		pay_with_cards_and_credit(Alice, Alice.Alfabank, Alice.Alfabank, Alice.entertainment, "entertainment", "Alice");
	}

	void David_pay_entertainment() {
		pay_with_cards_and_credit(David, David.Alfabank, David.Alfabank, David.entertainment, "entertainment", "David");
	}

	void Alice_pay_medicine() {
		pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.medicine, "medicine", "Alice");
	}

	void David_pay_medicine() {
		pay_with_cards_and_credit(David, David.Tbank, David.Tbank, David.medicine, "medicine", "David");
	}

	void Alice_pay_education() {
		pay_with_cards_and_credit(Alice, Alice.VTB, Alice.VTB, Alice.education, "education", "Alice");
	}

	void David_pay_education() {
		pay_with_cards_and_credit(David, David.VTB, David.VTB, David.education, "education", "David");
	}

	void Alice_pay_subscriptions() {
		pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.subscriptions, "subscriptions", "Alice");
	}

	void David_pay_subscriptions() {
		pay_with_cards_and_credit(David, David.Tbank, David.Tbank, David.subscriptions, "subscriptions", "David");
	}

	void Alice_pay_transport() {
		pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.transport, "transport", "Alice");
	}

	void David_pay_transport() {
		pay_with_cards_and_credit(David, David.Tbank, David.Tbank, David.transport, "transport", "David");
	}

	void Alice_pay_gifts() {
		pay_with_cards_and_credit(Alice, Alice.Sberbank, Alice.Sberbank, Alice.gifts, "gifts", "Alice");
	}

	void David_pay_gifts() {
		pay_with_cards_and_credit(David, David.Sberbank, David.Sberbank, David.gifts, "gifts", "David");
	}

	void Alice_pay_cafe() {
		pay_with_cards_and_credit(Alice, Alice.Alfabank, Alice.Alfabank, Alice.cafe, "cafe", "Alice");
	}

	void David_pay_cafe() {
		pay_with_cards_and_credit(David, David.Alfabank, David.Alfabank, David.cafe, "cafe", "David");
	}

	void Alice_pay_hygiene() {
		pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.hygiene, "hygiene", "Alice");
	}

	void David_pay_hygiene() {
		pay_with_cards_and_credit(David, David.Tbank, David.Tbank, David.hygiene, "hygiene", "David");
	}

	void Alice_pay_cosmetics() {
		pay_with_cards_and_credit(Alice, Alice.Sberbank, Alice.Sberbank, Alice.cosmetics, "cosmetics", "Alice");
	}

	void David_pay_cosmetics() {
		pay_with_cards_and_credit(David, David.Sberbank, David.Sberbank, David.cosmetics, "cosmetics", "David");
	}

	void Alice_pay_games() {
		pay_with_cards_and_credit(Alice, Alice.Alfabank, Alice.Alfabank, Alice.games, "games", "Alice");
	}

	void David_pay_games() {
		pay_with_cards_and_credit(David, David.Alfabank, David.Alfabank, David.games, "games", "David");
	}

	void Alice_pay_car_insurance() {
		pay_from_all_cards(Alice, Alice.car.insurance, "car insurance", "Alice");
	}

	void David_pay_car_insurance() {
		pay_from_all_cards(David, David.car.insurance, "car insurance", "David");
	}

	void Alice_pay_car_tax() {
		pay_from_all_cards(Alice, Alice.car.tax, "car tax", "Alice");
	}

	void David_pay_car_tax() {
		pay_from_all_cards(David, David.car.tax, "car tax", "David");
	}

	void Alice_pay_car_repair() {
		pay_from_all_cards(Alice, Alice.car.repair, "car repair", "Alice");
	}

	void David_pay_car_repair() {
		pay_from_all_cards(David, David.car.repair, "car repair", "David");
	}

	void Alice_pay_parking() {
		pay_from_all_cards(Alice, Alice.car.parking, "parking", "Alice");
	}

	void David_pay_parking() {
		pay_from_all_cards(David, David.car.parking, "parking", "David");
	}

	void Alice_pay_car_wash() {
		pay_from_all_cards(Alice, Alice.car.wash, "car wash", "Alice");
	}

	void David_pay_car_wash() {
		pay_from_all_cards(David, David.car.wash, "car wash", "David");
	}

	void Alice_pay_tires() {
		pay_from_all_cards(Alice, Alice.car.tires, "tires", "Alice");
	}

	void David_pay_tires() {
		pay_from_all_cards(David, David.car.tires, "tires", "David");
	}

	void Alice_pay_car_service() {
		pay_from_all_cards(Alice, Alice.car.service, "car service", "Alice");
	}

	void David_pay_car_service() {
		pay_from_all_cards(David, David.car.service, "car service", "David");
	}

	void salon_init() {
		salon.cash = 1'000'000;
		salon.price_small = 6'000;
		salon.price_medium = 12'000;
		salon.price_large = 20'000;
		salon.clients_small = 47;
		salon.clients_medium = 25;
		salon.clients_large = 13;
		salon.tips = 15'000;
		salon.rent = 120'000;
		salon.utilities = 9'000;
		salon.internet = 1'200;
		salon.ink = 10'000;
		salon.needles = 7'000;
		salon.gloves = 3'000;
		salon.antiseptic = 2'500;
		salon.film = 1'500;
		salon.paper = 800;
		salon.cleaning = 2'000;
		salon.marketing = 15'000;
		salon.smm = 10'000;
		salon.ads = 12'000;
		salon.equipment_value = 600'000;
		salon.equipment_wear = 10;
		salon.equipment_monthly_wear = 3;
		salon.equipment_repair_cost = 18'000;
		salon.master_salary = 90'000;
		salon.admin_salary = 55'000;
		salon.staff_taxes = 25'000;
		salon.tax_percent = 6.0;
		salon.reputation = 50;
		salon.reputation_growth = 1;
		salon.reputation_drop = 2;
		salon.month_income = 0;
		salon.month_expenses = 0;
		salon.month_profit = 0;
	}

	void salon_inflation_tick() {
		double inflation_month = (10.0 / 100.0 / 12.0);
		salon.price_small *= (1.0 + inflation_month);
		salon.price_medium *= (1.0 + inflation_month);
		salon.price_large *= (1.0 + inflation_month);
		salon.rent *= (1.0 + inflation_month);
		salon.utilities *= (1.0 + inflation_month);
		salon.internet *= (1.0 + inflation_month);
		salon.ink *= (1.0 + inflation_month);
		salon.needles *= (1.0 + inflation_month);
		salon.gloves *= (1.0 + inflation_month);
		salon.antiseptic *= (1.0 + inflation_month);
		salon.film *= (1.0 + inflation_month);
		salon.paper *= (1.0 + inflation_month);
		salon.cleaning *= (1.0 + inflation_month);
		salon.marketing *= (1.0 + inflation_month);
		salon.smm *= (1.0 + inflation_month);
		salon.ads *= (1.0 + inflation_month);
		salon.master_salary *= (1.0 + inflation_month);
		salon.admin_salary *= (1.0 + inflation_month);
		salon.staff_taxes *= (1.0 + inflation_month);
		salon.equipment_value *= (1.0 + inflation_month);
		salon.equipment_repair_cost *= (1.0 + inflation_month);
	}

	RUB salon_income_calculate() {
		RUB income = 0;
		income += salon.clients_small * salon.price_small;
		income += salon.clients_medium * salon.price_medium;
		income += salon.clients_large * salon.price_large;
		income += salon.tips;
		return income;
	}

	RUB salon_expenses_calculate() {
		RUB exp = 0;
		exp += salon.rent;
		exp += salon.utilities;
		exp += salon.internet;
		exp += salon.ink;
		exp += salon.needles;
		exp += salon.gloves;
		exp += salon.antiseptic;
		exp += salon.film;
		exp += salon.paper;
		exp += salon.cleaning;
		exp += salon.marketing;
		exp += salon.smm;
		exp += salon.ads;
		exp += salon.master_salary;
		exp += salon.admin_salary;
		exp += salon.staff_taxes;
		return exp;
	}

	void salon_equipment_wear_tick() {
		salon.equipment_wear += salon.equipment_monthly_wear;
		if (salon.equipment_wear > 100) {
			salon.equipment_wear = 100;
		}
	}

	void salon_equipment_repair_if_needed() {
		if (salon.equipment_wear < 80) {
			return;
		}
		if (salon.cash >= salon.equipment_repair_cost) {
			salon.cash -= salon.equipment_repair_cost;
			salon.month_expenses += salon.equipment_repair_cost;
			if (salon.equipment_wear >= 30) {
				salon.equipment_wear -= 30;
			}
			else {
				salon.equipment_wear = 0;
			}
		}
		else {
			if (salon.reputation >= salon.reputation_drop) {
				salon.reputation -= salon.reputation_drop;
			}
			else {
				salon.reputation = 0;
			}
		}
	}

	void salon_reputation_tick() {
		if (salon.equipment_wear <= 60) {
			if (salon.reputation + salon.reputation_growth <= 100) {
				salon.reputation += salon.reputation_growth;
			}
			else {
				salon.reputation = 100;
			}
		}
		if (salon.reputation < 40) {
			if (salon.clients_small > 10) { salon.clients_small -= 1; }
			if (salon.clients_medium > 6) { salon.clients_medium -= 1; }
		}
		if (salon.reputation > 70) {
			salon.clients_small += 1;
			if ((salon.clients_small % 3) == 0) {
				salon.clients_medium += 1;
			}
			if ((salon.clients_small % 6) == 0) {
				salon.clients_large += 1;
			}
		}
	}

	RUB salon_tax_from_profit(const RUB profit) {
		if (profit <= 0) {
			return 0;
		}
		double part = (salon.tax_percent / 100.0);
		RUB tax = (RUB)(profit * part);
		if (tax < 0) {
			tax = 0;
		}
		return tax;
	}

	void salon_month_tick() {
		salon.month_income = 0;
		salon.month_expenses = 0;
		salon.month_profit = 0;
		RUB income = salon_income_calculate();
		salon.cash += income;
		salon.month_income += income;
		RUB exp = salon_expenses_calculate();
		if (salon.cash >= exp) {
			salon.cash -= exp;
			salon.month_expenses += exp;
		}
		else {
			RUB rest = exp - salon.cash;
			salon.month_expenses += salon.cash;
			salon.cash = 0;
			pay_from_all_cards(Alice, rest, "tattoo salon expenses", "Alice");
			salon.month_expenses += rest;
		}
		RUB profit_before_tax = salon.month_income - salon.month_expenses;
		RUB tax = salon_tax_from_profit(profit_before_tax);
		if (tax > 0) {
			if (salon.cash >= tax) {
				salon.cash -= tax;
				salon.month_expenses += tax;
			}
			else {
				RUB rest = tax - salon.cash;
				salon.month_expenses += salon.cash;
				salon.cash = 0;
				pay_from_all_cards(Alice, rest, "tattoo salon tax", "Alice");
				salon.month_expenses += rest;
			}
		}
		salon.month_profit = salon.month_income - salon.month_expenses;
		salon_equipment_wear_tick();
		salon_equipment_repair_if_needed();
		salon_reputation_tick();
		const RUB salon_reserve = 150'000;
		if (salon.cash > salon_reserve) {
			RUB to_owner = salon.cash - salon_reserve;
			salon.cash -= to_owner;
			Alice.Tbank.card += to_owner;
		}
	}

	void print_salon() {
		printf("========== Tattoo salon ==========\n");
		printf("salon cash = %lld\n", salon.cash);
		printf("Clients: small=%lld medium=%lld large=%lld\n", salon.clients_small, salon.clients_medium, salon.clients_large);
		printf("Prices: small=%lld medium=%lld large=%lld\n", salon.price_small, salon.price_medium, salon.price_large);
		printf("Month income = %lld\n", salon.month_income);
		printf("Month expenses = %lld\n", salon.month_expenses);
		printf("Month profit = %lld\n", salon.month_profit);
		printf("Equipment value = %lld\n", salon.equipment_value);
		printf("Equipment wear = %lld\n", salon.equipment_wear);
		printf("Equipment repair = %lld\n", salon.equipment_repair_cost);
		printf("Reputation = %lld\n", salon.reputation);
		printf("Rent = %lld\n", salon.rent);
		printf("Utilities = %lld\n", salon.utilities);
		printf("Internet = %lld\n", salon.internet);
		printf("Consumables: ink=%lld needles=%lld gloves=%lld antiseptic=%lld film=%lld paper=%lld cleaning=%lld\n",
			salon.ink, salon.needles, salon.gloves, salon.antiseptic, salon.film, salon.paper, salon.cleaning);
		printf("Marketing: marketing=%lld smm=%lld ads=%lld\n", salon.marketing, salon.smm, salon.ads);
		printf("Staff: master=%lld admin=%lld taxes=%lld\n", salon.master_salary, salon.admin_salary, salon.staff_taxes);
		printf("\n");
	}

	void couple_inflation_tick() {
		inflation_tick_person(Alice);
		inflation_tick_person(David);
		inflation_tick_home();
		salon_inflation_tick();
	}

	void couple_bank_tick() {
		person_deposit_month_tick(Alice);
		person_deposit_month_tick(David);
		person_credit_month_tick(Alice);
		person_credit_month_tick(David);
		person_cashback_tick(Alice);
		person_cashback_tick(David);
	}

	void person_move_money_to_best_deposit(Person& person, const RUB emergency_fund) {
		Bank& best =
			(person.Sberbank.deposit_apr > person.Tbank.deposit_apr &&
				person.Sberbank.deposit_apr > person.Alfabank.deposit_apr &&
				person.Sberbank.deposit_apr > person.VTB.deposit_apr) ? person.Sberbank :
			(person.Alfabank.deposit_apr > person.Tbank.deposit_apr &&
				person.Alfabank.deposit_apr > person.VTB.deposit_apr) ? person.Alfabank :
			(person.VTB.deposit_apr > person.Tbank.deposit_apr) ? person.VTB :
			person.Tbank;
		if (person.Tbank.card > emergency_fund) {
			RUB amount = person.Tbank.card - emergency_fund;
			person.Tbank.card -= amount;
			best.deposit += amount;
		}
	}

	void Alice_move_money_to_deposit() {
		const RUB emergency_fund = 250'000;
		person_move_money_to_best_deposit(Alice, emergency_fund);
	}

	void David_move_money_to_deposit() {
		const RUB emergency_fund = 120'000;
		person_move_money_to_best_deposit(David, emergency_fund);
	}

	RUB person_total_cash(const Person& person) {
		return person.Tbank.card + person.Sberbank.card + person.Alfabank.card + person.VTB.card
			+ person.Tbank.deposit + person.Sberbank.deposit + person.Alfabank.deposit + person.VTB.deposit;
	}

	RUB person_total_credits(const Person& person) {
		return person.Tbank.credit_debt + person.Sberbank.credit_debt + person.Alfabank.credit_debt + person.VTB.credit_debt;
	}

	RUB person_total_items(const Person& person) {
		RUB items = 0;
		items += person.items.phone.value;
		items += person.items.laptop.value;
		items += person.items.headphones.value;
		items += person.items.smartwatch.value;
		items += person.items.pc.value;
		items += person.items.monitor.value;
		items += person.items.keyboard.value;
		items += person.items.mouse.value;
		items += person.items.chair.value;
		items += person.items.console.value;
		items += person.items.tv.value;
		items += person.items.fridge.value;
		items += person.items.microwave.value;
		items += person.items.washing_machine.value;
		items += person.items.vacuum.value;
		items += person.items.coffee_machine.value;
		items += person.items.blender.value;
		items += person.items.bed.value;
		items += person.items.sofa.value;
		items += person.items.table.value;
		items += person.items.skates.value;
		items += person.items.bike.value;
		items += person.items.camera.value;
		items += person.items.toolbox.value;
		return items;
	}

	RUB person_total_assets(const Person& person) {
		return person.car.value + person.cat.value + person_total_items(person);
	}

	void goals_init() {
		goals.travel_fund = 0;
		goals.repair_fund = 0;
		goals.education_fund = 0;
		goals.emergency_fund_target = 500'000;
		goals.monthly_to_travel = 15'000;
		goals.monthly_to_repair = 10'000;
		goals.monthly_to_education = 8'000;
		goals.last_event_cost = 0;
	}

	RUB bank_total_money(const Bank& b) {
		return b.card + b.deposit;
	}

	RUB person_total_money_everywhere(const Person& person) {
		return bank_total_money(person.Tbank) + bank_total_money(person.Sberbank) + bank_total_money(person.Alfabank) + bank_total_money(person.VTB);
	}

	Bank* person_best_deposit_bank(Person& person) {
		double best = person.Tbank.deposit_apr;
		Bank* b = &person.Tbank;
		if (person.Sberbank.deposit_apr > best) { best = person.Sberbank.deposit_apr; b = &person.Sberbank; }
		if (person.Alfabank.deposit_apr > best) { best = person.Alfabank.deposit_apr; b = &person.Alfabank; }
		if (person.VTB.deposit_apr > best) { best = person.VTB.deposit_apr; b = &person.VTB; }
		return b;
	}

	void move_from_card_to_deposit(Bank& from_card, Bank& to_deposit, const RUB amount) {
		if (amount <= 0) return;
		if (from_card.card >= amount) {
			from_card.card -= amount;
			to_deposit.deposit += amount;
		}
		else {
			RUB moved = from_card.card;
			from_card.card = 0;
			to_deposit.deposit += moved;
		}
	}

	void goals_month_tick() {
		Bank* best = person_best_deposit_bank(Alice);
		if (Alice.Tbank.card > 0) {
			RUB x = goals.monthly_to_travel;
			if (x > Alice.Tbank.card) x = Alice.Tbank.card;
			Alice.Tbank.card -= x;
			best->deposit += x;
			goals.travel_fund += x;
		}
		if (Alice.Tbank.card > 0) {
			RUB x = goals.monthly_to_repair;
			if (x > Alice.Tbank.card) x = Alice.Tbank.card;
			Alice.Tbank.card -= x;
			best->deposit += x;
			goals.repair_fund += x;
		}
		if (Alice.Tbank.card > 0) {
			RUB x = goals.monthly_to_education;
			if (x > Alice.Tbank.card) x = Alice.Tbank.card;
			Alice.Tbank.card -= x;
			best->deposit += x;
			goals.education_fund += x;
		}
	}

	RUB yearly_costs_tick(const int month, const int year) {
		(void)year;
		RUB total = 0;
		if (month == 4) {
			RUB tax = shared_home.bills.property_tax * 12;
			couple_pay_shared_bill_by_salary_with_help(tax, "property tax yearly (shared home)");
			total += tax;
		}
		if (month == 10) {
			RUB ins = shared_home.bills.home_insurance * 12;
			couple_pay_shared_bill_by_salary_with_help(ins, "home insurance yearly (shared home)");
			total += ins;
		}
		if (month == 1) {
			pay_from_all_cards(Alice, Alice.car.insurance * 12, "car insurance yearly", "Alice");
			pay_from_all_cards(David, David.car.insurance * 12, "car insurance yearly", "David");
			total += Alice.car.insurance * 12 + David.car.insurance * 12;
		}
		return total;
	}

	double season_multiplier_food(const int month) {
		if (month == 12 || month == 1 || month == 2) return 1.10;
		if (month == 6 || month == 7 || month == 8) return 0.95;
		return 1.00;
	}

	double season_multiplier_entertainment(const int month) {
		if (month == 12) return 1.30;
		if (month == 5) return 1.10;
		if (month == 8) return 1.15;
		return 1.00;
	}

	void couple_season_tick(const int month) {
		double mF = season_multiplier_food(month);
		double mE = season_multiplier_entertainment(month);
		Alice.food = (RUB)(Alice.food * mF);
		David.food = (RUB)(David.food * mF);
		Alice.entertainment = (RUB)(Alice.entertainment * mE);
		David.entertainment = (RUB)(David.entertainment * mE);
	}

	RUB planned_medical_event(Person& person, const char* who, const int month, const int year) {
		(void)year;
		RUB cost = 0;
		if (month == 3) {
			cost = 6'000;
		}
		if (month == 9) {
			cost = 8'000;
		}
		if (cost > 0) {
			pay_from_all_cards(person, cost, "planned medical", who);
		}
		return cost;
	}

	RUB planned_car_service_event(Person& person, const char* who, const int month, const int year) {
		(void)year;
		RUB cost = 0;
		if (month == 4) {
			cost = 15'000;
		}
		if (month == 10) {
			cost = 20'000;
		}
		if (cost > 0) {
			pay_from_all_cards(person, cost, "planned car service", who);
			person.car.repair += cost / 20;
		}
		return cost;
	}

	RUB planned_home_repair_event(const int month, const int year) {
		(void)year;
		RUB cost = 0;
		if (month == 5) {
			cost = 25'000;
		}
		if (month == 11) {
			cost = 35'000;
		}
		if (cost > 0) {
			couple_pay_shared_bill_by_salary_with_help(cost, "planned home repair");
		}
		return cost;
	}

	RUB planned_salon_expense_event(const int month, const int year) {
		(void)year;
		RUB cost = 0;
		if (month == 2) {
			cost = 12'000;
		}
		if (month == 8) {
			cost = 18'000;
		}
		if (cost <= 0) {
			return 0;
		}
		if (salon.cash >= cost) {
			salon.cash -= cost;
			salon.month_expenses += cost;
		}
		else {
			RUB rest = cost - salon.cash;
			salon.month_expenses += salon.cash;
			salon.cash = 0;
			pay_from_all_cards(Alice, rest, "planned salon expense", "Alice");
			salon.month_expenses += rest;
		}
		return cost;
	}

	RUB couple_planned_events_tick(const int month, const int year) {
		RUB total = 0;
		total += planned_medical_event(Alice, "Alice", month, year);
		total += planned_medical_event(David, "David", month, year);
		total += planned_car_service_event(Alice, "Alice", month, year);
		total += planned_car_service_event(David, "David", month, year);
		total += planned_home_repair_event(month, year);
		total += planned_salon_expense_event(month, year);
		goals.last_event_cost = total;
		return total;
	}

	void salon_try_upgrade() {
		if (salon.reputation < 75) return;
		const RUB need = 250'000;
		if (salon.cash < need) return;
		salon.cash -= need;
		salon.equipment_value += need;
		if (salon.equipment_wear >= 5) salon.equipment_wear -= 5;
		salon.price_small += 500;
		salon.price_medium += 900;
		salon.price_large += 1'200;
		salon.clients_small += 1;
	}

	RUB couple_total_net_worth() {
		RUB total_cash = person_total_cash(Alice) + person_total_cash(David) + salon.cash;
		RUB total_assets = person_total_assets(Alice) + person_total_assets(David) + shared_home.value + shared_home.furniture + salon.equipment_value;
		RUB total_debts = person_total_credits(Alice) + person_total_credits(David) + shared_home.mortgage_debt;
		return (total_cash + total_assets) - total_debts;
	}

	void person_more_items_repair(Person& person, const char* who) {
		try_repair_or_replace_item(person, person.items.fridge, "fridge", who);
		try_repair_or_replace_item(person, person.items.microwave, "microwave", who);
		try_repair_or_replace_item(person, person.items.coffee_machine, "coffee machine", who);
		try_repair_or_replace_item(person, person.items.blender, "blender", who);
		try_repair_or_replace_item(person, person.items.pc, "pc", who);
		try_repair_or_replace_item(person, person.items.monitor, "monitor", who);
		try_repair_or_replace_item(person, person.items.keyboard, "keyboard", who);
		try_repair_or_replace_item(person, person.items.mouse, "mouse", who);
		try_repair_or_replace_item(person, person.items.chair, "chair", who);
		try_repair_or_replace_item(person, person.items.skates, "skates", who);
	}

	void person_more_items_service(Person& person, const char* who) {
		RUB cloud = 350;
		RUB antivirus = 220;
		RUB music = 279;
		pay_from_all_cards(person, cloud, "cloud storage", who);
		pay_from_all_cards(person, antivirus, "antivirus", who);
		pay_from_all_cards(person, music, "music subscription", who);
	}

	void couple_season_special_expenses(const int month) {
		if (month == 12) {
			RUB gifts = 30'000;
			couple_pay_shared_bill_by_salary_with_help(gifts, "new year gifts (couple)");
		}
		if (month == 7) {
			RUB trip = 120'000;
			couple_pay_shared_bill_by_salary_with_help(trip, "summer vacation (couple)");
		}
		if (month == 3) {
			RUB check = 18'000;
			couple_pay_shared_bill_by_salary_with_help(check, "medical checkup (couple)");
		}
	}

	void extension_init() { goals_init(); }
	void all_month_tick(const int month, const int year) {
		couple_season_tick(month);
		couple_season_special_expenses(month);
		couple_planned_events_tick(month, year);
		yearly_costs_tick(month, year);
		person_more_items_service(Alice, "Alice");
		person_more_items_service(David, "David");
		person_more_items_repair(Alice, "Alice");
		person_more_items_repair(David, "David");
		salon_try_upgrade();
		goals_month_tick();
	}


	void print_bank_percent_details(const Bank& bank, const char* name) {
		printf("%s deposit APR = %.2f\n", name, bank.deposit_apr);
		printf("%s credit APR = %.2f\n", name, bank.credit_apr);
		printf("%s min payment percent = %.2f\n", name, bank.credit_min_payment_percent);
		printf("%s cashback percent = %.2f\n", name, bank.cashback_percent);
	}

	void print_person_bank_percents(const Person& person) {
		print_bank_percent_details(person.Tbank, "Tbank");
		print_bank_percent_details(person.Sberbank, "Sberbank");
		print_bank_percent_details(person.Alfabank, "Alfabank");
		print_bank_percent_details(person.VTB, "VTB");
	}

	RUB bank_net_money(const Bank& bank) {
		return bank.card + bank.deposit - bank.credit_debt;
	}

	void print_bank_money_details(const Bank& bank, const char* name) {
		printf("%s money = %lld\n", name, bank_total_money(bank));
		printf("%s net money = %lld\n", name, bank_net_money(bank));
		printf("%s free credit = %lld\n", name, bank_credit_available(bank));
		printf("%s cashback pending = %lld\n", name, bank.cashback_pending);
	}

	void print_person_bank_money(const Person& person) {
		print_bank_money_details(person.Tbank, "Tbank");
		print_bank_money_details(person.Sberbank, "Sberbank");
		print_bank_money_details(person.Alfabank, "Alfabank");
		print_bank_money_details(person.VTB, "VTB");
	}

	RUB person_regular_life_costs(const Person& person) {
		RUB total = 0;
		total += person.food;
		total += person.clothes;
		total += person.entertainment;
		total += person.medicine;
		total += person.education;
		total += person.subscriptions;
		total += person.transport;
		total += person.gifts;
		total += person.cafe;
		total += person.hygiene;
		total += person.cosmetics;
		total += person.pets;
		total += person.games;
		return total;
	}

	RUB person_regular_car_costs(const Person& person) {
		RUB total = 0;
		total += person.car.gas;
		total += person.car.insurance;
		total += person.car.tax;
		total += person.car.repair;
		total += person.car.parking;
		total += person.car.wash;
		total += person.car.tires;
		total += person.car.service;
		return total;
	}

	RUB person_regular_pet_costs(const Person& person) {
		return person.cat.food + person.pets;
	}

	RUB person_regular_month_costs(const Person& person) {
		return person_regular_life_costs(person) + person_regular_car_costs(person) + person_regular_pet_costs(person);
	}

	void print_person_month_budget(const Person& person) {
		printf("Regular life costs = %lld\n", person_regular_life_costs(person));
		printf("Regular car costs = %lld\n", person_regular_car_costs(person));
		printf("Regular pet costs = %lld\n", person_regular_pet_costs(person));
		printf("Regular month costs = %lld\n", person_regular_month_costs(person));
	}

	RUB home_utility_costs() {
		RUB total = 0;
		total += shared_home.bills.electricity;
		total += shared_home.bills.water;
		total += shared_home.bills.gas;
		total += shared_home.bills.heating;
		return total;
	}

	RUB home_service_costs() {
		RUB total = 0;
		total += shared_home.bills.trash;
		total += shared_home.bills.intercom;
		total += shared_home.bills.repairs_fund;
		total += shared_home.bills.cleaning;
		return total;
	}

	RUB home_media_costs() {
		RUB total = 0;
		total += shared_home.bills.internet;
		total += shared_home.bills.tv;
		total += shared_home.bills.mobile;
		return total;
	}

	RUB home_month_costs() {
		RUB total = 0;
		total += home_utility_costs();
		total += home_service_costs();
		total += home_media_costs();
		total += shared_home.bills.home_insurance;
		total += shared_home.bills.property_tax;
		total += shared_home.mortgage_payment;
		return total;
	}

	void print_home_summary() {
		printf("Utility costs = %lld\n", home_utility_costs());
		printf("Home service costs = %lld\n", home_service_costs());
		printf("Home media costs = %lld\n", home_media_costs());
		printf("Full home month costs = %lld\n", home_month_costs());
	}

	void print_item_status_line(const Item& item, const char* name) {
		if (item.value <= 0) {
			return;
		}
		printf("%s status wear %.1f of 100\n", name, item.wear);
	}

	void print_person_item_status(const Person& person) {
		print_item_status_line(person.items.phone, "Phone");
		print_item_status_line(person.items.laptop, "Laptop");
		print_item_status_line(person.items.headphones, "Headphones");
		print_item_status_line(person.items.smartwatch, "Smartwatch");
		print_item_status_line(person.items.pc, "PC");
		print_item_status_line(person.items.monitor, "Monitor");
		print_item_status_line(person.items.keyboard, "Keyboard");
		print_item_status_line(person.items.mouse, "Mouse");
		print_item_status_line(person.items.chair, "Chair");
		print_item_status_line(person.items.console, "Console");
		print_item_status_line(person.items.tv, "TV");
		print_item_status_line(person.items.fridge, "Fridge");
		print_item_status_line(person.items.microwave, "Microwave");
		print_item_status_line(person.items.washing_machine, "Washing machine");
		print_item_status_line(person.items.vacuum, "Vacuum");
		print_item_status_line(person.items.coffee_machine, "Coffee machine");
		print_item_status_line(person.items.blender, "Blender");
		print_item_status_line(person.items.bed, "Bed");
		print_item_status_line(person.items.sofa, "Sofa");
		print_item_status_line(person.items.table, "Table");
		print_item_status_line(person.items.skates, "Skates");
		print_item_status_line(person.items.bike, "Bike");
		print_item_status_line(person.items.camera, "Camera");
		print_item_status_line(person.items.toolbox, "Toolbox");
	}

	void print_item(const Item& it, const char* name) {
		printf("%s: value=%lld wear=%.1f repair=%lld replace=%lld service=%lld\n", name, it.value, it.wear, it.repair_cost, it.replace_cost, it.service_cost);
	}

	void print_home() {
		printf("========== Shared Home ==========\n");
		printf("Home value = %lld\n", shared_home.value);
		printf("Furniture = %lld\n", shared_home.furniture);
		printf("Mortgage debt = %lld\n", shared_home.mortgage_debt);
		printf("Mortgage rate = %.2f\n", shared_home.mortgage_rate);
		printf("Mortgage payment = %lld\n", shared_home.mortgage_payment);
		printf("Bills:\n");
		print_home_summary();
		printf("Electricity = %lld\n", shared_home.bills.electricity);
		printf("Water = %lld\n", shared_home.bills.water);
		printf("Gas = %lld\n", shared_home.bills.gas);
		printf("Heating = %lld\n", shared_home.bills.heating);
		printf("Trash = %lld\n", shared_home.bills.trash);
		printf("Intercom = %lld\n", shared_home.bills.intercom);
		printf("Internet = %lld\n", shared_home.bills.internet);
		printf("TV = %lld\n", shared_home.bills.tv);
		printf("Mobile = %lld\n", shared_home.bills.mobile);
		printf("Home insurance = %lld\n", shared_home.bills.home_insurance);
		printf("Property tax = %lld\n", shared_home.bills.property_tax);
		printf("Repairs fund = %lld\n", shared_home.bills.repairs_fund);
		printf("Cleaning = %lld\n", shared_home.bills.cleaning);
		printf("\n");
	}

	void print_person(const Person& person, const char* name) {
		printf("========== %s ==========\n", name);
		printf("Salary(Tbank) = %lld\n", person.Tbank.salary);
		printf("Tbank: card=%lld deposit=%lld credit=%lld limit=%lld\n", person.Tbank.card, person.Tbank.deposit, person.Tbank.credit_debt, person.Tbank.credit_limit);
		printf("Sber:  card=%lld deposit=%lld credit=%lld limit=%lld\n", person.Sberbank.card, person.Sberbank.deposit, person.Sberbank.credit_debt, person.Sberbank.credit_limit);
		printf("Alfa:  card=%lld deposit=%lld credit=%lld limit=%lld\n", person.Alfabank.card, person.Alfabank.deposit, person.Alfabank.credit_debt, person.Alfabank.credit_limit);
		printf("VTB:   card=%lld deposit=%lld credit=%lld limit=%lld\n", person.VTB.card, person.VTB.deposit, person.VTB.credit_debt, person.VTB.credit_limit);
		print_person_bank_percents(person);
		print_person_bank_money(person);
		print_person_month_budget(person);
		printf("Cash total = %lld\n", person_total_cash(person));
		printf("Credits total = %lld\n", person_total_credits(person));
		printf("Assets total = %lld\n", person_total_assets(person));
		printf("Food = %lld\n", person.food);
		printf("Clothes = %lld\n", person.clothes);
		printf("Entertainment = %lld\n", person.entertainment);
		printf("Medicine = %lld\n", person.medicine);
		printf("Education = %lld\n", person.education);
		printf("Subscriptions = %lld\n", person.subscriptions);
		printf("Transport = %lld\n", person.transport);
		printf("Gifts = %lld\n", person.gifts);
		printf("Cafe = %lld\n", person.cafe);
		printf("Hygiene = %lld\n", person.hygiene);
		printf("Cosmetics = %lld\n", person.cosmetics);
		printf("Games = %lld\n", person.games);
		printf("Car value = %lld\n", person.car.value);
		printf("Gas = %lld\n", person.car.gas);
		printf("Insurance = %lld\n", person.car.insurance);
		printf("Tax = %lld\n", person.car.tax);
		printf("Repair = %lld\n", person.car.repair);
		printf("Parking = %lld\n", person.car.parking);
		printf("Wash = %lld\n", person.car.wash);
		printf("Tires = %lld\n", person.car.tires);
		printf("Service = %lld\n", person.car.service);
		printf("Cat value = %lld\n", person.cat.value);
		printf("Cat food = %lld\n", person.cat.food);
		printf("Items:\n");
		print_person_item_status(person);
		print_item(person.items.phone, "Phone");
		print_item(person.items.laptop, "Laptop");
		print_item(person.items.headphones, "Headphones");
		print_item(person.items.smartwatch, "Smartwatch");
		print_item(person.items.pc, "PC");
		print_item(person.items.monitor, "Monitor");
		print_item(person.items.keyboard, "Keyboard");
		print_item(person.items.mouse, "Mouse");
		print_item(person.items.chair, "Chair");
		print_item(person.items.console, "Console");
		print_item(person.items.tv, "TV");
		print_item(person.items.fridge, "Fridge");
		print_item(person.items.microwave, "Microwave");
		print_item(person.items.washing_machine, "Washing machine");
		print_item(person.items.vacuum, "Vacuum");
		print_item(person.items.coffee_machine, "Coffee machine");
		print_item(person.items.blender, "Blender");
		print_item(person.items.bed, "Bed");
		print_item(person.items.sofa, "Sofa");
		print_item(person.items.table, "Table");
		print_item(person.items.skates, "Skates");
		print_item(person.items.gym_membership, "Gym membership");
		print_item(person.items.bike, "Bike");
		print_item(person.items.camera, "Camera");
		print_item(person.items.toolbox, "Toolbox");
		printf("\n");
	}

	void print_final_short_summary() {
		printf("Alice total money = %lld\n", person_total_money_everywhere(Alice));
		printf("David total money = %lld\n", person_total_money_everywhere(David));
		printf("Shared home month costs = %lld\n", home_month_costs());
		printf("Salon cash = %lld\n", salon.cash);
		printf("Travel fund = %lld\n", goals.travel_fund);
		printf("Education fund = %lld\n", goals.education_fund);
	}

	void print_results() {
		print_home();
		print_salon();
		print_person(Alice, "Alice");
		print_person(David, "David");
		RUB total_cash = person_total_cash(Alice) + person_total_cash(David) + salon.cash;
		RUB total_assets = person_total_assets(Alice) + person_total_assets(David) + shared_home.value + shared_home.furniture + salon.equipment_value;
		RUB total_debts = person_total_credits(Alice) + person_total_credits(David) + shared_home.mortgage_debt;
		print_final_short_summary();
		printf("========== Total Couple ==========\n");
		printf("Total cash (with salon) = %lld\n", total_cash);
		printf("Total assets (cash+property+salon) = %lld\n", total_cash + total_assets);
		printf("Total debts (credits+mortgage) = %lld\n", total_debts);
		printf("Net worth (assets - debts) = %lld\n", (total_cash + total_assets) - total_debts);
	}

	void simulation() {
		int month = 2;
		int year = 2026;
		while (!((month == 3) && (year == 2027))) {
			Alice_salary(month, year);
			Alice_pay_food();
			Alice_pay_cat_food();
			Alice_pay_gas();
			Alice_pay_medicine();
			Alice_pay_education();
			Alice_pay_subscriptions();
			Alice_pay_transport();
			Alice_pay_clothes();
			Alice_pay_entertainment();
			Alice_pay_gifts();
			Alice_pay_cafe();
			Alice_pay_hygiene();
			Alice_pay_cosmetics();
			Alice_pay_games();
			Alice_pay_car_insurance();
			Alice_pay_car_tax();
			Alice_pay_car_repair();
			Alice_pay_parking();
			Alice_pay_car_wash();
			Alice_pay_tires();
			Alice_pay_car_service();
			David_salary(month, year);
			David_pay_food();
			David_pay_gas();
			David_pay_clothes();
			David_pay_entertainment();
			David_pay_medicine();
			David_pay_education();
			David_pay_subscriptions();
			David_pay_transport();
			David_pay_gifts();
			David_pay_cafe();
			David_pay_hygiene();
			David_pay_cosmetics();
			David_pay_games();
			David_pay_car_insurance();
			David_pay_car_tax();
			David_pay_car_repair();
			David_pay_parking();
			David_pay_car_wash();
			David_pay_tires();
			David_pay_car_service();
			salon_month_tick();
			mortgage_interest_tick();
			couple_inflation_tick();
			couple_bank_tick();
			couple_pay_electricity();
			couple_pay_water();
			couple_pay_gas_home();
			couple_pay_heating();
			couple_pay_trash();
			couple_pay_intercom();
			couple_pay_internet();
			couple_pay_tv();
			couple_pay_mobile();
			couple_pay_home_insurance();
			couple_pay_property_tax();
			couple_pay_repairs_fund();
			couple_pay_cleaning();
			couple_pay_mortgage();
			person_items_wear_tick(Alice);
			person_items_service_pay(Alice, "Alice");
			person_items_repair_or_replace(Alice, "Alice");
			person_items_wear_tick(David);
			person_items_service_pay(David, "David");
			person_items_repair_or_replace(David, "David");
			Alice_move_money_to_deposit();
			David_move_money_to_deposit();
			all_month_tick(month, year);
			++month;
			if (month == 13) {
				month = 1;
				++year;
			}
		}
	}

public:
	void start() { home_init(); init_Alice_profile(); init_David_profile(); salon_init(); extension_init(); simulation(); print_results(); }
};

int main() {
	LifeSimulation life;
	life.start();
	return 0;
}
