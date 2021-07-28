#ifndef CLA__H
#define CLA__H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "status.h"

#define NO_ARGS_ENTERED 1
#define NORMAL_AMOUNT_ARGS 11
#define FLAGS_MAX 5
#define FORMATS_MAX 2

typedef enum {
	FLAG_FMT,
	FLAG_OUT,
	FLAG_IN,
	FLAG_TI,
	FLAG_TF
} flags_t;

typedef struct {
	char *fmt, *fi, *fo;
	unsigned long ti, tf;
} ADT_cla_t, *cla_t;

status_t validate_arguments(int argc, char **argv);
status_t check_flags_position(int argc, char **argv);
status_t check_flags_repeated(int argc, char **argv);

status_t cla_create(cla_t *cla);
status_t cla_setup(int argc, char **argv, cla_t *cla);
status_t cla_destroy(cla_t *cla);

extern const char *available_flags[FLAGS_MAX];
extern const char *available_formats[FORMATS_MAX];

#endif
