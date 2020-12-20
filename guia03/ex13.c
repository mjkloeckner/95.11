//	Reads a string from stdin and converts it to uppercase or lowercase 
//	depending on an option readed from stdin


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MSG_STR_PROMPT	"Introduzca una cadena:"
#define MSG_FMT_PROMPT	"Convertir a: (0 - MAYUSCULAS / 1 - MINUSCULAS)"
#define MSG_FMT_ERR		"Err: Formato incorrecto"

#define MAX_STR_LEN 100

typedef enum {
	FMT_MAYUSCULAS, FMT_MINUSCULAS
} format_t;


int main ( void ) {


	char buffer[MAX_STR_LEN];
	char str[MAX_STR_LEN];
	format_t format;


	printf(MSG_STR_PROMPT"\n>> ");
	fgets(buffer, MAX_STR_LEN, stdin);
	strcpy(str, buffer);

	printf(MSG_FMT_PROMPT"\n>> ");
	format = (getchar () - '0');
	if((format < 0) || (format > 1)) {
		fprintf(stderr, MSG_FMT_ERR"\n");
		return 1;
	}

	printf("La cadena ingresada: %sOpcion elegida: %d\n", str, format);			

	int i, aux;
	switch(format)
	{
		case FMT_MAYUSCULAS: 
			for(i = 0; (aux = str[i]) != '\n'; i++) {
				if(islower(aux))
					str[i] = toupper(aux);
			}
			break;
		case FMT_MINUSCULAS:
			for(i = 0; (aux = str[i]) != '\n'; i++) {
				if(isupper(aux))
					str[i] = tolower(aux);
			}
			break;
	}

	printf("%s", str);
	return 0;
}
