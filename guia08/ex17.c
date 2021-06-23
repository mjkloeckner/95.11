#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10
#define GROWTH_FACTOR .5

char *read_line(void);
char *fread_line(FILE *);

int main (void)
{
	char *str = NULL;

	str = fread_line(stdin);
	printf("%s", str);

	free(str);
	return 0;
}

char *read_line(void)
{
	char *dst;
	int aux;
	size_t i, alloc_size;

	alloc_size = INIT_SIZE;

	if(!(dst = (char *)calloc(alloc_size, sizeof(char)))) return NULL;

	for(i = 0; (aux = fgetc(stdin)) != EOF; i++)
	{
		if(i == (alloc_size - 2))
		{
			alloc_size += (alloc_size * GROWTH_FACTOR);
			if(!(dst = (char *)realloc(dst, alloc_size * sizeof(char)))) return NULL;
			for(size_t j = i; j < alloc_size; j++) dst[j] = '\0';
		}
		dst[i] = aux;
	}
	return dst;
}

char *fread_line(FILE *fp)
{
	char *dst;
	int aux;
	size_t i, alloc_size;

	alloc_size = INIT_SIZE;

	if(!(dst = (char *)calloc(alloc_size, sizeof(char)))) return NULL;

	for(i = 0; (aux = fgetc(fp)) != EOF; i++)
	{
		if(i == (alloc_size - 2))
		{
			alloc_size += (alloc_size * GROWTH_FACTOR);
			if(!(dst = (char *)realloc(dst, alloc_size * sizeof(char)))) return NULL;
			for(size_t j = i; j < alloc_size; j++) dst[j] = '\0';
		}
		dst[i] = aux;
	}
	return dst;
}
