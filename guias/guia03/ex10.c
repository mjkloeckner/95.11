#include <stdio.h>
#include <string.h>



int main(void) {

	char src[] = "Hello world!\n";
	size_t i, n;

	n = 12;
	char cpy[n];

	for(i = 0; i <= n; i++) {
		cpy[i] = src[i];
	}

	printf("%s", src);
	printf("%s", cpy);


	return 0;
}
