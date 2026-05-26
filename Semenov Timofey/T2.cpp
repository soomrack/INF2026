#include <stdio.h>

using RUB = long long;

const double INFLATION_RATE = 4.5;
const double INVESTMENT_YIELD = 16.0;

double monthly_factor(double annual_percentage) {
	return 1.0 + annual_percentage / 12.0 / 100.0;
}

struct PersonalVehicle {
	RUB asset_value;
	RUB fuel_cost;
	RUB insurance_policy;
	RUB scheduled_service;
	RUB unexpected_repairs;
	RUB car_wash_valet;
	RUB garage_parking;
	RUB winter_tires;
	RUB state_tax;
};

struct PublicShuttle {
	RUB token_fare;
	RUB commuter_pass;
	RUB regional_routes;
	RUB overweight_baggage;
	RUB transit_fines;
	RUB terminal_food;
	RUB station_cab;
	RUB power_bank;
};

struct EcoCycle {
	RUB purchase_value;
	RUB chain_lubrication;
	RUB frame_repairs;
	RUB rubber_tubes;
	RUB drive_chain;
	RUB pad_brakes;
	RUB led_lights;
	RUB cargo_baskets;
	RUB rack_parking;
	RUB safety_helmet;
};

struct SubwayTransit {
	RUB single_token;
	RUB smart_card_pass;
	RUB card_issuance;
	RUB balance_recharge;
	RUB gate_fines;
	RUB interchange_fee;
	RUB platform_kiosk;
	RUB heavy_luggage;
};

struct ElectricTramway {
	RUB conductor_ticket;
	RUB monthly_ticket;
	RUB transit_pass;
	RUB wallet_topup;
	RUB violation_fines;
	RUB baggage_fare;
	RUB stop_snacks;
	RUB route_transfer;
};

struct AviationTravel {
	RUB flight_tickets;
	RUB checked_bags;
	RUB excess_weight;
	RUB flight_insurance;
	RUB terminal_shuttle;
	RUB cabin_meals;
	RUB resort_hotel;
	RUB entry_visa;
	RUB foreign_taxi;
	RUB local_souvenirs;
};

struct CapitalVault {
	RUB checking_account;
	RUB deposit_account;
};

struct CanineCompanion {
	RUB kibble_diet;
	RUB vet_checkups;
	RUB chew_toys;
	RUB salon_grooming;
	RUB medical_pills;
	RUB obedience_training;
};

struct FelineCompanion {
	RUB canned_meat;
	RUB veterinary_care;
	RUB silica_litter;
	RUB plush_mice;
	RUB scratching_boards;
	RUB pharmacy_drops;
};

struct AvianPet {
	RUB seed_mixtures;
	RUB avian_doctor;
	RUB metal_cage;
	RUB swing_mirrors;
	RUB liquid_vitamins;
	RUB sand_substrate;
};

struct AquaticPet {
	RUB flake_rations;
	RUB glass_aquarium;
	RUB water_filter;
	RUB led_lighting;
	RUB aquarium_remedies;
	RUB underwater_plants;
};

struct DietaryBasket {
	RUB espresso_beans;
	RUB organic_milk;
	RUB rolled_oats;
	RUB basmati_rice;
	RUB wheat_pasta;
	RUB artisan_bread;
	RUB farm_eggs;
	RUB chicken_breasts;
	RUB cheddar_cheese;
	RUB greek_yogurt;
	RUB raw_potatoes;
	RUB yellow_onions;
	RUB red_tomatoes;
	RUB fresh_apples;
	RUB sweet_bananas;
	RUB frozen_greens;
	RUB sunflower_oil;
	RUB dried_lentils;
};

struct DigitalLicenses {
	RUB video_premium;
	RUB music_hd;
	RUB movie_network;
	RUB local_plus;
	RUB chat_premium;
	RUB ai_pro_token;
	RUB cinema_pass;
	RUB audio_cloud;
	RUB drive_storage;
	RUB cloud_backup;
	RUB office_cloud;
	RUB secure_vpn;
	RUB console_plus;
	RUB game_pass_ultimate;
	RUB design_cloud;
	RUB git_pro_host;
	RUB backup_box;
	RUB workspace_notes;
	RUB graphics_pro;
	RUB language_app;
};

struct SocialLeisure {
	RUB movie_theatre;
	RUB music_festivals;
	RUB drama_plays;
	RUB bistro_visits;
	RUB fine_restaurants;
	RUB lounge_bars;
	RUB fiction_books;
	RUB digital_games;
	RUB craft_materials;
	RUB indie_movies;
	RUB art_museums;
	RUB theme_parks;
	RUB tabletop_games;
	RUB stadium_events;
	RUB vacation_tours;
};

struct MobilitySystem {
	PersonalVehicle vehicle;
	PublicShuttle shuttle;
	EcoCycle cycle;
	SubwayTransit subway;
	ElectricTramway tramway;
	AviationTravel aviation;
};

struct ResidentialEstate {
	RUB lease_rent;
	RUB bank_mortgage;
	RUB power_bill;
	RUB water_bill;
	RUB thermal_heating;
	RUB cooking_gas;
	RUB fiber_internet;
	RUB mobile_network;
	RUB maid_service;
	RUB decor_furniture;
	RUB structural_repairs;
	RUB alarm_security;
	RUB land_tax;
	RUB sanitary_chemicals;
	RUB kitchen_appliances;
};

struct MedicalCare {
	RUB prescription_drugs;
	RUB daily_vitamins;
    RUB dental_care_clinic;
	RUB family_doctor;
	RUB laboratory_tests;
	RUB annual_screenings;
	RUB medical_insurance;
	RUB fitness_gym;
	RUB therapy_massage;
	RUB mental_counseling;
	RUB optical_lenses;
	RUB emergency_room;
	RUB surgical_wards;
	RUB clinic_rehab;
};

struct WardrobeCollection {
	RUB winter_coats;
	RUB casual_tees;
	RUB classic_shirts;
	RUB denim_trousers;
	RUB tailored_suits;
	RUB leather_shoes;
	RUB running_sneakers;
	RUB undergarments;
	RUB thermal_socks;
	RUB summer_hats;
	RUB fashion_accessories;
	RUB valet_dry_clean;
	RUB travel_backpacks;
	RUB active_sportswear;
};

struct IntellectualGrowth {
	RUB academy_courses;
	RUB textbook_volumes;
	RUB private_coaches;
	RUB qualification_exams;
	RUB diploma_certificates;
	RUB web_learning_hubs;
	RUB office_stationery;
	RUB study_seminars;
	RUB scientific_forums;
	RUB speech_classes;
	RUB coding_bootcamps;
	RUB ui_design_tracks;
};

struct TributeOfferings {
	RUB parents_anniversary;
	RUB friends_birthdays;
	RUB winter_festivities;
	RUB spring_celebration;
	RUB autumn_holiday;
	RUB relationship_date;
	RUB wedding_reception;
	RUB children_parties;
	RUB office_corporate;
	RUB unexpected_surprises;
};

struct BodyHygiene {
	RUB hair_shampoo;
	RUB beauty_cosmetics;
	RUB luxury_parfum;
	RUB barber_trim;
	RUB nail_manicure;
	RUB dermal_creams;
	RUB shaving_foam;
	RUB intimate_hygiene;
	RUB resort_spa;
	RUB hairstylist_salon;
	RUB oral_treatment;
	RUB spray_deodorants;
};

struct AmateurPassions {
	RUB sketch_canvases;
	RUB guitar_strings;
	RUB camera_lenses;
	RUB athletics_gear;
	RUB river_fishing;
	RUB antique_collecting;
	RUB greenhouse_plants;
	RUB home_diy_tools;
	RUB ballroom_dancing;
	RUB grandmaster_chess;
	RUB manual_crafting;
	RUB studio_instruments;
};

struct Person {
	RUB monthly_income;
	DietaryBasket dietary;
	DigitalLicenses licenses;
	SocialLeisure leisure;
	MobilitySystem mobility;
	ResidentialEstate estate;
	MedicalCare medical;
	WardrobeCollection wardrobe;
	IntellectualGrowth growth;
	TributeOfferings offerings;
	BodyHygiene hygiene;
	AmateurPassions passions;

	CanineCompanion canine;
	FelineCompanion feline;
	AvianPet avian;
	AquaticPet aquatic;
	CapitalVault vault;
};

struct PersonConfig {
	RUB monthly_income;
	DietaryBasket dietary;
	DigitalLicenses licenses;
	SocialLeisure leisure;
	ResidentialEstate estate;
	MedicalCare medical;
	WardrobeCollection wardrobe;
	IntellectualGrowth growth;
	TributeOfferings offerings;
	BodyHygiene hygiene;
	AmateurPassions passions;

	CanineCompanion canine;
	FelineCompanion feline;
	AvianPet avian;
	AquaticPet aquatic;
	MobilitySystem mobility;
};

void person_init(Person& p, const PersonConfig& cfg) {
	p.monthly_income = cfg.monthly_income;
	p.dietary = cfg.dietary;
	p.licenses = cfg.licenses;
	p.leisure = cfg.leisure;
	p.estate = cfg.estate;
	p.medical = cfg.medical;
	p.wardrobe = cfg.wardrobe;
	p.growth = cfg.growth;
	p.offerings = cfg.offerings;
	p.hygiene = cfg.hygiene;
	p.passions = cfg.passions;

	p.canine = cfg.canine;
	p.feline = cfg.feline;
	p.avian = cfg.avian;
	p.aquatic = cfg.aquatic;

	p.mobility = cfg.mobility;

	p.vault.checking_account = 0;
	p.vault.deposit_account = 0;
}

RUB total_dietary(const DietaryBasket& d) {
	return d.espresso_beans +
		d.organic_milk +
		d.rolled_oats +
		d.basmati_rice +
		d.wheat_pasta +
		d.artisan_bread +
		d.farm_eggs +
		d.chicken_breasts +
		d.cheddar_cheese +
		d.greek_yogurt +
		d.raw_potatoes +
		d.yellow_onions +
		d.red_tomatoes +
		d.fresh_apples +
		d.sweet_bananas +
		d.frozen_greens +
		d.sunflower_oil +
		d.dried_lentils;
}

RUB total_licenses(const DigitalLicenses& d) {
	return d.video_premium +
		d.music_hd +
		d.movie_network +
		d.local_plus +
		d.chat_premium +
		d.ai_pro_token +
		d.cinema_pass +
		d.audio_cloud +
		d.drive_storage +
		d.cloud_backup +
		d.office_cloud +
		d.secure_vpn +
		d.console_plus +
		d.game_pass_ultimate +
		d.design_cloud +
		d.git_pro_host +
		d.backup_box +
		d.workspace_notes +
		d.graphics_pro +
		d.language_app;
}

RUB total_leisure(const SocialLeisure& s) {
	return s.movie_theatre +
		s.music_festivals +
		s.drama_plays +
		s.bistro_visits +
		s.fine_restaurants +
		s.lounge_bars +
		s.fiction_books +
		s.digital_games +
		s.craft_materials +
		s.indie_movies +
		s.art_museums +
		s.theme_parks +
		s.tabletop_games +
		s.stadium_events +
		s.vacation_tours;
}

RUB total_estate(const ResidentialEstate& r) {
	return r.lease_rent +
		r.bank_mortgage +
		r.power_bill +
		r.water_bill +
		r.thermal_heating +
		r.cooking_gas +
		r.fiber_internet +
		r.mobile_network +
		r.maid_service +
		r.decor_furniture +
		r.structural_repairs +
		r.alarm_security +
		r.land_tax +
		r.sanitary_chemicals +
		r.kitchen_appliances;
}

RUB total_medical(const MedicalCare& m) {
	return m.prescription_drugs +
		m.daily_vitamins +
		m.dental_care_clinic +
		m.family_doctor +
		m.laboratory_tests +
		m.annual_screenings +
		m.medical_insurance +
		m.fitness_gym +
		m.therapy_massage +
		m.mental_counseling +
		m.optical_lenses +
		m.emergency_room +
		m.surgical_wards +
		m.clinic_rehab;
}

RUB total_wardrobe(const WardrobeCollection& w) {
	return w.winter_coats +
		w.casual_tees +
		w.classic_shirts +
		w.denim_trousers +
		w.tailored_suits +
		w.leather_shoes +
		w.running_sneakers +
		w.undergarments +
		w.thermal_socks +
		w.summer_hats +
		w.fashion_accessories +
		w.valet_dry_clean +
		w.travel_backpacks +
		w.active_sportswear;
}

RUB total_growth(const IntellectualGrowth& i) {
	return i.academy_courses +
		i.textbook_volumes +
		i.private_coaches +
		i.qualification_exams +
		i.diploma_certificates +
		i.web_learning_hubs +
		i.office_stationery +
		i.study_seminars +
		i.scientific_forums +
		i.speech_classes +
		i.coding_bootcamps +
		i.ui_design_tracks;
}

RUB total_offerings(const TributeOfferings& t) {
	return t.parents_anniversary +
		t.friends_birthdays +
		t.winter_festivities +
		t.spring_celebration +
		t.autumn_holiday +
		t.relationship_date +
		t.wedding_reception +
		t.children_parties +
		t.office_corporate +
		t.unexpected_surprises;
}

RUB total_hygiene(const BodyHygiene& b) {
	return b.hair_shampoo +
		b.beauty_cosmetics +
		b.luxury_parfum +
		b.barber_trim +
		b.nail_manicure +
		b.dermal_creams +
		b.shaving_foam +
		b.intimate_hygiene +
		b.resort_spa +
		b.hairstylist_salon +
		b.oral_treatment +
		b.spray_deodorants;
}

RUB total_passions(const AmateurPassions& a) {
	return a.sketch_canvases +
		a.guitar_strings +
		a.camera_lenses +
		a.athletics_gear +
		a.river_fishing +
		a.antique_collecting +
		a.greenhouse_plants +
		a.home_diy_tools +
		a.ballroom_dancing +
		a.grandmaster_chess +
		a.manual_crafting +
		a.studio_instruments;
}

RUB total_canine(const CanineCompanion& c) {
	return c.kibble_diet +
		c.vet_checkups +
		c.chew_toys +
		c.salon_grooming +
		c.medical_pills +
		c.obedience_training;
}

RUB total_feline(const FelineCompanion& f) {
	return f.canned_meat +
		f.veterinary_care +
		f.silica_litter +
		f.plush_mice +
		f.scratching_boards +
		f.pharmacy_drops;
}

RUB total_avian(const AvianPet& a) {
	return a.seed_mixtures +
		a.avian_doctor +
		a.metal_cage +
		a.swing_mirrors +
		a.liquid_vitamins +
		a.sand_substrate;
}

RUB total_aquatic(const AquaticPet& a) {
	return a.flake_rations +
		a.glass_aquarium +
		a.water_filter +
		a.led_lighting +
		a.aquarium_remedies +
		a.underwater_plants;
}

RUB total_animals(const Person& p) {
	return total_canine(p.canine) +
		total_feline(p.feline) +
		total_avian(p.avian) +
		total_aquatic(p.aquatic);
}

RUB total_vehicle(const PersonalVehicle& p) {
	return p.fuel_cost +
		p.insurance_policy +
		p.scheduled_service +
		p.unexpected_repairs +
		p.car_wash_valet +
		p.garage_parking +
		p.winter_tires +
		p.state_tax;
}

RUB total_shuttle(const PublicShuttle& p) {
	return p.token_fare +
		p.commuter_pass +
		p.regional_routes +
		p.overweight_baggage +
		p.transit_fines +
		p.terminal_food +
		p.station_cab +
		p.power_bank;
}

RUB total_cycle(const EcoCycle& e) {
	return e.chain_lubrication +
		e.frame_repairs +
		e.rubber_tubes +
		e.drive_chain +
		e.pad_brakes +
		e.led_lights +
		e.cargo_baskets +
		e.rack_parking +
		e.safety_helmet;
}

RUB total_subway(const SubwayTransit& s) {
	return s.single_token +
		s.smart_card_pass +
		s.card_issuance +
		s.balance_recharge +
		s.gate_fines +
		s.interchange_fee +
		s.platform_kiosk +
		s.heavy_luggage;
}

RUB total_tramway(const ElectricTramway& e) {
	return e.conductor_ticket +
		e.monthly_ticket +
		e.transit_pass +
		e.wallet_topup +
		e.violation_fines +
		e.baggage_fare +
		e.stop_snacks +
		e.route_transfer;
}

RUB total_aviation(const AviationTravel& a) {
	return a.flight_tickets +
		a.checked_bags +
		a.excess_weight +
		a.flight_insurance +
		a.terminal_shuttle +
		a.cabin_meals +
		a.resort_hotel +
		a.entry_visa +
		a.foreign_taxi +
		a.local_souvenirs;
}

RUB total_mobility(const MobilitySystem& m) {
	return total_vehicle(m.vehicle) +
		total_shuttle(m.shuttle) +
		total_cycle(m.cycle) +
		total_subway(m.subway) +
		total_tramway(m.tramway) +
		total_aviation(m.aviation);
}

void inflate_dietary(DietaryBasket& d, double k);
void inflate_licenses(DigitalLicenses& d, double k);
void inflate_leisure(SocialLeisure& s, double k);
void inflate_estate(ResidentialEstate& r, double k);
void inflate_medical(MedicalCare& m, double k);
void inflate_wardrobe(WardrobeCollection& w, double k);
void inflate_growth(IntellectualGrowth& i, double k);
void inflate_offerings(TributeOfferings& t, double k);
void inflate_hygiene(BodyHygiene& b, double k);
void inflate_passions(AmateurPassions& a, double k);
void inflate_vehicle(PersonalVehicle& p, double k);
void inflate_shuttle(PublicShuttle& p, double k);
void inflate_cycle(EcoCycle& e, double k);
void inflate_subway(SubwayTransit& s, double k);
void inflate_tramway(ElectricTramway& e, double k);
void inflate_aviation(AviationTravel& a, double k);
void inflate_canine(CanineCompanion& c, double k);
void inflate_feline(FelineCompanion& f, double k);
void inflate_avian(AvianPet& a, double k);
void inflate_aquatic(AquaticPet& a, double k);

void earn_revenue(Person& p, int month, int year) {
	if (month == 12 && year == 2026) {
		p.monthly_income = p.monthly_income * 3 / 2;
	}
	p.vault.checking_account += p.monthly_income;
}

void earn_custom_revenue(Person& p, const char* name, int month, int year) {
	earn_revenue(p, month, year);

	if (name[0] == 'B' && month == 7 && year == 2027) {
		p.vault.checking_account += 30000;
	}
}

void clear_dietary(Person& p, double annual_rate) {
	inflate_dietary(p.dietary, monthly_factor(annual_rate));
	p.vault.checking_account -= total_dietary(p.dietary);
}

void clear_licenses(Person& p, double annual_rate) {
	inflate_licenses(p.licenses, monthly_factor(annual_rate));
	p.vault.checking_account -= total_licenses(p.licenses);
}

void clear_leisure(Person& p, double annual_rate) {
	inflate_leisure(p.leisure, monthly_factor(annual_rate));
	p.vault.checking_account -= total_leisure(p.leisure);
}

void clear_mobility(Person& p, double annual_rate) {
	double k = monthly_factor(annual_rate);
	inflate_vehicle(p.mobility.vehicle, k);
	inflate_shuttle(p.mobility.shuttle, k);
	inflate_cycle(p.mobility.cycle, k);
	inflate_subway(p.mobility.subway, k);
	inflate_tramway(p.mobility.tramway, k);
	inflate_aviation(p.mobility.aviation, k);
	p.vault.checking_account -= total_mobility(p.mobility);
}

void clear_estate(Person& p, double annual_rate) {
	inflate_estate(p.estate, monthly_factor(annual_rate));
	p.vault.checking_account -= total_estate(p.estate);
}

void clear_medical(Person& p, double annual_rate) {
	inflate_medical(p.medical, monthly_factor(annual_rate));
	p.vault.checking_account -= total_medical(p.medical);
}

void clear_wardrobe(Person& p, double annual_rate) {
	inflate_wardrobe(p.wardrobe, monthly_factor(annual_rate));
	p.vault.checking_account -= total_wardrobe(p.wardrobe);
}

void clear_growth(Person& p, double annual_rate) {
	inflate_growth(p.growth, monthly_factor(annual_rate));
	p.vault.checking_account -= total_growth(p.growth);
}

void clear_offerings(Person& p, double annual_rate) {
	inflate_offerings(p.offerings, monthly_factor(annual_rate));
	p.vault.checking_account -= total_offerings(p.offerings);
}

void clear_hygiene(Person& p, double annual_rate) {
	inflate_hygiene(p.hygiene, monthly_factor(annual_rate));
	p.vault.checking_account -= total_hygiene(p.hygiene);
}

void clear_passions(Person& p, double annual_rate) {
	inflate_passions(p.passions, monthly_factor(annual_rate));
	p.vault.checking_account -= total_passions(p.passions);
}

void clear_all_animals(Person& p, double annual_rate) {
	double k = monthly_factor(annual_rate);
	inflate_canine(p.canine, k);
	inflate_feline(p.feline, k);
	inflate_avian(p.avian, k);
	inflate_aquatic(p.aquatic, k);
	p.vault.checking_account -= total_animals(p);
}

void send_to_vault(Person& p, RUB cash) {
	p.vault.checking_account -= cash;
	p.vault.deposit_account += cash;
}

void accrue_yield(Person& p, double yield) {
	p.vault.deposit_account += (RUB)(p.vault.deposit_account * (yield / 12.0 / 100.0));
}

void inflate_dietary(DietaryBasket& d, double k) {
	d.espresso_beans = (RUB)(d.espresso_beans * k);
	d.organic_milk = (RUB)(d.organic_milk * k);
	d.rolled_oats = (RUB)(d.rolled_oats * k);
	d.basmati_rice = (RUB)(d.basmati_rice * k);
	d.wheat_pasta = (RUB)(d.wheat_pasta * k);
	d.artisan_bread = (RUB)(d.artisan_bread * k);
	d.farm_eggs = (RUB)(d.farm_eggs * k);
	d.chicken_breasts = (RUB)(d.chicken_breasts * k);
	d.cheddar_cheese = (RUB)(d.cheddar_cheese * k);
	d.greek_yogurt = (RUB)(d.greek_yogurt * k);
	d.raw_potatoes = (RUB)(d.raw_potatoes * k);
	d.yellow_onions = (RUB)(d.yellow_onions * k);
	d.red_tomatoes = (RUB)(d.red_tomatoes * k);
	d.fresh_apples = (RUB)(d.fresh_apples * k);
	d.sweet_bananas = (RUB)(d.sweet_bananas * k);
	d.frozen_greens = (RUB)(d.frozen_greens * k);
	d.sunflower_oil = (RUB)(d.sunflower_oil * k);
	d.dried_lentils = (RUB)(d.dried_lentils * k);
}

void inflate_licenses(DigitalLicenses& d, double k) {
	d.video_premium = (RUB)(d.video_premium * k);
	d.music_hd = (RUB)(d.music_hd * k);
	d.movie_network = (RUB)(d.movie_network * k);
	d.local_plus = (RUB)(d.local_plus * k);
	d.chat_premium = (RUB)(d.chat_premium * k);
	d.ai_pro_token = (RUB)(d.ai_pro_token * k);
	d.cinema_pass = (RUB)(d.cinema_pass * k);
	d.audio_cloud = (RUB)(d.audio_cloud * k);
	d.drive_storage = (RUB)(d.drive_storage * k);
	d.cloud_backup = (RUB)(d.cloud_backup * k);
	d.office_cloud = (RUB)(d.office_cloud * k);
	d.secure_vpn = (RUB)(d.secure_vpn * k);
	d.console_plus = (RUB)(d.console_plus * k);
	d.game_pass_ultimate = (RUB)(d.game_pass_ultimate * k);
	d.design_cloud = (RUB)(d.design_cloud * k);
	d.git_pro_host = (RUB)(d.git_pro_host * k);
	d.backup_box = (RUB)(d.backup_box * k);
	d.workspace_notes = (RUB)(d.workspace_notes * k);
	d.graphics_pro = (RUB)(d.graphics_pro * k);
	d.language_app = (RUB)(d.language_app * k);
}

void inflate_leisure(SocialLeisure& s, double k) {
	s.movie_theatre = (RUB)(s.movie_theatre * k);
	s.music_festivals = (RUB)(s.music_festivals * k);
	s.drama_plays = (RUB)(s.drama_plays * k);
	s.bistro_visits = (RUB)(s.bistro_visits * k);
	s.fine_restaurants = (RUB)(s.fine_restaurants * k);
	s.lounge_bars = (RUB)(s.lounge_bars * k);
	s.fiction_books = (RUB)(s.fiction_books * k);
	s.digital_games = (RUB)(s.digital_games * k);
	s.craft_materials = (RUB)(s.craft_materials * k);
	s.indie_movies = (RUB)(s.indie_movies * k);
	s.art_museums = (RUB)(s.art_museums * k);
	s.theme_parks = (RUB)(s.theme_parks * k);
	s.tabletop_games = (RUB)(s.tabletop_games * k);
	s.stadium_events = (RUB)(s.stadium_events * k);
	s.vacation_tours = (RUB)(s.vacation_tours * k);
}

void inflate_estate(ResidentialEstate& r, double k) {
	r.lease_rent = (RUB)(r.lease_rent * k);
	r.bank_mortgage = (RUB)(r.bank_mortgage * k);
	r.power_bill = (RUB)(r.power_bill * k);
	r.water_bill = (RUB)(r.water_bill * k);
	r.thermal_heating = (RUB)(r.thermal_heating * k);
	r.cooking_gas = (RUB)(r.cooking_gas * k);
	r.fiber_internet = (RUB)(r.fiber_internet * k);
	r.mobile_network = (RUB)(r.mobile_network * k);
	r.maid_service = (RUB)(r.maid_service * k);
	r.decor_furniture = (RUB)(r.decor_furniture * k);
	r.structural_repairs = (RUB)(r.structural_repairs * k);
	r.alarm_security = (RUB)(r.alarm_security * k);
	r.land_tax = (RUB)(r.land_tax * k);
	r.sanitary_chemicals = (RUB)(r.sanitary_chemicals * k);
	r.kitchen_appliances = (RUB)(r.kitchen_appliances * k);
}

void inflate_medical(MedicalCare& m, double k) {
	m.prescription_drugs = (RUB)(m.prescription_drugs * k);
	m.daily_vitamins = (RUB)(m.daily_vitamins * k);
	m.dental_care_clinic = (RUB)(m.dental_care_clinic * k);
	m.family_doctor = (RUB)(m.family_doctor * k);
	m.laboratory_tests = (RUB)(m.laboratory_tests * k);
	m.annual_screenings = (RUB)(m.annual_screenings * k);
	m.medical_insurance = (RUB)(m.medical_insurance * k);
	m.fitness_gym = (RUB)(m.fitness_gym * k);
	m.therapy_massage = (RUB)(m.therapy_massage * k);
	m.mental_counseling = (RUB)(m.mental_counseling * k);
	m.optical_lenses = (RUB)(m.optical_lenses * k);
	m.emergency_room = (RUB)(m.emergency_room * k);
	m.surgical_wards = (RUB)(m.surgical_wards * k);
	m.clinic_rehab = (RUB)(m.clinic_rehab * k);
}

void inflate_wardrobe(WardrobeCollection& w, double k) {
	w.winter_coats = (RUB)(w.winter_coats * k);
	w.casual_tees = (RUB)(w.casual_tees * k);
	w.classic_shirts = (RUB)(w.classic_shirts * k);
	w.denim_trousers = (RUB)(w.denim_trousers * k);
	w.tailored_suits = (RUB)(w.tailored_suits * k);
	w.leather_shoes = (RUB)(w.leather_shoes * k);
	w.running_sneakers = (RUB)(w.running_sneakers * k);
	w.undergarments = (RUB)(w.undergarments * k);
	w.thermal_socks = (RUB)(w.thermal_socks * k);
	w.summer_hats = (RUB)(w.summer_hats * k);
	w.fashion_accessories = (RUB)(w.fashion_accessories * k);
	w.valet_dry_clean = (RUB)(w.valet_dry_clean * k);
	w.travel_backpacks = (RUB)(w.travel_backpacks * k);
	w.active_sportswear = (RUB)(w.active_sportswear * k);
}

void inflate_growth(IntellectualGrowth& i, double k) {
	i.academy_courses = (RUB)(i.academy_courses * k);
	i.textbook_volumes = (RUB)(i.textbook_volumes * k);
	i.private_coaches = (RUB)(i.private_coaches * k);
	i.qualification_exams = (RUB)(i.qualification_exams * k);
	i.diploma_certificates = (RUB)(i.diploma_certificates * k);
	i.web_learning_hubs = (RUB)(i.web_learning_hubs * k);
	i.office_stationery = (RUB)(i.office_stationery * k);
	i.study_seminars = (RUB)(i.study_seminars * k);
	i.scientific_forums = (RUB)(i.scientific_forums * k);
	i.speech_classes = (RUB)(i.speech_classes * k);
	i.coding_bootcamps = (RUB)(i.coding_bootcamps * k);
	i.ui_design_tracks = (RUB)(i.ui_design_tracks * k);
}

void inflate_offerings(TributeOfferings& t, double k) {
	t.parents_anniversary = (RUB)(t.parents_anniversary * k);
	t.friends_birthdays = (RUB)(t.friends_birthdays * k);
	t.winter_festivities = (RUB)(t.winter_festivities * k);
	t.spring_celebration = (RUB)(t.spring_celebration * k);
	t.autumn_holiday = (RUB)(t.autumn_holiday * k);
	t.relationship_date = (RUB)(t.relationship_date * k);
	t.wedding_reception = (RUB)(t.wedding_reception * k);
	t.children_parties = (RUB)(t.children_parties * k);
	t.office_corporate = (RUB)(t.office_corporate * k);
	t.unexpected_surprises = (RUB)(t.unexpected_surprises * k);
}

void inflate_hygiene(BodyHygiene& b, double k) {
	b.hair_shampoo = (RUB)(b.hair_shampoo * k);
	b.beauty_cosmetics = (RUB)(b.beauty_cosmetics * k);
	b.luxury_parfum = (RUB)(b.luxury_parfum * k);
	b.barber_trim = (RUB)(b.barber_trim * k);
	b.nail_manicure = (RUB)(b.nail_manicure * k);
	b.dermal_creams = (RUB)(b.dermal_creams * k);
	b.shaving_foam = (RUB)(b.shaving_foam * k);
	b.intimate_hygiene = (RUB)(b.intimate_hygiene * k);
	b.resort_spa = (RUB)(b.resort_spa * k);
	b.hairstylist_salon = (RUB)(b.hairstylist_salon * k);
	b.oral_treatment = (RUB)(b.oral_treatment * k);
	b.spray_deodorants = (RUB)(b.spray_deodorants * k);
}

void inflate_passions(AmateurPassions& a, double k) {
	a.sketch_canvases = (RUB)(a.sketch_canvases * k);
	a.guitar_strings = (RUB)(a.guitar_strings * k);
	a.camera_lenses = (RUB)(a.camera_lenses * k);
	a.athletics_gear = (RUB)(a.athletics_gear * k);
	a.river_fishing = (RUB)(a.river_fishing * k);
	a.antique_collecting = (RUB)(a.antique_collecting * k);
	a.greenhouse_plants = (RUB)(a.greenhouse_plants * k);
	a.home_diy_tools = (RUB)(a.home_diy_tools * k);
	a.ballroom_dancing = (RUB)(a.ballroom_dancing * k);
	a.grandmaster_chess = (RUB)(a.grandmaster_chess * k);
	a.manual_crafting = (RUB)(a.manual_crafting * k);
	a.studio_instruments = (RUB)(a.studio_instruments * k);
}

void inflate_vehicle(PersonalVehicle& p, double k) {
	p.asset_value = (RUB)(p.asset_value * k);
	p.fuel_cost = (RUB)(p.fuel_cost * k);
	p.insurance_policy = (RUB)(p.insurance_policy * k);
	p.scheduled_service = (RUB)(p.scheduled_service * k);
	p.unexpected_repairs = (RUB)(p.unexpected_repairs * k);
	p.car_wash_valet = (RUB)(p.car_wash_valet * k);
	p.garage_parking = (RUB)(p.garage_parking * k);
	p.winter_tires = (RUB)(p.winter_tires * k);
	p.state_tax = (RUB)(p.state_tax * k);
}

void inflate_shuttle(PublicShuttle& p, double k) {
	p.token_fare = (RUB)(p.token_fare * k);
	p.commuter_pass = (RUB)(p.commuter_pass * k);
	p.regional_routes = (RUB)(p.regional_routes * k);
	p.overweight_baggage = (RUB)(p.overweight_baggage * k);
	p.transit_fines = (RUB)(p.transit_fines * k);
	p.terminal_food = (RUB)(p.terminal_food * k);
	p.station_cab = (RUB)(p.station_cab * k);
	p.power_bank = (RUB)(p.power_bank * k);
}

void inflate_cycle(EcoCycle& e, double k) {
	e.purchase_value = (RUB)(e.purchase_value * k);
	e.chain_lubrication = (RUB)(e.chain_lubrication * k);
	e.frame_repairs = (RUB)(e.frame_repairs * k);
	e.rubber_tubes = (RUB)(e.rubber_tubes * k);
	e.drive_chain = (RUB)(e.drive_chain * k);
	e.pad_brakes = (RUB)(e.pad_brakes * k);
	e.led_lights = (RUB)(e.led_lights * k);
	e.cargo_baskets = (RUB)(e.cargo_baskets * k);
	e.rack_parking = (RUB)(e.rack_parking * k);
	e.safety_helmet = (RUB)(e.safety_helmet * k);
}

void inflate_subway(SubwayTransit& s, double k) {
	s.single_token = (RUB)(s.single_token * k);
	s.smart_card_pass = (RUB)(s.smart_card_pass * k);
	s.card_issuance = (RUB)(s.card_issuance * k);
	s.balance_recharge = (RUB)(s.balance_recharge * k);
	s.gate_fines = (RUB)(s.gate_fines * k);
	s.interchange_fee = (RUB)(s.interchange_fee * k);
	s.platform_kiosk = (RUB)(s.platform_kiosk * k);
	s.heavy_luggage = (RUB)(s.heavy_luggage * k);
}

void inflate_tramway(ElectricTramway& e, double k) {
	e.conductor_ticket = (RUB)(e.conductor_ticket * k);
	e.monthly_ticket = (RUB)(e.monthly_ticket * k);
	e.transit_pass = (RUB)(e.transit_pass * k);
	e.wallet_topup = (RUB)(e.wallet_topup * k);
	e.violation_fines = (RUB)(e.violation_fines * k);
	e.baggage_fare = (RUB)(e.baggage_fare * k);
	e.stop_snacks = (RUB)(e.stop_snacks * k);
	e.route_transfer = (RUB)(e.route_transfer * k);
}

void inflate_aviation(AviationTravel& a, double k) {
	a.flight_tickets = (RUB)(a.flight_tickets * k);
	a.checked_bags = (RUB)(a.checked_bags * k);
	a.excess_weight = (RUB)(a.excess_weight * k);
	a.flight_insurance = (RUB)(a.flight_insurance * k);
	a.terminal_shuttle = (RUB)(a.terminal_shuttle * k);
	a.cabin_meals = (RUB)(a.cabin_meals * k);
	a.resort_hotel = (RUB)(a.resort_hotel * k);
	a.entry_visa = (RUB)(a.entry_visa * k);
	a.foreign_taxi = (RUB)(a.foreign_taxi * k);
	a.local_souvenirs = (RUB)(a.local_souvenirs * k);
}

void inflate_canine(CanineCompanion& c, double k) {
	c.kibble_diet = (RUB)(c.kibble_diet * k);
	c.vet_checkups = (RUB)(c.vet_checkups * k);
	c.chew_toys = (RUB)(c.chew_toys * k);
	c.salon_grooming = (RUB)(c.salon_grooming * k);
	c.medical_pills = (RUB)(c.medical_pills * k);
	c.obedience_training = (RUB)(c.obedience_training * k);
}

void inflate_feline(FelineCompanion& f, double k) {
	f.canned_meat = (RUB)(f.canned_meat * k);
	f.veterinary_care = (RUB)(f.veterinary_care * k);
	f.silica_litter = (RUB)(f.silica_litter * k);
	f.plush_mice = (RUB)(f.plush_mice * k);
	f.scratching_boards = (RUB)(f.scratching_boards * k);
	f.pharmacy_drops = (RUB)(f.pharmacy_drops * k);
}

void inflate_avian(AvianPet& a, double k) {
	a.seed_mixtures = (RUB)(a.seed_mixtures * k);
	a.avian_doctor = (RUB)(a.avian_doctor * k);
	a.metal_cage = (RUB)(a.metal_cage * k);
	a.swing_mirrors = (RUB)(a.swing_mirrors * k);
	a.liquid_vitamins = (RUB)(a.liquid_vitamins * k);
	a.sand_substrate = (RUB)(a.sand_substrate * k);
}

void inflate_aquatic(AquaticPet& a, double k) {
	a.flake_rations = (RUB)(a.flake_rations * k);
	a.glass_aquarium = (RUB)(a.glass_aquarium * k);
	a.water_filter = (RUB)(a.water_filter * k);
	a.led_lighting = (RUB)(a.led_lighting * k);
	a.aquarium_remedies = (RUB)(a.aquarium_remedies * k);
	a.underwater_plants = (RUB)(a.underwater_plants * k);
}

void apply_inflation(Person& p, double rate) {
	double k = 1.0 + rate / 12.0 / 100.0;

	inflate_dietary(p.dietary, k);
	inflate_licenses(p.licenses, k);
	inflate_leisure(p.leisure, k);
	inflate_estate(p.estate, k);
	inflate_medical(p.medical, k);
	inflate_wardrobe(p.wardrobe, k);
	inflate_growth(p.growth, k);
	inflate_offerings(p.offerings, k);
	inflate_hygiene(p.hygiene, k);
	inflate_passions(p.passions, k);
	inflate_vehicle(p.mobility.vehicle, k);
	inflate_shuttle(p.mobility.shuttle, k);
	inflate_cycle(p.mobility.cycle, k);
	inflate_subway(p.mobility.subway, k);
	inflate_tramway(p.mobility.tramway, k);
	inflate_aviation(p.mobility.aviation, k);
	inflate_canine(p.canine, k);
	inflate_feline(p.feline, k);
	inflate_avian(p.avian, k);
	inflate_aquatic(p.aquatic, k);
}

void print_dietary(const DietaryBasket& d) {
	printf("dietary total=%lld\n", total_dietary(d));
	printf("dietary:\n");
	printf("espresso_beans=%lld, organic_milk=%lld, rolled_oats=%lld, basmati_rice=%lld, wheat_pasta=%lld, artisan_bread=%lld\n",
		d.espresso_beans, d.organic_milk, d.rolled_oats, d.basmati_rice, d.wheat_pasta, d.artisan_bread);
	printf("farm_eggs=%lld, chicken_breasts=%lld, cheddar_cheese=%lld, greek_yogurt=%lld\n",
		d.farm_eggs, d.chicken_breasts, d.cheddar_cheese, d.greek_yogurt);
	printf("raw_potatoes=%lld, yellow_onions=%lld, red_tomatoes=%lld, fresh_apples=%lld, sweet_bananas=%lld\n",
		d.raw_potatoes, d.yellow_onions, d.red_tomatoes, d.fresh_apples, d.sweet_bananas);
	printf("frozen_greens=%lld, sunflower_oil=%lld, dried_lentils=%lld\n",
		d.frozen_greens, d.sunflower_oil, d.dried_lentils);
}

void print_licenses(const DigitalLicenses& d) {
	printf("licenses total=%lld\n", total_licenses(d));
	printf("licenses:\n");
	printf("video_premium=%lld, music_hd=%lld, movie_network=%lld, local_plus=%lld, chat_premium=%lld\n",
		d.video_premium, d.music_hd, d.movie_network, d.local_plus, d.chat_premium);
	printf("ai_pro_token=%lld, cinema_pass=%lld, audio_cloud=%lld, drive_storage=%lld, cloud_backup=%lld\n",
		d.ai_pro_token, d.cinema_pass, d.audio_cloud, d.drive_storage, d.cloud_backup);
	printf("office_cloud=%lld, secure_vpn=%lld, console_plus=%lld, game_pass_ultimate=%lld, design_cloud=%lld\n",
		d.office_cloud, d.secure_vpn, d.console_plus, d.game_pass_ultimate, d.design_cloud);
	printf("git_pro_host=%lld, backup_box=%lld, workspace_notes=%lld, graphics_pro=%lld, language_app=%lld\n",
		d.git_pro_host, d.backup_box, d.workspace_notes, d.graphics_pro, d.language_app);
}

void print_leisure(const SocialLeisure& s) {
	printf("leisure total=%lld\n", total_leisure(s));
	printf("leisure:\n");
	printf("movie_theatre=%lld, music_festivals=%lld, drama_plays=%lld, bistro_visits=%lld, fine_restaurants=%lld\n",
		s.movie_theatre, s.music_festivals, s.drama_plays, s.bistro_visits, s.fine_restaurants);
	printf("lounge_bars=%lld, fiction_books=%lld, digital_games=%lld, craft_materials=%lld, indie_movies=%lld\n",
		s.lounge_bars, s.fiction_books, s.digital_games, s.craft_materials, s.indie_movies);
	printf("art_museums=%lld, theme_parks=%lld, tabletop_games=%lld, stadium_events=%lld, vacation_tours=%lld\n",
		s.art_museums, s.theme_parks, s.tabletop_games, s.stadium_events, s.vacation_tours);
}

void print_estate(const ResidentialEstate& r) {
	printf("estate total=%lld\n", total_estate(r));
	printf("estate:\n");
	printf("lease_rent=%lld, bank_mortgage=%lld, power_bill=%lld, water_bill=%lld, thermal_heating=%lld, cooking_gas=%lld\n",
		r.lease_rent, r.bank_mortgage, r.power_bill, r.water_bill, r.thermal_heating, r.cooking_gas);
	printf("fiber_internet=%lld, mobile_network=%lld, maid_service=%lld, decor_furniture=%lld, structural_repairs=%lld\n",
		r.fiber_internet, r.mobile_network, r.maid_service, r.decor_furniture, r.structural_repairs);
	printf("alarm_security=%lld, land_tax=%lld, sanitary_chemicals=%lld, kitchen_appliances=%lld\n",
		r.alarm_security, r.land_tax, r.sanitary_chemicals, r.kitchen_appliances);
}

void print_medical(const MedicalCare& m) {
	printf("medical total=%lld\n", total_medical(m));
	printf("medical:\n");
	printf("prescription_drugs=%lld, daily_vitamins=%lld, dental_care_clinic=%lld, family_doctor=%lld, laboratory_tests=%lld\n",
		m.prescription_drugs, m.daily_vitamins, m.dental_care_clinic, m.family_doctor, m.laboratory_tests);
	printf("annual_screenings=%lld, medical_insurance=%lld, fitness_gym=%lld, therapy_massage=%lld, mental_counseling=%lld\n",
		m.annual_screenings, m.medical_insurance, m.fitness_gym, m.therapy_massage, m.mental_counseling);
	printf("optical_lenses=%lld, emergency_room=%lld, surgical_wards=%lld, clinic_rehab=%lld\n",
		m.optical_lenses, m.emergency_room, m.surgical_wards, m.clinic_rehab);
}

void print_wardrobe(const WardrobeCollection& w) {
	printf("wardrobe total=%lld\n", total_wardrobe(w));
	printf("wardrobe:\n");
	printf("winter_coats=%lld, casual_tees=%lld, classic_shirts=%lld, denim_trousers=%lld, tailored_suits=%lld\n",
		w.winter_coats, w.casual_tees, w.classic_shirts, w.denim_trousers, w.tailored_suits);
	printf("leather_shoes=%lld, running_sneakers=%lld, undergarments=%lld, thermal_socks=%lld, summer_hats=%lld\n",
		w.leather_shoes, w.running_sneakers, w.undergarments, w.thermal_socks, w.summer_hats);
	printf("fashion_accessories=%lld, valet_dry_clean=%lld, travel_backpacks=%lld, active_sportswear=%lld\n",
		w.fashion_accessories, w.valet_dry_clean, w.travel_backpacks, w.active_sportswear);
}

void print_growth(const IntellectualGrowth& i) {
	printf("growth total=%lld\n", total_growth(i));
	printf("growth:\n");
	printf("academy_courses=%lld, textbook_volumes=%lld, private_coaches=%lld, qualification_exams=%lld, diploma_certificates=%lld\n",
		i.academy_courses, i.textbook_volumes, i.private_coaches, i.qualification_exams, i.diploma_certificates);
	printf("web_learning_hubs=%lld, office_stationery=%lld, study_seminars=%lld, scientific_forums=%lld, speech_classes=%lld\n",
		i.web_learning_hubs, i.office_stationery, i.study_seminars, i.scientific_forums, i.speech_classes);
	printf("coding_bootcamps=%lld, ui_design_tracks=%lld\n",
		i.coding_bootcamps, i.ui_design_tracks);
}

void print_offerings(const TributeOfferings& t) {
	printf("offerings total=%lld\n", total_offerings(t));
	printf("offerings:\n");
	printf("parents_anniversary=%lld, friends_birthdays=%lld, winter_festivities=%lld, spring_celebration=%lld, autumn_holiday=%lld\n",
		t.parents_anniversary, t.friends_birthdays, t.winter_festivities, t.spring_celebration, t.autumn_holiday);
	printf("relationship_date=%lld, wedding_reception=%lld, children_parties=%lld, office_corporate=%lld, unexpected_surprises=%lld\n",
		t.relationship_date, t.wedding_reception, t.children_parties, t.office_corporate, t.unexpected_surprises);
}

void print_hygiene(const BodyHygiene& b) {
	printf("hygiene total=%lld\n", total_hygiene(b));
	printf("hygiene:\n");
	printf("hair_shampoo=%lld, beauty_cosmetics=%lld, luxury_parfum=%lld, barber_trim=%lld, nail_manicure=%lld\n",
		b.hair_shampoo, b.beauty_cosmetics, b.luxury_parfum, b.barber_trim, b.nail_manicure);
	printf("dermal_creams=%lld, shaving_foam=%lld, intimate_hygiene=%lld, resort_spa=%lld, hairstylist_salon=%lld\n",
		b.dermal_creams, b.shaving_foam, b.intimate_hygiene, b.resort_spa, b.hairstylist_salon);
	printf("oral_treatment=%lld, spray_deodorants=%lld\n",
		b.oral_treatment, b.spray_deodorants);
}

void print_passions(const AmateurPassions& a) {
	printf("passions total=%lld\n", total_passions(a));
	printf("passions:\n");
	printf("sketch_canvases=%lld, guitar_strings=%lld, camera_lenses=%lld, athletics_gear=%lld, river_fishing=%lld\n",
		a.sketch_canvases, a.guitar_strings, a.camera_lenses, a.athletics_gear, a.river_fishing);
	printf("antique_collecting=%lld, greenhouse_plants=%lld, home_diy_tools=%lld, ballroom_dancing=%lld, grandmaster_chess=%lld\n",
		a.antique_collecting, a.greenhouse_plants, a.home_diy_tools, a.ballroom_dancing, a.grandmaster_chess);
	printf("manual_crafting=%lld, studio_instruments=%lld\n",
		a.manual_crafting, a.studio_instruments);
}

void print_canine(const CanineCompanion& c) {
	printf("canine total=%lld\n", total_canine(c));
	printf("canine:\n");
	printf("kibble_diet=%lld, vet_checkups=%lld, chew_toys=%lld, salon_grooming=%lld, medical_pills=%lld, obedience_training=%lld\n",
		c.kibble_diet, c.vet_checkups, c.chew_toys, c.salon_grooming, c.medical_pills, c.obedience_training);
}

void print_feline(const FelineCompanion& f) {
	printf("feline total=%lld\n", total_feline(f));
	printf("feline:\n");
	printf("canned_meat=%lld, veterinary_care=%lld, silica_litter=%lld, plush_mice=%lld, scratching_boards=%lld, pharmacy_drops=%lld\n",
		f.canned_meat, f.veterinary_care, f.silica_litter, f.plush_mice, f.scratching_boards, f.pharmacy_drops);
}

void print_avian(const AvianPet& a) {
	printf("avian total=%lld\n", total_avian(a));
	printf("avian:\n");
	printf("seed_mixtures=%lld, avian_doctor=%lld, metal_cage=%lld, swing_mirrors=%lld, liquid_vitamins=%lld, sand_substrate=%lld\n",
		a.seed_mixtures, a.avian_doctor, a.metal_cage, a.swing_mirrors, a.liquid_vitamins, a.sand_substrate);
}

void print_aquatic(const AquaticPet& a) {
	printf("aquatic total=%lld\n", total_aquatic(a));
	printf("aquatic:\n");
	printf("flake_rations=%lld, glass_aquarium=%lld, water_filter=%lld, led_lighting=%lld, aquarium_remedies=%lld, underwater_plants=%lld\n",
		a.flake_rations, a.glass_aquarium, a.water_filter, a.led_lighting, a.aquarium_remedies, a.underwater_plants);
}

void print_vehicle(const PersonalVehicle& p) {
	printf("vehicle total=%lld\n", total_vehicle(p));
	printf("vehicle:\n");
	printf("asset_value=%lld, fuel_cost=%lld, insurance_policy=%lld, scheduled_service=%lld, unexpected_repairs=%lld, car_wash_valet=%lld, garage_parking=%lld, winter_tires=%lld, state_tax=%lld\n",
		p.asset_value, p.fuel_cost, p.insurance_policy, p.scheduled_service, p.unexpected_repairs, p.car_wash_valet, p.garage_parking, p.winter_tires, p.state_tax);
}

void print_shuttle(const PublicShuttle& p) {
	printf("shuttle total=%lld\n", total_shuttle(p));
	printf("shuttle:\n");
	printf("token_fare=%lld, commuter_pass=%lld, regional_routes=%lld, overweight_baggage=%lld, transit_fines=%lld, terminal_food=%lld, station_cab=%lld, power_bank=%lld\n",
		p.token_fare, p.commuter_pass, p.regional_routes, p.overweight_baggage, p.transit_fines, p.terminal_food, p.station_cab, p.power_bank);
}

void print_cycle(const EcoCycle& e) {
	printf("cycle total=%lld\n", total_cycle(e));
	printf("cycle:\n");
	printf("purchase_value=%lld, chain_lubrication=%lld, frame_repairs=%lld, rubber_tubes=%lld, drive_chain=%lld, pad_brakes=%lld, led_lights=%lld, cargo_baskets=%lld, rack_parking=%lld, safety_helmet=%lld\n",
		e.purchase_value, e.chain_lubrication, e.frame_repairs, e.rubber_tubes, e.drive_chain, e.pad_brakes, e.led_lights, e.cargo_baskets, e.rack_parking, e.safety_helmet);
}

void print_subway(const SubwayTransit& s) {
	printf("subway total=%lld\n", total_subway(s));
	printf("subway:\n");
	printf("single_token=%lld, smart_card_pass=%lld, card_issuance=%lld, balance_recharge=%lld, gate_fines=%lld, interchange_fee=%lld, platform_kiosk=%lld, heavy_luggage=%lld\n",
		s.single_token, s.smart_card_pass, s.card_issuance, s.balance_recharge, s.gate_fines, s.interchange_fee, s.platform_kiosk, s.heavy_luggage);
}

void print_tramway(const ElectricTramway& e) {
	printf("tramway total=%lld\n", total_tramway(e));
	printf("tramway:\n");
	printf("conductor_ticket=%lld, monthly_ticket=%lld, transit_pass=%lld, wallet_topup=%lld, violation_fines=%lld, baggage_fare=%lld, stop_snacks=%lld, route_transfer=%lld\n",
		e.conductor_ticket, e.monthly_ticket, e.transit_pass, e.wallet_topup, e.violation_fines, e.baggage_fare, e.stop_snacks, e.route_transfer);
}

void print_aviation(const AviationTravel& a) {
	printf("aviation total=%lld\n", total_aviation(a));
	printf("aviation:\n");
	printf("flight_tickets=%lld, checked_bags=%lld, excess_weight=%lld, flight_insurance=%lld, terminal_shuttle=%lld, cabin_meals=%lld, resort_hotel=%lld, entry_visa=%lld, foreign_taxi=%lld, local_souvenirs=%lld\n",
		a.flight_tickets, a.checked_bags, a.excess_weight, a.flight_insurance, a.terminal_shuttle, a.cabin_meals, a.resort_hotel, a.entry_visa, a.foreign_taxi, a.local_souvenirs);
}

void print_results(const Person& p) {
	printf("monthly_income=%lld\n", p.monthly_income);
	printf("checking_account=%lld\n", p.vault.checking_account);
	printf("deposit_account=%lld\n", p.vault.deposit_account);

	printf("\n");
	print_dietary(p.dietary);

	printf("\n");
	print_licenses(p.licenses);

	printf("\n");
	print_leisure(p.leisure);

	printf("\n");
	print_estate(p.estate);

	printf("\n");
	print_medical(p.medical);

	printf("\n");
	print_wardrobe(p.wardrobe);

	printf("\n");
	print_growth(p.growth);

	printf("\n");
	print_offerings(p.offerings);

	printf("\n");
	print_hygiene(p.hygiene);

	printf("\n");
	print_passions(p.passions);

	printf("\n");
	print_vehicle(p.mobility.vehicle);

	printf("\n");
	print_shuttle(p.mobility.shuttle);

	printf("\n");
	print_cycle(p.mobility.cycle);

	printf("\n");
	print_subway(p.mobility.subway);

	printf("\n");
	print_tramway(p.mobility.tramway);

	printf("\n");
	print_aviation(p.mobility.aviation);

	printf("\n");
	print_canine(p.canine);

	printf("\n");
	print_feline(p.feline);

	printf("\n");
	print_avian(p.avian);

	printf("\n");
	print_aquatic(p.aquatic);

	printf("\nanimals total=%lld\n", total_animals(p));
}

void process_month(Person* ptr, const char* name, int month, int year) {
	accrue_yield(*ptr, INVESTMENT_YIELD);
	clear_dietary(*ptr, INFLATION_RATE);
	clear_licenses(*ptr, INFLATION_RATE);
	clear_leisure(*ptr, INFLATION_RATE);
	clear_estate(*ptr, INFLATION_RATE);
	clear_medical(*ptr, INFLATION_RATE);
	clear_wardrobe(*ptr, INFLATION_RATE);
	clear_growth(*ptr, INFLATION_RATE);
	clear_offerings(*ptr, INFLATION_RATE);
	clear_hygiene(*ptr, INFLATION_RATE);
	clear_passions(*ptr, INFLATION_RATE);
	clear_mobility(*ptr, INFLATION_RATE);
	clear_all_animals(*ptr, INFLATION_RATE);
	send_to_vault(*ptr, 50000);
	earn_custom_revenue(*ptr, name, month, year);
}

void simulation(Person& p, const char* name) {
	int month = 10;
	int year = 2026;

	while (!(month == 11 && year == 2027)) {
		process_month(&p, name, month, year);

		++month;
		if (month == 13) {
			month = 1;
			++year;
		}
	}
}

PersonConfig make_alice_config() {
	PersonConfig alice_cfg = {
		200000, // income

		{ // dietary
			1200, // espresso_beans
			900,  // organic_milk
			500,  // rolled_oats
			700,  // basmati_rice
			800,  // wheat_pasta
			1000, // artisan_bread
			1200, // farm_eggs
			3500, // chicken_breasts
			1800, // cheddar_cheese
			900,  // greek_yogurt
			700,  // raw_potatoes
			400,  // yellow_onions
			1200, // red_tomatoes
			1300, // fresh_apples
			900,  // sweet_bananas
			1000, // frozen_greens
			500,  // sunflower_oil
			700   // dried_lentils
		},

		{ // licenses
			0,    // video_premium
			169,  // music_hd
			0,    // movie_network
			399,  // local_plus
			0,    // chat_premium
			0,    // ai_pro_token
			299,  // cinema_pass
			0,    // audio_cloud
			99,   // drive_storage
			99,   // cloud_backup
			0,    // office_cloud
			150,  // secure_vpn
			0,    // console_plus
			0,    // game_pass_ultimate
			0,    // design_cloud
			0,    // git_pro_host
			0,    // backup_box
			0,    // workspace_notes
			0,    // graphics_pro
			0     // language_app
		},

		{ // leisure
			600,  // movie_theatre
			0,    // music_festivals
			0,    // drama_plays
			1500, // bistro_visits
			2000, // fine_restaurants
			0,    // lounge_bars
			300,  // fiction_books
			500,  // digital_games
			700,  // craft_materials
			300,  // indie_movies
			0,    // art_museums
			0,    // theme_parks
			300,  // tabletop_games
			0,    // stadium_events
			1000  // vacation_tours
		},

		{ // estate
			25000, // lease_rent
			0,     // bank_mortgage
			2500,  // power_bill
			800,   // water_bill
			1500,  // thermal_heating
			300,   // cooking_gas
			700,   // fiber_internet
			700,   // mobile_network
			500,   // maid_service
			500,   // decor_furniture
			500,   // structural_repairs
			0,     // alarm_security
			0,     // land_tax
			1000,  // sanitary_chemicals
			500    // kitchen_appliances
		},

		{ // medical
			500,  // prescription_drugs
			300,  // daily_vitamins
			500,  // dental_care_clinic
			0,    // family_doctor
			500,  // laboratory_tests
			300,  // annual_screenings
			0,    // medical_insurance
			1500, // fitness_gym
			0,    // therapy_massage
			0,    // mental_counseling
			0,    // optical_lenses
			500,  // emergency_room
			0,    // surgical_wards
			0     // clinic_rehab
		},

		{ // wardrobe
			0,    // winter_coats
			500,  // casual_tees
			300,  // classic_shirts
			800,  // denim_trousers
			500,  // tailored_suits
			1000, // leather_shoes
			1000, // running_sneakers
			500,  // undergarments
			300,  // thermal_socks
			0,    // summer_hats
			300,  // fashion_accessories
			0,    // valet_dry_clean
			0,    // travel_backpacks
			500   // active_sportswear
		},

		{ // growth
			0,    // academy_courses
			300,  // textbook_volumes
			0,    // private_coaches
			0,    // qualification_exams
			0,    // diploma_certificates
			0,    // web_learning_hubs
			100,  // office_stationery
			0,    // study_seminars
			0,    // scientific_forums
			500,  // speech_classes
			0,    // coding_bootcamps
			0     // ui_design_tracks
		},

		{ // offerings
			500,  // parents_anniversary
			300,  // friends_birthdays
			500,  // winter_festivities
			300,  // spring_celebration
			300,  // autumn_holiday
			0,    // relationship_date
			0,    // wedding_reception
			300,  // children_parties
			0,    // office_corporate
			300   // unexpected_surprises
		},

		{ // hygiene
			300,  // hair_shampoo
			500,  // beauty_cosmetics
			0,    // luxury_parfum
			800,  // barber_trim
			0,    // nail_manicure
			500,  // dermal_creams
			200,  // shaving_foam
			500,  // intimate_hygiene
			0,    // resort_spa
			0,    // hairstylist_salon
			300,  // oral_treatment
			200   // spray_deodorants
		},

		{ // passions
			0,    // sketch_canvases
			300,  // guitar_strings
			0,    // camera_lenses
			500,  // athletics_gear
			0,    // river_fishing
			0,    // antique_collecting
			0,    // greenhouse_plants
			200,  // home_diy_tools
			0,    // ballroom_dancing
			100,  // grandmaster_chess
			200,  // manual_crafting
			0     // studio_instruments
		},

		{ // canine
			0, // kibble_diet
			0, // vet_checkups
			0, // chew_toys
			0, // salon_grooming
			0, // medical_pills
			0  // obedience_training
		},

		{ // feline
			1500, // canned_meat
			300,  // veterinary_care
			400,  // silica_litter
			100,  // plush_mice
			0,    // scratching_boards
			200   // pharmacy_drops
		},

		{ // avian
			0, // seed_mixtures
			0, // avian_doctor
			0, // metal_cage
			0, // swing_mirrors
			0, // liquid_vitamins
			0  // sand_substrate
		},

		{ // aquatic
			0, // flake_rations
			0, // glass_aquarium
			0, // water_filter
			0, // led_lighting
			0, // aquarium_remedies
			0  // underwater_plants
		},

		{ // mobility
			{ // vehicle
				0, // asset_value
				0, // fuel_cost
				0, // insurance_policy
				0, // scheduled_service
				0, // unexpected_repairs
				0, // car_wash_valet
				0, // garage_parking
				0, // winter_tires
				0  // state_tax
			},

			{ // shuttle
				0, // token_fare
				0, // commuter_pass
				0, // regional_routes
				0, // overweight_baggage
				0, // transit_fines
				0, // terminal_food
				0, // station_cab
				0  // power_bank
			},

			{ // cycle
				0, // purchase_value
				0, // chain_lubrication
				0, // frame_repairs
				0, // rubber_tubes
				0, // drive_chain
				0, // pad_brakes
				0, // led_lights
				0, // cargo_baskets
				0, // rack_parking
				0  // safety_helmet
			},

			{ // subway
				0,    // single_token
				2500, // smart_card_pass
				0,    // card_issuance
				0,    // balance_recharge
				0,    // gate_fines
				0,    // interchange_fee
				0,    // platform_kiosk
				0     // heavy_luggage
			},

			{ // tramway
				0, // conductor_ticket
				0, // monthly_ticket
				0, // transit_pass
				0, // wallet_topup
				0, // violation_fines
				0, // baggage_fare
				0, // stop_snacks
				0  // route_transfer
			},

			{ // aviation
				0, // flight_tickets
				0, // checked_bags
				0, // excess_weight
				0, // flight_insurance
				0, // terminal_shuttle
				0, // cabin_meals
				0, // resort_hotel
				0, // entry_visa
				0, // foreign_taxi
				0  // local_souvenirs
			}
		}
	};
	return alice_cfg;
}

PersonConfig make_Cheshire_config() {
	PersonConfig Cheshire_cfg = {
		80000, // income

		{ // dietary
			18, // espresso_beans
			8,  // organic_milk
			10, // rolled_oats
			5,  // basmati_rice
			7,  // wheat_pasta
			15, // artisan_bread
			8,  // farm_eggs
			30, // chicken_breasts
			14, // cheddar_cheese
			8,  // greek_yogurt
			5,  // raw_potatoes
			3,  // yellow_onions
			10, // red_tomatoes
			10, // fresh_apples
			5,  // sweet_bananas
			8,  // frozen_greens
			2,  // sunflower_oil
			4   // dried_lentils
		},

		{ // licenses
			200,  // video_premium
			150,  // music_hd
			400,  // movie_network
			300,  // local_plus
			200,  // chat_premium
			1500, // ai_pro_token
			250,  // cinema_pass
			150,  // audio_cloud
			100,  // drive_storage
			80,   // cloud_backup
			500,  // office_cloud
			200,  // secure_vpn
			600,  // console_plus
			700,  // game_pass_ultimate
			1200, // design_cloud
			80,   // git_pro_host
			150,  // backup_box
			200,  // workspace_notes
			180,  // graphics_pro
			300   // language_app
		},

		{ // leisure
			400,  // movie_theatre
			1500, // music_festivals
			700,  // drama_plays
			1200, // bistro_visits
			2000, // fine_restaurants
			800,  // lounge_bars
			500,  // fiction_books
			1000, // digital_games
			900,  // craft_materials
			600,  // indie_movies
			300,  // art_museums
			700,  // theme_parks
			400,  // tabletop_games
			1000, // stadium_events
			2500  // vacation_tours
		},

		{ // estate
			35000, // lease_rent
			0,     // bank_mortgage
			4500,  // power_bill
			1200,  // water_bill
			3000,  // thermal_heating
			800,   // cooking_gas
			900,   // fiber_internet
			1200,  // mobile_network
			2500,  // maid_service
			4000,  // decor_furniture
			3000,  // structural_repairs
			1500,  // alarm_security
			2000,  // land_tax
			1800,  // sanitary_chemicals
			2500   // kitchen_appliances
		},

		{ // medical
			1500,  // prescription_drugs
			800,   // daily_vitamins
			3000,  // dental_care_clinic
			2500,  // family_doctor
			2000,  // laboratory_tests
			1500,  // annual_screenings
			4000,  // medical_insurance
			2500,  // fitness_gym
			1200,  // therapy_massage
			2000,  // mental_counseling
			1800,  // optical_lenses
			3000,  // emergency_room
			0,     // surgical_wards
			0      // clinic_rehab
		},

		{ // wardrobe
			5000, // winter_coats
			2500, // casual_tees
			3000, // classic_shirts
			4000, // denim_trousers
			3500, // tailored_suits
			6000, // leather_shoes
			5500, // running_sneakers
			1500, // undergarments
			800,  // thermal_socks
			1200, // summer_hats
			2000, // fashion_accessories
			1000, // valet_dry_clean
			3500, // travel_backpacks
			3000  // active_sportswear
		},

		{ // growth
			5000, // academy_courses
			1500, // textbook_volumes
			4000, // private_coaches
			2500, // qualification_exams
			3000, // diploma_certificates
			1200, // web_learning_hubs
			700,  // office_stationery
			2000, // study_seminars
			3500, // scientific_forums
			2500, // speech_classes
			4500, // coding_bootcamps
			3000  // ui_design_tracks
		},

		{ // offerings
			4000, // parents_anniversary
			2500, // friends_birthdays
			5000, // winter_festivities
			3000, // spring_celebration
			3000, // autumn_holiday
			4000, // relationship_date
			6000, // wedding_reception
			3500, // children_parties
			2500, // office_corporate
			2000  // unexpected_surprises
		},

		{ // hygiene
			700,  // hair_shampoo
			2500, // beauty_cosmetics
			3000, // luxury_parfum
			1500, // barber_trim
			1800, // nail_manicure
			2000, // dermal_creams
			600,  // shaving_foam
			1200, // intimate_hygiene
			2500, // resort_spa
			1500, // hairstylist_salon
			1000, // oral_treatment
			500   // spray_deodorants
		},

		{ // passions
			1500, // sketch_canvases
			2500, // guitar_strings
			3000, // camera_lenses
			2000, // athletics_gear
			1200, // river_fishing
			1000, // antique_collecting
			800,  // greenhouse_plants
			1500, // home_diy_tools
			1800, // ballroom_dancing
			500,  // grandmaster_chess
			1200, // manual_crafting
			4000  // studio_instruments
		},

		{ // canine
			3000, // kibble_diet
			1000, // vet_checkups
			500,  // chew_toys
			700,  // salon_grooming
			400,  // medical_pills
			800   // obedience_training
		},

		{ // feline
			2000, // canned_meat
			800,  // veterinary_care
			300,  // silica_litter
			400,  // plush_mice
			500,  // scratching_boards
			300   // pharmacy_drops
		},

		{ // avian
			1000, // seed_mixtures
			500,  // avian_doctor
			2000, // metal_cage
			300,  // swing_mirrors
			100,  // liquid_vitamins
			50    // sand_substrate
		},

		{ // aquatic
			500,  // flake_rations
			2000, // glass_aquarium
			300,  // water_filter
			100,  // led_lighting
			200,  // aquarium_remedies
			150   // underwater_plants
		},

		{ // mobility
			{ // vehicle
				1200000, // asset_value
				3000,    // fuel_cost
				5000,    // insurance_policy
				2500,    // scheduled_service
				4000,    // unexpected_repairs
				800,     // car_wash_valet
				1500,    // garage_parking
				2000,    // winter_tires
				1000     // state_tax
			},

			{ // shuttle
				50,   // token_fare
				1200, // commuter_pass
				300,  // regional_routes
				100,  // overweight_baggage
				0,    // transit_fines
				50,   // terminal_food
				0,    // station_cab
				0     // power_bank
			},

			{ // cycle
				30000, // purchase_value
				500,   // chain_lubrication
				700,   // frame_repairs
				400,   // rubber_tubes
				300,   // drive_chain
				100,   // pad_brakes
				100,   // led_lights
				100,   // cargo_baskets
				0,     // rack_parking
				500    // safety_helmet
			},

			{ // subway
				70,   // single_token
				2500, // smart_card_pass
				500,  // card_issuance
				0,    // balance_recharge
				0,    // gate_fines
				100,  // interchange_fee
				50,   // platform_kiosk
				0     // heavy_luggage
			},

			{ // tramway
				60,   // conductor_ticket
				2200, // monthly_ticket
				400,  // transit_pass
				0,    // wallet_topup
				0,    // violation_fines
				50,   // baggage_fare
				30,   // stop_snacks
				0     // route_transfer
			},

			{ // aviation
				5000, // flight_tickets
				2000, // checked_bags
				500,  // excess_weight
				1000, // flight_insurance
				700,  // terminal_shuttle
				3000, // cabin_meals
				5000, // resort_hotel
				0,    // entry_visa
				1000, // foreign_taxi
				500   // local_souvenirs
			}
		}
	};
	return Cheshire_cfg;
}

int main() {
	Person Alice;
	Person Cheshire;

	PersonConfig alice_cfg = make_alice_config();
	PersonConfig Cheshire_cfg = make_Cheshire_config();

	person_init(Alice, alice_cfg);
	person_init(Cheshire, Cheshire_cfg);

	simulation(Alice, "Alice");
	simulation(Cheshire, "Cheshire");

	printf("Alice final data:\n");
	print_results(Alice);

	printf("\nCheshire final data:\n");
	print_results(Cheshire);

	return 0;
}
