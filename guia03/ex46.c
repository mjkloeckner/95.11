#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 4

void m_initrand(size_t r, size_t c, double matrix[r][c]);
void m_print(size_t r, size_t c, double matrix[r][c]);
void m_transpose(size_t r, size_t c, double matrix[r][c], double matrix_t[c][r]);

int main (void)
{
	double matrix[N][M];
	double matrix_transpose[M][N];

	m_initrand(N, M, matrix);
	m_print(N, M, matrix);
	putchar('\n');
	
	m_transpose(N, M, matrix, matrix_transpose);
	m_print(M, N, matrix_transpose);


	return 0;
}

void m_initrand(size_t r, size_t c, double matrix[r][c])
{
	srand((unsigned int)time(NULL));

	for(size_t i = 0; i < N; i++) {
		for(size_t j = 0; j < M; j++) {
			matrix[i][j] = ((double)rand()/(double)(RAND_MAX)) * 20;
		}
	}
}

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

void m_transpose(size_t r, size_t c, double matrix[r][c], double matrix_t[c][r])
{
	for(size_t i = 0; i < r; i++) {
		for(size_t j = 0; j < c; j++)
			matrix_t[j][i] = matrix[i][j];

	}
}
