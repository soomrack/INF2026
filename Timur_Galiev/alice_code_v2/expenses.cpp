#include "expenses.hpp"

void apply_all_expenses(Person& p) {
    RUB monthly_expenses = 0;  // НОВАЯ переменная для подсчёта за месяц

    monthly_expenses += p.food;
    monthly_expenses += p.car.gas;
    monthly_expenses += p.dog;
    monthly_expenses += p.medicine;
    monthly_expenses += p.home;

    p.vtb.account -= monthly_expenses;

    // НОВОЕ: добавляем расходы в общую копилку
    p.total_expenses += monthly_expenses;

}
void apply_subscriptions(Person& p) {
    RUB monthly_sub_expenses = 0;

    monthly_sub_expenses += p.gamepass_sub;
    monthly_sub_expenses += p.netflix_sub;
    monthly_sub_expenses += p.netflix_sub;

    p.vtb.account -= monthly_sub_expenses;
    p.total_sub_expenses += monthly_sub_expenses;
}