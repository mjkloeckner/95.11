#include <stdio.h>
#include <ctype.h>

int main(void) 
{
	char str[] = "HELLO WORLD";
	int i;
	char aux;

	for(i = 0; aux = str[i]; i++)
		if((aux > 64) && (aux < 91))
			str[i] = aux + 32;

	printf("%s\n", str);
	return 0;
}



