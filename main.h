#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNTRY_CODES_FILE_NAME "iso3166-1_numbers_and_countries.csv"

typedef enum {
	OK,
	ERROR_INVOCATING_PROGRAM,
	ERROR_NULL_POINTER,
	FILE_NOT_FOUND,
	ERROR_LOADING_COUNTRY_CODES,
	ERROR_PRINTING,
	ERROR_READING_FILE,
	ERROR_ALLOCATING_TIME
} status_t;

#endif
