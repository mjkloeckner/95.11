#ifndef READLINES_H
#define READLINES_H

#include "main.h"
#include "load_country_codes.h"

typedef enum {
	PAIS,
	DATE,
	INFECTED
} data_t;

status_t read_file(FILE *src, u_long *country, u_long *date, u_long *infected);

status_t fprintf_date(FILE *dest, size_t data);
status_t fprintf_infected(FILE *dest, size_t data, char newline);
status_t clean_buffer(char *buffer, size_t size);
status_t time_translator(time_t unix_time, char *res, size_t size, const char *format); 
status_t fprintf_country(FILE *dest, size_t country_code, char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH]);

#endif
