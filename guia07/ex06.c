#include <stdio.h>





int main (void)
{
	unsigned int n;
	size_t i;

	unsigned char x[4] = {0x10, 0x30, 0x25,0xF4};

	for(i = 0, n = 0; i < sizeof(x); i++) {
		printf("%X", x[i]);
		n = ((n << 8) | x[i]);
	}		

	printf("\n%lu\n", n);

	return 0;
}
