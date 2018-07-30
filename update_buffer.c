#include "holberton.h"
/**
 * update_buffer - update the output buffer
 * concatenate format string and arg string to the output buffer
 * new memory will be allocated to the buffer, and old memory will be free
 * @buffer: address to the buffer pointer
 * @high: index of buffer string
 * @low: index of buffer string
 * @arg: arg string
 */
void update_buffer(char **buffer, char *format, int high, int low, char *arg)
{
	unsigned int len = 0;
	char *tmp = *buffer;

	len = high - low - 1;
	*buffer = string_nconcat(*buffer, *format, len);
	free(tmp);
	if (arg)
	{
		tmp = *buffer;
		*buffer = string_nconcat(*buffer, arg, _strlen(arg));
		free(tmp);
	}
}
