#include "../include/utils.h"

status_t string_split(char *s, char **data, char *delim)
{
	char *p, *tmp;
	size_t fields = 0;

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

status_t get_date(time_t *e, char **data)
{
	struct tm tm;

	if(e == NULL || data == NULL) return ERROR_NULL_POINTER;

	/* Desactiva el horario de verano */
	tm.tm_isdst = 0;

	switch(data[POS_TXN_DATE][2]) {
		case '/': 
			strptime(data[2], "%d/%m/%Y %H:%M:%S", &tm);
			*e = mktime(&tm);
			break;
		case '-':
			strptime(data[2], "%d-%m-%Y %H:%M:%S", &tm);
			*e = mktime(&tm);
			break;
		case '.':
			strptime(data[2], "%d.%m.%Y %H:%M:%S", &tm);
			*e = mktime(&tm);
			break;

		default: return ERROR_CORRUPT_DATA; break;
	}
	return OK;
}
