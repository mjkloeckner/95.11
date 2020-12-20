//	Reads an integer from stdin and prints it
//	on stdout in binary base.
//	only for numbers below 128; 

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN	8 
#define ERR_MSG_NEG "Err: invalid number!"

int main ( void ) {

	int i, num;
	char buffer[MAX_LEN];
//	0000 0000
	int bin[MAX_LEN] = {0,0,0,0,0,0,0,0};

	if(fgets(buffer, MAX_LEN, stdin) == NULL)
		return 1;

//	Converts the input str to int, if the number
//	is negative or greater than 128, puts an 
//	error message on stderr;
	if((num = atoi(buffer)) < 0 || num > 128) {
		fprintf(stderr, ERR_MSG_NEG"\n");
		return 1;
	}

//	Converts num to binary base by dividing it
//	by 2 until its zero, the rest of the division
//	is stored in every itineration in bin[];
	for(i = 0; num != 0; i++) {
		if((num % 2) == 1) {
			bin[i] = 1;
		} else {
			bin[i] = 0;
		}
		num = (num / 2);
	}

//	This part print bin in reverse order because
//	the previous algorithm stores the values in 
//	reverse order;
	for(i = 7; i >= 0; i--) {
		if(i == 3)
			putchar(' ');

		printf("%d", bin[i]);
	}

	putchar('\n');
	return 0;
}
