#include <stdio.h>


using RUB = long long int;
using USD = long long int;

float inflation = 8.7;

using Percent = float;


struct Bank {
    RUB account;
    RUB deposite;
    Percent interest;

    USD account_usd;
    float rate_usd_rub;
};


struct Car {
    RUB gas;
    RUB value;
};


struct Luxery {
    RUB nogti;
};


struct Hobby {
    RUB golf;
    RUB chess;
    RUB swim;
    RUB code;
    RUB paint;
    RUB cook;
};


struct Kvartira {
    RUB rent;
};


struct Food{
    RUB eggs;
    RUB bread;
};


struct Person {
    Kvartira kvartira;
    Luxery luxery;
    Bank vtb;
    Car car;
    RUB salary;
	Hobby hobby; 
    Food food;
    Gym gym;

};


struct Gym {
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


struct Person eva;
struct Person danil;

void eva_init()
{
    eva.vtb.account = 0;
    eva.vtb.deposite = 1'000'000;
    eva.vtb.interest = 14.5;
    eva.salary = 180'000;

    eva.vtb.account_usd = 1'000;
    eva.vtb.rate_usd_rub = 78.5;

    eva.food.eggs = 50;
    eva.food.bread = 25;

    eva.car.value = 2'400'000;
    eva.car.gas = 15'000;

    eva.luxery.nogti = 3000;
}

void danil_init()
{
    danil.vtb.account = 0;
    danil.vtb.deposite = 1'000'000;
    danil.vtb.interest = 14.5;
    danil.salary = 180'000;

    danil.vtb.account_usd = 1'000;
    danil.vtb.rate_usd_rub = 78.5;

    danil.food.eggs = 30;
    danil.food.bread = 15;

    danil.gym.abonement = 2'500;
    danil.gym.personal_trainer = 5'000;
    danil.gym.sportswear = 2'000;
    danil.gym.towel = 500;
    danil.gym.locker_lock = 100;
    danil.gym.protein = 1'500;
    danil.gym.buds = 2'000;
    danil.gym.creatin = 500;
    danil.gym.desodorant = 300;


    danil.car.value = 2'400'000;
    danil.car.gas = 15'000;

	danil.hobby.golf = 2'000;
    danil.hobby.chess = 1'500;
    danil.hobby.swim = 1'000;
    danil.hobby.code = 0;
    danil.hobby.paint = 2'000;
	danil.hobby.cook = 500;
}


void eva_salary(const int month, const int year)
{
    if (month == 12) {
        eva.vtb.account += eva.salary;  // 13th salary
    }

    if (month == 1 and year == 2027) {
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
        danil.salary *= 1.5;  // promotion
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
    eva.vtb.account -= eva.kvartira.rent;
}


void eva_luxery()
{
    eva.vtb.account -= eva.luxery.nogti;
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
    danil.vtb.account -= danil.gym.abonement;
}


void eva_car()
{
    eva.vtb.account -= eva.car.gas;
}


void danil_car()
{
    danil.vtb.account -= danil.car.gas;
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

    while (not (month == 3 and year == 2028)) {
        eva_salary(month, year);
        eva_freelance(month, year);
        eva_car();
        eva_food();
        eva_luxery();
        eva_kvartira();
        // my_cat();
        // my_medine();
        // my_home();
        eva_deposite(month, year);


        danil_salary(month, year);
        danil_freelance(month, year);
        danil_car();
        danil_food();
        danil_deposite(month, year);
        danil_gym();


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