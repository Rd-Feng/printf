#include <stdlib.h>

char *get_string(char *s)
{
    char *ptr;
	int i, j;
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
