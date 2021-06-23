#include <stdio.h>
#include <stdlib.h>

#define INT_MAX_HEX_DIGITS 4

char *itoo(int n);

int main (void)
{
	char *arr;
	arr = itoo(32155);
	printf("%s\n", arr);

	free(arr);
	return 0;
}

char *itoo(int n)
{
	char *arr;

	arr = (char *)calloc(INT_MAX_HEX_DIGITS + 1, sizeof(char));
	sprintf(arr, "%X", n);

	return arr;
}
