#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef long long int RUB;
typedef double INFLATION;
typedef double PERCENT;
typedef const char* string;


enum BankReliability {
    RELIABLE = 1,
    UNRELIABLE = 0
};


struct BankParams {
    string name;
    PERCENT base_rate;
    RUB min_deposit_amount;
    int deposit_term_months;
    enum BankReliability reliability;
};


struct Bank {
    string name;
    PERCENT deposit_rate;
    RUB min_deposit;
    int term_months;
    bool is_reliable;
};


struct BankAccount {
    RUB deposit;
    RUB checking;
    PERCENT deposit_rate;
    int deposit_term;
    int months_passed;
    struct Bank bank;
    RUB max_deposit;
    RUB interest_earned_total;
    int years_passed;
};


struct Car {
    RUB value;
    RUB gas;
    RUB maintenance;
    INFLATION gas_inflation;
    INFLATION maintenance_inflation;
    int purchase_year;
    int years_owned;
};


struct Phone {
    RUB value;
    RUB monthly_payment;
    int purchase_year;
    int replacement_cycle;
    bool is_contract;
};


struct Computer {
    RUB value;
    int purchase_year;
    int replacement_cycle;
    string type;
};


struct School {
    RUB monthly_food;
    RUB daily_transport;
    RUB daily_transport_without_card;
    RUB transport_card_cost;
    int transport_card_days;
    int school_days_per_month;
    RUB yearly_supplies;
    RUB yearly_activities;
    RUB uniform_cost;
    int start_year;
    int start_month;
    RUB tuition;
    RUB books;
    RUB extra_classes;
    RUB school_trips;
};


struct Holidays {
    RUB new_year;
    RUB christmas;
    RUB birthday_alice;
    RUB birthday_husband;
    RUB birthday_child;
    RUB march_8;
    RUB feb_23;
    RUB other;
    INFLATION inflation;
};


struct Vacation {
    RUB summer_vacation;
    RUB winter_vacation;
    RUB summer_duration_days;
    RUB winter_duration_days;
    INFLATION vacation_inflation;
};


struct FamilyActivities {
    RUB ice_skating;
    RUB badminton;
    RUB sup;
    RUB shooting_range;
    int ice_skating_months[4];
    int badminton_months[3];
    int sup_months[3];
    int shooting_range_months[3];
    INFLATION activities_inflation;
};


struct Donations {
    RUB robux;
    RUB war_thunder;
    RUB other_games;
    int robux_per_month;
    int war_thunder_per_month;
    INFLATION donations_inflation;
};


struct Books {
    RUB monthly_books;
    int books_per_month;
    RUB average_book_price;
    INFLATION book_inflation;
};


struct Dog {
    RUB value;
    RUB food;
    RUB vet;
    RUB grooming;
    RUB toys;
    RUB training;
    INFLATION food_inflation;
    INFLATION vet_inflation;
    INFLATION grooming_inflation;
};


struct Hamster {
    RUB value;
    RUB food;
    RUB bedding;
    RUB toys;
    RUB vet;
    INFLATION food_inflation;
    INFLATION bedding_inflation;
    INFLATION vet_inflation;
};


struct MusicLessons {
    RUB alice_piano;
    RUB child_piano;
    int lessons_per_month;
    RUB lesson_price;
    INFLATION music_inflation;
};


struct Child {
    RUB monthly_expenses;
    RUB education_fund;
    RUB clothes;
    RUB toys;
    RUB pocket_money;
    RUB sports;
    RUB music_school;
    RUB art_school;
    RUB summer_camp;
    INFLATION expenses_inflation;
    INFLATION education_inflation;
    int age;
    int grade;
    struct School school;
    struct Books books;
    struct Donations donations;
    struct MusicLessons music;
};


struct Spouse {
    RUB salary;
    RUB personal_expenses;
    RUB savings;
    INFLATION salary_indexation;
    INFLATION expenses_inflation;
    struct Car car;
    struct Phone phone;
    struct Computer computer;
    RUB work_lunches;
    RUB business_trips;
    RUB professional_courses;
    struct MusicLessons music;
};


struct Family {
    RUB common_fund;
    RUB emergency_fund;
    RUB monthly_savings_target;
    RUB total_expenses;
    RUB total_income;
    RUB emergency_threshold;
    RUB deposit_threshold;
    double education_contribution_rate;
    double husband_savings_rate;
    RUB checking_reserve;
    RUB common_fund_upper_limit;
    double alice_bonus_multiplier;
    int start_month;
    int start_year;
    int end_month;
    int end_year;
    RUB fathers_money;
    RUB initial_deposit;
    struct Holidays holidays;
    struct Vacation vacation;
    struct FamilyActivities activities;
    RUB vacation_fund;
    RUB medical_fund;
    RUB home_repair_fund;
    RUB car_repair_fund;
};


struct Person {
    RUB salary;
    RUB food;
    RUB utilities;
    RUB entertainment;
    RUB health_insurance;
    RUB fitness;
    RUB subscriptions;
    RUB beauty;
    RUB clothes;
    RUB hobbies;
    RUB courses;

    INFLATION food_inflation;
    INFLATION utilities_inflation;
    INFLATION entertainment_inflation;
    INFLATION health_inflation;
    INFLATION fitness_inflation;
    INFLATION subscriptions_inflation;
    INFLATION beauty_inflation;
    INFLATION clothes_inflation;
    INFLATION hobbies_inflation;
    INFLATION courses_inflation;
    INFLATION salary_indexation;

    struct Car car;
    struct Dog dog;
    struct Hamster hamster;
    struct BankAccount bank;
    RUB fathers_money;
    struct Phone phone;
    struct Computer computer;
    struct Books books;
    struct MusicLessons music;

    struct Spouse husband;
    struct Child child;
    struct Family family;
};


struct Person Alice;


const struct BankParams BANK_PARAMETERS[] = {
    // Название банка   Процентная ставка   Мин. сумма вклада   Срок вклада (мес.)   Надежность
    {"Sberbank",       12.5,                100000,             12,                   RELIABLE},      
    {"VTB",            13.0,                150000,             9,                    RELIABLE},      
    {"Gazprombank",    13.5,                200000,             6,                    RELIABLE},      
    {"Tinkoff",        14.0,                50000,              3,                    RELIABLE},      
    {"Alfa-Bank",      13.8,                100000,             6,                    RELIABLE},      
    {"Otkritie",       12.0,                50000,              12,                   RELIABLE},      
    {"Sovcombank",     11.5,                30000,              3,                    UNRELIABLE},    
    {"Rosselkhoz",     12.8,                100000,             12,                   RELIABLE},      
    {"MKB",            13.2,                150000,             6,                    RELIABLE},      
    {"Uralsib",        11.0,                50000,              3,                    UNRELIABLE}     
};


const int BANKS_COUNT = sizeof(BANK_PARAMETERS) / sizeof(BANK_PARAMETERS[0]);
struct Bank available_banks[10];


void initialize_banks();
struct Bank choose_best_bank(RUB deposit_amount, int months_to_keep);
void open_new_deposit(RUB amount);
void bank_interest_yearly(int year);
void husband_salary(int month, int year);
void child_expenses(int year);
void alice_salary(int month, int year);
void alice_food(int year);
void alice_car(int year);
void alice_dog(int year);
void alice_hamster(int year);
void alice_utilities(int year);
void alice_entertainment(int year);
void alice_health_insurance(int year);
void alice_fitness(int year);
void alice_subscriptions(int year);
void alice_books(int year);
void alice_beauty(int year);
void alice_clothes(int year);
void alice_hobbies(int year);
void alice_courses(int year);
void alice_music(int year);
void husband_car(int year);
void husband_work_expenses(int year);
void husband_courses(int year);
void husband_music(int year);
void phone_expenses(int year);
void computer_expenses(int year);
void holiday_expenses(int year, int month);
void vacation_expenses(int year, int month);
void family_activities(int year, int month);
void child_donations(int year);
void child_transport(int year, int month);
void child_music(int year);
void school_expenses(int year, int month);
void child_additional_activities(int year, int month);
void family_funds_management(int year);
void alice_husband_personal_expenses(int year);
void manage_family_budget();
void initialize_all();
void print_year_stats(int year);
void print_results();
void simulation();


void initialize_banks() {
    for (int i = 0; i < BANKS_COUNT; i++) {
        available_banks[i].name = BANK_PARAMETERS[i].name;
        available_banks[i].deposit_rate = BANK_PARAMETERS[i].base_rate;
        available_banks[i].min_deposit = BANK_PARAMETERS[i].min_deposit_amount;
        available_banks[i].term_months = BANK_PARAMETERS[i].deposit_term_months;
        available_banks[i].is_reliable = (BANK_PARAMETERS[i].reliability == RELIABLE);
    }
}


struct Bank choose_best_bank(RUB deposit_amount, int months_to_keep) {
    struct Bank best_bank = { NULL, 0, 0, 0, false };
    PERCENT best_rate = 0;

    for (int i = 0; i < BANKS_COUNT; i++) {
        struct Bank bank = available_banks[i];

        if (deposit_amount >= bank.min_deposit && months_to_keep >= bank.term_months && bank.deposit_rate > best_rate && bank.is_reliable) {
                best_rate = bank.deposit_rate;
                best_bank = bank;
        }
    }

    if (best_bank.name == NULL && deposit_amount >= available_banks[0].min_deposit) {
        best_bank = available_banks[0];
    }

    return best_bank;
}


void open_new_deposit(RUB amount) {
    if (amount <= 0) return;

    struct Bank chosen_bank = choose_best_bank(amount, 12);

    if (chosen_bank.name != NULL) {
        if (Alice.bank.deposit == 0) {
            Alice.bank.bank = chosen_bank;
            Alice.bank.deposit_rate = chosen_bank.deposit_rate;
            Alice.bank.deposit_term = chosen_bank.term_months;
            Alice.bank.months_passed = 0;
            Alice.bank.years_passed = 0;
        }
        else {
            if (chosen_bank.deposit_rate > Alice.bank.deposit_rate) {
                Alice.bank.bank = chosen_bank;
                Alice.bank.deposit_rate = chosen_bank.deposit_rate;
                Alice.bank.deposit_term = chosen_bank.term_months;
                Alice.bank.months_passed = 0;
                Alice.bank.years_passed = 0;
            }
        }

        Alice.bank.deposit += amount;
    }
}


void bank_interest_yearly(int year) {
    if (Alice.bank.checking > Alice.family.checking_reserve) {
        RUB to_deposit = Alice.bank.checking - Alice.family.checking_reserve;
        if (to_deposit > Alice.family.deposit_threshold) {
            Alice.bank.deposit += to_deposit;
            Alice.bank.checking = Alice.family.checking_reserve;
        }
    }

    if (Alice.bank.deposit > 0) {
        Alice.bank.years_passed++;

        if (Alice.bank.years_passed >= 1) {
            RUB interest = Alice.bank.deposit * Alice.bank.deposit_rate / 100;
            Alice.bank.deposit += interest;
            Alice.bank.interest_earned_total += interest;

            struct Bank new_bank = choose_best_bank(Alice.bank.deposit, 12);
            if (new_bank.name != NULL && new_bank.deposit_rate > Alice.bank.deposit_rate) {
                Alice.bank.bank = new_bank;
                Alice.bank.deposit_rate = new_bank.deposit_rate;
                Alice.bank.deposit_term = new_bank.term_months;
            }

            Alice.bank.years_passed = 0;
        }
    }
}


void husband_salary(int month, int year) {
    if (month == 1 && year > Alice.family.start_year) {
        Alice.husband.salary = Alice.husband.salary * (100 + Alice.husband.salary_indexation) / 100;
    }

    Alice.family.common_fund += Alice.husband.salary;
    Alice.family.total_income += Alice.husband.salary;
    Alice.family.common_fund -= Alice.husband.personal_expenses;
    Alice.family.total_expenses += Alice.husband.personal_expenses;
    Alice.husband.savings += Alice.husband.salary * Alice.family.husband_savings_rate;
}


void child_expenses(int year) {
    RUB child_total = Alice.child.monthly_expenses + Alice.child.clothes +
        Alice.child.toys + Alice.child.pocket_money + Alice.child.sports;
    Alice.family.common_fund -= child_total;
    Alice.family.total_expenses += child_total;

    RUB education_contribution = Alice.family.common_fund * Alice.family.education_contribution_rate;
    if (education_contribution > Alice.family.emergency_threshold) {
        Alice.child.education_fund += education_contribution;
        Alice.family.common_fund -= education_contribution;
    }

    static int last_year = 0;
    if (last_year != year) {
        Alice.child.monthly_expenses = Alice.child.monthly_expenses * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.clothes = Alice.child.clothes * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.toys = Alice.child.toys * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.pocket_money = Alice.child.pocket_money * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.sports = Alice.child.sports * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.music_school = Alice.child.music_school * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.art_school = Alice.child.art_school * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.summer_camp = Alice.child.summer_camp * (100 + Alice.child.expenses_inflation) / 100;
        last_year = year;
        Alice.child.age++;
        if (year >= Alice.child.school.start_year) {
            Alice.child.grade = year - Alice.child.school.start_year + 1;
        }
    }
}


void alice_salary(int month, int year) {
    if (month == 1 && year > Alice.family.start_year) {
        Alice.salary = Alice.salary * (100 + Alice.salary_indexation) / 100;
    }

    if ((month == 8) && (year == Alice.family.start_year)) {
        RUB bonus = Alice.salary * Alice.family.alice_bonus_multiplier;
        Alice.family.common_fund += bonus;
        Alice.family.total_income += bonus;
    }

    Alice.family.common_fund += Alice.salary;
    Alice.family.total_income += Alice.salary;
}


void alice_food(int year) {
    Alice.family.common_fund -= Alice.food;
    Alice.family.total_expenses += Alice.food;

    static int last_year = 0;
    if (last_year != year) {
        Alice.food = Alice.food * (100 + Alice.food_inflation) / 100;
        last_year = year;
    }
}


void alice_car(int year) {
    RUB total_car_cost = Alice.car.gas + Alice.car.maintenance;
    Alice.family.common_fund -= total_car_cost;
    Alice.family.total_expenses += total_car_cost;

    static int last_year = 0;
    if (last_year != year) {
        Alice.car.gas = Alice.car.gas * (100 + Alice.car.gas_inflation) / 100;
        Alice.car.maintenance = Alice.car.maintenance * (100 + Alice.car.maintenance_inflation) / 100;
        Alice.car.years_owned++;
        last_year = year;
    }
}


void alice_dog(int year) {
    RUB total_dog_cost = Alice.dog.food + Alice.dog.vet + Alice.dog.grooming +
        Alice.dog.toys + Alice.dog.training;
    Alice.family.common_fund -= total_dog_cost;
    Alice.family.total_expenses += total_dog_cost;

    static int last_year = 0;
    if (last_year != year) {
        Alice.dog.food = Alice.dog.food * (100 + Alice.dog.food_inflation) / 100;
        Alice.dog.vet = Alice.dog.vet * (100 + Alice.dog.vet_inflation) / 100;
        Alice.dog.grooming = Alice.dog.grooming * (100 + Alice.dog.grooming_inflation) / 100;
        Alice.dog.toys = Alice.dog.toys * (100 + Alice.dog.food_inflation) / 100;
        Alice.dog.training = Alice.dog.training * (100 + Alice.dog.vet_inflation) / 100;
        last_year = year;
    }
}


void alice_hamster(int year) {
    RUB total_hamster_cost = Alice.hamster.food + Alice.hamster.bedding +
        Alice.hamster.toys + Alice.hamster.vet;
    Alice.family.common_fund -= total_hamster_cost;
    Alice.family.total_expenses += total_hamster_cost;

    static int last_year = 0;
    if (last_year != year) {
        Alice.hamster.food = Alice.hamster.food * (100 + Alice.hamster.food_inflation) / 100;
        Alice.hamster.bedding = Alice.hamster.bedding * (100 + Alice.hamster.bedding_inflation) / 100;
        Alice.hamster.toys = Alice.hamster.toys * (100 + Alice.hamster.food_inflation) / 100;
        Alice.hamster.vet = Alice.hamster.vet * (100 + Alice.hamster.vet_inflation) / 100;
        last_year = year;
    }
}


void alice_utilities(int year) {
    Alice.family.common_fund -= Alice.utilities;
    Alice.family.total_expenses += Alice.utilities;

    static int last_year = 0;
    if (last_year != year) {
        Alice.utilities = Alice.utilities * (100 + Alice.utilities_inflation) / 100;
        last_year = year;
    }
}


void alice_entertainment(int year) {
    Alice.family.common_fund -= Alice.entertainment;
    Alice.family.total_expenses += Alice.entertainment;

    static int last_year = 0;
    if (last_year != year) {
        Alice.entertainment = Alice.entertainment * (100 + Alice.entertainment_inflation) / 100;
        last_year = year;
    }
}


void alice_health_insurance(int year) {
    Alice.family.common_fund -= Alice.health_insurance;
    Alice.family.total_expenses += Alice.health_insurance;

    static int last_year = 0;
    if (last_year != year) {
        Alice.health_insurance = Alice.health_insurance * (100 + Alice.health_inflation) / 100;
        last_year = year;
    }
}


void alice_fitness(int year) {
    Alice.family.common_fund -= Alice.fitness;
    Alice.family.total_expenses += Alice.fitness;

    static int last_year = 0;
    if (last_year != year) {
        Alice.fitness = Alice.fitness * (100 + Alice.fitness_inflation) / 100;
        last_year = year;
    }
}


void alice_subscriptions(int year) {
    Alice.family.common_fund -= Alice.subscriptions;
    Alice.family.total_expenses += Alice.subscriptions;

    static int last_year = 0;
    if (last_year != year) {
        Alice.subscriptions = Alice.subscriptions * (100 + Alice.subscriptions_inflation) / 100;
        last_year = year;
    }
}


void alice_books(int year){
    Alice.family.common_fund -= Alice.books.monthly_books;
    Alice.family.total_expenses += Alice.books.monthly_books;

    static int last_year = 0;
    if (last_year != year) {
        Alice.books.average_book_price = Alice.books.average_book_price * (100 + Alice.books.book_inflation) / 100;
        Alice.books.monthly_books = Alice.books.books_per_month * Alice.books.average_book_price;
        last_year = year;
    }
}


void alice_beauty(int year) {
    Alice.family.common_fund -= Alice.beauty;
    Alice.family.total_expenses += Alice.beauty;

    static int last_year = 0;
    if (last_year != year) {
        Alice.beauty = Alice.beauty * (100 + Alice.beauty_inflation) / 100;
        last_year = year;
    }
}


void alice_clothes(int year) {
    Alice.family.common_fund -= Alice.clothes;
    Alice.family.total_expenses += Alice.clothes;

    static int last_year = 0;
    if (last_year != year) {
        Alice.clothes = Alice.clothes * (100 + Alice.clothes_inflation) / 100;
        last_year = year;
    }
}


void alice_hobbies(int year) {
    Alice.family.common_fund -= Alice.hobbies;
    Alice.family.total_expenses += Alice.hobbies;

    static int last_year = 0;
    if (last_year != year) {
        Alice.hobbies = Alice.hobbies * (100 + Alice.hobbies_inflation) / 100;
        last_year = year;
    }
}


void alice_courses(int year) {
    Alice.family.common_fund -= Alice.courses;
    Alice.family.total_expenses += Alice.courses;

    static int last_year = 0;
    if (last_year != year) {
        Alice.courses = Alice.courses * (100 + Alice.courses_inflation) / 100;
        last_year = year;
    }
}


void alice_music(int year) {
    RUB music_cost = Alice.music.alice_piano;
    Alice.family.common_fund -= music_cost;
    Alice.family.total_expenses += music_cost;

    static int last_year = 0;
    if (last_year != year) {
        Alice.music.alice_piano = Alice.music.alice_piano * (100 + Alice.music.music_inflation) / 100;
        last_year = year;
    }
}


void husband_car(int year) {
    RUB total_car_cost = Alice.husband.car.gas + Alice.husband.car.maintenance;
    Alice.family.common_fund -= total_car_cost;
    Alice.family.total_expenses += total_car_cost;

    static int last_year = 0;
    if (last_year != year) {
        Alice.husband.car.gas = Alice.husband.car.gas * (100 + Alice.husband.car.gas_inflation) / 100;
        Alice.husband.car.maintenance = Alice.husband.car.maintenance * (100 + Alice.husband.car.maintenance_inflation) / 100;
        Alice.husband.car.years_owned++;
        last_year = year;
    }
}


void husband_work_expenses(int year) {
    RUB total_work = Alice.husband.work_lunches + Alice.husband.business_trips;
    Alice.family.common_fund -= total_work;
    Alice.family.total_expenses += total_work;

    static int last_year = 0;
    if (last_year != year) {
        Alice.husband.work_lunches = Alice.husband.work_lunches * (100 + Alice.husband.expenses_inflation) / 100;
        Alice.husband.business_trips = Alice.husband.business_trips * (100 + Alice.husband.expenses_inflation) / 100;
        last_year = year;
    }
}


void husband_courses(int year) {
    Alice.family.common_fund -= Alice.husband.professional_courses;
    Alice.family.total_expenses += Alice.husband.professional_courses;

    static int last_year = 0;
    if (last_year != year) {
        Alice.husband.professional_courses = Alice.husband.professional_courses * (100 + Alice.husband.expenses_inflation) / 100;
        last_year = year;
    }
}


void husband_music(int year) {
    static int last_year = 0;
    if (last_year != year) {
        last_year = year;
    }
}


void phone_expenses(int year) {
    RUB total_phone_cost = Alice.phone.monthly_payment + Alice.husband.phone.monthly_payment;
    Alice.family.common_fund -= total_phone_cost;
    Alice.family.total_expenses += total_phone_cost;

    if (year - Alice.phone.purchase_year >= Alice.phone.replacement_cycle) {
        Alice.family.common_fund -= Alice.phone.value;
        Alice.family.total_expenses += Alice.phone.value;
        Alice.phone.purchase_year = year;
    }

    if (year - Alice.husband.phone.purchase_year >= Alice.husband.phone.replacement_cycle) {
        Alice.family.common_fund -= Alice.husband.phone.value;
        Alice.family.total_expenses += Alice.husband.phone.value;
        Alice.husband.phone.purchase_year = year;
    }
}


void computer_expenses(int year) {
    if (year - Alice.computer.purchase_year >= Alice.computer.replacement_cycle) {
        Alice.family.common_fund -= Alice.computer.value;
        Alice.family.total_expenses += Alice.computer.value;
        Alice.computer.purchase_year = year;
    }

    if (year - Alice.husband.computer.purchase_year >= Alice.husband.computer.replacement_cycle) {
        Alice.family.common_fund -= Alice.husband.computer.value;
        Alice.family.total_expenses += Alice.husband.computer.value;
        Alice.husband.computer.purchase_year = year;
    }
}


void holiday_expenses(int year, int month) {
    RUB holiday_cost = 0;

    if (month == 12) holiday_cost += Alice.family.holidays.new_year;
    if (month == 1) holiday_cost += Alice.family.holidays.christmas;
    if (month == 2) holiday_cost += Alice.family.holidays.feb_23;
    if (month == 3) holiday_cost += Alice.family.holidays.march_8;
    if (month == 5 && Alice.child.age > 0) holiday_cost += Alice.family.holidays.birthday_child;
    if (month == 7) holiday_cost += Alice.family.holidays.birthday_alice;
    if (month == 10) holiday_cost += Alice.family.holidays.birthday_husband;

    holiday_cost += Alice.family.holidays.other / 12;

    Alice.family.common_fund -= holiday_cost;
    Alice.family.total_expenses += holiday_cost;

    static int last_year = 0;
    if (last_year != year) {
        Alice.family.holidays.new_year = Alice.family.holidays.new_year * (100 + Alice.family.holidays.inflation) / 100;
        Alice.family.holidays.christmas = Alice.family.holidays.christmas * (100 + Alice.family.holidays.inflation) / 100;
        Alice.family.holidays.birthday_alice = Alice.family.holidays.birthday_alice * (100 + Alice.family.holidays.inflation) / 100;
        Alice.family.holidays.birthday_husband = Alice.family.holidays.birthday_husband * (100 + Alice.family.holidays.inflation) / 100;
        Alice.family.holidays.birthday_child = Alice.family.holidays.birthday_child * (100 + Alice.family.holidays.inflation) / 100;
        Alice.family.holidays.march_8 = Alice.family.holidays.march_8 * (100 + Alice.family.holidays.inflation) / 100;
        Alice.family.holidays.feb_23 = Alice.family.holidays.feb_23 * (100 + Alice.family.holidays.inflation) / 100;
        Alice.family.holidays.other = Alice.family.holidays.other * (100 + Alice.family.holidays.inflation) / 100;
        last_year = year;
    }
}


void vacation_expenses(int year, int month) {
    if (month == 7) {
        Alice.family.common_fund -= Alice.family.vacation.summer_vacation;
        Alice.family.total_expenses += Alice.family.vacation.summer_vacation;
    }

    if (month == 1) {
        Alice.family.common_fund -= Alice.family.vacation.winter_vacation;
        Alice.family.total_expenses += Alice.family.vacation.winter_vacation;
    }

    static int last_year = 0;
    if (last_year != year) {
        Alice.family.vacation.summer_vacation = Alice.family.vacation.summer_vacation * (100 + Alice.family.vacation.vacation_inflation) / 100;
        Alice.family.vacation.winter_vacation = Alice.family.vacation.winter_vacation * (100 + Alice.family.vacation.vacation_inflation) / 100;
        last_year = year;
    }
}


void family_activities(int year, int month) {
    RUB activity_cost = 0;

    if (month == 12 || month == 1 || month == 2) {
        activity_cost += Alice.family.activities.ice_skating;
    }

    if (month == 3 || month == 4 || month == 5) {
        activity_cost += Alice.family.activities.badminton;
    }

    if (month == 6 || month == 7 || month == 8) {
        activity_cost += Alice.family.activities.sup;
    }

    if (month == 9 || month == 10 || month == 11) {
        activity_cost += Alice.family.activities.shooting_range;
    }

    Alice.family.common_fund -= activity_cost;
    Alice.family.total_expenses += activity_cost;

    static int last_year = 0;
    if (last_year != year) {
        Alice.family.activities.ice_skating = Alice.family.activities.ice_skating * (100 + Alice.family.activities.activities_inflation) / 100;
        Alice.family.activities.badminton = Alice.family.activities.badminton * (100 + Alice.family.activities.activities_inflation) / 100;
        Alice.family.activities.sup = Alice.family.activities.sup * (100 + Alice.family.activities.activities_inflation) / 100;
        Alice.family.activities.shooting_range = Alice.family.activities.shooting_range * (100 + Alice.family.activities.activities_inflation) / 100;
        last_year = year;
    }
}


void child_donations(int year) {
    RUB donations_total = Alice.child.donations.robux + Alice.child.donations.war_thunder;
    Alice.family.common_fund -= donations_total;
    Alice.family.total_expenses += donations_total;

    static int last_year = 0;
    if (last_year != year) {
        Alice.child.donations.robux = Alice.child.donations.robux * (100 + Alice.child.donations.donations_inflation) / 100;
        Alice.child.donations.war_thunder = Alice.child.donations.war_thunder * (100 + Alice.child.donations.donations_inflation) / 100;
        last_year = year;
    }
}


void child_transport(int year, int month) {
    if (year < Alice.child.school.start_year) return;
    if (month < 9 || month > 5) return;

    int days_in_month = 30;
    int days_with_card = Alice.child.school.transport_card_days;
    int days_without_card = days_in_month - days_with_card;

    RUB transport_cost = (days_with_card * Alice.child.school.daily_transport) +
        (days_without_card * Alice.child.school.daily_transport_without_card);

    if (month == 9 || month == 1) {
        transport_cost += Alice.child.school.transport_card_cost;
    }

    Alice.family.common_fund -= transport_cost;
    Alice.family.total_expenses += transport_cost;

    static int last_year = 0;
    if (last_year != year) {
        Alice.child.school.daily_transport = Alice.child.school.daily_transport * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.school.daily_transport_without_card = Alice.child.school.daily_transport_without_card * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.school.transport_card_cost = Alice.child.school.transport_card_cost * (100 + Alice.child.expenses_inflation) / 100;
        last_year = year;
    }
}


void child_music(int year) {
    RUB music_cost = Alice.child.music.child_piano;
    Alice.family.common_fund -= music_cost;
    Alice.family.total_expenses += music_cost;

    static int last_year = 0;
    if (last_year != year) {
        Alice.child.music.child_piano = Alice.child.music.child_piano * (100 + Alice.child.music.music_inflation) / 100;
        last_year = year;
    }
}


void school_expenses(int year, int month) {
    if (year < Alice.child.school.start_year) return;

    if (month >= 9 && month <= 5) {
        RUB school_monthly = Alice.child.school.monthly_food + Alice.child.school.books;
        Alice.family.common_fund -= school_monthly;
        Alice.family.total_expenses += school_monthly;
    }

    if (month == 8) {
        RUB school_yearly = Alice.child.school.yearly_supplies + Alice.child.school.books * 3;
        Alice.family.common_fund -= school_yearly;
        Alice.family.total_expenses += school_yearly;
    }

    if (month == 9) {
        RUB september_school = Alice.child.school.yearly_activities + Alice.child.school.extra_classes;
        Alice.family.common_fund -= september_school;
        Alice.family.total_expenses += september_school;

        if (year == Alice.child.school.start_year) {
            Alice.family.common_fund -= Alice.child.school.uniform_cost;
            Alice.family.total_expenses += Alice.child.school.uniform_cost;
        }
    }

    if (month == 4 && Alice.child.school.school_trips > 0) {
        Alice.family.common_fund -= Alice.child.school.school_trips;
        Alice.family.total_expenses += Alice.child.school.school_trips;
    }

    if (month == 1 && Alice.child.school.tuition > 0) {
        Alice.family.common_fund -= Alice.child.school.tuition;
        Alice.family.total_expenses += Alice.child.school.tuition;
    }

    static int last_year = 0;
    if (last_year != year) {
        Alice.child.school.monthly_food = Alice.child.school.monthly_food * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.school.yearly_supplies = Alice.child.school.yearly_supplies * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.school.yearly_activities = Alice.child.school.yearly_activities * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.school.books = Alice.child.school.books * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.school.extra_classes = Alice.child.school.extra_classes * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.school.school_trips = Alice.child.school.school_trips * (100 + Alice.child.expenses_inflation) / 100;
        Alice.child.school.tuition = Alice.child.school.tuition * (100 + Alice.child.education_inflation) / 100;
        last_year = year;
    }
}


void child_additional_activities(int year, int month) {
    if (month == 6) {
        Alice.family.common_fund -= Alice.child.summer_camp;
        Alice.family.total_expenses += Alice.child.summer_camp;
    }

    RUB monthly_activities = Alice.child.music_school + Alice.child.art_school;
    if (month >= 9 || month <= 5) {
        Alice.family.common_fund -= monthly_activities;
        Alice.family.total_expenses += monthly_activities;
    }
}


void family_funds_management(int year) {
    RUB total_funds = Alice.family.vacation_fund + Alice.family.medical_fund +
        Alice.family.home_repair_fund + Alice.family.car_repair_fund;

    if (total_funds < Alice.family.common_fund * 0.3) {
        RUB to_funds = Alice.family.common_fund * 0.05;
        Alice.family.vacation_fund += to_funds * 0.3;
        Alice.family.medical_fund += to_funds * 0.2;
        Alice.family.home_repair_fund += to_funds * 0.3;
        Alice.family.car_repair_fund += to_funds * 0.2;
        Alice.family.common_fund -= to_funds;
    }

    static int last_year = 0;
    if (last_year != year) {
        Alice.family.vacation_fund = Alice.family.vacation_fund * (100 + Alice.family.holidays.inflation) / 100;
        Alice.family.medical_fund = Alice.family.medical_fund * (100 + Alice.health_inflation) / 100;
        Alice.family.home_repair_fund = Alice.family.home_repair_fund * (100 + Alice.utilities_inflation) / 100;
        Alice.family.car_repair_fund = Alice.family.car_repair_fund * (100 + Alice.car.maintenance_inflation) / 100;
        last_year = year;
    }
}


void alice_husband_personal_expenses(int year) {
    static int last_year = 0;
    if (last_year != year) {
        Alice.husband.personal_expenses = Alice.husband.personal_expenses * (100 + Alice.husband.expenses_inflation) / 100;
        last_year = year;
    }
}


void manage_family_budget() {
    if (Alice.family.common_fund > Alice.family.emergency_fund * 2) {
        RUB to_emergency = Alice.family.common_fund * 0.1;
        if (to_emergency > Alice.family.emergency_threshold) {
            Alice.family.emergency_fund += to_emergency;
            Alice.family.common_fund -= to_emergency;
        }
    }

    if (Alice.family.common_fund > Alice.family.monthly_savings_target) {
        RUB min_sum_for_new_deposit = 5000000;
        RUB excess = Alice.family.common_fund - Alice.family.monthly_savings_target;
        if (excess > Alice.family.deposit_threshold) {
            if (Alice.bank.deposit + excess <= min_sum_for_new_deposit) {
                open_new_deposit(excess);
                Alice.family.common_fund -= excess;
            }
        }
    }

    if (Alice.family.common_fund > Alice.family.common_fund_upper_limit) {
        RUB to_bank = Alice.family.common_fund - Alice.family.common_fund_upper_limit;
        if (to_bank > Alice.family.deposit_threshold) {
             Alice.bank.checking += to_bank;
             Alice.family.common_fund -= to_bank;
        }
    }
}


void initialize_all() {
    initialize_banks();

    Alice.family.fathers_money = 5000000;
    Alice.family.initial_deposit = 50000;
    Alice.family.emergency_threshold = 10000;
    Alice.family.deposit_threshold = 50000;
    Alice.family.education_contribution_rate = 0.05;
    Alice.family.husband_savings_rate = 0.1;
    Alice.family.checking_reserve = 50000;
    Alice.family.common_fund_upper_limit = 100000;
    Alice.family.alice_bonus_multiplier = 0.5;
    Alice.family.start_month = 2;
    Alice.family.start_year = 2026;
    Alice.family.end_month = 3;
    Alice.family.end_year = 2037;

    Alice.family.holidays.new_year = 15000;
    Alice.family.holidays.christmas = 10000;
    Alice.family.holidays.birthday_alice = 8000;
    Alice.family.holidays.birthday_husband = 8000;
    Alice.family.holidays.birthday_child = 10000;
    Alice.family.holidays.march_8 = 5000;
    Alice.family.holidays.feb_23 = 5000;
    Alice.family.holidays.other = 20000;
    Alice.family.holidays.inflation = 1.5;

    Alice.family.vacation.summer_vacation = 80000;
    Alice.family.vacation.winter_vacation = 50000;
    Alice.family.vacation.summer_duration_days = 14;
    Alice.family.vacation.winter_duration_days = 7;
    Alice.family.vacation.vacation_inflation = 2.0;

    Alice.family.activities.ice_skating = 3000;
    Alice.family.activities.badminton = 1500;
    Alice.family.activities.sup = 5000;
    Alice.family.activities.shooting_range = 4000;
    Alice.family.activities.activities_inflation = 1.3;

    Alice.family.vacation_fund = 0;
    Alice.family.medical_fund = 0;
    Alice.family.home_repair_fund = 0;
    Alice.family.car_repair_fund = 0;

    Alice.bank.deposit = Alice.family.initial_deposit;
    Alice.bank.checking = 0;
    Alice.bank.deposit_rate = 11.0;
    Alice.bank.deposit_term = 12;
    Alice.bank.months_passed = 0;
    Alice.bank.years_passed = 0;
    Alice.bank.interest_earned_total = 0;
    Alice.bank.max_deposit = 5000000;
    Alice.bank.bank = available_banks[0];

    Alice.fathers_money = Alice.family.fathers_money;
    Alice.salary = 180000;
    Alice.salary_indexation = 2.0;
    Alice.food = 20000;
    Alice.food_inflation = 1.2;
    Alice.utilities = 15000;
    Alice.utilities_inflation = 1.5;
    Alice.entertainment = 10000;
    Alice.entertainment_inflation = 1.3;
    Alice.health_insurance = 8000;
    Alice.health_inflation = 2.0;
    Alice.fitness = 5000;
    Alice.fitness_inflation = 1.2;
    Alice.subscriptions = 3000;
    Alice.subscriptions_inflation = 1.1;
    Alice.beauty = 4000;
    Alice.beauty_inflation = 1.4;
    Alice.clothes = 8000;
    Alice.clothes_inflation = 1.3;
    Alice.hobbies = 3000;
    Alice.hobbies_inflation = 1.2;
    Alice.courses = 5000;
    Alice.courses_inflation = 1.5;

    Alice.music.alice_piano = 5000;
    Alice.music.lesson_price = 1500;
    Alice.music.lessons_per_month = 4;
    Alice.music.music_inflation = 1.2;

    Alice.books.monthly_books = 2000;
    Alice.books.books_per_month = 2;
    Alice.books.average_book_price = 1000;
    Alice.books.book_inflation = 1.3;

    Alice.car.value = 2400000;
    Alice.car.gas = 15000;
    Alice.car.maintenance = 5000;
    Alice.car.gas_inflation = 0.4;
    Alice.car.maintenance_inflation = 1.0;
    Alice.car.purchase_year = 2026;
    Alice.car.years_owned = 0;

    Alice.phone.value = 80000;
    Alice.phone.monthly_payment = 1500;
    Alice.phone.purchase_year = 2026;
    Alice.phone.replacement_cycle = 3;
    Alice.phone.is_contract = true;

    Alice.computer.value = 120000;
    Alice.computer.purchase_year = 2026;
    Alice.computer.replacement_cycle = 3;
    Alice.computer.type = "Laptop";

    Alice.dog.value = 5000;
    Alice.dog.food = 3000;
    Alice.dog.vet = 1000;
    Alice.dog.grooming = 1500;
    Alice.dog.toys = 500;
    Alice.dog.training = 1000;
    Alice.dog.food_inflation = 1.0;
    Alice.dog.vet_inflation = 2.0;
    Alice.dog.grooming_inflation = 1.3;

    Alice.hamster.value = 2000;
    Alice.hamster.food = 2000;
    Alice.hamster.bedding = 1000;
    Alice.hamster.toys = 300;
    Alice.hamster.vet = 500;
    Alice.hamster.food_inflation = 1.0;
    Alice.hamster.bedding_inflation = 1.5;
    Alice.hamster.vet_inflation = 2.0;

    Alice.husband.salary = 250000;
    Alice.husband.personal_expenses = 30000;
    Alice.husband.savings = 100000;
    Alice.husband.salary_indexation = 2.5;
    Alice.husband.expenses_inflation = 1.5;
    Alice.husband.work_lunches = 5000;
    Alice.husband.business_trips = 3000;
    Alice.husband.professional_courses = 4000;

    Alice.husband.car.value = 3000000;
    Alice.husband.car.gas = 18000;
    Alice.husband.car.maintenance = 6000;
    Alice.husband.car.gas_inflation = 0.4;
    Alice.husband.car.maintenance_inflation = 1.0;
    Alice.husband.car.purchase_year = 2026;
    Alice.husband.car.years_owned = 0;

    Alice.husband.phone.value = 80000;
    Alice.husband.phone.monthly_payment = 1500;
    Alice.husband.phone.purchase_year = 2026;
    Alice.husband.phone.replacement_cycle = 3;
    Alice.husband.phone.is_contract = true;

    Alice.husband.computer.value = 150000;
    Alice.husband.computer.purchase_year = 2026;
    Alice.husband.computer.replacement_cycle = 6;
    Alice.husband.computer.type = "Desktop";

    Alice.husband.music.alice_piano = 0;
    Alice.husband.music.child_piano = 0;
    Alice.husband.music.lessons_per_month = 0;
    Alice.husband.music.lesson_price = 0;
    Alice.husband.music.music_inflation = 0;

    Alice.child.monthly_expenses = 15000;
    Alice.child.education_fund = 0;
    Alice.child.clothes = 8000;
    Alice.child.toys = 5000;
    Alice.child.pocket_money = 3000;
    Alice.child.sports = 4000;
    Alice.child.music_school = 3000;
    Alice.child.art_school = 2500;
    Alice.child.summer_camp = 25000;
    Alice.child.expenses_inflation = 1.8;
    Alice.child.education_inflation = 3.0;
    Alice.child.age = 3;
    Alice.child.grade = 0;

    Alice.child.donations.robux = 1500;
    Alice.child.donations.war_thunder = 1000;
    Alice.child.donations.robux_per_month = 1;
    Alice.child.donations.war_thunder_per_month = 1;
    Alice.child.donations.donations_inflation = 1.1;

    Alice.child.music.child_piano = 4000;
    Alice.child.music.lesson_price = 1200;
    Alice.child.music.lessons_per_month = 4;
    Alice.child.music.music_inflation = 1.2;

    Alice.child.school.monthly_food = 5000;
    Alice.child.school.daily_transport = 20;
    Alice.child.school.daily_transport_without_card = 40;
    Alice.child.school.transport_card_cost = 1500;
    Alice.child.school.transport_card_days = 25;
    Alice.child.school.school_days_per_month = 30;
    Alice.child.school.yearly_supplies = 10000;
    Alice.child.school.yearly_activities = 15000;
    Alice.child.school.books = 2000;
    Alice.child.school.extra_classes = 4000;
    Alice.child.school.school_trips = 8000;
    Alice.child.school.uniform_cost = 20000;
    Alice.child.school.start_year = 2030;
    Alice.child.school.start_month = 9;
    Alice.child.school.tuition = 0;

    Alice.family.common_fund = 0;
    Alice.family.emergency_fund = 0;
    Alice.family.monthly_savings_target = 50000;
    Alice.family.total_expenses = 0;
    Alice.family.total_income = 0;

    Alice.family.common_fund += Alice.family.fathers_money;
    RUB initial_purchases = Alice.car.value + Alice.dog.value + Alice.hamster.value +
        Alice.husband.car.value + Alice.phone.value + Alice.husband.phone.value +
        Alice.computer.value + Alice.husband.computer.value;
    Alice.family.common_fund -= initial_purchases;
}


void print_year_stats(int year) {
    printf("\n=== Year %d ===\n", year);
    printf("Family total income: %lld RUB\n", Alice.family.total_income);
    printf("Family total expenses: %lld RUB\n", Alice.family.total_expenses);
    printf("Emergency fund: %lld RUB\n", Alice.family.emergency_fund);
    printf("Bank deposit: %lld RUB (rate %.1f%% in %s)\n",
        Alice.bank.deposit, Alice.bank.deposit_rate, Alice.bank.bank.name);
    printf("Child education fund: %lld RUB\n", Alice.child.education_fund);
    printf("Husband personal savings: %lld RUB\n", Alice.husband.savings);
    printf("Vacation fund: %lld RUB\n", Alice.family.vacation_fund);
    printf("Medical fund: %lld RUB\n", Alice.family.medical_fund);
    printf("Home repair fund: %lld RUB\n", Alice.family.home_repair_fund);
    printf("Car repair fund: %lld RUB\n", Alice.family.car_repair_fund);
    printf("Child age: %d, Grade: %d\n", Alice.child.age, Alice.child.grade);
    printf("Alice's car years owned: %d, Husband's car years owned: %d\n",
        Alice.car.years_owned, Alice.husband.car.years_owned);
    printf("Phone replacement years: Alice %d, Husband %d\n",
        Alice.phone.replacement_cycle - (year - Alice.phone.purchase_year),
        Alice.husband.phone.replacement_cycle - (year - Alice.husband.phone.purchase_year));
    printf("Computer replacement years: Alice %d, Husband %d\n\n",
        Alice.computer.replacement_cycle - (year - Alice.computer.purchase_year),
        Alice.husband.computer.replacement_cycle - (year - Alice.husband.computer.purchase_year));
}


void simulation() {
    int month = Alice.family.start_month;
    int year = Alice.family.start_year;

    alice_salary(1, Alice.family.start_year);

    while (!((month == Alice.family.end_month) && (year == Alice.family.end_year))) {

        alice_salary(month, year);
        husband_salary(month, year);

        alice_dog(year);
        alice_hamster(year);
        alice_food(year);
        alice_car(year);
        husband_car(year);
        alice_utilities(year);
        alice_entertainment(year);
        alice_health_insurance(year);
        alice_fitness(year);
        alice_subscriptions(year);
        alice_books(year);
        alice_beauty(year);
        alice_clothes(year);
        alice_hobbies(year);
        alice_courses(year);
        alice_music(year);
        husband_work_expenses(year);
        husband_courses(year);
        husband_music(year);
        phone_expenses(year);
        computer_expenses(year);
        holiday_expenses(year, month);
        vacation_expenses(year, month);
        family_activities(year, month);
        child_donations(year);
        child_transport(year, month);
        child_music(year);
        school_expenses(year, month);
        child_additional_activities(year, month);
        family_funds_management(year);
        alice_husband_personal_expenses(year);
        child_expenses(year);

        manage_family_budget();

        ++month;
        if (month == 13) {
            month = 1;
            ++year;

            bank_interest_yearly(year);

            print_year_stats(year);

            Alice.family.total_expenses = 0;
            Alice.family.total_income = 0;
        }
    }
}


void print_results() {
    RUB total_capital = Alice.bank.deposit + Alice.bank.checking +
        Alice.family.emergency_fund + Alice.child.education_fund +
        Alice.husband.savings + Alice.family.common_fund +
        Alice.family.vacation_fund + Alice.family.medical_fund +
        Alice.family.home_repair_fund + Alice.family.car_repair_fund;

    RUB initial_capital = Alice.family.fathers_money + Alice.family.initial_deposit;
    RUB profit = total_capital - initial_capital;
    double return_percentage = (double)profit / initial_capital * 100;

    printf("\n========== FINAL RESULTS (March 2037) ==========\n\n");

    printf("=== Alice ===\n");
    printf("Salary: %lld RUB\n", Alice.salary);
    printf("Deposit: %lld RUB\n", Alice.bank.deposit);
    printf("Checking account: %lld RUB\n", Alice.bank.checking);
    printf("Bank: %s (rate %.1f%%)\n",
        Alice.bank.bank.name, Alice.bank.deposit_rate);
    printf("Piano lessons: %lld RUB/month\n", Alice.music.alice_piano);
    printf("Total interest earned: %lld RUB\n", Alice.bank.interest_earned_total);

    printf("\n=== Family ===\n");
    printf("Common family fund: %lld RUB\n", Alice.family.common_fund);
    printf("Emergency fund: %lld RUB\n", Alice.family.emergency_fund);
    printf("Vacation fund: %lld RUB\n", Alice.family.vacation_fund);
    printf("Medical fund: %lld RUB\n", Alice.family.medical_fund);
    printf("Home repair fund: %lld RUB\n", Alice.family.home_repair_fund);
    printf("Car repair fund: %lld RUB\n", Alice.family.car_repair_fund);

    printf("\n=== Husband ===\n");
    printf("Husband salary: %lld RUB\n", Alice.husband.salary);
    printf("Husband personal savings: %lld RUB\n", Alice.husband.savings);

    printf("\n=== Child ===\n");
    printf("Child age: %d years\n", Alice.child.age);
    printf("Child grade: %d\n", Alice.child.grade);
    printf("Education fund: %lld RUB\n", Alice.child.education_fund);
    printf("Piano lessons: %lld RUB/month\n", Alice.child.music.child_piano);
    printf("Roblox donations: %lld RUB/month\n", Alice.child.donations.robux);
    printf("War Thunder donations: %lld RUB/month\n", Alice.child.donations.war_thunder);

    printf("\n=== School Transport ===\n");
    printf("Monthly transport with card: %lld RUB\n", Alice.child.school.daily_transport);
    printf("Monthly transport without card: %lld RUB\n", Alice.child.school.daily_transport_without_card);
    printf("Transport card cost: %lld RUB\n", Alice.child.school.transport_card_cost);
    printf("Card days per month: %d\n", Alice.child.school.transport_card_days);

    printf("\n=== Family Activities ===\n");
    printf("Ice skating (winter): %lld RUB/month\n", Alice.family.activities.ice_skating);
    printf("Badminton (spring): %lld RUB/month\n", Alice.family.activities.badminton);
    printf("SUP (summer): %lld RUB/month\n", Alice.family.activities.sup);
    printf("Shooting range (autumn): %lld RUB/month\n", Alice.family.activities.shooting_range);

    printf("\n=== Vacations ===\n");
    printf("Summer vacation: %lld RUB\n", Alice.family.vacation.summer_vacation);
    printf("Winter vacation: %lld RUB\n", Alice.family.vacation.winter_vacation);

    printf("\n=== ASSETS ===\n");
    printf("Alice's Car: %lld RUB\n", Alice.car.value);
    printf("Husband's Car: %lld RUB\n", Alice.husband.car.value);
    printf("Dog: %lld RUB\n", Alice.dog.value);
    printf("Hamster: %lld RUB\n", Alice.hamster.value);
    printf("Alice's Phone: %lld RUB\n", Alice.phone.value);
    printf("Husband's Phone: %lld RUB\n", Alice.husband.phone.value);
    printf("Alice's Computer: %lld RUB\n", Alice.computer.value);
    printf("Husband's Computer: %lld RUB\n", Alice.husband.computer.value);

    printf("\n=== TOTAL CAPITAL ===\n");
    printf("Total family capital: %lld RUB\n", total_capital);
    printf("Initial capital (father's money + initial deposit): %lld RUB\n", initial_capital);
    printf("Profit for the period: %lld RUB\n", profit);
    printf("Return: %.1f%%\n", return_percentage);

    printf("\n================================================\n");
}


int main() {
    printf("=== FAMILY BUDGET SIMULATION ===\n");
    printf("Start: February 2026\n");
    printf("End: March 2037\n\n");

    initialize_all();
    simulation();
    print_results();

    return 0;
}