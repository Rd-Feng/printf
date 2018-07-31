#include <stdlib.h>
#include <stdio.h>
char *move_left(char *a, int size, int num);

char *get_binary(unsigned int n)
{
	char *ptr = NULL;
	unsigned int i, num = 0, size = 0;

	if (n == 0)
	{
			ptr = malloc(2);
			if (ptr)
			{
				ptr[0] = '0';
				ptr[1] = '\0';
			}
			return (ptr);
	}
	size = sizeof(int) * 8 + 1;
	ptr = malloc(size);
	if (ptr)
	{
		for (i = 0; i < size; i++)
		{
			ptr[i] = '0';
		}
		ptr[size - 1] = '\0';

		i = size - 2;
		while (n != 0)
		{
			ptr[i] = n % 2 == 0 ? '0' : '1';
			num++;
			n = n / 2;
			i--;
		}
		num++;
		ptr = move_left(ptr, size, num);
	}
	return (ptr);
}


char *move_left(char *a, int size, int num)
{
	int i;
	char *ptr;

	for (i = 0, ptr = (a + size - num); i < num; i++, ptr++)
		*(a + i) = *ptr;
	*(a + num) = '\0';
	return (a);
}

int main(void)
{
	unsigned int i = 0;
	printf("%i is: %s\n", i, get_binary(i));
	return (0);
}