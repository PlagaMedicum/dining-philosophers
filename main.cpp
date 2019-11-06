#include "src/dining_philosophers.h"

int main(int argc, char** argv)
{
    Philosopher("Plato", 1, 3);
    Philosopher("Kant", 2, 2);
    Philosopher("Nietzsche", 3, 1);

    start_dinner();
}

