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
//  УПРОЩЕННАЯ СИСТЕМА ПИТАНИЯ
// ============================================================

struct ProductPrice {
    char name[50];
    RUB price_per_unit;
    RUB base_price;
};

struct Fridge {
    struct ProductPrice products[30];
    int num_products;
};

struct MealCategory {
    char name[20];
    RUB min_cost;
    RUB max_cost;
};

const struct MealCategory breakfast_options[] = {
    {"Каша", 80, 150},
    {"Бутерброд", 60, 120},
    {"Яичница", 70, 130},
    {"Творог", 90, 160},
    {"Йогурт", 50, 100}
};
const int breakfast_count = 5;

const struct MealCategory lunch_options[] = {
    {"Суп", 100, 200},
    {"Горячее", 150, 300},
    {"Салат", 50, 120}
};
const int lunch_count = 3;

const struct MealCategory dinner_options[] = {
    {"Горячее", 120, 250},
    {"Салат", 40, 100},
    {"Бутерброд", 50, 90},
    {"Каша", 70, 130}
};
const int dinner_count = 4;

const struct MealCategory snack_options[] = {
    {"Фрукт", 30, 70},
    {"Печенье", 40, 80},
    {"Йогурт", 50, 90},
    {"Орехи", 60, 120}
};
const int snack_count = 4;

const struct MealCategory drink_options[] = {
    {"Чай/Кофе", 10, 30},
    {"Сок", 40, 80},
    {"Вода", 5, 15},
    {"Кефир", 40, 70}
};
const int drink_count = 4;

struct FoodBudget {
    RUB total_monthly;
    RUB breakfast_cost;
    RUB lunch_cost;
    RUB dinner_cost;
    RUB snacks_cost;
    RUB drinks_cost;
};

// ============================================================
//  СТРУКТУРЫ ДЛЯ ПИТОМЦА
// ============================================================

struct Pet {
    char name[50];
    char breed[50];
    int age_months;
    RUB monthly_food;
    RUB yearly_vet_costs;
    RUB insurance_monthly;
    RUB toys_monthly;
    RUB training_cost;
    int last_vet_visit_month;
    int last_vet_visit_year;
    int has_insurance;
};

// ============================================================
//  СТРУКТУРЫ ДЛЯ КАРЬЕРНОГО РАЗВИТИЯ
// ============================================================

struct Skill {
    char name[50];
    int level;
    RUB learning_cost;
    RUB salary_bonus_per_level;
    int months_to_learn;
    int is_learning;
    int months_learned;
};

struct Career {
    char position[50];
    char company[50];
    int experience_years;
    int experience_months;
    struct Skill skills[10];
    int num_skills;
    RUB next_promotion_salary;
    int months_until_review;
    int promotion_probability;
    RUB annual_bonus_percentage;
};

// ============================================================
//  ОСНОВНАЯ СТРУКТУРА PERSON
// ============================================================

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
    struct Pet pet;
    struct Career career;
};

struct Person alice;

const float INFLATION_RATE = 8.5;
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
    RUB pet_expenses;
    RUB career_expenses;
} stats;

struct LifeEvent {
    int year;
    int month;
    char description[100];
    RUB financial_impact;
    void (*effect)(struct Person* p, RUB amount);
    int probability;
    int triggered;
    int min_month;
    int max_month;
    int min_year;
    int max_year;
};

std::vector<LifeEvent> events;

// Прототипы функций
void alice_init();
void init_stats();
void withdraw_cash(RUB amount);
RUB calculate_meal_cost(const struct MealCategory* category);
void alice_food();
void alice_housing_expenses();
void alice_car();
void alice_salary(int year, int month);
void alice_bank_interest();
void alice_manage_savings(int month);
void alice_simulation();
void print_results();
void init_product_prices(struct Fridge* fridge);
void update_product_prices(struct Fridge* fridge, int month);
void apply_gas_inflation(int month);
void try_take_mortgage(struct Person* man, int year);
void alice_pay_mortgage();
void alice_tax_refund(int year, int month);
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
void inheritance_receive(struct Person* man, RUB amount);
void init_pet(struct Person* man);
void pet_expenses(struct Person* man, int month, int year);
void init_career(struct Person* man);
void update_skill_learning(struct Person* man, int month);
void career_review(struct Person* man, int month);
void apply_annual_bonus(struct Person* man, int month);
void start_learning_skill(struct Person* man, int skill_index);
void add_new_skill(struct Person* man, const char* skill_name, RUB cost, RUB bonus, int months);
void check_events(int year, int month, struct Person* man);
void init_events_dynamic();
void schedule_events();
void calculate_seasonal_utilities(struct Person* man, int month);

// ============================================================
//  УПРОЩЕННЫЕ ФУНКЦИИ ПИТАНИЯ
// ============================================================

void init_product_prices(struct Fridge* fridge) {
    fridge->num_products = 0;
    
    struct ProductPrice products[] = {
        {"молоко", 70, 70},
        {"хлеб", 45, 45},
        {"мясо", 180, 180},
        {"овощи", 30, 30},
        {"фрукты", 50, 50}
    };
    
    for (int i = 0; i < 5; i++) {
        fridge->products[fridge->num_products++] = products[i];
    }
}

void update_product_prices(struct Fridge* fridge, int month) {
    for (int i = 0; i < fridge->num_products; i++) {
        float inflation = 0.7;
        
        if (strcmp(fridge->products[i].name, "мясо") == 0) {
            inflation = 1.2;
        } else if (strcmp(fridge->products[i].name, "овощи") == 0) {
            inflation = 0.5;
        }
        
        float multiplier = 1.0 + inflation / 100.0;
        fridge->products[i].price_per_unit = 
            fridge->products[i].base_price * pow(multiplier, month - 1);
    }
}

RUB calculate_meal_cost(const struct MealCategory* category) {
    RUB cost = category->min_cost + (rand() % (category->max_cost - category->min_cost + 1));
    
    if (alice.fridge.num_products > 0) {
        float avg_inflation = 0;
        for (int i = 0; i < alice.fridge.num_products; i++) {
            avg_inflation += alice.fridge.products[i].price_per_unit / alice.fridge.products[i].base_price;
        }
        avg_inflation /= alice.fridge.num_products;
        cost = cost * avg_inflation;
    }
    
    return cost;
}

void alice_food()
{
    static int current_month = 2;
    int is_holiday_month = (current_month == 12 || current_month == 1 || 
                            current_month == 3 || current_month == 5);
    
    int sick_days = 0;
    if (rand() % 100 < 10) {
        sick_days = 3 + rand() % 5;
        printf("\n   Алиса болеет %d дней в этом месяце\n", sick_days);
    }
    
    struct FoodBudget budget = {0, 0, 0, 0, 0, 0};
    int days_in_month = 30;
    
    for (int day = 1; day <= days_in_month; day++) {
        int is_sick = (day <= sick_days);
        
        if (is_sick) {
            budget.breakfast_cost += 50 + rand() % 50;
            budget.lunch_cost += 80 + rand() % 70;
            budget.dinner_cost += 60 + rand() % 60;
            budget.drinks_cost += 20 + rand() % 30;
        } else {
            int breakfast_idx = rand() % breakfast_count;
            budget.breakfast_cost += calculate_meal_cost(&breakfast_options[breakfast_idx]);
            budget.drinks_cost += calculate_meal_cost(&drink_options[rand() % drink_count]);
            
            int lunch_idx = rand() % lunch_count;
            budget.lunch_cost += calculate_meal_cost(&lunch_options[lunch_idx]);
            
            if (is_holiday_month && (day == 1 || day % 7 == 0)) {
                budget.lunch_cost += 200 + rand() % 200;
            }
            
            budget.drinks_cost += calculate_meal_cost(&drink_options[rand() % drink_count]);
            
            int dinner_idx = rand() % dinner_count;
            budget.dinner_cost += calculate_meal_cost(&dinner_options[dinner_idx]);
            budget.drinks_cost += calculate_meal_cost(&drink_options[rand() % drink_count]);
            
            if (rand() % 100 < 40) {
                int snack_idx = rand() % snack_count;
                budget.snacks_cost += calculate_meal_cost(&snack_options[snack_idx]);
            }
        }
    }
    
    budget.total_monthly = budget.breakfast_cost + budget.lunch_cost + 
                           budget.dinner_cost + budget.snacks_cost + budget.drinks_cost;
    
    RUB total_food_cost = budget.total_monthly;
    
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
    
    if (alice.main_bank != NULL) {
        RUB cashback = food_card * alice.main_bank->card_cashback;
        alice.bank.card += cashback;
        stats.cashback_received += cashback;
        if (cashback > 0) printf("  Кэшбэк за продукты: %lld руб.\n", cashback);
    }
    
    printf("\n РАСХОДЫ НА ПИТАНИЕ ЗА МЕСЯЦ:\n");
    printf("  Завтраки:   %10lld руб.\n", budget.breakfast_cost);
    printf("  Обеды:      %10lld руб.\n", budget.lunch_cost);
    printf("  Ужины:      %10lld руб.\n", budget.dinner_cost);
    printf("  Перекусы:   %10lld руб.\n", budget.snacks_cost);
    printf("  Напитки:    %10lld руб.\n", budget.drinks_cost);
    printf("  ИТОГО:      %10lld руб.\n", total_food_cost);
    
    current_month++;
    if (current_month > 12) current_month = 1;
}

// ============================================================
//  ФУНКЦИИ ДЛЯ ПИТОМЦА (ИМЯ ИЗМЕНЕНО НА ТУЗИК)
// ============================================================

void init_pet(struct Person* man) {
    strcpy(man->pet.name, "Тузик");
    strcpy(man->pet.breed, "Немецкая овчарка");
    man->pet.age_months = 24;
    man->pet.monthly_food = 5000;
    man->pet.yearly_vet_costs = 8000;
    man->pet.insurance_monthly = 1500;
    man->pet.toys_monthly = 1000;
    man->pet.training_cost = 15000;
    man->pet.last_vet_visit_month = 1;
    man->pet.last_vet_visit_year = 2026;
    man->pet.has_insurance = 1;
    
    printf("Питомец добавлен: %s (%s), возраст: %d мес.\n", 
           man->pet.name, man->pet.breed, man->pet.age_months);
}

void pet_expenses(struct Person* man, int month, int year) {
    RUB total_pet_cost = man->pet.monthly_food;
    total_pet_cost += man->pet.has_insurance ? man->pet.insurance_monthly : 0;
    total_pet_cost += man->pet.toys_monthly;
    
    if (month == man->pet.last_vet_visit_month && year > man->pet.last_vet_visit_year) {
        total_pet_cost += man->pet.yearly_vet_costs;
        man->pet.last_vet_visit_year = year;
        printf("  Ежегодный осмотр у ветеринара: %lld руб.\n", man->pet.yearly_vet_costs);
    }
    
    if (man->pet.age_months < 36 && month == 3 && year == 2026) {
        total_pet_cost += man->pet.training_cost;
        printf("  Курсы дрессировки: %lld руб.\n", man->pet.training_cost);
    }
    
    man->pet.age_months++;
    
    RUB pet_cash_needed = total_pet_cost * 0.3;
    
    if (man->cash < pet_cash_needed) {
        RUB needed = pet_cash_needed - man->cash;
        withdraw_cash(needed);
    }
    
    RUB pet_cash = pet_cash_needed;
    RUB pet_card = total_pet_cost * 0.7;
    
    man->cash -= pet_cash;
    man->bank.card -= pet_card;
    
    stats.pet_expenses += total_pet_cost;
    stats.cash_spent += pet_cash;
    stats.card_spent += pet_card;
    
    printf("  Расходы на питомца: %lld руб.\n", total_pet_cost);
}

// ============================================================
//  ФУНКЦИИ ДЛЯ КОММУНАЛЬНЫХ УСЛУГ ПО СЕЗОНУ
// ============================================================

void calculate_seasonal_utilities(struct Person* man, int month) {
    RUB base_utilities = man->housing.utilities;
    RUB seasonal_adjustment = 0;
    
    // Зимние месяцы (декабрь, январь, февраль) - отопление дороже
    if (month == 12 || month == 1 || month == 2) {
        seasonal_adjustment = base_utilities * 0.5;  // +50% к коммунальным
        printf("  Зимний сезон: увеличение расходов на отопление\n");
    }
    // Летние месяцы (июнь, июль, август) - кондиционер
    else if (month == 6 || month == 7 || month == 8) {
        seasonal_adjustment = base_utilities * 0.3;  // +30% к коммунальным
        printf("  Летний сезон: увеличение расходов на кондиционирование\n");
    }
    // Весенние и осенние месяцы - расходы ниже
    else if (month == 4 || month == 5 || month == 9 || month == 10) {
        seasonal_adjustment = -base_utilities * 0.1;  // -10% к коммунальным
        printf("  Межсезонье: снижение коммунальных расходов\n");
    }
    
    man->housing.utilities = base_utilities + seasonal_adjustment;
    
    if (seasonal_adjustment != 0) {
        printf("  Коммунальные услуги: %lld руб. (было %lld руб.)\n", 
               man->housing.utilities, base_utilities);
    }
}

// ============================================================
//  ФУНКЦИИ ДЛЯ КАРЬЕРНОГО РАЗВИТИЯ
// ============================================================

void init_career(struct Person* man) {
    strcpy(man->career.position, "Старший разработчик");
    strcpy(man->career.company, "IT-Компания");
    man->career.experience_years = 3;
    man->career.experience_months = 6;
    man->career.next_promotion_salary = man->salary * 1.3;
    man->career.months_until_review = 6;
    man->career.promotion_probability = 15;
    man->career.annual_bonus_percentage = 20;
    man->career.num_skills = 0;
    
    struct Skill skill1 = {"C++", 85, 30000, 5000, 3, 0, 0};
    man->career.skills[man->career.num_skills++] = skill1;
    
    struct Skill skill2 = {"Python", 70, 25000, 4000, 2, 0, 0};
    man->career.skills[man->career.num_skills++] = skill2;
    
    printf("Карьера: %s в %s\n", man->career.position, man->career.company);
}

void update_skill_learning(struct Person* man, int month) {
    for (int i = 0; i < man->career.num_skills; i++) {
        if (man->career.skills[i].is_learning) {
            man->career.skills[i].months_learned++;
            
            if (man->career.skills[i].months_learned >= man->career.skills[i].months_to_learn) {
                man->career.skills[i].level += 20;
                man->career.skills[i].is_learning = 0;
                
                RUB salary_increase = man->career.skills[i].salary_bonus_per_level * 20;
                man->salary += salary_increase;
                
                printf("  Навык освоен: %s (уровень %d)\n", 
                       man->career.skills[i].name, man->career.skills[i].level);
                printf("     Зарплата увеличена на %lld руб.\n", salary_increase);
            }
        }
    }
}

void career_review(struct Person* man, int month) {
    if (man->career.months_until_review > 0) {
        man->career.months_until_review--;
        return;
    }
    
    printf("\n  КАРЬЕРНАЯ ОЦЕНКА\n");
    
    int total_level = 0;
    for (int i = 0; i < man->career.num_skills; i++) {
        total_level += man->career.skills[i].level;
    }
    int avg_skill_level = man->career.num_skills > 0 ? total_level / man->career.num_skills : 0;
    
    int promotion_chance = man->career.promotion_probability + (avg_skill_level - 50) / 5;
    if (promotion_chance < 0) promotion_chance = 0;
    if (promotion_chance > 50) promotion_chance = 50;
    
    int roll = rand() % 100;
    
    if (roll < promotion_chance) {
        RUB old_salary = man->salary;
        man->salary = man->career.next_promotion_salary;
        
        if (strcmp(man->career.position, "Разработчик") == 0)
            strcpy(man->career.position, "Старший разработчик");
        else if (strcmp(man->career.position, "Старший разработчик") == 0)
            strcpy(man->career.position, "Team Lead");
        
        man->career.next_promotion_salary = man->salary * 1.2;
        
        printf("  ПОВЫШЕНИЕ! Новая должность: %s\n", man->career.position);
        printf("     Зарплата: %lld -> %lld руб.\n", old_salary, man->salary);
    } else {
        RUB increase = man->salary * 0.05;
        man->salary += increase;
        printf("  Индексация зарплаты: +%lld руб.\n", increase);
    }
    
    man->career.months_until_review = 6 + (rand() % 7);
}

void apply_annual_bonus(struct Person* man, int month) {
    if (month == 12) {
        RUB bonus = man->salary * (man->career.annual_bonus_percentage / 100.0);
        man->bank.card += bonus;
        stats.salary_received += bonus;
        printf("  ГОДОВАЯ ПРЕМИЯ: %lld руб.\n", bonus);
    }
}

// ============================================================
//  ОСТАЛЬНЫЕ ФУНКЦИИ
// ============================================================

void init_stats() {
    memset(&stats, 0, sizeof(stats));
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
    init_pet(&alice);
    init_career(&alice);
    
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
    float inflation_multiplier = 1.0 + GAS_MONTHLY_INFLATION / 100.0;
    alice.car.gas = alice.car.base_gas * pow(inflation_multiplier, month - 1);
    
    if (month == 1) {
        alice.car.base_gas = alice.car.gas;
    }
}

void try_take_mortgage(struct Person* man, int year) {
    if (man->mortgage.active) return;

    RUB flat_price = 4000000;
    RUB first_payment = flat_price * 0.2; 
    RUB parents_help = 200000;

    if (man->bank.savings < first_payment) {
        if (man->bank.savings + parents_help >= first_payment) {
            printf("\n РОДИТЕЛИ ПОМОГЛИ С ПЕРВОНАЧАЛЬНЫМ ВЗНОСОМ\n");
            man->bank.savings += parents_help;
        } else {
            return;
        }
    }

    RUB loan = flat_price - first_payment;
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
    man->housing.rent = 0;
}

void alice_pay_mortgage() {
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

void alice_housing_expenses() {
    RUB total_housing = alice.housing.rent + alice.housing.utilities + 
                        alice.housing.internet + alice.housing.mobile;
    RUB housing_cash_needed = total_housing * 0.5;
    
    if (alice.cash < housing_cash_needed) {
        withdraw_cash(housing_cash_needed - alice.cash);
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
    }
}

void alice_car() {
    RUB gas_cash_needed = alice.car.gas * 0.5;
    if (alice.cash < gas_cash_needed) {
        withdraw_cash(gas_cash_needed - alice.cash);
    }
    
    RUB gas_cash = gas_cash_needed;
    RUB gas_card = alice.car.gas * 0.5;
    
    alice.cash -= gas_cash;
    alice.bank.card -= gas_card;
    stats.gas_paid += alice.car.gas;
    stats.cash_spent += gas_cash;
    stats.card_spent += gas_card;
}

void alice_clothing() {
    RUB clothing_cash_needed = alice.clothing * 0.2;
    if (alice.cash < clothing_cash_needed) {
        withdraw_cash(clothing_cash_needed - alice.cash);
    }
    
    RUB clothing_cash = clothing_cash_needed;
    RUB clothing_card = alice.clothing * 0.8;
    
    alice.cash -= clothing_cash;
    alice.bank.card -= clothing_card;
    stats.clothing_paid += alice.clothing;
    stats.cash_spent += clothing_cash;
    stats.card_spent += clothing_card;
}

void alice_tax_refund(int year, int month) {
    if (month != 1 || stats.tax_deduction_base <= 0) return;
    
    RUB base = stats.tax_deduction_base;
    if (base > 150000) base = 150000;
    RUB refund = base * 0.13;
    
    printf("\n ВОЗВРАТ НАЛОГОВОГО ВЫЧЕТА: %lld руб.\n", refund);
    alice.bank.card += refund;
    stats.total_events_impact -= refund;
    stats.tax_deduction_base = 0;
}

void alice_salary(const int year, const int month) {
    RUB salary_to_pay = alice.salary;
    
    if (month == 3 && year == 2026) {
        RUB old_salary = alice.salary;
        alice.salary = alice.salary * 1.5;
        salary_to_pay = old_salary;
        printf("  ПОВЫШЕНИЕ ЗАРПЛАТЫ! Теперь %lld руб./мес\n", alice.salary);
        alice.career.next_promotion_salary = alice.salary * 1.3;
    }
    
    RUB tax = salary_to_pay * 0.13;
    RUB after_tax = salary_to_pay - tax;
    alice.bank.card += after_tax;
    stats.salary_received += after_tax;
    stats.taxes_paid += tax;
}

void alice_bank_interest() {
    if (alice.bank.savings <= 0) return;
    
    if (alice.main_bank != NULL && alice.main_bank->calculate_rate != NULL) {
        alice.bank.rate = alice.main_bank->calculate_rate(alice.bank.savings);
    }
    
    RUB monthly_interest = alice.bank.savings * (alice.bank.rate / 12.0 / 100.0);
    alice.bank.savings += monthly_interest;
    stats.interest_received += monthly_interest;
}

void alice_manage_savings(const int month) {
    if (alice.bank.card > 100000) {
        RUB transfer = (alice.bank.card - 50000) * 0.7;
        if (transfer > 0 && alice.main_bank != NULL && 
            transfer >= alice.main_bank->min_deposit) {
            alice.bank.savings += transfer;
            alice.bank.card -= transfer;
            stats.savings_moved += transfer;
        }
    }
    
    if (alice.bank.card < 20000 && alice.bank.savings > 0) {
        RUB withdraw = alice.bank.savings * 0.2;
        if (withdraw > 0) {
            if (alice.bank.savings - withdraw < alice.main_bank->min_deposit) {
                withdraw = alice.bank.savings;
            }
            alice.bank.savings -= withdraw;
            alice.bank.card += withdraw;
            stats.savings_moved -= withdraw;
        }
    }
}

// Жизненные события
void car_breakdown(struct Person* man, RUB amount) {
    RUB cost = 30000 + rand() % 120000;
    printf("\n ПОЛОМКА АВТОМОБИЛЯ: %lld руб.\n", cost);
    if (man->bank.savings >= cost) {
        man->bank.savings -= cost;
    } else {
        RUB remaining = cost - man->bank.savings;
        man->bank.savings = 0;
        man->bank.card -= remaining;
    }
    stats.total_events_impact += cost;
}

void medical_emergency(struct Person* man, RUB amount) {
    RUB cost = 20000 + rand() % 280000;
    printf("\n МЕДИЦИНСКАЯ ПРОБЛЕМА: %lld руб.\n", cost);
    if (man->bank.savings >= cost) {
        man->bank.savings -= cost;
    } else {
        RUB remaining = cost - man->bank.savings;
        man->bank.savings = 0;
        man->bank.card -= remaining;
    }
    stats.tax_deduction_base += cost;
    stats.total_events_impact += cost;
}

void salary_bonus(struct Person* man, RUB amount) {
    RUB bonus = man->salary * (0.3 + (rand() % 70) / 100.0);
    printf("\n ГОДОВАЯ ПРЕМИЯ: %lld руб.\n", bonus);
    man->bank.card += bonus;
    stats.salary_received += bonus;
    stats.total_events_impact -= bonus;
}

void vacation_expense(struct Person* man, RUB amount) {
    RUB cost = 50000 + rand() % 200000;
    printf("\n ОТПУСК: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void home_repair(struct Person* man, RUB amount) {
    RUB cost = 20000 + rand() % 180000;
    printf("\n РЕМОНТ: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void laptop_breakdown(struct Person* man, RUB amount) {
    RUB cost = 30000 + rand() % 70000;
    printf("\n ПОЛОМКА НОУТБУКА: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void dental_treatment(struct Person* man, RUB amount) {
    RUB cost = 15000 + rand() % 135000;
    printf("\n ЛЕЧЕНИЕ ЗУБОВ: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.tax_deduction_base += cost;
    stats.total_events_impact += cost;
}

void car_insurance(struct Person* man, RUB amount) {
    RUB cost = 25000 + rand() % 25000;
    printf("\n СТРАХОВКА: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void fitness_subscription(struct Person* man, RUB amount) {
    RUB cost = 15000 + rand() % 35000;
    printf("\n ФИТНЕС: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.tax_deduction_base += cost;
    stats.total_events_impact += cost;
}

void courses_expense(struct Person* man, RUB amount) {
    RUB cost = 20000 + rand() % 80000;
    printf("\n КУРСЫ: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.tax_deduction_base += cost;
    stats.total_events_impact += cost;
}

void phone_break(struct Person* man, RUB amount) {
    RUB cost = 10000 + rand() % 60000;
    printf("\n РАЗБИТ ТЕЛЕФОН: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void friend_wedding(struct Person* man, RUB amount) {
    RUB cost = 10000 + rand() % 40000;
    printf("\n СВАДЬБА ДРУГА: %lld руб.\n", cost);
    man->bank.card -= cost;
    stats.total_events_impact += cost;
}

void inheritance_receive(struct Person* man, RUB amount) {
    RUB inheritance = 100000 + rand() % 900000;
    printf("\n НАСЛЕДСТВО: %lld руб.\n", inheritance);
    man->bank.savings += inheritance;
    stats.total_events_impact -= inheritance;
}

void init_events_dynamic() {
    events.clear();
    
    struct LifeEvent events_data[] = {
        {"Поломка автомобиля", 2026, 2027, 1, 12, car_breakdown, 25},
        {"Медицинская проблема", 2026, 2027, 1, 12, medical_emergency, 15},
        {"Годовая премия", 2026, 2027, 12, 1, salary_bonus, 70},
        {"Отпуск", 2026, 2027, 6, 8, vacation_expense, 90},
        {"Свадьба друга", 2026, 2026, 11, 11, friend_wedding, 100},
        {"Ремонт", 2026, 2027, 4, 8, home_repair, 30},
        {"Поломка ноутбука", 2026, 2027, 1, 12, laptop_breakdown, 20},
        {"Лечение зубов", 2026, 2027, 1, 12, dental_treatment, 25},
        {"Страховка", 2026, 2026, 3, 3, car_insurance, 100},
        {"Фитнес", 2026, 2027, 1, 1, fitness_subscription, 60},
        {"Курсы", 2026, 2027, 9, 10, courses_expense, 40},
        {"Разбил телефон", 2026, 2027, 1, 12, phone_break, 15},
        {"Наследство", 2026, 2027, 1, 12, inheritance_receive, 5}
    };
    
    for (int i = 0; i < 13; i++) {
        struct LifeEvent e;
        strcpy(e.description, events_data[i].description);
        e.min_year = events_data[i].min_year;
        e.max_year = events_data[i].max_year;
        e.min_month = events_data[i].min_month;
        e.max_month = events_data[i].max_month;
        e.effect = events_data[i].effect;
        e.probability = events_data[i].probability;
        e.triggered = 0;
        e.financial_impact = 0;
        events.push_back(e);
    }
}

void schedule_events() {
    for (auto& event : events) {
        if (event.min_year == event.max_year) {
            event.year = event.min_year;
            if (event.min_month <= event.max_month) {
                event.month = event.min_month + (rand() % (event.max_month - event.min_month + 1));
            } else {
                int range = (12 - event.min_month + 1) + event.max_month;
                int offset = rand() % range;
                if (offset < (12 - event.min_month + 1)) {
                    event.month = event.min_month + offset;
                } else {
                    event.month = offset - (12 - event.min_month + 1) + 1;
                    event.year = event.min_year + 1;
                }
            }
        } else {
            int year_range = event.max_year - event.min_year;
            event.year = event.min_year + (rand() % (year_range + 1));
            if (event.year == event.min_year) {
                event.month = event.min_month + rand() % (13 - event.min_month);
            } else if (event.year == event.max_year) {
                event.month = 1 + rand() % event.max_month;
            } else {
                event.month = 1 + rand() % 12;
            }
        }
    }
}

void check_events(int year, int month, struct Person* man) {
    for (size_t i = 0; i < events.size(); i++) {
        if (events[i].year == year && events[i].month == month && !events[i].triggered) {
            if (rand() % 100 < events[i].probability) {
                if (events[i].effect != NULL) {
                    events[i].effect(man, events[i].financial_impact);
                }
                events[i].triggered = 1;
            }
        }
    }
}

void alice_simulation()
{
    int year = 2026;
    int month = 2;
    
    init_events_dynamic();
    schedule_events();
    
    printf("\n=== СТАРТ СИМУЛЯЦИИ ===\n");
    printf("Стартовое состояние:\n");
    printf("  Наличные: %lld руб.\n", alice.cash);
    printf("  Карта: %lld руб.\n", alice.bank.card);
    printf("  Сбережения: %lld руб.\n\n", alice.bank.savings);
    
    while (!(year == 2027 && month == 2)) {
        printf("\n--- %d.%d ---\n", month, year);

        update_product_prices(&alice.fridge, month);
        apply_gas_inflation(month);
        
        calculate_seasonal_utilities(&alice, month);
        
        try_take_mortgage(&alice, year);
        check_events(year, month, &alice);
        
        pet_expenses(&alice, month, year);
        update_skill_learning(&alice, month);
        career_review(&alice, month);
        apply_annual_bonus(&alice, month);
        
        alice_housing_expenses();
        alice_pay_mortgage();
        alice_food();
        alice_clothing();
        alice_car();
        alice_tax_refund(year, month);
        
        alice_bank_interest();
        alice_manage_savings(month);
        alice_salary(year, month);
        
        printf("  ИТОГ: Наличные %lld, Карта %lld, Сбережения %lld\n", 
               alice.cash, alice.bank.card, alice.bank.savings);
        
        month++;
        if (month == 13) {
            year++;
            month = 1;
            printf("\n=== НОВЫЙ ГОД: %d ===\n", year);
        }
    }
}

void print_results()
{
    RUB nominal_capital = alice.cash + alice.car.value + alice.bank.card + alice.bank.savings;
    float inflation_factor = 1.0 + INFLATION_RATE / 100.0;
    RUB real_capital = nominal_capital / inflation_factor;
    RUB monthly_housing = alice.housing.rent + alice.housing.utilities + 
                          alice.housing.internet + alice.housing.mobile;
    RUB avg_food_cost = stats.food_paid / 12;
    RUB avg_pet_cost = stats.pet_expenses / 12;
    RUB monthly_total = monthly_housing + avg_food_cost + alice.clothing + alice.car.gas + avg_pet_cost;
    
    printf("\n");
    printf("========================================\n");
    printf("     ФИНАНСОВЫЙ ОТЧЕТ АЛИСЫ            \n");
    printf("========================================\n");
    printf("  Период: Февраль 2026 - Февраль 2027\n");

    printf("\nТЕКУЩЕЕ СОСТОЯНИЕ\n");
    printf("  Наличные:          %10lld руб.\n", alice.cash);
    printf("  Карта:             %10lld руб.\n", alice.bank.card);
    printf("  Сбережения:        %10lld руб.\n", alice.bank.savings);
    printf("  Автомобиль:        %10lld руб.\n", alice.car.value);
    printf("  Зарплата:          %10lld руб./мес\n", alice.salary);
    
    printf("\nПИТОМЕЦ\n");
    printf("  Имя:               %s\n", alice.pet.name);
    printf("  Порода:            %s\n", alice.pet.breed);
    printf("  Возраст:           %d мес.\n", alice.pet.age_months);
    printf("  Расходы за год:    %10lld руб.\n", stats.pet_expenses);
    
    printf("\nКАРЬЕРА\n");
    printf("  Должность:         %s\n", alice.career.position);
    printf("  Компания:          %s\n", alice.career.company);
    printf("  Опыт:              %d лет %d мес.\n", 
           alice.career.experience_years, alice.career.experience_months);
    printf("  Навыки:\n");
    for (int i = 0; i < alice.career.num_skills; i++) {
        printf("    * %-12s ур.%d\n", alice.career.skills[i].name, alice.career.skills[i].level);
    }
    
    printf("\nКАПИТАЛ\n");
    printf("  Номинальный:       %10lld руб.\n", nominal_capital);
    printf("  Реальный:          %10lld руб.\n", real_capital);

    printf("\nДОХОДЫ (ЗА ГОД)\n");
    printf("  Зарплата:          %10lld руб.\n", stats.salary_received);
    printf("  Кэшбэк:            %10lld руб.\n", stats.cashback_received);
    printf("  Проценты:          %10lld руб.\n", stats.interest_received);
    printf("  ВСЕГО:             %10lld руб.\n", 
           stats.salary_received + stats.cashback_received + stats.interest_received);

    printf("\nРАСХОДЫ (ЗА ГОД)\n");
    printf("  Жилье:             %10lld руб.\n", stats.housing_paid);
    printf("  Еда:               %10lld руб.\n", stats.food_paid);
    printf("  Одежда:            %10lld руб.\n", stats.clothing_paid);
    printf("  Бензин:            %10lld руб.\n", stats.gas_paid);
    printf("  Питомец:           %10lld руб.\n", stats.pet_expenses);
    printf("  Налоги:            %10lld руб.\n", stats.taxes_paid);
    printf("  ВСЕГО:             %10lld руб.\n", 
           stats.housing_paid + stats.food_paid + stats.clothing_paid + 
           stats.gas_paid + stats.pet_expenses + stats.taxes_paid);
    
    printf("\nСРЕДНЕМЕСЯЧНЫЕ РАСХОДЫ\n");
    printf("  Жилье:             %10lld руб.\n", monthly_housing);
    printf("  Еда:               %10lld руб.\n", avg_food_cost);
    printf("  Одежда:            %10lld руб.\n", alice.clothing);
    printf("  Бензин:            %10lld руб.\n", alice.car.gas);
    printf("  Питомец:           %10lld руб.\n", avg_pet_cost);
    printf("  ВСЕГО:             %10lld руб.\n", monthly_total);
    
    if (alice.mortgage.active) {
        printf("\nИПОТЕКА\n");
        printf("  Остаток:           %10lld руб.\n", alice.mortgage.total_amount);
        printf("  Платёж:            %10lld руб./мес\n", alice.mortgage.monthly_payment);
    }
    
    printf("\nПРОИЗОШЕДШИЕ СОБЫТИЯ\n");
    for (size_t i = 0; i < events.size(); i++) {
        if (events[i].triggered) {
            printf("  * %d.%d: %s\n", events[i].month, events[i].year, events[i].description);
        }
    }
    printf("\n========================================\n");
}

int main()
{
    srand(time(NULL));
    printf("ФИНАНСОВАЯ СИМУЛЯЦИЯ АЛИСЫ\n");
    printf("(с питомцем Тузик и карьерным развитием)\n\n");
    
    alice_init();
    alice_simulation();
    print_results();
    
    return 0;
}