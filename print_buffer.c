#include <stdlib.h>
/**
 * print_buffer - print out the buffer
 * @buffer: buffer string
 *
 * Return: total number of characters printed
 */
int print_buffer(char *buffer)
{
	int num = 0;

	num = write(1, buffer, _strlen(buffer));

	return (num);
}
