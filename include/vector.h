#ifndef VECTOR__H
#define VECTOR__H

#define VECTOR_INIT_SIZE		10
#define VECTOR_GROWTH_FACTOR	2

#define STR_XML_ROOT	"root"
#define STR_XML_HEADER	"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"

#include <stdlib.h>

#include "types.h"

typedef status_t (*printer_t)(const void *, FILE *);
/* typedef int (*comparator_t)(void *, void *); */

typedef int (*comparator_t)(const void *, const void *);

typedef struct {
	void **a;
	size_t size, alloc;

	printer_t printer;

} ADT_Vector_t;

status_t ADT_Vector_create(ADT_Vector_t **);
status_t ADT_Vector_add(ADT_Vector_t **, void *);
status_t ADT_Vector_destroy(ADT_Vector_t **);

status_t ADT_Vector_load(ADT_Vector_t *, FILE *);
status_t ADT_Vector_print(ADT_Vector_t *, FILE *);
status_t ADT_Vector_sort(ADT_Vector_t *, comparator_t);

status_t ADT_Vector_set_printer(ADT_Vector_t *, printer_t);

status_t ADT_Vector_export_as_xml(ADT_Vector_t *, FILE *, printer_t);
status_t ADT_Vector_export_as_csv(ADT_Vector_t *, FILE *, printer_t);

#endif
