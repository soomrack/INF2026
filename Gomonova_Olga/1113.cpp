#include <stdio.h>


using Percent = float;

using RUB = long long int;
using USD = long long int;


//идеи: кв в ипотеку, болезнь, собака, хомяк, еду расписать, работа черная, лотерея, бабкино завещание, участок земли, дача, брак, развод, ребенок, завещание дедка и его долги

struct Car {
    RUB value;
    RUB gas;
    RUB STO;
    RUB OSAGO;
    RUB tires;
    RUB washing;
    RUB parking_space;
};


struct Trip {
    RUB flight_tickets;
    RUB hotel;       
    RUB meals;          
    RUB excursions;
    RUB transport;
    RUB insurance;
    RUB visa;
    RUB souvenirs;
    RUB luggage;
    RUB entertainment;
};


struct Dog {
    RUB purchase;
    RUB dog_food;
    RUB toys;
    RUB bowl;
    RUB bed;
    RUB collar_and_leash;
    RUB grooming;
    RUB veterinarian;
    RUB vaccines;
    RUB vitamins;
    RUB treats;
    RUB training;
    RUB kennel;
};


struct Flat {
    RUB rent;
    RUB household_supplies;
    RUB housing_and_communal_services;
    RUB furniture;
    RUB cleaning;
    RUB repair;
    RUB deposit;
    RUB realtors_commission;
};


struct Cat {
    RUB purchase;
    RUB cat_food;
    RUB cat_litter;
    RUB toys;
    RUB tray;
    RUB little_house;
    RUB scratching_post;
    RUB grooming;
    RUB veterinarian;
    RUB vitamins;
    RUB treats;
    RUB carrier;
};


struct Hamster {
    RUB purchase;
    RUB cage;
    RUB bedding;
    RUB food;
    RUB treats;
    RUB toys;
    RUB water_bottle;
    RUB bowl;
    RUB veterinarian;
    RUB vitamins;
    RUB exercise_ball;
    RUB sawdust;
    RUB hay;
    RUB transport_cage;
};


struct Wedding {
    RUB dress;
    RUB suit;
    RUB venue;
    RUB catering;
    RUB photographer;
    RUB videographer;
    RUB music;
    RUB flowers;
    RUB invitations;
    RUB cake;
    RUB rings;
    RUB honeymoon;
    RUB registrar;
    RUB transport;
    RUB gifts_for_guests;
};


struct Child {
    bool isBorn;
    int birth_month;
    int birth_year;
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
};


struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
};


struct Person {
    Bank vtb;
    RUB salary;
    RUB food;
    Car car;
    Flat flat;
    Cat cat;
    Dog dog;
    Hamster hamster;
    Trip trip;
    Wedding wedding;
    Child child;
};
struct Person alice;


struct Husband {
    RUB salary;
    RUB food;
    Car car;
    bool isPresent;
};
struct Husband bob;


bool isCatAlive = true;
bool isDogAlive = true;
bool isHamsterAlive = true;
bool isMarried = false;
bool isPregnant = false;
bool isChildAlive = false;


void alice_init()
{
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 1000;

    alice.salary = 180000;
    alice.food = 3000;

    alice.car.value = 2'400'000;
    alice.car.gas = 15'000;
    alice.car.OSAGO = 5'000;
    alice.car.STO = 10'000;
    alice.car.tires = 15'000;
    alice.car.washing = 500;
    alice.car.parking_space = 12'000;

    alice.flat.rent = 45'000;
    alice.flat.household_supplies = 2'000;
    alice.flat.housing_and_communal_services = 8'000;
    alice.flat.furniture = 10'000;
    alice.flat.cleaning = 15'000;
    alice.flat.repair = 5'000;
    alice.flat.deposit = 45'000;
    alice.flat.realtors_commission = 30'000;

    alice.cat.purchase = 5'000;
    alice.cat.cat_food = 3'000;
    alice.cat.cat_litter = 500;
    alice.cat.toys = 2'000;
    alice.cat.tray = 1'000;
    alice.cat.little_house = 1'500;
    alice.cat.scratching_post = 5'000;
    alice.cat.grooming = 2'000;
    alice.cat.veterinarian = 2'000;
    alice.cat.vitamins = 2'000;
    alice.cat.treats = 500;
    alice.cat.carrier = 2'500;
    
    alice.dog.purchase = 30'000;
    alice.dog.dog_food = 5'000;
    alice.dog.toys = 1'500;
    alice.dog.bowl = 1'000;
    alice.dog.bed = 3'000;
    alice.dog.collar_and_leash = 3'500;
    alice.dog.grooming = 5'000;
    alice.dog.veterinarian = 3'000;
    alice.dog.vaccines = 4'000;
    alice.dog.vitamins = 1'000;
    alice.dog.treats = 1'500;
    alice.dog.training = 5'000;
    alice.dog.kennel = 10'000;

    alice.hamster.purchase = 1'500;
    alice.hamster.cage = 4'000;
    alice.hamster.bedding = 500;
    alice.hamster.food = 500;
    alice.hamster.treats = 300;
    alice.hamster.toys = 500;
    alice.hamster.water_bottle = 400;
    alice.hamster.bowl = 200;
    alice.hamster.veterinarian = 1'500;
    alice.hamster.vitamins = 300;
    alice.hamster.exercise_ball = 600;
    alice.hamster.sawdust = 400;
    alice.hamster.hay = 300;
    alice.hamster.transport_cage = 1'000;

    alice.trip.flight_tickets = 85'000;
    alice.trip.hotel = 150'000;
    alice.trip.meals = 38'000;
    alice.trip.excursions = 30'000;
    alice.trip.transport = 30'000;
    alice.trip.insurance = 5'000;
    alice.trip.visa = 8'000;
    alice.trip.souvenirs = 20'000;
    alice.trip.luggage = 7'000;
    alice.trip.entertainment = 45'000;

    alice.child.prenatal_vitamins = 5'000;
    alice.child.doctor_visits = 3'000;
    alice.child.ultrasound = 5'500;
    alice.child.maternity_clothes = 20'000;
    alice.child.childbirth = 80'000;
    alice.child.stroller = 40'000;
    alice.child.crib = 30'000;
    alice.child.mattress = 7'000;
    alice.child.bedding = 4'000;
    alice.child.changing_table = 8'000;
    alice.child.baby_bath = 2'000;
    alice.child.baby_monitor = 5'000;
    alice.child.diapers = 5'000;
    alice.child.baby_wipes = 1'500;
    alice.child.baby_clothes = 5'000;
    alice.child.baby_food = 6'000;
    alice.child.bottles = 3'000;
    alice.child.pacifiers = 1'500;
    alice.child.sterilizer = 4'000;
    alice.child.bottle_warmer = 2'500;
    alice.child.car_seat = 15'000;
    alice.child.high_chair = 8'000;
    alice.child.playpen = 6'000;
    alice.child.toys = 3'000;
    alice.child.books = 1'500;
    alice.child.vaccinations = 5'000;
    alice.child.pediatrician = 2'500;
    alice.child.medications = 5'000;
    alice.child.nanny = 30'000;
    alice.child.nursery = 25'000;

    bob.salary = 400000;
    bob.food = 5000;
    bob.car.value = 2'800'000;
    bob.car.gas = 15'000;
    bob.car.OSAGO = 5'000;
    bob.car.STO = 10'000;
    bob.car.tires = 15'000;
    bob.car.washing = 500;
    bob.car.parking_space = 12'000;
}


void alice_food(const int month, const int year)
{
    if (month == 12) alice.vtb.account_rub -= 2000; //christmas party

    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    }

    alice.food += alice.food * (inflation / 100. / 12.);
    alice.vtb.account_rub -= alice.food;
}


void alice_car_gas(const int month, const int year)
{
    Percent inflation = 5.0;
    switch (year) {
    case 2026: inflation = 6.5; break;
    case 2027: inflation = 7.0; break;
    case 2028: inflation = 8.0; break;
    case 2029: inflation = 7.5; break;
    }

    alice.car.gas += alice.car.gas * (inflation / 100. / 5.);
    alice.vtb.account_rub -= alice.car.gas;
}


void alice_car_service(const int month, const int year)
{
    Percent inflation = 6.0;
    switch (year) {
    case 2026: inflation = 6.5; break;
    case 2027: inflation = 7.0; break;
    case 2028: inflation = 7.5; break;
    case 2029: inflation = 7.0; break;
    }

    alice.car.STO += alice.car.STO * (inflation / 100. / 6.);
    alice.car.OSAGO += alice.car.OSAGO * (inflation / 100. / 6.);
    alice.car.tires += alice.car.tires * (inflation / 100. / 6.);
    alice.car.washing += alice.car.washing * (inflation / 100. / 6.);
}


void alice_car_parking(const int month, const int year)
{
    Percent inflation = 7.0;
    switch (year) {
    case 2026: inflation = 7.5; break;
    case 2027: inflation = 8.0; break;
    case 2028: inflation = 8.5; break;
    case 2029: inflation = 8.0; break;
    }

    alice.car.parking_space += alice.car.parking_space * (inflation / 100. / 7.);
}


void alice_flat_rent(const int month, const int year)
{
    Percent inflation = 8.0;
    switch (year) {
    case 2026: inflation = 8.5; break;
    case 2027: inflation = 9.0; break;
    case 2028: inflation = 9.5; break;
    case 2029: inflation = 9.0; break;
    }

    alice.flat.rent += alice.flat.rent * (inflation / 100. / 8.);
}


void alice_flat_housing_and_communal(const int month, const int year)
{
    Percent inflation = 7.0;
    switch (year) {
    case 2026: inflation = 7.5; break;
    case 2027: inflation = 8.0; break;
    case 2028: inflation = 8.5; break;
    case 2029: inflation = 8.0; break;
    }

    alice.flat.housing_and_communal_services += alice.flat.housing_and_communal_services * (inflation / 100. / 7.);
}


void alice_flat_goods(const int month, const int year)
{
    Percent inflation = 6.0;
    switch (year) {
    case 2026: inflation = 6.5; break;
    case 2027: inflation = 7.0; break;
    case 2028: inflation = 7.5; break;
    case 2029: inflation = 7.0; break;
    }

    alice.flat.household_supplies += alice.flat.household_supplies * (inflation / 100. / 6.);
    alice.flat.furniture += alice.flat.furniture * (inflation / 100. / 6.);
    alice.flat.cleaning += alice.flat.cleaning * (inflation / 100. / 6.);
    alice.flat.repair += alice.flat.repair * (inflation / 100. / 6.);
}


void alice_cat_goods(const int month, const int year)
{
    Percent inflation = 7.0;
    switch (year) {
    case 2026: inflation = 7.5; break;
    case 2027: inflation = 8.0; break;
    case 2028: inflation = 8.5; break;
    case 2029: inflation = 8.0; break;
    }

    alice.cat.cat_food += alice.cat.cat_food * (inflation / 100. / 7.);
    alice.cat.cat_litter += alice.cat.cat_litter * (inflation / 100. / 7.);
    alice.cat.toys += alice.cat.toys * (inflation / 100. / 7.);
    alice.cat.grooming += alice.cat.grooming * (inflation / 100. / 7.);
    alice.cat.treats += alice.cat.treats * (inflation / 100. / 7.);
}


void alice_cat_vet(const int month, const int year)
{
    Percent inflation = 9.0;
    switch (year) {
    case 2026: inflation = 9.5; break;
    case 2027: inflation = 10.0; break;
    case 2028: inflation = 10.5; break;
    case 2029: inflation = 10.0; break;
    }

    alice.cat.veterinarian += alice.cat.veterinarian * (inflation / 100. / 9.);
    alice.cat.vitamins += alice.cat.vitamins * (inflation / 100. / 9.);
}


void alice_dog_goods(const int month, const int year)
{
    Percent inflation = 8.0;
    switch (year) {
    case 2026: inflation = 8.5; break;
    case 2027: inflation = 9.0; break;
    case 2028: inflation = 9.5; break;
    case 2029: inflation = 9.0; break;
    }

    alice.dog.dog_food += alice.dog.dog_food * (inflation / 100. / 8.);
    alice.dog.toys += alice.dog.toys * (inflation / 100. / 8.);
    alice.dog.grooming += alice.dog.grooming * (inflation / 100. / 8.);
    alice.dog.treats += alice.dog.treats * (inflation / 100. / 8.);
    alice.dog.training += alice.dog.training * (inflation / 100. / 8.);
}


void alice_dog_vet(const int month, const int year)
{
    Percent inflation = 9.0;
    switch (year) {
    case 2026: inflation = 9.5; break;
    case 2027: inflation = 10.0; break;
    case 2028: inflation = 10.5; break;
    case 2029: inflation = 10.0; break;
    }

    alice.dog.veterinarian += alice.dog.veterinarian * (inflation / 100. / 9.);
    alice.dog.vaccines += alice.dog.vaccines * (inflation / 100. / 9.);
    alice.dog.vitamins += alice.dog.vitamins * (inflation / 100. / 9.);
}


void alice_hamster_goods(const int month, const int year)
{
    Percent inflation = 6.0;
    switch (year) {
    case 2026: inflation = 6.5; break;
    case 2027: inflation = 7.0; break;
    case 2028: inflation = 7.5; break;
    case 2029: inflation = 7.0; break;
    }

    alice.hamster.food += alice.hamster.food * (inflation / 100. / 6.);
    alice.hamster.treats += alice.hamster.treats * (inflation / 100. / 6.);
    alice.hamster.bedding += alice.hamster.bedding * (inflation / 100. / 6.);
    alice.hamster.sawdust += alice.hamster.sawdust * (inflation / 100. / 6.);
    alice.hamster.hay += alice.hamster.hay * (inflation / 100. / 6.);
    alice.hamster.vitamins += alice.hamster.vitamins * (inflation / 100. / 6.);
}


void alice_trip_inflation(const int month, const int year)
{
    Percent inflation = 10.0;
    switch (year) {
    case 2026: inflation = 10.5; break;
    case 2027: inflation = 11.0; break;
    case 2028: inflation = 11.5; break;
    case 2029: inflation = 11.0; break;
    }

    alice.trip.flight_tickets += alice.trip.flight_tickets * (inflation / 100. / 10.);
    alice.trip.hotel += alice.trip.hotel * (inflation / 100. / 10.);
    alice.trip.meals += alice.trip.meals * (inflation / 100. / 10.);
    alice.trip.excursions += alice.trip.excursions * (inflation / 100. / 10.);
    alice.trip.transport += alice.trip.transport * (inflation / 100. / 10.);
    alice.trip.insurance += alice.trip.insurance * (inflation / 100. / 10.);
    alice.trip.visa += alice.trip.visa * (inflation / 100. / 10.);
    alice.trip.souvenirs += alice.trip.souvenirs * (inflation / 100. / 10.);
    alice.trip.entertainment += alice.trip.entertainment * (inflation / 100. / 10.);
}


void alice_wedding(const int month, const int year)
{
    if (month == 8 and year == 2026 and !isMarried) {
        isMarried = true;
        bob.isPresent = true;

        RUB wedding_total = 0;
        wedding_total += alice.wedding.dress;
        wedding_total += alice.wedding.suit;
        wedding_total += alice.wedding.venue;
        wedding_total += alice.wedding.catering;
        wedding_total += alice.wedding.photographer;
        wedding_total += alice.wedding.videographer;
        wedding_total += alice.wedding.music;
        wedding_total += alice.wedding.flowers;
        wedding_total += alice.wedding.invitations;
        wedding_total += alice.wedding.cake;
        wedding_total += alice.wedding.rings;
        wedding_total += alice.wedding.registrar;
        wedding_total += alice.wedding.transport;
        wedding_total += alice.wedding.gifts_for_guests;

        RUB alice_share = wedding_total / 2;
        alice.vtb.account_rub -= alice_share;

        alice.vtb.account_rub -= alice.wedding.honeymoon;
    }
}


void bob_income_and_expenses(const int month, const int year)
{
    if (bob.isPresent) {
        alice.vtb.account_rub += bob.salary;
        alice.vtb.account_rub -= bob.food;

        if (month % 2 == 0) {
            alice.vtb.account_rub -= bob.car.washing;
        }

        alice.vtb.account_rub -= bob.car.gas;
        alice.vtb.account_rub -= bob.car.parking_space;

        if (month == 11 and year == 2026) {
            alice.vtb.account_rub -= bob.car.tires;
        }

        if (month == 12 and year == 2026) {
            alice.vtb.account_rub -= bob.car.OSAGO;
            alice.vtb.account_rub -= bob.car.STO;
        }

        if (month == 11 and year == 2027) {
            alice.vtb.account_rub -= bob.car.tires;
        }

        if (month == 12 and year == 2027) {
            alice.vtb.account_rub -= bob.car.OSAGO;
            alice.vtb.account_rub -= bob.car.STO;
        }
    }
}


void alice_pregnancy(const int month, const int year)
{
    if (isMarried and !isPregnant and !isChildAlive) {
        if (month == 10 and year == 2026) {
            isPregnant = true;
            alice.child.birth_month = 7;
            alice.child.birth_year = 2027;
        }
    }

    if (isPregnant) {
        if (month == 10 and year == 2026) {
            alice.vtb.account_rub -= alice.child.prenatal_vitamins;
        }

        if (month == 11 and year == 2026) {
            alice.vtb.account_rub -= alice.child.doctor_visits;
            alice.vtb.account_rub -= alice.child.ultrasound;
        }

        if (month == 12 and year == 2026) {
            alice.vtb.account_rub -= alice.child.doctor_visits;
            alice.vtb.account_rub -= alice.child.maternity_clothes;
        }

        if (month == 1 and year == 2027) {
            alice.vtb.account_rub -= alice.child.doctor_visits;
            alice.vtb.account_rub -= alice.child.ultrasound;
        }

        if (month == 2 and year == 2027) {
            alice.vtb.account_rub -= alice.child.doctor_visits;
            alice.vtb.account_rub -= alice.child.prenatal_vitamins;
        }

        if (month == 3 and year == 2027) {
            alice.vtb.account_rub -= alice.child.doctor_visits;
            alice.vtb.account_rub -= alice.child.ultrasound;
        }

        if (month == 4 and year == 2027) {
            alice.vtb.account_rub -= alice.child.doctor_visits;
        }

        if (month == 5 and year == 2027) {
            alice.vtb.account_rub -= alice.child.doctor_visits;
            alice.vtb.account_rub -= alice.child.ultrasound;
            alice.vtb.account_rub -= alice.child.stroller;
            alice.vtb.account_rub -= alice.child.crib;
            alice.vtb.account_rub -= alice.child.mattress;
            alice.vtb.account_rub -= alice.child.bedding;
            alice.vtb.account_rub -= alice.child.changing_table;
            alice.vtb.account_rub -= alice.child.baby_bath;
            alice.vtb.account_rub -= alice.child.baby_monitor;
            alice.vtb.account_rub -= alice.child.car_seat;
            alice.vtb.account_rub -= alice.child.high_chair;
            alice.vtb.account_rub -= alice.child.playpen;
            alice.vtb.account_rub -= alice.child.bottles;
            alice.vtb.account_rub -= alice.child.pacifiers;
            alice.vtb.account_rub -= alice.child.sterilizer;
            alice.vtb.account_rub -= alice.child.bottle_warmer;
        }

        if (month == 6 and year == 2027) {
            alice.vtb.account_rub -= alice.child.doctor_visits;
        }
    }
}


void alice_childbirth(const int month, const int year)
{
    if (isPregnant and month == 7 and year == 2027) {
        isPregnant = false;
        isChildAlive = true;
        alice.child.isBorn = true;

        alice.vtb.account_rub -= alice.child.childbirth;
        alice.salary = alice.salary * 0.4;  // Алиса уходит в декрет
    }
}


void alice_child_expenses(const int month, const int year)
{
    if (isChildAlive) {
        alice.vtb.account_rub -= alice.child.diapers;
        alice.vtb.account_rub -= alice.child.baby_wipes;
        alice.vtb.account_rub -= alice.child.baby_clothes;
        alice.vtb.account_rub -= alice.child.baby_food;
        alice.vtb.account_rub -= alice.child.toys;
        alice.vtb.account_rub -= alice.child.books;
        alice.vtb.account_rub -= alice.child.medications;

        if (month == 9 or month == 12 and year == 2027) {
            alice.vtb.account_rub -= alice.child.vaccinations;
        }

        if (month == 3 or month == 8 or month == 10 or month == 12 and year == 2028) {
            alice.vtb.account_rub -= alice.child.vaccinations;
        }

        if (month == 2 and year == 2028) {
            alice.vtb.account_rub -= alice.child.pediatrician;
        }

        if (month == 9 and year == 2027) {
            alice.salary = 200000;
        }

        if (month >= 9 and year == 2027) {
            alice.vtb.account_rub -= alice.child.nursery;
        }
    }
}


void alice_flat(const int month, const int year)
{
    alice.vtb.account_rub -= alice.flat.rent;
    alice.vtb.account_rub -= alice.flat.housing_and_communal_services;

    if (month % 6 == 0) {
        alice.vtb.account_rub -= alice.flat.household_supplies;
    }

    if (month == 6 or month == 11) {
        alice.vtb.account_rub -= alice.flat.furniture;
    }

    if (month == 12) {
        alice.vtb.account_rub -= alice.flat.repair;
    }

    if (month == 5 or month == 10) {
        alice.vtb.account_rub -= alice.flat.cleaning;
    }

    if (month == 1 and year == 2026) {
        alice.vtb.account_rub -= alice.flat.deposit;
        alice.vtb.account_rub -= alice.flat.realtors_commission;
    }
}


void alice_cat(const int month, const int year)
{
    if (isCatAlive) {
        if (month == 2 and year == 2026) {
            alice.vtb.account_rub -= alice.cat.purchase;
            alice.vtb.account_rub -= alice.cat.tray;
            alice.vtb.account_rub -= alice.cat.little_house;
            alice.vtb.account_rub -= alice.cat.scratching_post;
            alice.vtb.account_rub -= alice.cat.carrier;
        }

        if (month % 2 == 0) {
            alice.vtb.account_rub -= alice.cat.cat_food;
            alice.vtb.account_rub -= alice.cat.cat_litter;
        }

        if (month % 6 == 0) {
            alice.vtb.account_rub -= alice.cat.toys;
        }

        if (month % 4 == 0) {
            alice.vtb.account_rub -= alice.cat.grooming;
            alice.vtb.account_rub -= alice.cat.veterinarian;
            alice.vtb.account_rub -= alice.cat.vitamins;
        }

        if (month % 6 == 0) {
            alice.vtb.account_rub -= alice.cat.treats;
        }
    }

}


void alice_dog(const int month, const int year)
{
    if (isDogAlive) {
        if (month == 3 and year == 2026) {
            alice.vtb.account_rub -= alice.dog.purchase;
            alice.vtb.account_rub -= alice.dog.bowl;
            alice.vtb.account_rub -= alice.dog.bed;
            alice.vtb.account_rub -= alice.dog.collar_and_leash;
            alice.vtb.account_rub -= alice.dog.kennel;
        }

        if (month % 2 == 0) {
            alice.vtb.account_rub -= alice.dog.dog_food;
        }

        if (month % 3 == 0) {
            alice.vtb.account_rub -= alice.dog.toys;
        }

        if (month % 6 == 0) {
            alice.vtb.account_rub -= alice.dog.treats;
        }

        if (month % 4 == 0) {
            alice.vtb.account_rub -= alice.dog.vitamins;
        }

        if (month == 5 or month == 11) {
            alice.vtb.account_rub -= alice.dog.grooming;
        }

        if (month == 3 and year == 2026) {
            alice.vtb.account_rub -= alice.dog.vaccines;
        }

        if (month == 3 and year == 2027) {
            alice.vtb.account_rub -= alice.dog.vaccines;
        }

        if (month % 6 == 2) {
            alice.vtb.account_rub -= alice.dog.veterinarian;
        }

        if ((month == 4 or month == 10) and year == 2026) {
            alice.vtb.account_rub -= alice.dog.training;
        }
    }
}


void alice_hamster(const int month, const int year)
{
    if (isHamsterAlive) {
        if (month == 4 and year == 2026) {
            alice.vtb.account_rub -= alice.hamster.purchase;
            alice.vtb.account_rub -= alice.hamster.cage;
            alice.vtb.account_rub -= alice.hamster.bedding;
            alice.vtb.account_rub -= alice.hamster.water_bottle;
            alice.vtb.account_rub -= alice.hamster.bowl;
            alice.vtb.account_rub -= alice.hamster.toys;
            alice.vtb.account_rub -= alice.hamster.exercise_ball;
            alice.vtb.account_rub -= alice.hamster.transport_cage;
        }

        if (month % 2 == 0) {
            alice.vtb.account_rub -= alice.hamster.food;
            alice.vtb.account_rub -= alice.hamster.treats;
        }

        if (month % 6 == 0) {
            alice.vtb.account_rub -= alice.hamster.toys;
        }

        if (month % 3 == 0) {
            alice.vtb.account_rub -= alice.hamster.vitamins;
        }

        if (month == 4) {
            alice.vtb.account_rub -= alice.hamster.veterinarian;
        }

        alice.vtb.account_rub -= alice.hamster.sawdust;
        alice.vtb.account_rub -= alice.hamster.hay;
    }
}


void alice_trip(const int month, const int year)
{
    if (month == 5 && year == 2026) {
        alice.vtb.account_rub -= alice.trip.flight_tickets * 0.7;
        alice.vtb.account_rub -= alice.trip.hotel;
        alice.vtb.account_rub -= alice.trip.meals * 0.5;
        alice.vtb.account_rub -= alice.trip.excursions;
        alice.vtb.account_rub -= alice.trip.transport;
        alice.vtb.account_rub -= alice.trip.insurance * 0.7;
        alice.vtb.account_rub -= alice.trip.souvenirs;
        alice.vtb.account_rub -= alice.trip.entertainment;
    }

    if (month == 1 && year == 2026) {
        alice.vtb.account_rub -= alice.trip.flight_tickets;
        alice.vtb.account_rub -= alice.trip.hotel;
        alice.vtb.account_rub -= alice.trip.meals;
        alice.vtb.account_rub -= alice.trip.excursions;
        alice.vtb.account_rub -= alice.trip.transport * 0.5;
        alice.vtb.account_rub -= alice.trip.insurance;
        alice.vtb.account_rub -= alice.trip.souvenirs * 0.6;
        alice.vtb.account_rub -= alice.trip.entertainment * 0.7;
    }

    if (month == 1 && year == 2027) {
        alice.vtb.account_rub -= alice.trip.flight_tickets;
        alice.vtb.account_rub -= alice.trip.hotel * 0.6;
        alice.vtb.account_rub -= alice.trip.meals;
        alice.vtb.account_rub -= alice.trip.excursions * 0.7;
        alice.vtb.account_rub -= alice.trip.transport;
        alice.vtb.account_rub -= alice.trip.insurance;
        alice.vtb.account_rub -= alice.trip.souvenirs;
        alice.vtb.account_rub -= alice.trip.entertainment * 0.5;
    }

    if (month == 7 && year == 2027) {
        alice.vtb.account_rub -= alice.trip.flight_tickets * 0.7;
        alice.vtb.account_rub -= alice.trip.hotel * 0.5;
        alice.vtb.account_rub -= alice.trip.meals * 0.6;
        alice.vtb.account_rub -= alice.trip.excursions * 0.5;
        alice.vtb.account_rub -= alice.trip.transport * 0.7;
        alice.vtb.account_rub -= alice.trip.insurance;
        alice.vtb.account_rub -= alice.trip.souvenirs * 0.5;
        alice.vtb.account_rub -= alice.trip.entertainment * 0.6;
    }

    if (month == 2 && year == 2028) {
        alice.vtb.account_rub -= alice.trip.flight_tickets * 0.6;
        alice.vtb.account_rub -= alice.trip.hotel;
        alice.vtb.account_rub -= alice.trip.meals;
        alice.vtb.account_rub -= alice.trip.excursions * 0.3;
        alice.vtb.account_rub -= alice.trip.transport;
        alice.vtb.account_rub -= alice.trip.insurance * 1.5;
        alice.vtb.account_rub -= alice.trip.souvenirs;
        alice.vtb.account_rub -= alice.trip.entertainment * 1.2;
    }
}


void alice_salary(const int month, const int year)
{
    if (month == 3) {
        alice.salary *= 1.5;  // индексация зп
    }

    if (month == 2 and year == 2026) {
        alice.vtb.account_rub += 5000;  // премия
    }

    alice.vtb.account_rub += alice.salary;  // capital = capital + salary
}


void alice_car(const int month, const int year)
{
    if (month == 10 and year == 2026) {
        alice.vtb.account_rub -= alice.car.tires;
    }

    if (month % 2 == 0) {
        alice.vtb.account_rub -= alice.car.washing;
    }

    if (month != 12) {
        alice.vtb.account_rub -= alice.car.parking_space;
    }

    alice.vtb.account_rub -= alice.car.gas;
    alice.vtb.account_rub -= alice.car.STO;
    alice.vtb.account_rub -= alice.car.OSAGO;
}


void apply_monthly_inflation(int month, int year)
{
    alice_food(month, year);
    alice_car_gas(month, year);
    alice_car_service(month, year);
    alice_car_parking(month, year);
    alice_flat_rent(month, year);
    alice_flat_housing_and_communal(month, year);
    alice_flat_goods(month, year);
    alice_cat_goods(month, year);
    alice_cat_vet(month, year);
    alice_dog_goods(month, year);
    alice_dog_vet(month, year);
    alice_hamster_goods(month, year);
    alice_trip_inflation(month, year);
}


void print_results()
{
    printf("Salary = %lld\n", alice.salary);
    
    RUB capital = 0;
    capital += alice.vtb.account_rub;
    capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
    capital += alice.car.value;
    if (bob.isPresent) {
    capital += bob.car.value;
    }
    printf("Capital = %lld", capital);
}


void simulation()
{
    int year = 2026;
    int month = 2;

    while (!(year == 2027 && month == 2) ) {
        alice_salary(month, year);
        alice_car(month, year);
        alice_cat(month, year);
        alice_flat(month, year);
        alice_dog(month, year);
        alice_hamster(month, year);
        alice_trip(month, year);
        // my_mortgage();
        alice_food(month, year);
        alice_wedding(month, year);
        bob_income_and_expenses(month, year);
        alice_pregnancy(month, year);
        alice_childbirth(month, year);
        alice_child_expenses(month, year);
        
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    alice_init();
    simulation();
    print_results();

}
