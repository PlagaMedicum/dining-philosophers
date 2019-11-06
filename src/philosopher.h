#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <string>
#include "stick.h"

class Philosopher
{
private:
    std::string name;
    int think_t;
    int eat_t;
    Stick *l_stick, *r_stick;
public:
    Philosopher(std::string name, int think_t, int eat_t)
        : name(name),
        think_t(think_t),
        eat_t(eat_t)
    {}
    void start();
    void set_l_stick(Stick* l_stick);
    void set_r_stick(Stick* r_stick);
    //void take_stick();
    //void put_stick();
};

#endif

