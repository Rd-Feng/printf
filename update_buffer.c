#include "holberton.h"
#include <stdlib.h>
/**
 * update_buffer - update the output buffer
 * concatenate format string and arg string to the output buffer
 * new memory will be allocated to the buffer, and old memory will be free
 * @buffer: address to the buffer pointer
 * @format: current position of the format string from printf
 * @high: index of buffer string
 * @low: index of buffer string
 * @arg: arg string
 */
void update_buffer(char **buffer, char *format, int high, int low, char *arg)
{
	unsigned int len = 0;
	char *tmp = NULL;

	if (!arg)
	{
		tmp = *buffer;
		len += 1; /* null statement to avoid unused variable warning */
		*buffer = str_concat(*buffer, format);
		free(tmp);
	}
	else
	{
		len = high - low - 1;
		tmp = string_nconcat(*buffer, format, len);
		free(*buffer);
		*buffer = tmp;
		tmp = str_concat(*buffer, arg);
		free(*buffer);
		*buffer = tmp;
		return;
	}
}
