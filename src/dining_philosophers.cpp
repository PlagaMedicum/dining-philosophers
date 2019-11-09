#include "dining_philosophers.h"
#include <thread>
#include <iostream>
#include <unistd.h>

void add_phil(const std::string& name, int think_t, int eat_t)
{
    std::cout << "\e[1;32mAdding " << name << "\e[0m\n";;
    phils.emplace_back(name, think_t, eat_t);

    if(phils.size() == 1)
    {
        phils[0].set_l_stick(new Stick);
        phils[0].set_r_stick(new Stick);

        return;
    }

    std::vector<Philosopher>::iterator phil = phils.end();

    (phil - 1)->set_l_stick((phil - 2)->get_l_stick());
    (phil - 1)->set_r_stick(new Stick);
}

void start_phil(size_t i)
{
    while(1)
    {
        phils[i].think();
        phils[i].occupy_sticks();
        phils[i].eat();
        phils[i].release_sticks();
    }
}

void start_dinner(size_t time_ms)
{
    std::vector<std::thread> p_threads;
    for(size_t i = 0; i < phils.size(); i++)
    {
        p_threads.push_back(std::thread(start_phil, i));
    }

    std::thread timer(usleep, time_ms*1000);
    timer.join();

    for(std::thread & th : p_threads)
    {
        th.detach();
    }

    std::cout << "\e[1;32mDinner finished\e[0m\n";
}

