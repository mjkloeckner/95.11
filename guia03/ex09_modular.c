/*  Makes a lexicographical comparison between the first n	*/
/*	numbers of two given strings							*/
/*	similar to strncmp() function from <string.h>			*/

#include <stdio.h>

/*	This function calculates the length of given string
    and returns it by its name, equivalent to strlen()		
	function from <string.h> library						*/
size_t str_len(const char *str)
{
	if(str == NULL)
		return 1;

	size_t i;
	for(i = 0; str[i] != '\0'; i++) 
		;

	return i;
}

/*  This function is equivalent to strncmp() function from   
    <string.h> library                                      */
int str_cmp(const char *str1, const char *str2, size_t n)
{ 
	if(str1 == NULL || str2 == NULL)
		return 1;

	char aux1, aux2;
	int i, j, cmp, str1_len, str2_len;
	str1_len = str_len(str1);
	str2_len = str_len(str2);
	
	if(n > str1_len || n > str2_len)
		return 1;

	for(i = 0, cmp = 0; i <= n; i++) {
		aux1 = str1[i];
		aux2 = str2[i];
		if(aux1 < aux2) {
			cmp -= (aux2 - aux1);
		} else if (aux1 > aux2) {
				cmp += (aux1 - aux2);
			}
	}
	return cmp;
}

	
int main(void) {

	char s1[] = "AB ";
	char s2[] = "ABC";

	int i;
	i = str_cmp(s1, s2, 4);

	printf("%d\n", i);
	return 0;
}
