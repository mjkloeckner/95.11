#include "../include/cla.h"
#include "../include/user.h"
#include "../include/utils.h"
#include "../include/status.h"
#include "../include/vector.h"

int main (int argc, char *argv[])
{
	status_t st;
	cla_t cla;
	ADT_Vector_t *v;

	/* Asigna memoria a cla (c.l.a.: "command line arguments") */
	if((st = cla_create(&cla)) != OK) {
		show_status(st);
		return st;
	}

	/* Valida que los argumentos sean correctos y asigna valores a cla */
	if((st = validate_arguments(argc, argv, cla)) != OK) {
		show_status(st);
		cla_destroy(cla);
		return st;
	}

	/* Crea un vector */
	if((st = ADT_Vector_create(&v)) != OK) {
		show_status(st);
		cla_destroy(cla);
		return st;
	}

	/* Setea el comparador a ADT_Vector */	
	if((st = ADT_Vector_set_comparator(v, user_equals)) != OK) {
		show_status(st);
		cla_destroy(cla);
		ADT_Vector_destroy(&v);
		return st;
	}

	/* Carga el vector con los usuarios del archivo de entrada */
	if((st = load_users_to_vector(&v, cla)) != OK) {
		show_status(st);
		cla_destroy(cla);
		ADT_Vector_destroy(&v);
		return st;
	}

	/* Ordena el vector con los usuarios */
	if((st = ADT_Vector_sort(v, user_comparator_credits_maxmin)) != OK) {
		show_status(st);
		cla_destroy(cla);
		ADT_Vector_destroy(&v);
		return st;
	}

	/* Setea el impresor e imprime ADT_Vector según el argumento ingresado */
	if(!strcmp(cla->fmt, STR_FMT_CSV)) {
		if((st = ADT_Vector_set_printer(v, user_print_as_csv)) != OK) {
			show_status(st);
			cla_destroy(cla);
			ADT_Vector_destroy(&v);
			return st;
		}
		/* E imprime el vector con los usuarios */
		if((st = ADT_Vector_export_as_csv(v, cla->fo)) != OK) {
			show_status(st);
			cla_destroy(cla);
			ADT_Vector_destroy(&v);
			return st;
		}
	}
	else if(!strcmp(cla->fmt, STR_FMT_XML)) {
		if((st = ADT_Vector_set_printer(v, user_print_as_xml)) != OK) {
			show_status(st);
			cla_destroy(cla);
			ADT_Vector_destroy(&v);
			return st;
		}
		if((st = ADT_Vector_export_as_xml(v, cla->fo)) != OK) {
			show_status(st);
			cla_destroy(cla);
			ADT_Vector_destroy(&v);
			return st;
		}
	}

	cla_destroy(cla);
	ADT_Vector_destroy(&v);
	return OK;
}
