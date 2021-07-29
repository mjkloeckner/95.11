#include "../include/cla.h"
#include "../include/user.h"
#include "../include/utils.h"
#include "../include/status.h"
#include "../include/vector.h"

#define IN_FILE_MAX_LEN	100
#define IN_FILE_DELIM	","
#define IN_FILE_FIELDS	6
#define IN_FILE_FIELDS_MAX_LEN	50

int main (int argc, char *argv[])
{
	status_t st;
	cla_t cla;
	ADT_Vector_t *v;
	ADT_user_t *user, *user_tmp;
	char buffer[IN_FILE_MAX_LEN];
	char *endptr, **data;
	size_t i;
	long amount;
	time_t epoch;

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

	/* Crea un arreglo de cadenas de caracteres */
	if((data = malloc(sizeof(char *) * IN_FILE_FIELDS)) == NULL) {
		show_status(ERROR_MEMORY);
		cla_destroy(cla);
		ADT_Vector_destroy(&v);
		return ERROR_MEMORY;
	}

	for(i = 0; i < IN_FILE_FIELDS; i++) {
		if((data[i] = calloc(sizeof(char), IN_FILE_FIELDS_MAX_LEN)) == NULL) {
			show_status(ERROR_MEMORY);
			cla_destroy(cla);
			ADT_Vector_destroy(&v);
			array_destroy(data, IN_FILE_FIELDS);
			return ERROR_MEMORY;
		}
	}

	/* Setea el comparador a ADT_Vector */	
	if((st = ADT_Vector_set_comparator(v, user_equals)) != OK) {
		show_status(st);
		cla_destroy(cla);
		ADT_Vector_destroy(&v);
		array_destroy(data, IN_FILE_FIELDS);
		return st;
	}

	/* Crea un usuario temporal */
	if((st = user_create(&user_tmp)) != OK) {
		show_status(st);
		cla_destroy(cla);
		ADT_Vector_destroy(&v);
		array_destroy(data, IN_FILE_FIELDS);
		return st;
	}

	/* Lee linea por linea del archivo de entrada */
	while(fgets(buffer, IN_FILE_MAX_LEN, cla->fi)) {

		/* Separa la linea leida segun un caracter delimitador */
		string_split(buffer, data, IN_FILE_DELIM);

		/* Setea el usuario temporal con los datos obtenidos de la linea */
		user_set_data(user_tmp, data);

		amount = strtol(data[POS_AMOUNT], &endptr, 10);
		if(*endptr != '\0') return ERROR_CORRUPT_DATA;

		/* Transforma el tiempo de la linea leida a formato UNIX */
		get_date(&epoch, data);

		/* Comprueba que el tiempo de la linea leida no supere los argumentos ingresados */
		if(epoch < cla->ti) continue;
		else if(epoch > cla->tf) break;

		/* Busca el id del usuario en el vector */
		if((user = ADT_Vector_get_elem(v, user_tmp)) != NULL) {
			/* Si lo encuentra le suma el monto correspondiente */
			user_add_amount(user, amount);
		}
		else { 
			/* Si no lo encuentra crea un usuario nuevo */
			user_create(&user);
			user_set_data(user, data);

			/* Y lo agrega al vector */
			if((st = ADT_Vector_add(&v, user)) != OK){
				show_status(st);
				free(user_tmp);
				cla_destroy(cla);
				ADT_Vector_destroy(&v);
				array_destroy(data, IN_FILE_FIELDS);
				return st;
			}
		}
		clean_buffer(buffer);
		clean_array(data);
	}

	/* Ordena el vector con los usuarios */
	if((st = ADT_Vector_sort(v, user_comparator_credits_maxmin)) != OK) {
		show_status(st);
		free(user_tmp);
		cla_destroy(cla);
		ADT_Vector_destroy(&v);
		array_destroy(data, IN_FILE_FIELDS);
		return st;
	}

	/* Imprime el vector con los usuarios de acuerdo al argumento recibido */
	if(!strcmp(cla->fmt, "xml")) {
		if((st = ADT_Vector_export_as_xml(v, cla->fo, user_print_as_xml)) != OK) {
			show_status(st);
			free(user_tmp);
			cla_destroy(cla);
			ADT_Vector_destroy(&v);
			array_destroy(data, IN_FILE_FIELDS);
			return st;
		}
	}
	else if(!strcmp(cla->fmt,"csv")) {
		if((st = ADT_Vector_export_as_csv(v, cla->fo, user_print_as_csv)) != OK) {
			show_status(st);
			free(user_tmp);
			cla_destroy(cla);
			ADT_Vector_destroy(&v);
			array_destroy(data, IN_FILE_FIELDS);
			return st;
		}
	}

	free(user_tmp);
	cla_destroy(cla);
	ADT_Vector_destroy(&v);
	array_destroy(data, IN_FILE_FIELDS);
	return OK;
}
