#include "../include/user.h"

status_t user_create(user_t *usr)
{
	if(((*usr) = (user_t)malloc(sizeof(ADT_user_t))) == NULL)
		return ERROR_MEMORY;

	(*usr)->id = 0;
	(*usr)->credit = 0;
	(*usr)->debt = 0;

	return OK;
}

void user_clean(user_t usr)
{
	usr->id = 0;
	usr->credit = 0;
	usr->debt = 0;
}

status_t user_set_data(user_t *user, char **data) 
{
	if(data == NULL || user == NULL) return ERROR_NULL_POINTER;

	char *endptr;
	long amount;

	(*user)->id = strtol(data[POS_USER_ID], &endptr, 10);
	if(*endptr != '\0') return ERROR_CORRUPT_DATA;

	amount = strtol(data[POS_AMOUNT], &endptr, 10);
	if(*endptr != '\0') return ERROR_CORRUPT_DATA;

	if(amount > 0) (*user)->credit = amount;
	else if(amount < 0) (*user)->debt = -amount; /* '-=' Para eliminar el menos	*/

	return OK;
}

user_t user_dup(user_t src)
{
	user_t dst = NULL;

	user_create(&dst);

	dst->id = src->id;
	dst->credit = src->credit;
	dst->debt = src->debt;

	return dst;
}

user_t user_find(const user_t *users, int id, size_t size)
{
	for(size_t i = 0; i < size; i++) {
		if(users[i]->id == id) {
			return users[i];
		}
	}
	return NULL;
}

status_t destroy_users(user_t *users, size_t size)
{
	if(users == NULL) return ERROR_NULL_POINTER;

	for(size_t i = 0; i < size; i++)
		free(users[i]);

	free(users);
	return OK;
}
