#include <stdio.h>


using RUB = long long int;
using USD = long long int;

bool danil_dog = false;
bool eva_popugay = false;

float inflation = 8.7;

using Percent = float;


struct Bank 
{
    RUB account;
    RUB deposite;
    Percent interest;

    USD account_usd;
    float rate_usd_rub;
};


struct Car 
{
    RUB bmw_oil;
    RUB bmw_tires;
    RUB bmw_engine;
    RUB bmw_wheels;
    RUB bmw_piston;
    RUB bmw_valve;
    RUB bmw_spark_plug;
    RUB bmw_starter;
    RUB bmw_battery;
    RUB bmw_radiator;
    RUB bmw_fan;
    RUB bmw_muffler;
    RUB bmw_exhaust;
    RUB bmw_air_filter;
    RUB bmw_oil_filter;
    RUB bmw_timing_belt;
    RUB bmw_clutch;
	RUB bmw_transmission;
    RUB bmw_spring;
    RUB bmw_control_arm;
    RUB bmw_steering_rack;
    RUB bmw_brake_drum;
    RUB bmw_brake_pad;
    RUB bmw_brake_caliper;

    RUB mazda_air_filter;
    RUB mazda_oil_filter;
    RUB mazda_oil;
    RUB mazda_clutch;
    RUB battery;

    RUB gas;
    RUB value;
    RUB repair;
};


struct Luxery 
{
    RUB nogti;
	RUB haircut;
	RUB jewelry;
    RUB perfume;
    RUB eyebrows;
    RUB tan;
};


struct E_cat 
{
    RUB napolnitel;
    RUB cats_food;
    //ниже непостоянные траты
    RUB osheinik;
    RUB toys;
};


struct Pet_buy
{
    RUB dog;
    RUB popugay;
};


struct E_popugay
{
    RUB popugay_food;
    RUB popugay_toys;
    //ниже непостоянные траты
    RUB kletka;
};


struct D_dog
{
    RUB dogs_food;
    RUB grooming;
    RUB vet;
	RUB napolnitel;
    //ниже непостояные траты
    RUB osheinik;
};


struct Hobby 
{
    RUB golf;
    RUB chess;
    RUB swim;
    RUB code;
    RUB paint;
    RUB cook;
};


struct Rent 
{
    RUB rent;
};


struct E_food 
{
    RUB eggs;
    RUB chicken_breast;
    RUB turkey;
    RUB salmon;
    RUB tuna;
    RUB oatmeal;
    RUB buckwheat;
    RUB quinoa;
    RUB rice;
    RUB avocado;
    RUB broccoli;
    RUB spinach;
    RUB cucumber;
    RUB tomatoes;
    RUB bell_pepper;
    RUB carrots;
    RUB cabbage;
    RUB greek_yogurt;
    RUB cottage_cheese;
    RUB milk;
    RUB nuts;
    RUB almonds;
    RUB walnuts;
    RUB berries;
    RUB blueberries;
    RUB strawberries;
    RUB banana;

};

struct D_food 
{
    RUB eggs;
    RUB bread;
    RUB milk;
    RUB meat;
    RUB vegetables;
    RUB potatoes;
    RUB pasta;
    RUB rice;
    RUB chicken;
    RUB pork;
    RUB beef;
    RUB sausage;
    RUB cheese;
    RUB butter;
    RUB buckwheat;
    RUB bacon;
    RUB french_fries;
    RUB pizza;
    RUB burger;
    RUB instant_noodles;
    RUB chips;
    RUB beer;
    RUB soda;
    RUB mayonnaise;
    RUB ice_cream;
};


struct Gym 
{
    RUB abonement;
    RUB personal_trainer;
    RUB sportswear;
    RUB towel;
    RUB locker_lock;
    RUB protein;
    RUB buds;
    RUB creatin;
    RUB desodorant;
};


struct Hoz_tovar 
{
    RUB holodos;
    RUB tv;
    RUB washing_machine;
    RUB microwave;
    RUB oven;
    RUB kover;
    RUB dishes;
};


struct Person 
{
    Luxery luxery;
    Bank vtb;
    Car car;
    RUB salary;
    Hobby hobby;
    E_food e_food;
	D_food d_food;
    Gym gym;
	Hoz_tovar ht;
    E_cat cat;
    Rent kvartira_rent;
	Pet_buy pet_buy;
	D_dog dog;
    E_popugay popugay;
};


struct Person eva;
struct Person danil;

void eva_init()
{
    eva.vtb.account = 0;
    eva.vtb.deposite = 100.000;
    eva.vtb.interest = 14.5;
    eva.salary = 45'000;

    eva.vtb.account_usd = 1'000;
    eva.vtb.rate_usd_rub = 78.5;

    eva.kvartira_rent.rent = 25'000;

    eva.e_food.eggs = 50;
	eva.e_food.chicken_breast = 100;
	eva.e_food.turkey = 150;
	eva.e_food.salmon = 200;
	eva.e_food.tuna = 150;
	eva.e_food.oatmeal = 50;
	eva.e_food.buckwheat = 50;
	eva.e_food.quinoa = 100;
	eva.e_food.rice = 50;
	eva.e_food.avocado = 150;
	eva.e_food.broccoli = 50;
	eva.e_food.spinach = 50;
	eva.e_food.cucumber = 50;
	eva.e_food.tomatoes = 50;
	eva.e_food.bell_pepper = 50;
	eva.e_food.carrots = 50;
	eva.e_food.cabbage = 50;
	eva.e_food.greek_yogurt = 100;
	eva.e_food.cottage_cheese = 100;
	eva.e_food.milk = 50;
	eva.e_food.nuts = 100;
	eva.e_food.almonds = 50;
	eva.e_food.walnuts = 50;
	eva.e_food.berries = 100;
	eva.e_food.blueberries = 50;
	eva.e_food.strawberries = 50;
	eva.e_food.banana = 50;

    eva.ht.holodos = 50'000;
    eva.ht.tv = 100'000;
	eva.ht.washing_machine = 30'000;
	eva.ht.microwave = 15'000;
	eva.ht.oven = 20'000;
	eva.ht.kover = 10'000;
	eva.ht.dishes = 5'000;

    eva.car.repair = 1'000;
    eva.car.value = 2'400'000;
    eva.car.gas = 15'000;
	eva.car.mazda_air_filter = 500;
	eva.car.mazda_oil_filter = 700;
	eva.car.mazda_oil = 3'500;
	eva.car.mazda_clutch = 15'000;
	eva.car.battery = 7'000;

    eva.luxery.nogti = 3'000;
    eva.luxery.haircut = 1'000;
    eva.luxery.jewelry = 1'500;
    eva.luxery.perfume = 500;
    eva.luxery.eyebrows = 750;
    eva.luxery.tan = 1'000;

    eva.cat.cats_food = 2500;
    eva.cat.napolnitel = 500;
    eva.cat.osheinik = 300;
    eva.cat.toys = 300;

    eva.pet_buy.popugay = 15'000;
    eva.popugay.popugay_food = 500;
    eva.popugay.popugay_toys = 300;
    eva.popugay.kletka = 2'000;
}

void danil_init()
{
    danil.vtb.account = 0;
    danil.vtb.deposite = 1'000'000;
    danil.vtb.interest = 14.5;
    danil.salary = 60'000;

    danil.vtb.account_usd = 1'000;
    danil.vtb.rate_usd_rub = 78.5;

    danil.d_food.eggs = 30;
    danil.d_food.bread = 15;
	danil.d_food.milk = 50;
	danil.d_food.meat = 200;
	danil.d_food.vegetables = 100;
	danil.d_food.potatoes = 50;
	danil.d_food.pasta = 50;
	danil.d_food.rice = 50;
	danil.d_food.chicken = 150;
	danil.d_food.pork = 150;
	danil.d_food.beef = 200;
	danil.d_food.sausage = 100;
	danil.d_food.cheese = 100;
	danil.d_food.butter = 50;
	danil.d_food.buckwheat = 50;
	danil.d_food.bacon = 100;
	danil.d_food.french_fries = 50;
	danil.d_food.pizza = 200;
	danil.d_food.burger = 150;
	danil.d_food.instant_noodles = 50;
	danil.d_food.chips = 50;
	danil.d_food.beer = 100;
	danil.d_food.soda = 50;
	danil.d_food.mayonnaise = 50;
	danil.d_food.ice_cream = 50;

    danil.kvartira_rent.rent = 15'000;

    danil.luxery.haircut = 1000;
    danil.luxery.perfume = 5000;

    danil.gym.abonement = 2'500;
    danil.gym.personal_trainer = 5'000;
    danil.gym.sportswear = 2'000;
    danil.gym.towel = 500;
    danil.gym.locker_lock = 100;
    danil.gym.protein = 1'500;
    danil.gym.buds = 2'000;
    danil.gym.creatin = 500;
    danil.gym.desodorant = 300;

    danil.car.repair = 1000;
    danil.car.value = 500'000;
    danil.car.gas = 15'000;
    danil.car.bmw_air_filter = 1'500;
	danil.car.bmw_oil_filter = 2'000;
	danil.car.bmw_oil = 5'000;
	danil.car.bmw_clutch = 20'000;
	danil.car.bmw_battery = 7'000;
	danil.car.bmw_radiator = 10'000;
	danil.car.bmw_fan = 5'000;
	danil.car.bmw_muffler = 15'000;
	danil.car.bmw_exhaust = 20'000;
    danil.car.bmw_tires = 20'000;
    danil.car.bmw_wheels = 30'000;
    danil.car.bmw_engine = 100'000;
    danil.car.bmw_piston = 2'000;
    danil.car.bmw_valve = 1'500;
    danil.car.bmw_spark_plug = 3'000;
    danil.car.bmw_starter = 5'000;
    danil.car.bmw_transmission = 25'000;
    danil.car.bmw_brake_drum = 3'000;
    danil.car.bmw_brake_pad = 2'000;
    danil.car.bmw_brake_caliper = 5'000;
    danil.car.bmw_timing_belt = 7'000;
    danil.car.bmw_steering_rack = 15'000;
    danil.car.bmw_spring = 3'000;

    danil.hobby.golf = 2'000;
    danil.hobby.chess = 1'500;
    danil.hobby.swim = 1'000;
    danil.hobby.code = 0;
    danil.hobby.paint = 2'000;
    danil.hobby.cook = 500;

	danil.ht.holodos = 30'000;
	danil.ht.tv = 50'000;

	danil.pet_buy.dog = 20'000;

	danil.dog.dogs_food = 2'000;
    danil.dog.grooming = 1'000;
    danil.dog.vet = 5'000;
    danil.dog.napolnitel = 500;
    danil.dog.osheinik = 500;
}


void eva_salary(const int month, const int year)
{
    if (month == 12) 
    {
        eva.vtb.account += eva.salary;  // 13th salary
    }


    if (month == 1 and year == 2027) 
    {
        eva.salary *= 1.25;  // promotion
    }


	if (month == 1 and year == 2028) 
    {
        eva.salary *= 1.5;  // promotion
    }


    if (month == 1 and year == 2029)
    {
        eva.salary *= 1.6;  // promotion
    }


    eva.vtb.account += eva.salary;
}


void danil_salary(const int month, const int year)
{
    if (month == 12) 
    {
        danil.vtb.account += danil.salary;  // 13th salary
    }


    if (month == 1 and year == 2027) 
    {
        danil.salary *= 1.25;  // promotion
    }
    

    if (month == 1 and year == 2028) 
    {
        danil.salary *= 1.4;  // promotion
    }


	if (month == 5 and year == 2028)
    {
		danil.vtb.account += 20'000'000;  // выйгрыш в лотерею
    }


    if (month == 1 and year == 2029)
    {
        danil.salary *= 1.5;  // promotion
	}


    if (month == 1 and year == 2030)
    {
        danil.salary *= 1.5;  // promotion
    }

    
    if (month == 1 and year == 2031)
    {
        danil.salary *= 1.3;  // promotion
    }

    
    if (year == 2032)
    {
		danil.vtb.account += 50'000;  // ежемесячная премия
    }


    danil.vtb.account += danil.salary;
}


void danil_hobby()
{
    danil.vtb.account -= danil.hobby.golf;
    danil.hobby.golf += danil.hobby.golf * inflation / 100.0 / 12;

    danil.vtb.account -= danil.hobby.chess;
    danil.hobby.chess += danil.hobby.chess * inflation / 100.0 / 12;

    danil.vtb.account -= danil.hobby.swim;
    danil.hobby.swim += danil.hobby.swim * inflation / 100.0 / 12;

    danil.vtb.account -= danil.hobby.code;
    danil.hobby.code += danil.hobby.code * inflation / 100.0 / 12;

    danil.vtb.account -= danil.hobby.paint;
    danil.hobby.paint += danil.hobby.paint * inflation / 100.0 / 12;

    danil.vtb.account -= danil.hobby.cook;
    danil.hobby.cook += danil.hobby.cook * inflation / 100.0 / 12;

}


void eva_kvartira()
{
    eva.vtb.account -= eva.kvartira_rent.rent;
    eva.kvartira_rent.rent += eva.kvartira_rent.rent * inflation / 100.0 / 12;
}


void danil_kvartira()
{
    danil.vtb.account -= danil.kvartira_rent.rent;
	danil.kvartira_rent.rent += danil.kvartira_rent.rent * inflation / 100.0 / 12;
}


void eva_luxery()
{
    eva.vtb.account -= eva.luxery.nogti;
    eva.luxery.nogti += eva.luxery.nogti * inflation / 100.0 / 12;

    eva.vtb.account -= eva.luxery.haircut;
    eva.luxery.haircut += eva.luxery.haircut * inflation / 100.0 / 12;

    eva.vtb.account -= eva.luxery.jewelry;
	eva.luxery.jewelry += eva.luxery.jewelry * inflation / 100.0 / 12;

	eva.vtb.account -= eva.luxery.perfume;
	eva.luxery.perfume += eva.luxery.perfume * inflation / 100.0 / 12;

	eva.vtb.account -= eva.luxery.eyebrows;
	eva.luxery.eyebrows += eva.luxery.eyebrows * inflation / 100.0 / 12;

	eva.vtb.account -= eva.luxery.tan;
	eva.luxery.tan += eva.luxery.tan * inflation / 100.0 / 12;
}


void danil_luxery()
{
    danil.vtb.account -= danil.luxery.haircut;
	danil.luxery.haircut += danil.luxery.haircut * inflation / 100.0 / 12;

    danil.vtb.account -= danil.luxery.perfume;
	danil.luxery.perfume += danil.luxery.perfume * inflation / 100.0 / 12;
}


void danil_and_eva_pet_buy(const int month, const int year)
{
    if (month == 6 and year == 2026) 
    {
        danil.vtb.deposite -= danil.pet_buy.dog;
        danil_dog = true;
    }
    danil.pet_buy.dog += danil.pet_buy.dog * inflation / 100.0 / 12;


    if (month == 7 and year == 2027)
    {
        eva.vtb.deposite -= eva.pet_buy.popugay;
		eva_popugay = true;
    }
    eva.pet_buy.popugay += eva.pet_buy.popugay * inflation / 100.0 / 12;
}


void eva_cat(const int month, const int year)
{
    eva.vtb.account -= eva.cat.cats_food;
	eva.cat.cats_food += eva.cat.cats_food * inflation / 100.0 / 12;

    eva.vtb.account -= eva.cat.napolnitel;
	eva.cat.napolnitel += eva.cat.napolnitel * inflation / 100.0 / 12;


    if (month == 5 and year == 2026)
    {
        eva.vtb.account -= eva.cat.osheinik;
    }

	eva.cat.osheinik += eva.cat.osheinik * inflation / 100.0 / 12;


    if (month == 8 and year == 2026)
    {
        eva.vtb.account -= eva.cat.toys;
    }

	eva.cat.toys += eva.cat.toys * inflation / 100.0 / 12;
}


void danils_dog(const int month, const int year)
{
    if (danil_dog == true) 
    {
        danil.vtb.account -= danil.dog.dogs_food;
        danil.dog.dogs_food += danil.dog.dogs_food * inflation / 100.0 / 12;

		danil.vtb.account -= danil.dog.grooming;
		danil.dog.grooming += danil.dog.grooming * inflation / 100.0 / 12;

		danil.vtb.account -= danil.dog.vet;
		danil.dog.vet += danil.dog.vet * inflation / 100.0 / 12;

		danil.vtb.account -= danil.dog.napolnitel;
		danil.dog.napolnitel += danil.dog.napolnitel * inflation / 100.0 / 12;
    }


    if (month == 7 and year == 2026)
    {
        danil.vtb.account -= danil.dog.osheinik;
    }
    danil.dog.osheinik += danil.dog.osheinik * inflation / 100.0 / 12;
}


void evas_popugay(const int month, const int year)
{
    if (eva_popugay == true)
    {
        eva.vtb.account -= eva.popugay.popugay_food;
        eva.popugay.popugay_food += eva.popugay.popugay_food * inflation / 100.0 / 12;

        eva.vtb.account -= eva.popugay.popugay_toys;
        eva.popugay.popugay_toys += eva.popugay.popugay_toys * inflation / 100.0 / 12;
    }


    if (month == 8 and year == 2027)
    {
        eva.vtb.account -= eva.popugay.kletka;
    }
    eva.popugay.kletka += eva.popugay.kletka * inflation / 100.0 / 12;
}


void eva_food()
{
    eva.vtb.account -= eva.e_food.eggs * 8;
    eva.e_food.eggs += eva.e_food.eggs * inflation / 100.0 / 12;

    eva.vtb.account -= eva.e_food.chicken_breast * 20;
    eva.e_food.chicken_breast += eva.e_food.chicken_breast * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.turkey * 25;
	eva.e_food.turkey += eva.e_food.turkey * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.salmon * 50;
	eva.e_food.salmon += eva.e_food.salmon * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.tuna * 30;
	eva.e_food.tuna += eva.e_food.tuna * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.oatmeal * 10;
	eva.e_food.oatmeal += eva.e_food.oatmeal * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.buckwheat * 15;
	eva.e_food.buckwheat += eva.e_food.buckwheat * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.quinoa * 25;
	eva.e_food.quinoa += eva.e_food.quinoa * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.rice * 10;
	eva.e_food.rice += eva.e_food.rice * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.avocado * 30;
	eva.e_food.avocado += eva.e_food.avocado * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.broccoli * 10;
	eva.e_food.broccoli += eva.e_food.broccoli * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.spinach * 10;
	eva.e_food.spinach += eva.e_food.spinach * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.cucumber * 10;
	eva.e_food.cucumber += eva.e_food.cucumber * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.tomatoes * 10;
	eva.e_food.tomatoes += eva.e_food.tomatoes * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.bell_pepper * 10;
	eva.e_food.bell_pepper += eva.e_food.bell_pepper * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.carrots * 10;
	eva.e_food.carrots += eva.e_food.carrots * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.cabbage * 10;
	eva.e_food.cabbage += eva.e_food.cabbage * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.greek_yogurt * 20;
	eva.e_food.greek_yogurt += eva.e_food.greek_yogurt * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.cottage_cheese * 20;
	eva.e_food.cottage_cheese += eva.e_food.cottage_cheese * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.milk * 10;
	eva.e_food.milk += eva.e_food.milk * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.nuts * 20;
	eva.e_food.nuts += eva.e_food.nuts * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.almonds * 20;
	eva.e_food.almonds += eva.e_food.almonds * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.walnuts * 20;
	eva.e_food.walnuts += eva.e_food.walnuts * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.berries * 20;
	eva.e_food.berries += eva.e_food.berries * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.blueberries * 20;
	eva.e_food.blueberries += eva.e_food.blueberries * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.strawberries * 20;
	eva.e_food.strawberries += eva.e_food.strawberries * inflation / 100.0 / 12;

	eva.vtb.account -= eva.e_food.banana * 20;
	eva.e_food.banana += eva.e_food.banana * inflation / 100.0 / 12;
}


void danil_food()
{
    danil.vtb.account -= danil.d_food.eggs * 10;
    danil.d_food.eggs += danil.d_food.eggs * inflation / 100.0 / 12;

    danil.vtb.account -= danil.d_food.bread * 30;
    danil.d_food.bread += danil.d_food.bread * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.milk * 50;
	danil.d_food.milk += danil.d_food.milk * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.meat * 200;
	danil.d_food.meat += danil.d_food.meat * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.vegetables * 100;
	danil.d_food.vegetables += danil.d_food.vegetables * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.potatoes * 50;
	danil.d_food.potatoes += danil.d_food.potatoes * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.pasta * 50;
	danil.d_food.pasta += danil.d_food.pasta * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.rice * 50;
	danil.d_food.rice += danil.d_food.rice * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.chicken * 150;
	danil.d_food.chicken += danil.d_food.chicken * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.pork * 150;
	danil.d_food.pork += danil.d_food.pork * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.beef * 200;
	danil.d_food.beef += danil.d_food.beef * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.sausage * 100;
	danil.d_food.sausage += danil.d_food.sausage * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.cheese * 100;
	danil.d_food.cheese += danil.d_food.cheese * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.butter * 50;
	danil.d_food.butter += danil.d_food.butter * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.buckwheat * 50;
	danil.d_food.buckwheat += danil.d_food.buckwheat * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.bacon * 100;
	danil.d_food.bacon += danil.d_food.bacon * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.french_fries * 50;
	danil.d_food.french_fries += danil.d_food.french_fries * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.pizza * 200;
	danil.d_food.pizza += danil.d_food.pizza * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.burger * 150;
	danil.d_food.burger += danil.d_food.burger * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.instant_noodles * 50;
	danil.d_food.instant_noodles += danil.d_food.instant_noodles * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.chips * 50;
	danil.d_food.chips += danil.d_food.chips * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.beer * 100;
	danil.d_food.beer += danil.d_food.beer * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.soda * 50;
	danil.d_food.soda += danil.d_food.soda * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.mayonnaise * 50;
	danil.d_food.mayonnaise += danil.d_food.mayonnaise * inflation / 100.0 / 12;

	danil.vtb.account -= danil.d_food.ice_cream * 50;
	danil.d_food.ice_cream += danil.d_food.ice_cream * inflation / 100.0 / 12;
}


void eva_home_hoz(const int month, const int year)
{
    if (month == 5 and year == 2028) 
    {
        eva.vtb.account -= eva.ht.holodos;
    }
    

    if (month == 6 and year == 2029) 
    {
        eva.vtb.account -= eva.ht.tv;
	}


    if (month == 7 and year == 2030)
    {
        eva.vtb.account -= eva.ht.washing_machine;
    }


    if (month == 8 and year == 2031)
    {
        eva.vtb.account -= eva.ht.microwave;
    }


    if (month == 9 and year == 2032)
    {
        eva.vtb.account -= eva.ht.oven;
    }


    if (month == 10 and year == 2033)
    {
        eva.vtb.account -= eva.ht.kover;
	}


    if (month == 11 and year == 2034)
    {
        eva.vtb.account -= eva.ht.dishes;
    }


    eva.ht.tv += eva.ht.tv * inflation / 100.0 / 12;
    eva.ht.holodos += eva.ht.holodos * inflation / 100.0 / 12;
	eva.ht.washing_machine += eva.ht.washing_machine * inflation / 100.0 / 12;
	eva.ht.microwave += eva.ht.microwave * inflation / 100.0 / 12;
	eva.ht.oven += eva.ht.oven * inflation / 100.0 / 12;
	eva.ht.kover += eva.ht.kover * inflation / 100.0 / 12;
	eva.ht.dishes += eva.ht.dishes * inflation / 100.0 / 12;
}


void danil_home_hoz(const int month, const int year)
{
	if (month == 5 and year == 2027) 
    {
        danil.vtb.account -= danil.ht.holodos;
    }
    
    danil.ht.holodos += danil.ht.holodos * inflation / 100.0 / 12;

	if (month == 6 and year == 2027)
    {
        danil.vtb.account -= danil.ht.tv;
    }


	danil.ht.tv += danil.ht.tv * inflation / 100.0 / 12;
}


void danil_gym()
{
    danil.vtb.account -= danil.gym.abonement;
    danil.gym.abonement += danil.gym.abonement * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.personal_trainer;
    danil.vtb.account += danil.gym.personal_trainer * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.sportswear;
    danil.vtb.account += danil.gym.sportswear * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.towel;
    danil.vtb.account += danil.gym.towel * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.locker_lock;
    danil.vtb.account += danil.gym.locker_lock * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.protein;
    danil.vtb.account += danil.gym.protein * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.buds;
    danil.vtb.account += danil.gym.buds * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.creatin;
    danil.vtb.account += danil.gym.creatin * inflation / 100.0 / 12;

    danil.vtb.account -= danil.gym.desodorant;
    danil.vtb.account += danil.gym.desodorant * inflation / 100.0 / 12;
}


void eva_car(const int month)
{
    if (month == 4)
    {
        eva.vtb.account -= eva.car.mazda_air_filter;
        eva.vtb.account -= eva.car.mazda_oil_filter;
        eva.vtb.account -= eva.car.mazda_oil;
        eva.vtb.account -= eva.car.mazda_clutch;
        eva.vtb.account -= eva.car.repair*15;
	}


    eva.vtb.account -= eva.car.gas;
    eva.vtb.account -= eva.car.gas * inflation / 100.0 / 12;
    eva.car.repair += eva.car.repair * inflation / 100.0 / 12;
    eva.car.mazda_air_filter += eva.car.mazda_air_filter * inflation / 100.0 / 12;
    eva.car.mazda_oil_filter += eva.car.mazda_oil_filter * inflation / 100.0 / 12;
    eva.car.mazda_oil += eva.car.mazda_oil * inflation / 100.0 / 12;
    eva.car.mazda_clutch += eva.car.mazda_clutch * inflation / 100.0 / 12;
}


void danil_car(const int month, const int year)
{
	if (month == 7)
    {
        danil.vtb.account -= danil.car.bmw_air_filter;
        danil.vtb.account -= danil.car.bmw_oil_filter;
        danil.vtb.account -= danil.car.bmw_oil;
        danil.vtb.account -= danil.car.bmw_clutch;
        danil.vtb.account -= danil.car.repair*20;
    }


    if (month == 10 and year == 2026)
    {
        danil.vtb.account -= danil.car.bmw_tires * 4;
        danil.vtb.account -= danil.car.bmw_wheels* 4;
        danil.vtb.account -= danil.car.bmw_spring * 4;
        danil.vtb.account -= danil.car.bmw_control_arm * 4;
        danil.vtb.account -= danil.car.repair*10;
	}


    if (month == 6 and year == 2027)
    {
        danil.vtb.account -= danil.car.bmw_starter;
        danil.vtb.account -= danil.car.bmw_muffler;
		danil.vtb.account -= danil.car.bmw_exhaust;
		danil.vtb.account -= danil.car.battery;
        danil.vtb.account -= danil.car.bmw_radiator;
        danil.vtb.account -= danil.car.bmw_fan;
        danil.vtb.account -= danil.car.repair * 30;
    }


    if (month == 10 and year == 2027)
    {
		danil.vtb.account -= danil.car.bmw_transmission;
        danil.vtb.account -= danil.car.repair * 10;
    }


    if (month == 4 and year == 2028)
    {
        danil.vtb.account -= danil.car.bmw_engine;
        danil.vtb.account -= danil.car.bmw_piston * 4;
        danil.vtb.account -= danil.car.bmw_valve * 16;
        danil.vtb.account -= danil.car.bmw_spark_plug * 6;
        danil.vtb.account -= danil.car.bmw_timing_belt;
        danil.vtb.account -= danil.car.bmw_steering_rack;
        danil.vtb.account -= danil.car.repair * 150;
	}


    if (month == 7 and year == 2032)
    {
        danil.vtb.account -= danil.car.bmw_brake_drum * 4;
        danil.vtb.account -= danil.car.bmw_brake_pad * 4;
        danil.vtb.account -= danil.car.bmw_brake_caliper * 4;
        danil.vtb.account -= danil.car.repair * 20;
    }


    danil.vtb.account -= danil.car.gas;
    danil.vtb.account -= danil.car.gas * inflation / 100.0 / 12;
    danil.car.repair += danil.car.repair * inflation / 100.0 / 12;
	danil.car.bmw_air_filter += danil.car.bmw_air_filter * inflation / 100.0 / 12;
	danil.car.bmw_oil_filter += danil.car.bmw_oil_filter * inflation / 100.0 / 12;
	danil.car.bmw_oil += danil.car.bmw_oil * inflation / 100.0 / 12;
	danil.car.bmw_clutch += danil.car.bmw_clutch * inflation / 100.0 / 12;
	danil.car.bmw_battery += danil.car.bmw_battery * inflation / 100.0 / 12;
	danil.car.bmw_radiator += danil.car.bmw_radiator * inflation / 100.0 / 12;
	danil.car.bmw_fan += danil.car.bmw_fan * inflation / 100.0 / 12;
	danil.car.bmw_muffler += danil.car.bmw_muffler * inflation / 100.0 / 12;
    danil.car.bmw_exhaust += danil.car.bmw_exhaust * inflation / 100.0 / 12;
    danil.car.bmw_tires += danil.car.bmw_tires * inflation / 100.0 / 12;
    danil.car.bmw_wheels += danil.car.bmw_wheels * inflation / 100.0 / 12;
    danil.car.bmw_engine += danil.car.bmw_engine * inflation / 100.0 / 12;
	danil.car.bmw_piston += danil.car.bmw_piston * inflation / 100.0 / 12;
	danil.car.bmw_valve += danil.car.bmw_valve * inflation / 100.0 / 12;
	danil.car.bmw_spark_plug += danil.car.bmw_spark_plug * inflation / 100.0 / 12;
	danil.car.bmw_starter += danil.car.bmw_starter * inflation / 100.0 / 12;
	danil.car.bmw_transmission += danil.car.bmw_transmission * inflation / 100.0 / 12;
	danil.car.bmw_brake_drum += danil.car.bmw_brake_drum * inflation / 100.0 / 12;
	danil.car.bmw_brake_pad += danil.car.bmw_brake_pad * inflation / 100.0 / 12;
	danil.car.bmw_brake_caliper += danil.car.bmw_brake_caliper * inflation / 100.0 / 12;
	danil.car.bmw_timing_belt += danil.car.bmw_timing_belt * inflation / 100.0 / 12;
	danil.car.bmw_steering_rack += danil.car.bmw_steering_rack * inflation / 100.0 / 12;
	danil.car.bmw_spring += danil.car.bmw_spring * inflation / 100.0 / 12;
}


void eva_deposite(const int month, const int year)
{
    if (year == 2026) eva.vtb.interest = 14.5;
    if (year == 2027) eva.vtb.interest = 13.5;
    if (year == 2028) eva.vtb.interest = 12.5;
    if (year == 2029) eva.vtb.interest = 11.5;

    eva.vtb.deposite += eva.vtb.deposite * (eva.vtb.interest / 12.0 / 100.0);

    eva.vtb.deposite += eva.vtb.account;
    eva.vtb.account = 0;
}


void danil_deposite(const int month, const int year)
{
    if (year == 2026) danil.vtb.interest = 15.0;
    if (year == 2027) danil.vtb.interest = 14.0;
    if (year == 2028) danil.vtb.interest = 13.0;
    if (year == 2029) danil.vtb.interest = 11.5;

}
void eva_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027)
    {
        eva.vtb.account += 3'000;
    };


    if (month == 4 and year == 2027)
    {
        eva.vtb.account += 10'000;
    };


	if (month == 6 and year == 2027)
    {
        eva.vtb.account += 12'000;
    };


    if (month == 7 and year == 2027)
    {
        eva.vtb.account += 20'000;
    };


    if (month == 8 and year == 2027)
    {
        eva.vtb.account += 15'000;
    };


    if (month == 9 and year == 2027)
    {
        eva.vtb.account += 12'000;
    };


    if (month == 10 and year == 2027)
    {
        eva.vtb.account += 6'000;
    };


    if (month == 11 and year == 2027)
    {
        eva.vtb.account += 12'000;
    };


    if (month == 12 and year == 2027)
    {
        eva.vtb.account += 100'000;
    };


	if (year == 2028)
    {
        eva.vtb.account += 30'000;
    }
}


void danil_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) 
    {
        danil.vtb.account += 3'000;
    }
}


void print_results()
{
    printf("Eva\n");
    printf("Salary = %lld\n", eva.salary);

    RUB eva_capital = 0;
    eva_capital += eva.vtb.account;
    eva_capital += eva.car.value;
    eva_capital += eva.vtb.deposite;
    eva_capital += eva.vtb.account_usd * eva.vtb.rate_usd_rub;
    printf("Capital = %lld\n\n", eva_capital);

    printf("Danil\n");
    printf("Salary = %lld\n", danil.salary);

    RUB danil_capital = 1;
    danil_capital += danil.vtb.account;
    danil_capital += danil.car.value;
    danil_capital += danil.vtb.deposite;
    danil_capital += danil.vtb.account_usd * danil.vtb.rate_usd_rub;
    printf("Capital = %lld\n", danil_capital);
}





void simulation()
{
    int month = 2;
    int year = 2026;

    while (not (month == 3 and year == 2035)) 
    {
        eva_salary(month, year);
        eva_freelance(month, year);
        eva_car(month);
        eva_food();
        eva_luxery();
        eva_kvartira();
        eva_cat(month, year);
        evas_popugay(month, year);
        eva_home_hoz(month, year);


        danil_salary(month, year);
        danil_hobby();
        danil_kvartira();
		danil_luxery();
        danils_dog(month, year);
        danil_freelance(month, year);
        danil_car(month, year);
        danil_food();
        danil_home_hoz(month, year);
        danil_gym();

		danil_and_eva_pet_buy(month, year);
        //чтобы деньги не минусовались
        eva_deposite(month, year);
        danil_deposite(month, year);
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    eva_init();

    danil_init();

    simulation();

    print_results();
}