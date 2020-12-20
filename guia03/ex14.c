#include <stdio.h>


typedef enum {
	OK, ERROR
} status_t; 


size_t rechar(char *str, char old, char new);


int main( void ) {

	char str[] = "Hello world!";

	rechar(str, 'o', 'e');

	printf("%s\n", str);
	return OK;
}



size_t rechar(char *str, char old, char new) {
	if(str == NULL)
		return ERROR;

	int i;
	for(i = 0; str[i] != '\0'; i++) {
		if(str[i] == old) {
			str[i] = new;
		}
	}
	return OK;
}
