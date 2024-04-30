#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 5	// max digits of the entered degree;
#define ERR_MSG_LEN "El angulo ingresado contiene demasiados digitos"

typedef enum {
	AGUDO, OBTUSO, RECTO
} angulo_t;


void clean(char *buffer)
{
	for(size_t i = 0; i < MAX_LEN; i++)
		buffer[i] = '\0';
}


int main(void) {
	
	char buffer[MAX_LEN];
	clean(buffer);
	int c, d, e, i;
	i = 0;		
	while(((c = getchar()) != EOF) && c != '\n') {
		if(i < MAX_LEN) {
			buffer[i] = c;
			i++;
		} else if (i >= MAX_LEN) {
			fprintf(stderr, ERR_MSG_LEN"\n");
			return 1;
		}
	}
	d = atoi(buffer);

	if (d < 90)
		e = AGUDO;
	else if (d == 90)
		e = RECTO;
	else if (d > 90)
		e = OBTUSO;


	switch (e)
	{
		case AGUDO:
			printf("El angulo es AGUDO\n");
			break;
		case RECTO:
			printf("El angulo es RECTO\n");
			break;
		case OBTUSO:
			printf("El angulo es OBTUSO\n");
			break;
	}
	return 0;
}




