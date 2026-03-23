#include <stdio.h>

using RUB = long long;

const double INFLATION = 2.0;
const double DEPOSIT_RATE = 14.5;

struct Car {
	RUB value;
	RUB gas;
	RUB insurance;
	RUB maintenance;
	RUB repairs;
	RUB car_wash;
	RUB parking;
	RUB tires;
	RUB tax;
};

struct Bus {
	RUB single_trip;
	RUB monthly_pass;
	RUB long_distance_trips;
	RUB luggage;
	RUB fines;
	RUB station_snacks;
	RUB taxi_to_station;
	RUB mobile_charging;
};

struct Bicycle {
	RUB value;
	RUB maintenance;
	RUB repairs;
	RUB tires;
	RUB chain;
	RUB brakes;
	RUB lights;
	RUB accessories;
	RUB parking;
	RUB helmet;
};

struct Metro {
	RUB single_trip;
	RUB monthly_pass;
	RUB transport_card;
	RUB card_recharge;
	RUB fines;
	RUB transfer_cost;
	RUB station_snacks;
	RUB luggage;
};

struct Tram {
	RUB single_trip;
	RUB monthly_pass;
	RUB transport_card;
	RUB card_recharge;
	RUB fines;
	RUB luggage;
	RUB station_snacks;
	RUB transfer_cost;
};

struct Airplane {
	RUB tickets;
	RUB luggage;
	RUB additional_baggage;
	RUB insurance;
	RUB airport_transfer;
	RUB onboard_food;
	RUB hotel;
	RUB visa;
	RUB taxi_abroad;
	RUB souvenirs;
};

struct Bank {
	RUB account;
	RUB deposit;
};

struct Dog {
	RUB food;
	RUB vet;
	RUB toys;
	RUB grooming;
	RUB medicine;
	RUB training;
};

struct Cat {
	RUB food;
	RUB vet;
	RUB litter;
	RUB toys;
	RUB scratching_post;
	RUB medicine;
};

struct Parrot {
	RUB food;
	RUB vet;
	RUB cage;
	RUB toys;
	RUB vitamins;
	RUB filler;
};

struct Fish {
	RUB food;
	RUB aquarium;
	RUB filter;
	RUB light;
	RUB medicine;
	RUB decorations;
};

struct Food {
	RUB coffee;
	RUB milk;
	RUB oatmeal;
	RUB rice;
	RUB pasta;
	RUB bread;
	RUB	eggs;
	RUB	chicken_fillet;
	RUB	cheese;
	RUB	yogurt;
	RUB	potatoes;
	RUB	onions;
	RUB	tomatoes;
	RUB	apples;
	RUB	bananas;
	RUB	frozen_vegetables;
	RUB	vegetable_oil;
	RUB	legumes;
};

struct Subscriptions {
	RUB youtube_premium;
	RUB spotify;
	RUB netflix;
	RUB yandex_plus;
	RUB telegram_premium;
	RUB chatgpt_plus;
	RUB kinopoisk;
	RUB apple_music;
	RUB google_drive;
	RUB icloud;
	RUB office_365;
	RUB vpn;
	RUB playstation_plus;
	RUB xbox_game_pass;
	RUB adobe;
	RUB github;
	RUB dropbox;
	RUB notion;
	RUB canva;
	RUB duolingo;
};

struct Entertainment {
	RUB cinema;
	RUB concerts;
	RUB theatre;
	RUB cafes;
	RUB restaurants;
	RUB bars;
	RUB books;
	RUB games;
	RUB hobbies;
	RUB streaming_movies;
	RUB museums;
	RUB amusement_parks;
	RUB board_games;
	RUB sports_events;
	RUB trips;
};

struct Transport {
	Car car;
	Bus bus;
	Bicycle bicycle;
	Metro metro;
	Tram tram;
	Airplane airplane;
};

struct Home {
	RUB rent;
	RUB mortgage;
	RUB electricity;
	RUB water;
	RUB heating;
	RUB gas;
	RUB internet;
	RUB mobile;
	RUB cleaning;
	RUB furniture;
	RUB repairs;
	RUB security;
	RUB property_tax;
	RUB household_chemicals;
	RUB appliances;
};

struct Health {
	RUB medicines;
	RUB vitamins;
	RUB dentist;
	RUB therapist;
	RUB tests;
	RUB checkups;
	RUB insurance;
	RUB gym;
	RUB massage;
	RUB psychologist;
	RUB glasses;
	RUB emergency;
	RUB surgery;
	RUB rehabilitation;
};

struct Clothes {
	RUB jackets;
	RUB tshirts;
	RUB shirts;
	RUB jeans;
	RUB trousers;
	RUB shoes;
	RUB sneakers;
	RUB underwear;
	RUB socks;
	RUB hats;
	RUB accessories;
	RUB dry_cleaning;
	RUB bags;
	RUB sportswear;
};

struct Education {
	RUB courses;
	RUB books;
	RUB tutors;
	RUB exams;
	RUB certificates;
	RUB online_platforms;
	RUB stationery;
	RUB seminars;
	RUB conferences;
	RUB language_learning;
	RUB programming_courses;
	RUB design_courses;
};

struct Gifts {
	RUB birthday_family;
	RUB birthday_friends;
	RUB new_year;
	RUB march_8;
	RUB february_23;
	RUB anniversary;
	RUB wedding;
	RUB children;
	RUB corporate;
	RUB surprise_gifts;
};

struct PersonalCare {
	RUB shampoo;
	RUB cosmetics;
	RUB perfume;
	RUB haircut;
	RUB manicure;
	RUB skincare;
	RUB shaving;
	RUB hygiene;
	RUB spa;
	RUB barber;
	RUB dental_care;
	RUB deodorants;
};

struct Hobbies {
	RUB drawing;
	RUB music;
	RUB photography;
	RUB sports;
	RUB fishing;
	RUB collecting;
	RUB gardening;
	RUB diy;
	RUB dancing;
	RUB chess;
	RUB crafting;
	RUB instruments;
};

struct Person {
	RUB salary;
	Food food;
	Subscriptions subscriptions;
	Entertainment entertainment;
	Transport transport;
	Home home;
	Health health;
	Clothes clothes;
	Education education;
	Gifts gifts;
	PersonalCare personal_care;
	Hobbies hobbies;

	Dog dog;
	Cat cat;
	Parrot parrot;
	Fish fish;
	Bank bank;
};

struct PersonConfig {
	RUB salary;
	Food food;
	Subscriptions subscriptions;
	Entertainment entertainment;
	Home home;
	Health health;
	Clothes clothes;
	Education education;
	Gifts gifts;
	PersonalCare personal_care;
	Hobbies hobbies;

	Dog dog;
	Cat cat;
	Parrot parrot;
	Fish fish;
	Transport transport;
};

void person_init(Person& p, const PersonConfig& cfg) {
	p.salary = cfg.salary;
	p.food = cfg.food;
	p.subscriptions = cfg.subscriptions;
	p.entertainment = cfg.entertainment;
	p.home = cfg.home;
	p.health = cfg.health;
	p.clothes = cfg.clothes;
	p.education = cfg.education;
	p.gifts = cfg.gifts;
	p.personal_care = cfg.personal_care;
	p.hobbies = cfg.hobbies;

	p.dog = cfg.dog;
	p.cat = cfg.cat;
	p.parrot = cfg.parrot;
	p.fish = cfg.fish;

	p.transport = cfg.transport;

	p.bank.account = 0;
	p.bank.deposit = 0;
}

RUB total_food(const Food& f) {
	return f.coffee +
		f.milk +
		f.oatmeal +
		f.rice +
		f.pasta +
		f.bread +
		f.eggs +
		f.chicken_fillet +
		f.cheese +
		f.yogurt +
		f.potatoes +
		f.onions +
		f.tomatoes +
		f.apples +
		f.bananas +
		f.frozen_vegetables +
		f.vegetable_oil +
		f.legumes;
}

RUB total_subscriptions(const Subscriptions& s) {
	return s.youtube_premium +
		s.spotify +
		s.netflix +
		s.yandex_plus +
		s.telegram_premium +
		s.chatgpt_plus +
		s.kinopoisk +
		s.apple_music +
		s.google_drive +
		s.icloud +
		s.office_365 +
		s.vpn +
		s.playstation_plus +
		s.xbox_game_pass +
		s.adobe +
		s.github +
		s.dropbox +
		s.notion +
		s.canva +
		s.duolingo;
}

RUB total_entertainment(const Entertainment& e) {
	return e.cinema +
		e.concerts +
		e.theatre +
		e.cafes +
		e.restaurants +
		e.bars +
		e.books +
		e.games +
		e.hobbies +
		e.streaming_movies +
		e.museums +
		e.amusement_parks +
		e.board_games +
		e.sports_events +
		e.trips;
}

RUB total_home(const Home& h) {
	return h.rent +
		h.mortgage +
		h.electricity +
		h.water +
		h.heating +
		h.gas +
		h.internet +
		h.mobile +
		h.cleaning +
		h.furniture +
		h.repairs +
		h.security +
		h.property_tax +
		h.household_chemicals +
		h.appliances;
}

RUB total_health(const Health& h) {
	return h.medicines +
		h.vitamins +
		h.dentist +
		h.therapist +
		h.tests +
		h.checkups +
		h.insurance +
		h.gym +
		h.massage +
		h.psychologist +
		h.glasses +
		h.emergency +
		h.surgery +
		h.rehabilitation;
}

RUB total_clothes(const Clothes& c) {
	return c.jackets +
		c.tshirts +
		c.shirts +
		c.jeans +
		c.trousers +
		c.shoes +
		c.sneakers +
		c.underwear +
		c.socks +
		c.hats +
		c.accessories +
		c.dry_cleaning +
		c.bags +
		c.sportswear;
}

RUB total_education(const Education& e) {
	return e.courses +
		e.books +
		e.tutors +
		e.exams +
		e.certificates +
		e.online_platforms +
		e.stationery +
		e.seminars +
		e.conferences +
		e.language_learning +
		e.programming_courses +
		e.design_courses;
}

RUB total_gifts(const Gifts& g) {
	return g.birthday_family +
		g.birthday_friends +
		g.new_year +
		g.march_8 +
		g.february_23 +
		g.anniversary +
		g.wedding +
		g.children +
		g.corporate +
		g.surprise_gifts;
}

RUB total_personal_care(const PersonalCare& pc) {
	return pc.shampoo +
		pc.cosmetics +
		pc.perfume +
		pc.haircut +
		pc.manicure +
		pc.skincare +
		pc.shaving +
		pc.hygiene +
		pc.spa +
		pc.barber +
		pc.dental_care +
		pc.deodorants +
		pc.spa;
}

RUB total_hobbies(const Hobbies& h) {
	return h.drawing +
		h.music +
		h.photography +
		h.sports +
		h.fishing +
		h.collecting +
		h.gardening +
		h.diy +
		h.dancing +
		h.chess +
		h.crafting +
		h.instruments;
}

RUB total_dog(const Dog& d) {
	return d.food + 
		d.vet + 
		d.toys + 
		d.grooming + 
		d.medicine + 
		d.training;
}

RUB total_cat(const Cat& c) {
	return c.food +
		c.vet +
		c.litter +
		c.toys +
		c.scratching_post +
		c.medicine;
}

RUB total_parrot(const Parrot& p) {
	return p.food +
		p.vet +
		p.cage +
		p.toys +
		p.vitamins +
		p.filler;
}

RUB total_fish(const Fish& f) {
	return f.food +
		f.aquarium +
		f.filter +
		f.light +
		f.medicine +
		f.decorations;
}

RUB total_pets(const Person& p) {
	return total_dog(p.dog) +
		total_cat(p.cat) +
		total_parrot(p.parrot) +
		total_fish(p.fish);
}

RUB total_car(const Car& c) {
	return c.gas +
		c.insurance +
		c.maintenance +
		c.repairs +
		c.car_wash +
		c.parking +
		c.tires +
		c.tax;
}

RUB total_bus(const Bus& b) {
	return b.single_trip +
		b.monthly_pass +
		b.long_distance_trips +
		b.luggage +
		b.fines +
		b.station_snacks +
		b.taxi_to_station +
		b.mobile_charging;
}

RUB total_bicycle(const Bicycle& b) {
	return b.maintenance +
		b.repairs +
		b.tires +
		b.chain +
		b.brakes +
		b.lights +
		b.accessories +
		b.parking +
		b.helmet;
}

RUB total_metro(const Metro& m) {
	return m.single_trip +
		m.monthly_pass +
		m.transport_card +
		m.card_recharge +
		m.fines +
		m.transfer_cost +
		m.station_snacks +
		m.luggage;
}

RUB total_tram(const Tram& t) {
	return t.single_trip +
		t.monthly_pass +
		t.transport_card +
		t.card_recharge +
		t.fines +
		t.luggage +
		t.station_snacks +
		t.transfer_cost;
}

RUB total_airplane(const Airplane& a) {
	return a.tickets +
		a.luggage +
		a.additional_baggage +
		a.insurance +
		a.airport_transfer +
		a.onboard_food +
		a.hotel +
		a.visa +
		a.taxi_abroad +
		a.souvenirs;
}

RUB total_transport(const Transport& t) {
	return total_car(t.car) +
		total_bus(t.bus) +
		total_bicycle(t.bicycle) +
		total_metro(t.metro) +
		total_tram(t.tram) +
		total_airplane(t.airplane);
}

void receive_salary(Person& p, int month, int year) {
	if (month == 12 && year == 2026) {
		p.salary = p.salary * 3 / 2;
	}
	p.bank.account += p.salary;
}

void pay_food(Person& p) {
	p.bank.account -= total_food(p.food);
}

void pay_subscriptions(Person& p) {
	p.bank.account -= total_subscriptions(p.subscriptions);
}

void pay_entertainment(Person& p) {
	p.bank.account -= total_entertainment(p.entertainment);
}

void pay_transport(Person& p) {
	p.bank.account -= total_transport(p.transport);
}

void pay_home(Person& p) {
	p.bank.account -= total_home(p.home);
}

void pay_health(Person& p) {
	p.bank.account -= total_health(p.health);
}

void pay_clothes(Person& p) {
	p.bank.account -= total_clothes(p.clothes);
}

void pay_education(Person& p) {
	p.bank.account -= total_education(p.education);
}

void pay_gifts(Person& p) {
	p.bank.account -= total_gifts(p.gifts);
}

void pay_personal_care(Person& p) {
	p.bank.account -= total_personal_care(p.personal_care);
}

void pay_hobbies(Person& p) {
	p.bank.account -= total_hobbies(p.hobbies);
}

void pay_all_pets(Person& p) {
	p.bank.account -= total_pets(p);
}

void transfer_to_deposit(Person& p, RUB amount) {
	p.bank.account -= amount;
	p.bank.deposit += amount;
}

void deposit_interest(Person& p, double pp) {
	p.bank.deposit += (RUB)(p.bank.deposit * (pp / 12.0 / 100.0));
}

void inflate_food(Food& f, double k) {
	f.coffee = (RUB)(f.coffee * k);
	f.milk = (RUB)(f.milk * k);
	f.oatmeal = (RUB)(f.oatmeal * k);
	f.rice = (RUB)(f.rice * k);
	f.pasta = (RUB)(f.pasta * k);
	f.bread = (RUB)(f.bread * k);
	f.eggs = (RUB)(f.eggs * k);
	f.chicken_fillet = (RUB)(f.chicken_fillet * k);
	f.cheese = (RUB)(f.cheese * k);
	f.yogurt = (RUB)(f.yogurt * k);
	f.potatoes = (RUB)(f.potatoes * k);
	f.onions = (RUB)(f.onions * k);
	f.tomatoes = (RUB)(f.tomatoes * k);
	f.apples = (RUB)(f.apples * k);
	f.bananas = (RUB)(f.bananas * k);
	f.frozen_vegetables = (RUB)(f.frozen_vegetables * k);
	f.vegetable_oil = (RUB)(f.vegetable_oil * k);
	f.legumes = (RUB)(f.legumes * k);
}

void inflate_subscriptions(Subscriptions& s, double k) {
	s.youtube_premium = (RUB)(s.youtube_premium * k);
	s.spotify = (RUB)(s.spotify * k);
	s.netflix = (RUB)(s.netflix * k);
	s.yandex_plus = (RUB)(s.yandex_plus * k);
	s.telegram_premium = (RUB)(s.telegram_premium * k);
	s.chatgpt_plus = (RUB)(s.chatgpt_plus * k);
	s.kinopoisk = (RUB)(s.kinopoisk * k);
	s.apple_music = (RUB)(s.apple_music * k);
	s.google_drive = (RUB)(s.google_drive * k);
	s.icloud = (RUB)(s.icloud * k);
	s.office_365 = (RUB)(s.office_365 * k);
	s.vpn = (RUB)(s.vpn * k);
	s.playstation_plus = (RUB)(s.playstation_plus * k);
	s.xbox_game_pass = (RUB)(s.xbox_game_pass * k);
	s.adobe = (RUB)(s.adobe * k);
	s.github = (RUB)(s.github * k);
	s.dropbox = (RUB)(s.dropbox * k);
	s.notion = (RUB)(s.notion * k);
	s.canva = (RUB)(s.canva * k);
	s.duolingo = (RUB)(s.duolingo * k);
}

void inflate_entertainment(Entertainment& e, double k) {
	e.cinema = (RUB)(e.cinema * k);
	e.concerts = (RUB)(e.concerts * k);
	e.theatre = (RUB)(e.theatre * k);
	e.cafes = (RUB)(e.cafes * k);
	e.restaurants = (RUB)(e.restaurants * k);
	e.bars = (RUB)(e.bars * k);
	e.books = (RUB)(e.books * k);
	e.games = (RUB)(e.games * k);
	e.hobbies = (RUB)(e.hobbies * k);
	e.streaming_movies = (RUB)(e.streaming_movies * k);
	e.museums = (RUB)(e.museums * k);
	e.amusement_parks = (RUB)(e.amusement_parks * k);
	e.board_games = (RUB)(e.board_games * k);
	e.sports_events = (RUB)(e.sports_events * k);
	e.trips = (RUB)(e.trips * k);
}

void inflate_home(Home& h, double k) {
	h.rent = (RUB)(h.rent * k);
	h.mortgage = (RUB)(h.mortgage * k);
	h.electricity = (RUB)(h.electricity * k);
	h.water = (RUB)(h.water * k);
	h.heating = (RUB)(h.heating * k);
	h.gas = (RUB)(h.gas * k);
	h.internet = (RUB)(h.internet * k);
	h.mobile = (RUB)(h.mobile * k);
	h.cleaning = (RUB)(h.cleaning * k);
	h.furniture = (RUB)(h.furniture * k);
	h.repairs = (RUB)(h.repairs * k);
	h.security = (RUB)(h.security * k);
	h.property_tax = (RUB)(h.property_tax * k);
	h.household_chemicals = (RUB)(h.household_chemicals * k);
	h.appliances = (RUB)(h.appliances * k);
}

void inflate_health(Health& h, double k) {
	h.medicines = (RUB)(h.medicines * k);
	h.vitamins = (RUB)(h.vitamins * k);
	h.dentist = (RUB)(h.dentist * k);
	h.therapist = (RUB)(h.therapist * k);
	h.tests = (RUB)(h.tests * k);
	h.checkups = (RUB)(h.checkups * k);
	h.insurance = (RUB)(h.insurance * k);
	h.gym = (RUB)(h.gym * k);
	h.massage = (RUB)(h.massage * k);
	h.psychologist = (RUB)(h.psychologist * k);
	h.glasses = (RUB)(h.glasses * k);
	h.emergency = (RUB)(h.emergency * k);
	h.surgery = (RUB)(h.surgery * k);
	h.rehabilitation = (RUB)(h.rehabilitation * k);
}

void inflate_clothes(Clothes& c, double k) {
	c.jackets = (RUB)(c.jackets * k);
	c.tshirts = (RUB)(c.tshirts * k);
	c.shirts = (RUB)(c.shirts * k);
	c.jeans = (RUB)(c.jeans * k);
	c.trousers = (RUB)(c.trousers * k);
	c.shoes = (RUB)(c.shoes * k);
	c.sneakers = (RUB)(c.sneakers * k);
	c.underwear = (RUB)(c.underwear * k);
	c.socks = (RUB)(c.socks * k);
	c.hats = (RUB)(c.hats * k);
	c.accessories = (RUB)(c.accessories * k);
	c.dry_cleaning = (RUB)(c.dry_cleaning * k);
	c.bags = (RUB)(c.bags * k);
	c.sportswear = (RUB)(c.sportswear * k);
}

void inflate_education(Education& e, double k) {
	e.courses = (RUB)(e.courses * k);
	e.books = (RUB)(e.books * k);
	e.tutors = (RUB)(e.tutors * k);
	e.exams = (RUB)(e.exams * k);
	e.certificates = (RUB)(e.certificates * k);
	e.online_platforms = (RUB)(e.online_platforms * k);
	e.stationery = (RUB)(e.stationery * k);
	e.seminars = (RUB)(e.seminars * k);
	e.conferences = (RUB)(e.conferences * k);
	e.language_learning = (RUB)(e.language_learning * k);
	e.programming_courses = (RUB)(e.programming_courses * k);
	e.design_courses = (RUB)(e.design_courses * k);
}

void inflate_gifts(Gifts& g, double k) {
	g.birthday_family = (RUB)(g.birthday_family * k);
	g.birthday_friends = (RUB)(g.birthday_friends * k);
	g.new_year = (RUB)(g.new_year * k);
	g.march_8 = (RUB)(g.march_8 * k);
	g.february_23 = (RUB)(g.february_23 * k);
	g.anniversary = (RUB)(g.anniversary * k);
	g.wedding = (RUB)(g.wedding * k);
	g.children = (RUB)(g.children * k);
	g.corporate = (RUB)(g.corporate * k);
	g.surprise_gifts = (RUB)(g.surprise_gifts * k);
}

void inflate_personal_care(PersonalCare& pc, double k) {
	pc.shampoo = (RUB)(pc.shampoo * k);
	pc.cosmetics = (RUB)(pc.cosmetics * k);
	pc.perfume = (RUB)(pc.perfume * k);
	pc.haircut = (RUB)(pc.haircut * k);
	pc.manicure = (RUB)(pc.manicure * k);
	pc.skincare = (RUB)(pc.skincare * k);
	pc.shaving = (RUB)(pc.shaving * k);
	pc.hygiene = (RUB)(pc.hygiene * k);
	pc.spa = (RUB)(pc.spa * k);
	pc.barber = (RUB)(pc.barber * k);
	pc.dental_care = (RUB)(pc.dental_care * k);
	pc.deodorants = (RUB)(pc.deodorants * k);
}

void inflate_hobbies(Hobbies& h, double k) {
	h.drawing = (RUB)(h.drawing * k);
	h.music = (RUB)(h.music * k);
	h.photography = (RUB)(h.photography * k);
	h.sports = (RUB)(h.sports * k);
	h.fishing = (RUB)(h.fishing * k);
	h.collecting = (RUB)(h.collecting * k);
	h.gardening = (RUB)(h.gardening * k);
	h.diy = (RUB)(h.diy * k);
	h.dancing = (RUB)(h.dancing * k);
	h.chess = (RUB)(h.chess * k);
	h.crafting = (RUB)(h.crafting * k);
	h.instruments = (RUB)(h.instruments * k);
}

void inflate_car(Car& c, double k) {
	c.value = (RUB)(c.value * k);
	c.gas = (RUB)(c.gas * k);
	c.insurance = (RUB)(c.insurance * k);
	c.maintenance = (RUB)(c.maintenance * k);
	c.repairs = (RUB)(c.repairs * k);
	c.car_wash = (RUB)(c.car_wash * k);
	c.parking = (RUB)(c.parking * k);
	c.tires = (RUB)(c.tires * k);
	c.tax = (RUB)(c.tax * k);
	
}

void inflate_bus(Bus& b, double k) {
	b.single_trip = (RUB)(b.single_trip * k);
	b.monthly_pass = (RUB)(b.monthly_pass * k);
	b.long_distance_trips = (RUB)(b.long_distance_trips * k);
	b.luggage = (RUB)(b.luggage * k);
	b.fines = (RUB)(b.fines * k);
	b.station_snacks = (RUB)(b.station_snacks * k);
	b.taxi_to_station = (RUB)(b.taxi_to_station * k);
	b.mobile_charging = (RUB)(b.mobile_charging * k);
}

void inflate_bicycle(Bicycle& b, double k) {
	b.value = (RUB)(b.value * k);
	b.maintenance = (RUB)(b.maintenance * k);
	b.repairs = (RUB)(b.repairs * k);
	b.tires = (RUB)(b.tires * k);
	b.chain = (RUB)(b.chain * k);
	b.brakes = (RUB)(b.brakes * k);
	b.lights = (RUB)(b.lights * k);
	b.accessories = (RUB)(b.accessories * k);
	b.parking = (RUB)(b.parking * k);
	b.helmet = (RUB)(b.helmet * k);
}

void inflate_metro(Metro& m, double k) {
	m.single_trip = (RUB)(m.single_trip * k);
	m.monthly_pass = (RUB)(m.monthly_pass * k);
	m.transport_card = (RUB)(m.transport_card * k);
	m.card_recharge = (RUB)(m.card_recharge * k);
	m.fines = (RUB)(m.fines * k);
	m.transfer_cost = (RUB)(m.transfer_cost * k);
	m.station_snacks = (RUB)(m.station_snacks * k);
	m.luggage = (RUB)(m.luggage * k);
}

void inflate_tram(Tram& t, double k) {
	t.single_trip = (RUB)(t.single_trip * k);
	t.monthly_pass = (RUB)(t.monthly_pass * k);
	t.transport_card = (RUB)(t.transport_card * k);
	t.card_recharge = (RUB)(t.card_recharge * k);
	t.fines = (RUB)(t.fines * k);
	t.luggage = (RUB)(t.luggage * k);
	t.station_snacks = (RUB)(t.station_snacks * k);
	t.transfer_cost = (RUB)(t.transfer_cost * k);
}

void inflate_airplane(Airplane& a, double k) {
	a.tickets = (RUB)(a.tickets * k);
	a.luggage = (RUB)(a.luggage * k);
	a.additional_baggage = (RUB)(a.additional_baggage * k);
	a.insurance = (RUB)(a.insurance * k);
	a.airport_transfer = (RUB)(a.airport_transfer * k);
	a.onboard_food = (RUB)(a.onboard_food * k);
	a.hotel = (RUB)(a.hotel * k);
	a.visa = (RUB)(a.visa * k);
	a.taxi_abroad = (RUB)(a.taxi_abroad * k);
	a.souvenirs = (RUB)(a.souvenirs * k);
}

void inflate_dog(Dog& d, double k) {
	d.food = (RUB)(d.food * k);
	d.vet = (RUB)(d.vet * k);
	d.toys = (RUB)(d.toys * k);
	d.grooming = (RUB)(d.grooming * k);
	d.medicine = (RUB)(d.medicine * k);
	d.training = (RUB)(d.training * k);
}

void inflate_cat(Cat& c, double k) {
	c.food = (RUB)(c.food * k);
	c.vet = (RUB)(c.vet * k);
	c.litter = (RUB)(c.litter * k);
	c.toys = (RUB)(c.toys * k);
	c.scratching_post = (RUB)(c.scratching_post * k);
	c.medicine = (RUB)(c.medicine * k);
}

void inflate_parrot(Parrot& p, double k) {
	p.food = (RUB)(p.food * k);
	p.vet = (RUB)(p.vet * k);
	p.cage = (RUB)(p.cage * k);
	p.toys = (RUB)(p.toys * k);
	p.vitamins = (RUB)(p.vitamins * k);
	p.filler = (RUB)(p.filler * k);
}

void inflate_fish(Fish& f, double k) {
	f.food = (RUB)(f.food * k);
	f.aquarium = (RUB)(f.aquarium * k);
	f.filter = (RUB)(f.filter * k);
	f.light = (RUB)(f.light * k);
	f.medicine = (RUB)(f.medicine * k);
	f.decorations = (RUB)(f.decorations * k);
}

void apply_inflation(Person& p, double inflation_pp) {
	double k = 1.0 + inflation_pp / 12.0 / 100.0;

	inflate_food(p.food, k);
	inflate_subscriptions(p.subscriptions, k);
	inflate_entertainment(p.entertainment, k);
	inflate_home(p.home, k);
	inflate_health(p.health, k);
	inflate_clothes(p.clothes, k);
	inflate_education(p.education, k);
	inflate_gifts(p.gifts, k);
	inflate_personal_care(p.personal_care, k);
	inflate_hobbies(p.hobbies, k);
	inflate_car(p.transport.car, k);
	inflate_bus(p.transport.bus, k);
	inflate_bicycle(p.transport.bicycle, k);
	inflate_metro(p.transport.metro, k);
	inflate_tram(p.transport.tram, k);
	inflate_airplane(p.transport.airplane, k);
	inflate_dog(p.dog, k);
	inflate_cat(p.cat, k);
	inflate_parrot(p.parrot, k);
	inflate_fish(p.fish, k);
}

void print_food(const Food& f) {
	printf("food total=%lld\n", total_food(f));

	printf("food:\n");
	printf("coffee=%lld, milk=%lld, oatmeal=%lld, rice=%lld, pasta=%lld, bread=%lld\n",
		f.coffee,
		f.milk,
		f.oatmeal,
		f.rice,
		f.pasta,
		f.bread
	);

	printf("eggs=%lld, chicken_fillet=%lld, cheese=%lld, yogurt=%lld\n",
		f.eggs,
		f.chicken_fillet,
		f.cheese,
		f.yogurt
	);

	printf("potatoes=%lld, onions=%lld, tomatoes=%lld, apples=%lld, bananas=%lld\n",
		f.potatoes,
		f.onions,
		f.tomatoes,
		f.apples,
		f.bananas
	);

	printf("frozen_vegetables=%lld, vegetable_oil=%lld, legumes=%lld\n",
		f.frozen_vegetables,
		f.vegetable_oil,
		f.legumes
	);
}

void print_subscriptions(const Subscriptions& s) {
	printf("subscriptions total=%lld\n", total_subscriptions(s));
	printf("subscriptions:\n");

	printf("youtube_premium=%lld, spotify=%lld, netflix=%lld, yandex_plus=%lld, telegram_premium=%lld\n",
		s.youtube_premium,
		s.spotify,
		s.netflix,
		s.yandex_plus,
		s.telegram_premium
	);
	printf("chatgpt_plus=%lld, kinopoisk=%lld, apple_music=%lld, google_drive=%lld, icloud=%lld\n",
		s.chatgpt_plus,
		s.kinopoisk,
		s.apple_music,
		s.google_drive,
		s.icloud
	);
	printf("office_365=%lld, vpn=%lld, playstation_plus=%lld, xbox_game_pass=%lld, adobe=%lld\n",
		s.office_365,
		s.vpn,
		s.playstation_plus,
		s.xbox_game_pass,
		s.adobe
	);
	printf("github=%lld, dropbox=%lld, notion=%lld, canva=%lld, duolingo=%lld\n",
		s.github,
		s.dropbox,
		s.notion,
		s.canva,
		s.duolingo
	);
}

void print_entertainment(const Entertainment& e) {
	printf("entertainment total=%lld\n", total_entertainment(e));
	printf("entertainment:\n");
	printf("cinema=%lld, concerts=%lld, theatre=%lld, cafes=%lld, restaurants=%lld\n",
		e.cinema,
		e.concerts,
		e.theatre,
		e.cafes,
		e.restaurants
	);
	printf("bars=%lld, books=%lld, games=%lld, hobbies=%lld, streaming_movies=%lld\n",
		e.bars,
		e.books,
		e.games,
		e.hobbies,
		e.streaming_movies
	);
	printf("museums=%lld, amusement_parks=%lld, board_games=%lld, sports_events=%lld, trips=%lld\n",
		e.museums,
		e.amusement_parks,
		e.board_games,
		e.sports_events,
		e.trips
	);
}

void print_home(const Home& h) {
	printf("home total=%lld\n", total_home(h));
	printf("home:\n");
	printf("rent=%lld, mortgage=%lld, electricity=%lld, water=%lld, heating=%lld, gas=%lld\n",
		h.rent,
		h.mortgage,
		h.electricity,
		h.water,
		h.heating,
		h.gas
	);
	printf("internet=%lld, mobile=%lld, cleaning=%lld, furniture=%lld, repairs=%lld\n",
		h.internet,
		h.mobile,
		h.cleaning,
		h.furniture,
		h.repairs
	);
	printf("security=%lld, property_tax=%lld, household_chemicals=%lld, appliances=%lld\n",
		h.security,
		h.property_tax,
		h.household_chemicals,
		h.appliances
	);
}

void print_health(const Health& h) {
	printf("health total=%lld\n", total_health(h));
	printf("health:\n");
	printf("medicines=%lld, vitamins=%lld, dentist=%lld, therapist=%lld, tests=%lld\n",
		h.medicines,
		h.vitamins,
		h.dentist,
		h.therapist,
		h.tests
	);
	printf("checkups=%lld, insurance=%lld, gym=%lld, massage=%lld, psychologist=%lld\n",
		h.checkups,
		h.insurance,
		h.gym,
		h.massage,
		h.psychologist
	);
	printf("glasses=%lld, emergency=%lld, surgery=%lld, rehabilitation=%lld\n",
		h.glasses,
		h.emergency,
		h.surgery,
		h.rehabilitation
	);
}

void print_clothes(const Clothes& c) {
	printf("clothes total=%lld\n", total_clothes(c));
	printf("clothes:\n");
	printf("jackets=%lld, tshirts=%lld, shirts=%lld, jeans=%lld, trousers=%lld\n",
		c.jackets,
		c.tshirts,
		c.shirts,
		c.jeans,
		c.trousers
	);
	printf("shoes=%lld, sneakers=%lld, underwear=%lld, socks=%lld, hats=%lld\n",
		c.shoes,
		c.sneakers,
		c.underwear,
		c.socks,
		c.hats
	);
	printf("accessories=%lld, dry_cleaning=%lld, bags=%lld, sportswear=%lld\n",
		c.accessories,
		c.dry_cleaning,
		c.bags,
		c.sportswear
	);
}

void print_education(const Education& e) {
	printf("education total=%lld\n", total_education(e));
	printf("education:\n");
	printf("courses=%lld, books=%lld, tutors=%lld, exams=%lld, certificates=%lld\n",
		e.courses,
		e.books,
		e.tutors,
		e.exams,
		e.certificates
	);
	printf("online_platforms=%lld, stationery=%lld, seminars=%lld, conferences=%lld, language_learning=%lld\n",
		e.online_platforms,
		e.stationery,
		e.seminars,
		e.conferences,
		e.language_learning
	);
	printf("programming_courses=%lld, design_courses=%lld\n",
		e.programming_courses,
		e.design_courses
	);
}

void print_gifts(const Gifts& g) {
	printf("gifts total=%lld\n", total_gifts(g));
	printf("gifts:\n");
	printf("birthday_family=%lld, birthday_friends=%lld, new_year=%lld, march_8=%lld, february_23=%lld\n",
		g.birthday_family,
		g.birthday_friends,
		g.new_year,
		g.march_8,
		g.february_23
	);
	printf("anniversary=%lld, wedding=%lld, children=%lld, corporate=%lld, surprise_gifts=%lld\n",
		g.anniversary,
		g.wedding,
		g.children,
		g.corporate,
		g.surprise_gifts
	);
}

void print_personal_care(const PersonalCare& pc) {
	printf("personal care total=%lld\n", total_personal_care(pc));
	printf("personal care:\n");
	printf("shampoo=%lld, cosmetics=%lld, perfume=%lld, haircut=%lld, manicure=%lld\n",
		pc.shampoo,
		pc.cosmetics,
		pc.perfume,
		pc.haircut,
		pc.manicure
	);
	printf("skincare=%lld, shaving=%lld, hygiene=%lld, spa=%lld, barber=%lld\n",
		pc.skincare,
		pc.shaving,
		pc.hygiene,
		pc.spa,
		pc.barber
	);
	printf("dental_care=%lld, deodorants=%lld\n",
		pc.dental_care,
		pc.deodorants
	);
}

void print_hobbies(const Hobbies& h) {
	printf("hobbies total=%lld\n", total_hobbies(h));
	printf("hobbies:\n");
	printf("drawing=%lld, music=%lld, photography=%lld, sports=%lld, fishing=%lld\n",
		h.drawing,
		h.music,
		h.photography,
		h.sports,
		h.fishing
	);
	printf("collecting=%lld, gardening=%lld, diy=%lld, dancing=%lld, chess=%lld\n",
		h.collecting,
		h.gardening,
		h.diy,
		h.dancing,
		h.chess
	);
	printf("crafting=%lld, instruments=%lld\n",
		h.crafting,
		h.instruments
	);
}

void print_dog(const Dog& d) {
	printf("dog total=%lld\n", total_dog(d));
	printf("dog:\n");
	printf("food=%lld, vet=%lld, toys=%lld, grooming=%lld, medicine=%lld, training=%lld\n",
		d.food,
		d.vet,
		d.toys,
		d.grooming,
		d.medicine,
		d.training
	);
}

void print_cat(const Cat& c) {
	printf("cat total=%lld\n", total_cat(c));
	printf("cat:\n");
	printf("food=%lld, vet=%lld, litter=%lld, toys=%lld, scratching_post=%lld, medicine=%lld\n",
		c.food,
		c.vet,
		c.litter,
		c.toys,
		c.scratching_post,
		c.medicine
	);
}

void print_parrot(const Parrot& p) {
	printf("parrot total=%lld\n", total_parrot(p));
	printf("parrot:\n");
	printf("food=%lld, vet=%lld, cage=%lld, toys=%lld, vitamins=%lld, filler=%lld\n",
		p.food,
		p.vet,
		p.cage,
		p.toys,
		p.vitamins,
		p.filler
	);
}

void print_fish(const Fish& f) {
	printf("fish total=%lld\n", total_fish(f));
	printf("fish:\n");
	printf("food=%lld, aquarium=%lld, filter=%lld, light=%lld, medicine=%lld, decorations=%lld\n",
		f.food,
		f.aquarium,
		f.filter,
		f.light,
		f.medicine,
		f.decorations
	);
}

void print_car(const Car& c) {
	printf("car total=%lld\n", total_car(c));
	printf("car:\n");
	printf("value=%lld, gas=%lld, insurance=%lld, maintenance=%lld, repairs=%lld, car_wash=%lld, parking=%lld, tires=%lld, tax=%lld\n",
		c.value,
		c.gas,
		c.insurance,
		c.maintenance,
		c.repairs,
		c.car_wash,
		c.parking,
		c.tires,
		c.tax
	);
}

void print_bus(const Bus& b) {
	printf("bus total=%lld\n", total_bus(b));
	printf("bus:\n");
	printf("single_trip=%lld, monthly_pass=%lld, long_distance_trips=%lld, luggage=%lld, fines=%lld, station_snacks=%lld, taxi_to_station=%lld, mobile_charging=%lld\n",
		b.single_trip,
		b.monthly_pass,
		b.long_distance_trips,
		b.luggage,
		b.fines,
		b.station_snacks,
		b.taxi_to_station,
		b.mobile_charging
	);
}

void print_bicycle(const Bicycle& b) {
	printf("bicycle total=%lld\n", total_bicycle(b));
	printf("bicycle:\n");
	printf("value=%lld, maintenance=%lld, repairs=%lld, tires=%lld, chain=%lld, brakes=%lld, lights=%lld, accessories=%lld, parking=%lld, helmet=%lld\n",
		b.value,
		b.maintenance,
		b.repairs,
		b.tires,
		b.chain,
		b.brakes,
		b.lights,
		b.accessories,
		b.parking,
		b.helmet
	);
}

void print_metro(const Metro& m) {
	printf("metro total=%lld\n", total_metro(m));
	printf("metro:\n");
	printf("single_trip=%lld, monthly_pass=%lld, transport_card=%lld, card_recharge=%lld, fines=%lld, transfer_cost=%lld, station_snacks=%lld, luggage=%lld\n",
		m.single_trip,
		m.monthly_pass,
		m.transport_card,
		m.card_recharge,
		m.fines,
		m.transfer_cost,
		m.station_snacks,
		m.luggage
	);
}

void print_tram(const Tram& t) {
	printf("tram total=%lld\n", total_tram(t));
	printf("tram:\n");
	printf("single_trip=%lld, monthly_pass=%lld, transport_card=%lld, card_recharge=%lld, fines=%lld, luggage=%lld, station_snacks=%lld, transfer_cost=%lld\n",
		t.single_trip,
		t.monthly_pass,
		t.transport_card,
		t.card_recharge,
		t.fines,
		t.luggage,
		t.station_snacks,
		t.transfer_cost
	);
}

void print_airplane(const Airplane& a) {
	printf("airplane total=%lld\n", total_airplane(a));
	printf("airplane:\n");
	printf("tickets=%lld, luggage=%lld, additional_baggage=%lld, insurance=%lld, airport_transfer=%lld, onboard_food=%lld, hotel=%lld, visa=%lld, taxi_abroad=%lld, souvenirs=%lld\n",
		a.tickets,
		a.luggage,
		a.additional_baggage,
		a.insurance,
		a.airport_transfer,
		a.onboard_food,
		a.hotel,
		a.visa,
		a.taxi_abroad,
		a.souvenirs
	);
}

void print_results(const Person& p) {
	printf("salary=%lld\n", p.salary);
	printf("account=%lld\n", p.bank.account);
	printf("deposit=%lld\n", p.bank.deposit);

	printf("\n");
	print_food(p.food);

	printf("\n");
	print_subscriptions(p.subscriptions);

	printf("\n");
	print_entertainment(p.entertainment);

	printf("\n");
	print_home(p.home);

	printf("\n");
	print_health(p.health);

	printf("\n");
	print_clothes(p.clothes);

	printf("\n");
	print_education(p.education);

	printf("\n");
	print_gifts(p.gifts);

	printf("\n");
	print_personal_care(p.personal_care);

	printf("\n");
	print_hobbies(p.hobbies);

	printf("\n");
	print_car(p.transport.car);

	printf("\n");
	print_bus(p.transport.bus);

	printf("\n");
	print_bicycle(p.transport.bicycle);

	printf("\n");
	print_metro(p.transport.metro);

	printf("\n");
	print_tram(p.transport.tram);

	printf("\n");
	print_airplane(p.transport.airplane);

	printf("\n");
	print_dog(p.dog);

	printf("\n");
	print_cat(p.cat);

	printf("\n");
	print_parrot(p.parrot);

	printf("\n");
	print_fish(p.fish);

	printf("\npets total=%lld\n", total_pets(p));
}


void simulation(Person& p) {
	int month = 10;
	int year = 2026;

	while (!(month == 11 && year == 2027)) {
		apply_inflation(p, INFLATION);
		deposit_interest(p, DEPOSIT_RATE);
		pay_food(p);
		pay_subscriptions(p);
		pay_entertainment(p);
		pay_home(p);
		pay_health(p);
		pay_clothes(p);
		pay_education(p);
		pay_gifts(p);
		pay_personal_care(p);
		pay_hobbies(p);
		pay_transport(p);
		pay_all_pets(p);
		transfer_to_deposit(p, 50000);
		receive_salary(p, month, year);

		++month;
		if (month == 13) {
			month = 1;
			++year;
		}
	}
}

int main() {
	Person Epstein;
	Person Trump;

	printf("NEW BUILD 12347\n");

	PersonConfig epstein_cfg = {
		200000, // salary

		{ // food
			1200, // coffee
			900,  // milk
			500,  // oatmeal
			700,  // rice
			800,  // pasta
			1000, // bread
			1200, // eggs
			3500, // chicken_fillet
			1800, // cheese
			900,  // yogurt
			700,  // potatoes
			400,  // onions
			1200, // tomatoes
			1300, // apples
			900,  // bananas
			1000, // frozen_vegetables
			500,  // vegetable_oil
			700   // legumes
		},

		{ // subscriptions
			0,    // youtube_premium
			169,  // spotify
			0,    // netflix
			399,  // yandex_plus
			0,    // telegram_premium
			0,    // chatgpt_plus
			299,  // kinopoisk
			0,    // apple_music
			99,   // google_drive
			99,   // icloud
			0,    // office_365
			150,  // vpn
			0,    // playstation_plus
			0,    // xbox_game_pass
			0,    // adobe
			0,    // github
			0,    // dropbox
			0,    // notion
			0,    // canva
			0     // duolingo
		},

		{ // entertainment
			600,  // cinema
			0,    // concerts
			0,    // theatre
			1500, // cafes
			2000, // restaurants
			0,    // bars
			300,  // books
			500,  // games
			700,  // hobbies
			300,  // streaming_movies
			0,    // museums
			0,    // amusement_parks
			300,  // board_games
			0,    // sports_events
			1000  // trips
		},

		{ // home
			25000, // rent
			0,     // mortgage
			2500,  // electricity
			800,   // water
			1500,  // heating
			300,   // gas
			700,   // internet
			700,   // mobile
			500,   // cleaning
			500,   // furniture
			500,   // repairs
			0,     // security
			0,     // property_tax
			1000,  // household_chemicals
			500    // appliances
		},

		{ // health
			500,  // medicines
			300,  // vitamins
			500,  // dentist
			0,    // therapist
			500,  // tests
			300,  // checkups
			0,    // insurance
			1500, // gym
			0,    // massage
			0,    // psychologist
			0,    // glasses
			500,  // emergency
			0,    // surgery
			0     // rehabilitation
		},

		{ // clothes
			0,    // jackets
			500,  // tshirts
			300,  // shirts
			800,  // jeans
			500,  // trousers
			1000, // shoes
			1000, // sneakers
			500,  // underwear
			300,  // socks
			0,    // hats
			300,  // accessories
			0,    // dry_cleaning
			0,    // bags
			500   // sportswear
		},

		{ // education
			0,    // courses
			300,  // books
			0,    // tutors
			0,    // exams
			0,    // certificates
			0,    // online_platforms
			100,  // stationery
			0,    // seminars
			0,    // conferences
			500,  // language_learning
			0,    // programming_courses
			0     // design_courses
		},

		{ // gifts
			500,  // birthday_family
			300,  // birthday_friends
			500,  // new_year
			300,  // march_8
			300,  // february_23
			0,    // anniversary
			0,    // wedding
			300,  // children
			0,    // corporate
			300   // surprise_gifts
		},

		{ // personal_care
			300,  // shampoo
			500,  // cosmetics
			0,    // perfume
			800,  // haircut
			0,    // manicure
			500,  // skincare
			200,  // shaving
			500,  // hygiene
			0,    // spa
			0,    // barber
			300,  // dental_care
			200   // deodorants
		},

		{ // hobbies
			0,    // drawing
			300,  // music
			0,    // photography
			500,  // sports
			0,    // fishing
			0,    // collecting
			0,    // gardening
			200,  // diy
			0,    // dancing
			100,  // chess
			200,  // crafting
			0     // instruments
		},

		{ // dog
			0, // food
			0, // vet
			0, // toys
			0, // grooming
			0, // medicine
			0  // training
		},

		{ // cat
			1500, // food
			300,  // vet
			400,  // litter
			100,  // toys
			0,    // scratching_post
			200   // medicine
		},

		{ // parrot
			0, // food
			0, // vet
			0, // cage
			0, // toys
			0, // vitamins
			0  // filler
		},

		{ // fish
			0, // food
			0, // aquarium
			0, // filter
			0, // light
			0, // medicine
			0  // decorations
		},

		{ // transport
			{ // car
				0, // value
				0, // gas
				0, // insurance
				0, // maintenance
				0, // repairs
				0, // car_wash
				0, // parking
				0, // tires
				0  // tax
			},

			{ // bus
				0,   // single_trip
				0,   // monthly_pass
				0,   // long_distance_trips
				0,   // luggage
				0,   // fines
				0,   // station_snacks
				0,   // taxi_to_station
				0    // mobile_charging
			},

			{ // bicycle
				0, // value
				0, // maintenance
				0, // repairs
				0, // tires
				0, // chain
				0, // brakes
				0, // lights
				0, // accessories
				0, // parking
				0  // helmet
			},

			{ // metro
				0,    // single_trip
				2500, // monthly_pass
				0,    // transport_card
				0,    // card_recharge
				0,    // fines
				0,    // transfer_cost
				0,    // station_snacks
				0     // luggage
			},

			{ // tram
				0, // single_trip
				0, // monthly_pass
				0, // transport_card
				0, // card_recharge
				0, // fines
				0, // luggage
				0, // station_snacks
				0  // transfer_cost
			},

			{ // airplane
				0, // tickets
				0, // luggage
				0, // additional_baggage
				0, // insurance
				0, // airport_transfer
				0, // onboard_food
				0, // hotel
				0, // visa
				0, // taxi_abroad
				0  // souvenirs
			}
		}
	};

	PersonConfig trump_cfg = {
		80000, // salary

		{ // food
			18, // coffee
			8,  // milk
			10, // oatmeal
			5,  // rice
			7,  // pasta
			15, // bread
			8,  // eggs
			30, // chicken_fillet
			14, // cheese
			8,  // yogurt
			5,  // potatoes
			3,  // onions
			10, // tomatoes
			10, // apples
			5,  // bananas
			8,  // frozen_vegetables
			2,  // vegetable_oil
			4   // legumes
		},

		{ // subscriptions
			200,  // youtube_premium
			150,  // spotify
			400,  // netflix
			300,  // yandex_plus
			200,  // telegram_premium
			1500, // chatgpt_plus
			250,  // kinopoisk
			150,  // apple_music
			100,  // google_drive
			80,   // icloud
			500,  // office_365
			200,  // vpn
			600,  // playstation_plus
			700,  // xbox_game_pass
			1200, // adobe
			80,   // github
			150,  // dropbox
			200,  // notion
			180,  // canva
			300   // duolingo
		},

		{ // entertainment
			400,  // cinema
			1500, // concerts
			700,  // theatre
			1200, // cafes
			2000, // restaurants
			800,  // bars
			500,  // books
			1000, // games
			900,  // hobbies
			600,  // streaming_movies
			300,  // museums
			700,  // amusement_parks
			400,  // board_games
			1000, // sports_events
			2500  // trips
		},

		{ //home
			35000, // rent
			0,     // mortgage
			4500,  // electricity
			1200,  // water
			3000,  // heating
			800,   // gas
			900,   // internet
			1200,  // mobile
			2500,  // cleaning
			4000,  // furniture
			3000,  // repairs
			1500,  // security
			2000,  // property_tax
			1800,  // household_chemicals
			2500   // appliances
		},

		{ // health
			1500,  // medicines
			800,   // vitamins
			3000,  // dentist
			2500,  // therapist
			2000,  // tests
			1500,  // checkups
			4000,  // insurance
			2500,  // gym
			1200,  // massage
			2000,  // psychologist
			1800,  // glasses
			3000,  // emergency
			0,     // surgery
			0      // rehabilitation
		},

		{ // clothes
			5000, // jackets
			2500, // tshirts
			3000, // shirts
			4000, // jeans
			3500, // trousers
			6000, // shoes
			5500, // sneakers
			1500, // underwear
			800,  // socks
			1200, // hats
			2000, // accessories
			1000, // dry_cleaning
			3500, // bags
			3000  // sportswear
		},

		{ // education
			5000, // courses
			1500, // books
			4000, // tutors
			2500, // exams
			3000, // certificates
			1200, // online_platforms
			700,  // stationery
			2000, // seminars
			3500, // conferences
			2500, // language_learning
			4500, // programming_courses
			3000  // design_courses
		},

		{ // gifts
			4000, // birthday_family
			2500, // birthday_friends
			5000, // new_year
			3000, // march_8
			3000, // february_23
			4000, // anniversary
			6000, // wedding
			3500, // children
			2500, // corporate
			2000  // surprise_gifts
		},

		{ // personal_care
			700,  // shampoo
			2500, // cosmetics
			3000, // perfume
			1500, // haircut
			1800, // manicure
			2000, // skincare
			600,  // shaving
			1200, // hygiene
			2500, // spa
			1500, // barber
			1000, // dental_care
			500   // deodorants
		},

		{ // hobbies
			1500, // drawing
			2500, // music
			3000, // photography
			2000, // sports
			1200, // fishing
			1000, // collecting
			800,  // gardening
			1500, // diy
			1800, // dancing
			500,  // chess
			1200, // crafting
			4000  // instruments
		},

		{ // dog
			3000, // food
			1000, // vet
			500,  // toys
			700,  // grooming
			400,  // medicine
			800   // training
		},

		{ // cat
			2000, // food
			800,  // vet
			300,  // litter
			400,  // toys
			500,  // scratching_post
			300   // medicine
		},

		{ // parrot
			1000, // food
			500,  // vet
			2000, // cage
			300,  // toys
			100,  // vitamins
			50    // filler
		},

		{ // fish
			500,  // food
			2000, // aquarium
			300,  // filter
			100,  // light
			200,  // medicine
			150   // decorations
		},

		{ // transport
			{ // car
				1200000, // value
				3000,    // gas
				5000,    // insurance
				2500,    // maintenance
				4000,    // repairs
				800,     // car_wash
				1500,    // parking
				2000,    // tires
				1000     // tax
			},

			{ // bus
				50,   // single_trip
				1200, // monthly_pass
				300,  // long_distance_trips
				100,  // luggage
				0,    // fines
				50,   // station_snacks
				0,    // taxi_to_station
				0     // mobile_charging
			},

			{ // bicycle
				30000, // value
				500,   // maintenance
				700,   // repairs
				400,   // tires
				300,   // chain
				100,   // brakes
				100,   // lights
				100,   // accessories
				0,     // parking
				500    // helmet
			},

			{ // metro
				70,   // single_trip
				2500, // monthly_pass
				500,  // transport_card
				0,    // card_recharge
				0,    // fines
				100,  // transfer_cost
				50,   // station_snacks
				0     // luggage
			},

			{ // tram
				60,   // single_trip
				2200, // monthly_pass
				400,  // transport_card
				0,    // card_recharge
				0,    // fines
				50,   // luggage
				30,   // station_snacks
				0     // transfer_cost
			},

			{ // airplane
				5000, // tickets
				2000, // luggage
				500,  // additional_baggage
				1000, // insurance
				700,  // airport_transfer
				3000, // onboard_food
				5000, // hotel
				0,    // visa
				1000, // taxi_abroad
				500   // souvenirs
			}
		}
	};

	person_init(Epstein, epstein_cfg);
	person_init(Trump, trump_cfg);

	simulation(Epstein);
	simulation(Trump);

	printf("Epstein:\n");
	print_results(Epstein);

	printf("\nTrump:\n");
	print_results(Trump);
}