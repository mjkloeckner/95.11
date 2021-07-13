#include "../include/errors.h"

const char *status_strings[] = {
	"Everything executed succesfully. Have a nice day.",
	"There are arguments missing",
	"There is a flags misspeled",
	"ERROR_FLAG_NOT_FOUND_",
	"ERROR_FLAG_REPEATED_",
	"ERROR_NULL_POINTER_"
};

void show_status(status_t st)
{
	fprintf(stderr, "%s\n", status_strings[st]);
}

void free_arrays(size_t num,...)
{
	va_list valist;
	size_t i;

	va_start(valist, num);

	for(i = 0; i < num; i++)
		free(va_arg(valist, char *));
}

void close_streams(size_t num,...)
{
	va_list valist;
	size_t i;

	va_start(valist, num);

	for(i = 0; i < num; i++)
		free(va_arg(valist, FILE *));
}
