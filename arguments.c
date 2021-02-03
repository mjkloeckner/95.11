#include "arguments.h"

#define INPUT_ARGUMENT_FOUND_MSG 	"Encontre un '-in'\n"
#define OUTPUT_ARGUMENT_FOUND_MSG 	"Encontre un '-out'\n"

#define INPUT_FILE_NAME_MSG 	"\t -> Archivo de entrada: "
#define OUTPUT_FILE_NAME_MSG 	"\t -> Archivo de salida: "

//	Checks if the arguments are right;
status_t validate_arguments(int argc, char * argv[])
{
	if(argc == NO_CMD_ARGUMENTS)
		return ERROR_INVOCATING_PROGRAM;
	else if(argv == NULL)
		return ERROR_NULL_POINTER;

	return OK;
}

//	Valida que los argumentos esten correctos y guardas los nombres de los 
//	archivos de entrada y salida en src y dest respectivamente;
status_t set_files_name(int argc, char * argv[], char * src, char * dest)
{
	int i;
	status_t inputFile, outputFile;
	inputFile = outputFile = FILE_NOT_FOUND;

	for(i = 1; i < argc; i++) {
		if(!strcmp(argv[i], INPUT_ARGUMENT)) {
			printf(INPUT_ARGUMENT_FOUND_MSG);
			if(!strcmp(argv[i + 1], OUTPUT_ARGUMENT))
				return ERROR_INVOCATING_PROGRAM;

			strcpy(src, argv[++i]);
			printf(INPUT_FILE_NAME_MSG"'%s'\n", src);
			inputFile = OK;
		} else if(!strcmp(argv[i], OUTPUT_ARGUMENT)) {
			printf(OUTPUT_ARGUMENT_FOUND_MSG);
			if(!strcmp(argv[i + 1], INPUT_ARGUMENT))

				return ERROR_INVOCATING_PROGRAM;
			strcpy(dest, argv[++i]);
			printf(OUTPUT_FILE_NAME_MSG"'%s'\n", argv[i]);
			outputFile = OK;
		}
	}

//	Return error if it could get input or output file names;
	if((inputFile && outputFile) != OK)
		return ERROR_INVOCATING_PROGRAM;

	return OK;
}

