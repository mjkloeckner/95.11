#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 3
#define M 3

typedef struct {
	size_t rows, columns;
	double array[N][M];
} matrix_t;

/*
bool m_isSimetric(size_t r, size_t c, double matrix[r][c]);
*/

void m_load(matrix_t *matrix);
void m_initrand(matrix_t *matrix);
void m_print(matrix_t *matrix);
void m_transpose(matrix_t *matrix, matrix_t *matrix_transpose);

int main (void)
{
	matrix_t matrix;
	matrix.rows = N;
	matrix.columns = M;

	m_initrand(&matrix);
	m_print(&matrix);

	//m_load(N, M, matrix);
	//m_print(N, M, matrix);
	//putchar('\n');
	
	//m_transpose(N, M, matrix, matrix_transpose);
	//m_print(M, N, matrix_transpose);


	return 0;
}
/*
void m_print(size_t r, size_t c, double matrix[r][c])
{
	for(size_t i = 0; i < r; i++) {
		putchar('(');
		putchar(' ');
		for(size_t j = 0; j < c; j++) {
			printf("%6.2f ", matrix[i][j]);
		}
		putchar(')');
		putchar('\n');
	}
}

*/

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

void m_transpose(size_t r, size_t c, double matrix[r][c], double matrix_t[c][r])
{
	for(size_t i = 0; i < r; i++) {
		for(size_t j = 0; j < c; j++)
			matrix_t[j][i] = matrix[i][j];

	}
}
