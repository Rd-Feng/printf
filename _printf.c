#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"
#include "errorcode.h"

/**
 * _printf - output text to standard output specified by format
 * @format: directives for outputing text
 *
 * Return: number of characters output
 */
int _printf(const char *format, ...)
{
	int low, high, sum = 0;
	char *buffer = NULL, *arg = NULL, *ptr = NULL;
	va_list params;
	if (!format)
	{
		exit(NULL_PTR);
	}
	low = 0;
	high = 0;
	sum = 0;
	va_start(params, format);
	/* initialize buffer as an empty string */
	buffer = malloc(sizeof(char));
	*buffer = '\0';
	while (1)
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
			default:/* unknown specifier */
				va_end(params);
				die_with_error(buffer, arg,
					       WRONG_SPECIFIER);
			}
			if (!arg)
			{
				va_end(params);
				die_with_error(buffer, arg, NULL_PTR);
			}
			ptr = (char *) format;
			update_buffer(&buffer, ptr  + low, high, low, arg);
			ptr = NULL;
			if (!buffer)
			{
				va_end(params);
				die_with_error(buffer, arg, NULL_PTR);
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
			ptr = (char*) format;
			update_buffer(&buffer, ptr + low, high, low, NULL);
			if (!buffer)
			{
				va_end(params);
				die_with_error(buffer, arg, NULL_PTR);
			}
			sum = print_buffer(buffer);
			free(buffer);
			va_end(params);
			break;
		}
	}
	return (sum);
}
