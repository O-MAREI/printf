#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Mimics printf.
 * @format: The string
 * Return: Character count.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, temp, count = 0;
	char ch, converter;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		ch = format[i];

		if (ch != '%')
		{
			write(1, &ch, 1);
			count++;
		}
		else
		{
			converter = format[i + 1];
			i++;
			if (converter == '\0' || converter == ' ')
				return (-1);
			else
			{
				temp = print_handler(args, converter);
				if (temp == -2)
					return (-1);
				else
					count = count + temp;
			}
		}
	}

	va_end(args);

	return (count);
}

/**
 * unsigned_handler - Handles unsigned int types.
 * @value: The value to print.
 * @converter: The converter keyword.
 * Return: Character count.
 */
int unsigned_handler(unsigned int value, char converter)
{
	int count = 0;

	if (converter == 'u')
		count = print_unsigned(value);
	else if (converter == 'o')
		count = print_octal(value);
	else if (converter == 'b')
		count = print_binary(value);
	else if (converter == 'x')
		count = print_hex(value);

	return (count);
}

/**
 * print_handler - handles priinting based on argument
 * @args: The arguments
 * @conv: converter character
 * Return: Character count
 */
int print_handler(va_list args, char conv)
{
	int count;

	if (conv == 'c')
	{
		char value = va_arg(args, int);

		write(1, &value, 1);
		count = 1;
	}
	else if (conv == 's')
	{
		char *value;

		value = va_arg(args, char *);
		count = print_string(value);
	}
	else if (conv == '%')
	{
		write(1, "%%", 1);
		count = 1;
	}
	else if (conv == 'd' || conv == 'i')
	{
		int value = va_arg(args, int);

		count = print_int(value);
	}
	else
	{
		count = -2;
	}

	return (count);
}

int print_string(char *s)
{
	int len, i;

	if (s == NULL)
	{
		s = "(null)";
		len = get_size(s);
		for (i = 0; i < len; i++)
			write(1, &s[i], 1);
		return (len);
	}
	else
	{
		len = get_size(s);
		for (i = 0; i < len; i++)
			write(1, &s[i], 1);
		return (len);
	}
}
