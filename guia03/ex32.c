//	Calculates the max or min in an array of numbers;
//	of type int;

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ELEM				10
#define NO_ARGUMENT_ENTERED		1 
#define EXTREMO_ARGUMENT		1

typedef enum {
	MAXIMUM,
	MINIMUM
} extreme_t;

typedef enum {
	OK,
	ERROR_INVOCATING_PROGRAM,
	ERROR_NULL_POINTER
} status_t;

status_t validate_arguments (int argc, char ** argv);

int main (int argc, char * argv[])
{
	size_t i;
	int vector[MAX_ELEM] = {9, 10, 25, 31, 9, 5, 11, 46, 50, 20};
	extreme_t extremo;
	status_t st; 

	if((st = validate_arguments(argc, argv)) != OK)
		return st;

	extremo = atoi(argv[EXTREMO_ARGUMENT]);
	if(extremo == MAXIMUM) {
	//	Find maximum element in array;
		int maximum;
		for(i = 0, maximum = INT_MIN; i < (sizeof(vector)/sizeof(vector[0])); i++)
			if(vector[i] > maximum)
				maximum = vector[i];
		
		printf("%d\n", maximum);
	} else if (extremo == MINIMUM){
	//	Find minimum element in array;
		int minimum;
		for(i = 0, minimum = INT_MAX; i < (sizeof(vector)/sizeof(vector[0])); i++)
			if(vector[i] < minimum)
				minimum = vector[i];

		printf("%d\n", minimum);
	}
	return 0;
}

status_t validate_arguments (int argc, char ** argv) {
	if(argc == NO_ARGUMENT_ENTERED)
		return ERROR_INVOCATING_PROGRAM;

	else if (argv == NULL)
		return ERROR_NULL_POINTER;

	else return OK;
}

