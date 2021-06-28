#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strclone(char *);

int main (void) {
	char str[] = "Hello, world!";
	char *cpy;

	if(!(cpy = strclone(str))) return 1;

	printf("%s\n", cpy);

	free(cpy);
	return 0;
}

char *strclone(char *s)
{
	if(!s) return NULL;

	char *c;

	/* +1 for the null character */
	if(!(c = (char *)calloc(sizeof(char), (strlen(s) + 1)))) return NULL;

	for(size_t i = 0; *s; s++, i++) c[i] = *s;

	return c;
}
