#include "../include/status.h"

const char *status_strings[] = {
	"Everything executed succesfully. Have a nice day.",
	"El elemento no pertenece al vector (ELEM_NOT_FOUND)",
	"Error hubo un problema con la memoria, puede que sea escasa (ERROR_MEMORY)",
	"There is a flags misspeled",
	"There is a problem with entered time",
	"Error en los argumentos ingresados (ERROR_INVALID_POS)"
	"Error faltan argumentos (ERROR_MISSING_ARGS)",
	"Error el archivo de se pudo abrir, puede que no existe o que el nombre sea incorrecto",
	"Error al leer un dato, puede que el archivo de entrada este corrupto",
	"Error hay una flag repetida",
	"Error flag no encontrada",
	"Error el formato de salida no se reconoce",
	"Hubo un problema durante la ejecucion (ERROR_NULL_POINTER)"
};

void show_status(status_t st)
{
	fprintf(stderr, "\n%s\n", status_strings[st]);
}
