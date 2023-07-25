#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int j = 0, i, length = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[j] != '\0')
	{
		i = 13;
		while (i >= 0)
		{
			if (m[i].id[0] == format[j] && m[i].id[1] == format[j + 1])
			{
				length += m[i].f(args);
				j = j + 2;
				goto Here;
			}
			i--;
		}
		_putchar(format[j]);
		length++;
		j++;
	}
	va_end(args);
	return (length);
}
