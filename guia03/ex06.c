#include <stdio.h>
#include <string.h>



int main(void) {

	char origen[] = "Hello world!\n";
	size_t i, len;
	len = strlen(origen);	
	char destino[len];

	for(i = 0; i <= len; i++) {
		destino[i] = origen[i];
		if(i == len)
			destino[i + 1] = '\0';
	}

	printf("%s", origen);
	printf("%s", destino);


	return 0;
}
