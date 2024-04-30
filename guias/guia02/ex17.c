#include <stdio.h>

int main(void)
{
	#ifdef DEBUG
		printf("DEBUGGING\n");
	#endif
	
	printf("Hello world!\n");

	return 0;
}
