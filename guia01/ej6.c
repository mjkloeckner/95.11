#include <stdio.h>
#include <math.h>


int main( void ) {

	int a, b, c;
	float x1, x2;
	
	a =  1;
	b = -12;
	c =  36;

	x1 = ((-b) + sqrtf( (b*b)-(4*a*c) )) / (2*a);
	x2 = ((-b) - sqrtf( (b*b)-(4*a*c) )) / (2*a);

	printf("x1 = % .2f\nx2 = % .2f\n", x1, x2);

	return 0;
}
