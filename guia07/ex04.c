#include <stdio.h>

#define BIT_MASK 0b00000001

#define MASK_STATUS 0b10000000

unsigned char reg;

void print_byte(unsigned char *reg);
void turnOn(unsigned char bit);
void turnOff(unsigned char bit);

int main (void)
{
	reg = 0b01010101;
	
	reg = reg & ~(BIT_MASK << 7);
	print_byte(&reg);

	putchar('\n');
	reg = reg | (BIT_MASK << 7);
	print_byte(&reg);

	putchar('\n');
	reg = reg & ~(BIT_MASK << 7);
	print_byte(&reg);

	turnOn(MASK_STATUS);
	putchar('\n');
	print_byte(&reg);

	turnOff(MASK_STATUS);
	putchar('\n');
	print_byte(&reg);
	return 0;
}



void print_byte(unsigned char *reg)
{
	int i;
	for(i = (sizeof(*reg) * 8); i > 0; i--)
		putchar((BIT_MASK << (i - 1)) & (*reg) ? '1' : '0');

	return;
}

void turnOn(unsigned char bit) 
{
	reg = reg | bit;
}


void turnOff(unsigned char bit) 
{
	reg = reg & ~(bit);
}
