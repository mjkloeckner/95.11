#ifndef LOAD_COUNTRY_CODES
#define LOAD_COUNTRY_CODES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE		65
#define COUNTRIES_NUMBER	500
#define ARRAYS_LENGTH		25

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_LOADING_COUNTRY_CODES
} status_t;

typedef enum {
	CODE,
	NAME
} part_t;

status_t empty_country_codes(char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH]); 
status_t load_country_codes(char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH]);

#endif
