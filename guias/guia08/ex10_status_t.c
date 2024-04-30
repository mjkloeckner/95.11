#include <stdio.h>
#include <stdlib.h>

typedef enum {
	OK,
	ERROR_MEMORY_ALLOC,
	ERROR_NULL_POINTER
} status_t;

status_t identity_matrix(size_t dim, double ***m);

int main (void)
{
	double **m;
	size_t len = 5;
	if(!identity_matrix(len, &m));

	for(size_t i = 0; i < len; i++) {
		for(size_t j = 0; j < len; j++)
			printf("%.0f ", m[i][j]);

		putchar('\n');
	}

	return 0;
}

status_t identity_matrix(size_t dim, double ***m)
{
	if(!m) return ERROR_NULL_POINTER;

	/* Allocates memory for a squared matrix of dimension dim */
	if(!(*m = (double **)malloc(sizeof(double) * (dim * dim)))) return ERROR_MEMORY_ALLOC;

	/* Gets memory for every element of the matrix, if an error occurs, frees every previous allocated element and returns ERROR_NULL_POINTER, if no errors are enconuntered and both indexes are equal stores a 1 otherwise leaves it at zero */
	for(size_t i = 0; i < dim; i++) {
		if(!((*m)[i] = (double *)calloc(sizeof(double), dim))) {
			for(size_t k = i; k--;) free((*m)[k]);
			return ERROR_MEMORY_ALLOC;
		}
		for(size_t j = 0; j < dim; j++) {
			if(i == j) (*m)[i][j] = 1;
			else (*m)[i][j] = 0;
		}
	}

	return OK;
}
