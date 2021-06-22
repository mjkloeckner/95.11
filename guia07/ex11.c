#include <stdio.h>

#define MASK_SPIE	0x80
#define MASK_SPE	0x40
#define MASK_CPOL	0x08
#define MASK_SPR1	0x04
#define MASK_SPR0	0x02

#define SHIFT_SPIE	7
#define SHIFT_SPE	6
#define SHIFT_CPOL	3
#define SHIFT_SPR1	2
#define SHIFT_SPR0	1

typedef unsigned char uchar;
typedef enum { LO, HI } bit_t;

bit_t getSPIE(uchar);
bit_t getCPOL(uchar);
uchar getPrescalingFactor(uchar SPCR);

void getCOMControl(uchar control, uchar *prescalingFactor, uchar *divisionFactor);
void setCPOL(uchar *, bit_t);

int main (void)
{
	uchar SPCR = 0xCE; /* 1100 1110 */

	printf("Interrupciones: %s\n", getSPIE(SPCR) ? "habilitadas" : " deshabilitadas");
	printf("Reloj activo: %s\n", getCPOL(SPCR) ? "nivel bajo" : "nivel alto");
	printf("Factor de division: %d\n", getPrescalingFactor(SPCR));
	
	printf("0x%X\n", SPCR);

	/* Sets CPOL bit to LOW */
	setCPOL(&SPCR, LO);

	printf("0x%X\n", SPCR);

	return 0;
}

bit_t getSPIE(uchar SPCR)
{
	return (SPCR & MASK_SPIE) >> SHIFT_SPIE;
}

bit_t getCPOL(uchar SPCR)
{
	return (SPCR & MASK_CPOL) >> SHIFT_CPOL;
}

uchar getPrescalingFactor(uchar SPCR)
{
	static uchar divFactor[4] = { 2, 4, 16, 32 };
	return divFactor[(SPCR & (MASK_SPR0 + MASK_SPR1)) >> SHIFT_SPR0];
}

void getCOMControl(uchar control, uchar *prescalingFactor, uchar *divisionFactor)
{
	if(!prescalingFactor || !divisionFactor) return;

	static uchar divFactor[4] = { 2, 4, 16, 32 };

	*prescalingFactor = ((control & (MASK_SPR0 + MASK_SPR1)) >> SHIFT_SPR0);
	*divisionFactor = divFactor[*prescalingFactor];
}

void setCPOL(uchar *control, bit_t CPOL)
{
	if(!control) return;

	*control = ((*control & ~MASK_CPOL) + (CPOL << SHIFT_CPOL));
}
