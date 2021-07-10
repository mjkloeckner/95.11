#include "../include/cla.h"
#include "../include/errors.h"
#include "../include/io.h" /* output_gen() */

#include <stdlib.h>

int main (int argc, char *argv[])
{
	status_t st;
	cla_t cla;

	if((st = validate_arguments(argc, argv)) != OK) {
		show_status(st);
		return st;
	}

	if((st = setup(argc, argv, &cla))) {
		show_status(st);
		return st;
	}
	/* En este punto ya tengo todos los datos que necesito, el nombre de los archivos de entrada, el tiempo inicial y final, y el formato de el archivo de salida */

	if((st = output_gen(cla))) {
		show_status(st);
		return st;
	}

	clean(cla);
	return OK;
}
