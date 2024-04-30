#include <stdio.h>


#define TM "3M Corporation"
#define MAXWELL "Maxwell Corporation"
#define SONY "Sony Corporation"
#define VERBATIM "Verbatim Corporation"

typedef enum {
	TM_CORPORATION,
	MAXWELL_CORPORATION,
	SONY_CORPORATION,
	VERBATIM_CORPORATION
} manufacturer_t;


int main(void) {
	manufacturer_t c;
	printf("Introduzca un Id. de fabricante: ");
	c = (getchar() - '0');
	switch(c) {
		case TM_CORPORATION:
			printf(TM"\n");
			break;
		case MAXWELL_CORPORATION:
			printf(MAXWELL"\n");
			break;
		case SONY_CORPORATION:
			printf(SONY"\n");
			break;
		case VERBATIM_CORPORATION:
			printf(VERBATIM"\n");
			break;
		default:
			printf("El numero ingresado no es valido\n");
			return 1;
	}
	return 0;
}
