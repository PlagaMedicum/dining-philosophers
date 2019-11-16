#include "philosopher.h"
#include <iostream>
#include <ctime>
#include <mutex>
#include <unistd.h>

static std::mutex log_mtx;

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

void Philosopher::think()
{
    log_mtx.lock();
    std::cout << name << " is now \e[1;35mTHINKING\e[0m.\n";
    log_mtx.unlock();

    usleep(think_t*1000);
}

void Philosopher::eat()
{
    log_mtx.lock();
    std::cout << name << " is now \e[1;36mEATING\e[0m.\n";
    log_mtx.unlock();

    usleep(eat_t*1000);
}

std::string Philosopher::get_name()
{
    return name;
}

void Philosopher::occupy_sticks()
{
    log_mtx.lock();
    std::cout << name << " tries to take sticks.\n";
    log_mtx.unlock();

    std::clock_t start_t;
    start_t = std::clock()*1000;

    while(true)
    {
        if(l_stick->try_lock())
        {
            if(!r_stick->try_lock())
            {
                l_stick->unlock();
                continue;
            }

            log_mtx.lock();
            std::cout << name << " was \e[1;31mHUNGRY\e[0m for \e[1;31m" << (std::clock()*1000. - start_t)/CLOCKS_PER_SEC << "ms\e[0m.\n";
            log_mtx.unlock();

            return;
        }
    }

}

void Philosopher::release_sticks()
{
    log_mtx.lock();
    std::cout << name << " putting down his sticks.\n";
    log_mtx.unlock();

    l_stick->unlock();
    r_stick->unlock();
}

