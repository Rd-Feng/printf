#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"

void die_with_error(char *buffer, char *arg);

int print_buffer(char *buffer);

/**
 * _printf - output text to standard output specified by format
 * @format: directives for outputing text
 *
 * Return: number of characters output
 */
int _printf(const char *format, ...)
{
	int low, high, sum = -1;
	char *buffer = NULL, *arg = NULL, *ptr = NULL;
	va_list params;

	low = 0;
	high = 0;
	va_start(params, format);
	/* initialize buffer as an empty string */
	buffer = malloc(sizeof(char));
	*buffer = '\0';
	while (format)
	{
		if (format[high] == '%')
		{
			high++;
			switch (format[high])
			{
			case 'c':
				arg = get_arg('c', va_arg(params, int));
				break;
			case 's':
				arg = get_arg('s', va_arg(params, char*));
				break;
			case 'd':
			case 'i':
				arg = get_arg('d', va_arg(params, int));
				break;
			case '%':
				arg = malloc(2);
				arg[0] = '%';
				arg[1] = '\0';
				break;
			default:/* unknown specifier */
				va_end(params);
				die_with_error(buffer, arg);
				return (-1);
			}
			if (!arg)
			{
				va_end(params);
				die_with_error(buffer, arg);
				return (-1);
			}
			ptr = (char *) format;
			update_buffer(&buffer, ptr  + low, high, low, arg);
			ptr = NULL;
			if (!buffer)
			{
				va_end(params);
				die_with_error(buffer, arg);
				return (-1);
			}
			free(arg);
			arg = NULL;
			high++;
			low = high;
		}
		else if (format[high] != '\0')
		{
			high++;
		}
		else
		{
			ptr = (char *) format;
			update_buffer(&buffer, ptr + low, high, low, NULL);
			if (!buffer)
			{
				va_end(params);
				die_with_error(buffer, arg);
				return (-1);
			}
			sum = print_buffer(buffer);
			free(buffer);
			va_end(params);
			break;
		}
	}
	return (sum);
}

/**
 * die_with_error - free memory and exit process with exit code e
 * @buffer: output buffer to be free
 * @arg: argument buffer to be free
 * @e: error code to exit process
 */
void die_with_error(char *buffer, char *arg)
{
	free(buffer);
	free(arg);
}
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
