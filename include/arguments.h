#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARGUMENTS_H
#define ARGUMENTS_H

void print_error(status_t error);

status_t validate_arguments(int argc, char * argv[]);

status_t set_files_name(int argc, char * argv[], char * src, char * dest);

#endif
