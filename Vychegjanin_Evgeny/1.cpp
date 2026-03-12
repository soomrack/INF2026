#include <iostream>
#include <cmath>

// Тип для денег
using RUB = long long;



// СТРУКТУРЫ ДАННЫХ

// Основная структура персонажа
struct Person {
    RUB salary;            // текущая зарплата (грязными)
    RUB cash;              // свободные деньги
    RUB food_cost;         // ежемесячные расходы на еду
    RUB rent_cost;         // аренда квартиры
    RUB internet_cost;     // интернет и связь
    RUB fitness_cost;      // фитнес / здоровье
    double tax_rate;       // ставка НДФЛ
    bool has_computer;     // куплен ли компьютер
    bool has_apartment;    // куплена ли квартира
};

// Машина
struct Car {
    RUB value;                 // текущая стоимость машины
    RUB monthly_cost;          // ежемесячные расходы
    double depreciation_rate;  // процент удешевления в месяц
    RUB insurance_cost;        // ОСАГО раз в год
    RUB service_cost;          // ТО раз в год
    bool is_active;            // активна ли машина
};

// Банковский вклад
struct Deposit {
    RUB balance;                    // сумма на вкладе
    double interest_rate;           // годовой процент
    double transfer_percent;        // процент перевода от свободных денег
    RUB min_cash_after_transfer;    // минимальный остаток наличных после перевода
    RUB max_monthly_transfer;       // ограничение на пополнение вклада в месяц
};

// Инфляция
struct Inflation {
    double rate; // годовая инфляция
};

// Индексация зарплаты
struct SalaryIndexation {
    double rate; // процент индексации
    int month;   // месяц индексации
};

// Общественный транспорт
struct PublicTransport {
    RUB monthly_cost; // стоимость в месяц
    bool is_active;   // активен ли транспорт
};

// Квартира
struct Apartment {
    RUB price;         // фиксированная цена квартиры
    bool is_bought;    // куплена ли квартира
    RUB utility_cost;  // коммунальные платежи после покупки квартиры
};

// Отпуск
struct Vacation {
    RUB cost;       // стоимость отпуска
    int month;      // месяц отпуска
    bool is_active; // активен ли блок
};

// Непредвиденные расходы
struct UnexpectedExpense {
    RUB cost;       // сумма расхода
    int month;      // месяц расхода
    bool is_active; // активен ли блок
};



// ГЛОБАЛЬНЫЕ ОБЪЕКТЫ


Person alice;

Car first_car;   // первая машина
Car second_car;  // вторая машина

Deposit alice_deposit;
Inflation inflation;
SalaryIndexation salary_indexation;
PublicTransport public_transport;
Apartment apartment;
Vacation vacation;
UnexpectedExpense unexpected_expense;

// Константы крупных покупок
constexpr RUB COMPUTER_PRICE = 300'000;
constexpr RUB SECOND_CAR_PRICE = 2'000'000;
constexpr RUB SECOND_CAR_DEPOSIT_THRESHOLD = 2'500'000;



// ИНИЦИАЛИЗАЦИЯ


void person_init()
{
    alice.salary = 180'000;
    alice.cash = 0;
    alice.food_cost = 15'000;
    alice.rent_cost = 40'000;      // аренда до покупки квартиры
    alice.internet_cost = 1'500;   // интернет и связь
    alice.fitness_cost = 4'000;    // фитнес / здоровье
    alice.tax_rate = 13.0;         // НДФЛ
    alice.has_computer = false;
    alice.has_apartment = false;
}

void first_car_init()
{
    first_car.value = 2'400'000;
    first_car.monthly_cost = 12'000;
    first_car.depreciation_rate = 2.0;
    first_car.insurance_cost = 18'000; // ОСАГО
    first_car.service_cost = 25'000;   // ТО
    first_car.is_active = true;
}

void second_car_init()
{
    // Вторая машина изначально не куплена
    second_car.value = SECOND_CAR_PRICE;
    second_car.monthly_cost = 15'000;
    second_car.depreciation_rate = 2.0;
    second_car.insurance_cost = 18'000; // ОСАГО
    second_car.service_cost = 30'000;   // ТО
    second_car.is_active = false;
}

void deposit_init()
{
    alice_deposit.balance = 0;
    alice_deposit.interest_rate = 12.5;
    alice_deposit.transfer_percent = 20.0;
    alice_deposit.min_cash_after_transfer = 20'000;
    alice_deposit.max_monthly_transfer = 80'000; // ограничение на слишком быстрое накопление
}

void inflation_init()
{
    inflation.rate = 6.01;
}

void salary_indexation_init()
{
    salary_indexation.rate = 7.6;
    salary_indexation.month = 1; // январь
}

void public_transport_init()
{
    public_transport.monthly_cost = 3'900;
    public_transport.is_active = false;
}

void apartment_init()
{
    apartment.price = 7'000'000; // цена фиксированная
    apartment.is_bought = false;
    apartment.utility_cost = 8'000; // коммуналка после покупки квартиры
}

void vacation_init()
{
    vacation.cost = 180'000;
    vacation.month = 7; // июль
    vacation.is_active = true;
}

void unexpected_expense_init()
{
    unexpected_expense.cost = 50'000;
    unexpected_expense.month = 11; // ноябрь
    unexpected_expense.is_active = true;
}

void all_init()
{
    person_init();
    first_car_init();
    second_car_init();
    deposit_init();
    inflation_init();
    salary_indexation_init();
    public_transport_init();
    apartment_init();
    vacation_init();
    unexpected_expense_init();
}



// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ


// Перевод годового процента в месячный
double monthly_rate(double yearly_rate)
{
    return yearly_rate / 12.0 / 100.0;
}

// Вычисление процента от суммы
RUB percent_of(RUB value, double percent)
{
    return static_cast<RUB>(std::llround(value * percent / 100.0));
}

// Максимум, который можно взять со вклада на компьютер
RUB computer_max_deposit_part()
{
    return percent_of(COMPUTER_PRICE, 20.0); // не более 20% от цены компьютера
}

// Общая сумма ликвидных средств: наличные + вклад
RUB liquid_money()
{
    return alice.cash + alice_deposit.balance;
}

// Итоговый капитал
RUB total_capital()
{
    RUB result = 0;

    result += alice.cash;
    result += alice_deposit.balance;

    if (first_car.is_active) {
        result += first_car.value;
    }

    if (second_car.is_active) {
        result += second_car.value;
    }

    if (apartment.is_bought) {
        result += apartment.price;
    }

    return result;
}



// СИСТЕМНЫЕ БЛОКИ


// Инфляция:
// - увеличивает еду
// - увеличивает аренду
// - увеличивает коммуналку
// - увеличивает интернет
// - увеличивает фитнес
// - увеличивает расходы на машины
// - увеличивает отпуск
// - увеличивает непредвиденные расходы
// - НЕ влияет на общественный транспорт
// - НЕ влияет на стоимость квартиры
void apply_inflation()
{
    const double k = 1.0 + monthly_rate(inflation.rate);

    alice.food_cost = static_cast<RUB>(std::llround(alice.food_cost * k));
    alice.rent_cost = static_cast<RUB>(std::llround(alice.rent_cost * k));
    alice.internet_cost = static_cast<RUB>(std::llround(alice.internet_cost * k));
    alice.fitness_cost = static_cast<RUB>(std::llround(alice.fitness_cost * k));

    apartment.utility_cost = static_cast<RUB>(std::llround(apartment.utility_cost * k));

    vacation.cost = static_cast<RUB>(std::llround(vacation.cost * k));
    unexpected_expense.cost = static_cast<RUB>(std::llround(unexpected_expense.cost * k));

    if (first_car.is_active) {
        first_car.monthly_cost = static_cast<RUB>(std::llround(first_car.monthly_cost * k));
        first_car.insurance_cost = static_cast<RUB>(std::llround(first_car.insurance_cost * k));
        first_car.service_cost = static_cast<RUB>(std::llround(first_car.service_cost * k));
    }

    if (second_car.is_active) {
        second_car.monthly_cost = static_cast<RUB>(std::llround(second_car.monthly_cost * k));
        second_car.insurance_cost = static_cast<RUB>(std::llround(second_car.insurance_cost * k));
        second_car.service_cost = static_cast<RUB>(std::llround(second_car.service_cost * k));
    }
}

// Ежегодная индексация зарплаты в январе
void apply_salary_indexation(int month)
{
    if (month == salary_indexation.month) {
        alice.salary = static_cast<RUB>(
            std::llround(alice.salary * (1.0 + salary_indexation.rate / 100.0))
        );
    }
}

// Начисление зарплаты с учётом налога
void apply_salary()
{
    RUB tax = percent_of(alice.salary, alice.tax_rate);
    RUB net_salary = alice.salary - tax;
    alice.cash += net_salary;
}

// Пополнение вклада:
// переводим 20% от наличных, но не больше лимита в месяц,
// и только если после этого останется не меньше 20000
void apply_deposit_transfer()
{
    if (alice.cash <= alice_deposit.min_cash_after_transfer) {
        return;
    }

    RUB transfer = percent_of(alice.cash, alice_deposit.transfer_percent);

    if (transfer > alice_deposit.max_monthly_transfer) {
        transfer = alice_deposit.max_monthly_transfer;
    }

    if (transfer <= 0) {
        return;
    }

    if (alice.cash - transfer < alice_deposit.min_cash_after_transfer) {
        return;
    }

    alice.cash -= transfer;
    alice_deposit.balance += transfer;
}

// Начисление процентов по вкладу
void apply_deposit_interest()
{
    RUB income = static_cast<RUB>(
        std::llround(alice_deposit.balance * monthly_rate(alice_deposit.interest_rate))
    );

    alice_deposit.balance += income;
}



// БЫТОВЫЕ РАСХОДЫ


// Еда
void apply_food_cost()
{
    alice.cash -= alice.food_cost;
}

// Интернет и связь
void apply_internet_cost()
{
    alice.cash -= alice.internet_cost;
}

// Фитнес / здоровье
void apply_fitness_cost()
{
    alice.cash -= alice.fitness_cost;
}

// Аренда квартиры платится, пока собственная квартира не куплена
void apply_rent_cost()
{
    if (!apartment.is_bought) {
        alice.cash -= alice.rent_cost;
    }
}

// После покупки квартиры платим коммуналку
void apply_utility_cost()
{
    if (apartment.is_bought) {
        alice.cash -= apartment.utility_cost;
    }
}

// Расходы на первую машину
void apply_first_car_cost()
{
    if (!first_car.is_active) {
        return;
    }

    alice.cash -= first_car.monthly_cost;
}

// Расходы на вторую машину
void apply_second_car_cost()
{
    if (!second_car.is_active) {
        return;
    }

    alice.cash -= second_car.monthly_cost;
}

// Удешевление первой машины
void apply_first_car_depreciation()
{
    if (!first_car.is_active) {
        return;
    }

    first_car.value = static_cast<RUB>(
        std::llround(first_car.value * (1.0 - first_car.depreciation_rate / 100.0))
    );
}

// Удешевление второй машины
void apply_second_car_depreciation()
{
    if (!second_car.is_active) {
        return;
    }

    second_car.value = static_cast<RUB>(
        std::llround(second_car.value * (1.0 - second_car.depreciation_rate / 100.0))
    );
}

// Общественный транспорт
void apply_public_transport_cost()
{
    if (!public_transport.is_active) {
        return;
    }

    alice.cash -= public_transport.monthly_cost;
}

// Отпуск раз в год
void apply_vacation_cost(int month)
{
    if (!vacation.is_active) {
        return;
    }

    if (month == vacation.month) {
        alice.cash -= vacation.cost;
    }
}

// Непредвиденные расходы раз в год
void apply_unexpected_expense(int month)
{
    if (!unexpected_expense.is_active) {
        return;
    }

    if (month == unexpected_expense.month) {
        alice.cash -= unexpected_expense.cost;
    }
}

// ОСАГО для первой машины раз в год
void apply_first_car_insurance(int month)
{
    if (!first_car.is_active) {
        return;
    }

    if (month == 3) {
        alice.cash -= first_car.insurance_cost;
    }
}

// ОСАГО для второй машины раз в год
void apply_second_car_insurance(int month)
{
    if (!second_car.is_active) {
        return;
    }

    if (month == 3) {
        alice.cash -= second_car.insurance_cost;
    }
}

// ТО для первой машины раз в год
void apply_first_car_service(int month)
{
    if (!first_car.is_active) {
        return;
    }

    if (month == 9) {
        alice.cash -= first_car.service_cost;
    }
}

// ТО для второй машины раз в год
void apply_second_car_service(int month)
{
    if (!second_car.is_active) {
        return;
    }

    if (month == 9) {
        alice.cash -= second_car.service_cost;
    }
}



// СОБЫТИЯ


// Покупка компьютера:
// - можно оплатить наличными
// - можно добрать со вклада, но не более 20% от цены компьютера
void try_buy_computer()
{
    if (alice.has_computer) {
        return;
    }

    RUB max_from_deposit = computer_max_deposit_part();
    RUB available_from_deposit = std::min(alice_deposit.balance, max_from_deposit);

    if (alice.cash + available_from_deposit < COMPUTER_PRICE) {
        return;
    }

    RUB need_from_deposit = 0;

    if (alice.cash < COMPUTER_PRICE) {
        need_from_deposit = COMPUTER_PRICE - alice.cash;
    }

    if (need_from_deposit > available_from_deposit) {
        return;
    }

    RUB from_cash = COMPUTER_PRICE - need_from_deposit;

    alice.cash -= from_cash;
    alice_deposit.balance -= need_from_deposit;
    alice.has_computer = true;
}

// Покупка квартиры без кредита:
// - квартира покупается только если хватает наличных + вклада
// - сначала тратятся наличные
// - остаток при необходимости добирается со вклада
void try_buy_apartment()
{
    if (apartment.is_bought) {
        return;
    }

    if (liquid_money() < apartment.price) {
        return;
    }

    RUB need_from_deposit = 0;

    if (alice.cash < apartment.price) {
        need_from_deposit = apartment.price - alice.cash;
    }

    RUB from_cash = apartment.price - need_from_deposit;

    alice.cash -= from_cash;
    alice_deposit.balance -= need_from_deposit;

    apartment.is_bought = true;
    alice.has_apartment = true;
}

// Покупка второй машины:
// - только после покупки квартиры
// - только если вторая машина ещё не куплена
// - если на вкладе хотя бы 2 500 000
// - покупаем её со вклада за 2 000 000
void try_buy_second_car()
{
    if (!apartment.is_bought) {
        return;
    }

    if (second_car.is_active) {
        return;
    }

    if (alice_deposit.balance < SECOND_CAR_DEPOSIT_THRESHOLD) {
        return;
    }

    alice_deposit.balance -= SECOND_CAR_PRICE;
    second_car.is_active = true;
}

// Покрытие минуса со вклада
void cover_negative_cash_from_deposit()
{
    if (alice.cash >= 0) {
        return;
    }

    RUB need = -alice.cash;
    RUB taken = std::min(need, alice_deposit.balance);

    alice_deposit.balance -= taken;
    alice.cash += taken;
}

// Продажа первой машины, если денег всё ещё не хватает
void sell_first_car_if_needed()
{
    if (alice.cash >= 0) {
        return;
    }

    if (!first_car.is_active) {
        return;
    }

    alice.cash += first_car.value;
    first_car.value = 0;
    first_car.monthly_cost = 0;
    first_car.insurance_cost = 0;
    first_car.service_cost = 0;
    first_car.is_active = false;

    public_transport.is_active = true;
}

// При необходимости можно продать и вторую машину
void sell_second_car_if_needed()
{
    if (alice.cash >= 0) {
        return;
    }

    if (!second_car.is_active) {
        return;
    }

    alice.cash += second_car.value;
    second_car.value = 0;
    second_car.monthly_cost = 0;
    second_car.insurance_cost = 0;
    second_car.service_cost = 0;
    second_car.is_active = false;
}



// СИМУЛЯЦИЯ


void simulate_month(int year, int month)
{
    (void)year; // оставлено для расширения модели

    // 1. Инфляция
    apply_inflation();

    // 2. Индексация зарплаты
    apply_salary_indexation(month);

    // 3. Начисление зарплаты
    apply_salary();

    // 4. Ежемесячные расходы
    apply_food_cost();
    apply_internet_cost();
    apply_fitness_cost();
    apply_rent_cost();
    apply_utility_cost();

    apply_first_car_cost();
    apply_second_car_cost();
    apply_public_transport_cost();

    // 5. Годовые расходы
    apply_vacation_cost(month);
    apply_unexpected_expense(month);

    apply_first_car_insurance(month);
    apply_second_car_insurance(month);

    apply_first_car_service(month);
    apply_second_car_service(month);

    // 6. Амортизация машин
    apply_first_car_depreciation();
    apply_second_car_depreciation();

    // 7. Пополнение вклада и проценты
    apply_deposit_transfer();
    apply_deposit_interest();

    // 8. Крупные события
    try_buy_computer();
    try_buy_apartment();
    try_buy_second_car();

    // 9. Если ушли в минус — сначала закрываем вкладом
    cover_negative_cash_from_deposit();

    // 10. Если вклада не хватило — продаём машины
    sell_first_car_if_needed();
    cover_negative_cash_from_deposit();

    sell_second_car_if_needed();
    cover_negative_cash_from_deposit();
}

void simulate_years(int start_year, int start_month, int years_count)
{
    int year = start_year;
    int month = start_month;

    const int total_months = years_count * 12;

    for (int i = 0; i < total_months; ++i) {
        simulate_month(year, month);

        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}



// ВЫВОД РЕЗУЛЬТАТОВ


void print_results()
{
    std::cout << "===== Результаты симуляции =====\n";
    std::cout << "Зарплата: " << alice.salary << "\n";
    std::cout << "Свободные деньги: " << alice.cash << "\n";
    std::cout << "Вклад: " << alice_deposit.balance << "\n";
    std::cout << "Еда в месяц: " << alice.food_cost << "\n";
    std::cout << "Интернет и связь в месяц: " << alice.internet_cost << "\n";
    std::cout << "Фитнес в месяц: " << alice.fitness_cost << "\n";

    if (!apartment.is_bought) {
        std::cout << "Аренда в месяц: " << alice.rent_cost << "\n";
    } else {
        std::cout << "Коммуналка в месяц: " << apartment.utility_cost << "\n";
    }

    std::cout << "Компьютер куплен: "
              << (alice.has_computer ? "да" : "нет") << "\n";

    // Первая машина
    std::cout << "Первая машина: "
              << (first_car.is_active ? "есть" : "нет") << "\n";

    if (first_car.is_active) {
        std::cout << "Стоимость первой машины: " << first_car.value << "\n";
        std::cout << "Расход первой машины в месяц: " << first_car.monthly_cost << "\n";
    }

    // Вторая машина
    std::cout << "Вторая машина: "
              << (second_car.is_active ? "есть" : "нет") << "\n";

    if (second_car.is_active) {
        std::cout << "Стоимость второй машины: " << second_car.value << "\n";
        std::cout << "Расход второй машины в месяц: " << second_car.monthly_cost << "\n";
    }

    std::cout << "Общественный транспорт: "
              << (public_transport.is_active ? "да" : "нет") << "\n";

    std::cout << "Квартира: "
              << (apartment.is_bought ? "есть" : "нет") << "\n";

    if (apartment.is_bought) {
        std::cout << "Стоимость квартиры: " << apartment.price << "\n";
    }

    std::cout << "Отпуск в год: " << vacation.cost << "\n";
    std::cout << "Непредвиденные расходы в год: " << unexpected_expense.cost << "\n";

    std::cout << "Итоговый капитал: " << total_capital() << "\n";
}



// MAIN


int main()
{
    all_init();

    // Симуляция на 5 лет с января 2026 года
    simulate_years(2026, 1, 5);

    print_results();

    return 0;
}
