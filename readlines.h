#ifndef READLINES
#define READLINES

#include "main.h"
#include "load_country_codes.h"

#define INPUT_FILE_NAME "input.csv"
#define INITIAL_SIZE 1000
#define TIME_MAX_DIGITS 1000

#define ARG "Argentina"
#define COL "Colombia"
#define GER "Germany"

typedef enum {
	PAIS,
	DATE,
	INFECTED
} data_t;


status_t readlines(char *src, char *dest);
status_t print_date(size_t data);
status_t print_infected(size_t data);
status_t clean_buffer(char *buffer);
status_t time_translator(time_t unix_time, char *res, size_t size); 
status_t print_country(size_t country_code, char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH]);

#endif
