#include <stdio.h>
#include <math.h>

typedef struct {
	float x, y;
} r2Point_T;

float dist(r2Point_T a,r2Point_T b)
{
	return sqrt(powf((b.x - a.x), 2) + powf((b.y - a.y), 2));
}

int main (void)
{
	r2Point_T a, b;

	a.x = 2;
	a.y = 3;

	b.x = 3;
	b.y = 6;

	printf("The distance between A = (%.1f, %.1f) & B = (%.1f, %.1f) is:\n%.2f\n" \
			, a.x, a.y, b.x, b.y, dist(a, b));
	return 0;
}
