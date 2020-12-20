#include <stdio.h>
#include <stdlib.h>

#define ERR_ARG "Error: No arguments"

int main (int argc, char *argv[]) {
    size_t i;
	if(argc == 1) {
		fprintf(stderr, ERR_ARG"\n");
		return 1;
	}

    printf("argc: %d \n", argc);

    for (i = 0; i < argc; i++) {
    	printf("argv[%ld] = %s \n", i, argv[i]);
    }

    return EXIT_SUCCESS;
}
