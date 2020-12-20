#include <stdio.h>
#include <stdlib.h>

#define MASK_BYTE 0xFF

int main(void) {

//	0x10 30 25 F4
	unsigned int n = 271590900;

//	Arreglo de 4 bytes;
	unsigned char v[4]; 

	size_t i;
/*
	v[0] = (n >> 24) & 0xFF;
	v[1] = (n >> 16) & 0xFF;
	v[2] = (n >> 8) & 0xFF;
	v[3] = (n >> 0) & 0xFF;
*/
	for(i = 0; i < sizeof(unsigned int); i++)
		v[i] = (n >> ( (sizeof(unsigned int) - 1 - i) * 8  )) & 0xFF;

	printf("%d\n", n);
	printf("%x\n", n);

	for(i = 0; i < sizeof(unsigned int); i++)
		printf("v[%lu] = %x\n", i, v[i]);

	return EXIT_SUCCESS;
}
