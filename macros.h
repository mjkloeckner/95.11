#ifndef MACROS_H
#define MACROS_H

#define NO_CMD_ARGUMENTS	1
#define MAX_CMD_ARGUMENTS	5

#define SOURCE_ARGUMENT			"-in"
#define DESTINATION_ARGUMENT	"-out"

#define INITIAL_SIZE		1000

#define MSG_ERROR_NULL_POINTER	"ERROR_NULL_POINTER\n"\
								"An unexpected error has occured during the execution\n"\
								"of the program"

#define MSG_ERROR_INVOCATING_PROGRAM	"ERROR_INVOCATING_PROGRAM\n"\
										"Usage:\t$ ./main -in <input file> -out <outputfile>\n"\
										"\t$ ./main -out <output file -in <input file>\n"\
										"Read documentation to know more"

#define MSG_OK "Everything executed correctly"

#endif
