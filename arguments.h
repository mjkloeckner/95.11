#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include "main.h"
#include "macros.h"

#define INPUT_ARGUMENT_FOUND_MSG 	"Encontre un '-in'\n"
#define OUTPUT_ARGUMENT_FOUND_MSG 	"Encontre un '-out'\n"

#define INPUT_FILE_NAME_MSG 	"\t -> Archivo de entrada: "
#define OUTPUT_FILE_NAME_MSG 	"\t -> Archivo de salida: "

void print_error(status_t error);

status_t validate_arguments(int argc, char * argv[], char * src, char * dest);

#endif
