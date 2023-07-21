#include "main.h"

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0;
	int a;
	char *s = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}
	while (s[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			 write(1, &s[0], length);
			 for (a = width - length; a > 0; a--)
				 write(1, " ", 1);
			 return (width);
		}
		else
		{
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			write(1, &s[0], length);
			return (width);
		}
	}
	return (write(1, s, length));
}

/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: int
 */

int print_percent(va_list types,
		char buffer[], int flags, int width,
		int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */

int print_binary(va_list types,
		char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned int x, y, j, total;
	unsigned int arr[32];
	int count;

	 UNUSED(buffer);
	 UNUSED(flags);
	 UNUSED(width);
	 UNUSED(precision);
	 UNUSED(size);

	 x = va_arg(types, unsigned int);
	 y = 2147483648; /* (2 ^ 31) */
	 arr[0] = x / y;

	 for (j = 1; j < 32; j++)
	 {
		 y /= 2;
		 arr[j] = (x / y) % 2;
	 }
	 for (j = 0, total = 0, count = 0; j < 32; j++)
	 {
		 total +=arr[j];
		 if (total || j == 31)
		 {
			 char z = '0'+arr[j];
			 write(1, &z, 1);
			 count++;
		 }
	 }
	 return (count);
}
