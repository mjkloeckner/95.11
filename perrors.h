#ifndef DATA_H
#define DATA_H

#include "main.h"

#define MSG_ERROR_NULL_POINTER	"ERROR_NULL_POINTER (3)\n"\
								"Un error inesperado ha ocurrido durante la ejecucion de\n"\
								"el programa"

#define MSG_ERROR_INVOCATING_PROGRAM	"\nERROR_INVOCATING_PROGRAM (2)\n"\
										"Uso:\t$ ./main -in <input file> -out <outputfile>\n"\
										"\t$     ./main -out <output file -in <input file>\n"\
										"Lee el archivo README.md para saber mas"

#define MSG_IO_FILE_NOT_FOUND 	"\nIO_FILE_NOT_FOUND (1)\n"\
								"Un de los archivos de entrada o salida no se ha especificado"\

#define MSG_ERROR_LOADING_COUNTRY_CODES "\nERROR_LOADING_COUNTRY_CODES (4)\n"\
										"Ha ocurrido un error al cargar los codigos de los paises.\n"\
										"compruebe que el archivo \""COUNTRY_CODES_FILE_NAME"\" se encuentre\n"\
										"disponible en el directorio de el programa ejecutado y que\n"\
										"el nombre coincida con el de \"COUNTRY_CODES_FILE_NAME\" dentro\n"\
										"de el archivo main.h"

#define MSG_ERROR_PRINTING

#define MSG_ERROR_READING_FILE			"\nERROR_READING_FILE (6)\n"\
										"El archivo de entrada no pudo ser leido, compruebe que el nombre este\n"\
										"escrito correctamente y la existencia de el mismo"

#define MSG_ERROR_ALLOCATING_TIME		"\nERROR_ALOCATING_TIME (7)\n"\
										"Hubo un problema inesperado durante la traduccion de la fecha al formato\n"\
										"especificado."

#define MSG_ERROR_DATA_ON_FILE_MISSING	"\nERROR_DATA_ON_FILE_MISSING (8)\n"\
										"En alguna linea de el archivo de entrada falta un dato,\n"\
										"compruebe que dicho archivo no esta corrupto y ejecute\n"\
										"el programa nuevamente"

#define MSG_OK "\nOperacion realizada exitosamente!\n"


void print_error(status_t error);


#endif
