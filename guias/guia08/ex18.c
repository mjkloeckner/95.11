#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10
#define GROWTH_FACTOR .5

typedef enum {
	OK,
	ERROR_ALLOC_MEMORY,
	ERROR_NULL_POINTER
} status_t;

status_t fread_line(FILE *, char **);

int main (void)
{
	char *str;

	fread_line(stdin, &str);
	printf("%s", str);

	free(str);
	return 0;
}

status_t fread_line(FILE *fp, char **dst)
{
	int aux;
	size_t i, alloc_size;

	if(!dst || !fp) return ERROR_NULL_POINTER;

	alloc_size = INIT_SIZE;

	if(!(*dst = (char *)calloc(alloc_size, sizeof(char)))) return ERROR_ALLOC_MEMORY;

	for(i = 0; (aux = fgetc(fp)) != EOF; i++)
	{
		if(i == (alloc_size - 2))
		{
			alloc_size += (alloc_size * GROWTH_FACTOR);
			if(!(*dst = (char *)realloc(*dst, alloc_size * sizeof(char)))) return ERROR_ALLOC_MEMORY;
			/* Fills the new memory with zeros to avoid valgrind uninitialized warning */
			for(size_t j = i; j < alloc_size; j++) (*dst)[j] = '\0';
		}
		(*dst)[i] = aux;
	}
	return OK;
}
