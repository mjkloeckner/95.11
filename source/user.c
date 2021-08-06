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

status_t user_dup(ADT_user_t *src, ADT_user_t *dst)
{
	status_t st;

	if(src == NULL || dst == NULL) return ERROR_NULL_POINTER;

	if((st = user_create(&dst)) != OK)
		return st;

	dst->id = src->id;
	dst->c = src->c;
	dst->d = src->d;

	return OK;
}

status_t user_destroy(ADT_user_t **user)
{
	if(user == NULL) return ERROR_NULL_POINTER;

	free(*user);
	*user = NULL;

	return OK;
}

status_t user_set_data(ADT_user_t *user, ulong id, ulong c, ulong d) 
{
	if(user == NULL) return ERROR_NULL_POINTER;

	user->id = id;
	user->c = c;
	user->d = d;

	return OK;
}

status_t user_add_amount(ADT_user_t *user, long amount)
{
	if(user == NULL) return ERROR_NULL_POINTER;

	if(amount > 0) user->c += amount;
	else if(amount < 0) user->d -= amount; /* '-=' Para eliminar el menos	*/

	return OK;
}

int user_equals(const void *a, const void *b)
{
	ADT_user_t *A, *B;

	if(a == NULL || b == NULL) return ERROR_NULL_POINTER;

	A = (ADT_user_t *)a;
	B = (ADT_user_t *)b;

	if(A->id == B->id) return 1;

	return 0;
}

status_t user_print_as_csv(const void *u, FILE *fp)
{
	if(u == NULL || fp == NULL) return ERROR_NULL_POINTER;

	ADT_user_t *user = (ADT_user_t *)u;

	fprintf(fp, "%ld%s%ld%s%ld\n", user->id, OUT_FILE_DELIM, user->c, OUT_FILE_DELIM, user->d);

	return OK;
}

status_t user_print_as_xml(const void *u, FILE *fp)
{
	if(u == NULL || fp == NULL) return ERROR_NULL_POINTER;

	ADT_user_t *user = (ADT_user_t *)u;

	fprintf(fp, "\t\t<%s>%ld</%s>\n", XML_STR_ID, user->id, XML_STR_ID);
	fprintf(fp, "\t\t<%s>%ld</%s>\n", XML_STR_CREDIT, user->c, XML_STR_CREDIT);
	fprintf(fp, "\t\t<%s>%ld</%s>\n", XML_STR_DEBIT, user->d, XML_STR_DEBIT);

	return OK;
}

int user_comparator_credits_minmax(const void *a, const void *b)
{
	ADT_user_t *A, *B;

	if(a == NULL || b == NULL) return ERROR_NULL_POINTER;

	A = *(ADT_user_t **)a;
	B = *(ADT_user_t **)b;

	if(A->c > B->c) return 1;
	else if(A->c == B->c) return 0;
	return -1;
}  

int user_comparator_credits_maxmin(const void *a, const void *b)
{
	ADT_user_t *A, *B;

	if(a == NULL || b == NULL) return ERROR_NULL_POINTER;

	A = *(ADT_user_t **)a;
	B = *(ADT_user_t **)b;

	if(A->c < B->c) return 1;
	else if(A->c == B->c) return 0;
	return -1;
}  
