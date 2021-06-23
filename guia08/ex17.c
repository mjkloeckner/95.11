#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10
#define GROWTH_FACTOR .5

char *read_line(void);

int main (void)
{
	char *str = NULL;

	str = read_line();
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
	printf("allocating: %ld bytes\n", alloc_size * sizeof(char));

	for(i = 0; (aux = fgetc(stdin)) != EOF; i++)
	{
		if(i == (alloc_size - 2))
		{
			printf("\nReallocating\ni: %ld\nold size: %ld\n", i, alloc_size);
			alloc_size += (alloc_size * GROWTH_FACTOR);
			printf("new size: %ld\n", alloc_size);
			if(!(dst = (char *)realloc(dst, alloc_size * sizeof(char)))) return NULL;
			for(size_t j = i; j < alloc_size; j++) dst[j] = '\0';
		}
		dst[i] = aux;
	}
	return dst;
}
