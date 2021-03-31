#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2
#define MATRIX_MAX 20

double matrix_det(size_t n, double matrix[][n]);

int main (void)
{
	double matrix[N][N];

	double determinant;
	double trace;

	srand((unsigned int)time(NULL));

	for(size_t i = 0; i < N; i++) {
		/* This to make it fancy */	
		putchar('(');
		putchar(' ');

		/* Initialize the matrix with random numbers in range 0 - MATRIX_MAX */
		for(size_t j = 0; j < N; j++) {
			matrix[i][j] = ((double)rand()/(double)(RAND_MAX)) * 20;
			printf("%5.1f ", matrix[i][j]);
		}

		/* This to make it fancy too*/	
		putchar(')');
		putchar('\n');

		/* Calculates the matrix trace */
		trace += matrix[i][i];
	}


	determinant = matrix_det(N, matrix);

	printf("\nDeterminant = %2.1f.-\nTrace = %2.1f.-\n", determinant, trace);

	return 0;
}

double matrix_det(size_t n, double matrix[][n])
{
	double det;
	if(n == 2) {
		det = ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
	} else if (n == 3) {
		det = (matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])) 
			- (matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]))
			- (matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]));
	}
	return det;
}
