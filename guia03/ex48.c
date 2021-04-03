#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 3
#define M 3

typedef struct {
	size_t rows, columns;
	double **array;
} matrix_t;


void m_create(size_t rows, size_t columns, matrix_t *matrix);
void m_destroy(matrix_t *matrix);

void m_load(matrix_t *matrix);
void m_initrand(matrix_t *matrix);
void m_print(matrix_t *matrix);
void m_transpose(matrix_t *matrix, matrix_t *matrix_transpose);
void m_multiply(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result);

bool m_isSimetric(size_t r, size_t c, double matrix[r][c]);


int main (void)
{
	matrix_t matrix;
	matrix_t matrix2;
	matrix_t matrix_result;
	matrix_t matrix_transpose;

	m_create(2, 2, &matrix);
	m_create(2, 3, &matrix2);
	m_create(2, 3, &matrix_result);

	m_initrand(&matrix);
	m_print(&matrix);

	putchar('\n');

	m_initrand(&matrix2);
	m_print(&matrix2);

	putchar('\n');

	m_multiply(&matrix, &matrix2, &matrix_result);
	m_print(&matrix_result);

	m_destroy(&matrix);
	m_destroy(&matrix2);
	m_destroy(&matrix_result);

	return 0;
}

void m_print(matrix_t *matrix)
{
	for(size_t i = 0; i < matrix->rows; i++) {
		putchar('(');
		putchar(' ');
		for(size_t j = 0; j < matrix->columns; j++) {
			printf("%6.2f ", matrix->array[i][j]);
		}
		putchar(')');
		putchar('\n');
	}
}

void m_initrand(matrix_t *matrix)
{
	srand((unsigned int)time(NULL));
	
	for(size_t i = 0; i < matrix->rows; i++) {
		for(size_t j = 0; j < matrix->columns; j++) {
			matrix->array[i][j] = ((double)rand()/(double)(RAND_MAX)) * 20;
		}
	}
}

void m_load(matrix_t *matrix)
{
	char buf[20];
	for(size_t i = 0; i < matrix->rows; i++) {
		for(size_t j = 0; j < matrix->columns; j++) {
			fgets(buf, 20, stdin);
			matrix->array[i][j] = strtod(buf, NULL);
		}
	}
}

void m_transpose(matrix_t *matrix, matrix_t *matrix_transpose)
{
	for(size_t i = 0; i < matrix->rows; i++) {
		for(size_t j = 0; j < matrix->columns; j++)
			matrix_transpose->array[j][i] = matrix->array[i][j];

	}
}

void m_multiply(matrix_t *matrixA, matrix_t *matrixB, matrix_t *result)
{
	if(matrixA->columns != matrixB->rows)
		return;

	double aux;
	for(size_t i = 0; i < matrixA->rows; i++) {
		for(size_t j = 0; j < matrixB->columns; j++) {
			for(size_t k = aux = 0; k < matrixA->columns; k++)
				aux += ((matrixA->array[i][k])*(matrixB->array[k][j]));
			
			result->array[i][j] = aux;
		}	
	}
}

void m_create(size_t rows, size_t columns, matrix_t *matrix)
{
	matrix->rows = rows;
	matrix->columns = columns;

	matrix->array = (double **)malloc((rows) * sizeof(double));

	for (size_t i = 0; i < rows; i++)
		 matrix->array[i] = (double *)malloc(columns * sizeof(double));
}

void m_destroy(matrix_t *matrix)
{
	for (size_t i = 0; i < matrix->rows; i++)
		 free(matrix->array[i]);

	free(matrix->array);
}
