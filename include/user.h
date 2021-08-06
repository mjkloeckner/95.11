#ifndef USER__H
#define USER__H

#include "status.h"
#include "utils.h"

#define OUT_FILE_DELIM	","

typedef unsigned long ulong;

typedef struct {
	/* id: user id / c: user credits / d: user debits */
	ulong id, c, d;
} ADT_user_t;

status_t user_create(ADT_user_t **);
status_t user_dup(ADT_user_t *, ADT_user_t *);
status_t user_destroy(ADT_user_t **);

status_t user_set_data(ADT_user_t *, ulong, ulong, ulong);

status_t user_add_amount(ADT_user_t *, long);

int user_equals(const void *, const void *);

status_t user_print_as_csv(const void *, FILE *);
status_t user_print_as_xml(const void *, FILE *);

int user_comparator_credits_minmax(const void *, const void *);
int user_comparator_credits_maxmin(const void *, const void *);


#endif
