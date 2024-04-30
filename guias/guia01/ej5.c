#include <stdio.h>
#include <math.h>

int main( void ) {

	float raiz = 25;
	float inv = 4;

	printf("sqrt(%.2f) = ", raiz);

	if(raiz > 0)
		raiz = sqrt(raiz);
	else
		return 1;

	printf("%.2f\n", raiz);
	printf("inv(%.2f) = ", inv);

	if (inv != 0)
		inv = 1/inv;
	else
		return 1;

	printf("%.2f\n", inv);

	return 0;
}
