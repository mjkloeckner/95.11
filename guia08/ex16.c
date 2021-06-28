#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	OK,
	ERROR_MEMORY_ALLOC,
	ERROR_NULL_POINTER
} status_t;

status_t strclone(const char *, char **);

int main (void) {
	char str[] = "Hello, world!";
	char *cpy;
	status_t st;

	if((st = strclone(str, &cpy))) return st;

	printf("%s\n", cpy);

	free(cpy);
	return 0;
}

status_t strclone(const char *s, char **d)
{
	if(!s || !d) return ERROR_NULL_POINTER;

	/* +1 for the null character */
	if(!(*d = (char *)calloc(sizeof(char), (strlen(s) + 1)))) return ERROR_MEMORY_ALLOC;

	for(size_t i = 0; *s; s++, i++) (*d)[i] = *s;

	return OK;
}
