#ifndef PRINT_FILE_H
#define PRINT_FILE_H

#include "main.h"

status_t print_file(FILE *dest, char **country_codes, uint *country, uint *date, uint *infected);

status_t fprintf_country(FILE *dest, size_t country_code, char **country_codes);
status_t fprintf_date(FILE *dest, size_t date);
status_t fprintf_infected(FILE *dest, uint infected, char newline);

void fprintf_infected_monthly(FILE *dest);

status_t clean_buffer(char *buffer, size_t size);
status_t time_translator(time_t unix_time, char *res, size_t size, const char *format);


#endif
