#ifndef DINING_PHILOSOPHERS_H
#define DINING_PHILOSOPHERS_H

#include <vector>
#include <string>
#include <stdlib.h>
#include "philosopher.h"

static std::vector<Philosopher> phils;

// add_phil adds a philosopher in vector 'phils'.
void add_phil(const std::string& name, int think_t, int eat_t);

// strt_dinner starts threads of dining philosophers.
void start_dinner(size_t time_ms);

#endif

