/*	Populates the direction in memory pointed by every element of an array
 *	of 10 pointers to float	with 10 numbers entered via stdin.	*/
 
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define BUFFER_LEN 10

int main (void)
{
	char aux, buffer[BUFFER_LEN + 1];
	float *pf[10];
	double *sum;
	size_t i;

	printf("%d\n", FLT_MAX);
	printf("%d\n", FLT_DIG);

	if(!(sum = (double *)calloc(1, sizeof(double))))
		return 1;

	/*	Makes every pointer point to a space in memmory with space for one float number	*/
	for(i = 0; i < 10; i++) {
		if(!(pf[i] = (float *)calloc(1, sizeof(float)))) {
			for(size_t j = i; j > 0; j--)
				free(pf[j]);

			return 1;
		}
	}

	/*	Populates the array with user input converted to float, computes the sume of all
	 *	the converted numbers and then frees the memmory since it's no longer needed	*/
	for(i = *sum = 0; i < 10 ; i++) {
		if(!fgets(buffer, BUFFER_LEN, stdin)) return 2;
		*sum += (*pf[i] = strtof(buffer, NULL));

		printf("%p: %5f\n", pf[i], *pf[i]);
		free(pf[i]);
		while(((aux = getchar()) != 10) && (aux != 13))
			putchar(aux);
	}

	printf("\nsum:  %5f\n", *sum);

	free(sum);
	return 0;
}
