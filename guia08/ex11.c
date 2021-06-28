/* guia08/ej11.c 
 * por Martin J. Klöckner
 * github.com/klewer-martin
 */

#include <stdio.h>
#include <stdlib.h>

#define ARR_INIT_SIZE	3
#define STR_INIT_SIZE	10

#define GROWTH_FACTOR	2

char **split(const char *s, char delim, size_t *fields);

int main (void)
{
	char csv[] = "Hola,Hello,Hallo,Aloha";
	char **arr;
	size_t i, len;

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

	char **arr;
	size_t i, arr_size, str_size;

	arr_size = ARR_INIT_SIZE;
	str_size = STR_INIT_SIZE;

	if(!(arr = (char **)calloc(sizeof(char *), arr_size))) return NULL;

	if(!(*arr = (char *)calloc(sizeof(char), str_size))) {
		free(arr)
		return NULL;
	}

	for(*fields = i = 0; *s; i++, s++) {
		/* If the array doesn't have any memory left then it gets more memory */
		if(*fields == (arr_size - 1)) {
			/* Exponential growth of the array */
			arr_size *= GROWTH_FACTOR;

			if(!(arr = (char **)realloc(arr, arr_size * sizeof(char *)))) {
				/* If it can't get more memory then all the previous allocations gets freed */
				while((*fields) + 1) free(arr[(*fields)--]);
				free(arr);
				return NULL;
			}
		}

		if(*s == delim) {			
			/* Gets memory for a new string and increments arr index by one */
			if(!(arr[++(*fields)] = (char *)calloc(sizeof(char), str_size))) {
				/* If it can't get more memory then all the previous allocations gets freed */
				while(*fields)
					free(arr[(*fields)--]);

				free(arr);
				return NULL;
			}
			i = 0;
			s++;
		}
		/* This makes sure that every string has available memory, if not then it gets more */
		if(i == (str_size - 2))
		{
			str_size *= GROWTH_FACTOR;
			if(!(arr[*fields] = (char *)realloc(arr[*fields], str_size))) {
				/* If it can't get more memory all the previous used memmory gets freed */
				while((*fields) + 1)
					free(arr[(*fields)--]);

				free(arr);
				return NULL;
			}
			/* Sets all the new memory to the null character */
			for(size_t j = i; j < str_size; j++) (*arr)[j] = '\0';
		}
		arr[*fields][i] = (*s);
	}
	return arr;
}
