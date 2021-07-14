#ifndef TYPES__H
#define TYPES__H

#define STATUS_T_MAX 6

#define TMP_FILE_NAME "tmp.bin"

typedef enum {
	OK,
	ERROR_MISSING_ARGS,
	ERROR_WRONG_FLAGS,
	ERROR_FLAG_NOT_FOUND,
	ERROR_FLAG_REPEATED,
	ERROR_OPENING_FILE,
	ERROR_NULL_POINTER
} status_t;

typedef struct {
	int id, credit, debt;
} ADT_user_t, *user_t;

#endif
