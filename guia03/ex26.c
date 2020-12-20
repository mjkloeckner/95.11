#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
#define ERR_MAX_STR_LEN "Err: the entered number is too big"


int main ( void ) {

    char buffer[MAX_LEN], str1[MAX_LEN], str2[MAX_LEN];
	char dest[MAX_LEN];
    int i, j, num;

    if(fgets(str1, MAX_LEN, stdin) == NULL) {
        return 1;
	}

//  This part counts the length of the first string
//	and replaces the new line character for a blank space;
    for(i = 0; str1[i] != '\0'; i++)
		if(str1[i] == '\n')
			str1[i] = ' ';
			str1[i + 1] = '\0';

    if(fgets(str2, MAX_LEN, stdin) == NULL) {
        return 1;
	}

    if(fgets(buffer, MAX_LEN, stdin) == NULL) {
       return 1;
	}

    num = atoi(buffer);

//  This part checks if the input number is bigger than
//  the length of the first string;
    if(num > i) {
		fprintf(stderr, ERR_MAX_STR_LEN"\n");
        return 1;
	}


//	Removes the new line chracter from string two;
	for(i = 0; str2[i] != '\0'; i++)
		if(str2[i] == '\n')
			str2[i] = '\0';

    for(i = 0, j = 0; str2[j] != '\0'; i++) {
        if((i <= num) && (str1[i] != '\0')) {
            dest[i] = str1[i];
		} else { 
            dest[i] = str2[j];
            j++;
		}
	}
	printf("%s\n", dest);
    return 0;
}
