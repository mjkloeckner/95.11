#include "../include/status.h"

#ifdef __DEBUG_MODE__

const char *status_strings[] = {
	"(OK)",
	"(ELEM_NOT_FOUND)",
	"(ERROR_MEMORY)",
	"(ERROR_WRONG_FLAGS)",
	"(ERROR_WRONG_TIME)",
	"(ERROR_INVALID_POS)"
	"(ERROR_MISSING_ARGS)",
	"(ERROR_OPENING_FILE)",
	"(ERROR_CORRUPT_DATA)",
	"(ERROR_FLAG_REPEATED)",
	"(ERROR_FLAG_NOT_FOUND)",
	"(ERROR_FORMAT_NOT_FOUND)",
	"(ERROR_NULL_POINTER)"
};

#else

const char *status_strings[] = {
	"Todo se ejecuto correctamente.\nTenga un buen dia.",
	"El elemento no pertenece al vector.",
	"ERROR: Hubo un problema con la memoria, puede que sea escasa.",
	"ERROR: No se reconoce un argumento.",
	"ERROR: El tiempo ingresado no es correcto.",
	"ERROR: En los argumentos ingresados.",
	"ERROR: Faltan argumentos.",
	"ERROR: El archivo de se pudo abrir, puede que no exista o el nombre sea incorrecto.",
	"ERROR: Puede que el archivo de entrada este vacio, corrupto o no se encuentre.",
	"ERROR: Hay una flag repetida.",
	"ERROR: Flag no encontrada.",
	"ERROR: El formato de salida no se reconoce.",
	"ERROR: Hubo un problema durante la ejecucion."
};

#endif

void show_status(status_t st)
{
	fprintf(stderr, "\n%s\n", status_strings[st]);
}
