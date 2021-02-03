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
//	un archivo de extension .csv que tambien recibe como argumento,
//	si no recibe un archivo de salida crea uno con el nombre por
//	defecto 'output.csv';


#include "main.h"
#include "arguments.h"
#include "macros.h"
#include "load_country_codes.h"
#include "readlines.h"


int main(int argc, char * argv[])
{

//	Esta variable es para guardar los codigos de error en
//	caso de que haya alguno;
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
	if(load_country_codes(country_codes) != OK)
		return ERROR_LOADING_COUNTRY_CODES;	

	if((st = readlines(src, dest)) != OK) {
		print_error(st);
		return st;
	}	

	return OK;
}
