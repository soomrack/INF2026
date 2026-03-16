#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

using Percent = float;
using RUB = long long int;
using USD = long long int;


struct Car {
    RUB value;
    RUB gas;
    RUB insurance;           // страховка ОСАГО/КАСКО
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

struct Subscriptions {
    RUB netflix;              // Netflix
    RUB spotify;              // Spotify
    RUB youtube_premium;      // YouTube Premium
    RUB icloud;               // iCloud
    RUB dropbox;              // Dropbox
    RUB adobe_cloud;          // Adobe Creative Cloud
    RUB chatgpt_plus;         // ChatGPT Plus
    RUB online_cinema;        // Онлайн-кинотеатры
    RUB fitness_app;          // Фитнес-приложения
    RUB password_manager;     // Менеджер паролей
    RUB vpn_service;          // VPN
    RUB alarm_clock_app;      // Будильник
    RUB forgotten_subscriptions;  // Забытые подписки
    bool has_subscriptions;   // Есть ли подписки
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
    RUB bank_commissions;     // Комиссии банка
    RUB sms_banking_fee;      // Плата за СМС-информирование
    RUB currency_exchange_loss; // Потери на обмене валют
    RUB atm_withdrawal_fee;    // Комиссия за снятие в чужих банкоматах
    RUB transfer_fees;         // Комиссии за переводы
};

struct TransactionCosts {
    RUB delivery_returns;      // Возвраты и пересылки
    RUB online_shopping;       // Онлайн-шопинг
    RUB return_shipping;       // Обратная доставка
    RUB failed_purchases;      // Неудачные покупки
    RUB late_fees;             // Пени за просрочки
    RUB fines_and_penalties;   // Штрафы
    RUB forgotten_payments;    // Забытые платежи
    RUB tax_penalties;         // Налоговые пени
};

struct EmotionalShopping {
    RUB stress_purchases;      // Покупки от стресса
    RUB boredom_shopping;      // Покупки от скуки
    RUB mood_boosters;         // Поднятие настроения
    RUB unneeded_items;        // Ненужные вещи
    RUB impulse_buys;          // Импульсивные покупки
    RUB comfort_shopping;      // Шопинг для комфорта
    RUB retail_therapy;        // Розничная терапия
    RUB unused_items;          // Вещи с бирками
};

struct ConvenienceFees {
    RUB corner_store_markup;   // Наценка магазина у дома
    RUB food_delivery;         // Доставка еды
    RUB ready_meals;           // Готовая еда
    RUB premium_products;      // Премиум-продукты
    RUB lazy_tax;              // Налог на лень
    RUB express_delivery;      // Экспресс-доставка
    RUB convenience_products;  // Товары для удобства
    RUB time_savers;           // Экономия времени
};

struct ProxySpending {
    RUB children_toys_adult;   // Игрушки для детей (хотят взрослые)
    RUB pet_luxury;            // Люксовые товары для питомцев
    RUB spouse_gifts_self;     // Подарки супругу (себе)
    RUB hobby_for_child;       // Хобби для ребенка (мечта родителя)
    RUB gadgets_for_family;    // Гаджеты для семьи
    RUB expensive_pet_items;   // Дорогие вещи для питомцев
    RUB child_dreams;          // Детские мечты взрослых
    RUB pet_humanization;      // Очеловечивание питомцев
};

struct SleepHealth {
    RUB orthopedic_mattress;   // Ортопедический матрас
    RUB expensive_pillows;     // Дорогие подушки
    RUB bedding_sets;          // Постельное белье
    RUB weighted_blanket;      // Утяжеленное одеяло
    RUB sleep_trackers;        // Трекеры сна
    RUB blackout_curtains;     // Блэкаут шторы
    RUB white_noise;           // Белый шум
    RUB sleep_aids;            // Средства для сна
    RUB sad_lamps;             // Лампы для светотерапии
    RUB vitamin_d;             // Витамин Д
    RUB winter_sun_trips;      // Поездки за солнцем
};

struct SocialCapital {
    RUB colleague_gifts;       // Подарки коллегам
    RUB teacher_gifts;         // Подарки учителям
    RUB relative_gifts;        // Подарки родственникам
    RUB work_contributions;    // Сборы на работе
    RUB friend_dinners;        // Ужины с друзьями
    RUB social_obligations;    // Социальные обязательства
    RUB networking_events;     // Нетворкинг
    RUB status_symbols;        // Символы статуса
};

struct IntangibleServices {
    RUB psychologist;          // Психолог
    RUB life_coach;            // Лайф-коуч
    RUB career_consultant;     // Карьерный консультант
    RUB astrologer;            // Астролог
    RUB tarot_reader;          // Таролог
    RUB personal_trainer;      // Персональный тренер
    RUB nutritionist;          // Диетолог
    RUB image_consultant;      // Имидж-консультант
};

struct SituationalPurchases {
    RUB corporate_outfit;      // Костюм на корпоратив
    RUB wedding_outfit;        // Наряд на свадьбу
    RUB special_equipment;     // Специальная экипировка
    RUB one_time_items;        // Одноразовые вещи
    RUB event_clothing;        // Одежда для мероприятий
    RUB theme_party_gear;      // Для тематических вечеринок
    RUB team_building_gear;    // Для тимбилдинга
};

struct PaidApps {
    RUB planner_app;           // Приложение-ежедневник
    RUB password_manager_app;  // Менеджер паролей
    RUB vpn_app;               // VPN приложение
    RUB sleep_app;             // Приложение для сна
    RUB meditation_app;        // Приложение для медитации
    RUB fitness_app_paid;      // Фитнес-приложение
    RUB language_learning;     // Изучение языков
    RUB productivity_tools;    // Инструменты продуктивности
};

struct LegalMistakes {
    RUB tax_unclaimed;         // Неоформленные налоговые вычеты
    RUB contract_violations;   // Нарушения договоров
    RUB late_tax_payment;      // Просрочка налогов
    RUB legal_ignorance;       // Юридическая безграмотность
    RUB document_errors;       // Ошибки в документах
    RUB missed_deadlines;      // Пропущенные сроки
    RUB unnecessary_fees;      // Излишние комиссии
};

struct FriendSupport {
    RUB paying_for_friends;    // Оплата за друзей
    RUB group_taxi;            // Такси для компании
    RUB shared_housing;        // Совместное жилье
    RUB friend_loans;          // Долги друзьям
    RUB entertainment_for_all; // Развлечения для всех
    RUB generous_treats;       // Щедрые угощения
    RUB unconscious_spending;  // Неосознанные траты на компанию
};

struct Flat {
    RUB housing_and_communal_servisec; // ЖКХ
    RUB current_repairs; // текущий ремонт
    RUB household_chemicals; // бытовая химия
    RUB general_household_needs; // общедомовые нужды
    RUB checking_counters; // проверка счётчиков
    RUB repair_of_large_household_appliances; // ремонт крупногабаритной техники
    RUB internet;              // интернет
    RUB tv;                    // телевидение
    RUB phone;                 // домашний телефон
    RUB furniture_renewal;     // обновление мебели
    RUB curtains;              // шторы/жалюзи
    RUB dishes;                // посуда
    RUB cleaning_equipment;    // инвентарь для уборки
    RUB air_conditioner_service; // обслуживание кондиционера
    RUB water_filter;          // фильтры для воды
    RUB insects_control;       // борьба с насекомыми
    RUB new_lamps;             // лампочки и светильники
    RUB emergency_fund;        // аварийный запас на непредвиденные расходы
};

struct Storage {
    RUB seasonal_tires_storage; // Хранение сезонных шин
    RUB bike_storage;           // Хранение велосипеда
    RUB self_storage_rent;      // Аренда склада
    RUB old_items_storage;      // Хранение старого хлама
    RUB warehouse_rent;         // Аренда кладовки
    bool has_storage;           // Есть ли аренда хранилища
};

struct Mortgage {
    RUB loan_amount; // сумма ипотеки
    RUB monthly_payment; // ежемесячный платеж
    RUB down_payment;      // первоначальный взнос
    float interest_rate;     // процентная ставка
    RUB property_insurance; // страховка квартиры
    RUB life_insurance;    // страховка жизни
    RUB appraisal;         // оценка квартиры
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
    RUB professional_certificate; // сертификаты
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

struct HealthAddiction {
    RUB gym_membership;          // абонемент в спортзал (премиум)
    RUB personal_trainer;        // персональный тренер
    RUB group_classes;           // групповые занятия (йога, кроссфит)
    RUB swimming_pool;           // бассейн
    RUB massage_therapist;       // массажист
    RUB osteopath;               // остеопат

    RUB sportswear;              // брендовая спортивная одежда
    RUB sneakers;                // кроссовки (по 2-3 пары в год)
    RUB fitness_tracker;         // фитнес-трекеры (Garmin, Apple Watch)
    RUB heart_rate_monitor;      // пульсометр
    RUB yoga_mat;                // коврики для йоги (премиум)
    RUB gym_equipment_home;      // домашний инвентарь (гантели, резинки)

    RUB protein;                 // протеин
    RUB bcaa;                    // BCAA
    RUB creatine;                // креатин
    RUB pre_workout;             // предтренировочные комплексы
    RUB vitamins_sports;         // спортивные витамины
    RUB omega3;                  // омега-3 (премиум)
    RUB collagen;                // коллаген
    RUB glutamine;               // глутамин

    RUB organic_vegetables;      // органические овощи
    RUB organic_meat;            // фермерское мясо
    RUB organic_chicken;         // фермерская курица
    RUB organic_eggs;            // фермерские яйца
    RUB organic_fish;            // дикая рыба (не фермерская)
    RUB organic_dairy;           // органические молочные
    RUB superfoods;              // суперфуды (киноа, чиа, годжи)
    RUB healthy_snacks;          // здоровые снеки (протеиновые батончики)
    RUB detox_water;             // детокс-вода, кокосовая вода
    RUB gluten_free;             // безглютеновые продукты
    RUB lactose_free;            // безлактозные продукты

    RUB cryotherapy;             // криотерапия
    RUB salt_cave;               // соляная пещера
    RUB hyperbaric_chamber;      // барокамера
    RUB iv_therapy;              // капельницы с витаминами
    RUB detox_programs;          // детокс-программы
    RUB fasting;                 // лечебное голодание (под наблюдением)

    int addiction_level;         // уровень зависимости (0-100)
    bool orthorexia;             // орторексия (патологическая тяга к здоровой пище)
    bool gym_addict;             // зависимость от тренировок
    bool body_dysmorphia;        // дисморфия тела (кажется себе толстым/хилым)
    bool counting_calories;      // маниакальный подсчет калорий
    bool weighing_food;          // взвешивание всей еды
    bool avoiding_social;        // отказ от встреч с едой вне дома

    RUB total_spent;             // всего потрачено на ЗОЖ
    RUB monthly_average;         // средние траты в месяц
    int years_pursuing;          // сколько лет "в теме"
    bool problem_addict;         // проблемная зависимость

    RUB food_scale;              // кухонные весы (премиум)
    RUB blenders;                // дорогие блендеры (Vitamix)
    RUB juicers;                 // соковыжималки (медленные)
    RUB food_containers;         // контейнеры для еды (стекло/бамбук)
    RUB meal_prep_services;      // услуги по готовке здоровой еды
    RUB nutritionist;            // диетолог/нутрициолог
    RUB food_analyzer;           // анализаторы состава тела

    bool food_adjusted;      
    bool eating_out_adjusted;
};
struct Inheritance {
    
    RUB amount;                 // сумма наследства
    int year_received;          // год получения
    int month_received;         // месяц получения
    bool received;              // получено ли уже

    
    bool from_grandmother;      // от бабушки
    bool from_distant_relative; // от дальнего родственника
    bool from_unexpected;       // неожиданное (лотерея, выигрыш)

    RUB cash;                   // наличные
    RUB apartment_value;        // квартира (если продали)
    RUB car_value;              // машина
    RUB jewelry;                // драгоценности
    RUB antiques;               // антиквариат

    RUB tax_on_inheritance;     // налог на наследство (в РФ 13% для неблизких)
    RUB notary_costs;           // нотариус
    RUB lawyer_costs;           // юрист
    RUB appraisal_costs;        // оценка имущества
    RUB debt_of_relative;       // долги умершего (если есть)

    bool was_expected;          // ожидаемое
    bool was_shock;             // шокирующее
    bool caused_family_drama;   // вызвало семейную драму
};

struct Person {
    Bank vtb;
    Subscriptions subs;
    TransactionCosts transactions;
    EmotionalShopping emotions;
    ConvenienceFees convenience;
    ProxySpending proxy;
    SleepHealth sleep;
    SocialCapital social;
    IntangibleServices intangible;
    SituationalPurchases situational;
    PaidApps paid_apps;
    LegalMistakes legal;
    FriendSupport friends;
    Storage storage;

    RUB salary; // зарплата Алисы
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

    HealthAddiction health;
    Inheritance inheritance;
};

struct Person alice;


void alice_init()
{
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 500'000;                    // рублевый счет
    alice.vtb.account_usd = 1'000;                       // валютный счет
    alice.vtb.credit_card_debt = 0;                      // задолженность по кредитке
    alice.vtb.credit_card_limit = 300'000;                // лимит кредитки
    alice.vtb.deposit_rub = 200'000;                      // рублевый депозит
    alice.vtb.deposit_usd = 500;                          // валютный депозит
    alice.vtb.deposit_rate = 8.5;                         // ставка по депозиту (%)
    alice.vtb.investment_bonds = 100'000;                 // облигации
    alice.vtb.investment_stocks = 50'000;                 // акции
    alice.vtb.bank_commissions = 300;                      // комиссии банка
    alice.vtb.sms_banking_fee = 99;                        // СМС-информирование
    alice.vtb.currency_exchange_loss = 200;                // потери на обмене валют
    alice.vtb.atm_withdrawal_fee = 150;                    // комиссия за снятие в чужих банкоматах
    alice.vtb.transfer_fees = 100;                         // комиссии за переводы

    
    alice.health.gym_membership = 5'000;           // премиум-абонемент
    alice.health.personal_trainer = 8'000;          // персональный тренер
    alice.health.group_classes = 3'000;             // йога/кроссфит
    alice.health.swimming_pool = 2'500;             // бассейн
    alice.health.massage_therapist = 3'500;         // массаж
    alice.health.osteopath = 4'000;                 // остеопат

    alice.health.sportswear = 5'000;                 // брендовая одежда
    alice.health.sneakers = 8'000;                   // кроссовки
    alice.health.fitness_tracker = 25'000;           // Apple Watch / Garmin
    alice.health.heart_rate_monitor = 5'000;         // пульсометр
    alice.health.yoga_mat = 3'000;                    // премиум-коврик
    alice.health.gym_equipment_home = 10'000;        // гантели, резинки

    alice.health.protein = 3'000;                     // протеин
    alice.health.bcaa = 1'500;                        // BCAA
    alice.health.creatine = 1'000;                    // креатин
    alice.health.pre_workout = 1'500;                 // предтреник
    alice.health.vitamins_sports = 2'000;             // спортивные витамины
    alice.health.omega3 = 1'500;                       // омега-3
    alice.health.collagen = 2'000;                     // коллаген
    alice.health.glutamine = 1'000;                    // глутамин

    alice.health.organic_vegetables = 4'000;          // органик овощи
    alice.health.organic_meat = 5'000;                 // фермерское мясо
    alice.health.organic_chicken = 3'000;              // фермерская курица
    alice.health.organic_eggs = 1'000;                 // фермерские яйца
    alice.health.organic_fish = 4'000;                 // дикая рыба
    alice.health.organic_dairy = 2'000;                // органик молочка
    alice.health.superfoods = 2'500;                   // киноа, чиа, годжи
    alice.health.healthy_snacks = 1'500;               // протеиновые батончики
    alice.health.detox_water = 1'000;                  // кокосовая вода
    alice.health.gluten_free = 1'500;                  // безглютеновое
    alice.health.lactose_free = 1'000;                 // безлактозное

    alice.health.cryotherapy = 2'500;                  // криотерапия
    alice.health.salt_cave = 1'000;                    // соляная пещера
    alice.health.hyperbaric_chamber = 5'000;           // барокамера
    alice.health.iv_therapy = 7'000;                   // капельницы
    alice.health.detox_programs = 15'000;              // детокс
    alice.health.fasting = 10'000;                      // голодание под контролем

    alice.health.addiction_level = 0;                   // уровень зависимости
    alice.health.orthorexia = false;                    // орторексия
    alice.health.gym_addict = false;                    // зависимость от тренировок
    alice.health.body_dysmorphia = false;               // дисморфия тела
    alice.health.counting_calories = false;             // подсчет калорий
    alice.health.weighing_food = false;                  // взвешивание еды
    alice.health.avoiding_social = false;                // отказ от встреч

    alice.health.total_spent = 0;                        // всего потрачено
    alice.health.monthly_average = 0;                    // средние траты
    alice.health.years_pursuing = 0;                      // сколько лет
    alice.health.problem_addict = false;                  // проблемная зависимость

    alice.health.food_scale = 3'000;                     // кухонные весы
    alice.health.blenders = 20'000;                       // Vitamix блендер
    alice.health.juicers = 15'000;                        // соковыжималка
    alice.health.food_containers = 2'000;                 // контейнеры
    alice.health.meal_prep_services = 10'000;             // готовая еда
    alice.health.nutritionist = 4'000;                    // диетолог
    alice.health.food_analyzer = 8'000;                   // анализатор тела

    alice.subs.netflix = 999;                                // Netflix
    alice.subs.spotify = 299;                                // Spotify
    alice.subs.youtube_premium = 399;                        // YouTube Premium
    alice.subs.icloud = 149;                                 // iCloud
    alice.subs.dropbox = 699;                                // Dropbox
    alice.subs.adobe_cloud = 1'899;                          // Adobe Creative Cloud
    alice.subs.chatgpt_plus = 999;                           // ChatGPT Plus
    alice.subs.online_cinema = 599;                          // Онлайн-кинотеатры
    alice.subs.fitness_app = 499;                            // Фитнес-приложения
    alice.subs.password_manager = 299;                       // Менеджер паролей
    alice.subs.vpn_service = 399;                            // VPN
    alice.subs.alarm_clock_app = 99;                         // Будильник
    alice.subs.forgotten_subscriptions = 500;                // Забытые подписки
    alice.subs.has_subscriptions = true;                     // Есть ли подписки

    alice.transactions.delivery_returns = 500;               // Возвраты и пересылки
    alice.transactions.online_shopping = 2'000;              // Онлайн-шопинг
    alice.transactions.return_shipping = 300;                // Обратная доставка
    alice.transactions.failed_purchases = 1'000;             // Неудачные покупки
    alice.transactions.late_fees = 300;                      // Пени за просрочки
    alice.transactions.fines_and_penalties = 500;            // Штрафы
    alice.transactions.forgotten_payments = 400;             // Забытые платежи
    alice.transactions.tax_penalties = 1'000;                // Налоговые пени

    alice.emotions.stress_purchases = 2'000;                 // Покупки от стресса
    alice.emotions.boredom_shopping = 1'500;                 // Покупки от скуки
    alice.emotions.mood_boosters = 1'000;                    // Поднятие настроения
    alice.emotions.unneeded_items = 1'200;                   // Ненужные вещи
    alice.emotions.impulse_buys = 1'800;                     // Импульсивные покупки
    alice.emotions.comfort_shopping = 1'300;                 // Шопинг для комфорта
    alice.emotions.retail_therapy = 1'600;                   // Розничная терапия
    alice.emotions.unused_items = 900;                       // Вещи с бирками

    alice.convenience.corner_store_markup = 1'000;           // Наценка магазина у дома
    alice.convenience.food_delivery = 2'000;                 // Доставка еды
    alice.convenience.ready_meals = 3'000;                   // Готовая еда
    alice.convenience.premium_products = 1'500;              // Премиум-продукты
    alice.convenience.lazy_tax = 1'200;                      // Налог на лень
    alice.convenience.express_delivery = 500;                // Экспресс-доставка
    alice.convenience.convenience_products = 800;            // Товары для удобства
    alice.convenience.time_savers = 600;                     // Экономия времени

    alice.proxy.children_toys_adult = 2'000;                 // Игрушки для детей (хотят взрослые)
    alice.proxy.pet_luxury = 1'500;                          // Люксовые товары для питомцев
    alice.proxy.spouse_gifts_self = 3'000;                   // Подарки супругу (себе)
    alice.proxy.hobby_for_child = 2'500;                     // Хобби для ребенка (мечта родителя)
    alice.proxy.gadgets_for_family = 4'000;                  // Гаджеты для семьи
    alice.proxy.expensive_pet_items = 1'200;                 // Дорогие вещи для питомцев
    alice.proxy.child_dreams = 1'800;                        // Детские мечты взрослых
    alice.proxy.pet_humanization = 900;                      // Очеловечивание питомцев

    alice.sleep.orthopedic_mattress = 15'000;                // Ортопедический матрас
    alice.sleep.expensive_pillows = 3'000;                   // Дорогие подушки
    alice.sleep.bedding_sets = 2'000;                        // Постельное белье
    alice.sleep.weighted_blanket = 4'000;                    // Утяжеленное одеяло
    alice.sleep.sleep_trackers = 2'500;                      // Трекеры сна
    alice.sleep.blackout_curtains = 3'000;                   // Блэкаут шторы
    alice.sleep.white_noise = 1'500;                         // Белый шум
    alice.sleep.sleep_aids = 1'000;                          // Средства для сна
    alice.sleep.sad_lamps = 5'000;                           // Лампы для светотерапии
    alice.sleep.vitamin_d = 800;                             // Витамин Д
    alice.sleep.winter_sun_trips = 30'000;                   // Поездки за солнцем

    alice.social.colleague_gifts = 1'000;                    // Подарки коллегам
    alice.social.teacher_gifts = 1'500;                      // Подарки учителям
    alice.social.relative_gifts = 2'000;                     // Подарки родственникам
    alice.social.work_contributions = 800;                   // Сборы на работе
    alice.social.friend_dinners = 2'500;                     // Ужины с друзьями
    alice.social.social_obligations = 1'200;                 // Социальные обязательства
    alice.social.networking_events = 3'000;                  // Нетворкинг
    alice.social.status_symbols = 5'000;                     // Символы статуса

    alice.intangible.psychologist = 4'000;                   // Психолог
    alice.intangible.life_coach = 5'000;                     // Лайф-коуч
    alice.intangible.career_consultant = 3'500;              // Карьерный консультант
    alice.intangible.astrologer = 2'000;                     // Астролог
    alice.intangible.tarot_reader = 1'800;                   // Таролог
    alice.intangible.personal_trainer = 3'000;               // Персональный тренер
    alice.intangible.nutritionist = 2'500;                   // Диетолог
    alice.intangible.image_consultant = 4'000;               // Имидж-консультант

    alice.situational.corporate_outfit = 5'000;              // Костюм на корпоратив
    alice.situational.wedding_outfit = 8'000;                // Наряд на свадьбу
    alice.situational.special_equipment = 3'000;             // Специальная экипировка
    alice.situational.one_time_items = 2'000;                // Одноразовые вещи
    alice.situational.event_clothing = 4'000;                // Одежда для мероприятий
    alice.situational.theme_party_gear = 2'500;              // Для тематических вечеринок
    alice.situational.team_building_gear = 1'500;            // Для тимбилдинга

    alice.paid_apps.planner_app = 500;                       // Приложение-ежедневник
    alice.paid_apps.password_manager_app = 300;              // Менеджер паролей
    alice.paid_apps.vpn_app = 400;                           // VPN приложение
    alice.paid_apps.sleep_app = 250;                         // Приложение для сна
    alice.paid_apps.meditation_app = 350;                    // Приложение для медитации
    alice.paid_apps.fitness_app_paid = 450;                  // Фитнес-приложение
    alice.paid_apps.language_learning = 600;                 // Изучение языков
    alice.paid_apps.productivity_tools = 550;                // Инструменты продуктивности

    alice.legal.tax_unclaimed = 5'000;                       // Неоформленные налоговые вычеты
    alice.legal.contract_violations = 2'000;                 // Нарушения договоров
    alice.legal.late_tax_payment = 1'000;                    // Просрочка налогов
    alice.legal.legal_ignorance = 3'000;                     // Юридическая безграмотность
    alice.legal.document_errors = 1'500;                     // Ошибки в документах
    alice.legal.missed_deadlines = 800;                      // Пропущенные сроки
    alice.legal.unnecessary_fees = 600;                      // Излишние комиссии

    alice.friends.paying_for_friends = 2'000;                // Оплата за друзей
    alice.friends.group_taxi = 800;                          // Такси для компании
    alice.friends.shared_housing = 5'000;                    // Совместное жилье
    alice.friends.friend_loans = 1'000;                      // Долги друзьям
    alice.friends.entertainment_for_all = 2'500;             // Развлечения для всех
    alice.friends.generous_treats = 1'500;                   // Щедрые угощения
    alice.friends.unconscious_spending = 1'200;              // Неосознанные траты на компанию

    alice.storage.seasonal_tires_storage = 3'000;            // Хранение сезонных шин
    alice.storage.bike_storage = 1'500;                      // Хранение велосипеда
    alice.storage.self_storage_rent = 5'000;                 // Аренда склада
    alice.storage.old_items_storage = 2'000;                 // Хранение старого хлама
    alice.storage.warehouse_rent = 2'500;                    // Аренда кладовки
    alice.storage.has_storage = false;                       // Есть ли аренда хранилища

    alice.salary = 700'000;                                    // зарплата Алисы
    alice.husband_salary = 900'000;                           // зарплата мужа

    alice.food = 10'000;                                      // еда для Алисы
    alice.husband_food = 10'000;                             // еда для мужа
    alice.eating_out = 5'000;                                // кафе/рестораны
    alice.delivery = 3'000;                                  // доставка еды

    alice.car_alice.value = 800'000;                         // стоимость машины
    alice.car_alice.gas = 5'000;                             // бензин
    alice.car_alice.insurance = 40'000;                      // страховка (в год)
    alice.car_alice.maintenance = 5'000;                     // техобслуживание
    alice.car_alice.winter_tires = 20'000;                   // зимняя резина
    alice.car_alice.summer_tires = 20'000;                   // летняя резина
    alice.car_alice.tire_change = 3'000;                     // шиномонтаж
    alice.car_alice.car_wash = 1'500;                        // мойка
    alice.car_alice.parking = 2'000;                         // парковка
    alice.car_alice.fines = 500;                             // штрафы
    alice.car_alice.diagnostics = 3'000;                     // диагностика
    alice.car_alice.oil_change = 3'000;                      // замена масла
    alice.car_alice.tax = 5'000;                             // транспортный налог

    alice.car_husband.value = 1'200'000;                     // стоимость машины
    alice.car_husband.gas = 7'000;                           // бензин
    alice.car_husband.insurance = 50'000;                    // страховка (в год)
    alice.car_husband.maintenance = 6'000;                   // техобслуживание
    alice.car_husband.winter_tires = 25'000;                 // зимняя резина
    alice.car_husband.summer_tires = 25'000;                 // летняя резина
    alice.car_husband.tire_change = 3'000;                   // шиномонтаж
    alice.car_husband.car_wash = 1'500;                      // мойка
    alice.car_husband.parking = 3'000;                       // парковка
    alice.car_husband.fines = 500;                           // штрафы
    alice.car_husband.diagnostics = 3'500;                   // диагностика
    alice.car_husband.oil_change = 3'500;                    // замена масла
    alice.car_husband.tax = 7'000;                           // транспортный налог

    alice.flat_1.housing_and_communal_servisec = 6'000;      // ЖКХ
    alice.flat_1.current_repairs = 1'000;                    // текущий ремонт
    alice.flat_1.household_chemicals = 1'000;                // бытовая химия
    alice.flat_1.general_household_needs = 1'500;            // общедомовые нужды
    alice.flat_1.checking_counters = 700;                    // проверка счётчиков
    alice.flat_1.repair_of_large_household_appliances = 3'000; // ремонт крупной техники
    alice.flat_1.internet = 600;                             // интернет
    alice.flat_1.tv = 0;                                     // телевидение
    alice.flat_1.phone = 300;                                // домашний телефон
    alice.flat_1.furniture_renewal = 2'000;                  // обновление мебели
    alice.flat_1.curtains = 500;                             // шторы/жалюзи
    alice.flat_1.dishes = 500;                               // посуда
    alice.flat_1.cleaning_equipment = 500;                   // инвентарь для уборки
    alice.flat_1.air_conditioner_service = 0;                // обслуживание кондиционера
    alice.flat_1.water_filter = 500;                         // фильтры для воды
    alice.flat_1.insects_control = 300;                      // борьба с насекомыми
    alice.flat_1.new_lamps = 200;                            // лампочки и светильники
    alice.flat_1.emergency_fund = 1'000;                     // аварийный запас

    alice.flat_2.loan_amount = 3'000'000;                    // сумма ипотеки
    alice.flat_2.monthly_payment = 35'000;                   // ежемесячный платеж
    alice.flat_2.down_payment = 600'000;                     // первоначальный взнос
    alice.flat_2.interest_rate = 9.5;                        // процентная ставка
    alice.flat_2.property_insurance = 10'000;                // страховка квартиры
    alice.flat_2.life_insurance = 3'000;                     // страховка жизни
    alice.flat_2.appraisal = 5'000;                          // оценка квартиры
    alice.flat_2.notary = 7'000;                             // нотариус
    alice.flat_2.state_fee = 2'000;                          // госпошлина
    alice.flat_2.bank_commission = 15'000;                   // комиссия банка
    alice.flat_2.early_repayment = 0;                        // досрочное погашение
    alice.flat_2.penalty = 0;                                // пеня за просрочку
    alice.flat_2.renovation = 200'000;                       // ремонт в ипотечной квартире
    alice.flat_2.furniture = 300'000;                        // мебель в ипотечную квартиру

    alice.wedding.restaurant = 150'000;                      // ресторан
    alice.wedding.dress_and_suit = 80'000;                   // платье и костюм
    alice.wedding.rings = 50'000;                            // кольца
    alice.wedding.photographer = 40'000;                     // фотограф
    alice.wedding.videographer = 30'000;                     // видеограф
    alice.wedding.makeup_artist = 8'000;                     // визажист
    alice.wedding.hairdresser = 5'000;                       // парикмахер
    alice.wedding.bouquet = 5'000;                           // букет невесты
    alice.wedding.boutonniere = 1'000;                       // бутоньерка
    alice.wedding.transport = 15'000;                        // транспорт для гостей
    alice.wedding.venue_decor = 25'000;                      // декор зала
    alice.wedding.invitations = 5'000;                       // приглашения
    alice.wedding.wedding_cake = 8'000;                      // свадебный торт
    alice.wedding.alcohol = 20'000;                          // алкоголь
    alice.wedding.music = 15'000;                            // музыкальное сопровождение
    alice.wedding.host = 20'000;                             // ведущий
    alice.wedding.honeymoon = 100'000;                       // медовый месяц
    alice.wedding.other_expenses = 30'000;                   // прочие расходы
    alice.wedding.happened = false;                          // состоялась ли свадьба

    alice.child.initial_expenses = 100'000;                  // роды, коляска, кроватка
    alice.child.monthly_food = 3'000;                        // питание (смеси, пюре)
    alice.child.diapers = 2'500;                             // подгузники
    alice.child.clothes = 3'000;                             // одежда
    alice.child.medicine = 1'000;                            // медицина
    alice.child.toys = 1'500;                                // игрушки
    alice.child.kindergarten = 15'000;                       // детский сад
    alice.child.doctor_visits = 2'000;                       // платные врачи
    alice.child.vitamins = 800;                              // витамины
    alice.child.dentist = 1'500;                             // стоматолог
    alice.child.child_birthday = 5'000;                      // день рождения
    alice.child.babysitter = 10'000;                         // няня
    alice.child.development = 2'000;                         // развивающие занятия
    alice.child.stroller = 15'000;                           // коляска
    alice.child.car_seat = 8'000;                            // автокресло
    alice.child.high_chair = 3'000;                          // стульчик для кормления
    alice.child.playpen = 4'000;                             // манеж
    alice.child.baby_monitor = 3'000;                        // радионяня
    alice.child.breastfeeding = 3'000;                       // молокоотсос, бутылочки
    alice.child.hygiene = 1'500;                             // присыпки, крема
    alice.child.swimming = 2'000;                            // бассейн/плавание
    alice.child.massage = 2'000;                              // массаж
    alice.child.born = false;                                // родился ли ребенок
    alice.child.age_months = 0;                              // возраст в месяцах

    alice.cat.food = 1'500;                                  // корм
    alice.cat.treats = 300;                                  // лакомства
    alice.cat.veterinary = 500;                              // ветеринар
    alice.cat.vaccinations = 1'500;                          // прививки
    alice.cat.grooming = 0;                                  // груминг
    alice.cat.toys_for_pet = 300;                            // игрушки
    alice.cat.bedding = 500;                                 // лежанка
    alice.cat.bowl = 200;                                    // миски
    alice.cat.carrier = 1'000;                               // переноска
    alice.cat.toilet_trainer = 500;                          // лоток
    alice.cat.filler = 800;                                  // наполнитель
    alice.cat.claws_care = 300;                              // когтеточка/стрижка
    alice.cat.pet_insurance = 0;                             // страховка
    alice.cat.pet_sitting = 300;                             // передержка
    alice.cat.training = 0;                                  // дрессировка
    alice.cat.chip = 1'000;                                  // чипирование
    alice.cat.sterilization = 4'000;                         // стерилизация
    alice.cat.have_pet = false;                              // есть ли питомец

    alice.hamster.food = 200;                                // корм
    alice.hamster.treats = 50;                               // лакомства
    alice.hamster.veterinary = 200;                          // ветеринар
    alice.hamster.vaccinations = 0;                          // прививки
    alice.hamster.grooming = 0;                              // груминг
    alice.hamster.toys_for_pet = 100;                        // игрушки
    alice.hamster.bedding = 200;                             // лежанка
    alice.hamster.bowl = 100;                                // миски
    alice.hamster.carrier = 300;                             // переноска
    alice.hamster.toilet_trainer = 200;                      // лоток
    alice.hamster.filler = 200;                              // наполнитель
    alice.hamster.pet_insurance = 0;                         // страховка
    alice.hamster.pet_sitting = 50;                          // передержка
    alice.hamster.training = 0;                              // дрессировка
    alice.hamster.chip = 0;                                  // чипирование
    alice.hamster.sterilization = 0;                         // стерилизация
    alice.hamster.have_pet = false;                          // есть ли питомец

    alice.dog.food = 2'500;                                  // корм
    alice.dog.treats = 500;                                  // лакомства
    alice.dog.veterinary = 700;                              // ветеринар
    alice.dog.vaccinations = 2'000;                          // прививки
    alice.dog.grooming = 1'000;                              // груминг
    alice.dog.toys_for_pet = 500;                            // игрушки
    alice.dog.bedding = 700;                                 // лежанка
    alice.dog.bowl = 300;                                    // миски
    alice.dog.leash_and_collar = 500;                        // поводок и ошейник
    alice.dog.carrier = 1'500;                               // переноска
    alice.dog.toilet_trainer = 300;                          // лоток/пеленки
    alice.dog.filler = 0;                                    // наполнитель
    alice.dog.claws_care = 300;                              // когтеточка/стрижка
    alice.dog.pet_insurance = 0;                             // страховка
    alice.dog.pet_sitting = 500;                             // передержка
    alice.dog.training = 1'500;                              // дрессировка
    alice.dog.chip = 1'000;                                  // чипирование
    alice.dog.sterilization = 5'000;                         // стерилизация
    alice.dog.have_pet = false;                              // есть ли питомец

    alice.divorce.lawyer_services = 50'000;                  // услуги адвоката
    alice.divorce.court_fee = 30'000;                        // госпошлина
    alice.divorce.property_division = 500'000;               // раздел имущества
    alice.divorce.alimony = 20'000;                          // алименты
    alice.divorce.appraiser_services = 20'000;               // оценщик
    alice.divorce.notary_for_divorce = 10'000;               // нотариус
    alice.divorce.moving_expenses = 50'000;                  // переезд
    alice.divorce.separate_living = 30'000;                  // отдельное проживание
    alice.divorce.new_furniture = 100'000;                   // новая мебель
    alice.divorce.emotional_damage = 30'000;                 // моральный ущерб
    alice.divorce.psychotherapy = 5'000;                     // психотерапевт
    alice.divorce.documents_reissue = 10'000;                // переоформление документов
    alice.divorce.bank_accounts_division = 5'000;            // раздел счетов
    alice.divorce.car_division = 300'000;                    // раздел авто
    alice.divorce.debt_division = 200'000;                   // раздел долгов
    alice.divorce.happened = false;                          // состоялся ли развод

    alice.alice_job.salary = 70'000;                         // зарплата
    alice.alice_job.bonus = 10'000;                          // премия
    alice.alice_job.thirteenth_salary = 70'000;              // 13-я зарплата
    alice.alice_job.sick_leave = 5'000;                      // больничный
    alice.alice_job.vacation_pay = 7'000;                    // отпускные
    alice.alice_job.business_trip = 10'000;                  // командировочные
    alice.alice_job.transportation = 1'000;                  // транспортные расходы
    alice.alice_job.lunch = 2'000;                           // обеды
    alice.alice_job.work_clothes = 2'000;                    // рабочая одежда
    alice.alice_job.training_courses = 5'000;                // курсы повышения квалификации
    alice.alice_job.professional_certificate = 3'000;        // сертификаты
    alice.alice_job.literature = 1'000;                      // профлитература
    alice.alice_job.software = 1'000;                        // ПО
    alice.alice_job.equipment = 10'000;                      // оборудование
    alice.alice_job.internet_for_work = 500;                 // интернет
    alice.alice_job.phone_for_work = 500;                    // телефон
    alice.alice_job.workplace_rent = 0;                      // аренда места
    alice.alice_job.taxes = 9'100;                           // налоги (13%)
    alice.alice_job.pension_contributions = 15'400;          // пенсионные (22%)
    alice.alice_job.health_insurance = 3'000;                // ДМС
    alice.alice_job.employed = true;                         // трудоустроена
    alice.alice_job.looking_for_job = false;                 // в поиске работы

    alice.husband_job.salary = 90'000;                       // зарплата
    alice.husband_job.bonus = 15'000;                        // премия
    alice.husband_job.thirteenth_salary = 90'000;            // 13-я зарплата
    alice.husband_job.sick_leave = 6'000;                    // больничный
    alice.husband_job.vacation_pay = 9'000;                  // отпускные
    alice.husband_job.business_trip = 15'000;                // командировочные
    alice.husband_job.transportation = 1'500;                // транспортные расходы
    alice.husband_job.lunch = 3'000;                         // обеды
    alice.husband_job.work_clothes = 3'000;                  // рабочая одежда
    alice.husband_job.training_courses = 7'000;              // курсы
    alice.husband_job.professional_certificate = 4'000;      // сертификаты
    alice.husband_job.literature = 1'500;                    // литература
    alice.husband_job.software = 1'500;                      // ПО
    alice.husband_job.equipment = 15'000;                    // оборудование
    alice.husband_job.internet_for_work = 500;               // интернет
    alice.husband_job.phone_for_work = 500;                  // телефон
    alice.husband_job.workplace_rent = 0;                    // аренда места
    alice.husband_job.taxes = 11'700;                        // налоги (13%)
    alice.husband_job.pension_contributions = 19'800;        // пенсионные (22%)
    alice.husband_job.health_insurance = 4'000;              // ДМС
    alice.husband_job.employed = true;                       // трудоустроен
    alice.husband_job.looking_for_job = false;               // в поиске работы

    alice.on_maternity_leave = false;                        // в декрете
    alice.married = false;                                   // замужем
    alice.husband_alimony = 0;                               // алименты от мужа
    alice.random_income = 0;                                 // случайные доходы
    alice.random_expenses = 0;                               // случайные расходы
    alice.inflation_protection = 0;                          // защита от инфляции
    alice.emergency_fund_personal = 30'000;                  // личный резервный фонд
    alice.inheritance.amount = 0;
    alice.inheritance.year_received = 0;
    alice.inheritance.month_received = 0;
    alice.inheritance.received = false;

    alice.inheritance.from_grandmother = false;
    alice.inheritance.from_distant_relative = false;
    alice.inheritance.from_unexpected = false;

    alice.inheritance.cash = 0;
    alice.inheritance.apartment_value = 0;
    alice.inheritance.car_value = 0;
    alice.inheritance.jewelry = 0;
    alice.inheritance.antiques = 0;

    alice.inheritance.tax_on_inheritance = 0;
    alice.inheritance.notary_costs = 0;
    alice.inheritance.lawyer_costs = 0;
    alice.inheritance.appraisal_costs = 0;
    alice.inheritance.debt_of_relative = 0;

    alice.inheritance.was_expected = false;
    alice.inheritance.was_shock = false;
    alice.inheritance.caused_family_drama = false;
    alice.health.food_adjusted = false;
    alice.health.eating_out_adjusted = false;
}


void alice_bank_fees(const int month, const int year) {
    
    alice.vtb.account_rub -= alice.vtb.sms_banking_fee;

    if (rand() % 100 < 30) {
        alice.vtb.account_rub -= alice.vtb.transfer_fees;
    }

    if (alice.vtb.account_usd > 0 && month % 3 == 0) {
        alice.vtb.currency_exchange_loss = static_cast<RUB>(alice.vtb.account_usd * 0.01 * alice.vtb.rate_usd_rub);
        alice.vtb.account_rub -= alice.vtb.currency_exchange_loss;
    }

    if (rand() % 100 < 20) {
        alice.vtb.account_rub -= alice.vtb.atm_withdrawal_fee;
    }
}

void alice_subscriptions(const int month, const int year) {
    if (!alice.subs.has_subscriptions) return;

    RUB total_subs = 0;
    
    total_subs += alice.subs.netflix;
    total_subs += alice.subs.spotify;
    total_subs += alice.subs.youtube_premium;
    total_subs += alice.subs.icloud;
    total_subs += alice.subs.dropbox;
    total_subs += alice.subs.adobe_cloud;
    total_subs += alice.subs.chatgpt_plus;
    total_subs += alice.subs.online_cinema;
    total_subs += alice.subs.fitness_app;
    total_subs += alice.subs.password_manager;
    total_subs += alice.subs.vpn_service;
    total_subs += alice.subs.alarm_clock_app;
    
    if (month % 3 == 0) {
        total_subs += alice.subs.forgotten_subscriptions;
    }

    alice.vtb.account_rub -= total_subs;
}

void alice_transaction_costs(const int month, const int year) {
    RUB total_costs = 0;

    if (rand() % 100 < 40) {
        total_costs += alice.transactions.return_shipping;
        total_costs += alice.transactions.delivery_returns / 2;
    }

    if (rand() % 100 < 10) {
        total_costs += alice.transactions.late_fees;
    }

    if (month == 4 && year > 2026) {
        total_costs += alice.transactions.tax_penalties;
    }

    alice.vtb.account_rub -= total_costs;
}

void alice_emotional_spending(const int month, const int year) {
    RUB emotional_total = 0;

    if (alice.vtb.account_rub < 100'000) {
        emotional_total += alice.emotions.stress_purchases;
    }

    if (rand() % 100 < 30) {
        emotional_total += alice.emotions.impulse_buys / 2;
    }
    
    if (rand() % 100 < 25) {
        emotional_total += alice.emotions.retail_therapy;
    }

    alice.vtb.account_rub -= emotional_total;
    
    if (emotional_total > 0) {
        alice.emotions.unused_items += emotional_total * 0.3;
    }
}

void alice_convenience_spending(const int month, const int year) {
    RUB convenience_total = 0;

    if (rand() % 100 < 60) {
        convenience_total += alice.convenience.corner_store_markup;
    }

    if (alice.on_maternity_leave) {
        convenience_total += alice.convenience.food_delivery * 2;
        convenience_total += alice.convenience.ready_meals;
    }

    if (rand() % 100 < 15) {
        convenience_total += alice.convenience.express_delivery;
    }

    alice.vtb.account_rub -= convenience_total;
}

void alice_proxy_spending(const int month, const int year) {
    RUB proxy_total = 0;

    if (alice.child.born) {
   
        if (rand() % 100 < 20) {
            proxy_total += alice.proxy.children_toys_adult;
        }

        if (alice.child.age_months > 12 && rand() % 100 < 15) {
            proxy_total += alice.proxy.hobby_for_child;
        }
    }

    if (alice.cat.have_pet || alice.dog.have_pet) {
        if (rand() % 100 < 10) {
            proxy_total += alice.proxy.pet_luxury;
            proxy_total += alice.proxy.expensive_pet_items;
        }
    }

    alice.vtb.account_rub -= proxy_total;
}

void alice_sleep_health(const int month, const int year) {
    
    if (month == 11 && year == 2027) {
        alice.vtb.account_rub -= alice.sleep.orthopedic_mattress;
        alice.vtb.account_rub -= alice.sleep.expensive_pillows;
    }

    if (month == 10 && year == 2028) {
        alice.vtb.account_rub -= alice.sleep.weighted_blanket;
        alice.vtb.account_rub -= alice.sleep.blackout_curtains;
    }

    if (month >= 10 || month <= 3) {
        alice.vtb.account_rub -= alice.sleep.vitamin_d;
    }

    if (month == 1 && alice.married && year >= 2027) {
        alice.vtb.account_rub -= alice.sleep.winter_sun_trips;
    }
}

void alice_social_capital(const int month, const int year) {
    RUB social_total = 0;

    if (rand() % 100 < 30) {
        social_total += alice.social.colleague_gifts;
    }

    if (rand() % 100 < 40) {
        social_total += alice.social.work_contributions;
    }

    if (month == 12) {
        social_total += alice.social.relative_gifts * 3; // новый год
    }

    if (month == 2) {
        social_total += alice.social.relative_gifts; // 23 февраля
    }

    if (month == 3) {
        social_total += alice.social.relative_gifts; // 8 марта
    }

    alice.vtb.account_rub -= social_total;
}

void alice_intangible_services(const int month, const int year) {
    RUB intangible_total = 0;

    if (alice.divorce.happened || alice.vtb.account_rub < 50'000) {
        intangible_total += alice.intangible.psychologist;
    }

    if (alice.alice_job.looking_for_job) {
        intangible_total += alice.intangible.career_consultant;
    }

    if (alice.vtb.account_rub < 30'000 && rand() % 100 < 20) {
        intangible_total += alice.intangible.astrologer;
        intangible_total += alice.intangible.tarot_reader;
    }

    alice.vtb.account_rub -= intangible_total;
}

void alice_situational_purchases(const int month, const int year) {
    RUB situational_total = 0;

    if (month == 11 && year == 2027 && alice.alice_job.employed) {
        situational_total += alice.situational.corporate_outfit;
    }

    if (month == 6 && year == 2028 && alice.married) {
        situational_total += alice.situational.wedding_outfit;
    }

    if (month == 5 && year == 2027 && alice.alice_job.employed) {
        situational_total += alice.situational.team_building_gear;
    }

    alice.vtb.account_rub -= situational_total;
}

void alice_paid_apps(const int month, const int year) {
    RUB apps_total = 0;

    apps_total += alice.paid_apps.planner_app;
    apps_total += alice.paid_apps.password_manager_app;
    apps_total += alice.paid_apps.vpn_app;
    apps_total += alice.paid_apps.sleep_app;
    apps_total += alice.paid_apps.meditation_app;
    apps_total += alice.paid_apps.fitness_app_paid;
    apps_total += alice.paid_apps.language_learning;
    apps_total += alice.paid_apps.productivity_tools;

    alice.vtb.account_rub -= apps_total;
}

void alice_legal_mistakes(const int month, const int year) {
    RUB legal_total = 0;
    
    if (month == 4 && year == 2028) {
        legal_total += alice.legal.tax_unclaimed;
    }
   
    if (rand() % 100 < 5) {
        legal_total += alice.legal.contract_violations;
    }

    if (rand() % 100 < 8) {
        legal_total += alice.legal.document_errors;
    }

    alice.vtb.account_rub -= legal_total;
}

void alice_friend_support(const int month, const int year) {
    RUB friend_total = 0;

    if (rand() % 100 < 25 && alice.eating_out > 0) {
        friend_total += alice.friends.paying_for_friends;
    }

    if (rand() % 100 < 30 && alice.eating_out > 0) {
        friend_total += alice.friends.group_taxi;
    }

    if (alice.married && alice.eating_out > 0) {
        friend_total += alice.friends.unconscious_spending;
    }

    alice.vtb.account_rub -= friend_total;
}

void alice_storage(const int month, const int year) {
    if (!alice.storage.has_storage) return;

    RUB storage_total = 0;

    storage_total += alice.storage.self_storage_rent;

    if (month == 4 || month == 10) {
        storage_total += alice.storage.seasonal_tires_storage;
    }

    alice.vtb.account_rub -= storage_total;
}

void alice_food(const int month, const int year)
{
    if (month == 12) alice.vtb.account_rub -= 3'000;  // новый год

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
    if (month == 1 && year > 2026) {
        if (alice.alice_job.employed) {
            alice.salary = static_cast<RUB>(alice.salary * 1.07);
            alice.alice_job.salary = alice.salary;
        }
        if (alice.husband_job.employed && alice.married) {
            alice.husband_salary = static_cast<RUB>(alice.husband_salary * 1.08);
            alice.husband_job.salary = alice.husband_salary;
        }
    }

    if (year == 2028 && month == 3)
        alice.on_maternity_leave = true;
    if (year == 2029 && month == 3)
        alice.on_maternity_leave = false;

    RUB current_salary = 0;

    if (alice.alice_job.employed) {
        current_salary = alice.salary;

        if (alice.on_maternity_leave) {
            current_salary = static_cast<RUB>(current_salary * 0.4); 
        }

        if (month == 12) {
            current_salary += alice.alice_job.bonus;
        }

        if (month == 1) {
            current_salary += alice.alice_job.thirteenth_salary;
        }
    }
    
    alice.vtb.account_rub += current_salary;

    if (alice.married && alice.husband_job.employed) {
        RUB husband_current = alice.husband_salary;

        if (month == 12) {
            husband_current += alice.husband_job.bonus;
        }
        if (month == 1) {
            husband_current += alice.husband_job.thirteenth_salary;
        }

        alice.vtb.account_rub += husband_current;
    }

    if (alice.divorce.happened && alice.child.born) {
        alice.vtb.account_rub += alice.divorce.alimony;
    }
}

void alice_car(Car& car, const int month, const int year)
{
    alice.vtb.account_rub -= car.gas;
    alice.vtb.account_rub -= car.car_wash;
    alice.vtb.account_rub -= car.parking;

    if (month == 10) {
        alice.vtb.account_rub -= car.winter_tires;
        alice.vtb.account_rub -= car.tire_change;
    }
    if (month == 4) {
        alice.vtb.account_rub -= car.summer_tires;
        alice.vtb.account_rub -= car.tire_change;
    }

    if (month == 1) {
        alice.vtb.account_rub -= car.insurance;
        alice.vtb.account_rub -= car.tax;
    }

    if (month % 3 == 0) {
        alice.vtb.account_rub -= car.maintenance;
        alice.vtb.account_rub -= car.oil_change;
    }

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

    alice.flat_1.housing_and_communal_servisec +=
        static_cast<RUB>(alice.flat_1.housing_and_communal_servisec * (inflation_flat_1 / 100.0 / 12.0));

    alice.vtb.account_rub -= alice.flat_1.housing_and_communal_servisec;
    alice.vtb.account_rub -= alice.flat_1.current_repairs;
    alice.vtb.account_rub -= alice.flat_1.household_chemicals;
    alice.vtb.account_rub -= alice.flat_1.general_household_needs;
    alice.vtb.account_rub -= alice.flat_1.internet;
    alice.vtb.account_rub -= alice.flat_1.phone;
    alice.vtb.account_rub -= alice.flat_1.cleaning_equipment;
    alice.vtb.account_rub -= alice.flat_1.emergency_fund;

    if (year % 2 == 0) {
        alice.vtb.account_rub -= alice.flat_1.checking_counters;
        alice.flat_1.general_household_needs += 500;
    }
    else {
        alice.flat_1.general_household_needs += 300;
    }

    if (month % 5 == 0) {
        alice.vtb.account_rub -= alice.flat_1.repair_of_large_household_appliances;
    }

    if (month % 3 == 0) {
        alice.vtb.account_rub -= alice.flat_1.water_filter;
    }
}

void alice_mortgage(const int month, const int year)
{
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
        alice.vtb.account_rub -= alice.flat_2.monthly_payment;
        alice.flat_2.loan_amount -= alice.flat_2.monthly_payment;

        RUB interest = static_cast<RUB>(alice.flat_2.loan_amount * (alice.flat_2.interest_rate / 100.0 / 12.0));
        alice.vtb.account_rub -= interest;

        if (month == 7) {
            alice.vtb.account_rub -= alice.flat_2.property_insurance;
            alice.vtb.account_rub -= alice.flat_2.life_insurance;
        }

        if (year == 2027 && month == 8) alice.vtb.account_rub -= alice.flat_2.renovation / 6;
        if (year == 2027 && month == 9) alice.vtb.account_rub -= alice.flat_2.renovation / 6;
        if (year == 2027 && month == 10) alice.vtb.account_rub -= alice.flat_2.renovation / 6;
        if (year == 2027 && month == 11) alice.vtb.account_rub -= alice.flat_2.renovation / 6;
        if (year == 2027 && month == 12) alice.vtb.account_rub -= alice.flat_2.renovation / 6;
        if (year == 2028 && month == 1) alice.vtb.account_rub -= alice.flat_2.renovation / 6;

        if (year == 2027 && month == 12) alice.vtb.account_rub -= alice.flat_2.furniture / 2;
        if (year == 2028 && month == 1) alice.vtb.account_rub -= alice.flat_2.furniture / 2;
    }
}

void alice_wedding(const int month, const int year)
{
    if (!alice.wedding.happened && year == 2026 && month == 8) {
        RUB total =alice.wedding.restaurant + alice.wedding.dress_and_suit + alice.wedding.rings + alice.wedding.photographer + alice.wedding.videographer + alice.wedding.makeup_artist + alice.wedding.hairdresser + alice.wedding.bouquet +alice.wedding.boutonniere +
            alice.wedding.transport + alice.wedding.venue_decor + alice.wedding.invitations + alice.wedding.wedding_cake + alice.wedding.alcohol + alice.wedding.music + alice.wedding.host +alice.wedding.honeymoon + alice.wedding.other_expenses;

        alice.vtb.account_rub -= total;
        alice.wedding.happened = true;
        alice.married = true;

        printf("cвадьба состоялась в %d.%d! потрачено: %lld руб.\n", month, year, total);
    }
}


void alice_child(const int month, const int year)
{
    if (!alice.child.born && alice.married && year == 2027 && month == 5) {
        alice.vtb.account_rub -= alice.child.initial_expenses;
        alice.child.born = true;
        alice.child.age_months = 0;
        printf("ребенок родился в %d.%d!\n", month, year);
    }

    if (alice.child.born) {
        alice.child.age_months++;

        Percent inflation_child = 9.0;
        switch (year) {
        case 2027: inflation_child = 10.0; break;
        case 2028: inflation_child = 11.0; break;
        case 2029: inflation_child = 9.0; break;
        }

        if (month % 6 == 0) {
            alice.child.monthly_food += static_cast<RUB>(alice.child.monthly_food * (inflation_child / 100.0 / 2));
            alice.child.diapers += static_cast<RUB>(alice.child.diapers * (inflation_child / 100.0 / 2));
            alice.child.clothes += static_cast<RUB>(alice.child.clothes * (inflation_child / 100.0 / 2));
            alice.child.medicine += static_cast<RUB>(alice.child.medicine * (inflation_child / 100.0 / 2));
            alice.child.toys += static_cast<RUB>(alice.child.toys * (inflation_child / 100.0 / 2));
        }

        alice.vtb.account_rub -= alice.child.monthly_food;
        alice.vtb.account_rub -= alice.child.diapers;
        alice.vtb.account_rub -= alice.child.clothes;
        alice.vtb.account_rub -= alice.child.medicine;
        alice.vtb.account_rub -= alice.child.toys;
        alice.vtb.account_rub -= alice.child.hygiene;

        if (alice.child.age_months <= 12) {
            if (month % 3 == 0) {
                alice.vtb.account_rub -= alice.child.swimming;
                alice.vtb.account_rub -= alice.child.massage;
            }
            alice.vtb.account_rub -= alice.child.breastfeeding / 3;
        }

        if (alice.child.age_months >= 6) {
            alice.child.monthly_food = 4'000;
        }

        if (alice.child.age_months >= 12) {
            alice.child.diapers = 1'500;
            alice.vtb.account_rub -= alice.child.development;
            alice.vtb.account_rub -= alice.child.car_seat / 12;
        }

        if (alice.child.age_months >= 18) {
            alice.vtb.account_rub -= alice.child.kindergarten;
        }

        if (alice.child.age_months >= 24) {
            if (month % 6 == 0) {
                alice.vtb.account_rub -= alice.child.dentist;
            }
        }

        if (month % 2 == 0) {
            alice.vtb.account_rub -= alice.child.doctor_visits;
            alice.vtb.account_rub -= alice.child.vitamins;
        }

        if (month == 5) {
            alice.vtb.account_rub -= alice.child.child_birthday;
        }

        if (alice.vtb.account_rub > 200'000 && rand() % 10 == 0) {
            alice.vtb.account_rub -= alice.child.babysitter;
        }

        if (alice.child.age_months == 12) {
            alice.vtb.account_rub -= alice.child.high_chair;
        }
        if (alice.child.age_months == 18) {
            alice.vtb.account_rub -= alice.child.playpen;
        }
    }
}


void alice_pet(Pet& pet, const int month, const int year)
{
    if (!pet.have_pet) return;

    Percent inflation_pet = 9.0;

    alice.vtb.account_rub -= pet.food;
    alice.vtb.account_rub -= pet.treats;
    alice.vtb.account_rub -= pet.filler;
    alice.vtb.account_rub -= pet.toys_for_pet / 3;

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
    if (!alice.divorce.happened && alice.married && alice.child.born &&
        year == 2029 && month == 3 && alice.vtb.account_rub < 100'000) {

        RUB total_divorce =
            alice.divorce.lawyer_services +
            alice.divorce.court_fee +
            alice.divorce.appraiser_services +
            alice.divorce.notary_for_divorce;

        alice.vtb.account_rub -= total_divorce;

        alice.divorce.property_division = alice.vtb.account_rub / 2;
        alice.vtb.account_rub -= alice.divorce.property_division;

        alice.divorce.happened = true;
        alice.married = false;
        alice.husband_alimony = alice.divorce.alimony;

        printf("развод состоялся в %d.%d\n", month, year);
    }
}


void alice_job_change(const int month, const int year)
{
    
    if (alice.alice_job.employed && year == 2028 && month == 10 && rand() % 100 < 20) {
        alice.alice_job.employed = false;
        alice.alice_job.looking_for_job = true;
        alice.salary = 0;
        printf("Алиса потеряла работу в %d.%d!\n", month, year);
    }
    
    if (!alice.alice_job.employed && alice.alice_job.looking_for_job) {
        alice.salary = 0;

        if (month % 3 == 0) {
            alice.vtb.account_rub -= alice.alice_job.training_courses / 3;
        }
        
        int chance = 10 + (2029 - year) * 5;
        if (rand() % 100 < chance) {
            alice.alice_job.employed = true;
            alice.alice_job.looking_for_job = false;
            
            RUB new_salary = alice.alice_job.salary * (1.0 + (rand() % 20) / 100.0);
            alice.salary = new_salary;
            printf("Алиса нашла новую работу в %d.%d с зарплатой %lld руб.\n",
                month, year, alice.salary);
        }
    }
}


void alice_bank(const int month, const int year)
{
    if (month == 1) {
        RUB deposit_interest_rub = static_cast<RUB>(alice.vtb.deposit_rub * (alice.vtb.deposit_rate / 100.0));
        alice.vtb.deposit_rub += deposit_interest_rub;

        RUB deposit_interest_usd = static_cast<RUB>(alice.vtb.deposit_usd * 3.0 / 100.0);
        alice.vtb.deposit_usd += deposit_interest_usd;
    }

    if (month == 12) {
        RUB dividends = static_cast<RUB>(alice.vtb.investment_stocks * 0.05);
        alice.vtb.account_rub += dividends;
    }

    if (month == 6 || month == 12) {
        RUB coupons = static_cast<RUB>(alice.vtb.investment_bonds * 0.04);
        alice.vtb.account_rub += coupons;
    }

    if (alice.vtb.account_rub > 200'000) {
        RUB transfer = (alice.vtb.account_rub - 100'000) / 2;
        alice.vtb.deposit_rub += transfer;
        alice.vtb.account_rub -= transfer;
    }
}


void alice_health_addiction(const int month, const int year) {
    
    if (!alice.health.problem_addict && alice.health.addiction_level == 0) {
        int start_chance = 10; 

        if (year >= 2028) {
            start_chance = 20;
        }

        if (rand() % 100 < start_chance) {
            alice.health.addiction_level = 15;
            alice.health.years_pursuing = 1;
        }
        else {
            return;
        }
    }

    if (alice.health.addiction_level > 0) {
        if (rand() % 100 < 20) {
            alice.health.addiction_level += 3;
            if (alice.health.addiction_level > 100) alice.health.addiction_level = 100;
        }

        if (alice.health.addiction_level >= 30 && !alice.health.counting_calories) {
            alice.health.counting_calories = true;
        }

        if (alice.health.addiction_level >= 40 && !alice.health.weighing_food) {
            alice.health.weighing_food = true;
            alice.vtb.account_rub -= alice.health.food_scale;
        }

        if (alice.health.addiction_level >= 50 && !alice.health.gym_addict) {
            alice.health.gym_addict = true;
        }

        if (alice.health.addiction_level >= 60 && !alice.health.orthorexia) {
            alice.health.orthorexia = true;
            alice.health.problem_addict = true;
        }

        if (alice.health.addiction_level >= 70 && !alice.health.body_dysmorphia) {
            alice.health.body_dysmorphia = true;
        }

        if (alice.health.addiction_level >= 80 && !alice.health.avoiding_social) {
            alice.health.avoiding_social = true;
        }
    }

    RUB monthly_sport = 0;
    float addiction_multiplier = 1.0 + (alice.health.addiction_level / 100.0);

    monthly_sport += static_cast<RUB>(alice.health.gym_membership * addiction_multiplier);

    if (alice.health.gym_addict) {
        monthly_sport += static_cast<RUB>(alice.health.personal_trainer * 2);
        monthly_sport += static_cast<RUB>(alice.health.group_classes);
    }

    if (alice.health.addiction_level > 40) {
        monthly_sport += alice.health.swimming_pool;
    }

    RUB monthly_supplements = 0;
    monthly_supplements += alice.health.protein;
    monthly_supplements += alice.health.bcaa;
    monthly_supplements += alice.health.creatine;
    monthly_supplements += alice.health.pre_workout;
    monthly_supplements += alice.health.vitamins_sports;

    if (alice.health.addiction_level > 50) {
        monthly_supplements += alice.health.omega3;
        monthly_supplements += alice.health.collagen;
        monthly_supplements += alice.health.glutamine;
    }

    RUB organic_food = 0;
    organic_food += alice.health.organic_vegetables;
    organic_food += alice.health.organic_meat;
    organic_food += alice.health.organic_chicken;
    organic_food += alice.health.organic_eggs;
    organic_food += alice.health.organic_fish;
    organic_food += alice.health.organic_dairy;

    if (alice.health.orthorexia) {
        organic_food += alice.health.superfoods;
        organic_food += alice.health.gluten_free;
        organic_food += alice.health.lactose_free;
        organic_food += alice.health.healthy_snacks;
        organic_food += alice.health.detox_water;
    }

    RUB treatments = 0;
    if (alice.health.addiction_level > 50 && rand() % 100 < 20) {
        treatments += alice.health.cryotherapy;
    }
    if (alice.health.addiction_level > 60 && rand() % 100 < 15) {
        treatments += alice.health.salt_cave;
    }
    if (alice.health.addiction_level > 70 && rand() % 100 < 10) {
        treatments += alice.health.hyperbaric_chamber;
    }
    if (alice.health.addiction_level > 80 && rand() % 100 < 5) {
        treatments += alice.health.iv_therapy;
    }
    if (alice.health.problem_addict && rand() % 100 < 8) {
        treatments += alice.health.detox_programs;
    }

    if (alice.health.addiction_level > 40 && month == 1 && year % 2 == 0) {
        alice.vtb.account_rub -= alice.health.fitness_tracker;
    }

    if (alice.health.addiction_level > 60 && month == 6 && rand() % 100 < 30) {
        alice.vtb.account_rub -= alice.health.blenders;
    }

    RUB total = monthly_sport + monthly_supplements + organic_food + treatments;
    alice.vtb.account_rub -= total;
    alice.health.total_spent += total;

    static bool food_adjusted = false;
    if (alice.health.addiction_level > 20 && !food_adjusted) {
        alice.food = static_cast<RUB>(alice.food * 0.7);
        alice.husband_food = static_cast<RUB>(alice.husband_food * 0.7);
        food_adjusted = true;
    }

    if (alice.health.addiction_level > 30 && month % 3 == 0) {
        alice.vtb.account_rub -= alice.health.nutritionist;
    }

    static bool eating_out_adjusted = false;
    if (alice.health.avoiding_social && !eating_out_adjusted) {
        alice.eating_out = static_cast<RUB>(alice.eating_out * 0.3);
        eating_out_adjusted = true;
    }

    alice.health.monthly_average =
        (alice.health.monthly_average * 11 + total) / 12;
}


void alice_inheritance(const int month, const int year) {
    if (alice.inheritance.received) return;

    int chance = 0;
    if (year == 2027) chance = 15;
    else if (year == 2028) chance = 10;
    else if (year == 2029) chance = 5;
    else return;

    if (alice.vtb.account_rub < 50'000) {
        chance *= 2;
    }

    if (rand() % 100 >= chance) return;

    int type = rand() % 100;

    RUB total_amount = 0;
    RUB expenses = 0;

    if (type < 50) {
        alice.inheritance.from_grandmother = true;
        alice.inheritance.was_expected = (rand() % 100 < 70); // 70% что ожидаемо

        RUB apartment_price = 0;
        if (rand() % 100 < 30) { // Москва/Питер
            apartment_price = 8'000'000 + (rand() % 5'000'000);
        }
        else if (rand() % 100 < 50) { // Крупный город
            apartment_price = 4'000'000 + (rand() % 3'000'000);
        }
        else { // Маленький город
            apartment_price = 1'500'000 + (rand() % 1'500'000);
        }

        alice.inheritance.apartment_value = apartment_price;
        total_amount += apartment_price;

        alice.inheritance.notary_costs = 15'000 + (rand() % 20'000);
        alice.inheritance.appraisal_costs = 5'000 + (rand() % 5'000);

        expenses += alice.inheritance.notary_costs;
        expenses += alice.inheritance.appraisal_costs;
    }
    else if (type < 80) {
        alice.inheritance.from_distant_relative = true;
        alice.inheritance.was_shock = true; // всегда неожиданно

        RUB cash_amount = 300'000 + (rand() % 700'000);
        alice.inheritance.cash = cash_amount;
        total_amount += cash_amount;

        alice.inheritance.tax_on_inheritance = static_cast<RUB>(cash_amount * 0.13);
        expenses += alice.inheritance.tax_on_inheritance;

        alice.inheritance.lawyer_costs = 30'000 + (rand() % 30'000);
        expenses += alice.inheritance.lawyer_costs;
    }
    else {
        alice.inheritance.from_unexpected = true;
        alice.inheritance.was_shock = true;

        int sub_type = rand() % 3;

        if (sub_type == 0) { // Старый бабушкин сундук
            alice.inheritance.jewelry = 200'000 + (rand() % 300'000);
            alice.inheritance.antiques = 100'000 + (rand() % 200'000);
            total_amount += alice.inheritance.jewelry + alice.inheritance.antiques;
        }
        else if (sub_type == 1) { // Старая машина в гараже
            alice.inheritance.car_value = 400'000 + (rand() % 400'000);
            total_amount += alice.inheritance.car_value;
        }
        else { // Наличка в матрасе
            alice.inheritance.cash = 100'000 + (rand() % 200'000);
            total_amount += alice.inheritance.cash;
        }
        if (rand() % 100 < 30) { // 30% шанс, что есть долги
            alice.inheritance.debt_of_relative = static_cast<RUB>(total_amount * 0.2);
            expenses += alice.inheritance.debt_of_relative;
            printf("    но пришлось оплатить долги: %lld руб.\n", alice.inheritance.debt_of_relative);
        }
    }

    if (rand() % 100 < 25 && total_amount > 1'000'000) {
        alice.inheritance.caused_family_drama = true;
        RUB legal_costs = static_cast<RUB>(total_amount * 0.1);
        expenses += legal_costs;
        printf("    !!! родственники судятся, расходы на юристов: %lld руб.\n", legal_costs);
    }

    RUB net_amount = total_amount - expenses;
    if (net_amount < 0) net_amount = 0;

    alice.inheritance.amount = net_amount;
    alice.inheritance.year_received = year;
    alice.inheritance.month_received = month;
    alice.inheritance.received = true;

    alice.vtb.account_rub += net_amount;

    printf("    всего получено: %lld руб.\n", total_amount);
    printf("    расходы на оформление: %lld руб.\n", expenses);
    printf("    ЧИСТЫМИ: %lld руб.\n", net_amount);
}

void print_results()
{
    RUB total_income = 0;
    RUB total_expenses = 0;

    printf("\nдоходы\n");
    printf("финальная зарплата Алисы: %lld руб./мес\n", alice.salary);
    printf("финальная зарплата мужа(или уже не мужа Алисы): %lld руб./мес\n", alice.husband_salary);

    printf("\nбанковские счета\n");
    RUB capital = 0;
    capital += alice.vtb.account_rub;
    capital += static_cast<RUB>(alice.vtb.account_usd * alice.vtb.rate_usd_rub);
    capital += alice.vtb.deposit_rub;
    capital += static_cast<RUB>(alice.vtb.deposit_usd * alice.vtb.rate_usd_rub);
    capital += alice.vtb.investment_bonds;
    capital += alice.vtb.investment_stocks;

    printf("рублевый счет: %lld руб.\n", alice.vtb.account_rub);
    printf("валютный счет: %lld USD (%.0f руб.)\n", alice.vtb.account_usd,
        alice.vtb.account_usd * alice.vtb.rate_usd_rub);
    printf("рублевый депозит: %lld руб.\n", alice.vtb.deposit_rub);
    printf("валютный депозит: %lld USD\n", alice.vtb.deposit_usd);
    printf("инвестиции (облигации): %lld руб.\n", alice.vtb.investment_bonds);
    printf("инвестиции (акции): %lld руб.\n", alice.vtb.investment_stocks);
    printf("задолженность по кредитке: %lld руб.\n", alice.vtb.credit_card_debt);

    printf("\nнедвижимость\n");
    capital += 5000000;
    printf("остаток по ипотеке: %lld руб.\n", alice.flat_2.loan_amount);
    if (alice.flat_2.loan_amount < 3000000) {
        printf("выплачено ипотеки: %lld руб.\n", 3000000 - alice.flat_2.loan_amount);
    }

    printf("\nавтомобили\n");
    capital += alice.car_alice.value;
    capital += alice.car_husband.value;
    printf("машина Алисы: %lld руб.\n", alice.car_alice.value);
    printf("машина мужа: %lld руб.\n", alice.car_husband.value);

    printf("\nсемейное положение\n");
    printf("замужем ли Алиса: %s\n", alice.married ? "да" : "нет");
    printf("свадьба состоялась: %s\n", alice.wedding.happened ? "да" : "нет");
    printf("развод состоялся: %s\n", alice.divorce.happened ? "да" : "нет");
    printf("ребенок родился: %s\n", alice.child.born ? "да" : "нет");
    if (alice.child.born) {
        printf("возраст ребенка: %d месяцев (%.1f лет)\n",
            alice.child.age_months, alice.child.age_months / 12.0);
    }
    printf("в декрете: %s\n", alice.on_maternity_leave ? "да" : "нет");

    printf("\nпитомцы\n");
    printf("котейка: %s\n", alice.cat.have_pet ? "есть" : "нет");
    printf("хомяк: %s\n", alice.hamster.have_pet ? "есть" : "нет");
    printf("собака: %s\n", alice.dog.have_pet ? "есть" : "нет");

    printf("\nтрудоустройство\n");
    printf("Алиса работает: %s\n", alice.alice_job.employed ? "да" : "нет");
    printf("Муж работает: %s\n", alice.husband_job.employed ? "да" : "нет");

    printf("\nобщий капитал\n");
    printf("ИТОГО: %lld руб.\n", capital);

    printf("\nДиНаМиКа\n");
    printf("начальный капитал: 500,000 руб.\n");
    printf("конечный капитал: %lld руб.\n", capital);
    printf("изменение: %+lld руб. (%+.1f%%)\n",
        capital - 500000,
        (capital - 500000) * 100.0 / 500000);

    printf("\n==========================================\n");
}


void simulation()
{
    int year = 2026;
    int month = 1;

    while (!(year == 2030 && month == 1)) {

        alice_salary(month, year);
        alice_bank(month, year);

        if (month == 6) { // проверяем в июне каждого года
            alice_inheritance(month, year);
        }

        alice_mortgage(month, year);
        alice_flat_1(month, year);
        alice_car(alice.car_alice, month, year);
        if (alice.married) {
            alice_car(alice.car_husband, month, year);
        }

        alice_food(month, year);
        alice_subscriptions(month, year);
        alice_paid_apps(month, year);
        alice_health_addiction(month, year);
        alice_sleep_health(month, year);

        alice_social_capital(month, year);
        alice_friend_support(month, year);
        alice_intangible_services(month, year);

        alice_transaction_costs(month, year);
        alice_emotional_spending(month, year);
        alice_convenience_spending(month, year);
        alice_proxy_spending(month, year);
        alice_situational_purchases(month, year);
        alice_legal_mistakes(month, year);
        alice_bank_fees(month, year);
        alice_storage(month, year);

        alice_wedding(month, year);
        alice_child(month, year);
        alice_divorce(month, year);
        alice_job_change(month, year);

        if (alice.married && year >= 2027) {
            if (!alice.cat.have_pet && month == 9) {
                alice.cat.have_pet = true;
                alice.vtb.account_rub -= 10'000;
                printf("Купили кота в %d.%d!\n", month, year);
            }
            if (!alice.dog.have_pet && alice.child.born && month == 10) {
                alice.dog.have_pet = true;
                alice.vtb.account_rub -= 15'000;
                printf("Купили собаку в %d.%d!\n", month, year);
            }
            if (!alice.hamster.have_pet && alice.child.born && month == 11) {
                alice.hamster.have_pet = true;
                alice.vtb.account_rub -= 2'000;
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

        if (alice.vtb.account_rub > alice.emergency_fund_personal * 12) {
            RUB transfer = alice.vtb.account_rub / 10;
            alice.emergency_fund_personal += transfer;
            alice.vtb.account_rub -= transfer;
        }

        ++month;
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
            capital += 5000000;

            printf("\nИТОГИ %d ГОДА\n", year);
            printf("деньги на счетах: %lld руб.\n", alice.vtb.account_rub + alice.vtb.deposit_rub);
            printf("инвестиции: %lld руб.\n", alice.vtb.investment_bonds + alice.vtb.investment_stocks);
            printf("машины: %lld руб.\n", alice.car_alice.value + (alice.married ? alice.car_husband.value : 0));
            printf("квартира: 5,000,000 руб.\n");
            printf("общий капитал: %lld руб.\n", capital);
        }
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    alice_init();
    simulation();
    print_results();

    return 0;
}