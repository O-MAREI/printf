#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>


/**
 * print_int - Prints integer, returns character count.
 * @num: The integer.
 * Return: Character count.
 */
int print_int(int num)
{
	char digits[100];
	int i = 0, count;

	while (num > 0)
	{
		digits[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}

	count = i;

	for (i = i - 1; i >= 0; i--)
	{
		write(1, &digits[i], 1);
	}

	return (count);
}

/**
 * print_binary - Converts unsigned int to binary and prints it.
 * Returns character count.
 *
 * @n: The integer.
 * Return: Character count.
 */
int print_binary(unsigned int n)
{
	char a[100];
	int i, count;

	for (i = 0; n > 0; i++)
	{
		a[i] = n % 2 + '0';
		n = n / 2;
	}

	count = i;

	for (i = i - 1; i >= 0; i--)
	{
		write(1, &a[i], 2);
	}

	return (count);
}

/**
 * print_unsigned - Prints unsigned int, returns character count.
 * @num: The unsigned integer.
 * Return: Character count.
 */
int print_unsigned(unsigned int num)
{
	char digits[100];
	int i = 0, count;

	while (num > 0)
	{
		digits[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}

	count = i;

	for (i = i - 1; i >= 0; i--)
	{
		write(1, &digits[i], 1);
	}

	return (count);
}

/**
 * print_octal - Converts int to octal and prints it.
 * @num: The integer.
 * Return: Character count.
 */
int print_octal(unsigned int num)
{
	int octal = 0, i = 1, count = 0, charcount;
	char digits[1000];

	while (num != 0)
	{
		octal += (num % 8) * i;
		num /= 8;
		i *= 10;
	}

	while (octal > 0)
	{
		digits[count] = (octal % 10) + '0';
		octal = octal / 10;
		count++;
	}

	charcount = count;

	for (count = count - 1; count >= 0; count--)
	{
		write(1, &digits[count], 1);
	}

	return (charcount);
}

/**
 * print_hex - Converts int to hexadecimal and prints it.
 * @num: The integer.
 * Return: Character count.
 */
int print_hex(unsigned int num)
{
	char hexnum[100];
	int remainder, i, j = 0;

	while (num != 0)
	{
		remainder = num % 16;

		if (remainder < 10)
			hexnum[j++] = 48 + remainder;
		else
			hexnum[j++] = 55 + remainder;

		num = num / 16;
	}

	for (i = j; i >= 0; i--)
		write(1, &hexnum[i], 1);

	return (j);
}
