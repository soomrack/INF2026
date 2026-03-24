#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iomanip>


class MoneyFormatter {
public:
    static std::string format(double amount) {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2);
        
        if (std::abs(amount) >= 1'000'000'000) {
            ss << amount / 1'000'000'000 << " млрд руб";
        } else if (std::abs(amount) >= 1'000'000) {
            ss << amount / 1'000'000 << " млн руб";
        } else if (std::abs(amount) >= 1'000) {
            ss << amount / 1'000 << " тыс руб";
        } else {
            ss << amount << " руб";
        }
        
        return ss.str();
    }
    
    static std::string formatShort(double amount) {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1);
        
        if (std::abs(amount) >= 1'000'000) {
            ss << amount / 1'000'000 << "M";
        } else if (std::abs(amount) >= 1'000) {
            ss << amount / 1'000 << "K";
        } else {
            ss << amount;
        }
        
        return ss.str();
    }
};



struct MonthlyExpenses {
    double food;           // еда
    double utilities;      // коммунальные услуги
    double transport;      // транспорт (общественный)
    double entertainment;  // развлечения
    double other;          // прочее
    
    double total() const {
        return food + utilities + transport + entertainment + other;
    }
};

struct Pet {
    std::string type;      // тип питомца (собака/кошка/и т.д.)
    int count;             // количество
    double foodPerMonth;   // расходы на корм в месяц
    double vetPerYear;     // расходы на ветеринара в год
    double insurance;      // страховка в год
    
    double monthlyCost() const {
        return foodPerMonth + (vetPerYear + insurance) / 12;
    }
};

struct Car {
    std::string model;
    double fuelCostPerMonth;      // бензин
    double maintenancePerMonth;   // обслуживание (ТО, резина, мойка)
    double insurancePerYear;      // страховка
    double taxPerYear;             // транспортный налог
    double depreciationRate;      // амортизация в год (0.15 = 15%)
    
    double monthlyCost() const {
        return fuelCostPerMonth + maintenancePerMonth + 
               (insurancePerYear + taxPerYear) / 12;
    }
};



class InflationModel {
private:
    double baseRate;           // базовая ставка инфляции
    double volatility;         // волатильность (отклонение)
    std::vector<double> yearlyRates;  // исторические значения
    
public:
    InflationModel(double rate = 0.07, double vol = 0.02) 
        : baseRate(rate), volatility(vol) {}
    
    double getRateForYear(int year) {
        // Простая модель: инфляция может немного колебаться
        double variation = 1.0 + (std::sin(year) * volatility);
        double rate = baseRate * variation;
        
        // Ограничиваем разумными пределами
        rate = std::max(0.03, std::min(0.12, rate));
        yearlyRates.push_back(rate);
        return rate;
    }
    
    double getAverageRate() const {
        if (yearlyRates.empty()) return baseRate;
        return std::accumulate(yearlyRates.begin(), yearlyRates.end(), 0.0) 
               / yearlyRates.size();
    }
};



class InvestmentAccount {
private:
    double balance;                 // текущий баланс
    double annualReturnRate;        // годовая доходность
    double riskFactor;              // фактор риска (для симуляции)
    std::vector<double> history;
    
public:
    InvestmentAccount(double rate = 0.12, double risk = 0.03) 
        : balance(0), annualReturnRate(rate), riskFactor(risk) {}
    
    void deposit(double amount) {
        balance += amount;
    }
    
    void withdraw(double amount) {
        balance = std::max(0.0, balance - amount);
    }
    
    void applyMonthlyReturn(int month) {
        // Ежемесячная капитализация с небольшой волатильностью
        double monthlyRate = annualReturnRate / 12;
        double variation = 1.0 + (std::sin(month) * riskFactor);
        double effectiveRate = monthlyRate * variation;
        
        balance *= (1 + effectiveRate);
        history.push_back(balance);
    }
    
    double getBalance() const { return balance; }
    
    double getTotalProfit() const {
        if (history.empty()) return 0;
        return balance - (history.front() > 0 ? history.front() : 0);
    }
};



class Person {
protected:
    std::string name;
    int age;
    double monthlySalary;
    double monthlySalaryGrowth;      // рост зарплаты сверх инфляции
    
    // Расходы
    MonthlyExpenses baseExpenses;
    std::vector<Pet> pets;
    Car car;
    
    // Финансы
    InvestmentAccount investments;
    double cash;
    
    // Статистика
    double totalIncome;
    double totalExpenses;
    double totalWastedMoney;          // деньги, ушедшие "в никуда" (аренда/проценты)
    
    // История для аналитики
    std::vector<double> wealthHistory;
    std::vector<double> cashHistory;
    
    // Параметры симуляции
    InflationModel* inflation;
    int currentYear;
    int currentMonth;
    
public:
    Person(std::string n, double salary, int startAge = 25, InflationModel* inf = nullptr)
        : name(n)
        , age(startAge)
        , monthlySalary(salary)
        , monthlySalaryGrowth(0.01)     // +1% сверх инфляции за опыт
        , cash(500'000)                 // начальный капитал 500к
        , totalIncome(0)
        , totalExpenses(0)
        , totalWastedMoney(0)
        , inflation(inf)
        , currentYear(2025)
        , currentMonth(1) {
        
        // Настройка базовых расходов
        baseExpenses.food = 25'000;
        baseExpenses.utilities = 8'000;
        baseExpenses.transport = 5'000;
        baseExpenses.entertainment = 10'000;
        baseExpenses.other = 7'000;
        
        // Добавляем питомца (кошка)
        Pet cat;
        cat.type = "Кошка";
        cat.count = 1;
        cat.foodPerMonth = 5'000;
        cat.vetPerYear = 8'000;
        cat.insurance = 3'000;
        pets.push_back(cat);
        
        // Настройка автомобиля
        car.model = "Toyota Camry";
        car.fuelCostPerMonth = 15'000;
        car.maintenancePerMonth = 7'000;
        car.insurancePerYear = 40'000;
        car.taxPerYear = 8'000;
        car.depreciationRate = 0.12;
        
        // Начальные инвестиции
        investments.deposit(cash);
    }
    
    virtual ~Person() = default;
    
    // Виртуальные методы
    virtual void liveMonth() = 0;
    virtual void printStatus() const = 0;
    virtual std::string getStrategy() const = 0;
    
    // Обновление расходов с учетом инфляции
    void applyInflation() {
        if (!inflation) return;
        
        double inflationRate = inflation->getRateForYear(currentYear);
        
        // Индексируем все расходы
        baseExpenses.food *= (1 + inflationRate);
        baseExpenses.utilities *= (1 + inflationRate);
        baseExpenses.transport *= (1 + inflationRate);
        baseExpenses.entertainment *= (1 + inflationRate);
        baseExpenses.other *= (1 + inflationRate);
        
        // Расходы на питомцев
        for (auto& pet : pets) {
            pet.foodPerMonth *= (1 + inflationRate);
            pet.vetPerYear *= (1 + inflationRate);
            pet.insurance *= (1 + inflationRate);
        }
        
        // Автомобильные расходы
        car.fuelCostPerMonth *= (1 + inflationRate);
        car.maintenancePerMonth *= (1 + inflationRate);
        car.insurancePerYear *= (1 + inflationRate);
        car.taxPerYear *= (1 + inflationRate);
        
        // Зарплата растет (инфляция + карьерный рост)
        monthlySalary *= (1 + inflationRate + monthlySalaryGrowth);
    }
    
    double getTotalMonthlyExpenses() const {
        double total = baseExpenses.total();
        
        // Расходы на питомцев
        for (const auto& pet : pets) {
            total += pet.monthlyCost();
        }
        
        // Расходы на авто
        total += car.monthlyCost();
        
        return total;
    }
    
    void investSavings() {
        // Инвестируем все свободные деньги в конце месяца
        if (cash > 0) {
            investments.deposit(cash);
            cash = 0;
        }
    }
    
    void applyInvestmentReturns(int month) {
        investments.applyMonthlyReturn(month);
    }
    
    void recordHistory() {
        wealthHistory.push_back(getNetWorth());
        cashHistory.push_back(cash + investments.getBalance());
    }
    
    // Геттеры
    double getNetWorth() const { return cash + investments.getBalance(); }
    double getCash() const { return cash; }
    double getInvestments() const { return investments.getBalance(); }
    double getTotalIncome() const { return totalIncome; }
    double getTotalExpenses() const { return totalExpenses; }
    double getTotalWastedMoney() const { return totalWastedMoney; }
    
    const std::vector<double>& getWealthHistory() const { return wealthHistory; }
    
    void setYear(int year) { currentYear = year; }
    void setMonth(int month) { currentMonth = month; }
    
protected:
    void addIncome(double amount) {
        cash += amount;
        totalIncome += amount;
    }
    
    void addExpense(double amount, bool isWasted = false) {
        cash -= amount;
        totalExpenses += amount;
        if (isWasted) totalWastedMoney += amount;
    }
};

class Alice : public Person {
private:
    double rentPerMonth;              // арендная плата
    double targetApartmentPrice;      // целевая стоимость квартиры
    double targetApartmentArea;       // площадь квартиры
    double rentGrowthRate;            // рост аренды
    
    std::vector<double> rentHistory;
    bool boughtApartment;
    double apartmentValue;            // стоимость купленной квартиры
    
public:
    Alice(InflationModel* inf) 
        : Person("Алиса", 250'000, 25, inf)
        , rentPerMonth(65'000)
        , targetApartmentPrice(14'500'000)
        , targetApartmentArea(58)
        , rentGrowthRate(0.06)          // аренда растет чуть медленнее инфляции
        , boughtApartment(false)
        , apartmentValue(0) {
        
        std::cout << "\n=== Инициализация Алисы ===\n";
        std::cout << "Стратегия: аренда + накопление на квартиру\n";
        std::cout << "Аренда: " << MoneyFormatter::format(rentPerMonth) << "/мес\n";
        std::cout << "Цель: купить квартиру за " 
                  << MoneyFormatter::format(targetApartmentPrice) << "\n";
        std::cout << "Начальный капитал: " << MoneyFormatter::format(cash) << "\n";
    }
    
    void liveMonth() override {
        // 1. Получаем зарплату
        addIncome(monthlySalary);
        
        // 2. Оплачиваем все расходы
        double monthlyExpenses = getTotalMonthlyExpenses() + rentPerMonth;
        addExpense(monthlyExpenses, true);  // аренда считается "выброшенными" деньгами
        
        // 3. Если накопили достаточно и еще не купили квартиру
        if (!boughtApartment && getNetWorth() >= targetApartmentPrice) {
            buyApartment();
        }
        
        // 4. Инвестируем остатки
        investSavings();
    }
    
    void buyApartment() {
        double totalMoney = getNetWorth();
        double price = std::min(targetApartmentPrice, totalMoney);
        
        // Снимаем деньги с инвестиций
        double fromInvestments = std::min(investments.getBalance(), price);
        investments.withdraw(fromInvestments);
        
        double fromCash = std::min(cash, price - fromInvestments);
        cash -= fromCash;
        
        apartmentValue = price;
        boughtApartment = true;
        
        std::cout << "\n🎉 " << name << " купила квартиру!\n";
        std::cout << "   Стоимость: " << MoneyFormatter::format(price) << "\n";
        std::cout << "   Остаток накоплений: " << MoneyFormatter::format(getNetWorth()) << "\n";
    }
    
    void applyRentIndexation() {
        rentPerMonth *= (1 + rentGrowthRate);
        rentHistory.push_back(rentPerMonth);
    }
    
    void printStatus() const override {
        std::cout << "\n┌─────────────────────────────────────────────────\n";
        std::cout << "│  " << name << " | " << currentYear << " г.\n";
        std::cout << "├─────────────────────────────────────────────────\n";
        std::cout << "│  Накопления: " << MoneyFormatter::format(getNetWorth()) << "\n";
        std::cout << "│    - Наличные: " << MoneyFormatter::format(cash) << "\n";
        std::cout << "│    - Инвестиции: " << MoneyFormatter::format(investments.getBalance()) << "\n";
        std::cout << "│  Аренда: " << MoneyFormatter::format(rentPerMonth) << "/мес\n";
        
        if (boughtApartment) {
            std::cout << "│  Квартира куплена! Стоимость: " 
                      << MoneyFormatter::format(apartmentValue) << "\n";
            std::cout << "│ Текущая стоимость (с учетом роста цен): " 
                      << MoneyFormatter::format(getApartmentCurrentValue()) << "\n";
        } else {
            double progress = (getNetWorth() / targetApartmentPrice) * 100;
            double need = targetApartmentPrice - getNetWorth();
            std::cout << "│  Прогресс к цели: " << std::fixed << std::setprecision(1) 
                      << progress << "%\n";
            std::cout << "│    Осталось: " << MoneyFormatter::format(need) << "\n";
        }
        
        std::cout << "│  Ежемесячные расходы: " 
                  << MoneyFormatter::format(getTotalMonthlyExpenses() + rentPerMonth) << "\n";
        std::cout << "│    - Из них 'на ветер': " 
                  << MoneyFormatter::format(rentPerMonth) << " (аренда)\n";
        std::cout << "└─────────────────────────────────────────────────\n";
    }
    
    double getApartmentCurrentValue() const {
        if (!boughtApartment) return 0;
        
        // Квартира дорожает на 8% в год (инфляция + рост рынка)
        int yearsSincePurchase = currentYear - 2025;
        return apartmentValue * std::pow(1.08, yearsSincePurchase);
    }
    
    std::string getStrategy() const override { return "Аренда + накопления"; }
    
    double getNetWorth() const override {
        if (boughtApartment) {
            return cash + investments.getBalance() + getApartmentCurrentValue();
        }
        return cash + investments.getBalance();
    }
};



class Subo : public Person {
private:
    double apartmentPrice;            // стоимость квартиры
    double apartmentArea;             // площадь
    double initialPayment;            // первоначальный взнос
    double mortgagePrincipal;         // тело кредита
    double mortgageMonthlyPayment;    // ежемесячный платеж
    double mortgageAnnualRate;        // годовая ставка
    int mortgageYears;                // срок ипотеки
    
    double remainingDebt;             // оставшийся долг
    double totalPaidToBank;           // всего выплачено банку
    double totalInterestPaid;         // всего процентов
    
    std::vector<double> debtHistory;
    bool mortgagePaid;
    
public:
    Subo(InflationModel* inf) 
        : Person("Субо", 250'000, 25, inf)
        , apartmentPrice(14'500'000)
        , apartmentArea(58)
        , mortgageAnnualRate(0.145)     // 14.5% годовых
        , mortgageYears(15)
        , mortgagePaid(false) {
        
        // Первоначальный взнос 20%
        initialPayment = apartmentPrice * 0.20;
        mortgagePrincipal = apartmentPrice - initialPayment;
        remainingDebt = mortgagePrincipal;
        
        // Расчет аннуитетного платежа
        double monthlyRate = mortgageAnnualRate / 12;
        int months = mortgageYears * 12;
        
        mortgageMonthlyPayment = mortgagePrincipal * monthlyRate *
                                 std::pow(1 + monthlyRate, months) /
                                 (std::pow(1 + monthlyRate, months) - 1);
        
        totalPaidToBank = initialPayment;
        totalInterestPaid = 0;
        
        // Первоначальный взнос из накоплений
        cash -= initialPayment;
        
        std::cout << "\n=== Инициализация Субо ===\n";
        std::cout << "Стратегия: ипотека\n";
        std::cout << "Квартира: " << MoneyFormatter::format(apartmentPrice) << "\n";
        std::cout << "Первоначальный взнос: " << MoneyFormatter::format(initialPayment) << "\n";
        std::cout << "Сумма кредита: " << MoneyFormatter::format(mortgagePrincipal) << "\n";
        std::cout << "Ежемесячный платеж: " << MoneyFormatter::format(mortgageMonthlyPayment) << "\n";
        std::cout << "Ставка: " << (mortgageAnnualRate * 100) << "%\n";
        std::cout << "Срок: " << mortgageYears << " лет\n";
        std::cout << "Начальный капитал: " << MoneyFormatter::format(cash) << "\n";
    }
    
    void liveMonth() override {
        // 1. Получаем зарплату
        addIncome(monthlySalary);
        
        // 2. Оплачиваем базовые расходы
        double monthlyExpenses = getTotalMonthlyExpenses();
        addExpense(monthlyExpenses);
        
        // 3. Оплачиваем ипотеку
        if (!mortgagePaid && remainingDebt > 0) {
            // Рассчитываем, сколько из платежа идет на проценты
            double monthlyRate = mortgageAnnualRate / 12;
            double interestPart = remainingDebt * monthlyRate;
            double principalPart = mortgageMonthlyPayment - interestPart;
            
            // Уменьшаем долг
            remainingDebt -= principalPart;
            if (remainingDebt < 0) remainingDebt = 0;
            
            // Учитываем платеж
            addExpense(mortgageMonthlyPayment, true);  // проценты - выброшенные деньги
            totalPaidToBank += mortgageMonthlyPayment;
            totalInterestPaid += interestPart;
            
            if (remainingDebt <= 0) {
                mortgagePaid = true;
                std::cout << "\n🎉 " << name << " полностью погасил ипотеку!\n";
                std::cout << "   Всего выплачено банку: " 
                          << MoneyFormatter::format(totalPaidToBank) << "\n";
                std::cout << "   Из них проценты: " 
                          << MoneyFormatter::format(totalInterestPaid) << "\n";
            }
        }
        
        // 4. Инвестируем остатки
        investSavings();
    }
    
    void printStatus() const override {
        std::cout << "\n┌─────────────────────────────────────────────────\n";
        std::cout << "│  " << name << " | " << currentYear << " г.\n";
        std::cout << "├─────────────────────────────────────────────────\n";
        std::cout << "│  Накопления: " << MoneyFormatter::format(getNetWorth()) << "\n";
        std::cout << "│    - Наличные: " << MoneyFormatter::format(cash) << "\n";
        std::cout << "│    - Инвестиции: " << MoneyFormatter::format(investments.getBalance()) << "\n";
        std::cout << "│ Квартира: " << MoneyFormatter::format(getApartmentCurrentValue()) << "\n";
        std::cout << "│  Ипотека: " << MoneyFormatter::format(mortgageMonthlyPayment) << "/мес\n";
        
        if (mortgagePaid) {
            std::cout << "│  ИПОТЕКА ПОЛНОСТЬЮ ПОГАШЕНА!\n";
        } else {
            std::cout << "│  Остаток долга: " << MoneyFormatter::format(remainingDebt) << "\n";
            double progress = ((mortgagePrincipal - remainingDebt) / mortgagePrincipal) * 100;
            std::cout << "│    Погашено: " << std::fixed << std::setprecision(1) << progress << "%\n";
        }
        
        std::cout << "│  Ежемесячные расходы: " 
                  << MoneyFormatter::format(getTotalMonthlyExpenses() + mortgageMonthlyPayment) << "\n";
        std::cout << "│    - Из них 'на ветер': " 
                  << MoneyFormatter::format(mortgageMonthlyPayment * 0.7) << " (проценты)\n";
        std::cout << "│  Всего выплачено банку: " 
                  << MoneyFormatter::format(totalPaidToBank) << "\n";
        std::cout << "│    Из них проценты: " << MoneyFormatter::format(totalInterestPaid) << "\n";
        std::cout << "└─────────────────────────────────────────────────\n";
    }
    
    double getApartmentCurrentValue() const {
        // Квартира дорожает на 8% в год (инфляция + рост рынка)
        int yearsSincePurchase = currentYear - 2025;
        return apartmentPrice * std::pow(1.08, yearsSincePurchase);
    }
    
    std::string getStrategy() const override { return "Ипотека"; }
    
    double getNetWorth() const override {
        return cash + investments.getBalance() + getApartmentCurrentValue();
    }
    
    double getTotalWastedMoney() const override {
        // У Субо выброшенные деньги - это проценты по ипотеке
        return totalInterestPaid;
    }
};



class Simulation {
private:
    InflationModel inflation;
    Alice alice;
    Subo subo;
    
    int startYear;
    int simulationYears;
    
    // Данные для аналитики
    std::vector<int> years;
    std::vector<double> aliceWealth;
    std::vector<double> suboWealth;
    std::vector<double> aliceWasted;
    std::vector<double> suboWasted;
    std::vector<double> inflationRates;
    
public:
    Simulation(int years = 15, int start = 2025)
        : inflation(0.07, 0.02)
        , alice(&inflation)
        , subo(&inflation)
        , startYear(start)
        , simulationYears(years) {
        
        printHeader();
    }
    
    void run() {
        std::cout << "\n ЗАПУСК СИМУЛЯЦИИ НА " << simulationYears << " ЛЕТ\n";
        std::cout << std::string(80, '═') << "\n";
        
        for (int year = 0; year < simulationYears; ++year) {
            int currentYear = startYear + year;
            
            // Применяем инфляцию и индексацию в начале года
            if (year > 0) {
                alice.applyInflation();
                subo.applyInflation();
                alice.applyRentIndexation();
            }
            
            alice.setYear(currentYear);
            subo.setYear(currentYear);
            
            // Симуляция 12 месяцев
            for (int month = 1; month <= 12; ++month) {
                alice.setMonth(month);
                subo.setMonth(month);
                
                alice.liveMonth();
                subo.liveMonth();
                
                // Применяем доходность инвестиций
                int globalMonth = year * 12 + month;
                alice.applyInvestmentReturns(globalMonth);
                subo.applyInvestmentReturns(globalMonth);
            }
            
            // Записываем годовые данные
            collectYearlyData(currentYear);
            
            // Выводим годовой отчет
            printYearlyReport(currentYear, year + 1);
        }
        
        printFinalReport();
    }
    
private:
    void printHeader() {
        std::cout << "\n" << std::string(80, '█') << "\n";
        std::cout << " ФИНАНСОВЫЙ СИМУЛЯТОР: АРЕНДА vs ИПОТЕКА\n";
        std::cout << std::string(80, '█') << "\n";
        
        std::cout << "\n ПАРАМЕТРЫ СИМУЛЯЦИИ:\n";
        std::cout << "┌───────────────────────────────────────────────────────────\n";
        std::cout << "│ Зарплата:              " << std::setw(30) << "250 000 руб/мес\n";
        std::cout << "│ Инфляция:              " << std::setw(30) << "7% в год (с вариациями)\n";
        std::cout << "│ Доходность инвестиций: " << std::setw(30) << "12% годовых\n";
        std::cout << "│ Стоимость квартиры:    " << std::setw(30) << "14 500 000 руб\n";
        std::cout << "│ Площадь:               " << std::setw(30) << "58 кв.м.\n";
        std::cout << "│ Рост цен на жилье:     " << std::setw(30) << "8% в год\n";
        std::cout << "└────────────────────────────────────────────────────────────┘\n";
        
        std::cout << "\n РАСХОДЫ (оба сценария):\n";
        std::cout << "┌────────────────────────────────────────────────────────────┐\n";
        std::cout << "│ Еда:                   " << std::setw(30) << "25 000 руб/мес\n";
        std::cout << "│ Коммунальные услуги:   " << std::setw(30) << "8 000 руб/мес\n";
        std::cout << "│ Транспорт:             " << std::setw(30) << "5 000 руб/мес\n";
        std::cout << "│ Развлечения:           " << std::setw(30) << "10 000 руб/мес\n";
        std::cout << "│ Прочее:                " << std::setw(30) << "7 000 руб/мес\n";
        std::cout << "│ Питомец (кошка):       " << std::setw(30) << "~6 400 руб/мес\n";
        std::cout << "│ Автомобиль:            " << std::setw(30) << "~27 000 руб/мес\n";
        std::cout << "│ ИТОГО БАЗОВЫХ:         " << std::setw(30) << "~88 400 руб/мес\n";
        std::cout << "└────────────────────────────────────────────────────────────┘\n";
    }
    
    void collectYearlyData(int year) {
        years.push_back(year);
        aliceWealth.push_back(alice.getNetWorth());
        suboWealth.push_back(subo.getNetWorth());
        aliceWasted.push_back(alice.getTotalWastedMoney());
        suboWasted.push_back(subo.getTotalWastedMoney());
        inflationRates.push_back(inflation.getRateForYear(year));
    }
    
    void printYearlyReport(int year, int yearNumber) {
        std::cout << "\n" << std::string(80, '─') << "\n";
        std::cout << " ГОД " << year << " (" << yearNumber << "/" << simulationYears << ")\n";
        std::cout << std::string(80, '─') << "\n";
        
        alice.printStatus();
        subo.printStatus();
        
        // Сравнение
        std::cout << "\n СРАВНЕНИЕ НА КОНЕЦ ГОДА:\n";
        std::cout << std::string(50, '─') << "\n";
        
        double aliceNet = alice.getNetWorth();
        double suboNet = subo.getNetWorth();
        
        std::cout << "├─ Алиса (чистая стоимость): " 
                  << MoneyFormatter::format(aliceNet) << "\n";
        std::cout << "├─ Субо (чистая стоимость):  " 
                  << MoneyFormatter::format(suboNet) << "\n";
        
        if (aliceNet > suboNet) {
            double diff = aliceNet - suboNet;
            double percent = (diff / suboNet) * 100;
            std::cout << "└─ Алиса богаче на " << MoneyFormatter::format(diff) 
                      << " (" << std::fixed << std::setprecision(1) << percent << "%)\n";
        } else if (suboNet > aliceNet) {
            double diff = suboNet - aliceNet;
            double percent = (diff / aliceNet) * 100;
            std::cout << "└─  Субо богаче на " << MoneyFormatter::format(diff) 
                      << " (" << std::fixed << std::setprecision(1) << percent << "%)\n";
        } else {
            std::cout << "└─  Ничья\n";
        }
        
        // Инфляция
        double currentInflation = inflationRates.back();
        std::cout << "└─  Инфляция за год: " << (currentInflation * 100) << "%\n";
    }
    
    void printFinalReport() {
        std::cout << "\n\n" << std::string(80, '▓') << "\n";
        std::cout << " ФИНАЛЬНЫЙ ОТЧЕТ ПОСЛЕ " << simulationYears << " ЛЕТ\n";
        std::cout << std::string(80, '▓') << "\n\n";
        
        // ===== ДЕТАЛЬНЫЙ АНАЛИЗ АЛИСЫ =====
        std::cout << "┌────────────────────────────────────────────────────────────┐\n";
        std::cout << "│  АЛИСА - " << alice.getStrategy() << "\n";
        std::cout << "├────────────────────────────────────────────────────────────┤\n";
        
        double aliceFinalWealth = alice.getNetWorth();
        double aliceFinalCash = alice.getCash();
        double aliceFinalInvestments = alice.getInvestments();
        double aliceTotalIncome = alice.getTotalIncome();
        double aliceTotalExpenses = alice.getTotalExpenses();
        double aliceWasted = alice.getTotalWastedMoney();
        
        std::cout << "│ ИТОГОВАЯ ЧИСТАЯ СТОИМОСТЬ: " 
                  << std::setw(35) << MoneyFormatter::format(aliceFinalWealth) << "\n";
        std::cout << "│   - Наличные: " << std::setw(45) 
                  << MoneyFormatter::format(aliceFinalCash) << "\n";
        std::cout << "│   - Инвестиции: " << std::setw(44) 
                  << MoneyFormatter::format(aliceFinalInvestments) << "\n";
        std::cout << "│\n";
        std::cout << "│ СТАТИСТИКА ЗА " << simulationYears << " ЛЕТ:\n";
        std::cout << "│   Всего заработано: " << std::setw(36) 
                  << MoneyFormatter::format(aliceTotalIncome) << "\n";
        std::cout << "│   Всего потрачено: " << std::setw(37) 
                  << MoneyFormatter::format(aliceTotalExpenses) << "\n";
        std::cout << "│   Деньги 'на ветер' (аренда): " << std::setw(29) 
                  << MoneyFormatter::format(aliceWasted) << "\n";
        std::cout << "│   Эффективность (сохранено/заработано): " << std::setw(22)
                  << std::fixed << std::setprecision(1) 
                  << (aliceFinalWealth / aliceTotalIncome * 100) << "%\n";
        
        // ===== ДЕТАЛЬНЫЙ АНАЛИЗ СУБО =====
        std::cout << "│\n├────────────────────────────────────────────────────────────┤\n";
        std::cout << "│  СУБО - " << subo.getStrategy() << "\n";
        std::cout << "├────────────────────────────────────────────────────────────┤\n";
        
        double suboFinalWealth = subo.getNetWorth();
        double suboFinalCash = subo.getCash();
        double suboFinalInvestments = subo.getInvestments();
        double suboTotalIncome = subo.get