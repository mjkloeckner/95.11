#include <stdio.h>
#include <stdlib.h>

#define N 10

int main (void)
{
	int vector[N];
	size_t i;

	for(i = 0; i < N; i++) {
		vector[i] = rand();
		printf("%d\n", vector[i]);	
	}
	return 0;
}
