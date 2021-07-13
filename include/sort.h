#ifndef SORT__H
#define SORT__H

#include "types.h"

#include <stdio.h>
#include <stdlib.h>

int minmax(const void *, const void *);
int maxmix(const void *, const void *);

status_t sort_tmp_file(FILE *, char *);

#endif
