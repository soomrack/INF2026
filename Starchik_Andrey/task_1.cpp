#include <stdio.h>
#include <stdlib.h>


using RUB = long long int;


struct RealEstate 
{
    RUB apartment_value;
    RUB apartment_tax;
    RUB rent_income;
    int has_mortgage;
    RUB mortgage_payment;
};


struct Investments 
{
    RUB stocks;
    RUB bonds;
    double stocks_growth_rate;
};


struct Health 
{
    int happiness;
    RUB gym_membership;
    RUB medicine;
};


struct Entertainment 
{
    RUB cinema;
    RUB restaurants;
    RUB travel_budget;
    RUB hobbies;
};


struct Car 
{
    RUB value;
    RUB gas;
    RUB maintenance;
    RUB fine;
    int age_months;
};


struct Person 
{
    RUB salary;
    RUB capital;
    RUB food;
    RUB education;
    RUB random_income;
    RUB random_expense;
    struct Car car;
    struct RealEstate realty;
    struct Investments invest;
    struct Health health;
    struct Entertainment fun;
};


struct Person Alice;

double pp = 14.5;


void alice_bank_interest();
void alice_food();
void alice_health();
void alice_investments();
void alice_real_estate();
void alice_entertainment();
void alice_random_events();
void alice_car();
void alice_education();
void alice_salary(const int month, const int year);
void alice_init();
void simulation();
void print_results();


// Банк
void alice_bank_interest()
{
    Alice.capital += Alice.capital * (pp / 12.0 / 100.0);
}


// Еда
void alice_food()
{
    Alice.capital -= Alice.food;
}


// Здоровье
void alice_health() 
{
    // Счастье
    if (Alice.capital > 1'000'000)
    {
        Alice.health.happiness += 2;
    }

    else if (Alice.capital < 100'000)
    {
        Alice.health.happiness -= 3;
    }
    
    if (Alice.health.happiness > 100)
    {
        Alice.health.happiness = 100;
    }

    if (Alice.health.happiness < 0)
    {
        Alice.health.happiness = 0;
    }
    
    Alice.capital -= Alice.health.gym_membership;

    Alice.capital -= Alice.health.medicine;
    
    Alice.health.medicine = 0; //!
}


// Инвестиции
void alice_investments()
{
    // Акции
    Alice.invest.stocks += Alice.invest.stocks * (Alice.invest.stocks_growth_rate / 100.0);
    
    // Облигации
    Alice.invest.bonds += Alice.invest.bonds * 0.5 / 100.0;
    
    // Сумма
    Alice.capital += Alice.invest.stocks + Alice.invest.bonds;
}


// Недвижимость
void alice_real_estate()
{
    // Налог
    Alice.capital -= Alice.realty.apartment_tax;
    
    // Доход от аренды
    Alice.capital += Alice.realty.rent_income;
    
    // Ипотека
    if (Alice.realty.has_mortgage)
    {
        Alice.capital -= Alice.realty.mortgage_payment;
    }
    
    // Квартира дорожает
    Alice.realty.apartment_value += Alice.realty.apartment_value * 0.3 / 100.0;
}


// Развлечения
void alice_entertainment()
{
    Alice.capital -= Alice.fun.cinema;
    Alice.capital -= Alice.fun.restaurants;
    Alice.capital -= Alice.fun.travel_budget;
    Alice.capital -= Alice.fun.hobbies; //!
    
    // + счастье
    RUB total_fun = Alice.fun.cinema + Alice.fun.restaurants + Alice.fun.travel_budget + Alice.fun.hobbies;
    
    if (total_fun > 30'000)
    {
        Alice.health.happiness += 15;
    }
    
    else if (total_fun > 10'000)
    {
        Alice.health.happiness += 8;
    }
    
    else
    {
        Alice.health.happiness -= 3;  // Мало развлечений - грустно
    }

    if (Alice.health.happiness > 100)
    {
        Alice.health.happiness = 100;
    }

    if (Alice.health.happiness < 0)
    {
        Alice.health.happiness = 0;
    }
}


// Случайные события
void alice_random_events()
{
    // Лотерея
    Alice.capital -= 100; // Стоимость билета
    int lottery_prob = rand() % 100;
    
    if (lottery_prob < 5)
    {
        RUB win = 50'000 + (rand() % 200'000);
        Alice.random_income += win;

        printf("Алиса выиграла %lld RUB в лотерею\n", win);
    }

    // Штраф
    int fine_prob = rand() % 100;

    if (fine_prob < 10)
    {
        RUB fine = 1'000 + (rand() % 10'000);
        Alice.random_expense += fine;

        printf("Алиса получила штраф %lld RUB\n", fine);
    }

    // Подарок
    int gift_prob = rand() % 100;

    if (gift_prob < 15)
    {
        RUB gift = 3'000 + (rand() % 20'000);
        Alice.random_income += gift;

        printf("Алисе подарили %lld RUB\n", gift);
    }
    
    Alice.capital += Alice.random_income;
    Alice.capital -= Alice.random_expense;
    
    Alice.random_income = 0;
    Alice.random_expense = 0;
}


// Машина
void alice_car()
{
    Alice.capital -= Alice.car.gas;
    Alice.capital -= Alice.car.maintenance;
    Alice.capital -= Alice.car.fine;
    
    // Машина теряет цену
    Alice.car.age_months++;

    if (Alice.car.age_months > 12)
    {
        Alice.car.value -= Alice.car.value * 2.0 / 100.0;
    }

    else
    {
        Alice.car.value -= Alice.car.value * 1.0 / 100.0;
    }
    
    // Техобслуживание
    if (Alice.car.age_months % 6 == 0)
    {
        Alice.car.maintenance = 10'000 + (rand() % 20'000);
    }

    else
    {
        Alice.car.maintenance = 0;
    }
}

// Обучение
void alice_education()
{
    if (Alice.education > 0)
    {
        Alice.capital -= Alice.education;

        static int study_months = 0;
        study_months++;

        if (study_months == 12)
        {
            Alice.salary += Alice.salary * 0.1;
            printf("Алиса закончила курсы! Зарплата повышена до %lld\n", Alice.salary);

            study_months = 0;
        }
    }
}


// Задать переменные
void alice_init()
{
    // Основное
    Alice.capital = 500'000;
    Alice.salary = 180'000;
    Alice.food = 20'000;
    Alice.education = 5'000;

    // Машина
    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;
    Alice.car.maintenance = 0;
    Alice.car.fine = 0;
    Alice.car.age_months = 0;
    
    // Недвижимость
    Alice.realty.apartment_value = 8'000'000;
    Alice.realty.apartment_tax = 2'000;
    Alice.realty.rent_income = 0;
    Alice.realty.has_mortgage = 0;
    Alice.realty.mortgage_payment = 0;
    
    // Инвестиции
    Alice.invest.stocks = 100'000;
    Alice.invest.bonds = 200'000;
    Alice.invest.stocks_growth_rate = 2.5;
    
    // Здоровье
    Alice.health.happiness = 80;
    Alice.health.gym_membership = 5'000;
    Alice.health.medicine = 0;
    
    // Развлечения
    Alice.fun.cinema = 2'000;
    Alice.fun.restaurants = 8'000;
    Alice.fun.travel_budget = 10'000;
    Alice.fun.hobbies = 3'000;
    
    // Случайное
    Alice.random_income = 0;
    Alice.random_expense = 0;
}


void alice_salary(const int month, const int year)
{
    if ((month == 8) && (year == 2026))
    {
        Alice.salary *= 1.5;
        printf("Повышение! Новая зарплата: %lld RUB\n", Alice.salary);
    }

        Alice.capital += Alice.salary;
}


void print_results()
{
    printf("\n\nРезультаты:\n");
    printf("Зарплата: %lld RUB\n", Alice.salary);
    printf("Капитал: %lld RUB\n", Alice.capital);
    printf("\nАктивы:\n");
    printf("Стоимость машины: %lld RUB\n", Alice.car.value);
    printf("Стоимость квартиры: %lld RUB\n", Alice.realty.apartment_value);
    printf("Инвестиции: акции %lld, облигации %lld\n", Alice.invest.stocks, Alice.invest.bonds);
    printf("\nСостояние:\n");
    printf("Счастье: %d/100\n", Alice.health.happiness);
}

void simulation()
{
    int month = 2;
    int year = 2026;
    
    printf("Начало симуляции\n");
    
    while ( !((month == 3) && (year == 2027)) )
    {
        printf("\nДата %d/%d\n", month, year);
        
        alice_food();
        alice_education();
        alice_car();
        alice_health();
        alice_entertainment();
        alice_real_estate();
        alice_investments();
        alice_random_events();
        alice_salary(month, year);
        alice_bank_interest();
        
        printf("Капитал: %lld RUB, Счастье: %d\n", Alice.capital, Alice.health.happiness);
        
        ++month;
        if (month == 13)
        {
            month = 1;
            ++year;
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
