#include <stdio.h>

#define LANG_DE

#ifdef LANG_ES
	#include "include/LANG_ES.h"
#elif defined LANG_EN
	#include "include/LANG_EN.h"
#elif defined LANG_DE
	#include "include/LANG_DE.h"
#endif

typedef enum { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC } month_t;

int main (void)
{
	month_t month;

	month = MAR;

	printf("Month: %s\n", months[month]);
	
	return 0;
}
