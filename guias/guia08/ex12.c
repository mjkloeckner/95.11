/* guia08/ej12.c + CLA
 * por Martin J. Klöckner
 * github.com/klewer-martin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_POS	1
#define ARGS			2

#define MSG_USAGE		"Usage: ./a.out <file name>"

#define GROWTH_FACTOR	2

#define ARR_INIT_SIZE	1000
#define STR_INIT_SIZE	2

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
status_t split(const char *s, char ***array, char delim, size_t *fields);

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

	if((st = split(input, &arr, ',', &len))) return st;

	free(input);

	for(i = 0; i <= len; i++)
		printf("%s\n", arr[i]);

	while(len + 1) free(arr[len--]);

	free(arr);

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
status_t split(const char *s, char ***array, char delim, size_t *fields)
{
	if(!s || !fields) return ERROR_NULL_POINTER;

	size_t i, arr_size, str_size;

	arr_size = ARR_INIT_SIZE;
	str_size = STR_INIT_SIZE;

	if(!(*array = (char **)calloc(sizeof(char *), arr_size))) return ERROR_ALLOC_MEMORY;

	if(!(**array = (char *)calloc(sizeof(char), str_size))) { free(*array); return ERROR_ALLOC_MEMORY; }

	for(*fields = i = 0; *s; i++, s++) {
		/* If the array doesn't have any memory left then it gets more memory */
		if(*fields == (arr_size - 1)) {
			/* Exponential growth of the array */
			arr_size *= GROWTH_FACTOR;
			if(!(*array = (char **)realloc(*array, arr_size * sizeof(char *)))) {
				/* If it can't get more memory then all the previous allocations gets freed */
				while((*fields) + 1) free((*array)[(*fields)--]);
				free(*array);
				return ERROR_ALLOC_MEMORY;
			}
		}
		if((*s == delim) || (*s == '\n')) {
			str_size = STR_INIT_SIZE;
			if(!((*array)[++(*fields)] = (char *)calloc(sizeof(char), str_size))) {
				/* If it can't get more memory then all the previous allocations gets freed */
				while(*fields)
					free((*array)[(*fields)--]);

				free(*array);
				return ERROR_ALLOC_MEMORY;
			}
			s++; i = 0;
		}
		/* This makes sure that the current string has available memory, if not then it gets more */
		if(i == (str_size - 2)) {
			str_size *= GROWTH_FACTOR;
			if(!((*array)[*fields] = (char *)realloc((*array)[*fields], str_size))) {
				/* If it can't get more memory all the previous used memmory gets freed */
				while((*fields) + 1)
					free((*array)[(*fields)--]);

				free(*array);
				return ERROR_ALLOC_MEMORY;
			}
		}
		(*array)[*fields][i] = (*s);
	} /* End for loop */

	free((*array)[(*fields)--]);
	return OK;
}
