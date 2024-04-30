/*	Reads a string of chars from stdin and converts
	it to a number, int or float; */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 26

int
main (void)
{
	char buffer[MAX_LEN];
	int num1;
	float num2;

	if(!fgets(buffer, MAX_LEN, stdin)) return 1;
	num1 = atoi(buffer);
	printf("n1(int) = %d\n", num1);

	if(!fgets(buffer, MAX_LEN, stdin)) return 1;
	num2 = atof(buffer);
	printf("n2(float) = %.2f\n", num2);

	return 0;
}
