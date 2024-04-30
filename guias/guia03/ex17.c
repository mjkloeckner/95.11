/*	Makes a case sensitive search of the s2 in s1	*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int
main (void)
{
	char s1[MAX_LEN];
	char s2[MAX_LEN];

	/* Get two strings from stdin */
	if(!fgets(s1, MAX_LEN, stdin)) return 1;
	if(!fgets(s2, MAX_LEN, stdin)) return 1;

	if(strlen(s2) > strlen(s1)) return 1;

	for(size_t i = 0; s1[i]; i++)
		if(s1[i] == s2[0])
			for(size_t j = 0; s2[j]; j++)
				if(s1[i] == s2[j])
					putchar(s1[i++]);
				
	return 0;
}


