#include <stdio.h>

#define MASK_RXCIE	0x80
#define MASK_TXCIE	0x40
#define MASK_UDRIE	0x20
#define MASK_RXEN	0x10
#define MASK_TXEN	0x08
#define MASK_CHR9	0x04
#define	MASK_RXB8	0x02
#define MASK_TXB8	0x01

#define SHIFT_RXCIE	7
#define SHIFT_TXCIE	6
#define SHIFT_UDRIE	5
#define SHIFT_RXEN	4
#define SHIFT_TXEN	3
#define SHIFT_CHR9	2
#define	SHIFT_RXB8	1
#define SHIFT_TXB8	0

#define MSG_TX_COMPLETE "Transmission Completed"
#define MSG_TX_UNCOMPLETE "Transmission Incomplete"

typedef unsigned char uchar;
typedef enum { LO, HI } bit_t;
typedef enum { FALSE, TRUE } bool_t;
typedef enum {
	OK,
	ERROR_TRANSMISSION_UNCOMPLETE,
	ERROR_NULL_POINTER
} status_t;

bit_t tx_complete(uchar);
status_t tx_complete2(uchar, bit_t *state);

void print_reg(uchar reg)
{
	for(size_t i = ((sizeof(reg) * 8)); i > 0; i--)
		putchar((reg & (0x01 << (i - 1))) ? '1' : '0');

	putchar('\n');
}

int main (void)
{
	uchar reg = 0x42;
	status_t st;
	bit_t tx;

	print_reg(reg);

	printf("%s\n", tx_complete(reg) ? MSG_TX_UNCOMPLETE : MSG_TX_COMPLETE);

	if((st = tx_complete2(reg, &tx))) return st;
	printf("%s\n", tx ? MSG_TX_COMPLETE : MSG_TX_UNCOMPLETE);

	return OK;
}

bit_t tx_complete(uchar reg)
{
	return ((reg & MASK_TXCIE) >> SHIFT_TXCIE) ? LO : HI;
}

status_t tx_complete2(uchar reg, bit_t *state)
{
	if(!state) return ERROR_NULL_POINTER;

	*state = ((reg & MASK_TXCIE) >> SHIFT_TXCIE);

	return OK;
}
