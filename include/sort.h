#ifndef SORT__H
#define SORT__H

#include "cla.h"
#include "types.h"

#include <stdio.h>
#include <stdlib.h>

int minmax(const void *, const void *);
int maxmix(const void *, const void *);

status_t tmp_file_sort(FILE *tmp, size_t len, char order);

#endif
