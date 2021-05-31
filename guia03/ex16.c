/* Reads a string from stdin and if it ends in blank
 * spaces it erase them and move the '\0' char
 * it performs a "right trim"
*/

#include <stdio.h>

#define MAX_LEN 100

int
main (void)
{
	int i, j, k;
	char str[MAX_LEN];

	if(!fgets(str, MAX_LEN, stdin))
		return 1;

	/* Goes to end of string, then starts counting trailing spaces */
	for(i = 0; str[i]; i++) 
		if(str[i + 1] == '\n') 
			for(j = 0; str[i - j] == 32; j++)
				;
	
	/* Places the '\0' character j times 'til end of string	*/
	str[i - j] = '\0';

	printf("%s", str);
	return 0;
}
