#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using RUB = long long int;

// машинка
struct Car {
    RUB value;   // стоимость автомобиля 
    RUB gas;   // ежемесячные расходы на бензин
    RUB maintenance;   // расходы на обслуживание (замена резины, ТО и т.д.)
};

// питомец
struct Animal {
    RUB food;   // ежемесячные расходы на корм
    RUB vet;   // расходы на ветеринара (раз в полгода)
};

// банк + инфляция
struct Bank {
    RUB deposit;   // депозит (сбережения, которые приносят проценты)
    RUB account;   // текущий счет (деньги, доступные для трат)
    float pp;   // процентная ставка по вкладу (годовых)
    float month_inf;   // месячный коэффициент инфляции 
};

// инвестиции
struct Investments {
    RUB stocks;   // акции 
    RUB bonds;   // облигации 
    RUB liquid_funds;   // ликвидные фонды (деньги под небольшой процент)
};

// медицинские расходы и возраст
struct Health {
    int age;   // возраст Алисы
    RUB dentist;   // расходы на стоматолога (раз в год)
    RUB med_chest;   // ежемесячные траты на витамины, гигиену, лекарства
    RUB disease;   // базовая стоимость болезней (умножается на возрастной коэффициент)
    RUB insurance;   // страховка (раз в год)
    RUB med_examination;   // профосмотр (раз в год)
};

// аренда жилья и бытовая техника
struct Flat {
    RUB renting;   // ежемесячная аренда
    RUB appliance;   // замена/ремонт техники (раз в год)
};

// повседневные расходы
struct Regular {
    RUB food;   // еда
    RUB cloth;   // одежда
    RUB gifts;   // подарки
    RUB subscription;   // подписки
};

// образование
struct Education {
    RUB courses;   // курсы повышения квалификации
    RUB books;   // книги
    RUB hobby;   // хобби (материалы, инструменты)
};

// благотворительность
struct Charity {
    RUB donations;   // ежемесячные пожертвования
    RUB special;   // специальные акции (раз в год)
};

// досуг
struct Leisure {
    RUB entertainment;   // кино, кафе, концерты
    RUB sport;   // спорт (абонемент, инвентарь)
    RUB vacation;   // отпуск (дополнительно к travel)
};


struct Person {
    RUB salary;   // зарплата
    Car car;   // автомобиль
    Animal animal;   // питомец
    RUB travel;   // путешествия (основной бюджет)
    Flat flat;   // жилье
    Health health;   // здоровье
    Bank bank;   // банк + инфляция
    Regular payments;   // регулярные платежи
    Investments invest;   // инвестиции
    Education education;   // образование
    Charity charity;   // благотворительность (новое)
    Leisure leisure;   // досуг
};

struct Person Alice;

// глобальные переменные для отслеживания времени (месяц и год)
int month = 2;   // начало: февраль 2026 года
int year = 2026;

// переход к следующему месяцу (изменяет глобальные переменные)
void passing_of_time() {
    ++month;   // увеличиваем месяц на 1
    if (month == 13) {   // если месяц стал 13 — это следующий год
        month = 1;   // сбрасываем месяц на январь
        ++year;   // увеличиваем год
    }
}

// БЛОК РАСХОДОВ И ДОХОДОВ

// автомобиль
void alice_car() {
    // инфляция: расходы на бензин и обслуживание растут каждый месяц
    Alice.car.maintenance *= Alice.bank.month_inf;
    Alice.car.gas *= Alice.bank.month_inf;
    // ежемесячные траты на бензин
    Alice.bank.account -= Alice.car.gas;
    // два раза в год (апрель и октябрь) — замена резины (обслуживание)
    if ((month == 4) || (month == 10)) {
        Alice.bank.account -= Alice.car.maintenance;
    }
}

// питомец (джунгарик)
void alice_humster() {
    // инфляция для корма и ветеринара
    Alice.animal.vet *= Alice.bank.month_inf;
    Alice.animal.food *= Alice.bank.month_inf;
    // ежемесячные траты на корм
    Alice.bank.account -= Alice.animal.food;
    // раз в полгода — визит к ветеринару
    if (month % 6 == 0) {
        Alice.bank.account -= Alice.animal.vet;
    }
}

// путешествия (основной бюджет, тратится из депозита раз в год)
void alice_travel() {
    // инфляция увеличивает траты на путешествия
    Alice.travel *= Alice.bank.month_inf;
    // отпуск в августе
    if (month == 8) {
        // если на депозите достаточно денег, тратим на отпуск
        if (Alice.bank.deposit >= Alice.travel) {
            Alice.bank.deposit -= Alice.travel;
        }
        // если недостаточно — путешествие не состоится (деньги не снимаются)
    }
}

// зарплата
void alice_salary() {
    // каждые 5 лет (в августе) — повышение зарплаты на 30%
    if ((month == 8) && ((year % 5) == 0)) {
        Alice.salary *= 1.3;
    }
    // зарплата поступает на текущий счет каждый месяц
    Alice.bank.account += Alice.salary;
}

// регулярные траты: еда, одежда, подарки, подписки
void alice_regular_payments() {
    // инфляция для всех категорий
    Alice.payments.food *= Alice.bank.month_inf;
    Alice.payments.cloth *= Alice.bank.month_inf;
    Alice.payments.gifts *= Alice.bank.month_inf;
    Alice.payments.subscription *= Alice.bank.month_inf;
    // ежемесячные траты
    Alice.bank.account -= Alice.payments.food;
    Alice.bank.account -= Alice.payments.cloth;
    Alice.bank.account -= Alice.payments.gifts;
    Alice.bank.account -= Alice.payments.subscription;
}

// здоровье
void alice_health() {
    // каждый февраль — день рождения, увеличиваем возраст
    if (month == 2) {
        Alice.health.age += 1;
    }
    // в сентябре — стоматолог
    if (month == 9) {
        Alice.bank.account -= Alice.health.dentist;
    }
    // в январе — оплата страховки
    if (month == 1) {
        Alice.bank.account -= Alice.health.insurance;
    }
    // в марте — профосмотр 
    if (month == 3) {
        Alice.bank.account -= Alice.health.med_examination;
    }
    // ежемесячные траты на витамины и гигиену
    Alice.bank.account -= Alice.health.med_chest;
    // расходы на болезни: чем старше, тем больше вероятность и тяжесть
    // тяжесть увеличивается раз в 25 лет
    float age_factor = Alice.health.age / 25.0;
    Alice.bank.account -= (Alice.health.disease * age_factor);
}

// жилье
void alice_accommodation() {
    // инфляция для аренды и техники
    Alice.flat.renting *= Alice.bank.month_inf;
    Alice.flat.appliance *= Alice.bank.month_inf;
    // ежемесячная аренда
    Alice.bank.account -= Alice.flat.renting;
    // в апреле — замена или ремонт техники (тратится с депозита, как крупная покупка)
    if (month == 4) {
        Alice.bank.deposit -= Alice.flat.appliance;
    }
}

// образование
void alice_education() {
    // инфляция для образовательных расходов
    Alice.education.courses *= Alice.bank.month_inf;
    Alice.education.books *= Alice.bank.month_inf;
    Alice.education.hobby *= Alice.bank.month_inf;
    // ежемесячные траты на книги и хобби
    Alice.bank.account -= Alice.education.books;
    Alice.bank.account -= Alice.education.hobby;
    // раз в полгода (в январе и июле) — оплата курсов
    if (month == 1 || month == 7) {
        Alice.bank.account -= Alice.education.courses;
    }
}

// благотворительность
void alice_charity() {
    // инфляция для пожертвований
    Alice.charity.donations *= Alice.bank.month_inf;
    Alice.charity.special *= Alice.bank.month_inf;
    // ежемесячные пожертвования
    Alice.bank.account -= Alice.charity.donations;
    // в декабре — специальные благотворительные акции
    if (month == 12) {
        Alice.bank.account -= Alice.charity.special;
    }
}

// досуг
void alice_leisure() {
    // инфляция для развлечений
    Alice.leisure.entertainment *= Alice.bank.month_inf;
    Alice.leisure.sport *= Alice.bank.month_inf;
    Alice.leisure.vacation *= Alice.bank.month_inf;
    // ежемесячные траты на развлечения и спорт
    Alice.bank.account -= Alice.leisure.entertainment;
    Alice.bank.account -= Alice.leisure.sport;
    // в июне — дополнительный отпускной бюджет 
    if (month == 6) {
        Alice.bank.account -= Alice.leisure.vacation;
    }
}

// начисление процентов по вкладу и перекладывание текущего счета на депозит
void alice_bank_interest() {
    // все деньги с текущего счета переводим на депозит в конце месяца
    Alice.bank.deposit += Alice.bank.account;
    Alice.bank.account = 0;
    // начисляем проценты по вкладу (pp — годовая ставка, делим на 12 для месячной)
    Alice.bank.deposit += Alice.bank.deposit * (Alice.bank.pp / 12.0 / 100.0);
}

// ежемесячное инвестирование: откладываем 10% от зарплаты, если хватает
void alice_monthly_invest() {
    RUB to_invest = Alice.salary * 0.1;   // 10% от зарплаты
    // Проверяем, что на счету достаточно денег плюс остаток на жизнь (60000)
    if (Alice.bank.account > to_invest + 60000) {
        Alice.bank.account -= to_invest;   // снимаем деньги со счета

        // распределяем инвестиции: 40% в акции, 35% в облигации, 25% в ликвидные фонды
        Alice.invest.stocks += static_cast<RUB>(to_invest * 0.40);
        Alice.invest.bonds += static_cast<RUB>(to_invest * 0.35);
        Alice.invest.liquid_funds += static_cast<RUB>(to_invest * 0.25);
    }
}

// доходность от инвестиций
void alice_investment_income() {
    // акции: случайная доходность от -4% до +5% (0.96 + случайное число от 0 до 0.09)
    float stock_market = 0.96 + (rand() % 9) / 100.0;
    Alice.invest.stocks = static_cast<RUB>(Alice.invest.stocks * stock_market);

    // облигации: стабильный рост 0.5% в месяц
    Alice.invest.bonds = static_cast<RUB>(Alice.invest.bonds * 1.005);

    // ликвидные фонды: рост 0.3% в месяц
    Alice.invest.liquid_funds = static_cast<RUB>(Alice.invest.liquid_funds * 1.003);
}

// вывод текущего состояния (раз в год)
void print_status() {
    RUB total_invest = Alice.invest.stocks + Alice.invest.bonds + Alice.invest.liquid_funds;
    RUB total_capital = Alice.bank.account + Alice.bank.deposit + total_invest;

    printf("Year %d:\n", year);
    printf("  Age: %d\n", Alice.health.age);
    printf("  Salary: %lld RUB\n", Alice.salary);
    printf("  Deposit: %lld RUB\n", Alice.bank.deposit);
    printf("  Investments: Stocks=%lld Bonds=%lld Liquid=%lld Total=%lld RUB\n",
        Alice.invest.stocks, Alice.invest.bonds, Alice.invest.liquid_funds, total_invest);
    printf("  TOTAL CAPITAL: %lld RUB\n", total_capital);
    printf("  --- Additional breakdown ---\n");
    printf("  Regular expenses: Food=%lld Cloth=%lld Gifts=%lld Subscr=%lld\n",
        Alice.payments.food, Alice.payments.cloth, Alice.payments.gifts, Alice.payments.subscription);
    printf("  Education: Courses=%lld Books=%lld Hobby=%lld\n",
        Alice.education.courses, Alice.education.books, Alice.education.hobby);
    printf("  Charity: Donations=%lld Special=%lld\n",
        Alice.charity.donations, Alice.charity.special);
    printf("  Leisure: Entertain=%lld Sport=%lld Vacation=%lld\n",
        Alice.leisure.entertainment, Alice.leisure.sport, Alice.leisure.vacation);
}

// вывод итоговых результатов после симуляции
void print_results() {
    RUB total_invest = Alice.invest.stocks + Alice.invest.bonds + Alice.invest.liquid_funds;
    RUB total_capital = Alice.bank.account + Alice.bank.deposit + total_invest;

    printf("\n========== FINAL RESULTS ==========\n");
    printf("Final salary: %lld RUB\n", Alice.salary);
    printf("Final deposit: %lld RUB\n", Alice.bank.deposit);
    printf("Final investments: %lld RUB\n", total_invest);
    printf("TOTAL CAPITAL: %lld RUB\n", total_capital);
    printf("Final age: %d years\n", Alice.health.age);
    printf("Simulation completed from Feb 2026 to Mar 2057\n");
}

// цикл по месяцам
void simulation() {
    // симуляция до марта 2057 года включительно
    while (!(year == 2057 && month == 3)) {

        // получение зарплаты
        alice_salary();

        // все расходы (каждый месяц)
        alice_turtle();   // питомец
        alice_travel();   // путешествия (раз в год)
        alice_health();   // здоровье
        alice_regular_payments();   // повседневные расходы
        alice_car();   // автомобиль
        alice_accommodation();   // аилье
        alice_education();   // образование
        alice_charity();    // благотворительность
        alice_leisure();   // отдых и развлечения

        // инвестиции
        alice_monthly_invest();   // откладываем и покупаем активы
        alice_investment_income();   // получаем доходность от активов

        // банковские операции (проценты и перевод на депозит)
        alice_bank_interest();

        // раз в год выводим статус (в январе)
        if (month == 1) {
            print_status();
        }

        // переход к следующему месяцу
        passing_of_time();
    }
}

// начальные значения
void alice_init() {
    // Банк
    Alice.bank.deposit = 0;
    Alice.bank.account = 0;
    Alice.bank.pp = 9.8;   // 9.8% годовых по вкладу
    Alice.bank.month_inf = 1.0062;   // ~7.7% инфляции в год

    // зарплата
    Alice.salary = 155000;   // 155 000 рублей в месяц

    // регулярные платежи
    Alice.payments.food = 20000;
    Alice.payments.cloth = 7000;
    Alice.payments.gifts = 2000;
    Alice.payments.subscription = 1500;  // подписки: музыка, кино, спортзал

    // автомобиль
    Alice.car.value = 2400000;
    Alice.car.gas = 15000;
    Alice.car.maintenance = 8000;

    // питомец
    Alice.animal.food = 1500;
    Alice.animal.vet = 3000;

    // Путешествия
    Alice.travel = 50000;

    // жилье
    Alice.flat.renting = 40000;
    Alice.flat.appliance = 10000;

    // здоровье
    Alice.health.dentist = 4000;
    Alice.health.med_chest = 1500;
    Alice.health.disease = 2000;
    Alice.health.insurance = 15000;
    Alice.health.med_examination = 3000;  // Профосмотр
    Alice.health.age = 25;

    // инвестиции
    Alice.invest.stocks = 0;
    Alice.invest.bonds = 0;
    Alice.invest.liquid_funds = 0;

    // образование
    Alice.education.courses = 5000;   // курсы раз в полгода
    Alice.education.books = 2000;   // книги каждый месяц
    Alice.education.hobby = 3000;     // хобби (материалы) каждый месяц

    // благотворительность
    Alice.charity.donations = 1000;   // ежемесячные пожертвования
    Alice.charity.special = 5000;     // специальные акции в декабре

    // досуг
    Alice.leisure.entertainment = 5000;  // кино и театры
    Alice.leisure.sport = 2500;          // спортивный абонемент
    Alice.leisure.vacation = 15000;      // дополнительный отпускной бюджет в июне
}


int main() {
    // генератор случайных чисел текущим временем
    // чтобы доходность акций была разной при каждом запуске
    srand(time(NULL));

    // начальные параметры Алисы
    alice_init();

    // запуск симуляцию
    simulation();

    // итог
    print_results();

    return 0; // конееец
}