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

#define MSG_FILE_NOT_FOUND "No se ha encontrado dicho archivo\n"

#define MSG_ERROR_LOADING_COUNTRY_CODES
#define MSG_ERROR_PRINTING
#define MSG_ERROR_READING_FILE
#define MSG_ERROR_ALLOCATING_TIME
#define MSG_ERROR_DATA_ON_FILE_MISSING	"\nERROR_DATA_ON_FILE_MISSING\n"\
										"En alguna linea de el archivo de entrada falta un dato,\n"\
										"compruebe que dicho archivo no esta corrupto y ejecute\n"\
										"el programa nuevamente"

#define MSG_OK "Everything executed correctly\n"

#endif
