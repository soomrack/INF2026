#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <iomanip>


using RUB = unsigned long long int;

struct Birthdays
{
    RUB her;
    RUB mother;
    RUB father;
    RUB friends;
    RUB son;
};

struct Inspection
{
    RUB brake;   //тормоз
    RUB medical_bad;    // аптечка
    RUB fire_extinguisher;    //  огнетушитель
    RUB pendant;    // подвеска
    RUB steering_control;    // рулевое управление
    RUB checking_the_barrery;    // проверка аккумулятора
    RUB working_fluid;   // рабочая жидкость
    RUB candles;    //свечи зажигания
    RUB oil_change;   // смена масла
    RUB tires;    // шины
    RUB adjusting_the_headlights;    // регулировка фар
    RUB body_maintenance;   // обслуживание кузова
    RUB wiper_blade; // стеклоочиститель
};

struct Car
{
    RUB value;
    RUB gas;
    Inspection inspection;
};

struct Holidays
{
    RUB christmas;
    Birthdays birthday;
    RUB march8th;
    RUB february23th;
};

struct Vacation
{
    RUB plane;
    RUB excursion;
    RUB hotel;
    RUB food;
    RUB entertainment;
};

struct Car_In
{
    RUB adjusting_the_headlights;
    RUB gas;
    RUB body_maintenance;
    RUB brake;
    RUB candles;
    RUB checking_the_barrery;
    RUB fire_extinguisher;
    RUB medical_bad;
    RUB oil_change;
    RUB pendant;
    RUB steering_control;
    RUB tires;
    RUB working_fluid;
    RUB wiper_blade;
};

struct First_flat_in
{
    RUB cold_water;  // холодная вода
    RUB hot_water;    //горячая вода
    RUB electricity;   //  электричество
    RUB gas;   // газ
    RUB parking;   // паркинг
    RUB garbage_collection;    //  вывоз мусора
    RUB concierge;   //  консьерж
    RUB sewage_system;   //  система канализации
    RUB cleaning;   // мытьё полов в подъезде
    RUB repair;   //  ремонт подъезда и тд
    RUB management;   // оплата управлению дома
};

struct New_flat_in  // газа нет, переход на электрическую плиту
{
    RUB cold_water;
    RUB hot_water;
    RUB electricity;
    RUB parking;
    RUB garbage_collection;
    RUB concierge;
    RUB sewage_system;
    RUB cleaning;
    RUB repair;
    RUB management;
};

struct Communal_services_in
{
    First_flat_in first_flat;
    New_flat_in new_flat;
};

struct Inflation
{
    RUB food;
    Car_In car_in;
    RUB salary;
    RUB holiday;
    RUB vacation;
    RUB plane;
    RUB hotel;
    Communal_services_in communal_services;
};

struct Inflation russian_inflation;

void inflation_init()
{
    russian_inflation.food = 5.0;
    russian_inflation.salary = 6.0;
    russian_inflation.holiday = 7.0;
    russian_inflation.vacation = 7.0;
    russian_inflation.plane = 5.0;
    russian_inflation.hotel = 6.0;

    russian_inflation.car_in.adjusting_the_headlights = 7.0;
    russian_inflation.car_in.body_maintenance = 8.0;
    russian_inflation.car_in.brake = 3.0;
    russian_inflation.car_in.candles = 5.0;
    russian_inflation.car_in.checking_the_barrery = 4.0;
    russian_inflation.car_in.fire_extinguisher = 2.0;
    russian_inflation.car_in.gas = 6.0;
    russian_inflation.car_in.medical_bad = 4.5;
    russian_inflation.car_in.oil_change = 3.5;
    russian_inflation.car_in.pendant = 6.2;
    russian_inflation.car_in.steering_control = 4.3;
    russian_inflation.car_in.tires = 3.7;
    russian_inflation.car_in.working_fluid = 7.6;
    russian_inflation.car_in.wiper_blade = 4.2;

    russian_inflation.communal_services.first_flat.cleaning = 6.4;
    russian_inflation.communal_services.first_flat.cold_water = 2.0;
    russian_inflation.communal_services.first_flat.concierge = 2.6;
    russian_inflation.communal_services.first_flat.electricity = 2.3;
    russian_inflation.communal_services.first_flat.garbage_collection = 2.7;
    russian_inflation.communal_services.first_flat.gas = 2.9;
    russian_inflation.communal_services.first_flat.hot_water = 2.15;
    russian_inflation.communal_services.first_flat.management = 3.7;
    russian_inflation.communal_services.first_flat.parking = 5.0;
    russian_inflation.communal_services.first_flat.repair = 4.0;
    russian_inflation.communal_services.first_flat.sewage_system = 3.3;

    russian_inflation.communal_services.new_flat.cleaning = 1.4;
    russian_inflation.communal_services.new_flat.cold_water = 5.7;
    russian_inflation.communal_services.new_flat.concierge = 2.5;
    russian_inflation.communal_services.new_flat.electricity = 2.8;
    russian_inflation.communal_services.new_flat.garbage_collection = 4.6;
    russian_inflation.communal_services.new_flat.hot_water = 3.0;
    russian_inflation.communal_services.new_flat.management = 2.0;
    russian_inflation.communal_services.new_flat.parking = 4.0;
    russian_inflation.communal_services.new_flat.repair = 5.0;
    russian_inflation.communal_services.new_flat.sewage_system = 2.4;
}

double rand_inf_coef(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}

void inflation_rand()   //случайный выбор инфляции
{
    double inf_coef = rand_inf_coef(1.03, 1.1);
    russian_inflation.food *= inf_coef;
    russian_inflation.salary *= inf_coef;
    russian_inflation.holiday *= inf_coef;
    russian_inflation.vacation *= inf_coef;
    russian_inflation.plane *= inf_coef;
    russian_inflation.hotel *= inf_coef;

    russian_inflation.car_in.adjusting_the_headlights *= inf_coef;
    russian_inflation.car_in.body_maintenance *= inf_coef;
    russian_inflation.car_in.brake *= inf_coef;
    russian_inflation.car_in.candles *= inf_coef;
    russian_inflation.car_in.checking_the_barrery *= inf_coef;
    russian_inflation.car_in.fire_extinguisher *= inf_coef;
    russian_inflation.car_in.gas *= inf_coef;
    russian_inflation.car_in.medical_bad *= inf_coef;
    russian_inflation.car_in.oil_change *= inf_coef;
    russian_inflation.car_in.pendant *= inf_coef;
    russian_inflation.car_in.steering_control *= inf_coef;
    russian_inflation.car_in.tires *= inf_coef;
    russian_inflation.car_in.working_fluid *= inf_coef;

    russian_inflation.communal_services.first_flat.cleaning *= inf_coef;
    russian_inflation.communal_services.first_flat.cold_water *= inf_coef;
    russian_inflation.communal_services.first_flat.concierge *= inf_coef;
    russian_inflation.communal_services.first_flat.electricity *= inf_coef;
    russian_inflation.communal_services.first_flat.garbage_collection *= inf_coef;
    russian_inflation.communal_services.first_flat.gas *= inf_coef;
    russian_inflation.communal_services.first_flat.hot_water *= inf_coef;
    russian_inflation.communal_services.first_flat.management *= inf_coef;
    russian_inflation.communal_services.first_flat.parking *= inf_coef;
    russian_inflation.communal_services.first_flat.repair *= inf_coef;
    russian_inflation.communal_services.first_flat.sewage_system *= inf_coef;

    russian_inflation.communal_services.new_flat.cleaning *= inf_coef;
    russian_inflation.communal_services.new_flat.cold_water *= inf_coef;
    russian_inflation.communal_services.new_flat.concierge *= inf_coef;
    russian_inflation.communal_services.new_flat.electricity *= inf_coef;
    russian_inflation.communal_services.new_flat.garbage_collection *= inf_coef;
    russian_inflation.communal_services.new_flat.hot_water *= inf_coef;
    russian_inflation.communal_services.new_flat.management *= inf_coef;
    russian_inflation.communal_services.new_flat.parking *= inf_coef;
    russian_inflation.communal_services.new_flat.repair *= inf_coef;
    russian_inflation.communal_services.new_flat.sewage_system *= inf_coef;
}

struct Credit
{
    RUB remaind;
    RUB persents;
    RUB loan_payment;
};

struct First_flat
{
    RUB cold_water;
    RUB hot_water;
    RUB electricity;
    RUB gas;
    RUB parking;
    RUB garbage_collection;
    RUB concierge;
    RUB sewage_system;
    RUB cleaning;
    RUB repair;
    RUB management;
};

struct New_flat
{
    RUB cold_water;
    RUB hot_water;
    RUB electricity;
    RUB parking;
    RUB garbage_collection;
    RUB concierge;
    RUB sewage_system;
    RUB cleaning;
    RUB repair;
    RUB management;
};

struct Communal_services
{
    First_flat first_flat;
    New_flat new_flat;
};

struct Person
{
    RUB salary;
    RUB bank;
    RUB deposit;
    RUB food;
    Holidays holidays;
    Car car;
    Vacation vacation;
    Credit credit;
    RUB rend;
    Communal_services communal_services;
    //Flat flat_one, flat_two;
};

struct Person Alice;


double random_price_gas(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}

void alice_car(const int day, const int month, const int year)
{
    double price = random_price_gas(0.5, 1.5);    //случайные ежедневные затраты на бензин

    RUB daily_gas_cost = Alice.car.gas;
    daily_gas_cost = static_cast<int>(round(double(daily_gas_cost) * price));

    if ((day == 13) && (month == 10) && (year == 2028)) {  //рождение сына
        daily_gas_cost *= 1.3;
    }

    Alice.bank -= daily_gas_cost;

    if ((day == 1) && (month == 1))        //ежегодная инфляция 
    {
        Alice.car.gas *= 1.0 + (russian_inflation.car_in.gas / 100.0);
        Alice.car.inspection.adjusting_the_headlights *= 1.0 + (russian_inflation.car_in.adjusting_the_headlights / 100.0);
        Alice.car.inspection.body_maintenance *= 1.0 + (russian_inflation.car_in.body_maintenance / 100.0);
        Alice.car.inspection.brake *= 1.0 + (russian_inflation.car_in.brake / 100.0);
        Alice.car.inspection.candles *= 1.0 + (russian_inflation.car_in.candles / 100.0);
        Alice.car.inspection.checking_the_barrery *= 1.0 + (russian_inflation.car_in.checking_the_barrery / 100.0);
        Alice.car.inspection.fire_extinguisher *= 1.0 + (russian_inflation.car_in.fire_extinguisher / 100.0);
        Alice.car.inspection.medical_bad *= 1.0 + (russian_inflation.car_in.medical_bad / 100.0);
        Alice.car.inspection.oil_change *= 1.0 + (russian_inflation.car_in.oil_change / 100.0);
        Alice.car.inspection.pendant *= 1.0 + (russian_inflation.car_in.pendant / 100.0);
        Alice.car.inspection.steering_control *= 1.0 + (russian_inflation.car_in.steering_control / 100.0);
        Alice.car.inspection.tires *= 1.0 + (russian_inflation.car_in.tires / 100.0);
        Alice.car.inspection.working_fluid *= 1.0 + (russian_inflation.car_in.working_fluid / 100.0);
        Alice.car.inspection.wiper_blade *= 1.0 + (russian_inflation.car_in.wiper_blade);
    }

    if ((day == 30) && (month == 11))    //ежегодное техобслуживание автомобиля
    {
        RUB adjusting_the_headlights_cost = Alice.car.inspection.adjusting_the_headlights;
        adjusting_the_headlights_cost = static_cast<int>(round(double(adjusting_the_headlights_cost) * price));
        Alice.bank -= adjusting_the_headlights_cost;

        RUB body_maintenance_cost = Alice.car.inspection.body_maintenance;
        body_maintenance_cost = static_cast<int>(round(double(body_maintenance_cost) * price));
        Alice.bank -= body_maintenance_cost;

        RUB oil_change_cost = Alice.car.inspection.oil_change;
        oil_change_cost = static_cast<int>(round(double(oil_change_cost) * price));
        Alice.bank -= oil_change_cost;

        RUB candles_cost = Alice.car.inspection.candles;
        candles_cost = static_cast<int>(round(double(candles_cost) * price));
        Alice.bank -= candles_cost;

        RUB working_fluid_cost = Alice.car.inspection.working_fluid;
        working_fluid_cost = static_cast<int>(round(double(working_fluid_cost) * price));
        Alice.bank -= working_fluid_cost;

        RUB checking_the_barrery_cost = Alice.car.inspection.checking_the_barrery;
        checking_the_barrery_cost = static_cast<int>(round(double(checking_the_barrery_cost) * price));
        Alice.bank -= checking_the_barrery_cost;

        RUB steering_control_cost = Alice.car.inspection.steering_control;
        steering_control_cost = static_cast<int>(round(double(steering_control_cost) * price));
        Alice.bank -= steering_control_cost;

        RUB pendant_cost = Alice.car.inspection.pendant;
        pendant_cost = static_cast<int>(round(double(pendant_cost) * price));
        Alice.bank -= pendant_cost;

        RUB  fire_extinguisher_cost = Alice.car.inspection.fire_extinguisher;
        fire_extinguisher_cost = static_cast<int>(round(double(fire_extinguisher_cost) * price));
        Alice.bank -= fire_extinguisher_cost;

        RUB medical_bad_cost = Alice.car.inspection.medical_bad;
        medical_bad_cost = static_cast<int>(round(double(medical_bad_cost) * price));
        Alice.bank -= medical_bad_cost;

        RUB brake_cost = Alice.car.inspection.brake;
        brake_cost = static_cast<int>(round(double(brake_cost) * price));
        Alice.bank -= brake_cost;

        RUB wiper_blade_cost = Alice.car.inspection.wiper_blade;
        wiper_blade_cost = static_cast<int>(round(double(wiper_blade_cost) * price));
        Alice.bank -= wiper_blade_cost;
    }

    if (((day == 30) && (month == 2)) or ((day == 30) && (month == 11)))  // замена шин
    {
        RUB tires_cost = Alice.car.inspection.tires;
        tires_cost = static_cast<int>(round(double(tires_cost) * price));
        Alice.bank -= Alice.car.inspection.tires;
    }

}

double random_premium(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}

void alice_salary(const int day, const int month, const int year)
{
    double price = random_premium(0.0, 0.5);

    if ((day == 1) && (month == 8))   //ежегодная возможная премия
    {
        RUB premium = Alice.salary;
        premium = static_cast<int>(round(double(premium) * price));
        Alice.bank += premium;
    }
    if ((day == 1) && (month == 12) && (year == 2028))   //уход в декрет
    {
        Alice.salary = Alice.salary * 0.4;
    }
    if ((day == 1) && (month == 12) && (year == 2030))   //выход с декрета
    {
        Alice.salary = Alice.salary * 2.5;
    }
    if (day == 1)     //аванс
    {
        Alice.bank += Alice.salary * 0.5;
    }
    if (day == 15)    //зарплата
    {
        Alice.bank += Alice.salary * 0.5;
    }
    if ((day == 1) && (month == 1))   //годовая инфляция
    {
        Alice.salary *= 1.0 + (russian_inflation.salary / 100.0);
    }

}

double random_price_holidays(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}

void alice_holidays(const int day, const int month, const int year)
{
    double price = random_price_holidays(0.8, 1.7);   //случайная затрата на подарки

    if ((day == 1) && (month == 1))
    {
        RUB christmas_cost = Alice.holidays.christmas;
        christmas_cost = static_cast<int>(round(double(christmas_cost) * price));
        Alice.bank -= christmas_cost;
    }
    if ((day == 23) && (month == 2))
    {
        RUB february23th_cost = Alice.holidays.february23th;
        february23th_cost = static_cast<int>(round(double(february23th_cost) * price));
        Alice.bank -= february23th_cost;
    }
    if ((day == 8) && (month == 3))
    {
        RUB march8th_cost = Alice.holidays.march8th;
        march8th_cost = static_cast<int>(round(double(march8th_cost) * price));
        Alice.bank -= march8th_cost;
    }
    if ((day == 4) && (month == 5))
    {
        RUB birthday_father_cost = Alice.holidays.birthday.father;
        birthday_father_cost = static_cast<int>(round(double(birthday_father_cost) * price));
        Alice.bank -= birthday_father_cost;
    }
    if ((day == 7) && (month == 6))
    {
        RUB birthday_friends_cost = Alice.holidays.birthday.friends;
        birthday_friends_cost = static_cast<int>(round(double(birthday_friends_cost) * price));
        Alice.bank -= birthday_friends_cost;
    }
    if ((day == 28) && (month == 8))
    {
        RUB birthday_her_cost = Alice.holidays.birthday.her;
        birthday_her_cost = static_cast<int>(round(double(birthday_her_cost) * price));
        Alice.bank -= birthday_her_cost;
    }
    if ((day == 16) && (month == 9))
    {
        RUB birthday_mother_cost = Alice.holidays.birthday.mother;
        birthday_mother_cost = static_cast<int>(round(double(birthday_mother_cost) * price));
        Alice.bank -= birthday_mother_cost;
    }

    if ((day == 13) && (month == 10) && (year >= 2028))
    {
        RUB birthday_son_cost = Alice.holidays.birthday.son;
        birthday_son_cost = static_cast<int>(round(double(birthday_son_cost) * price));
        Alice.bank -= birthday_son_cost;
    }

    if ((day == 1) && (month == 1))    //среднее измеенение затрат на подарки
    {
        Alice.holidays.birthday.father *= 1.0 + (russian_inflation.holiday / 100.0);
        Alice.holidays.birthday.friends *= 1.0 + (russian_inflation.holiday / 100.0);
        Alice.holidays.birthday.her *= 1.0 + (russian_inflation.holiday / 100.0);
        Alice.holidays.birthday.mother *= 1.0 + (russian_inflation.holiday / 100.0);
        Alice.holidays.birthday.son *= 1.0 + (russian_inflation.holiday / 100.0);
        Alice.holidays.christmas *= 1.0 + (russian_inflation.holiday / 100.0);
        Alice.holidays.february23th *= 1.0 + (russian_inflation.holiday / 100.0);
        Alice.holidays.march8th *= 1.0 + (russian_inflation.holiday / 100.0);
    }

}


double random_price_vacation(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}


void alice_vacation(const int day, const int month, const int year)
{
    double price = random_price_vacation(0.85, 1.50);   //случайная сумма затрат на путешествие

    if ((day >= 3) && (day <= 17) && (month == 7))    //затраты на еду
    {
        RUB vacation_food_cost = Alice.vacation.food;
        vacation_food_cost = static_cast<int>(round(double(vacation_food_cost) * price));
        Alice.deposit -= vacation_food_cost;
    }

    if ((day == 20) && (month == 6))        //покупка билетов
    {
        RUB vacation_plane_cost = Alice.vacation.plane;
        vacation_plane_cost = static_cast<int>(round(double(vacation_plane_cost) * price));
        Alice.deposit -= vacation_plane_cost;
    }

    if ((day == 21) && (month == 6))       //снятие номера в отеле
    {
        RUB vacation_hotel_cost = Alice.vacation.hotel;
        vacation_hotel_cost  = static_cast<int>(round(double(vacation_hotel_cost) * price));
        Alice.deposit -= vacation_hotel_cost;
    }

    if (((day == 4) or (day == 10) or (day == 15)) && (month == 7))    //затраты на экскурсии
    {
        RUB vacation_excursion_cost = Alice.vacation.excursion;
        vacation_excursion_cost  = static_cast<int>(round(double(vacation_excursion_cost) * price));
        Alice.deposit -= vacation_excursion_cost;
    }

    if ((day >= 4) && (day <= 16) && (month == 7))      //затраты на развлечения
    {
        RUB vacation_entertainment_cost = Alice.vacation.entertainment;
        vacation_entertainment_cost  = static_cast<int>(round(double(vacation_entertainment_cost) * price));
        Alice.deposit -= vacation_entertainment_cost;
    }

    if ((day == 1) && (month == 1))   //увеличение стоимости 
    {
        Alice.vacation.excursion *= 1.0 + (russian_inflation.vacation / 100.0);
        Alice.vacation.entertainment *= 1.0 + (russian_inflation.vacation / 100.0);
        Alice.vacation.food *= 1.0 + (russian_inflation.food / 100.0);
        Alice.vacation.plane *= 1.0 + (russian_inflation.plane / 100.0);
        Alice.vacation.hotel *= 1.0 + (russian_inflation.hotel / 100.0);
    }

    if ((day == 13) && (month == 10) && (year == 2028))  //увеличение затрат из-за рождения сына
    {
        Alice.vacation.food *= 2.0;
        Alice.vacation.plane *= 2.0;
        Alice.vacation.hotel *= 1.5;
        Alice.vacation.excursion *= 2.0;
        Alice.vacation.entertainment *= 1.5;
    }
}

void print_results()
{
    std::cout << "Salary = ";
    std::cout << Alice.salary;
    std::cout << std::endl;

    std::cout << "Deposit = ";
    std::cout << Alice.deposit;
    std::cout << std::endl;
}

double random_price_food(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}

void alice_food(const int day, const int month, const int year)
{
    double price = random_price_food(0.5, 1.5);

    if ((day == 13) && (month == 10) && (year == 2028))    //увеличение затрат из-за рождения сына
    {
        Alice.food = Alice.food * 2.0;
    }

    if ((day >= 3) && (day <= 17) && (month == 7))    //затрата учитывается в рассчёте отпуска
    {
        Alice.food = 0.0;
    }

    if ((day == 1) && (month == 1))      //инфляция еды
    {
        Alice.food *= 1.0 + (russian_inflation.food / 100.0);
    }

    RUB food_cost = Alice.food;
    food_cost  = static_cast<int>(round(double(food_cost) * price));

    Alice.bank -= food_cost;
}

double random_loan_payment(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}

double random_communal_services(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}


void alice_apartment(const int day, const int month, const int year)
{
    if ((day == 30 && month < 4 && year == 2030) or (day == 30 && year < 2030))  // аренда квартиры
    {
        Alice.deposit -= Alice.rend;
    }

    if (day == 30 && month == 4 && year == 2030)   //первый взнос, переезд
    {
        Alice.deposit -= Alice.credit.remaind * 0.2;
        Alice.credit.remaind *= 0.8;
    }

    if ((day == 30 && month > 4 && year == 2030) or (day == 30 && year > 2030))
    {
        if (!(Alice.credit.remaind == 0.0))
        {
            if (Alice.credit.remaind < 70000.0)   //последняя выплата
            {
                Alice.deposit -= Alice.credit.remaind;
                Alice.credit.remaind = 0.0;
            }
            else   //регулярные месячные выплаты
            {
                double price = random_loan_payment(1.0, 1.1);
                RUB loan_payment_opportunity = Alice.credit.loan_payment;
                loan_payment_opportunity = static_cast<int>(round(double() * price));
                Alice.deposit -= loan_payment_opportunity;
                Alice.credit.remaind -= loan_payment_opportunity;
                Alice.credit.remaind *= Alice.credit.persents;
            }
        }
    }

    if ((day == 13) && (month == 10) && (year == 2028))  //рождение сына
    {
        Alice.communal_services.first_flat.cleaning *= 2.0;
        Alice.communal_services.first_flat.cold_water *= 2.0;
        Alice.communal_services.first_flat.concierge *= 2.0;
        Alice.communal_services.first_flat.electricity *= 2.0;
        Alice.communal_services.first_flat.garbage_collection *= 2.0;
        Alice.communal_services.first_flat.gas *= 2.0;
        Alice.communal_services.first_flat.hot_water *= 2.0;
        Alice.communal_services.first_flat.management *= 2.0;
        Alice.communal_services.first_flat.parking *= 2.0;
        Alice.communal_services.first_flat.repair *= 2.0;
        Alice.communal_services.first_flat.sewage_system *= 2.0;
    }

    if ((day == 1) && (month == 1) && (year <= 2030))
    {
        Alice.communal_services.first_flat.cleaning *= 1.0 + (russian_inflation.communal_services.first_flat.cleaning / 100.0);
        Alice.communal_services.first_flat.cold_water *= 1.0 + (russian_inflation.communal_services.first_flat.cold_water/ 100.0);
        Alice.communal_services.first_flat.concierge *= 1.0 + (russian_inflation.communal_services.first_flat.concierge / 100.0);
        Alice.communal_services.first_flat.electricity *= 1.0 + (russian_inflation.communal_services.first_flat.electricity / 100.0);
        Alice.communal_services.first_flat.garbage_collection *= 1.0 + (russian_inflation.communal_services.first_flat.garbage_collection / 100.0);
        Alice.communal_services.first_flat.gas *= 1.0 + (russian_inflation.communal_services.first_flat.gas / 100.0);
        Alice.communal_services.first_flat.hot_water *= 1.0 + (russian_inflation.communal_services.first_flat.hot_water / 100.0);
        Alice.communal_services.first_flat.management *= 1.0 + (russian_inflation.communal_services.first_flat.management / 100.0);
        Alice.communal_services.first_flat.parking *= 1.0 + (russian_inflation.communal_services.first_flat.parking / 100.0);
        Alice.communal_services.first_flat.repair *= 1.0 + (russian_inflation.communal_services.first_flat.repair / 100.0);
        Alice.communal_services.first_flat.sewage_system *= 1.0 + (russian_inflation.communal_services.first_flat.sewage_system / 100.0);
    }

    if ((day == 1) && (month == 1) && (year > 2030))
    {
        Alice.communal_services.new_flat.cleaning = 1.0 + (russian_inflation.communal_services.new_flat.cleaning);
        Alice.communal_services.new_flat.cold_water = 1.0 + (russian_inflation.communal_services.new_flat.cold_water);
        Alice.communal_services.new_flat.concierge = 1.0 + (russian_inflation.communal_services.new_flat.concierge);
        Alice.communal_services.new_flat.electricity = 1.0 + (russian_inflation.communal_services.new_flat.electricity);
        Alice.communal_services.new_flat.garbage_collection = 1.0 + (russian_inflation.communal_services.new_flat.garbage_collection);
        Alice.communal_services.new_flat.hot_water = 1.0 + (russian_inflation.communal_services.new_flat.hot_water);
        Alice.communal_services.new_flat.management = 1.0 + (russian_inflation.communal_services.new_flat.management);
        Alice.communal_services.new_flat.parking = 1.0 + (russian_inflation.communal_services.new_flat.parking);
        Alice.communal_services.new_flat.repair = 1.0 + (russian_inflation.communal_services.new_flat.repair);
        Alice.communal_services.new_flat.sewage_system = 1.0 + (russian_inflation.communal_services.new_flat.sewage_system);
    }

    if ((day == 30 && month < 4 && year == 2030) or (day == 30 && year < 2030))
    {
        double price = random_communal_services(0.5, 1.5);

        RUB cleaning_cout = Alice.communal_services.first_flat.cleaning;
        cleaning_cout = static_cast<int>(round(double(cleaning_cout) * price));
        Alice.bank -= cleaning_cout;

        RUB cold_water_cout = Alice.communal_services.first_flat.cold_water;
        cold_water_cout = static_cast<int>(round(double(cold_water_cout) * price));
        Alice.bank -= cold_water_cout;

        RUB concierge_cout = Alice.communal_services.first_flat.concierge;
        concierge_cout = static_cast<int>(round(double(concierge_cout) * price));
        Alice.bank -= concierge_cout;

        RUB electricity_cout = Alice.communal_services.first_flat.electricity;
        electricity_cout = static_cast<int>(round(double(electricity_cout) * price));
        Alice.bank -= electricity_cout;

        RUB garbage_collection_cout = Alice.communal_services.first_flat.garbage_collection;
        garbage_collection_cout = static_cast<int>(round(double(garbage_collection_cout) * price));
        Alice.bank -= garbage_collection_cout;

        RUB gas_cout = Alice.communal_services.first_flat.gas;
        gas_cout = static_cast<int>(round(double(gas_cout) * price));
        Alice.bank -= gas_cout;

        RUB hot_water_cout = Alice.communal_services.first_flat.hot_water;
        hot_water_cout = static_cast<int>(round(double(hot_water_cout) * price));
        Alice.bank -= hot_water_cout;

        RUB management_cout = Alice.communal_services.first_flat.management;
        management_cout = static_cast<int>(round(double(management_cout) * price));
        Alice.bank -= management_cout;

        RUB parking_cout = Alice.communal_services.first_flat.parking;
        parking_cout = static_cast<int>(round(double(parking_cout) * price));
        Alice.bank -= parking_cout;

        RUB repair_cout = Alice.communal_services.first_flat.repair;
        repair_cout = static_cast<int>(round(double(repair_cout) * price));
        Alice.bank -= repair_cout;

        RUB sewage_system_cout = Alice.communal_services.first_flat.sewage_system;
        sewage_system_cout = static_cast<int>(round(double(sewage_system_cout) * price));
        Alice.bank -= sewage_system_cout;
    }

    if ((day == 30 && month >= 4 && year == 2030) or (day == 30 && year > 2030))
    {
        double price = random_communal_services(0.5, 1.5);

        RUB cleaning_cout = Alice.communal_services.new_flat.cleaning;
        cleaning_cout = static_cast<int>(round(double(cleaning_cout) * price));
        Alice.bank -= cleaning_cout;

        RUB cold_water_cout = Alice.communal_services.new_flat.cold_water;
        cold_water_cout = static_cast<int>(round(double(cold_water_cout) * price));
        Alice.bank -= cold_water_cout;

        RUB concierge_cout = Alice.communal_services.new_flat.concierge;
        concierge_cout = static_cast<int>(round(double(concierge_cout) * price));
        Alice.bank -= concierge_cout;

        RUB electricity_cout = Alice.communal_services.new_flat.electricity;
        electricity_cout = static_cast<int>(round(double(electricity_cout) * price));
        Alice.bank -= electricity_cout;

        RUB garbage_collection_cout = Alice.communal_services.new_flat.garbage_collection;
        garbage_collection_cout = static_cast<int>(round(double(garbage_collection_cout) * price));
        Alice.bank -= garbage_collection_cout;

        RUB hot_water_cout = Alice.communal_services.new_flat.hot_water;
        hot_water_cout = static_cast<int>(round(double(hot_water_cout) * price));
        Alice.bank -= hot_water_cout;

        RUB management_cout = Alice.communal_services.new_flat.management;
        management_cout = static_cast<int>(round(double(management_cout) * price));
        Alice.bank -= management_cout;

        RUB parking_cout = Alice.communal_services.new_flat.parking;
        parking_cout = static_cast<int>(round(double(parking_cout) * price));
        Alice.bank -= parking_cout;

        RUB repair_cout = Alice.communal_services.new_flat.repair;
        repair_cout = static_cast<int>(round(double(repair_cout) * price));
        Alice.bank -= repair_cout;

        RUB sewage_system_cout = Alice.communal_services.new_flat.sewage_system;
        sewage_system_cout = static_cast<int>(round(double(sewage_system_cout) * price));
        Alice.bank -= sewage_system_cout;
    }

}

void alice_dacha(const int day, const int month, const int year)
{

}

void alice_bank_deposit(const int day, const int month, const int year)
{
    float pp = 14.5;

    if ((day >= 1 && month >= 10 && year >= 2026) or (year > 2026))     //окончание акции повышенного процента вклада
    {
        pp = 10.0;
    }

    if (day == 30)    //ежемесячное начисление остатков и процентов
    {
        RUB to_deposit = Alice.bank * 0.9;  //откладывание 90% остатков в депозит
        Alice.deposit += to_deposit;
        Alice.bank -= to_deposit;
        Alice.deposit *= 1 + (pp / 100.0 / 12.0);
    }

}

void simulation()
{

    int day = 2;
    int month = 2;
    int year = 2026;


    while (!((day == 3) && (month == 4) && (year == 2040)))
    {


        // my_cat() 
        alice_salary(day, month, year);

        alice_holidays(day, month, year);
        alice_vacation(day, month, year);
        alice_food(day, month, year);
        alice_car(day, month, year);
        alice_apartment(day, month, year);
        alice_dacha(day, month, year);

        alice_bank_deposit(day, month, year);

        if ((day == 1) && (month == 1))
        {
            inflation_rand();
        }


        ++day;

        if (day == 31)  {
            day = 1;
            ++month;
        }

        if (month == 13)
        {
            month = 1;
            ++year;
        }
    }
}

void alice_init()
{

    Alice.bank = 50000.0;
    Alice.deposit = 500000.0;
    Alice.salary = 181000.0;

    Alice.food = 1000.0;

    Alice.car.value = 2400000.0;
    Alice.car.gas = 500.0;
    Alice.car.inspection.adjusting_the_headlights = 3000.0;
    Alice.car.inspection.body_maintenance = 2000.0;
    Alice.car.inspection.brake = 1500.0;
    Alice.car.inspection.candles = 2500.0;
    Alice.car.inspection.checking_the_barrery = 1700.0;
    Alice.car.inspection.fire_extinguisher = 1300.0;
    Alice.car.inspection.medical_bad = 1200.0;
    Alice.car.inspection.oil_change = 1000.0;
    Alice.car.inspection.pendant = 1100.0;
    Alice.car.inspection.steering_control = 1900.0;
    Alice.car.inspection.tires = 1800.0;
    Alice.car.inspection.working_fluid = 1400.0;

    Alice.holidays.birthday.father = 6000.0;
    Alice.holidays.birthday.friends = 4000.0;
    Alice.holidays.birthday.mother = 7000.0;
    Alice.holidays.birthday.her = 10000.0;
    Alice.holidays.christmas = 10000.0;
    Alice.holidays.february23th = 3000.0;
    Alice.holidays.march8th = 2000.0;
    Alice.holidays.birthday.son = 10000.0;

    Alice.vacation.entertainment = 2000.0;
    Alice.vacation.excursion = 5000.0;
    Alice.vacation.food = 1500.0;
    Alice.vacation.hotel = 30000.0;
    Alice.vacation.plane = 20000.0;

    Alice.credit.remaind = 12000000.0;
    Alice.credit.loan_payment = 60000.0;
    Alice.credit.persents = 8;

    Alice.rend = 20000;

    Alice.communal_services.first_flat.cleaning = 1100;
    Alice.communal_services.first_flat.cold_water = 900;
    Alice.communal_services.first_flat.concierge = 600;
    Alice.communal_services.first_flat.electricity = 1500;
    Alice.communal_services.first_flat.garbage_collection = 1030;
    Alice.communal_services.first_flat.gas = 1010;
    Alice.communal_services.first_flat.hot_water = 200;
    Alice.communal_services.first_flat.management = 700;
    Alice.communal_services.first_flat.parking = 1047;
    Alice.communal_services.first_flat.repair = 1036;
    Alice.communal_services.first_flat.sewage_system = 1092;

    Alice.communal_services.new_flat.cleaning = 800;
    Alice.communal_services.new_flat.cold_water = 1100;
    Alice.communal_services.new_flat.concierge = 1050;
    Alice.communal_services.new_flat.electricity = 2400;
    Alice.communal_services.new_flat.garbage_collection = 870;
    Alice.communal_services.new_flat.hot_water = 1000;
    Alice.communal_services.new_flat.management = 1060;
    Alice.communal_services.new_flat.parking = 1230;
    Alice.communal_services.new_flat.repair = 760;
    Alice.communal_services.new_flat.sewage_system = 990;
}


int main()
{
    inflation_init();

    alice_init();

    simulation();

    print_results();

}



