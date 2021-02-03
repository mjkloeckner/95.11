// Carga en memoria los codigos de los paises de el archivo de nombre 
// "COUNTRY_CODES_FILE_NAME" definido en macros.h y devuelve un puntero
// a dicho arreglo con los codigos cargados;


#include "main.h"
#include "macros.h"
#include "load_country_codes.h"

status_t clean (char *buffer, size_t size)
{
	size_t i;
    i = 0;

	if(buffer == NULL)
		return ERROR_NULL_POINTER;

    while(i < size) {
        buffer[i] = '\0';
        i++;
    }
    return OK;
}

//	Inicializa el arreglo alocando el caracter '\0' en todas las posiciones;
status_t empty_country_codes(char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH]) 
{
	size_t i, j;
	for(i = 0; i < COUNTRIES_NUMBER; i++)
		for(j = 0; j < (ARRAYS_LENGTH - 1); j++) {
			country_codes[i][j] = '\0';
		
		country_codes[i][ARRAYS_LENGTH - 1] = '\n';
		}

	return OK;
}


// Abre el archivo "COUNTRY_CODES_FILE_NAME" y lee linea por linea hasta llegar
// al final, mientras lee lo va guardando en un buffer que recorre caracter por
// caracter en busqueda de el character separador de datos, en este caso ',', 
// mientras recorre el buffer va separando los datos y los guarda en la variable
// que corresponda;
status_t load_country_codes(char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH])
{
	FILE *fp;

	empty_country_codes(country_codes);

	char *buff;
	char buff_2[INITIAL_SIZE];
	buff_2[INITIAL_SIZE] = '\0';

	int country_code;
	char country_name[INITIAL_SIZE];
	country_name[INITIAL_SIZE - 1] = '\0';

	size_t i, j;
	part_t part;
		
	buff = malloc(INITIAL_SIZE);
	
	if((fp = fopen(COUNTRY_CODES_FILE_NAME, "r")) == NULL)
		return ERROR_NULL_POINTER;


	while(fgets(buff, INITIAL_SIZE, fp) != NULL) {
		clean(country_name, INITIAL_SIZE);
		for(i = 0, j = 0, part = CODE; buff[i] != '\0'; i++) {
			if(buff[i] == ',') {
				part = NAME;
				i++;
			} else if (buff[i] == '\n') {
				part = CODE;
				j = 0;
			}

			switch(part)
			{
				case CODE: buff_2[i] = *(buff + i); break;
				case NAME: country_name[j] = *(buff + i); j++; break;
			}
		}
		country_code = atoi(buff_2);
		clean(buff_2, INITIAL_SIZE);
		strcpy(country_codes[country_code], country_name);
	}

//	Cierra el archivo que contiene el codigo de los paises de acuerdo al estandar;
	fclose(fp);
	free(buff);
	return OK;
}

