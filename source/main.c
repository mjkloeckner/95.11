#include "../include/cla.h"
#include "../include/errors.h"

typedef struct {
	int id, credit, debt;
} user_t, *user;

typedef struct {
	char *fmt, *fi, fo;
	unsigned long ti, tf;
} cla_t, *cla;

/* user_create */
/* user_destroy */
/* user_assign_amount */
/* user_get_amount */

int main (int argc, char *argv[])
{
	status_t st;

	if((st = validate_arguments(argc, argv)) != OK) {
		show_status(st);
		return st;
	}

	/* parse_arguments(argc, argv); */

	/* get_argument(argc, argv); */
	/* if((st = parse_file())) { */
	/* 	show_error(st); */
	/* 	return st; */
	/* } */

	return OK;
}
