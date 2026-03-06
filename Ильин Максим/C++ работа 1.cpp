
#include <iostream>
using namespace std;



int salary = 13000;
int capitalinbank = 10000;
int capitalsumma = 0;
int main()
{
	// Устанавливаем кодировку
	std::system("chcp 65001 > nul");
	 std::system("chcp 65001 > nul");
	float pp = 24;
	//Лада Веста Спорт!
	//Лада Веста Спорт!
	//Лада Веста Спорт!
	//Лада Веста Спорт!
	//Лада Веста Спорт!
	string carName = "LadaVestaSport";
	int carRepairCost = 3000;
	int carRepairProbability = 40;
	int totalCarRepairExpenses = 0;
	int carRepairCount = 0;
	int month = 2;
	int year = 2026;
	// Инициализируем генератор случайных чисел для поломок машины
	srand(time(0));
	// Информация о машине
	printf("ИНФОРМАЦИЯ О МАШИНЕ %s:\n", carName.c_str());
	printf("- Вероятность поломки: %d%% каждый месяц\n", carRepairProbability);
	printf("- Стоимость ремонта: %d руб\n\n", carRepairCost);
	string sneakersName = "NikeDunk";
	int sneakersPrice = 6000;
	// ========== CHUPA-CHUPS ==========
		int chupaChupsPrice = 36;
	int chupaChupsPerWeek = 1;
	int weeksInMonth = 4;
	int totalChupaChupsExpenses = 0;
	printf("Chupa-Chups: %d руб/неделя, %d руб/месяц\n\n", 
		   (chupaChupsPrice * chupaChupsPerWeek),
			(chupaChupsPrice * chupaChupsPerWeek * weeksInMonth));
	// ========== РАСХОДЫ НА ПРОЕЗДНОЙ ==========
	
	// Переменные для расходов на проездной
	int travelCardPrice = 1500;  // стоимость проездного в месяц
	int totalTravelCardExpenses = 0;  // всего потрачено на проездные
	
	// В начале программы (после других объявлений переменных, до цикла)
	printf("Расходы на проездной:\n");
	printf("- Стоимость проездного в месяц: %d руб\n", travelCardPrice);
	printf("- Ежемесячные расходы на проездной: %d руб\n\n", travelCardPrice);
	
	// старстовый капитал, с него начинаем весь расчет
	 capitalsumma = capitalinbank;
	//КОТИК Феликс
	//КОТИК Феликс
	//КОТИК Феликс
	//КОТИК Феликс
	//КОТИК Феликс
	 printf("Старт: фев 2026, депозит = %d, общий = %d\n\n", capitalinbank, capitalsumma); 
		   // Переменные для расходов на кота Felix
		   string catName = "Felix";
		   int catFoodExpenses = 0;
		   int catToyExpenses = 0;
		   int totalCatExpenses = 0;
		   int currentMonthCatFood = 0;
		   int currentMonthCatToys = 0;
	printf("Месяцы в программе:\n");
	printf("  2 - Февраль\n");
	printf("  3 - Март\n");
	printf("  4 - Апрель\n");
	printf("  5 - Май\n");
	printf("  6 - Июнь\n\n");
	//Названия месяцев!!!
	//Названия месяцев!!!
	//Названия месяцев!!!
	//Названия месяцев!!!
	//Названия месяцев!!!
	string getMonthName (int monthNumber);
	{
		string monthName = " ";
		if ( monthName == 2)
		{
			 monthName = "Февраль";
		}
		else if ( monthNumber == 3)
		{
			 monthName = "Март";
		}
		else if (monthNumber == 4)
		{
			 monthName = "Апрель";
		}
		else if (monthNumber == 5)
		{
			 monthName = "Май";
		}
		else if (monthNumber == 6)
		{
			 monthName = "Июнь";
		}
		else if (monthNumber == 7) 
		{
			 monthName = "Июль";
		}
		else if (monthNumber == 8)
		{
			 monthName = "Август";
		}
		else if (monthNumber == 9)
		{
			 monthName = "Сентябрь";
		}
		else if (monthNumber == 10)
		{
			 monthName = "Октябрь";
		}
		else if (monthNumber == 11)
		{
			 monthName = "Ноябрь";
		}
		else if (monthNumber == 12)
		{
			 monthName = "Декабрь";
		}
		else
		{
			monthName = "Неизвестный месяц";
		}
		return 0;
	}
	//Shaverma
	//Shaverma
	//Shaverma
	//Shaverma
	//Shaverma
	//Shaverma
	// Переменные для расходов на шаверму
	// цена одной шавермы:'
	int shaverma = 150;
	// сколько раз в неделю покупаем:
	int shavermaPerWeek = 1; 
	// количество недель в месяце
	int weeksInMonth = 4;  
	printf("Начинаем учитывать расходы на кота:\n");
	printf("- Еда для кота: 3000 руб/мес\n");	
	printf("- Игрушки для кота: 1500 руб/мес\n\n");
	printf("Каждую неделю покупается шаверма:\n");
	printf("- Цена одной шавермы: %d руб\n", 
		   shaverma);
	printf("- Покупается %d раз в неделю\n", 
		   shavermaPerWeek);
	printf("- В месяце %d недели\n", 
		   weeksInMonth);
	printf("- Ежемесячные расходы на шаверму: %d руб\n\n", 
		   (shaverma * shavermaPerWeek * weeksInMonth));
	//считаем проценты
	// ========== ПРОДУКТОВАЯ КОРЗИНА ==========
	
// Продукты и их цены
	int breadPrice = 45;
	int milkPrice = 80;
	int eggsPrice = 100;
	int cheesePrice = 300;
	int chickenPrice = 350;
	int applesPrice = 120;
	int bananasPrice = 90;
	int potatoesPrice = 40;
	int pastaPrice = 70;
	int ricePrice = 95;
	int butterPrice = 150;
	int yogurtPrice = 60;
	
// Количество каждого продукта в этом месяце (меняется каждый месяц)
	int breadCount = 0;
	int milkCount = 0;
	int eggsCount = 0;
	int cheeseCount = 0;
	int chickenCount = 0;
	int applesCount = 0;
	int bananasCount = 0;
	int potatoesCount = 0;
	int pastaCount = 0;
	int riceCount = 0;
	int butterCount = 0;
	int yogurtCount = 0;
	
	int totalGroceriesExpenses = 0;
	
	printf("ПРОДУКТОВАЯ КОРЗИНА (цены за единицу):\n");
	printf("  Хлеб: %d руб\n", breadPrice);
	printf("  Молоко: %d руб\n", milkPrice);
	printf("  Яйца: %d руб\n", eggsPrice);
	printf("  Сыр: %d руб\n", cheesePrice);
	printf("  Курица: %d руб\n", chickenPrice);
	printf("  Яблоки: %d руб\n", applesPrice);
	printf("  Бананы: %d руб\n", bananasPrice);
	printf("  Картофель: %d руб\n", potatoesPrice);
	printf("  Макароны: %d руб\n", pastaPrice);
	printf("  Рис: %d руб\n", ricePrice);
	printf("  Масло: %d руб\n", butterPrice);
	printf("  Йогурт: %d руб\n\n", yogurtPrice);
	//ЦИКЛ!!!
		//ЦИКЛ!!!
		//ЦИКЛ!!!
		//ЦИКЛ!!!
		//ЦИКЛ!!!
		//ЦИКЛ!!!
		//ЦИКЛ!!!
		//ЦИКЛ!!!
	while (!((month == 7) && (year == 2026))) 
	{
		string currentMonthName = getMonthName(month);
		printf("========== МЕСЯЦ %d - %s ==========\n", month, currentMonthName.c_str());
		int interest = capitalinbank * (pp / 12.0 / 100.0);
		capitalinbank += interest;
		capitalsumma += interest;
		capitalsumma += salary;
	printf("Месяц %d: проценты = %d, зарплата = %d, депозит = %d, общий = %d\n",
			   month, interest, salary, capitalinbank, capitalsumma);
		  // Расходы на кота в текущем месяце
		currentMonthCatFood = 3000;
		
		currentMonthCatToys = 1500;
		
		int monthlyChupaChupsExpenses = chupaChupsPrice * chupaChupsPerWeek * weeksInMonth;
		totalChupaChupsExpenses += monthlyChupaChupsExpenses;
		capitalsumma -= monthlyChupaChupsExpenses;
		
		// Суммируем расходы на кота
		catFoodExpenses = catFoodExpenses + currentMonthCatFood;
		catToyExpenses = catToyExpenses + currentMonthCatToys;
		totalCatExpenses = catFoodExpenses + catToyExpenses;
		// Вычитаем расходы на кота из общей суммы
		capitalsumma = capitalsumma - currentMonthCatFood;
		capitalsumma = capitalsumma - currentMonthCatToys;
		
		// Выводим информацию о расходах на кота
		printf("Расходы на кота %s:\n", 
			   catName.c_str());
		printf("  - Еда: -%d руб\n", 
			   currentMonthCatFood);
		printf("  - Игрушки: -%d руб\n", 
			   currentMonthCatToys);
		printf("Итого расходов на кота в этом месяце: -%d руб\n", 
			   (currentMonthCatFood + currentMonthCatToys));
		printf("Накоплено расходов на еду с начала года: %d руб\n", 
			   catFoodExpenses);
		printf("Накоплено расходов на игрушки с начала года: %d руб\n", 
			   catToyExpenses);
		printf("Всего потрачено на кота с начала года: %d руб\n", 
			   totalCatExpenses);
		// Рассчитываем расходы на шаверму за месяц
		int monthlyShavermaExpenses = shaverma * shavermaPerWeek * weeksInMonth;
		// Вычитаем расходы на шаверму из общей суммы
		capitalsumma = capitalsumma - monthlyShavermaExpenses;
		// Выводим информацию о шаверме
		printf("Расходы на шаверму:\n");
		printf("  - Потрачено на шаверму в этом месяце: -%d руб\n", 
			   monthlyShavermaExpenses);
		// РАСХОДЫ НА МАШИНУ LadaVestaSport
		int randomNumber = rand() % 100 + 1;
		
		if (randomNumber <= carRepairProbability)
		{
			capitalsumma = capitalsumma - carRepairCost;
			totalCarRepairExpenses = totalCarRepairExpenses + carRepairCost;
			carRepairCount = carRepairCount + 1;
			
			printf("\n РЕМОНТ МАШИНЫ %s:\n", carName.c_str());
			printf("  - Случайное число: %d (нужно <= %d)\n", randomNumber, carRepairProbability);
			printf("  - Расход на ремонт: -%d руб\n", carRepairCost);
			printf("  - Это %d-й ремонт с начала года\n", carRepairCount);
		}
		else
		{
			printf("\nМашина %s не сломалась в этом месяце\n", carName.c_str());
			printf("  - Случайное число: %d (нужно было <= %d)\n", randomNumber, carRepairProbability);
		}
		// Вычитаем расходы на проездной из общей суммы
		capitalsumma = capitalsumma - travelCardPrice;
		totalTravelCardExpenses = totalTravelCardExpenses + travelCardPrice;
		
		// переходим к следующему месяцу
		month++;
	}
	//Праздник + шавера праздника
		//Праздник + шавера праздника
		//Праздник + шавера праздника
		//Праздник + шавера праздника
	if (month==4)
	{
		capitalsumma+=5000;
	}
	if (month==3)
	{
		capitalsumma-=sneakersPrice;
	}
	int shavermanaprazdnik;
	shavermanaprazdnik=300;
	if (month==4)
	{
		capitalsumma=capitalsumma-shavermanaprazdnik;
	}
	else
	{
		capitalsumma=capitalsumma;
	}
	if (month == 2)  // февраль
	{
		breadCount = 10;
		milkCount = 8;
		eggsCount = 2;
		cheeseCount = 2;
		chickenCount = 3;
		applesCount = 2;
		bananasCount = 3;
		potatoesCount = 5;
		pastaCount = 3;
		riceCount = 2;
		butterCount = 1;
		yogurtCount = 10;
	}
	else if (month == 3)  // март
	{
		breadCount = 12;
		milkCount = 10;
		eggsCount = 3;
		cheeseCount = 1;
		chickenCount = 4;
		applesCount = 3;
		bananasCount = 4;
		potatoesCount = 6;
		pastaCount = 4;
		riceCount = 2;
		butterCount = 2;
		yogurtCount = 12;
	}
	else if (month == 4)  // апрель
	{
		breadCount = 10;
		milkCount = 8;
		eggsCount = 2;
		cheeseCount = 2;
		chickenCount = 3;
		applesCount = 4;
		bananasCount = 4;
		potatoesCount = 5;
		pastaCount = 3;
		riceCount = 2;
		butterCount = 1;
		yogurtCount = 8;
	}
	else if (month == 5)  // май
	{
		breadCount = 12;
		milkCount = 10;
		eggsCount = 3;
		cheeseCount = 2;
		chickenCount = 4;
		applesCount = 5;
		bananasCount = 5;
		potatoesCount = 6;
		pastaCount = 4;
		riceCount = 3;
		butterCount = 2;
		yogurtCount = 10;
	}
	else if (month == 6)  // июнь
	{
		breadCount = 10;
		milkCount = 12;
		eggsCount = 3;
		cheeseCount = 2;
		chickenCount = 4;
		applesCount = 6;
		bananasCount = 6;
		potatoesCount = 4;
		pastaCount = 3;
		riceCount = 2;
		butterCount = 1;
		yogurtCount = 12;
	}
	
// Расчет стоимости продуктов
	int breadExpenses = breadPrice * breadCount;
	int milkExpenses = milkPrice * milkCount;
	int eggsExpenses = eggsPrice * eggsCount;
	int cheeseExpenses = cheesePrice * cheeseCount;
	int chickenExpenses = chickenPrice * chickenCount;
	int applesExpenses = applesPrice * applesCount;
	int bananasExpenses = bananasPrice * bananasCount;
	int potatoesExpenses = potatoesPrice * potatoesCount;
	int pastaExpenses = pastaPrice * pastaCount;
	int riceExpenses = ricePrice * riceCount;
	int butterExpenses = butterPrice * butterCount;
	int yogurtExpenses = yogurtPrice * yogurtCount;
	
	int monthlyGroceriesExpenses = breadExpenses + milkExpenses + eggsExpenses + cheeseExpenses + 
	chickenExpenses + applesExpenses + bananasExpenses + potatoesExpenses + 
	pastaExpenses + riceExpenses + butterExpenses + yogurtExpenses;
	
	capitalsumma = capitalsumma - monthlyGroceriesExpenses;
	totalGroceriesExpenses = totalGroceriesExpenses + monthlyGroceriesExpenses;
	
	printf("ПРОДУКТЫ В ЭТОМ МЕСЯЦЕ:\n");
	printf("  Хлеб: %d шт x %d руб = %d руб\n", breadCount, breadPrice, breadExpenses);
	printf("  Молоко: %d шт x %d руб = %d руб\n", milkCount, milkPrice, milkExpenses);
	printf("  Яйца: %d шт x %d руб = %d руб\n", eggsCount, eggsPrice, eggsExpenses);
	printf("  Сыр: %d шт x %d руб = %d руб\n", cheeseCount, cheesePrice, cheeseExpenses);
	printf("  Курица: %d шт x %d руб = %d руб\n", chickenCount, chickenPrice, chickenExpenses);
	printf("  Яблоки: %d шт x %d руб = %d руб\n", applesCount, applesPrice, applesExpenses);
	printf("  Бананы: %d шт x %d руб = %d руб\n", bananasCount, bananasPrice, bananasExpenses);
	printf("  Картофель: %d шт x %d руб = %d руб\n", potatoesCount, potatoesPrice, potatoesExpenses);
	printf("  Макароны: %d шт x %d руб = %d руб\n", pastaCount, pastaPrice, pastaExpenses);
	printf("  Рис: %d шт x %d руб = %d руб\n", riceCount, ricePrice, riceExpenses);
	printf("  Масло: %d шт x %d руб = %d руб\n", butterCount, butterPrice, butterExpenses);
	printf("  Йогурт: %d шт x %d руб = %d руб\n", yogurtCount, yogurtPrice, yogurtExpenses);
	printf("  ВСЕГО НА ПРОДУКТЫ: %d руб\n", monthlyGroceriesExpenses);
	
	printf("\n========== СТАТИСТИКА РАСХОДОВ НА КОТА %s ==========\n", 
		   catName.c_str());
	
	printf("Всего потрачено на еду: %d руб\n", 
		   catFoodExpenses);
	
	printf("Всего потрачено на игрушки: %d руб\n", 
		   catToyExpenses);
	
	printf("ОБЩИЕ РАСХОДЫ НА КОТА: %d руб\n", 
		   totalCatExpenses);
	return 0;
	printf("\nСТАТИСТИКА РАСХОДОВ НА МАШИНУ %s:\n", carName.c_str());
	printf("Количество ремонтов: %d\n", carRepairCount);
	printf("Всего потрачено на ремонт: %d руб\n", totalCarRepairExpenses);
	printf("ВСЕГО ПОТРАЧЕНО НА CHUPA-CHUPS: %d руб\n", totalChupaChupsExpenses);
	printf("\n========== СТАТИСТИКА РАСХОДОВ НА ПРОЕЗДНОЙ ==========\n");
	printf("Стоимость проездного в месяц: %d руб\n", travelCardPrice);
	printf("ВСЕГО ПОТРАЧЕНО НА ПРОЕЗДНЫЕ: %d руб\n", totalTravelCardExpenses);
	printf("==================================================\n\n");
	printf("\n========== СТАТИСТИКА ПРОДУКТОВ ==========\n");
	printf("Всего потрачено на продукты: %d руб\n", totalGroceriesExpenses);
	printf("==========================================\n");
}
