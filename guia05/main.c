#include <stdio.h>

#include "ex09.h"
#include "ex10.h"

int main (void)
{
	double a[] = {9, 1.50, 3, 8.75};

	double am, sd;
	am = arithmetic_mean(a, 3);
	sd = standard_deviation(a, 3);


	printf("%f\n%f\n", am, sd);
	return 0;
}
