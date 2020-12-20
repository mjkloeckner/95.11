//	Reads an integer from stdin and prints it
//	on stdout in octal base; 

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
#define ERR_MSG_NEG "Err: the number is negative"

int main ( void ) {

	int num;
	char buffer[MAX_LEN];

	if(fgets(buffer, MAX_LEN, stdin) == NULL)
		return 1;

//	Converts the input str to int, if the number
//	is negative, puts an error message on stderr;
	if((num = atoi(buffer)) < 0 ) {
		fprintf(stderr, ERR_MSG_NEG"\n");
		return 1;
	}
	
//	prints the integer in octal base;
	printf("%o\n", num);
	return 0;
}
