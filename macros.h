#ifndef MACROS_H
#define MACROS_H

#define NO_CMD_ARGUMENTS	1
#define ONE_CMD_ARGUMENT	2
#define MAX_CMD_ARGUMENTS	5

#define INPUT_ARGUMENT			"-in"
#define OUTPUT_ARGUMENT			"-out"

#define INITIAL_SIZE		1000

#define MSG_ERROR_NULL_POINTER	"ERROR_NULL_POINTER\n"\
								"An unexpected error has occured during the execution\n"\
								"of the program"

#define MSG_ERROR_INVOCATING_PROGRAM	"\nERROR_INVOCATING_PROGRAM\n"\
										"Usage:\t$ ./main -in <input file> -out <outputfile>\n"\
										"\t$ ./main -out <output file -in <input file>\n"\
										"Read documentation to know more"

#define MSG_IO_FILE_NOT_FOUND 	"\nIO_FILE_NOT_FOUND\n"\
								"Un de los archivos de entrada o salida no se ha especificado"\

#define MSG_ERROR_LOADING_COUNTRY_CODES "\nERROR_LOADING_COUNTRY_CODES\n"\
										"Ha ocurrido un error al cargar los codigos de los paises.\n"\
										"compruebe que el archivo \""COUNTRY_CODES_FILE_NAME"\" se encuentre\n"\
										"disponible en el directorio de el programa ejecutado y que\n"\
										"el nombre coincida con el de \"COUNTRY_CODES_FILE_NAME\" dentro\n"\
										"de el archivo main.h\n"

#define MSG_ERROR_PRINTING

#define MSG_ERROR_READING_FILE			"\nERROR_READING_FILE\n"\
										"El archivo de entrada no pudo ser leido, compruebe que el nombre este\n"\
										"escrito correctamente y la existencia de el mismo"

#define MSG_ERROR_ALLOCATING_TIME		"\nstrftime(3): el formato especificado "

#define MSG_ERROR_DATA_ON_FILE_MISSING	"\nERROR_DATA_ON_FILE_MISSING\n"\
										"En alguna linea de el archivo de entrada falta un dato,\n"\
										"compruebe que dicho archivo no esta corrupto y ejecute\n"\
										"el programa nuevamente"

#define MSG_OK "\nEverything executed correctly.\n"

#endif
