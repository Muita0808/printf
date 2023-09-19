#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>

int _printf(const char *format, ...)
{
	int num_chars = 0;
	va_list args;
	int i = 0;
	
	va_start(args, format);
	
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++; /* Move past '%' */
			switch (format[i])
			{
				case 'u': /* Handle unsigned decimal specifier */
					{
						unsigned int uint_arg = va_arg(args, unsigned int);
						num_chars += printf("%u", uint_arg);
					}
					break;
				case 'o': /* Handle octal specifier */
					{
						unsigned int uint_arg = va_arg(args, unsigned int);
						num_chars += printf("%o", uint_arg);
					}
					break;
				case 'x': /* Handle lowercase hexadecimal specifier */
					{
						unsigned int uint_arg = va_arg(args, unsigned int);
						num_chars += printf("%x", uint_arg);
					}
					break;
				case 'X': /* Handle uppercase hexadecimal specifier */
					{
						unsigned int uint_arg = va_arg(args, unsigned int);
						num_chars += printf("%X", uint_arg);
					}
					break;
				default:
					/* Handle unsupported format specifier */
					num_chars += putchar('%');
					num_chars += putchar(format[i]);
					break;
			}
		}
		else
		{
			num_chars += putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (num_chars);
}Z
