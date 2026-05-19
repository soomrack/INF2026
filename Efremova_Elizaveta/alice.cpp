#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using RUB = long long int;

// розовая машинка
struct Car {
    RUB value;
    RUB gas;
    RUB maintenance;
    RUB coolant_flush;
    RUB washer_fluid;
    RUB osago;
    RUB casco;
    RUB green_card;

};

// питомец
struct Animal {
    RUB food;
    RUB vet;
    RUB toys;
    RUB vitamins;
    RUB treats;
    RUB shampoo;
    RUB grooming;

};

// банк + инфляция
struct Bank {
    RUB deposit;
    RUB account;
    RUB monthly_maintenance;
    RUB sms_notifications;
    RUB online_banking; 
    RUB currency_exchange_commission;
    RUB card_insurance;

    float pp;
    float month_inf;
};

// инвестиции
struct Investments {
    RUB stocks;
    RUB bonds;
    RUB liquid_funds;
};

// медицинские расходы и возраст
struct Health {
    int age;
    RUB dentist;   // (раз в год)
    RUB med_chest;
    RUB disease;   // базовая стоимость болезней (умножается на возрастной коэффициент)
    RUB insurance;   // страховка (раз в год)
    RUB med_examination;   // (раз в год)
};

// аренда жилья и бытовая техника
struct Flat {
    RUB renting;
    RUB appliance;   // замена/ремонт техники (раз в год)
};

// повседневные расходы
struct Regular {
    RUB food;
    RUB cloth;
    RUB gifts;
    RUB subscription;
};

// образование
struct Education {
    RUB courses;   // курсы повышения квалификации
    RUB books;
    RUB hobby;
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
    RUB vacation;
};

// бизнес ALICE'ONE - производство домиков для животных
struct Business {
    int employees;   // количество сотрудников (максимум 4)
    int team_builder;   // опыт команды (0-100, влияет на качество)
    bool is_active;   // бизнес работает или нет
    int monthly_sales_dogs;
    int monthly_sales_cats;
    int monthly_sales_reptiles;
    int monthly_sales_fish;
    RUB company_cash;
    RUB monthly_revenue;
    RUB production_cost;
    RUB marketing;
    RUB rent;
    RUB utilities;
    RUB raw_materials;
    RUB dog_house_price;
    RUB cat_house_price;
    RUB reptile_house_price;
    RUB fish_castle_price;
};

// питание и РПП 
struct EatingDisorder {
    int relapse_count;   // количество срывов за месяц
    int stress_level;   // уровень стресса (0-100), влияет на вероятность срыва
    bool is_healthy_mode;   // режим правильного питания (true - старается есть правильно)
    float relapse_probability;   // вероятность срыва в текущем месяце
    RUB healthy_food;   // траты на правильное питание
    RUB relapse_food;   // траты на срывы (конфеты, торты, шоколад, быстрые углеводы)
};

// усталость от бизнеса / работы
struct Fatigue {
    int level;
    int burnout_rate;
    bool is_searching_job;
    int months_searching;
}

// работа
struct Job {
    int experience;   // опыт работы
    int vacation_days;
    int sick_leave_months;
    bool has_job;
    bool on_sick_leave;
    char position[50];
    
    RUB salary;
};

// ТРАВМЫ
struct Injury {
    char injury_name[100];
    int recovery_months;
    bool has_injury;
    bool needs_surgery;

    RUB treatment_cost;
    RUB surgery_cost;
};

// отношения
struct Relationship {
    bool has_boyfriend;
    bool boyfriend_pays;   // true - парень платит, false - Алиса
 
    char boyfriend_name[50];
    int relationship_months;
    int relationship_quality;
    char last_gift_type[50];
    RUB restaurant_spent;
    RUB cosmetics_spent;
    RUB small_wants_spent;
    RUB handmade_gifts_spent;
    RUB clothes_increase;
    RUB shoes_increase;
    RUB jewelry_increase;
    RUB last_gift_amount;
};


struct Person {
    RUB salary;
    Car car;
    Animal animal;
    RUB travel;
    Flat flat;
    Health health;
    Bank bank;
    Regular payments;
    Investments invest;
    Education education;
    Charity charity;
    Leisure leisure;
    Business business;
    EatingDisorder eating;
    Fatigue fatigue;
    Job job;
    Injury injury;
    Relationship relationship;
};

struct Person Alice;

// глобальные переменные для отслеживания времени (месяц и год)
int month = 2;
int year = 2026;

// переход к следующему месяцу (изменяет глобальные переменные)
void passing_of_time() {
    ++month;
    if (month == 13) {
        month = 1;
        ++year;
    }
}

// БЛОК РАСХОДОВ И ДОХОДОВ

// автомобиль
void alice_car() {
    Alice.car.maintenance *= Alice.bank.month_inf;
    Alice.car.gas *= Alice.bank.month_inf;

    Alice.bank.account -= Alice.car.gas;

    if ((month == 4) || (month == 10)) {
        Alice.bank.account -= Alice.car.maintenance;
    }
}

// питомец (джунгарик)
void alice_humster() {
    Alice.animal.vet *= Alice.bank.month_inf;
    Alice.animal.food *= Alice.bank.month_inf;

    Alice.bank.account -= Alice.animal.food;
    if (month % 6 == 0) {
        Alice.bank.account -= Alice.animal.vet;
    }
}

// путешествия (основной бюджет, тратится из депозита раз в год)
void alice_travel() {
    Alice.travel *= Alice.bank.month_inf;

    if (month == 8 && Alice.bank.deposit >= 50'000) {
        if (Alice.bank.deposit >= Alice.travel) {
            Alice.bank.deposit -= Alice.travel;
        }
        // если недостаточно — путешествие не состоится (деньги не снимаются)
    }
}

// зарплата
void alice_salary() {
    if ((month == 8) && ((year % 5) == 0)) {
        Alice.salary *= 1.3;
    }

    Alice.bank.account += Alice.salary;
}

// регулярные траты: еда, одежда, подарки, подписки
void alice_regular_payments() {
    Alice.payments.food *= Alice.bank.month_inf;
    Alice.payments.cloth *= Alice.bank.month_inf;
    Alice.payments.gifts *= Alice.bank.month_inf;
    Alice.payments.subscription *= Alice.bank.month_inf;

    Alice.bank.account -= Alice.payments.food;
    Alice.bank.account -= Alice.payments.cloth;
    Alice.bank.account -= Alice.payments.gifts;
    Alice.bank.account -= Alice.payments.subscription;
}

// здоровье
void alice_health() {

    Alice.health.dentist *= Alice.bank.month_inf;
    Alice.health.med_chest *= Alice.bank.month_inf;
    Alice.health.disease *= Alice.bank.month_inf;
    Alice.health.insurance *= Alice.bank.month_inf;
    Alice.health.med_examination *= Alice.bank.month_inf;

    if (month == 2) {
        Alice.health.age += 1;
    }

    if (month == 9) {
        Alice.bank.account -= Alice.health.dentist;
    }

    if (month == 1) {
        Alice.bank.account -= Alice.health.insurance;
    }

    if (month == 3) {
        Alice.bank.account -= Alice.health.med_examination;
    }

    Alice.bank.account -= Alice.health.med_chest;
    // расходы на болезни: чем старше, тем больше вероятность и тяжесть
    // тяжесть увеличивается раз в 25 лет
    float age_factor = Alice.health.age / 25.0;
    Alice.bank.account -= (Alice.health.disease * age_factor);
}

// жилье
void alice_accommodation() {
    Alice.flat.renting *= Alice.bank.month_inf;
    Alice.flat.appliance *= Alice.bank.month_inf;

    Alice.bank.account -= Alice.flat.renting;
    // в апреле — замена или ремонт техники (тратится с депозита, как крупная покупка)
    if (month == 4) {
        Alice.bank.deposit -= Alice.flat.appliance;
    }
}

// образование
void alice_education() {
    Alice.education.courses *= Alice.bank.month_inf;
    Alice.education.books *= Alice.bank.month_inf;
    Alice.education.hobby *= Alice.bank.month_inf;

    Alice.bank.account -= Alice.education.books;
    Alice.bank.account -= Alice.education.hobby;

    if (month == 1 || month == 7) {
        Alice.bank.account -= Alice.education.courses;
    }
}

// благотворительность
void alice_charity() {
    Alice.charity.donations *= Alice.bank.month_inf;
    Alice.charity.special *= Alice.bank.month_inf;
    // ежемесячные пожертвования
    Alice.bank.account -= Alice.charity.donations;
    // в декабре — новогодние благотворительные акции
    if (month == 12) {
        Alice.bank.account -= Alice.charity.special;
    }
}

// досуг
void alice_leisure() {
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

    // найм команды для бизнеса
    void alice_hire_team() {
        int chance = rand() % 100 + 1;

        printf("\n Hiring team for ALICE'ONE \n");

        if (chance <= 3) {  // 3% шанс - находит гениального менеджера
            Alice.business.employees = 4;
            Alice.business.team_builder = 100;
            Alice.business.is_active = true;
            printf("[Legendary event] Alice found a brilliant team!\n");
            printf("4 professionals with 20 years of experience joined!\n");
            printf("Team synergy is perfect! Production quality +100%%\n");
            printf("All product prices increased by 50%% due to premium quality!\n");

            // повышение цены из-за премиум-качества
            Alice.business.dog_house_price *= 1.5;
            Alice.business.cat_house_price *= 1.5;
            Alice.business.reptile_house_price *= 1.5;
            Alice.business.fish_castle_price *= 1.5;

        }
        else if (chance <= 10) {  // 7% шанс (3-10) - находит хороших специалистов
            Alice.business.employees = 4;
            Alice.business.team_builder = 80;
            Alice.business.is_active = true;
            printf("[Great event] Alice hired an experienced team!\n");
            printf("4 skilled craftsmen joined the company!\n");
            printf("Team experience: 80/100. Production quality is high!\n");
            printf("Product prices increased by 25%%!\n");

            Alice.business.dog_house_price *= 1.25;
            Alice.business.cat_house_price *= 1.25;
            Alice.business.reptile_house_price *= 1.25;
            Alice.business.fish_castle_price *= 1.25;

        }
        else if (chance <= 20) {  // 10% шанс (10-20) - находит среднюю команду
            Alice.business.employees = 4;
            Alice.business.team_builder = 60;
            Alice.business.is_active = true;
            printf("[Good event] Alice found a decent team!\n");
            printf("4 ordinary workers started production.\n");
            printf("Team experience: 60/100. Quality is acceptable.\n");
            printf("Prices remain standard.\n");

        }
        else if (chance <= 28) {  // 8% шанс (20-28) - находит новичков
            Alice.business.employees = 4;
            Alice.business.team_builder = 40;
            Alice.business.is_active = true;
            printf("[Novice event] Alice hired beginners!\n");
            printf("4 young specialists with little experience.\n");
            printf("Team experience: 40/100. Quality needs improvement.\n");
            printf("Prices reduced by 15%% to attract customers.\n");

            Alice.business.dog_house_price *= 0.85;
            Alice.business.cat_house_price *= 0.85;
            Alice.business.reptile_house_price *= 0.85;
            Alice.business.fish_castle_price *= 0.85;

        }
        else if (chance <= 30) {  // 2% шанс (28-30) - конфликт в команде
            Alice.business.employees = 2;
            Alice.business.team_builder = 30;
            Alice.business.is_active = true;
            printf("[Conflict event] Two employees constantly argue!\n");
            printf("Only 2 out of 4 remained. Team experience: 30/100.\n");
            printf("Production is slow and quality is low.\n");
            printf("Prices reduced by 30%%!\n");

            Alice.business.dog_house_price *= 0.7;
            Alice.business.cat_house_price *= 0.7;
            Alice.business.reptile_house_price *= 0.7;
            Alice.business.fish_castle_price *= 0.7;

        }
        else if (chance <= 33) {  // 3% шанс (30-33) - уходят лучшие сотрудники
            Alice.business.employees = 1;
            Alice.business.team_builder = 20;
            Alice.business.is_active = true;
            printf("[Bad event] Best employees left for a competitor!\n");
            printf("Only 1 assistant remained. Team experience: 20/100.\n");
            printf("Production is extremely slow!\n");
            printf("Prices reduced by 40%%!\n");

            Alice.business.dog_house_price *= 0.6;
            Alice.business.cat_house_price *= 0.6;
            Alice.business.reptile_house_price *= 0.6;
            Alice.business.fish_castle_price *= 0.6;

        }
        else {  // 67% шанс (33-100) - пока не находит команду
            if (Alice.business.employees == 0) {
                printf("[Waiting event] No suitable team found this month.\n");
                printf("Alice continues searching for employees...\n");
            }
            else {
                // Команда уже есть, просто ничего не меняем
                printf("[Team is already hired] Business continues as usual.\n");
            }
        }

        if (Alice.business.is_active) {
            printf("\nCurrent team status:\n");
            printf("  Employees: %d\n", Alice.business.employees);
            printf("  Team experience: %d/100\n", Alice.business.team_builder);
            printf("  Product prices: Dogs=%lld Cats=%lld Reptiles=%lld Fish=%lld RUB\n",
                Alice.business.dog_house_price, Alice.business.cat_house_price,
                Alice.business.reptile_house_price, Alice.business.fish_castle_price);
        }
}

// работа бизнеса ALICE'ONE
void alice_business_operations() {
    if (!Alice.business.is_active) {
        // бизнес еще не запущен, пытаемся найти команду
        if (year >= 2026 && month >= 3) {
            alice_hire_team();
        }
        return;
    }

    // инфляция для расходов бизнеса
    Alice.business.production_cost *= Alice.bank.month_inf;
    Alice.business.marketing *= Alice.bank.month_inf;
    Alice.business.rent *= Alice.bank.month_inf;
    Alice.business.utilities *= Alice.bank.month_inf;
    Alice.business.raw_materials *= Alice.bank.month_inf;

    Alice.business.dog_house_price *= Alice.bank.month_inf;
    Alice.business.cat_house_price *= Alice.bank.month_inf;
    Alice.business.reptile_house_price *= Alice.bank.month_inf;
    Alice.business.fish_castle_price *= Alice.bank.month_inf;

    float productivity = Alice.business.team_builder / 100.0;
    int base_sales = Alice.business.employees * 10;
    float quality_factor = 0.5 + (productivity * 0.8);

    // случайные колебания спроса (сезонность, тренды)
    int demand_variation = 70 + (rand() % 60);  // от 70% до 130%

    // продажи за месяц
    Alice.business.monthly_sales_dogs = base_sales * quality_factor * (demand_variation / 100.0);
    Alice.business.monthly_sales_cats = base_sales * quality_factor * (demand_variation / 100.0);
    Alice.business.monthly_sales_reptiles = base_sales * quality_factor * (demand_variation / 100.0);
    Alice.business.monthly_sales_fish = base_sales * quality_factor * (demand_variation / 100.0);

    // выручка от продаж
    RUB revenue = (Alice.business.monthly_sales_dogs * Alice.business.dog_house_price) +
        (Alice.business.monthly_sales_cats * Alice.business.cat_house_price) +
        (Alice.business.monthly_sales_reptiles * Alice.business.reptile_house_price) +
        (Alice.business.monthly_sales_fish * Alice.business.fish_castle_price);

    Alice.business.monthly_revenue = revenue;

    // расходы бизнеса за месяц
    RUB total_expenses = Alice.business.production_cost +
        Alice.business.marketing +
        Alice.business.rent +
        Alice.business.utilities +
        Alice.business.raw_materials;

    // прибыль/убыток за месяц
    RUB monthly_profit = revenue - total_expenses;

    // обновляем деньги компании
    Alice.business.company_cash += monthly_profit;

    // отчет о бизнесе (раз в квартал)
    if (month == 3 || month == 6 || month == 9 || month == 12) {
        printf("\n ALICE'ONE business report \n");
        printf("Month: %d/%d\n", month, year);
        printf("Team: %d employees, experience: %d/100\n",
            Alice.business.employees, Alice.business.team_builder);
        printf("\n Sales in this month:\n");
        printf("  Dog houses sold: %d x %lld RUB = %lld RUB\n",
            Alice.business.monthly_sales_dogs, Alice.business.dog_house_price,
            Alice.business.monthly_sales_dogs * Alice.business.dog_house_price);
        printf("  Cat houses sold: %d x %lld RUB = %lld RUB\n",
            Alice.business.monthly_sales_cats, Alice.business.cat_house_price,
            Alice.business.monthly_sales_cats * Alice.business.cat_house_price);
        printf("  Reptile houses sold: %d x %lld RUB = %lld RUB\n",
            Alice.business.monthly_sales_reptiles, Alice.business.reptile_house_price,
            Alice.business.monthly_sales_reptiles * Alice.business.reptile_house_price);
        printf("  Fish castles sold: %d x %lld RUB = %lld RUB\n",
            Alice.business.monthly_sales_fish, Alice.business.fish_castle_price,
            Alice.business.monthly_sales_fish * Alice.business.fish_castle_price);
        printf("\n Financials:\n");
        printf("  Total revenue: %lld RUB\n", revenue);
        printf("  Total expenses: %lld RUB\n", total_expenses);
        printf("  Monthly profit: %lld RUB\n", monthly_profit);
        printf("  Company cash: %lld RUB\n", Alice.business.company_cash);
        printf("===============================================\n\n");
    }

    // Алиса может забрать часть прибыли себе
    if (monthly_profit > 0 && month == 12) {
        RUB dividend = monthly_profit * 0.3;  // 30% прибыли забирает Алиса
        Alice.bank.deposit += dividend;
        Alice.business.company_cash -= dividend;
        printf("[Dividend] Alice took %lld RUB from business profit!\n", dividend);
    }

    // если убыток компании составляет более 100'000, то она может закрыться
    if (Alice.business.company_cash < -100000) {
        printf("[Bunkruptsy] Alice'one is bankrupt! Business closes.\n");
        Alice.business.is_active = false;
        Alice.business.employees = 0;
    }
}

// питание алисы и срывы (случайные события)
void alice_eating_disorder() {
    // применяем инфляцию к тратам на питание
    Alice.eating.healthy_food *= Alice.bank.month_inf;
    Alice.eating.relapse_food *= Alice.bank.month_inf;

    // базовые траты на правильное питание (если Алиса старается)
    if (Alice.eating.is_healthy_mode) {
        Alice.bank.account -= Alice.eating.healthy_food;
    }

    // расчет вероятности срыва в этом месяце
    // чем выше уровень стресса, тем выше вероятность срыва
    // стресс растет от: работы, бизнеса, финансовых проблем, возраста
    int stress_from_age = Alice.health.age / 10;   // каждые 10 лет +1 к стрессу
    int stress_from_business = 0;
    if (Alice.business.is_active && Alice.business.company_cash < 0) {
        stress_from_business = 30;   // бизнес в убытке - сильный стресс
    }
    else if (Alice.business.is_active && Alice.business.company_cash < 100000) {
        stress_from_business = 15;
    }

    int stress_from_money = 0;
    RUB total_money = Alice.bank.account + Alice.bank.deposit;
    if (total_money < 50000) {
        stress_from_money = 40;  // почти нет денег - паника
    }
    else if (total_money < 100000) {
        stress_from_money = 20;  // мало денег
    }
    else if (total_money < 200000) {
        stress_from_money = 10;  // нормально, но могло быть лучше
    }

    // обновляем уровень стресса (базовый 20 + все факторы)
    Alice.eating.stress_level = 20 + stress_from_age + stress_from_business + stress_from_money;
    if (Alice.eating.stress_level > 100) Alice.eating.stress_level = 100;

    // вероятность срыва = базовый шанс 15% + уровень стресса / 4
    // максимальная вероятность 40% при стрессе 100
    Alice.eating.relapse_probability = 0.15 + (Alice.eating.stress_level / 4.0 / 100.0);
    if (Alice.eating.relapse_probability > 0.40) Alice.eating.relapse_probability = 0.40;

    int chance = rand() % 100 + 1;
    int probability_percent = Alice.eating.relapse_probability * 100;

    // сброс количества срывов в новом месяце
    Alice.eating.relapse_count = 0;

    printf("n\ EATING & HEALTH STATUS \n");
    printf("Stress level: %d/100\n", Alice.eating.stress_level);
    printf("Relapse probability this month: %.1f%%\n", Alice.eating.relapse_probability * 100);

    // определяем, будет ли срыв
    if (chance <= probability_percent) {
        // Срыв случился! Вычисляем его "тяжесть"
        int relapse_severity = 1 + (rand() % 4);  // от 1 до 4 срывов в месяц

        // тяжесть срыва зависит от уровня стресса
        if (Alice.eating.stress_level > 70) {
            relapse_severity += 2;  // тяжелый стресс = больше срывов
        }
        else if (Alice.eating.stress_level > 50) {
            relapse_severity += 1;
        }

        if (relapse_severity > 7) relapse_severity = 7;  // Максимум 7 срывов

        Alice.eating.relapse_count = relapse_severity;

        // Расходы на срывы (каждый срыв стоит денег)
        RUB total_relapse_cost = Alice.eating.relapse_food * relapse_severity;
        Alice.bank.account -= total_relapse_cost;

        printf("\n [Relapse event] Alice had a food relapse!\n");
        printf("She couldn't resist and ate sweets, cakes, and chocolate.\n");
        printf("Number of relapses this month: %d\n", relapse_severity);
        printf("Money spent on relapse foods: %lld RUB\n", total_relapse_cost);

        // типы срывов 
        for (int i = 0; i < relapse_severity; i++) {
            int relapse_type = rand() % 5;
            switch (relapse_type) {
            case 0:
                printf("  - Bought a large chocolate cake (3000 RUB)\n");
                break;
            case 1:
                printf("  - Bought several chocolate bars (500 RUB each)\n");
                break;
            case 2:
                printf("  - Bought ice cream and cookies (800 RUB)\n");
                break;
            case 3:
                printf("  - Ordered fast food delivery (1200 RUB)\n");
                break;
            case 4:
                printf("  - Bought candies and pastries (600 RUB)\n");
                break;
            }
        }

        // последствия срыва для здоровья
        float health_penalty = relapse_severity * 0.02;  // 2% за каждый срыв
        RUB extra_health_cost = Alice.health.disease * health_penalty;
        Alice.bank.account -= extra_health_cost;
        printf("\n Health consequences: +%lld RUB for medications \n", extra_health_cost);

        // если срывов слишком много, Алиса может заболеть
        if (relapse_severity >= 5) {
            RUB illness_cost = Alice.health.disease * 1.5;
            Alice.bank.account -= illness_cost;
            printf("Serious Consequence] Severe relapse caused illness! +%lld RUB\n", illness_cost);
        }

    }
    else {
        // нет срыва в этом месяце
        printf("\n[Good mounth] Alice maintained healthy eating!\n");
        printf("She ate balanced meals: vegetables, fish, buckwheat\n");

        // бонус к здоровью за правильное питание
        RUB health_bonus = Alice.health.med_chest * 0.3;  // экономия 30% на лекарствах
        Alice.bank.account += health_bonus;
        printf("Health bonus saved: +%lld RUB (less need for medications)\n", health_bonus);

        // если долго нет срывов, стресс постепенно снижается
        static int months_without_relapse = 0;
        months_without_relapse++;
        if (months_without_relapse >= 3) {
            printf("3 months without relapse! Stress decreased!\n");
            Alice.eating.stress_level = Alice.eating.stress_level * 0.8;
            months_without_relapse = 0;
        }
    }

    // статистика за месяц
    printf("\n--- Monthly eating summary ---\n");
    printf("Healthy food budget spent: %lld RUB\n", Alice.eating.healthy_food);
    printf("Stress level: %d/100\n", Alice.eating.stress_level);
}

// случайные травмы
void alice_random_injury() {
    // если уже есть травма или на больничном, новые травмы не получает
    if (Alice.injury.has_injury || Alice.job.on_sick_leave) {
        return;
    }

    // шанс получить травму в этом месяце (базовый 8%)
    int chance = rand() % 100 + 1;
    if (chance > 8) return;  // 92% шанс, что всё ок

    printf("\n INJURY EVENT! \n");

    int injury_type = rand() % 24;

    switch (injury_type) {
    case 0:
        sprintf(Alice.injury.injury_name, "Ankle sprain");
        Alice.injury.treatment_cost = 15000;
        Alice.injury.recovery_months = 2;
        Alice.injury.needs_surgery = false;
        printf("Alice sprained her ankle while running!\n");
        break;
    case 1:
        sprintf(Alice.injury.injury_name, "Wrist fracture");
        Alice.injury.treatment_cost = 45000;
        Alice.injury.recovery_months = 3;
        Alice.injury.needs_surgery = false;
        printf("Alice fell and fractured her wrist!\n");
        break;
    case 2:
        sprintf(Alice.injury.injury_name, "Knee ligament tear");
        Alice.injury.treatment_cost = 120000;
        Alice.injury.recovery_months = 6;
        Alice.injury.needs_surgery = true;
        Alice.injury.surgery_cost = 80000;
        printf("Alice tore her knee ligament during training!\n");
        break;
    case 3:
        sprintf(Alice.injury.injury_name, "Shoulder dislocation");
        Alice.injury.treatment_cost = 25000;
        Alice.injury.recovery_months = 2;
        Alice.injury.needs_surgery = false;
        printf("Alice dislocated her shoulder while swimming!\n");
        break;
    case 4:
        sprintf(Alice.injury.injury_name, "Back muscle strain");
        Alice.injury.treatment_cost = 8000;
        Alice.injury.recovery_months = 1;
        Alice.injury.needs_surgery = false;
        printf("[Alice strained her back muscles at the gym!\n");
        break;
    case 5:
        sprintf(Alice.injury.injury_name, "Concussion");
        Alice.injury.treatment_cost = 60000;
        Alice.injury.recovery_months = 3;
        Alice.injury.needs_surgery = false;
        printf("Alice hit her head and got a concussion!\n");
        break;
    case 6:
        sprintf(Alice.injury.injury_name, "Achilles tendon rupture");
        Alice.injury.treatment_cost = 200000;
        Alice.injury.recovery_months = 8;
        Alice.injury.needs_surgery = true;
        Alice.injury.surgery_cost = 150000;
        printf("Alice ruptured her Achilles tendon!\n");
        break;
    case 7:
        sprintf(Alice.injury.injury_name, "Rib fracture");
        Alice.injury.treatment_cost = 35000;
        Alice.injury.recovery_months = 2;
        Alice.injury.needs_surgery = false;
        printf("Alice fractured a rib during workout!\n");
        break;
    case 8:
        sprintf(Alice.injury.injury_name, "Tennis elbow");
        Alice.injury.treatment_cost = 12000;
        Alice.injury.recovery_months = 3;
        Alice.injury.needs_surgery = false;
        printf("Alice developed tennis elbow!\n");
        break;
    case 9:
        sprintf(Alice.injury.injury_name, "Hamstring pull");
        Alice.injury.treatment_cost = 10000;
        Alice.injury.recovery_months = 1;
        Alice.injury.needs_surgery = false;
        printf("Alice pulled her hamstring while sprinting!\n");
        break;
    case 10:
        sprintf(Alice.injury.injury_name, "ACL tear");
        Alice.injury.treatment_cost = 250000;
        Alice.injury.recovery_months = 12;
        Alice.injury.needs_surgery = true;
        Alice.injury.surgery_cost = 180000;
        printf("Alice tore her ACL! Serious injury!\n");
        break;
    case 11:
        sprintf(Alice.injury.injury_name, "Groin strain");
        Alice.injury.treatment_cost = 8000;
        Alice.injury.recovery_months = 1;
        Alice.injury.needs_surgery = false;
        printf("Alice strained her groin during stretching!\n");
        break;
    case 12:
        sprintf(Alice.injury.injury_name, "Stress fracture (foot)");
        Alice.injury.treatment_cost = 30000;
        Alice.injury.recovery_months = 3;
        Alice.injury.needs_surgery = false;
        printf("Alice developed a stress fracture in her foot!\n");
        break;
    case 13:
        sprintf(Alice.injury.injury_name, "Rotator cuff tear");
        Alice.injury.treatment_cost = 90000;
        Alice.injury.recovery_months = 5;
        Alice.injury.needs_surgery = true;
        Alice.injury.surgery_cost = 70000;
        printf("Alice tore her rotator cuff while swimming!\n");
        break;
    case 14:
        sprintf(Alice.injury.injury_name, "Meniscus tear");
        Alice.injury.treatment_cost = 100000;
        Alice.injury.recovery_months = 4;
        Alice.injury.needs_surgery = true;
        Alice.injury.surgery_cost = 90000;
        printf("Alice tore her meniscus during squat!\n");
        break;
    case 15:
        sprintf(Alice.injury.injury_name, "Cervical spine injury");
        Alice.injury.treatment_cost = 180000;
        Alice.injury.recovery_months = 6;
        Alice.injury.needs_surgery = true;
        Alice.injury.surgery_cost = 200000;
        printf("Alice injured her cervical spine!\n");
        break;
    case 16:
        sprintf(Alice.injury.injury_name, "Broken collarbone");
        Alice.injury.treatment_cost = 50000;
        Alice.injury.recovery_months = 2;
        Alice.injury.needs_surgery = false;
        printf("Alice broke her collarbone in a fall!\n");
        break;
    case 17:
        sprintf(Alice.injury.injury_name, "Carpal tunnel syndrome");
        Alice.injury.treatment_cost = 20000;
        Alice.injury.recovery_months = 3;
        Alice.injury.needs_surgery = true;
        Alice.injury.surgery_cost = 40000;
        printf("Alice developed carpal tunnel syndrome!\n");
        break;
    case 18:
        sprintf(Alice.injury.injury_name, "Hip labral tear");
        Alice.injury.treatment_cost = 130000;
        Alice.injury.recovery_months = 5;
        Alice.injury.needs_surgery = true;
        Alice.injury.surgery_cost = 120000;
        printf("Alice tore her hip labrum!\n");
        break;
    case 19:
        sprintf(Alice.injury.injury_name, "Concussion with memory loss");
        Alice.injury.treatment_cost = 100000;
        Alice.injury.recovery_months = 4;
        Alice.injury.needs_surgery = false;
        printf("Alice got a severe concussion with memory loss!\n");
        break;
    case 20:
        sprintf(Alice.injury.injury_name, "Patellar dislocation");
        Alice.injury.treatment_cost = 40000;
        Alice.injury.recovery_months = 2;
        Alice.injury.needs_surgery = false;
        printf("Alice's kneecap got dislocated!\n");
        break;
    case 21:
        sprintf(Alice.injury.injury_name, "Lumbar disc herniation");
        Alice.injury.treatment_cost = 150000;
        Alice.injury.recovery_months = 6;
        Alice.injury.needs_surgery = true;
        Alice.injury.surgery_cost = 160000;
        printf("Alice herniated a disc in her lower back!\n");
        break;
    case 22:
        sprintf(Alice.injury.injury_name, "Facial fracture");
        Alice.injury.treatment_cost = 80000;
        Alice.injury.recovery_months = 2;
        Alice.injury.needs_surgery = true;
        Alice.injury.surgery_cost = 100000;
        printf("Alice suffered a facial fracture!\n");
        break;
    case 23:
        sprintf(Alice.injury.injury_name, "Multiple bruises and contusions");
        Alice.injury.treatment_cost = 5000;
        Alice.injury.recovery_months = 1;
        Alice.injury.needs_surgery = false;
        printf("Alice has multiple bruises from a fall!\n");
        break;
    }

    Alice.injury.has_injury = true;
    printf("Injury: %s\n", Alice.injury.injury_name);
    printf("Treatment cost: %lld RUB\n", Alice.injury.treatment_cost);
    printf("Recovery time: %d months\n", Alice.injury.recovery_months);

    if (Alice.injury.needs_surgery) {
        printf("Surgery REQUIRED! Cost: %lld RUB\n", Alice.injury.surgery_cost);

        // 70% шанс, что согласится на операцию
        int surgery_chance = rand() % 100 + 1;
        if (surgery_chance <= 70 && (Alice.bank.deposit + Alice.bank.account) >= Alice.injury.surgery_cost) {
            Alice.bank.deposit -= Alice.injury.surgery_cost;
            printf("Alice underwent surgery! %lld RUB paid\n", Alice.injury.surgery_cost);
        }
        else if (surgery_chance <= 70) {
            printf("Alice needs surgery but can't afford it! Taking a loan...\n");
            // берет кредит (отрицательный баланс)
            Alice.bank.deposit -= Alice.injury.surgery_cost;
        }
        else {
            printf("Alice refused surgery, recovery will take longer\n");
            Alice.injury.recovery_months += 3;
        }
    }

    // Тратим на лечение
    Alice.bank.account -= Alice.injury.treatment_cost;

    // Уходим на больничный
    Alice.job.on_sick_leave = true;
    Alice.job.sick_leave_months = Alice.injury.recovery_months;
    Alice.job.vacation_days = 0;

    printf("Alice is now on sick leave for %d months\n", Alice.injury.recovery_months);
}

// начисление процентов по вкладу и перекладывание текущего счета на депозит
void alice_bank_interest() {
    Alice.bank.deposit += Alice.bank.account;
    Alice.bank.account = 0;

    Alice.bank.deposit += Alice.bank.deposit * (Alice.bank.pp / 12.0 / 100.0);
}

// усталось от бизнеса + поиск новой работы
void alice_business_fatigue() {
    // если бизнес не активен или уже ищет работу, не накапливаем усталость
    if (!Alice.business.is_active || Alice.fatigue.is_searching_job) {
        return;
    }

    // накопление усталости от бизнеса
    // факторы, увеличивающие усталость:
    int fatigue_increase = 0;

    // бизнес в убытке => сильная усталость
    if (Alice.business.company_cash < 0) {
        fatigue_increase += 15;
    }
    // маленькая прибыль => умеренная усталость
    else if (Alice.business.monthly_revenue < Alice.business.production_cost * 1.2) {
        fatigue_increase += 8;
    }
    // команда маленькая => больше работы на Алису
    if (Alice.business.employees < 3) {
        fatigue_increase += 10;
    }
    // низкий опыт команды => нужно контролировать всё
    if (Alice.business.team_builder < 50) {
        fatigue_increase += 7;
    }
    // высокий уровень стресса от РПП увеличивает усталость
    fatigue_increase += (Alice.eating.stress_level / 10);

    // базовое накопление усталости
    Alice.fatigue.level += (5 + fatigue_increase);

    if (Alice.fatigue.level > 100) Alice.fatigue.level = 100;

    printf("\n BUSINESS FATIGUE \n");
    printf("Current fatigue level: %d/100\n", Alice.fatigue.level);
    printf("Fatigue increase this month: %d\n", 5 + fatigue_increase);

    // Если усталость достигла 100, начинаем искать новую работу
    if (Alice.fatigue.level >= 100 && !Alice.fatigue.is_searching_job) {
        printf("\n[Burnout warning] Alice is exhausted from the business!\n");
        printf("She decided to close the business and find a new job as a coach!\n");

        // Закрываем бизнес
        Alice.business.is_active = false;
        Alice.business.employees = 0;

        // Начинаем поиск работы
        Alice.fatigue.is_searching_job = true;
        Alice.fatigue.months_searching = 0;

        // Последняя прибыль от бизнеса (если есть)
        if (Alice.business.company_cash > 0) {
            Alice.bank.deposit += Alice.business.company_cash;
            printf("Company cash %lld RUB transferred to personal deposit\n", Alice.business.company_cash);
        }
    }
}

// поиск новой работы
void alice_search_new_job() {
    if (!Alice.fatigue.is_searching_job) return;

    Alice.fatigue.months_searching++;

    printf("\n JOB SEARCH \n");
    printf("Searching month #%d\n", Alice.fatigue.months_searching);

    // шанс найти работу зависит от опыта и месяца поиска
    int chance_to_find = 30 + (Alice.fatigue.months_searching * 10);
    if (chance_to_find > 85) chance_to_find = 85;

    int chance = rand() % 100 + 1;

    if (chance <= chance_to_find) {
        // Алиса нашла работу! определяем какую
        int job_type = rand() % 5;

        Alice.job.has_job = true;
        Alice.job.experience = 0;
        Alice.job.vacation_days = 28;
        Alice.job.on_sick_leave = false;
        Alice.job.sick_leave_months = 0;
        Alice.fatigue.is_searching_job = false;

        RUB base_salary = 0;

        switch (job_type) {
        case 0:
            sprintf(Alice.job.position, "Swimming Coach");
            base_salary = 70000;
            printf("Alice got a job as a SWIMMING COACH!\n");
            printf("Teaching children and adults to swim in the pool\n");
            break;
        case 1:
            sprintf(Alice.job.position, "Group Fitness Instructor");
            base_salary = 65000;
            printf("Alice got a job as a GROUP FITNESS INSTRUCTOR!\n");
            printf("Leading group classes: aerobics, Zumba, stretching\n");
            break;
        case 2:
            sprintf(Alice.job.position, "Personal Trainer");
            base_salary = 85000;
            printf("Alice got a job as a PERSONAL TRAINER!\n");
            printf("One-on-one training with clients\n");
            break;
        case 3:
            sprintf(Alice.job.position, "Children's Coach");
            base_salary = 60000;
            printf("Alice got a job as a CHILDREN'S COACH!\n");
            printf("Teaching sports to kids aged 5-12\n");
            break;
        case 4:
            sprintf(Alice.job.position, "Running Coach");
            base_salary = 75000;
            printf("Alice got a job as a RUNNING COACH!\n");
            printf("Training runners and organizing marathons\n");
            break;
        }

        // зп зависит от возраста и опыта
        int age_bonus = (Alice.health.age - 25) / 5 * 5000;
        if (age_bonus < 0) age_bonus = 0;

        Alice.job.salary = base_salary + age_bonus;
        Alice.salary = Alice.job.salary;  // теперь у Алисы другая зп

        printf("Salary: %lld RUB/month\n", Alice.job.salary);
        printf("Vacation days per year: %d\n", Alice.job.vacation_days);
        printf("Experience starts at: %d/100\n", Alice.job.experience);

        // сброс усталости
        Alice.fatigue.level = 0;
        Alice.eating.stress_level = Alice.eating.stress_level * 0.5;
        printf("\n Fresh start! Fatigue reset to 0, stress decreased by 50%% \n");

    }
    else {
        printf("Still searching for a coaching position...\n");
        printf("Current chance to find job: %d%%\n", chance_to_find);

        // если ищет слишком долго (больше года), возможно, снижает требования
        if (Alice.fatigue.months_searching >= 12) {
            printf("Long job search! Alice is considering lower-paid positions\n");
            chance_to_find += 20;
        }
    }
}

// травмы и больничный
void alice_injury_recovery() {
    if (!Alice.job.on_sick_leave) return;

    printf("\n INJURY RECOVERY \n");
    printf("Recovering from: %s\n", Alice.injury.injury_name);
    printf("Months remaining: %d\n", Alice.job.sick_leave_months);

    // на больничном начисляется только часть зп
    RUB sick_leave_pay = Alice.salary * 0.6; 
    Alice.bank.account += sick_leave_pay;
    printf("Sick leave payment (60%% of salary): %lld RUB\n", sick_leave_pay);

    // ежемесячные расходы на реабилитацию
    RUB rehab_cost = Alice.injury.treatment_cost * 0.1;
    Alice.bank.account -= rehab_cost;
    printf("Rehabilitation costs this month: %lld RUB\n", rehab_cost);

    Alice.job.sick_leave_months--;

    if (Alice.job.sick_leave_months <= 0) {
        // Алиса восстановилась!
        Alice.job.on_sick_leave = false;
        Alice.injury.has_injury = false;
        printf("\n Alice has fully recovered and can return to work!\n");

        // Опыт работы увеличивается после травмы
        Alice.job.experience += 5;
        if (Alice.job.experience > 100) Alice.job.experience = 100;
        printf("Work experience increased to %d/100\n", Alice.job.experience);
    }
}

// накопление опыта на работе
void alice_work_experience() {
    if (!Alice.job.has_job || Alice.job.on_sick_leave) return;

    // каждый месяц работы увеличивает опыт
    Alice.job.experience += 2;
    if (Alice.job.experience > 100) Alice.job.experience = 100;

    // каждый год работы (в августе) - повышение зарплаты
    if (month == 8 && (year % 1 == 0)) {
        RUB raise = Alice.job.salary * 0.05;
        Alice.job.salary += raise;
        Alice.salary = Alice.job.salary;
        printf("\n Work anniversary! Salary increased by 5%% to %lld RUB\n", Alice.job.salary);
    }

    // если опыт достиг 100, можно получить премию
    if (Alice.job.experience >= 100) {
        static bool bonus_received = false;
        if (!bonus_received && month == 12) {
            RUB bonus = Alice.job.salary * 2;
            Alice.bank.account += bonus;
            printf("\n MASTER COACH! Year-end bonus: %lld RUB\n", bonus);
            bonus_received = true;
        }
    }

    // поиск парня
    void alice_find_boyfriend() {
        // если уже есть парень, не ищет
        if (Alice.relationship.has_boyfriend) return;

        // если на больничном или нет денег, меньше шансов
        int chance_modifier = 0;
        if (Alice.job.on_sick_leave) chance_modifier = -10;
        if ((Alice.bank.account + Alice.bank.deposit) < 50000) chance_modifier = -5;

        // базовый шанс найти парня 5% в месяц
        int chance = rand() % 100 + 1;
        if (chance > 8 + chance_modifier) return;  // 8% шанс

        printf("\n NEW RELATIONSHIP! \n");

        // Список возможных имён парней
        const char* names[] = { "Alexander", "Dmitry", "Maxim", "Ivan", "Michael",
                               "Daniel", "Andrew", "Paul", "Sergey", "Vladimir" };
        int name_index = rand() % 10;
        sprintf(Alice.relationship.boyfriend_name, names[name_index]);

        Alice.relationship.has_boyfriend = true;
        Alice.relationship.relationship_months = 0;
        Alice.relationship.relationship_quality = 50 + (rand() % 40);

        // типы парней с разными характеристиками
        int boyfriend_type = rand() % 5;
        switch (boyfriend_type) {
        case 0:
            printf("Alice met %s at a coffee shop!\n", Alice.relationship.boyfriend_name);
            printf("He's a romantic and generous man!\n");
            Alice.relationship.boyfriend_pays = true;
            break;
        case 1:
            printf("Alice met %s at the gym!\n", Alice.relationship.boyfriend_name);
            printf("He's an athlete and shares her passion for sports!\n");
            Alice.relationship.boyfriend_pays = (rand() % 2 == 0);
            break;
        case 2:
            printf("Alice met %s at an art exhibition!\n", Alice.relationship.boyfriend_name);
            printf("He's creative and understanding!\n");
            Alice.relationship.boyfriend_pays = true;
            break;
        case 3:
            printf("Alice met %s through work connections!\n", Alice.relationship.boyfriend_name);
            printf("He's ambitious and hardworking!\n");
            Alice.relationship.boyfriend_pays = (rand() % 3 != 0);
            break;
        case 4:
            printf("Alice met %s at the dog park!\n", Alice.relationship.boyfriend_name);
            printf("He loves animals just like her!\n");
            Alice.relationship.boyfriend_pays = false;
            break;
        }

        printf("Relationship quality: %d/100\n", Alice.relationship.relationship_quality);
        if (Alice.relationship.boyfriend_pays) {
            printf("He usually pays for dates!\n");
        }
        else {
            printf("They split expenses equally or Alice pays more\n");
        }

        // снижение стресса от новых отношений
        int stress_reduction = 15 + (rand() % 15);
        Alice.eating.stress_level -= stress_reduction;
        if (Alice.eating.stress_level < 0) Alice.eating.stress_level = 0;
        printf("Stress decreased by % d points!\n", stress_reduction);
    }

    // траты на отношения
    void alice_relationship_spending() {
        if (!Alice.relationship.has_boyfriend) return;

        // увеличение трат на одежду
        Alice.relationship.clothes_increase *= Alice.bank.month_inf;
        Alice.relationship.shoes_increase *= Alice.bank.month_inf;
        Alice.relationship.jewelry_increase *= Alice.bank.month_inf;

        // базовое увеличение трат
        RUB extra_clothes = Alice.payments.cloth * (0.3 + (rand() % 30) / 100.0);
        RUB extra_shoes = Alice.payments.cloth * 0.2;
        RUB extra_jewelry = 2000 + (rand() % 5000);

        Alice.bank.account -= extra_clothes;
        Alice.bank.account -= extra_shoes;
        Alice.bank.account -= extra_jewelry;

        printf("\n RELATIONSHIP EXPENSES \n");
        printf("Wants to look cooler: spent %lld RUB on new clothes\n", extra_clothes);
        printf("Spent %lld RUB on stylish shoes\n", extra_shoes);
        printf("Spent %lld RUB on accessories and jewelry\n", extra_jewelry);

        // траты на рестораны
        Alice.relationship.restaurant_spent *= Alice.bank.month_inf;
        RUB restaurant_cost = Alice.relationship.restaurant_spent;

        // траты на косметику
        Alice.relationship.cosmetics_spent *= Alice.bank.month_inf;
        RUB cosmetics_cost = Alice.relationship.cosmetics_spent;

        // маленькие хотелки (кофе, такси, мелочи)
        Alice.relationship.small_wants_spent *= Alice.bank.month_inf;
        RUB small_wants = Alice.relationship.small_wants_spent;

        // кто платит?
        if (Alice.relationship.boyfriend_pays) {
            // парень платит большую часть
            printf("%s took Alice to a restaurant! He paid %lld RUB\n",
                Alice.relationship.boyfriend_name, restaurant_cost);
            printf("He also bought her cosmetics for %lld RUB\n", cosmetics_cost);
            printf("He covered small wants: %lld RUB\n", small_wants);
            // Алиса тратит только 20% от этого
            RUB alice_share = (restaurant_cost + cosmetics_cost + small_wants) * 0.2;
            Alice.bank.account -= alice_share;
            printf("Alice paid only her share: %lld RUB\n", alice_share);
        }
        else {
            // Алиса платит сама
            Alice.bank.account -= restaurant_cost;
            Alice.bank.account -= cosmetics_cost;
            Alice.bank.account -= small_wants;
            printf("Restaurant date cost : % lld RUB(Alice paid)\n", restaurant_cost);
            printf("Cosmetics shopping: %lld RUB\n", cosmetics_cost);
            printf("Small wants and treats: %lld RUB\n", small_wants);
        }

        // накопление усталости от отношений (если качество низкое)
        if (Alice.relationship.relationship_quality < 50) {
            Alice.fatigue.level += 2;
            printf("Low relationship quality increases fatigue!\n");
        }
    }

    // подарки парню своими руками
    void alice_handmade_gifts() {
        if (!Alice.relationship.has_boyfriend) return;

        // шанс сделать подарок (30% в месяц)
        int chance = rand() % 100 + 1;
        if (chance > 35) return;

        Alice.relationship.handmade_gifts_spent *= Alice.bank.month_inf;
        RUB gift_cost = Alice.relationship.handmade_gifts_spent;

        printf("\n HANDMADE GIFT \n");

        int gift_type = rand() % 8;
        switch (gift_type) {
        case 0:
            printf("Alice made a beautiful scrapbook with memories!\n");
            printf("Materials: colored paper, stickers, glue, ribbons\n");
            break;
        case 1:
            printf("Alice painted a portrait of them together!\n");
            printf("Materials: canvas, acrylic paints, brushes, varnish\n");
            break;
        case 2:
            printf("Alice knitted a warm scarf!\n");
            printf("Materials: wool yarn, knitting needles, buttons\n");
            break;
        case 3:
            printf("Alice wrote a poem collection and handmade the book!\n");
            printf("Materials: paper, binding tools, cover design\n");
            break;
        case 4:
            printf("Alice baked personalized cookies and cake!\n");
            printf("Materials: ingredients, decorative icing, packaging\n");
            break;
        case 5:
            printf("Alice made scented candles in jars!\n");
            printf("Materials: wax, essential oils, wicks, glass jars\n");
            break;
        case 6:
            printf("Alice created a mixtape with meaningful songs!\n");
            printf("Materials: USB drive, custom case, handwritten notes\n");
            break;
        case 7:
            printf("Alice made a terrarium in a glass bottle!\n");
            printf("Materials: glass container, soil, moss, tiny decorations\n");
            break;
        }

        Alice.bank.account -= gift_cost;
        printf("Handmade gift cost: %lld RUB\n", gift_cost);

        // подарок улучшает отношения
        int quality_boost = 5 + (rand() % 10);
        Alice.relationship.relationship_quality += quality_boost;
        if (Alice.relationship.relationship_quality > 100) Alice.relationship.relationship_quality = 100;
        printf("Relationship quality improved by %d points!\n", quality_boost);

        // снижение стресса от творчества
        int stress_reduction = 5 + (rand() % 10);
        Alice.eating.stress_level -= stress_reduction;
        if (Alice.eating.stress_level < 0) Alice.eating.stress_level = 0;
        printf("Stress decreased by %d points!\n", stress_reduction);
    }

    // подарки Алисе от парня
    void alice_receive_gifts() {
        if (!Alice.relationship.has_boyfriend) return;

        // шанс получить подарок
        int chance = rand() % 100 + 1;
        if (chance > 28) return;

        printf("\n GIFT FROM BOYFRIEND \n");

        int gift_type = rand() % 12;
        RUB gift_value = 0;

        switch (gift_type) {
        case 0:
            sprintf(Alice.relationship.last_gift_type, "flowers");
            gift_value = 2000 + (rand() % 5000);
            printf("%s gave Alice a beautiful bouquet of roses! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        case 1:
            sprintf(Alice.relationship.last_gift_type, "jewelry");
            gift_value = 5000 + (rand() % 20000);
            printf("%s surprised Alice with elegant earrings! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        case 2:
            sprintf(Alice.relationship.last_gift_type, "money");
            gift_value = 10000 + (rand() % 40000);
            printf("%s gave Alice money for her dreams! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        case 3:
            sprintf(Alice.relationship.last_gift_type, "perfume");
            gift_value = 3000 + (rand() % 8000);
            printf("%s bought Alice luxurious perfume! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        case 4:
            sprintf(Alice.relationship.last_gift_type, "handbag");
            gift_value = 7000 + (rand() % 25000);
            printf("%s gifted Alice a designer handbag! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        case 5:
            sprintf(Alice.relationship.last_gift_type, "tech");
            gift_value = 15000 + (rand() % 50000);
            printf("%s bought Alice new AirPods! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        case 6:
            sprintf(Alice.relationship.last_gift_type, "spa");
            gift_value = 4000 + (rand() % 10000);
            printf("%s gave Alice a spa certificate! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        case 7:
            sprintf(Alice.relationship.last_gift_type, "dinner");
            gift_value = 5000 + (rand() % 15000);
            printf("%s took Alice to a Michelin restaurant! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        case 8:
            sprintf(Alice.relationship.last_gift_type, "experience");
            gift_value = 8000 + (rand() % 20000);
            printf("%s bought tickets to a concert! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        case 9:
            sprintf(Alice.relationship.last_gift_type, "self-care");
            gift_value = 3000 + (rand() % 7000);
            printf("%s gave Alice luxury skincare set! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        case 10:
            sprintf(Alice.relationship.last_gift_type, "surprise");
            gift_value = 1000 + (rand() % 3000);
            printf("%s left sweet notes and chocolates! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        case 11:
            sprintf(Alice.relationship.last_gift_type, "sports");
            gift_value = 6000 + (rand() % 15000);
            printf("%s bought new yoga mat and sportswear! (%lld RUB)\n",
                Alice.relationship.boyfriend_name, gift_value);
            break;
        }

        Alice.relationship.last_gift_amount = gift_value;

        // деньги идут на счет, остальное - подарки
        if (strcmp(Alice.relationship.last_gift_type, "money") == 0) {
            Alice.bank.account += gift_value;
            printf("Money added to account!\n");
        }
        else {
            printf("Alice received a wonderful gift! She saved %lld RUB\n", gift_value);
        }

        // подарки снижают стресс
        int stress_reduction = 10 + (rand() % 20);
        Alice.eating.stress_level -= stress_reduction;
        if (Alice.eating.stress_level < 0) Alice.eating.stress_level = 0;
        printf("Stress decreased by %d points!\n", stress_reduction);

        // качество отношений улучшается
        Alice.relationship.relationship_quality += 3;
        if (Alice.relationship.relationship_quality > 100) Alice.relationship.relationship_quality = 100;
        printf("Relationship quality +3 (now %d/100)\n", Alice.relationship.relationship_quality);
    }

    // расставание
    void alice_breakup() {
        if (!Alice.relationship.has_boyfriend) return;

        int breakup_chance = 0;

        // Плохое качество отношений => высокий шанс
        if (Alice.relationship.relationship_quality < 30) {
            breakup_chance = 25;
        }
        else if (Alice.relationship.relationship_quality < 50) {
            breakup_chance = 15;
        }
        else if (Alice.relationship.relationship_quality < 70) {
            breakup_chance = 8;
        }
        else {
            breakup_chance = 3;
        }

        // дополнительные факторы
        if (Alice.fatigue.level > 80) breakup_chance += 10;  // усталость портит отношения
        if (Alice.eating.stress_level > 70) breakup_chance += 8;

        int chance = rand() % 100 + 1;
        if (chance > breakup_chance) return;

        printf("\n BREAK UP! \n");
        printf("Alice and %s broke up!\n", Alice.relationship.boyfriend_name);

        // причина расставания
        int reason = rand() % 6;
        switch (reason) {
        case 0:
            printf("Reason: Different life goals and priorities\n");
            break;
        case 1:
            printf("Reason: Constant arguments and misunderstandings\n");
            break;
        case 2:
            printf("Reason: %s moved to another city\n", Alice.relationship.boyfriend_name);
            break;
        case 3:
            printf("Reason: Lost feelings, grew apart over time\n");
            break;
        case 4:
            printf("Reason: Trust issues and jealousy\n");
            break;
        case 5:
            printf("Reason: Alice's career demanded all her attention\n");
            break;
        }

        // расставание повышает стресс
        int stress_increase = 20 + (rand() % 30);
        Alice.eating.stress_level += stress_increase;
        if (Alice.eating.stress_level > 100) Alice.eating.stress_level = 100;
        printf("Stress increased by %d points!\n", stress_increase);

        // усталость тоже растет
        Alice.fatigue.level += 10;
        if (Alice.fatigue.level > 100) Alice.fatigue.level = 100;

        // сбрасываем отношения
        Alice.relationship.has_boyfriend = false;
        Alice.relationship.relationship_months = 0;
        Alice.relationship.relationship_quality = 0;
        sprintf(Alice.relationship.boyfriend_name, "None");

    }

    void alice_update_relationship_quality() {
        if (!Alice.relationship.has_boyfriend) return;

        Alice.relationship.relationship_months++;

        int quality_change = 0;

        // позитивные факторы
        if (Alice.eating.stress_level < 30) quality_change += 2;
        if (Alice.business.is_active && Alice.business.company_cash > 100000) quality_change += 1;
        if (Alice.job.has_job && Alice.job.experience > 50) quality_change += 1;

        // негативные факторы
        if (Alice.eating.stress_level > 70) quality_change -= 3;
        if (Alice.fatigue.level > 70) quality_change -= 2;
        if (Alice.injury.has_injury) quality_change -= 4;

        quality_change += (rand() % 7) - 3;

        Alice.relationship.relationship_quality += quality_change;
        if (Alice.relationship.relationship_quality > 100) Alice.relationship.relationship_quality = 100;
        if (Alice.relationship.relationship_quality < 0) Alice.relationship.relationship_quality = 0;

        // раз в 3 месяца показываем статус отношений
        if (Alice.relationship.relationship_months % 3 == 0) {
            printf("\n RELATIONSHIP UPDATE \n");
            printf("Together for %d months with %s\n",
                Alice.relationship.relationship_months, Alice.relationship.boyfriend_name);
            printf("Current relationship quality: %d/100\n", Alice.relationship.relationship_quality);

            if (Alice.relationship.relationship_quality >= 80) {
                printf("Amazing relationship! Very happy together!\n");
            }
            else if (Alice.relationship.relationship_quality >= 60) {
                printf("Good relationship, some small issues\n");
            }
            else if (Alice.relationship.relationship_quality >= 40) {
                printf("Average relationship, need to work on it\n");
            }
            else {
                printf("Struggling relationship, risk of breakup!\n");
            }
        }
}

// ежемесячное инвестирование: откладываем 10% от зарплаты, если хватает
void alice_monthly_invest() {
    RUB to_invest = Alice.salary * 0.1;
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

    // ликвидные фонды: рост 3% в месяц
    Alice.invest.liquid_funds = static_cast<RUB>(Alice.invest.liquid_funds * 1.03);
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
    printf("  --- Business Alice'one ---\n");
    if (Alice.business.is_active) {
        printf("  Business ACTIVE | Team: %d emp | Experience: %d/100\n",
            Alice.business.employees, Alice.business.team_builder);
        printf("  Company cash: %lld RUB\n", Alice.business.company_cash);
        RUB total_business_value = Alice.business.company_cash +
            (Alice.business.employees * 50000) +
            (Alice.business.team_builder * 1000);
        printf("  Business value: ~%lld RUB\n", total_business_value);
    }
    else {
        printf("  Business NOT ACTIVE (searching for team)\n");
    }
    printf("  Eating and Health \n");
    printf("  Healthy food budget: %lld RUB\n", Alice.eating.healthy_food);
    printf("  Stress level: %d/100\n", Alice.eating.stress_level);
    printf("  Relapse probability: %.1f%%\n", Alice.eating.relapse_probability * 100);
    if (Alice.eating.relapse_count > 0) {
        printf("  RELAPSES this month: %d\n", Alice.eating.relapse_count);
    }
    else {
        printf(" No relapses this month\n");
    }

    printf("  Fatigue and Work \n");
    printf("  Business fatigue: %d/100\n", Alice.fatigue.level);
    if (Alice.fatigue.is_searching_job) {
        printf(" Searching for new job (month %d)\n", Alice.fatigue.months_searching);
    }

    if (Alice.job.has_job) {
        printf("  Current job: %s\n", Alice.job.position);
        printf("  Job salary: %lld RUB\n", Alice.job.salary);
        printf("  Experience: %d/100\n", Alice.job.experience);
        if (Alice.job.on_sick_leave) {
            printf(" ON SICK LEAVE (%d months remaining)\n", Alice.job.sick_leave_months);
        }
    }
    else if (!Alice.business.is_active && !Alice.fatigue.is_searching_job) {
        printf(" No active job or business\n");
    }

    if (Alice.injury.has_injury) {
        printf(" Injury Status \n");
        printf(" Current injury: %s\n", Alice.injury.injury_name);
        printf("  Recovery: %d months remaining\n", Alice.job.sick_leave_months);
    }

    printf(" Relationship Status \n");
    if (Alice.relationship.has_boyfriend) {
        printf("In a relationship with: %s (%d months)\n",
            Alice.relationship.boyfriend_name, Alice.relationship.relationship_months);
        printf("  Relationship quality: %d/100\n", Alice.relationship.relationship_quality);
        if (Alice.relationship.relationship_quality >= 80) {
            printf("  Status: Amazing!\n");
        }
        else if (Alice.relationship.relationship_quality >= 60) {
            printf("  Status: Good\n");
        }
        else if (Alice.relationship.relationship_quality >= 40) {
            printf("  Status: Average\n");
        }
        else {
            printf("  Status: Struggling\n");
        }
        if (Alice.relationship.boyfriend_pays) {
            printf(" Boyfriend usually pays for dates\n");
        }
        else {
            printf(" Splitting expenses or Alice pays\n");
        }
        if (Alice.relationship.last_gift_amount > 0) {
            printf(" Last gift from boyfriend: %s (%lld RUB)\n",
                Alice.relationship.last_gift_type, Alice.relationship.last_gift_amount);
        }
    }
    else {
        printf(" Single (ready to mingle)\n");
    }
}


// вывод итоговых результатов после симуляции
void print_results() {
    RUB total_invest = Alice.invest.stocks + Alice.invest.bonds + Alice.invest.liquid_funds;
    RUB total_capital = Alice.bank.account + Alice.bank.deposit + total_invest;

    printf("\n FINAL RESULTS \n");
    printf("Final salary: %lld RUB\n", Alice.salary);
    printf("Final deposit: %lld RUB\n", Alice.bank.deposit);
    printf("Final investments: %lld RUB\n", total_invest);
    printf("TOTAL CAPITAL: %lld RUB\n", total_capital);
    printf("\n Busines ALICE'ONE final status \n");
    if (Alice.business.is_active) {
        printf("Business survived and ended with: %lld RUB company cash\n",
            Alice.business.company_cash);
        printf("Final team: %d employees with %d/100 experience\n",
            Alice.business.employees, Alice.business.team_builder);
    }
    else {
        printf("Business did not start or went bankrupt\n");
    }
    printf("\n EATING DISORDER STATISTICS \n");
    printf("Alice tried to maintain healthy eating throughout her life.\n");
    printf("However, due to high stress from work, business, and finances,\n");
    printf("she experienced periodic relapses.\n");
    printf("Final stress level: %d/100\n", Alice.eating.stress_level);
    printf("If stress was high → more relapses → more money spent on:\n");
    printf("  - Sweets, cakes, chocolate\n");
    printf("  - Fast carbohydrates and sugars\n");
    printf("  - Consequent health issues\n");

    printf("Final age: %d years\n", Alice.health.age);
    printf("Simulation completed from Feb 2026 to Mar 2057\n");

    printf("\n WORK and INJURY STATISTICS \n");
    if (Alice.job.has_job) {
        printf("Alice ended as: %s\n", Alice.job.position);
        printf("Final job salary: %lld RUB\n", Alice.job.salary);
        printf("Final work experience: %d/100\n", Alice.job.experience);
    }
    else if (Alice.business.is_active) {
        printf("Alice continued running ALICE'ONE business\n");
    }
    else {
        printf("Alice was between jobs at the end of simulation\n");
    }

    if (Alice.injury.has_injury) {
        printf("\n Alice had an active injury at simulation end: %s\n", Alice.injury.injury_name);
    }
    
    printf("\n RELATIONSHIP STATISTICS \n");
    if (Alice.relationship.has_boyfriend) {
        printf("Alice ended the simulation in a relationship with %s\n",
            Alice.relationship.boyfriend_name);
        printf("They were together for %d months\n", Alice.relationship.relationship_months);
        printf("Final relationship quality: %d/100\n", Alice.relationship.relationship_quality);
    }
    else {
        printf("Alice was single at the end of the simulation\n");
    }
    printf("Throughout her life, Alice:\n");
    printf("  - Increased spending on clothes, shoes, and jewelry to look cooler\n");
    printf("  - Made handmade gifts (scrapbooks, paintings, baked goods, candles)\n");
    printf("  - Went on dates to restaurants and received gifts\n");
    printf("  - Her stress level was affected by relationship ups and downs\n");

    printf("Final age: %d years\n", Alice.health.age);
    printf("Simulation completed from Feb 2026 to Mar 2057\n");
}

    printf("Final age: %d years\n", Alice.health.age);
    printf("Simulation completed from Feb 2026 to Mar 2057\n");
}

// цикл по месяцам
void simulation() {
    while (!(year == 2057 && month == 3)) {

        alice_salary();

        alice_humster();
        alice_travel();
        alice_health();
        alice_regular_payments();
        alice_car();
        alice_accommodation();
        alice_education();
        alice_charity();
        alice_leisure();
        alice_business_operations();
        alice_eating_disorder();

        alice_random_injury();
        alice_business_fatigue();
        alice_search_new_job();
        alice_injury_recovery();
        alice_work_experience();

        alice_find_boyfriend();
        alice_relationship_spending();
        alice_handmade_gifts();
        alice_receive_gifts();
        alice_breakup();
        alice_update_relationship_quality();й

        // инвестиции
        alice_monthly_invest();
        alice_investment_income();

        // банковские операции (проценты и перевод на депозит)
        alice_bank_interest();

        if (month == 1) {
            print_status();
        }

        passing_of_time();
    }
}

// начальные значения
void alice_init() {
    Alice.bank.deposit = 0;
    Alice.bank.account = 0;
    Alice.bank.pp = 9.8;
    Alice.bank.month_inf = 1.0062;   // ~7.7% инфляции в год
    Alice.bank.monthly_maintenance = 500;
    Alice.bank.sms_notifications = 60;
    Alice.bank.online_banking = 300;
    Alice.bank.currency_exchange_commission = 0;
    Alice.bank.card_insurance = 200;

    Alice.salary = 155'000;

    // регулярные платежи
    Alice.payments.food = 20'000;
    Alice.payments.cloth = 7'000;
    Alice.payments.gifts = 2'000;
    Alice.payments.subscription = 1'500;
    Alice.payments.month_inf = 1.0062;

    // автомобиль
    Alice.car.value = 2'400'000;
    Alice.car.gas = 15'000;
    Alice.car.maintenance = 8'000;
    Alice.car.coolant_flush = 2'000;
    Alice.car.washer_fluid = 3'000;
    Alice.car.osago = 10'000;
    Alice.car.casco = 50'000;
    Alice.car.green_card = 12'000;
    Alice.car.month_inf = 1.0062;

    // питомец
    Alice.animal.food = 1'500;
    Alice.animal.vet = 3'000;
    Alice.animal.toys = 2'000;
    Alice.animal.vitamins = 8'000;
    Alice.animal.treats = 1'000;
    Alice.animal.shampoo = 4'000;
    Alice.animal.grooming = 12'000;
    Alice.animal.mounth_inf = 1.0062;

    // Путешествия
    Alice.travel = 50'000;

    // жилье
    Alice.flat.renting = 40'000;
    Alice.flat.appliance = 10'000;
    Alice.flat.month_inf = 1.0062;

    // здоровье
    Alice.health.dentist = 4'000;
    Alice.health.med_chest = 1'500;
    Alice.health.disease = 2'000;
    Alice.health.insurance = 15'000;
    Alice.health.med_examination = 3'000;
    Alice.health.age = 25;
    Alice.health.mounth_inf = 1.0062;

    // инвестиции
    Alice.invest.stocks = 0;
    Alice.invest.bonds = 0;
    Alice.invest.liquid_funds = 0;

    // образование
    Alice.education.courses = 5'000;
    Alice.education.books = 2'000;
    Alice.education.hobby = 3'000;
    Alice.education.mounth_inf = 1.0062;

    // благотворительность
    Alice.charity.donations = 1'000;
    Alice.charity.special = 5'000;

    // досуг
    Alice.leisure.entertainment = 5'000;
    Alice.leisure.sport = 2'500;
    Alice.leisure.vacation = 15'000;
    Alice.leisure.mounth_inf = 1.0062;

    // бизнес ALICE'ONE
    Alice.business.company_cash = 500'000;
    Alice.business.monthly_revenue = 0;
    Alice.business.production_cost = 80'000;
    Alice.business.marketing = 20'000;
    Alice.business.rent = 30'000;
    Alice.business.utilities = 10'000;   // свет, вода, отопление
    Alice.business.raw_materials = 40'000;
    Alice.business.employees = 0;
    Alice.business.team_builder = 0;
    Alice.business.is_active = false;   // бизнес пока не активен

    // цены на продукцию (растут с качеством)
    Alice.business.dog_house_price = 12'000;
    Alice.business.cat_house_price = 8'000;
    Alice.business.reptile_house_price = 5'000;
    Alice.business.fish_castle_price = 3'000;

    // продажи
    Alice.business.monthly_sales_dogs = 0;
    Alice.business.monthly_sales_cats = 0;
    Alice.business.monthly_sales_reptiles = 0;
    Alice.business.monthly_sales_fish = 0;

    // питание и РПП
    Alice.eating.healthy_food = 15'000;
    Alice.eating.relapse_food = 3'000;   // базовые траты на один срыв
    Alice.eating.relapse_count = 0;
    Alice.eating.stress_level = 20;
    Alice.eating.is_healthy_mode = true;   // Алиса старается питаться правильно
    Alice.eating.relapse_probability = 0.15;    // 15% вероятность срыва изначально

    // усталость
    Alice.fatigue.level = 0;
    Alice.fatigue.burnout_rate = 5;
    Alice.fatigue.is_searching_job = false;
    Alice.fatigue.months_searching = 0;

    // работа
    Alice.job.has_job = false;
    sprintf(Alice.job.position, "None");
    Alice.job.salary = 0;
    Alice.job.experience = 0;
    Alice.job.vacation_days = 0;
    Alice.job.on_sick_leave = false;
    Alice.job.sick_leave_months = 0;

    // травмы
    Alice.injury.has_injury = false;
    sprintf(Alice.injury.injury_name, "None");
    Alice.injury.treatment_cost = 0;
    Alice.injury.recovery_months = 0;
    Alice.injury.needs_surgery = false;
    Alice.injury.surgery_cost = 0;

    // отношения
    Alice.relationship.has_boyfriend = false;
    sprintf(Alice.relationship.boyfriend_name, "None");
    Alice.relationship.relationship_months = 0;
    Alice.relationship.relationship_quality = 0;
    Alice.relationship.restaurant_spent = 8000;
    Alice.relationship.cosmetics_spent = 5000;
    Alice.relationship.small_wants_spent = 3000;
    Alice.relationship.handmade_gifts_spent = 2000;
    Alice.relationship.clothes_increase = 5000;
    Alice.relationship.shoes_increase = 3000;
    Alice.relationship.jewelry_increase = 2000;
    Alice.relationship.boyfriend_pays = true;
    Alice.relationship.last_gift_amount = 0;
    sprintf(Alice.relationship.last_gift_type, "None");
}
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
