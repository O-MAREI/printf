#include "main.h"
#include <unistd.h>

int get_size(char str[])
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	return (i);
}

int count_num (int n)
{
	int count = 0;

	while (n != 0)
	{
		n /= 10;
		count++;
	}

	return (count);
}
