#ifndef VECTOR__H
#define VECTOR__H

#define VECTOR_INIT_SIZE		10
#define VECTOR_GROWTH_FACTOR	2

#include <stdlib.h>

#include "utils.h"
#include "status.h"

typedef status_t (*printer_t)(const void *, FILE *);
typedef int (*comparator_t)(const void *, const void *);

typedef struct {
	void **a;
	size_t size, alloc;

	printer_t printer;
	comparator_t comparator;

} ADT_Vector_t;

status_t ADT_Vector_create(ADT_Vector_t **);
status_t ADT_Vector_add(ADT_Vector_t **, void *);
status_t ADT_Vector_destroy(ADT_Vector_t **);

status_t ADT_Vector_set(ADT_Vector_t **, void *, size_t);
status_t ADT_Vector_print(const ADT_Vector_t *, FILE *);
status_t ADT_Vector_sort(ADT_Vector_t *, comparator_t);

void *ADT_Vector_get_elem(const ADT_Vector_t *v, void *e);

status_t ADT_Vector_set_printer(ADT_Vector_t *, printer_t);
status_t ADT_Vector_set_comparator(ADT_Vector_t *, comparator_t);

status_t ADT_Vector_export_as_xml(const ADT_Vector_t *, FILE *);
status_t ADT_Vector_export_as_csv(const ADT_Vector_t *, FILE *);

#endif
