#include <stdio.h>
#include <string.h>



int main(void) {

	char origen[] = "Hello world!\n";
	size_t i, len;

	len = strlen(origen);	
	char destino[len]; /*	+1 for the '\0'	*/

	for(i = 0; i <= len; i++)
		destino[i] = origen[i];

	printf("%s", origen);
	printf("%s", destino);

	return 0;
}
