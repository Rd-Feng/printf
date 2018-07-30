#include <stdio.h>
#include <stdlib.h>
/**
 * get_char - returns a copied char
 * @c: char to be copied
 * Return: ptr of copied char
 */
char *get_char(char c)
{
	char *ptr;

	ptr = malloc(2);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ptr[0] = c;
	ptr[1] = '\0';
	return (ptr);
}

/**
 * get_string - returns a new duplicated string
 * @s: string to be copied
 * Return: Null if string is null, else pointer of copied string
 */
char *get_string(char *s)
{
	char *ptr;
	int i, j;

	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		;
	}
	ptr = (char *)malloc(i * sizeof(char) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		ptr[j] = s[j];
	}
	ptr[j] = '\0';
	return (ptr);
}

/**
 * get_number - put integer into a memory block as string
 * @n: integer
 *
 * Return: pointer to integer string, NULL on error
 */
char *get_number(int n)
{
	int i, len = 0, tmp;
	char *buf = NULL;
	/* find number bytes to allocate */
	tmp = n;
	while (tmp >= 10 || tmp <= -10)
	{
		tmp /= 10;
		len++;
	}
	len++;
	if (n < 0)
		len++;
	buf = malloc(sizeof(char) * (len + 1));
	if (buf)
	{
		buf[len] = '\0';
		if (n < 0)
		{
			buf[0] = '-';
		}
		i = len - 1;
		while (n >= 10 || n <= -10)
		{
			tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
			buf[i] = tmp + '0';
			i--;
			n /= 10;
		}
		tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
		buf[i] = tmp + '0';
	}
	return (buf);
}
