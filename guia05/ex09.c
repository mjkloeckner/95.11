#include "ex09.h"

double arithmetic_mean(double *arr, size_t len)
{
	if(arr == NULL) return -1;

	double sum = 0;
	for(size_t i = 0; i <= len; i++)
		sum += arr[i];
	
	return (sum / (len + 1));
}
