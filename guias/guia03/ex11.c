#include <stdio.h>
#include <ctype.h>

int main(void) 
{
	int i, aux;
	char str[] = "hello world";

	for(i = 0; aux = str[i]; i++)
		if((aux < 123) && (aux > 96))
			str[i] = (aux - 32);

	printf("%s\n", str);
	return 0;
}
