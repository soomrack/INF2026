#include <stdio.h>
#include <string>
#include <windows.h>


using RUB = long long int;
using USD = long long int;

using Percent = float;


struct Bank {
    RUB account;
    RUB deposite;
    Percent interest;

    USD account_usd;
    float rate_usd_rub;
    RUB credit_card;
    RUB investment;
};


struct Company {
    RUB income;
    RUB expenses;
    RUB capital;
    int employees;
    RUB marketing;
    RUB equipment;
    std::string company_name;
};


struct Cat {
    RUB food;
    RUB vet;
    RUB grooming;
    std::string name;
    RUB toys;
    RUB insurance;
};


struct Dog {
    RUB food;
    RUB vet;
    RUB grooming;
    RUB walking;
    RUB toys;
    RUB insurance;
    RUB training;
    std::string name;
};


struct Mortgage {
    RUB loan_amount;
    RUB monthly_payment;
    RUB debt;
    Percent rate;
    int years;
    int start_year;
    RUB overpayment;
};


struct Apartment {
    RUB property_value;
    RUB utilities;
    RUB repair;
    RUB furniture;
    RUB appliances;
    int square_meters;
    int rooms;
    std::string address;
};


struct Car {
    RUB gas;
    RUB value;
    RUB maintenance;
    RUB wash;
    RUB parking;
    RUB tuning;
    RUB insurance;
    RUB tires;
    RUB fine;
    RUB tax;

};


struct Vacation {
    RUB flights;
    RUB hotel;
    RUB food;
    RUB entertainment;
    RUB shopping;
    RUB transport;
    int days;
    std::string country;
};


struct Health {
    RUB gym;
    RUB doctor;
    RUB dentist;
    RUB pharmacy;
    RUB cosmetics;
};


struct GroceryItem {
    std::string name;
    RUB price;
    int quantity;
    RUB total;
};

struct MonthlyMenu {
    std::string month_name;
    std::string diet_type;          // тип диеты: "keto", "vegan", "sport", "balanced"
    GroceryItem items[12];
    int item_count;                  // фактическое количество продуктов
    RUB total_cost;                  // общая стоимость меню
};

struct Nutrition {
    MonthlyMenu current_menu;
    RUB monthly_budget;
    RUB protein_shakes;
    RUB vitamins;
    RUB sports_supplements;           // спортпит (BCAA, креатин и т.д.)
    RUB meal_delivery;
    RUB restaurant_visits;
};


struct Person {
    Bank vtb;
    Car car;
    Cat cat;
    Dog dog;
    Mortgage mortgage;
    Apartment apartment;
    Health health;
    RUB salary;
    RUB food;
    RUB clothes;
    RUB entertainment;
    RUB education;
    RUB gifts;
    RUB internet;
    RUB mobile;

};

struct PersonBob {
    Bank vtb;
    Company sport_nutrition;
    Cat cat;
    Dog dog;
    Car BMW;
    Health health;
    RUB salary;
    RUB food;
    RUB business_income;
    RUB total_business_income;
    RUB rental_income;
    RUB dividends;
    RUB luxury;
    Vacation vacation;
    Nutrition nutrition;
};


struct Person alice;
struct PersonBob bob;

float inflation_rate = 0.08;
float inflation_coef = 1.0;


void alice_init()
{
    alice.vtb.account = 0; // банк
    alice.vtb.deposite = 1'000'000;
    alice.vtb.interest = 14.5;
    alice.vtb.account_usd = 1'000;
    alice.vtb.rate_usd_rub = 78.5;
    alice.vtb.credit_card = 0;
    alice.vtb.investment = 200'000;

    alice.salary = 180'000; // зп

    alice.food = 20'000; // ежемесячные расходы
    alice.clothes = 10'000;
    alice.entertainment = 8'000;
    alice.education = 5'000; // англ курсы например
    alice.gifts = 3'000;
    alice.internet = 1'000;
    alice.mobile = 1'500;

    alice.car.value = 2'400'000;  // машинка
    alice.car.gas = 15'000;
    alice.car.maintenance = 8'000;
    alice.car.wash = 1'500;
    alice.car.parking = 4'000;
    alice.car.tuning = 0;
    alice.car.insurance = 25'000;
    alice.car.tires = 12'000;
    alice.car.tax = 10'000;  // транспортный налог
    alice.car.fine = 0;

    alice.cat.food = 2'500;  // котэ Снежок
    alice.cat.vet = 1'200;
    alice.cat.grooming = 2'000;
    alice.cat.toys = 500;
    alice.cat.insurance = 3'000;
    alice.cat.name = "Snowball";

    alice.dog.food = 3'500;  // собака Бадди
    alice.dog.vet = 1'500;
    alice.dog.grooming = 2'000;
    alice.dog.walking = 3'000;  // выгул
    alice.dog.toys = 700;
    alice.dog.insurance = 4'000;
    alice.dog.training = 2'000;  // дрессировка
    alice.dog.name = "Buddy";

    alice.apartment.property_value = 8500000;
    alice.apartment.utilities = 5000;
    alice.apartment.repair = 2000;
    alice.apartment.furniture = 300000;
    alice.apartment.appliances = 200000;
    alice.apartment.square_meters = 45;
    alice.apartment.rooms = 2;
    alice.apartment.address = "ул. Ленина, д. 10, кв. 5";


    alice.mortgage.loan_amount = 7'000'000;  //  ипотешн
    alice.mortgage.monthly_payment = 65'000;
    alice.mortgage.debt = 6'800'000;
    alice.mortgage.rate = 11.0;
    alice.mortgage.years = 15;
    alice.mortgage.start_year = 2025;
    alice.mortgage.overpayment = 0;

    alice.health.gym = 3'000;
    alice.health.doctor = 2'000;
    alice.health.dentist = 1'500;
    alice.health.pharmacy = 1'000;
    alice.health.cosmetics = 2'000;

}


void bob_init()
{
    bob.vtb.account = 5'000'000;  // банковские счета
    bob.vtb.deposite = 500'000;
    bob.vtb.interest = 16.0;
    bob.vtb.account_usd = 20'000;
    bob.vtb.rate_usd_rub = 78.5;
    bob.vtb.credit_card = 0;
    bob.vtb.investment = 1000000;


    bob.sport_nutrition.income = 2'000'000;  //  Компания спорт. питания
    bob.sport_nutrition.expenses = 600'000;
    bob.sport_nutrition.capital = 3'000'000;
    bob.sport_nutrition.employees = 6;
    bob.sport_nutrition.marketing = 200000;
    bob.sport_nutrition.equipment = 500000;
    bob.sport_nutrition.company_name = "ProteinPro";


    bob.cat.food = 3'000;  //  Кот Дарт Вейдер
    bob.cat.vet = 1'000;
    bob.cat.grooming = 10'000;
    bob.cat.toys = 1000;
    bob.cat.insurance = 5000;
    bob.cat.name = "Darth Vader";

    bob.dog.food = 5000; // собака Рекс
    bob.dog.vet = 2000;
    bob.dog.grooming = 3000;
    bob.dog.walking = 5000;
    bob.dog.toys = 1500;
    bob.dog.insurance = 6000;
    bob.dog.training = 3000;
    bob.dog.name = "Rex";

    bob.BMW.value = 8'000'000;  //  Машина
    bob.BMW.gas = 30'000;
    bob.BMW.maintenance = 25'000;
    bob.BMW.wash = 3'500;
    bob.BMW.parking = 10'000;
    bob.BMW.tuning = 150'000;
    bob.BMW.insurance = 120'000;
    bob.BMW.tires = 30'000;
    bob.BMW.tax = 25'000;
    bob.BMW.fine = 0;

    bob.salary = 800'000;  //  Личные финансы Боба
    bob.food = 50'000;
    bob.business_income = 800'000;
    bob.rental_income = 50000;
    bob.dividends = 20'000;
    bob.luxury = 100'000;

    bob.total_business_income = 0;

    bob.health.gym = 10'000;  // здоровье
    bob.health.doctor = 5'000;
    bob.health.dentist = 5'000;
    bob.health.pharmacy = 2'000;
    bob.health.cosmetics = 5'000;

    bob.vacation.flights = 200'000;  // отпуск
    bob.vacation.hotel = 300'000;
    bob.vacation.food = 100'000;
    bob.vacation.entertainment = 150'000;
    bob.vacation.shopping = 200'000;
    bob.vacation.transport = 50'000;
    bob.vacation.days = 14;
    bob.vacation.country = "Maldives";

    bob.nutrition.monthly_budget = 150'000;     // бюджет на еду
    bob.nutrition.protein_shakes = 15'000;
    bob.nutrition.vitamins = 8'000;
    bob.nutrition.sports_supplements = 12'000;
    bob.nutrition.meal_delivery = 25'000;
    bob.nutrition.restaurant_visits = 20'000;
}


void alice_salary(const int month, const int year)
{
    alice.vtb.account += alice.salary;  // обычная зарплата

    if (month == 12) {
        alice.vtb.account += alice.salary;  // 13th salary
    }

    if (month == 1 and year == 2027) {
        alice.salary *= 1.5;  // promotion
    }

    RUB dividends = alice.vtb.deposite * 1 / 100;  // 1% от депозита
    alice.vtb.account += dividends;

    if (month == 6 || month == 12) {
        RUB invest = 10'000;
        alice.vtb.investment += invest;
        alice.vtb.account -= invest;  // тратим на инвестиции
    }

    if (month == 12) {
        RUB profit = alice.vtb.investment * 10 / 100;
        alice.vtb.investment += profit;
        alice.vtb.account += profit;  // прибыль зачисляем на счет
    }
}


void alice_additional_income(int month, int year)
{
    if (month % 3 == 0) {  // фриланс
        alice.vtb.account += 15'000;
    }

    if (month == 4 && year == 2026) {  // продажа вещей
        alice.vtb.account += 10'000;
    }

    RUB cashback = alice.food * 1 / 100;  // кешбек
    alice.vtb.account += cashback;
}

void alice_mortgage_payment(int month, int year)
{
    if (alice.mortgage.debt <= 0) return;  // если долга нет, ничего не делаем

    alice.vtb.account -= alice.mortgage.monthly_payment;  // основной платеж

    // Расчет переплаты (проценты)
    RUB interest = alice.mortgage.debt * (alice.mortgage.rate / 12 / 100);
    alice.mortgage.overpayment += interest;

    // Уменьшение долга
    RUB principal = alice.mortgage.monthly_payment - interest;
    alice.mortgage.debt -= principal;

    if (alice.mortgage.debt < 0) {
        alice.mortgage.debt = 0;
    }
}


void alice_apartment(int month, int year)
{
    // Коммунальные платежи (каждый месяц)
    RUB utilities_cost = alice.apartment.utilities * inflation_coef;
    alice.vtb.account -= utilities_cost;

    // Ремонт (раз в 3 месяца)
    if (month % 3 == 0) {
        RUB repair_cost = alice.apartment.repair * inflation_coef;
        alice.vtb.account -= repair_cost;
    }

    // Обновление мебели/техники (раз в год)
    if (month == 12) {
        RUB home_items = 10000 * inflation_coef;
        alice.vtb.account -= home_items;
    }

    // Рост стоимости квартиры (раз в год)
    if (month == 12) {
        alice.apartment.property_value = alice.apartment.property_value * 105 / 100;
    }
}

void alice_health()
{
    RUB gym_cost = alice.health.gym * inflation_coef;
    RUB doctor_cost = alice.health.doctor * inflation_coef;
    RUB pharmacy_cost = alice.health.pharmacy * inflation_coef;

    alice.vtb.account -= gym_cost;
    alice.vtb.account -= doctor_cost;
    alice.vtb.account -= pharmacy_cost;
}

void alice_monthly_expenses()
{
    RUB food_cost = alice.food * inflation_coef;
    RUB clothes_cost = alice.clothes * inflation_coef;
    RUB entertainment_cost = alice.entertainment * inflation_coef;
    RUB education_cost = alice.education * inflation_coef;
    RUB gifts_cost = alice.gifts * inflation_coef;
    RUB internet_cost = alice.internet * inflation_coef;
    RUB mobile_cost = alice.mobile * inflation_coef;

    alice.vtb.account -= food_cost;
    alice.vtb.account -= clothes_cost;
    alice.vtb.account -= entertainment_cost;
    alice.vtb.account -= education_cost;
    alice.vtb.account -= gifts_cost;
    alice.vtb.account -= internet_cost;
    alice.vtb.account -= mobile_cost;
}

void alice_dog(int month, int year)
{
    RUB dog_food = alice.dog.food * inflation_coef;
    RUB dog_walking = alice.dog.walking * inflation_coef;
    RUB dog_toys = alice.dog.toys * inflation_coef;

    alice.vtb.account -= dog_food;
    alice.vtb.account -= dog_walking;
    alice.vtb.account -= dog_toys;

    if (month % 2 == 0) {
        RUB dog_vet = alice.dog.vet * inflation_coef;
        alice.vtb.account -= dog_vet;
    }

    if (month % 3 == 1) {
        RUB dog_grooming = alice.dog.grooming * inflation_coef;
        alice.vtb.account -= dog_grooming;
    }

    if (month == 3) {
        RUB dog_insurance = alice.dog.insurance * inflation_coef;
        alice.vtb.account -= dog_insurance;
    }

    if (month == 2 || month == 8) {
        RUB dog_training = alice.dog.training * inflation_coef;
        alice.vtb.account -= dog_training;
    }
}

void alice_seasonal_expenses(int month, int year)
{
    if (month == 12) {
        RUB gifts = 20'000 * inflation_coef;
        alice.vtb.account -= gifts;
    }

    if (month == 9) {
        RUB celebration = 15'000 * inflation_coef;
        alice.vtb.account -= celebration;
    }

    if (month == 7 && year == 2027) {
        RUB vacation = 80'000 * inflation_coef;
        alice.vtb.account -= vacation;
    }
}


void alice_investments(int month, int year)
{
    if (month == 6 || month == 12) {  // инвестиции
        RUB invest = 10'000;
        alice.vtb.investment += invest;
        alice.vtb.account -= invest;
    }

    if (month == 12) {  // Доход от инвестиций (раз в год)
        RUB profit = alice.vtb.investment * 10 / 100;
        alice.vtb.investment += profit;
    }
}


void bob_salary(const int month, const int year)
{
    bob.vtb.account += bob.salary;
    bob.vtb.account += bob.business_income;
    bob.vtb.account += bob.rental_income;
    bob.vtb.account += bob.dividends;

    if (month == 12) {
        bob.vtb.account += bob.business_income;  // бонус в декабре
    }

    if (month == 1 and year == 2027) {
        bob.salary = bob.salary * 110 / 100;
        bob.business_income = bob.business_income * 120 / 100;
        bob.rental_income = bob.rental_income * 110 / 100;
    }

    RUB dividends = bob.vtb.deposite * 1 / 100;  // 1% от депозита
    bob.vtb.account += dividends;

    if (month == 6 || month == 12) {
        RUB invest = 50000;
        bob.vtb.investment += invest;
        bob.vtb.account -= invest;  // тратим на инвестиции
    }

    if (month == 12) {
        RUB profit = bob.vtb.investment * 15 / 100;
        bob.vtb.investment += profit;
        bob.vtb.account += profit;  // прибыль зачисляем на счет
    }
}

void bob_business(int month, int year)
{
    // Считаем прибыль за месяц
    int profit = bob.sport_nutrition.income - bob.sport_nutrition.expenses - bob.sport_nutrition.marketing;

    if (profit > 0) {
        RUB bob_takes = profit * 70 / 100;

        bob.vtb.account += bob_takes;

        bob.total_business_income += bob_takes;

        bob.sport_nutrition.capital += profit * 30 / 100;
    }

    // События развития бизнеса
    if (month == 6 && year == 2026) {
        bob.sport_nutrition.income += 1'000'000;
        bob.sport_nutrition.equipment += 200'000;
        printf("  Боб: расширение бизнеса! Доход увеличен\n");
    }

    if (month == 9 && year == 2026) {
        bob.sport_nutrition.income += 1'000'000;
        bob.sport_nutrition.employees += 2;
        printf("  Боб: новые сотрудники, доход увеличен\n");
    }

    if (month == 3 && year == 2027) {
        bob.sport_nutrition.income += 1'000'000;
        printf("  Боб: крупный контракт! Доход +1 млн\n");
    }

    bob_bonus_from_company(month, year);
}


void bob_dog(int month, int year)
{
    RUB dog_food = bob.dog.food * inflation_coef;
    RUB dog_walking = bob.dog.walking * inflation_coef;
    RUB dog_toys = bob.dog.toys * inflation_coef;

    bob.vtb.account -= dog_food;
    bob.vtb.account -= dog_walking;
    bob.vtb.account -= dog_toys;

    if (month % 2 == 0) {
        RUB dog_vet = bob.dog.vet * inflation_coef;
        bob.vtb.account -= dog_vet;
    }

    if (month % 3 == 1) {
        RUB dog_grooming = bob.dog.grooming * inflation_coef;
        bob.vtb.account -= dog_grooming;
    }

    if (month == 4) {
        RUB dog_insurance = bob.dog.insurance * inflation_coef;
        RUB dog_training = bob.dog.training * inflation_coef;
        bob.vtb.account -= dog_insurance;
        bob.vtb.account -= dog_training;
    }
}


void bob_luxury_expenses(int month, int year)
{
    RUB luxury_cost = bob.luxury * inflation_coef;
    bob.vtb.account -= luxury_cost;

    if (month % 2 == 0) {
        RUB restaurant = 30'000 * inflation_coef;
        bob.vtb.account -= restaurant;
    }

    if (month == 8 && year == 2026) {
        RUB travel = 200'000 * inflation_coef;
        bob.vtb.account -= travel;
    }

    if (month >= 6 && month <= 8 && year == 2027) {
        RUB yacht = 150'000 * inflation_coef;
        bob.vtb.account -= yacht;
    }
}


void bob_health()
{
    RUB gym_cost = bob.health.gym * inflation_coef;
    RUB doctor_cost = bob.health.doctor * inflation_coef;
    RUB dentist_cost = bob.health.dentist * inflation_coef;
    RUB pharmacy_cost = bob.health.pharmacy * inflation_coef;
    RUB cosmetics_cost = bob.health.cosmetics * inflation_coef;

    bob.vtb.account -= gym_cost;
    bob.vtb.account -= doctor_cost;
    bob.vtb.account -= dentist_cost;
    bob.vtb.account -= pharmacy_cost;
    bob.vtb.account -= cosmetics_cost;
}


void bob_generate_monthly_menu(int month, int year)
{
    bob.nutrition.current_menu.item_count = 0;
    bob.nutrition.current_menu.total_cost = 0;

    // Определяем месяц и тип диеты
    switch (month) {
    case 1:
        bob.nutrition.current_menu.month_name = "Январь";
        bob.nutrition.current_menu.diet_type = "Зимнее укрепление иммунитета";

        // Продукты на январь
        bob.nutrition.current_menu.items[0] = { "Гречка", 120, 3, 120 * 3 };        // 3 кг
        bob.nutrition.current_menu.items[1] = { "Куриное филе", 450, 8, 450 * 8 };  // 8 кг
        bob.nutrition.current_menu.items[2] = { "Лосось", 1'200, 2, 1'200 * 2 };     // 2 кг
        bob.nutrition.current_menu.items[3] = { "Яйца (30шт)", 250, 4, 250 * 4 };     // 4 упаковки
        bob.nutrition.current_menu.items[4] = { "Творог 5%", 180, 6, 180 * 6 };       // 6 пачек
        bob.nutrition.current_menu.items[5] = { "Овощи замороженные", 150, 5, 150 * 5 };
        bob.nutrition.current_menu.items[6] = { "Фрукты сезонные", 200, 8, 200 * 8 };
        bob.nutrition.current_menu.items[7] = { "Орехи миндаль", 800, 1, 800 * 1 };   // 1 кг
        bob.nutrition.current_menu.items[8] = { "Мед", 600, 1, 600 * 1 };
        bob.nutrition.current_menu.items[9] = { "Имбирь/лимон", 300, 2, 300 * 2 };
        bob.nutrition.current_menu.item_count = 10;
        break;

    case 2:
        bob.nutrition.current_menu.month_name = "Февраль";
        bob.nutrition.current_menu.diet_type = "Подготовка к весне";

        bob.nutrition.current_menu.items[0] = { "Овсянка", 90, 4, 90 * 4 };
        bob.nutrition.current_menu.items[1] = { "Говядина", 700, 6, 700 * 6 };
        bob.nutrition.current_menu.items[2] = { "Индейка", 550, 5, 550 * 5 };
        bob.nutrition.current_menu.items[3] = { "Яйца", 250, 4, 250 * 4 };
        bob.nutrition.current_menu.items[4] = { "Сыр твердый", 800, 2, 800 * 2 };
        bob.nutrition.current_menu.items[5] = { "Капуста/морковь", 80, 6, 80 * 6 };
        bob.nutrition.current_menu.items[6] = { "Цитрусовые", 180, 5, 180 * 5 };
        bob.nutrition.current_menu.items[7] = { "Курага/чернослив", 500, 1, 500 * 1 };
        bob.nutrition.current_menu.items[8] = { "Грецкие орехи", 900, 1, 900 * 1 };
        bob.nutrition.current_menu.item_count = 9;
        break;

    case 3:
        bob.nutrition.current_menu.month_name = "Март";
        bob.nutrition.current_menu.diet_type = "Весенний детокс";

        bob.nutrition.current_menu.items[0] = { "Рис бурый", 130, 3, 130 * 3 };
        bob.nutrition.current_menu.items[1] = { "Кролик", 650, 4, 650 * 4 };
        bob.nutrition.current_menu.items[2] = { "Рыба белая", 500, 6, 500 * 6 };
        bob.nutrition.current_menu.items[3] = { "Тофу", 300, 3, 300 * 3 };
        bob.nutrition.current_menu.items[4] = { "Зелень (укроп/петрушка)", 50, 8, 50 * 8 };
        bob.nutrition.current_menu.items[5] = { "Огурцы/помидоры", 150, 6, 150 * 6 };
        bob.nutrition.current_menu.items[6] = { "Авокадо", 200, 8, 200 * 8 };
        bob.nutrition.current_menu.items[7] = { "Семена чиа", 600, 1, 600 * 1 };
        bob.nutrition.current_menu.items[8] = { "Проростки", 300, 2, 300 * 2 };
        bob.nutrition.current_menu.item_count = 9;
        break;

    case 4:
        bob.nutrition.current_menu.month_name = "Апрель";
        bob.nutrition.current_menu.diet_type = "Спортивное питание - набор массы";

        bob.nutrition.current_menu.items[0] = { "Макароны твердые сорта", 110, 5, 110 * 5 };
        bob.nutrition.current_menu.items[1] = { "Курица", 450, 10, 450 * 10 };
        bob.nutrition.current_menu.items[2] = { "Говядина", 700, 5, 700 * 5 };
        bob.nutrition.current_menu.items[3] = { "Тунец консервированный", 250, 8, 250 * 8 };
        bob.nutrition.current_menu.items[4] = { "Рис", 100, 4, 100 * 4 };
        bob.nutrition.current_menu.items[5] = { "Гречка", 120, 3, 120 * 3 };
        bob.nutrition.current_menu.items[6] = { "Молоко", 80, 10, 80 * 10 };
        bob.nutrition.current_menu.items[7] = { "Творог", 180, 8, 180 * 8 };
        bob.nutrition.current_menu.items[8] = { "Банан", 120, 10, 120 * 10 };
        bob.nutrition.current_menu.items[9] = { "Арахисовая паста", 500, 2, 500 * 2 };
        bob.nutrition.current_menu.item_count = 10;
        break;

    case 5:
        bob.nutrition.current_menu.month_name = "Май";
        bob.nutrition.current_menu.diet_type = "Сушка - рельеф";

        bob.nutrition.current_menu.items[0] = { "Грудка куриная", 450, 12, 450 * 12 };
        bob.nutrition.current_menu.items[1] = { "Кальмары", 600, 4, 600 * 4 };
        bob.nutrition.current_menu.items[2] = { "Креветки", 800, 3, 800 * 3 };
        bob.nutrition.current_menu.items[3] = { "Яичные белки", 200, 6, 200 * 6 };
        bob.nutrition.current_menu.items[4] = { "Огурцы", 80, 8, 80 * 8 };
        bob.nutrition.current_menu.items[5] = { "Помидоры", 120, 8, 120 * 8 };
        bob.nutrition.current_menu.items[6] = { "Перец болгарский", 150, 5, 150 * 5 };
        bob.nutrition.current_menu.items[7] = { "Спаржа", 400, 3, 400 * 3 };
        bob.nutrition.current_menu.items[8] = { "Грейпфрут", 130, 6, 130 * 6 };
        bob.nutrition.current_menu.item_count = 9;
        break;

    case 6:
        bob.nutrition.current_menu.month_name = "Июнь";
        bob.nutrition.current_menu.diet_type = "Летний легкий рацион";

        bob.nutrition.current_menu.items[0] = { "Овощи гриль", 200, 5, 200 * 5 };
        bob.nutrition.current_menu.items[1] = { "Рыба на пару", 550, 6, 550 * 6 };
        bob.nutrition.current_menu.items[2] = { "Салат листовой", 60, 8, 60 * 8 };
        bob.nutrition.current_menu.items[3] = { "Редис", 50, 4, 50 * 4 };
        bob.nutrition.current_menu.items[4] = { "Клубника", 300, 4, 300 * 4 };
        bob.nutrition.current_menu.items[5] = { "Черешня", 350, 3, 350 * 3 };
        bob.nutrition.current_menu.items[6] = { "Йогурт греческий", 150, 6, 150 * 6 };
        bob.nutrition.current_menu.items[7] = { "Мороженое протеиновое", 400, 2, 400 * 2 };
        bob.nutrition.current_menu.item_count = 8;
        break;

    case 7:
        bob.nutrition.current_menu.month_name = "Июль";
        bob.nutrition.current_menu.diet_type = "Отпускной режим (Мальдивы)";

        bob.nutrition.current_menu.items[0] = { "Фрукты тропические", 500, 5, 500 * 5 };
        bob.nutrition.current_menu.items[1] = { "Морепродукты", 1'200, 4, 1'200 * 4 };
        bob.nutrition.current_menu.items[2] = { "Кокосы", 150, 6, 150 * 6 };
        bob.nutrition.current_menu.items[3] = { "Рыба гриль", 700, 5, 700 * 5 };
        bob.nutrition.current_menu.items[4] = { "Смузи боул", 400, 8, 400 * 8 };
        bob.nutrition.current_menu.items[5] = { "Легкие салаты", 250, 6, 250 * 6 };
        bob.nutrition.current_menu.item_count = 6;
        break;

    default:
        // Для остальных месяцев - сбалансированный рацион
        bob.nutrition.current_menu.month_name = "Стандартный месяц";
        bob.nutrition.current_menu.diet_type = "Сбалансированное питание";

        bob.nutrition.current_menu.items[0] = { "Крупы разные", 500, 3, 500 * 3 };
        bob.nutrition.current_menu.items[1] = { "Мясо/рыба", 3'000, 4, 3'000 * 4 };
        bob.nutrition.current_menu.items[2] = { "Молочка", 1'500, 2, 1'500 * 2 };
        bob.nutrition.current_menu.items[3] = { "Овощи/фрукты", 2'000, 2, 2'000 * 2 };
        bob.nutrition.current_menu.items[4] = { "Здоровые снеки", 1'000, 1, 1'000 * 1 };
        bob.nutrition.current_menu.item_count = 5;
    }

    // Подсчитываем общую стоимость меню
    for (int i = 0; i < bob.nutrition.current_menu.item_count; i++) {
        bob.nutrition.current_menu.total_cost += bob.nutrition.current_menu.items[i].total;
    }
}


void bob_nutrition_expenses(int month, int year)
{
    bob_generate_monthly_menu(month, year);

    RUB menu_cost = bob.nutrition.current_menu.total_cost * inflation_coef;
    RUB protein_cost = bob.nutrition.protein_shakes * inflation_coef;
    RUB vitamins_cost = bob.nutrition.vitamins * inflation_coef;
    RUB sports_cost = bob.nutrition.sports_supplements * inflation_coef;

    bob.vtb.account -= menu_cost;
    bob.vtb.account -= protein_cost;
    bob.vtb.account -= vitamins_cost;
    bob.vtb.account -= sports_cost;

    if (month % 2 == 0) {
        RUB delivery_cost = bob.nutrition.meal_delivery * inflation_coef;
        bob.vtb.account -= delivery_cost;
    }

    if (month == 6 || month == 12) {
        RUB restaurant_cost = bob.nutrition.restaurant_visits * 2 * inflation_coef;
        bob.vtb.account -= restaurant_cost;
    }
    else {
        RUB restaurant_cost = bob.nutrition.restaurant_visits * inflation_coef;
        bob.vtb.account -= restaurant_cost;
    }
}


void bob_print_nutrition_info(int month, int year)
{
    printf("\n--- Питание Боба: %s %d ---\n",
        bob.nutrition.current_menu.month_name.c_str(), year);
    printf("  Диета: %s\n", bob.nutrition.current_menu.diet_type.c_str());
    printf("  Продуктовая корзина:\n");

    for (int i = 0; i < bob.nutrition.current_menu.item_count; i++) {
        printf("    - %s: %d шт x %lld = %lld руб\n",
            bob.nutrition.current_menu.items[i].name.c_str(),
            bob.nutrition.current_menu.items[i].quantity,
            bob.nutrition.current_menu.items[i].price,
            bob.nutrition.current_menu.items[i].total);
    }

    printf("  Итого продукты: %lld руб\n", bob.nutrition.current_menu.total_cost);
    printf("  Протеин: %lld руб\n", bob.nutrition.protein_shakes);
    printf("  Витамины: %lld руб\n", bob.nutrition.vitamins);
    printf("  Спортпит: %lld руб\n", bob.nutrition.sports_supplements);
    printf("  Доставка: %lld руб\n", bob.nutrition.meal_delivery);
    printf("  Рестораны: %lld руб\n", bob.nutrition.restaurant_visits);
    printf("  ВСЕГО НА ПИТАНИЕ: %lld руб\n",
        bob.nutrition.current_menu.total_cost +
        bob.nutrition.protein_shakes +
        bob.nutrition.vitamins +
        bob.nutrition.sports_supplements +
        bob.nutrition.meal_delivery +
        bob.nutrition.restaurant_visits);
}


void bob_vacation(int month, int year)
{
    if (month == 7 && year == 2027) {
        RUB flights = bob.vacation.flights * inflation_coef;
        RUB hotel = bob.vacation.hotel * inflation_coef;
        RUB food = bob.vacation.food * inflation_coef;
        RUB entertainment = bob.vacation.entertainment * inflation_coef;
        RUB shopping = bob.vacation.shopping * inflation_coef;
        RUB transport = bob.vacation.transport * inflation_coef;

        bob.vtb.account -= flights;
        bob.vtb.account -= hotel;
        bob.vtb.account -= food;
        bob.vtb.account -= entertainment;
        bob.vtb.account -= shopping;
        bob.vtb.account -= transport;
    }
}


void bob_investments(int month, int year)
{
    if (month == 6 || month == 12) {
        RUB invest = 50000;
        bob.vtb.investment += invest;
        bob.vtb.account -= invest;
    }

    if (month == 12) {
        RUB profit = bob.vtb.investment * 15 / 100;
        bob.vtb.investment += profit;
    }
}


void bob_bonus_from_company(int month, int year)
{
    // Если у компании хорошая прибыль - бонус Бобу
    int profit = bob.sport_nutrition.income - bob.sport_nutrition.expenses;
    if (profit > 400'000) {
        RUB bonus = profit * 10 / 100;  // 10% от прибыли
        bob.vtb.account += bonus;
    }
}


void bob_investment_dividends()
{
    RUB dividends = bob.vtb.deposite * 1 / 100;  // 1% от депозита
    bob.vtb.account += dividends;
}


void bob_cat()
{
    RUB cat_food = bob.cat.food * inflation_coef;
    RUB cat_grooming = bob.cat.grooming * inflation_coef;
    RUB cat_vet = bob.cat.vet * inflation_coef;
    RUB cat_toys = bob.cat.toys * inflation_coef;

    bob.vtb.account -= cat_food;
    bob.vtb.account -= cat_grooming;
    bob.vtb.account -= cat_vet;
    bob.vtb.account -= cat_toys;
}


void bob_car(int month, int year)
{
    // ===== ЕЖЕМЕСЯЧНЫЕ РАСХОДЫ =====
    RUB maintenance = bob.BMW.value * 5 / 1000 * inflation_coef;
    bob.vtb.account -= maintenance;

    RUB wash = 3'000 * inflation_coef;
    bob.vtb.account -= wash;

    RUB parking = 8'000 * inflation_coef;
    bob.vtb.account -= parking;

    RUB gas = 30'000 * inflation_coef;
    bob.vtb.account -= gas;

    printf("  Боб: ежемесячные расходы на BMW: ТО %lld, мойка %lld, парковка %lld\n",
        maintenance, wash, parking);

    // ===== СЕЗОННЫЕ РАСХОДЫ =====
    if (month == 8) {
        RUB tuning = 150'000 * inflation_coef;
        bob.vtb.account -= tuning;
        bob.BMW.value += 200'000;  // машина дорожает после тюнинга
        printf("  Боб: тюнинг BMW -%lld руб (стоимость авто +200000)\n", tuning);
    }

    if (month == 1) {
        RUB insurance = bob.BMW.value * 7 / 100 * inflation_coef;  // 7% от стоимости
        bob.vtb.account -= insurance;
        printf("  Боб: страховка BMW -%lld руб\n", insurance);
    }

    if (month == 10) {
        bob.vtb.account -= bob.BMW.tires * inflation_coef;
        printf("  Боб: замена шин для BMW -%lld руб\n", bob.BMW.tires);
    }

    if (month == 3) {
        bob.vtb.account -= bob.BMW.tax * inflation_coef;
        printf("  Боб: транспортный налог на BMW -%lld руб\n", bob.BMW.tax);
    }
}


// ============================================================
//         ГРУППЫ РАНДОМНЫХ СОБЫТИЙ ДЛЯ БОБА
// ============================================================

void bob_base_events(const int month,const int year)
{
    if (month == 4 && year == 2026) {
        bob.sport_nutrition.capital -= 500'000;
        RUB expense = 350'000 * inflation_coef;
        bob.vtb.account -= expense;
        printf("  БОБ: убыток из-за сломанного оборудования -%lld руб\n", expense);
    }

    if (month == 8 && year == 2026) {
        RUB expense = 15'000 * inflation_coef;
        bob.vtb.account -= expense;
        printf("  БОБ: прививки для кота -%lld руб\n", expense);
    }

    if (month == 11 && year == 2026) {
        bob.sport_nutrition.income += 500'000;
        printf("  БОБ: рост дохода бизнеса +500'000\n");
    }

    if (month == 2 && year == 2027) {
        RUB expense = 50'000 * inflation_coef;
        bob.vtb.account -= expense;
        printf("  БОБ: коту нужна операция -%lld руб\n", expense);
    }
}


void bob_investment_success(int month, int year)
{
    if (year == 2026) {
        if (month == 2) {
            RUB profit = 250'000 * inflation_coef;
            bob.vtb.account += profit;
            bob.total_business_income += profit;
            printf("  БОБ: удачные инвестиции в крипту +%lld руб\n", profit);
        }
        else if (month == 7) {
            RUB profit = 400'000 * inflation_coef;
            bob.vtb.account += profit;
            bob.total_business_income += profit;
            printf("  БОБ: акции выросли на %lld руб\n", profit);
        }
        else if (month == 11) {
            RUB profit = 600'000 * inflation_coef;
            bob.vtb.account += profit;
            bob.total_business_income += profit;
            printf("  БОБ: удачная сделка на бирже +%lld руб\n", profit);
        }
    }
    else if (year == 2027) {
        if (month == 4) {
            RUB profit = 350'000 * inflation_coef;
            bob.vtb.account += profit;
            bob.total_business_income += profit;
            printf("  БОБ: дивиденды от зарубежных акций +%lld руб\n", profit);
        }
        else if (month == 9) {
            RUB profit = 800'000 * inflation_coef;
            bob.vtb.account += profit;
            bob.total_business_income += profit;
            printf("  БОБ: IPO компании-стартапа +%lld руб\n", profit);
        }
    }
}


void bob_business_success(int month, int year)
{
    if (year == 2026) {
        if (month == 3) {
            bob.sport_nutrition.income += 500'000;
            printf("  БОБ: новый крупный клиент! Доход бизнеса увеличен\n");
        }
        else if (month == 8) {
            bob.sport_nutrition.income += 700'000;
            printf("  БОБ: заключил эксклюзивный контракт! Доход +700'000\n");
        }
        else if (month == 12) {
            bob.sport_nutrition.income += 1'000'000;
            bob.sport_nutrition.capital += 500'000;
            printf("  БОБ: открыл новый филиал! Доход +1 млн\n");
        }
    }
    else if (year == 2027) {
        if (month == 5) {
            bob.sport_nutrition.income += 800'000;
            bob.sport_nutrition.employees += 3;
            printf("  БОБ: выход на маркетплейсы! Доход +800'000\n");
        }
        else if (month == 10) {
            bob.sport_nutrition.income += 1'200'000;
            bob.sport_nutrition.equipment += 1'000'000;
            printf("  БОБ: запуск собственной линейки товаров! Доход +1.2 млн\n");
        }
    }
}


void bob_unexpected_income(int month, int year)
{
    if (year == 2026) {
        if (month == 1) {
            RUB income = 100'000 * inflation_coef;
            bob.vtb.account += income;
            bob.total_business_income += income;
            printf("  БОБ: возврат старого долга +%lld руб\n", income);
        }
        else if (month == 6) {
            RUB income = 50'000 * inflation_coef;
            bob.vtb.account += income;
            bob.total_business_income += income;
            printf("  БОБ: выигрыш в покер с друзьями +%lld руб\n", income);
        }
        else if (month == 10) {
            RUB income = 150'000 * inflation_coef;
            bob.vtb.account += income;
            bob.total_business_income += income;
            printf("  БОБ: продажа старого мотоцикла +%lld руб\n", income);
        }
    }
    else if (year == 2027) {
        if (month == 2) {
            RUB income = 75'000 * inflation_coef;
            bob.vtb.account += income;
            bob.total_business_income += income;
            printf("  БОБ: кэшбэк с премиальной карты +%lld руб\n", income);
        }
        else if (month == 7) {
            RUB income = 200'000 * inflation_coef;
            bob.vtb.account += income;
            bob.total_business_income += income;
            printf("  БОБ: наследство от дальнего родственника +%lld руб\n", income);
        }
    }
}


void bob_car_problems(int month, int year)
{
    if (month == 9 && year == 2026) {
        RUB expense = 120'000 * inflation_coef;
        bob.vtb.account -= expense;
        printf("  БОБ: замена дорогих запчастей в BMW -%lld руб\n", expense);
    }

    if (month == 6 && year == 2027) {
        RUB expense = 150'000 * inflation_coef;
        bob.vtb.account -= expense;
        bob.BMW.value -= 200'000;
        printf("  БОБ: серьезная поломка BMW - ремонт %lld руб\n", expense);
    }
}


void bob_property_problems(int month, int year)
{
    if (year == 2026) {
        if (month == 5) {
            RUB expense = 300'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: прорвало трубу в квартире - ремонт %lld руб\n", expense);
        }
        else if (month == 11) {
            RUB expense = 180'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: замена дорогой бытовой техники -%lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 3) {
            RUB expense = 90'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: ремонт кондиционера -%lld руб\n", expense);
        }
        else if (month == 8) {
            RUB expense = 220'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: затопили соседи - ремонт %lld руб\n", expense);
        }
    }
}


void bob_luxury_spontanious(int month, int year)
{
    if (year == 2026) {
        if (month == 2) {
            RUB expense = 150'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: спонтанная покупка дорогих часов -%lld руб\n", expense);
        }
        else if (month == 7) {
            RUB expense = 200'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: вип-билеты на концерт -%lld руб\n", expense);
        }
        else if (month == 12) {
            RUB expense = 5'000'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: новогодний отдых в Швейцарии -%lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 3) {
            RUB expense = 12'000'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: дизайнерская одежда -%lld руб\n", expense);
        }
        else if (month == 9) {
            RUB expense = 180'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: ресторан с мишленовским шеф-поваром -%lld руб\n", expense);
        }
    }
}


void bob_health_elite(int month, int year)
{
    if (year == 2026) {
        if (month == 1) {
            RUB expense = 85'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: чекап в платной клинике -%lld руб\n", expense);
        }
        else if (month == 6) {
            RUB expense = 60'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: стоматолог-имплантолог -%lld руб\n", expense);
        }
        else if (month == 10) {
            RUB expense = 45'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: массаж и спа -%lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 4) {
            RUB expense = 95'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: лазерная коррекция зрения -%lld руб\n", expense);
        }
    }
}


void bob_pets_elite(int month, int year)
{
    if (year == 2026) {
        if (month == 3) {
            RUB expense = 25'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: груминг салон для кота -%lld руб\n", expense);
        }
        else if (month == 8) {
            RUB expense = 30'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: собачий психолог -%lld руб\n", expense);
        }
        else if (month == 12) {
            RUB expense = 40'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: отель для животных на праздники -%lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 5) {
            RUB expense = 20'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: элитный корм для питомцев -%lld руб\n", expense);
        }
    }
}


void bob_business_problems(int month, int year)
{
    if (year == 2026) {
        if (month == 1) {
            bob.sport_nutrition.capital -= 200'000;
            RUB expense = 100'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: проблемы с поставщиками -%lld руб\n", expense);
        }
        else if (month == 7) {
            bob.sport_nutrition.income -= 300'000;
            printf("  БОБ: сезонный спад продаж - доход бизнеса снижен\n");
        }
    }
    else if (year == 2027) {
        if (month == 2) {
            bob.sport_nutrition.capital -= 400'000;
            RUB expense = 150'000 * inflation_coef;
            bob.vtb.account -= expense;
            printf("  БОБ: налоговая проверка - штраф %lld руб\n", expense);
        }
        else if (month == 8) {
            bob.sport_nutrition.income -= 200'000;
            bob.sport_nutrition.employees -= 1;
            printf("  БОБ: уход ключевого сотрудника\n");
        }
    }
}


void bob_misc_events(int month, int year)
{
    if (month == 5 && year == 2026) {
        bob.BMW.value += 100'000;
        printf("  БОБ: BMW стала раритетной! +100'000 к стоимости\n");
    }

    if (month == 9 && year == 2026) {
        bob.vacation.country = "Таиланд";
        printf("  БОБ: спонтанно решил лететь в Таиланд в следующем месяце\n");
    }

    if (month == 1 && year == 2027) {
        bob.nutrition.current_menu.diet_type = "Кето-диета";
        printf("  БОБ: перешел на кето-диету\n");
    }

    if (month == 4 && year == 2027) {
        bob.luxury += 50'000;  
        printf("  БОБ: увеличил бюджет на люкс до %lld\n", bob.luxury);
    }

    if (month == 11 && year == 2027) {
        printf("  БОБ: планирует купить яхту в следующем году \n");
    }
}

// ============================================================
//         ГЛАВНАЯ ФУНКЦИЯ РАНДОМНЫХ СОБЫТИЙ БОБА
// ============================================================

void bob_random_events(int month, int year)
{
    bob_base_events(month, year);
    bob_investment_success(month, year);
    bob_business_success(month, year);
    bob_unexpected_income(month, year);
    bob_car_problems(month, year);
    bob_property_problems(month, year);
    bob_luxury_spontanious(month, year);
    bob_health_elite(month, year);
    bob_pets_elite(month, year);
    bob_business_problems(month, year);
    bob_misc_events(month, year);
}

void bob_deposite(const int month, const int year)
{
    if (year == 2026) bob.vtb.interest = 11.0;
    if (year == 2027) bob.vtb.interest = 10.0;
    if (year == 2028) bob.vtb.interest = 9.0;
    if (year == 2029) bob.vtb.interest = 8.0;

    bob.vtb.deposite += bob.vtb.deposite * (bob.vtb.interest / 12.0 / 100.0);

    bob.vtb.deposite += bob.vtb.account;
    bob.vtb.account = 0;
}


void alice_food()
{
    RUB food_cost = alice.food * inflation_coef;
    alice.vtb.account -= food_cost;
}

void alice_car(int month, int year)
{
    // Ежемесячные расходы
    RUB maintenance_cost = alice.car.maintenance * inflation_coef;
    RUB wash_cost = alice.car.wash * inflation_coef;
    RUB parking_cost = alice.car.parking * inflation_coef;
    RUB gas_cost = alice.car.gas * inflation_coef;

    alice.vtb.account -= maintenance_cost;
    alice.vtb.account -= wash_cost;
    alice.vtb.account -= parking_cost;
    alice.vtb.account -= gas_cost;

    // Сезонные расходы
    if (month == 11) {
        RUB tires_cost = alice.car.tires * inflation_coef;
        alice.vtb.account -= tires_cost;
    }

    if (month == 1) {
        RUB insurance_cost = alice.car.insurance * inflation_coef;
        alice.vtb.account -= insurance_cost;
    }

    if (month == 8) {
        RUB tax_cost = alice.car.tax * inflation_coef;
        alice.vtb.account -= tax_cost;
    }
}

void alice_cat()
{
    RUB cat_food = alice.cat.food * inflation_coef;
    RUB cat_vet = alice.cat.vet * inflation_coef;
    RUB cat_grooming = alice.cat.grooming * inflation_coef;
    RUB cat_toys = alice.cat.toys * inflation_coef;

    alice.vtb.account -= cat_food;
    alice.vtb.account -= cat_vet;
    alice.vtb.account -= cat_grooming;
    alice.vtb.account -= cat_toys;
}

void alice_car_fine()
{
    RUB fine = 2'500 * inflation_coef;
    alice.vtb.account -= fine;
}



void alice_deposite(const int month, const int year)
{
    if (year == 2026) alice.vtb.interest = 14.5;
    if (year == 2027) alice.vtb.interest = 13.5;
    if (year == 2028) alice.vtb.interest = 12.5;
    if (year == 2029) alice.vtb.interest = 11.5;

    alice.vtb.deposite += alice.vtb.deposite * (alice.vtb.interest / 12.0 / 100.0);

    alice.vtb.deposite += alice.vtb.account;
    alice.vtb.account = 0;
}


// ============================================================
//         ГРУППЫ РАНДОМНЫХ СОБЫТИЙ ДЛЯ АЛИСЫ
// ============================================================

void alice_work_bonuses(int month, int year)
{
    if (year == 2026) {
        if (month == 2) {
            RUB bonus = 8'000 * inflation_coef;
            alice.vtb.account += bonus;
            printf("  Алиса: получила небольшую премию на работе +%lld руб\n", bonus);
        }
        else if (month == 5) {
            RUB bonus = 5'000 * inflation_coef;
            alice.vtb.account += bonus;
            printf("  Алиса: выплатили больничный +%lld руб\n", bonus);
        }
        else if (month == 9) {
            RUB bonus = 12'000 * inflation_coef;
            alice.vtb.account += bonus;
            printf("  Алиса: квартальная премия +%lld руб\n", bonus);
        }
        else if (month == 12) {
            RUB bonus = 15'000 * inflation_coef;
            alice.vtb.account += bonus;
            printf("  Алиса: новогодний бонус +%lld руб\n", bonus);
        }
    }
    else if (year == 2027) {
        if (month == 3) {
            RUB bonus = 10'000 * inflation_coef;
            alice.vtb.account += bonus;
            printf("  Алиса: премия за успешный проект +%lld руб\n", bonus);
        }
        else if (month == 8) {
            RUB bonus = 7'000 * inflation_coef;
            alice.vtb.account += bonus;
            printf("  Алиса: компенсация за неиспользованный отпуск +%lld руб\n", bonus);
        }
    }
}


void alice_refunds(int month, int year)
{
    if (year == 2026) {
        if (month == 4) {
            RUB refund = 3'200 * inflation_coef;
            alice.vtb.account += refund;
            printf("  Алиса: налоговый вычет за лечение зубов +%lld руб\n", refund);
        }
        else if (month == 7) {
            RUB refund = 1'800 * inflation_coef;
            alice.vtb.account += refund;
            printf("  Алиса: кэшбэк по кредитной карте за полгода +%lld руб\n", refund);
        }
        else if (month == 10) {
            RUB refund = 2'500 * inflation_coef;
            alice.vtb.account += refund;
            printf("  Алиса: вернули переплату за коммунальные услуги +%lld руб\n", refund);
        }
    }
    else if (year == 2027) {
        if (month == 1) {
            RUB refund = 4'200 * inflation_coef;
            alice.vtb.account += refund;
            printf("  Алиса: возврат 13% за обучение +%lld руб\n", refund);
        }
        else if (month == 6) {
            RUB refund = 1'200 * inflation_coef;
            alice.vtb.account += refund;
            printf("  Алиса: кэшбэк с супермаркетов за полгода +%lld руб\n", refund);
        }
    }
}


void alice_sales(int month, int year)
{
    if (year == 2026) {
        if (month == 3) {
            RUB sale = 3'500 * inflation_coef;
            alice.vtb.account += sale;
            printf("  Алиса: продала старый телефон на авито +%lld руб\n", sale);
        }
        else if (month == 8) {
            RUB sale = 2'000 * inflation_coef;
            alice.vtb.account += sale;
            printf("  Алиса: продала ненужную сумку +%lld руб\n", sale);
        }
        else if (month == 11) {
            RUB sale = 4'000 * inflation_coef;
            alice.vtb.account += sale;
            printf("  Алиса: продала зимнюю куртку, которая мала +%lld руб\n", sale);
        }
    }
    else if (year == 2027) {
        if (month == 4) {
            RUB sale = 2'800 * inflation_coef;
            alice.vtb.account += sale;
            printf("  Алиса: продала старые книги и диски +%lld руб\n", sale);
        }
        else if (month == 9) {
            RUB sale = 3'200 * inflation_coef;
            alice.vtb.account += sale;
            printf("  Алиса: продала детские вещи (остались от племянников) +%lld руб\n", sale);
        }
    }
}


void alice_gifts_from_family(int month, int year)
{
    if (year == 2026) {
        if (month == 2) {
            RUB gift = 3'000 * inflation_coef;
            alice.vtb.account += gift;
            printf("  Алиса: подарок от мамы на день рождения +%lld руб\n", gift);
        }
        else if (month == 5) {
            RUB gift = 1'500 * inflation_coef;
            alice.vtb.account += gift;
            printf("  Алиса: бабушка прислала денег на лекарства +%lld руб\n", gift);
        }
        else if (month == 9) {
            RUB gift = 2'000 * inflation_coef;
            alice.vtb.account += gift;
            printf("  Алиса: подарок от крестной +%lld руб\n", gift);
        }
    }
    else if (year == 2027) {
        if (month == 1) {
            RUB gift = 5'000 * inflation_coef;
            alice.vtb.account += gift;
            printf("  Алиса: родственники подарили на Новый год +%lld руб\n", gift);
        }
        else if (month == 8) {
            RUB gift = 1'000 * inflation_coef;
            alice.vtb.account += gift;
            printf("  Алиса: брат вернул старый долг +%lld руб\n", gift);
        }
    }
}


void alice_lucky_events(int month, int year)
{
    if (year == 2026) {
        if (month == 6) {
            RUB lucky = 500 * inflation_coef;
            alice.vtb.account += lucky;
            printf("  Алиса: нашла %lld руб на улице\n", lucky);
        }
        else if (month == 10) {
            RUB lucky = 700 * inflation_coef;
            alice.vtb.account += lucky;
            printf("  Алиса: выиграла %lld руб в лотерейном билете\n", lucky);
        }
        else if (month == 12) {
            RUB lucky = 1'000 * inflation_coef;
            alice.vtb.account += lucky;
            printf("  Алиса: выиграла в розыгрыш в инстаграме +%lld руб\n", lucky);
        }
    }
}


void alice_health_expenses_random(int month, int year)
{
    if (year == 2026) {
        if (month == 1) {
            RUB expense = 2'200 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: заболела гриппом - лекарства %lld руб\n", expense);
        }
        else if (month == 4) {
            RUB expense = 3'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: поход к стоматологу - пломба %lld руб\n", expense);
        }
        else if (month == 7) {
            RUB expense = 1'800 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: аллергия весной - антигистаминные %lld руб\n", expense);
        }
        else if (month == 11) {
            RUB expense = 4'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: удаление зуба мудрости -%lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 2) {
            RUB expense = 2'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: физиотерапия для спины -%lld руб\n", expense);
        }
        else if (month == 6) {
            RUB expense = 1'200 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: витамины и БАДы -%lld руб\n", expense);
        }
        else if (month == 10) {
            RUB expense = 3'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: плановый чекап у гинеколога -%lld руб\n", expense);
        }
    }
}


void alice_tech_problems(int month, int year)
{
    if (year == 2026) {
        if (month == 2) {
            RUB expense = 2'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: сломался утюг - купила новый %lld руб\n", expense);
        }
        else if (month == 5) {
            RUB expense = 4'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: разбился телефон - ремонт экрана %lld руб\n", expense);
        }
        else if (month == 8) {
            RUB expense = 3'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: сгорела зарядка для ноутбука - новая %lld руб\n", expense);
        }
        else if (month == 12) {
            RUB expense = 2'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: сломались наушники - новые %lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 3) {
            RUB expense = 6'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: сломался пылесос - купила новый %lld руб\n", expense);
        }
        else if (month == 7) {
            RUB expense = 1'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: перестал работать фен - новый %lld руб\n", expense);
        }
        else if (month == 11) {
            RUB expense = 3'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: сломался чайник - новый %lld руб\n", expense);
        }
    }
}


void alice_clothing_problems(int month, int year)
{
    if (year == 2026) {
        if (month == 1) {
            RUB expense = 3'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: порвались зимние сапоги - новые %lld руб\n", expense);
        }
        else if (month == 4) {
            RUB expense = 2'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила демисезонные ботинки %lld руб\n", expense);
        }
        else if (month == 6) {
            RUB expense = 2'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: порвалась любимая юбка - новая %lld руб\n", expense);
        }
        else if (month == 9) {
            RUB expense = 3'200 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила осеннюю куртку %lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 3) {
            RUB expense = 2'800 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: новые джинсы %lld руб\n", expense);
        }
        else if (month == 8) {
            RUB expense = 4'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила кроссовки на распродаже %lld руб\n", expense);
        }
    }
}


void alice_pet_problems(int month, int year)
{
    if (year == 2026) {
        if (month == 2) {
            RUB expense = 1'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: кот разбил вазу - новая %lld руб\n", expense);
        }
        else if (month == 6) {
            RUB expense = 2'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: собака погрызла тапки - новые %lld руб\n", expense);
        }
        else if (month == 9) {
            RUB expense = 1'800 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: кот поранил лапу - ветклиника %lld руб\n", expense);
        }
        else if (month == 12) {
            RUB expense = 2'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: прививки для кота и собаки %lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 4) {
            RUB expense = 3'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: собака съела что-то на улице - лечение %lld руб\n", expense);
        }
        else if (month == 10) {
            RUB expense = 1'200 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: кот порвал диван - ремонт обивки %lld руб\n", expense);
        }
    }
}


void alice_house_problems(int month, int year)
{
    if (year == 2026) {
        if (month == 3) {
            RUB expense = 2'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: потеряла ключи - вызов мастера %lld руб\n", expense);
        }
        else if (month == 7) {
            RUB expense = 1'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: прорвало стиральную машину - ремонт %lld руб\n", expense);
        }
        else if (month == 10) {
            RUB expense = 2'200 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: замена замка в двери %lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 2) {
            RUB expense = 1'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: разбила чашку - новая %lld руб\n", expense);
        }
        else if (month == 5) {
            RUB expense = 3'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: засор в трубах - вызов сантехника %lld руб\n", expense);
        }
        else if (month == 9) {
            RUB expense = 800 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: перегорели лампочки в квартире - новые %lld руб\n", expense);
        }
    }
}


void alice_fines(int month, int year)
{
    if (year == 2026) {
        if (month == 1) {
            RUB fine = 500 * inflation_coef;
            alice.vtb.account -= fine;
            printf("  Алиса: штраф за просрочку библиотечной книги %lld руб\n", fine);
        }
        else if (month == 5) {
            RUB fine = 1'000 * inflation_coef;
            alice.vtb.account -= fine;
            printf("  Алиса: забыла оплатить интернет - пеня %lld руб\n", fine);
        }
        else if (month == 8) {
            RUB fine = 2'000 * inflation_coef;
            alice.vtb.account -= fine;
            printf("  Алиса: штраф за неправильную парковку %lld руб\n", fine);
        }
        else if (month == 11) {
            RUB fine = 800 * inflation_coef;
            alice.vtb.account -= fine;
            printf("  Алиса: потеряла читательский билет - восстановление %lld руб\n", fine);
        }
    }
    else if (year == 2027) {
        if (month == 3) {
            RUB fine = 1'200 * inflation_coef;
            alice.vtb.account -= fine;
            printf("  Алиса: просрочила возврат товара в интернет-магазине %lld руб\n", fine);
        }
        else if (month == 7) {
            RUB fine = 1'500 * inflation_coef;
            alice.vtb.account -= fine;
            printf("  Алиса: штраф за превышение скорости %lld руб\n", fine);
        }
    }
}


void alice_social_expenses(int month, int year)
{
    if (year == 2026) {
        if (month == 2) {
            RUB expense = 2'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: подарок подруге на день рождения %lld руб\n", expense);
        }
        else if (month == 6) {
            RUB expense = 3'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: свадьба подруги - подарок и платье %lld руб\n", expense);
        }
        else if (month == 8) {
            RUB expense = 1'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: поездка на дачу к друзьям %lld руб\n", expense);
        }
        else if (month == 11) {
            RUB expense = 2'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: день рождения коллеги - скинулись на подарок %lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 3) {
            RUB expense = 2'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: девичник - ресторан %lld руб\n", expense);
        }
        else if (month == 9) {
            RUB expense = 4'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: поход на концерт любимой группы %lld руб\n", expense);
        }
        else if (month == 12) {
            RUB expense = 5'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: новогодний корпоратив - наряд и такси %lld руб\n", expense);
        }
    }
}


void alice_furniture_and_repair(int month, int year)
{
    if (year == 2026) {
        if (month == 4) {
            RUB expense = 3'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила новые шторы %lld руб\n", expense);
        }
        else if (month == 9) {
            RUB expense = 4'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила тумбочку в прихожую %lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 1) {
            RUB expense = 2'800 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила постельное белье %lld руб\n", expense);
        }
        else if (month == 6) {
            RUB expense = 5'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: покрасила стены в комнате %lld руб\n", expense);
        }
        else if (month == 11) {
            RUB expense = 8'000 * inflation_coef;
            alice.apartment.furniture += expense;
            alice.vtb.account -= expense;
            printf("  Алиса: купила новый диван %lld руб\n", expense);
        }
    }
}


void alice_beauty(int month, int year)
{
    if (year == 2026) {
        if (month == 3) {
            RUB expense = 1'800 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила косметику %lld руб\n", expense);
        }
        else if (month == 7) {
            RUB expense = 1'200 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: поход в парикмахерскую %lld руб\n", expense);
        }
        else if (month == 10) {
            RUB expense = 2'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила зимний крем и гигиенические принадлежности %lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 4) {
            RUB expense = 1'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: маникюр %lld руб\n", expense);
        }
        else if (month == 8) {
            RUB expense = 2'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила духи %lld руб\n", expense);
        }
    }
}


void alice_small_joys(int month, int year)
{
    if (year == 2026) {
        if (month == 2) {
            RUB expense = 800 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила книгу %lld руб\n", expense);
        }
        else if (month == 5) {
            RUB expense = 1'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: сходила в кино с подругой %lld руб\n", expense);
        }
        else if (month == 9) {
            RUB expense = 1'200 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила билеты в театр %lld руб\n", expense);
        }
        else if (month == 12) {
            RUB expense = 2'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: новогодние украшения для дома %lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 2) {
            RUB expense = 600 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила цветы для мамы %lld руб\n", expense);
        }
        else if (month == 6) {
            RUB expense = 1'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила мороженое и вкусняшки %lld руб\n", expense);
        }
        else if (month == 10) {
            RUB expense = 900 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила новый чехол для телефона %lld руб\n", expense);
        }
    }
}


void alice_education(int month, int year)
{
    if (year == 2026) {
        if (month == 1) {
            RUB expense = 1'000 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила книги по саморазвитию %lld руб\n", expense);
        }
        else if (month == 8) {
            RUB expense = 2'500 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: записалась на онлайн-курс %lld руб\n", expense);
        }
    }
    else if (year == 2027) {
        if (month == 2) {
            RUB expense = 1'800 * inflation_coef;
            alice.vtb.account -= expense;
            printf("  Алиса: купила учебник по английскому %lld руб\n", expense);
        }
    }
}

// ============================================================
//         ГЛАВНАЯ ФУНКЦИЯ РАНДОМНЫХ СОБЫТИЙ
// ============================================================

void alice_random_events(const int month,const int year)
{
    alice_work_bonuses(month, year);
    alice_refunds(month, year);
    alice_sales(month, year);
    alice_gifts_from_family(month, year);
    alice_lucky_events(month, year);
    alice_health_expenses_random(month, year);
    alice_tech_problems(month, year);
    alice_clothing_problems(month, year);
    alice_pet_problems(month, year);
    alice_house_problems(month, year);
    alice_fines(month, year);
    alice_social_expenses(month, year);
    alice_furniture_and_repair(month, year);
    alice_beauty(month, year);
    alice_small_joys(month, year);
    alice_education(month, year);
}



void alice_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        alice.vtb.account_usd += 3'000;
    }
}


void apply_inflation(int year)
{
    inflation_coef *= (1.0 + inflation_rate);

    printf("\n========== НОВЫЙ %d ГОД ==========\n", year);
    printf("Цены выросли в %.2f раза\n", inflation_coef);
}


void print_results()
{
    printf("\n");
    printf("=================================================================\n");
    printf("                    ФИНАЛЬНЫЙ ОТЧЕТ (Март 2028)                  \n");
    printf("=================================================================\n\n");

    // Расчет капитала Алисы 
    RUB alice_capital = 0;
    alice_capital += alice.vtb.account;
    alice_capital += alice.car.value;
    alice_capital += alice.vtb.investment;
    alice_capital += alice.vtb.deposite;
    alice_capital += (RUB)(alice.vtb.account_usd * alice.vtb.rate_usd_rub);
    alice_capital += alice.apartment.property_value;

    // Расчет капитала Боба
    RUB bob_capital = 0;
    bob_capital += bob.vtb.account;
    bob_capital += bob.BMW.value;
    bob_capital += bob.vtb.investment;
    bob_capital += bob.vtb.deposite;
    bob_capital += (RUB)(bob.vtb.account_usd * bob.vtb.rate_usd_rub);
    bob_capital += bob.sport_nutrition.capital;

    // ТАБЛИЦА 
    printf("+-------------------------+------------------+------------------+\n");
    printf("| Показатель              | Алиса            | Боб              |\n");
    printf("+-------------------------+------------------+------------------+\n");
    printf("| Зарплата                | %16lld | %16lld |\n", alice.salary, bob.salary);
    printf("+-------------------------+------------------+------------------+\n");

    // Дополнительные доходы Боба 
    if (bob.total_business_income > 0) {
        printf("| Доход от бизнеса        | %16s | %16lld |\n", "-", bob.total_business_income);
        printf("+-------------------------+------------------+------------------+\n");
    }

    printf("| КАПИТАЛ                 | %16lld | %16lld |\n", alice_capital, bob_capital);
    printf("+-------------------------+------------------+------------------+\n\n");

    // Детали капитала 
    printf("Детали капитала:\n");
    printf("  Алиса: счет=%lld, авто=%lld, депозит=%lld, инвестиции=%lld, квартира=%lld, валюта=%lld\n",
        alice.vtb.account, alice.car.value, alice.vtb.deposite,
        alice.vtb.investment, alice.apartment.property_value,
        (RUB)(alice.vtb.account_usd * alice.vtb.rate_usd_rub));

    printf("  Боб:   счет=%lld, BMW=%lld, депозит=%lld, инвестиции=%lld, бизнес=%lld, валюта=%lld\n",
        bob.vtb.account, bob.BMW.value, bob.vtb.deposite,
        bob.vtb.investment, bob.sport_nutrition.capital,
        (RUB)(bob.vtb.account_usd * bob.vtb.rate_usd_rub));

    printf("  Боб:   ВСЕГО ДОХОД ОТ БИЗНЕСА за 2 года: %lld руб\n", bob.total_business_income);


    // Долги Алисы
    if (alice.mortgage.debt > 0) {
        printf("\n  Долг Алисы по ипотеке: %lld руб\n", alice.mortgage.debt);
        printf("  Чистый капитал Алисы (активы - долги): %lld руб\n",
            alice_capital - alice.mortgage.debt);
    }

    // Питомцы для настроения
    printf("\n Питомцы: %s (кот) и %s (собака) | %s (кот) и %s (собака)\n",
        alice.cat.name.c_str(), alice.dog.name.c_str(),
        bob.cat.name.c_str(), bob.dog.name.c_str());

    printf("=================================================================\n");

}





void simulation()
{
    int month = 2;
    int year = 2026;

    while (!(month == 3 and year == 2028)) {

        printf("\n----- %d.%d -----\n", month, year);
        alice_salary(month, year);
        alice_freelance(month, year);
        alice_additional_income(month, year);  // доходы от второстепенных продаж (проадажа вещей и т.д.)

        alice_monthly_expenses();  // месячные траты (еда,одежда и т.д.)
        alice_health();
        alice_random_events(month, year);

        alice_cat();
        alice_dog(month, year);

        alice_mortgage_payment(month, year);  // ипотека
        alice_apartment(month, year);

        alice_seasonal_expenses(month, year); // сезонные траты (подарки,празднования и т.д.)   

        alice_car(month, year);

        alice_deposite(month, year);


        bob_salary(month, year);
        bob_business(month, year);

        bob_health();
        bob_nutrition_expenses(month, year);
        if (month % 3 == 0) {
            bob_print_nutrition_info(month, year);
        }

        bob_luxury_expenses(month, year);  // люксовые траты боба
        bob_vacation(month, year);

        bob_car(month, year);

        bob_cat();
        bob_dog(month, year);
        bob_random_events(month, year);
        bob_deposite(month, year);

        apply_inflation(year);

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    SetConsoleOutputCP(1251);  // кодировка Windows-1251 для вывода
    SetConsoleCP(1251);

    alice_init();
    bob_init();

    simulation();

    print_results();

    return 0;
}

