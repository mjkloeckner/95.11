#include <stdio.h>
#include <string.h>

void clean(char * buffer)
{
	puts(buffer);
	printf("%lu\n", strlen(buffer));
	while(*buffer != '\0')
	{
		(*buffer) = ' ';
		buffer++;
	}
}

int main (void)
{
	char str[] = "Hello world!";
	puts(str);

	clean(str);
	puts(str);

	return 0;
}
