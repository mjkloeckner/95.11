#include "arguments.h"

//	Valida que los argumentos esten correctos y guarda los nombres de los 
//	archivos de entrada y salida en src y dest respectivamente;
status_t validate_arguments(int argc, char * argv[], char * src, char * dest)
{
	if(argc == NO_CMD_ARGUMENTS)
		return ERROR_INVOCATING_PROGRAM;
	else if(argc == ONE_CMD_ARGUMENT)
		return ERROR_INVOCATING_PROGRAM;
	else if(argv == NULL)
		return ERROR_NULL_POINTER;

	int i;
	status_t inputFile, outputFile;
	inputFile = outputFile = IO_FILE_NOT_FOUND;

	for(i = 1; i < argc; i++) {
//		Comprueba que el primer argumento sea INPUT_ARGUMENT ('-in');
		if(!strcmp(argv[i], INPUT_ARGUMENT)) {
			printf(INPUT_ARGUMENT_FOUND_MSG);

//			Si el argumento que sigue es OUTPUT_ARGUMENT entonces hay un error
//			en la invocacion de el programa;
			if(!strcmp(argv[i + 1], OUTPUT_ARGUMENT))
				return ERROR_INVOCATING_PROGRAM;

//			Si el primer argumento esta bien y el siguiente es una cadena entonces
//			guarda en src la cadena e imprime dicha cadena;
			strcpy(src, argv[++i]);
			printf(INPUT_FILE_NAME_MSG"'%s'\n", src);

//			Marca el archivo de entrada como encontrado;
			inputFile = OK;

//		Procede de la misma forma pero para OUTPUT_ARGUMENT ('-out');
		} else if(!strcmp(argv[i], OUTPUT_ARGUMENT)) {
			printf(OUTPUT_ARGUMENT_FOUND_MSG);
			if(!strcmp(argv[i + 1], INPUT_ARGUMENT))
				return ERROR_INVOCATING_PROGRAM;

			strcpy(dest, argv[++i]);
			printf(OUTPUT_FILE_NAME_MSG"'%s'\n", argv[i]);
			outputFile = OK;
		}
	}

//	Si uno o ambos de los argumentos no se encontro entonces imprime un codigo 
//	de error;
	if((inputFile && outputFile) != OK)
		return IO_FILE_NOT_FOUND;

	return OK;
}

bool file_are_the_same(char *file1, char *file2)
{
	if(strcmp(file1, file2))
		return true;

	return false;
}
