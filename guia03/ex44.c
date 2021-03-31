#include <stdio.h>
#include <stdlib.h>

#define N 4

double getnum(void);

int main (void)
{
	double matrix[N][N];
	double trace;

	for(size_t i = 0; i < N; i++) {
		putchar('(');
		putchar(' ');
		for(size_t j = 0; j < N; j++) {
			matrix[i][j] = getnum();
			printf("%5.2f ", matrix[i][j]);
		}
		putchar(')');
		putchar('\n');
		trace += matrix[i][i];
	}

	printf("\nTrace = %2.2f.-\n", trace);
	return 0;
}

double getnum(void)
{
	char aux, buffer[300];

	for(size_t i = 0; aux = (getchar() != '\n'); i++)
		buffer[i] = aux;
	
	return strtod(buffer, NULL);
}
