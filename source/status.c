#include "../include/status.h"

const char *status_strings[] = {
	"Everything executed succesfully. Have a nice day.",
	"There is a problem with the memory",
	"There is a flags misspeled",
	"There is a problem with entered time",
	"There are arguments missing",
	"Error el archivo de se pudo abrir, puede que no existe o que el nombre sea incorrecto",
	"Error al leer un dato, puede que el archivo de entrada este corrupto",
	"Error hay una flag repetida",
	"Error flag no encontrada",
	"Error el formato de salida no se reconoce",
	"Error usuario no encontrado, puede que el archivo de entrada este corrupto",
	"ERROR_NULL_POINTER"
};

void show_status(status_t st)
{
	fprintf(stderr, "\n%s\n", status_strings[st]);
}
