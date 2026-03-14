#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// ============================================================
// СТРУКТУРЫ ДАННЫХ
// ============================================================

struct Car {
	string name;
	int repairCost;
	int repairChance;
	int totalRepairs;
	int totalRepairCost;
	string color;
	int year;
	int mileage;
	float fuelConsumption;
	int insuranceCost;
	int taxCost;
	int serviceCost;
	int washCost;
	int parkingCost;
};

struct Cat {
	string name;
	string breed;
	int age;
	int foodCost;
	int toyCost;
	int vetCost;
	int totalFood;
	int totalToys;
	int totalVet;
	int totalCost;
	int trayCost;
	int vitaminsCost;
	int beddingCost;
	int bowlCost;
};

struct Invest {
	string name;
	int dailyIncome;
	int totalIncome;
	int totalDays;
	int riskLevel;
	int minDeposit;
	int commission;
	float profitPercent;
};

struct OzonBusiness {
	string productName;
	int buyPrice;
	int sellPrice;
	int monthlySales;
	int totalSales;
	int totalRevenue;
	int totalProfit;
	int advertisingCost;
	int deliveryCost;
	int storageCost;
	int commission;
	int returns;
};

struct Phone {
	string model;
	int price;
	int buyMonth;
	int buyYear;
	bool isBought;
	int memory;
	string processor;
	double screenSize;
	int battery;
	string color;
	int camera;
};

struct Food {
	string name;
	int price;
	int count;
	string category;
};

// ============================================================
// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
// ============================================================

// Деньги
int moneyOnCard = 200000;
int salary = 58000;
int totalMoney = 200000;
int startMoney = 200000;
float bankPercent = 19.0;

// ============================================================
// БИЗНЕС 1 - БЕСПРОВОДНЫЕ НАУШНИКИ
// ============================================================

string productName1 = "Беспроводные наушники";
int buyPrice1 = 680;
int sellPrice1 = 1990;
int monthlySales1 = 48;
int totalSales1 = 0;
int totalRevenue1 = 0;
int totalProfit1 = 0;
int advertisingCost1 = 8500;
int deliveryCost1 = 380;
int storageCost1 = 2200;
int commissionPercent1 = 16;
int returnsPerMonth1 = 3;

// ============================================================
// БИЗНЕС 2 - УМНЫЕ ЧАСЫ
// ============================================================

string productName2 = "Умные часы";
int buyPrice2 = 1350;
int sellPrice2 = 3890;
int monthlySales2 = 28;
int totalSales2 = 0;
int totalRevenue2 = 0;
int totalProfit2 = 0;
int advertisingCost2 = 7000;
int deliveryCost2 = 380;
int storageCost2 = 1800;
int commissionPercent2 = 16;
int returnsPerMonth2 = 2;

// ============================================================
// БИЗНЕС 3 - ВНЕШНИЙ АККУМУЛЯТОР
// ============================================================

string productName3 = "Внешний аккумулятор";
int buyPrice3 = 950;
int sellPrice3 = 2590;
int monthlySales3 = 38;
int totalSales3 = 0;
int totalRevenue3 = 0;
int totalProfit3 = 0;
int advertisingCost3 = 7500;
int deliveryCost3 = 380;
int storageCost3 = 2000;
int commissionPercent3 = 16;
int returnsPerMonth3 = 2;

// ============================================================
// БИЗНЕС 4 - ФИТНЕС-БРАСЛЕТ
// ============================================================

string productName4 = "Фитнес-браслет";
int buyPrice4 = 850;
int sellPrice4 = 2290;
int monthlySales4 = 42;
int totalSales4 = 0;
int totalRevenue4 = 0;
int totalProfit4 = 0;
int advertisingCost4 = 6500;
int deliveryCost4 = 380;
int storageCost4 = 1900;
int commissionPercent4 = 16;
int returnsPerMonth4 = 2;

// ============================================================
// БИЗНЕС 5 - ПОРТАТИВНАЯ КОЛОНКА
// ============================================================

string productName5 = "Портативная колонка";
int buyPrice5 = 1450;
int sellPrice5 = 3990;
int monthlySales5 = 22;
int totalSales5 = 0;
int totalRevenue5 = 0;
int totalProfit5 = 0;
int advertisingCost5 = 8000;
int deliveryCost5 = 380;
int storageCost5 = 1600;
int commissionPercent5 = 16;
int returnsPerMonth5 = 1;

// ============================================================
// МАШИНА ЛАДА ВЕСТА СПОРТЛАЙН
// ============================================================

string carName = "Лада Веста Спортлайн";
int carRepairCost = 5500;
int carRepairChance = 24;
int carTotalRepairs = 0;
int carTotalRepairCost = 0;
string carColor = "Черный";
int carYear = 2024;
int carMileage = 15000;
float carFuelConsumption = 8.5;
int carInsuranceCost = 26000;
int carTaxCost = 6800;
int carServiceCost = 4200;
int carWashCost = 1600;
int carParkingCost = 2700;

// ============================================================
// КОТ ФЕЛИКС
// ============================================================

string catName = "Феликс";
string catBreed = "Британский";
int catAge = 5;
int catFoodCost = 3600;
int catToyCost = 1600;
int catVetCost = 1300;
int catTotalFood = 0;
int catTotalToys = 0;
int catTotalVet = 0;
int catTotalCost = 0;
int catTrayCost = 1100;
int catVitaminsCost = 850;
int catBeddingCost = 950;
int catBowlCost = 650;

// ============================================================
// ИНВЕСТИЦИИ
// ============================================================

string investName = "Сбер Инвестиции";
int investDailyIncome = 220;
int investTotalIncome = 0;
int investTotalDays = 0;
int investRiskLevel = 3;
int investMinDeposit = 25000;
int investCommission = 180;
float investProfitPercent = 19.0;

// ============================================================
// ТЕЛЕФОН
// ============================================================

string phoneModel = "";
int phonePrice = 0;
int phoneBuyMonth = 3;
int phoneBuyYear = 2026;
bool phoneIsBought = false;
int phoneMemory = 256;
string phoneProcessor = "Snapdragon 7 Gen 3";
double phoneScreenSize = 6.6;
int phoneBattery = 5000;
string phoneColor = "Графитовый";
int phoneCamera = 108;

// ============================================================
// МАКДОНАЛЬДС
// ============================================================

string mcFoodName = "БигМак Комбо";
int mcFoodPrice = 580;
int mcBuyChance = 24;
int mcTotalPurchases = 0;
int mcTotalMoney = 0;

// ============================================================
// ШАВЕРМА
// ============================================================

int shawarmaPrice = 260;
int shawarmaPerWeek = 1;
int shawarmaTotalExpenses = 0;

// ============================================================
// ЧУПА-ЧУПС
// ============================================================

int chupaPrice = 52;
int chupaPerWeek = 2;
int chupaTotalExpenses = 0;

// ============================================================
// ПРОЕЗДНОЙ
// ============================================================

int travelCardPrice = 3100;
int travelCardTotal = 0;

// ============================================================
// КРОССОВКИ
// ============================================================

int sneakersPrice = 7200;
bool sneakersAreBought = false;

// ============================================================
// КОММУНАЛЬНЫЕ ПЛАТЕЖИ
// ============================================================

int electricityBill = 4200;
int waterBill = 2900;
int gasBill = 2100;
int internetBill = 1350;
int trashBill = 550;
int intercomBill = 220;
int heatingBill = 3600;
int renovationBill = 1050;
int totalCommunalPayments = 0;

// ============================================================
// ОНЛАЙН ПОКУПКИ
// ============================================================

int ozonSpending = 4200;
int wildberriesSpending = 3600;
int marketSpending = 2600;
int aliexpressSpending = 3100;
int totalOnlineSpending = 0;

// ============================================================
// КАФЕ
// ============================================================

int cafeVisitsCount = 0;
int cafeAverageBill = 1550;
int cafeTotalSpending = 0;
int deliveryTimesCount = 0;
int deliveryAverageBill = 1050;
int deliveryTotalSpending = 0;

// ============================================================
// КИНО
// ============================================================

int cinemaTicketPrice = 620;
int cinemaVisitsPerMonth = 1;
int cinemaTotalSpending = 0;

// ============================================================
// СПОРТ
// ============================================================

int gymMonthlyPrice = 3600;
int gymTotalSpending = 0;

// ============================================================
// ТАКСИ
// ============================================================

int taxiTripsCount = 0;
int taxiAveragePrice = 520;
int taxiTotalSpending = 0;

// ============================================================
// АПТЕКА
// ============================================================

int medicineMonthly = 2100;
int medicineTotal = 0;
int vitaminsMonthly = 1250;
int vitaminsTotal = 0;

// ============================================================
// КОФЕ С СОБОЙ
// ============================================================

int coffeePrice = 290;
int coffeePerWeek = 3;
int coffeeTotalSpending = 0;

// ============================================================
// ПИВО
// ============================================================

int beerPrice = 210;
int beerPerWeek = 2;
int beerTotalSpending = 0;
int chipsPrice = 160;
int chipsPerWeek = 1;
int chipsTotalSpending = 0;

// ============================================================
// ДЕНЬ РОЖДЕНИЯ
// ============================================================

int birthdayGiftsAmount = 6500;
int birthdayMonthNumber = 4;
bool birthdayHasHappened = false;
int birthdayCakePrice = 2200;
int birthdayRestaurantPrice = 5500;
int birthdayTotalSpending = 0;

// ============================================================
// НАЛОГИ
// ============================================================

int monthlyTax = 3700;
int monthlyTaxTotal = 0;
int transportTax = 6800;

// ============================================================
// ОДЕЖДА
// ============================================================

int clothesMonthly = 4700;
int clothesTotal = 0;
int shoesMonthly = 3200;
int shoesTotal = 0;

// ============================================================
// КНИГИ
// ============================================================

int booksMonthly = 1600;
int booksTotalSpending = 0;

// ============================================================
// ХОББИ
// ============================================================

int hobbyMonthly = 2700;
int hobbyTotalSpending = 0;

// ============================================================
// ПОДАРКИ
// ============================================================

int giftsMonthly = 2200;
int giftsTotalSpending = 0;

// ============================================================
// БЕНЗИН
// ============================================================

int gasolineMonthly = 6200;
int gasolineTotalSpending = 0;
int carWashMonthly = 1300;
int carWashTotalSpending = 0;
int tireFittingCost = 4200;
int tireStorageCost = 3200;

// ============================================================
// ЗДОРОВЬЕ
// ============================================================

int dentistVisitCost = 4500;
int massageMonthly = 2200;
int massageTotalSpending = 0;

// ============================================================
// ОБРАЗОВАНИЕ
// ============================================================

int englishMonthly = 2700;
int englishTotalSpending = 0;

// ============================================================
// ПУТЕШЕСТВИЯ
// ============================================================

int vacationYearlyCost = 65000;
int vacationMonthNumber = 7;
bool vacationHasHappened = false;
int weekendTripsCost = 13000;
int weekendTripsTotal = 0;

// ============================================================
// ПРОДУКТЫ
// ============================================================

// Хлеб
string breadName = "Хлеб";
int breadPrice = 58;
int breadCount = 0;

// Молоко
string milkName = "Молоко";
int milkPrice = 98;
int milkCount = 0;

// Яйца
string eggsName = "Яйца";
int eggsPrice = 135;
int eggsCount = 0;

// Сыр
string cheeseName = "Сыр";
int cheesePrice = 420;
int cheeseCount = 0;

// Курица
string chickenName = "Курица";
int chickenPrice = 470;
int chickenCount = 0;

// Мясо
string meatName = "Говядина";
int meatPrice = 620;
int meatCount = 0;

// Рыба
string fishName = "Рыба";
int fishPrice = 530;
int fishCount = 0;

// Яблоки
string applesName = "Яблоки";
int applesPrice = 150;
int applesCount = 0;

// Бананы
string bananasName = "Бананы";
int bananasPrice = 125;
int bananasCount = 0;

// Картофель
string potatoesName = "Картофель";
int potatoesPrice = 48;
int potatoesCount = 0;

// Помидоры
string tomatoesName = "Помидоры";
int tomatoesPrice = 250;
int tomatoesCount = 0;

// Огурцы
string cucumbersName = "Огурцы";
int cucumbersPrice = 140;
int cucumbersCount = 0;

// Лук
string onionName = "Лук";
int onionPrice = 42;
int onionCount = 0;

// Чеснок
string garlicName = "Чеснок";
int garlicPrice = 260;
int garlicCount = 0;

// Макароны
string pastaName = "Макароны";
int pastaPrice = 85;
int pastaCount = 0;

// Рис
string riceName = "Рис";
int ricePrice = 120;
int riceCount = 0;

// Гречка
string buckwheatName = "Гречка";
int buckwheatPrice = 130;
int buckwheatCount = 0;

// Масло
string oilName = "Масло";
int oilPrice = 200;
int oilCount = 0;

// Йогурт
string yogurtName = "Йогурт";
int yogurtPrice = 75;
int yogurtCount = 0;

// Шоколад
string chocolateName = "Шоколад";
int chocolatePrice = 150;
int chocolateCount = 0;

// Чай
string teaName = "Чай";
int teaPrice = 280;
int teaCount = 0;

// Кофе
string coffeeName = "Кофе";
int coffeePriceGrocery = 600;
int coffeeCount = 0;

// Вода
string waterName = "Вода";
int waterPrice = 40;
int waterCount = 0;

// Сок
string juiceName = "Сок";
int juicePrice = 160;
int juiceCount = 0;

// Мороженое
string icecreamName = "Мороженое";
int icecreamPrice = 100;
int icecreamCount = 0;

// Общие расходы на продукты
int totalFoodSpending = 0;

// ============================================================
// НАЗВАНИЯ МЕСЯЦЕВ
// ============================================================

string january = "Январь";
string february = "Февраль";
string march = "Март";
string april = "Апрель";
string may = "Май";
string june = "Июнь";
string july = "Июль";
string august = "Август";
string september = "Сентябрь";
string october = "Октябрь";
string november = "Ноябрь";
string december = "Декабрь";

string monthNamesArray[12] = {
	january, february, march, april, may, june,
	july, august, september, october, november, december
};
// ============================================================
// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
// ============================================================

string getMonthName(int monthNumber) {
	if (monthNumber == 1) {
		return january;
	}
	else if (monthNumber == 2) {
		return february;
	}
	else if (monthNumber == 3) {
		return march;
	}
	else if (monthNumber == 4) {
		return april;
	}
	else if (monthNumber == 5) {
		return may;
	}
	else if (monthNumber == 6) {
		return june;
	}
	else if (monthNumber == 7) {
		return july;
	}
	else if (monthNumber == 8) {
		return august;
	}
	else if (monthNumber == 9) {
		return september;
	}
	else if (monthNumber == 10) {
		return october;
	}
	else if (monthNumber == 11) {
		return november;
	}
	else if (monthNumber == 12) {
		return december;
	}
	else {
		return "Неизвестный месяц";
	}
}

int getDaysInMonth(int month, int year) {
	if (month == 2) {
		if (year % 4 == 0) {
			if (year % 100 == 0) {
				if (year % 400 == 0) {
					return 29;
				}
				else {
					return 28;
				}
			}
			else {
				return 29;
			}
		}
		else {
			return 28;
		}
	}
	else if (month == 4) {
		return 30;
	}
	else if (month == 6) {
		return 30;
	}
	else if (month == 9) {
		return 30;
	}
	else if (month == 11) {
		return 30;
	}
	else {
		return 31;
	}
}

int getRandomNumber() {
	int randomNumber = rand() % 100;
	randomNumber = randomNumber + 1;
	return randomNumber;
}

int getRandomInRange(int minimum, int maximum) {
	int range = maximum - minimum + 1;
	int randomNumber = rand() % range;
	randomNumber = randomNumber + minimum;
	return randomNumber;
}
// ============================================================
// БИЗНЕС 1 - БЕСПРОВОДНЫЕ НАУШНИКИ
// ============================================================

void processBusiness1(int currentMonth) {
	int salesThisMonth = monthlySales1;
	
	if (currentMonth == 11) {
		salesThisMonth = salesThisMonth * 1.8;
	}
	else if (currentMonth == 12) {
		salesThisMonth = salesThisMonth * 2.0;
	}
	else if (currentMonth == 1) {
		salesThisMonth = salesThisMonth * 0.6;
	}
	else if (currentMonth == 2) {
		salesThisMonth = salesThisMonth * 0.8;
	}
	else if (currentMonth == 3) {
		salesThisMonth = salesThisMonth * 0.9;
	}
	else if (currentMonth == 5) {
		salesThisMonth = salesThisMonth * 1.1;
	}
	else if (currentMonth == 6) {
		salesThisMonth = salesThisMonth * 1.1;
	}
	else if (currentMonth == 9) {
		salesThisMonth = salesThisMonth * 1.2;
	}
	
	int randomFactor = getRandomInRange(80, 120);
	salesThisMonth = salesThisMonth * randomFactor;
	salesThisMonth = salesThisMonth / 100;
	
	int returnsThisMonth = returnsPerMonth1;
	if (currentMonth == 1) {
		returnsThisMonth = returnsThisMonth * 2;
	}
	
	int realSales = salesThisMonth - returnsThisMonth;
	if (realSales < 0) {
		realSales = 0;
	}
	
	int revenue = realSales * sellPrice1;
	int commissionAmount = revenue * commissionPercent1;
	commissionAmount = commissionAmount / 100;
	
	int totalCosts = 0;
	totalCosts = totalCosts + (realSales * buyPrice1);
	totalCosts = totalCosts + (realSales * deliveryCost1);
	totalCosts = totalCosts + commissionAmount;
	totalCosts = totalCosts + advertisingCost1;
	totalCosts = totalCosts + storageCost1;
	
	int profit = revenue - totalCosts;
	
	totalSales1 = totalSales1 + realSales;
	totalRevenue1 = totalRevenue1 + revenue;
	totalProfit1 = totalProfit1 + profit;
	
	moneyOnCard = moneyOnCard + profit;
	
	cout << "  БИЗНЕС 1: " << productName1 << endl;
	cout << "    Продано товаров: " << realSales << " штук" << endl;
	cout << "    Возвратов: " << returnsThisMonth << " штук" << endl;
	cout << "    Выручка: +" << revenue << " рублей" << endl;
	cout << "    Расходы: -" << totalCosts << " рублей" << endl;
	cout << "    ПРИБЫЛЬ: +" << profit << " рублей" << endl;
}

// ============================================================
// БИЗНЕС 2 - УМНЫЕ ЧАСЫ
// ============================================================

void processBusiness2(int currentMonth) {
	int salesThisMonth = monthlySales2;
	
	if (currentMonth == 11) {
		salesThisMonth = salesThisMonth * 1.8;
	}
	else if (currentMonth == 12) {
		salesThisMonth = salesThisMonth * 2.0;
	}
	else if (currentMonth == 1) {
		salesThisMonth = salesThisMonth * 0.6;
	}
	else if (currentMonth == 2) {
		salesThisMonth = salesThisMonth * 0.8;
	}
	else if (currentMonth == 3) {
		salesThisMonth = salesThisMonth * 0.9;
	}
	else if (currentMonth == 5) {
		salesThisMonth = salesThisMonth * 1.1;
	}
	else if (currentMonth == 6) {
		salesThisMonth = salesThisMonth * 1.1;
	}
	else if (currentMonth == 9) {
		salesThisMonth = salesThisMonth * 1.2;
	}
	
	int randomFactor = getRandomInRange(80, 120);
	salesThisMonth = salesThisMonth * randomFactor;
	salesThisMonth = salesThisMonth / 100;
	
	int returnsThisMonth = returnsPerMonth2;
	if (currentMonth == 1) {
		returnsThisMonth = returnsThisMonth * 2;
	}
	
	int realSales = salesThisMonth - returnsThisMonth;
	if (realSales < 0) {
		realSales = 0;
	}
	
	int revenue = realSales * sellPrice2;
	int commissionAmount = revenue * commissionPercent2;
	commissionAmount = commissionAmount / 100;
	
	int totalCosts = 0;
	totalCosts = totalCosts + (realSales * buyPrice2);
	totalCosts = totalCosts + (realSales * deliveryCost2);
	totalCosts = totalCosts + commissionAmount;
	totalCosts = totalCosts + advertisingCost2;
	totalCosts = totalCosts + storageCost2;
	
	int profit = revenue - totalCosts;
	
	totalSales2 = totalSales2 + realSales;
	totalRevenue2 = totalRevenue2 + revenue;
	totalProfit2 = totalProfit2 + profit;
	
	moneyOnCard = moneyOnCard + profit;
	
	cout << "  БИЗНЕС 2: " << productName2 << endl;
	cout << "    Продано товаров: " << realSales << " штук" << endl;
	cout << "    Возвратов: " << returnsThisMonth << " штук" << endl;
	cout << "    Выручка: +" << revenue << " рублей" << endl;
	cout << "    Расходы: -" << totalCosts << " рублей" << endl;
	cout << "    ПРИБЫЛЬ: +" << profit << " рублей" << endl;
}

// ============================================================
// БИЗНЕС 3 - ВНЕШНИЙ АККУМУЛЯТОР
// ============================================================

void processBusiness3(int currentMonth) {
	int salesThisMonth = monthlySales3;
	
	if (currentMonth == 11) {
		salesThisMonth = salesThisMonth * 1.8;
	}
	else if (currentMonth == 12) {
		salesThisMonth = salesThisMonth * 2.0;
	}
	else if (currentMonth == 1) {
		salesThisMonth = salesThisMonth * 0.6;
	}
	else if (currentMonth == 2) {
		salesThisMonth = salesThisMonth * 0.8;
	}
	else if (currentMonth == 3) {
		salesThisMonth = salesThisMonth * 0.9;
	}
	else if (currentMonth == 5) {
		salesThisMonth = salesThisMonth * 1.1;
	}
	else if (currentMonth == 6) {
		salesThisMonth = salesThisMonth * 1.1;
	}
	else if (currentMonth == 9) {
		salesThisMonth = salesThisMonth * 1.2;
	}
	
	int randomFactor = getRandomInRange(80, 120);
	salesThisMonth = salesThisMonth * randomFactor;
	salesThisMonth = salesThisMonth / 100;
	
	int returnsThisMonth = returnsPerMonth3;
	if (currentMonth == 1) {
		returnsThisMonth = returnsThisMonth * 2;
	}
	
	int realSales = salesThisMonth - returnsThisMonth;
	if (realSales < 0) {
		realSales = 0;
	}
	
	int revenue = realSales * sellPrice3;
	int commissionAmount = revenue * commissionPercent3;
	commissionAmount = commissionAmount / 100;
	
	int totalCosts = 0;
	totalCosts = totalCosts + (realSales * buyPrice3);
	totalCosts = totalCosts + (realSales * deliveryCost3);
	totalCosts = totalCosts + commissionAmount;
	totalCosts = totalCosts + advertisingCost3;
	totalCosts = totalCosts + storageCost3;
	
	int profit = revenue - totalCosts;
	
	totalSales3 = totalSales3 + realSales;
	totalRevenue3 = totalRevenue3 + revenue;
	totalProfit3 = totalProfit3 + profit;
	
	moneyOnCard = moneyOnCard + profit;
	
	cout << "  БИЗНЕС 3: " << productName3 << endl;
	cout << "    Продано товаров: " << realSales << " штук" << endl;
	cout << "    Возвратов: " << returnsThisMonth << " штук" << endl;
	cout << "    Выручка: +" << revenue << " рублей" << endl;
	cout << "    Расходы: -" << totalCosts << " рублей" << endl;
	cout << "    ПРИБЫЛЬ: +" << profit << " рублей" << endl;
}

// ============================================================
// БИЗНЕС 4 - ФИТНЕС-БРАСЛЕТ
// ============================================================

void processBusiness4(int currentMonth) {
	int salesThisMonth = monthlySales4;
	
	if (currentMonth == 11) {
		salesThisMonth = salesThisMonth * 1.8;
	}
	else if (currentMonth == 12) {
		salesThisMonth = salesThisMonth * 2.0;
	}
	else if (currentMonth == 1) {
		salesThisMonth = salesThisMonth * 0.6;
	}
	else if (currentMonth == 2) {
		salesThisMonth = salesThisMonth * 0.8;
	}
	else if (currentMonth == 3) {
		salesThisMonth = salesThisMonth * 0.9;
	}
	else if (currentMonth == 5) {
		salesThisMonth = salesThisMonth * 1.1;
	}
	else if (currentMonth == 6) {
		salesThisMonth = salesThisMonth * 1.1;
	}
	else if (currentMonth == 9) {
		salesThisMonth = salesThisMonth * 1.2;
	}
	
	int randomFactor = getRandomInRange(80, 120);
	salesThisMonth = salesThisMonth * randomFactor;
	salesThisMonth = salesThisMonth / 100;
	
	int returnsThisMonth = returnsPerMonth4;
	if (currentMonth == 1) {
		returnsThisMonth = returnsThisMonth * 2;
	}
	
	int realSales = salesThisMonth - returnsThisMonth;
	if (realSales < 0) {
		realSales = 0;
	}
	
	int revenue = realSales * sellPrice4;
	int commissionAmount = revenue * commissionPercent4;
	commissionAmount = commissionAmount / 100;
	
	int totalCosts = 0;
	totalCosts = totalCosts + (realSales * buyPrice4);
	totalCosts = totalCosts + (realSales * deliveryCost4);
	totalCosts = totalCosts + commissionAmount;
	totalCosts = totalCosts + advertisingCost4;
	totalCosts = totalCosts + storageCost4;
	
	int profit = revenue - totalCosts;
	
	totalSales4 = totalSales4 + realSales;
	totalRevenue4 = totalRevenue4 + revenue;
	totalProfit4 = totalProfit4 + profit;
	
	moneyOnCard = moneyOnCard + profit;
	
	cout << "  БИЗНЕС 4: " << productName4 << endl;
	cout << "    Продано товаров: " << realSales << " штук" << endl;
	cout << "    Возвратов: " << returnsThisMonth << " штук" << endl;
	cout << "    Выручка: +" << revenue << " рублей" << endl;
	cout << "    Расходы: -" << totalCosts << " рублей" << endl;
	cout << "    ПРИБЫЛЬ: +" << profit << " рублей" << endl;
}

// ============================================================
// БИЗНЕС 5 - ПОРТАТИВНАЯ КОЛОНКА
// ============================================================

void processBusiness5(int currentMonth) {
	int salesThisMonth = monthlySales5;
	
	if (currentMonth == 11) {
		salesThisMonth = salesThisMonth * 1.8;
	}
	else if (currentMonth == 12) {
		salesThisMonth = salesThisMonth * 2.0;
	}
	else if (currentMonth == 1) {
		salesThisMonth = salesThisMonth * 0.6;
	}
	else if (currentMonth == 2) {
		salesThisMonth = salesThisMonth * 0.8;
	}
	else if (currentMonth == 3) {
		salesThisMonth = salesThisMonth * 0.9;
	}
	else if (currentMonth == 5) {
		salesThisMonth = salesThisMonth * 1.1;
	}
	else if (currentMonth == 6) {
		salesThisMonth = salesThisMonth * 1.1;
	}
	else if (currentMonth == 9) {
		salesThisMonth = salesThisMonth * 1.2;
	}
	
	int randomFactor = getRandomInRange(80, 120);
	salesThisMonth = salesThisMonth * randomFactor;
	salesThisMonth = salesThisMonth / 100;
	
	int returnsThisMonth = returnsPerMonth5;
	if (currentMonth == 1) {
		returnsThisMonth = returnsThisMonth * 2;
	}
	
	int realSales = salesThisMonth - returnsThisMonth;
	if (realSales < 0) {
		realSales = 0;
	}
	
	int revenue = realSales * sellPrice5;
	int commissionAmount = revenue * commissionPercent5;
	commissionAmount = commissionAmount / 100;
	
	int totalCosts = 0;
	totalCosts = totalCosts + (realSales * buyPrice5);
	totalCosts = totalCosts + (realSales * deliveryCost5);
	totalCosts = totalCosts + commissionAmount;
	totalCosts = totalCosts + advertisingCost5;
	totalCosts = totalCosts + storageCost5;
	
	int profit = revenue - totalCosts;
	
	totalSales5 = totalSales5 + realSales;
	totalRevenue5 = totalRevenue5 + revenue;
	totalProfit5 = totalProfit5 + profit;
	
	moneyOnCard = moneyOnCard + profit;
	
	cout << "  БИЗНЕС 5: " << productName5 << endl;
	cout << "    Продано товаров: " << realSales << " штук" << endl;
	cout << "    Возвратов: " << returnsThisMonth << " штук" << endl;
	cout << "    Выручка: +" << revenue << " рублей" << endl;
	cout << "    Расходы: -" << totalCosts << " рублей" << endl;
	cout << "    ПРИБЫЛЬ: +" << profit << " рублей" << endl;
}
// ============================================================
// ФУНКЦИИ ДОХОДОВ
// ============================================================

void calculateBankPercent(int currentMonth, int currentYear) {
	int daysInCurrentMonth = getDaysInMonth(currentMonth, currentYear);
	float monthlyPercent = bankPercent / 12.0;
	monthlyPercent = monthlyPercent / 100.0;
	
	int interestAmount = moneyOnCard * monthlyPercent;
	
	moneyOnCard = moneyOnCard + interestAmount;
	totalMoney = totalMoney + interestAmount;
	
	cout << "  Банковские проценты:" << endl;
	cout << "    Начислено: +" << interestAmount << " рублей" << endl;
	cout << "    Ставка: " << bankPercent << "% годовых" << endl;
}

void receiveSalary() {
	moneyOnCard = moneyOnCard + salary;
	totalMoney = totalMoney + salary;
	
	cout << "  Зарплата:" << endl;
	cout << "    Получено: +" << salary << " рублей" << endl;
	
	int randomChance = getRandomNumber();
	if (randomChance <= 20) {
		int bonusAmount = salary * 30;
		bonusAmount = bonusAmount / 100;
		
		moneyOnCard = moneyOnCard + bonusAmount;
		totalMoney = totalMoney + bonusAmount;
		
		cout << "    Премия: +" << bonusAmount << " рублей" << endl;
	}
}

void calculateInvestIncome(int currentMonth, int currentYear) {
	int daysInCurrentMonth = getDaysInMonth(currentMonth, currentYear);
	int incomeAmount = investDailyIncome * daysInCurrentMonth;
	
	moneyOnCard = moneyOnCard + incomeAmount;
	investTotalIncome = investTotalIncome + incomeAmount;
	investTotalDays = investTotalDays + daysInCurrentMonth;
	
	cout << "  Инвестиционный доход:" << endl;
	cout << "    Получено: +" << incomeAmount << " рублей" << endl;
	cout << "    Доход в день: " << investDailyIncome << " рублей" << endl;
	cout << "    Дней в месяце: " << daysInCurrentMonth << endl;
}
// ============================================================
// ФУНКЦИИ РАСХОДОВ - ЧАСТЬ 1
// ============================================================

void spendOnCat() {
	moneyOnCard = moneyOnCard - catFoodCost;
	moneyOnCard = moneyOnCard - catToyCost;
	moneyOnCard = moneyOnCard - catVetCost;
	moneyOnCard = moneyOnCard - catTrayCost;
	moneyOnCard = moneyOnCard - catVitaminsCost;
	moneyOnCard = moneyOnCard - catBeddingCost;
	moneyOnCard = moneyOnCard - catBowlCost;
	
	catTotalFood = catTotalFood + catFoodCost;
	catTotalToys = catTotalToys + catToyCost;
	catTotalVet = catTotalVet + catVetCost;
	
	catTotalCost = 0;
	catTotalCost = catTotalCost + catTotalFood;
	catTotalCost = catTotalCost + catTotalToys;
	catTotalCost = catTotalCost + catTotalVet;
	catTotalCost = catTotalCost + (catTrayCost * 12);
	catTotalCost = catTotalCost + (catVitaminsCost * 12);
	catTotalCost = catTotalCost + (catBeddingCost * 2);
	catTotalCost = catTotalCost + catBowlCost;
	
	cout << "  Кот " << catName << ":" << endl;
	cout << "    Корм: -" << catFoodCost << " рублей" << endl;
	cout << "    Игрушки: -" << catToyCost << " рублей" << endl;
	cout << "    Ветеринар: -" << catVetCost << " рублей" << endl;
	cout << "    Наполнитель: -" << catTrayCost << " рублей" << endl;
	cout << "    Витамины: -" << catVitaminsCost << " рублей" << endl;
	cout << "    Лежанка: -" << catBeddingCost << " рублей" << endl;
	cout << "    Миски: -" << catBowlCost << " рублей" << endl;
}

void spendOnCar(int currentMonth, int currentYear) {
	int randomNumber = getRandomNumber();
	
	moneyOnCard = moneyOnCard - gasolineMonthly;
	gasolineTotalSpending = gasolineTotalSpending + gasolineMonthly;
	cout << "  Бензин: -" << gasolineMonthly << " рублей" << endl;
	
	if (currentMonth == 3) {
		moneyOnCard = moneyOnCard - carWashMonthly;
		carWashTotalSpending = carWashTotalSpending + carWashMonthly;
		cout << "  Мойка машины: -" << carWashMonthly << " рублей" << endl;
	}
	else if (currentMonth == 6) {
		moneyOnCard = moneyOnCard - carWashMonthly;
		carWashTotalSpending = carWashTotalSpending + carWashMonthly;
		cout << "  Мойка машины: -" << carWashMonthly << " рублей" << endl;
	}
	else if (currentMonth == 9) {
		moneyOnCard = moneyOnCard - carWashMonthly;
		carWashTotalSpending = carWashTotalSpending + carWashMonthly;
		cout << "  Мойка машины: -" << carWashMonthly << " рублей" << endl;
	}
	
	moneyOnCard = moneyOnCard - carParkingCost;
	cout << "  Парковка: -" << carParkingCost << " рублей" << endl;
	
	if (randomNumber <= carRepairChance) {
		moneyOnCard = moneyOnCard - carRepairCost;
		carTotalRepairs = carTotalRepairs + 1;
		carTotalRepairCost = carTotalRepairCost + carRepairCost;
		
		cout << "  Ремонт автомобиля " << carName << ":" << endl;
		cout << "    Стоимость: -" << carRepairCost << " рублей" << endl;
		cout << "    Это ремонт номер: " << carTotalRepairs << endl;
	}
	
	if (currentMonth == 3) {
		moneyOnCard = moneyOnCard - carServiceCost;
		cout << "  Техническое обслуживание: -" << carServiceCost << " рублей" << endl;
	}
	else if (currentMonth == 9) {
		moneyOnCard = moneyOnCard - carServiceCost;
		cout << "  Техническое обслуживание: -" << carServiceCost << " рублей" << endl;
	}
	
	if (currentMonth == 4) {
		moneyOnCard = moneyOnCard - tireFittingCost;
		cout << "  Шиномонтаж (летняя резина): -" << tireFittingCost << " рублей" << endl;
	}
	else if (currentMonth == 10) {
		moneyOnCard = moneyOnCard - tireFittingCost;
		cout << "  Шиномонтаж (зимняя резина): -" << tireFittingCost << " рублей" << endl;
	}
	
	if (currentMonth == 4 && currentYear == 2026) {
		moneyOnCard = moneyOnCard - tireStorageCost;
		cout << "  Хранение шин: -" << tireStorageCost << " рублей" << endl;
	}
}
// ============================================================
// ФУНКЦИИ РАСХОДОВ - ЧАСТЬ 2
// ============================================================

void spendOnMcDonalds() {
	int weeksInMonth = 4;
	int purchasesThisMonth = 0;
	
	for (int week = 1; week <= weeksInMonth; week++) {
		int randomChance = getRandomNumber();
		if (randomChance <= mcBuyChance) {
			purchasesThisMonth = purchasesThisMonth + 1;
		}
	}
	
	int totalCost = purchasesThisMonth * mcFoodPrice;
	moneyOnCard = moneyOnCard - totalCost;
	
	mcTotalPurchases = mcTotalPurchases + purchasesThisMonth;
	mcTotalMoney = mcTotalMoney + totalCost;
	
	if (purchasesThisMonth > 0) {
		cout << "  Макдональдс:" << endl;
		cout << "    Куплено раз: " << purchasesThisMonth << endl;
		cout << "    Потрачено: -" << totalCost << " рублей" << endl;
	}
}

void spendOnShawarma() {
	int weeksInMonth = 4;
	int monthlyCost = shawarmaPrice * shawarmaPerWeek * weeksInMonth;
	
	moneyOnCard = moneyOnCard - monthlyCost;
	shawarmaTotalExpenses = shawarmaTotalExpenses + monthlyCost;
	
	cout << "  Шаверма:" << endl;
	cout << "    Потрачено: -" << monthlyCost << " рублей" << endl;
	cout << "    Раз в неделю: " << shawarmaPerWeek << endl;
}

void spendOnChupaChups() {
	int weeksInMonth = 4;
	int monthlyCost = chupaPrice * chupaPerWeek * weeksInMonth;
	
	moneyOnCard = moneyOnCard - monthlyCost;
	chupaTotalExpenses = chupaTotalExpenses + monthlyCost;
	
	cout << "  Чупа-чупс:" << endl;
	cout << "    Потрачено: -" << monthlyCost << " рублей" << endl;
}

void spendOnTravelCard() {
	moneyOnCard = moneyOnCard - travelCardPrice;
	travelCardTotal = travelCardTotal + travelCardPrice;
	
	cout << "  Проездной билет:" << endl;
	cout << "    Стоимость: -" << travelCardPrice << " рублей" << endl;
}

void spendOnSneakers(int currentMonth) {
	if (currentMonth == 3) {
		if (sneakersAreBought == false) {
			moneyOnCard = moneyOnCard - sneakersPrice;
			sneakersAreBought = true;
			
			cout << "  Кроссовки:" << endl;
			cout << "    Стоимость: -" << sneakersPrice << " рублей" << endl;
		}
	}
}

void spendOnCommunal() {
	int totalBills = 0;
	totalBills = totalBills + electricityBill;
	totalBills = totalBills + waterBill;
	totalBills = totalBills + gasBill;
	totalBills = totalBills + internetBill;
	totalBills = totalBills + trashBill;
	totalBills = totalBills + intercomBill;
	totalBills = totalBills + heatingBill;
	totalBills = totalBills + renovationBill;
	
	moneyOnCard = moneyOnCard - totalBills;
	totalCommunalPayments = totalCommunalPayments + totalBills;
	
	cout << "  Коммунальные платежи:" << endl;
	cout << "    Электричество: -" << electricityBill << " рублей" << endl;
	cout << "    Вода: -" << waterBill << " рублей" << endl;
	cout << "    Газ: -" << gasBill << " рублей" << endl;
	cout << "    Интернет: -" << internetBill << " рублей" << endl;
	cout << "    Вывоз мусора: -" << trashBill << " рублей" << endl;
	cout << "    Домофон: -" << intercomBill << " рублей" << endl;
	cout << "    Отопление: -" << heatingBill << " рублей" << endl;
	cout << "    Капитальный ремонт: -" << renovationBill << " рублей" << endl;
	cout << "    ВСЕГО: -" << totalBills << " рублей" << endl;
}

void spendOnOnlineShopping() {
	int totalSpent = 0;
	totalSpent = totalSpent + ozonSpending;
	totalSpent = totalSpent + wildberriesSpending;
	totalSpent = totalSpent + marketSpending;
	totalSpent = totalSpent + aliexpressSpending;
	
	moneyOnCard = moneyOnCard - totalSpent;
	totalOnlineSpending = totalOnlineSpending + totalSpent;
	
	cout << "  Покупки в интернете:" << endl;
	cout << "    Ozon: -" << ozonSpending << " рублей" << endl;
	cout << "    Wildberries: -" << wildberriesSpending << " рублей" << endl;
	cout << "    Яндекс Маркет: -" << marketSpending << " рублей" << endl;
	cout << "    AliExpress: -" << aliexpressSpending << " рублей" << endl;
	cout << "    ВСЕГО: -" << totalSpent << " рублей" << endl;
}

void spendOnCafe() {
	int cafeVisitsThisMonth = getRandomInRange(2, 4);
	int deliveryThisMonth = getRandomInRange(1, 3);
	
	int cafeCost = cafeVisitsThisMonth * cafeAverageBill;
	int deliveryCost = deliveryThisMonth * deliveryAverageBill;
	
	moneyOnCard = moneyOnCard - cafeCost;
	moneyOnCard = moneyOnCard - deliveryCost;
	
	cafeVisitsCount = cafeVisitsCount + cafeVisitsThisMonth;
	deliveryTimesCount = deliveryTimesCount + deliveryThisMonth;
	
	cafeTotalSpending = cafeTotalSpending + cafeCost;
	deliveryTotalSpending = deliveryTotalSpending + deliveryCost;
	
	cout << "  Кафе и доставка:" << endl;
	cout << "    Кафе: -" << cafeCost << " рублей (посещений: " << cafeVisitsThisMonth << ")" << endl;
	cout << "    Доставка: -" << deliveryCost << " рублей (заказов: " << deliveryThisMonth << ")" << endl;
}

void spendOnCinema(int currentMonth) {
	int cinemaVisitsThisMonth = getRandomInRange(1, 2);
	int cinemaCost = cinemaVisitsThisMonth * cinemaTicketPrice;
	
	moneyOnCard = moneyOnCard - cinemaCost;
	cinemaTotalSpending = cinemaTotalSpending + cinemaCost;
	
	cout << "  Кино:" << endl;
	cout << "    Потрачено: -" << cinemaCost << " рублей" << endl;
	cout << "    Посещений: " << cinemaVisitsThisMonth << endl;
}

void spendOnGym() {
	moneyOnCard = moneyOnCard - gymMonthlyPrice;
	gymTotalSpending = gymTotalSpending + gymMonthlyPrice;
	
	cout << "  Спортивный зал:" << endl;
	cout << "    Абонемент: -" << gymMonthlyPrice << " рублей" << endl;
}

void spendOnTaxi() {
	int tripsThisMonth = getRandomInRange(1, 3);
	int totalCost = tripsThisMonth * taxiAveragePrice;
	
	moneyOnCard = moneyOnCard - totalCost;
	taxiTripsCount = taxiTripsCount + tripsThisMonth;
	taxiTotalSpending = taxiTotalSpending + totalCost;
	
	cout << "  Такси:" << endl;
	cout << "    Поездок: " << tripsThisMonth << endl;
	cout << "    Потрачено: -" << totalCost << " рублей" << endl;
}
// ============================================================
// ФУНКЦИИ РАСХОДОВ - ЧАСТЬ 3
// ============================================================

void spendOnMedicine() {
	moneyOnCard = moneyOnCard - medicineMonthly;
	moneyOnCard = moneyOnCard - vitaminsMonthly;
	
	medicineTotal = medicineTotal + medicineMonthly;
	vitaminsTotal = vitaminsTotal + vitaminsMonthly;
	
	cout << "  Аптека:" << endl;
	cout << "    Лекарства: -" << medicineMonthly << " рублей" << endl;
	cout << "    Витамины: -" << vitaminsMonthly << " рублей" << endl;
}

void spendOnCoffee() {
	int weeksInMonth = 4;
	int monthlyCost = coffeePrice * coffeePerWeek * weeksInMonth;
	
	moneyOnCard = moneyOnCard - monthlyCost;
	coffeeTotalSpending = coffeeTotalSpending + monthlyCost;
	
	cout << "  Кофе с собой:" << endl;
	cout << "    Потрачено: -" << monthlyCost << " рублей" << endl;
	cout << "    Раз в неделю: " << coffeePerWeek << endl;
}

void spendOnBeerAndSnacks() {
	int weeksInMonth = 4;
	int beerMonthly = beerPrice * beerPerWeek * weeksInMonth;
	int chipsMonthly = chipsPrice * chipsPerWeek * weeksInMonth;
	
	moneyOnCard = moneyOnCard - beerMonthly;
	moneyOnCard = moneyOnCard - chipsMonthly;
	
	beerTotalSpending = beerTotalSpending + beerMonthly;
	chipsTotalSpending = chipsTotalSpending + chipsMonthly;
	
	cout << "  Пиво и снеки:" << endl;
	cout << "    Пиво: -" << beerMonthly << " рублей" << endl;
	cout << "    Чипсы: -" << chipsMonthly << " рублей" << endl;
}

void spendOnBirthday(int currentMonth) {
	if (currentMonth == birthdayMonthNumber) {
		if (birthdayHasHappened == false) {
			moneyOnCard = moneyOnCard - birthdayGiftsAmount;
			moneyOnCard = moneyOnCard - birthdayCakePrice;
			moneyOnCard = moneyOnCard - birthdayRestaurantPrice;
			
			birthdayHasHappened = true;
			birthdayTotalSpending = birthdayGiftsAmount + birthdayCakePrice + birthdayRestaurantPrice;
			
			cout << "  ДЕНЬ РОЖДЕНИЯ:" << endl;
			cout << "    Подарки: -" << birthdayGiftsAmount << " рублей" << endl;
			cout << "    Торт: -" << birthdayCakePrice << " рублей" << endl;
			cout << "    Ресторан: -" << birthdayRestaurantPrice << " рублей" << endl;
			cout << "    ВСЕГО: -" << birthdayTotalSpending << " рублей" << endl;
		}
	}
}

void spendOnTaxes(int currentMonth, int currentYear) {
	moneyOnCard = moneyOnCard - monthlyTax;
	monthlyTaxTotal = monthlyTaxTotal + monthlyTax;
	
	cout << "  Ежемесячные налоги:" << endl;
	cout << "    Сумма: -" << monthlyTax << " рублей" << endl;
	
	if (currentMonth == 5) {
		moneyOnCard = moneyOnCard - transportTax;
		cout << "  Транспортный налог:" << endl;
		cout << "    Сумма: -" << transportTax << " рублей" << endl;
	}
}

void spendOnClothes() {
	moneyOnCard = moneyOnCard - clothesMonthly;
	moneyOnCard = moneyOnCard - shoesMonthly;
	
	clothesTotal = clothesTotal + clothesMonthly;
	shoesTotal = shoesTotal + shoesMonthly;
	
	cout << "  Одежда и обувь:" << endl;
	cout << "    Одежда: -" << clothesMonthly << " рублей" << endl;
	cout << "    Обувь: -" << shoesMonthly << " рублей" << endl;
}

void spendOnBooks() {
	moneyOnCard = moneyOnCard - booksMonthly;
	booksTotalSpending = booksTotalSpending + booksMonthly;
	
	cout << "  Книги:" << endl;
	cout << "    Потрачено: -" << booksMonthly << " рублей" << endl;
	
	int randomChance = getRandomNumber();
	if (randomChance <= 30) {
		int extraBookPrice = getRandomInRange(500, 1000);
		moneyOnCard = moneyOnCard - extraBookPrice;
		booksTotalSpending = booksTotalSpending + extraBookPrice;
		cout << "    Дополнительная книга: -" << extraBookPrice << " рублей" << endl;
	}
}

void spendOnHobby(int currentMonth) {
	moneyOnCard = moneyOnCard - hobbyMonthly;
	hobbyTotalSpending = hobbyTotalSpending + hobbyMonthly;
	
	cout << "  Хобби:" << endl;
	cout << "    Ежемесячные расходы: -" << hobbyMonthly << " рублей" << endl;
}

void spendOnGifts() {
	moneyOnCard = moneyOnCard - giftsMonthly;
	giftsTotalSpending = giftsTotalSpending + giftsMonthly;
	
	cout << "  Подарки друзьям:" << endl;
	cout << "    Потрачено: -" << giftsMonthly << " рублей" << endl;
	
	int randomChance = getRandomNumber();
	if (randomChance <= 40) {
		int extraGiftPrice = getRandomInRange(800, 1500);
		moneyOnCard = moneyOnCard - extraGiftPrice;
		giftsTotalSpending = giftsTotalSpending + extraGiftPrice;
		cout << "    Внезапный подарок: -" << extraGiftPrice << " рублей" << endl;
	}
}

void spendOnEducation(int currentMonth) {
	moneyOnCard = moneyOnCard - englishMonthly;
	englishTotalSpending = englishTotalSpending + englishMonthly;
	
	cout << "  Английский язык:" << endl;
	cout << "    Занятия: -" << englishMonthly << " рублей" << endl;
}

void spendOnVacation(int currentMonth) {
	if (currentMonth == vacationMonthNumber) {
		if (vacationHasHappened == false) {
			moneyOnCard = moneyOnCard - vacationYearlyCost;
			vacationHasHappened = true;
			
			cout << "  ОТПУСК:" << endl;
			cout << "    Стоимость: -" << vacationYearlyCost << " рублей" << endl;
		}
	}
	
	if (currentMonth == 5) {
		moneyOnCard = moneyOnCard - weekendTripsCost;
		weekendTripsTotal = weekendTripsTotal + weekendTripsCost;
		cout << "  Поездка на выходные (май): -" << weekendTripsCost << " рублей" << endl;
	}
	else if (currentMonth == 6) {
		moneyOnCard = moneyOnCard - weekendTripsCost;
		weekendTripsTotal = weekendTripsTotal + weekendTripsCost;
		cout << "  Поездка на выходные (июнь): -" << weekendTripsCost << " рублей" << endl;
	}
}

void spendOnHealth(int currentMonth, int currentYear) {
	if (currentMonth == 3) {
		moneyOnCard = moneyOnCard - dentistVisitCost;
		cout << "  Стоматолог:" << endl;
		cout << "    Лечение: -" << dentistVisitCost << " рублей" << endl;
	}
	
	if (currentMonth == 4 && currentYear == 2026) {
		moneyOnCard = moneyOnCard - massageMonthly;
		massageTotalSpending = massageTotalSpending + massageMonthly;
		cout << "  Массаж:" << endl;
		cout << "    Сеанс: -" << massageMonthly << " рублей" << endl;
	}
	else if (currentMonth == 7 && currentYear == 2026) {
		moneyOnCard = moneyOnCard - massageMonthly;
		massageTotalSpending = massageTotalSpending + massageMonthly;
		cout << "  Массаж:" << endl;
		cout << "    Сеанс: -" << massageMonthly << " рублей" << endl;
	}
	else if (currentMonth == 10 && currentYear == 2026) {
		moneyOnCard = moneyOnCard - massageMonthly;
		massageTotalSpending = massageTotalSpending + massageMonthly;
		cout << "  Массаж:" << endl;
		cout << "    Сеанс: -" << massageMonthly << " рублей" << endl;
	}
}

void spendOnInsurance(int currentMonth) {
	if (currentMonth == 1) {
		moneyOnCard = moneyOnCard - carInsuranceCost;
		cout << "  Страховка автомобиля:" << endl;
		cout << "    Стоимость: -" << carInsuranceCost << " рублей" << endl;
	}
}
// ============================================================
// ФУНКЦИИ ДЛЯ ПРОДУКТОВ
// ============================================================

void setupProductCounts(int currentMonth) {
	if (currentMonth == 1) {
		breadCount = 16;
		milkCount = 13;
		eggsCount = 4;
		cheeseCount = 3;
		chickenCount = 5;
		meatCount = 2;
		fishCount = 2;
		applesCount = 5;
		bananasCount = 4;
		potatoesCount = 9;
		tomatoesCount = 4;
		cucumbersCount = 4;
		onionCount = 2;
		garlicCount = 1;
		pastaCount = 4;
		riceCount = 3;
		buckwheatCount = 3;
		oilCount = 2;
		yogurtCount = 10;
		chocolateCount = 3;
		teaCount = 1;
		coffeeCount = 1;
		waterCount = 8;
		juiceCount = 4;
		icecreamCount = 2;
	}
	else if (currentMonth == 2) {
		breadCount = 15;
		milkCount = 12;
		eggsCount = 4;
		cheeseCount = 3;
		chickenCount = 5;
		meatCount = 2;
		fishCount = 2;
		applesCount = 4;
		bananasCount = 4;
		potatoesCount = 8;
		tomatoesCount = 4;
		cucumbersCount = 4;
		onionCount = 2;
		garlicCount = 1;
		pastaCount = 4;
		riceCount = 3;
		buckwheatCount = 3;
		oilCount = 2;
		yogurtCount = 10;
		chocolateCount = 2;
		teaCount = 1;
		coffeeCount = 1;
		waterCount = 6;
		juiceCount = 3;
		icecreamCount = 3;
	}
	else if (currentMonth == 3) {
		breadCount = 18;
		milkCount = 14;
		eggsCount = 5;
		cheeseCount = 3;
		chickenCount = 6;
		meatCount = 3;
		fishCount = 2;
		applesCount = 5;
		bananasCount = 5;
		potatoesCount = 9;
		tomatoesCount = 5;
		cucumbersCount = 5;
		onionCount = 2;
		garlicCount = 1;
		pastaCount = 5;
		riceCount = 4;
		buckwheatCount = 3;
		oilCount = 2;
		yogurtCount = 12;
		chocolateCount = 3;
		teaCount = 1;
		coffeeCount = 1;
		waterCount = 8;
		juiceCount = 4;
		icecreamCount = 4;
	}
	else if (currentMonth == 4) {
		breadCount = 16;
		milkCount = 13;
		eggsCount = 4;
		cheeseCount = 3;
		chickenCount = 5;
		meatCount = 2;
		fishCount = 2;
		applesCount = 6;
		bananasCount = 5;
		potatoesCount = 8;
		tomatoesCount = 6;
		cucumbersCount = 6;
		onionCount = 2;
		garlicCount = 1;
		pastaCount = 4;
		riceCount = 3;
		buckwheatCount = 3;
		oilCount = 2;
		yogurtCount = 10;
		chocolateCount = 2;
		teaCount = 1;
		coffeeCount = 1;
		waterCount = 10;
		juiceCount = 4;
		icecreamCount = 5;
	}
	else if (currentMonth == 5) {
		breadCount = 18;
		milkCount = 14;
		eggsCount = 5;
		cheeseCount = 3;
		chickenCount = 6;
		meatCount = 3;
		fishCount = 2;
		applesCount = 7;
		bananasCount = 6;
		potatoesCount = 9;
		tomatoesCount = 7;
		cucumbersCount = 7;
		onionCount = 2;
		garlicCount = 1;
		pastaCount = 5;
		riceCount = 4;
		buckwheatCount = 4;
		oilCount = 2;
		yogurtCount = 12;
		chocolateCount = 3;
		teaCount = 1;
		coffeeCount = 1;
		waterCount = 12;
		juiceCount = 5;
		icecreamCount = 7;
	}
	else if (currentMonth == 6) {
		breadCount = 16;
		milkCount = 15;
		eggsCount = 5;
		cheeseCount = 3;
		chickenCount = 6;
		meatCount = 3;
		fishCount = 2;
		applesCount = 8;
		bananasCount = 7;
		potatoesCount = 7;
		tomatoesCount = 8;
		cucumbersCount = 8;
		onionCount = 2;
		garlicCount = 1;
		pastaCount = 4;
		riceCount = 3;
		buckwheatCount = 3;
		oilCount = 2;
		yogurtCount = 12;
		chocolateCount = 3;
		teaCount = 1;
		coffeeCount = 1;
		waterCount = 15;
		juiceCount = 6;
		icecreamCount = 8;
	}
	else if (currentMonth == 7) {
		breadCount = 17;
		milkCount = 16;
		eggsCount = 5;
		cheeseCount = 4;
		chickenCount = 6;
		meatCount = 3;
		fishCount = 3;
		applesCount = 9;
		bananasCount = 8;
		potatoesCount = 8;
		tomatoesCount = 9;
		cucumbersCount = 9;
		onionCount = 3;
		garlicCount = 1;
		pastaCount = 4;
		riceCount = 3;
		buckwheatCount = 3;
		oilCount = 2;
		yogurtCount = 14;
		chocolateCount = 4;
		teaCount = 1;
		coffeeCount = 1;
		waterCount = 18;
		juiceCount = 7;
		icecreamCount = 10;
	}
	else if (currentMonth == 8) {
		breadCount = 17;
		milkCount = 16;
		eggsCount = 5;
		cheeseCount = 4;
		chickenCount = 6;
		meatCount = 3;
		fishCount = 3;
		applesCount = 9;
		bananasCount = 8;
		potatoesCount = 8;
		tomatoesCount = 9;
		cucumbersCount = 9;
		onionCount = 3;
		garlicCount = 1;
		pastaCount = 4;
		riceCount = 3;
		buckwheatCount = 3;
		oilCount = 2;
		yogurtCount = 14;
		chocolateCount = 4;
		teaCount = 1;
		coffeeCount = 1;
		waterCount = 18;
		juiceCount = 7;
		icecreamCount = 10;
	}
	else if (currentMonth == 9) {
		breadCount = 16;
		milkCount = 14;
		eggsCount = 4;
		cheeseCount = 3;
		chickenCount = 5;
		meatCount = 3;
		fishCount = 2;
		applesCount = 7;
		bananasCount = 6;
		potatoesCount = 8;
		tomatoesCount = 7;
		cucumbersCount = 7;
		onionCount = 2;
		garlicCount = 1;
		pastaCount = 4;
		riceCount = 3;
		buckwheatCount = 3;
		oilCount = 2;
		yogurtCount = 12;
		chocolateCount = 3;
		teaCount = 1;
		coffeeCount = 1;
		waterCount = 14;
		juiceCount = 5;
		icecreamCount = 6;
	}
	else if (currentMonth == 10) {
		breadCount = 16;
		milkCount = 14;
		eggsCount = 4;
		cheeseCount = 3;
		chickenCount = 5;
		meatCount = 3;
		fishCount = 2;
		applesCount = 6;
		bananasCount = 5;
		potatoesCount = 9;
		tomatoesCount = 6;
		cucumbersCount = 5;
		onionCount = 2;
		garlicCount = 1;
		pastaCount = 4;
		riceCount = 3;
		buckwheatCount = 3;
		oilCount = 2;
		yogurtCount = 12;
		chocolateCount = 3;
		teaCount = 1;
		coffeeCount = 1;
		waterCount = 12;
		juiceCount = 5;
		icecreamCount = 4;
	}
	else if (currentMonth == 11) {
		breadCount = 17;
		milkCount = 15;
		eggsCount = 5;
		cheeseCount = 4;
		chickenCount = 6;
		meatCount = 3;
		fishCount = 3;
		applesCount = 5;
		bananasCount = 5;
		potatoesCount = 10;
		tomatoesCount = 5;
		cucumbersCount = 4;
		onionCount = 3;
		garlicCount = 2;
		pastaCount = 5;
		riceCount = 4;
		buckwheatCount = 4;
		oilCount = 3;
		yogurtCount = 13;
		chocolateCount = 5;
		teaCount = 2;
		coffeeCount = 1;
		waterCount = 10;
		juiceCount = 4;
		icecreamCount = 2;
	}
	else if (currentMonth == 12) {
		breadCount = 20;
		milkCount = 18;
		eggsCount = 6;
		cheeseCount = 5;
		chickenCount = 7;
		meatCount = 5;
		fishCount = 4;
		applesCount = 6;
		bananasCount = 6;
		potatoesCount = 12;
		tomatoesCount = 6;
		cucumbersCount = 5;
		onionCount = 4;
		garlicCount = 2;
		pastaCount = 6;
		riceCount = 5;
		buckwheatCount = 5;
		oilCount = 3;
		yogurtCount = 15;
		chocolateCount = 8;
		teaCount = 2;
		coffeeCount = 2;
		waterCount = 12;
		juiceCount = 6;
		icecreamCount = 3;
	}
}

void spendOnFood() {
	int totalSpent = 0;
	
	totalSpent = totalSpent + (breadPrice * breadCount);
	totalSpent = totalSpent + (milkPrice * milkCount);
	totalSpent = totalSpent + (eggsPrice * eggsCount);
	totalSpent = totalSpent + (cheesePrice * cheeseCount);
	totalSpent = totalSpent + (chickenPrice * chickenCount);
	totalSpent = totalSpent + (meatPrice * meatCount);
	totalSpent = totalSpent + (fishPrice * fishCount);
	totalSpent = totalSpent + (applesPrice * applesCount);
	totalSpent = totalSpent + (bananasPrice * bananasCount);
	totalSpent = totalSpent + (potatoesPrice * potatoesCount);
	totalSpent = totalSpent + (tomatoesPrice * tomatoesCount);
	totalSpent = totalSpent + (cucumbersPrice * cucumbersCount);
	totalSpent = totalSpent + (onionPrice * onionCount);
	totalSpent = totalSpent + (garlicPrice * garlicCount);
	totalSpent = totalSpent + (pastaPrice * pastaCount);
	totalSpent = totalSpent + (ricePrice * riceCount);
	totalSpent = totalSpent + (buckwheatPrice * buckwheatCount);
	totalSpent = totalSpent + (oilPrice * oilCount);
	totalSpent = totalSpent + (yogurtPrice * yogurtCount);
	totalSpent = totalSpent + (chocolatePrice * chocolateCount);
	totalSpent = totalSpent + (teaPrice * teaCount);
	totalSpent = totalSpent + (coffeePriceGrocery * coffeeCount);
	totalSpent = totalSpent + (waterPrice * waterCount);
	totalSpent = totalSpent + (juicePrice * juiceCount);
	totalSpent = totalSpent + (icecreamPrice * icecreamCount);
	
	moneyOnCard = moneyOnCard - totalSpent;
	totalFoodSpending = totalFoodSpending + totalSpent;
	
	cout << "  Продукты питания:" << endl;
	cout << "    Всего потрачено: -" << totalSpent << " рублей" << endl;
	cout << "    Количество наименований: 26" << endl;
}

void spendOnPhone(int currentMonth, int currentYear) {
	if (currentMonth == phoneBuyMonth && currentYear == phoneBuyYear) {
		if (phoneIsBought == false) {
			phoneModel = "Samsung Galaxy A55";
			phonePrice = 38000;
			
			moneyOnCard = moneyOnCard - phonePrice;
			phoneIsBought = true;
			
			cout << "  ТЕЛЕФОН КУПЛЕН:" << endl;
			cout << "    Модель: " << phoneModel << endl;
			cout << "    Цена: -" << phonePrice << " рублей" << endl;
			cout << "    Память: " << phoneMemory << " ГБ" << endl;
			cout << "    Процессор: " << phoneProcessor << endl;
			cout << "    Экран: " << phoneScreenSize << " дюймов" << endl;
			cout << "    Цвет: " << phoneColor << endl;
		}
	}
}
// ============================================================
// ГЛАВНАЯ ФУНКЦИЯ СИМУЛЯЦИИ
// ============================================================

void startSimulation() {
	int currentMonth = 1;
	int currentYear = 2026;
	
	cout << "\n==========================================" << endl;
	cout << "   ФИНАНСОВЫЙ СИМУЛЯТОР 2026 ГОДА" << endl;
	cout << "==========================================\n" << endl;
	
	cout << "НАЧАЛЬНЫЕ УСЛОВИЯ:" << endl;
	cout << "  Дата старта: Январь 2026 года" << endl;
	cout << "  Денег на карте: " << moneyOnCard << " рублей" << endl;
	cout << "  Ежемесячная зарплата: " << salary << " рублей" << endl;
	cout << "  Процент по вкладу: " << bankPercent << "% годовых" << endl;
	cout << "\n==========================================\n" << endl;
	
	while (true) {
		if (currentMonth == 1 && currentYear == 2027) {
			break;
		}
		
		string monthName = getMonthName(currentMonth);
		cout << "\n========== " << monthName << " " << currentYear << " ==========" << endl;
		
		int moneyAtStartOfMonth = moneyOnCard;
		
		cout << "\n--- ДОХОДЫ ---" << endl;
		calculateBankPercent(currentMonth, currentYear);
		receiveSalary();
		calculateInvestIncome(currentMonth, currentYear);
		
		cout << "\n--- БИЗНЕС НА OZON ---" << endl;
		processBusiness1(currentMonth);
		processBusiness2(currentMonth);
		processBusiness3(currentMonth);
		processBusiness4(currentMonth);
		processBusiness5(currentMonth);
		
		cout << "\n--- РАСХОДЫ ---" << endl;
		spendOnCat();
		spendOnCar(currentMonth, currentYear);
		spendOnMcDonalds();
		spendOnShawarma();
		spendOnChupaChups();
		spendOnTravelCard();
		spendOnSneakers(currentMonth);
		spendOnCommunal();
		spendOnOnlineShopping();
		spendOnCafe();
		spendOnCinema(currentMonth);
		spendOnGym();
		spendOnTaxi();
		spendOnMedicine();
		spendOnCoffee();
		spendOnBeerAndSnacks();
		spendOnBirthday(currentMonth);
		spendOnTaxes(currentMonth, currentYear);
		spendOnClothes();
		spendOnBooks();
		spendOnHobby(currentMonth);
		spendOnGifts();
		spendOnEducation(currentMonth);
		spendOnVacation(currentMonth);
		spendOnHealth(currentMonth, currentYear);
		spendOnInsurance(currentMonth);
		
		cout << "\n--- ПРОДУКТЫ ---" << endl;
		setupProductCounts(currentMonth);
		spendOnFood();
		
		cout << "\n--- ТЕЛЕФОН ---" << endl;
		spendOnPhone(currentMonth, currentYear);
		
		int moneyAtEndOfMonth = moneyOnCard;
		int monthlyChange = moneyAtEndOfMonth - moneyAtStartOfMonth;
		
		cout << "\n--- ИТОГИ МЕСЯЦА ---" << endl;
		cout << "  Денег на начало месяца: " << moneyAtStartOfMonth << " рублей" << endl;
		cout << "  Денег на конец месяца: " << moneyAtEndOfMonth << " рублей" << endl;
		cout << "  Изменение за месяц: ";
		
		if (monthlyChange > 0) {
			cout << "+" << monthlyChange << " рублей (ПРИБЫЛЬ)";
		}
		else if (monthlyChange < 0) {
			cout << monthlyChange << " рублей (УБЫТОК)";
		}
		else {
			cout << "0 рублей (БЕЗ ИЗМЕНЕНИЙ)";
		}
		cout << endl;
		
		currentMonth = currentMonth + 1;
		if (currentMonth > 12) {
			currentMonth = 1;
			currentYear = currentYear + 1;
		}
	}
}
// ============================================================
// ФУНКЦИЯ ВЫВОДА ИТОГОВОЙ СТАТИСТИКИ
// ============================================================

void printFinalStatistics() {
	cout << "\n\n";
	cout << "==========================================" << endl;
	cout << "         ИТОГОВАЯ СТАТИСТИКА 2026" << endl;
	cout << "==========================================\n" << endl;
	
	cout << "ДЕНЬГИ НА КАРТЕ:" << endl;
	cout << "  Старт (Январь 2026): " << startMoney << " рублей" << endl;
	cout << "  Финал (Декабрь 2026): " << moneyOnCard << " рублей" << endl;
	
	int totalDifference = moneyOnCard - startMoney;
	cout << "  Изменение за год: ";
	if (totalDifference > 0) {
		cout << "+";
	}
	cout << totalDifference << " рублей" << endl;
	
	float growthPercent = (totalDifference * 100.0) / startMoney;
	cout << "  Рост капитала: " << growthPercent << "%" << endl;
	
	cout << "\n------------------------------------------" << endl;
	cout << "ИТОГИ БИЗНЕСА НА OZON:" << endl;
	cout << "------------------------------------------" << endl;
	
	cout << "\n  1. " << productName1 << ":" << endl;
	cout << "     Продано за год: " << totalSales1 << " штук" << endl;
	cout << "     Выручка: " << totalRevenue1 << " рублей" << endl;
	cout << "     ПРИБЫЛЬ: " << totalProfit1 << " рублей" << endl;
	
	cout << "\n  2. " << productName2 << ":" << endl;
	cout << "     Продано за год: " << totalSales2 << " штук" << endl;
	cout << "     Выручка: " << totalRevenue2 << " рублей" << endl;
	cout << "     ПРИБЫЛЬ: " << totalProfit2 << " рублей" << endl;
	
	cout << "\n  3. " << productName3 << ":" << endl;
	cout << "     Продано за год: " << totalSales3 << " штук" << endl;
	cout << "     Выручка: " << totalRevenue3 << " рублей" << endl;
	cout << "     ПРИБЫЛЬ: " << totalProfit3 << " рублей" << endl;
	
	cout << "\n  4. " << productName4 << ":" << endl;
	cout << "     Продано за год: " << totalSales4 << " штук" << endl;
	cout << "     Выручка: " << totalRevenue4 << " рублей" << endl;
	cout << "     ПРИБЫЛЬ: " << totalProfit4 << " рублей" << endl;
	
	cout << "\n  5. " << productName5 << ":" << endl;
	cout << "     Продано за год: " << totalSales5 << " штук" << endl;
	cout << "     Выручка: " << totalRevenue5 << " рублей" << endl;
	cout << "     ПРИБЫЛЬ: " << totalProfit5 << " рублей" << endl;
	
	int totalBusinessProfit = 0;
	totalBusinessProfit = totalBusinessProfit + totalProfit1;
	totalBusinessProfit = totalBusinessProfit + totalProfit2;
	totalBusinessProfit = totalBusinessProfit + totalProfit3;
	totalBusinessProfit = totalBusinessProfit + totalProfit4;
	totalBusinessProfit = totalBusinessProfit + totalProfit5;
	
	cout << "\n  ОБЩАЯ ПРИБЫЛЬ ОТ БИЗНЕСА: " << totalBusinessProfit << " рублей" << endl;
	
	cout << "\n------------------------------------------" << endl;
	cout << "ОСНОВНЫЕ РАСХОДЫ ЗА ГОД:" << endl;
	cout << "------------------------------------------" << endl;
	
	int carTotalExpenses = 0;
	carTotalExpenses = carTotalExpenses + carTotalRepairCost;
	carTotalExpenses = carTotalExpenses + gasolineTotalSpending;
	carTotalExpenses = carTotalExpenses + carWashTotalSpending;
	carTotalExpenses = carTotalExpenses + (carParkingCost * 12);
	carTotalExpenses = carTotalExpenses + carInsuranceCost;
	carTotalExpenses = carTotalExpenses + carTaxCost;
	carTotalExpenses = carTotalExpenses + (carServiceCost * 2);
	carTotalExpenses = carTotalExpenses + (tireFittingCost * 2);
	carTotalExpenses = carTotalExpenses + tireStorageCost;
	
	int foodTotalExpenses = totalFoodSpending;
	
	int cafeTotalExpenses = cafeTotalSpending + deliveryTotalSpending;
	
	int clothesTotalExpenses = clothesTotal + shoesTotal;
	
	int vacationTotalExpenses = 0;
	if (vacationHasHappened == true) {
		vacationTotalExpenses = vacationTotalExpenses + vacationYearlyCost;
	}
	vacationTotalExpenses = vacationTotalExpenses + weekendTripsTotal;
	
	int healthTotalExpenses = 0;
	healthTotalExpenses = healthTotalExpenses + dentistVisitCost;
	healthTotalExpenses = healthTotalExpenses + massageTotalSpending;
	
	cout << "\n  КОТ " << catName << ":" << endl;
	cout << "    Всего расходов: " << catTotalCost << " рублей" << endl;
	
	cout << "\n  АВТОМОБИЛЬ " << carName << ":" << endl;
	cout << "    Всего расходов: " << carTotalExpenses << " рублей" << endl;
	cout << "    Количество ремонтов: " << carTotalRepairs << endl;
	
	cout << "\n  КОММУНАЛЬНЫЕ ПЛАТЕЖИ:" << endl;
	cout << "    Всего: " << totalCommunalPayments << " рублей" << endl;
	
	cout << "\n  ПРОДУКТЫ ПИТАНИЯ:" << endl;
	cout << "    Всего: " << foodTotalExpenses << " рублей" << endl;
	
	cout << "\n  КАФЕ И ДОСТАВКА:" << endl;
	cout << "    Всего: " << cafeTotalExpenses << " рублей" << endl;
	cout << "    Посещений кафе: " << cafeVisitsCount << endl;
	cout << "    Заказов доставки: " << deliveryTimesCount << endl;
	
	cout << "\n  ОДЕЖДА И ОБУВЬ:" << endl;
	cout << "    Всего: " << clothesTotalExpenses << " рублей" << endl;
	
	cout << "\n  ПУТЕШЕСТВИЯ:" << endl;
	cout << "    Всего: " << vacationTotalExpenses << " рублей" << endl;
	
	cout << "\n  ЗДОРОВЬЕ:" << endl;
	cout << "    Всего: " << healthTotalExpenses << " рублей" << endl;
	
	int allExpenses = 0;
	allExpenses = allExpenses + catTotalCost;
	allExpenses = allExpenses + carTotalExpenses;
	allExpenses = allExpenses + totalCommunalPayments;
	allExpenses = allExpenses + foodTotalExpenses;
	allExpenses = allExpenses + cafeTotalExpenses;
	allExpenses = allExpenses + clothesTotalExpenses;
	allExpenses = allExpenses + vacationTotalExpenses;
	allExpenses = allExpenses + healthTotalExpenses;
	allExpenses = allExpenses + mcTotalMoney;
	allExpenses = allExpenses + shawarmaTotalExpenses;
	allExpenses = allExpenses + chupaTotalExpenses;
	allExpenses = allExpenses + travelCardTotal;
	allExpenses = allExpenses + totalOnlineSpending;
	allExpenses = allExpenses + cinemaTotalSpending;
	allExpenses = allExpenses + gymTotalSpending;
	allExpenses = allExpenses + taxiTotalSpending;
	allExpenses = allExpenses + medicineTotal;
	allExpenses = allExpenses + vitaminsTotal;
	allExpenses = allExpenses + coffeeTotalSpending;
	allExpenses = allExpenses + beerTotalSpending;
	allExpenses = allExpenses + chipsTotalSpending;
	allExpenses = allExpenses + birthdayTotalSpending;
	allExpenses = allExpenses + monthlyTaxTotal;
	allExpenses = allExpenses + transportTax;
	allExpenses = allExpenses + booksTotalSpending;
	allExpenses = allExpenses + hobbyTotalSpending;
	allExpenses = allExpenses + giftsTotalSpending;
	allExpenses = allExpenses + englishTotalSpending;
	
	if (sneakersAreBought == true) {
		allExpenses = allExpenses + sneakersPrice;
	}
	
	if (phoneIsBought == true) {
		allExpenses = allExpenses + phonePrice;
	}
	
	cout << "\n------------------------------------------" << endl;
	cout << "ОБЩИЙ ИТОГ:" << endl;
	cout << "------------------------------------------" << endl;
	cout << "  Всего расходов за год: " << allExpenses << " рублей" << endl;
	
	int totalIncome = 0;
	totalIncome = totalIncome + (salary * 12);
	totalIncome = totalIncome + investTotalIncome;
	totalIncome = totalIncome + totalBusinessProfit;
	
	int bankInterest = moneyOnCard - startMoney - (salary * 12) - investTotalIncome - totalBusinessProfit + allExpenses;
	totalIncome = totalIncome + bankInterest;
	
	cout << "  Всего доходов за год: " << totalIncome << " рублей" << endl;
	cout << "  Чистая прибыль: " << (totalIncome - allExpenses) << " рублей" << endl;
	
	cout << "\n==========================================" << endl;
	cout << "         ДЕНЬГИ НА КАРТЕ: " << moneyOnCard << " рублей" << endl;
	cout << "==========================================" << endl;
}
// ============================================================
// ГЛАВНАЯ ФУНКЦИЯ MAIN
// ============================================================

int main() {
	system("chcp 65001 > nul");
	srand(time(0));
	
	cout << "==========================================" << endl;
	cout << "    ФИНАНСОВЫЙ СИМУЛЯТОР 2026" << endl;
	cout << "==========================================" << endl;
	
	startSimulation();
	printFinalStatistics();
	
	return 0;
}
