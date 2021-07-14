#include "../include/sort.h"

int minmax(const void *a, const void *b)
{
	int *A = (int *)a;
	int *B = (int *)b;

	return (*A > *B) ? *A : (*A - *B);
}

int maxmin(const void *a, const void *b)
{
	int *A = (int *)a;
	int *B = (int *)b;

	return (*A > *B) ? *A : (*A - *B);
}

status_t tmp_file_sort(FILE *tmp, size_t len, char order)
{
	if(tmp == NULL) return ERROR_NULL_POINTER;

	switch (order)
	{
		case 'a': qsort(tmp, len, sizeof(ADT_cla_t), minmax); break;
		case 'd': qsort(tmp, len, sizeof(ADT_cla_t), maxmin); break;
	}

	return OK;
}
