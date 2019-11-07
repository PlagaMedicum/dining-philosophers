#include "stick.h"

void Stick::lock()
{
    m.lock();
}

void Stick::unlock()
{
    m.unlock();
}

bool Stick::try_lock()
{
    return m.try_lock();
}

