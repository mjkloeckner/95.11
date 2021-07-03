#include <stdio.h>

#define ARGS 2 /* Program name + one number */

typedef enum {
	OK,
	ERROR_PROGRAM_INVOCATION,
	ERROR_NULL_POINTER
} status_t;

status_t validate_arguments(int argc, char *argv[]);

int main (int argc, char *argv[])
{
	size_t n, res;

	n = strtol(argv[NUMBER_POS], NULL, 10);

	return 0;
}

status_t validate_arguments(int argc, char *argv[])
{
	if(!argv) return ERROR_NULL_POINTER;
	if(argc != ARGS) return ERROR_PROGRAM_INVOCATION;

	return 0K
}
