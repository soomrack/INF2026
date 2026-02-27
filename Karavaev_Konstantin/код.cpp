#include <stdio.h>


using RUB = long long int;
using USD = long long int;

using Percent = float;


struct Bank {
    RUB account;
    RUB deposite;
    Percent interest;

    USD account_usd;
    float rate_usd_rub;
    RUB credit_card;  // кредитка
    RUB investment;  //  инвестиции
};


struct Company {
    RUB income;
    RUB expenses;
    RUB capital;
    int employees;
    RUB marketing;  // маркетинг
    RUB equipment;  // оборудование
};


struct Cat {
    RUB food;
    RUB vet;
    RUB grooming;
    char name[20];
    RUB toys;  // игрушки котику
    RUB insurance;  // страховка
};


struct Dog {
    RUB food;
    RUB vet;
    RUB grooming;
    RUB walking;  // выгул
    RUB toys;
    RUB insurance;
    RUB training;  // дрессировка
    char name[20];
};


struct Mortgage {
    RUB loan_amount;  // сумма кредита
    RUB monthly_payment;
    RUB debt;  // оставток долга
    Percent rate;  // ставка
    int years;
    RUB property_value;
    RUB utilities;  // коммунальные платежи
    RUB repair;  // ремонт
};


struct Car {
    RUB gas;
    RUB value;
    RUB maintenance;  // ТО
    RUB wash;  // мойка
    RUB parking;  // парковка
    RUB tuning;  // тюнинг
    RUB insurance;  // страховка
    RUB tires;  // шины
    RUB fine;  // штраф
    RUB tax;  // налог

};


struct Vacation {
    RUB flights;
    RUB hotel;
    RUB food;
    RUB entertainment;
    RUB shopping;
    RUB transport;
    int days;
    char country[30];
};


struct Health {
    RUB gym;  // качалка
    RUB doctor;  // врачи
    RUB dentist;  // стоматолог
    RUB pharmacy;  // лекарства
    RUB cosmetics;  // косметика
};


struct Person {
    Bank vtb;
    Car car;
    Cat cat;
    Dog dog;  // ПЕС
    Mortgage mortgage;
    Health health;  // хелф
    RUB salary;
    RUB food;
    RUB clothes;  // одежда
    RUB entertainment;  // развлечения
    RUB education;  // образование
    RUB gifts;  // подарки
    RUB internet;  // интернет
    RUB mobile;  // телефон

};

struct PersonBob {
    Bank vtb;
    Company sport_nutrition;
    Cat cat;
    Dog dog;  // пес
    Car BMW;
    Health health;  // хелф
    RUB salary;
    RUB food;
    RUB business_income;
    RUB rental_income;  // доход от аренды
    RUB dividends;  // дивиденды
    RUB luxury;  // люкс расходы,для богатого БОБА
    Vacation vacation;  // отпуск
};


struct Person alice;
struct PersonBob bob;


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
    const char* alice_cat_name = "Snowball";
    for (int i = 0; i < 20 && alice_cat_name[i] != '\0'; i++) {
        alice.cat.name[i] = alice_cat_name[i];
    }
    alice.cat.name[19] = '\0';

    alice.dog.food = 3'500;  // собака Бадди
    alice.dog.vet = 1'500;
    alice.dog.grooming = 2'000;
    alice.dog.walking = 3'000;  // выгул
    alice.dog.toys = 700;
    alice.dog.insurance = 4'000;
    alice.dog.training = 2'000;  // дрессировка
    const char* alice_dog_name = "Buddy";
    for (int i = 0; i < 19 && alice_dog_name[i] != '\0'; i++) {
        alice.dog.name[i] = alice_dog_name[i];
    }
    alice.dog.name[19] = '\0';

    alice.mortgage.loan_amount = 7'000'000;  //  ипотешн
    alice.mortgage.monthly_payment = 65'000;
    alice.mortgage.debt = 6'800'000;
    alice.mortgage.rate = 11.0;
    alice.mortgage.years = 15;
    alice.mortgage.property_value = 8'500'000;
    alice.mortgage.utilities = 5'000;  // коммуналка
    alice.mortgage.repair = 2'000;  // ремонт

    alice.health.gym = 3'000;  //  здоровье алисы
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


    bob.sport_nutrition.income = 1'000'000;  //  Компания спорт. питания
    bob.sport_nutrition.expenses = 200'000;
    bob.sport_nutrition.capital = 3'000'000;
    bob.sport_nutrition.employees = 6;
    bob.sport_nutrition.marketing = 50000;
    bob.sport_nutrition.equipment = 500000;


    bob.cat.food = 3'000;  //  Кот Дарт Вейдер
    bob.cat.vet = 1'000;
    bob.cat.grooming = 10'000;
    bob.cat.toys = 1000;
    bob.cat.insurance = 5000;
    const char* cat_name = "Darth Vader";  // имя кота
    for (int i = 0; i < 20 && cat_name[i] != '\0'; i++) {
        bob.cat.name[i] = cat_name[i];
    }
    bob.cat.name[19] = '\0';

    bob.dog.food = 5000; // собака Рекс
    bob.dog.vet = 2000;
    bob.dog.grooming = 3000;
    bob.dog.walking = 5000;
    bob.dog.toys = 1500;
    bob.dog.insurance = 6000;
    bob.dog.training = 3000;
    const char* bob_dog_name = "Rex";
    for (int i = 0; i < 19 && bob_dog_name[i] != '\0'; i++) {
        bob.dog.name[i] = bob_dog_name[i];
    }
    bob.dog.name[19] = '\0';

    bob.BMW.value = 8'000'000;  //  Машина
    bob.BMW.gas = 30'000;
    bob.BMW.maintenance = 25'000;  // ТО BMW
    bob.BMW.wash = 3'500;  // мойка
    bob.BMW.parking = 10'000;  // парковка
    bob.BMW.tuning = 150'000;  // тюнинг
    bob.BMW.insurance = 120'000;  // страховка
    bob.BMW.tires = 30'000;  // шины
    bob.BMW.tax = 25'000;
    bob.BMW.fine = 0;

    bob.salary = 800'000;  //  Личные финансы Боба
    bob.food = 50'000;
    bob.business_income = 800'000;
    bob.rental_income = 50000;  // сдает квартиру
    bob.dividends = 20'000;  // дивиденды
    bob.luxury = 100'000;  // люкс расходы, те самые

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
    const char* country = "Maldives";
    for (int i = 0; i < 29 && country[i] != '\0'; i++) {
        bob.vacation.country[i] = country[i];
    }
    bob.vacation.country[29] = '\0';
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

    alice.vtb.account += alice.salary;
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
    alice.vtb.account -= alice.mortgage.utilities;  // коммуналка

    alice.mortgage.debt -= alice.mortgage.monthly_payment;  // уменьшение долга
    if (alice.mortgage.debt < 0) {
        alice.mortgage.debt = 0;
    }

    if (month % 3 == 0) {  // ремонт раз в 3 мес
        alice.vtb.account -= alice.mortgage.repair;
    }

    if (month == 12) {
        alice.mortgage.property_value = alice.mortgage.property_value * 105 / 100;
    }
}


void alice_health_expenses()  // здоровье
{
    alice.vtb.account -= alice.health.gym;
    alice.vtb.account -= alice.health.doctor;
    alice.vtb.account -= alice.health.pharmacy;
}

void alice_monthly_expenses()
{
    alice.vtb.account -= alice.food;
    alice.vtb.account -= alice.clothes;
    alice.vtb.account -= alice.entertainment;
    alice.vtb.account -= alice.education;
    alice.vtb.account -= alice.gifts;
    alice.vtb.account -= alice.internet;
    alice.vtb.account -= alice.mobile;
}

void alice_dog_expenses(int month, int year)
{
    alice.vtb.account -= alice.dog.food;
    alice.vtb.account -= alice.dog.walking;
    alice.vtb.account -= alice.dog.toys;

    if (month % 2 == 0) {
        alice.vtb.account -= alice.dog.vet;
    }

    if (month % 3 == 1) {
        alice.vtb.account -= alice.dog.grooming;
    }

    if (month == 3) {
        alice.vtb.account -= alice.dog.insurance;
    }

    if (month == 2 || month == 8) {
        alice.vtb.account -= alice.dog.training;
    }
}


void alice_seasonal_expenses(int month, int year)
{
    if (month == 12) {
        alice.vtb.account -= 20'000;  // подарки
    }

    if (month == 9) {
        alice.vtb.account -= 15'000;  // празднование
    }

    if (month == 7 && year == 2027) {
        alice.vtb.account -= 80'000;  // отпуск
    }
}


void alice_investments(int month, int year)
{
    if (month == 6 || month == 12) {  // инвестиции
        RUB invest = 10'000;
        alice.vtb.investment += invest;
        alice.vtb.account -= invest;
    }

    if (month == 12) { // // Доход от инвестиций (раз в год)
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
        bob.salary = bob.salary * 130 / 100;
        bob.business_income = bob.business_income * 120 / 100;
        bob.rental_income = bob.rental_income * 110 / 100;
    }
}


void bob_business(int month, int year)
{
    int profit = bob.sport_nutrition.income - bob.sport_nutrition.expenses - bob.sport_nutrition.marketing;

    if (profit > 0) {
        bob.vtb.account += profit * 70 / 100;  // если доход есть - зачисляем на счет бобика

        bob.sport_nutrition.capital += profit * 30 / 100;  // увеличение капитала компании
    }

    if (month == 6 and year == 2026) {
        bob.sport_nutrition.income += 500'000;
        bob.sport_nutrition.equipment += 200'000;
    }

    if (month == 9 and year == 2026) {
        bob.sport_nutrition.income += 500'000;
        bob.sport_nutrition.employees += 2;
    }
}


void bob_dog_expenses(int month, int year)
{
    bob.vtb.account -= bob.dog.food;
    bob.vtb.account -= bob.dog.walking;
    bob.vtb.account -= bob.dog.toys;

    if (month % 2 == 0) {
        bob.vtb.account -= bob.dog.vet;
    }

    if (month % 3 == 1) {
        bob.vtb.account -= bob.dog.grooming;
    }

    if (month == 4) {
        bob.vtb.account -= bob.dog.insurance;
        bob.vtb.account -= bob.dog.training;
    }
}


void bob_luxury_expenses(int month, int year)
{
    bob.vtb.account -= bob.luxury;

    if (month % 2 == 0) {  // рестораны
        bob.vtb.account -= 30'000;
    }

    if (month == 8 && year == 2026) {  // Путешествия
        bob.vtb.account -= 200'000;
    }

    if (month >= 6 && month <= 8 && year == 2027) {  // Яхта (летом)
        bob.vtb.account -= 150'000;
    }
}


void bob_health_expenses()
{
    bob.vtb.account -= bob.health.gym;
    bob.vtb.account -= bob.health.doctor;
    bob.vtb.account -= bob.health.dentist;
    bob.vtb.account -= bob.health.pharmacy;
    bob.vtb.account -= bob.health.cosmetics;
}


void bob_vacation(int month, int year)  // Отпуск Боба
{
    if (month == 7 && year == 2027) {
        bob.vtb.account -= bob.vacation.flights;
        bob.vtb.account -= bob.vacation.hotel;
        bob.vtb.account -= bob.vacation.food;
        bob.vtb.account -= bob.vacation.entertainment;
        bob.vtb.account -= bob.vacation.shopping;
        bob.vtb.account -= bob.vacation.transport;
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
    bob.vtb.account -= bob.cat.food;
    bob.vtb.account -= bob.cat.grooming;
    bob.vtb.account -= bob.cat.vet;
    bob.vtb.account -= bob.cat.toys;
}


void bob_car_tires()
{
    bob.vtb.account -= bob.BMW.tires;
}


void bob_car_maintenance()
{
    RUB maintenance = bob.BMW.value * 5 / 1000;  // 0.5% от стоимости BMW
    bob.vtb.account -= maintenance;
}


void bob_car_wash()
{
    RUB wash = 3'000;  // премиум мойка
    bob.vtb.account -= wash;
}


void bob_car_parking()
{
    RUB parking = 8'000;  // парковка в центре
    bob.vtb.account -= parking;
}


void bob_car_tuning()
{
    RUB tuning = 150'000;
    bob.vtb.account -= tuning;
    bob.BMW.value += 200'000;  // машина дорожает после тюнинга
}


void bob_car_insurance()
{
    RUB insurance = bob.BMW.value * 7 / 100;  // 7% страховка в год
    bob.vtb.account -= insurance;
}


void bob_car_tax() 
{ 
    bob.vtb.account -= bob.BMW.tax; 
}


void bob_random_events(int month, int year)
{
    if (month == 4 and year == 2026) {
        bob.sport_nutrition.capital -= 500'000;  // убыток из-за сломанного оборудования
        bob.vtb.account -= 350'000;  // доплата за доп оборудование
    }

    if (month == 8 and year == 2026) {
        bob.vtb.account -= 15'000;  // прививки для кота
    }

    if (month == 11 and year == 2026) {
        bob.sport_nutrition.income += 500'000;  // рост дохода 
    }

    if (month == 2 and year == 2027) {
        bob.vtb.account -= 50'000;  // коту нужна операция
    }
}


void bob_deposite(const int month, const int year)
{
    bob.vtb.deposite += bob.vtb.account;
    bob.vtb.account = 0;

    if (year == 2026) bob.vtb.interest = 11.0;
    if (year == 2027) bob.vtb.interest = 10.0;
    if (year == 2028) bob.vtb.interest = 9.0;
    if (year == 2029) bob.vtb.interest = 8.0;

    RUB monthly_interest = bob.vtb.deposite * (bob.vtb.interest / 12.0 / 100.0);
    bob.vtb.deposite += monthly_interest;
}


void alice_food()
{
    alice.vtb.account -= alice.food;
}


void alice_car()
{
    alice.vtb.account -= alice.car.gas;
}


void alice_car_maintenance()
{
    alice.vtb.account -= alice.car.maintenance;
}

void alice_car_wash()
{
    alice.vtb.account -= alice.car.wash;
}

void alice_car_parking()
{
    alice.vtb.account -= alice.car.parking;
}

void alice_car_insurance()
{
    alice.vtb.account -= alice.car.insurance;
}

void alice_car_tires()
{
    alice.vtb.account -= alice.car.tires;
}


void alice_car_tax() 
{ 
    alice.vtb.account -= alice.car.tax; 
}


void alice_cat()
{
    alice.vtb.account -= alice.cat.food;
    alice.vtb.account -= alice.cat.vet;
    alice.vtb.account -= alice.cat.grooming;
    alice.vtb.account -= alice.cat.toys;
}


void alice_car_fine()
{
    RUB fine = 2'500;
    alice.vtb.account -= fine;
}


void alice_deposite(const int month, const int year)
{
    alice.vtb.deposite += alice.vtb.account;
    alice.vtb.account = 0;

    if (year == 2026) alice.vtb.interest = 14.5;
    if (year == 2027) alice.vtb.interest = 13.5;
    if (year == 2028) alice.vtb.interest = 12.5;
    if (year == 2029) alice.vtb.interest = 11.5;

    RUB monthly_interest = alice.vtb.deposite * (alice.vtb.interest / 12.0 / 100.0);
    alice.vtb.deposite += monthly_interest;
}


void alice_freelance(const int month, const int year)
{
    if (month == 3 and year == 2027) {
        alice.vtb.account_usd += 3'000;
    }
}


void print_results()
{
    printf("Salary = %lld\n", alice.salary);

    RUB capital = 0;
    capital += alice.vtb.account;
    capital += alice.car.value;
    capital += alice.vtb.investment;
    capital += alice.vtb.deposite;
    capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
    capital += alice.mortgage.property_value;

    printf("Capital = %lld\n", capital);
    printf("-------------------\n");
}


void print_bob_results()
{
    printf("Bob Salary = %lld\n", bob.salary);

    RUB bob_capital = 0;
    bob_capital += bob.vtb.account;
    bob_capital += bob.BMW.value;
    bob_capital += bob.vtb.investment;
    bob_capital += bob.vtb.deposite;
    bob_capital += bob.vtb.account_usd * bob.vtb.rate_usd_rub;
    bob_capital += bob.sport_nutrition.capital;

    printf("Bob Capital = %lld\n", bob_capital);
}

void simulation()
{
    int month = 2;
    int year = 2026;

    while (!(month == 3 and year == 2028)) {

        alice_salary(month, year);
        alice_freelance(month, year);
        alice_additional_income(month, year);

        alice_monthly_expenses();
        alice_health_expenses();

        alice_food();
        alice_cat();
        alice_car();  // бензин
        alice_dog_expenses(month, year);

        alice_mortgage_payment(month, year);  // ипотека
        alice_car_maintenance();
        alice_seasonal_expenses(month, year);
        alice_investments(month, year);

        alice_car_wash();
        alice_car_parking();
        if (month == 11) alice_car_tires();      // шины в ноябре
        if (month == 1) alice_car_insurance();    // страховка в январе
        if (month == 8) alice_car_tax();

        alice_deposite(month, year);


        bob_salary(month, year);
        bob_business(month, year);
        bob_bonus_from_company(month, year);
        bob_investment_dividends();

        bob_health_expenses();
        bob_luxury_expenses(month, year);
        bob_vacation(month, year);

        bob_car_maintenance();
        bob_car_wash();
        bob_car_parking();
        if (month == 8) bob_car_tuning();         // тюнинг в августе
        if (month == 1) bob_car_insurance();      // страховка в январе
        if (month == 10) bob_car_tires();         // шины в октябре
        if (month == 3) bob_car_tax();

        bob_cat();
        bob_dog_expenses(month, year);
        bob_random_events(month, year);
        bob_investments(month, year);
        bob_deposite(month, year);

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
    bob_init();

    simulation();

    print_results();
    print_bob_results();

    return 0;
}
