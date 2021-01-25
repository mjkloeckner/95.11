#include "main.h"

void print_error(status_t error)
{
	switch (error) {
		case ERROR_INVOCATING_PROGRAM: 
			fprintf(stderr, MSG_ERROR_INVOCATING_PROGRAM"\n");
			break;
		case ERROR_NULL_POINTER:
			fprintf(stderr, MSG_ERROR_NULL_POINTER"\n");
			break;
		default:
			fprintf(stdin, MSG_OK"\n");
	}
}

