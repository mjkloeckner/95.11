#include "../include/io.h"

status_t output_gen(cla_t cla)
{
	FILE *fpi, *fpo;
	char *buffer;
	user_t user;

	if((fpi = fopen(cla->fi, "rt")) == NULL) return ERROR_OPENING_FILE;
	if((fpo = fopen(cla->fo, "wt")) == NULL) return ERROR_OPENING_FILE;

	buffer = calloc(sizeof(char), 1000);

	if(fgets(buffer, 1000, fpi) == NULL) return ERROR_NULL_POINTER;

	get_data(buffer, &user);

	return OK;
}

status_t get_data(char *buf, user_t *user)
{
	(*user) = (user_t)malloc(sizeof(user_t));

	printf("%s", buf);

	return OK;
}
