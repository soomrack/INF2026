#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

typedef long long int RUB;
typedef unsigned int Days;
typedef int Age;
typedef unsigned int People;
typedef bool Life;




struct date {
	short day;
	short month;
	short year;
};

date start_date;
date end_date;
date now_date;


struct person {
	std :: string name;
	Age age_start;
	People friends;
	Life life;
	Life cat_life;
	Life dog_life;
	float health;
	int car_grade;
	RUB balance_diff;
	RUB balance;
	RUB balance_start;
	RUB bank_account;
	RUB salary_RUB;
	int event_decision;
};

person Pasha;

void Pasha_initialization() {
	Pasha.name = "Pasha";
	Pasha.friends = 0;
	Pasha.life = 1;
	Pasha.cat_life = 1;
	Pasha.dog_life = 1;
	Pasha.health = 8;
	Pasha.health = 10 - Pasha.age_start * 0.1;
	Pasha.car_grade = 0;
	Pasha.balance_diff = 0;
	Pasha.balance = 0;
	Pasha.bank_account = 0;
	Pasha.salary_RUB = 128000;
}


struct car {
	int grade;
	std::string brand;
	RUB gasoline_expense;
	RUB repair_expense;
	float mental_satisfaction;
};


car Granta;
car Vesta;
car Polo;
car Superb;
car m_911;
car Urus;


void car_initialization() {
	Granta.grade = 1;
	Granta.brand = "Lada";
	Granta.gasoline_expense = 10000;
	Granta.repair_expense = 7000;
	Granta.mental_satisfaction = 0;

	Vesta.grade = 2;
	Vesta.brand = "Lada";
	Vesta.gasoline_expense = 15000;
	Vesta.repair_expense = 10000;
	Vesta.mental_satisfaction = 0.000001;

	Polo.grade = 3;
	Polo.brand = "Volkswagen";
	Polo.gasoline_expense = 20000;
	Polo.repair_expense = 20000;
	Polo.mental_satisfaction = 0.00001;

	Superb.grade = 4;
	Superb.brand = "Skoda";
	Superb.gasoline_expense = 30000;
	Superb.repair_expense = 50000;
	Superb.mental_satisfaction = 0.0001;

	m_911.grade = 5;
	m_911.brand = "Porshe";
	m_911.gasoline_expense = 50000;
	m_911.repair_expense = 70000;
	m_911.mental_satisfaction = 0.0005;

	Urus.grade = 6;
	Urus.brand = "Lamborgini";
	Urus.gasoline_expense = 70000;
	Urus.repair_expense = 150000;
	Urus.mental_satisfaction = 0.001;
}


void balance_results() {
	std :: cout << std::endl;
	std :: cout << "For the period from " << start_date.day << "."
	            << start_date.month << "." << start_date.year << " to " << now_date.day
	            << "." << now_date.month << "." << now_date.year << " the balance will change by "
	            << Pasha.balance_diff << " RUB" << std::endl;
	std :: cout << "New balance is " << Pasha.balance << " RUB" << std::endl;
}


void death_results() {
	if (Pasha.health <= 0) {
		std::cout << "You died at the age of "
		          << now_date.year - start_date.year + Pasha.age_start << " years(";
	}
	std :: cout << std::endl;

}


void car_results() {
	if (Pasha.car_grade == 0) {
		std::cout << "You didn't have a car" << std::endl;
	}

	else if (Pasha.car_grade == 1 ) {
		std::cout << "You had a Granta" << std::endl;
	}

	else if (Pasha.car_grade == 2 ) {
		std::cout << "You had a Vesta" << std::endl;
	}

	else if (Pasha.car_grade == 3 ) {
		std::cout << "You had a Polo" << std::endl;
	}

	else if (Pasha.car_grade == 4 ) {
		std::cout << "You had a Superb" << std::endl;
	}

	else if (Pasha.car_grade == 5 ) {
		std::cout << "You had a Porhse 911" << std::endl;
	}

	else if (Pasha.car_grade == 6 ) {
		std::cout << "You had a Urus" << std::endl;
	}
}


void print_results() {
	balance_results();
	car_results();
	death_results();
}


void input_date() {
	std :: cout << "Enter data" << std::endl;

	std :: cout << "--------------" << std::endl;

	std :: cout << "Start date: ";
	std :: cin >> start_date.day >> start_date.month >> start_date.year;

	std :: cout << "End date: ";
	std :: cin >> end_date.day >> end_date.month >> end_date.year;

	std :: cout << "Start balance: ";
	std :: cin >> Pasha.balance_start;

	std :: cout << "Start age: ";
	std :: cin >> Pasha.age_start;

	std :: cout << "--------------" << std::endl;

	now_date.day = start_date.day;
	now_date.month = start_date.month;
	now_date.year = start_date.year;
}



int days_in_month(int month, int year) {
	if (month == 2) {
		if ((year % 4)==0) {
			return 29;
		} else {
			return 28;
		}
	} else {
		if (month < 8) {
			return (30 + month%2);
		} else {
			return (30 + (month-1)%2);
		}
	}
}



void new_day() {

	now_date.day++;

	if (now_date.day == days_in_month(now_date.month,now_date.year)) {
		now_date.day = 1;
		now_date.month++;
	}

	if (now_date.month==13) {
		now_date.month = 1;
		now_date.year++;
	}
}


void randint() {
	std::srand(static_cast<unsigned int>(std::time(0)));
}


void food() {
	int random_coefficient = std::rand();
	if (Pasha.balance >= random_coefficient % 800 + 400) {
		Pasha.balance_diff -= (random_coefficient % 800 + 400);
	} else {
		Pasha.health -= (1 - Pasha.balance/(random_coefficient % 800 + 400)) * 0.0001;
	}
}


void damage_from_poverty() {
	if (Pasha.balance < 0) {
		Pasha.health += Pasha.balance * 0.00000001;
	}
}


void balance_new_status() {
	Pasha.balance = Pasha.balance_start + Pasha.balance_diff;
}


void salary_indexation() {
	if (!(now_date.month == 1 && now_date.day == 1)) {
		return;
	}
	Pasha.salary_RUB = Pasha.salary_RUB * 1.05;
}


void salary() {
	salary_indexation();
	if (!(now_date.day == 1) || ((now_date.year - start_date.year + Pasha.age_start) < 18 ) ) {
		return;
	}
	Pasha.balance_diff += Pasha.salary_RUB;
}



void sports() {

	if (!(now_date.day % 3 == 2) || Pasha.balance < 750) {
		return;
	}
	Pasha.balance_diff -= 750;
	Pasha.health += 0.000000001;
}




void years_old() {

	if (!(now_date.day == 1 && now_date.month == 1)) {
		return;
	}
	Pasha.health -= 0.001 * pow(1.08, (now_date.year - start_date.year + Pasha.age_start));
}


void drugs() {
	if (!(now_date.day == 15) || (Pasha.balance < 2000)) {
		return;
	}
	Pasha.balance_diff -= 2000;
	Pasha.health += 0.00001;
}



void smoking() {
	if (!(now_date.day%2 == 0) || (Pasha.balance < 800)) {
		return;
	}
	Pasha.balance_diff -= 800;
	Pasha.health -= 0.000001;
}


void drinks() {
	if (!(now_date.day % 5 == 0) || (Pasha.balance < 2500)) {
		return;
	}
	Pasha.balance_diff -= 2500;
	Pasha.health -= 0.000001;
}


void gaming_addiction() {
	if (std::rand() % 100 < 10) {
		RUB cost = 500 + (std::rand() % 2000);
		if (Pasha.balance >= cost) {
			Pasha.balance_diff -= cost;
			Pasha.health -= 0.000005;
		} else {
			Pasha.health -= 0.00001;
		}
	}
}


void travel() {

	if (!(now_date.month == 8) || (Pasha.balance < 60000)) {
		return;
	}
	Pasha.balance_diff -= 60000;
	Pasha.health += 0.0001;
}



void home() {
	if (!(now_date.day == 1)) {
		return;
	}
	if (Pasha.balance >= 30000) {
		Pasha.balance_diff -= 30000;
	}
	else {
		Pasha.health -= 0.001;
	}
}


void psychology() {
	if (!(now_date.day % 4 == 2 && Pasha.balance >= 3000)) {
		return;
	}
	Pasha.balance_diff -= 300;
	Pasha.health += 0.00000001;
}


void bank() {
	if (!(now_date.day == 1 && Pasha.balance >= 5000)) {
		return;
	}
	Pasha.balance_diff += Pasha.bank_account*(0.01);
	Pasha.balance_diff -= 5000;
	Pasha.bank_account += 5000;
}



void taxes() {
	if (!(now_date.month == 4 && now_date.day == 15)) {
		return;
	}

	float tax_rate = 0.13;

	if (Pasha.balance > 1000000) {
		tax_rate = 0.20;
	}

	else if (Pasha.balance > 500000) {
		tax_rate = 0.15;
	}

	Pasha.balance_diff -= Pasha.balance * tax_rate;
}



void random_shoping() {

	int random_coefficient = std :: rand();

	if ((random_coefficient % 100) > 60) {
		if (Pasha.balance >= random_coefficient % 5000) {
			Pasha.balance_diff -= random_coefficient % 5000;
			Pasha.health += 0.00001;
		}
		else {
			Pasha.balance_diff = 0;
			Pasha.health -= 0.000001;
		}
	}
}



void new_year() {

	int random_coefficient = std::rand();

	if (!(now_date.month == 12 && now_date.day == 31)) {
		return;
	}
	if (Pasha.balance >= (random_coefficient % 5000)*Pasha.friends) {
		Pasha.balance_diff -= (random_coefficient % 5000)*Pasha.friends;
	}
	else {
		Pasha.health -= 0.000001 * Pasha.friends;
		Pasha.friends -= 1;
	}
}



void eight_march() {

	int random_coefficient = std::rand();

	if (!(now_date.month == 3 && now_date.day == 8)) {
		return;
	}
	if (Pasha.balance >= (random_coefficient % 5000)*Pasha.friends/2) {
		Pasha.balance_diff -= (random_coefficient % 5000)*Pasha.friends/2;
	} else {
		Pasha.health -= 0.000001 * Pasha.friends / 2;
		Pasha.friends -= 1;
	}
}



void twenty_three_february() {

	int random_coefficient = std::rand();

	if (!(now_date.month == 2 && now_date.day == 23)) {
		return;
	}
	if (Pasha.balance >= (random_coefficient % 5000)*Pasha.friends/2) {
		Pasha.balance_diff -= (random_coefficient % 5000)*Pasha.friends/2;
	} else {
		Pasha.health -= 0.000001 * Pasha.friends / 2;
		Pasha.friends -= 1;
	}
}


void valentines_day() {
	if (now_date.month == 2 && now_date.day == 14) {
		RUB expense = 2000;
		if (Pasha.balance >= expense) {
			Pasha.balance_diff -= expense;
			Pasha.health += 0.00002;
		} else {
			Pasha.health -= 0.00001;
		}
	}
}


void labor_day() {
	if (now_date.month == 5 && now_date.day == 1) {
		RUB expense = 1000;
		if (Pasha.balance >= expense) {
			Pasha.balance_diff -= expense;
			Pasha.health += 0.00001;
		} else {
			Pasha.health -= 0.000005;
		}
	}
}


void victory_day() {
	if (now_date.month == 5 && now_date.day == 9) {
		RUB expense = 500;
		if (Pasha.balance >= expense) {
			Pasha.balance_diff -= expense;
			Pasha.health += 0.00001;
		} else {
			Pasha.health -= 0.000005;
		}
	}
}


void halloween() {
	if (now_date.month == 10 && now_date.day == 31) {
		RUB expense = 1000;
		if (Pasha.balance >= expense) {
			Pasha.balance_diff -= expense;
			Pasha.health += 0.000005;
		} else {
			Pasha.health -= 0.00001;
		}
	}
}

void student_day() {
	if (now_date.month == 1 && now_date.day == 25) {
		int age = now_date.year - start_date.year + Pasha.age_start;
		if (age >= 18 && age <= 25) {
			RUB expense = 1500;
			if (Pasha.balance >= expense) {
				Pasha.balance_diff -= expense;
				Pasha.health += 0.00002;
			} else {
				Pasha.health -= 0.000015;
			}
		} else {
			RUB expense = 800;
			if (Pasha.balance >= expense) {
				Pasha.balance_diff -= expense;
				Pasha.health += 0.000005;
			} else {
				Pasha.health -= 0.000005;
			}
		}
	}
}


void maslenitsa() {
	if (now_date.month == 2 && now_date.day == 20) {
		RUB expense = 1200;
		if (Pasha.balance >= expense) {
			Pasha.balance_diff -= expense;
			Pasha.health += 0.00001;
		} else {
			Pasha.health -= 0.000008;
		}
	}
}


void friends_birthdays() {

	int random_coefficient = std::rand();

	if (!(now_date.month == 12 && now_date.day == 31)) {
		return;
	}
	if (Pasha.balance >= (random_coefficient % 5000)*Pasha.friends) {
		Pasha.balance_diff -= (random_coefficient % 5000)*Pasha.friends;
	} else {
		Pasha.health -= 0.000001 * Pasha.friends;
		Pasha.friends -= 1;
	}
}


void birthday_gifts() {
	if (now_date.month == 1 && now_date.day == 1) {
		RUB gift = Pasha.friends * 500;
		if (gift > 0) {
			Pasha.balance_diff += gift;
			Pasha.health += 0.00002;
		}
	}
}


void new_friends() {

	int random_coefficient = std::rand();

	if (random_coefficient%300 == 0) {
		Pasha.friends += 1;
	}
}


void society() {
	if (!(now_date.day == 1)) {
		return;
	}
	Pasha.health += 0.0005 * Pasha.friends;
}


void dead_check() {
	if (Pasha.health <= 0) {
		Pasha.life = 0;
	}
}


void cat() {
	if (Pasha.cat_life && Pasha.balance >= 1200) {
		Pasha.balance_diff -= 1200;
		Pasha.health += 0.00001;
	}
	else {
		Pasha.cat_life = 0;
	}
}


void dog() {
	if (Pasha.dog_life && Pasha.balance >= 1200) {
		Pasha.balance_diff -= 1200;
		Pasha.health += 0.00001;
	}
	else {
		Pasha.dog_life = 0;
	}
}


void buying_a_car() {
	if (Pasha.balance <= 1000000 * (Pasha.car_grade+1) || (Pasha.car_grade >= 6)) {
		return;
	}
	Pasha.balance_diff -= 1000000 * (Pasha.car_grade+1);
	Pasha.car_grade += 1;
}


void car_expenses() {
	if (!(now_date.day == 1) || (Pasha.car_grade == 0)) {
		return;
	}
	if (Pasha.car_grade == 1) {
		if (Pasha.balance >= Granta.gasoline_expense + Granta.repair_expense) {
			Pasha.balance_diff -= Granta.gasoline_expense;
			Pasha.balance_diff -= Granta.repair_expense;
			Pasha.health += Granta.mental_satisfaction;
		}
		else {
			Pasha.car_grade -= 1;
			Pasha.balance_diff += 500000 * (Pasha.car_grade + 1);
		}
	}
	else if (Pasha.car_grade == 2) {
		if (Pasha.balance >= Vesta.gasoline_expense + Vesta.repair_expense) {
			Pasha.balance_diff -= Vesta.gasoline_expense;
			Pasha.balance_diff -= Vesta.repair_expense;
			Pasha.health += Vesta.mental_satisfaction;
		}
		else {
			Pasha.car_grade -= 1;
			Pasha.balance_diff += 500000 * (Pasha.car_grade + 1);
		}
	}
	else if (Pasha.car_grade == 3) {
		if (Pasha.balance >= Polo.gasoline_expense + Polo.repair_expense) {
			Pasha.balance_diff -= Polo.gasoline_expense;
			Pasha.balance_diff -= Polo.repair_expense;
			Pasha.health += Polo.mental_satisfaction;
		}
		else {
			Pasha.car_grade -= 1;
			Pasha.balance_diff += 500000 * (Pasha.car_grade + 1);
		}
	}
	else if (Pasha.car_grade == 4) {
		if (Pasha.balance >= Superb.gasoline_expense + Superb.repair_expense) {
			Pasha.balance_diff -= Superb.gasoline_expense;
			Pasha.balance_diff -= Superb.repair_expense;
			Pasha.health += Superb.mental_satisfaction;
		}
		else {
			Pasha.car_grade -= 1;
			Pasha.balance_diff += 500000 * (Pasha.car_grade + 1);
		}
	}
	else if (Pasha.car_grade == 5) {
		if (Pasha.balance >= m_911.gasoline_expense + m_911.repair_expense) {
			Pasha.balance_diff -= m_911.gasoline_expense;
			Pasha.balance_diff -= m_911.repair_expense;
			Pasha.health += m_911.mental_satisfaction;
		}
		else {
			Pasha.car_grade -= 1;
			Pasha.balance_diff += 500000 * (Pasha.car_grade + 1);
		}
	}
	else if (Pasha.car_grade == 6) {
		if (Pasha.balance >= Urus.gasoline_expense + Urus.repair_expense) {
			Pasha.balance_diff -= Urus.gasoline_expense;
			Pasha.balance_diff -= Urus.repair_expense;
			Pasha.health += Urus.mental_satisfaction;
		}
		else {
			Pasha.car_grade -= 1;
			Pasha.balance_diff += 500000 * (Pasha.car_grade + 1);
		}
	}
}


void car() {
	car_expenses();
	buying_a_car();
}


void Holidays() {
	new_year();
	friends_birthdays();
	eight_march();
	twenty_three_february();
	birthday_gifts();
	valentines_day();
	labor_day();
	victory_day();
	halloween();
	student_day();
	maslenitsa();
}


void seasonal_cold() {
	int month = now_date.month;
	if (month == 12 || month == 1 || month == 2) {
		if (std::rand() % 100 < 15) {
			Pasha.health -= 0.00001;
		}
	} else if (month == 3 || month == 4 || month == 10 || month == 11) {
		if (std::rand() % 100 < 8) {
			Pasha.health -= 0.000005;
		}
	}
}


void junk_food_overeating() {
	if (std::rand() % 100 < 5) {
		RUB cost = 400 + (std::rand() % 600);
		if (Pasha.balance >= cost) {
			Pasha.balance_diff -= cost;
			Pasha.health -= 0.000012;
		} else {
			Pasha.health -= 0.000002;
		}
	}
}


void social_media() {
	int random_coefficient = std::rand() % 100;
	if (random_coefficient < 10) {
		int new_friends = (std::rand() % 3) + 1;
		Pasha.friends += new_friends;
		Pasha.health += 0.00001;
	} else if (random_coefficient < 15) {
		if (Pasha.friends > 0) Pasha.friends -= 1;
		Pasha.health -= 0.00002;
	} else {
		Pasha.health -= 0.000001;
	}
}


void charity() {
	int random_coefficient = std::rand();
	int chance = random_coefficient % 100;
	if (chance < 10) {
		RUB amount = (random_coefficient % 5000) + 1000;
		std::cout << "A charity organization asks for a donation of " << amount << " RUB." << std::endl;
		std::cout << "Donate? (1 = Yes / 0 = No): ";
		std::cin >> Pasha.event_decision;
		if (Pasha.event_decision == 1 && Pasha.balance >= amount) {
			Pasha.balance_diff -= amount;
			Pasha.health += 0.00002;
			std::cout << "You donated. You feel a warm glow inside." << std::endl;
		} else if (Pasha.event_decision == 1 && Pasha.balance < amount) {
			std::cout << "You don't have enough money. The charity worker looks disappointed." << std::endl;
		} else {
			std::cout << "You declined. A small pang of guilt..." << std::endl;
			Pasha.health -= 0.000005;
		}
		std::cout << "--------------" << std::endl;
	}
}


void seasonal_discounts() {
	if (now_date.day == 15) {
		RUB saving = std::rand() % 1000 + 200;
		Pasha.balance_diff += saving;
		Pasha.health += 0.000001;
	}
}


void pollution() {
	if (std::rand() % 100 < 30) {
		Pasha.health -= 0.000001;
	}
}


void sedentary_work() {
	if (now_date.year - start_date.year + Pasha.age_start >= 18 && now_date.year - start_date.year + Pasha.age_start < 65) {
		Pasha.health -= 0.0000002;
	}
}


void noise_pollution() {
	if (std::rand() % 100 < 20) {
		Pasha.health -= 0.0000005;
	}
}


void public_transport() {
	if (now_date.day == 1 && Pasha.car_grade == 0) {
		RUB monthly_pass = 2000;
		if (Pasha.balance >= monthly_pass) {
			Pasha.balance_diff -= monthly_pass;
		} else {
			Pasha.balance_diff -= Pasha.balance;
			Pasha.health -= 0.000005;
		}
	}
}


void mental_break() {
	if (Pasha.health < 3.0 && now_date.day == 20) {
		std::cout << "Your health is critical. You need to take a mental break for a week." << std::endl;
		std::cout << "Take time off? (1 = Yes / 0 = No)" << std::endl;
		std::cin >> Pasha.event_decision;
		if (Pasha.event_decision == 1) {
			Pasha.health += 0.0002;
			Pasha.balance_diff -= Pasha.salary_RUB / 4;
			std::cout << "You rested and feel better, but lost a week's salary." << std::endl;
		} else {
			Pasha.health -= 0.0001;
			std::cout << "You pushed through, but your health worsened." << std::endl;
		}
		std::cout << "--------------" << std::endl;
	}
}


void appliance_repair() {
	if (std::rand() % 1000 < 15) {
		RUB cost = (std::rand() % 5000) + 2000;
		if (Pasha.balance >= cost) {
			Pasha.balance_diff -= cost;
		} else {
			Pasha.balance_diff -= Pasha.balance;
			Pasha.health -= 0.000008;
		}
	}
}


void utilities() {
	if (now_date.day == 1) {
		RUB bill = 5000;
		if (now_date.month == 12 || now_date.month == 1 || now_date.month == 2) {
			bill = 8000;
		}
		if (Pasha.balance >= bill) {
			Pasha.balance_diff -= bill;
		} else {
			Pasha.balance_diff -= Pasha.balance;
			Pasha.health -= 0.00002;
		}
	}
}

void bank_service_fee() {
	if (now_date.day == 1) {
		if (Pasha.balance >= 500) {
			Pasha.balance_diff -= 500;
		} else {
			Pasha.balance_diff -= Pasha.balance;
		}
	}
}


void car_insurance() {
	if (now_date.day == 1 && Pasha.car_grade > 0) {
		if (Pasha.balance >= 3000 + (Pasha.car_grade - 1) * 1000) {
			Pasha.balance_diff -= 3000 + (Pasha.car_grade - 1) * 10000;
		} else {
			Pasha.health -= 0.00001;
			Pasha.car_grade = 0;
		}
	}
}


void coffee_habit() {
	RUB coffee_price = 200;
	if (Pasha.balance >= coffee_price) {
		Pasha.balance_diff -= coffee_price;
		Pasha.health += 0.000001;
	} else {
		Pasha.health -= 0.0000005;
	}
}


void burnout() {
	if (Pasha.salary_RUB > 200000 && Pasha.health < 6.0 && (std::rand() % 100 < 3)) {
		Pasha.health -= 0.00002;
		std::cout << "You're feeling exhausted from work. Take a break?" << std::endl;
		std::cout << "Spend 20000 RUB on a spa? (1 = Yes / 0 = No)" << std::endl;
		std::cin >> Pasha.event_decision;
		if (Pasha.event_decision == 1 && Pasha.balance >= 20000) {
			Pasha.balance_diff -= 20000;
			Pasha.health += 0.00003;
			std::cout << "You relaxed and feel better" << std::endl;
		} else if (Pasha.event_decision == 1) {
			std::cout << "Not enough money. Stress continues" << std::endl;
		} else {
			std::cout << "You ignore the stress, health decreases further" << std::endl;
			Pasha.health -= 0.0002;
		}
		std::cout << "--------------" << std::endl;
	}
}



void streaming_subscription() {
	if (now_date.day == 1) {
		RUB cost = 800;
		if (Pasha.balance >= cost) {
			Pasha.balance_diff -= cost;
			Pasha.health += 0.000005;
		} else {
			Pasha.health -= 0.000002;
		}
	}
}


void insomnia() {
	if (std::rand() % 100 < 5) {
		Pasha.health -= 0.00001;
	}
}


void communication_fee() {
	if (now_date.day == 1) {
		RUB fee = 800;
		if (Pasha.balance >= fee) {
			Pasha.balance_diff -= fee;
		} else {
			Pasha.balance_diff -= Pasha.balance;
			Pasha.health -= 0.000005;
		}
	}
}


void public_events() {
	int chance = std::rand() % 100;
	if (chance < 2) {
		int friends_gain = (std::rand() % 2) + 1;
		Pasha.friends += friends_gain;
		Pasha.health += 0.00003;
	}
}


void random_weather_mental_effect() {
	if (now_date.month == 12 || now_date.month == 1 || now_date.month == 2) {
		if (std::rand() % 100 < 20) {
			Pasha.health -= 0.000005;
		}
	}
	else if (now_date.month == 6 || now_date.month == 7 || now_date.month == 8) {
		if (std::rand() % 100 < 15) {
			Pasha.health -= 0.000003;
		}
	}
	else {
		if (std::rand() % 100 < 10) {
			Pasha.health -= 0.000002;
		}
	}
}


void seasonal_clothing_update() {
	if ((now_date.month == 3 && now_date.day == 15) || (now_date.month == 9 && now_date.day == 15)) {
		RUB cost = 5000;
		if (Pasha.balance >= cost) {
			Pasha.balance_diff -= cost;
			Pasha.health += 0.00001;
		} else {
			Pasha.health -= 0.000008;
		}
	}
}


void online_shopping_discount() {
	if (std::rand() % 100 < 3) {
		if (Pasha.balance >= 3000) {
			Pasha.balance_diff -= 3000;
			Pasha.health += 0.00002;
		}
	}
}

//////////////////////////////////Event_Mechanics////////////////////////////////////////////////////////////////

void event_1_find_5000() {
	std :: cout << "You found 5000 rubles" << std::endl;
	std :: cout << "take it? (1 = Yes / 0 = No)" << std::endl;
	std :: cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		int random_coefficient = std::rand();
		if (random_coefficient%100 >= 51) {
			std :: cout << "You get 5000 RUB" << std::endl;
			Pasha.balance_diff += 5000;
		}
		else {
			std :: cout << "It's fake" << std::endl;
			Pasha.health -= 0.000001;
		}
	}
	std :: cout << "--------------" << std::endl;
}


void event_2_find_2000() {
	std :: cout << "You found 2000 rubles" << std::endl;
	std :: cout << "take it? (1 = Yes / 0 = No)" << std::endl;
	std :: cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		int random_coefficient = std::rand();
		if (random_coefficient%100 >= 31) {
			std :: cout << "You get 2000 RUB" << std::endl;
			Pasha.balance_diff += 2000;
		}
		else {
			std :: cout << "It's fake" << std::endl;
			Pasha.health -= 0.0000001;
		}
	}
	std :: cout << "--------------" << std::endl;
}



void event_3_find_1000() {
	std :: cout << "You found 1000 rubles" << std::endl;
	std :: cout << "take it? (1 = Yes / 0 = No)" << std::endl;
	std :: cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		int random_coefficient = std::rand();
		if (random_coefficient%100 >= 11) {
			std :: cout << "You get 1000 RUB" << std::endl;
			Pasha.balance_diff += 1000;
		}
		else {
			std :: cout << "It's fake" << std::endl;
			Pasha.health -= 0.00000001;
		}
	}
	std :: cout << "--------------" << std::endl;
}


void event_4_lost_5000() {
	std :: cout << "You lost 5000 RUB(" << std :: endl;
	Pasha.balance_diff -= 5000;
	std :: cout << "--------------" << std::endl;
}


void event_5_lost_2000() {
	std :: cout << "You lost 2000 RUB(" << std :: endl;
	Pasha.balance_diff -= 2000;
	std :: cout << "--------------" << std::endl;
}


void event_6_lost_1000() {
	std :: cout << "You lost 1000 RUB(" << std :: endl;
	Pasha.balance_diff -= 1000;
	std :: cout << "--------------" << std::endl;
}


void event_7_finding_a_dog() {
	std :: cout << "You found a dog" << std :: endl;
	Pasha.dog_life = 1;
	std :: cout << "--------------" << std::endl;
}


void event_8_finding_a_cat() {
	std :: cout << "You found a cat" << std :: endl;
	Pasha.cat_life = 1;
	std :: cout << "--------------" << std::endl;
}


void event_9_lottery() {
	std :: cout << "Do you want to buy a lottery ticket? (1 = Yes / 0 = No)" << std :: endl;
	std :: cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		int random_coefficient_1 = std::rand();
		int random_coefficient_2 = std::rand();
		if (random_coefficient_1 % 1000 == random_coefficient_2 % 1000) {
			std :: cout << "You won!" << std::endl;
			std :: cout << "You get " << random_coefficient_1 * random_coefficient_2 * 10000 << " RUB!" << std::endl;
			Pasha.balance_diff += random_coefficient_1 * random_coefficient_2 * 10000;
		}
		else {
			std :: cout << "You lose(" << std::endl;
			Pasha.health -= 0.0000001;
		}
	}
	std :: cout << "--------------" << std::endl;
}


void event_10_found_purse() {
	std::cout << "You found a wallet with 5000 rubles" << std :: endl;
	std::cout << "Take it for yourself? (1 = Yes / 0 = No)" << std :: endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		int random_coefficient = std::rand() % 100;
		if (random_coefficient <= 91) {
			std::cout << "You get 5000 RUB" << std :: endl;
			Pasha.balance_diff += 5000;
		} else {
			std::cout << "You have been noticed!" << std :: endl;
			std::cout << "You were fined 2000 rubles" << std :: endl;
			Pasha.health -= 0.00001;
			Pasha.balance_diff -= 2000;
		}
	} else {
		std :: cout << "You found the owner and returned the wallet to him" << std :: endl;
		std :: cout << "You were thanked!" << std :: endl;
		Pasha.health += 0.000005;
	}
	std::cout << "--------------" << std :: endl;
}


void event_11_investment() {
	std::cout << "You are offered to invest 10000 rubles in a promising startup" << std::endl;
	std::cout << "Agree? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance < 10000) {
			std::cout << "You don't have enough money!" << std::endl;
		} else {
			Pasha.balance_diff -= 10000;
			int random_coefficient = std::rand() % 100;
			if (random_coefficient < 30) {
				std::cout << "The startup took off! You get 50000 rubles" << std::endl;
				Pasha.balance_diff += 50000;
			} else {
				std::cout << "The startup failed. Money lost" << std::endl;
				Pasha.health -= 0.00002;
			}
		}
	} else {
		std::cout << "You refused. No risk" << std::endl;
	}
	std::cout << "--------------" << std::endl;
}


void event_12_promotion() {
	std::cout << "You got a promotion at work! Salary increased by 10%!" << std::endl;
	Pasha.salary_RUB = Pasha.salary_RUB * 1.1;
	std::cout << "New salary: " << Pasha.salary_RUB << " RUB" << std::endl;
	Pasha.health += 0.00003;
	std::cout << "--------------" << std::endl;
}


void event_13_accident() {
	std::cout << "You had a minor accident" << std::endl;
	if (Pasha.car_grade > 0) {
		std::cout << "Your car is damaged. Repairs will cost " << 20000 * Pasha.car_grade << " RUB" << std::endl;
		if (Pasha.balance >= 20000 * Pasha.car_grade) {
			Pasha.balance_diff -= 20000 * Pasha.car_grade;
		} else {
			std::cout << "Not enough money for repairs; you have to sell the car" << std::endl;
			Pasha.car_grade = 0;
			Pasha.balance_diff += 500000 * Pasha.car_grade;
		}
	} else {
		std::cout << "You don't have a car, but you spent 5000 RUB on taxi and treatment" << std::endl;
		Pasha.balance_diff -= 5000;
	}
	Pasha.health -= 0.00002;
	std::cout << "--------------" << std::endl;
}


void event_14_friend_loan() {
	std::cout << "A friend asks to borrow 5000 rubles" << std::endl;
	std::cout << "Lend? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 5000) {
			Pasha.balance_diff -= 5000;
			std::cout << "Your friend is grateful. Your relationship strengthened!" << std::endl;
			Pasha.friends += 1;
			Pasha.health += 0.00001;
		} else {
			std::cout << "You don't have the money to help" << std::endl;
			Pasha.health -= 0.000005;
		}
	} else {
		std::cout << "You refused. Your friend is offended" << std::endl;
		if (Pasha.friends > 0) Pasha.friends -= 1;
		Pasha.health -= 0.00002;
	}
	std::cout << "--------------" << std::endl;
}


void event_15_health_crisis() {
	std::cout << "You feel very unwell. You need medicine" << std::endl;
	std::cout << "Buy medicine for 3000 RUB? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 3000) {
			Pasha.balance_diff -= 3000;
			Pasha.health -= 0.00005;
			std::cout << "You bought medicine, but the illness took its toll" << std::endl;
		} else {
			std::cout << "You don't have money for medicine. Your Pasha.health worsened significantly" << std::endl;
			Pasha.health -= 0.0002;
		}
	} else {
		std::cout << "You decided to tough it out. Your Pasha.health dropped" << std::endl;
		Pasha.health -= 0.0001;
	}
	std::cout << "--------------" << std::endl;
}


void event_16_competition_win() {
	std::cout << "You won an amateur competition (photo, poetry, etc.)!" << std::endl;
	std::cout << "Prize: 20000 RUB. Donate to charity? (1 = Take prize / 0 = Donate)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		std::cout << "You took the prize. +20000 RUB" << std::endl;
		Pasha.balance_diff += 20000;
	} else {
		std::cout << "You donated the prize to charity. You feel great!" << std::endl;
		Pasha.health += 0.0002;
	}
	std::cout << "--------------" << std::endl;
}


void event_17_pet_illness() {
	if (!Pasha.cat_life && !Pasha.dog_life) {
		return;
	}
	std::cout << "Your pet is sick!" << std::endl;
	std::cout << "Treatment costs 3000 RUB. Pay? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 3000) {
			Pasha.balance_diff -= 3000;
			std::cout << "You paid for treatment. Your pet is healthy again" << std::endl;
			Pasha.health += 0.00001;
		} else {
			std::cout << "You don't have enough money. Your pet..." << std::endl;
			if (Pasha.cat_life) {
				Pasha.cat_life = 0;
			}
			if (Pasha.dog_life) {
				Pasha.dog_life = 0;
			}
			Pasha.health -= 0.0001;
		}
	} else {
		std::cout << "You refused treatment. Your pet..." << std::endl;
		if (Pasha.cat_life) {
			Pasha.cat_life = 0;
		}
		if (Pasha.dog_life) {
			Pasha.dog_life = 0;
		}
		Pasha.health -= 0.0002;
	}
	std::cout << "--------------" << std::endl;
}


void event_18_bonus() {
	std::cout << "You received a bonus at work for excellent performance!" << std::endl;
	RUB bonus = (Pasha.salary_RUB * 0.5);
	bonus = bonus/10;
	std::cout << "Bonus amount: " << bonus << " RUB. Accept? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		Pasha.balance_diff += bonus;
		std::cout << "You accepted the bonus" << std::endl;
	} else {
		std::cout << "You declined the bonus to show loyalty. The boss is impressed" << std::endl;
		Pasha.health += 0.00015;
	}
	std::cout << "--------------" << std::endl;
}


void event_19_robbery() {
	std::cout << "Someone snatched your wallet!" << std::endl;
	std::cout << "Try to catch the thief? (1 = Yes / 0 = No )" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		int random_coefficient = std::rand() % 100;
		if (random_coefficient >= 61) {
			std::cout << "You caught the thief and got your wallet back!" << std::endl;
			Pasha.health += 0.00001;
		} else {
			std::cout << "You tripped and fell. The thief got away, and you're injured" << std::endl;
			Pasha.health -= 0.0001;
			Pasha.balance_diff -= 3000;
		}
	} else {
		std::cout << "You let it go. You lost about 5000 RUB." << std::endl;
		Pasha.balance_diff -= 5000;
		Pasha.health -= 0.00001;
	}
	std::cout << "--------------" << std::endl;
}


void event_20_networking_on_conference() {
	std::cout << "At a conference, you met interesting people" << std::endl;
	std::cout << "Spend 2000 RUB on a joint dinner to build relationships? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 2000) {
			Pasha.balance_diff -= 2000;
			int random_coefficient = std::rand();
			std::cout << "You had a great time and made new Pasha.friends" << std::endl;
			Pasha.friends += random_coefficient%5;
			Pasha.health += 0.00002;
		} else {
			std::cout << "You don't have enough money. Opportunity lost" << std::endl;
		}
	} else {
		std::cout << "You politely declined. No change" << std::endl;
	}
	std::cout << "--------------" << std::endl;
}


void event_21_inheritance() {
	std::cout << "A distant relative left you an inheritance of 100000 RUB" << std::endl;
	std::cout << "But you must pay 13% tax. Accept? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	int random_coefficient = std :: rand();

	if (Pasha.event_decision == 1) {
		RUB tax = 13000;
		if (Pasha.balance >= tax) {
			Pasha.balance_diff -= tax;
			if (random_coefficient%100 >= 81) {
				Pasha.balance_diff += 100000;
				std::cout << "You paid the tax and received the inheritance. Net gain: 87000 RUB" << std::endl;
			}
			else {
				std::cout << "its scam(" << std::endl;
			}
		} else {
			std::cout << "You don't have enough money to pay the tax. Inheritance lost" << std::endl;
			Pasha.health -= 0.00002;
		}
	} else {
		std::cout << "You declined the inheritance" << std::endl;
	}
	std::cout << "--------------" << std::endl;
}


void event_22_marathon() {
	std::cout << "A friend invites you to a charity marathon" << std::endl;
	std::cout << "Entry fee is 2000 RUB. Participate? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 2000) {
			Pasha.balance_diff -= 2000;
			std::cout << "You ran the marathon! You feel healthier and happier." << std::endl;
			Pasha.health += 0.0001;
			Pasha.friends += 1;
		} else {
			std::cout << "Not enough money to register" << std::endl;
		}
	} else {
		std::cout << "You decided not to go" << std::endl;
	}
	std::cout << "--------------" << std::endl;
}


void event_23_friend_gift() {
	std::cout << "A close friend gives you a gift: 5000 RUB." << std::endl;
	std::cout << "Accept the gift? (1 = Yes / 0 = Politely refuse)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		Pasha.balance_diff += 5000;
		std::cout << "You accept the gift. +5000 RUB" << std::endl;
		Pasha.health += 0.00002;
	} else {
		std::cout << "You politely refuse, saying you don't need money. Your friend respects you even more." << std::endl;
		Pasha.friends += 1;
		Pasha.health += 0.00001;
	}
	std::cout << "--------------" << std::endl;
}


void event_24_medical_emergency() {
	std::cout << "You experience a sudden medical emergency!" << std::endl;
	std::cout << "Pay 8000 RUB for immediate treatment? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 8000) {
			Pasha.balance_diff -= 8000;
			std::cout << "You paid for treatment. Your health stabilizes" << std::endl;
			Pasha.health -= 0.00005;
		} else {
			std::cout << "You don't have enough money! The condition worsens" << std::endl;
			Pasha.health -= 0.0003;
		}
	} else {
		std::cout << "You decide to wait it out. Your health suffers severely" << std::endl;
		Pasha.health -= 0.0002;
	}
	std::cout << "--------------" << std::endl;
}


void event_25_car_upgrade_discount() {
	if (Pasha.car_grade >= 6) {
		return;
	}
	int next_grade = Pasha.car_grade + 1;
	RUB full_price = 1000000 * next_grade;
	RUB discount_price = full_price * 0.7;
	std::cout << "A car dealership offers you a 30% discount on upgrading to the next car!" << std::endl;
	std::cout << "Next car normally costs " << full_price << " RUB, now only " << discount_price << " RUB" << std::endl;
	std::cout << "Buy the upgrade? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= discount_price) {
			Pasha.balance_diff -= discount_price;
			Pasha.car_grade += 1;
			std::cout << "Congratulations! You upgraded your car" << std::endl;
			Pasha.health += 0.00005;
		} else {
			std::cout << "Not enough money. Opportunity lost" << std::endl;
		}
	} else {
		std::cout << "You decline the offer" << std::endl;
	}
	std::cout << "--------------" << std::endl;
}


void event_26_scam_call() {
	std::cout << "You receive a call from a 'bank employee' claiming suspicious activity on your account" << std::endl;
	std::cout << "They ask you to transfer 3000 RUB to a 'secure account' to protect your money" << std::endl;
	std::cout << "Do you follow the instructions? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 3000) {
			Pasha.balance_diff -= 3000;
			std::cout << "You transferred the money and later realize it was a scam. You lost 3000 RUB" << std::endl;
			Pasha.health -= 0.00003;
		} else {
			std::cout << "You try to transfer but don't have enough money. The scammer hangs up. Lucky escape" << std::endl;
			Pasha.health -= 0.00001;
		}
	} else {
		std::cout << "You recognize the scam and hang up. Smart decision!" << std::endl;
		Pasha.health += 0.00001;
	}
	std::cout << "--------------" << std::endl;
}


void event_27_lucky_ticket() {
	std::cout << "You find a lottery ticket on the ground" << std::endl;
	std::cout << "Check if it's a winner? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		int random_coefficient = std::rand() % 100;
		if (random_coefficient < 5) {
			int win_amount = (std::rand() % 20000) + 5000;
			std::cout << "It's a winning ticket! You get " << win_amount << " RUB!" << std::endl;
			Pasha.balance_diff += win_amount;
			Pasha.health += 0.00005;
		} else {
			std::cout << "It's just a losing ticket. Too bad" << std::endl;
			Pasha.health -= 0.000005;
		}
	} else {
		std::cout << "You throw the ticket away without checking. You'll never know" << std::endl;
	}
	std::cout << "--------------" << std::endl;
}


void event_28_surprise_party() {
	std::cout << "Your friends throw a surprise party for you!" << std::endl;
	std::cout << "They've spent 3000 RUB on decorations and gifts" << std::endl;
	std::cout << "Do you want to reimburse them? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 3000) {
			Pasha.balance_diff -= 3000;
			std::cout << "You repay your friends. They appreciate your generosity" << std::endl;
			Pasha.friends += 2;
			Pasha.health += 0.00003;
		} else {
			std::cout << "You'd like to pay but don't have enough money. Your friends understand" << std::endl;
			Pasha.health += 0.00002;
		}
	} else {
		std::cout << "You happily accept the surprise. Your friendships grow stronger" << std::endl;
		Pasha.friends += 1;
		Pasha.health += 0.00005;
	}
	std::cout << "--------------" << std::endl;
}


void event_29_crypto_investment() {
	std::cout << "A colleague suggests investing 20000 RUB in a new cryptocurrency" << std::endl;
	std::cout << "Invest? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 20000) {
			Pasha.balance_diff -= 20000;
			int random_coefficient = std::rand() % 100;
			if (random_coefficient < 15) {
				RUB win = 20000 + (std::rand() % 80000);
				std::cout << "The crypto skyrockets! You gain " << win << " RUB" << std::endl;
				Pasha.balance_diff += win;
				Pasha.health += 0.0001;
			} else if (random_coefficient < 40) {
				RUB win = 5000 + (std::rand() % 15000);
				std::cout << "The crypto performs well. You earn " << win << " RUB" << std::endl;
				Pasha.balance_diff += win;
				Pasha.health += 0.00002;
			} else if (random_coefficient < 70) {
				std::cout << "The crypto stays flat. You get your money back" << std::endl;
				Pasha.balance_diff += 20000;
			} else {
				std::cout << "The crypto crashes! You lose your investment" << std::endl;
				Pasha.health -= 0.00008;
			}
		} else {
			std::cout << "You don't have enough money to invest." << std::endl;
		}
	} else {
		std::cout << "You decline, avoiding the risk." << std::endl;
	}
	std::cout << "--------------" << std::endl;
}


void event_30_family_visit() {
	std::cout << "Your parents invite you for a weekend visit" << std::endl;
	std::cout << "Travel and gifts will cost about 5000 RUB. Go? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 5000) {
			Pasha.balance_diff -= 5000;
			std::cout << "You spend quality time with family. Your mood improves" << std::endl;
			Pasha.health += 0.00007;
			Pasha.friends += 1;
		} else {
			std::cout << "You'd love to go but can't afford it. You feel a bit sad" << std::endl;
			Pasha.health -= 0.00002;
		}
	} else {
		std::cout << "You decide to stay home. Your parents are a little disappointed" << std::endl;
		if (Pasha.friends > 0) Pasha.friends -= 1;
		Pasha.health -= 0.00001;
	}
	std::cout << "--------------" << std::endl;
}


void event_31_antique_find() {
	std::cout << "You find an old painting in a thrift store for 1000 RUB" << std::endl;
	std::cout << "Buy it? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 1000) {
			Pasha.balance_diff -= 1000;
			int random_coefficient = std::rand() % 100;
			if (random_coefficient < 20) {
				RUB value = 50000 + (std::rand() % 200000);
				std::cout << "It's a valuable antique! You sell it for " << value << " RUB" << std::endl;
				Pasha.balance_diff += value;
				Pasha.health += 0.0001;
			} else if (random_coefficient < 50) {
				RUB value = 5000 + (std::rand() % 20000);
				std::cout << "It's a decent find. You sell it for " << value << " RUB" << std::endl;
				Pasha.balance_diff += value;
				Pasha.health += 0.00002;
			} else {
				std::cout << "It's a worthless copy. You lost 1000 RUB" << std::endl;
				Pasha.health -= 0.00001;
			}
		} else {
			std::cout << "Not enough money to buy it" << std::endl;
		}
	} else {
		std::cout << "You pass on the painting. Someone else buys it later" << std::endl;
	}
	std::cout << "--------------" << std::endl;
}


void event_32_work_mistake() {
	std::cout << "You made a mistake at work that cost the company money" << std::endl;
	std::cout << "Your boss gives you a choice: pay a 10000 RUB fine or accept a 5% salary cut" << std::endl;
	std::cout << "Choose: (1 = Pay fine / 0 = Accept salary cut)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 10000) {
			Pasha.balance_diff -= 10000;
			std::cout << "You pay the fine. Your boss respects your responsibility" << std::endl;
			Pasha.health -= 0.00002;
		} else {
			std::cout << "You can't afford the fine, so you're forced to take the salary cut" << std::endl;
			Pasha.salary_RUB = Pasha.salary_RUB * 0.95;
			Pasha.health -= 0.00005;
		}
	} else {
		std::cout << "You accept the salary cut. It will be tough for a while" << std::endl;
		Pasha.salary_RUB = Pasha.salary_RUB * 0.95;
		Pasha.health -= 0.00004;
	}
	std::cout << "--------------" << std::endl;
}


void event_33_education_course() {
	std::cout << "You have an opportunity to take a professional course" << std::endl;
	std::cout << "Cost: 15000 RUB. After completion, your salary will increase by 15%" << std::endl;
	std::cout << "Enroll? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 15000) {
			Pasha.balance_diff -= 15000;
			Pasha.salary_RUB *= 1.15;
			std::cout << "You started the course. Your salary now is " << Pasha.salary_RUB << " RUB" << std :: endl;
		}
		else {
			std::cout << "You don't have enough money for the course" << std::endl;
		}
	}
	else {
		std::cout << "You decide to skip the course" << std::endl;
	}
	std::cout << "--------------" << std::endl;
}


void event_34_public_transport_strike() {
	if (now_date.day == 1 && (now_date.month % 3 == 0) && (std::rand() % 100 < 40)) {
		std::cout << "Public transport strike today!" << std::endl;
		if (Pasha.car_grade == 0) {
			if (Pasha.balance >= 1000) {
				Pasha.balance_diff -= 1000;
				std::cout << "You took a taxi. Cost: " << 1000 << " RUB" << std::endl;
			} else {
				std::cout << "You had to walk. It was tiring" << std::endl;
				Pasha.health -= 0.00001;
			}
		} else {
			std::cout << "You used your car. No problem" << std::endl;
		}
		std::cout << "--------------" << std::endl;
	}
}


void event_35_language_learning() {
	std::cout << "You can enroll in a language course for " << 5000 << " RUB" << std::endl;
	std::cout << "It may improve your career prospects. Enroll? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		if (Pasha.balance >= 5000) {
			Pasha.balance_diff -= 5000;
			Pasha.health += 0.00001;
			if (std::rand() % 100 < 30) {
				Pasha.salary_RUB *= 1.05;
				std::cout << "Your new language skills impressed your boss! Salary increased by 5%!" << std::endl;
			} else {
				std::cout << "You started learning, but it will take time to see results" << std::endl;
			}
		} else {
			std::cout << "Not enough money for the course" << std::endl;
		}
	} else {
		std::cout << "You decided not to enroll" << std::endl;
	}
	std::cout << "--------------" << std::endl;
}


void event_36_volunteering() {
	std::cout << "A volunteer opportunity is available today." << std::endl;
	std::cout << "Participate? (1 = Yes / 0 = No)" << std::endl;
	std::cin >> Pasha.event_decision;
	if (Pasha.event_decision == 1) {
		Pasha.health += 0.00003;
		int new_friends = (std::rand() % 2) + 1;
		Pasha.friends += new_friends;
		std::cout << "You helped others and met " << new_friends << " new friend(s)!" << std::endl;
	} else {
		std::cout << "You stayed home." << std::endl;
	}
	std::cout << "--------------" << std::endl;
}


void event_37_dangerous_taxi() {
	if (Pasha.car_grade == 0) {
		std::cout << "You took a taxi, but the driver drove recklessly. Minor accident!" << std::endl;
		RUB cost = 2000 + (std::rand() % 3000);
		if (Pasha.balance >= cost) {
			Pasha.balance_diff -= cost;
		} else {
			Pasha.balance_diff -= Pasha.balance;
			Pasha.health -= 0.00002;
		}
		Pasha.health -= 0.00001;
		std::cout << "--------------" << std::endl;
	}
}


void event_38_contaminated_water() {
	if (std::rand() % 1000 < 3) {
		std::cout << "You drank contaminated water. You feel sick" << std::endl;
		RUB treatment = 2000 + (std::rand() % 3000);
		std::cout << "Go to the doctor? Cost: " << treatment << " RUB. (1 = Yes / 0 = No)" << std::endl;
		std::cin >> Pasha.event_decision;
		if (Pasha.event_decision == 1 && Pasha.balance >= treatment) {
			Pasha.balance_diff -= treatment;
			std::cout << "You got treatment and recovered" << std::endl;
		} else if (Pasha.event_decision == 1) {
			std::cout << "Not enough money. You suffer" << std::endl;
			Pasha.health -= 0.00003;
		} else {
			std::cout << "You try to ignore it, but it gets worse" << std::endl;
			Pasha.health -= 0.00005;
		}
		std::cout << "--------------" << std::endl;
	}
}


void random_events() {

	int random_coefficient = std::rand();

	int event = random_coefficient%100000;

	if (event == 1) {
		event_1_find_5000();
	}

	else if (event == 2) {
		event_2_find_2000();
	}

	else if (event == 3) {
		event_3_find_1000();
	}

	else if (event == 4) {
		event_4_lost_5000();
	}

	else if (event == 5) {
		event_5_lost_2000();
	}

	else if (event == 6) {
		event_6_lost_1000();
	}

	else if (event == 7) {
		event_7_finding_a_dog();
	}

	else if (event == 8) {
		event_8_finding_a_cat();
	}

	else if (event == 9) {
		event_9_lottery();
	}

	else if (event == 10) {
		event_10_found_purse();
	}

	else if (event == 11) {
		event_11_investment();
	}

	else if (event == 12) {
		event_12_promotion();
	}

	else if (event == 13) {
		event_13_accident();
	}

	else if (event == 14) {
		event_14_friend_loan();
	}

	else if (event == 15) {
		event_15_health_crisis();
	}

	else if (event == 16) {
		event_16_competition_win();
	}

	else if (event == 17) {
		event_17_pet_illness();
	}

	else if (event == 18) {
		event_18_bonus();
	}

	else if (event == 19) {
		event_19_robbery();
	}

	else if (event == 20) {
		event_20_networking_on_conference();
	}

	else if (event == 21) {
		event_21_inheritance();
	}

	else if (event == 22) {
		event_22_marathon();
	}

	else if (event == 23) {
		event_23_friend_gift();
	}

	else if (event == 24) {
		event_24_medical_emergency();
	}

	else if (event == 25) {
		event_25_car_upgrade_discount();
	}

	else if (event == 26) {
		event_26_scam_call();
	}

	else if (event == 27) {
		event_27_lucky_ticket();
	}

	else if (event == 28) {
		event_28_surprise_party();
	}

	else if (event == 29) {
		event_29_crypto_investment();
	}

	else if (event == 30) {
		event_30_family_visit();
	}

	else if (event == 31) {
		event_31_antique_find();
	}

	else if (event == 32) {
		event_32_work_mistake();
	}

	else if (event == 33) {
		event_33_education_course();
	}

	else if (event == 34) {
		event_34_public_transport_strike();
	}

	else if (event == 35) {
		event_35_language_learning();
	}

	else if (event == 36) {
		event_36_volunteering();
	}

	else if (event == 37) {
		event_37_dangerous_taxi();
	}

	else if (event == 38) {
		event_38_contaminated_water();
	}
}
///////////////////////////////////Simulation_Core//////////////////////////////////////////////////////////////////////////////

void simulation() {
	while
	(!((now_date.month == end_date.month)

	        && (now_date.year == end_date.year)

	        && (now_date.day == end_date.day))

	        && Pasha.life)


	{
		salary();
		taxes();
		bank();

		cat();
		dog();
		car();
		food();
		home();
		drugs();
		drinks();
		travel();
		sports();
		smoking();
		burnout();
		Holidays();
		insomnia();
		utilities();
		pollution();
		psychology();
		mental_break();
		seasonal_cold();
		car_insurance();
		public_events();
		sedentary_work();
		random_shoping();
		noise_pollution();
		public_transport();
		appliance_repair();
		bank_service_fee();
		gaming_addiction();
		communication_fee();
		seasonal_discounts();
		junk_food_overeating();
		streaming_subscription();
		seasonal_clothing_update();
		online_shopping_discount();
		random_weather_mental_effect();

		new_friends();
		society();

		random_events();

		balance_new_status();
		damage_from_poverty();
		years_old();
		dead_check();

		new_day();
	}
}




int main() {
	input_date();
	Pasha_initialization();
	car_initialization();
	simulation();
	print_results();
}
