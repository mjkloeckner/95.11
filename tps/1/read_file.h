#ifndef READLINES_H
#define READLINES_H

#include "main.h"
#include "load_country_codes.h"

typedef enum {
	PAIS,
	DATE,
	INFECTED
} data_t;

status_t read_file(FILE *src, uint *country, uint *date, uint *infected);

status_t clean_buffer(char *buffer, size_t size);

#endif
