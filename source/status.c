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
	fprintf(stderr, "%s\n", ERROR_RETRY_MSG);
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
