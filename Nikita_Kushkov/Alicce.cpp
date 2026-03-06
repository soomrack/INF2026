#include <stdio.h>
#include <random>
#include <time.h>

// typedef int RUB;  // C
using RUB = long long int;  // C++

struct CounterStrike {
    RUB Cases;
    RUB Battle_pass;
};



struct MedicalInsurance {
    RUB monthly;          
    RUB dentist;           
    RUB emergency;         
};



struct Entertainment {
    RUB cinema;            
    RUB restaurant;        
    RUB subscriptions;     
    RUB hobbies;           
};



struct Transport {
    RUB public_transport;  
    RUB taxi;              
    RUB car_insurance;     
    RUB car_maintenance;   
};



struct Education {
    RUB courses;           
    RUB books;             
    RUB child_circles;     
};



struct Health {
    RUB pharmacy;          // Лекарства
    RUB vitamins;          // Витамины
    RUB sports_equipment;  // Спортивный инвентарь
};



struct Gifts {
    RUB birthday;          // Дни рождения
    RUB new_year;          // Новый год
    RUB other;             // Прочие подарки
};



struct AdditionalIncome {
    RUB freelance;         // Фриланс/подработка
    RUB dividends;         // Дивиденды от инвестиций
    RUB cashback;          // Кэшбэк с покупок
    RUB birthday_gifts;    // Подарки на день рождения
    RUB bonus;             // Премии на работе
};



struct Investments {
    RUB stocks;            // Акции
    RUB crypto;            // Криптовалюта
    RUB deposit;
    RUB steam_marketplace;           
};



struct Loan {
    RUB amount;           // Сумма кредита
    RUB monthly_payment;  // Ежемесячный платеж
    RUB interest_rate;    // Процентная ставка
    int months_left;      // Осталось месяцев
    bool has_loan;        // Есть ли активный кредит
};



struct CapitalController {
    RUB min_threshold;    // Минимальный порог капитала
    RUB loan_amount;      // Сумма кредита при достижении порога
    Loan active_loan;     // Активный кредит
    int loan_count;       // Счетчик взятых кредитов
    RUB total_loan_amount; // Общая сумма взятых кредитов
    RUB total_interest_paid; // Общая сумма выплаченных процентов
    RUB total_penalties;   // Общая сумма штрафов
};



struct Friends {
    RUB rest;
};



struct Car {
    RUB value;
    RUB gas;
};



struct Cat {
    RUB Proplan;
    RUB Vet;
};



struct tax_servise {
    RUB salary_tax;
};



struct House {
    RUB fixed_costs;
    RUB repair;
};



struct Child {
    RUB food;
    RUB clothes;
    RUB school;
    RUB medicine;
};



struct Husband {
    RUB food;
    RUB alimony_payments;
};



struct Person {
    RUB salary;
    RUB capital;
    RUB food;
    RUB gambling;
    RUB savings;
    RUB salary_tax;
    RUB internet;
    RUB clothes;
    RUB gym;
    Cat cat;
    Car car;
    RUB fixed_costs;
    RUB rest;
    Child child;
    Husband husband;
    House house;
    MedicalInsurance medical;
    Entertainment entertainment;
    Transport transport;
    Education education;
    Health health;
    Gifts gifts;
    AdditionalIncome additional_income;
    Investments investments;
    
    CapitalController capital_control;
    CounterStrike cs;
};



struct Person alice;



void alice_init()
{
    alice.capital = 500'000;
    alice.salary = 250'000;
    alice.food = 15'000;
    alice.gambling = 5'000;
    alice.savings = 0;
    alice.salary_tax = 68'400;
    alice.car.value = 2'400'000;
    alice.car.gas = 12'000;
    alice.internet = 5'000;
    alice.clothes = 20'000;
    alice.gym = 5'000;
    alice.house.repair = 100'000;

    alice.cs.Battle_pass = 1'500;
    alice.cs.Cases = 500;

    alice.cat.Proplan = 60;
    alice.cat.Vet = 10'000;
    alice.fixed_costs = 7'000;
    alice.rest = 10'000;
    alice.child.clothes = 50'000;
    alice.child.food = 30'000;
    alice.child.medicine = 20'000;
    alice.child.school = 25'000;

    alice.husband.alimony_payments = 0;
    alice.husband.food = 15'000;

    alice.medical.monthly = 3'000;        
    alice.medical.dentist = 15'000;        
    alice.medical.emergency = 30'000;      

    alice.entertainment.cinema = 2'000;  
    alice.entertainment.subscriptions = 2'500; 
    alice.entertainment.hobbies = 3'000;    
    
    alice.transport.public_transport = 2'000; 
    alice.transport.taxi = 3'000;           
    alice.transport.car_insurance = 60'000;  
    alice.transport.car_maintenance = 40'000; 
    
    alice.education.courses = 10'000;       
    alice.education.books = 2'000;           
    alice.education.child_circles = 15'000;  
    
    alice.health.pharmacy = 2'000;           // Лекарства
    alice.health.vitamins = 1'500;            // Витамины
    alice.health.sports_equipment = 3'000;    // Спортинвентарь
    
    alice.gifts.birthday = 10'000;            // Подарки на ДР
    alice.gifts.new_year = 15'000;            // Новый год
    alice.gifts.other = 5'000;                 // Прочие подарки
    
    
    alice.additional_income.freelance = 15'000;    // Фриланс
    alice.additional_income.dividends = 5'000;      // Дивиденды
    alice.additional_income.cashback = 2'000;       // Кэшбэк
    alice.additional_income.birthday_gifts = 20'000; // Подарки на ДР
    alice.additional_income.bonus = 100'000;         // Премия (раз в год)
    
    alice.investments.stocks = 0;             // Инвестиции в акции
    alice.investments.crypto = 0;              // Криптовалюта
    alice.investments.deposit = alice.capital;
    alice.investments.steam_marketplace = 0;

    alice.capital_control.min_threshold = 10'000;     // Критический порог - 10,000 руб
    alice.capital_control.loan_amount = 100'000;      // Кредит 100,000 руб
    alice.capital_control.loan_count = 0;
    alice.capital_control.total_loan_amount = 0;
    alice.capital_control.total_interest_paid = 0;
    alice.capital_control.total_penalties = 0;
    alice.capital_control.active_loan.has_loan = false;
    alice.capital_control.active_loan.amount = 0;
    alice.capital_control.active_loan.monthly_payment = 0;
    alice.capital_control.active_loan.interest_rate = 0;
    alice.capital_control.active_loan.months_left = 0;
}


// Функция для расчета степени (замена pow)
double my_pow(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}



void check_and_take_loan(const int year, const int month)
{
    // Если уже есть активный кредит, не берем новый
    if (alice.capital_control.active_loan.has_loan) {
        return;
    }
    
    // Проверяем, не упал ли капитал ниже критического порога
    if (alice.capital <= alice.capital_control.min_threshold) {
        // Сумма кредита = минимальная сумма для покрытия долга + запас
        RUB needed_amount = (alice.capital_control.min_threshold * 2) - alice.capital;
        if (needed_amount < 0) needed_amount = alice.capital_control.loan_amount;
        
        // Ограничиваем максимальный кредит
        if (needed_amount > 500'000) {
            needed_amount = 500'000;
        }
        
        // Параметры кредита
        alice.capital_control.active_loan.amount = needed_amount;
        alice.capital_control.active_loan.interest_rate = 15.0; // 15% годовых
        alice.capital_control.active_loan.months_left = 12; // На 12 месяцев
        alice.capital_control.active_loan.has_loan = true;
        
        // Расчет ежемесячного платежа (аннуитетный платеж)
        double monthly_rate = alice.capital_control.active_loan.interest_rate / 12.0 / 100.0;
        double annuity_factor = (monthly_rate * my_pow(1 + monthly_rate, 12)) / (my_pow(1 + monthly_rate, 12) - 1);
        alice.capital_control.active_loan.monthly_payment = alice.capital_control.active_loan.amount * annuity_factor;
        
        // Добавляем кредит в капитал
        alice.capital += alice.capital_control.active_loan.amount;
        
        // Обновляем статистику
        alice.capital_control.loan_count++;
        alice.capital_control.total_loan_amount += alice.capital_control.active_loan.amount;
        
        printf("\n*** ВНИМАНИЕ! КРИТИЧЕСКИЙ КАПИТАЛ! ***\n");
        printf("Капитал упал до %lld руб. (порог %lld руб.)\n", alice.capital - alice.capital_control.active_loan.amount, alice.capital_control.min_threshold);
        printf("Алиса берет кредит: %lld руб. под %.1f%% на %d месяцев\n", alice.capital_control.active_loan.amount, alice.capital_control.active_loan.interest_rate, alice.capital_control.active_loan.months_left);
        printf("Ежемесячный платеж: %lld руб.\n", alice.capital_control.active_loan.monthly_payment);
        printf("Капитал после кредита: %lld руб.\n", alice.capital);
        printf("Сбережения: %lld руб.\n", alice.savings);
        printf("***************************************\n\n");
    }
}



void process_loan_payment(const int year, const int month)
{
    if (alice.capital_control.active_loan.has_loan) {
        RUB payment = alice.capital_control.active_loan.monthly_payment;
        
        printf("\n--- Обработка кредитного платежа (месяц %d) ---\n", month);
        printf("  Требуется платеж: %lld руб.\n", payment);
        printf("  Текущий капитал: %lld руб.\n", alice.capital);
        printf("  Текущие сбережения: %lld руб.\n", alice.savings);
        
        RUB remaining_payment = payment;
        RUB paid_from_capital = 0;
        RUB paid_from_savings = 0;
        
        // Сначала платим из капитала
        if (alice.capital > 0) {
            paid_from_capital = (alice.capital >= remaining_payment) ? remaining_payment : alice.capital;
            alice.capital -= paid_from_capital;
            remaining_payment -= paid_from_capital;
        }
        
        // Если не хватило капитала, платим из сбережений
        if (remaining_payment > 0 && alice.savings > 0) {
            paid_from_savings = (alice.savings >= remaining_payment) ? remaining_payment : alice.savings;
            alice.savings -= paid_from_savings;
            remaining_payment -= paid_from_savings;
        }
        
        printf("  Оплачено: %lld руб. (капитал: %lld, сбережения: %lld)\n", payment - remaining_payment, paid_from_capital, paid_from_savings);
        
        // Если осталась неоплаченная сумма
        if (remaining_payment > 0) {
            printf("\n*** ПРОСРОЧКА КРЕДИТА! ***\n");
            printf("Неоплачено: %lld руб.\n", remaining_payment);
            
            // Штраф 10% от неоплаченной суммы
            RUB penalty = remaining_payment * 0.1;
            alice.capital_control.total_penalties += penalty;
            
            printf("Штраф 10%%: %lld руб.\n", penalty);
            
            // Увеличиваем оставшийся долг
            alice.capital_control.active_loan.amount += remaining_payment + penalty;
            
            // Пересчитываем ежемесячный платеж (оставшиеся месяцы)
            if (alice.capital_control.active_loan.months_left > 0) {
                double monthly_rate = alice.capital_control.active_loan.interest_rate / 12.0 / 100.0;
                double annuity_factor = (monthly_rate * my_pow(1 + monthly_rate, alice.capital_control.active_loan.months_left)) / (my_pow(1 + monthly_rate, alice.capital_control.active_loan.months_left) - 1);
                alice.capital_control.active_loan.monthly_payment = alice.capital_control.active_loan.amount * annuity_factor;
            }
            
            printf("Новый долг: %lld руб.\n", alice.capital_control.active_loan.amount);
            printf("Новый ежемесячный платеж: %lld руб.\n", alice.capital_control.active_loan.monthly_payment);
            printf("***************************\n\n");
        } else {
            // Успешный платеж - уменьшаем основной долг
            RUB interest_part = payment * 0.15; // Приблизительная часть процентов
            RUB principal_part = payment - interest_part;
            
            alice.capital_control.active_loan.amount -= principal_part;
            alice.capital_control.total_interest_paid += interest_part;
            
            printf("  ✅ Платеж успешно обработан\n");
            printf("  Основной долг уменьшен на: %lld руб.\n", principal_part);
        }
        
        alice.capital_control.active_loan.months_left--;
        printf("  📊 После платежа: капитал = %lld руб., сбережения = %lld руб.\n", alice.capital, alice.savings);
        printf("  Остаток долга: %lld руб., осталось месяцев: %d\n", alice.capital_control.active_loan.amount, alice.capital_control.active_loan.months_left);
        
        // Если кредит выплачен
        if (alice.capital_control.active_loan.months_left <= 0 || 
            alice.capital_control.active_loan.amount <= 0) {
            printf("\n*** КРЕДИТ ПОЛНОСТЬЮ ВЫПЛАЧЕН! ***\n");
            printf("Всего выплачено процентов: %lld руб.\n", alice.capital_control.total_interest_paid);
            printf("Всего штрафов: %lld руб.\n", alice.capital_control.total_penalties);
            alice.capital_control.active_loan.has_loan = false;
            alice.capital_control.active_loan.amount = 0;
            alice.capital_control.active_loan.monthly_payment = 0;
            printf("***********************************\n\n");
        }
    }
}



float sberbank_interest(RUB sum)
{
    if (sum > 10'000 && sum < 3'000'000) {
        return 11.5;
    }
    if (sum >= 3'000'000) {
        return 12.5;  
    }
    return 0.1;
}



void alice_medical_expenses(const int month, const int year)
{
    // Ежемесячные расходы на медицину
    alice.capital -= alice.medical.monthly;
    printf("Месяц %d: - Медицинская страховка: %lld руб. (капитал: %lld руб.)\n", month, alice.medical.monthly, alice.capital);
    
    // Стоматолог раз в полгода
    if (month == 3 || month == 9) {
        alice.capital -= alice.medical.dentist;
        printf("Месяц %d: - СТОМАТОЛОГ: %lld руб. (капитал: %lld руб.)\n", month, alice.medical.dentist, alice.capital);
    }
    
    // Экстренные случаи (редко, 5% шанс)
    if (rand() % 100 < 5) {
        alice.capital -= alice.medical.emergency;
        printf("Месяц %d: - ЭКСТРЕННАЯ МЕДИЦИНА: %lld руб. (капитал: %lld руб.)\n", month, alice.medical.emergency, alice.capital);
    }
    
    check_and_take_loan(year, month);
}



void alice_CounterStrike(const int month, const int year)
{
    alice.capital -= alice.cs.Battle_pass;
    printf("Месяц %d: - Боевой пропуск: %lld руб. (капитал: %lld руб.)\n", month, alice.cs.Battle_pass, alice.capital);

    alice.capital -= alice.cs.Cases;
    printf("Месяц %d: - Кейсы: %lld руб. (капитал: %lld руб.)\n", month, alice.cs.Cases, alice.capital);

    check_and_take_loan(year, month);
}



void alice_entertainment(const int month, const int year)
{
    // Регулярные развлечения
    alice.capital -= alice.entertainment.cinema;
    alice.capital -= alice.entertainment.subscriptions;
    
    printf("Месяц %d: - Кино: %lld руб., Подписки: %lld руб. (капитал: %lld руб.)\n", month, alice.entertainment.cinema, alice.entertainment.subscriptions, alice.capital);
    
    // Рестораны (70% шанс)
    if (rand() % 100 < 70) {
        alice.capital -= alice.entertainment.restaurant;
        printf("Месяц %d: - Ресторан: %lld руб. (капитал: %lld руб.)\n", month, alice.entertainment.restaurant, alice.capital);
    }
    
    // Хобби (50% шанс)
    if (rand() % 100 < 50) {
        alice.capital -= alice.entertainment.hobbies;
        printf("Месяц %d: - Хобби: %lld руб. (капитал: %lld руб.)\n", month, alice.entertainment.hobbies, alice.capital);
    }
    
    check_and_take_loan(year, month);
}



void alice_transport(const int month, const int year)
{
    // Ежемесячные расходы на транспорт
    alice.capital -= alice.transport.public_transport;
    printf("Месяц %d: - Общественный транспорт: %lld руб. (капитал: %lld руб.)\n", month, alice.transport.public_transport, alice.capital);
    
    // Такси (40% шанс)
    if (rand() % 100 < 40) {
        alice.capital -= alice.transport.taxi;
        printf("Месяц %d: - Такси: %lld руб. (капитал: %lld руб.)\n", month, alice.transport.taxi, alice.capital);
    }
    
    // Годовые расходы на машину
    if (month == 6) { // Страховка в июне
        alice.capital -= alice.transport.car_insurance;
        printf("Месяц %d: - Страховка машины (ГОДОВАЯ): %lld руб. (капитал: %lld руб.)\n", month, alice.transport.car_insurance, alice.capital);
    }
    if (month == 9) { // ТО в сентябре
        alice.capital -= alice.transport.car_maintenance;
        printf("Месяц %d: - ТО машины: %lld руб. (капитал: %lld руб.)\n", month, alice.transport.car_maintenance, alice.capital);
    }
    
    check_and_take_loan(year, month);
}



void alice_education(const int month, const int year)
{
    // Ежемесячные расходы на образование
    alice.capital -= alice.education.books;
    printf("Месяц %d: - Книги: %lld руб. (капитал: %lld руб.)\n", month, alice.education.books, alice.capital);
    
    // Кружки для ребенка
    alice.capital -= alice.education.child_circles;
    printf("Месяц %d: - Кружки ребенка: %lld руб. (капитал: %lld руб.)\n", month, alice.education.child_circles, alice.capital);
    
    // Курсы (раз в 4 месяца)
    if (month % 4 == 0) {
        alice.capital -= alice.education.courses;
        printf("Месяц %d: - Курсы повышения квалификации: %lld руб. (капитал: %lld руб.)\n", month, alice.education.courses, alice.capital);
    }
    
    check_and_take_loan(year, month);
}



void alice_health(const int month, const int year)
{
    // Расходы на здоровье
    alice.capital -= alice.health.pharmacy;
    alice.capital -= alice.health.vitamins;
    
    printf("Месяц %d: - Лекарства: %lld руб., Витамины: %lld руб. (капитал: %lld руб.)\n", month, alice.health.pharmacy, alice.health.vitamins, alice.capital);
    
    // Спортивный инвентарь (раз в 3 месяца)
    if (month % 3 == 0) {
        alice.capital -= alice.health.sports_equipment;
        printf("Месяц %d: - Спортивный инвентарь: %lld руб. (капитал: %lld руб.)\n", month, alice.health.sports_equipment, alice.capital);
    }
    
    check_and_take_loan(year, month);
}



void alice_gifts(const int month, const int year)
{
    // Подарки на дни рождения (случайные месяцы)
    if (month == 2 || month == 5 || month == 8 || month == 11) {
        alice.capital -= alice.gifts.birthday;
        printf("Месяц %d: - Подарки на дни рождения: %lld руб. (капитал: %lld руб.)\n", month, alice.gifts.birthday, alice.capital);
    }
    
    // Новогодние подарки
    if (month == 12) {
        alice.capital -= alice.gifts.new_year;
        printf("Месяц %d: - НОВОГОДНИЕ ПОДАРКИ: %lld руб. (капитал: %lld руб.)\n", month, alice.gifts.new_year, alice.capital);
    }
    
    // Прочие подарки (30% шанс)
    if (rand() % 100 < 30) {
        alice.capital -= alice.gifts.other;
        printf("Месяц %d: - Прочие подарки: %lld руб. (капитал: %lld руб.)\n", month, alice.gifts.other, alice.capital);
    }
    
    check_and_take_loan(year, month);
}



void alice_additional_income(const int month, const int year)
{
    // Фриланс (70% шанс)
    if (rand() % 100 < 70) {
        RUB freelance = alice.additional_income.freelance + (rand() % 10000);
        alice.capital += freelance;
        printf("Месяц %d: + Фриланс: %lld руб. (капитал: %lld руб.)\n", month, freelance, alice.capital);
    }
    
    // Дивиденды (раз в квартал)
    if (month == 3 || month == 6 || month == 9 || month == 12) {
        RUB dividends = alice.additional_income.dividends * (1 + (rand() % 50) / 100.0);
        alice.capital += dividends;
        printf("Месяц %d: + Дивиденды: %lld руб. (капитал: %lld руб.)\n", month, dividends, alice.capital);
    }
    
    // Кэшбэк (всегда)
    RUB cashback = alice.additional_income.cashback + (rand() % 1000);
    alice.capital += cashback;
    printf("Месяц %d: + Кэшбэк: %lld руб. (капитал: %lld руб.)\n", month, cashback, alice.capital);
    
    // Подарки на день рождения Алисы (допустим, в апреле)
    if (month == 4) {
        alice.capital += alice.additional_income.birthday_gifts;
        printf("Месяц %d: + Подарки на ДЕНЬ РОЖДЕНИЯ: %lld руб. (капитал: %lld руб.)\n", month, alice.additional_income.birthday_gifts, alice.capital);
    }
    
    // Годовая премия
    if (month == 12) {
        alice.capital += alice.additional_income.bonus;
        printf("Месяц %d: + ГОДОВАЯ ПРЕМИЯ: %lld руб. (капитал: %lld руб.)\n", month, alice.additional_income.bonus, alice.capital);
    }
    
    check_and_take_loan(year, month);
}



void alice_investments(const int month, const int year)
{
    // Инвестиции в акции (если есть свободные средства)
    if (alice.capital > 500'000 && rand() % 100 < 20) {
        RUB investment = (alice.capital - 500'000) * 0.3;
        if (investment > 10000) {
            alice.investments.stocks += investment;
            alice.capital -= investment;
            printf("Месяц %d: - Инвестиции в АКЦИИ: %lld руб. (капитал: %lld руб.)\n", month, investment, alice.capital);
        }
    }
    

    // Рост/падение акций
    if (alice.investments.stocks > 0) {
        int market_change = (rand() % 21) - 10; // -10% до +10%
        RUB change = alice.investments.stocks * market_change / 100;
        alice.investments.stocks += change;
        printf("Месяц %d: 📈 Изменение стоимости акций: %+lld руб. (всего: %lld руб.)\n", month, change, alice.investments.stocks);
    }
    

    // Криптовалюта (более волатильно)
    if (alice.capital > 300'000 && rand() % 100 < 10) {
        RUB crypto_invest = (rand() % 50000) + 10000;
        alice.investments.crypto += crypto_invest;
        alice.capital -= crypto_invest;
        printf("Месяц %d: - Инвестиции в КРИПТОВАЛЮТУ: %lld руб. (капитал: %lld руб.)\n", month, crypto_invest, alice.capital);
    }
    

    // Волатильность крипты
    if (alice.investments.crypto > 0) {
        int crypto_change = (rand() % 41) - 20; // -20% до +20%
        RUB change = alice.investments.crypto * crypto_change / 100;
        alice.investments.crypto += change;
        printf("Месяц %d: 📊 Изменение стоимости криптовалюты: %+lld руб. (всего: %lld руб.)\n", month, change, alice.investments.crypto);

    }


    // Торговая площадка Steam
    if(alice.capital > 200'000 && rand() % 100 < 25) {
        RUB Steam_marketplace = (alice.capital - 500'000) * 0.3;
        if (Steam_marketplace > 15000) {
            alice.investments.steam_marketplace += Steam_marketplace;
            alice.capital -= Steam_marketplace;
            printf("Месяц %d: - Инвестиции в Стим: %lld руб. (капитал: %lld руб.)\n", month, Steam_marketplace, alice.capital);
        }
    }


    // Рост/падение стоимости предметов 
    if (alice.investments.steam_marketplace > 0) {
        int items_change = (rand() % 21) - 10;
        RUB change = alice.investments.steam_marketplace * items_change / 100;
        alice.investments.steam_marketplace += change;
        printf("Месяц %d: 📊 Изменение стоимости предмета: %+lld руб. (всего: %lld руб.)\n", month, change, alice.investments.steam_marketplace);
    }
}



void alice_husband_alimony(const int month, const int year) // Алименты
{
    alice.capital += alice.husband.alimony_payments;
    printf("Месяц %d.%d: + Алименты: %lld руб. (капитал %lld руб.)\n", month, year, alice.husband.alimony_payments, alice.capital);

    check_and_take_loan(year, month);
}



void alice_house_repair(const int year) // Ремонт дома
{
    alice.capital -= alice.house.repair;
    printf("Год %d: - Ремонт дома: %lld руб. (капитал %lld руб.)\n", year, alice.house.repair, alice.capital);

    check_and_take_loan(year, 1);
}



void alice_salary(const int year, const int month) // Зарплата
{
    RUB old_salary = alice.salary;
    if (month == 3 && year == 2026) {
        alice.salary *= 1.2; // Повышение на 20%
        printf("Повышение зарплаты! Было: %lld, стало: %lld\n", old_salary, alice.salary);
    }
    
    // Ежегодная индексация
    if (month == 1 && year > 2026) {
        alice.salary *= 1.05; // Индексация 5% в год
        printf("Индексация зарплаты! Новая зарплата: %lld руб.\n", alice.salary);
    }
    
    alice.capital += alice.salary;
    printf("Месяц %d.%d: + Зарплата: %lld руб. (капитал: %lld руб.)\n", month, year, alice.salary, alice.capital);

    check_and_take_loan(year, month);
}



void alice_taxes(const int month, const int year) // Подоходный налог
{
    alice.capital -= alice.salary_tax;
    printf("Месяц %d: - Налог: %lld руб. (капитал: %lld руб.)\n", month, alice.salary_tax, alice.capital);

    check_and_take_loan(year, month);
}



void alice_gym(const int month, const int year) // Тренажерный зал
{
    alice.capital -= alice.gym;
    printf("Месяц %d: - Тренажерный зал: %lld руб. (капитал: %lld руб.)\n", month, alice.gym, alice.capital);

    check_and_take_loan(year, month);
}



void alice_clothes(const int month, const int year) // Одежда
{
    alice.capital -= alice.clothes;
    printf("Месяц %d: - Одежда: %lld руб. (капитал: %lld руб.)\n", month, alice.clothes, alice.capital);

    check_and_take_loan(year, month);
}



void alice_internet(const int month, const int year) // Интернет
{
    alice.capital -= alice.internet;
    printf("Месяц %d: - Интернет: %lld руб. (капитал: %lld руб.)\n", month, alice.internet, alice.capital);

    check_and_take_loan(year, month);
}



void alice_fixed_costs(const int month, const int year) // Коммунальные платежи
{
    // Коммунальные платежи могут меняться в зависимости от сезона
    RUB season_costs = alice.fixed_costs;
    if (month == 12 || month == 1 || month == 2) {
        season_costs += 3000; // Зимой больше за отопление
    }
    
    alice.capital -= season_costs;
    printf("Месяц %d: - Коммунальные: %lld руб. (капитал: %lld руб.)\n", month, season_costs, alice.capital);

    check_and_take_loan(year, month);
}



void alice_child_expenses(const int month, const int year) // Расходы на ребенка
{
    RUB total_child = alice.child.clothes + alice.child.food + alice.child.medicine + alice.child.school;
    
    // Дополнительные расходы на ребенка летом (лагерь и т.д.)
    if (month >= 6 && month <= 8) {
        total_child += 30000; // Летний лагерь
        printf("Месяц %d: + Летний лагерь для ребенка\n", month);
    }
    
    alice.capital -= total_child;
    printf("Месяц %d: - Ребенок (одежда + еда + лекарства + школа): %lld руб. (капитал: %lld руб.)\n", month, total_child, alice.capital);

    check_and_take_loan(year, month);
}



void alice_food(const int month, const int year) // Расходы на еду
{
    // Расходы на еду могут варьироваться
    RUB food_costs = alice.food;
    
    // Праздничные застолья
    if (month == 12 || month == 1) {
        food_costs += 10000;
    }
    
    alice.capital -= food_costs;
    printf("Месяц %d: - Еда: %lld руб. (капитал: %lld руб.)\n", month, food_costs, alice.capital);

    check_and_take_loan(year, month);
}



void alice_cat(const int month, const int year) // Расходы на кота
{
    alice.capital -= alice.cat.Proplan;
    printf("Месяц %d: - Корм для кота: %lld руб. (капитал: %lld руб.)\n", month, alice.cat.Proplan, alice.capital);

           alice.capital -= alice.cat.Vet;
           printf("Месяц %d: - Ветеринар; %lld руб. (капитал: %lld руб.)\n", month, alice.cat.Vet, alice.capital);

    check_and_take_loan(year, month);
}



void alice_car(const int month, const int year) // Расходы на машину
{
    // Бензин зависит от сезона и поездок
    RUB gas_cost = alice.car.gas;
    if (month >= 6 && month <= 8) {
        gas_cost += 5000; // Летом больше поездок
    }
    
    alice.capital -= gas_cost;
    printf("Месяц %d: - Бензин: %lld руб. (капитал: %lld руб.)\n", month, gas_cost, alice.capital);
    check_and_take_loan(year, month);
}



void friends_rest(const int month, const int year) // Встречи с друзьями
{
    int chance = rand() % 100 + 1; // Случайный шанс от 1 до 100
    
    if (chance <= 75) { // 75% шанс пойти с друзьями
        alice.capital -= alice.rest;
        printf("Месяц %d: - Встреча с друзьями (шанс %d%%): %lld руб. (капитал: %lld руб.)\n", month, chance, alice.rest, alice.capital);
        check_and_take_loan(year, month);
    } else {
        printf("Месяц %d: Встреча с друзьями отменяется (шанс %d%%)\n", month, chance);
    }
}



void alice_gambling(const int month, const int year) // Лотереи
{
    alice.capital -= alice.gambling;
    printf("Месяц %d: - Лотереи: %lld руб. (капитал: %lld руб.)\n", 
           month, alice.gambling, alice.capital);
    check_and_take_loan(year, month);
}



void alice_bank_interest(const int month) // Проценты по вкладу
{
    float pp = sberbank_interest(alice.capital);
    RUB interest = alice.capital * (pp / 12.0 / 100.0);
    alice.capital += interest;
    printf("Месяц %d: + Банковский процент (%.1f%%): %lld руб. (капитал: %lld руб.)\n", month, pp, interest, alice.capital);
}



void alice_savings(const int month) // Накопления
{
    RUB saved = alice.salary * 0.1; // 10% от зарплаты
    alice.savings += saved;
    printf("Месяц %d: Отложено в сбережения: %lld руб. (всего сбережений: %lld руб.)\n", month, saved, alice.savings);
}



void alice_trip(const int year, const int month) // Накопление на путешествие
{
    static RUB trip_savings = 0; // Отдельные сбережения на поездку
    trip_savings += 5000;
    printf("Месяц %d.%d: Накопление на путешествие: +5000 руб. (всего: %lld руб.)\n", month, year, trip_savings);
    
    if(trip_savings >= 200'000) {
        alice.capital -= 200'000;
        printf("***** ПУТЕШЕСТВИЕ! Потрачено 200,000 руб. (капитал: %lld руб.) *****\n", alice.capital);
        trip_savings = 0;
        check_and_take_loan(year, month);
    }
}



void alice_casino(const int month, const int year) // Казино
{
    // Начало игры только если есть деньги
    if (alice.capital <= 0) return;
    
    // Максимальное и минимальное значение ставки
    RUB max_bet = (alice.capital > 5000) ? 5000 : alice.capital / 10;
    RUB min_bet = (alice.capital > 1000) ? 1000 : 100;
    
    if (max_bet < min_bet) return; // Недостаточно денег для игры
    
    // Рандомное значение ставки
    RUB bet = min_bet + (rand() % (max_bet - min_bet + 1));
    
    // Рандомное число от 1 до 10 для игры
    int alice_number = rand() % 10 + 1;
    
    // Рандомное число приводящее к выйгрышу
    int winning_number = rand() % 10 + 1;
    
    printf("Месяц %d.%d - Казино: Ставка = %lld руб., число Алисы = %d, ", month, year, bet, alice_number);
    
    if (alice_number == winning_number) {
        RUB win_amount = bet * 5;
        alice.capital += win_amount;
        printf("ВЫИГРЫШ! +%lld руб. (выигрышное число %d) капитал: %lld руб.\n", win_amount, winning_number, alice.capital);
    } else {
        alice.capital -= bet;
        printf("ПРОИГРЫШ! -%lld руб. (выигрышное число %d) капитал: %lld руб.\n", bet, winning_number, alice.capital);
    }
    check_and_take_loan(year, month);
}



void alice_simulation()
{
    int year = 2026;
    int month = 2;
    
    printf("\n========== НАЧАЛО СИМУЛЯЦИИ ==========\n");
    printf("Начальный капитал: %lld руб.\n", alice.capital);
    printf("Период: Февраль 2026 - Февраль 2031\n\n");
    
    while (!(year == 2031 && month == 2)) {
        printf("\n========== МЕСЯЦ %d.%d ==========\n", month, year);
        
        // ДОХОДЫ
        alice_husband_alimony(month, year);      // Алименты
        alice_salary(year, month);                 // Зарплата
        alice_additional_income(month, year);      // Дополнительные доходы
        alice_bank_interest(month);                 // Банковские проценты
        
        // РАСХОДЫ (обязательные)
        alice_taxes(month, year);                   // Налоги
        alice_fixed_costs(month, year);             // Коммунальные
        alice_food(month, year);                     // Еда
        alice_child_expenses(month, year);           // Ребенок
        alice_medical_expenses(month, year);         // Медицина
        alice_transport(month, year);                 // Транспорт
        alice_internet(month, year);                  // Интернет
        alice_car(month, year);                       // Бензин
        alice_cat(month, year);                       // Кот
        
        // РАСХОДЫ (необязательные, но регулярные)
        alice_education(month, year);                 // Образование
        alice_health(month, year);                    // Здоровье
        alice_entertainment(month, year);             // Развлечения
        alice_gym(month, year);                        // Спортзал
        alice_clothes(month, year);                    // Одежда
        alice_gifts(month, year);                      // Подарки
        alice_gambling(month, year);    
        alice_CounterStrike(month, year);
        
        // СОЦИАЛЬНЫЕ РАСХОДЫ
        friends_rest(month, year);                     // Друзья
        
        // ИНВЕСТИЦИИ И РИСКИ
        alice_investments(month, year);                // Инвестиции
        alice_casino(month, year);                     // Казино
        
        // НАКОПЛЕНИЯ И БОЛЬШИЕ ТРАТЫ
        alice_savings(month);                          // Сбережения
        alice_trip(year, month);                       // Путешествие
        
        // ГОДОВЫЕ РАСХОДЫ
        if (month == 12) {                             // Ремонт дома раз в год
            alice_house_repair(year);
        }
        
        // ПЛАТЕЖИ ПО КРЕДИТАМ
        process_loan_payment(year, month);             // Платеж по кредиту
        
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}



void print_spending_summary() 
{
    printf("\n\n========== ИТОГИ ЗА 5 ЛЕТ (2026-2031) ==========\n");
    printf("================================================\n");
    
    int total_months = 61; // Фев 2026 - Фев 2031 (5 лет)
    int total_years = 5;
    
    // Основные расходы
    long long total_food = alice.food * total_months;
    long long total_gambling = alice.gambling * total_months;
    long long total_tax = alice.salary_tax * total_months;
    long long total_fixed_costs = alice.fixed_costs * total_months;
    long long total_car_gas = alice.car.gas * total_months;
    long long total_cat_food = alice.cat.Proplan * total_months;
    long long total_cat_Vet = alice.cat.Vet * total_months;
    long long total_rest = alice.rest * 45;
    long long total_internet = alice.internet * total_months;
    long long total_clothes = alice.clothes * total_months;
    long long total_gym = alice.gym * total_months;
    long long total_house_repair = alice.house.repair * total_years;
    long long total_CounterStrike = (alice.cs.Battle_pass * total_months) + (alice.cs.Battle_pass * total_months);
    
    // Новые расходы
    long long total_medical = (alice.medical.monthly * total_months) + (alice.medical.dentist * 10) + (alice.medical.emergency * 3); 
    
    long long total_entertainment = (alice.entertainment.cinema + alice.entertainment.subscriptions) * total_months + (alice.entertainment.restaurant * 40) + (alice.entertainment.hobbies * 30);     
    
    long long total_transport = (alice.transport.public_transport * total_months) + (alice.transport.taxi * 24) + (alice.transport.car_insurance * 5) + (alice.transport.car_maintenance * 5);
    
    long long total_education = (alice.education.books * total_months) + (alice.education.child_circles * total_months) + (alice.education.courses * 15); 
    
    long long total_health = (alice.health.pharmacy + alice.health.vitamins) * total_months + (alice.health.sports_equipment * 20); 
    
    long long total_gifts = (alice.gifts.birthday * 20) + (alice.gifts.new_year * 5) + (alice.gifts.other * 18); 
    
    long long total_child = (alice.child.clothes + alice.child.food + alice.child.medicine + alice.child.school) * total_months;
    
    
    long long total_alimony = alice.husband.alimony_payments * total_months;
    
    long long total_salary = 0;
    RUB current_salary = 200'000;
    for (int i = 0; i < total_months; i++) {
        if (i == 1) { // Март 2026 (повышение)
            current_salary *= 1.2;
        }
        if (i % 12 == 11) { // Каждый январь индексация
            current_salary *= 1.05;
        }
        total_salary += current_salary;
    }
    
    printf("\n========== КРЕДИТНАЯ ИСТОРИЯ ==========\n");
    printf("Количество взятых кредитов: %d\n", alice.capital_control.loan_count);
    printf("Общая сумма взятых кредитов: %'lld руб.\n", alice.capital_control.total_loan_amount);
    printf("Всего выплачено процентов: %'lld руб.\n", alice.capital_control.total_interest_paid);
    printf("Всего штрафов: %'lld руб.\n", alice.capital_control.total_penalties);
    
    if (alice.capital_control.active_loan.has_loan) {
        printf("\nАктивный кредит:\n");
        printf("  Сумма: %'lld руб.\n", alice.capital_control.active_loan.amount);
        printf("  Ставка: %.1f%%\n", alice.capital_control.active_loan.interest_rate);
        printf("  Ежемесячный платеж: %'lld руб.\n", alice.capital_control.active_loan.monthly_payment);
        printf("  Осталось месяцев: %d\n", alice.capital_control.active_loan.months_left);
    } else {
        printf("\nНет активных кредитов\n");
    }
    
    printf("\n========== ИНВЕСТИЦИОННЫЙ ПОРТФЕЛЬ ==========\n");
    printf("Предметы в Стим: %'lld руб. \n", alice.investments.steam_marketplace);
    printf("Акции: %'lld руб.\n", alice.investments.stocks);
    printf("Криптовалюта: %'lld руб.\n", alice.investments.crypto);
    printf("Депозит: %'lld руб.\n", alice.capital);
    printf("Всего инвестиций: %'lld руб.\n", alice.investments.stocks + alice.investments.crypto + alice.investments.steam_marketplace);
    
    long long total_expenses = total_food + total_gambling + total_tax + total_fixed_costs + 
                               total_car_gas + total_cat_food + total_cat_Vet + total_rest + total_internet + 
                               total_clothes + total_gym + total_house_repair + total_child +
                               total_medical + total_entertainment + total_transport + 
                               total_education + total_health + total_CounterStrike + total_gifts;
    
    long long total_income = total_salary + total_alimony + 
                             (alice.additional_income.freelance * 40) + 
                             (alice.additional_income.dividends * 20) + 
                             (alice.additional_income.cashback * total_months) +
                             (alice.additional_income.birthday_gifts * 5) +
                             (alice.additional_income.bonus * 5);
    
    printf("\n========== ИТОГОВЫЙ БАЛАНС ==========\n");
    printf("Начальный капитал: %'lld руб.\n", 500'000);
    printf("Всего доходов: %'lld руб.\n", total_income);
    printf("Всего расходов: %'lld руб.\n", total_expenses);
    printf("Всего кредитов: %'lld руб.\n", alice.capital_control.total_loan_amount);
    printf("----------------------------------------\n");
    printf("Фактический капитал: %'lld руб.\n", alice.capital);
    printf("Фактические сбережения: %'lld руб.\n", alice.savings);
    printf("Инвестиции: %'lld руб.\n", alice.investments.stocks + alice.investments.crypto);
    printf("========================================\n");
}



int main()
{
    alice_init();
    srand(time(NULL)); // Инициализация генератора случайных чисел
    alice_simulation();
    print_spending_summary();
    return 0;
}