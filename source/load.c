#include "../include/load.h"

status_t load_users_to_vector(ADT_Vector_t **v, ADT_cla_t *cla)
{
	status_t st;
	char buffer[IN_FILE_MAX_LEN];
	char *endptr1, *endptr2, **data;
	ADT_user_t *u1, *u2, *u3;
	time_t epoch;
	long long amount;
	size_t user_pos, parsed_lines;
	ulong id, c, d;

	if(v == NULL || cla == NULL) return ERROR_NULL_POINTER;

	if((st = create_2darray(&data, IN_FILE_FIELDS, IN_FILE_FIELDS_MAX_LEN)) != OK)
		return st;

	parsed_lines = 0;
	while(fgets(buffer, IN_FILE_MAX_LEN, cla->fi)) {
		if((st = user_create(&u1)) != OK) {
			destroy_2darray(data, IN_FILE_FIELDS);
			return st;
		}

		if((st = string_split(buffer, data, IN_FILE_DELIM)) != OK) {
			free(u1);
			destroy_2darray(data, IN_FILE_FIELDS);
			return st;
		}

		id = strtol(data[POS_USER_ID], &endptr1, 10);
		amount = strtol(data[POS_AMOUNT], &endptr2, 10);

		if(*endptr1 || *endptr2) {
			free(u1);
			destroy_2darray(data, IN_FILE_FIELDS);
			return ERROR_CORRUPT_DATA;
		}

		if(amount > 0) { c = amount; d = 0; }
		else if(amount < 0) { c = 0; d = -amount; }

		if((st = user_set_data(u1, id, c, d)) != OK) {
			free(u1);
			destroy_2darray(data, IN_FILE_FIELDS);
			return ERROR_CORRUPT_DATA;
		}

		if((st = get_date(&epoch, data[POS_TXN_DATE])) != OK){
			free(u1);
			destroy_2darray(data, IN_FILE_FIELDS);
			return ERROR_CORRUPT_DATA;
		}

		/* Comprueba el que el tiempo este dentro de los valores pasados como argumentos */
		if(epoch < cla->ti) continue;
		else if(epoch > cla->tf) break;

		/* Comprueba que la tarjeta usada en la transaccion sea la correcta */
		if(!is_valid_card(data[POS_CARD_NUMBER])) {
			fprintf(stderr, "%s: %s\n", STR_INVALID_CARD_NUMBER, data[POS_CARD_NUMBER]);
			continue;
		}

		/* Busca el id del usuario en el vector */
		if((st = ADT_Vector_get_elem_pos(*v, u1, &user_pos)) == OK) {
			/* Si llega aca lo encontró, entonces se lo asigna a un usuario temporal */
			if((st = ADT_Vector_get_elem(*v, (void **)&u2, user_pos) != OK)) {
				destroy_2darray(data, IN_FILE_FIELDS);
				free(u1);
				return st;
			}

			/* Crea un usuario nuevo para almacenar la copia */
			if((st = user_create(&u3)) != OK) {
				destroy_2darray(data, IN_FILE_FIELDS);
				free(u1);
				return st;
			}

			/* Copia el contenido del usuario */
			*u3 = *u2;

			/* Asigna a la copia el nuevo monto */
			if(amount > 0) u3->c += amount;
			else if(amount < 0) u2->d -= amount;

			/* Asigna la copia al vector en el lugar que estaba el usuario original */
			if((st = ADT_Vector_set_elem(v, u3, user_pos)) != OK) {
				destroy_2darray(data, IN_FILE_FIELDS);
				free(u1);
			}

			free(u1);
			free(u2);
		}

		/* Hubo un error distinto a no encontrar el usuario */
		else if(st != ELEM_NOT_FOUND) {
				destroy_2darray(data, IN_FILE_FIELDS);
				return st;
		}

		else { 
			/* Si no lo encuentra entonces lo agrega al vector */
			if((st = ADT_Vector_add(v, u1)) != OK){
				destroy_2darray(data, IN_FILE_FIELDS);
				return st;
			}
		}
		clean_buffer(buffer); clean_array(data);
		parsed_lines++;
	} /* End while */

	destroy_2darray(data, IN_FILE_FIELDS);
	printf("%s%8ld\n", STR_MSG_END_PROCSS, parsed_lines);

	return OK;
}
