#ifndef CLA__H
#define CLA__H

#include "types.h"

#define NO_ARGS_ENTERED 1
#define NORMAL_AMOUNT_ARGS 11

status_t validate_arguments(int argc, char *argv[]);

static char *available_flags[] = { "-fmt", "-out", "-in", "-ti", "-tf" };

#endif
