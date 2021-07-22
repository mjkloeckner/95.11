#include "../include/sort.h"

int credit_minmax(const void *a, const void *b)
{
	user_t *A = (user_t *)a;
	user_t *B = (user_t *)b;

	return ((*A)->credit > (*B)->credit) ? 1 : 0;
}

int credit_maxmin(const void *a, const void *b)
{
	user_t *A = (user_t *)a;
	user_t *B = (user_t *)b;

	return ((*A)->credit > (*B)->credit) ? 0 : 1;
}

int debt_minmax(const void *a, const void *b)
{
	user_t *A = (user_t *)a;
	user_t *B = (user_t *)b;

	return ((*A)->debt > (*B)->debt) ? 1 : 0;
}

int debt_maxmin(const void *a, const void *b)
{
	user_t *A = (user_t *)a;
	user_t *B = (user_t *)b;

	return ((*A)->debt > (*B)->debt) ? 0 : 1;
}

status_t sort_users(user_t *users, size_t l, char *order)
{
	if(users == NULL || order == NULL)
		return ERROR_NULL_POINTER;

	if(!strcmp(order, "ca"))
		qsort(users, l, sizeof(user_t), credit_minmax);

	if(!strcmp(order, "cd"))
		qsort(users, l, sizeof(user_t), credit_maxmin);

	if(!strcmp(order, "da"))
		qsort(users, l, sizeof(user_t), debt_minmax);

	if(!strcmp(order, "dd"))
		qsort(users, l, sizeof(user_t), debt_maxmin);

	return OK;
}
