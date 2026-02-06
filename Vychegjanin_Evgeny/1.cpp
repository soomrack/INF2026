#include <stdio.h>
int main() 
{
	int salary = 100001;
	int capital = 0;
    
	int month = 2;
	int year = 2026;
    
	while (! (year == 2027 && month == 2))
	{
		if (month == 3)
        {
			salary = (salary*1.5);
		}

		capital += salary;
		++month;
        
			if (month == 13)
            {
				++year;
				month = 1;
			}
	}
	printf("Capital = %d\n", capital);
	printf("Salary = %d", salary);
}
