#include "../include/user.h"

status_t user_create(ADT_user_t **user)
{
	if((*user = (ADT_user_t *)malloc(sizeof(ADT_user_t))) == NULL)
		return ERROR_MEMORY;

	(*user)->id = 0;
	(*user)->c = 0;
	(*user)->d = 0;

	return OK;
}

void user_clean(user_t usr)
{
	usr->id = 0;
	usr->c = 0;
	usr->d = 0;
}

status_t user_set_data(ADT_user_t *user, char **data) 
{
	char *endptr;
	long amount;

	if(data == NULL || user == NULL) return ERROR_NULL_POINTER;

	user->id = strtol(data[POS_USER_ID], &endptr, 10);
	if(*endptr != '\0') return ERROR_CORRUPT_DATA;

	amount = strtol(data[POS_AMOUNT], &endptr, 10);
	if(*endptr != '\0') return ERROR_CORRUPT_DATA;

	if(amount > 0) user->c = amount;
	else if(amount < 0) user->d = -amount; /* '-=' Para eliminar el menos	*/

	return OK;
}

status_t user_add_amount(ADT_user_t *user, long amount)
{
	if(user == NULL) return ERROR_NULL_POINTER;

	if(amount > 0) user->c += amount;
	else if(amount < 0) user->d -= amount; /* '-=' Para eliminar el menos	*/

	return OK;
}

ADT_user_t *user_dup(user_t src)
{
	ADT_user_t *dst = NULL;

	user_create(&dst);

	dst->id = src->id;
	dst->c = src->c;
	dst->d = src->d;

	return dst;
}

user_t user_find(const user_t *users, int id, size_t size)
{
	size_t i;
	for(i = 0; i < size; i++) {
		if(users[i]->id == id) {
			return users[i];
		}
	}
	return NULL;
}

status_t destroy_users(user_t *users, size_t size)
{
	size_t i;

	if(users == NULL) return ERROR_NULL_POINTER;

	for(i = 0; i < size; i++)
		free(users[i]);

	free(users);
	return OK;
}

status_t user_printer(const void *u, FILE *fp)
{
	if(u == NULL || fp == NULL) return ERROR_NULL_POINTER;

	ADT_user_t *user = (ADT_user_t *)u;

	fprintf(fp, "id: %6ld| credits: %6ld| debits: %6ld\n", user->id, user->c, user->d);

	return OK;
}

int user_id_equal(const void *a, const void *b)
{
	ADT_user_t *A, *B;

	if(a == NULL || b == NULL) return ERROR_NULL_POINTER;

	A = (ADT_user_t *)a;
	B = (ADT_user_t *)b;

	if(A->id == B->id) return 1;

	return 0;
}

int user_comparator_credits_minmax(const void *a, const void *b)
{
	user_t A, B;

	if(a == NULL || b == NULL) return ERROR_NULL_POINTER;

	A = *(user_t *)a;
	B = *(user_t *)b;

	if(A->c > B->c) return 1;
	else if(A->c == B->c) return 0;
	return -1;
}  

int user_comparator_credits_maxmin(const void *a, const void *b)
{
	user_t A, B;

	if(a == NULL || b == NULL) return ERROR_NULL_POINTER;

	A = *(user_t *)a;
	B = *(user_t *)b;

	if(A->c < B->c) return 1;
	else if(A->c == B->c) return 0;
	return -1;
}  
