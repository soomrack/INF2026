#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "person.hpp"

void run_simulation(Person& p);
void simulation_step(Person& p, int month, int year);
RUB calculate_total_capital(const Person& p);
float calculate_cumulative_inflation(const Person& p);
RUB calculate_real_capital(const Person& p, float cumulative_inflation);
void print_results(const Person& p);

#endif