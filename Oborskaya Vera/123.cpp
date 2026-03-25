#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using RUB = long long int;

struct Car {
    RUB value;
    RUB gas;
    RUB insurance;
    RUB tires_winter;
    RUB tires_summer;
    RUB washing;
    RUB parking_home;
    RUB parking_work;
    RUB fines;
    RUB toll_roads;
    RUB repair;
    RUB diagnostics;
    RUB antifreeze;
    RUB oil_change;
};

struct Transport {
    RUB taxi;
    RUB carsharing;
    RUB pub;
};

struct Trip {
    RUB flight;
    RUB hotel;
    RUB meals;
    RUB excursions;
    RUB transport;
    RUB insurance;
    RUB visa;
    RUB souvenirs;
    RUB entertainment;
    RUB shopping;
};

struct Home {
    RUB rent;
    RUB farm;
    RUB electricity;
    RUB heating;
    RUB water;
    RUB gas;
    RUB garbage;
    RUB intercom;
    RUB furniture;
    RUB cleaning;
    RUB repair;
};

struct Dog {
    RUB dvalue;
    RUB dfood;
    RUB toys;
    RUB bed;
    RUB leash;
    RUB vet;
    RUB vaccines;
    RUB vitamins;
    RUB teeth_cleaning;
    RUB allergy_meds;
};

struct Cat {
    RUB cvalue;
    RUB cfood;
    RUB toys;
    RUB tray;
    RUB house_bed;
    RUB scratching_post;
    RUB cvet;
    RUB vitamins;
    RUB treats;
    RUB carrier;
    RUB dental_treats;
};

struct Wedding {
    RUB dress;
    RUB suit;
    RUB venue;
    RUB catering;
    RUB cake;
    RUB photographer;
    RUB music;
    RUB flowers;
    RUB rings;
    RUB transport;
    RUB honeymoon;
};

struct Child {
    bool isBorn;
    int birth_month;
    int birth_year;
    int age_years;
    RUB prenatal_vitamins;
    RUB doctor_visits;
    RUB ultrasound;
    RUB maternity_clothes;
    RUB childbirth;
    RUB stroller;
    RUB crib;
    RUB mattress;
    RUB bedding;
    RUB changing_table;
    RUB baby_bath;
    RUB baby_monitor;
    RUB diapers;
    RUB baby_wipes;
    RUB baby_clothes;
    RUB baby_food;
    RUB bottles;
    RUB pacifiers;
    RUB sterilizer;
    RUB bottle_warmer;
    RUB car_seat;
    RUB high_chair;
    RUB playpen;
    RUB toys;
    RUB books;
    RUB vaccinations;
    RUB pediatrician;
    RUB medications;
    RUB nanny;
    RUB nursery;
    RUB kindergarten;
    RUB school_supplies;
    RUB school_uniform;
    RUB tutoring;
    RUB music_school;
    RUB sports_section;
    RUB art_school;
    RUB summer_camp;
    RUB pocket_money;
    RUB birthday_party;
    RUB clothes_yearly;
    RUB shoes_yearly;
    RUB electronics;
    RUB mobile_phone;
    RUB internet_for_child;
    RUB psychologist;
    RUB speech_therapist;
    RUB dental_treatment;
    RUB glasses;
    RUB first_car;
    RUB university_tuition;
    RUB dormitory;
};

struct Bank {
    RUB account_rub;
    RUB deposit_rub;
};

struct Investments {
    RUB stocks;
    RUB bonds;
    RUB etf;
    RUB crypto;
    RUB mutual_funds;
    RUB gold;
    RUB real_estate_fund;
    RUB startup_investment;
    RUB total;
};

struct Education {
    RUB professional_courses;
    RUB language_courses;
    RUB mba;
    RUB books;
    RUB online_subscriptions;
    RUB conferences;
    RUB coaching;
    RUB software_licenses;
};

struct Healthcare {
    RUB medical_insurance;
    RUB fitness_club;
    RUB yoga;
    RUB massage;
    RUB psychologist;
    RUB vitamins_general;
    RUB regular_meds;
};

struct Entertainment {
    RUB cinema;
    RUB theater;
    RUB concerts;
    RUB museums;
    RUB quests;
    RUB bowling;
    RUB restaurants;
    RUB bars;
    RUB hookah;
    RUB alcohol;
    RUB cigarettes;
    RUB vape;
    RUB gaming_subscriptions;
    RUB game_purchases;
    RUB board_games;
};

struct Utilities {
    RUB internet;
    RUB mobile_family;
    RUB tv_subscription;
    RUB streaming_video;
    RUB streaming_music;
    RUB cloud_storage;
    RUB vpn;
    RUB antivirus;
};

struct Gifts {
    RUB birthday_family;
    RUB birthday_friends;
    RUB birthday_colleagues;
    RUB new_year;
    RUB march_8;
    RUB february_23;
    RUB children_birthdays;
    RUB donations;
};


struct Person {
    char name[50];
    int age;
    RUB salary;
    RUB bonus;
    RUB food;
    RUB food_delivery;
    Car car;
    Transport transport;
    Home home;
    Cat cat;
    Dog dog;
    Trip trip;
    Wedding wedding;
    Child child;
    Bank bank;
    Investments investments;
    Education education;
    Healthcare healthcare;
    Entertainment entertainment;
    Utilities utilities;
    Gifts gifts;
};

struct Family {
    Person husband;
    Person wife;
    bool isMarried;
    bool hasChildren;
    int child_age;

};

Family family;
int current_year = 2026;
int current_month = 1;
bool simulation_running = true;
RUB total_capital = 0;

void init_person(Person* p, const char* name, int age, RUB salary) {
    strcpy_s(p->name, name);
    p->age = age;
    p->salary = salary;
    p->bonus = 0;
    p->food = 20000;
    p->food_delivery = 5000;

    p->car.value = 3000000;
    p->car.gas = 15000;
    p->car.insurance = 5000;
    p->car.tires_winter = 20000;
    p->car.tires_summer = 20000;
    p->car.washing = 1000;
    p->car.parking_home = 5000;
    p->car.parking_work = 5000;
    p->car.fines = 0;
    p->car.toll_roads = 2000;
    p->car.repair = 5000;
    p->car.diagnostics = 3000;
    p->car.antifreeze = 1000;
    p->car.oil_change = 4000;

    p->transport.taxi = 3000;
    p->transport.carsharing = 2000;
    p->transport.pub = 2000;

    p->home.rent = 45000;
    p->home.farm = 2000;
    p->home.electricity = 4000;
    p->home.heating = 3000;
    p->home.water = 1500;
    p->home.gas = 500;
    p->home.garbage = 500;
    p->home.intercom = 300;
    p->home.furniture = 10000;
    p->home.cleaning = 1000;
    p->home.repair = 5000;

    p->cat.cvalue = 5000;
    p->cat.cfood = 3000;
    p->cat.toys = 2000;
    p->cat.tray = 1000;
    p->cat.house_bed = 1500;
    p->cat.scratching_post = 5000;
    p->cat.cvet = 2000;
    p->cat.vitamins = 2000;
    p->cat.treats = 500;
    p->cat.carrier = 2500;
    p->cat.dental_treats = 800;

    p->dog.dvalue = 30000;
    p->dog.dfood = 5000;
    p->dog.toys = 1500;
    p->dog.bed = 3000;
    p->dog.leash = 3500;
    p->dog.vet = 3000;
    p->dog.vaccines = 4000;
    p->dog.vitamins = 1000;
    p->dog.teeth_cleaning = 3000;
    p->dog.allergy_meds = 2000;

    p->wedding.dress = 50000;
    p->wedding.suit = 30000;
    p->wedding.venue = 100000;
    p->wedding.catering = 80000;
    p->wedding.photographer = 40000;
    p->wedding.music = 25000;
    p->wedding.flowers = 20000;
    p->wedding.cake = 10000;
    p->wedding.rings = 30000;
    p->wedding.honeymoon = 200000;
    p->wedding.transport = 15000;

    p->child.isBorn = false;
    p->child.birth_month = 0;
    p->child.birth_year = 0;
    p->child.age_years = 0;
    p->child.prenatal_vitamins = 5000;
    p->child.doctor_visits = 3000;
    p->child.ultrasound = 5500;
    p->child.maternity_clothes = 20000;
    p->child.childbirth = 80000;
    p->child.stroller = 40000;
    p->child.crib = 30000;
    p->child.mattress = 7000;
    p->child.bedding = 4000;
    p->child.changing_table = 8000;
    p->child.baby_bath = 2000;
    p->child.baby_monitor = 5000;
    p->child.diapers = 5000;
    p->child.baby_wipes = 1500;
    p->child.baby_clothes = 5000;
    p->child.baby_food = 6000;
    p->child.bottles = 3000;
    p->child.pacifiers = 1500;
    p->child.sterilizer = 4000;
    p->child.bottle_warmer = 2500;
    p->child.car_seat = 15000;
    p->child.high_chair = 8000;
    p->child.playpen = 6000;
    p->child.toys = 3000;
    p->child.books = 1500;
    p->child.vaccinations = 5000;
    p->child.pediatrician = 2500;
    p->child.medications = 5000;
    p->child.nanny = 30000;
    p->child.nursery = 25000;
    p->child.kindergarten = 20000;
    p->child.school_supplies = 10000;
    p->child.school_uniform = 8000;
    p->child.tutoring = 15000;
    p->child.music_school = 8000;
    p->child.sports_section = 7000;
    p->child.art_school = 5000;
    p->child.summer_camp = 30000;
    p->child.pocket_money = 2000;
    p->child.birthday_party = 15000;
    p->child.clothes_yearly = 20000;
    p->child.shoes_yearly = 10000;
    p->child.electronics = 50000;
    p->child.mobile_phone = 20000;
    p->child.internet_for_child = 1000;
    p->child.psychologist = 3000;
    p->child.speech_therapist = 4000;
    p->child.dental_treatment = 5000;
    p->child.glasses = 10000;
    p->child.first_car = 500000;
    p->child.university_tuition = 300000;
    p->child.dormitory = 50000;

    p->bank.account_rub = 0;
    p->bank.deposit_rub = 0;

    p->investments.stocks = 0;
    p->investments.bonds = 0;
    p->investments.etf = 0;
    p->investments.crypto = 0;
    p->investments.mutual_funds = 0;
    p->investments.gold = 0;
    p->investments.real_estate_fund = 0;
    p->investments.startup_investment = 0;
    p->investments.total = 0;


    p->education.professional_courses = 20000;
    p->education.language_courses = 15000;
    p->education.mba = 0;
    p->education.books = 5000;
    p->education.online_subscriptions = 3000;
    p->education.conferences = 10000;
    p->education.coaching = 8000;
    p->education.software_licenses = 5000;

    p->healthcare.medical_insurance = 15000;
    p->healthcare.fitness_club = 4000;
    p->healthcare.yoga = 3000;
    p->healthcare.massage = 4000;
    p->healthcare.psychologist = 5000;
    p->healthcare.vitamins_general = 2000;
    p->healthcare.regular_meds = 3000;


    p->entertainment.cinema = 2000;
    p->entertainment.theater = 4000;
    p->entertainment.concerts = 5000;
    p->entertainment.museums = 1000;
    p->entertainment.quests = 2000;
    p->entertainment.bowling = 1500;
    p->entertainment.restaurants = 8000;
    p->entertainment.bars = 5000;
    p->entertainment.hookah = 2000;
    p->entertainment.alcohol = 4000;
    p->entertainment.cigarettes = 0;
    p->entertainment.vape = 0;
    p->entertainment.gaming_subscriptions = 1000;
    p->entertainment.game_purchases = 2000;
    p->entertainment.board_games = 1500;

    p->utilities.internet = 800;
    p->utilities.mobile_family = 1500;
    p->utilities.tv_subscription = 500;
    p->utilities.streaming_video = 800;
    p->utilities.streaming_music = 300;
    p->utilities.cloud_storage = 200;
    p->utilities.vpn = 500;
    p->utilities.antivirus = 300;

    p->gifts.birthday_family = 5000;
    p->gifts.birthday_friends = 3000;
    p->gifts.birthday_colleagues = 2000;
    p->gifts.new_year = 10000;
    p->gifts.march_8 = 3000;
    p->gifts.february_23 = 3000;
    p->gifts.children_birthdays = 2000;
    p->gifts.donations = 1000;

    p->trip.flight = 85000;
    p->trip.hotel = 150000;
    p->trip.meals = 38000;
    p->trip.excursions = 30000;
    p->trip.transport = 30000;
    p->trip.insurance = 5000;
    p->trip.visa = 8000;
    p->trip.souvenirs = 20000;
    p->trip.entertainment = 45000;
    p->trip.shopping = 15000;
}

void init_family() {
    init_person(&family.husband, "Alexander", 30, 200000);
    init_person(&family.wife, "Alice", 26, 350000);
    family.isMarried = false;
    family.hasChildren = false;
    family.child_age = 0;

    family.husband.bank.account_rub = 500000;
    family.wife.bank.account_rub = 500000;
}

float get_inflation_rate(int year, const char* category) {
    if (strcmp(category, "food") == 0) {
        if (year == 2026) return 12.5;
        if (year == 2027) return 14.0;
        if (year == 2028) return 13.0;
        return 10.0;
    }
    if (strcmp(category, "fuel") == 0) {
        if (year == 2026) return 6.5;
        if (year == 2027) return 7.0;
        if (year == 2028) return 8.0;
        return 7.0;
    }
    if (strcmp(category, "rent") == 0) {
        if (year == 2026) return 8.5;
        if (year == 2027) return 9.0;
        if (year == 2028) return 9.5;
        return 8.5;
    }
    if (strcmp(category, "utilities") == 0) {
        if (year == 2026) return 7.5;
        if (year == 2027) return 8.0;
        if (year == 2028) return 8.5;
        return 7.5;
    }
    if (strcmp(category, "vet") == 0) {
        return 9.5;
    }
    if (strcmp(category, "travel") == 0) {
        return 10.5;
    }
    return 8.0;
}

void apply_inflation(Person* p, int year) {
    float food_inf = get_inflation_rate(year, "food");
    p->food += p->food * food_inf / 100.0;
    p->food_delivery += p->food_delivery * food_inf / 100.0;

    float fuel_inf = get_inflation_rate(year, "fuel");
    p->car.gas += p->car.gas * fuel_inf / 100.0;
    p->car.toll_roads += p->car.toll_roads * fuel_inf / 100.0;
    p->car.insurance += p->car.insurance * fuel_inf / 100.0;
    p->car.repair += p->car.repair * fuel_inf / 100.0;
    p->car.oil_change += p->car.oil_change * fuel_inf / 100.0;

    float rent_inf = get_inflation_rate(year, "rent");
    p->home.rent += p->home.rent * rent_inf / 100.0;

    float util_inf = get_inflation_rate(year, "utilities");
    p->home.electricity += p->home.electricity * util_inf / 100.0;
    p->home.heating += p->home.heating * util_inf / 100.0;
    p->home.water += p->home.water * util_inf / 100.0;
    p->home.gas += p->home.gas * util_inf / 100.0;

    float vet_inf = get_inflation_rate(year, "vet");
    p->cat.cfood += p->cat.cfood * fuel_inf / 100.0;
    p->cat.cvet += p->cat.cvet * vet_inf / 100.0;
    p->dog.dfood += p->dog.dfood * fuel_inf / 100.0;
    p->dog.vet += p->dog.vet * vet_inf / 100.0;

    float travel_inf = get_inflation_rate(year, "travel");
    p->trip.flight += p->trip.flight * travel_inf / 100.0;
    p->trip.hotel += p->trip.hotel * travel_inf / 100.0;
    p->trip.meals += p->trip.meals * travel_inf / 100.0;
    p->trip.excursions += p->trip.excursions * travel_inf / 100.0;
}


void apply_salary(Person* p, int month, int year) {
    if (month == 3) {
        p->salary *=  1.2;
    }

    if (month == 12) {
        p->bonus = p->salary * 1.5;
        p->bank.account_rub += p->bonus;
    }

    p->bank.account_rub += p->salary;

    RUB tax = p->salary * 0.13;
    p->bank.account_rub -= tax;
}

void apply_food_expenses(Person* p, int month) {
    p->bank.account_rub -= p->food;

    if (month % 2 == 0) {
        p->bank.account_rub -= p->food_delivery;
    }
}

void apply_housing_expenses(Person* p, int month) {
    p->bank.account_rub -= p->home.rent;
    p->bank.account_rub -= p->home.electricity;
    p->bank.account_rub -= p->home.heating;
    p->bank.account_rub -= p->home.water;
    p->bank.account_rub -= p->home.gas;
    p->bank.account_rub -= p->home.garbage;
    p->bank.account_rub -= p->home.intercom;

    if (month % 3 == 0) {
        p->bank.account_rub -= p->home.farm;
        p->bank.account_rub -= p->home.cleaning;
    }

    if (month == 6 || month == 12) {
        p->bank.account_rub -= p->home.repair;
    }
    if (month == 5 || month == 11) {
        p->bank.account_rub -= p->home.furniture;
    }
}

void apply_car_expenses(Person* p, int month, int year) {
    p->bank.account_rub -= p->car.gas;
    p->bank.account_rub -= p->car.toll_roads;

    if (month % 2 == 0) {
        p->bank.account_rub -= p->car.washing;
    }

    p->bank.account_rub -= p->car.parking_home;
    p->bank.account_rub -= p->car.parking_work;

    if (month == 10) {
        p->bank.account_rub -= p->car.tires_winter;
        p->bank.account_rub -= p->car.diagnostics;
    }
    if (month == 4) {
        p->bank.account_rub -= p->car.tires_summer;
        p->bank.account_rub -= p->car.diagnostics;
    }

    if (month == 6 || month == 12) {
        p->bank.account_rub -= p->car.oil_change;
        p->bank.account_rub -= p->car.antifreeze;
    }

    if (month == 12) {
        p->bank.account_rub -= p->car.insurance;
        p->bank.account_rub -= p->car.repair;
    }

    if (rand() % 100 < 5) {
        RUB fine = 500 + rand() % 5000;
        p->car.fines += fine;
        p->bank.account_rub -= fine;
    }
}

void apply_transport_expenses(Person* p, int month) {
    p->bank.account_rub -= p->transport.pub;

    if (month % 2 == 0) {
        p->bank.account_rub -= p->transport.taxi;
    }
    if (month % 3 == 0) {
        p->bank.account_rub -= p->transport.carsharing;
    }
}

void apply_trip_expenses(Person* p, int month) {
    p->bank.account_rub -= p->trip.flight;
    p->bank.account_rub -= p->trip.hotel;
    p->bank.account_rub -= p->trip.meals;
    p->bank.account_rub -= p->trip.excursions;
    p->bank.account_rub -= p->trip.transport;
    p->bank.account_rub -= p->trip.insurance;
    p->bank.account_rub -= p->trip.visa;
    p->bank.account_rub -= p->trip.souvenirs;
    p->bank.account_rub -= p->trip.shopping;
    p->bank.account_rub -= p->trip.entertainment;
}

void apply_child_expenses(Person* p, int month, int year, bool has_child, int child_age) {
    if (!has_child) return;

    if (child_age < 1) {
    
        p->bank.account_rub -= p->child.diapers;
        p->bank.account_rub -= p->child.baby_wipes;
        p->bank.account_rub -= p->child.baby_clothes;
        p->bank.account_rub -= p->child.baby_food;
        p->bank.account_rub -= p->child.medications;
        p->bank.account_rub -= p->child.pediatrician;
        p->bank.account_rub -= p->child.toys;

        if (month == 3 || month == 6 || month == 9 || month == 12) {
            p->bank.account_rub -= p->child.vaccinations;
        }
    }
    else if (child_age >= 1 && child_age < 3) {
       
        p->bank.account_rub -= p->child.diapers;
        p->bank.account_rub -= p->child.baby_wipes;
        p->bank.account_rub -= p->child.baby_clothes;
        p->bank.account_rub -= p->child.baby_food;
        p->bank.account_rub -= p->child.toys;
        p->bank.account_rub -= p->child.books;
        p->bank.account_rub -= p->child.medications;
        p->bank.account_rub -= p->child.pediatrician;

        if (month == 12) {
            p->bank.account_rub -= p->child.vaccinations;
        }
        if (month == p->child.birth_month) {
            p->bank.account_rub -= p->child.birthday_party;
        }
    }
    else if (child_age >= 3 && child_age < 7) {

        p->bank.account_rub -= p->child.kindergarten;
        p->bank.account_rub -= p->child.clothes_yearly / 12;
        p->bank.account_rub -= p->child.shoes_yearly / 12;
        p->bank.account_rub -= p->child.toys;
        p->bank.account_rub -= p->child.books;
        p->bank.account_rub -= p->child.medications;

        if (month == 9) {
            p->bank.account_rub -= p->child.school_supplies;
        }
        if (month == p->child.birth_month) {
            p->bank.account_rub -= p->child.birthday_party;
        }
        if (month == 6) {
            p->bank.account_rub -= p->child.summer_camp / 2;
        }
    }
    else if (child_age >= 7 && child_age < 12) {
      
        p->bank.account_rub -= p->child.tutoring;
        p->bank.account_rub -= p->child.sports_section;
        p->bank.account_rub -= p->child.music_school;
        p->bank.account_rub -= p->child.clothes_yearly / 12;
        p->bank.account_rub -= p->child.shoes_yearly / 12;
        p->bank.account_rub -= p->child.pocket_money;
        p->bank.account_rub -= p->child.books;
        p->bank.account_rub -= p->child.medications;

        if (month == 8) {
            p->bank.account_rub -= p->child.school_supplies;
            p->bank.account_rub -= p->child.school_uniform;
        }
        if (month == 6) {
            p->bank.account_rub -= p->child.summer_camp;
        }
        if (month == p->child.birth_month) {
            p->bank.account_rub -= p->child.birthday_party;
        }
        if (month == 12) {
            p->bank.account_rub -= p->child.electronics / 4;
        }
    }
    else if (child_age >= 12 && child_age < 18) {
        
        p->bank.account_rub -= p->child.tutoring;
        p->bank.account_rub -= p->child.sports_section;
        p->bank.account_rub -= p->child.clothes_yearly / 12;
        p->bank.account_rub -= p->child.shoes_yearly / 12;
        p->bank.account_rub -= p->child.pocket_money;
        p->bank.account_rub -= p->child.mobile_phone / 12;
        p->bank.account_rub -= p->child.internet_for_child;

        if (month == 8) {
            p->bank.account_rub -= p->child.school_supplies;
        }
        if (month == 6) {
            p->bank.account_rub -= p->child.summer_camp;
        }
        if (month == p->child.birth_month) {
            p->bank.account_rub -= p->child.birthday_party;
        }
        if (month == 1 || month == 7) {
            p->bank.account_rub -= p->child.dental_treatment;
        }
        if (child_age >= 16 && month == 9) {
            p->bank.account_rub -= p->child.psychologist;
            p->bank.account_rub -= p->child.speech_therapist;
        }
        if (child_age == 18 && month == 1) {
            p->bank.account_rub -= p->child.first_car;
        }
    }
    else if (child_age >= 18) {
       
        p->bank.account_rub -= p->child.university_tuition / 12;
        p->bank.account_rub -= p->child.dormitory;
        p->bank.account_rub -= p->child.pocket_money;
        p->bank.account_rub -= p->child.clothes_yearly / 12;

        if (month == 8) {
            p->bank.account_rub -= p->child.school_supplies;
            p->bank.account_rub -= p->child.electronics / 2;
        }
        if (month == p->child.birth_month) {
            p->bank.account_rub -= p->child.birthday_party;
        }
    }
}

void apply_cat_expenses(Person* p, int month, bool has_cat) {
    if (!has_cat) return;

    p->bank.account_rub -= p->cat.cfood;

    if (month % 2 == 0) {
        p->bank.account_rub -= p->cat.treats;
    }
    if (month % 3 == 0) {
        p->bank.account_rub -= p->cat.toys;
        p->bank.account_rub -= p->cat.dental_treats;
    }
    if (month % 4 == 0) {
        p->bank.account_rub -= p->cat.cvet;
        p->bank.account_rub -= p->cat.vitamins;
    }
    if (month  == 1) {
        p->bank.account_rub -= p->cat.tray;
        p->bank.account_rub -= p->cat.house_bed;
        p->bank.account_rub -= p->cat.scratching_post;
        p->bank.account_rub -= p->cat.carrier;

    }
}

void apply_dog_expenses(Person* p, int month, bool has_dog) {
    if (!has_dog) return;

    p->bank.account_rub -= p->dog.dfood;

    if (month % 2 == 0) {
        p->bank.account_rub -= p->dog.allergy_meds;
    }
    if (month % 3 == 0) {
        p->bank.account_rub -= p->dog.toys;
        p->bank.account_rub -= p->dog.teeth_cleaning;
    }
    if (month % 4 == 0) {
        p->bank.account_rub -= p->dog.vet;
        p->bank.account_rub -= p->dog.vitamins;
    }
    if (month == 3) {
        p->bank.account_rub -= p->dog.vaccines;
    }
    if (month == 1) {
        p->bank.account_rub -= p->dog.bed;
        p->bank.account_rub -= p->dog.leash;
    }
}

void apply_entertainment_expenses(Person* p, int month) {
    if (month % 2 == 0) {
        p->bank.account_rub -= p->entertainment.cinema;
        p->bank.account_rub -= p->entertainment.bowling;
    }
    if (month % 3 == 0) {
        p->bank.account_rub -= p->entertainment.theater;
        p->bank.account_rub -= p->entertainment.concerts;
        p->bank.account_rub -= p->entertainment.quests;
        p->bank.account_rub -= p->entertainment.restaurants;
        p->bank.account_rub -= p->entertainment.museums;
    }
    if (month % 4 == 0) {
        p->bank.account_rub -= p->entertainment.bars;
        p->bank.account_rub -= p->entertainment.hookah;
    }
    if (month % 5 == 0) {
        p->bank.account_rub -= p->entertainment.board_games;
        p->bank.account_rub -= p->entertainment.game_purchases;
    }

    p->bank.account_rub -= p->entertainment.alcohol;
    p->bank.account_rub -= p->entertainment.gaming_subscriptions;
    p->bank.account_rub -= p->entertainment.cigarettes;
    p->bank.account_rub -= p->entertainment.vape;
}

void apply_utilities_expenses(Person* p, int month) {
    p->bank.account_rub -= p->utilities.internet;
    p->bank.account_rub -= p->utilities.mobile_family;
    p->bank.account_rub -= p->utilities.tv_subscription;
    p->bank.account_rub -= p->utilities.streaming_video;
    p->bank.account_rub -= p->utilities.streaming_music;
    p->bank.account_rub -= p->utilities.cloud_storage;
    p->bank.account_rub -= p->utilities.vpn;
    p->bank.account_rub -= p->utilities.antivirus;
}

void apply_gifts_expenses(Person* p, int month) {
    if (month == 1) {
        p->bank.account_rub -= p->gifts.new_year;
    }
    if (month == 2) {
        p->bank.account_rub -= p->gifts.february_23;
    }
    if (month == 3) {
        p->bank.account_rub -= p->gifts.march_8;
    }
    if (month == 6 || month == 12) {
        p->bank.account_rub -= p->gifts.birthday_family;
    }
    if (month == 9) {
        p->bank.account_rub -= p->gifts.children_birthdays;
    }
    if (month == 7) {
        p->bank.account_rub -= p->gifts.birthday_friends;
    }
    if (month == 4) {
        p->bank.account_rub -= p->gifts.birthday_colleagues;
    }

    p->bank.account_rub -= p->gifts.donations;
}

void apply_healthcare_expenses(Person* p, int month) {
    if (month == 1) {
        p->bank.account_rub -= p->healthcare.medical_insurance;
    }

    if (month == 6) {
        p->bank.account_rub -= p->healthcare.psychologist;
    }

    p->bank.account_rub -= p->healthcare.vitamins_general;
    p->bank.account_rub -= p->healthcare.regular_meds;

    if (month % 2 == 0) {
        p->bank.account_rub -= p->healthcare.fitness_club;
    }
    if (month % 3 == 0) {
        p->bank.account_rub -= p->healthcare.massage;
        p->bank.account_rub -= p->healthcare.yoga;
    }
}

void apply_education_expenses(Person* p, int month) {
    if (month == 1 || month == 8) {
        p->bank.account_rub -= p->education.professional_courses;
        p->bank.account_rub -= p->education.books;
    }
    if (month == 9) {
        p->bank.account_rub -= p->education.language_courses;
    }
    if (month == 3) {
        p->bank.account_rub -= p->education.mba;
    }
    if (month == 5) {
        p->bank.account_rub -= p->education.coaching;
    }
    if (month == 7) {
        p->bank.account_rub -= p->education.conferences;
    }

    p->bank.account_rub -= p->education.online_subscriptions;
    p->bank.account_rub -= p->education.software_licenses;
}

void apply_investments(Person* p, int month) {

    RUB invest_amount = p->salary * 0.10;
    if (month == 1 || month>4 ) {
        p->investments.crypto += 0.5 * invest_amount;
        p->investments.gold += 0.5 * invest_amount;
    }
    if (month == 2) {
        p->investments.stocks += 0.5 * invest_amount;
        p->investments.bonds += 0.5 * invest_amount;
    }
    if (month == 3) {
        p->investments.etf += 0.5 * invest_amount;
        p->investments.mutual_funds += 0.5 * invest_amount;
    }
    if (month == 4) {
        p->investments.real_estate_fund= 0.5 * invest_amount;
        p->investments.startup_investment += 0.5 * invest_amount;
    }
    p->bank.account_rub -= invest_amount;

    RUB stocks_return = p->investments.stocks * 0.01;
    p->investments.stocks += stocks_return;

    RUB bonds_return = p->investments.bonds * 0.008;
    p->investments.bonds += bonds_return;

    RUB crypto_return = p->investments.crypto * 0.1;
    p->investments.crypto += crypto_return;

    RUB gold_return = p->investments.gold * 0.05;
    p->investments.gold += gold_return;

    RUB etf_return = p->investments.etf * 0.0012;
    p->investments.etf += etf_return;

    RUB fund_return = p->investments.mutual_funds * 0.03;
    p->investments.mutual_funds += fund_return;

    RUB est_return = p->investments.real_estate_fund * 0.12;
    p->investments.real_estate_fund += est_return;

    RUB stup_return = p->investments.startup_investment * 0.2;
    p->investments.startup_investment += stup_return;

    p->investments.total = p->investments.gold + p->investments.crypto + p->investments.stocks + p->investments.startup_investment + p->investments.real_estate_fund + p->investments.mutual_funds + p->investments.etf + p->investments.bonds;

}

void apply_deposit_interest(Person* p, int month) {
    p->bank.deposit_rub += 0.05 * p->salary;
    p->bank.account_rub -= 0.05 * p->salary;
    if (p->bank.deposit_rub > 0) {
        RUB interest = p->bank.deposit_rub * 0.12 / 12;
        p->bank.deposit_rub += interest;
    }
}

void apply_wedding(Person* p, int month, int year, bool isMarried) {

    RUB total = 0;
    total += p->wedding.dress;
    total += p->wedding.suit;
    total += p->wedding.venue;
    total += p->wedding.catering;
    total += p->wedding.cake;
    total += p->wedding.photographer;
    total += p->wedding.music;
    total += p->wedding.flowers;
    total += p->wedding.rings;
    total += p->wedding.transport;

    p->bank.account_rub -= total;
    p->bank.account_rub -= p->wedding.honeymoon;

}

void print_monthly_report(int month, int year, Person* p) {
    printf("\n           %d.%d   \n", month, year);
    printf("Salary: %lld RUB\n", p->salary);
    printf("Account RUB: %lld RUB\n", p->bank.account_rub);
    printf("Deposit: %lld RUB\n", p->bank.deposit_rub);
    printf("Investments: %lld RUB\n", p->investments.total);
}

void print_final_report(Person* p, int start_year, int start_month, int end_year, int end_month) {
    printf("Simulation period: %d.%d - %d.%d\n", start_month, start_year, end_month, end_year);
    printf("-----------------------------------\n");
    printf("Final salary: %lld RUB\n", p->salary);
    printf("Account RUB: %lld RUB\n", p->bank.account_rub);
    printf("Deposit: %lld RUB\n", p->bank.deposit_rub);
    printf("\n--- INVESTMENTS ---\n");
    printf("Total: %lld RUB\n", p->investments.total);
    printf("\n--- CAR ---\n");
    printf("Car value: %lld RUB\n", p->car.value);
    printf("\n--- TOTAL CAPITAL ---\n");

    RUB total = p->bank.account_rub + p->bank.deposit_rub + p->investments.total + p->car.value;
    printf("TOTAL: %lld RUB\n", total);
}

void simulation(int start_year, int start_month, int end_year, int end_month) {
    int year = start_year;
    int month = start_month;

    bool has_cat = true;
    bool has_dog = true;
    bool is_married = family.isMarried;
    bool child = family.hasChildren;


    while (!(year > end_year || (year == end_year && month > end_month))) {
        Person* p = &family.husband;
        Person* q = &family.wife;
        apply_salary(p, month, year);
        apply_salary(q, month, year);
        apply_food_expenses(p, month);
        apply_food_expenses(q, month);
        apply_housing_expenses(q, month);
        apply_child_expenses(p, month, year, child, family.child_age);
        apply_car_expenses(p, month, year);
        apply_car_expenses(q, month, year);
        apply_transport_expenses(q, month);
        if (has_cat) {
            apply_cat_expenses(p, month, has_cat);
        }
        if (has_dog) {
            apply_dog_expenses(p, month, has_dog);
        }
        if (month == 6) {
            apply_trip_expenses(p, month);
        }
        apply_entertainment_expenses(p, month);
        apply_utilities_expenses(q, month);
        apply_gifts_expenses(q, month);
        apply_healthcare_expenses(p, month);
        apply_healthcare_expenses(q, month);
        apply_education_expenses(p, month);
        apply_investments(p, month);
        apply_investments(q, month);
        apply_deposit_interest(p, month);
        apply_deposit_interest(q, month);
        if (year == 2027 && month == 1) {
            apply_wedding(p, month, year, is_married);
        }
        if (month == 12) {
            is_married = true;
            apply_inflation(p, year);
            apply_inflation(q, year);
            family.child_age += 1;
        }

        

        if (month == 3 || month == 6 || month == 9 || month == 12) {
           //print_monthly_report(month, year, p);
        }

        month++;
        if (month == 13) {
            month = 1;
            year++;
        }
    }
    printf("\n-----HUSBAND-----\n");
    print_final_report(&family.husband, start_year, start_month, end_year, end_month);
    printf("\n-----WIFE-----\n");
    print_final_report(&family.wife, start_year, start_month, end_year, end_month);
}

int main() {
    init_family();

    int start_year, start_month, end_year, end_month;

    start_year = 2026;
    end_year = 2028;
    start_month = 1;
    end_month = 12;
    printf("FINANCIAL SIMULATION \n");
 
    if (start_year < 2026 || end_year < start_year) {
        printf("Invalid period! Using default: 2026.1 - 2028.12\n");
        start_year = 2026;
        start_month = 1;
        end_year = 2028;
        end_month = 12;
    }

    simulation(start_year, start_month, end_year, end_month);

    return 0;
}