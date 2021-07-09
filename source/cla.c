#include "cla.h"
#include <bool.h>

status_t validate_arguments(int argc, char *argv[])
{
	if(argv == NULL) return ERROR_NULL_POINTER;
	if(argc == NO_ARGS_ENTERED || argc != NORMAL_AMOUNT_ARGS)
		return ERROR_MISSING_ARGS;

	bool prev_was_flag = 0;
	bool current_arg_is_flag = 0;
	for(size_t i = 1; i < argc; i++, prev_was_flag = current_arg_is_flag) {
		if(argv[i][0] == '-') current_arg_is_flag = 1;
		else current_arg_is_flag = 0;

		if(current_arg_is_flag && prev_was_flag) return ERROR_WRONG_FLAGS;
	}

	return OK;
}
