#include <stdio.h>
#include <stdlib.h>

double **identity_matrix(size_t dim);

int main (void)
{
	double **m;
	size_t len = 3;
	m = identity_matrix(len);

	for(size_t i = 0; i < len; i++) {
		for(size_t j = 0; j < len; j++)
			printf("%.0f ", m[i][j]);

		putchar('\n');
	}

	return 0;
}

double **identity_matrix(size_t dim)
{
	double **m;
	
	/* Allocates memory for a squared matrix of dimension dim */
	if(!(m = (double **)malloc(sizeof(double) * (dim * dim)))) return NULL;

	/* Gets memory for every element of the matrix, if an error occurs, frees every previous allocated element and returns null, if no errors are enconuntered and both indexes are equal stores a 1 otherwise leaves it at zero */
	for(size_t i = 0; i < dim; i++) {
		if(!(m[i] = (double *)calloc(sizeof(double), dim))) {
			for(size_t k = i; k--;) free(m[k]);
			return NULL;
		}
		for(size_t j = 0; j < dim; j++) {
			if(i == j) m[i][j] = 1;
			else m[i][j] = 0;
		}
	}

	return m;
}
