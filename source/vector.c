#include "vector.h"

void swap(void *a, void *b)
{
	int *A = (int *)a;
	int *B = (int *)b;

	int tmp = *A;
	*A = *B;
	*B = tmp;
}

status_t ADT_Vector_create(ADT_Vector_t **v)
{
	if(v == NULL) return ERROR_NULL_POINTER;

	if((*v = (ADT_Vector_t *)malloc(sizeof(ADT_Vector_t))) == NULL)
		return ERROR_MEMORY;

	if(((*v)->a = (void **)malloc(sizeof(void *) * VECTOR_INIT_SIZE)) == NULL)
		return ERROR_MEMORY;

	(*v)->size = 0;
	(*v)->alloc = VECTOR_INIT_SIZE;
	(*v)->printer = NULL;

	return OK;
}

status_t ADT_Vector_add(ADT_Vector_t **v, void *e)
{
	void *tmp;

	if(v == NULL || e == NULL) return ERROR_NULL_POINTER;

	/* Extends the array in case low memory left */
	if(((*v)->size + 1) == (*v)->alloc) {
		if((tmp = (void **)realloc((*v)->a, sizeof(void *) * (*v)->alloc * VECTOR_GROWTH_FACTOR)) == NULL)
			return ERROR_MEMORY;
		else {
			(*v)->a = tmp;
			(*v)->alloc *= VECTOR_GROWTH_FACTOR;
		}
	}

	(*v)->a[(*v)->size++] = e;

	return OK;
}

status_t ADT_Vector_destroy(ADT_Vector_t **v)
{
	if(v == NULL) return ERROR_NULL_POINTER;

	for(size_t i = 0; i < (*v)->size; i++) {
		free((*v)->a[i]);
		(*v)->a[i] = NULL;
	}

	free((*v)->a);
	free(*v);
	*v = NULL;

	return OK;
}

#define BUFFER_SIZE	100
status_t ADT_Vector_load(ADT_Vector_t *v, FILE *fi)
{
	char *b, *endptr;
	int  *tmp;

	if(v == NULL || fi == NULL) return ERROR_NULL_POINTER;

	if((b = calloc(sizeof(char), BUFFER_SIZE)) == NULL)
		return ERROR_MEMORY;

	while(fgets(b, BUFFER_SIZE, fi))
	{
		tmp = (int *)malloc(sizeof(int));

		*tmp = (int)strtol(b, &endptr, 10);
		if(*endptr != '\n') return ERROR_CORRUPT_FILE;

		ADT_Vector_add(&v, tmp);

		ADT_Vector_print(v, stdout);
	}

	return OK;
}

status_t ADT_Vector_print(ADT_Vector_t *v, FILE *fp)
{
	size_t i;

	if(v == NULL) return ERROR_NULL_POINTER;

	for(i = 0; i < v->size; i++)
		v->printer(v->a[i], fp);

	putchar('\n');
	return OK;
}

status_t ADT_Vector_sort(ADT_Vector_t *v, comparator_t pf)
{
	if(v == NULL) return ERROR_NULL_POINTER;

	/* Bubble sort */
	/* for(size_t i = 0; i < v->size; i++) */
	/* 	for(size_t j = 0; j < (v->size - i - 1); j++) */
	/* 		if(pf(v->a[j], v->a[j + 1]) > 0) */
	/* 			swap(v->a[j], v->a[j + 1]); */

	/* Quick sort */
	qsort(v->a, v->size, sizeof(void *), pf);

	return OK;
}

status_t ADT_Vector_set_printer(ADT_Vector_t *v, printer_t pf)
{
	if(v == NULL) return ERROR_NULL_POINTER;

	v->printer = pf;

	return OK;
}

status_t ADT_Vector_export_as_csv(ADT_Vector_t *v, FILE *fp, printer_t pf)
{
	status_t st;
	size_t i;

	if(v == NULL) return ERROR_NULL_POINTER;

	for(i = 0; i < v->size; i++)
		if((st = (*pf)(v->a[i], fp)) != OK)
			return st;

	return OK;
}

status_t ADT_Vector_export_as_xml(ADT_Vector_t *v, FILE *fp, printer_t pf)
{
	status_t st;
	size_t i;

	if(v == NULL) return ERROR_NULL_POINTER;

	fprintf(fp, "%s\n", STR_XML_HEADER);
	fprintf(fp, "<%s>\n", STR_XML_ROOT);

	for(i = 0; i < v->size; i++)
		if((st = (*pf)(v->a[i], fp)) != OK) 
			return st;

	fprintf(fp, "</%s>\n", STR_XML_ROOT);
	return OK;
}
