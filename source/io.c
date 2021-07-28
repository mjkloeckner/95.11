#include "../include/io.h"


/*
//Lee los datos del archivo de entrada linea por linea mientras los procesa y asigna a un arreglo de usuarios
status_t process_file(cla_t cla, user_t **users, size_t *size)
{
	FILE *fpi;
	char *buffer, **data;
	time_t epoch;
	size_t alloc_size;
	user_t user, user_found, *tmp;
	status_t st;

	*size = 0;
	alloc_size = INIT_SIZE;
	user = user_found = NULL;

	if((fpi = fopen(cla->fi, "rt")) == NULL) {
		*users = NULL;
		return ERROR_OPENING_FILE;
	}

	if((data = (char **)malloc(sizeof(char *) * INPUT_FILE_FIELDS)) == NULL) {
		fclose(fpi);
		return ERROR_MEMORY;
	}

	if((buffer = calloc(sizeof(char), BUFFER_SIZE)) == NULL) {
		destroy_data(data);
		fclose(fpi);
		return ERROR_MEMORY;
	}

	if(user_create(&user) != OK) {
		free(buffer);
		destroy_data(data);
		fclose(fpi);
	}

	//En caso de haber algun error users no es liberado, se libera luego en main
	if(((*users) = (user_t *)malloc(sizeof(user_t) * INIT_SIZE)) == NULL) {
		free(buffer);
		free(user);
		destroy_data(data);
		fclose(fpi);
	}

	//Lee los datos de el archivo de entrada linea por linea 
	while(fgets(buffer, BUFFER_SIZE, fpi) != NULL) {
	//	Extiende el arreglo de usuarios en caso de que haya poca memoria
		if(*size == alloc_size) {
			alloc_size *= GROWTH_FACTOR;
			if((tmp = realloc((*users), alloc_size * sizeof(user_t))) == NULL) {
				fclose(fpi);
				free(buffer);
				destroy_data(data);
				return ERROR_MEMORY;
			}
			(*users) = tmp;
		}

	//	Divide el buffer en subarreglos segun un caracter delimitador
		if((st = string_split(buffer, data, INPUT_FILE_DELIM)) != OK) {
			fclose(fpi);
			free(buffer);
			destroy_data(data);
			return st;
		}

	//	Asigna a 'user' id, creditos y debitos cargados en data
		if((st = user_set_data(&user, data)) != OK) {
			destroy_data(data);
			free(buffer);
			fclose(fpi);
			return st;
		}

	//	Transforma la fecha leida a tiempo UNIX en segundos
		if((st = get_date(&epoch, data)) != OK) {
			destroy_data(data);
			free(buffer);
			fclose(fpi);
			return st;
		}

	//	Comprueba que la fecha leida este dentro del rango de fechas ingresadas en CLA
		if(epoch < cla->ti) continue;
		else if(epoch > cla->tf) {
			free(user);
			destroy_data(data);
			free(buffer);
			fclose(fpi);
			return OK;
		}

	//	Busca el numero de id en los usuarios ya ingresados, si no lo encuentra agrega un usuario nuevo al arreglo de usuarios
		if((user_found = user_find(*users, user->id, *size)) != NULL) {
			user_found->c += user->c;
			user_found->d += user->d;
		} else {
			(*users)[(*size)++] = user_dup(user);
		}

		user_clean(user);
		clean_data(data);
		clean_buffer(buffer);
	} // End while 

	free(user);
	destroy_data(data);
	free(buffer);
	fclose(fpi);
	return OK;
}
*/

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

status_t destroy_data(char **data)
{
	size_t i;

	if(data == NULL) return ERROR_NULL_POINTER;

	for(i = 0; i < INPUT_FILE_FIELDS; i++) {
		free(data[i]);
		data[i] = NULL;
	}

	free(data);
	return OK;
}

status_t export_data(cla_t cla, const user_t *users, size_t size)
{
	FILE *fo;

	if(users == NULL) return ERROR_NULL_POINTER;

	if((fo = fopen(cla->fo, "wt")) == NULL)
		return ERROR_OPENING_FILE;

	if(!strcmp(cla->fmt, "csv")) {
		export_data_as_csv(fo, users, size);
	} else if(!strcmp(cla->fmt, "xml")) {
		export_data_as_xml(fo, users, size);
	} else return ERROR_FORMAT_NOT_FOUND;

	fclose(fo);
	return OK;
}

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

