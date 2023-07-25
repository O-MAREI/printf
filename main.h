#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int get_size(char str[]);
int count_num (int n);
int print_binary (unsigned int n);
int print_int (int num);
int print_unsigned (unsigned int num);
int print_octal (unsigned int num);
int print_hex (unsigned int num);
int print_handler(va_list args, char conv);

#endif
