#include <stdio.h>
#include <stdlib.h>

#define MSG_ERR_NO_ARG "Error: No arguments"

#define STR_ARG_POS	1

int main (int argc, char *argv[]) {

	if(argc == 1) {
		fprintf(stderr, "%s\n", MSG_ERR_NO_ARG);
		return 1;
	}

	size_t i = 0;
    while((*(argv + STR_ARG_POS))[++i])
		;

	printf("%ld\n", i);

    return EXIT_SUCCESS;
}
