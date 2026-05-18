#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

using RUB = long long int;

vector<double> inflation_history;


struct Healthy_Food {
    RUB meat;
    RUB eggs;
    RUB greenery;
    RUB milk;
    RUB bread;
    RUB vegetablse;
    RUB cereal;
    RUB tea;
    RUB coffee;
    RUB fruits;
    RUB porridge;
};

struct Travel {
    RUB airplane_ticket;
    RUB hotel;
    RUB souvenirs;
    RUB excursions;
    RUB train_tickets;
    RUB ski_rental;
    RUB aquapark;
    RUB amusementpark;
    RUB cave;
    RUB fishing;
    RUB guadbike;
    RUB diving;
    RUB surfing;
    RUB kayak;
    bool winter_trip_food = false;
    bool summer_trip_food = false;
};

struct Apartment {
    RUB value;
    RUB communal;
};

struct Clothes {
    RUB shoes;
    RUB socks;
    RUB pants;
    RUB sneakers;
    RUB jeans;
    RUB trousers;
    RUB tshirt;
    RUB dress;
    RUB brassiere;
    RUB hat;
    RUB swimsuit;
    RUB jacket;
    RUB coat;
    RUB bag;
};

struct Cat {
    RUB value;
    RUB food;
    RUB vetclinic;
    RUB ill;
};

struct TAX {
    double tax;
    RUB salaryyear;
    RUB sum;
};

struct Economictyges {
    double indexation;
    double inflation;
};

struct Bank {
    RUB depozit;
    float percent;
    RUB account;
    short period;
    bool has_depozit;
    bool indefinite_depozit;
};

struct Car {
    RUB value;
    RUB gas;
    RUB maintenance;
    RUB wintertires;
    RUB engine_oil;
    RUB insurance_KASKO;
    RUB insuranse_OSAGO;
    RUB wheels;
    RUB traffic_accident_value;
    RUB calculation;
    short age;
    short driving_experience;
    bool traffic_accident_quilty;
    bool traffic_accident;
    bool KASKO;
    bool OSAGO;
};

struct Money {
    RUB salary;
    double highprice;
};

struct Person {
    Cat cat;
    RUB capital;
    Car car;
    Bank bank;
    Apartment apartment;
    Travel trip;
    TAX tax;
    Economictyges economic;
    Money money;
    RUB ill;
    Clothes clothes;
    Healthy_Food food;
    short age;
};

Person alice;

void alice_init() {
    alice.capital = 0;
    alice.bank.account = 0;
    alice.bank.depozit = 0;

    alice.money.salary = 120000;
    alice.money.highprice = 0;

    alice.ill = 1500;

    alice.apartment.value = 12000000;
    alice.apartment.communal = 18000;

    alice.car.value = 2400000;
    alice.car.gas = 12000;
    alice.car.maintenance = 6000;
    alice.car.wintertires = 10000;
    alice.car.traffic_accident = false;
    alice.car.engine_oil = 5000;
    alice.car.insurance_KASKO = 0;
    alice.car.insuranse_OSAGO = 0;
    alice.car.wheels = 10000;
    alice.car.driving_experience = 0;
    alice.car.traffic_accident_quilty = false;
    alice.car.calculation = 10000;

    alice.cat.food = 6000;
    alice.cat.value = 10000;
    alice.cat.ill = 25000;
    alice.cat.vetclinic = 0;

    alice.economic.indexation = 10;
    alice.economic.inflation = 13;

    alice.tax.salaryyear = 0;
    alice.tax.sum = 0;
    alice.tax.tax = 0;

    alice.clothes.shoes = 7000;
    alice.clothes.socks = 500;
    alice.clothes.pants = 4000;
    alice.clothes.sneakers = 8000;
    alice.clothes.jeans = 5000;
    alice.clothes.trousers = 4500;
    alice.clothes.tshirt = 1500;
    alice.clothes.dress = 6000;
    alice.clothes.brassiere = 2000;
    alice.clothes.hat = 3000;
    alice.clothes.swimsuit = 5000;
    alice.clothes.jacket = 12000;
    alice.clothes.coat = 10000;
    alice.clothes.bag = 8000;

    alice.trip.hotel = 50000;
    alice.trip.airplane_ticket = 12000;
    alice.trip.excursions = 3000;
    alice.trip.ski_rental = 7000;
    alice.trip.souvenirs = 2000;
    alice.trip.train_tickets = 7000;
    alice.trip.aquapark = 3000;
    alice.trip.amusementpark = 2500;
    alice.trip.cave = 1500;
    alice.trip.fishing = 2000;
    alice.trip.guadbike = 3000;
    alice.trip.diving = 4000;
    alice.trip.surfing = 3500;
    alice.trip.kayak = 2500;

    alice.food.meat = 7000;
    alice.food.vegetablse = 3500;
    alice.food.cereal = 800;
    alice.food.fruits = 3300;
    alice.food.milk = 3000;
    alice.food.eggs = 500;
    alice.food.porridge = 1000;
    alice.food.bread = 1500;
    alice.food.tea = 1700;
    alice.food.coffee = 4000;
    alice.food.greenery = 1000;

    alice.age = 17;
}

bool true_with_probability(unsigned int permille)
{
    if (permille == 0) return false;
    unsigned int second_operand = std::pow(2, 1 - (1000 / (double)permille));
    return rand() % second_operand;
}

void random_lottery_win(int month) {
    if (rand() % 500 == 0) {
        RUB win = 50000 + rand() % 500000;
        alice.bank.account += win;
    }
}

void random_fine(int month) {
    if (rand() % 20 == 0) {
        RUB fine = 500 + rand() % 5000;
        alice.bank.account += fine;
    }
}

void random_gift_from_relatives(int month) {
    if (1 + rand() % 10 < 6 && month == 12) {
        RUB gift = 10000 + rand() % 100000;
        alice.bank.account += gift;
    }
}

void level_inflation_indexation(bool& high_inflation, bool& high_indexation, bool& middle_inflation, bool& middle_indexation, bool& low_inflation, bool& low_indexation) {
    if (alice.economic.inflation >= 22) {
        high_inflation = true;
        middle_inflation = false;
        low_inflation = false;
    }
    else if (alice.economic.inflation > 5 && alice.economic.inflation < 22) {
        middle_inflation = true;
        high_inflation = false;
        low_inflation = false;
    }
    else if (alice.economic.inflation <= 5 && alice.economic.inflation > -3) {
        low_inflation = true;
        middle_inflation = false;
        high_inflation = false;
    }

    if (alice.economic.indexation >= 19) {
        high_indexation = true;
        middle_indexation = false;
        low_indexation = false;
    }
    else if (alice.economic.indexation > 4 && alice.economic.indexation < 19) {
        middle_indexation = true;
        high_indexation = false;
        low_indexation = false;
    }
    else if (alice.economic.indexation <= 4 && alice.economic.indexation >= 0) {
        low_indexation = true;
        high_indexation = false;
        middle_indexation = false;
    }
}

void inflation_index(const int month, bool high_inflation, bool high_indexation, bool middle_inflation, bool middle_indexation, bool low_inflation, bool low_indexation) {
    short random_inflation_ivent = 1 + rand() % 1000;
    short random_inflation = 1 + rand() % 30;
    short r = 1 + rand() % 2;

    if (month == 6 || month == 12) {
        if (middle_inflation) {
            switch (r) {
            case 1: alice.economic.inflation -= random_inflation / 10; break;
            case 2: alice.economic.inflation += random_inflation / 10; break;
            }
        }
        else if (high_inflation) {
            alice.economic.inflation -= random_inflation / 10;
        }
        else if (low_inflation) {
            alice.economic.inflation += random_inflation / 10;
        }

        if (random_inflation_ivent > 890 && random_inflation_ivent < 960) {
            switch (r) {
            case 1: alice.economic.inflation -= 4; break;
            case 2: alice.economic.inflation += 5; break;
            }
        }
        else if (random_inflation_ivent >= 970) {
            alice.economic.inflation += 11;
        }
    }
}

void infation_indexation_index(const int month) {
    static bool high_inflation = false;
    static bool high_indexation = false;
    static bool middle_inflation = false;
    static bool middle_indexation = false;
    static bool low_inflation = false;
    static bool low_indexation = false;
    short random_indexation_ivent = 1 + rand() % 1000;
    short random_indexation = 1 + rand() % 25;
    short r = 1 + rand() % 2;

    level_inflation_indexation(high_inflation, high_indexation, middle_inflation, middle_indexation, low_inflation, low_indexation);
    inflation_index(month, high_inflation, high_indexation, middle_inflation, middle_indexation, low_inflation, low_indexation);
    if (month == 6 || month == 12) {
        if (middle_inflation && middle_indexation) {
            switch (r) {
            case 1: alice.economic.indexation -= random_indexation / 10; break;
            case 2: alice.economic.indexation += random_indexation / 10; break;
            }
        }
        else if (middle_inflation && high_indexation) {
            switch (r) {
            case 1: alice.economic.indexation -= random_indexation / 10; break;
            case 2: alice.economic.indexation += random_indexation / 20; break;
            }
        }
        else if (middle_inflation && low_indexation) {
            switch (r) {
            case 1: alice.economic.indexation -= random_indexation / 20; break;
            case 2: alice.economic.indexation += random_indexation / 10; break;
            }
        }
        else if (high_inflation && middle_indexation) {
            switch (r) {
            case 1: alice.economic.indexation -= random_indexation / 20; break;
            case 2: alice.economic.indexation += random_indexation / 10; break;
            }
        }
        else if (high_inflation && high_indexation) {
            switch (r) {
            case 1: alice.economic.indexation -= random_indexation / 10; break;
            case 2: alice.economic.indexation += random_indexation / 10; break;
            }
        }
        else if (high_inflation && low_indexation) {
            alice.economic.indexation += random_indexation / 10;
        }
        else if (low_inflation && middle_indexation) {
            alice.economic.indexation -= random_indexation / 10;
        }
        else if (low_inflation && high_indexation) {
            alice.economic.indexation -= random_indexation / 4;
        }
        else if (low_inflation && low_indexation) {
            switch (r) {
            case 1: alice.economic.indexation -= random_indexation / 20; break;
            case 2: alice.economic.indexation += random_indexation / 40; break;
            }
        }

        if (random_indexation_ivent > 950 && random_indexation_ivent <= 1000) {
            alice.economic.indexation = alice.economic.inflation;
        }
        else if (random_indexation_ivent <= 10) {
            alice.economic.indexation = 0;
        }
    }
    inflation_history.push_back(alice.economic.inflation);
}


void plot_inflation() {
    cout << "\nИнфляция по месяцам (%%):\n";
    for (size_t i = 0; i < inflation_history.size(); ++i) {
        int bars = static_cast<int>(inflation_history[i] / 2); // 1 звезда = 2%
        if (bars > 80) bars = 80;
        cout << "Месяц " << i + 1 << " (" << 2026 + i / 12 << "." << i % 12 + 1 << "): ";
        cout << string(bars, '*') << " " << fixed << setprecision(2) << inflation_history[i] << "%\n";
    }
}


void random_value_a_procent(RUB thing, short random_plus_minus, short random, short procent) {
    switch (random) {
    case 1: alice.bank.account -= thing * random / 100; break;
    case 2: alice.bank.account += thing * random / 100; break;
    }
}

float random_depozit_procent(int inflation, short random, short random_spread, short a) {
    switch (random) {
    case 1: alice.bank.percent -= inflation * random_spread / 100; break;
    case 2: alice.bank.percent += inflation * random_spread / 100; break;
    }
    return alice.bank.percent;
}

void winter_food(const int month) {
    if (month == 12 || month == 1 || month == 2) {
        alice.bank.account -= alice.food.vegetablse;
        alice.bank.account -= alice.food.greenery;
        alice.bank.account -= alice.food.fruits * 0.5;
    }
}

void summer_food(const int month) {
    if (month < 9 && month > 4) {
        alice.bank.account += alice.food.vegetablse * 0.5;
        alice.bank.account += alice.food.greenery * 0.5;
        alice.bank.account += alice.food.fruits * 0.5;
    }
}

void apply_inflation_to_food(const int month) {
    if (month == 1) {
        float inf = alice.economic.inflation / 100.0;
        alice.food.bread += alice.food.bread * inf;
        alice.food.meat += alice.food.meat * inf;
        alice.food.cereal += alice.food.cereal * inf;
        alice.food.coffee += alice.food.coffee * inf;
        alice.food.eggs += alice.food.eggs * inf;
        alice.food.fruits += alice.food.fruits * inf;
        alice.food.greenery += alice.food.greenery * inf;
        alice.food.milk += alice.food.milk * inf;
        alice.food.porridge += alice.food.porridge * inf;
        alice.food.tea += alice.food.tea * inf;
        alice.food.vegetablse += alice.food.vegetablse * inf;
    }
}

double tax_rate(int year_income) {
    if (alice.tax.salaryyear < 2400000) {
        return 13;
    }
    else if (alice.tax.salaryyear >= 2400000 && alice.tax.salaryyear < 5000000) {
        return 15;
    }
    else if (alice.tax.salaryyear >= 5000000 && alice.tax.salaryyear < 20000000) {
        return 18;
    }
    else if (alice.tax.salaryyear >= 20000000 && alice.tax.salaryyear < 50000000) {
        return 20;
    }
    else return 22;
}

void winter_trip(const int month) {
    static bool winter_trip_agree = true;
    short randomtrip = 1 + rand() % 50;
    short rt = 1 + rand() % 2;
    short r = 1 + rand() % 2;
    double conditoinals_trip = 100000;

    if ((month == 12 || month == 1 || month == 2) && (rand() % 5 == 1) && winter_trip_agree) {
        winter_trip_agree = false;
        static bool winter_trip_food = true;

        if (alice.bank.depozit < conditoinals_trip * 4) {
            switch (r) {
            case 1: alice.bank.depozit += alice.trip.train_tickets * randomtrip / 100; break;
            case 2: alice.bank.depozit -= alice.trip.train_tickets * randomtrip / 100; break;
            }

            alice.bank.depozit -= alice.trip.train_tickets;

            double hotel_two_star = alice.trip.hotel;
            switch (rt) {
            case 1: alice.bank.depozit -= hotel_two_star * randomtrip / 100; break;
            case 2: alice.bank.depozit += hotel_two_star * randomtrip / 100; break;
            }
            alice.bank.depozit -= hotel_two_star;

            alice.bank.depozit -= alice.trip.souvenirs;
            if (rand() % 4 == 0)
                alice.bank.depozit -= alice.trip.excursions;
            alice.bank.depozit -= alice.trip.ski_rental;
        }
        else if (alice.bank.depozit >= conditoinals_trip * 4 && alice.bank.depozit < conditoinals_trip * 10) {
            if (r == 1)
                alice.bank.depozit += alice.trip.airplane_ticket * randomtrip / 100;
            else
                alice.bank.depozit -= alice.trip.airplane_ticket * randomtrip / 100;
            alice.bank.depozit -= alice.trip.airplane_ticket;

            double hotel_three_star = alice.trip.hotel * 1.8;
            switch (rt) {
            case 1: alice.bank.depozit -= hotel_three_star * randomtrip / 100; break;
            case 2: alice.bank.depozit += hotel_three_star * randomtrip / 100; break;
            }
            alice.bank.depozit -= hotel_three_star;
            alice.bank.depozit -= alice.trip.souvenirs * 2;
            if (rand() % 4 < 3) {
                int ve = 1 + rand() % 2;
                alice.bank.depozit -= alice.trip.excursions * ve;
            }
            alice.bank.depozit -= alice.trip.ski_rental * 1.5;
        }
        else if (alice.bank.depozit >= conditoinals_trip * 10 && alice.bank.depozit < conditoinals_trip * 18) {
            double airplane_bisness = alice.trip.airplane_ticket * 2.5;
            if (r == 1)
                alice.bank.depozit += alice.trip.airplane_ticket * randomtrip / 100;
            else
                alice.bank.depozit -= alice.trip.airplane_ticket * randomtrip / 100;
            alice.bank.depozit -= airplane_bisness;

            double hotel_four_star = alice.trip.hotel * 3;
            switch (rt) {
            case 1: alice.bank.depozit -= hotel_four_star * randomtrip / 100; break;
            case 2: alice.bank.depozit += hotel_four_star * randomtrip / 100; break;
            }
            alice.bank.depozit -= hotel_four_star;
            alice.bank.depozit -= alice.trip.souvenirs * 3;
            if (rand() % 4 < 4) {
                int ve = 1 + rand() % 3;
                alice.bank.depozit -= alice.trip.excursions * ve;
            }
            alice.bank.depozit -= alice.trip.ski_rental * 2;
        }
        else {
            double airplane_bisness = alice.trip.airplane_ticket * 2.5;
            if (r == 1)
                alice.bank.depozit += alice.trip.airplane_ticket * randomtrip / 100;
            else
                alice.bank.depozit -= alice.trip.airplane_ticket * randomtrip / 100;
            alice.bank.depozit -= airplane_bisness;

            double hotel_five_star = alice.trip.hotel * 5;
            switch (rt) {
            case 1: alice.bank.depozit -= hotel_five_star * randomtrip / 100; break;
            case 2: alice.bank.depozit += hotel_five_star * randomtrip / 100; break;
            }
            alice.bank.depozit -= hotel_five_star;
            alice.bank.depozit -= alice.trip.souvenirs * 3;
            if (rand() % 4 < 4) {
                int ve = 1 + rand() % 4;
                alice.bank.depozit -= alice.trip.excursions * ve;
            }
            alice.bank.depozit -= alice.trip.ski_rental * 3;
        }
    }
    if (month == 3) winter_trip_agree = true;
}

void summer_mountains(const int month) {
    static bool entertainment = true;
    static bool summer_trip_mountain = true;
    int random_trip = 1 + rand() % 50;
    int rt = 1 + rand() % 2;
    int r = 1 + rand() % 2;
    double conditoinals_trip = 100000;

    if (summer_trip_mountain) {
        summer_trip_mountain = false;

        if (alice.bank.depozit < conditoinals_trip * 5) {
            switch (r) {
            case 1: alice.bank.depozit += alice.trip.train_tickets * random_trip / 100; break;
            case 2: alice.bank.depozit -= alice.trip.train_tickets * random_trip / 100; break;
            }
            alice.bank.depozit -= alice.trip.train_tickets;
            alice.bank.depozit -= alice.trip.souvenirs / 2;

            if (rand() % 4 == 0) {
                alice.bank.depozit -= alice.trip.excursions;
            }

            if (rand() % 4 == 3 && entertainment) {
                alice.bank.depozit -= alice.trip.cave;
                entertainment = false;
            }
            if (rand() % 4 == 1 && entertainment) {
                alice.bank.depozit -= alice.trip.kayak;
                entertainment = false;
            }
            if (rand() % 4 == 2 && entertainment) {
                alice.bank.depozit -= alice.trip.fishing;
                entertainment = false;
            }
            if (rand() % 4 == 0 && entertainment) {
                alice.bank.depozit -= alice.trip.guadbike;
                entertainment = false;
            }

            entertainment = true;
        }
        else if (alice.bank.depozit >= conditoinals_trip * 4 && alice.bank.depozit < conditoinals_trip * 10) {
            switch (r) {
            case 1: alice.bank.depozit += alice.trip.airplane_ticket * random_trip / 100; break;
            case 2: alice.bank.depozit -= alice.trip.airplane_ticket * random_trip / 100; break;
            }
            alice.bank.depozit -= alice.trip.airplane_ticket;

            double hotel_three_star = alice.trip.hotel * 1.8;
            switch (rt) {
            case 1: alice.bank.depozit -= hotel_three_star * random_trip / 100; break;
            case 2: alice.bank.depozit += hotel_three_star * random_trip / 100; break;
            }
            alice.bank.depozit -= hotel_three_star;
            alice.bank.depozit -= alice.trip.souvenirs * 2;

            if (rand() % 4 < 3) {
                int ve = 1 + rand() % 2;
                alice.bank.depozit -= alice.trip.excursions * ve;
            }

            if (rand() % 4 == 3) {
                alice.bank.depozit -= alice.trip.cave;
            }

            if (rand() % 4 == 1 && entertainment) {
                alice.bank.depozit -= alice.trip.kayak;
                entertainment = false;
            }
            if (rand() % 4 == 2 && entertainment) {
                alice.bank.depozit -= alice.trip.fishing;
                entertainment = false;
            }
            if (rand() % 4 == 0 && entertainment) {
                alice.bank.depozit -= alice.trip.guadbike;
                entertainment = false;
            }

            entertainment = true;
        }
        else if (alice.bank.depozit >= conditoinals_trip * 10 && alice.bank.depozit < conditoinals_trip * 18) {
            double airplane_bisness = alice.trip.airplane_ticket * 2.5;

            switch (r) {
            case 1: alice.bank.depozit += alice.trip.airplane_ticket * random_trip / 100; break;
            case 2: alice.bank.depozit -= alice.trip.airplane_ticket * random_trip / 100; break;
            }
            alice.bank.depozit -= airplane_bisness;

            double hotel_four_star = alice.trip.hotel * 3;
            switch (rt) {
            case 1: alice.bank.depozit -= hotel_four_star * random_trip / 100; break;
            case 2: alice.bank.depozit += hotel_four_star * random_trip / 100; break;
            }
            alice.bank.depozit -= hotel_four_star;
            alice.bank.depozit -= alice.trip.souvenirs * 3;

            if (rand() % 4 < 4) {
                int ve = 1 + rand() % 3;
                alice.bank.depozit -= alice.trip.excursions * ve;
            }

            if (rand() % 4 == 3) {
                alice.bank.depozit -= alice.trip.cave;
            }
            if (rand() % 4 == 1) {
                alice.bank.depozit -= alice.trip.kayak;
            }
            if (rand() % 4 == 2) {
                alice.bank.depozit -= alice.trip.fishing;
            }
            if (rand() % 4 == 0) {
                alice.bank.depozit -= alice.trip.guadbike;
            }
        }
        else {
            double airplane_bisness = alice.trip.airplane_ticket * 2.5;

            switch (r) {
            case 1: alice.bank.depozit += alice.trip.airplane_ticket * random_trip / 100; break;
            case 2: alice.bank.depozit -= alice.trip.airplane_ticket * random_trip / 100; break;
            }
            alice.bank.depozit -= airplane_bisness;

            double hotel_five_star = alice.trip.hotel * 5;
            switch (rt) {
            case 1: alice.bank.depozit -= hotel_five_star * random_trip / 100; break;
            case 2: alice.bank.depozit += hotel_five_star * random_trip / 100; break;
            }
            alice.bank.depozit -= hotel_five_star;
            alice.bank.depozit -= alice.trip.souvenirs * 3;

            if (rand() % 4 < 4) {
                int ve = 1 + rand() % 4;
                alice.bank.depozit -= alice.trip.excursions * ve;

                if (rand() % 4 < 3) {
                    alice.bank.depozit -= alice.trip.cave * 2;
                }
                if (rand() % 4 < 3) {
                    alice.bank.depozit -= alice.trip.kayak * 2;
                }
                if (rand() % 4 < 3) {
                    alice.bank.depozit -= alice.trip.fishing * 2;
                }
                if (rand() % 4 < 3) {
                    alice.bank.depozit -= alice.trip.guadbike * 2;
                }
            }
        }
    }

    if (month == 10) {
        summer_trip_mountain = true;
    }
}

void summer_sea(const int month) {
    static bool summer_trip_sea = true;
    static bool entertainment = true;
    int random_trip = 1 + rand() % 50;
    int rt = 1 + rand() % 2;
    int r = 1 + rand() % 2;
    double conditoinals_trip = 100000;

    if (summer_trip_sea) {
        summer_trip_sea = false;
        if (alice.bank.depozit < conditoinals_trip * 5) {
            switch (r) {
            case 1: alice.bank.depozit += alice.trip.train_tickets * random_trip / 100; break;
            case 2: alice.bank.depozit -= alice.trip.train_tickets * random_trip / 100; break;
            }

            alice.bank.depozit -= alice.trip.train_tickets;

            alice.bank.depozit -= alice.trip.souvenirs / 2;

            if (rand() % 4 == 0) {
                alice.bank.depozit -= alice.trip.excursions;
            }

            if (rand() % 4 == 3 && entertainment) {
                alice.bank.depozit -= alice.trip.diving;
                entertainment = false;
            }

            if (rand() % 4 == 1 && entertainment) {
                alice.bank.depozit -= alice.trip.surfing;
                entertainment = false;
            }

            if (rand() % 4 == 2 && entertainment) {
                alice.bank.depozit -= alice.trip.kayak;
                entertainment = false;
            }

            if (rand() % 4 == 0 && entertainment) {
                alice.bank.depozit -= alice.trip.aquapark;
                entertainment = false;
            }

            entertainment = true;
        }
        else if (alice.bank.depozit >= conditoinals_trip * 4 && alice.bank.depozit < conditoinals_trip * 10) {
            if (r == 1)
                alice.bank.depozit += alice.trip.airplane_ticket * random_trip / 100;
            else
                alice.bank.depozit -= alice.trip.airplane_ticket * random_trip / 100;
            alice.bank.depozit -= alice.trip.airplane_ticket;

            double hotel_three_star = alice.trip.hotel * 1.8;

            switch (rt) {
            case 1: alice.bank.depozit -= hotel_three_star * random_trip / 100; break;
            case 2: alice.bank.depozit += hotel_three_star * random_trip / 100; break;
            }

            alice.bank.depozit -= hotel_three_star;

            alice.bank.depozit -= alice.trip.souvenirs * 2;

            if (rand() % 4 < 3) {
                int ve = 1 + rand() % 2;
                alice.bank.depozit -= alice.trip.excursions * ve;
            }

            if (rand() % 4 == 3) {
                alice.bank.depozit -= alice.trip.diving;
            }

            if (rand() % 4 == 1 && entertainment) {
                alice.bank.depozit -= alice.trip.surfing;
                entertainment = false;
            }

            if (rand() % 4 == 2 && entertainment) {
                alice.bank.depozit -= alice.trip.kayak;
                entertainment = false;
            }

            if (rand() % 4 == 0 && entertainment) {
                alice.bank.depozit -= alice.trip.aquapark;
                entertainment = false;
            }

            entertainment = true;
        }
        else if (alice.bank.depozit >= conditoinals_trip * 10 && alice.bank.depozit < conditoinals_trip * 18) {
            double airplane_bisness = alice.trip.airplane_ticket * 2.5;

            switch (r) {
            case 1: alice.bank.depozit += alice.trip.airplane_ticket * random_trip / 100; break;
            case 2: alice.bank.depozit -= alice.trip.airplane_ticket * random_trip / 100; break;
            }

            alice.bank.depozit -= airplane_bisness;

            double hotel_four_star = alice.trip.hotel * 3;

            switch (rt) {
            case 1: alice.bank.depozit -= hotel_four_star * random_trip / 100; break;
            case 2: alice.bank.depozit += hotel_four_star * random_trip / 100; break;
            }

            alice.bank.depozit -= hotel_four_star;

            alice.bank.depozit -= alice.trip.souvenirs * 3;

            if (rand() % 4 < 4) {
                int ve = 1 + rand() % 3;
                alice.bank.depozit -= alice.trip.excursions * ve;
            }

            if (rand() % 4 == 3) {
                alice.bank.depozit -= alice.trip.diving;
            }

            if (rand() % 4 == 1) {
                alice.bank.depozit -= alice.trip.surfing;
            }

            if (rand() % 4 == 2) {
                alice.bank.depozit -= alice.trip.kayak;
            }

            if (rand() % 4 == 0) {
                alice.bank.depozit -= alice.trip.amusementpark;
            }
        }
        else {
            double airplane_bisness = alice.trip.airplane_ticket * 2.5;

            switch (r) {
            case 1: alice.bank.depozit += alice.trip.airplane_ticket * random_trip / 100; break;
            case 2: alice.bank.depozit -= alice.trip.airplane_ticket * random_trip / 100; break;
            }

            alice.bank.depozit -= airplane_bisness;

            double hotel_five_star = alice.trip.hotel * 5;

            switch (rt) {
            case 1: alice.bank.depozit -= hotel_five_star * random_trip / 100; break;
            case 2: alice.bank.depozit += hotel_five_star * random_trip / 100; break;
            }

            alice.bank.depozit -= hotel_five_star;

            alice.bank.depozit -= alice.trip.souvenirs * 3;

            if (rand() % 4 < 4) {
                int ve = 1 + rand() % 4;
                alice.bank.depozit -= alice.trip.excursions * ve;

                if (rand() % 4 < 3) {
                    alice.bank.depozit -= alice.trip.diving * 2;
                }

                if (rand() % 4 < 3) {
                    alice.bank.depozit -= alice.trip.surfing * 2;
                }

                if (rand() % 4 < 3) {
                    alice.bank.depozit -= alice.trip.kayak * 2;
                }

                if (rand() % 4 < 3) {
                    alice.bank.depozit -= alice.trip.aquapark * 2;
                }

                if (rand() % 4 < 3) {
                    alice.bank.depozit -= alice.trip.amusementpark * 2;
                }
            }
        }
    }
    if (month == 10) {
        summer_trip_sea = true;
    }
}

void apply_inflation_to_travel() {
    float inf = alice.economic.inflation / 100.0;
    alice.trip.airplane_ticket += alice.trip.airplane_ticket * inf;
    alice.trip.hotel += alice.trip.hotel * inf;
    alice.trip.souvenirs += alice.trip.souvenirs * inf;
    alice.trip.excursions += alice.trip.excursions * inf;
    alice.trip.train_tickets += alice.trip.train_tickets * inf;
    alice.trip.ski_rental += alice.trip.ski_rental * inf;
    alice.trip.aquapark += alice.trip.aquapark * inf;
    alice.trip.amusementpark += alice.trip.amusementpark * inf;
    alice.trip.cave += alice.trip.cave * inf;
    alice.trip.fishing += alice.trip.fishing * inf;
    alice.trip.guadbike += alice.trip.guadbike * inf;
    alice.trip.diving += alice.trip.diving * inf;
    alice.trip.surfing += alice.trip.surfing * inf;
    alice.trip.kayak += alice.trip.kayak * inf;
}

void travel(const int month) {
    static bool trip_done_sea = false;
    static bool trip_done_mountain = false;
    static bool summer_trip_food = false;
    if (alice.bank.depozit > 300000) {

        if (month >= 5 && month <= 8) {
            if ((rand() % 5 == 2)) {
                trip_done_sea = true;
            }

            if ((rand() % 5 == 1)) {
                trip_done_mountain = true;
            }

            if (trip_done_sea == trip_done_mountain) {
                trip_done_mountain = false;
                trip_done_sea = false;
            }

            if (trip_done_mountain) {
                summer_mountains(month);
                summer_trip_food = true;
            }

            if (trip_done_sea) {
                summer_sea(month);
                summer_trip_food = true;
            }
        }

        winter_trip(month);

        if (month == 1) {
            apply_inflation_to_travel();
        }
    }
}

void apply_inflation_to_clothes(const int month) {
    if (month == 1) {
        float inf = alice.economic.inflation / 100.0;
        alice.clothes.shoes += alice.clothes.shoes * inf;
        alice.clothes.socks += alice.clothes.socks * inf;
        alice.clothes.pants += alice.clothes.pants * inf;
        alice.clothes.sneakers += alice.clothes.sneakers * inf;
        alice.clothes.jeans += alice.clothes.jeans * inf;
        alice.clothes.trousers += alice.clothes.trousers * inf;
        alice.clothes.tshirt += alice.clothes.tshirt * inf;
        alice.clothes.dress += alice.clothes.dress * inf;
        alice.clothes.brassiere += alice.clothes.brassiere * inf;
        alice.clothes.hat += alice.clothes.hat * inf;
        alice.clothes.swimsuit += alice.clothes.swimsuit * inf;
        alice.clothes.jacket += alice.clothes.jacket * inf;
        alice.clothes.coat += alice.clothes.coat * inf;
        alice.clothes.bag += alice.clothes.bag * inf;
    }
}

void alice_clothes(const int month) {
    static bool bought_winter_coat = false;
    static bool bought_winter_jacket = false;
    static bool bought_swimsuit = false;
    static bool bought_hat = false;

    if ((month == 9 || month == 10 || month == 11) && !bought_winter_coat) {
        if (rand() % 3 == 2) {
            alice.bank.account -= alice.clothes.coat;
            bought_winter_coat = true;
        }
    }

    if ((month == 12 || month == 1 || month == 2) && !bought_winter_jacket) {
        if (rand() % 3 == 2) {
            alice.bank.account -= alice.clothes.jacket;
        }
        alice.bank.account -= alice.clothes.shoes;
        bought_winter_jacket = true;
    }

    if ((month >= 5 && month <= 8) && !bought_swimsuit) {
        if (rand() % 3 == 2) {
            alice.bank.account -= alice.clothes.swimsuit;
            bought_swimsuit = true;
        }
    }
    if ((month >= 5 && month <= 8) && !bought_hat) {
        if (rand() % 3 == 1) {
            alice.bank.account -= alice.clothes.hat;
            bought_hat = true;
        }
    }
    if (rand() % 3 == 1) {
        alice.bank.account -= (alice.clothes.pants + alice.clothes.socks);
    }

    if (month == 3) {
        bought_winter_coat = false;
        bought_winter_jacket = false;
    }

    if (month == 8) {
        bought_swimsuit = false;
        bought_hat = false;
    }

    if (rand() % 100 < 5) {
        alice.bank.account -= alice.clothes.tshirt;
    }

    if (rand() % 100 < 3) {
        alice.bank.account -= alice.clothes.jeans;
    }

    if (rand() % 100 < 2) {
        alice.bank.account -= alice.clothes.bag;
    }

    apply_inflation_to_clothes(month);
}

void alice_ill(const int month) {
    short randomill = 1 + rand() % 80;
    short randomvalueill = 1 + rand() % 5;

    if (randomill <= 10) {
        alice.bank.account -= alice.ill * randomvalueill;
    }

    switch (month) {
    case 1:  alice.ill += alice.ill * alice.economic.inflation / 100; break;
    }

    if (randomill > 75) {
        alice.bank.depozit -= alice.ill * randomill * 0.6;
        alice.tax.sum -= alice.ill * randomill * tax_rate(alice.tax.salaryyear);
        if (alice.tax.sum <= 0) {
            alice.tax.sum += alice.ill * randomill * tax_rate(alice.tax.salaryyear);
            alice.bank.depozit += alice.tax.sum;
            alice.tax.sum = 0;
        }
        else {
            alice.bank.depozit += alice.ill * randomill * tax_rate(alice.tax.salaryyear);
        }
    }
}

void alice_capital() {
    alice.capital = alice.car.value + alice.bank.depozit + alice.apartment.value;
}

void alice_apartment(int month) {
    if (month < 3 || month == 12) {
        alice.apartment.communal *= 1.5;
    }

    short randomcommunal = 1 + rand() % 5;
    short rc = 1 + rand() % 2;

    switch (rc) {
    case 1: alice.bank.account -= alice.apartment.communal * randomcommunal / 100; break;
    case 2: alice.bank.account += alice.apartment.communal * randomcommunal / 100; break;
    }

    alice.bank.account -= alice.apartment.communal;

    if (month == 1) {
        alice.apartment.communal += alice.apartment.communal * alice.economic.inflation / 100;
    }

    if (month < 3 || month == 12) {
        alice.apartment.communal /= 1.5;
    }
}

void alice_cat(const int month) {
    if (month == 1) {
        alice.cat.food += alice.cat.food * alice.economic.inflation / 100;
    }

    alice.bank.account -= alice.cat.food;

    short randomcatill = 1 + rand() % 100;
    if (randomcatill < 10) {
        alice.cat.vetclinic = alice.cat.ill / randomcatill;
        alice.bank.account -= alice.cat.vetclinic;
    }
    switch (month) {
    case 1: alice.cat.ill += alice.cat.ill * alice.economic.inflation / 100; break;
    }
}

void amortization(const int month) {
    if (month == 1) {
        if (alice.car.age <= 3) {
            alice.car.value = alice.car.value / 1.20;
        }
        if (alice.car.age > 3 && alice.car.age <= 6) {
            alice.car.value = alice.car.value / 1.10;
        }
        if (alice.car.age > 6 && alice.car.age <= 10) {
            alice.car.value = alice.car.value / 1.07;
        }
        if (alice.car.age > 10) {
            alice.car.value = alice.car.value / 1.05;
        }
    }
}

float tbank_percent(short period) {
    short r = 1 + rand() % 2;
    short random_spread = 1 + rand() % 15;

    if (!alice.bank.indefinite_depozit && !alice.bank.has_depozit) {
        if (alice.bank.period <= 3) {
            alice.bank.has_depozit = true;
            return random_depozit_procent(alice.economic.inflation, r, random_spread, 15) * 1.15;
        }
        if (alice.bank.period <= 12 && alice.bank.period > 3) {
            alice.bank.has_depozit = true;
            return random_depozit_procent(alice.economic.inflation, r, random_spread, 15) * 1.10;
        }
        if (alice.bank.period <= 24 && alice.bank.period > 12) {
            alice.bank.has_depozit = true;
            return random_depozit_procent(alice.economic.inflation, r, random_spread, 15) * 1.05;
        }
    }
    if (alice.bank.period == 25 && alice.bank.percent > 12 && !alice.bank.indefinite_depozit && !alice.bank.has_depozit) {
        alice.bank.indefinite_depozit = true;
    }
    return alice.bank.percent;
}

void alice_tbank_interest() {
    float pp;
    pp = tbank_percent(alice.bank.period);

    if (alice.bank.has_depozit && alice.bank.period != 0) {
        alice.bank.depozit += alice.bank.depozit * (pp / 12.0 / 100.0);
    }
    if (alice.bank.indefinite_depozit) {
        alice.bank.depozit += alice.bank.depozit * (pp / 12.0 / 100.0);
    }
}

void alice_depozit() {
    double money_under_the_pillow = 0;

    if (!alice.bank.has_depozit) {
        money_under_the_pillow = alice.bank.account;
    }

    if (!alice.bank.has_depozit && money_under_the_pillow >= 100000) {
        money_under_the_pillow = 0;

        short random_period = 1 + rand() % 25;
        alice.bank.period = random_period;

        if (alice.bank.indefinite_depozit) {
            alice.bank.period = -1;
        }

        if (alice.bank.period == 0) {
            alice.bank.has_depozit = false;
            alice.bank.account += alice.bank.depozit;
            alice.bank.depozit = 0;
        }
    }

    alice_tbank_interest();
}

void alice_salary(const int year, const int month) {
    int random = 1 + rand() % 10;
    RUB gross = alice.money.salary;
    if (random == 5) {
        alice.money.highprice = alice.money.salary * 0.2;
        gross += alice.money.highprice;
    }

    if (month == 12) {
        alice.money.salary += alice.money.salary * alice.economic.indexation / 100;
    }
    if (month == 3 && year == 2026) {
        alice.money.salary *= 1.2;
    }

    alice.tax.salaryyear += gross;
    float tt = tax_rate(alice.tax.salaryyear);
    RUB tax = gross * tt / 100;
    alice.tax.sum += tax;
    RUB net = gross - tax;
    alice.bank.account += net;

    if (month == 1) alice.tax.salaryyear = 0;
}

void alice_food(int month, bool winter_trip_food, bool summer_trip_food) {
    RUB sum_food = 0;
    RUB alice_fridge[11] = { alice.food.bread, alice.food.meat, alice.food.milk, alice.food.eggs, alice.food.greenery,
        alice.food.porridge, alice.food.vegetablse, alice.food.cereal, alice.food.coffee, alice.food.tea, alice.food.fruits };

    winter_food(month);
    summer_food(month);

    if (winter_trip_food == true) {
        alice.bank.account -= sum_food / 2;
        winter_trip_food = false;
    }

    if (summer_trip_food == true) {
        alice.bank.account -= sum_food / 2;
        summer_trip_food = false;
    }

    short r = 1 + rand() % 2;
    short random;

    for (int i = 0; i < 11; i++) {
        random = 1 + rand() % 15;
        random_value_a_procent(alice_fridge[i], r, random, 15);
        sum_food += alice_fridge[i];
    }
    alice.bank.account -= sum_food;

    apply_inflation_to_food(month);
}

void print_results() {
    printf("\n==================== ФИНАНСОВЫЙ ОТЧЕТ АЛИСЫ ====================\n");
    printf("Возраст: %d лет\n", alice.age);
    printf("\n--- КАПИТАЛ И АКТИВЫ ---\n");
    printf("Общий капитал: %lld руб.\n", alice.capital);
    printf("Наличные (счет): %lld руб.\n", alice.bank.account);
    printf("Депозит в банке: %lld руб.\n", alice.bank.depozit);
    printf("Стоимость квартиры: %lld руб.\n", alice.apartment.value);
    printf("Стоимость автомобиля: %lld руб.\n", alice.car.value);
    printf("Стоимость кота (покупка): %lld руб.\n", alice.cat.value);

    printf("\n--- ДОХОДЫ ---\n");
    printf("Месячная зарплата (gross): %lld руб.\n", alice.money.salary);
    printf("Годовой доход до налога: %lld руб.\n", alice.tax.salaryyear);
    printf("Суммарный уплаченный налог за год: %lld руб.\n", alice.tax.sum);
    printf("Эффективная ставка налога: %.2f%%\n", (alice.tax.sum * 100.0 / alice.tax.salaryyear));

    printf("\n--- ЭКОНОМИЧЕСКИЕ ПОКАЗАТЕЛИ ---\n");
    printf("Инфляция (текущая): %.2f%%\n", alice.economic.inflation);
    printf("Индексация зарплаты: %.2f%%\n", alice.economic.indexation);

    printf("\n--- РАСХОДЫ НА ЖИЛЬЕ ---\n");
    printf("Коммунальные платежи (в месяц): %lld руб.\n", alice.apartment.communal);
    printf("Годовые расходы на коммуналку (приблизительно): %lld руб.\n", alice.apartment.communal * 12);

    printf("\n--- РАСХОДЫ НА АВТОМОБИЛЬ ---\n");
    printf("Бензин (месяц): %lld руб.\n", alice.car.gas);
    printf("Техобслуживание: %lld руб.\n", alice.car.maintenance);
    printf("Зимняя резина (разово): %lld руб.\n", alice.car.wintertires);
    printf("Моторное масло: %lld руб.\n", alice.car.engine_oil);
    printf("Наличие КАСКО: %s\n", alice.car.KASKO ? "да" : "нет");
    printf("Наличие ОСАГО: %s\n", alice.car.OSAGO ? "да" : "нет");
    printf("Ущерб от ДТП (последний): %lld руб.\n", alice.car.traffic_accident_value);

    printf("\n--- КОТ ---\n");
    printf("Еда для кота в месяц: %lld руб.\n", alice.cat.food);
    printf("Расходы на ветклинику (последние): %lld руб.\n", alice.cat.vetclinic);
    printf("Стоимость лечения кота при болезни: %lld руб.\n", alice.cat.ill);

    printf("\n--- ЗДОРОВЬЕ ---\n");
    printf("Типичные расходы на лечение Алисы: %lld руб.\n", alice.ill);

    printf("\n--- ОДЕЖДА (текущие цены) ---\n");
    printf("Обувь: %lld, Носки: %lld, Штаны: %lld, Кроссовки: %lld\n",
        alice.clothes.shoes, alice.clothes.socks, alice.clothes.pants, alice.clothes.sneakers);
    printf("Джинсы: %lld, Брюки: %lld, Футболка: %lld, Платье: %lld\n",
        alice.clothes.jeans, alice.clothes.trousers, alice.clothes.tshirt, alice.clothes.dress);
    printf("Бюстгальтер: %lld, Шапка: %lld, Купальник: %lld, Куртка: %lld\n",
        alice.clothes.brassiere, alice.clothes.hat, alice.clothes.swimsuit, alice.clothes.jacket);
    printf("Пальто: %lld, Сумка: %lld\n", alice.clothes.coat, alice.clothes.bag);

    printf("\n--- ЕДА (месячный набор, цены) ---\n");
    printf("Мясо: %lld, Яйца: %lld, Зелень: %lld, Молоко: %lld, Хлеб: %lld\n",
        alice.food.meat, alice.food.eggs, alice.food.greenery, alice.food.milk, alice.food.bread);
    printf("Овощи: %lld, Крупы: %lld, Чай: %lld, Кофе: %lld, Фрукты: %lld, Каша: %lld\n",
        alice.food.vegetablse, alice.food.cereal, alice.food.tea, alice.food.coffee,
        alice.food.fruits, alice.food.porridge);

    printf("\n--- ПУТЕШЕСТВИЯ (текущие цены) ---\n");
    printf("Авиабилет: %lld, Отель (база): %lld, Сувениры: %lld, Экскурсии: %lld\n",
        alice.trip.airplane_ticket, alice.trip.hotel, alice.trip.souvenirs, alice.trip.excursions);
    printf("Ж/д билет: %lld, Прокат лыж: %lld, Аквапарк: %lld, Парк аттракционов: %lld\n",
        alice.trip.train_tickets, alice.trip.ski_rental, alice.trip.aquapark, alice.trip.amusementpark);
    printf("Пещера: %lld, Рыбалка: %lld, Горный вел: %lld, Дайвинг: %lld, Сёрфинг: %lld, Байдарка: %lld\n",
        alice.trip.cave, alice.trip.fishing, alice.trip.guadbike, alice.trip.diving, alice.trip.surfing, alice.trip.kayak);

    printf("\n==================== КОНЕЦ ОТЧЕТА ====================\n");
}

float reliability_ratio() {
    if (alice.age <= 21) {
        switch (alice.car.driving_experience) {
        case 0: return 2.27;
        case 1: return 1.92;
        case 2: return 1.84;
        case 3:
        case 4: return 1.65;
        case 5:
        case 6: return 1.62;
        }
    }

    if (alice.age > 21 && alice.age <= 24) {
        switch (alice.car.driving_experience) {
        case 0: return 1.88;
        case 1: return 1.72;
        case 2: return 1.71;
        case 3:
        case 4: return 1.13;
        case 5:
        case 6: return 1.10;
        case 7:
        case 8:
        case 9: return 1.09;
        }
    }

    if (alice.age > 24 && alice.age <= 29) {
        switch (alice.car.driving_experience) {
        case 0: return 1.72;
        case 1: return 1.60;
        case 2: return 1.54;
        case 3:
        case 4: return 1.09;
        case 5:
        case 6: return 1.08;
        case 7:
        case 8:
        case 9: return 1.07;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:return 1.02;
        }
    }

    if (alice.age > 29 && alice.age <= 34) {
        switch (alice.car.driving_experience) {
        case 0: return 1.56;
        case 1: return 1.50;
        case 2: return 1.48;
        case 3:
        case 4: return 1.05;
        case 5:
        case 6: return 1.04;
        case 7:
        case 8:
        case 9: return 1.01;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:return 0.97;
        default: return 0.95;
        }
    }

    if (alice.age > 34 && alice.age <= 39) {
        switch (alice.car.driving_experience) {
        case 0: return 1.54;
        case 1: return 1.47;
        case 2: return 1.46;
        case 3:
        case 4: return 1.00;
        case 5:
        case 6: return 0.97;
        case 7:
        case 8:
        case 9: return 0.95;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:return 0.94;
        default: return 0.93;
        }
    }

    if (alice.age > 39 && alice.age <= 49) {
        switch (alice.car.driving_experience) {
        case 0: return 1.50;
        case 1: return 1.44;
        case 2: return 1.43;
        case 3:
        case 4: return 0.96;
        case 5:
        case 6: return 0.95;
        case 7:
        case 8:
        case 9: return 0.94;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:return 0.93;
        default: return 0.91;
        }
    }

    if (alice.age > 49 && alice.age <= 59) {
        switch (alice.car.driving_experience) {
        case 0: return 1.46;
        case 1: return 1.40;
        case 2: return 1.39;
        case 3:
        case 4: return 0.93;
        case 5:
        case 6: return 0.92;
        case 7:
        case 8:
        case 9: return 0.91;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:return 0.90;
        default: return 0.86;
        }
    }

    if (alice.age > 59) {
        switch (alice.car.driving_experience) {
        case 0: return 1.43;
        case 1: return 1.36;
        case 2: return 1.35;
        case 3:
        case 4: return 0.91;
        case 5:
        case 6: return 0.90;
        case 7:
        case 8:
        case 9: return 0.89;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:return 0.88;
        default: return 0.83;
        }
    }
    return 1.0;
}

int range_traffic_accident_random(const int month) {
    if (!(month == 1 || month == 12 || month == 2)) {
        return reliability_ratio() * 100;
    }
    return reliability_ratio() * 100 * 1.5;
}

void traffic_accident_probability(const int month) {
    double range_double = range_traffic_accident_random(month);
    if (range_double <= 0.0) range_double = 0.001;
    int range = static_cast<int>(100.0 / range_double);
    if (range < 1) range = 1;

    if (rand() % range == 0) {
        alice.car.traffic_accident = true;
    }
    if (rand() % 4 == 0) {
        alice.car.traffic_accident_quilty = true;
    }
}

void traffic_accident_value() {
    if (alice.car.traffic_accident) {
        RUB damage = alice.car.calculation + (rand() % (alice.car.calculation * 50));
        alice.car.traffic_accident_value = damage;

        if (alice.car.traffic_accident_quilty && alice.car.KASKO) {
            alice.car.insurance_KASKO = damage;
            RUB franchise = damage * 10 / 100;
            alice.bank.account -= franchise;
        }
        else if (alice.car.traffic_accident_quilty && !alice.car.KASKO) {
            alice.bank.account -= damage;
            alice.car.insuranse_OSAGO = damage;
            if (alice.car.insuranse_OSAGO > alice.car.calculation * 40) {
                alice.car.insuranse_OSAGO = alice.car.calculation * 40;
            }
        }
        else if (!alice.car.traffic_accident_quilty) {
            alice.car.insuranse_OSAGO = damage;
            alice.bank.account += alice.car.insuranse_OSAGO;
        }

        alice.car.traffic_accident = false;
        alice.car.traffic_accident_quilty = false;
    }
}

int random_range_KASKO_permille() {
    int base = 50;
    if (alice.car.traffic_accident) {
        base += 30;
    }
    double ratio = reliability_ratio();
    if (ratio > 1.5) base += 20;
    else if (ratio > 1.2) base += 10;
    else if (ratio < 0.9) base -= 15;
    if (base < 0) base = 0;
    if (base > 1000) base = 1000;
    return base;
}

void kasko(const int month) {
    static bool already_bought_this_year = false;
    if (month == 1) {
        already_bought_this_year = false;
    }
    if (month == 1 && !already_bought_this_year) {
        int r = rand() % 1000;
        int permille = random_range_KASKO_permille();
        if (r < permille) {
            alice.car.KASKO = true;
            already_bought_this_year = true;
            RUB cost = alice.car.value * 5 / 100;
            alice.bank.account -= cost;
        }
        else {
            alice.car.KASKO = false;
        }
    }
    if (month == 12) {
        already_bought_this_year = false;
    }
}

void alice_winter_car(const int month) {
    if (month < 3 || month == 12) {
        alice.car.gas *= 1.5;
        alice.car.maintenance += alice.car.wintertires;
    }
}

void alice_car(const int month) {
    short r = 1 + rand() % 2;
    short random = 1 + rand() % 15;

    random_value_a_procent(alice.car.gas, r, random, 15);
    random_value_a_procent(alice.car.maintenance, r, random, 15);

    alice_winter_car(month);

    alice.bank.account -= alice.car.gas;
    alice.bank.account -= alice.car.maintenance;

    static bool winter_mode = false;
    if ((month == 12 || month == 1 || month == 2) && !winter_mode) {
        winter_mode = true;
    }
    if (month == 3 && winter_mode) {
        alice.car.gas /= 1.5;
        alice.car.maintenance -= alice.car.wintertires;
        winter_mode = false;
    }

    amortization(month);

    traffic_accident_probability(month);
    traffic_accident_value();

    kasko(month);
}

void alice_simulation(bool winter_trip_food, bool summer_trip_food) {
    int year = 2026;
    int month = 2;

    while (!(year == 2031 && month == 2)) {
        tax_rate(alice.tax.salaryyear);
        alice_salary(year, month);
        travel(month);
        alice_food(month, winter_trip_food, summer_trip_food);
        alice_clothes(month);
        alice_ill(month);
        alice_car(month);
        alice_apartment(month);
        alice_cat(month);
        alice_depozit();
        alice_capital();
        infation_indexation_index(month);

        ++month;

        if (alice.bank.period > 0) {
            --alice.bank.period;
        }

        if (month == 13) {
            ++year;
            month = 1;
        }

        if (month == 7) {
            ++alice.age;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    alice_init();
    alice_simulation(alice.trip.winter_trip_food, alice.trip.summer_trip_food);
    print_results();
    plot_inflation();
    return 0;
}