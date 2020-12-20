//	Reads a number from stdin and prints it 
//	in hexadecimal base on stout;

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int main ( void ) {

	char buffer[MAX_LEN];
	int num;
	char num2[MAX_LEN];

	if(fgets(buffer, MAX_LEN, stdin) == NULL)
		return 1;

	num = atoi(buffer);

//	Converts num to hexadecimal and stores it
//	on num2 str;
	sprintf(num2, "%x\n", num);

//	prints the string with the octal number;
	printf("%s", num2);
	return 0;
}
