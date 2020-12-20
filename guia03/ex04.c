#include <stdio.h>
#include <string.h>

int main(void) {

	char s[] = "Hello world!\n";
	char aux;
	int n;

	for(n = strlen(s); n >= 0; n--) {
		aux = s[n];
		if(aux != '\n')
			putchar(aux);
	}
	putchar('\n');
	return 0;
}
