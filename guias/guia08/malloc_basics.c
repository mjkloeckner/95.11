//	Stores an array of numbers in heap, then prints it on
//	stdout finally frees the memory used;

#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 10

int main (void) 
{
	int *p;

	if((p = (int*)malloc(ARR_LEN * sizeof(int))) == NULL)
		return 1;

	for(int i = 0; i < ARR_LEN; i++) {
		*(p + i) = i;
		printf("%d\n", *(p + i));
	}
	free(p);
	return 0;
}
