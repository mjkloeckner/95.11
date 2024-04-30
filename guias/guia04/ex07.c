/*
 * What is the difference between NULL and '\0'?
 * The difference is that NULL is defined as '\0' casted to void*,
 * they both are evaluated to the constant value 0, 
 * but they are used in different contexts, in general NULL
 * is used to check for pointers, and '\0' for the ends of a string.
*/

#include <stdio.h>

int main (void)
{
	printf("'\\0' = %d", '\0');
	printf("'NULL' = %d", NULL);

	return 0;
}
