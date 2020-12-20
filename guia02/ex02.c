#include <stdio.h>

typedef enum {
		ERROR,
		OK
} status_t; 

int main(void)
{

	status_t isworking = OK;

	if (isworking == 1)
		printf("OK\n");
	else
		printf("ERROR\n");

	return 0;
}


