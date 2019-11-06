#include "src/dining_philosophers.h"

int main(int argc, char** argv)
{
    add_phil("Plato", 1, 3);
    add_phil("Kant", 2, 2);
    add_phil("Nietzsche", 3, 1);

    start_dinner();

    return 0;
}

