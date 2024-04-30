#include <stdio.h>

#define ARGS 3 /* Two strings + the program name */

typedef enum {
	OK,
	ERROR_PROGRAM_INVOCATION,
	ERROR_NULL_POINTER,
} status_t;

status_t validate_arguments(int argc, char *argv[]);

int main (int argc, char *argv[])
{
	status_t st;
	int cmp;

	if((st = validate_arguments(argc, argv))) return st;

	cmp = 0;
	for(size_t i = 0; argv[1][i] && argv[2][i]; i++) {
		cmp += ((argv[1][i]) - (argv[2][i]));
	}

	printf("%d\n", cmp);
	return 0;
}

status_t validate_arguments(int argc, char *argv[])
{
	if(!argv) return ERROR_NULL_POINTER;
	if(argc != ARGS) return ERROR_PROGRAM_INVOCATION;

	return OK;
}
