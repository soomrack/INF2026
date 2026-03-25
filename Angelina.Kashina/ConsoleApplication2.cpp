#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>



using RUB = long long;



RUB TAX_RATE = 13; // 13% налог
RUB apply_tax(RUB income) {
    RUB tax = income * TAX_RATE / 100;
    return income - tax;
}



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



struct Car {
      RUB value = 2000000;
      RUB gas = 8000;
      RUB service = 3000;
    } car;



struct House {

      RUB value = 10000000;
} house;



struct Friend {
    std::string name;
    int loyalty = 50; // до 100
    bool owes_help = false;
};



struct Health {
    int value = 100;      // до 100
    bool sick = false;
    bool injured = false;
};



struct Career {
    int score = 50;       // до 100
    std::string position = "Employee";
};



struct SocialLife {
    std::vector<Friend> friends_list;
    int reputation = 50;  // до 100
};



struct Investments {
    RUB real_estate = 0;
    RUB stocks = 0;
    RUB cars = 0;
};



struct Alice {

    RUB cash = 100000;
    RUB salary = 150000;
    RUB beauty = 7000;
    RUB pets_expenses = 0;
    RUB food_expenses = 0;
    Health health;
    Career career;
    SocialLife social;
    Investments investments;
    Pet my_pet;
    Car car;
    House house;

    void init_friends(Alice& person) {
        person.social.friends_list = {
            {"Anna", 80, false},
            {"Boris", 50, false},
            {"Clara", 70, false},
            {"Dmitry", 40, false},
            {"Elena", 60, false}
        };
    };
};



    Alice alice;
    double inflation_rate = 0.007; // 0.7% в месяц
    std::map<std::string, RUB> market_prices;
    std::vector<Dish> cookbook;
  



struct LifeEvents {

    int relationship_score = 100;

    bool married = false;
    bool divorced = false;

    bool pregnant = false;
    int pregnancy_month = 0;
    int children = 0;

    RUB wedding_cost = 300000;
    RUB maternity_capital = 729000;

    struct Business {
        bool active = false;
        RUB account = 0;
        RUB debt = 0;

        RUB income = 0;

        std::vector<RUB> employees = { 40000, 50000, 60000 }; // зпшка
    } business;

    struct RiskyLife {

        bool failed_business = false;

        bool trading = false;
        RUB trading_account = 0;

        bool illegal = false;
        RUB illegal_income = 0;

        bool caught = false;
        bool in_prison = false;

        RUB lawyer_cost = 150000;
        RUB fine = 500000;

        int prison_months = 0;

        int reputation = 100; 

        enum IllegalType {
            NONE,
            FRAUD,
            SHADOW_CAFE,
            SMUGGLING
        } illegal_type = NONE;

    } risky;

} life;



// фия для рандома
std::mt19937 gen(std::random_device{}());



RUB random_range(RUB a, RUB b) {
    std::uniform_int_distribution<RUB> d(a, b);
    return d(gen);
}

RUB generate_wedding_gifts() {
    RUB guests = random_range(20, 60);
    RUB total = 0;
    for (int i = 0; i < guests; i++)
        total += random_range(1000, 10000);
    return total;
}



// бизнес Элис
void business_logic() {

    if (!life.business.active) return;

   
    RUB invest = 30000;
    alice.cash -= invest;
    life.business.account += invest;

    
    RUB salary = 0;
    for (auto s : life.business.employees) salary += s;

    RUB expenses = salary + 30000 + 20000 + 10000;

    life.business.account -= expenses;

    
    RUB income = 0;
    for (int i = 0; i < 50; i++) {
        Dish d = cookbook[random_range(0, cookbook.size() - 1)];
        RUB cost = 0;
        for (auto& ing : d.ingredients_needed)
            cost += market_prices[ing];

        income += cost * 2; // наценочка
    }

   
    life.business.income += 10000;
    income += life.business.income;

    RUB taxed_income = apply_tax(income);
    life.business.account += taxed_income;

    std::cout << "[Tax] Business tax paid: " << (income - taxed_income) << std::endl;

   
    if (life.business.account < 0) {
        RUB credit = 200000;
        life.business.account += credit;
        life.business.debt += credit;
        std::cout << "[Business] Took credit: " << credit << std::endl;
    }

 
    if (life.business.account < -500000) {
        life.business.active = false;
        std::cout << "[Business] BANKRUPTCY!" << std::endl;
    }

    std::cout << "[Business] Income: " << income
        << " Balance: " << life.business.account << std::endl;
}



void failed_business_logic(int month) {

    if (month == 8 && !life.risky.failed_business) {

        RUB credit = 1000000;
        alice.cash += credit;
        life.business.debt += credit;

        std::cout << "[Business] Alice took a big loan: " << credit << std::endl;

        RUB invest = 800000;
        alice.cash -= invest;

        std::cout << "[Business] New risky business launched..." << std::endl;

        // почти гарантированный провал во имя сюжета
        if (random_range(1, 100) <= 80) {
            life.risky.failed_business = true;
            std::cout << "[Business] Business FAILED lol" << std::endl;
        }
    }
}



void trading_logic() {

    if (!life.risky.failed_business || life.risky.trading) return;

    life.risky.trading = true;
    life.risky.trading_account = 200000;
    alice.cash -= 200000;

    std::cout << "[Stocks] Alice started trading..." << std::endl;
}



void trading_process() {

    if (!life.risky.trading || life.risky.illegal) return;

    RUB result = random_range(-50000, 50000);
        result = apply_tax(std::max(result, (RUB)0)); // налог только на прибыль

    life.risky.trading_account += result;

    std::cout << "[Stocks] Result: " << result
        << " Balance: " << life.risky.trading_account << std::endl;

    int baseChance = 70;

    // чем больше детей — тем меньше шанс уйти в криминал
    int child_modifier = life.children * 15;

    int finalChance = baseChance - child_modifier;

    if (life.risky.trading_account < 50000 &&
        random_range(1, 100) <= finalChance) {

        life.risky.trading = false;
        life.risky.illegal = true;

      // иллюзия выбора 
        RUB type = random_range(1, 3);

        if (type == 1) life.risky.illegal_type = LifeEvents::RiskyLife::FRAUD;
        if (type == 2) life.risky.illegal_type = LifeEvents::RiskyLife::SHADOW_CAFE;
        if (type == 3) life.risky.illegal_type = LifeEvents::RiskyLife::SMUGGLING;

        std::cout << "[Life] Trading failed... entering illegal business" << std::endl;
    }
}


void court_case() {

    if (!life.risky.caught || life.risky.in_prison) return;

    alice.cash -= life.risky.lawyer_cost;

    std::cout << "[Court] Paid lawyer: " << life.risky.lawyer_cost << std::endl;

    if (random_range(1, 100) <= 50) {
        life.risky.in_prison = true;
        life.risky.prison_months = 12;

        std::cout << "[Court] LOST. Alice goes to prison for 12 months. Not good(" << std::endl;
    }
    else {
        alice.cash -= life.risky.fine;
        life.risky.illegal = false;

        life.risky.reputation -= 20;

        std::cout << "[Court] WON. Paid fine: " << life.risky.fine << std::endl;
    }
}



void illegal_activity() {

    if (!life.risky.illegal || life.risky.caught) return;

    RUB income = 0;
    int risk = 0;

    switch (life.risky.illegal_type) {

    case LifeEvents::RiskyLife::FRAUD:
        income = random_range(30000, 120000);
        risk = 25;
        std::cout << "[Illegal] Fraud scheme running..." << std::endl;
        break;

    case LifeEvents::RiskyLife::SHADOW_CAFE:
        income = random_range(50000, 150000);
        risk = 15;
        std::cout << "[Illegal] Shadow cafe working..." << std::endl;
        break;

    case LifeEvents::RiskyLife::SMUGGLING:
        income = random_range(80000, 250000);
        risk = 35;
        std::cout << "[Illegal] Smuggling operation..." << std::endl;
        break;

    default:
        return;
    }

    income = apply_tax(income / 2);

    alice.cash += income;
    life.risky.illegal_income += income;

    std::cout << "[Illegal] Earned: " << income << std::endl;

    if (random_range(1, 100) <= risk) {
        life.risky.caught = true;
        std::cout << "[CRIME] Alice got caught!" << std::endl;
    }
}



void prison_logic() {

    if (!life.risky.in_prison) return;

    life.risky.prison_months--;

    std::cout << "[Prison] Months left: " << life.risky.prison_months << std::endl;

    if (life.risky.prison_months <= 0) {
        life.risky.in_prison = false;
        life.risky.caught = false;

        life.risky.reputation = std::max(0, life.risky.reputation);

        std::cout << "[Life] Alice released from prison..." << std::endl;
    }
}



void life_events(int month) {

   
    if (month == 2 && !life.married) {
        life.married = true;

        RUB gifts = generate_wedding_gifts();

        alice.cash -= life.wedding_cost;
        alice.cash += gifts;

        std::cout << "[Life] Wedding! Gifts: " << gifts << std::endl;
    }

    
    if (life.married && !life.divorced && random_range(1, 100) <= 5) {
        life.divorced = true;
        alice.cash -= 200000;
        std::cout << "[Life] Divorce happened..." << std::endl;
    }

   
    if (month == 5 && !life.pregnant) {
        life.pregnant = true;
        life.pregnancy_month = 1;
        std::cout << "[Life] Pregnancy started" << std::endl;
    }

    if (life.pregnant) {

        life.pregnancy_month++;

        RUB cost = 15000;
        if (life.pregnancy_month == 9) {
            cost += 150000;
            alice.cash += life.maternity_capital;
            life.children++;

            std::cout << "[Life] Child born! Total children: " << life.children << std::endl;
        }

        alice.cash -= cost;

        if (life.pregnancy_month >= 5)
            alice.salary = 0;
    }

    
    if (life.children == 1 && random_range(1, 100) < 20) {
        life.pregnant = true;
        life.pregnancy_month = 1;
        std::cout << "[Life] Second pregnancy!" << std::endl;
    }

    // бизнес
    if (month == 7 && !life.business.active) {
        life.business.active = true;

        RUB start = 400000;
        alice.cash -= start;
        life.business.account += 200000;

        std::cout << "[Business] Cafe opened!" << std::endl;
    }

    business_logic();
}



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
    market_prices["Pork"] = 650;
    market_prices["Potatoes"] = 80;
    market_prices["Onions"] = 50;
    market_prices["Garlic"] = 40;
    market_prices["Lemon"] = 70;
    market_prices["Herbs"] = 60;
    market_prices["Olive Oil"] = 200;
    market_prices["Sour Cream"] = 120;
    market_prices["Bacon"] = 350;
    market_prices["Tomatoes"] = 100;
    market_prices["Cucumbers"] = 90;
    market_prices["Carrots"] = 70;
    market_prices["Peppers"] = 110;
    market_prices["Corn"] = 85;
    market_prices["Beans"] = 95;
    market_prices["Tofu"] = 280;
    market_prices["Lamb"] = 850;
    market_prices["Duck"] = 900;
    market_prices["Sausages"] = 320;
    market_prices["Broccoli"] = 110;
    market_prices["Spinach"] = 95;
    market_prices["Honey"] = 140;
    market_prices["Nuts"] = 220;
    market_prices["Yogurt"] = 100;
    market_prices["Flour"] = 70;
    market_prices["Sugar"] = 60;
    market_prices["Chocolate"] = 180;
    market_prices["Milk"] = 85;
    market_prices["Cinnamon"] = 95;
    market_prices["Vanilla"] = 120;
    market_prices["Soy Sauce"] = 110;
    market_prices["Ginger"] = 90;
    market_prices["Chili"] = 65;
    market_prices["Coconut Milk"] = 160;
    market_prices["Curry Paste"] = 140;
    market_prices["Lime"] = 55;

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
    cookbook.push_back({
        "Pork Chop",
        {"Pork", "Potatoes", "Vegetables"}
        });
    cookbook.push_back({
        "BBQ Pork Ribs",
        {"Pork", "Tomato Sauce", "Honey"}
        });
    cookbook.push_back({
        "Pork Schnitzel",
        {"Pork", "Bread", "Eggs", "Lemon"}
        });
    cookbook.push_back({
        "Pork Stir-Fry",
        {"Pork", "Vegetables", "Soy Sauce", "Ginger"}
        });
    cookbook.push_back({
        "Stuffed Pork Tenderloin",
        {"Pork", "Mushrooms", "Cheese", "Garlic"}
        });
    cookbook.push_back({
        "Pork Adobo",
        {"Pork", "Soy Sauce", "Garlic", "Onions"}
        });
    cookbook.push_back({
        "Pork Meatballs",
        {"Pork", "Bread", "Tomato Sauce", "Herbs"}
        });
    cookbook.push_back({
        "Pork Tacos",
        {"Pork", "Bread", "Vegetables", "Onions"}
        });
    cookbook.push_back({
        "Lamb Chops",
        {"Lamb", "Garlic", "Herbs", "Butter"}
        });
    cookbook.push_back({
        "Lamb Curry",
        {"Lamb", "Rice", "Coconut Milk", "Curry Paste"}
        });
    cookbook.push_back({
        "Lamb Stew",
        {"Lamb", "Potatoes", "Carrots", "Onions"}
        });
    cookbook.push_back({
        "Grilled Lamb",
        {"Lamb", "Lemon", "Herbs", "Olive Oil"}
        });
    cookbook.push_back({
        "Lamb Kebabs",
        {"Lamb", "Onions", "Peppers", "Yogurt"}
        });
    cookbook.push_back({
        "Roasted Duck",
        {"Duck", "Honey", "Soy Sauce", "Ginger"}
        });
    cookbook.push_back({
        "Duck Breast",
        {"Duck", "Honey", "Garlic", "Vegetables"}
        });
    cookbook.push_back({
        "Duck Noodles",
        {"Duck", "Pasta", "Soy Sauce", "Vegetables"}
        });
    cookbook.push_back({
        "Vegetable Stir-Fry",
        {"Vegetables", "Tofu", "Soy Sauce", "Ginger"}
        });
    cookbook.push_back({
        "Tofu Curry",
        {"Tofu", "Coconut Milk", "Rice", "Curry Paste"}
        });
    cookbook.push_back({
        "Vegetable Lasagna",
        {"Pasta", "Vegetables", "Cheese", "Tomato Sauce"}
        });
    cookbook.push_back({
        "Stuffed Mushrooms",
        {"Mushrooms", "Cheese", "Garlic", "Herbs"}
        });
    cookbook.push_back({
        "Vegetable Soup",
        {"Vegetables", "Potatoes", "Carrots", "Onions"}
        });
    cookbook.push_back({
        "Ratatouille",
        {"Vegetables", "Tomatoes", "Garlic", "Olive Oil"}
        });
    cookbook.push_back({
        "Broccoli Cheddar Soup",
        {"Broccoli", "Cheese", "Cream", "Onions"}
        });
    cookbook.push_back({
        "Spinach Ricotta Pasta",
        {"Pasta", "Spinach", "Cheese", "Garlic"}
        });
    cookbook.push_back({
        "Vegetable Paella",
        {"Rice", "Vegetables", "Peppers", "Tomatoes"}
        });
    cookbook.push_back({
        "Bean Burrito",
        {"Beans", "Bread", "Cheese", "Vegetables"}
        });
    cookbook.push_back({
        "Omelette",
        {"Eggs", "Cheese", "Vegetables", "Butter"}
        });
    cookbook.push_back({
        "French Toast",
        {"Bread", "Eggs", "Milk", "Cinnamon"}
        });
    cookbook.push_back({
        "Scrambled Eggs",
        {"Eggs", "Butter", "Milk", "Cheese"}
        });
    cookbook.push_back({
        "Breakfast Sandwich",
        {"Bread", "Eggs", "Cheese", "Bacon"}
        });
    cookbook.push_back({
        "Porridge",
        {"Milk", "Honey", "Nuts", "Cinnamon"}
        });
        cookbook.push_back({
        "Paella",
        {"Rice", "Shrimp", "Fish", "Vegetables"}
        });
    cookbook.push_back({
        "Seafood Chowder",
        {"Fish", "Shrimp", "Cream", "Potatoes"}
        });
    cookbook.push_back({
        "Garlic Shrimp",
        {"Shrimp", "Garlic", "Butter", "Lemon"}
        });
    cookbook.push_back({
        "Lemon Fish",
        {"Fish", "Lemon", "Butter", "Herbs"}
        });
        cookbook.push_back({
        "Tomato Soup",
        {"Tomatoes", "Cream", "Onions", "Garlic"}
        });
    cookbook.push_back({
        "Mushroom Soup",
        {"Mushrooms", "Cream", "Onions", "Butter"}
        });
    cookbook.push_back({
        "Beef Noodle Soup",
        {"Beef", "Pasta", "Vegetables", "Onions"}
        });
        cookbook.push_back({
        "Chocolate Cake",
        {"Flour", "Sugar", "Chocolate", "Eggs", "Butter"}
        });
    cookbook.push_back({
        "Cheesecake",
        {"Cheese", "Sugar", "Eggs", "Butter"}
        });
    cookbook.push_back({
        "Apple Pie",
        {"Flour", "Butter", "Sugar", "Cinnamon"}
        });
    cookbook.push_back({
        "Ice Cream",
        {"Milk", "Cream", "Sugar", "Vanilla"}
        });
    cookbook.push_back({
        "Brownies",
        {"Chocolate", "Butter", "Sugar", "Eggs", "Flour"}
        });
    cookbook.push_back({
        "Cinnamon Rolls",
        {"Flour", "Butter", "Sugar", "Cinnamon", "Milk"}
        });
    cookbook.push_back({
        "Pudding",
        {"Milk", "Sugar", "Vanilla", "Eggs"}
        });
        cookbook.push_back({
        "Pasta Alfredo",
        {"Pasta", "Cream", "Cheese", "Butter"}
        });
    cookbook.push_back({
        "Pasta Primavera",
        {"Pasta", "Vegetables", "Cream", "Cheese"}
        });
    cookbook.push_back({
        "Pasta with Pesto",
        {"Pasta", "Herbs", "Garlic", "Cheese", "Nuts"}
        });
    cookbook.push_back({
        "Mashed Potatoes",
        {"Potatoes", "Butter", "Milk"}
        });
    cookbook.push_back({
        "Roasted Vegetables",
        {"Vegetables", "Olive Oil", "Herbs", "Garlic"}
        });
    cookbook.push_back({
        "Garlic Bread",
        {"Bread", "Butter", "Garlic", "Herbs"}
        });
    cookbook.push_back({
        "French Fries",
        {"Potatoes", "Olive Oil"}
        });
    cookbook.push_back({
        "Sausage Pasta",
        {"Sausages", "Pasta", "Tomato Sauce", "Cheese"}
        });
    cookbook.push_back({
        "Sausage Casserole",
        {"Sausages", "Potatoes", "Vegetables", "Tomato Sauce"}
        });
    cookbook.push_back({
        "Hot Dogs",
        {"Sausages", "Bread", "Onions", "Tomato Sauce"}
        });
    cookbook.push_back({
        "Sausage Breakfast",
        {"Sausages", "Eggs", "Beans", "Bread"}
        });
    cookbook.push_back({
        "Fried Rice",
        {"Rice", "Eggs", "Vegetables", "Soy Sauce"}
        });
    cookbook.push_back({
        "Risotto",
        {"Rice", "Mushrooms", "Cheese", "Butter"}
        });
    cookbook.push_back({
        "Jambalaya",
        {"Rice", "Sausages", "Chicken", "Tomatoes"}
        });
        cookbook.push_back({
        "Quinoa Salad",
        {"Rice", "Vegetables", "Lemon", "Herbs"}
        });
    cookbook.push_back({
        "Greek Salad",
        {"Vegetables", "Cheese", "Olive Oil", "Lemon"}
        });
    cookbook.push_back({
        "Buddha Bowl",
        {"Rice", "Vegetables", "Beans", "Avocado"}
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

    // Стерилизация коськи в первый месяц
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
    Dish selected = cookbook[random_range(0, cookbook.size() - 1)];

    // Элис готовит 4 раза в неделю 
    for (int i = 0; i < 16; ++i) {
        Dish selected = cookbook[random_range(0, cookbook.size() - 1)];
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

        if (chance <= 2) { 
        RUB repair = 50000;
        alice.cash -= repair;
        std::cout << "[Event] Car broken! Repair cost: "
            << repair << " RUB" << std::endl;
    }

       else if (chance <= 4) { 
        RUB bonus = 30000;
        bonus = apply_tax(bonus);
        alice.cash += bonus;
        std::cout << "[Event] Work bonus received: " 
            << bonus << " RUB" << std::endl;
    }

       else if (chance <= 6) { 
        RUB vet_bills = 15000;
        alice.cash -= vet_bills;
        std::cout << "[Event] Pet fell ill. Vet clinic visit cost: "
            << vet_bills << " RUB" << std::endl;
    }

       else if (chance <= 8) { 
        RUB appliance_fix = 8000;
        alice.cash -= appliance_fix;
        std::cout << "[Event] Washing machine leaked! Repair cost: "
            << appliance_fix << " RUB" << std::endl;
    }

      else if (chance <= 10) { 
        RUB fire_damage = 200000;
        alice.cash -= fire_damage;
        std::cout << "[CRITICAL] Small fire in the kitchen! Restoration cost: " 
            << fire_damage << " RUB" << std::endl;
    }

      else if (chance <= 12) { 
        RUB dentist = 12000;
        alice.cash -= dentist;
        std::cout << "[Event] Sudden toothache. Dentist appointment: "
            << dentist << " RUB" << std::endl;
    }

      else if (chance <= 16) {
        RUB gift = 5000;
        alice.cash += gift;
        std::cout << "[Event] Received a cash gift from relatives: " 
            << gift << " RUB" << std::endl;
    }
  
      else if (chance <= 18) { 
            RUB foundMoney = 500;
            alice.cash += foundMoney;
            std::cout << "[Event] You found a bill on the sidewalk: " << foundMoney << " RUB" << std::endl;
        }
       
      else if (chance <= 20) {
            RUB savings = 1200;
            alice.cash += savings;
            std::cout << "[Event] Huge sale at the mall! You saved on groceries: " << savings << " RUB" << std::endl;
        }
     
      else if (chance <= 22) {
            RUB fine = 1500;
            alice.cash -= fine;
            std::cout << "[Event] Received a traffic fine: " << fine << " RUB" << std::endl;
        }

      else if (chance <= 24) { 
            RUB cashback = 800;
            alice.cash += cashback;
            std::cout << "[Event] Monthly cashback received: " << cashback << " RUB" << std::endl;
        }
 
      else if (chance <= 26) { 
            RUB repairCost = 7000;
            alice.cash -= repairCost;
            std::cout << "[Event] Phone screen cracked! Repair cost: " << repairCost << " RUB" << std::endl;
        }

      else if (chance <= 28) { 
            RUB sideHustle = 3000;
            sideHustle = apply_tax(sideHustle);
            alice.cash += sideHustle;
            std::cout << "[Event] Finished a small freelance project: " << sideHustle << " RUB" << std::endl;
        }

      else if (chance <= 30) {
            RUB mochenniki = 100000;
            alice.cash -= mochenniki;
            std::cout << "[Event] Whoops! You sent your money to bad people((: " << mochenniki << " RUB" << std::endl;
        }

      else if (chance <= 40) {
            RUB lotery = 100000;
            lotery = apply_tax(lotery);
            alice.cash += lotery;
            std::cout << "[Event] Omg you won in lotery, cool, You won: " << lotery << " RUB" << std::endl;
        }

      else if (chance <= 42) {
            RUB medical_bill = 25000;
            alice.cash -= medical_bill;
            std::cout << "[Event] Unexpected medical procedure needed! Cost: " << medical_bill << " RUB" << std::endl;
        }

      else if (chance <= 44) {
            RUB inheritance = 75000;
            inheritance = apply_tax(inheritance);
            alice.cash += inheritance;
            std::cout << "[Event] Received inheritance from distant relative: " << inheritance << " RUB" << std::endl;
        }

      else if (chance <= 46) {
            RUB fridge_break = 18000;
            alice.cash -= fridge_break;
            std::cout << "[Event] Refrigerator broke down! New fridge cost: " << fridge_break << " RUB" << std::endl;
        }

      else if (chance <= 48) {
            RUB investment_return = 12000;
            investment_return = apply_tax(investment_return);
            alice.cash += investment_return;
            std::cout << "[Event] Small investment paid dividends: " << investment_return << " RUB" << std::endl;
        }

      else if (chance <= 50) {
            RUB stolen_wallet = 2500;
            alice.cash -= stolen_wallet;
            std::cout << "[Event] Wallet was stolen! Lost: " << stolen_wallet << " RUB" << std::endl;
        }

      else if (chance <= 52) {
            RUB contest_win = 15000;
            contest_win = apply_tax(contest_win);
            alice.cash += contest_win;
            std::cout << "[Event] Won a cooking contest! Prize: " << contest_win << " RUB" << std::endl;
        }

      else if (chance <= 54) {
            RUB heating_repair = 22000;
            alice.cash -= heating_repair;
            std::cout << "[Event] Heating system malfunction! Emergency repair: " << heating_repair << " RUB" << std::endl;
        }

      else if (chance <= 56) {
            RUB bonus_from_client = 5000;
            bonus_from_client = apply_tax(bonus_from_client);
            alice.cash += bonus_from_client;
            std::cout << "[Event] Happy client left a generous tip: " << bonus_from_client << " RUB" << std::endl;
        }

      else if (chance <= 58) {
            RUB gym_membership = 3500;
            alice.cash -= gym_membership;
            std::cout << "[Event] Signed up for gym membership: " << gym_membership << " RUB" << std::endl;
        }

      else if (chance <= 60) {
            RUB lucky_find = 2500;
            alice.cash += lucky_find;
            std::cout << "[Event] Found an old gift card with balance: " << lucky_find << " RUB" << std::endl;
        }

      else if (chance <= 60) {
            RUB lucky_find = 2500;
            alice.cash += lucky_find;
            std::cout << "[Event] Found an old gift card with balance: " << lucky_find << " RUB" << std::endl;
        }

      else if (chance <= 62) {
            RUB water_pipe = 45000;
            alice.cash -= water_pipe;
            std::cout << "[Event] Burst water pipe! Emergency plumber cost: " << water_pipe << " RUB" << std::endl;
        }

      else if (chance <= 64) {
            RUB art_sale = 18000;
            art_sale = apply_tax(art_sale);
            alice.cash += art_sale;
            std::cout << "[Event] Sold handmade crafts at fair: " << art_sale << " RUB" << std::endl;
        }

      else if (chance <= 66) {
            RUB parking_fine = 3000;
            alice.cash -= parking_fine;
            std::cout << "[Event] Accumulated parking tickets: " << parking_fine << " RUB" << std::endl;
        }

      else if (chance <= 68) {
            RUB neighbor_return = 7000;
            alice.cash += neighbor_return;
            std::cout << "[Event] Neighbor returned old debt: " << neighbor_return << " RUB" << std::endl;
        }

      else if (chance <= 70) {
            RUB laptop_repair = 15000;
            alice.cash -= laptop_repair;
            std::cout << "[Event] Laptop stopped working! Repair cost: " << laptop_repair << " RUB" << std::endl;
        }

      else if (chance <= 72) {
            RUB birthday_gift = 10000;
            alice.cash += birthday_gift;
            std::cout << "[Event] Generous birthday gifts from friends: " << birthday_gift << " RUB" << std::endl;
        }

      else if (chance <= 74) {
            RUB electricity_bill = 9000;
            alice.cash -= electricity_bill;
            std::cout << "[Event] Unexpected high electricity bill: " << electricity_bill << " RUB" << std::endl;
        }

      else if (chance <= 76) {
            RUB cashback_bonus = 2500;
            alice.cash += cashback_bonus;
            std::cout << "[Event] Credit card cashback bonus: " << cashback_bonus << " RUB" << std::endl;
        }

      else if (chance <= 78) {
            RUB dental_implant = 35000;
            alice.cash -= dental_implant;
            std::cout << "[Event] Urgent dental implant needed! Cost: " << dental_implant << " RUB" << std::endl;
        }

      else if (chance <= 80) {
            RUB stock_profit = 22000;
            stock_profit = apply_tax(stock_profit);
            alice.cash += stock_profit;
            std::cout << "[Event] Smart stock market trade paid off: " << stock_profit << " RUB" << std::endl;
        }

      else if (chance <= 82) {
            RUB broken_window = 12000;
            alice.cash -= broken_window;
            std::cout << "[Event] Storm broke apartment window! Replacement: " << broken_window << " RUB" << std::endl;
        }

      else if (chance <= 84) {
            RUB blog_income = 8000;
            blog_income = apply_tax(blog_income);
            alice.cash += blog_income;
            std::cout << "[Event] First income from cooking blog: " << blog_income << " RUB" << std::endl;
        }

      else if (chance <= 86) {
            RUB speeding_ticket = 5000;
            alice.cash -= speeding_ticket;
            std::cout << "[Event] Speed camera caught you! Fine: " << speeding_ticket << " RUB" << std::endl;
        }

      else if (chance <= 88) {
            RUB mystery_box = 1500;
            alice.cash += mystery_box;
            std::cout << "[Event] Won prize in mystery box contest: " << mystery_box << " RUB" << std::endl;
        }

      else if (chance <= 90) {
            RUB roof_leak = 28000;
            alice.cash -= roof_leak;
            std::cout << "[Event] Roof started leaking! Emergency repair: " << roof_leak << " RUB" << std::endl;
        }

      else if (chance <= 92) {
            RUB pet_sitting = 12000;
            pet_sitting = apply_tax(pet_sitting);
            alice.cash += pet_sitting;
            std::cout << "[Event] Pet sitting for neighbor during vacation: " << pet_sitting << " RUB" << std::endl;
        }

      else if (chance <= 94) {
            RUB smartphone_stolen = 40000;
            alice.cash -= smartphone_stolen;
            std::cout << "[Event] New smartphone was stolen! Replacement cost: " << smartphone_stolen << " RUB" << std::endl;
        }

      else if (chance <= 98) {
            RUB kitchen_renovation = 55000;
            alice.cash -= kitchen_renovation;
            std::cout << "[Event] Kitchen renovation went over budget! Extra cost: " << kitchen_renovation << " RUB" << std::endl;
        }

      else if (chance <= 100) {
            RUB lottery_second = 5000;
            lottery_second = apply_tax(lottery_second);
            alice.cash += lottery_second;
            std::cout << "[Event] Won second prize in local lottery! Amount: " << lottery_second << " RUB" << std::endl;
        }
                                                                                          
}



float sberbank_interest(RUB amount) {
    if (amount < 500000) return 16.0f;
    return 18.0f;
}



void alice_salary(int year, int month) {

    if (life.risky.in_prison) {
        std::cout << "[Life] Alice is in prison. No salary." << std::endl;
        return;
    }

    if (month == 3 && year == 2026) {
        alice.salary = static_cast<RUB>(alice.salary * 1.5);
    }

    // штраф к зп за плохую репутацию
    RUB adjusted_salary = alice.salary * life.risky.reputation / 100;

    RUB taxed_salary = apply_tax(adjusted_salary);
    alice.cash += taxed_salary;

    std::cout << "[Tax] Salary after tax: " << taxed_salary << std::endl;
}


void career_events() {
    int chance = random_range(1, 100);
   
    if (chance <= 15) {
        alice.career.score += random_range(5, 10);
        std::cout << "[Career] Project success! Career score: " << alice.career.score << std::endl;
    }
    else if (chance <= 25) {
        alice.career.score -= random_range(5, 15);
        std::cout << "[Career] Project failure. Career score: " << alice.career.score << std::endl;
    }

    alice.salary = 150000 * alice.career.score / 100;
}



void social_events() {
    int chance = random_range(1, 100);
    if (chance <= 10 && !alice.social.friends_list.empty()) {
        int idx = random_range(0, alice.social.friends_list.size() - 1);
        if (alice.social.friends_list[idx].loyalty > 50) {
            RUB gift = random_range(5000, 20000);
            alice.cash += gift;
            std::cout << "[Friends] " << alice.social.friends_list[idx].name
                << " gave money: " << gift << std::endl;
        }
    }
}



void investments_logic() {
    int chance = random_range(1, 100);

    // покупка недвижки
    if (chance <= 5 && alice.cash > 500000) {
        alice.investments.real_estate += 500000;
        alice.cash -= 500000;
        std::cout << "[Invest] Bought property for 500000 RUB." << std::endl;
    }

    // рыночные потери
    if (chance <= 3 && alice.investments.real_estate > 0) {
        alice.investments.real_estate *= 0.7;
        std::cout << "[Invest] Market crash! Real estate lost 30%." << std::endl;
    }
}



void disaster_events() {
    int chance = random_range(1, 1000);
    if (chance <= 2) {
        RUB damage = random_range(100000, 300000);
        alice.cash -= damage;
        std::cout << "[Disaster] Fire or flood! Damage: " << damage << " RUB" << std::endl;
    }
}



void hobbies_events() {
    int chance = random_range(1, 100);
    if (chance <= 10) {
        RUB cost = random_range(10000, 50000);
        alice.cash -= cost;
        alice.social.reputation += 5;
        std::cout << "[Hobby] Alice went on a luxury trip. Cost: " << cost
            << ", Reputation +5" << std::endl;
    }
}



void family_conflict() {
    int chance = random_range(1, 100);
    if (chance <= 10) {
        int change = random_range(5, 15);
        life.relationship_score -= change;
        std::cout << "[Drama] Spouse had an argument. Relationship score: "
            << life.relationship_score << std::endl;
    }

    if (life.relationship_score < 20 && !life.divorced) {
        life.divorced = true;
        RUB alimony = 200000;
        alice.cash -= alimony;
        std::cout << "[Drama] Divorce! Paid alimony: " << alimony << std::endl;
    }
}


void health_events() {
    int chance = random_range(1, 100);
    if (chance <= 5) {
        int damage = random_range(5, 20);
        alice.health.value -= damage;
        alice.health.sick = true;
        std::cout << "[Health] Alice caught a cold. Health -" << damage
            << ". Current: " << alice.health.value << std::endl;
    }

    if (alice.health.value < 50) {
        alice.salary = alice.salary * 0.7;
        std::cout << "[Health] Low health affects salary!" << std::endl;
    }
}



RUB nanny_expenses() {
    RUB nanny_cost_per_child = 40000;
    if (life.children == 0) return 0;

    RUB total = life.children * nanny_cost_per_child;

    std::cout << "[Kids] Nanny cost: " << total << std::endl;

    return total;
}



void exp() {

    std::cout << "Food exp: " << alice.food_expenses << " | Pet exp: " << alice.pets_expenses << std::endl;
    std::cout << "Current Cash: " << alice.cash << " RUB" << std::endl;

}



void sberlogic() {

    float pp = sberbank_interest(alice.cash);
    alice.cash += static_cast<RUB>(alice.cash * (pp / 12.0 / 100.0));

}



void update_life(int month) {
    life_events(month);
    failed_business_logic(month);
    trading_logic();
    trading_process();
    illegal_activity();
    court_case();
    prison_logic();
}



void alice_simulation() {

    int year = 2026;
    int month = 2;

    init_market();
    init_cookbook();

    while (!(year == 2027 && month == 2)) {
        std::cout << "--- Month: " << month << " Year: " << year << " ---" << std::endl;

        init_market();
        init_cookbook();
        apply_inflation();
        alice_pet_care(month);
        alice_cooking();
        random_events();
        life_events(month);
        failed_business_logic(month);
        trading_logic();
        trading_process();
        illegal_activity();
        court_case();
        update_life(month);
        family_conflict();
        health_events();
        career_events();
        social_events();
        investments_logic();
        disaster_events();
        hobbies_events();

        if (!life.risky.in_prison) {
            alice.cash -= alice.food_expenses;
            alice.cash -= alice.pets_expenses;
            alice.cash -= alice.car.gas;
            alice.cash -= alice.car.service;
            alice.cash -= alice.beauty;
            alice.cash -= nanny_expenses();

        }
        prison_logic();

        sberlogic();

        alice_salary(year, month);

        exp();

        month++;
        if (month == 13) {
            year++;
            month = 1;
        }

        if (alice.cash < -500000) {
            std::cout << "[CRITICAL] Alice is bankrupt...(" << std::endl;
        }
    }
}



void print_results() {

    RUB real_capital = alice.cash + alice.car.value + alice.house.value;
    std::cout << "\n=== FINAL RESULTS ===" << std::endl;
    std::cout << "Final Salary: " << alice.salary << " RUB" << std::endl;
    std::cout << "Cash: " << alice.cash << " RUB" << std::endl;
    std::cout << "Pet (Sonya) is healthy and happy :3" << std::endl;
    std::cout << "Assets (Car + House): " << alice.car.value + alice.house.value << " RUB" << std::endl;
    std::cout << "TOTAL REAL CAPITAL: " << real_capital << " RUB" << std::endl;

}

int main() {
    alice_simulation();
    print_results();
    return 0;                                                                                     

}