#include <stdio.h>
#include <math.h>


using Percent = float;

using RUB = long long int;
using USD = long long int;


// идеи: болезнь, досуг, работа черная, лотерея, бабкино завещание,

struct Illness {
    bool alice_is_sick;
    bool bob_is_sick;
    bool child_is_sick;
    int alice_illness_type;      // 1-простуда, 2-грипп, 3-ангина, 4-травма
    int bob_illness_type;
    int child_illness_type;
    RUB doctor_visit;
    RUB tests;
    RUB medications;
    RUB hospital;
    RUB surgery;
    int total_illnesses;
    RUB total_medical_expenses;
    int months_since_last_illness;
};

struct Gambling {
    RUB lottery_ticket_price;
    int tickets_per_week;
    RUB lottery_winnings;
    int lottery_win_month;
    int lottery_win_year;
    RUB lottery_big_win;
    bool has_won_big;
    RUB casino_visit_cost;
    int casino_visits_per_year;
    RUB casino_winnings;
    RUB casino_losses;
    int casino_last_visit_month;
    int casino_last_visit_year;
    bool casino_win_streak;
    RUB slot_machine_per_play;
    int slot_machine_plays_per_month;
    RUB slot_machine_winnings;
    RUB slot_machine_losses;
    int slot_machine_jackpot_month;
    int slot_machine_jackpot_year;
    RUB slot_machine_jackpot;
    RUB total_spent;
    RUB total_won;
    RUB net_result;                   // чистый результат (+ прибыль, - убыток)
};

struct FoodBasket {
    RUB bread;
    RUB milk;
    RUB meat;
    RUB chicken;
    RUB fish;
    RUB vegetables;
    RUB fruits;
    RUB cereals;
    RUB pasta;
    RUB eggs;
    RUB cheese;
    RUB oil;
    RUB sugar;
    RUB salt;
    RUB spices;
    RUB tea;
    RUB coffee;
    RUB sweets;
    RUB snacks;
    RUB water;
    RUB juices;
    RUB total;
};


struct CountryHouse {
    RUB land_cost;
    int land_area;
    bool has_land;
    RUB house_project;
    RUB house_foundation;
    RUB house_walls;
    RUB house_roof;
    RUB house_windows;
    RUB house_doors;
    RUB house_facade;
    RUB house_heating;
    RUB house_electricity;
    RUB house_plumbing;
    RUB house_interior;
    RUB house_total;
    int house_construction_months;
    int house_months_done;
    bool is_house_built;
    RUB fence;
    RUB gate;
    RUB driveway;
    RUB landscaping;
    RUB garden;
    RUB lawn;
    RUB trees;
    RUB bushes;
    RUB flowers;
    RUB paths;
    RUB terrace;
    RUB gazebo;
    RUB barbecue;
    RUB well;
    RUB septic;
    RUB greenhouse;
    RUB garden_tools;
    RUB outdoor_furniture;
    RUB lighting;
    RUB territory_total;
    RUB total_spent;
    bool is_construction_active;
    int construction_start_month;
    int construction_start_year;
};


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


struct PreparationStage {
    RUB design_project;
    RUB permit;         // разрешение на перепланировку
    RUB dismantling;     // демонтаж старых покрытий
    RUB walls_construction;
};


struct EngineeringStage {
    RUB electrical;
    RUB plumbing;      // сантехника
    RUB heating;          // отопление
    RUB ventilation;
};


struct RoughFinishStage {
    RUB screed;           // стяжка пола
    RUB plaster;          // штукатурка стен
    RUB putty;            // шпаклевка
    RUB primer;           // грунтовка
};


struct FineFinishStage {
    RUB flooring;
    RUB walls;
    RUB ceilings;         // потолки
    RUB doors;
    RUB windows;
};


struct FurnitureStage {
    RUB kitchen_set;
    RUB bathroom_set;
    RUB wardrobe;
    RUB hallway;
    RUB bedroom;
    RUB living_room;
};


struct AppliancesStage {
    RUB refrigerator;
    RUB stove;               // плита
    RUB oven;                // духовка
    RUB microwave;           // микроволновка
    RUB dishwasher;
    RUB washing_machine;
    RUB dryer;               // сушильная машина
    RUB tv;
    RUB computer;
};


struct DecorStage {
    RUB lighting;
    RUB textiles;
    RUB decor;
    RUB plants;
};


struct OwnFlat {
    RUB total_cost;              // полная стоимость квартиры
    int square_meters;           // площадь в квадратных метрах
    int rooms;
    int floor;
    RUB initial_payment;         // первоначальный взнос
    RUB credit_amount;           // сумма кредита
    RUB mortgage_monthly;        // ежемесячный платеж по ипотеке
    RUB mortgage_rate;           // процентная ставка
    int mortgage_years;          // срок ипотеки в годах
    RUB remaining_debt;          // оставшийся долг
    RUB paid_interest;           // выплачено процентов
    RUB paid_principal;          // выплачено основного долга
    int payments_made;           // количество сделанных платежей
    RUB property_tax;            // налог на недвижимость (ежегодно)
    RUB insurance;               // страховка квартиры (ежегодно)
    RUB renovation_total;        // общая стоимость ремонта
    RUB renovation_spent;        // сколько уже потрачено
    int renovation_months_total; // сколько месяцев длится ремонт
    int renovation_months_done;  // сколько месяцев уже прошло
    PreparationStage preparation;
    EngineeringStage engineering;
    RoughFinishStage rough_finish;
    FineFinishStage fine_finish;
    FurnitureStage furniture;
    AppliancesStage appliances;
    DecorStage decor;
    RUB unexpected;              // непредвиденные расходы (10-15%)
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
    FoodBasket food;
    Car car;
    Flat flat;
    Cat cat;
    Dog dog;
    Hamster hamster;
    Trip trip;
    Wedding wedding;
    Child child;
    OwnFlat own_flat;
    CountryHouse country_house;
    Gambling gambling;
    Illness illness;
};
struct Person alice;


struct Husband {
    RUB salary;
    RUB food;
    Car car;
    bool isPresent;
};
struct Husband bob;


bool hasInheritance = false;
bool hasDebt = false;
int debt_start_month = 0;
int debt_start_year = 0;
RUB debt_remaining = 0;


bool isCatAlive = true;
bool isDogAlive = true;
bool isHamsterAlive = true;
bool isMarried = false;
bool isPregnant = false;
bool isChildAlive = false;
bool hasOwnFlat = false;
bool isRenovating = false;
int renovation_month = 0;       // Сколько месяцев идет ремонт


void alice_init()
{
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 1000;

    alice.salary = 180000;

    alice.food.bread = 500;
    alice.food.milk = 800;
    alice.food.meat = 2000;
    alice.food.chicken = 1000;
    alice.food.fish = 1000;
    alice.food.vegetables = 1500;
    alice.food.fruits = 1000;
    alice.food.cereals = 500;
    alice.food.pasta = 400;
    alice.food.eggs = 400;
    alice.food.cheese = 600;
    alice.food.oil = 300;
    alice.food.sugar = 200;
    alice.food.salt = 50;
    alice.food.spices = 150;
    alice.food.tea = 200;
    alice.food.coffee = 300;
    alice.food.sweets = 500;
    alice.food.snacks = 300;
    alice.food.water = 300;
    alice.food.juices = 400;
    alice.food.total = alice.food.bread + alice.food.milk + alice.food.meat + alice.food.chicken + alice.food.fish + alice.food.vegetables + alice.food.fruits + alice.food.cereals + alice.food.pasta +  alice.food.eggs + alice.food.cheese + alice.food.oil + alice.food.sugar + alice.food.salt + alice.food.spices + alice.food.tea + alice.food.coffee + alice.food.sweets + alice.food.snacks + alice.food.water + alice.food.juices;

    alice.illness.alice_is_sick = false;
    alice.illness.bob_is_sick = false;
    alice.illness.child_is_sick = false;
    alice.illness.alice_illness_type = 0;
    alice.illness.bob_illness_type = 0;
    alice.illness.child_illness_type = 0;
    alice.illness.doctor_visit = 2000;
    alice.illness.tests = 3000;
    alice.illness.medications = 2500;
    alice.illness.hospital = 15000;
    alice.illness.surgery = 50000;
    alice.illness.total_illnesses = 0;
    alice.illness.total_medical_expenses = 0;
    alice.illness.months_since_last_illness = 0;

    alice.gambling.lottery_ticket_price = 100;
    alice.gambling.tickets_per_week = 2;
    alice.gambling.lottery_winnings = 0;
    alice.gambling.lottery_win_month = 4;
    alice.gambling.lottery_win_year = 2027;
    alice.gambling.lottery_big_win = 1'500'000;
    alice.gambling.has_won_big = false;
    alice.gambling.casino_visit_cost = 10000;
    alice.gambling.casino_visits_per_year = 4;
    alice.gambling.casino_winnings = 0;
    alice.gambling.casino_losses = 0;
    alice.gambling.casino_last_visit_month = 0;
    alice.gambling.casino_last_visit_year = 0;
    alice.gambling.casino_win_streak = false;
    alice.gambling.slot_machine_per_play = 500;
    alice.gambling.slot_machine_plays_per_month = 8;
    alice.gambling.slot_machine_winnings = 0;
    alice.gambling.slot_machine_losses = 0;
    alice.gambling.slot_machine_jackpot_month = 0;
    alice.gambling.slot_machine_jackpot_year = 0;
    alice.gambling.slot_machine_jackpot = 50000;
    alice.gambling.total_spent = 0;
    alice.gambling.total_won = 0;
    alice.gambling.net_result = 0;

    alice.country_house.land_cost = 3'500'000;
    alice.country_house.land_area = 15;
    alice.country_house.has_land = false;

    alice.country_house.house_project = 200'000;
    alice.country_house.house_foundation = 400'000;
    alice.country_house.house_walls = 2'200'000;
    alice.country_house.house_roof = 800'000;
    alice.country_house.house_windows = 300'000;
    alice.country_house.house_doors = 200'000;
    alice.country_house.house_facade = 400'000;
    alice.country_house.house_heating = 700'000;
    alice.country_house.house_electricity = 500'000;
    alice.country_house.house_plumbing = 600'000;
    alice.country_house.house_interior = 1'800'000;
    alice.country_house.house_total = alice.country_house.house_project + alice.country_house.house_foundation + alice.country_house.house_walls + alice.country_house.house_roof + alice.country_house.house_windows + alice.country_house.house_doors + alice.country_house.house_facade + alice.country_house.house_heating + alice.country_house.house_electricity + alice.country_house.house_plumbing + alice.country_house.house_interior;
    alice.country_house.house_construction_months = 12;
    alice.country_house.house_months_done = 0;
    alice.country_house.is_house_built = false;

    alice.country_house.fence = 300'000;
    alice.country_house.gate = 200'000;
    alice.country_house.driveway = 200'000;
    alice.country_house.landscaping = 550'000;
    alice.country_house.garden = 100'000;
    alice.country_house.lawn = 80'000;
    alice.country_house.trees = 70'000;
    alice.country_house.bushes = 50'000;
    alice.country_house.flowers = 40'000;
    alice.country_house.paths = 120'000;
    alice.country_house.terrace = 450'000;
    alice.country_house.gazebo = 180'000;
    alice.country_house.barbecue = 70'000;
    alice.country_house.well = 300'000;
    alice.country_house.septic = 250'000;
    alice.country_house.greenhouse = 80'000;
    alice.country_house.garden_tools = 100'000;
    alice.country_house.outdoor_furniture = 350'000;
    alice.country_house.lighting = 80'000;
    alice.country_house.territory_total = alice.country_house.fence + alice.country_house.gate + alice.country_house.driveway + alice.country_house.landscaping + alice.country_house.garden + alice.country_house.lawn + alice.country_house.trees + alice.country_house.bushes + alice.country_house.flowers + alice.country_house.paths + alice.country_house.terrace + alice.country_house.gazebo + alice.country_house.barbecue + alice.country_house.well + alice.country_house.septic + alice.country_house.greenhouse + alice.country_house.garden_tools + alice.country_house.outdoor_furniture + alice.country_house.lighting;

    alice.country_house.total_spent = 0;
    alice.country_house.is_construction_active = false;

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

    alice.own_flat.total_cost = 12'500'000;
    alice.own_flat.square_meters = 65;
    alice.own_flat.rooms = 2;
    alice.own_flat.floor = 7;
    alice.own_flat.initial_payment = 2'500'000;       // первоначальный взнос 20%
    alice.own_flat.credit_amount = alice.own_flat.total_cost - alice.own_flat.initial_payment;
    alice.own_flat.mortgage_rate = 8.9;                // ставка 8.9% годовых
    alice.own_flat.mortgage_years = 25;                // на 25 лет
    alice.own_flat.remaining_debt = alice.own_flat.credit_amount;
    alice.own_flat.paid_interest = 0;
    alice.own_flat.paid_principal = 0;
    alice.own_flat.payments_made = 0;
    // Расчет ежемесячного платежа по ипотеке (аннуитетный)
    double monthly_rate = alice.own_flat.mortgage_rate / 100. / 12.;
    int periods = alice.own_flat.mortgage_years * 12;
    double annuity_factor = (monthly_rate * pow(1 + monthly_rate, periods)) / (pow(1 + monthly_rate, periods) - 1);
    alice.own_flat.mortgage_monthly = alice.own_flat.credit_amount * annuity_factor;
    alice.own_flat.property_tax = alice.own_flat.total_cost * 0.001;  // налог 0.1% от стоимости
    alice.own_flat.insurance = 18'000;

    alice.own_flat.renovation_total = 3'000'000;
    alice.own_flat.renovation_spent = 0;
    alice.own_flat.renovation_months_total = 8;
    alice.own_flat.renovation_months_done = 0;

    alice.own_flat.preparation.design_project = 120'000;
    alice.own_flat.preparation.permit = 30'000;
    alice.own_flat.preparation.dismantling = 50'000;
    alice.own_flat.preparation.walls_construction = 80'000;

    alice.own_flat.engineering.electrical = 180'000;
    alice.own_flat.engineering.plumbing = 150'000;
    alice.own_flat.engineering.heating = 120'000;
    alice.own_flat.engineering.ventilation = 60'000;

    alice.own_flat.rough_finish.screed = 100'000;
    alice.own_flat.rough_finish.plaster = 120'000;
    alice.own_flat.rough_finish.putty = 80'000;
    alice.own_flat.rough_finish.primer = 20'000;

    alice.own_flat.fine_finish.flooring = 200'000;
    alice.own_flat.fine_finish.walls = 150'000;
    alice.own_flat.fine_finish.ceilings = 100'000;
    alice.own_flat.fine_finish.doors = 120'000;
    alice.own_flat.fine_finish.windows = 90'000;

    alice.own_flat.furniture.kitchen_set = 250'000;
    alice.own_flat.furniture.bathroom_set = 80'000;
    alice.own_flat.furniture.wardrobe = 120'000;
    alice.own_flat.furniture.hallway = 60'000;
    alice.own_flat.furniture.bedroom = 150'000;
    alice.own_flat.furniture.living_room = 180'000;

    alice.own_flat.appliances.refrigerator = 70'000;
    alice.own_flat.appliances.stove = 40'000;
    alice.own_flat.appliances.oven = 35'000;
    alice.own_flat.appliances.microwave = 15'000;
    alice.own_flat.appliances.dishwasher = 45'000;
    alice.own_flat.appliances.washing_machine = 50'000;
    alice.own_flat.appliances.dryer = 40'000;
    alice.own_flat.appliances.tv = 60'000;
    alice.own_flat.appliances.computer = 80'000;

    alice.own_flat.decor.lighting = 50'000;
    alice.own_flat.decor.textiles = 40'000;
    alice.own_flat.decor.decor = 30'000;
    alice.own_flat.decor.plants = 15'000;

    alice.own_flat.unexpected = 300'000;

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

    bob.salary = 350000;
    bob.food = 5000;
    bob.car.value = 2'800'000;
    bob.car.gas = 15'000;
    bob.car.OSAGO = 5'000;
    bob.car.STO = 10'000;
    bob.car.tires = 15'000;
    bob.car.washing = 500;
    bob.car.parking_space = 12'000;
}


void alice_food_inflation(const int month, const int year)
{
    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    }

    alice.food.bread += alice.food.bread * (inflation / 100. / 12.);
    alice.food.milk += alice.food.milk * (inflation / 100. / 12.);
    alice.food.meat += alice.food.meat * (inflation / 100. / 12.);
    alice.food.chicken += alice.food.chicken * (inflation / 100. / 12.);
    alice.food.fish += alice.food.fish * (inflation / 100. / 12.);
    alice.food.vegetables += alice.food.vegetables * (inflation / 100. / 12.);
    alice.food.fruits += alice.food.fruits * (inflation / 100. / 12.);
    alice.food.cereals += alice.food.cereals * (inflation / 100. / 12.);
    alice.food.pasta += alice.food.pasta * (inflation / 100. / 12.);
    alice.food.eggs += alice.food.eggs * (inflation / 100. / 12.);
    alice.food.cheese += alice.food.cheese * (inflation / 100. / 12.);
    alice.food.oil += alice.food.oil * (inflation / 100. / 12.);
    alice.food.sugar += alice.food.sugar * (inflation / 100. / 12.);
    alice.food.salt += alice.food.salt * (inflation / 100. / 12.);
    alice.food.spices += alice.food.spices * (inflation / 100. / 12.);
    alice.food.tea += alice.food.tea * (inflation / 100. / 12.);
    alice.food.coffee += alice.food.coffee * (inflation / 100. / 12.);
    alice.food.sweets += alice.food.sweets * (inflation / 100. / 12.);
    alice.food.snacks += alice.food.snacks * (inflation / 100. / 12.);
    alice.food.water += alice.food.water * (inflation / 100. / 12.);
    alice.food.juices += alice.food.juices * (inflation / 100. / 12.);
    alice.food.total = alice.food.bread + alice.food.milk + alice.food.meat + alice.food.chicken + alice.food.fish + alice.food.vegetables + alice.food.fruits + alice.food.cereals + alice.food.pasta + alice.food.eggs + alice.food.cheese + alice.food.oil +  alice.food.sugar + alice.food.salt + alice.food.spices + alice.food.tea + alice.food.coffee + alice.food.sweets + alice.food.snacks + alice.food.water + alice.food.juices;
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

    alice.car.gas += alice.car.gas * (inflation / 100. / 12.);
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

    alice.car.STO += alice.car.STO * (inflation / 100. / 12.);
    alice.car.OSAGO += alice.car.OSAGO * (inflation / 100. / 12.);
    alice.car.tires += alice.car.tires * (inflation / 100. / 12.);
    alice.car.washing += alice.car.washing * (inflation / 100. / 12.);
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

    alice.car.parking_space += alice.car.parking_space * (inflation / 100. / 12.);
}


void alice_flat_rent(const int month, const int year)
{
    if (!hasOwnFlat) {
        Percent inflation = 8.0;
        switch (year) {
        case 2026: inflation = 8.5; break;
        case 2027: inflation = 9.0; break;
        case 2028: inflation = 9.5; break;
        case 2029: inflation = 9.0; break;
        }

        alice.flat.rent += alice.flat.rent * (inflation / 100. / 12.);
    }
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

    alice.flat.housing_and_communal_services += alice.flat.housing_and_communal_services * (inflation / 100. / 12.);
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

    alice.flat.household_supplies += alice.flat.household_supplies * (inflation / 100. / 12.);
    alice.flat.furniture += alice.flat.furniture * (inflation / 100. / 12.);
    alice.flat.cleaning += alice.flat.cleaning * (inflation / 100. / 12.);
    alice.flat.repair += alice.flat.repair * (inflation / 100. / 12.);
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

    alice.cat.cat_food += alice.cat.cat_food * (inflation / 100. / 12.);
    alice.cat.cat_litter += alice.cat.cat_litter * (inflation / 100. / 12.);
    alice.cat.toys += alice.cat.toys * (inflation / 100. / 12.);
    alice.cat.grooming += alice.cat.grooming * (inflation / 100. / 12.);
    alice.cat.treats += alice.cat.treats * (inflation / 100. / 12.);
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

    alice.cat.veterinarian += alice.cat.veterinarian * (inflation / 100. / 12.);
    alice.cat.vitamins += alice.cat.vitamins * (inflation / 100. / 12.);
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

    alice.dog.dog_food += alice.dog.dog_food * (inflation / 100. / 12.);
    alice.dog.toys += alice.dog.toys * (inflation / 100. / 12.);
    alice.dog.grooming += alice.dog.grooming * (inflation / 100. / 12.);
    alice.dog.treats += alice.dog.treats * (inflation / 100. / 12.);
    alice.dog.training += alice.dog.training * (inflation / 100. / 12.);
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

    alice.dog.veterinarian += alice.dog.veterinarian * (inflation / 100. / 12.);
    alice.dog.vaccines += alice.dog.vaccines * (inflation / 100. / 12.);
    alice.dog.vitamins += alice.dog.vitamins * (inflation / 100. / 12.);
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

    alice.hamster.food += alice.hamster.food * (inflation / 100. / 12.);
    alice.hamster.treats += alice.hamster.treats * (inflation / 100. / 12.);
    alice.hamster.bedding += alice.hamster.bedding * (inflation / 100. / 12.);
    alice.hamster.sawdust += alice.hamster.sawdust * (inflation / 100. / 12.);
    alice.hamster.hay += alice.hamster.hay * (inflation / 100. / 12.);
    alice.hamster.vitamins += alice.hamster.vitamins * (inflation / 100. / 12.);
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

    alice.trip.flight_tickets += alice.trip.flight_tickets * (inflation / 100. / 12.);
    alice.trip.hotel += alice.trip.hotel * (inflation / 100. / 12.);
    alice.trip.meals += alice.trip.meals * (inflation / 100. / 12.);
    alice.trip.excursions += alice.trip.excursions * (inflation / 100. / 12.);
    alice.trip.transport += alice.trip.transport * (inflation / 100. / 12.);
    alice.trip.insurance += alice.trip.insurance * (inflation / 100. / 12.);
    alice.trip.visa += alice.trip.visa * (inflation / 100. / 12.);
    alice.trip.souvenirs += alice.trip.souvenirs * (inflation / 100. / 12.);
    alice.trip.entertainment += alice.trip.entertainment * (inflation / 100. / 12.);
}


void alice_lottery(const int month, const int year, const int week_of_month)
{
    if (!bob.isPresent) return;  // Если нет Боба, не играют
    RUB weekly_cost = alice.gambling.lottery_ticket_price * alice.gambling.tickets_per_week;
    alice.vtb.account_rub -= weekly_cost;
    alice.gambling.total_spent += weekly_cost;
    if (month == 4 && year == 2027 && !alice.gambling.has_won_big) {
        if (week_of_month == 2) {
            alice.vtb.account_rub += alice.gambling.lottery_big_win;
            alice.gambling.lottery_winnings += alice.gambling.lottery_big_win;
            alice.gambling.total_won += alice.gambling.lottery_big_win;
            alice.gambling.has_won_big = true;
        }
    }

    if (month % 3 == 0 && week_of_month == 1) {
        RUB small_win = 500;
        alice.vtb.account_rub += small_win;
        alice.gambling.lottery_winnings += small_win;
        alice.gambling.total_won += small_win;
    }
}


void alice_casino(const int month, const int year)
{
    if (!bob.isPresent) return;  // Если нет Боба, не ходят
    if (month == 1 || month == 4 || month == 7 || month == 10) {
        if (alice.gambling.casino_last_visit_month != month || alice.gambling.casino_last_visit_year != year) {

            RUB spent = alice.gambling.casino_visit_cost;
            alice.vtb.account_rub -= spent;
            alice.gambling.casino_losses += spent;
            alice.gambling.total_spent += spent;

            if (month == 6 && year == 2027) {
                RUB win = 50000;
                alice.vtb.account_rub += win;
                alice.gambling.casino_winnings += win;
                alice.gambling.total_won += win;
                alice.gambling.casino_win_streak = true;
            }

            else if (month == 12 && year == 2028) {
                RUB loss = 30000;
                alice.vtb.account_rub -= loss;
                alice.gambling.casino_losses += loss;
                alice.gambling.total_spent += loss;
                alice.gambling.casino_win_streak = false;
            }

            alice.gambling.casino_last_visit_month = month;
            alice.gambling.casino_last_visit_year = year;
        }
    }
}


void alice_slot_machines(const int month, const int year, const int week_of_month)
{
    if (!bob.isPresent) return;  // Если нет Боба, не играют
    RUB weekly_plays = alice.gambling.slot_machine_plays_per_month / 4;
    RUB weekly_cost = weekly_plays * alice.gambling.slot_machine_per_play;

    alice.vtb.account_rub -= weekly_cost;
    alice.gambling.slot_machine_losses += weekly_cost;
    alice.gambling.total_spent += weekly_cost;

    if (month == 1 && year == 2028 && week_of_month == 3) {
        RUB jackpot = alice.gambling.slot_machine_jackpot;
        alice.vtb.account_rub += jackpot;
        alice.gambling.slot_machine_winnings += jackpot;
        alice.gambling.total_won += jackpot;
        alice.gambling.slot_machine_jackpot_month = month;
        alice.gambling.slot_machine_jackpot_year = year;
    }
}


void alice_gambling_update()
{
    alice.gambling.net_result = alice.gambling.total_won - alice.gambling.total_spent;
}


void alice_illness(const int month, const int year)
{
    if (!alice.illness.alice_is_sick && !alice.illness.bob_is_sick && !alice.illness.child_is_sick) {
        alice.illness.months_since_last_illness++;
    }

    else {
        alice.illness.months_since_last_illness = 0;
    }

    if (month == 1 || month == 4 || month == 7 || month == 10) {
        int sick_person = 0;
        if (year == 2026) {
            if (month == 1) sick_person = 1;  // Алиса
            else if (month == 4) sick_person = 2;  // Боб
            else if (month == 7) sick_person = 3;  // Ребенок
            else if (month == 10) sick_person = 1;  // Алиса
        }

        else if (year == 2027) {
            if (month == 1) sick_person = 2;  // Боб
            else if (month == 4) sick_person = 3;  // Ребенок
            else if (month == 7) sick_person = 1;  // Алиса
            else if (month == 10) sick_person = 2;  // Боб
        }

        else if (year == 2028) {
            if (month == 1) sick_person = 3;  // Ребенок
            else if (month == 4) sick_person = 1;  // Алиса
            else if (month == 7) sick_person = 2;  // Боб
            else if (month == 10) sick_person = 3;  // Ребенок
        }

        else if (year == 2029) {
            if (month == 1) sick_person = 1;  // Алиса
            else if (month == 4) sick_person = 2;  // Боб
            else if (month == 7) sick_person = 3;  // Ребенок
            else if (month == 10) sick_person = 1;  // Алиса
        }

        int illness_type = 0;
        if (year == 2026) illness_type = 1;  // простуда
        else if (year == 2027) illness_type = 2;  // грипп
        else if (year == 2028) illness_type = 3;  // ангина
        else if (year == 2029) illness_type = 4;  // травма

        RUB treatment_cost = 0;
        RUB doctor_cost = alice.illness.doctor_visit;
        RUB meds_cost = alice.illness.medications;
        RUB tests_cost = 0;
        RUB hospital_cost = 0;

        switch (illness_type) {
        case 1: // простуда
            treatment_cost = doctor_cost + meds_cost;
            break;
        case 2: // грипп
            tests_cost = alice.illness.tests;
            treatment_cost = doctor_cost + tests_cost + meds_cost * 2;
            break;
        case 3: // ангина
            tests_cost = alice.illness.tests;
            treatment_cost = doctor_cost + tests_cost + meds_cost * 2 + 5000;
            break;
        case 4: // травма
            hospital_cost = alice.illness.hospital;
            treatment_cost = doctor_cost + hospital_cost + alice.illness.medications * 3;
            break;
        }

        if (sick_person == 1 && alice.illness.alice_is_sick == false) {
            alice.illness.alice_is_sick = true;
            alice.illness.alice_illness_type = illness_type;
            alice.vtb.account_rub -= treatment_cost;
            alice.illness.total_medical_expenses += treatment_cost;
            alice.illness.total_illnesses++;
        }

        else if (sick_person == 2 && bob.isPresent && alice.illness.bob_is_sick == false) {
            alice.illness.bob_is_sick = true;
            alice.illness.bob_illness_type = illness_type;
            alice.vtb.account_rub -= treatment_cost;
            alice.illness.total_medical_expenses += treatment_cost;
            alice.illness.total_illnesses++;
        }

        else if (sick_person == 3 && isChildAlive && alice.illness.child_is_sick == false) {
            alice.illness.child_is_sick = true;
            alice.illness.child_illness_type = illness_type;
            alice.vtb.account_rub -= treatment_cost;
            alice.illness.total_medical_expenses += treatment_cost;
            alice.illness.total_illnesses++;
        }
    }

    if (alice.illness.alice_is_sick && month > 1) {
        alice.illness.alice_is_sick = false;
        alice.illness.alice_illness_type = 0;
    }
    if (alice.illness.bob_is_sick && month > 1) {
        alice.illness.bob_is_sick = false;
        alice.illness.bob_illness_type = 0;
    }
    if (alice.illness.child_is_sick && month > 1) {
        alice.illness.child_is_sick = false;
        alice.illness.child_illness_type = 0;
    }
}


void alice_holiday_food(const int month, const int year)
{
    if (month == 12) {  // Новый год
        alice.food.sweets += 1000;
        alice.food.meat += 2000;
    }

    if (month == 2 and year == 2026) {  // День рождения Алисы
        alice.food.sweets += 1000;
        alice.food.fruits += 1000;
    }

    if (month == 3 and year == 2027) {  // Рождение ребенка
        alice.food.sweets += 2000;
        alice.food.fruits += 2000;
    }

    alice.food.total = alice.food.bread + alice.food.milk + alice.food.meat + alice.food.chicken + alice.food.fish + alice.food.vegetables + alice.food.fruits + alice.food.cereals + alice.food.pasta + alice.food.eggs + alice.food.cheese + alice.food.oil + alice.food.sugar + alice.food.salt + alice.food.spices + alice.food.tea + alice.food.coffee + alice.food.sweets + alice.food.snacks + alice.food.water + alice.food.juices;
}


void alice_food_couple(const int month, const int year)
{
    if (bob.isPresent) {
        alice.food.bread *= 1.8;
        alice.food.milk *= 1.8;
        alice.food.meat *= 2.0;
        alice.food.chicken *= 1.8;
        alice.food.fish *= 1.8;
        alice.food.vegetables *= 1.7;
        alice.food.fruits *= 1.7;
        alice.food.cereals *= 1.8;
        alice.food.pasta *= 1.8;
        alice.food.eggs *= 1.8;
        alice.food.cheese *= 1.8;
        alice.food.oil *= 1.5;
        alice.food.sugar *= 1.5;
        alice.food.spices *= 1.3;
        alice.food.tea *= 2.0;
        alice.food.coffee *= 2.0;
        alice.food.sweets *= 1.8;
        alice.food.snacks *= 2.0;
        alice.food.water *= 2.0;
        alice.food.juices *= 1.8;
        alice.food.total = alice.food.bread + alice.food.milk + alice.food.meat + alice.food.chicken + alice.food.fish + alice.food.vegetables + alice.food.fruits + alice.food.cereals + alice.food.pasta + alice.food.eggs + alice.food.cheese + alice.food.oil + alice.food.sugar + alice.food.salt + alice.food.spices + alice.food.tea + alice.food.coffee + alice.food.sweets + alice.food.snacks + alice.food.water + alice.food.juices;
    }
}

void alice_country_house(const int month, const int year)
{
    if (month == 2 and year == 2029 and !alice.country_house.has_land) {
        alice.country_house.has_land = true;
        alice.country_house.is_construction_active = true;
        alice.vtb.account_rub -= alice.country_house.land_cost;
        alice.country_house.total_spent += alice.country_house.land_cost;
    }

    if (alice.country_house.is_construction_active) {
        int months_passed = (year - alice.country_house.construction_start_year) * 12 +
            (month - alice.country_house.construction_start_month);

        if (months_passed >= 1 and months_passed <= 12) {
            
            if (months_passed == 1) {
                alice.vtb.account_rub -= alice.country_house.house_project;
                alice.vtb.account_rub -= alice.country_house.house_foundation * 0.5;
                alice.country_house.total_spent += alice.country_house.house_project + alice.country_house.house_foundation * 0.5;
            }

            else if (months_passed == 2) {
                alice.vtb.account_rub -= alice.country_house.house_foundation * 0.5;
                alice.vtb.account_rub -= alice.country_house.house_walls * 0.3;
                alice.country_house.total_spent += alice.country_house.house_foundation * 0.5 + alice.country_house.house_walls * 0.3;
            }

            else if (months_passed == 3) {
                alice.vtb.account_rub -= alice.country_house.house_walls * 0.4;
                alice.country_house.total_spent += alice.country_house.house_walls * 0.4;
            }

            else if (months_passed == 4) {
                alice.vtb.account_rub -= alice.country_house.house_walls * 0.3;
                alice.vtb.account_rub -= alice.country_house.house_roof * 0.5;
                alice.country_house.total_spent += alice.country_house.house_walls * 0.3 + alice.country_house.house_roof * 0.5;
            }

            else if (months_passed == 5) {
                alice.vtb.account_rub -= alice.country_house.house_roof * 0.5;
                alice.vtb.account_rub -= alice.country_house.house_windows * 0.5;
                alice.country_house.total_spent += alice.country_house.house_roof * 0.5 + alice.country_house.house_windows * 0.5;
            }

            else if (months_passed == 6) {
                alice.vtb.account_rub -= alice.country_house.house_windows * 0.5;
                alice.vtb.account_rub -= alice.country_house.house_doors;
                alice.country_house.total_spent += alice.country_house.house_windows * 0.5 + alice.country_house.house_doors;
            }

            else if (months_passed == 7) {
                alice.vtb.account_rub -= alice.country_house.house_facade;
                alice.vtb.account_rub -= alice.country_house.house_electricity * 0.5;
                alice.vtb.account_rub -= alice.country_house.house_plumbing * 0.5;
                alice.country_house.total_spent += alice.country_house.house_facade + alice.country_house.house_electricity * 0.5 + alice.country_house.house_plumbing * 0.5;
            }

            else if (months_passed == 8) {
                alice.vtb.account_rub -= alice.country_house.house_heating * 0.5;
                alice.vtb.account_rub -= alice.country_house.house_electricity * 0.5;
                alice.vtb.account_rub -= alice.country_house.house_plumbing * 0.5;
                alice.country_house.total_spent += alice.country_house.house_heating * 0.5 + alice.country_house.house_electricity * 0.5 + alice.country_house.house_plumbing * 0.5;
            }

            else if (months_passed == 9) {
                alice.vtb.account_rub -= alice.country_house.house_heating * 0.5;
                alice.vtb.account_rub -= alice.country_house.house_interior * 0.25;
                alice.country_house.total_spent += alice.country_house.house_heating * 0.5 + alice.country_house.house_interior * 0.25;
            }

            else if (months_passed == 10) {
                alice.vtb.account_rub -= alice.country_house.house_interior * 0.5;
                alice.vtb.account_rub -= alice.country_house.well;
                alice.country_house.total_spent += alice.country_house.house_interior * 0.5 + alice.country_house.well;
            }

            else if (months_passed == 11) {
                alice.vtb.account_rub -= alice.country_house.house_interior * 0.25;
                alice.vtb.account_rub -= alice.country_house.septic;
                alice.vtb.account_rub -= alice.country_house.fence * 0.5;
                alice.country_house.total_spent += alice.country_house.house_interior * 0.25 + alice.country_house.septic + alice.country_house.fence * 0.5;
            }

            else if (months_passed == 12) {
                alice.vtb.account_rub -= alice.country_house.fence * 0.5;
                alice.vtb.account_rub -= alice.country_house.gate;
                alice.vtb.account_rub -= alice.country_house.driveway;
                alice.vtb.account_rub -= alice.country_house.landscaping;
                alice.vtb.account_rub -= alice.country_house.garden;
                alice.vtb.account_rub -= alice.country_house.lawn;
                alice.vtb.account_rub -= alice.country_house.trees;
                alice.vtb.account_rub -= alice.country_house.bushes;
                alice.vtb.account_rub -= alice.country_house.flowers;
                alice.vtb.account_rub -= alice.country_house.paths;
                alice.vtb.account_rub -= alice.country_house.terrace;
                alice.vtb.account_rub -= alice.country_house.gazebo;
                alice.vtb.account_rub -= alice.country_house.barbecue;
                alice.vtb.account_rub -= alice.country_house.greenhouse;
                alice.vtb.account_rub -= alice.country_house.garden_tools;
                alice.vtb.account_rub -= alice.country_house.outdoor_furniture;
                alice.vtb.account_rub -= alice.country_house.lighting;

                alice.country_house.total_spent += alice.country_house.fence * 0.5 + alice.country_house.gate + alice.country_house.driveway + alice.country_house.landscaping + alice.country_house.garden + alice.country_house.lawn + alice.country_house.trees + alice.country_house.bushes + alice.country_house.flowers + alice.country_house.paths + alice.country_house.terrace + alice.country_house.gazebo + alice.country_house.barbecue + alice.country_house.greenhouse + alice.country_house.garden_tools + alice.country_house.outdoor_furniture + alice.country_house.lighting;

                alice.country_house.is_house_built = true;
                alice.country_house.is_construction_active = false;
                alice.country_house.house_months_done = 12;
            }

            alice.country_house.house_months_done = months_passed;
        }
    }
}


void alice_food_expense(const int month, const int year)
{
    alice_holiday_food(month, year);
    if (bob.isPresent and month == 9 and year == 2026) {
        alice_food_couple(month, year);
    }

    alice.vtb.account_rub -= alice.food.total;
}


void alice_inheritance(const int month, const int year)
{
    if (month == 5 and year == 2026 and !hasInheritance) {
        hasInheritance = true;
        alice.vtb.account_rub += 3'000'000;
    }
}


void alice_debt_payment(const int month, const int year)
{
    if (hasInheritance and !hasDebt) {
        if (year == 2027 and month == 5) {
            hasDebt = true;
            debt_start_month = month;
            debt_start_year = year;
            debt_remaining = 3'600'000;
        }
    }

    if (hasDebt and debt_remaining > 0) {
        alice.vtb.account_rub -= 300'000;
        debt_remaining -= 300'000;

        if (debt_remaining <= 0) {
            hasDebt = false;
        }
    }
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
            alice.salary = 300000;  // Выходит на новую работу        
        }

        if (month >= 9 and year == 2027) {
            alice.vtb.account_rub -= alice.child.nursery;
        }
    }
}


void alice_buy_flat(const int month, const int year)
{
    if (month == 9 and year == 2026 and isMarried and !hasOwnFlat) {
        hasOwnFlat = true;
        isRenovating = true;
        alice.vtb.account_rub -= alice.own_flat.initial_payment;
    }
}


void alice_renovation(const int month, const int year)
{
    if (hasOwnFlat and isRenovating) {
        renovation_month++;
        alice.own_flat.renovation_months_done = renovation_month;
        if (renovation_month == 1) {
            alice.vtb.account_rub -= alice.own_flat.preparation.design_project;
            alice.vtb.account_rub -= alice.own_flat.preparation.permit;
            alice.vtb.account_rub -= alice.own_flat.preparation.dismantling;

            alice.own_flat.renovation_spent += alice.own_flat.preparation.design_project + alice.own_flat.preparation.permit + alice.own_flat.preparation.dismantling;
        }

        else if (renovation_month == 2) {
            alice.vtb.account_rub -= alice.own_flat.preparation.walls_construction;
            alice.vtb.account_rub -= alice.own_flat.engineering.electrical;
            alice.vtb.account_rub -= alice.own_flat.engineering.plumbing;

            alice.own_flat.renovation_spent += alice.own_flat.preparation.walls_construction + alice.own_flat.engineering.electrical + alice.own_flat.engineering.plumbing;
        }

        else if (renovation_month == 3) {
            alice.vtb.account_rub -= alice.own_flat.engineering.heating;
            alice.vtb.account_rub -= alice.own_flat.engineering.ventilation;
            alice.vtb.account_rub -= alice.own_flat.rough_finish.screed;
            alice.vtb.account_rub -= alice.own_flat.rough_finish.plaster;

            alice.own_flat.renovation_spent += alice.own_flat.engineering.heating +  alice.own_flat.engineering.ventilation + alice.own_flat.rough_finish.screed + alice.own_flat.rough_finish.plaster;
        }

        else if (renovation_month == 4) {
            alice.vtb.account_rub -= alice.own_flat.rough_finish.putty;
            alice.vtb.account_rub -= alice.own_flat.rough_finish.primer;

            alice.own_flat.renovation_spent += alice.own_flat.rough_finish.putty + alice.own_flat.rough_finish.primer;
        }

        else if (renovation_month == 5) {
            alice.vtb.account_rub -= alice.own_flat.fine_finish.flooring;
            alice.vtb.account_rub -= alice.own_flat.fine_finish.walls;
            alice.vtb.account_rub -= alice.own_flat.fine_finish.ceilings;

            alice.own_flat.renovation_spent += alice.own_flat.fine_finish.flooring + alice.own_flat.fine_finish.walls + alice.own_flat.fine_finish.ceilings;
        }

        else if (renovation_month == 6) {
            alice.vtb.account_rub -= alice.own_flat.fine_finish.doors;
            alice.vtb.account_rub -= alice.own_flat.fine_finish.windows;

            alice.own_flat.renovation_spent += alice.own_flat.fine_finish.doors + alice.own_flat.fine_finish.windows;
        }

        else if (renovation_month == 7) {
            alice.vtb.account_rub -= alice.own_flat.furniture.kitchen_set;
            alice.vtb.account_rub -= alice.own_flat.furniture.bathroom_set;
            alice.vtb.account_rub -= alice.own_flat.furniture.wardrobe;
            alice.vtb.account_rub -= alice.own_flat.furniture.hallway;
            alice.vtb.account_rub -= alice.own_flat.furniture.bedroom;
            alice.vtb.account_rub -= alice.own_flat.furniture.living_room;

            alice.own_flat.renovation_spent += alice.own_flat.furniture.kitchen_set + alice.own_flat.furniture.bathroom_set + alice.own_flat.furniture.wardrobe + alice.own_flat.furniture.hallway + alice.own_flat.furniture.bedroom + alice.own_flat.furniture.living_room;
        }

        else if (renovation_month == 8) {
            alice.vtb.account_rub -= alice.own_flat.appliances.refrigerator;
            alice.vtb.account_rub -= alice.own_flat.appliances.stove;
            alice.vtb.account_rub -= alice.own_flat.appliances.oven;
            alice.vtb.account_rub -= alice.own_flat.appliances.microwave;
            alice.vtb.account_rub -= alice.own_flat.appliances.dishwasher;
            alice.vtb.account_rub -= alice.own_flat.appliances.washing_machine;
            alice.vtb.account_rub -= alice.own_flat.appliances.dryer;
            alice.vtb.account_rub -= alice.own_flat.appliances.tv;
            alice.vtb.account_rub -= alice.own_flat.appliances.computer;
            alice.vtb.account_rub -= alice.own_flat.decor.lighting;
            alice.vtb.account_rub -= alice.own_flat.decor.textiles;
            alice.vtb.account_rub -= alice.own_flat.decor.decor;
            alice.vtb.account_rub -= alice.own_flat.decor.plants;
            alice.vtb.account_rub -= alice.own_flat.unexpected;

            alice.own_flat.renovation_spent += alice.own_flat.appliances.refrigerator + alice.own_flat.appliances.stove + alice.own_flat.appliances.oven + alice.own_flat.appliances.microwave + alice.own_flat.appliances.dishwasher + alice.own_flat.appliances.washing_machine + alice.own_flat.appliances.dryer + alice.own_flat.appliances.tv + alice.own_flat.appliances.computer + alice.own_flat.decor.lighting + alice.own_flat.decor.textiles + alice.own_flat.decor.decor + alice.own_flat.decor.plants + alice.own_flat.unexpected;

            isRenovating = false;
        }
    }
}


void alice_mortgage_payment(const int month, const int year)
{
    if (hasOwnFlat) {
        alice.vtb.account_rub -= alice.own_flat.mortgage_monthly;
        double monthly_rate = alice.own_flat.mortgage_rate / 100. / 12.;
        RUB interest_payment = alice.own_flat.remaining_debt * monthly_rate;
        RUB principal_payment = alice.own_flat.mortgage_monthly - interest_payment;
        alice.own_flat.remaining_debt -= principal_payment;
        alice.own_flat.paid_interest += interest_payment;
        alice.own_flat.paid_principal += principal_payment;
        alice.own_flat.payments_made++;

        if (month == 1) {
            alice.vtb.account_rub -= alice.own_flat.property_tax;
            alice.vtb.account_rub -= alice.own_flat.insurance;
        }

        alice.vtb.account_rub -= alice.flat.housing_and_communal_services;
    }
}


void alice_flat(const int month, const int year)
{
    if (!hasOwnFlat) {
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

    else {
        alice_mortgage_payment(month, year);
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
    if (month <= 9 and year <= 27) {
        if (month == 3) {
            alice.salary *= 1.5; // индексация зп
        }

        if (month == 2 and year == 2026) {
            alice.vtb.account_rub += 5000; // премия
        }
    }

    else {
        if (month == 3) {
            alice.salary *= 1.2; // индексация зп
        }
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
    alice_food_inflation(month, year);
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

    if (hasOwnFlat) {
        capital += alice.own_flat.total_cost - alice.own_flat.remaining_debt;
    }
    printf("Capital = %lld", capital);

    if (hasOwnFlat) {
        printf("\nFlat\n");
        printf("Cost: %lld RUB\n", alice.own_flat.total_cost);
        printf("Remaining debt: %lld RUB\n", alice.own_flat.remaining_debt);
        printf("Paid interest: %lld RUB\n", alice.own_flat.paid_interest);
        printf("Payment made: %d from %d\n", alice.own_flat.payments_made, alice.own_flat.mortgage_years * 12);
        printf("Renovation spent: %lld RUB\n", alice.own_flat.renovation_spent);
    }
    
    if (alice.country_house.has_land) {
        printf("\nHouse\n");
        printf("Land: %d hundred acres, cost: %lld RUB\n", alice.country_house.land_area, alice.country_house.land_cost);
        printf("Spent: %lld RUB\n", alice.country_house.total_spent - alice.country_house.land_cost);
        printf("Total: %lld RUB\n", alice.country_house.total_spent);
        if (alice.country_house.is_house_built) {
            printf("Built\n");
        }
    }

    printf("\nGAMBLING\n");
    printf("Lottery: Winning %lld RUB, Big Win in April 2027\n", alice.gambling.lottery_winnings);
    printf("Casino: winnings of %lld RUB, losses of %lld RUB\n", alice.gambling.casino_winnings, alice.gambling.casino_losses);
    printf("Slot machines: winnings of %lld RUB, losses of %lld RUB\n", alice.gambling.slot_machine_winnings, alice.gambling.slot_machine_losses);
    printf("Total: %lld RUB\n", alice.gambling.total_spent, alice.gambling.total_won);

    printf("\nIllnesses\n");
    printf("Total: %d\n", alice.illness.total_illnesses);
    printf("Expenses: %lld RUB\n", alice.illness.total_medical_expenses);
}


void simulation()
{
    int year = 2026;
    int month = 2;
    
    while (!(year == 2030 && month == 2)) {
        printf("\n Month %d.%d \n", month, year);

        apply_monthly_inflation(month, year);
        alice_salary(month, year);
        alice_car(month, year);
        alice_cat(month, year);
        alice_flat(month, year);
        alice_buy_flat(month, year);
        alice_renovation(month, year);
        alice_dog(month, year);
        alice_hamster(month, year);
        alice_trip(month, year);
        alice_food_expense(month, year);
        alice_wedding(month, year);
        bob_income_and_expenses(month, year);
        alice_pregnancy(month, year);
        alice_childbirth(month, year);
        alice_child_expenses(month, year);
        alice_inheritance(month, year);
        alice_debt_payment(month, year);
        alice_country_house(month, year);
        for (int week = 1; week <= 4; week++) {
            alice_lottery(month, year, week);
            alice_slot_machines(month, year, week);
        }
        alice_casino(month, year);
        alice_gambling_update();
        alice_illness(month, year);

        printf("\n Balance after month: %lld RUB\n", alice.vtb.account_rub);

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
    return 0;
}