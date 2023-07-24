#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int get_size(char str[]);

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
