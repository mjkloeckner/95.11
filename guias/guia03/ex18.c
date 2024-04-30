/*	Reads a string of chars from stdin and check if it's
	a palindrome.	*/

#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

int
main (void)
{
	char str[MAX_LEN];
	int len, i, j;

	if(!fgets(str, MAX_LEN, stdin))
		return 1;

	/* Converts all the string to lowercase; */
	for(i = 0; str[i] != '\0'; i++)
		if(isupper(str[i]))
			str[i] = tolower(str[i]);

	/*	Erases all the blank spaces between words	*/
	for(i = 0; str[i]; i++)
		if(str[i] == ' ')
			for(size_t j = i; str[j]; j++)
				str[j] = str[j + 1];

	/* Counts the length of the string; */
	for(i = 0; str[i] != '\n'; i++)
		;

	/* Stored the lengh of the string for later, */ 
	/* and subtract one from i because of the last char; */
	len = i;
	i = (i - 1);

	/* This part compares one by one the chars from the */ 
	/* string, first with last, second with before last, */
	/* and so on, only comparing the next one if the previous */
	/* one was equal; */
	for(j = 0; (str[j] == str[i]) && str[j]; j++, i--)
		;

	/* If the string or sentence its palindrome, then in the previous */
	/* block j would end with the value of the lengh, stored previously; */
	if(j == len)
		printf("%s\n", "La cadena es capicua.");

	return 0;
}
