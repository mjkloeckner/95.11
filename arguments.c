#include "arguments.h"


//	Checks if the arguments are right;
status_t validate_arguments(int argc, char * argv[])
{
	if(argc == NO_CMD_ARGUMENTS)
		return ERROR_INVOCATING_PROGRAM;
	else if(argv == NULL)
		return ERROR_NULL_POINTER;

	return OK;
}

//	Set the files name acording to the arguments;
status_t set_files_name(int argc, char * argv[], char * src, char * dest)
{
	int i;
	status_t inputFile, outputFile;
	inputFile = outputFile = NOT_FOUND;

	for(i = 1; i < argc; i++) {
		if(!strcmp(argv[i], SOURCE_ARGUMENT)) {
			printf("Encontre un '-in'\n");
			if(!strcmp(argv[i + 1], DESTINATION_ARGUMENT))
				return ERROR_INVOCATING_PROGRAM;

			strcpy(src, argv[++i]);
			printf("\tthen input file: '%s'\n", src);
			inputFile = OK;
		} else if(!strcmp(argv[i], DESTINATION_ARGUMENT)) {
			printf("Encontre un '-out'\n");
			if(!strcmp(argv[i + 1], SOURCE_ARGUMENT))

				return ERROR_INVOCATING_PROGRAM;
			strcpy(dest, argv[++i]);
			printf("\tthen output file: '%s'\n", argv[i]);
			outputFile = OK;
		}
	}
//	Return error if it could get input or output file names;
	if((inputFile && outputFile) != OK)
		return ERROR_INVOCATING_PROGRAM;

	return OK;
}

