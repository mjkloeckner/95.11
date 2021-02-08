#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "macros.h"

#define COUNTRY_CODES_FILE_NAME "iso3166-1.csv"

#define COUNTRIES_NUMBER	1000
#define ARRAYS_LENGTH		100

#define COUNTRY_PROMPT "Pais"

#define SIZE_OF_BUFF1	32
#define SIZE_OF_BUFF2	32	

#define INITIAL_SIZE 1000
#define TIME_MAX_DIGITS 1000

extern const char formato_de_la_fecha[];

extern ulong country, date, infected;

typedef enum {
	OK,
	IO_FILE_NOT_FOUND,
	ERROR_INVOCATING_PROGRAM,
	ERROR_NULL_POINTER,
	ERROR_LOADING_COUNTRY_CODES,
	ERROR_PRINTING,
	ERROR_READING_FILE,
	ERROR_ALLOCATING_TIME,
	ERROR_DATA_ON_FILE_MISSING,
	END_OF_INPUT_FILE
} status_t;


#endif
