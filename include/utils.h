#ifndef UTILS__H
#define UTILS__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "cla.h"
#include "user.h"
#include "status.h"
#include "vector.h"

#define _XOPEN_SOURCE
#define __USE_XOPEN
#include <time.h>

#define IN_FILE_MAX_LEN	100
#define IN_FILE_DELIM	","
#define IN_FILE_FIELDS	6
#define IN_FILE_FIELDS_MAX_LEN	50

#define STR_FMT_CSV "csv"
#define STR_FMT_XML "xml"

#define CARD_NO_VALID_LEN 16

#define XML_STR_HEADER	"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
#define XML_STR_ROOT	"root"
#define XML_STR_ROW		"row"
#define XML_STR_ID		"user"
#define XML_STR_CREDIT	"credits"
#define XML_STR_DEBIT	"debits"

status_t get_date(time_t *, char *);

status_t array_destroy(char **, size_t);

status_t string_split(char *, char **, char *);
status_t load_users_to_vector(ADT_Vector_t **, ADT_cla_t *);

bool is_valid_card(char *);

void clean_array(char **);
void clean_buffer(char *);

#endif
