//	Lee el archivo de entrada y va separando los datos mientras va leyendo linea
//	por linea, y los va imprimiendo en pantalla


#include "readlines.h"

#define COUNTRY_PROMPT "Pais"

#define SIZE_OF_BUFF1	32
#define SIZE_OF_BUFF2	32	

const char date_print_format[] = "%d %b %Y";

status_t readlines(char *src, char *dest)
{
	size_t line, i, j;
	status_t st;

//	Puntero para el archivo de entrada y de salida respectivamente;	
	FILE *fpi; 
	FILE *fpo;


	char buff1[SIZE_OF_BUFF1];
	char buff2[SIZE_OF_BUFF2];

	clean_buffer(buff1, SIZE_OF_BUFF1);
	clean_buffer(buff2, SIZE_OF_BUFF2);

//	Esta variable es para saber de que tipo de dato estamos hablando, si es un
//	codigo de pais, una fecha o el numero de infectados;
	data_t data;

	unsigned long country;
	unsigned long date;
	unsigned long infected;

//	Arreglo para almacenar los codigos de los paises segun el standard iso3166-1,
	char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH];

//	Carga los datos al arreglo mencionado previamente, en caso de haber algun
//	error devuelve el codigo de dicho error;
	if((st = load_country_codes(country_codes)) != OK) 
		return st;
	
//	Abre el archivo de entrada en modo lectura si por algun motivo no se puede
//	abrir devuelve un codigo de error;
	if((fpi = fopen(src, "r")) == NULL)
			return ERROR_READING_FILE;

	if((fpo = fopen(dest, "w")) == NULL)
			return ERROR_READING_FILE;

//	Lee de el archivo de entrada linea por linea y va guardando las 
//	lineas en buff1 hasta que se terminen;
	for(line = 0; fgets(buff1, sizeof(buff1), fpi) != NULL; line++)
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
//					Saltea la coma;					
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
					}


//					Como encontro una coma entonces el tipo de dato cambia;
					data++;

//					j vale cero porque es el indice de el buffer en el que se van
//					guardando los datos;
					j = 0;

//					Se limpia el buffer ya que se va a volver a utilizar;
					clean_buffer(buff2, SIZE_OF_BUFF2);


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
					infected = atol(buff2);
					clean_buffer(buff2, SIZE_OF_BUFF2);
				}

				switch(data) 
				{
					case PAIS: buff2[i] = buff1[i];	break;
					case DATE: buff2[j] = buff1[i]; j++; break;
					case INFECTED: buff2[j] = buff1[i]; j++; break;
				}
			}
			fprintf_country(fpo, country, country_codes);
			fprintf_date(fpo, date);
			fprintf_infected(fpo, infected);
		}
	}

	fclose(fpi);
	fclose(fpo);
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

	if((st = time_translator(date, time_c, sizeof(time_c))) != OK)
		return st;

	fprintf(dest, "Fecha: %s\n", time_c);
	return OK;
}

status_t fprintf_infected(FILE *dest, size_t infected)
{
	if(dest == NULL)
		return ERROR_NULL_POINTER;

	fprintf(dest, "Infectados: %lu\n\n", infected);
	return OK;
}

status_t clean_buffer(char *buffer, size_t size)
{
	if(buffer == NULL)
		return ERROR_NULL_POINTER;

	size_t i;
	for(i = 0; i < size; i++)
		buffer[i] = '\0';
	
	return OK;
}


status_t time_translator(time_t unix_time, char *res, size_t size) 
{
	if(res == NULL)
		return ERROR_NULL_POINTER;

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

