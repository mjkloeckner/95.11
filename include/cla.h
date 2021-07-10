#ifndef CLA__H
#define CLA__H

#include <string.h>
#include <stdbool.h>

#include "types.h"

#define NO_ARGS_ENTERED 1
#define NORMAL_AMOUNT_ARGS 11
#define FLAGS_MAX 5
#define FORMATS_MAX 2

status_t validate_arguments(int argc, char **argv);
status_t check_flags_position(int argc, char **argv);
status_t check_flags_repeated(int argc, char **argv);

status_t get_flags_values(int argc, char **argv);

extern const char *available_flags[FLAGS_MAX];
extern const char *available_formats[FORMATS_MAX];

#endif
