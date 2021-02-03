//	Lee el archivo de entrada y va separando los datos mientras va leyendo linea
//	por linea, y los va imprimiendo en pantalla



#include "readlines.h"

#define COUNTRY_PROMPT "Pais"

const char date_print_format[] = "%d %b %Y";

status_t readlines(char *src, char *dest)
{
	size_t line, i, j;

//	Puntero para el archivo de entrada;	
	FILE *fp;

	char buff1[] = "                          ";
	char buff2[] = "                          ";

//	Esta variable es para saber de que tipo de dato estamos hablando, si es un
//	codigo de pais, una fecha o el numero de infectados;
	data_t data;

	char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH];
	load_country_codes(country_codes);

	unsigned long country;
	unsigned long date;
	unsigned long infected;


// Abre el archivo de entrada en modo lectura si por algun motivo no se puede
// abrir devuelve un codigo de error;
	if((fp = fopen(src, "r")) == NULL)
			return ERROR_READING_FILE;


//	Lee de el archivo de entrada linea por linea y va guardando las 
//	lineas en buff1 hasta que se terminen;
	for(line = 0; fgets(buff1, sizeof(buff1), fp) != NULL; line++)
	{

//	Este 'if' es para evitar la primer linea que no contiene ningun tipo de dato;
		if(line != 0) {

//			Recorre el buff1 separando los datos de acuerdo a si es el codigo de
//			un pais, una fecha o el numero de infectados;
			for(i = 0, j = 0, data = PAIS; buff1[i] != '\0'; i++)
			{

//				Si encuentra una coma cambia el tipo de dato;
				if((buff1[i] == ','))
				{

//					Se incrementa i para evitar que sea guardado en algun lado;
					i++;

//					De acuerdo al tipo de dato que se guardo hasta llegar a la
//					coma va a guardarlo de distinta manera, ej: si el dato que
//					se guardo en buff2 era el codigo de un PAIS, entonces lo 
//					guarda en la variable country, si el tipo de dato que se 
//					guardo en buff2 era una fecha entonces lo guarda en date, etc;
					switch(data) 
					{
						case PAIS: country = atoi(buff2); break;
						case DATE: date = atol(buff2); j++; break;
						case INFECTED: infected = atol(buff2); break;
					}

//					Como encontro una coma entonces el tipo de dato cambia;
					data++;

//					j vale cero porque es el indice de el buffer en el que se van
//					guardando los datos;
					j = 0;

//					Se limpia el buffer ya que se va a volver a utilizar;
					clean_buffer(buff2);


//				Si en lugar de una coma se encuentra un caracter de nueva line 
//				entonces significa que esta parado en el ultimo dato
				} else if (buff1[i] == '\n') {

//					Si estamos parados en el ultimo dato y no es INFECTED,
//					entonces la variable datos no se incremento tres veces, por
//					lo cual se supone que falta un dato, devolviendo un codigo de
//					error;
					if(data != INFECTED) 
						return ERROR_DATA_ON_FILE_MISSING;

//					Si esta todo bien entonces el dato vuelve a ser PAIS que es 
//					el primer dato de el archivo de entrada
					data = PAIS;
				}

				switch(data) 
				{
					case PAIS: buff2[i] = buff1[i];	break;
					case DATE: buff2[j] = buff1[i]; j++; break;
					case INFECTED: buff2[j] = buff1[i]; j++; break;

				}
			}
//			print_country(country, country_codes);
//			print_date(date);
//			print_infected(infected);
		}
	}

	fclose(fp);
	return OK;
}



status_t print_country(size_t country_code, char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH])
{
	if(country_codes == NULL)
		return ERROR_NULL_POINTER;

	printf(COUNTRY_PROMPT": %s\n", country_codes[country_code]);
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

