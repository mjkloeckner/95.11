/* guia08/ej11.c 
 * por Martin J. Klöckner
 * github.com/klewer-martin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_INIT_SIZE	3
#define STR_INIT_SIZE	10

#define GROWTH_FACTOR	2

char **split(const char *s, char delim, size_t *fields);

int main (void)
{
	char csv[] = "Hola,Hello,Hallo,Aloha";
	char **arr, d[1];
	size_t i, len;

	d[0] = delim;

	if(!(arr = split(csv, ',', &len))) return 1;

	for(i = 0; i <= len; i++)
		puts(arr[i]);

	while(len + 1) free(arr[len--]);

	free(arr);

	return 0;
}

char **split(const char *s, char delim, size_t *fields)
{
	if(!s || !fields) return NULL;

	char **arr, *p;
	size_t i, arr_size, str_size;

	arr_size = ARR_INIT_SIZE;
	str_size = STR_INIT_SIZE;

	if(!(arr = (char **)calloc(sizeof(char *), arr_size))) return NULL;

	if(!(*arr = (char *)calloc(sizeof(char), str_size))) {
		free(arr);
		return NULL;
	}

	*fields = i = 0;
	while(*p = strtok(s, delim));

	return arr;
}
