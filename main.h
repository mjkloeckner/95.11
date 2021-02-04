#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "macros.h"

#define COUNTRY_CODES_FILE_NAME "iso3166-1.csv"

typedef enum {
	OK,
	IO_FILE_NOT_FOUND,
	ERROR_INVOCATING_PROGRAM,
	ERROR_NULL_POINTER,
	ERROR_LOADING_COUNTRY_CODES,
	ERROR_PRINTING,
	ERROR_READING_FILE,
	ERROR_ALLOCATING_TIME,
	ERROR_DATA_ON_FILE_MISSING	
} status_t;


#endif
