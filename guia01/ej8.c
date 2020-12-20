/*	Calculates the factorial of a given number.	*/

#include <stdio.h>

#define ERR_MSG_NEG "ERR: The entered number is negative!"

int main(void) {
	
	int fact, i, res;

	printf("Enter a number: ");
	if(scanf("%i", &fact) == EOF)
		return 1;		

	if(fact < 0) {
		printf(ERR_MSG_NEG"\n");
		return 1;
	}

	res = 1;
	for(i = 1; i <= fact; i++) {
		res *= i;
	}

	printf("%d! = %d\n", fact, res);
	return 0;
}
