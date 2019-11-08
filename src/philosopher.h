#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <string>
#include <utility>
#include <stdlib.h>
#include "stick.h"

class Philosopher
{
private:
    std::string name;
    size_t think_t; // thinking time in milliseconds
    size_t eat_t;   // eating time in milliseconds
    Stick *l_stick{}, *r_stick{};
public:
    Philosopher(std::string name, size_t think_t, size_t eat_t)
        : name(std::move(name)),
        think_t(think_t),
        eat_t(eat_t)
    {}

    void set_l_stick(Stick* l_stick);
    void set_r_stick(Stick* r_stick);

    Stick* get_l_stick();
    size_t get_think_t();
    size_t get_eat_t();
    std::string get_name();

    void occupy_sticks();
    void release_sticks();
};

#endif

