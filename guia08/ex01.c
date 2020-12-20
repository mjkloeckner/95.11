//	Clones a given string entered as arguments of function main;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_ARGUMENT		  1
#define INIT_SIZE		100

typedef enum {
	OK,
	ERROR_PROGRAM_INVOCATION,
	ERROR_NULL_POINTER,
	ERROR_ALLOC_MEMORY
} status_t;

status_t validar_argumentos(int argc, char **argv);

int main (int argc, char * argv[]) 
{
	char *dest;
	size_t i;
	status_t st;

//	Verify if arguments are right;
	if((st = validar_argumentos(argc, argv) != OK))
		return st;

//	Allocates memmory in heap of size INIT_SIZE;
	if((dest = (char *)malloc(INIT_SIZE * sizeof(char))) == NULL)
			return ERROR_ALLOC_MEMORY;

//	Assigns 1 to i to avoid the first element of argv, 
//	which is the program name. Then copies every string of argv
//	into dest and prints it on stdout;
	for(i = 1; (int)i < argc; i++) {
		strcpy(dest, argv[i]);
	//	Puts a space in between strings, avoiding a blank
	//	space after first string is printed;
		if(i != 1) putchar(' ');
		printf("%s", dest);
	}

//	Adds the new line character;
	putchar('\n');
	free(dest);
	return OK;
}

status_t validar_argumentos(int argc, char **argv) 
{
	if(argc == NO_ARGUMENT)
		return ERROR_PROGRAM_INVOCATION;

	else if(argv == NULL)
		return ERROR_NULL_POINTER;

	else return OK;
}
