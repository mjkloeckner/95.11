#include "../include/io.h"
#include "../include/cla.h"
#include "../include/user.h"
#include "../include/status.h"
#include "../include/vector.h"

#define IN_FILE_MAX_LEN	100
#define IN_FILE_DELIM	","
#define OUT_FILE_DELIM	","
#define IN_FILE_FIELDS	6
#define IN_FILE_FIELDS_MAX_LEN	50

int main (int argc, char *argv[])
{
	status_t st;
	cla_t cla;
	ADT_Vector_t *v;
	ADT_user_t *user, *user_tmp;
	char buffer[IN_FILE_MAX_LEN];
	char **data;
	char *endptr;
	long amount;

	/* Asigna memoria a cla */
	if((st = cla_create(&cla)) != OK) {
		show_status(st);
		return st;
	}

	/* Valida que los argumentos sean correctos */
	if((st = validate_arguments(argc, argv, cla)) != OK) {
		show_status(st);
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

	if((st = user_create(&user_tmp)) != OK) {
		show_status(st);
		cla_destroy(cla);
		ADT_Vector_destroy(&v);
		return st;
	}

	while(fgets(buffer, IN_FILE_MAX_LEN, cla->fi)) {
		string_split(buffer, data, IN_FILE_DELIM);
		user_set_data(user_tmp, data);

		amount = strtol(data[POS_AMOUNT], &endptr, 10);
		if(*endptr != '\0') return ERROR_CORRUPT_DATA;

		if((user = ADT_Vector_get_elem(v, user_tmp)) != NULL) {
			/* El usuario ya existe */
			user_add_amount(user, amount);
		}
		else { 
			/* El usuario no existe */
			user_create(&user);
			user_set_data(user, data);
			ADT_Vector_add(&v, user);
		}
	}

	if((st = ADT_Vector_sort(v, user_comparator_credits_maxmin)) != OK) {
		show_status(st);
		free(user_tmp);
		cla_destroy(cla);
		ADT_Vector_destroy(&v);
		return st;
	}

	if((st = ADT_Vector_print(v, stdout, user_print_as_csv)) != OK) {
		show_status(st);
		free(user_tmp);
		cla_destroy(cla);
		ADT_Vector_destroy(&v);
		return st;
	}

	free(user_tmp);
	cla_destroy(cla);
	ADT_Vector_destroy(&v);
	return OK;
}
