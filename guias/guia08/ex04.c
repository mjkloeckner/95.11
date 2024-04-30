#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *full_trim(const char *);

int main (void)
{
	char str[] = "  Hello world!";
	char *dst;

	printf("%s\nlen %ld\n", str, strlen(str));
	dst = full_trim(str);
	printf("%s\nlen %ld\n", dst, strlen(dst));
	
	return 0;
}

char *full_trim(const char *src)
{
	char *dst;	
	size_t i, j, len;

	len = strlen(src);

	/* Counts starting blank spaces */
	for(i = 0; src[i] == ' '; i++);

	/* Counts ending blank spaces */
	for(j = len; src[j - 1] == ' '; j--);

	if(!(dst = (char *)calloc(j - i, sizeof(char))))
		return NULL;

	strcpy(dst, src + i);
	dst[j - i] = '\0';
	return dst;
}
