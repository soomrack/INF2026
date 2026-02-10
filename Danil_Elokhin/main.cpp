#include <stdio.h>

int main(){
	int year = 2026;
	int month = 2;

	int salary = 100000;
	int capital = 0;
	
	//for (int month = 1; month < 13; ++month) {
	while ((year == 2027 || month != 2) ) {
		if (month == 3) {
				salary *= 1.5;
			}
		capital = capital + salary;
		++month;
		if (month == 13) {
			++year;
			month = 1;
		}

	}

	printf("Salary = %d\n", salary);
	printf("Capital = %d", capital);


}