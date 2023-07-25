#include "main.h"
#include <unistd.h>

/**
 * get_size - Gets number of chars in a string.
 * @str: The string.
 * Return: The number of chars.
 */
int get_size(char str[])
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * count_num - Counts digits in an int.
 * @n: The integer.
 * Return: The number of digits.
 */
int count_num(int n)
{
	int count = 0;

	while (n != 0)
	{
		n /= 10;
		count++;
	}

	return (count);
}
