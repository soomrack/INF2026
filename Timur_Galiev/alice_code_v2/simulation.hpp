#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "person.hpp"

void run_simulation(Person& p);
void simulation_step(Person& p, int month, int year);
RUB calculate_total_capital(const Person& p);
RUB calculate_total_expenses(const Person& p);
void print_results(const Person& p);

#endif