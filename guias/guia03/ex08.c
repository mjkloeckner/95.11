#include <stdio.h>
#include <string.h>

size_t str_len(const char *str) {
	if(str == NULL) return 1;

	size_t i = 0;
	while(str[i++]); 

	return i;
}

int main(void) {

	char s1[] = "ABC";
	char s2[] = "ABC";

	size_t s1_len, s2_len;
	int i, j, cmp;

	s1_len = str_len(s1);
	s2_len = str_len(s2);
	
	j = (s1_len > s2_len) ? s1_len : s2_len;

	for(i = 0, cmp = 0; i < j; i++) {
		if(s1[i] < s2[i]) {
			cmp -= (s2[i] - s1[i]);
		} else 
			if (s1[i] > s2[i]) {
				cmp += (s1[i] - s2[i]);
			}
	}	

	printf("%d\n", cmp);
	return 0;
}
