#include <stdio.h>
#include <ctype.h>

int main(void) 
{
	char str[] = "HELLO WORLD";
	int i;
	char aux;

	for(i = 0; (aux = str[i]) != '\0'; i++)
		if(isupper(aux))
			str[i] = tolower(aux);

	printf("%s\n", str);
	return 0;
}



