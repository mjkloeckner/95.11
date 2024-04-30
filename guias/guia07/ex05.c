#include <stdio.h>
#include <stdlib.h>

#define MASK_BYTE 0xFF

int main(void) {

	/* 0x10 30 25 F4 */
	unsigned int n = 271590900;

	/* Arreglo de 4 bytes; */
	unsigned char x[4]; 

	size_t i;
/*
	x[0] = (n >> 24) & 0xFF;
	x[1] = (n >> 16) & 0xFF;
	x[2] = (n >> 8) & 0xFF;
	x[3] = (n >> 0) & 0xFF;
*/
	for(i = 0; i < sizeof(unsigned int); i++)
		x[i] = (n >> ( (sizeof(unsigned int) - 1 - i) * 8  )) & MASK_BYTE;

	printf("%d\n", n);
	printf("%X\n", n);

	for(i = 0; i < sizeof(unsigned int); i++)
		printf("x[%lu] = %X\n", i, x[i]);

	return EXIT_SUCCESS;
}
