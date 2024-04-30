#include "ex10.h"

#include <stdio.h>

double standard_deviation(double *arr, size_t len)
{
	if(arr == NULL) return -1;

	double sum, am;
	sum = 0;
	am = arithmetic_mean(arr, len);
	for(size_t n = 0; n <= len; n++)
		sum += pow((arr[n] - am), 2);

	return sqrt(sum / (len + 1));
}
