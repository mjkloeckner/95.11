#include <stdio.h>
#include <string.h>


int main(void)
{
	int i, s1_len, s2_len, cat_len;

	char s1[] = "Hello world!";
	char s2[] = "Hola mundo!";

	s1_len = strlen(s1);
	s2_len = strlen(s2);

	cat_len = ((s1_len + s2_len) + 1); //	One more for the '\0' byte;
	char cat[cat_len];

	for(i = 0; i <= cat_len; i++) {
		if (i < s1_len) {
			cat[i] = s1[i];
		} else if (i >= s1_len) {
			cat[i] = s2[i - s1_len];
		} else if (i == cat_len) {
			cat[i + 1] = '\0';
		}
	}
	printf("%s\n", cat);
	return 0;
}
