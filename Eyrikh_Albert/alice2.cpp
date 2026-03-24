
#ifndef CONFIG_H
#define CONFIG_H

// Базовые константы
const int SIMULATION_START_MONTH = 1;
const int SIMULATION_START_YEAR = 2024;
const int SIMULATION_END_MONTH = 12;
const int SIMULATION_END_YEAR = 2027;  

// Денежные константы (в копейках)
const long long MINIMUM_WAGE = 19'242 * 100;
const long long AVERAGE_SALARY = 75'000 * 100;

// Налоги
const float INCOME_TAX_RATE = 0.13;      
const float PROPERTY_TAX_RATE = 0.001;   
const float VAT_RATE = 0.20;             

// Инфляция по категориям
const float FOOD_INFLATION = 0.10;       
const float HOUSING_INFLATION = 0.08;
const float CAR_INFLATION = 0.05;
const float UTILITIES_INFLATION = 0.12;  
const float PET_INFLATION = 0.07;

// Банковские ставки
const float DEPOSIT_RATE_PREMIUM = 16.0;   
const float DEPOSIT_RATE_STANDARD = 12.0;
const float DEPOSIT_RATE_SAVINGS = 8.0;
const float CREDIT_CARD_RATE = 25.0;       
const float MORTGAGE_RATE_BASE = 11.0;
const float MORTGAGE_RATE_FAMILY = 6.0;    
const float CAR_LOAN_RATE = 15.0;

// Лимиты
const long long CREDIT_CARD_LIMIT = 100'000 * 100;
const long long OVERDRAFT_LIMIT = 30'000 * 100;
const long long MORTGAGE_MAX_AMOUNT = 12'000'000 * 100;
const long long CAR_LOAN_MAX = 2'000'000 * 100;

#endif

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <stdio.h>
#include <string.h>
#include <time.h>

enum TransactionType {
    TRANSACTION_INCOME_SALARY,
    TRANSACTION_INCOME_BONUS,
    TRANSACTION_INCOME_INTEREST,
    TRANSACTION_INCOME_DIVIDEND,
    TRANSACTION_EXPENSE_FOOD,
    TRANSACTION_EXPENSE_RENT,
    TRANSACTION_EXPENSE_UTILITIES,
    TRANSACTION_EXPENSE_GAS,
    TRANSACTION_EXPENSE_PET,
    TRANSACTION_EXPENSE_VET,
    TRANSACTION_EXPENSE_ENTERTAINMENT,
    TRANSACTION_EXPENSE_CLOTHES,
    TRANSACTION_EXPENSE_MEDICINE,
    TRANSACTION_EXPENSE_EDUCATION,
    TRANSACTION_EXPENSE_TAX,
    TRANSACTION_EXPENSE_INSURANCE,
    TRANSACTION_TRANSFER_TO_DEPOSIT,
    TRANSACTION_TRANSFER_FROM_DEPOSIT,
    TRANSACTION_CREDIT_PAYMENT,
    TRANSACTION_CREDIT_INTEREST
};

struct Transaction {
    char id[37];                    // UUID
    time_t timestamp;
    enum TransactionType type;
    long long amount;               // в копейках
    char description[200];
    char category[50];
    char counterparty[100];         // контрагент (магазин, банк и т.д.)
    struct Transaction* next;       // для связного списка
};

struct TransactionHistory {
    struct Transaction* head;
    struct Transaction* tail;
    int count;

    // Функции
    void (*add)(struct TransactionHistory*, enum TransactionType, long long, const char*, const char*);
    void (*print_last)(struct TransactionHistory*, int);
    long long (*get_sum_by_type)(struct TransactionHistory*, enum TransactionType);
    long long (*get_sum_by_category)(struct TransactionHistory*, const char*);
    void (*export_to_csv)(struct TransactionHistory*, const char* filename);
    void (*clear)(struct TransactionHistory*);
};

void transaction_add(struct TransactionHistory* h, enum TransactionType type,
    long long amount, const char* description, const char* counterparty) {
    struct Transaction* t = (struct Transaction*)malloc(sizeof(struct Transaction));

    // Генерация простого ID
    static int counter = 0;
    snprintf(t->id, 37, "TXN-%d-%ld", counter++, time(NULL));

    t->timestamp = time(NULL);
    t->type = type;
    t->amount = amount;
    strncpy(t->description, description, 199);
    strncpy(t->category, description, 49);  // упрощенно
    strncpy(t->counterparty, counterparty, 99);
    t->next = NULL;

    if (!h->head) {
        h->head = t;
        h->tail = t;
    }
    else {
        h->tail->next = t;
        h->tail = t;
    }
    h->count++;
}

void transaction_print_last(struct TransactionHistory* h, int n) {
    struct Transaction* curr = h->head;
    int total = h->count;
    int skip = total - n;
    if (skip < 0) skip = 0;

    for (int i = 0; i < skip && curr; i++) curr = curr->next;

    printf("\n=== Последние %d транзакций ===\n", n);
    while (curr) {
        char time_str[64];
        struct tm* tm_info = localtime(&curr->timestamp);
        strftime(time_str, 64, "%Y-%m-%d %H:%M:%S", tm_info);

        printf("[%s] %s: %.2f руб - %s (%s)\n",
            time_str,
            curr->type < 10 ? "ДОХОД " : "РАСХОД",
            curr->amount / 100.0,
            curr->description,
            curr->counterparty);
        curr = curr->next;
    }
}

long long transaction_get_sum_by_type(struct TransactionHistory* h, enum TransactionType type) {
    long long sum = 0;
    struct Transaction* curr = h->head;
    while (curr) {
        if (curr->type == type) sum += curr->amount;
        curr = curr->next;
    }
    return sum;
}

void transaction_clear(struct TransactionHistory* h) {
    struct Transaction* curr = h->head;
    while (curr) {
        struct Transaction* next = curr->next;
        free(curr);
        curr = next;
    }
    h->head = h->tail = NULL;
    h->count = 0;
}

#endif

#ifndef BUDGET_H
#define BUDGET_H

struct BudgetCategory {
    char name[50];
    long long planned;          
    long long actual;           
    long long limit;            
    int is_flexible;            
    struct BudgetCategory* next;
};

struct MonthlyBudget {
    int year;
    int month;
    long long total_income_planned;
    long long total_income_actual;
    long long total_expense_planned;
    long long total_expense_actual;
    long long savings_planned;
    long long savings_actual;
    struct BudgetCategory* categories;

    void (*init)(struct MonthlyBudget*, int, int);
    void (*add_category)(struct MonthlyBudget*, const char*, long long, long long);
    void (*record_expense)(struct MonthlyBudget*, const char*, long long);
    void (*analyze)(struct MonthlyBudget*);
    void (*print_report)(struct MonthlyBudget*);
};

void budget_init(struct MonthlyBudget* b, int year, int month) {
    b->year = year;
    b->month = month;
    b->total_income_planned = 0;
    b->total_income_actual = 0;
    b->total_expense_planned = 0;
    b->total_expense_actual = 0;
    b->savings_planned = 0;
    b->savings_actual = 0;
    b->categories = NULL;
}

void budget_add_category(struct MonthlyBudget* b, const char* name, long long planned, long long limit) {
    struct BudgetCategory* cat = (struct BudgetCategory*)malloc(sizeof(struct BudgetCategory));
    strncpy(cat->name, name, 49);
    cat->planned = planned;
    cat->actual = 0;
    cat->limit = limit;
    cat->is_flexible = (limit == 0);
    cat->next = b->categories;
    b->categories = cat;

    b->total_expense_planned += planned;
}

void budget_record_expense(struct MonthlyBudget* b, const char* category, long long amount) {
    struct BudgetCategory* curr = b->categories;
    while (curr) {
        if (strcmp(curr->name, category) == 0) {
            curr->actual += amount;
            b->total_expense_actual += amount;

            if (!curr->is_flexible && curr->actual > curr->limit) {
                printf("   ПРЕВЫШЕНИЕ ЛИМИТА по категории '%s': %.2f / %.2f руб\n",
                    curr->name, curr->actual / 100.0, curr->limit / 100.0);
            }
            return;
        }
        curr = curr->next;
    }
}

void budget_print_report(struct MonthlyBudget* b) {
    printf("\n БЮДЖЕТНЫЙ ОТЧЕТ: %d/%d\n", b->month, b->year);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf(" ДОХОДЫ:\n");
    printf("   План: %.2f руб\n", b->total_income_planned / 100.0);
    printf("   Факт: %.2f руб\n", b->total_income_actual / 100.0);

    printf("\n РАСХОДЫ:\n");
    struct BudgetCategory* curr = b->categories;
    while (curr) {
        printf("   %-20s: план %.2f | факт %.2f",
            curr->name, curr->planned / 100.0, curr->actual / 100.0);
        if (!curr->is_flexible) {
            printf(" | лимит %.2f", curr->limit / 100.0);
            if (curr->actual > curr->limit) printf(" ⚠️");
        }
        printf("\n");
        curr = curr->next;
    }

    printf("\n СБЕРЕЖЕНИЯ:\n");
    printf("   План: %.2f руб\n", b->savings_planned / 100.0);
    printf("   Факт: %.2f руб\n", b->savings_actual / 100.0);

    long long variance = b->total_income_actual - b->total_expense_actual;
    printf("\n ИТОГ: %s%.2f руб\n", variance >= 0 ? "+" : "", variance / 100.0);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

#endif

#ifndef INSURANCE_H
#define INSURANCE_H

enum InsuranceType {
    INSURANCE_HEALTH,
    INSURANCE_CAR,
    INSURANCE_HOME,
    INSURANCE_LIFE,
    INSURANCE_TRAVEL
};

struct InsurancePolicy {
    char policy_number[50];
    enum InsuranceType type;
    long long insured_amount;
    long long monthly_premium;
    long long paid_to_date;
    int start_year;
    int start_month;
    int duration_years;
    int is_active;

    struct InsurancePolicy* next;
};

struct InsurancePortfolio {
    struct InsurancePolicy* policies;
    long long total_monthly_premium;

    void (*add_policy)(struct InsurancePortfolio*, enum InsuranceType, long long, long long, int);
    void (*pay_monthly)(struct InsurancePortfolio*, struct Bank*);
    void (*check_expiry)(struct InsurancePortfolio*, int, int);
    void (*print_summary)(struct InsurancePortfolio*);
};

void insurance_add_policy(struct InsurancePortfolio* p, enum InsuranceType type,
    long long insured_amount, long long monthly_premium, int duration_years) {
    struct InsurancePolicy* policy = (struct InsurancePolicy*)malloc(sizeof(struct InsurancePolicy));

    static int policy_counter = 0;
    snprintf(policy->policy_number, 50, "INS-%d-%d", type, policy_counter++);

    policy->type = type;
    policy->insured_amount = insured_amount;
    policy->monthly_premium = monthly_premium;
    policy->paid_to_date = 0;
    policy->start_year = 2024;
    policy->start_month = 1;
    policy->duration_years = duration_years;
    policy->is_active = 1;
    policy->next = p->policies;
    p->policies = policy;
    p->total_monthly_premium += monthly_premium;

    const char* type_names[] = { "Медицинская", "Авто", "Жилье", "Жизнь", "Туристическая" };
    printf(" Добавлен полис %s: страховая сумма %.2f руб, премия %.2f руб/мес\n",
        type_names[type], insured_amount / 100.0, monthly_premium / 100.0);
}

void insurance_pay_monthly(struct InsurancePortfolio* p, struct Bank* bank) {
    if (bank->current_account >= p->total_monthly_premium) {
        bank->current_account -= p->total_monthly_premium;

        struct InsurancePolicy* curr = p->policies;
        while (curr) {
            curr->paid_to_date += curr->monthly_premium;
            curr = curr->next;
        }

        printf("  Оплачены страховки: %.2f руб\n", p->total_monthly_premium / 100.0);
    }
    else {
        printf("   НЕДОСТАТОЧНО СРЕДСТВ для оплаты страховок!\n");
    }
}

void insurance_print_summary(struct InsurancePortfolio* p) {
    printf("\n СТРАХОВОЙ ПОРТФЕЛЬ\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    struct InsurancePolicy* curr = p->policies;
    const char* type_names[] = { "Медицинская", "Авто", "Жилье", "Жизнь", "Туристическая" };

    while (curr) {
        printf("№%s: %s\n", curr->policy_number, type_names[curr->type]);
        printf("   Страховая сумма: %.2f руб\n", curr->insured_amount / 100.0);
        printf("   Премия: %.2f руб/мес\n", curr->monthly_premium / 100.0);
        printf("   Оплачено: %.2f руб\n", curr->paid_to_date / 100.0);
        printf("   Статус: %s\n", curr->is_active ? "Активен" : "Завершен");
        printf("   ─────────────────────────\n");
        curr = curr->next;
    }

    printf("Всего премий в месяц: %.2f руб\n", p->total_monthly_premium / 100.0);
}

#endif

#ifndef INVESTMENT_H
#define INVESTMENT_H

enum InvestmentType {
    INVEST_STOCKS,      
    INVEST_BONDS,       
    INVEST_ETF,         
    INVEST_REAL_ESTATE, 
    INVEST_GOLD,        
    INVEST_CRYPTO       
};

struct InvestmentAsset {
    char name[100];
    enum InvestmentType type;
    long long shares;           
    long long price_per_unit;   
    long long total_value;      
    long long purchase_value;   
    float annual_yield;         
    float risk_level;           
    int purchase_year;
    int purchase_month;

    struct InvestmentAsset* next;
};

struct InvestmentPortfolio {
    struct InvestmentAsset* assets;
    long long total_value;
    long long total_invested;
    float total_yield_percent;

    void (*add_asset)(struct InvestmentPortfolio*, const char*, enum InvestmentType,
        long long, long long, float, float);
    void (*update_prices)(struct InvestmentPortfolio*, float market_growth);
    void (*rebalance)(struct InvestmentPortfolio*);
    void (*print_portfolio)(struct InvestmentPortfolio*);
    void (*sell_asset)(struct InvestmentPortfolio*, const char*, long long, struct Bank*);
};

void investment_add_asset(struct InvestmentPortfolio* p, const char* name, enum InvestmentType type,
    long long shares, long long price, float yield, float risk) {
    struct InvestmentAsset* asset = (struct InvestmentAsset*)malloc(sizeof(struct InvestmentAsset));

    strncpy(asset->name, name, 99);
    asset->type = type;
    asset->shares = shares;
    asset->price_per_unit = price;
    asset->total_value = shares * price;
    asset->purchase_value = shares * price;
    asset->annual_yield = yield;
    asset->risk_level = risk;
    asset->purchase_year = 2024;
    asset->purchase_month = 1;
    asset->next = p->assets;
    p->assets = asset;
    p->total_invested += asset->total_value;
    p->total_value += asset->total_value;

    const char* type_names[] = { "Акции", "Облигации", "ETF", "Недвижимость", "Золото", "Крипто" };
    printf("  Инвестиция: %s (%s) - %.2f руб, доходность %.1f%%\n",
        name, type_names[type], asset->total_value / 100.0, yield);
}

void investment_update_prices(struct InvestmentPortfolio* p, float market_growth) {
    p->total_value = 0;
    struct InvestmentAsset* curr = p->assets;

    while (curr) {
        // Изменение цены с учетом рыночного роста и риск-фактора
        float asset_growth = market_growth * (1 + (curr->risk_level - 0.5) * 0.5);
        curr->price_per_unit += curr->price_per_unit * asset_growth;
        curr->total_value = curr->shares * curr->price_per_unit;
        p->total_value += curr->total_value;

        curr = curr->next;
    }

    p->total_yield_percent = ((float)(p->total_value - p->total_invested) / p->total_invested) * 100;
}

void investment_print_portfolio(struct InvestmentPortfolio* p) {
    printf("\n ИНВЕСТИЦИОННЫЙ ПОРТФЕЛЬ\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    struct InvestmentAsset* curr = p->assets;
    const char* type_names[] = { "Акции", "Облигации", "ETF", "Недвижимость", "Золото", "Крипто" };

    while (curr) {
        float yield_pct = ((float)(curr->total_value - curr->purchase_value) / curr->purchase_value) * 100;

        printf("%s (%s):\n", curr->name, type_names[curr->type]);
        printf("  Количество: %lld\n", curr->shares);
        printf("  Цена: %.2f руб\n", curr->price_per_unit / 100.0);
        printf("  Стоимость: %.2f руб\n", curr->total_value / 100.0);
        printf("  Доходность: %.2f%% (%+.2f%%)\n", curr->annual_yield, yield_pct);
        printf("  Риск: %.0f%%\n", curr->risk_level * 100);
        printf("  ───────────────────────────────────────────────────\n");
        curr = curr->next;
    }

    printf("\n ИТОГО:\n");
    printf("  Инвестировано: %.2f руб\n", p->total_invested / 100.0);
    printf("  Текущая стоимость: %.2f руб\n", p->total_value / 100.0);
    printf("  Доходность: %.2f%%\n", p->total_yield_percent);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

#endif

#ifndef CREDIT_HISTORY_H
#define CREDIT_HISTORY_H

struct CreditRecord {
    char creditor[100];
    long long amount;
    long long remaining;
    float interest_rate;
    int start_month;
    int start_year;
    int term_months;
    int payments_made;
    long long monthly_payment;
    int is_closed;

    struct CreditRecord* next;
};

struct CreditHistory {
    struct CreditRecord* loans;
    struct CreditRecord* credit_cards;
    int credit_score;           // 300-850
    long long total_debt;
    long long available_credit;

    void (*add_loan)(struct CreditHistory*, const char*, long long, float, int);
    void (*add_credit_card)(struct CreditHistory*, const char*, long long);
    void (*make_payment)(struct CreditHistory*, const char*, long long, struct Bank*);
    void (*calculate_score)(struct CreditHistory*);
    void (*print_report)(struct CreditHistory*);
};

void credit_add_loan(struct CreditHistory* ch, const char* creditor, long long amount,
    float rate, int term_months) {
    struct CreditRecord* loan = (struct CreditRecord*)malloc(sizeof(struct CreditRecord));

    strncpy(loan->creditor, creditor, 99);
    loan->amount = amount;
    loan->remaining = amount;
    loan->interest_rate = rate;
    loan->start_month = 1;
    loan->start_year = 2024;
    loan->term_months = term_months;
    loan->payments_made = 0;
    loan->is_closed = 0;

    
    float monthly_rate = rate / 12.0 / 100.0;
    loan->monthly_payment = amount * (monthly_rate * pow(1 + monthly_rate, term_months)) /
        (pow(1 + monthly_rate, term_months) - 1);

    loan->next = ch->loans;
    ch->loans = loan;
    ch->total_debt += amount;

    printf("  Выдан кредит от %s: %.2f руб, %.1f%%, %d мес, платеж %.2f руб/мес\n",
        creditor, amount / 100.0, rate, term_months, loan->monthly_payment / 100.0);
}

void credit_make_payment(struct CreditHistory* ch, const char* creditor,
    long long amount, struct Bank* bank) {
    struct CreditRecord* curr = ch->loans;
    while (curr) {
        if (strcmp(curr->creditor, creditor) == 0 && !curr->is_closed) {
            if (bank->current_account >= amount) {
                bank->current_account -= amount;
                curr->remaining -= amount;
                curr->payments_made++;

                printf("  Платеж по кредиту %s: %.2f руб, остаток %.2f руб\n",
                    creditor, amount / 100.0, curr->remaining / 100.0);

                if (curr->remaining <= 0) {
                    curr->is_closed = 1;
                    printf("   Кредит %s полностью погашен!\n", creditor);
                }
            }
            else {
                printf("   НЕДОСТАТОЧНО СРЕДСТВ для платежа по кредиту!\n");
            }
            return;
        }
        curr = curr->next;
    }
}

void credit_calculate_score(struct CreditHistory* ch) {
    int score = 700;  

   
    int active_loans = 0;
    struct CreditRecord* curr = ch->loans;
    while (curr) {
        if (!curr->is_closed) active_loans++;
        curr = curr->next;
    }

    score -= (active_loans - 1) * 30;  

    float debt_ratio = (float)ch->total_debt / (ch->available_credit + 1);
    if (debt_ratio > 0.5) score -= 50;
    if (debt_ratio > 0.8) score -= 80;

    ch->credit_score = score < 300 ? 300 : (score > 850 ? 850 : score);
}

void credit_print_report(struct CreditHistory* ch) {
    printf("\n КРЕДИТНАЯ ИСТОРИЯ\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Кредитный рейтинг: %d (%s)\n", ch->credit_score,
        ch->credit_score >= 700 ? "Отлично" :
        (ch->credit_score >= 600 ? "Хорошо" : "Требует улучшения"));
    printf("Общий долг: %.2f руб\n", ch->total_debt / 100.0);
    printf("Доступный кредит: %.2f руб\n", ch->available_credit / 100.0);
    printf("\nАктивные кредиты:\n");

    struct CreditRecord* curr = ch->loans;
    while (curr) {
        if (!curr->is_closed) {
            printf("  • %s: %.2f руб, %.1f%%, осталось %d/%d мес\n",
                curr->creditor, curr->remaining / 100.0, curr->interest_rate,
                curr->term_months - curr->payments_made, curr->term_months);
        }
        curr = curr->next;
    }
}
#endif

#ifndef EXPANDED_PERSON_H
#define EXPANDED_PERSON_H


struct ExpandedPerson {
    
    char name[50];
    int age;
    char gender[10];
    char profession[50];
    char education[100];
    int experience_years;

    
    long long salary;
    long long bonus;                    
    long long side_income;              
    struct Bank* primary_bank;
    struct Bank* secondary_bank;        

    
    struct Car* cars[3];                
    int car_count;
    struct Pet* pets[5];                
    int pet_count;
    struct Housing* primary_housing;
    struct Housing* investment_housing[3];  
    int investment_property_count;

    // Финансовые инструменты
    struct InvestmentPortfolio* portfolio;
    struct InsurancePortfolio* insurance;
    struct CreditHistory* credit_history;
    struct TransactionHistory* transactions;
    struct MonthlyBudget* budget;

    
    struct FinancialGoal {
        char name[100];
        long long target_amount;
        long long current_amount;
        int target_year;
        int priority;  
        int is_achieved;
    } goals[10];
    int goal_count;

    // Психологические факторы
    float risk_tolerance;               // 0-1
    float financial_literacy;           // 0-1
    float spending_habit;               // 0=экономный, 1=транжира

   
    int health_status;                  
    long long medical_expenses;
    int has_medical_insurance;

    
    struct ExpandedPerson* friends[10];
    int friend_count;
    struct ExpandedPerson* spouse;
    struct ExpandedPerson* children[5];
    int child_count;

    
    void (*work)(struct ExpandedPerson*, int, int);
    void (*pay_bills)(struct ExpandedPerson*);
    void (*manage_finances)(struct ExpandedPerson*);
    void (*invest)(struct ExpandedPerson*);
    void (*make_goal_progress)(struct ExpandedPerson*);
    void (*health_check)(struct ExpandedPerson*);
    void (*social_interaction)(struct ExpandedPerson*);
    void (*learn)(struct ExpandedPerson*);  // повышение фин. грамотности
    void (*print_wealth_report)(struct ExpandedPerson*);
};


void expanded_person_work(struct ExpandedPerson* p, int month, int year) {
    long long total_income = p->salary;

    
    if (month == 12 && p->bonus > 0) {
        total_income += p->bonus;
        printf("   %s получил годовую премию: %.2f руб\n",
            p->name, p->bonus / 100.0);
    }

    
    if (p->side_income > 0 && (month % 3 == 0)) { 
        total_income += p->side_income;
        printf("   %s получил дополнительный доход: %.2f руб\n",
            p->name, p->side_income / 100.0);
    }

    
    long long tax = total_income * INCOME_TAX_RATE;
    long long net_income = total_income - tax;

    p->primary_bank->current_account += net_income;

    
    p->transactions->add(p->transactions, TRANSACTION_INCOME_SALARY, net_income,
        "Зарплата", p->primary_bank->name);

    printf("  %s: зарплата %.2f руб (налог %.2f руб), получено %.2f руб\n",
        p->name, total_income / 100.0, tax / 100.0, net_income / 100.0);
}

void expanded_person_invest(struct ExpandedPerson* p) {
    // Автоматическое инвестирование 20% от текущего счета
    if (p->primary_bank->current_account > 10000 * 100) {
        long long to_invest = p->primary_bank->current_account * 0.2;
        if (to_invest > 0 && p->portfolio) {
            p->primary_bank->transfer_to_deposit(p->primary_bank, to_invest);

            // Часть переводим в инвестиционный портфель
            p->portfolio->update_prices(p->portfolio, 0.02);  // +2% рыночный рост
        }
    }
}

void expanded_person_make_goal_progress(struct ExpandedPerson* p) {
    for (int i = 0; i < p->goal_count; i++) {
        if (!p->goals[i].is_achieved) {
            
            long long monthly_saving = p->goals[i].target_amount /
                ((p->goals[i].target_year - 2024) * 12);

            if (p->primary_bank->current_account >= monthly_saving) {
                p->primary_bank->current_account -= monthly_saving;
                p->goals[i].current_amount += monthly_saving;

                if (p->goals[i].current_amount >= p->goals[i].target_amount) {
                    p->goals[i].is_achieved = 1;
                    printf("   ЦЕЛЬ ДОСТИГНУТА: %s!\n", p->goals[i].name);
                }
            }
        }
    }
}

void expanded_person_health_check(struct ExpandedPerson* p) {
    // Случайные проблемы со здоровьем
    int rand_health = rand() % 100;
    if (rand_health < 5 && p->health_status > 0) {  // 5% вероятность
        long long medical_cost = (5000 + rand() % 50000) * 100;

        if (p->has_medical_insurance && p->insurance) {
            
            long long covered = medical_cost * 0.8;
            medical_cost -= covered;
            printf("   Страховка покрыла %.2f руб медицинских расходов\n", covered / 100.0);
        }

        p->primary_bank->current_account -= medical_cost;
        p->medical_expenses += medical_cost;
        p->health_status -= 10;

        printf("   %s: медицинские расходы %.2f руб\n",
            p->name, medical_cost / 100.0);
    }

    
    if (p->health_status < 100) {
        p->health_status += 2;
        if (p->health_status > 100) p->health_status = 100;
    }
}

void expanded_person_learn(struct ExpandedPerson* p) {
    
    if (p->financial_literacy < 1.0) {
        p->financial_literacy += 0.005;
        if (p->financial_literacy > 1.0) p->financial_literacy = 1.0;
    }

    
    if (p->financial_literacy > 0.8 && (rand() % 100) < 3) {
        p->salary += p->salary * 0.05;
        printf("   %s повысил финансовую грамотность! Зарплата увеличена до %.2f руб\n",
            p->name, p->salary / 100.0);
    }
}

void expanded_person_print_wealth_report(struct ExpandedPerson* p) {
    printf("\n╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                ФИНАНСОВЫЙ ОТЧЕТ: %-30s ║\n", p->name);
    printf("╠══════════════════════════════════════════════════════════════╣\n");

    long long total_assets = p->primary_bank->current_account + p->primary_bank->deposit;
    if (p->portfolio) total_assets += p->portfolio->total_value;
    for (int i = 0; i < p->car_count; i++) {
        if (p->cars[i]) total_assets += p->cars[i]->value;
    }

    long long total_liabilities = 0;
    if (p->credit_history) total_liabilities += p->credit_history->total_debt;
    if (p->primary_housing && p->primary_housing->is_mortgage) {
        total_liabilities += p->primary_housing->mortgage_debt;
    }

    long long net_worth = total_assets - total_liabilities;

    printf("║ АКТИВЫ:\n");
    printf("║    Текущий счет: %20.2f руб\n", p->primary_bank->current_account / 100.0);
    printf("║    Депозит:        %20.2f руб\n", p->primary_bank->deposit / 100.0);
    printf("║    Инвестиции:     %20.2f руб\n",
        p->portfolio ? p->portfolio->total_value / 100.0 : 0.0);
    printf("║    Автомобили:     %20.2f руб\n",
        (p->car_count > 0 && p->cars[0]) ? p->cars[0]->value / 100.0 : 0.0);
    printf("║    Недвижимость:   %20.2f руб\n",
        (p->primary_housing && p->primary_housing->is_mortgage) ?
        p->primary_housing->apartment_value / 100.0 : 0.0);
    printf("║   ИТОГО АКТИВЫ:     %20.2f руб\n", total_assets / 100.0);
    printf("║\n");
    printf("║ ПАССИВЫ:\n");
    printf("║    Кредиты:        %20.2f руб\n",
        p->credit_history ? p->credit_history->total_debt / 100.0 : 0.0);
    printf("║    Ипотека:        %20.2f руб\n",
        (p->primary_housing && p->primary_housing->is_mortgage) ?
        p->primary_housing->mortgage_debt / 100.0 : 0.0);
    printf("║   ИТОГО ПАССИВЫ:    %20.2f руб\n", total_liabilities / 100.0);
    printf("║\n");
    printf("║ ════════════════════════════════════════════════════════════\n");
    printf("║  ЧИСТЫЙ КАПИТАЛ:  %20.2f руб\n", net_worth / 100.0);
    printf("║\n");
    printf("║  МЕТРИКИ:\n");
    printf("║   Финансовая грамотность: %5.1f%%\n", p->financial_literacy * 100);
    printf("║   Склонность к риску:     %5.1f%%\n", p->risk_tolerance * 100);
    printf("║   Здоровье:               %5.1f%%\n", p->health_status / 100.0);
    printf("║   Кредитный рейтинг:      %d\n",
        p->credit_history ? p->credit_history->credit_score : 0);
    printf("╚══════════════════════════════════════════════════════════════╝\n");
}

#endif

#ifndef TAX_SYSTEM_H
#define TAX_SYSTEM_H

// Типы налогов
enum TaxType {
    TAX_INCOME,           
    TAX_PROPERTY,         
    TAX_TRANSPORT,        
    TAX_LAND,             
    TAX_DIVIDEND,         
    TAX_CAPITAL_GAINS,    
    TAX_SELF_EMPLOYED,    
    TAX_VAT               
};

struct TaxDeduction {
    char name[100];
    enum TaxType tax_type;
    long long max_amount;
    long long used_amount;
    int is_social;          
    int is_property;        
    int is_investment;      

    void (*apply)(struct TaxDeduction*, long long amount);
    void (*reset_yearly)(struct TaxDeduction*);
};

struct TaxReturn {
    int year;
    long long total_income;
    long long total_deductions;
    long long taxable_income;
    long long tax_calculated;
    long long tax_paid;
    long long tax_refund;           
    long long tax_additional;       
    int is_filed;
    time_t filing_date;

    struct TaxDeduction* deductions[20];
    int deduction_count;

    void (*calculate)(struct TaxReturn*);
    void (*file)(struct TaxReturn*, struct Bank*);
    void (*print)(struct TaxReturn*);
};

struct TaxAuthority {
    char name[50];
    long long total_collected;
    long long total_refunds;
    int audit_rate;                 

    void (*collect_tax)(struct TaxAuthority*, struct Person*, enum TaxType, long long);
    void (*perform_audit)(struct TaxAuthority*, struct Person*);
    void (*issue_fine)(struct TaxAuthority*, struct Person*, long long, const char*);
    void (*print_annual_report)(struct TaxAuthority*, int year);
};


void tax_deduction_apply(struct TaxDeduction* td, long long amount) {
    long long remaining = td->max_amount - td->used_amount;
    long long to_use = amount < remaining ? amount : remaining;
    td->used_amount += to_use;
}

void tax_return_calculate(struct TaxReturn* tr) {
    tr->taxable_income = tr->total_income - tr->total_deductions;
    if (tr->taxable_income < 0) tr->taxable_income = 0;

    
    if (tr->taxable_income <= 5'000'000 * 100) {
        tr->tax_calculated = tr->taxable_income * 0.13;
    }
    else {
        tr->tax_calculated = 5'000'000 * 100 * 0.13 +
            (tr->taxable_income - 5'000'000 * 100) * 0.15;
    }

    tr->tax_refund = (tr->tax_paid > tr->tax_calculated) ?
        (tr->tax_paid - tr->tax_calculated) : 0;
    tr->tax_additional = (tr->tax_calculated > tr->tax_paid) ?
        (tr->tax_calculated - tr->tax_paid) : 0;
}

void tax_return_file(struct TaxReturn* tr, struct Bank* bank) {
    tr->is_filed = 1;
    tr->filing_date = time(NULL);

    if (tr->tax_refund > 0) {
        bank->current_account += tr->tax_refund;
        printf("  Возврат налога: +%.2f руб\n", tr->tax_refund / 100.0);
    }

    if (tr->tax_additional > 0) {
        if (bank->current_account >= tr->tax_additional) {
            bank->current_account -= tr->tax_additional;
            printf("  Доплата налога: -%.2f руб\n", tr->tax_additional / 100.0);
        }
        else {
            printf("   Недостаточно средств для доплаты налога!\n");
        }
    }
}

void tax_return_print(struct TaxReturn* tr) {
    printf("\n НАЛОГОВАЯ ДЕКЛАРАЦИЯ %d\n", tr->year);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Общий доход:        %.2f руб\n", tr->total_income / 100.0);
    printf("Налоговые вычеты:   %.2f руб\n", tr->total_deductions / 100.0);
    printf("Налогооблагаемая база: %.2f руб\n", tr->taxable_income / 100.0);
    printf("Налог к уплате:     %.2f руб\n", tr->tax_calculated / 100.0);
    printf("Уплачено за год:    %.2f руб\n", tr->tax_paid / 100.0);
    printf("К возврату:         %.2f руб\n", tr->tax_refund / 100.0);
    printf("К доплате:          %.2f руб\n", tr->tax_additional / 100.0);
    printf("Статус: %s\n", tr->is_filed ? "Декларация подана" : "Не подана");
}

void tax_authority_collect(struct TaxAuthority* ta, struct Person* p,
    enum TaxType type, long long amount) {
    if (p->bank && p->bank->current_account >= amount) {
        p->bank->current_account -= amount;
        ta->total_collected += amount;
        printf("  %s: уплачен налог %.2f руб\n", p->name, amount / 100.0);
    }
    else {
        printf("   %s: недостаточно средств для уплаты налога!\n", p->name);
        
        long long penalty = amount * 0.01;
        ta->total_collected += penalty;
        printf("  Начислена пеня: %.2f руб\n", penalty / 100.0);
    }
}

#endif
#ifndef EDUCATION_CAREER_H
#define EDUCATION_CAREER_H

enum EducationLevel {
    ED_NO_EDUCATION,
    ED_SCHOOL,
    ED_COLLEGE,
    ED_BACHELOR,
    ED_MASTER,
    ED_PHD,
    ED_MBA
};

struct Education {
    enum EducationLevel level;
    char institution[100];
    char specialization[100];
    int start_year;
    int end_year;
    long long total_cost;
    long long paid;
    int is_completed;

    void (*complete)(struct Education*, struct Person*);
    float (*salary_bonus)(struct Education*);  
};

struct Skill {
    char name[50];
    int level;              
    int years_experience;
    float market_demand;    
    float salary_multiplier;

    void (*improve)(struct Skill*, int months);
    void (*certify)(struct Skill*, struct Person*);
};

struct Career {
    char company[100];
    char position[100];
    int start_year;
    int start_month;
    int end_year;
    int end_month;
    long long start_salary;
    long long end_salary;
    int is_current;

    struct Career* next;
};

struct CareerPath {
    struct Career* history;
    int total_jobs;
    int years_experience_total;
    float loyalty_factor;       // лояльность к работодателю

    void (*add_job)(struct CareerPath*, const char*, const char*, int, int, long long);
    void (*promotion)(struct CareerPath*, struct Person*);
    void (*change_job)(struct CareerPath*, struct Person*, const char*, const char*, long long);
    void (*calculate_experience)(struct CareerPath*);
    void (*print_career)(struct CareerPath*);
};


float education_salary_bonus(struct Education* e) {
    switch (e->level) {
    case ED_NO_EDUCATION: return 1.0;
    case ED_SCHOOL: return 1.1;
    case ED_COLLEGE: return 1.2;
    case ED_BACHELOR: return 1.4;
    case ED_MASTER: return 1.6;
    case ED_PHD: return 1.8;
    case ED_MBA: return 2.0;
    default: return 1.0;
    }
}

void education_complete(struct Education* e, struct Person* p) {
    e->is_completed = 1;
    float bonus = e->salary_bonus(e);
    p->salary = p->salary * bonus;
    printf("   %s завершил образование! Зарплата увеличена до %.2f руб\n",
        p->name, p->salary / 100.0);
}

void skill_improve(struct Skill* s, int months) {
    int increase = months * (rand() % 5 + 1);
    s->level += increase;
    if (s->level > 100) s->level = 100;

    if (increase > 0) {
        printf("   Навык '%s' повышен до %d\n", s->name, s->level);
    }
}

void career_add_job(struct CareerPath* cp, const char* company, const char* position,
    int year, int month, long long salary) {
    struct Career* new_job = (struct Career*)malloc(sizeof(struct Career));
    strcpy(new_job->company, company);
    strcpy(new_job->position, position);
    new_job->start_year = year;
    new_job->start_month = month;
    new_job->start_salary = salary;
    new_job->end_salary = salary;
    new_job->is_current = 1;
    new_job->next = cp->history;

    
    if (cp->history && cp->history->is_current) {
        cp->history->is_current = 0;
        cp->history->end_year = year;
        cp->history->end_month = month;
    }

    cp->history = new_job;
    cp->total_jobs++;
}

void career_promotion(struct CareerPath* cp, struct Person* p) {
    if (cp->history && cp->history->is_current) {
        long long increase = p->salary * 0.15;  
        p->salary += increase;
        cp->history->end_salary = p->salary;
        printf("   %s получил повышение! Новая зарплата: %.2f руб\n",
            p->name, p->salary / 100.0);
    }
}

void career_change_job(struct CareerPath* cp, struct Person* p,
    const char* new_company, const char* new_position, long long new_salary) {
    career_add_job(cp, new_company, new_position,
        p->current_year, p->current_month, new_salary);
    p->salary = new_salary;
    printf("   %s сменил работу: %s -> %s\n", p->name,
        cp->history->next ? cp->history->next->company : "Первая работа", new_company);
}

void career_print(struct CareerPath* cp) {
    printf("\n КАРЬЕРНЫЙ ПУТЬ\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Всего мест работы: %d\n", cp->total_jobs);
    printf("Общий опыт: %d лет\n", cp->years_experience_total);

    struct Career* curr = cp->history;
    int num = 1;
    while (curr) {
        printf("%d. %s - %s (%d-%d)\n", num++, curr->company, curr->position,
            curr->start_year, curr->end_year ? curr->end_year : curr->start_year);
        printf("   Зарплата: %.2f руб -> %.2f руб\n",
            curr->start_salary / 100.0, curr->end_salary / 100.0);
        curr = curr->next;
    }
}

#endif

#ifndef TRAVEL_LEISURE_H
#define TRAVEL_LEISURE_H

enum TravelType {
    TRAVEL_VACATION,
    TRAVEL_BUSINESS,
    TRAVEL_EDUCATION,
    TRAVEL_MEDICAL
};

struct Trip {
    char destination[100];
    enum TravelType type;
    int start_day;
    int start_month;
    int start_year;
    int duration_days;
    long long total_cost;
    long long paid;
    int satisfaction;           

    struct Trip* next;
};

struct TravelHistory {
    struct Trip* trips;
    int total_trips;
    long long total_spent;

    void (*add_trip)(struct TravelHistory*, const char*, enum TravelType,
        int, int, long long);
    void (*plan_trip)(struct TravelHistory*, struct Person*, int month);
    void (*print_travel_log)(struct TravelHistory*);
};

struct Leisure {
    char activity[50];
    long long monthly_cost;
    int hours_per_week;
    int satisfaction_boost;
    int is_active;

    void (*do_activity)(struct Leisure*, struct Person*);
    void (*upgrade)(struct Leisure*, long long cost);
};


void travel_add_trip(struct TravelHistory* th, const char* dest, enum TravelType type,
    int days, int satisfaction, long long cost) {
    struct Trip* trip = (struct Trip*)malloc(sizeof(struct Trip));
    strcpy(trip->destination, dest);
    trip->type = type;
    trip->duration_days = days;
    trip->total_cost = cost;
    trip->satisfaction = satisfaction;
    trip->next = th->trips;
    th->trips = trip;
    th->total_trips++;
    th->total_spent += cost;
}

void travel_plan_trip(struct TravelHistory* th, struct Person* p, int month) {
    
    if (month == 6 || month == 7 || month == 8) {
        long long trip_cost = (50000 + rand() % 100000) * 100;
        const char* destinations[] = { "Турция", "Египет", "Таиланд", "Сочи",
                                       "Крым", "Италия", "Франция" };
        const char* dest = destinations[rand() % 7];

        if (p->bank && p->bank->current_account >= trip_cost) {
            p->bank->current_account -= trip_cost;
            travel_add_trip(th, dest, TRAVEL_VACATION, 14, 85, trip_cost);
            printf("  ✈️ %s отправился в отпуск в %s (%.2f руб)\n",
                p->name, dest, trip_cost / 100.0);
        }
        else {
            printf("   %s не может позволить себе отпуск\n", p->name);
        }
    }
}

void leisure_do_activity(struct Leisure* l, struct Person* p) {
    if (l->is_active && p->bank) {
        p->bank->current_account -= l->monthly_cost;
        printf("   %s занимается %s (+%d к удовлетворенности)\n",
            p->name, l->activity, l->satisfaction_boost);
    }
}

#endif

#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H

struct Relationship {
    struct Person* person;
    char relation_type[30];     
    int closeness;               
    int years_known;
    float influence_factor;      

    void (*interact)(struct Relationship*, struct Person*);
    void (*share_opportunity)(struct Relationship*, struct Person*);
};

struct SocialNetwork {
    struct Relationship** connections;
    int connection_count;
    int max_connections;
    int popularity_score;        

    void (*add_connection)(struct SocialNetwork*, struct Person*, const char*, int);
    void (*remove_connection)(struct SocialNetwork*, struct Person*);
    void (*social_event)(struct SocialNetwork*, struct Person*, int month);
    void (*get_advice)(struct SocialNetwork*, struct Person*, const char* topic);
    void (*print_network)(struct SocialNetwork*);
};


void social_add_connection(struct SocialNetwork* sn, struct Person* p,
    const char* relation, int closeness) {
    if (sn->connection_count >= sn->max_connections) return;

    struct Relationship* rel = (struct Relationship*)malloc(sizeof(struct Relationship));
    rel->person = p;
    strcpy(rel->relation_type, relation);
    rel->closeness = closeness;
    rel->years_known = 0;
    rel->influence_factor = closeness / 100.0;

    sn->connections[sn->connection_count++] = rel;
    sn->popularity_score += 5;
    if (sn->popularity_score > 100) sn->popularity_score = 100;
}

void social_social_event(struct SocialNetwork* sn, struct Person* p, int month) {
    // Новогодние праздники
    if (month == 12) {
        long long event_cost = (10000 + rand() % 30000) * 100;
        if (p->bank && p->bank->current_account >= event_cost) {
            p->bank->current_account -= event_cost;
            printf("   %s организовал вечеринку (%.2f руб)\n",
                p->name, event_cost / 100.0);

            // Новые знакомства
            int new_friends = rand() % 3;
            sn->popularity_score += new_friends * 5;
            printf("   Завел %d новых знакомых!\n", new_friends);
        }
    }
}

void social_get_advice(struct SocialNetwork* sn, struct Person* p, const char* topic) {
    if (strcmp(topic, "investment") == 0 && sn->popularity_score > 60) {
        printf("   %s получил инвестиционный совет от друзей\n", p->name);
        p->financial_literacy += 0.05;
    }
}

#endif

#ifndef MACROECONOMICS_H
#define MACROECONOMICS_H

struct EconomicIndicators {
    float inflation_rate;           
    float cpi_change;               
    float key_rate;                 
    float gdp_growth;               
    float unemployment_rate;       
    float oil_price;                
    float usd_rub_rate;             
    float stock_market_index;       

    void (*update_monthly)(struct EconomicIndicators*, int month, int year);
    void (*apply_economic_shock)(struct EconomicIndicators*);
    void (*print_forecast)(struct EconomicIndicators*);
};

struct MarketTrends {
    float real_estate_growth;        
    float car_market_growth;        
    float food_price_growth;        
    float utilities_growth;         
    float luxury_goods_growth;      

    void (*update_trends)(struct MarketTrends*, struct EconomicIndicators*);
};


void economic_update_indicators(struct EconomicIndicators* e, int month, int year) {
   
    if (month == 12) {
        e->inflation_rate += 0.5;  
    }
    else if (month == 1) {
        e->inflation_rate -= 0.3;  
    }

    
    e->inflation_rate += (rand() % 20 - 10) / 100.0;
    if (e->inflation_rate < 0) e->inflation_rate = 0;
    if (e->inflation_rate > 20) e->inflation_rate = 20;

    
    if (e->inflation_rate > 6) {
        e->key_rate += 0.25;
    }
    else if (e->inflation_rate < 4) {
        e->key_rate -= 0.25;
    }

    
    e->usd_rub_rate = 75.0 + (e->oil_price - 60) * 0.5 + (rand() % 200 - 100) / 100.0;

    
    e->stock_market_index += e->gdp_growth * 10 + (rand() % 100 - 50) / 10.0;
}

void economic_apply_shock(struct EconomicIndicators* e) {
    int shock_type = rand() % 5;

    switch (shock_type) {
    case 0: 
        e->inflation_rate += 5;
        e->gdp_growth -= 3;
        e->stock_market_index -= 20;
        printf("   ФИНАНСОВЫЙ КРИЗИС! Инфляция скакнула до %.1f%%\n", e->inflation_rate);
        break;
    case 1: 
        e->oil_price += 20;
        e->usd_rub_rate -= 10;
        printf("   НЕФТЯНОЙ ШОК! Цена нефти выросла до $%.1f\n", e->oil_price);
        break;
    case 2: 
        e->inflation_rate += 3;
        e->gdp_growth -= 2;
        e->usd_rub_rate += 15;
        printf("   ВВЕДЕНЫ САНКЦИИ! Рубль ослаб до %.2f\n", e->usd_rub_rate);
        break;
    case 3: 
        e->gdp_growth += 2;
        e->stock_market_index += 15;
        printf("   ТЕХНОЛОГИЧЕСКИЙ БУМ! Рынок вырос на %.1f%%\n", e->stock_market_index);
        break;
    case 4: 
        e->gdp_growth -= 4;
        e->unemployment_rate += 3;
        printf("   ПАНДЕМИЯ! Безработица выросла до %.1f%%\n", e->unemployment_rate);
        break;
    }
}

#endif

#ifndef HEALTH_FITNESS_H
#define HEALTH_FITNESS_H

enum FitnessLevel {
    FITNESS_SEDENTARY,
    FITNESS_LIGHT,
    FITNESS_MODERATE,
    FITNESS_ACTIVE,
    FITNESS_ATHLETE
};

struct HealthMetrics {
    int heart_rate;
    int blood_pressure_systolic;
    int blood_pressure_diastolic;
    float bmi;
    int sleep_hours;
    int stress_level;           // 0-100
    int energy_level;           // 0-100

    void (*measure)(struct HealthMetrics*);
    void (*improve)(struct HealthMetrics*, int days);
};

struct Gym {
    char name[50];
    long long monthly_fee;
    long long annual_fee;
    int has_pool;
    int has_sauna;
    int has_personal_trainer;
    float location_quality;

    void (*join)(struct Gym*, struct Person*);
    void (*train)(struct Gym*, struct Person*, int hours);
};

struct Nutrition {
    int calories_per_day;
    int protein_grams;
    int carbs_grams;
    int fat_grams;
    int water_ml;
    int is_healthy;
    long long monthly_cost;

    void (*track_meal)(struct Nutrition*, const char* food, int calories);
    void (*optimize)(struct Nutrition*, struct Person*);
};

struct MedicalHistory {
    struct Disease {
        char name[50];
        int diagnosed_year;
        int is_chronic;
        long long treatment_cost;
        struct Disease* next;
    }*diseases;

    int doctor_visits;
    long long total_medical_cost;
    int sick_days;

    void (*add_disease)(struct MedicalHistory*, const char*, int, int, long long);
    void (*record_visit)(struct MedicalHistory*, long long cost);
    void (*get_checkup)(struct MedicalHistory*, struct Person*);
};

// Реализация
void health_metrics_measure(struct HealthMetrics* hm, struct Person* p) {
    hm->heart_rate = 60 + rand() % 40;
    hm->blood_pressure_systolic = 110 + rand() % 30;
    hm->blood_pressure_diastolic = 70 + rand() % 20;
    hm->stress_level = rand() % 100;

    // Влияние образа жизни
    if (p->spending_habit > 0.7) {  // много тратит -> больше стресса
        hm->stress_level += 20;
    }

    printf("   Здоровье: пульс %d, давление %d/%d, стресс %d%%\n",
        hm->heart_rate, hm->blood_pressure_systolic,
        hm->blood_pressure_diastolic, hm->stress_level);
}

void gym_train(struct Gym* g, struct Person* p, int hours) {
    if (p->bank && p->bank->current_account >= g->monthly_fee) {
        p->bank->current_account -= g->monthly_fee;
        p->health_status += hours * 2;
        if (p->health_status > 100) p->health_status = 100;

        printf("   %s тренировался в %s (%d часов)\n", p->name, g->name, hours);
    }
}

#endif

#ifndef CHARITY_H
#define CHARITY_H

enum CharityType {
    CHARITY_ENVIRONMENT,
    CHARITY_EDUCATION,
    CHARITY_MEDICAL,
    CHARITY_ANIMALS,
    CHARITY_CHILDREN,
    CHARITY_ARTS
};

struct CharityOrganization {
    char name[100];
    enum CharityType type;
    char registration_number[50];
    float efficiency_rating;        // 0-1, сколько процентов идет на помощь
    long long total_donations;
    int projects_count;

    void (*donate)(struct CharityOrganization*, struct Person*, long long);
    void (*report_impact)(struct CharityOrganization*);
};

struct CharityPortfolio {
    struct CharityOrganization** organizations;
    int org_count;
    long long total_donated_year;
    long long monthly_budget;
    int is_tax_deductible;           // налоговый вычет на пожертвования

    void (*add_organization)(struct CharityPortfolio*, struct CharityOrganization*);
    void (*monthly_donation)(struct CharityPortfolio*, struct Person*);
    void (*special_campaign)(struct CharityPortfolio*, struct Person*, const char*);
    void (*print_impact_report)(struct CharityPortfolio*);
};

// Реализация
void charity_donate(struct CharityOrganization* co, struct Person* p, long long amount) {
    if (p->bank && p->bank->current_account >= amount) {
        p->bank->current_account -= amount;
        co->total_donations += amount;

        printf("   %s пожертвовал %.2f руб в '%s'\n",
            p->name, amount / 100.0, co->name);

        // Налоговый вычет (13% от пожертвования)
        if (p->tax_return) {
            long long deduction = amount * 0.13;
            p->tax_return->total_deductions += deduction;
            printf("   Налоговый вычет: +%.2f руб\n", deduction / 100.0);
        }
    }
}

void charity_report_impact(struct CharityOrganization* co) {
    long long effective_help = co->total_donations * co->efficiency_rating;
    const char* type_names[] = { "Экология", "Образование", "Медицина",
                                  "Животные", "Дети", "Искусство" };

    printf("\n Отчет '%s' (%s):\n", co->name, type_names[co->type]);
    printf("   Собрано: %.2f млн руб\n", co->total_donations / 100.0 / 1e6);
    printf("   Эффективно направлено: %.2f млн руб (%.0f%%)\n",
        effective_help / 100.0 / 1e6, co->efficiency_rating * 100);
    printf("   Реализовано проектов: %d\n", co->projects_count);
}

void portfolio_monthly_donation(struct CharityPortfolio* cp, struct Person* p) {
    if (cp->monthly_budget > 0 && p->bank) {
        long long total = 0;
        for (int i = 0; i < cp->org_count && i < 5; i++) {
            long long donation = cp->monthly_budget / cp->org_count;
            cp->organizations[i]->donate(cp->organizations[i], p, donation);
            total += donation;
        }
        cp->total_donated_year += total;
        printf("   Ежемесячные пожертвования: %.2f руб\n", total / 100.0);
    }
}

#endif
#ifndef RETIREMENT_H
#define RETIREMENT_H

struct PensionFund {
    char name[50];
    long long accumulated;
    long long monthly_contributions;
    long long employer_contributions;
    float expected_return;          
    int years_until_retirement;
    int is_private;                  

    void (*contribute)(struct PensionFund*, long long amount);
    void (*calculate_projection)(struct PensionFund*);
    void (*withdraw)(struct PensionFund*, struct Bank*, int age);
};

struct RetirementPlan {
    int retirement_age;
    int current_age;
    long long desired_monthly_income;
    long long projected_monthly_income;
    long long total_needed;
    long long current_savings;
    float shortfall_percent;

    struct PensionFund* state_pension;
    struct PensionFund** private_pensions;
    int private_pension_count;

    void (*calculate_needs)(struct RetirementPlan*);
    void (*adjust_contributions)(struct RetirementPlan*, struct Person*);
    void (*generate_retirement_report)(struct RetirementPlan*);
};


void pension_contribute(struct PensionFund* pf, long long amount) {
    pf->accumulated += amount;
    pf->monthly_contributions += amount;
}

void pension_calculate_projection(struct PensionFund* pf) {
   
    float monthly_rate = pf->expected_return / 12.0 / 100.0;
    int months = pf->years_until_retirement * 12;

    long long projected = pf->accumulated;
    for (int i = 0; i < months; i++) {
        projected += projected * monthly_rate;
        projected += pf->monthly_contributions;
    }

    pf->accumulated = projected;
}

void retirement_calculate_needs(struct RetirementPlan* rp) {
    // Расчет необходимого капитала для выхода на пенсию
    int years_in_retirement = 25;  // предполагаемая продолжительность пенсии
    rp->total_needed = rp->desired_monthly_income * 12 * years_in_retirement;

    
    float inflation_adjustment = 1.05;  // 5% инфляция
    rp->total_needed *= inflation_adjustment;

    
    rp->current_savings = 0;
    if (rp->state_pension) {
        rp->current_savings += rp->state_pension->accumulated;
    }
    for (int i = 0; i < rp->private_pension_count; i++) {
        rp->current_savings += rp->private_pensions[i]->accumulated;
    }

    rp->shortfall_percent = ((float)(rp->total_needed - rp->current_savings) /
        rp->total_needed) * 100;
    if (rp->shortfall_percent < 0) rp->shortfall_percent = 0;
}

void retirement_adjust_contributions(struct RetirementPlan* rp, struct Person* p) {
    if (rp->shortfall_percent > 20) {
        
        long long additional = p->salary * 0.05;
        if (p->bank && p->bank->current_account >= additional) {
            p->bank->current_account -= additional;
            if (rp->state_pension) {
                rp->state_pension->contribute(rp->state_pension, additional);
            }
            printf("   Увеличены пенсионные отчисления: +%.2f руб/мес\n",
                additional / 100.0);
        }
    }
}

void retirement_generate_report(struct RetirementPlan* rp) {
    printf("\n👴 ПЕНСИОННОЕ ПЛАНИРОВАНИЕ\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Текущий возраст: %d лет\n", rp->current_age);
    printf("Планируемый возраст выхода: %d лет\n", rp->retirement_age);
    printf("Осталось до пенсии: %d лет\n", rp->retirement_age - rp->current_age);
    printf("\nЦЕЛИ:\n");
    printf("  Желаемый доход: %.2f руб/мес\n", rp->desired_monthly_income / 100.0);
    printf("  Необходимый капитал: %.2f млн руб\n", rp->total_needed / 100.0 / 1e6);
    printf("\nТЕКУЩЕЕ СОСТОЯНИЕ:\n");
    printf("  Накопления: %.2f млн руб\n", rp->current_savings / 100.0 / 1e6);

    if (rp->shortfall_percent > 0) {
        printf("  ⚠ ДЕФИЦИТ: %.1f%% (не хватает %.2f млн руб)\n",
            rp->shortfall_percent, (rp->total_needed - rp->current_savings) / 100.0 / 1e6);
        printf("   Рекомендуется увеличить ежемесячные отчисления\n");
    }
    else {
        printf("   ЦЕЛЬ ДОСТИЖИМА! Отчисления достаточны\n");
    }
}

#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Подключение всех модулей
#include "config.h"
#include "transaction.h"
#include "budget.h"
#include "insurance.h"
#include "investment.h"
#include "credit_history.h"
#include "tax_system.h"
#include "education_career.h"
#include "travel_leisure.h"
#include "social_network.h"
#include "macroeconomics.h"
#include "health_fitness.h"


struct EconomicIndicators global_economy;
struct MarketTrends global_trends;
struct TaxAuthority federal_tax;

// Расширенная структура Person с новыми полями
struct Person {
    
    struct Education* education;
    struct CareerPath* career;
    struct TravelHistory* travels;
    struct SocialNetwork* social;
    struct HealthMetrics* health;
    struct Gym* gym;
    struct Nutrition* diet;
    struct MedicalHistory* medical;

    int current_year;
    int current_month;
};


void init_economy() {
    global_economy.inflation_rate = 7.5;
    global_economy.cpi_change = 0.6;
    global_economy.key_rate = 16.0;
    global_economy.gdp_growth = 2.1;
    global_economy.unemployment_rate = 3.2;
    global_economy.oil_price = 75.0;
    global_economy.usd_rub_rate = 92.5;
    global_economy.stock_market_index = 3200;

    global_economy.update_monthly = economic_update_indicators;
    global_economy.apply_economic_shock = economic_apply_shock;

    strcpy(federal_tax.name, "ФНС");
    federal_tax.total_collected = 0;
    federal_tax.total_refunds = 0;
    federal_tax.audit_rate = 5;
    federal_tax.collect_tax = tax_authority_collect;
}

void init_person_full(struct Person* p, const char* name) {
    
    strcpy(p->name, name);
    p->current_year = 2024;
    p->current_month = 1;

    
    p->education = (struct Education*)malloc(sizeof(struct Education));
    p->education->level = ED_BACHELOR;
    p->education->salary_bonus = education_salary_bonus;

    
    p->career = (struct CareerPath*)malloc(sizeof(struct CareerPath));
    p->career->total_jobs = 0;
    p->career->years_experience_total = 0;
    p->career->add_job = career_add_job;
    p->career->promotion = career_promotion;

    
    p->travels = (struct TravelHistory*)malloc(sizeof(struct TravelHistory));
    p->travels->total_trips = 0;
    p->travels->total_spent = 0;
    p->travels->plan_trip = travel_plan_trip;

    
    p->social = (struct SocialNetwork*)malloc(sizeof(struct SocialNetwork));
    p->social->connection_count = 0;
    p->social->max_connections = 20;
    p->social->popularity_score = 50;
    p->social->social_event = social_social_event;

   
    p->health = (struct HealthMetrics*)malloc(sizeof(struct HealthMetrics));
    p->health->stress_level = 30;
    p->health->measure = health_metrics_measure;
}


void simulate_month(struct Person* alice, struct Person* bob, int month, int year) {
    printf("\n╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    МЕСЯЦ %d/%d                              ║\n", month, year);
    printf("╚══════════════════════════════════════════════════════════════╝\n");

    
    global_economy.update_monthly(&global_economy, month, year);

    
    if (month == 1 && (year % 3 == 0)) {
        global_economy.apply_economic_shock(&global_economy);
    }

   
    printf("\n ИНФЛЯЦИЯ: %.1f%% (годовая)\n", global_economy.inflation_rate);

    // Симуляция для Алисы
    printf("\n %s:\n", alice->name);
    simulate_person_month(alice, month, year);

    // Симуляция для Боба
    printf("\n %s:\n", bob->name);
    simulate_person_month(bob, month, year);

    
    if (alice->social && bob->social) {
        alice->social->social_event(alice->social, alice, month);
        bob->social->social_event(bob->social, bob, month);

        
        if (rand() % 100 < 30) {
            alice->social->get_advice(alice->social, alice, "investment");
            bob->social->get_advice(bob->social, bob, "investment");
        }
    }

    
    alice->travels->plan_trip(alice->travels, alice, month);
    bob->travels->plan_trip(bob->travels, bob, month);

   
    alice->health->measure(alice->health, alice);
    bob->health->measure(bob->health, bob);
}

void simulate_person_month(struct Person* p, int month, int year) {
    
    p->work(p, month, year);

    
    p->pay_bills(p);

   
    if (rand() % 100 < 20) {
        p->career->promotion(p->career, p);
    }

    
    p->invest(p);

    
    if (p->insurance) {
        p->insurance->pay_monthly(p->insurance, p->primary_bank);
    }

    
    if (p->credit_history) {
        
        if (p->credit_history->loans) {
            credit_make_payment(p->credit_history, "Sberbank",
                MORTGAGE_MONTHLY, p->primary_bank);
        }
    }

    
    federal_tax.collect_tax(&federal_tax, p, TAX_INCOME,
        p->salary * INCOME_TAX_RATE);

    
    p->make_goal_progress(p);

   
    p->learn(p);

    
    if (p->gym && rand() % 100 < 50) {
        p->gym->train(p->gym, p, 1);
    }

    
    p->current_month++;
    if (p->current_month == 13) {
        p->current_month = 1;
        p->current_year++;

        
        if (p->current_month == 1) {
            struct TaxReturn tax_return;
            tax_return.year = p->current_year - 1;
            tax_return.total_income = p->salary * 12;
            tax_return.tax_paid = tax_return.total_income * INCOME_TAX_RATE;
            tax_return.calculate = tax_return_calculate;
            tax_return.file = tax_return_file;
            tax_return.calculate(&tax_return);
            tax_return.file(&tax_return, p->primary_bank);
        }
    }
}

int main() {
    srand(time(NULL));

    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║     ФИНАНСОВЫЙ СИМУЛЯТОР ЖИЗНИ v2.0                        ║\n");
    printf("║     Алиса (аренда) vs Боб (ипотека)                        ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");

    // Инициализация
    init_economy();

    struct Person alice, bob;
    init_person_full(&alice, "Алиса");
    init_person_full(&bob, "Боб");

    
    alice.spending_habit = 0.6;  
    alice.risk_tolerance = 0.7;   
    alice.financial_literacy = 0.5;

    bob.spending_habit = 0.4;      
    bob.risk_tolerance = 0.3;      
    bob.financial_literacy = 0.6;

    
    alice.portfolio = (struct InvestmentPortfolio*)malloc(sizeof(struct InvestmentPortfolio));
    alice.portfolio->total_value = 0;
    alice.portfolio->total_invested = 0;
    alice.portfolio->update_prices = investment_update_prices;

    bob.portfolio = (struct InvestmentPortfolio*)malloc(sizeof(struct InvestmentPortfolio));
    bob.portfolio->total_value = 0;
    bob.portfolio->total_invested = 0;
    bob.portfolio->update_prices = investment_update_prices;

    
    alice.insurance = (struct InsurancePortfolio*)malloc(sizeof(struct InsurancePortfolio));
    alice.insurance->total_monthly_premium = 0;
    alice.insurance->add_policy = insurance_add_policy;
    alice.insurance->add_policy(alice.insurance, INSURANCE_HEALTH, 1'000'000 * 100, 2'500 * 100, 10);
    alice.insurance->add_policy(alice.insurance, INSURANCE_CAR, 500'000 * 100, 1'500 * 100, 5);

    bob.insurance = (struct InsurancePortfolio*)malloc(sizeof(struct InsurancePortfolio));
    bob.insurance->total_monthly_premium = 0;
    bob.insurance->add_policy = insurance_add_policy;
    bob.insurance->add_policy(bob.insurance, INSURANCE_HEALTH, 2'000'000 * 100, 5'000 * 100, 15);
    bob.insurance->add_policy(bob.insurance, INSURANCE_HOME, 5'000'000 * 100, 3'000 * 100, 20);

    
    alice.credit_history = (struct CreditHistory*)malloc(sizeof(struct CreditHistory));
    alice.credit_history->total_debt = 0;
    alice.credit_history->available_credit = 500'000 * 100;
    alice.credit_history->add_loan = credit_add_loan;

    bob.credit_history = (struct CreditHistory*)malloc(sizeof(struct CreditHistory));
    bob.credit_history->total_debt = APARTMENT_PRICE;
    bob.credit_history->available_credit = 200'000 * 100;
    bob.credit_history->add_loan = credit_add_loan;
    bob.credit_history->add_loan(bob.credit_history, "Sberbank", APARTMENT_PRICE, MORTGAGE_RATE_BASE, 240);

    
    alice.gym = (struct Gym*)malloc(sizeof(struct Gym));
    strcpy(alice.gym->name, "World Class");
    alice.gym->monthly_fee = 5'000 * 100;
    alice.gym->train = gym_train;

    // Основной цикл симуляции (3 года)
    int month = 1, year = 2024;
    while (year < 2027) {
        simulate_month(&alice, &bob, month, year);

        
        if (month == 12) {
            printf("\n ГОДОВОЙ ОТЧЕТ %d\n", year);
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
            alice.print_wealth_report(&alice);
            bob.print_wealth_report(&bob);

            
            printf("\n СРАВНЕНИЕ КАПИТАЛА:\n");
            if (alice.capital_total > bob.capital_total) {
                printf("    Алиса лидирует: +%.2f руб\n",
                    (alice.capital_total - bob.capital_total) / 100.0);
            }
            else {
                printf("    Боб лидирует: +%.2f руб\n",
                    (bob.capital_total - alice.capital_total) / 100.0);
            }
        }

        month++;
        if (month == 13) {
            month = 1;
            year++;
        }
    }

    // Финальный отчет
    printf("\n╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    ИТОГИ 3-ЛЕТНЕЙ СИМУЛЯЦИИ                 ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");

    alice.print_wealth_report(&alice);
    bob.print_wealth_report(&bob);

    printf("\n МАКРОЭКОНОМИЧЕСКИЕ ИТОГИ:\n");
    printf("   Средняя инфляция: %.1f%%\n", global_economy.inflation_rate);
    printf("   Рост ВВП: %.1f%%\n", global_economy.gdp_growth);
    printf("   Собрано налогов: %.2f млрд руб\n", federal_tax.total_collected / 1e11);

    

    return 0;
}