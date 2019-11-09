#include <iostream>
#include "src/dining_philosophers.h"

int main(int argc, char** argv)
{
    std::cout << "\e[1;32mAdding philosophers...\e[0m\n";

    add_phil("Plato", 1, 3);
    add_phil("Kant", 2, 2);
    add_phil("Nietzsche", 3, 1);

    std::cout << "\e[1;32mPhilosophers added. Starting dinner...\e[0m\n";

    start_dinner(20);

    return 0;
}

