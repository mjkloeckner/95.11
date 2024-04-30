#ifndef LOAD__H
#define LOAD__H

#include "../include/cla.h"
#include "../include/user.h"
#include "../include/utils.h"
#include "../include/vector.h"
#include "../include/status.h"

#define STR_MSG_END_PROCSS_EN	"End processing input file"

#define STR_MSG_END_PROCSS_ES		"Se termino el procesamiento del archivo"
#define STR_MSG_LINES_PROCSSD_ES	"Lineas procesadas:"
#define STR_MSG_USRS_REGISTERD_ES		"Usuarios registrados:"


status_t load_users_to_vector(ADT_Vector_t **, cla_t);

#endif
