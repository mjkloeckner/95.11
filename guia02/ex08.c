#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 5	// max digits of the entered degree;
#define ERR_MSG_LEN "El angulo ingresado contiene demasiados digitos"

#define FST_YR 48
#define SND_YR 95
#define TRD_YR 143


typedef enum {
	FIRST, SECOND, THIRD, FOURTH
} year_t;


void clean(char *buffer)
{
	for(size_t i = 0; i < MAX_LEN; i++)
		buffer[i] = '\0';
}


int main(void) {
	
	char buffer[MAX_LEN];
	clean(buffer);
	int c, d, i;
	year_t e;
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

	if (d <= FST_YR) 
		e = FIRST;
	else if ((d > FST_YR) && (d <= SND_YR))
		e = SECOND;
	else if ((d > SND_YR) && d <= (TRD_YR))
		e = THIRD;
	else if (d > TRD_YR) 
		e = FOURTH;


	switch (e)
	{
		case FIRST:
			printf("Primer año\n");
			break;
		case SECOND:
			printf("Segundo año\n");
			break;
		case THIRD:
			printf("Tercer año\n");
			break;
		case FOURTH:
			printf("Curto año o superior\n");
			break;
	}
	return 0;
}




