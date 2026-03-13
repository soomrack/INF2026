#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string>

using RUB = long long int;
int year = 2026;
int month = 2;
double salary_up = 0.07;
int inflation = 7;

struct Car {
    std::string name;
    RUB price;
    int max_speed;
    int engine_power;
    double fuel_consumption;
    int year_of_issue;
    RUB monthly_maintenance;
};

struct Apartment {
    std::string address;
    RUB price;
    int rooms;
    double area;
    int floor;
    int building_year;
    RUB monthly_maintenance;
    std::string district;
};

struct User
{
    RUB salary;
    RUB balance;
    double koeff;
    int trust_lvl;
    Car car;
    int has_car;
    RUB car_credit_payment;
    int car_credit_months;
    Apartment apartment;
    int has_apartment;
    RUB apartment_credit_payment;
    int apartment_credit_months;
    RUB apartment_initial_payment;
};

struct Car car_catalog[10];  // std::array<...>
struct Apartment apartment_catalog_center[10];    
struct Apartment apartment_catalog_sleeping[10];   
struct Apartment apartment_catalog_suburb[10];     

void fill_car_catalog() {
    car_catalog[0].name = "Lada Vesta";
    car_catalog[0].price = 1500000;
    car_catalog[0].max_speed = 180;
    car_catalog[0].engine_power = 106;
    car_catalog[0].fuel_consumption = 7.5;
    car_catalog[0].year_of_issue = 2023;
    car_catalog[0].monthly_maintenance = 2023;
    
    car_catalog[1].name = "Nissan";
    car_catalog[1].price = 2000000;
    car_catalog[1].max_speed = 190;
    car_catalog[1].engine_power = 123;
    car_catalog[1].fuel_consumption = 6.8;
    car_catalog[1].year_of_issue = 2024;
    car_catalog[1].monthly_maintenance = 2023;
    
    car_catalog[2].name = "Skoda";
    car_catalog[2].price = 1900000;
    car_catalog[2].max_speed = 185;
    car_catalog[2].engine_power = 115;
    car_catalog[2].fuel_consumption = 7.0;
    car_catalog[2].year_of_issue = 2024;
    car_catalog[2].monthly_maintenance = 2023;
    
    car_catalog[3].name = "ferrari";
    car_catalog[3].price = 3500000;
    car_catalog[3].max_speed = 210;
    car_catalog[3].engine_power = 200;
    car_catalog[3].fuel_consumption = 8.5;
    car_catalog[3].year_of_issue = 2025;
    car_catalog[3].monthly_maintenance = 2023;
    
    car_catalog[4].name = "Mitsubisi";
    car_catalog[4].price = 7500000;
    car_catalog[4].max_speed = 250;
    car_catalog[4].engine_power = 340;
    car_catalog[4].fuel_consumption = 11.2;
    car_catalog[4].year_of_issue = 2025;
    car_catalog[4].monthly_maintenance = 2023;
    
    car_catalog[5].name = "Maybach";
    car_catalog[5].price = 6800000;
    car_catalog[5].max_speed = 240;
    car_catalog[5].engine_power = 300;
    car_catalog[5].fuel_consumption = 10.5;
    car_catalog[5].year_of_issue = 2024;
    car_catalog[5].monthly_maintenance = 2023;
    
    car_catalog[6].name = "Tesla";
    car_catalog[6].price = 7200000;
    car_catalog[6].max_speed = 245;
    car_catalog[6].engine_power = 320;
    car_catalog[6].fuel_consumption = 11.0;
    car_catalog[6].year_of_issue = 2025;
    car_catalog[6].monthly_maintenance = 2023;
    
    car_catalog[7].name = "Porshe";
    car_catalog[7].price = 1300000;
    car_catalog[7].max_speed = 170;
    car_catalog[7].engine_power = 90;
    car_catalog[7].fuel_consumption = 6.5;
    car_catalog[7].year_of_issue = 2023;
    car_catalog[7].monthly_maintenance = 2023;
    
    car_catalog[8].name = "Range rover";
    car_catalog[8].price = 2500000;
    car_catalog[8].max_speed = 200;
    car_catalog[8].engine_power = 150;
    car_catalog[8].fuel_consumption = 7.2;
    car_catalog[8].year_of_issue = 2024;
    car_catalog[8].monthly_maintenance = 2023;
    
    car_catalog[9].name = "Zeekr";
    car_catalog[9].price = 1800000;
    car_catalog[9].max_speed = 185;
    car_catalog[9].engine_power = 110;
    car_catalog[9].fuel_consumption = 6.9;
    car_catalog[9].year_of_issue = 2024;
    car_catalog[9].monthly_maintenance = 2023;
}

void fill_apartment_catalog_center() {
    std::string districts[3] = {"Центральный", "Спальный", "Пригород"};
    
    apartment_catalog_center[0].address = "ул. Ленина, д. 10, кв. 5";
    apartment_catalog_center[0].price = 15000000;
    apartment_catalog_center[0].rooms = 3;
    apartment_catalog_center[0].area = 75.5;
    apartment_catalog_center[0].floor = 5;
    apartment_catalog_center[0].building_year = 2015;
    apartment_catalog_center[0].monthly_maintenance = 8500;
    apartment_catalog_center[0].district = districts[0];
    
    apartment_catalog_center[1].address = "ул. Советская, д. 25, кв. 12";
    apartment_catalog_center[1].price = 18500000;
    apartment_catalog_center[1].rooms = 4;
    apartment_catalog_center[1].area = 92.0;
    apartment_catalog_center[1].floor = 7;
    apartment_catalog_center[1].building_year = 2018;
    apartment_catalog_center[1].monthly_maintenance = 12000;
    apartment_catalog_center[1].district = districts[0];
    
    apartment_catalog_center[2].address = "пр. Мира, д. 15, кв. 8";
    apartment_catalog_center[2].price = 9200000;
    apartment_catalog_center[2].rooms = 2;
    apartment_catalog_center[2].area = 52.3;
    apartment_catalog_center[2].floor = 3;
    apartment_catalog_center[2].building_year = 2010;
    apartment_catalog_center[2].monthly_maintenance = 6200;
    apartment_catalog_center[2].district = districts[0];
    
    apartment_catalog_center[3].address = "ул. Пушкина, д. 7, кв. 15";
    apartment_catalog_center[3].price = 21000000;
    apartment_catalog_center[3].rooms = 4;
    apartment_catalog_center[3].area = 105.0;
    apartment_catalog_center[3].floor = 9;
    apartment_catalog_center[3].building_year = 2020;
    apartment_catalog_center[3].monthly_maintenance = 15000;
    apartment_catalog_center[3].district = districts[0];
    
    apartment_catalog_center[4].address = "ул. Гагарина, д. 3, кв. 22";
    apartment_catalog_center[4].price = 7800000;
    apartment_catalog_center[4].rooms = 1;
    apartment_catalog_center[4].area = 38.5;
    apartment_catalog_center[4].floor = 2;
    apartment_catalog_center[4].building_year = 2005;
    apartment_catalog_center[4].monthly_maintenance = 4800;
    apartment_catalog_center[4].district = districts[0];
    
    apartment_catalog_center[5].address = "ул. Кирова, д. 12, кв. 31";
    apartment_catalog_center[5].price = 12500000;
    apartment_catalog_center[5].rooms = 3;
    apartment_catalog_center[5].area = 68.0;
    apartment_catalog_center[5].floor = 4;
    apartment_catalog_center[5].building_year = 2012;
    apartment_catalog_center[5].monthly_maintenance = 7800;
    apartment_catalog_center[5].district = districts[0];
    
    apartment_catalog_center[6].address = "пр. Революции, д. 8, кв. 42";
    apartment_catalog_center[6].price = 16800000;
    apartment_catalog_center[6].rooms = 3;
    apartment_catalog_center[6].area = 82.5;
    apartment_catalog_center[6].floor = 6;
    apartment_catalog_center[6].building_year = 2016;
    apartment_catalog_center[6].monthly_maintenance = 9800;
    apartment_catalog_center[6].district = districts[0];
    
    apartment_catalog_center[7].address = "ул. Коммунистическая, д. 5, кв. 18";
    apartment_catalog_center[7].price = 5600000;
    apartment_catalog_center[7].rooms = 1;
    apartment_catalog_center[7].area = 32.0;
    apartment_catalog_center[7].floor = 1;
    apartment_catalog_center[7].building_year = 2000;
    apartment_catalog_center[7].monthly_maintenance = 3900;
    apartment_catalog_center[7].district = districts[0];
    
    apartment_catalog_center[8].address = "ул. Октябрьская, д. 22, кв. 7";
    apartment_catalog_center[8].price = 14200000;
    apartment_catalog_center[8].rooms = 3;
    apartment_catalog_center[8].area = 71.0;
    apartment_catalog_center[8].floor = 5;
    apartment_catalog_center[8].building_year = 2014;
    apartment_catalog_center[8].monthly_maintenance = 8300;
    apartment_catalog_center[8].district = districts[0];
    
    apartment_catalog_center[9].address = "ул. Карла Маркса, д. 17, кв. 25";
    apartment_catalog_center[9].price = 19700000;
    apartment_catalog_center[9].rooms = 4;
    apartment_catalog_center[9].area = 98.0;
    apartment_catalog_center[9].floor = 8;
    apartment_catalog_center[9].building_year = 2019;
    apartment_catalog_center[9].monthly_maintenance = 13500;
    apartment_catalog_center[9].district = districts[0];
}

void fill_apartment_catalog_sleeping() {
    std::string districts[3] = {"Центральный", "Спальный", "Пригород"};
    
    apartment_catalog_sleeping[0].address = "ул. Молодежная, д. 5, кв. 42";
    apartment_catalog_sleeping[0].price = 8500000;
    apartment_catalog_sleeping[0].rooms = 3;
    apartment_catalog_sleeping[0].area = 65.0;
    apartment_catalog_sleeping[0].floor = 9;
    apartment_catalog_sleeping[0].building_year = 2017;
    apartment_catalog_sleeping[0].monthly_maintenance = 6200;
    apartment_catalog_sleeping[0].district = districts[1];
    
    apartment_catalog_sleeping[1].address = "ул. Строителей, д. 12, кв. 78";
    apartment_catalog_sleeping[1].price = 6200000;
    apartment_catalog_sleeping[1].rooms = 2;
    apartment_catalog_sleeping[1].area = 48.5;
    apartment_catalog_sleeping[1].floor = 5;
    apartment_catalog_sleeping[1].building_year = 2015;
    apartment_catalog_sleeping[1].monthly_maintenance = 4800;
    apartment_catalog_sleeping[1].district = districts[1];
    
    apartment_catalog_sleeping[2].address = "ул. Космонавтов, д. 8, кв. 15";
    apartment_catalog_sleeping[2].price = 4300000;
    apartment_catalog_sleeping[2].rooms = 1;
    apartment_catalog_sleeping[2].area = 35.0;
    apartment_catalog_sleeping[2].floor = 3;
    apartment_catalog_sleeping[2].building_year = 2012;
    apartment_catalog_sleeping[2].monthly_maintenance = 3500;
    apartment_catalog_sleeping[2].district = districts[1];
    
    apartment_catalog_sleeping[3].address = "ул. Мира, д. 3, кв. 92";
    apartment_catalog_sleeping[3].price = 11200000;
    apartment_catalog_sleeping[3].rooms = 4;
    apartment_catalog_sleeping[3].area = 88.0;
    apartment_catalog_sleeping[3].floor = 12;
    apartment_catalog_sleeping[3].building_year = 2019;
    apartment_catalog_sleeping[3].monthly_maintenance = 9200;
    apartment_catalog_sleeping[3].district = districts[1];
    
    apartment_catalog_sleeping[4].address = "ул. Парковая, д. 15, кв. 34";
    apartment_catalog_sleeping[4].price = 7600000;
    apartment_catalog_sleeping[4].rooms = 3;
    apartment_catalog_sleeping[4].area = 62.0;
    apartment_catalog_sleeping[4].floor = 7;
    apartment_catalog_sleeping[4].building_year = 2016;
    apartment_catalog_sleeping[4].monthly_maintenance = 5600;
    apartment_catalog_sleeping[4].district = districts[1];
    
    apartment_catalog_sleeping[5].address = "ул. Лесная, д. 22, кв. 51";
    apartment_catalog_sleeping[5].price = 5800000;
    apartment_catalog_sleeping[5].rooms = 2;
    apartment_catalog_sleeping[5].area = 45.0;
    apartment_catalog_sleeping[5].floor = 4;
    apartment_catalog_sleeping[5].building_year = 2014;
    apartment_catalog_sleeping[5].monthly_maintenance = 4300;
    apartment_catalog_sleeping[5].district = districts[1];
    
    apartment_catalog_sleeping[6].address = "ул. Солнечная, д. 7, кв. 63";
    apartment_catalog_sleeping[6].price = 9800000;
    apartment_catalog_sleeping[6].rooms = 3;
    apartment_catalog_sleeping[6].area = 72.5;
    apartment_catalog_sleeping[6].floor = 10;
    apartment_catalog_sleeping[6].building_year = 2018;
    apartment_catalog_sleeping[6].monthly_maintenance = 7100;
    apartment_catalog_sleeping[6].district = districts[1];
    
    apartment_catalog_sleeping[7].address = "ул. Цветочная, д. 11, кв. 28";
    apartment_catalog_sleeping[7].price = 3900000;
    apartment_catalog_sleeping[7].rooms = 1;
    apartment_catalog_sleeping[7].area = 33.0;
    apartment_catalog_sleeping[7].floor = 2;
    apartment_catalog_sleeping[7].building_year = 2010;
    apartment_catalog_sleeping[7].monthly_maintenance = 3100;
    apartment_catalog_sleeping[7].district = districts[1];
    
    apartment_catalog_sleeping[8].address = "ул. Школьная, д. 18, кв. 47";
    apartment_catalog_sleeping[8].price = 8400000;
    apartment_catalog_sleeping[8].rooms = 3;
    apartment_catalog_sleeping[8].area = 68.0;
    apartment_catalog_sleeping[8].floor = 6;
    apartment_catalog_sleeping[8].building_year = 2017;
    apartment_catalog_sleeping[8].monthly_maintenance = 5900;
    apartment_catalog_sleeping[8].district = districts[1];
    
    apartment_catalog_sleeping[9].address = "ул. Новая, д. 4, кв. 82";
    apartment_catalog_sleeping[9].price = 7100000;
    apartment_catalog_sleeping[9].rooms = 2;
    apartment_catalog_sleeping[9].area = 52.0;
    apartment_catalog_sleeping[9].floor = 8;
    apartment_catalog_sleeping[9].building_year = 2016;
    apartment_catalog_sleeping[9].monthly_maintenance = 5200;
    apartment_catalog_sleeping[9].district = districts[1];
}

void fill_apartment_catalog_suburb() {
    std::string districts[3] = {"Центральный", "Спальный", "Пригород"};
    
    apartment_catalog_suburb[0].address = "ул. Загородная, д. 1, кв. 3";
    apartment_catalog_suburb[0].price = 3500000;
    apartment_catalog_suburb[0].rooms = 2;
    apartment_catalog_suburb[0].area = 54.0;
    apartment_catalog_suburb[0].floor = 2;
    apartment_catalog_suburb[0].building_year = 2013;
    apartment_catalog_suburb[0].monthly_maintenance = 3800;
    apartment_catalog_suburb[0].district = districts[2];
    
    apartment_catalog_suburb[1].address = "ул. Дачная, д. 7, кв. 12";
    apartment_catalog_suburb[1].price = 4200000;
    apartment_catalog_suburb[1].rooms = 3;
    apartment_catalog_suburb[1].area = 65.0;
    apartment_catalog_suburb[1].floor = 3;
    apartment_catalog_suburb[1].building_year = 2015;
    apartment_catalog_suburb[1].monthly_maintenance = 4200;
    apartment_catalog_suburb[1].district = districts[2];
    
    apartment_catalog_suburb[2].address = "ул. Полевая, д. 3, кв. 8";
    apartment_catalog_suburb[2].price = 2800000;
    apartment_catalog_suburb[2].rooms = 1;
    apartment_catalog_suburb[2].area = 38.0;
    apartment_catalog_suburb[2].floor = 1;
    apartment_catalog_suburb[2].building_year = 2011;
    apartment_catalog_suburb[2].monthly_maintenance = 2900;
    apartment_catalog_suburb[2].district = districts[2];
    
    apartment_catalog_suburb[3].address = "ул. Озерная, д. 5, кв. 21";
    apartment_catalog_suburb[3].price = 5800000;
    apartment_catalog_suburb[3].rooms = 4;
    apartment_catalog_suburb[3].area = 92.0;
    apartment_catalog_suburb[3].floor = 5;
    apartment_catalog_suburb[3].building_year = 2018;
    apartment_catalog_suburb[3].monthly_maintenance = 5800;
    apartment_catalog_suburb[3].district = districts[2];
    
    apartment_catalog_suburb[4].address = "ул. Речная, д. 12, кв. 34";
    apartment_catalog_suburb[4].price = 4600000;
    apartment_catalog_suburb[4].rooms = 3;
    apartment_catalog_suburb[4].area = 71.0;
    apartment_catalog_suburb[4].floor = 4;
    apartment_catalog_suburb[4].building_year = 2016;
    apartment_catalog_suburb[4].monthly_maintenance = 4500;
    apartment_catalog_suburb[4].district = districts[2];
    
    apartment_catalog_suburb[5].address = "ул. Береговая, д. 9, кв. 16";
    apartment_catalog_suburb[5].price = 3200000;
    apartment_catalog_suburb[5].rooms = 2;
    apartment_catalog_suburb[5].area = 48.0;
    apartment_catalog_suburb[5].floor = 2;
    apartment_catalog_suburb[5].building_year = 2012;
    apartment_catalog_suburb[5].monthly_maintenance = 3300;
    apartment_catalog_suburb[5].district = districts[2];
    
    apartment_catalog_suburb[6].address = "ул. Луговая, д. 15, кв. 42";
    apartment_catalog_suburb[6].price = 5200000;
    apartment_catalog_suburb[6].rooms = 3;
    apartment_catalog_suburb[6].area = 78.0;
    apartment_catalog_suburb[6].floor = 6;
    apartment_catalog_suburb[6].building_year = 2017;
    apartment_catalog_suburb[6].monthly_maintenance = 5100;
    apartment_catalog_suburb[6].district = districts[2];
    
    apartment_catalog_suburb[7].address = "ул. Садовая, д. 2, кв. 5";
    apartment_catalog_suburb[7].price = 1900000;
    apartment_catalog_suburb[7].rooms = 1;
    apartment_catalog_suburb[7].area = 31.0;
    apartment_catalog_suburb[7].floor = 1;
    apartment_catalog_suburb[7].building_year = 2008;
    apartment_catalog_suburb[7].monthly_maintenance = 2400;
    apartment_catalog_suburb[7].district = districts[2];
    
    apartment_catalog_suburb[8].address = "ул. Лесопарковая, д. 11, кв. 27";
    apartment_catalog_suburb[8].price = 3800000;
    apartment_catalog_suburb[8].rooms = 2;
    apartment_catalog_suburb[8].area = 56.0;
    apartment_catalog_suburb[8].floor = 3;
    apartment_catalog_suburb[8].building_year = 2014;
    apartment_catalog_suburb[8].monthly_maintenance = 3600;
    apartment_catalog_suburb[8].district = districts[2];
    
    apartment_catalog_suburb[9].address = "ул. Зеленая, д. 6, кв. 19";
    apartment_catalog_suburb[9].price = 6100000;
    apartment_catalog_suburb[9].rooms = 4;
    apartment_catalog_suburb[9].area = 95.0;
    apartment_catalog_suburb[9].floor = 7;
    apartment_catalog_suburb[9].building_year = 2019;
    apartment_catalog_suburb[9].monthly_maintenance = 6200;
    apartment_catalog_suburb[9].district = districts[2];
}

void next_month()
{
    ++month;
    if (month == 13)  {
        ++year;
        month = 1;
    }
}

User calc_salary(User user)
{
    if (month == 1)
    {
        user.salary = (int)(user.salary * (1 + salary_up));
    }
    return user;
}

User calc_trust_lvl(User user)
{
    user.trust_lvl = (int)(user.balance / 1000000 + user.salary / 100000);
    if (user.trust_lvl > 10)
    {
        user.trust_lvl = 10;
    }
    return user;
}

User calc_koef(User user)
{
    user.koeff = 1 + (double)user.trust_lvl / 50;
    return user;
}

User buy_car(User user) {
    //if (not user.car.exists) return;

    int purchase_year = 2027 + rand() % 8;
    int purchase_month = 1 + rand() % 11;
    if (user.has_car == 0 && user.balance >= 100000 && year == purchase_year && month == purchase_month ) {  // return
        int car_index = rand() % 10;
        
        user.balance -= 100000;
        
        int credit_term = 12 + rand() % 37;
        int credit_sum = car_catalog[car_index].price - 100000;
        RUB monthly_payment = credit_sum / credit_term;
        user.car.name = car_catalog[car_index].name;
        user.car.price = car_catalog[car_index].price;
        user.car.max_speed = car_catalog[car_index].max_speed;
        user.car.engine_power = car_catalog[car_index].engine_power;
        user.car.fuel_consumption = car_catalog[car_index].fuel_consumption;
        user.car.year_of_issue = car_catalog[car_index].year_of_issue;
        user.car.monthly_maintenance = car_catalog[car_index].monthly_maintenance;
        user.has_car = 1;
        user.car_credit_payment = monthly_payment;
        user.car_credit_months = credit_term;
        
        printf("        ОФОРМЛЕН КРЕДИТ: \n");
        printf("Кредит взят на машину %s \n", user.car.name.c_str());
        printf("Первый взнос: 100'000 rub.\n");
        printf("Кредит на %d мес.\n", credit_term);
        printf("Ежемесячный платеж: %d rub.\n", monthly_payment);
    }
    return user;
}

User buy_apartment(User user) {
    int purchase_year = 2027 + rand() % 8;
    int purchase_month = 1 + rand() % 11;
    
    if (user.has_apartment == 0 && user.balance >= 500000 && year == purchase_year && month == purchase_month) {
    
        int district_choice = rand() % 3;
        int apartment_index = rand() % 10;
        
        Apartment selected_apartment;
        
        if (district_choice == 0) {
            selected_apartment = apartment_catalog_center[apartment_index];
        } else if (district_choice == 1) {
            selected_apartment = apartment_catalog_sleeping[apartment_index];
        } else {
            selected_apartment = apartment_catalog_suburb[apartment_index];
        }
        
        int initial_payment = 500000;
        user.balance -= initial_payment;
        
        int credit_term = 60 + rand() % 181;
        int credit_sum = selected_apartment.price - initial_payment;
        RUB monthly_payment = credit_sum / credit_term;
        
        user.apartment = selected_apartment;
        user.has_apartment = 1;
        user.apartment_credit_payment = monthly_payment;
        user.apartment_credit_months = credit_term;
        user.apartment_initial_payment = initial_payment;
        
        printf("        ОФОРМЛЕНА ИПОТЕКА\n");
        printf("Квартира куплена в %s районе\n", selected_apartment.district.c_str());
        printf("Адрес: %s\n", selected_apartment.address.c_str());
        printf("Цена квартиры: %d rub.\n", selected_apartment.price);
        printf("Комнат: %d, площадь: %.1f кв.м\n", selected_apartment.rooms, selected_apartment.area);
        printf("Первый взнос: %d rub.\n", initial_payment);
        printf("Кредит на %d мес. (%.1f лет)\n", credit_term, credit_term/12.0);
        printf("Ежемесячный платеж по ипотеке: %d rub.\n", monthly_payment);
    }
    return user;
}

int calc_loose(User user){
    int base_loose = 75000;
    
    if (user.has_car == 1) {
        base_loose += user.car.monthly_maintenance;
    }
    
    if (user.has_apartment == 1) {
        base_loose += user.apartment.monthly_maintenance;
    }
    
    int loose = (int)(base_loose * (1 + (double)inflation / 100));
    
    if (user.car_credit_months > 0) {
        loose = loose + user.car_credit_payment;
    }
    
    if (user.apartment_credit_months > 0) {
        loose = loose + user.apartment_credit_payment;
    }
    
    return loose;
}

User calc_balance(User user)
{
    user.balance = user.balance + user.salary - calc_loose(user);
    
    if (month == 1)
    {
        user.balance = (int)(user.balance * user.koeff);
    }
    return user;
}

User credits(User user){
    if (user.car_credit_months > 0) 
    {
        user.car_credit_months = user.car_credit_months - 1;
    }
    
    if (user.apartment_credit_months > 0) 
    {
        user.apartment_credit_months = user.apartment_credit_months - 1;
    }
    
    return user;
}

void print_inf(User user){
    printf("        ИНФОРМАЦИЯ О ПОЛЬЗОВАТЕЛЕ \n");
    printf("Зарплата: %d rub.\n", user.salary);
    printf("Коэффициент: %.3lf\n", user.koeff);
    printf("Уровень доверия: %d\n", user.trust_lvl);
    printf("Капитал: %d rub.\n", user.balance);
    
    if (user.has_car == 1) {
        printf("         ИНФОРМАЦИЯ О МАШИНЕ  \n");
        printf("Модель: %s\n", user.car.name.c_str());
        printf("Цена: %d rub.\n", user.car.price);
        printf("Макс. скорость: %d км/ч\n", user.car.max_speed);
        printf("Мощность: %d л.c.\n", user.car.engine_power);
        printf("Расход топлива: %.1f л/100км\n", user.car.fuel_consumption);
        printf("Год выпуска: %d\n", user.car.year_of_issue);
        printf("         ИНФОРМАЦИЯ ПО КРЕДИТУ HA МАШИНУ \n");
        
        if (user.car_credit_months > 0) {
            printf("Осталось платежей: %d мес.\n", user.car_credit_months);
            printf("Ежемесячный платеж: %d rub.\n", user.car_credit_payment);
        } else {
            printf("Кредит на машину полностью выплачен\n");
        }
    }
    
    if (user.has_apartment == 1) {
        printf("        ИНФОРМАЦИЯ О КВАРТИРЕ \n");
        printf("Район: %s\n", user.apartment.district.c_str());
        printf("Адрес: %s\n", user.apartment.address.c_str());
        printf("Цена: %d rub.\n", user.apartment.price);
        printf("Комнат: %d\n", user.apartment.rooms);
        printf("Площадь: %.1f кв.м\n", user.apartment.area);
        printf("Этаж: %d\n", user.apartment.floor);
        printf("Год постройки: %d\n", user.apartment.building_year);
        printf("Коммунальные платежи: %d rub/мес\n", user.apartment.monthly_maintenance);
        printf("        ИНФОРМАЦИЯ ПО ИПОТЕКЕ  \n");
        
        if (user.apartment_credit_months > 0) {
            printf("Первоначальный взнос: %d rub.\n", user.apartment_initial_payment);
            printf("Осталось платежей: %d мес.\n", user.apartment_credit_months);
            printf("Ежемесячный платеж по ипотеке: %d rub.\n", user.apartment_credit_payment);
        } else {
            printf("Ипотека полностью выплачена\n");
        }
    }
}

User Ignat;

void ignat_innit(){
    Ignat.balance = 1000000;
    Ignat.salary = 150120;
    Ignat.koeff = 1;
    Ignat.trust_lvl = 2;
    Ignat.has_car = 0;
    Ignat.car_credit_payment = 0;
    Ignat.car_credit_months = 0;
    Ignat.has_apartment = 0;
    Ignat.apartment_credit_payment = 0;
    Ignat.apartment_credit_months = 0;
}

void ignat_simulation() {
    srand(time(NULL));
    ignat_innit();
    fill_car_catalog();
    fill_apartment_catalog_center();
    fill_apartment_catalog_sleeping();
    fill_apartment_catalog_suburb();
    
    while (year != 2035 || month != 6)
    {
        Ignat = calc_salary(Ignat);
        Ignat = calc_trust_lvl(Ignat);
        Ignat = calc_koef(Ignat);
        Ignat = buy_car(Ignat);
        Ignat = buy_apartment(Ignat);
        
        Ignat = calc_balance(Ignat);
        Ignat = credits(Ignat);
        next_month();
    }
}

int main()
{
    ignat_simulation();
    print_inf(Ignat);
    return 0;
}
