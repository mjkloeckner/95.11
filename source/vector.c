#include "../include/vector.h"

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
	(*v)->comparator = NULL;

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

/* Esta funcion no puede crear elementos nuevos, solo setear los que ya estan */
status_t ADT_Vector_set_elem(ADT_Vector_t **v, void *e, size_t pos)
{
	if(v == NULL || e == NULL) return ERROR_NULL_POINTER;
	else if(pos > (*v)->size) return ERROR_INVALID_POS;

	(*v)->a[pos] = e;

	return OK;
}

status_t ADT_Vector_get_elem(const ADT_Vector_t *v, void **e, size_t pos)
{
	if(v == NULL || e == NULL) return ERROR_NULL_POINTER;

	*e = v->a[pos];

	return OK;
}

status_t ADT_Vector_get_elem_pos(const ADT_Vector_t *v, void *e, size_t *pos)
{
	size_t i;

	if(v == NULL || e == NULL) return ERROR_NULL_POINTER;

	for(i = 0; i < v->size; i++) { 
		if(v->comparator(e, v->a[i])) {
			*pos = i;
			return OK;
		}
	}

	return ELEM_NOT_FOUND;
}

status_t ADT_Vector_print(const ADT_Vector_t *v, FILE *fp)
{
	status_t st;
	size_t i;

	if(v == NULL) return ERROR_NULL_POINTER;

	for(i = 0; i < v->size; i++)
		if((st = v->printer(v->a[i], fp)) != OK)
			return st;

	return OK;
}

status_t ADT_Vector_sort(ADT_Vector_t *v, comparator_t pf)
{
	if(v == NULL) return ERROR_NULL_POINTER;

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

status_t ADT_Vector_set_comparator(ADT_Vector_t *v, comparator_t pf)
{
	if(v == NULL) return ERROR_NULL_POINTER;

	v->comparator = pf;

	return OK;
}

status_t ADT_Vector_export_as_csv(const ADT_Vector_t *v, FILE *fp)
{
	status_t st;
	size_t i;

	if(v == NULL) return ERROR_NULL_POINTER;

	for(i = 0; i < v->size; i++)
		if((st = v->printer(v->a[i], fp)) != OK)
			return st;

	return OK;
}

status_t ADT_Vector_export_as_xml(const ADT_Vector_t *v, FILE *fp)
{
	status_t st;
	size_t i;

	if(v == NULL) return ERROR_NULL_POINTER;

	fprintf(fp, "%s\n", XML_STR_HEADER);
	fprintf(fp, "<%s>\n", XML_STR_ROOT);

	for(i = 0; i < v->size; i++){
		fprintf(fp, "\t<%s>\n", XML_STR_ROW);
		if((st = v->printer(v->a[i], fp)) != OK)
			return st;

		fprintf(fp, "\t</%s>\n", XML_STR_ROW);
	}

	fprintf(fp, "</%s>\n", XML_STR_ROOT);
	return OK;
}
