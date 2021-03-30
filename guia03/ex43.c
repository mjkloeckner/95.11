#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int main (void)
{
	double matrix[N][N];
	double trace;

	srand((unsigned int)time(NULL));

	for(size_t i = 0; i < N; i++) {
		putchar('(');
		putchar(' ');
		for(size_t j = 0; j < N; j++) {
			matrix[i][j] = ((double)rand()/(double)(RAND_MAX)) * 20;
			printf("%5.2f ", matrix[i][j]);
		}
		putchar(')');
		putchar('\n');
		trace += matrix[i][i];
	}

	printf("\nTrace = %2.2f.-\n", trace);
	return 0;
}
