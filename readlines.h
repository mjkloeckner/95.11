#ifndef READLINES
#define READLINES

#include "main.h"
#include "load_country_codes.h"

#define INITIAL_SIZE 1000
#define TIME_MAX_DIGITS 1000

typedef enum {
	PAIS,
	DATE,
	INFECTED
} data_t;


status_t readlines(char *src, char *dest);
status_t fprintf_date(FILE *dest, size_t data);
status_t fprintf_infected(FILE *dest, size_t data);
status_t clean_buffer(char *buffer, size_t size);
status_t time_translator(time_t unix_time, char *res, size_t size); 
status_t fprintf_country(FILE *dest, size_t country_code, char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH]);

#endif
