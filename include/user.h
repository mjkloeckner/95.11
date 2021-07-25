#ifndef USER__H
#define USER__H

#include "status.h"

typedef struct {
	size_t id;
	long credit, debt;
} ADT_user_t, *user_t;

user_t user_find(const user_t *users, int id, size_t size);
user_t user_dup(user_t src);

status_t user_create(user_t *usr);
status_t user_set_data(user_t *user, char **data);

void user_clean(user_t usr);

status_t sort_users(user_t *users, size_t size, char *order);
status_t destroy_users(user_t *users, size_t size);

#endif
