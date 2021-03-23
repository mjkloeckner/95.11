#include <stdio.h>
#include <stdbool.h>

#define N 10

bool isSorted(int *vector, size_t size);

int main (void) 
{
	int vector[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	printf("The vector is sorted: %s\n", isSorted(vector, N) ? "Yes" : "No");

	return 0;
}

bool isSorted(int *vector, size_t size)
{
	size_t i;
	for(i = 1; (i < size) && (vector[i] >= vector[i - 1]); i++)
		;

	return true * (size == i);
}

