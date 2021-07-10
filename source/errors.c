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
