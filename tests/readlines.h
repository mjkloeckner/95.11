#ifndef READLINES
#define READLINES

#define INPUT_FILE_NAME "input.csv"
#define INITIAL_SIZE 1000
#define TIME_MAX_DIGITS 1000

#define ARG "Argentina"
#define COL "Colombia"
#define GER "Germany"

typedef enum {
	OK,
	ERROR_PRINTING,
	ERROR_READING_FILE,
	ERROR_NULL_POINTER,
	ERROR_ALLOCATING_TIME
} status_t;

typedef enum {
	PAIS,
	DATE,
	INFECTED
} data_t;

#endif
