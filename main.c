//	
//	Programa escrito por Martin J. Klockner
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
#include "readlines.h"
#include "perrors.h"


int main(int argc, char * argv[])
{

//	Esta variable es para guardar los codigos de error;
	status_t st;

//	Las siguientes variables son para guardar los nombres de los archivos de 
//	entrada y salida luego de validar que los argumentos recibidos sean correctos;
	char src[32], dest[32];

//	El siguiente arreglo de dos dimensiones es donde se van a guardar los codigos
//	de los paises;
	char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH];

//	Valida de que los argumentos sean correctos y guarda los nombres de los
//	archivos de entrada y salida en src y dest respectivamente, de haber algun
//	error en el proceso devuelve un codigo de error de tipo status_t (definido 
//	en main.h);
	if((st = validate_arguments(argc, argv, src, dest)) != OK) {
		print_error(st);
		return st;
	}
	
//	Carga los codigos de error de los paises de acuerdo al standard iso3166 en el
//	arreglo mencionado previamente 'country_codes', en caso de haber algun error 
//	en el proceso devuelve dicho codigo e impreme por stderr un mensaje de error; 
	if((st = load_country_codes(country_codes)) != OK) {
		print_error(st);
		return ERROR_LOADING_COUNTRY_CODES;	
	}

	if((st = readlines(src, dest, country_codes)) != OK) {
		print_error(st);
		return st;
	}	

	printf(MSG_OK);
	return OK;
}
