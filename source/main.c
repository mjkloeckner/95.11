#include "../include/cla.h"
#include "../include/status.h"
#include "../include/io.h" /* output_gen() */
#include "../include/sort.h"

/* "ca" - creditos ascendentes | "cd" - creditos descendentes
 * "da" - debitos ascendentes  | "dd" - debitos descendentes */
#define SORTING_ORDER	"cd"

#define EXIT_SUCCESS_MSG "Ejecución terminada exitosamente"
#define USERS_REGISTERED_MSG	"Usuarios registrados: "
#define PROCESED_LINES_MSG		"Lineas procesadas: "

int main (int argc, char *argv[])
{
	status_t st;
	cla_t cla;
	user_t *users;
	size_t size;

	/* Valida que los argumentos sean correctos */
	if((st = validate_arguments(argc, argv)) != OK) {
		show_status(st);
		return st;
	}

	/* Asigna memoria a cla */
	if((st = cla_create(&cla)) != OK) {
		show_status(st);
		return st;
	}

	/* Asigna a la estructura 'cla' los argumentos ingresados */
	if((st = cla_setup(argc, argv, &cla)) != OK) {
		show_status(st);
		return st;
	}

	/* Carga en users los usuarios desde el archivo de entrada */
	if((st = process_file(cla, &users, &size)) != OK) {
		show_status(st);
		cla_destroy(&cla);
		destroy_users(users, size);
		return st;
	}

	/* Ordena los usuarios con orden SORTING_ORDER */
	if((st = sort_users(users, size, SORTING_ORDER)) != OK) {
		show_status(st);
		cla_destroy(&cla);
		destroy_users(users, size);
		return st;
	}

	/* Imprime los datos cargados en users a un archivo de salida */
	if((st = export_data(cla, users, size)) != OK) {
		show_status(st);
		cla_destroy(&cla);
		destroy_users(users, size);
		return st;
	}

	printf("\n%s\n%s%ld\n%s%ld\n", EXIT_SUCCESS_MSG, USERS_REGISTERED_MSG,\
			size, PROCESED_LINES_MSG, cla->parsed_lines);

	cla_destroy(&cla);
	destroy_users(users, size);

	return OK;
}
