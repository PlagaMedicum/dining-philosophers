#include "philosopher.h"
#include <iostream>

void Philosopher::set_l_stick(Stick* l_stick)
{
    this->l_stick = l_stick;
}

void Philosopher::set_r_stick(Stick* r_stick)
{
    this->r_stick = r_stick;
}

Stick* Philosopher::get_l_stick()
{
    return l_stick;
}

size_t Philosopher::get_think_t()
{
    return think_t;
}

size_t Philosopher::get_eat_t()
{
    return eat_t;
}

std::string Philosopher::get_name()
{
    return name;
}

void Philosopher::occupy_sticks()
{
    while(true)
    {
        if(l_stick->try_lock())
        {
            if(!r_stick->try_lock())
            {
                l_stick->unlock();
                std::cout << name << " can't take a stick.";
                continue;
            }

            return;
        }

        std::cout << name << " can't take a stick.";
    }

}

void Philosopher::release_sticks()
{
    l_stick->unlock();
    r_stick->unlock();
}

