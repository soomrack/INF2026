#include <stdio.h>


using RUB = long long int;
using USD = long long int;

bool danil_dog = false;

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


struct Food 
{
    RUB eggs;
    RUB bread;
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

};


struct Person 
{
    Luxery luxery;
    Bank vtb;
    Car car;
    RUB salary;
    Hobby hobby;
    Food food;
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

    eva.food.eggs = 50;
    eva.food.bread = 25;

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

    danil.food.eggs = 30;
    danil.food.bread = 15;

    danil.kvartira_rent.rent = 15'000;

    danil.luxery.haircut = 1000;

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
    if (month == 12) {
        eva.vtb.account += eva.salary;  // 13th salary
    }

    if (month == 1 and year == 2027) {
        eva.salary *= 1.25;  // promotion
    }

	if (month == 1 and year == 2028) {
        eva.salary *= 1.5;  // promotion
    }

    eva.vtb.account += eva.salary;
}


void danil_salary(const int month, const int year)
{
    if (month == 12) {
        danil.vtb.account += danil.salary;  // 13th salary
    }

    if (month == 1 and year == 2027) {
        danil.salary *= 1.25;  // promotion
    }
    
    if (month == 1 and year == 2028) {
        danil.salary *= 1.4;  // promotion
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


void eva_popugay(const int month, const int year)
{
    eva.vtb.account -= eva.popugay.popugay_food;
	eva.popugay.popugay_food += eva.popugay.popugay_food * inflation / 100.0 / 12;

    eva.vtb.account -= eva.popugay.popugay_toys;
    eva.popugay.popugay_toys += eva.popugay.popugay_toys * inflation / 100.0 / 12;


    if (month == 8 and year == 2027)
    {
        eva.vtb.account -= eva.popugay.kletka;
    }
    eva.popugay.kletka += eva.popugay.kletka * inflation / 100.0 / 12;
}


void eva_food()
{
    eva.vtb.account -= eva.food.eggs * 8;
    eva.food.eggs += eva.food.eggs * inflation / 100.0 / 12;

    eva.vtb.account -= eva.food.bread * 20;
    eva.food.bread += eva.food.bread * inflation / 100.0 / 12;

}


void danil_food()
{
    danil.vtb.account -= danil.food.eggs * 10;
    danil.food.eggs += danil.food.eggs * inflation / 100.0 / 12;

    danil.vtb.account -= danil.food.bread * 30;
    danil.food.bread += danil.food.bread * inflation / 100.0 / 12;

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
    if (month == 3 and year == 2027) {
        eva.vtb.account_usd += 3'000;
    }
}


void danil_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        danil.vtb.account_usd += 3'000;
    }
}


void print_results()
{
    printf("Salary = %lld\n", eva.salary);

    RUB eva_capital = 0;
    eva_capital += eva.vtb.account;
    eva_capital += eva.car.value;
    eva_capital += eva.vtb.deposite;
    eva_capital += eva.vtb.account_usd * eva.vtb.rate_usd_rub;
    printf("Capital = %lld\n", eva_capital);

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
        eva_popugay(month, year);


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