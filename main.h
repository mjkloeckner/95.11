#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

#ifndef MAIN_H
#define MAIN_H

typedef enum {
	OK,
	ERROR_INVOCATING_PROGRAM,
	ERROR_NULL_POINTER,
	NOT_FOUND
} status_t;

#endif
