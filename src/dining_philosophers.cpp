#include "dining_philosophers.h"

void add_phil(std::string name, int think_t, int eat_t)
{
    phils.push_back(Philosopher(name, think_t, eat_t));

    if(phils.size() == 1)
    {
        phils[0].set_l_stick(new Stick);
        phils[0].set_r_stick(new Stick);

        return;
    }

    
}

void start_dinner()
{

}

