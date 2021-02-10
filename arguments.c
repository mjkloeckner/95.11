#include "arguments.h"

//	Valida que los argumentos esten correctos y guarda los nombres de los 
//	archivos de entrada y salida en src y dest respectivamente;
status_t validate_arguments(int argc, char * argv[], char * src, char * dest)
{
	if(argc < EXPECTED_CMD_ARGUMENTS || argc > EXPECTED_CMD_ARGUMENTS)
		return ERROR_INVOCATING_PROGRAM;
	else if(argv == NULL)
		return ERROR_NULL_POINTER;

	status_t inputFile, outputFile;
	inputFile = outputFile = IO_FILE_NOT_FOUND;

	size_t i;
	for(i = 1; i < argc; i++) {
//		Comprueba que el primer argumento sea INPUT_ARGUMENT ('-in');
		if(!strcmp(argv[i], INPUT_ARGUMENT)) {

//			Si el argumento que sigue es OUTPUT_ARGUMENT entonces hay un error
//			en la invocacion de el programa, y si el que le sigue a ese no es
//			OUTPUT_ARGUMENT estamos ante un problema de orden de argumentos;
			if(!strcmp(argv[i + 1], OUTPUT_ARGUMENT))
				return ERROR_INVOCATING_PROGRAM;

//			Si el primer argumento esta bien y el siguiente es una cadena entonces
//			guarda en src la cadena e imprime dicha cadena;
			strcpy(src, argv[++i]);

			printf(INPUT_ARGUMENT_FOUND_MSG);
			printf(INPUT_FILE_NAME_MSG"'%s'\n", src);

//			Marca el archivo de entrada como encontrado;
			inputFile = OK;

//		Procede de la misma forma pero para OUTPUT_ARGUMENT ('-out');
		} else if(!strcmp(argv[i], OUTPUT_ARGUMENT)) {

			if(!strcmp(argv[i + 1], INPUT_ARGUMENT))
				return ERROR_INVOCATING_PROGRAM;

			strcpy(dest, argv[++i]);

			printf(OUTPUT_ARGUMENT_FOUND_MSG);
			printf(OUTPUT_FILE_NAME_MSG"'%s'\n", dest);

			outputFile = OK;
		}
	}

//	Si uno o ambos de los argumentos no se encontro entonces imprime un codigo 
//	de error;
	if((inputFile && outputFile) != OK)
		return ERROR_INVOCATING_PROGRAM;

	return OK;
}


