#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
using Percent = float;
using RUB = long long int;
using USD = long long int;

struct Car {
    RUB value;
    RUB gas;
    RUB insurance;            // страховка ОСАГО/КАСКО
    RUB maintenance;          // техническое обслуживание
    RUB winter_tires;         // зимняя резина
    RUB summer_tires;         // летняя резина
    RUB tire_change;          // шиномонтаж
    RUB car_wash;             // мойка
    RUB parking;              // парковка
    RUB fines;                // штрафы
    RUB diagnostics;          // диагностика
    RUB oil_change;           // замена масла
    RUB tax;                  // транспортный налог
};

struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
    RUB credit_card_debt;     // задолженность по кредитке
    RUB credit_card_limit;    // лимит кредитки
    RUB deposit_rub;          // рублевый депозит
    RUB deposit_usd;          // валютный депозит
    float deposit_rate;       // ставка по депозиту
    RUB investment_bonds;     // облигации
    RUB investment_stocks;    // акции
};

struct Flat { // оплата собственной квартиры
    RUB housing_and_communal_servisec; // ЖКХ
    RUB current_repairs;               // текущий ремонт
    RUB household_chemicals;           // бытовая химия
    RUB general_household_needs;       // общедомовые нужды
    RUB checking_counters;             // проверка счётчиков
    RUB repair_of_large_household_appliances; // ремонт крупногабаритной техники
    RUB internet;                      // интернет
    RUB tv;                            // телевидение
    RUB phone;                         // домашний телефон
    RUB furniture_renewal;             // обновление мебели
    RUB curtains;                      // шторы/жалюзи
    RUB dishes;                        // посуда
    RUB cleaning_equipment;            // инвентарь для уборки
    RUB air_conditioner_service;       // обслуживание кондиционера
    RUB water_filter;                  // фильтры для воды
    RUB insects_control;               // борьба с насекомыми
    RUB new_lamps;                     // лампочки и светильники
    RUB emergency_fund;                // аварийный запас на непредвиденные расходы
};

struct Mortgage { // ипотечная квартира
    RUB loan_amount; // сумма ипотеки
    RUB monthly_payment; // ежемесячный платеж
    RUB down_payment;      // первоначальный взнос
    float interest_rate;   // процентная ставка
    RUB property_insurance;// страховка квартиры
    RUB life_insurance;    // страховка жизни
    RUB appraisal;        // оценка квартиры
    RUB notary;           // нотариус
    RUB state_fee;        // госпошлина
    RUB bank_commission;  // комиссия банка
    RUB early_repayment;  // досрочное погашение
    RUB penalty;          // пеня за просрочку
    RUB renovation;       // ремонт в ипотечной квартире
    RUB furniture;        // мебель в ипотечную квартиру
};

struct Wedding {
    RUB restaurant;        // ресторан
    RUB dress_and_suit;    // платье и костюм
    RUB rings;             // кольца
    RUB photographer;      // фотограф
    RUB videographer;      // видеограф
    RUB makeup_artist;     // визажист
    RUB hairdresser;       // парикмахер
    RUB bouquet;           // букет невесты
    RUB boutonniere;       // бутоньерка
    RUB transport;         // транспорт для гостей
    RUB venue_decor;       // декор зала
    RUB invitations;       // приглашения
    RUB wedding_cake;      // свадебный торт
    RUB alcohol;           // алкоголь
    RUB music;             // музыкальное сопровождение
    RUB host;              // ведущий
    RUB honeymoon;         // медовый месяц
    RUB other_expenses;    // прочие расходы
    bool happened;         // состоялась ли свадьба
};

struct Child {
    RUB initial_expenses;  // роды, коляска, кроватка
    RUB monthly_food;      // питание (смеси, пюре)
    RUB diapers;           // подгузники
    RUB clothes;           // одежда (быстро растет!)
    RUB medicine;          // медицина
    RUB toys;              // игрушки (погремушки, развивашки)
    RUB kindergarten;      // детский сад (с 1.5-2 лет)
    RUB doctor_visits;     // платные врачи (педиатр)
    RUB vitamins;          // витамины
    RUB dentist;           // стоматолог (с 2-3 лет)
    RUB child_birthday;    // день рождения ребенка
    RUB babysitter;        // няня (если нужна)
    RUB development;       // развивающие занятия (с 2 лет)
    RUB stroller;          // коляска (может сломаться)
    RUB car_seat;          // автокресло (по мере роста)
    RUB high_chair;        // стульчик для кормления
    RUB playpen;           // манеж
    RUB baby_monitor;      // радионяня
    RUB breastfeeding;     // молокоотсос, бутылочки
    RUB hygiene;           // присыпки, крема, влажные салфетки
    RUB swimming;          // бассейн/грудничковое плавание
    RUB massage;           // массаж (до года)
    bool born;             // родился ли ребенок
    int age_months;        // возраст ребенка в месяцах
};

struct Pet {
    RUB food;               // корм
    RUB treats;             // лакомства
    RUB veterinary;         // ветеринар
    RUB vaccinations;       // прививки
    RUB grooming;           // груминг
    RUB toys_for_pet;       // игрушки
    RUB bedding;            // лежанка
    RUB bowl;               // миски
    RUB leash_and_collar;   // поводок и ошейник
    RUB carrier;            // переноска
    RUB toilet_trainer;     // лоток/пеленки
    RUB filler;             // наполнитель
    RUB claws_care;         // когтеточка/стрижка когтей
    RUB pet_insurance;      // страховка для питомца
    RUB pet_sitting;        // передержка
    RUB training;           // дрессировка
    RUB chip;               // чипирование
    RUB sterilization;      // стерилизация
    bool have_pet;          // есть ли питомец
};

struct Divorce {
    RUB lawyer_services;        // услуги адвоката
    RUB court_fee;              // госпошлина за развод
    RUB property_division;      // раздел имущества
    RUB alimony;                // алименты
    RUB appraiser_services;     // оценщик имущества
    RUB notary_for_divorce;     // нотариус при разводе
    RUB moving_expenses;        // расходы на переезд
    RUB separate_living;        // отдельное проживание
    RUB new_furniture;          // новая мебель
    RUB emotional_damage;       // моральный ущерб
    RUB psychotherapy;          // психотерапевт
    RUB documents_reissue;      // переоформление документов
    RUB bank_accounts_division; // раздел банковских счетов
    RUB car_division;           // раздел автомобиля
    RUB debt_division;          // раздел долгов
    bool happened;              // состоялся ли развод
};

struct Job {
    RUB salary;                 // зарплата
    RUB bonus;                  // премия
    RUB thirteenth_salary;      // 13-я зарплата
    RUB sick_leave;             // больничный
    RUB vacation_pay;           // отпускные
    RUB business_trip;          // командировочные
    RUB transportation;         // транспортные расходы
    RUB lunch;                  // обеды
    RUB work_clothes;           // рабочая одежда
    RUB training_courses;       // курсы повышения квалификации
    RUB professional_certificate;// сертификаты
    RUB literature;             // профессиональная литература
    RUB software;               // программное обеспечение
    RUB equipment;              // оборудование для работы
    RUB internet_for_work;      // интернет для работы
    RUB phone_for_work;         // телефон для работы
    RUB workplace_rent;         // аренда рабочего места
    RUB taxes;                  // налоги
    RUB pension_contributions;  // пенсионные отчисления
    RUB health_insurance;       // ДМС
    bool employed;              // трудоустроен ли
    bool looking_for_job;       // в поиске работы
};

struct Person {
    Bank vtb;
    RUB salary;           // зарплата Алисы
    RUB husband_salary;  // зарплата супруга
    RUB food;
    RUB husband_food;       // еда для мужа
    RUB eating_out;         // кафе/рестораны
    RUB delivery;           // доставка еды

    Car car_alice;
    Car car_husband;

    Flat flat_1;
    Mortgage flat_2;
    Wedding wedding;
    Child child;
    Pet cat;
    Pet hamster;
    Pet dog;
    Divorce divorce;
    Job alice_job;
    Job husband_job;

    bool on_maternity_leave; // декрет
    bool married;            // замужем ли
    RUB husband_alimony;     // алименты от мужа
    RUB random_income;       // случайные доходы
    RUB random_expenses;     // случайные расходы
    RUB inflation_protection; // защита от инфляции
    RUB emergency_fund_personal; // личный резервный фонд
};

struct Person alice;

void alice_init()
{
    // Банковские счета
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 500'000;  // Начальный капитал
    alice.vtb.account_usd = 1'000;
    alice.vtb.credit_card_debt = 0;
    alice.vtb.credit_card_limit = 300'000;
    alice.vtb.deposit_rub = 200'000;
    alice.vtb.deposit_usd = 500;
    alice.vtb.deposit_rate = 8.5;
    alice.vtb.investment_bonds = 100'000;
    alice.vtb.investment_stocks = 50'000;

    // Зарплаты и доходы
    alice.salary = 70'000;  // Уменьшил для реалистичности (было 700k)
    alice.husband_salary = 90'000;

    // Еда
    alice.food = 10'000;    // На человека в месяц
    alice.husband_food = 10'000;
    alice.eating_out = 5'000;
    alice.delivery = 3'000;

    // Машина Алисы
    alice.car_alice.value = 800'000;  // Более реалистичная цена
    alice.car_alice.gas = 5'000;
    alice.car_alice.insurance = 40'000; // в год
    alice.car_alice.maintenance = 5'000;
    alice.car_alice.winter_tires = 20'000;
    alice.car_alice.summer_tires = 20'000;
    alice.car_alice.tire_change = 3'000;
    alice.car_alice.car_wash = 1'500;
    alice.car_alice.parking = 2'000;
    alice.car_alice.fines = 500;
    alice.car_alice.diagnostics = 3'000;
    alice.car_alice.oil_change = 3'000;
    alice.car_alice.tax = 5'000;

    // Машина мужа
    alice.car_husband.value = 1'200'000;
    alice.car_husband.gas = 7'000;
    alice.car_husband.insurance = 50'000;
    alice.car_husband.maintenance = 6'000;
    alice.car_husband.winter_tires = 25'000;
    alice.car_husband.summer_tires = 25'000;
    alice.car_husband.tire_change = 3'000;
    alice.car_husband.car_wash = 1'500;
    alice.car_husband.parking = 3'000;
    alice.car_husband.fines = 500;
    alice.car_husband.diagnostics = 3'500;
    alice.car_husband.oil_change = 3'500;
    alice.car_husband.tax = 7'000;

    // Квартира (своя)
    alice.flat_1.housing_and_communal_servisec = 6'000;  // Коммуналка
    alice.flat_1.current_repairs = 1'000;
    alice.flat_1.household_chemicals = 1'000;
    alice.flat_1.checking_counters = 700;
    alice.flat_1.general_household_needs = 1'500;
    alice.flat_1.repair_of_large_household_appliances = 3'000;
    alice.flat_1.internet = 600;
    alice.flat_1.tv = 0;  // Не пользуются
    alice.flat_1.phone = 300;
    alice.flat_1.furniture_renewal = 2'000;
    alice.flat_1.curtains = 500;
    alice.flat_1.dishes = 500;
    alice.flat_1.cleaning_equipment = 500;
    alice.flat_1.air_conditioner_service = 0;  // Нет кондиционера
    alice.flat_1.water_filter = 500;
    alice.flat_1.insects_control = 300;
    alice.flat_1.new_lamps = 200;
    alice.flat_1.emergency_fund = 1'000;

    // Ипотека (если решат взять)
    alice.flat_2.loan_amount = 3'000'000;
    alice.flat_2.monthly_payment = 35'000;
    alice.flat_2.down_payment = 600'000;
    alice.flat_2.interest_rate = 9.5;
    alice.flat_2.property_insurance = 10'000;
    alice.flat_2.life_insurance = 3'000;
    alice.flat_2.appraisal = 5'000;
    alice.flat_2.notary = 7'000;
    alice.flat_2.state_fee = 2'000;
    alice.flat_2.bank_commission = 15'000;
    alice.flat_2.early_repayment = 0;
    alice.flat_2.penalty = 0;
    alice.flat_2.renovation = 200'000;
    alice.flat_2.furniture = 300'000;

    // Свадьба
    alice.wedding.restaurant = 150'000;
    alice.wedding.dress_and_suit = 80'000;
    alice.wedding.rings = 50'000;
    alice.wedding.photographer = 40'000;
    alice.wedding.videographer = 30'000;
    alice.wedding.makeup_artist = 8'000;
    alice.wedding.hairdresser = 5'000;
    alice.wedding.bouquet = 5'000;
    alice.wedding.boutonniere = 1'000;
    alice.wedding.transport = 15'000;
    alice.wedding.venue_decor = 25'000;
    alice.wedding.invitations = 5'000;
    alice.wedding.wedding_cake = 8'000;
    alice.wedding.alcohol = 20'000;
    alice.wedding.music = 15'000;
    alice.wedding.host = 20'000;
    alice.wedding.honeymoon = 100'000;
    alice.wedding.other_expenses = 30'000;
    alice.wedding.happened = false;

    // Ребенок (расходы только до 2 лет, т.к. промежуток 4 года)
    alice.child.initial_expenses = 100'000;  // Коляска, кроватка, комод
    alice.child.monthly_food = 3'000;        // Смеси, пюре (до 1 года)
    alice.child.diapers = 2'500;             // Подгузники
    alice.child.clothes = 3'000;              // Одежда (быстро растет)
    alice.child.medicine = 1'000;              // Лекарства, градусник и т.д.
    alice.child.toys = 1'500;                  // Погремушки, развивашки
    alice.child.kindergarten = 15'000;         // Ясли/сад (с 1.5 лет)
    alice.child.doctor_visits = 2'000;         // Платные врачи
    alice.child.vitamins = 800;                // Витамин Д и т.д.
    alice.child.dentist = 1'500;                // Стоматолог (редко)
    alice.child.child_birthday = 5'000;         // День рождения
    alice.child.babysitter = 10'000;            // Няня (изредка)
    alice.child.development = 2'000;            // Развивашки (с 1 года)
    alice.child.stroller = 15'000;              // Коляска (запасная)
    alice.child.car_seat = 8'000;                // Автокресло (2 шт)
    alice.child.high_chair = 3'000;              // Стульчик
    alice.child.playpen = 4'000;                 // Манеж
    alice.child.baby_monitor = 3'000;            // Радионяня
    alice.child.breastfeeding = 3'000;           // Бутылочки, молокоотсос
    alice.child.hygiene = 1'500;                  // Крема, присыпки
    alice.child.swimming = 2'000;                 // Бассейн (до года)
    alice.child.massage = 2'000;                   // Массаж (до года)
    alice.child.born = false;
    alice.child.age_months = 0;

    // Кот
    alice.cat.food = 1'500;
    alice.cat.treats = 300;
    alice.cat.veterinary = 500;
    alice.cat.vaccinations = 1'500;
    alice.cat.grooming = 0;  // Коты не требуют груминга обычно
    alice.cat.toys_for_pet = 300;
    alice.cat.bedding = 500;
    alice.cat.bowl = 200;
    alice.cat.carrier = 1'000;
    alice.cat.toilet_trainer = 500;
    alice.cat.filler = 800;
    alice.cat.claws_care = 300;
    alice.cat.pet_insurance = 0;  // Не популярно в РФ
    alice.cat.pet_sitting = 300;
    alice.cat.training = 0;  // Котов не дрессируют
    alice.cat.chip = 1'000;
    alice.cat.sterilization = 4'000;
    alice.cat.have_pet = false;

    // Хомяк
    alice.hamster.food = 200;
    alice.hamster.treats = 50;
    alice.hamster.veterinary = 200;
    alice.hamster.vaccinations = 0;
    alice.hamster.grooming = 0;
    alice.hamster.toys_for_pet = 100;
    alice.hamster.bedding = 200;
    alice.hamster.bowl = 100;
    alice.hamster.carrier = 300;
    alice.hamster.toilet_trainer = 200;
    alice.hamster.filler = 200;
    alice.hamster.pet_insurance = 0;
    alice.hamster.pet_sitting = 50;
    alice.hamster.training = 0;
    alice.hamster.chip = 0;
    alice.hamster.sterilization = 0;
    alice.hamster.have_pet = false;

    // Собака
    alice.dog.food = 2'500;
    alice.dog.treats = 500;
    alice.dog.veterinary = 700;
    alice.dog.vaccinations = 2'000;
    alice.dog.grooming = 1'000;
    alice.dog.toys_for_pet = 500;
    alice.dog.bedding = 700;
    alice.dog.bowl = 300;
    alice.dog.leash_and_collar = 500;
    alice.dog.carrier = 1'500;
    alice.dog.toilet_trainer = 300;
    alice.dog.filler = 0;  // Собаки на улице
    alice.dog.claws_care = 300;
    alice.dog.pet_insurance = 0;
    alice.dog.pet_sitting = 500;
    alice.dog.training = 1'500;
    alice.dog.chip = 1'000;
    alice.dog.sterilization = 5'000;
    alice.dog.have_pet = false;

    // Развод
    alice.divorce.lawyer_services = 50'000;
    alice.divorce.court_fee = 30'000;
    alice.divorce.property_division = 500'000;
    alice.divorce.alimony = 20'000; // ежемесячно
    alice.divorce.appraiser_services = 20'000;
    alice.divorce.notary_for_divorce = 10'000;
    alice.divorce.moving_expenses = 50'000;
    alice.divorce.separate_living = 30'000;
    alice.divorce.new_furniture = 100'000;
    alice.divorce.emotional_damage = 30'000;
    alice.divorce.psychotherapy = 5'000;
    alice.divorce.documents_reissue = 10'000;
    alice.divorce.bank_accounts_division = 5'000;
    alice.divorce.car_division = 300'000;
    alice.divorce.debt_division = 200'000;
    alice.divorce.happened = false;

    // Работа Алисы
    alice.alice_job.salary = 70'000;
    alice.alice_job.bonus = 10'000;
    alice.alice_job.thirteenth_salary = 70'000;
    alice.alice_job.sick_leave = 5'000;
    alice.alice_job.vacation_pay = 7'000;
    alice.alice_job.business_trip = 10'000;
    alice.alice_job.transportation = 1'000;
    alice.alice_job.lunch = 2'000;
    alice.alice_job.work_clothes = 2'000;
    alice.alice_job.training_courses = 5'000;
    alice.alice_job.professional_certificate = 3'000;
    alice.alice_job.literature = 1'000;
    alice.alice_job.software = 1'000;
    alice.alice_job.equipment = 10'000;
    alice.alice_job.internet_for_work = 500;
    alice.alice_job.phone_for_work = 500;
    alice.alice_job.workplace_rent = 0;
    alice.alice_job.taxes = 9'100; // 13% от зарплаты
    alice.alice_job.pension_contributions = 15'400; // 22%
    alice.alice_job.health_insurance = 3'000;
    alice.alice_job.employed = true;
    alice.alice_job.looking_for_job = false;

    // Работа мужа
    alice.husband_job.salary = 90'000;
    alice.husband_job.bonus = 15'000;
    alice.husband_job.thirteenth_salary = 90'000;
    alice.husband_job.sick_leave = 6'000;
    alice.husband_job.vacation_pay = 9'000;
    alice.husband_job.business_trip = 15'000;
    alice.husband_job.transportation = 1'500;
    alice.husband_job.lunch = 3'000;
    alice.husband_job.work_clothes = 3'000;
    alice.husband_job.training_courses = 7'000;
    alice.husband_job.professional_certificate = 4'000;
    alice.husband_job.literature = 1'500;
    alice.husband_job.software = 1'500;
    alice.husband_job.equipment = 15'000;
    alice.husband_job.internet_for_work = 500;
    alice.husband_job.phone_for_work = 500;
    alice.husband_job.workplace_rent = 0;
    alice.husband_job.taxes = 11'700;
    alice.husband_job.pension_contributions = 19'800;
    alice.husband_job.health_insurance = 4'000;
    alice.husband_job.employed = true;
    alice.husband_job.looking_for_job = false;

    // Общие параметры
    alice.on_maternity_leave = false;
    alice.married = false;
    alice.husband_alimony = 0;
    alice.random_income = 0;
    alice.random_expenses = 0;
    alice.inflation_protection = 0;
    alice.emergency_fund_personal = 30'000;
}

void alice_food(const int month, const int year)
{
    if (month == 12) alice.vtb.account_rub -= 3'000;  // Новый год

    Percent inflation_food = 10.0;
    switch (year) {
    case 2026: inflation_food = 11.5; break;
    case 2027: inflation_food = 12.0; break;
    case 2028: inflation_food = 11.0; break;
    case 2029: inflation_food = 10.5; break;
    }

    alice.food += static_cast<RUB>(alice.food * (inflation_food / 100.0 / 12.0));
    alice.husband_food += static_cast<RUB>(alice.husband_food * (inflation_food / 100.0 / 12.0));
    alice.eating_out += static_cast<RUB>(alice.eating_out * (inflation_food / 100.0 / 12.0));
    alice.delivery += static_cast<RUB>(alice.delivery * (inflation_food / 100.0 / 12.0));

    alice.vtb.account_rub -= alice.food;
    if (alice.married) {
        alice.vtb.account_rub -= alice.husband_food;
    }
    alice.vtb.account_rub -= alice.eating_out;
    alice.vtb.account_rub -= alice.delivery;
}

void alice_salary(const int month, const int year)
{
    // Индексация зарплат
    if (month == 1 && year > 2026) {
        alice.husband_salary = static_cast<RUB>(alice.husband_salary * 1.08);
        alice.salary = static_cast<RUB>(alice.salary * 1.07);

        // Обновляем в структурах работ
        alice.alice_job.salary = alice.salary;
        alice.husband_job.salary = alice.husband_salary;
    }

    // Декрет: с марта 2028 по март 2029
    if (year == 2028 && month == 3)
        alice.on_maternity_leave = true;
    if (year == 2029 && month == 3)
        alice.on_maternity_leave = false;

    // Расчет зарплаты Алисы
    RUB current_salary = alice.salary;
    if (alice.on_maternity_leave) {
        current_salary = static_cast<RUB>(current_salary * 0.4); // Пособие по уходу
    }

    // Премии (в декабре)
    if (month == 12) {
        current_salary += alice.alice_job.bonus;
        if (alice.married) {
            alice.husband_salary += alice.husband_job.bonus;
        }
    }

    // 13-я зарплата (в январе)
    if (month == 1) {
        current_salary += alice.alice_job.thirteenth_salary;
        if (alice.married) {
            alice.husband_salary += alice.husband_job.thirteenth_salary;
        }
    }

    // Начисление зарплаты
    alice.vtb.account_rub += current_salary;
    if (alice.married) {
        alice.vtb.account_rub += alice.husband_salary;
    }

    // Алименты, если есть развод и ребенок
    if (alice.divorce.happened && alice.child.born) {
        alice.vtb.account_rub += alice.divorce.alimony;
    }
}

void alice_car(Car& car, const int month, const int year)
{
    // Ежемесячные расходы
    alice.vtb.account_rub -= car.gas;
    alice.vtb.account_rub -= car.car_wash;
    alice.vtb.account_rub -= car.parking;

    // Сезонные расходы
    if (month == 10) { // Подготовка к зиме
        alice.vtb.account_rub -= car.winter_tires;
        alice.vtb.account_rub -= car.tire_change;
    }
    if (month == 4) { // Подготовка к лету
        alice.vtb.account_rub -= car.summer_tires;
        alice.vtb.account_rub -= car.tire_change;
    }

    // Ежегодные расходы
    if (month == 1) {
        alice.vtb.account_rub -= car.insurance;
        alice.vtb.account_rub -= car.tax;
    }

    // Техническое обслуживание (раз в 3 месяца)
    if (month % 3 == 0) {
        alice.vtb.account_rub -= car.maintenance;
        alice.vtb.account_rub -= car.oil_change;
    }

    // Диагностика (раз в 6 месяцев)
    if (month % 6 == 0) {
        alice.vtb.account_rub -= car.diagnostics;
    }
}

void alice_flat_1(const int month, const int year)
{
    Percent inflation_flat_1 = 10.0;
    switch (year) {
    case 2026: inflation_flat_1 = 11.5; break;
    case 2027: inflation_flat_1 = 13.0; break;
    case 2028: inflation_flat_1 = 12.0; break;
    case 2029: inflation_flat_1 = 11.0; break;
    }

    // Индексация ЖКХ
    alice.flat_1.housing_and_communal_servisec +=
        static_cast<RUB>(alice.flat_1.housing_and_communal_servisec * (inflation_flat_1 / 100.0 / 12.0));

    // Ежемесячные расходы
    alice.vtb.account_rub -= alice.flat_1.housing_and_communal_servisec;
    alice.vtb.account_rub -= alice.flat_1.current_repairs;
    alice.vtb.account_rub -= alice.flat_1.household_chemicals;
    alice.vtb.account_rub -= alice.flat_1.general_household_needs;
    alice.vtb.account_rub -= alice.flat_1.internet;
    alice.vtb.account_rub -= alice.flat_1.phone;
    alice.vtb.account_rub -= alice.flat_1.cleaning_equipment;
    alice.vtb.account_rub -= alice.flat_1.emergency_fund;

    // Расходы по четным/нечетным годам
    if (year % 2 == 0) {
        alice.vtb.account_rub -= alice.flat_1.checking_counters;
        alice.flat_1.general_household_needs += 500;
    }
    else {
        alice.flat_1.general_household_needs += 300;
    }

    // Периодические расходы
    if (month % 5 == 0) {
        alice.vtb.account_rub -= alice.flat_1.repair_of_large_household_appliances;
    }

    if (month % 3 == 0) {
        alice.vtb.account_rub -= alice.flat_1.water_filter;
    }
}

void alice_mortgage(const int month, const int year)
{
    // Ипотека берется в 2027 году, если есть свадьба
    static bool mortgage_taken = false;

    if (!mortgage_taken && alice.married && year == 2027 && month == 7) {
        alice.vtb.account_rub -= alice.flat_2.down_payment;
        alice.vtb.account_rub -= alice.flat_2.appraisal;
        alice.vtb.account_rub -= alice.flat_2.notary;
        alice.vtb.account_rub -= alice.flat_2.state_fee;
        alice.vtb.account_rub -= alice.flat_2.bank_commission;
        mortgage_taken = true;
    }

    if (mortgage_taken) {
        // Ежемесячный платеж
        alice.vtb.account_rub -= alice.flat_2.monthly_payment;
        alice.flat_2.loan_amount -= alice.flat_2.monthly_payment;

        // Проценты по ипотеке
        RUB interest = static_cast<RUB>(alice.flat_2.loan_amount * (alice.flat_2.interest_rate / 100.0 / 12.0));
        alice.vtb.account_rub -= interest;

        // Страховки раз в год
        if (month == 7) {
            alice.vtb.account_rub -= alice.flat_2.property_insurance;
            alice.vtb.account_rub -= alice.flat_2.life_insurance;
        }

        // Ремонт и мебель в первый год
        if (year == 2027 && month == 8) {
            alice.vtb.account_rub -= alice.flat_2.renovation / 6;
        }
        if (year == 2027 && month == 9) {
            alice.vtb.account_rub -= alice.flat_2.renovation / 6;
        }
        if (year == 2027 && month == 10) {
            alice.vtb.account_rub -= alice.flat_2.renovation / 6;
        }
        if (year == 2027 && month == 11) {
            alice.vtb.account_rub -= alice.flat_2.renovation / 6;
        }
        if (year == 2027 && month == 12) {
            alice.vtb.account_rub -= alice.flat_2.renovation / 6;
        }
        if (year == 2028 && month == 1) {
            alice.vtb.account_rub -= alice.flat_2.renovation / 6;
        }

        if (year == 2027 && month == 12) {
            alice.vtb.account_rub -= alice.flat_2.furniture / 2;
        }
        if (year == 2028 && month == 1) {
            alice.vtb.account_rub -= alice.flat_2.furniture / 2;
        }
    }
}

void alice_wedding(const int month, const int year)
{
    if (!alice.wedding.happened && year == 2026 && month == 8) {
        RUB total =
            alice.wedding.restaurant +
            alice.wedding.dress_and_suit +
            alice.wedding.rings +
            alice.wedding.photographer +
            alice.wedding.videographer +
            alice.wedding.makeup_artist +
            alice.wedding.hairdresser +
            alice.wedding.bouquet +
            alice.wedding.boutonniere +
            alice.wedding.transport +
            alice.wedding.venue_decor +
            alice.wedding.invitations +
            alice.wedding.wedding_cake +
            alice.wedding.alcohol +
            alice.wedding.music +
            alice.wedding.host +
            alice.wedding.honeymoon +
            alice.wedding.other_expenses;

        alice.vtb.account_rub -= total;
        alice.wedding.happened = true;
        alice.married = true;

        printf("Свадьба состоялась в %d.%d! Потрачено: %lld руб.\n", month, year, total);
    }
}

void alice_child(const int month, const int year)
{
    // Рождение ребенка через 9 месяцев после свадьбы
    if (!alice.child.born && alice.married && year == 2027 && month == 5) {
        alice.vtb.account_rub -= alice.child.initial_expenses;
        alice.child.born = true;
        alice.child.age_months = 0;
        printf("Ребенок родился в %d.%d!\n", month, year);
    }

    if (alice.child.born) {
        // Увеличиваем возраст ребенка
        alice.child.age_months++;

        Percent inflation_child = 9.0;
        switch (year) {
        case 2027: inflation_child = 10.0; break;
        case 2028: inflation_child = 11.0; break;
        case 2029: inflation_child = 9.0; break;
        }

        // Индексация расходов на ребенка (раз в полгода)
        if (month % 6 == 0) {
            alice.child.monthly_food += static_cast<RUB>(alice.child.monthly_food * (inflation_child / 100.0 / 2));
            alice.child.diapers += static_cast<RUB>(alice.child.diapers * (inflation_child / 100.0 / 2));
            alice.child.clothes += static_cast<RUB>(alice.child.clothes * (inflation_child / 100.0 / 2));
            alice.child.medicine += static_cast<RUB>(alice.child.medicine * (inflation_child / 100.0 / 2));
            alice.child.toys += static_cast<RUB>(alice.child.toys * (inflation_child / 100.0 / 2));
        }

        // Ежемесячные расходы (все возрасты до 2 лет)
        alice.vtb.account_rub -= alice.child.monthly_food;
        alice.vtb.account_rub -= alice.child.diapers;
        alice.vtb.account_rub -= alice.child.clothes;
        alice.vtb.account_rub -= alice.child.medicine;
        alice.vtb.account_rub -= alice.child.toys;
        alice.vtb.account_rub -= alice.child.hygiene;

        // Расходы по возрасту
        if (alice.child.age_months <= 12) { // До года
            if (month % 3 == 0) {
                alice.vtb.account_rub -= alice.child.swimming;
                alice.vtb.account_rub -= alice.child.massage;
            }
            alice.vtb.account_rub -= alice.child.breastfeeding / 3; // Бутылочки и т.д.
        }

        if (alice.child.age_months >= 6) { // С 6 месяцев - прикорм
            alice.child.monthly_food = 4'000; // Больше еды
        }

        if (alice.child.age_months >= 12) { // После года
            alice.child.diapers = 1'500; // Меньше подгузников
            alice.vtb.account_rub -= alice.child.development; // Развивашки
            alice.vtb.account_rub -= alice.child.car_seat / 12; // Новое кресло
        }

        if (alice.child.age_months >= 18) { // С 1.5 лет - ясли/сад
            alice.vtb.account_rub -= alice.child.kindergarten;
        }

        if (alice.child.age_months >= 24) { // С 2 лет - стоматолог
            if (month % 6 == 0) {
                alice.vtb.account_rub -= alice.child.dentist;
            }
        }

        // Регулярные медицинские расходы
        if (month % 2 == 0) {
            alice.vtb.account_rub -= alice.child.doctor_visits;
            alice.vtb.account_rub -= alice.child.vitamins;
        }

        // День рождения
        if (month == 5) { // Ребенок родился в мае
            alice.vtb.account_rub -= alice.child.child_birthday;
        }

        // Няня (изредка, если есть деньги)
        if (alice.vtb.account_rub > 200'000 && rand() % 10 == 0) {
            alice.vtb.account_rub -= alice.child.babysitter;
        }

        // Крупные покупки по мере роста
        if (alice.child.age_months == 12) {
            alice.vtb.account_rub -= alice.child.high_chair; // Стульчик для кормления
        }
        if (alice.child.age_months == 18) {
            alice.vtb.account_rub -= alice.child.playpen; // Манеж
        }
    }
}

void alice_pet(Pet& pet, const int month, const int year)
{
    if (!pet.have_pet) return;

    Percent inflation_pet = 9.0;

    // Ежемесячные расходы
    alice.vtb.account_rub -= pet.food;
    alice.vtb.account_rub -= pet.treats;
    alice.vtb.account_rub -= pet.filler;
    alice.vtb.account_rub -= pet.toys_for_pet / 3;

    // Периодические расходы
    if (month % 3 == 0) {
        alice.vtb.account_rub -= pet.veterinary;
        alice.vtb.account_rub -= pet.grooming;
    }

    if (month % 6 == 0) {
        alice.vtb.account_rub -= pet.vaccinations;
        alice.vtb.account_rub -= pet.claws_care;
    }

    if (month == 1) {
        alice.vtb.account_rub -= pet.bedding;
        alice.vtb.account_rub -= pet.carrier / 2;
    }
}

void alice_divorce(const int month, const int year)
{
    // Развод через 2 года после свадьбы, если есть ребенок и тяжелые времена
    if (!alice.divorce.happened && alice.married && alice.child.born &&
        year == 2029 && month == 3 && alice.vtb.account_rub < 100'000) {

        RUB total_divorce =
            alice.divorce.lawyer_services +
            alice.divorce.court_fee +
            alice.divorce.appraiser_services +
            alice.divorce.notary_for_divorce;

        alice.vtb.account_rub -= total_divorce;

        // Раздел имущества (упрощенно)
        alice.divorce.property_division = alice.vtb.account_rub / 2;
        alice.vtb.account_rub -= alice.divorce.property_division;

        alice.divorce.happened = true;
        alice.married = false;
        alice.husband_alimony = alice.divorce.alimony;

        printf("Развод состоялся в %d.%d\n", month, year);
    }
}

void alice_job_change(const int month, const int year)
{
    // Алиса теряет работу в кризис
    if (alice.alice_job.employed && year == 2028 && month == 10 && rand() % 100 < 20) {
        alice.alice_job.employed = false;
        alice.alice_job.looking_for_job = true;
        alice.salary = 0;
        printf("Алиса потеряла работу в %d.%d!\n", month, year);
    }

    // Поиск новой работы
    if (!alice.alice_job.employed && alice.alice_job.looking_for_job) {
        // Расходы на поиск работы
        if (month % 3 == 0) {
            alice.vtb.account_rub -= alice.alice_job.training_courses / 3;
        }

        // Шанс найти работу каждый месяц (увеличивается со временем)
        int chance = 10 + (2029 - year) * 5;
        if (rand() % 100 < chance) {
            alice.alice_job.employed = true;
            alice.alice_job.looking_for_job = false;
            alice.salary = alice.alice_job.salary * (1.0 + (rand() % 10) / 100.0);
            printf("Алиса нашла новую работу в %d.%d с зарплатой %lld руб.\n",
                month, year, alice.salary);
        }
    }
}

void alice_bank(const int month, const int year)
{
    // Проценты по депозиту (раз в год)
    if (month == 1) {
        RUB deposit_interest_rub = static_cast<RUB>(alice.vtb.deposit_rub * (alice.vtb.deposit_rate / 100.0));
        alice.vtb.deposit_rub += deposit_interest_rub;

        RUB deposit_interest_usd = static_cast<RUB>(alice.vtb.deposit_usd * 3.0 / 100.0); // 3% по валютному
        alice.vtb.deposit_usd += deposit_interest_usd;
    }

    // Дивиденды по акциям (раз в год)
    if (month == 12) {
        RUB dividends = static_cast<RUB>(alice.vtb.investment_stocks * 0.05);
        alice.vtb.account_rub += dividends;
    }

    // Купоны по облигациям (раз в полгода)
    if (month == 6 || month == 12) {
        RUB coupons = static_cast<RUB>(alice.vtb.investment_bonds * 0.04);
        alice.vtb.account_rub += coupons;
    }

    // Перевод излишков на депозит
    if (alice.vtb.account_rub > 200'000) {
        RUB transfer = (alice.vtb.account_rub - 100'000) / 2;
        alice.vtb.deposit_rub += transfer;
        alice.vtb.account_rub -= transfer;
    }
}

void print_results()
{
    printf("\n\n========== РЕЗУЛЬТАТЫ СИМУЛЯЦИИ (2026-2030) ==========\n\n");

    RUB total_income = 0;
    RUB total_expenses = 0;

    printf("=== ДОХОДЫ ===\n");
    printf("Финальная зарплата Алисы: %lld руб./мес\n", alice.salary);
    printf("Финальная зарплата мужа: %lld руб./мес\n", alice.husband_salary);

    printf("\n=== БАНКОВСКИЕ СЧЕТА ===\n");
    RUB capital = 0;
    capital += alice.vtb.account_rub;
    capital += static_cast<RUB>(alice.vtb.account_usd * alice.vtb.rate_usd_rub);
    capital += alice.vtb.deposit_rub;
    capital += static_cast<RUB>(alice.vtb.deposit_usd * alice.vtb.rate_usd_rub);
    capital += alice.vtb.investment_bonds;
    capital += alice.vtb.investment_stocks;

    printf("Рублевый счет: %lld руб.\n", alice.vtb.account_rub);
    printf("Валютный счет: %lld USD (%.0f руб.)\n", alice.vtb.account_usd,
        alice.vtb.account_usd * alice.vtb.rate_usd_rub);
    printf("Рублевый депозит: %lld руб.\n", alice.vtb.deposit_rub);
    printf("Валютный депозит: %lld USD\n", alice.vtb.deposit_usd);
    printf("Инвестиции (облигации): %lld руб.\n", alice.vtb.investment_bonds);
    printf("Инвестиции (акции): %lld руб.\n", alice.vtb.investment_stocks);
    printf("Задолженность по кредитке: %lld руб.\n", alice.vtb.credit_card_debt);

    printf("\n=== НЕДВИЖИМОСТЬ ===\n");
    capital += 5000000; // Примерная стоимость квартиры
    printf("Остаток по ипотеке: %lld руб.\n", alice.flat_2.loan_amount);
    if (alice.flat_2.loan_amount < 3000000) {
        printf("Выплачено ипотеки: %lld руб.\n", 3000000 - alice.flat_2.loan_amount);
    }

    printf("\n=== АВТОМОБИЛИ ===\n");
    capital += alice.car_alice.value;
    capital += alice.car_husband.value;
    printf("Машина Алисы: %lld руб.\n", alice.car_alice.value);
    printf("Машина мужа: %lld руб.\n", alice.car_husband.value);

    printf("\n=== СЕМЕЙНОЕ ПОЛОЖЕНИЕ ===\n");
    printf("Замужем: %s\n", alice.married ? "да" : "нет");
    printf("Свадьба состоялась: %s\n", alice.wedding.happened ? "да" : "нет");
    printf("Развод состоялся: %s\n", alice.divorce.happened ? "да" : "нет");
    printf("Ребенок родился: %s\n", alice.child.born ? "да" : "нет");
    if (alice.child.born) {
        printf("Возраст ребенка: %d месяцев (%.1f лет)\n",
            alice.child.age_months, alice.child.age_months / 12.0);
    }
    printf("В декрете: %s\n", alice.on_maternity_leave ? "да" : "нет");

    printf("\n=== ПИТОМЦЫ ===\n");
    printf("Кот: %s\n", alice.cat.have_pet ? "есть" : "нет");
    printf("Хомяк: %s\n", alice.hamster.have_pet ? "есть" : "нет");
    printf("Собака: %s\n", alice.dog.have_pet ? "есть" : "нет");

    printf("\n=== ТРУДОУСТРОЙСТВО ===\n");
    printf("Алиса работает: %s\n", alice.alice_job.employed ? "да" : "нет");
    printf("Муж работает: %s\n", alice.husband_job.employed ? "да" : "нет");

    printf("\n=== ОБЩИЙ КАПИТАЛ ===\n");
    printf("ИТОГО: %lld руб.\n", capital);

    // Динамика за 4 года
    printf("\n=== ДИНАМИКА ЗА 4 ГОДА ===\n");
    printf("Начальный капитал: 500,000 руб.\n");
    printf("Конечный капитал: %lld руб.\n", capital);
    printf("Изменение: %+lld руб. (%+.1f%%)\n",
        capital - 500000,
        (capital - 500000) * 100.0 / 500000);

    printf("\n==========================================\n");
}

void simulation()
{
    int year = 2026;
    int month = 1;  // Начинаем с января

    printf("НАЧАЛО СИМУЛЯЦИИ: Январь 2026\n");
    printf("========================================\n\n");

    while (!(year == 2030 && month == 1)) {
        // Зарплата и доходы
        alice_salary(month, year);

        // Расходы на автомобили
        alice_car(alice.car_alice, month, year);
        if (alice.married) {
            alice_car(alice.car_husband, month, year);
        }

        // Расходы на жилье
        alice_flat_1(month, year);
        alice_mortgage(month, year);

        // Семейные события
        alice_wedding(month, year);
        alice_child(month, year);
        alice_divorce(month, year);

        // Питомцы (заводим после свадьбы)
        if (alice.married && year >= 2027) {
            if (!alice.cat.have_pet && month == 9) {
                alice.cat.have_pet = true;
                alice.vtb.account_rub -= 10'000; // Покупка кота
                printf("Купили кота в %d.%d!\n", month, year);
            }
            if (!alice.dog.have_pet && alice.child.born && month == 10) {
                alice.dog.have_pet = true;
                alice.vtb.account_rub -= 15'000; // Покупка собаки
                printf("Купили собаку в %d.%d!\n", month, year);
            }
            if (!alice.hamster.have_pet && alice.child.born && month == 11) {
                alice.hamster.have_pet = true;
                alice.vtb.account_rub -= 2'000; // Покупка хомяка
                printf("Купили хомяка в %d.%d!\n", month, year);
            }
        }

        if (alice.cat.have_pet) {
            alice_pet(alice.cat, month, year);
        }
        if (alice.hamster.have_pet) {
            alice_pet(alice.hamster, month, year);
        }
        if (alice.dog.have_pet) {
            alice_pet(alice.dog, month, year);
        }

        // Работа
        alice_job_change(month, year);

        // Банковские операции
        alice_bank(month, year);

        // Еда
        alice_food(month, year);

        // Резервный фонд
        if (alice.vtb.account_rub > alice.emergency_fund_personal * 12) {
            RUB transfer = alice.vtb.account_rub / 10;
            alice.emergency_fund_personal += transfer;
            alice.vtb.account_rub -= transfer;
        }

        if (month == 12) {
            RUB capital = 0;
            capital += alice.vtb.account_rub;
            capital += alice.vtb.deposit_rub;
            capital += static_cast<RUB>(alice.vtb.account_usd * alice.vtb.rate_usd_rub);
            capital += static_cast<RUB>(alice.vtb.deposit_usd * alice.vtb.rate_usd_rub);
            capital += alice.vtb.investment_bonds;
            capital += alice.vtb.investment_stocks;
            capital += alice.car_alice.value;
            if (alice.married) {
                capital += alice.car_husband.value;
            }
            capital += 5000000;  // <--- ДОБАВИЛА СТОИМОСТЬ КВАРТИРЫ!

            printf("\n--- ИТОГИ %d ГОДА ---\n", year);
            printf("  Деньги на счетах: %lld руб.\n", alice.vtb.account_rub + alice.vtb.deposit_rub);
            printf("  Инвестиции: %lld руб.\n", alice.vtb.investment_bonds + alice.vtb.investment_stocks);
            printf("  Машины: %lld руб.\n", alice.car_alice.value + (alice.married ? alice.car_husband.value : 0));
            printf("  Квартира: 5,000,000 руб.\n");
            printf("  ОБЩИЙ КАПИТАЛ: %lld руб.\n", capital);
            printf("------------------\n\n");
        }

        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}

int main()
{
    // Инициализация генератора случайных чисел
    // Устанавливаем русскую локаль
    
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    alice_init();

    simulation();
    print_results();

    return 0;
}