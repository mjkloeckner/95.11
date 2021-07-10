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
	bool prev_was_flag = 0;
	bool current_arg_is_flag = 0;
	for(size_t i = 1; i < argc; i++, prev_was_flag = current_arg_is_flag) {
		if(argv[i][0] == '-') current_arg_is_flag = 1;
		else current_arg_is_flag = 0;

		if(current_arg_is_flag && prev_was_flag) return ERROR_WRONG_FLAGS;
	}
	return OK;
}

/* Need to add a record for already founded flags */
status_t check_flags_repeated(int argc, char **argv)
{
	size_t i, j, fflags_index;
	int founded_flags[FLAGS_MAX];

	/* Inicializa a -1 para evitar confuciones con 0 */
	for(i = 0; i < FLAGS_MAX; i++) founded_flags[i] = -1;

	for(i = 1, fflags_index = 0; i <= (argc - 2); i += 2) {
		for(j = 0; j < FLAGS_MAX; j++) {
			if(!strcmp(argv[i], available_flags[j])) {
				for(size_t k = 0; k < FLAGS_MAX; k++) {
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
