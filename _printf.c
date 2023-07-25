#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;
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
				count++;
			}
			else if (converter == 's')
			{
				char *value;
				value = va_arg(args, char *);
				write (1, value, get_size(value));
				count = count + get_size(value);
			}
			else if (converter == '%')
			{
				char value = '%';
				write (1, &value, 1);
				count++;
			}
		
			else if (converter == 'd' || converter == 'i')
			{
				int value = va_arg(args, int);
				count = count + print_int(value);
			}
			else if (converter == 'b')
			{
				unsigned int value = va_arg(args, unsigned int);
				count = count + print_binary (value);
			}
			else if (converter == 'u')
			{
				unsigned int value = va_arg(args, unsigned int);
				count = count + print_unsigned (value);
			}
			else if (converter == 'o')
			{
				unsigned int value = va_arg(args, unsigned int);
				count = count + print_octal (value);
			}
			else if (converter == 'x')
			{
				unsigned int value = va_arg(args, unsigned int);
				count = count + print_hex (value);
			}
		}
	}

	return (count);
}
