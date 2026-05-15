#include "person.hpp"
#include "simulation.hpp"

int main() {
    Person alice;
    person_init(alice);

    run_simulation(alice);

    print_results(alice);

    return 0;
}