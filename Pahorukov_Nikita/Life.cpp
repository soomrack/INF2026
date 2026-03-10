#include <iostream>
#include <string>
#include <random>

using KOP = int;

int random_year(int min, int max) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

struct Ivan {
    std::string name;
    double age;
    int birth_year;
    KOP money;
};

struct Barin {
    double percent_obrok;
    int forced_crop;
    int how_many_years;
};

struct Grain {
    std::string name;
    double price_per_kg;
    int kg_for_desyatina;
    int storage_kg;  // сколько есть в амбаре
};

struct Field {
    int crop_index; // индекс культуры, которая будет посеяна
    double area;    // площадь в десятинах
};

enum Season { Spring, Summer, Autumn, Winter };

Ivan ivan;
std::array<Grain, 4> grains;
Field field;
Barin barin;

void ivan_init() {
    ivan.name = "Ivan";
    ivan.age = 18.0;
    ivan.money = 500;
}

void randomBarinOrder() {
    static std::mt19937 gen(std::random_device{}());

    std::uniform_int_distribution<> crop_dist(0, 3);
    std::uniform_int_distribution<> years_dist(1, 5);

    barin.forced_crop = crop_dist(gen);
    barin.how_many_years = years_dist(gen);

    std::cout << "Barin ordered to plant "
        << grains[barin.forced_crop].name
        << " for " << barin.how_many_years
        << " years\n";
}

void barin_init() {
    barin.percent_obrok = 0.3;
    randomBarinOrder();
}

void grains_init() {
    grains[0] = {"Oats", 0.8, 190, 190};
    grains[1] = { "Barley", 0.9, 150, 150 }; // ячмень
    grains[2] = { "Rye", 1.2, 140, 140 };
    grains[3] = {"Wheat", 1.4, 160, 160};
}

void field_init() {
    field.area = 20.0; // площадь поля
    field.crop_index = -1; // пока ничего не посеяно
}

// Весна: посадка культуры
void plant_сrop(Season season) {
    if (season != Spring) return;
    if (barin.how_many_years > 0) {
        field.crop_index = barin.forced_crop; // Иван сеет то, что приказал барин
        std::cout << "Spring: " << grains[field.crop_index].name << " is planted\n";
        barin.how_many_years--;
    }

    else {
        // Барин берет новый приказ из массива приказов.
        //std::cout << "Spring: Barin didn't order anything. " << grains[3].name << " is planted\n"; // пока сажает пшено
    }
}

// Лето: сбор урожая
void harvest_сrop(Season season) {
    if (season != Summer) return;

    int grown_harvest = field.area * grains[field.crop_index].kg_for_desyatina; 

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

    for (auto& grain : grains) {
        if (grain.storage_kg == 0) continue;     // если текущий сейчас grain.storage_kg пустой или равен посадке то
        if (grain.storage_kg == grain.kg_for_desyatina) continue;  // переходим к следующему grain в массиве

        ivan.money += (grain.storage_kg - grain.kg_for_desyatina) * grain.price_per_kg;
        grain.storage_kg = grain.kg_for_desyatina; // продано

        std::cout << (grain.storage_kg - grain.kg_for_desyatina) << " kg of "
            << grain.name << " sold for "
            << (grain.storage_kg - grain.kg_for_desyatina) * grain.price_per_kg << " KOP\n";

    }
}

// Основная функция обработки сезона
void process_cropping(Season season) {
    switch (season) {
    case Spring: plant_сrop(season); break;
    case Summer: harvest_сrop(season); break;
    case Autumn:
    case Winter: sell_crop(season); break;
    }
}



int main() {
    ivan_init();
    barin_init();
    grains_init();
    field_init();

    int year = random_year(1820, 1856);
    int start_year = year;
    Season currentSeason = Spring;
    std::cout << "Start year: " << year << "\n";
    while (year < 1861) {
        std::cout << ivan.money << "KOP \n";
        process_cropping(currentSeason);

        currentSeason = static_cast<Season>((currentSeason + 1) % 4);

        // ivan.money -= 500; // расходы на еду, условно

        //std::cout << currentSeason + 1 << " season: Ivan spent 500 COP on food\n";

        if (currentSeason == Spring) {
            year++;
        }
    }

    std::cout << "After " << year - start_year << " years, Ivan has " << ivan.money/100 << " RUB and "
        << ivan.money%100  << " KOP \n";
}
