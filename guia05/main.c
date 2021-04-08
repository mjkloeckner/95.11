#include <stdio.h>

#include "ex09.h"

int main (void)
{
	double a[] = {9, 1.50, 3, 8.75};

	double am;
	am = arithmetic_mean(a, 3);

	printf("%f\n", am);
	return 0;
}
