#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUT_FILE_NAME "input.csv"
#define INITIAL_SIZE 1000
#define TIME_MAX_DIGITS 1000

#define ARG "Argentina"
#define COL "Colombia"
#define GER "Germany"

const char date_print_format[] = "%b %Y";

typedef enum {
	OK,
	ERROR_PRINTING,
	ERROR_READING_FILE,
	ERROR_NULL_POINTER,
	ERROR_ALLOCATING_TIME
} status_t;

typedef enum {
	PAIS,
	DATE,
	INFECTED
} data_t;

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

