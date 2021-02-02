#include "main.h"
#include "arguments.h"
#include "macros.h"
#include "load_country_codes.h"

#define CANTIDAD_DE_DATOS 3

int main(int argc, char * argv[])
{
	status_t st;
	FILE *fpi;
//		, *fpo;

	char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH];

	if((st = validate_arguments(argc, argv)) != OK) {
		print_error(st);
		return st;
	}
	
	char * src;
	char * dest;

	src = (char *)malloc(INITIAL_SIZE * sizeof(char));
	dest = (char *)malloc(INITIAL_SIZE * sizeof(char));

	if((st = set_files_name(argc, argv, src, dest)) != OK) {
		print_error(st);
		return st;
	}


	if(load_country_codes(country_codes) != OK)
		return ERROR_LOADING_COUNTRY_CODES;	


	printf("Hello world! (after load_country_codes call)\n");
	printf("the country number 32 of iso 3166 is: %s\n", country_codes[32]);

	fpi = fopen(src, "r");
//	fpo = fopen(dest, "w");

	fclose(fpi);
//	fclose(fpo);
	return OK;
}
