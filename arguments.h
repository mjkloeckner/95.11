#include "main.h"
#include "macros.h"

#ifndef ARGUMENTS_H
#define ARGUMENTS_H

void print_error(status_t error);

status_t validate_arguments(int argc, char * argv[], char * src, char * dest);

#endif
