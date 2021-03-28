#include <stdio.h>

typedef enum { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC } month_t;

const char months[][10] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"  };

int main (void)
{
	month_t month;

	month = MAR;

	printf("Month: %s\n", months[month]);
	
	return 0;
}
