#include "inflation.hpp"

void apply_inflation_to_person(Person& p) {
    float monthly_rate = 1.0f + (p.vtb.inflation / 12.0f / 100.0f);

    p.food = static_cast<RUB>(p.food * monthly_rate);
    p.dog = static_cast<RUB>(p.dog * monthly_rate);
    p.medicine = static_cast<RUB>(p.medicine * monthly_rate);
    p.home = static_cast<RUB>(p.home * monthly_rate);
    p.car.gas = static_cast<RUB>(p.car.gas * monthly_rate);

    p.netflix_sub = static_cast<RUB>(p.netflix_sub * monthly_rate);
    p.yandex_plus_sub = static_cast<RUB>(p.yandex_plus_sub * monthly_rate);
    p.game_pass_sub = static_cast<RUB>(p.game_pass_sub * monthly_rate);
}