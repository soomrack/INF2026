#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

using RUB = long long int;
using Percent = double;

const double INFLATION = 8.5;
const double MARKET = 12.0;

int salary = 100001;
int capital = 0;
int food = 15000;

enum Currency {
    RUBLES,
    DOLLARS,
    EUROS,
    BITCOIN
};

struct Money {
    RUB amount;
    Currency currency;
    
    void convert_to(Currency new_currency) {
        if (currency == RUBLES && new_currency == DOLLARS) {
            amount /= 90;
        } else if (currency == DOLLARS && new_currency == RUBLES) {
            amount *= 90;
        }
        currency = new_currency;
    }
    
    void print() {
        const char* names[] = {"RUB", "USD", "EUR", "BTC"};
        printf("%lld %s", amount, names[currency]);
    }
};

struct Car {
    RUB value;
    RUB gas;
    RUB service;
    RUB insurance;
    int year;
    char brand[50];
    char model[50];
    double mileage;
    
    void init(const char* b, const char* m, int y, RUB v) {
        strcpy(brand, b);
        strcpy(model, m);
        year = y;
        value = v;
        gas = 12000;
        service = 5000;
        insurance = 8000;
        mileage = 0;
    }
    
    void drive(int km) {
        mileage += km;
        gas += (km / 100) * 800;
    }
    
    RUB monthly() {
        return gas + service + insurance;
    }
    
    void print_info() {
        printf("%s %s %d\n", brand, model, year);
        printf("Цена: "); 
        Money{value, RUBLES}.print();
        printf("\n");
        printf("Пробег: %.1f км\n", mileage);
        printf("Расходы: %lld RUB\n", monthly());
    }
};

struct RealEstate {
    RUB value;
    RUB rent;
    RUB tax;
    char address[100];
    double area;
    
    void init(const char* addr, double a, RUB v, RUB r) {
        strcpy(address, addr);
        area = a;
        value = v;
        rent = r;
        tax = value * 0.001;
    }
    
    RUB income() {
        return rent - tax;
    }
    
    void print_info() {
        printf("%s (%.1f м²)\n", address, area);
        printf("Цена: %lld RUB\n", value);
        printf("Доход: %lld RUB/мес\n", income());
    }
};

struct Portfolio {
    RUB stocks;
    RUB bonds;
    RUB crypto;
    RUB cash;
    
    void init() {
        stocks = 0;
        bonds = 0;
        crypto = 0;
        cash = 0;
    }
    
    RUB total() {
        return stocks + bonds + crypto + cash;
    }
    
    void add_stocks(RUB amount) {
        stocks += amount;
    }
    
    void add_bonds(RUB amount) {
        bonds += amount;
    }
    
    void add_crypto(RUB amount) {
        crypto += amount;
    }
    
    double monthly_return() {
        return stocks * (MARKET / 12.0 / 100.0) +
               bonds * (8.0 / 12.0 / 100.0) +
               crypto * (20.0 / 12.0 / 100.0) +
               cash * (10.0 / 12.0 / 100.0);
    }
    
    void print_info() {
        printf("Портфель:\n");
        printf("  Акции: %lld RUB\n", stocks);
        printf("  Облигации: %lld RUB\n", bonds);
        printf("  Крипта: %lld RUB\n", crypto);
        printf("  Кэш: %lld RUB\n", cash);
        printf("  Всего: %lld RUB\n", total());
    }
};

struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    RUB fun;
    RUB study;
    RUB health;
    RUB other;
    
    Car car;
    RealEstate* flats;
    int flat_count;
    Portfolio portfolio;
    
    char name[50];
    int age;
    RUB monthly_total;
    
    void init(const char* n, int a, RUB s) {
        strcpy(name, n);
        age = a;
        salary = s;
        capital = 0;
        food = 15000;
        fun = 10000;
        study = 5000;
        health = 3000;
        other = 7000;
        
        car.init("Toyota", "Camry", 2022, 2400000);
        
        flats = nullptr;
        flat_count = 0;
        portfolio.init();
        
        update_total();
    }
    
    void update_total() {
        monthly_total = food + fun + study + health + other + car.monthly();
    }
    
    void buy_flat(const char* addr, double area, RUB value, RUB rent) {
        RealEstate* new_flats = new RealEstate[flat_count + 1];
        
        for (int i = 0; i < flat_count; i++) {
            new_flats[i] = flats[i];
        }
        
        new_flats[flat_count].init(addr, area, value, rent);
        
        delete[] flats;
        flats = new_flats;
        flat_count++;
        
        capital -= value;
        printf("%s купил квартиру за ", name);
        Money{value, RUBLES}.print();
        printf("\n");
    }
    
    void get_salary(int year, int month) {
        if (month == 1) {
            salary *= (1.0 + INFLATION / 100.0);
        }
        
        if (month == 12) {
            salary *= 1.3;
        } else if (month == 6) {
            salary *= 1.1;
        }
        
        capital += salary;
        printf("%s получил: ", name);
        Money{salary, RUBLES}.print();
        printf("\n");
    }
    
    void pay_bills() {
        capital -= monthly_total;
        printf("%s заплатил: ", name);
        Money{monthly_total, RUBLES}.print();
        printf("\n");
    }
    
    void invest() {
        if (capital > 100000) {
            RUB to_invest = capital * 0.2;
            
            portfolio.add_stocks(to_invest * 0.4);
            portfolio.add_bonds(to_invest * 0.3);
            portfolio.add_crypto(to_invest * 0.1);
            
            capital -= to_invest;
            
            printf("%s инвестировал: ", name);
            Money{to_invest, RUBLES}.print();
            printf("\n");
        }
    }
    
    void get_returns() {
        double income = portfolio.monthly_return();
        capital += income;
        
        if (income > 0) {
            printf("Доход от инвестиций: %.0f RUB\n", income);
        }
    }
    
    void get_rent() {
        for (int i = 0; i < flat_count; i++) {
            capital += flats[i].income();
            printf("Аренда: %lld RUB\n", flats[i].income());
        }
    }
    
    void print_all() {
        printf("\n=== %s ===\n", name);
        printf("Возраст: %d\n", age);
        printf("Зарплата: %lld RUB\n", salary);
        printf("Капитал: %lld RUB\n", capital);
        printf("Расходы: %lld RUB\n", monthly_total);
        printf("Запас: %.1f мес\n", (double)capital / monthly_total);
        
        printf("\nИнвестиции:\n");
        portfolio.print_info();
        
        printf("\nНедвижимость:\n");
        for (int i = 0; i < flat_count; i++) {
            flats[i].print_info();
        }
        
        printf("\nМашина:\n");
        car.print_info();
    }
    
    ~Person() {
        delete[] flats;
    }
};

Person alice;

void alice_init() {
    alice.init("Алиса", 30, 180000);
}

float bank_rate(RUB sum, int month, int year) {
    if (month == 12 && year % 2 == 0) {
        return 14.0;
    }
    
    if (sum > 10000 && sum < 3000000) {
        return 11.5;
    }

    if (sum >= 3000000 && sum < 10000000) {
        return 12.5;
    }
    
    if (sum >= 10000000) {
        return 13.5;
    }

    return 0.1;
}

void apply_inflation(Person& p, int year) {
    if (year % 2 == 0) {
        p.food *= (1.0 + INFLATION / 100.0);
        p.fun *= (1.0 + INFLATION / 100.0);
        p.car.gas *= (1.0 + INFLATION / 100.0);
        p.update_total();
        
        printf("Инфляция: расходы выросли\n");
    }
}

void market_sim(Person& p) {
    srand(time(NULL));
    double change = (rand() % 20 - 10) / 100.0;
    
    p.portfolio.stocks *= (1.0 + change);
    p.portfolio.bonds *= (1.0 + change * 0.3);
    p.portfolio.crypto *= (1.0 + change * 3.0);
    
    if (change > 0.05) {
        printf("Рынок вырос на %.1f%%\n", change * 100);
    } else if (change < -0.05) {
        printf("Рынок упал на %.1f%%\n", change * 100);
    }
}

void simulation(int years) {
    int start = 2026;
    int month = 2;
    int year = start;
    int target = start + years;
    
    printf("\nСТАРТ %d - %d\n\n", start, target);
    
    while (year < target || (year == target && month <= 2)) {
        printf("\n%d год, месяц %d\n", year, month);
        
        alice.pay_bills();
        alice.car.drive(1500);
        
        if (month % 3 == 0) {
            alice.get_rent();
            market_sim(alice);
        }
        
        if (month == 6 || month == 12) {
            alice.invest();
        }
        
        float rate = bank_rate(alice.capital, month, year);
        alice.capital += alice.capital * (rate / 12.0 / 100.0);
        
        alice.get_returns();
        alice.get_salary(year, month);
        
        if (month == 1) {
            apply_inflation(alice, year);
        }
        
        month++;
        if (month == 13) {
            month = 1;
            year++;
            
            printf("\nГОД %d\n", year-1);
            alice.print_all();
            printf("\n");
        }
    }
}

void global_stats() {
    printf("\nГЛОБАЛЬНО\n");
    printf("Salary = %d\n", salary);
    printf("Capital = %d\n", capital);
    printf("Food = %d\n", food);
}

int main() {
    printf("ФИНСИМ\n");
    printf("======\n");
    
    alice_init();
    alice.print_all();
    
    simulation(5);
    
    printf("\nИТОГ\n");
    alice.print_all();
    
    printf("\nАНАЛИЗ\n");
    printf("Доход: %lld RUB\n", alice.capital + alice.portfolio.total());
    printf("Активы: %lld RUB\n", alice.car.value + alice.portfolio.total());
    
    double passive = alice.portfolio.monthly_return();
    if (alice.flat_count > 0) {
        passive += alice.flats[0].income();
    }
    
    printf("Пассив: %.0f RUB/мес\n", passive);
    
    if (passive >= alice.monthly_total) {
        printf("СВОБОДА!\n");
    } else {
        double need = alice.monthly_total - passive;
        double save = alice.salary * 0.3;
        double years = (need * 12) / save;
        printf("До свободы: %.1f лет\n", years);
    }
    
    global_stats();
    
    return 0;
}


// Каждый месяц: расходы, пробег, проценты, зарплата
// Каждый квартал: аренда и рынок
// Полгода: инвестиции
// Год: инфляция и итоги

// В конце считаем пассивный доход
// Если пассив >= расходов - свобода
// Иначе сколько лет копить
