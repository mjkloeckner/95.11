/*	Makes a lexicographical comparison between two strings	*/
/*	similar to strcmp() function from <string.h>		*/

#include <stdio.h>

/*	This function calculates the length of given string
	and returns the lenghth by its name as a size_t		*/
size_t str_len(const char *str) 
{
	if(str == NULL)
		return 1;

	size_t i;
	while(str[i++])
		;

	return i;
}

/*	This function is equivalent to strcmp() function from	
	<string.h> library					*/
int str_cmp(const char *str1, const char *str2) 
{ 
	/* In case one of the given strings is NULL returns 1; */ 
	if(str1 == NULL || str2 == NULL)
		return 1;


	char aux1, aux2;
	int i, j, cmp, str1_len, str2_len;
	str1_len = str_len(str1);
	str2_len = str_len(str2);

	/* Assigns the length of the longer string to j; */
	j = (str1_len > str2_len) ? str1_len : str2_len; 

	/* The for loop itinirate until the longest str ENDs */
	for(i = 0, cmp = 0; i < j; i++) {

		aux1 = str1[i];
		aux2 = str2[i];

		/* This statement assigns to cmp the difference between */
		/* the two coresponding chars of str1 and str2 */
		if(aux1 < aux2) {
			cmp -= (aux2 - aux1);
		} else if (aux1 > aux2) {
				cmp += (aux1 - aux2);
			}

	}
	return cmp;
}

	
int main(void) {

	char s1[] = "AB";
	char s2[] = "ABC";

	int i, j;
	i = str_cmp(s1, s2);

	printf("%d\n", i);
	
	return 0;
}
