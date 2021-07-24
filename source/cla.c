#include "../include/cla.h"

const char *available_flags[] = { "-fmt", "-out", "-in", "-ti", "-tf" };
const char *available_formats[] = { "csv", "xml" };

status_t validate_arguments(int argc,  char **argv)
{
	status_t st;

	if(argv == NULL) return ERROR_NULL_POINTER;
	if((argc == NO_ARGS_ENTERED) || (argc != NORMAL_AMOUNT_ARGS))
		return ERROR_MISSING_ARGS;

	if((st = check_flags_position(argc, argv))) return st;
	if((st = check_flags_repeated(argc, argv))) return st;

	return OK;
}

/* No chequea argumentos ya que se considera subfuncion de validate_arguments */
status_t check_flags_position(int argc, char **argv)
{
	size_t i;
	bool prev_was_flag = 0;
	bool current_arg_is_flag = 0;

	for(i = 1; i < argc; i++, prev_was_flag = current_arg_is_flag) {
		if(argv[i][0] == '-') current_arg_is_flag = 1;
		else current_arg_is_flag = 0;

		if(current_arg_is_flag && prev_was_flag) return ERROR_WRONG_FLAGS;
	}
	return OK;
}

status_t check_flags_repeated(int argc, char **argv)
{
	size_t i, j, k, fflags_index;
	int founded_flags[FLAGS_MAX];

	/* Inicializa a -1 para evitar confusiones con 0 */
	for(i = 0; i < FLAGS_MAX; i++) founded_flags[i] = -1;

	for(i = 1, fflags_index = 0; i <= (argc - 2); i += 2) {
		for(j = 0; j < FLAGS_MAX; j++) {
			if(!strcmp(argv[i], available_flags[j])) {
				for(k = 0; k < FLAGS_MAX; k++) {
					if(founded_flags[k] == j) return ERROR_FLAG_REPEATED;
				}
				founded_flags[fflags_index++] = j;
				break;
			}
			if((j + 1) == FLAGS_MAX) return ERROR_FLAG_NOT_FOUND;
		}
	}
	return OK;
}

status_t cla_setup(int argc, char **argv, cla_t *cla)
{
	char *endptr;
	size_t i;
	flags_t f;

	for(i = 1; i < argc; i += 2) {
		for(f = FLAG_FMT; f < FLAGS_MAX; f++) {
			if(!strcmp(available_flags[f], argv[i])) {
				switch (f) {
					case FLAG_FMT: strcpy((*cla)->fmt, argv[i + 1]); break;
					case FLAG_OUT: strcpy((*cla)->fo, argv[i + 1]); break;
					case FLAG_IN: strcpy((*cla)->fi, argv[i + 1]); break;
					case FLAG_TI: 
								  (*cla)->ti = strtoul(argv[i + 1], &endptr, 10); 
								  if(*endptr != '\0') return ERROR_WRONG_TIME;
								  break;
					case FLAG_TF: 
								  (*cla)->tf = strtoul(argv[i + 1], &endptr, 10); 
								  if(*endptr != '\0') return ERROR_WRONG_TIME;
								  break;
					default: return ERROR_FLAG_NOT_FOUND;
				}
			}
		}
	}

	return OK;
}


status_t cla_create(cla_t *cla)
{
	if(cla == NULL) return ERROR_NULL_POINTER;

	if((*cla = (cla_t)malloc(sizeof(ADT_cla_t))) == NULL)
		return ERROR_MEMORY;

	if(((*cla)->fmt = calloc(sizeof(char), 100)) == NULL) {
		free(cla);
		cla = NULL;
		return ERROR_MEMORY;
	}

	if(((*cla)->fo = calloc(sizeof(char), 100)) == NULL) {
		free((*cla)->fmt);
		free(cla);
		cla = NULL;
		return ERROR_MEMORY;
	}

	if(((*cla)->fi = calloc(sizeof(char), 100)) == NULL) {
		free((*cla)->fo);
		free((*cla)->fmt);
		free(cla);
		cla = NULL;
		return ERROR_MEMORY;
	}

	return OK;
}

status_t cla_destroy(cla_t *cla)
{
	if(cla == NULL) return ERROR_NULL_POINTER;

	free((*cla)->fmt);
	free((*cla)->fo);
	free((*cla)->fi);
	free(*cla);

	cla = NULL;

	return OK;
}
