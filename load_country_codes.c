#include "main.h"
#include "macros.h"
#include "load_country_codes.h"

status_t clean (char *buffer)
{
    size_t i;
    i = 0;
    while(buffer[i] != '\0') {
        buffer[i] = ' ';
        i++;
    }
    return OK;
}


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
	char buff_2[20];
	buff_2[19] = '\0';

	int country_code;
	char country_name[INITIAL_SIZE];
	country_name[INITIAL_SIZE - 1] = '\0';

	size_t i, j;
	part_t part;
		
	buff = malloc(INITIAL_SIZE);
	
	if((fp = fopen(COUNTRY_CODES_FILE_NAME, "r")) == NULL)
		return ERROR_NULL_POINTER;


	while(fgets(buff, INITIAL_SIZE, fp) != NULL) {
//		printf("%s", buff);

		for(i = 0, j = 0, part = CODE; (*(buff + i)) != '\0'; i++) {

			if((*(buff + i)) == ',') {
				country_code = atoi(buff_2);
				clean(buff_2);
//				printf("%d\n", country_code);
				part = NAME;
				i++;
			} else if (*(buff + i + 1) == '\n') {
//				clean(country_name);
				part = CODE;
				j = 0;
			}

			switch(part)
			{
				case CODE: buff_2[i] = *(buff + i); break;
				case NAME: country_name[j] = *(buff + i); j++; break;
			}
		}
//		putchar(country_name[1]);
		printf("%s\n", country_name);
		strcpy(country_name, country_codes[country_code]);
	}

	fclose(fp);
	free(buff);
	return OK;
}

