#include <stdio.h>

#define MAX_LEN 100


int main(void) {

	char s[MAX_LEN];

	printf("> ");
	scanf("%s", s);
	puts(s);

	printf("> ");
	/* gets(s); removed from std C11 because it's very unsecure */
	fgets(s, MAX_LEN, stdin);
	puts(s);

	return 0;
}
