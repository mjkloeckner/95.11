#include <stdio.h>
#include <string.h>

typedef enum {
	OK,
	ERROR_NULL_POINTER
} status_t;

status_t string_reverse(char *);
void swap_char(char *a, char *b);

int main (void)
{
	char str[] = "Hello world!";

	puts(str);
	string_reverse(str);
	puts(str);

	return 0;
}

status_t string_reverse(char *str)
{
	if(str == NULL) return ERROR_NULL_POINTER;

	size_t len = strlen(str);
	for(size_t i = 0; i < (len / 2); i++)
		swap_char(&str[i], &str[len - 1 - i]);

	return OK;
}

void swap_char(char *a, char *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
