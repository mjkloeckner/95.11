#include "../include/io.h"

void print_user(const user_t user);
status_t write_tmp_file(FILE *bfp, const user_t user);
status_t read_tmp_file(FILE *bfp, user_t user);
status_t load_values(FILE *);

/* Lee los datos de el archivo de entrada linea por linea 
 * y los imprime en un archivo binario temporal */
status_t tmp_gen(cla_t cla, FILE **bfp)
{
	FILE *fpi, *fpo;
	char *buffer, **data;
	user_t user;
	status_t st;

	if((fpi = fopen(cla->fi, "rt")) == NULL) return ERROR_OPENING_FILE;

	if((fpo = fopen(cla->fo, "wt")) == NULL) return ERROR_OPENING_FILE;

	if(((*bfp) = fopen(TMP_FILE_NAME, "wb")) == NULL) return ERROR_OPENING_FILE;

	data = (char **)malloc(sizeof(char *) * INPUT_FILE_FIELDS);

	for(size_t i = 0; i < INPUT_FILE_FIELDS; i++)
		data[i] = calloc(sizeof(char), BUFFER_SIZE);

	buffer = calloc(sizeof(char), BUFFER_SIZE);

	/* Lee los datos de el archivo de entrada linea por linea 
	 * y los imprime en un archivo binario temporal */
	while(fgets(buffer, BUFFER_SIZE, fpi) != NULL) {
		if((st = split(buffer, data))) return st;
		if((st = set_data(&user, data))) return st;
		write_tmp_file((*bfp), user);
	}

	fclose(fpi);
	fclose(fpo);
	return OK;
}

status_t set_data(user_t *user, char **data) 
{
	int amount;

	(*user) = (user_t)malloc(sizeof(user_t));

	(*user)->id = strtol(data[POS_USER_ID], NULL, 10);

	amount = strtol(data[POS_AMOUNT], NULL, 10);

	if(amount > 0) (*user)->credit += amount;
	else if(amount < 0) (*user)->debt += amount;

	return OK;
}

status_t split(char *s, char **data)
{
	char *p;
	size_t fields = 0;
	for(p = s; (data[fields++] = strtok(p, ",")); p = NULL);

	return OK;
}

void print_user(const user_t user)
{
	printf("ID: %5d CREDITS: %5d DEBITS: %5d\n", user->id, user->credit, user->debt);
}

status_t write_tmp_file(FILE *bfp, const user_t user)
{
	if(bfp == NULL) return ERROR_NULL_POINTER;

	fwrite(user, 1, sizeof(ADT_user_t), bfp);

	return OK;
}

status_t read_tmp_file(FILE *bfp, user_t user)
{
	if(bfp == NULL || user == NULL) return ERROR_NULL_POINTER;

	fread(user, 1, sizeof(ADT_user_t), bfp);

	return OK;
}
