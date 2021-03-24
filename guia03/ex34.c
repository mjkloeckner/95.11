#include <stdio.h>
#include <stdbool.h>

#define N 10

bool isSorted(int *vector, size_t size);
bool isSortedBothDirections(int *vector, size_t size);

int main (void) 
{
	int vector[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int vectorInv[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	printf("The vector is sorted: %s\n", isSorted(vector, N) ? "Yes" : "No");
	printf("The vector is sorted: %s\n", isSortedBothDirections(vector, N) ? "Yes" : "No");

	return 0;
}


bool isSortedBothDirections(int *vector, size_t size)
{
	size_t i, j, k;
	i = j = k = 1;

	while(i < size) {
		j += (vector[i] >= vector[i - 1]);
		k += (vector[i] <= vector[i - 1]);
		i++;
	}

	return true * (j == size) + true * (k == size);
}

bool isSorted(int *vector, size_t size)
{
	size_t i;
	for(i = 1; (i < size) && (vector[i] >= vector[i - 1]); i++)
		;

	return true * (size == i);
}

