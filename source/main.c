#include "cla.h"

int main (int argc, char *argv[])
{
	status_t st;

	if((st = validate_arguments(argc, argv)) != OK) return st;

	return 0;
}
