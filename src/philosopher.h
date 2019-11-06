#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <string>
#include "stick.h"

class Philosopher
{
private:
    std::string name;
    int thinking_t;
    int eating_t;
    Stick l_stick, r_stick;
public:
    Philosopher(std::string name, int thinking_t, int eating_t)
        : name(name),
        thinking_t(thinking_t),
        eating_t(eating_t)
    {}
    void start();
    void take_stick();
    void put_stick();
};

#endif

