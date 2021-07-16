#include "../include/cla.h"
#include "../include/errors.h"
#include "../include/io.h" /* output_gen() */
#include "../include/sort.h"

#include <stdlib.h>

#define SORTING_ORDER	"a"

status_t create_array(int *arr, size_t len);
status_t load_values(int **arr, size_t len);
status_t destroy_array(int *arr, size_t len);

int main (int argc, char *argv[])
{
	status_t st;
	FILE *tmp_file;
	cla_t cla;

	if((st = validate_arguments(argc, argv)) != OK) {
		show_status(st);
		return st;
	}

	if((st = setup(argc, argv, &cla)) != OK) {
		show_status(st);
		return st;
	}
	/* En este punto ya tengo todos los datos que necesito, el nombre de los archivos de entrada, el tiempo inicial y final, y el formato de el archivo de salida */

	/* Genera un archivo binario temporal con los datos parseados  */
	if((st = tmp_file_gen(cla, &tmp_file)) != OK) {
		show_status(st);
		return st;
	}

	/* Exporta el archivo temporal a un archivo de texto con formato de acuerdo a la flag recibida como argumento */
	/* if((st = export_data(cla, tmp_file)) != OK) { */
	/* 	show_status(st); */
	/* 	return st; */
	/* } */

	clean(cla);
	return OK;
}
