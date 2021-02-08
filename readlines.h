#ifndef READLINES_H
#define READLINES_H

#include "main.h"
#include "load_country_codes.h"

#define COUNTRY_PROMPT "Pais"

#define SIZE_OF_BUFF1	32
#define SIZE_OF_BUFF2	32	

#define INITIAL_SIZE 1000
#define TIME_MAX_DIGITS 1000

extern const char formato_de_la_fecha[];

typedef enum {
	PAIS,
	DATE,
	INFECTED
} data_t;

status_t readlines(char *src, char *dest, char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH]);
status_t fprintf_date(FILE *dest, size_t data);
status_t fprintf_infected(FILE *dest, size_t data, char newline);
status_t clean_buffer(char *buffer, size_t size);
status_t time_translator(time_t unix_time, char *res, size_t size, const char *format); 
status_t fprintf_country(FILE *dest, size_t country_code, char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH]);

#endif
