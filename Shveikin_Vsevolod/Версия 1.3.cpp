#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;
using RUB = long long int;
using PERCENT = double;


const int MAX_EVENTS = 1000;
const int MAX_EVENT_LENGTH = 300;
const int MAX_PERSON_NAME = 100;


struct BankAccount {
    RUB balance;
    RUB microloan_debt;
    int microloan_months_remaining;
    RUB total_deposited;
    RUB total_withdrawn;
    int overdraft_count;
    int microloan_count;
    RUB total_microloan_interest;
};


struct HealthState {
    int physical;
    int mental;
    int stress;
    bool in_clinic;
    bool is_alive;
    bool died_from_debt;
    int last_checkup_month;
    int therapy_sessions;
    int hospital_visits;
    bool has_insurance;
};


struct House {
    RUB rent_cost;
    RUB utilities_cost;
    RUB maintenance_cost;
    bool is_owned;
    RUB current_market_value;
    string address;
    bool needs_repair;
    RUB repair_cost;
    int last_repair_month;
    bool has_alarm;
    RUB insurance_cost;
};


struct Education {
    int exam_score;
    int education_level;
    bool exams_passed;
    bool enrolled;
    RUB education_cost;
    string institution_name;
    int years_remaining;
    string status;
    bool can_study_later;
    RUB scholarship_amount;
    bool has_scholarship;
    int attendance_rate;
    RUB textbook_cost;
};


struct Car {
    RUB value;
    RUB gas_cost;
    RUB insurance_cost;
    RUB repair_cost;
    int year;
    string brand;
    bool is_working;
    int mileage;
    int last_service_month;
    RUB service_cost;
    bool needs_inspection;
};


struct Investment {
    string type;
    RUB amount;
    RUB current_value;
    PERCENT change_rate;
    int quantity;
    bool active;
    RUB purchase_price;
    int purchase_month;
    string broker_name;
    PERCENT commission;
};


struct Career {
    int level;
    string position;
    RUB base_salary;
    int experience;
    int skill_points;
    bool can_work;
    RUB monthly_bonus;
    bool is_fired;
    int months_unemployed;
    string company_name;
    int vacation_days;
    bool on_vacation;
};


struct Person {
    string name;
    int age;
    struct BankAccount account;
    struct HealthState health;
    struct Car car;
    struct Career career;
    struct Investment investments[10];
    int investment_count;
    RUB personal_spending_limit;
    bool is_parent;
    RUB total_earned_lifetime;
    RUB total_spent_lifetime;
    int birth_month;
    int birth_year;
    string phone_number;
    string email;
};


struct Pet {
    string name;
    int health;
    int mental_health;
    RUB food_cost;
    RUB vet_cost;
    bool is_alive;
    bool is_ill;
    int illness_severity;
    bool is_stray;
    string breed;
    int age_months;
    bool vaccinated;
    RUB vaccination_cost;
};


struct EventLog {
    string description;
    int month;
    int year;
    int type;
    string category;
    int priority;
    bool archived;
};


struct Prices {
    RUB food_base;
    RUB clothing_base;
    RUB transport_base;
    RUB entertainment_base;
    RUB medical_base;
    RUB education_base;
    RUB utilities_base;
    RUB gas_base;
    RUB inflation_multiplier;
    RUB housing_base;
    RUB insurance_base;
    RUB vacation_base;
};


struct MonthStats {
    int month;
    int year;
    RUB total_income;
    RUB total_expenses;
    RUB bank_interest;
    RUB microloan_payments;
    RUB shopping_expenses;
    RUB education_expenses;
    RUB investment_income;
    RUB investment_loss;
    RUB career_bonus;
    RUB vacation_expenses;
    RUB sanatorium_expenses;
    RUB unexpected_expenses;
    RUB entertainment_expenses;
    RUB clothing_expenses;
    RUB medical_expenses;
    RUB household_expenses;
    RUB transport_expenses;
    RUB food_expenses;
    RUB tax_payments;
    RUB insurance_payments;
    RUB car_maintenance;
    RUB pet_expenses;
    RUB utility_payments;
    RUB microloan_interest;
};


struct SimulationConfig {
    PERCENT bank_rate;
    PERCENT inflation_rate;
    PERCENT microloan_rate;
    int start_month;
    int start_year;
    int end_month;
    int end_year;
    bool is_running;
    int current_month_index;
    PERCENT tax_rate;
};


struct InvestmentMarket {
    RUB stocks_price;
    RUB bonds_price;
    RUB crypto_price;
    RUB realty_price;
    RUB gold_price;
    int volatility_index;
    string market_trend;
    PERCENT average_yield;
};


struct Family {
    struct Person husband;
    struct Person wife;
    struct Person daughter;
    struct Pet dog;
    struct Pet cat;
    RUB shared_budget_pool;
    int family_stress;
    int daughter_good_behavior_points;
    bool daughter_stole;
    int months_without_stealing;
    bool made_major_purchase;
    string major_purchase_name;
    RUB base_expenses;
    int total_earnings;
    int total_losses;
    int family_vacations;
    int family_sanatoriums;
    int total_microloans_taken;
    RUB total_microloan_debt_paid;
};


struct SimulationState {
    struct EventLog event_log[MAX_EVENTS];
    int event_count;
    int total_months;
    RUB total_income;
    RUB total_expenses;
    int bankruptcy_months;
    bool daughter_in_orphanage;
    bool simulation_ended;
    bool game_saved;
    int deaths_count;
    RUB cumulative_inflation;
    int warnings_count;
    int achievements_count;
    bool tutorial_shown;
};


struct Family g_family;
struct House g_house;
struct Education g_daughter_edu;
struct MonthStats g_current_stats;
struct SimulationConfig g_config;
struct InvestmentMarket g_market;
struct Prices g_prices;
struct SimulationState g_state;


const string g_minor_events_positive[] = {
    "Соседский ребёнок помог донести сумки",
    "На улице нашли кошелек с небольшой суммой",
    "Дочь получила похвалу в школе",
    "Муж нашел скидку на продукты",
    "Жена испекла вкусный праздничный торт",
    "Погода благоприятствовала прогулке",
    "Пришла премия на работу раньше срока",
    "Друзья подарили билет в кино",
    "Случайная находка в старой одежде",
    "Бесплатный концерт в парке",
    "Удалось избежать пробок",
    "Продавец дал скидку на одежду",
    "На работе оценили инициативу",
    "Получили подарок от родственников",
    "Удалось купить товар по акции",
    "Соседи угостили ужином",
    "Нашли хорошую парковку бесплатно",
    "Получили кэшбэк от банка",
    "Дочь принесла хорошую оценку",
    "Случайная встреча с другом"
};


const string g_minor_events_negative[] = {
    "Ребенок разбил дорогую вазу",
    "Потеряли ключи от квартиры",
    "Сломалась бытовая техника",
    "Штраф за неправильную парковку",
    "Порвалась дорогая одежда",
    "Отключили горячую воду",
    "Соседи затопили квартиру",
    "Потеряли банковскую карту",
    "Испорчены продукты в холодильнике",
    "Задержали зарплату на работе",
    "Поломка автомобиля в пути",
    "Укусил клещ в парке",
    "Потеряли телефон",
    "Сломался замок в двери",
    "Прорвало трубу в ванной",
    "Украли посылку из почтового ящика",
    "Испорчена обувь после дождя",
    "Отменили рейс в отпуске",
    "Поломался компьютер",
    "Потеряли документы"
};


const string g_minor_events_neutral[] = {
    "Обычный будничный день",
    "Просмотрели новый сериал",
    "Сходили в гости к родственникам",
    "Прибрались в квартире",
    "Купили новые шторы",
    "Позвонили старые друзья",
    "Изменили маршрут на работу",
    "Попробовали новое блюдо",
    "Почитали книги вечером",
    "Посетили выставку",
    "Сменили прическу",
    "Купили комнатные растения",
    "Прогулялись в парке",
    "Приготовили семейный ужин",
    "Посмотрели старый фильм",
    "Сходили в библиотеку",
    "Навестили бабушку",
    "Купили новые полотенца",
    "Помыли машину",
    "Сделали перестановку"
};


void print_header(const string& title) {
    cout << endl;
    cout << "================================================================" << endl;
    cout << " " << title << endl;
    cout << "================================================================" << endl;
}


void print_separator() {
    cout << "----------------------------------------------------------------" << endl;
}


void print_subseparator() {
    cout << "................................................................" << endl;
}


void print_person_health_status(const Person* p) {
    cout << " Здоровье: " << p->health.physical << "% | Психика: " << p->health.mental << "% | Стресс: " << p->health.stress << endl;
    if (!p->health.is_alive) {
        cout << " [СТАТУС: ПОКОЙНЫЙ]" << endl;
    }
    if (p->health.in_clinic) {
        cout << " [СТАТУС: В КЛИНИКЕ]" << endl;
    }
}


void print_person_career_status(const Person* p) {
    cout << " Должность: " << p->career.position << " (Ур. " << p->career.level << ")" << endl;
    cout << " Зарплата: " << p->career.base_salary << " руб." << endl;
    if (!p->career.can_work) {
        cout << " [СТАТУС: НЕ РАБОТАЕТ]" << endl;
    }
}


void print_person_finances(const Person* p) {
    cout << " Личный счет: " << p->account.balance << " руб." << endl;
    cout << " Микрозайм: " << p->account.microloan_debt << " руб." << endl;
    cout << " Всего микрозаймов: " << p->account.microloan_count << endl;
}


void print_family_budget_status() {
    cout << " Общий бюджет семьи: " << g_family.shared_budget_pool << " руб." << endl;
    cout << " Стресс семьи: " << g_family.family_stress << endl;
    cout << " Всего взято микрозаймов: " << g_family.total_microloans_taken << endl;
    cout << " Выплачено по микрозаймам: " << g_family.total_microloan_debt_paid << " руб." << endl;
    if (g_house.is_owned) {
        cout << " Жилье: Собственное (" << g_house.address << ")" << endl;
    }
    else {
        cout << " Жилье: Аренда (" << g_house.rent_cost << " руб./мес)" << endl;
    }
}


void print_market_status() {
    cout << " Акции: " << g_market.stocks_price << " руб." << endl;
    cout << " Облигации: " << g_market.bonds_price << " руб." << endl;
    cout << " Крипта: " << g_market.crypto_price << " руб." << endl;
    cout << " Недвижимость: " << g_market.realty_price << " руб." << endl;
}


void print_prices_status() {
    cout << " Инфляция: " << g_prices.inflation_multiplier << "x" << endl;
    cout << " Еда (база): " << g_prices.food_base << " руб." << endl;
    cout << " Одежда (база): " << g_prices.clothing_base << " руб." << endl;
    cout << " Транспорт (база): " << g_prices.transport_base << " руб." << endl;
}


void print_event_log_entry(const EventLog& ev) {
    string type_str = "";
    switch (ev.type) {
    case 0: type_str = "[ИНФО]"; break;
    case 1: type_str = "[УСПЕХ]"; break;
    case 2: case 3: type_str = "[РАСХОД]"; break;
    case 4: type_str = "[ПРОБЛЕМА]"; break;
    case 5: type_str = "[ТРАГЕДИЯ]"; break;
    default: type_str = "[???]"; break;
    }
    cout << setw(4) << ev.month << "." << setw(4) << ev.year << " " << type_str << " " << ev.description << endl;
}



void print_month_events() {
    print_header("СОБЫТИЯ МЕСЯЦА");

    int current_month = g_current_stats.month;
    int current_year = g_current_stats.year;
    int events_found = 0;

    for (int i = g_state.event_count - 1; i >= 0; i--) {
        if (g_state.event_log[i].month == current_month &&
            g_state.event_log[i].year == current_year) {
            print_event_log_entry(g_state.event_log[i]);
            events_found++;
        }
    }

    if (events_found == 0) {
        cout << "  [ИНФО] За этот месяц ничего значимого не произошло" << endl;
    }

    print_separator();
}

void print_month_summary_header() {
    print_header("ОТЧЕТ ЗА МЕСЯЦ");
    cout << "Месяц: " << g_current_stats.month << " | Год: " << g_current_stats.year << endl;
    print_separator();
}


void print_month_income_section() {
    cout << "ДОХОДЫ:" << endl;
    cout << "  Зарплаты: " << (g_current_stats.total_income - g_current_stats.bank_interest - g_current_stats.investment_income - g_current_stats.career_bonus) << " руб." << endl;
    cout << "  Проценты банка: " << g_current_stats.bank_interest << " руб." << endl;
    cout << "  Инвестиции: " << g_current_stats.investment_income << " руб." << endl;
    cout << "  Премии: " << g_current_stats.career_bonus << " руб." << endl;
}


void print_month_expenses_section() {
    cout << "РАСХОДЫ:" << endl;
    cout << "  Еда: " << g_current_stats.food_expenses << " руб." << endl;
    cout << "  Одежда: " << g_current_stats.clothing_expenses << " руб." << endl;
    cout << "  Развлечения: " << g_current_stats.entertainment_expenses << " руб." << endl;
    cout << "  Быт: " << g_current_stats.household_expenses << " руб." << endl;
    cout << "  Транспорт: " << g_current_stats.transport_expenses << " руб." << endl;
    cout << "  Покупки дочери: " << g_current_stats.shopping_expenses << " руб." << endl;
    cout << "  Образование: " << g_current_stats.education_expenses << " руб." << endl;
    cout << "  Отдых/Лечение: " << (g_current_stats.vacation_expenses + g_current_stats.sanatorium_expenses) << " руб." << endl;
    cout << "  Медицина: " << g_current_stats.medical_expenses << " руб." << endl;
    cout << "  Микрозаймы: " << g_current_stats.microloan_payments << " руб." << endl;
    cout << "  Проценты по микрозаймам: " << g_current_stats.microloan_interest << " руб." << endl;
    cout << "  Налоги: " << g_current_stats.tax_payments << " руб." << endl;
    cout << "  Страховки: " << g_current_stats.insurance_payments << " руб." << endl;
    cout << "  Неожиданное: " << g_current_stats.unexpected_expenses << " руб." << endl;
    cout << "  Убытки инвестиций: " << g_current_stats.investment_loss << " руб." << endl;
}


void print_month_final_balance() {
    print_separator();
    RUB balance = g_current_stats.total_income - g_current_stats.total_expenses;
    cout << "БАЛАНС МЕСЯЦА: " << balance << " руб." << endl;
    if (balance < 0) {
        cout << "[ВНИМАНИЕ] Отрицательный баланс!" << endl;
    }
    print_separator();
}


void print_final_report_header() {
    cout << endl;
    cout << "################################################################" << endl;
    cout << "#                                                              #" << endl;
    cout << "#                  ИТОГОВЫЙ ОТЧЕТ СИМУЛЯЦИИ                    #" << endl;
    cout << "#                                                              #" << endl;
    cout << "################################################################" << endl;
}


void print_final_family_status() {
    cout << "СОСТОЯНИЕ СЕМЬИ:" << endl;
    cout << " Муж: " << (g_family.husband.health.is_alive ? "Жив" : "Покойный") << endl;
    if (g_family.husband.health.is_alive) {
        cout << "   Микрозайм: " << g_family.husband.account.microloan_debt << " руб." << endl;
        cout << "   Всего микрозаймов: " << g_family.husband.account.microloan_count << endl;
        cout << "   Карьера: " << g_family.husband.career.position << endl;
    }
    cout << " Жена: " << (g_family.wife.health.is_alive ? "Жива" : "Покойная") << endl;
    if (g_family.wife.health.is_alive) {
        cout << "   Микрозайм: " << g_family.wife.account.microloan_debt << " руб." << endl;
        cout << "   Всего микрозаймов: " << g_family.wife.account.microloan_count << endl;
        cout << "   Карьера: " << g_family.wife.career.position << endl;
    }
    cout << " Дочь: " << (g_family.daughter.health.is_alive ? "Жива" : "Покойная") << endl;
    if (g_family.daughter.health.is_alive) {
        cout << "   Образование: " << g_daughter_edu.status << endl;
        cout << "   ВУЗ: " << g_daughter_edu.institution_name << endl;
        cout << "   Баллы ЕГЭ: " << g_daughter_edu.exam_score << endl;
    }
    cout << " Собака: " << (g_family.dog.is_alive ? "Жива" : "Покойная") << endl;
    cout << " Кошка: " << (g_family.cat.is_alive ? "Жива" : "Покойная") << endl;
    if (g_family.made_major_purchase) {
        cout << " Крупная покупка: " << g_family.major_purchase_name << endl;
    }
}


void print_final_financial_status() {
    cout << endl;
    cout << "ФИНАНСЫ:" << endl;
    cout << " Остаток на счетах: " << g_family.shared_budget_pool << " руб." << endl;
    cout << " Общий доход за все время: " << g_state.total_income << " руб." << endl;
    cout << " Общий расход за все время: " << g_state.total_expenses << " руб." << endl;
    cout << " Чистая прибыль: " << (g_state.total_income - g_state.total_expenses) << " руб." << endl;
    cout << " Всего взято микрозаймов: " << g_family.total_microloans_taken << endl;
    cout << " Выплачено по микрозаймам: " << g_family.total_microloan_debt_paid << " руб." << endl;
    cout << " Месяцев банкротства: " << g_state.bankruptcy_months << endl;
    cout << " Всего смертей: " << g_state.deaths_count << endl;
}


void print_final_achievements() {
    cout << endl;
    cout << "ДОСТИЖЕНИЯ:" << endl;
    if (g_daughter_edu.education_level == 3) {
        cout << " - Дочь окончила ВУЗ" << endl;
    }
    if (g_family.husband.career.level >= 4 || g_family.wife.career.level >= 4) {
        cout << " - Кто-то из родителей стал руководителем" << endl;
    }
    if (g_family.cat.is_alive) {
        cout << " - В семье есть кошка" << endl;
    }
    if (g_family.made_major_purchase) {
        cout << " - Совершена крупная покупка" << endl;
    }
    if (g_state.total_income > 5000000) {
        cout << " - Заработано более 5 млн руб." << endl;
    }
    if (g_state.bankruptcy_months == 0) {
        cout << " - Ни одного месяца банкротства" << endl;
    }
    if (g_family.total_microloans_taken == 0) {
        cout << " - Ни одного микрозайма" << endl;
    }
}


void print_event_log_full() {
    print_header("ЖУРНАЛ СОБЫТИЙ");
    cout << "Всего событий: " << g_state.event_count << endl;
    print_separator();
    int pos = 0, neg = 0, neu = 0;
    for (int i = 0; i < g_state.event_count; i++) {
        if (g_state.event_log[i].type == 1) pos++;
        else if (g_state.event_log[i].type == 4 || g_state.event_log[i].type == 5) neg++;
        else neu++;
    }
    cout << " Позитивные: " << pos << endl;
    cout << " Негативные: " << neg << endl;
    cout << " Нейтральные: " << neu << endl;
    print_separator();
    for (int i = 0; i < g_state.event_count; i++) {
        print_event_log_entry(g_state.event_log[i]);
    }
}


void print_minor_events_list() {
    cout << endl;
    cout << "ВОЗМОЖНЫЕ СОБЫТИЯ МЕСЯЦА:" << endl;
    cout << " Позитивные: " << sizeof(g_minor_events_positive) / sizeof(g_minor_events_positive[0]) << endl;
    cout << " Негативные: " << sizeof(g_minor_events_negative) / sizeof(g_minor_events_negative[0]) << endl;
    cout << " Нейтральные: " << sizeof(g_minor_events_neutral) / sizeof(g_minor_events_neutral[0]) << endl;
    print_separator();
}


void print_warning(const string& message) {
    cout << "[ПРЕДУПРЕЖДЕНИЕ] " << message << endl;
}


void print_error(const string& message) {
    cout << "[ОШИБКА] " << message << endl;
}


void print_success(const string& message) {
    cout << "[УСПЕХ] " << message << endl;
}


void print_info(const string& message) {
    cout << "[ИНФО] " << message << endl;
}


void add_event(const string& description, int type, const string& category = "ОБЩЕЕ") {
    if (g_state.event_count < MAX_EVENTS) {
        g_state.event_log[g_state.event_count].description = description;
        g_state.event_log[g_state.event_count].month = g_current_stats.month;
        g_state.event_log[g_state.event_count].year = g_current_stats.year;
        g_state.event_log[g_state.event_count].type = type;
        g_state.event_log[g_state.event_count].category = category;
        g_state.event_log[g_state.event_count].priority = 0;
        g_state.event_log[g_state.event_count].archived = false;
        g_state.event_count++;
    }
}


void init_config() {
    g_config.bank_rate = 14.5;
    g_config.inflation_rate = 8.0;
    g_config.microloan_rate = 2.0;
    g_config.start_month = 2;
    g_config.start_year = 2026;
    g_config.end_month = 3;
    g_config.end_year = 2027;
    g_config.is_running = true;
    g_config.current_month_index = 0;
    g_config.tax_rate = 13.0;
}


void init_market() {
    g_market.stocks_price = 1000;
    g_market.bonds_price = 500;
    g_market.crypto_price = 5000;
    g_market.realty_price = 100000;
    g_market.gold_price = 5000;
    g_market.volatility_index = 10;
    g_market.market_trend = "Стабильный";
    g_market.average_yield = 5.0;
}


void update_market() {
    int change = rand() % 20 - 10;
    g_market.stocks_price = (RUB)(g_market.stocks_price * (1 + change / 100.0));
    if (g_market.stocks_price < 500) g_market.stocks_price = 500;
    change = rand() % 10 - 5;
    g_market.bonds_price = (RUB)(g_market.bonds_price * (1 + change / 100.0));
    if (g_market.bonds_price < 500) g_market.bonds_price = 500;
    change = rand() % 40 - 20;
    g_market.crypto_price = (RUB)(g_market.crypto_price * (1 + change / 100.0));
    if (g_market.crypto_price < 500) g_market.crypto_price = 500;
    change = rand() % 15 - 5;
    g_market.realty_price = (RUB)(g_market.realty_price * (1 + change / 100.0));
    if (g_market.realty_price < 5000) g_market.realty_price = 5000;
}


void init_prices() {
    g_prices.food_base = 15000;
    g_prices.clothing_base = 5000;
    g_prices.transport_base = 3000;
    g_prices.entertainment_base = 5000;
    g_prices.medical_base = 10000;
    g_prices.education_base = 100000;
    g_prices.utilities_base = 5000;
    g_prices.gas_base = 50;
    g_prices.inflation_multiplier = 1.0;
    g_prices.housing_base = 30000;
    g_prices.insurance_base = 10000;
    g_prices.vacation_base = 50000;
}


void update_prices() {
    PERCENT monthly_inflation = g_config.inflation_rate / 100.0 / 12.0;
    g_prices.inflation_multiplier *= (1.0 + monthly_inflation);
    g_state.cumulative_inflation = (RUB)(g_prices.inflation_multiplier * 1000);
}


RUB get_dynamic_price(RUB base_price) {
    return (RUB)(base_price * g_prices.inflation_multiplier);
}


void init_bank_account(BankAccount* acc, RUB start_balance) {
    acc->balance = start_balance;
    acc->microloan_debt = 0;
    acc->microloan_months_remaining = 0;
    acc->total_deposited = 0;
    acc->total_withdrawn = 0;
    acc->overdraft_count = 0;
    acc->microloan_count = 0;
    acc->total_microloan_interest = 0;
}


void init_health(HealthState* h) {
    h->physical = 98 + (rand() % 3);
    h->mental = 90 + (rand() % 6);
    h->stress = 0;
    h->in_clinic = false;
    h->is_alive = true;
    h->died_from_debt = false;
    h->last_checkup_month = 0;
    h->therapy_sessions = 0;
    h->hospital_visits = 0;
    h->has_insurance = false;
}


void init_car(Car* car, const string& brand, RUB value, RUB gas) {
    car->value = value;
    car->gas_cost = gas;
    car->insurance_cost = 10000;
    car->repair_cost = 0;
    car->year = 2024;
    car->brand = brand;
    car->is_working = true;
    car->mileage = 0;
    car->last_service_month = 0;
    car->service_cost = 15000;
    car->needs_inspection = false;
}


void init_career(Career* career, int level, const string& position, RUB base_salary) {
    career->level = level;
    career->position = position;
    career->base_salary = base_salary;
    career->experience = 0;
    career->skill_points = 0;
    career->can_work = true;
    career->monthly_bonus = 0;
    career->is_fired = false;
    career->months_unemployed = 0;
    career->company_name = "Компания";
    career->vacation_days = 28;
    career->on_vacation = false;
}


void init_investment(Investment* inv, const string& type, RUB amount, RUB price, int qty) {
    inv->type = type;
    inv->amount = amount;
    inv->current_value = amount;
    inv->change_rate = 0;
    inv->quantity = qty;
    inv->active = true;
    inv->purchase_price = price;
    inv->purchase_month = g_current_stats.month;
    inv->broker_name = "Брокер";
    inv->commission = 0.5;
}


void init_person(Person* person, const string& name, int age, RUB salary, RUB capital, bool is_parent) {
    person->name = name;
    person->age = age;
    init_bank_account(&person->account, capital);
    init_health(&person->health);
    person->personal_spending_limit = 100000;
    person->is_parent = is_parent;
    person->total_earned_lifetime = 0;
    person->total_spent_lifetime = 0;
    person->investment_count = 0;
    person->birth_month = rand() % 12 + 1;
    person->birth_year = g_config.start_year - age;
    person->phone_number = "+7-XXX-XXX-XX-XX";
    person->email = name + "@example.com";
}


void init_pet(Pet* pet, const string& name, const string& breed) {
    pet->name = name;
    pet->breed = breed;
    pet->health = 100;
    pet->mental_health = 100;
    pet->food_cost = 5000;
    pet->vet_cost = 10000;
    pet->is_alive = true;
    pet->is_ill = false;
    pet->illness_severity = 0;
    pet->is_stray = false;
    pet->age_months = 12;
    pet->vaccinated = true;
    pet->vaccination_cost = 3000;
}


void init_house() {
    g_house.rent_cost = 30000;
    g_house.utilities_cost = 5000;
    g_house.maintenance_cost = 2000;
    g_house.is_owned = false;
    g_house.current_market_value = 5000000;
    g_house.address = "ул. Ленина, д. 10, кв. 5";
    g_house.needs_repair = false;
    g_house.repair_cost = 0;
    g_house.last_repair_month = 0;
    g_house.has_alarm = false;
    g_house.insurance_cost = 5000;
}


void init_education() {
    g_daughter_edu.exam_score = 0;
    g_daughter_edu.education_level = 0;
    g_daughter_edu.exams_passed = false;
    g_daughter_edu.enrolled = false;
    g_daughter_edu.education_cost = 0;
    g_daughter_edu.institution_name = "Не обучается";
    g_daughter_edu.years_remaining = 0;
    g_daughter_edu.status = "Школьница";
    g_daughter_edu.can_study_later = false;
    g_daughter_edu.scholarship_amount = 0;
    g_daughter_edu.has_scholarship = false;
    g_daughter_edu.attendance_rate = 95;
    g_daughter_edu.textbook_cost = 5000;
}


void init_state() {
    g_state.event_count = 0;
    g_state.total_months = 0;
    g_state.total_income = 0;
    g_state.total_expenses = 0;
    g_state.bankruptcy_months = 0;
    g_state.daughter_in_orphanage = false;
    g_state.simulation_ended = false;
    g_state.game_saved = false;
    g_state.deaths_count = 0;
    g_state.cumulative_inflation = 0;
    g_state.warnings_count = 0;
    g_state.achievements_count = 0;
    g_state.tutorial_shown = false;
}


void init_family() {
    init_person(&g_family.husband, "Отец", 35, 95000, 60000, true);
    init_car(&g_family.husband.car, "BMW X5", 5500000, 20000);
    init_career(&g_family.husband.career, 3, "Ведущий инженер", 95000);

    init_person(&g_family.wife, "Мать", 33, 75000, 0, true);
    init_car(&g_family.wife.car, "Toyota Camry", 2400000, 15000);
    init_career(&g_family.wife.career, 2, "Менеджер", 75000);

    g_family.shared_budget_pool = g_family.husband.account.balance + g_family.wife.account.balance;
    g_family.husband.account.balance = 0;
    g_family.wife.account.balance = 0;

    init_person(&g_family.daughter, "Дочь", 16, 0, 0, false);
    g_family.daughter.health.mental = 65 + (rand() % 10);
    init_career(&g_family.daughter.career, 0, "Школьница", 0);
    g_family.daughter.career.can_work = false;

    init_pet(&g_family.dog, "Бобик", "Овчарка");
    init_pet(&g_family.cat, "Барсик", "Дворовая");
    g_family.cat.is_alive = false;

    init_house();
    init_education();

    g_family.family_stress = 0;
    g_family.daughter_good_behavior_points = 0;
    g_family.daughter_stole = false;
    g_family.months_without_stealing = 0;
    g_family.made_major_purchase = false;
    g_family.major_purchase_name = "Нет";
    g_family.base_expenses = 30000;
    g_family.total_earnings = 0;
    g_family.total_losses = 0;
    g_family.family_vacations = 0;
    g_family.family_sanatoriums = 0;
    g_family.total_microloans_taken = 0;
    g_family.total_microloan_debt_paid = 0;
}


void init_stats() {
    g_current_stats.month = 0;
    g_current_stats.year = 0;
    g_current_stats.total_income = 0;
    g_current_stats.total_expenses = 0;
    g_current_stats.bank_interest = 0;
    g_current_stats.microloan_payments = 0;
    g_current_stats.shopping_expenses = 0;
    g_current_stats.education_expenses = 0;
    g_current_stats.investment_income = 0;
    g_current_stats.investment_loss = 0;
    g_current_stats.career_bonus = 0;
    g_current_stats.vacation_expenses = 0;
    g_current_stats.sanatorium_expenses = 0;
    g_current_stats.unexpected_expenses = 0;
    g_current_stats.entertainment_expenses = 0;
    g_current_stats.clothing_expenses = 0;
    g_current_stats.medical_expenses = 0;
    g_current_stats.household_expenses = 0;
    g_current_stats.transport_expenses = 0;
    g_current_stats.food_expenses = 0;
    g_current_stats.tax_payments = 0;
    g_current_stats.insurance_payments = 0;
    g_current_stats.car_maintenance = 0;
    g_current_stats.pet_expenses = 0;
    g_current_stats.utility_payments = 0;
    g_current_stats.microloan_interest = 0;
}


void split_expense_proportional(RUB amount, Person* p1, Person* p2) {
    if (amount <= 0) return;
    RUB total_available = p1->account.balance + p2->account.balance;
    if (total_available <= 0) {
        g_family.shared_budget_pool -= amount;
        g_current_stats.total_expenses += amount;
        return;
    }
    RUB ratio1 = (p1->account.balance > 0) ? (double)p1->account.balance / total_available : 0.0;
    RUB ratio2 = (p2->account.balance > 0) ? (double)p2->account.balance / total_available : 0.0;
    RUB pay1 = (RUB)(amount * ratio1);
    RUB pay2 = amount - pay1;
    if (p1->account.balance < pay1) {
        RUB diff = pay1 - p1->account.balance;
        p1->account.balance = 0;
        pay2 += diff;
    }
    else {
        p1->account.balance -= pay1;
    }
    if (p2->account.balance < pay2) {
        RUB diff = pay2 - p2->account.balance;
        p2->account.balance = 0;
        g_family.shared_budget_pool -= diff;
    }
    else {
        p2->account.balance -= pay2;
    }
    g_current_stats.total_expenses += amount;
}


void process_expense(Person* p, RUB amount, int category) {
    if (!p->health.is_alive) return;
    if (p->account.balance >= amount) {
        p->account.balance -= amount;
        p->account.total_withdrawn += amount;
    }
    else {
        RUB diff = amount - p->account.balance;
        p->account.balance = 0;
        g_family.shared_budget_pool -= diff;
        p->account.overdraft_count++;
    }
    g_current_stats.total_expenses += amount;
    p->total_spent_lifetime += amount;
    switch (category) {
    case 1: g_current_stats.food_expenses += amount; break;
    case 2: g_current_stats.clothing_expenses += amount; break;
    case 3: g_current_stats.entertainment_expenses += amount; break;
    case 4: g_current_stats.household_expenses += amount; break;
    case 5: g_current_stats.transport_expenses += amount; break;
    case 6: g_current_stats.medical_expenses += amount; break;
    case 7: g_current_stats.education_expenses += amount; break;
    case 8: g_current_stats.vacation_expenses += amount; break;
    case 9: g_current_stats.sanatorium_expenses += amount; break;
    case 10: g_current_stats.unexpected_expenses += amount; break;
    case 11: g_current_stats.pet_expenses += amount; break;
    case 12: g_current_stats.utility_payments += amount; break;
    case 13: g_current_stats.insurance_payments += amount; break;
    case 14: g_current_stats.car_maintenance += amount; break;
    }
}


void process_income(Person* p, RUB amount) {
    if (!p->health.is_alive) return;
    p->account.balance += amount;
    p->account.total_deposited += amount;
    g_current_stats.total_income += amount;
    p->total_earned_lifetime += amount;
}


void take_microloan(Person* p, RUB amount) {
    if (amount <= 0) return;
    if (p->account.microloan_debt > 0) return;
    if (amount > 100000) amount = 100000;
    p->account.microloan_debt += amount;
    p->account.microloan_months_remaining = 12;
    p->account.microloan_count++;
    g_family.shared_budget_pool += amount;
    g_family.total_microloans_taken++;
    g_current_stats.total_income += amount;
    string event_msg = "Взят микрозайм: " + to_string(amount) + " руб.";
    add_event(event_msg, 4, "ФИНАНСЫ");
}


void pay_microloan(Person* p) {
    if (p->account.microloan_debt <= 0) return;
    RUB monthly_payment = (RUB)(p->account.microloan_debt * g_config.microloan_rate / 100.0);
    RUB principal = p->account.microloan_debt / 12;
    RUB total = monthly_payment + principal;
    if (p->account.balance >= total) {
        p->account.balance -= total;
        p->account.microloan_debt -= principal;
        p->account.total_microloan_interest += monthly_payment;
        g_current_stats.total_expenses += total;
        g_current_stats.microloan_payments += total;
        g_current_stats.microloan_interest += monthly_payment;
        g_family.total_microloan_debt_paid += total;
        p->account.microloan_months_remaining--;
        p->health.stress += 5;
        if (p->account.microloan_debt <= 0) {
            p->account.microloan_debt = 0;
            add_event("Микрозайм погашен", 1, "ФИНАНСЫ");
        }
    }
    else {
        p->account.microloan_debt += monthly_payment;
        p->health.stress += 10;
        add_event("Просрочка микрозайма", 5, "ФИНАНСЫ");
    }
    if (p->account.microloan_months_remaining <= 0) {
        p->account.microloan_debt = 0;
    }
}


void check_microloan_need() {
    if (g_family.husband.account.microloan_debt > 0) return;
    if (g_family.shared_budget_pool < -50000) {
        RUB loan = 100000;
        take_microloan(&g_family.husband, loan);
        g_family.family_stress += 20;
    }
}


void person_salary(Person* p, int month, int year) {
    if (!p->health.is_alive || p->health.in_clinic) return;
    if (p->career.base_salary <= 0) return;
    if (!p->career.can_work) return;
    if ((month == 8) && (year == 2026) && (p->career.base_salary > 50000)) {
        p->career.base_salary = (RUB)(p->career.base_salary * 1.5);
        add_event(p->name + " повысили зарплату", 1, "КАРЬЕРА");
    }
    if ((month == 1) && (year > 2026)) {
        p->career.base_salary = (RUB)(p->career.base_salary * 1.1);
        add_event(p->name + " индексация зарплаты", 1, "КАРЬЕРА");
    }
    RUB tax = (RUB)(p->career.base_salary * 0.13);
    RUB net_salary = p->career.base_salary - tax;
    process_income(p, net_salary);
    g_current_stats.tax_payments += tax;
}


void person_food(Person* p) {
    if (!p->health.is_alive || p->health.in_clinic) return;
    RUB base = g_prices.food_base;
    if (!p->is_parent) base = base / 3;
    RUB actual = get_dynamic_price(base);
    process_expense(p, actual, 1);
}


void person_clothing(Person* p) {
    if (!p->health.is_alive || p->health.in_clinic) return;
    RUB actual = get_dynamic_price(g_prices.clothing_base);
    process_expense(p, actual, 2);
}


void person_entertainment(Person* p) {
    if (!p->health.is_alive || p->health.in_clinic) return;
    RUB actual = get_dynamic_price(g_prices.entertainment_base);
    process_expense(p, actual, 3);
}


void person_household(Person* p) {
    if (!p->health.is_alive || p->health.in_clinic) return;
    RUB actual = get_dynamic_price(g_prices.utilities_base / 2);
    process_expense(p, actual, 4);
}


void person_transport(Person* p) {
    if (!p->health.is_alive || p->health.in_clinic) return;
    RUB actual = get_dynamic_price(g_prices.transport_base);
    process_expense(p, actual, 5);
}


void person_car(Person* p) {
    if (!p->health.is_alive || p->health.in_clinic) return;
    if (p->car.value <= 0) return;
    RUB gas = get_dynamic_price(p->car.gas_cost);
    process_expense(p, gas, 5);
    if (g_current_stats.month == 1) {
        RUB insurance = get_dynamic_price(p->car.insurance_cost);
        process_expense(p, insurance, 13);
        g_current_stats.insurance_payments += insurance;
    }
    int repair_chance = rand() % 100;
    if (repair_chance < 5) {
        RUB repair = 50000;
        process_expense(p, repair, 14);
        p->health.stress += 10;
        add_event("Ремонт автомобиля", 4, "ТРАНСПОРТ");
    }
}


void person_utilities() {
    RUB actual = g_house.utilities_cost;
    if ((g_current_stats.month >= 11) || (g_current_stats.month <= 3)) {
        actual = (RUB)(actual * 1.3);
    }
    split_expense_proportional(actual, &g_family.husband, &g_family.wife);
}


void daughter_shopping() {
    if (!g_family.daughter.health.is_alive || g_family.daughter.health.in_clinic) return;
    if (g_family.daughter.health.mental >= 50) return;
    int shopping_chance = rand() % 100;
    if (shopping_chance >= 40) return;
    RUB shopping = 5000;
    if (g_family.shared_budget_pool >= shopping) {
        g_family.shared_budget_pool -= shopping;
        g_current_stats.total_expenses += shopping;
        g_current_stats.shopping_expenses += shopping;
        g_family.daughter.health.mental += 20;
        g_family.daughter.health.stress -= 10;
        g_family.daughter_good_behavior_points += 1;
        add_event("Покупки для дочери", 2, "СЕМЬЯ");
    }
}


void daughter_stealing_check() {
    if (!g_family.daughter.health.is_alive || g_family.daughter.health.in_clinic) return;
    int steal_chance = rand() % 100;
    if (g_family.daughter.account.balance < 0 && steal_chance < 10) {
        g_family.daughter_stole = true;
        g_family.months_without_stealing = 0;
        RUB stolen = 10000 + (rand() % 5000);
        g_family.shared_budget_pool -= stolen;
        g_family.daughter.account.balance += stolen;
        g_current_stats.total_expenses += stolen;
        g_family.daughter.health.mental -= 30;
        g_family.daughter.health.stress += 25;
        g_family.family_stress += 15;
        add_event("Дочь украла деньги", 5, "СЕМЬЯ");
    }
    else if (g_family.daughter.account.balance >= 0) {
        g_family.months_without_stealing++;
        if (g_family.months_without_stealing <= 12) {
            g_family.daughter_good_behavior_points += 1;
        }
    }
}


void person_mental_health(Person* p) {
    if (!p->health.is_alive) return;
    p->health.stress += 5;
    p->health.mental -= (p->health.stress / 10);
    p->health.mental -= 2;
    if (g_family.shared_budget_pool < 50000) {
        p->health.stress += 10;
        p->health.mental -= 5;
    }
    if (p->account.microloan_debt > 0) {
        p->health.stress += 15;
        p->health.mental -= 8;
    }
    if (p->health.mental < 30) p->health.stress += 15;
    if (p->health.mental > 70) p->health.stress -= 5;
    if (p->health.stress < 0) p->health.stress = 0;
    if (p->health.mental < 0) p->health.mental = 0;
    if (p->health.mental > 95) p->health.mental = 95;
    p->health.mental += (rand() % 5) - 2;
    if (p->health.mental > 95) p->health.mental = 95;
    if (p->health.mental < 70) p->health.mental = 70;
}


void daughter_mental_health() {
    if (!g_family.daughter.health.is_alive || g_family.daughter.health.in_clinic) return;
    g_family.daughter.health.mental -= 20;
    g_family.daughter.health.stress += 18;
    if (g_family.shared_budget_pool < 100000) {
        g_family.daughter.health.mental -= 12;
        g_family.daughter.health.stress += 15;
    }
    if (g_family.husband.health.mental < 50 || g_family.wife.health.mental < 50) {
        g_family.daughter.health.mental -= 15;
    }
    if (g_family.cat.is_alive) {
        g_family.daughter.health.mental += 8;
        g_family.daughter.health.stress -= 5;
    }
    if (g_family.daughter.health.mental < 0) g_family.daughter.health.mental = 0;
    if (g_family.daughter.health.mental > 85) g_family.daughter.health.mental = 85;
    g_family.daughter.health.mental += (rand() % 8) - 4;
    if (g_family.daughter.health.mental > 85) g_family.daughter.health.mental = 85;
    if (g_family.daughter.health.mental < 50) g_family.daughter.health.mental = 50;
}


void person_health_update() {
    Person* persons[3] = { &g_family.husband, &g_family.wife, &g_family.daughter };
    for (int i = 0; i < 3; i++) {
        if (!persons[i]->health.is_alive) continue;
        persons[i]->health.physical += (rand() % 5) - 2;
        if (persons[i]->health.physical > 100) persons[i]->health.physical = 100;
        if (persons[i]->health.physical < 95) persons[i]->health.physical = 95;
    }
}


void person_rest(Person* p) {
    if (!p->health.is_alive || p->health.in_clinic) return;
    p->health.mental += 10;
    p->health.stress -= 10;
    if (p->health.mental > 95) p->health.mental = 95;
    if (p->health.stress < 0) p->health.stress = 0;
}


void person_therapist(Person* p) {
    if (!p->health.is_alive || p->health.in_clinic) return;
    RUB cost = 15000;
    if (g_family.shared_budget_pool >= cost) {
        split_expense_proportional(cost, &g_family.husband, &g_family.wife);
        g_current_stats.medical_expenses += cost;
        p->health.mental += 25;
        p->health.stress -= 20;
        if (p->health.mental > 95) p->health.mental = 95;
        if (p->health.stress < 0) p->health.stress = 0;
        add_event(p->name + " посетил терапевта", 2, "ЗДОРОВЬЕ");
    }
}


void person_clinic_check(Person* p) {
    if (!p->health.is_alive) return;
    if (p->health.mental <= 0 && !p->health.in_clinic) {
        p->health.in_clinic = true;
        p->health.stress = 0;
        add_event(p->name + " в клинике", 5, "ЗДОРОВЬЕ");
    }
    if (p->health.in_clinic && p->health.mental > 50) {
        p->health.in_clinic = false;
        add_event(p->name + " выписан из клиники", 1, "ЗДОРОВЬЕ");
    }
}


void check_auto_sanatorium() {
    if (g_family.husband.health.physical < 60 || g_family.wife.health.physical < 60) {
        RUB cost = 30000;
        if (g_family.shared_budget_pool >= cost) {
            split_expense_proportional(cost, &g_family.husband, &g_family.wife);
            g_current_stats.sanatorium_expenses += cost;
            g_family.husband.health.physical += 10;
            g_family.wife.health.physical += 10;
            g_family.husband.health.mental += 15;
            g_family.wife.health.mental += 15;
            add_event("Поездка в санаторий", 1, "ЗДОРОВЬЕ");
        }
    }
}


void check_auto_vacation() {
    if (g_family.husband.health.stress > 50 || g_family.wife.health.stress > 50) {
        RUB cost = 50000;
        if (g_family.shared_budget_pool >= cost) {
            split_expense_proportional(cost, &g_family.husband, &g_family.wife);
            g_current_stats.vacation_expenses += cost;
            g_family.husband.health.mental += 20;
            g_family.wife.health.mental += 20;
            g_family.daughter.health.mental += 15;
            g_family.husband.health.stress -= 15;
            g_family.wife.health.stress -= 15;
            add_event("Семейный отпуск", 1, "ОТДЫХ");
        }
    }
}


void check_auto_courses() {
    if (g_family.husband.career.skill_points < 50) {
        RUB cost = 35000;
        if (g_family.shared_budget_pool >= cost) {
            split_expense_proportional(cost, &g_family.husband, &g_family.wife);
            g_family.husband.career.skill_points += 15;
            g_family.husband.health.mental += 10;
            add_event("Курсы повышения квалификации", 2, "КАРЬЕРА");
        }
    }
}


void pet_care() {
    if (!g_family.dog.is_alive) return;
    g_family.dog.health -= 2;
    RUB food = g_family.dog.food_cost;
    split_expense_proportional(food, &g_family.husband, &g_family.wife);
    int illness_chance = rand() % 100;
    if (illness_chance < 8 && !g_family.dog.is_ill) {
        g_family.dog.is_ill = true;
        g_family.dog.illness_severity = rand() % 3 + 1;
        add_event("Собака заболела", 4, "ПИТОМЦЫ");
    }
    if (g_family.dog.is_ill) {
        RUB vet = g_family.dog.vet_cost * g_family.dog.illness_severity;
        split_expense_proportional(vet, &g_family.husband, &g_family.wife);
        g_current_stats.medical_expenses += vet;
        g_family.dog.health -= 10 * g_family.dog.illness_severity;
        int recovery = rand() % 100;
        if (recovery < 60) {
            g_family.dog.is_ill = false;
            g_family.dog.illness_severity = 0;
            add_event("Собака выздоровела", 1, "ПИТОМЦЫ");
        }
    }
    int death_chance = rand() % 1000;
    if (g_family.dog.health <= 0 || death_chance < 3) {
        g_family.dog.is_alive = false;
        add_event("Собака умерла", 5, "ПИТОМЦЫ");
        g_family.wife.health.mental -= 20;
        g_family.daughter.health.mental -= 25;
    }
    if (g_family.dog.health < 50 && !g_family.dog.is_ill) {
        RUB vet = g_family.dog.vet_cost;
        split_expense_proportional(vet, &g_family.husband, &g_family.wife);
        g_current_stats.medical_expenses += vet;
        g_family.dog.health += 30;
        add_event("Визит к ветеринару", 2, "ПИТОМЦЫ");
    }
}


void pet_cat_care() {
    if (!g_family.cat.is_alive) return;
    RUB food = 3000;
    split_expense_proportional(food, &g_family.husband, &g_family.wife);
    g_family.cat.health += 1;
    if (g_family.cat.health > 100) g_family.cat.health = 100;
    int illness_chance = rand() % 100;
    if (illness_chance < 6 && !g_family.cat.is_ill) {
        g_family.cat.is_ill = true;
        g_family.cat.illness_severity = rand() % 3 + 1;
        add_event("Кошка заболела", 4, "ПИТОМЦЫ");
    }
    if (g_family.cat.is_ill) {
        RUB vet = g_family.cat.vet_cost * g_family.cat.illness_severity;
        split_expense_proportional(vet, &g_family.husband, &g_family.wife);
        g_current_stats.medical_expenses += vet;
        g_family.cat.health -= 8 * g_family.cat.illness_severity;
        int recovery = rand() % 100;
        if (recovery < 65) {
            g_family.cat.is_ill = false;
            g_family.cat.illness_severity = 0;
            add_event("Кошка выздоровела", 1, "ПИТОМЦЫ");
        }
    }
    int death_chance = rand() % 1500;
    if (g_family.cat.health <= 0 || death_chance < 2) {
        g_family.cat.is_alive = false;
        add_event("Кошка умерла", 5, "ПИТОМЦЫ");
        g_family.daughter.health.mental -= 30;
    }
    if (g_family.cat.health < 50 && !g_family.cat.is_ill) {
        RUB vet = g_family.cat.vet_cost;
        split_expense_proportional(vet, &g_family.husband, &g_family.wife);
        g_current_stats.medical_expenses += vet;
        g_family.cat.health += 25;
        add_event("Визит к ветеринару", 2, "ПИТОМЦЫ");
    }
    g_family.cat.mental_health += 5;
    if (g_family.cat.mental_health > 100) g_family.cat.mental_health = 100;
}


void check_new_pet() {
    if (g_family.cat.is_alive) return;
    if (!g_family.husband.health.is_alive || !g_family.wife.health.is_alive) return;
    if (g_family.daughter_good_behavior_points >= 20 && g_family.months_without_stealing >= 3) {
        g_family.cat.is_alive = true;
        add_event("Купили новую кошку", 1, "ПИТОМЦЫ");
        g_family.daughter.health.mental += 20;
        g_family.daughter_good_behavior_points = 0;
    }
    int stray_chance = rand() % 100;
    if (stray_chance < 5 && !g_family.cat.is_alive) {
        g_family.cat.is_alive = true;
        g_family.cat.is_stray = true;
        add_event("Подобрали бездомную кошку", 1, "ПИТОМЦЫ");
        g_family.daughter.health.mental += 15;
    }
}


void minor_events_list() {
    print_minor_events_list();
}


void minor_events_apply() {
    int event_type = rand() % 100;
    string event_msg = "";
    int type = 0;
    bool affects_daughter_mental = false;
    int mental_decrease = 0;
    if (event_type < 35) {
        int idx = rand() % 20;
        event_msg = g_minor_events_positive[idx];
        type = 1;
        g_family.daughter_good_behavior_points += 1;
        add_event(event_msg, 1, "СОБЫТИЯ");
    }
    else if (event_type < 70) {
        int neg_index = rand() % 20;
        event_msg = g_minor_events_negative[neg_index];
        type = 4;
        g_family.family_stress += 2;
        if (neg_index == 1 || neg_index == 4 || neg_index == 10 || neg_index == 12) {
            affects_daughter_mental = true;
            mental_decrease = 8 + (rand() % 7);
        }
        add_event(event_msg, 4, "СОБЫТИЯ");
    }
    else {
        int idx = rand() % 20;
        event_msg = g_minor_events_neutral[idx];
        type = 0;
        add_event(event_msg, 0, "СОБЫТИЯ");
    }
    if (affects_daughter_mental && g_family.daughter.health.is_alive) {
        g_family.daughter.health.mental -= mental_decrease;
        g_family.daughter.health.stress += 5;
        if (g_family.daughter.health.mental < 0) g_family.daughter.health.mental = 0;
    }
}


void daughter_exams() {
    if (!g_family.daughter.health.is_alive) return;
    if (g_daughter_edu.exams_passed) return;
    if (g_current_stats.month == 5 && g_current_stats.year == 2026) {
        int base_score = 50 + (g_family.daughter.health.mental / 5);
        if (g_family.husband.health.mental > 70 && g_family.wife.health.mental > 70) {
            base_score += 10;
        }
        if (g_family.shared_budget_pool > 200000) {
            base_score += 10;
        }
        if (!g_family.daughter_stole && g_family.months_without_stealing >= 3) {
            base_score += 15;
        }
        int random_factor = rand() % 30 - 15;
        g_daughter_edu.exam_score = base_score + random_factor;
        if (g_daughter_edu.exam_score < 0) g_daughter_edu.exam_score = 0;
        if (g_daughter_edu.exam_score > 100) g_daughter_edu.exam_score = 100;
        g_daughter_edu.exams_passed = true;
        string event_msg = "ЕГЭ сдан: " + to_string(g_daughter_edu.exam_score) + " баллов";
        add_event(event_msg, 3, "ОБРАЗОВАНИЕ");
        if (g_daughter_edu.exam_score >= 80) {
            g_family.daughter_good_behavior_points += 20;
        }
        else if (g_daughter_edu.exam_score >= 60) {
            g_family.daughter_good_behavior_points += 10;
        }
        else if (g_daughter_edu.exam_score >= 40) {
            g_family.daughter_good_behavior_points += 5;
        }
    }
}


void daughter_education_choice() {
    if (!g_family.daughter.health.is_alive) return;
    if (!g_daughter_edu.exams_passed) return;
    if (g_daughter_edu.enrolled) return;
    if (g_current_stats.month == 6 && g_current_stats.year == 2026) {
        RUB base_cost = 0;
        RUB discount = 0;
        if (g_daughter_edu.exam_score >= 80) {
            base_cost = 250000;
            discount = (RUB)(base_cost * 0.20);
        }
        else if (g_daughter_edu.exam_score >= 60) {
            base_cost = 150000;
            discount = (RUB)(base_cost * 0.10);
        }
        else if (g_daughter_edu.exam_score >= 40) {
            base_cost = 50000;
            discount = 0;
        }
        RUB final_cost = base_cost - discount;
        if (g_daughter_edu.exam_score >= 80 && g_family.shared_budget_pool >= final_cost) {
            g_daughter_edu.education_level = 3;
            g_daughter_edu.education_cost = final_cost;
            g_daughter_edu.years_remaining = 4;
            g_daughter_edu.institution_name = "МГУ";
            g_daughter_edu.status = "Студент";
            add_event("Поступление в МГУ", 1, "ОБРАЗОВАНИЕ");
        }
        else if (g_daughter_edu.exam_score >= 60 && g_family.shared_budget_pool >= final_cost) {
            g_daughter_edu.education_level = 3;
            g_daughter_edu.education_cost = final_cost;
            g_daughter_edu.years_remaining = 4;
            g_daughter_edu.institution_name = "ВШЭ";
            g_daughter_edu.status = "Студент";
            add_event("Поступление в ВШЭ", 1, "ОБРАЗОВАНИЕ");
        }
        else if (g_daughter_edu.exam_score >= 40 && g_family.shared_budget_pool >= final_cost) {
            g_daughter_edu.education_level = 2;
            g_daughter_edu.education_cost = final_cost;
            g_daughter_edu.years_remaining = 2;
            g_daughter_edu.institution_name = "Колледж";
            g_daughter_edu.status = "Студент";
            add_event("Поступление в колледж", 1, "ОБРАЗОВАНИЕ");
        }
        else {
            g_daughter_edu.education_level = 1;
            g_daughter_edu.education_cost = 0;
            g_daughter_edu.years_remaining = 0;
            g_daughter_edu.institution_name = "Работа";
            g_daughter_edu.can_study_later = true;
            add_event("Работа вместо ВУЗа", 3, "ОБРАЗОВАНИЕ");
        }
        if (g_daughter_edu.education_cost > 0) {
            if (g_family.shared_budget_pool >= g_daughter_edu.education_cost) {
                g_family.shared_budget_pool -= g_daughter_edu.education_cost;
                g_current_stats.total_expenses += g_daughter_edu.education_cost;
                g_current_stats.education_expenses += g_daughter_edu.education_cost;
            }
            else {
                RUB microloan_amount = g_daughter_edu.education_cost;
                if (microloan_amount > 100000) microloan_amount = 100000;
                take_microloan(&g_family.husband, microloan_amount);
                g_family.shared_budget_pool -= g_daughter_edu.education_cost;
                g_current_stats.total_expenses += g_daughter_edu.education_cost;
                g_current_stats.education_expenses += g_daughter_edu.education_cost;
            }
        }
        g_daughter_edu.enrolled = true;
        if (g_daughter_edu.education_level >= 2) {
            g_family.daughter.career.can_work = false;
        }
        else {
            g_family.daughter.career.can_work = true;
            g_family.daughter.career.base_salary = 25000;
            init_career(&g_family.daughter.career, 1, "Работник", 25000);
        }
    }
}


void daughter_education_progress() {
    if (!g_family.daughter.health.is_alive) return;
    if (!g_daughter_edu.enrolled) return;
    if (g_daughter_edu.years_remaining <= 0) return;
    if (g_current_stats.month == 6) {
        g_daughter_edu.years_remaining--;
        add_event("Курс обучения пройден", 0, "ОБРАЗОВАНИЕ");
        if (g_daughter_edu.years_remaining <= 0) {
            g_daughter_edu.enrolled = false;
            g_family.daughter.career.can_work = true;
            if (g_daughter_edu.education_level == 3) {
                g_family.daughter.career.base_salary = 150000;
                init_career(&g_family.daughter.career, 2, "Специалист", 150000);
                add_event("Окончание ВУЗа", 1, "ОБРАЗОВАНИЕ");
            }
            else if (g_daughter_edu.education_level == 2) {
                g_family.daughter.career.base_salary = 80000;
                init_career(&g_family.daughter.career, 1, "Техник", 80000);
                add_event("Окончание колледжа", 1, "ОБРАЗОВАНИЕ");
            }
        }
    }
}


void major_purchase_check() {
    if (g_family.made_major_purchase) return;
    if (g_family.shared_budget_pool < 2000000) return;
    g_family.shared_budget_pool -= 1500000;
    g_current_stats.total_expenses += 1500000;
    g_family.husband.health.mental += 20;
    g_family.wife.health.mental += 20;
    g_family.daughter.health.mental += 20;
    g_family.made_major_purchase = true;
    g_family.major_purchase_name = "Дача";
    add_event("Куплена дача", 1, "ПОКУПКИ");
}


void random_event(Person* p, const string& role) {
    if (!p->health.is_alive || p->health.in_clinic) return;
    int event = rand() % 1000;
    if (event < 2) {
        p->health.physical -= 50;
        RUB hospital = 100000;
        split_expense_proportional(hospital, &g_family.husband, &g_family.wife);
        g_current_stats.medical_expenses += hospital;
        add_event(p->name + " госпитализация", 5, "ЗДОРОВЬЕ");
    }
    else if (event < 5) {
        RUB loss = 50000;
        split_expense_proportional(loss, &g_family.husband, &g_family.wife);
        g_current_stats.unexpected_expenses += loss;
        add_event(p->name + " потеря денег", 4, "ФИНАНСЫ");
    }
    else if (event < 8) {
        p->health.physical -= 20;
        RUB medicine = 30000;
        split_expense_proportional(medicine, &g_family.husband, &g_family.wife);
        g_current_stats.medical_expenses += medicine;
        add_event(p->name + " болезнь", 4, "ЗДОРОВЬЕ");
    }
    else if (event < 10 && p->car.value > 0) {
        int accident = rand() % 100;
        if (accident < 30) {
            p->health.is_alive = false;
            g_state.deaths_count++;
            add_event(p->name + " ДТП (смерть)", 5, "ТРАГЕДИЯ");
        }
        else {
            p->health.physical -= 40;
            RUB repair = 200000;
            split_expense_proportional(repair, &g_family.husband, &g_family.wife);
            g_current_stats.unexpected_expenses += repair;
            add_event(p->name + " ДТП (травма)", 5, "ТРАГЕДИЯ");
        }
    }
    else if (event < 13) {
        RUB fine = 10000;
        split_expense_proportional(fine, &g_family.husband, &g_family.wife);
        g_current_stats.unexpected_expenses += fine;
        add_event(p->name + " штраф", 4, "ФИНАНСЫ");
    }
    else if (event < 20) {
        RUB bonus = p->career.base_salary / 4;
        process_income(p, bonus);
        g_current_stats.career_bonus += bonus;
        add_event(p->name + " премия", 1, "КАРЬЕРА");
    }
    else if (event < 28) {
        RUB inheritance = 200000;
        g_family.shared_budget_pool += inheritance;
        g_current_stats.total_income += inheritance;
        add_event(p->name + " наследство", 1, "ФИНАНСЫ");
    }
    else if (event < 32) {
        p->health.stress += 20;
        p->health.mental -= 15;
        add_event(p->name + " стресс", 4, "ЗДОРОВЬЕ");
    }
    else if (event < 40) {
        RUB lottery = 100000;
        g_family.shared_budget_pool += lottery;
        g_current_stats.total_income += lottery;
        add_event(p->name + " лотерея", 1, "ФИНАНСЫ");
    }
}


void major_life_event() {
    int event = rand() % 100;
    if (event < 2) {
        add_event("Экономический кризис", 5, "ГЛОБАЛЬНОЕ");
        g_config.inflation_rate = 25.0;
        g_family.husband.career.base_salary = (RUB)(g_family.husband.career.base_salary * 0.7);
        g_family.wife.career.base_salary = (RUB)(g_family.wife.career.base_salary * 0.7);
    }
    else if (event < 8) {
        add_event("Экономический бум", 1, "ГЛОБАЛЬНОЕ");
        g_family.husband.career.base_salary = (RUB)(g_family.husband.career.base_salary * 1.3);
        g_family.wife.career.base_salary = (RUB)(g_family.wife.career.base_salary * 1.3);
        g_config.bank_rate = 20.0;
    }
    else if (event < 10) {
        RUB damage = 500000;
        split_expense_proportional(damage, &g_family.husband, &g_family.wife);
        g_current_stats.unexpected_expenses += damage;
        add_event("Пожар в квартире", 5, "ТРАГЕДИЯ");
    }
    else if (event < 12) {
        RUB theft = 150000;
        split_expense_proportional(theft, &g_family.husband, &g_family.wife);
        g_current_stats.unexpected_expenses += theft;
        add_event("Кража в квартире", 5, "ТРАГЕДИЯ");
    }
}


void bank_interest() {
    PERCENT monthly_rate = g_config.bank_rate / 12.0 / 100.0;
    RUB interest = (RUB)(g_family.shared_budget_pool * monthly_rate);
    g_family.shared_budget_pool += interest;
    g_current_stats.bank_interest += interest;
    g_current_stats.total_income += interest;
    if (interest > 1000) {
        string event_msg = "Банковские проценты: " + to_string(interest);
        add_event(event_msg, 1, "ФИНАНСЫ");
    }
}


void check_bankruptcy() {
    RUB total_debt = g_family.husband.account.microloan_debt + g_family.wife.account.microloan_debt + g_family.daughter.account.microloan_debt;
    if (g_family.shared_budget_pool < 0 || total_debt > 500000) {
        if (g_family.shared_budget_pool >= -500000) {
            g_state.bankruptcy_months++;
            if (g_state.bankruptcy_months == 1) {
                add_event("Начало банкротства", 5, "ФИНАНСЫ");
            }
        }
    }
    else {
        g_state.bankruptcy_months = 0;
    }
}


void check_death(Person* p, const string& role) {
    if (!p->health.is_alive) return;
    if (p->health.physical <= 0) {
        p->health.is_alive = false;
        g_state.deaths_count++;
        add_event(p->name + " умер (здоровье)", 5, "ТРАГЕДИЯ");
    }
    if (g_family.shared_budget_pool < -500000) {
        p->health.is_alive = false;
        p->health.died_from_debt = true;
        g_state.deaths_count++;
        add_event(p->name + " умер (долги)", 5, "ТРАГЕДИЯ");
    }
}


void check_poverty_death() {
    if (g_family.shared_budget_pool <= -500000) {
        g_state.bankruptcy_months++;
        if (g_state.bankruptcy_months >= 2) {
            if (g_family.husband.health.is_alive) {
                g_family.husband.health.is_alive = false;
                g_family.husband.health.died_from_debt = true;
                g_state.deaths_count++;
            }
            if (g_family.wife.health.is_alive) {
                g_family.wife.health.is_alive = false;
                g_family.wife.health.died_from_debt = true;
                g_state.deaths_count++;
            }
            if (g_family.daughter.health.is_alive) {
                g_family.daughter.health.is_alive = false;
                g_family.daughter.health.died_from_debt = true;
                g_state.deaths_count++;
            }
            add_event("Смерть от нищеты", 5, "ТРАГЕДИЯ");
            g_state.simulation_ended = true;
        }
    }
    else {
        g_state.bankruptcy_months = 0;
    }
}


void check_orphanage() {
    if (!g_family.husband.health.is_alive && !g_family.wife.health.is_alive && g_family.daughter.health.is_alive && !g_state.daughter_in_orphanage) {
        g_state.daughter_in_orphanage = true;
        g_family.daughter.health.is_alive = false;
        g_state.deaths_count++;
        add_event("Дочь в детдоме", 5, "ТРАГЕДИЯ");
        g_state.simulation_ended = true;
    }
}


void update_investments(Person* p) {
    if (!p->health.is_alive) return;
    for (int i = 0; i < p->investment_count; i++) {
        if (!p->investments[i].active) continue;
        PERCENT change = 0;
        int rand_val = rand() % 100;
        if (p->investments[i].type == "Акции") {
            if (rand_val < 35) change = -0.05;
            else if (rand_val < 80) change = 0.04;
            else change = 0.12;
        }
        else if (p->investments[i].type == "Облигации") {
            change = 0.01;
        }
        else if (p->investments[i].type == "Криптовалюта") {
            if (rand_val < 25) change = -0.20;
            else if (rand_val < 75) change = 0.06;
            else change = 0.35;
        }
        else if (p->investments[i].type == "Недвижимость") {
            change = 0.005;
        }
        RUB old_value = p->investments[i].current_value;
        p->investments[i].current_value = (RUB)(p->investments[i].current_value * (1 + change));
        RUB diff = p->investments[i].current_value - old_value;
        if (diff > 0) {
            g_current_stats.investment_income += diff;
            string event_msg = "Инвестиции +" + to_string(diff);
            add_event(event_msg, 1, "ИНВЕСТ");
        }
        else if (diff < 0) {
            g_current_stats.investment_loss += (-diff);
            string event_msg = "Инвестиции -" + to_string(-diff);
            add_event(event_msg, 4, "ИНВЕСТ");
        }
    }
}


void career_level_up(Person* p) {
    if (!p->health.is_alive || p->health.in_clinic) return;
    if (!p->career.can_work) return;
    p->career.experience += 5;
    int promotion_chance = 100 - (p->career.skill_points * 2);
    if (promotion_chance < 20) promotion_chance = 20;
    if (rand() % 100 >= promotion_chance) return;
    if (p->career.experience >= 20 && p->career.level == 1) {
        p->career.level = 2;
        p->career.base_salary = (RUB)(p->career.base_salary * 1.3);
        p->career.position = "Специалист";
        add_event(p->name + " повышение", 1, "КАРЬЕРА");
    }
    else if (p->career.experience >= 50 && p->career.level == 2) {
        p->career.level = 3;
        p->career.base_salary = (RUB)(p->career.base_salary * 1.5);
        p->career.position = "Ведущий специалист";
        add_event(p->name + " повышение", 1, "КАРЬЕРА");
    }
    else if (p->career.experience >= 100 && p->career.level == 3) {
        p->career.level = 4;
        p->career.base_salary = (RUB)(p->career.base_salary * 1.8);
        p->career.position = "Руководитель";
        add_event(p->name + " повышение", 1, "КАРЬЕРА");
    }
    else if (p->career.experience >= 150 && p->career.level == 4) {
        p->career.level = 5;
        p->career.base_salary = (RUB)(p->career.base_salary * 2.0);
        p->career.position = "Директор";
        add_event(p->name + " повышение", 1, "КАРЬЕРА");
    }
}


void process_month_actions() {
    person_food(&g_family.husband);
    person_food(&g_family.wife);
    person_food(&g_family.daughter);
    person_clothing(&g_family.husband);
    person_clothing(&g_family.wife);
    person_clothing(&g_family.daughter);
    person_entertainment(&g_family.husband);
    person_entertainment(&g_family.wife);
    person_entertainment(&g_family.daughter);
    person_household(&g_family.husband);
    person_household(&g_family.wife);
    person_household(&g_family.daughter);
    person_transport(&g_family.husband);
    person_transport(&g_family.wife);
    person_transport(&g_family.daughter);
    person_car(&g_family.husband);
    person_car(&g_family.wife);
    person_utilities();
    person_salary(&g_family.husband, g_current_stats.month, g_current_stats.year);
    person_salary(&g_family.wife, g_current_stats.month, g_current_stats.year);
    person_salary(&g_family.daughter, g_current_stats.month, g_current_stats.year);
    daughter_shopping();
    daughter_stealing_check();
    person_mental_health(&g_family.husband);
    person_mental_health(&g_family.wife);
    daughter_mental_health();
    person_health_update();
    if (g_family.husband.health.mental < 30) person_therapist(&g_family.husband);
    if (g_family.wife.health.mental < 30) person_therapist(&g_family.wife);
    if (g_family.daughter.health.mental < 30) person_therapist(&g_family.daughter);
    person_rest(&g_family.husband);
    person_rest(&g_family.wife);
    person_rest(&g_family.daughter);
    person_clinic_check(&g_family.husband);
    person_clinic_check(&g_family.wife);
    person_clinic_check(&g_family.daughter);
    career_level_up(&g_family.husband);
    career_level_up(&g_family.wife);
    daughter_exams();
    daughter_education_choice();
    daughter_education_progress();
    check_new_pet();
    minor_events_apply();
    random_event(&g_family.husband, "Отец");
    random_event(&g_family.wife, "Мать");
    random_event(&g_family.daughter, "Дочь");
    major_life_event();
    major_purchase_check();
    check_bankruptcy();
    check_death(&g_family.husband, "Отец");
    check_death(&g_family.wife, "Мать");
    check_death(&g_family.daughter, "Дочь");
    check_poverty_death();
    check_orphanage();
    pet_care();
    pet_cat_care();
    bank_interest();
    check_microloan_need();
    pay_microloan(&g_family.husband);
    pay_microloan(&g_family.wife);
    update_investments(&g_family.husband);
    update_investments(&g_family.wife);
    check_auto_sanatorium();
    check_auto_vacation();
    check_auto_courses();
}


void run_simulation() {
    while (!g_state.simulation_ended) {
        init_stats();
        g_current_stats.month = g_state.total_months + 1;
        g_current_stats.year = g_config.start_year + (g_config.start_month + g_state.total_months) / 12;
        add_event("Начало месяца " + to_string(g_current_stats.month), 0, "СИСТЕМА");
        update_prices();
        update_market();
        process_month_actions();
        g_state.total_months++;
        g_state.total_income += g_current_stats.total_income;
        g_state.total_expenses += g_current_stats.total_expenses;
        print_month_summary_header();
        print_month_income_section();
        print_month_expenses_section();
        print_month_final_balance();
        print_month_events();
        if (g_state.total_months >= (g_config.end_year - g_config.start_year) * 12 + (g_config.end_month - g_config.start_month)) {
            g_state.simulation_ended = true;
        }
        if (!g_family.husband.health.is_alive && !g_family.wife.health.is_alive && !g_family.daughter.health.is_alive) {
            g_state.simulation_ended = true;
        }
    }
}


void save_to_file() {
    ofstream outfile;
    outfile.open("report.txt");
    if (outfile.is_open()) {
        outfile << "=== ОТЧЕТ СИМУЛЯЦИИ ===" << endl;
        outfile << "Остаток бюджета: " << g_family.shared_budget_pool << " руб." << endl;
        outfile << "Всего микрозаймов: " << g_family.total_microloans_taken << endl;
        outfile << "Выплачено по микрозаймам: " << g_family.total_microloan_debt_paid << " руб." << endl;
        outfile << "Отец: " << (g_family.husband.health.is_alive ? "Жив" : "Мертв") << endl;
        outfile << "Мать: " << (g_family.wife.health.is_alive ? "Жива" : "Мертва") << endl;
        outfile << "Дочь: " << (g_family.daughter.health.is_alive ? "Жива" : "Мертва") << endl;
        outfile << "Образование: " << g_daughter_edu.status << endl;
        outfile << "ВУЗ: " << g_daughter_edu.institution_name << endl;
        outfile << "ЕГЭ: " << g_daughter_edu.exam_score << "/100" << endl;
        outfile << "Месяцев: " << g_state.total_months << endl;
        outfile << "Доход: " << g_state.total_income << " руб." << endl;
        outfile << "Расход: " << g_state.total_expenses << " руб." << endl;
        outfile << "Поведение дочери: " << g_family.daughter_good_behavior_points << " очков" << endl;
        outfile << "Собака: " << (g_family.dog.is_alive ? "Жива" : "Мертва") << endl;
        if (g_family.cat.is_alive) {
            outfile << "Кошка: Жива" << (g_family.cat.is_stray ? " (Бродяга)" : "") << endl;
        }
        if (g_family.made_major_purchase) {
            outfile << "Покупка: " << g_family.major_purchase_name << endl;
        }
        outfile << endl << "=== ЖУРНАЛ СОБЫТИЙ ===" << endl;
        for (int i = 0; i < g_state.event_count; i++) {
            outfile << i + 1 << ". " << g_state.event_log[i].description << endl;
        }
        outfile.close();
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned int)time(NULL));
    init_config();
    init_market();
    init_prices();
    init_family();
    init_state();
    print_header("СИМУЛЯТОР СЕМЬИ v2.0");
    run_simulation();
    print_final_report_header();
    print_final_family_status();
    print_final_financial_status();
    print_final_achievements();
    print_event_log_full();
    save_to_file();
    cout << endl << "Нажмите Enter для выхода...";
    cin.get();
    return 0;
}