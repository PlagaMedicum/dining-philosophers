#ifndef STICK_H
#define STICK_H

#include <mutex>

class Stick
{
public:
    void unlock();
    bool try_lock();
private:
    std::mutex m;
};

#endif

