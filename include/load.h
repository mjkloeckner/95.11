#ifndef LOAD__H
#define LOAD__H

#include "../include/cla.h"
#include "../include/user.h"
#include "../include/utils.h"
#include "../include/vector.h"
#include "../include/status.h"

#define STR_MSG_END_PROCSS	"End processing input file\nLines processed: "

status_t load_users_to_vector(ADT_Vector_t **, ADT_cla_t *);

#endif
