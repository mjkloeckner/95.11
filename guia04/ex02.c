#include <stdio.h>

#define MAX 10

int main ( void ) {

	int x, array[MAX];
	array[4] = 1;

	x = array[4];

	printf("%d\n", x);

	return 0;
}
