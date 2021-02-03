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

	char src[32], dest[32];

	char country_codes[COUNTRIES_NUMBER][ARRAYS_LENGTH];

//	char **country_codes = (char**)malloc(COUNTRIES_NUMBER * ARRAYS_LENGTH * sizeof(char));

	if((st = validate_arguments(argc, argv, src, dest)) != OK) {
		print_error(st);
		return st;
	}
	

	if(load_country_codes(country_codes) != OK)
		return ERROR_LOADING_COUNTRY_CODES;	


	putchar('\n');

	readlines();

	return OK;
}
