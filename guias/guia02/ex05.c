#include <stdio.h>

typedef enum {
	JAN, FEB, MAR, APR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DEC
} mes_t;

#define JANUARY		"ENERO"
#define FEBRUARY	"FEBRERO"
#define MARCH 		"MARZO"
#define APRIL		"ABRIL"
#define MAYO		"MAYO"
#define JUNE		"JUNIO"
#define JULY		"JULIO"
#define AUGUST		"AGOSTO"
#define SEPTEMBER	"SEPTIEMBRE"
#define OCTOBER		"OCTUBRE"
#define NOVEMBER	"NOVIEMBRE"
#define DECEMBER	"DICIEMBRE"

int main(void) {
	mes_t mes = NOV;
	switch(mes)
	{
		case JAN:
			printf(JANUARY"\n");
			break;
		case FEB:
			printf(FEBRUARY"\n");
			break;
		case MAR:
			printf(MARCH"\n");
			break;
		case APR:
			printf(APRIL"\n");
			break;
		case MAY:
			printf(MAYO"\n");
			break;
		case JUN:
			printf(JUNE"\n");
			break;
		case JUL:
			printf(JULY"\n");
			break;
		case AGO:
			printf(AUGUST"\n");
			break;
		case SEP:
			printf(SEPTEMBER"\n");
			break;
		case OCT:
			printf(OCTOBER"\n");
			break;
		case NOV:
			printf(NOVEMBER"\n");
			break;
		case DEC:
			printf(DECEMBER"\n");
			break;
	}	
	return 0;
}
