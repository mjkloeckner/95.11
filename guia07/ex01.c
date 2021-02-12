#include <stdio.h>


typedef enum {
	OK,
	ERROR
} status_t;

status_t print_byte(unsigned char *byte);

int main (void)
{
	unsigned char a, b, res;

	a = 0b11001010;
	b = 0b10100101;

	printf("a = ");
	print_byte(&a);

	printf("b = ");
	print_byte(&b);
	putchar('\n');
		
	printf("& = ");
	res = (a & b);
	print_byte(&res);

	printf("| = ");
	res = (a | b);
	print_byte(&res);


	printf("^ = ");
	res = (a ^ b);
	print_byte(&res);
	return OK;
}

status_t print_byte(unsigned char *byte) 
{
	if(byte == NULL) return ERROR;

	unsigned char aux = 0x01;
	for(int i = ((sizeof(*byte) * 8) - 1); i >= 0; i--)
		putchar(((*byte) & (aux << i)) ? '1' : '0');

	putchar('\n');
	return OK;
}



//	for(size_t i = 0; i < (sizeof(*byte) * 8); i++)
//		putchar(((*byte) & (aux << i)) ? '1' : '0');
