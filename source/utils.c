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

	for(i = 0, k = 0, sum = 0; i < 4; i++) {
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

status_t create_2darray(char ***arr, size_t r, size_t c) {
	size_t i;

	if(((*arr) = malloc(sizeof(char *) * r)) == NULL)
		return ERROR_MEMORY;

	for(i = 0; i < r; i++) {
		if(((*arr)[i] = calloc(sizeof(char), c)) == NULL) {
			destroy_2darray((*arr), c);
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
