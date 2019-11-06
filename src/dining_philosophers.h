#ifndef DINING_PHILOSOPHERS_H
#define DINING_PHILOSOPHERS_H

#include <vector>
#include <string>
#include "philosopher.h"

std::vector<Philosopher> phils;

void add_phil(std::string name, int think_t, int eat_t);

void start_dinner();

#endif

