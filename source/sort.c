#include "../include/sort.h"

int minmax(const void *a, const void *b)
{
	int *A = (int *)a;
	int *B = (int *)b;

	return (*A > *B) ? *A : (*A - *B);
}

int maxmix(const void *a, const void *b)
{
	int *A = (int *)a;
	int *B = (int *)b;

	return (*A > *B) ? *A : (*A - *B);
}

status_t sort_tmp_file(FILE *bfp, char *sort_order)
{
	if(bfp == NULL || sort_order == NULL)
		return ERROR_NULL_POINTER;

	/* qsort(bfp, sizeof); */

	return OK;
}
