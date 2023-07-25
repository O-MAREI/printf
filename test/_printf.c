#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int get_size(char str[]);
int count_num (int n);
void print_binary (unsigned int n);
void print_int (int num);

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
	char digit;
	
	while (num > 0)
	{
		digit = (num % 10) + '0';
		num = num / 10;
		write (1, &digit, 1);
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

	for(i = i - 1; i >= 0; i--)
	{
		write (1, &a[i], 2);
	}
}
