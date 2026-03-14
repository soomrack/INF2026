#include <stdio.h>






using Percent = float;





using RUB = long long int;
using USD = long long int;






struct Car {
    RUB value;
    RUB grm;
    RUB tires;
    RUB oil;
    RUB car_other;
    RUB gas;
    RUB car_summ;
};






struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
};





struct Mortgage {
    RUB mortgage_pays;
    RUB mortgage_summ;
};





struct JKH {
    RUB cold_water;
    RUB hot_water;
    RUB light;
    RUB jkh_summ;
};



struct Cat {
    RUB cat_food;
    RUB cat_wc;
    RUB cat_summ;
};





struct Guinea_pig {
    RUB pig_food;
    RUB pig_wc;
    RUB pig_summ;
};





struct Canary {
    RUB canary_food;
    RUB canary_wc;
    RUB canary_summ;
};



struct Person {
    Bank vtb;
    RUB salary;
    RUB food;
    Mortgage mortgage;
    JKH jkh;
    Cat cat;
    Guinea_pig pig;
    Canary canary;
    Car car;
};
struct Person Kostya;






void Kostya_init()
{
    Kostya.vtb.rate_usd_rub = 78.76;
    Kostya.vtb.account_rub = 0;
    Kostya.vtb.account_usd = 1'000;
    
    Kostya.salary = 100'000;
    Kostya.food = 3'000;
    Kostya.mortgage.mortgage_pays = 20'000;
    Kostya.jkh.cold_water = 5'000;
    Kostya.jkh.hot_water = 5'000;
    Kostya.jkh.light = 5'000; 
    Kostya.cat.cat_food = 1000;
    Kostya.cat.cat_wc = 1500;
    Kostya.pig.pig_food = 1000;
    Kostya.pig.pig_wc = 1500;
    Kostya.canary.canary_food = 1000;
    Kostya.canary.canary_wc = 1500;
    
    
    Kostya.car.value = 2'400'0;
    Kostya.car.gas = 15'000;
    Kostya.car.tires = 20'000;
    Kostya.car.oil = 14'000;
    Kostya.car.car_other = 10'000;
    Kostya.car.gas = 15'000;
}






void Kostya_food(const int month, const int year)
{
    if (month == 12) Kostya.vtb.account_rub -= 2000;  // christmas party
    if (month == 3) Kostya.vtb.account_rub -= 800;  // lottery ticket

    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    case 2030: inflation = 12.5; break;
    case 2031: inflation = 13.5; break;
    case 2032: inflation = 14.0; break;
    case 2033: inflation = 14.5; break;
    case 2034: inflation = 13.0; break;
    case 2035: inflation = 12.5; break;
    case 2036: inflation = 12.0; break;
    case 2037: inflation = 13.5; break;
    case 2038: inflation = 13.0; break;
    }
    Kostya.food += Kostya.food * (inflation / 100. / 12.);
        
    Kostya.vtb.account_rub -= Kostya.food;
}





void Kostya_mortgage(const int month, const int year)
{
    if (month == 2 && year == 2026) Kostya.vtb.account_rub -= 50000;  // first pay

    Kostya.vtb.account_rub -= Kostya.mortgage.mortgage_pays;
    Kostya.mortgage.mortgage_summ += Kostya.mortgage.mortgage_pays;
}





void Kostya_jkh(const int month, const int year)
{

    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    case 2030: inflation = 12.5; break;
    case 2031: inflation = 13.5; break;
    case 2032: inflation = 14.0; break;
    case 2033: inflation = 14.5; break;
    case 2034: inflation = 13.0; break;
    case 2035: inflation = 12.5; break;
    case 2036: inflation = 12.0; break;
    case 2037: inflation = 13.5; break;
    case 2038: inflation = 13.0; break;
    }
    Kostya.jkh.cold_water += Kostya.jkh.cold_water * (inflation / 100. / 12.);
    Kostya.jkh.hot_water += Kostya.jkh.hot_water * (inflation / 100. / 12.);
    Kostya.jkh.light += Kostya.jkh.light * (inflation / 100. / 12.);
        
    Kostya.vtb.account_rub -= Kostya.jkh.cold_water;
    Kostya.vtb.account_rub -= Kostya.jkh.hot_water;
    Kostya.vtb.account_rub -= Kostya.jkh.light;
    Kostya.jkh.jkh_summ += Kostya.jkh.cold_water;
    Kostya.jkh.jkh_summ += Kostya.jkh.hot_water;
    Kostya.jkh.jkh_summ += Kostya.jkh.light;
}




void Kostya_salary(const int month, const int year)
{
    if (month == 3) {
        Kostya.salary *= 1.5;
    }

    if (month == 2 && year == 2026) {
        Kostya.vtb.account_rub += 5000;  // bonus
    }

    if (month == 5 && year == 2026) {
        Kostya.vtb.account_rub += 25000;  // lottery win
    }
        
    Kostya.vtb.account_rub += Kostya.salary;
}





void Kostya_cat(const int month, const int year)
{
    if (month == 9 && year == 2026) Kostya.vtb.account_rub -= 5000;  // cat illness
    if (month == 7 && year == 2026) Kostya.vtb.account_rub -= 800;  // new dish
    if (month == 3 && year == 2026) Kostya.vtb.account_rub -= 1000;  // new scatching point

    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    case 2030: inflation = 12.5; break;
    case 2031: inflation = 13.5; break;
    case 2032: inflation = 14.0; break;
    case 2033: inflation = 14.5; break;
    case 2034: inflation = 13.0; break;
    case 2035: inflation = 12.5; break;
    case 2036: inflation = 12.0; break;
    case 2037: inflation = 13.5; break;
    case 2038: inflation = 13.0; break;
    }
    Kostya.cat.cat_food += Kostya.cat.cat_food * (inflation / 100. / 12.);
    Kostya.cat.cat_wc += Kostya.cat.cat_wc * (inflation / 100. / 12.);
        
    Kostya.vtb.account_rub -= Kostya.cat.cat_food;
    Kostya.vtb.account_rub -= Kostya.cat.cat_wc;
    Kostya.cat.cat_summ += Kostya.cat.cat_food;
    Kostya.cat.cat_summ += Kostya.cat.cat_wc;
}





void Kostya_pig(const int month, const int year)
{
    if (month == 9 && year == 2028) Kostya.vtb.account_rub -= 5000;  // cat illness
    if (month == 7 && year == 2026) Kostya.vtb.account_rub -= 800;  // new dish
    if (month == 3 && year == 2029) Kostya.vtb.account_rub -= 1000;  // new cage

    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    case 2030: inflation = 12.5; break;
    case 2031: inflation = 13.5; break;
    case 2032: inflation = 14.0; break;
    case 2033: inflation = 14.5; break;
    case 2034: inflation = 13.0; break;
    case 2035: inflation = 12.5; break;
    case 2036: inflation = 12.0; break;
    case 2037: inflation = 13.5; break;
    case 2038: inflation = 13.0; break;
    }
    Kostya.pig.pig_food += Kostya.pig.pig_food * (inflation / 100. / 12.);
    Kostya.pig.pig_wc += Kostya.pig.pig_wc * (inflation / 100. / 12.);
        
    Kostya.vtb.account_rub -= Kostya.pig.pig_food;
    Kostya.vtb.account_rub -= Kostya.pig.pig_wc;
    Kostya.pig.pig_summ += Kostya.pig.pig_food;
    Kostya.pig.pig_summ += Kostya.pig.pig_wc;
}





void Kostya_canary(const int month, const int year)
{
    if (month == 9 && year == 2026) Kostya.vtb.account_rub -= 5000;  // canary illness
    if (month == 7 && year == 2026) Kostya.vtb.account_rub -= 800;  // new dish

    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    case 2030: inflation = 12.5; break;
    case 2031: inflation = 13.5; break;
    case 2032: inflation = 14.0; break;
    case 2033: inflation = 14.5; break;
    case 2034: inflation = 13.0; break;
    case 2035: inflation = 12.5; break;
    case 2036: inflation = 12.0; break;
    case 2037: inflation = 13.5; break;
    case 2038: inflation = 13.0; break;
    }
    Kostya.canary.canary_food += Kostya.canary.canary_food * (inflation / 100. / 12.);
    Kostya.canary.canary_wc += Kostya.canary.canary_wc * (inflation / 100. / 12.);
        
    Kostya.vtb.account_rub -= Kostya.canary.canary_food;
    Kostya.vtb.account_rub -= Kostya.canary.canary_wc;
    Kostya.canary.canary_summ += Kostya.canary.canary_food;
    Kostya.canary.canary_summ += Kostya.canary.canary_wc;
}




void print_results()
{

    RUB capital = 0;
    capital += Kostya.vtb.account_rub;
    capital += Kostya.vtb.account_usd * Kostya.vtb.rate_usd_rub;
    capital += Kostya.car.value;
    printf("Salary = %lld\n", Kostya.salary);
    printf("Capital = %lld\n", capital);
    printf("mortgage = %lld\n", Kostya.mortgage.mortgage_summ);
    printf("jkh = %lld\n", Kostya.jkh.jkh_summ);
    printf("cat = %lld\n", Kostya.cat.cat_summ);
    printf("pig = %lld\n", Kostya.pig.pig_summ);
    printf("canary = %lld\n", Kostya.canary.canary_summ);
    printf("car = %lld\n", Kostya.car.car_summ);


}






void Kostya_car(const int month, const int year)
{
    Percent inflation = 12.0;
    switch (year) {
    case 2026: inflation = 12.5; break;
    case 2027: inflation = 14.0; break;
    case 2028: inflation = 13.0; break;
    case 2029: inflation = 11.5; break;
    case 2030: inflation = 12.5; break;
    case 2031: inflation = 13.5; break;
    case 2032: inflation = 14.0; break;
    case 2033: inflation = 14.5; break;
    case 2034: inflation = 13.0; break;
    case 2035: inflation = 12.5; break;
    case 2036: inflation = 12.0; break;
    case 2037: inflation = 13.5; break;
    case 2038: inflation = 13.0; break;
    }
    Kostya.car.gas += Kostya.car.gas * (inflation / 100. / 12.);
    Kostya.car.grm += Kostya.car.grm * (inflation / 100. / 12.);
    Kostya.car.tires += Kostya.car.tires * (inflation / 100. / 12.);
    Kostya.car.oil += Kostya.car.oil * (inflation / 100. / 12.);
    Kostya.car.car_other += Kostya.car.car_other * (inflation / 100. / 12.);

    Kostya.vtb.account_rub -= Kostya.car.gas;

    if (month == 8 && year % 2 == 0) Kostya.vtb.account_rub -= Kostya.car.grm, Kostya.car.car_summ += Kostya.car.grm;
    if (month % 6 == 0) Kostya.vtb.account_rub -= Kostya.car.tires, Kostya.car.car_summ += Kostya.car.tires;
    if (month % 1 == 0) Kostya.vtb.account_rub -= Kostya.car.oil, Kostya.car.car_summ += Kostya.car.oil;
    if (month % 2 == 0) Kostya.vtb.account_rub -= Kostya.car.car_other, Kostya.car.car_summ += Kostya.car.car_other;

    Kostya.car.car_summ += Kostya.car.gas;

}






void simulation()
{
    int year = 2026;
    int month = 2;
    
    while ( !(year == 2038 && month == 2) ) {
        Kostya_salary(month, year);
        Kostya_car(month, year);
        // my_trip();
        // my_rent();
        Kostya_food(month, year);
        Kostya_mortgage(month, year);
        Kostya_jkh(month, year);
        Kostya_cat(month, year);
        Kostya_pig(month, year);
        Kostya_canary(month, year);
        
        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }
    }
}






int main()
{
    Kostya_init();
    simulation();
    print_results();
}