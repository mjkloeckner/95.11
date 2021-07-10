#ifndef IO__H
#define IO__H

#include <stdio.h>
#include <stdlib.h>

#include "types.h"


status_t output_gen(cla_t cla);
status_t get_data(char *buf, user_t *user);

#endif
