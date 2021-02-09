#include "print_file.h"

const char formato_de_la_fecha[] = "%d %b %Y";

int prev_month, prev_country;
ulong infected_monthly;

status_t print_file(FILE *dest, char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH], ulong *country, ulong *date, ulong *infected) {

	int month;
	char time_s[TIME_MAX_DIGITS];
	time_translator(*(date), time_s, sizeof(time_s), "%m");

	month = atoi(time_s);
	if((prev_month == -1) || (prev_country == -1)) {
		prev_month = month;
		prev_country = *country;
	}

//	Imprime la suma de infectados por mes cada vez que cambia el pais;
	if((*(country) == prev_country) && (month == prev_month)) {
		infected_monthly += *(infected);
	}	
	else if(*(country) != prev_country) {
		fprintf_infected_monthly(dest);
		infected_monthly = *(infected);

		prev_country = *(country);
		prev_month = month;
	}
	else if(month != prev_month) {
		prev_month = month;

		fprintf_infected_monthly(dest);
		infected_monthly = *(infected);
	}

//	Imprime datos segun el archivo de entrada;
	fprintf_country(dest, *(country), country_codes);
	fprintf_date(dest, *(date));
	fprintf_infected(dest, *(infected), '\n');
	
	return OK;
}


status_t fprintf_country(FILE *dest, size_t country_code, char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH])
{
	if((country_codes == NULL) || (dest == NULL))
		return ERROR_NULL_POINTER;

	fprintf(dest, COUNTRY_PROMPT": %s\n", country_codes[country_code]);
	return OK;
}

status_t fprintf_date(FILE *dest, size_t date)
{
	char time_c[TIME_MAX_DIGITS];
	status_t st;

	if(dest == NULL)
		return ERROR_NULL_POINTER;

	if((st = time_translator(date, time_c, sizeof(time_c), formato_de_la_fecha)) != OK)
		return st;

	fprintf(dest, "Fecha: %s\n", time_c);
	return OK;
}

status_t fprintf_infected(FILE *dest, size_t infected, char newline)
{
	if(dest == NULL)
		return ERROR_NULL_POINTER;

	fprintf(dest, "Infectados: %lu\n%c", infected, newline);
	return OK;
}


//	Traduce de la fecha de formato unix a format y lo guarda en res como
//	como una cadena de caracteres;
status_t time_translator(time_t unix_time, char *res, size_t size, const char *format) 
{
	if(res == NULL || format == NULL)
		return ERROR_NULL_POINTER;

	
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

void fprintf_infected_monthly(FILE *dest) 
{
	char guion_medio[] = "-----------";

	int length = snprintf( NULL, 0, "%lu", infected_monthly );
	char* str_infected_monthly = (char *)malloc( length + 1 );
	snprintf( str_infected_monthly, length + 1, "%lu", infected_monthly );


	fprintf(dest, "Infectados por mes: %lu\n", infected_monthly);	
	sprintf(str_infected_monthly, "%lu", 10);
	fprintf(dest, "-------------------%.*s\n", (length + 1), guion_medio); 

	free(str_infected_monthly);
}
