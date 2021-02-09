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
//	un archivo de texto cuyo nombre tambien recibe como argumento.


#include "main.h"
#include "macros.h"
#include "arguments.h"
#include "load_country_codes.h"
#include "read_file.h"
#include "print_file.h"
#include "perrors.h"


int main(int argc, char * argv[])
{

//	Esta variable es para guardar los codigos de error;
	status_t st;

//	Las siguientes variables son para guardar los nombres de los archivos de 
//	entrada y salida luego de validar que los argumentos recibidos sean correctos;
	char src[32], dest[32];

	FILE *fpi, *fpo;
	ulong country, date, infected;
	country = date = infected = 0;

	prev_month = prev_country = -1;

	infected_monthly = 0;

//	El siguiente arreglo de dos dimensiones es donde se van a guardar los
//	codigos	de los paises;
	char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH];

//	Valida de que los argumentos sean correctos y guarda los nombres de los
//	archivos de entrada y salida en src y dest respectivamente, de haber algun
//	error en el proceso devuelve un codigo de error de tipo status_t (definido
//	en main.h);
	if((st = validate_arguments(argc, argv, src, dest)) != OK) {
		print_error(st);
		return st;
	}
	
//	Carga los codigos de error de los paises de acuerdo al standard iso3166 en
//	el arreglo mencionado previamente 'country_codes', en caso de haber algun
//	error en el proceso devuelve dicho codigo e impreme por stderr un mensaje
//	de error; 
	if((st = load_country_codes(country_codes)) != OK) {
		print_error(st);
		return ERROR_LOADING_COUNTRY_CODES;	
	}

//	Abre el archivo de entrada en modo lectura, y el de salida en modo 
//	escritura, si por algun motivo falla imprime un codigo de error;
	if((fpi = fopen(src, "r")) == NULL) {
		fclose(fpi);
		return ERROR_READING_FILE;
	}

	if((fpo = fopen(dest, "w")) == NULL) {
		fclose(fpo);
		return ERROR_READING_FILE;
	}

	size_t line;
	for(line = 0; (st = read_file(fpi, &country, &date, &infected)) == OK; line++) {
		if(line != 0) {
			print_file(fpo, country_codes, &country, &date, &infected);
		}
		st = OK;
	}

	if((st != OK) && (st != END_OF_INPUT_FILE)) {
		fclose(fpi);
		fclose(fpo);
		return st;
	}

	fprintf_infected_monthly(fpo);

	fclose(fpi);
	fclose(fpo);

	printf(MSG_OK);
	return OK;
}
