#include <stdio.h>

#define MASK_POWER		0x80

#define SHIFT_POWER		7

typedef unsigned char uchar;
typedef enum { OK, ERROR_NULL_POINTER } status_t;

void print_reg(unsigned char reg);
status_t toggle_bit(uchar *reg, uchar shift);

int main (void)
{
	/* 0000 0000 */
	uchar reg = 0x00;
	print_reg(reg);

	if(toggle_bit(&reg, SHIFT_POWER)) return ERROR_NULL_POINTER;
	print_reg(reg);

	if(toggle_bit(&reg, SHIFT_POWER)) return ERROR_NULL_POINTER;
	print_reg(reg);
	return 0;
}

void print_reg(uchar reg)
{
	for(size_t i = ((sizeof(reg) * 8)); i > 0; i--)
		putchar((reg & (0x01 << (i - 1))) ? '1' : '0');

	putchar('\n');
}

status_t toggle_bit(uchar *reg, uchar shift)
{
	if(!reg) return ERROR_NULL_POINTER;

	*reg ^= (0x01 << shift);

	return OK;
}
