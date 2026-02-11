#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

// typedef int RUB;  // C
using RUB = long long int;  // C++
using BUB = long double;


struct Expenses {
    string name;
    RUB value;
    string date;
};

struct Income {
    string name;
    RUB value;
    string date;
};

struct Wallet {
    Income income;
    Expenses expenses;
    BUB balance;
};

struct Car {
    RUB value;
};

struct Person {
    RUB capital;
    Wallet wallet;
    Car car;
    RUB house_value;
};
struct Person alice;

void alice_init()
{
    alice.capital = 0;
    alice.wallet.balance = 180'000;

    alice.car.value = 15'400'000;
    alice.house_value = 40'000'000;
}

void expenses_init(string name, RUB value, string date)
{
    alice.wallet.expenses.name = name;
    alice.wallet.expenses.value = value;
    alice.wallet.expenses.date = date;
    cout << "Expense added: " << alice.wallet.expenses.name << ", " << alice.wallet.expenses.value << ", " << alice.wallet.expenses.date << endl;
}

void income_init(string name, RUB value, string date)
{
    alice.wallet.income.name = name;
    alice.wallet.income.value = value;
    alice.wallet.income.date = date;
    cout << "Income added: " << alice.wallet.income.name << ", " << alice.wallet.income.value << ", " << alice.wallet.income.date << endl;
}

void balance_init()
{
    alice.wallet.balance = alice.wallet.income.value - alice.wallet.expenses.value;
    cout << "Balance updated: " << alice.wallet.balance << endl;
}

void mains(int sizexp)
{
    int *exp = new int[sizexp];
}
// float sberbank_interest(RUB sum)   // Сделать sum 
// {
//     if (sum > 10'000 and sum < 3'000'000) {
//         return 11.5;
//     }

//     if (sum >= 3'000'000) {
//         return 12.5;  //  125 -1 +
//     }

//     return 0.1;
// }



// void alice_bank_interest()
// {
//     float pp;
//     pp = sberbank_interest(alice.capital);
//     alice.capital += alice.capital * (pp / 12.0 / 100.0);
// }


// void alice_simulation()
// {
//     int year = 2026;
//     int month = 2;

//     while ( not (year == 2027 and month == 2) ) {
//         // my_cat();
//         // my_trip();
//         alice_food();
//         alice_car();
//         alice_bank_interest();
//         alice_salary(year, month);

//         ++month;
//         if (month == 13) {
//             ++year;
//             month = 1;
//         }
//     }
// }


int main()
{
    int sizexp = 0;
    cout << "Capital: " << alice.wallet.balance + alice.car.value + alice.house_value << endl;

    while (true)
    {
        string operations;
        cout << "Enter operations (Add_expense, Add_income, Check_balance): ";
        cin >> operations;

        if (operations == "Add_expense") {
            string name_expense;
            cout << "Name of expense: ";
            cin >> name_expense;

            RUB value_expense;
            cout << "Value of expense: ";
            cin >> value_expense;

            string date_expense;
            cout << "Date of expense: ";
            cin >> date_expense;
            sizexp++;
            mains(sizexp);

            expenses_init(name_expense, value_expense, date_expense);
            cout << "Expense added! ";

        }
        else if (operations == "Add_income") {
            string name_income;
            cout << "Name of income: ";
            cin >> name_income;

            RUB value_income;
            cout << "Value of income: ";
            cin >> value_income;

            string date_income;
            cout << "Date of income: ";
            cin >> date_income;

            income_init(name_income, value_income, date_income);
            cout << "Income added! ";
        }
        else if (operations == "Check_balance") {
            balance_init();
        }
        else {
            cout << "Invalid operation!" << endl;
        }
    }

}



//bool create_csv_if_not_exists(const std::string& filename) {
 //    ifstream check(filename);
 //    if (check.good()) {
 //        check.close();
 //        return false; // файл уже есть
 //    }

 //    ofstream file(filename);
 //    if (!file.is_open()) {
 //        throw std::runtime_error("не удалось создать файл: " + filename);
 //    }

 //     //заголовок csv (по желанию)
 //    file << "name,value,date\n";
 //    return true; // файл создан
 //}
 //void create_csv(const string& namef, const string& data)
 //{
 //    if (namef.empty()) return;

 //    ofstream file(namef, ios::app); // append, чтобы не затирать файл
 //    if (file.is_open()) {
 //        file << data;
 //    }
 //}
// Узнать, как сделать файл для хранения данных, и как его использовать для сохранения данных о доходах и расходах.