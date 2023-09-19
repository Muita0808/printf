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
				case 'd': /* Handle integer specifier */
				case 'i':
					{
						int int_arg = va_arg(args, int);
						num_chars += printf("%d", int_arg);
					}
					break;
				case 'b': /* Handle binary specifier */
					{
						unsigned int uint_arg = va_arg(args, unsigned int);
						num_chars += print_binary(uint_arg);
					}
					break;
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
}

int print_binary(unsigned int num)
{
	int num_chars = 0;
	int binary[32]; // Assume a 32-bit integer
	
	/* Convert the integer to binary and store it in the binary array*/
	for (int i = 31; i >= 0; i--)
	{
		binary[i] = num % 2;
		num /= 2;
	}
	
	/* Print the binary representation*/
	for (int i = 0; i < 32; i++)
	{
		num_chars += putchar('0' + binary[i]);
	}
	return num_chars;
}

int main(void)
{
	int num = 4;
	unsigned int binary_num = 433;
	unsigned int decimal_num = 1.23;
	unsigned int octal_num = 6657853;
	unsigned int hex_num = 256542095;
	
	_printf("This is a number: %d\n", num);
	_printf("Binary representation: %b\n", binary_num);
	_printf("Unsigned decimal: %u\n", decimal_num);
	_printf("Octal representation: %o\n", octal_num);
	_printf("Lowercase hexadecimal: %x\n", hex_num);
	_printf("Uppercase hexadecimal: %X\n", hex_num);
	
	return( 0);
}
