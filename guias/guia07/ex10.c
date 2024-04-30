#include <stdio.h>

#define MASK_AFT	0x80
#define MASK_BAND	0x40
#define MASK_FDIV	0x3E	/* 0011 1110 */
#define MASK_SYN	0x01

#define SHIFT_AFT	7
#define SHIFT_BAND	6
#define SHIFT_FDIV	1

typedef unsigned char uchar;
typedef enum { BAND_FM, BAND_AM } band_t;
typedef enum { OK, ERROR_NULL_POINTER } status_t;

uchar get_synthesizer_divider(uchar control);

status_t set_synthesizer_divider(uchar fdiv, uchar *control);

band_t get_band(uchar control);

uchar set_band(uchar control, band_t new_band);

int main (void)
{
	uchar reg = 0x3C;	/* 0011 1100 */

	printf("%d\n", get_synthesizer_divider(reg));

	set_synthesizer_divider(4, &reg);

	printf("%d\n", get_synthesizer_divider(reg));

	printf("%s\n", get_band(reg) ? "BAND: AM" : "BAND: FM");

	reg = set_band(reg, BAND_AM);

	printf("%s\n", get_band(reg) ? "BAND: AM" : "BAND: FM");

	return 0;
}

uchar get_synthesizer_divider(uchar control)
{
	return (((control & MASK_FDIV) >> SHIFT_FDIV) + 1);
}

status_t set_synthesizer_divider(uchar fdiv, uchar *control)
{
	if(!control) return ERROR_NULL_POINTER;

	*control = (*control & ~MASK_FDIV) + ((fdiv - 1) << SHIFT_FDIV);

	return OK;
}

band_t get_band(uchar control)
{
	return (control & MASK_BAND) >> SHIFT_BAND;
}

uchar set_band(uchar control, band_t new_band)
{
	return ((control & ~MASK_BAND) + (new_band << SHIFT_BAND));
}
