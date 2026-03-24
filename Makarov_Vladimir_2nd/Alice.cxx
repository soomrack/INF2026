#include <stdio.h>

using Percent = float;
using RUB = long long int;
using USD = long long int;
using Time = int;

struct Car {
	RUB value;
	RUB gas;
	RUB maintenance; // ТО
	RUB parking;
	RUB tire_change; // Резина
	RUB insurance; // Страховка
	RUB tax; // Налог на авто
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
};

struct Mortgage { // Ипотека
	RUB debt;
	int months_total;
	int months_paid; // Месяцев оплачено
	RUB payment;
	RUB remainder; // Остаток
	Percent rate;
};

struct Food 
{
	RUB rice;
	RUB buckwheat; // Греча
	RUB oatmeal; // Овсянка
	RUB potatoes;
	RUB carrots;
	RUB onion;
	RUB garlic;
	RUB cabbage;
	RUB tomatoes;
	RUB cucumbers;
	RUB apples;
	RUB bananas;
	RUB chicken_breast;
	RUB pork; // Свинина
	RUB beef;
	RUB cheese;
	RUB tvorog;
	RUB butter;
	RUB eggs;
	RUB milk;
	RUB vegetable_oil;
	RUB tea;
	RUB coffee;
	RUB salt;
	RUB pepper;
	RUB sugar;
	RUB flour;
	RUB pasta;
	RUB canned_food; // Консервы
	RUB fish;
	RUB sausage;
	RUB bread;
	RUB juice;
	RUB water;
	RUB honey;
	RUB nuts;
	RUB dried_fruits;
};

struct Household { // Быт
	RUB washing_powder; // Стиральный порошок
	RUB toilet_paper;
	RUB toothpaste;
	RUB toothbrush;
	RUB deodorant;
	RUB shower_gel;
	RUB shampoo;
	RUB razor; // Бритва
	RUB dish_soap; // Средство для посуды
	RUB trash_bags;
	RUB paper_towels;
	RUB laundry_softener; // Кондиционер для белья
	RUB cleaning_spray;
	RUB sponge; // Губка
	RUB batteries;
	RUB foil; // Фольга
	RUB cling_film; // Пищевая пленка
};

struct Utilities {
	RUB electricity;
	RUB water_cold;
	RUB water_hot;
	RUB heating; // Отопление
	RUB capital_repair;
	RUB garbage; // Вывоз мусора
	RUB internet;
	RUB intercom; // Домофон
	RUB gas_supply;
	RUB sewer; // Водоотведение
	RUB tv;
};

struct Health {
	RUB fitness;
	RUB massage;
	RUB medicines;
	RUB dentist;
	RUB vitamins;
	RUB omega3;
	RUB vitamin_d;
	RUB magnesium;
	RUB zinc;
	RUB iron;
	RUB calcium;
	RUB collagen;
	RUB probiotics;
	RUB eye_drops;
	RUB cream;
};

struct Lifestyle {
	RUB cinema;
	RUB restaurant;
	RUB bar;
	RUB billiards;
	RUB bowling;
	RUB theater;
	RUB quest;
	RUB concert;
	RUB museum;
	RUB hookah; // Кальян
	RUB ice_skating;
	RUB skiing;
};

struct Shopping {
	RUB clothes;
	RUB shoes;
	RUB accessories;
	RUB electronics;
	RUB cosmetics;
	RUB tools;
	RUB home_goods;
	RUB sport_equipment;
	RUB backpack;
	RUB watch;
	RUB perfume;
};

struct Development {
	RUB yandex_plus;
	RUB t2;
	RUB youtube_premium;
	RUB books;
	RUB courses;
	RUB english;
	RUB programming;
	RUB audiobooks;
};

struct Pets {
	RUB cat_food;
	RUB cat_litter; // Наполнитель
	RUB cat_vet;
	RUB cat_toys;
	RUB dog_food;
	RUB dog_vet;
	RUB dog_toys;
	RUB dog_walker;
	RUB pet_insurance; // Страховка
};

struct Vacation {
	RUB summer_trip;
	RUB winter_trip;
	RUB weekend_trips;
	RUB visa;
	RUB insurance;
	RUB equipment;
	RUB souvenirs;
};

struct Deposit { // Вклад
	RUB amount; // Сумма на вкладе
	RUB total_deposited; // Всего внесено
	Percent rate;
	int active;
};

struct Person {
	Bank bank;
	RUB salary;
	RUB fun;
	RUB total_savings;
	RUB total_investment_usd;
	Car car;
	Credit credit;
	Mortgage mortgage;
	Food food_stock;
	Household household;
	Utilities utils; // Коммуналка
	Health health;
	Lifestyle lifestyle;
	Shopping shopping;
	Development development;
	Pets pets;
	Vacation vacation; // Отпуск
	Deposit deposit;
	float inflation_rate;
	int has_mortgage;
	int has_credit;
	RUB haircut;
	RUB coffee_takeaway;
	RUB lunch_work;
	RUB parking_cost;
	RUB gifts;
	RUB psychologist;
	RUB manicure;
	RUB cosmetologist;
	RUB taxi;
	RUB cigarettes; // Сигареты
	RUB charity; // Благотворительность
};

struct Person alice;

struct Person den;

void alice_init()
{
	alice.bank.rate_usd_rub = 78.76;
	alice.bank.account_rub = 0;
	alice.bank.account_usd = 1000;
	alice.salary = 150000;
	alice.fun = 8000;
	alice.total_savings = 0;
	alice.total_investment_usd = 0;
	alice.inflation_rate = 0.008;
	alice.has_mortgage = 0;
	alice.has_credit = 1;
	alice.car.value = 1800000;
	alice.car.gas = 10000;
	alice.car.maintenance = 10000;
	alice.car.parking = 3000;
	alice.car.tire_change = 12000;
	alice.car.insurance = 8000;
	alice.car.tax = 2500;
	alice.credit.debt = 3000000;
	alice.credit.payment = 40000;
	alice.credit.month = (alice.credit.debt / alice.credit.payment);
	alice.credit.rate = 14.5;
	alice.mortgage.debt = 0;
	alice.mortgage.payment = 0;
	alice.food_stock.rice = 500;
	alice.food_stock.buckwheat = 500;
	alice.food_stock.oatmeal = 400;
	alice.food_stock.potatoes = 300;
	alice.food_stock.carrots = 250;
	alice.food_stock.onion = 200;
	alice.food_stock.garlic = 100;
	alice.food_stock.cabbage = 200;
	alice.food_stock.tomatoes = 400;
	alice.food_stock.cucumbers = 350;
	alice.food_stock.apples = 500;
	alice.food_stock.bananas = 400;
	alice.food_stock.chicken_breast = 600;
	alice.food_stock.pork = 400;
	alice.food_stock.beef = 500;
	alice.food_stock.cheese = 600;
	alice.food_stock.tvorog = 500;
	alice.food_stock.butter = 400;
	alice.food_stock.eggs = 800;
	alice.food_stock.milk = 1000;
	alice.food_stock.vegetable_oil = 250;
	alice.food_stock.tea = 300;
	alice.food_stock.coffee = 500;
	alice.food_stock.salt = 50;
	alice.food_stock.pepper = 80;
	alice.food_stock.sugar = 100;
	alice.food_stock.flour = 80;
	alice.food_stock.pasta = 200;
	alice.food_stock.canned_food = 300;
	alice.food_stock.fish = 800;
	alice.food_stock.sausage = 400;
	alice.food_stock.bread = 200;
	alice.food_stock.juice = 300;
	alice.food_stock.water = 400;
	alice.food_stock.honey = 300;
	alice.food_stock.nuts = 400;
	alice.food_stock.dried_fruits = 350;
	alice.household.washing_powder = 600;
	alice.household.toilet_paper = 400;
	alice.household.toothpaste = 200;
	alice.household.toothbrush = 150;
	alice.household.deodorant = 250;
	alice.household.shower_gel = 350;
	alice.household.shampoo = 400;
	alice.household.razor = 500;
	alice.household.dish_soap = 150;
	alice.household.trash_bags = 100;
	alice.household.paper_towels = 200;
	alice.household.laundry_softener = 250;
	alice.household.cleaning_spray = 180;
	alice.household.sponge = 80;
	alice.household.batteries = 200;
	alice.household.foil = 100;
	alice.household.cling_film = 80;
	alice.utils.electricity = 1200;
	alice.utils.water_cold = 400;
	alice.utils.water_hot = 600;
	alice.utils.heating = 0;
	alice.utils.capital_repair = 500;
	alice.utils.garbage = 250;
	alice.utils.internet = 500;
	alice.utils.intercom = 150;
	alice.utils.gas_supply = 300;
	alice.utils.sewer = 200;
	alice.utils.tv = 250;
	alice.health.fitness = 4000;
	alice.health.massage = 2000;
	alice.health.medicines = 800;
	alice.health.dentist = 0;
	alice.health.vitamins = 1500;
	alice.health.omega3 = 800;
	alice.health.vitamin_d = 500;
	alice.health.magnesium = 600;
	alice.health.zinc = 400;
	alice.health.iron = 300;
	alice.health.calcium = 500;
	alice.health.collagen = 1200;
	alice.health.probiotics = 700;
	alice.health.eye_drops = 200;
	alice.health.cream = 500;
	alice.lifestyle.cinema = 0;
	alice.lifestyle.restaurant = 0;
	alice.lifestyle.bar = 0;
	alice.lifestyle.billiards = 0;
	alice.lifestyle.bowling = 0;
	alice.lifestyle.theater = 0;
	alice.lifestyle.quest = 0;
	alice.lifestyle.concert = 0;
	alice.lifestyle.museum = 0;
	alice.lifestyle.hookah = 0;
	alice.lifestyle.ice_skating = 0;
	alice.lifestyle.skiing = 0;
	alice.shopping.clothes = 8000;
	alice.shopping.shoes = 6000;
	alice.shopping.accessories = 3000;
	alice.shopping.electronics = 0;
	alice.shopping.cosmetics = 5000;
	alice.shopping.tools = 0;
	alice.shopping.home_goods = 2000;
	alice.shopping.sport_equipment = 0;
	alice.shopping.backpack = 0;
	alice.shopping.watch = 0;
	alice.shopping.perfume = 0;
	alice.development.yandex_plus = 350;
	alice.development.t2 = 300;
	alice.development.youtube_premium = 500;
	alice.development.books = 1500;
	alice.development.courses = 0;
	alice.development.english = 0;
	alice.development.programming = 0;
	alice.development.audiobooks = 300;
	alice.pets.cat_food = 2000;
	alice.pets.cat_litter = 800;
	alice.pets.cat_vet = 0;
	alice.pets.cat_toys = 300;
	alice.pets.dog_food = 0;
	alice.pets.dog_vet = 0;
	alice.pets.dog_toys = 0;
	alice.pets.dog_walker = 0;
	alice.pets.pet_insurance = 0;
	alice.vacation.summer_trip = 0;
	alice.vacation.winter_trip = 0;
	alice.vacation.weekend_trips = 0;
	alice.vacation.visa = 0;
	alice.vacation.insurance = 0;
	alice.vacation.equipment = 0;
	alice.vacation.souvenirs = 0;
	alice.deposit.amount = 0;
	alice.deposit.total_deposited = 0;
	alice.deposit.rate = 0.12;
	alice.deposit.active = 1;
	alice.haircut = 1250;
	alice.coffee_takeaway = 5000;
	alice.lunch_work = 6000;
	alice.parking_cost = 3000;
	alice.gifts = 0;
	alice.psychologist = 3000;
	alice.manicure = 3000;
	alice.cosmetologist = 2000;
	alice.taxi = 3000;
	alice.cigarettes = 0;
	alice.charity = 1000;
}

void alice_inflation_after()
{
	alice.inflation_rate = 0.008;
	alice.food_stock.rice = alice.food_stock.rice * (1 + alice.inflation_rate);
	alice.food_stock.buckwheat = alice.food_stock.buckwheat * (1 + alice.inflation_rate);
	alice.food_stock.oatmeal = alice.food_stock.oatmeal * (1 + alice.inflation_rate);
	alice.food_stock.potatoes = alice.food_stock.potatoes * (1 + alice.inflation_rate);
	alice.food_stock.carrots = alice.food_stock.carrots * (1 + alice.inflation_rate);
	alice.food_stock.onion = alice.food_stock.onion * (1 + alice.inflation_rate);
	alice.food_stock.garlic = alice.food_stock.garlic * (1 + alice.inflation_rate);
	alice.food_stock.cabbage = alice.food_stock.cabbage * (1 + alice.inflation_rate);
	alice.food_stock.tomatoes = alice.food_stock.tomatoes * (1 + alice.inflation_rate);
	alice.food_stock.cucumbers = alice.food_stock.cucumbers * (1 + alice.inflation_rate);
	alice.food_stock.apples = alice.food_stock.apples * (1 + alice.inflation_rate);
	alice.food_stock.bananas = alice.food_stock.bananas * (1 + alice.inflation_rate);
	alice.food_stock.chicken_breast = alice.food_stock.chicken_breast * (1 + alice.inflation_rate);
	alice.food_stock.pork = alice.food_stock.pork * (1 + alice.inflation_rate);
	alice.food_stock.beef = alice.food_stock.beef * (1 + alice.inflation_rate);
	alice.food_stock.cheese = alice.food_stock.cheese * (1 + alice.inflation_rate);
	alice.food_stock.tvorog = alice.food_stock.tvorog * (1 + alice.inflation_rate);
	alice.food_stock.butter = alice.food_stock.butter * (1 + alice.inflation_rate);
	alice.food_stock.eggs = alice.food_stock.eggs * (1 + alice.inflation_rate);
	alice.food_stock.milk = alice.food_stock.milk * (1 + alice.inflation_rate);
	alice.food_stock.vegetable_oil = alice.food_stock.vegetable_oil * (1 + alice.inflation_rate);
	alice.food_stock.tea = alice.food_stock.tea * (1 + alice.inflation_rate);
	alice.food_stock.coffee = alice.food_stock.coffee * (1 + alice.inflation_rate);
	alice.food_stock.salt = alice.food_stock.salt * (1 + alice.inflation_rate);
	alice.food_stock.pepper = alice.food_stock.pepper * (1 + alice.inflation_rate);
	alice.food_stock.sugar = alice.food_stock.sugar * (1 + alice.inflation_rate);
	alice.food_stock.flour = alice.food_stock.flour * (1 + alice.inflation_rate);
	alice.food_stock.pasta = alice.food_stock.pasta * (1 + alice.inflation_rate);
	alice.food_stock.canned_food = alice.food_stock.canned_food * (1 + alice.inflation_rate);
	alice.food_stock.fish = alice.food_stock.fish * (1 + alice.inflation_rate);
	alice.food_stock.sausage = alice.food_stock.sausage * (1 + alice.inflation_rate);
	alice.food_stock.bread = alice.food_stock.bread * (1 + alice.inflation_rate);
	alice.food_stock.juice = alice.food_stock.juice * (1 + alice.inflation_rate);
	alice.food_stock.water = alice.food_stock.water * (1 + alice.inflation_rate);
	alice.food_stock.honey = alice.food_stock.honey * (1 + alice.inflation_rate);
	alice.food_stock.nuts = alice.food_stock.nuts * (1 + alice.inflation_rate);
	alice.food_stock.dried_fruits = alice.food_stock.dried_fruits * (1 + alice.inflation_rate);
	alice.household.washing_powder = alice.household.washing_powder * (1 + alice.inflation_rate);
	alice.household.toilet_paper = alice.household.toilet_paper * (1 + alice.inflation_rate);
	alice.household.toothpaste = alice.household.toothpaste * (1 + alice.inflation_rate);
	alice.household.toothbrush = alice.household.toothbrush * (1 + alice.inflation_rate);
	alice.household.deodorant = alice.household.deodorant * (1 + alice.inflation_rate);
	alice.household.shower_gel = alice.household.shower_gel * (1 + alice.inflation_rate);
	alice.household.shampoo = alice.household.shampoo * (1 + alice.inflation_rate);
	alice.household.razor = alice.household.razor * (1 + alice.inflation_rate);
	alice.household.dish_soap = alice.household.dish_soap * (1 + alice.inflation_rate);
	alice.household.trash_bags = alice.household.trash_bags * (1 + alice.inflation_rate);
	alice.household.paper_towels = alice.household.paper_towels * (1 + alice.inflation_rate);
	alice.household.laundry_softener = alice.household.laundry_softener * (1 + alice.inflation_rate);
	alice.household.cleaning_spray = alice.household.cleaning_spray * (1 + alice.inflation_rate);
	alice.household.sponge = alice.household.sponge * (1 + alice.inflation_rate);
	alice.household.batteries = alice.household.batteries * (1 + alice.inflation_rate);
	alice.household.foil = alice.household.foil * (1 + alice.inflation_rate);
	alice.household.cling_film = alice.household.cling_film * (1 + alice.inflation_rate);
	alice.utils.electricity = alice.utils.electricity * (1 + alice.inflation_rate);
	alice.utils.water_cold = alice.utils.water_cold * (1 + alice.inflation_rate);
	alice.utils.water_hot = alice.utils.water_hot * (1 + alice.inflation_rate);
	alice.utils.capital_repair = alice.utils.capital_repair * (1 + alice.inflation_rate);
	alice.utils.garbage = alice.utils.garbage * (1 + alice.inflation_rate);
	alice.utils.internet = alice.utils.internet * (1 + alice.inflation_rate);
	alice.utils.intercom = alice.utils.intercom * (1 + alice.inflation_rate);
	alice.utils.gas_supply = alice.utils.gas_supply * (1 + alice.inflation_rate);
	alice.utils.sewer = alice.utils.sewer * (1 + alice.inflation_rate);
	alice.utils.tv = alice.utils.tv * (1 + alice.inflation_rate);
	alice.health.medicines = alice.health.medicines * (1 + alice.inflation_rate);
	alice.health.vitamins = alice.health.vitamins * (1 + alice.inflation_rate);
	alice.health.omega3 = alice.health.omega3 * (1 + alice.inflation_rate);
	alice.health.vitamin_d = alice.health.vitamin_d * (1 + alice.inflation_rate);
	alice.health.magnesium = alice.health.magnesium * (1 + alice.inflation_rate);
	alice.health.zinc = alice.health.zinc * (1 + alice.inflation_rate);
	alice.health.iron = alice.health.iron * (1 + alice.inflation_rate);
	alice.health.calcium = alice.health.calcium * (1 + alice.inflation_rate);
	alice.health.collagen = alice.health.collagen * (1 + alice.inflation_rate);
	alice.health.probiotics = alice.health.probiotics * (1 + alice.inflation_rate);
	alice.health.eye_drops = alice.health.eye_drops * (1 + alice.inflation_rate);
	alice.health.cream = alice.health.cream * (1 + alice.inflation_rate);
	alice.haircut = alice.haircut * (1 + alice.inflation_rate);
	alice.coffee_takeaway = alice.coffee_takeaway * (1 + alice.inflation_rate);
	alice.lunch_work = alice.lunch_work * (1 + alice.inflation_rate);
	alice.psychologist = alice.psychologist * (1 + alice.inflation_rate);
	alice.manicure = alice.manicure * (1 + alice.inflation_rate);
	alice.cosmetologist = alice.cosmetologist * (1 + alice.inflation_rate);
	alice.taxi = alice.taxi * (1 + alice.inflation_rate);
	alice.charity = alice.charity * (1 + alice.inflation_rate);
}

void alice_utilities_jan()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
	alice.bank.account_rub -= alice.utils.heating;
}

void alice_utilities_feb()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
	alice.bank.account_rub -= alice.utils.heating;
}

void alice_utilities_mar()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
	alice.bank.account_rub -= alice.utils.heating;
}

void alice_utilities_apr()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
}

void alice_utilities_may()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
}

void alice_utilities_jun()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
}

void alice_utilities_jul()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
}

void alice_utilities_aug()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
}

void alice_utilities_sep()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
}

void alice_utilities_oct()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
	alice.bank.account_rub -= alice.utils.heating;
}

void alice_utilities_nov()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
	alice.bank.account_rub -= alice.utils.heating;
}

void alice_utilities_dec()
{
	alice.bank.account_rub -= alice.utils.electricity;
	alice.bank.account_rub -= alice.utils.water_cold;
	alice.bank.account_rub -= alice.utils.water_hot;
	alice.bank.account_rub -= alice.utils.capital_repair;
	alice.bank.account_rub -= alice.utils.garbage;
	alice.bank.account_rub -= alice.utils.internet;
	alice.bank.account_rub -= alice.utils.intercom;
	alice.bank.account_rub -= alice.utils.gas_supply;
	alice.bank.account_rub -= alice.utils.sewer;
	alice.bank.account_rub -= alice.utils.tv;
	alice.bank.account_rub -= alice.utils.heating;
}

void alice_food_rice() { // Еда Алисы
	alice.bank.account_rub -= alice.food_stock.rice; 
}
void alice_food_buckwheat() {
	alice.bank.account_rub -= alice.food_stock.buckwheat;
}
void alice_food_oatmeal() {
	alice.bank.account_rub -= alice.food_stock.oatmeal;
}
void alice_food_potatoes() {
	alice.bank.account_rub -= alice.food_stock.potatoes;
}
void alice_food_carrots() {
	alice.bank.account_rub -= alice.food_stock.carrots;
}
void alice_food_onion() {
	alice.bank.account_rub -= alice.food_stock.onion;
}
void alice_food_garlic() {
	alice.bank.account_rub -= alice.food_stock.garlic;
}
void alice_food_cabbage() {
	alice.bank.account_rub -= alice.food_stock.cabbage;
}
void alice_food_tomatoes() {
	alice.bank.account_rub -= alice.food_stock.tomatoes;
}
void alice_food_cucumbers() {
	alice.bank.account_rub -= alice.food_stock.cucumbers;
}
void alice_food_apples() {
	alice.bank.account_rub -= alice.food_stock.apples;
}
void alice_food_bananas() {
	alice.bank.account_rub -= alice.food_stock.bananas;
}
void alice_food_chicken() {
	alice.bank.account_rub -= alice.food_stock.chicken_breast;
}
void alice_food_pork() {
	alice.bank.account_rub -= alice.food_stock.pork;
}
void alice_food_beef() {
	alice.bank.account_rub -= alice.food_stock.beef;
}
void alice_food_cheese() {
	alice.bank.account_rub -= alice.food_stock.cheese;
}
void alice_food_tvorog() {
	alice.bank.account_rub -= alice.food_stock.tvorog;
}
void alice_food_butter() {
	alice.bank.account_rub -= alice.food_stock.butter;
}
void alice_food_eggs() {
	alice.bank.account_rub -= alice.food_stock.eggs;
}
void alice_food_milk() {
	alice.bank.account_rub -= alice.food_stock.milk;
}
void alice_food_oil() {
	alice.bank.account_rub -= alice.food_stock.vegetable_oil;
}
void alice_food_tea() {
	alice.bank.account_rub -= alice.food_stock.tea;
}
void alice_food_coffee() {
	alice.bank.account_rub -= alice.food_stock.coffee;
}
void alice_food_salt() {
	alice.bank.account_rub -= alice.food_stock.salt;
}
void alice_food_pepper() {
	alice.bank.account_rub -= alice.food_stock.pepper;
}
void alice_food_sugar() {
	alice.bank.account_rub -= alice.food_stock.sugar;
}
void alice_food_flour() {
	alice.bank.account_rub -= alice.food_stock.flour;
}
void alice_food_pasta() {
	alice.bank.account_rub -= alice.food_stock.pasta;
}
void alice_food_canned() {
	alice.bank.account_rub -= alice.food_stock.canned_food;
}
void alice_food_fish() {
	alice.bank.account_rub -= alice.food_stock.fish;
}
void alice_food_sausage() {
	alice.bank.account_rub -= alice.food_stock.sausage;
}
void alice_food_bread() {
	alice.bank.account_rub -= alice.food_stock.bread;
}
void alice_food_juice() {
	alice.bank.account_rub -= alice.food_stock.juice;
}
void alice_food_water() {
	alice.bank.account_rub -= alice.food_stock.water;
}
void alice_food_honey() {
	alice.bank.account_rub -= alice.food_stock.honey;
}
void alice_food_nuts() {
	alice.bank.account_rub -= alice.food_stock.nuts;
}
void alice_food_dried_fruits() {
	alice.bank.account_rub -= alice.food_stock.dried_fruits;
}

void alice_household_washing() { // Для дома Алисы
	alice.bank.account_rub -= alice.household.washing_powder;
}
void alice_household_toilet_paper() {
	alice.bank.account_rub -= alice.household.toilet_paper;
}
void alice_household_toothpaste() {
	alice.bank.account_rub -= alice.household.toothpaste;
}
void alice_household_toothbrush() {
	alice.bank.account_rub -= alice.household.toothbrush;
}
void alice_household_deodorant() {
	alice.bank.account_rub -= alice.household.deodorant;
}
void alice_household_shower_gel() {
	alice.bank.account_rub -= alice.household.shower_gel;
}
void alice_household_shampoo() {
	alice.bank.account_rub -= alice.household.shampoo;
}
void alice_household_razor() {
	alice.bank.account_rub -= alice.household.razor;
}
void alice_household_dish_soap() {
	alice.bank.account_rub -= alice.household.dish_soap;
}
void alice_household_trash_bags() {
	alice.bank.account_rub -= alice.household.trash_bags;
}
void alice_household_paper_towels() {
	alice.bank.account_rub -= alice.household.paper_towels;
}
void alice_household_softener() {
	alice.bank.account_rub -= alice.household.laundry_softener;
}
void alice_household_cleaning_spray() {
	alice.bank.account_rub -= alice.household.cleaning_spray;
}
void alice_household_sponge() {
	alice.bank.account_rub -= alice.household.sponge;
}
void alice_household_batteries() {
	alice.bank.account_rub -= alice.household.batteries;
}
void alice_household_foil() {
	alice.bank.account_rub -= alice.household.foil;
}
void alice_household_cling_film() {
	alice.bank.account_rub -= alice.household.cling_film;
}

void alice_health_fitness() { // Для здоровья Алисы
	alice.bank.account_rub -= alice.health.fitness;
}
void alice_health_massage() {
	alice.bank.account_rub -= alice.health.massage;
}
void alice_health_medicines() {
	alice.bank.account_rub -= alice.health.medicines;
}
void alice_health_vitamins() {
	alice.bank.account_rub -= alice.health.vitamins;
}
void alice_health_omega3() {
	alice.bank.account_rub -= alice.health.omega3;
}
void alice_health_vitamin_d() {
	alice.bank.account_rub -= alice.health.vitamin_d;
}
void alice_health_magnesium() {
	alice.bank.account_rub -= alice.health.magnesium;
}
void alice_health_zinc() {
	alice.bank.account_rub -= alice.health.zinc;
}
void alice_health_iron() {
	alice.bank.account_rub -= alice.health.iron;
}
void alice_health_calcium() {
	alice.bank.account_rub -= alice.health.calcium;
}
void alice_health_collagen() {
	alice.bank.account_rub -= alice.health.collagen;
}
void alice_health_probiotics() {
	alice.bank.account_rub -= alice.health.probiotics;
}
void alice_health_eye_drops() {
	alice.bank.account_rub -= alice.health.eye_drops;
}
void alice_health_cream() {
	alice.bank.account_rub -= alice.health.cream;
}

void alice_lifestyle_cinema() {
	alice.bank.account_rub -= alice.lifestyle.cinema;
}
void alice_lifestyle_restaurant() {
	alice.bank.account_rub -= alice.lifestyle.restaurant;
}
void alice_lifestyle_theater() {
	alice.bank.account_rub -= alice.lifestyle.theater;
}
void alice_lifestyle_quest() {
	alice.bank.account_rub -= alice.lifestyle.quest;
}
void alice_lifestyle_concert() {
	alice.bank.account_rub -= alice.lifestyle.concert;
}
void alice_lifestyle_museum() {
	alice.bank.account_rub -= alice.lifestyle.museum;
}
void alice_lifestyle_ice_skating() {
	alice.bank.account_rub -= alice.lifestyle.ice_skating;
}
void alice_lifestyle_skiing() {
	alice.bank.account_rub -= alice.lifestyle.skiing;
}

void alice_shopping_clothes() {
	alice.bank.account_rub -= alice.shopping.clothes;
}
void alice_shopping_shoes() {
	alice.bank.account_rub -= alice.shopping.shoes;
}
void alice_shopping_accessories() {
	alice.bank.account_rub -= alice.shopping.accessories;
}
void alice_shopping_cosmetics() {
	alice.bank.account_rub -= alice.shopping.cosmetics;
}
void alice_shopping_home() {
	alice.bank.account_rub -= alice.shopping.home_goods;
}
void alice_shopping_electronics() {
	alice.bank.account_rub -= alice.shopping.electronics;
}
void alice_shopping_sport() {
	alice.bank.account_rub -= alice.shopping.sport_equipment;
}
void alice_shopping_perfume() {
	alice.bank.account_rub -= alice.shopping.perfume;
}

void alice_development_yandex() {
	alice.bank.account_rub -= alice.development.yandex_plus;
}
void alice_development_t2() {
	alice.bank.account_rub -= alice.development.t2;
}
void alice_development_youtube() { 
	alice.bank.account_rub -= alice.development.youtube_premium;
}
void alice_development_books() {
	alice.bank.account_rub -= alice.development.books;
}
void alice_development_audiobooks() {
	alice.bank.account_rub -= alice.development.audiobooks;
}

void alice_pets_cat_food() {
	alice.bank.account_rub -= alice.pets.cat_food;
}
void alice_pets_cat_litter() {
	alice.bank.account_rub -= alice.pets.cat_litter;
}
void alice_pets_cat_vet() {
	alice.bank.account_rub -= alice.pets.cat_vet;
}
void alice_pets_cat_toys() {
	alice.bank.account_rub -= alice.pets.cat_toys;
}
void alice_pets_pet_insurance() {
	alice.bank.account_rub -= alice.pets.pet_insurance;
}

void alice_car_gas() {
	alice.bank.account_rub -= alice.car.gas;
}
void alice_car_parking() {
	alice.bank.account_rub -= alice.car.parking;
}
void alice_car_maintenance() {
	alice.bank.account_rub -= alice.car.maintenance;
}
void alice_car_tires() {
	alice.bank.account_rub -= alice.car.tire_change;
}
void alice_car_insurance() {
	alice.bank.account_rub -= alice.car.insurance;
}
void alice_car_tax() {
	alice.bank.account_rub -= alice.car.tax;
}

void alice_vacation_summer() {
	alice.bank.account_rub -= alice.vacation.summer_trip;
}
void alice_vacation_winter() {
	alice.bank.account_rub -= alice.vacation.winter_trip;
}
void alice_vacation_weekend() {
	alice.bank.account_rub -= alice.vacation.weekend_trips;
}
void alice_vacation_visa() {
	alice.bank.account_rub -= alice.vacation.visa;
}
void alice_vacation_insurance() {
	alice.bank.account_rub -= alice.vacation.insurance;
}
void alice_vacation_souvenirs() {
	alice.bank.account_rub -= alice.vacation.souvenirs;
}

void alice_salary_func(int month, int year) // Зп и её повышение
{
	if (month == 3 && year == 2027) {
		alice.salary = alice.salary * 1.05;
	}
	if (month == 3 && year == 2028) {
		alice.salary = alice.salary * 1.05;
	}
	if (month == 2 && year == 2026) {
		alice.bank.account_rub += 5000;
	}
	alice.bank.account_rub += alice.salary;
}

void alice_credit_func() // Выплата кредита
{
	if (alice.credit.debt > 0) {
		alice.bank.account_rub -= alice.credit.payment;
		alice.credit.debt -= alice.credit.payment;
		if (alice.credit.debt < 0) alice.credit.debt = 0;
	}
}

void alice_savings_func()  
{
	RUB save = alice.salary * 0.1; // 10% от зп
	if (alice.bank.account_rub >= save) {
		alice.bank.account_rub -= save;
		alice.total_savings += save;
		alice.bank.account_rub += save * 0.01;
	}
}

void alice_deposit_func()
{
	if (alice.deposit.active == 1 && alice.bank.account_rub >= 20000) {
		RUB deposit_amount = 20000;
		alice.bank.account_rub -= deposit_amount;
		alice.deposit.amount += deposit_amount;
		alice.deposit.total_deposited += deposit_amount;
		alice.bank.account_rub += deposit_amount * (alice.deposit.rate / 12);
	}
}

void alice_usd_investment_func()
{
	if (alice.bank.account_rub >= 50000) {
		USD buy_usd = (alice.bank.account_rub * 0.2) / alice.bank.rate_usd_rub;
		alice.bank.account_usd += buy_usd;
		alice.bank.account_rub -= buy_usd * alice.bank.rate_usd_rub;
		alice.total_investment_usd += buy_usd;
	}
}

void alice_personal_expenses(int month) // Личные расходы
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) {
		alice.bank.account_rub -= alice.haircut;
	}
	alice.bank.account_rub -= alice.coffee_takeaway;
	alice.bank.account_rub -= alice.lunch_work;
	alice.bank.account_rub -= alice.psychologist;
	alice.bank.account_rub -= alice.taxi;
	alice.bank.account_rub -= alice.charity;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) {
		alice.bank.account_rub -= alice.manicure;
	}
	if (month == 2 || month == 5 || month == 8 || month == 11) {
		alice.bank.account_rub -= alice.cosmetologist;
	}
}

void alice_fun_func(int month) // Развлечения
{
	if (month == 7 || month == 8) {
		alice.bank.account_rub -= alice.fun * 2;
	}
	alice.bank.account_rub -= alice.fun;
}

void alice_bonus_events(int month, int year) // Бонусы, нал вычет
{
	if (month == 12 && year == 2026) {
		alice.bank.account_rub += 50000;
	}
	if (month == 12 && year == 2027) {
		alice.bank.account_rub += 55000;
	}
	if (month == 12 && year == 2028) {
		alice.bank.account_rub += 60000;
	}
	if (month == 5 && year == 2027) {
		alice.bank.account_rub += 12000;
	}
	if (month == 5 && year == 2028) {
		alice.bank.account_rub += 13000;
	}
	if (month == 5 && year == 2029) {
		alice.bank.account_rub += 14000;
	}
}

void alice_emergency(int month, int year)
{
	if (month == 4 && year == 2027) {
		alice.bank.account_rub -= 10000; // Сломалась техника
	}
	if (month == 9 && year == 2028) {
		alice.bank.account_rub -= 8000; //непредвиденные расходы
	}
}

void alice_vacation_func(int month, int year) // Отпуск
{
	if (month == 7 && year == 2027) {
		alice_vacation_summer();
		alice_vacation_souvenirs();
	}
	if (month == 7 && year == 2028) {
		alice_vacation_summer();
		alice_vacation_souvenirs();
	}
	if (month == 1 && year == 2028) {
		alice_vacation_winter();
	}
	if (month == 5 && year == 2027) {
		alice_vacation_visa();
	}
	if (month == 6 && year == 2027) {
		alice_vacation_insurance();
	}
}

void alice_simulation()
{
	int year = 2026;
	int month = 2;
	while (!(year == 2029 && month == 2)) {
		if (month == 1) {
			alice_inflation_after();
		}
		alice_salary_func(month, year);
		alice_food_rice();
		alice_food_buckwheat();
		alice_food_oatmeal();
		alice_food_potatoes();
		alice_food_carrots();
		alice_food_onion();
		alice_food_garlic();
		alice_food_cabbage();
		alice_food_tomatoes();
		alice_food_cucumbers();
		alice_food_apples();
		alice_food_bananas();
		alice_food_chicken();
		alice_food_pork();
		alice_food_beef();
		alice_food_cheese();
		alice_food_tvorog();
		alice_food_butter();
		alice_food_eggs();
		alice_food_milk();
		alice_food_oil();
		alice_food_tea();
		alice_food_coffee();
		alice_food_salt();
		alice_food_pepper();
		alice_food_sugar();
		alice_food_flour();
		alice_food_pasta();
		alice_food_canned();
		alice_food_fish();
		alice_food_sausage();
		alice_food_bread();
		alice_food_juice();
		alice_food_water();
		alice_food_honey();
		alice_food_nuts();
		alice_food_dried_fruits();
		if (month == 1) { alice_utilities_jan(); }
		if (month == 2) { alice_utilities_feb(); }
		if (month == 3) { alice_utilities_mar(); }
		if (month == 4) { alice_utilities_apr(); }
		if (month == 5) { alice_utilities_may(); }
		if (month == 6) { alice_utilities_jun(); }
		if (month == 7) { alice_utilities_jul(); }
		if (month == 8) { alice_utilities_aug(); }
		if (month == 9) { alice_utilities_sep(); }
		if (month == 10) { alice_utilities_oct(); }
		if (month == 11) { alice_utilities_nov(); }
		if (month == 12) { alice_utilities_dec(); }
		if (month == 1 || month == 4 || month == 7 || month == 10) {
			alice_household_washing();
			alice_household_shower_gel();
			alice_household_shampoo();
			alice_household_razor();
			alice_household_trash_bags();
			alice_household_cleaning_spray();
			alice_household_sponge();
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) {
			alice_household_toilet_paper();
			alice_household_foil();
			alice_household_cling_film();
		}
		if (month == 2 || month == 5 || month == 8 || month == 11) {
			alice_household_toothpaste();
			alice_household_deodorant();
			alice_household_dish_soap();
		}
		if (month == 3 || month == 9) {
			alice_household_toothbrush();
		}
		if (month == 4 || month == 10) {
			alice_household_paper_towels();
		}
		if (month == 6 || month == 12) {
			alice_household_softener();
			alice_household_batteries();
		}
		alice_health_fitness();
		if (month == 3 || month == 6 || month == 9 || month == 12) {
			alice_health_massage();
		}
		if (month == 2 || month == 5 || month == 8 || month == 11) {
			alice_health_medicines();
		}
		if (month == 1 || month == 4 || month == 7 || month == 10) {
			alice_health_vitamins();
			alice_health_omega3();
			alice_health_vitamin_d();
			alice_health_magnesium();
			alice_health_zinc();
			alice_health_iron();
			alice_health_calcium();
			alice_health_eye_drops();
		}
		if (month == 3 || month == 9) {
			alice_health_collagen();
			alice_health_probiotics();
			alice_health_cream();
		}
		if (month == 6 || month == 12) {
			alice_lifestyle_cinema();
		}
		if (month == 2 || month == 5 || month == 8 || month == 11) {
			alice_lifestyle_restaurant();
		}
		if (month == 5 || month == 10) {
			alice_lifestyle_theater();
		}
		if (month == 4 || month == 11) {
			alice_lifestyle_quest();
		}
		if (month == 7) {
			alice_lifestyle_concert();
		}
		if (month == 9) {
			alice_lifestyle_museum();
		}
		if (month == 12) {
			alice_lifestyle_ice_skating();
		}
		if (month == 1) {
			alice_lifestyle_skiing();
		}
		if (month == 3 || month == 9) {
			alice_shopping_clothes();
		}
		if (month == 5 || month == 11) {
			alice_shopping_shoes();
		}
		if (month == 2 || month == 8) {
			alice_shopping_accessories();
			alice_shopping_perfume();
		}
		if (month == 4 || month == 10) {
			alice_shopping_cosmetics();
		}
		if (month == 6) {
			alice_shopping_home();
			alice_shopping_electronics();
		}
		if (month == 1) {
			alice_shopping_sport();
		}
		alice_development_yandex();
		alice_development_t2();
		alice_development_youtube();
		if (month == 3 || month == 9) {
			alice_development_books();
		}
		if (month == 6 || month == 12) {
			alice_development_audiobooks();
		}
		alice_pets_cat_food();
		alice_pets_cat_litter();
		if (month == 6) {
			alice_pets_cat_vet();
		}
		if (month == 12) {
			alice_pets_cat_toys();
		}
		if (month == 3) {
			alice_pets_pet_insurance();
		}
		alice_car_gas();
		alice_car_parking();
		if (month == 6) {
			alice_car_maintenance();
		}
		if (month == 10) {
			alice_car_tires();
		}
		if (month == 1) {
			alice_car_insurance();
		}
		if (month == 3) {
			alice_car_tax();
		}
		alice_credit_func();
		alice_personal_expenses(month);
		alice_fun_func(month);
		alice_savings_func();
		alice_deposit_func();
		alice_usd_investment_func();
		alice_bonus_events(month, year);
		alice_emergency(month, year);
		alice_vacation_func(month, year);
		month++;
		if (month == 13) {
			year++;
			month = 1;
		}
	}
}

void den_init()
{
	den.bank.rate_usd_rub = 78.76;
	den.bank.account_rub = 50000;
	den.bank.account_usd = 0;
	den.salary = 130000;
	den.fun = 5000;
	den.total_savings = 0;
	den.total_investment_usd = 0;
	den.inflation_rate = 0.008;
	den.has_mortgage = 1;
	den.has_credit = 0;
	den.car.value = 2500000;
	den.car.gas = 15000;
	den.car.maintenance = 20000;
	den.car.parking = 0;
	den.car.tire_change = 20000;
	den.car.insurance = 25000;
	den.car.tax = 10500;
	den.credit.debt = 0;
	den.credit.payment = 0;
	den.mortgage.debt = 3500000;
	den.mortgage.months_total = 120; // 10 месяцев
	den.mortgage.months_paid = 0;
	den.mortgage.payment = 52000;
	den.mortgage.remainder = 3500000;
	den.mortgage.rate = 13.0;
	den.food_stock.rice = 800;
	den.food_stock.buckwheat = 800;
	den.food_stock.oatmeal = 600;
	den.food_stock.potatoes = 500;
	den.food_stock.carrots = 300;
	den.food_stock.onion = 250;
	den.food_stock.garlic = 100;
	den.food_stock.cabbage = 250;
	den.food_stock.tomatoes = 300;
	den.food_stock.cucumbers = 250;
	den.food_stock.apples = 400;
	den.food_stock.bananas = 300;
	den.food_stock.chicken_breast = 1000;
	den.food_stock.pork = 800;
	den.food_stock.beef = 700;
	den.food_stock.cheese = 500;
	den.food_stock.tvorog = 400;
	den.food_stock.butter = 400;
	den.food_stock.eggs = 1000;
	den.food_stock.milk = 1200;
	den.food_stock.vegetable_oil = 300;
	den.food_stock.tea = 250;
	den.food_stock.coffee = 400;
	den.food_stock.salt = 40;
	den.food_stock.pepper = 60;
	den.food_stock.sugar = 80;
	den.food_stock.flour = 60;
	den.food_stock.pasta = 300;
	den.food_stock.canned_food = 400;
	den.food_stock.fish = 500;
	den.food_stock.sausage = 600;
	den.food_stock.bread = 300;
	den.food_stock.juice = 250;
	den.food_stock.water = 200;
	den.food_stock.honey = 200;
	den.food_stock.nuts = 300;
	den.food_stock.dried_fruits = 250;
	den.household.washing_powder = 500;
	den.household.toilet_paper = 350;
	den.household.toothpaste = 150;
	den.household.toothbrush = 100;
	den.household.deodorant = 200;
	den.household.shower_gel = 250;
	den.household.shampoo = 250;
	den.household.razor = 400;
	den.household.dish_soap = 120;
	den.household.trash_bags = 80;
	den.household.paper_towels = 150;
	den.household.laundry_softener = 200;
	den.household.cleaning_spray = 120;
	den.household.sponge = 60;
	den.household.batteries = 150;
	den.household.foil = 80;
	den.household.cling_film = 60;
	den.utils.electricity = 800;
	den.utils.water_cold = 250;
	den.utils.water_hot = 350;
	den.utils.heating = 0;
	den.utils.capital_repair = 300;
	den.utils.garbage = 150;
	den.utils.internet = 500;
	den.utils.intercom = 100;
	den.utils.gas_supply = 250;
	den.utils.sewer = 120; // Канализация
	den.utils.tv = 200;
	den.health.fitness = 2500;
	den.health.massage = 0;
	den.health.medicines = 500;
	den.health.dentist = 0;
	den.health.vitamins = 500;
	den.health.omega3 = 0;
	den.health.vitamin_d = 0;
	den.health.magnesium = 0;
	den.health.zinc = 0;
	den.health.iron = 0;
	den.health.calcium = 0;
	den.health.collagen = 0;
	den.health.probiotics = 0;
	den.health.eye_drops = 0;
	den.health.cream = 0;
	den.lifestyle.cinema = 0;
	den.lifestyle.restaurant = 0;
	den.lifestyle.bar = 4000;
	den.lifestyle.billiards = 2000;
	den.lifestyle.bowling = 0;
	den.lifestyle.theater = 0;
	den.lifestyle.quest = 0;
	den.lifestyle.concert = 0;
	den.lifestyle.museum = 0;
	den.lifestyle.hookah = 0;
	den.lifestyle.ice_skating = 0;
	den.lifestyle.skiing = 0;
	den.shopping.clothes = 4000;
	den.shopping.shoes = 3000;
	den.shopping.accessories = 500;
	den.shopping.electronics = 0;
	den.shopping.cosmetics = 0;
	den.shopping.tools = 2000;
	den.shopping.home_goods = 1000;
	den.shopping.sport_equipment = 1500;
	den.shopping.backpack = 0;
	den.shopping.watch = 0;
	den.shopping.perfume = 0;
	den.development.yandex_plus = 350;
	den.development.t2 = 300;
	den.development.youtube_premium = 500;
	den.development.books = 800;
	den.development.courses = 0;
	den.development.english = 0;
	den.development.programming = 0;
	den.development.audiobooks = 0;
	den.pets.cat_food = 0;
	den.pets.cat_litter = 0;
	den.pets.cat_vet = 0;
	den.pets.cat_toys = 0;
	den.pets.dog_food = 3000;
	den.pets.dog_vet = 0;
	den.pets.dog_toys = 500;
	den.pets.dog_walker = 0;
	den.pets.pet_insurance = 0;
	den.vacation.summer_trip = 0;
	den.vacation.winter_trip = 0;
	den.vacation.weekend_trips = 0;
	den.vacation.visa = 0;
	den.vacation.insurance = 0;
	den.vacation.equipment = 0;
	den.vacation.souvenirs = 0;
	den.deposit.amount = 0;
	den.deposit.total_deposited = 0;
	den.deposit.rate = 0;
	den.deposit.active = 0;
	den.haircut = 800;
	den.coffee_takeaway = 0;
	den.lunch_work = 2000;
	den.parking_cost = 0;
	den.gifts = 10000;
	den.psychologist = 0;
	den.manicure = 0;
	den.cosmetologist = 0;
	den.taxi = 0;
	den.cigarettes = 0;
	den.charity = 500;
}

void den_inflation_after()
{
	den.inflation_rate = 0.008;
	den.food_stock.rice = den.food_stock.rice * (1 + den.inflation_rate);
	den.food_stock.buckwheat = den.food_stock.buckwheat * (1 + den.inflation_rate);
	den.food_stock.oatmeal = den.food_stock.oatmeal * (1 + den.inflation_rate);
	den.food_stock.potatoes = den.food_stock.potatoes * (1 + den.inflation_rate);
	den.food_stock.carrots = den.food_stock.carrots * (1 + den.inflation_rate);
	den.food_stock.onion = den.food_stock.onion * (1 + den.inflation_rate);
	den.food_stock.garlic = den.food_stock.garlic * (1 + den.inflation_rate);
	den.food_stock.cabbage = den.food_stock.cabbage * (1 + den.inflation_rate);
	den.food_stock.tomatoes = den.food_stock.tomatoes * (1 + den.inflation_rate);
	den.food_stock.cucumbers = den.food_stock.cucumbers * (1 + den.inflation_rate);
	den.food_stock.apples = den.food_stock.apples * (1 + den.inflation_rate);
	den.food_stock.bananas = den.food_stock.bananas * (1 + den.inflation_rate);
	den.food_stock.chicken_breast = den.food_stock.chicken_breast * (1 + den.inflation_rate);
	den.food_stock.pork = den.food_stock.pork * (1 + den.inflation_rate);
	den.food_stock.beef = den.food_stock.beef * (1 + den.inflation_rate);
	den.food_stock.cheese = den.food_stock.cheese * (1 + den.inflation_rate);
	den.food_stock.tvorog = den.food_stock.tvorog * (1 + den.inflation_rate);
	den.food_stock.butter = den.food_stock.butter * (1 + den.inflation_rate);
	den.food_stock.eggs = den.food_stock.eggs * (1 + den.inflation_rate);
	den.food_stock.milk = den.food_stock.milk * (1 + den.inflation_rate);
	den.food_stock.vegetable_oil = den.food_stock.vegetable_oil * (1 + den.inflation_rate);
	den.food_stock.tea = den.food_stock.tea * (1 + den.inflation_rate);
	den.food_stock.coffee = den.food_stock.coffee * (1 + den.inflation_rate);
	den.food_stock.salt = den.food_stock.salt * (1 + den.inflation_rate);
	den.food_stock.pepper = den.food_stock.pepper * (1 + den.inflation_rate);
	den.food_stock.sugar = den.food_stock.sugar * (1 + den.inflation_rate);
	den.food_stock.flour = den.food_stock.flour * (1 + den.inflation_rate);
	den.food_stock.pasta = den.food_stock.pasta * (1 + den.inflation_rate);
	den.food_stock.canned_food = den.food_stock.canned_food * (1 + den.inflation_rate);
	den.food_stock.fish = den.food_stock.fish * (1 + den.inflation_rate);
	den.food_stock.sausage = den.food_stock.sausage * (1 + den.inflation_rate);
	den.food_stock.bread = den.food_stock.bread * (1 + den.inflation_rate);
	den.food_stock.juice = den.food_stock.juice * (1 + den.inflation_rate);
	den.food_stock.water = den.food_stock.water * (1 + den.inflation_rate);
	den.food_stock.honey = den.food_stock.honey * (1 + den.inflation_rate);
	den.food_stock.nuts = den.food_stock.nuts * (1 + den.inflation_rate);
	den.food_stock.dried_fruits = den.food_stock.dried_fruits * (1 + den.inflation_rate);
	den.household.washing_powder = den.household.washing_powder * (1 + den.inflation_rate);
	den.household.toilet_paper = den.household.toilet_paper * (1 + den.inflation_rate);
	den.household.toothpaste = den.household.toothpaste * (1 + den.inflation_rate);
	den.household.toothbrush = den.household.toothbrush * (1 + den.inflation_rate);
	den.household.deodorant = den.household.deodorant * (1 + den.inflation_rate);
	den.household.shower_gel = den.household.shower_gel * (1 + den.inflation_rate);
	den.household.shampoo = den.household.shampoo * (1 + den.inflation_rate);
	den.household.razor = den.household.razor * (1 + den.inflation_rate);
	den.household.dish_soap = den.household.dish_soap * (1 + den.inflation_rate);
	den.household.trash_bags = den.household.trash_bags * (1 + den.inflation_rate);
	den.household.paper_towels = den.household.paper_towels * (1 + den.inflation_rate);
	den.household.laundry_softener = den.household.laundry_softener * (1 + den.inflation_rate);
	den.household.cleaning_spray = den.household.cleaning_spray * (1 + den.inflation_rate);
	den.household.sponge = den.household.sponge * (1 + den.inflation_rate);
	den.household.batteries = den.household.batteries * (1 + den.inflation_rate);
	den.household.foil = den.household.foil * (1 + den.inflation_rate);
	den.household.cling_film = den.household.cling_film * (1 + den.inflation_rate);
	den.utils.electricity = den.utils.electricity * (1 + den.inflation_rate);
	den.utils.water_cold = den.utils.water_cold * (1 + den.inflation_rate);
	den.utils.water_hot = den.utils.water_hot * (1 + den.inflation_rate);
	den.utils.capital_repair = den.utils.capital_repair * (1 + den.inflation_rate);
	den.utils.garbage = den.utils.garbage * (1 + den.inflation_rate);
	den.utils.internet = den.utils.internet * (1 + den.inflation_rate);
	den.utils.intercom = den.utils.intercom * (1 + den.inflation_rate);
	den.utils.gas_supply = den.utils.gas_supply * (1 + den.inflation_rate);
	den.utils.sewer = den.utils.sewer * (1 + den.inflation_rate);
	den.utils.tv = den.utils.tv * (1 + den.inflation_rate);
	den.health.medicines = den.health.medicines * (1 + den.inflation_rate);
	den.health.vitamins = den.health.vitamins * (1 + den.inflation_rate);
	den.haircut = den.haircut * (1 + den.inflation_rate);
	den.lunch_work = den.lunch_work * (1 + den.inflation_rate);
	den.gifts = den.gifts * (1 + den.inflation_rate);
	den.charity = den.charity * (1 + den.inflation_rate);
}

void den_utilities_jan()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
	den.bank.account_rub -= den.utils.heating;
}

void den_utilities_feb()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
	den.bank.account_rub -= den.utils.heating;
}

void den_utilities_mar()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
	den.bank.account_rub -= den.utils.heating;
}

void den_utilities_apr()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
}

void den_utilities_may()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
}

void den_utilities_jun()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
}

void den_utilities_jul()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
}

void den_utilities_aug()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
}

void den_utilities_sep()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
}

void den_utilities_oct()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
	den.bank.account_rub -= den.utils.heating;
}

void den_utilities_nov()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
	den.bank.account_rub -= den.utils.heating;
}

void den_utilities_dec()
{
	den.bank.account_rub -= den.utils.electricity;
	den.bank.account_rub -= den.utils.water_cold;
	den.bank.account_rub -= den.utils.water_hot;
	den.bank.account_rub -= den.utils.capital_repair;
	den.bank.account_rub -= den.utils.garbage;
	den.bank.account_rub -= den.utils.internet;
	den.bank.account_rub -= den.utils.intercom;
	den.bank.account_rub -= den.utils.gas_supply;
	den.bank.account_rub -= den.utils.sewer;
	den.bank.account_rub -= den.utils.tv;
	den.bank.account_rub -= den.utils.heating;
}

void den_food_rice() {
	den.bank.account_rub -= den.food_stock.rice;
}
void den_food_buckwheat() {
	den.bank.account_rub -= den.food_stock.buckwheat;
}
void den_food_oatmeal() {
	den.bank.account_rub -= den.food_stock.oatmeal;
}
void den_food_potatoes() {
	den.bank.account_rub -= den.food_stock.potatoes;
}
void den_food_carrots() {
	den.bank.account_rub -= den.food_stock.carrots;
}
void den_food_onion() {
	den.bank.account_rub -= den.food_stock.onion;
}
void den_food_garlic() {
	den.bank.account_rub -= den.food_stock.garlic;
}
void den_food_cabbage() {
	den.bank.account_rub -= den.food_stock.cabbage;
}
void den_food_tomatoes() {
	den.bank.account_rub -= den.food_stock.tomatoes;
}
void den_food_cucumbers() {
	den.bank.account_rub -= den.food_stock.cucumbers;
}
void den_food_apples() {
	den.bank.account_rub -= den.food_stock.apples;
}
void den_food_bananas() {
	den.bank.account_rub -= den.food_stock.bananas;
}
void den_food_chicken() {
	den.bank.account_rub -= den.food_stock.chicken_breast;
}
void den_food_pork() {
	den.bank.account_rub -= den.food_stock.pork;
}
void den_food_beef() {
	den.bank.account_rub -= den.food_stock.beef;
}
void den_food_cheese() {
	den.bank.account_rub -= den.food_stock.cheese;
}
void den_food_tvorog() {
	den.bank.account_rub -= den.food_stock.tvorog;
}
void den_food_butter() {
	den.bank.account_rub -= den.food_stock.butter;
}
void den_food_eggs() {
	den.bank.account_rub -= den.food_stock.eggs;
}
void den_food_milk() {
	den.bank.account_rub -= den.food_stock.milk;
}
void den_food_oil() {
	den.bank.account_rub -= den.food_stock.vegetable_oil;
}
void den_food_tea() {
	den.bank.account_rub -= den.food_stock.tea;
}
void den_food_coffee() {
	den.bank.account_rub -= den.food_stock.coffee;
}
void den_food_salt() {
	den.bank.account_rub -= den.food_stock.salt;
}
void den_food_pepper() {
	den.bank.account_rub -= den.food_stock.pepper;
}
void den_food_sugar() {
	den.bank.account_rub -= den.food_stock.sugar;
}
void den_food_flour() {
	den.bank.account_rub -= den.food_stock.flour;
}
void den_food_pasta() {
	den.bank.account_rub -= den.food_stock.pasta;
}
void den_food_canned() {
	den.bank.account_rub -= den.food_stock.canned_food;
}
void den_food_fish() {
	den.bank.account_rub -= den.food_stock.fish;
}
void den_food_sausage() {
	den.bank.account_rub -= den.food_stock.sausage;
}
void den_food_bread() {
	den.bank.account_rub -= den.food_stock.bread;
}
void den_food_juice() {
	den.bank.account_rub -= den.food_stock.juice;
}
void den_food_water() {
	den.bank.account_rub -= den.food_stock.water;
}
void den_food_honey() {
	den.bank.account_rub -= den.food_stock.honey;
}
void den_food_nuts() {
	den.bank.account_rub -= den.food_stock.nuts;
}
void den_food_dried_fruits() {
	den.bank.account_rub -= den.food_stock.dried_fruits;
}

void den_household_washing() {
	den.bank.account_rub -= den.household.washing_powder;
}
void den_household_toilet_paper() {
	den.bank.account_rub -= den.household.toilet_paper;
}
void den_household_toothpaste() {
	den.bank.account_rub -= den.household.toothpaste;
}
void den_household_toothbrush() {
	den.bank.account_rub -= den.household.toothbrush;
}
void den_household_deodorant() {
	den.bank.account_rub -= den.household.deodorant;
}
void den_household_shower_gel() {
	den.bank.account_rub -= den.household.shower_gel;
}
void den_household_shampoo() {
	den.bank.account_rub -= den.household.shampoo;
}
void den_household_razor() {
	den.bank.account_rub -= den.household.razor;
}
void den_household_dish_soap() {
	den.bank.account_rub -= den.household.dish_soap;
}
void den_household_trash_bags() {
	den.bank.account_rub -= den.household.trash_bags;
}
void den_household_paper_towels() {
	den.bank.account_rub -= den.household.paper_towels;
}
void den_household_softener() {
	den.bank.account_rub -= den.household.laundry_softener;
}
void den_household_cleaning_spray() {
	den.bank.account_rub -= den.household.cleaning_spray;
}
void den_household_sponge() {
	den.bank.account_rub -= den.household.sponge;
}
void den_household_batteries() {
	den.bank.account_rub -= den.household.batteries;
}
void den_household_foil() {
	den.bank.account_rub -= den.household.foil;
}
void den_household_cling_film() {
	den.bank.account_rub -= den.household.cling_film;
}

void den_health_fitness() {
	den.bank.account_rub -= den.health.fitness;
}
void den_health_medicines() {
	den.bank.account_rub -= den.health.medicines;
}
void den_health_vitamins() {
	den.bank.account_rub -= den.health.vitamins;
}

void den_lifestyle_bar() {
	den.bank.account_rub -= den.lifestyle.bar;
}
void den_lifestyle_billiards() {
	den.bank.account_rub -= den.lifestyle.billiards;
}
void den_lifestyle_bowling() {
	den.bank.account_rub -= den.lifestyle.bowling;
}
void den_lifestyle_hookah() {
	den.bank.account_rub -= den.lifestyle.hookah;
}

void den_shopping_clothes() {
	den.bank.account_rub -= den.shopping.clothes;
}
void den_shopping_shoes() {
	den.bank.account_rub -= den.shopping.shoes;
}
void den_shopping_tools() {
	den.bank.account_rub -= den.shopping.tools;
}
void den_shopping_electronics() {
	den.bank.account_rub -= den.shopping.electronics;
}
void den_shopping_sport() {
	den.bank.account_rub -= den.shopping.sport_equipment;
}

void den_development_youtube() {
	den.bank.account_rub -= den.development.youtube_premium;
}
void den_development_books() {
	den.bank.account_rub -= den.development.books;
}
void den_development_yandex() {
	den.bank.account_rub -= den.development.yandex_plus;
}
void den_development_t2() {
	den.bank.account_rub -= den.development.t2;
}

void den_pets_dog_food() {
	den.bank.account_rub -= den.pets.dog_food;
}
void den_pets_dog_toys() {
	den.bank.account_rub -= den.pets.dog_toys;
}
void den_pets_dog_vet() {
	den.bank.account_rub -= den.pets.dog_vet;
}

void den_car_gas() {
	den.bank.account_rub -= den.car.gas;
}
void den_car_maintenance() {
	den.bank.account_rub -= den.car.maintenance;
}
void den_car_tires() {
	den.bank.account_rub -= den.car.tire_change;
}
void den_car_insurance() {
	den.bank.account_rub -= den.car.insurance;
}
void den_car_tax() {
	den.bank.account_rub -= den.car.tax;
}


void den_vacation_summer() { // Путешестивя Дена
	den.bank.account_rub -= den.vacation.summer_trip;
} 
void den_vacation_winter() {
	den.bank.account_rub -= den.vacation.winter_trip;
}

void den_salary_func(int month, int year)
{
	if (month == 3 && year == 2027) {
		den.salary = den.salary * 1.05;
	}
	if (month == 3 && year == 2028) {
		den.salary = den.salary * 1.05;
	}
	den.bank.account_rub += den.salary;
}

void den_mortgage_func()
{
	if (den.mortgage.debt > 0) {
		den.bank.account_rub -= den.mortgage.payment;
		den.mortgage.debt -= den.mortgage.payment;
		if (den.mortgage.debt < 0) den.mortgage.debt = 0;
		den.mortgage.months_paid++;
	}
}

void den_savings_func()
{
	RUB save = den.salary * 0.1;
	if (den.bank.account_rub >= save) {
		den.bank.account_rub -= save;
		den.total_savings += save;
		den.bank.account_rub += save * 0.01;
	}
}

void den_personal_expenses(int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) {
		den.bank.account_rub -= den.haircut;
	}
	den.bank.account_rub -= den.lunch_work;
	den.bank.account_rub -= den.charity;
	if (month == 2 || month == 5 || month == 8 || month == 11) {
		den.bank.account_rub -= den.gifts;
	}
}

void den_fun_func(int month)
{
	if (month == 7 || month == 8) {
		den.bank.account_rub -= den.fun * 2;
	}
	den.bank.account_rub -= den.fun;
}

void den_bonus_events(int month, int year)
{
	if (month == 5 && year == 2027) {
		den.bank.account_rub += 12000;
	}
	if (month == 5 && year == 2028) {
		den.bank.account_rub += 13000;
	}
	if (month == 5 && year == 2029) {
		den.bank.account_rub += 14000;
	}
}

void den_emergency(int month, int year)
{
	if (month == 4 && year == 2027) {
		den.bank.account_rub -= 15000;
	}
	if (month == 8 && year == 2028) {
		den.bank.account_rub -= 20000;
	}
	if (month == 2 && year == 2029) {
		den.bank.account_rub -= 5000;
	}
}

void den_vacation_func(int month, int year)
{
	if (month == 8 && year == 2027) {
		den_vacation_summer();
	}
	if (month == 8 && year == 2028) {
		den_vacation_summer();
	}
}

void den_simulation()
{
	int year = 2026;
	int month = 2;
	while (!(year == 2029 && month == 2)) {
		if (month == 1) {
			den_inflation_after();
		}
		den_salary_func(month, year);
		den_food_rice();
		den_food_buckwheat();
		den_food_oatmeal();
		den_food_potatoes();
		den_food_carrots();
		den_food_onion();
		den_food_garlic();
		den_food_cabbage();
		den_food_tomatoes();
		den_food_cucumbers();
		den_food_apples();
		den_food_bananas();
		den_food_chicken();
		den_food_pork();
		den_food_beef();
		den_food_cheese();
		den_food_tvorog();
		den_food_butter();
		den_food_eggs();
		den_food_milk();
		den_food_oil();
		den_food_tea();
		den_food_coffee();
		den_food_salt();
		den_food_pepper();
		den_food_sugar();
		den_food_flour();
		den_food_pasta();
		den_food_canned();
		den_food_fish();
		den_food_sausage();
		den_food_bread();
		den_food_juice();
		den_food_water();
		den_food_honey();
		den_food_nuts();
		den_food_dried_fruits();
		if (month == 1) { den_utilities_jan(); }
		if (month == 2) { den_utilities_feb(); }
		if (month == 3) { den_utilities_mar(); }
		if (month == 4) { den_utilities_apr(); }
		if (month == 5) { den_utilities_may(); }
		if (month == 6) { den_utilities_jun(); }
		if (month == 7) { den_utilities_jul(); }
		if (month == 8) { den_utilities_aug(); }
		if (month == 9) { den_utilities_sep(); }
		if (month == 10) { den_utilities_oct(); }
		if (month == 11) { den_utilities_nov(); }
		if (month == 12) { den_utilities_dec(); }
		if (month == 1 || month == 4 || month == 7 || month == 10) {
			den_household_washing();
			den_household_shower_gel();
			den_household_shampoo();
			den_household_razor();
			den_household_trash_bags();
			den_household_cleaning_spray();
			den_household_sponge();
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) {
			den_household_toilet_paper();
			den_household_foil();
			den_household_cling_film();
		}
		if (month == 2 || month == 5 || month == 8 || month == 11) {
			den_household_toothpaste();
			den_household_deodorant();
			den_household_dish_soap();
		}
		if (month == 3 || month == 9) {
			den_household_toothbrush();
		}
		if (month == 4 || month == 10) {
			den_household_paper_towels();
		}
		if (month == 6 || month == 12) {
			den_household_softener();
			den_household_batteries();
		}
		den_health_fitness();
		if (month == 2 || month == 5 || month == 8 || month == 11) {
			den_health_medicines();
		}
		if (month == 1 || month == 4 || month == 7 || month == 10) {
			den_health_vitamins();
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) {
			den_lifestyle_bar();
		}
		if (month == 2 || month == 4 || month == 6 || month == 8 || month == 10 || month == 12) {
			den_lifestyle_billiards();
		}
		if (month == 8) {
			den_lifestyle_bowling();
		}
		if (month == 12) {
			den_lifestyle_hookah();
		}
		if (month == 3 || month == 9) {
			den_shopping_clothes();
		}
		if (month == 5 || month == 11) {
			den_shopping_shoes();
		}
		if (month == 6) {
			den_shopping_tools();
		}
		if (month == 12) {
			den_shopping_electronics();
		}
		if (month == 1) {
			den_shopping_sport();
		}
		den_development_yandex();
		den_development_t2();
		den_development_youtube();
		if (month == 3 || month == 9) {
			den_development_books();
		}
		den_pets_dog_food();
		if (month == 6) {
			den_pets_dog_toys();
		}
		if (month == 9) {
			den_pets_dog_vet();
		}
		den_car_gas();
		if (month == 6) {
			den_car_maintenance();
		}
		if (month == 10) {
			den_car_tires();
		}
		if (month == 1) {
			den_car_insurance();
		}
		if (month == 3) {
			den_car_tax();
		}
		den_mortgage_func();
		den_personal_expenses(month);
		den_fun_func(month);
		den_savings_func();
		den_bonus_events(month, year);
		den_emergency(month, year);
		den_vacation_func(month, year);
		month++;
		if (month == 13) {
			year++;
			month = 1;
		}
	}
}

void print_results()
{
	printf("Alice\n");
	printf("Final Monthly Salary: %lld RUB\n", alice.salary);

	RUB alice_capital = 0;
	alice_capital += alice.bank.account_rub;
	alice_capital += alice.bank.account_usd * alice.bank.rate_usd_rub;
	alice_capital += alice.car.value;
	printf("Total Capital: %lld RUB\n", alice_capital);
	printf("Savings Account: %lld RUB\n", alice.total_savings);
	printf("Bank Deposit: %lld RUB\n", alice.deposit.amount, alice.deposit.total_deposited);
	printf("USD Investment: %lld USD\n", alice.total_investment_usd);
	printf("Car Value: %lld RUB\n", alice.car.value);
	printf("RUB Balance: %lld RUB\n", alice.bank.account_rub);
	printf("USD Balance: %lld USD\n", alice.bank.account_usd);
	if (alice.credit.debt > 0) {
		printf("Credit Remaining: %lld RUB\n", alice.credit.debt);
	}

	RUB alice_food_total =
		alice.food_stock.rice + alice.food_stock.buckwheat + alice.food_stock.oatmeal +
		alice.food_stock.potatoes + alice.food_stock.carrots + alice.food_stock.onion +
		alice.food_stock.garlic + alice.food_stock.cabbage + alice.food_stock.tomatoes +
		alice.food_stock.cucumbers + alice.food_stock.apples + alice.food_stock.bananas +
		alice.food_stock.chicken_breast + alice.food_stock.pork + alice.food_stock.beef +
		alice.food_stock.cheese + alice.food_stock.tvorog + alice.food_stock.butter +
		alice.food_stock.eggs + alice.food_stock.milk + alice.food_stock.vegetable_oil +
		alice.food_stock.tea + alice.food_stock.coffee + alice.food_stock.salt +
		alice.food_stock.pepper + alice.food_stock.sugar + alice.food_stock.flour +
		alice.food_stock.pasta + alice.food_stock.canned_food + alice.food_stock.fish +
		alice.food_stock.sausage + alice.food_stock.bread + alice.food_stock.juice +
		alice.food_stock.water + alice.food_stock.honey + alice.food_stock.nuts +
		alice.food_stock.dried_fruits;
	printf("Monthly Food: %lld RUB\n", alice_food_total);
	printf("Monthly Utilities: %lld RUB\n", alice.utils.electricity + alice.utils.water_cold + alice.utils.water_hot + alice.utils.gas_supply + alice.utils.sewer + alice.utils.tv);
	printf("Monthly Housing Services: %lld RUB\n", alice.utils.capital_repair + alice.utils.garbage + alice.utils.internet + alice.utils.intercom);
	printf("Monthly Fitness: %lld RUB\n", alice.health.fitness);
	printf("Monthly Personal Care: %lld RUB\n", alice.haircut + alice.coffee_takeaway + alice.taxi);
	printf("Monthly Lunch Work: %lld RUB\n", alice.lunch_work);
	printf("Monthly Beauty: %lld RUB\n", alice.manicure + alice.cosmetologist);
	printf("Monthly Psychologist: %lld RUB\n", alice.psychologist);
	printf("Monthly Charity: %lld RUB\n", alice.charity);
	printf("\n");

	printf("Den\n");
	printf("Final Monthly Salary: %lld RUB\n", den.salary);

	RUB den_capital = 0;
	den_capital += den.bank.account_rub;
	den_capital += den.bank.account_usd * den.bank.rate_usd_rub;
	den_capital += den.car.value;
	printf("Total Capital: %lld RUB\n", den_capital);
	printf("Savings Account: %lld RUB\n", den.total_savings);
	printf("Car Value: %lld RUB\n", den.car.value);
	printf("RUB Balance: %lld RUB\n", den.bank.account_rub);
	if (den.mortgage.debt > 0) {
		printf("Mortgage Remaining: %lld RUB (%d months paid)\n", den.mortgage.debt, den.mortgage.months_paid);
	}

	RUB den_food_total =
		den.food_stock.rice + den.food_stock.buckwheat + den.food_stock.oatmeal +
		den.food_stock.potatoes + den.food_stock.carrots + den.food_stock.onion +
		den.food_stock.garlic + den.food_stock.cabbage + den.food_stock.tomatoes +
		den.food_stock.cucumbers + den.food_stock.apples + den.food_stock.bananas +
		den.food_stock.chicken_breast + den.food_stock.pork + den.food_stock.beef +
		den.food_stock.cheese + den.food_stock.tvorog + den.food_stock.butter +
		den.food_stock.eggs + den.food_stock.milk + den.food_stock.vegetable_oil +
		den.food_stock.tea + den.food_stock.coffee + den.food_stock.salt +
		den.food_stock.pepper + den.food_stock.sugar + den.food_stock.flour +
		den.food_stock.pasta + den.food_stock.canned_food + den.food_stock.fish +
		den.food_stock.sausage + den.food_stock.bread + den.food_stock.juice +
		den.food_stock.water + den.food_stock.honey + den.food_stock.nuts +
		den.food_stock.dried_fruits;
	printf("Monthly Food: %lld RUB\n", den_food_total);
	printf("Monthly Utilities: %lld RUB\n", den.utils.electricity + den.utils.water_cold + den.utils.water_hot + den.utils.gas_supply + den.utils.sewer + den.utils.tv);
	printf("Monthly Housing Services: %lld RUB\n", den.utils.capital_repair + den.utils.garbage + den.utils.internet + den.utils.intercom);
	printf("Monthly Fitness: %lld RUB\n", den.health.fitness);
	printf("Monthly Personal Care: %lld RUB\n", den.haircut);
	printf("Monthly Lunch Work: %lld RUB\n", den.lunch_work);
	printf("Monthly Gifts: %lld RUB\n", den.gifts);
	printf("Monthly Bar & Billiards: %lld RUB\n", den.lifestyle.bar + den.lifestyle.billiards);
	printf("Monthly Charity: %lld RUB\n", den.charity);

	printf("\n\n");
	printf("Alice Total Capital: %lld RUB\n", alice_capital);
	printf("Den Total Capital: %lld RUB\n", den_capital);
	if (alice_capital > den_capital) {
		printf("Alice is richer by %lld RUB\n", alice_capital - den_capital);
	}
	else {
		printf("Denis is richer by %lld RUB\n", den_capital - alice_capital);
	}
	printf("Alice Savings: %lld RUB\n", alice.total_savings);
	printf("Den Savings: %lld RUB\n", den.total_savings);
	printf("Alice Deposit: %lld RUB\n", alice.deposit.amount);
	printf("Den Mortgage Remaining: %lld RUB\n", den.mortgage.debt);
	printf("Alice USD Investment: %lld USD\n", alice.total_investment_usd);
}

int main()
{
	alice_init();
	den_init();
	alice_simulation();
	den_simulation();
	print_results();
}