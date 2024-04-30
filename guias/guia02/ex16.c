#include <stdio.h>

#define TRUE 0

#ifdef TRUE
	#undef TRUE
	#define TRUE 1
#endif

int main(void) 
{
	printf("TRUE = %d\n", TRUE);
	return 0;
}


