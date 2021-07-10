#ifndef CLA__H
#define CLA__H

#include <stdbool.h>
#include <string.h>

#include "types.h"

#define NO_ARGS_ENTERED 1
#define NORMAL_AMOUNT_ARGS 11
#define FLAGS_MAX 5

status_t validate_arguments(int argc, char **argv);
status_t check_flags_position(int argc, char **argv);
status_t check_flags_repeated(int argc, char **argv);

static const char *available_flags[FLAGS_MAX + 1] = { "-fmt", "-out", "-in", "-ti", "-tf" };

#endif
