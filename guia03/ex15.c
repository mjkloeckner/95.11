#include <stdio.h>

#define MAX_LEN 100

int main(void) {

	int i, j;
	char str[MAX_LEN];

	fgets(str, MAX_LEN, stdin);

	j = 0;
	while(str[j] == ' ')
		j++;

	for(i = 0; str[i] != '\0'; i++) {
		str[i] = str[i + j];
	}
	puts(str);
	return 0;
}
