/*	G04E08 - Different declarations of arrays and pointers
 *	by Martin J. Kloeckner	
 *	github.com/klewer-martin	*/

#include <stdio.h>
#include <string.h>

int main (void)
{
	char cadena1[] = "Hola"; 
	char *cadena2 = "Hola"; 
	/* The difference is that cadena1 is an array that contains the secuence of chars "Hola", and cadena2 is a pointer which points to an array of chars that contains "Hola"; */


	char meses1 [12][] = {"Enero", "Febrero", ... , "Diciembre"}; 
	char * meses2 [12] = {"Enero", "Febrero", ... , "Diciembre"}; 
	/* Similar as the previous example, meses1 is an array of arrays of chars, and meses2 is a pointer to an array of chars which the maximum length is 12; */

	/* The first of this statements doesn't work because cadena1 is an array so the adress can't be modified; cadena2 instead is a pointer, so we are just pointing cadena2 to "Chau". */
	cadena1 = "Chau";
	cadena2 = "Chau"; 
	
	/* The first statement works because, it's how strcpy is intended to be used, the third statement its wrong because it's trying to copy more characters than cadena1 it's meant to hold, and the second statement won't work because strcpy treats the first argument as an array, and cadena2 ain't an array  */ 
	strcpy(cadena1,"Chau"); 
	strcpy(cadena2,"Chau"); 
	strcpy(cadena1,"Hola y chau"); 

	return 0;
}
