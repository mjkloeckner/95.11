#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYS 3
#define LARGE_OF_ARRAYS 4

typedef struct {
	size_t n, m;
	int **a;
} array_t;

int arr_find_max(array_t *array);
void arr_create(size_t n, size_t m, array_t *array);
void arr_initran(array_t *array);
void arr_print(array_t *array);
void arr_destroy(array_t *array);

int main (void)
{
	array_t array;

	arr_create(ARRAYS, LARGE_OF_ARRAYS, &array);

	arr_initran(&array);

	arr_print(&array);

	printf("\nThe maximum value is: %d\n", arr_find_max(&array));

	arr_destroy(&array);
	return 0;
}


void arr_create(size_t n, size_t m, array_t *array)
{
	array->n = n; 
	array->m = m;

	array->a = (int **)malloc(n * sizeof(int *));

	for(size_t i = 0; i < n; i++)
		*(array->a + i) = (int *)malloc(m * sizeof(int));
}

void arr_destroy(array_t *array)
{
	for(size_t i = 0; i < array->n; i++)
		free(*(array->a + i));

	free(array->a);
}

void arr_initran(array_t *array)
{
	srand((unsigned int)time(NULL));
	
	for(size_t i = 0; i < array->n; i++)
		for(size_t j = 0; j < array->m; j++)
			array->a[i][j] = ((double)rand()/(double)(RAND_MAX)) * 20;
		
}

void arr_print(array_t *array)
{
	for(size_t i = 0; i < array->n; i++) {
		for(size_t j = 0; j < array->m; j++)
			printf("%2d ", array->a[i][j]);
		
		putchar('\n');
	}
}

int arr_find_max(array_t *array)
{
	int max = 0;
	for(size_t i = 0; i < array->n; i++)
		for(size_t j = 0; j < array->m; j++)
			if(array->a[i][j] > max)
				max = array->a[i][j];
	
	return max;
}
