#include <iostream>
#include <string>
#include <random>
#include <array>
#include <vector>

using DAR = int;

class Grain;
class Barin;
class Ivan;
class Field;
class Storage;
class Random;

/*====================================CЛУЧАЙНОСТИ НЕ СЛУЧАЙНЫ======================*/

class Random {
private:
    static std::mt19937 gen;

public:
    static void init() {
        gen.seed(std::random_device{}());
    }
    static int random_int(int min, int max);
    static bool chance(double p);


    static double weighted(const std::vector<std::pair<double, int>>& data);
};

std::mt19937 Random::gen;

//случайное целое число из диапазона
int Random::random_int(int min, int max) {
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

//случайное число по Бернулли (число р = вероятность выполнения)
bool Random::chance(double p) {
    std::bernoulli_distribution dist(p);
    return dist(gen);
}

// принцип весов (для работы добавить вектор с шансами)

double Random::weighted(const std::vector<std::pair<double, int>>& data) {

    std::vector<int> weights;

    for (const auto& e : data)
        weights.push_back(e.second);

    std::discrete_distribution<> dist(weights.begin(), weights.end());

    return data[dist(gen)].first;
}


/*================================СПИСОК_РЕСУРСОВ========================*/

enum  ResourceID {
    Oats, Barley, Rye, Wheat, Cow_milk, Goat_milk, Sheep_wool, Chicken_eggs,
    Cow_meat, Sheep_meat, Goat_meat, Chicken_meat, Pig_meat,
};

const int NO_RESOURCE = -1;

struct Resource {
    std::string name;
	int price_for_unit; // для твердого - кг, для жидкого - литр, для яйца - штука
    int grain_data_id; // будет -1, если не зерно

    int resource_id;
};

std::vector<Resource> resources{
    {"Oats", 8, 0, 0},
    { "Barley", 9, 1, 1 },
    { "Rye", 12, 2, 2 },
    { "Wheat", 14, 3, 3 },

    { "Cow_milk", 30, -1, 4 },
    { "Goat_milk", 6, -1, 5  },

    { "Sheep_wool", 150, -1, 6 },
	{ "Chicken_eggs", 7, -1, 7 },

    { "Cow_meat", 140, -1, 8 },
    { "Sheep_meat", 100, -1, 9 },
	{ "Goat_meat", 18, -1, 10 },
	{ "Chicken_meat", 10, -1, 11 },
	{ "Pig_meat", 100, -1, 12 },
};
/*=====================================СКЛАД======================================*/

struct Storage_Stack {
    int resource_id;
    int amount;
};

class Storage {
public:
    std::vector<Storage_Stack> items;

    void add(int resource_id, int amount);
    bool remove(int resource_id, int amount);
    int get_amount(int resource_id);
};

Storage storage = {
    {
        {0, 1900}, // овес
        {1, 1500}, // ячмень
        {2, 1400},  // рожь
        {3, 1600}  // пшеница
        // {"milk", 100}
        // в будущем добавить сюда молоко, мясо и т.д. для животных
    }
};


void Storage::add(int resource_id, int amount) {
    for (auto& item : items) {
        if (item.resource_id == resource_id) {
            item.amount += amount;
            return;
        }
    }
    items.push_back({ resource_id, amount });
}

bool Storage::remove(int resource_id, int amount) {
    for (auto& item : items) {
        if (item.resource_id == resource_id) {
            if (item.amount < amount) return false; // недостаточно ресурса для удаления

            item.amount -= amount;
            return true;


        }
    }
    return false;
}

int Storage::get_amount(int resource_id) {
    for (auto& item : items) {
        if (item.resource_id == resource_id) {
            return item.amount;
        }
    }
    return 0;
}

/* =============================ЗЕРНО И ПОЛЕ============================ */

struct Grain {

    int kg_for_desyatina;
};

std::array<Grain, 4> grains;

void grains_init() {
    grains[0] = { 95 };
    grains[1] = { 75 }; // ячмень
    grains[2] = { 70 };
    grains[3] = { 80 };
}

struct Field {
    int crop_index; // индекс культуры, которая будет посеяна
    double area;    // площадь в десятинах
    int planted_kg;
};

enum Season { Spring, Summer, Autumn, Winter };

Field field;

std::vector< std::pair<double, int>> harvest_chance{
  {0.1, 1},
  {0.7, 2},
  {0.9, 5},
  {1.0, 20},
  {1.1, 25},
  {1.3, 23},
  {1.5, 13},
  {2.0, 20},
  {5.0, 1}
};

void field_init() {
    field.area = 20.0; // площадь поля
    field.crop_index = -1; // пока ничего не посеяно
}


/* =============================БАРИН============================ */
class Barin {
public:
    double percent_obrok = 0.3;
    int forced_crop;
    int how_many_years;

    void random_barin_order();
};

Barin barin;

void Barin::random_barin_order() {
    static std::mt19937 gen(std::random_device{}());

    std::uniform_int_distribution<> crop_dist(0, 3);
    std::uniform_int_distribution<> years_dist(1, 5);

    forced_crop = crop_dist(gen);
    how_many_years = years_dist(gen);

    std::cout << "Barin ordered to plant "
        << resources[forced_crop].name
        << " for " << how_many_years
        << " years\n";
}

/* ==================================ИВАН=============================== */

class Ivan {
public:
    double age = 18.0;
    int birth_year;
    DAR money = 10000;


    void expenses();
};
Ivan ivan;

void Ivan::expenses() {
    money -= 2000;
    std::cout << "Ivan spend 2000 DAR for food \n";
    // траты зерна на еду
}


/*============================УРОЖАЙ=========================*/

// Весна: посадка культуры
void plant_crop(Season season) {
    if (season != Spring) return;

    if (barin.how_many_years == 0) {
        barin.random_barin_order();
    }

    field.crop_index = barin.forced_crop;
    barin.how_many_years--;


    int max_needed = field.area * grains[field.crop_index].kg_for_desyatina;

    int available = storage.get_amount(field.crop_index);
    
    int planted = std::min(max_needed, available);

    if (planted == 0) {
        std::cout << "Not enough " << resources[field.crop_index].name 
                  << " to plant. Needed: " << max_needed 
                  << " kg, available: " << available << " kg\n";
        field.crop_index = -1; // не сажаем ничего
        return;
    }

    storage.remove(field.crop_index, planted);

    std::cout << "Spring: Planted " << planted << " kg of "
        << resources[field.crop_index].name << "\n";
    field.planted_kg = planted;
}

// Лето: сбор урожая
void harvest_crop(Season season) {
    if (season != Summer) return;
    if (field.crop_index < 0) return;

    double random_harvest_coeff = Random::weighted(harvest_chance);
    std::cout << "Harvest coefficient: " << random_harvest_coeff << "\n";

    int grown_harvest = field.planted_kg * random_harvest_coeff;

    int obrok = grown_harvest * barin.percent_obrok;
    int ivan_part = grown_harvest - obrok;

    storage.add(field.crop_index, ivan_part);

    std::cout << "Summer: Harvested " << grown_harvest << " kg of "
        << resources[field.crop_index].name << "\n";
    std::cout << "Barin take obrok " << obrok << " kg of "
        << resources[field.crop_index].name << "\n";
    std::cout << "Ivan take his part " << ivan_part << " kg of "
        << resources[field.crop_index].name << "\n";

    field.crop_index = -1;
    field.planted_kg = 0;
}

// Осень и зима: продажа УРОЖАЯ
void sell_crop(Season season)
{
    if (season != Winter) return;

    for (auto& stack : storage.items)
    {
		int resource_id = stack.resource_id;

        int grain_id = resources[stack.resource_id].grain_data_id;

        if (grain_id == -1) continue; // не зерно, не продаем
	
        int seed_needed = field.area * grains[grain_id].kg_for_desyatina;

        if (stack.amount <= seed_needed)
            continue;

        int sold = stack.amount - seed_needed;

        ivan.money += sold * resources[stack.resource_id].price_for_unit;

        stack.amount = seed_needed;

        std::cout << sold << " kg of " << resources[stack.resource_id].name 
                          << " sold for " << sold * resources[stack.resource_id].price_for_unit
                          << " DARфффффффффффффффффффффффффффффффф\n";
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


/*==============================ЖИВОТНЫЕ===========================*/

struct Production {

    int product_resource_id;
    int amount_of_product;
    int production_interval;
};

struct Meat {

    int meat_resource_id;
    int amount_of_meat;
};

struct Animal {

	std::string name;
    int count;
    
    int current_age;
    int max_age;
    
    Production production;
    Meat meat;
};


std::vector<Animal> animals {

    {
    "Cow", 2,
    0, 10,
    { Cow_milk, 12, 1 },
    { Cow_meat, 180 }
},

{
    "Goat", 3,
    0, 8,
    { Goat_milk, 6, 1 },
    { Goat_meat, 18 }
},

{
    "Sheep", 5,
    0, 10,
    { Sheep_wool, 2, 52 },
    { Sheep_meat, 20 }
},

{
    "Chicken", 10,
    0, 3,
    { Chicken_eggs, 5, 1 },
    { Chicken_meat, 1 }
},

{
    "Pig", 2,
    0, 2,
    { NO_RESOURCE, 0, 0 },
    { Pig_meat, 85 }
},

{
    "Bull", 1,
    0, 12,
    { NO_RESOURCE, 0, 0 },
    { Cow_meat, 300 }
}

};

void product_add(int week) {
    for (auto& animal : animals) {
        if (animal.production.product_resource_id == NO_RESOURCE) continue;
        if (week % animal.production.production_interval != 0) continue;

        storage.add(animal.production.product_resource_id, 
            animal.production.amount_of_product * animal.count);
    }
}

void slaughter() {
    for (auto& animal : animals) {
        if (animal.count > 0 and animal.current_age >= animal.max_age) {

            storage.add(animal.meat.meat_resource_id,
                animal.meat.amount_of_meat * animal.count); // исправить после добавления разного возраста животных

            animal.count = 0;
        }
    }
}

void sell_resources() {
    
    for (auto& item : storage.items) {

        if (resources[item.resource_id].grain_data_id != -1) continue;

        ivan.money += resources[item.resource_id].price_for_unit * item.amount;

        std::cout << "Sold " << item.amount << " of "
            << resources[item.resource_id].name << "\n";
        item.amount = 0;
    }
}

/* ======================ВСПОМОГАТЕЛЬНЫЕ КОМАНДЫ======================= */

void process_week(Season season) {
    for (int week = 1; week <= 12; week++) {

        product_add(week);


    }
}

void oldering(int year) {
    
    ivan.age++;

    for (auto& animal : animals) {
        animal.current_age++;
    }
}

void years_simulation() {

    int year = Random::random_int(1820, 1856);


    int start_year = year;
    Season current_season = Spring;
    std::cout << "Start year: " << year << "\n";

    while (year < 1861) {
        std::cout << ivan.money << " DAR \n";

        process_week(current_season);
        process_cropping(current_season);

        ivan.expenses();

        slaughter();
        sell_resources();

        std::cout << storage.get_amount(0) << " " << storage.get_amount(1) 
            << " " << storage.get_amount(2) << " " << storage.get_amount(3) << "\n";

        current_season = static_cast<Season>((current_season + 1) % 4);
        if (current_season == Spring) {
            year++;
            oldering(year);
        }
    }

    std::cout << "After " << year - start_year << " years, Ivan has " << ivan.money / 1000 << " RUB and "
        << ivan.money % 1000 << " DAR \n";
    std::cout << "Ivan's age = " << ivan.age;
}

void initialization() {

    Random::init();
    grains_init();
    field_init();
    
}

/*=================================ГЛАВНАЯ ЧАСТЬ==============================*/

int main() {
    //family_init(); // если нужно, можно добавить семью и расходы на нее
    //pets_init(); // если нужно, можно добавить животных и расходы на них,

    initialization();

    years_simulation();

    // after 1861 будет совсем другая история, которую мы обязательно продолжим

}
