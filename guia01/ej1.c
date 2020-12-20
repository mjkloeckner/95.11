#include <stdio.h>

#define DIVISA_NAME_ARS	"Pesos"
#define DIVISA_NAME_BRL	"Reales"
#define DIVISA_NAME_USD	"Dolares"
#define DIVISA_NAME_EUR "Euros"

#define MAX_DIVISAS	4

typedef enum {
	ARS, BRL, USD, EUR
} divisa_t;


int main( void ) {

	divisa_t divisa_origen = ARS;
	divisa_t divisa_final = USD;

	float monto_origen, monto_final;

	monto_origen = 1000;
	


	float divisas[MAX_DIVISAS][MAX_DIVISAS] = {
		{1.000, 0.067, 0.012, 0.011},	//	ARS
		{0.067, 1.000, 0.190, 0.160},	//	BRL
		{0.012, 0.190, 1.000, 0.850},	//	USD
		{0.011, 0.160, 0.850, 1.000}	//	EUR
	};

	monto_final = (monto_origen * divisas[divisa_origen][divisa_final]);
	printf("%f\n", monto_final);

	return 0;
}


