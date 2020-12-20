//	Reads a string from stdin and if it ends in blank
//	spaces it erase them and moves the '\n', '\0' chars
//	it performs a "right trim"


#include <stdio.h>

#define MAX_LEN 100


int main ( void ) {

	int i, j, k;
	char str[MAX_LEN];

	if(fgets(str, MAX_LEN, stdin) == NULL)
		return 1;

	for(i = 0; str[i] != '\0'; i++) 
		if(str[i + 1] == '\n') 
			for(j = 0; str[i - j] == ' '; j++)
				;
			
	str[(i - j) - 1] = str[i - 1];
	str[(i - j)] = '\0';

	return 0;
}
