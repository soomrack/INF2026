#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <sstream>

using RUB = long long int;
using USD = long long int;
using EUR = long long int;
using procent = const float;

// ============================================================
//  Глобальный счётчик прожитых лет (для расчёта инфляции)
// ============================================================

static int global_years_lived = 0;
static constexpr float annual_inflation_rate = 0.07f;

float inflation_factor()
{
    return std::pow(1.0f + annual_inflation_rate, static_cast<float>(global_years_lived));
}

RUB inflate(RUB base_price)
{
    return static_cast<RUB>(base_price * inflation_factor());
}

float inflate_f(float base_price)
{
    return base_price * inflation_factor();
}

// Множитель расходов семьи: 1.0=одна, 1.5=замужем/бабушка, 2.0=с ребёнком
static float global_expense_multiplier = 1.0f;

// ============================================================
//  Налоговые ставки и сборы
// ============================================================

struct taxes_state
{
    procent income_tax = 13.0f;
    procent income_tax_high = 15.0f;
    procent investment_tax = 13.0f;
    procent deposit_tax = 13.0f;
    procent transport_tax_rate = 15.0f;
    procent property_tax = 0.1f;
    procent pension_fund = 22.0f;
    procent social_insurance = 2.9f;
    procent medical_insurance = 5.1f;
    procent vat = 22.0f;
    procent vat_food = 10.0f;

    RUB   calc_income_tax(RUB gross, RUB annual_income_so_far = 0) const;
    RUB   calc_transport_tax(int horsepower)      const;
    RUB   calc_deposit_tax(RUB interest_earned) const;
    RUB   calc_investment_tax(RUB profit)          const;
    RUB   calc_property_tax(RUB cadastral_value) const;
    float total_employer_burden() const;
};

RUB taxes_state::calc_income_tax(RUB gross, RUB annual_income_so_far) const
{
    const RUB threshold = 5'000'000;
    RUB total = annual_income_so_far + gross;
    
    if (total <= threshold)
        return static_cast<RUB>(gross * (income_tax / 100.0f));
    
    if (annual_income_so_far >= threshold)
        return static_cast<RUB>(gross * (income_tax_high / 100.0f));
    
    RUB below = threshold - annual_income_so_far;
    RUB above = gross - below;
    return static_cast<RUB>(below * (income_tax / 100.0f))
        + static_cast<RUB>(above * (income_tax_high / 100.0f));
}

RUB taxes_state::calc_transport_tax(int horsepower) const
{
    return static_cast<RUB>(horsepower * transport_tax_rate);
}

RUB taxes_state::calc_deposit_tax(RUB interest_earned) const
{
    return static_cast<RUB>(interest_earned * (deposit_tax / 100.0f));
}

RUB taxes_state::calc_investment_tax(RUB profit) const
{
    return profit > 0 ? static_cast<RUB>(profit * (investment_tax / 100.0f)) : 0;
}

RUB taxes_state::calc_property_tax(RUB cadastral_value) const
{
    return static_cast<RUB>(cadastral_value * (property_tax / 100.0f));
}

float taxes_state::total_employer_burden() const
{
    return pension_fund + social_insurance + medical_insurance;
}

struct taxes_state taxes_state;

// ============================================================
//  class Bank — банк Алисы
// ============================================================

class Bank
{
private:
    float BASE_DOLLAR_RATE = 90.91f;
    float BASE_EURO_RATE = 100.00f;
    float deposit_rate_short = 0.14f;
    float deposit_rate_long = 0.18f;
    static constexpr RUB   MIN_DEPOSIT_SUM = 30'000;

    struct transaction { std::string type; RUB amount_rub; std::string note; };

    struct deposit
    {
        std::string name;
        RUB   principal;
        RUB   accrued = 0;
        float rate;
        int   total_months;
        int   months_done = 0;
        bool  active = true;

        RUB  monthly_gain()    const;
        RUB  tax_on_interest() const;
        RUB  payout()          const;
        void accrue_month();
    };

    std::vector<transaction> tx_history;
    std::vector<deposit>     deposits;
    int next_deposit_id = 1;

    void     log(const std::string& type, RUB amount, const std::string& note);
    void     require_rub(RUB needed) const;
    deposit& find_deposit(int id);

public:
    RUB account_rub = 0;
    USD account_usd = 0;
    EUR account_eur = 0;

    RUB total_deposit_interest_earned = 0;
    RUB total_deposit_tax_paid = 0;
    int total_deposits_opened = 0;
    int total_deposits_closed = 0;

    float dollar_rate() const;
    float euro_rate()   const;

    void rub_to_usd(RUB amount);
    void rub_to_eur(RUB amount);
    void usd_to_rub(USD amount);
    void eur_to_rub(EUR amount);

    void receive_salary(RUB gross, int unpaid_days,
        const std::string& employer = "Работодатель");

    int  open_deposit_short(const std::string& dep_name, RUB amount);
    int  open_deposit_long(const std::string& dep_name, RUB amount);
    void close_deposit(int id);
    void accrue_month_deposits();
    void try_auto_deposit();

    RUB  total_assets_rub() const;

    void print_account_summary() const;
    void print_deposits()        const;
    void print_deposit_summary() const;
    void print_history(int last_n = 10) const;
};

RUB Bank::deposit::monthly_gain() const
{
    return static_cast<RUB>(principal * (rate / 12.0f));
}

RUB Bank::deposit::tax_on_interest() const
{
    return static_cast<RUB>(accrued * 0.035f);
}

RUB Bank::deposit::payout() const
{
    return principal + accrued - tax_on_interest();
}

void Bank::deposit::accrue_month()
{
    if (!active) return;
    accrued += monthly_gain();
    ++months_done;
}

void Bank::log(const std::string& type, RUB amount, const std::string& note)
{
    tx_history.push_back({ type, amount, note });
}

void Bank::require_rub(RUB needed) const
{
    if (account_rub < needed)
        throw std::runtime_error("Недостаточно RUB: нужно " +
            std::to_string(needed) + ", есть " + std::to_string(account_rub));
}

Bank::deposit& Bank::find_deposit(int id)
{
    if (id < 1 || id > static_cast<int>(deposits.size()))
        throw std::runtime_error("Вклад не найден: " + std::to_string(id));
    return deposits[id - 1];
}

float Bank::dollar_rate() const
{
    return BASE_DOLLAR_RATE;
}

float Bank::euro_rate() const
{
    return BASE_EURO_RATE;
}

void Bank::rub_to_usd(RUB amount)
{
    require_rub(amount);
    account_rub -= amount;
    account_usd += static_cast<USD>(amount / dollar_rate());
    log("Обмен RUB->USD", amount, "курс=" + std::to_string(static_cast<int>(dollar_rate())));
}

void Bank::rub_to_eur(RUB amount)
{
    require_rub(amount);
    account_rub -= amount;
    account_eur += static_cast<EUR>(amount / euro_rate());
    log("Обмен RUB->EUR", amount, "курс=" + std::to_string(static_cast<int>(euro_rate())));
}

void Bank::usd_to_rub(USD amount)
{
    if (account_usd < amount) throw std::runtime_error("Недостаточно USD");
    account_usd -= amount;
    account_rub += static_cast<RUB>(amount * dollar_rate());
    log("Обмен USD->RUB", static_cast<RUB>(amount * dollar_rate()), "");
}

void Bank::eur_to_rub(EUR amount)
{
    if (account_eur < amount) throw std::runtime_error("Недостаточно EUR");
    account_eur -= amount;
    account_rub += static_cast<RUB>(amount * euro_rate());
    log("Обмен EUR->RUB", static_cast<RUB>(amount * euro_rate()), "");
}

void Bank::receive_salary(RUB gross, int unpaid_days, const std::string& employer)
{
    RUB daily_rate = gross / 22;
    RUB lost_pay = daily_rate * std::min(unpaid_days, 22);
    RUB reduced_gross = std::max(0LL, gross - lost_pay);
    RUB tax = taxes_state.calc_income_tax(reduced_gross);
    RUB net = reduced_gross - tax;
    account_rub += net;
    log("Зарплата (нетто)", net, "от " + employer);
    log("НДФЛ удержан", tax, std::to_string(taxes_state.income_tax) + "%");
    if (unpaid_days > 0)
        log("Потеря (болезнь)", lost_pay,
            "не оплачено " + std::to_string(unpaid_days) + " дн.");
}

int Bank::open_deposit_short(const std::string& dep_name, RUB amount)
{
    require_rub(amount);
    account_rub -= amount;
    deposits.push_back({ dep_name, amount, 0, deposit_rate_short, 3 });
    log("Вклад открыт (3 мес.)", amount, dep_name + " 14% год.");
    ++total_deposits_opened;
    return next_deposit_id++;
}

int Bank::open_deposit_long(const std::string& dep_name, RUB amount)
{
    require_rub(amount);
    account_rub -= amount;
    deposits.push_back({ dep_name, amount, 0, deposit_rate_long, 36 });
    log("Вклад открыт (36 мес.)", amount, dep_name + " 18% год.");
    ++total_deposits_opened;
    return next_deposit_id++;
}

void Bank::close_deposit(int id)
{
    deposit& dep = find_deposit(id);
    if (!dep.active) return;
    RUB interest = dep.accrued;
    RUB tax = dep.tax_on_interest();
    RUB payout = dep.payout();
    account_rub += payout;
    dep.active = false;
    total_deposit_interest_earned += interest;
    total_deposit_tax_paid += tax;
    ++total_deposits_closed;
    log("Вклад закрыт", payout, dep.name + " (%" + std::to_string(interest) + " руб.)");
    if (tax > 0)
        log("Налог с вклада", tax, "удержан автоматически");
}

void Bank::accrue_month_deposits()
{
    for (int i = 0; i < static_cast<int>(deposits.size()); ++i)
    {
        deposit& dep = deposits[i];
        if (!dep.active) continue;
        dep.accrue_month();
        if (dep.months_done >= dep.total_months)
            close_deposit(i + 1);
    }
}

void Bank::try_auto_deposit()
{
    bool has_long_active = false;
    for (const auto& dep : deposits)
        if (dep.active && dep.total_months == 36) { has_long_active = true; break; }

    const RUB cushion = 50'000;

    if (!has_long_active && account_rub >= 200'000 + cushion)
    {
        RUB to_deposit = account_rub - cushion;
        if (to_deposit >= MIN_DEPOSIT_SUM)
        {
            open_deposit_long("Долгосрочный вклад", to_deposit);
            return;
        }
    }

    bool has_short_active = false;
    for (const auto& dep : deposits)
        if (dep.active && dep.total_months == 3) { has_short_active = true; break; }

    if (!has_short_active && account_rub >= MIN_DEPOSIT_SUM * 2 + cushion)
    {
        RUB to_deposit = account_rub / 2;
        if (to_deposit >= MIN_DEPOSIT_SUM)
            open_deposit_short("Краткосрочный вклад", to_deposit);
    }
}

RUB Bank::total_assets_rub() const
{
    RUB total = account_rub
        + static_cast<RUB>(account_usd * dollar_rate())
        + static_cast<RUB>(account_eur * euro_rate());
    for (const auto& dep : deposits)
        if (dep.active) total += dep.payout();
    return total;
}

void Bank::print_account_summary() const
{
    std::cout << "  Количество рублей: " << account_rub << " руб.\n";
    if (account_usd > 0)
        std::cout << "  Количество долларов: " << account_usd
        << " (≈" << static_cast<RUB>(account_usd * dollar_rate()) << " руб.)\n";
    if (account_eur > 0)
        std::cout << "  Количество евро: " << account_eur
        << " (≈" << static_cast<RUB>(account_eur * euro_rate()) << " руб.)\n";
    std::cout << "  Сумма всех денег Алисы в рублях: " << total_assets_rub() << " руб.\n";
}

void Bank::print_deposits() const
{
    std::cout << "\n=== Вклады ===\n";
    if (deposits.empty()) { std::cout << "  Нет вкладов\n"; return; }
    for (int i = 0; i < static_cast<int>(deposits.size()); ++i)
    {
        const auto& dep = deposits[i];
        std::cout << "  [" << (i + 1) << "] " << dep.name
            << " | тело=" << dep.principal << " руб."
            << " | начислено=" << dep.accrued << " руб."
            << " | " << dep.months_done << "/" << dep.total_months << " мес."
            << " | " << (dep.active ? "активен" : "закрыт")
            << " | к выплате=" << dep.payout() << " руб.\n";
    }
}

void Bank::print_deposit_summary() const
{
    std::cout << "  Вкладов открыто:         " << total_deposits_opened << " шт.\n"
        << "  Вкладов закрыто:         " << total_deposits_closed << " шт.\n"
        << "  Заработано процентов:    " << total_deposit_interest_earned << " руб.\n"
        << "  Налог с процентов:       " << total_deposit_tax_paid << " руб.\n"
        << "  Чистый доход от вкладов: "
        << (total_deposit_interest_earned - total_deposit_tax_paid) << " руб.\n";
}

void Bank::print_history(int last_n) const
{
    std::cout << "=== Последние " << last_n << " операций ===\n";
    int start = std::max(0, static_cast<int>(tx_history.size()) - last_n);
    for (int i = start; i < static_cast<int>(tx_history.size()); ++i)
        std::cout << "  " << tx_history[i].type
        << " | " << tx_history[i].amount_rub << " RUB"
        << " | " << tx_history[i].note << "\n";
}

// ============================================================
//  Система болезней
// ============================================================

enum class illness_severity { none, mild, moderate, severe };

struct illness_type
{
    std::string      name;
    illness_severity severity;
    int   min_days;
    int   max_days;
    RUB   doctor_cost;
    RUB   medicine_min;
    RUB   medicine_max;
    float chance_per_month;
    float food_multiplier;
};

const std::vector<illness_type>& illness_catalog()
{
    static const std::vector<illness_type> v{
        { "Насморк / лёгкое ОРВИ",     illness_severity::mild,       3,  5,        0,    200,    700,   35.0f, 0.70f },
        { "Грипп",                     illness_severity::moderate,   5,  8,      500,  1'500,  3'500,   15.0f, 0.50f },
        { "Ангина",                    illness_severity::moderate,   5,  7,    1'000,  2'000,  4'000,   10.0f, 0.45f },
        { "Отравление",                illness_severity::moderate,   3,  6,      800,    500,  1'500,   12.0f, 0.35f },
        { "Бронхит",                   illness_severity::moderate,   7,  8,    1'500,  2'500,  5'000,    8.0f, 0.50f },
        { "Пневмония",                 illness_severity::severe,     7,  8,    5'000,  8'000, 20'000,    3.0f, 0.30f },
        { "Аллергия",                  illness_severity::mild,       3,  7,      400,    800,  2'000,   10.0f, 0.80f },
        { "Конъюнктивит",              illness_severity::mild,       4,  6,      300,    600,  1'200,    8.0f, 0.90f },
        { "Остеохондроз (обострение)", illness_severity::moderate,   5, 10,    2'000,  3'000,  7'000,    6.0f, 0.60f },
        { "Гастрит (обострение)",      illness_severity::moderate,   4,  7,    1'200,  2'500,  5'500,    7.0f, 0.40f },
        { "Мигрень",                   illness_severity::mild,       1,  3,      500,    300,    900,   12.0f, 0.75f },
        { "Варикоз (обострение)",      illness_severity::mild,       3,  5,    1'500,  1'000,  3'000,    5.0f, 0.85f },
    };
    return v;
}

struct illness_result
{
    bool             sick = false;
    std::string      name;
    illness_severity severity = illness_severity::none;
    int              days = 0;
    RUB              doctor_cost = 0;
    RUB              medicine_cost = 0;
    float            food_multiplier = 1.0f;
    RUB              lost_salary = 0;
    RUB              vacation_savings = 0;
};

illness_result generate_illness(std::mt19937& gen)
{
    illness_result result;
    const auto& catalog = illness_catalog();

    float total_chance = 0.0f;
    for (const auto& ill : catalog) total_chance += ill.chance_per_month;

    std::uniform_real_distribution<float> roll(0.0f, 100.0f);
    if (roll(gen) > std::min(total_chance, 55.0f))
        return result;

    std::vector<int> weights;
    for (const auto& ill : catalog)
        weights.push_back(static_cast<int>(ill.chance_per_month * 100));
    std::discrete_distribution<> dist(weights.begin(), weights.end());
    const illness_type& chosen = catalog[dist(gen)];

    result.sick = true;
    result.name = chosen.name;
    result.severity = chosen.severity;
    result.food_multiplier = chosen.food_multiplier;

    std::uniform_int_distribution<> days_dist(chosen.min_days, chosen.max_days);
    result.days = days_dist(gen);

    bool visits_doctor = (chosen.severity != illness_severity::mild) || (roll(gen) < 60.0f);
    float med_inflation = std::pow(1.10f, static_cast<float>(global_years_lived));
    result.doctor_cost = visits_doctor
        ? static_cast<RUB>(chosen.doctor_cost * med_inflation) : 0;

    std::uniform_int_distribution<> med_dist(
        static_cast<int>(chosen.medicine_min * med_inflation),
        static_cast<int>(chosen.medicine_max * med_inflation));
    result.medicine_cost = static_cast<RUB>(med_dist(gen));

    return result;
}

// ============================================================
//  Система случайных событий с машиной
// ============================================================

struct car_event
{
    std::string name;
    float       chance;
    RUB         repair_min;
    RUB         repair_max;
    bool        needs_tow;
};

const std::vector<car_event>& car_event_catalog()
{
    static const std::vector<car_event> v{
        { "Прокол колеса",                25.0f,     500,    2'500, false },
        { "Разряженный аккумулятор",      15.0f,   2'000,    8'000, false },
        { "Замена тормозных колодок",     10.0f,   3'000,    8'000, false },
        { "Поломка стартера",              5.0f,   5'000,   15'000,  true },
        { "ДТП (незначительное)",          8.0f,  10'000,   50'000,  true },
        { "Кража зеркала/фары",            6.0f,   3'000,   10'000, false },
        { "Скол лобового стекла",          9.0f,   1'500,    8'000, false },
        { "Поломка АКПП/сцепления",        3.0f,  20'000,   80'000,  true },
        { "Утечка масла/антифриза",        7.0f,   2'000,   12'000, false },
        { "Штраф от ГИБДД",               20.0f,     500,    5'000, false },
        { "Царапина на парковке",          12.0f,   2'000,   15'000, false },
        { "Замена амортизаторов",           6.0f,   8'000,   25'000, false },
        { "Неисправность датчика",          8.0f,   1'500,    6'000, false },
        { "Замена катализатора",            3.0f,  15'000,   40'000, false },
        { "Угон авто (частичный ущерб)",    1.0f,  30'000,  100'000,  true },
        { "Замена ремня ГРМ (внеплановая)", 4.0f,   7'000,   20'000,  true },
    };
    return v;
}

struct car_event_result
{
    bool        happened = false;
    std::string name;
    RUB         repair_cost = 0;
    RUB         tow_cost = 0;
    RUB         total_cost = 0;
};

car_event_result generate_car_event(std::mt19937& gen)
{
    car_event_result result;
    const auto& catalog = car_event_catalog();

    std::uniform_real_distribution<float> roll(0.0f, 100.0f);
    if (roll(gen) > 40.0f) return result;

    std::vector<int> weights;
    for (const auto& ev : catalog)
        weights.push_back(static_cast<int>(ev.chance * 100));
    std::discrete_distribution<> dist(weights.begin(), weights.end());
    const car_event& chosen = catalog[dist(gen)];

    result.happened = true;
    result.name = chosen.name;

    float car_inflation = std::pow(1.08f, static_cast<float>(global_years_lived));
    std::uniform_int_distribution<> cost_dist(
        static_cast<int>(chosen.repair_min * car_inflation),
        static_cast<int>(chosen.repair_max * car_inflation));
    result.repair_cost = static_cast<RUB>(cost_dist(gen));

    if (chosen.needs_tow)
    {
        std::uniform_int_distribution<> tow_dist(
            static_cast<int>(3'000 * car_inflation),
            static_cast<int>(7'000 * car_inflation));
        result.tow_cost = static_cast<RUB>(tow_dist(gen));
    }

    result.total_cost = result.repair_cost + result.tow_cost;
    return result;
}

// ============================================================
//  Расходы на бензин
// ============================================================

struct fuel_params
{
    float km_per_day;
    float liters_per_100km;
    float fuel_price_per_liter;
    int   work_days_per_month;
};

RUB calc_monthly_fuel_cost(const fuel_params& fp, int sick_days = 0)
{
    int   active_days = std::max(0, fp.work_days_per_month - sick_days);
    float liters = (fp.km_per_day / 100.0f) * fp.liters_per_100km * active_days;
    liters *= 1.15f;
    float fuel_inflation = std::pow(1.06f, static_cast<float>(global_years_lived));
    return static_cast<RUB>(liters * fp.fuel_price_per_liter * fuel_inflation);
}

// ============================================================
//  Алиса и её имущество
// ============================================================

struct Car
{
    RUB   car_cost;
    RUB   car_cost_initial;
    float fuel_cost_monthly;
    int   horsepower = 150;
    float liters_per_100km = 9.5f;
    float km_per_day = 40.0f;
    float fuel_price = 58.0f;
    int   age_years = 0;

    void depreciate()
    {
        float rate = (age_years < 3) ? 0.15f
            : (age_years < 7) ? 0.10f
            : 0.05f;
        car_cost = static_cast<RUB>(car_cost * (1.0f - rate));
        ++age_years;
    }
};

struct Apartment
{
    std::string name;
    RUB         price;
    RUB         cadastral_value;
    int         area_sqm;
};

const std::vector<Apartment>& apartment_catalog()
{
    static const std::vector<Apartment> v{
        { "Студия в спальном районе",           1'800'000,   1'200'000,  28 },
        { "Однушка на окраине",                 3'200'000,   2'400'000,  38 },
        { "Двушка в хорошем районе",            6'500'000,   5'000'000,  58 },
        { "Трёшка в центре",                   12'000'000,  10'000'000,  85 },
        { "Просторная квартира бизнес-класса", 22'000'000,  18'000'000, 120 },
    };
    return v;
}

RUB apartment_current_price(int catalog_index)
{
    float re_inflation = std::pow(1.09f, static_cast<float>(global_years_lived));
    return static_cast<RUB>(apartment_catalog()[catalog_index].price * re_inflation);
}

struct Alice
{
    short age;
    std::unordered_map<std::string, double> fridge;

    RUB   salary = 0;
    Car   car;
    Bank  sber;

    RUB   invest_portfolio = 0;
    RUB   invest_cost_basis = 0;
    RUB   total_invest_profit = 0;
    RUB   total_invest_loss = 0;

    int total_sick_days = 0;
    RUB total_medical_cost = 0;
    RUB total_lost_salary = 0;

    RUB total_fuel_cost = 0;
    RUB total_transport_tax = 0;
    RUB total_car_repair_cost = 0;
    int total_car_incidents = 0;

    int apartment_level = -1;
    RUB total_property_tax = 0;

    bool is_married = false;
    bool has_first_child = false;
    bool is_grandmother = false;
    bool is_retired = false;
    bool passport_renewed = false;
    bool darwin_prize = false;  // Алиса получила премию Дарвина

    float career_multiplier = 1.0f;
};

struct Alice Alice;

// ============================================================
//  Возрастные события
// ============================================================

enum class age_event_type
{
    marriage, first_child, passport_renewal, became_grandmother, retirement,
};

struct age_event
{
    short          trigger_age;
    age_event_type type;
    std::string    description;
    RUB            cost;
    RUB            income_change;
};

const std::vector<age_event>& age_event_catalog()
{
    static const std::vector<age_event> v{
        { 30, age_event_type::marriage,
          "Алиса вышла замуж! Свадебный банкет, кольца, платье...", 350'000, 15'000 },
        { 32, age_event_type::first_child,
          "Алиса родила первого ребёнка! Роддом, приданое, коляска, кроватка...", 120'000, -8'000 },
        { 45, age_event_type::passport_renewal,
          "Замена паспорта в 45 лет. Госпошлина, фото, МФЦ...", 1'500, 0 },
        { 64, age_event_type::became_grandmother,
          "Алиса стала бабушкой! Подарки, радость...", 25'000, 0 },
        { 65, age_event_type::retirement,
          "Алиса вышла на пенсию! Прощальный корпоратив, торт, цветы от коллег.", 15'000, -30'000 },
    };
    return v;
}

void apply_age_event(const age_event& ev)
{
    RUB inflated_cost = inflate(ev.cost);

    std::cout << "\n╔══════════════════════════════════════════════════╗\n"
                << "║  ЖИЗНЕННОЕ СОБЫТИЕ [возраст " << ev.trigger_age << " лет]              ║\n"
                << "╚══════════════════════════════════════════════════╝\n"
                << "  " << ev.description << "\n";

    switch (ev.type)
    {
    case age_event_type::marriage:
        if (!Alice.is_married)
        {
            Alice.is_married = true;
            global_expense_multiplier = 1.5f;
            RUB actual_cost = std::min(inflated_cost, std::max(0LL, Alice.sber.account_rub));
            Alice.sber.account_rub -= actual_cost;
            Alice.salary += ev.income_change;
            std::cout << "  Расходы на свадьбу:         " << actual_cost << " руб.\n"
                << "  Прибавка от мужа:          +" << ev.income_change << " руб./мес.\n"
                << "  Расходы вырастают в:        x" << global_expense_multiplier << "\n";
        }
        break;

    case age_event_type::first_child:
        if (!Alice.has_first_child)
        {
            Alice.has_first_child = true;
            global_expense_multiplier = 2.0f;
            RUB actual_cost = std::min(inflated_cost, std::max(0LL, Alice.sber.account_rub));
            Alice.sber.account_rub -= actual_cost;
            Alice.salary = std::max(0LL, Alice.salary + ev.income_change);
            std::cout << "  Расходы на рождение:        " << actual_cost << " руб.\n"
                << "  Декрет (изменение дохода): " << ev.income_change << " руб./мес.\n"
                << "  Расходы вырастают в:        x" << global_expense_multiplier << "\n";
        }
        break;

    case age_event_type::passport_renewal:
        if (!Alice.passport_renewed)
        {
            Alice.passport_renewed = true;
            RUB actual_cost = std::min(inflated_cost, std::max(0LL, Alice.sber.account_rub));
            Alice.sber.account_rub -= actual_cost;
            std::cout << "  Расходы: " << actual_cost << " руб. (госпошлина + фото)\n";
        }
        break;

    case age_event_type::became_grandmother:
        if (!Alice.is_grandmother)
        {
            Alice.is_grandmother = true;
            global_expense_multiplier = 1.5f;
            RUB actual_cost = std::min(inflated_cost, std::max(0LL, Alice.sber.account_rub));
            Alice.sber.account_rub -= actual_cost;
            std::cout << "  Подарки внуку/внучке:       " << actual_cost << " руб.\n"
                << "  Расходы снизились до:       x" << global_expense_multiplier << "\n";
        }
        break;

    case age_event_type::retirement:
        if (!Alice.is_retired)
        {
            Alice.is_retired = true;
            RUB actual_cost = std::min(inflated_cost, std::max(0LL, Alice.sber.account_rub));
            Alice.sber.account_rub -= actual_cost;
            Alice.salary = std::max(0LL, Alice.salary + ev.income_change);
            std::cout << "  Корпоратив:                 " << actual_cost << " руб.\n"
                << "  Новый доход (пенсия):       " << Alice.salary << " руб./мес.\n";
        }
        break;
    }

    std::cout << "  Баланс после события: " << Alice.sber.account_rub << " руб.\n\n";
}

void check_age_events(short age)
{
    for (const auto& ev : age_event_catalog())
    {
        if (ev.trigger_age != age) continue;
        bool already_done = false;
        switch (ev.type)
        {
        case age_event_type::marriage:          already_done = Alice.is_married;      break;
        case age_event_type::first_child:       already_done = Alice.has_first_child; break;
        case age_event_type::passport_renewal:  already_done = Alice.passport_renewed; break;
        case age_event_type::became_grandmother:already_done = Alice.is_grandmother;  break;
        case age_event_type::retirement:        already_done = Alice.is_retired;      break;
        }
        if (!already_done) apply_age_event(ev);
    }
}

// ============================================================
//  Карьерный рост Алисы
// ============================================================

void apply_annual_salary_growth(std::mt19937& gen)
{
    if (Alice.is_retired) return;

    int years_worked = Alice.age - 24;
    if (years_worked <= 0) return;

    float experience_growth = (years_worked < 10) ? 0.05f : 0.02f;
    float inflation_compensation = annual_inflation_rate * 0.80f;
    float total_growth = experience_growth + inflation_compensation;

    std::uniform_int_distribution<> bonus_roll(1, 100);
    int roll = bonus_roll(gen);
    if (roll <= 20) total_growth += 0.10f;
    else if (roll <= 35) total_growth -= 0.03f;
    else if (roll <= 40) total_growth += 0.20f;
    else if (roll == 1)  total_growth += 0.50f;

    if (total_growth < 0.0f) total_growth = 0.0f;

    Alice.salary = static_cast<RUB>(Alice.salary * (1.0f + total_growth));
    Alice.career_multiplier *= (1.0f + total_growth);
}

// ============================================================
//  Система отпуска
// ============================================================

enum class vacation_currency_zone { EUR, USD, RUB };
enum class vacation_style { backpacker, budget, comfort, luxury, elite };

struct vacation_profile
{
    vacation_style style;
    std::string    style_name;
    int   vacation_days;
    float hotel_multiplier;
    float food_multiplier;
    float other_multiplier;
    float flight_multiplier;
    RUB   extras_rub;
    float budget_share;
    RUB   daily_entertainment;
};

vacation_profile get_vacation_style(RUB monthly_salary)
{
    if (monthly_salary < 30'000)
        return { vacation_style::backpacker, "Backpacker",  7, 0.4f, 0.5f, 0.4f, 1.0f,   3'000, 0.08f,   500 };
    if (monthly_salary < 60'000)
        return { vacation_style::budget,     "Budget",     10, 0.7f, 0.8f, 0.7f, 1.0f,   8'000, 0.12f, 1'000 };
    if (monthly_salary < 120'000)
        return { vacation_style::comfort,    "Comfort",    14, 1.0f, 1.2f, 1.3f, 1.0f,  20'000, 0.18f, 2'500 };
    if (monthly_salary < 250'000)
        return { vacation_style::luxury,     "Luxury",     21, 2.5f, 2.0f, 2.5f, 3.0f,  80'000, 0.25f, 6'000 };
    return   { vacation_style::elite,       "Elite",      30, 5.0f, 4.0f, 5.0f, 6.0f, 250'000, 0.35f,15'000 };
}

struct vacation_destination
{
    std::string name;
    float tourist_markup;
    RUB avg_daily_hotel_rub;
    RUB avg_daily_food_rub;
    RUB avg_daily_other_rub;
};

struct vacation_pool
{
    static const std::vector<vacation_destination>& eur_destinations()
    {
        static const std::vector<vacation_destination> v{
            {"Испания (Барселона)",   1.40f, 7'000, 2'500, 2'000},
            {"Италия (Рим)",          1.50f, 8'000, 3'000, 2'500},
            {"Германия (Берлин)",     1.30f, 6'500, 2'200, 1'800},
            {"Франция (Париж)",       1.60f, 9'000, 3'500, 3'000},
            {"Черногория (Будва)",    1.20f, 4'500, 1'800, 1'200},
            {"Венгрия (Будапешт)",    1.15f, 3'500, 1'500, 1'000},
            {"Чехия (Прага)",         1.20f, 4'000, 1'700, 1'100},
            {"Греция (Крит)",         1.30f, 5'500, 2'000, 1'500},
            {"Португалия (Лиссабон)", 1.25f, 5'000, 1'900, 1'400},
            {"Австрия (Вена)",        1.40f, 7'500, 2'800, 2'200},
            {"Хорватия (Дубровник)", 1.35f,  6'000, 2'300, 1'700},
            {"Финляндия (Хельсинки)",1.30f,  6'500, 2'100, 1'600},
        };
        return v;
    }
    static const std::vector<vacation_destination>& usd_destinations()
    {
        static const std::vector<vacation_destination> v{
            {"Таиланд (Бангкок)",   1.20f,  3'500, 1'200, 1'000},
            {"ОАЭ (Дубай)",         1.50f, 12'000, 4'000, 3'500},
            {"Мальдивы",            1.70f, 20'000, 5'000, 4'000},
            {"Вьетнам (Ханой)",     1.15f,  2'500,   900,   700},
            {"Индонезия (Бали)",    1.25f,  4'000, 1'400, 1'100},
            {"Китай (Шанхай)",      1.30f,  5'000, 1'800, 1'500},
            {"Египет (Хургада)",    1.20f,  4'000, 1'300, 1'000},
            {"Куба (Гавана)",       1.35f,  5'500, 1'700, 1'200},
            {"Мексика (Канкун)",    1.30f,  6'000, 2'000, 1'500},
            {"США (Нью-Йорк)",      1.60f, 11'000, 4'500, 4'000},
            {"Шри-Ланка (Коломбо)", 1.15f,  3'000, 1'100,   900},
            {"Марокко (Марракеш)",  1.20f,  3'200, 1'200,   950},
            {"Иордания (Петра)",    1.25f,  4'500, 1'500, 1'200},
        };
        return v;
    }
    static const std::vector<vacation_destination>& rub_destinations()
    {
        static const std::vector<vacation_destination> v{
            {"Абхазия (Сухум)",           1.10f, 2'500,   800, 600},
            {"Абхазия (Гагра)",           1.10f, 2'800,   900, 650},
            {"Южная Осетия (Цхинвали)",   1.05f, 1'800,   600, 400},
            {"Приднестровье (Тирасполь)", 1.08f, 1'500,   550, 350},
            {"Беларусь (Минск)",          1.05f, 3'000, 1'000, 800},
            {"Казахстан (Алма-Ата)",      1.10f, 3'500, 1'100, 900},
            {"Казахстан (Астана)",        1.10f, 3'800, 1'200, 950},
            {"Кыргызстан (Бишкек)",       1.08f, 2'200,   750, 550},
            {"Армения (Ереван)",          1.10f, 3'200, 1'050, 800},
            {"Крым (Ялта)",               1.12f, 3'000,   950, 700},
            {"Краснодарский край (Сочи)", 1.15f, 4'000, 1'200, 850},
            {"Карелия (Петрозаводск)",    1.08f, 2'500,   850, 600},
            {"Байкал (Иркутск)",          1.10f, 2'800,   900, 650},
            {"Алтай (Горно-Алтайск)",     1.10f, 2'600,   870, 620},
        };
        return v;
    }
};

std::pair<RUB, RUB> alice_vacation(std::mt19937& gen, const illness_result& illness)
{
    float vac_inflation = std::pow(1.08f, static_cast<float>(global_years_lived));
    vacation_profile profile = get_vacation_style(Alice.salary);

    std::vector<int> zone_weights;
    switch (profile.style)
    {
    case vacation_style::backpacker: zone_weights = { 30, 30, 40 }; break;
    case vacation_style::budget:     zone_weights = { 35, 35, 30 }; break;
    case vacation_style::comfort:    zone_weights = { 40, 40, 20 }; break;
    case vacation_style::luxury:     zone_weights = { 45, 50,  5 }; break;
    case vacation_style::elite:      zone_weights = { 40, 58,  2 }; break;
    }
    std::discrete_distribution<> zone_dist(zone_weights.begin(), zone_weights.end());
    vacation_currency_zone zone = static_cast<vacation_currency_zone>(zone_dist(gen));

    RUB vacation_budget_rub = static_cast<RUB>(Alice.salary * 12 * profile.budget_share);
    if (vacation_budget_rub > Alice.sber.account_rub)
        vacation_budget_rub = Alice.sber.account_rub / 2;

    switch (zone)
    {
    case vacation_currency_zone::EUR:
        if (Alice.sber.account_rub >= vacation_budget_rub)
            Alice.sber.rub_to_eur(vacation_budget_rub);
        break;
    case vacation_currency_zone::USD:
        if (Alice.sber.account_rub >= vacation_budget_rub)
            Alice.sber.rub_to_usd(vacation_budget_rub);
        break;
    case vacation_currency_zone::RUB:
        break;
    }

    const std::vector<vacation_destination>* dest_pool = nullptr;
    switch (zone)
    {
    case vacation_currency_zone::EUR: dest_pool = &vacation_pool::eur_destinations(); break;
    case vacation_currency_zone::USD: dest_pool = &vacation_pool::usd_destinations(); break;
    case vacation_currency_zone::RUB: dest_pool = &vacation_pool::rub_destinations(); break;
    }

    std::uniform_int_distribution<> dest_dist(0, (int)dest_pool->size() - 1);
    const vacation_destination& dest = (*dest_pool)[dest_dist(gen)];

    RUB base_flight_cost = 0;
    switch (zone)
    {
    case vacation_currency_zone::EUR: base_flight_cost = static_cast<RUB>(35'000 * vac_inflation); break;
    case vacation_currency_zone::USD: base_flight_cost = static_cast<RUB>(55'000 * vac_inflation); break;
    case vacation_currency_zone::RUB: base_flight_cost = static_cast<RUB>(10'000 * vac_inflation); break;
    }

    int days = profile.vacation_days;
    int sick_days = illness.sick ? std::min(illness.days, days) : 0;
    int well_days = days - sick_days;

    RUB flight_cost = static_cast<RUB>(base_flight_cost * dest.tourist_markup * profile.flight_multiplier);
    RUB hotel_cost = static_cast<RUB>(dest.avg_daily_hotel_rub * vac_inflation * days * dest.tourist_markup * profile.hotel_multiplier);
    RUB food_well = static_cast<RUB>(dest.avg_daily_food_rub * vac_inflation * well_days * dest.tourist_markup * profile.food_multiplier);
    RUB other_well = static_cast<RUB>(dest.avg_daily_other_rub * vac_inflation * well_days * dest.tourist_markup * profile.other_multiplier);
    RUB food_sick = static_cast<RUB>(dest.avg_daily_food_rub * vac_inflation * sick_days * dest.tourist_markup * profile.food_multiplier * illness.food_multiplier);
    RUB other_sick = static_cast<RUB>(dest.avg_daily_other_rub * vac_inflation * sick_days * dest.tourist_markup * profile.other_multiplier * 0.15f);
    RUB extras = static_cast<RUB>(profile.extras_rub * vac_inflation);
    RUB total_cost_rub = flight_cost + hotel_cost + food_well + food_sick + other_well + other_sick + extras;

    RUB other_full = static_cast<RUB>(dest.avg_daily_other_rub * vac_inflation * days * dest.tourist_markup * profile.other_multiplier);
    RUB food_full = static_cast<RUB>(dest.avg_daily_food_rub * vac_inflation * days * dest.tourist_markup * profile.food_multiplier);
    RUB saved = (other_full - other_well - other_sick) + (food_full - food_well - food_sick);
    if (saved < 0) saved = 0;

    switch (zone)
    {
    case vacation_currency_zone::EUR:
    {
        EUR cost_eur = static_cast<EUR>(std::ceil(total_cost_rub / Alice.sber.euro_rate()));
        EUR eur_before = Alice.sber.account_eur;
        if (Alice.sber.account_eur < cost_eur)
        {
            EUR need = cost_eur - Alice.sber.account_eur;
            RUB need_rub = static_cast<RUB>(need * Alice.sber.euro_rate()) + 1;
            if (Alice.sber.account_rub >= need_rub) Alice.sber.rub_to_eur(need_rub);
            else { cost_eur = Alice.sber.account_eur; total_cost_rub = static_cast<RUB>(cost_eur * Alice.sber.euro_rate()); }
        }
        Alice.sber.account_eur -= cost_eur;
        EUR leftover = Alice.sber.account_eur - eur_before;
        if (leftover > 0) Alice.sber.eur_to_rub(leftover);
        break;
    }
    case vacation_currency_zone::USD:
    {
        USD cost_usd = static_cast<USD>(std::ceil(total_cost_rub / Alice.sber.dollar_rate()));
        USD usd_before = Alice.sber.account_usd;
        if (Alice.sber.account_usd < cost_usd)
        {
            USD need = cost_usd - Alice.sber.account_usd;
            RUB need_rub = static_cast<RUB>(need * Alice.sber.dollar_rate()) + 1;
            if (Alice.sber.account_rub >= need_rub) Alice.sber.rub_to_usd(need_rub);
            else { cost_usd = Alice.sber.account_usd; total_cost_rub = static_cast<RUB>(cost_usd * Alice.sber.dollar_rate()); }
        }
        Alice.sber.account_usd -= cost_usd;
        USD leftover = Alice.sber.account_usd - usd_before;
        if (leftover > 0) Alice.sber.usd_to_rub(leftover);
        break;
    }
    case vacation_currency_zone::RUB:
        if (Alice.sber.account_rub < total_cost_rub) total_cost_rub = Alice.sber.account_rub;
        Alice.sber.account_rub -= total_cost_rub;
        break;
    }

    return { total_cost_rub, saved };
}

// ============================================================
//  Продуктовая система
// ============================================================

struct Ingredient { std::string name; double amount; };
struct Recipe { std::string name; std::vector<Ingredient> ingredients; };
struct shop_product { std::string name; double price_per_pack; double pack_size; };
struct purchased_item { std::string name; int packs_bought; double total_amount; double total_price; };
struct shop_result { std::vector<purchased_item> items; double total_spent = 0; };

enum class income_level { low, medium, high, rich };
enum class budget_mode { normal, no_snacks, cheap };

income_level get_income_level(double salary)
{
    if (salary < 30'000)  return income_level::low;
    if (salary < 250'000)  return income_level::medium;
    if (salary < 500'000) return income_level::high;
    return income_level::rich;
}

budget_mode get_budget_mode(double spent_so_far, double budget, int days_left, int total_days)
{
    int days_done = total_days - days_left;
    if (days_done == 0) return budget_mode::normal;
    double projected = (spent_so_far / days_done) * total_days;
    if (projected <= budget)       return budget_mode::normal;
    if (projected <= budget * 1.2) return budget_mode::no_snacks;
    return budget_mode::cheap;
}

struct price_catalog
{
    static const std::vector<shop_product>& get(income_level level)
    {
        float inf = inflation_factor();
        static std::vector<shop_product> low, medium, high, rich;

        low = {
            {"овсянка",40. * inf,500.},{"гречка",60. * inf,900.},{"рис",50. * inf,900.},
            {"манка",35. * inf,700.},{"молоко",60. * inf,1000.},{"яйца",70. * inf,10.},
            {"хлеб",35. * inf,500.},{"масло",90. * inf,200.},{"сыр",130. * inf,300.},
            {"колбаса",150. * inf,300.},{"курица",200. * inf,1000.},{"говядина",350. * inf,1000.},
            {"картошка",40. * inf,1000.},{"макароны",50. * inf,400.},{"помидоры",60. * inf,500.},
            {"огурцы",50. * inf,500.},{"капуста",30. * inf,1000.},{"морковь",35. * inf,500.},
            {"сметана",45. * inf,400.},{"борщ (набор)",120. * inf,1.},{"чай",60. * inf,100.},
            {"кофе",150. * inf,200.},{"сок",60. * inf,1000.},{"вода",25. * inf,500.},
            {"печенье",70. * inf,400.},{"шоколад",80. * inf,100.},{"чипсы",70. * inf,150.},
            {"орехи",120. * inf,150.},{"йогурт",40. * inf,300.},{"банан",20. * inf,1.},
            {"яблоко",15. * inf,1.},{"творог",70. * inf,200.},{"сосиски",120. * inf,400.},
            {"лапша",180. * inf,1.},{"перловка",35. * inf,800.},{"пшено",40. * inf,700.},
            {"кефир",50. * inf,900.},{"ряженка",55. * inf,500.},{"сухари",30. * inf,300.},
            {"пряники",60. * inf,400.},{"свёкла",25. * inf,500.},{"лук",20. * inf,500.},
            {"чеснок",30. * inf,100.},{"перец болгарский",80. * inf,300.},
        };
        medium = {
            {"овсянка",60. * inf,500.},{"гречка",90. * inf,900.},{"рис",80. * inf,900.},
            {"манка",55. * inf,700.},{"молоко",80. * inf,1000.},{"яйца",90. * inf,10.},
            {"хлеб",50. * inf,500.},{"масло",150. * inf,200.},{"сыр",200. * inf,300.},
            {"колбаса",250. * inf,300.},{"курица",300. * inf,1000.},{"говядина",500. * inf,1000.},
            {"картошка",60. * inf,1000.},{"макароны",70. * inf,400.},{"помидоры",90. * inf,500.},
            {"огурцы",70. * inf,500.},{"капуста",40. * inf,1000.},{"морковь",50. * inf,500.},
            {"сметана",60. * inf,400.},{"борщ (набор)",200. * inf,1.},{"чай",100. * inf,100.},
            {"кофе",300. * inf,200.},{"сок",90. * inf,1000.},{"вода",40. * inf,500.},
            {"печенье",120. * inf,400.},{"шоколад",150. * inf,100.},{"чипсы",100. * inf,150.},
            {"орехи",200. * inf,150.},{"йогурт",60. * inf,300.},{"банан",30. * inf,1.},
            {"яблоко",25. * inf,1.},{"творог",100. * inf,200.},{"сосиски",180. * inf,400.},
            {"лапша",250. * inf,1.},{"перловка",55. * inf,800.},{"пшено",60. * inf,700.},
            {"кефир",75. * inf,900.},{"ряженка",80. * inf,500.},{"сухари",50. * inf,300.},
            {"пряники",90. * inf,400.},{"свёкла",40. * inf,500.},{"лук",30. * inf,500.},
            {"чеснок",45. * inf,100.},{"перец болгарский",110. * inf,300.},
        };
        high = {
            {"овсянка",100. * inf,500.},{"гречка",150. * inf,900.},{"рис",130. * inf,900.},
            {"манка",90. * inf,700.},{"молоко",130. * inf,1000.},{"яйца",150. * inf,10.},
            {"хлеб",120. * inf,500.},{"масло",280. * inf,200.},{"сыр",450. * inf,300.},
            {"колбаса",500. * inf,300.},{"курица",550. * inf,1000.},{"говядина",900. * inf,1000.},
            {"картошка",100. * inf,1000.},{"макароны",150. * inf,400.},{"помидоры",200. * inf,500.},
            {"огурцы",180. * inf,500.},{"капуста",80. * inf,1000.},{"морковь",100. * inf,500.},
            {"сметана",130. * inf,400.},{"борщ (набор)",400. * inf,1.},{"чай",300. * inf,100.},
            {"кофе",800. * inf,200.},{"сок",200. * inf,1000.},{"вода",100. * inf,500.},
            {"печенье",300. * inf,400.},{"шоколад",400. * inf,100.},{"чипсы",200. * inf,150.},
            {"орехи",400. * inf,150.},{"йогурт",150. * inf,300.},{"банан",60. * inf,1.},
            {"яблоко",70. * inf,1.},{"творог",200. * inf,200.},{"сосиски",400. * inf,400.},
            {"лапша",400. * inf,1.},{"перловка",90. * inf,800.},{"пшено",100. * inf,700.},
            {"кефир",120. * inf,900.},{"ряженка",140. * inf,500.},{"сухари",80. * inf,300.},
            {"пряники",180. * inf,400.},{"свёкла",70. * inf,500.},{"лук",55. * inf,500.},
            {"чеснок",75. * inf,100.},{"перец болгарский",200. * inf,300.},
        };
        rich = {
            {"овсянка",150. * inf,500.},{"гречка",225. * inf,900.},{"рис",195. * inf,900.},
            {"манка",135. * inf,700.},{"молоко",195. * inf,1000.},{"яйца",225. * inf,10.},
            {"хлеб",180. * inf,500.},{"масло",420. * inf,200.},{"сыр",675. * inf,300.},
            {"колбаса",750. * inf,300.},{"курица",825. * inf,1000.},{"говядина",1350. * inf,1000.},
            {"картошка",150. * inf,1000.},{"макароны",225. * inf,400.},{"помидоры",300. * inf,500.},
            {"огурцы",270. * inf,500.},{"капуста",120. * inf,1000.},{"морковь",150. * inf,500.},
            {"сметана",195. * inf,400.},{"борщ (набор)",600. * inf,1.},{"чай",450. * inf,100.},
            {"кофе",1200. * inf,200.},{"сок",300. * inf,1000.},{"вода",150. * inf,500.},
            {"печенье",450. * inf,400.},{"шоколад",600. * inf,100.},{"чипсы",300. * inf,150.},
            {"орехи",600. * inf,150.},{"йогурт",225. * inf,300.},{"банан",90. * inf,1.},
            {"яблоко",105. * inf,1.},{"творог",300. * inf,200.},{"сосиски",600. * inf,400.},
            {"лапша",600. * inf,1.},{"перловка",135. * inf,800.},{"пшено",150. * inf,700.},
            {"кефир",180. * inf,900.},{"ряженка",210. * inf,500.},{"сухари",120. * inf,300.},
            {"пряники",270. * inf,400.},{"свёкла",105. * inf,500.},{"лук",82. * inf,500.},
            {"чеснок",112. * inf,100.},{"перец болгарский",300. * inf,300.},
        };

        switch (level)
        {
        case income_level::low:    return low;
        case income_level::medium: return medium;
        case income_level::high:   return high;
        case income_level::rich:   return rich;
        }
        return low;
    }
};

shop_result shop(const std::vector<std::pair<std::string, double>>& shopping_list, income_level level)
{
    const auto& products = price_catalog::get(level);
    std::unordered_map<std::string, const shop_product*> product_map;
    for (const auto& p : products) product_map[p.name] = &p;
    shop_result result;
    for (const auto& [name, needed] : shopping_list)
    {
        auto it = product_map.find(name);
        if (it == product_map.end()) continue;
        const shop_product& product = *it->second;
        int    packs = (int)std::ceil(needed / product.pack_size);
        double amt = packs * product.pack_size;
        double cost = packs * product.price_per_pack;
        result.items.push_back({ name, packs, amt, cost });
        result.total_spent += cost;
    }
    return result;
}

bool has_holiday(int month, int day)
{
    if (month == 1 && day == 1)  return true;
    if (month == 2 && day == 23) return true;
    if (month == 3 && day == 8)  return true;
    if (month == 5 && day == 9)  return true;
    if (month == 12 && day == 31) return true;
    return false;
}

int days_in_month(int month)
{
    constexpr int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month < 1 || month > 12) return 30;
    return days[month];
}

double buy_if_needed(std::unordered_map<std::string, double>& fridge,
    const Ingredient& ing, income_level level)
{
    double have = fridge[ing.name];
    if (have >= ing.amount) return 0.0;
    shop_result res = shop({ { ing.name, ing.amount - have } }, level);
    for (const auto& item : res.items) fridge[item.name] += item.total_amount;
    return res.total_spent;
}

double cook_meal(std::unordered_map<std::string, double>& fridge,
    const Recipe& meal, income_level level)
{
    double spent = 0.0;
    for (const auto& ing : meal.ingredients)
    {
        spent += buy_if_needed(fridge, ing, level);
        fridge[ing.name] -= ing.amount;
    }
    return spent;
}

// ============================================================
//  Книга рецептов
// ============================================================

struct recipe_book
{
    static const std::vector<Recipe>& porridges()
    {
        static const std::vector<Recipe> v{
            {"Овсянка на молоке",    {{"овсянка",80.},{"молоко",200.}}},
            {"Гречка с маслом",      {{"гречка",80.},{"масло",10.}}},
            {"Рисовая каша",         {{"рис",80.},{"молоко",200.}}},
            {"Манная каша",          {{"манка",60.},{"молоко",200.}}},
            {"Перловая каша",        {{"перловка",80.},{"масло",10.}}},
            {"Пшённая каша",         {{"пшено",70.},{"молоко",200.}}},
            {"Рисовая каша с маслом",{{"рис",80.},{"масло",10.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& light_breakfast()
    {
        static const std::vector<Recipe> v{
            {"Бутерброд с сыром",     {{"хлеб",80.},{"сыр",30.},{"масло",5.}}},
            {"Бутерброд с колбасой",  {{"хлеб",80.},{"колбаса",40.}}},
            {"Яичница глазунья",      {{"яйца",2.},{"масло",10.}}},
            {"Творог со сметаной",    {{"творог",150.},{"сметана",30.}}},
            {"Йогурт с бананом",      {{"йогурт",200.},{"банан",1.}}},
            {"Яйцо варёное с хлебом", {{"яйца",2.},{"хлеб",60.},{"масло",5.}}},
            {"Омлет",                 {{"яйца",3.},{"молоко",60.},{"масло",8.}}},
            {"Ряженка с сухарями",    {{"ряженка",300.},{"сухари",50.}}},
            {"Кефир с хлебом",        {{"кефир",250.},{"хлеб",60.}}},
            {"Бутерброд с сосисками", {{"хлеб",80.},{"сосиски",60.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& breakfast_drinks()
    {
        static const std::vector<Recipe> v{
            {"Чай",{{"чай",5.}}},{"Кофе",{{"кофе",10.}}},
            {"Сок",{{"сок",200.}}},{"Кефир",{{"кефир",250.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& first_course()
    {
        static const std::vector<Recipe> v{
            {"Борщ",           {{"борщ (набор)",1.},{"сметана",50.}}},
            {"Куриный суп",    {{"курица",300.},{"картошка",150.},{"морковь",50.}}},
            {"Гречневый суп",  {{"гречка",80.},{"морковь",50.},{"картошка",100.}}},
            {"Щи",             {{"капуста",200.},{"картошка",100.},{"морковь",40.},{"сметана",30.}}},
            {"Рассольник",     {{"рис",50.},{"картошка",150.},{"морковь",50.}}},
            {"Суп с перловкой",{{"перловка",60.},{"картошка",120.},{"морковь",40.}}},
            {"Лапша куриная",  {{"макароны",80.},{"курица",200.},{"морковь",30.}}},
            {"Гороховый суп",  {{"картошка",150.},{"морковь",50.},{"лук",30.}}},
            {"Суп из говядины",{{"говядина",200.},{"картошка",150.},{"морковь",50.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& second_course()
    {
        static const std::vector<Recipe> v{
            {"Курица с картошкой",   {{"курица",300.},{"картошка",250.}}},
            {"Макароны с сыром",     {{"макароны",200.},{"сыр",50.},{"масло",15.}}},
            {"Гречка с говядиной",   {{"гречка",150.},{"говядина",250.}}},
            {"Рис с курицей",        {{"рис",150.},{"курица",250.}}},
            {"Картошка с сосисками", {{"картошка",250.},{"сосиски",150.}}},
            {"Перловка с мясом",     {{"перловка",150.},{"говядина",200.}}},
            {"Макароны с говядиной", {{"макароны",200.},{"говядина",200.},{"масло",10.}}},
            {"Рис с сосисками",      {{"рис",150.},{"сосиски",120.}}},
            {"Пюре с котлетой",      {{"картошка",300.},{"говядина",150.},{"масло",20.}}},
            {"Гречка с курицей",     {{"гречка",150.},{"курица",200.}}},
            {"Тушёная капуста",      {{"капуста",300.},{"морковь",80.},{"масло",15.}}},
            {"Пшено с тыквой",       {{"пшено",120.},{"морковь",60.},{"масло",10.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& salads()
    {
        static const std::vector<Recipe> v{
            {"Салат овощной",   {{"помидоры",150.},{"огурцы",150.},{"сметана",30.}}},
            {"Салат капустный", {{"капуста",200.},{"морковь",80.},{"сметана",30.}}},
            {"Помидоры свежие", {{"помидоры",200.}}},
            {"Огурцы свежие",   {{"огурцы",200.}}},
            {"Тёртая морковь",  {{"морковь",150.},{"сметана",20.}}},
            {"Свёкла варёная",  {{"свёкла",150.},{"масло",10.}}},
            {"Нарезка овощная", {{"помидоры",100.},{"огурцы",100.},{"перец болгарский",50.}}},
            {"Салат с яйцом",   {{"яйца",2.},{"огурцы",100.},{"сметана",30.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& lunch_drinks()
    {
        static const std::vector<Recipe> v{
            {"Чай",{{"чай",5.}}},{"Сок",{{"сок",300.}}},
            {"Вода",{{"вода",500.}}},{"Кефир",{{"кефир",200.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& light_dinner()
    {
        static const std::vector<Recipe> v{
            {"Бутерброд с колбасой", {{"хлеб",80.},{"колбаса",40.}}},
            {"Яичница вечерняя",     {{"яйца",2.},{"масло",10.}}},
            {"Творог со сметаной",   {{"творог",150.},{"сметана",30.}}},
            {"Йогурт натуральный",   {{"йогурт",200.}}},
            {"Каша гречневая",       {{"гречка",80.},{"масло",10.}}},
            {"Бутерброд с сыром",    {{"хлеб",80.},{"сыр",30.}}},
            {"Кефир с хлебом",       {{"кефир",250.},{"хлеб",50.}}},
            {"Ряженка",              {{"ряженка",300.}}},
            {"Рисовая каша вечер",   {{"рис",80.},{"молоко",150.},{"масло",8.}}},
            {"Перловка с маслом",    {{"перловка",80.},{"масло",10.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& dinner_drinks()
    {
        static const std::vector<Recipe> v{
            {"Чай вечерний",{{"чай",5.}}},{"Кофе вечерний",{{"кофе",10.}}},
            {"Вода ночная",{{"вода",300.}}},{"Кефир вечером",{{"кефир",250.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& holiday_lunches()
    {
        static const std::vector<Recipe> v{
            {"Праздничная курица",{{"курица",800.},{"картошка",500.},{"сметана",100.}}},
            {"Плов праздничный",  {{"рис",300.},{"говядина",600.},{"морковь",150.},{"масло",50.}}},
            {"Запечённая курица", {{"курица",1000.},{"картошка",400.},{"сметана",80.}}},
            {"Говядина тушёная",  {{"говядина",700.},{"картошка",300.},{"морковь",100.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& snacks()
    {
        static const std::vector<Recipe> v{
            {"Печенье",{{"печенье",50.}}},{"Шоколад",{{"шоколад",25.}}},
            {"Чипсы",{{"чипсы",40.}}},{"Орехи",{{"орехи",30.}}},
            {"Банан",{{"банан",1.}}},{"Яблоко",{{"яблоко",1.}}},
            {"Лапша",{{"лапша",1.}}},{"Пряники",{{"пряники",60.}}},
            {"Йогурт",{{"йогурт",150.}}},{"Ряженка",{{"ряженка",200.}}},
            {"Сухари ржаные",{{"сухари",40.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& day_drinks()
    {
        static const std::vector<Recipe> v{
            {"Чай дневной",{{"чай",5.}}},{"Кофе дневной",{{"кофе",10.}}},
            {"Сок дневной",{{"сок",200.}}},{"Вода дневная",{{"вода",500.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_porridges()
    {
        static const std::vector<Recipe> v{
            {"Овсянка на воде", {{"овсянка",80.},{"вода",200.}}},
            {"Гречка на воде",  {{"гречка",80.}}},
            {"Перловка на воде",{{"перловка",80.},{"вода",200.}}},
            {"Пшённая на воде", {{"пшено",70.},{"вода",200.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_light()
    {
        static const std::vector<Recipe> v{
            {"Хлеб с маслом",{{"хлеб",80.},{"масло",5.}}},
            {"Яйцо варёное", {{"яйца",2.}}},
            {"Хлеб с кефиром",{{"хлеб",60.},{"кефир",200.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_drinks()
    {
        static const std::vector<Recipe> v{
            {"Чай эконом",{{"чай",5.}}},{"Вода эконом",{{"вода",300.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_first()
    {
        static const std::vector<Recipe> v{
            {"Картофельный суп",{{"картошка",200.},{"морковь",50.},{"лук",20.}}},
            {"Гречневый суп",   {{"гречка",80.},{"морковь",50.},{"лук",20.}}},
            {"Перловый суп",    {{"перловка",60.},{"картошка",150.},{"морковь",40.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_second()
    {
        static const std::vector<Recipe> v{
            {"Гречка с маслом",  {{"гречка",150.},{"масло",10.}}},
            {"Макароны с маслом",{{"макароны",200.},{"масло",10.}}},
            {"Рис с маслом",     {{"рис",150.},{"масло",10.}}},
            {"Перловка с луком", {{"перловка",150.},{"лук",30.},{"масло",8.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_dinner()
    {
        static const std::vector<Recipe> v{
            {"Хлеб с маслом",{{"хлеб",80.},{"масло",5.}}},
            {"Каша на воде", {{"гречка",80.}}},
            {"Яйцо варёное", {{"яйца",2.}}},
            {"Кефир",        {{"кефир",250.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& sick_breakfast()
    {
        static const std::vector<Recipe> v{
            {"Жидкая овсянка на воде",{{"овсянка",50.},{"вода",300.}}},
            {"Рисовый отвар",         {{"рис",40.},{"вода",400.}}},
            {"Сухарик с чаем",        {{"хлеб",30.},{"чай",5.}}},
            {"Жидкая манка",          {{"манка",40.},{"вода",300.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& sick_main()
    {
        static const std::vector<Recipe> v{
            {"Куриный бульон",    {{"курица",100.},{"морковь",20.},{"вода",500.}}},
            {"Картофельный суп",  {{"картошка",100.},{"морковь",20.},{"вода",400.}}},
            {"Гречка на воде",    {{"гречка",60.}}},
            {"Рис отварной",      {{"рис",60.},{"вода",200.}}},
            {"Куриный суп лёгкий",{{"курица",80.},{"рис",30.},{"вода",500.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& sick_drinks()
    {
        static const std::vector<Recipe> v{
            {"Стакан воды", {{"вода",300.}}},
            {"Тёплый чай",  {{"чай",5.},{"вода",300.}}},
            {"Чай с соком", {{"чай",5.},{"сок",50.},{"вода",200.}}},
            {"Тёплое молоко",{{"молоко",250.}}},
        };
        return v;
    }
};

double simulate_day(std::unordered_map<std::string, double>& fridge,
    income_level level, budget_mode mode,
    bool is_holiday_day, bool is_sick, std::mt19937& gen)
{
    auto pick = [&](const std::vector<Recipe>& v) -> const Recipe& {
        std::uniform_int_distribution<> d(0, (int)v.size() - 1);
        return v[d(gen)];
        };
    auto chance = [&](int pct) -> bool {
        std::uniform_int_distribution<> d(1, 100);
        return d(gen) <= pct;
        };

    double spent = 0.0;
    if (is_sick)
    {
        spent += cook_meal(fridge, pick(recipe_book::sick_breakfast()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_drinks()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_main()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_drinks()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_main()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_drinks()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_drinks()), level);
    }
    else
    {
        const bool cheap = (mode == budget_mode::cheap);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_porridges() : recipe_book::porridges()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_light() : recipe_book::light_breakfast()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_drinks() : recipe_book::breakfast_drinks()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_first() : recipe_book::first_course()), level);
        spent += cook_meal(fridge,
            (is_holiday_day && !cheap) ? pick(recipe_book::holiday_lunches())
            : pick(cheap ? recipe_book::cheap_second() : recipe_book::second_course()), level);
        if (!cheap) spent += cook_meal(fridge, pick(recipe_book::salads()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_drinks() : recipe_book::lunch_drinks()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_dinner() : recipe_book::light_dinner()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_drinks() : recipe_book::dinner_drinks()), level);
        if (mode == budget_mode::normal)
        {
            if (chance(70)) spent += cook_meal(fridge, pick(recipe_book::snacks()), level);
            if (chance(80)) spent += cook_meal(fridge, pick(recipe_book::day_drinks()), level);
        }
    }
    return spent;
}

RUB calc_food_cost(int month, int sick_days)
{
    std::mt19937 gen(std::random_device{}());
    income_level level = get_income_level(static_cast<double>(Alice.salary));
    double budget = Alice.salary * 0.30;
    double total_spent = 0.0;
    int    total_days = days_in_month(month);

    for (int day = 1; day <= total_days; ++day)
    {
        bool is_sick_today = (day <= sick_days);
        budget_mode mode = is_sick_today
            ? budget_mode::normal
            : get_budget_mode(total_spent, budget, total_days - day, total_days);
        total_spent += simulate_day(Alice.fridge, level, mode,
            has_holiday(month, day), is_sick_today, gen);
    }
    return static_cast<RUB>(total_spent * global_expense_multiplier);
}

// ============================================================
//  Случайные события месяца
// ============================================================

struct Event { std::string name_event; float chance; int income; bool used = false; };
struct month_result { std::vector<std::string> events; int total_income = 0; bool darwin_triggered = false; };

struct event_pool
{
    std::vector<Event> positive{
        {"Нашёл потерянный кошелёк",       2000,    750},
        {"Выполнил сложное задание",        3000,  5'000},
        {"Перевыполнил план продаж",        4000,  7'000},
        {"Выиграл в лотерею",           5,1'000'000},
        {"Сдал бутылки",                    7000,    200},
        {"Сдал макулатуру",                 7000,    500},
        {"Получил бонусные баллы магазина", 5000,  1'500},
        {"Нашёл мелочь в диване",           2000,    100},
        {"Нашёл 100 рублей на улице",       1200,    100},
        {"Нашёл 500 рублей на улице",        700,    500},
        {"Нашёл 1000 рублей на улице",       500,  1'000},
        {"Получил кэшбэк от банка",         4500,  2'000},
        {"Продал ненужные вещи",            2500,  3'500},
        {"Получил премию за стаж",          1500,  8'000},
        {"Сосед вернул долг",               1000,  4'000},
        {"Удачно перепродал акции",          800,  6'000},
        {"Выиграл в конкурсе",              1200,  2'500},
        {"Возврат налогового вычета",        500, 15'000},
        {"Бабушка дала деньги на день рожд",1800,  5'000},
        {"Нашёл ошибку в чеке в свою пользу",600, 1'200},
    };
    std::vector<Event> negative{
        {"Пропала мелочь из кошелька",      2000,   -100},
        {"Задержка транспорта, взял такси", 3000,   -400},
        {"Потерял вещь",                    1000,   -700},
        {"Случайная ссора — штраф",         1500,   -200},
        {"Сломался зонт",                   2000,   -500},
        {"Вы получили премию Дравина, из-за того, что задохнулись от вдоха", 4, -1},
        {"Штраф за просрочку платежа",      1200, -1'500},
        {"Испортился телефон — ремонт",      800, -3'000},
        {"Сломался бытовой прибор",          600, -4'500},
        {"Штраф от ИФНС",                    400, -2'000},
        {"Незапланированный подарок",        1800,-2'500},
        {"Разбил стекло/посуду",            1500,   -800},
        {"Испортились продукты — выброс",   2200,   -600},
        {"Лопнула труба — сантехник",        400, -6'000},
        {"Упала антенна — вызов мастера",    500, -1'800},
    };
    std::vector<Event> one_time_positive{
        {"Выиграл крупный приз",                5,  5'000, false},
        {"Получил неожиданную премию",          3,  3'000, false},
        {"Наследство от дальнего родственника", 1, 50'000, false},
        {"Выиграл грант на обучение",           2, 20'000, false},
    };
    std::vector<Event> one_time_negative{
        {"Серьёзная поломка техники",       4,  -4'000, false},
        {"Потерял важный документ",         3,  -1'500, false},
        {"Мошенничество — украли деньги",   2, -10'000, false},
        {"Затопил соседей снизу",           1, -25'000, false},
    };
};

bool pick_one_time(std::vector<Event>& pool, month_result& result, std::mt19937& gen)
{
    std::vector<int> weights, indices;
    for (int i = 0; i < (int)pool.size(); ++i)
        if (!pool[i].used) { weights.push_back((int)pool[i].chance); indices.push_back(i); }
    if (weights.empty()) return false;
    std::discrete_distribution<> dist(weights.begin(), weights.end());
    int idx = indices[dist(gen)];
    pool[idx].used = true;
    result.events.push_back(pool[idx].name_event);
    result.total_income += pool[idx].income;
    return true;
}

month_result generate_monthly_events()
{
    static std::random_device rd;
    static std::mt19937       gen(rd());
    static event_pool         pool;

    std::uniform_int_distribution<>  total_dist(6, 15);
    std::uniform_real_distribution<> mood_dist(0.3, 0.7);
    std::bernoulli_distribution      type_dist(mood_dist(gen));
    std::bernoulli_distribution      ultra_rare(0.02);

    int total_events = total_dist(gen);
    auto make_weights = [](const std::vector<Event>& v) {
        std::vector<int> w;
        for (const auto& e : v) w.push_back((int)e.chance);
        return w;
        };
    auto pos_w = make_weights(pool.positive);
    auto neg_w = make_weights(pool.negative);
    std::discrete_distribution<> pos_dist(pos_w.begin(), pos_w.end());
    std::discrete_distribution<> neg_dist(neg_w.begin(), neg_w.end());

    month_result result;
    result.events.reserve(total_events);
    for (int i = 0; i < total_events; ++i)
    {
        bool is_positive = type_dist(gen);
        if (ultra_rare(gen))
        {
            bool fired = is_positive
                ? pick_one_time(pool.one_time_positive, result, gen)
                : pick_one_time(pool.one_time_negative, result, gen);
            if (fired) continue;
        }
        if (is_positive)
        {
            int idx = pos_dist(gen);
            result.events.push_back(pool.positive[idx].name_event);
            result.total_income += pool.positive[idx].income;
        }
        else
        {
            int idx = neg_dist(gen);
            result.events.push_back(pool.negative[idx].name_event);
            result.total_income += pool.negative[idx].income;
            if (pool.negative[idx].name_event.find("Дравина") != std::string::npos)
                result.darwin_triggered = true;
        }
    }
    std::shuffle(result.events.begin(), result.events.end(), gen);
    return result;
}

// ============================================================
//  Вспомогательные функции отдельных расходов
// ============================================================

void process_car_service(int month)
{
    float car_parts_inflation = std::pow(1.08f, static_cast<float>(global_years_lived));

    std::map<std::string, RUB> parts_costs{
        {"filter_oil",    static_cast<RUB>(1'000 * car_parts_inflation)},
        {"filter_air",    static_cast<RUB>(750 * car_parts_inflation)},
        {"filter_fuel",   static_cast<RUB>(10'000 * car_parts_inflation)},
        {"filter_cabin",  static_cast<RUB>(5'600 * car_parts_inflation)},
        {"antifreeze",    static_cast<RUB>(2'400 * car_parts_inflation)},
        {"break_fluid",   static_cast<RUB>(9'000 * car_parts_inflation)},
        {"motor_oil",     static_cast<RUB>(5'000 * car_parts_inflation)},
        {"spark_plugs",   static_cast<RUB>(10'000 * car_parts_inflation)},
    };

    RUB cost = 0;
    if (month == 7)
        for (const auto& [part, price] : parts_costs) cost += price;
    cost += static_cast<RUB>(500 * car_parts_inflation);

    RUB actual = std::min(cost, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual;
}

void process_holiday_expenses(int month)
{
    struct HolidayEntry { int month; RUB base_cost; };
    static const HolidayEntry holiday_list[] = {
        { 1,  40'000 },
        { 2,  20'000 },
        { 3,  20'000 },
        { 12, 50'000 },
    };

    for (const auto& h : holiday_list)
    {
        if (h.month != month) continue;
        RUB cost = static_cast<RUB>(inflate(h.base_cost) * global_expense_multiplier);
        RUB actual = std::min(cost, std::max(0LL, Alice.sber.account_rub));
        Alice.sber.account_rub -= actual;
    }
}

RUB process_salary(illness_result& illness)
{
    int unpaid_days = 0;
    if (illness.sick)
    {
        switch (illness.severity)
        {
        case illness_severity::mild:
            unpaid_days = std::min(illness.days, 2); break;
        case illness_severity::moderate:
        case illness_severity::severe:
            unpaid_days = illness.days; break;
        default: break;
        }
    }
    RUB daily_rate = Alice.salary / 22;
    illness.lost_salary = daily_rate * std::min(unpaid_days, 22);
    Alice.sber.receive_salary(Alice.salary, unpaid_days);
    return illness.lost_salary;
}

void process_fuel(const illness_result& illness)
{
    float km = Alice.is_retired
        ? Alice.car.km_per_day * 0.25f
        : Alice.car.km_per_day;

    int sick_days = (!Alice.is_retired && illness.sick)
        ? std::min(illness.days, 22) : 0;

    fuel_params fp{ km, Alice.car.liters_per_100km, Alice.car.fuel_price, 22 };
    RUB fuel_cost = calc_monthly_fuel_cost(fp, sick_days);
    Alice.sber.account_rub -= fuel_cost;
    Alice.total_fuel_cost += fuel_cost;
}

void process_medicine(const illness_result& illness)
{
    if (!illness.sick) return;
    RUB medical_total = illness.doctor_cost + illness.medicine_cost;
    RUB actual_payment = std::min(medical_total, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual_payment;
    Alice.total_sick_days += illness.days;
    Alice.total_medical_cost += actual_payment;
    Alice.total_lost_salary += illness.lost_salary;
}

void process_investments(std::mt19937& gen)
{
    const RUB low_balance_threshold = Alice.salary * 2;

    bool hard_period = (Alice.sber.account_rub < low_balance_threshold)
        && (Alice.invest_portfolio > 0);
    if (hard_period)
    {
        RUB gross_profit = Alice.invest_portfolio - Alice.invest_cost_basis;
        RUB tax = gross_profit > 0
            ? taxes_state.calc_investment_tax(gross_profit) : 0;
        RUB payout = std::max(0LL, Alice.invest_portfolio - tax);
        Alice.sber.account_rub += payout;
        if (gross_profit > 0) Alice.total_invest_profit += gross_profit;
        Alice.invest_portfolio = 0;
        Alice.invest_cost_basis = 0;
        return;
    }

    RUB contrib = Alice.salary / 10;
    if (contrib > 0 && Alice.sber.account_rub >= contrib)
    {
        Alice.sber.account_rub -= contrib;
        Alice.invest_portfolio += contrib;
        Alice.invest_cost_basis += contrib;
    }

    if (Alice.invest_portfolio <= 0) return;

    std::uniform_real_distribution<float> market(-0.15f, 0.20f);
    float monthly_return = market(gen);
    RUB   delta = static_cast<RUB>(Alice.invest_portfolio * monthly_return);
    Alice.invest_portfolio += delta;

    if (Alice.invest_portfolio < 0)
    {
        RUB debt = -Alice.invest_portfolio;
        RUB covered = std::min(debt, std::max(0LL, Alice.sber.account_rub));
        Alice.sber.account_rub -= covered;
        Alice.total_invest_loss += debt;
        Alice.invest_portfolio = 0;
        Alice.invest_cost_basis = 0;
        return;
    }

    if (Alice.invest_cost_basis > 0)
    {
        float gain_pct = static_cast<float>(
            Alice.invest_portfolio - Alice.invest_cost_basis)
            / static_cast<float>(Alice.invest_cost_basis);

        if (gain_pct > 0.10f)
        {
            std::bernoulli_distribution sell_dist(0.40);
            if (sell_dist(gen))
            {
                RUB gross_profit = Alice.invest_portfolio - Alice.invest_cost_basis;
                RUB tax = taxes_state.calc_investment_tax(gross_profit);
                RUB payout = Alice.invest_portfolio - tax;
                Alice.sber.account_rub += payout;
                Alice.total_invest_profit += gross_profit;
                Alice.invest_portfolio = 0;
                Alice.invest_cost_basis = 0;
            }
        }
    }
}

void process_apartment_upgrade()
{
    const auto& catalog = apartment_catalog();
    int next_level = Alice.apartment_level + 1;
    if (next_level >= static_cast<int>(catalog.size())) return;

    RUB price = apartment_current_price(next_level);
    RUB needed = static_cast<RUB>(price * 1.1); 

    if (Alice.sber.total_assets_rub() >= needed && Alice.sber.account_rub >= price / 2)
    {
        while (Alice.sber.account_rub < price) {
            break;
        }
        if (Alice.sber.account_rub >= price) {
            Alice.sber.account_rub -= price;
            Alice.apartment_level = next_level;
        }
    }
}

void process_car_upgrade()
{
    bool car_old = Alice.car.age_years >= 10;
    bool car_worn = Alice.car.car_cost < Alice.car.car_cost_initial / 5;
    if (!car_old && !car_worn) return;

    RUB new_car_price = static_cast<RUB>(
        std::min((double)Alice.salary * 24.0 * inflation_factor(), 20'000'000.0));
    RUB cushion = Alice.salary * 6;

    if (Alice.sber.account_rub >= new_car_price + cushion)
    {
        Alice.sber.account_rub -= new_car_price;
        Alice.car.car_cost = new_car_price;
        Alice.car.car_cost_initial = new_car_price;
        Alice.car.age_years = 0;
        Alice.car.liters_per_100km = 8.5f;
        Alice.car.horsepower = 160;
    }
}

void process_property_tax()
{
    if (Alice.apartment_level < 0) return;
    const Apartment& apt = apartment_catalog()[Alice.apartment_level];
    RUB inflated_cadastral = static_cast<RUB>(
        apt.cadastral_value * std::pow(1.09f, static_cast<float>(global_years_lived)));
    RUB prop_tax = taxes_state.calc_property_tax(inflated_cadastral);
    RUB actual = std::min(prop_tax, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual;
    Alice.total_property_tax += actual;
}

void process_transport_tax()
{
    RUB transport_tax = static_cast<RUB>(
        taxes_state.calc_transport_tax(Alice.car.horsepower) * inflation_factor());
    RUB actual_tax = std::min(transport_tax, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual_tax;
    Alice.total_transport_tax += actual_tax;
}

void process_utilities()
{
    if (Alice.apartment_level < 0) return;
    RUB base_utilities = 5'000 * (Alice.apartment_level + 1);
    RUB utilities = static_cast<RUB>(
        base_utilities * 12 * std::pow(1.08f, (float)global_years_lived));
    RUB actual = std::min(utilities, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual;
}

void process_car_incident(std::mt19937& car_gen)
{
    car_event_result car_ev = generate_car_event(car_gen);
    if (!car_ev.happened) return;
    RUB actual = std::min(car_ev.total_cost, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual;
    Alice.total_car_repair_cost += actual;
    ++Alice.total_car_incidents;
}

// ============================================================
//  Инициализация
// ============================================================

void alice_start()
{
    global_years_lived = 0;
    global_expense_multiplier = 1.0f;

    Alice.age = 24;
    Alice.salary = 100'000;
    Alice.sber.account_rub = 0;

    Alice.car.car_cost = 4'000'000;
    Alice.car.car_cost_initial = 4'000'000;
    Alice.car.horsepower = 150;
    Alice.car.liters_per_100km = 9.5f;
    Alice.car.km_per_day = 40.0f;
    Alice.car.fuel_price = 58.0f;
    Alice.car.age_years = 0;
    Alice.car.fuel_cost_monthly = 0.0f;

    Alice.invest_portfolio = 0;
    Alice.invest_cost_basis = 0;
    Alice.total_invest_profit = 0;
    Alice.total_invest_loss = 0;

    Alice.total_sick_days = 0;
    Alice.total_medical_cost = 0;
    Alice.total_lost_salary = 0;
    Alice.total_fuel_cost = 0;
    Alice.total_transport_tax = 0;
    Alice.total_car_repair_cost = 0;
    Alice.total_car_incidents = 0;
    Alice.apartment_level = -1;
    Alice.total_property_tax = 0;

    Alice.is_married = false;
    Alice.has_first_child = false;
    Alice.is_grandmother = false;
    Alice.is_retired = false;
    Alice.passport_renewed = false;
    Alice.darwin_prize = false;
    Alice.career_multiplier = 1.0f;
}

// ============================================================
//  БЛОКИ ЖИЗНИ — тематические группы для alice_live()
// ============================================================

// ── Доходы: зарплата + случайные события ────────────────────
// Всё что приходит на счёт в этом месяце собрано здесь.
bool process_income(illness_result& illness)
{
    month_result events = generate_monthly_events();
    if (events.darwin_triggered)
    {
        Alice.darwin_prize = true;
        return false; // Алиса умерла
    }
    Alice.sber.account_rub += static_cast<RUB>(events.total_income * inflation_factor());

    process_salary(illness);
    return true;
}


void process_car_monthly(int month, const illness_result& illness,
    std::mt19937& car_gen)
{
    process_fuel(illness);
    process_car_service(month);
    process_car_incident(car_gen);
    if (month == 12) process_car_upgrade();
}


void process_living_expenses(int month, const illness_result& illness)
{
    Alice.sber.account_rub -= calc_food_cost(month, illness.sick ? illness.days : 0);
    process_holiday_expenses(month);
}


void process_health(const illness_result& illness)
{
    process_medicine(illness);
}


void process_savings(std::mt19937& invest_gen)
{
    process_investments(invest_gen);
    Alice.sber.accrue_month_deposits();
    Alice.sber.try_auto_deposit();
}


void process_annual_housing_and_taxes(const int month)
{
    if (month == 12) {
        process_apartment_upgrade();
        process_property_tax();
        process_transport_tax();
        process_utilities();
    }
}


void process_vacation(const int month, illness_result& illness, std::mt19937& vacation_gen)
{
    if (month == 7) {
        auto [vcost, vsaved] = alice_vacation(vacation_gen, illness);
        illness.vacation_savings = vsaved;
    }
}


void process_new_year(const int month, std::mt19937& career_gen)
{
    if (month == 1) {
        check_age_events(Alice.age);
        if (global_years_lived > 0) apply_annual_salary_growth(career_gen);
        Alice.car.depreciate();
    }
}


void Alice_birthday(const int month)
{
    if (month == 1) ++Alice.age;
}

// ============================================================
//  Премия Дарвина — финальный экран
// ============================================================

void print_darwin_award()
{
    const std::string GOLD = "\033[38;5;220m";
    const std::string DARK = "\033[38;5;94m";
    const std::string GRAY = "\033[38;5;240m";
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";

    std::cout << BOLD;

    std::cout << GOLD << "                /\\   /\\   /\\           " << RESET << "\n";
    std::cout << GOLD << "               /  \\ /  \\ /  \\          " << RESET << "\n";
    std::cout << GOLD << "              /    V    V    \\         " << RESET << "\n";
    std::cout << GOLD << "             |________________|        " << RESET << "\n";
    std::cout << GOLD << "             |________________|        " << RESET << "\n";

    // Ручки и тело кубка
    std::cout << GOLD << "            .'`   .======.   `'.      " << RESET << "\n";
    std::cout << GOLD << "          /  //  (        )  \\\\  \\" << RESET << "\n";
    std::cout << GOLD << "         |  //    \\      /    \\\\  |" << RESET << "\n";
    std::cout << GOLD << "         | //      )    (      \\\\ |" << RESET << "\n";
    std::cout << GOLD << "         |//       \\    /       \\\\|" << RESET << "\n";
    std::cout << GOLD << "         //    .    `--'    .    \\\\" << RESET << "\n";
    std::cout << GOLD << "        //    / \\          / \\    \\\\" << RESET << "\n";
    std::cout << GOLD << "        \\`.__/   `.______.'   \\__.'/" << RESET << "\n";

    // Ножка
    std::cout << GOLD << "                |          |          " << RESET << "\n";
    std::cout << GOLD << "                |          |          " << RESET << "\n";
    std::cout << GOLD << "               /|          |\\         " << RESET << "\n";
    std::cout << GOLD << "              / |          | \\        " << RESET << "\n";
    std::cout << GOLD << "             /  '----------'  \\       " << RESET << "\n";

    // Подставка
    std::cout << GRAY << "         .========================.  " << RESET << "\n";
    std::cout << GRAY << "         | " << GOLD << " .------------------. " << GRAY << " |  " << RESET << "\n";
    std::cout << GRAY << "         | " << GOLD << " |                  | " << GRAY << " |  " << RESET << "\n";
    std::cout << GRAY << "         | " << GOLD << " `------------------' " << GRAY << " |  " << RESET << "\n";
    std::cout << GRAY << "         '========================'  " << RESET << "\n";
    std::cout << GRAY << "        .-'----------------------'-.  " << RESET << "\n";
    std::cout << GRAY << "       /____________________________\\ " << RESET << "\n";

    std::cout << "\n";
            std::cout << "  Приносим свои извинения, но вы не смогли\n";
    std::cout << "  удивить Алису, поэтому она умерла от вдоха.\n";
    std::cout << "\n";
    std::cout << "  ╔══════════════════════════════════════════╗\n";
    std::cout << "  ║    Вручается премия Дарвина за самый     ║\n";
    std::cout << "  ║               конченый код               ║\n";
    std::cout << "  ╚══════════════════════════════════════════╝\n";
    std::cout << "\n";
}

// ============================================================
//  Основной цикл жизни
// ============================================================

bool alice_live()
{
    static std::mt19937 vacation_gen(std::random_device{}());
    static std::mt19937 illness_gen(std::random_device{}());
    static std::mt19937 car_gen(std::random_device{}());
    static std::mt19937 career_gen(std::random_device{}());
    static std::mt19937 invest_gen(std::random_device{}());

    int month = 1;
    illness_result illness;

    while (Alice.age < 97)
    {
        illness = generate_illness(illness_gen);

        if (!process_income(illness))
        {
            print_darwin_award();
            return true;
        }

        process_living_expenses(month, illness);
        process_health(illness);
        process_car_monthly(month, illness, car_gen);
        process_savings(invest_gen);
        process_vacation(month, illness, vacation_gen);
        process_annual_housing_and_taxes(month);
        process_new_year(month, career_gen); 
        Alice_birthday(month);
        
        ++month;
        if (month == 13) { 
            month = 1; 
            ++global_years_lived; 
        }
    }

    return false;
}

// ============================================================
//  БЛОКИ ОТЧЁТА — тематические секции для alice_conclusion()
// ============================================================

namespace report
{
    // Вспомогательные типографские функции
    static constexpr int W = 54;
    static constexpr int WL = 34;
    static constexpr int WR = 16;

    int vis_len(const std::string& s)
    {
        int len = 0;
        for (unsigned char c : s)
            if ((c & 0xC0) != 0x80) ++len;
        return len;
    }

    void hline(char c = '-')
    {
        std::cout << std::setfill(c) << std::setw(W + 2) << "" << std::setfill(' ') << "\n";
    }

    void title(const std::string& s)
    {
        std::string padded = " " + s;
        int pad = W - vis_len(padded);
        std::cout << "|" << padded << std::string(std::max(0, pad), ' ') << "|\n";
    }

    void row(const std::string& label, const std::string& value)
    {
        int lpad = WL - vis_len(label);
        int rpad = WR - vis_len(value);
        std::cout << "|  " << label << std::string(std::max(0, lpad), ' ')
            << std::string(std::max(0, rpad), ' ') << value << "  |\n";
    }

    void row_rub(const std::string& label, RUB value)
    {
        row(label, std::to_string(value) + " руб.");
    }

    void center_line(const std::string& s)
    {
        int vl = vis_len(s);
        int lp = (W - vl) / 2, rp = W - vl - lp;
        std::cout << "|" << std::string(lp, ' ') << s << std::string(rp, ' ') << "|\n";
    }

    // ── Секция: биография (хроника жизни) ───────────────────
    void print_biography()
    {
        auto life_event = [](const char* tag, const std::string& text) {
            std::cout << std::left << std::setw(11) << tag << text << "\n";
            };

        life_event("[24 года]", "Начало самостоятельной жизни. Зарплата 20 000 руб.,");
        std::cout << std::setw(11) << "" << "автомобиль за 4 000 000 руб.\n";
        if (Alice.is_married)       life_event("[30 лет] ", "Вышла замуж. Свадьба, кольца, счастье.");
        if (Alice.has_first_child)  life_event("[32 года]", "Родился первый ребёнок. Декрет, бессонные ночи.");
        if (Alice.passport_renewed) life_event("[45 лет] ", "Сходила в МФЦ — поменяла паспорт.");
        if (Alice.apartment_level >= 0)
        {
            const Apartment& best = apartment_catalog()[Alice.apartment_level];
            std::cout << std::left << std::setw(11) << "[жильё]"
                << "\"" << best.name << "\" (" << best.area_sqm << " кв.м)\n";
        }
        if (Alice.is_grandmother) life_event("[64 года]", "Стала бабушкой. Подарки, радость, новый круг.");
        if (Alice.is_retired)     life_event("[65 лет] ", "Вышла на пенсию. Торт, цветы, свобода.");
    }

    // ── Секция: карьера и автомобиль (краткая сводка) ───────
    void print_career_and_car()
    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << Alice.career_multiplier << "x";
        std::cout << std::setw(11) << "[карьера]"
            << "Рост зарплаты за всю жизнь: " << oss.str() << "\n"
            << std::setw(11) << ""
            << "Финальная зарплата: " << Alice.salary << " руб./мес.\n\n";

        std::cout << std::setw(11) << "[авто]"
            << "Куплен за " << Alice.car.car_cost_initial << " руб., "
            << "сейчас стоит " << Alice.car.car_cost
            << " руб. (возраст " << Alice.car.age_years << " лет)\n\n";
    }

    // ── Секция: здоровье ────────────────────────────────────
    void print_health_section()
    {
        hline('-'); title("  ЗДОРОВЬЕ"); hline('-');
        row("Дней на больничном", std::to_string(Alice.total_sick_days) + " дней.");
        row_rub("Расходы на медицину", Alice.total_medical_cost);
        row_rub("Потери зарплаты (болезни)", Alice.total_lost_salary);
        hline('-');
        if (Alice.total_sick_days < 200) title("  Отличное здоровье — редко брала больничный.");
        else if (Alice.total_sick_days < 600) title("  Болела регулярно, но всегда справлялась.");
        else                                  title("  Здоровье доставляло немало хлопот.");
        std::cout << "\n";
    }

    // ── Секция: транспорт ────────────────────────────────────
    void print_transport_section()
    {
        hline('-'); title("  АВТОМОБИЛЬ"); hline('-');
        row_rub("Расходы на бензин", Alice.total_fuel_cost);
        row_rub("Транспортный налог", Alice.total_transport_tax);
        row_rub("Ремонты (инциденты)", Alice.total_car_repair_cost);
        row("Количество происшествий", std::to_string(Alice.total_car_incidents) + " шт.");
        row_rub("Текущая стоимость авто", Alice.car.car_cost);
        hline('-');
        row_rub("ИТОГО на автомобиль", Alice.total_fuel_cost
            + Alice.total_transport_tax
            + Alice.total_car_repair_cost);
        hline('-');
        if (Alice.total_car_incidents == 0) title("  Ни единой аварии — повезло!");
        else                                title("  С машиной случалось всякое.");
        std::cout << "\n";
    }

    // ── Секция: жильё ────────────────────────────────────────
    void print_housing_section()
    {
        hline('-'); title("  ЖИЛЬЁ"); hline('-');
        if (Alice.apartment_level < 0)
        {
            title("  Собственной квартиры так и не появилось.");
            title("  Всю жизнь снимала или жила с родственниками.");
        }
        else
        {
            const Apartment& apt = apartment_catalog()[Alice.apartment_level];
            row("Последняя квартира", apt.name);
            row("Площадь", std::to_string(apt.area_sqm) + " кв.м");
            row_rub("Цена покупки (базовая)", apt.price);
            row_rub("Кадастровая стоимость", apt.cadastral_value);
            row_rub("Налог на имущество", Alice.total_property_tax);
            hline('-');
            if (Alice.apartment_level == 0) title("  Скромный, но свой угол — это тоже немало.");
            else if (Alice.apartment_level <= 2) title("  Хорошая квартира, нажитая честным трудом.");
            else                                 title("  Роскошное жильё — итог всей жизни.");
        }
        std::cout << "\n";
    }

    // ── Секция: банковские вклады ────────────────────────────
    void print_deposits_section()
    {
        hline('-'); title("  БАНКОВСКИЕ ВКЛАДЫ"); hline('-');
        Alice.sber.print_deposit_summary();
        hline('-');
        std::cout << "\n";
    }

    // ── Секция: инвестиции ───────────────────────────────────
    void print_investments_section()
    {
        hline('-'); title("  ИНВЕСТИЦИИ В АКЦИИ"); hline('-');
        row_rub("Текущий портфель", Alice.invest_portfolio);
        row_rub("Суммарная зафикс. прибыль", Alice.total_invest_profit);
        row_rub("Суммарные покрытые убытки", Alice.total_invest_loss);
        row_rub("Чистый инвест. результат", Alice.total_invest_profit - Alice.total_invest_loss);
        hline('-');
        if (Alice.total_invest_profit > Alice.total_invest_loss)
            title("  Биржа принесла свои плоды.");
        else
            title("  Рынок не всегда был благосклонен.");
        std::cout << "\n";
    }

    // ── Секция: финансовый итог ──────────────────────────────
    void print_financial_summary()
    {
        hline('-'); title("  ФИНАНСОВЫЙ ИТОГ"); hline('-');
        Alice.sber.print_account_summary();
        if (Alice.invest_portfolio > 0)
            row_rub("Инвест. портфель (акции)", Alice.invest_portfolio);

        RUB total = Alice.sber.total_assets_rub() + Alice.invest_portfolio;
        RUB grand_total = total + Alice.car.car_cost;

        hline('-');
        row_rub("ИТОГО без авто", total);
        row_rub("Стоимость автомобиля", Alice.car.car_cost);
        hline('-');
        row_rub("ИТОГО со всеми активами", grand_total);
        hline('-');

        // Процентная разбивка расходов
        RUB total_spent = Alice.total_medical_cost + Alice.total_fuel_cost
            + Alice.total_transport_tax + Alice.total_car_repair_cost
            + Alice.total_property_tax;
        if (total_spent > 0)
        {
            auto pct_str = [&](RUB part) {
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(1) << (part * 100.0 / total_spent) << "%";
                return oss.str();
                };
            row("Медицина (% расходов)", pct_str(Alice.total_medical_cost));
            row("Автомобиль (% расходов)", pct_str(Alice.total_fuel_cost
                + Alice.total_transport_tax
                + Alice.total_car_repair_cost));
            row("Имущество (% расходов)", pct_str(Alice.total_property_tax));
            hline('-');
        }

        if (grand_total <= 0)        title("  Жизнь прожита на полную — денег не осталось.");
        else if (grand_total < 500'000)   title("  Скромные сбережения, зато прожита честно.");
        else if (grand_total < 5'000'000) title("  Приличная сумма — есть что оставить детям.");
        else                              title("  Финансовый гений своего времени.");

        std::cout << "\n";
    }

} // namespace report

// ============================================================
//  Итоговый отчёт
// ============================================================

void alice_conclusion()
{
    using namespace report;

    hline('='); center_line("ИСТОРИЯ ЖИЗНИ АЛИСЫ"); hline('=');
    std::cout << "\n";

    print_biography();
    std::cout << "\n";
    print_career_and_car();

    print_health_section();
    print_transport_section();
    print_housing_section();
    print_deposits_section();
    print_investments_section();
    print_financial_summary();

    hline('='); center_line("К О Н Е Ц"); hline('=');
    std::cout << "\n";
}

// ============================================================
//  Точка входа
// ============================================================

int main()
{
    setlocale(LC_ALL, "ru");
    alice_start();
    if (!alice_live())
        alice_conclusion();
    return 0;
}#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <sstream>

using RUB = long long int;
using USD = long long int;
using EUR = long long int;
using procent = const float;

// ============================================================
//  Глобальный счётчик прожитых лет (для расчёта инфляции)
// ============================================================

static int g_years_lived = 0;
static constexpr float ANNUAL_INFLATION_RATE = 0.07f;

float inflation_factor()
{
    return std::pow(1.0f + ANNUAL_INFLATION_RATE, static_cast<float>(g_years_lived));
}

RUB inflate(RUB base_price)
{
    return static_cast<RUB>(base_price * inflation_factor());
}

float inflate_f(float base_price)
{
    return base_price * inflation_factor();
}

// Множитель расходов семьи: 1.0=одна, 1.5=замужем/бабушка, 2.0=с ребёнком
static float g_expense_multiplier = 1.0f;

// ============================================================
//  Налоговые ставки и сборы
// ============================================================

struct taxes_state
{
    procent income_tax = 13.0f;
    procent income_tax_high = 15.0f;
    procent investment_tax = 13.0f;
    procent deposit_tax = 13.0f;
    procent transport_tax_rate = 15.0f;
    procent property_tax = 0.1f;
    procent pension_fund = 22.0f;
    procent social_insurance = 2.9f;
    procent medical_insurance = 5.1f;
    procent vat = 22.0f;
    procent vat_food = 10.0f;

    RUB   calc_income_tax(RUB gross, RUB annual_income_so_far = 0) const;
    RUB   calc_transport_tax(int horsepower)      const;
    RUB   calc_deposit_tax(RUB interest_earned) const;
    RUB   calc_investment_tax(RUB profit)          const;
    RUB   calc_property_tax(RUB cadastral_value) const;
    float total_employer_burden() const;
};

RUB taxes_state::calc_income_tax(RUB gross, RUB annual_income_so_far) const
{
    const RUB threshold = 5'000'000;
    RUB total = annual_income_so_far + gross;
    
    if (total <= threshold)
        return static_cast<RUB>(gross * (income_tax / 100.0f));
    
    if (annual_income_so_far >= threshold)
        return static_cast<RUB>(gross * (income_tax_high / 100.0f));
    
    RUB below = threshold - annual_income_so_far;
    RUB above = gross - below;
    return static_cast<RUB>(below * (income_tax / 100.0f))
        + static_cast<RUB>(above * (income_tax_high / 100.0f));
}

RUB taxes_state::calc_transport_tax(int horsepower) const
{
    return static_cast<RUB>(horsepower * transport_tax_rate);
}

RUB taxes_state::calc_deposit_tax(RUB interest_earned) const
{
    return static_cast<RUB>(interest_earned * (deposit_tax / 100.0f));
}

RUB taxes_state::calc_investment_tax(RUB profit) const
{
    return profit > 0 ? static_cast<RUB>(profit * (investment_tax / 100.0f)) : 0;
}

RUB taxes_state::calc_property_tax(RUB cadastral_value) const
{
    return static_cast<RUB>(cadastral_value * (property_tax / 100.0f));
}

float taxes_state::total_employer_burden() const
{
    return pension_fund + social_insurance + medical_insurance;
}

struct taxes_state taxes_state;

// ============================================================
//  class Bank — банк Алисы
// ============================================================

class Bank
{
private:
    float BASE_DOLLAR_RATE = 90.91f;
    float BASE_EURO_RATE = 100.00f;
    float deposit_rate_short = 0.14f;
    float deposit_rate_long = 0.18f;
    static constexpr RUB   MIN_DEPOSIT_SUM = 30'000;

    struct transaction { std::string type; RUB amount_rub; std::string note; };

    struct deposit
    {
        std::string name;
        RUB   principal;
        RUB   accrued = 0;
        float rate;
        int   total_months;
        int   months_done = 0;
        bool  active = true;

        RUB  monthly_gain()    const;
        RUB  tax_on_interest() const;
        RUB  payout()          const;
        void accrue_month();
    };

    std::vector<transaction> tx_history;
    std::vector<deposit>     deposits;
    int next_deposit_id = 1;

    void     log(const std::string& type, RUB amount, const std::string& note);
    void     require_rub(RUB needed) const;
    deposit& find_deposit(int id);

public:
    RUB account_rub = 0;
    USD account_usd = 0;
    EUR account_eur = 0;

    RUB total_deposit_interest_earned = 0;
    RUB total_deposit_tax_paid = 0;
    int total_deposits_opened = 0;
    int total_deposits_closed = 0;

    float dollar_rate() const;
    float euro_rate()   const;

    void rub_to_usd(RUB amount);
    void rub_to_eur(RUB amount);
    void usd_to_rub(USD amount);
    void eur_to_rub(EUR amount);

    void receive_salary(RUB gross, int unpaid_days,
        const std::string& employer = "Работодатель");

    int  open_deposit_short(const std::string& dep_name, RUB amount);
    int  open_deposit_long(const std::string& dep_name, RUB amount);
    void close_deposit(int id);
    void accrue_month_deposits();
    void try_auto_deposit();

    RUB  total_assets_rub() const;

    void print_account_summary() const;
    void print_deposits()        const;
    void print_deposit_summary() const;
    void print_history(int last_n = 10) const;
};

RUB Bank::deposit::monthly_gain() const
{
    return static_cast<RUB>(principal * (rate / 12.0f));
}

RUB Bank::deposit::tax_on_interest() const
{
    return static_cast<RUB>(accrued * 0.035f);
}

RUB Bank::deposit::payout() const
{
    return principal + accrued - tax_on_interest();
}

void Bank::deposit::accrue_month()
{
    if (!active) return;
    accrued += monthly_gain();
    ++months_done;
}

void Bank::log(const std::string& type, RUB amount, const std::string& note)
{
    tx_history.push_back({ type, amount, note });
}

void Bank::require_rub(RUB needed) const
{
    if (account_rub < needed)
        throw std::runtime_error("Недостаточно RUB: нужно " +
            std::to_string(needed) + ", есть " + std::to_string(account_rub));
}

Bank::deposit& Bank::find_deposit(int id)
{
    if (id < 1 || id > static_cast<int>(deposits.size()))
        throw std::runtime_error("Вклад не найден: " + std::to_string(id));
    return deposits[id - 1];
}

float Bank::dollar_rate() const
{
    return BASE_DOLLAR_RATE;
}

float Bank::euro_rate() const
{
    return BASE_EURO_RATE;
}

void Bank::rub_to_usd(RUB amount)
{
    require_rub(amount);
    account_rub -= amount;
    account_usd += static_cast<USD>(amount / dollar_rate());
    log("Обмен RUB->USD", amount, "курс=" + std::to_string(static_cast<int>(dollar_rate())));
}

void Bank::rub_to_eur(RUB amount)
{
    require_rub(amount);
    account_rub -= amount;
    account_eur += static_cast<EUR>(amount / euro_rate());
    log("Обмен RUB->EUR", amount, "курс=" + std::to_string(static_cast<int>(euro_rate())));
}

void Bank::usd_to_rub(USD amount)
{
    if (account_usd < amount) throw std::runtime_error("Недостаточно USD");
    account_usd -= amount;
    account_rub += static_cast<RUB>(amount * dollar_rate());
    log("Обмен USD->RUB", static_cast<RUB>(amount * dollar_rate()), "");
}

void Bank::eur_to_rub(EUR amount)
{
    if (account_eur < amount) throw std::runtime_error("Недостаточно EUR");
    account_eur -= amount;
    account_rub += static_cast<RUB>(amount * euro_rate());
    log("Обмен EUR->RUB", static_cast<RUB>(amount * euro_rate()), "");
}

void Bank::receive_salary(RUB gross, int unpaid_days, const std::string& employer)
{
    RUB daily_rate = gross / 22;
    RUB lost_pay = daily_rate * std::min(unpaid_days, 22);
    RUB reduced_gross = std::max(0LL, gross - lost_pay);
    RUB tax = taxes_state.calc_income_tax(reduced_gross);
    RUB net = reduced_gross - tax;
    account_rub += net;
    log("Зарплата (нетто)", net, "от " + employer);
    log("НДФЛ удержан", tax, std::to_string(taxes_state.income_tax) + "%");
    if (unpaid_days > 0)
        log("Потеря (болезнь)", lost_pay,
            "не оплачено " + std::to_string(unpaid_days) + " дн.");
}

int Bank::open_deposit_short(const std::string& dep_name, RUB amount)
{
    require_rub(amount);
    account_rub -= amount;
    deposits.push_back({ dep_name, amount, 0, deposit_rate_short, 3 });
    log("Вклад открыт (3 мес.)", amount, dep_name + " 14% год.");
    ++total_deposits_opened;
    return next_deposit_id++;
}

int Bank::open_deposit_long(const std::string& dep_name, RUB amount)
{
    require_rub(amount);
    account_rub -= amount;
    deposits.push_back({ dep_name, amount, 0, deposit_rate_long, 36 });
    log("Вклад открыт (36 мес.)", amount, dep_name + " 18% год.");
    ++total_deposits_opened;
    return next_deposit_id++;
}

void Bank::close_deposit(int id)
{
    deposit& dep = find_deposit(id);
    if (!dep.active) return;
    RUB interest = dep.accrued;
    RUB tax = dep.tax_on_interest();
    RUB payout = dep.payout();
    account_rub += payout;
    dep.active = false;
    total_deposit_interest_earned += interest;
    total_deposit_tax_paid += tax;
    ++total_deposits_closed;
    log("Вклад закрыт", payout, dep.name + " (%" + std::to_string(interest) + " руб.)");
    if (tax > 0)
        log("Налог с вклада", tax, "удержан автоматически");
}

void Bank::accrue_month_deposits()
{
    for (int i = 0; i < static_cast<int>(deposits.size()); ++i)
    {
        deposit& dep = deposits[i];
        if (!dep.active) continue;
        dep.accrue_month();
        if (dep.months_done >= dep.total_months)
            close_deposit(i + 1);
    }
}

void Bank::try_auto_deposit()
{
    bool has_long_active = false;
    for (const auto& dep : deposits)
        if (dep.active && dep.total_months == 36) { has_long_active = true; break; }

    const RUB cushion = 50'000;

    if (!has_long_active && account_rub >= 200'000 + cushion)
    {
        RUB to_deposit = account_rub - cushion;
        if (to_deposit >= MIN_DEPOSIT_SUM)
        {
            open_deposit_long("Долгосрочный вклад", to_deposit);
            return;
        }
    }

    bool has_short_active = false;
    for (const auto& dep : deposits)
        if (dep.active && dep.total_months == 3) { has_short_active = true; break; }

    if (!has_short_active && account_rub >= MIN_DEPOSIT_SUM * 2 + cushion)
    {
        RUB to_deposit = account_rub / 2;
        if (to_deposit >= MIN_DEPOSIT_SUM)
            open_deposit_short("Краткосрочный вклад", to_deposit);
    }
}

RUB Bank::total_assets_rub() const
{
    RUB total = account_rub
        + static_cast<RUB>(account_usd * dollar_rate())
        + static_cast<RUB>(account_eur * euro_rate());
    for (const auto& dep : deposits)
        if (dep.active) total += dep.payout();
    return total;
}

void Bank::print_account_summary() const
{
    std::cout << "  Количество рублей: " << account_rub << " руб.\n";
    if (account_usd > 0)
        std::cout << "  Количество долларов: " << account_usd
        << " (≈" << static_cast<RUB>(account_usd * dollar_rate()) << " руб.)\n";
    if (account_eur > 0)
        std::cout << "  Количество евро: " << account_eur
        << " (≈" << static_cast<RUB>(account_eur * euro_rate()) << " руб.)\n";
    std::cout << "  Сумма всех денег Алисы в рублях: " << total_assets_rub() << " руб.\n";
}

void Bank::print_deposits() const
{
    std::cout << "\n=== Вклады ===\n";
    if (deposits.empty()) { std::cout << "  Нет вкладов\n"; return; }
    for (int i = 0; i < static_cast<int>(deposits.size()); ++i)
    {
        const auto& dep = deposits[i];
        std::cout << "  [" << (i + 1) << "] " << dep.name
            << " | тело=" << dep.principal << " руб."
            << " | начислено=" << dep.accrued << " руб."
            << " | " << dep.months_done << "/" << dep.total_months << " мес."
            << " | " << (dep.active ? "активен" : "закрыт")
            << " | к выплате=" << dep.payout() << " руб.\n";
    }
}

void Bank::print_deposit_summary() const
{
    std::cout << "  Вкладов открыто:         " << total_deposits_opened << " шт.\n"
        << "  Вкладов закрыто:         " << total_deposits_closed << " шт.\n"
        << "  Заработано процентов:    " << total_deposit_interest_earned << " руб.\n"
        << "  Налог с процентов:       " << total_deposit_tax_paid << " руб.\n"
        << "  Чистый доход от вкладов: "
        << (total_deposit_interest_earned - total_deposit_tax_paid) << " руб.\n";
}

void Bank::print_history(int last_n) const
{
    std::cout << "=== Последние " << last_n << " операций ===\n";
    int start = std::max(0, static_cast<int>(tx_history.size()) - last_n);
    for (int i = start; i < static_cast<int>(tx_history.size()); ++i)
        std::cout << "  " << tx_history[i].type
        << " | " << tx_history[i].amount_rub << " RUB"
        << " | " << tx_history[i].note << "\n";
}

// ============================================================
//  Система болезней
// ============================================================

enum class illness_severity { none, mild, moderate, severe };

struct illness_type
{
    std::string      name;
    illness_severity severity;
    int   min_days;
    int   max_days;
    RUB   doctor_cost;
    RUB   medicine_min;
    RUB   medicine_max;
    float chance_per_month;
    float food_multiplier;
};

const std::vector<illness_type>& illness_catalog()
{
    static const std::vector<illness_type> v{
        { "Насморк / лёгкое ОРВИ",     illness_severity::mild,       3,  5,        0,    200,    700,   35.0f, 0.70f },
        { "Грипп",                     illness_severity::moderate,   5,  8,      500,  1'500,  3'500,   15.0f, 0.50f },
        { "Ангина",                    illness_severity::moderate,   5,  7,    1'000,  2'000,  4'000,   10.0f, 0.45f },
        { "Отравление",                illness_severity::moderate,   3,  6,      800,    500,  1'500,   12.0f, 0.35f },
        { "Бронхит",                   illness_severity::moderate,   7,  8,    1'500,  2'500,  5'000,    8.0f, 0.50f },
        { "Пневмония",                 illness_severity::severe,     7,  8,    5'000,  8'000, 20'000,    3.0f, 0.30f },
        { "Аллергия",                  illness_severity::mild,       3,  7,      400,    800,  2'000,   10.0f, 0.80f },
        { "Конъюнктивит",              illness_severity::mild,       4,  6,      300,    600,  1'200,    8.0f, 0.90f },
        { "Остеохондроз (обострение)", illness_severity::moderate,   5, 10,    2'000,  3'000,  7'000,    6.0f, 0.60f },
        { "Гастрит (обострение)",      illness_severity::moderate,   4,  7,    1'200,  2'500,  5'500,    7.0f, 0.40f },
        { "Мигрень",                   illness_severity::mild,       1,  3,      500,    300,    900,   12.0f, 0.75f },
        { "Варикоз (обострение)",      illness_severity::mild,       3,  5,    1'500,  1'000,  3'000,    5.0f, 0.85f },
    };
    return v;
}

struct illness_result
{
    bool             sick = false;
    std::string      name;
    illness_severity severity = illness_severity::none;
    int              days = 0;
    RUB              doctor_cost = 0;
    RUB              medicine_cost = 0;
    float            food_multiplier = 1.0f;
    RUB              lost_salary = 0;
    RUB              vacation_savings = 0;
};

illness_result generate_illness(std::mt19937& gen)
{
    illness_result result;
    const auto& catalog = illness_catalog();

    float total_chance = 0.0f;
    for (const auto& ill : catalog) total_chance += ill.chance_per_month;

    std::uniform_real_distribution<float> roll(0.0f, 100.0f);
    if (roll(gen) > std::min(total_chance, 55.0f))
        return result;

    std::vector<int> weights;
    for (const auto& ill : catalog)
        weights.push_back(static_cast<int>(ill.chance_per_month * 100));
    std::discrete_distribution<> dist(weights.begin(), weights.end());
    const illness_type& chosen = catalog[dist(gen)];

    result.sick = true;
    result.name = chosen.name;
    result.severity = chosen.severity;
    result.food_multiplier = chosen.food_multiplier;

    std::uniform_int_distribution<> days_dist(chosen.min_days, chosen.max_days);
    result.days = days_dist(gen);

    bool visits_doctor = (chosen.severity != illness_severity::mild) || (roll(gen) < 60.0f);
    float med_inflation = std::pow(1.10f, static_cast<float>(g_years_lived));
    result.doctor_cost = visits_doctor
        ? static_cast<RUB>(chosen.doctor_cost * med_inflation) : 0;

    std::uniform_int_distribution<> med_dist(
        static_cast<int>(chosen.medicine_min * med_inflation),
        static_cast<int>(chosen.medicine_max * med_inflation));
    result.medicine_cost = static_cast<RUB>(med_dist(gen));

    return result;
}

// ============================================================
//  Система случайных событий с машиной
// ============================================================

struct car_event
{
    std::string name;
    float       chance;
    RUB         repair_min;
    RUB         repair_max;
    bool        needs_tow;
};

const std::vector<car_event>& car_event_catalog()
{
    static const std::vector<car_event> v{
        { "Прокол колеса",                25.0f,     500,    2'500, false },
        { "Разряженный аккумулятор",      15.0f,   2'000,    8'000, false },
        { "Замена тормозных колодок",     10.0f,   3'000,    8'000, false },
        { "Поломка стартера",              5.0f,   5'000,   15'000,  true },
        { "ДТП (незначительное)",          8.0f,  10'000,   50'000,  true },
        { "Кража зеркала/фары",            6.0f,   3'000,   10'000, false },
        { "Скол лобового стекла",          9.0f,   1'500,    8'000, false },
        { "Поломка АКПП/сцепления",        3.0f,  20'000,   80'000,  true },
        { "Утечка масла/антифриза",        7.0f,   2'000,   12'000, false },
        { "Штраф от ГИБДД",               20.0f,     500,    5'000, false },
        { "Царапина на парковке",          12.0f,   2'000,   15'000, false },
        { "Замена амортизаторов",           6.0f,   8'000,   25'000, false },
        { "Неисправность датчика",          8.0f,   1'500,    6'000, false },
        { "Замена катализатора",            3.0f,  15'000,   40'000, false },
        { "Угон авто (частичный ущерб)",    1.0f,  30'000,  100'000,  true },
        { "Замена ремня ГРМ (внеплановая)", 4.0f,   7'000,   20'000,  true },
    };
    return v;
}

struct car_event_result
{
    bool        happened = false;
    std::string name;
    RUB         repair_cost = 0;
    RUB         tow_cost = 0;
    RUB         total_cost = 0;
};

car_event_result generate_car_event(std::mt19937& gen)
{
    car_event_result result;
    const auto& catalog = car_event_catalog();

    std::uniform_real_distribution<float> roll(0.0f, 100.0f);
    if (roll(gen) > 40.0f) return result;

    std::vector<int> weights;
    for (const auto& ev : catalog)
        weights.push_back(static_cast<int>(ev.chance * 100));
    std::discrete_distribution<> dist(weights.begin(), weights.end());
    const car_event& chosen = catalog[dist(gen)];

    result.happened = true;
    result.name = chosen.name;

    float car_inflation = std::pow(1.08f, static_cast<float>(g_years_lived));
    std::uniform_int_distribution<> cost_dist(
        static_cast<int>(chosen.repair_min * car_inflation),
        static_cast<int>(chosen.repair_max * car_inflation));
    result.repair_cost = static_cast<RUB>(cost_dist(gen));

    if (chosen.needs_tow)
    {
        std::uniform_int_distribution<> tow_dist(
            static_cast<int>(3'000 * car_inflation),
            static_cast<int>(7'000 * car_inflation));
        result.tow_cost = static_cast<RUB>(tow_dist(gen));
    }

    result.total_cost = result.repair_cost + result.tow_cost;
    return result;
}

// ============================================================
//  Расходы на бензин
// ============================================================

struct fuel_params
{
    float km_per_day;
    float liters_per_100km;
    float fuel_price_per_liter;
    int   work_days_per_month;
};

RUB calc_monthly_fuel_cost(const fuel_params& fp, int sick_days = 0)
{
    int   active_days = std::max(0, fp.work_days_per_month - sick_days);
    float liters = (fp.km_per_day / 100.0f) * fp.liters_per_100km * active_days;
    liters *= 1.15f;
    float fuel_inflation = std::pow(1.06f, static_cast<float>(g_years_lived));
    return static_cast<RUB>(liters * fp.fuel_price_per_liter * fuel_inflation);
}

// ============================================================
//  Алиса и её имущество
// ============================================================

struct Car
{
    RUB   car_cost;
    RUB   car_cost_initial;
    float fuel_cost_monthly;
    int   horsepower = 150;
    float liters_per_100km = 9.5f;
    float km_per_day = 40.0f;
    float fuel_price = 58.0f;
    int   age_years = 0;

    void depreciate()
    {
        float rate = (age_years < 3) ? 0.15f
            : (age_years < 7) ? 0.10f
            : 0.05f;
        car_cost = static_cast<RUB>(car_cost * (1.0f - rate));
        ++age_years;
    }
};

struct Apartment
{
    std::string name;
    RUB         price;
    RUB         cadastral_value;
    int         area_sqm;
};

const std::vector<Apartment>& apartment_catalog()
{
    static const std::vector<Apartment> v{
        { "Студия в спальном районе",           1'800'000,   1'200'000,  28 },
        { "Однушка на окраине",                 3'200'000,   2'400'000,  38 },
        { "Двушка в хорошем районе",            6'500'000,   5'000'000,  58 },
        { "Трёшка в центре",                   12'000'000,  10'000'000,  85 },
        { "Просторная квартира бизнес-класса", 22'000'000,  18'000'000, 120 },
    };
    return v;
}

RUB apartment_current_price(int catalog_index)
{
    float re_inflation = std::pow(1.09f, static_cast<float>(g_years_lived));
    return static_cast<RUB>(apartment_catalog()[catalog_index].price * re_inflation);
}

struct Alice
{
    short age;
    std::unordered_map<std::string, double> fridge;

    RUB   salary = 0;
    Car   car;
    Bank  sber;

    RUB   invest_portfolio = 0;
    RUB   invest_cost_basis = 0;
    RUB   total_invest_profit = 0;
    RUB   total_invest_loss = 0;

    int total_sick_days = 0;
    RUB total_medical_cost = 0;
    RUB total_lost_salary = 0;

    RUB total_fuel_cost = 0;
    RUB total_transport_tax = 0;
    RUB total_car_repair_cost = 0;
    int total_car_incidents = 0;

    int apartment_level = -1;
    RUB total_property_tax = 0;

    bool is_married = false;
    bool has_first_child = false;
    bool is_grandmother = false;
    bool is_retired = false;
    bool passport_renewed = false;
    bool darwin_prize = false;  // Алиса получила премию Дарвина

    float career_multiplier = 1.0f;
};

struct Alice Alice;

// ============================================================
//  Возрастные события
// ============================================================

enum class age_event_type
{
    marriage, first_child, passport_renewal, became_grandmother, retirement,
};

struct age_event
{
    short          trigger_age;
    age_event_type type;
    std::string    description;
    RUB            cost;
    RUB            income_change;
};

const std::vector<age_event>& age_event_catalog()
{
    static const std::vector<age_event> v{
        { 30, age_event_type::marriage,
          "Алиса вышла замуж! Свадебный банкет, кольца, платье...", 350'000, 15'000 },
        { 32, age_event_type::first_child,
          "Алиса родила первого ребёнка! Роддом, приданое, коляска, кроватка...", 120'000, -8'000 },
        { 45, age_event_type::passport_renewal,
          "Замена паспорта в 45 лет. Госпошлина, фото, МФЦ...", 1'500, 0 },
        { 64, age_event_type::became_grandmother,
          "Алиса стала бабушкой! Подарки, радость...", 25'000, 0 },
        { 65, age_event_type::retirement,
          "Алиса вышла на пенсию! Прощальный корпоратив, торт, цветы от коллег.", 15'000, -30'000 },
    };
    return v;
}

void apply_age_event(const age_event& ev)
{
    RUB inflated_cost = inflate(ev.cost);

    std::cout << "\n╔══════════════════════════════════════════════════╗\n"
                << "║  ЖИЗНЕННОЕ СОБЫТИЕ [возраст " << ev.trigger_age << " лет]              ║\n"
                << "╚══════════════════════════════════════════════════╝\n"
                << "  " << ev.description << "\n";

    switch (ev.type)
    {
    case age_event_type::marriage:
        if (!Alice.is_married)
        {
            Alice.is_married = true;
            g_expense_multiplier = 1.5f;
            RUB actual_cost = std::min(inflated_cost, std::max(0LL, Alice.sber.account_rub));
            Alice.sber.account_rub -= actual_cost;
            Alice.salary += ev.income_change;
            std::cout << "  Расходы на свадьбу:         " << actual_cost << " руб.\n"
                << "  Прибавка от мужа:          +" << ev.income_change << " руб./мес.\n"
                << "  Расходы вырастают в:        x" << g_expense_multiplier << "\n";
        }
        break;

    case age_event_type::first_child:
        if (!Alice.has_first_child)
        {
            Alice.has_first_child = true;
            g_expense_multiplier = 2.0f;
            RUB actual_cost = std::min(inflated_cost, std::max(0LL, Alice.sber.account_rub));
            Alice.sber.account_rub -= actual_cost;
            Alice.salary = std::max(0LL, Alice.salary + ev.income_change);
            std::cout << "  Расходы на рождение:        " << actual_cost << " руб.\n"
                << "  Декрет (изменение дохода): " << ev.income_change << " руб./мес.\n"
                << "  Расходы вырастают в:        x" << g_expense_multiplier << "\n";
        }
        break;

    case age_event_type::passport_renewal:
        if (!Alice.passport_renewed)
        {
            Alice.passport_renewed = true;
            RUB actual_cost = std::min(inflated_cost, std::max(0LL, Alice.sber.account_rub));
            Alice.sber.account_rub -= actual_cost;
            std::cout << "  Расходы: " << actual_cost << " руб. (госпошлина + фото)\n";
        }
        break;

    case age_event_type::became_grandmother:
        if (!Alice.is_grandmother)
        {
            Alice.is_grandmother = true;
            g_expense_multiplier = 1.5f;
            RUB actual_cost = std::min(inflated_cost, std::max(0LL, Alice.sber.account_rub));
            Alice.sber.account_rub -= actual_cost;
            std::cout << "  Подарки внуку/внучке:       " << actual_cost << " руб.\n"
                << "  Расходы снизились до:       x" << g_expense_multiplier << "\n";
        }
        break;

    case age_event_type::retirement:
        if (!Alice.is_retired)
        {
            Alice.is_retired = true;
            RUB actual_cost = std::min(inflated_cost, std::max(0LL, Alice.sber.account_rub));
            Alice.sber.account_rub -= actual_cost;
            Alice.salary = std::max(0LL, Alice.salary + ev.income_change);
            std::cout << "  Корпоратив:                 " << actual_cost << " руб.\n"
                << "  Новый доход (пенсия):       " << Alice.salary << " руб./мес.\n";
        }
        break;
    }

    std::cout << "  Баланс после события: " << Alice.sber.account_rub << " руб.\n\n";
}

void check_age_events(short age)
{
    for (const auto& ev : age_event_catalog())
    {
        if (ev.trigger_age != age) continue;
        bool already_done = false;
        switch (ev.type)
        {
        case age_event_type::marriage:          already_done = Alice.is_married;      break;
        case age_event_type::first_child:       already_done = Alice.has_first_child; break;
        case age_event_type::passport_renewal:  already_done = Alice.passport_renewed; break;
        case age_event_type::became_grandmother:already_done = Alice.is_grandmother;  break;
        case age_event_type::retirement:        already_done = Alice.is_retired;      break;
        }
        if (!already_done) apply_age_event(ev);
    }
}

// ============================================================
//  Карьерный рост Алисы
// ============================================================

void apply_annual_salary_growth(std::mt19937& gen)
{
    if (Alice.is_retired) return;

    int years_worked = Alice.age - 24;
    if (years_worked <= 0) return;

    float experience_growth = (years_worked < 10) ? 0.05f : 0.02f;
    float inflation_compensation = ANNUAL_INFLATION_RATE * 0.80f;
    float total_growth = experience_growth + inflation_compensation;

    std::uniform_int_distribution<> bonus_roll(1, 100);
    int roll = bonus_roll(gen);
    if (roll <= 20) total_growth += 0.10f;
    else if (roll <= 35) total_growth -= 0.03f;
    else if (roll <= 40) total_growth += 0.20f;
    else if (roll == 1)  total_growth += 0.50f;

    if (total_growth < 0.0f) total_growth = 0.0f;

    Alice.salary = static_cast<RUB>(Alice.salary * (1.0f + total_growth));
    Alice.career_multiplier *= (1.0f + total_growth);
}

// ============================================================
//  Система отпуска
// ============================================================

enum class vacation_currency_zone { EUR, USD, RUB };
enum class vacation_style { backpacker, budget, comfort, luxury, elite };

struct vacation_profile
{
    vacation_style style;
    std::string    style_name;
    int   vacation_days;
    float hotel_multiplier;
    float food_multiplier;
    float other_multiplier;
    float flight_multiplier;
    RUB   extras_rub;
    float budget_share;
    RUB   daily_entertainment;
};

vacation_profile get_vacation_style(RUB monthly_salary)
{
    if (monthly_salary < 30'000)
        return { vacation_style::backpacker, "Backpacker",  7, 0.4f, 0.5f, 0.4f, 1.0f,   3'000, 0.08f,   500 };
    if (monthly_salary < 60'000)
        return { vacation_style::budget,     "Budget",     10, 0.7f, 0.8f, 0.7f, 1.0f,   8'000, 0.12f, 1'000 };
    if (monthly_salary < 120'000)
        return { vacation_style::comfort,    "Comfort",    14, 1.0f, 1.2f, 1.3f, 1.0f,  20'000, 0.18f, 2'500 };
    if (monthly_salary < 250'000)
        return { vacation_style::luxury,     "Luxury",     21, 2.5f, 2.0f, 2.5f, 3.0f,  80'000, 0.25f, 6'000 };
    return   { vacation_style::elite,       "Elite",      30, 5.0f, 4.0f, 5.0f, 6.0f, 250'000, 0.35f,15'000 };
}

struct vacation_destination
{
    std::string name;
    float tourist_markup;
    RUB avg_daily_hotel_rub;
    RUB avg_daily_food_rub;
    RUB avg_daily_other_rub;
};

struct vacation_pool
{
    static const std::vector<vacation_destination>& eur_destinations()
    {
        static const std::vector<vacation_destination> v{
            {"Испания (Барселона)",   1.40f, 7'000, 2'500, 2'000},
            {"Италия (Рим)",          1.50f, 8'000, 3'000, 2'500},
            {"Германия (Берлин)",     1.30f, 6'500, 2'200, 1'800},
            {"Франция (Париж)",       1.60f, 9'000, 3'500, 3'000},
            {"Черногория (Будва)",    1.20f, 4'500, 1'800, 1'200},
            {"Венгрия (Будапешт)",    1.15f, 3'500, 1'500, 1'000},
            {"Чехия (Прага)",         1.20f, 4'000, 1'700, 1'100},
            {"Греция (Крит)",         1.30f, 5'500, 2'000, 1'500},
            {"Португалия (Лиссабон)", 1.25f, 5'000, 1'900, 1'400},
            {"Австрия (Вена)",        1.40f, 7'500, 2'800, 2'200},
            {"Хорватия (Дубровник)", 1.35f,  6'000, 2'300, 1'700},
            {"Финляндия (Хельсинки)",1.30f,  6'500, 2'100, 1'600},
        };
        return v;
    }
    static const std::vector<vacation_destination>& usd_destinations()
    {
        static const std::vector<vacation_destination> v{
            {"Таиланд (Бангкок)",   1.20f,  3'500, 1'200, 1'000},
            {"ОАЭ (Дубай)",         1.50f, 12'000, 4'000, 3'500},
            {"Мальдивы",            1.70f, 20'000, 5'000, 4'000},
            {"Вьетнам (Ханой)",     1.15f,  2'500,   900,   700},
            {"Индонезия (Бали)",    1.25f,  4'000, 1'400, 1'100},
            {"Китай (Шанхай)",      1.30f,  5'000, 1'800, 1'500},
            {"Египет (Хургада)",    1.20f,  4'000, 1'300, 1'000},
            {"Куба (Гавана)",       1.35f,  5'500, 1'700, 1'200},
            {"Мексика (Канкун)",    1.30f,  6'000, 2'000, 1'500},
            {"США (Нью-Йорк)",      1.60f, 11'000, 4'500, 4'000},
            {"Шри-Ланка (Коломбо)", 1.15f,  3'000, 1'100,   900},
            {"Марокко (Марракеш)",  1.20f,  3'200, 1'200,   950},
            {"Иордания (Петра)",    1.25f,  4'500, 1'500, 1'200},
        };
        return v;
    }
    static const std::vector<vacation_destination>& rub_destinations()
    {
        static const std::vector<vacation_destination> v{
            {"Абхазия (Сухум)",           1.10f, 2'500,   800, 600},
            {"Абхазия (Гагра)",           1.10f, 2'800,   900, 650},
            {"Южная Осетия (Цхинвали)",   1.05f, 1'800,   600, 400},
            {"Приднестровье (Тирасполь)", 1.08f, 1'500,   550, 350},
            {"Беларусь (Минск)",          1.05f, 3'000, 1'000, 800},
            {"Казахстан (Алма-Ата)",      1.10f, 3'500, 1'100, 900},
            {"Казахстан (Астана)",        1.10f, 3'800, 1'200, 950},
            {"Кыргызстан (Бишкек)",       1.08f, 2'200,   750, 550},
            {"Армения (Ереван)",          1.10f, 3'200, 1'050, 800},
            {"Крым (Ялта)",               1.12f, 3'000,   950, 700},
            {"Краснодарский край (Сочи)", 1.15f, 4'000, 1'200, 850},
            {"Карелия (Петрозаводск)",    1.08f, 2'500,   850, 600},
            {"Байкал (Иркутск)",          1.10f, 2'800,   900, 650},
            {"Алтай (Горно-Алтайск)",     1.10f, 2'600,   870, 620},
        };
        return v;
    }
};

std::pair<RUB, RUB> alice_vacation(std::mt19937& gen, const illness_result& illness)
{
    float vac_inflation = std::pow(1.08f, static_cast<float>(g_years_lived));
    vacation_profile profile = get_vacation_style(Alice.salary);

    std::vector<int> zone_weights;
    switch (profile.style)
    {
    case vacation_style::backpacker: zone_weights = { 30, 30, 40 }; break;
    case vacation_style::budget:     zone_weights = { 35, 35, 30 }; break;
    case vacation_style::comfort:    zone_weights = { 40, 40, 20 }; break;
    case vacation_style::luxury:     zone_weights = { 45, 50,  5 }; break;
    case vacation_style::elite:      zone_weights = { 40, 58,  2 }; break;
    }
    std::discrete_distribution<> zone_dist(zone_weights.begin(), zone_weights.end());
    vacation_currency_zone zone = static_cast<vacation_currency_zone>(zone_dist(gen));

    RUB vacation_budget_rub = static_cast<RUB>(Alice.salary * 12 * profile.budget_share);
    if (vacation_budget_rub > Alice.sber.account_rub)
        vacation_budget_rub = Alice.sber.account_rub / 2;

    switch (zone)
    {
    case vacation_currency_zone::EUR:
        if (Alice.sber.account_rub >= vacation_budget_rub)
            Alice.sber.rub_to_eur(vacation_budget_rub);
        break;
    case vacation_currency_zone::USD:
        if (Alice.sber.account_rub >= vacation_budget_rub)
            Alice.sber.rub_to_usd(vacation_budget_rub);
        break;
    case vacation_currency_zone::RUB:
        break;
    }

    const std::vector<vacation_destination>* dest_pool = nullptr;
    switch (zone)
    {
    case vacation_currency_zone::EUR: dest_pool = &vacation_pool::eur_destinations(); break;
    case vacation_currency_zone::USD: dest_pool = &vacation_pool::usd_destinations(); break;
    case vacation_currency_zone::RUB: dest_pool = &vacation_pool::rub_destinations(); break;
    }

    std::uniform_int_distribution<> dest_dist(0, (int)dest_pool->size() - 1);
    const vacation_destination& dest = (*dest_pool)[dest_dist(gen)];

    RUB base_flight_cost = 0;
    switch (zone)
    {
    case vacation_currency_zone::EUR: base_flight_cost = static_cast<RUB>(35'000 * vac_inflation); break;
    case vacation_currency_zone::USD: base_flight_cost = static_cast<RUB>(55'000 * vac_inflation); break;
    case vacation_currency_zone::RUB: base_flight_cost = static_cast<RUB>(10'000 * vac_inflation); break;
    }

    int days = profile.vacation_days;
    int sick_days = illness.sick ? std::min(illness.days, days) : 0;
    int well_days = days - sick_days;

    RUB flight_cost = static_cast<RUB>(base_flight_cost * dest.tourist_markup * profile.flight_multiplier);
    RUB hotel_cost = static_cast<RUB>(dest.avg_daily_hotel_rub * vac_inflation * days * dest.tourist_markup * profile.hotel_multiplier);
    RUB food_well = static_cast<RUB>(dest.avg_daily_food_rub * vac_inflation * well_days * dest.tourist_markup * profile.food_multiplier);
    RUB other_well = static_cast<RUB>(dest.avg_daily_other_rub * vac_inflation * well_days * dest.tourist_markup * profile.other_multiplier);
    RUB food_sick = static_cast<RUB>(dest.avg_daily_food_rub * vac_inflation * sick_days * dest.tourist_markup * profile.food_multiplier * illness.food_multiplier);
    RUB other_sick = static_cast<RUB>(dest.avg_daily_other_rub * vac_inflation * sick_days * dest.tourist_markup * profile.other_multiplier * 0.15f);
    RUB extras = static_cast<RUB>(profile.extras_rub * vac_inflation);
    RUB total_cost_rub = flight_cost + hotel_cost + food_well + food_sick + other_well + other_sick + extras;

    RUB other_full = static_cast<RUB>(dest.avg_daily_other_rub * vac_inflation * days * dest.tourist_markup * profile.other_multiplier);
    RUB food_full = static_cast<RUB>(dest.avg_daily_food_rub * vac_inflation * days * dest.tourist_markup * profile.food_multiplier);
    RUB saved = (other_full - other_well - other_sick) + (food_full - food_well - food_sick);
    if (saved < 0) saved = 0;

    switch (zone)
    {
    case vacation_currency_zone::EUR:
    {
        EUR cost_eur = static_cast<EUR>(std::ceil(total_cost_rub / Alice.sber.euro_rate()));
        EUR eur_before = Alice.sber.account_eur;
        if (Alice.sber.account_eur < cost_eur)
        {
            EUR need = cost_eur - Alice.sber.account_eur;
            RUB need_rub = static_cast<RUB>(need * Alice.sber.euro_rate()) + 1;
            if (Alice.sber.account_rub >= need_rub) Alice.sber.rub_to_eur(need_rub);
            else { cost_eur = Alice.sber.account_eur; total_cost_rub = static_cast<RUB>(cost_eur * Alice.sber.euro_rate()); }
        }
        Alice.sber.account_eur -= cost_eur;
        EUR leftover = Alice.sber.account_eur - eur_before;
        if (leftover > 0) Alice.sber.eur_to_rub(leftover);
        break;
    }
    case vacation_currency_zone::USD:
    {
        USD cost_usd = static_cast<USD>(std::ceil(total_cost_rub / Alice.sber.dollar_rate()));
        USD usd_before = Alice.sber.account_usd;
        if (Alice.sber.account_usd < cost_usd)
        {
            USD need = cost_usd - Alice.sber.account_usd;
            RUB need_rub = static_cast<RUB>(need * Alice.sber.dollar_rate()) + 1;
            if (Alice.sber.account_rub >= need_rub) Alice.sber.rub_to_usd(need_rub);
            else { cost_usd = Alice.sber.account_usd; total_cost_rub = static_cast<RUB>(cost_usd * Alice.sber.dollar_rate()); }
        }
        Alice.sber.account_usd -= cost_usd;
        USD leftover = Alice.sber.account_usd - usd_before;
        if (leftover > 0) Alice.sber.usd_to_rub(leftover);
        break;
    }
    case vacation_currency_zone::RUB:
        if (Alice.sber.account_rub < total_cost_rub) total_cost_rub = Alice.sber.account_rub;
        Alice.sber.account_rub -= total_cost_rub;
        break;
    }

    return { total_cost_rub, saved };
}

// ============================================================
//  Продуктовая система
// ============================================================

struct Ingredient { std::string name; double amount; };
struct Recipe { std::string name; std::vector<Ingredient> ingredients; };
struct shop_product { std::string name; double price_per_pack; double pack_size; };
struct purchased_item { std::string name; int packs_bought; double total_amount; double total_price; };
struct shop_result { std::vector<purchased_item> items; double total_spent = 0; };

enum class income_level { low, medium, high, rich };
enum class budget_mode { normal, no_snacks, cheap };

income_level get_income_level(double salary)
{
    if (salary < 30'000)  return income_level::low;
    if (salary < 250'000)  return income_level::medium;
    if (salary < 500'000) return income_level::high;
    return income_level::rich;
}

budget_mode get_budget_mode(double spent_so_far, double budget, int days_left, int total_days)
{
    int days_done = total_days - days_left;
    if (days_done == 0) return budget_mode::normal;
    double projected = (spent_so_far / days_done) * total_days;
    if (projected <= budget)       return budget_mode::normal;
    if (projected <= budget * 1.2) return budget_mode::no_snacks;
    return budget_mode::cheap;
}

struct price_catalog
{
    static const std::vector<shop_product>& get(income_level level)
    {
        float inf = inflation_factor();
        static std::vector<shop_product> low, medium, high, rich;

        low = {
            {"овсянка",40. * inf,500.},{"гречка",60. * inf,900.},{"рис",50. * inf,900.},
            {"манка",35. * inf,700.},{"молоко",60. * inf,1000.},{"яйца",70. * inf,10.},
            {"хлеб",35. * inf,500.},{"масло",90. * inf,200.},{"сыр",130. * inf,300.},
            {"колбаса",150. * inf,300.},{"курица",200. * inf,1000.},{"говядина",350. * inf,1000.},
            {"картошка",40. * inf,1000.},{"макароны",50. * inf,400.},{"помидоры",60. * inf,500.},
            {"огурцы",50. * inf,500.},{"капуста",30. * inf,1000.},{"морковь",35. * inf,500.},
            {"сметана",45. * inf,400.},{"борщ (набор)",120. * inf,1.},{"чай",60. * inf,100.},
            {"кофе",150. * inf,200.},{"сок",60. * inf,1000.},{"вода",25. * inf,500.},
            {"печенье",70. * inf,400.},{"шоколад",80. * inf,100.},{"чипсы",70. * inf,150.},
            {"орехи",120. * inf,150.},{"йогурт",40. * inf,300.},{"банан",20. * inf,1.},
            {"яблоко",15. * inf,1.},{"творог",70. * inf,200.},{"сосиски",120. * inf,400.},
            {"лапша",180. * inf,1.},{"перловка",35. * inf,800.},{"пшено",40. * inf,700.},
            {"кефир",50. * inf,900.},{"ряженка",55. * inf,500.},{"сухари",30. * inf,300.},
            {"пряники",60. * inf,400.},{"свёкла",25. * inf,500.},{"лук",20. * inf,500.},
            {"чеснок",30. * inf,100.},{"перец болгарский",80. * inf,300.},
        };
        medium = {
            {"овсянка",60. * inf,500.},{"гречка",90. * inf,900.},{"рис",80. * inf,900.},
            {"манка",55. * inf,700.},{"молоко",80. * inf,1000.},{"яйца",90. * inf,10.},
            {"хлеб",50. * inf,500.},{"масло",150. * inf,200.},{"сыр",200. * inf,300.},
            {"колбаса",250. * inf,300.},{"курица",300. * inf,1000.},{"говядина",500. * inf,1000.},
            {"картошка",60. * inf,1000.},{"макароны",70. * inf,400.},{"помидоры",90. * inf,500.},
            {"огурцы",70. * inf,500.},{"капуста",40. * inf,1000.},{"морковь",50. * inf,500.},
            {"сметана",60. * inf,400.},{"борщ (набор)",200. * inf,1.},{"чай",100. * inf,100.},
            {"кофе",300. * inf,200.},{"сок",90. * inf,1000.},{"вода",40. * inf,500.},
            {"печенье",120. * inf,400.},{"шоколад",150. * inf,100.},{"чипсы",100. * inf,150.},
            {"орехи",200. * inf,150.},{"йогурт",60. * inf,300.},{"банан",30. * inf,1.},
            {"яблоко",25. * inf,1.},{"творог",100. * inf,200.},{"сосиски",180. * inf,400.},
            {"лапша",250. * inf,1.},{"перловка",55. * inf,800.},{"пшено",60. * inf,700.},
            {"кефир",75. * inf,900.},{"ряженка",80. * inf,500.},{"сухари",50. * inf,300.},
            {"пряники",90. * inf,400.},{"свёкла",40. * inf,500.},{"лук",30. * inf,500.},
            {"чеснок",45. * inf,100.},{"перец болгарский",110. * inf,300.},
        };
        high = {
            {"овсянка",100. * inf,500.},{"гречка",150. * inf,900.},{"рис",130. * inf,900.},
            {"манка",90. * inf,700.},{"молоко",130. * inf,1000.},{"яйца",150. * inf,10.},
            {"хлеб",120. * inf,500.},{"масло",280. * inf,200.},{"сыр",450. * inf,300.},
            {"колбаса",500. * inf,300.},{"курица",550. * inf,1000.},{"говядина",900. * inf,1000.},
            {"картошка",100. * inf,1000.},{"макароны",150. * inf,400.},{"помидоры",200. * inf,500.},
            {"огурцы",180. * inf,500.},{"капуста",80. * inf,1000.},{"морковь",100. * inf,500.},
            {"сметана",130. * inf,400.},{"борщ (набор)",400. * inf,1.},{"чай",300. * inf,100.},
            {"кофе",800. * inf,200.},{"сок",200. * inf,1000.},{"вода",100. * inf,500.},
            {"печенье",300. * inf,400.},{"шоколад",400. * inf,100.},{"чипсы",200. * inf,150.},
            {"орехи",400. * inf,150.},{"йогурт",150. * inf,300.},{"банан",60. * inf,1.},
            {"яблоко",70. * inf,1.},{"творог",200. * inf,200.},{"сосиски",400. * inf,400.},
            {"лапша",400. * inf,1.},{"перловка",90. * inf,800.},{"пшено",100. * inf,700.},
            {"кефир",120. * inf,900.},{"ряженка",140. * inf,500.},{"сухари",80. * inf,300.},
            {"пряники",180. * inf,400.},{"свёкла",70. * inf,500.},{"лук",55. * inf,500.},
            {"чеснок",75. * inf,100.},{"перец болгарский",200. * inf,300.},
        };
        rich = {
            {"овсянка",150. * inf,500.},{"гречка",225. * inf,900.},{"рис",195. * inf,900.},
            {"манка",135. * inf,700.},{"молоко",195. * inf,1000.},{"яйца",225. * inf,10.},
            {"хлеб",180. * inf,500.},{"масло",420. * inf,200.},{"сыр",675. * inf,300.},
            {"колбаса",750. * inf,300.},{"курица",825. * inf,1000.},{"говядина",1350. * inf,1000.},
            {"картошка",150. * inf,1000.},{"макароны",225. * inf,400.},{"помидоры",300. * inf,500.},
            {"огурцы",270. * inf,500.},{"капуста",120. * inf,1000.},{"морковь",150. * inf,500.},
            {"сметана",195. * inf,400.},{"борщ (набор)",600. * inf,1.},{"чай",450. * inf,100.},
            {"кофе",1200. * inf,200.},{"сок",300. * inf,1000.},{"вода",150. * inf,500.},
            {"печенье",450. * inf,400.},{"шоколад",600. * inf,100.},{"чипсы",300. * inf,150.},
            {"орехи",600. * inf,150.},{"йогурт",225. * inf,300.},{"банан",90. * inf,1.},
            {"яблоко",105. * inf,1.},{"творог",300. * inf,200.},{"сосиски",600. * inf,400.},
            {"лапша",600. * inf,1.},{"перловка",135. * inf,800.},{"пшено",150. * inf,700.},
            {"кефир",180. * inf,900.},{"ряженка",210. * inf,500.},{"сухари",120. * inf,300.},
            {"пряники",270. * inf,400.},{"свёкла",105. * inf,500.},{"лук",82. * inf,500.},
            {"чеснок",112. * inf,100.},{"перец болгарский",300. * inf,300.},
        };

        switch (level)
        {
        case income_level::low:    return low;
        case income_level::medium: return medium;
        case income_level::high:   return high;
        case income_level::rich:   return rich;
        }
        return low;
    }
};

shop_result shop(const std::vector<std::pair<std::string, double>>& shopping_list, income_level level)
{
    const auto& products = price_catalog::get(level);
    std::unordered_map<std::string, const shop_product*> product_map;
    for (const auto& p : products) product_map[p.name] = &p;
    shop_result result;
    for (const auto& [name, needed] : shopping_list)
    {
        auto it = product_map.find(name);
        if (it == product_map.end()) continue;
        const shop_product& product = *it->second;
        int    packs = (int)std::ceil(needed / product.pack_size);
        double amt = packs * product.pack_size;
        double cost = packs * product.price_per_pack;
        result.items.push_back({ name, packs, amt, cost });
        result.total_spent += cost;
    }
    return result;
}

bool has_holiday(int month, int day)
{
    if (month == 1 && day == 1)  return true;
    if (month == 2 && day == 23) return true;
    if (month == 3 && day == 8)  return true;
    if (month == 5 && day == 9)  return true;
    if (month == 12 && day == 31) return true;
    return false;
}

int days_in_month(int month)
{
    constexpr int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month < 1 || month > 12) return 30;
    return days[month];
}

double buy_if_needed(std::unordered_map<std::string, double>& fridge,
    const Ingredient& ing, income_level level)
{
    double have = fridge[ing.name];
    if (have >= ing.amount) return 0.0;
    shop_result res = shop({ { ing.name, ing.amount - have } }, level);
    for (const auto& item : res.items) fridge[item.name] += item.total_amount;
    return res.total_spent;
}

double cook_meal(std::unordered_map<std::string, double>& fridge,
    const Recipe& meal, income_level level)
{
    double spent = 0.0;
    for (const auto& ing : meal.ingredients)
    {
        spent += buy_if_needed(fridge, ing, level);
        fridge[ing.name] -= ing.amount;
    }
    return spent;
}

// ============================================================
//  Книга рецептов
// ============================================================

struct recipe_book
{
    static const std::vector<Recipe>& porridges()
    {
        static const std::vector<Recipe> v{
            {"Овсянка на молоке",    {{"овсянка",80.},{"молоко",200.}}},
            {"Гречка с маслом",      {{"гречка",80.},{"масло",10.}}},
            {"Рисовая каша",         {{"рис",80.},{"молоко",200.}}},
            {"Манная каша",          {{"манка",60.},{"молоко",200.}}},
            {"Перловая каша",        {{"перловка",80.},{"масло",10.}}},
            {"Пшённая каша",         {{"пшено",70.},{"молоко",200.}}},
            {"Рисовая каша с маслом",{{"рис",80.},{"масло",10.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& light_breakfast()
    {
        static const std::vector<Recipe> v{
            {"Бутерброд с сыром",     {{"хлеб",80.},{"сыр",30.},{"масло",5.}}},
            {"Бутерброд с колбасой",  {{"хлеб",80.},{"колбаса",40.}}},
            {"Яичница глазунья",      {{"яйца",2.},{"масло",10.}}},
            {"Творог со сметаной",    {{"творог",150.},{"сметана",30.}}},
            {"Йогурт с бананом",      {{"йогурт",200.},{"банан",1.}}},
            {"Яйцо варёное с хлебом", {{"яйца",2.},{"хлеб",60.},{"масло",5.}}},
            {"Омлет",                 {{"яйца",3.},{"молоко",60.},{"масло",8.}}},
            {"Ряженка с сухарями",    {{"ряженка",300.},{"сухари",50.}}},
            {"Кефир с хлебом",        {{"кефир",250.},{"хлеб",60.}}},
            {"Бутерброд с сосисками", {{"хлеб",80.},{"сосиски",60.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& breakfast_drinks()
    {
        static const std::vector<Recipe> v{
            {"Чай",{{"чай",5.}}},{"Кофе",{{"кофе",10.}}},
            {"Сок",{{"сок",200.}}},{"Кефир",{{"кефир",250.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& first_course()
    {
        static const std::vector<Recipe> v{
            {"Борщ",           {{"борщ (набор)",1.},{"сметана",50.}}},
            {"Куриный суп",    {{"курица",300.},{"картошка",150.},{"морковь",50.}}},
            {"Гречневый суп",  {{"гречка",80.},{"морковь",50.},{"картошка",100.}}},
            {"Щи",             {{"капуста",200.},{"картошка",100.},{"морковь",40.},{"сметана",30.}}},
            {"Рассольник",     {{"рис",50.},{"картошка",150.},{"морковь",50.}}},
            {"Суп с перловкой",{{"перловка",60.},{"картошка",120.},{"морковь",40.}}},
            {"Лапша куриная",  {{"макароны",80.},{"курица",200.},{"морковь",30.}}},
            {"Гороховый суп",  {{"картошка",150.},{"морковь",50.},{"лук",30.}}},
            {"Суп из говядины",{{"говядина",200.},{"картошка",150.},{"морковь",50.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& second_course()
    {
        static const std::vector<Recipe> v{
            {"Курица с картошкой",   {{"курица",300.},{"картошка",250.}}},
            {"Макароны с сыром",     {{"макароны",200.},{"сыр",50.},{"масло",15.}}},
            {"Гречка с говядиной",   {{"гречка",150.},{"говядина",250.}}},
            {"Рис с курицей",        {{"рис",150.},{"курица",250.}}},
            {"Картошка с сосисками", {{"картошка",250.},{"сосиски",150.}}},
            {"Перловка с мясом",     {{"перловка",150.},{"говядина",200.}}},
            {"Макароны с говядиной", {{"макароны",200.},{"говядина",200.},{"масло",10.}}},
            {"Рис с сосисками",      {{"рис",150.},{"сосиски",120.}}},
            {"Пюре с котлетой",      {{"картошка",300.},{"говядина",150.},{"масло",20.}}},
            {"Гречка с курицей",     {{"гречка",150.},{"курица",200.}}},
            {"Тушёная капуста",      {{"капуста",300.},{"морковь",80.},{"масло",15.}}},
            {"Пшено с тыквой",       {{"пшено",120.},{"морковь",60.},{"масло",10.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& salads()
    {
        static const std::vector<Recipe> v{
            {"Салат овощной",   {{"помидоры",150.},{"огурцы",150.},{"сметана",30.}}},
            {"Салат капустный", {{"капуста",200.},{"морковь",80.},{"сметана",30.}}},
            {"Помидоры свежие", {{"помидоры",200.}}},
            {"Огурцы свежие",   {{"огурцы",200.}}},
            {"Тёртая морковь",  {{"морковь",150.},{"сметана",20.}}},
            {"Свёкла варёная",  {{"свёкла",150.},{"масло",10.}}},
            {"Нарезка овощная", {{"помидоры",100.},{"огурцы",100.},{"перец болгарский",50.}}},
            {"Салат с яйцом",   {{"яйца",2.},{"огурцы",100.},{"сметана",30.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& lunch_drinks()
    {
        static const std::vector<Recipe> v{
            {"Чай",{{"чай",5.}}},{"Сок",{{"сок",300.}}},
            {"Вода",{{"вода",500.}}},{"Кефир",{{"кефир",200.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& light_dinner()
    {
        static const std::vector<Recipe> v{
            {"Бутерброд с колбасой", {{"хлеб",80.},{"колбаса",40.}}},
            {"Яичница вечерняя",     {{"яйца",2.},{"масло",10.}}},
            {"Творог со сметаной",   {{"творог",150.},{"сметана",30.}}},
            {"Йогурт натуральный",   {{"йогурт",200.}}},
            {"Каша гречневая",       {{"гречка",80.},{"масло",10.}}},
            {"Бутерброд с сыром",    {{"хлеб",80.},{"сыр",30.}}},
            {"Кефир с хлебом",       {{"кефир",250.},{"хлеб",50.}}},
            {"Ряженка",              {{"ряженка",300.}}},
            {"Рисовая каша вечер",   {{"рис",80.},{"молоко",150.},{"масло",8.}}},
            {"Перловка с маслом",    {{"перловка",80.},{"масло",10.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& dinner_drinks()
    {
        static const std::vector<Recipe> v{
            {"Чай вечерний",{{"чай",5.}}},{"Кофе вечерний",{{"кофе",10.}}},
            {"Вода ночная",{{"вода",300.}}},{"Кефир вечером",{{"кефир",250.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& holiday_lunches()
    {
        static const std::vector<Recipe> v{
            {"Праздничная курица",{{"курица",800.},{"картошка",500.},{"сметана",100.}}},
            {"Плов праздничный",  {{"рис",300.},{"говядина",600.},{"морковь",150.},{"масло",50.}}},
            {"Запечённая курица", {{"курица",1000.},{"картошка",400.},{"сметана",80.}}},
            {"Говядина тушёная",  {{"говядина",700.},{"картошка",300.},{"морковь",100.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& snacks()
    {
        static const std::vector<Recipe> v{
            {"Печенье",{{"печенье",50.}}},{"Шоколад",{{"шоколад",25.}}},
            {"Чипсы",{{"чипсы",40.}}},{"Орехи",{{"орехи",30.}}},
            {"Банан",{{"банан",1.}}},{"Яблоко",{{"яблоко",1.}}},
            {"Лапша",{{"лапша",1.}}},{"Пряники",{{"пряники",60.}}},
            {"Йогурт",{{"йогурт",150.}}},{"Ряженка",{{"ряженка",200.}}},
            {"Сухари ржаные",{{"сухари",40.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& day_drinks()
    {
        static const std::vector<Recipe> v{
            {"Чай дневной",{{"чай",5.}}},{"Кофе дневной",{{"кофе",10.}}},
            {"Сок дневной",{{"сок",200.}}},{"Вода дневная",{{"вода",500.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_porridges()
    {
        static const std::vector<Recipe> v{
            {"Овсянка на воде", {{"овсянка",80.},{"вода",200.}}},
            {"Гречка на воде",  {{"гречка",80.}}},
            {"Перловка на воде",{{"перловка",80.},{"вода",200.}}},
            {"Пшённая на воде", {{"пшено",70.},{"вода",200.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_light()
    {
        static const std::vector<Recipe> v{
            {"Хлеб с маслом",{{"хлеб",80.},{"масло",5.}}},
            {"Яйцо варёное", {{"яйца",2.}}},
            {"Хлеб с кефиром",{{"хлеб",60.},{"кефир",200.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_drinks()
    {
        static const std::vector<Recipe> v{
            {"Чай эконом",{{"чай",5.}}},{"Вода эконом",{{"вода",300.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_first()
    {
        static const std::vector<Recipe> v{
            {"Картофельный суп",{{"картошка",200.},{"морковь",50.},{"лук",20.}}},
            {"Гречневый суп",   {{"гречка",80.},{"морковь",50.},{"лук",20.}}},
            {"Перловый суп",    {{"перловка",60.},{"картошка",150.},{"морковь",40.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_second()
    {
        static const std::vector<Recipe> v{
            {"Гречка с маслом",  {{"гречка",150.},{"масло",10.}}},
            {"Макароны с маслом",{{"макароны",200.},{"масло",10.}}},
            {"Рис с маслом",     {{"рис",150.},{"масло",10.}}},
            {"Перловка с луком", {{"перловка",150.},{"лук",30.},{"масло",8.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& cheap_dinner()
    {
        static const std::vector<Recipe> v{
            {"Хлеб с маслом",{{"хлеб",80.},{"масло",5.}}},
            {"Каша на воде", {{"гречка",80.}}},
            {"Яйцо варёное", {{"яйца",2.}}},
            {"Кефир",        {{"кефир",250.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& sick_breakfast()
    {
        static const std::vector<Recipe> v{
            {"Жидкая овсянка на воде",{{"овсянка",50.},{"вода",300.}}},
            {"Рисовый отвар",         {{"рис",40.},{"вода",400.}}},
            {"Сухарик с чаем",        {{"хлеб",30.},{"чай",5.}}},
            {"Жидкая манка",          {{"манка",40.},{"вода",300.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& sick_main()
    {
        static const std::vector<Recipe> v{
            {"Куриный бульон",    {{"курица",100.},{"морковь",20.},{"вода",500.}}},
            {"Картофельный суп",  {{"картошка",100.},{"морковь",20.},{"вода",400.}}},
            {"Гречка на воде",    {{"гречка",60.}}},
            {"Рис отварной",      {{"рис",60.},{"вода",200.}}},
            {"Куриный суп лёгкий",{{"курица",80.},{"рис",30.},{"вода",500.}}},
        };
        return v;
    }
    static const std::vector<Recipe>& sick_drinks()
    {
        static const std::vector<Recipe> v{
            {"Стакан воды", {{"вода",300.}}},
            {"Тёплый чай",  {{"чай",5.},{"вода",300.}}},
            {"Чай с соком", {{"чай",5.},{"сок",50.},{"вода",200.}}},
            {"Тёплое молоко",{{"молоко",250.}}},
        };
        return v;
    }
};

double simulate_day(std::unordered_map<std::string, double>& fridge,
    income_level level, budget_mode mode,
    bool is_holiday_day, bool is_sick, std::mt19937& gen)
{
    auto pick = [&](const std::vector<Recipe>& v) -> const Recipe& {
        std::uniform_int_distribution<> d(0, (int)v.size() - 1);
        return v[d(gen)];
        };
    auto chance = [&](int pct) -> bool {
        std::uniform_int_distribution<> d(1, 100);
        return d(gen) <= pct;
        };

    double spent = 0.0;
    if (is_sick)
    {
        spent += cook_meal(fridge, pick(recipe_book::sick_breakfast()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_drinks()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_main()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_drinks()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_main()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_drinks()), level);
        spent += cook_meal(fridge, pick(recipe_book::sick_drinks()), level);
    }
    else
    {
        const bool cheap = (mode == budget_mode::cheap);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_porridges() : recipe_book::porridges()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_light() : recipe_book::light_breakfast()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_drinks() : recipe_book::breakfast_drinks()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_first() : recipe_book::first_course()), level);
        spent += cook_meal(fridge,
            (is_holiday_day && !cheap) ? pick(recipe_book::holiday_lunches())
            : pick(cheap ? recipe_book::cheap_second() : recipe_book::second_course()), level);
        if (!cheap) spent += cook_meal(fridge, pick(recipe_book::salads()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_drinks() : recipe_book::lunch_drinks()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_dinner() : recipe_book::light_dinner()), level);
        spent += cook_meal(fridge, pick(cheap ? recipe_book::cheap_drinks() : recipe_book::dinner_drinks()), level);
        if (mode == budget_mode::normal)
        {
            if (chance(70)) spent += cook_meal(fridge, pick(recipe_book::snacks()), level);
            if (chance(80)) spent += cook_meal(fridge, pick(recipe_book::day_drinks()), level);
        }
    }
    return spent;
}

RUB calc_food_cost(int month, int sick_days)
{
    std::mt19937 gen(std::random_device{}());
    income_level level = get_income_level(static_cast<double>(Alice.salary));
    double budget = Alice.salary * 0.30;
    double total_spent = 0.0;
    int    total_days = days_in_month(month);

    for (int day = 1; day <= total_days; ++day)
    {
        bool is_sick_today = (day <= sick_days);
        budget_mode mode = is_sick_today
            ? budget_mode::normal
            : get_budget_mode(total_spent, budget, total_days - day, total_days);
        total_spent += simulate_day(Alice.fridge, level, mode,
            has_holiday(month, day), is_sick_today, gen);
    }
    return static_cast<RUB>(total_spent * g_expense_multiplier);
}

// ============================================================
//  Случайные события месяца
// ============================================================

struct Event { std::string name_event; float chance; int income; bool used = false; };
struct month_result { std::vector<std::string> events; int total_income = 0; bool darwin_triggered = false; };

struct event_pool
{
    std::vector<Event> positive{
        {"Нашёл потерянный кошелёк",       2000,    750},
        {"Выполнил сложное задание",        3000,  5'000},
        {"Перевыполнил план продаж",        4000,  7'000},
        {"Выиграл в лотерею",           5,1'000'000},
        {"Сдал бутылки",                    7000,    200},
        {"Сдал макулатуру",                 7000,    500},
        {"Получил бонусные баллы магазина", 5000,  1'500},
        {"Нашёл мелочь в диване",           2000,    100},
        {"Нашёл 100 рублей на улице",       1200,    100},
        {"Нашёл 500 рублей на улице",        700,    500},
        {"Нашёл 1000 рублей на улице",       500,  1'000},
        {"Получил кэшбэк от банка",         4500,  2'000},
        {"Продал ненужные вещи",            2500,  3'500},
        {"Получил премию за стаж",          1500,  8'000},
        {"Сосед вернул долг",               1000,  4'000},
        {"Удачно перепродал акции",          800,  6'000},
        {"Выиграл в конкурсе",              1200,  2'500},
        {"Возврат налогового вычета",        500, 15'000},
        {"Бабушка дала деньги на день рожд",1800,  5'000},
        {"Нашёл ошибку в чеке в свою пользу",600, 1'200},
    };
    std::vector<Event> negative{
        {"Пропала мелочь из кошелька",      2000,   -100},
        {"Задержка транспорта, взял такси", 3000,   -400},
        {"Потерял вещь",                    1000,   -700},
        {"Случайная ссора — штраф",         1500,   -200},
        {"Сломался зонт",                   2000,   -500},
        {"Вы получили премию Дравина, из-за того, что задохнулись от вдоха", 4, -1},
        {"Штраф за просрочку платежа",      1200, -1'500},
        {"Испортился телефон — ремонт",      800, -3'000},
        {"Сломался бытовой прибор",          600, -4'500},
        {"Штраф от ИФНС",                    400, -2'000},
        {"Незапланированный подарок",        1800,-2'500},
        {"Разбил стекло/посуду",            1500,   -800},
        {"Испортились продукты — выброс",   2200,   -600},
        {"Лопнула труба — сантехник",        400, -6'000},
        {"Упала антенна — вызов мастера",    500, -1'800},
    };
    std::vector<Event> one_time_positive{
        {"Выиграл крупный приз",                5,  5'000, false},
        {"Получил неожиданную премию",          3,  3'000, false},
        {"Наследство от дальнего родственника", 1, 50'000, false},
        {"Выиграл грант на обучение",           2, 20'000, false},
    };
    std::vector<Event> one_time_negative{
        {"Серьёзная поломка техники",       4,  -4'000, false},
        {"Потерял важный документ",         3,  -1'500, false},
        {"Мошенничество — украли деньги",   2, -10'000, false},
        {"Затопил соседей снизу",           1, -25'000, false},
    };
};

bool pick_one_time(std::vector<Event>& pool, month_result& result, std::mt19937& gen)
{
    std::vector<int> weights, indices;
    for (int i = 0; i < (int)pool.size(); ++i)
        if (!pool[i].used) { weights.push_back((int)pool[i].chance); indices.push_back(i); }
    if (weights.empty()) return false;
    std::discrete_distribution<> dist(weights.begin(), weights.end());
    int idx = indices[dist(gen)];
    pool[idx].used = true;
    result.events.push_back(pool[idx].name_event);
    result.total_income += pool[idx].income;
    return true;
}

month_result generate_monthly_events()
{
    static std::random_device rd;
    static std::mt19937       gen(rd());
    static event_pool         pool;

    std::uniform_int_distribution<>  total_dist(6, 15);
    std::uniform_real_distribution<> mood_dist(0.3, 0.7);
    std::bernoulli_distribution      type_dist(mood_dist(gen));
    std::bernoulli_distribution      ultra_rare(0.02);

    int total_events = total_dist(gen);
    auto make_weights = [](const std::vector<Event>& v) {
        std::vector<int> w;
        for (const auto& e : v) w.push_back((int)e.chance);
        return w;
        };
    auto pos_w = make_weights(pool.positive);
    auto neg_w = make_weights(pool.negative);
    std::discrete_distribution<> pos_dist(pos_w.begin(), pos_w.end());
    std::discrete_distribution<> neg_dist(neg_w.begin(), neg_w.end());

    month_result result;
    result.events.reserve(total_events);
    for (int i = 0; i < total_events; ++i)
    {
        bool is_positive = type_dist(gen);
        if (ultra_rare(gen))
        {
            bool fired = is_positive
                ? pick_one_time(pool.one_time_positive, result, gen)
                : pick_one_time(pool.one_time_negative, result, gen);
            if (fired) continue;
        }
        if (is_positive)
        {
            int idx = pos_dist(gen);
            result.events.push_back(pool.positive[idx].name_event);
            result.total_income += pool.positive[idx].income;
        }
        else
        {
            int idx = neg_dist(gen);
            result.events.push_back(pool.negative[idx].name_event);
            result.total_income += pool.negative[idx].income;
            if (pool.negative[idx].name_event.find("Дравина") != std::string::npos)
                result.darwin_triggered = true;
        }
    }
    std::shuffle(result.events.begin(), result.events.end(), gen);
    return result;
}

// ============================================================
//  Вспомогательные функции отдельных расходов
// ============================================================

void process_car_service(int month)
{
    float car_parts_inflation = std::pow(1.08f, static_cast<float>(g_years_lived));

    std::map<std::string, RUB> parts_costs{
        {"filter_oil",    static_cast<RUB>(1'000 * car_parts_inflation)},
        {"filter_air",    static_cast<RUB>(750 * car_parts_inflation)},
        {"filter_fuel",   static_cast<RUB>(10'000 * car_parts_inflation)},
        {"filter_cabin",  static_cast<RUB>(5'600 * car_parts_inflation)},
        {"antifreeze",    static_cast<RUB>(2'400 * car_parts_inflation)},
        {"break_fluid",   static_cast<RUB>(9'000 * car_parts_inflation)},
        {"motor_oil",     static_cast<RUB>(5'000 * car_parts_inflation)},
        {"spark_plugs",   static_cast<RUB>(10'000 * car_parts_inflation)},
    };

    RUB cost = 0;
    if (month == 7)
        for (const auto& [part, price] : parts_costs) cost += price;
    cost += static_cast<RUB>(500 * car_parts_inflation);

    RUB actual = std::min(cost, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual;
}

void process_holiday_expenses(int month)
{
    struct HolidayEntry { int month; RUB base_cost; };
    static const HolidayEntry holiday_list[] = {
        { 1,  40'000 },
        { 2,  20'000 },
        { 3,  20'000 },
        { 12, 50'000 },
    };

    for (const auto& h : holiday_list)
    {
        if (h.month != month) continue;
        RUB cost = static_cast<RUB>(inflate(h.base_cost) * g_expense_multiplier);
        RUB actual = std::min(cost, std::max(0LL, Alice.sber.account_rub));
        Alice.sber.account_rub -= actual;
    }
}

RUB process_salary(illness_result& illness)
{
    int unpaid_days = 0;
    if (illness.sick)
    {
        switch (illness.severity)
        {
        case illness_severity::mild:
            unpaid_days = std::min(illness.days, 2); break;
        case illness_severity::moderate:
        case illness_severity::severe:
            unpaid_days = illness.days; break;
        default: break;
        }
    }
    RUB daily_rate = Alice.salary / 22;
    illness.lost_salary = daily_rate * std::min(unpaid_days, 22);
    Alice.sber.receive_salary(Alice.salary, unpaid_days);
    return illness.lost_salary;
}

void process_fuel(const illness_result& illness)
{
    float km = Alice.is_retired
        ? Alice.car.km_per_day * 0.25f
        : Alice.car.km_per_day;

    int sick_days = (!Alice.is_retired && illness.sick)
        ? std::min(illness.days, 22) : 0;

    fuel_params fp{ km, Alice.car.liters_per_100km, Alice.car.fuel_price, 22 };
    RUB fuel_cost = calc_monthly_fuel_cost(fp, sick_days);
    Alice.sber.account_rub -= fuel_cost;
    Alice.total_fuel_cost += fuel_cost;
}

void process_medicine(const illness_result& illness)
{
    if (!illness.sick) return;
    RUB medical_total = illness.doctor_cost + illness.medicine_cost;
    RUB actual_payment = std::min(medical_total, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual_payment;
    Alice.total_sick_days += illness.days;
    Alice.total_medical_cost += actual_payment;
    Alice.total_lost_salary += illness.lost_salary;
}

void process_investments(std::mt19937& gen)
{
    const RUB low_balance_threshold = Alice.salary * 2;

    bool hard_period = (Alice.sber.account_rub < low_balance_threshold)
        && (Alice.invest_portfolio > 0);
    if (hard_period)
    {
        RUB gross_profit = Alice.invest_portfolio - Alice.invest_cost_basis;
        RUB tax = gross_profit > 0
            ? taxes_state.calc_investment_tax(gross_profit) : 0;
        RUB payout = std::max(0LL, Alice.invest_portfolio - tax);
        Alice.sber.account_rub += payout;
        if (gross_profit > 0) Alice.total_invest_profit += gross_profit;
        Alice.invest_portfolio = 0;
        Alice.invest_cost_basis = 0;
        return;
    }

    RUB contrib = Alice.salary / 10;
    if (contrib > 0 && Alice.sber.account_rub >= contrib)
    {
        Alice.sber.account_rub -= contrib;
        Alice.invest_portfolio += contrib;
        Alice.invest_cost_basis += contrib;
    }

    if (Alice.invest_portfolio <= 0) return;

    std::uniform_real_distribution<float> market(-0.15f, 0.20f);
    float monthly_return = market(gen);
    RUB   delta = static_cast<RUB>(Alice.invest_portfolio * monthly_return);
    Alice.invest_portfolio += delta;

    if (Alice.invest_portfolio < 0)
    {
        RUB debt = -Alice.invest_portfolio;
        RUB covered = std::min(debt, std::max(0LL, Alice.sber.account_rub));
        Alice.sber.account_rub -= covered;
        Alice.total_invest_loss += debt;
        Alice.invest_portfolio = 0;
        Alice.invest_cost_basis = 0;
        return;
    }

    if (Alice.invest_cost_basis > 0)
    {
        float gain_pct = static_cast<float>(
            Alice.invest_portfolio - Alice.invest_cost_basis)
            / static_cast<float>(Alice.invest_cost_basis);

        if (gain_pct > 0.10f)
        {
            std::bernoulli_distribution sell_dist(0.40);
            if (sell_dist(gen))
            {
                RUB gross_profit = Alice.invest_portfolio - Alice.invest_cost_basis;
                RUB tax = taxes_state.calc_investment_tax(gross_profit);
                RUB payout = Alice.invest_portfolio - tax;
                Alice.sber.account_rub += payout;
                Alice.total_invest_profit += gross_profit;
                Alice.invest_portfolio = 0;
                Alice.invest_cost_basis = 0;
            }
        }
    }
}

void process_apartment_upgrade()
{
    const auto& catalog = apartment_catalog();
    int next_level = Alice.apartment_level + 1;
    if (next_level >= static_cast<int>(catalog.size())) return;

    RUB price = apartment_current_price(next_level);
    RUB needed = static_cast<RUB>(price * 1.1); 

    if (Alice.sber.total_assets_rub() >= needed && Alice.sber.account_rub >= price / 2)
    {
        while (Alice.sber.account_rub < price) {
            break;
        }
        if (Alice.sber.account_rub >= price) {
            Alice.sber.account_rub -= price;
            Alice.apartment_level = next_level;
        }
    }
}

void process_car_upgrade()
{
    bool car_old = Alice.car.age_years >= 10;
    bool car_worn = Alice.car.car_cost < Alice.car.car_cost_initial / 5;
    if (!car_old && !car_worn) return;

    RUB new_car_price = static_cast<RUB>(
        std::min((double)Alice.salary * 24.0 * inflation_factor(), 20'000'000.0));
    RUB cushion = Alice.salary * 6;

    if (Alice.sber.account_rub >= new_car_price + cushion)
    {
        Alice.sber.account_rub -= new_car_price;
        Alice.car.car_cost = new_car_price;
        Alice.car.car_cost_initial = new_car_price;
        Alice.car.age_years = 0;
        Alice.car.liters_per_100km = 8.5f;
        Alice.car.horsepower = 160;
    }
}

void process_property_tax()
{
    if (Alice.apartment_level < 0) return;
    const Apartment& apt = apartment_catalog()[Alice.apartment_level];
    RUB inflated_cadastral = static_cast<RUB>(
        apt.cadastral_value * std::pow(1.09f, static_cast<float>(g_years_lived)));
    RUB prop_tax = taxes_state.calc_property_tax(inflated_cadastral);
    RUB actual = std::min(prop_tax, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual;
    Alice.total_property_tax += actual;
}

void process_transport_tax()
{
    RUB transport_tax = static_cast<RUB>(
        taxes_state.calc_transport_tax(Alice.car.horsepower) * inflation_factor());
    RUB actual_tax = std::min(transport_tax, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual_tax;
    Alice.total_transport_tax += actual_tax;
}

void process_utilities()
{
    if (Alice.apartment_level < 0) return;
    RUB base_utilities = 5'000 * (Alice.apartment_level + 1);
    RUB utilities = static_cast<RUB>(
        base_utilities * 12 * std::pow(1.08f, (float)g_years_lived));
    RUB actual = std::min(utilities, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual;
}

void process_car_incident(std::mt19937& car_gen)
{
    car_event_result car_ev = generate_car_event(car_gen);
    if (!car_ev.happened) return;
    RUB actual = std::min(car_ev.total_cost, std::max(0LL, Alice.sber.account_rub));
    Alice.sber.account_rub -= actual;
    Alice.total_car_repair_cost += actual;
    ++Alice.total_car_incidents;
}

// ============================================================
//  Инициализация
// ============================================================

void alice_start()
{
    g_years_lived = 0;
    g_expense_multiplier = 1.0f;

    Alice.age = 24;
    Alice.salary = 100'000;
    Alice.sber.account_rub = 0;

    Alice.car.car_cost = 4'000'000;
    Alice.car.car_cost_initial = 4'000'000;
    Alice.car.horsepower = 150;
    Alice.car.liters_per_100km = 9.5f;
    Alice.car.km_per_day = 40.0f;
    Alice.car.fuel_price = 58.0f;
    Alice.car.age_years = 0;
    Alice.car.fuel_cost_monthly = 0.0f;

    Alice.invest_portfolio = 0;
    Alice.invest_cost_basis = 0;
    Alice.total_invest_profit = 0;
    Alice.total_invest_loss = 0;

    Alice.total_sick_days = 0;
    Alice.total_medical_cost = 0;
    Alice.total_lost_salary = 0;
    Alice.total_fuel_cost = 0;
    Alice.total_transport_tax = 0;
    Alice.total_car_repair_cost = 0;
    Alice.total_car_incidents = 0;
    Alice.apartment_level = -1;
    Alice.total_property_tax = 0;

    Alice.is_married = false;
    Alice.has_first_child = false;
    Alice.is_grandmother = false;
    Alice.is_retired = false;
    Alice.passport_renewed = false;
    Alice.darwin_prize = false;
    Alice.career_multiplier = 1.0f;
}

// ============================================================
//  БЛОКИ ЖИЗНИ — тематические группы для alice_live()
// ============================================================

// ── Доходы: зарплата + случайные события ────────────────────
// Всё что приходит на счёт в этом месяце собрано здесь.
bool process_income(illness_result& illness)
{
    month_result events = generate_monthly_events();
    if (events.darwin_triggered)
    {
        Alice.darwin_prize = true;
        return false; // Алиса умерла
    }
    Alice.sber.account_rub += static_cast<RUB>(events.total_income * inflation_factor());

    process_salary(illness);
    return true;
}


void process_transport_monthly(int month, const illness_result& illness,
    std::mt19937& car_gen)
{
    process_fuel(illness);
    process_car_service(month);
    process_car_incident(car_gen);
}


void process_living_expenses(int month, const illness_result& illness)
{
    Alice.sber.account_rub -= calc_food_cost(month, illness.sick ? illness.days : 0);
    process_holiday_expenses(month);
}


void process_health(const illness_result& illness)
{
    process_medicine(illness);
}


void process_savings(std::mt19937& invest_gen)
{
    process_investments(invest_gen);
    Alice.sber.accrue_month_deposits();
    Alice.sber.try_auto_deposit();
}


void process_annual_housing_and_taxes()
{
    process_car_upgrade();
    process_apartment_upgrade();
    process_property_tax();
    process_transport_tax();
    process_utilities();
}


void process_vacation(illness_result& illness, std::mt19937& vacation_gen)
{
    auto [vcost, vsaved] = alice_vacation(vacation_gen, illness);
    illness.vacation_savings = vsaved;
}


void process_new_year(std::mt19937& career_gen)
{
    check_age_events(Alice.age);
    if (g_years_lived > 0) apply_annual_salary_growth(career_gen);
    Alice.car.depreciate();
}


// ============================================================
//  Премия Дарвина — финальный экран
// ============================================================

void print_darwin_award()
{
    const std::string GOLD = "\033[38;5;220m";
    const std::string DARK = "\033[38;5;94m";
    const std::string GRAY = "\033[38;5;240m";
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";

    std::cout << BOLD;

    std::cout << GOLD << "                /\\   /\\   /\\           " << RESET << "\n";
    std::cout << GOLD << "               /  \\ /  \\ /  \\          " << RESET << "\n";
    std::cout << GOLD << "              /    V    V    \\         " << RESET << "\n";
    std::cout << GOLD << "             |________________|        " << RESET << "\n";
    std::cout << GOLD << "             |________________|        " << RESET << "\n";

    // Ручки и тело кубка
    std::cout << GOLD << "            .'`   .======.   `'.      " << RESET << "\n";
    std::cout << GOLD << "          /  //  (        )  \\\\  \\" << RESET << "\n";
    std::cout << GOLD << "         |  //    \\      /    \\\\  |" << RESET << "\n";
    std::cout << GOLD << "         | //      )    (      \\\\ |" << RESET << "\n";
    std::cout << GOLD << "         |//       \\    /       \\\\|" << RESET << "\n";
    std::cout << GOLD << "         //    .    `--'    .    \\\\" << RESET << "\n";
    std::cout << GOLD << "        //    / \\          / \\    \\\\" << RESET << "\n";
    std::cout << GOLD << "        \\`.__/   `.______.'   \\__.'/" << RESET << "\n";

    // Ножка
    std::cout << GOLD << "                |          |          " << RESET << "\n";
    std::cout << GOLD << "                |          |          " << RESET << "\n";
    std::cout << GOLD << "               /|          |\\         " << RESET << "\n";
    std::cout << GOLD << "              / |          | \\        " << RESET << "\n";
    std::cout << GOLD << "             /  '----------'  \\       " << RESET << "\n";

    // Подставка
    std::cout << GRAY << "         .========================.  " << RESET << "\n";
    std::cout << GRAY << "         | " << GOLD << " .------------------. " << GRAY << " |  " << RESET << "\n";
    std::cout << GRAY << "         | " << GOLD << " |                  | " << GRAY << " |  " << RESET << "\n";
    std::cout << GRAY << "         | " << GOLD << " `------------------' " << GRAY << " |  " << RESET << "\n";
    std::cout << GRAY << "         '========================'  " << RESET << "\n";
    std::cout << GRAY << "        .-'----------------------'-.  " << RESET << "\n";
    std::cout << GRAY << "       /____________________________\\ " << RESET << "\n";

    std::cout << "\n";
            std::cout << "  Приносим свои извинения, но вы не смогли\n";
    std::cout << "  удивить Алису, поэтому она умерла от вдоха.\n";
    std::cout << "\n";
    std::cout << "  ╔══════════════════════════════════════════╗\n";
    std::cout << "  ║    Вручается премия Дарвина за самый     ║\n";
    std::cout << "  ║               конченый код               ║\n";
    std::cout << "  ╚══════════════════════════════════════════╝\n";
    std::cout << "\n";
}

// ============================================================
//  Основной цикл жизни
// ============================================================

bool alice_live()
{
    static std::mt19937 vacation_gen(std::random_device{}());
    static std::mt19937 illness_gen(std::random_device{}());
    static std::mt19937 car_gen(std::random_device{}());
    static std::mt19937 career_gen(std::random_device{}());
    static std::mt19937 invest_gen(std::random_device{}());

    int month = 1;
    illness_result illness;

    while (Alice.age < 97)
    {
        if (month == 1) process_new_year(career_gen);

        illness = generate_illness(illness_gen);

        if (!process_income(illness))
        {
            print_darwin_award();
            return true;
        }

        process_living_expenses(month, illness);
        process_health(illness);
        process_transport_monthly(month, illness, car_gen);
        process_savings(invest_gen);

        if (month == 7)  process_vacation(illness, vacation_gen);
        if (month == 12) process_annual_housing_and_taxes();

        ++month;
        if (month == 13) { month = 1; ++Alice.age; ++g_years_lived; }
    }

    return false;
}

// ============================================================
//  БЛОКИ ОТЧЁТА — тематические секции для alice_conclusion()
// ============================================================

namespace report
{
    // Вспомогательные типографские функции
    static constexpr int W = 54;
    static constexpr int WL = 34;
    static constexpr int WR = 16;

    int vis_len(const std::string& s)
    {
        int len = 0;
        for (unsigned char c : s)
            if ((c & 0xC0) != 0x80) ++len;
        return len;
    }

    void hline(char c = '-')
    {
        std::cout << std::setfill(c) << std::setw(W + 2) << "" << std::setfill(' ') << "\n";
    }

    void title(const std::string& s)
    {
        std::string padded = " " + s;
        int pad = W - vis_len(padded);
        std::cout << "|" << padded << std::string(std::max(0, pad), ' ') << "|\n";
    }

    void row(const std::string& label, const std::string& value)
    {
        int lpad = WL - vis_len(label);
        int rpad = WR - vis_len(value);
        std::cout << "|  " << label << std::string(std::max(0, lpad), ' ')
            << std::string(std::max(0, rpad), ' ') << value << "  |\n";
    }

    void row_rub(const std::string& label, RUB value)
    {
        row(label, std::to_string(value) + " руб.");
    }

    void center_line(const std::string& s)
    {
        int vl = vis_len(s);
        int lp = (W - vl) / 2, rp = W - vl - lp;
        std::cout << "|" << std::string(lp, ' ') << s << std::string(rp, ' ') << "|\n";
    }

    // ── Секция: биография (хроника жизни) ───────────────────
    void print_biography()
    {
        auto life_event = [](const char* tag, const std::string& text) {
            std::cout << std::left << std::setw(11) << tag << text << "\n";
            };

        life_event("[24 года]", "Начало самостоятельной жизни. Зарплата 20 000 руб.,");
        std::cout << std::setw(11) << "" << "автомобиль за 4 000 000 руб.\n";
        if (Alice.is_married)       life_event("[30 лет] ", "Вышла замуж. Свадьба, кольца, счастье.");
        if (Alice.has_first_child)  life_event("[32 года]", "Родился первый ребёнок. Декрет, бессонные ночи.");
        if (Alice.passport_renewed) life_event("[45 лет] ", "Сходила в МФЦ — поменяла паспорт.");
        if (Alice.apartment_level >= 0)
        {
            const Apartment& best = apartment_catalog()[Alice.apartment_level];
            std::cout << std::left << std::setw(11) << "[жильё]"
                << "\"" << best.name << "\" (" << best.area_sqm << " кв.м)\n";
        }
        if (Alice.is_grandmother) life_event("[64 года]", "Стала бабушкой. Подарки, радость, новый круг.");
        if (Alice.is_retired)     life_event("[65 лет] ", "Вышла на пенсию. Торт, цветы, свобода.");
    }

    // ── Секция: карьера и автомобиль (краткая сводка) ───────
    void print_career_and_car()
    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << Alice.career_multiplier << "x";
        std::cout << std::setw(11) << "[карьера]"
            << "Рост зарплаты за всю жизнь: " << oss.str() << "\n"
            << std::setw(11) << ""
            << "Финальная зарплата: " << Alice.salary << " руб./мес.\n\n";

        std::cout << std::setw(11) << "[авто]"
            << "Куплен за " << Alice.car.car_cost_initial << " руб., "
            << "сейчас стоит " << Alice.car.car_cost
            << " руб. (возраст " << Alice.car.age_years << " лет)\n\n";
    }

    // ── Секция: здоровье ────────────────────────────────────
    void print_health_section()
    {
        hline('-'); title("  ЗДОРОВЬЕ"); hline('-');
        row("Дней на больничном", std::to_string(Alice.total_sick_days) + " дней.");
        row_rub("Расходы на медицину", Alice.total_medical_cost);
        row_rub("Потери зарплаты (болезни)", Alice.total_lost_salary);
        hline('-');
        if (Alice.total_sick_days < 200) title("  Отличное здоровье — редко брала больничный.");
        else if (Alice.total_sick_days < 600) title("  Болела регулярно, но всегда справлялась.");
        else                                  title("  Здоровье доставляло немало хлопот.");
        std::cout << "\n";
    }

    // ── Секция: транспорт ────────────────────────────────────
    void print_transport_section()
    {
        hline('-'); title("  АВТОМОБИЛЬ"); hline('-');
        row_rub("Расходы на бензин", Alice.total_fuel_cost);
        row_rub("Транспортный налог", Alice.total_transport_tax);
        row_rub("Ремонты (инциденты)", Alice.total_car_repair_cost);
        row("Количество происшествий", std::to_string(Alice.total_car_incidents) + " шт.");
        row_rub("Текущая стоимость авто", Alice.car.car_cost);
        hline('-');
        row_rub("ИТОГО на автомобиль", Alice.total_fuel_cost
            + Alice.total_transport_tax
            + Alice.total_car_repair_cost);
        hline('-');
        if (Alice.total_car_incidents == 0) title("  Ни единой аварии — повезло!");
        else                                title("  С машиной случалось всякое.");
        std::cout << "\n";
    }

    // ── Секция: жильё ────────────────────────────────────────
    void print_housing_section()
    {
        hline('-'); title("  ЖИЛЬЁ"); hline('-');
        if (Alice.apartment_level < 0)
        {
            title("  Собственной квартиры так и не появилось.");
            title("  Всю жизнь снимала или жила с родственниками.");
        }
        else
        {
            const Apartment& apt = apartment_catalog()[Alice.apartment_level];
            row("Последняя квартира", apt.name);
            row("Площадь", std::to_string(apt.area_sqm) + " кв.м");
            row_rub("Цена покупки (базовая)", apt.price);
            row_rub("Кадастровая стоимость", apt.cadastral_value);
            row_rub("Налог на имущество", Alice.total_property_tax);
            hline('-');
            if (Alice.apartment_level == 0) title("  Скромный, но свой угол — это тоже немало.");
            else if (Alice.apartment_level <= 2) title("  Хорошая квартира, нажитая честным трудом.");
            else                                 title("  Роскошное жильё — итог всей жизни.");
        }
        std::cout << "\n";
    }

    // ── Секция: банковские вклады ────────────────────────────
    void print_deposits_section()
    {
        hline('-'); title("  БАНКОВСКИЕ ВКЛАДЫ"); hline('-');
        Alice.sber.print_deposit_summary();
        hline('-');
        std::cout << "\n";
    }

    // ── Секция: инвестиции ───────────────────────────────────
    void print_investments_section()
    {
        hline('-'); title("  ИНВЕСТИЦИИ В АКЦИИ"); hline('-');
        row_rub("Текущий портфель", Alice.invest_portfolio);
        row_rub("Суммарная зафикс. прибыль", Alice.total_invest_profit);
        row_rub("Суммарные покрытые убытки", Alice.total_invest_loss);
        row_rub("Чистый инвест. результат", Alice.total_invest_profit - Alice.total_invest_loss);
        hline('-');
        if (Alice.total_invest_profit > Alice.total_invest_loss)
            title("  Биржа принесла свои плоды.");
        else
            title("  Рынок не всегда был благосклонен.");
        std::cout << "\n";
    }

    // ── Секция: финансовый итог ──────────────────────────────
    void print_financial_summary()
    {
        hline('-'); title("  ФИНАНСОВЫЙ ИТОГ"); hline('-');
        Alice.sber.print_account_summary();
        if (Alice.invest_portfolio > 0)
            row_rub("Инвест. портфель (акции)", Alice.invest_portfolio);

        RUB total = Alice.sber.total_assets_rub() + Alice.invest_portfolio;
        RUB grand_total = total + Alice.car.car_cost;

        hline('-');
        row_rub("ИТОГО без авто", total);
        row_rub("Стоимость автомобиля", Alice.car.car_cost);
        hline('-');
        row_rub("ИТОГО со всеми активами", grand_total);
        hline('-');

        // Процентная разбивка расходов
        RUB total_spent = Alice.total_medical_cost + Alice.total_fuel_cost
            + Alice.total_transport_tax + Alice.total_car_repair_cost
            + Alice.total_property_tax;
        if (total_spent > 0)
        {
            auto pct_str = [&](RUB part) {
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(1) << (part * 100.0 / total_spent) << "%";
                return oss.str();
                };
            row("Медицина (% расходов)", pct_str(Alice.total_medical_cost));
            row("Автомобиль (% расходов)", pct_str(Alice.total_fuel_cost
                + Alice.total_transport_tax
                + Alice.total_car_repair_cost));
            row("Имущество (% расходов)", pct_str(Alice.total_property_tax));
            hline('-');
        }

        if (grand_total <= 0)        title("  Жизнь прожита на полную — денег не осталось.");
        else if (grand_total < 500'000)   title("  Скромные сбережения, зато прожита честно.");
        else if (grand_total < 5'000'000) title("  Приличная сумма — есть что оставить детям.");
        else                              title("  Финансовый гений своего времени.");

        std::cout << "\n";
    }

} // namespace report

// ============================================================
//  Итоговый отчёт
// ============================================================

void alice_conclusion()
{
    using namespace report;

    hline('='); center_line("ИСТОРИЯ ЖИЗНИ АЛИСЫ"); hline('=');
    std::cout << "\n";

    print_biography();
    std::cout << "\n";
    print_career_and_car();

    print_health_section();
    print_transport_section();
    print_housing_section();
    print_deposits_section();
    print_investments_section();
    print_financial_summary();

    hline('='); center_line("К О Н Е Ц"); hline('=');
    std::cout << "\n";
}

// ============================================================
//  Точка входа
// ============================================================

int main()
{
    setlocale(LC_ALL, "ru");
    alice_start();
    if (!alice_live())
        alice_conclusion();
    return 0;
}
