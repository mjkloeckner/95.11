#include <stdio.h>

#define MASK_BIT 0x01

typedef unsigned char uchar;

uchar set_bit(uchar byte, short linea);
uchar clear_bit(uchar byte, short linea);

int main (void)
{
	uchar byte = 0x81; /* 1000 0001 */

	printf("0x%X\n", byte);

	byte = set_bit(byte, 3);

	printf("0x%X\n", byte);

	byte = clear_bit(byte, 3);

	printf("0x%X\n", byte);

	return 0;
}

uchar set_bit(uchar byte, short linea)
{
	return (byte | (MASK_BIT << linea));
}

uchar clear_bit(uchar byte, short linea)
{
	return (byte & ~(MASK_BIT << linea));
}
