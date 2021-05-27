/*	G04E06 - Print elements of a 2D array using a pointer
 *	by Martin J. Kloeckner	
 *	github.com/klewer-martin	*/

#include <stdio.h>

int main (void)
{
	int *dos_ptr; 
	int (*ptr2vector)[4]; 

	int dos_vector[3][4] = {{ 1, 2, 3, 4 }, 
                            { 5, 6, 7, 8 },
                            { 9,10,11,12 }}; 

	dos_ptr = dos_vector[0];
	for(size_t i = 0; i < 3 * 4; i++)
		printf("dos_vector[%ld][%ld]: %2d\n", i / 4, i % 4, *(dos_ptr + i));

	putchar(10);
	ptr2vector = dos_vector;
	for(size_t i = 0; i < 3; i++) {
		for(size_t j = 0; j < 4; j++)
			printf("%2d ", *(ptr2vector[i] + j));
		
		putchar(10);
	}

	return 0;
}
