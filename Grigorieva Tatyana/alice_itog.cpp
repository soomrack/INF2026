#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <vector> 

typedef long long int RUB;

struct Car {
    RUB value;
    RUB gas;
    RUB base_gas;
};

struct Housing {
    RUB rent;
    RUB utilities;
    RUB internet;
    RUB mobile;
};

struct Mortgage {
    RUB total_amount;
    RUB monthly_payment;
    float rate;
    int months_left;
    int active;
};

struct BankPackage {
    RUB card;
    RUB savings;
    float rate;
};

struct Bank {
    char name[50];
    float deposit_rate;
    float card_cashback;
    RUB min_deposit;
    float (*calculate_rate)(RUB sum);
};


float sberbank_rate_calculator(RUB sum)
{
    if (sum >= 3000000) return 12.5;
    if (sum > 10000) return 11.5;
    return 0.1;
}

struct Bank sberbank = {
    "Сбербанк",
    11.5,
    0.01,
    10000,
    sberbank_rate_calculator
};

// ============================================================
//  СТРУКТУРЫ ДЛЯ СИСТЕМЫ ПИТАНИЯ
// ============================================================

// Структура для хранения цен на продукты
struct ProductPrice {
    char name[50];
    RUB price_per_unit;      // цена за 100г/шт/л
    RUB base_price;           // базовая цена для инфляции
};

// Структура для холодильника (цены на продукты)
struct Fridge {
    struct ProductPrice products[50];
    int num_products;
};

// Структура для ингредиента
struct Ingredient {
    char name[50];
    double grams;            // количество в граммах/мл/штуках
};

// Структура для рецепта
struct Recipe {
    char name[50];
    struct Ingredient ingredients[10];
    int num_ingredients;
};

// Структура для бюджета питания
struct FoodBudget {
    RUB total_monthly;
    RUB breakfast_cost;
    RUB lunch_cost;
    RUB dinner_cost;
    RUB snacks_cost;
    RUB drinks_cost;
};

// ============================================================
//  КНИГА РЕЦЕПТОВ (КАЖДАЯ КАТЕГОРИЯ - ОТДЕЛЬНЫЙ МАССИВ)
// ============================================================

// Каши на завтрак
const Recipe porridges[] = {
    {"Овсянка на молоке", {{"овсянка",80}, {"молоко",200}}, 2},
    {"Гречка с маслом", {{"гречка",80}, {"масло",10}}, 2},
    {"Рисовая каша", {{"рис",80}, {"молоко",200}}, 2},
    {"Манная каша", {{"манка",60}, {"молоко",200}}, 2},
    {"Перловая каша", {{"перловка",80}, {"масло",10}}, 2},
    {"Пшённая каша", {{"пшено",70}, {"молоко",200}}, 2}
};
const int porridges_count = 6;

// Лёгкий завтрак
const Recipe light_breakfast[] = {
    {"Бутерброд с сыром", {{"хлеб",80}, {"сыр",30}, {"масло",5}}, 3},
    {"Бутерброд с колбасой", {{"хлеб",80}, {"колбаса",40}}, 2},
    {"Яичница глазунья", {{"яйца",2}, {"масло",10}}, 2},
    {"Творог со сметаной", {{"творог",150}, {"сметана",30}}, 2},
    {"Йогурт с бананом", {{"йогурт",200}, {"банан",1}}, 2},
    {"Яйцо варёное с хлебом", {{"яйца",2}, {"хлеб",60}, {"масло",5}}, 3},
    {"Омлет", {{"яйца",3}, {"молоко",60}, {"масло",8}}, 3},
    {"Ряженка с сухарями", {{"ряженка",300}, {"сухари",50}}, 2},
    {"Кефир с хлебом", {{"кефир",250}, {"хлеб",60}}, 2}
};
const int light_breakfast_count = 9;

// Напитки на завтрак
const Recipe breakfast_drinks[] = {
    {"Чай", {{"чай",5}}, 1},
    {"Кофе", {{"кофе",10}}, 1},
    {"Сок", {{"сок",200}}, 1},
    {"Кефир", {{"кефир",250}}, 1}
};

const int breakfast_drinks_count = 4;

// Первые блюда
const Recipe first_course[] = {
    {"Борщ", {{"борщ набор",1}, {"сметана",50}}, 2},
    {"Куриный суп", {{"курица",300}, {"картошка",150}, {"морковь",50}}, 3},
    {"Гречневый суп", {{"гречка",80}, {"морковь",50}, {"картошка",100}}, 3},
    {"Щи", {{"капуста",200}, {"картошка",100}, {"морковь",40}, {"сметана",30}}, 4},
    {"Рассольник", {{"рис",50}, {"картошка",150}, {"морковь",50}}, 3},
    {"Лапша куриная", {{"макароны",80}, {"курица",200}, {"морковь",30}}, 3},
    {"Гороховый суп", {{"картошка",150}, {"морковь",50}, {"лук",30}}, 3}
};
const int first_course_count = 7;

// Вторые блюда
const Recipe second_course[] = {
    {"Курица с картошкой", {{"курица",300}, {"картошка",250}}, 2},
    {"Макароны с сыром", {{"макароны",200}, {"сыр",50}, {"масло",15}}, 3},
    {"Гречка с говядиной", {{"гречка",150}, {"говядина",250}}, 2},
    {"Рис с курицей", {{"рис",150}, {"курица",250}}, 2},
    {"Картошка с сосисками", {{"картошка",250}, {"сосиски",150}}, 2},
    {"Макароны с говядиной", {{"макароны",200}, {"говядина",200}, {"масло",10}}, 3},
    {"Пюре с котлетой", {{"картошка",300}, {"говядина",150}, {"масло",20}}, 3}
};
const int second_course_count = 7;

// Праздничные блюда
const Recipe holiday_lunches[] = {
    {"Праздничная курица", {{"курица",800}, {"картошка",500}, {"сметана",100}}, 3},
    {"Плов праздничный", {{"рис",300}, {"говядина",600}, {"морковь",150}, {"масло",50}}, 4},
    {"Запечённая курица", {{"курица",1000}, {"картошка",400}, {"сметана",80}}, 3},
    {"Говядина тушёная", {{"говядина",700}, {"картошка",300}, {"морковь",100}}, 3}
};
const int holiday_lunches_count = 4;

// Салаты
const Recipe salads[] = {
    {"Салат овощной", {{"помидоры",150}, {"огурцы",150}, {"сметана",30}}, 3},
    {"Салат капустный", {{"капуста",200}, {"морковь",80}, {"сметана",30}}, 3},
    {"Помидоры свежие", {{"помидоры",200}}, 1},
    {"Огурцы свежие", {{"огурцы",200}}, 1},
    {"Тёртая морковь", {{"морковь",150}, {"сметана",20}}, 2}
};
const int salads_count = 5;

// Лёгкий ужин
const Recipe light_dinner[] = {
    {"Бутерброд с колбасой", {{"хлеб",80}, {"колбаса",40}}, 2},
    {"Яичница вечерняя", {{"яйца",2}, {"масло",10}}, 2},
    {"Творог со сметаной", {{"творог",150}, {"сметана",30}}, 2},
    {"Йогурт натуральный", {{"йогурт",200}}, 1},
    {"Каша гречневая", {{"гречка",80}, {"масло",10}}, 2},
    {"Кефир с хлебом", {{"кефир",250}, {"хлеб",50}}, 2}
};
const int light_dinner_count = 6;

// Напитки на ужин
const Recipe dinner_drinks[] = {
    {"Чай вечерний", {{"чай",5}}, 1},
    {"Кофе вечерний", {{"кофе",10}}, 1},
    {"Кефир вечером", {{"кефир",250}}, 1}
};
const int dinner_drinks_count = 3;

// Перекусы
const Recipe snacks[] = {
    {"Печенье", {{"печенье",50}}, 1},
    {"Шоколад", {{"шоколад",25}}, 1},
    {"Чипсы", {{"чипсы",40}}, 1},
    {"Орехи", {{"орехи",30}}, 1},
    {"Банан", {{"банан",1}}, 1},
    {"Яблоко", {{"яблоко",1}}, 1},
    {"Йогурт", {{"йогурт",150}}, 1}
};
const int snacks_count = 7;

// Дневные напитки
const Recipe day_drinks[] = {
    {"Чай дневной", {{"чай",5}}, 1},
    {"Кофе дневной", {{"кофе",10}}, 1},
    {"Сок дневной", {{"сок",200}}, 1},
    {"Вода дневная", {{"вода",500}}, 1}
};
const int day_drinks_count = 4;

// Блюда для больного (лёгкие)
const Recipe sick_breakfast[] = {
    {"Жидкая овсянка на воде", {{"овсянка",50}, {"вода",300}}, 2},
    {"Рисовый отвар", {{"рис",40}, {"вода",400}}, 2},
    {"Сухарик с чаем", {{"хлеб",30}, {"чай",5}}, 2},
    {"Жидкая манка", {{"манка",40}, {"вода",300}}, 2}
};
const int sick_breakfast_count = 4;

const Recipe sick_main[] = {
    {"Куриный бульон", {{"курица",100}, {"морковь",20}, {"вода",500}}, 3},
    {"Картофельный суп", {{"картошка",100}, {"морковь",20}, {"вода",400}}, 3},
    {"Гречка на воде", {{"гречка",60}}, 1},
    {"Рис отварной", {{"рис",60}, {"вода",200}}, 2}
};
const int sick_main_count = 4;

const Recipe sick_drinks[] = {
    {"Стакан воды", {{"вода",300}}, 1},
    {"Тёплый чай", {{"чай",5}, {"вода",300}}, 2},
    {"Тёплое молоко", {{"молоко",250}}, 1}
};
const int sick_drinks_count = 3;


struct Person {
    RUB salary;
    RUB cash;
    RUB clothing;
    struct Car car;
    struct Housing housing;
    struct Mortgage mortgage;
    struct BankPackage bank;
    struct Bank* main_bank;
    struct Fridge fridge;
};

struct Person alice;


const float INFLATION_RATE = 8.5;
const float FOOD_MONTHLY_INFLATION = 0.7;
const float GAS_MONTHLY_INFLATION = 1.0;

struct MonthlyStats {
    RUB salary_received;
    RUB housing_paid;
    RUB food_paid;
    RUB clothing_paid;
    RUB gas_paid;
    RUB cashback_received;
    RUB interest_received;
    RUB savings_moved;
    RUB cash_spent;
    RUB card_spent;
    RUB cash_withdrawn;
    RUB emergency_fund_used;
    RUB taxes_paid;
    RUB total_events_impact;
    RUB tax_deduction_base;
} stats;


// Структура для жизненных событий
struct LifeEvent {
    int year;
    int month;
    char description[100];
    RUB financial_impact;
    void (*effect)(struct Person* p, RUB amount);
    int probability;  //вероятность
    int triggered;
    int min_month;    // минимальный месяц для события
    int max_month;    // максимальный месяц для события
    int min_year;     // минимальный год
    int max_year;     // максимальный год
};


std::vector<LifeEvent> events;


void alice_init();
void init_stats();
void withdraw_cash(RUB amount);
void alice_food();
void alice_housing_expenses();
void alice_car();
void alice_salary(int year, int month);
void alice_bank_interest();
void alice_manage_savings(int month);
void alice_simulation();
void print_results();

// Прототипы функций для питания
void init_product_prices(struct Fridge* fridge);
RUB get_product_price(struct Fridge* fridge, const char* name, double grams);
const Recipe* pick_random_recipe(const Recipe recipes[], int count);
RUB cook_meal(struct Fridge* fridge, const Recipe* recipe, RUB* total_cost);
struct FoodBudget calculate_monthly_food(int month, int sick_days, int is_holiday_month);
void update_product_prices(struct Fridge* fridge, int month);

// Прототипы функций для событий
void car_breakdown(struct Person* man, RUB amount);
void medical_emergency(struct Person* man, RUB amount);
void salary_bonus(struct Person* man, RUB amount);
void vacation_expense(struct Person* man, RUB amount);
void home_repair(struct Person* man, RUB amount);
void laptop_breakdown(struct Person* man, RUB amount);
void dental_treatment(struct Person* man, RUB amount);
void car_insurance(struct Person* man, RUB amount);
void fitness_subscription(struct Person* man, RUB amount);
void courses_expense(struct Person* man, RUB amount);
void phone_break(struct Person* man, RUB amount);
void friend_wedding(struct Person* man, RUB amount);
void tax_refund(struct Person* man, RUB amount);
void inheritance_receive(struct Person* man, RUB amount);


void init_events_dynamic() {
    events.clear(); 
    
    struct LifeEvent e1;
    strcpy(e1.description, "Поломка автомобиля");
    e1.min_year = 2026;
    e1.max_year = 2027;
    e1.min_month = 1;
    e1.max_month = 12;
    e1.effect = car_breakdown;
    e1.probability = 25;
    e1.triggered = 0;
    e1.financial_impact = 0;
    events.push_back(e1); 
    
    struct LifeEvent e2;
    strcpy(e2.description, "Медицинская проблема");
    e2.min_year = 2026;
    e2.max_year = 2027;
    e2.min_month = 1;
    e2.max_month = 12;
    e2.effect = medical_emergency;
    e2.probability = 15;
    e2.triggered = 0;
    e2.financial_impact = 0;
    events.push_back(e2);
    
    struct LifeEvent e3;
    strcpy(e3.description, "Годовая премия");
    e3.min_year = 2026;
    e3.max_year = 2027;
    e3.min_month = 12;
    e3.max_month = 1;  // декабрь-январь
    e3.effect = salary_bonus;
    e3.probability = 70;
    e3.triggered = 0;
    e3.financial_impact = 0;
    events.push_back(e3);
    
    struct LifeEvent e4;
    strcpy(e4.description, "Отпуск");
    e4.min_year = 2026;
    e4.max_year = 2027;
    e4.min_month = 6;
    e4.max_month = 8;  // летние месяцы
    e4.effect = vacation_expense;
    e4.probability = 90;
    e4.triggered = 0;
    e4.financial_impact = 0;
    events.push_back(e4);
    
    struct LifeEvent e5;
    strcpy(e5.description, "Свадьба друга");
    e5.min_year = 2026;
    e5.max_year = 2026;
    e5.min_month = 11;
    e5.max_month = 11;  // только ноябрь
    e5.effect = friend_wedding;
    e5.probability = 100;
    e5.triggered = 0;
    e5.financial_impact = 0;
    events.push_back(e5);
    
    struct LifeEvent e6;
    strcpy(e6.description, "Ремонт в квартире");
    e6.min_year = 2026;
    e6.max_year = 2027;
    e6.min_month = 4;
    e6.max_month = 8;  // весна-лето
    e6.effect = home_repair;
    e6.probability = 30;
    e6.triggered = 0;
    e6.financial_impact = 0;
    events.push_back(e6);
    
    struct LifeEvent e7;
    strcpy(e7.description, "Поломка ноутбука");
    e7.min_year = 2026;
    e7.max_year = 2027;
    e7.min_month = 1;
    e7.max_month = 12;
    e7.effect = laptop_breakdown;
    e7.probability = 20;
    e7.triggered = 0;
    e7.financial_impact = 0;
    events.push_back(e7);
    
    struct LifeEvent e8;
    strcpy(e8.description, "Лечение зубов");
    e8.min_year = 2026;
    e8.max_year = 2027;
    e8.min_month = 1;
    e8.max_month = 12;
    e8.effect = dental_treatment;
    e8.probability = 25;
    e8.triggered = 0;
    e8.financial_impact = 0;
    events.push_back(e8);
    
    struct LifeEvent e9;
    strcpy(e9.description, "Страховка автомобиля");
    e9.min_year = 2026;
    e9.max_year = 2026;
    e9.min_month = 3;
    e9.max_month = 3;  // только март
    e9.effect = car_insurance;
    e9.probability = 100;
    e9.triggered = 0;
    e9.financial_impact = 0;
    events.push_back(e9);
    
    struct LifeEvent e10;
    strcpy(e10.description, "Годовой абонемент в фитнес");
    e10.min_year = 2026;
    e10.max_year = 2027;
    e10.min_month = 1;
    e10.max_month = 1;  // только январь
    e10.effect = fitness_subscription;
    e10.probability = 60;
    e10.triggered = 0;
    e10.financial_impact = 0;
    events.push_back(e10);
    
    struct LifeEvent e11;
    strcpy(e11.description, "Профессиональные курсы");
    e11.min_year = 2026;
    e11.max_year = 2027;
    e11.min_month = 9;
    e11.max_month = 10;  // осень
    e11.effect = courses_expense;
    e11.probability = 40;
    e11.triggered = 0;
    e11.financial_impact = 0;
    events.push_back(e11);
    
    struct LifeEvent e12;
    strcpy(e12.description, "Разбил телефон");
    e12.min_year = 2026;
    e12.max_year = 2027;
    e12.min_month = 1;
    e12.max_month = 12;
    e12.effect = phone_break;
    e12.probability = 15;
    e12.triggered = 0;
    e12.financial_impact = 0;
    events.push_back(e12);
    
    struct LifeEvent e13;
    strcpy(e13.description, "Получение наследства");
    e13.min_year = 2026;
    e13.max_year = 2027;
    e13.min_month = 1;
    e13.max_month = 12;
    e13.effect = inheritance_receive;
    e13.probability = 5;
    e13.triggered = 0;
    e13.financial_impact = 0;
    events.push_back(e13);
}


  void schedule_events() {
    
    printf("\n ПЛАНИРОВАНИЕ ЖИЗНЕННЫХ СОБЫТИЙ\n");
    
    // Используем range-based for (C++11)
    for (auto& event : events) {
        // Выбираем случайный месяц в заданном диапазоне
        if (event.min_year == event.max_year) {
            // Событие в одном году
            event.year = event.min_year;
            
            if (event.min_month <= event.max_month) {
                // Обычный диапазон (например, июнь-сентябрь)
                event.month = event.min_month + 
                    (rand() % (event.max_month - event.min_month + 1));
            } else {
                // Диапазон через новый год (например, декабрь-январь)
                int range = (12 - event.min_month + 1) + event.max_month;
                int offset = rand() % range;
                
                if (offset < (12 - event.min_month + 1)) {
                    event.month = event.min_month + offset;
                    event.year = event.min_year;
                } else {
                    event.month = offset - (12 - event.min_month + 1) + 1;
                    event.year = event.min_year + 1;
                }
            }
        } else {
            // Событие может быть в разных годах
            int year_range = event.max_year - event.min_year;
            event.year = event.min_year + (rand() % (year_range + 1));
            
            if (event.year == event.min_year) {
                // В первый год - от min_month до декабря
                event.month = event.min_month + 
                              rand() % (13 - event.min_month);
            } else if (event.year == event.max_year) {
                // В последний год - от января до max_month
                event.month = 1 + rand() % event.max_month;
            } else {
                // В промежуточные годы - любой месяц
                event.month = 1 + rand() % 12;
            }
        }
        
        // Генерируем случайную сумму для событий без эффекта
        if (event.effect == NULL) {
            event.financial_impact = 10000 + rand() % 190000;
        }
        
        printf("  Запланировано событие \"%s\" на %d.%d (вероятность %d%%)\n", 
               event.description, event.month, event.year, event.probability);
    }
}

void car_breakdown(struct Person* man, RUB amount) {
    RUB cost = 30000 + rand() % 120000;
    printf("\n ПОЛОМКА АВТОМОБИЛЯ\n");
    printf("Ремонт обошелся в %lld руб.\n", cost);
    
    if (man->bank.savings >= cost) {
        man->bank.savings -= cost;
        stats.emergency_fund_used += cost;
        printf("Оплачено из сбережений\n");
    } else {
        RUB remaining = cost - man->bank.savings;
        man->bank.savings = 0;
        man->bank.card -= remaining;
        stats.emergency_fund_used += cost;
        printf("Сбережений не хватило, пришлось снимать с карты: %lld руб.\n", remaining);
    }
    stats.total_events_impact += cost;
}


void medical_emergency(struct Person* man, RUB amount) {
    RUB cost = 20000 + rand() % 280000;
    printf("\n МЕДИЦИНСКАЯ ПРОБЛЕМА\n");
    printf("  Лечение обошлось в %lld руб.\n", cost);
    
    if (man->bank.savings >= cost) {
        man->bank.savings -= cost;
        stats.emergency_fund_used += cost;
        stats.tax_deduction_base += cost;
        printf("Оплачено из сбережений\n");
    } else {
        RUB remaining = cost - man->bank.savings;
        man->bank.savings = 0;
        man->bank.card -= remaining;
        stats.emergency_fund_used += cost;
        stats.tax_deduction_base += cost;
        printf("Сбережений не хватило, пришлось снимать с карты: %lld руб.\n", remaining);
    }
    stats.total_events_impact += cost;
}

void salary_bonus(struct Person* man, RUB amount) {
    RUB bonus = man->salary * (0.3 + (rand() % 70) / 100.0);
    printf("\n ГОДОВАЯ ПРЕМИЯ\n");
    printf("  Получено %lld руб.\n", bonus);
    man->bank.card += bonus;
    stats.salary_received += bonus;
    stats.total_events_impact -= bonus;
}

void vacation_expense(struct Person* man, RUB amount) {
    RUB cost = 50000 + rand() % 200000;
    printf("\n ОТПУСК\n");
    printf("  Потрачено на отпуск: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void home_repair(struct Person* man, RUB amount) {
    RUB cost = 20000 + rand() % 180000;
    printf("\n РЕМОНТ В КВАРТИРЕ\n");
    printf("  Потрачено на ремонт: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void laptop_breakdown(struct Person* man, RUB amount) {
    RUB cost = 30000 + rand() % 70000;
    printf("\n ПОЛОМКА НОУТБУКА\n");
    printf("  Ремонт/покупка нового: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void dental_treatment(struct Person* man, RUB amount) {
    RUB cost = 15000 + rand() % 135000;
    printf("\n ЛЕЧЕНИЕ ЗУБОВ\n");
    printf("  Потрачено на стоматолога: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
    stats.tax_deduction_base += cost;
}

void car_insurance(struct Person* man, RUB amount) {
    RUB cost = 25000 + rand() % 25000;
    printf("\n СТРАХОВКА АВТОМОБИЛЯ\n");
    printf("  Годовая страховка: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void fitness_subscription(struct Person* man, RUB amount) {
    RUB cost = 15000 + rand() % 35000;
    printf("\n ФИТНЕС АБОНЕМЕНТ\n");
    printf("  Годовой абонемент: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
    stats.tax_deduction_base += cost;
}

void courses_expense(struct Person* man, RUB amount) {
    RUB cost = 20000 + rand() % 80000;
    printf("\n ПРОФЕССИОНАЛЬНЫЕ КУРСЫ\n");
    printf("  Оплата курсов: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
    stats.tax_deduction_base += cost;
}

void phone_break(struct Person* man, RUB amount) {
    RUB cost = 10000 + rand() % 60000;
    printf("\n РАЗБИЛ ТЕЛЕФОН\n");
    printf("  Ремонт/покупка нового: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void friend_wedding(struct Person* man, RUB amount) {
    RUB cost = 10000 + rand() % 40000;
    printf("\n СВАДЬБА ДРУГА\n");
    printf("  Подарок и расходы: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void inheritance_receive(struct Person* man, RUB amount) {
    RUB inheritance = 100000 + rand() % 900000;
    printf("\n ПОЛУЧЕНИЕ НАСЛЕДСТВА\n");
    printf("  Получено: %lld руб.\n", inheritance);
    man->bank.savings += inheritance;
    stats.total_events_impact -= inheritance;
}


void check_events(int year, int month, struct Person*man) {
    for (size_t i = 0; i < events.size(); i++) {
        if (events[i].year == year && events[i].month == month && !events[i].triggered) {
            int roll = rand() % 100;
            printf("\n--- ПРОВЕРКА СОБЫТИЯ: %s (roll=%d, need<%d) ---\n", 
                   events[i].description, roll, events[i].probability);
            
            if (roll < events[i].probability) {
                printf(" СОБЫТИЕ СРАБОТАЛО!\n");
                if (events[i].effect != NULL) {
                    events[i].effect(man, events[i].financial_impact);
                } else {
                    printf("\n СОБЫТИЕ: %s\n", events[i].description);
                    printf("  Финансовое влияние: %lld руб.\n", events[i].financial_impact);
                    man->bank.card -= events[i].financial_impact;
                    stats.total_events_impact += events[i].financial_impact;
                }
                events[i].triggered = 1;
            } else {
                printf(" СОБЫТИЕ НЕ СРАБОТАЛО (вероятность %d%%)\n", events[i].probability);
            }
        }
    }
}


void init_stats() {
    stats.salary_received = 0;
    stats.housing_paid = 0;
    stats.food_paid = 0;
    stats.clothing_paid = 0;
    stats.gas_paid = 0;
    stats.cashback_received = 0;
    stats.interest_received = 0;
    stats.savings_moved = 0;
    stats.cash_spent = 0;
    stats.card_spent = 0;
    stats.cash_withdrawn = 0;
    stats.emergency_fund_used = 0;
    stats.taxes_paid = 0;
    stats.total_events_impact = 0;
    stats.tax_deduction_base = 0;
}


void alice_init()
{
    alice.cash = 50000;
    alice.salary = 250000;
    alice.clothing = 8000;

    alice.car.value = 2400000;
    alice.car.gas = 12000;
    alice.car.base_gas = 12000;

    alice.housing.rent = 40000;
    alice.housing.utilities = 7000;
    alice.housing.internet = 1000;
    alice.housing.mobile = 1500;
    
    alice.bank.card = 20000;
    alice.bank.savings = 200000;
    alice.bank.rate = 0;
    
    alice.main_bank = &sberbank;
    
    alice.mortgage.total_amount = 0;
    alice.mortgage.monthly_payment = 0;
    alice.mortgage.rate = 0;
    alice.mortgage.months_left = 0;
    alice.mortgage.active = 0;

    init_product_prices(&alice.fridge);
    
    init_stats();
}


void withdraw_cash(RUB amount)
{
    if (amount <= alice.bank.card) {
        alice.bank.card -= amount;
        alice.cash += amount;
        stats.cash_withdrawn += amount;
        printf("  Снято с карты: %lld руб.\n", amount);
    }
}


void apply_gas_inflation(int month) {
    RUB old_gas = alice.car.gas;
    
    float inflation_multiplier = 1.0 + GAS_MONTHLY_INFLATION / 100.0;
    alice.car.gas = alice.car.base_gas * pow(inflation_multiplier, month - 1);
    
    if (month == 1) {
        alice.car.base_gas = alice.car.gas;
    }
}    


void try_take_mortgage(struct Person* man, int year)
{
    if (man->mortgage.active) return;

    RUB flat_price = 4000000;
    RUB first_payment = flat_price * 0.2; 

    RUB parents_help = 200000;

    // если не хватает — помогают родители
    if (man->bank.savings < first_payment) {
        if (man->bank.savings + parents_help >= first_payment) {
            printf("\n РОДИТЕЛИ ПОМОГЛИ С ПЕРВОНАЧАЛЬНЫМ ВЗНОСОМ\n");
            man->bank.savings += parents_help;
        } else {
            return; // всё равно не хватает
        }
    }

    RUB loan = flat_price - first_payment; // 3.2 млн
    float rate = 11.0;
    int months = 20 * 12;

    float monthly_rate = rate / 100.0 / 12.0;
    RUB monthly = loan * (monthly_rate * pow(1 + monthly_rate, months)) /
                  (pow(1 + monthly_rate, months) - 1);

    printf("\n АЛИСА БЕРЁТ ИПОТЕКУ!\n");

    man->bank.savings -= first_payment;

    man->mortgage.total_amount = loan;
    man->mortgage.monthly_payment = monthly;
    man->mortgage.rate = rate;
    man->mortgage.months_left = months;
    man->mortgage.active = 1;

    printf("  Квартира: %lld руб.\n", flat_price);
    printf("  Первоначальный взнос: %lld руб.\n", first_payment);
    printf("  Платёж: %lld руб./мес\n", monthly);

    // убираем аренду
    man->housing.rent = 0;
}


void alice_pay_mortgage()
{
    if (!alice.mortgage.active) return;

    RUB payment = alice.mortgage.monthly_payment;

    printf("  Ипотека: %lld руб.\n", payment);

    if (alice.bank.card >= payment) {
        alice.bank.card -= payment;
    } else {
        RUB need = payment - alice.bank.card;
        alice.bank.card = 0;
        withdraw_cash(need);
        alice.cash -= need;
    }

    alice.mortgage.months_left--;

    if (alice.mortgage.months_left <= 0) {
        printf("  ИПОТЕКА ПОГАШЕНА!\n");
        alice.mortgage.active = 0;
    }
}


void alice_housing_expenses()
{
    RUB total_housing = alice.housing.rent + 
                        alice.housing.utilities + 
                        alice.housing.internet + 
                        alice.housing.mobile;
    
    RUB housing_cash_needed = total_housing * 0.5;
    
    if (alice.cash < housing_cash_needed) {
        RUB needed = housing_cash_needed - alice.cash;
        withdraw_cash(needed);
    }
    
    RUB housing_cash = housing_cash_needed;
    RUB housing_card = total_housing * 0.5;
    
    alice.cash -= housing_cash;
    alice.bank.card -= housing_card;
    
    stats.housing_paid += total_housing;
    stats.cash_spent += housing_cash;
    stats.card_spent += housing_card;
    
    if (alice.main_bank != NULL) {
        RUB cashback = housing_card * alice.main_bank->card_cashback;
        alice.bank.card += cashback;
        stats.cashback_received += cashback;
        if (cashback > 0) printf("  Кэшбэк за жилье: %lld руб.\n", cashback);
    }
    
    printf("  Жилье: наличные %lld руб., карта %lld руб. (всего %lld руб.)\n", 
           housing_cash, housing_card, total_housing);
}


void alice_car()
{
    RUB gas_cash_needed = alice.car.gas * 0.5;
    
    if (alice.cash < gas_cash_needed) {
        RUB needed = gas_cash_needed - alice.cash;
        withdraw_cash(needed);
    }
    
    RUB gas_cash = gas_cash_needed;
    RUB gas_card = alice.car.gas * 0.5;
    
    alice.cash -= gas_cash;
    alice.bank.card -= gas_card;
    
    stats.gas_paid += alice.car.gas;
    stats.cash_spent += gas_cash;
    stats.card_spent += gas_card;
    
    if (alice.main_bank != NULL) {
        RUB cashback = gas_card * alice.main_bank->card_cashback;
        alice.bank.card += cashback;
        stats.cashback_received += cashback;
        if (cashback > 0) printf("  Кэшбэк за бензин: %lld руб.\n", cashback);
    }
    
    printf("  Бензин: наличные %lld руб., карта %lld руб.\n", gas_cash, gas_card);
}


void alice_clothing()
{
    RUB clothing_cash_needed = alice.clothing * 0.2;  // 20% наличными
    
    if (alice.cash < clothing_cash_needed) {
        RUB needed = clothing_cash_needed - alice.cash;
        withdraw_cash(needed);
    }
    
    RUB clothing_cash = clothing_cash_needed;
    RUB clothing_card = alice.clothing * 0.8;  // 80% картой
    
    alice.cash -= clothing_cash;
    alice.bank.card -= clothing_card;
    
    stats.clothing_paid += alice.clothing;
    stats.cash_spent += clothing_cash;
    stats.card_spent += clothing_card;
    
    if (alice.main_bank != NULL) {
        RUB cashback = clothing_card * alice.main_bank->card_cashback;
        alice.bank.card += cashback;
        stats.cashback_received += cashback;
        if (cashback > 0) printf("  Кэшбэк за одежду: %lld руб.\n", cashback);
    }
    
    printf("  Одежда: наличные %lld руб., карта %lld руб.\n", clothing_cash, clothing_card);
}

void alice_food()
{
    // Определяем, есть ли праздничные дни в этом месяце
    static int current_month = 2;
    int is_holiday_month = (current_month == 12 || current_month == 1 || 
                            current_month == 3 || current_month == 5);
    
    // Определяем, сколько дней болели (10% шанс заболеть)
    int sick_days = 0;
    if (rand() % 100 < 10) {
        sick_days = 3 + rand() % 5;  // 3-7 дней
        printf("\n   Алиса болеет %d дней в этом месяце\n", sick_days);
    }
    
    // Рассчитываем расходы на еду
    struct FoodBudget food_budget = calculate_monthly_food(current_month, sick_days, is_holiday_month);
    
    RUB total_food_cost = food_budget.total_monthly;
    
    // Оплата (30% наличными, 70% картой)
    RUB food_cash_needed = total_food_cost * 0.3;
    
    if (alice.cash < food_cash_needed) {
        RUB needed = food_cash_needed - alice.cash;
        withdraw_cash(needed);
    }
    
    RUB food_cash = food_cash_needed;
    RUB food_card = total_food_cost * 0.7;
    
    alice.cash -= food_cash;
    alice.bank.card -= food_card;
    
    stats.food_paid += total_food_cost;
    stats.cash_spent += food_cash;
    stats.card_spent += food_card;
    
    // Кэшбэк
    if (alice.main_bank != NULL) {
        RUB cashback = food_card * alice.main_bank->card_cashback;
        alice.bank.card += cashback;
        stats.cashback_received += cashback;
        if (cashback > 0) printf("  Кэшбэк за продукты: %lld руб.\n", cashback);
    }
    
    // Вывод детализации
    printf("\n РАСХОДЫ НА ПИТАНИЕ ЗА МЕСЯЦ:\n");
    printf("  Завтраки:   %10lld руб.\n", food_budget.breakfast_cost);
    printf("  Обеды:      %10lld руб.\n", food_budget.lunch_cost);
    printf("  Ужины:      %10lld руб.\n", food_budget.dinner_cost);
    printf("  Перекусы:   %10lld руб.\n", food_budget.snacks_cost);
    printf("  Напитки:    %10lld руб.\n", food_budget.drinks_cost);
    printf("  ИТОГО:      %10lld руб.\n", total_food_cost);
    printf("  Оплачено: наличные %lld руб., карта %lld руб.\n", food_cash, food_card);
    
    // Обновляем текущий месяц для следующего вызова
    current_month++;
    if (current_month > 12) current_month = 1;
}

void alice_tax_refund(int year, int month)
{
    // делаем возврат в начале года
    if (month != 1) return;

    if (stats.tax_deduction_base <= 0) return;

    printf("\n ВОЗВРАТ НАЛОГОВОГО ВЫЧЕТА\n");

    // ограничение базы
    RUB base = stats.tax_deduction_base;
    if (base > 150000) base = 150000;

    RUB refund = base * 0.13;

    printf("  База для вычета: %lld руб.\n", base);
    printf("  Возвращено: %lld руб.\n", refund);
    printf("\n");

    alice.bank.card += refund;

    stats.total_events_impact -= refund;

    // обнуляем базу после возврата
    stats.tax_deduction_base = 0;
}


void alice_salary(const int year, const int month)
{
    RUB salary_to_pay = alice.salary;
    
    if (month == 3 && year == 2026) {
        RUB old_salary = alice.salary;
        alice.salary = alice.salary * 1.5;
        salary_to_pay = old_salary;
        printf("  ПОВЫШЕНИЕ ЗАРПЛАТЫ! Теперь %lld руб./мес\n", alice.salary);
    }
    
    RUB tax = salary_to_pay * 0.13;
    RUB after_tax = salary_to_pay - tax;
    
    alice.bank.card += after_tax;
    stats.salary_received += after_tax;
    stats.taxes_paid += tax;
    
    printf("  Зарплата: %lld руб., налог 13%%: %lld руб., на руки: %lld руб.\n", 
           salary_to_pay, tax, after_tax);
}


void alice_bank_interest()
{
    if (alice.bank.savings <= 0) return;
    
    if (alice.main_bank != NULL && alice.main_bank->calculate_rate != NULL) {
        alice.bank.rate = alice.main_bank->calculate_rate(alice.bank.savings);
    }
    
    RUB monthly_interest = alice.bank.savings * (alice.bank.rate / 12.0 / 100.0);
    alice.bank.savings += monthly_interest;
    
    stats.interest_received += monthly_interest;
    
    if (monthly_interest > 0) {
        printf("  Проценты по сбережениям: %lld руб. (ставка %.2f%%)\n", 
               monthly_interest, alice.bank.rate);
    }
}


void alice_manage_savings(const int month)
{
     // Если на карте больше 100 тыс - перекладываем излишек в сбережения
    if (alice.bank.card > 100000) {
        RUB transfer = (alice.bank.card - 50000) * 0.7;
        if (transfer > 0 && alice.main_bank != NULL && 
            transfer >= alice.main_bank->min_deposit) {
            alice.bank.savings += transfer;
            alice.bank.card -= transfer;
            stats.savings_moved += transfer;
            printf("  Переложено на сбережения: %lld руб.\n", transfer);
        }
    }
    
    // Если на карте меньше 20 тыс - снимаем со сбережений
    if (alice.bank.card < 20000 && alice.bank.savings > 0) {
        RUB withdraw = (alice.bank.savings * 0.2);
        if (withdraw > 0) {
            if (alice.bank.savings - withdraw < alice.main_bank->min_deposit) {
                withdraw = alice.bank.savings;
            }
            alice.bank.savings -= withdraw;
            alice.bank.card += withdraw;
            stats.savings_moved -= withdraw;
            printf("  Снято со сбережений: %lld руб.\n", withdraw);
        }
    }

    // Обновляем ставку (на случай, если сумма изменилась)
    if (alice.main_bank != NULL && alice.main_bank->calculate_rate != NULL) {
        float new_rate = alice.main_bank->calculate_rate(alice.bank.savings);
        if (new_rate != alice.bank.rate) {
            alice.bank.rate = new_rate;
            printf("  Ставка по сбережениям изменена на %.2f%%\n", alice.bank.rate);
        }
    }
}

// ============================================================
//  РЕАЛИЗАЦИЯ ФУНКЦИЙ ДЛЯ СИСТЕМЫ ПИТАНИЯ
// ============================================================

void init_product_prices(struct Fridge* fridge) {
    fridge->num_products = 0;
    
    struct ProductPrice p1 = {"овсянка", 40, 40};
    fridge->products[fridge->num_products++] = p1;
    
    struct ProductPrice p2 = {"молоко", 70, 70};
    fridge->products[fridge->num_products++] = p2;
    
    struct ProductPrice p3 = {"гречка", 45, 45};
    fridge->products[fridge->num_products++] = p3;
    
    struct ProductPrice p4 = {"рис", 42, 42};
    fridge->products[fridge->num_products++] = p4;
    
    struct ProductPrice p5 = {"манка", 35, 35};
    fridge->products[fridge->num_products++] = p5;
    
    struct ProductPrice p6 = {"перловка", 38, 38};
    fridge->products[fridge->num_products++] = p6;
    
    struct ProductPrice p7 = {"пшено", 40, 40};
    fridge->products[fridge->num_products++] = p7;
    
    struct ProductPrice p8 = {"хлеб", 45, 45};
    fridge->products[fridge->num_products++] = p8;
    
    struct ProductPrice p9 = {"сыр", 80, 80};
    fridge->products[fridge->num_products++] = p9;
    
    struct ProductPrice p10 = {"колбаса", 60, 60};
    fridge->products[fridge->num_products++] = p10;
    
    struct ProductPrice p11 = {"масло", 120, 120};
    fridge->products[fridge->num_products++] = p11;
    
    struct ProductPrice p12 = {"яйца", 12, 12};
    fridge->products[fridge->num_products++] = p12;
    
    struct ProductPrice p13 = {"творог", 60, 60};
    fridge->products[fridge->num_products++] = p13;
    
    struct ProductPrice p14 = {"сметана", 50, 50};
    fridge->products[fridge->num_products++] = p14;
    
    struct ProductPrice p15 = {"йогурт", 30, 30};
    fridge->products[fridge->num_products++] = p15;
    
    struct ProductPrice p16 = {"банан", 40, 40};
    fridge->products[fridge->num_products++] = p16;
    
    struct ProductPrice p17 = {"ряженка", 40, 40};
    fridge->products[fridge->num_products++] = p17;
    
    struct ProductPrice p18 = {"сухари", 20, 20};
    fridge->products[fridge->num_products++] = p18;
    
    struct ProductPrice p19 = {"кефир", 35, 35};
    fridge->products[fridge->num_products++] = p19;
    
    struct ProductPrice p20 = {"чай", 10, 10};
    fridge->products[fridge->num_products++] = p20;
    
    struct ProductPrice p21 = {"кофе", 15, 15};
    fridge->products[fridge->num_products++] = p21;
    
    struct ProductPrice p22 = {"сок", 50, 50};
    fridge->products[fridge->num_products++] = p22;
    
    struct ProductPrice p23 = {"курица", 110, 110};
    fridge->products[fridge->num_products++] = p23;
    
    struct ProductPrice p24 = {"картошка", 15, 15};
    fridge->products[fridge->num_products++] = p24;
    
    struct ProductPrice p25 = {"морковь", 12, 12};
    fridge->products[fridge->num_products++] = p25;
    
    struct ProductPrice p26 = {"капуста", 10, 10};
    fridge->products[fridge->num_products++] = p26;
    
    struct ProductPrice p27 = {"говядина", 180, 180};
    fridge->products[fridge->num_products++] = p27;
    
    struct ProductPrice p28 = {"сосиски", 70, 70};
    fridge->products[fridge->num_products++] = p28;
    
    struct ProductPrice p29 = {"помидоры", 40, 40};
    fridge->products[fridge->num_products++] = p29;
    
    struct ProductPrice p30 = {"огурцы", 35, 35};
    fridge->products[fridge->num_products++] = p30;
    
    struct ProductPrice p31 = {"лук", 8, 8};
    fridge->products[fridge->num_products++] = p31;
    
    struct ProductPrice p32 = {"вода", 1, 1};
    fridge->products[fridge->num_products++] = p32;
    
    struct ProductPrice p33 = {"макароны", 25, 25};
    fridge->products[fridge->num_products++] = p33;
    
    struct ProductPrice p34 = {"печенье", 30, 30};
    fridge->products[fridge->num_products++] = p34;
    
    struct ProductPrice p35 = {"шоколад", 10, 10};
    fridge->products[fridge->num_products++] = p35;
    
    struct ProductPrice p36 = {"чипсы", 25, 25};
    fridge->products[fridge->num_products++] = p36;
    
    struct ProductPrice p37 = {"орехи", 120, 120};
    fridge->products[fridge->num_products++] = p37;
    
    struct ProductPrice p38 = {"яблоко", 35, 35};
    fridge->products[fridge->num_products++] = p38;
    
    struct ProductPrice p39 = {"борщ набор", 120, 120};
    fridge->products[fridge->num_products++] = p39;
}

RUB get_product_price(struct Fridge* fridge, const char* name, double grams) {
    for (int i = 0; i < fridge->num_products; i++) {
        if (strcmp(fridge->products[i].name, name) == 0) {
            return fridge->products[i].price_per_unit * grams / 100;
        }
    }
    return 0;
}

const Recipe* pick_random_recipe(const Recipe recipes[], int count) {
    if (count == 0) return NULL;
    int index = rand() % count;
    return &recipes[index];
}

RUB cook_meal(struct Fridge* fridge, const Recipe* recipe, RUB* total_cost) {
    RUB meal_cost = 0;
    
    for (int i = 0; i < recipe->num_ingredients; i++) {
        RUB ingredient_cost = get_product_price(fridge, 
            recipe->ingredients[i].name, 
            recipe->ingredients[i].grams);
        meal_cost += ingredient_cost;
        
        /*printf("     %s: %.0f г → %lld руб.\n",
               recipe->ingredients[i].name,
               recipe->ingredients[i].grams,
               ingredient_cost);*/
    }
    
    //printf("     ИТОГО: %lld руб.\n", meal_cost);//
    *total_cost += meal_cost;
    
    return meal_cost;
}

struct FoodBudget calculate_monthly_food(int month, int sick_days, int is_holiday_month) {
    struct FoodBudget budget = {0, 0, 0, 0, 0, 0};
    int days_in_month = 30;
    
    for (int day = 1; day <= days_in_month; day++) {
        int is_sick = (day <= sick_days);
        int is_holiday = (is_holiday_month && (day == 1 || day == 31 || day % 7 == 0));
        
        if (is_sick) {
            // Больной режим
            cook_meal(&alice.fridge, 
                pick_random_recipe(sick_breakfast, sick_breakfast_count), &budget.total_monthly);
            cook_meal(&alice.fridge,
                pick_random_recipe(sick_main, sick_main_count), &budget.total_monthly);
            cook_meal(&alice.fridge,
                pick_random_recipe(sick_main, sick_main_count), &budget.total_monthly);
            cook_meal(&alice.fridge,
                pick_random_recipe(sick_drinks, sick_drinks_count), &budget.total_monthly);
        } else {
            // Обычный режим
            // Завтрак
            budget.breakfast_cost += cook_meal(&alice.fridge,
                pick_random_recipe(porridges, porridges_count), &budget.total_monthly);
            budget.drinks_cost += cook_meal(&alice.fridge,
                pick_random_recipe(breakfast_drinks, breakfast_drinks_count), &budget.total_monthly);
            
            // Обед
            budget.lunch_cost += cook_meal(&alice.fridge,
                pick_random_recipe(first_course, first_course_count), &budget.total_monthly);
            
            if (is_holiday) {
                budget.lunch_cost += cook_meal(&alice.fridge,
                    pick_random_recipe(holiday_lunches, holiday_lunches_count), &budget.total_monthly);
            } else {
                budget.lunch_cost += cook_meal(&alice.fridge,
                    pick_random_recipe(second_course, second_course_count), &budget.total_monthly);
            }
            
            budget.lunch_cost += cook_meal(&alice.fridge,
                pick_random_recipe(salads, salads_count), &budget.total_monthly);
            budget.drinks_cost += cook_meal(&alice.fridge,
                pick_random_recipe(day_drinks, day_drinks_count), &budget.total_monthly);
            
            // Ужин
            budget.dinner_cost += cook_meal(&alice.fridge,
                pick_random_recipe(light_dinner, light_dinner_count), &budget.total_monthly);
            budget.drinks_cost += cook_meal(&alice.fridge,
                pick_random_recipe(dinner_drinks, dinner_drinks_count), &budget.total_monthly);
            
            // Перекусы (70% вероятность)
            if (rand() % 100 < 70) {
                budget.snacks_cost += cook_meal(&alice.fridge,
                    pick_random_recipe(snacks, snacks_count), &budget.total_monthly);
            }
        }
    }
    
    return budget;
}

void update_product_prices(struct Fridge* fridge, int month) {
    //printf("\n ИНФЛЯЦИЯ НА ПРОДУКТЫ:\n");//
    
    for (int i = 0; i < fridge->num_products; i++) {
        RUB old_price = fridge->products[i].price_per_unit;
        
        // Разная инфляция для разных продуктов
        float product_inflation = 0.7;  // базовая 0.7%
        
        if (strcmp(fridge->products[i].name, "говядина") == 0 ||
            strcmp(fridge->products[i].name, "курица") == 0 ||
            strcmp(fridge->products[i].name, "сосиски") == 0) {
            product_inflation = 1.2;  // мясо дорожает быстрее
        } else if (strcmp(fridge->products[i].name, "картошка") == 0 ||
                   strcmp(fridge->products[i].name, "морковь") == 0 ||
                   strcmp(fridge->products[i].name, "капуста") == 0) {
            product_inflation = 0.5;  // овощи медленнее
        }
        
        float multiplier = 1.0 + product_inflation / 100.0;
        fridge->products[i].price_per_unit = 
            fridge->products[i].base_price * pow(multiplier, month - 1);
        
        /*if (fridge->products[i].price_per_unit != old_price && month > 2) {
            printf("  %s: %.0f → %.0f руб./100г (+%.1f%%)\n",
                   fridge->products[i].name, (double)old_price,
                   (double)fridge->products[i].price_per_unit, product_inflation);
        }*/
    }
}


void alice_simulation()
{
    int year = 2026;
    int month = 2;
    
    init_events_dynamic();
    schedule_events();
    
    printf("Стартовое состояние:\n");
    printf("  Наличные: %lld руб.\n", alice.cash);
    printf("  Карта: %lld руб.\n", alice.bank.card);
    printf("  Сбережения: %lld руб.\n\n", alice.bank.savings);
    
    while (!(year == 2027 && month == 2)) {
        printf("\n--- %d.%d ---\n", month, year);

        // ОБНОВЛЯЕМ ЦЕНЫ НА ПРОДУКТЫ (ИНФЛЯЦИЯ)
        update_product_prices(&alice.fridge, month);

        apply_gas_inflation(month);

        try_take_mortgage(&alice, year); //пытаемся взять ипотеку

        // Проверяем жизненные события
        check_events(year, month, &alice);
        
        alice_housing_expenses();
        alice_pay_mortgage();
        alice_food();
        alice_clothing();
        alice_car();
        alice_tax_refund(year, month);

        
        alice_bank_interest();
        alice_manage_savings(month);
        
        alice_salary(year, month);
        
        printf("  ИТОГ МЕСЯЦА: Наличные %lld, Карта %lld, Сбережения %lld\n", 
               alice.cash, alice.bank.card, alice.bank.savings);
        
        month++;
        if (month == 13) {
            year++;
            month = 1;
            printf("\n НОВЫЙ ГОД: %d \n", year);
        }
    }
}


void print_results()
{
    RUB nominal_capital = alice.cash + alice.car.value + 
                          alice.bank.card + alice.bank.savings;
    
    float inflation_factor = 1.0 + INFLATION_RATE / 100.0;
    RUB real_capital = nominal_capital / inflation_factor;

    RUB monthly_housing = alice.housing.rent + alice.housing.utilities + 
                          alice.housing.internet + alice.housing.mobile;
    
    RUB avg_food_cost = stats.food_paid / 12;  // средняя за год



    RUB monthly_total = monthly_housing + avg_food_cost + alice.clothing + alice.car.gas;
    
    printf("\n");
    printf("         ФИНАНСОВЫЙ ОТЧЕТ АЛИСЫ           \n");
    printf("      Период: Февраль 2026 - Февраль 2027\n");

    printf("\nТЕКУЩЕЕ СОСТОЯНИЕ\n");
    printf("  Наличные:                 %10lld руб.\n", alice.cash);
    printf("  Карта:                    %10lld руб.\n", alice.bank.card);
    printf("  Сбережения:               %10lld руб.\n", alice.bank.savings);
    printf("  Автомобиль:               %10lld руб.\n", alice.car.value);
    printf("  Текущая зарплата:         %10lld руб./мес\n", alice.salary);
    printf("  Процентная ставка:        %10.2f%%\n", alice.bank.rate);
    printf("\n");
    
    printf("КАПИТАЛ\n");
    printf("  Номинальный капитал:      %10lld руб.\n", nominal_capital);
    printf("  Реальный капитал (с\n");
    printf("  инфляцией %.1f%%):        %10lld руб.\n", 
           INFLATION_RATE, real_capital);
    printf("\n");

    printf("ДОХОДЫ (ЗА ГОД)\n");
    printf("  Получено зарплаты:        %10lld руб.\n", stats.salary_received);
    printf("  Получено кэшбэка:         %10lld руб.\n", stats.cashback_received);
    printf("  Получено процентов:       %10lld руб.\n", stats.interest_received);
    printf("  ВСЕГО ДОХОДОВ:            %10lld руб.\n", 
           stats.salary_received + stats.cashback_received + stats.interest_received);
    printf("\n");

    printf("РАСХОДЫ (ЗА ГОД)\n");
    printf("  Жилье:                    %10lld руб.\n", stats.housing_paid);
    printf("  Еда:                      %10lld руб.\n", stats.food_paid);
    printf("  Одежда:                   %10lld руб.\n", stats.clothing_paid);
    printf("  Бензин:                   %10lld руб.\n", stats.gas_paid);
    printf("  Налоги:                   %10lld руб.\n", stats.taxes_paid);
    printf("  ВСЕГО РАСХОДОВ:           %10lld руб.\n", 
           stats.housing_paid + stats.food_paid + stats.clothing_paid + 
           stats.gas_paid + stats.taxes_paid);
    printf("\n");
  
    printf("ЖИЗНЕННЫЕ СОБЫТИЯ\n");
    printf("  Использовано резервов:    %10lld руб.\n", stats.emergency_fund_used);
    printf("  Чистый эффект событий:    %10lld руб.\n", stats.total_events_impact);
    printf("\n");
  
    printf("ДВИЖЕНИЕ НАЛИЧНЫХ\n");
    printf("  Снято с карты:            %10lld руб.\n", stats.cash_withdrawn);
    printf("  Потрачено наличными:      %10lld руб.\n", stats.cash_spent);
    printf("\n");
 
    printf("СПОСОБЫ ОПЛАТЫ\n");
    RUB total_paid = stats.cash_spent + stats.card_spent;
    if (total_paid > 0) {
        printf("  Оплачено наличными:       %10lld руб. (%.1f%%)\n", 
               stats.cash_spent, 
               (float)stats.cash_spent / total_paid * 100);
        printf("  Оплачено картой:          %10lld руб. (%.1f%%)\n", 
               stats.card_spent,
               (float)stats.card_spent / total_paid * 100);
    }
    printf("\n");
  
    printf("ДВИЖЕНИЕ СБЕРЕЖЕНИЙ\n");
    if (stats.savings_moved >= 0) {
        printf("  Переложено в сбережения:  %10lld руб.\n", stats.savings_moved);
    } else {
        printf("  Снято со сбережений:      %10lld руб.\n", -stats.savings_moved);
    }
    printf("\n");
    
    printf("ЕЖЕМЕСЯЧНЫЕ РАСХОДЫ\n");
    printf("  Жилье:                    %10lld руб./мес\n", monthly_housing);
    printf("  Еда (среднее):            %10lld руб./мес\n", avg_food_cost);
    printf("  Одежда:                   %10lld руб./мес\n", alice.clothing);
    printf("  Бензин:                   %10lld руб./мес\n", alice.car.gas);
    printf("  ВСЕГО:                    %10lld руб./мес\n", monthly_total);
    printf("\n");

    if (alice.mortgage.active) {
    printf("  Остаток ипотеки:         %10lld руб.\n", alice.mortgage.total_amount);
    printf("  Платёж:                  %10lld руб./мес\n", alice.mortgage.monthly_payment);}
    
    printf("ИНФОРМАЦИЯ О БАНКЕ\n");
    printf("  Банк:                     %s\n", alice.main_bank->name);
    printf("  Кэшбэк по карте:          %.1f%%\n", 
           alice.main_bank->card_cashback * 100);
    printf("  Минимальная сумма депозита: %lld руб.\n", alice.main_bank->min_deposit);
    printf("\n");
    
    printf("ПРОИЗОШЕДШИЕ СОБЫТИЯ\n");
    int events_occurred = 0;
    
    for (size_t i = 0; i < events.size(); i++) {
        if (events[i].triggered) {
            printf("  ✓ %d.%d: %s\n", events[i].month, events[i].year, events[i].description);
            events_occurred++;
        }
    }
    if (events_occurred == 0) {
        printf("  Не произошло ни одного события\n");
    }
    printf("\n");

}

int main()
{
    srand(time(NULL)); 

    printf("ФИНАНСОВАЯ СИМУЛЯЦИЯ С ЖИЗНЕННЫМИ СОБЫТИЯМИ\n");
    
    alice_init();
    alice_simulation();
    print_results();
    
    return 0;
}
