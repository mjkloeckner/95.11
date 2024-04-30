#include <stdio.h>
#include <string.h>

int main(void) {

	char s[] = "Hello world!\n";
	int i, aux;

	for(i = strlen(s); i >= 0; i--) {
		aux = s[i];
		if(aux != '\n')
			putchar(aux);
	}
	putchar('\n');
	return 0;
}
