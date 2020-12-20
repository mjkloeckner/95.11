/*	Ejercicio 4 - Guia 2, Algoritmos y Programacion I - FIUBA	*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_INP_LEN 10

typedef enum {
	FAHRENHEIT,
	CELSIUS
} escala_t;

typedef float dato_t;	
					
dato_t ftoc(dato_t fahrenheit)
{
	return (((fahrenheit - 32) *5 ) / 9);
}

dato_t ctof(dato_t celsius)
{
	return (((celsius * 9) / 5) + 32);
}

void title(int i)
{
	printf(
		"---------------------------------------\n"
		"---------------------------------------\n"
		"--- %s TO %s CONVERTER ---\n"
		"---------------------------------------\n"
		"---      to exit press Ctrl+D      ----\n"
		"---------------------------------------\n"
		"---------------------------------------\n",
		i ? "CELSIUS" : "FAHRENHEIT",
		i ? "FAHRENHEIT" : "CELSIUS"
	);
}

void cursor()
{
	printf(">> ");
}



int main(void)
{
	char buffer[MAX_INP_LEN];
	escala_t c;
	dato_t i, res;
	printf("0 - FAHRENHEIT TO CELSIUS\n");
	printf("1 - CELSIUS TO FAHRENHEIT\n");
	cursor();
	c = getchar() - '0';
	if (c == FAHRENHEIT) {
		title(FAHRENHEIT);
		while (fgets(buffer, MAX_INP_LEN, stdin) != NULL) {
			i = atoi(buffer);
			res = ftoc(i);
			printf("%.0f°F = %.2f°C\n", i, res);
			cursor();
		}
	} else if (c == CELSIUS) {
		title(CELSIUS);
		while (fgets(buffer, MAX_INP_LEN, stdin) != NULL) {
			i = atoi(buffer);
			res = ctof(i);
			printf("%.0f°C = %.2f°F\n", i, res);
			cursor();
		}
	}
	printf("\n");
	return 0;
}



