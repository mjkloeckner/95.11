/*  Makes a lexicographical comparison between the first n	*/
/*	numbers of two given strings							*/
/*	similar to strncmp() function from <string.h>			*/

#include <stdio.h>
#include <string.h>

/*	This function calculates the length of given string
    and returns it by its name, equivalent to strlen()		
	function from <string.h> library						*/
size_t str_len(const char *str)
{
	size_t i;

	if(!str) return 1;

	for(i = 0; str[i]; i++);

	return i;
}

/*  This function is equivalent to strncmp() function from   
    <string.h> library                                      */
int str_cmp(const char *sa, const char *sb, size_t n)
{ 
	/*	Since the return value is an integer this function won't check for errors	*/
	int cmp;
	size_t i;

	for(i = cmp = 0; (i < n) && sa[i] && sb[i]; i++)
		cmp += sa[i] - sb[i];

	return cmp;
}

	
int main(void) {

	char s1[] = "HELLO";
	char s2[] = "hello";

	int i, j;
	i = str_cmp(s1, s2, 109);
	j = strncmp(s1, s2, 8);

	printf("%d\n%d\n", i, j);
	return 0;
}
