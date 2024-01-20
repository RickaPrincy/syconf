#ifndef __SYCONF_RELOAD__
#define __SYCONF_RELOAD__

#include <string>
#include <vector>
#include "config.hpp"

void reload(const Config &config);
void status();
void stash();

#endif	// __SYCONF_RELOAD__
