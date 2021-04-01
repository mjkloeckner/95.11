#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 3
#define M 3

void m_load(size_t r, size_t c, double matrix[r][c]);
void m_print(size_t r, size_t c, double matrix[r][c]);
void m_initrand(size_t r, size_t c, double matrix[r][c]);
void m_transpose(size_t r, size_t c, double matrix[r][c], double matrix_t[c][r]);

bool m_isSimetric(size_t r, size_t c, double matrix[r][c]);


int main (void)
{
	double matrix[N][M];
	double matrix_transpose[M][N];

	m_load(N, M, matrix);
	m_print(N, M, matrix);
	putchar('\n');
	
	m_transpose(N, M, matrix, matrix_transpose);
	m_print(M, N, matrix_transpose);

	printf("\nThe matrix is %s SIMETRIC.", m_isSimetric(N, M, matrix) ? "" : "NOT");

	return 0;
}

void m_load(size_t r, size_t c, double matrix[r][c])
{
	char buf[20];
	for(size_t i = 0; i < r; i++) {
		for(size_t j = 0; j < c; j++) {
			fgets(buf, 20, stdin);
			matrix[i][j] = strtod(buf, NULL);	/*	value from stdin	*/ 
		}
	}
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

bool m_isSimetric(size_t r, size_t c, double matrix[r][c])
{
	double matrix_transpose[r][c];
	m_transpose(r, c, matrix, matrix_transpose);

	size_t aux = 0;
	for(size_t i = 0; i < r; i++)
		for(size_t j = 0; j < c; j++)
			if(matrix[i][j] == matrix_transpose[i][j])
				aux++;

	//if(aux == (r * c))
	//	return true;

	//return false;
	return true * (aux == (r * c)) + false * (aux != (r * c));
}
