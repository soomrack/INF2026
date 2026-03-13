#include <iostream>
#include <string>
#include <random>
#include <array>

using DAR = int;
                                /* =======================
                                   ВСПОМОГАТЕЛЬНЫЕ КОМАНДЫ
                                   ======================= */
int random_year(const int min, const int max) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen); 
}

                                /* =======================
                                            ЗЕРНО 
                                   ======================= */

class Grain {
public:
    std::string name;
    double price_per_kg;
    int kg_for_desyatina;
    int storage_kg;

};

std::array<Grain, 4> grains;

void grains_init() {
    grains[0] = { "Oats", 8, 190, 190 };
    grains[1] = { "Barley", 9, 150, 150 }; // ячмень
    grains[2] = { "Rye", 12, 140, 140 };
    grains[3] = { "Wheat", 14, 160, 160 };
}


                                /* =======================
                                            БАРИН 
                                   ======================= */
class Barin {
public:
    double percent_obrok = 0.3;
    int forced_crop;
    int how_many_years;

    void random_barin_order();
    void barin_init();
};
Barin barin;

void Barin::random_barin_order() {
    static std::mt19937 gen(std::random_device{}());

    std::uniform_int_distribution<> crop_dist(0, 3);
    std::uniform_int_distribution<> years_dist(1, 5);

    forced_crop = crop_dist(gen);
    how_many_years = years_dist(gen);

    std::cout << "Barin ordered to plant "
        << grains[forced_crop].name
        << " for " << how_many_years
        << " years\n";
}
                                /* =======================
                                            ИВАН 
                                   ======================= */

class Ivan {
public:
    double age = 18.0;
    int birth_year;
    DAR money = 10000;

    void expenses() {
        money -= 2000;
        std::cout << "Ivan spend 2000 DAR for food \n";
        // траты зерна на еду
    }
};

Ivan ivan;

class Depended_Ivan:Ivan {

};






struct Field {
    int crop_index; // индекс культуры, которая будет посеяна
    double area;    // площадь в десятинах
};

enum Season { Spring, Summer, Autumn, Winter };



Field field;

std::array <double, 16> harvest_coeff = {
    0.1,
    0.3,
    0.5, 0.5,
    0.7, 0.7,
    0.9, 0.9, 0.9,
    1.1, 1.1, 1.1,
    1.3, 1.3,
    1.6,
    2.0
};

double random_harvest_coeff_init() {

    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> coeff(0, 15);
    return harvest_coeff[coeff(gen)];
}



void field_init() {
    field.area = 20.0; // площадь поля
    field.crop_index = -1; // пока ничего не посеяно
}

// Весна: посадка культуры
void plant_crop(Season season) {
    if (season != Spring) return;

    if (barin.how_many_years == 0) {
        barin.random_barin_order();
    }

    field.crop_index = barin.forced_crop;
    std::cout << "Spring: " << grains[field.crop_index].name << " is planted\n";

    barin.how_many_years--;
}

// Лето: сбор урожая
void harvest_crop(Season season) {
    if (season != Summer) return;
    if (field.crop_index < 0) return;

    double random_harvest_coeff = random_harvest_coeff_init();
    std::cout << "Harvest coefficient: " << random_harvest_coeff << "\n";

    int grown_harvest = field.area * grains[field.crop_index].kg_for_desyatina * random_harvest_coeff;

    int obrok = grown_harvest * barin.percent_obrok;
    int ivan_part = grown_harvest - obrok;

    grains[field.crop_index].storage_kg += ivan_part;

    std::cout << "Summer: Harvested " << grown_harvest << " kg of "
        << grains[field.crop_index].name << "\n";
    std::cout << "Barin take obrok " << obrok << " kg of "
        << grains[field.crop_index].name << "\n";
    std::cout << "Ivan take his part " << ivan_part << " kg of "
        << grains[field.crop_index].name << "\n";

}

// Осень и зима: продажа и еда
void sell_crop(Season season) {
    if (season == Spring) return;
    if (season == Summer) return;

    for (auto& grain : grains) { // & нужно чтобы у меня обновлялось storage_kg
		int seed_needed = field.area * grain.kg_for_desyatina; // сколько нужно для посадки

        if (grain.storage_kg <= seed_needed) continue;  // переходим к следующему grain в массиве


        int sold = grain.storage_kg - seed_needed;

        ivan.money += sold * grain.price_per_kg;

        std::cout << sold << " kg of "
            << grain.name << " sold for "
            << sold * grain.price_per_kg << " DAR\n";

        grain.storage_kg = grain.kg_for_desyatina;
    }
}

// Основная функция обработки сезона
void process_cropping(Season season) {
    switch (season) {
    case Spring: plant_crop(season); break;
    case Summer: harvest_crop(season); break;
    case Autumn: break;
    case Winter: sell_crop(season); break;
    }
}



int main() {

    int year = random_year(1820, 1856);

    int start_year = year;
    Season current_season = Spring;
    std::cout << "Start year: " << year << "\n";
   
    grains_init();
    field_init();

	//family_init(); // если нужно, можно добавить семью и расходы на нее
	//pets_init(); // если нужно, можно добавить животных и расходы на них,


    while (year < 1861) {
        std::cout << ivan.money << " DAR \n";
        process_cropping(current_season);
        ivan.expenses();

        current_season = static_cast<Season>((current_season + 1) % 4);
        if (current_season == Spring) {
            year++;
        }
    }
    // after 1861 будет совсем другая история, которую мы обязательно продолжим
    std::cout << "After " << year - start_year << " years, Ivan has " << ivan.money/1000 << " RUB and "
        << ivan.money%1000  << " DAR \n";
}
