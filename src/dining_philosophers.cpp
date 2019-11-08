#include "dining_philosophers.h"
#include <thread>
#include <iostream>
#include <unistd.h>

void add_phil(const std::string& name, int think_t, int eat_t)
{
    phils.emplace_back(name, think_t, eat_t);

    if(phils.size() == 1)
    {
        phils[0].set_l_stick(new Stick);
        phils[0].set_r_stick(new Stick);

        return;
    }

    phils[-1].set_l_stick(phils[-2].get_l_stick());
    phils[-1].set_r_stick(new Stick);
}

bool is_diner = true;

void diner_timer(size_t d_time)
{
    usleep(d_time);
    is_diner = false;
}

void start_phil(size_t i)
{
    while(is_diner)
    {
        std::cout << phils[i].get_name() << " is now thinking.";
        usleep(phils[i].get_think_t()*1000);

        std::cout << phils[i].get_name() << " tries to take sticks.";
        phils[i].occupy_sticks();

        std::cout << phils[i].get_name() << " is now eating.";
        usleep(phils[i].get_eat_t()*1000);

        std::cout << phils[i].get_name() << " putting down his sticks.";
        phils[i].release_sticks();
    }
}

void start_dinner(size_t time_ms)
{
//    std::vector<std::thread*> p_threads;
//    for(size_t i = 0; i < phils.size(); i++)
//    {
//        p_threads.push_back(new std::thread(start_phil, i));
//    }

//    std::thread timer(diner_timer, time_ms*1000);
//    timer.join();
//    for(auto & p_thread : p_threads)
//    {
//        p_thread->join();
//    }

    std::cout << "Dinner finished";
}

