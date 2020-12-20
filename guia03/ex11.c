#include <stdio.h>
#include <ctype.h>

int main(void) 
{
	char str[] = "hello world";
	int i;
	char aux;

	for(i = 0; (aux = str[i]) != '\0'; i++)
		if(islower(aux))
			str[i] = toupper(aux);

	printf("%s\n", str);
	return 0;
}



