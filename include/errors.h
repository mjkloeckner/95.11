#ifndef ERRROS__H
#define ERRORS__H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "types.h"

void show_status(status_t st);

void free_arrays(size_t num,...);

extern const char *status_strings[STATUS_T_MAX];

#endif
