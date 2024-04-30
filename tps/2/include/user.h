#ifndef USER__H
#define USER__H

#include "status.h"
#include "utils.h"

#define CSV_OUT_FILE_DELIM	","

typedef unsigned long ulong;

typedef struct {
	/* id: user id / c: user credits / d: user debits */
	ulong id, c, d;
} user_t;

status_t user_create(user_t **);
status_t user_set_data(user_t *, ulong, ulong, ulong);
status_t user_destroy(user_t **);

int user_equals(const void *, const void *);

status_t user_print_as_csv(const void *, FILE *);
status_t user_print_as_xml(const void *, FILE *);

int user_comparator_credits_minmax(const void *, const void *);
int user_comparator_credits_maxmin(const void *, const void *);


#endif
