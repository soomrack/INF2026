#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>



using RUB = long long;



struct Pet {

    std::string type = "Cat";
    std::string name = "Sonya";
    RUB food_per_month = 3000;
    RUB toys_per_month = 500;
    RUB sterilization_cost = 5000;
    RUB vaccines_annual = 2000;
    bool is_sterilized = false;
};



struct Ingredient {

    std::string name;
    RUB price;
};



struct Dish {

    std::string name;
    std::vector<std::string> ingredients_needed;
};



struct Alice {

    RUB cash = 100000;
    RUB salary = 150000;
    RUB beauty = 7000;
    RUB pets_expenses = 0;
    RUB food_expenses = 0;


    struct Car {

        RUB value = 2000000;
        RUB gas = 8000;
        RUB service = 3000;
    } car;


    struct House {

        RUB value = 10000000;
    } house;

    Pet my_pet;
};



Alice alice;
double inflation_rate = 0.007; // 0.7% в месяц
std::map<std::string, RUB> market_prices;
std::vector<Dish> cookbook;



void init_market() {

    market_prices["Chicken"] = 400;
    market_prices["Pasta"] = 100;
    market_prices["Cheese"] = 200;
    market_prices["Vegetables"] = 300;
    market_prices["Fish"] = 800;
    market_prices["Rice"] = 120;
    market_prices["Beef"] = 700;
    market_prices["Mushrooms"] = 250;
    market_prices["Cream"] = 150;
    market_prices["Tomato Sauce"] = 130;
    market_prices["Shrimp"] = 950;
    market_prices["Eggs"] = 90;
    market_prices["Bread"] = 60;
    market_prices["Butter"] = 180;

}



void init_cookbook() {

    cookbook.push_back({
        "Pasta Carbonara", 
        {"Pasta", "Cheese", "Beef"}
        });
    cookbook.push_back({
        "Chicken Salad", 
        {"Chicken", "Vegetables"}
        });
    cookbook.push_back({
        "Baked Fish",
        {"Fish", "Vegetables", "Rice"}
        });
    cookbook.push_back({
        "Steak",
        {"Beef", "Vegetables"}
        });
    cookbook.push_back({
        "Chicken Curry", 
        {"Chicken", "Rice", "Vegetables"} 
        });
    cookbook.push_back({
        "Chicken Risotto",
        {"Chicken", "Rice", "Mushrooms", "Cheese"}
        });
    cookbook.push_back({
        "Creamy Chicken",
        {"Chicken", "Cream", "Mushrooms"} 
        });
    cookbook.push_back({
        "Chicken Sandwich",
        {"Chicken", "Bread", "Vegetables", "Cheese"} 
        });
    cookbook.push_back({
        "Chicken Pasta", 
        {"Chicken", "Pasta", "Tomato Sauce"} 
        });
    cookbook.push_back({ 
        "Chicken Soup",
        {"Chicken", "Vegetables", "Rice"}
        });
    cookbook.push_back({ 
        "Fried Chicken",
        {"Chicken", "Bread", "Butter"}
        });
    cookbook.push_back({ 
        "Chicken Omelette",
        {"Chicken", "Eggs", "Cheese"}
        });
    cookbook.push_back({ 
        "Chicken Stir-Fry",
        {"Chicken", "Vegetables", "Rice"} 
        });
    cookbook.push_back({ 
        "Chicken Au Gratin",
        {"Chicken", "Cream", "Cheese"}
        });
    cookbook.push_back({ 
        "Beef Burger",
        {"Beef", "Bread", "Vegetables", "Cheese"}
        });
    cookbook.push_back({
        "Beef Stew",
        {"Beef", "Vegetables", "Tomato Sauce"}
        });
    cookbook.push_back({ 
        "Bolognese Pasta",
        {"Beef", "Pasta", "Tomato Sauce", "Cheese"} 
        });
    cookbook.push_back({ 
        "Beef Stroganoff",
        {"Beef", "Mushrooms", "Cream", "Rice"}
        });
    cookbook.push_back({ 
        "Beef Rice Bowl",
        {"Beef", "Rice", "Vegetables"}
        });
    cookbook.push_back({ 
        "Meatballs",
        {"Beef", "Bread", "Tomato Sauce"}
        });
    cookbook.push_back({ 
        "Stuffed Peppers",
        {"Beef", "Rice", "Vegetables"}
        });
    cookbook.push_back({ 
        "Beef Lasagna", 
        {"Beef", "Pasta", "Cheese", "Tomato Sauce"} 
        });
    cookbook.push_back({
        "Steak with Mushrooms", 
        {"Beef", "Mushrooms", "Butter"}
        });
    cookbook.push_back({ 
        "Beef Pita",
        {"Beef", "Bread", "Vegetables"}
        });
    cookbook.push_back({ 
        "Shrimp Pasta",
        {"Shrimp", "Pasta", "Cream"}
        });
    cookbook.push_back({
        "Fish Tacos",
        {"Fish", "Bread", "Vegetables"}
        });
    cookbook.push_back({ 
        "Shrimp Risotto", 
        {"Shrimp", "Rice", "Cheese", "Butter"} 
        });
    cookbook.push_back({
        "Baked Shrimp",
        {"Shrimp", "Butter", "Vegetables"}
        });
    cookbook.push_back({ 
        "Fish Soup",
        {"Fish", "Vegetables", "Cream"} 
        });
    cookbook.push_back({
        "Grilled Shrimp",
        {"Shrimp", "Vegetables"}
        });
    cookbook.push_back({
        "Fish Casserole",
        {"Fish", "Rice", "Cheese"}
        });
    cookbook.push_back({ 
        "Shrimp Cocktail", 
        {"Shrimp", "Vegetables", "Tomato Sauce"}
        });
    cookbook.push_back({
        "Fish Cutlets",
        {"Fish", "Bread", "Eggs"}
        });
    cookbook.push_back({
        "Shrimp Omelette",
        {"Shrimp", "Eggs", "Cheese"} 
        });
    cookbook.push_back({ 
        "Mushroom Pasta",
        {"Pasta", "Mushrooms", "Cream"}
        });
    cookbook.push_back({
        "Vegetable Rice",
        {"Rice", "Vegetables"}
        });
    cookbook.push_back({
        "Baked Fish",
        {"Fish", "Vegetables", "Butter"}
        });
    cookbook.push_back({
        "Fish and Chips",
        {"Fish", "Vegetables"} 
        });
    cookbook.push_back({
        "Seafood Pasta",
        {"Pasta", "Fish", "Tomato Sauce"}
        });
    cookbook.push_back({ 
        "Creamy Fish Soup", 
        {"Fish", "Cream", "Vegetables"}
        });
    cookbook.push_back({ 
        "Grilled Fish", 
        {"Fish", "Butter"} 
        });
    cookbook.push_back({
        "Fish Rice Bowl", 
        {"Fish", "Rice", "Vegetables"}
        });
    cookbook.push_back({ 
        "Sushi Roll",
        {"Fish", "Rice"} 
        });
    cookbook.push_back({
        "Fish Sandwich",
        {"Fish", "Bread", "Vegetables"}
        });
    cookbook.push_back({
        "Cheesy Fish Bake",
        {"Fish", "Cheese", "Cream"}
        });
    cookbook.push_back({
        "Fisherman's Stew",
        {"Fish", "Tomato Sauce", "Vegetables"}
        });
    cookbook.push_back({ 
        "Pancakes", 
        {"Eggs", "Cream", "Butter"}
        });
    cookbook.push_back({
        "Sweet Rice Plov", 
        {"Rice", "Butter", "Cream"} 
        });
    cookbook.push_back({ 
        "Bread Pudding", 
        {"Bread", "Eggs", "Cream"} 
        });
    cookbook.push_back({
        "Cheese Souffle", 
        {"Eggs", "Cheese"}
        });
    cookbook.push_back({ 
        "Fried Bread with Cheese",
        {"Bread", "Butter", "Cheese"}
        });
    cookbook.push_back({ 
        "Meat Lasagna",
        {"Pasta", "Meat", "Cheese", "Tomato Sauce"}
        });
    cookbook.push_back({
        "Beef Stroganoff",
        {"Meat", "Mushrooms", "Cream"} 
        });
    cookbook.push_back({ 
        "Stuffed Peppers",
        {"Meat", "Rice", "Vegetables"}
        });
    cookbook.push_back({ 
        "Meat Pie",
        {"Meat", "Bread", "Vegetables"}
        });
    cookbook.push_back({ 
        "Cheeseburger", 
        {"Meat", "Bread", "Cheese"}
        });
    cookbook.push_back({ 
        "Meatballs in Tomato Sauce", 
        {"Meat", "Tomato Sauce", "Vegetables"} 
        });
    cookbook.push_back({
        "Creamy Chicken",
        {"Meat", "Cream", "Mushrooms"}
        });
    cookbook.push_back({ 
        "Breakfast Burrito", 
        {"Meat", "Eggs", "Cheese"}
        });
    cookbook.push_back({
        "Shepherd's Pie",
        {"Meat", "Vegetables", "Butter"}
        });
    cookbook.push_back({
        "Carbonara",
        {"Pasta", "Meat", "Eggs", "Cheese"}
        });

}



void apply_inflation() {

    for (auto& item : market_prices) {
        item.second = static_cast<RUB>(item.second * (1.0 + inflation_rate));
    }
    alice.car.gas = static_cast<RUB>(alice.car.gas * (1.0 + inflation_rate));
    alice.car.service = static_cast<RUB>(alice.car.service * (1.0 + inflation_rate));
    alice.beauty = static_cast<RUB>(alice.beauty * (1.0 + inflation_rate));
    alice.my_pet.food_per_month = static_cast<RUB>(alice.my_pet.food_per_month * (1.0 + inflation_rate));
}



void alice_pet_care(int month) {

    alice.pets_expenses = 0;
    alice.pets_expenses += alice.my_pet.food_per_month;
    alice.pets_expenses += alice.my_pet.toys_per_month;

    // Стерилизация коськи в первый месяц дл
    if (!alice.my_pet.is_sterilized && month == 3) {
        alice.pets_expenses += alice.my_pet.sterilization_cost;
        alice.my_pet.is_sterilized = true;
        std::cout << "[Pet] Sonya was sterilized." << std::endl;
    }

    // Прививки раз в год для коськи в сентябре
    if (month == 9) {
        alice.pets_expenses += alice.my_pet.vaccines_annual;
        std::cout << "[Pet] Annual vaccines for Sonya." << std::endl;
    }
}



void alice_cooking() {

    alice.food_expenses = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, cookbook.size() - 1);

    // Элис готовит 4 раза в неделю 
    for (int i = 0; i < 16; ++i) {
        Dish selected = cookbook[dis(gen)];
        for (const auto& ing : selected.ingredients_needed) {
            alice.food_expenses += market_prices[ing];
        }
    }
}



void random_events() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    int chance = dis(gen);

        if (chance <= 5) { 
        RUB repair = 50000;
        alice.cash -= repair;
        std::cout << "[Event] Car broken! Repair cost: "
            << repair << " RUB" << std::endl;
    }

       else if (chance <= 10) { 
        RUB bonus = 30000;
        alice.cash += bonus;
        std::cout << "[Event] Work bonus received: " 
            << bonus << " RUB" << std::endl;
    }

       else if (chance <= 15) { 
        RUB vet_bills = 15000;
        alice.cash -= vet_bills;
        std::cout << "[Event] Pet fell ill. Vet clinic visit cost: "
            << vet_bills << " RUB" << std::endl;
    }

       else if (chance <= 18) { 
        RUB appliance_fix = 8000;
        alice.cash -= appliance_fix;
        std::cout << "[Event] Washing machine leaked! Repair cost: "
            << appliance_fix << " RUB" << std::endl;
    }

      else if (chance <= 19) { 
        RUB fire_damage = 200000;
        alice.cash -= fire_damage;
        std::cout << "[CRITICAL] Small fire in the kitchen! Restoration cost: " 
            << fire_damage << " RUB" << std::endl;
    }

      else if (chance <= 25) { 
        RUB dentist = 12000;
        alice.cash -= dentist;
        std::cout << "[Event] Sudden toothache. Dentist appointment: "
            << dentist << " RUB" << std::endl;
    }

      else if (chance <= 30) {
        RUB gift = 5000;
        alice.cash += gift;
        std::cout << "[Event] Received a cash gift from relatives: " 
            << gift << " RUB" << std::endl;
    }
  
      else if (chance <= 35) { 
            RUB foundMoney = 500;
            alice.cash += foundMoney;
            std::cout << "[Event] You found a bill on the sidewalk: " << foundMoney << " RUB" << std::endl;
        }
       
      else if (chance <= 45) {
            RUB savings = 1200;
            alice.cash += savings;
            std::cout << "[Event] Huge sale at the mall! You saved on groceries: " << savings << " RUB" << std::endl;
        }
     
      else if (chance <= 50) {
            RUB fine = 1500;
            alice.cash -= fine;
            std::cout << "[Event] Received a traffic fine: " << fine << " RUB" << std::endl;
        }

      else if (chance <= 55) { 
            RUB cashback = 800;
            alice.cash += cashback;
            std::cout << "[Event] Monthly cashback received: " << cashback << " RUB" << std::endl;
        }
 
      else if (chance <= 58) { 
            RUB repairCost = 7000;
            alice.cash -= repairCost;
            std::cout << "[Event] Phone screen cracked! Repair cost: " << repairCost << " RUB" << std::endl;
        }

      else if (chance <= 63) { 
            RUB sideHustle = 3000;
            alice.cash += sideHustle;
            std::cout << "[Event] Finished a small freelance project: " << sideHustle << " RUB" << std::endl;
        }

      else if (chance <= 68) {
            RUB mochenniki = 100000;
            alice.cash -= mochenniki;
            std::cout << "[Event] Whoops! You sent your money to bad people((: " << mochenniki << " RUB" << std::endl;
        }

      else if (chance <= 70) {
            RUB lotery = 1000000;
            alice.cash += lotery;
            std::cout << "[Event] Omg you won in lotery, cool, You won: " << lotery << " RUB" << std::endl;
        }

}



float sberbank_interest(RUB amount) {
    if (amount < 500000) return 16.0f;
    return 18.0f;
}



void alice_salary(int year, int month) {
    if (month == 3 && year == 2026) {
        alice.salary = static_cast<RUB>(alice.salary * 1.5);
    }
    alice.cash += alice.salary;

}



void alice_simulation() {

    int year = 2026;
    int month = 2;

    init_market();
    init_cookbook();

    while (!(year == 2027 && month == 2)) {
        std::cout << "--- Month: " << month << " Year: " << year << " ---" << std::endl;

        apply_inflation();
        alice_pet_care(month);
        alice_cooking();
        random_events();

        alice.cash -= alice.food_expenses;
        alice.cash -= alice.pets_expenses;
        alice.cash -= alice.car.gas;
        alice.cash -= alice.car.service;
        alice.cash -= alice.beauty;

        float pp = sberbank_interest(alice.cash);
        alice.cash += static_cast<RUB>(alice.cash * (pp / 12.0 / 100.0));

        alice_salary(year, month);

        std::cout << "Food exp: " << alice.food_expenses << " | Pet exp: " << alice.pets_expenses << std::endl;
        std::cout << "Current Cash: " << alice.cash << " RUB" << std::endl;

        month++;
        if (month == 13) {
            year++;
            month = 1;
        }
    }
}



void print_results() {

    RUB real_capital = alice.cash + alice.car.value + alice.house.value;
    std::cout << "\n=== FINAL RESULTS ===" << std::endl;
    std::cout << "Final Salary: " << alice.salary << " RUB" << std::endl;
    std::cout << "Cash: " << alice.cash << " RUB" << std::endl;
    std::cout << "Pet (Sonya) is healthy and happy :3" << std::endl;
    std::cout << "TOTAL REAL CAPITAL: " << real_capital << " RUB" << std::endl;
}

int main() {
    alice_simulation();
    print_results();
    return 0;

}