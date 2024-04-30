#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *left_trim(const char *);

int main (void)
{
	char str[] = "     Hola mundo";

	printf("%s\n", str);

	printf("%s\n", left_trim(str));

	return 0;
}

char *left_trim(const char *src)
{
	char *dst;

	/* Counts blank spaces */
	size_t i = 0;
	while(src[i] == ' ') i++;

	/* +1 for the null character */
	if(!(dst = (char *)malloc((strlen(src) - i + 1) * sizeof(char))))
		return NULL;

	strcpy(dst, src + i);
	return dst;
}
