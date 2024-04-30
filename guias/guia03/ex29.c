#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 20

int main (void) {

	int i, suma, vector[MAX_LEN], vector_end;
	char buffer[MAX_LEN];

	vector_end = MAX_LEN;
	for(i = 0, suma = 0; i < vector_end; i++) {
		if(fgets(buffer, sizeof(int) + 1, stdin) != NULL) {
			vector[i] = atoi(buffer);
			suma += vector[i];
		} else {
			vector_end = i;
			i = MAX_LEN;
		}
	}
	printf("%d\n", suma);
	return 0;
}
