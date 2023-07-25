#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int get_size(char str[]);
int count_num (int n);
void print_binary (unsigned int n);
void print_int (int num);
void print_unsigned (unsigned int num);
void print_octal (unsigned int num);
void print_hex (unsigned int num);

int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;
	char ch, converter;
	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		ch = format[i];

		if (ch != '%')
		{
			write (1, &ch, 1);
			count++;
		}
		else
		{
			converter = format[i + 1];
			i++;

			if (converter == 'c')
			{
				char value = va_arg(args, int);
				write (1, &value, 1);
			}
			else if (converter == 's')
			{
				char *value;
				value = va_arg(args, char *);
				write (1, value, get_size(value));
			}
			else if (converter == '%')
			{
				char value = '%';
				write (1, &value, 1);
			}
		
			else if (converter == 'd' || converter == 'i')
			{
				int value = va_arg(args, int);
				print_int(value);
			}
			else if (converter == 'b')
			{
				unsigned int value = va_arg(args, unsigned int);
				print_binary (value);
			}
			else if (converter == 'u')
			{
				unsigned int value = va_arg(args, unsigned int);
				print_unsigned (value);
			}
			else if (converter == 'o')
			{
				unsigned int value = va_arg(args, unsigned int);
				print_octal (value);
			}
			else if (converter == 'x')
			{
				unsigned int value = va_arg(args, unsigned int);
				print_hex (value);
			}
			else if (converter == 'S')
			{
				char * value;
				value = va_arg(args, char *);
				write (1, value, get_size(value));
			}
		}
	}
	
	return (0);
}


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

void print_int (int num)
{
	char digits[10];
	int i = 0;
	
	while (num > 0)
	{
		digits[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		write (1, &digits[i], 1);
	}
}

void print_binary (unsigned int n)
{
	char a[10];
	int i;

	for (i = 0; n > 0; i++)
	{
		a[i] = n % 2 + '0';
		n = n / 2;
	}

	for (i = i - 1; i >= 0; i--)
	{
		write (1, &a[i], 2);
	}
}

void print_unsigned (unsigned int num)
{
        char digits[10];
	int i = 0;

	while (num > 0)
	{
		digits[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		write (1, &digits[i], 1);
	}
}

void print_octal (unsigned int num)
{
	int octal = 0, i = 1, count = 0;
	char digits[10];
	
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

	for (count = count - 1; count >= 0; count--)
	{
		write (1, &digits[count], 1);
	}
}

void print_hex (unsigned int num)
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
		write (1, &hexnum[i], 1);
}
