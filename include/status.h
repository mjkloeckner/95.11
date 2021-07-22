#ifndef STATUS__H
#define STATUS__H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define ERROR_RETRY_MSG "Verifique y vuelva a intentar"

#define STATUS_T_MAX 12

typedef enum {
	OK,
	ERROR_MEMORY,
	ERROR_WRONG_FLAGS,
	ERROR_WRONG_TIME,
	ERROR_MISSING_ARGS,
	ERROR_OPENING_FILE,
	ERROR_CORRUPT_DATA,
	ERROR_FLAG_REPEATED,
	ERROR_FLAG_NOT_FOUND,
	ERROR_FORMAT_NOT_FOUND,
	ERROR_USER_NOT_FOUND,
	ERROR_NULL_POINTER
} status_t;

typedef struct {
	size_t id;
	long credit, debt;
} ADT_user_t, *user_t;

void show_status(status_t st);
void free_arrays(size_t num,...);

extern const char *status_strings[STATUS_T_MAX];

#endif
