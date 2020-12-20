/*	Reads a number of credits from stdin and prints the corresponding
	grade of the Engineer in stdout*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 5	// max digits of the entered degree;
#define ERR_MSG_LEN "El numero ingresado contiene demasiados digitos"
#define ERR_NEG_MSG "El numero ingresado no es valido"

#define FST_YR 52
#define SND_YR 104
#define TRD_YR 156

#define FST_MSG "Primer año"
#define SND_MSG "Segundo año"
#define TRD_MSG "Tercer año"
#define FTH_MSG "Cuarto año"

typedef enum {
	FIRST, SECOND, THIRD, FOURTH
} year_t;

typedef enum {
	OK, ERROR
} status_t;

status_t clean(char *buffer)
{
	if(buffer == NULL)
		return ERROR;

	for(size_t i = 0; i < MAX_LEN; i++)
		buffer[i] = '\0';
	
	return OK;
}


int main(void) {
	
	/*	Defining variables	*/
	char buffer[MAX_LEN]; 
	int c, credits, i;
	year_t year;
	i = 0;		
	
	/*	Cleaning buffer in case it contains a random number	*/ 
	if(clean(buffer) == ERROR)
		return ERROR;
	
	/*	Reading one char from stdin and storing it on a buffer until EOF	*/
	while(((c = getchar()) != EOF) && c != '\n') {
		if(i < MAX_LEN) {
			buffer[i] = c;
			i++;
		} else if (i >= MAX_LEN) {
			fprintf(stderr, ERR_MSG_LEN"\n");
			return 1;
		}
	}
	
	/*	Converting the first portion of buffer to int with atoi() 
		and cleaning the buffer	*/
	credits = atoi(buffer);
	if(clean(buffer) == ERROR)
		return ERROR;

	/*	Checks if credits is a valid number	*/
	if(credits < 0) {
		fprintf(stderr, ERR_NEG_MSG"\n");
		return 1;
	}

	/*	Evaluating the numbers of credits to match the current year 	*/
	if (credits <= FST_YR) 
		year = FIRST;
	else if ((credits > FST_YR) && (credits <= SND_YR))
		year = SECOND;
	else if ((credits > SND_YR) && (credits <= TRD_YR))
		year = THIRD;
	else if (credits > TRD_YR) 
		year = FOURTH;

	/*	Printing to stdout the corresponding year	*/
	switch (year)
	{
		case FIRST:
			printf(FST_MSG"\n");
			break;
		case SECOND:
			printf(SND_MSG"\n");
			break;
		case THIRD:
			printf(TRD_MSG"\n");
			break;
		case FOURTH:
			printf(FTH_MSG"\n");
			break;
	}
	return OK;
}




