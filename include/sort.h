#ifndef SORT__H
#define SORT__H

#include "cla.h"
#include "status.h"

#include <stdio.h>
#include <stdlib.h>

int credit_minmax(const void *, const void *);
int credit_maxmix(const void *, const void *);

int debt_minmax(const void *, const void *);
int debt_maxmin(const void *, const void *);

status_t sort_users(user_t *users, size_t size, char *order);

#endif
