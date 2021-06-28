#include <stdio.h>

#define ARGS

typedef enum {
	OK,
	ERROR_NO_ARGUMENT,
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

	printf("%s\n", cmp ? "Son distintas" : "Son iguales");
	return 0;
}

status_t validate_arguments(int argc, char *argv[])
{
	return OK;
}
