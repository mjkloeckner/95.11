#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { TRUE, FALSE } bool_t;

 
bool_t is_empty_string(const char *); 
 
int main (void)
{
	char str[] = "Hello";
	char str_empty[] = "";

	printf("%s\n", str);
	printf("La cadena %s vacia\n", is_empty_string(str) ? "no esta" : "esta");

	printf("%s\n", str_empty);
	printf("La cadena %s vacia\n", is_empty_string(str_empty) ? "no esta" : "esta");

	return 0;
}

bool_t is_empty_string(const char *str)
{
	if(!strcmp(str, ""))
		return TRUE;

	return FALSE;
}
