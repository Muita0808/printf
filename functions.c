#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
* _printf - Produces output according to a format.
* @format: The format string.
*
* Return: The number of characters printed (excluding the null byte).
*/
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
case 'c': /* handles character specifier */
num_chars += putchar(va_arg(args, int));
break;
case 's': /* handles string specifier */
const char *str_arg = va_arg(args, const char *);
num_chars += fputs(str_arg, stdout);
break;
case '%': /* handle % character */
num_chars += write(1, "%", 1);
num_chars += write(1, format, 1);
break;
default:
/* Handle unsupported format specifier */
break;
}
}
else
{
num_chars += write(1, &format[i], 1);
}
i++;
}

va_end(args);
return (num_chars);
}
