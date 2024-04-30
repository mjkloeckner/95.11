//	Calculates the arithmetic mean of a certain amount of
//	numbers. First ask for the quantity and then calculates
//	it and prints it;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 20

int main (void) {

	int i, n;
	float d, x, suma, numbers[MAX_LEN];
	char buffer[MAX_LEN];

//	Read the quantity of numbers to mean;
	if(fgets(buffer, sizeof(int) + 1, stdin) != NULL)
		n = atoi(buffer);
	else return 1;

//	Read the values to mean  and stores it on numbers;
	for(i = 0, suma = 0; i < n; i++) {
		if(fgets(buffer, sizeof(int) + 1, stdin) != NULL) {
			numbers[i] = atof(buffer);
			suma += numbers[i];
		} else return 1;
	}

//	Calculate the arithmetic mean and stores it on x;
	x = ((1 / (float)n) * suma); 

//	Calculates the standard deviation;
	for(i = 0; i < n; i++) {
		suma += (numbers[i] - x);
		d = sqrtf((1/n) * powf(suma, 2.0));
	}

//	Print the arithmetic mean;
	printf("x = %.3f\n", x);

//	Print the standard deviation;
	printf("d = %.3f\n", d);
	return 0;
}
