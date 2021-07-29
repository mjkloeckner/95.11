#include "../include/io.h"

status_t string_split(char *s, char **data, char *delim)
{
	char *p, *tmp;
	size_t fields = 0;

	for(p = s; (tmp = strtok(p, delim)); p = NULL)
		strcpy(data[fields++], tmp);

	if(fields != INPUT_FILE_FIELDS)
		return ERROR_CORRUPT_DATA;

	return OK;
}

status_t destroy_data(char **data, size_t fields)
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
/*
status_t export_data_as_csv(FILE *fo, const user_t *users, size_t size)
{
	size_t i;

	if(fo == NULL || users == NULL)
		return ERROR_NULL_POINTER;

	for(i = 0; i < size; i++)
		fprintf(fo, "%ld%s%ld%s%ld\n", users[i]->id, CSV_OUTPUT_DELIM,\
				users[i]->c, CSV_OUTPUT_DELIM, users[i]->d);

	return OK;
}

status_t export_data_as_xml(FILE *fo, const user_t *users, size_t size)
{
	size_t i;

	if(fo == NULL || users == NULL)
		return ERROR_NULL_POINTER;

	fprintf(fo, "%s\n%s\n", XML_HEADER, XML_ROOT_OPEN);

	for(i = 0; i < size; i++) {
		fprintf(fo, "\t%s\n", XML_ROW_OPEN);
		fprintf(fo, "\t\t%s%ld%s\n", XML_ID_OPEN, users[i]->id, XML_ID_CLOSE);
		fprintf(fo, "\t\t%s%ld%s\n", XML_CREDIT_OPEN, users[i]->c, XML_CREDIT_CLOSE);
		fprintf(fo, "\t\t%s%ld%s\n", XML_DEBT_OPEN, users[i]->d, XML_DEBT_CLOSE);
		fprintf(fo, "\t%s\n", XML_ROW_CLOSE);
	}

	fprintf(fo, "%s\n", XML_ROOT_CLOSE);
	return OK;
}
*/
void clean_buffer(char *buf)
{
	size_t i;

	for(i = 0; i < BUFFER_SIZE; i++)
		buf[i] = '\0';
}

void clean_data(char **data)
{
	size_t i;

	for(i = 0; i < INPUT_FILE_FIELDS; i++) {
		free(data[i]);
		data[i] = NULL;
	}
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
