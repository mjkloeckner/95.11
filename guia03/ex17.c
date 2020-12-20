#include <stdio.h>
#include <string.h>

#define MAX_LEN 100


int main ( void ) {

	int i, j;
	
	char s1[MAX_LEN];
	char s2[MAX_LEN];
	
	if(fgets(s1, MAX_LEN, stdin) == NULL)
		return 1;

	if(fgets(s2, MAX_LEN, stdin) == NULL)
		return 1;

	if(strlen(s2) > strlen(s1))
		return 1;

	for(i = 0; s1[i] != '\0'; i++)
		if(s1[i] == s2[0])
			for(j = 0; (s2[j] != '\0'); j++)
				if(s1[i] == s2[j]) {
					putchar(s1[i]);
					i++;
				}
	putchar('\n');
	return 0;
}


