#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int alpha, nonalpha, num;
	int c;
	
	alpha = nonalpha = num = 0;

	while((c = getchar()) != EOF ) {
		if(isalpha(c))
			alpha++;
		else if(isdigit(c))
			num++;
		else if(!isalnum(c))
			nonalpha++;
	}
	printf(
		"Alphanumerics: %d\n"
		"NonAlphanumerics: %d\n"
		"Digits: %d\n",
		alpha, nonalpha, num
	);

	return 0;
}
