#ifndef USER__H
#define USER__H

#include "status.h"

typedef unsigned long ulong;

typedef struct {
	/* id: user id / c: user credits / d: user debits */
	ulong id, c, d;
} ADT_user_t, *user_t;

user_t user_find(const user_t *users, int id, size_t size);
user_t user_dup(user_t src);

status_t user_create(ADT_user_t **);
status_t user_set_data(ADT_user_t *, char **data);
status_t user_add_amount(ADT_user_t *, long amount);

int user_id_equal(const void *, const void *);

void user_clean(user_t usr);

status_t sort_users(user_t *users, size_t size, char *order);
status_t destroy_users(user_t *users, size_t size);

status_t user_printer(const void *, FILE *);

int user_comparator(const void *, FILE *);

int user_comparator_credits_minmax(const void *, const void *);
int user_comparator_credits_maxmin(const void *, const void *);


#endif
