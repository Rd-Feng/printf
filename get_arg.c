#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_arg - put the variadic parameter into a buffer as string
 * type: type of parameter
 *
 * Return: pointer to to the resulting buffer string
 */
char *get_arg(char type, ...)
{
	va_list params;

	va_start(params, type);
	switch(type)
	{
	case 'c':
		return (get_char(va_arg(params, int)));
	case 's':
		return (get_string(va_arg(params, char*)));
	case 'd':
	case 'i':
		/* 0x05 100-print_number */
		return (get_number(va_arg(params, int)));
	default:
		return (NULL);/* Error */
	}
}
