#ifndef _MAIN_H_
#define _MAIN_H_
 
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int handle_specifier(char specifier, va_list args);
int print_char(va_list args);
int print_string(va_list args);

#endif
