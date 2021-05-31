#include <stdio.h>

#define MAX_LEN 100

int main(void) {

	int i, j;
	char str[MAX_LEN];

	fgets(str, MAX_LEN, stdin);

	/* Count consecutive starting blank spaces */
	for(i = 0; str[i] == 32; i++)
		;

	/* Shift the string i times to the left */
	for(j = 0; str[j]; j++)
		str[j] = str[j + i];

	printf("%s", str);
	return 0;
}
