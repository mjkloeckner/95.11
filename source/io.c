#include "../include/io.h"

#define INIT_SIZE		1000
#define GROWTH_FACTOR 	2

user_t find_user(const user_t *users, int id, size_t size);
status_t destroy_data(char **data);

status_t get_date(time_t *e, char **data);

void user_clean(user_t usr);
void clean_buffer(char *buf);
void clean_data(char **data);

user_t user_dup(user_t src);

/* Lee los datos del archivo de entrada linea por linea mientras los procesa y asigna a un arreglo de usuarios */
status_t process_file(cla_t cla, user_t **users, size_t *size)
{
	FILE *fpi;
	char *buffer, **data;
	time_t epoch;
	size_t alloc_size;
	user_t user, user_found, *tmp;
	status_t st;

	*size = cla->parsed_lines = 0;
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

	/* En caso de haber algun error users no es liberado, se libera luego en main */
	if(((*users) = (user_t *)malloc(sizeof(user_t) * INIT_SIZE)) == NULL) {
		free(buffer);
		free(user);
		destroy_data(data);
		fclose(fpi);
	}

	/* Lee los datos de el archivo de entrada linea por linea */ 
	while(fgets(buffer, BUFFER_SIZE, fpi) != NULL) {
		/* Extiende el arreglo de usuarios en caso de que haya poca memoria */
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

		/* Divide el buffer en subarreglos segun un caracter delimitador */
		if((st = string_split(buffer, data, INPUT_FILE_DELIM)) != OK) {
			fclose(fpi);
			free(buffer);
			destroy_data(data);
			return st;
		}

		/* Asigna a 'user' id, creditos y debitos cargados en data */
		if((st = set_data(&user, data)) != OK) {
			destroy_data(data);
			free(buffer);
			fclose(fpi);
			return st;
		}

		/* Transforma la fecha leida a tiempo UNIX en segundos */
		if((st = get_date(&epoch, data)) != OK) {
			destroy_data(data);
			free(buffer);
			fclose(fpi);
			return st;
		}

		/* Comprueba que la fecha leida este dentro del rango de fechas ingresadas en CLA */
		if(epoch < cla->ti) continue;
		else if(epoch > cla->tf) {
			free(user);
			destroy_data(data);
			free(buffer);
			fclose(fpi);
			return OK;
		}

		/* Busca el numero de id en los usuarios ya ingresados, si no lo encuentra agrega un usuario nuevo al arreglo de usuarios */
		if((user_found = find_user(*users, user->id, *size)) != NULL) {
			user_found->credit += user->credit;
			user_found->debt += user->debt;
		} else {
			(*users)[(*size)++] = user_dup(user);
		}

		cla->parsed_lines++;

		user_clean(user);
		clean_data(data);
		clean_buffer(buffer);
	} /* End while */

	free(user);
	destroy_data(data);
	free(buffer);
	fclose(fpi);
	return OK;
}

status_t set_data(user_t *user, char **data) 
{
	if(data == NULL || user == NULL) return ERROR_NULL_POINTER;

	char *endptr;
	long amount;

	(*user)->id = strtol(data[POS_USER_ID], &endptr, 10);
	if(*endptr != '\0') return ERROR_CORRUPT_DATA;

	amount = strtol(data[POS_AMOUNT], &endptr, 10);
	if(*endptr != '\0') return ERROR_CORRUPT_DATA;

	if(amount > 0) (*user)->credit = amount;
	else if(amount < 0) (*user)->debt = -amount; /* '-=' Para eliminar el menos	*/

	return OK;
}

status_t string_split(char *s, char **data, char *delim)
{
	char *p, *tmp;
	size_t fields = 0;

	for(p = s; (tmp = strtok(p, delim)); p = NULL)
		data[fields++] = strdup(tmp);

	if(fields != INPUT_FILE_FIELDS)
		return ERROR_CORRUPT_DATA;

	return OK;
}


status_t destroy_users(user_t *users, size_t size)
{
	if(users == NULL) return ERROR_NULL_POINTER;

	for(size_t i = 0; i < size; i++)
		free(users[i]);

	free(users);
	return OK;
}

status_t destroy_data(char **data)
{
	if(data == NULL) return ERROR_NULL_POINTER;

	for(size_t i = 0; i < INPUT_FILE_FIELDS; i++) {
		free(data[i]);
		data[i] = NULL;
	}

	free(data);
	return OK;
}

status_t export_data(cla_t cla, const user_t *users, size_t size)
{
	if(users == NULL) return ERROR_NULL_POINTER;

	FILE *fo;

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
	if(fo == NULL || users == NULL)
		return ERROR_NULL_POINTER;

	for(size_t i = 0; i < size; i++)
		fprintf(fo, "%ld%s%ld%s%ld\n", users[i]->id, CSV_OUTPUT_DELIM,\
				users[i]->credit, CSV_OUTPUT_DELIM, users[i]->debt);

	return OK;
}

status_t export_data_as_xml(FILE *fo, const user_t *users, size_t size)
{
	if(fo == NULL || users == NULL)
		return ERROR_NULL_POINTER;

	fprintf(fo, "%s\n%s\n", XML_HEADER, XML_ROOT_OPEN);
	for(size_t i = 0; i < size; i++) {
		fprintf(fo, "\t%s\n", XML_ROW_OPEN);
		fprintf(fo, "\t\t%s%ld%s\n", XML_ID_OPEN, users[i]->id, XML_ID_CLOSE);
		fprintf(fo, "\t\t%s%ld%s\n", XML_CREDIT_OPEN, users[i]->credit, XML_CREDIT_CLOSE);
		fprintf(fo, "\t\t%s%ld%s\n", XML_DEBT_OPEN, users[i]->debt, XML_DEBT_CLOSE);
		fprintf(fo, "\t%s\n", XML_ROW_CLOSE);
	}

	fprintf(fo, "%s\n", XML_ROOT_CLOSE);
	return OK;
}

void clean_buffer(char *buf)
{
	for(size_t i = 0; i < BUFFER_SIZE; i++)
		buf[i] = '\0';
}

void clean_data(char **data)
{
	for(size_t i = 0; i < INPUT_FILE_FIELDS; i++) {
		free(data[i]);
		data[i] = NULL;
	}
}

status_t get_date(time_t *e, char **data)
{
	if(e == NULL || data == NULL) return ERROR_NULL_POINTER;

	struct tm tm;

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

void user_clean(user_t usr)
{
	usr->id = 0;
	usr->credit = 0;
	usr->debt = 0;
}

status_t user_set_data(user_t usr, int id, long credit, long debt)
{
	usr->id = id;
	usr->credit = credit;
	usr->debt = debt;

	return OK;
}

user_t user_dup(user_t src)
{
	user_t dst = NULL;

	user_create(&dst);

	dst->id = src->id;
	dst->credit = src->credit;
	dst->debt = src->debt;

	return dst;
}

status_t user_create(user_t *usr)
{
	if(((*usr) = (user_t)malloc(sizeof(ADT_user_t))) == NULL)
		return ERROR_MEMORY;

	(*usr)->id = 0;
	(*usr)->credit = 0;
	(*usr)->debt = 0;

	return OK;
}

user_t find_user(const user_t *users, int id, size_t size)
{
	for(size_t i = 0; i < size; i++) {
		if(users[i]->id == id) {
			return users[i];
		}
	}
	return NULL;
}
