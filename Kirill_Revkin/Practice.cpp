#include <stdio.h> 

using RUB = long long int; 

struct Cat { // Структура для кота
	RUB value;
	RUB food;
};

struct Car { // Структура для машины
	RUB value;
	RUB gas;

	RUB insurance; // Страховка
	RUB tax; // Налог

	RUB parking;
	RUB wash;

	RUB tires; // Шины
	RUB service;
	RUB repair;
};

struct Bank { // Cтруктура для банка

	RUB salary;
	RUB card;
	RUB deposit;
	double deposit_apr;

	RUB credit_debt; // Текущий долг по кредиту
	RUB credit_limit; // Максимальный кредитный лимит
	RUB credit_penalty_fee; // Штраф за просрочку платежа по кредиту
	double credit_apr; 
	double credit_min_payment_percent; // Минимальный платеж по кредиту в процентах от долга

	RUB cashback_pending;
	double cashback_percent;
};

struct HomeBills { // Структура для ежемесячных платежей за дом
	RUB home_insurance; // Страховка дома
	RUB property_tax; // Налог на имущество

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

struct Home { // Структура для дома
	RUB value;

	RUB furniture; 

	RUB mortgage_debt; // Остаток по ипотеке
	RUB mortgage_payment; // Ежемесячный платеж по ипотеке
	double mortgage_rate; // Годовая процентная ставка по ипотеке

	HomeBills bills; 
};

struct Item { // Структура для предметов
	RUB value; // Стоимость предмета
	RUB wear; // Износ в процентах (0 - новый, 100 - полностью изношен)        
	RUB monthly_wear; // Ежемесячный износ в процентах   
	RUB repair_cost; // Стоимость ремонта для снижения износа на 30% (или до 0%)
	RUB replace_cost; // Стоимость замены при износе 90% или выше
	RUB service_cost; // Ежемесячная стоимость обслуживания (например, абонемент в спортзал)  
};

struct Inventory { // Структура для инвентаря
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

struct Person { // Структура для человека
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

struct TattooSalon { // Структура для тату-салона
	RUB cash;

	RUB price_small;
	RUB price_medium;
	RUB price_large;

	RUB clients_small; 
	RUB clients_medium;
	RUB clients_large;

	RUB tips;

	RUB rent;
	RUB utilities; // Коммунальные услуги
	RUB internet;

	RUB ink; // чернила
	RUB needles; // иглы
	RUB gloves;
	RUB antiseptic;
	RUB film; // пленка
	RUB paper; 

	RUB cleaning;

	RUB marketing;
	RUB smm;
	RUB ads;

	RUB equipment_value; // Стоимость оборудования
	RUB equipment_wear; // Износ оборудования в процентах
	RUB equipment_monthly_wear; // Ежемесячный износ оборудования в процентах
	RUB equipment_repair_cost; // Стоимость ремонта оборудования для снижения износа на 30% (или до 0%)

	RUB master_salary;
	RUB admin_salary;
	RUB staff_taxes; // Налоги на зарплату персонала

	double tax_percent; 

	RUB reputation;     
	RUB reputation_growth; 
	RUB reputation_drop; 

	RUB month_income; // Доход за месяц
	RUB month_expenses; // Расходы за месяц
	RUB month_profit; 
};

struct FamilyGoals { // Структура для целей семьи
	RUB travel_fund;
	RUB repair_fund;
	RUB education_fund;
	RUB emergency_fund_target;

	RUB monthly_to_travel;
	RUB monthly_to_repair;
	RUB monthly_to_education;

	RUB last_event_cost; // Стоимость последнего крупного события для корректировки планов
};

FamilyGoals Goals;

struct MonthLog { // Структура для логов месяца
	int month;
	int year;

	RUB alice_cash;
	RUB david_cash;
	RUB salon_cash;

	RUB alice_credits; 
	RUB david_credits;
	RUB mortgage_debt;

	RUB total_net_worth; // Суммарная стоимость всех активов семьи - суммарные долги семьи

	RUB events_cost; // Стоимость всех событий месяца
	RUB yearly_costs; // Стоимость всех событий года
};

Person Alice;
Person David;

Home SharedHome;
TattooSalon Salon;

void bank_init(Bank& bank) { // Инициализация банка с нулевыми значениями
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

void item_init(Item& it, const RUB value, const RUB wear, const RUB monthly_wear, const RUB repair_cost, const RUB replace_cost, const RUB service_cost) { // Инициализация предмета с заданными параметрами
	it.value = value;
	it.wear = wear;
	it.monthly_wear = monthly_wear;
	it.repair_cost = repair_cost;
	it.replace_cost = replace_cost;
	it.service_cost = service_cost;
}

void home_bills_init() { // Инициализация ежемесячных платежей за дом
	SharedHome.bills.electricity = 3'500;
	SharedHome.bills.water = 2'500;
	SharedHome.bills.gas = 1000;
	SharedHome.bills.heating = 2'000;

	SharedHome.bills.trash = 500;
	SharedHome.bills.intercom = 250;
	SharedHome.bills.internet = 1'000;
	SharedHome.bills.tv = 500;
	SharedHome.bills.mobile = 1'000;

	SharedHome.bills.home_insurance = 2'500;
	SharedHome.bills.property_tax = 1'500;

	SharedHome.bills.repairs_fund = 3'000;
	SharedHome.bills.cleaning = 1000;
}

void home_init() { // Инициализация данных дома
	SharedHome.value = 12'000'000;

	SharedHome.furniture = 750'000;

	SharedHome.mortgage_debt = 10'000'000;
	SharedHome.mortgage_rate = 12.0;
	SharedHome.mortgage_payment = 110'000;

	home_bills_init(); // Инициализация ежемесячных платежей за дом
}

void inventory_init_alice() { // Инициализация инвентаря Алисы с заданными параметрами
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

void inventory_init_david() { // Инициализация инвентаря Дэвида с заданными параметрами
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

void alice_init() { // Инициализация данных Алисы
	Alice.food = 30'000;

	Alice.clothes = 6'000;
	Alice.entertainment = 5'000; // Хобби
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

	inventory_init_alice(); // Инициализация инвентаря Алисы с заданными параметрами

	bank_init(Alice.Tbank);
	bank_init(Alice.Sberbank);
	bank_init(Alice.Alfabank);
	bank_init(Alice.VTB);

	Alice.Tbank.salary = 100'000;

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

void david_init() { // Инициализация данных Дэвида
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

	inventory_init_david(); // Инициализация инвентаря Дэвида с заданными параметрами

	bank_init(David.Tbank);
	bank_init(David.Sberbank);
	bank_init(David.Alfabank);
	bank_init(David.VTB);

	David.Tbank.salary = 40'000;

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

RUB pay_from_bank_card(Bank& bank, const RUB amount) { // Платеж с банковской карты
	if (amount <= 0) {
		return 0;
	}

	if (bank.card >= amount) { // Если на карте достаточно средств для оплаты, то списываем сумму платежа с карты
		bank.card -= amount;
		return 0;
	}

	else { // Если на карте недостаточно средств для оплаты, то списываем все, что есть на карте, и возвращаем остаток, который не удалось оплатить
		RUB rest = amount - bank.card;
		bank.card = 0;
		return rest;
	}
}

RUB person_total_card_money(const Person& p) { // Суммарное количество денег на всех картах человека
	return p.Tbank.card + p.Sberbank.card + p.Alfabank.card + p.VTB.card;
}

void bank_transfer_cards(Bank& from, Bank& to, const RUB amount) { // Перевод денег с одной карты на другую
	if (amount <= 0) {
		return;
	}

	if (from.card >= amount) { // Если на карте-отправителе достаточно средств для перевода, то списываем сумму перевода с карты-отправителя и добавляем ее на карту-получателя
		from.card -= amount;
		to.card += amount;
	}
	else { // Если на карте-отправителе недостаточно средств для перевода, то переводим все, что есть на карте-отправителе, и обнуляем ее
		RUB moved = from.card;
		from.card = 0;
		to.card += moved;
	}
}

void person_transfer_to_people(Person& from, Person& to, const RUB amount) { // Перевод денег с карты одного человека на карту другого человека
	if (amount <= 0) { 
		return;
	}

	bank_transfer_cards(from.Tbank, to.Tbank, amount); // Сначала пытаемся перевести деньги с карты в банке Tbank
}

void pay_from_all_cards(Person& p, const RUB amount, const char* what, const char* who) { // Платеж с карт всех банков человека
	RUB rest = amount; // Остаток, который нужно оплатить

	rest = pay_from_bank_card(p.Tbank, rest); 
	rest = pay_from_bank_card(p.Sberbank, rest);
	rest = pay_from_bank_card(p.Alfabank, rest);
	rest = pay_from_bank_card(p.VTB, rest);

	if (rest > 0) { // Если после оплаты с всех карт остался остаток, который не удалось оплатить, то выводим сообщение 
		printf("%s cannot pay for %s! Need: %lld, Unpaid: %lld\n", who, what, amount, rest);
	}
}

void add_cashback_for_spending(Bank& bank, const RUB amount) { // Начисление кэшбэка за потраченные деньги
	if (amount <= 0) {
		return;
	}

	double part = (bank.cashback_percent / 100.0); // Процент кэшбэка
	RUB cb = (RUB)(amount * part); // Сумма кэшбэка за эту покупку
	if (cb < 0) {
		cb = 0;
	}
	bank.cashback_pending += cb;
}

void person_cashback_tick(Person& p) { // Начисление кэшбэка на карты человека
	p.Tbank.card += p.Tbank.cashback_pending;
	p.Sberbank.card += p.Sberbank.cashback_pending;
	p.Alfabank.card += p.Alfabank.cashback_pending;
	p.VTB.card += p.VTB.cashback_pending;

	p.Tbank.cashback_pending = 0;
	p.Sberbank.cashback_pending = 0;
	p.Alfabank.cashback_pending = 0;
	p.VTB.cashback_pending = 0;
}

RUB bank_credit_available(const Bank& bank) { // Доступный кредит в банке
	RUB avail = bank.credit_limit - bank.credit_debt;
	if (avail < 0) {
		avail = 0;
	}
	return avail;
}

RUB pay_from_credit(Bank& bank, const RUB amount) { // Платеж с использованием кредита банка
	if (amount <= 0) {
		return 0;
	}

	RUB avail = bank_credit_available(bank); // Доступный кредит в банке
	if (avail <= 0) {
		return amount;
	}

	if (avail >= amount) { // Если доступного кредита в банке достаточно для оплаты, то увеличиваем долг по кредиту на сумму платежа
		bank.credit_debt += amount;
		return 0;
	}

	else { // Если доступного кредита в банке недостаточно для оплаты, то используем весь доступный кредит и возвращаем остаток, который не удалось оплатить
		bank.credit_debt += avail;
		return amount - avail;
	}
}

void pay_with_cards_and_credit(Person& p, Bank& prefer_card_bank, Bank& prefer_credit_bank, const RUB amount, const char* what, const char* who) { // Платеж с использованием карт всех банков человека и кредита одного из банков человека
	if (amount <= 0) {
		return;
	}

	RUB rest = amount;

	RUB before = prefer_card_bank.card; // Сохраняем сумму на карте предпочитаемого банка до оплаты
	rest = pay_from_bank_card(prefer_card_bank, rest); // Пытаемся оплатить с карты предпочитаемого банка
	RUB spent = before - prefer_card_bank.card; // Считаем, сколько удалось оплатить с карты предпочитаемого банка
	add_cashback_for_spending(prefer_card_bank, spent); // Начисляем кэшбэк за потраченные деньги с карты предпочитаемого банка

	if (&prefer_card_bank != &p.Tbank) { // Если предпочитаемый банк для оплаты картой не Tbank, то пытаемся оплатить с карты Tbank
		RUB b = p.Tbank.card;
		rest = pay_from_bank_card(p.Tbank, rest);
		add_cashback_for_spending(p.Tbank, b - p.Tbank.card);
	}
	 
	if (&prefer_card_bank != &p.Sberbank) { // Если предпочитаемый банк для оплаты картой не Sberbank, то пытаемся оплатить с карты Sberbank
		RUB b = p.Sberbank.card;
		rest = pay_from_bank_card(p.Sberbank, rest);
		add_cashback_for_spending(p.Sberbank, b - p.Sberbank.card);
	}

	if (&prefer_card_bank != &p.Alfabank) { // Если предпочитаемый банк для оплаты картой не Alfabank, то пытаемся оплатить с карты Alfabank
		RUB b = p.Alfabank.card;
		rest = pay_from_bank_card(p.Alfabank, rest);
		add_cashback_for_spending(p.Alfabank, b - p.Alfabank.card);
	}

	if (&prefer_card_bank != &p.VTB) { // Если предпочитаемый банк для оплаты картой не VTB, то пытаемся оплатить с карты VTB
		RUB b = p.VTB.card;
		rest = pay_from_bank_card(p.VTB, rest);
		add_cashback_for_spending(p.VTB, b - p.VTB.card);
	}

	rest = pay_from_credit(prefer_credit_bank, rest); // Если после оплаты с карт всех банков остался остаток, который не удалось оплатить, то пытаемся оплатить с помощью кредита предпочитаемого банка для кредита 

	if (rest > 0) { // Если после оплаты с карт всех банков и кредита предпочитаемого банка для кредита остался остаток, который не удалось оплатить, то выводим сообщение
		printf("%s cannot pay for %s even with credit! Need: %lld, Unpaid: %lld\n", who, what, amount, rest);
	}
}

void deposit_interest_bank(Bank& bank) { // Начисление процентов на депозит в банке
	double deposit_month = (bank.deposit_apr / 100.0 / 12.0);
	bank.deposit += bank.deposit * deposit_month;
}

void credit_interest_bank(Bank& bank) { // Начисление процентов на кредит в банке
	if (bank.credit_debt <= 0) {
		return;
	}

	double credit_month = (bank.credit_apr / 100.0 / 12.0);
	bank.credit_debt += bank.credit_debt * credit_month;
}

RUB credit_min_payment(const Bank& bank) { // Расчет минимального платежа по кредиту в банке
	if (bank.credit_debt <= 0) {
		return 0;
	}

	double part = (bank.credit_min_payment_percent / 100.0); // Процент минимального платежа от долга
	RUB mp = (RUB)(bank.credit_debt * part); // Сумма минимального платежа по кредиту

	if (mp < 500) { // 
		mp = 500;
	}
	if (mp > bank.credit_debt) { // Если рассчитанный минимальный платеж больше текущего долга по кредиту, то минимальный платеж становится равным текущему долгу по кредиту
		mp = bank.credit_debt;
	}
	return mp;
}

void credit_pay_minimum(Bank& bank) { // Оплата минимального платежа по кредиту в банке
	RUB mp = credit_min_payment(bank); // Сумма минимального платежа по кредиту в банке
	if (mp <= 0) { // Если минимальный платеж по кредиту в банке равен нулю или меньше, то ничего не делаем
		return;
	}

	if (bank.card >= mp) { // Если на карте банка достаточно средств для оплаты минимального платежа по кредиту, то списываем сумму минимального платежа с карты и уменьшаем долг по кредиту на эту сумму
		bank.card -= mp;
		bank.credit_debt -= mp;
	}
	else { // Если на карте банка недостаточно средств для оплаты минимального платежа по кредиту, то списываем все, что есть на карте, и уменьшаем долг по кредиту на эту сумму, а также добавляем штраф за просрочку платежа
		RUB paid = bank.card;
		bank.card = 0;
		bank.credit_debt -= paid;
		if (bank.credit_debt < 0) { // Если после оплаты минимального платежа долг по кредиту стал меньше нуля, то обнуляем его
			bank.credit_debt = 0;
		}
		bank.credit_debt += bank.credit_penalty_fee;
	}
}

void person_credit_month_tick(Person& p) { // Начисление процентов по кредиту и оплата минимального платежа по кредиту для всех банков человека
	credit_interest_bank(p.Tbank);
	credit_interest_bank(p.Sberbank);
	credit_interest_bank(p.Alfabank);
	credit_interest_bank(p.VTB);

	credit_pay_minimum(p.Tbank);
	credit_pay_minimum(p.Sberbank);
	credit_pay_minimum(p.Alfabank);
	credit_pay_minimum(p.VTB);
}

void person_deposit_month_tick(Person& p) { // Начисление процентов по депозиту для всех банков человека
	deposit_interest_bank(p.Tbank);
	deposit_interest_bank(p.Sberbank);
	deposit_interest_bank(p.Alfabank);
	deposit_interest_bank(p.VTB);
}

void item_wear_tick(Item& it) { // Увеличение износа предмета на ежемесячный износ, если предмет имеет стоимость больше нуля
	if (it.value <= 0) { // Если стоимость предмета равна нулю или меньше, то не увеличиваем износ, так как такой предмет считается ненужным и неиспользуемым
		return;
	}

	it.wear += it.monthly_wear; // Увеличиваем износ предмета на ежемесячный износ
	if (it.wear > 100) {
		it.wear = 100;
	}
}

void person_items_wear_tick(Person& p) { // Увеличение износа всех предметов человека на ежемесячный износ
	item_wear_tick(p.items.phone);
	item_wear_tick(p.items.laptop);
	item_wear_tick(p.items.headphones);
	item_wear_tick(p.items.smartwatch);

	item_wear_tick(p.items.pc);
	item_wear_tick(p.items.monitor);
	item_wear_tick(p.items.keyboard);
	item_wear_tick(p.items.mouse);
	item_wear_tick(p.items.chair);

	item_wear_tick(p.items.console);
	item_wear_tick(p.items.tv);

	item_wear_tick(p.items.fridge);
	item_wear_tick(p.items.microwave);
	item_wear_tick(p.items.washing_machine);
	item_wear_tick(p.items.vacuum);
	item_wear_tick(p.items.coffee_machine);
	item_wear_tick(p.items.blender);

	item_wear_tick(p.items.bed);
	item_wear_tick(p.items.sofa);
	item_wear_tick(p.items.table);

	item_wear_tick(p.items.skates);
	item_wear_tick(p.items.bike);
	item_wear_tick(p.items.camera);

	item_wear_tick(p.items.toolbox);
}

void try_repair_or_replace_item(Person& p, Item& it, const char* item_name, const char* who) { // Попытка отремонтировать или заменить предмет, если его износ достиг определенных порогов
	if (it.value <= 0) { // Если стоимость предмета равна нулю или меньше, то не пытаемся его ремонтировать или заменять, так как такой предмет считается ненужным и неиспользуемым
		return;
	}

	if (it.wear < 80) { // Если износ предмета меньше 80, то не пытаемся его ремонтировать или заменять, так как он еще достаточно хорош для использования
		return;
	}

	RUB repair = it.repair_cost; // Стоимость ремонта предмета
	pay_from_all_cards(p, repair, item_name, who); // Пытаемся оплатить ремонт предмета с карт всех банков человека. Если после оплаты с карт всех банков остался остаток, который не удалось оплатить, то выводится сообщение

	if (it.wear >= 30) { // Если после оплаты ремонта предмета его износ все еще больше или равен 30, то считаем, что ремонт прошел успешно и уменьшаем износ предмета на 30. Иначе считаем, что ремонт не помог и обнуляем износ предмета, так как он уже почти полностью изношен
		it.wear -= 30;
	}
	else { 
		it.wear = 0;
	}

	if (it.wear >= 90) { // Если после ремонта предмета его износ все еще больше или равен 90, то считаем, что ремонт не помог и пытаемся заменить предмет. Для замены предмета нужно оплатить его стоимость замены с карт всех банков человека. Если после оплаты с карт всех банков остался остаток, который не удалось оплатить, то выводится сообщение. Если замена прошла успешно, то износ предмета обнуляется, так как он уже новый
		RUB repl = it.replace_cost;
		pay_from_all_cards(p, repl, item_name, who);

		it.value = repl;
		it.wear = 0;
	}
}

void person_items_service_pay(Person& p, const char* who) { // Оплата сервисного обслуживания для всех предметов человека, которые требуют сервисного обслуживания. Для оплаты сервисного обслуживания нужно оплатить его стоимость с карт всех банков человека. Если после оплаты с карт всех банков остался остаток, который не удалось оплатить, то выводится сообщение
	pay_from_all_cards(p, p.items.phone.service_cost, "phone service", who);
	pay_from_all_cards(p, p.items.laptop.service_cost, "laptop service", who);
	pay_from_all_cards(p, p.items.headphones.service_cost, "headphones service", who);
	pay_from_all_cards(p, p.items.smartwatch.service_cost, "smartwatch service", who);

	pay_from_all_cards(p, p.items.gym_membership.service_cost, "gym membership", who);
}

void person_items_repair_or_replace(Person& p, const char* who) { // Попытка отремонтировать или заменить все предметы человека, которые имеют износ больше или равен 80. Для ремонта или замены предмета нужно оплатить его стоимость ремонта или замены с карт всех банков человека. Если после оплаты с карт всех банков остался остаток, который не удалось оплатить, то выводится сообщение
	try_repair_or_replace_item(p, p.items.phone, "phone", who);
	try_repair_or_replace_item(p, p.items.laptop, "laptop", who);
	try_repair_or_replace_item(p, p.items.headphones, "headphones", who);
	try_repair_or_replace_item(p, p.items.smartwatch, "smartwatch", who);

	try_repair_or_replace_item(p, p.items.tv, "tv", who);
	try_repair_or_replace_item(p, p.items.vacuum, "vacuum", who);
	try_repair_or_replace_item(p, p.items.washing_machine, "washing machine", who);
}

void alice_salary(const int month, const int year) { // Начисление зарплаты Алисе. Если месяц август 2026 года, то зарплата Алисы увеличивается на 50% из-за повышения на работе
	if ((month == 8) && (year == 2026))
	{
		Alice.Tbank.salary *= 1.5;
	}

	Alice.Tbank.card += Alice.Tbank.salary;
}

void david_salary(const int month, const int year) { // Начисление зарплаты Дэвиду. Если месяц август 2026 года, то зарплата Дэвида увеличивается на 25% из-за повышения на работе
	if ((month == 8) && (year == 2026))
	{
		David.Tbank.salary *= 1.5;
	}

	David.Tbank.card += David.Tbank.salary;
}

void inflation_tick_person(Person& p) { // Увеличение расходов человека на 10% в год из-за инфляции
	double inflation_month = (10 / 100.0 / 12.0);

	p.food *= (1.0 + inflation_month);

	p.clothes *= (1.0 + inflation_month);
	p.entertainment *= (1.0 + inflation_month);
	p.medicine *= (1.0 + inflation_month);
	p.education *= (1.0 + inflation_month);
	p.subscriptions *= (1.0 + inflation_month);

	p.transport *= (1.0 + inflation_month);
	p.gifts *= (1.0 + inflation_month);
	p.cafe *= (1.0 + inflation_month);

	p.hygiene *= (1.0 + inflation_month);
	p.cosmetics *= (1.0 + inflation_month);
	p.pets *= (1.0 + inflation_month);
	p.games *= (1.0 + inflation_month);

	p.car.gas *= (1.0 + inflation_month);
	p.car.insurance *= (1.0 + inflation_month);
	p.car.tax *= (1.0 + inflation_month);
	p.car.repair *= (1.0 + inflation_month);
	p.car.parking *= (1.0 + inflation_month);
	p.car.wash *= (1.0 + inflation_month);
	p.car.tires *= (1.0 + inflation_month);
	p.car.service *= (1.0 + inflation_month);

	p.car.value *= (1.0 + inflation_month);

	p.cat.food *= (1.0 + inflation_month);
	p.cat.value *= (1.0 + inflation_month);

	p.items.phone.repair_cost *= (1.0 + inflation_month);
	p.items.laptop.repair_cost *= (1.0 + inflation_month);
	p.items.headphones.repair_cost *= (1.0 + inflation_month);
	p.items.smartwatch.repair_cost *= (1.0 + inflation_month);

	p.items.phone.replace_cost *= (1.0 + inflation_month);
	p.items.laptop.replace_cost *= (1.0 + inflation_month);
	p.items.headphones.replace_cost *= (1.0 + inflation_month);
	p.items.smartwatch.replace_cost *= (1.0 + inflation_month);

	p.items.gym_membership.service_cost *= (1.0 + inflation_month);
}

void inflation_tick_home() { // Увеличение расходов на содержание общего жилья на 10% в год из-за инфляции
	double inflation_month = (10 / 100.0 / 12.0);

	SharedHome.value *= (1.0 + inflation_month);
	SharedHome.furniture *= (1.0 + inflation_month);

	SharedHome.bills.electricity *= (1.0 + inflation_month);
	SharedHome.bills.water *= (1.0 + inflation_month);
	SharedHome.bills.gas *= (1.0 + inflation_month);
	SharedHome.bills.heating *= (1.0 + inflation_month);

	SharedHome.bills.trash *= (1.0 + inflation_month);
	SharedHome.bills.intercom *= (1.0 + inflation_month);
	SharedHome.bills.internet *= (1.0 + inflation_month);
	SharedHome.bills.tv *= (1.0 + inflation_month);
	SharedHome.bills.mobile *= (1.0 + inflation_month);

	SharedHome.bills.home_insurance *= (1.0 + inflation_month);
	SharedHome.bills.property_tax *= (1.0 + inflation_month);

	SharedHome.bills.repairs_fund *= (1.0 + inflation_month);
	SharedHome.bills.cleaning *= (1.0 + inflation_month);
}

void mortgage_interest_tick() { // Начисление процентов по ипотеке на долг по ипотеке. Если долг по ипотеке равен нулю или меньше, то проценты не начисляются
	double mortgage_month = (SharedHome.mortgage_rate / 100.0 / 12.0);
	SharedHome.mortgage_debt += SharedHome.mortgage_debt * mortgage_month;
}

RUB person_salary_now(const Person& p) { // Получение текущей зарплаты человека
	return p.Tbank.salary;
}

void couple_split_by_salary(const RUB total, RUB& alice_part, RUB& david_part) { // Разделение общей суммы расходов на части для Алисы и Дэвида пропорционально их зарплатам. Если у одного из них зарплата отрицательная, то она считается нулевой. Если сумма зарплат обоих равна нулю или меньше, то общая сумма расходов делится поровну между ними
	RUB sA = person_salary_now(Alice);
	RUB sD = person_salary_now(David);

	if (sA < 0) { sA = 0; }
	if (sD < 0) { sD = 0; }

	RUB sum = sA + sD;
	if (sum <= 0) {
		alice_part = total / 2;
		david_part = total - alice_part;
		return;
	}

	double shareA = (double)sA / (double)sum;
	alice_part = (RUB)(total * shareA);
	david_part = total - alice_part;
}

void couple_help_if_needed(Person& who_needs_help, Person& helper, RUB need_amount, const char* need_name) { // Если человеку, который нуждается в помощи, не хватает денег для оплаты своих расходов, то другой человек может помочь ему, переведя деньги с карты. Сумма помощи не может быть больше, чем сумма, которая нужна человеку, который нуждается в помощи, и не может быть больше, чем сумма денег на картах человека, который помогает
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

void couple_pay_shared_bill_by_salary_with_help(const RUB total, const char* what) { // Пара платит за общую статью расходов, разделяя ее пропорционально своим зарплатам. Если одному из них не хватает денег для оплаты своей части, то другой помогает ему, переводя деньги с карты. Сумма помощи не может быть больше, чем сумма, которая нужна человеку, который нуждается в помощи, и не может быть больше, чем сумма денег на картах человека, который помогает
	RUB a = 0;
	RUB d = 0;

	couple_split_by_salary(total, a, d);

	RUB alice_before = person_total_card_money(Alice);
	pay_from_all_cards(Alice, a, what, "Alice");
	RUB alice_after = person_total_card_money(Alice);

	RUB alice_paid = alice_before - alice_after;
	RUB alice_unpaid = a - alice_paid;
	if (alice_unpaid < 0) { alice_unpaid = 0; }

	RUB david_before = person_total_card_money(David);
	pay_from_all_cards(David, d, what, "David");
	RUB david_after = person_total_card_money(David);

	RUB david_paid = david_before - david_after;
	RUB david_unpaid = d - david_paid;
	if (david_unpaid < 0) { david_unpaid = 0; }

	if (alice_unpaid > 0) {
		couple_help_if_needed(Alice, David, alice_unpaid, what);
		pay_from_all_cards(Alice, alice_unpaid, what, "Alice");
	}

	if (david_unpaid > 0) {
		couple_help_if_needed(David, Alice, david_unpaid, what);
		pay_from_all_cards(David, david_unpaid, what, "David");
	}
}

// Функции для оплаты общих статей расходов пары, которые используют функцию для разделения расходов пропорционально зарплатам и оказания помощи друг другу при необходимости
void couple_pay_electricity() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.electricity, "electricity (shared home)"); }
void couple_pay_water() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.water, "water (shared home)"); }
void couple_pay_gas_home() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.gas, "home gas (shared home)"); }
void couple_pay_heating() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.heating, "heating (shared home)"); }

void couple_pay_trash() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.trash, "trash (shared home)"); }
void couple_pay_intercom() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.intercom, "intercom (shared home)"); }
void couple_pay_internet() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.internet, "internet (shared home)"); }
void couple_pay_tv() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.tv, "tv (shared home)"); }
void couple_pay_mobile() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.mobile, "mobile (shared home)"); }

void couple_pay_home_insurance() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.home_insurance, "home insurance (shared home)"); }
void couple_pay_property_tax() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.property_tax, "property tax (shared home)"); }

void couple_pay_repairs_fund() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.repairs_fund, "repairs fund (shared home)"); }
void couple_pay_cleaning() { couple_pay_shared_bill_by_salary_with_help(SharedHome.bills.cleaning, "cleaning (shared home)"); }

void couple_pay_mortgage() { // Оплата ипотеки для общего жилья. Пара платит за ипотеку, разделяя ее пропорционально своим зарплатам. Если одному из них не хватает денег для оплаты своей части, то другой помогает ему, переводя деньги с карты. Сумма помощи не может быть больше, чем сумма, которая нужна человеку, который нуждается в помощи, и не может быть больше, чем сумма денег на картах человека, который помогает. Если долг по ипотеке равен нулю или меньше, то ипотека считается полностью оплаченной и платить за нее не нужно
	if (SharedHome.mortgage_debt <= 0) {
		return;
	}

	couple_pay_shared_bill_by_salary_with_help(SharedHome.mortgage_payment, "mortgage (shared home)");

	if (SharedHome.mortgage_debt >= SharedHome.mortgage_payment) {
		SharedHome.mortgage_debt -= SharedHome.mortgage_payment;
	}
	else {
		SharedHome.mortgage_debt = 0;
	}
}

// Функции для оплаты личных статей расходов каждого человека, которые используют функцию для оплаты с карт всех банков человека и кредита одного из банков человека
void alice_pay_food() { pay_with_cards_and_credit(Alice, Alice.Alfabank, Alice.Alfabank, Alice.food, "food", "Alice"); }
void david_pay_food() { pay_with_cards_and_credit(David, David.Alfabank, David.Alfabank, David.food, "food", "David"); }

void alice_pay_gas() { pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.car.gas, "gas", "Alice"); }
void david_pay_gas() { pay_with_cards_and_credit(David, David.Tbank, David.Tbank, David.car.gas, "gas", "David"); }

void alice_pay_cat_food() { pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.cat.food, "cat food", "Alice"); }

void alice_pay_clothes() { pay_with_cards_and_credit(Alice, Alice.Sberbank, Alice.Sberbank, Alice.clothes, "clothes", "Alice"); }
void david_pay_clothes() { pay_with_cards_and_credit(David, David.Sberbank, David.Sberbank, David.clothes, "clothes", "David"); }

void alice_pay_entertainment() { pay_with_cards_and_credit(Alice, Alice.Alfabank, Alice.Alfabank, Alice.entertainment, "entertainment", "Alice"); }
void david_pay_entertainment() { pay_with_cards_and_credit(David, David.Alfabank, David.Alfabank, David.entertainment, "entertainment", "David"); }

void alice_pay_medicine() { pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.medicine, "medicine", "Alice"); }
void david_pay_medicine() { pay_with_cards_and_credit(David, David.Tbank, David.Tbank, David.medicine, "medicine", "David"); }

void alice_pay_education() { pay_with_cards_and_credit(Alice, Alice.VTB, Alice.VTB, Alice.education, "education", "Alice"); }
void david_pay_education() { pay_with_cards_and_credit(David, David.VTB, David.VTB, David.education, "education", "David"); }

void alice_pay_subscriptions() { pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.subscriptions, "subscriptions", "Alice"); }
void david_pay_subscriptions() { pay_with_cards_and_credit(David, David.Tbank, David.Tbank, David.subscriptions, "subscriptions", "David"); }

void alice_pay_transport() { pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.transport, "transport", "Alice"); }
void david_pay_transport() { pay_with_cards_and_credit(David, David.Tbank, David.Tbank, David.transport, "transport", "David"); }

void alice_pay_gifts() { pay_with_cards_and_credit(Alice, Alice.Sberbank, Alice.Sberbank, Alice.gifts, "gifts", "Alice"); }
void david_pay_gifts() { pay_with_cards_and_credit(David, David.Sberbank, David.Sberbank, David.gifts, "gifts", "David"); }

void alice_pay_cafe() { pay_with_cards_and_credit(Alice, Alice.Alfabank, Alice.Alfabank, Alice.cafe, "cafe", "Alice"); }
void david_pay_cafe() { pay_with_cards_and_credit(David, David.Alfabank, David.Alfabank, David.cafe, "cafe", "David"); }

void alice_pay_hygiene() { pay_with_cards_and_credit(Alice, Alice.Tbank, Alice.Tbank, Alice.hygiene, "hygiene", "Alice"); }
void david_pay_hygiene() { pay_with_cards_and_credit(David, David.Tbank, David.Tbank, David.hygiene, "hygiene", "David"); }

void alice_pay_cosmetics() { pay_with_cards_and_credit(Alice, Alice.Sberbank, Alice.Sberbank, Alice.cosmetics, "cosmetics", "Alice"); }
void david_pay_cosmetics() { pay_with_cards_and_credit(David, David.Sberbank, David.Sberbank, David.cosmetics, "cosmetics", "David"); }

void alice_pay_games() { pay_with_cards_and_credit(Alice, Alice.Alfabank, Alice.Alfabank, Alice.games, "games", "Alice"); }
void david_pay_games() { pay_with_cards_and_credit(David, David.Alfabank, David.Alfabank, David.games, "games", "David"); }

void alice_pay_car_insurance() { pay_from_all_cards(Alice, Alice.car.insurance, "car insurance", "Alice"); }
void david_pay_car_insurance() { pay_from_all_cards(David, David.car.insurance, "car insurance", "David"); }

void alice_pay_car_tax() { pay_from_all_cards(Alice, Alice.car.tax, "car tax", "Alice"); }
void david_pay_car_tax() { pay_from_all_cards(David, David.car.tax, "car tax", "David"); }

void alice_pay_car_repair() { pay_from_all_cards(Alice, Alice.car.repair, "car repair", "Alice"); }
void david_pay_car_repair() { pay_from_all_cards(David, David.car.repair, "car repair", "David"); }

void alice_pay_parking() { pay_from_all_cards(Alice, Alice.car.parking, "parking", "Alice"); }
void david_pay_parking() { pay_from_all_cards(David, David.car.parking, "parking", "David"); }

void alice_pay_car_wash() { pay_from_all_cards(Alice, Alice.car.wash, "car wash", "Alice"); }
void david_pay_car_wash() { pay_from_all_cards(David, David.car.wash, "car wash", "David"); }

void alice_pay_tires() { pay_from_all_cards(Alice, Alice.car.tires, "tires", "Alice"); }
void david_pay_tires() { pay_from_all_cards(David, David.car.tires, "tires", "David"); }

void alice_pay_car_service() { pay_from_all_cards(Alice, Alice.car.service, "car service", "Alice"); }
void david_pay_car_service() { pay_from_all_cards(David, David.car.service, "car service", "David"); }

void salon_init() { // Инициализация параметров салона татуировки
	Salon.cash = 1'000'000;

	Salon.price_small = 6'000;
	Salon.price_medium = 12'000;
	Salon.price_large = 20'000;

	Salon.clients_small = 47;
	Salon.clients_medium = 25;
	Salon.clients_large = 13;

	Salon.tips = 15'000;

	Salon.rent = 120'000;
	Salon.utilities = 9'000;
	Salon.internet = 1'200;

	Salon.ink = 10'000;
	Salon.needles = 7'000;
	Salon.gloves = 3'000;
	Salon.antiseptic = 2'500;
	Salon.film = 1'500;
	Salon.paper = 800;
	Salon.cleaning = 2'000;

	Salon.marketing = 15'000;
	Salon.smm = 10'000;
	Salon.ads = 12'000;

	Salon.equipment_value = 600'000;
	Salon.equipment_wear = 10;
	Salon.equipment_monthly_wear = 3;
	Salon.equipment_repair_cost = 18'000;

	Salon.master_salary = 90'000;
	Salon.admin_salary = 55'000;
	Salon.staff_taxes = 25'000;

	Salon.tax_percent = 6.0;

	Salon.reputation = 50;
	Salon.reputation_growth = 1;
	Salon.reputation_drop = 2;

	Salon.month_income = 0;
	Salon.month_expenses = 0;
	Salon.month_profit = 0;
}

void salon_inflation_tick() { // Увеличение цен на услуги и расходы салона татуировки на 10% в год из-за инфляции
	double inflation_month = (10 / 100.0 / 12.0);

	Salon.price_small *= (1.0 + inflation_month);
	Salon.price_medium *= (1.0 + inflation_month);
	Salon.price_large *= (1.0 + inflation_month);

	Salon.rent *= (1.0 + inflation_month);
	Salon.utilities *= (1.0 + inflation_month);
	Salon.internet *= (1.0 + inflation_month);

	Salon.ink *= (1.0 + inflation_month);
	Salon.needles *= (1.0 + inflation_month);
	Salon.gloves *= (1.0 + inflation_month);
	Salon.antiseptic *= (1.0 + inflation_month);
	Salon.film *= (1.0 + inflation_month);
	Salon.paper *= (1.0 + inflation_month);
	Salon.cleaning *= (1.0 + inflation_month);

	Salon.marketing *= (1.0 + inflation_month);
	Salon.smm *= (1.0 + inflation_month);
	Salon.ads *= (1.0 + inflation_month);

	Salon.master_salary *= (1.0 + inflation_month);
	Salon.admin_salary *= (1.0 + inflation_month);
	Salon.staff_taxes *= (1.0 + inflation_month);

	Salon.equipment_value *= (1.0 + inflation_month);
	Salon.equipment_repair_cost *= (1.0 + inflation_month);
}

RUB salon_income_calculate() { // Расчет дохода салона татуировки за месяц на основе количества клиентов, цен на услуги и чаевых
	RUB income = 0;

	income += Salon.clients_small * Salon.price_small;
	income += Salon.clients_medium * Salon.price_medium;
	income += Salon.clients_large * Salon.price_large;

	income += Salon.tips;

	return income;
}

RUB salon_expenses_calculate() { // Расчет расходов салона татуировки за месяц на основе арендной платы, коммунальных услуг, расходных материалов, маркетинга и зарплаты сотрудников
	RUB exp = 0;

	exp += Salon.rent;
	exp += Salon.utilities;
	exp += Salon.internet;

	exp += Salon.ink;
	exp += Salon.needles;
	exp += Salon.gloves;
	exp += Salon.antiseptic;
	exp += Salon.film;
	exp += Salon.paper;
	exp += Salon.cleaning;

	exp += Salon.marketing;
	exp += Salon.smm;
	exp += Salon.ads;

	exp += Salon.master_salary;
	exp += Salon.admin_salary;
	exp += Salon.staff_taxes;

	return exp;
}

void salon_equipment_wear_tick() { // Увеличение износа оборудования салона татуировки на ежемесячный износ. Если износ оборудования превышает 100, то он считается полностью изношенным и не может использоваться для работы, что может привести к потере клиентов и ухудшению репутации салона
	Salon.equipment_wear += Salon.equipment_monthly_wear;
	if (Salon.equipment_wear > 100) {
		Salon.equipment_wear = 100;
	}
}

void salon_equipment_repair_if_needed() { // Попытка отремонтировать оборудование салона татуировки, если его износ достиг 80. Для ремонта оборудования нужно оплатить его стоимость ремонта с карты салона. Если после оплаты ремонта оборудования его износ все еще больше или равен 30, то считаем, что ремонт прошел успешно и уменьшаем износ оборудования на 30. Иначе считаем, что ремонт не помог и обнуляем износ оборудования, так как оно уже почти полностью изношено. Если после ремонта оборудования его износ все еще больше или равен 80, то считаем, что ремонт не помог и ухудшаем репутацию салона на определенное количество пунктов. Если после ухудшения репутации салона ее значение стало меньше нуля, то обнуляем репутацию салона
	if (Salon.equipment_wear < 80) {
		return;
	}

	if (Salon.cash >= Salon.equipment_repair_cost) {
		Salon.cash -= Salon.equipment_repair_cost;
		Salon.month_expenses += Salon.equipment_repair_cost;

		if (Salon.equipment_wear >= 30) {
			Salon.equipment_wear -= 30;
		}
		else {
			Salon.equipment_wear = 0;
		}
	}
	else {
		if (Salon.reputation >= Salon.reputation_drop) {
			Salon.reputation -= Salon.reputation_drop;
		}
		else {
			Salon.reputation = 0;
		}
	}
}

void salon_reputation_tick() { // Изменение репутации салона татуировки в зависимости от износа оборудования и количества клиентов. Если износ оборудования меньше или равен 60, то репутация салона увеличивается на определенное количество пунктов, но не может превышать 100. Если репутация салона меньше 40, то количество клиентов малого и среднего размера уменьшается на 1, если оно больше определенного количества. Если репутация салона больше 70, то количество клиентов малого размера увеличивается на 1, а количество клиентов среднего и большого размера увеличивается на 1, если количество клиентов малого размера кратно определенному числу
	if (Salon.equipment_wear <= 60) {
		if (Salon.reputation + Salon.reputation_growth <= 100) {
			Salon.reputation += Salon.reputation_growth;
		}
		else {
			Salon.reputation = 100;
		}
	}

	if (Salon.reputation < 40) {
		if (Salon.clients_small > 10) { Salon.clients_small -= 1; }
		if (Salon.clients_medium > 6) { Salon.clients_medium -= 1; }
	}

	if (Salon.reputation > 70) {
		Salon.clients_small += 1;
		if ((Salon.clients_small % 3) == 0) {
			Salon.clients_medium += 1;
		}
		if ((Salon.clients_small % 6) == 0) {
			Salon.clients_large += 1;
		}
	}
}

RUB salon_tax_from_profit(const RUB profit) { // Расчет налога салона татуировки на основе его прибыли. Если прибыль меньше или равна нулю, то налог не начисляется. Иначе налог рассчитывается как определенный процент от прибыли. Если налог меньше нуля, то он считается нулем, так как налог не может быть отрицательным
	if (profit <= 0) {
		return 0;
	}

	double part = (Salon.tax_percent / 100.0);
	RUB tax = (RUB)(profit * part);
	if (tax < 0) {
		tax = 0;
	}
	return tax;
}

void salon_month_tick() { // Месячный тик для салона татуировки, который включает в себя расчет дохода и расходов за месяц, оплату расходов с карты салона и помощью от Алисы при необходимости, расчет налога на прибыль и его оплату с карты салона и помощью от Алисы при необходимости, обновление прибыли за месяц, увеличение износа оборудования, попытку отремонтировать оборудование при необходимости, обновление репутации салона и перевод избыточной наличности салона на карту Алисы
	Salon.month_income = 0;
	Salon.month_expenses = 0;
	Salon.month_profit = 0;

	RUB income = salon_income_calculate();
	Salon.cash += income;
	Salon.month_income += income;

	RUB exp = salon_expenses_calculate();
	if (Salon.cash >= exp) {
		Salon.cash -= exp;
		Salon.month_expenses += exp;
	}
	else {
		RUB rest = exp - Salon.cash;
		Salon.month_expenses += Salon.cash;
		Salon.cash = 0;

		pay_from_all_cards(Alice, rest, "tattoo salon expenses", "Alice");
		Salon.month_expenses += rest;
	}

	RUB profit_before_tax = Salon.month_income - Salon.month_expenses;
	RUB tax = salon_tax_from_profit(profit_before_tax);

	if (tax > 0) {
		if (Salon.cash >= tax) {
			Salon.cash -= tax;
			Salon.month_expenses += tax;
		}
		else {
			RUB rest = tax - Salon.cash;
			Salon.month_expenses += Salon.cash;
			Salon.cash = 0;

			pay_from_all_cards(Alice, rest, "tattoo salon tax", "Alice");
			Salon.month_expenses += rest;
		}
	}

	Salon.month_profit = Salon.month_income - Salon.month_expenses;

	salon_equipment_wear_tick();
	salon_equipment_repair_if_needed();
	salon_reputation_tick();

	const RUB salon_reserve = 150'000;
	if (Salon.cash > salon_reserve) {
		RUB to_owner = Salon.cash - salon_reserve;
		Salon.cash -= to_owner;
		Alice.Tbank.card += to_owner;
	}
}

void print_salon() { // Вывод текущего состояния салона татуировки, включая наличные, количество клиентов, цены на услуги, доходы и расходы за месяц, износ оборудования, репутацию и другие параметры
	printf("========== Tattoo Salon ==========\n");
	printf("Salon cash = %lld\n", Salon.cash);

	printf("Clients: small=%lld medium=%lld large=%lld\n", Salon.clients_small, Salon.clients_medium, Salon.clients_large);
	printf("Prices: small=%lld medium=%lld large=%lld\n", Salon.price_small, Salon.price_medium, Salon.price_large);

	printf("Month income = %lld\n", Salon.month_income);
	printf("Month expenses = %lld\n", Salon.month_expenses);
	printf("Month profit = %lld\n", Salon.month_profit);

	printf("Equipment value = %lld\n", Salon.equipment_value);
	printf("Equipment wear = %lld\n", Salon.equipment_wear);
	printf("Equipment repair = %lld\n", Salon.equipment_repair_cost);

	printf("Reputation = %lld\n", Salon.reputation);

	printf("Rent = %lld\n", Salon.rent);
	printf("Utilities = %lld\n", Salon.utilities);
	printf("Internet = %lld\n", Salon.internet);

	printf("Consumables: ink=%lld needles=%lld gloves=%lld antiseptic=%lld film=%lld paper=%lld cleaning=%lld\n",
		Salon.ink, Salon.needles, Salon.gloves, Salon.antiseptic, Salon.film, Salon.paper, Salon.cleaning);

	printf("Marketing: marketing=%lld smm=%lld ads=%lld\n", Salon.marketing, Salon.smm, Salon.ads);

	printf("Staff: master=%lld admin=%lld taxes=%lld\n", Salon.master_salary, Salon.admin_salary, Salon.staff_taxes);

	printf("\n");
}

void couple_inflation_tick() { // Месячный тик для инфляции, который увеличивает расходы каждого человека и общие расходы на содержание жилья на 10% в год из-за инфляции
	inflation_tick_person(Alice);
	inflation_tick_person(David);
	inflation_tick_home();

	salon_inflation_tick();
}

void couple_bank_tick() { // Месячный тик для банков, который включает в себя начисление процентов на депозиты, начисление процентов по кредитам и начисление кэшбэка на картах для каждого человека
	person_deposit_month_tick(Alice);
	person_deposit_month_tick(David);

	person_credit_month_tick(Alice);
	person_credit_month_tick(David);

	person_cashback_tick(Alice);
	person_cashback_tick(David);
}

void person_move_money_to_best_deposit(Person& p, const RUB emergency_fund) { // Перевод денег с карты банка, у которого меньше всего денег на карте, на депозит банка, у которого самый высокий процент по депозиту. Если после перевода на карте банка, у которого меньше всего денег на карте, останется меньше или равно emergency_fund, то перевод не выполняется, так как нужно оставить деньги на карте для экстренных случаев
	double best_apr = p.Tbank.deposit_apr;
	int best_id = 1;

	if (p.Sberbank.deposit_apr > best_apr) { best_apr = p.Sberbank.deposit_apr; best_id = 2; }
	if (p.Alfabank.deposit_apr > best_apr) { best_apr = p.Alfabank.deposit_apr; best_id = 3; }
	if (p.VTB.deposit_apr > best_apr) { best_apr = p.VTB.deposit_apr; best_id = 4; }

	Bank* best = &p.Tbank;
	if (best_id == 2) { best = &p.Sberbank; }
	if (best_id == 3) { best = &p.Alfabank; }
	if (best_id == 4) { best = &p.VTB; }

	if (p.Tbank.card > emergency_fund) {
		RUB amount = p.Tbank.card - emergency_fund;
		p.Tbank.card -= amount;
		best->deposit += amount;
	}
}

void alice_move_money_to_deposit() { // Перевод денег с карты банка, у которого меньше всего денег на карте, на депозит банка, у которого самый высокий процент по депозиту для Алисы. Если после перевода на карте банка, у которого меньше всего денег на карте, останется меньше или равно определенной суммы для экстренных случаев, то перевод не выполняется, так как нужно оставить деньги на карте для экстренных случаев
	const RUB emergency_fund = 250'000;
	person_move_money_to_best_deposit(Alice, emergency_fund);
}

void david_move_money_to_deposit() { // Перевод денег с карты банка, у которого меньше всего денег на карте, на депозит банка, у которого самый высокий процент по депозиту для Дэвида. Если после перевода на карте банка, у которого меньше всего денег на карте, останется меньше или равно определенной суммы для экстренных случаев, то перевод не выполняется, так как нужно оставить деньги на карте для экстренных случаев
	const RUB emergency_fund = 120'000;
	person_move_money_to_best_deposit(David, emergency_fund);
}

RUB person_total_cash(const Person& p) { // Получение общей суммы наличных денег человека, которая включает в себя деньги на картах всех банков человека и деньги в депозите банка, у которого самый высокий процент по депозиту
	return p.Tbank.card + p.Sberbank.card + p.Alfabank.card + p.VTB.card
		+ p.Tbank.deposit + p.Sberbank.deposit + p.Alfabank.deposit + p.VTB.deposit;
}

RUB person_total_credits(const Person& p) { // Получение общей суммы долгов по кредитам человека, которая включает в себя долги по кредитам всех банков человека
	return p.Tbank.credit_debt + p.Sberbank.credit_debt + p.Alfabank.credit_debt + p.VTB.credit_debt;
}

RUB person_total_items(const Person& p) { // Получение общей стоимости всех вещей человека, которая включает в себя стоимость всех категорий вещей человека
	RUB items = 0;

	items += p.items.phone.value;
	items += p.items.laptop.value;
	items += p.items.headphones.value;
	items += p.items.smartwatch.value;

	items += p.items.pc.value;
	items += p.items.monitor.value;
	items += p.items.keyboard.value;
	items += p.items.mouse.value;
	items += p.items.chair.value;

	items += p.items.console.value;
	items += p.items.tv.value;

	items += p.items.fridge.value;
	items += p.items.microwave.value;
	items += p.items.washing_machine.value;
	items += p.items.vacuum.value;
	items += p.items.coffee_machine.value;
	items += p.items.blender.value;

	items += p.items.bed.value;
	items += p.items.sofa.value;
	items += p.items.table.value;

	items += p.items.skates.value;
	items += p.items.bike.value;
	items += p.items.camera.value;

	items += p.items.toolbox.value;

	return items;
}

RUB person_total_assets(const Person& p) { // Получение общей стоимости всех активов человека, которая включает в себя общую сумму наличных денег человека и общую стоимость всех вещей человека
	return p.car.value + p.cat.value + person_total_items(p);
}

MonthLog Logs[24]; // Массив для хранения логов за каждый месяц. Каждый элемент массива представляет собой структуру, которая содержит информацию о том, что произошло в этом месяце, например, какие расходы были оплачены, какие доходы были получены, какие события произошли и т.д.
int LogsCount = 0;

static unsigned int g_seed = 123456789u; // Глобальная переменная для генератора псевдослучайных чисел, которая инициализируется определенным значением. Это значение может быть любым, но обычно выбирается так, чтобы обеспечить хорошее распределение случайных чисел

unsigned int prng_next() { // Генерация следующего псевдослучайного числа с помощью линейного конгруэнтного генератора. Эта функция использует глобальную переменную g_seed для хранения текущего состояния генератора и обновляет ее при каждом вызове, возвращая новое псевдослучайное число
	g_seed = (1103515245u * g_seed + 12345u);
	return g_seed;
}

int prng_range(const int a, const int b) { // Генерация псевдослучайного числа в заданном диапазоне от a до b включительно. Эта функция использует функцию prng_next() для получения следующего псевдослучайного числа и преобразует его в нужный диапазон. Если b меньше или равно a, то функция возвращает a, так как в этом случае диапазон некорректный
	if (b <= a) return a;
	unsigned int r = prng_next();
	int span = (b - a + 1);
	return a + (int)(r % (unsigned int)span);
}

void goals_init() { // Инициализация параметров целей, которые включают в себя накопления на путешествия, ремонт и образование, а также ежемесячные суммы, которые нужно откладывать на эти цели. Также инициализируется цель по накоплению определенной суммы для экстренных случаев и стоимость последнего события, которое произошло
	Goals.travel_fund = 0;
	Goals.repair_fund = 0;
	Goals.education_fund = 0;

	Goals.emergency_fund_target = 500'000;

	Goals.monthly_to_travel = 15'000;
	Goals.monthly_to_repair = 10'000;
	Goals.monthly_to_education = 8'000;

	Goals.last_event_cost = 0;
}

RUB bank_total_money(const Bank& b) { // Получение общей суммы денег в банке, которая включает в себя деньги на карте и деньги в депозите банка
	return b.card + b.deposit;
}

RUB person_total_money_everywhere(const Person& p) { // Получение общей суммы денег человека, которая включает в себя деньги на картах всех банков человека и деньги в депозитах всех банков человека
	return bank_total_money(p.Tbank) + bank_total_money(p.Sberbank) + bank_total_money(p.Alfabank) + bank_total_money(p.VTB);
}

Bank* person_best_deposit_bank(Person& p) { // Получение указателя на банк, который предлагает самый высокий процент по депозиту для человека. Эта функция сравнивает процент по депозиту в каждом банке человека и возвращает указатель на банк с самым высоким процентом. Если несколько банков предлагают одинаковый процент, то возвращается первый из них в порядке проверки
	double best = p.Tbank.deposit_apr;
	Bank* b = &p.Tbank;

	if (p.Sberbank.deposit_apr > best) { best = p.Sberbank.deposit_apr; b = &p.Sberbank; }
	if (p.Alfabank.deposit_apr > best) { best = p.Alfabank.deposit_apr; b = &p.Alfabank; }
	if (p.VTB.deposit_apr > best) { best = p.VTB.deposit_apr; b = &p.VTB; }

	return b;
}

void move_from_card_to_deposit(Bank& from_card, Bank& to_deposit, const RUB amount) { // Перевод денег с карты одного банка на депозит другого банка. Если сумма для перевода меньше или равна нулю, то перевод не выполняется. Если на карте банка, с которого нужно перевести деньги, достаточно денег для перевода, то перевод выполняется полностью. Иначе переводится вся сумма денег с карты банка, с которого нужно перевести деньги, и карта банка обнуляется
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

void goals_month_tick() { // Месячный тик для целей, который включает в себя перевод денег с карты банка, у которого меньше всего денег на карте, на депозит банка, у которого самый высокий процент по депозиту для каждой цели. Сначала определяется банк с самым высоким процентом по депозиту для каждой цели, а затем переводятся деньги с карты банка, у которого меньше всего денег на карте, на депозит этого банка для каждой цели. Если после перевода на карте банка, у которого меньше всего денег на карте, останется меньше или равно определенной суммы для экстренных случаев, то перевод не выполняется, так как нужно оставить деньги на карте для экстренных случаев
	Bank* best = person_best_deposit_bank(Alice);

	if (Alice.Tbank.card > 0) {
		RUB x = Goals.monthly_to_travel;
		if (x > Alice.Tbank.card) x = Alice.Tbank.card;
		Alice.Tbank.card -= x;
		best->deposit += x;
		Goals.travel_fund += x;
	}

	if (Alice.Tbank.card > 0) {
		RUB x = Goals.monthly_to_repair;
		if (x > Alice.Tbank.card) x = Alice.Tbank.card;
		Alice.Tbank.card -= x;
		best->deposit += x;
		Goals.repair_fund += x;
	}

	if (Alice.Tbank.card > 0) {
		RUB x = Goals.monthly_to_education;
		if (x > Alice.Tbank.card) x = Alice.Tbank.card;
		Alice.Tbank.card -= x;
		best->deposit += x;
		Goals.education_fund += x;
	}
}

RUB yearly_costs_tick(const int month, const int year) { // Годовой тик для оплаты ежегодных расходов, который включает в себя оплату налогов на имущество и страховки для общего жилья, а также оплату страховки для каждой машины. Эти расходы оплачиваются в определенные месяцы года, например, налоги на имущество оплачиваются в апреле, страховка для общего жилья оплачивается в октябре, а страховка для машин оплачивается в январе. Оплата этих расходов выполняется с помощью карт банков каждого человека и помощью от Алисы при необходимости. Функция возвращает общую сумму оплаченных расходов за год
	(void)year;

	RUB total = 0;

	if (month == 4) {
		RUB tax = SharedHome.bills.property_tax * 12;
		couple_pay_shared_bill_by_salary_with_help(tax, "property tax yearly (shared home)");
		total += tax;
	}

	if (month == 10) {
		RUB ins = SharedHome.bills.home_insurance * 12;
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

double season_multiplier_food(const int month) { // Получение сезонного множителя для расходов на еду в зависимости от месяца года. В зимние месяцы (декабрь, январь, февраль) расходы на еду увеличиваются на 10%, так как люди чаще готовят дома и покупают больше продуктов. В летние месяцы (июнь, июль, август) расходы на еду уменьшаются на 5%, так как люди чаще едят вне дома и покупают меньше продуктов. В остальные месяцы года сезонного множителя нет, и расходы на еду остаются без изменений
	if (month == 12 || month == 1 || month == 2) return 1.10;
	if (month == 6 || month == 7 || month == 8) return 0.95;
	return 1.00;
}

double season_multiplier_entertainment(const int month) { // Получение сезонного множителя для расходов на развлечения в зависимости от месяца года. В декабре расходы на развлечения увеличиваются на 30%, так как люди чаще покупают подарки, посещают мероприятия и отдыхают. В мае расходы на развлечения увеличиваются на 10%, так как люди начинают проводить больше времени на улице и участвовать в различных мероприятиях. В августе расходы на развлечения увеличиваются на 15%, так как люди часто ездят в отпуск и проводят время с семьей и друзьями. В остальные месяцы года сезонного множителя нет, и расходы на развлечения остаются без изменений
	if (month == 12) return 1.30;
	if (month == 5) return 1.10;
	if (month == 8) return 1.15;
	return 1.00;
}

void couple_season_tick(const int month) { // Сезонный тик для расходов на еду и развлечения, который включает в себя применение сезонных множителей к расходам на еду и развлечения для каждого человека в зависимости от месяца года. Эти множители увеличивают или уменьшают расходы на еду и развлечения в определенные месяцы года, например, расходы на еду увеличиваются в зимние месяцы и уменьшаются в летние месяцы, а расходы на развлечения увеличиваются в декабре, мае и августе. Функция изменяет значения расходов на еду и развлечения для каждого человека с учетом этих множителей
	double mF = season_multiplier_food(month);
	double mE = season_multiplier_entertainment(month);

	Alice.food = (RUB)(Alice.food * mF);
	David.food = (RUB)(David.food * mF);

	Alice.entertainment = (RUB)(Alice.entertainment * mE);
	David.entertainment = (RUB)(David.entertainment * mE);
}

RUB event_medical(Person& p, const char* who) { // Случайное медицинское событие, которое может произойти с определенным шансом для каждого человека. Если событие происходит, то генерируется случайная стоимость медицинских расходов, которая оплачивается с помощью карт банков человека и помощью от Алисы при необходимости. Функция возвращает стоимость медицинских расходов, если событие произошло, или 0, если событие не произошло
	int chance = prng_range(1, 100);
	if (chance <= 12) { 
		RUB cost = (RUB)prng_range(2'000, 25'000);
		pay_from_all_cards(p, cost, "random medical", who);
		return cost;
	}
	return 0;
}

RUB event_car_breakdown(Person& p, const char* who) { // Случайное событие поломки машины, которое может произойти с определенным шансом для каждого человека. Если событие происходит, то генерируется случайная стоимость ремонта машины, которая оплачивается с помощью карт банков человека и помощью от Алисы при необходимости. Также, если после оплаты ремонта машины ее стоимость ремонта меньше 1'000'000, то она увеличивается на 10% от стоимости ремонта, так как машина становится более изношенной. Функция возвращает стоимость ремонта машины, если событие произошло, или 0, если событие не произошло
	int chance = prng_range(1, 100);
	if (chance <= 10) {
		RUB cost = (RUB)prng_range(5'000, 60'000);
		pay_from_all_cards(p, cost, "random car breakdown", who);

		if (p.car.repair < 1'000'000) p.car.repair += (RUB)(cost / 10);

		return cost;
	}
	return 0;
}

RUB event_home_repair() { // Случайное событие поломки в общем жилье, которое может произойти с определенным шансом. Если событие происходит, то генерируется случайная стоимость ремонта, которая оплачивается с помощью карт банков каждого человека и помощью от Алисы при необходимости. Функция возвращает стоимость ремонта, если событие произошло, или 0, если событие не произошло
	int chance = prng_range(1, 100);
	if (chance <= 8) {
		RUB cost = (RUB)prng_range(7'000, 120'000);
		couple_pay_shared_bill_by_salary_with_help(cost, "random home repair");
		return cost;
	}
	return 0;
}

RUB event_salon_shock() { // Случайное событие, которое может произойти в салоне татуировки с определенным шансом. Если событие происходит, то генерируется случайная стоимость ущерба, которая оплачивается с помощью карты салона и помощью от Алисы при необходимости. Также, если после оплаты ущерба репутация салона больше 0, то она уменьшается на 1 пункт. Функция возвращает стоимость ущерба, если событие произошло, или 0, если событие не произошло
	int chance = prng_range(1, 100);
	if (chance <= 9) {
		int t = prng_range(1, 3);
		RUB cost = 0;

		if (t == 1) { cost = (RUB)prng_range(10'000, 50'000); }
		if (t == 2) { cost = (RUB)prng_range(8'000, 35'000); }
		if (t == 3) { cost = (RUB)prng_range(15'000, 70'000); }

		if (Salon.cash >= cost) {
			Salon.cash -= cost;
			Salon.month_expenses += cost;
		}
		else {
			RUB rest = cost - Salon.cash;
			Salon.month_expenses += Salon.cash;
			Salon.cash = 0;
			pay_from_all_cards(Alice, rest, "salon shock event", "Alice");
			Salon.month_expenses += rest;
		}

		if (Salon.reputation >= 1) Salon.reputation -= 1;
		return cost;
	}
	return 0;
}
 
RUB couple_random_events_tick() { // Месячный тик для случайных событий, который включает в себя проверку на случайные медицинские события для каждого человека, случайные поломки машины для каждого человека, случайные поломки в общем жилье и случайные события в салоне татуировки. Если какое-то из этих событий происходит, то генерируется случайная стоимость ущерба или расходов, которая оплачивается с помощью карт банков каждого человека и помощью от Алисы при необходимости. Также, если событие происходит в салоне татуировки, то репутация салона может уменьшаться. Функция возвращает общую сумму ущерба или расходов за месяц от всех произошедших событий
	RUB total = 0;

	total += event_medical(Alice, "Alice");
	total += event_medical(David, "David");

	total += event_car_breakdown(Alice, "Alice");
	total += event_car_breakdown(David, "David");

	total += event_home_repair();

	total += event_salon_shock();

	Goals.last_event_cost = total;
	return total;
}

void salon_try_upgrade() { // Попытка улучшить салон татуировки, которая может быть выполнена, если репутация салона больше или равна 75 и наличные салона больше или равны определенной суммы. Если эти условия выполняются, то с карты салона списывается определенная сумма денег, которая добавляется к стоимости оборудования салона. Также, если износ оборудования салона больше или равен 5, то он уменьшается на 5. После улучшения оборудования, цены на услуги салона увеличиваются на определенные суммы, а количество клиентов малого размера увеличивается на 1
	if (Salon.reputation < 75) return;

	const RUB need = 250'000;
	if (Salon.cash < need) return;

	Salon.cash -= need;
	Salon.equipment_value += need;
	if (Salon.equipment_wear >= 5) Salon.equipment_wear -= 5;

	Salon.price_small += 500;
	Salon.price_medium += 900;
	Salon.price_large += 1'200;

	Salon.clients_small += 1;
}

RUB couple_total_net_worth() { // Получение общей чистой стоимости пары, которая включает в себя общую сумму наличных денег каждого человека, общую стоимость всех вещей каждого человека, стоимость общего жилья и оборудования салона татуировки, а также вычет долгов по кредитам каждого человека и долга по ипотеке общего жилья. Эта функция позволяет оценить финансовое состояние пары с учетом всех их активов и обязательств
	RUB total_cash = person_total_cash(Alice) + person_total_cash(David) + Salon.cash;
	RUB total_assets = person_total_assets(Alice) + person_total_assets(David) + SharedHome.value + SharedHome.furniture + Salon.equipment_value;
	RUB total_debts = person_total_credits(Alice) + person_total_credits(David) + SharedHome.mortgage_debt;
	return (total_cash + total_assets) - total_debts;
}

void monthlog_add(const int month, const int year, const RUB events_cost, const RUB yearly_costs) { // Добавление нового лога за месяц в массив логов. Этот лог содержит информацию о месяце и годе, общей чистой стоимости пары, наличных деньгах каждого человека и салона, кредитах каждого человека, долге по ипотеке общего жилья, а также стоимости событий и ежегодных расходов за этот месяц. Если количество логов уже достигло 24, то новый лог не добавляется, так как массив может хранить только 24 лога
	if (LogsCount >= 24) return;

	Logs[LogsCount].month = month;
	Logs[LogsCount].year = year;

	Logs[LogsCount].alice_cash = person_total_cash(Alice);
	Logs[LogsCount].david_cash = person_total_cash(David);
	Logs[LogsCount].salon_cash = Salon.cash;

	Logs[LogsCount].alice_credits = person_total_credits(Alice);
	Logs[LogsCount].david_credits = person_total_credits(David);
	Logs[LogsCount].mortgage_debt = SharedHome.mortgage_debt;

	Logs[LogsCount].total_net_worth = couple_total_net_worth();

	Logs[LogsCount].events_cost = events_cost;
	Logs[LogsCount].yearly_costs = yearly_costs;

	LogsCount++;
}

void print_month_logs() { // Вывод логов за каждый месяц
	printf("========== Month Logs ==========\n");
	for (int i = 0; i < LogsCount; ++i) {
		printf("[%02d.%d] NetWorth=%lld | AliceCash=%lld DavidCash=%lld SalonCash=%lld | Credits(A/D)=%lld/%lld | Mortgage=%lld | Events=%lld | Yearly=%lld\n",
			Logs[i].month, Logs[i].year,
			Logs[i].total_net_worth,
			Logs[i].alice_cash, Logs[i].david_cash, Logs[i].salon_cash,
			Logs[i].alice_credits, Logs[i].david_credits,
			Logs[i].mortgage_debt,
			Logs[i].events_cost,
			Logs[i].yearly_costs
		);
	}
	printf("\n");
}

void person_more_items_repair(Person& p, const char* who) { // Попытка отремонтировать или заменить вещи человека
	try_repair_or_replace_item(p, p.items.fridge, "fridge", who);
	try_repair_or_replace_item(p, p.items.microwave, "microwave", who);
	try_repair_or_replace_item(p, p.items.coffee_machine, "coffee machine", who);
	try_repair_or_replace_item(p, p.items.blender, "blender", who);

	try_repair_or_replace_item(p, p.items.pc, "pc", who);
	try_repair_or_replace_item(p, p.items.monitor, "monitor", who);
	try_repair_or_replace_item(p, p.items.keyboard, "keyboard", who);
	try_repair_or_replace_item(p, p.items.mouse, "mouse", who);
	try_repair_or_replace_item(p, p.items.chair, "chair", who);

	try_repair_or_replace_item(p, p.items.skates, "skates", who);
}

void person_more_items_service(Person& p, const char* who) { // Оплата сервисов для вещей человека
	RUB cloud = 350;
	RUB antivirus = 220;
	RUB music = 279;

	pay_from_all_cards(p, cloud, "cloud storage", who);
	pay_from_all_cards(p, antivirus, "antivirus", who);
	pay_from_all_cards(p, music, "music subscription", who);
}

void couple_season_special_expenses(const int month) { // Сезонный тик для специальных расходов
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

void extension_init() { // Инициализация расширения, которая включает в себя инициализацию параметров целей, а также установку начального значения для генератора псевдослучайных чисел
	goals_init();
	g_seed = 123456789u;
}
 
void extension_month_tick(const int month, const int year) { // Месячный тик для расширения, который включает в себя выполнение сезонного тика для расходов на еду и развлечения, выполнение тика для банков, выполнение сезонного тика для специальных расходов, выполнение тика для случайных событий, попытку улучшить салон татуировки, выполнение тика для целей и добавление нового лога за месяц в массив логов.
	couple_season_tick(month);

	couple_season_special_expenses(month);

	RUB events_cost = couple_random_events_tick();

	RUB yearly_costs = yearly_costs_tick(month, year);

	person_more_items_service(Alice, "Alice");
	person_more_items_service(David, "David");

	person_more_items_repair(Alice, "Alice");
	person_more_items_repair(David, "David");

	salon_try_upgrade();

	goals_month_tick();

	monthlog_add(month, year, events_cost, yearly_costs);
}

void print_item(const Item& it, const char* name) { // Вывод информации о вещи человека, которая включает в себя ее стоимость, износ, стоимость ремонта, стоимость замены и стоимость сервисов для этой вещи
	printf("%s: value=%lld wear=%lld repair=%lld replace=%lld service=%lld\n", name, it.value, it.wear, it.repair_cost, it.replace_cost, it.service_cost);
}

void print_home() { // Вывод информации о общем жилье, которая включает в себя его стоимость, стоимость мебели, долг по ипотеке, процент по ипотеке, ежемесячный платеж по ипотеке, а также стоимость всех счетов за жилье
	printf("========== Shared Home ==========\n");
	printf("Home value = %lld\n", SharedHome.value);
	printf("Furniture = %lld\n", SharedHome.furniture);

	printf("Mortgage debt = %lld\n", SharedHome.mortgage_debt);
	printf("Mortgage rate = %.2f\n", SharedHome.mortgage_rate);
	printf("Mortgage payment = %lld\n", SharedHome.mortgage_payment);

	printf("Bills:\n");
	printf("Electricity = %lld\n", SharedHome.bills.electricity);
	printf("Water = %lld\n", SharedHome.bills.water);
	printf("Gas = %lld\n", SharedHome.bills.gas);
	printf("Heating = %lld\n", SharedHome.bills.heating);

	printf("Trash = %lld\n", SharedHome.bills.trash);
	printf("Intercom = %lld\n", SharedHome.bills.intercom);

	printf("Internet = %lld\n", SharedHome.bills.internet);
	printf("TV = %lld\n", SharedHome.bills.tv);
	printf("Mobile = %lld\n", SharedHome.bills.mobile);

	printf("Home insurance = %lld\n", SharedHome.bills.home_insurance);
	printf("Property tax = %lld\n", SharedHome.bills.property_tax);

	printf("Repairs fund = %lld\n", SharedHome.bills.repairs_fund);
	printf("Cleaning = %lld\n", SharedHome.bills.cleaning);

	printf("\n");
}

void print_person(const Person& p, const char* name) { // Вывод информации о человеке
	printf("========== %s ==========\n", name);

	printf("Salary(Tbank) = %lld\n", p.Tbank.salary);

	printf("Tbank: card=%lld deposit=%lld credit=%lld limit=%lld\n", p.Tbank.card, p.Tbank.deposit, p.Tbank.credit_debt, p.Tbank.credit_limit);
	printf("Sber:  card=%lld deposit=%lld credit=%lld limit=%lld\n", p.Sberbank.card, p.Sberbank.deposit, p.Sberbank.credit_debt, p.Sberbank.credit_limit);
	printf("Alfa:  card=%lld deposit=%lld credit=%lld limit=%lld\n", p.Alfabank.card, p.Alfabank.deposit, p.Alfabank.credit_debt, p.Alfabank.credit_limit);
	printf("VTB:   card=%lld deposit=%lld credit=%lld limit=%lld\n", p.VTB.card, p.VTB.deposit, p.VTB.credit_debt, p.VTB.credit_limit);

	printf("Cash total = %lld\n", person_total_cash(p));
	printf("Credits total = %lld\n", person_total_credits(p));
	printf("Assets total = %lld\n", person_total_assets(p));

	printf("Food = %lld\n", p.food);
	printf("Clothes = %lld\n", p.clothes);
	printf("Entertainment = %lld\n", p.entertainment);
	printf("Medicine = %lld\n", p.medicine);
	printf("Education = %lld\n", p.education);
	printf("Subscriptions = %lld\n", p.subscriptions);

	printf("Transport = %lld\n", p.transport);
	printf("Gifts = %lld\n", p.gifts);
	printf("Cafe = %lld\n", p.cafe);

	printf("Hygiene = %lld\n", p.hygiene);
	printf("Cosmetics = %lld\n", p.cosmetics);
	printf("Games = %lld\n", p.games);

	printf("Car value = %lld\n", p.car.value);
	printf("Gas = %lld\n", p.car.gas);
	printf("Insurance = %lld\n", p.car.insurance);
	printf("Tax = %lld\n", p.car.tax);
	printf("Repair = %lld\n", p.car.repair);
	printf("Parking = %lld\n", p.car.parking);
	printf("Wash = %lld\n", p.car.wash);
	printf("Tires = %lld\n", p.car.tires);
	printf("Service = %lld\n", p.car.service);

	printf("Cat value = %lld\n", p.cat.value);
	printf("Cat food = %lld\n", p.cat.food);

	printf("Items:\n");
	print_item(p.items.phone, "Phone");
	print_item(p.items.laptop, "Laptop");
	print_item(p.items.headphones, "Headphones");
	print_item(p.items.smartwatch, "Smartwatch");

	print_item(p.items.pc, "PC");
	print_item(p.items.monitor, "Monitor");
	print_item(p.items.keyboard, "Keyboard");
	print_item(p.items.mouse, "Mouse");
	print_item(p.items.chair, "Chair");

	print_item(p.items.console, "Console");
	print_item(p.items.tv, "TV");

	print_item(p.items.fridge, "Fridge");
	print_item(p.items.microwave, "Microwave");
	print_item(p.items.washing_machine, "Washing machine");
	print_item(p.items.vacuum, "Vacuum");
	print_item(p.items.coffee_machine, "Coffee machine");
	print_item(p.items.blender, "Blender");

	print_item(p.items.bed, "Bed");
	print_item(p.items.sofa, "Sofa");
	print_item(p.items.table, "Table");

	print_item(p.items.skates, "Skates");
	print_item(p.items.gym_membership, "Gym membership");
	print_item(p.items.bike, "Bike");
	print_item(p.items.camera, "Camera");

	print_item(p.items.toolbox, "Toolbox");

	printf("\n");
}

void print_results() { // Вывод итогов симуляции
	print_home();
	print_salon();

	print_person(Alice, "Alice");
	print_person(David, "David");

	RUB total_cash = person_total_cash(Alice) + person_total_cash(David) + Salon.cash;
	RUB total_assets = person_total_assets(Alice) + person_total_assets(David) + SharedHome.value + SharedHome.furniture + Salon.equipment_value;
	RUB total_debts = person_total_credits(Alice) + person_total_credits(David) + SharedHome.mortgage_debt;

	printf("========== Total Couple ==========\n");
	printf("Total cash (with salon) = %lld\n", total_cash);
	printf("Total assets (cash+property+salon) = %lld\n", total_cash + total_assets);
	printf("Total debts (credits+mortgage) = %lld\n", total_debts);
	printf("Net worth (assets - debts) = %lld\n", (total_cash + total_assets) - total_debts);

	print_month_logs();
}

void couple_init() { // Инициализация всех параметров для симуляции
	home_init();
	alice_init();
	david_init();
	salon_init();
	extension_init();
}

void simulation() { // Основная функция симуляции
	int month = 2;
	int year = 2026;

	while (!((month == 3) && (year == 2027))) {

		couple_inflation_tick();

		mortgage_interest_tick();

		person_items_wear_tick(Alice);
		person_items_wear_tick(David);

		alice_salary(month, year);
		david_salary(month, year);

		salon_month_tick();

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

		alice_pay_food();
		david_pay_food();

		alice_pay_gas();
		david_pay_gas();

		alice_pay_cat_food();

		alice_pay_clothes();
		david_pay_clothes();

		alice_pay_entertainment();
		david_pay_entertainment();

		alice_pay_medicine();
		david_pay_medicine();

		alice_pay_education();
		david_pay_education();

		alice_pay_subscriptions();
		david_pay_subscriptions();

		alice_pay_transport();
		david_pay_transport();

		alice_pay_gifts();
		david_pay_gifts();

		alice_pay_cafe();
		david_pay_cafe();

		alice_pay_hygiene();
		david_pay_hygiene();

		alice_pay_cosmetics();
		david_pay_cosmetics();

		alice_pay_games();
		david_pay_games();

		alice_pay_car_insurance();
		david_pay_car_insurance();

		alice_pay_car_tax();
		david_pay_car_tax();

		alice_pay_car_repair();
		david_pay_car_repair();

		alice_pay_parking();
		david_pay_parking();

		alice_pay_car_wash();
		david_pay_car_wash();

		alice_pay_tires();
		david_pay_tires();

		alice_pay_car_service();
		david_pay_car_service();

		person_items_service_pay(Alice, "Alice");
		person_items_service_pay(David, "David");

		person_items_repair_or_replace(Alice, "Alice");
		person_items_repair_or_replace(David, "David");

		alice_move_money_to_deposit();
		david_move_money_to_deposit();

		extension_month_tick(month, year);

		++month;
		if (month == 13) {
			month = 1;
			++year;
		}
	}
}

int main() { // Главная функция
	couple_init();
	simulation();
	print_results();
}