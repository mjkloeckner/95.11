#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int main ( void ) {

	char buffer[MAX_LEN];
	int num;
	char num2[MAX_LEN];

	if(fgets(buffer, MAX_LEN, stdin) == NULL)
		return 1;

	num = atoi(buffer);
	sprintf(num2, "%d\n", num);

	printf("%s", num2);
	return 0;
}
