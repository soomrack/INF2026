#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

typedef short date;
typedef long long int RUB;
typedef long long int RUB_k;
typedef unsigned int days;
typedef int age;
typedef unsigned int people;



RUB

balance_diff = 0,
balance,
balance_start,
bank_account;



RUB_k
salary_RUB = 128000;



date

month_start,
day_start,
month_end,
day_end,
month_now,
day_now,year_start,
year_end,
year_now;




age

age_start;


people

friends = 0;


float

health;





void print_results()
{
	std :: cout << "For the period from " << day_start << "." << month_start << "." << year_start << " to " << day_now << "." << month_now << "." << year_now << " the balance will change by " << balance_diff << " RUB" << std::endl;
	std :: cout << "New balance is " << balance << " RUB" << std::endl;

	if (health <= 0)
	{
		std::cout << "You're dead(";
	}
}






void input_date()
{
	std :: cout << "Enter the start date ";
	std :: cin >> day_start >> month_start >> year_start;

	std :: cout << "Enter the end date ";
	std :: cin >> day_end >> month_end >> year_end;

	std :: cout << "Enter the start balance ";
	std :: cin >> balance_start;

	std :: cout << "Enter the start age ";
	std :: cin >> age_start;

	health = 10 - age_start*0.1;
	day_now = day_start;
	month_now = month_start;
	year_now = year_start;
}





int days_in_month(int month, int year)
{
	if (month == 2)
	{
		if ((year%4)==0)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else
	{
		if (month<8)
		{
			return (30 + month%2);
		}
		else
		{
			return (30 + (month-1)%2);
		}
	}
}






void times()
{
	day_now++;
	if (day_now == days_in_month(month_now,year_now))
	{
		day_now=1;
		month_now++;
	}
	if (month_now==13)
	{
		month_now=1;
		year_now++;
	}
}




void randint()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
}





void food()
{
	int r = std::rand();
	if (balance >= r%800 + 400)
	{
		balance_diff -= (r%800 + 400);
	}
	else
	{
		health -= (1 - balance/(r%800 + 400))*0.0001;
	}
}





void health_score()
{
	if (balance < 0)
	{
		health += balance*0.00000001;
	}
}





void balance_new()
{
	balance = balance_start + balance_diff;
}





void salary()
{
	if(day_now == 1

	        && (year_now - year_start + age_start)>=18 )


	{
		balance_diff += salary_RUB;
	}
}




void salary_indexation()
{
	if (month_now == 1

	        && day_now == 1)


	{
		salary_RUB = salary_RUB*1.05;
	}
}




void sports()
{
	if (day_now % 3 == 2

	        && balance >= 750)


	{
		balance_diff -= 750;
		health += 0.000000001;
	}
}




void years_old()
{
	if (day_now == 1

	        && month_now == 1)


	{
		health -= 0.001*pow(1.08, (year_now - year_start + age_start));
	}
}


void drugs()
{
	if (day_now == 15

	        && balance >= 2000)


	{
		balance -= 2000;
		health += 0.00001;
	}
}



void smoking()
{
	if (day_now%2 == 0

	        && balance >= 800)


	{
		balance -= 800;
		health -= 0.000001;
	}
}


void drinks()
{
	if (day_now%5 == 0

	        && balance >= 200)


	{
		balance -= 200;
		health -= 0.000001;
	}
}



void travel()
{
	if (month_now == 8

	        && balance >= 30000)


	{
		balance -= 30000;
		health += 0.0001;
	}
}



void home()
{
	if (day_now == 1

	        && balance >= 25000)


	{
		balance -= 30000;
	}

	else

	{
		health -= 0.001;
	}
}


void psychology()
{
	if (day_now % 4 == 2

	        && balance >= 3000)


	{
		balance_diff -= 300;
		health += 0.00000001;
	}
}


void bank()
{
	if (day_now == 1

	        && balance >= 5000)


	{
		balance += bank_account*(0.01);
		balance -= 5000;
		bank_account += 5000;
	}
}



void taxes()
{
	if (month_now == 4

	        && day_now == 15)

	{
		float tax_rate = 0.13;

		if (balance > 1000000)
		{
			tax_rate = 0.20;
		}

		else if (balance > 500000)
		{
			tax_rate = 0.15;
		}

		balance_diff -= balance * tax_rate;
	}
}



void random_shoping()
{

	int r = std::rand();

	if ((r%100) > 60)
	{
		if (balance >= r%5000)
		{
			balance -= r%5000;
			health += 0.00001;
		}
		else
		{
			balance = 0;
			health -= 0.000001;
		}
	}
}



void new_year()
{

	int r = std::rand();

	if (month_now == 12

	        && day_now == 31)
	{
		if (balance >= (r%5000)*friends)
		{
			balance -= (r%5000)*friends;
		}
		else
		{
			health -= 0.000001*friends;
			friends -= 1;
		}
	}
}


void eight_march()
{

	int r = std::rand();

	if (month_now == 3

	        && day_now == 8)
	{
		if (balance >= (r%5000)*friends/2)
		{
			balance -= (r%5000)*friends/2;
		}
		else
		{
			health -= 0.000001*friends/2;
			friends -= 1;
		}
	}
}


void twenty_three_february()
{

	int r = std::rand();

	if (month_now == 2

	        && day_now == 23)
	{
		if (balance >= (r%5000)*friends/2)
		{
			balance -= (r%5000)*friends/2;
		}
		else
		{
			health -= 0.000001*friends/2;
			friends -= 1;
		}
	}
}



void new_friends()
{

	int r = std::rand();

	if (r%300 == 0)
	{
		friends += 1;
	}
}


void society()
{
	if (day_now == 1)
	{
		health += 0.0005*friends;
	}
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void simulation()
{
	while
	(!((month_now==month_end)

	        && (year_now==year_end)

	        && (day_now == day_end))

	        && health>0)


	{
		salary_indexation();
		salary();
		taxes();
		bank();

		food();
		smoking();
		drinks();
		travel();
		home();
		drugs();
		random_shoping();
		sports();
		psychology();
		
		new_friends();
		society();

		new_year();
		eight_march();
		twenty_three_february();

		balance_new();
		years_old();
		health_score();
		times();
	}
}




int main()
{
	input_date();
	simulation();
	print_results();
}
