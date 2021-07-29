#ifndef IO__H
#define IO__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cla.h"
#include "user.h"
#include "status.h"

#define _XOPEN_SOURCE
#define __USE_XOPEN
#include <time.h>

#define INIT_SIZE		1000
#define INPUT_FILE_FIELDS 6

#define BUFFER_SIZE		1000
#define GROWTH_FACTOR 	2

#define INPUT_FILE_DELIM ","
#define CSV_OUTPUT_DELIM	","

#define XML_HEADER		"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
#define XML_ROOT_OPEN	"<root>"
#define XML_ROOT_CLOSE	"</root>"

#define XML_ROW_OPEN	"<row>"
#define XML_ROW_CLOSE	"</row>"

#define XML_ID_OPEN		"<user>"
#define XML_ID_CLOSE	"</user>"

#define XML_CREDIT_OPEN		"<credits>"
#define XML_CREDIT_CLOSE	"</credits>"

#define XML_DEBT_OPEN	"<debits>"
#define XML_DEBT_CLOSE	"</debits>"

/* typedef enum { */
/* 	POS_ID_TXN, */
/* 	POS_USER_ID, */
/* 	POS_TXN_DATE, */
/* 	POS_AMOUNT, */
/* 	POS_CARD_NUMBER, */
/* 	POS_DESC */
/* } csv_pos_t; */

status_t string_split(char *s, char **data, char *delim);

status_t load_values(FILE *, cla_t *data);

void clean_data(char **data);

/*
status_t export_data_as_csv(FILE *fo, const user_t *users, size_t size);
status_t export_data_as_xml(FILE *fo, const user_t *users, size_t size);
*/

status_t destroy_data(char **, size_t);
status_t get_date(time_t *e, char **data);

void clean_buffer(char *buf);

#endif
