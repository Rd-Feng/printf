char *_putchar(char c)
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
