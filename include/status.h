#ifndef STATUS__H
#define STATUS__H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define ERROR_RETRY_MSG "Verifique y vuelva a intentar"
#define EXIT_SUCCESS_MSG "Ejecución terminada exitosamente"
#define USERS_REGISTERED_MSG	"Usuarios registrados: "
#define PROCESED_LINES_MSG		"Lineas procesadas: "

#define STATUS_T_MAX 12

typedef enum {
	OK,
	ERROR_MEMORY,
	ERROR_WRONG_FLAGS,
	ERROR_WRONG_TIME,
	ERROR_INVALID_POS,
	ERROR_MISSING_ARGS,
	ERROR_OPENING_FILE,
	ERROR_CORRUPT_DATA,
	ERROR_FLAG_REPEATED,
	ERROR_FLAG_NOT_FOUND,
	ERROR_FORMAT_NOT_FOUND,
	ERROR_USER_NOT_FOUND,
	ERROR_NULL_POINTER
} status_t;

typedef enum {
	POS_ID_TXN,
	POS_USER_ID,
	POS_TXN_DATE,
	POS_AMOUNT,
	POS_CARD_NUMBER,
	POS_DESC
} csv_pos_t;

void show_status(status_t st);
void free_arrays(size_t num,...);

extern const char *status_strings[STATUS_T_MAX];

#endif
