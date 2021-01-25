#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "readlines.h"

const char date_print_format[] = "%d %b %Y";

status_t print_country(size_t country_code);
status_t print_date(size_t data);
status_t print_infected(size_t data);
status_t clean_buffer(char *buffer);
status_t time_translator(time_t unix_time, char *res, size_t size); 

int main(void)
{
	size_t line, i, j;
	FILE *fp;
	char buff1[] = "                          ";
	char buff2[] = "                          ";
	data_t data;

	unsigned long country;
	unsigned long date;
	unsigned long infected;

	if((fp = fopen(INPUT_FILE_NAME, "r")) == NULL)
			return ERROR_READING_FILE;

	for(line = 0; fgets(buff1, sizeof(buff1), fp) != NULL; line++)
	{
//	This if is to skip the first line which doesn't contain information;
		if(line != 0) {
			for(i = 0, j = 0, data = PAIS; buff1[i] != '\0'; i++)
			{
				if((buff1[i] == ',') || (buff1[i] == '\n'))
				{
					i++;
					switch(data) 
					{
						case PAIS: country = atoi(buff2); break;
						case DATE: date = atol(buff2); j++; break;
						case INFECTED: infected = atol(buff2); break;
					}
					data++;
					j = 0;
					clean_buffer(buff2);
				}

				switch(data) 
				{
					case PAIS: buff2[i] = buff1[i];	break;
					case DATE: buff2[j] = buff1[i]; j++; break;
					case INFECTED: buff2[j] = buff1[i]; j++; break;

				}
			}
			print_country(country);
			print_date(date);
			print_infected(infected);
		}
	}

//	char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH];

//	if(load_country_codes(country_codes) != OK)
//		return ERROR_LOADING_COUNTRY_CODES;
//	empty_country_codes(country_codes);

//	size_t i;
//	for(i = 0; i < 500; i++)
//		printf("%s", *(country_codes + i));


	fclose(fp);
	return 0;
}



status_t print_country(size_t country_code)
{
	switch(country_code)
	{
		case 32: printf("Pais: "ARG"\n"); break;
		case 170: printf("Pais: "COL"\n"); break;
		case 276: printf("Pais: "GER"\n"); break;
	}
	return OK;
}

status_t print_date(size_t date)
{
	char time_c[TIME_MAX_DIGITS];
	
	time_translator(date, time_c, sizeof(time_c));
	printf("Fecha: %s\n", time_c);

	return OK;
}

status_t print_infected(size_t infected)
{
	printf("Infectados: %lu\n\n", infected);

	return OK;
}

status_t clean_buffer(char *buffer)
{
	if(buffer == NULL)
		return ERROR_NULL_POINTER;

	while(*buffer != '\0')
	{
		(*buffer) = ' ';
		buffer++;
	}
	return OK;
}


status_t time_translator(time_t unix_time, char *res, size_t size) 
{
	const char *format = date_print_format;
	struct tm *tmp = gmtime(&unix_time);

	if (strftime(res, size, format, tmp) == 0) {
		(void) fprintf(stderr,  "strftime(3): cannot format supplied "
								"date/time into buffer of size %u "
								"using: '%s'\n",
								(unsigned int)sizeof(res), format);
		return ERROR_ALLOCATING_TIME;
	}
	return OK;
}

