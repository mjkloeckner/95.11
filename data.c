#include "main.h"
#include "macros.h"

void print_error(status_t error)
{
	switch (error) {
		case ERROR_INVOCATING_PROGRAM: 
			fprintf(stderr, MSG_ERROR_INVOCATING_PROGRAM"\n");
			break;
		case ERROR_NULL_POINTER:
			fprintf(stderr, MSG_ERROR_NULL_POINTER"\n");
			break;
		case IO_FILE_NOT_FOUND: 
			fprintf(stderr, MSG_IO_FILE_NOT_FOUND"\n");
			break;
		case ERROR_LOADING_COUNTRY_CODES:
			fprintf(stderr, MSG_ERROR_LOADING_COUNTRY_CODES"\n");
			break;
		case ERROR_PRINTING: 
			fprintf(stderr, MSG_ERROR_PRINTING"\n");
			break;
		case ERROR_READING_FILE:
			fprintf(stderr, MSG_ERROR_READING_FILE"\n");
			break;
		case ERROR_ALLOCATING_TIME: 
			fprintf(stderr, MSG_ERROR_ALLOCATING_TIME"\n");
			break;
		case ERROR_DATA_ON_FILE_MISSING: 
			fprintf(stderr, MSG_ERROR_DATA_ON_FILE_MISSING"\n");
			break;
		default:
			fprintf(stdin, MSG_OK"\n");
	}
}

