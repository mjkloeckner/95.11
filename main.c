#include "main.h"
#include "arguments.h"
#include "macros.h"

int main(int argc, char * argv[])
{
	status_t st;
	if((st = validate_arguments(argc, argv)) != OK) {
		print_error(st);
		return st;
	}
	
	char * src;
	char * dest;

	src = (char *)malloc(INITIAL_SIZE * sizeof(char));
	dest = (char *)malloc(INITIAL_SIZE * sizeof(char));

	if((st = set_files_name(argc, argv, src, dest)) != OK) {
		print_error(st);
		return st;
	}



	return OK;
}


