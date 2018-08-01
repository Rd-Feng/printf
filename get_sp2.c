#include "holberton.h"
#include <stdlib.h>

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 */
void rev_string(char *s)
{
	int head, tail;
	int len;
	char tmp;

	for (len = 0; s[len] != '\0'; len++)
		;
	head = 0;
	tail = len - 1;
	while (head < tail)
	{
		tmp = *(s + head);
		*(s + head) = *(s + tail);
		*(s + tail) = tmp;
		head++;
		tail--;
	}
}

/**
 * get_rev - reverse a string
 * @s: string
 * Return: string reversed
 */
char *get_rev(char *s)
{
	char *ptr = NULL;

	ptr = get_string(s);
	rev_string(ptr);
	return (ptr);
}

