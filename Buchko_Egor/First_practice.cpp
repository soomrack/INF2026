#include <stdio.h>

int main(){
   int year = 2026;
   int month = 2;
   int salary = 10001;
   int capital = 0;
   int premia = 5000;
   while ( !(year == 2027 && month == 2)) {
      if (month == 3){
         salary = (salary * 1.5);
      }

      capital += salary;
      
      if (month == 2 && year == 2026){
         capital += premia;
      }

      ++month;
      if (month == 13){
         ++year;
         month = 1;
      }
   }
   printf("Salary = %d\n", salary);
   printf("Capital = %d", capital);
}
