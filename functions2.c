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
case 'b':/*handles interger binary*/
{
unsigned int uint_arg = va_arg(args, unsigned int);
num_chars += print_binary(uint_arg);
}
break;
default:
/* Handle unsupported format specifier */
num_chars += putchar('%');
num_chars += putchar(format[i]);
break;
}
else
{
num_chars += putchar(format[i]);
}
i++;
}
va_end(args);
return (num_chars);
}
}
