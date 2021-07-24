#ifndef USER__H
#define USER__H

#include "status.h"
#include "io.h"

status_t destroy_users(user_t *users, size_t size);

status_t user_create(user_t *usr);
status_t user_set_data(user_t *user, char **data);

user_t user_find(const user_t *users, int id, size_t size);
user_t user_dup(user_t src);


void user_clean(user_t usr);

#endif
