#ifndef TYPES__H
#define TYPES__H

typedef enum {
	OK,
	ERROR_MISSING_ARGS,
	ERROR_WRONG_FLAGS,
	ERROR_FLAG_NOT_FOUND,
	ERROR_FLAG_REPEATED,
	ERROR_NULL_POINTER
} status_t;

#endif
