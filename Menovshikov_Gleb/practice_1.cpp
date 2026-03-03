#include <stdio.h>
#include <iostream>
#include <list>
#include <array>


using std::cout;
using std::endl;

using std::list;
using std::array;

using std::string;


using Percent = float;

using RUB = long long int;
using USD = long long int;

using USint = unsigned short int;


struct Calendar{
    const array<USint, 12> normal_year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const array<USint, 12> leap_year = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    array<USint, 12> current_year_days;
    USint current_year;
    USint current_month;
    USint current_day;

    USint get_days_in_current_month()
    {
        return current_year_days[current_month-1];
    }

    void update_current_year_days()
    {
        if (current_year%4 != 0)
        {
            current_year_days = normal_year;
        }
        else if (current_year%4 == 0)
        {
            current_year_days = leap_year;

        }
    }

    void advance()
    {
        current_day++;

        if (current_day>current_year_days[current_month-1])
        {
            ++current_month;
            current_day = 1;
        }

        if (current_month == 13) 
        {
            ++current_year;
            update_current_year_days();
            current_month = 1;
        }
    }
};

Calendar calendar;

struct Mind {
    USint current_stress;
    string current_mind_state;

    void update_current_mind_state()
    {
        if (current_stress < 10)
        {
            current_mind_state = "Cheerful";
        }

        else if (current_stress < 20)
        {
            current_mind_state = "Normal";
        }

        else if (current_stress < 30)
        {
            current_mind_state = "Exhausted";
        }

        else 
        {
            current_mind_state = "Frenzy";
        }
    }

    const USint* get_stress_pointer()
    {
        USint* current_stress_pointer = &current_stress;

        return current_stress_pointer;
    }
};


struct Home {
    RUB rent;
    
    RUB get_rent()
    {
        return rent;
    }
};


struct Job {
    RUB salary;
    RUB bonus;

    USint current_workload;
    USint daily_workload;

    USint workday_stress;
    
private:
    struct Overtime {
        USint workload_decrease;
        USint stress_increase;
        Percent extra_pay_multiplier;

    public:
        Overtime (const USint workload, const Percent multiplier, const USint stress)
        {
            workload_decrease = workload;
            stress_increase = stress;
            extra_pay_multiplier = multiplier;

        }

    };

public:

    Overtime zero_overtime{0,0,0};
    Overtime small_overtime{daily_workload, 1.3, workday_stress*1.5};
    Overtime meduim_overtime{daily_workload*2, 1.6, workday_stress*2};
    Overtime large_overtime{daily_workload*3, 2, workday_stress*2.5};


    RUB get_daily_pay()
    {
        return salary/calendar.get_days_in_current_month();
    }

    RUB get_bonus()
    {
        return bonus;
    }

    void promote()
    {
        salary *= 1.5;
    }

    USint get_current_workload()
    {
        return current_workload;
    }

    void increase_current_workload_by_days(const USint days)
    {
        current_workload += days * daily_workload;
    }

    Overtime what_overtime_needed()
    {
        if (current_workload <= daily_workload)
        {
            return zero_overtime;
        }

        else if (current_workload > daily_workload && current_workload <= daily_workload*2)
        {
            return small_overtime;
        }

        else if (current_workload*2 > daily_workload && current_workload <= daily_workload*3)
        {
            return meduim_overtime;
        }

        else if (current_workload*3 > daily_workload && current_workload <= daily_workload*4)
        {
            return large_overtime;
        }

        return zero_overtime;
    }

    void do_work(USint *current_stress, RUB *account_rub)
    {
        current_workload -= daily_workload;
        *current_stress += workday_stress;
        *account_rub += get_daily_pay();
    }

    void do_overtime(const Overtime overtime, USint *current_stress, RUB *account_rub)
    {
        current_workload -= overtime.workload_decrease;
        *current_stress += overtime.stress_increase;
        *account_rub += get_daily_pay()*overtime.extra_pay_multiplier;
    }

    
};


struct Car {
    RUB value;
    RUB gas;
    RUB tires_price;

    RUB get_tires_price()
    {
        return tires_price;
    }
};


struct Bank {
    RUB account_rub;
    USD account_usd;
    float rate_usd_rub;
};


struct Economy {
    Percent inflation;

    Percent get_current_inflation()
    {
        return inflation;
    }
    

    void recalculate_inflation(const int year)
    {

        switch (year) 
        {
            case 2026: inflation = 12.5; break;
            case 2027: inflation = 14.0; break;
            case 2028: inflation = 13.0; break;
            case 2029: inflation = 11.5; break;
        }
    }


    void recalculate_prices(list<RUB*> prices)
    {
            
        for (RUB* i : prices)
        {
            *i += *i*(get_current_inflation()/100.);
        }


    }
};


struct Country {
    Economy economy;
};


struct Person {
    Mind mind;
    Home home;
    Country country;
    Bank vtb;
    Job job;
    RUB food;
    Car car;

    USint day_off_stress_decrease;

    const list<RUB*> get_prices_pointers()
    {
        RUB* food_pointer= &food;
        RUB* gas_pointer = &car.gas;
        RUB* rent_pointer = &home.rent;
        RUB* tires_price_pointer = &car.tires_price;

        return {gas_pointer, food_pointer, rent_pointer, tires_price_pointer};
    }

    void rest()
    {
        mind.current_stress -= day_off_stress_decrease;
    }
};


struct Person alice;


void alice_init()
{
    alice.mind.current_stress = 0;
    alice.mind.update_current_mind_state();

    alice.country.economy.inflation = 12.5;

    alice.vtb.rate_usd_rub = 78.76;
    alice.vtb.account_rub = 0;
    alice.vtb.account_usd = 1'000;
    
    alice.job.salary = 180'000;
    alice.job.daily_workload = 100;
    alice.job.workday_stress = 10;

    alice.food = 3'000;
    
    alice.home.rent = 30'000;

    alice.car.value = 2'400'000;
    alice.car.gas = 15'000;
    alice.car.tires_price = 3'000;
}


void alice_home(const int day)
{
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.home.get_rent()
        
    ;
    }
}


void alice_food(const int day, const int month, const int year)
{
    if (day == 1)
    {
        if (month == 12) alice.vtb.account_rub -= 2000;  // christmas party

        alice.vtb.account_rub -= alice.food;
    }
}


void alice_job(const int day, const int month, const int year)
{
    if (day == 1)
    {
        if (month == 3) 
        {
            alice.job.promote();
        }

        if (month == 2 && year == 2026) 
        {
            alice.vtb.account_rub += alice.job.get_bonus();  
        }
    }

    alice.job.increase_current_workload_by_days(1);
    alice.job.do_overtime(alice.job.what_overtime_needed(), &alice.mind.current_stress, &alice.vtb.account_rub);
    alice.job.do_work(&alice.mind.current_stress, &alice.vtb.account_rub);
}


void alice_car(const int day, const int month, const int year)
{
    if (day == 1)
    {
        alice.vtb.account_rub -= alice.car.gas;

        if (month == 4 or month == 10)
        {
            alice.vtb.account_rub -= alice.car.get_tires_price();
        }
    }
}


void alice_expenses(const int day, const int month, const int year)
{    
    alice_food(day, month, year);
    alice_car(day, month, year);
    alice_home(day);

    alice.country.economy.recalculate_inflation(year);
    
    if (month == 1 && day == 1){

    alice.country.economy.recalculate_prices(alice.get_prices_pointers());
    }
}


void print_results()
{
    printf("Salary = %lld\n", alice.job.salary);

    RUB net_worth = 0;
    net_worth += alice.vtb.account_rub;
    net_worth += alice.vtb.account_usd * alice.vtb.rate_usd_rub;
    net_worth += alice.car.value;

    cout << "Balance = "<< alice.vtb.account_rub<<endl;

    printf("Capital = %lld\n", net_worth);

    cout << "Inflation = " << alice.country.economy.get_current_inflation() << "%" << endl;

    cout << "Workload = " << alice.job.current_workload << endl;

    cout << "Stress = " << alice.mind.current_stress << endl;
}


void simulation()
{
    calendar.current_day = 1;
    calendar.current_month = 2;
    calendar.current_year = 2026;
    calendar.update_current_year_days();

    while ( !(calendar.current_year == 2029 && calendar.current_month == 2) ) 
    {
        alice_expenses(calendar.current_day, calendar.current_month, calendar.current_year);
        // my_cat();
        // my_trip();
        // my_rent();
        // my_mortgage();

        alice_job(calendar.current_day, calendar.current_month, calendar.current_year);
        
        calendar.advance(); //goes on and on and on
    }
}


int main()
{
    alice_init();
    simulation();
    print_results();
}
