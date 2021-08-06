#include "../include/load.h"

status_t load_users_to_vector(ADT_Vector_t **v, ADT_cla_t *cla)
{
	status_t st;
	char buffer[IN_FILE_MAX_LEN];
	char *endptr, **data;
	ADT_user_t *user, *user_tmp;
	time_t epoch;
	long long amount;
	ulong id, c, d;

	if(v == NULL || cla == NULL) return ERROR_NULL_POINTER;

	if((st = create_2darray(&data, IN_FILE_FIELDS, IN_FILE_FIELDS_MAX_LEN)) != OK)
		return st;

	/* Crea un usuario temporal */
	if((st = user_create(&user_tmp)) != OK) {
		destroy_2darray(data, IN_FILE_FIELDS);
		return st;
	}

	while(fgets(buffer, IN_FILE_MAX_LEN, cla->fi)) {
		if((st = string_split(buffer, data, IN_FILE_DELIM)) != OK) {
			free(user_tmp);
			destroy_2darray(data, IN_FILE_FIELDS);
			return st;
		}

		id = strtol(data[POS_USER_ID], &endptr, 10);
		if(*endptr != '\0') {
			free(user_tmp);
			destroy_2darray(data, IN_FILE_FIELDS);
			return ERROR_CORRUPT_DATA;
		}

		amount = strtol(data[POS_AMOUNT], &endptr, 10);
		if(*endptr != '\0') {
			free(user_tmp);
			destroy_2darray(data, IN_FILE_FIELDS);
			return ERROR_CORRUPT_DATA;
		}

		if(amount > 0) { c = amount; d = 0; }
		else if(amount < 0) { c = 0; d = -amount; }

		if((st = user_set_data(user_tmp, id, c, d)) != OK) {
			free(user_tmp);
			destroy_2darray(data, IN_FILE_FIELDS);
			return ERROR_CORRUPT_DATA;
		}

		if((st = get_date(&epoch, data[POS_TXN_DATE])) != OK){
			free(user_tmp);
			destroy_2darray(data, IN_FILE_FIELDS);
			return ERROR_CORRUPT_DATA;
		}

		/* Comprueba el que el tiempo este dentro de los valores pasados como argumentos */
		if(epoch < cla->ti) continue;
		else if(epoch > cla->tf) break;

		/* Comprueba que la tarjeta usada en la transaccion sea la correcta */
		if(!is_valid_card(data[POS_CARD_NUMBER])) {
			fprintf(stderr, "%s: %s\n",STR_INVALID_CARD_NUMBER, data[POS_CARD_NUMBER]);
			continue;
		}

		/* Busca el id del usuario en el vector */
		if((user = ADT_Vector_get_elem(*v, user_tmp)) != NULL) {
			/* Si lo encuentra le suma el monto correspondiente */
			if((st = user_add_amount(user, amount)) != OK) {
				destroy_2darray(data, IN_FILE_FIELDS);
				free(user_tmp);
				return st;
			}
		}

		/* Si no lo encuentra crea un usuario nuevo */
		else { 
			if((st = user_create(&user)) != OK) {
				destroy_2darray(data, IN_FILE_FIELDS);
				free(user_tmp);
				return st;
			}

			if((st = user_set_data(user, id, c, d))) {
				destroy_2darray(data, IN_FILE_FIELDS);
				free(user_tmp);
				return st;
			}

			/* Y lo agrega al vector */
			if((st = ADT_Vector_add(v, user)) != OK){
				destroy_2darray(data, IN_FILE_FIELDS);
				free(user_tmp);
				return st;
			}
		}
		clean_buffer(buffer);
		clean_array(data);
	} /* End while */

		
	destroy_2darray(data, IN_FILE_FIELDS);
	free(user_tmp);

	return OK;
}
