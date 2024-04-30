#include <stdio.h>

unsigned long fact(int num) {
	unsigned long j, res;
	res = 1;

	for (j = 1; j <= num; j++) {
		res = (res * j);
	}
	return res;
}

int main ( void ) {

	printf("%lu\n", fact(5));
	printf("%lu\n", fact_recursive(5));

	return 0;
}
