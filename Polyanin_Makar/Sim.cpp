
#include <stdio.h>
#include <math.h>      
#include <stdlib.h>    
#include <time.h>     


using Percent = float;
using RUB = long long int;
using USD = long long int;


struct Cat {
    RUB cfood;         
    RUB vet;           
    RUB toys;          
};


struct Car {
    RUB value;         
    RUB gas;          
    RUB maintenance;   
    RUB insurance;    
    RUB repair;        
    int year;          
    int mileage;      
};


struct Bank {
    RUB account_rub;  
    USD account_usd;   
    float rate_usd_rub;
    
    
    RUB credit_amount; 
    RUB credit_monthly_payment; 
    RUB credit_total_paid; 
    Percent credit_rate; 
    int credit_months_remaining; 
};


struct Deposit {
    RUB amount;        
    Percent rate;      
    bool is_active;    
    int months_remaining; 
    RUB monthly_income; 
};


struct Apartment {
    RUB cost;          
    RUB monthly_maintenance; 
    bool is_owned;     
    bool is_mortgage;  
    RUB rent_income;   
    RUB rent_expense;  
    RUB square_meters; 
    int rooms;         
};



struct Person {
    Bank vtb;          
    Deposit deposit;   
    RUB salary;        
    RUB food;          
    RUB utilities;     
    RUB entertainment; 
    RUB clothes;       
    RUB health;        
    RUB education;     
    RUB transport;     
    RUB internet;      
    
    
    Cat cat;           
    Car car;           
    Apartment apartment; 
    
    
    RUB savings_goal;  
    RUB emergency_fund;
    
    
    bool has_credit_card; 
    RUB credit_card_limit; 
    RUB credit_card_debt; 
    
    
    int age;           
    int work_experience; 
    char name[50];     
};


struct Person alice;
struct Person bob;


RUB random_range(RUB min, RUB max) {
    return min + rand() % (max - min + 1);
}


void update_exchange_rate(Person* person) {
    float change = (rand() % 100 - 50) / 1000.0; 
    person->vtb.rate_usd_rub *= (1.0 + change);
    
    
    if (person->vtb.rate_usd_rub < 50.0) person->vtb.rate_usd_rub = 50.0;
    if (person->vtb.rate_usd_rub > 150.0) person->vtb.rate_usd_rub = 150.0;
}


void alice_init() {
    sprintf(alice.name, "Alice");
    alice.age = 28;
    alice.work_experience = 5;
    
    
    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 50'000;  
    alice.vtb.account_usd = 1'000;
    
    
    alice.vtb.credit_amount = 5'000'000;  
    alice.vtb.credit_rate = 18.0;  
    alice.vtb.credit_months_remaining = 240;  
    alice.vtb.credit_total_paid = 0;
    
    
    double monthly_rate = alice.vtb.credit_rate / 100.0 / 12.0;
    double power = pow(1.0 + monthly_rate, alice.vtb.credit_months_remaining);
    alice.vtb.credit_monthly_payment = alice.vtb.credit_amount * (monthly_rate * power) / (power - 1.0);
    
    
    alice.salary = 180'000;
    
    
    alice.food = 25'000;  
    alice.utilities = 8'000;  
    alice.entertainment = 10'000;  
    alice.clothes = 5'000;  
    alice.health = 3'000;  
    alice.education = 0; 
    alice.transport = 3'000;  
    alice.internet = 1'500;  
    
    
    alice.cat.cfood = 2'500;
    alice.cat.vet = 1'000;  
    alice.cat.toys = 500;
    
    
    
    alice.car.value = 2'400'000;
    alice.car.gas = 12'000;
    alice.car.maintenance = 3'000;  
    alice.car.insurance = 8'000;  
    alice.car.repair = 0;  
    alice.car.year = 2022;
    alice.car.mileage = 30'000;
    
    
    
    alice.apartment.cost = 8'000'000;  
    alice.apartment.monthly_maintenance = 5'000;  
    alice.apartment.is_owned = false;  
    alice.apartment.is_mortgage = true;
    alice.apartment.square_meters = 45;
    alice.apartment.rooms = 2;
    
    
    
    alice.savings_goal = 1'000'000;  
    alice.emergency_fund = 0;  
    
    
    alice.has_credit_card = true;
    alice.credit_card_limit = 300'000;
    alice.credit_card_debt = 0;
}



void bob_init() {
    sprintf(bob.name, "Bob");
    bob.age = 30;
    bob.work_experience = 7;
    
    
    bob.vtb.rate_usd_rub = 78.76;
    bob.vtb.account_rub = 300'000;  
    bob.vtb.account_usd = 2'000;
    
    

    bob.deposit.amount = 200'000;  
    bob.deposit.rate = 16.0;  
    bob.deposit.is_active = true;
    bob.deposit.months_remaining = 12;  
    bob.deposit.monthly_income = 0;  
    
    
    bob.salary = 220'000;  
    
    
    bob.food = 20'000;
    bob.utilities = 7'000;
    bob.entertainment = 15'000;  
    bob.clothes = 4'000;


bob.health = 2'000;
    bob.education = 5'000;  
    bob.transport = 2'000;  
    bob.internet = 2'000;
    
    
    bob.cat.cfood = 0;
    bob.cat.vet = 0;
    bob.cat.toys = 0;
    
    
    bob.car.value = 0;
    bob.car.gas = 0;
    bob.car.maintenance = 0;
    bob.car.insurance = 0;
    bob.car.year = 0;
    bob.car.mileage = 0;
    
    
    bob.apartment.rent_expense = 30'000;  
    bob.apartment.monthly_maintenance = 0;  
    bob.apartment.is_owned = false;
    bob.apartment.is_mortgage = false;
    bob.apartment.square_meters = 40;
    bob.apartment.rooms = 1;
    
    
    bob.savings_goal = 2'000'000;  
    bob.emergency_fund = 100'000;  
    
    
    bob.has_credit_card = true;
    bob.credit_card_limit = 200'000;
    bob.credit_card_debt = 0;
}


void calculate_deposit_income(Person* person) {
    if (!person->deposit.is_active) return;
    
    
    person->deposit.monthly_income = person->deposit.amount * (person->deposit.rate / 100.0 / 12.0);
    
    
    person->deposit.amount += person->deposit.monthly_income;
    person->deposit.months_remaining--;
    
    
    if (person->deposit.months_remaining <= 0) {
        person->deposit.months_remaining = 12;  
        person->deposit.rate = 15.0 + (rand() % 3);  
    }
}


void pay_mortgage(Person* person) {
    if (person->vtb.credit_months_remaining <= 0) return;  
    
    
    if (person->vtb.account_rub >= person->vtb.credit_monthly_payment) {
        person->vtb.account_rub -= person->vtb.credit_monthly_payment;
        person->vtb.credit_total_paid += person->vtb.credit_monthly_payment;
        person->vtb.credit_months_remaining--;
        
        
        if (person->vtb.credit_months_remaining == 0) {
            person->apartment.is_owned = true;
            person->apartment.is_mortgage = false;
            printf("    * Поздравляем! Кредит на квартиру полностью выплачен! *\n");
        }
    } else {
        if (person->has_credit_card && person->credit_card_limit - person->credit_card_debt >= person->vtb.credit_monthly_payment) {
            person->credit_card_debt += person->vtb.credit_monthly_payment;
            person->vtb.credit_total_paid += person->vtb.credit_monthly_payment;
            person->vtb.credit_months_remaining--;
            printf("    ВНИМАНИЕ: Не хватает денег на ипотеку! Использована кредитная карта.\n");
        } else 
            printf("    * КРИТИЧНО: ПРОСРОЧКА ПЛАТЕЖА ПО ИПОТЕКЕ! *\n");
            person->vtb.credit_amount += person->vtb.credit_amount * 0.01;  // Штраф 1%
            double monthly_rate = person->vtb.credit_rate / 100.0 / 12.0;
            double power = pow(1.0 + monthly_rate, person->vtb.credit_months_remaining);
            person->vtb.credit_monthly_payment = person->vtb.credit_amount * (monthly_rate * power) / (power - 1.0);
        }
    }
}


void person_food(Person* person, const int month, const int year) {
    if (month == 12) {
        person->food += 5'000;  // Новогодний стол
        person->vtb.account_rub -= 5'000;
    }
    if (month == 2 && person == &alice) {
        person->food += 3'000;  // День рождения Алисы
        person->vtb.account_rub -= 3'000;
    }
    if (month == 7 && person == &bob) {
        person->food += 4'000;  // День рождения Боба
        person->vtb.account_rub -= 4'000;
    }
    
    
    Percent inflation = 12.0;
    switch (year) {
        case 2026: inflation = 12.5; break;
        case 2027: inflation = 14.0; break;
        case 2028: inflation = 13.0; break;
        case 2029: inflation = 11.5; break;
        case 2030: inflation = 10.0; break;
        case 2031: inflation = 9.5; break;
    }
    person->food += person->food * (inflation / 100. / 12.);
    
    
    person->vtb.account_rub -= person->food;
}



void person_cat(Person* person, const int month, const int year) {
    // Если нет кота, ничего не делаем
    if (person->cat.cfood == 0 && person->cat.vet == 0) return;
    
    
    Percent inflation = 12.0;
    switch (year) {
        case 2026: inflation = 12.5; break;
        case 2027: inflation = 14.0; break;
        case 2028: inflation = 12.0; break;
        case 2029: inflation = 11.5; break;
    }
    person->cat.cfood += person->cat.cfood * (inflation / 100. / 12.);
    
    
    if (month == 3 || month == 9) {
        person->vtb.account_rub -= person->cat.vet;
    }
    
    
    if (month == 12) {
        person->vtb.account_rub -= person->cat.toys * 2;
    }
    
    
    person->vtb.account_rub -= person->cat.cfood;
}



void person_car(Person* person, const int month, const int year) {
    
    if (person->car.value == 0) return;
    
    
    person->vtb.account_rub -= person->car.gas;
    
    
    if (month == 4 || month == 10) {
        person->vtb.account_rub -= person->car.maintenance;
    }
    
    
    if (month == 1) {
        person->vtb.account_rub -= person->car.insurance * 12;  
    }
    
    
    if (rand() % 100 < 5) { 
        RUB repair_cost = random_range(5'000, 50'000);
        person->vtb.account_rub -= repair_cost;
        printf("    Неожиданный ремонт машины: %lld руб.\n", repair_cost);
    }
    
    
    person->car.mileage += 1'500;  
    
    
    // Амортизация (машина теряет в цене)
    person->car.value -= person->car.value * 0.005;  // 0.5% в месяц
}


void person_salary(Person* person, const int month, const int year) {
    
    if (month == 3) {
        person->salary *= 1.5;
    }
    
    
    // Индексация зарплаты в январе
    if (month == 1 && year > 2026) {
        Percent salary_increase = 8.0;  // 8% индексация в год
        person->salary += person->salary * (salary_increase / 100.0);
    }
    
    
    
    if (month == 2 && year == 2026 && person == &alice) {
        person->vtb.account_rub += 5'000;  // Бонус для Алисы
    }
    
    
    if (month == 11 && year == 2026 && person == &bob) {
        person->vtb.account_rub += 10'000;  // Бонус для Боба
    }
    
    
    person->vtb.account_rub += person->salary;
}


void person_apartment(Person* person, const int month, const int year) {


    person->vtb.account_rub -= person->apartment.monthly_maintenance;
    
    
    if (!person->apartment.is_owned && person->apartment.rent_expense > 0) {
        person->vtb.account_rub -= person->apartment.rent_expense;
    }
    
    
    if (person->apartment.is_owned && person->apartment.rent_income > 0) {
        person->vtb.account_rub += person->apartment.rent_income;
    }
    
    
    if (rand() % 200 < 1) {  
        RUB repair_cost = random_range(10'000, 100'000);
        person->vtb.account_rub -= repair_cost;
        printf("    Ремонт в квартире: %lld руб.\n", repair_cost);
    }
}


void person_other_expenses(Person* person, const int month, const int year) {
    
    person->vtb.account_rub -= person->entertainment;
    
    
    if (month == 4 || month == 9) {  
        person->vtb.account_rub -= person->clothes * 3;
    } else {
        person->vtb.account_rub -= person->clothes;
    }
    
    
    person->vtb.account_rub -= person->health;
    

    if (person->education > 0) {
        if (month == 9) {  
            person->vtb.account_rub -= person->education * 12;
        }
    }
    

    person->vtb.account_rub -= person->transport;
    
    
    person->vtb.account_rub -= person->internet;
    
    
    if (month == 7) {
        RUB vacation_cost = random_range(50'000, 150'000);
        person->vtb.account_rub -= vacation_cost;
        printf("    Отпуск: %lld руб.\n", vacation_cost);
    }
    
    
    if (month == 12) {
        RUB gifts_cost = random_range(10'000, 30'000);
        person->vtb.account_rub -= gifts_cost;
    }
}


void random_financial_events(Person* person, const int month, const int year) {
    int event = rand() % 1000;
    
    
    if (event < 10) {  // 1% - выигрыш в лотерею
        RUB win = random_range(1'000, 50'000);
        person->vtb.account_rub += win;
        printf("    Удача! Выигрыш в лотерею: %lld руб.\n", win);
    }
    else if (event < 20) {  // 1% - штраф
        RUB fine = random_range(500, 5'000);
        person->vtb.account_rub -= fine;
        printf("    Штраф: %lld руб.\n", fine);
    }
    else if (event < 30) {  // 1% - нашли деньги
        RUB found = random_range(100, 10'000);
        person->vtb.account_rub += found;
        printf("    Нашли деньги: %lld руб.\n", found);
    }
    else if (event < 40) {  // 1% - потеряли деньги
        RUB lost = random_range(100, 5'000);
        person->vtb.account_rub -= lost;
        printf("    Потеряли деньги: %lld руб.\n", lost);
    }
    else if (event < 45) {  // 0.5% - премия на работе (внеплановая)
        RUB bonus = random_range(10'000, 100'000);
        person->vtb.account_rub += bonus;
        printf("    Неожиданная премия на работе: %lld руб.\n", bonus);
    }
    else if (event < 48) {  // 0.3% - поломка техники
        RUB breakdown = random_range(10'000, 40'000);
        person->vtb.account_rub -= breakdown;
        printf("    Поломка техники (ремонт/покупка): %lld руб.\n", breakdown);
    }
}


void manage_emergency_fund(Person* person) {
    RUB monthly_expenses = person->food + person->utilities + person->entertainment + 
                          person->clothes + person->health + person->transport + 
                          person->internet + person->cat.cfood + person->car.gas;


RUB target_emergency_fund = monthly_expenses * 6;
    
    
    if (person->vtb.account_rub > target_emergency_fund + 100'000) {
        RUB excess = person->vtb.account_rub - target_emergency_fund;
        RUB transfer = excess * 0.5; 
        person->vtb.account_rub -= transfer;
        person->emergency_fund += transfer;
    }
    
    
    if (person->emergency_fund > target_emergency_fund * 1.2) {
        RUB excess = person->emergency_fund - target_emergency_fund;
        person->emergency_fund -= excess;
        person->vtb.account_rub += excess;
    }
    
    
    if (person->vtb.account_rub < monthly_expenses && person->emergency_fund > 0) {
        RUB needed = monthly_expenses - person->vtb.account_rub;
        RUB take = (needed < person->emergency_fund) ? needed : person->emergency_fund;
        person->emergency_fund -= take;
        person->vtb.account_rub += take;
        printf("    Использована подушка безопасности: %lld руб. Остаток: %lld\n", take, person->emergency_fund);
    }
}


void manage_credit_card(Person* person) {
    if (!person->has_credit_card) return;
    
    
    if (person->credit_card_debt > 0) {

        RUB min_payment = person->credit_card_debt * 0.05;
        if (min_payment < 1'000) min_payment = person->credit_card_debt;
        
        if (person->vtb.account_rub > min_payment + 10'000) {
            RUB payment = (person->vtb.account_rub - 10'000 > person->credit_card_debt) ? 
                          person->credit_card_debt : (person->vtb.account_rub - 10'000);
            person->vtb.account_rub -= payment;
            person->credit_card_debt -= payment;
            printf("    Погашен долг по кредитной карте: %lld руб. Остаток долга: %lld\n", 
                   payment, person->credit_card_debt);
        }
    }
}


void invest_in_currency(Person* person, const int month) {
    // Раз в 3 месяца, если есть лишние деньги, покупаем валюту
    if (month % 3 == 0 && person->vtb.account_rub > 100'000) {
        RUB to_invest = person->vtb.account_rub * 0.2;
        if (to_invest > 200'000) to_invest = 200'000;
        
        
        USD dollars_to_buy = to_invest / person->vtb.rate_usd_rub;
        person->vtb.account_rub -= to_invest;
        person->vtb.account_usd += dollars_to_buy;
        printf("    Инвестиция: куплено %lld долларов по курсу %.2f\n", 
               dollars_to_buy, person->vtb.rate_usd_rub);
    }
}


void print_monthly_report(const int year, const int month, Person* p1, Person* p2) {
    printf("\n========================================\n");
    printf("ОТЧЕТ ЗА %d.%d\n", month, year);
    printf("========================================\n");
    
    
    // Отчет по Алисе
    printf("\n--- %s ---\n", p1->name);
    printf("  Счет (рубли): %'lld руб.\n", p1->vtb.account_rub);
    printf("  Счет (доллары): %'lld USD (%.2f руб.)\n", p1->vtb.account_usd, p1->vtb.rate_usd_rub);
    printf("  Доллар-счет в рублях: %'lld руб.\n", p1->vtb.account_usd * p1->vtb.rate_usd_rub);
    printf("  Подушка безопасности: %'lld руб.\n", p1->emergency_fund);
    printf("  Машина: %'lld руб.\n", p1->car.value);
    printf("  Квартира: %'lld руб.\n", p1->apartment.cost);
    printf("  Остаток по ипотеке: %'lld руб. (%d мес.)\n", 
           p1->vtb.credit_amount - p1->vtb.credit_total_paid, p1->vtb.credit_months_remaining);
           
           
    printf("  Долг по кредитке: %'lld руб.\n", p1->credit_card_debt);
    
    
    RUB total_capital_p1 = p1->vtb.account_rub + 
                          p1->vtb.account_usd * p1->vtb.rate_usd_rub + 
                          p1->car.value + 
                          p1->apartment.cost - 
                          (p1->vtb.credit_amount - p1->vtb.credit_total_paid);
    printf("  ОБЩИЙ КАПИТАЛ: %'lld руб.\n", total_capital_p1);
    
    
    // Отчет по Бобу
    printf("\n--- %s ---\n", p2->name);
    printf("  Счет (рубли): %'lld руб.\n", p2->vtb.account_rub);
    printf("  Счет (доллары): %'lld USD (%.2f руб.)\n", p2->vtb.account_usd, p2->vtb.rate_usd_rub);
    printf("  Доллар-счет в рублях: %'lld руб.\n", p2->vtb.account_usd * p2->vtb.rate_usd_rub);
    printf("  Вклад: %'lld руб. (%.1f%%, осталось %d мес.)\n", 
           p2->deposit.amount, p2->deposit.rate, p2->deposit.months_remaining);
    printf("  Подушка безопасности: %'lld руб.\n", p2->emergency_fund);
    printf("  Долг по кредитке: %'lld руб.\n", p2->credit_card_debt);
    printf("  Накоплено на квартиру: %'lld руб. (цель: %'lld)\n", 
           p2->vtb.account_rub + p2->emergency_fund + p2->deposit.amount, 
           p2->savings_goal);
    
    
    RUB total_capital_p2 = p2->vtb.account_rub + 
                          p2->vtb.account_usd * p2->vtb.rate_usd_rub + 
                          p2->deposit.amount;
    printf("  ОБЩИЙ КАПИТАЛ: %'lld руб.\n", total_capital_p2);
    
    
    printf("\n----------------------------------------\n");
}


void print_yearly_report(const int year, Person* p1, Person* p2) {
    printf("\n\n**** ГОДОВОЙ ОТЧЕТ %d ****\n", year);
    
    
    RUB capital_p1_start = 0;  
    RUB capital_p2_start = 0; 
    
    
    printf("\n--- %s ---\n", p1->name);
    printf("  Итоговый счет: %'lld руб.\n", p1->vtb.account_rub);
    printf("  Итоговая недвижимость: %'lld руб.\n", p1->apartment.cost);
    printf("  Остаток по ипотеке: %'lld руб.\n", p1->vtb.credit_amount - p1->vtb.credit_total_paid);
    
    
    printf("\n--- %s ---\n", p2->name);
    printf("  Итоговый счет: %'lld руб.\n", p2->vtb.account_rub);
    printf("  Итоговый вклад: %'lld руб.\n", p2->deposit.amount);
    printf("  Накоплено на квартиру: %'lld руб.\n", 
           p2->vtb.account_rub + p2->emergency_fund + p2->deposit.amount);
    
    
    printf("************\n\n");
}


void simulation() {
    int year = 2026;
    int month = 2;
    
    
    printf("========== НАЧАЛО СИМУЛЯЦИИ ==========\n");
    printf("Алиса берет ипотеку, Боб копит на вклад\n\n");
    
    
    RUB alice_capital_last_year = 0;
    RUB bob_capital_last_year = 0;
    
    
    while (!(year == 2046 && month == 2)) { 
        update_exchange_rate(&alice);
        update_exchange_rate(&bob);
        
        
        random_financial_events(&alice, month, year);
        random_financial_events(&bob, month, year);
        
        
        person_salary(&alice, month, year);
        person_car(&alice, month, year);
        person_cat(&alice, month, year);
        pay_mortgage(&alice); 
        person_apartment(&alice, month, year);  
        person_food(&alice, month, year);
        person_other_expenses(&alice, month, year);
        invest_in_currency(&alice, month);  
        
        
        person_salary(&bob, month, year);
        calculate_deposit_income(&bob);  


person_apartment(&bob, month, year);  
        person_food(&bob, month, year);
        person_other_expenses(&bob, month, year);
        invest_in_currency(&bob, month);  
        
        
        manage_emergency_fund(&alice);
        manage_emergency_fund(&bob);
        manage_credit_card(&alice);
        manage_credit_card(&bob);
        
    
        if (month % 6 == 0) {
            print_monthly_report(year, month, &alice, &bob);
        }
    

        if (month == 12) {
            print_yearly_report(year, &alice, &bob);
        }
        
        
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
            
            
            if (year == 2030) {
                printf("\n* 2030 год - кризис! Курс доллара скачет *\n");
                alice.vtb.rate_usd_rub *= 1.5;  // Девальвация
                bob.vtb.rate_usd_rub *= 1.5;
            }
            
            
            if (year == 2035) {
                printf("\n* 2035 год - Алиса получила повышение! *\n");
                alice.salary += 50'000;
            }
            
            
            if (year == 2040) {
                printf("\n* 2040 год - Боб получил наследство! *\n");
                bob.vtb.account_rub += 500'000;
            }
        }
    }
    
    
    printf("\n========== КОНЕЦ СИМУЛЯЦИИ ==========\n");
}


void print_results() {
    printf("\n\n");
    printf("========================================\n");
    printf("            ИТОГОВЫЕ РЕЗУЛЬТАТЫ         \n");
    printf("========================================\n\n");
    
    
    // Результаты Алисы
    printf("=== %s ===\n", alice.name);
    printf("Возраст: %d лет\n", alice.age + 20);  
    printf("Зарплата в конце периода: %'lld руб.\n", alice.salary);
    printf("\nАКТИВЫ:\n");
    printf("  Счет в рублях: %'lld руб.\n", alice.vtb.account_rub);
    printf("  Счет в долларах: %'lld USD (%.2f руб.)\n", alice.vtb.account_usd, alice.vtb.rate_usd_rub);
    printf("  Долларовый счет в рублях: %'lld руб.\n", alice.vtb.account_usd * alice.vtb.rate_usd_rub);
    printf("  Подушка безопасности: %'lld руб.\n", alice.emergency_fund);
    printf("  Машина: %'lld руб.\n", alice.car.value);
    printf("  Квартира: %'lld руб.\n", alice.apartment.cost);
    
    
    printf("\nПАССИВЫ:\n");
    if (alice.vtb.credit_months_remaining > 0) {
        printf("  Остаток по ипотеке: %'lld руб. (%d мес.)\n", 
               alice.vtb.credit_amount - alice.vtb.credit_total_paid, 
               alice.vtb.credit_months_remaining);
    } else {
        printf("  Ипотека: ПОЛНОСТЬЮ ВЫПЛАЧЕНА!\n");
    }
    printf("  Долг по кредитной карте: %'lld руб.\n", alice.credit_card_debt);
    
    
    RUB alice_total_assets = alice.vtb.account_rub + 
                            alice.vtb.account_usd * alice.vtb.rate_usd_rub + 
                            alice.emergency_fund +
                            alice.car.value + 
                            alice.apartment.cost;
    
    
    RUB alice_total_liabilities = (alice.vtb.credit_amount - alice.vtb.credit_total_paid) + 
                                 alice.credit_card_debt;
    
    
    RUB alice_net_worth = alice_total_assets - alice_total_liabilities;
    
    
    printf("\nИТОГО:\n");
    printf("  Всего активов: %'lld руб.\n", alice_total_assets);
    printf("  Всего обязательств: %'lld руб.\n", alice_total_liabilities);
    printf("  ЧИСТЫЙ КАПИТАЛ: %'lld руб.\n", alice_net_worth);
    
    
    printf("\n----------------------------------------\n\n");
    
    
    // Результаты Боба
    printf("=== %s ===\n", bob.name);


printf("Возраст: %d лет\n", bob.age + 20);
    printf("Зарплата в конце периода: %'lld руб.\n", bob.salary);
    printf("\nАКТИВЫ:\n");
    printf("  Счет в рублях: %'lld руб.\n", bob.vtb.account_rub);
    printf("  Счет в долларах: %'lld USD (%.2f руб.)\n", bob.vtb.account_usd, bob.vtb.rate_usd_rub);
    printf("  Долларовый счет в рублях: %'lld руб.\n", bob.vtb.account_usd * bob.vtb.rate_usd_rub);
    printf("  Вклад в банке: %'lld руб.\n", bob.deposit.amount);
    printf("  Подушка безопасности: %'lld руб.\n", bob.emergency_fund);
    
    
    // Предположим, что Боб купил квартиру, если накопил достаточно
    bool bought_apartment = false;
    RUB bob_savings = bob.vtb.account_rub + bob.vtb.account_usd * bob.vtb.rate_usd_rub + 
                     bob.deposit.amount + bob.emergency_fund;
    
    
    if (bob_savings >= bob.savings_goal && !bob.apartment.is_owned) {
        printf("\n* Боб накопил достаточно и КУПИЛ КВАРТИРУ! *\n");
        bob.apartment.is_owned = true;
        bob.apartment.cost = bob.savings_goal;
        bob.apartment.square_meters = 50;
        bob.apartment.rooms = 2;
        bought_apartment = true;
    }
    
    
    if (bob.apartment.is_owned) {
        printf("  Квартира: %'lld руб.\n", bob.apartment.cost);
    }
    
    
    printf("\nПАССИВЫ:\n");
    printf("  Долг по кредитной карте: %'lld руб.\n", bob.credit_card_debt);
    
    
    RUB bob_total_assets = bob.vtb.account_rub + 
                          bob.vtb.account_usd * bob.vtb.rate_usd_rub + 
                          bob.deposit.amount +
                          bob.emergency_fund;
    
    
    if (bob.apartment.is_owned) {
        bob_total_assets += bob.apartment.cost;
    }
    
    
    RUB bob_total_liabilities = bob.credit_card_debt;
    RUB bob_net_worth = bob_total_assets - bob_total_liabilities;
    
    
    printf("\nИТОГО:\n");
    printf("  Всего активов: %'lld руб.\n", bob_total_assets);
    printf("  Всего обязательств: %'lld руб.\n", bob_total_liabilities);
    printf("  ЧИСТЫЙ КАПИТАЛ: %'lld руб.\n", bob_net_worth);
    
    
    printf("\n========================================\n");
    
    
    printf("\n");
    printf("========================================\n");
    printf("         СРАВНЕНИЕ РЕЗУЛЬТАТОВ          \n");
    printf("========================================\n");
    printf("Алиса (ипотека): %'lld руб.\n", alice_net_worth);
    printf("Боб (вклад):     %'lld руб.\n", bob_net_worth);
    
    
    if (alice_net_worth > bob_net_worth) {
        printf("\nПОБЕДИТЕЛЬ: Алиса! Ипотека оказалась выгоднее накоплений.\n");
        printf("Разница: %'lld руб.\n", alice_net_worth - bob_net_worth);
    } else if (bob_net_worth > alice_net_worth) {
        printf("\nПОБЕДИТЕЛЬ: Боб! Накопления оказались выгоднее ипотеки.\n");
        printf("Разница: %'lld руб.\n", bob_net_worth - alice_net_worth);
    } else {
        printf("\nНИЧЬЯ! Оба достигли одинакового результата.\n");
    }
    printf("========================================\n");
}


void scenario_analysis() {
    printf("\n\n");
    printf("========================================\n");
    printf("       АНАЛИЗ РАЗЛИЧНЫХ СЦЕНАРИЕВ       \n");
    printf("========================================\n\n");
    
    
    printf("Сценарий 1: Высокая инфляция (15%%)\n");
    printf("Сценарий 2: Низкая инфляция (5%%)\n");
    printf("Сценарий 3: Экономический кризис\n");
    printf("Сценарий 4: Стабильная экономика\n\n");
    
    
    printf("Для более детального анализа запустите программу несколько раз\n");
    printf("с различными начальными параметрами (ставки, суммы и т.д.)\n");
}


int main() {


srand(time(NULL));
    
    
    printf("========================================\n");
    printf("   СИМУЛЯЦИЯ ЖИЗНИ: АЛИСА vs БОБ      \n");
    printf("========================================\n\n");
    
    
    printf("Алиса берет ипотеку на квартиру\n");
    printf("Боб копит деньги на вкладе\n");
    printf("Сравнение результатов через 20 лет\n\n");
    
    
    alice_init();
    bob_init();
    
    
    printf("Начальные данные:\n");
    printf("  Алиса: зарплата %lld руб., ипотека %lld руб. на 20 лет\n", 
           alice.salary, alice.vtb.credit_amount);
    printf("  Боб:   зарплата %lld руб., вклад %lld руб. под %.1f%%\n\n", 
           bob.salary, bob.deposit.amount, bob.deposit.rate);
    

    simulation();
    
    
    print_results();
    
    
    scenario_analysis();
    
    
    printf("\nПрограмма завершена. Спасибо за использование!\n");
    
    
    return 0;
}
