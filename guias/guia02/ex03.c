#include <stdio.h>

typedef enum {
	LUN, MAR, MIE, JUE, VIE, SAB, DOM
} dia_t;

int main(void)
{
	dia_t dia = VIE;

	printf("%d\n", dia);
	

	return 0;
}
