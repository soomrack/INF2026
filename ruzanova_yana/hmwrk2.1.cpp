#include <stdio.h>


using Percent = float;

using RUB = long long int;
using USD = long long int;


struct Car {
    RUB value;
    RUB gas;
};


struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
};


struct Flat { //оплата собственной квартиры 
    RUB housing_and_communal_servisec; //ЖКХ
    RUB current_repairs; //текущий ремонт
    RUB household_chemicals; //бытовая химия 
    RUB general_household_needs; //общедомовые нужды
    RUB checking_counters;//проверка счётчиков
    RUB repair_of_large_household_appliances; //ремонт крупногабаритной техники
};

struct Mortgage { //ипотечная квартира
    RUB loan_amount; //сумма импотеки
    RUB monthly_payment; //ежемесячный платеж
};


struct Wedding {
    RUB restaurant;        // ресторан
    RUB dress_and_suit;    // платье и костюм
    RUB rings;             // кольца
    RUB photographer;      // фотограф
    RUB other_expenses;    // прочие расходы
    bool happened;         // состоялась ли свадьба
};

struct Child {
    RUB initial_expenses;  // роды, коляска, кроватка
    RUB monthly_food;      // питание
    RUB diapers;           // подгузники
    RUB clothes;           // одежда
    RUB medicine;          // медицина
    bool born;             // родился ли ребенок
};


struct Person {
    Bank vtb;

    RUB salary; //зарплата Алисы 
    RUB husband_salary;  // зарплата супруга

    RUB food;
    Car car;
    Flat flat_1;
    Mortgage flat_2;
    Wedding wedding;
    Child child;

    bool on_maternity_leave; // декрет
};


struct Person alice; //алиса несчастная


void alice_init()
{
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 1'000;

    alice.salary = 700'000;
    alice.food = 3'000;

    alice.car.value = 2'400'000;
    alice.car.gas = 15'000;

    alice.flat_1.housing_and_communal_servisec = 17'000;
    alice.flat_1.current_repairs = 3'000;
    alice.flat_1.household_chemicals = 2'000;
    alice.flat_1.checking_counters=700;
    alice.flat_1.general_household_needs = 3'797;
    alice.flat_1.repair_of_large_household_appliances = 20'000;

    // свадьба
    alice.wedding.restaurant = 500'000;
    alice.wedding.dress_and_suit = 300'000;
    alice.wedding.rings = 200'000;
    alice.wedding.photographer = 150'000;
    alice.wedding.other_expenses = 100'000;
    alice.wedding.happened = false;

    // ребенок
    alice.child.initial_expenses = 400'000;
    alice.child.monthly_food = 10'000;
    alice.child.diapers = 8'000;
    alice.child.clothes = 5'000;
    alice.child.medicine = 3'000;
    alice.child.born = false;

    alice.husband_salary = 900'000;
    alice.on_maternity_leave = false;
}


void alice_food(const int month, const int year) //блок питания и тд
{
    if (month == 12) alice.vtb.account_rub -= 2000;  // christmas party

    Percent inflation_food = 12.0;
    switch (year) {
    case 2026: inflation_food = 12.5; break;
    case 2027: inflation_food = 14.0; break;
    case 2028: inflation_food = 13.0; break;
    case 2029: inflation_food = 11.5; break;
    }
    alice.food += alice.food * (inflation_food / 100. / 12.);

    alice.vtb.account_rub -= alice.food;
}


void alice_salary(const int month, const int year)
{
    // рост зарплаты мужа каждый январь
    if (month == 1 && year > 2026) {
        alice.husband_salary *= 1.08; // +8% в год
    }

    // декрет: с марта 2028 по март 2029
    if (year == 2028 && month == 3)
        alice.on_maternity_leave = true;

    if (year == 2029 && month == 3)
        alice.on_maternity_leave = false;

    RUB current_salary = alice.salary;

    if (alice.on_maternity_leave) {
        current_salary *= 0.4; // 40% пособие
    }

    alice.vtb.account_rub += current_salary;
    alice.vtb.account_rub += alice.husband_salary;
}


void print_results()
{
    printf("Salary = %lld\n", alice.salary);

    RUB capital = 0;
    capital += alice.vtb.account_rub;
    capital += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
    capital += alice.car.value;
    printf("Capital = %lld", capital);
}


void alice_car()//бибика
{
    alice.vtb.account_rub -= alice.car.gas;
}


void alice_flat_1(const int month, const int year) //квартирка
{
    Percent inflation_flat_1 = 12.0;
    switch (year) {
    case 2026: inflation_flat_1 = 13.5; break;
    case 2027: inflation_flat_1 = 17.0; break;
    case 2028: inflation_flat_1 = 15.0; break;
    case 2029: inflation_flat_1 = 19.5; break;
    }

    alice.flat_1.housing_and_communal_servisec += alice.flat_1.housing_and_communal_servisec * (inflation_flat_1 / 100. / 12.);

    if (year % 2 == 0) {
        alice.vtb.account_rub -= alice.flat_1.checking_counters;
        alice.flat_1.general_household_needs= alice.flat_1.general_household_needs+500;
    }
    else {
        alice.flat_1.general_household_needs = alice.flat_1.general_household_needs + 300;
    }
    if (month % 5 == 0) {
        alice.vtb.account_rub -= alice.flat_1.repair_of_large_household_appliances;
    }

    if (year)

    alice.vtb.account_rub -= alice.flat_1.housing_and_communal_servisec;
    alice.vtb.account_rub -= alice.flat_1.current_repairs;
    alice.vtb.account_rub -= alice.flat_1.household_chemicals;
    alice.vtb.account_rub -= alice.flat_1.general_household_needs;
}



void alice_wedding(const int month, const int year)
{
    if (!alice.wedding.happened && year == 2027 && month == 6) {

        RUB total =
            alice.wedding.restaurant +
            alice.wedding.dress_and_suit +
            alice.wedding.rings +
            alice.wedding.photographer +
            alice.wedding.other_expenses;

        alice.vtb.account_rub -= total;
        alice.wedding.happened = true;
    }
}


void alice_child(const int month, const int year)
{
    if (!alice.child.born && year == 2028 && month == 3) {
        alice.vtb.account_rub -= alice.child.initial_expenses;
        alice.child.born = true;
    }

    if (alice.child.born) {

        Percent inflation_child = 10.0;

        switch (year) {
        case 2028: inflation_child = 12.0; break;
        case 2029: inflation_child = 11.0; break;
        }

        // ежемесячная индексация
        alice.child.monthly_food +=
            alice.child.monthly_food * (inflation_child / 100. / 12.);

        alice.child.diapers +=
            alice.child.diapers * (inflation_child / 100. / 12.);

        alice.child.clothes +=
            alice.child.clothes * (inflation_child / 100. / 12.);

        alice.child.medicine +=
            alice.child.medicine * (inflation_child / 100. / 12.);

        alice.vtb.account_rub -= alice.child.monthly_food;
        alice.vtb.account_rub -= alice.child.diapers;
        alice.vtb.account_rub -= alice.child.clothes;
        alice.vtb.account_rub -= alice.child.medicine;
    }
}


void simulation()
{
    int year = 2026;
    int month = 2;

    while (!(year == 2030 && month == 1)) {
        alice_salary(month, year);
        alice_car();
        alice_flat_1(month, year);
        alice_wedding(month, year);
        alice_child(month, year);
        alice_food(month, year);

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