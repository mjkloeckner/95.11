#include "main.h"
#include "load_country_codes.h"

status_t empty_country_codes(char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH]) 
{
	size_t i, j;
	for(i = 0; i < COUNTRIES_NUMBER; i++)
		for(j = 0; j < (ARRAYS_LENGTH - 1); j++) {
			country_codes[i][j] = 'a';
		
		country_codes[i][ARRAYS_LENGTH - 1] = '\n';
		}

	return OK;
}

status_t load_country_codes(char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH])
{
	FILE *fp;

	char *buff;
	char buff_2[10];

	int country_code;
	char country_name[INITIAL_SIZE];

	size_t i, j;
	part_t part;
		
	buff = malloc(INITIAL_SIZE);
	
	
	if((fp = fopen("iso3166-1_numbers_and_countries.csv", "r")) == NULL)
		return ERROR_NULL_POINTER;

	while(fgets(buff, INITIAL_SIZE, fp) != NULL) {
		for(i = 0, j = 0, part = CODE; (*(buff + i)) != '\0'; i++) {
			if((*(buff + i + 1)) == ',') {
				country_code = atoi(buff_2);
				part = NAME;
			}


			switch(part)
			{
				case CODE: buff_2[i] = *(buff + i); break;
				case NAME: country_name[j] = *(buff + i); j++; break;
			}
		}
		strcpy(country_name, country_codes[country_code]);
	}

	fclose(fp);
	free(buff);
	return OK;
}

