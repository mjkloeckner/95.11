#ifndef LOAD_COUNTRY_CODES
#define LOAD_COUNTRY_CODES

#include "main.h"

#define COUNTRIES_NUMBER	1000
#define ARRAYS_LENGTH		100

typedef enum {
	CODE,
	NAME
} part_t;

status_t clean (char *buffer, size_t size);
status_t empty_country_codes(char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH]); 
status_t load_country_codes(char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH]);

#endif
