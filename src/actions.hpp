#ifndef __SYCONF_ACTIONS__
#define __SYCONF_ACTIONS__

#include <string>
#include <vector>
#include "config.hpp"

void reload(const Config &config);
void status();
void stash();
void push();
void commit();

#endif	// __SYCONF_ACTIONS__
