#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define ERR_EMPTY_MSG "no chars have been readed"

int main(void) {
	
	char s[MAX_LEN];
	if(fgets(s, MAX_LEN, stdin) == NULL) {
		fprintf(stderr, ERR_EMPTY_MSG"\n");
		return 1;
	} else if(strcmp(s, "") == 0) {
		fprintf(stderr, ERR_EMPTY_MSG"\n");
		return 1;
	}
	printf("%s", s);
	return 0;
}
