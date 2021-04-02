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

matrix_t * m_multiply(matrix_t *matrixA, matrix_t *matrixB);

bool m_isSimetric(size_t r, size_t c, double matrix[r][c]);


int main (void)
{
	matrix_t matrix;
	matrix_t matrix_result;
	matrix_t matrix_transpose;

	m_create(3, 4, &matrix);
	m_create(4, 3, &matrix_result);
	m_create(4, 3, &matrix_transpose);

	(&matrix_result) = m_multiply(&matrix, &matrix_transpose);

	//m_load(N, M, matrix);
	//m_print(N, M, matrix);
	
	m_initrand(&matrix);
	m_print(&matrix);

	putchar('\n');
	
	m_transpose(&matrix, &matrix_transpose);
	m_print(&matrix_transpose);

	m_destroy(&matrix);
	m_destroy(&matrix_transpose);

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

matrix_t *m_multiply(matrix_t *matrixA, matrix_t *matrixB)
{
	if(matrixA->columns != matrixB->rows)
		return NULL;

	matrix_t matrix_aux;
	m_create(matrixA->rows, matrixB->columns, &matrix_aux);

	for(size_t i = 0; i < matrixA->rows; i++) {
		for(size_t j = 0; j < matrixA->columns; j++)
			//matrix_aux->array[i][j] = matrixA->array[i][j] matrix[];

	}
	return &matrix_aux;
//	m_destroy(&matrix_aux);
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
