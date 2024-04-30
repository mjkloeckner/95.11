#include <stdio.h>

typedef enum {
		FALSE,
		TRUE
} bool_t; 

int main(void)
{
	bool_t isworking = TRUE;
	printf("%s\n", isworking ? "TRUE" : "FALSE");

	return 0;
}


