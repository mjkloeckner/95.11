#include <stdio.h>

#define LANGUAGE GER	//	Define language in which month are displyed ESP,GER,ENG

#if LANGUAGE == ESP
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
#elif LANGUAGE == GER 
	#define JANUARY		"JANUAR"
	#define FEBRUARY	"FEBRUAR"
	#define MARCH 		"MÄRZ"
	#define APRIL		"APRIL"
	#define MAYO		"MAI"
	#define JUNE		"JUNI"
	#define JULY		"JULI"
	#define AUGUST		"AUGUST"
	#define SEPTEMBER	"SEPTEMBER"
	#define OCTOBER		"OKTOBER"
	#define NOVEMBER	"NOVEMBER"
	#define DECEMBER	"DEZEMBER"
#else 
	#define JANUARY		"JANUARY"
	#define FEBRUARY	"FEBRUARY"
	#define MARCH 		"MARCH"
	#define APRIL		"ABPRIL"
	#define MAYO		"MAY"
	#define JUNE		"JUNE"
	#define JULY		"JULY"
	#define AUGUST		"AUGUST"
	#define SEPTEMBER	"SEPTEMBER"
	#define OCTOBER		"OCTOBER"
	#define NOVEMBER	"NOVEMBER"
	#define DECEMBER	"DECEMBER"
#endif

typedef enum {
	JAN, FEB, MAR, APR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DEC
} mes_t;

int main(void) {
	mes_t mes = MAR;
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
