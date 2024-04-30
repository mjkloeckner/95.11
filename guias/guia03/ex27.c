#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int main ( void ) {

	char str[MAX_LEN], buffer[MAX_LEN];
	int i, j, num;

	if(fgets(str, MAX_LEN, stdin) == NULL)
		return 1;

	if(fgets(buffer, MAX_LEN, stdin) == NULL)
		return 1;

	num = atoi(buffer);

	for(i = 0; str[i] != '\0'; i++)
		if(str[i] == '\n')
			i++;
			for(j = 0; j <= num; j++)
				str[i + j] = ' ';

	printf("%s\n", str);
	return 0;
}
