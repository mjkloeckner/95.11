#include "../include/user.h"

status_t user_create(user_t **user)
{
	if((*user = (user_t *)malloc(sizeof(user_t))) == NULL)
		return ERROR_MEMORY;

	(*user)->id = 0;
	(*user)->c = 0;
	(*user)->d = 0;

	return OK;
}

status_t user_destroy(user_t **user)
{
	if(user == NULL) return ERROR_NULL_POINTER;

	free(*user);
	*user = NULL;

	return OK;
}

status_t user_set_data(user_t *user, ulong id, ulong c, ulong d) 
{
	if(user == NULL) return ERROR_NULL_POINTER;

	user->id = id;
	user->c = c;
	user->d = d;

	return OK;
}

int user_equals(const void *a, const void *b)
{
	user_t *A, *B;

	if(a == NULL || b == NULL) return ERROR_NULL_POINTER;

	A = (user_t *)a;
	B = (user_t *)b;

	if(A->id == B->id) return 1;

	return 0;
}

status_t user_print_as_csv(const void *u, FILE *fp)
{
	if(u == NULL || fp == NULL) return ERROR_NULL_POINTER;

	user_t *user = (user_t *)u;

	fprintf(fp, "%ld%s%ld%s%ld\n", user->id, CSV_OUT_FILE_DELIM, user->c, CSV_OUT_FILE_DELIM, user->d);

	return OK;
}

status_t user_print_as_xml(const void *u, FILE *fp)
{
	if(u == NULL || fp == NULL) return ERROR_NULL_POINTER;

	user_t *user = (user_t *)u;

	fprintf(fp, "\t\t<%s>%ld</%s>\n", XML_STR_ID, user->id, XML_STR_ID);
	fprintf(fp, "\t\t<%s>%ld</%s>\n", XML_STR_CREDIT, user->c, XML_STR_CREDIT);
	fprintf(fp, "\t\t<%s>%ld</%s>\n", XML_STR_DEBIT, user->d, XML_STR_DEBIT);

	return OK;
}

int user_comparator_credits_minmax(const void *a, const void *b)
{
	user_t *A, *B;

	if(a == NULL || b == NULL) return ERROR_NULL_POINTER;

	A = *(user_t **)a;
	B = *(user_t **)b;

	if(A->c > B->c) return 1;
	else if(A->c == B->c) return 0;
	return -1;
}  

int user_comparator_credits_maxmin(const void *a, const void *b)
{
	user_t *A, *B;

	if(a == NULL || b == NULL) return ERROR_NULL_POINTER;

	A = *(user_t **)a;
	B = *(user_t **)b;

	if(A->c < B->c) return 1;
	else if(A->c == B->c) return 0;
	return -1;
}  
