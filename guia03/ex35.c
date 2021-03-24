#include <stdio.h>
#include <math.h>

#define PI 3.1415922654

int main (void)
{
	size_t i, samples, interval;
	double amp, frequency, time, phi;

	amp = 100;
	frequency = 20;
	time = 0;
	phi = 0.1;

	samples = 10;
	interval = 1;

	double data[samples];

	for(i = 0; i < samples; i++, time += interval) {
		data[i] = (amp * sin((2 * PI * frequency * time) + phi));
//		printf("data: %ld\n", data[i]);
		printf("sin: %ld\n", sin((2 * PI * frequency * time) + phi));
	}

	return 0;
}
