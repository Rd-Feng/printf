#include <stdlib.h>

/**
 * die_with_error - free memory and exit process with exit code e
 * @buffer: output buffer to be free
 * @arg: argument buffer to be free
 * @e: error code to exit process
 */
void die_with_error(char *buffer, char *arg, int e)
{
	free(buffer);
	free(arg);
	exit(e);
}
