#include <stdio.h>
#include <time.h>
#include <string.h>

const char default_format[] = "%B %d %Y";

typedef enum {
	OK,
	ERROR_NULL_POINTER
} status_t;

status_t date_translator(time_t unix_time, char *res, size_t size) 
{
	const char *format = default_format;
	struct tm *tmp = gmtime(&unix_time);

	if (strftime(res, size, format, tmp) == 0) {
		(void) fprintf(stderr,  "strftime(3): cannot format supplied "
								"date/time into buffer of size %u "
								"using: '%s'\n",
								(unsigned int)sizeof(res), format);
		return 1;
	}
	return 0;
}

int main (void) 
{
	char res[32];

	time_t t;

	t = 1577880000;

	date_translator(t, res, sizeof(res));
	puts(res);
	return 0;
}
