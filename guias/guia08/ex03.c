#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *right_trim(const char *);

int main (void)
{
	char str[] = "Hola mundo     ";
	char *dst;

	printf("%s\n", str);
	printf("len %ld\n", strlen(str));

	dst = right_trim(str);
	printf("%s\n", dst);
	printf("len %ld\n", strlen(dst));

	free(dst);
	return 0;
}

char *right_trim(const char *src)
{
	char *dst;
	size_t i;

	/* Counts blank spaces */
	for(i = strlen(src); src[i - 1] == ' '; i--);

	/* +1 for the null character */
	if(!(dst = (char *)malloc((i + 1) * sizeof(char))))
		return NULL;

	strncpy(dst, src, i);
	dst[i] = '\0';
	return dst;
}
