#include "person.hpp"
#include "simulation.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Person alice;
    Person bob;

    person_init(alice, "Alice", STRATEGY_CONSERVATIVE);
    person_init(bob, "Bob", STRATEGY_AGGRESSIVE);

    run_simulation(alice);
    run_simulation(bob);

    printf("\n\n");
    printf("========================================\n");
    printf("          FINAL RESULTS\n");
    printf("========================================\n");

    print_results(alice);
    print_results(bob);

    // Сравнение
    RUB alice_capital = calculate_total_capital(alice);
    RUB bob_capital = calculate_total_capital(bob);

    printf("========================================\n");
    printf("          COMPARISON\n");
    printf("========================================\n");

    if (alice_capital > bob_capital) {
        RUB diff = alice_capital - bob_capital;
        float percent = (float)diff / bob_capital * 100;
        printf("  ALICE wins! +%lld RUB (%.1f%% more than Bob)\n", diff, percent);
    }
    else if (bob_capital > alice_capital) {
        RUB diff = bob_capital - alice_capital;
        float percent = (float)diff / alice_capital * 100;
        printf("  BOB wins! +%lld RUB (%.1f%% more than Alice)\n", diff, percent);
    }
    else {
        printf("  It's a tie!\n");
    }

    printf("\n");
    printf("  Alice strategy: Conservative (mortgage, all subscriptions, 20k/month invest)\n");
    printf("  Bob strategy:   Aggressive (no mortgage, only Yandex, 35k/month invest, 25%% ROI)\n");
    printf("========================================\n");

    return 0;
}