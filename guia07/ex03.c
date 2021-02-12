#include <stdio.h>

int main (void)
{
	unsigned int aux, a, b, c, d;

	a = 0157;
	b = 0701;
	c = 0673;
	d = 067;
	aux = 0b1101111;

	printf("%o\n%o\n%o\n%o\n", a<<1, b<<2, c>>2, d>>3);
	printf("%o\n", aux<<1);

	return 0;

}
