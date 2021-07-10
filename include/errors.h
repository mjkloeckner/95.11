#ifndef ERRROS__H
#define ERRORS__H

#include <stdio.h>

#include "types.h"

void show_status(status_t st);

extern const char *status_strings[STATUS_T_MAX];

#endif
