/* guia08/ej11.c + CLA
 * por Martin J. Klöckner
 * github.com/klewer-martin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGS	2	/* Program name and file to read name */
#define FILE_NAME_POS	1

#define MSG_USAGE	"Usage: ./a.out <file name>"

#define ARR_INIT_SIZE	3
#define STR_INIT_SIZE	10

#define GROWTH_FACTOR	2

#define LOAD_FILE_BUFFER_SIZE 100

typedef enum {
	OK,
	ERROR_PROGRAM_INVOCATION,
	ERROR_OPENING_FILE,
	ERROR_ALLOC_MEMORY,
	ERROR_NULL_POINTER
} status_t;

status_t validate_arguments(int argc, char *argv[]);

status_t load_file(const char *file_name, char **array);
char **split(const char *s, char delim, size_t *fields);

int main (int argc, char *argv[])
{
	char **arr, *input;
	size_t i, len;
	status_t st;

	if((st = validate_arguments(argc, argv))) {
		fprintf(stderr, "%s\n", MSG_USAGE);
		return ERROR_PROGRAM_INVOCATION;
	} 

	if((st = load_file(argv[FILE_NAME_POS], &input))) return st;

	if(!(arr = split(input, ',', &len))) return 1;

	for(i = 0; i <= len; i++)
		printf("%s\n", arr[i]);

	while(len + 1) free(arr[len--]);

	free(arr);
	free(input);

	return 0;
}

status_t validate_arguments(int argc, char *argv[])
{
	if(!argv) return ERROR_NULL_POINTER;
	if(argc != ARGS) return ERROR_PROGRAM_INVOCATION;

	return OK;
}

status_t load_file(const char *file_name, char **array)
{
	FILE *fp;
	size_t alloc_size;

	if(!(fp = fopen(file_name, "rt"))) return ERROR_OPENING_FILE;

	alloc_size = LOAD_FILE_BUFFER_SIZE;
	if(!(*array = calloc(sizeof(char), alloc_size))) return ERROR_ALLOC_MEMORY;

	for(size_t i = 0; ((*array)[i] = fgetc(fp)) != EOF; i++) {
		if(i == (alloc_size - 2)) {
			alloc_size *= 2;
			if(!(*array = realloc(*array, alloc_size))) {
				free(*array);
				array = NULL;
				fclose(fp);
				return ERROR_ALLOC_MEMORY;
			}
		}
	}

	fclose(fp);
	return OK;
}

/* Recibe una cadena de caracteres de longitud desconocida, con valores separados por un caracter delimitador y los separa en cadenas de caracteres de longitud dinamica */
char **split(const char *s, char delim, size_t *fields)
{
	if(!s || !fields) return NULL;

	char **arr;
	size_t i, arr_size, str_size;

	arr_size = ARR_INIT_SIZE;
	str_size = STR_INIT_SIZE;

	if(!(arr = (char **)calloc(sizeof(char *), arr_size))) return NULL;

	if(!(*arr = (char *)calloc(sizeof(char), str_size))) {
		free(arr);
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
		if((*s == delim) || (*s == '\n')) {	
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
		/* This makes sure that the current string has available memory, if not then it gets more */
		if(i == (str_size - 2)) {
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
	free(arr[(*fields)--]);
	return arr;
}
