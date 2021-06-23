#include <stdio.h>
#include <stdlib.h>

#define INT_MAX_DIGITS 5

char *itoa(int n);

int main (void)
{
	char *arr;
	arr = itoa(32211);
	printf("%s\n", arr);

	free(arr);
	return 0;
}

char *itoa(int n)
{
	char *arr;

	arr = (char *)calloc(INT_MAX_DIGITS + 1, sizeof(char));
	sprintf(arr, "%d", n);

	return arr;
}
