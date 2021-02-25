//	
//	Programa escrito por Martin J. Klӧckner
//		martin.cachari@gmail.com
//		github.com/klewer-martin
//
//	Repositorio de github del proyecto:
//			https://github.com/klewer-martin/9511_project01.git
//			(Disponible a partir de la fecha de correccion)
			

//	Lee texto de un archivo con extension .csv cuyo nombre recibe 
//	como argumento; el cual contiene solo numeros que representan 
//	un pais, una fecha y una cantidad de infectados y lo guarda en
//	un archivo de texto cuyo nombre tambien recibe como argumento 
//	con un formato humanamente entendible.


#include "main.h"
#include "macros.h"
#include "arguments.h"
#include "load_country_codes.h"
#include "read_file.h"
#include "print_file.h"
#include "perrors.h"


int main(int argc, char * argv[])
{
	status_t st;

//	Las siguientes variables son para guardar los nombres de los archivos de 
//	entrada y salida luego de validar los argumentos
//	char src[MAX_NAME_LENGTH], dest[MAX_NAME_LENGTH];
	char *src;
	char *dest;

	src = (char *)malloc(MAX_NAME_LENGTH);
	dest = (char *)malloc(MAX_NAME_LENGTH);

	FILE *fpi, *fpo;
	uint country, date, infected;

	country = date = infected = 0;
	prev_month = prev_country = -1;
	infected_monthly = 0;

//	Arreglo de arreglos de caracteres para guardar los codigos de los paises
	char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH];

//	Valida de que los argumentos sean correctos y guarda los nombres de los
//	archivos de entrada y salida en src y dest respectivamente
	if((st = validate_arguments(argc, argv, src, dest)) != OK) {
		print_error(st);
		return st;
	}
	
//	Carga los codigos de error de los paises de acuerdo al standard iso3166 en
//	el arreglo mencionado previamente 'country_codes'  
	if((st = load_country_codes(country_codes)) != OK) {
		print_error(st);
		return ERROR_LOADING_COUNTRY_CODES;	
	}

//	Abre el archivo de entrada en modo lectura
	if((fpi = fopen(src, "r")) == NULL) {
		fclose(fpi);
		print_error(ERROR_READING_FILE);
		return ERROR_READING_FILE;
	}

//	Abre el archivo de salida en modo escritura
	if((fpo = fopen(dest, "w")) == NULL) {
		fclose(fpo);
		print_error(ERROR_READING_FILE);
		return ERROR_READING_FILE;
	}

//	Lee el archivo de entrada y va imprimiendo linea por linea en el de salida
	size_t line;
	for(line = 0; (st = read_file(fpi, &country, &date, &infected)) == OK; line++) {
		if(line != 0) {
			print_file(fpo, country_codes, &country, &date, &infected);
		}
	}


//	Si hubo algun error al leer o escribir el archivo va a imprimir un error
	if((st != OK) && (st != END_OF_INPUT_FILE)) {
		fclose(fpi);
		fclose(fpo);
		print_error(st);
		return st;
	}

//	El la ultima linea de 'infectados por mes'
	fprintf_infected_monthly(fpo);

	fclose(fpi);
	fclose(fpo);

	printf(MSG_OK);
	return OK;
}
