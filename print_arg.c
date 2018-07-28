#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_arg - print the variadic parameter as specified type
 * type: type
 *
 * Return: pointer to a string to replace the conversion specifier
 */
char *print_arg(char type, ...)
{
	va_list params;

	va_start(params, type);
	switch(type)
	{
	case 'c':
		return (_putchar(va_arg(params, int)));
	case 's':
		return (_puts(va_arg(params, char*)));
	case 'd':
	case 'i':
		/* 0x05 100-print_number */
		return (print_number(va_arg(params, int)));
	default:
		return (NULL);/* Error */
	}
}
