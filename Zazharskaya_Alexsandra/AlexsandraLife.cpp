#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

// ---глобальные переменные---
int current_year = 2024;
int current_month = 1;
float annual_inflation = 9.2; // проценты в год

typedef long long int RUB; // тип для денег

// ---вспомогательные функции---
float inflation_monthly(float amount) {
    return amount * (1.0 + annual_inflation / 100.0 / 12.0);
}

RUB inflation_monthly_rub(RUB amount) {
    return (RUB)(amount * (1.0 + annual_inflation / 100.0 / 12.0));
}

int random_int(int from, int to) {
    return from + rand() % (to - from + 1);
}

// ---структура для событий---
struct LifeEvent {
    int year;
    int month;
    string description;
    RUB money_change;
};

// ---структура для болезней---
struct Illness {
    string name;
    int min_days;
    int max_days;
    RUB doctor_cost;
    RUB medicine_min;
    RUB medicine_max;
    int chance_per_month;
};

// ---все возможные болезни---
vector<Illness> illness_list = {
    {"простуда", 3, 7, 0, 300, 1500, 25},
    {"грипп", 5, 10, 1000, 2000, 5000, 10},
    {"ангина", 4, 8, 1500, 1500, 4000, 8},
    {"отравление", 2, 5, 2000, 1000, 3000, 5},
    {"бронхит", 7, 14, 2500, 3000, 8000, 4},
    {"пневмония", 10, 21, 5000, 8000, 20000, 2},
    {"аллергия", 5, 15, 2000, 2000, 6000, 6},
    {"мигрень", 1, 3, 1000, 500, 1500, 12},
    {"гастрит", 3, 7, 2000, 1500, 4000, 5},
    {"травма", 5, 20, 5000, 3000, 15000, 3},
    {"зубная боль", 1, 3, 3000, 500, 2000, 8},
    {"депрессия", 10, 30, 5000, 2000, 8000, 2},
    {"миозит", 4, 10, 2000, 1000, 3000, 5},
    {"отит", 3, 7, 2500, 1500, 4000, 4},
    {"гайморит", 5, 12, 3000, 2000, 5000, 3}
};

// ---структура для отпуска---
struct Vacation {
    string country;
    string city;
    int days;
    RUB flight_cost;
    RUB hotel_per_day;
    RUB food_per_day;
    RUB entertainment_cost;
    bool went;
};

// ---все возможные направления для отпуска---
vector<Vacation> vacation_list = {
    {"Турция", "Анталия", 10, 25000, 4000, 2000, 15000, false},
    {"Египет", "Хургада", 10, 28000, 3500, 1800, 12000, false},
    {"Таиланд", "Пхукет", 14, 45000, 3000, 1500, 20000, false},
    {"Италия", "Рим", 7, 35000, 6000, 3000, 25000, false},
    {"Франция", "Париж", 7, 38000, 6500, 3500, 30000, false},
    {"Испания", "Барселона", 7, 32000, 5500, 2800, 22000, false},
    {"Греция", "Крит", 10, 30000, 4500, 2200, 18000, false},
    {"Кипр", "Лимассол", 10, 28000, 5000, 2500, 15000, false},
    {"ОАЭ", "Дубай", 7, 40000, 8000, 4000, 35000, false},
    {"Грузия", "Тбилиси", 7, 15000, 3000, 1500, 8000, false},
    {"Абхазия", "Гагра", 7, 8000, 2000, 1200, 5000, false},
    {"Крым", "Ялта", 10, 12000, 2500, 1500, 7000, false},
    {"Сочи", "Краснодарский край", 10, 10000, 3000, 1800, 8000, false},
    {"Санкт-Петербург", "Питер", 5, 4000, 3500, 2000, 6000, false},
    {"Казань", "Казань", 5, 3500, 2800, 1800, 5000, false},
    {"Вьетнам", "Нячанг", 12, 40000, 2500, 1200, 15000, false},
    {"Шри-Ланка", "Коломбо", 12, 48000, 3000, 1500, 18000, false},
    {"Мальдивы", "Мале", 7, 60000, 12000, 6000, 50000, false}
};

// ---структура для членов семьи---
struct FamilyMember {
    string name;
    string relation;
    int age;
    bool is_alive;
    bool lives_together;
    RUB monthly_help; // положительное - дает деньги, отрицательное - требует
};

// ---структура для работы---
struct Job {
    string company;
    string position;
    RUB salary;
    int start_year;
    int end_year;
    bool is_current;
};

// ---структура для кредита---
struct Credit {
    string purpose;
    RUB amount;
    RUB monthly_payment;
    int months_left;
    float percent;
};

// ---структура для образования---
struct Education {
    string institution;
    string degree;
    int start_year;
    int end_year;
    RUB cost;
    bool is_graduated;
};

// ------------------------------------------------------------------
// КЛАСС ЧЕЛОВЕК (ЗАЖАРСКАЯ АЛЕКСАНДРА)
// ------------------------------------------------------------------

class Alexandra {
private:
    string last_name;
    string first_name;
    string middle_name;
    int birth_day;
    int birth_month;
    int birth_year;
    
    vector<LifeEvent> events_history;
    vector<FamilyMember> family;
    vector<Vacation> vacations_taken;
    vector<Job> jobs_history;
    vector<Credit> credits;
    vector<Education> education_history;
    
public:
    // основные данные
    int age;
    RUB salary_main;
    RUB salary_extra;
    RUB pension;
    bool is_retired;
    bool is_married;
    bool have_children;
    int children_count;
    vector<int> children_ages;
    vector<string> children_names;
    
    // деньги
    RUB cash;          // наличные
    RUB card;          // на карте
    RUB savings;       // сбережения
    RUB investments;   // инвестиции
    RUB debt;          // долги
    RUB gold;          // золото
    RUB foreign_currency; // валюта
    
    // расходы
    RUB food_expense;
    RUB utilities_expense;
    RUB clothes_expense;
    RUB health_expense;
    RUB home_expense;
    RUB transport_expense;
    RUB internet_expense;
    RUB entertainment_expense;
    RUB gifts_expense;
    RUB education_expense;
    RUB charity_expense;
    RUB pets_expense;
    RUB beauty_expense;
    RUB sports_expense;
    RUB books_expense;
    RUB courses_expense;
    RUB other_expense;
    
    // статистика
    int sick_days_total;
    RUB total_earned;
    RUB total_spent;
    RUB total_tax_paid;
    int happy_count;
    int sad_count;
    int vacation_days_total;
    int promotions_count;
    int fired_count;
    int moved_count;
    int friends_count;
    int conflicts_count;
    
    // ---конструктор---
    Alexandra(string last, string first, string middle, int day, int month, int year) {
        last_name = last;
        first_name = first;
        middle_name = middle;
        birth_day = day;
        birth_month = month;
        birth_year = year;
        
        // расчет возраста
        age = current_year - birth_year;
        if (current_month < birth_month) age--;
        if (current_month == birth_month && 1 < birth_day) age--;
        
        // работа и доходы
        salary_main = 65000;
        salary_extra = 0;
        pension = 0;
        is_retired = false;
        is_married = false;
        have_children = false;
        children_count = 0;
        
        // деньги
        cash = 0;
        card = 0;
        savings = 0;
        investments = 0;
        debt = 0;
        gold = 0;
        foreign_currency = 0;
        
        // расходы базовые
        food_expense = 12000;
        utilities_expense = 5500;
        clothes_expense = 3000;
        health_expense = 2000;
        home_expense = 2000;
        transport_expense = 2500;
        internet_expense = 1500;
        entertainment_expense = 3000;
        gifts_expense = 1500;
        education_expense = 0;
        charity_expense = 0;
        pets_expense = 0;
        beauty_expense = 2000;
        sports_expense = 0;
        books_expense = 500;
        courses_expense = 0;
        other_expense = 1500;
        
        // статистика
        sick_days_total = 0;
        total_earned = 0;
        total_spent = 0;
        total_tax_paid = 0;
        happy_count = 0;
        sad_count = 0;
        vacation_days_total = 0;
        promotions_count = 0;
        fired_count = 0;
        moved_count = 0;
        friends_count = 3;
        conflicts_count = 0;
        
        // семья
        FamilyMember mom = {"Елена", "мама", 45, true, false, 0};
        FamilyMember dad = {"Виктор", "папа", 48, true, false, 0};
        FamilyMember grandma = {"Нина", "бабушка", 70, true, false, 2000};
        FamilyMember grandpa = {"Иван", "дедушка", 72, true, false, 1500};
        
        family.push_back(mom);
        family.push_back(dad);
        family.push_back(grandma);
        family.push_back(grandpa);
        
        // друзья
        friends_count = random_int(2, 5);
        
        cout << "=== СОЗДАН ЧЕЛОВЕК ===" << endl;
        cout << last_name << " " << first_name << " " << middle_name << endl;
        cout << "дата рождения: " << day << "." << month << "." << year << endl;
        cout << "возраст: " << age << " лет" << endl;
        cout << "======================" << endl;
        
        add_event("рождение", 0);
    }
    
    // ---добавить событие в историю---
    void add_event(string desc, RUB money = 0) {
        LifeEvent ev;
        ev.year = current_year;
        ev.month = current_month;
        ev.description = desc;
        ev.money_change = money;
        events_history.push_back(ev);
    }
    
    // ---получить полное имя---
    string get_full_name() {
        return last_name + " " + first_name + " " + middle_name;
    }
    
    // ---день рождения---
    void celebrate_birthday() {
        age++;
        cout << "--- У " << first_name << " ДЕНЬ РОЖДЕНИЯ! исполнилось " << age << " лет ---" << endl;
        
        // подарки от родственников
        RUB gifts_sum = 0;
        for (auto& m : family) {
            if (m.is_alive && random_int(1, 100) <= 70) {
                RUB gift = random_int(1000, 5000);
                gifts_sum += gift;
                cout << "  от " << m.name << " подарок " << gift << " руб" << endl;
            }
        }
        
        // подарки от друзей
        if (friends_count > 0) {
            RUB friends_gifts = random_int(500, 2000) * friends_count;
            gifts_sum += friends_gifts;
            cout << "  от друзей подарки " << friends_gifts << " руб" << endl;
        }
        
        if (gifts_sum > 0) {
            receive_money(gifts_sum, "подарки на день рождения");
        }
        
        // траты на праздник
        if (random_int(1, 100) <= 60) {
            RUB party_cost = random_int(3000, 15000);
            spend_money(party_cost, "празднование дня рождения");
        }
        
        if (age == 18) {
            cout << "  СОВЕРШЕННОЛЕТИЕ! получение паспорта" << endl;
            add_event("совершеннолетие", 0);
        }
        if (age == 21) {
            cout << "  возраст - можно замуж" << endl;
            add_event("21 год", 0);
        }
        if (age == 22) {
            cout << "  окончание института" << endl;
            add_event("окончание института", 0);
            salary_main += 15000;
        }
        if (age == 25) {
            cout << "  четверть века!" << endl;
            add_event("25 лет", 0);
        }
        if (age == 30) {
            cout << "  30 лет - серьезный возраст" << endl;
            add_event("30 лет", 0);
        }
        if (age == 33) {
            cout << "  возраст Христа" << endl;
        }
        if (age == 35) {
            cout << "  35 лет" << endl;
            add_event("35 лет", 0);
        }
        if (age == 40) {
            cout << "  40 лет - юбилей" << endl;
            add_event("40 лет", 0);
        }
        if (age == 45) {
            cout << "  45 лет" << endl;
            add_event("45 лет", 0);
        }
        if (age == 50) {
            cout << "  ПОЛВЕКА!" << endl;
            add_event("50 лет", 0);
        }
        if (age == 55) {
            cout << "  55 лет" << endl;
            add_event("55 лет", 0);
            if (!is_retired) {
                cout << "  предпенсионный возраст" << endl;
            }
        }
        if (age == 60) {
            cout << "  60 лет" << endl;
            add_event("60 лет", 0);
        }
        if (age >= 65 && !is_retired) {
            is_retired = true;
            pension = salary_main * 0.4;
            cout << "  ВЫХОД НА ПЕНСИЮ! пенсия " << pension << " руб/мес" << endl;
            add_event("выход на пенсию", 0);
        }
        if (age == 70) {
            cout << "  70 лет - мудрость" << endl;
            add_event("70 лет", 0);
        }
        if (age == 75) {
            cout << "  75 лет" << endl;
            add_event("75 лет", 0);
        }
        if (age == 80) {
            cout << "  80 лет - большой юбилей" << endl;
            add_event("80 лет", 0);
        }
    }
    
    // ---события, связанные с работой---
    void work_events() {
        if (is_retired) return;
        
        int event = random_int(1, 100);
        
        if (event <= 5) { // повышение
            RUB old_salary = salary_main;
            salary_main = salary_main * (100 + random_int(10, 30)) / 100;
            promotions_count++;
            cout << "  ПОВЫШЕНИЕ НА РАБОТЕ! зарплата была " << old_salary << " руб, стала " << salary_main << " руб" << endl;
            add_event("повышение на работе", 0);
            happy_count += 2;
        }
        else if (event <= 8) { // премия
            RUB bonus = salary_main * random_int(20, 100) / 100;
            receive_money(bonus, "премия на работе");
            cout << "  премия на работе " << bonus << " руб" << endl;
            happy_count++;
        }
        else if (event <= 10) { // увольнение
            cout << "  УВОЛЬНЕНИЕ С РАБОТЫ" << endl;
            fired_count++;
            sad_count += 3;
            add_event("увольнение", 0);
            
            // поиск новой работы
            int months_unemployed = random_int(1, 6);
            for (int i = 0; i < months_unemployed; i++) {
                // пропуск зарплаты на несколько месяцев
            }
            cout << "  поиск новой работы займет " << months_unemployed << " месяцев" << endl;
        }
        else if (event <= 13) { // смена работы
            RUB old_salary = salary_main;
            salary_main = salary_main * (100 + random_int(-10, 40)) / 100;
            cout << "  СМЕНА РАБОТЫ! зарплата была " << old_salary << " руб, стала " << salary_main << " руб" << endl;
            add_event("смена работы", 0);
        }
        else if (event <= 16) { // конфликт на работе
            cout << "  конфликт на работе" << endl;
            conflicts_count++;
            sad_count++;
            add_event("конфликт на работе", 0);
        }
        else if (event <= 18) { // новый проект
            RUB extra = salary_main * random_int(5, 15) / 100;
            receive_money(extra, "премия за проект");
            cout << "  успешный проект, премия " << extra << " руб" << endl;
            happy_count++;
        }
    }
    
    // ---замужество---
    void get_married() {
        if (is_married) return;
        if (age < 18) return;
        
        if (random_int(1, 1000) <= 8 && age >= 22 && age <= 40) { // 0.8% шанс в месяц
            is_married = true;
            cout << "  АЛЕКСАНДРА ВЫШЛА ЗАМУЖ!" << endl;
            add_event("замужество", 0);
            
            // расходы на свадьбу
            RUB wedding_cost = random_int(200000, 800000);
            if (savings >= wedding_cost) {
                savings -= wedding_cost;
                spend_money(wedding_cost, "свадьба");
                cout << "  свадьба обошлась в " << wedding_cost << " руб" << endl;
            } else {
                RUB need = wedding_cost - savings;
                savings = 0;
                debt += need;
                spend_money(wedding_cost, "свадьба (в кредит)");
                cout << "  свадьба " << wedding_cost << " руб, взят кредит " << need << " руб" << endl;
                
                Credit cr;
                cr.purpose = "свадьба";
                cr.amount = need;
                cr.monthly_payment = need / 60; // на 5 лет
                cr.months_left = 60;
                cr.percent = 12.0;
                credits.push_back(cr);
            }
            
            // муж приносит доход
            salary_extra += random_int(20000, 60000);
            friends_count += random_int(1, 3); // новые знакомые
        }
    }
    
    // ---развод---
    void get_divorced() {
        if (!is_married) return;
        
        if (random_int(1, 1000) <= 2 && age >= 25) { // 0.2% шанс в месяц
            is_married = false;
            cout << "  РАЗВОД!" << endl;
            add_event("развод", 0);
            
            salary_extra = 0;
            sad_count += 5;
            
            // раздел имущества
            RUB loss = savings * random_int(30, 50) / 100;
            savings -= loss;
            cout << "  потери при разделе имущества: " << loss << " руб" << endl;
            spend_money(loss, "развод (раздел имущества)");
        }
    }
    
    // ---рождение детей---
    void have_baby() {
        if (!is_married) return;
        if (have_children && children_count >= 4) return;
        if (age < 20 || age > 45) return;
        
        int chance = 15; // базовый шанс в год
        if (have_children) chance = 10;
        
        if (random_int(1, 1200) <= chance) { // примерно 1% в месяц
            have_children = true;
            children_count++;
            int baby_age = 0;
            children_ages.push_back(baby_age);
            
            string baby_names[] = {"Анна", "Мария", "Екатерина", "Ольга", "Татьяна", "Дарья", "Елена"};
            string baby_name = baby_names[random_int(0, 6)];
            children_names.push_back(baby_name);
            
            cout << "  РОЖДЕНИЕ РЕБЕНКА! " << baby_name << endl;
            add_event("рождение ребенка " + baby_name, 0);
            
            // расходы на ребенка
            RUB baby_cost = random_int(50000, 200000);
            if (savings >= baby_cost) {
                savings -= baby_cost;
                spend_money(baby_cost, "ребенок (приданое)");
            } else {
                RUB need = baby_cost - savings;
                savings = 0;
                debt += need;
                spend_money(baby_cost, "ребенок (в кредит)");
                
                Credit cr;
                cr.purpose = "рождение ребенка";
                cr.amount = need;
                cr.monthly_payment = need / 36;
                cr.months_left = 36;
                cr.percent = 10.0;
                credits.push_back(cr);
            }
            
            // увеличиваем расходы
            food_expense += 5000;
            clothes_expense += 2000;
            education_expense += 2000;
            health_expense += 1000;
            
            cout << "  теперь детей: " << children_count << endl;
            happy_count += 5;
        }
    }
    
    // ---дети растут---
    void children_grow() {
        for (int i = 0; i < children_ages.size(); i++) {
            children_ages[i]++;
            
            // ребенок идет в сад
            if (children_ages[i] == 3) {
                education_expense += 5000;
                cout << "  ребенок " << children_names[i] << " пошел в садик, расходы +5000 руб" << endl;
            }
            
            // ребенок идет в школу
            if (children_ages[i] == 7) {
                education_expense += 3000;
                clothes_expense += 2000;
                cout << "  ребенок " << children_names[i] << " пошел в школу, расходы +5000 руб" << endl;
            }
            
            // ребенок идет в институт
            if (children_ages[i] == 17) {
                education_expense += 15000;
                cout << "  ребенок " << children_names[i] << " поступил в институт, расходы +15000 руб" << endl;
            }
            
            // ребенок начинает работать
            if (children_ages[i] == 22) {
                education_expense -= 10000;
                salary_extra += 10000;
                cout << "  ребенок " << children_names[i] << " начал работать, помогает семье" << endl;
            }
            
            // ребенок съезжает
            if (children_ages[i] == 25 && random_int(1, 100) <= 70) {
                food_expense -= 3000;
                utilities_expense -= 1000;
                cout << "  ребенок " << children_names[i] << " съехал, расходы уменьшились" << endl;
            }
        }
    }
    
    // ---события с друзьями---
    void friend_events() {
        int event = random_int(1, 100);
        
        if (event <= 3) { // новый друг
            friends_count++;
            cout << "  появился новый друг, теперь друзей: " << friends_count << endl;
            happy_count++;
            add_event("новый друг", 0);
        }
        else if (event <= 5) { // потеря друга
            if (friends_count > 0) {
                friends_count--;
                cout << "  потеря друга, осталось друзей: " << friends_count << endl;
                sad_count++;
                add_event("потеря друга", 0);
            }
        }
        else if (event <= 8) { // помощь другу
            RUB help = random_int(1000, 10000);
            spend_money(help, "помощь другу");
            cout << "  помощь другу " << help << " руб" << endl;
        }
        else if (event <= 10) { // друг помогает
            RUB help = random_int(1000, 5000);
            receive_money(help, "помощь от друга");
            cout << "  помощь от друга " << help << " руб" << endl;
        }
    }
    
    // ---события с родственниками---
    void family_events() {
        for (auto& m : family) {
            if (!m.is_alive) continue;
            
            // родственники стареют
            m.age++;
            
            // смерть родственника
            if (m.age > 70 && random_int(1, 500) == 1) {
                m.is_alive = false;
                cout << "  УМЕР " << m.relation << " " << m.name << endl;
                add_event("смерть " + m.relation + " " + m.name, 0);
                sad_count += 3;
                
                // возможно наследство
                if (random_int(1, 100) <= 30) {
                    RUB inheritance = random_int(50000, 500000);
                    receive_money(inheritance, "наследство от " + m.name);
                    cout << "  получено наследство " << inheritance << " руб" << endl;
                }
            }
            
            // болезнь родственника
            if (m.age > 60 && random_int(1, 100) <= 2) {
                RUB help = random_int(10000, 50000);
                spend_money(help, "помощь " + m.relation + " " + m.name + " (лечение)");
                cout << "  помощь на лечение " << m.relation << " " << help << " руб" << endl;
            }
        }
        
        // помощь от семьи
        for (auto& m : family) {
            if (m.is_alive && m.monthly_help > 0) {
                receive_money(m.monthly_help, "помощь от " + m.name);
            }
            if (m.is_alive && m.monthly_help < 0 && m.lives_together) {
                RUB need = -m.monthly_help;
                spend_money(need, "помощь " + m.name);
            }
        }
    }
    
    // ---кредиты---
    void handle_credits() {
        for (int i = 0; i < credits.size(); i++) {
            if (credits[i].months_left > 0) {
                spend_money(credits[i].monthly_payment, "кредит: " + credits[i].purpose);
                credits[i].months_left--;
                credits[i].amount -= credits[i].monthly_payment;
            }
        }
        
        // удалить выплаченные кредиты
        credits.erase(
            remove_if(credits.begin(), credits.end(), 
                [](Credit cr) { return cr.months_left <= 0; }),
            credits.end()
        );
    }
    
    // ---взять кредит---
    void take_credit(RUB amount, string purpose) {
        Credit cr;
        cr.purpose = purpose;
        cr.amount = amount;
        cr.months_left = 60;
        cr.monthly_payment = amount / 60 + (amount * 15 / 100 / 60);
        cr.percent = 15.0;
        credits.push_back(cr);
        
        receive_money(amount, "кредит на " + purpose);
        debt += amount;
        
        cout << "  взят кредит на " << amount << " руб на " << purpose << endl;
        add_event("взят кредит на " + purpose, amount);
    }
    
    // ---образование---
    void study() {
        if (age > 30) return; // после 30 редко учатся
        
        if (random_int(1, 500) == 1 && age < 25) {
            cout << "  ПОСТУПЛЕНИЕ НА КУРСЫ ПОВЫШЕНИЯ КВАЛИФИКАЦИИ" << endl;
            
            RUB course_cost = random_int(30000, 150000);
            if (savings >= course_cost) {
                savings -= course_cost;
                spend_money(course_cost, "курсы");
                courses_expense += course_cost / 12;
                
                // после курсов зарплата растет
                salary_main = salary_main * 115 / 100;
                cout << "  после курсов зарплата выросла до " << salary_main << " руб" << endl;
                add_event("окончание курсов", -course_cost);
            }
        }
    }
    
    // ---получение денег---
    void receive_money(RUB amount, string source) {
        RUB to_card = amount * 70 / 100;
        RUB to_cash = amount * 30 / 100;
        
        card += to_card;
        cash += to_cash;
        total_earned += amount;
        
        cout << "  ПОЛУЧЕНО: " << amount << " руб (" << source << ")" << endl;
        
        add_event("доход: " + source, amount);
    }
    
    // ---трата денег---
    bool spend_money(RUB amount, string purpose) {
        RUB left = amount;
        
        if (card > 0) {
            RUB from_card = (card >= left) ? left : card;
            card -= from_card;
            left -= from_card;
        }
        
        if (left > 0) {
            if (cash >= left) {
                cash -= left;
            } else {
                cout << "    НЕ ХВАТАЕТ " << left - cash << " РУБ!" << endl;
                sad_count++;
                return false;
            }
        }
        
        total_spent += amount;
        cout << "    ПОТРАЧЕНО: " << amount << " руб (" << purpose << ")" << endl;
        
        if (amount > 20000) {
            sad_count++;
        } else if (amount > 0) {
            happy_count++;
        }
        
        add_event("расход: " + purpose, -amount);
        return true;
    }
    
    // ---получить зарплату---
    void get_salary() {
        RUB tax = salary_main * 13 / 100;
        RUB net = salary_main - tax;
        total_tax_paid += tax;
        
        receive_money(net, "зарплата");
        cout << "    начислено: " << salary_main << " руб, налог: " << tax << " руб" << endl;
        
        if (salary_extra > 0) {
            RUB extra_tax = salary_extra * 13 / 100;
            RUB extra_net = salary_extra - extra_tax;
            total_tax_paid += extra_tax;
            receive_money(extra_net, "дополнительный доход");
        }
    }
    
    // ---посчитать все расходы за месяц---
    RUB get_total_expenses() {
        return food_expense + utilities_expense + clothes_expense + 
               health_expense + home_expense + transport_expense + 
               internet_expense + entertainment_expense + gifts_expense + 
               education_expense + charity_expense + pets_expense +
               beauty_expense + sports_expense + books_expense + 
               courses_expense + other_expense;
    }
    
    // ---оплата счетов---
    void pay_bills(int sick_days = 0) {
        cout << "--- ЕЖЕМЕСЯЧНЫЕ РАСХОДЫ ---" << endl;
        
        spend_money(utilities_expense, "коммунальные услуги");
        spend_money(food_expense, "продукты");
        spend_money(home_expense, "товары для дома");
        spend_money(internet_expense, "интернет и связь");
        spend_money(transport_expense, "транспорт");
        spend_money(beauty_expense, "косметика/парикмахерская");
        
        if (pets_expense > 0) {
            spend_money(pets_expense, "животные");
        }
        
        if (sports_expense > 0) {
            spend_money(sports_expense, "спорт");
        }
        
        if (books_expense > 0) {
            if (random_int(1, 100) <= 40) {
                spend_money(books_expense, "книги");
            }
        }
        
        if (education_expense > 0) {
            spend_money(education_expense, "образование");
        }
        
        if (sick_days > 0) {
            RUB treatment = health_expense + sick_days * 300;
            spend_money(treatment, "лечение");
            sick_days_total += sick_days;
        } else {
            if (random_int(1, 100) <= 30) {
                spend_money(health_expense, "витамины/профилактика");
            }
        }
        
        if (random_int(1, 100) <= 20) {
            spend_money(clothes_expense, "одежда");
        }
        
        if (random_int(1, 100) <= 30) {
            spend_money(entertainment_expense, "развлечения");
        }
        
        if (current_month == 1 || current_month == 2 || current_month == 3 || 
            current_month == 8 || current_month == 9 || current_month == 12) {
            spend_money(gifts_expense * 2, "подарки");
        }
        
        if (random_int(1, 100) <= 10) {
            spend_money(charity_expense, "благотворительность");
        }
        
        if (random_int(1, 100) <= 15) {
            spend_money(other_expense, "прочие расходы");
        }
        
        cout << "---------------------------" << endl;
    }
    
    // ---отложить деньги---
    void save_up(RUB amount) {
        if (card >= amount) {
            card -= amount;
            savings += amount;
            cout << "  ОТЛОЖЕНО В СБЕРЕЖЕНИЯ: " << amount << " руб" << endl;
        } else {
            cout << "  недостаточно денег на карте для сбережений" << endl;
        }
    }
    
    // ---инвестиции---
    void invest_money() {
        if (savings < 100000) return;
        
        RUB invest_amount = savings * 0.2;
        if (invest_amount > 200000) invest_amount = 200000;
        
        savings -= invest_amount;
        investments += invest_amount;
        cout << "  ИНВЕСТИРОВАНО: " << invest_amount << " руб" << endl;
        
        // случайная доходность
        int profit_percent = random_int(-20, 35);
        RUB profit = investments * profit_percent / 100;
        investments += profit;
        
        if (profit > 0) {
            cout << "  доход от инвестиций: +" << profit << " руб (" << profit_percent << "%)" << endl;
            happy_count++;
        } else if (profit < 0) {
            cout << "  убыток от инвестиций: " << profit << " руб (" << profit_percent << "%)" << endl;
            sad_count++;
        }
        
        add_event("инвестиции", profit);
    }
    
    // ---покупка золота---
    void buy_gold() {
        if (savings < 50000) return;
        
        RUB gold_amount = savings * 0.1;
        if (gold_amount > 100000) gold_amount = 100000;
        
        savings -= gold_amount;
        gold += gold_amount;
        cout << "  КУПЛЕНО ЗОЛОТО на " << gold_amount << " руб" << endl;
    }
    
    // ---покупка валюты---
    void buy_currency() {
        if (savings < 50000) return;
        
        RUB currency_amount = savings * 0.1;
        if (currency_amount > 100000) currency_amount = 100000;
        
        savings -= currency_amount;
        foreign_currency += currency_amount;
        cout << "  КУПЛЕНО ВАЛЮТЫ на " << currency_amount << " руб" << endl;
    }
    
    // ---заболеть---
    void get_ill() {
        int index = random_int(0, illness_list.size() - 1);
        Illness ill = illness_list[index];
        
        int chance = ill.chance_per_month;
        if (random_int(1, 100) <= chance) {
            int days = random_int(ill.min_days, ill.max_days);
            cout << "  АЛЕКСАНДРА ЗАБОЛЕЛА: " << ill.name << " (" << days << " дней)" << endl;
            
            RUB doctor = ill.doctor_cost;
            RUB medicine = random_int(ill.medicine_min, ill.medicine_max);
            RUB total_cost = doctor + medicine;
            
            cout << "  стоимость лечения: " << total_cost << " руб" << endl;
            spend_money(total_cost, "лечение: " + ill.name);
            
            add_event("болезнь " + ill.name, -total_cost);
            sick_days_total += days;
            
            // потеря зарплаты из-за болезни
            if (!is_retired) {
                RUB lost = (salary_main / 22) * min(days, 14);
                if (lost > 0) {
                    cout << "  потеря зарплаты за больничный: " << lost << " руб" << endl;
                    total_earned -= lost;
                }
            }
        }
    }
    
    // ---отпуск---
    void go_vacation() {
        if (is_retired) {
            // пенсионеры могут ездить чаще
            if (random_int(1, 100) > 10) return;
        } else {
            if (random_int(1, 100) > 8) return; // примерно раз в год
        }
        
        if (savings < 100000) return;
        
        int index = random_int(0, vacation_list.size() - 1);
        Vacation vac = vacation_list[index];
        
        RUB total_cost = vac.flight_cost + 
                        (vac.hotel_per_day + vac.food_per_day) * vac.days + 
                        vac.entertainment_cost;
        
        total_cost = inflation_monthly_rub(total_cost);
        
        if (savings >= total_cost) {
            savings -= total_cost;
            cout << "  АЛЕКСАНДРА ПОЕХАЛА В ОТПУСК: " << vac.country << ", " << vac.city << endl;
            cout << "  на " << vac.days << " дней, стоимость " << total_cost << " руб" << endl;
            
            vacation_days_total += vac.days;
            vac.went = true;
            vacations_taken.push_back(vac);
            happy_count += 3;
            add_event("отпуск в " + vac.country, -total_cost);
            
            // шанс заболеть в отпуске
            if (random_int(1, 100) <= 15) {
                cout << "  заболела в отпуске!" << endl;
                get_ill();
            }
        }
    }
    
    // ---индексация зарплаты---
    void index_salary() {
        if (is_retired) return;
        
        int percent = random_int(3, 10);
        salary_main = salary_main * (100 + percent) / 100;
        cout << "  ИНДЕКСАЦИЯ ЗАРПЛАТЫ: +" << percent << "%, теперь " << salary_main << " руб" << endl;
    }
    
    // ---случайные события---
    void random_event() {
        int event_type = random_int(1, 200);
        
        if (event_type == 1) { // выигрыш в лотерею
            RUB win = random_int(10000, 200000);
            receive_money(win, "выигрыш в лотерею");
            happy_count += 3;
            add_event("выигрыш в лотерею", win);
        }
        else if (event_type == 2) { // крупный выигрыш
            RUB win = random_int(200000, 1000000);
            receive_money(win, "крупный выигрыш");
            happy_count += 5;
            add_event("крупный выигрыш", win);
        }
        else if (event_type == 3) { // потеря кошелька
            RUB loss = min(cash, (RUB)random_int(1000, 10000));
            if (loss > 0) {
                cash -= loss;
                spend_money(loss, "потеря кошелька");
                sad_count += 2;
            }
        }
        else if (event_type == 4) { // кража
            RUB stolen = min(cash, (RUB)random_int(5000, 30000));
            if (stolen > 0) {
                cash -= stolen;
                spend_money(stolen, "кража");
                sad_count += 3;
            }
        }
        else if (event_type == 5) { // нашли деньги
            RUB found = random_int(100, 5000);
            receive_money(found, "нашли деньги");
        }
        else if (event_type == 6) { // сломался телефон
            RUB repair = random_int(3000, 15000);
            spend_money(repair, "ремонт телефона");
        }
        else if (event_type == 7) { // сломался компьютер
            RUB repair = random_int(5000, 25000);
            spend_money(repair, "ремонт компьютера");
        }
        else if (event_type == 8) { // сломался холодильник
            RUB repair = random_int(8000, 30000);
            spend_money(repair, "ремонт холодильника");
        }
        else if (event_type == 9) { // сломалась стиральная машина
            RUB repair = random_int(5000, 20000);
            spend_money(repair, "ремонт стиральной машины");
        }
        else if (event_type == 10) { // штраф за парковку
            RUB fine = random_int(500, 3000);
            spend_money(fine, "штраф за парковку");
        }
        else if (event_type == 11) { // штраф за превышение скорости
            RUB fine = random_int(500, 5000);
            spend_money(fine, "штраф за скорость");
        }
        else if (event_type == 12) { // возврат налогового вычета
            RUB refund = random_int(5000, 40000);
            receive_money(refund, "налоговый вычет");
        }
        else if (event_type == 13) { // кэшбэк
            RUB cashback = random_int(500, 3000);
            receive_money(cashback, "кэшбэк");
        }
        else if (event_type == 14) { // подарок от начальника
            RUB gift = random_int(2000, 10000);
            receive_money(gift, "подарок от начальника");
        }
        else if (event_type == 15) { // сосед просит в долг
            RUB loan = random_int(1000, 5000);
            if (random_int(1, 100) <= 50) {
                spend_money(loan, "долг соседу");
                if (random_int(1, 100) <= 30) {
                    // сосед вернул
                    receive_money(loan, "сосед вернул долг");
                }
            }
        }
        else if (event_type == 16) { // выигрыш в конкурсе
            RUB win = random_int(2000, 15000);
            receive_money(win, "выигрыш в конкурсе");
        }
        else if (event_type == 17) { // продажа ненужных вещей
            RUB sell = random_int(1000, 10000);
            receive_money(sell, "продажа вещей");
        }
        else if (event_type == 18) { // покупка ненужной вещи
            RUB buy = random_int(1000, 5000);
            spend_money(buy, "импульсивная покупка");
        }
        else if (event_type == 19) { // поход в ресторан
            RUB restaurant = random_int(2000, 8000);
            spend_money(restaurant, "ресторан");
        }
        else if (event_type == 20) { // поход в кино
            RUB cinema = random_int(500, 2000);
            spend_money(cinema, "кино");
        }
        else if (event_type == 21) { // поход в театр
            RUB theater = random_int(1000, 4000);
            spend_money(theater, "театр");
        }
        else if (event_type == 22) { // поход в музей
            RUB museum = random_int(300, 1500);
            spend_money(museum, "музей");
        }
        else if (event_type == 23) { // поход в спортзал (разово)
            RUB gym = random_int(500, 2000);
            spend_money(gym, "разовое посещение спортзала");
        }
        else if (event_type == 24) { // покупка абонемента в спортзал
            sports_expense += 2000;
            cout << "  куплен абонемент в спортзал, расходы +2000 руб/мес" << endl;
        }
        else if (event_type == 25) { // завести питомца
            if (pets_expense == 0) {
                pets_expense = random_int(2000, 5000);
                cout << "  ЗАВЕЛА ПИТОМЦА, расходы +" << pets_expense << " руб/мес" << endl;
                RUB buy_pet = random_int(5000, 30000);
                spend_money(buy_pet, "покупка питомца");
            }
        }
        else if (event_type == 26) { // потеря питомца
            if (pets_expense > 0) {
                pets_expense = 0;
                cout << "  питомец пропал" << endl;
                sad_count += 3;
            }
        }
        else if (event_type == 27) { // переезд
            RUB move_cost = random_int(10000, 50000);
            spend_money(move_cost, "переезд");
            moved_count++;
        }
        else if (event_type == 28) { // ремонт в квартире
            RUB repair_cost = random_int(30000, 200000);
            spend_money(repair_cost, "ремонт в квартире");
        }
        else if (event_type == 29) { // покупка мебели
            RUB furniture = random_int(10000, 100000);
            spend_money(furniture, "покупка мебели");
        }
        else if (event_type == 30) { // покупка техники
            RUB tech = random_int(15000, 80000);
            spend_money(tech, "покупка техники");
        }
        else if (event_type == 31) { // день рождения друга
            RUB gift = random_int(1000, 5000);
            spend_money(gift, "подарок другу");
        }
        else if (event_type == 32) { // свадьба друга
            RUB gift = random_int(3000, 10000);
            spend_money(gift, "подарок на свадьбу друга");
        }
        else if (event_type == 33) { // рождение ребенка у друзей
            RUB gift = random_int(1000, 5000);
            spend_money(gift, "подарок на рождение ребенка");
        }
        else if (event_type == 34) { // поездка к родственникам
            RUB trip = random_int(3000, 15000);
            spend_money(trip, "поездка к родственникам");
        }
        else if (event_type == 35) { // курсы повышения квалификации
            RUB courses = random_int(5000, 30000);
            spend_money(courses, "курсы");
            salary_main = salary_main * 105 / 100;
        }
    }
    
    // ---показать состояние---
    void show_status() {
        cout << endl;
        cout << "=======================================" << endl;
        cout << get_full_name() << endl;
        cout << "возраст: " << age << " лет";
        if (is_married) cout << ", замужем";
        if (have_children) cout << ", детей: " << children_count;
        cout << endl;
        cout << "дата: " << current_month << "." << current_year << endl;
        cout << "---------------------------------------" << endl;
        cout << "ДЕНЬГИ:" << endl;
        cout << "  наличные: " << cash << " руб" << endl;
        cout << "  на карте: " << card << " руб" << endl;
        cout << "  сбережения: " << savings << " руб" << endl;
        cout << "  инвестиции: " << investments << " руб" << endl;
        cout << "  золото: " << gold << " руб" << endl;
        cout << "  валюта: " << foreign_currency << " руб" << endl;
        if (debt > 0) cout << "  долги: " << debt << " руб" << endl;
        if (!credits.empty()) cout << "  кредитов: " << credits.size() << endl;
        cout << "  ВСЕГО: " << (cash + card + savings + investments + gold + foreign_currency) << " руб" << endl;
        cout << "---------------------------------------" << endl;
        cout << "ДОХОДЫ:" << endl;
        if (!is_retired) {
            cout << "  зарплата: " << salary_main << " руб/мес" << endl;
            if (salary_extra > 0) cout << "  доп. доход: " << salary_extra << " руб/мес" << endl;
        } else {
            cout << "  пенсия: " << pension << " руб/мес" << endl;
        }
        cout << "---------------------------------------" << endl;
        cout << "РАСХОДЫ в месяц: " << get_total_expenses() << " руб" << endl;
        cout << "  продукты: " << food_expense << endl;
        cout << "  коммуналка: " << utilities_expense << endl;
        cout << "  одежда: " << clothes_expense << endl;
        cout << "  здоровье: " << health_expense << endl;
        cout << "  дом: " << home_expense << endl;
        cout << "  транспорт: " << transport_expense << endl;
        cout << "  связь: " << internet_expense << endl;
        cout << "  развлечения: " << entertainment_expense << endl;
        cout << "  подарки: " << gifts_expense << endl;
        cout << "  образование: " << education_expense << endl;
        cout << "  красота: " << beauty_expense << endl;
        if (sports_expense > 0) cout << "  спорт: " << sports_expense << endl;
        if (pets_expense > 0) cout << "  питомцы: " << pets_expense << endl;
        cout << "  прочее: " << other_expense << endl;
        cout << "---------------------------------------" << endl;
        cout << "СТАТИСТИКА:" << endl;
        cout << "  всего заработано: " << total_earned << " руб" << endl;
        cout << "  всего потрачено: " << total_spent << " руб" << endl;
        cout << "  разница: " << total_earned - total_spent << " руб" << endl;
        cout << "  налоги: " << total_tax_paid << " руб" << endl;
        cout << "  болела: " << sick_days_total << " дней" << endl;
        cout << "  отпуск: " << vacation_days_total << " дней" << endl;
        cout << "  повышений: " << promotions_count << endl;
        cout << "  увольнений: " << fired_count << endl;
        cout << "  переездов: " << moved_count << endl;
        cout << "  друзей: " << friends_count << endl;
        cout << "=======================================" << endl;
    }
    
    // ---показать историю---
    void show_history(int last_n = 20) {
        cout << "--- ПОСЛЕДНИЕ СОБЫТИЯ ---" << endl;
        int start = events_history.size() - last_n;
        if (start < 0) start = 0;
        
        for (int i = start; i < events_history.size(); i++) {
            cout << "  " << events_history[i].year << "." 
                 << setw(2) << setfill('0') << events_history[i].month << " "
                 << setfill(' ') << events_history[i].description;
            if (events_history[i].money_change != 0) {
                cout << " (" << events_history[i].money_change << " руб)";
            }
            cout << endl;
        }
    }
    
    // ---показать отпуска---
    void show_vacations() {
        cout << "--- ОТПУСКА ---" << endl;
        if (vacations_taken.empty()) {
            cout << "  не была в отпуске" << endl;
        } else {
            for (auto& v : vacations_taken) {
                cout << "  " << v.country << ", " << v.city << " - " << v.days << " дней" << endl;
            }
        }
    }
    
    // ---показать кредиты---
    void show_credits() {
        cout << "--- КРЕДИТЫ ---" << endl;
        if (credits.empty()) {
            cout << "  кредитов нет" << endl;
        } else {
            RUB total = 0;
            for (auto& cr : credits) {
                cout << "  " << cr.purpose << ": " << cr.amount << " руб, " 
                     << cr.months_left << " мес, платеж " << cr.monthly_payment << " руб/мес" << endl;
                total += cr.amount;
            }
            cout << "  всего осталось: " << total << " руб" << endl;
        }
    }
};

// ------------------------------------------------------------------
// КЛАСС ДЛЯ МАШИНЫ
// ------------------------------------------------------------------

class Car {
private:
    string brand;
    string model;
    int year;
    RUB price_new;
    RUB price_now;
    int km_driven;
    bool have_car;
    
    RUB fuel_cost;
    RUB service_cost;
    RUB insurance_cost;
    RUB tax_cost;
    vector<string> repairs;
    
public:
    Car() {
        have_car = false;
        brand = "нет";
        model = "нет";
        year = 0;
        price_new = 0;
        price_now = 0;
        km_driven = 0;
        fuel_cost = 0;
        service_cost = 0;
        insurance_cost = 0;
        tax_cost = 0;
    }
    
    void buy(string b, string m, int y, RUB price) {
        brand = b;
        model = m;
        year = y;
        price_new = price;
        price_now = price;
        km_driven = random_int(10, 50) * 1000;
        have_car = true;
        
        fuel_cost = random_int(6000, 15000);
        service_cost = random_int(2000, 8000);
        insurance_cost = random_int(15000, 50000);
        tax_cost = random_int(5000, 25000);
        
        cout << "    куплена машина " << brand << " " << model << " " << year << " года за " << price << " руб" << endl;
    }
    
    void sell() {
        have_car = false;
    }
    
    void drive(int km) {
        if (!have_car) return;
        km_driven += km;
        if (km > 2000) {
            fuel_cost = fuel_cost * 1.1;
        }
        if (km_driven % 10000 < km && km_driven > 10000) {
            // ТО каждые 10000 км
            RUB to_cost = random_int(5000, 15000);
            service_cost += to_cost / 12;
        }
    }
    
    void repair(string name, RUB cost) {
        repairs.push_back(name + " (" + to_string(cost) + " руб)");
        service_cost += cost / 12;
    }
    
    void update_price() {
        if (!have_car) return;
        int age = current_year - year;
        float koef;
        if (age < 3) koef = 0.8;
        else if (age < 6) koef = 0.6;
        else if (age < 10) koef = 0.4;
        else if (age < 15) koef = 0.25;
        else koef = 0.15;
        
        price_now = (RUB)(price_new * koef);
    }
    
    RUB monthly_cost() {
        if (!have_car) return 0;
        return fuel_cost + service_cost + insurance_cost/12 + tax_cost/12;
    }
    
    bool is_have() { return have_car; }
    RUB get_price() { return price_now; }
    string get_name() { return brand + " " + model; }
    
    void print() {
        if (!have_car) {
            cout << "  машины нет" << endl;
            return;
        }
        cout << "  машина: " << brand << " " << model << ", " << year << " г.в." << endl;
        cout << "  пробег: " << km_driven << " км" << endl;
        cout << "  цена сейчас: " << price_now << " руб" << endl;
        cout << "  расходы в месяц:" << endl;
        cout << "    бензин: " << fuel_cost << " руб" << endl;
        cout << "    обслуживание: " << service_cost << " руб" << endl;
        cout << "    страховка: " << insurance_cost/12 << " руб" << endl;
        cout << "    налог: " << tax_cost/12 << " руб" << endl;
        cout << "    итого: " << monthly_cost() << " руб" << endl;
        
        if (repairs.size() > 0) {
            cout << "  ремонты:" << endl;
            for (int i = 0; i < repairs.size() && i < 3; i++) {
                cout << "    - " << repairs[i] << endl;
            }
        }
    }
};

// ------------------------------------------------------------------
// КЛАСС ДЛЯ КВАРТИРЫ
// ------------------------------------------------------------------

class Apartment {
private:
    bool have;
    string address;
    int square;
    int rooms;
    RUB price;
    RUB cadastral;
    
    RUB credit_left;
    RUB credit_pay;
    int credit_years;
    
public:
    Apartment() {
        have = false;
        credit_left = 0;
        credit_pay = 0;
        credit_years = 0;
    }
    
    void buy(string addr, int sq, int r, RUB pr, bool credit = false, RUB first = 0) {
        have = true;
        address = addr;
        square = sq;
        rooms = r;
        price = pr;
        cadastral = pr * 0.8;
        
        if (credit) {
            credit_left = pr - first;
            credit_years = 20;
            float month_percent = 12.0 / 12 / 100;
            credit_pay = (RUB)(credit_left * month_percent * 
                              pow(1 + month_percent, 240) / 
                              (pow(1 + month_percent, 240) - 1));
            cout << "    ипотека: " << credit_left << " руб, платеж " << credit_pay << " руб/мес" << endl;
        }
        
        cout << "    куплена квартира " << rooms << "-комнатная, " << square << " м², " << price << " руб" << endl;
    }
    
    void pay_credit() {
        if (credit_left <= 0) return;
        credit_left -= credit_pay;
        if (credit_left <= 0) {
            credit_left = 0;
            credit_pay = 0;
            cout << "    ипотека выплачена полностью!" << endl;
        }
    }
    
    RUB monthly_cost() {
        if (!have) return 0;
        RUB total = 0;
        total += square * 80; // коммуналка
        total += credit_pay;
        total += cadastral * 0.3 / 100 / 12; // налог
        return total;
    }
    
    RUB get_tax() {
        if (!have) return 0;
        return cadastral * 0.3 / 100;
    }
    
    bool is_have() { return have; }
    RUB get_price() { return price; }
    RUB get_credit_left() { return credit_left; }
    
    void print() {
        if (!have) {
            cout << "  квартиры нет, снимает жилье" << endl;
            return;
        }
        cout << "  квартира: " << rooms << "-комнатная, " << square << " м²" << endl;
        cout << "  адрес: " << address << endl;
        cout << "  цена: " << price << " руб" << endl;
        if (credit_left > 0) {
            cout << "  остаток ипотеки: " << credit_left << " руб" << endl;
            cout << "  платеж: " << credit_pay << " руб/мес" << endl;
        }
        cout << "  коммуналка: " << square * 80 << " руб/мес" << endl;
        cout << "  налог: " << cadastral * 0.3 / 100 << " руб/год" << endl;
    }
};

// ------------------------------------------------------------------
// ОСНОВНАЯ ФУНКЦИЯ СИМУЛЯЦИИ
// ------------------------------------------------------------------

void run_life_simulation(Alexandra& person, int years) {
    int target_year = current_year + years;
    
    cout << endl;
    cout << "=========================================" << endl;
    cout << "ЗАПУСК СИМУЛЯЦИИ ЖИЗНИ НА " << years << " ЛЕТ" << endl;
    cout << "=========================================" << endl;
    
    Car person_car;
    Apartment person_flat;
    
    while (current_year < target_year || (current_year == target_year && current_month <= 12)) {
        cout << endl;
        cout << "---------- " << current_year << " ГОД, МЕСЯЦ " << current_month << " ----------" << endl;
        
        // январь - индексация, день рождения, обновление цен
        if (current_month == 1) {
            person.index_salary();
            person.celebrate_birthday();
            person_car.update_price();
        }
        
        // каждый месяц
        if (!person.is_retired) {
            person.get_salary();
        } else {
            person.receive_money(person.pension, "пенсия");
        }
        
        // события с родственниками
        person.family_events();
        
        // события с друзьями
        person.friend_events();
        
        // случайные события
        person.random_event();
        
        // болезнь
        person.get_ill();
        
        // работа
        person.work_events();
        
        // семья и дети
        person.get_married();
        person.get_divorced();
        person.have_baby();
        person.children_grow();
        
        // образование
        person.study();
        
        // оплата счетов
        person.pay_bills(0);
        
        // кредиты
        person.handle_credits();
        
        // машина
        if (person_car.is_have()) {
            int km = random_int(500, 3000);
            person_car.drive(km);
            RUB car_cost = person_car.monthly_cost();
            person.spend_money(car_cost, "машина");
            
            if (random_int(1, 100) <= 8) {
                RUB repair_cost = random_int(5000, 60000);
                person_car.repair("ремонт", repair_cost);
                person.spend_money(repair_cost, "ремонт машины");
            }
            
        } else {
            if (person.savings > 600000 && person.age > 20 && random_int(1, 100) <= 2) {
                RUB car_price = random_int(400000, 2000000);
                if (person.savings >= car_price) {
                    person.savings -= car_price;
                    person_car.buy("Toyota", "Corolla", current_year-1, car_price);
                }
            }
        }
        
        // квартира
        if (person_flat.is_have()) {
            RUB flat_cost = person_flat.monthly_cost();
            person.spend_money(flat_cost, "квартира");
            person_flat.pay_credit();
            
        } else {
            if (person.savings > 1500000 && person.age > 25 && random_int(1, 100) <= 1) {
                RUB flat_price = random_int(3000000, 10000000);
                RUB first_pay = flat_price * 30 / 100;
                if (person.savings >= first_pay) {
                    person.savings -= first_pay;
                    person_flat.buy("ул. Ленина, д. 1", 45, 2, flat_price, true, first_pay);
                }
            }
        }
        
        // отпуск
        if (current_month >= 6 && current_month <= 8) {
            person.go_vacation();
        }
        
        // инвестиции
        if (current_month % 3 == 0) {
            person.invest_money();
            person.buy_gold();
            person.buy_currency();
        }
        
        // сбережения
        if (person.card > 50000) {
            RUB to_save = person.card * 0.2;
            person.save_up(to_save);
        }
        
        // инфляция расходов
        if (current_month % 12 == 0) {
            person.food_expense = inflation_monthly_rub(person.food_expense);
            person.utilities_expense = inflation_monthly_rub(person.utilities_expense);
            person.transport_expense = inflation_monthly_rub(person.transport_expense);
        }
        
        current_month++;
        if (current_month > 12) {
            current_month = 1;
            current_year++;
        }
    }
    
    cout << endl;
    cout << "=========================================" << endl;
    cout << "СИМУЛЯЦИЯ ЗАВЕРШЕНА" << endl;
    cout << "=========================================" << endl;
}

// ------------------------------------------------------------------
// ГЛАВНАЯ ФУНКЦИЯ
// ------------------------------------------------------------------

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    
    cout << "=========================================" << endl;
    cout << "СИМУЛЯТОР ЖИЗНИ" << endl;
    cout << "Зажарская Александра Витальевна" << endl;
    cout << "12.08.2005 г.р." << endl;
    cout << "=========================================" << endl;
    
    Alexandra sasha("Зажарская", "Александра", "Витальевна", 12, 8, 2005);
    
    sasha.show_status();
    
    run_life_simulation(sasha, 50);
    
    cout << endl;
    cout << "=========================================" << endl;
    cout << "ИТОГИ ЖИЗНИ" << endl;
    cout << "=========================================" << endl;
    
    sasha.show_status();
    sasha.show_history(30);
    sasha.show_vacations();
    sasha.show_credits();
    
    RUB total_assets = sasha.cash + sasha.card + sasha.savings + 
                       sasha.investments + sasha.gold + sasha.foreign_currency;
    
    cout << endl;
    cout << "--- ФИНАЛЬНЫЙ АНАЛИЗ ---" << endl;
    cout << "всего накоплено активов: " << total_assets << " руб" << endl;
    cout << "средний доход в месяц: " << sasha.total_earned / (50 * 12) << " руб" << endl;
    cout << "средний расход в месяц: " << sasha.total_spent / (50 * 12) << " руб" << endl;
    cout << "всего уплачено налогов: " << sasha.total_tax_paid << " руб" << endl;
    
    if (sasha.debt > 0) {
        cout << "остаток долга: " << sasha.debt << " руб" << endl;
    }
    
    if (total_assets > 20000000) {
        cout << "СТАТУС: очень богатый человек" << endl;
    } else if (total_assets > 10000000) {
        cout << "СТАТУС: миллионер" << endl;
    } else if (total_assets > 5000000) {
        cout << "СТАТУС: обеспеченный человек" << endl;
    } else if (total_assets > 1000000) {
        cout << "СТАТУС: средний класс" << endl;
    } else if (total_assets > 500000) {
        cout << "СТАТУС: есть сбережения" << endl;
    } else if (total_assets > 100000) {
        cout << "СТАТУС: небольшие накопления" << endl;
    } else {
        cout << "СТАТУС: денег практически нет" << endl;
    }
    
    if (sasha.sick_days_total < 500) {
        cout << "ЗДОРОВЬЕ: отличное, болела редко" << endl;
    } else if (sasha.sick_days_total < 1500) {
        cout << "ЗДОРОВЬЕ: среднее" << endl;
    } else {
        cout << "ЗДОРОВЬЕ: слабое, много болела" << endl;
    }
    
    if (sasha.vacation_days_total > 200) {
        cout << "ПУТЕШЕСТВИЯ: много путешествовала" << endl;
    } else if (sasha.vacation_days_total > 100) {
        cout << "ПУТЕШЕСТВИЯ: несколько раз была в отпуске" << endl;
    } else {
        cout << "ПУТЕШЕСТВИЯ: мало отдыхала" << endl;
    }
    
    if (sasha.promotions_count > 5) {
        cout << "КАРЬЕРА: успешная, много повышений" << endl;
    } else if (sasha.promotions_count > 2) {
        cout << "КАРЬЕРА: были повышения" << endl;
    } else {
        cout << "КАРЬЕРА: без особого роста" << endl;
    }
    
    if (sasha.fired_count == 0) {
        cout << "СТАБИЛЬНОСТЬ: ни разу не увольняли" << endl;
    } else if (sasha.fired_count == 1) {
        cout << "СТАБИЛЬНОСТЬ: один раз увольняли" << endl;
    } else {
        cout << "СТАБИЛЬНОСТЬ: часто меняла работу" << endl;
    }
    
    cout << "=========================================" << endl;
    
    return 0;
}
