#include "../include/utils.h"

status_t string_split(char *s, char **data, char *delim)
{
	char *p, *tmp;
	size_t fields = 0;

	if(s == NULL || data == NULL || delim == NULL)
		return ERROR_NULL_POINTER;

	for(p = s; (tmp = strtok(p, delim)); p = NULL)
		strcpy(data[fields++], tmp);

	if(fields != IN_FILE_FIELDS)
		return ERROR_CORRUPT_DATA;

	return OK;
}


void clean_buffer(char *buf)
{
	size_t i;

	for(i = 0; i < IN_FILE_MAX_LEN; i++)
		buf[i] = '\0';
}

void clean_array(char **data)
{
	size_t i, j;

	for(i = 0; i < IN_FILE_FIELDS; i++) {
		for(j = 0; j < IN_FILE_FIELDS_MAX_LEN; j++)
			data[i][j] = '\0';
	}
}

status_t array_destroy(char **data, size_t fields)
{
	size_t i;

	if(data == NULL) return ERROR_NULL_POINTER;

	for(i = 0; i < fields; i++) {
		free(data[i]);
		data[i] = NULL;
	}

	free(data);
	return OK;
}

status_t get_date(time_t *e, char *str)
{
	struct tm tm;

	if(e == NULL || str == NULL) return ERROR_NULL_POINTER;

	/* Desactiva el horario de verano */
	tm.tm_isdst = 0;

	switch(str[2]) {
		case '/': 
			strptime(str, "%d/%m/%Y %H:%M:%S", &tm);
			*e = mktime(&tm);
			break;
		case '-':
			strptime(str, "%d-%m-%Y %H:%M:%S", &tm);
			*e = mktime(&tm);
			break;
		case '.':
			strptime(str, "%d.%m.%Y %H:%M:%S", &tm);
			*e = mktime(&tm);
			break;

		default: return ERROR_CORRUPT_DATA; break;
	}
	return OK;
}

bool is_valid_card(char *card_no)
{
	size_t i, j, k;
	int arr[4][4], sum;
	char tmp[2];

	if(card_no == NULL) return false;
	if(strlen(card_no) != CARD_NO_VALID_LEN) return false;

	for(i = 0, k = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			arr[i][j] = (card_no[k++] - '0');
			if(j % 2) {
				arr[i][j] *= 2;
				sprintf(tmp, "%d", arr[i][j]);
				if(!(strlen(tmp) - 1)) arr[i][j] = (tmp[0] - '0');
				else arr[i][j] = ((tmp[0] - '0') + (tmp[1] - '0'));

			}
			sum += arr[i][j];
		}
	}

	return (sum % 10) ? false : true;
}

status_t create_2darray(char **arr, size_t r, size_t c) {
	size_t i;

	if((arr = malloc(sizeof(char *) * r)) == NULL)
		return ERROR_MEMORY;

	for(i = 0; i < r; i++) {
		if((arr[i] = calloc(sizeof(char), c)) == NULL) {
			destroy_2darray(arr, c);
			return ERROR_MEMORY;
		}
	}

	return OK;
}

status_t destroy_2darray(char **arr, size_t r)
{
	size_t i;

	if(arr == NULL) return ERROR_NULL_POINTER;

	for(i = 0; i < r; i++) {
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
	return OK;
}

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

	if((st = create_2darray(data, IN_FILE_FIELDS, IN_FILE_FIELDS_MAX_LEN)) != OK)
		return st;

	/* Crea un usuario temporal */
	if((st = user_create(&user_tmp)) != OK) {
		array_destroy(data, IN_FILE_FIELDS);
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
