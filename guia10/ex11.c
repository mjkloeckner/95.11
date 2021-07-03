#include <stdio.h>

int dot_product(int *v1, int *v2, size_t l);

void test(int *v1);

int main (void)
{
	int v1[4] = { 1,2,3,4 };
	int v2[4] = { 1,2,3,4 };
	printf("%d\n", dot_product(v1,v2,4));

	test(v1);

	printf("v1 elements: %ld\n", sizeof(v1) / sizeof(int));
	return 0;
}

/* int dot_m(int *v1, int *v2, size_t index) */
/* { */
/* 	if(index == 0) return v1[0] * v2[0]; */
/* 	return v1[index] * v2[index] + dot_product(v1, v2, index - 1); */
/* } */

void test(int *v1)
{
	printf("%ld\n", sizeof(*v1));
}

int dot_product(int *v1, int *v2, size_t l)
{
	return l ? v1[l-1] * v2[l-1] + dot_product(v1, v2, l-1) : 0;
}
